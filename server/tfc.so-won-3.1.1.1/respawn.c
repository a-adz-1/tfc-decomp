// respawn__FP9entvars_si  @ 00094960
void respawn__FP9entvars_si(char *param_1,int param_2)

{
  float fVar1;
  code *pcVar2;
  char **ppcVar3;
  int iStack_14;
  char *pcStack_10;
  
  if (cease_fire == 0) {
    if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(gpGlobals + 0x18)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(gpGlobals + 0x18) == 0.0) << 0xe) >> 8)) == 0x40)
       && (fVar1 = *(float *)(gpGlobals + 0x14),
          (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
      pcStack_10 = "reload\n";
      ppcVar3 = &pcStack_10;
      pcVar2 = DAT_0019f73c;
    }
    else {
      if (param_2 != 0) {
        pcStack_10 = param_1;
        iStack_14 = 0x949b7;
        CopyToBodyQue__FP9entvars_s();
      }
      pcStack_10 = param_1;
      iStack_14 = 0x949c0;
      iStack_14 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01();
      ppcVar3 = (char **)&iStack_14;
      pcVar2 = *(code **)(*(int *)(iStack_14 + 0x454) + 0xc);
    }
    *(undefined4 *)((int)ppcVar3 + -4) = 0x949e5;
    (*pcVar2)();
  }
  return;
}


