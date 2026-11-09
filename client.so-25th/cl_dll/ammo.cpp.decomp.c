// Ghidra decompilation of functions from cl_dll/ammo.cpp
// 60 functions, ordered by original source line

// WeaponsResource::LoadAllWeaponSprites  @ 00062c50  (line 43)

/* DWARF original prototype: void LoadAllWeaponSprites(WeaponsResource * this) */

void __thiscall WeaponsResource::LoadAllWeaponSprites(WeaponsResource *this)

{
  WEAPON *pWVar1;
  WeaponsResource *pWeapon;
  
  pWeapon = this;
  do {
    while (pWeapon->rgWeapons[0].iId != 0) {
      pWVar1 = pWeapon->rgWeapons;
      LoadWeaponSprites(this,pWeapon->rgWeapons);
      pWeapon = (WeaponsResource *)(pWVar1 + 1);
      if ((WeaponsResource *)(pWVar1 + 1) == (WeaponsResource *)this->rgSlots) {
        return;
      }
    }
    pWeapon = (WeaponsResource *)(pWeapon->rgWeapons + 1);
                    /* Unresolved local var: int i@[???] */
  } while (pWeapon != (WeaponsResource *)this->rgSlots);
  return;
}


// WeaponsResource::CountAmmo  @ 00062210  (line 52)

/* DWARF original prototype: int CountAmmo(WeaponsResource * this, int iId) */

int __thiscall WeaponsResource::CountAmmo(WeaponsResource *this,int iId)

{
  if (-1 < iId) {
    return this->riAmmo[iId];
  }
  return 0;
}


// WeaponsResource::HasAmmo  @ 00062230  (line 60)

/* DWARF original prototype: int HasAmmo(WeaponsResource * this, WEAPON * p) */

int __thiscall WeaponsResource::HasAmmo(WeaponsResource *this,WEAPON *p)

{
  int iVar1;
  
  if (p == (WEAPON *)0x0) {
    return 0;
  }
  if (p->iMax1 != -1) {
    iVar1 = p->iAmmoType;
    if ((((iVar1 != -1) && (p->iClip < 1)) && ((iVar1 < 0 || (this->riAmmo[iVar1] == 0)))) &&
       ((p->iAmmo2Type < 0 || (this->riAmmo[p->iAmmo2Type] == 0)))) {
      return p->iFlags & 1;
    }
    return 1;
  }
  return 1;
}


// WeaponsResource::LoadWeaponSprites  @ 000622c0  (line 74)

/* DWARF original prototype: void LoadWeaponSprites(WeaponsResource * this, WEAPON * pWeapon) */

void __thiscall WeaponsResource::LoadWeaponSprites(WeaponsResource *this,WEAPON *pWeapon)

{
  client_sprite_s *pcVar1;
  HANDLE_SPRITE HVar2;
  int iVar3;
  int iVar4;
  client_sprite_s *pcVar5;
  int iVar6;
  char *pcVar7;
  client_sprite_s *pcVar8;
  int in_GS_OFFSET;
  bool bVar9;
  byte bVar10;
  int local_c0;
  int local_b8;
  HANDLE_SPRITE local_b0;
  int local_a4;
  char local_a0 [128];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iRes@[???]
                       Unresolved local var: char[128] sz@[???]
                       Unresolved local var: client_sprite_t * pList@[???]
                       Unresolved local var: client_sprite_t * p@[???] */
  bVar10 = 0;
  iVar6 = 0x140;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (0x27f < gHUD.m_scrinfo.iWidth) {
    iVar6 = 0x280;
  }
  iVar3 = gHR.iHistoryGap;
  if (pWeapon != (WEAPON *)0x0) {
    (pWeapon->rcInactive).left = 0;
    (pWeapon->rcInactive).right = 0;
    (pWeapon->rcInactive).top = 0;
    (pWeapon->rcInactive).bottom = 0;
    (pWeapon->rcAmmo).left = 0;
    (pWeapon->rcAmmo).right = 0;
    (pWeapon->rcAmmo2).top = 0;
    (pWeapon->rcAmmo2).bottom = 0;
    pWeapon->hInactive = 0;
    pWeapon->hActive = 0;
    (pWeapon->rcActive).left = 0;
    (pWeapon->rcActive).right = 0;
    (pWeapon->rcActive).top = 0;
    (pWeapon->rcActive).bottom = 0;
    pWeapon->hAmmo = 0;
    (pWeapon->rcAmmo).top = 0;
    (pWeapon->rcAmmo).bottom = 0;
    pWeapon->hAmmo2 = 0;
    (pWeapon->rcAmmo2).left = 0;
    (pWeapon->rcAmmo2).right = 0;
    __sprintf_chk(local_a0,1,0x80,"sprites/%s.txt",pWeapon);
    pcVar1 = (*gEngfuncs.pfnSPR_GetList)(local_a0,&local_a4);
    iVar3 = gHR.iHistoryGap;
    pcVar5 = pcVar1;
    iVar4 = local_a4;
    if (pcVar1 != (client_sprite_s *)0x0) {
      for (; iVar4 != 0; iVar4 = iVar4 + -1) {
        if (iVar6 == pcVar5->iRes) {
          iVar3 = 10;
          bVar9 = true;
          pcVar7 = "crosshair";
          pcVar8 = pcVar5;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar9 = *pcVar7 == pcVar8->szName[0];
            pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
            pcVar8 = (client_sprite_s *)((int)pcVar8 + (uint)bVar10 * -2 + 1);
          } while (bVar9);
          if (bVar9) {
            if (pcVar5 != (client_sprite_s *)0x0) {
              __sprintf_chk(local_a0,1,0x80,"sprites/%s.spr",pcVar5->szSprite);
              HVar2 = (*gEngfuncs.pfnSPR_Load)(local_a0);
              pWeapon->hCrosshair = HVar2;
              (pWeapon->rcCrosshair).left = (pcVar5->rc).left;
              (pWeapon->rcCrosshair).right = (pcVar5->rc).right;
              (pWeapon->rcCrosshair).top = (pcVar5->rc).top;
              (pWeapon->rcCrosshair).bottom = (pcVar5->rc).bottom;
              goto LAB_000624c3;
            }
            break;
          }
        }
        pcVar5 = pcVar5 + 1;
      }
      pWeapon->hCrosshair = 0;
LAB_000624c3:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_sprite_t * p@[???] */
      local_b8 = local_a4 + -1;
      iVar3 = local_b8;
      pcVar5 = pcVar1;
      if (local_a4 != 0) {
        do {
          if (iVar6 == pcVar5->iRes) {
            iVar4 = 8;
            bVar9 = true;
            pcVar7 = "autoaim";
            pcVar8 = pcVar5;
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pcVar7 == pcVar8->szName[0];
              pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
              pcVar8 = (client_sprite_s *)((int)pcVar8 + (uint)bVar10 * -2 + 1);
            } while (bVar9);
            if (bVar9) {
              if (pcVar5 != (client_sprite_s *)0x0) {
                __sprintf_chk(local_a0,1,0x80,"sprites/%s.spr",pcVar5->szSprite);
                HVar2 = (*gEngfuncs.pfnSPR_Load)(local_a0);
                pWeapon->hAutoaim = HVar2;
                (pWeapon->rcAutoaim).left = (pcVar5->rc).left;
                (pWeapon->rcAutoaim).right = (pcVar5->rc).right;
                (pWeapon->rcAutoaim).top = (pcVar5->rc).top;
                (pWeapon->rcAutoaim).bottom = (pcVar5->rc).bottom;
                local_b8 = local_a4 + -1;
                goto LAB_0006259a;
              }
              break;
            }
          }
          iVar3 = iVar3 + -1;
          pcVar5 = pcVar5 + 1;
        } while (iVar3 != -1);
      }
      pWeapon->hAutoaim = 0;
LAB_0006259a:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_sprite_t * p@[???] */
      iVar3 = local_b8;
      pcVar5 = pcVar1;
      if (local_a4 != 0) {
        do {
          if (iVar6 == pcVar5->iRes) {
            iVar4 = 5;
            bVar9 = true;
            pcVar7 = "zoom";
            pcVar8 = pcVar5;
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pcVar7 == pcVar8->szName[0];
              pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
              pcVar8 = (client_sprite_s *)((int)pcVar8 + (uint)bVar10 * -2 + 1);
            } while (bVar9);
            if (bVar9) {
              if (pcVar5 != (client_sprite_s *)0x0) {
                __sprintf_chk(local_a0,1,0x80,"sprites/%s.spr",pcVar5->szSprite);
                local_b0 = (*gEngfuncs.pfnSPR_Load)(local_a0);
                pWeapon->hZoomedCrosshair = local_b0;
                (pWeapon->rcZoomedCrosshair).left = (pcVar5->rc).left;
                (pWeapon->rcZoomedCrosshair).right = (pcVar5->rc).right;
                (pWeapon->rcZoomedCrosshair).top = (pcVar5->rc).top;
                (pWeapon->rcZoomedCrosshair).bottom = (pcVar5->rc).bottom;
                local_b8 = local_a4 + -1;
                goto LAB_00062676;
              }
              break;
            }
          }
          iVar3 = iVar3 + -1;
          pcVar5 = pcVar5 + 1;
        } while (iVar3 != -1);
      }
      local_b0 = pWeapon->hCrosshair;
      pWeapon->hZoomedCrosshair = local_b0;
      (pWeapon->rcZoomedCrosshair).left = (pWeapon->rcCrosshair).left;
      (pWeapon->rcZoomedCrosshair).right = (pWeapon->rcCrosshair).right;
      (pWeapon->rcZoomedCrosshair).top = (pWeapon->rcCrosshair).top;
      (pWeapon->rcZoomedCrosshair).bottom = (pWeapon->rcCrosshair).bottom;
LAB_00062676:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_sprite_t * p@[???] */
      iVar3 = local_b8;
      pcVar5 = pcVar1;
      if (local_a4 != 0) {
        do {
          if (iVar6 == pcVar5->iRes) {
            iVar4 = 0xd;
            bVar9 = true;
            pcVar7 = "zoom_autoaim";
            pcVar8 = pcVar5;
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pcVar7 == pcVar8->szName[0];
              pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
              pcVar8 = (client_sprite_s *)((int)pcVar8 + (uint)bVar10 * -2 + 1);
            } while (bVar9);
            if (bVar9) {
              if (pcVar5 != (client_sprite_s *)0x0) {
                __sprintf_chk(local_a0,1,0x80,"sprites/%s.spr",pcVar5->szSprite);
                HVar2 = (*gEngfuncs.pfnSPR_Load)(local_a0);
                pWeapon->hZoomedAutoaim = HVar2;
                (pWeapon->rcZoomedAutoaim).left = (pcVar5->rc).left;
                (pWeapon->rcZoomedAutoaim).right = (pcVar5->rc).right;
                (pWeapon->rcZoomedAutoaim).top = (pcVar5->rc).top;
                (pWeapon->rcZoomedAutoaim).bottom = (pcVar5->rc).bottom;
                local_b8 = local_a4 + -1;
                goto LAB_0006274a;
              }
              break;
            }
          }
          iVar3 = iVar3 + -1;
          pcVar5 = pcVar5 + 1;
        } while (iVar3 != -1);
      }
      pWeapon->hZoomedAutoaim = local_b0;
      (pWeapon->rcZoomedAutoaim).left = (pWeapon->rcZoomedCrosshair).left;
      (pWeapon->rcZoomedAutoaim).right = (pWeapon->rcZoomedCrosshair).right;
      (pWeapon->rcZoomedAutoaim).top = (pWeapon->rcZoomedCrosshair).top;
      (pWeapon->rcZoomedAutoaim).bottom = (pWeapon->rcZoomedCrosshair).bottom;
LAB_0006274a:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_sprite_t * p@[???] */
      iVar3 = local_b8;
      pcVar5 = pcVar1;
      if (local_a4 != 0) {
        do {
          if (iVar6 == pcVar5->iRes) {
            iVar4 = 7;
            bVar9 = true;
            pcVar7 = "weapon";
            pcVar8 = pcVar5;
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pcVar7 == pcVar8->szName[0];
              pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
              pcVar8 = (client_sprite_s *)((int)pcVar8 + (uint)bVar10 * -2 + 1);
            } while (bVar9);
            if (bVar9) {
              if (pcVar5 != (client_sprite_s *)0x0) {
                __sprintf_chk(local_a0,1,0x80,"sprites/%s.spr",pcVar5->szSprite);
                HVar2 = (*gEngfuncs.pfnSPR_Load)(local_a0);
                iVar3 = (pWeapon->rcActive).top;
                pWeapon->hInactive = HVar2;
                (pWeapon->rcInactive).left = (pcVar5->rc).left;
                (pWeapon->rcInactive).right = (pcVar5->rc).right;
                (pWeapon->rcInactive).top = (pcVar5->rc).top;
                (pWeapon->rcInactive).bottom = (pcVar5->rc).bottom;
                iVar3 = (pWeapon->rcActive).bottom - iVar3;
                if (iVar3 < gHR.iHistoryGap) {
                  iVar3 = gHR.iHistoryGap;
                }
                local_b8 = local_a4 + -1;
                gHR.iHistoryGap = iVar3;
                goto LAB_00062840;
              }
              break;
            }
          }
          iVar3 = iVar3 + -1;
          pcVar5 = pcVar5 + 1;
        } while (iVar3 != -1);
      }
      pWeapon->hInactive = 0;
LAB_00062840:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_sprite_t * p@[???] */
      iVar3 = local_b8;
      pcVar5 = pcVar1;
      if (local_a4 != 0) {
        do {
          if (iVar6 == pcVar5->iRes) {
            iVar4 = 9;
            bVar9 = true;
            pcVar7 = "weapon_s";
            pcVar8 = pcVar5;
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pcVar7 == pcVar8->szName[0];
              pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
              pcVar8 = (client_sprite_s *)((int)pcVar8 + (uint)bVar10 * -2 + 1);
            } while (bVar9);
            if (bVar9) {
              if (pcVar5 != (client_sprite_s *)0x0) {
                __sprintf_chk(local_a0,1,0x80,"sprites/%s.spr",pcVar5->szSprite);
                HVar2 = (*gEngfuncs.pfnSPR_Load)(local_a0);
                pWeapon->hActive = HVar2;
                (pWeapon->rcActive).left = (pcVar5->rc).left;
                (pWeapon->rcActive).right = (pcVar5->rc).right;
                (pWeapon->rcActive).top = (pcVar5->rc).top;
                (pWeapon->rcActive).bottom = (pcVar5->rc).bottom;
                local_b8 = local_a4 + -1;
                goto LAB_0006291a;
              }
              break;
            }
          }
          iVar3 = iVar3 + -1;
          pcVar5 = pcVar5 + 1;
        } while (iVar3 != -1);
      }
      pWeapon->hActive = 0;
LAB_0006291a:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_sprite_t * p@[???] */
      iVar3 = local_b8;
      pcVar5 = pcVar1;
      if (local_a4 != 0) {
        do {
          if (iVar6 == pcVar5->iRes) {
            iVar4 = 5;
            bVar9 = true;
            pcVar7 = "ammo";
            pcVar8 = pcVar5;
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pcVar7 == pcVar8->szName[0];
              pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
              pcVar8 = (client_sprite_s *)((int)pcVar8 + (uint)bVar10 * -2 + 1);
            } while (bVar9);
            if (bVar9) {
              if (pcVar5 != (client_sprite_s *)0x0) {
                __sprintf_chk(local_a0,1,0x80,"sprites/%s.spr",pcVar5->szSprite);
                HVar2 = (*gEngfuncs.pfnSPR_Load)(local_a0);
                iVar3 = (pWeapon->rcActive).top;
                pWeapon->hAmmo = HVar2;
                (pWeapon->rcAmmo).left = (pcVar5->rc).left;
                (pWeapon->rcAmmo).right = (pcVar5->rc).right;
                (pWeapon->rcAmmo).top = (pcVar5->rc).top;
                (pWeapon->rcAmmo).bottom = (pcVar5->rc).bottom;
                iVar3 = (pWeapon->rcActive).bottom - iVar3;
                if (iVar3 < gHR.iHistoryGap) {
                  iVar3 = gHR.iHistoryGap;
                }
                local_c0 = local_a4;
                local_b8 = local_a4 + -1;
                gHR.iHistoryGap = iVar3;
                goto LAB_00062a0c;
              }
              break;
            }
          }
          iVar3 = iVar3 + -1;
          pcVar5 = pcVar5 + 1;
        } while (iVar3 != -1);
      }
      pWeapon->hAmmo = 0;
      local_c0 = local_a4;
LAB_00062a0c:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_sprite_t * p@[???] */
      if (local_c0 != 0) {
        do {
          if (iVar6 == pcVar1->iRes) {
            iVar3 = 6;
            bVar9 = true;
            pcVar7 = "ammo2";
            pcVar5 = pcVar1;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar9 = *pcVar7 == pcVar5->szName[0];
              pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
              pcVar5 = (client_sprite_s *)((int)pcVar5 + (uint)bVar10 * -2 + 1);
            } while (bVar9);
            if (bVar9) {
              if (pcVar1 != (client_sprite_s *)0x0) {
                __sprintf_chk(local_a0,1,0x80,"sprites/%s.spr",pcVar1->szSprite);
                HVar2 = (*gEngfuncs.pfnSPR_Load)(local_a0);
                pWeapon->hAmmo2 = HVar2;
                (pWeapon->rcAmmo2).left = (pcVar1->rc).left;
                (pWeapon->rcAmmo2).right = (pcVar1->rc).right;
                (pWeapon->rcAmmo2).top = (pcVar1->rc).top;
                iVar3 = (pWeapon->rcActive).top;
                (pWeapon->rcAmmo2).bottom = (pcVar1->rc).bottom;
                iVar3 = (pWeapon->rcActive).bottom - iVar3;
                if (iVar3 < gHR.iHistoryGap) {
                  iVar3 = gHR.iHistoryGap;
                }
                goto LAB_00062af3;
              }
              break;
            }
          }
          local_b8 = local_b8 + -1;
          pcVar1 = pcVar1 + 1;
        } while (local_b8 != -1);
      }
      pWeapon->hAmmo2 = 0;
      iVar3 = gHR.iHistoryGap;
    }
  }
LAB_00062af3:
  gHR.iHistoryGap = iVar3;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// WeaponsResource::GetFirstPos  @ 00062db0  (line 207)

/* DWARF original prototype: WEAPON * GetFirstPos(WeaponsResource * this, int iSlot) */

WEAPON * __thiscall WeaponsResource::GetFirstPos(WeaponsResource *this,int iSlot)

{
  WEAPON *pWVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: WEAPON * pret@[???] */
                    /* Unresolved local var: int i@[???] */
  iVar3 = 0;
  while( true ) {
    pWVar1 = this->rgSlots[iSlot][iVar3];
    if ((pWVar1 != (WEAPON *)0x0) &&
       ((((pWVar1->iMax1 == -1 || (iVar2 = pWVar1->iAmmoType, iVar2 == -1)) || (0 < pWVar1->iClip))
        || ((((-1 < iVar2 && (this->riAmmo[iVar2] != 0)) ||
             ((-1 < pWVar1->iAmmo2Type && (this->riAmmo[pWVar1->iAmmo2Type] != 0)))) ||
            ((pWVar1->iFlags & 1) != 0)))))) break;
    iVar3 = iVar3 + 1;
    if (iVar3 == 5) {
      return (WEAPON *)0x0;
    }
  }
  return pWVar1;
}


// WeaponsResource::GetNextActivePos  @ 00062e30  (line 224)

/* DWARF original prototype: WEAPON * GetNextActivePos(WeaponsResource * this, int iSlot, int
   iSlotPos) */

WEAPON * __thiscall WeaponsResource::GetNextActivePos(WeaponsResource *this,int iSlot,int iSlotPos)

{
  WEAPON *pWVar1;
  int iVar2;
  
                    /* Unresolved local var: WEAPON * p@[???] */
  do {
    if (4 < iSlotPos) {
      return (WEAPON *)0x0;
    }
    while( true ) {
      if (4 < iSlot) {
        return (WEAPON *)0x0;
      }
      iSlotPos = iSlotPos + 1;
      pWVar1 = *(WEAPON **)(iSlot * 0x18 + 0xf8660 + iSlotPos * 4);
      if (pWVar1 == (WEAPON *)0x0) break;
      if ((((pWVar1->iMax1 == -1) || (iVar2 = pWVar1->iAmmoType, iVar2 == -1)) ||
          (0 < pWVar1->iClip)) ||
         ((((-1 < iVar2 && (gWR.riAmmo[iVar2] != 0)) ||
           ((-1 < pWVar1->iAmmo2Type && (gWR.riAmmo[pWVar1->iAmmo2Type] != 0)))) ||
          ((pWVar1->iFlags & 1) != 0)))) {
        return pWVar1;
      }
      if (4 < iSlotPos) {
        return (WEAPON *)0x0;
      }
    }
  } while( true );
}


// __MsgFunc_CurWeapon  @ 00061f90  (line 241)

int __MsgFunc_CurWeapon(char *pszName,int iSize,void *pbuf)

{
  WEAPON *pWVar1;
  wrect_t wVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int fOnTarget@[???]
                       Unresolved local var: int iState@[???]
                       Unresolved local var: int iId@[???]
                       Unresolved local var: int iClip@[???]
                       Unresolved local var: WEAPON * pWeapon@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar3 = READ_BYTE();
  iVar4 = READ_CHAR();
  iVar5 = READ_CHAR();
  if (iVar4 < 1) {
    wVar2.right = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.right;
    wVar2.left = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.left;
    wVar2.top = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.top;
    wVar2.bottom = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.bottom;
    (*gEngfuncs.pfnSetCrosshair)(0,wVar2,0,0,0);
    iVar5 = 0;
  }
  else {
    if (g_iUser1 != 4) {
      gHUD.m_fPlayerDead = 0;
    }
    if (iVar5 < -1) {
      iVar5 = -iVar5;
    }
    pWVar1 = gWR.rgWeapons + iVar4;
    gWR.rgWeapons[iVar4].iClip = iVar5;
    iVar5 = 1;
    if (iVar3 != 0) {
      gHUD.m_Ammo.m_pWeapon = pWVar1;
      if (gHUD.m_iFOV < 0x5a) {
        if ((iVar3 < 2) || (iVar5 = gWR.rgWeapons[iVar4].hZoomedAutoaim, iVar5 == 0)) {
          (*gEngfuncs.pfnSetCrosshair)
                    (gWR.rgWeapons[iVar4].hZoomedCrosshair,gWR.rgWeapons[iVar4].rcZoomedCrosshair,
                     0xff,0xff,0xff);
        }
        else {
          (*gEngfuncs.pfnSetCrosshair)(iVar5,gWR.rgWeapons[iVar4].rcZoomedAutoaim,0xff,0xff,0xff);
        }
      }
      else if ((iVar3 < 2) || (iVar5 = gWR.rgWeapons[iVar4].hAutoaim, iVar5 == 0)) {
        (*gEngfuncs.pfnSetCrosshair)
                  (gWR.rgWeapons[iVar4].hCrosshair,gWR.rgWeapons[iVar4].rcCrosshair,0xff,0xff,0xff);
      }
      else {
        (*gEngfuncs.pfnSetCrosshair)(iVar5,gWR.rgWeapons[iVar4].rcAutoaim,0xff,0xff,0xff);
      }
      gHUD.m_Ammo.super_CHudBase.m_iFlags = gHUD.m_Ammo.super_CHudBase.m_iFlags | 1;
      iVar5 = 1;
      gHUD.m_Ammo.m_fFade = 200.0;
    }
  }
  return iVar5;
}


// __MsgFunc_WeaponList  @ 00064ba0  (line 242)

int __MsgFunc_WeaponList(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHudAmmo::MsgFunc_WeaponList(&gHUD.m_Ammo,pszName,iSize,pbuf);
  return iVar1;
}


// __MsgFunc_AmmoX  @ 000614d0  (line 243)

int __MsgFunc_AmmoX(char *pszName,int iSize,void *pbuf)

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


// __MsgFunc_AmmoPickup  @ 00061730  (line 244)

int __MsgFunc_AmmoPickup(char *pszName,int iSize,void *pbuf)

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


// __MsgFunc_WeapPickup  @ 00061610  (line 245)

int __MsgFunc_WeapPickup(char *pszName,int iSize,void *pbuf)

{
  int iId;
  
                    /* Unresolved local var: int iIndex@[???] */
  BEGIN_READ(pbuf,iSize);
  iId = READ_BYTE();
  HistoryResource::AddToHistory(&gHR,2,iId,0);
  return 1;
}


// __MsgFunc_HideWeapon  @ 00061d50  (line 246)

int __MsgFunc_HideWeapon(char *pszName,int iSize,void *pbuf)

{
  wrect_t wVar1;
  int iVar2;
  
  BEGIN_READ(pbuf,iSize);
  gHUD.m_iHideHUDDisplay = READ_BYTE();
  iVar2 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar2 == 0) {
    if ((gHUD.m_iHideHUDDisplay & 5U) != 0) {
      gpActiveSel = (WEAPON *)0x0;
      wVar1.right = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.right;
      wVar1.left = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.left;
      wVar1.top = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.top;
      wVar1.bottom = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.bottom;
      (*gEngfuncs.pfnSetCrosshair)(0,wVar1,0,0,0);
      return 1;
    }
    if (gHUD.m_Ammo.m_pWeapon != (WEAPON *)0x0) {
      (*gEngfuncs.pfnSetCrosshair)
                ((gHUD.m_Ammo.m_pWeapon)->hCrosshair,(gHUD.m_Ammo.m_pWeapon)->rcCrosshair,0xff,0xff,
                 0xff);
    }
  }
  return 1;
}


// __MsgFunc_ItemPickup  @ 00061660  (line 247)

int __MsgFunc_ItemPickup(char *pszName,int iSize,void *pbuf)

{
  char *szName;
  
                    /* Unresolved local var: char * szName@[???] */
  BEGIN_READ(pbuf,iSize);
  szName = READ_STRING();
  HistoryResource::AddToHistory(&gHR,3,szName,0);
  return 1;
}


// __CmdFunc_Slot1  @ 00063790  (line 249)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot1(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,0), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 0)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[0][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,0);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,1);
    }
  }
  return;
}


// __CmdFunc_Slot2  @ 000631b0  (line 250)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot2(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,1), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 1)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[1][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,1);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,2);
    }
  }
  return;
}


// __CmdFunc_Slot3  @ 000634a0  (line 251)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot3(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,2), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 2)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[2][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,2);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,3);
    }
  }
  return;
}


// __CmdFunc_Slot4  @ 00063a80  (line 252)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot4(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,3), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 3)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[3][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,3);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,4);
    }
  }
  return;
}


// __CmdFunc_Slot5  @ 00062ec0  (line 253)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot5(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,4), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 4)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[4][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,4);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,5);
    }
  }
  return;
}


// __CmdFunc_Slot6  @ 00063d70  (line 254)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot6(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,5), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 5)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[5][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,5);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,6);
    }
  }
  return;
}


// __CmdFunc_Slot7  @ 00061ea0  (line 255)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot7(void)

{
  bool bVar1;
  
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar1 = TeamFortressViewport::SlotInput(gViewPort,6), bVar1)) {
    return;
  }
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
  if (gHUD.m_Menu.m_fMenuDisplayed != 0) {
    CHudMenu::SelectMenuItem(&gHUD.m_Menu,7);
  }
  return;
}


// __CmdFunc_Slot8  @ 00061ef0  (line 256)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot8(void)

{
  bool bVar1;
  
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar1 = TeamFortressViewport::SlotInput(gViewPort,7), bVar1)) {
    return;
  }
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
  if (gHUD.m_Menu.m_fMenuDisplayed != 0) {
    CHudMenu::SelectMenuItem(&gHUD.m_Menu,8);
  }
  return;
}


// __CmdFunc_Slot9  @ 00061f40  (line 257)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot9(void)

{
  bool bVar1;
  
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar1 = TeamFortressViewport::SlotInput(gViewPort,8), bVar1)) {
    return;
  }
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
  if (gHUD.m_Menu.m_fMenuDisplayed != 0) {
    CHudMenu::SelectMenuItem(&gHUD.m_Menu,9);
  }
  return;
}


// __CmdFunc_Slot10  @ 00061e50  (line 258)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot10(void)

{
  bool bVar1;
  
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar1 = TeamFortressViewport::SlotInput(gViewPort,9), bVar1)) {
    return;
  }
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
  if (gHUD.m_Menu.m_fMenuDisplayed != 0) {
    CHudMenu::SelectMenuItem(&gHUD.m_Menu,10);
  }
  return;
}


// __CmdFunc_Close  @ 00061780  (line 259)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Close(void)

{
  if (gpActiveSel != (WEAPON *)0x0) {
    gpLastSel = gpActiveSel;
    gpActiveSel = (WEAPON *)0x0;
    (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudoff.wav",1.0);
    return;
  }
  (*gEngfuncs.pfnClientCmd)("escape");
  return;
}


// CHudAmmo::Init  @ 000617d0  (line 270)

/* DWARF original prototype: int Init(CHudAmmo * this) */

int __thiscall CHudAmmo::Init(CHudAmmo *this)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  uint uVar3;
  uint uVar4;
  
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  (*gEngfuncs.pfnHookUserMsg)("CurWeapon",__MsgFunc_CurWeapon);
  (*gEngfuncs.pfnHookUserMsg)("WeaponList",__MsgFunc_WeaponList);
  (*gEngfuncs.pfnHookUserMsg)("AmmoPickup",__MsgFunc_AmmoPickup);
  (*gEngfuncs.pfnHookUserMsg)("WeapPickup",__MsgFunc_WeapPickup);
  (*gEngfuncs.pfnHookUserMsg)("ItemPickup",__MsgFunc_ItemPickup);
  (*gEngfuncs.pfnHookUserMsg)("HideWeapon",__MsgFunc_HideWeapon);
  (*gEngfuncs.pfnHookUserMsg)("AmmoX",__MsgFunc_AmmoX);
  (*gEngfuncs.pfnAddCommand)("slot1",__CmdFunc_Slot1);
  (*gEngfuncs.pfnAddCommand)("slot2",__CmdFunc_Slot2);
  (*gEngfuncs.pfnAddCommand)("slot3",__CmdFunc_Slot3);
  (*gEngfuncs.pfnAddCommand)("slot4",__CmdFunc_Slot4);
  (*gEngfuncs.pfnAddCommand)("slot5",__CmdFunc_Slot5);
  (*gEngfuncs.pfnAddCommand)("slot6",__CmdFunc_Slot6);
  (*gEngfuncs.pfnAddCommand)("slot7",__CmdFunc_Slot7);
  (*gEngfuncs.pfnAddCommand)("slot8",__CmdFunc_Slot8);
  (*gEngfuncs.pfnAddCommand)("slot9",__CmdFunc_Slot9);
  (*gEngfuncs.pfnAddCommand)("slot10",__CmdFunc_Slot10);
  (*gEngfuncs.pfnAddCommand)("cancelselect",__CmdFunc_Close);
  (*gEngfuncs.pfnAddCommand)("invnext",__CmdFunc_NextWeapon);
  (*gEngfuncs.pfnAddCommand)("invprev",__CmdFunc_PrevWeapon);
  p_Var2 = (this->super_CHudBase)._vptr_CHudBase[6];
  if (p_Var2 == Reset) {
    this->m_fFade = 0.0;
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 | 1;
    gHUD.m_iHideHUDDisplay = 0;
    gWR.iOldWeaponBits = 0;
    gpActiveSel = (WEAPON *)0x0;
    uVar4 = 0;
    do {
      *(undefined4 *)((int)gWR.rgSlots[0] + uVar4) = 0;
      uVar3 = uVar4 + 8;
      *(undefined4 *)((int)gWR.rgSlots[0] + uVar4 + 4) = 0;
      uVar4 = uVar3;
    } while (uVar3 < 0x90);
    uVar4 = 0;
    do {
      *(undefined4 *)((int)gWR.riAmmo + uVar4) = 0;
      uVar3 = uVar4 + 8;
      *(undefined4 *)((int)gWR.riAmmo + uVar4 + 4) = 0;
      uVar4 = uVar3;
    } while (uVar3 < 0x80);
    uVar4 = 0;
    do {
      *(undefined4 *)((int)&gHR.rgAmmoHistory[0].type + uVar4) = 0;
      uVar3 = uVar4 + 8;
      *(undefined4 *)((int)&gHR.rgAmmoHistory[0].DisplayTime + uVar4) = 0;
      uVar4 = uVar3;
    } while (uVar3 < 0xc0);
  }
  else {
    (*p_Var2)(this);
  }
  (*gEngfuncs.pfnRegisterVariable)("hud_drawhistory_time","5",0);
  (*gEngfuncs.pfnRegisterVariable)("hud_fastswitch","0",1);
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  memset(&gWR,0,0x2900);
  gWR.iOldWeaponBits = 0;
  uVar4 = 0;
  do {
    *(undefined4 *)((int)gWR.rgSlots[0] + uVar4) = 0;
    uVar3 = uVar4 + 8;
    *(undefined4 *)((int)gWR.rgSlots[0] + uVar4 + 4) = 0;
    uVar4 = uVar3;
  } while (uVar3 < 0x90);
  uVar4 = 0;
  do {
    *(undefined4 *)((int)gWR.riAmmo + uVar4) = 0;
    uVar3 = uVar4 + 8;
    *(undefined4 *)((int)gWR.riAmmo + uVar4 + 4) = 0;
    uVar4 = uVar3;
  } while (uVar3 < 0x80);
  uVar4 = 0;
  do {
    *(undefined4 *)((int)&gHR.rgAmmoHistory[0].type + uVar4) = 0;
    uVar3 = uVar4 + 8;
    *(undefined4 *)((int)&gHR.rgAmmoHistory[0].DisplayTime + uVar4) = 0;
    uVar4 = uVar3;
  } while (uVar3 < 0xc0);
  return 1;
}


// CHudAmmo::Reset  @ 000616b0  (line 309)

/* DWARF original prototype: void Reset(CHudAmmo * this) */

void __thiscall CHudAmmo::Reset(CHudAmmo *this)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  this->m_fFade = 0.0;
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  gpActiveSel = (WEAPON *)0x0;
  gHUD.m_iHideHUDDisplay = 0;
  gWR.iOldWeaponBits = 0;
  uVar3 = 0;
  do {
    *(undefined4 *)((int)gWR.rgSlots[0] + uVar3) = 0;
    uVar2 = uVar3 + 8;
    *(undefined4 *)((int)gWR.rgSlots[0] + uVar3 + 4) = 0;
    uVar3 = uVar2;
  } while (uVar2 < 0x90);
  uVar3 = 0;
  do {
    *(undefined4 *)((int)gWR.riAmmo + uVar3) = 0;
    uVar2 = uVar3 + 8;
    *(undefined4 *)((int)gWR.riAmmo + uVar3 + 4) = 0;
    uVar3 = uVar2;
  } while (uVar2 < 0x80);
  uVar3 = 0;
  do {
    *(undefined4 *)((int)&gHR.rgAmmoHistory[0].type + uVar3) = 0;
    uVar2 = uVar3 + 8;
    *(undefined4 *)((int)&gHR.rgAmmoHistory[0].DisplayTime + uVar3) = 0;
    uVar3 = uVar2;
  } while (uVar2 < 0xc0);
  return;
}


// CHudAmmo::VidInit  @ 00062ca0  (line 321)

/* DWARF original prototype: int VidInit(CHudAmmo * this) */

int __thiscall CHudAmmo::VidInit(CHudAmmo *this)

{
  WEAPON *pWVar1;
  int iVar2;
  wrect_t *pwVar3;
  WeaponsResource *pWeapon;
  
                    /* Unresolved local var: int nScale@[???] */
  iVar2 = CHud::GetSpriteIndex(&gHUD,"bucket1");
  this->m_HUD_bucket0 = iVar2;
  iVar2 = CHud::GetSpriteIndex(&gHUD,"selection");
  ghsprBuckets = 0;
  this->m_HUD_selection = iVar2;
  iVar2 = this->m_HUD_bucket0;
  if (-1 < iVar2) {
    ghsprBuckets = gHUD.m_rghSprites[iVar2];
  }
  pwVar3 = gHUD.m_rgrcRects + iVar2;
  giBucketWidth = pwVar3->right - pwVar3->left;
  giBucketHeight = pwVar3->bottom - pwVar3->top;
  pWeapon = &gWR;
  iVar2 = giBucketHeight;
  if (giBucketHeight <= gHR.iHistoryGap) {
    iVar2 = gHR.iHistoryGap;
  }
  do {
    while (gHR.iHistoryGap = iVar2, pWeapon->rgWeapons[0].iId == 0) {
      pWeapon = (WeaponsResource *)(pWeapon->rgWeapons + 1);
                    /* Unresolved local var: int i@[???] */
      iVar2 = gHR.iHistoryGap;
      if (pWeapon == (WeaponsResource *)gWR.rgSlots) goto LAB_00062d6e;
    }
    pWVar1 = pWeapon->rgWeapons;
    WeaponsResource::LoadWeaponSprites(&gWR,pWeapon->rgWeapons);
    pWeapon = (WeaponsResource *)(pWVar1 + 1);
    iVar2 = gHR.iHistoryGap;
  } while ((WeaponsResource *)(pWVar1 + 1) != (WeaponsResource *)gWR.rgSlots);
LAB_00062d6e:
  giABWidth = 0x14;
  if (gHUD.m_scrinfo.iWidth < 0x280) {
    giABWidth = 10;
  }
  giABHeight = (uint)(0x27f < gHUD.m_scrinfo.iWidth) * 2 + 2;
  return 1;
}


// CHudAmmo::Think  @ 00061520  (line 359)

/* DWARF original prototype: void Think(CHudAmmo * this) */

void __thiscall CHudAmmo::Think(CHudAmmo *this)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  WEAPON *pWVar4;
  
  iVar3 = gHUD.m_iWeaponBits;
  if (gHUD.m_fPlayerDead == 0) {
    if (gHUD.m_iWeaponBits != gWR.iOldWeaponBits) {
      gWR.iOldWeaponBits = gHUD.m_iWeaponBits;
      pWVar4 = (WEAPON *)0xf8518;
      do {
        while (pcVar1 = pWVar4->szName,
              (iVar3 >> ((byte)*(int *)(pWVar4->szName + 0x9c) & 0x1f) & 1U) != 0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: WEAPON * p@[???] */
          gWR.rgSlots[*(int *)(pcVar1 + 0x90)][*(int *)(pWVar4->szName + 0x94)] = pWVar4;
          pWVar4 = pWVar4 + -1;
          if ((WeaponsResource *)pWVar4 == &gWR) goto LAB_000615a2;
        }
        pcVar2 = pWVar4->szName;
        pWVar4 = pWVar4 + -1;
        gWR.rgSlots[*(int *)(pcVar1 + 0x90)][*(int *)(pcVar2 + 0x94)] = (WEAPON *)0x0;
      } while ((WeaponsResource *)pWVar4 != &gWR);
    }
LAB_000615a2:
    if ((gpActiveSel != (WEAPON *)0x0) && ((gHUD.m_iKeyBits & 1U) != 0)) {
      pWVar4 = gpActiveSel;
      if (gpActiveSel != (WEAPON *)0x1) {
        (*gEngfuncs.pfnServerCmd)(gpActiveSel->szName);
        g_weaponselect = gpActiveSel->iId;
        pWVar4 = gpActiveSel;
      }
      gHUD.m_iKeyBits = gHUD.m_iKeyBits & 0xfffffffe;
      gpActiveSel = (WEAPON *)0x0;
      gpLastSel = pWVar4;
      (*gEngfuncs.pfnPlaySoundByName)("common/wpn_select.wav",1.0);
    }
  }
  return;
}


// WeaponsResource::GetAmmoPicFromWeapon  @ 00064060  (line 406)

/* DWARF original prototype: HANDLE_SPRITE * GetAmmoPicFromWeapon(WeaponsResource * this, int
   iAmmoId, wrect_t * rect) */

HANDLE_SPRITE * __thiscall
WeaponsResource::GetAmmoPicFromWeapon(WeaponsResource *this,int iAmmoId,wrect_t *rect)

{
  int *piVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  piVar1 = &this->rgWeapons[0].iAmmoType;
  while( true ) {
    if (*piVar1 == iAmmoId) {
      rect->left = this->rgWeapons[iVar2].rcAmmo.left;
      rect->right = this->rgWeapons[iVar2].rcAmmo.right;
      rect->top = this->rgWeapons[iVar2].rcAmmo.top;
      rect->bottom = this->rgWeapons[iVar2].rcAmmo.bottom;
      return &this->rgWeapons[iVar2].hAmmo;
    }
    if (iAmmoId == piVar1[1]) break;
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 0x52;
    if (iVar2 == 0x20) {
      return (HANDLE_SPRITE *)0x0;
    }
  }
  rect->left = this->rgWeapons[iVar2].rcAmmo2.left;
  rect->right = this->rgWeapons[iVar2].rcAmmo2.right;
  rect->top = this->rgWeapons[iVar2].rcAmmo2.top;
  rect->bottom = this->rgWeapons[iVar2].rcAmmo2.bottom;
  return &this->rgWeapons[iVar2].hAmmo2;
}


// WeaponsResource::SelectSlot  @ 00064110  (line 428)

/* DWARF original prototype: void SelectSlot(WeaponsResource * this, int iSlot, int fAdvance, int
   iDirection) */

void __thiscall
WeaponsResource::SelectSlot(WeaponsResource *this,int iSlot,int fAdvance,int iDirection)

{
  WEAPON *pWVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longdouble lVar5;
  
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
  if (((gHUD.m_Menu.m_fMenuDisplayed != 0) && (fAdvance == 0)) && (iDirection == 1)) {
    CHudMenu::SelectMenuItem(&gHUD.m_Menu,iSlot + 1);
    return;
  }
  if (5 < iSlot) {
    return;
  }
  if (gHUD.m_fPlayerDead != 0) {
    return;
  }
  if (((byte)gHUD.m_iHideHUDDisplay & 5) != 0) {
    return;
  }
  if (-1 < gHUD.m_iWeaponBits) {
    return;
  }
  if ((gHUD.m_iWeaponBits & 0x7fffffffU) == 0) {
    return;
  }
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
  lVar5 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
  if ((gpActiveSel < (WEAPON *)0x2) || (iSlot != gpActiveSel->iSlot)) {
    (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
    iVar4 = 0;
    do {
      pWVar1 = this->rgSlots[iSlot][iVar4];
      if ((pWVar1 != (WEAPON *)0x0) &&
         (((((pWVar1->iMax1 == -1 || (iVar2 = pWVar1->iAmmoType, iVar2 == -1)) ||
            ((0 < pWVar1->iClip || ((-1 < iVar2 && (this->riAmmo[iVar2] != 0)))))) ||
           ((-1 < pWVar1->iAmmo2Type && (this->riAmmo[pWVar1->iAmmo2Type] != 0)))) ||
          ((pWVar1->iFlags & 1) != 0)))) {
        if ((float)lVar5 == 0.0) {
          gpActiveSel = pWVar1;
          return;
        }
                    /* Unresolved local var: WEAPON * p2@[???] */
        iVar4 = pWVar1->iSlotPos;
        while( true ) {
          do {
                    /* Unresolved local var: WEAPON * p@[???] */
            if ((4 < iVar4) || (4 < pWVar1->iSlot)) {
              (*gEngfuncs.pfnServerCmd)(pWVar1->szName);
              g_weaponselect = pWVar1->iId;
              return;
            }
            iVar4 = iVar4 + 1;
            iVar2 = *(int *)(pWVar1->iSlot * 0x18 + 0xf8660 + iVar4 * 4);
          } while (iVar2 == 0);
          if (*(int *)(iVar2 + 0x88) == -1) {
            gpActiveSel = pWVar1;
            return;
          }
          iVar3 = *(int *)(iVar2 + 0x80);
          if (iVar3 == -1) break;
          if (0 < *(int *)(iVar2 + 0xa0)) {
            gpActiveSel = pWVar1;
            return;
          }
          if ((-1 < iVar3) && (gWR.riAmmo[iVar3] != 0)) {
            gpActiveSel = pWVar1;
            return;
          }
          if ((-1 < *(int *)(iVar2 + 0x84)) && (gWR.riAmmo[*(int *)(iVar2 + 0x84)] != 0)) {
            gpActiveSel = pWVar1;
            return;
          }
          if ((*(byte *)(iVar2 + 0x98) & 1) != 0) {
            gpActiveSel = pWVar1;
            return;
          }
        }
        gpActiveSel = pWVar1;
        return;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 5);
  }
  else {
    (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
    if (gpActiveSel != (WEAPON *)0x0) {
      iVar4 = gpActiveSel->iSlotPos;
                    /* Unresolved local var: WEAPON * p@[???] */
      while ((iVar4 < 5 && (gpActiveSel->iSlot < 5))) {
        iVar4 = iVar4 + 1;
        pWVar1 = *(WEAPON **)(gpActiveSel->iSlot * 0x18 + 0xf8660 + iVar4 * 4);
        if (pWVar1 != (WEAPON *)0x0) {
          if (pWVar1->iMax1 == -1) {
            gpActiveSel = pWVar1;
            return;
          }
          iVar2 = pWVar1->iAmmoType;
          if (iVar2 == -1) {
            gpActiveSel = pWVar1;
            return;
          }
          if (0 < pWVar1->iClip) {
            gpActiveSel = pWVar1;
            return;
          }
          if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
            gpActiveSel = pWVar1;
            return;
          }
          if ((-1 < pWVar1->iAmmo2Type) && (gWR.riAmmo[pWVar1->iAmmo2Type] != 0)) {
            gpActiveSel = pWVar1;
            return;
          }
          if ((pWVar1->iFlags & 1) != 0) {
            gpActiveSel = pWVar1;
            return;
          }
        }
      }
    }
    gpActiveSel = GetFirstPos(this,iSlot);
    if (gpActiveSel != (WEAPON *)0x0) {
      return;
    }
  }
  gpActiveSel = (WEAPON *)(uint)((float)lVar5 == 0.0);
  return;
}


// CHudAmmo::MsgFunc_AmmoX  @ 00064490  (line 498)

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


// CHudAmmo::MsgFunc_AmmoPickup  @ 000644e0  (line 510)

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


// CHudAmmo::MsgFunc_WeapPickup  @ 00064530  (line 522)

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


// CHudAmmo::MsgFunc_ItemPickup  @ 00064580  (line 533)

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


// CHudAmmo::MsgFunc_HideWeapon  @ 000645d0  (line 545)

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


// CHudAmmo::MsgFunc_CurWeapon  @ 000646d0  (line 574)

/* DWARF original prototype: int MsgFunc_CurWeapon(CHudAmmo * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudAmmo::MsgFunc_CurWeapon(CHudAmmo *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  wrect_t wVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int fOnTarget@[???]
                       Unresolved local var: int iState@[???]
                       Unresolved local var: int iId@[???]
                       Unresolved local var: int iClip@[???]
                       Unresolved local var: WEAPON * pWeapon@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar3 = READ_BYTE();
  iVar4 = READ_CHAR();
  iVar5 = READ_CHAR();
  if (iVar4 < 1) {
    wVar2.right = MsgFunc_HideWeapon::lexical_block_0::nullrc.right;
    wVar2.left = MsgFunc_HideWeapon::lexical_block_0::nullrc.left;
    wVar2.top = MsgFunc_HideWeapon::lexical_block_0::nullrc.top;
    wVar2.bottom = MsgFunc_HideWeapon::lexical_block_0::nullrc.bottom;
    (*gEngfuncs.pfnSetCrosshair)(0,wVar2,0,0,0);
    iVar5 = 0;
  }
  else {
    if (g_iUser1 != 4) {
      gHUD.m_fPlayerDead = 0;
    }
    if (iVar5 < -1) {
      iVar5 = -iVar5;
    }
    gWR.rgWeapons[iVar4].iClip = iVar5;
    iVar5 = 1;
    if (iVar3 != 0) {
      this->m_pWeapon = gWR.rgWeapons + iVar4;
      if (gHUD.m_iFOV < 0x5a) {
        if ((iVar3 < 2) || (iVar5 = gWR.rgWeapons[iVar4].hZoomedAutoaim, iVar5 == 0)) {
          (*gEngfuncs.pfnSetCrosshair)
                    (gWR.rgWeapons[iVar4].hZoomedCrosshair,gWR.rgWeapons[iVar4].rcZoomedCrosshair,
                     0xff,0xff,0xff);
        }
        else {
          (*gEngfuncs.pfnSetCrosshair)(iVar5,gWR.rgWeapons[iVar4].rcZoomedAutoaim,0xff,0xff,0xff);
        }
      }
      else {
        if ((iVar3 < 2) || (iVar5 = gWR.rgWeapons[iVar4].hAutoaim, iVar5 == 0)) {
          (*gEngfuncs.pfnSetCrosshair)
                    (gWR.rgWeapons[iVar4].hCrosshair,gWR.rgWeapons[iVar4].rcCrosshair,0xff,0xff,0xff
                    );
          piVar1 = &(this->super_CHudBase).m_iFlags;
          *piVar1 = *piVar1 | 1;
          this->m_fFade = 200.0;
          return 1;
        }
        (*gEngfuncs.pfnSetCrosshair)(iVar5,gWR.rgWeapons[iVar4].rcAutoaim,0xff,0xff,0xff);
      }
      piVar1 = &(this->super_CHudBase).m_iFlags;
      *piVar1 = *piVar1 | 1;
      this->m_fFade = 200.0;
      return 1;
    }
  }
  return iVar5;
}


// CHudAmmo::MsgFunc_WeaponList  @ 00064980  (line 650)

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
  int in_GS_OFFSET;
  char local_168 [4];
  undefined4 auStack_164 [30];
  undefined1 local_e9;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  uint local_d8;
  uint local_d4;
  int local_d0;
  uint local_cc;
  undefined4 local_c8;
  int local_20;
  
                    /* Unresolved local var: WEAPON Weapon@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BEGIN_READ(pbuf,iSize);
  __src = READ_STRING();
  strncpy(local_168,__src,0x80);
  local_e9 = 0;
  iVar4 = READ_CHAR();
  local_e8 = iVar4;
  local_e0 = READ_BYTE();
  if (local_e0 == 0xff) {
    local_e0 = -1;
  }
  iVar2 = local_e0;
  iVar5 = READ_CHAR();
  local_e4 = iVar5;
  local_dc = READ_BYTE();
  if (local_dc == 0xff) {
    local_dc = -1;
  }
  iVar3 = local_dc;
  uVar6 = READ_CHAR();
  local_d8 = uVar6;
  uVar7 = READ_CHAR();
  local_d4 = uVar7;
  uVar8 = READ_CHAR();
  local_cc = uVar8;
  local_d0 = READ_BYTE();
  local_c8 = 0;
  if ((((uVar8 < 0x20) && (uVar6 < 6)) && (uVar7 < 6)) &&
     ((iVar4 + 1U < 0x21 && (iVar5 + 1U < 0x21)))) {
    if (((iVar4 == -1) || (iVar4 = 0, iVar2 != 0)) && ((iVar5 == -1 || (iVar4 = 0, iVar3 != 0)))) {
      uVar6 = 0;
      do {
        uVar1 = *(undefined4 *)((int)auStack_164 + uVar6);
        *(undefined4 *)(gWR.rgWeapons[uVar8].szName + uVar6) =
             *(undefined4 *)((int)auStack_164 + (uVar6 - 4));
        *(undefined4 *)(uVar8 * 0x148 + 0xf5d64 + uVar6) = uVar1;
        uVar6 = uVar6 + 8;
      } while (uVar6 < 0x148);
      iVar4 = 1;
      WeaponsResource::LoadWeaponSprites(&gWR,gWR.rgWeapons + uVar8);
    }
  }
  else {
    iVar4 = 0;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}


// CHudAmmo::SlotInput  @ 00064bd0  (line 707)

/* DWARF original prototype: void SlotInput(CHudAmmo * this, int iSlot) */

void __thiscall CHudAmmo::SlotInput(CHudAmmo *this,int iSlot)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  WEAPON *pWVar5;
  longdouble lVar6;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,iSlot), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed != 0) {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,iSlot + 1);
      return;
    }
    if ((((iSlot < 6) && (gHUD.m_fPlayerDead == 0)) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
       ((gHUD.m_iWeaponBits < 0 && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)))) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
      lVar6 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
      if ((gpActiveSel < (WEAPON *)0x2) || (iSlot != gpActiveSel->iSlot)) {
        (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
        iVar4 = 0;
        do {
          pWVar5 = *(WEAPON **)(iSlot * 0x18 + 0xf8660 + iVar4 * 4);
          if ((pWVar5 != (WEAPON *)0x0) &&
             (((((pWVar5->iMax1 == -1 || (iVar1 = pWVar5->iAmmoType, iVar1 == -1)) ||
                ((0 < pWVar5->iClip || ((-1 < iVar1 && (gWR.riAmmo[iVar1] != 0)))))) ||
               ((-1 < pWVar5->iAmmo2Type && (gWR.riAmmo[pWVar5->iAmmo2Type] != 0)))) ||
              ((pWVar5->iFlags & 1) != 0)))) {
            if ((float)lVar6 == 0.0) {
              gpActiveSel = pWVar5;
              return;
            }
                    /* Unresolved local var: WEAPON * p2@[???] */
            iVar4 = pWVar5->iSlotPos;
            while( true ) {
              do {
                    /* Unresolved local var: WEAPON * p@[???] */
                if ((4 < iVar4) || (4 < pWVar5->iSlot)) {
                  (*gEngfuncs.pfnServerCmd)(pWVar5->szName);
                  g_weaponselect = pWVar5->iId;
                  return;
                }
                iVar4 = iVar4 + 1;
                iVar1 = *(int *)(pWVar5->iSlot * 0x18 + 0xf8660 + iVar4 * 4);
              } while (iVar1 == 0);
              if (*(int *)(iVar1 + 0x88) == -1) {
                gpActiveSel = pWVar5;
                return;
              }
              iVar2 = *(int *)(iVar1 + 0x80);
              if (iVar2 == -1) break;
              if (0 < *(int *)(iVar1 + 0xa0)) {
                gpActiveSel = pWVar5;
                return;
              }
              if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                gpActiveSel = pWVar5;
                return;
              }
              if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                gpActiveSel = pWVar5;
                return;
              }
              if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                gpActiveSel = pWVar5;
                return;
              }
            }
            gpActiveSel = pWVar5;
            return;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 != 5);
      }
      else {
        (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
        if ((gpActiveSel != (WEAPON *)0x0) &&
           (pWVar5 = WeaponsResource::GetNextActivePos
                               (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
           pWVar5 != (WEAPON *)0x0)) {
          gpActiveSel = pWVar5;
          return;
        }
        gpActiveSel = WeaponsResource::GetFirstPos(&gWR,iSlot);
        if (gpActiveSel != (WEAPON *)0x0) {
          return;
        }
      }
      if ((float)lVar6 == 0.0) {
        gpActiveSel = (WEAPON *)0x1;
      }
      else {
        gpActiveSel = (WEAPON *)0x0;
      }
    }
  }
  return;
}


// CHudAmmo::UserCmd_Slot1  @ 00064ec0  (line 715)

/* DWARF original prototype: void UserCmd_Slot1(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot1(CHudAmmo *this)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,0), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 0)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[0][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,0);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,1);
    }
  }
  return;
}


// CHudAmmo::UserCmd_Slot2  @ 000651b0  (line 720)

/* DWARF original prototype: void UserCmd_Slot2(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot2(CHudAmmo *this)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,1), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 1)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[1][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,1);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,2);
    }
  }
  return;
}


// CHudAmmo::UserCmd_Slot3  @ 000654a0  (line 725)

/* DWARF original prototype: void UserCmd_Slot3(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot3(CHudAmmo *this)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,2), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 2)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[2][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,2);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,3);
    }
  }
  return;
}


// CHudAmmo::UserCmd_Slot4  @ 00065790  (line 730)

/* DWARF original prototype: void UserCmd_Slot4(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot4(CHudAmmo *this)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,3), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 3)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[3][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,3);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,4);
    }
  }
  return;
}


// CHudAmmo::UserCmd_Slot5  @ 00065a80  (line 735)

/* DWARF original prototype: void UserCmd_Slot5(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot5(CHudAmmo *this)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,4), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 4)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[4][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,4);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,5);
    }
  }
  return;
}


// CHudAmmo::UserCmd_Slot6  @ 00065d70  (line 740)

/* DWARF original prototype: void UserCmd_Slot6(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot6(CHudAmmo *this)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  WeaponsResource *pWVar4;
  int iVar5;
  WEAPON *pWVar6;
  longdouble lVar7;
  
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar3 = TeamFortressViewport::SlotInput(gViewPort,5), !bVar3)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
    if (gHUD.m_Menu.m_fMenuDisplayed == 0) {
      if ((((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) &&
          (gHUD.m_iWeaponBits < 0)) && ((gHUD.m_iWeaponBits & 0x7fffffffU) != 0)) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
        lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_fastswitch");
        if ((gpActiveSel < (WEAPON *)0x2) || (gpActiveSel->iSlot != 5)) {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudon.wav",1.0);
          pWVar4 = &gWR;
          do {
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
            pWVar6 = pWVar4->rgSlots[5][0];
            if ((pWVar6 != (WEAPON *)0x0) &&
               (((((pWVar6->iMax1 == -1 || (iVar5 = pWVar6->iAmmoType, iVar5 == -1)) ||
                  ((0 < pWVar6->iClip || ((-1 < iVar5 && (gWR.riAmmo[iVar5] != 0)))))) ||
                 ((-1 < pWVar6->iAmmo2Type && (gWR.riAmmo[pWVar6->iAmmo2Type] != 0)))) ||
                ((pWVar6->iFlags & 1) != 0)))) {
              if ((float)lVar7 == 0.0) {
                gpActiveSel = pWVar6;
                return;
              }
                    /* Unresolved local var: WEAPON * p2@[???] */
              iVar5 = pWVar6->iSlotPos;
              while( true ) {
                do {
                    /* Unresolved local var: WEAPON * p@[???] */
                  if ((4 < iVar5) || (4 < pWVar6->iSlot)) {
                    (*gEngfuncs.pfnServerCmd)(pWVar6->szName);
                    g_weaponselect = pWVar6->iId;
                    return;
                  }
                  iVar5 = iVar5 + 1;
                  iVar1 = *(int *)(pWVar6->iSlot * 0x18 + 0xf8660 + iVar5 * 4);
                } while (iVar1 == 0);
                if (*(int *)(iVar1 + 0x88) == -1) {
                  gpActiveSel = pWVar6;
                  return;
                }
                iVar2 = *(int *)(iVar1 + 0x80);
                if (iVar2 == -1) break;
                if (0 < *(int *)(iVar1 + 0xa0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < iVar2) && (gWR.riAmmo[iVar2] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((-1 < *(int *)(iVar1 + 0x84)) && (gWR.riAmmo[*(int *)(iVar1 + 0x84)] != 0)) {
                  gpActiveSel = pWVar6;
                  return;
                }
                if ((*(byte *)(iVar1 + 0x98) & 1) != 0) {
                  gpActiveSel = pWVar6;
                  return;
                }
              }
              gpActiveSel = pWVar6;
              return;
            }
            pWVar4 = (WeaponsResource *)(pWVar4->rgWeapons[0].szName + 4);
          } while (pWVar4 != (WeaponsResource *)0xf5d74);
        }
        else {
          (*gEngfuncs.pfnPlaySoundByName)("common/wpn_moveselect.wav",1.0);
          if ((gpActiveSel != (WEAPON *)0x0) &&
             (pWVar6 = WeaponsResource::GetNextActivePos
                                 (&gWR,gpActiveSel->iSlot,gpActiveSel->iSlotPos),
             pWVar6 != (WEAPON *)0x0)) {
            gpActiveSel = pWVar6;
            return;
          }
          gpActiveSel = WeaponsResource::GetFirstPos(&gWR,5);
          if (gpActiveSel != (WEAPON *)0x0) {
            return;
          }
        }
        if ((float)lVar7 == 0.0) {
          gpActiveSel = (WEAPON *)0x1;
        }
        else {
          gpActiveSel = (WEAPON *)0x0;
        }
      }
    }
    else {
      CHudMenu::SelectMenuItem(&gHUD.m_Menu,6);
    }
  }
  return;
}


// CHudAmmo::UserCmd_Slot7  @ 00066060  (line 745)

/* DWARF original prototype: void UserCmd_Slot7(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot7(CHudAmmo *this)

{
  bool bVar1;
  
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar1 = TeamFortressViewport::SlotInput(gViewPort,6), bVar1)) {
    return;
  }
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
  if (gHUD.m_Menu.m_fMenuDisplayed != 0) {
    CHudMenu::SelectMenuItem(&gHUD.m_Menu,7);
  }
  return;
}


// CHudAmmo::UserCmd_Slot8  @ 000660b0  (line 750)

/* DWARF original prototype: void UserCmd_Slot8(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot8(CHudAmmo *this)

{
  bool bVar1;
  
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar1 = TeamFortressViewport::SlotInput(gViewPort,7), bVar1)) {
    return;
  }
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
  if (gHUD.m_Menu.m_fMenuDisplayed != 0) {
    CHudMenu::SelectMenuItem(&gHUD.m_Menu,8);
  }
  return;
}


// CHudAmmo::UserCmd_Slot9  @ 00066100  (line 755)

/* DWARF original prototype: void UserCmd_Slot9(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot9(CHudAmmo *this)

{
  bool bVar1;
  
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar1 = TeamFortressViewport::SlotInput(gViewPort,8), bVar1)) {
    return;
  }
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
  if (gHUD.m_Menu.m_fMenuDisplayed != 0) {
    CHudMenu::SelectMenuItem(&gHUD.m_Menu,9);
  }
  return;
}


// CHudAmmo::UserCmd_Slot10  @ 00066150  (line 760)

/* DWARF original prototype: void UserCmd_Slot10(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot10(CHudAmmo *this)

{
  bool bVar1;
  
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar1 = TeamFortressViewport::SlotInput(gViewPort,9), bVar1)) {
    return;
  }
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: bool fastSwitch@[???] */
  if (gHUD.m_Menu.m_fMenuDisplayed != 0) {
    CHudMenu::SelectMenuItem(&gHUD.m_Menu,10);
  }
  return;
}


// CHudAmmo::UserCmd_Close  @ 000661a0  (line 765)

/* DWARF original prototype: void UserCmd_Close(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Close(CHudAmmo *this)

{
  if (gpActiveSel != (WEAPON *)0x0) {
    gpLastSel = gpActiveSel;
    gpActiveSel = (WEAPON *)0x0;
    (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudoff.wav",1.0);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000661e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.pfnClientCmd)("escape");
  return;
}


// __CmdFunc_NextWeapon  @ 00061d20  (line 780)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_NextWeapon(void)

{
  CHudAmmo *in_stack_00000004;
  
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
  if ((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) {
    CHudAmmo::UserCmd_NextWeapon(in_stack_00000004);
    return;
  }
  return;
}


// CHudAmmo::UserCmd_NextWeapon  @ 000661f0  (line 780)

/* DWARF original prototype: void UserCmd_NextWeapon(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_NextWeapon(CHudAmmo *this)

{
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
  if ((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) {
    UserCmd_NextWeapon(this);
    return;
  }
  return;
}


// CHudAmmo::UserCmd_NextWeapon  @ 00061c20  (line 783)

/* DWARF original prototype: void UserCmd_NextWeapon(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_NextWeapon(CHudAmmo *this)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
  if (gpActiveSel < (WEAPON *)0x2) {
    gpActiveSel = *(WEAPON **)(in_EAX + 0x1c);
  }
  if (gpActiveSel == (WEAPON *)0x0) {
    iVar4 = 0;
    iVar2 = 0;
  }
  else {
    iVar4 = gpActiveSel->iSlot;
    iVar2 = gpActiveSel->iSlotPos + 1;
  }
                    /* Unresolved local var: int loop@[???] */
  iVar5 = 2;
  if (4 < iVar4) goto LAB_00061cf5;
  do {
    iVar3 = iVar4 * 0x18;
    if (4 < iVar2) goto LAB_00061ce6;
    do {
      do {
                    /* Unresolved local var: WEAPON * wsp@[???] */
        gpActiveSel = *(WEAPON **)(iVar3 + 0xf8660 + iVar2 * 4);
        if ((gpActiveSel != (WEAPON *)0x0) &&
           ((((gpActiveSel->iMax1 == -1 || (iVar1 = gpActiveSel->iAmmoType, iVar1 == -1)) ||
             (0 < gpActiveSel->iClip)) ||
            ((((-1 < iVar1 && (gWR.riAmmo[iVar1] != 0)) ||
              ((-1 < gpActiveSel->iAmmo2Type && (gWR.riAmmo[gpActiveSel->iAmmo2Type] != 0)))) ||
             ((gpActiveSel->iFlags & 1) != 0)))))) {
          return;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 5);
LAB_00061ce6:
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x18;
      iVar2 = 0;
    } while (iVar4 != 5);
LAB_00061cf5:
    iVar4 = 0;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      gpActiveSel = (WEAPON *)0x0;
      return;
    }
  } while( true );
}


// __CmdFunc_PrevWeapon  @ 00061bf0  (line 821)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_PrevWeapon(void)

{
  CHudAmmo *in_stack_00000004;
  
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
  if ((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) {
    CHudAmmo::UserCmd_PrevWeapon(in_stack_00000004);
    return;
  }
  return;
}


// CHudAmmo::UserCmd_PrevWeapon  @ 00066220  (line 821)

/* DWARF original prototype: void UserCmd_PrevWeapon(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_PrevWeapon(CHudAmmo *this)

{
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
  if ((gHUD.m_fPlayerDead == 0) && (((byte)gHUD.m_iHideHUDDisplay & 5) == 0)) {
    UserCmd_PrevWeapon(this);
    return;
  }
  return;
}


// CHudAmmo::UserCmd_PrevWeapon  @ 00061af0  (line 824)

/* DWARF original prototype: void UserCmd_PrevWeapon(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_PrevWeapon(CHudAmmo *this)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
  if (gpActiveSel < (WEAPON *)0x2) {
    gpActiveSel = *(WEAPON **)(in_EAX + 0x1c);
  }
  if (gpActiveSel == (WEAPON *)0x0) {
    iVar4 = 4;
    iVar2 = 4;
  }
  else {
    iVar4 = gpActiveSel->iSlot;
    iVar2 = gpActiveSel->iSlotPos + -1;
  }
                    /* Unresolved local var: int loop@[???] */
  iVar5 = 2;
  if (iVar4 < 0) goto LAB_00061bc8;
  do {
    iVar3 = iVar4 * 0x18;
    if (iVar2 < 0) goto LAB_00061bb6;
    do {
      do {
                    /* Unresolved local var: WEAPON * wsp@[???] */
        gpActiveSel = *(WEAPON **)(iVar3 + 0xf8660 + iVar2 * 4);
        if ((gpActiveSel != (WEAPON *)0x0) &&
           ((((gpActiveSel->iMax1 == -1 || (iVar1 = gpActiveSel->iAmmoType, iVar1 == -1)) ||
             (0 < gpActiveSel->iClip)) ||
            ((((-1 < iVar1 && (gWR.riAmmo[iVar1] != 0)) ||
              ((-1 < gpActiveSel->iAmmo2Type && (gWR.riAmmo[gpActiveSel->iAmmo2Type] != 0)))) ||
             ((gpActiveSel->iFlags & 1) != 0)))))) {
          return;
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != -1);
LAB_00061bb6:
      iVar4 = iVar4 + -1;
      iVar3 = iVar3 + -0x18;
      iVar2 = 4;
    } while (iVar4 != -1);
LAB_00061bc8:
    iVar5 = iVar5 + -1;
    iVar4 = 4;
    if (iVar5 == 0) {
      gpActiveSel = (WEAPON *)0x0;
      return;
    }
  } while( true );
}


// CHudAmmo::Draw  @ 000671a0  (line 870)

/* DWARF original prototype: int Draw(CHudAmmo * this, float flTime) */

int __thiscall CHudAmmo::Draw(CHudAmmo *this,float flTime)

{
  float fVar1;
  WEAPON *pWVar2;
  WEAPON *pWVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_40;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int AmmoWidth@[???]
                       Unresolved local var: WEAPON * pw@[???]
                       Unresolved local var: int iFlags@[???] */
  iVar4 = 1;
  if (gHUD.m_iWeaponBits < 0) {
    if ((gHUD.m_iHideHUDDisplay & 5U) == 0) {
      DrawWList(this,flTime);
      HistoryResource::DrawAmmoHistory(&gHR,flTime);
      iVar4 = 0;
      if (((this->super_CHudBase).m_iFlags & 1U) != 0) {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int AmmoWidth@[???]
                       Unresolved local var: WEAPON * pw@[???]
                       Unresolved local var: int iFlags@[???] */
        pWVar2 = this->m_pWeapon;
        if ((pWVar2 == (WEAPON *)0x0) || ((pWVar2->iAmmoType < 0 && (pWVar2->iAmmo2Type < 0)))) {
          iVar4 = 0;
        }
        else {
          iVar4 = gHUD.m_rgrcRects[gHUD.m_HUD_number_0].right -
                  gHUD.m_rgrcRects[gHUD.m_HUD_number_0].left;
          fVar1 = this->m_fFade;
          iVar8 = (int)fVar1;
          if (iVar8 < 100) {
            iVar8 = 100;
          }
          if (0.0 < fVar1) {
            this->m_fFade = fVar1 - (float)gHUD.m_flTimeDelta * 20.0;
          }
          local_20[0] = 0;
          local_28 = 0xff;
          local_24 = 0xa0;
          ScaleColors(&local_28,&local_24,local_20,iVar8);
          iVar7 = ((gHUD.m_scrinfo.iHeight - gHUD.m_iFontHeight) - gHUD.m_iFontHeight / 2) +
                  (int)((float)gHUD.m_iFontHeight * 0.2);
          pWVar3 = this->m_pWeapon;
          if (0 < pWVar3->iAmmoType) {
                    /* Unresolved local var: int iIconWidth@[???]
                       Unresolved local var: int iOffset@[???] */
                    /* Unresolved local var: wrect_t rc@[???]
                       Unresolved local var: int iBarWidth@[???] */
            iVar6 = (pWVar3->rcAmmo).right - (pWVar3->rcAmmo).left;
            if (pWVar2->iClip < 0) {
              local_40 = 0;
              if (-1 < pWVar2->iAmmoType) {
                local_40 = gWR.riAmmo[pWVar2->iAmmoType];
              }
              iVar8 = CHud::DrawHudNumber(&gHUD,(gHUD.m_scrinfo.iWidth + iVar4 * -4) - iVar6,iVar7,5
                                          ,local_40,local_28,local_24,local_20[0]);
            }
            else {
              iVar6 = CHud::DrawHudNumber(&gHUD,(gHUD.m_scrinfo.iWidth + iVar4 * -8) - iVar6,iVar7,5
                                          ,pWVar2->iClip,local_28,local_24,local_20[0]);
              local_28 = 0xff;
              local_24 = 0xa0;
              local_20[0] = 0;
              iVar6 = iVar6 + iVar4 / 2;
              (*gEngfuncs.pfnFillRGBA)(iVar6,iVar7,iVar4 / 10,gHUD.m_iFontHeight,0xff,0xa0,0,iVar8);
              ScaleColors(&local_28,&local_24,local_20,iVar8);
              local_40 = 0;
              if (-1 < pWVar2->iAmmoType) {
                local_40 = gWR.riAmmo[pWVar2->iAmmoType];
              }
              iVar8 = CHud::DrawHudNumber(&gHUD,iVar4 / 2 + iVar4 / 10 + iVar6,iVar7,5,local_40,
                                          local_28,local_24,local_20[0]);
            }
            pWVar3 = this->m_pWeapon;
            iVar5 = (pWVar3->rcAmmo).bottom - (pWVar3->rcAmmo).top;
            iVar6 = iVar5 + 7;
            if (-1 < iVar5) {
              iVar6 = iVar5;
            }
            (*gEngfuncs.pfnSPR_Set)(pWVar3->hAmmo,local_28,local_24,local_20[0]);
            (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar8,iVar7 - (iVar6 >> 3),&this->m_pWeapon->rcAmmo);
          }
          if (0 < pWVar2->iAmmo2Type) {
                    /* Unresolved local var: int iIconWidth@[???] */
            if (0 < gWR.riAmmo[pWVar2->iAmmo2Type]) {
                    /* Unresolved local var: int iOffset@[???] */
              iVar8 = gHUD.m_iFontHeight + 3;
              if (-1 < gHUD.m_iFontHeight) {
                iVar8 = gHUD.m_iFontHeight;
              }
              iVar7 = iVar7 - (gHUD.m_iFontHeight + (iVar8 >> 2));
              iVar8 = CHud::DrawHudNumber(&gHUD,(gHUD.m_scrinfo.iWidth + iVar4 * -4) -
                                                ((this->m_pWeapon->rcAmmo2).right -
                                                (this->m_pWeapon->rcAmmo2).left),iVar7,5,
                                          gWR.riAmmo[pWVar2->iAmmo2Type],local_28,local_24,
                                          local_20[0]);
              (*gEngfuncs.pfnSPR_Set)(this->m_pWeapon->hAmmo2,local_28,local_24,local_20[0]);
              pWVar2 = this->m_pWeapon;
              iVar4 = (pWVar2->rcAmmo2).bottom - (pWVar2->rcAmmo2).top;
              if (iVar4 < 0) {
                iVar4 = iVar4 + 7;
              }
              (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar8,iVar7 - (iVar4 >> 3),&pWVar2->rcAmmo2);
            }
          }
          iVar4 = 1;
        }
      }
    }
    return iVar4;
  }
  return iVar4;
}


// DrawBar  @ 00066250  (line 985)

int DrawBar(int x,int y,int width,int height,float f)

{
  int iVar1;
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???] */
  if (0.0 <= f) {
    if (f <= 1.0) {
      if (f == 0.0) goto LAB_000662f8;
    }
    else {
      f = 1.0;
    }
                    /* Unresolved local var: int w@[???] */
    iVar1 = (int)((float)width * f);
    if (iVar1 < 1) {
      iVar1 = 1;
    }
    width = width - iVar1;
    (*gEngfuncs.pfnFillRGBA)(x,y,iVar1,height,0,0xa0,0,0xff);
    x = x + iVar1;
  }
LAB_000662f8:
  (*gEngfuncs.pfnFillRGBA)(x,y,width,height,0xff,0xa0,0,0x80);
  return x + width;
}


// DrawAmmoBar  @ 00066360  (line 1016)

void DrawAmmoBar(WEAPON *p,int x,int y,int width,int height)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  if (p == (WEAPON *)0x0) {
    return;
  }
                    /* Unresolved local var: float f@[???] */
  if (p->iAmmoType < 0) {
    return;
  }
  if (gWR.riAmmo[p->iAmmoType] == 0) {
    return;
  }
  fVar1 = (float)gWR.riAmmo[p->iAmmoType] / (float)p->iMax1;
  iVar3 = width;
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???] */
  if (0.0 <= fVar1) {
    if (fVar1 <= 1.0) {
      if (fVar1 == 0.0) goto LAB_0006642d;
    }
    else {
      fVar1 = 1.0;
    }
                    /* Unresolved local var: int w@[???] */
    iVar2 = (int)((float)width * fVar1);
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    (*gEngfuncs.pfnFillRGBA)(x,y,iVar2,height,0,0xa0,0,0xff);
    iVar3 = width - iVar2;
    x = x + iVar2;
  }
LAB_0006642d:
  (*gEngfuncs.pfnFillRGBA)(x,y,iVar3,height,0xff,0xa0,0,0x80);
  iVar2 = p->iAmmo2Type;
  if (iVar2 == -1) {
    return;
  }
  if (iVar2 < 0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = (float)gWR.riAmmo[iVar2];
  }
  iVar3 = x + iVar3 + 5;
  fVar1 = fVar1 / (float)p->iMax2;
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???] */
  if (0.0 <= fVar1) {
    if (fVar1 <= 1.0) {
      if (fVar1 == 0.0) goto LAB_00066510;
    }
    else {
      fVar1 = 1.0;
    }
                    /* Unresolved local var: int w@[???] */
    iVar2 = (int)((float)width * fVar1);
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    (*gEngfuncs.pfnFillRGBA)(iVar3,y,iVar2,height,0,0xa0,0,0xff);
    width = width - iVar2;
    iVar3 = iVar3 + iVar2;
  }
LAB_00066510:
  (*gEngfuncs.pfnFillRGBA)(iVar3,y,width,height,0xff,0xa0,0,0x80);
  return;
}


// CHudAmmo::DrawWList  @ 000665b0  (line 1053)

/* DWARF original prototype: int DrawWList(CHudAmmo * this, float flTime) */

int __thiscall CHudAmmo::DrawWList(CHudAmmo *this,float flTime)

{
  int iVar1;
  WEAPON *pWVar2;
  rect_s *prVar3;
  HANDLE_SPRITE HVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  WeaponsResource *pWVar9;
  int iVar10;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int iActiveSlot@[???] */
  if (gpActiveSel != (WEAPON *)0x0) {
    if (gpActiveSel == (WEAPON *)0x1) {
      local_48 = -1;
    }
    else {
      local_48 = gpActiveSel->iSlot;
                    /* Unresolved local var: WEAPON * pret@[???]
                       Unresolved local var: int i@[???] */
      if ((((0 < local_48) &&
           ((pWVar2 = gWR.rgSlots[local_48][0], pWVar2 == (WEAPON *)0x0 ||
            (((((pWVar2->iMax1 != -1 && (iVar8 = pWVar2->iAmmoType, iVar8 != -1)) &&
               (pWVar2->iClip < 1)) &&
              (((iVar8 < 0 || (gWR.riAmmo[iVar8] == 0)) &&
               ((pWVar2->iAmmo2Type < 0 || (gWR.riAmmo[pWVar2->iAmmo2Type] == 0)))))) &&
             ((pWVar2->iFlags & 1) == 0)))))) &&
          ((pWVar2 = gWR.rgSlots[local_48][1], pWVar2 == (WEAPON *)0x0 ||
           (((((pWVar2->iMax1 != -1 && (iVar8 = pWVar2->iAmmoType, iVar8 != -1)) &&
              ((pWVar2->iClip < 1 && ((iVar8 < 0 || (gWR.riAmmo[iVar8] == 0)))))) &&
             ((pWVar2->iAmmo2Type < 0 || (gWR.riAmmo[pWVar2->iAmmo2Type] == 0)))) &&
            ((pWVar2->iFlags & 1) == 0)))))) &&
         ((((pWVar2 = gWR.rgSlots[local_48][2], pWVar2 == (WEAPON *)0x0 ||
            ((((pWVar2->iMax1 != -1 && (iVar8 = pWVar2->iAmmoType, iVar8 != -1)) &&
              (pWVar2->iClip < 1)) &&
             ((((iVar8 < 0 || (gWR.riAmmo[iVar8] == 0)) &&
               ((pWVar2->iAmmo2Type < 0 || (gWR.riAmmo[pWVar2->iAmmo2Type] == 0)))) &&
              ((pWVar2->iFlags & 1) == 0)))))) &&
           ((pWVar2 = gWR.rgSlots[local_48][3], pWVar2 == (WEAPON *)0x0 ||
            ((((pWVar2->iMax1 != -1 && (iVar8 = pWVar2->iAmmoType, iVar8 != -1)) &&
              (((pWVar2->iClip < 1 && ((iVar8 < 0 || (gWR.riAmmo[iVar8] == 0)))) &&
               ((pWVar2->iAmmo2Type < 0 || (gWR.riAmmo[pWVar2->iAmmo2Type] == 0)))))) &&
             ((pWVar2->iFlags & 1) == 0)))))) &&
          ((pWVar2 = gWR.rgSlots[local_48][4], pWVar2 == (WEAPON *)0x0 ||
           ((((((pWVar2->iMax1 != -1 && (iVar8 = pWVar2->iAmmoType, iVar8 != -1)) &&
               (pWVar2->iClip < 1)) && ((iVar8 < 0 || (gWR.riAmmo[iVar8] == 0)))) &&
             ((pWVar2->iAmmo2Type < 0 || (gWR.riAmmo[pWVar2->iAmmo2Type] == 0)))) &&
            ((pWVar2->iFlags & 1) == 0)))))))) {
        gpActiveSel = (WEAPON *)0x1;
        local_48 = -1;
      }
    }
    iVar6 = 0;
    iVar8 = 10;
    do {
                    /* Unresolved local var: int iWidth@[???] */
      local_28 = 0xff;
      local_24 = 0xa0;
      local_20[0] = 0;
      ScaleColors(&local_28,&local_24,local_20,0xff);
      iVar10 = iVar6 + this->m_HUD_bucket0;
      if (iVar10 < 0) {
        HVar4 = 0;
      }
      else {
        HVar4 = gHUD.m_rghSprites[iVar10];
      }
      (*gEngfuncs.pfnSPR_Set)(HVar4,local_28,local_24,local_20[0]);
      iVar10 = giBucketWidth;
      if ((local_48 == iVar6) &&
         (pWVar2 = WeaponsResource::GetFirstPos(&gWR,local_48), iVar10 = giBucketWidth,
         pWVar2 != (WEAPON *)0x0)) {
        iVar10 = (pWVar2->rcActive).right - (pWVar2->rcActive).left;
      }
      iVar1 = this->m_HUD_bucket0 + iVar6;
      iVar6 = iVar6 + 1;
      (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar8,10,gHUD.m_rgrcRects + iVar1);
      iVar8 = iVar10 + 5 + iVar8;
    } while (iVar6 != 5);
    local_4c = 0;
    iVar8 = 10;
    pWVar9 = &gWR;
    do {
      iVar10 = giBucketHeight;
      iVar6 = giBucketHeight + 10;
      if (local_48 == local_4c) {
                    /* Unresolved local var: WEAPON * p@[???]
                       Unresolved local var: int iWidth@[???] */
        pWVar2 = WeaponsResource::GetFirstPos(&gWR,local_48);
        local_40 = giBucketWidth;
        if (pWVar2 != (WEAPON *)0x0) {
          local_40 = (pWVar2->rcActive).right - (pWVar2->rcActive).left;
        }
                    /* Unresolved local var: int iPos@[???] */
        local_44 = 0;
        do {
          pWVar2 = *(WEAPON **)(local_4c * 0x18 + 0xf8660 + local_44 * 4);
          if ((pWVar2 != (WEAPON *)0x0) && (pWVar2->iId != 0)) {
            local_28 = 0xff;
            local_24 = 0xa0;
            local_20[0] = 0;
            if (gpActiveSel == pWVar2) {
              (*gEngfuncs.pfnSPR_Set)(pWVar2->hActive,0xff,0xa0,0);
              (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar8,iVar6,&pWVar2->rcActive);
              if (this->m_HUD_selection < 0) {
                HVar4 = 0;
              }
              else {
                HVar4 = gHUD.m_rghSprites[this->m_HUD_selection];
              }
              (*gEngfuncs.pfnSPR_Set)(HVar4,local_28,local_24,local_20[0]);
              prVar3 = gHUD.m_rgrcRects + this->m_HUD_selection;
            }
            else {
              if (((((pWVar2->iMax1 == -1) || (iVar10 = pWVar2->iAmmoType, iVar10 == -1)) ||
                   (0 < pWVar2->iClip)) ||
                  (((-1 < iVar10 && (gWR.riAmmo[iVar10] != 0)) ||
                   ((-1 < pWVar2->iAmmo2Type && (gWR.riAmmo[pWVar2->iAmmo2Type] != 0)))))) ||
                 ((pWVar2->iFlags & 1) != 0)) {
                iVar10 = 0xc0;
              }
              else {
                local_20[0] = 0x10;
                local_24 = 0x10;
                iVar10 = 0x80;
              }
              ScaleColors(&local_28,&local_24,local_20,iVar10);
              (*gEngfuncs.pfnSPR_Set)(pWVar2->hInactive,local_28,local_24,local_20[0]);
              prVar3 = &pWVar2->rcInactive;
            }
            (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar8,iVar6,prVar3);
            DrawAmmoBar(pWVar2,giABWidth / 2 + iVar8,iVar6,giABWidth,giABHeight);
            iVar6 = iVar6 + 5 + ((pWVar2->rcActive).bottom - (pWVar2->rcActive).top);
          }
          local_44 = local_44 + 1;
        } while (local_44 != 5);
        iVar8 = iVar8 + 5 + local_40;
      }
      else {
        local_24 = 0xa0;
                    /* Unresolved local var: int iPos@[???]
                       Unresolved local var: WEAPON * p@[???] */
        pWVar2 = pWVar9->rgSlots[0][0];
        local_28 = 0xff;
        local_20[0] = 0;
        if ((pWVar2 != (WEAPON *)0x0) && (pWVar2->iId != 0)) {
          if (((pWVar2->iMax1 == -1) ||
              ((iVar1 = pWVar2->iAmmoType, iVar1 == -1 || (0 < pWVar2->iClip)))) ||
             (((-1 < iVar1 && (gWR.riAmmo[iVar1] != 0)) ||
              (((-1 < pWVar2->iAmmo2Type && (gWR.riAmmo[pWVar2->iAmmo2Type] != 0)) ||
               ((pWVar2->iFlags & 1) != 0)))))) {
            iVar1 = 0;
            local_24 = 0xa0;
            iVar7 = 0xa0;
            local_20[0] = 0;
            iVar5 = 0x80;
          }
          else {
            iVar7 = 0x10;
            local_24 = 0x10;
            iVar5 = 0x60;
            local_20[0] = 0x10;
            iVar1 = 0x10;
          }
          local_28 = 0xff;
          (*gEngfuncs.pfnFillRGBA)(iVar8,iVar6,giBucketWidth,giBucketHeight,0xff,iVar7,iVar1,iVar5);
          iVar6 = iVar10 + 0xf + giBucketHeight;
        }
        pWVar2 = pWVar9->rgSlots[0][1];
        if ((pWVar2 != (WEAPON *)0x0) && (pWVar2->iId != 0)) {
          if ((((pWVar2->iMax1 == -1) ||
               ((iVar10 = pWVar2->iAmmoType, iVar10 == -1 || (0 < pWVar2->iClip)))) ||
              ((-1 < iVar10 && (gWR.riAmmo[iVar10] != 0)))) ||
             (((-1 < pWVar2->iAmmo2Type && (gWR.riAmmo[pWVar2->iAmmo2Type] != 0)) ||
              ((pWVar2->iFlags & 1) != 0)))) {
            iVar10 = 0;
            local_24 = 0xa0;
            iVar5 = 0xa0;
            local_20[0] = 0;
            iVar1 = 0x80;
          }
          else {
            iVar5 = 0x10;
            local_24 = 0x10;
            iVar1 = 0x60;
            local_20[0] = 0x10;
            iVar10 = 0x10;
          }
          local_28 = 0xff;
          (*gEngfuncs.pfnFillRGBA)(iVar8,iVar6,giBucketWidth,giBucketHeight,0xff,iVar5,iVar10,iVar1)
          ;
          iVar6 = iVar6 + 5 + giBucketHeight;
        }
        pWVar2 = pWVar9->rgSlots[0][2];
        if ((pWVar2 != (WEAPON *)0x0) && (pWVar2->iId != 0)) {
          if (((pWVar2->iMax1 == -1) ||
              ((iVar10 = pWVar2->iAmmoType, iVar10 == -1 || (0 < pWVar2->iClip)))) ||
             (((-1 < iVar10 && (gWR.riAmmo[iVar10] != 0)) ||
              (((-1 < pWVar2->iAmmo2Type && (gWR.riAmmo[pWVar2->iAmmo2Type] != 0)) ||
               ((pWVar2->iFlags & 1) != 0)))))) {
            iVar10 = 0;
            local_24 = 0xa0;
            iVar5 = 0xa0;
            local_20[0] = 0;
            iVar1 = 0x80;
          }
          else {
            iVar5 = 0x10;
            local_24 = 0x10;
            iVar1 = 0x60;
            local_20[0] = 0x10;
            iVar10 = 0x10;
          }
          local_28 = 0xff;
          (*gEngfuncs.pfnFillRGBA)(iVar8,iVar6,giBucketWidth,giBucketHeight,0xff,iVar5,iVar10,iVar1)
          ;
          iVar6 = iVar6 + 5 + giBucketHeight;
        }
        pWVar2 = pWVar9->rgSlots[0][3];
        if ((pWVar2 != (WEAPON *)0x0) && (pWVar2->iId != 0)) {
          if ((((pWVar2->iMax1 == -1) ||
               ((iVar10 = pWVar2->iAmmoType, iVar10 == -1 || (0 < pWVar2->iClip)))) ||
              ((-1 < iVar10 && (gWR.riAmmo[iVar10] != 0)))) ||
             (((-1 < pWVar2->iAmmo2Type && (gWR.riAmmo[pWVar2->iAmmo2Type] != 0)) ||
              ((pWVar2->iFlags & 1) != 0)))) {
            iVar10 = 0;
            local_24 = 0xa0;
            iVar5 = 0xa0;
            local_20[0] = 0;
            iVar1 = 0x80;
          }
          else {
            iVar5 = 0x10;
            local_24 = 0x10;
            iVar1 = 0x60;
            local_20[0] = 0x10;
            iVar10 = 0x10;
          }
          local_28 = 0xff;
          (*gEngfuncs.pfnFillRGBA)(iVar8,iVar6,giBucketWidth,giBucketHeight,0xff,iVar5,iVar10,iVar1)
          ;
          iVar6 = iVar6 + 5 + giBucketHeight;
        }
        pWVar2 = pWVar9->rgSlots[0][4];
        if ((pWVar2 != (WEAPON *)0x0) && (pWVar2->iId != 0)) {
          if ((((pWVar2->iMax1 == -1) ||
               ((iVar10 = pWVar2->iAmmoType, iVar10 == -1 || (0 < pWVar2->iClip)))) ||
              ((-1 < iVar10 && (gWR.riAmmo[iVar10] != 0)))) ||
             (((-1 < pWVar2->iAmmo2Type && (gWR.riAmmo[pWVar2->iAmmo2Type] != 0)) ||
              ((pWVar2->iFlags & 1) != 0)))) {
            iVar10 = 0;
            local_24 = 0xa0;
            iVar5 = 0x80;
            local_20[0] = 0;
            iVar1 = 0xa0;
          }
          else {
            iVar10 = 0x10;
            local_24 = 0x10;
            iVar5 = 0x60;
            local_20[0] = 0x10;
            iVar1 = 0x10;
          }
          local_28 = 0xff;
          (*gEngfuncs.pfnFillRGBA)(iVar8,iVar6,giBucketWidth,giBucketHeight,0xff,iVar1,iVar10,iVar5)
          ;
        }
        iVar8 = iVar8 + 5 + giBucketWidth;
      }
      local_4c = local_4c + 1;
      pWVar9 = (WeaponsResource *)(pWVar9->rgWeapons[0].szName + 0x18);
    } while (local_4c != 5);
    return 1;
  }
  return 0;
}


// GetSpriteList  @ 000676a0  (line 1219)

client_sprite_t * GetSpriteList(client_sprite_t *pList,char *psz,int iRes,int iCount)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_sprite_t * p@[???] */
  if (pList != (client_sprite_t *)0x0) {
    for (; iCount != 0; iCount = iCount + -1) {
      if ((pList->iRes == iRes) && (iVar1 = strcmp(psz,pList->szName), iVar1 == 0)) {
        return pList;
      }
      pList = pList + 1;
    }
  }
  return (client_sprite_t *)0x0;
}


