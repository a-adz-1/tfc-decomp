// IsLegalClass__11CBasePlayeri  @ 000e43d4
undefined4 IsLegalClass__11CBasePlayeri(int param_1,int param_2)

{
  uint in_ECX;
  
  if (((byte)((byte)((ushort)((ushort)NAN(spy_off) << 10) >> 8) |
             (byte)((ushort)((ushort)(spy_off == 1.0) << 0xe) >> 8)) != 0x40) || (param_2 != 8)) {
    if (param_2 == 1) {
      in_ECX = 1;
    }
    else if (param_2 == 2) {
      in_ECX = 2;
    }
    else if (param_2 == 3) {
      in_ECX = 4;
    }
    else if (param_2 == 4) {
      in_ECX = 8;
    }
    else if (param_2 == 5) {
      in_ECX = 0x10;
    }
    else if (param_2 == 6) {
      in_ECX = 0x20;
    }
    else if (param_2 == 7) {
      in_ECX = 0x40;
    }
    else if (param_2 == 8) {
      in_ECX = 0x100;
    }
    else if (param_2 == 9) {
      in_ECX = 0x200;
    }
    else if (param_2 == 10) {
      in_ECX = 0x80;
    }
    if (((illegalclasses & in_ECX) == 0) &&
       (((&illegalclasses)[*(int *)(param_1 + 0x120)] & in_ECX) == 0)) {
      return 1;
    }
  }
  return 0;
}


