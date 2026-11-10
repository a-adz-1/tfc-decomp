// TurretDeath__11CBaseTurret  @ 00108798
void TurretDeath__11CBaseTurret(int *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  longdouble lVar5;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  local_4 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = local_4;
  if (*(int *)(*param_1 + 0x170) != 2) {
    *(undefined4 *)(*param_1 + 0x170) = 2;
    lVar4 = (longdouble)(*DAT_001a7fac)(0,0x3f800000);
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
    if (param_1[400] == 0) {
      param_1[0x19e] = -0x3e900000;
    }
    else {
      param_1[0x19e] = -0x3d4c0000;
    }
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,5);
    (**(code **)(param_1[0xf5] + 0x220))(param_1);
  }
  (**(code **)(param_1[0xf5] + 0x224))(param_1);
  lVar5 = (longdouble)(*DAT_001a7fac)(0,0x40000000);
  lVar5 = lVar5 + (longdouble)*(float *)(*param_1 + 0x1e4);
  lVar4 = (longdouble)*gpGlobals;
  if (0x3f < (byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
    (*DAT_001a7ef8)(0,0x17,0,0);
    (*DAT_001a7f00)(5);
    lVar4 = (longdouble)
            (*DAT_001a7fac)(*(undefined4 *)(*param_1 + 0xc4),*(undefined4 *)(*param_1 + 0xd0));
    (*DAT_001a7f14)((float)lVar4);
    lVar4 = (longdouble)
            (*DAT_001a7fac)(*(undefined4 *)(*param_1 + 200),*(undefined4 *)(*param_1 + 0xd4));
    (*DAT_001a7f14)((float)lVar4);
    (*DAT_001a7f14)(*(float *)(*param_1 + 0x10) - (float)(param_1[400] << 6));
    (*DAT_001a7f08)((int)g_sModelIndexSmoke);
    (*DAT_001a7f00)(0x19);
    (*DAT_001a7f00)(param_1[400] * -5 + 10);
    (*DAT_001a7efc)();
  }
  lVar5 = (longdouble)(*DAT_001a7fac)(0,0x40a00000);
  iVar2 = *param_1;
  lVar5 = lVar5 + (longdouble)*(float *)(iVar2 + 0x1e4);
  lVar4 = (longdouble)*gpGlobals;
  if (0x3f < (byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
    lVar4 = (longdouble)(*DAT_001a7fac)(*(undefined4 *)(iVar2 + 0xc4),*(undefined4 *)(iVar2 + 0xd0))
    ;
    lVar5 = (longdouble)
            (*DAT_001a7fac)(*(undefined4 *)(*param_1 + 200),*(undefined4 *)(*param_1 + 0xd4));
    local_c = (float)lVar5;
    local_8 = 0.0;
    local_10 = (float)lVar4;
    if (param_1[400] == 0) {
      lVar4 = (longdouble)
              (*DAT_001a7fac)(*(undefined4 *)(*param_1 + 0x10),*(undefined4 *)(*param_1 + 0xd8));
      local_8 = local_8 + (float)lVar4;
    }
    else {
      lVar4 = (longdouble)
              (*DAT_001a7fac)(*(undefined4 *)(*param_1 + 0xcc),*(undefined4 *)(*param_1 + 0x10));
      local_8 = local_8 + (float)lVar4;
    }
    UTIL_Sparks__FRC6Vector(&local_10);
  }
  if (param_1[0xfb] != 0) {
    iVar2 = MoveTurret__11CBaseTurret(param_1);
    if ((iVar2 == 0) && (*(float *)(*param_1 + 0x1e4) + 5.0 < *gpGlobals)) {
      *(undefined4 *)(*param_1 + 0x138) = 0;
      param_1[3] = 0;
      param_1[4] = 0;
    }
  }
  return;
}


