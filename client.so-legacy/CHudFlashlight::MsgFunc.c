// CHudFlashlight::MsgFunc_FlashBat  @ 0008f330
/* DWARF original prototype: int MsgFunc_FlashBat(CHudFlashlight * this, char * pszName, int iSize,
   void * pbuf) */

int __thiscall
CHudFlashlight::MsgFunc_FlashBat(CHudFlashlight *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
                    /* Unresolved local var: int x@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_iBat = iVar1;
  this->m_flBat = (float)iVar1 / 100.0;
  return 1;
}


// CHudFlashlight::MsgFunc_Flashlight  @ 0008f370
/* DWARF original prototype: int MsgFunc_Flashlight(CHudFlashlight * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
CHudFlashlight::MsgFunc_Flashlight(CHudFlashlight *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
                    /* Unresolved local var: int x@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_fOn = iVar1;
  iVar1 = READ_BYTE();
  this->m_iBat = iVar1;
  this->m_flBat = (float)iVar1 / 100.0;
  return 1;
}


