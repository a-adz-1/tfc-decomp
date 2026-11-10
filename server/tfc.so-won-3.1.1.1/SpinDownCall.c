// SpinDownCall__11CBaseTurret  @ 0011d54c
void SpinDownCall__11CBaseTurret(int param_1)

{
  *(undefined4 *)(param_1 + 0x6a0) = 0;
  return;
}


// SpinDownCall__7CTurret  @ 0011cf08
void SpinDownCall__7CTurret(int *param_1)

{
  float fVar1;
  int iVar2;
  
  if (param_1[0x1a8] != 0) {
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,2);
    iVar2 = *param_1;
    if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0x138)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(iVar2 + 0x138) == 1.0) << 0xe) >> 8)) == 0x40) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar2 + 0x208),6,"turret/tu_active2.wav",0,0,0x20,100);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"turret/tu_spindown.wav",0x3f000000,0x3f4ccccd,
                 0,100);
      iVar2 = *param_1;
    }
    *(float *)(iVar2 + 0x138) = *(float *)(iVar2 + 0x138) - 0.02;
    fVar1 = *(float *)(*param_1 + 0x138);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      *(undefined4 *)(*param_1 + 0x138) = 0;
      param_1[0x1a8] = 0;
    }
  }
  return;
}


