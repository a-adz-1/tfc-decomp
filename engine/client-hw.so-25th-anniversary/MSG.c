// MSG_BeginReading  @ 000a1020
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MSG_BeginReading(void)

{
  msg_readcount = 0;
  msg_badread = false;
  return;
}


// MSG_CurrentBit  @ 0009fc00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int MSG_CurrentBit(void)

{
                    /* Unresolved local var: int nbits@[???] */
  if (bfread.pbuf != (sizebuf_t *)0x0) {
    return bfread.nCurInputBit + bfread.nBytesRead * 8;
  }
  return msg_readcount << 3;
}


// MSG_EndBitReading  @ 0009fc90
void MSG_EndBitReading(sizebuf_t *buf)

{
  if (buf->cursize < bfread.msg_readcount) {
    msg_badread = true;
  }
  msg_readcount = bfread.msg_readcount;
  bfread.nBitFieldReadStartByte = 0;
  bfread.pInByte = (uchar *)0x0;
  bfread.nCurInputBit = 0;
  bfread.nBytesRead = 0;
  bfread.pbuf = (sizebuf_t *)0x0;
  return;
}


// MSG_EndBitWriting  @ 0009f920
void MSG_EndBitWriting(sizebuf_t *buf)

{
  sizebuf_t *psVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
  if (((bfwrite.pbuf)->flags & 2) != 0) {
    return;
  }
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
  *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)(0xff >> (8U - (char)bfwrite.nCurOutputBit & 0x1f));
  psVar1 = bfwrite.pbuf;
                    /* Unresolved local var: void * data@[???] */
  iVar3 = (bfwrite.pbuf)->maxsize;
  if ((bfwrite.pbuf)->cursize < iVar3) {
    iVar3 = (bfwrite.pbuf)->cursize + 1;
  }
  else {
    if (((bfwrite.pbuf)->flags & 1) == 0) {
      pcVar2 = (bfwrite.pbuf)->buffername;
      if (iVar3 == 0) {
        if (pcVar2 == (char *)0x0) {
          pcVar2 = "???";
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar2);
      }
      if (pcVar2 == (char *)0x0) {
        pcVar2 = "???";
      }
                    /* WARNING: Subroutine does not return */
      Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar2);
    }
    if (iVar3 < 1) {
      pcVar2 = (bfwrite.pbuf)->buffername;
      if (pcVar2 == (char *)0x0) {
        pcVar2 = "???";
      }
      Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",1,pcVar2);
    }
    pcVar2 = psVar1->buffername;
    if (pcVar2 == (char *)0x0) {
      pcVar2 = "???";
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar2);
    psVar1->flags = (ushort)*(undefined4 *)&psVar1->flags | 2;
    iVar3 = 1;
  }
  psVar1->cursize = iVar3;
  bfwrite.nCurOutputBit = 0;
  bfwrite.pOutByte = (uchar *)0x0;
  bfwrite.pbuf = (sizebuf_t *)0x0;
  return;
}


// MSG_IsBitReading  @ 0009fc30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean MSG_IsBitReading(void)

{
  return (uint)(bfread.pbuf != (sizebuf_t *)0x0);
}


// MSG_IsBitWriting  @ 0009f910
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean MSG_IsBitWriting(void)

{
  return (uint)(bfwrite.pbuf != (sizebuf_t *)0x0);
}


// MSG_PeekBits  @ 0009fec0
uint32 MSG_PeekBits(int numbits)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint32 local_1c;
  
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: bf_read_t savebf@[???] */
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  if (msg_badread == false) {
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
    if (bfread.nCurInputBit < 8) {
      uVar5 = numbits + bfread.nCurInputBit;
      uVar3 = *(uint *)bfread.pInByte >> ((byte)bfread.nCurInputBit & 0x1f);
      iVar4 = bfread.msg_readcount;
      iVar1 = bfread.nCurInputBit;
      puVar2 = (uint *)bfread.pInByte;
    }
    else {
      uVar3 = *(uint *)(bfread.pInByte + 1);
      iVar4 = bfread.msg_readcount + 1;
      iVar1 = 0;
      puVar2 = (uint *)(bfread.pInByte + 1);
      uVar5 = numbits;
    }
    if (uVar5 < 0x21) {
      local_1c = uVar3 & ROWBITTABLE[numbits];
      uVar3 = uVar5 >> 3;
      if ((uVar5 & 7) == 0) {
        uVar3 = uVar3 - 1;
      }
      iVar4 = iVar4 + uVar3;
    }
    else {
      local_1c = (puVar2[1] & ROWBITTABLE[uVar5 & 7]) << (0x20U - (char)iVar1 & 0x1f) | uVar3;
      iVar4 = iVar4 + 4;
    }
    if ((bfread.pbuf)->cursize < iVar4) {
      msg_badread = true;
      local_1c = 1;
    }
    return local_1c;
  }
  return 1;
}


// MSG_ReadAngle  @ 000a13e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float MSG_ReadAngle(void)

{
  byte *pbVar1;
  
                    /* Unresolved local var: int angle@[???]
                       Unresolved local var: int c@[???] */
  if (net_message.cursize <= msg_readcount) {
    msg_badread = true;
    return 0.0;
  }
  pbVar1 = net_message.data + msg_readcount;
  msg_readcount = msg_readcount + 1;
  if (msg_badread == false) {
    return (float)(short)(char)*pbVar1 * 1.40625;
  }
  return 0.0;
}


// MSG_ReadBitAngle  @ 0009fa70
float MSG_ReadBitAngle(int numbits)

{
  uint *puVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
                    /* Unresolved local var: float fReturn@[???]
                       Unresolved local var: uint32 ui@[???]
                       Unresolved local var: float shift@[???] */
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  if (msg_badread != false) {
    fVar2 = 1.0;
    goto LAB_0009faa1;
  }
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  if (bfread.nCurInputBit < 8) {
    uVar4 = numbits + bfread.nCurInputBit;
    if (0x20 < uVar4) goto LAB_0009fafd;
LAB_0009fba0:
    uVar3 = *(uint *)bfread.pInByte >> ((byte)bfread.nCurInputBit & 0x1f) & ROWBITTABLE[numbits];
    uVar5 = uVar4 >> 3;
    bfread.nCurInputBit = uVar4 & 7;
    if (bfread.nCurInputBit == 0) {
      uVar5 = uVar5 - 1;
      bfread.nCurInputBit = 8;
    }
    bfread.pInByte = (uchar *)((int)bfread.pInByte + uVar5);
    bfread.msg_readcount = bfread.msg_readcount + uVar5;
    bfread.nBytesRead = uVar5 + bfread.nBytesRead;
    if (bfread.msg_readcount <= (bfread.pbuf)->cursize) goto LAB_0009fbea;
  }
  else {
    bfread.nCurInputBit = 0;
    bfread.msg_readcount = bfread.msg_readcount + 1;
    bfread.nBytesRead = bfread.nBytesRead + 1;
    bfread.pInByte = bfread.pInByte + 1;
    uVar4 = numbits;
    if ((uint)numbits < 0x21) goto LAB_0009fba0;
LAB_0009fafd:
    puVar1 = (uint *)((int)bfread.pInByte + 4);
    uVar4 = uVar4 & 7;
    bfread.msg_readcount = bfread.msg_readcount + 4;
    bfread.nBytesRead = bfread.nBytesRead + 4;
    uVar3 = (*(uint *)((int)bfread.pInByte + 4) & ROWBITTABLE[uVar4]) <<
            (0x20 - (byte)bfread.nCurInputBit & 0x1f) |
            *(uint *)bfread.pInByte >> ((byte)bfread.nCurInputBit & 0x1f);
    bfread.nCurInputBit = uVar4;
    bfread.pInByte = (uchar *)puVar1;
    if (bfread.msg_readcount <= (bfread.pbuf)->cursize) {
LAB_0009fbea:
      fVar2 = (float)uVar3;
      goto LAB_0009faa1;
    }
  }
  msg_badread = true;
  fVar2 = 1.0;
LAB_0009faa1:
  return fVar2 * (360.0 / (float)(1 << ((byte)numbits & 0x1f)));
}


// MSG_ReadBitCoord  @ 000a05a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float MSG_ReadBitCoord(void)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  uint32 uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
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
      goto LAB_000a067a;
    }
                    /* Unresolved local var: int nValue@[???] */
    iVar5 = bfread.nCurInputBit + 1;
    uVar6 = (uint)*bfread.pInByte & BITTABLE[bfread.nCurInputBit];
                    /* Unresolved local var: int nValue@[???] */
    bfread.nCurInputBit = iVar5;
    if (iVar5 == 8) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.nCurInputBit = 0;
    }
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      uVar3 = (uint)(uVar6 != 0);
      bVar7 = true;
      msg_badread = true;
    }
    else {
                    /* Unresolved local var: int nValue@[???] */
      iVar5 = bfread.nCurInputBit + 1;
      uVar2 = (uint)*bfread.pInByte & BITTABLE[bfread.nCurInputBit];
      if ((uVar6 == 0) && (uVar2 == 0)) {
        bfread.nCurInputBit = iVar5;
        return 0.0;
      }
                    /* Unresolved local var: int nValue@[???] */
      if (iVar5 < 8) {
        bfread.nCurInputBit = iVar5;
        if ((bfread.pbuf)->cursize < bfread.msg_readcount) goto LAB_000a075e;
LAB_000a06d8:
                    /* Unresolved local var: int nValue@[???] */
        bfread.nCurInputBit = iVar5 + 1;
        bVar7 = (BITTABLE[iVar5] & (uint)*bfread.pInByte) != 0;
        uVar3 = 0;
        if (uVar6 != 0) {
          uVar3 = MSG_ReadBits(0xc);
        }
      }
      else {
        iVar5 = 0;
        bfread.pInByte = bfread.pInByte + 1;
        bfread.nBytesRead = bfread.nBytesRead + 1;
        bfread.msg_readcount = bfread.msg_readcount + 1;
        bfread.nCurInputBit = 0;
        if (bfread.msg_readcount <= (bfread.pbuf)->cursize) goto LAB_000a06d8;
LAB_000a075e:
        msg_badread = true;
        if (uVar6 == 0) {
          if (uVar2 == 0) {
            msg_badread = true;
            return -0.0;
          }
          bVar7 = true;
          uVar3 = 0;
          goto LAB_000a06a6;
        }
        uVar3 = 1;
        bVar7 = true;
      }
      if (uVar2 == 0) {
        fVar1 = 0.0;
        goto LAB_000a070c;
      }
    }
  }
  else {
LAB_000a067a:
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
    uVar3 = 1;
    bVar7 = true;
  }
LAB_000a06a6:
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  if (msg_badread == false) {
    uVar4 = MSG_ReadBits(3);
    fVar1 = (float)(int)uVar4 * 0.125;
  }
  else {
    fVar1 = 0.125;
  }
LAB_000a070c:
  fVar1 = (float)(int)uVar3 + fVar1;
  if (bVar7) {
    fVar1 = -fVar1;
  }
  return fVar1;
}


// MSG_ReadBitData  @ 000a0420
int MSG_ReadBitData(void *dest,int length)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  int local_18;
  int local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int readlen@[???]
                       Unresolved local var: uchar * p@[???] */
  pbVar2 = dest;
  if (0 < length) {
    do {
      while( true ) {
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
        pbVar3 = pbVar2 + 1;
        bVar4 = 1;
        if (msg_badread == false) break;
LAB_000a0440:
        *pbVar2 = bVar4;
        pbVar2 = pbVar3;
        if (pbVar3 == (byte *)(length + (int)dest)) {
          return length;
        }
      }
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
      if (bfread.nCurInputBit < 8) {
        uVar1 = bfread.nCurInputBit + 8;
        bVar4 = (byte)bfread.nCurInputBit;
        if (uVar1 < 0x21) {
          local_18 = bfread.msg_readcount;
          uVar5 = uVar1 >> 3;
          local_14 = bfread.nBytesRead;
          bfread.nCurInputBit = uVar1 & 7;
          bVar4 = (byte)(*(uint *)bfread.pInByte >> (bVar4 & 0x1f));
          if (bfread.nCurInputBit == 0) goto LAB_000a04ac;
          goto LAB_000a04b2;
        }
        bfread.nCurInputBit = uVar1 & 7;
        bfread.nBytesRead = bfread.nBytesRead + 4;
        bVar4 = (byte)((*(uint *)(bfread.pInByte + 4) & ROWBITTABLE[bfread.nCurInputBit]) <<
                      (0x20 - bVar4 & 0x1f)) | (byte)(*(uint *)bfread.pInByte >> (bVar4 & 0x1f));
        bfread.msg_readcount = bfread.msg_readcount + 4;
        bfread.pInByte = bfread.pInByte + 4;
      }
      else {
        uVar5 = 1;
        local_18 = bfread.msg_readcount + 1;
        local_14 = bfread.nBytesRead + 1;
        bVar4 = bfread.pInByte[1];
        bfread.pInByte = bfread.pInByte + 1;
LAB_000a04ac:
        uVar5 = uVar5 - 1;
        bfread.nCurInputBit = 8;
LAB_000a04b2:
        bfread.msg_readcount = local_18 + uVar5;
        bfread.nBytesRead = uVar5 + local_14;
        bfread.pInByte = bfread.pInByte + uVar5;
      }
      if (bfread.msg_readcount <= (bfread.pbuf)->cursize) goto LAB_000a0440;
      msg_badread = true;
      *pbVar2 = 1;
      pbVar2 = pbVar3;
    } while (pbVar3 != (byte *)(length + (int)dest));
  }
  return length;
}


// MSG_ReadBitString  @ 000a02a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * MSG_ReadBitString(void)

{
  uint uVar1;
  uchar *puVar2;
  sizebuf_t *psVar3;
  qboolean qVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  int local_14;
  
                    /* Unresolved local var: char c@[???]
                       Unresolved local var: char * p@[???] */
  psVar3 = bfread.pbuf;
  MSG_ReadBitString::buf[0] = '\0';
  if (msg_badread != false) {
    MSG_ReadBitString::buf[0] = '\0';
    return MSG_ReadBitString::buf;
  }
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  pbVar5 = (byte *)MSG_ReadBitString::buf;
  iVar8 = bfread.msg_readcount;
  do {
    qVar4 = msg_badread;
    if (bfread.nCurInputBit < 8) {
      uVar1 = bfread.nCurInputBit + 8;
      bVar7 = (byte)bfread.nCurInputBit;
      if (uVar1 < 0x21) {
        local_14 = bfread.nBytesRead;
        uVar9 = uVar1 >> 3;
        bfread.nCurInputBit = uVar1 & 7;
        bVar7 = (byte)(*(uint *)bfread.pInByte >> (bVar7 & 0x1f));
        if (bfread.nCurInputBit == 0) goto LAB_000a0315;
        goto LAB_000a031b;
      }
      puVar2 = bfread.pInByte + 4;
      bfread.nCurInputBit = uVar1 & 7;
      iVar8 = iVar8 + 4;
      bfread.nBytesRead = bfread.nBytesRead + 4;
      bVar7 = (byte)((*(uint *)(bfread.pInByte + 4) & ROWBITTABLE[bfread.nCurInputBit]) <<
                    (0x20 - bVar7 & 0x1f)) | (byte)(*(uint *)bfread.pInByte >> (bVar7 & 0x1f));
      bfread.msg_readcount = iVar8;
      bfread.pInByte = puVar2;
      if (psVar3->cursize < iVar8) goto LAB_000a0345;
    }
    else {
      iVar8 = iVar8 + 1;
      uVar9 = 1;
      local_14 = bfread.nBytesRead + 1;
      bVar7 = bfread.pInByte[1];
      bfread.pInByte = bfread.pInByte + 1;
LAB_000a0315:
      uVar9 = uVar9 - 1;
      bfread.nCurInputBit = 8;
LAB_000a031b:
      bfread.pInByte = bfread.pInByte + uVar9;
      iVar8 = iVar8 + uVar9;
      bfread.nBytesRead = uVar9 + local_14;
      bfread.msg_readcount = iVar8;
      if (psVar3->cursize < iVar8) {
LAB_000a0345:
        msg_badread = true;
        *pbVar5 = 1;
        pbVar6 = pbVar5 + 1;
        break;
      }
    }
    pbVar6 = pbVar5;
    bfread.msg_readcount = iVar8;
    if (bVar7 == 0) break;
    pbVar6 = pbVar5 + 1;
    *pbVar5 = bVar7;
    pbVar5 = pbVar6;
  } while (qVar4 == false);
  *pbVar6 = 0;
  return MSG_ReadBitString::buf;
}


// MSG_ReadBitVec3Coord  @ 000a07c0
void MSG_ReadBitVec3Coord(vec_t *fa)

{
  int iVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint32 uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  float fVar10;
  
                    /* Unresolved local var: int xflag@[???]
                       Unresolved local var: int yflag@[???]
                       Unresolved local var: int zflag@[???] */
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
      goto LAB_000a08ea;
    }
                    /* Unresolved local var: int nValue@[???] */
    iVar1 = bfread.nCurInputBit + 1;
    puVar2 = BITTABLE + bfread.nCurInputBit;
    bVar3 = *bfread.pInByte;
                    /* Unresolved local var: int nValue@[???] */
    bfread.nCurInputBit = iVar1;
    if (iVar1 == 8) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.nCurInputBit = 0;
    }
    if (bfread.msg_readcount <= (bfread.pbuf)->cursize) {
                    /* Unresolved local var: int nValue@[???] */
      iVar1 = bfread.nCurInputBit + 1;
      bVar8 = (BITTABLE[bfread.nCurInputBit] & (uint)*bfread.pInByte) != 0;
                    /* Unresolved local var: int nValue@[???] */
      bfread.nCurInputBit = iVar1;
      if (iVar1 == 8) {
        bfread.nBytesRead = bfread.nBytesRead + 1;
        bfread.msg_readcount = bfread.msg_readcount + 1;
        bfread.pInByte = bfread.pInByte + 1;
        bfread.nCurInputBit = 0;
      }
      if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
        msg_badread = true;
        bVar9 = true;
      }
      else {
                    /* Unresolved local var: int nValue@[???] */
        bVar9 = (BITTABLE[bfread.nCurInputBit] & (uint)*bfread.pInByte) != 0;
        bfread.nCurInputBit = bfread.nCurInputBit + 1;
      }
      if (((uint)bVar3 & *puVar2) != 0) goto LAB_000a08f4;
      goto LAB_000a08c2;
    }
    msg_badread = true;
    if (((uint)bVar3 & *puVar2) != 0) goto LAB_000a08ea;
    bVar9 = true;
LAB_000a0933:
    fVar10 = MSG_ReadBitCoord();
    fa[1] = fVar10;
  }
  else {
LAB_000a08ea:
    bVar8 = true;
    bVar9 = true;
LAB_000a08f4:
    fVar10 = MSG_ReadBitCoord();
    *fa = fVar10;
LAB_000a08c2:
    if (bVar8) goto LAB_000a0933;
  }
  if (!bVar9) {
    return;
  }
                    /* Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???]
                       Unresolved local var: int signbit@[???]
                       Unresolved local var: float value@[???]
                       Unresolved local var: int nValue@[???] */
  if (msg_badread == false) {
    if (7 < bfread.nCurInputBit) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.nCurInputBit = 0;
    }
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      msg_badread = true;
      goto LAB_000a0a0a;
    }
                    /* Unresolved local var: int nValue@[???] */
    iVar1 = bfread.nCurInputBit + 1;
    uVar7 = (uint)*bfread.pInByte & BITTABLE[bfread.nCurInputBit];
                    /* Unresolved local var: int nValue@[???] */
    bfread.nCurInputBit = iVar1;
    if (iVar1 == 8) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.nCurInputBit = 0;
    }
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      uVar5 = (uint)(uVar7 != 0);
      bVar8 = true;
      msg_badread = true;
      goto LAB_000a0a36;
    }
                    /* Unresolved local var: int nValue@[???] */
    iVar1 = bfread.nCurInputBit + 1;
    uVar4 = (uint)*bfread.pInByte & BITTABLE[bfread.nCurInputBit];
    bfread.nCurInputBit = iVar1;
    if ((uVar7 == 0) && (uVar4 == 0)) {
      fVar10 = 0.0;
      goto LAB_000a09ef;
    }
                    /* Unresolved local var: int nValue@[???] */
    if (7 < iVar1) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.nCurInputBit = 0;
    }
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      msg_badread = true;
      if (uVar7 == 0) {
        if (uVar4 == 0) {
          fVar10 = -0.0;
          goto LAB_000a09ef;
        }
        bVar8 = true;
        uVar5 = 0;
        goto LAB_000a0a36;
      }
      uVar5 = 1;
      bVar8 = true;
    }
    else {
                    /* Unresolved local var: int nValue@[???] */
      iVar1 = bfread.nCurInputBit + 1;
      bVar8 = (BITTABLE[bfread.nCurInputBit] & (uint)*bfread.pInByte) != 0;
      uVar5 = 0;
      bfread.nCurInputBit = iVar1;
      if (uVar7 != 0) {
        uVar5 = MSG_ReadBits(0xc);
      }
    }
    if (uVar4 != 0) goto LAB_000a0a36;
    fVar10 = 0.0;
  }
  else {
LAB_000a0a0a:
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
    uVar5 = 1;
    bVar8 = true;
LAB_000a0a36:
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
    if (msg_badread == false) {
      uVar6 = MSG_ReadBits(3);
      fVar10 = (float)(int)uVar6 * 0.125;
    }
    else {
      fVar10 = 0.125;
    }
  }
  fVar10 = (float)(int)uVar5 + fVar10;
  if (bVar8) {
    fVar10 = -fVar10;
  }
LAB_000a09ef:
  fa[2] = fVar10;
  return;
}


// MSG_ReadBits  @ 0009dc60
uint32 __regparm3 MSG_ReadBits(int numbits)

{
  uint uVar1;
  uint32 uVar2;
  byte bVar3;
  uint uVar4;
  
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  if (7 < bfread.nCurInputBit) {
    bfread.nCurInputBit = 0;
    bfread.msg_readcount = bfread.msg_readcount + 1;
    bfread.pInByte = bfread.pInByte + 1;
    bfread.nBytesRead = bfread.nBytesRead + 1;
  }
  uVar1 = numbits + bfread.nCurInputBit;
  bVar3 = (byte)bfread.nCurInputBit;
  uVar4 = *(uint *)bfread.pInByte >> (bVar3 & 0x1f);
  if (uVar1 < 0x21) {
    uVar2 = uVar4 & ROWBITTABLE[numbits];
    uVar4 = uVar1 >> 3;
    bfread.nCurInputBit = uVar1 & 7;
    if (bfread.nCurInputBit == 0) {
      uVar4 = uVar4 - 1;
      bfread.nCurInputBit = 8;
    }
    bfread.pInByte = (uchar *)((int)bfread.pInByte + uVar4);
    bfread.msg_readcount = bfread.msg_readcount + uVar4;
    bfread.nBytesRead = uVar4 + bfread.nBytesRead;
  }
  else {
    bfread.nCurInputBit = uVar1 & 7;
    bfread.msg_readcount = bfread.msg_readcount + 4;
    bfread.nBytesRead = bfread.nBytesRead + 4;
    uVar2 = (*(uint *)((int)bfread.pInByte + 4) & ROWBITTABLE[bfread.nCurInputBit]) <<
            (0x20 - bVar3 & 0x1f) | uVar4;
    bfread.pInByte = (uchar *)((int)bfread.pInByte + 4);
  }
  if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
    msg_badread = true;
    uVar2 = 1;
  }
  return uVar2;
}


// MSG_ReadBits  @ 0009fd70
uint32 MSG_ReadBits(int numbits)

{
  uint *puVar1;
  uint32 uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  if (msg_badread == false) {
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
    if (bfread.nCurInputBit < 8) {
      uVar4 = numbits + bfread.nCurInputBit;
      puVar1 = (uint *)bfread.pInByte;
    }
    else {
      bfread.nCurInputBit = 0;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.nBytesRead = bfread.nBytesRead + 1;
      puVar1 = (uint *)(bfread.pInByte + 1);
      uVar4 = numbits;
    }
    bVar3 = (byte)bfread.nCurInputBit;
    if (uVar4 < 0x21) {
      uVar5 = uVar4 >> 3;
      uVar2 = *puVar1 >> (bVar3 & 0x1f) & ROWBITTABLE[numbits];
      bfread.nCurInputBit = uVar4 & 7;
      if (bfread.nCurInputBit == 0) {
        uVar5 = uVar5 - 1;
        bfread.nCurInputBit = 8;
      }
      bfread.pInByte = (uchar *)((int)puVar1 + uVar5);
      bfread.msg_readcount = bfread.msg_readcount + uVar5;
      bfread.nBytesRead = uVar5 + bfread.nBytesRead;
    }
    else {
      bfread.pInByte = (uchar *)(puVar1 + 1);
      bfread.nCurInputBit = uVar4 & 7;
      bfread.msg_readcount = bfread.msg_readcount + 4;
      bfread.nBytesRead = bfread.nBytesRead + 4;
      uVar2 = (puVar1[1] & ROWBITTABLE[bfread.nCurInputBit]) << (0x20 - bVar3 & 0x1f) |
              *puVar1 >> (bVar3 & 0x1f);
    }
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      msg_badread = true;
      uVar2 = 1;
    }
    return uVar2;
  }
  return 1;
}


// MSG_ReadBuf  @ 000a11d0
int MSG_ReadBuf(int iSize,void *pbuf)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  if (net_message.cursize < msg_readcount + iSize) {
    iVar4 = -1;
    msg_badread = true;
  }
  else {
    pbVar5 = net_message.data + msg_readcount;
    iVar4 = iSize;
    if (7 < (uint)iSize) {
      pbVar6 = pbuf;
      if (((uint)pbuf & 1) != 0) {
        bVar1 = *pbVar5;
        pbVar6 = (byte *)((int)pbuf + 1);
        pbVar5 = pbVar5 + 1;
        iVar4 = iSize + -1;
        *(byte *)pbuf = bVar1;
      }
      pbVar7 = pbVar6;
      if (((uint)pbVar6 & 2) != 0) {
        uVar2 = *(undefined2 *)pbVar5;
        pbVar7 = pbVar6 + 2;
        pbVar5 = pbVar5 + 2;
        iVar4 = iVar4 + -2;
        *(undefined2 *)pbVar6 = uVar2;
      }
      pbuf = pbVar7;
      if (((uint)pbVar7 & 4) != 0) {
        uVar3 = *(undefined4 *)pbVar5;
        pbuf = pbVar7 + 4;
        pbVar5 = pbVar5 + 4;
        iVar4 = iVar4 + -4;
        *(undefined4 *)pbVar7 = uVar3;
      }
    }
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(byte *)pbuf = *pbVar5;
      pbVar5 = pbVar5 + 1;
      pbuf = (byte *)((int)pbuf + 1);
    }
    msg_readcount = msg_readcount + iSize;
    iVar4 = 1;
  }
  return iVar4;
}


// MSG_ReadByte  @ 000a1060
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


// MSG_ReadChar  @ 000a1030
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


// MSG_ReadCoord  @ 000a0b40
float MSG_ReadCoord(sizebuf_t *sb)

{
  byte *pbVar1;
  int iVar2;
  
                    /* Unresolved local var: short coord@[???]
                       Unresolved local var: int c@[???] */
  if (net_message.cursize <= msg_readcount + 1) {
    msg_badread = true;
    return 0.0;
  }
  iVar2 = msg_readcount + 1;
  pbVar1 = net_message.data + msg_readcount;
  msg_readcount = msg_readcount + 2;
  if (msg_badread == false) {
    return (float)CONCAT11(net_message.data[iVar2],*pbVar1) * 0.125;
  }
  return 0.0;
}


// MSG_ReadFloat  @ 000a1180
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


// MSG_ReadHiresAngle  @ 000a1440
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float MSG_ReadHiresAngle(void)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: int angle@[???]
                       Unresolved local var: int c@[???] */
  if (net_message.cursize <= msg_readcount + 1) {
    msg_badread = true;
    return 0.0;
  }
  iVar3 = msg_readcount + 1;
  pbVar1 = net_message.data + msg_readcount;
  msg_readcount = msg_readcount + 2;
  if (msg_badread == false) {
    fVar2 = (float)CONCAT11(net_message.data[iVar3],*pbVar1) * 0.005493164;
  }
  else {
    fVar2 = 0.0;
  }
  return fVar2;
}


// MSG_ReadLong  @ 000a1110
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
    return (uint)net_message.data[iVar3] * 0x10000 +
           (uint)net_message.data[iVar2] * 0x100 + (uint)*pbVar1 +
           (uint)net_message.data[iVar4] * 0x1000000;
  }
  msg_badread = true;
  return -1;
}


// MSG_ReadOneBit  @ 0009fce0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int MSG_ReadOneBit(void)

{
  uint uVar1;
  
                    /* Unresolved local var: int nValue@[???] */
  uVar1 = 1;
  if (msg_badread == false) {
    if (bfread.nCurInputBit < 8) {
      if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
        msg_badread = true;
        return 1;
      }
    }
    else {
      bfread.pInByte = bfread.pInByte + 1;
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.nCurInputBit = 0;
      if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
        bfread.nCurInputBit = 0;
        msg_badread = true;
        return 1;
      }
    }
                    /* Unresolved local var: int nValue@[???] */
    uVar1 = (uint)((BITTABLE[bfread.nCurInputBit] & (uint)*bfread.pInByte) != 0);
    bfread.nCurInputBit = bfread.nCurInputBit + 1;
  }
  return uVar1;
}


// MSG_ReadSBits  @ 000a0090
int MSG_ReadSBits(int numbits)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_18;
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int nSignBit@[???]
                       Unresolved local var: int nValue@[???] */
  if (msg_badread != false) {
    return -1;
  }
  if (bfread.nCurInputBit < 8) {
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      msg_badread = true;
      return -1;
    }
    iVar4 = bfread.nCurInputBit + 1;
    uVar3 = numbits - 1;
    uVar5 = (uint)*bfread.pInByte & BITTABLE[bfread.nCurInputBit];
    if (iVar4 == 8) {
      bfread.msg_readcount = bfread.msg_readcount + 1;
      iVar4 = 0;
      bfread.nBytesRead = bfread.nBytesRead + 1;
      uVar2 = *(uint *)(bfread.pInByte + 1);
      puVar1 = (uint *)(bfread.pInByte + 1);
      goto joined_r0x000a0215;
    }
  }
  else {
    bfread.msg_readcount = bfread.msg_readcount + 1;
    bfread.nBytesRead = bfread.nBytesRead + 1;
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
      bfread.nCurInputBit = 0;
      bfread.pInByte = bfread.pInByte + 1;
      msg_badread = true;
      return -1;
    }
                    /* Unresolved local var: int nValue@[???] */
    iVar4 = 1;
    uVar5 = (uint)(bfread.pInByte[1] & 1);
    bfread.pInByte = bfread.pInByte + 1;
  }
                    /* Unresolved local var: uint32 r@[???]
                       Unresolved local var: uint32 post@[???]
                       Unresolved local var: uint32 d@[???] */
  local_18 = numbits + -1;
  uVar3 = local_18 + iVar4;
  uVar2 = *(uint *)bfread.pInByte >> ((byte)iVar4 & 0x1f);
  puVar1 = (uint *)bfread.pInByte;
joined_r0x000a0215:
  if (uVar3 < 0x21) {
    local_18 = numbits + -1;
    uVar2 = uVar2 & ROWBITTABLE[local_18];
    uVar6 = uVar3 >> 3;
    bfread.nCurInputBit = uVar3 & 7;
    if (bfread.nCurInputBit == 0) {
      uVar6 = uVar6 - 1;
      bfread.nCurInputBit = 8;
    }
    bfread.pInByte = (uchar *)((int)puVar1 + uVar6);
    bfread.msg_readcount = bfread.msg_readcount + uVar6;
    bfread.nBytesRead = uVar6 + bfread.nBytesRead;
  }
  else {
    bfread.pInByte = (uchar *)(puVar1 + 1);
    bfread.nCurInputBit = uVar3 & 7;
    bfread.msg_readcount = bfread.msg_readcount + 4;
    uVar2 = (puVar1[1] & ROWBITTABLE[bfread.nCurInputBit]) << (0x20U - (char)iVar4 & 0x1f) | uVar2;
    bfread.nBytesRead = bfread.nBytesRead + 4;
  }
  if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
    uVar2 = 1;
    msg_badread = true;
  }
  if (uVar5 != 0) {
    uVar2 = -uVar2;
  }
  return uVar2;
}


// MSG_ReadShort  @ 000a1090
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


// MSG_ReadString  @ 000a1290
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
  iVar4 = 0;
  iVar6 = msg_readcount;
  while (iVar5 = iVar4, iVar6 < iVar3) {
    iVar6 = iVar6 + 1;
    msg_readcount = iVar6;
    if ((int)(char)pbVar2[iVar5 + iVar1] + 1U < 2) goto LAB_000a12bf;
    MSG_ReadString::string[iVar5] = pbVar2[iVar5 + iVar1];
    iVar4 = iVar5 + 1;
    if (iVar5 + 1 == 0x1fff) {
      MSG_ReadString::string[iVar5 + 1] = '\0';
      return MSG_ReadString::string;
    }
  }
  msg_badread = true;
LAB_000a12bf:
  MSG_ReadString::string[iVar5] = '\0';
  return MSG_ReadString::string;
}


// MSG_ReadStringLine  @ 000a1310
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * MSG_ReadStringLine(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = net_message.cursize;
  pbVar3 = net_message.data;
                    /* Unresolved local var: int l@[???]
                       Unresolved local var: int c@[???] */
  iVar2 = msg_readcount;
                    /* Unresolved local var: int c@[???] */
  iVar5 = 0;
  iVar7 = msg_readcount;
  while (iVar6 = iVar5, iVar7 < iVar4) {
    bVar1 = pbVar3[iVar6 + iVar2];
    iVar7 = iVar7 + 1;
    msg_readcount = iVar7;
    if (((int)(char)bVar1 + 1U < 2) || (bVar1 == '\n')) goto LAB_000a133f;
    MSG_ReadStringLine::string[iVar6] = bVar1;
    iVar5 = iVar6 + 1;
    if (iVar6 + 1 == 0x7ff) {
      MSG_ReadStringLine::string[iVar6 + 1] = '\0';
      return MSG_ReadStringLine::string;
    }
  }
  msg_badread = true;
LAB_000a133f:
  MSG_ReadStringLine::string[iVar6] = '\0';
  return MSG_ReadStringLine::string;
}


// MSG_ReadUsercmd  @ 000a14b0
void MSG_ReadUsercmd(usercmd_t *to,usercmd_t *from)

{
  float fVar1;
  delta_t *pFields;
  double dVar2;
  
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
                    /* Unresolved local var: int i@[???] */
  fVar1 = to->viewangles[0];
  if (180.0 < fVar1) {
    dVar2 = fmod((double)fVar1,360.0);
    to->viewangles[0] = (float)dVar2 - 360.0;
    fVar1 = to->viewangles[1];
  }
  else {
    if (fVar1 < -180.0) {
      dVar2 = fmod((double)fVar1,360.0);
      to->viewangles[0] = (float)dVar2 + 360.0;
    }
    fVar1 = to->viewangles[1];
  }
  if (180.0 < fVar1) {
    dVar2 = fmod((double)fVar1,360.0);
    to->viewangles[1] = (float)dVar2 - 360.0;
    fVar1 = to->viewangles[2];
  }
  else {
    if (fVar1 < -180.0) {
      dVar2 = fmod((double)fVar1,360.0);
      to->viewangles[1] = (float)dVar2 + 360.0;
    }
    fVar1 = to->viewangles[2];
  }
  if (180.0 < fVar1) {
    dVar2 = fmod((double)fVar1,360.0);
    to->viewangles[2] = (float)dVar2 - 360.0;
    return;
  }
  if (-180.0 <= fVar1) {
    return;
  }
  dVar2 = fmod((double)fVar1,360.0);
  to->viewangles[2] = (float)dVar2 + 360.0;
  return;
}


// MSG_ReadVec3Coord  @ 000a0cc0
void MSG_ReadVec3Coord(sizebuf_t *sb,float *fa)

{
  uchar *puVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  float fVar8;
  
  if (bfread.pbuf == (sizebuf_t *)0x0) {
    bfread.nCurInputBit = 0;
    bfread.nBytesRead = 0;
    bfread.pbuf = sb;
    bfread.nBitFieldReadStartByte = msg_readcount;
    bfread.pInByte = sb->data + msg_readcount;
    bfread.msg_readcount = msg_readcount + 1;
    if (sb->cursize < bfread.msg_readcount) {
      msg_badread = true;
LAB_000a0e5d:
                    /* Unresolved local var: int xflag@[???]
                       Unresolved local var: int yflag@[???]
                       Unresolved local var: int zflag@[???] */
      bVar3 = 1;
                    /* Unresolved local var: int nValue@[???] */
      bVar4 = 1;
LAB_000a0e67:
      fVar8 = MSG_ReadBitCoord();
      *fa = fVar8;
LAB_000a0e72:
      if (bVar3 == 0) goto LAB_000a0e7a;
    }
    else {
                    /* Unresolved local var: int nValue@[???] */
      if (msg_badread != false) goto LAB_000a0e5d;
                    /* Unresolved local var: int nValue@[???] */
      bfread.nCurInputBit = 1;
                    /* Unresolved local var: int nValue@[???] */
      if (bfread.msg_readcount <= sb->cursize) {
                    /* Unresolved local var: int nValue@[???] */
        bfread.nCurInputBit = 2;
        bVar3 = *bfread.pInByte >> 1 & 1;
        if (sb->cursize < bfread.msg_readcount) {
          msg_badread = true;
          bVar4 = 1;
        }
        else {
                    /* Unresolved local var: int nValue@[???] */
          bfread.nCurInputBit = 3;
          bVar4 = *bfread.pInByte >> 2 & 1;
        }
        if ((*bfread.pInByte & 1) != 0) goto LAB_000a0e67;
        goto LAB_000a0e72;
      }
      msg_badread = true;
      if ((*bfread.pInByte & 1) != 0) goto LAB_000a0e5d;
      bVar4 = 1;
    }
    fVar8 = MSG_ReadBitCoord();
    fa[1] = fVar8;
LAB_000a0e7a:
    if (bVar4 != 0) {
      fVar8 = MSG_ReadBitCoord();
      fa[2] = fVar8;
    }
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
                    /* Unresolved local var: int xflag@[???]
                       Unresolved local var: int yflag@[???]
                       Unresolved local var: int zflag@[???]
                       Unresolved local var: int nValue@[???] */
  if (msg_badread == false) {
    if (7 < bfread.nCurInputBit) {
      bfread.nCurInputBit = 0;
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      puVar1 = bfread.pInByte + 1;
      if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
LAB_000a0df0:
        bfread.pInByte = puVar1;
        msg_badread = true;
        goto LAB_000a0dfb;
      }
      iVar2 = 1;
      bfread.nCurInputBit = 1;
      bVar5 = (bool)(bfread.pInByte[1] & 1);
      bfread.pInByte = puVar1;
      if ((bfread.pbuf)->cursize < bfread.msg_readcount) goto LAB_000a0f93;
LAB_000a0d5a:
                    /* Unresolved local var: int nValue@[???] */
      bfread.nCurInputBit = iVar2 + 1;
      bVar6 = (BITTABLE[iVar2] & (uint)*bfread.pInByte) != 0;
                    /* Unresolved local var: int nValue@[???] */
      if (bfread.nCurInputBit == 8) {
        bfread.nBytesRead = bfread.nBytesRead + 1;
        bfread.pInByte = bfread.pInByte + 1;
        bfread.msg_readcount = bfread.msg_readcount + 1;
        bfread.nCurInputBit = 0;
      }
      if ((bfread.pbuf)->cursize < bfread.msg_readcount) {
        bVar7 = true;
        msg_badread = true;
      }
      else {
                    /* Unresolved local var: int nValue@[???] */
        bVar7 = (BITTABLE[bfread.nCurInputBit] & (uint)*bfread.pInByte) != 0;
        bfread.nCurInputBit = bfread.nCurInputBit + 1;
      }
      if (bVar5 != false) goto LAB_000a0e05;
      goto LAB_000a0dbe;
    }
    puVar1 = bfread.pInByte;
    if ((bfread.pbuf)->cursize < bfread.msg_readcount) goto LAB_000a0df0;
                    /* Unresolved local var: int nValue@[???] */
    iVar2 = bfread.nCurInputBit + 1;
    bVar5 = (BITTABLE[bfread.nCurInputBit] & (uint)*bfread.pInByte) != 0;
                    /* Unresolved local var: int nValue@[???] */
    bfread.nCurInputBit = iVar2;
    if (iVar2 == 8) {
      bfread.nBytesRead = bfread.nBytesRead + 1;
      bfread.msg_readcount = bfread.msg_readcount + 1;
      bfread.pInByte = bfread.pInByte + 1;
      bfread.nCurInputBit = 0;
    }
    iVar2 = bfread.nCurInputBit;
    if (bfread.msg_readcount <= (bfread.pbuf)->cursize) goto LAB_000a0d5a;
LAB_000a0f93:
    msg_badread = true;
    if (bVar5 != false) goto LAB_000a0dfb;
    bVar7 = true;
  }
  else {
LAB_000a0dfb:
    bVar6 = true;
    bVar7 = true;
LAB_000a0e05:
    fVar8 = MSG_ReadBitCoord();
    *fa = fVar8;
LAB_000a0dbe:
    if (!bVar6) goto LAB_000a0dc6;
  }
  fVar8 = MSG_ReadBitCoord();
  fa[1] = fVar8;
LAB_000a0dc6:
  if (bVar7) {
    fVar8 = MSG_ReadBitCoord();
    fa[2] = fVar8;
  }
  return;
}


// MSG_ReadWord  @ 000a10d0
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
    return (uint)net_message.data[iVar2] * 0x100 + (uint)*pbVar1;
  }
  msg_badread = true;
  return -1;
}


// MSG_SkipString  @ 000a1390
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


// MSG_StartBitReading  @ 0009fc40
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


// MSG_StartBitWriting  @ 0009f8f0
void MSG_StartBitWriting(sizebuf_t *buf)

{
  bfwrite.nCurOutputBit = 0;
  bfwrite.pbuf = buf;
  bfwrite.pOutByte = buf->data + buf->cursize;
  return;
}


// MSG_WriteAngle  @ 0009f300
void MSG_WriteAngle(sizebuf_t *sb,float f)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  double dVar4;
  
  dVar4 = fmod((double)f,360.0);
                    /* Unresolved local var: byte * buf@[DW_OP_reg0(EAX)]
                       Unresolved local var: void * data@[???] */
  iVar1 = sb->cursize;
  iVar2 = sb->maxsize;
  bVar3 = (byte)(int)(((float)dVar4 * 256.0) / 360.0);
  if (iVar1 < iVar2) {
    sb->cursize = iVar1 + 1;
    sb->data[iVar1] = bVar3;
    return;
  }
  if ((sb->flags & 1) == 0) {
    if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s");
    }
                    /* WARNING: Subroutine does not return */
    Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s");
  }
  if (iVar2 < 1) {
    Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring");
  }
  Con_Printf("SZ_GetSpace: overflow on %s\n");
  sb->cursize = 1;
  sb->flags = (ushort)*(undefined4 *)&sb->flags | 2;
  *sb->data = bVar3;
  return;
}


// MSG_WriteBitAngle  @ 000a3890
void MSG_WriteBitAngle(float fAngle,int numbits)

{
  bool bVar1;
  uchar *puVar2;
  sizebuf_t *psVar3;
  sizebuf_t *psVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  uint32 uVar10;
  uint uVar11;
  double dVar12;
  
                    /* Unresolved local var: int d@[???]
                       Unresolved local var: uint32 mask@[???]
                       Unresolved local var: uint32 shift@[???] */
  if (0x1f < numbits) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Can\'t write bit angle with 32 bits precision\n");
  }
  uVar11 = 1 << ((byte)numbits & 0x1f);
  dVar12 = fmod((double)fAngle,360.0);
  psVar3 = bfwrite.pbuf;
  uVar10 = uVar11 - 1 & (int)((float)dVar12 * (float)uVar11) / 0x168;
                    /* Unresolved local var: uint32 d@[???]
                       Unresolved local var: uint32 reserveBytes@[???] */
  if (uVar11 <= uVar10) {
    uVar10 = ROWBITTABLE[numbits];
  }
  bVar1 = 7 < bfwrite.nCurOutputBit;
  if (bVar1) {
    iVar5 = 5;
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
  }
  else {
    numbits = numbits + bfwrite.nCurOutputBit;
    iVar5 = 4;
  }
  if ((uint)numbits < 0x21) {
                    /* Unresolved local var: int length@[???] */
    uVar11 = numbits & 7;
    iVar6 = ((uint)numbits >> 3) - (uint)(uVar11 == 0);
    iVar9 = (uint)bVar1 + iVar6;
                    /* Unresolved local var: void * data@[???] */
    iVar5 = (bfwrite.pbuf)->maxsize;
    iVar8 = (bfwrite.pbuf)->cursize + iVar9;
    if (iVar5 < iVar8) {
      if (((bfwrite.pbuf)->flags & 1) == 0) {
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s");
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s");
      }
      if (iVar5 < iVar9) {
        Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring");
      }
      Con_Printf("SZ_GetSpace: overflow on %s\n");
      psVar3->flags = (ushort)*(undefined4 *)&psVar3->flags | 2;
      iVar8 = iVar9;
    }
    psVar4 = bfwrite.pbuf;
    psVar3->cursize = iVar8;
    if ((psVar4->flags & 2) == 0) {
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
      *(uint *)bfwrite.pOutByte =
           *(uint *)bfwrite.pOutByte | uVar10 << ((byte)bfwrite.nCurOutputBit & 0x1f);
      if (uVar11 == 0) {
        uVar11 = 8;
      }
      bfwrite.pOutByte = bfwrite.pOutByte + iVar6;
      bfwrite.nCurOutputBit = uVar11;
    }
  }
  else {
    SZ_GetSpace(bfwrite.pbuf,iVar5);
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
      *(uint *)bfwrite.pOutByte =
           *(uint *)bfwrite.pOutByte | uVar10 << ((byte)bfwrite.nCurOutputBit & 0x1f);
      bVar7 = 0x20 - (byte)bfwrite.nCurOutputBit;
      puVar2 = bfwrite.pOutByte;
      bfwrite.nCurOutputBit = numbits & 7;
      bfwrite.pOutByte = bfwrite.pOutByte + 4;
      puVar2[4] = '\0';
      puVar2[5] = '\0';
      puVar2[6] = '\0';
      puVar2[7] = '\0';
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte | uVar10 >> (bVar7 & 0x1f);
    }
  }
  return;
}


// MSG_WriteBitCoord  @ 000a22f0
/* WARNING: Removing unreachable block (ram,0x000a2458) */
/* WARNING: Removing unreachable block (ram,0x000a240c) */

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
      puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
    }
    else {
      puVar1 = BITTABLE + bfwrite.nCurOutputBit;
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar1;
    }
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
  if (data != 0) {
    if (7 < bfwrite.nCurOutputBit) {
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


// MSG_WriteBitData  @ 000a1d00
void MSG_WriteBitData(void *src,int length)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uchar *puVar4;
  sizebuf_t *psVar5;
  sizebuf_t *psVar6;
  int iVar7;
  char *pcVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  uint local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar * p@[???] */
  pbVar1 = (byte *)((int)src + length);
  if (0 < length) {
    do {
      while( true ) {
        psVar6 = bfwrite.pbuf;
        bVar2 = *(byte *)src;
        if (bfwrite.nCurOutputBit < 8) break;
                    /* Unresolved local var: uint32 d@[???]
                       Unresolved local var: uint32 reserveBytes@[???] */
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
        uVar11 = 1;
        iVar10 = 1;
        bfwrite.nCurOutputBit = 0;
LAB_000a1d40:
                    /* Unresolved local var: int length@[???] */
        uVar11 = uVar11 - 1;
        local_20 = 0;
LAB_000a1d47:
        iVar10 = iVar10 + uVar11;
                    /* Unresolved local var: void * data@[???] */
        iVar3 = (bfwrite.pbuf)->maxsize;
        iVar7 = (bfwrite.pbuf)->cursize + iVar10;
        if (iVar3 < iVar7) {
          if (((bfwrite.pbuf)->flags & 1) == 0) {
            pcVar8 = (bfwrite.pbuf)->buffername;
            if (iVar3 == 0) {
              if (pcVar8 == (char *)0x0) {
                pcVar8 = "???";
              }
                    /* WARNING: Subroutine does not return */
              Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar8);
            }
            if (pcVar8 == (char *)0x0) {
              pcVar8 = "???";
            }
                    /* WARNING: Subroutine does not return */
            Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar8);
          }
          if (iVar3 < iVar10) {
            pcVar8 = (bfwrite.pbuf)->buffername;
            if (pcVar8 == (char *)0x0) {
              pcVar8 = "???";
            }
            Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",iVar10,pcVar8);
          }
          pcVar8 = psVar6->buffername;
          if (pcVar8 == (char *)0x0) {
            pcVar8 = "???";
          }
          Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar8);
          psVar6->flags = (ushort)*(undefined4 *)&psVar6->flags | 2;
          iVar7 = iVar10;
        }
        psVar5 = bfwrite.pbuf;
        psVar6->cursize = iVar7;
        if ((psVar5->flags & 2) == 0) {
          *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit]
          ;
          *(uint *)bfwrite.pOutByte =
               *(uint *)bfwrite.pOutByte | (uint)bVar2 << ((byte)bfwrite.nCurOutputBit & 0x1f);
          bfwrite.nCurOutputBit = 8;
          if (local_20 != 0) {
            bfwrite.nCurOutputBit = local_20;
          }
          bfwrite.pOutByte = bfwrite.pOutByte + uVar11;
        }
LAB_000a1e35:
        src = (void *)((int)src + 1);
        if (src == pbVar1) {
          return;
        }
      }
      local_20 = bfwrite.nCurOutputBit + 8;
      if (local_20 < 0x21) {
        iVar10 = 0;
        uVar11 = local_20 >> 3;
        local_20 = local_20 & 7;
        if (local_20 == 0) goto LAB_000a1d40;
        goto LAB_000a1d47;
      }
      SZ_GetSpace(bfwrite.pbuf,4);
      if (((bfwrite.pbuf)->flags & 2) != 0) goto LAB_000a1e35;
      src = (void *)((int)src + 1);
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
      *(uint *)bfwrite.pOutByte =
           *(uint *)bfwrite.pOutByte | (uint)bVar2 << ((byte)bfwrite.nCurOutputBit & 0x1f);
      bVar9 = 0x20 - (byte)bfwrite.nCurOutputBit;
      puVar4 = bfwrite.pOutByte;
      bfwrite.nCurOutputBit = local_20 & 7;
      bfwrite.pOutByte = bfwrite.pOutByte + 4;
      puVar4[4] = '\0';
      puVar4[5] = '\0';
      puVar4[6] = '\0';
      puVar4[7] = '\0';
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte | (uint)(bVar2 >> (bVar9 & 0x1f));
    } while (src != pbVar1);
  }
  return;
}


// MSG_WriteBitString  @ 000a1f70
void MSG_WriteBitString(char *p)

{
  byte bVar1;
  int iVar2;
  uchar *puVar3;
  char *pcVar4;
  sizebuf_t *psVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  sizebuf_t *buf;
  uint uVar10;
  uint local_28;
  uint local_20;
  
                    /* Unresolved local var: uchar * pch@[???] */
  bVar1 = *p;
  uVar9 = bfwrite.nCurOutputBit;
  buf = bfwrite.pbuf;
joined_r0x000a1f8c:
  bfwrite.nCurOutputBit = uVar9;
  bfwrite.pbuf = buf;
  if (bVar1 != 0) {
    do {
      if ((int)uVar9 < 8) {
        local_20 = uVar9 + 8;
        if (local_20 < 0x21) {
          local_28 = local_20 >> 3;
          local_20 = local_20 & 7;
          iVar6 = 0;
          if (local_20 == 0) goto LAB_000a1fb9;
          goto LAB_000a1fc4;
        }
        SZ_GetSpace(buf,4);
        uVar9 = bfwrite.nCurOutputBit;
        buf = bfwrite.pbuf;
        if (((bfwrite.pbuf)->flags & 2) == 0) goto code_r0x000a210a;
      }
      else {
                    /* Unresolved local var: uint32 d@[???]
                       Unresolved local var: uint32 reserveBytes@[???] */
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
        uVar9 = 0;
        iVar6 = 1;
        bfwrite.nCurOutputBit = 0;
        local_28 = 1;
LAB_000a1fb9:
                    /* Unresolved local var: int length@[???] */
        local_28 = local_28 - 1;
        local_20 = 0;
LAB_000a1fc4:
                    /* Unresolved local var: void * data@[???] */
        iVar6 = iVar6 + local_28;
        iVar2 = buf->maxsize;
        iVar8 = buf->cursize + iVar6;
        psVar5 = buf;
        if (iVar2 < iVar8) {
          if ((buf->flags & 1) == 0) {
            pcVar4 = buf->buffername;
            if (pcVar4 == (char *)0x0) {
              pcVar4 = "???";
            }
            if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
              Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar4);
            }
                    /* WARNING: Subroutine does not return */
            Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar4);
          }
          if (iVar2 < iVar6) {
            pcVar4 = buf->buffername;
            if (pcVar4 == (char *)0x0) {
              pcVar4 = "???";
            }
            Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",iVar6,pcVar4);
          }
          pcVar4 = buf->buffername;
          if (pcVar4 == (char *)0x0) {
            pcVar4 = "???";
          }
          Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar4);
          uVar9 = bfwrite.nCurOutputBit;
          buf->flags = (ushort)*(undefined4 *)&buf->flags | 2;
          psVar5 = bfwrite.pbuf;
          iVar8 = iVar6;
        }
        buf->cursize = iVar8;
        buf = psVar5;
        if ((psVar5->flags & 2) == 0) {
          *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[uVar9];
          *(uint *)bfwrite.pOutByte =
               *(uint *)bfwrite.pOutByte | (uint)bVar1 << ((byte)bfwrite.nCurOutputBit & 0x1f);
          uVar9 = 8;
          if (local_20 != 0) {
            uVar9 = local_20;
          }
          bfwrite.pOutByte = bfwrite.pOutByte + local_28;
          buf = bfwrite.pbuf;
          bfwrite.nCurOutputBit = uVar9;
        }
      }
      p = p + 1;
      bVar1 = *p;
      if (bVar1 == 0) break;
    } while( true );
  }
                    /* Unresolved local var: uint32 d@[???]
                       Unresolved local var: uint32 reserveBytes@[???] */
  if ((int)uVar9 < 8) {
    uVar9 = uVar9 + 8;
    if (0x20 < uVar9) {
      SZ_GetSpace(buf,4);
      if (((bfwrite.pbuf)->flags & 2) != 0) {
        return;
      }
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
      puVar3 = bfwrite.pOutByte;
      bfwrite.nCurOutputBit = uVar9 & 7;
      bfwrite.pOutByte = bfwrite.pOutByte + 4;
      puVar3[4] = '\0';
      puVar3[5] = '\0';
      puVar3[6] = '\0';
      puVar3[7] = '\0';
      return;
    }
    iVar6 = 0;
    uVar10 = uVar9 >> 3;
    uVar9 = uVar9 & 7;
    if (uVar9 != 0) goto LAB_000a21a4;
  }
  else {
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
    iVar6 = 1;
    uVar10 = 1;
    bfwrite.nCurOutputBit = 0;
  }
                    /* Unresolved local var: int length@[???] */
  uVar10 = uVar10 - 1;
  uVar9 = 0;
LAB_000a21a4:
  SZ_GetSpace(buf,iVar6 + uVar10);
  if (((bfwrite.pbuf)->flags & 2) == 0) {
    *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
    if (uVar9 == 0) {
      uVar9 = 8;
    }
    bfwrite.pOutByte = bfwrite.pOutByte + uVar10;
    bfwrite.nCurOutputBit = uVar9;
  }
  return;
code_r0x000a210a:
  p = p + 1;
  *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
  *(uint *)bfwrite.pOutByte =
       *(uint *)bfwrite.pOutByte | (uint)bVar1 << ((byte)bfwrite.nCurOutputBit & 0x1f);
  bVar7 = 0x20 - (byte)bfwrite.nCurOutputBit;
  puVar3 = bfwrite.pOutByte;
  bfwrite.nCurOutputBit = local_20 & 7;
  bfwrite.pOutByte = bfwrite.pOutByte + 4;
  puVar3[4] = '\0';
  puVar3[5] = '\0';
  puVar3[6] = '\0';
  puVar3[7] = '\0';
  *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte | (uint)(bVar1 >> (bVar7 & 0x1f));
  bVar1 = *p;
  uVar9 = bfwrite.nCurOutputBit;
  buf = bfwrite.pbuf;
  goto joined_r0x000a1f8c;
}


// MSG_WriteBitVec3Coord  @ 000a24d0
/* WARNING: Removing unreachable block (ram,0x000a2b50) */
/* WARNING: Removing unreachable block (ram,0x000a2bd0) */
/* WARNING: Removing unreachable block (ram,0x000a2be0) */
/* WARNING: Removing unreachable block (ram,0x000a2a20) */
/* WARNING: Removing unreachable block (ram,0x000a28fc) */
/* WARNING: Removing unreachable block (ram,0x000a27ba) */

void MSG_WriteBitVec3Coord(vec_t *fa)

{
  int iVar1;
  uint32 *puVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint32 uVar11;
  
                    /* Unresolved local var: int xflag@[???]
                       Unresolved local var: int yflag@[???]
                       Unresolved local var: int zflag@[???] */
  bVar4 = 0.125 <= *fa;
  bVar5 = *fa <= -0.125;
  bVar7 = 0.125 <= fa[1] || fa[1] <= -0.125;
  bVar6 = 0.125 <= fa[2] || fa[2] <= -0.125;
  if (bfwrite.nCurOutputBit < 8) {
    if (((bfwrite.pbuf)->flags & 2) != 0) goto LAB_000a2643;
    iVar1 = bfwrite.nCurOutputBit + 1;
    iVar9 = bfwrite.nCurOutputBit;
    bfwrite.nCurOutputBit = iVar1;
    if (bVar4 || bVar5) goto LAB_000a2a8b;
LAB_000a259f:
    *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)INVBITTABLE[iVar9];
LAB_000a25b3:
    if (bfwrite.nCurOutputBit < 8) goto LAB_000a25bc;
    SZ_GetSpace(bfwrite.pbuf,1);
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
    bfwrite.nCurOutputBit = 0;
    uVar8 = *(uint *)&(bfwrite.pbuf)->flags;
  }
  else {
    SZ_GetSpace(bfwrite.pbuf,1);
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      iVar9 = 0;
      bfwrite.nCurOutputBit = 1;
      if (!bVar4 && !bVar5) goto LAB_000a259f;
LAB_000a2a8b:
      *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)BITTABLE[iVar9];
      goto LAB_000a25b3;
    }
LAB_000a25bc:
    uVar8 = *(uint *)&(bfwrite.pbuf)->flags;
  }
  if ((uVar8 & 2) == 0) {
    if (bVar7) {
      puVar2 = BITTABLE + bfwrite.nCurOutputBit;
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar2;
    }
    else {
      puVar2 = INVBITTABLE + bfwrite.nCurOutputBit;
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar2;
    }
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
      bfwrite.nCurOutputBit = 0;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (bVar6) {
        puVar2 = BITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar2;
      }
      else {
        puVar2 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar2;
      }
    }
  }
LAB_000a2643:
  if (bVar4 || bVar5) {
    fVar3 = *fa;
                    /* Unresolved local var: int signbit@[???]
                       Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???] */
    uVar10 = (uint)fVar3;
    uVar8 = (int)uVar10 >> 0x1f;
    uVar11 = (uVar8 ^ uVar10) - uVar8;
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (uVar11 == 0) {
        puVar2 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar2;
      }
      else {
        puVar2 = BITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar2;
      }
      if (7 < bfwrite.nCurOutputBit) {
        SZ_GetSpace(bfwrite.pbuf,1);
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
        bfwrite.nCurOutputBit = 0;
      }
      if (((bfwrite.pbuf)->flags & 2) == 0) {
        puVar2 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar2;
      }
    }
    if ((uVar11 != 0) && (MSG_WriteOneBit((uint)(fVar3 <= -0.125)), uVar11 != 0)) {
      MSG_WriteBits(uVar11,0xc);
    }
  }
  if (bVar7) {
    fVar3 = fa[1];
                    /* Unresolved local var: int signbit@[???]
                       Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???] */
    uVar8 = (uint)fVar3;
    uVar10 = (int)uVar8 >> 0x1f;
    uVar11 = (uVar10 ^ uVar8) - uVar10;
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (uVar11 == 0) {
        puVar2 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar2;
      }
      else {
        puVar2 = BITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar2;
      }
      if (7 < bfwrite.nCurOutputBit) {
        SZ_GetSpace(bfwrite.pbuf,1);
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
        bfwrite.nCurOutputBit = 0;
      }
      if (((bfwrite.pbuf)->flags & 2) == 0) {
        puVar2 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar2;
      }
    }
    if ((uVar11 != 0) && (MSG_WriteOneBit((uint)(fVar3 <= -0.125)), uVar11 != 0)) {
      MSG_WriteBits(uVar11,0xc);
    }
  }
  if (bVar6) {
    fVar3 = fa[2];
                    /* Unresolved local var: int signbit@[???]
                       Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???] */
    uVar8 = (uint)fVar3;
    uVar10 = (int)uVar8 >> 0x1f;
    uVar11 = (uVar10 ^ uVar8) - uVar10;
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (uVar11 == 0) {
        puVar2 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar2;
      }
      else {
        puVar2 = BITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar2;
      }
      if (7 < bfwrite.nCurOutputBit) {
        SZ_GetSpace(bfwrite.pbuf,1);
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
        bfwrite.nCurOutputBit = 0;
      }
      if (((bfwrite.pbuf)->flags & 2) == 0) {
        puVar2 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar2;
      }
    }
    if (uVar11 != 0) {
      if (7 < bfwrite.nCurOutputBit) {
        SZ_GetSpace(bfwrite.pbuf,1);
        bfwrite.nCurOutputBit = 0;
        bfwrite.pOutByte = bfwrite.pOutByte + 1;
      }
      if (((bfwrite.pbuf)->flags & 2) == 0) {
        if (fVar3 <= -0.125) {
          puVar2 = BITTABLE + bfwrite.nCurOutputBit;
          bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
          *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar2;
        }
        else {
          puVar2 = INVBITTABLE + bfwrite.nCurOutputBit;
          bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
          *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar2;
        }
      }
      if (uVar11 != 0) {
        MSG_WriteBits(uVar11,0xc);
      }
    }
  }
  return;
}


// MSG_WriteBits  @ 000a18c0
void MSG_WriteBits(uint32 data,int numbits)

{
  bool bVar1;
  uchar *puVar2;
  sizebuf_t *psVar3;
  sizebuf_t *psVar4;
  int iVar5;
  char *pcVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
                    /* Unresolved local var: uint32 d@[???]
                       Unresolved local var: uint32 reserveBytes@[???] */
  psVar3 = bfwrite.pbuf;
  if ((numbits < 0x20) && ((uint)(1 << ((byte)numbits & 0x1f)) <= data)) {
    data = ROWBITTABLE[numbits];
  }
  bVar1 = bfwrite.nCurOutputBit < 8;
  if (bVar1) {
    numbits = numbits + bfwrite.nCurOutputBit;
    iVar8 = 4;
  }
  else {
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
    bfwrite.nCurOutputBit = 0;
    iVar8 = 5;
  }
  if ((uint)numbits < 0x21) {
                    /* Unresolved local var: int length@[???] */
    uVar9 = numbits & 7;
    iVar10 = ((uint)numbits >> 3) - (uint)(uVar9 == 0);
    iVar11 = (uint)!bVar1 + iVar10;
                    /* Unresolved local var: void * data@[???] */
    iVar8 = (bfwrite.pbuf)->maxsize;
    iVar5 = (bfwrite.pbuf)->cursize + iVar11;
    if (iVar8 < iVar5) {
      if (((bfwrite.pbuf)->flags & 1) == 0) {
        pcVar6 = (bfwrite.pbuf)->buffername;
        if (pcVar6 == (char *)0x0) {
          pcVar6 = "???";
        }
        if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar6);
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar6);
      }
      if (iVar8 < iVar11) {
        pcVar6 = (bfwrite.pbuf)->buffername;
        if (pcVar6 == (char *)0x0) {
          pcVar6 = "???";
        }
        Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",iVar11,pcVar6);
      }
      pcVar6 = psVar3->buffername;
      if (pcVar6 == (char *)0x0) {
        pcVar6 = "???";
      }
      Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar6);
      psVar3->flags = (ushort)*(undefined4 *)&psVar3->flags | 2;
      iVar5 = iVar11;
    }
    psVar4 = bfwrite.pbuf;
    psVar3->cursize = iVar5;
    if ((psVar4->flags & 2) == 0) {
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
      *(uint *)bfwrite.pOutByte =
           *(uint *)bfwrite.pOutByte | data << ((byte)bfwrite.nCurOutputBit & 0x1f);
      if (uVar9 == 0) {
        uVar9 = 8;
      }
      bfwrite.pOutByte = bfwrite.pOutByte + iVar10;
      bfwrite.nCurOutputBit = uVar9;
    }
  }
  else {
    SZ_GetSpace(bfwrite.pbuf,iVar8);
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
      *(uint *)bfwrite.pOutByte =
           *(uint *)bfwrite.pOutByte | data << ((byte)bfwrite.nCurOutputBit & 0x1f);
      bVar7 = 0x20 - (byte)bfwrite.nCurOutputBit;
      puVar2 = bfwrite.pOutByte;
      bfwrite.nCurOutputBit = numbits & 7;
      bfwrite.pOutByte = bfwrite.pOutByte + 4;
      puVar2[4] = '\0';
      puVar2[5] = '\0';
      puVar2[6] = '\0';
      puVar2[7] = '\0';
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte | data >> (bVar7 & 0x1f);
    }
  }
  return;
}


// MSG_WriteBuf  @ 0009f150
void MSG_WriteBuf(sizebuf_t *sb,int iSize,void *buf)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  if (buf != (void *)0x0) {
                    /* Unresolved local var: byte * pData@[???]
                       Unresolved local var: void * data@[???] */
    iVar3 = sb->cursize;
    iVar4 = sb->maxsize;
    iVar6 = iSize + iVar3;
    if (iVar4 < iVar6) {
      if ((sb->flags & 1) == 0) {
        pcVar5 = sb->buffername;
        if (iVar4 == 0) {
          if (pcVar5 == (char *)0x0) {
            pcVar5 = "???";
          }
                    /* WARNING: Subroutine does not return */
          Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar5);
        }
        if (pcVar5 == (char *)0x0) {
          pcVar5 = "???";
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar5);
      }
      if (iVar4 < iSize) {
        pcVar5 = sb->buffername;
        if (pcVar5 == (char *)0x0) {
          pcVar5 = "???";
        }
        Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",iSize,pcVar5);
      }
      pcVar5 = sb->buffername;
      if (pcVar5 == (char *)0x0) {
        pcVar5 = "???";
      }
      Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar5);
      sb->cursize = iSize;
      sb->flags = (ushort)*(undefined4 *)&sb->flags | 2;
    }
    else {
      sb->cursize = iVar6;
      if ((sb->flags & 2) == 0) {
        pbVar7 = sb->data + iVar3;
        if (7 < (uint)iSize) {
          pbVar8 = pbVar7;
          if (((uint)pbVar7 & 1) != 0) {
            bVar1 = *(byte *)buf;
            pbVar8 = pbVar7 + 1;
            buf = (void *)((int)buf + 1);
            iSize = iSize + -1;
            *pbVar7 = bVar1;
          }
          pbVar7 = pbVar8;
          if (((uint)pbVar8 & 2) != 0) {
            uVar2 = *(undefined2 *)buf;
            pbVar7 = pbVar8 + 2;
            buf = (void *)((int)buf + 2);
            iSize = iSize + -2;
            *(undefined2 *)pbVar8 = uVar2;
          }
          if (((uint)pbVar7 & 4) != 0) {
            *(undefined4 *)pbVar7 = *(undefined4 *)buf;
            pbVar8 = (byte *)((int)buf + 4);
            pbVar7 = pbVar7 + 4;
            for (iVar6 = iSize + -4; iVar6 != 0; iVar6 = iVar6 + -1) {
              *pbVar7 = *pbVar8;
              pbVar8 = pbVar8 + 1;
              pbVar7 = pbVar7 + 1;
            }
            return;
          }
        }
        for (; iSize != 0; iSize = iSize + -1) {
          *pbVar7 = *(byte *)buf;
          buf = (byte *)((int)buf + 1);
          pbVar7 = pbVar7 + 1;
        }
      }
    }
  }
  return;
}


// MSG_WriteByte  @ 0009ebb0
void MSG_WriteByte(sizebuf_t *sb,int c)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: byte * buf@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: void * data@[???] */
  iVar2 = sb->cursize;
  iVar3 = sb->maxsize;
  if (iVar2 < iVar3) {
    iVar3 = iVar2 + 1;
  }
  else {
    if ((sb->flags & 1) == 0) {
      pcVar1 = sb->buffername;
      if (iVar3 != 0) {
        if (pcVar1 == (char *)0x0) {
          pcVar1 = "???";
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar1);
      }
      if (pcVar1 == (char *)0x0) {
        pcVar1 = "???";
      }
                    /* WARNING: Subroutine does not return */
      Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar1);
    }
    if (iVar3 < 1) {
      pcVar1 = sb->buffername;
      if (pcVar1 == (char *)0x0) {
        pcVar1 = "???";
      }
      Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",1,pcVar1);
    }
    pcVar1 = sb->buffername;
    if (pcVar1 == (char *)0x0) {
      pcVar1 = "???";
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar1);
    iVar3 = 1;
    sb->flags = (ushort)*(undefined4 *)&sb->flags | 2;
    iVar2 = 0;
  }
  sb->cursize = iVar3;
  sb->data[iVar2] = (byte)c;
  return;
}


// MSG_WriteChar  @ 0009ea90
void MSG_WriteChar(undefined4 *param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[4];
  iVar3 = param_1[3];
  if (iVar2 < iVar3) {
    iVar3 = iVar2 + 1;
  }
  else {
    if ((*(byte *)(param_1 + 1) & 1) == 0) {
      puVar1 = (undefined1 *)*param_1;
      if (iVar3 != 0) {
        if (puVar1 == (undefined1 *)0x0) {
          puVar1 = &LAB_00255a78;
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",puVar1);
      }
      if (puVar1 == (undefined1 *)0x0) {
        puVar1 = &LAB_00255a78;
      }
                    /* WARNING: Subroutine does not return */
      Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",puVar1);
    }
    if (iVar3 < 1) {
      puVar1 = (undefined1 *)*param_1;
      if (puVar1 == (undefined1 *)0x0) {
        puVar1 = &LAB_00255a78;
      }
      Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",1,puVar1);
    }
    puVar1 = (undefined1 *)*param_1;
    if (puVar1 == (undefined1 *)0x0) {
      puVar1 = &LAB_00255a78;
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",puVar1);
    iVar3 = 1;
    *(ushort *)(param_1 + 1) = (ushort)param_1[1] | 2;
    iVar2 = 0;
  }
  param_1[4] = iVar3;
  *(undefined1 *)(iVar2 + param_1[2]) = param_2;
  return;
}


// MSG_WriteCoord  @ 000a0ba0
void MSG_WriteCoord(sizebuf_t *sb,float f)

{
  int iVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: byte * buf@[DW_OP_reg0(EAX)]
                       Unresolved local var: void * data@[???] */
  iVar4 = sb->cursize;
  iVar1 = sb->maxsize;
  iVar5 = iVar4 + 2;
  if (iVar1 < iVar5) {
    if ((sb->flags & 1) == 0) {
      pcVar3 = sb->buffername;
      if (pcVar3 == (char *)0x0) {
        pcVar3 = "???";
      }
      if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar3);
      }
                    /* WARNING: Subroutine does not return */
      Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar3);
    }
    if (iVar1 < 2) {
      pcVar3 = sb->buffername;
      if (pcVar3 == (char *)0x0) {
        pcVar3 = "???";
      }
      Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",2,pcVar3);
    }
    pcVar3 = sb->buffername;
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "???";
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar3);
    iVar5 = 2;
    sb->flags = (ushort)*(undefined4 *)&sb->flags | 2;
    iVar4 = 0;
  }
  pbVar2 = sb->data;
  sb->cursize = iVar5;
  pbVar2[iVar4] = (byte)(int)(f * 8.0);
  (pbVar2 + iVar4)[1] = (byte)((uint)(int)(f * 8.0) >> 8);
  return;
}


// MSG_WriteFloat  @ 0009f010
void MSG_WriteFloat(sizebuf_t *sb,float f)

{
  int iVar1;
  int32 iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: anon_union_4_2_947300a7 dat@[???] */
  iVar2 = (*LittleLong)((int32)f);
                    /* Unresolved local var: byte * pData@[???]
                       Unresolved local var: void * data@[???] */
  iVar6 = sb->cursize;
  iVar5 = iVar6 + 4;
  iVar1 = sb->maxsize;
  if (iVar1 < iVar5) {
    if ((sb->flags & 1) == 0) {
      pcVar3 = sb->buffername;
      if (iVar1 != 0) {
        if (pcVar3 == (char *)0x0) {
          pcVar3 = "???";
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar3);
      }
      if (pcVar3 == (char *)0x0) {
        pcVar3 = "???";
      }
                    /* WARNING: Subroutine does not return */
      Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar3);
    }
    if (iVar1 < 4) {
      pcVar3 = sb->buffername;
      if (pcVar3 == (char *)0x0) {
        pcVar3 = "???";
      }
      Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",4,pcVar3);
    }
    pcVar3 = sb->buffername;
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "???";
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar3);
    iVar5 = 4;
    iVar6 = 0;
    uVar4 = *(uint *)&sb->flags & 0xffff | 2;
    sb->flags = (ushort)uVar4;
  }
  else {
    uVar4 = (uint)sb->flags;
  }
  sb->cursize = iVar5;
  if ((uVar4 & 2) == 0) {
    *(int32 *)(sb->data + iVar6) = iVar2;
  }
  return;
}


// MSG_WriteHiresAngle  @ 0009f460
void MSG_WriteHiresAngle(sizebuf_t *sb,float f)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  double dVar6;
  
  dVar6 = fmod((double)f,360.0);
                    /* Unresolved local var: byte * buf@[DW_OP_reg0(EAX)]
                       Unresolved local var: void * data@[???] */
  iVar3 = sb->cursize;
  iVar1 = sb->maxsize;
  iVar4 = iVar3 + 2;
  uVar5 = (int)(((float)dVar6 * 65536.0) / 360.0) & 0xffff;
  if (iVar1 < iVar4) {
    if ((sb->flags & 1) == 0) {
      if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s");
      }
                    /* WARNING: Subroutine does not return */
      Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s");
    }
    if (iVar1 < 2) {
      Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring");
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n");
    iVar4 = 2;
    sb->flags = (ushort)*(undefined4 *)&sb->flags | 2;
    iVar3 = 0;
  }
  pbVar2 = sb->data;
  sb->cursize = iVar4;
  pbVar2[iVar3] = (byte)uVar5;
  (pbVar2 + iVar3)[1] = (byte)(uVar5 >> 8);
  return;
}


// MSG_WriteLong  @ 0009eef0
void MSG_WriteLong(sizebuf_t *sb,int c)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  
                    /* Unresolved local var: byte * buf@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: void * data@[???] */
  iVar3 = sb->cursize;
  iVar1 = sb->maxsize;
  iVar5 = iVar3 + 4;
  if (iVar1 < iVar5) {
    if ((sb->flags & 1) == 0) {
      pcVar2 = sb->buffername;
      if (pcVar2 == (char *)0x0) {
        pcVar2 = "???";
      }
      if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar2);
      }
                    /* WARNING: Subroutine does not return */
      Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar2);
    }
    if (iVar1 < 4) {
      pcVar2 = sb->buffername;
      if (pcVar2 == (char *)0x0) {
        pcVar2 = "???";
      }
      Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",4,pcVar2);
    }
    pcVar2 = sb->buffername;
    if (pcVar2 == (char *)0x0) {
      pcVar2 = "???";
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar2);
    iVar5 = 4;
    sb->flags = (ushort)*(undefined4 *)&sb->flags | 2;
    iVar3 = 0;
  }
  sb->cursize = iVar5;
  pbVar4 = sb->data + iVar3;
  pbVar4[1] = (byte)((uint)c >> 8);
  *pbVar4 = (byte)c;
  pbVar4[2] = (byte)((uint)c >> 0x10);
  pbVar4[3] = (byte)((uint)c >> 0x18);
  return;
}


// MSG_WriteOneBit  @ 0009f780
void MSG_WriteOneBit(int nValue)

{
  uint32 *puVar1;
  sizebuf_t *psVar2;
  char *pcVar3;
  int iVar4;
  sizebuf_t *psVar5;
  
  psVar2 = bfwrite.pbuf;
  psVar5 = bfwrite.pbuf;
  if (7 < bfwrite.nCurOutputBit) {
                    /* Unresolved local var: void * data@[???] */
    iVar4 = (bfwrite.pbuf)->maxsize;
    if ((bfwrite.pbuf)->cursize < iVar4) {
      iVar4 = (bfwrite.pbuf)->cursize + 1;
    }
    else {
      if (((bfwrite.pbuf)->flags & 1) == 0) {
        pcVar3 = (bfwrite.pbuf)->buffername;
        if (iVar4 == 0) {
          if (pcVar3 == (char *)0x0) {
            pcVar3 = "???";
          }
                    /* WARNING: Subroutine does not return */
          Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar3);
        }
        if (pcVar3 == (char *)0x0) {
          pcVar3 = "???";
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar3);
      }
      if (iVar4 < 1) {
        pcVar3 = (bfwrite.pbuf)->buffername;
        if (pcVar3 == (char *)0x0) {
          pcVar3 = "???";
        }
        Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",1,pcVar3);
      }
      pcVar3 = psVar2->buffername;
      if (pcVar3 == (char *)0x0) {
        pcVar3 = "???";
      }
      Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar3);
      psVar2->flags = (ushort)*(undefined4 *)&psVar2->flags | 2;
      iVar4 = 1;
    }
    psVar5 = bfwrite.pbuf;
    psVar2->cursize = iVar4;
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
  }
  if ((psVar5->flags & 2) == 0) {
    if (nValue != 0) {
      puVar1 = BITTABLE + bfwrite.nCurOutputBit;
      bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
      *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar1;
      return;
    }
    puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
    bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
    *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
  }
  return;
}


// MSG_WriteSBits  @ 000a3510
void MSG_WriteSBits(int data,int numbits)

{
  uint32 *puVar1;
  bool bVar2;
  uchar *puVar3;
  sizebuf_t *psVar4;
  sizebuf_t *psVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint32 uVar14;
  
                    /* Unresolved local var: uint32 uidata@[???] */
  uVar11 = data;
                    /* Unresolved local var: int sigbits@[???]
                       Unresolved local var: int maxnum@[???] */
  if (((numbits < 0x20) &&
      (uVar12 = (1 << ((char)numbits - 1U & 0x1f)) - 1, uVar11 = uVar12, data <= (int)uVar12)) &&
     (uVar11 = data, data < (int)-uVar12)) {
    uVar11 = -uVar12;
  }
  if ((int)uVar11 < 0) {
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
  psVar4 = bfwrite.pbuf;
  uVar12 = numbits - 1;
  uVar14 = (uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f);
                    /* Unresolved local var: uint32 d@[???]
                       Unresolved local var: uint32 reserveBytes@[???] */
  if (((int)uVar12 < 0x20) && ((uint)(1 << ((byte)uVar12 & 0x1f)) <= uVar14)) {
    uVar14 = ROWBITTABLE[uVar12];
  }
  bVar2 = bfwrite.nCurOutputBit < 8;
  if (bVar2) {
    uVar12 = uVar12 + bfwrite.nCurOutputBit;
    iVar8 = 4;
  }
  else {
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
    bfwrite.nCurOutputBit = 0;
    iVar8 = 5;
  }
  if (uVar12 < 0x21) {
                    /* Unresolved local var: int length@[???] */
    uVar11 = uVar12 & 7;
                    /* Unresolved local var: void * data@[???] */
    iVar6 = (uVar12 >> 3) - (uint)(uVar11 == 0);
    iVar13 = (uint)!bVar2 + iVar6;
    iVar8 = (bfwrite.pbuf)->maxsize;
    iVar9 = (bfwrite.pbuf)->cursize + iVar13;
    if (iVar8 < iVar9) {
      if (((bfwrite.pbuf)->flags & 1) == 0) {
        pcVar10 = (bfwrite.pbuf)->buffername;
        if (pcVar10 == (char *)0x0) {
          pcVar10 = "???";
        }
        if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar10);
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar10);
      }
      if (iVar8 < iVar13) {
        pcVar10 = (bfwrite.pbuf)->buffername;
        if (pcVar10 == (char *)0x0) {
          pcVar10 = "???";
        }
        Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",iVar13,pcVar10);
      }
      pcVar10 = psVar4->buffername;
      if (pcVar10 == (char *)0x0) {
        pcVar10 = "???";
      }
      Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar10);
      psVar4->flags = (ushort)*(undefined4 *)&psVar4->flags | 2;
      iVar9 = iVar13;
    }
    psVar5 = bfwrite.pbuf;
    psVar4->cursize = iVar9;
    if ((psVar5->flags & 2) == 0) {
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
      *(uint *)bfwrite.pOutByte =
           *(uint *)bfwrite.pOutByte | uVar14 << ((byte)bfwrite.nCurOutputBit & 0x1f);
      if (uVar11 == 0) {
        uVar11 = 8;
      }
      bfwrite.pOutByte = bfwrite.pOutByte + iVar6;
      bfwrite.nCurOutputBit = uVar11;
    }
  }
  else {
    SZ_GetSpace(bfwrite.pbuf,iVar8);
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte & ROWBITTABLE[bfwrite.nCurOutputBit];
      *(uint *)bfwrite.pOutByte =
           *(uint *)bfwrite.pOutByte | uVar14 << ((byte)bfwrite.nCurOutputBit & 0x1f);
      bVar7 = 0x20 - (byte)bfwrite.nCurOutputBit;
      puVar3 = bfwrite.pOutByte;
      bfwrite.nCurOutputBit = uVar12 & 7;
      bfwrite.pOutByte = bfwrite.pOutByte + 4;
      puVar3[4] = '\0';
      puVar3[5] = '\0';
      puVar3[6] = '\0';
      puVar3[7] = '\0';
      *(uint *)bfwrite.pOutByte = *(uint *)bfwrite.pOutByte | uVar14 >> (bVar7 & 0x1f);
      return;
    }
  }
  return;
}


// MSG_WriteShort  @ 0009ecd0
void MSG_WriteShort(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1[4];
  iVar1 = param_1[3];
  iVar4 = iVar3 + 2;
  if (iVar1 < iVar4) {
    if ((*(byte *)(param_1 + 1) & 1) == 0) {
      puVar2 = (undefined1 *)*param_1;
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &LAB_00255a78;
      }
      if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",puVar2);
      }
                    /* WARNING: Subroutine does not return */
      Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",puVar2);
    }
    if (iVar1 < 2) {
      puVar2 = (undefined1 *)*param_1;
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &LAB_00255a78;
      }
      Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",2,puVar2);
    }
    puVar2 = (undefined1 *)*param_1;
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &LAB_00255a78;
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",puVar2);
    iVar4 = 2;
    *(ushort *)(param_1 + 1) = (ushort)param_1[1] | 2;
    iVar3 = 0;
  }
  iVar1 = param_1[2];
  param_1[4] = iVar4;
  *(undefined1 *)(iVar3 + iVar1) = (char)param_2;
  ((undefined1 *)(iVar3 + iVar1))[1] = (char)((uint)param_2 >> 8);
  return;
}


// MSG_WriteString  @ 000a1b30
void MSG_WriteString(sizebuf_t *sb,char *s)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  if (s == (char *)0x0) {
                    /* Unresolved local var: byte * pData@[???] */
    puVar5 = SZ_GetSpace(sb,1);
    if ((sb->flags & 2) == 0) {
      *puVar5 = 0;
    }
    return;
  }
                    /* Unresolved local var: int count@[???] */
  uVar8 = 1;
  iVar7 = 0;
  if (*s != '\0') {
    do {
      iVar6 = iVar7;
      iVar7 = iVar6 + 1;
    } while (s[iVar7] != '\0');
    uVar8 = iVar6 + 2;
  }
                    /* Unresolved local var: byte * pData@[???]
                       Unresolved local var: void * data@[???] */
  iVar6 = sb->cursize;
  iVar3 = sb->maxsize;
  iVar7 = iVar6 + uVar8;
  if (iVar7 <= iVar3) {
    sb->cursize = iVar7;
    if ((sb->flags & 2) != 0) {
      return;
    }
    pbVar9 = sb->data + iVar6;
    if (7 < uVar8) {
      pbVar10 = pbVar9;
      if (((uint)pbVar9 & 1) != 0) {
        bVar1 = *s;
        pbVar10 = pbVar9 + 1;
        s = s + 1;
        uVar8 = uVar8 - 1;
        *pbVar9 = bVar1;
      }
      pbVar9 = pbVar10;
      if (((uint)pbVar10 & 2) != 0) {
        uVar2 = *(undefined2 *)s;
        pbVar9 = pbVar10 + 2;
        s = s + 2;
        uVar8 = uVar8 - 2;
        *(undefined2 *)pbVar10 = uVar2;
      }
      if (((uint)pbVar9 & 4) != 0) {
        *(undefined4 *)pbVar9 = *(undefined4 *)s;
        pbVar10 = (byte *)(s + 4);
        pbVar9 = pbVar9 + 4;
        for (iVar7 = uVar8 - 4; iVar7 != 0; iVar7 = iVar7 + -1) {
          *pbVar9 = *pbVar10;
          pbVar10 = pbVar10 + 1;
          pbVar9 = pbVar9 + 1;
        }
        return;
      }
    }
    for (; uVar8 != 0; uVar8 = uVar8 - 1) {
      *pbVar9 = *s;
      s = s + 1;
      pbVar9 = pbVar9 + 1;
    }
    return;
  }
  if ((sb->flags & 1) != 0) {
    if (iVar3 < (int)uVar8) {
      pcVar4 = sb->buffername;
      if (pcVar4 == (char *)0x0) {
        pcVar4 = "???";
      }
      Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",uVar8,pcVar4);
    }
    pcVar4 = sb->buffername;
    if (pcVar4 == (char *)0x0) {
      pcVar4 = "???";
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar4);
    sb->cursize = uVar8;
    sb->flags = (ushort)*(undefined4 *)&sb->flags | 2;
    return;
  }
  pcVar4 = sb->buffername;
  if (iVar3 == 0) {
    if (pcVar4 == (char *)0x0) {
      pcVar4 = "???";
    }
                    /* WARNING: Subroutine does not return */
    Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar4);
  }
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "???";
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar4);
}


// MSG_WriteUsercmd  @ 0009f5b0
void MSG_WriteUsercmd(sizebuf_t *buf,usercmd_t *to,usercmd_t *from)

{
  sizebuf_t *psVar1;
  delta_t **ppdVar2;
  char *pcVar3;
  int iVar4;
  
                    /* Unresolved local var: delta_t * * ppdesc@[???] */
  ppdVar2 = DELTA_LookupRegistration("usercmd_t");
  bfwrite.nCurOutputBit = 0;
  bfwrite.pbuf = buf;
  bfwrite.pOutByte = buf->data + buf->cursize;
  DELTA_WriteDelta((uchar *)from,(uchar *)to,true,*ppdVar2,(_func_void *)0x0);
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
  if (((bfwrite.pbuf)->flags & 2) != 0) {
    return;
  }
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
  *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)(0xff >> (8U - (char)bfwrite.nCurOutputBit & 0x1f));
  psVar1 = bfwrite.pbuf;
                    /* Unresolved local var: void * data@[???] */
  iVar4 = (bfwrite.pbuf)->maxsize;
  if ((bfwrite.pbuf)->cursize < iVar4) {
    iVar4 = (bfwrite.pbuf)->cursize + 1;
  }
  else {
    if (((bfwrite.pbuf)->flags & 1) == 0) {
      pcVar3 = (bfwrite.pbuf)->buffername;
      if (iVar4 == 0) {
        if (pcVar3 == (char *)0x0) {
          pcVar3 = "???";
        }
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar3);
      }
      if (pcVar3 == (char *)0x0) {
        pcVar3 = "???";
      }
                    /* WARNING: Subroutine does not return */
      Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar3);
    }
    if (iVar4 < 1) {
      pcVar3 = (bfwrite.pbuf)->buffername;
      if (pcVar3 == (char *)0x0) {
        pcVar3 = "???";
      }
      Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",1,pcVar3);
    }
    pcVar3 = psVar1->buffername;
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "???";
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar3);
    psVar1->flags = (ushort)*(undefined4 *)&psVar1->flags | 2;
    iVar4 = 1;
  }
  psVar1->cursize = iVar4;
  bfwrite.nCurOutputBit = 0;
  bfwrite.pOutByte = (uchar *)0x0;
  bfwrite.pbuf = (sizebuf_t *)0x0;
  return;
}


// MSG_WriteVec3Coord  @ 000a2ca0
/* WARNING: Removing unreachable block (ram,0x000a3410) */
/* WARNING: Removing unreachable block (ram,0x000a3450) */
/* WARNING: Removing unreachable block (ram,0x000a3420) */
/* WARNING: Removing unreachable block (ram,0x000a3282) */
/* WARNING: Removing unreachable block (ram,0x000a315b) */
/* WARNING: Removing unreachable block (ram,0x000a304a) */

void MSG_WriteVec3Coord(sizebuf_t *sb,float *fa)

{
  uint32 *puVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint32 uVar9;
  
  if (bfwrite.pbuf == (sizebuf_t *)0x0) {
    bfwrite.pbuf = sb;
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = sb->data + sb->cursize;
    MSG_WriteBitVec3Coord(fa);
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
    if (((bfwrite.pbuf)->flags & 2) != 0) {
      return;
    }
                    /* Unresolved local var: int nPadBitsNeeded@[???]
                       Unresolved local var: uchar cmask@[???]
                       Unresolved local var: int nBytesAdded@[???] */
    *bfwrite.pOutByte =
         *bfwrite.pOutByte & (byte)(0xff >> (8U - (char)bfwrite.nCurOutputBit & 0x1f));
    SZ_GetSpace(bfwrite.pbuf,1);
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = (uchar *)0x0;
    bfwrite.pbuf = (sizebuf_t *)0x0;
    return;
  }
                    /* Unresolved local var: int xflag@[???]
                       Unresolved local var: int yflag@[???]
                       Unresolved local var: int zflag@[???] */
  fVar2 = *fa;
  bVar4 = 0.125 <= fa[1] || fa[1] <= -0.125;
  bVar3 = true;
  if (fa[2] < 0.125) {
    bVar3 = fa[2] <= -0.125;
    if (7 < bfwrite.nCurOutputBit) goto LAB_000a2e4e;
LAB_000a2d1e:
    if (((bfwrite.pbuf)->flags & 2) != 0) goto LAB_000a2de3;
    iVar5 = bfwrite.nCurOutputBit + 1;
    iVar6 = bfwrite.nCurOutputBit;
joined_r0x000a2d39:
    bfwrite.nCurOutputBit = iVar5;
    if (0.125 <= fVar2 || fVar2 <= -0.125) {
      *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)BITTABLE[iVar6];
    }
    else {
      *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)INVBITTABLE[iVar6];
    }
    if (bfwrite.nCurOutputBit < 8) goto LAB_000a2d5c;
    SZ_GetSpace(bfwrite.pbuf,1);
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
    bfwrite.nCurOutputBit = 0;
    uVar7 = *(uint *)&(bfwrite.pbuf)->flags;
  }
  else {
    if (bfwrite.nCurOutputBit < 8) goto LAB_000a2d1e;
LAB_000a2e4e:
    SZ_GetSpace(bfwrite.pbuf,1);
    bfwrite.nCurOutputBit = 0;
    bfwrite.pOutByte = bfwrite.pOutByte + 1;
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      iVar6 = 0;
      bfwrite.nCurOutputBit = 1;
      iVar5 = bfwrite.nCurOutputBit;
      goto joined_r0x000a2d39;
    }
LAB_000a2d5c:
    uVar7 = *(uint *)&(bfwrite.pbuf)->flags;
  }
  if ((uVar7 & 2) == 0) {
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
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
      bfwrite.nCurOutputBit = 0;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (bVar3) {
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
LAB_000a2de3:
  if (0.125 <= fVar2 || fVar2 <= -0.125) {
    fVar2 = *fa;
                    /* Unresolved local var: int signbit@[???]
                       Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???] */
    uVar7 = (uint)fVar2;
    uVar8 = (int)uVar7 >> 0x1f;
    uVar9 = (uVar8 ^ uVar7) - uVar8;
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (uVar9 == 0) {
        puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
      }
      else {
        puVar1 = BITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar1;
      }
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
    if ((uVar9 != 0) && (MSG_WriteOneBit((uint)(fVar2 <= -0.125)), uVar9 != 0)) {
      MSG_WriteBits(uVar9,0xc);
    }
  }
  if (bVar4) {
    fVar2 = fa[1];
                    /* Unresolved local var: int signbit@[???]
                       Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???] */
    uVar7 = (uint)fVar2;
    uVar8 = (int)uVar7 >> 0x1f;
    uVar9 = (uVar8 ^ uVar7) - uVar8;
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (uVar9 == 0) {
        puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
      }
      else {
        puVar1 = BITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar1;
      }
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
    if ((uVar9 != 0) && (MSG_WriteOneBit((uint)(fVar2 <= -0.125)), uVar9 != 0)) {
      MSG_WriteBits(uVar9,0xc);
    }
  }
  if (bVar3) {
    fVar2 = fa[2];
                    /* Unresolved local var: int signbit@[???]
                       Unresolved local var: int intval@[???]
                       Unresolved local var: int fractval@[???] */
    uVar7 = (uint)fVar2;
    uVar8 = (int)uVar7 >> 0x1f;
    uVar9 = (uVar8 ^ uVar7) - uVar8;
    if (7 < bfwrite.nCurOutputBit) {
      SZ_GetSpace(bfwrite.pbuf,1);
      bfwrite.nCurOutputBit = 0;
      bfwrite.pOutByte = bfwrite.pOutByte + 1;
    }
    if (((bfwrite.pbuf)->flags & 2) == 0) {
      if (uVar9 == 0) {
        puVar1 = INVBITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte & (byte)*puVar1;
      }
      else {
        puVar1 = BITTABLE + bfwrite.nCurOutputBit;
        bfwrite.nCurOutputBit = bfwrite.nCurOutputBit + 1;
        *bfwrite.pOutByte = *bfwrite.pOutByte | (byte)*puVar1;
      }
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
    if (uVar9 != 0) {
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
      if (uVar9 != 0) {
        MSG_WriteBits(uVar9,0xc);
      }
    }
  }
  return;
}


// MSG_WriteWord  @ 0009ede0
void MSG_WriteWord(sizebuf_t *sb,int c)

{
  int iVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: byte * buf@[DW_OP_reg0(EAX)] */
                    /* Unresolved local var: void * data@[???] */
  iVar4 = sb->cursize;
  iVar1 = sb->maxsize;
  iVar5 = iVar4 + 2;
  if (iVar1 < iVar5) {
    if ((sb->flags & 1) == 0) {
      pcVar3 = sb->buffername;
      if (pcVar3 == (char *)0x0) {
        pcVar3 = "???";
      }
      if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("SZ_GetSpace: overflow without FSB_ALLOWOVERFLOW set on %s",pcVar3);
      }
                    /* WARNING: Subroutine does not return */
      Sys_Error("SZ_GetSpace:  Tried to write to an uninitialized sizebuf_t: %s",pcVar3);
    }
    if (iVar1 < 2) {
      pcVar3 = sb->buffername;
      if (pcVar3 == (char *)0x0) {
        pcVar3 = "???";
      }
      Con_DPrintf("SZ_GetSpace: %i is > full buffer size on %s, ignoring",2,pcVar3);
    }
    pcVar3 = sb->buffername;
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "???";
    }
    Con_Printf("SZ_GetSpace: overflow on %s\n",pcVar3);
    iVar5 = 2;
    sb->flags = (ushort)*(undefined4 *)&sb->flags | 2;
    iVar4 = 0;
  }
  pbVar2 = sb->data;
  sb->cursize = iVar5;
  pbVar2[iVar4] = (byte)c;
  (pbVar2 + iVar4)[1] = (byte)((uint)c >> 8);
  return;
}


