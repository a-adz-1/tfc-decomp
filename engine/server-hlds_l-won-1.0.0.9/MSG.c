// MSG_BeginReading  @ 0804f4f0
void MSG_BeginReading(void)

{
  msg_readcount = 0;
  msg_badread = 0;
  return;
}


// MSG_EndBitReading  @ 0804f1c0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MSG_EndBitReading(int param_1)

{
  if (*(int *)(param_1 + 0x10) < bfread) {
    msg_badread = 1;
  }
  msg_readcount = bfread;
  _DAT_080b4fbc = 0;
  DAT_080b4fc4 = 0;
  _DAT_080b4fc0 = 0;
  DAT_080b4fc8 = 0;
  DAT_080b4fb8 = 0;
  return;
}


// MSG_EndBitWriting  @ 0804ee00
void MSG_EndBitWriting(void)

{
  int iVar1;
  byte bVar2;
  
  if (*(int *)(DAT_080b4fb0 + 4) == 0) {
    bVar2 = 0xff;
    iVar1 = 0;
    if (0 < 8 - bfwrite) {
      do {
        bVar2 = bVar2 & ~(byte)(1 << ((byte)iVar1 & 0x1f));
        iVar1 = iVar1 + 1;
      } while (iVar1 < 8 - bfwrite);
    }
    *DAT_080b4fac = *DAT_080b4fac & bVar2;
    SZ_GetSpace(DAT_080b4fb0,1);
    bfwrite = 0;
    DAT_080b4fac = (byte *)0x0;
    DAT_080b4fb0 = 0;
  }
  return;
}


// MSG_PeekBitByte  @ 0804f300
byte MSG_PeekBitByte(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte local_1d;
  undefined4 local_1c [6];
  
  puVar2 = &bfread;
  puVar3 = local_1c;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_1d = 0;
  while (0 < param_1) {
    param_1 = param_1 + -1;
    iVar1 = MSG_ReadOneBit();
    if (iVar1 != 0) {
      local_1d = local_1d | (byte)(1 << ((byte)param_1 & 0x1f));
    }
  }
  puVar2 = local_1c;
  puVar3 = &bfread;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return local_1d;
}


// MSG_PeekBitLong  @ 0804f3f0
uint MSG_PeekBitLong(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint local_20;
  undefined4 local_1c [6];
  
  puVar2 = &bfread;
  puVar3 = local_1c;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_20 = 0;
  while (0 < param_1) {
    param_1 = param_1 + -1;
    iVar1 = MSG_ReadOneBit();
    if (iVar1 != 0) {
      local_20 = local_20 | 1 << ((byte)param_1 & 0x1f);
    }
  }
  puVar2 = local_1c;
  puVar3 = &bfread;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return local_20;
}


// MSG_ReadAngle  @ 0804f870
longdouble MSG_ReadAngle(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadChar();
  return (longdouble)((float)iVar1 * 1.40625);
}


// MSG_ReadBitAngle  @ 0804f0f0
longdouble MSG_ReadBitAngle(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  
  if (param_1 < 0x11) {
    if (param_1 < 9) {
      cVar1 = MSG_ReadBitByte(param_1);
      iVar3 = (int)cVar1;
    }
    else {
      sVar2 = MSG_ReadBitShort(param_1);
      iVar3 = (int)sVar2;
    }
  }
  else {
    iVar3 = MSG_ReadBitLong(param_1);
  }
  return (longdouble)((360.0 / (float)(1 << ((byte)param_1 & 0x1f))) * (float)iVar3);
}


// MSG_ReadBitByte  @ 0804f2b0
byte MSG_ReadBitByte(int param_1)

{
  int iVar1;
  byte local_5;
  
  local_5 = 0;
  while (0 < param_1) {
    param_1 = param_1 + -1;
    iVar1 = MSG_ReadOneBit();
    if (iVar1 != 0) {
      local_5 = local_5 | (byte)(1 << ((byte)param_1 & 0x1f));
    }
  }
  return local_5;
}


// MSG_ReadBitLong  @ 0804f3b0
uint MSG_ReadBitLong(int param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while (0 < param_1) {
    param_1 = param_1 + -1;
    iVar1 = MSG_ReadOneBit();
    if (iVar1 != 0) {
      uVar2 = uVar2 | 1 << ((byte)param_1 & 0x1f);
    }
  }
  return uVar2;
}


// MSG_ReadBitShort  @ 0804f370
undefined2 MSG_ReadBitShort(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  while (0 < param_1) {
    param_1 = param_1 + -1;
    iVar1 = MSG_ReadOneBit();
    if (iVar1 != 0) {
      uVar3 = uVar3 | 1 << ((byte)param_1 & 0x1f);
    }
    uVar2 = (undefined2)uVar3;
  }
  return uVar2;
}


// MSG_ReadBitUsercmd  @ 0804fa60
void MSG_ReadBitUsercmd(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  ushort uVar5;
  short sVar6;
  undefined2 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int local_10;
  
  puVar9 = param_1;
  for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar9 = *param_2;
    param_2 = param_2 + 1;
    puVar9 = puVar9 + 1;
  }
  bVar2 = MSG_ReadBitByte(8);
  if ((bVar2 & 1) != 0) {
    uVar5 = MSG_ReadBitShort(10);
    param_1[1] = (float)uVar5 * 0.3515625;
  }
  if ((bVar2 & 2) != 0) {
    uVar5 = MSG_ReadBitShort(10);
    param_1[2] = (float)uVar5 * 0.3515625;
  }
  if ((bVar2 & 4) != 0) {
    bVar3 = MSG_ReadBitByte(6);
    param_1[3] = (float)bVar3 * 5.625;
  }
  local_10 = 0;
  do {
    if (180.0 < (float)param_1[local_10 + 1]) {
      param_1[local_10 + 1] = (float)param_1[local_10 + 1] - 360.0;
    }
    fVar1 = (float)param_1[local_10 + 1];
    if ((byte)(fVar1 < -180.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == -180.0) << 0xe) >> 8)) == 1) {
      param_1[local_10 + 1] = fVar1 + 360.0;
    }
    local_10 = local_10 + 1;
  } while (local_10 < 3);
  if ((bVar2 & 8) != 0) {
    sVar6 = MSG_ReadSBitShort(8);
    param_1[4] = (float)(int)sVar6 * 4.0;
  }
  if ((bVar2 & 0x10) != 0) {
    sVar6 = MSG_ReadSBitShort(8);
    param_1[5] = (float)(int)sVar6 * 4.0;
  }
  if ((bVar2 & 0x20) != 0) {
    sVar6 = MSG_ReadSBitShort(8);
    param_1[6] = (float)(int)sVar6 * 4.0;
  }
  if ((bVar2 & 0x40) != 0) {
    uVar7 = MSG_ReadBitShort(0x10);
    *(undefined2 *)((int)param_1 + 0x1e) = uVar7;
  }
  if ((char)bVar2 < '\0') {
    uVar4 = MSG_ReadBitByte(8);
    *(undefined1 *)(param_1 + 8) = uVar4;
  }
  uVar4 = MSG_ReadBitByte(6);
  *(undefined1 *)(param_1 + 7) = uVar4;
  *(char *)(param_1 + 7) = *(char *)(param_1 + 7) << 2;
  uVar4 = MSG_ReadBitByte(8);
  *(undefined1 *)param_1 = uVar4;
  return;
}


// MSG_ReadBuf  @ 0804f750
undefined4 MSG_ReadBuf(size_t param_1,void *param_2)

{
  undefined4 uVar1;
  
  if ((int)net_message._16_4_ < (int)(msg_readcount + param_1)) {
    msg_badread = 1;
    uVar1 = 0xffffffff;
  }
  else {
    memcpy(param_2,(void *)(net_message._8_4_ + msg_readcount),param_1);
    msg_readcount = msg_readcount + param_1;
    uVar1 = 1;
  }
  return uVar1;
}


// MSG_ReadByte  @ 0804f560
uint MSG_ReadByte(void)

{
  uint uVar1;
  
  if ((int)net_message._16_4_ < msg_readcount + 1) {
    msg_badread = 1;
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)*(byte *)(msg_readcount + net_message._8_4_);
    msg_readcount = msg_readcount + 1;
  }
  return uVar1;
}


// MSG_ReadChar  @ 0804f510
int MSG_ReadChar(void)

{
  int iVar1;
  
  if ((int)net_message._16_4_ < msg_readcount + 1) {
    msg_badread = 1;
    iVar1 = -1;
  }
  else {
    iVar1 = (int)*(char *)(msg_readcount + net_message._8_4_);
    msg_readcount = msg_readcount + 1;
  }
  return iVar1;
}


// MSG_ReadCoord  @ 0804f840
longdouble MSG_ReadCoord(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadShort();
  return (longdouble)((float)iVar1 * 0.125);
}


// MSG_ReadFloat  @ 0804f6e0
longdouble MSG_ReadFloat(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  float fVar5;
  
  puVar1 = (undefined1 *)(msg_readcount + net_message._8_4_);
  puVar2 = (undefined1 *)(net_message._8_4_ + 1 + msg_readcount);
  puVar3 = (undefined1 *)(net_message._8_4_ + 2 + msg_readcount);
  puVar4 = (undefined1 *)(net_message._8_4_ + 3 + msg_readcount);
  msg_readcount = msg_readcount + 4;
  fVar5 = (float)(*LittleLong)(CONCAT13(*puVar4,CONCAT12(*puVar3,CONCAT11(*puVar2,*puVar1))));
  return (longdouble)fVar5;
}


// MSG_ReadHiresAngle  @ 0804f8a0
longdouble MSG_ReadHiresAngle(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadShort();
  return (longdouble)((float)iVar1 * 0.005493164);
}


// MSG_ReadLong  @ 0804f670
int MSG_ReadLong(void)

{
  int iVar1;
  
  if ((int)net_message._16_4_ < msg_readcount + 4) {
    msg_badread = 1;
    iVar1 = -1;
  }
  else {
    iVar1 = (uint)*(byte *)(msg_readcount + net_message._8_4_) +
            (uint)*(byte *)(net_message._8_4_ + 1 + msg_readcount) * 0x100 +
            (uint)*(byte *)(net_message._8_4_ + 2 + msg_readcount) * 0x10000 +
            (uint)*(byte *)(net_message._8_4_ + 3 + msg_readcount) * 0x1000000;
    msg_readcount = msg_readcount + 4;
  }
  return iVar1;
}


// MSG_ReadOneBit  @ 0804f220
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool MSG_ReadOneBit(void)

{
  char cVar1;
  
  if (msg_badread == 0) {
    if (7 < DAT_080b4fc4) {
      bfread = bfread + 1;
      DAT_080b4fc4 = 0;
      _DAT_080b4fc0 = _DAT_080b4fc0 + 1;
      DAT_080b4fc8 = DAT_080b4fc8 + 1;
    }
    if (bfread <= *(int *)(DAT_080b4fb8 + 0x10)) {
      cVar1 = (char)DAT_080b4fc4;
      DAT_080b4fc4 = DAT_080b4fc4 + 1;
      return ((byte)(1 << (7U - cVar1 & 0x1f)) & *DAT_080b4fc8) != 0;
    }
    msg_badread = 1;
  }
  return true;
}


// MSG_ReadSBitByte  @ 0804f460
int MSG_ReadSBitByte(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = MSG_ReadOneBit();
  cVar1 = MSG_ReadBitByte(param_1 + -1);
  if (iVar2 != 0) {
    cVar1 = -cVar1;
  }
  return (int)cVar1;
}


// MSG_ReadSBitLong  @ 0804f4c0
int MSG_ReadSBitLong(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = MSG_ReadOneBit();
  iVar2 = MSG_ReadBitLong(param_1 + -1);
  if (iVar1 != 0) {
    iVar2 = -iVar2;
  }
  return iVar2;
}


// MSG_ReadSBitShort  @ 0804f490
int MSG_ReadSBitShort(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = MSG_ReadOneBit();
  sVar1 = MSG_ReadBitShort(param_1 + -1);
  if (iVar2 != 0) {
    sVar1 = -sVar1;
  }
  return (int)sVar1;
}


// MSG_ReadShort  @ 0804f5b0
int MSG_ReadShort(void)

{
  int iVar1;
  
  if ((int)net_message._16_4_ < msg_readcount + 2) {
    msg_badread = 1;
    iVar1 = -1;
  }
  else {
    iVar1 = (int)(short)((ushort)*(byte *)(msg_readcount + net_message._8_4_) +
                        (ushort)*(byte *)(net_message._8_4_ + 1 + msg_readcount) * 0x100);
    msg_readcount = msg_readcount + 2;
  }
  return iVar1;
}


// MSG_ReadString  @ 0804f7b0
void MSG_ReadString(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = MSG_ReadChar();
    if (iVar1 + 1U < 2) break;
    (&string_250)[uVar2] = (char)iVar1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x7ff);
  (&string_250)[uVar2] = 0;
  return;
}


// MSG_ReadStringLine  @ 0804f7f0
void MSG_ReadStringLine(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = MSG_ReadChar();
    if ((iVar1 + 1U < 2) || (iVar1 == 10)) break;
    (&string_253)[uVar2] = (char)iVar1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x7ff);
  (&string_253)[uVar2] = 0;
  return;
}


// MSG_ReadUsercmd  @ 0804fc70
void MSG_ReadUsercmd(undefined4 param_1,undefined4 param_2)

{
  if (PROTOCOL_VERSION == 0x23) {
    MSG_ReadUsercmdGold(param_1,param_2);
  }
  else {
    MSG_ReadUsercmd36(param_1,param_2);
  }
  return;
}


// MSG_ReadUsercmd36  @ 0804f990
void MSG_ReadUsercmd36(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *puVar5;
  longdouble lVar6;
  
  puVar5 = param_1;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_2;
    param_2 = param_2 + 1;
    puVar5 = puVar5 + 1;
  }
  bVar1 = MSG_ReadByte();
  if ((bVar1 & 1) != 0) {
    lVar6 = (longdouble)MSG_ReadHiresAngle();
    param_1[1] = (float)lVar6;
  }
  if ((bVar1 & 2) != 0) {
    lVar6 = (longdouble)MSG_ReadHiresAngle();
    param_1[2] = (float)lVar6;
  }
  if ((bVar1 & 4) != 0) {
    lVar6 = (longdouble)MSG_ReadAngle();
    param_1[3] = (float)lVar6;
  }
  if ((bVar1 & 8) != 0) {
    iVar4 = MSG_ReadShort();
    param_1[4] = (float)iVar4;
  }
  if ((bVar1 & 0x10) != 0) {
    iVar4 = MSG_ReadShort();
    param_1[5] = (float)iVar4;
  }
  if ((bVar1 & 0x20) != 0) {
    iVar4 = MSG_ReadShort();
    param_1[6] = (float)iVar4;
  }
  if ((bVar1 & 0x40) != 0) {
    uVar3 = MSG_ReadShort();
    *(undefined2 *)((int)param_1 + 0x1e) = uVar3;
  }
  if ((char)bVar1 < '\0') {
    uVar2 = MSG_ReadByte();
    *(undefined1 *)(param_1 + 8) = uVar2;
  }
  uVar2 = MSG_ReadByte();
  *(undefined1 *)(param_1 + 7) = uVar2;
  uVar2 = MSG_ReadByte();
  *(undefined1 *)param_1 = uVar2;
  return;
}


// MSG_ReadUsercmdGold  @ 0804f8d0
void MSG_ReadUsercmdGold(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *puVar5;
  longdouble lVar6;
  
  puVar5 = param_1;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_2;
    param_2 = param_2 + 1;
    puVar5 = puVar5 + 1;
  }
  bVar1 = MSG_ReadByte();
  if ((bVar1 & 1) != 0) {
    lVar6 = (longdouble)MSG_ReadHiresAngle();
    param_1[1] = (float)lVar6;
  }
  if ((bVar1 & 2) != 0) {
    lVar6 = (longdouble)MSG_ReadHiresAngle();
    param_1[2] = (float)lVar6;
  }
  if ((bVar1 & 4) != 0) {
    lVar6 = (longdouble)MSG_ReadAngle();
    param_1[3] = (float)lVar6;
  }
  if ((bVar1 & 8) != 0) {
    lVar6 = (longdouble)MSG_ReadFloat();
    param_1[4] = (float)lVar6;
  }
  if ((bVar1 & 0x10) != 0) {
    lVar6 = (longdouble)MSG_ReadFloat();
    param_1[5] = (float)lVar6;
  }
  if ((bVar1 & 0x20) != 0) {
    lVar6 = (longdouble)MSG_ReadFloat();
    param_1[6] = (float)lVar6;
  }
  if ((bVar1 & 0x40) != 0) {
    uVar3 = MSG_ReadShort();
    *(undefined2 *)((int)param_1 + 0x1e) = uVar3;
  }
  if ((char)bVar1 < '\0') {
    uVar2 = MSG_ReadByte();
    *(undefined1 *)(param_1 + 8) = uVar2;
  }
  uVar2 = MSG_ReadByte();
  *(undefined1 *)(param_1 + 7) = uVar2;
  uVar2 = MSG_ReadByte();
  *(undefined1 *)param_1 = uVar2;
  return;
}


// MSG_ReadWord  @ 0804f610
uint MSG_ReadWord(void)

{
  uint uVar1;
  
  if ((int)net_message._16_4_ < msg_readcount + 2) {
    msg_badread = 1;
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)CONCAT11(*(undefined1 *)(net_message._8_4_ + 1 + msg_readcount),
                           *(undefined1 *)(msg_readcount + net_message._8_4_));
    msg_readcount = msg_readcount + 2;
  }
  return uVar1;
}


// MSG_StartBitReading  @ 0804f160
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MSG_StartBitReading(int param_1)

{
  _DAT_080b4fbc = msg_readcount;
  DAT_080b4fc4 = 0;
  _DAT_080b4fc0 = 0;
  DAT_080b4fc8 = msg_readcount + *(int *)(param_1 + 8);
  DAT_080b4fb8 = param_1;
  bfread = msg_readcount + 1;
  if (*(int *)(param_1 + 0x10) < bfread) {
    msg_badread = 1;
  }
  return;
}


// MSG_StartBitWriting  @ 0804edd0
void MSG_StartBitWriting(int param_1)

{
  bfwrite = 0;
  DAT_080b4fac = *(int *)(param_1 + 0x10) + *(int *)(param_1 + 8);
  DAT_080b4fb0 = param_1;
  return;
}


// MSG_WriteAngle  @ 0804e610
void MSG_WriteAngle(undefined4 param_1,float param_2)

{
  MSG_WriteByte(param_1,(int)ROUND((param_2 * 256.0) / 360.0) & 0xff);
  return;
}


// MSG_WriteBitAngle  @ 0804f030
void MSG_WriteBitAngle(float param_1,int param_2)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined1 local_17;
  undefined2 local_16;
  uint local_14;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  uVar1 = 1 << ((byte)param_2 & 0x1f);
  _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
  local_10 = (int)ROUND((float)uVar1 * param_1);
  local_14 = local_10 / 0x168 & uVar1 - 1;
  if (param_2 < 0x11) {
    if (param_2 < 9) {
      local_17 = (undefined1)local_14;
      MSG_WriteBitByte(&local_17,param_2);
    }
    else {
      local_16 = (undefined2)local_14;
      MSG_WriteBitShort(&local_16,param_2);
    }
  }
  else {
    MSG_WriteBitLong(&local_14,param_2);
  }
  return;
}


// MSG_WriteBitByte  @ 0804ee80
void MSG_WriteBitByte(byte *param_1,int param_2)

{
  while (0 < param_2) {
    param_2 = param_2 + -1;
    MSG_WriteOneBit((uint)*param_1 & 1 << ((byte)param_2 & 0x1f));
  }
  return;
}


// MSG_WriteBitLong  @ 0804ef00
void MSG_WriteBitLong(uint *param_1,int param_2)

{
  while (0 < param_2) {
    param_2 = param_2 + -1;
    MSG_WriteOneBit(1 << ((byte)param_2 & 0x1f) & *param_1);
  }
  return;
}


// MSG_WriteBitShort  @ 0804eec0
void MSG_WriteBitShort(ushort *param_1,int param_2)

{
  while (0 < param_2) {
    param_2 = param_2 + -1;
    MSG_WriteOneBit((uint)*param_1 & 1 << ((byte)param_2 & 0x1f));
  }
  return;
}


// MSG_WriteBitUsercmd  @ 0804ea50
void MSG_WriteBitUsercmd(byte *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  byte local_1c;
  undefined2 local_18;
  byte local_15;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  local_14 = (uint)(uint3)local_14;
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_1 + iVar3 * 4 + 4);
    fVar2 = *(float *)(iVar3 * 4 + param_2 + 4);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      local_14 = CONCAT13(local_14._3_1_ | (byte)(1 << ((byte)iVar3 & 0x1f)),(uint3)local_14);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  fVar1 = *(float *)(param_1 + 0x10);
  fVar2 = *(float *)(param_2 + 0x10);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    local_14 = local_14 | 0x8000000;
  }
  fVar1 = *(float *)(param_1 + 0x14);
  fVar2 = *(float *)(param_2 + 0x14);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    local_14 = local_14 | 0x10000000;
  }
  fVar1 = *(float *)(param_1 + 0x18);
  fVar2 = *(float *)(param_2 + 0x18);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    local_14 = local_14 | 0x20000000;
  }
  if (*(short *)(param_1 + 0x1e) != *(short *)(param_2 + 0x1e)) {
    local_14 = local_14 | 0x40000000;
  }
  if (param_1[0x20] != *(byte *)(param_2 + 0x20)) {
    local_14 = local_14 | 0x80000000;
  }
  MSG_WriteBitByte((int)&local_14 + 3,8);
  if ((local_14 & 0x1000000) != 0) {
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    local_14 = CONCAT22(local_14._2_2_,(short)(int)ROUND((*(float *)(param_1 + 4) * 1024.0) / 360.0)
                       );
    local_14 = local_14 & 0xffff03ff;
    MSG_WriteBitShort(&local_14,10);
  }
  if ((local_14 & 0x2000000) != 0) {
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    local_14 = CONCAT22(local_14._2_2_,(short)(int)ROUND((*(float *)(param_1 + 8) * 1024.0) / 360.0)
                       ) & 0xffff03ff;
    MSG_WriteBitShort(&local_14,10);
  }
  if ((local_14 & 0x4000000) != 0) {
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    local_1c = (byte)(int)ROUND((*(float *)(param_1 + 0xc) * 64.0) / 360.0);
    local_15 = local_1c & 0x3f;
    MSG_WriteBitByte(&local_15,6);
  }
  if ((local_14 & 0x8000000) != 0) {
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    local_18 = (undefined2)(int)ROUND(*(float *)(param_1 + 0x10) * 0.25);
    MSG_WriteSBitShort(&local_18,8);
  }
  if ((local_14 & 0x10000000) != 0) {
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    local_18 = (undefined2)(int)ROUND(*(float *)(param_1 + 0x14) * 0.25);
    MSG_WriteSBitShort(&local_18,8);
  }
  if ((local_14 & 0x20000000) != 0) {
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
    local_18 = (undefined2)(int)ROUND(*(float *)(param_1 + 0x18) * 0.25);
    MSG_WriteSBitShort(&local_18,8);
  }
  if ((local_14 & 0x40000000) != 0) {
    local_14 = CONCAT22(local_14._2_2_,*(undefined2 *)(param_1 + 0x1e));
    MSG_WriteBitShort(&local_14,0x10);
  }
  if ((int)local_14 < 0) {
    MSG_WriteBitByte(param_1 + 0x20,8);
  }
  local_15 = param_1[0x1c] >> 2;
  MSG_WriteBitByte(&local_15,6);
  local_15 = *param_1;
  MSG_WriteBitByte(&local_15,8);
  return;
}


// MSG_WriteBuf  @ 0804e5b0
void MSG_WriteBuf(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    SZ_Write(param_1,param_3,param_2);
  }
  return;
}


// MSG_WriteByte  @ 0804e470
void MSG_WriteByte(undefined4 param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,1);
  *puVar1 = param_2;
  return;
}


// MSG_WriteChar  @ 0804e450
void MSG_WriteChar(undefined4 param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,1);
  *puVar1 = param_2;
  return;
}


// MSG_WriteCoord  @ 0804e5d0
void MSG_WriteCoord(undefined4 param_1,float param_2)

{
  MSG_WriteShort(param_1,(int)ROUND(param_2 * 8.0));
  return;
}


// MSG_WriteFloat  @ 0804e530
void MSG_WriteFloat(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_8;
  
  local_8 = param_2;
  local_8 = (*LittleLong)(param_2);
  SZ_Write(param_1,&local_8,4);
  return;
}


// MSG_WriteHiresAngle  @ 0804e660
void MSG_WriteHiresAngle(undefined4 param_1,float param_2)

{
  MSG_WriteShort(param_1,(int)ROUND((param_2 * 65536.0) / 360.0) & 0xffff);
  return;
}


// MSG_WriteLong  @ 0804e4f0
void MSG_WriteLong(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,4);
  *puVar1 = (char)param_2;
  puVar1[1] = (char)((uint)param_2 >> 8);
  puVar1[2] = (char)((uint)param_2 >> 0x10);
  puVar1[3] = (char)((uint)param_2 >> 0x18);
  return;
}


// MSG_WriteOneBit  @ 0804ed50
void MSG_WriteOneBit(int param_1)

{
  byte bVar1;
  
  if (*(int *)(DAT_080b4fb0 + 4) == 0) {
    if (7 < bfwrite) {
      SZ_GetSpace(DAT_080b4fb0,1);
      bfwrite = 0;
      DAT_080b4fac = DAT_080b4fac + 1;
    }
    if (*(int *)(DAT_080b4fb0 + 4) == 0) {
      bVar1 = 7 - (char)bfwrite;
      if (param_1 == 0) {
        *DAT_080b4fac = *DAT_080b4fac & ~(byte)(1 << (bVar1 & 0x1f));
      }
      else {
        *DAT_080b4fac = *DAT_080b4fac | (byte)(1 << (bVar1 & 0x1f));
      }
      bfwrite = bfwrite + 1;
    }
  }
  return;
}


// MSG_WriteSBitByte  @ 0804ef40
void MSG_WriteSBitByte(char *param_1,int param_2)

{
  char local_5;
  
  MSG_WriteOneBit(*param_1 < '\0');
  local_5 = *param_1;
  if (local_5 < '\0') {
    local_5 = -local_5;
  }
  MSG_WriteBitByte(&local_5,param_2 + -1);
  return;
}


// MSG_WriteSBitLong  @ 0804efe0
void MSG_WriteSBitLong(int *param_1,int param_2)

{
  int local_8;
  
  MSG_WriteOneBit(*param_1 < 0);
  local_8 = *param_1;
  if (local_8 < 0) {
    local_8 = -local_8;
  }
  MSG_WriteBitLong(&local_8,param_2 + -1);
  return;
}


// MSG_WriteSBitShort  @ 0804ef90
void MSG_WriteSBitShort(short *param_1,int param_2)

{
  short local_6;
  
  MSG_WriteOneBit(*param_1 < 0);
  local_6 = *param_1;
  if (local_6 < 0) {
    local_6 = -local_6;
  }
  MSG_WriteBitShort(&local_6,param_2 + -1);
  return;
}


// MSG_WriteShort  @ 0804e490
void MSG_WriteShort(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,2);
  *puVar1 = (char)param_2;
  puVar1[1] = (char)((uint)param_2 >> 8);
  return;
}


// MSG_WriteString  @ 0804e570
void MSG_WriteString(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined **ppuVar2;
  int iStack_18;
  undefined *puStack_14;
  int iStack_10;
  
  if (param_2 == 0) {
    iStack_10 = 1;
    ppuVar2 = &puStack_14;
    puStack_14 = &DAT_0809ebf8;
  }
  else {
    iStack_10 = param_2;
    puStack_14 = (undefined *)0x804e596;
    iVar1 = Q_strlen();
    puStack_14 = (undefined *)(iVar1 + 1);
    ppuVar2 = (undefined **)&iStack_18;
    iStack_18 = param_2;
  }
  *(undefined4 *)((int)ppuVar2 + -4) = param_1;
  *(undefined4 *)((int)ppuVar2 + -8) = 0x804e59f;
  SZ_Write();
  return;
}


// MSG_WriteUsercmd  @ 0804ece0
void MSG_WriteUsercmd(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (PROTOCOL_VERSION == 0x23) {
    MSG_WriteUsercmdGold(param_1,param_2,param_3);
  }
  else {
    MSG_WriteUsercmd36(param_1,param_2,param_3);
  }
  return;
}


// MSG_WriteUsercmd36  @ 0804e860
void MSG_WriteUsercmd36(undefined4 param_1,undefined1 *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_2 + iVar3 * 4 + 4);
    fVar2 = *(float *)(iVar3 * 4 + param_3 + 4);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      uVar4 = uVar4 | 1 << ((byte)iVar3 & 0x1f);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  fVar1 = *(float *)(param_2 + 0x10);
  fVar2 = *(float *)(param_3 + 0x10);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    uVar4 = uVar4 | 8;
  }
  fVar1 = *(float *)(param_2 + 0x14);
  fVar2 = *(float *)(param_3 + 0x14);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    uVar4 = uVar4 | 0x10;
  }
  fVar1 = *(float *)(param_2 + 0x18);
  fVar2 = *(float *)(param_3 + 0x18);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    uVar4 = uVar4 | 0x20;
  }
  if (*(short *)(param_2 + 0x1e) != *(short *)(param_3 + 0x1e)) {
    uVar4 = uVar4 | 0x40;
  }
  if (param_2[0x20] != *(char *)(param_3 + 0x20)) {
    uVar4 = uVar4 | 0x80;
  }
  MSG_WriteByte(param_1,uVar4);
  if ((uVar4 & 1) != 0) {
    MSG_WriteHiresAngle(param_1,*(undefined4 *)(param_2 + 4));
  }
  if ((uVar4 & 2) != 0) {
    MSG_WriteHiresAngle(param_1,*(undefined4 *)(param_2 + 8));
  }
  if ((uVar4 & 4) != 0) {
    MSG_WriteAngle(param_1,*(undefined4 *)(param_2 + 0xc));
  }
  if ((uVar4 & 8) != 0) {
    MSG_WriteShort(param_1,(int)ROUND(*(float *)(param_2 + 0x10)));
  }
  if ((uVar4 & 0x10) != 0) {
    MSG_WriteShort(param_1,(int)ROUND(*(float *)(param_2 + 0x14)));
  }
  if ((uVar4 & 0x20) != 0) {
    MSG_WriteShort(param_1,(int)ROUND(*(float *)(param_2 + 0x18)));
  }
  if ((uVar4 & 0x40) != 0) {
    MSG_WriteShort(param_1,*(undefined2 *)(param_2 + 0x1e));
  }
  if ((char)uVar4 < '\0') {
    MSG_WriteByte(param_1,param_2[0x20]);
  }
  MSG_WriteByte(param_1,param_2[0x1c]);
  MSG_WriteByte(param_1,*param_2);
  return;
}


// MSG_WriteUsercmdGold  @ 0804e6b0
void MSG_WriteUsercmdGold(undefined4 param_1,undefined1 *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_2 + iVar3 * 4 + 4);
    fVar2 = *(float *)(iVar3 * 4 + param_3 + 4);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      uVar4 = uVar4 | 1 << ((byte)iVar3 & 0x1f);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  fVar1 = *(float *)(param_2 + 0x10);
  fVar2 = *(float *)(param_3 + 0x10);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    uVar4 = uVar4 | 8;
  }
  fVar1 = *(float *)(param_2 + 0x14);
  fVar2 = *(float *)(param_3 + 0x14);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    uVar4 = uVar4 | 0x10;
  }
  fVar1 = *(float *)(param_2 + 0x18);
  fVar2 = *(float *)(param_3 + 0x18);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    uVar4 = uVar4 | 0x20;
  }
  if (*(short *)(param_2 + 0x1e) != *(short *)(param_3 + 0x1e)) {
    uVar4 = uVar4 | 0x40;
  }
  if (param_2[0x20] != *(char *)(param_3 + 0x20)) {
    uVar4 = uVar4 | 0x80;
  }
  MSG_WriteByte(param_1,uVar4);
  if ((uVar4 & 1) != 0) {
    MSG_WriteHiresAngle(param_1,*(undefined4 *)(param_2 + 4));
  }
  if ((uVar4 & 2) != 0) {
    MSG_WriteHiresAngle(param_1,*(undefined4 *)(param_2 + 8));
  }
  if ((uVar4 & 4) != 0) {
    MSG_WriteAngle(param_1,*(undefined4 *)(param_2 + 0xc));
  }
  if ((uVar4 & 8) != 0) {
    MSG_WriteFloat(param_1,*(undefined4 *)(param_2 + 0x10));
  }
  if ((uVar4 & 0x10) != 0) {
    MSG_WriteFloat(param_1,*(undefined4 *)(param_2 + 0x14));
  }
  if ((uVar4 & 0x20) != 0) {
    MSG_WriteFloat(param_1,*(undefined4 *)(param_2 + 0x18));
  }
  if ((uVar4 & 0x40) != 0) {
    MSG_WriteShort(param_1,*(undefined2 *)(param_2 + 0x1e));
  }
  if ((char)uVar4 < '\0') {
    MSG_WriteByte(param_1,param_2[0x20]);
  }
  MSG_WriteByte(param_1,param_2[0x1c]);
  MSG_WriteByte(param_1,*param_2);
  return;
}


// MSG_WriteWord  @ 0804e4c0
void MSG_WriteWord(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,2);
  *puVar1 = (char)param_2;
  puVar1[1] = (char)((uint)param_2 >> 8);
  return;
}


