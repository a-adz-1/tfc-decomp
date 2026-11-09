// DropPlayerItem__11CBasePlayerPc  @ 000df860
void DropPlayerItem__11CBasePlayerPc(int *param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined1 auStack_54 [8];
  int iStack_4c;
  byte bStack_30;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
  if ((iVar3 != 0) &&
     ((byte)(0.0 < (float)weaponstay._12_4_ |
             (byte)((ushort)((ushort)NAN((float)weaponstay._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)weaponstay._12_4_ == 0.0) << 0xe) >> 8)) != 1)) {
    iVar3 = -1;
    pcVar7 = param_2;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (iVar3 == -2) {
      param_2 = (char *)0x0;
    }
    iVar3 = 0;
    do {
      puVar6 = (undefined4 *)param_1[iVar3 + 0x206];
      if (puVar6 != (undefined4 *)0x0) {
        do {
          if (param_2 == (char *)0x0) {
            if (puVar6 == (undefined4 *)param_1[0x20c]) break;
          }
          else {
            iVar4 = strcmp(param_2,(char *)(*(int *)*puVar6 + *(int *)(gpGlobals + 0x98)));
            if (iVar4 == 0) break;
          }
          puVar6 = (undefined4 *)puVar6[0xfb];
        } while (puVar6 != (undefined4 *)0x0);
        if (puVar6 != (undefined4 *)0x0) {
          (**(code **)(*g_pGameRules + 0x1c))(g_pGameRules,param_1,puVar6);
          UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
          bVar2 = (byte)puVar6[0xfc] & 0x1f;
          *(uint *)(*param_1 + 0x148) =
               *(uint *)(*param_1 + 0x148) & (-2 << bVar2 | 0xfffffffeU >> 0x20 - bVar2);
          fStack_1c = *(float *)(gpGlobals + 0x28) * 10.0;
          fStack_18 = *(float *)(gpGlobals + 0x2c) * 10.0;
          fStack_14 = *(float *)(gpGlobals + 0x30) * 10.0;
          iVar3 = *param_1;
          local_10 = *(float *)(iVar3 + 8) + fStack_1c;
          fStack_c = *(float *)(iVar3 + 0xc) + fStack_18;
          fStack_8 = *(float *)(iVar3 + 0x10) + fStack_14;
          piVar5 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                                    ("weaponbox",&local_10,iVar3 + 0x50,
                                     *(undefined4 *)(iVar3 + 0x1e8));
          *(undefined4 *)(*piVar5 + 0x50) = 0;
          *(undefined4 *)(*piVar5 + 0x58) = 0;
          PackWeapon__10CWeaponBoxP15CBasePlayerItem(piVar5,puVar6);
          iVar3 = *piVar5;
          local_10 = *(float *)(gpGlobals + 0x28) * 300.0;
          fStack_c = *(float *)(gpGlobals + 0x2c) * 300.0;
          fStack_8 = *(float *)(gpGlobals + 0x30) * 300.0;
          fStack_28 = *(float *)(gpGlobals + 0x28) * 100.0;
          fStack_24 = *(float *)(gpGlobals + 0x2c) * 100.0;
          fStack_20 = *(float *)(gpGlobals + 0x30) * 100.0;
          fStack_1c = local_10 + fStack_28;
          fStack_18 = fStack_c + fStack_24;
          fStack_14 = fStack_8 + fStack_20;
          *(float *)(iVar3 + 0x20) = fStack_1c;
          *(float *)(iVar3 + 0x24) = fStack_18;
          *(float *)(iVar3 + 0x28) = fStack_14;
          (**(code **)(puVar6[0xf2] + 0x110))(puVar6,auStack_54);
          iVar3 = GetAmmoIndex__11CBasePlayerPCc(iStack_4c);
          if (iVar3 == -1) {
            return;
          }
          if ((bStack_30 & 0x10) != 0) {
            PackAmmo__10CWeaponBoxii
                      (piVar5,iStack_4c - *(int *)(gpGlobals + 0x98),param_1[iVar3 + 0x20f]);
            param_1[iVar3 + 0x20f] = 0;
            return;
          }
          PackAmmo__10CWeaponBoxii
                    (piVar5,iStack_4c - *(int *)(gpGlobals + 0x98),
                     param_1[iVar3 + 0x20f] - (param_1[iVar3 + 0x20f] >> 0x1f) >> 1);
          param_1[iVar3 + 0x20f] = param_1[iVar3 + 0x20f] - (param_1[iVar3 + 0x20f] >> 0x1f) >> 1;
          return;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
  }
  return;
}


