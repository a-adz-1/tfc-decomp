// MSG_BeginReading  @ 0005877c
void MSG_BeginReading(void)

{
  msg_readcount = 0;
  msg_badread = 0;
  return;
}


// MSG_CurrentBit  @ 00057d34
int MSG_CurrentBit(void)

{
  int iVar1;
  
  if (DAT_00114d38 == 0) {
    iVar1 = msg_readcount * 8;
  }
  else {
    iVar1 = DAT_00114d44 + DAT_00114d40 * 8;
  }
  return iVar1;
}


// MSG_EndBitReading  @ 00057e48
void MSG_EndBitReading(int param_1)

{
  if (*(int *)(param_1 + 0x10) < bfread) {
    msg_badread = 1;
  }
  msg_readcount = bfread;
  DAT_00114d3c = 0;
  DAT_00114d44 = 0;
  DAT_00114d40 = 0;
  DAT_00114d48 = 0;
  DAT_00114d38 = 0;
  return;
}


// MSG_EndBitWriting  @ 0005783c
void MSG_EndBitWriting(void)

{
  if ((*(ushort *)(DAT_00114d30 + 4) & 2) == 0) {
    *DAT_00114d2c = *DAT_00114d2c & (byte)(0xff >> (8U - (char)bfwrite & 0x1f));
    SZ_GetSpace(DAT_00114d30,1);
    bfwrite = 0;
    DAT_00114d2c = (byte *)0x0;
    DAT_00114d30 = 0;
  }
  return;
}


// MSG_IsBitReading  @ 00057d94
bool MSG_IsBitReading(void)

{
  return DAT_00114d38 != 0;
}


// MSG_IsBitWriting  @ 00057810
bool MSG_IsBitWriting(void)

{
  return DAT_00114d30 != 0;
}


// MSG_PeekBits  @ 0005810c
undefined4 MSG_PeekBits(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_20 [6];
  undefined4 local_8;
  
  puVar2 = &bfread;
  puVar3 = local_20;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_8 = MSG_ReadBits(param_1);
  puVar2 = local_20;
  puVar3 = &bfread;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return local_8;
}


// MSG_ReadAngle  @ 00058d0c
longdouble MSG_ReadAngle(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadChar();
  return (longdouble)((float)iVar1 * 1.40625);
}


// MSG_ReadBitAngle  @ 00057ccc
longdouble MSG_ReadBitAngle(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = MSG_ReadBits(param_1);
  return (longdouble)((360.0 / (float)(1 << ((byte)param_1 & 0x1f))) * (float)uVar1);
}


// MSG_ReadBitCoord  @ 00058280
longdouble MSG_ReadBitCoord(void)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = 0.0;
  local_8 = MSG_ReadOneBit();
  local_c = MSG_ReadOneBit();
  if ((local_8 != 0) || (local_c != 0)) {
    iVar1 = MSG_ReadOneBit();
    if (local_8 != 0) {
      local_8 = MSG_ReadBits(0xc);
    }
    if (local_c != 0) {
      local_c = MSG_ReadBits(3);
    }
    local_14 = (float)local_c * 0.125 + (float)local_8;
    if (iVar1 != 0) {
      local_14 = -local_14;
    }
  }
  return (longdouble)local_14;
}


// MSG_ReadBitData  @ 00058220
int MSG_ReadBitData(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 *local_10;
  int local_8;
  
  local_10 = param_1;
  for (local_8 = 0; local_8 < param_2; local_8 = local_8 + 1) {
    uVar1 = MSG_ReadBits(8);
    *local_10 = uVar1;
    local_10 = local_10 + 1;
  }
  return param_2;
}


// MSG_ReadBitString  @ 000581b4
undefined1 * MSG_ReadBitString(void)

{
  char cVar1;
  char *local_c;
  
  buf_192 = 0;
  local_c = &buf_192;
  while( true ) {
    cVar1 = MSG_ReadBits(8);
    if (cVar1 == '\0') break;
    *local_c = cVar1;
    local_c = local_c + 1;
  }
  *local_c = '\0';
  return &buf_192;
}


// MSG_ReadBitVec3Coord  @ 00058438
void MSG_ReadBitVec3Coord(float *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  
  iVar1 = MSG_ReadOneBit();
  iVar2 = MSG_ReadOneBit();
  iVar3 = MSG_ReadOneBit();
  if (iVar1 != 0) {
    lVar4 = (longdouble)MSG_ReadBitCoord();
    *param_1 = (float)lVar4;
  }
  if (iVar2 != 0) {
    lVar4 = (longdouble)MSG_ReadBitCoord();
    param_1[1] = (float)lVar4;
  }
  if (iVar3 != 0) {
    lVar4 = (longdouble)MSG_ReadBitCoord();
    param_1[2] = (float)lVar4;
  }
  return;
}


// MSG_ReadBits  @ 00057f7c
uint MSG_ReadBits(int param_1)

{
  uint uVar1;
  byte bVar2;
  uint local_10;
  uint local_8;
  
  if (msg_badread == 0) {
    if (7 < (int)DAT_00114d44) {
      bfread = bfread + 1;
      DAT_00114d44 = 0;
      DAT_00114d40 = DAT_00114d40 + 1;
      DAT_00114d48 = (uint *)((int)DAT_00114d48 + 1);
    }
    local_10 = DAT_00114d44 + param_1;
    bVar2 = (byte)DAT_00114d44;
    if (local_10 < 0x21) {
      local_8 = (&ROWBITTABLE)[param_1] & *DAT_00114d48 >> (bVar2 & 0x1f);
      if ((local_10 & 7) == 0) {
        DAT_00114d44 = 8;
        local_10 = (local_10 >> 3) - 1;
      }
      else {
        DAT_00114d44 = local_10 & 7;
        local_10 = local_10 >> 3;
      }
      DAT_00114d48 = (uint *)((int)DAT_00114d48 + local_10);
      bfread = bfread + local_10;
      DAT_00114d40 = DAT_00114d40 + local_10;
    }
    else {
      uVar1 = *DAT_00114d48;
      DAT_00114d48 = DAT_00114d48 + 1;
      DAT_00114d44 = local_10 & 7;
      local_8 = uVar1 >> (bVar2 & 0x1f) |
                (*DAT_00114d48 & (&ROWBITTABLE)[DAT_00114d44]) << (0x20 - bVar2 & 0x1f);
      bfread = bfread + 4;
      DAT_00114d40 = DAT_00114d40 + 4;
    }
    if (*(int *)(DAT_00114d38 + 0x10) < bfread) {
      msg_badread = 1;
      local_8 = 1;
    }
  }
  else {
    local_8 = 1;
  }
  return local_8;
}


// MSG_ReadBuf  @ 00058b7c
undefined4 MSG_ReadBuf(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (DAT_0059d8d0 < param_1 + msg_readcount) {
    msg_badread = 1;
    uVar1 = 0xffffffff;
  }
  else {
    Q_memcpy(param_2,DAT_0059d8c8 + msg_readcount,param_1);
    msg_readcount = param_1 + msg_readcount;
    uVar1 = 1;
  }
  return uVar1;
}


// MSG_ReadByte  @ 00058818
uint MSG_ReadByte(void)

{
  uint uVar1;
  
  if (DAT_0059d8d0 < msg_readcount + 1) {
    msg_badread = 1;
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)*(byte *)(DAT_0059d8c8 + msg_readcount);
    msg_readcount = msg_readcount + 1;
  }
  return uVar1;
}


// MSG_ReadChar  @ 000587ac
int MSG_ReadChar(void)

{
  int iVar1;
  
  if (DAT_0059d8d0 < msg_readcount + 1) {
    msg_badread = 1;
    iVar1 = -1;
  }
  else {
    iVar1 = (int)*(char *)(DAT_0059d8c8 + msg_readcount);
    msg_readcount = msg_readcount + 1;
  }
  return iVar1;
}


// MSG_ReadCoord  @ 00058628
longdouble MSG_ReadCoord(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadShort();
  return (longdouble)((float)iVar1 / 8.0);
}


// MSG_ReadFloat  @ 00058abc
longdouble MSG_ReadFloat(void)

{
  float fVar1;
  undefined4 local_8;
  
  local_8 = CONCAT13(*(undefined1 *)(DAT_0059d8c8 + msg_readcount + 3),
                     CONCAT12(*(undefined1 *)(DAT_0059d8c8 + msg_readcount + 2),
                              CONCAT11(*(undefined1 *)(DAT_0059d8c8 + msg_readcount + 1),
                                       *(undefined1 *)(DAT_0059d8c8 + msg_readcount))));
  msg_readcount = msg_readcount + 4;
  fVar1 = (float)(*LittleLong)(local_8);
  return (longdouble)fVar1;
}


// MSG_ReadHiresAngle  @ 00058d44
longdouble MSG_ReadHiresAngle(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadShort();
  return (longdouble)((float)iVar1 * 0.005493164);
}


// MSG_ReadLong  @ 000589d4
undefined4 MSG_ReadLong(void)

{
  undefined4 uVar1;
  
  if (DAT_0059d8d0 < msg_readcount + 4) {
    msg_badread = 1;
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = CONCAT13(*(undefined1 *)(DAT_0059d8c8 + msg_readcount + 3),
                     CONCAT12(*(undefined1 *)(DAT_0059d8c8 + msg_readcount + 2),
                              CONCAT11(*(undefined1 *)(DAT_0059d8c8 + msg_readcount + 1),
                                       *(undefined1 *)(DAT_0059d8c8 + msg_readcount))));
    msg_readcount = msg_readcount + 4;
  }
  return uVar1;
}


// MSG_ReadOneBit  @ 00057ebc
bool MSG_ReadOneBit(void)

{
  int iVar1;
  bool bVar2;
  
  if (msg_badread == 0) {
    if (7 < DAT_00114d44) {
      bfread = bfread + 1;
      DAT_00114d44 = 0;
      DAT_00114d40 = DAT_00114d40 + 1;
      DAT_00114d48 = DAT_00114d48 + 1;
    }
    if (*(int *)(DAT_00114d38 + 0x10) < bfread) {
      msg_badread = 1;
      bVar2 = true;
    }
    else {
      iVar1 = DAT_00114d44 * 4;
      DAT_00114d44 = DAT_00114d44 + 1;
      bVar2 = (*(uint *)(&BITTABLE + iVar1) & (uint)*DAT_00114d48) != 0;
    }
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}


// MSG_ReadSBits  @ 0005816c
int MSG_ReadSBits(int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = MSG_ReadOneBit();
  local_8 = MSG_ReadBits(param_1 + -1);
  if (iVar1 != 0) {
    local_8 = -local_8;
  }
  return local_8;
}


// MSG_ReadShort  @ 00058888
int MSG_ReadShort(void)

{
  int iVar1;
  
  if (DAT_0059d8d0 < msg_readcount + 2) {
    msg_badread = 1;
    iVar1 = -1;
  }
  else {
    iVar1 = (int)(short)((ushort)*(byte *)(DAT_0059d8c8 + msg_readcount) +
                        (ushort)*(byte *)(DAT_0059d8c8 + msg_readcount + 1) * 0x100);
    msg_readcount = msg_readcount + 2;
  }
  return iVar1;
}


// MSG_ReadString  @ 00058c0c
undefined1 * MSG_ReadString(void)

{
  int iVar1;
  undefined1 local_c;
  uint local_8;
  
  local_8 = 0;
  do {
    iVar1 = MSG_ReadChar();
    if ((iVar1 == -1) || (iVar1 == 0)) break;
    local_c = (undefined1)iVar1;
    string_247[local_8] = local_c;
    local_8 = local_8 + 1;
  } while (local_8 < 0x1fff);
  string_247[local_8] = 0;
  return string_247;
}


// MSG_ReadStringLine  @ 00058c88
undefined1 * MSG_ReadStringLine(void)

{
  int iVar1;
  undefined1 local_c;
  uint local_8;
  
  local_8 = 0;
  do {
    iVar1 = MSG_ReadChar();
    if (((iVar1 == -1) || (iVar1 == 0)) || (iVar1 == 10)) break;
    local_c = (undefined1)iVar1;
    string_251[local_8] = local_c;
    local_8 = local_8 + 1;
  } while (local_8 < 0x7ff);
  string_251[local_8] = 0;
  return string_251;
}


// MSG_ReadUsercmd  @ 00058d7c
void MSG_ReadUsercmd(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = SV_LookupDelta(FUN_000dfda4);
  MSG_StartBitReading(&net_message);
  DELTA_ParseDelta(param_2,param_1,uVar1);
  MSG_EndBitReading(&net_message);
  COM_NormalizeAngles(param_1 + 4);
  return;
}


// MSG_ReadVec3Coord  @ 000586b4
void MSG_ReadVec3Coord(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = MSG_IsBitReading();
  if (iVar1 == 0) {
    MSG_StartBitReading(param_1);
    MSG_ReadBitVec3Coord(param_2);
    MSG_EndBitReading(param_1);
  }
  else {
    MSG_ReadBitVec3Coord(param_2);
  }
  return;
}


// MSG_ReadWord  @ 00058930
uint MSG_ReadWord(void)

{
  uint uVar1;
  
  if (DAT_0059d8d0 < msg_readcount + 2) {
    msg_badread = 1;
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)CONCAT11(*(undefined1 *)(DAT_0059d8c8 + msg_readcount + 1),
                           *(undefined1 *)(DAT_0059d8c8 + msg_readcount));
    msg_readcount = msg_readcount + 2;
  }
  return uVar1;
}


// MSG_StartBitReading  @ 00057dc0
void MSG_StartBitReading(int param_1)

{
  DAT_00114d44 = 0;
  DAT_00114d40 = 0;
  DAT_00114d38 = param_1;
  if (*(int *)(param_1 + 0x10) < msg_readcount + 1) {
    msg_badread = 1;
  }
  bfread = msg_readcount + 1;
  DAT_00114d3c = msg_readcount;
  DAT_00114d48 = msg_readcount + *(int *)(param_1 + 8);
  return;
}


// MSG_StartBitWriting  @ 000577d0
void MSG_StartBitWriting(int param_1)

{
  bfwrite = 0;
  DAT_00114d2c = *(int *)(param_1 + 0x10) + *(int *)(param_1 + 8);
  DAT_00114d30 = param_1;
  return;
}


// MSG_WriteAngle  @ 00057578
void MSG_WriteAngle(undefined4 param_1,float param_2)

{
  MSG_WriteByte(param_1,(int)ROUND((param_2 * 256.0) / 360.0) & 0xff);
  return;
}


// MSG_WriteBitAngle  @ 00057c14
void MSG_WriteBitAngle(float param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 < 0x20) {
    uVar1 = 1 << ((byte)param_2 & 0x1f);
    MSG_WriteBits((int)ROUND((float)uVar1 * param_1) / 0x168 & uVar1 - 1,param_2);
  }
  else {
    Sys_Error("Can\'t write bit angle with 32 bits precision\n");
  }
  return;
}


// MSG_WriteBitCoord  @ 00058338
/* WARNING: Removing unreachable block (ram,0x00058420) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MSG_WriteBitCoord(float param_1)

{
  float fVar1;
  int local_18;
  
  fVar1 = (float)_FUN_000dffe0;
  local_18 = (int)ROUND(param_1);
  if (local_18 < 0) {
    local_18 = -local_18;
  }
  MSG_WriteOneBit(local_18);
  MSG_WriteOneBit(0);
  if ((local_18 != 0) && (MSG_WriteOneBit(param_1 <= fVar1), local_18 != 0)) {
    MSG_WriteBits(local_18,0xc);
  }
  return;
}


// MSG_WriteBitData  @ 00057bc0
void MSG_WriteBitData(undefined1 *param_1,int param_2)

{
  undefined1 *local_c;
  int local_8;
  
  local_c = param_1;
  for (local_8 = 0; local_8 < param_2; local_8 = local_8 + 1) {
    MSG_WriteBits(*local_c,8);
    local_c = local_c + 1;
  }
  return;
}


// MSG_WriteBitString  @ 00057b64
void MSG_WriteBitString(char *param_1)

{
  char *local_8;
  
  for (local_8 = param_1; *local_8 != '\0'; local_8 = local_8 + 1) {
    MSG_WriteBits((int)*local_8,8);
  }
  MSG_WriteBits(0,8);
  return;
}


// MSG_WriteBitVec3Coord  @ 000584a8
void MSG_WriteBitVec3Coord(float *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int local_20;
  
  local_20 = 0;
  fVar1 = *param_1;
  if (((byte)((0.125 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.125) << 0xe) >> 8)) - 1) < 0x40) ||
     (*param_1 <= -0.125)) {
    local_20 = 1;
  }
  iVar2 = local_20;
  local_20 = 0;
  fVar1 = param_1[1];
  if (((byte)((0.125 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.125) << 0xe) >> 8)) - 1) < 0x40) ||
     (param_1[1] <= -0.125)) {
    local_20 = 1;
  }
  iVar3 = local_20;
  local_20 = 0;
  fVar1 = param_1[2];
  if (((byte)((0.125 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.125) << 0xe) >> 8)) - 1) < 0x40) ||
     (param_1[2] <= -0.125)) {
    local_20 = 1;
  }
  MSG_WriteOneBit(iVar2);
  MSG_WriteOneBit(iVar3);
  MSG_WriteOneBit(local_20);
  if (iVar2 != 0) {
    MSG_WriteBitCoord(*param_1);
  }
  if (iVar3 != 0) {
    MSG_WriteBitCoord(param_1[1]);
  }
  if (local_20 != 0) {
    MSG_WriteBitCoord(param_1[2]);
  }
  return;
}


// MSG_WriteBits  @ 000578e4
void MSG_WriteBits(uint param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  uint local_10;
  uint local_c;
  
  if ((param_2 < 0x20) && (param_1 >> ((byte)param_2 & 0x1f) != 0)) {
    param_1 = (&ROWBITTABLE)[param_2];
  }
  bVar1 = 7 < (int)bfwrite;
  if (bVar1) {
    bfwrite = 0;
    DAT_00114d2c = (uint *)((int)DAT_00114d2c + 1);
  }
  local_c = (uint)bVar1;
  uVar2 = param_2 + bfwrite;
  if (uVar2 < 0x21) {
    local_10 = uVar2 >> 3;
    uVar2 = uVar2 & 7;
    if (uVar2 == 0) {
      local_10 = local_10 - 1;
    }
    SZ_GetSpace(DAT_00114d30,local_c + local_10);
    *DAT_00114d2c = *DAT_00114d2c & (&ROWBITTABLE)[bfwrite];
    *DAT_00114d2c = param_1 << ((byte)bfwrite & 0x1f) | *DAT_00114d2c;
    bfwrite = uVar2;
    if (uVar2 == 0) {
      bfwrite = 8;
    }
    DAT_00114d2c = (uint *)((int)DAT_00114d2c + local_10);
  }
  else {
    SZ_GetSpace(DAT_00114d30,local_c + 4);
    *DAT_00114d2c = *DAT_00114d2c & (&ROWBITTABLE)[bfwrite];
    *DAT_00114d2c = param_1 << ((byte)bfwrite & 0x1f) | *DAT_00114d2c;
    bVar3 = 0x20 - (byte)bfwrite;
    bfwrite = uVar2 & 7;
    DAT_00114d2c = DAT_00114d2c + 1;
    *DAT_00114d2c = 0;
    *DAT_00114d2c = *DAT_00114d2c | param_1 >> (bVar3 & 0x1f);
  }
  return;
}


// MSG_WriteBuf  @ 0005753c
void MSG_WriteBuf(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    SZ_Write(param_1,param_3,param_2,0x57548);
  }
  return;
}


// MSG_WriteByte  @ 00057348
void MSG_WriteByte(undefined4 param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,1);
  *puVar1 = param_2;
  return;
}


// MSG_WriteChar  @ 00057310
void MSG_WriteChar(undefined4 param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,1);
  *puVar1 = param_2;
  return;
}


// MSG_WriteCoord  @ 00058660
void MSG_WriteCoord(undefined4 param_1,float param_2)

{
  MSG_WriteShort(param_1,(int)ROUND(param_2 * 8.0));
  return;
}


// MSG_WriteFloat  @ 00057480
void MSG_WriteFloat(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_8;
  
  local_8 = param_2;
  local_8 = (*LittleLong)(param_2);
  SZ_Write(param_1,&local_8,4);
  return;
}


// MSG_WriteHiresAngle  @ 000575dc
void MSG_WriteHiresAngle(undefined4 param_1,float param_2)

{
  MSG_WriteShort(param_1,(int)ROUND((param_2 * 65536.0) / 360.0) & 0xffff);
  return;
}


// MSG_WriteLong  @ 00057414
void MSG_WriteLong(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,4);
  *puVar1 = (undefined1)param_2;
  puVar1[1] = (char)((uint)param_2 >> 8);
  puVar1[2] = (char)((uint)param_2 >> 0x10);
  puVar1[3] = (char)((uint)param_2 >> 0x18);
  return;
}


// MSG_WriteOneBit  @ 000576fc
void MSG_WriteOneBit(int param_1)

{
  if (7 < bfwrite) {
    SZ_GetSpace(DAT_00114d30,1);
    bfwrite = 0;
    DAT_00114d2c = DAT_00114d2c + 1;
  }
  if ((*(ushort *)(DAT_00114d30 + 4) & 2) == 0) {
    if (param_1 == 0) {
      *DAT_00114d2c = *DAT_00114d2c & (&INVBITTABLE)[bfwrite * 4];
      bfwrite = bfwrite + 1;
    }
    else {
      *DAT_00114d2c = *DAT_00114d2c | (&BITTABLE)[bfwrite * 4];
      bfwrite = bfwrite + 1;
    }
  }
  return;
}


// MSG_WriteSBits  @ 00057ac8
void MSG_WriteSBits(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1;
  if (((param_2 < 0x20) &&
      (iVar1 = (1 << ((char)param_2 - 1U & 0x1f)) + -1, iVar2 = iVar1, param_1 <= iVar1)) &&
     (iVar2 = param_1, param_1 < -iVar1)) {
    iVar2 = -iVar1;
  }
  param_1 = iVar2;
  if (param_1 < 0) {
    MSG_WriteOneBit(1);
  }
  else {
    MSG_WriteOneBit(0);
  }
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  MSG_WriteBits(param_1,param_2 + -1);
  return;
}


// MSG_WriteShort  @ 00057380
void MSG_WriteShort(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,2);
  *puVar1 = (undefined1)param_2;
  puVar1[1] = (char)((uint)param_2 >> 8);
  return;
}


// MSG_WriteString  @ 000574d4
void MSG_WriteString(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    SZ_Write(param_1,&DAT_000dfd91,1);
  }
  else {
    iVar1 = Q_strlen(param_2);
    SZ_Write(param_1,param_2,iVar1 + 1);
  }
  return;
}


// MSG_WriteUsercmd  @ 00057640
void MSG_WriteUsercmd(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)DELTA_LookupRegistration(FUN_000dfda4);
  MSG_StartBitWriting(param_1);
  DELTA_WriteDelta(param_3,param_2,1,*puVar1,0);
  MSG_EndBitWriting(param_1);
  return;
}


// MSG_WriteVec3Coord  @ 00058718
void MSG_WriteVec3Coord(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = MSG_IsBitWriting();
  if (iVar1 == 0) {
    MSG_StartBitWriting(param_1);
    MSG_WriteBitVec3Coord(param_2);
    MSG_EndBitWriting(param_1);
  }
  else {
    MSG_WriteBitVec3Coord(param_2);
  }
  return;
}


// MSG_WriteWord  @ 000573c8
void MSG_WriteWord(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,2);
  *puVar1 = (undefined1)param_2;
  puVar1[1] = (char)((uint)param_2 >> 8);
  return;
}


