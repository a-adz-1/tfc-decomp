// PathFind__9CTestHull  @ 000cd360
void PathFind__9CTestHull(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int local_cc;
  int aiStack_c8 [49];
  
  if ((WorldGraph == 0) || (DAT_001758c4 == 0)) {
    pcVar5 = "Graph not ready!\n";
  }
  else {
    iVar2 = FindShortestPath__6CGraphPiiiii(&WorldGraph,&local_cc,0,0x13,0,0);
    if (iVar2 != 0) {
      (*DAT_001755b4)(2,&DAT_00137442,iVar2);
      puVar4 = (undefined4 *)(DAT_001758cc + local_cc * 0x58);
      for (iVar3 = 0; iVar3 < iVar2 + -1; iVar3 = iVar3 + 1) {
        puVar1 = (undefined4 *)(DAT_001758cc + aiStack_c8[iVar3] * 0x58);
        (*DAT_00175578)(0,0x17,0,0);
        (*DAT_00175580)(0x66);
        (*DAT_00175594)(*puVar4);
        (*DAT_00175594)(puVar4[1]);
        (*DAT_00175594)((float)puVar4[2] + 8.0);
        (*DAT_00175594)(*puVar1);
        (*DAT_00175594)(puVar1[1]);
        (*DAT_00175594)((float)puVar1[2] + 8.0);
        (*DAT_0017557c)();
        puVar4 = puVar1;
      }
      return;
    }
    pcVar5 = "No Path!\n";
  }
  (*DAT_001755b4)(2,pcVar5);
  return;
}


