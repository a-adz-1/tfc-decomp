// UpdateStepSound__11CBasePlayer  @ 000da5b0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateStepSound__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  char *__s1;
  undefined4 uVar7;
  int *__s2;
  bool bVar8;
  float local_c4;
  float local_c0;
  float local_8c;
  float local_88;
  undefined4 local_84;
  float local_80;
  float local_7c;
  float local_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  char acStack_44 [12];
  undefined1 uStack_38;
  
  iVar6 = (**(code **)(*g_pGameRules + 0xd8))(g_pGameRules,param_1,0x3f800000);
  if (iVar6 == 0) {
    return;
  }
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x19c];
  if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    return;
  }
  iVar6 = *param_1;
  if ((*(byte *)(iVar6 + 0x185) & 0x10) != 0) {
    return;
  }
  fVar1 = SQRT(*(float *)(iVar6 + 0x28) * *(float *)(iVar6 + 0x28) +
               *(float *)(iVar6 + 0x24) * *(float *)(iVar6 + 0x24) +
               *(float *)(iVar6 + 0x20) * *(float *)(iVar6 + 0x20));
  iVar6 = IsOnLadder__11CBasePlayer(param_1);
  if (((*(byte *)(*param_1 + 0x185) & 0x40) == 0) && (iVar6 == 0)) {
    fVar2 = 120.0;
    local_c0 = 210.0;
    local_c4 = 0.0;
  }
  else {
    fVar2 = 60.0;
    local_c0 = 80.0;
    local_c4 = 0.1;
  }
  if ((iVar6 == 0) && ((*(byte *)(*param_1 + 0x185) & 2) == 0)) {
    return;
  }
  iVar4 = *param_1;
  bVar8 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar4 + 0x20))) << 10) >> 8)
             | (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar4 + 0x20)) << 0xe) >> 8)) ==
       0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN(*(float *)(iVar4 + 0x24))) << 10) >>
                   8) |
            (byte)((ushort)((ushort)(DAT_00175484 == *(float *)(iVar4 + 0x24)) << 0xe) >> 8)) ==
      0x40)) {
    fVar3 = *(float *)(iVar4 + 0x28);
    bVar8 = (byte)(DAT_00175488 < fVar3 |
                   (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00175488 == fVar3) << 0xe) >> 8)) == 0x40;
  }
  if (bVar8) {
    return;
  }
  if ((0x3f < (byte)((fVar2 < fVar1 |
                      (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) &&
     ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x19c]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x19c] == 0.0) << 0xe) >> 8)) != 0x40)) {
    return;
  }
  SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,1);
  bVar8 = (byte)(fVar1 < local_c0 |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_c0)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == local_c0) << 0xe) >> 8)) != 1;
  iVar4 = *param_1;
  fVar1 = (*(float *)(iVar4 + 0xa4) + *(float *)(iVar4 + 0xb0)) * 0.5;
  fVar2 = (*(float *)(iVar4 + 0xa8) + *(float *)(iVar4 + 0xb4)) * 0.5;
  local_78 = (*(float *)(iVar4 + 0xb8) - *(float *)(iVar4 + 0xac)) * 0.2 + *(float *)(iVar4 + 0xac);
  local_84 = *(undefined4 *)(iVar4 + 0xac);
  local_8c = fVar1;
  local_88 = fVar2;
  local_80 = fVar1;
  local_7c = fVar2;
  if (iVar6 != 0) {
    uVar7 = 8;
    fVar2 = 0.35;
    fVar1 = 0.35;
LAB_000da872:
    fVar1 = fVar1 + *gpGlobals;
    goto LAB_000daaed;
  }
  iVar6 = UTIL_PointContents__FRC6Vector(&local_80);
  if (iVar6 == -3) {
    uVar7 = 7;
    fVar2 = 0.65;
    fVar1 = 0.6;
    goto LAB_000da872;
  }
  iVar6 = UTIL_PointContents__FRC6Vector(&local_8c);
  if (iVar6 == -3) {
    switchD_000daa06::caseD_4d();
    return;
  }
  fStack_6c = *(float *)(*param_1 + 0xac);
  fStack_60 = fStack_6c + 4.0;
  fStack_6c = fStack_6c - 24.0;
  fStack_74 = fVar1;
  fStack_70 = fVar2;
  fStack_68 = fVar1;
  fStack_64 = fVar2;
  fStack_5c = fVar1;
  fStack_58 = fVar2;
  fStack_54 = fStack_6c;
  fStack_50 = fVar1;
  fStack_4c = fVar2;
  fStack_48 = fStack_60;
  __s1 = (char *)(*DAT_00175550)(*(undefined4 *)(*param_1 + 0x17c),&fStack_68,&fStack_74);
  if (__s1 != (char *)0x0) {
    if (*__s1 == '-') {
      __s1 = __s1 + 2;
    }
    if ((*__s1 == '{') || (*__s1 == '!')) {
      __s1 = __s1 + 1;
    }
    __s2 = param_1 + 0x1ed;
    iVar6 = strncasecmp(__s1,(char *)__s2,0xc);
    if (iVar6 != 0) {
      strcpy(acStack_44,__s1);
      uStack_38 = 0;
      strcpy((char *)__s2,acStack_44);
      uVar5 = TEXTURETYPE_Find__FPc(__s2);
      *(undefined1 *)((int)param_1 + 0x7c1) = uVar5;
    }
  }
  uVar7 = MapTextureTypeStepType__Fc((int)*(char *)((int)param_1 + 0x7c1));
  switch(*(undefined1 *)((int)param_1 + 0x7c1)) {
  default:
    fVar2 = 0.5;
    if (bVar8) goto LAB_000daae0;
    fVar2 = 0.2;
LAB_000daac2:
    if (bVar8) goto LAB_000daae0;
    fVar1 = 0.4;
    break;
  case 0x44:
    fVar2 = 0.55;
    if (!bVar8) {
      fVar2 = 0.25;
      goto LAB_000daac2;
    }
LAB_000daae0:
    fVar1 = 0.3;
    break;
  case 0x4d:
  case 0x54:
    fVar2 = 0.5;
    if (bVar8) goto LAB_000daa80;
    fVar1 = 0.2;
LAB_000daa62:
    fVar2 = fVar1;
    if (bVar8) goto LAB_000daa80;
    fVar1 = 0.4;
    goto LAB_000daa8b;
  case 0x56:
    fVar2 = 0.7;
    fVar1 = _FUN_00139f50;
    if (!bVar8) goto LAB_000daa62;
LAB_000daa80:
    fVar1 = 0.3;
LAB_000daa8b:
    param_1[0x19c] = (int)(fVar1 + *gpGlobals);
    goto LAB_000dab02;
  }
  fVar1 = fVar1 + *gpGlobals;
LAB_000daaed:
  param_1[0x19c] = (int)fVar1;
LAB_000dab02:
  param_1[0x19c] = (int)(local_c4 + (float)param_1[0x19c]);
  if ((*(byte *)(*param_1 + 0x185) & 0x40) != 0) {
    fVar2 = fVar2 * 0.35;
  }
  PlayStepSound__11CBasePlayerif(param_1,uVar7,fVar2);
  return;
}


