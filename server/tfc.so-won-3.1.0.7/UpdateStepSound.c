// UpdateStepSound__11CBasePlayer  @ 000d7ec0
uint UpdateStepSound__11CBasePlayer(uint *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined1 uVar4;
  byte bVar8;
  int iVar5;
  undefined2 uVar9;
  uint uVar6;
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
  
  iVar5 = (**(code **)(*g_pGameRules + 0xd8))(g_pGameRules,param_1,0x3f800000);
  if (iVar5 == 0) {
    return 0;
  }
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x1bd];
  bVar8 = (fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1;
  uVar7 = (uint)CONCAT21((short)((uint)param_1 >> 0x10),bVar8) << 8;
  if (bVar8 < 0x40) {
    return uVar7;
  }
  uVar6 = *param_1;
  if ((*(byte *)(uVar6 + 0x1a5) & 0x10) != 0) {
    return uVar7;
  }
  fVar1 = SQRT(*(float *)(uVar6 + 0x28) * *(float *)(uVar6 + 0x28) +
               *(float *)(uVar6 + 0x24) * *(float *)(uVar6 + 0x24) +
               *(float *)(uVar6 + 0x20) * *(float *)(uVar6 + 0x20));
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
  uVar7 = *param_1;
  bVar10 = false;
  bVar8 = (byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(uVar7 + 0x20))) << 10) >> 8) |
          (byte)((ushort)((ushort)(g_vecZero == *(float *)(uVar7 + 0x20)) << 0xe) >> 8);
  uVar9 = (undefined2)(uVar7 >> 0x10);
  uVar6 = (uint)CONCAT21(uVar9,bVar8) << 8 ^ 0x4000;
  if ((bVar8 == 0x40) &&
     (bVar8 = (byte)((ushort)((ushort)(NAN(DAT_001c0fe4) || NAN(*(float *)(uVar7 + 0x24))) << 10) >>
                    8) |
              (byte)((ushort)((ushort)(DAT_001c0fe4 == *(float *)(uVar7 + 0x24)) << 0xe) >> 8),
     uVar6 = (uint)CONCAT21(uVar9,bVar8) << 8 ^ 0x4000, bVar8 == 0x40)) {
    fVar3 = *(float *)(uVar7 + 0x28);
    bVar8 = DAT_001c0fe8 < fVar3 |
            (byte)((ushort)((ushort)(NAN(DAT_001c0fe8) || NAN(fVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(DAT_001c0fe8 == fVar3) << 0xe) >> 8);
    bVar10 = bVar8 == 0x40;
    uVar6 = CONCAT31(CONCAT21(uVar9,bVar8),bVar10);
  }
  if (bVar10) {
    return uVar6;
  }
  if ((0x3f < (byte)((fVar2 < fVar1 |
                      (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) &&
     (bVar8 = (byte)((ushort)((ushort)NAN((float)param_1[0x1bd]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x1bd] == 0.0) << 0xe) >> 8), bVar8 != 0x40))
  {
    return (uint)CONCAT21((short)(uVar6 >> 0x10),bVar8) << 8 ^ 0x4000;
  }
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,1);
  bVar10 = (byte)(fVar1 < local_bc |
                  (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_bc)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == local_bc) << 0xe) >> 8)) != 1;
  uVar7 = *param_1;
  fVar1 = (*(float *)(uVar7 + 0xc4) + *(float *)(uVar7 + 0xd0)) * 0.5;
  fVar2 = (*(float *)(uVar7 + 200) + *(float *)(uVar7 + 0xd4)) * 0.5;
  local_74 = (*(float *)(uVar7 + 0xd8) - *(float *)(uVar7 + 0xcc)) * 0.2 + *(float *)(uVar7 + 0xcc);
  local_80 = *(undefined4 *)(uVar7 + 0xcc);
  if (iVar5 == 0) {
    local_88 = fVar1;
    local_84 = fVar2;
    local_7c = fVar1;
    local_78 = fVar2;
    iVar5 = UTIL_PointContents__FRC6Vector(&local_7c);
    if (iVar5 == -3) {
      uVar7 = FUN_000d8412();
      return uVar7;
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
      __s1 = (char *)(*DAT_001c10b0)(*(undefined4 *)(*param_1 + 0x19c),&local_64,&local_70);
      if (__s1 != (char *)0x0) {
        if (*__s1 == '-') {
          __s1 = __s1 + 2;
        }
        if ((*__s1 == '{') || (*__s1 == '!')) {
          __s1 = __s1 + 1;
        }
        __s2 = param_1 + 0x20e;
        iVar5 = strncasecmp(__s1,(char *)__s2,0xc);
        if (iVar5 != 0) {
          strcpy(local_40,__s1);
          local_34 = 0;
          strcpy((char *)__s2,local_40);
          uVar4 = TEXTURETYPE_Find__FPc(__s2);
          *(undefined1 *)((int)param_1 + 0x845) = uVar4;
        }
      }
      MapTextureTypeStepType__Fc((int)*(char *)((int)param_1 + 0x845));
      switch(*(undefined1 *)((int)param_1 + 0x845)) {
      case 0x4d:
      case 0x54:
      case 0x56:
        if (bVar10) {
          fVar1 = 0.3;
        }
        else {
          fVar1 = 0.4;
        }
        param_1[0x1bd] = (uint)(fVar1 + *gpGlobals);
        goto LAB_000d8469;
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
  param_1[0x1bd] = (uint)fVar1;
LAB_000d8469:
  param_1[0x1bd] = (uint)(local_c0 + (float)param_1[0x1bd]);
  return *param_1;
}


