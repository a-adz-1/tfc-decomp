// decode_sleb128  @ 001207bc
byte * decode_sleb128(byte *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint local_8;
  
  uVar2 = 0;
  local_8 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    local_8 = local_8 | (bVar1 & 0x7f) << ((byte)uVar2 & 0x1f);
    uVar2 = uVar2 + 7;
  } while ((char)bVar1 < '\0');
  if ((uVar2 < 0x20) && ((bVar1 & 0x40) != 0)) {
    local_8 = local_8 | -1 << ((byte)uVar2 & 0x1f);
  }
  *param_2 = local_8;
  return param_1;
}


// decode_uleb128  @ 0012077c
byte * decode_uleb128(byte *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar2 = 0;
  while( true ) {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar3 = uVar3 | (bVar1 & 0x7f) << (bVar2 & 0x1f);
    if (-1 < (char)bVar1) break;
    bVar2 = bVar2 + 7;
  }
  *param_2 = uVar3;
  return param_1;
}


