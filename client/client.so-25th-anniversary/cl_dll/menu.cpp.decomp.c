// Ghidra decompilation of functions from cl_dll/menu.cpp
// 9 functions, ordered by original source line

// __MsgFunc_ShowMenu  @ 00077260  (line 35)

int __MsgFunc_ShowMenu(char *pszName,int iSize,void *pbuf)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  char *local_10 [2];
  
                    /* Unresolved local var: char * temp@[???]
                       Unresolved local var: int DisplayTime@[???]
                       Unresolved local var: int NeedMore@[???] */
  local_10[0] = (char *)0x0;
  BEGIN_READ(pbuf,iSize);
  gHUD.m_Menu.m_bitsValidSlots = READ_SHORT();
  iVar2 = READ_CHAR();
  iVar3 = READ_BYTE();
  if (iVar2 < 1) {
    gHUD.m_Menu.m_flShutoffTime = -1.0;
  }
  else {
    gHUD.m_Menu.m_flShutoffTime = (float)iVar2 + gHUD.m_flTime;
  }
  if (gHUD.m_Menu.m_bitsValidSlots == 0) {
    gHUD.m_Menu.super_CHudBase.m_iFlags = gHUD.m_Menu.super_CHudBase.m_iFlags & 0xfffffffe;
    gHUD.m_Menu.m_fMenuDisplayed = 0;
  }
  else {
    if (gHUD.m_Menu.m_fWaitingForMore == 0) {
      pcVar4 = READ_STRING();
      strncpy(g_szPrelocalisedMenuString,pcVar4,0x200);
    }
    else {
      puVar8 = (uint *)g_szPrelocalisedMenuString;
      do {
        puVar7 = puVar8;
        uVar5 = *puVar7 + 0xfefefeff & ~*puVar7;
        uVar6 = uVar5 & 0x80808080;
        puVar8 = puVar7 + 1;
      } while (uVar6 == 0);
      bVar1 = (byte)uVar6;
      if ((uVar5 & 0x8080) == 0) {
        bVar1 = (byte)(uVar6 >> 0x10);
        puVar8 = (uint *)((int)puVar7 + 6);
      }
      pcVar4 = READ_STRING();
      __strncat_chk(g_szPrelocalisedMenuString,pcVar4,
                    0x200 - ((int)puVar8 + (-0x107fe3 - (uint)CARRY1(bVar1,bVar1))),0x200);
    }
    g_szPrelocalisedMenuString[0x1ff] = '\0';
    if (iVar3 == 0) {
      g_szPrelocalisedMenuString[0x1ff] = '\0';
      pcVar4 = CHudTextMessage::BufferedLocaliseTextString(g_szPrelocalisedMenuString);
      strncpy(g_szMenuString,pcVar4,0x200);
      g_szMenuString[0x1ff] = '\0';
      iVar2 = KB_ConvertString(g_szMenuString,local_10);
      pcVar4 = local_10[0];
      if (iVar2 != 0) {
        strncpy(g_szMenuString,local_10[0],0x200);
        g_szMenuString[0x1ff] = '\0';
        free(pcVar4);
      }
    }
    gHUD.m_Menu.m_fMenuDisplayed = 1;
    gHUD.m_Menu.super_CHudBase.m_iFlags = gHUD.m_Menu.super_CHudBase.m_iFlags | 1;
  }
  gHUD.m_Menu.m_fWaitingForMore = iVar3;
  return 1;
}


// CHudMenu::Init  @ 000771d0  (line 38)

/* DWARF original prototype: int Init(CHudMenu * this) */

int __thiscall CHudMenu::Init(CHudMenu *this)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  (*gEngfuncs.pfnHookUserMsg)("ShowMenu",__MsgFunc_ShowMenu);
  pp_Var1 = (this->super_CHudBase)._vptr_CHudBase;
  p_Var2 = pp_Var1[7];
  if (p_Var2 != InitHUDData) {
    (*p_Var2)(this);
    return 1;
  }
  this->m_fMenuDisplayed = 0;
  this->m_bitsValidSlots = 0;
  p_Var2 = pp_Var1[6];
  if (p_Var2 == Reset) {
    g_szPrelocalisedMenuString[0] = '\0';
    this->m_fWaitingForMore = 0;
    return 1;
  }
  (*p_Var2)(this);
  return 1;
}


// CHudMenu::InitHUDData  @ 00077190  (line 49)

/* DWARF original prototype: void InitHUDData(CHudMenu * this) */

void __thiscall CHudMenu::InitHUDData(CHudMenu *this)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  
  pp_Var1 = (this->super_CHudBase)._vptr_CHudBase;
  this->m_fMenuDisplayed = 0;
  this->m_bitsValidSlots = 0;
  UNRECOVERED_JUMPTABLE = pp_Var1[6];
  if (UNRECOVERED_JUMPTABLE == Reset) {
    g_szPrelocalisedMenuString[0] = '\0';
    this->m_fWaitingForMore = 0;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000771c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CHudMenu::Reset  @ 00076db0  (line 58)

/* DWARF original prototype: void Reset(CHudMenu * this) */

void __thiscall CHudMenu::Reset(CHudMenu *this)

{
  g_szPrelocalisedMenuString[0] = '\0';
  this->m_fWaitingForMore = 0;
  return;
}


// CHudMenu::VidInit  @ 00076dd0  (line 64)

/* DWARF original prototype: int VidInit(CHudMenu * this) */

int __thiscall CHudMenu::VidInit(CHudMenu *this)

{
  return 1;
}


// CHudMenu::Draw  @ 00076de0  (line 129)

/* DWARF original prototype: int Draw(CHudMenu * this, float flTime) */

int __thiscall CHudMenu::Draw(CHudMenu *this,float flTime)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int in_GS_OFFSET;
  int local_298;
  SCREENINFO_s local_284;
  char local_70 [80];
  int local_20;
  
                    /* Unresolved local var: SCREENINFO screenInfo@[???]
                       Unresolved local var: int nlc@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int nFontHeight@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: char * sptr@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_284.iSize = 0x214;
  (*gEngfuncs.pfnGetScreenInfo)(&local_284);
  iVar6 = 0;
  iVar4 = 0;
  do {
    pcVar8 = g_szMenuString + iVar4;
    if (*pcVar8 == '\0') break;
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + (uint)(*pcVar8 == '\n');
  } while (iVar4 != 0x200);
                    /* Unresolved local var: char[80] menubuf@[???]
                       Unresolved local var: char * ptr@[???] */
  iVar4 = 0xc;
  if (0xb < local_284.iCharHeight) {
    iVar4 = local_284.iCharHeight;
  }
  pcVar8 = g_szMenuString;
  local_298 = (gHUD.m_scrinfo.iHeight / 2 - (iVar6 >> 1) * iVar4) - (iVar4 * 3 + iVar4 / 3);
  menu_r = 0xff;
  menu_g = 0xff;
  menu_b = 0xff;
  uVar5 = (uint)(byte)g_szMenuString[0];
  menu_x = 0x14;
  menu_ralign = 0;
LAB_00076ec2:
  bVar3 = (byte)uVar5;
  do {
    if (bVar3 == 0) {
LAB_00076f9c:
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return uVar5;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    if ((char)uVar5 == '\\') {
      bVar3 = pcVar8[1];
      uVar5 = (uint)bVar3;
      if (bVar3 == 100) {
        menu_r = 100;
        menu_g = 100;
        menu_b = 100;
      }
      else if ((char)bVar3 < 'e') {
        if (bVar3 == 0) goto LAB_00076f9c;
        if (bVar3 == 0x52) {
          menu_x = gHUD.m_scrinfo.iWidth / 2;
          menu_ralign = 1;
        }
      }
      else if (bVar3 == 0x77) {
        menu_r = 0xff;
        menu_g = 0xff;
        menu_b = 0xff;
      }
      else if (bVar3 == 0x79) {
        menu_r = 0xff;
        menu_g = 0xd2;
        menu_b = 0x40;
      }
      else if (bVar3 == 0x72) {
        menu_r = 0xd2;
        menu_g = 0x18;
        menu_b = 0;
      }
      uVar5 = (uint)(byte)pcVar8[2];
      pcVar8 = pcVar8 + 2;
      goto LAB_00076ec2;
    }
    pcVar1 = pcVar8;
    if ((char)uVar5 == '\n') break;
    do {
      pcVar7 = pcVar1;
      cVar2 = pcVar7[1];
      pcVar1 = pcVar7 + 1;
      if (cVar2 == '\0' || cVar2 == '\n') break;
    } while (cVar2 != '\\');
    iVar6 = (int)pcVar1 - (int)pcVar8;
    if (iVar6 < 0x51) {
      __strncpy_chk(local_70,pcVar8,iVar6,0x50);
      if (0x4f < iVar6) {
        iVar6 = 0x4f;
      }
    }
    else {
      strncpy(local_70,pcVar8,0x50);
      iVar6 = 0x4f;
    }
    local_70[iVar6] = '\0';
    if (menu_ralign == 0) {
      menu_x = CHud::DrawHudString(&gHUD,menu_x,local_298,0x140,local_70,menu_r,menu_g,menu_b);
    }
    else {
      menu_x = CHud::DrawHudStringReverse(&gHUD,menu_x,local_298,0,local_70,menu_r,menu_g,menu_b);
    }
    bVar3 = pcVar7[1];
    uVar5 = (uint)bVar3;
    pcVar8 = pcVar1;
  } while( true );
  uVar5 = (uint)(byte)pcVar8[1];
  menu_x = 0x14;
  pcVar8 = pcVar8 + 1;
  menu_ralign = 0;
  local_298 = local_298 + iVar4;
  goto LAB_00076ec2;
}


// CHudMenu::Draw  @ 00077110  (line 130)

/* DWARF original prototype: int Draw(CHudMenu * this, float flTime) */

int __thiscall CHudMenu::Draw(CHudMenu *this,float flTime)

{
  int *piVar1;
  bool bVar2;
  TeamFortressViewport *in_stack_ffffffe4;
  float in_stack_ffffffe8;
  
                    /* Unresolved local var: SCREENINFO screenInfo@[???]
                       Unresolved local var: int nlc@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int nFontHeight@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: char * sptr@[???] */
  if ((0.0 < this->m_flShutoffTime) && (this->m_flShutoffTime <= gHUD.m_flTime)) {
    this->m_fMenuDisplayed = 0;
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 & 0xfffffffe;
    return 1;
  }
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (in_stack_ffffffe4 = gViewPort, bVar2 = TeamFortressViewport::IsScoreBoardVisible(gViewPort),
     bVar2)) {
    return 1;
  }
  Draw((CHudMenu *)in_stack_ffffffe4,in_stack_ffffffe8);
  return 1;
}


// CHudMenu::SelectMenuItem  @ 00077430  (line 216)

/* DWARF original prototype: void SelectMenuItem(CHudMenu * this, int menu_item) */

void __thiscall CHudMenu::SelectMenuItem(CHudMenu *this,int menu_item)

{
  int *piVar1;
  int in_GS_OFFSET;
  char local_30 [32];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((0 < menu_item) && ((this->m_bitsValidSlots >> ((char)menu_item - 1U & 0x1f) & 1U) != 0)) {
                    /* Unresolved local var: char[32] szbuf@[???] */
    __sprintf_chk(local_30,1,0x20,"menuselect %d\n",menu_item);
    (*gEngfuncs.pfnClientCmd)(local_30);
    this->m_fMenuDisplayed = 0;
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 & 0xfffffffe;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHudMenu::MsgFunc_ShowMenu  @ 000774d0  (line 239)

/* DWARF original prototype: int MsgFunc_ShowMenu(CHudMenu * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHudMenu::MsgFunc_ShowMenu(CHudMenu *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  char *local_10;
  
                    /* Unresolved local var: char * temp@[???]
                       Unresolved local var: int DisplayTime@[???]
                       Unresolved local var: int NeedMore@[???] */
  local_10 = (char *)0x0;
  BEGIN_READ(pbuf,iSize);
  iVar4 = READ_SHORT();
  this->m_bitsValidSlots = iVar4;
  iVar4 = READ_CHAR();
  iVar5 = READ_BYTE();
  if (iVar4 < 1) {
    fVar2 = -1.0;
  }
  else {
    fVar2 = (float)iVar4 + gHUD.m_flTime;
  }
  this->m_flShutoffTime = fVar2;
  if (this->m_bitsValidSlots == 0) {
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 & 0xfffffffe;
    this->m_fMenuDisplayed = 0;
  }
  else {
    if (this->m_fWaitingForMore == 0) {
      pcVar6 = READ_STRING();
      strncpy(g_szPrelocalisedMenuString,pcVar6,0x200);
    }
    else {
      puVar10 = (uint *)g_szPrelocalisedMenuString;
      do {
        puVar9 = puVar10;
        uVar7 = *puVar9 + 0xfefefeff & ~*puVar9;
        uVar8 = uVar7 & 0x80808080;
        puVar10 = puVar9 + 1;
      } while (uVar8 == 0);
      bVar3 = (byte)uVar8;
      if ((uVar7 & 0x8080) == 0) {
        bVar3 = (byte)(uVar8 >> 0x10);
        puVar10 = (uint *)((int)puVar9 + 6);
      }
      pcVar6 = READ_STRING();
      __strncat_chk(g_szPrelocalisedMenuString,pcVar6,
                    0x200 - ((int)puVar10 + (-0x107fe3 - (uint)CARRY1(bVar3,bVar3))),0x200);
    }
    g_szPrelocalisedMenuString[0x1ff] = '\0';
    if (iVar5 == 0) {
      g_szPrelocalisedMenuString[0x1ff] = '\0';
      pcVar6 = CHudTextMessage::BufferedLocaliseTextString(g_szPrelocalisedMenuString);
      strncpy(g_szMenuString,pcVar6,0x200);
      g_szMenuString[0x1ff] = '\0';
      iVar4 = KB_ConvertString(g_szMenuString,&local_10);
      pcVar6 = local_10;
      if (iVar4 != 0) {
        strncpy(g_szMenuString,local_10,0x200);
        g_szMenuString[0x1ff] = '\0';
        free(pcVar6);
      }
    }
    this->m_fMenuDisplayed = 1;
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 | 1;
  }
  this->m_fWaitingForMore = iVar5;
  return 1;
}


