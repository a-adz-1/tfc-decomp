// respawn__FP9entvars_si  @ 0008fa1c
void respawn__FP9entvars_si(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  
  if (cease_fire == 0) {
    if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(gpGlobals + 0x18)) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(gpGlobals + 0x18) == 0.0) << 0xe) >> 8)) == 0x40)
       && (fVar1 = *(float *)(gpGlobals + 0x14),
          (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
      (*DAT_001c10bc)("reload\n");
    }
    else {
      if (param_2 != 0) {
        CopyToBodyQue__FP9entvars_s(param_1);
      }
      iVar2 = GetClassPtr__H1Z11CBasePlayer_PX01_PX01(param_1);
      (**(code **)(*(int *)(iVar2 + 0x444) + 0xc))(iVar2);
    }
  }
  return;
}


