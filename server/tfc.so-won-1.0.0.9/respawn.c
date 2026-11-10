// respawn__FP9entvars_ti  @ 000a1ee0
void respawn__FP9entvars_ti(char *param_1,int param_2)

{
  float fVar1;
  code *pcVar2;
  char **ppcVar3;
  int iStack_10;
  char *pcStack_c;
  
  if (cease_fire == 0) {
    if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(gpGlobals + 0x18)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(gpGlobals + 0x18) == 0.0) << 0xe) >> 8)) == 0x40)
       && (fVar1 = *(float *)(gpGlobals + 0x14),
          (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
      ppcVar3 = &pcStack_c;
      pcStack_c = "reload\n";
      pcVar2 = DAT_0017555c;
    }
    else {
      if (param_2 != 0) {
        pcStack_c = param_1;
        iStack_10 = 0xa1f28;
        CopyToBodyQue__FP9entvars_t();
      }
      pcStack_c = param_1;
      iStack_10 = 0xa1f31;
      iStack_10 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01();
      ppcVar3 = (char **)&iStack_10;
      pcVar2 = *(code **)(*(int *)(iStack_10 + 0x3c8) + 8);
    }
    *(undefined4 *)((int)ppcVar3 + -4) = 0xa1f4c;
    (*pcVar2)();
  }
  return;
}


