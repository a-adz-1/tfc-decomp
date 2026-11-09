// CHudAmmoSecondary::MsgFunc_SecAmmoIcon  @ 0008b030
/* DWARF original prototype: int MsgFunc_SecAmmoIcon(CHudAmmoSecondary * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
CHudAmmoSecondary::MsgFunc_SecAmmoIcon(CHudAmmoSecondary *this,char *pszName,int iSize,void *pbuf)

{
  char *SpriteName;
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  SpriteName = READ_STRING();
  iVar1 = CHud::GetSpriteIndex(&gHUD,SpriteName);
  this->m_HUD_ammoicon = iVar1;
  return 1;
}


// CHudAmmoSecondary::MsgFunc_SecAmmoVal  @ 0008b070
/* DWARF original prototype: int MsgFunc_SecAmmoVal(CHudAmmoSecondary * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
CHudAmmoSecondary::MsgFunc_SecAmmoVal(CHudAmmoSecondary *this,char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int count@[???] */
  BEGIN_READ(pbuf,iSize);
  uVar1 = READ_BYTE();
  if (3 < uVar1) {
    return 1;
  }
  iVar2 = READ_BYTE();
  this->m_iAmmoAmounts[uVar1] = iVar2;
                    /* Unresolved local var: int i@[???] */
  uVar1 = (this->super_CHudBase).m_iFlags;
  iVar2 = 0;
  if (-1 < this->m_iAmmoAmounts[0]) {
    iVar2 = this->m_iAmmoAmounts[0];
  }
  iVar4 = 0;
  if (-1 < this->m_iAmmoAmounts[1]) {
    iVar4 = this->m_iAmmoAmounts[1];
  }
  (this->super_CHudBase).m_iFlags = uVar1 | 1;
  iVar5 = 0;
  if (-1 < this->m_iAmmoAmounts[2]) {
    iVar5 = this->m_iAmmoAmounts[2];
  }
  iVar3 = 0;
  if (-1 < this->m_iAmmoAmounts[3]) {
    iVar3 = this->m_iAmmoAmounts[3];
  }
  if (iVar3 + iVar4 + iVar2 + iVar5 != 0) {
    this->m_fFade = 200.0;
    return 1;
  }
  (this->super_CHudBase).m_iFlags = uVar1 & 0xfffffffe;
  return 1;
}


