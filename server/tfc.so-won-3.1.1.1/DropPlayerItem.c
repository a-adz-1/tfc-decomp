// DropPlayerItem__11CBasePlayerPc  @ 000dd424
void DropPlayerItem__11CBasePlayerPc(int *param_1,uint *param_2)

{
  byte bVar1;
  char *__s1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined1 auStack_54 [8];
  char *pcStack_4c;
  byte bStack_30;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
  if (iVar3 == 0) {
    return;
  }
  if ((byte)(0.0 < (float)weaponstay._12_4_ |
             (byte)((ushort)((ushort)NAN((float)weaponstay._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)weaponstay._12_4_ == 0.0) << 0xe) >> 8)) == 1) {
    return;
  }
  uVar7 = (uint)param_2 & 3;
  puVar2 = param_2;
  if (uVar7 != 0) {
    puVar4 = param_2;
    if ((POPCOUNT(uVar7) & 1U) != 0) {
      if (uVar7 != 2) {
        if ((char)*param_2 == '\0') goto LAB_000dd4b1;
        puVar4 = (uint *)((int)param_2 + 1);
      }
      if ((char)*puVar4 == '\0') goto LAB_000dd4b1;
      puVar4 = (uint *)((int)puVar4 + 1);
    }
    if ((char)*puVar4 == '\0') goto LAB_000dd4b1;
    puVar2 = (uint *)((int)puVar4 + 1);
  }
  do {
    puVar4 = puVar2;
    uVar7 = *puVar4;
    if ((char)uVar7 == '\0') goto LAB_000dd4b1;
    if ((char)(uVar7 >> 8) == '\0') goto LAB_000dd4b0;
    if ((uVar7 & 0xff0000) == 0) goto LAB_000dd4af;
    puVar2 = puVar4 + 1;
  } while ((uVar7 & 0xff000000) != 0);
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_000dd4af:
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_000dd4b0:
  puVar4 = (uint *)((int)puVar4 + 1);
LAB_000dd4b1:
  if (puVar4 == param_2) {
    param_2 = (uint *)0x0;
  }
  iVar3 = 0;
  do {
    puVar8 = (undefined4 *)param_1[iVar3 + 0x231];
    if (puVar8 != (undefined4 *)0x0) {
      do {
        if (param_2 == (uint *)0x0) {
          if (puVar8 == (undefined4 *)param_1[0x237]) break;
        }
        else {
          iVar5 = strcmp((char *)param_2,(char *)(*(int *)*puVar8 + *(int *)(gpGlobals + 0x98)));
          if (iVar5 == 0) break;
        }
        puVar8 = (undefined4 *)puVar8[0x11e];
      } while (puVar8 != (undefined4 *)0x0);
      if (puVar8 != (undefined4 *)0x0) {
        (**(code **)(*g_pGameRules + 0x1c))(g_pGameRules,param_1,puVar8);
        UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
        bVar1 = (byte)puVar8[0x11f] & 0x1f;
        *(uint *)(*param_1 + 0x168) =
             *(uint *)(*param_1 + 0x168) & (-2 << bVar1 | 0xfffffffeU >> 0x20 - bVar1);
        fStack_1c = *(float *)(gpGlobals + 0x28) * 10.0;
        fStack_18 = *(float *)(gpGlobals + 0x2c) * 10.0;
        fStack_14 = *(float *)(gpGlobals + 0x30) * 10.0;
        iVar3 = *param_1;
        fStack_10 = fStack_1c + *(float *)(iVar3 + 8);
        fStack_c = fStack_18 + *(float *)(iVar3 + 0xc);
        fStack_8 = fStack_14 + *(float *)(iVar3 + 0x10);
        piVar6 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                                  ("weaponbox",&fStack_10,iVar3 + 0x50,
                                   *(undefined4 *)(iVar3 + 0x208));
        *(undefined4 *)(*piVar6 + 0x50) = 0;
        *(undefined4 *)(*piVar6 + 0x58) = 0;
        PackWeapon__10CWeaponBoxP15CBasePlayerItem(piVar6,puVar8);
        iVar3 = *piVar6;
        fStack_10 = *(float *)(gpGlobals + 0x28) * 300.0;
        fStack_c = *(float *)(gpGlobals + 0x2c) * 300.0;
        fStack_8 = *(float *)(gpGlobals + 0x30) * 300.0;
        fStack_28 = *(float *)(gpGlobals + 0x28) * 100.0;
        fStack_1c = fStack_10 + fStack_28;
        fStack_24 = *(float *)(gpGlobals + 0x2c) * 100.0;
        fStack_18 = fStack_c + fStack_24;
        fStack_20 = *(float *)(gpGlobals + 0x30) * 100.0;
        fStack_14 = fStack_8 + fStack_20;
        *(float *)(iVar3 + 0x20) = fStack_1c;
        *(float *)(iVar3 + 0x24) = fStack_18;
        *(float *)(iVar3 + 0x28) = fStack_14;
        (**(code **)(puVar8[0x115] + 0x118))(puVar8,auStack_54);
        __s1 = pcStack_4c;
        if (pcStack_4c == (char *)0x0) goto LAB_000dd6dd;
        iVar3 = 1;
        break;
      }
    }
    iVar3 = iVar3 + 1;
    if (5 < iVar3) {
      return;
    }
  } while( true );
  while (iVar3 = iVar3 + 1, iVar3 < 0x20) {
    if (((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar3 * 2] != (char *)0x0) &&
       (iVar5 = strcasecmp(__s1,(char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar3 * 2]), iVar5 == 0)
       ) goto LAB_000dd6e2;
  }
LAB_000dd6dd:
  iVar3 = -1;
LAB_000dd6e2:
  if (iVar3 == -1) {
    return;
  }
  if ((bStack_30 & 0x10) != 0) {
    PackAmmo__10CWeaponBoxii
              (piVar6,(int)pcStack_4c - *(int *)(gpGlobals + 0x98),param_1[iVar3 + 0x23b]);
    param_1[iVar3 + 0x23b] = 0;
    return;
  }
  PackAmmo__10CWeaponBoxii
            (piVar6,(int)pcStack_4c - *(int *)(gpGlobals + 0x98),
             param_1[iVar3 + 0x23b] - (param_1[iVar3 + 0x23b] >> 0x1f) >> 1);
  param_1[iVar3 + 0x23b] = param_1[iVar3 + 0x23b] - (param_1[iVar3 + 0x23b] >> 0x1f) >> 1;
  return;
}


