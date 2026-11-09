// READ_ANGLE  @ 000cb550
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float READ_ANGLE(void)

{
  byte *pbVar1;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead < giSize) {
    pbVar1 = gpBuf + giRead;
    giRead = giRead + 1;
    return (float)(int)(char)*pbVar1 * 1.40625;
  }
  giBadRead = 1;
  return -1.40625;
}


// READ_BYTE  @ 000cb300
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int READ_BYTE(void)

{
  byte *pbVar1;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead < giSize) {
    pbVar1 = gpBuf + giRead;
    giRead = giRead + 1;
    return (uint)*pbVar1;
  }
  giBadRead = 1;
  return -1;
}


// READ_CHAR  @ 000cb2d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int READ_CHAR(void)

{
  byte *pbVar1;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead < giSize) {
    pbVar1 = gpBuf + giRead;
    giRead = giRead + 1;
    return (int)(char)*pbVar1;
  }
  giBadRead = 1;
  return -1;
}


// READ_COORD  @ 000cb4e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float READ_COORD(void)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead + 1 < giSize) {
    iVar3 = giRead + 1;
    pbVar1 = gpBuf + giRead;
    giRead = giRead + 2;
    fVar2 = (float)(short)((ushort)gpBuf[iVar3] * 0x100 + (ushort)*pbVar1) * 0.125;
  }
  else {
    fVar2 = -0.125;
    giBadRead = 1;
  }
  return fVar2;
}


// READ_FLOAT  @ 000cb410
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float READ_FLOAT(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = giRead + 1;
                    /* Unresolved local var: anon_union_4_3_4e909c68 dat@[???] */
  pbVar1 = gpBuf + giRead;
  iVar3 = giRead + 2;
  iVar4 = giRead + 3;
  giRead = giRead + 4;
  return (float)CONCAT13(gpBuf[iVar4],CONCAT12(gpBuf[iVar3],CONCAT11(gpBuf[iVar2],*pbVar1)));
}


// READ_HIRESANGLE  @ 000cb5b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float READ_HIRESANGLE(void)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead + 1 < giSize) {
    iVar3 = giRead + 1;
    pbVar1 = gpBuf + giRead;
    giRead = giRead + 2;
    fVar2 = (float)(short)((ushort)gpBuf[iVar3] * 0x100 + (ushort)*pbVar1) * 0.005493164;
  }
  else {
    fVar2 = -0.005493164;
    giBadRead = 1;
  }
  return fVar2;
}


// READ_LONG  @ 000cb3b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int READ_LONG(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead + 3 < giSize) {
    iVar2 = giRead + 1;
    pbVar1 = gpBuf + giRead;
    iVar3 = giRead + 2;
    iVar4 = giRead + 3;
    giRead = giRead + 4;
    return CONCAT13(gpBuf[iVar4],CONCAT12(gpBuf[iVar3],CONCAT11(gpBuf[iVar2],*pbVar1)));
  }
  giBadRead = 1;
  return -1;
}


// READ_OK  @ 000cb290
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int READ_OK(void)

{
  return (uint)(giBadRead == 0);
}


// READ_SHORT  @ 000cb330
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int READ_SHORT(void)

{
  byte *pbVar1;
  int iVar2;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead + 1 < giSize) {
    iVar2 = giRead + 1;
    pbVar1 = gpBuf + giRead;
    giRead = giRead + 2;
    return (int)CONCAT11(gpBuf[iVar2],*pbVar1);
  }
  giBadRead = 1;
  return -1;
}


// READ_STRING  @ 000cb460
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * READ_STRING(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  pbVar2 = gpBuf;
  iVar1 = giSize;
                    /* Unresolved local var: int l@[???]
                       Unresolved local var: int c@[???] */
  iVar4 = 0;
  READ_STRING::lexical_block_0::string[0] = '\0';
  iVar3 = giRead;
  do {
    if (iVar1 <= iVar3) {
      giRead = iVar3;
      READ_STRING::lexical_block_0::string[iVar4] = '\0';
      return READ_STRING::lexical_block_0::string;
    }
    iVar3 = iVar3 + 1;
    if ((int)(char)pbVar2[iVar4 + giRead] + 1U < 2) break;
    READ_STRING::lexical_block_0::string[iVar4] = pbVar2[iVar4 + giRead];
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x7ff);
  giRead = iVar3;
  READ_STRING::lexical_block_0::string[iVar4] = '\0';
  return READ_STRING::lexical_block_0::string;
}


// READ_WORD  @ 000cb370
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int READ_WORD(void)

{
  byte *pbVar1;
  int iVar2;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead + 1 < giSize) {
    iVar2 = giRead + 1;
    pbVar1 = gpBuf + giRead;
    giRead = giRead + 2;
    return (int)CONCAT11(gpBuf[iVar2],*pbVar1);
  }
  giBadRead = 1;
  return -1;
}


