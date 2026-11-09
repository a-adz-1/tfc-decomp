// CHudStatusBar::MsgFunc_StatusText  @ 0009fa80
/* DWARF original prototype: int MsgFunc_StatusText(CHudStatusBar * this, char * pszName, int iSize,
   void * pbuf) */

int __thiscall
CHudStatusBar::MsgFunc_StatusText(CHudStatusBar *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  uint uVar2;
  char *__src;
  
                    /* Unresolved local var: int line@[???] */
  BEGIN_READ(pbuf,iSize);
  uVar2 = READ_BYTE();
  if (uVar2 < 4) {
    __src = READ_STRING();
    strncpy(this->m_szStatusText[uVar2],__src,0x80);
    this->m_szStatusText[uVar2][0x7f] = '\0';
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 | 1;
    this->m_bReparseString = 1;
  }
  return 1;
}


// CHudStatusBar::MsgFunc_StatusValue  @ 0009fb00
/* DWARF original prototype: int MsgFunc_StatusValue(CHudStatusBar * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
CHudStatusBar::MsgFunc_StatusValue(CHudStatusBar *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int index@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  if (iVar1 - 1U < 8) {
    iVar2 = READ_SHORT();
    this->m_iStatusValues[iVar1] = iVar2;
    this->m_bReparseString = 1;
  }
  return 1;
}


