// Ghidra decompilation of functions from cl_dll/ammohistory.cpp
// 4 functions, ordered by original source line

// HistoryResource::AddToHistory  @ 00067c80  (line 47)

/* DWARF original prototype: void AddToHistory(HistoryResource * this, int iType, int iId, int
   iCount) */

void __thiscall HistoryResource::AddToHistory(HistoryResource *this,int iType,int iId,int iCount)

{
  HIST_ITEM *pHVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  longdouble lVar5;
  
                    /* Unresolved local var: HIST_ITEM * freeslot@[???] */
  if ((iType != 1) || (iCount != 0)) {
    iVar4 = this->iCurrentHistorySlot;
    if (((gHR.iHistoryGap + 5) * iVar4 + 0x20 + gHR.iHistoryGap * 2 < gHUD.m_scrinfo.iHeight + -99)
       && (iVar4 < 0xc)) {
      iVar3 = iVar4 + 1;
    }
    else {
      iVar3 = 1;
      iVar4 = 0;
    }
    this->iCurrentHistorySlot = iVar3;
    lVar5 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_drawhistory_time");
    HISTORY_DRAW_TIME = (int)lVar5;
    pHVar1 = this->rgAmmoHistory + iVar4;
    pHVar1->type = iType;
    pHVar1->iId = iId;
    fVar2 = (float)HISTORY_DRAW_TIME;
    pHVar1->iCount = iCount;
    pHVar1->DisplayTime = fVar2 + gHUD.m_flTime;
  }
  return;
}


// HistoryResource::AddToHistory  @ 00067d50  (line 67)

/* DWARF original prototype: void AddToHistory(HistoryResource * this, int iType, char * szName, int
   iCount) */

void __thiscall
HistoryResource::AddToHistory(HistoryResource *this,int iType,char *szName,int iCount)

{
  int iVar1;
  HIST_ITEM *pHVar2;
  int iVar3;
  longdouble lVar4;
  
                    /* Unresolved local var: HIST_ITEM * freeslot@[???]
                       Unresolved local var: int i@[???] */
  if (iType == 3) {
    iVar3 = this->iCurrentHistorySlot;
    if (((gHR.iHistoryGap + 5) * iVar3 + 0x20 + gHR.iHistoryGap * 2 < gHUD.m_scrinfo.iHeight + -99)
       && (iVar3 < 0xc)) {
      iVar1 = iVar3 + 1;
    }
    else {
      iVar1 = 1;
      iVar3 = 0;
    }
    this->iCurrentHistorySlot = iVar1;
    iVar1 = CHud::GetSpriteIndex(&gHUD,szName);
    if (iVar1 != -1) {
      pHVar2 = this->rgAmmoHistory + iVar3;
      pHVar2->iId = iVar1;
      pHVar2->type = 3;
      pHVar2->iCount = iCount;
      lVar4 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_drawhistory_time");
      HISTORY_DRAW_TIME = (int)lVar4;
      pHVar2->DisplayTime = (float)HISTORY_DRAW_TIME + gHUD.m_flTime;
      return;
    }
  }
  return;
}


// HistoryResource::CheckClearHistory  @ 00067e10  (line 95)

/* DWARF original prototype: void CheckClearHistory(HistoryResource * this) */

void __thiscall HistoryResource::CheckClearHistory(HistoryResource *this)

{
                    /* Unresolved local var: int i@[???] */
  if (((((this->rgAmmoHistory[0].type == 0) && (this->rgAmmoHistory[1].type == 0)) &&
       (this->rgAmmoHistory[2].type == 0)) &&
      ((((this->rgAmmoHistory[3].type == 0 && (this->rgAmmoHistory[4].type == 0)) &&
        ((this->rgAmmoHistory[5].type == 0 &&
         ((this->rgAmmoHistory[6].type == 0 && (this->rgAmmoHistory[7].type == 0)))))) &&
       (this->rgAmmoHistory[8].type == 0)))) &&
     (((this->rgAmmoHistory[9].type == 0 && (this->rgAmmoHistory[10].type == 0)) &&
      (this->rgAmmoHistory[0xb].type == 0)))) {
    this->iCurrentHistorySlot = 0;
  }
  return;
}


// HistoryResource::DrawAmmoHistory  @ 00067e80  (line 109)

/* DWARF original prototype: int DrawAmmoHistory(HistoryResource * this, float flTime) */

int __thiscall HistoryResource::DrawAmmoHistory(HistoryResource *this,float flTime)

{
  float fVar1;
  wrect_t *pwVar2;
  int iVar3;
  HANDLE_SPRITE *pHVar4;
  HANDLE_SPRITE HVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  HistoryResource *pHVar9;
  int local_38;
  int local_34;
  int local_30;
  wrect_t local_2c;
  
                    /* Unresolved local var: int i@[???] */
  iVar8 = 0;
  pHVar9 = this;
  do {
    iVar3 = pHVar9->rgAmmoHistory[0].type;
    if (iVar3 != 0) {
      fVar1 = pHVar9->rgAmmoHistory[0].DisplayTime;
      if ((float)HISTORY_DRAW_TIME + gHUD.m_flTime < fVar1) {
        fVar1 = (float)HISTORY_DRAW_TIME + gHUD.m_flTime;
      }
      pHVar9->rgAmmoHistory[0].DisplayTime = fVar1;
      if (fVar1 <= flTime) {
        pHVar9->rgAmmoHistory[0].type = 0;
        pHVar9->rgAmmoHistory[0].DisplayTime = 0.0;
        pHVar9->rgAmmoHistory[0].iCount = 0;
        pHVar9->rgAmmoHistory[0].iId = 0;
                    /* Unresolved local var: int i@[???] */
        if ((((((this->rgAmmoHistory[0].type == 0) && (this->rgAmmoHistory[1].type == 0)) &&
              (this->rgAmmoHistory[2].type == 0)) &&
             ((this->rgAmmoHistory[3].type == 0 && (this->rgAmmoHistory[4].type == 0)))) &&
            ((this->rgAmmoHistory[5].type == 0 &&
             ((this->rgAmmoHistory[6].type == 0 && (this->rgAmmoHistory[7].type == 0)))))) &&
           ((this->rgAmmoHistory[8].type == 0 &&
            (((this->rgAmmoHistory[9].type == 0 && (this->rgAmmoHistory[10].type == 0)) &&
             (this->rgAmmoHistory[0xb].type == 0)))))) {
          this->iCurrentHistorySlot = 0;
        }
      }
      else if (iVar3 == 1) {
                    /* Unresolved local var: wrect_t rcPic@[???]
                       Unresolved local var: HANDLE_SPRITE * spr@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: float scale@[???]
                       Unresolved local var: int ypos@[???]
                       Unresolved local var: int xpos@[???] */
        pHVar4 = WeaponsResource::GetAmmoPicFromWeapon(&gWR,pHVar9->rgAmmoHistory[0].iId,&local_2c);
        local_38 = 0xff;
        local_34 = 0xa0;
        local_30 = 0;
        iVar3 = (int)((pHVar9->rgAmmoHistory[0].DisplayTime - flTime) * 80.0);
        if (0xff < iVar3) {
          iVar3 = 0xff;
        }
        ScaleColors(&local_38,&local_34,&local_30,iVar3);
        iVar3 = gHUD.m_scrinfo.iHeight -
                ((gHR.iHistoryGap + 5) * iVar8 + 0x20 + gHR.iHistoryGap * 2);
        iVar6 = gHUD.m_scrinfo.iWidth - (local_2c.right - local_2c.left);
        if ((pHVar4 != (HANDLE_SPRITE *)0x0) && (*pHVar4 != 0)) {
          (*gEngfuncs.pfnSPR_Set)(*pHVar4,local_38,local_34,local_30);
          (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar6 + -4,iVar3,&local_2c);
        }
        CHud::DrawHudNumberString
                  (&gHUD,iVar6 + -0xe,iVar3,iVar6 + -0x68,pHVar9->rgAmmoHistory[0].iCount,local_38,
                   local_34,local_30);
      }
      else if (iVar3 == 2) {
                    /* Unresolved local var: WEAPON * weap@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: float scale@[???]
                       Unresolved local var: int ypos@[???]
                       Unresolved local var: int xpos@[???] */
        iVar3 = pHVar9->rgAmmoHistory[0].iId;
        if (gWR.rgWeapons + iVar3 == (WEAPON *)0x0) {
          return 1;
        }
        local_34 = 0xff;
        local_30 = 0xa0;
        local_2c.left = 0;
        iVar6 = WeaponsResource::HasAmmo(&gWR,gWR.rgWeapons + iVar3);
        if (iVar6 == 0) {
          local_30 = 0x10;
          local_34 = 0xff;
          local_2c.left = 0x10;
        }
        iVar6 = (int)((pHVar9->rgAmmoHistory[0].DisplayTime - flTime) * 80.0);
        if (0xff < iVar6) {
          iVar6 = 0xff;
        }
        ScaleColors(&local_34,&local_30,&local_2c.left,iVar6);
        iVar7 = gHUD.m_scrinfo.iHeight -
                ((gHR.iHistoryGap + 5) * iVar8 + 0x20 + gHR.iHistoryGap * 2);
        iVar6 = gHUD.m_scrinfo.iWidth -
                (gWR.rgWeapons[iVar3].rcInactive.right - gWR.rgWeapons[iVar3].rcInactive.left);
        (*gEngfuncs.pfnSPR_Set)(gWR.rgWeapons[iVar3].hInactive,local_34,local_30,local_2c.left);
        (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar6,iVar7,(rect_s *)(iVar3 * 0x148 + 0xf5e20));
      }
      else {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: wrect_t rect@[???]
                       Unresolved local var: float scale@[???]
                       Unresolved local var: int ypos@[???]
                       Unresolved local var: int xpos@[???] */
        if ((iVar3 == 3) && (iVar3 = pHVar9->rgAmmoHistory[0].iId, iVar3 != 0)) {
          pwVar2 = gHUD.m_rgrcRects + iVar3;
          local_2c.left = pwVar2->left;
          local_2c.right = pwVar2->right;
          local_2c.top = pwVar2->top;
          local_2c.bottom = pwVar2->bottom;
          local_38 = 0xff;
          local_34 = 0xa0;
          local_30 = 0;
          iVar3 = (int)((fVar1 - flTime) * 80.0);
          if (0xff < iVar3) {
            iVar3 = 0xff;
          }
          ScaleColors(&local_38,&local_34,&local_30,iVar3);
          iVar7 = gHUD.m_scrinfo.iHeight -
                  ((gHR.iHistoryGap + 5) * iVar8 + 0x20 + gHR.iHistoryGap * 2);
          iVar6 = gHUD.m_scrinfo.iWidth - (local_2c.right - local_2c.left);
          iVar3 = pHVar9->rgAmmoHistory[0].iId;
          if (iVar3 < 0) {
            HVar5 = 0;
          }
          else {
            HVar5 = gHUD.m_rghSprites[iVar3];
          }
          (*gEngfuncs.pfnSPR_Set)(HVar5,local_38,local_34,local_30);
          (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar6 + -10,iVar7,&local_2c);
        }
      }
    }
    pHVar9 = (HistoryResource *)(pHVar9->rgAmmoHistory + 1);
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0xc);
  return 1;
}


