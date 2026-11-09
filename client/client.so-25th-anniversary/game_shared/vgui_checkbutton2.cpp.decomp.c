// Ghidra decompilation of functions from game_shared/vgui_checkbutton2.cpp
// 15 functions, ordered by original source line

// vgui::CCheckButton2::CCheckButton2  @ 000a6f90  (line 21)

/* DWARF original prototype: void CCheckButton2(CCheckButton2 * this) */

void __thiscall vgui::CCheckButton2::CCheckButton2(CCheckButton2 *this)

{
  Label *this_00;
  ImagePanel *this_01;
  
  this_00 = &this->m_Label;
  vgui::Panel::Panel(&this->super_Panel);
  this->m_pHandler = (ICheckButton2Handler *)0x0;
  this_01 = &this->m_CheckboxPanel;
  (this->super_CDefaultInputSignal).super_InputSignal._vptr_InputSignal =
       (_func_int_varargs **)&PTR_cursorMoved_000cb2fc;
  *(undefined ***)this = &PTR_setPos_000cb0f4;
  vgui::Label::Label(this_00,"");
  vgui::ImagePanel::ImagePanel(this_01,(Image *)0x0);
  this->m_pChecked = (Image *)0x0;
  this->m_pUnchecked = (Image *)0x0;
  this->m_bOwnImages = false;
  this->m_bChecked = false;
  this->m_bCheckboxLeft = true;
  vgui::Panel::setParent((Panel *)this_00);
  vgui::Label::setFgColor((int)this_00,0xff,0xff,0xff);
  vgui::Panel::setBgColor((int)this_00,0,0,0);
  vgui::Panel::addInputSignal((InputSignal *)this_00);
  vgui::Panel::setParent((Panel *)this_01);
  vgui::Panel::addInputSignal((InputSignal *)this_01);
  vgui::Panel::setPaintBackgroundEnabled(SUB41(this,0));
  return;
}


// vgui::CCheckButton2::~CCheckButton2  @ 000a7460  (line 45)

/* DWARF original prototype: void ~CCheckButton2(CCheckButton2 * this, int __in_chrg) */

void __thiscall vgui::CCheckButton2::~CCheckButton2(CCheckButton2 *this,int __in_chrg)

{
  bool bVar1;
  
  bVar1 = this->m_bOwnImages;
  *(undefined ***)this = &PTR_setPos_000cb0f4;
  (this->super_CDefaultInputSignal).super_InputSignal._vptr_InputSignal =
       (_func_int_varargs **)&PTR_cursorMoved_000cb2fc;
  if (bVar1 != false) {
    operator_delete(this->m_pChecked);
    operator_delete(this->m_pUnchecked);
  }
  this->m_pChecked = (Image *)0x0;
  this->m_pUnchecked = (Image *)0x0;
  this->m_bOwnImages = false;
  SetupControls(this);
  return;
}


// vgui::CCheckButton2::SetImages  @ 000a7560  (line 52)

/* DWARF original prototype: void SetImages(CCheckButton2 * this, char * pChecked, char *
   pUnchecked) */

void __thiscall vgui::CCheckButton2::SetImages(CCheckButton2 *this,char *pChecked,char *pUnchecked)

{
  BitmapTGA *pBVar1;
  
  if (this->m_bOwnImages != false) {
    operator_delete(this->m_pChecked);
    operator_delete(this->m_pUnchecked);
  }
  this->m_pUnchecked = (Image *)0x0;
  this->m_pChecked = (Image *)0x0;
  this->m_bOwnImages = false;
  SetupControls(this);
  pBVar1 = vgui_LoadTGA(pChecked);
  this->m_pChecked = (Image *)pBVar1;
  pBVar1 = vgui_LoadTGA(pUnchecked);
  this->m_bOwnImages = true;
  this->m_pUnchecked = (Image *)pBVar1;
  SetupControls(this);
  return;
}


// vgui::CCheckButton2::SetImages  @ 000a74d0  (line 64)

/* DWARF original prototype: void SetImages(CCheckButton2 * this, Image * pChecked, Image *
   pUnchecked) */

void __thiscall
vgui::CCheckButton2::SetImages(CCheckButton2 *this,Image *pChecked,Image *pUnchecked)

{
  if (this->m_bOwnImages != false) {
    operator_delete(this->m_pChecked);
    operator_delete(this->m_pUnchecked);
  }
  this->m_pChecked = (Image *)0x0;
  this->m_pUnchecked = (Image *)0x0;
  this->m_bOwnImages = false;
  SetupControls(this);
  this->m_pChecked = pChecked;
  this->m_pUnchecked = pUnchecked;
  this->m_bOwnImages = false;
  SetupControls(this);
  return;
}


// vgui::CCheckButton2::DeleteImages  @ 000a7270  (line 76)

/* DWARF original prototype: void DeleteImages(CCheckButton2 * this) */

void __thiscall vgui::CCheckButton2::DeleteImages(CCheckButton2 *this)

{
  if (this->m_bOwnImages != false) {
    operator_delete(this->m_pChecked);
    operator_delete(this->m_pUnchecked);
  }
  this->m_pChecked = (Image *)0x0;
  this->m_pUnchecked = (Image *)0x0;
  this->m_bOwnImages = false;
  SetupControls(this);
  return;
}


// vgui::CCheckButton2::SetCheckboxLeft  @ 000a72d0  (line 92)

/* DWARF original prototype: void SetCheckboxLeft(CCheckButton2 * this, bool bLeftAlign) */

void __thiscall vgui::CCheckButton2::SetCheckboxLeft(CCheckButton2 *this,bool bLeftAlign)

{
  this->m_bCheckboxLeft = bLeftAlign;
  SetupControls(this);
  return;
}


// vgui::CCheckButton2::GetCheckboxLeft  @ 000a6f60  (line 100)

/* DWARF original prototype: bool GetCheckboxLeft(CCheckButton2 * this) */

bool __thiscall vgui::CCheckButton2::GetCheckboxLeft(CCheckButton2 *this)

{
  return this->m_bCheckboxLeft;
}


// vgui::CCheckButton2::SetText  @ 000a72f0  (line 105)

/* DWARF original prototype: void SetText(CCheckButton2 * this, char * pText, ...) */

void __thiscall vgui::CCheckButton2::SetText(CCheckButton2 *this,char *pText,...)

{
  int in_GS_OFFSET;
  undefined1 local_210 [512];
  int local_10;
  
                    /* Unresolved local var: char[512] str@[???]
                       Unresolved local var: va_list marker@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_210,0x200,1,0x200,pText,&stack0x0000000c);
  vgui::Label::setText((char *)&this->m_Label,local_210);
  SetupControls(this);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// vgui::CCheckButton2::SetTextColor  @ 000a70c0  (line 119)

/* DWARF original prototype: void SetTextColor(CCheckButton2 * this, int r, int g, int b, int a) */

void __thiscall vgui::CCheckButton2::SetTextColor(CCheckButton2 *this,int r,int g,int b,int a)

{
  vgui::Label::setFgColor((int)&this->m_Label,r,g,b);
                    /* WARNING: Could not recover jumptable at 0x000a7103. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x30))();
  return;
}


// vgui::CCheckButton2::SetHandler  @ 000a6f70  (line 127)

/* DWARF original prototype: void SetHandler(CCheckButton2 * this, ICheckButton2Handler * pHandler)
    */

void __thiscall vgui::CCheckButton2::SetHandler(CCheckButton2 *this,ICheckButton2Handler *pHandler)

{
  this->m_pHandler = pHandler;
  return;
}


// vgui::CCheckButton2::IsChecked  @ 000a6f80  (line 133)

/* DWARF original prototype: bool IsChecked(CCheckButton2 * this) */

bool __thiscall vgui::CCheckButton2::IsChecked(CCheckButton2 *this)

{
  return this->m_bChecked;
}


// vgui::CCheckButton2::SetChecked  @ 000a7390  (line 138)

/* DWARF original prototype: void SetChecked(CCheckButton2 * this, bool bChecked) */

void __thiscall vgui::CCheckButton2::SetChecked(CCheckButton2 *this,bool bChecked)

{
  this->m_bChecked = bChecked;
  SetupControls(this);
  return;
}


// vgui::CCheckButton2::internalMousePressed  @ 000a73b0  (line 145)

/* DWARF original prototype: void internalMousePressed(CCheckButton2 * this, MouseCode code) */

void __thiscall vgui::CCheckButton2::internalMousePressed(CCheckButton2 *this,MouseCode code)

{
  ICheckButton2Handler *pIVar1;
  
  pIVar1 = this->m_pHandler;
  this->m_bChecked = (bool)(this->m_bChecked ^ 1);
  if (pIVar1 != (ICheckButton2Handler *)0x0) {
    (*(code *)**(undefined4 **)pIVar1)(pIVar1,this);
  }
  SetupControls(this);
  return;
}


// vgui::CCheckButton2::SetupControls  @ 000a7110  (line 156)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SetupControls(CCheckButton2 * this) */

void __thiscall vgui::CCheckButton2::SetupControls(CCheckButton2 *this)

{
  ImagePanel *pIVar1;
  Label *pLVar2;
  bool bVar3;
  bool bVar4;
  Image *pIVar5;
  uint uVar6;
  Image *local_34;
  Label *local_30;
  int local_2c [2];
  int local_24;
  int local_20;
  
                    /* Unresolved local var: Image * pBitmap@[???]
                       Unresolved local var: Panel *[2] controls@[???]
                       Unresolved local var: int[2][2] controlSizes@[???]
                       Unresolved local var: int iLeftControl@[???]
                       Unresolved local var: int iBiggestY@[???] */
  pIVar1 = &this->m_CheckboxPanel;
  pIVar5 = this->m_pUnchecked;
  if (this->m_bChecked != false) {
    pIVar5 = this->m_pChecked;
  }
  pLVar2 = &this->m_Label;
  local_2c[1] = 0;
  local_2c[0] = 0;
  local_34 = (Image *)pIVar1;
  local_30 = pLVar2;
  if (pIVar5 != (Image *)0x0) {
    (**(code **)(*(int *)pIVar5 + 8))(pIVar5,local_2c,local_2c + 1);
  }
  vgui::ImagePanel::setImage((Image *)pIVar1);
  vgui::Panel::setSize((int)pIVar1,local_2c[0]);
  vgui::Panel::getSize((int *)pLVar2,local_2c + 2);
  vgui::Label::setContentAlignment((Alignment)pLVar2);
  bVar3 = this->m_bCheckboxLeft;
  uVar6 = (uint)(bVar3 ^ 1);
  bVar4 = local_2c[1] <= local_24;
  (*(code *)**(undefined4 **)(&local_34)[uVar6])
            ((&local_34)[uVar6],0,(local_2c[(uint)bVar4 * 2 + 1] - local_2c[uVar6 * 2 + 1]) / 2);
  (*(code *)**(undefined4 **)(&local_34)[bVar3])
            ((&local_34)[bVar3],local_2c[uVar6 * 2] + 5,
             (local_2c[(uint)bVar4 * 2 + 1] - local_2c[(uint)bVar3 * 2 + 1]) / 2);
  if (local_20 <= local_2c[1]) {
    local_20 = local_2c[1];
  }
  (**(code **)(*(int *)this + 8))(this,local_24 + local_2c[0] + 5,local_20);
  (**(code **)(*(int *)this + 0x30))(this);
  return;
}


// vgui::CCheckButton2::mousePressed  @ 000a73f0  (line 190)

/* DWARF original prototype: void mousePressed(CCheckButton2 * this, MouseCode code, Panel * panel)
    */

void __thiscall vgui::CCheckButton2::mousePressed(CCheckButton2 *this,MouseCode code,Panel *panel)

{
  ICheckButton2Handler *pIVar1;
  
  if (*(code **)(*(int *)this + 0x1d4) == internalMousePressed) {
    pIVar1 = this->m_pHandler;
    this->m_bChecked = (bool)(this->m_bChecked ^ 1);
    if (pIVar1 != (ICheckButton2Handler *)0x0) {
      (*(code *)**(undefined4 **)pIVar1)(pIVar1,this);
    }
    SetupControls(this);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000a7444. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x1d4))();
  return;
}


