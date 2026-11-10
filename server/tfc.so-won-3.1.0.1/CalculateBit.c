// CalculateBit__10CItemArmorf  @ 000ecc58
undefined4 CalculateBit__10CItemArmorf(undefined4 param_1,float param_2)

{
  undefined4 uVar1;
  
  if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_2 == 0.3) << 0xe) >> 8)) == 0x40) {
    uVar1 = 0x2000;
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_2 == 0.6) << 0xe) >> 8)) == 0x40) {
    uVar1 = 0x4000;
  }
  else if ((byte)(0.8 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_2 == 0.8) << 0xe) >> 8)) == 0x40) {
    uVar1 = 0x8000;
  }
  else {
    (*DAT_001a7f34)(4,"Bad ArmorType.\n");
    uVar1 = 0;
  }
  return uVar1;
}


