// CHudBattery::MsgFunc_Battery  @ 0008bd60
/* DWARF original prototype: int MsgFunc_Battery(CHudBattery * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudBattery::MsgFunc_Battery(CHudBattery *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = &(this->super_CHudBase).m_iFlags;
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  *piVar1 = *piVar1 | 1;
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_SHORT();
  iVar3 = READ_SHORT();
  if ((this->m_iBat != iVar2) || (this->m_iBatMax != iVar3)) {
    this->m_fFade = 100.0;
    this->m_iBat = iVar2;
    this->m_iBatMax = iVar3;
  }
  return 1;
}


