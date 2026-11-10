// SpinDownCall__11CBaseTurret  @ 0011959c
void SpinDownCall__11CBaseTurret(int param_1)

{
  *(undefined4 *)(param_1 + 0x690) = 0;
  return;
}


// SpinDownCall__7CTurret  @ 00117da8
void SpinDownCall__7CTurret(int *param_1)

{
  float fVar1;
  
  if (param_1[0x1a4] != 0) {
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
    fVar1 = *(float *)(*param_1 + 0x138);
    if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 0x40) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),6,"turret/tu_active2.wav",0,0,0x20,100);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"turret/tu_spindown.wav",0x3f000000,0x3f4ccccd,
                 0,100);
    }
    *(float *)(*param_1 + 0x138) = *(float *)(*param_1 + 0x138) - 0.02;
    fVar1 = *(float *)(*param_1 + 0x138);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      *(undefined4 *)(*param_1 + 0x138) = 0;
      param_1[0x1a4] = 0;
    }
  }
  return;
}


