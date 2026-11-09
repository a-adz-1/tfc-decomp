// FRefreshRoute__12CBaseMonster  @ 000c1a40
undefined4 FRefreshRoute__12CBaseMonster(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uStack_30;
  int iStack_2c;
  int *piStack_28;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piStack_28 = (int *)param_1;
  iStack_2c = 0xc1a52;
  RouteNew__12CBaseMonster();
  iVar2 = *(int *)(param_1 + 0x57c);
  if (iVar2 == 0x10) {
    piVar3 = *(int **)(param_1 + 4);
    local_14 = 0;
    if (piVar3 != (int *)0x0) {
      do {
        if (7 < local_14) {
          return 1;
        }
        iVar7 = local_14 * 0x10;
        *(undefined4 *)(iVar7 + param_1 + 0x508) = 0x10;
        iVar2 = param_1 + iVar7;
        iVar5 = *piVar3;
        *(undefined4 *)(iVar2 + 0x4fc) = *(undefined4 *)(iVar5 + 8);
        *(undefined4 *)(iVar2 + 0x500) = *(undefined4 *)(iVar5 + 0xc);
        *(undefined4 *)(iVar2 + 0x504) = *(undefined4 *)(iVar5 + 0x10);
        iStack_2c = 0xc1b05;
        piStack_28 = piVar3;
        piVar3 = (int *)(**(code **)(piVar3[0xf2] + 0xa4))();
        local_14 = local_14 + 1;
      } while (piVar3 != (int *)0x0);
      pbVar1 = (byte *)(iVar7 + param_1 + 0x508);
      *pbVar1 = *pbVar1 | 0x80;
    }
    return 1;
  }
  if (iVar2 < 0x11) {
    if (iVar2 == 1) {
      iVar5 = param_1 + 0x478;
      iStack_2c = 0xc1b6f;
      piStack_28 = (int *)iVar5;
      iVar2 = __opP11CBaseEntity__7EHANDLE();
      if (iVar2 == 0) {
        return 0;
      }
      iStack_2c = 0xc1b7c;
      piStack_28 = (int *)iVar5;
      iStack_2c = __opP11CBaseEntity__7EHANDLE();
      uStack_30 = 1;
      piVar3 = (int *)__rf__7EHANDLE(iVar5);
      piVar6 = &uStack_30;
      iVar2 = *piVar3 + 8;
    }
    else {
      if (iVar2 != 2) {
        return 0;
      }
      piStack_28 = (int *)(param_1 + 0x470);
      iStack_2c = 0xc1b3e;
      iStack_2c = __opP11CBaseEntity__7EHANDLE();
      piVar6 = &uStack_30;
      uStack_30 = 2;
      iVar2 = param_1 + 0x5b8;
    }
  }
  else {
    if (iVar2 == 0x20) {
      local_10 = *(undefined4 *)(param_1 + 0x588);
      local_c = *(undefined4 *)(param_1 + 0x58c);
      local_8 = *(undefined4 *)(param_1 + 0x590);
      piStack_28 = &local_10;
      iStack_2c = param_1;
      uStack_30 = 0xc1bc8;
      uVar4 = FGetNodeRoute__12CBaseMonsterG6Vector();
      return uVar4;
    }
    if (iVar2 != 0x40) {
      return 0;
    }
    piStack_28 = (int *)0x0;
    piVar6 = &iStack_2c;
    iStack_2c = 0x40;
    iVar2 = param_1 + 0x588;
  }
  *(int *)((int)piVar6 + -4) = iVar2;
  *(int *)((int)piVar6 + -8) = param_1;
  *(undefined4 *)((int)piVar6 + -0xc) = 0xc1b97;
  uVar4 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity();
  return uVar4;
}


