// CHudTrain::MsgFunc_Train  @ 000a7340
/* DWARF original prototype: int MsgFunc_Train(CHudTrain * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHudTrain::MsgFunc_Train(CHudTrain *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  int iVar2;
  
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  this->m_iPos = iVar2;
  if (iVar2 == 0) {
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 & 0xfffffffe;
    return 1;
  }
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  return 1;
}


