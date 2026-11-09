// Ghidra decompilation of functions from game_shared/vgui_loadtga.cpp
// 9 functions, ordered by original source line

// MemoryInputStream::seekStart  @ 000a9310  (line 27)

/* DWARF original prototype: void seekStart(MemoryInputStream * this, bool * success) */

void __thiscall MemoryInputStream::seekStart(MemoryInputStream *this,bool *success)

{
  this->m_ReadPos = 0;
  *success = true;
  return;
}


// MemoryInputStream::seekRelative  @ 000a9330  (line 28)

/* DWARF original prototype: void seekRelative(MemoryInputStream * this, int count, bool * success)
    */

void __thiscall MemoryInputStream::seekRelative(MemoryInputStream *this,int count,bool *success)

{
  this->m_ReadPos = this->m_ReadPos + count;
  *success = true;
  return;
}


// MemoryInputStream::seekEnd  @ 000a9350  (line 29)

/* DWARF original prototype: void seekEnd(MemoryInputStream * this, bool * success) */

void __thiscall MemoryInputStream::seekEnd(MemoryInputStream *this,bool *success)

{
  this->m_ReadPos = this->m_DataLen;
  *success = true;
  return;
}


// MemoryInputStream::getAvailable  @ 000a9370  (line 30)

/* DWARF original prototype: int getAvailable(MemoryInputStream * this, bool * success) */

int __thiscall MemoryInputStream::getAvailable(MemoryInputStream *this,bool *success)

{
  *success = false;
  return 0;
}


// MemoryInputStream::readUChar  @ 000a9380  (line 32)

/* DWARF original prototype: uchar readUChar(MemoryInputStream * this, bool * success) */

uchar __thiscall MemoryInputStream::readUChar(MemoryInputStream *this,bool *success)

{
  uchar uVar1;
  
  if ((-1 < this->m_ReadPos) && (this->m_ReadPos < this->m_DataLen)) {
                    /* Unresolved local var: uchar ret@[DW_OP_reg0(EAX)] */
    *success = true;
    uVar1 = this->m_pData[this->m_ReadPos];
    this->m_ReadPos = this->m_ReadPos + 1;
    return uVar1;
  }
  *success = false;
  return '\0';
}


// MemoryInputStream::readUChar  @ 000a93e0  (line 48)

/* DWARF original prototype: void readUChar(MemoryInputStream * this, uchar * buf, int count, bool *
   success) */

void __thiscall
MemoryInputStream::readUChar(MemoryInputStream *this,uchar *buf,int count,bool *success)

{
  _func_int_varargs *p_Var1;
  uchar uVar2;
  int iVar3;
  uchar *puVar4;
  uchar *puVar5;
  
                    /* Unresolved local var: int i@[???] */
  puVar4 = buf;
  if (count < 1) {
    return;
  }
  do {
    while (p_Var1 = (this->super_InputStream)._vptr_InputStream[4], p_Var1 != readUChar) {
      iVar3 = (*p_Var1)(this,success);
      uVar2 = (uchar)iVar3;
LAB_000a9406:
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
      if (puVar4 == buf + count) {
        return;
      }
    }
    if ((this->m_ReadPos < 0) || (this->m_DataLen <= this->m_ReadPos)) {
      *success = false;
      uVar2 = '\0';
      goto LAB_000a9406;
    }
                    /* Unresolved local var: uchar ret@[???] */
    *success = true;
    puVar5 = puVar4 + 1;
    uVar2 = this->m_pData[this->m_ReadPos];
    this->m_ReadPos = this->m_ReadPos + 1;
    *puVar4 = uVar2;
    puVar4 = puVar5;
    if (puVar5 == buf + count) {
      return;
    }
  } while( true );
}


// MemoryInputStream::close  @ 000a93c0  (line 54)

/* DWARF original prototype: void close(MemoryInputStream * this, bool * success) */

void __thiscall MemoryInputStream::close(MemoryInputStream *this,bool *success)

{
  this->m_pData = (uchar *)0x0;
  this->m_ReadPos = 0;
  this->m_DataLen = 0;
  return;
}


// vgui_LoadTGA  @ 000a91c0  (line 66)

BitmapTGA * vgui_LoadTGA(char *pFilename)

{
  BitmapTGA *this;
  InputStream local_1c;
  byte *local_18;
  int local_14 [3];
  
                    /* Unresolved local var: MemoryInputStream stream@[???]
                       Unresolved local var: BitmapTGA * pRet@[???] */
  local_14[0] = 0;
  local_1c._vptr_InputStream = (_func_int_varargs **)&PTR_seekStart_000cb828;
  local_18 = (byte *)0x0;
  local_14[1] = 0;
  local_18 = (*gEngfuncs.COM_LoadFile)(pFilename,5,local_14);
  if (local_18 == (byte *)0x0) {
    this = (BitmapTGA *)0x0;
  }
  else {
    local_14[1] = 0;
    this = operator_new(0x30);
    vgui::BitmapTGA::BitmapTGA(this,&local_1c,true);
    (*gEngfuncs.COM_FreeFile)(local_18);
  }
  return this;
}


// vgui_LoadTGANoInvertAlpha  @ 000a9270  (line 81)

BitmapTGA * vgui_LoadTGANoInvertAlpha(char *pFilename)

{
  BitmapTGA *this;
  InputStream local_1c;
  byte *local_18;
  int local_14 [3];
  
                    /* Unresolved local var: MemoryInputStream stream@[???]
                       Unresolved local var: BitmapTGA * pRet@[???] */
  local_14[0] = 0;
  local_1c._vptr_InputStream = (_func_int_varargs **)&PTR_seekStart_000cb828;
  local_18 = (byte *)0x0;
  local_14[1] = 0;
  local_18 = (*gEngfuncs.COM_LoadFile)(pFilename,5,local_14);
  if (local_18 == (byte *)0x0) {
    this = (BitmapTGA *)0x0;
  }
  else {
    local_14[1] = 0;
    this = operator_new(0x30);
    vgui::BitmapTGA::BitmapTGA(this,&local_1c,false);
    (*gEngfuncs.COM_FreeFile)(local_18);
  }
  return this;
}


