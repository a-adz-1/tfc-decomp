// CHudAmmo::MsgFunc_AmmoPickup  @ 00087a80
/* DWARF original prototype: int MsgFunc_AmmoPickup(CHudAmmo * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudAmmo::MsgFunc_AmmoPickup(CHudAmmo *this,char *pszName,int iSize,void *pbuf)

{
  int iId;
  uint uVar1;
  
                    /* Unresolved local var: int iIndex@[???]
                       Unresolved local var: int iCount@[???] */
  BEGIN_READ(pbuf,iSize);
  iId = READ_BYTE();
  uVar1 = READ_BYTE();
  HistoryResource::AddToHistory(&gHR,1,iId,(uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f));
  return 1;
}


// CHudAmmo::MsgFunc_AmmoX  @ 00087a30
/* DWARF original prototype: int MsgFunc_AmmoX(CHudAmmo * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHudAmmo::MsgFunc_AmmoX(CHudAmmo *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: int iIndex@[???]
                       Unresolved local var: int iCount@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  uVar2 = READ_BYTE();
  gWR.riAmmo[iVar1] = uVar2 ^ (int)uVar2 >> 0x1f;
  gWR.riAmmo[iVar1] = gWR.riAmmo[iVar1] - ((int)uVar2 >> 0x1f);
  return 1;
}


// CHudAmmo::MsgFunc_CurWeapon  @ 00087c90
/* DWARF original prototype: int MsgFunc_CurWeapon(CHudAmmo * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudAmmo::MsgFunc_CurWeapon(CHudAmmo *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  wrect_t wVar2;
  wrect_t wVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
                    /* Unresolved local var: int fOnTarget@[???]
                       Unresolved local var: int iState@[???]
                       Unresolved local var: int iId@[???]
                       Unresolved local var: int iClip@[???]
                       Unresolved local var: WEAPON * pWeapon@[DW_OP_reg2(EDX)] */
  BEGIN_READ(pbuf,iSize);
  iVar4 = READ_BYTE();
  iVar5 = READ_CHAR();
  iVar6 = READ_CHAR();
  if (iVar5 < 1) {
    wVar2.right = MsgFunc_CurWeapon::lexical_block_0::nullrc.right;
    wVar2.left = MsgFunc_CurWeapon::lexical_block_0::nullrc.left;
    wVar2.top = MsgFunc_CurWeapon::lexical_block_0::nullrc.top;
    wVar2.bottom = MsgFunc_CurWeapon::lexical_block_0::nullrc.bottom;
    (*gEngfuncs.pfnSetCrosshair)(0,wVar2,0,0,0);
    return 0;
  }
  if (g_iUser1 != 4) {
    gHUD.m_fPlayerDead = 0;
  }
  if (iVar6 < -1) {
    gWR.rgWeapons[iVar5].iClip = -iVar6;
  }
  else {
    gWR.rgWeapons[iVar5].iClip = iVar6;
  }
  if (iVar4 == 0) {
    return 1;
  }
  this->m_pWeapon = gWR.rgWeapons + iVar5;
  if (gHUD.m_iFOV < 0x5a) {
    if ((iVar4 < 2) || (iVar4 = gWR.rgWeapons[iVar5].hZoomedAutoaim, iVar4 == 0)) {
      (*gEngfuncs.pfnSetCrosshair)
                (gWR.rgWeapons[iVar5].hZoomedCrosshair,gWR.rgWeapons[iVar5].rcZoomedCrosshair,0xff,
                 0xff,0xff);
      goto LAB_00087d9c;
    }
    iVar6 = gWR.rgWeapons[iVar5].rcZoomedAutoaim.left;
    iVar8 = gWR.rgWeapons[iVar5].rcZoomedAutoaim.right;
    iVar7 = gWR.rgWeapons[iVar5].rcZoomedAutoaim.top;
    iVar5 = gWR.rgWeapons[iVar5].rcZoomedAutoaim.bottom;
  }
  else {
    if ((iVar4 < 2) || (iVar4 = gWR.rgWeapons[iVar5].hAutoaim, iVar4 == 0)) {
      (*gEngfuncs.pfnSetCrosshair)
                (gWR.rgWeapons[iVar5].hCrosshair,gWR.rgWeapons[iVar5].rcCrosshair,0xff,0xff,0xff);
      goto LAB_00087d9c;
    }
    iVar6 = gWR.rgWeapons[iVar5].rcAutoaim.left;
    iVar8 = gWR.rgWeapons[iVar5].rcAutoaim.right;
    iVar7 = gWR.rgWeapons[iVar5].rcAutoaim.top;
    iVar5 = gWR.rgWeapons[iVar5].rcAutoaim.bottom;
  }
  wVar3.right = iVar8;
  wVar3.left = iVar6;
  wVar3.top = iVar7;
  wVar3.bottom = iVar5;
  (*gEngfuncs.pfnSetCrosshair)(iVar4,wVar3,0xff,0xff,0xff);
LAB_00087d9c:
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  this->m_fFade = 200.0;
  return 1;
}


// CHudAmmo::MsgFunc_HideWeapon  @ 00087b70
/* DWARF original prototype: int MsgFunc_HideWeapon(CHudAmmo * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudAmmo::MsgFunc_HideWeapon(CHudAmmo *this,char *pszName,int iSize,void *pbuf)

{
  WEAPON *pWVar1;
  wrect_t wVar2;
  int iVar3;
  
  BEGIN_READ(pbuf,iSize);
  gHUD.m_iHideHUDDisplay = READ_BYTE();
  iVar3 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar3 == 0) {
    if ((gHUD.m_iHideHUDDisplay & 5U) != 0) {
      gpActiveSel = (WEAPON *)0x0;
      wVar2.right = MsgFunc_HideWeapon::lexical_block_0::nullrc.right;
      wVar2.left = MsgFunc_HideWeapon::lexical_block_0::nullrc.left;
      wVar2.top = MsgFunc_HideWeapon::lexical_block_0::nullrc.top;
      wVar2.bottom = MsgFunc_HideWeapon::lexical_block_0::nullrc.bottom;
      (*gEngfuncs.pfnSetCrosshair)(0,wVar2,0,0,0);
      return 1;
    }
    pWVar1 = this->m_pWeapon;
    if (pWVar1 != (WEAPON *)0x0) {
      (*gEngfuncs.pfnSetCrosshair)(pWVar1->hCrosshair,pWVar1->rcCrosshair,0xff,0xff,0xff);
    }
  }
  return 1;
}


// CHudAmmo::MsgFunc_ItemPickup  @ 00087b20
/* DWARF original prototype: int MsgFunc_ItemPickup(CHudAmmo * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudAmmo::MsgFunc_ItemPickup(CHudAmmo *this,char *pszName,int iSize,void *pbuf)

{
  char *szName;
  
                    /* Unresolved local var: char * szName@[???] */
  BEGIN_READ(pbuf,iSize);
  szName = READ_STRING();
  HistoryResource::AddToHistory(&gHR,3,szName,0);
  return 1;
}


// CHudAmmo::MsgFunc_WeapPickup  @ 00087ad0
/* DWARF original prototype: int MsgFunc_WeapPickup(CHudAmmo * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudAmmo::MsgFunc_WeapPickup(CHudAmmo *this,char *pszName,int iSize,void *pbuf)

{
  int iId;
  
                    /* Unresolved local var: int iIndex@[???] */
  BEGIN_READ(pbuf,iSize);
  iId = READ_BYTE();
  HistoryResource::AddToHistory(&gHR,2,iId,0);
  return 1;
}


// CHudAmmo::MsgFunc_WeaponList  @ 00087f40
/* DWARF original prototype: int MsgFunc_WeaponList(CHudAmmo * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudAmmo::MsgFunc_WeaponList(CHudAmmo *this,char *pszName,int iSize,void *pbuf)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *__src;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char local_16c [4];
  undefined4 auStack_168 [30];
  undefined1 local_ed;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  uint local_dc;
  uint local_d8;
  int local_d4;
  uint local_d0;
  undefined4 local_cc;
  
                    /* Unresolved local var: WEAPON Weapon@[???] */
  BEGIN_READ(pbuf,iSize);
  __src = READ_STRING();
  strncpy(local_16c,__src,0x80);
  local_ed = 0;
  iVar4 = READ_CHAR();
  local_ec = iVar4;
  local_e4 = READ_BYTE();
  if (local_e4 == 0xff) {
    local_e4 = -1;
  }
  iVar2 = local_e4;
  iVar5 = READ_CHAR();
  local_e8 = iVar5;
  local_e0 = READ_BYTE();
  if (local_e0 == 0xff) {
    local_e0 = -1;
  }
  iVar3 = local_e0;
  uVar6 = READ_CHAR();
  local_dc = uVar6;
  uVar7 = READ_CHAR();
  local_d8 = uVar7;
  uVar8 = READ_CHAR();
  local_d0 = uVar8;
  local_d4 = READ_BYTE();
  local_cc = 0;
  iVar9 = 0;
  if ((((((uVar8 < 0x20) && (uVar6 < 6)) && (uVar7 < 6)) &&
       ((iVar4 + 1U < 0x21 && (iVar5 + 1U < 0x21)))) && ((iVar4 == -1 || (iVar2 != 0)))) &&
     ((iVar5 == -1 || (iVar9 = 0, iVar3 != 0)))) {
    uVar6 = 0;
    do {
      uVar1 = *(undefined4 *)((int)auStack_168 + uVar6);
      *(undefined4 *)(gWR.rgWeapons[uVar8].szName + uVar6) =
           *(undefined4 *)((int)auStack_168 + (uVar6 - 4));
      *(undefined4 *)(uVar8 * 0x148 + 0x1189a4 + uVar6) = uVar1;
      uVar6 = uVar6 + 8;
    } while (uVar6 < 0x148);
    WeaponsResource::LoadWeaponSprites(&gWR,gWR.rgWeapons + uVar8);
    iVar9 = 1;
  }
  return iVar9;
}


