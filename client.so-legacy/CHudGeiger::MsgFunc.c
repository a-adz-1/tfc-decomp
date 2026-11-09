// CHudGeiger::MsgFunc_Geiger  @ 0008f840
/* DWARF original prototype: int MsgFunc_Geiger(CHudGeiger * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHudGeiger::MsgFunc_Geiger(CHudGeiger *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  int iVar2;
  
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  this->m_iGeigerRange = iVar2 << 2;
  return 1;
}


