// Ghidra decompilation of functions from cl_dll/battery.cpp
// 5 functions, ordered by original source line

// __MsgFunc_Battery  @ 000687f0  (line 28)

int __MsgFunc_Battery(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  gHUD.m_Battery.super_CHudBase.m_iFlags = gHUD.m_Battery.super_CHudBase.m_iFlags | 1;
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_SHORT();
  iVar2 = READ_SHORT();
  if ((iVar1 != gHUD.m_Battery.m_iBat) || (iVar2 != gHUD.m_Battery.m_iBatMax)) {
    gHUD.m_Battery.m_fFade = 100.0;
    gHUD.m_Battery.m_iBat = iVar1;
    gHUD.m_Battery.m_iBatMax = iVar2;
  }
  return 1;
}


// CHudBattery::Init  @ 000683a0  (line 31)

/* DWARF original prototype: int Init(CHudBattery * this) */

int __thiscall CHudBattery::Init(CHudBattery *this)

{
  this->m_iBat = 0;
  this->m_fFade = 0.0;
  (this->super_CHudBase).m_iFlags = 0;
  (*gEngfuncs.pfnHookUserMsg)("Battery",__MsgFunc_Battery);
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  return 1;
}


// CHudBattery::VidInit  @ 000683f0  (line 45)

/* DWARF original prototype: int VidInit(CHudBattery * this) */

int __thiscall CHudBattery::VidInit(CHudBattery *this)

{
  int iVar1;
  int iVar2;
  wrect_t *pwVar3;
  wrect_t *pwVar4;
  
                    /* Unresolved local var: int HUD_suit_empty@[???]
                       Unresolved local var: int HUD_suit_full@[???] */
  iVar1 = CHud::GetSpriteIndex(&gHUD,"suit_empty");
  iVar2 = CHud::GetSpriteIndex(&gHUD,"suit_full");
  this->m_hSprite2 = 0;
  this->m_hSprite1 = 0;
  pwVar4 = gHUD.m_rgrcRects + iVar1;
  this->m_prc1 = pwVar4;
  pwVar3 = gHUD.m_rgrcRects + iVar2;
  this->m_prc2 = pwVar3;
  iVar1 = pwVar4->top;
  iVar2 = pwVar3->bottom;
  this->m_fFade = 0.0;
  this->m_iHeight = iVar2 - iVar1;
  return 1;
}


// CHudBattery::MsgFunc_Battery  @ 00068860  (line 58)

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
  if ((iVar2 != this->m_iBat) || (iVar3 != this->m_iBatMax)) {
    this->m_fFade = 100.0;
    this->m_iBat = iVar2;
    this->m_iBatMax = iVar3;
  }
  return 1;
}


// CHudBattery::Draw  @ 00068470  (line 86)

/* DWARF original prototype: int Draw(CHudBattery * this, float flTime) */

int __thiscall CHudBattery::Draw(CHudBattery *this,float flTime)

{
  float fVar1;
  wrect_t *pwVar2;
  int iVar3;
  int iVar4;
  HANDLE_SPRITE HVar5;
  int iVar6;
  int iVar7;
  int iVar8;
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
                       Unresolved local var: float fScale@[???]
                       Unresolved local var: int iOffset@[???]
                       Unresolved local var: int width@[???] */
  if (((byte)gHUD.m_iHideHUDDisplay & 8) == 0) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: wrect_t rc@[???]
                       Unresolved local var: float fScale@[???]
                       Unresolved local var: int iOffset@[???]
                       Unresolved local var: int width@[???] */
    pwVar2 = this->m_prc2;
    local_2c.left = pwVar2->left;
    local_2c.right = pwVar2->right;
    local_2c.bottom = pwVar2->bottom;
    iVar3 = this->m_iBatMax;
    if (iVar3 < 1) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = 1.0 / (float)iVar3;
    }
    iVar6 = iVar3;
    if (this->m_iBat <= iVar3) {
      iVar6 = this->m_iBat;
    }
    local_34 = 0xa0;
    local_30 = 0;
    local_38 = 0xff;
    local_2c.top = (int)((float)pwVar2->top +
                        (float)this->m_iHeight * (float)(iVar3 - iVar6) * fVar1);
    if (gHUD.m_iWeaponBits < 0) {
      fVar1 = this->m_fFade;
      iVar3 = 100;
      if (fVar1 != 0.0) {
        if (100.0 < fVar1) {
          this->m_fFade = 100.0;
          fVar1 = 100.0;
        }
        fVar1 = fVar1 - (float)gHUD.m_flTimeDelta * 20.0;
        if (fVar1 <= 0.0) {
          this->m_fFade = 0.0;
          iVar3 = 100;
        }
        else {
          this->m_fFade = fVar1;
          iVar3 = (int)((fVar1 / 100.0) * 128.0 + 100.0);
        }
      }
      ScaleColors(&local_38,&local_34,&local_30,iVar3);
      pwVar2 = this->m_prc1;
      HVar5 = this->m_hSprite1;
      iVar3 = pwVar2->top;
      iVar6 = pwVar2->bottom;
      iVar7 = (gHUD.m_scrinfo.iHeight - gHUD.m_iFontHeight) - gHUD.m_iFontHeight / 2;
      iVar8 = pwVar2->right - pwVar2->left;
      if (HVar5 == 0) {
        iVar4 = CHud::GetSpriteIndex(&gHUD,"suit_empty");
        if (-1 < iVar4) {
          HVar5 = gHUD.m_rghSprites[iVar4];
        }
        this->m_hSprite1 = HVar5;
      }
      if (this->m_hSprite2 == 0) {
        iVar4 = CHud::GetSpriteIndex(&gHUD,"suit_full");
        HVar5 = 0;
        if (-1 < iVar4) {
          HVar5 = gHUD.m_rghSprites[iVar4];
        }
        this->m_hSprite2 = HVar5;
        HVar5 = this->m_hSprite1;
      }
      (*gEngfuncs.pfnSPR_Set)(HVar5,local_38,local_34,local_30);
      iVar3 = iVar7 - (iVar6 - iVar3) / 6;
      (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar8 * 3,iVar3,this->m_prc1);
      if (local_2c.top < local_2c.bottom) {
        (*gEngfuncs.pfnSPR_Set)(this->m_hSprite2,local_38,local_34,local_30);
        (*gEngfuncs.pfnSPR_DrawAdditive)
                  (0,iVar8 * 3,(iVar3 - this->m_prc2->top) + local_2c.top,&local_2c);
      }
      CHud::DrawHudNumber(&gHUD,iVar8 * 4,iVar7 + (int)((float)gHUD.m_iFontHeight * 0.2),5,
                          this->m_iBat,local_38,local_34,local_30);
    }
  }
  return 1;
}


