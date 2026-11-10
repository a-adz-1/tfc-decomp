// FGetNodeRoute__12CBaseMonsterG6Vector  @ 000bfd00
undefined4 FGetNodeRoute__12CBaseMonsterG6Vector(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_34;
  int local_30;
  int local_2c [10];
  
  iVar1 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,*param_1 + 8,param_1);
  iVar2 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,param_2,param_1);
  if ((iVar1 == -1) || (iVar2 == -1)) {
    uVar3 = 0;
  }
  else {
    uVar3 = HullIndex__6CGraphPC11CBaseEntity(&WorldGraph,param_1);
    iVar4 = FindShortestPath__6CGraphPiiiii(&WorldGraph,local_2c,iVar1,iVar2,uVar3,param_1[0x195]);
    if (iVar4 == 0) {
      (*DAT_0019f794)(2,"No Path from %d to %d!\n",iVar1,iVar2);
      uVar3 = 0;
    }
    else {
      local_34 = 8;
      if (iVar4 < 8) {
        local_34 = iVar4;
      }
      local_30 = 0;
      if (0 < local_34) {
        do {
          iVar1 = DAT_0019fb2c;
          iVar2 = local_2c[local_30] * 0x58;
          param_1[local_30 * 4 + 0x162] = *(int *)(DAT_0019fb2c + iVar2);
          param_1[local_30 * 4 + 0x163] = *(int *)(iVar1 + 4 + iVar2);
          param_1[local_30 * 4 + 0x164] = *(int *)(iVar1 + 8 + iVar2);
          param_1[local_30 * 4 + 0x165] = 0x20;
          local_30 = local_30 + 1;
        } while (local_30 < local_34);
      }
      if (local_34 < 8) {
        param_1[local_34 * 4 + 0x162] = *param_2;
        param_1[local_34 * 4 + 0x163] = param_2[1];
        param_1[local_34 * 4 + 0x164] = param_2[2];
        *(byte *)(param_1 + local_34 * 4 + 0x165) = *(byte *)(param_1 + local_34 * 4 + 0x165) | 0x80
        ;
      }
      uVar3 = 1;
    }
  }
  return uVar3;
}


