// Ping__11CBaseTurret  @ 00114230
void Ping__11CBaseTurret(int *param_1)

{
  float fVar1;
  float fVar2;
  code *pcVar3;
  
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x19e]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x19e] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x19e] = (int)(*gpGlobals + 1.0);
  }
  else {
    fVar1 = (float)param_1[0x19e];
    fVar2 = *gpGlobals;
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
      param_1[0x19e] = (int)(*gpGlobals + 1.0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),3,"turret/tu_ping.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      pcVar3 = *(code **)(param_1[0xf2] + 0x220);
    }
    else {
      if (param_1[0x187] < 1) {
        return;
      }
      pcVar3 = *(code **)(param_1[0xf2] + 0x224);
    }
    (*pcVar3)(param_1);
  }
  return;
}


