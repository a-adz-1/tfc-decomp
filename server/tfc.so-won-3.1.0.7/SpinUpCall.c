// SpinUpCall__11CBaseTurret  @ 0011958c
void SpinUpCall__11CBaseTurret(int param_1)

{
  *(undefined4 *)(param_1 + 0x690) = 1;
  return;
}


// SpinUpCall__7CTurret  @ 00117c18
void SpinUpCall__7CTurret(int *param_1)

{
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if (param_1[0x1a4] == 0) {
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
    if (param_1[0x1bf] == 0) {
      *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),4,"turret/tu_spinup.wav",0x3f000000,0x3f4ccccd,0,
                 100);
      param_1[0x1bf] = 1;
      *(undefined4 *)(*param_1 + 0x138) = 0x3dcccccd;
    }
    else if (*(float *)(*param_1 + 0x138) < 1.0) {
      *(float *)(*param_1 + 0x138) = *(float *)(*param_1 + 0x138) + 0.075;
    }
    else {
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,"turret/tu_active2.wav",0x3f000000,0x3f4ccccd,0
                 ,100);
      param_1[3] = -0x10000;
      param_1[4] = (int)ActiveThink__11CBaseTurret;
      param_1[0x1bf] = 0;
      param_1[0x1a4] = 1;
    }
    if (param_1[0x1a4] == 0) {
      return;
    }
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)ActiveThink__11CBaseTurret;
  return;
}


