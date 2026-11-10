// PackDeadPlayerItems__11CBasePlayer  @ 000d4b44
void PackDeadPlayerItems__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int local_f0;
  int local_ec;
  int local_d8 [33];
  int local_54 [20];
  
  local_ec = 0;
  local_f0 = 0;
  memset(local_54,0,0x50);
  memset(local_d8,-1,0x84);
  fVar2 = cb_prematch_time + 3.0;
  fVar1 = *gpGlobals;
  if ((byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
    iVar4 = (**(code **)(*g_pGameRules + 0xc4))(g_pGameRules,param_1);
    iVar5 = (**(code **)(*g_pGameRules + 200))(g_pGameRules,param_1);
    if ((iVar4 != 9) || (iVar5 != 0xc)) {
      iVar7 = 0;
      do {
        for (iVar3 = param_1[iVar7 + 0x231]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x478)) {
          if (iVar4 == 7) {
            local_54[local_ec] = iVar3;
            local_ec = local_ec + 1;
          }
          else if (((iVar4 == 8) && (param_1[0x237] != 0)) && (iVar3 == param_1[0x237])) {
            local_54[local_ec] = iVar3;
            local_ec = local_ec + 1;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 6);
      if (iVar5 != 0xc) {
        iVar4 = 0;
        do {
          if ((0 < param_1[iVar4 + 0x23b]) &&
             ((iVar5 == 10 ||
              (((iVar5 == 0xb && (iVar7 = param_1[0x237], iVar7 != 0)) &&
               ((iVar7 = (**(code **)(*(int *)(iVar7 + 0x454) + 0x144))(iVar7), iVar4 == iVar7 ||
                ((iVar7 = param_1[0x237], iVar7 != 0 &&
                 (iVar7 = (**(code **)(*(int *)(iVar7 + 0x454) + 0x148))(iVar7), iVar4 == iVar7)))))
               ))))) {
            local_d8[local_f0] = iVar4;
            local_f0 = local_f0 + 1;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0x20);
      }
      iVar4 = *param_1;
      piVar6 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                                ("weaponbox",iVar4 + 8,iVar4 + 0x50,*(undefined4 *)(iVar4 + 0x208));
      *(undefined4 *)(*piVar6 + 0x50) = 0;
      *(undefined4 *)(*piVar6 + 0x58) = 0;
      piVar6[3] = -0x10000;
      piVar6[4] = (int)Kill__10CWeaponBox;
      local_f0 = 0;
      local_ec = 0;
      *(float *)(*piVar6 + 0x104) = *gpGlobals + 120.0;
      while (local_d8[0] != -1) {
        iVar4 = local_d8[local_f0];
        PackAmmo__10CWeaponBoxii
                  (piVar6,(&_15CBasePlayerItem_AmmoInfoArray)[iVar4 * 2] - (int)gpGlobals[0x26],
                   param_1[iVar4 + 0x23b]);
        local_f0 = local_f0 + 1;
        local_d8[0] = local_d8[local_f0];
      }
      iVar4 = 0;
      while (local_54[0] != 0) {
        PackWeapon__10CWeaponBoxP15CBasePlayerItem(piVar6,*(undefined4 *)(iVar4 + (int)local_54));
        local_ec = local_ec + 1;
        iVar4 = local_ec * 4;
        local_54[0] = local_54[local_ec];
      }
      if (iVar5 != 0xc) {
        piVar6[0x33] = param_1[0x33];
        piVar6[0x35] = param_1[0x35];
        piVar6[0x39] = param_1[0x39];
        piVar6[0x37] = param_1[0x37];
        *(undefined4 *)(*piVar6 + 0x1bc) = *(undefined4 *)(*param_1 + 0x1bc);
      }
      iVar4 = *piVar6;
      iVar5 = *param_1;
      fVar1 = *(float *)(iVar5 + 0x24);
      fVar2 = *(float *)(iVar5 + 0x28);
      *(float *)(iVar4 + 0x20) = *(float *)(iVar5 + 0x20) * 1.2;
      *(float *)(iVar4 + 0x24) = fVar1 * 1.2;
      *(float *)(iVar4 + 0x28) = fVar2 * 1.2;
    }
  }
  RemoveAllItems__11CBasePlayeri(param_1,0);
  return;
}


