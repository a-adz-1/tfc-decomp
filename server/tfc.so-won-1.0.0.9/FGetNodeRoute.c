// FGetNodeRoute__12CBaseMonsterG6Vector  @ 000c6ca0
undefined4 FGetNodeRoute__12CBaseMonsterG6Vector(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iStack_3c;
  int iStack_30;
  int local_2c [10];
  
  iVar1 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,*param_1 + 8,param_1);
  iVar2 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,param_2,param_1);
  if ((iVar1 != -1) && (iVar2 != -1)) {
    uVar3 = HullIndex__6CGraphPC11CBaseEntity(&WorldGraph,param_1);
    iVar4 = FindShortestPath__6CGraphPiiiii(&WorldGraph,local_2c,iVar1,iVar2,uVar3,param_1[0x172]);
    if (iVar4 != 0) {
      iStack_30 = 8;
      if (iVar4 < 8) {
        iStack_30 = iVar4;
      }
      iStack_3c = 0;
      if (0 < iStack_30) {
        do {
          iVar1 = DAT_001758cc;
          iVar2 = local_2c[iStack_3c] * 0x58;
          param_1[iStack_3c * 4 + 0x13f] = *(int *)(DAT_001758cc + iVar2);
          param_1[iStack_3c * 4 + 0x140] = *(int *)(iVar1 + 4 + iVar2);
          param_1[iStack_3c * 4 + 0x141] = *(int *)(iVar1 + 8 + iVar2);
          param_1[iStack_3c * 4 + 0x142] = 0x20;
          iStack_3c = iStack_3c + 1;
        } while (iStack_3c < iStack_30);
      }
      if (iStack_30 < 8) {
        param_1[iStack_30 * 4 + 0x13f] = *param_2;
        param_1[iStack_30 * 4 + 0x140] = param_2[1];
        param_1[iStack_30 * 4 + 0x141] = param_2[2];
        *(byte *)(param_1 + iStack_30 * 4 + 0x142) =
             *(byte *)(param_1 + iStack_30 * 4 + 0x142) | 0x80;
      }
      return 1;
    }
    (*DAT_001755b4)(2,"No Path from %d to %d!\n",iVar1,iVar2);
  }
  return 0;
}


