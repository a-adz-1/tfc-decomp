// UpdateStepSound__11CBasePlayer  @ 000d7a10
/* WARNING: Switch with 1 destination removed at 0x000d7e53 : 20 cases all go to same destination */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * UpdateStepSound__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  ushort uVar3;
  float fVar4;
  undefined1 uVar5;
  byte bVar8;
  int iVar6;
  int *piVar7;
  char *__s1;
  char cVar9;
  bool bVar10;
  bool bVar11;
  float local_c8;
  float local_c4;
  float local_8c;
  float local_88;
  undefined4 local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  char local_44 [12];
  undefined1 local_38;
  
  iVar6 = (**(code **)(*g_pGameRules + 0xd8))(g_pGameRules,param_1,0x3f800000);
  if (iVar6 == 0) {
    return (int *)0x0;
  }
  uVar3 = (ushort)((float)param_1[0x1c7] < *gpGlobals) << 8 |
          (ushort)(NAN((float)param_1[0x1c7]) || NAN(*gpGlobals)) << 10;
  if ((char)(uVar3 >> 8) == '\0') {
    return (int *)(uint)uVar3;
  }
  iVar6 = *param_1;
  if ((*(byte *)(iVar6 + 0x1a5) & 0x10) != 0) {
    return param_1;
  }
  fVar4 = SQRT(*(float *)(iVar6 + 0x28) * *(float *)(iVar6 + 0x28) +
               *(float *)(iVar6 + 0x24) * *(float *)(iVar6 + 0x24) +
               *(float *)(iVar6 + 0x20) * *(float *)(iVar6 + 0x20));
  bVar10 = *(int *)(iVar6 + 0x108) == 5;
  if (((*(byte *)(iVar6 + 0x1a5) & 0x40) != 0) || (bVar10)) {
    fVar1 = 60.0;
    local_c4 = 80.0;
    local_c8 = 0.1;
  }
  else {
    fVar1 = 120.0;
    local_c4 = 210.0;
    local_c8 = 0.0;
  }
  if ((!bVar10) && ((*(byte *)(*param_1 + 0x1a5) & 2) == 0)) {
    return (int *)*param_1;
  }
  bVar11 = false;
  iVar6 = *param_1;
  bVar8 = (byte)((ushort)((ushort)(NAN(*(float *)(iVar6 + 0x20)) || NAN(g_vecZero)) << 10) >> 8) |
          (byte)((ushort)((ushort)(*(float *)(iVar6 + 0x20) == g_vecZero) << 0xe) >> 8);
  piVar7 = (int *)((uint)bVar8 << 8 ^ 0x4000);
  if ((bVar8 == 0x40) &&
     (bVar8 = (byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar6 + 0x24))) << 10) >>
                    8) |
              (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar6 + 0x24)) << 0xe) >> 8),
     piVar7 = (int *)((uint)bVar8 << 8 ^ 0x4000), bVar8 == 0x40)) {
    fVar2 = *(float *)(iVar6 + 0x28);
    bVar8 = DAT_0019f668 < fVar2 |
            (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(DAT_0019f668 == fVar2) << 0xe) >> 8);
    bVar11 = bVar8 == 0x40;
    piVar7 = (int *)(uint)CONCAT11(bVar8,bVar11);
  }
  if (bVar11) {
    return piVar7;
  }
  if ((0x3f < (byte)((fVar1 < fVar4 |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar4)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == fVar4) << 0xe) >> 8)) - 1)) &&
     (bVar8 = (byte)((ushort)((ushort)NAN((float)param_1[0x1c7]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x1c7] == 0.0) << 0xe) >> 8), bVar8 != 0x40))
  {
    return (int *)((uint)bVar8 << 8 ^ 0x4000);
  }
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,1);
  bVar11 = (byte)(fVar4 < local_c4 |
                  (byte)((ushort)((ushort)(NAN(fVar4) || NAN(local_c4)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar4 == local_c4) << 0xe) >> 8)) == 1;
  iVar6 = *param_1;
  fVar4 = (*(float *)(iVar6 + 0xc4) + *(float *)(iVar6 + 0xd0)) * 0.5;
  fVar1 = (*(float *)(iVar6 + 200) + *(float *)(iVar6 + 0xd4)) * 0.5;
  local_78 = (float)_FUN_001506d8 * (*(float *)(iVar6 + 0xd8) - *(float *)(iVar6 + 0xcc)) +
             *(float *)(iVar6 + 0xcc);
  local_84 = *(undefined4 *)(iVar6 + 0xcc);
  if (bVar10) {
    fVar4 = 0.35;
    goto LAB_000d7eda;
  }
  local_8c = fVar4;
  local_88 = fVar1;
  local_80 = fVar4;
  local_7c = fVar1;
  iVar6 = UTIL_PointContents__FRC6Vector(&local_80);
  if (iVar6 == -3) {
    fVar4 = 0.6;
    goto LAB_000d7eda;
  }
  iVar6 = UTIL_PointContents__FRC6Vector(&local_8c);
  if (iVar6 == -3) {
    if (!bVar11) {
LAB_000d7eb1:
      if (!bVar11) goto LAB_000d7ecc;
    }
    fVar4 = 0.4;
  }
  else {
    local_6c = *(float *)(*param_1 + 0xcc);
    local_60 = local_6c + 4.0;
    local_6c = local_6c - 24.0;
    local_74 = fVar4;
    local_70 = fVar1;
    local_68 = fVar4;
    local_64 = fVar1;
    local_5c = fVar4;
    local_58 = fVar1;
    local_54 = local_6c;
    local_50 = fVar4;
    local_4c = fVar1;
    local_48 = local_60;
    __s1 = (char *)(*DAT_0019f730)(*(undefined4 *)(*param_1 + 0x19c),&local_68,&local_74);
    if (__s1 != (char *)0x0) {
      cVar9 = *__s1;
      if (cVar9 == '-') {
        __s1 = __s1 + 2;
        cVar9 = *__s1;
      }
      if ((cVar9 == '{') || (cVar9 == '!')) {
        __s1 = __s1 + 1;
      }
      piVar7 = param_1 + 0x218;
      iVar6 = strncasecmp(__s1,(char *)piVar7,0xc);
      if (iVar6 != 0) {
        strcpy(local_44,__s1);
        local_38 = 0;
        strcpy((char *)piVar7,local_44);
        uVar5 = TEXTURETYPE_Find__FPc(piVar7);
        *(undefined1 *)((int)param_1 + 0x86d) = uVar5;
      }
    }
    if (bVar11) goto LAB_000d7eb1;
LAB_000d7ecc:
    fVar4 = 0.3;
  }
LAB_000d7eda:
  param_1[0x1c7] = (int)(fVar4 + *gpGlobals);
  param_1[0x1c7] = (int)(local_c8 + (float)param_1[0x1c7]);
  return (int *)*param_1;
}


