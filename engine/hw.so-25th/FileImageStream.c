// FileImageStream_Memory::ErrorStatus  @ 001d6870
/* DWARF original prototype: bool ErrorStatus(FileImageStream_Memory * this) */

bool __thiscall FileImageStream_Memory::ErrorStatus(FileImageStream_Memory *this)

{
  bool bVar1;
  
                    /* Unresolved local var: bool ret@[DW_OP_reg0(EAX)] */
  bVar1 = this->m_bError;
  this->m_bError = false;
  return bVar1;
}


// FileImageStream_Memory::FileImageStream_Memory  @ 001d6ed0
/* DWARF original prototype: void FileImageStream_Memory(FileImageStream_Memory * this, void *
   pData, int dataLen) */

void __thiscall
FileImageStream_Memory::FileImageStream_Memory(FileImageStream_Memory *this,void *pData,int dataLen)

{
  (this->super_FileImageStream)._vptr_FileImageStream = (_func_int_varargs **)&PTR_Read_002722bc;
  this->m_pData = pData;
  this->m_CurPos = 0;
  this->m_bError = false;
  this->m_DataLen = dataLen;
  return;
}


// FileImageStream_Memory::Read  @ 001d6820
/* DWARF original prototype: void Read(FileImageStream_Memory * this, void * pData, int len) */

void __thiscall FileImageStream_Memory::Read(FileImageStream_Memory *this,void *pData,int len)

{
  uchar *puVar1;
  uchar *puVar2;
  
                    /* Unresolved local var: uchar * pOut@[???]
                       Unresolved local var: int i@[???] */
  puVar2 = pData;
  if (0 < len) {
    do {
      while (this->m_CurPos < this->m_DataLen) {
        puVar1 = puVar2 + 1;
        *puVar2 = this->m_pData[this->m_CurPos];
        this->m_CurPos = this->m_CurPos + 1;
        puVar2 = puVar1;
        if ((uchar *)((int)pData + len) == puVar1) {
          return;
        }
      }
      *puVar2 = '\0';
      puVar2 = puVar2 + 1;
      this->m_bError = true;
    } while ((uchar *)((int)pData + len) != puVar2);
  }
  return;
}


