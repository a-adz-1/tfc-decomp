// TurretDeath__11CBaseTurret  @ 0011bc54
void TurretDeath__11CBaseTurret(int *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  longdouble lVar5;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  local_8 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = local_8;
  if (*(int *)(*param_1 + 0x170) != 2) {
    *(undefined4 *)(*param_1 + 0x170) = 2;
    lVar4 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
    lVar5 = (longdouble)0.33;
    if ((byte)(lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) == 1) {
      lVar5 = (longdouble)0.66;
      if ((byte)(lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) == 1) {
        uVar3 = *(undefined4 *)(*param_1 + 0x208);
        pcVar1 = "turret/tu_die3.wav";
      }
      else {
        uVar3 = *(undefined4 *)(*param_1 + 0x208);
        pcVar1 = "turret/tu_die2.wav";
      }
    }
    else {
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar1 = "turret/tu_die.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar3,4,pcVar1,0x3f800000,0x3f4ccccd,0,100);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,"turret/tu_active2.wav",0,0,0x20,100);
    if (param_1[0x1b0] == 0) {
      param_1[0x1be] = -0x3e900000;
    }
    else {
      param_1[0x1be] = -0x3d4c0000;
    }
    if (*(int *)(*param_1 + 0x128) != 5) {
      *(undefined4 *)(*param_1 + 0x130) = 0;
      *(undefined4 *)(*param_1 + 0x128) = 5;
      ResetSequenceInfo__14CBaseAnimating(param_1);
      *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
    }
    (**(code **)(param_1[0x115] + 0x228))(param_1);
  }
  (**(code **)(param_1[0x115] + 0x22c))(param_1);
  lVar5 = (longdouble)(*DAT_0019f80c)(0,0x40000000);
  lVar5 = lVar5 + (longdouble)*(float *)(*param_1 + 0x1e4);
  lVar4 = (longdouble)*gpGlobals;
  if (0x3f < (byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
    (*DAT_0019f758)(0,0x17,0,0);
    (*DAT_0019f760)(5);
    lVar4 = (longdouble)
            (*DAT_0019f80c)(*(undefined4 *)(*param_1 + 0xc4),*(undefined4 *)(*param_1 + 0xd0));
    (*DAT_0019f774)((float)lVar4);
    lVar4 = (longdouble)
            (*DAT_0019f80c)(*(undefined4 *)(*param_1 + 200),*(undefined4 *)(*param_1 + 0xd4));
    (*DAT_0019f774)((float)lVar4);
    (*DAT_0019f774)(*(float *)(*param_1 + 0x10) - (float)(param_1[0x1b0] << 6));
    (*DAT_0019f768)((int)g_sModelIndexSmoke);
    (*DAT_0019f760)(0x19);
    (*DAT_0019f760)(param_1[0x1b0] * -5 + 10);
    (*DAT_0019f75c)();
  }
  lVar5 = (longdouble)(*DAT_0019f80c)(0,0x40a00000);
  iVar2 = *param_1;
  lVar5 = lVar5 + (longdouble)*(float *)(iVar2 + 0x1e4);
  lVar4 = (longdouble)*gpGlobals;
  if (0x3f < (byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
    lVar4 = (longdouble)(*DAT_0019f80c)(*(undefined4 *)(iVar2 + 0xc4),*(undefined4 *)(iVar2 + 0xd0))
    ;
    lVar5 = (longdouble)
            (*DAT_0019f80c)(*(undefined4 *)(*param_1 + 200),*(undefined4 *)(*param_1 + 0xd4));
    local_10 = (float)lVar5;
    local_c = 0.0;
    local_14 = (float)lVar4;
    if (param_1[0x1b0] == 0) {
      lVar4 = (longdouble)
              (*DAT_0019f80c)(*(undefined4 *)(*param_1 + 0x10),*(undefined4 *)(*param_1 + 0xd8));
      lVar4 = lVar4 + (longdouble)local_c;
    }
    else {
      lVar4 = (longdouble)
              (*DAT_0019f80c)(*(undefined4 *)(*param_1 + 0xcc),*(undefined4 *)(*param_1 + 0x10));
      lVar4 = lVar4 + (longdouble)local_c;
    }
    local_c = (float)lVar4;
    UTIL_Sparks__FRC6Vector(&local_14);
  }
  if (param_1[0x11b] != 0) {
    iVar2 = MoveTurret__11CBaseTurret(param_1);
    if ((iVar2 == 0) && (*(float *)(*param_1 + 0x1e4) + 5.0 < *gpGlobals)) {
      *(undefined4 *)(*param_1 + 0x138) = 0;
      param_1[3] = 0;
      param_1[4] = 0;
    }
  }
  return;
}


