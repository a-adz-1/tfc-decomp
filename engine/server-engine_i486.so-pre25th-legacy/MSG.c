// MSG_BeginReading  @ 00060930
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MSG_BeginReading(void)

{
  msg_readcount = 0;
  msg_badread = false;
  return;
}


// MSG_CurrentBit  @ 0005ff00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int MSG_CurrentBit(void)

{
                    /* Unresolved local var: int nbits@[???] */
  if (bfread.pbuf != (sizebuf_t *)0x0) {
    return bfread.nCurInputBit + bfread.nBytesRead * 8;
  }
  return msg_readcount << 3;
}


// MSG_EndBitReading  @ 0005ff90
void MSG_EndBitReading(sizebuf_t *buf)

{
  if (buf->cursize < bfread.msg_readcount) {
    msg_badread = true;
  }
  msg_readcount = bfread.msg_readcount;
  bfread.nBitFieldReadStartByte = 0;
  bfread.nCurInputBit = 0;
  bfread.nBytesRead = 0;
  bfread.pInByte = (uchar *)0x0;
  bfread.pbuf = (sizebuf_t *)0x0;
  return;
}


// MSG_EndBitWriting  @ 000617e0
void MSG_EndBitWriting(sizebuf_t *buf)

{
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
  if (((bfwrite.pbuf)->flags & 2) == 0) {
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
    *bfwrite.pOutByte =
         *bfwrite.pOutByte & (byte)(0xff >> (8U - (char)bfwrite.nCurOutputBit & 0x1f));
    SZ_GetSpace(bfwrite.pbuf,1);
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = (uchar *)0x0;
    bfwrite.pbuf = (sizebuf_t *)0x0;
  }
  return;
}


// MSG_IsBitReading  @ 0005ff30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean MSG_IsBitReading(void)

{
  return (uint)(bfread.pbuf != (sizebuf_t *)0x0);
}


// MSG_IsBitWriting  @ 0005fe90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean MSG_IsBitWriting(void)

{
  return (uint)(bfwrite.pbuf != (sizebuf_t *)0x0);
}


// MSG_PeekBits  @ 00060080
uint32 MSG_PeekBits(int numbits)

{
  int iVar1;
  sizebuf_t *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  uint32 uVar7;
  
  puVar6 = bfread.pInByte;
  iVar5 = bfread.nCurInputBit;
  iVar4 = bfread.nBytesRead;
  iVar3 = bfread.nBitFieldReadStartByte;
  psVar2 = bfread.pbuf;
                    /* Unresolved local var: uint32 r@[DW_OP_reg0(EAX)]
                       Unresolved local var: bf_read_t savebf@[???] */
  iVar1 = bfread.msg_readcount;
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  uVar7 = 1;
  if (msg_badread == false) {
    uVar7 = MSG_ReadBits(numbits);
  }
  bfread.pbuf = psVar2;
  bfread.nBitFieldReadStartByte = iVar3;
  bfread.nBytesRead = iVar4;
  bfread.nCurInputBit = iVar5;
  bfread.msg_readcount = iVar1;
  bfread.pInByte = puVar6;
  return uVar7;
}


// MSG_ReadAngle  @ 00060d60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float MSG_ReadAngle(void)

{
  byte *pbVar1;
  
                    /* Unresolved local var: int angle@[???] */
                    /* Unresolved local var: int c@[???] */
  if (msg_readcount < net_message.cursize) {
    pbVar1 = net_message.data + msg_readcount;
    msg_readcount = msg_readcount + 1;
    if (msg_badread == false) {
      return (float)(int)(char)*pbVar1 * 1.40625;
    }
  }
  else {
    msg_badread = true;
  }
  return 0.0;
}


// MSG_ReadBitAngle  @ 0005fea0
float MSG_ReadBitAngle(int numbits)

{
  float fVar1;
  uint32 uVar2;
  
                    /* Unresolved local var: float fReturn@[???]
                       Unresolved local var: uint32 ui@[DW_OP_reg21(XMM0)]
                       Unresolved local var: float shift@[???] */
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  if (msg_badread == false) {
    uVar2 = MSG_ReadBits(numbits);
    fVar1 = (float)uVar2;
  }
  else {
    fVar1 = 1.0;
  }
  return (360.0 / (float)(1 << ((byte)numbits & 0x1f))) * fVar1;
}


// MSG_ReadBitCoord  @ 00060260
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float MSG_ReadBitCoord(void)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  qboolean qVar4;
  uint32 uVar5;
  uint32 uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
                    /* Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???]
                       Unresolved local var: int signbit@[???]
                       Unresolved local var: float value@[???] */
                    /* Unresolved local var: int nValue@[???] */
  if (msg_badread == false) {
    if (7 < bfread.nCurInputBit) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.nCurInputBit = 0;
    }
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      msg_badread = true;
      goto LAB_00060330;
    }
                    /* Unresolved local var: int nValue@[???] */
    bVar7 = ((uint)*bfread.pInByte & BITTABLE[bfread.nCurInputBit]) != 0;
    bfread.nCurInputBit = bfread.nCurInputBit + 1;
                    /* Unresolved local var: int nValue@[???] */
    if (bfread.nCurInputBit == 8) {
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.nCurInputBit = 0;
      bfread.nBytesRead = bfread.nBytesRead + 1;
    }
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      msg_badread = true;
      goto LAB_000603cf;
    }
    puVar1 = BITTABLE + bfread.nCurInputBit;
                    /* Unresolved local var: int nValue@[???] */
    bfread.nCurInputBit = bfread.nCurInputBit + 1;
    bVar8 = ((uint)*bfread.pInByte & *puVar1) != 0;
    if (!bVar8 && !bVar7) {
      return 0.0;
    }
LAB_00060348:
    if (7 < bfread.nCurInputBit) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.nCurInputBit = 0;
    }
    if (bfread.msg_readcount <= (bfread.pbuf)->cursize) {
      puVar1 = BITTABLE + bfread.nCurInputBit;
                    /* Unresolved local var: int nValue@[???] */
      bfread.nCurInputBit = bfread.nCurInputBit + 1;
      bVar9 = ((uint)*bfread.pInByte & *puVar1) != 0;
      qVar4 = false;
      goto joined_r0x000603db;
    }
    msg_badread = true;
  }
  else {
LAB_00060330:
                    /* Unresolved local var: int nValue@[???] */
    bVar7 = true;
    if (msg_badread == false) {
      bVar8 = true;
      goto LAB_00060348;
    }
LAB_000603cf:
    bVar8 = true;
  }
  bVar9 = true;
  qVar4 = msg_badread;
joined_r0x000603db:
  uVar6 = 0;
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  if ((bVar7) && (uVar6 = 1, qVar4 == false)) {
    uVar6 = MSG_ReadBits(0xc);
  }
  if (bVar8) {
                    /* Unresolved local var: uint32 r@[DW_OP_reg0(EAX)]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
    if (msg_badread == false) {
      uVar5 = MSG_ReadBits(3);
      fVar2 = (float)(int)uVar5 * 0.125;
    }
    else {
      fVar2 = 0.125;
    }
  }
  else {
    fVar2 = 0.0;
  }
  fVar3 = -((float)(int)uVar6 + fVar2);
  if (!bVar9) {
    fVar3 = (float)(int)uVar6 + fVar2;
  }
  return fVar3;
}


// MSG_ReadBitData  @ 00060210
int MSG_ReadBitData(void *dest,int length)

{
  uint32 uVar1;
  undefined1 uVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int readlen@[???]
                       Unresolved local var: uchar * p@[???] */
  if (0 < length) {
    iVar3 = 0;
    do {
                    /* Unresolved local var: uint32 r@[DW_OP_reg0(EAX)]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
      uVar2 = 1;
      if (msg_badread == false) {
        uVar1 = MSG_ReadBits(8);
        uVar2 = (undefined1)uVar1;
      }
      *(undefined1 *)((int)dest + iVar3) = uVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 != length);
  }
  return length;
}


// MSG_ReadBitString  @ 000601c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * MSG_ReadBitString(void)

{
  uint32 uVar1;
  char *pcVar2;
  
                    /* Unresolved local var: char c@[???]
                       Unresolved local var: char * p@[???] */
  pcVar2 = MSG_ReadBitString::buf;
  MSG_ReadBitString::buf[0] = '\0';
  while (msg_badread == false) {
    uVar1 = MSG_ReadBits(8);
    if ((char)uVar1 == '\0') break;
    *pcVar2 = (char)uVar1;
    pcVar2 = pcVar2 + 1;
  }
  *pcVar2 = '\0';
  return MSG_ReadBitString::buf;
}


// MSG_ReadBitVec3Coord  @ 00060490
/* WARNING: Variable defined which should be unmapped: yflag */
/* WARNING: Type propagation algorithm not settling */

void MSG_ReadBitVec3Coord(vec_t *fa)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  float fVar6;
  int yflag;
  
                    /* Unresolved local var: int xflag@[DW_OP_reg0(EAX)]
                       Unresolved local var: int zflag@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: int nValue@[???] */
  if (msg_badread == false) {
    if (7 < bfread.nCurInputBit) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.nCurInputBit = 0;
    }
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      msg_badread = true;
      goto LAB_000605b2;
    }
                    /* Unresolved local var: int nValue@[???] */
    iVar1 = bfread.nCurInputBit + 1;
    bVar3 = ((uint)*bfread.pInByte & BITTABLE[bfread.nCurInputBit]) != 0;
                    /* Unresolved local var: int nValue@[???] */
    if (iVar1 == 8) {
      bfread.pInByte = bfread.pInByte + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.nCurInputBit = 0;
      iVar1 = 0;
      bfread.nBytesRead = bfread.nBytesRead + 1;
      if (bfread.msg_readcount <= (bfread.pbuf)->cursize) goto LAB_00060523;
LAB_00060647:
      msg_badread = true;
      goto LAB_000605b7;
    }
    bfread.nCurInputBit = iVar1;
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) goto LAB_00060647;
LAB_00060523:
                    /* Unresolved local var: int nValue@[???] */
    iVar2 = iVar1 + 1;
    bVar4 = ((uint)*bfread.pInByte & BITTABLE[iVar1]) != 0;
                    /* Unresolved local var: int nValue@[???] */
    if (iVar2 == 8) {
      bfread.pInByte = bfread.pInByte + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.nCurInputBit = 0;
      iVar2 = 0;
      bfread.nBytesRead = bfread.nBytesRead + 1;
      if (bfread.msg_readcount <= (bfread.pbuf)->cursize) goto LAB_00060552;
    }
    else {
      bfread.nCurInputBit = iVar2;
      if (bfread.msg_readcount <= (bfread.pbuf)->cursize) {
LAB_00060552:
                    /* Unresolved local var: int nValue@[???] */
        bfread.nCurInputBit = iVar2 + 1;
        bVar5 = ((uint)*bfread.pInByte & BITTABLE[iVar2]) != 0;
        goto joined_r0x000605c3;
      }
    }
    msg_badread = true;
  }
  else {
LAB_000605b2:
    bVar3 = true;
LAB_000605b7:
    bVar4 = true;
  }
  bVar5 = true;
joined_r0x000605c3:
  if (bVar3) {
    fVar6 = MSG_ReadBitCoord();
    *fa = fVar6;
  }
  if (bVar4) {
    fVar6 = MSG_ReadBitCoord();
    fa[1] = fVar6;
  }
  if (bVar5) {
    fVar6 = MSG_ReadBitCoord();
    fa[2] = fVar6;
  }
  return;
}


// MSG_ReadBits  @ 0005eff0
uint32 __regparm3 MSG_ReadBits(int numbits)

{
  byte bVar1;
  uint32 uVar2;
  uint uVar3;
  
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  if (7 < bfread.nCurInputBit) {
    bfread.nCurInputBit = 0;
    bfread.msg_readcount = bfread.msg_readcount + 1;
    bfread.nBytesRead = bfread.nBytesRead + 1;
    bfread.pInByte = bfread.pInByte + 1;
  }
  uVar3 = numbits + bfread.nCurInputBit;
  bVar1 = (byte)bfread.nCurInputBit;
  if (uVar3 < 0x21) {
    uVar2 = *(uint *)bfread.pInByte >> (bVar1 & 0x1f) & ROWBITTABLE[numbits];
    bfread.nCurInputBit = uVar3 & 7;
    if (bfread.nCurInputBit == 0) {
      bfread.nCurInputBit = 8;
      uVar3 = (uVar3 >> 3) - 1;
    }
    else {
      uVar3 = uVar3 >> 3;
    }
    bfread.pInByte = (uchar *)((int)bfread.pInByte + uVar3);
    bfread.nBytesRead = bfread.nBytesRead + uVar3;
    bfread.msg_readcount = bfread.msg_readcount + uVar3;
  }
  else {
    bfread.nCurInputBit = uVar3 & 7;
    uVar2 = (ROWBITTABLE[bfread.nCurInputBit] & *(uint *)((int)bfread.pInByte + 4)) <<
            (0x20 - bVar1 & 0x1f) | *(uint *)bfread.pInByte >> (bVar1 & 0x1f);
    bfread.nBytesRead = bfread.nBytesRead + 4;
    bfread.msg_readcount = bfread.msg_readcount + 4;
    bfread.pInByte = (uchar *)((int)bfread.pInByte + 4);
  }
  if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
    msg_badread = true;
    uVar2 = 1;
  }
  return uVar2;
}


// MSG_ReadBits  @ 00060060
uint32 MSG_ReadBits(int numbits)

{
  uint32 uVar1;
  
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  if (msg_badread == false) {
    uVar1 = MSG_ReadBits(numbits);
    return uVar1;
  }
  return 1;
}


// MSG_ReadBuf  @ 00060b00
int MSG_ReadBuf(int iSize,void *pbuf)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  
  if (net_message.cursize < msg_readcount + iSize) {
    iVar5 = -1;
    msg_badread = true;
  }
  else {
    pbVar7 = net_message.data + msg_readcount;
    uVar4 = iSize;
    if (7 < (uint)iSize) {
      uVar6 = iSize;
      if (((uint)pbuf & 1) != 0) {
        bVar1 = *pbVar7;
        pbVar7 = pbVar7 + 1;
        *(byte *)pbuf = bVar1;
        pbuf = (void *)((int)pbuf + 1);
        uVar6 = iSize - 1;
      }
      if (((uint)pbuf & 2) != 0) {
        uVar2 = *(undefined2 *)pbVar7;
        uVar6 = uVar6 - 2;
        pbVar7 = pbVar7 + 2;
        *(undefined2 *)pbuf = uVar2;
        pbuf = (void *)((int)pbuf + 2);
      }
      if (((uint)pbuf & 4) != 0) {
        uVar3 = *(undefined4 *)pbVar7;
        uVar6 = uVar6 - 4;
        pbVar7 = pbVar7 + 4;
        *(undefined4 *)pbuf = uVar3;
        pbuf = (void *)((int)pbuf + 4);
      }
      uVar4 = uVar6 & 3;
      for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pbuf = *(undefined4 *)pbVar7;
        pbVar7 = pbVar7 + 4;
        pbuf = (undefined4 *)((int)pbuf + 4);
      }
    }
    iVar5 = 0;
    if ((uVar4 & 4) != 0) {
      *(undefined4 *)pbuf = *(undefined4 *)pbVar7;
      iVar5 = 4;
    }
    if ((uVar4 & 2) != 0) {
      *(undefined2 *)((int)pbuf + iVar5) = *(undefined2 *)(pbVar7 + iVar5);
      iVar5 = iVar5 + 2;
    }
    if ((uVar4 & 1) != 0) {
      *(byte *)((int)pbuf + iVar5) = pbVar7[iVar5];
    }
    msg_readcount = msg_readcount + iSize;
    iVar5 = 1;
  }
  return iVar5;
}


// MSG_ReadByte  @ 00060970
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int MSG_ReadByte(void)

{
  byte *pbVar1;
  
                    /* Unresolved local var: int c@[???] */
  if (msg_readcount < net_message.cursize) {
    pbVar1 = net_message.data + msg_readcount;
    msg_readcount = msg_readcount + 1;
    return (uint)*pbVar1;
  }
  msg_badread = true;
  return -1;
}


// MSG_ReadChar  @ 00060940
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int MSG_ReadChar(void)

{
  byte *pbVar1;
  
                    /* Unresolved local var: int c@[???] */
  if (msg_readcount < net_message.cursize) {
    pbVar1 = net_message.data + msg_readcount;
    msg_readcount = msg_readcount + 1;
    return (int)(char)*pbVar1;
  }
  msg_badread = true;
  return -1;
}


// MSG_ReadCoord  @ 00060660
float MSG_ReadCoord(sizebuf_t *sb)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: short coord@[???] */
                    /* Unresolved local var: int c@[???] */
  if (msg_readcount + 1 < net_message.cursize) {
    fVar2 = 0.0;
    iVar3 = msg_readcount + 1;
    pbVar1 = net_message.data + msg_readcount;
    msg_readcount = msg_readcount + 2;
    if (msg_badread == false) {
      fVar2 = (float)(short)((ushort)net_message.data[iVar3] * 0x100 + (ushort)*pbVar1) * 0.125;
    }
  }
  else {
    msg_badread = true;
    fVar2 = 0.0;
  }
  return fVar2;
}


// MSG_ReadFloat  @ 00060ab0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float MSG_ReadFloat(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  
  iVar2 = msg_readcount + 1;
                    /* Unresolved local var: anon_union_4_3_4e909c68 dat@[???] */
  pbVar1 = net_message.data + msg_readcount;
  iVar3 = msg_readcount + 2;
  iVar4 = msg_readcount + 3;
  msg_readcount = msg_readcount + 4;
  fVar5 = (float)(*LittleLong)(CONCAT13(net_message.data[iVar4],
                                        CONCAT12(net_message.data[iVar3],
                                                 CONCAT11(net_message.data[iVar2],*pbVar1))));
  return fVar5;
}


// MSG_ReadHiresAngle  @ 00060dd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float MSG_ReadHiresAngle(void)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: int angle@[???] */
                    /* Unresolved local var: int c@[???] */
  if (msg_readcount + 1 < net_message.cursize) {
    fVar2 = 0.0;
    pbVar1 = net_message.data + msg_readcount;
    iVar3 = msg_readcount + 1;
    msg_readcount = msg_readcount + 2;
    if (msg_badread == false) {
      fVar2 = (float)(short)((ushort)net_message.data[iVar3] * 0x100 + (ushort)*pbVar1) *
              0.005493164;
    }
  }
  else {
    msg_badread = true;
    fVar2 = 0.0;
  }
  return fVar2;
}


// MSG_ReadLong  @ 00060a50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int MSG_ReadLong(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int c@[???] */
  if (msg_readcount + 3 < net_message.cursize) {
    iVar2 = msg_readcount + 1;
    pbVar1 = net_message.data + msg_readcount;
    iVar3 = msg_readcount + 2;
    iVar4 = msg_readcount + 3;
    msg_readcount = msg_readcount + 4;
    return CONCAT13(net_message.data[iVar4],
                    CONCAT12(net_message.data[iVar3],CONCAT11(net_message.data[iVar2],*pbVar1)));
  }
  msg_badread = true;
  return -1;
}


// MSG_ReadOneBit  @ 0005ffe0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int MSG_ReadOneBit(void)

{
  uint *puVar1;
  uint uVar2;
  
                    /* Unresolved local var: int nValue@[???] */
  uVar2 = 1;
  if (msg_badread == false) {
    if (7 < bfread.nCurInputBit) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.nCurInputBit = 0;
    }
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      msg_badread = true;
      return 1;
    }
    puVar1 = BITTABLE + bfread.nCurInputBit;
                    /* Unresolved local var: int nValue@[???] */
    bfread.nCurInputBit = bfread.nCurInputBit + 1;
    uVar2 = (uint)(((uint)*bfread.pInByte & *puVar1) != 0);
  }
  return uVar2;
}


// MSG_ReadSBits  @ 00060120
int MSG_ReadSBits(int numbits)

{
  byte bVar1;
  uint uVar2;
  uint32 uVar3;
  int iVar4;
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int nSignBit@[???]
                       Unresolved local var: int nValue@[???] */
  if (msg_badread == false) {
    if (7 < bfread.nCurInputBit) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.nCurInputBit = 0;
    }
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      uVar3 = 1;
      msg_badread = true;
    }
    else {
                    /* Unresolved local var: int nValue@[???] */
      bVar1 = *bfread.pInByte;
      uVar2 = BITTABLE[bfread.nCurInputBit];
      bfread.nCurInputBit = bfread.nCurInputBit + 1;
      uVar3 = MSG_ReadBits(numbits + -1);
      if ((bVar1 & uVar2) == 0) {
        return uVar3;
      }
    }
    iVar4 = -uVar3;
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}


// MSG_ReadShort  @ 000609b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int MSG_ReadShort(void)

{
  byte *pbVar1;
  int iVar2;
  
                    /* Unresolved local var: int c@[???] */
  if (msg_readcount + 1 < net_message.cursize) {
    iVar2 = msg_readcount + 1;
    pbVar1 = net_message.data + msg_readcount;
    msg_readcount = msg_readcount + 2;
    return (int)CONCAT11(net_message.data[iVar2],*pbVar1);
  }
  msg_badread = true;
  return -1;
}


// MSG_ReadString  @ 00060c30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * MSG_ReadString(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = net_message.cursize;
  pbVar2 = net_message.data;
                    /* Unresolved local var: int l@[???]
                       Unresolved local var: int c@[???] */
  iVar1 = msg_readcount;
                    /* Unresolved local var: int c@[???] */
  iVar5 = msg_readcount;
  iVar4 = 0;
  while (iVar6 = iVar4, iVar5 < iVar3) {
    iVar5 = iVar5 + 1;
    msg_readcount = iVar5;
    if ((int)(char)pbVar2[iVar6 + iVar1] + 1U < 2) goto LAB_00060c5f;
    MSG_ReadString::string[iVar6] = pbVar2[iVar6 + iVar1];
    iVar4 = iVar6 + 1;
    if (iVar6 + 1 == 0x1fff) {
      MSG_ReadString::string[iVar6 + 1] = '\0';
      return MSG_ReadString::string;
    }
  }
  msg_badread = true;
LAB_00060c5f:
  MSG_ReadString::string[iVar6] = '\0';
  return MSG_ReadString::string;
}


// MSG_ReadStringLine  @ 00060cb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * MSG_ReadStringLine(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = net_message.cursize;
  pbVar3 = net_message.data;
                    /* Unresolved local var: int l@[???]
                       Unresolved local var: int c@[DW_OP_reg3(EBX)] */
  iVar2 = msg_readcount;
                    /* Unresolved local var: int c@[DW_OP_reg3(EBX)] */
  iVar6 = 0;
  iVar5 = msg_readcount;
  while (iVar5 < iVar4) {
    bVar1 = pbVar3[iVar6 + iVar2];
    iVar5 = iVar5 + 1;
    msg_readcount = iVar5;
    if (((int)(char)bVar1 + 1U < 2) || ((char)bVar1 == 10)) goto LAB_00060cdf;
    MSG_ReadStringLine::string[iVar6] = bVar1;
    iVar6 = iVar6 + 1;
    if (iVar6 == 0x7ff) goto LAB_00060cdf;
  }
  msg_badread = true;
LAB_00060cdf:
  MSG_ReadStringLine::string[iVar6] = '\0';
  return MSG_ReadStringLine::string;
}


// MSG_ReadUsercmd  @ 000647b0
void MSG_ReadUsercmd(usercmd_t *to,usercmd_t *from)

{
  delta_t *pFields;
  
                    /* Unresolved local var: delta_t * pdesc@[???] */
  pFields = SV_LookupDelta("usercmd_t");
  bfread.nCurInputBit = 0;
  bfread.nBytesRead = 0;
  bfread.nBitFieldReadStartByte = msg_readcount;
  bfread.pInByte = net_message.data + msg_readcount;
  bfread.msg_readcount = msg_readcount + 1;
  bfread.pbuf = &net_message;
  if (net_message.cursize < bfread.msg_readcount) {
    msg_badread = true;
  }
  DELTA_ParseDelta((uchar *)from,(uchar *)to,pFields,0x34);
  if (net_message.cursize < bfread.msg_readcount) {
    msg_badread = true;
  }
  msg_readcount = bfread.msg_readcount;
  bfread.nBitFieldReadStartByte = 0;
  bfread.nCurInputBit = 0;
  bfread.nBytesRead = 0;
  bfread.pInByte = (uchar *)0x0;
  bfread.pbuf = (sizebuf_t *)0x0;
  COM_NormalizeAngles(to->viewangles);
  return;
}


// MSG_ReadVec3Coord  @ 000606d0
/* WARNING: Variable defined which should be unmapped: yflag */

void MSG_ReadVec3Coord(sizebuf_t *sb,float *fa)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  float fVar6;
  int yflag;
  
  if (bfread.pbuf == (sizebuf_t *)0x0) {
    bfread.nCurInputBit = 0;
    bfread.nBytesRead = 0;
    bfread.pbuf = sb;
    bfread.nBitFieldReadStartByte = msg_readcount;
    bfread.pInByte = sb->data + msg_readcount;
    bfread.msg_readcount = msg_readcount + 1;
    if (sb->cursize < bfread.msg_readcount) {
      msg_badread = true;
    }
    MSG_ReadBitVec3Coord(fa);
    if (sb->cursize < bfread.msg_readcount) {
      msg_badread = true;
    }
    bfread.pbuf = (sizebuf_t *)0x0;
    bfread.nBitFieldReadStartByte = 0;
    bfread.nBytesRead = 0;
    bfread.nCurInputBit = 0;
    bfread.pInByte = (uchar *)0x0;
    msg_readcount = bfread.msg_readcount;
    return;
  }
                    /* Unresolved local var: int xflag@[DW_OP_reg0(EAX)]
                       Unresolved local var: int zflag@[DW_OP_reg3(EBX)]
                       Unresolved local var: int nValue@[???] */
  if (msg_badread == false) {
    if (7 < bfread.nCurInputBit) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.nCurInputBit = 0;
    }
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      msg_badread = true;
      goto LAB_000607e2;
    }
                    /* Unresolved local var: int nValue@[???] */
    iVar1 = bfread.nCurInputBit + 1;
    bVar3 = ((uint)*bfread.pInByte & BITTABLE[bfread.nCurInputBit]) != 0;
                    /* Unresolved local var: int nValue@[???] */
    if (iVar1 != 8) {
      bfread.nCurInputBit = iVar1;
      if (bfread.msg_readcount <= (bfread.pbuf)->cursize) goto LAB_0006076f;
LAB_00060887:
      msg_badread = true;
      goto LAB_000607e7;
    }
    bfread.pInByte = bfread.pInByte + 1;
    bfread.msg_readcount = bfread.msg_readcount + 1;
    bfread.nCurInputBit = 0;
    iVar1 = 0;
    bfread.nBytesRead = bfread.nBytesRead + 1;
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) goto LAB_00060887;
LAB_0006076f:
                    /* Unresolved local var: int nValue@[???] */
    iVar2 = iVar1 + 1;
    bVar4 = ((uint)*bfread.pInByte & BITTABLE[iVar1]) != 0;
                    /* Unresolved local var: int nValue@[???] */
    if (iVar2 == 8) {
      bfread.pInByte = bfread.pInByte + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.nCurInputBit = 0;
      iVar2 = 0;
      bfread.nBytesRead = bfread.nBytesRead + 1;
      if ((bfread.pbuf)->cursize < bfread.msg_readcount) goto LAB_00060847;
LAB_0006079e:
                    /* Unresolved local var: int nValue@[???] */
      bfread.nCurInputBit = iVar2 + 1;
      bVar5 = ((uint)*bfread.pInByte & BITTABLE[iVar2]) != 0;
      goto joined_r0x000607f3;
    }
    bfread.nCurInputBit = iVar2;
    if (bfread.msg_readcount <= (bfread.pbuf)->cursize) goto LAB_0006079e;
LAB_00060847:
    msg_badread = true;
  }
  else {
LAB_000607e2:
    bVar3 = true;
LAB_000607e7:
    bVar4 = true;
  }
  bVar5 = true;
joined_r0x000607f3:
  if (bVar3) {
    fVar6 = MSG_ReadBitCoord();
    *fa = fVar6;
  }
  if (bVar4) {
    fVar6 = MSG_ReadBitCoord();
    fa[1] = fVar6;
  }
  if (bVar5) {
    fVar6 = MSG_ReadBitCoord();
    fa[2] = fVar6;
  }
  return;
}


// MSG_ReadWord  @ 00060a00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int MSG_ReadWord(void)

{
  byte *pbVar1;
  int iVar2;
  
                    /* Unresolved local var: int c@[???] */
  if (msg_readcount + 1 < net_message.cursize) {
    iVar2 = msg_readcount + 1;
    pbVar1 = net_message.data + msg_readcount;
    msg_readcount = msg_readcount + 2;
    return (uint)CONCAT11(net_message.data[iVar2],*pbVar1);
  }
  msg_badread = true;
  return -1;
}


// MSG_SkipString  @ 00060d20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MSG_SkipString(void)

{
  byte *pbVar1;
  
  do {
    if (net_message.cursize <= msg_readcount) {
      msg_badread = true;
      return;
    }
    pbVar1 = net_message.data + msg_readcount;
    msg_readcount = msg_readcount + 1;
  } while (1 < (int)(char)*pbVar1 + 1U);
  return;
}


// MSG_StartBitReading  @ 0005ff40
void MSG_StartBitReading(sizebuf_t *buf)

{
  bfread.nCurInputBit = 0;
  bfread.nBytesRead = 0;
  bfread.nBitFieldReadStartByte = msg_readcount;
  bfread.pbuf = buf;
  bfread.pInByte = buf->data + msg_readcount;
  bfread.msg_readcount = msg_readcount + 1;
  if (buf->cursize < msg_readcount + 1) {
    msg_badread = true;
  }
  return;
}


// MSG_StartBitWriting  @ 0005fe70
void MSG_StartBitWriting(sizebuf_t *buf)

{
  bfwrite.nCurOutputBit = 0;
  bfwrite.pbuf = buf;
  bfwrite.pOutByte = buf->data + buf->cursize;
  return;
}


// MSG_WriteAngle  @ 00061470
void MSG_WriteAngle(sizebuf_t *sb,float f)

{
  undefined1 *puVar1;
  ushort in_FPUStatusWord;
  longdouble lVar2;
  double dVar3;
  
  lVar2 = (longdouble)f;
  do {
    lVar2 = lVar2 - (longdouble)(unkint10)(lVar2 / (longdouble)360.0) * (longdouble)360.0;
  } while ((in_FPUStatusWord & 0x400) != 0);
  if (NAN(lVar2)) {
    dVar3 = fmod((double)f,360.0);
    lVar2 = (longdouble)dVar3;
  }
                    /* Unresolved local var: uchar * buf@[???] */
  puVar1 = SZ_GetSpace(sb,1);
  *puVar1 = (char)(int)(((float)lVar2 * 256.0) / 360.0);
  return;
}


// MSG_WriteBitAngle  @ 00061190
void MSG_WriteBitAngle(float fAngle,int numbits)

{
  uint uVar1;
  ushort in_FPUStatusWord;
  longdouble lVar2;
  double dVar3;
  
                    /* Unresolved local var: int d@[???]
                       Unresolved local var: uint32 mask@[???]
                       Unresolved local var: uint32 shift@[???] */
  lVar2 = (longdouble)fAngle;
  if (numbits < 0x20) {
    uVar1 = 1 << ((byte)numbits & 0x1f);
    do {
      lVar2 = lVar2 - (longdouble)(unkint10)(lVar2 / (longdouble)360.0) * (longdouble)360.0;
    } while ((in_FPUStatusWord & 0x400) != 0);
    if (NAN(lVar2)) {
      dVar3 = fmod((double)fAngle,360.0);
      lVar2 = (longdouble)dVar3;
    }
    MSG_WriteBits((int)((float)lVar2 * (float)uVar1) / 0x168 & uVar1 - 1,numbits);
    return;
  }
  Sys_Error("Can\'t write bit angle with 32 bits precision\n");
  return;
}


// MSG_WriteBitCoord  @ 00061970
/* WARNING: Removing unreachable block (ram,0x00061ae0) */
/* WARNING: Removing unreachable block (ram,0x00061a98) */

void MSG_WriteBitCoord(float f)

{
  uint32 *puVar1;
  uint uVar2;
  uint32 data;
  
                    /* Unresolved local var: int signbit@[???]
                       Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???] */
  uVar2 = (int)f >> 0x1f;
  data = (uVar2 ^ (int)f) - uVar2;
  if (7 < bfwrite.nCurOutputBit) {
    SZ_GetSpace(bfwrite.pbuf,1);
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
  }
  if (((bfwrite.pbuf)->flags & 2) == 0) {
    if (data == 0) {
      *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)INVBITTABLE[bfwrite.nCurOutputBit];
    }
    else {
      *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)BITTABLE[bfwrite.nCurOutputBit];
    }
    bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
    if (bfwrite.nCurOutputBit == 8) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
      bfwrite.nCurOutputBit = 0;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
    }
  }
  if (data != 0) {
    if (bfwrite.nCurOutputBit == 8) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (f <= -0.125) {
        puVar1 = BITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar1;
      }
      else {
        puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
      }
    }
    if (data != 0) {
      MSG_WriteBits(data,0xc);
    }
  }
  return;
}


// MSG_WriteBitData  @ 00061250
void MSG_WriteBitData(void *src,int length)

{
  byte *pbVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar * p@[???] */
  if (0 < length) {
    iVar2 = 0;
    do {
      pbVar1 = (byte *)((int)src + iVar2);
      iVar2 = iVar2 + 1;
      MSG_WriteBits((uint)*pbVar1,8);
    } while (iVar2 != length);
  }
  return;
}


// MSG_WriteBitString  @ 000612a0
void MSG_WriteBitString(char *p)

{
  byte bVar1;
  
                    /* Unresolved local var: uchar * pch@[???] */
  bVar1 = *p;
  while (bVar1 != 0) {
    p = p + 1;
    MSG_WriteBits((uint)bVar1,8);
    bVar1 = *p;
  }
  MSG_WriteBits(0,8);
  return;
}


// MSG_WriteBitVec3Coord  @ 00061c90
/* WARNING: Removing unreachable block (ram,0x000622c0) */
/* WARNING: Removing unreachable block (ram,0x00062378) */
/* WARNING: Removing unreachable block (ram,0x000623b0) */
/* WARNING: Removing unreachable block (ram,0x0006221a) */
/* WARNING: Removing unreachable block (ram,0x000620d3) */
/* WARNING: Removing unreachable block (ram,0x00061f6b) */

void MSG_WriteBitVec3Coord(vec_t *fa)

{
  uint32 *puVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint32 uVar8;
  
                    /* Unresolved local var: int xflag@[???]
                       Unresolved local var: int yflag@[???]
                       Unresolved local var: int zflag@[???] */
  bVar3 = 0.125 <= *fa || *fa <= -0.125;
  bVar5 = 0.125 <= fa[1] || fa[1] <= -0.125;
  bVar4 = 0.125 <= fa[2] || fa[2] <= -0.125;
  if (7 < bfwrite.nCurOutputBit) {
    SZ_GetSpace(bfwrite.pbuf,1);
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
  }
  if (((bfwrite.pbuf)->flags & 2) == 0) {
    if (bVar3) {
      *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)BITTABLE[bfwrite.nCurOutputBit];
    }
    else {
      *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)INVBITTABLE[bfwrite.nCurOutputBit];
    }
    bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
    if (bfwrite.nCurOutputBit == 8) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
      bfwrite.nCurOutputBit = 0;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (bVar5) {
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)BITTABLE[bfwrite.nCurOutputBit];
      }
      else {
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)INVBITTABLE[bfwrite.nCurOutputBit];
      }
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      if (bfwrite.nCurOutputBit == 8) {
        SZ_GetSpace(bfwrite.pbuf,1);
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
        bfwrite.nCurOutputBit = 0;
      }
      if (((bfwrite.pbuf)->flags & 2) == 0) {
        if (bVar4) {
          puVar1 = BITTABLE + bfwrite.nCurOutputBit;
          bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
          *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar1;
        }
        else {
          puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
          bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
          *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
        }
      }
    }
  }
  if (bVar3) {
    fVar2 = *fa;
                    /* Unresolved local var: int signbit@[???]
                       Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???] */
    uVar7 = (uint)fVar2;
    uVar6 = (int)uVar7 >> 0x1f;
    uVar8 = (uVar6 ^ uVar7) - uVar6;
    if (bfwrite.nCurOutputBit == 8) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (uVar8 == 0) {
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)INVBITTABLE[bfwrite.nCurOutputBit];
      }
      else {
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)BITTABLE[bfwrite.nCurOutputBit];
      }
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      if (7 < bfwrite.nCurOutputBit) {
        SZ_GetSpace(bfwrite.pbuf,1);
        bfwrite.nCurOutputBit = 0;
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
      }
      if (((bfwrite.pbuf)->flags & 2) == 0) {
        puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
      }
    }
    if (uVar8 != 0) {
      if (7 < bfwrite.nCurOutputBit) {
        SZ_GetSpace(bfwrite.pbuf,1);
        bfwrite.nCurOutputBit = 0;
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
      }
      if (((bfwrite.pbuf)->flags & 2) == 0) {
        if (fVar2 <= -0.125) {
          puVar1 = BITTABLE + bfwrite.nCurOutputBit;
          bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
          *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar1;
        }
        else {
          puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
          bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
          *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
        }
      }
      if (uVar8 != 0) {
        MSG_WriteBits(uVar8,0xc);
      }
    }
  }
  if (bVar5) {
    fVar2 = fa[1];
                    /* Unresolved local var: int signbit@[???]
                       Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???] */
    uVar7 = (uint)fVar2;
    uVar6 = (int)uVar7 >> 0x1f;
    uVar8 = (uVar6 ^ uVar7) - uVar6;
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (uVar8 == 0) {
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)INVBITTABLE[bfwrite.nCurOutputBit];
      }
      else {
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)BITTABLE[bfwrite.nCurOutputBit];
      }
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      if (7 < bfwrite.nCurOutputBit) {
        SZ_GetSpace(bfwrite.pbuf,1);
        bfwrite.nCurOutputBit = 0;
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
      }
      if (((bfwrite.pbuf)->flags & 2) == 0) {
        puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
      }
    }
    if (uVar8 != 0) {
      if (bfwrite.nCurOutputBit == 8) {
        SZ_GetSpace(bfwrite.pbuf,1);
        bfwrite.nCurOutputBit = 0;
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
      }
      if (((bfwrite.pbuf)->flags & 2) == 0) {
        if (fVar2 <= -0.125) {
          puVar1 = BITTABLE + bfwrite.nCurOutputBit;
          bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
          *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar1;
        }
        else {
          puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
          bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
          *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
        }
      }
      if (uVar8 != 0) {
        MSG_WriteBits(uVar8,0xc);
      }
    }
  }
  if (bVar4) {
    fVar2 = fa[2];
                    /* Unresolved local var: int signbit@[???]
                       Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???] */
    uVar7 = (uint)fVar2;
    uVar6 = (int)uVar7 >> 0x1f;
    uVar8 = (uVar6 ^ uVar7) - uVar6;
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (uVar8 == 0) {
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)INVBITTABLE[bfwrite.nCurOutputBit];
      }
      else {
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)BITTABLE[bfwrite.nCurOutputBit];
      }
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      if (7 < bfwrite.nCurOutputBit) {
        SZ_GetSpace(bfwrite.pbuf,1);
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
        bfwrite.nCurOutputBit = 0;
      }
      if (((bfwrite.pbuf)->flags & 2) == 0) {
        puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
      }
    }
    if (uVar8 != 0) {
      if (7 < bfwrite.nCurOutputBit) {
        SZ_GetSpace(bfwrite.pbuf,1);
        bfwrite.nCurOutputBit = 0;
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
      }
      if (((bfwrite.pbuf)->flags & 2) == 0) {
        if (fVar2 <= -0.125) {
          puVar1 = BITTABLE + bfwrite.nCurOutputBit;
          bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
          *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar1;
        }
        else {
          puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
          bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
          *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
        }
      }
      if (uVar8 != 0) {
        MSG_WriteBits(uVar8,0xc);
      }
    }
  }
  return;
}


// MSG_WriteBits  @ 00061010
void MSG_WriteBits(uint32 data,int numbits)

{
  bool bVar1;
  uchar *puVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
                    /* Unresolved local var: uint32 d@[???]
                       Unresolved local var: uint32 reserveBytes@[???] */
  if ((numbits < 0x20) && ((uint)(1 << ((byte)numbits & 0x1f)) <= data)) {
    data = ROWBITTABLE[numbits];
  }
  bVar1 = bfwrite.nCurOutputBit < 8;
  if (bVar1) {
    numbits = bfwrite.nCurOutputBit + numbits;
    iVar4 = 4;
  }
  else {
    iVar4 = 5;
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
    bfwrite.nCurOutputBit = 0;
  }
  if ((uint)numbits < 0x21) {
                    /* Unresolved local var: int length@[???] */
    uVar5 = numbits & 7;
    iVar4 = ((uint)numbits >> 3) - (uint)(uVar5 == 0);
    SZ_GetSpace(bfwrite.pbuf,(uint)!bVar1 + iVar4);
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
      *(uint *)bfwrite.pOutByte =
           *(uint *)bfwrite.pOutByte | data << ((byte)bfwrite.nCurOutputBit & 0x1f);
      bfwrite.nCurOutputBit = 8;
      if (uVar5 != 0) {
        bfwrite.nCurOutputBit = uVar5;
      }
      bfwrite.pOutByte = bfwrite.pOutByte + iVar4;
    }
  }
  else {
    SZ_GetSpace(bfwrite.pbuf,iVar4);
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
      *(uint *)bfwrite.pOutByte =
           *(uint *)bfwrite.pOutByte | data << ((byte)bfwrite.nCurOutputBit & 0x1f);
      bVar3 = 0x20 - (byte)bfwrite.nCurOutputBit;
      puVar2 = bfwrite.pOutByte;
      bfwrite.nCurOutputBit = numbits & 7;
      bfwrite.pOutByte = bfwrite.pOutByte + 4;
      puVar2[4] = '\0';
      puVar2[5] = '\0';
      puVar2[6] = '\0';
      puVar2[7] = '\0';
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte | data >> (bVar3 & 0x1f);
      return;
    }
  }
  return;
}


// MSG_WriteBuf  @ 00061610
/* WARNING: Removing unreachable block (ram,0x000616d5) */

void MSG_WriteBuf(sizebuf_t *sb,int iSize,void *buf)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  
  bVar7 = 0;
  if (buf == (void *)0x0) {
    return;
  }
                    /* Unresolved local var: uchar * pData@[???] */
  puVar4 = SZ_GetSpace(sb,iSize);
  if ((sb->flags & 2) != 0) {
    return;
  }
  if ((uint)iSize < 8) {
    if ((iSize & 4U) != 0) {
      iVar5 = 4;
      *puVar4 = *(undefined4 *)buf;
      goto joined_r0x00061673;
    }
  }
  else {
    uVar6 = iSize;
    if (((uint)puVar4 & 1) != 0) {
      uVar1 = *(undefined1 *)buf;
      uVar6 = iSize - 1;
      buf = (void *)((int)buf + 1);
      *(undefined1 *)puVar4 = uVar1;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    if (((uint)puVar4 & 2) != 0) {
      uVar2 = *(undefined2 *)buf;
      uVar6 = uVar6 - 2;
      buf = (void *)((int)buf + 2);
      *(undefined2 *)puVar4 = uVar2;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    }
    if (((uint)puVar4 & 4) != 0) {
      uVar3 = *(undefined4 *)buf;
      uVar6 = uVar6 - 4;
      buf = (void *)((int)buf + 4);
      *puVar4 = uVar3;
      puVar4 = puVar4 + 1;
    }
    iSize = uVar6 & 3;
    for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar4 = *(undefined4 *)buf;
      buf = (undefined4 *)((int)buf + ((uint)bVar7 * -2 + 1) * 4);
      puVar4 = puVar4 + (uint)bVar7 * -2 + 1;
    }
  }
  iVar5 = 0;
joined_r0x00061673:
  if ((iSize & 2U) != 0) {
    *(undefined2 *)((int)puVar4 + iVar5) = *(undefined2 *)((int)buf + iVar5);
    iVar5 = iVar5 + 2;
  }
  if ((iSize & 1U) != 0) {
    *(undefined1 *)((int)puVar4 + iVar5) = *(undefined1 *)((int)buf + iVar5);
  }
  return;
}


// MSG_WriteByte  @ 00061410
void MSG_WriteByte(sizebuf_t *sb,int c)

{
  undefined1 *puVar1;
  
                    /* Unresolved local var: uchar * buf@[DW_OP_reg0(EAX)] */
  puVar1 = SZ_GetSpace(sb,1);
  *puVar1 = (char)c;
  return;
}


// MSG_WriteChar  @ 00061440
void MSG_WriteChar(sizebuf_t *sb,int c)

{
  undefined1 *puVar1;
  
                    /* Unresolved local var: uchar * buf@[DW_OP_reg0(EAX)] */
  puVar1 = SZ_GetSpace(sb,1);
  *puVar1 = (char)c;
  return;
}


// MSG_WriteCoord  @ 00061580
void MSG_WriteCoord(sizebuf_t *sb,float f)

{
  undefined1 *puVar1;
  
                    /* Unresolved local var: uchar * buf@[DW_OP_reg0(EAX)] */
  puVar1 = SZ_GetSpace(sb,2);
  *puVar1 = (char)(int)(f * 8.0);
  puVar1[1] = (char)((uint)(int)(f * 8.0) >> 8);
  return;
}


// MSG_WriteFloat  @ 000615c0
void MSG_WriteFloat(sizebuf_t *sb,float f)

{
  int32 iVar1;
  int32 *piVar2;
  
                    /* Unresolved local var: anon_union_4_2_947300a7 dat@[???] */
  iVar1 = (*LittleLong)((int32)f);
                    /* Unresolved local var: uchar * pData@[DW_OP_reg0(EAX)] */
  piVar2 = SZ_GetSpace(sb,4);
  if ((sb->flags & 2) == 0) {
    *piVar2 = iVar1;
  }
  return;
}


// MSG_WriteHiresAngle  @ 000614f0
void MSG_WriteHiresAngle(sizebuf_t *sb,float f)

{
  undefined1 *puVar1;
  uint uVar2;
  ushort in_FPUStatusWord;
  longdouble lVar3;
  double dVar4;
  
  lVar3 = (longdouble)f;
  do {
    lVar3 = lVar3 - (longdouble)(unkint10)(lVar3 / (longdouble)360.0) * (longdouble)360.0;
  } while ((in_FPUStatusWord & 0x400) != 0);
  if (NAN(lVar3)) {
    dVar4 = fmod((double)f,360.0);
    lVar3 = (longdouble)dVar4;
  }
                    /* Unresolved local var: uchar * buf@[???] */
  puVar1 = SZ_GetSpace(sb,2);
  uVar2 = (int)(((float)lVar3 * 65536.0) / 360.0) & 0xffff;
  *puVar1 = (char)uVar2;
  puVar1[1] = (char)(uVar2 >> 8);
  return;
}


// MSG_WriteLong  @ 00061370
void MSG_WriteLong(sizebuf_t *sb,int c)

{
  undefined1 *puVar1;
  
                    /* Unresolved local var: uchar * buf@[DW_OP_reg0(EAX)] */
  puVar1 = SZ_GetSpace(sb,4);
  puVar1[1] = (char)((uint)c >> 8);
  *puVar1 = (char)c;
  puVar1[2] = (char)((uint)c >> 0x10);
  puVar1[3] = (char)((uint)c >> 0x18);
  return;
}


// MSG_WriteOneBit  @ 000612f0
void MSG_WriteOneBit(int nValue)

{
  uint32 *puVar1;
  
  if (7 < bfwrite.nCurOutputBit) {
    SZ_GetSpace(bfwrite.pbuf,1);
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
  }
  if (((bfwrite.pbuf)->flags & 2) == 0) {
    if (nValue != 0) {
      *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)BITTABLE[bfwrite.nCurOutputBit];
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      return;
    }
    puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
    bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
    *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
  }
  return;
}


// MSG_WriteSBits  @ 00061b60
void MSG_WriteSBits(int data,int numbits)

{
  uint32 *puVar1;
  uint uVar2;
  uint uVar3;
  
                    /* Unresolved local var: uint32 uidata@[???] */
  uVar2 = data;
                    /* Unresolved local var: int sigbits@[???]
                       Unresolved local var: int maxnum@[???] */
  if (((numbits < 0x20) &&
      (uVar3 = (1 << ((char)numbits - 1U & 0x1f)) - 1, uVar2 = uVar3, data <= (int)uVar3)) &&
     (uVar2 = data, data < (int)-uVar3)) {
    uVar2 = -uVar3;
  }
  if ((int)uVar2 < 0) {
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      puVar1 = BITTABLE + bfwrite.nCurOutputBit;
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar1;
    }
  }
  else {
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
    }
  }
  MSG_WriteBits((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f),numbits + -1);
  return;
}


// MSG_WriteShort  @ 000613e0
void MSG_WriteShort(sizebuf_t *sb,int c)

{
  undefined1 *puVar1;
  
                    /* Unresolved local var: uchar * buf@[DW_OP_reg0(EAX)] */
  puVar1 = SZ_GetSpace(sb,2);
  *puVar1 = (char)c;
  puVar1[1] = (char)((uint)c >> 8);
  return;
}


// MSG_WriteString  @ 00061840
void MSG_WriteString(sizebuf_t *sb,char *s)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  uint length;
  byte bVar9;
  int iVar8;
  
  bVar9 = 0;
  if (s == (char *)0x0) {
                    /* Unresolved local var: uchar * pData@[???] */
    puVar5 = SZ_GetSpace(sb,1);
    if ((sb->flags & 2) == 0) {
      *puVar5 = 0;
    }
  }
  else {
                    /* Unresolved local var: int count@[???] */
    iVar7 = 0;
    if (*s == '\0') {
      length = 1;
    }
    else {
      do {
        iVar8 = iVar7;
        iVar7 = iVar8 + 1;
      } while (s[iVar7] != '\0');
      length = iVar8 + 2;
    }
                    /* Unresolved local var: uchar * pData@[???] */
    pcVar4 = SZ_GetSpace(sb,length);
    if ((sb->flags & 2) == 0) {
      if (7 < length) {
        uVar6 = length;
        if (((uint)pcVar4 & 1) != 0) {
          cVar1 = *s;
          uVar6 = length - 1;
          s = s + 1;
          *pcVar4 = cVar1;
          pcVar4 = pcVar4 + 1;
        }
        if (((uint)pcVar4 & 2) != 0) {
          uVar2 = *(undefined2 *)s;
          uVar6 = uVar6 - 2;
          s = s + 2;
          *(undefined2 *)pcVar4 = uVar2;
          pcVar4 = pcVar4 + 2;
        }
        if (((uint)pcVar4 & 4) != 0) {
          uVar3 = *(undefined4 *)s;
          uVar6 = uVar6 - 4;
          s = s + 4;
          *(undefined4 *)pcVar4 = uVar3;
          pcVar4 = pcVar4 + 4;
        }
        length = uVar6 & 3;
        for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar4 = *(undefined4 *)s;
          s = s + (uint)bVar9 * -8 + 4;
          pcVar4 = pcVar4 + (uint)bVar9 * -8 + 4;
        }
      }
      iVar7 = 0;
      if ((length & 4) != 0) {
        iVar7 = 4;
        *(undefined4 *)pcVar4 = *(undefined4 *)s;
      }
      if ((length & 2) != 0) {
        *(undefined2 *)(pcVar4 + iVar7) = *(undefined2 *)(s + iVar7);
        iVar7 = iVar7 + 2;
      }
      if ((length & 1) != 0) {
        pcVar4[iVar7] = s[iVar7];
      }
    }
  }
  return;
}


// MSG_WriteUsercmd  @ 00061720
void MSG_WriteUsercmd(sizebuf_t *buf,usercmd_t *to,usercmd_t *from)

{
  delta_t **ppdVar1;
  
                    /* Unresolved local var: delta_t * * ppdesc@[???] */
  ppdVar1 = DELTA_LookupRegistration("usercmd_t");
  bfwrite.nCurOutputBit = 0;
  bfwrite.pbuf = buf;
  bfwrite.pOutByte = buf->data + buf->cursize;
  DELTA_WriteDelta((uchar *)from,(uchar *)to,true,*ppdVar1,(_func_void *)0x0);
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
  if (((bfwrite.pbuf)->flags & 2) == 0) {
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
    *bfwrite.pOutByte =
         *bfwrite.pOutByte & (byte)(0xff >> (8U - (char)bfwrite.nCurOutputBit & 0x1f));
    SZ_GetSpace(bfwrite.pbuf,1);
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = (uchar *)0x0;
    bfwrite.pbuf = (sizebuf_t *)0x0;
  }
  return;
}


// MSG_WriteVec3Coord  @ 00062530
void MSG_WriteVec3Coord(sizebuf_t *sb,float *fa)

{
  if (bfwrite.pbuf != (sizebuf_t *)0x0) {
    MSG_WriteBitVec3Coord(fa);
    return;
  }
  bfwrite.nCurOutputBit = 0;
  bfwrite.pOutByte = sb->data + sb->cursize;
  bfwrite.pbuf = sb;
  MSG_WriteBitVec3Coord(fa);
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
  if (((bfwrite.pbuf)->flags & 2) == 0) {
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
    *bfwrite.pOutByte =
         *bfwrite.pOutByte & (byte)(0xff >> (8U - (char)bfwrite.nCurOutputBit & 0x1f));
    SZ_GetSpace(bfwrite.pbuf,1);
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = (uchar *)0x0;
    bfwrite.pbuf = (sizebuf_t *)0x0;
  }
  return;
}


// MSG_WriteWord  @ 000613b0
void MSG_WriteWord(sizebuf_t *sb,int c)

{
  undefined1 *puVar1;
  
                    /* Unresolved local var: uchar * buf@[DW_OP_reg0(EAX)] */
  puVar1 = SZ_GetSpace(sb,2);
  *puVar1 = (char)c;
  puVar1[1] = (char)((uint)c >> 8);
  return;
}


