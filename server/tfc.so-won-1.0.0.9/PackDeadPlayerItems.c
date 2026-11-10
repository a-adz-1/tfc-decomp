// PackDeadPlayerItems__11CBasePlayer  @ 000d75e0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PackDeadPlayerItems__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int local_130;
  int local_d8 [33];
  int local_54 [20];
  
  iVar8 = 0;
  memset(local_54,0,0x50);
  memset(local_d8,-1,0x84);
  if (_FUN_00139880 + cb_prematch_time <= *gpGlobals) {
    iVar4 = (**(code **)(*g_pGameRules + 0xc4))(g_pGameRules,param_1);
    iVar5 = (**(code **)(*g_pGameRules + 200))(g_pGameRules,param_1);
    if ((iVar4 != 9) || (iVar5 != 0xc)) {
      iVar7 = 0;
      do {
        if (param_1[iVar7 + 0x206] != 0) {
          for (iVar3 = param_1[iVar7 + 0x206]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x3ec)) {
            if (iVar4 == 7) {
              local_54[iVar8] = iVar3;
LAB_000d771f:
              iVar8 = iVar8 + 1;
            }
            else if (((iVar4 == 8) && (param_1[0x20c] != 0)) && (iVar3 == param_1[0x20c])) {
              local_54[iVar8] = iVar3;
              goto LAB_000d771f;
            }
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 6);
      if (iVar5 != 0xc) {
        iVar8 = 0;
        iVar4 = 0;
        do {
          if ((0 < param_1[iVar8 + 0x20f]) &&
             ((iVar5 == 10 ||
              (((iVar5 == 0xb && (param_1[0x20c] != 0)) &&
               ((iVar7 = (**(code **)(*(int *)(param_1[0x20c] + 0x3c8) + 0x13c))(param_1[0x20c]),
                iVar8 == iVar7 ||
                ((param_1[0x20c] != 0 &&
                 (iVar7 = (**(code **)(*(int *)(param_1[0x20c] + 0x3c8) + 0x140))(param_1[0x20c]),
                 iVar8 == iVar7)))))))))) {
            local_d8[iVar4] = iVar8;
            iVar4 = iVar4 + 1;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < 0x20);
      }
      iVar8 = *param_1;
      piVar6 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                                ("weaponbox",iVar8 + 8,iVar8 + 0x50,*(undefined4 *)(iVar8 + 0x1e8));
      *(undefined4 *)(*piVar6 + 0x50) = 0;
      *(undefined4 *)(*piVar6 + 0x58) = 0;
      piVar6[3] = -0x10000;
      piVar6[4] = (int)Kill__10CWeaponBox;
      *(float *)(*piVar6 + 0xe4) = *gpGlobals + 120.0;
      iVar8 = 0;
      if (local_d8[0] != -1) {
        iVar4 = 0;
        do {
          PackAmmo__10CWeaponBoxii
                    (piVar6,(&_15CBasePlayerItem_AmmoInfoArray)[local_d8[iVar4] * 2] -
                            (int)gpGlobals[0x26],param_1[local_d8[iVar4] + 0x20f]);
          iVar4 = iVar4 + 1;
        } while (local_d8[iVar4] != -1);
      }
      local_130 = 0;
      while (local_54[0] != 0) {
        PackWeapon__10CWeaponBoxP15CBasePlayerItem
                  (piVar6,*(undefined4 *)((int)local_54 + local_130));
        iVar8 = iVar8 + 1;
        local_130 = iVar8 * 4;
        local_54[0] = local_54[iVar8];
      }
      if (iVar5 != 0xc) {
        piVar6[0x33] = param_1[0x33];
        piVar6[0x35] = param_1[0x35];
        piVar6[0x39] = param_1[0x39];
        piVar6[0x37] = param_1[0x37];
        *(undefined4 *)(*piVar6 + 0x19c) = *(undefined4 *)(*param_1 + 0x19c);
      }
      iVar8 = *piVar6;
      iVar4 = *param_1;
      fVar1 = *(float *)(iVar4 + 0x24);
      fVar2 = *(float *)(iVar4 + 0x28);
      *(float *)(iVar8 + 0x20) = *(float *)(iVar4 + 0x20) * 1.2;
      *(float *)(iVar8 + 0x24) = fVar1 * 1.2;
      *(float *)(iVar8 + 0x28) = fVar2 * 1.2;
    }
  }
  RemoveAllItems__11CBasePlayeri(param_1,1);
  return;
}


