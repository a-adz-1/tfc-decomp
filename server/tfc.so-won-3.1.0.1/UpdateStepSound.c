// UpdateStepSound__11CBasePlayer  @ 000cc810
uint UpdateStepSound__11CBasePlayer(uint *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  undefined2 uVar9;
  uint uVar7;
  char *__s1;
  uint *__s2;
  bool bVar10;
  float local_c0;
  float local_bc;
  float local_88;
  float local_84;
  undefined4 local_80;
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
  float local_44;
  char local_40 [12];
  undefined1 local_34;
  byte bVar8;
  
  iVar5 = (**(code **)(*g_pGameRules + 0xd8))(g_pGameRules,param_1,0x3f800000);
  if (iVar5 == 0) {
    return 0;
  }
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x1a1];
  bVar8 = (fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1;
  uVar6 = (uint)CONCAT21((short)((uint)param_1 >> 0x10),bVar8) << 8;
  if (bVar8 < 0x40) {
    return uVar6;
  }
  uVar7 = *param_1;
  if ((*(byte *)(uVar7 + 0x1a5) & 0x10) != 0) {
    return uVar6;
  }
  fVar1 = SQRT(*(float *)(uVar7 + 0x28) * *(float *)(uVar7 + 0x28) +
               *(float *)(uVar7 + 0x24) * *(float *)(uVar7 + 0x24) +
               *(float *)(uVar7 + 0x20) * *(float *)(uVar7 + 0x20));
  iVar5 = IsOnLadder__11CBasePlayer(param_1);
  if (((*(byte *)(*param_1 + 0x1a5) & 0x40) == 0) && (iVar5 == 0)) {
    fVar2 = 120.0;
    local_bc = 210.0;
    local_c0 = 0.0;
  }
  else {
    fVar2 = 60.0;
    local_bc = 80.0;
    local_c0 = 0.1;
  }
  if ((iVar5 == 0) && ((*(byte *)(*param_1 + 0x1a5) & 2) == 0)) {
    return *param_1;
  }
  uVar6 = *param_1;
  bVar10 = false;
  bVar8 = (byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(uVar6 + 0x20))) << 10) >> 8) |
          (byte)((ushort)((ushort)(g_vecZero == *(float *)(uVar6 + 0x20)) << 0xe) >> 8);
  uVar9 = (undefined2)(uVar6 >> 0x10);
  uVar7 = (uint)CONCAT21(uVar9,bVar8) << 8 ^ 0x4000;
  if ((bVar8 == 0x40) &&
     (bVar8 = (byte)((ushort)((ushort)(NAN(DAT_001a7e04) || NAN(*(float *)(uVar6 + 0x24))) << 10) >>
                    8) |
              (byte)((ushort)((ushort)(DAT_001a7e04 == *(float *)(uVar6 + 0x24)) << 0xe) >> 8),
     uVar7 = (uint)CONCAT21(uVar9,bVar8) << 8 ^ 0x4000, bVar8 == 0x40)) {
    fVar3 = *(float *)(uVar6 + 0x28);
    bVar8 = DAT_001a7e08 < fVar3 |
            (byte)((ushort)((ushort)(NAN(DAT_001a7e08) || NAN(fVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(DAT_001a7e08 == fVar3) << 0xe) >> 8);
    bVar10 = bVar8 == 0x40;
    uVar7 = CONCAT31(CONCAT21(uVar9,bVar8),bVar10);
  }
  if (bVar10) {
    return uVar7;
  }
  if ((0x3f < (byte)((fVar2 < fVar1 |
                      (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) &&
     (bVar8 = (byte)((ushort)((ushort)NAN((float)param_1[0x1a1]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x1a1] == 0.0) << 0xe) >> 8), bVar8 != 0x40))
  {
    return (uint)CONCAT21((short)(uVar7 >> 0x10),bVar8) << 8 ^ 0x4000;
  }
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,1);
  bVar10 = (byte)(fVar1 < local_bc |
                  (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_bc)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == local_bc) << 0xe) >> 8)) != 1;
  uVar6 = *param_1;
  fVar1 = (*(float *)(uVar6 + 0xc4) + *(float *)(uVar6 + 0xd0)) * 0.5;
  fVar2 = (*(float *)(uVar6 + 200) + *(float *)(uVar6 + 0xd4)) * 0.5;
  local_74 = (*(float *)(uVar6 + 0xd8) - *(float *)(uVar6 + 0xcc)) * 0.2 + *(float *)(uVar6 + 0xcc);
  local_80 = *(undefined4 *)(uVar6 + 0xcc);
  if (iVar5 == 0) {
    local_88 = fVar1;
    local_84 = fVar2;
    local_7c = fVar1;
    local_78 = fVar2;
    iVar5 = UTIL_PointContents__FRC6Vector(&local_7c);
    if (iVar5 == -3) {
      fVar1 = 0.6;
LAB_000ccd62:
      param_1[0x1a1] = (uint)(fVar1 + *gpGlobals);
      goto LAB_000ccdb9;
    }
    iVar5 = UTIL_PointContents__FRC6Vector(&local_88);
    if (iVar5 != -3) {
      local_68 = *(float *)(*param_1 + 0xcc);
      local_5c = local_68 + 4.0;
      local_68 = local_68 - 24.0;
      local_70 = fVar1;
      local_6c = fVar2;
      local_64 = fVar1;
      local_60 = fVar2;
      local_58 = fVar1;
      local_54 = fVar2;
      local_50 = local_68;
      local_4c = fVar1;
      local_48 = fVar2;
      local_44 = local_5c;
      __s1 = (char *)(*DAT_001a7ed0)(*(undefined4 *)(*param_1 + 0x19c),&local_64,&local_70);
      if (__s1 != (char *)0x0) {
        if (*__s1 == '-') {
          __s1 = __s1 + 2;
        }
        if ((*__s1 == '{') || (*__s1 == '!')) {
          __s1 = __s1 + 1;
        }
        __s2 = param_1 + 0x1f2;
        iVar5 = strncasecmp(__s1,(char *)__s2,0xc);
        if (iVar5 != 0) {
          strcpy(local_40,__s1);
          local_34 = 0;
          strcpy((char *)__s2,local_40);
          uVar4 = TEXTURETYPE_Find__FPc(__s2);
          *(undefined1 *)((int)param_1 + 0x7d5) = uVar4;
        }
      }
      MapTextureTypeStepType__Fc((int)*(char *)((int)param_1 + 0x7d5));
      switch(*(undefined1 *)((int)param_1 + 0x7d5)) {
      case 0x4d:
      case 0x54:
      case 0x56:
        if (bVar10) {
          fVar1 = 0.3;
        }
        else {
          fVar1 = 0.4;
        }
        goto LAB_000ccd62;
      }
    }
    if (bVar10) {
      fVar1 = 0.3;
    }
    else {
      fVar1 = 0.4;
    }
    fVar1 = fVar1 + *gpGlobals;
  }
  else {
    fVar1 = *gpGlobals + 0.35;
  }
  param_1[0x1a1] = (uint)fVar1;
LAB_000ccdb9:
  param_1[0x1a1] = (uint)(local_c0 + (float)param_1[0x1a1]);
  return *param_1;
}


