// Ghidra decompilation of functions from cl_dll/vgui_ScorePanel.h
// 13 functions, ordered by original source line

// CLabelHeader::setFont  @ 00091590  (line 49)

/* DWARF original prototype: void setFont(CLabelHeader * this, Font * font) */

void __thiscall CLabelHeader::setFont(CLabelHeader *this,Font *font)

{
                    /* WARNING: Could not recover jumptable at 0x000915a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_dualImage->_image[0] + 0x7c))();
  return;
}


// CTextImage2::getSize  @ 00091300  (line 52)

/* DWARF original prototype: void getSize(CTextImage2 * this, int * wide, int * tall) */

void __thiscall CTextImage2::getSize(CTextImage2 *this,int *wide,int *tall)

{
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [2];
  
                    /* Unresolved local var: int w1@[???]
                       Unresolved local var: int w2@[???]
                       Unresolved local var: int t1@[???]
                       Unresolved local var: int t2@[???] */
  (**(code **)(*(int *)this->_image[0] + 100))(this->_image[0],&local_1c,&local_14);
  (**(code **)(*(int *)this->_image[1] + 100))(this->_image[1],&local_18,local_10);
  *wide = local_18 + local_1c;
  if (local_10[0] <= local_14) {
    local_10[0] = local_14;
  }
  *tall = local_10[0];
  (**(code **)(*(int *)this + 0x14))(this,*wide,local_10[0]);
  return;
}


// CTextImage2::doPaint  @ 00091380  (line 63)

/* DWARF original prototype: void doPaint(CTextImage2 * this, Panel * panel) */

void __thiscall CTextImage2::doPaint(CTextImage2 *this,Panel *panel)

{
  (**(code **)(*(int *)this->_image[0] + 0x5c))(this->_image[0],panel);
                    /* WARNING: Could not recover jumptable at 0x000913bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_image[1] + 0x5c))();
  return;
}


// CTextImage2::setPos  @ 000913c0  (line 69)

/* DWARF original prototype: void setPos(CTextImage2 * this, int x, int y) */

void __thiscall CTextImage2::setPos(CTextImage2 *this,int x,int y)

{
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  int local_10 [2];
  
                    /* Unresolved local var: int swide@[???]
                       Unresolved local var: int stall@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  (*(code *)**(undefined4 **)this->_image[0])(this->_image[0],x,y);
  (**(code **)(*(int *)this->_image[0] + 8))(this->_image[0],local_1c,&local_18);
  (**(code **)(*(int *)this->_image[1] + 8))(this->_image[1],&local_14,local_10);
  (*(code *)**(undefined4 **)this->_image[1])
            (this->_image[1],x + local_14,
             (int)(((double)y + (double)local_18 * 0.9) - (double)local_10[0]));
  return;
}


// CTextImage2::setColor  @ 00091460  (line 81)

/* DWARF original prototype: void setColor(CTextImage2 * this, Color color) */

void __thiscall CTextImage2::setColor(CTextImage2 *this,int param_2)

{
  int in_GS_OFFSET;
  code *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_1c = isalnum;
  local_18 = *(undefined4 *)(param_2 + 4);
  local_14 = *(undefined4 *)(param_2 + 8);
  (**(code **)(*(int *)this->_image[0] + 0xc))(this->_image[0],&local_1c);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CLabelHeader::~CLabelHeader  @ 00091bb0  (line 112)

/* DWARF original prototype: void ~CLabelHeader(CLabelHeader * this, int __in_chrg) */

void __thiscall CLabelHeader::~CLabelHeader(CLabelHeader *this,int __in_chrg)

{
  CTextImage2 *pCVar1;
  
  pCVar1 = this->_dualImage;
  *(undefined ***)this = &PTR_setPos_000c6964;
  if (pCVar1 != (CTextImage2 *)0x0) {
    *(undefined ***)pCVar1 = &PTR_setPos_000c64b8;
    operator_delete(pCVar1->_image[0]);
    operator_delete(pCVar1->_image[1]);
    operator_delete(pCVar1);
    return;
  }
  return;
}


// CLabelHeader::setText  @ 000914c0  (line 127)

/* DWARF original prototype: void setText(CLabelHeader * this, int textBufferLen, char * text) */

void __thiscall CLabelHeader::setText(CLabelHeader *this,int textBufferLen,char *text)

{
  char cVar1;
  TextImage *pTVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: Font * font@[???] */
  pTVar2 = this->_dualImage->_image[0];
  (**(code **)(*(int *)pTVar2 + 0x74))(pTVar2,text);
  pTVar2 = this->_dualImage->_image[0];
  piVar4 = (int *)(**(code **)(*(int *)pTVar2 + 0x6c))(pTVar2);
  this->_gap = 0;
                    /* Unresolved local var: char * ch@[???] */
  cVar1 = *text;
  if (cVar1 == '\0') {
    fVar3 = 0.0;
  }
  else {
    do {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
      text = text + 1;
      (**(code **)(*piVar4 + 8))(piVar4,(int)cVar1,&local_28,&local_24,local_20);
      iVar5 = local_24 + local_28 + local_20[0] + this->_gap;
      this->_gap = iVar5;
      cVar1 = *text;
    } while (cVar1 != '\0');
    fVar3 = (float)iVar5;
  }
  this->_gap = (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 5.0 + fVar3);
  return;
}


// CLabelHeader::setText  @ 000918b0  (line 144)

/* DWARF original prototype: void setText(CLabelHeader * this, char * text) */

void __thiscall CLabelHeader::setText(CLabelHeader *this,char *text)

{
  TextImage *pTVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  int in_GS_OFFSET;
  int local_22c;
  int local_228;
  undefined4 local_224;
  char local_220 [512];
  int local_20;
  
                    /* Unresolved local var: char[512] buf@[???]
                       Unresolved local var: int len@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar6 = local_220;
  iVar3 = __stpcpy_chk(pcVar6,text,0x200);
  iVar3 = iVar3 - (int)pcVar6;
  while (iVar3 != 0) {
    iVar3 = iVar3 + -1;
    iVar4 = isspace((int)pcVar6[iVar3]);
    if (iVar4 == 0) break;
    pcVar6[iVar3] = '\0';
  }
                    /* Unresolved local var: Font * font@[???] */
  pTVar1 = this->_dualImage->_image[0];
  (**(code **)(*(int *)pTVar1 + 0x74))(pTVar1,pcVar6);
  pTVar1 = this->_dualImage->_image[0];
  piVar5 = (int *)(**(code **)(*(int *)pTVar1 + 0x6c))(pTVar1);
  this->_gap = 0;
                    /* Unresolved local var: char * ch@[???] */
  if (local_220[0] == '\0') {
    fVar2 = 0.0;
  }
  else {
    do {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
      pcVar6 = pcVar6 + 1;
      (**(code **)(*piVar5 + 8))(piVar5,(int)local_220[0],&local_22c,&local_228,&local_224);
      iVar3 = local_228 + local_22c + local_224 + this->_gap;
      local_220[0] = *pcVar6;
      this->_gap = iVar3;
    } while (local_220[0] != '\0');
    fVar2 = (float)iVar3;
  }
  this->_gap = (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 5.0 + fVar2);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CLabelHeader::getTextSize  @ 00091800  (line 164)

/* DWARF original prototype: void getTextSize(CLabelHeader * this, int * wide, int * tall) */

void __thiscall CLabelHeader::getTextSize(CLabelHeader *this,int *wide,int *tall)

{
  CTextImage2 *pCVar1;
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [2];
  
  pCVar1 = this->_dualImage;
  if (*(code **)(*(int *)pCVar1 + 8) == CTextImage2::getSize) {
                    /* Unresolved local var: int w1@[???]
                       Unresolved local var: int w2@[???]
                       Unresolved local var: int t1@[???]
                       Unresolved local var: int t2@[???] */
    (**(code **)(*(int *)pCVar1->_image[0] + 100))(pCVar1->_image[0],&local_1c,&local_14);
    (**(code **)(*(int *)pCVar1->_image[1] + 100))(pCVar1->_image[1],&local_18,local_10);
    *wide = local_18 + local_1c;
    if (local_10[0] <= local_14) {
      local_10[0] = local_14;
    }
    *tall = local_10[0];
    (**(code **)(*(int *)pCVar1 + 0x14))(pCVar1,*wide,local_10[0]);
    return;
  }
  (**(code **)(*(int *)pCVar1 + 8))(pCVar1,wide,tall);
  return;
}


// CLabelHeader::setFgColor  @ 000916c0  (line 169)

/* DWARF original prototype: void setFgColor(CLabelHeader * this, int r, int g, int b, int a) */

void __thiscall CLabelHeader::setFgColor(CLabelHeader *this,int r,int g,int b,int a)

{
  CTextImage2 *pCVar1;
  TextImage *pTVar2;
  int in_GS_OFFSET;
  Color local_44 [4];
  undefined4 local_40;
  undefined4 local_3c;
  code *local_38;
  undefined4 local_34;
  undefined4 local_30;
  code *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
                    /* Unresolved local var: Color color@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Label::setFgColor((int)this,r,g,b);
  vgui::Color::Color(local_44,r,g,b,a);
  pCVar1 = this->_dualImage;
  local_38 = isalnum;
  local_34 = local_40;
  local_30 = local_3c;
  if (*(code **)(*(int *)pCVar1 + 0xc) == CTextImage2::setColor) {
    local_28 = local_40;
    local_2c = isalnum;
    local_24 = local_3c;
    (**(code **)(*(int *)pCVar1->_image[0] + 0xc))(pCVar1->_image[0],&local_2c);
  }
  else {
    (**(code **)(*(int *)pCVar1 + 0xc))(pCVar1,&local_38);
  }
  local_34 = local_40;
  pTVar2 = this->_dualImage->_image[1];
  local_28 = local_40;
  local_2c = isalnum;
  local_24 = local_3c;
  (**(code **)(*(int *)pTVar2 + 0xc))(pTVar2,&local_2c);
  (**(code **)(*(int *)this + 0x30))(this);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CLabelHeader::setFgColor  @ 00091a20  (line 178)

/* DWARF original prototype: void setFgColor(CLabelHeader * this, SchemeColor sc) */

void __thiscall CLabelHeader::setFgColor(CLabelHeader *this,SchemeColor sc)

{
  CTextImage2 *pCVar1;
  TextImage *pTVar2;
  int in_GS_OFFSET;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  Color local_44 [4];
  undefined4 local_40;
  undefined4 local_3c;
  code *local_38;
  undefined4 local_34;
  undefined4 local_30;
  code *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Label::setFgColor((SchemeColor)this);
  vgui::Panel::getFgColor((int *)this,&local_54,&local_50,&local_4c);
                    /* Unresolved local var: Color color@[???] */
  if (*(code **)(*(int *)this + 0x124) == setFgColor) {
    vgui::Label::setFgColor((int)this,local_54,local_50,local_4c);
    vgui::Color::Color(local_44,local_54,local_50,local_4c,local_48);
    pCVar1 = this->_dualImage;
    local_38 = isalnum;
    local_34 = local_40;
    local_30 = local_3c;
    if (*(code **)(*(int *)pCVar1 + 0xc) == CTextImage2::setColor) {
      local_2c = isalnum;
      local_28 = local_40;
      local_24 = local_3c;
      (**(code **)(*(int *)pCVar1->_image[0] + 0xc))(pCVar1->_image[0],&local_2c);
    }
    else {
      (**(code **)(*(int *)pCVar1 + 0xc))(pCVar1,&local_38);
    }
    local_34 = local_40;
    pTVar2 = this->_dualImage->_image[1];
    local_28 = local_40;
    local_2c = isalnum;
    local_24 = local_3c;
    (**(code **)(*(int *)pTVar2 + 0xc))(pTVar2,&local_2c);
    (**(code **)(*(int *)this + 0x30))(this);
  }
  else {
    (**(code **)(*(int *)this + 0x124))(this,local_54,local_50,local_4c,local_48);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ScorePanel::mousePressed  @ 0008d4a0  (line 301)

/* non-virtual thunk to ScorePanel::mousePressed(vgui::MouseCode, vgui::Panel*) */

void __thiscall ScorePanel::mousePressed(ScorePanel *this,MouseCode param_1,Panel *param_2)

{
  mousePressed((ScorePanel *)(this[-1].m_iIsATeam + 0x2d),param_1,param_2);
  return;
}


// ScorePanel::cursorMoved  @ 0008d5d0  (line 302)

/* non-virtual thunk to ScorePanel::cursorMoved(int, int, vgui::Panel*) */

void __thiscall ScorePanel::cursorMoved(ScorePanel *this,int param_1,int param_2,Panel *param_3)

{
  cursorMoved((ScorePanel *)(this[-1].m_iIsATeam + 0x2d),param_1,param_2,param_3);
  return;
}


