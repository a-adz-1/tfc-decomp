// Ping__11CBaseTurret  @ 0011d05c
void Ping__11CBaseTurret(int *param_1)

{
  float fVar1;
  float fVar2;
  code *pcVar3;
  
  fVar1 = (float)param_1[0x1c1];
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x1c1] = (int)(*gpGlobals + 1.0);
  }
  else {
    fVar2 = *gpGlobals;
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
      if (param_1[0x1aa] < 1) {
        return;
      }
      pcVar3 = *(code **)(param_1[0x115] + 0x22c);
    }
    else {
      param_1[0x1c1] = (int)(fVar2 + 1.0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"turret/tu_ping.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      pcVar3 = *(code **)(param_1[0x115] + 0x228);
    }
    (*pcVar3)(param_1);
  }
  return;
}


