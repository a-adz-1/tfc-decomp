// CRC32_Final  @ 000a7f00
CRC32_t CRC32_Final(CRC32_t pulCRC)

{
  return ~pulCRC;
}


// CRC32_Init  @ 000a7ef0
void CRC32_Init(CRC32_t *pulCRC)

{
  *pulCRC = 0xffffffff;
  return;
}


// CRC32_ProcessBuffer  @ 000a7f30
void CRC32_ProcessBuffer(CRC32_t *pulCRC,void *pBuffer,int nBuffer)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  
                    /* Unresolved local var: CRC32_t ulCrc@[???]
                       Unresolved local var: uchar * pb@[???]
                       Unresolved local var: uint nFront@[???]
                       Unresolved local var: int nMain@[???] */
  uVar3 = *pulCRC;
LAB_000a7f43:
  bVar1 = (byte)uVar3;
  puVar5 = pBuffer;
  switch(nBuffer) {
  case 0:
    goto switchD_000a7f4c_caseD_0;
  case 3:
    puVar5 = (uint *)((int)pBuffer + 1);
    uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)(bVar1 ^ (byte)*(uint *)pBuffer)];
  case 2:
    pBuffer = (void *)((int)puVar5 + 1);
    uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)*puVar5)];
  case 1:
    uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)*(uint *)pBuffer)];
    goto switchD_000a7f4c_caseD_0;
  case 4:
    break;
  case 7:
    puVar5 = (uint *)((int)pBuffer + 1);
    uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)(bVar1 ^ (byte)*(uint *)pBuffer)];
  case 6:
    pBuffer = (void *)((int)puVar5 + 1);
    uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)*puVar5)];
  case 5:
    uVar6 = *(uint *)pBuffer;
    pBuffer = (void *)((int)pBuffer + 1);
    uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)uVar6)];
    break;
  default:
    uVar6 = (uint)pBuffer & 3;
    puVar5 = pBuffer;
    if (uVar6 == 2) {
LAB_000a811d:
      pBuffer = (void *)((int)puVar5 + 1);
      uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)*puVar5)];
LAB_000a8132:
      uVar2 = *(uint *)pBuffer;
      pBuffer = (void *)((int)pBuffer + 1);
      uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)uVar2)];
    }
    else {
      if (uVar6 == 3) {
        puVar5 = (uint *)((int)pBuffer + 1);
        uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)(bVar1 ^ (byte)*(uint *)pBuffer)];
        goto LAB_000a811d;
      }
      if (uVar6 == 1) goto LAB_000a8132;
    }
    iVar4 = (int)(nBuffer - uVar6) >> 3;
    if (iVar4 != 0) {
      puVar5 = (uint *)((int)pBuffer + iVar4 * 2 * 4);
      puVar7 = pBuffer;
      do {
        puVar8 = puVar7 + 2;
        uVar3 = (uVar3 ^ *puVar7) >> 8 ^ pulCRCTable[(uVar3 ^ *puVar7) & 0xff];
        uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
        uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
        uVar3 = uVar3 >> 8 ^ puVar7[1] ^ pulCRCTable[uVar3 & 0xff];
        uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
        uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
        uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
        uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
        pBuffer = puVar5;
        puVar7 = puVar8;
      } while (puVar8 != puVar5);
    }
    nBuffer = nBuffer - uVar6 & 7;
    goto LAB_000a7f43;
  }
  uVar3 = (uVar3 ^ *(uint *)pBuffer) >> 8 ^ pulCRCTable[(uVar3 ^ *(uint *)pBuffer) & 0xff];
  uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
  uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
  *pulCRC = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
  return;
switchD_000a7f4c_caseD_0:
  *pulCRC = uVar3;
  return;
}


// CRC32_ProcessByte  @ 000a7f10
void CRC32_ProcessByte(CRC32_t *pulCRC,uchar ch)

{
                    /* Unresolved local var: CRC32_t ulCrc@[???] */
  *pulCRC = *pulCRC >> 8 ^ pulCRCTable[((uint)ch ^ *pulCRC) & 0xff];
  return;
}


