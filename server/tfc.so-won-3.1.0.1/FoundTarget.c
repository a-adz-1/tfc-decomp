// FoundTarget__12CTFSentrygun  @ 000dee3c
void FoundTarget__12CTFSentrygun(int *param_1)

{
  if ((0 < param_1[0x33]) || ((0 < param_1[0x39] && (param_1[0x23] == 3)))) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),3,"weapons/turrspot.wav",0x3f800000,0x3f4ccccd,0,
               100);
  }
  param_1[3] = -0x10000;
  param_1[4] = (int)Attack__12CTFSentrygun;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[0x176] = (int)(*gpGlobals + 0.1);
  if ((float)param_1[0xed] < *gpGlobals) {
    param_1[0xed] = (int)(*gpGlobals + 0.5);
  }
  return;
}


