// PopEnemy__12CBaseMonster  @ 000c2a70
undefined4 PopEnemy__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 3;
  do {
    iVar3 = param_1 + 0x480 + iVar4 * 8;
    iVar2 = __opP11CBaseEntity__7EHANDLE(iVar3);
    if (iVar2 != 0) {
      iVar3 = __rf__7EHANDLE(iVar3);
      iVar3 = (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x88))(iVar3);
      if (iVar3 != 0) {
        uVar1 = *(undefined4 *)(param_1 + 0x484 + iVar4 * 8);
        *(undefined4 *)(param_1 + 0x470) = *(undefined4 *)(param_1 + 0x480 + iVar4 * 8);
        *(undefined4 *)(param_1 + 0x474) = uVar1;
        iVar4 = param_1 + iVar4 * 0xc;
        *(undefined4 *)(param_1 + 0x5b8) = *(undefined4 *)(iVar4 + 0x4a0);
        *(undefined4 *)(param_1 + 0x5bc) = *(undefined4 *)(iVar4 + 0x4a4);
        *(undefined4 *)(param_1 + 0x5c0) = *(undefined4 *)(iVar4 + 0x4a8);
        return 1;
      }
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x480 + iVar4 * 8,0);
    }
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  return 0;
}


