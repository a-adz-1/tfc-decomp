// FGetNodeRoute__12CBaseMonsterG6Vector  @ 000c07d0
undefined4 FGetNodeRoute__12CBaseMonsterG6Vector(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *local_48;
  int *piStack_44;
  int *piStack_40;
  int *local_3c;
  uint local_30;
  uint local_2c;
  int local_28 [10];
  
  iVar1 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,*param_1 + 8,param_1);
  iVar2 = FindNearestNode__6CGraphRC6VectorP11CBaseEntity(&WorldGraph,param_2,param_1);
  if ((iVar1 == -1) || (iVar2 == -1)) {
    return 0;
  }
  uVar3 = HullIndex__6CGraphPC11CBaseEntity(&WorldGraph,param_1);
  uVar4 = FindShortestPath__6CGraphPiiiii(&WorldGraph,local_28,iVar1,iVar2,uVar3,param_1[0x191]);
  iVar5 = DAT_001c148c;
  if (uVar4 == 0) {
    (*DAT_001c1114)(2,"No Path from %d to %d!\n",iVar1,iVar2);
    return 0;
  }
  local_30 = 8;
  if ((int)uVar4 < 8) {
    local_30 = uVar4;
  }
  local_2c = 0;
  if (0 < (int)local_30) {
    local_48 = param_1 + 0x160;
    piVar6 = param_1 + 0x15f;
    local_3c = param_1 + 0x15e;
    iVar1 = 0;
    uVar4 = local_30 & 3;
    if (uVar4 != 0) {
      if (1 < uVar4) {
        if (2 < uVar4) {
          local_28[0] = local_28[0] * 0x58;
          param_1[0x15e] = *(int *)(DAT_001c148c + local_28[0]);
          param_1[0x15f] = *(int *)(iVar5 + 4 + local_28[0]);
          param_1[0x160] = *(int *)(iVar5 + 8 + local_28[0]);
          param_1[0x161] = 0x20;
          local_48 = param_1 + 0x164;
          piVar6 = param_1 + 0x163;
          local_3c = param_1 + 0x162;
          iVar1 = 4;
        }
        iVar2 = DAT_001c148c;
        local_2c = (uint)(2 < uVar4);
        iVar5 = *(int *)((int)local_28 + iVar1) * 0x58;
        *local_3c = *(int *)(DAT_001c148c + iVar5);
        *piVar6 = *(int *)(iVar2 + 4 + iVar5);
        *local_48 = *(int *)(iVar2 + 8 + iVar5);
        param_1[iVar1 + 0x161] = 0x20;
        local_48 = local_48 + 4;
        piVar6 = piVar6 + 4;
        local_3c = local_3c + 4;
        iVar1 = iVar1 + 4;
        local_2c = local_2c + 1;
      }
      iVar2 = DAT_001c148c;
      iVar5 = *(int *)((int)local_28 + iVar1) * 0x58;
      *local_3c = *(int *)(DAT_001c148c + iVar5);
      *piVar6 = *(int *)(iVar2 + 4 + iVar5);
      *local_48 = *(int *)(iVar2 + 8 + iVar5);
      param_1[iVar1 + 0x161] = 0x20;
      local_48 = local_48 + 4;
      piVar6 = piVar6 + 4;
      local_3c = local_3c + 4;
      iVar1 = iVar1 + 4;
      local_2c = local_2c + 1;
      if ((int)local_30 <= (int)local_2c) goto LAB_000c0b3e;
    }
    piStack_40 = param_1 + iVar1 + 0x161;
    piStack_44 = local_48;
    local_48 = local_3c;
    piVar7 = (int *)((int)local_28 + iVar1);
    do {
      iVar1 = DAT_001c148c;
      iVar2 = *piVar7 * 0x58;
      *local_48 = *(int *)(DAT_001c148c + iVar2);
      *piVar6 = *(int *)(iVar1 + 4 + iVar2);
      *piStack_44 = *(int *)(iVar1 + 8 + iVar2);
      *piStack_40 = 0x20;
      iVar1 = DAT_001c148c;
      iVar2 = piVar7[1] * 0x58;
      local_48[4] = *(int *)(DAT_001c148c + iVar2);
      piVar6[4] = *(int *)(iVar1 + 4 + iVar2);
      piStack_44[4] = *(int *)(iVar1 + 8 + iVar2);
      piStack_40[4] = 0x20;
      iVar1 = DAT_001c148c;
      iVar2 = piVar7[2] * 0x58;
      local_48[8] = *(int *)(DAT_001c148c + iVar2);
      piVar6[8] = *(int *)(iVar1 + 4 + iVar2);
      piStack_44[8] = *(int *)(iVar1 + 8 + iVar2);
      piStack_40[8] = 0x20;
      iVar1 = DAT_001c148c;
      iVar2 = piVar7[3] * 0x58;
      local_48[0xc] = *(int *)(DAT_001c148c + iVar2);
      piVar6[0xc] = *(int *)(iVar1 + 4 + iVar2);
      piStack_44[0xc] = *(int *)(iVar1 + 8 + iVar2);
      piStack_40[0xc] = 0x20;
      piStack_44 = piStack_44 + 0x10;
      piVar6 = piVar6 + 0x10;
      local_48 = local_48 + 0x10;
      piStack_40 = piStack_40 + 0x10;
      piVar7 = piVar7 + 4;
      local_2c = local_2c + 4;
    } while ((int)local_2c < (int)local_30);
  }
LAB_000c0b3e:
  if ((int)local_30 < 8) {
    param_1[local_30 * 4 + 0x15e] = *param_2;
    param_1[local_30 * 4 + 0x15f] = param_2[1];
    param_1[local_30 * 4 + 0x160] = param_2[2];
    *(byte *)(param_1 + local_30 * 4 + 0x161) = *(byte *)(param_1 + local_30 * 4 + 0x161) | 0x80;
  }
  return 1;
}


