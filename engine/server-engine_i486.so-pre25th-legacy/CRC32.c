// CRC32_Final  @ 00066a10
CRC32_t CRC32_Final(CRC32_t pulCRC)

{
  return ~pulCRC;
}


// CRC32_Init  @ 00066a00
void CRC32_Init(CRC32_t *pulCRC)

{
  *pulCRC = 0xffffffff;
  return;
}


// CRC32_ProcessBuffer  @ 00066a40
void CRC32_ProcessBuffer(CRC32_t *pulCRC,void *pBuffer,int nBuffer)

{
  uint uVar1;
  int iVar2;
  
  do {
    if ((uint)nBuffer < 8) {
                    /* WARNING: Could not recover jumptable at 0x00066b30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&PTR_LAB_000e19c0)[nBuffer])();
      return;
    }
    uVar1 = (uint)pBuffer & 3;
    if (uVar1 == 2) {
LAB_00066c24:
      pBuffer = (void *)((int)pBuffer + 1);
LAB_00066c38:
      pBuffer = (void *)((int)pBuffer + 1);
    }
    else {
      if (uVar1 == 3) {
        pBuffer = (void *)((int)pBuffer + 1);
        goto LAB_00066c24;
      }
      if (uVar1 == 1) goto LAB_00066c38;
    }
    iVar2 = (int)(nBuffer - uVar1) >> 3;
    if (iVar2 != 0) {
      iVar2 = iVar2 + -1;
      do {
        iVar2 = iVar2 + -1;
      } while (iVar2 != -1);
    }
    nBuffer = nBuffer - uVar1 & 7;
  } while( true );
}


// CRC32_ProcessByte  @ 00066a20
void CRC32_ProcessByte(CRC32_t *pulCRC,uchar ch)

{
                    /* Unresolved local var: CRC32_t ulCrc@[???] */
  *pulCRC = *pulCRC >> 8 ^ pulCRCTable[((uint)ch ^ *pulCRC) & 0xff];
  return;
}


