// PathFind__9CTestHull  @ 000bd0c8
void PathFind__9CTestHull(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int local_c8;
  int aiStack_c4 [49];
  
  if ((WorldGraph == 0) || (DAT_001a82a4 == 0)) {
    pcVar4 = "Graph not ready!\n";
  }
  else {
    iVar2 = FindShortestPath__6CGraphPiiiii(&WorldGraph,&local_c8,0,0x13,0,0);
    if (iVar2 != 0) {
      (*DAT_001a7f34)(2,&DAT_00139122,iVar2);
      puVar5 = (undefined4 *)(DAT_001a82ac + local_c8 * 0x58);
      for (iVar3 = 0; iVar3 < iVar2 + -1; iVar3 = iVar3 + 1) {
        puVar1 = (undefined4 *)(DAT_001a82ac + aiStack_c4[iVar3] * 0x58);
        (*DAT_001a7ef8)(0,0x17,0,0);
        (*DAT_001a7f00)(0x66);
        (*DAT_001a7f14)(*puVar5);
        (*DAT_001a7f14)(puVar5[1]);
        (*DAT_001a7f14)((float)puVar5[2] + 8.0);
        (*DAT_001a7f14)(*puVar1);
        (*DAT_001a7f14)(puVar1[1]);
        (*DAT_001a7f14)((float)puVar1[2] + 8.0);
        (*DAT_001a7efc)();
        puVar5 = puVar1;
      }
      return;
    }
    pcVar4 = "No Path!\n";
  }
  (*DAT_001a7f34)(2,pcVar4);
  return;
}


