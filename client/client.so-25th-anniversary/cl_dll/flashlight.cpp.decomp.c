// Ghidra decompilation of functions from cl_dll/flashlight.cpp
// 8 functions, ordered by original source line

// __MsgFunc_FlashBat  @ 0006b760  (line 30)

int __MsgFunc_FlashBat(char *pszName,int iSize,void *pbuf)

{
                    /* Unresolved local var: int x@[???] */
  BEGIN_READ(pbuf,iSize);
  gHUD.m_Flash.m_iBat = READ_BYTE();
  gHUD.m_Flash.m_flBat = (float)gHUD.m_Flash.m_iBat / 100.0;
  return 1;
}


// __MsgFunc_Flashlight  @ 0006b9e0  (line 31)

int __MsgFunc_Flashlight(char *pszName,int iSize,void *pbuf)

{
                    /* Unresolved local var: int x@[???] */
  BEGIN_READ(pbuf,iSize);
  gHUD.m_Flash.m_fOn = READ_BYTE();
  gHUD.m_Flash.m_iBat = READ_BYTE();
  gHUD.m_Flash.m_flBat = (float)gHUD.m_Flash.m_iBat / 100.0;
  return 1;
}


// CHudFlashlight::Init  @ 0006b630  (line 36)

/* DWARF original prototype: int Init(CHudFlashlight * this) */

int __thiscall CHudFlashlight::Init(CHudFlashlight *this)

{
  int *piVar1;
  
  this->m_fFade = 0.0;
  this->m_fOn = 0;
  (*gEngfuncs.pfnHookUserMsg)("Flashlight",__MsgFunc_Flashlight);
  (*gEngfuncs.pfnHookUserMsg)("FlashBat",__MsgFunc_FlashBat);
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  return 1;
}


// CHudFlashlight::Reset  @ 0006b610  (line 51)

/* DWARF original prototype: void Reset(CHudFlashlight * this) */

void __thiscall CHudFlashlight::Reset(CHudFlashlight *this)

{
  this->m_fFade = 0.0;
  this->m_fOn = 0;
  return;
}


// CHudFlashlight::VidInit  @ 0006b690  (line 57)

/* DWARF original prototype: int VidInit(CHudFlashlight * this) */

int __thiscall CHudFlashlight::VidInit(CHudFlashlight *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  HANDLE_SPRITE HVar4;
  wrect_t *pwVar5;
  
                    /* Unresolved local var: int HUD_flash_empty@[???]
                       Unresolved local var: int HUD_flash_full@[???]
                       Unresolved local var: int HUD_flash_beam@[???] */
  iVar1 = CHud::GetSpriteIndex(&gHUD,"flash_empty");
  iVar2 = CHud::GetSpriteIndex(&gHUD,"flash_full");
  iVar3 = CHud::GetSpriteIndex(&gHUD,"flash_beam");
  HVar4 = 0;
  if (-1 < iVar1) {
    HVar4 = gHUD.m_rghSprites[iVar1];
  }
  this->m_hSprite1 = HVar4;
  HVar4 = 0;
  if (-1 < iVar2) {
    HVar4 = gHUD.m_rghSprites[iVar2];
  }
  this->m_hSprite2 = HVar4;
  HVar4 = 0;
  if (-1 < iVar3) {
    HVar4 = gHUD.m_rghSprites[iVar3];
  }
  this->m_hBeam = HVar4;
  this->m_prc1 = gHUD.m_rgrcRects + iVar1;
  pwVar5 = gHUD.m_rgrcRects + iVar2;
  this->m_prc2 = pwVar5;
  this->m_prcBeam = gHUD.m_rgrcRects + iVar3;
  this->m_iWidth = pwVar5->right - pwVar5->left;
  return 1;
}


// CHudFlashlight::MsgFunc_FlashBat  @ 0006ba30  (line 74)

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


// CHudFlashlight::MsgFunc_Flashlight  @ 0006ba70  (line 86)

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


// CHudFlashlight::Draw  @ 0006b7a0  (line 98)

/* DWARF original prototype: int Draw(CHudFlashlight * this, float flTime) */

int __thiscall CHudFlashlight::Draw(CHudFlashlight *this,float flTime)

{
  wrect_t *pwVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_38;
  int local_34;
  int local_30;
  rect_s local_2c;
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: wrect_t rc@[???]
                       Unresolved local var: int iOffset@[???] */
  if ((((byte)gHUD.m_iHideHUDDisplay & 6) == 0) && (gHUD.m_iWeaponBits < 0)) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: wrect_t rc@[???]
                       Unresolved local var: int iOffset@[???] */
    local_38 = 0xff;
    if (this->m_flBat < 0.2) {
      local_34 = 0x10;
      local_30 = 0x10;
    }
    else {
      local_34 = 0xa0;
      local_30 = 0;
    }
    ScaleColors(&local_38,&local_34,&local_30,(-(uint)(this->m_fOn == 0) & 0xffffff83) + 0xe1);
    iVar5 = this->m_iWidth;
    iVar2 = (this->m_prc1->bottom - this->m_prc2->top) / 2;
    iVar3 = gHUD.m_scrinfo.iWidth - iVar5;
    (*gEngfuncs.pfnSPR_Set)(this->m_hSprite1,local_38,local_34,local_30);
    (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar3 - iVar5 / 2,iVar2,this->m_prc1);
    if (this->m_fOn != 0) {
      iVar5 = gHUD.m_scrinfo.iWidth - this->m_iWidth / 2;
      (*gEngfuncs.pfnSPR_Set)(this->m_hBeam,local_38,local_34,local_30);
      (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar5,iVar2,this->m_prcBeam);
    }
    iVar3 = gHUD.m_scrinfo.iWidth;
    iVar5 = this->m_iWidth;
    iVar4 = (int)((float)iVar5 * (1.0 - this->m_flBat));
    if (iVar4 < iVar5) {
      pwVar1 = this->m_prc2;
      local_2c.right = pwVar1->right;
      local_2c.left = pwVar1->left + iVar4;
      local_2c.top = pwVar1->top;
      local_2c.bottom = pwVar1->bottom;
      (*gEngfuncs.pfnSPR_Set)(this->m_hSprite2,local_38,local_34,local_30);
      (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar4 + ((iVar3 - iVar5) - iVar5 / 2),iVar2,&local_2c);
    }
  }
  return 1;
}


