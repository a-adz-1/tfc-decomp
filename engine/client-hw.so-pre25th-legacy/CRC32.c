// CRC32_Final  @ 00110d50
CRC32_t CRC32_Final(CRC32_t pulCRC)

{
  return ~pulCRC;
}


// CRC32_Init  @ 00110d40
void CRC32_Init(CRC32_t *pulCRC)

{
  *pulCRC = 0xffffffff;
  return;
}


// CRC32_ProcessBuffer  @ 00110d80
void CRC32_ProcessBuffer(CRC32_t *pulCRC,void *pBuffer,int nBuffer)

{
  uint uVar1;
  int iVar2;
  
  do {
    if ((uint)nBuffer < 8) {
                    /* WARNING: Could not recover jumptable at 0x00110e70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&PTR_LAB_0027c740)[nBuffer])();
      return;
    }
    uVar1 = (uint)pBuffer & 3;
    if (uVar1 == 2) {
LAB_00110f64:
      pBuffer = (void *)((int)pBuffer + 1);
LAB_00110f78:
      pBuffer = (void *)((int)pBuffer + 1);
    }
    else {
      if (uVar1 == 3) {
        pBuffer = (void *)((int)pBuffer + 1);
        goto LAB_00110f64;
      }
      if (uVar1 == 1) goto LAB_00110f78;
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


// CRC32_ProcessByte  @ 00110d60
void CRC32_ProcessByte(CRC32_t *pulCRC,uchar ch)

{
                    /* Unresolved local var: CRC32_t ulCrc@[???] */
  *pulCRC = *pulCRC >> 8 ^ pulCRCTable[((uint)ch ^ *pulCRC) & 0xff];
  return;
}


