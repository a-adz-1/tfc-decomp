// SpinUpCall__11CBaseTurret  @ 00116600
void SpinUpCall__11CBaseTurret(int param_1)

{
  *(undefined4 *)(param_1 + 0x614) = 1;
  return;
}


// SpinUpCall__7CTurret  @ 00114f80
void SpinUpCall__7CTurret(int *param_1)

{
  float fVar1;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  if (param_1[0x185] == 0) {
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
    if (param_1[0x1a0] == 0) {
      *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),4,"turret/tu_spinup.wav",0x3f000000,0x3f4ccccd,0,
                 100);
      param_1[0x1a0] = 1;
      *(undefined4 *)(*param_1 + 0x118) = 0x3dcccccd;
    }
    else {
      fVar1 = *(float *)(*param_1 + 0x118);
      if ((byte)((1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) - 1) < 0x40) {
        *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),6,"turret/tu_active2.wav",0x3f000000,0x3f4ccccd
                   ,0,100);
        param_1[3] = -0x10000;
        param_1[4] = (int)ActiveThink__11CBaseTurret;
        param_1[0x1a0] = 0;
        param_1[0x185] = 1;
      }
      else {
        *(float *)(*param_1 + 0x118) = *(float *)(*param_1 + 0x118) + 0.075;
      }
    }
    if (param_1[0x185] == 0) {
      return;
    }
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)ActiveThink__11CBaseTurret;
  return;
}


