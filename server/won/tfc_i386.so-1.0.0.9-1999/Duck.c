// Duck__11CBasePlayer  @ 000d9a60
void Duck__11CBasePlayer(int *param_1)

{
  int iVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  undefined4 uStack_78;
  int iStack_74;
  undefined4 uStack_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if ((*(byte *)(*param_1 + 0x160) & 4) == 0) {
    iVar1 = *param_1;
    local_40 = *(float *)(iVar1 + 8);
    fStack_3c = *(float *)(iVar1 + 0xc);
    fStack_38 = *(float *)(iVar1 + 0x10);
    if ((*(byte *)(iVar1 + 0x185) & 2) != 0) {
      uStack_1c = 0xc1800000;
      fStack_18 = -16.0;
      fStack_14 = -18.0;
      fStack_10 = -16.0;
      uStack_c = 0xc1800000;
      uStack_8 = 0xc2100000;
      uStack_28 = 0;
      uStack_24 = 0;
      uStack_20 = 0x41900000;
      local_40 = local_40 + 0.0;
      fStack_3c = fStack_3c + 0.0;
      fStack_38 = fStack_38 + 18.0;
      fStack_34 = local_40;
      fStack_30 = fStack_3c;
      fStack_2c = fStack_38;
    }
    UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
              (&local_40,&local_40,0,1,*(undefined4 *)(*param_1 + 0x1e8),&uStack_78);
    if (iStack_74 == 0) {
      *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xbf;
      *(byte *)(param_1 + 0x19a) = *(byte *)(param_1 + 0x19a) & 0xf7;
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + 0x154) = 0;
      *(undefined4 *)(iVar1 + 0x158) = 0;
      *(undefined4 *)(iVar1 + 0x15c) = 0x41e00000;
      fStack_34 = 16.0;
      fStack_30 = 16.0;
      fStack_2c = 36.0;
      uStack_28 = 0xc1800000;
      uStack_24 = 0xc1800000;
      uStack_20 = 0xc2100000;
      UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&uStack_28,&fStack_34);
      iVar1 = *param_1;
      *(float *)(iVar1 + 8) = local_40;
      *(float *)(iVar1 + 0xc) = fStack_3c;
      *(float *)(iVar1 + 0x10) = fStack_38;
    }
  }
  else {
    if (((*(byte *)(param_1 + 0x18d) & 4) != 0) && ((*(byte *)(*param_1 + 0x185) & 0x40) == 0)) {
      param_1[0x19f] = (int)*gpGlobals;
      *(byte *)(param_1 + 0x19a) = *(byte *)(param_1 + 0x19a) | 8;
    }
    fVar2 = *gpGlobals - (float)param_1[0x19f];
    if ((*(byte *)(param_1 + 0x19a) & 8) != 0) {
      if (((byte)((0.4 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.4) << 0xe) >> 8)) - 1) < 0x40) ||
         ((*(byte *)(*param_1 + 0x185) & 2) == 0)) {
        iVar1 = *param_1;
        if ((*(byte *)(iVar1 + 0x185) & 2) != 0) {
          local_60 = -16.0;
          local_5c = -16.0;
          local_58 = -18.0;
          local_6c = -16.0;
          local_68 = -16.0;
          local_64 = -36.0;
          local_54 = 0;
          local_50 = 0;
          local_4c = 0x41900000;
          local_48 = *(float *)(iVar1 + 8) - 0.0;
          local_44 = *(float *)(iVar1 + 0xc) - 0.0;
          local_40 = *(float *)(iVar1 + 0x10) - 18.0;
          *(float *)(iVar1 + 8) = local_48;
          *(float *)(iVar1 + 0xc) = local_44;
          *(float *)(iVar1 + 0x10) = local_40;
          FixPlayerCrouchStuck__FP7edict_s(*(undefined4 *)(*param_1 + 0x1e8));
        }
        UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
        local_6c = 16.0;
        local_68 = 16.0;
        local_64 = 18.0;
        local_60 = -16.0;
        local_5c = -16.0;
        local_58 = -18.0;
        UTIL_SetSize__FP9entvars_tRC6VectorT1(*param_1,&local_60,&local_6c);
        iVar1 = *param_1;
        local_6c = 0.0;
        local_68 = 0.0;
        local_64 = 12.0;
        *(undefined4 *)(iVar1 + 0x154) = 0;
        *(undefined4 *)(iVar1 + 0x158) = 0;
        *(undefined4 *)(iVar1 + 0x15c) = 0x41400000;
        *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) | 0x40;
        *(byte *)(param_1 + 0x19a) = *(byte *)(param_1 + 0x19a) & 0xf7;
      }
      else {
        lVar3 = (longdouble)UTIL_SplineFraction__Fff(fVar2,0x40200000);
        iVar1 = *param_1;
        local_48 = 0.0;
        local_44 = 0.0;
        local_40 = 12.0;
        fStack_30 = -16.0;
        fStack_2c = -16.0;
        uStack_28 = 0xc1900000;
        uStack_24 = 0xc1800000;
        uStack_20 = 0xc1800000;
        uStack_1c = 0xc2100000;
        fStack_3c = 0.0;
        fStack_38 = 0.0;
        fStack_34 = 18.0;
        local_54 = 0;
        local_50 = 0;
        local_4c = 0xc0c00000;
        local_60 = (float)(lVar3 * (longdouble)0.0);
        local_5c = (float)(lVar3 * (longdouble)0.0);
        local_58 = (float)(lVar3 * (longdouble)-6.0);
        uStack_78 = 0;
        iStack_74 = 0;
        uStack_70 = 0x41e00000;
        lVar4 = (longdouble)1 - lVar3;
        fStack_18 = (float)(lVar4 * (longdouble)0.0);
        fStack_14 = (float)(lVar4 * (longdouble)0.0);
        fStack_10 = (float)(lVar4 * (longdouble)28.0);
        local_6c = local_60 + fStack_18;
        local_68 = (float)((longdouble)local_5c + lVar4 * (longdouble)0.0);
        local_64 = (float)(lVar3 * (longdouble)-6.0 + (longdouble)fStack_10);
        *(float *)(iVar1 + 0x154) = local_6c;
        *(float *)(iVar1 + 0x158) = local_68;
        *(float *)(iVar1 + 0x15c) = local_64;
      }
    }
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,1);
  }
  return;
}


