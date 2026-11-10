// MSG_BeginReading  @ 0004ad40
void MSG_BeginReading(void)

{
  msg_readcount = 0;
  msg_badread = 0;
  return;
}


// MSG_CurrentBit  @ 0004a4a0
int MSG_CurrentBit(void)

{
  int iVar1;
  
  if (DAT_000c67d8 == 0) {
    iVar1 = msg_readcount << 3;
  }
  else {
    iVar1 = DAT_000c67e0 * 8 + DAT_000c67e4;
  }
  return iVar1;
}


// MSG_EndBitReading  @ 0004a584
void MSG_EndBitReading(int param_1)

{
  if (*(int *)(param_1 + 0xc) < bfread) {
    msg_badread = 1;
  }
  msg_readcount = bfread;
  DAT_000c67dc = 0;
  DAT_000c67e4 = 0;
  DAT_000c67e0 = 0;
  DAT_000c67e8 = 0;
  DAT_000c67d8 = 0;
  return;
}


// MSG_EndBitWriting  @ 0004a0a8
void MSG_EndBitWriting(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte local_5;
  
  if ((*DAT_000c67d0 & 2) != 0) {
    return;
  }
  uVar4 = 8 - bfwrite;
  local_5 = 0xff;
  iVar3 = 0;
  if (0 < (int)uVar4) {
    uVar1 = uVar4 & 3;
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          local_5 = 0xfe;
        }
        local_5 = local_5 & ~(byte)(1 << (2 < uVar1));
        iVar3 = (2 < uVar1) + 1;
      }
      local_5 = local_5 & ~(byte)(1 << (sbyte)iVar3);
      iVar3 = iVar3 + 1;
      if ((int)uVar4 <= iVar3) goto LAB_0004a14e;
    }
    do {
      bVar2 = (byte)iVar3;
      local_5 = local_5 & ~(byte)(1 << (bVar2 & 0x1f)) & ~(byte)(1 << (bVar2 + 1 & 0x1f)) &
                ~(byte)(1 << (bVar2 + 2 & 0x1f)) & ~(byte)(1 << (bVar2 + 3 & 0x1f));
      iVar3 = iVar3 + 4;
    } while (iVar3 < (int)uVar4);
  }
LAB_0004a14e:
  *DAT_000c67cc = *DAT_000c67cc & local_5;
  SZ_GetSpace(DAT_000c67d0,1);
  DAT_000c67d0 = (byte *)0x0;
  DAT_000c67cc = (byte *)0x0;
  bfwrite = 0;
  return;
}


// MSG_IsBitReading  @ 0004a4e4
bool MSG_IsBitReading(void)

{
  return DAT_000c67d8 != 0;
}


// MSG_IsBitWriting  @ 0004a080
bool MSG_IsBitWriting(void)

{
  return DAT_000c67d0 != 0;
}


// MSG_PeekBits  @ 0004a6d0
uint MSG_PeekBits(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint local_20;
  undefined4 local_1c [6];
  
  local_20 = 0;
  puVar2 = &bfread;
  puVar3 = local_1c;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
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


// MSG_ReadAngle  @ 0004b0d8
longdouble MSG_ReadAngle(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadChar();
  return (longdouble)((float)iVar1 * 1.40625);
}


// MSG_ReadBitAngle  @ 0004a450
longdouble MSG_ReadBitAngle(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = MSG_ReadBits(param_1);
  return (longdouble)((float)uVar1 * (360.0 / (float)(1 << ((byte)param_1 & 0x1f))));
}


// MSG_ReadBitCoord  @ 0004a8d0
longdouble MSG_ReadBitCoord(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  float local_10;
  
  puVar6 = &stack0xffffffe4;
  local_10 = 0.0;
  iVar1 = MSG_IsBitReading();
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("MSG_IsBitReading()","/home/jihad/valve/goldsrc/engine/common.c",0x4c2,
                  "MSG_ReadBitCoord");
  }
  iVar1 = MSG_ReadOneBit();
  iVar2 = MSG_ReadOneBit();
  if ((iVar1 != 0) || (iVar2 != 0)) {
    iVar3 = MSG_ReadOneBit();
    uVar4 = 0;
    if (iVar1 != 0) {
      uVar4 = MSG_ReadBits();
    }
    uVar5 = 0;
    if (iVar2 != 0) {
      puVar6 = &stack0xffffffe0;
      uVar5 = MSG_ReadBits();
    }
    *(undefined4 *)(puVar6 + -4) = uVar5;
    iVar1 = *(int *)(puVar6 + -4);
    *(undefined4 *)(puVar6 + -4) = uVar4;
    local_10 = (float)iVar1 * 0.125 + (float)*(int *)(puVar6 + -4);
    if (iVar3 != 0) {
      local_10 = -local_10;
    }
  }
  return (longdouble)local_10;
}


// MSG_ReadBitData  @ 0004a7f4
uint MSG_ReadBitData(undefined1 *param_1,uint param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = MSG_IsBitReading();
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("MSG_IsBitReading()","/home/jihad/valve/goldsrc/engine/common.c",0x4b0,
                  "MSG_ReadBitData");
  }
  iVar2 = 0;
  if (0 < (int)param_2) {
    uVar3 = param_2 & 3;
    if (uVar3 != 0) {
      if (1 < uVar3) {
        if (2 < uVar3) {
          uVar1 = MSG_ReadBits(8);
          *param_1 = uVar1;
          param_1 = param_1 + 1;
        }
        uVar1 = MSG_ReadBits(8);
        *param_1 = uVar1;
        param_1 = param_1 + 1;
        iVar2 = (2 < uVar3) + 1;
      }
      uVar1 = MSG_ReadBits(8);
      *param_1 = uVar1;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
      if ((int)param_2 <= iVar2) {
        return param_2;
      }
    }
    do {
      uVar1 = MSG_ReadBits(8);
      *param_1 = uVar1;
      uVar1 = MSG_ReadBits(8);
      param_1[1] = uVar1;
      uVar1 = MSG_ReadBits(8);
      param_1[2] = uVar1;
      uVar1 = MSG_ReadBits(8);
      param_1[3] = uVar1;
      param_1 = param_1 + 4;
      iVar2 = iVar2 + 4;
    } while (iVar2 < (int)param_2);
  }
  return param_2;
}


// MSG_ReadBitString  @ 0004a784
undefined1 * MSG_ReadBitString(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = MSG_IsBitReading();
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("MSG_IsBitReading()","/home/jihad/valve/goldsrc/engine/common.c",0x49c,
                  "MSG_ReadBitString");
  }
  buf_146 = 0;
  pcVar3 = &buf_146;
  while( true ) {
    cVar1 = MSG_ReadBits(8);
    if (cVar1 == '\0') break;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  }
  *pcVar3 = '\0';
  return &buf_146;
}


// MSG_ReadBitVec3Coord  @ 0004aa54
void MSG_ReadBitVec3Coord(float *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  
  iVar1 = MSG_IsBitReading();
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("MSG_IsBitReading()","/home/jihad/valve/goldsrc/engine/common.c",0x4ee,
                  "MSG_ReadBitVec3Coord");
  }
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


// MSG_ReadBits  @ 0004a68c
uint MSG_ReadBits(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  while (iVar2 = param_1 + -1, 0 < param_1) {
    iVar1 = MSG_ReadOneBit();
    param_1 = iVar2;
    if (iVar1 != 0) {
      uVar3 = uVar3 | 1 << ((byte)iVar2 & 0x1f);
    }
  }
  return uVar3;
}


// MSG_ReadBuf  @ 0004afd8
undefined4 MSG_ReadBuf(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (DAT_00226fec < param_1 + msg_readcount) {
    msg_badread = 1;
    uVar1 = 0xffffffff;
  }
  else {
    Q_memcpy(param_2,msg_readcount + DAT_00226fe4,param_1);
    msg_readcount = msg_readcount + param_1;
    uVar1 = 1;
  }
  return uVar1;
}


// MSG_ReadByte  @ 0004adc0
uint MSG_ReadByte(void)

{
  uint uVar1;
  
  if (DAT_00226fec < msg_readcount + 1) {
    msg_badread = 1;
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)*(byte *)(msg_readcount + DAT_00226fe4);
    msg_readcount = msg_readcount + 1;
  }
  return uVar1;
}


// MSG_ReadChar  @ 0004ad70
int MSG_ReadChar(void)

{
  int iVar1;
  
  if (DAT_00226fec < msg_readcount + 1) {
    msg_badread = 1;
    iVar1 = -1;
  }
  else {
    iVar1 = (int)*(char *)(msg_readcount + DAT_00226fe4);
    msg_readcount = msg_readcount + 1;
  }
  return iVar1;
}


// MSG_ReadCoord  @ 0004ac38
longdouble MSG_ReadCoord(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadShort();
  return (longdouble)((float)iVar1 * 0.125);
}


// MSG_ReadFloat  @ 0004af58
longdouble MSG_ReadFloat(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  float fVar5;
  
  puVar1 = (undefined1 *)(msg_readcount + DAT_00226fe4);
  puVar2 = (undefined1 *)(DAT_00226fe4 + 1 + msg_readcount);
  puVar3 = (undefined1 *)(DAT_00226fe4 + 2 + msg_readcount);
  puVar4 = (undefined1 *)(DAT_00226fe4 + 3 + msg_readcount);
  msg_readcount = msg_readcount + 4;
  fVar5 = (float)(*LittleLong)(CONCAT13(*puVar4,CONCAT12(*puVar3,CONCAT11(*puVar2,*puVar1))));
  return (longdouble)fVar5;
}


// MSG_ReadHiresAngle  @ 0004b10c
longdouble MSG_ReadHiresAngle(void)

{
  int iVar1;
  
  iVar1 = MSG_ReadShort();
  return (longdouble)((float)iVar1 * 0.005493164);
}


// MSG_ReadLong  @ 0004aed4
int MSG_ReadLong(void)

{
  int iVar1;
  
  if (DAT_00226fec < msg_readcount + 4) {
    msg_badread = 1;
    iVar1 = -1;
  }
  else {
    iVar1 = (uint)*(byte *)(DAT_00226fe4 + 3 + msg_readcount) * 0x1000000 +
            (uint)*(byte *)(msg_readcount + DAT_00226fe4) +
            (uint)*(byte *)(DAT_00226fe4 + 1 + msg_readcount) * 0x100 +
            (uint)*(byte *)(DAT_00226fe4 + 2 + msg_readcount) * 0x10000;
    msg_readcount = msg_readcount + 4;
  }
  return iVar1;
}


// MSG_ReadOneBit  @ 0004a5f8
bool MSG_ReadOneBit(void)

{
  byte *pbVar1;
  
  if (msg_badread == 0) {
    if (7 < DAT_000c67e4) {
      bfread = bfread + 1;
      DAT_000c67e4 = 0;
      DAT_000c67e0 = DAT_000c67e0 + 1;
      DAT_000c67e8 = DAT_000c67e8 + 1;
    }
    if (bfread <= *(int *)(DAT_000c67d8 + 0xc)) {
      pbVar1 = &masks + DAT_000c67e4;
      DAT_000c67e4 = DAT_000c67e4 + 1;
      return (*DAT_000c67e8 & *pbVar1) != 0;
    }
    msg_badread = 1;
  }
  return true;
}


// MSG_ReadSBits  @ 0004a750
int MSG_ReadSBits(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = MSG_ReadOneBit();
  iVar2 = MSG_ReadBits(param_1 + -1);
  if (iVar1 != 0) {
    iVar2 = -iVar2;
  }
  return iVar2;
}


// MSG_ReadShort  @ 0004ae14
int MSG_ReadShort(void)

{
  int iVar1;
  
  if (DAT_00226fec < msg_readcount + 2) {
    msg_badread = 1;
    iVar1 = -1;
  }
  else {
    iVar1 = (int)(short)((ushort)*(byte *)(msg_readcount + DAT_00226fe4) +
                        (ushort)*(byte *)(DAT_00226fe4 + 1 + msg_readcount) * 0x100);
    msg_readcount = msg_readcount + 2;
  }
  return iVar1;
}


// MSG_ReadString  @ 0004b03c
void MSG_ReadString(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = MSG_ReadChar();
    if (iVar1 + 1U < 2) break;
    (&string_183)[uVar2] = (char)iVar1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x1fff);
  (&string_183)[uVar2] = 0;
  return;
}


// MSG_ReadStringLine  @ 0004b088
void MSG_ReadStringLine(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = MSG_ReadChar();
    if ((iVar1 + 1U < 2) || (iVar1 == 10)) break;
    (&string_186)[uVar2] = (char)iVar1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x7ff);
  (&string_186)[uVar2] = 0;
  return;
}


// MSG_ReadUsercmd  @ 0004b140
void MSG_ReadUsercmd(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = SV_LookupDelta("usercmd_t");
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("pdesc","/home/jihad/valve/goldsrc/engine/common.c",0x611,"MSG_ReadUsercmd");
  }
  MSG_StartBitReading(&net_message);
  DELTA_ParseDelta(param_2,param_1,iVar1);
  MSG_EndBitReading(&net_message);
  COM_NormalizeAngles(param_1 + 4);
  return;
}


// MSG_ReadVec3Coord  @ 0004acb0
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


// MSG_ReadWord  @ 0004ae74
uint MSG_ReadWord(void)

{
  uint uVar1;
  
  if (DAT_00226fec < msg_readcount + 2) {
    msg_badread = 1;
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)CONCAT11(*(undefined1 *)(DAT_00226fe4 + 1 + msg_readcount),
                           *(undefined1 *)(msg_readcount + DAT_00226fe4));
    msg_readcount = msg_readcount + 2;
  }
  return uVar1;
}


// MSG_StartBitReading  @ 0004a50c
void MSG_StartBitReading(int param_1)

{
  DAT_000c67e4 = 0;
  DAT_000c67e0 = 0;
  DAT_000c67d8 = param_1;
  if (*(int *)(param_1 + 0xc) < msg_readcount + 1) {
    msg_badread = 1;
  }
  bfread = msg_readcount + 1;
  DAT_000c67dc = msg_readcount;
  DAT_000c67e8 = msg_readcount + *(int *)(param_1 + 4);
  return;
}


// MSG_StartBitWriting  @ 0004a048
void MSG_StartBitWriting(int param_1)

{
  bfwrite = 0;
  DAT_000c67cc = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 4);
  DAT_000c67d0 = param_1;
  return;
}


// MSG_WriteAngle  @ 00049e80
void MSG_WriteAngle(undefined4 param_1,float param_2)

{
  MSG_WriteByte(param_1,(int)ROUND(param_2 * 0.7111111) & 0xff);
  return;
}


// MSG_WriteBitAngle  @ 0004a3c0
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


// MSG_WriteBitCoord  @ 0004a984
/* WARNING: Removing unreachable block (ram,0x0004aa42) */

void MSG_WriteBitCoord(float param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)ROUND(param_1);
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  iVar1 = MSG_IsBitWriting();
  if (iVar1 != 0) {
    MSG_WriteOneBit(iVar2);
    MSG_WriteOneBit(0);
    if ((iVar2 != 0) && (MSG_WriteOneBit(param_1 <= -0.125), iVar2 != 0)) {
      MSG_WriteBits(iVar2,0xc);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("MSG_IsBitWriting()","/home/jihad/valve/goldsrc/engine/common.c",0x4dc,
                "MSG_WriteBitCoord");
}


// MSG_WriteBitData  @ 0004a2d4
void MSG_WriteBitData(undefined1 *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = MSG_IsBitWriting();
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("MSG_IsBitWriting()","/home/jihad/valve/goldsrc/engine/common.c",0x3c8,
                  "MSG_WriteBitData");
  }
  iVar1 = 0;
  if (0 < (int)param_2) {
    uVar2 = param_2 & 3;
    if (uVar2 != 0) {
      if (1 < uVar2) {
        if (2 < uVar2) {
          MSG_WriteBits(*param_1,8);
          param_1 = param_1 + 1;
        }
        MSG_WriteBits(*param_1,8);
        param_1 = param_1 + 1;
        iVar1 = (2 < uVar2) + 1;
      }
      MSG_WriteBits(*param_1,8);
      param_1 = param_1 + 1;
      iVar1 = iVar1 + 1;
      if ((int)param_2 <= iVar1) {
        return;
      }
    }
    do {
      MSG_WriteBits(*param_1,8);
      MSG_WriteBits(param_1[1],8);
      MSG_WriteBits(param_1[2],8);
      MSG_WriteBits(param_1[3],8);
      param_1 = param_1 + 4;
      iVar1 = iVar1 + 4;
    } while (iVar1 < (int)param_2);
  }
  return;
}


// MSG_WriteBitString  @ 0004a268
void MSG_WriteBitString(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = MSG_IsBitWriting();
  if (iVar2 != 0) {
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      MSG_WriteBits((int)*param_1,8);
      param_1 = param_1 + 1;
      cVar1 = *param_1;
    }
    MSG_WriteBits(0,8);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("MSG_IsBitWriting()","/home/jihad/valve/goldsrc/engine/common.c",0x3b8,
                "MSG_WriteBitString");
}


// MSG_WriteBitVec3Coord  @ 0004aae4
void MSG_WriteBitVec3Coord(float *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  iVar2 = MSG_IsBitWriting();
  if (iVar2 != 0) {
    local_8 = 0;
    fVar1 = *param_1;
    if (((byte)((0.125 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.125) << 0xe) >> 8)) - 1) < 0x40) ||
       ((byte)(-0.125 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == -0.125) << 0xe) >> 8)) != 1)) {
      local_8 = 1;
    }
    iVar2 = 0;
    fVar1 = param_1[1];
    if (((byte)((0.125 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.125) << 0xe) >> 8)) - 1) < 0x40) ||
       ((byte)(-0.125 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == -0.125) << 0xe) >> 8)) != 1)) {
      iVar2 = 1;
    }
    iVar3 = 0;
    fVar1 = param_1[2];
    if (((byte)((0.125 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.125) << 0xe) >> 8)) - 1) < 0x40) ||
       ((byte)(-0.125 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == -0.125) << 0xe) >> 8)) != 1)) {
      iVar3 = 1;
    }
    MSG_WriteOneBit(local_8);
    MSG_WriteOneBit(iVar2);
    MSG_WriteOneBit(iVar3);
    if (local_8 != 0) {
      MSG_WriteBitCoord(*param_1);
    }
    if (iVar2 != 0) {
      MSG_WriteBitCoord(param_1[1]);
    }
    if (iVar3 != 0) {
      MSG_WriteBitCoord(param_1[2]);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("MSG_IsBitWriting()","/home/jihad/valve/goldsrc/engine/common.c",0x500,
                "MSG_WriteBitVec3Coord");
}


// MSG_WriteBits  @ 0004a198
void MSG_WriteBits(uint param_1,int param_2)

{
  if (((param_2 < 0x20) && (param_1 >> ((byte)param_2 & 0x1f) != 0)) && (param_1 != 0xffffffff)) {
    param_1 = (1 << ((byte)param_2 & 0x1f)) - 1;
  }
  while (0 < param_2) {
    param_2 = param_2 + -1;
    MSG_WriteOneBit(1 << ((byte)param_2 & 0x1f) & param_1);
  }
  return;
}


// MSG_WriteBuf  @ 00049e54
void MSG_WriteBuf(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    SZ_Write(param_1,param_3,param_2);
  }
  return;
}


// MSG_WriteByte  @ 00049cf8
void MSG_WriteByte(undefined4 param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,1);
  *puVar1 = param_2;
  return;
}


// MSG_WriteChar  @ 00049cd0
void MSG_WriteChar(undefined4 param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,1);
  *puVar1 = param_2;
  return;
}


// MSG_WriteCoord  @ 0004ac6c
void MSG_WriteCoord(undefined4 param_1,float param_2)

{
  MSG_WriteShort(param_1,(int)ROUND(param_2 * 8.0));
  return;
}


// MSG_WriteFloat  @ 00049dcc
void MSG_WriteFloat(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_8;
  
  local_8 = param_2;
  local_8 = (*LittleLong)(param_2);
  SZ_Write(param_1,&local_8,4);
  return;
}


// MSG_WriteHiresAngle  @ 00049ecc
void MSG_WriteHiresAngle(undefined4 param_1,float param_2)

{
  MSG_WriteShort(param_1,(int)ROUND(param_2 * 182.04445) & 0xffff);
  return;
}


// MSG_WriteLong  @ 00049d88
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


// MSG_WriteOneBit  @ 00049fcc
void MSG_WriteOneBit(int param_1)

{
  if (7 < bfwrite) {
    SZ_GetSpace(DAT_000c67d0,1);
    bfwrite = 0;
    DAT_000c67cc = DAT_000c67cc + 1;
  }
  if ((*DAT_000c67d0 & 2) == 0) {
    if (param_1 == 0) {
      *DAT_000c67cc = *DAT_000c67cc & (&inv_masks)[bfwrite];
    }
    else {
      *DAT_000c67cc = *DAT_000c67cc | (&masks)[bfwrite];
    }
    bfwrite = bfwrite + 1;
  }
  return;
}


// MSG_WriteSBits  @ 0004a200
void MSG_WriteSBits(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0x20) &&
     ((iVar1 = (1 << ((char)param_2 - 1U & 0x1f)) + -1, iVar1 < param_1 ||
      (iVar1 = -iVar1, param_1 < iVar1)))) {
    param_1 = iVar1;
  }
  MSG_WriteOneBit(param_1 < 0);
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  MSG_WriteBits(param_1,param_2 + -1);
  return;
}


// MSG_WriteShort  @ 00049d20
void MSG_WriteShort(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,2);
  *puVar1 = (char)param_2;
  puVar1[1] = (char)((uint)param_2 >> 8);
  return;
}


// MSG_WriteString  @ 00049e10
void MSG_WriteString(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined **ppuVar2;
  int iStack_1c;
  undefined *puStack_18;
  int iStack_14;
  
  if (param_2 == 0) {
    iStack_14 = 1;
    puStack_18 = &DAT_000a4500;
    ppuVar2 = &puStack_18;
  }
  else {
    iStack_14 = param_2;
    puStack_18 = (undefined *)0x49e3e;
    iVar1 = Q_strlen();
    puStack_18 = (undefined *)(iVar1 + 1);
    ppuVar2 = (undefined **)&iStack_1c;
    iStack_1c = param_2;
  }
  *(undefined4 *)((int)ppuVar2 + -4) = param_1;
  *(undefined4 *)((int)ppuVar2 + -8) = 0x49e47;
  SZ_Write();
  return;
}


// MSG_WriteUsercmd  @ 00049f18
void MSG_WriteUsercmd(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  piVar1 = (int *)DELTA_LookupRegistration("usercmd_t");
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    MSG_StartBitWriting(param_1);
    DELTA_WriteDelta(param_3,param_2,1,*piVar1,0);
    MSG_EndBitWriting(param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("ppdesc && *ppdesc","/home/jihad/valve/goldsrc/engine/common.c",0x2f7,
                "MSG_WriteUsercmd");
}


// MSG_WriteVec3Coord  @ 0004acf8
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


// MSG_WriteWord  @ 00049d54
void MSG_WriteWord(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)SZ_GetSpace(param_1,2);
  *puVar1 = (char)param_2;
  puVar1[1] = (char)((uint)param_2 >> 8);
  return;
}


