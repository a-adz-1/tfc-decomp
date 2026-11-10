// Ping__11CBaseTurret  @ 00116e08
void Ping__11CBaseTurret(int *param_1)

{
  code *pcVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x1bd]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x1bd] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x1bd] = (int)(*gpGlobals + 1.0);
  }
  else {
    if (*gpGlobals < (float)param_1[0x1bd]) {
      if (param_1[0x1a6] < 1) {
        return;
      }
      pcVar1 = *(code **)(param_1[0x111] + 0x22c);
    }
    else {
      param_1[0x1bd] = (int)(*gpGlobals + 1.0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"turret/tu_ping.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      pcVar1 = *(code **)(param_1[0x111] + 0x228);
    }
    (*pcVar1)(param_1);
  }
  return;
}


