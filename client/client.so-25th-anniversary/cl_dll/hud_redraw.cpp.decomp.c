// Ghidra decompilation of functions from cl_dll/hud_redraw.cpp
// 8 functions, ordered by original source line

// CHud::Think  @ 0006ff50  (line 43)

/* DWARF original prototype: void Think(CHud * this) */

void __thiscall CHud::Think(CHud *this)

{
  CHudBase *pCVar1;
  int iVar2;
  cvar_s *pcVar3;
  HUDLIST *pHVar4;
  int iVar5;
  longdouble extraout_ST0;
  float fVar6;
  float fVar7;
  
                    /* Unresolved local var: int newfov@[???]
                       Unresolved local var: HUDLIST * pList@[???] */
  (this->m_scrinfo).iSize = 0x214;
  (*gEngfuncs.pfnGetScreenInfo)(&this->m_scrinfo);
  for (pHVar4 = this->m_pHudList; pHVar4 != (HUDLIST *)0x0; pHVar4 = pHVar4->pNext) {
    while (pCVar1 = pHVar4->p, (pCVar1->m_iFlags & 1) != 0) {
      (*pCVar1->_vptr_CHudBase[5])(pCVar1);
      pHVar4 = pHVar4->pNext;
      if (pHVar4 == (HUDLIST *)0x0) goto LAB_0006ff9e;
    }
  }
LAB_0006ff9e:
  fVar6 = HUD_GetFOV();
  iVar5 = (int)fVar6;
  if (iVar5 == 0) {
    pcVar3 = this->default_fov;
    iVar2 = (int)pcVar3->value;
  }
  else {
    pcVar3 = this->default_fov;
    iVar2 = iVar5;
  }
  this->m_iFOV = iVar2;
  if ((float)iVar2 == pcVar3->value) {
    this->m_flMouseSensitivity = 0.0;
  }
  else {
    fVar7 = IN_GetMouseSensitivity();
    iVar2 = (int)this->default_fov->value;
    fVar6 = 90.0;
    if (0x59 < iVar2) {
      fVar6 = (float)iVar2;
    }
    (*gEngfuncs.pfnGetCvarFloat)("zoom_sensitivity_ratio");
    iVar2 = this->m_iFOV;
    this->m_flMouseSensitivity =
         (float)(extraout_ST0 * (longdouble)(((float)iVar5 / fVar6) * fVar7));
  }
  if (iVar2 == 0) {
    iVar5 = (int)this->default_fov->value;
    if (iVar5 < 0x5a) {
      iVar5 = 0x5a;
    }
    this->m_iFOV = iVar5;
  }
  iVar5 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar5 != 0) {
    fVar6 = CHudSpectator::GetFOV(&gHUD.m_Spectator);
    this->m_iFOV = (int)fVar6;
  }
  Bench_CheckStart();
  return;
}


// CHud::Redraw  @ 00070090  (line 99)

/* DWARF original prototype: int Redraw(CHud * this, float flTime, int intermission) */

int __thiscall CHud::Redraw(CHud *this,float flTime,int intermission)

{
  CHudBenchmark *pCVar1;
  float fVar2;
  CHudBase *pCVar3;
  float fVar4;
  TeamFortressViewport *this_00;
  int iVar5;
  int iVar6;
  HUDLIST *pHVar7;
  longdouble extraout_ST0;
  
  this_00 = gViewPort;
  fVar2 = this->m_flTime;
  this->m_flTime = flTime;
  this->m_fOldTime = fVar2;
  fVar2 = flTime - fVar2;
  fVar4 = 0.0;
  if (0.0 <= fVar2) {
    fVar4 = fVar2;
  }
  this->m_flTimeDelta = (double)fVar4;
  if (this_00 != (TeamFortressViewport *)0x0) {
    if (this->m_iIntermission == 0) {
      if (intermission != 0) {
        this->m_iIntermission = intermission;
        TeamFortressViewport::HideCommandMenu(this_00);
        TeamFortressViewport::HideVGUIMenu(gViewPort);
        TeamFortressViewport::ShowScoreBoard(gViewPort);
        TeamFortressViewport::UpdateSpectatorPanel(gViewPort);
        (*gEngfuncs.pfnGetCvarFloat)("hud_takesshots");
        if (extraout_ST0 != (longdouble)0) {
          Redraw::m_flShotTime = flTime + 1.0;
        }
      }
    }
    else if (intermission == 0) {
      this->m_iIntermission = 0;
      TeamFortressViewport::HideCommandMenu(this_00);
      TeamFortressViewport::HideScoreBoard(gViewPort);
      TeamFortressViewport::UpdateSpectatorPanel(gViewPort);
    }
  }
  if ((Redraw::m_flShotTime != 0.0) && (Redraw::m_flShotTime < flTime)) {
    (*gEngfuncs.pfnClientCmd)("snapshot\n");
    Redraw::m_flShotTime = 0.0;
  }
  this->m_iIntermission = intermission;
                    /* Unresolved local var: HUDLIST * pList@[???] */
  if ((this->m_pCvarDraw->value != 0.0) && (pHVar7 = this->m_pHudList, pHVar7 != (HUDLIST *)0x0)) {
    pCVar1 = &this->m_Benchmark;
    do {
      iVar5 = Bench_Active();
      if (iVar5 == 0) {
        pCVar3 = pHVar7->p;
        if (intermission == 0) {
          if (((pCVar3->m_iFlags & 1) != 0) && ((this->m_iHideHUDDisplay & 4) == 0)) {
            (*pCVar3->_vptr_CHudBase[4])(pCVar3,flTime);
          }
        }
        else if ((pCVar3->m_iFlags & 2) != 0) {
          (*pCVar3->_vptr_CHudBase[4])(pCVar3,flTime);
        }
      }
      else if ((((CHudBenchmark *)pHVar7->p == pCVar1) &&
               (((this->m_Benchmark).super_CHudBase.m_iFlags & 1) != 0)) &&
              ((this->m_iHideHUDDisplay & 4) == 0)) {
        (*(pCVar1->super_CHudBase)._vptr_CHudBase[4])(pCVar1,flTime);
      }
      pHVar7 = pHVar7->pNext;
    } while (pHVar7 != (HUDLIST *)0x0);
  }
  if (this->m_iLogo != 0) {
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int iFrame@[???] */
    iVar5 = this->m_hsprLogo;
    if (iVar5 == 0) {
      iVar5 = LoadSprite("sprites/%d_logo.spr");
      this->m_hsprLogo = iVar5;
    }
    (*gEngfuncs.pfnSPR_Set)(iVar5,0xfa,0xfa,0xfa);
    iVar5 = (*gEngfuncs.pfnSPR_Width)(this->m_hsprLogo,0);
    iVar5 = gHUD.m_scrinfo.iWidth - iVar5;
    iVar6 = (*gEngfuncs.pfnSPR_Height)(this->m_hsprLogo,0);
    (*gEngfuncs.pfnSPR_DrawAdditive)
              (grgLogoFrame[(int)(flTime * 20.0) % 0x38] + -1,iVar5,iVar6 / 2,(rect_s *)0x0);
  }
  return 1;
}


// ScaleColors  @ 000703a0  (line 226)

void ScaleColors(int *r,int *g,int *b,int a)

{
  float fVar1;
  
                    /* Unresolved local var: float x@[???] */
  fVar1 = (float)a / 255.0;
  *r = (int)((float)*r * fVar1);
  *g = (int)((float)*g * fVar1);
  *b = (int)((float)*b * fVar1);
  return;
}


// CHud::DrawHudString  @ 000703f0  (line 234)

/* DWARF original prototype: int DrawHudString(CHud * this, int xpos, int ypos, int iMaxX, char *
   szIt, int r, int g, int b) */

int __thiscall
CHud::DrawHudString(CHud *this,int xpos,int ypos,int iMaxX,char *szIt,int r,int g,int b)

{
  int iVar1;
  
  iVar1 = (*gEngfuncs.pfnDrawString)(xpos,ypos,szIt,r,g,b);
  return iVar1 + xpos;
}


// CHud::DrawHudNumberString  @ 00070430  (line 239)

/* DWARF original prototype: int DrawHudNumberString(CHud * this, int xpos, int ypos, int iMinX, int
   iNumber, int r, int g, int b) */

int __thiscall
CHud::DrawHudNumberString(CHud *this,int xpos,int ypos,int iMinX,int iNumber,int r,int g,int b)

{
  int iVar1;
  int in_GS_OFFSET;
  char local_30 [32];
  int local_10;
  
                    /* Unresolved local var: char[32] szString@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __sprintf_chk(local_30,1,0x20,"%d",iNumber);
  iVar1 = (*gEngfuncs.pfnDrawStringReverse)(xpos,ypos,local_30,r,g,b);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return xpos - iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHud::DrawHudStringReverse  @ 000704c0  (line 248)

/* DWARF original prototype: int DrawHudStringReverse(CHud * this, int xpos, int ypos, int iMinX,
   char * szString, int r, int g, int b) */

int __thiscall
CHud::DrawHudStringReverse(CHud *this,int xpos,int ypos,int iMinX,char *szString,int r,int g,int b)

{
  int iVar1;
  
  iVar1 = (*gEngfuncs.pfnDrawStringReverse)(xpos,ypos,szString,r,g,b);
  return xpos - iVar1;
}


// CHud::DrawHudNumber  @ 00070510  (line 253)

/* DWARF original prototype: int DrawHudNumber(CHud * this, int x, int y, int iFlags, int iNumber,
   int r, int g, int b) */

int __thiscall CHud::DrawHudNumber(CHud *this,int x,int y,int iFlags,int iNumber,int r,int g,int b)

{
  int iVar1;
  int iVar2;
  int iVar3;
  HANDLE_SPRITE HVar4;
  
                    /* Unresolved local var: int iWidth@[???]
                       Unresolved local var: int k@[???] */
  iVar2 = this->m_HUD_number_0;
  iVar3 = this->m_rgrcRects[iVar2].right - this->m_rgrcRects[iVar2].left;
  if (iNumber < 1) {
    if ((iFlags & 1U) == 0) {
      return x;
    }
    if (iVar2 < 0) {
      HVar4 = 0;
    }
    else {
      HVar4 = this->m_rghSprites[iVar2];
    }
    (*gEngfuncs.pfnSPR_Set)(HVar4,r,g,b);
    if ((iFlags & 4U) != 0) {
      x = iVar3 + x;
    }
    if ((iFlags & 6U) != 0) {
      x = iVar3 + x;
    }
    (*gEngfuncs.pfnSPR_DrawAdditive)(0,x,y,this->m_rgrcRects + this->m_HUD_number_0);
    return x + iVar3;
  }
  if (iNumber < 100) {
    if ((iFlags & 4U) != 0) {
      x = iVar3 + x;
    }
    if (iNumber < 10) {
      if ((iFlags & 6U) != 0) {
        x = iVar3 + x;
      }
      goto LAB_0007069b;
    }
  }
  else {
    iVar2 = iVar2 + iNumber / 100;
    if (iVar2 < 0) {
      HVar4 = 0;
    }
    else {
      HVar4 = this->m_rghSprites[iVar2];
    }
    (*gEngfuncs.pfnSPR_Set)(HVar4,r,g,b);
    (*gEngfuncs.pfnSPR_DrawAdditive)(0,x,y,this->m_rgrcRects + iNumber / 100 + this->m_HUD_number_0)
    ;
    iVar2 = this->m_HUD_number_0;
    x = x + iVar3;
  }
  iVar1 = (iNumber % 100) / 10;
  iVar2 = iVar2 + iVar1;
  if (iVar2 < 0) {
    HVar4 = 0;
  }
  else {
    HVar4 = this->m_rghSprites[iVar2];
  }
  (*gEngfuncs.pfnSPR_Set)(HVar4,r,g,b);
  (*gEngfuncs.pfnSPR_DrawAdditive)(0,x,y,this->m_rgrcRects + iVar1 + this->m_HUD_number_0);
  iVar2 = this->m_HUD_number_0;
  x = x + iVar3;
LAB_0007069b:
  iVar2 = iVar2 + iNumber % 10;
  if (iVar2 < 0) {
    HVar4 = 0;
  }
  else {
    HVar4 = this->m_rghSprites[iVar2];
  }
  (*gEngfuncs.pfnSPR_Set)(HVar4,r,g,b);
  (*gEngfuncs.pfnSPR_DrawAdditive)(0,x,y,this->m_rgrcRects + iNumber % 10 + this->m_HUD_number_0);
  return x + iVar3;
}


// CHud::GetNumWidth  @ 000707f0  (line 321)

/* DWARF original prototype: int GetNumWidth(CHud * this, int iNumber, int iFlags) */

int __thiscall CHud::GetNumWidth(CHud *this,int iNumber,int iFlags)

{
  int iVar1;
  
  iVar1 = 3;
  if (((iFlags & 4U) == 0) && (iVar1 = 2, (iFlags & 2U) == 0)) {
    if (iNumber < 1) {
      return iFlags & 1;
    }
    iVar1 = 1;
    if (9 < iNumber) {
      return (99 < iNumber) + 2;
    }
  }
  return iVar1;
}


