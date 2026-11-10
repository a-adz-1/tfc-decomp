// PopEnemy__12CBaseMonster  @ 000b0944
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
  puVar4 = (undefined4 *)(param_1 + 0x4a4);
  local_8 = (undefined4 *)(param_1 + 0x4d8);
  local_c = (undefined4 *)(param_1 + 0x4d4);
  local_10 = (undefined4 *)(param_1 + 0x4d0);
  local_14 = puVar4;
  do {
    iVar2 = __opP11CBaseEntity__7EHANDLE(puVar4);
    if (iVar2 != 0) {
      iVar2 = __rf__7EHANDLE(puVar4);
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x88))(iVar2);
      if (iVar2 != 0) {
        uVar3 = local_14[1];
        *(undefined4 *)(param_1 + 0x47c) = *local_14;
        *(undefined4 *)(param_1 + 0x480) = uVar3;
        *(undefined4 *)(param_1 + 0x5c4) = *local_10;
        *(undefined4 *)(param_1 + 0x5c8) = *local_c;
        uVar3 = *local_8;
        goto LAB_000b0a5c;
      }
      __as__7EHANDLEP11CBaseEntity(puVar4,0);
    }
    puVar1 = puVar4 + -2;
    iVar2 = __opP11CBaseEntity__7EHANDLE(puVar1);
    if (iVar2 != 0) {
      iVar2 = __rf__7EHANDLE(puVar1);
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x3d4) + 0x88))(iVar2);
      if (iVar2 != 0) {
        uVar3 = local_14[-1];
        *(undefined4 *)(param_1 + 0x47c) = local_14[-2];
        *(undefined4 *)(param_1 + 0x480) = uVar3;
        *(undefined4 *)(param_1 + 0x5c4) = local_10[-3];
        *(undefined4 *)(param_1 + 0x5c8) = local_c[-3];
        uVar3 = local_8[-3];
LAB_000b0a5c:
        *(undefined4 *)(param_1 + 0x5cc) = uVar3;
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


