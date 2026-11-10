// PopEnemy__12CBaseMonster  @ 000bbba4
undefined4 PopEnemy__12CBaseMonster(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  int local_4;
  
  local_4 = 3;
  puVar4 = (undefined4 *)(param_1 + 0x514);
  local_8 = (undefined4 *)(param_1 + 0x548);
  local_c = (undefined4 *)(param_1 + 0x544);
  local_10 = (undefined4 *)(param_1 + 0x540);
  local_14 = puVar4;
  do {
    iVar2 = __opP11CBaseEntity__7EHANDLE(puVar4);
    if (iVar2 != 0) {
      iVar2 = __rf__7EHANDLE(puVar4);
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x444) + 0x8c))(iVar2);
      if (iVar2 != 0) {
        uVar3 = local_14[1];
        *(undefined4 *)(param_1 + 0x4ec) = *local_14;
        *(undefined4 *)(param_1 + 0x4f0) = uVar3;
        *(undefined4 *)(param_1 + 0x634) = *local_10;
        *(undefined4 *)(param_1 + 0x638) = *local_c;
        uVar3 = *local_8;
        goto LAB_000bbcbc;
      }
      __as__7EHANDLEP11CBaseEntity(puVar4,0);
    }
    puVar1 = puVar4 + -2;
    iVar2 = __opP11CBaseEntity__7EHANDLE(puVar1);
    if (iVar2 != 0) {
      iVar2 = __rf__7EHANDLE(puVar1);
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x444) + 0x8c))(iVar2);
      if (iVar2 != 0) {
        uVar3 = local_14[-1];
        *(undefined4 *)(param_1 + 0x4ec) = local_14[-2];
        *(undefined4 *)(param_1 + 0x4f0) = uVar3;
        *(undefined4 *)(param_1 + 0x634) = local_10[-3];
        *(undefined4 *)(param_1 + 0x638) = local_c[-3];
        uVar3 = local_8[-3];
LAB_000bbcbc:
        *(undefined4 *)(param_1 + 0x63c) = uVar3;
        return 1;
      }
      __as__7EHANDLEP11CBaseEntity(puVar1,0);
    }
    local_14 = local_14 + -4;
    puVar4 = puVar4 + -4;
    local_8 = local_8 + -6;
    local_c = local_c + -6;
    local_10 = local_10 + -6;
    local_4 = local_4 + -2;
    if (local_4 < 0) {
      return 0;
    }
  } while( true );
}


