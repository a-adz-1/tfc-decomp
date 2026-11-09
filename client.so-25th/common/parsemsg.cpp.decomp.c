// Ghidra decompilation of functions from common/parsemsg.cpp
// 19 functions, ordered by original source line

// READ_OK  @ 000a6a30  (line 32)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int READ_OK(void)

{
  return (uint)(giBadRead == 0);
}


// BEGIN_READ  @ 000a6a40  (line 37)

void BEGIN_READ(void *buf,int size)

{
  giRead = 0;
  giBadRead = 0;
  giSize = size;
  gpBuf = buf;
  return;
}


// READ_CHAR  @ 000a6a70  (line 48)

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


// READ_ANGLE  @ 000a6cf0  (line 48)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float READ_ANGLE(void)

{
  byte *pbVar1;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead < giSize) {
    pbVar1 = gpBuf + giRead;
    giRead = giRead + 1;
    return (float)(short)(char)*pbVar1 * 1.40625;
  }
  giBadRead = 1;
                    /* catch() { ... } // from try @ 000a6d97 with catch @ 000a6d40
                       catch() { ... } // from try @ 000a6e1f with catch @ 000a6d40
                       catch() { ... } // from try @ 000a7385 with catch @ 000a6d40
                       catch() { ... } // from try @ 000a740d with catch @ 000a6d40
                       catch() { ... } // from try @ 000a7867 with catch @ 000a6d40
                       catch() { ... } // from try @ 000a78fb with catch @ 000a6d40
                       catch() { ... } // from try @ 000a7ae7 with catch @ 000a6d40
                       catch() { ... } // from try @ 000a7ccc with catch @ 000a6d40
                       catch() { ... } // from try @ 000a7d60 with catch @ 000a6d40 */
  return -1.40625;
}


// READ_BYTE  @ 000a6aa0  (line 64)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int READ_BYTE(void)

{
  byte *pbVar1;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead < giSize) {
    pbVar1 = gpBuf + giRead;
                    /* try { // try from 000a6abb to 000b6abf has its CatchHandler @ 000a6b08 */
    giRead = giRead + 1;
    return (uint)*pbVar1;
  }
  giBadRead = 1;
  return -1;
}


// READ_SHORT  @ 000a6ad0  (line 67)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* READ_SHORT() */

int READ_SHORT(void)

{
  byte *pbVar1;
  int iVar2;
  
  if (giRead + 1 < giSize) {
    iVar2 = giRead + 1;
                    /* try { // try from 000a6ae1 to 000b6b90 has its CatchHandler @ 000a45f0 */
    pbVar1 = gpBuf + giRead;
    giRead = giRead + 2;
    return (int)CONCAT11(gpBuf[iVar2],*pbVar1);
  }
  giBadRead = 1;
  return -1;
}


// READ_WORD  @ 000a6b10  (line 80)

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


// READ_COORD  @ 000a6c80  (line 80)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float READ_COORD(void)

{
  byte *pbVar1;
  int iVar2;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead + 1 < giSize) {
    iVar2 = giRead + 1;
    pbVar1 = gpBuf + giRead;
    giRead = giRead + 2;
    return (float)CONCAT11(gpBuf[iVar2],*pbVar1) * 0.125;
  }
  giBadRead = 1;
  return -0.125;
}


// READ_HIRESANGLE  @ 000a6d50  (line 80)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float READ_HIRESANGLE(void)

{
  byte *pbVar1;
  int iVar2;
  
                    /* Unresolved local var: int c@[???] */
  if (giRead + 1 < giSize) {
    iVar2 = giRead + 1;
    pbVar1 = gpBuf + giRead;
    giRead = giRead + 2;
    return (float)CONCAT11(gpBuf[iVar2],*pbVar1) * 0.005493164;
  }
  giBadRead = 1;
  return -0.005493164;
}


// READ_LONG  @ 000a6b50  (line 103)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int READ_LONG(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int c@[???] */
                    /* catch() { ... } // from try @ 000a62a3 with catch @ 000a6b55 */
  if (giRead + 3 < giSize) {
    iVar2 = giRead + 1;
    pbVar1 = gpBuf + giRead;
    iVar3 = giRead + 2;
    iVar4 = giRead + 3;
    giRead = giRead + 4;
    return (uint)gpBuf[iVar3] * 0x10000 + (uint)gpBuf[iVar2] * 0x100 + (uint)*pbVar1 +
           (uint)gpBuf[iVar4] * 0x1000000;
  }
  giBadRead = 1;
  return -1;
}


// READ_FLOAT  @ 000a6bc0  (line 117)

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


// READ_STRING  @ 000a6c00  (line 137)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * READ_STRING(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  
  pbVar4 = gpBuf;
  iVar3 = giSize;
                    /* Unresolved local var: int l@[???]
                       Unresolved local var: int c@[???] */
  iVar2 = giRead;
                    /* try { // try from 000a6c02 to 000b6c06 has its CatchHandler @ 000a6d0f */
  bVar1 = false;
  iVar5 = 0;
  READ_STRING::string[0] = '\0';
  iVar6 = giRead;
  do {
    if (iVar3 <= iVar6) {
      if (!bVar1) {
        READ_STRING::string[iVar5] = '\0';
        return READ_STRING::string;
      }
      break;
    }
                    /* try { // try from 000a6c28 to 000b6c55 has its CatchHandler @ 000a45f0 */
    iVar6 = iVar6 + 1;
    if ((int)(char)pbVar4[iVar5 + iVar2] + 1U < 2) break;
    READ_STRING::string[iVar5] = pbVar4[iVar5 + iVar2];
    iVar5 = iVar5 + 1;
    bVar1 = true;
  } while (iVar5 != 0x7ff);
  READ_STRING::string[iVar5] = '\0';
  giRead = iVar6;
  return READ_STRING::string;
}


// BufferWriter::BufferWriter  @ 000a6dc0  (line 177)

/* DWARF original prototype: void BufferWriter(BufferWriter * this) */

void __thiscall BufferWriter::BufferWriter(BufferWriter *this)

{
  this->m_overflow = false;
  this->m_buffer = (uchar *)0x0;
  this->m_remaining = 0;
  this->m_overallLength = 0;
  return;
}


// BufferWriter::BufferWriter  @ 000a6de0  (line 183)

/* DWARF original prototype: void BufferWriter(BufferWriter * this, uchar * buffer, int bufferLen)
    */

void __thiscall BufferWriter::BufferWriter(BufferWriter *this,uchar *buffer,int bufferLen)

{
  this->m_overflow = false;
  this->m_remaining = bufferLen;
  this->m_buffer = buffer;
  this->m_overallLength = bufferLen;
  return;
}


// BufferWriter::Init  @ 000a6e00  (line 190)

/* DWARF original prototype: void Init(BufferWriter * this, uchar * buffer, int bufferLen) */

void __thiscall BufferWriter::Init(BufferWriter *this,uchar *buffer,int bufferLen)

{
  this->m_overflow = false;
  this->m_remaining = bufferLen;
  this->m_buffer = buffer;
  this->m_overallLength = bufferLen;
  return;
}


// BufferWriter::WriteByte  @ 000a6e20  (line 199)

/* DWARF original prototype: void WriteByte(BufferWriter * this, uchar data) */

void __thiscall BufferWriter::WriteByte(BufferWriter *this,uchar data)

{
  if ((this->m_buffer != (uchar *)0x0) && (this->m_remaining != 0)) {
    *this->m_buffer = data;
    this->m_buffer = this->m_buffer + 1;
    this->m_remaining = this->m_remaining + -1;
    return;
  }
  this->m_overflow = true;
  return;
}


// BufferWriter::WriteLong  @ 000a6e50  (line 213)

/* DWARF original prototype: void WriteLong(BufferWriter * this, int data) */

void __thiscall BufferWriter::WriteLong(BufferWriter *this,int data)

{
  if ((this->m_buffer != (uchar *)0x0) && (3 < this->m_remaining)) {
    *this->m_buffer = (uchar)data;
    this->m_buffer[1] = (uchar)((uint)data >> 8);
    this->m_buffer[2] = (uchar)((uint)data >> 0x10);
    this->m_buffer[3] = (uchar)((uint)data >> 0x18);
    this->m_buffer = this->m_buffer + 4;
    this->m_remaining = this->m_remaining + -4;
    return;
  }
  this->m_overflow = true;
  return;
}


// BufferWriter::WriteString  @ 000a6ea0  (line 230)

/* DWARF original prototype: void WriteString(BufferWriter * this, char * str) */

void __thiscall BufferWriter::WriteString(BufferWriter *this,char *str)

{
  uchar *__dest;
  int iVar1;
  size_t sVar2;
  int iVar3;
  
                    /* Unresolved local var: int len@[???] */
  __dest = this->m_buffer;
  if ((__dest == (uchar *)0x0) || (iVar1 = this->m_remaining, iVar1 == 0)) {
    this->m_overflow = true;
  }
  else {
    if (str == (char *)0x0) {
      iVar3 = 1;
      str = "";
    }
    else {
      sVar2 = strlen(str);
      iVar3 = sVar2 + 1;
    }
    if (iVar1 < iVar3) {
      this->m_overflow = true;
      iVar3 = 1;
      str = "";
    }
    strcpy((char *)__dest,str);
    this->m_remaining = this->m_remaining - iVar3;
    this->m_buffer = this->m_buffer + iVar3;
  }
  return;
}


// BufferWriter::GetSpaceUsed  @ 000a6f50  (line 255)

/* DWARF original prototype: int GetSpaceUsed(BufferWriter * this) */

int __thiscall BufferWriter::GetSpaceUsed(BufferWriter *this)

{
  return this->m_overallLength - this->m_remaining;
}


