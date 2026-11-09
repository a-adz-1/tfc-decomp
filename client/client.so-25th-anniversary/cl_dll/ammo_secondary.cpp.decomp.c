// Ghidra decompilation of functions from cl_dll/ammo_secondary.cpp
// 8 functions, ordered by original source line

// __MsgFunc_SecAmmoVal  @ 00067ab0  (line 27)

int __MsgFunc_SecAmmoVal(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int count@[???] */
  BEGIN_READ(pbuf,iSize);
  uVar2 = READ_BYTE();
  if (3 < uVar2) {
    return 1;
  }
  iVar3 = READ_BYTE();
  iVar1 = gHUD.m_AmmoSecondary.super_CHudBase.m_iFlags;
  gHUD.m_AmmoSecondary.m_iAmmoAmounts[uVar2] = iVar3;
                    /* Unresolved local var: int i@[???] */
  gHUD.m_AmmoSecondary.super_CHudBase.m_iFlags = gHUD.m_AmmoSecondary.super_CHudBase.m_iFlags | 1;
  if ((gHUD.m_AmmoSecondary.m_iAmmoAmounts[0] & -(uint)(0 < gHUD.m_AmmoSecondary.m_iAmmoAmounts[0]))
      + (gHUD.m_AmmoSecondary.m_iAmmoAmounts[2] &
        -(uint)(0 < gHUD.m_AmmoSecondary.m_iAmmoAmounts[2])) +
      (gHUD.m_AmmoSecondary.m_iAmmoAmounts[1] & -(uint)(0 < gHUD.m_AmmoSecondary.m_iAmmoAmounts[1]))
      + (gHUD.m_AmmoSecondary.m_iAmmoAmounts[3] &
        -(uint)(0 < gHUD.m_AmmoSecondary.m_iAmmoAmounts[3])) != 0) {
    gHUD.m_AmmoSecondary.m_fFade = 200.0;
    return 1;
  }
  gHUD.m_AmmoSecondary.super_CHudBase.m_iFlags = iVar1 & 0xfffffffe;
  return 1;
}


// __MsgFunc_SecAmmoIcon  @ 00067a70  (line 28)

int __MsgFunc_SecAmmoIcon(char *pszName,int iSize,void *pbuf)

{
  char *SpriteName;
  
  BEGIN_READ(pbuf,iSize);
  SpriteName = READ_STRING();
  gHUD.m_AmmoSecondary.m_HUD_ammoicon = CHud::GetSpriteIndex(&gHUD,SpriteName);
  return 1;
}


// CHudAmmoSecondary::Init  @ 000679d0  (line 31)

/* DWARF original prototype: int Init(CHudAmmoSecondary * this) */

int __thiscall CHudAmmoSecondary::Init(CHudAmmoSecondary *this)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  
  (*gEngfuncs.pfnHookUserMsg)("SecAmmoVal",__MsgFunc_SecAmmoVal);
  (*gEngfuncs.pfnHookUserMsg)("SecAmmoIcon",__MsgFunc_SecAmmoIcon);
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  pp_Var1 = (this->super_CHudBase)._vptr_CHudBase;
  this->m_HUD_ammoicon = 0;
                    /* Unresolved local var: int i@[???] */
  this->m_iAmmoAmounts[0] = -1;
  this->m_iAmmoAmounts[1] = -1;
  this->m_iAmmoAmounts[2] = -1;
  this->m_iAmmoAmounts[3] = -1;
  p_Var2 = pp_Var1[6];
  if (p_Var2 == Reset) {
    this->m_fFade = 0.0;
    return 1;
  }
  (*p_Var2)(this);
  return 1;
}


// CHudAmmoSecondary::Reset  @ 00067730  (line 48)

/* DWARF original prototype: void Reset(CHudAmmoSecondary * this) */

void __thiscall CHudAmmoSecondary::Reset(CHudAmmoSecondary *this)

{
  this->m_fFade = 0.0;
  return;
}


// CHudAmmoSecondary::VidInit  @ 00067740  (line 54)

/* DWARF original prototype: int VidInit(CHudAmmoSecondary * this) */

int __thiscall CHudAmmoSecondary::VidInit(CHudAmmoSecondary *this)

{
  return 1;
}


// CHudAmmoSecondary::Draw  @ 00067750  (line 57)

/* DWARF original prototype: int Draw(CHudAmmoSecondary * this, float flTime) */

int __thiscall CHudAmmoSecondary::Draw(CHudAmmoSecondary *this,float flTime)

{
  float fVar1;
  int a;
  int iVar2;
  wrect_t *pwVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  HANDLE_SPRITE local_44;
  int local_34;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int AmmoWidth@[???] */
  if ((gHUD.m_iHideHUDDisplay & 5U) == 0) {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int AmmoWidth@[???] */
    fVar1 = this->m_fFade;
    local_28 = 0xff;
    local_24 = 0xa0;
    local_20[0] = 0;
    a = 100;
    if (99 < (int)fVar1) {
      a = (int)fVar1;
    }
    if (0.0 < fVar1) {
      this->m_fFade = fVar1 - (float)gHUD.m_flTimeDelta * 20.0;
    }
    ScaleColors(&local_28,&local_24,local_20,a);
    pwVar3 = gHUD.m_rgrcRects + gHUD.m_HUD_number_0;
    iVar5 = pwVar3->right - pwVar3->left;
    iVar2 = gHUD.m_scrinfo.iHeight + gHUD.m_iFontHeight * -4;
    iVar6 = this->m_HUD_ammoicon;
    if (iVar6 == 0) {
      iVar4 = (gHUD.m_scrinfo.iWidth - iVar5) - iVar5;
      local_34 = (iVar2 + pwVar3->bottom) - pwVar3->top;
    }
    else {
      pwVar3 = gHUD.m_rgrcRects + iVar6;
      iVar4 = ((gHUD.m_scrinfo.iWidth - iVar5) + pwVar3->left) - pwVar3->right;
      local_34 = (iVar2 + pwVar3->bottom) - pwVar3->top;
      local_44 = 0;
      if (-1 < iVar6) {
        local_44 = gHUD.m_rghSprites[iVar6];
      }
      (*gEngfuncs.pfnSPR_Set)(local_44,local_28,local_24,local_20[0]);
      (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar4,local_34,gHUD.m_rgrcRects + this->m_HUD_ammoicon);
    }
                    /* Unresolved local var: int i@[???] */
    iVar6 = 3;
    do {
      if (-1 < this->m_iAmmoAmounts[iVar6]) {
        iVar2 = CHud::GetNumWidth(&gHUD,this->m_iAmmoAmounts[iVar6],1);
        iVar4 = (iVar4 + -(iVar5 / 2)) - iVar2 * iVar5;
        CHud::DrawHudNumber(&gHUD,iVar4,local_34,1,this->m_iAmmoAmounts[iVar6],local_28,local_24,
                            local_20[0]);
        if (iVar6 == 0) {
          return 1;
        }
        iVar4 = iVar4 + -(iVar5 / 2);
        (*gEngfuncs.pfnFillRGBA)
                  (iVar4,local_34,iVar5 / 10,gHUD.m_iFontHeight,local_28,local_24,local_20[0],a);
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != -1);
  }
  return 1;
}


// CHudAmmoSecondary::MsgFunc_SecAmmoIcon  @ 00067b70  (line 117)

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


// CHudAmmoSecondary::MsgFunc_SecAmmoVal  @ 00067bb0  (line 130)

/* DWARF original prototype: int MsgFunc_SecAmmoVal(CHudAmmoSecondary * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
CHudAmmoSecondary::MsgFunc_SecAmmoVal(CHudAmmoSecondary *this,char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int count@[???] */
  BEGIN_READ(pbuf,iSize);
  uVar5 = READ_BYTE();
  if (uVar5 < 4) {
    iVar6 = READ_BYTE();
    this->m_iAmmoAmounts[uVar5] = iVar6;
    uVar5 = (this->super_CHudBase).m_iFlags;
                    /* Unresolved local var: int i@[???] */
    uVar1 = this->m_iAmmoAmounts[0];
    uVar2 = this->m_iAmmoAmounts[1];
    uVar3 = this->m_iAmmoAmounts[2];
    uVar4 = this->m_iAmmoAmounts[3];
    (this->super_CHudBase).m_iFlags = uVar5 | 1;
    if ((uVar1 & -(uint)(0 < (int)uVar1)) + (uVar3 & -(uint)(0 < (int)uVar3)) +
        (uVar2 & -(uint)(0 < (int)uVar2)) + (uVar4 & -(uint)(0 < (int)uVar4)) == 0) {
      (this->super_CHudBase).m_iFlags = uVar5 & 0xfffffffe;
    }
    else {
      this->m_fFade = 200.0;
    }
  }
  return 1;
}


