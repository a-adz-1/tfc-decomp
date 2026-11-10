// PathFind__9CTestHull  @ 000c8174
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PathFind__9CTestHull(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *local_dc;
  int local_cc [50];
  
  if ((WorldGraph == 0) || (DAT_0019fb24 == 0)) {
    pcVar4 = "Graph not ready!\n";
  }
  else {
    iVar2 = FindShortestPath__6CGraphPiiiii(&WorldGraph,local_cc,0,0x13,0,0);
    if (iVar2 != 0) {
      (*DAT_0019f794)(2,&DAT_0014ee56,iVar2);
      local_dc = (undefined4 *)(DAT_0019fb2c + local_cc[0] * 0x58);
      iVar3 = 0;
      if (iVar2 + -1 < 1) {
        return;
      }
      do {
        iVar3 = iVar3 + 1;
        puVar1 = (undefined4 *)(DAT_0019fb2c + local_cc[iVar3] * 0x58);
        (*DAT_0019f758)(0,0x17,0,0);
        (*DAT_0019f760)(0x66);
        (*DAT_0019f774)(*local_dc);
        (*DAT_0019f774)(local_dc[1]);
        (*DAT_0019f774)((float)local_dc[2] + _FUN_0014ee5c);
        (*DAT_0019f774)(*puVar1);
        (*DAT_0019f774)(puVar1[1]);
        (*DAT_0019f774)((float)puVar1[2] + _FUN_0014ee5c);
        (*DAT_0019f75c)();
        local_dc = puVar1;
      } while (iVar3 < iVar2 + -1);
      return;
    }
    pcVar4 = "No Path!\n";
  }
  (*DAT_0019f794)(2,pcVar4);
  return;
}


