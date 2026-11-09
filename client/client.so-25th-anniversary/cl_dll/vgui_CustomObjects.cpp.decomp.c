// Ghidra decompilation of functions from cl_dll/vgui_CustomObjects.cpp
// 32 functions, ordered by original source line

// GetTGANameForRes  @ 00089d30  (line 48)

char * GetTGANameForRes(char *pszName)

{
  undefined4 uVar1;
  int in_GS_OFFSET;
  undefined1 local_110 [256];
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] sz@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = 0x140;
  if (0x27f < gHUD.m_scrinfo.iWidth) {
    uVar1 = 0x280;
  }
  __sprintf_chk(local_110,1,0x100,pszName,uVar1);
  __sprintf_chk(GetTGANameForRes::gd,1,0x100,"gfx/vgui/%s.tga",local_110);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return GetTGANameForRes::gd;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// LoadTGAForRes  @ 00089de0  (line 65)

BitmapTGA * LoadTGAForRes(char *pImageName)

{
  undefined4 uVar1;
  BitmapTGA *pBVar2;
  int in_GS_OFFSET;
  undefined1 local_210 [256];
  undefined1 local_110 [256];
  int local_10;
  
                    /* Unresolved local var: BitmapTGA * pTGA@[???]
                       Unresolved local var: char[256] sz@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __sprintf_chk(local_210,1,0x100,"%%d_%s",pImageName);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] sz@[???] */
  uVar1 = 0x140;
  if (0x27f < gHUD.m_scrinfo.iWidth) {
    uVar1 = 0x280;
  }
  __sprintf_chk(local_110,1,0x100,local_210,uVar1);
  __sprintf_chk(GetTGANameForRes::gd,1,0x100,"gfx/vgui/%s.tga",local_110);
  pBVar2 = vgui_LoadTGA(GetTGANameForRes::gd);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pBVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CommandButton::CommandButton  @ 00089ec0  (line 77)

/* DWARF original prototype: void CommandButton(CommandButton * this, char * text, int x, int y, int
   wide, int tall, bool bNoHighlight) */

void __thiscall
CommandButton::CommandButton
          (CommandButton *this,char *text,int x,int y,int wide,int tall,bool bNoHighlight)

{
  undefined4 *puVar1;
  int in_GS_OFFSET;
  undefined1 local_90 [31];
  undefined1 local_71;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Button::Button(&this->super_Button,"",x,y,wide,tall);
  this->m_iPlayerClass = 0;
  *(undefined ***)this = &PTR_setPos_000c4fd0;
  this->m_bFlat = false;
  this->m_bNoHighlight = bNoHighlight;
  this->m_pSubMenu = (CCommandMenu *)0x0;
  this->m_pSubLabel = (CommandLabel *)0x0;
  this->m_pParentMenu = (CCommandMenu *)0x0;
  vgui::Label::setFgColor((SchemeColor)this);
  vgui::Label::setContentAlignment((Alignment)this);
  if (this->m_bNoHighlight == false) {
    puVar1 = operator_new(0xc);
    puVar1[1] = this;
    *puVar1 = &PTR_cursorMoved_000c4d6c;
    puVar1[2] = this;
    vgui::Panel::addInputSignal((InputSignal *)this);
  }
  this->m_cBoundKey = '\0';
  strncpy(this->m_sMainText,text,0x20);
                    /* Unresolved local var: char[128] szBuf@[???] */
  this->m_sMainText[0x1f] = '\0';
  __sprintf_chk(local_90,1,0x80,&DAT_000c4b69,this->m_sMainText);
  local_71 = 0;
  vgui::Label::setText((char *)this,local_90);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CommandButton::CommandButton  @ 0008a040  (line 86)

/* DWARF original prototype: void CommandButton(CommandButton * this, int iPlayerClass, char * text,
   int x, int y, int wide, int tall, bool bFlat) */

void __thiscall
CommandButton::CommandButton
          (CommandButton *this,int iPlayerClass,char *text,int x,int y,int wide,int tall,bool bFlat)

{
  undefined4 *puVar1;
  int in_GS_OFFSET;
  undefined1 local_90 [31];
  undefined1 local_71;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Button::Button(&this->super_Button,"",x,y,wide,tall);
  *(undefined ***)this = &PTR_setPos_000c4fd0;
  this->m_bNoHighlight = false;
  this->m_bFlat = bFlat;
  this->m_pSubMenu = (CCommandMenu *)0x0;
  this->m_pSubLabel = (CommandLabel *)0x0;
  this->m_pParentMenu = (CCommandMenu *)0x0;
  this->m_iPlayerClass = iPlayerClass;
  vgui::Label::setFgColor((SchemeColor)this);
  vgui::Label::setContentAlignment((Alignment)this);
  if (this->m_bNoHighlight == false) {
    puVar1 = operator_new(0xc);
    puVar1[1] = this;
    *puVar1 = &PTR_cursorMoved_000c4d6c;
    puVar1[2] = this;
    vgui::Panel::addInputSignal((InputSignal *)this);
  }
  this->m_cBoundKey = '\0';
  strncpy(this->m_sMainText,text,0x20);
                    /* Unresolved local var: char[128] szBuf@[???] */
  this->m_sMainText[0x1f] = '\0';
  __sprintf_chk(local_90,1,0x80,&DAT_000c4b69,this->m_sMainText);
  local_71 = 0;
  vgui::Label::setText((char *)this,local_90);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CommandButton::CommandButton  @ 0008a1c0  (line 95)

/* DWARF original prototype: void CommandButton(CommandButton * this, char * text, int x, int y, int
   wide, int tall, bool bNoHighlight, bool bFlat) */

void __thiscall
CommandButton::CommandButton
          (CommandButton *this,char *text,int x,int y,int wide,int tall,bool bNoHighlight,bool bFlat
          )

{
  undefined4 *puVar1;
  int in_GS_OFFSET;
  undefined1 local_90 [31];
  undefined1 local_71;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Button::Button(&this->super_Button,"",x,y,wide,tall);
  this->m_iPlayerClass = 0;
  *(undefined ***)this = &PTR_setPos_000c4fd0;
  this->m_bFlat = bFlat;
  this->m_bNoHighlight = bNoHighlight;
  this->m_pSubMenu = (CCommandMenu *)0x0;
  this->m_pSubLabel = (CommandLabel *)0x0;
  this->m_pParentMenu = (CCommandMenu *)0x0;
  vgui::Label::setFgColor((SchemeColor)this);
  vgui::Label::setContentAlignment((Alignment)this);
  if (this->m_bNoHighlight == false) {
    puVar1 = operator_new(0xc);
    puVar1[1] = this;
    *puVar1 = &PTR_cursorMoved_000c4d6c;
    puVar1[2] = this;
    vgui::Panel::addInputSignal((InputSignal *)this);
  }
  this->m_cBoundKey = '\0';
  strncpy(this->m_sMainText,text,0x20);
                    /* Unresolved local var: char[128] szBuf@[???] */
  this->m_sMainText[0x1f] = '\0';
  __sprintf_chk(local_90,1,0x80,&DAT_000c4b69,this->m_sMainText);
  local_71 = 0;
  vgui::Label::setText((char *)this,local_90);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CommandButton::Init  @ 0008a350  (line 105)

/* DWARF original prototype: void Init(CommandButton * this) */

void __thiscall CommandButton::Init(CommandButton *this)

{
  code *pcVar1;
  undefined4 *puVar2;
  
  this->m_pSubMenu = (CCommandMenu *)0x0;
  this->m_pSubLabel = (CommandLabel *)0x0;
  this->m_pParentMenu = (CCommandMenu *)0x0;
  (**(code **)(*(int *)this + 0x11c))(this,3);
  (**(code **)(*(int *)this + 0x21c))(this,3);
  if (this->m_bNoHighlight == false) {
    pcVar1 = *(code **)(*(int *)this + 0x70);
    puVar2 = operator_new(0xc);
    puVar2[1] = this;
    *puVar2 = &PTR_cursorMoved_000c4d6c;
    puVar2[2] = this;
    (*pcVar1)(this,puVar2);
  }
  this->m_cBoundKey = '\0';
  return;
}


// CommandButton::RecalculateText  @ 0008a3f0  (line 129)

/* DWARF original prototype: void RecalculateText(CommandButton * this) */

void __thiscall CommandButton::RecalculateText(CommandButton *this)

{
  char cVar1;
  int in_GS_OFFSET;
  undefined1 local_90 [31];
  undefined1 local_71;
  int local_10;
  
                    /* Unresolved local var: char[128] szBuf@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  cVar1 = this->m_cBoundKey;
  if (cVar1 == '\0') {
    __sprintf_chk(local_90,1,0x80,&DAT_000c4b69,this->m_sMainText);
  }
  else if (cVar1 == -1) {
    __strcpy_chk(local_90,this->m_sMainText,0x80);
  }
  else {
    __sprintf_chk(local_90,1,0x80,"  %c  %s",(int)cVar1,this->m_sMainText);
  }
  local_71 = 0;
  vgui::Label::setText((char *)this,local_90);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CommandButton::setText  @ 00089c20  (line 155)

/* DWARF original prototype: void setText(CommandButton * this, char * text) */

void __thiscall CommandButton::setText(CommandButton *this,char *text)

{
  char *__dest;
  char cVar1;
  int in_GS_OFFSET;
  undefined1 local_90 [31];
  undefined1 local_71;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __dest = this->m_sMainText;
  strncpy(__dest,text,0x20);
                    /* Unresolved local var: char[128] szBuf@[???] */
  cVar1 = this->m_cBoundKey;
  this->m_sMainText[0x1f] = '\0';
  if (cVar1 == '\0') {
    __sprintf_chk(local_90,1,0x80,&DAT_000c4b69,__dest);
  }
  else if (cVar1 == -1) {
    __strcpy_chk(local_90,__dest,0x80);
  }
  else {
    __sprintf_chk(local_90,1,0x80,"  %c  %s",(int)cVar1,__dest);
  }
  local_71 = 0;
  vgui::Label::setText((char *)this,local_90);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CommandButton::setBoundKey  @ 0008a4f0  (line 163)

/* DWARF original prototype: void setBoundKey(CommandButton * this, char boundKey) */

void __thiscall CommandButton::setBoundKey(CommandButton *this,char boundKey)

{
  int in_GS_OFFSET;
  undefined1 local_90 [31];
  undefined1 local_71;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: char[128] szBuf@[???] */
  this->m_cBoundKey = boundKey;
  if (boundKey == '\0') {
    __sprintf_chk(local_90,1,0x80,&DAT_000c4b69,this->m_sMainText);
  }
  else if (boundKey == -1) {
    __strcpy_chk(local_90,this->m_sMainText,0x80);
  }
  else {
    __sprintf_chk(local_90,1,0x80,"  %c  %s",(int)boundKey,this->m_sMainText);
  }
  local_71 = 0;
  vgui::Label::setText((char *)this,local_90);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CommandButton::getBoundKey  @ 0008a600  (line 170)

/* DWARF original prototype: char getBoundKey(CommandButton * this) */

char __thiscall CommandButton::getBoundKey(CommandButton *this)

{
  return this->m_cBoundKey;
}


// CommandButton::AddSubMenu  @ 0008a610  (line 174)

/* DWARF original prototype: void AddSubMenu(CommandButton * this, CCommandMenu * pNewMenu) */

void __thiscall CommandButton::AddSubMenu(CommandButton *this,CCommandMenu *pNewMenu)

{
  this->m_pSubMenu = pNewMenu;
  (**(code **)(*(int *)this + 0x250))(this,0,0);
  return;
}


// CommandButton::UpdateSubMenus  @ 0008a640  (line 183)

/* DWARF original prototype: void UpdateSubMenus(CommandButton * this, int iAdjustment) */

void __thiscall CommandButton::UpdateSubMenus(CommandButton *this,int iAdjustment)

{
  if (this->m_pSubMenu != (CCommandMenu *)0x0) {
    CCommandMenu::RecalculatePositions(this->m_pSubMenu,iAdjustment);
    return;
  }
  return;
}


// CommandButton::paint  @ 000898e0  (line 188)

/* DWARF original prototype: void paint(CommandButton * this) */

void __thiscall CommandButton::paint(CommandButton *this)

{
  CommandLabel *pCVar1;
  char cVar2;
  
  if (this->m_pSubLabel != (CommandLabel *)0x0) {
    cVar2 = (**(code **)(*(int *)this + 0x238))(this);
    pCVar1 = this->m_pSubLabel;
    if (cVar2 == '\0') {
      pCVar1->m_iState = 0;
      (**(code **)(*(int *)pCVar1 + 0x30))(pCVar1);
    }
    else {
      pCVar1->m_iState = 1;
      (**(code **)(*(int *)pCVar1 + 0x30))(pCVar1);
    }
  }
  cVar2 = (**(code **)(*(int *)this + 0x248))(this);
  if (cVar2 == '\0') {
    (**(code **)(*(int *)this + 0x11c))(this,3);
    vgui::Label::paint();
    return;
  }
  (**(code **)(*(int *)this + 0x11c))(this,7);
  vgui::Label::paint();
  return;
}


// CommandButton::paintBackground  @ 00089b30  (line 212)

/* DWARF original prototype: void paintBackground(CommandButton * this) */

void __thiscall CommandButton::paintBackground(CommandButton *this)

{
  char cVar1;
  
  if (this->m_bFlat == false) {
    cVar1 = (**(code **)(*(int *)this + 0x248))(this);
    if (cVar1 != '\0') {
      (**(code **)(*(int *)this + 0x174))(this,4);
      (**(code **)(*(int *)this + 0x17c))
                (this,0,0,*(undefined4 *)&this->field_0xc,*(undefined4 *)&this->field_0x10);
    }
  }
  else {
    cVar1 = (**(code **)(*(int *)this + 0x248))();
    if (cVar1 == '\0') {
      return;
    }
  }
  (**(code **)(*(int *)this + 0x174))(this,6);
  (**(code **)(*(int *)this + 0x180))
            (this,0,0,*(undefined4 *)&this->field_0xc,*(undefined4 *)&this->field_0x10);
  return;
}


// CommandButton::cursorEntered  @ 0008a670  (line 241)

/* DWARF original prototype: void cursorEntered(CommandButton * this) */

void __thiscall CommandButton::cursorEntered(CommandButton *this)

{
  CCommandMenu *pCVar1;
  CommandButton *pCVar2;
  CommandButton *pCVar3;
  CommandButton *pCVar4;
  CommandButton *pCVar5;
  CommandButton *this_00;
  
                    /* Unresolved local var: CCommandMenu * containingMenu@[???] */
  pCVar1 = this->m_pParentMenu;
  if (pCVar1 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[???] */
    CCommandMenu::ClearButtonsOfArmedState(pCVar1);
    if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
      pCVar2 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
                    /* Unresolved local var: CCommandMenu * containingMenu@[???] */
      pCVar1 = pCVar2->m_pParentMenu;
      if (pCVar1 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[???] */
        CCommandMenu::ClearButtonsOfArmedState(pCVar1);
        if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
          pCVar3 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
                    /* Unresolved local var: CCommandMenu * containingMenu@[???] */
          pCVar1 = pCVar3->m_pParentMenu;
          if (pCVar1 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[???] */
            CCommandMenu::ClearButtonsOfArmedState(pCVar1);
            if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
              pCVar4 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
                    /* Unresolved local var: CCommandMenu * containingMenu@[???] */
              pCVar1 = pCVar4->m_pParentMenu;
              if (pCVar1 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[???] */
                CCommandMenu::ClearButtonsOfArmedState(pCVar1);
                if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
                  pCVar5 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
                    /* Unresolved local var: CCommandMenu * containingMenu@[???] */
                  pCVar1 = pCVar5->m_pParentMenu;
                  if (pCVar1 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CCommandMenu * pCParent@[???] */
                    CCommandMenu::ClearButtonsOfArmedState(pCVar1);
                    if (pCVar1->m_pParentMenu != (CCommandMenu *)0x0) {
                    /* Unresolved local var: CommandButton * pParentButton@[???] */
                      this_00 = CCommandMenu::FindButtonWithSubmenu(pCVar1->m_pParentMenu,pCVar1);
                      cursorEntered(this_00);
                    }
                  }
                  (**(code **)(*(int *)pCVar5 + 0x234))(pCVar5,1);
                }
              }
              (**(code **)(*(int *)pCVar4 + 0x234))(pCVar4,1);
            }
          }
          (**(code **)(*(int *)pCVar3 + 0x234))(pCVar3,1);
        }
      }
      (**(code **)(*(int *)pCVar2 + 0x234))(pCVar2,1);
    }
  }
  (**(code **)(*(int *)this + 0x234))(this,1);
  return;
}


// CommandButton::cursorExited  @ 0008a820  (line 266)

/* DWARF original prototype: void cursorExited(CommandButton * this) */

void __thiscall CommandButton::cursorExited(CommandButton *this)

{
  if ((this->m_pParentMenu != (CCommandMenu *)0x0) && (this->m_pSubMenu != (CCommandMenu *)0x0)) {
    return;
  }
  (**(code **)(*(int *)this + 0x234))(this,0);
  return;
}


// CommandButton::getParentMenu  @ 0008a860  (line 282)

/* DWARF original prototype: CCommandMenu * getParentMenu(CommandButton * this) */

CCommandMenu * __thiscall CommandButton::getParentMenu(CommandButton *this)

{
  return this->m_pParentMenu;
}


// CommandButton::setParentMenu  @ 0008a870  (line 291)

/* DWARF original prototype: void setParentMenu(CommandButton * this, CCommandMenu * pParentMenu) */

void __thiscall CommandButton::setParentMenu(CommandButton *this,CCommandMenu *pParentMenu)

{
  this->m_pParentMenu = pParentMenu;
  return;
}


// ClassButton::IsNotValid  @ 00089a60  (line 297)

/* DWARF original prototype: int IsNotValid(ClassButton * this) */

int __thiscall ClassButton::IsNotValid(ClassButton *this)

{
  longdouble lVar1;
  
                    /* Unresolved local var: bool bAutoKill@[???] */
  if (this->m_iPlayerClass == -1) {
    return (uint)(gViewPort->m_iValidClasses[g_iTeamNumber] == -1);
  }
  if (((gViewPort->m_iValidClasses[0] & sTFValidClassInts[this->m_iPlayerClass]) == 0) &&
     ((sTFValidClassInts[this->m_iPlayerClass] & gViewPort->m_iValidClasses[g_iTeamNumber]) == 0)) {
    lVar1 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_classautokill");
    if (lVar1 == (longdouble)0) {
      return 0;
    }
    if (gViewPort->m_iRandomPC == 0) {
      if (this->m_iPlayerClass != g_iPlayerClass) {
        return 0;
      }
    }
    else if (this->m_iPlayerClass != 10) {
      return 0;
    }
  }
                    /* Unresolved local var: bool bAutoKill@[???] */
  return 1;
}


// CImageLabel::CImageLabel  @ 0008a880  (line 325)

/* DWARF original prototype: void CImageLabel(CImageLabel * this, char * pImageName, int x, int y)
    */

void __thiscall CImageLabel::CImageLabel(CImageLabel *this,char *pImageName,int x,int y)

{
  BitmapTGA *pBVar1;
  
  vgui::Label::Label(&this->super_Label,"",x,y);
  *(undefined ***)this = &PTR_setPos_000c54b0;
  vgui::Label::setContentFitted(SUB41(this,0));
  pBVar1 = LoadTGAForRes(pImageName);
  this->m_pTGA = pBVar1;
  vgui::Label::setImage((Image *)this);
  return;
}


// CImageLabel::CImageLabel  @ 0008a900  (line 332)

/* DWARF original prototype: void CImageLabel(CImageLabel * this, char * pImageName, int x, int y,
   int wide, int tall) */

void __thiscall
CImageLabel::CImageLabel(CImageLabel *this,char *pImageName,int x,int y,int wide,int tall)

{
  BitmapTGA *pBVar1;
  
  vgui::Label::Label(&this->super_Label,"",x,y,wide,tall);
  *(undefined ***)this = &PTR_setPos_000c54b0;
  vgui::Label::setContentFitted(SUB41(this,0));
  pBVar1 = LoadTGAForRes(pImageName);
  this->m_pTGA = pBVar1;
  vgui::Label::setImage((Image *)this);
  return;
}


// CImageLabel::getImageWide  @ 000895e0  (line 342)

/* DWARF original prototype: int getImageWide(CImageLabel * this) */

int __thiscall CImageLabel::getImageWide(CImageLabel *this)

{
  BitmapTGA *pBVar1;
  int local_14;
  undefined1 local_10 [16];
  
  pBVar1 = this->m_pTGA;
  if (pBVar1 != (BitmapTGA *)0x0) {
                    /* Unresolved local var: int iXSize@[???]
                       Unresolved local var: int iYSize@[???] */
    (**(code **)(*(int *)pBVar1 + 8))(pBVar1,&local_14,local_10);
    return local_14;
  }
  return 1;
}


// CImageLabel::getImageTall  @ 00089630  (line 356)

/* DWARF original prototype: int getImageTall(CImageLabel * this) */

int __thiscall CImageLabel::getImageTall(CImageLabel *this)

{
  BitmapTGA *pBVar1;
  undefined1 local_14 [4];
  int local_10 [4];
  
  pBVar1 = this->m_pTGA;
  if (pBVar1 != (BitmapTGA *)0x0) {
                    /* Unresolved local var: int iXSize@[???]
                       Unresolved local var: int iYSize@[???] */
    (**(code **)(*(int *)pBVar1 + 8))(pBVar1,local_14,local_10);
    return local_10[0];
  }
  return 1;
}


// CImageLabel::LoadImage  @ 0008a980  (line 370)

/* DWARF original prototype: void LoadImage(CImageLabel * this, char * pImageName) */

void __thiscall CImageLabel::LoadImage(CImageLabel *this,char *pImageName)

{
  int iVar1;
  undefined4 uVar2;
  BitmapTGA *pBVar3;
  char *pcVar4;
  FileInputStream *this_00;
  int in_GS_OFFSET;
  int local_218;
  int local_214;
  undefined1 local_210 [256];
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: int w@[???]
                       Unresolved local var: int t@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (this->m_pTGA != (BitmapTGA *)0x0) {
    operator_delete(this->m_pTGA);
  }
                    /* Unresolved local var: BitmapTGA * pTGA@[DW_OP_reg0(EAX)]
                       Unresolved local var: char[256] sz@[???] */
  __sprintf_chk(local_210,1,0x100,"%%d_%s",pImageName);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] sz@[???] */
  uVar2 = 0x280;
  if (gHUD.m_scrinfo.iWidth < 0x280) {
    uVar2 = 0x140;
  }
  __sprintf_chk(local_110,1,0x100,local_210,uVar2);
  __sprintf_chk(GetTGANameForRes::gd,1,0x100,"gfx/vgui/%s.tga",local_110);
  pBVar3 = vgui_LoadTGA(GetTGANameForRes::gd);
  this->m_pTGA = pBVar3;
  if (pBVar3 == (BitmapTGA *)0x0) {
                    /* Unresolved local var: char[256] sz@[???]
                       Unresolved local var: FileInputStream * fis@[???] */
    pcVar4 = (*gEngfuncs.pfnGetGameDirectory)();
    __sprintf_chk(local_110,1,0x100,"%s/%s",pcVar4,pImageName);
    this_00 = operator_new(8);
    vgui::FileInputStream::FileInputStream(this_00,local_110,false);
    pBVar3 = operator_new(0x30);
    vgui::BitmapTGA::BitmapTGA(pBVar3,(InputStream *)this_00,true);
    iVar1 = *(int *)this_00;
    this->m_pTGA = pBVar3;
    (**(code **)(iVar1 + 0x1c))(this_00);
    pBVar3 = this->m_pTGA;
    if (pBVar3 == (BitmapTGA *)0x0) goto LAB_0008aae1;
  }
  (**(code **)(*(int *)pBVar3 + 8))(pBVar3,&local_218,&local_214);
  (**(code **)(*(int *)this + 8))
            (this,(int)((float)local_218 * ((float)gHUD.m_scrinfo.iWidth / 640.0)),
             (int)((float)local_214 * ((float)gHUD.m_scrinfo.iHeight / 480.0)));
  (**(code **)(*(int *)this + 0x1fc))(this,this->m_pTGA);
LAB_0008aae1:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CCommandMenu::paintBackground  @ 00089680  (line 403)

/* DWARF original prototype: void paintBackground(CCommandMenu * this) */

void __thiscall CCommandMenu::paintBackground(CCommandMenu *this)

{
  if (this->m_iSpectCmdMenu == 0) {
    (**(code **)(*(int *)this + 0x174))(this,5);
  }
  else {
    (**(code **)(*(int *)this + 0x178))(this,0,0,0,0x40);
  }
  (**(code **)(*(int *)this + 0x17c))
            (this,0,0,*(undefined4 *)&this->field_0xc,*(undefined4 *)&this->field_0x10);
  return;
}


// CTFScrollButton::CTFScrollButton  @ 0008abc0  (line 417)

/* DWARF original prototype: void CTFScrollButton(CTFScrollButton * this, int iArrow, char * text,
   int x, int y, int wide, int tall) */

void __thiscall
CTFScrollButton::CTFScrollButton
          (CTFScrollButton *this,int iArrow,char *text,int x,int y,int wide,int tall)

{
  char *__dest;
  undefined4 *puVar1;
  BitmapTGA *pBVar2;
  int in_GS_OFFSET;
  undefined1 local_90 [31];
  undefined1 local_71;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Button::Button((Button *)this,"",x,y,wide,tall);
  (this->super_CommandButton).m_iPlayerClass = 0;
  (this->super_CommandButton).m_pSubMenu = (CCommandMenu *)0x0;
  (this->super_CommandButton).m_pSubLabel = (CommandLabel *)0x0;
  (this->super_CommandButton).m_pParentMenu = (CCommandMenu *)0x0;
  *(undefined ***)&this->super_CommandButton = &PTR_setPos_000c4fd0;
  (this->super_CommandButton).m_bNoHighlight = false;
  (this->super_CommandButton).m_bFlat = false;
  vgui::Label::setFgColor((SchemeColor)this);
  vgui::Label::setContentAlignment((Alignment)this);
  if ((this->super_CommandButton).m_bNoHighlight == false) {
    puVar1 = operator_new(0xc);
    puVar1[1] = this;
    *puVar1 = &PTR_cursorMoved_000c4d6c;
    puVar1[2] = this;
    vgui::Panel::addInputSignal((InputSignal *)this);
  }
  __dest = (this->super_CommandButton).m_sMainText;
  (this->super_CommandButton).m_cBoundKey = '\0';
                    /* Unresolved local var: InputSignal * pISignal@[???] */
  strncpy(__dest,text,0x20);
                    /* Unresolved local var: char[128] szBuf@[???] */
  (this->super_CommandButton).m_sMainText[0x1f] = '\0';
  __sprintf_chk(local_90,1,0x80,&DAT_000c4b69,__dest);
  local_71 = 0;
  vgui::Label::setText((char *)this,local_90);
  *(undefined ***)&this->super_CommandButton = &PTR_setPos_000c58f0;
  vgui::Label::setFgColor((SchemeColor)this);
  pBVar2 = LoadTGAForRes(sArrowFilenames[iArrow]);
  this->m_pTGA = pBVar2;
  vgui::Label::setImage((Image *)this);
  puVar1 = operator_new(0xc);
  puVar1[1] = this;
  *puVar1 = &PTR_cursorMoved_000c4d6c;
  puVar1[2] = this;
  vgui::Panel::addInputSignal((InputSignal *)this);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(this,puVar1);
}


// CTFScrollButton::paint  @ 00089990  (line 432)

/* DWARF original prototype: void paint(CTFScrollButton * this) */

void __thiscall CTFScrollButton::paint(CTFScrollButton *this)

{
  code *pcVar1;
  char cVar2;
  int in_GS_OFFSET;
  int iVar3;
  Color local_1c [12];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (this->m_pTGA != (BitmapTGA *)0x0) {
    cVar2 = (**(code **)(*(int *)&this->super_CommandButton + 0x248))(this);
    pcVar1 = *(code **)(*(int *)this->m_pTGA + 0xc);
    if (cVar2 == '\0') {
      iVar3 = 0x80;
    }
    else {
      iVar3 = 0;
    }
    vgui::Color::Color(local_1c,0xff,0xff,0xff,iVar3);
    (*pcVar1)(this->m_pTGA,local_1c);
    (**(code **)(*(int *)this->m_pTGA + 0x5c))(this->m_pTGA,this);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CTFScrollButton::paintBackground  @ 00089700  (line 450)

/* DWARF original prototype: void paintBackground(CTFScrollButton * this) */

void __thiscall CTFScrollButton::paintBackground(CTFScrollButton *this)

{
  return;
}


// CTFSlider::paintBackground  @ 00089710  (line 466)

/* DWARF original prototype: void paintBackground(CTFSlider * this) */

void __thiscall CTFSlider::paintBackground(CTFSlider *this)

{
  char cVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10 [3];
  
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: int nobx@[???]
                       Unresolved local var: int noby@[???] */
  (**(code **)(*(int *)this + 0xe8))(this,&local_1c,&local_18);
  (**(code **)(*(int *)this + 0x21c))(this,&local_14,local_10);
  (**(code **)(*(int *)this + 0x174))(this,6);
  (**(code **)(*(int *)this + 0x180))(this,0,0,local_1c,local_18);
  cVar1 = (**(code **)(*(int *)this + 0x204))(this);
  if (cVar1 == '\0') {
    (**(code **)(*(int *)this + 0x174))();
    (**(code **)(*(int *)this + 0x17c))(this,local_14,0,local_10[0],local_18);
    (**(code **)(*(int *)this + 0x174))(this,3);
    (**(code **)(*(int *)this + 0x180))(this,local_14,0,local_10[0],local_18);
    return;
  }
  (**(code **)(*(int *)this + 0x174))(this,4);
  (**(code **)(*(int *)this + 0x17c))(this,0,local_14,local_1c,local_10[0]);
  (**(code **)(*(int *)this + 0x174))(this,3);
  (**(code **)(*(int *)this + 0x180))(this,0,local_14,local_1c,local_10[0]);
  return;
}


// CTFScrollPanel::CTFScrollPanel  @ 0008ad90  (line 497)

/* DWARF original prototype: void CTFScrollPanel(CTFScrollPanel * this, int x, int y, int wide, int
   tall) */

void __thiscall CTFScrollPanel::CTFScrollPanel(CTFScrollPanel *this,int x,int y,int wide,int tall)

{
  code *pcVar1;
  int *piVar2;
  CTFScrollButton *pCVar3;
  Slider *pSVar4;
  
  vgui::ScrollPanel::ScrollPanel(&this->super_ScrollPanel,x,y,wide,tall);
  *(undefined ***)this = &PTR_setPos_000c4da0;
                    /* Unresolved local var: ScrollBar * pScrollBar@[???] */
  piVar2 = (int *)vgui::ScrollPanel::getVerticalScrollBar();
  pcVar1 = *(code **)(*piVar2 + 0x21c);
  pCVar3 = operator_new(0x134);
  CTFScrollButton::CTFScrollButton(pCVar3,0,"",0,0,0x10,0x10);
  (*pcVar1)(piVar2,pCVar3,0);
  pcVar1 = *(code **)(*piVar2 + 0x21c);
  pCVar3 = operator_new(0x134);
  CTFScrollButton::CTFScrollButton(pCVar3,1,"",0,0,0x10,0x10);
  (*pcVar1)(piVar2,pCVar3,1);
  pcVar1 = *(code **)(*piVar2 + 0x224);
  pSVar4 = operator_new(0xfc);
  vgui::Slider::Slider(pSVar4,0,wide + -1,wide,tall + wide * -2 + 2,true);
  *(undefined ***)pSVar4 = &PTR_setPos_000c5b60;
  (*pcVar1)(piVar2,pSVar4);
  (**(code **)(*piVar2 + 0xd8))(piVar2,0);
  (**(code **)(*piVar2 + 0xdc))(piVar2,0);
  (**(code **)(*piVar2 + 0xe0))(piVar2,0);
  piVar2 = (int *)vgui::ScrollPanel::getHorizontalScrollBar();
  pcVar1 = *(code **)(*piVar2 + 0x21c);
  pCVar3 = operator_new(0x134);
  CTFScrollButton::CTFScrollButton(pCVar3,2,"",0,0,0x10,0x10);
  (*pcVar1)(piVar2,pCVar3,0);
  pcVar1 = *(code **)(*piVar2 + 0x21c);
  pCVar3 = operator_new(0x134);
  CTFScrollButton::CTFScrollButton(pCVar3,3,"",0,0,0x10,0x10);
  (*pcVar1)(piVar2,pCVar3,1);
  pcVar1 = *(code **)(*piVar2 + 0x224);
  pSVar4 = operator_new(0xfc);
  vgui::Slider::Slider(pSVar4,tall,0,wide + tall * -2,tall,false);
  *(undefined ***)pSVar4 = &PTR_setPos_000c5b60;
  (*pcVar1)(piVar2,pSVar4);
  (**(code **)(*piVar2 + 0xd8))(piVar2,0);
  (**(code **)(*piVar2 + 0xdc))(piVar2,0);
                    /* WARNING: Could not recover jumptable at 0x0008b09f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0xe0))();
  return;
}


// CHandler_MenuButtonOver::cursorEntered  @ 000898a0  (line 522)

/* DWARF original prototype: void cursorEntered(CHandler_MenuButtonOver * this, Panel * panel) */

void __thiscall CHandler_MenuButtonOver::cursorEntered(CHandler_MenuButtonOver *this,Panel *panel)

{
  if ((gViewPort != (TeamFortressViewport *)0x0) && (this->m_pMenuPanel != (CMenuPanel *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000898c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)&this->m_pMenuPanel->super_CTransparentPanel + 0x20c))();
    return;
  }
  return;
}


// CMenuHandler_StringCommandClassSelect::actionPerformed  @ 00089be0  (line 529)

/* DWARF original prototype: void actionPerformed(CMenuHandler_StringCommandClassSelect * this,
   Panel * panel) */

void __thiscall
CMenuHandler_StringCommandClassSelect::actionPerformed
          (CMenuHandler_StringCommandClassSelect *this,Panel *panel)

{
  (*gEngfuncs.pfnClientCmd)((this->super_CMenuHandler_StringCommand).m_pszCommand);
  if ((this->super_CMenuHandler_StringCommand).m_iCloseVGUIMenu == 0) {
    TeamFortressViewport::HideCommandMenu(gViewPort);
    return;
  }
  TeamFortressViewport::HideTopMenu(gViewPort);
  return;
}


