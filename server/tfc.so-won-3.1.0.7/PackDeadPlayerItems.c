// PackDeadPlayerItems__11CBasePlayer  @ 000d4c44
void PackDeadPlayerItems__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *local_138;
  int local_100;
  int local_e8;
  int local_d4 [33];
  int local_50 [20];
  
  iVar6 = 0;
  memset(local_50,0,0x50);
  memset(local_d4,-1,0x84);
  if (cb_prematch_time + 3.0 <= *gpGlobals) {
    iVar3 = (**(code **)(*g_pGameRules + 0xc4))(g_pGameRules,param_1);
    iVar4 = (**(code **)(*g_pGameRules + 200))(g_pGameRules,param_1);
    if ((iVar3 != 9) || (iVar4 != 0xc)) {
      local_e8 = 0;
      piVar5 = param_1 + 0x227;
      do {
        if ((*piVar5 != 0) && (local_100 = *piVar5, local_100 != 0)) {
          local_138 = local_50 + iVar6;
          do {
            if (iVar3 == 7) {
              *local_138 = local_100;
LAB_000d4dc5:
              local_138 = local_138 + 1;
              iVar6 = iVar6 + 1;
            }
            else if (((iVar3 == 8) && (param_1[0x22d] != 0)) && (local_100 == param_1[0x22d])) {
              *local_138 = local_100;
              goto LAB_000d4dc5;
            }
            local_100 = *(int *)(local_100 + 0x468);
          } while (local_100 != 0);
        }
        if ((piVar5[1] != 0) && (local_100 = piVar5[1], local_100 != 0)) {
          local_138 = local_50 + iVar6;
          do {
            if (iVar3 == 7) {
              *local_138 = local_100;
LAB_000d4e3d:
              local_138 = local_138 + 1;
              iVar6 = iVar6 + 1;
            }
            else if (((iVar3 == 8) && (param_1[0x22d] != 0)) && (local_100 == param_1[0x22d])) {
              *local_138 = local_100;
              goto LAB_000d4e3d;
            }
            local_100 = *(int *)(local_100 + 0x468);
          } while (local_100 != 0);
        }
        if ((piVar5[2] != 0) && (local_100 = piVar5[2], local_100 != 0)) {
          local_138 = local_50 + iVar6;
          do {
            if (iVar3 == 7) {
              *local_138 = local_100;
LAB_000d4eb5:
              local_138 = local_138 + 1;
              iVar6 = iVar6 + 1;
            }
            else if (((iVar3 == 8) && (param_1[0x22d] != 0)) && (local_100 == param_1[0x22d])) {
              *local_138 = local_100;
              goto LAB_000d4eb5;
            }
            local_100 = *(int *)(local_100 + 0x468);
          } while (local_100 != 0);
        }
        piVar5 = piVar5 + 3;
        local_e8 = local_e8 + 3;
      } while (local_e8 < 6);
      if (iVar4 != 0xc) {
        local_e8 = 0;
        piVar5 = local_d4;
        do {
          if ((0 < param_1[local_e8 + 0x231]) &&
             ((iVar4 == 10 ||
              (((iVar4 == 0xb && (param_1[0x22d] != 0)) &&
               ((iVar6 = (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x144))(param_1[0x22d]),
                local_e8 == iVar6 ||
                ((param_1[0x22d] != 0 &&
                 (iVar6 = (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x148))(param_1[0x22d]),
                 local_e8 == iVar6)))))))))) {
            *piVar5 = local_e8;
            piVar5 = piVar5 + 1;
          }
          iVar6 = local_e8 + 1;
          if ((0 < param_1[local_e8 + 0x232]) &&
             ((iVar4 == 10 ||
              (((iVar4 == 0xb && (param_1[0x22d] != 0)) &&
               ((iVar3 = (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x144))(param_1[0x22d]),
                iVar6 == iVar3 ||
                ((param_1[0x22d] != 0 &&
                 (iVar3 = (**(code **)(*(int *)(param_1[0x22d] + 0x444) + 0x148))(param_1[0x22d]),
                 iVar6 == iVar3)))))))))) {
            *piVar5 = iVar6;
            piVar5 = piVar5 + 1;
          }
          local_e8 = local_e8 + 2;
        } while (local_e8 < 0x20);
      }
      iVar6 = *param_1;
      piVar5 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                                ("weaponbox",iVar6 + 8,iVar6 + 0x50,*(undefined4 *)(iVar6 + 0x208));
      *(undefined4 *)(*piVar5 + 0x50) = 0;
      *(undefined4 *)(*piVar5 + 0x58) = 0;
      piVar5[3] = -0x10000;
      piVar5[4] = (int)Kill__10CWeaponBox;
      *(float *)(*piVar5 + 0x104) = *gpGlobals + 120.0;
      iVar6 = 0;
      if (local_d4[0] != -1) {
        local_100 = 0;
        do {
          PackAmmo__10CWeaponBoxii
                    (piVar5,(&_15CBasePlayerItem_AmmoInfoArray)
                            [*(int *)((int)local_d4 + local_100) * 2] - (int)gpGlobals[0x26],
                     param_1[*(int *)((int)local_d4 + local_100) + 0x231]);
          iVar3 = local_100 + 4;
          local_100 = local_100 + 4;
        } while (*(int *)((int)local_d4 + iVar3) != -1);
      }
      iVar3 = 0;
      while (local_50[0] != 0) {
        PackWeapon__10CWeaponBoxP15CBasePlayerItem(piVar5,*(undefined4 *)((int)local_50 + iVar3));
        iVar6 = iVar6 + 1;
        iVar3 = iVar6 * 4;
        local_50[0] = local_50[iVar6];
      }
      if (iVar4 != 0xc) {
        piVar5[0x33] = param_1[0x33];
        piVar5[0x35] = param_1[0x35];
        piVar5[0x39] = param_1[0x39];
        piVar5[0x37] = param_1[0x37];
        *(undefined4 *)(*piVar5 + 0x1bc) = *(undefined4 *)(*param_1 + 0x1bc);
      }
      iVar6 = *piVar5;
      iVar3 = *param_1;
      fVar1 = *(float *)(iVar3 + 0x24);
      fVar2 = *(float *)(iVar3 + 0x28);
      *(float *)(iVar6 + 0x20) = *(float *)(iVar3 + 0x20) * 1.2;
      *(float *)(iVar6 + 0x24) = fVar1 * 1.2;
      *(float *)(iVar6 + 0x28) = fVar2 * 1.2;
    }
  }
  RemoveAllItems__11CBasePlayeri(param_1,0);
  return;
}


