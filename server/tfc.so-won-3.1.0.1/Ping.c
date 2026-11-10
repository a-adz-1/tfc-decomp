// Ping__11CBaseTurret  @ 0010733c
void Ping__11CBaseTurret(int *param_1)

{
  code *pcVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x1a1]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x1a1] == 0.0) << 0xe) >> 8)) == 0x40) {
    param_1[0x1a1] = (int)(*gpGlobals + 1.0);
  }
  else {
    if (*gpGlobals < (float)param_1[0x1a1]) {
      if (param_1[0x18a] < 1) {
        return;
      }
      pcVar1 = *(code **)(param_1[0xf5] + 0x224);
    }
    else {
      param_1[0x1a1] = (int)(*gpGlobals + 1.0);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),3,"turret/tu_ping.wav",0x3f800000,0x3f4ccccd,0,
                 100);
      pcVar1 = *(code **)(param_1[0xf5] + 0x220);
    }
    (*pcVar1)(param_1);
  }
  return;
}


