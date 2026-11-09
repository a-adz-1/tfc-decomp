// FileImageStream_Memory::ErrorStatus  @ 00220c60
/* DWARF original prototype: bool ErrorStatus(FileImageStream_Memory * this) */

bool __thiscall FileImageStream_Memory::ErrorStatus(FileImageStream_Memory *this)

{
  bool bVar1;
  
                    /* Unresolved local var: bool ret@[???] */
  bVar1 = this->m_bError;
  this->m_bError = false;
  return bVar1;
}


// FileImageStream_Memory::FileImageStream_Memory  @ 00221600
/* DWARF original prototype: void FileImageStream_Memory(FileImageStream_Memory * this, void *
   pData, int dataLen) */

void __thiscall
FileImageStream_Memory::FileImageStream_Memory(FileImageStream_Memory *this,void *pData,int dataLen)

{
  (this->super_FileImageStream)._vptr_FileImageStream = (_func_int_varargs **)&PTR_Read_00296d40;
  this->m_pData = pData;
  this->m_CurPos = 0;
  this->m_bError = false;
  this->m_DataLen = dataLen;
  return;
}


// FileImageStream_Memory::Read  @ 00220c10
/* DWARF original prototype: void Read(FileImageStream_Memory * this, void * pData, int len) */

void __thiscall FileImageStream_Memory::Read(FileImageStream_Memory *this,void *pData,int len)

{
  int iVar1;
  
                    /* Unresolved local var: uchar * pOut@[???]
                       Unresolved local var: int i@[???] */
  if (0 < len) {
    iVar1 = 0;
    do {
      while (this->m_DataLen <= this->m_CurPos) {
        *(undefined1 *)((int)pData + iVar1) = 0;
        iVar1 = iVar1 + 1;
        this->m_bError = true;
        if (iVar1 == len) {
          return;
        }
      }
      *(uchar *)((int)pData + iVar1) = this->m_pData[this->m_CurPos];
      iVar1 = iVar1 + 1;
      this->m_CurPos = this->m_CurPos + 1;
    } while (iVar1 != len);
  }
  return;
}


