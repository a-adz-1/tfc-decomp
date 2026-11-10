// FoundTarget__12CTFSentrygun  @ 000eca34
void FoundTarget__12CTFSentrygun(int *param_1)

{
  float fVar1;
  float fVar2;
  
  if ((0 < param_1[0x33]) || ((0 < param_1[0x39] && (param_1[0x23] == 3)))) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"weapons/turrspot.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)Attack__12CTFSentrygun;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x196] = (int)(*gpGlobals + 0.1);
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x10d];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
    param_1[0x10d] = (int)(fVar1 + 0.5);
  }
  return;
}


