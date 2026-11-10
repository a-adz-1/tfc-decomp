// FRefreshRoute__12CBaseMonster  @ 000bb834
undefined4 FRefreshRoute__12CBaseMonster(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined1 **ppuVar5;
  int iVar6;
  int iVar7;
  undefined1 *puStack_34;
  int iStack_30;
  int *piStack_2c;
  int local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  *(undefined4 *)(param_1 + 0x594) = 0;
  *(undefined4 *)(param_1 + 0x60c) = 0;
  iVar2 = *(int *)(param_1 + 0x608);
  if (iVar2 == 0x10) {
    local_14 = 0;
    piVar3 = *(int **)(param_1 + 4);
    if (piVar3 != (int *)0x0) {
      do {
        if (7 < local_14) {
          return 1;
        }
        iVar6 = local_14 * 0x10;
        *(undefined4 *)(iVar6 + param_1 + 0x594) = 0x10;
        iVar2 = param_1 + iVar6;
        iVar7 = *piVar3;
        *(undefined4 *)(iVar2 + 0x588) = *(undefined4 *)(iVar7 + 8);
        *(undefined4 *)(iVar2 + 0x58c) = *(undefined4 *)(iVar7 + 0xc);
        *(undefined4 *)(iVar2 + 0x590) = *(undefined4 *)(iVar7 + 0x10);
        iStack_30 = 0xbb905;
        piStack_2c = piVar3;
        piVar3 = (int *)(**(code **)(piVar3[0x115] + 0xac))();
        local_14 = local_14 + 1;
      } while (piVar3 != (int *)0x0);
      pbVar1 = (byte *)(iVar6 + param_1 + 0x594);
      *pbVar1 = *pbVar1 | 0x80;
    }
    return 1;
  }
  if (iVar2 < 0x11) {
    if (iVar2 == 1) {
      iVar7 = param_1 + 0x504;
      iStack_30 = 0xbb963;
      piStack_2c = (int *)iVar7;
      iVar2 = __opP11CBaseEntity__7EHANDLE();
      if (iVar2 == 0) {
        return 0;
      }
      iStack_30 = 0xbb970;
      piStack_2c = (int *)iVar7;
      iStack_30 = __opP11CBaseEntity__7EHANDLE();
      puStack_34 = (undefined1 *)0x1;
      piVar3 = (int *)__rf__7EHANDLE(iVar7);
      ppuVar5 = &puStack_34;
      iVar2 = *piVar3 + 8;
    }
    else {
      if (iVar2 != 2) {
        return 0;
      }
      piStack_2c = (int *)(param_1 + 0x4fc);
      iStack_30 = 0xbb936;
      iStack_30 = __opP11CBaseEntity__7EHANDLE();
      ppuVar5 = &puStack_34;
      puStack_34 = (undefined1 *)0x2;
      iVar2 = param_1 + 0x644;
    }
  }
  else {
    if (iVar2 == 0x20) {
      piStack_2c = &uStack_10;
      uStack_10 = *(undefined4 *)(param_1 + 0x614);
      uStack_c = *(undefined4 *)(param_1 + 0x618);
      uStack_8 = *(undefined4 *)(param_1 + 0x61c);
      iStack_30 = param_1;
      puStack_34 = &LAB_000bb9b8;
      uVar4 = FGetNodeRoute__12CBaseMonsterG6Vector();
      return uVar4;
    }
    if (iVar2 != 0x40) {
      return 0;
    }
    piStack_2c = (int *)0x0;
    ppuVar5 = (undefined1 **)&iStack_30;
    iStack_30 = 0x40;
    iVar2 = param_1 + 0x614;
  }
  *(int *)((int)ppuVar5 + -4) = iVar2;
  *(int *)((int)ppuVar5 + -8) = param_1;
  *(undefined4 *)((int)ppuVar5 + -0xc) = 0xbb98b;
  uVar4 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity();
  return uVar4;
}


