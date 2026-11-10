// PopEnemy__12CBaseMonster  @ 000c269c
undefined4 PopEnemy__12CBaseMonster(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 3;
  do {
    iVar1 = param_1 + 0x50c + iVar4 * 8;
    iVar3 = __opP11CBaseEntity__7EHANDLE(iVar1);
    if (iVar3 != 0) {
      iVar3 = __rf__7EHANDLE(iVar1);
      iVar3 = (**(code **)(*(int *)(iVar3 + 0x454) + 0x8c))(iVar3);
      if (iVar3 != 0) {
        uVar2 = *(undefined4 *)(param_1 + 0x510 + iVar4 * 8);
        *(undefined4 *)(param_1 + 0x4fc) = *(undefined4 *)(param_1 + 0x50c + iVar4 * 8);
        *(undefined4 *)(param_1 + 0x500) = uVar2;
        iVar4 = param_1 + iVar4 * 0xc;
        *(undefined4 *)(param_1 + 0x644) = *(undefined4 *)(iVar4 + 0x52c);
        *(undefined4 *)(param_1 + 0x648) = *(undefined4 *)(iVar4 + 0x530);
        *(undefined4 *)(param_1 + 0x64c) = *(undefined4 *)(iVar4 + 0x534);
        return 1;
      }
      __as__7EHANDLEP11CBaseEntity(iVar1,0);
    }
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  return 0;
}


