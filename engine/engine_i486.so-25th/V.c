// V_Init  @ 000b3110
void V_Init(void)

{
  return;
}


// V_UTF8ToUChar32  @ 000c24e0
qboolean V_UTF8ToUChar32(char *pUTF8_,uchar32 *uValueOut)

{
  uint uVar1;
  char *pcVar2;
  qboolean qVar3;
  int iVar4;
  char *pcVar5;
  
                    /* Unresolved local var: bool bError@[???] */
                    /* Unresolved local var: uint8 * pUTF8@[???]
                       Unresolved local var: int nBytes@[???]
                       Unresolved local var: uint32 uValue@[???]
                       Unresolved local var: uint32 uMinValue@[???] */
  pcVar2 = (char *)(uint)(byte)*pUTF8_;
  if (pcVar2 < (char *)0x80) {
LAB_000c25e0:
    qVar3 = 0;
  }
  else {
    if ((pcVar2 + -0xc0 < (char *)0x38) && ((pUTF8_[1] & 0xc0U) == 0x80)) {
      pcVar2 = (char *)((int)pcVar2 * 0x40 + -0x3080 + (uint)(byte)pUTF8_[1]);
      if (((uint)pcVar2 & 0x800) == 0) {
        pcVar5 = (char *)0x80;
        goto LAB_000c2655;
      }
      if ((pUTF8_[2] & 0xc0U) == 0x80) {
        iVar4 = (uint)(byte)pUTF8_[2] + (int)pcVar2 * 0x40;
        pcVar2 = (char *)(iVar4 - 0x20080);
        if (((uint)pcVar2 & 0x10000) == 0) {
          uVar1 = iVar4 - 0x2d880;
          pcVar5 = (char *)0x800;
          if ((((0x3ff < uVar1) || (pUTF8_[3] != -0x13)) || (0xf < (byte)(pUTF8_[4] + 0x50U))) ||
             ((pUTF8_[5] & 0xc0U) != 0x80)) goto LAB_000c2655;
          pcVar2 = (char *)((uint)(byte)(pUTF8_[4] + 0x50U) * 0x40 + 0xff80 + (uint)(byte)pUTF8_[5]
                           + uVar1 * 0x400);
LAB_000c25a0:
          if ((((char *)0x7ff < pcVar2 + -0xd800) &&
              (pcVar2 < Netchan_OutOfBandPrint::string + 0xf20)) &&
             (((ushort)pcVar2 < 0xfffe && ((char *)0x1f < pcVar2 + -0xfdd0)))) goto LAB_000c25e0;
        }
        else if ((pUTF8_[3] & 0xc0U) == 0x80) {
          pcVar5 = "\x7fELF\x01\x01\x01";
          pcVar2 = (char *)((int)pcVar2 * 0x40 + -0x400080 + (uint)(byte)pUTF8_[3]);
LAB_000c2655:
          if (pcVar5 <= pcVar2) goto LAB_000c25a0;
        }
      }
    }
    qVar3 = 1;
    pcVar2 = (char *)0x3f;
  }
  *uValueOut = (uchar32)pcVar2;
  return qVar3;
}


