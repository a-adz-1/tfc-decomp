// DropPlayerItem__11CBasePlayerPc  @ 000dea90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DropPlayerItem__11CBasePlayerPc(int *param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined1 local_50 [8];
  int local_48;
  byte local_2c;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
  if ((iVar3 != 0) &&
     ((byte)(0.0 < (float)weaponstay._12_4_ |
             (byte)((ushort)((ushort)NAN((float)weaponstay._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)weaponstay._12_4_ == 0.0) << 0xe) >> 8)) != 1)) {
    iVar3 = -1;
    pcVar6 = param_2;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (iVar3 == -2) {
      param_2 = (char *)0x0;
    }
    iVar3 = 0;
    do {
      puVar7 = (undefined4 *)param_1[iVar3 + 0x227];
      if (puVar7 != (undefined4 *)0x0) {
        do {
          if (param_2 == (char *)0x0) {
            if (puVar7 == (undefined4 *)param_1[0x22d]) break;
          }
          else {
            iVar4 = strcmp(param_2,(char *)(*(int *)*puVar7 + *(int *)(gpGlobals + 0x98)));
            if (iVar4 == 0) break;
          }
          puVar7 = (undefined4 *)puVar7[0x11a];
        } while (puVar7 != (undefined4 *)0x0);
        if (puVar7 != (undefined4 *)0x0) {
          (**(code **)(*g_pGameRules + 0x1c))(g_pGameRules,param_1,puVar7);
          UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
          bVar2 = (byte)puVar7[0x11b] & 0x1f;
          *(uint *)(*param_1 + 0x168) =
               *(uint *)(*param_1 + 0x168) & (-2 << bVar2 | 0xfffffffeU >> 0x20 - bVar2);
          local_18 = *(float *)(gpGlobals + 0x28) * 10.0;
          local_14 = *(float *)(gpGlobals + 0x2c) * 10.0;
          local_10 = *(float *)(gpGlobals + 0x30) * 10.0;
          iVar3 = *param_1;
          local_c = *(float *)(iVar3 + 8) + local_18;
          local_8 = *(float *)(iVar3 + 0xc) + local_14;
          local_4 = *(float *)(iVar3 + 0x10) + local_10;
          piVar5 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                                    ("weaponbox",&local_c,iVar3 + 0x50,
                                     *(undefined4 *)(iVar3 + 0x208));
          *(undefined4 *)(*piVar5 + 0x50) = 0;
          *(undefined4 *)(*piVar5 + 0x58) = 0;
          PackWeapon__10CWeaponBoxP15CBasePlayerItem(piVar5,puVar7);
          iVar3 = *piVar5;
          local_c = *(float *)(gpGlobals + 0x28) * _FUN_0014b92c;
          local_8 = *(float *)(gpGlobals + 0x2c) * _FUN_0014b92c;
          local_4 = _FUN_0014b92c * *(float *)(gpGlobals + 0x30);
          local_24 = *(float *)(gpGlobals + 0x28) * 100.0;
          local_20 = *(float *)(gpGlobals + 0x2c) * 100.0;
          local_1c = *(float *)(gpGlobals + 0x30) * 100.0;
          local_18 = local_c + local_24;
          local_14 = local_8 + local_20;
          local_10 = local_4 + local_1c;
          *(float *)(iVar3 + 0x20) = local_18;
          *(float *)(iVar3 + 0x24) = local_14;
          *(float *)(iVar3 + 0x28) = local_10;
          (**(code **)(puVar7[0x111] + 0x118))(puVar7,local_50);
          iVar3 = GetAmmoIndex__11CBasePlayerPCc(local_48);
          if (iVar3 == -1) {
            return;
          }
          if ((local_2c & 0x10) != 0) {
            PackAmmo__10CWeaponBoxii
                      (piVar5,local_48 - *(int *)(gpGlobals + 0x98),param_1[iVar3 + 0x231]);
            param_1[iVar3 + 0x231] = 0;
            return;
          }
          PackAmmo__10CWeaponBoxii
                    (piVar5,local_48 - *(int *)(gpGlobals + 0x98),
                     param_1[iVar3 + 0x231] - (param_1[iVar3 + 0x231] >> 0x1f) >> 1);
          param_1[iVar3 + 0x231] = param_1[iVar3 + 0x231] - (param_1[iVar3 + 0x231] >> 0x1f) >> 1;
          return;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
  }
  return;
}


