// Ghidra decompilation of functions from game_shared/vgui_listbox.cpp
// 16 functions, ordered by original source line

// vgui::CListBox::CListBox  @ 000a8e20  (line 9)

/* DWARF original prototype: void CListBox(CListBox * this) */

void __thiscall vgui::CListBox::CListBox(CListBox *this)

{
  Panel *this_00;
  ScrollBar2 *this_01;
  Slider2 *this_02;
  
  this_00 = &this->m_ItemsPanel;
  this_01 = &this->m_ScrollBar;
  vgui::Panel::Panel(&this->super_Panel,0,0,0,0);
  *(undefined ***)this = &PTR_setPos_000cb5e0;
  this_02 = &this->m_Slider;
  vgui::Panel::Panel(this_00,0,0,0,0);
  Slider2::Slider2(this_02,0,0,10,0x28,true);
  ScrollBar2::ScrollBar2(this_01,0,0,0,0,true);
  (this->m_Signal).super_IntChangeSignal._vptr_IntChangeSignal =
       (_func_int_varargs **)&PTR_intChanged_000cb5d4;
  (this->m_Signal).m_pListBox = this;
  vgui::Panel::setParent(this_00);
  vgui::Panel::setBgColor((int)this_00,0,0,0);
  Slider2::setRangeWindow(this_02,0x32);
  Slider2::setRangeWindowEnabled(this_02,true);
  vgui::Panel::setParent(&this_01->super_Panel);
  ScrollBar2::addIntChangeSignal(this_01,&(this->m_Signal).super_IntChangeSignal);
  ScrollBar2::setSlider(this_01,this_02);
  ScrollBar2::setButtonPressedScrollValue(this_01,1);
  (this->m_Items).m_pPrev = &this->m_Items;
  (this->m_Items).m_pNext = &this->m_Items;
  this->m_ItemOffset = 0;
  this->m_iScrollMax = -1;
  return;
}


// vgui::CListBox::~CListBox  @ 000a89b0  (line 32)

/* DWARF original prototype: void ~CListBox(CListBox * this, int __in_chrg) */

void __thiscall vgui::CListBox::~CListBox(CListBox *this,int __in_chrg)

{
  LBItem *pLVar1;
  LBItem *pLVar2;
  
                    /* Unresolved local var: LBItem * pNext@[???] */
  this->m_ItemOffset = 0;
                    /* Unresolved local var: LBItem * pItem@[???] */
  pLVar1 = (this->m_Items).m_pNext;
  *(undefined ***)this = &PTR_setPos_000cb5e0;
  while (pLVar1 != &this->m_Items) {
    (**(code **)(*(int *)pLVar1->m_pPanel + 0x40))(pLVar1->m_pPanel,0);
    pLVar2 = pLVar1->m_pNext;
    operator_delete(pLVar1);
    pLVar1 = pLVar2;
  }
  return;
}


// vgui::CListBox::Init  @ 000a8a10  (line 38)

/* DWARF original prototype: void Init(CListBox * this) */

void __thiscall vgui::CListBox::Init(CListBox *this)

{
  LBItem *pLVar1;
  LBItem *pLVar2;
  LBItem *pLVar3;
  
                    /* Unresolved local var: LBItem * pNext@[???] */
  this->m_ItemOffset = 0;
                    /* Unresolved local var: LBItem * pItem@[???] */
  pLVar1 = &this->m_Items;
  pLVar3 = (this->m_Items).m_pNext;
  while (pLVar3 != pLVar1) {
    (**(code **)(*(int *)pLVar3->m_pPanel + 0x40))(pLVar3->m_pPanel,0);
    pLVar2 = pLVar3->m_pNext;
    operator_delete(pLVar3);
    pLVar3 = pLVar2;
  }
  (this->m_Items).m_pNext = pLVar1;
  (this->m_Items).m_pPrev = pLVar1;
  return;
}


// vgui::CListBox::Term  @ 000a8a80  (line 43)

/* DWARF original prototype: void Term(CListBox * this) */

void __thiscall vgui::CListBox::Term(CListBox *this)

{
  LBItem *pLVar1;
  LBItem *pLVar2;
  LBItem *pLVar3;
  
                    /* Unresolved local var: LBItem * pNext@[???] */
  this->m_ItemOffset = 0;
                    /* Unresolved local var: LBItem * pItem@[???] */
  pLVar1 = &this->m_Items;
  pLVar3 = (this->m_Items).m_pNext;
  while (pLVar3 != pLVar1) {
    (**(code **)(*(int *)pLVar3->m_pPanel + 0x40))(pLVar3->m_pPanel,0);
    pLVar2 = pLVar3->m_pNext;
    operator_delete(pLVar3);
    pLVar3 = pLVar2;
  }
  (this->m_Items).m_pNext = pLVar1;
  (this->m_Items).m_pPrev = pLVar1;
  return;
}


// vgui::CListBox::AddItem  @ 000a8fb0  (line 58)

/* DWARF original prototype: void AddItem(CListBox * this, Panel * panel) */

void __thiscall vgui::CListBox::AddItem(CListBox *this,Panel *panel)

{
  LBItem *pLVar1;
  LBItem *pLVar2;
  int iVar3;
  LBItem *pLVar4;
  int max;
  
                    /* Unresolved local var: LBItem * pItem@[???] */
  pLVar4 = operator_new(0xc);
  if (pLVar4 == (LBItem *)0x0) {
    return;
  }
  pLVar4->m_pPanel = panel;
  pLVar1 = &this->m_Items;
  (**(code **)(*(int *)panel + 0x40))(panel,&this->m_ItemsPanel);
  pLVar2 = (this->m_Items).m_pPrev;
  pLVar4->m_pNext = pLVar1;
  pLVar4->m_pPrev = pLVar2;
  pLVar2->m_pNext = pLVar4;
  max = this->m_iScrollMax;
  (this->m_Items).m_pPrev = pLVar4;
  if (max < 0) {
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: LBItem * pItem@[???] */
    pLVar4 = (this->m_Items).m_pNext;
    if (pLVar1 == pLVar4) {
      max = -1;
    }
    else {
      iVar3 = 0;
      do {
        max = iVar3;
        pLVar4 = pLVar4->m_pNext;
        iVar3 = max + 1;
      } while (pLVar1 != pLVar4);
    }
  }
  ScrollBar2::setRange(&this->m_ScrollBar,0,max);
  Slider2::setRangeWindow(&this->m_Slider,0x32);
  Slider2::setRangeWindowEnabled(&this->m_Slider,true);
  InternalLayout(this);
  return;
}


// vgui::CListBox::GetNumItems  @ 000a8af0  (line 79)

/* DWARF original prototype: int GetNumItems(CListBox * this) */

int __thiscall vgui::CListBox::GetNumItems(CListBox *this)

{
  int iVar1;
  LBItem *pLVar2;
  
                    /* Unresolved local var: int count@[???] */
  iVar1 = 0;
                    /* Unresolved local var: LBItem * pItem@[???] */
  pLVar2 = (this->m_Items).m_pNext;
  if (pLVar2 == &this->m_Items) {
    return iVar1;
  }
  do {
    pLVar2 = pLVar2->m_pNext;
    iVar1 = iVar1 + 1;
  } while (pLVar2 != &this->m_Items);
  return iVar1;
}


// vgui::CListBox::GetItemWidth  @ 000a8b20  (line 88)

/* DWARF original prototype: int GetItemWidth(CListBox * this) */

int __thiscall vgui::CListBox::GetItemWidth(CListBox *this)

{
  int local_14 [5];
  
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  vgui::Panel::getSize((int *)&this->m_ItemsPanel,local_14);
  return local_14[0];
}


// vgui::CListBox::GetScrollPos  @ 000a8b50  (line 96)

/* DWARF original prototype: int GetScrollPos(CListBox * this) */

int __thiscall vgui::CListBox::GetScrollPos(CListBox *this)

{
  return this->m_ItemOffset;
}


// vgui::CListBox::SetScrollPos  @ 000a8d40  (line 100)

/* DWARF original prototype: void SetScrollPos(CListBox * this, int pos) */

void __thiscall vgui::CListBox::SetScrollPos(CListBox *this,int pos)

{
  int iVar1;
  int iVar2;
  LBItem *pLVar3;
  
                    /* Unresolved local var: int maxItems@[???] */
  iVar2 = this->m_iScrollMax;
  if (iVar2 < 0) {
    pLVar3 = (this->m_Items).m_pNext;
    if (pLVar3 == &this->m_Items) {
      return;
    }
    iVar1 = 0;
    do {
      iVar2 = iVar1;
      pLVar3 = pLVar3->m_pNext;
      iVar1 = iVar2 + 1;
    } while (pLVar3 != &this->m_Items);
  }
  if (pos < 0) {
    iVar2 = 0;
  }
  else if (pos <= iVar2) {
    iVar2 = pos;
  }
  this->m_ItemOffset = iVar2;
  InternalLayout(this);
  return;
}


// vgui::CListBox::setPos  @ 000a90e0  (line 110)

/* DWARF original prototype: void setPos(CListBox * this, int x, int y) */

void __thiscall vgui::CListBox::setPos(CListBox *this,int x,int y)

{
  vgui::Panel::setPos((int)this,x);
  InternalLayout(this);
  return;
}


// vgui::CListBox::setSize  @ 000a9110  (line 116)

/* DWARF original prototype: void setSize(CListBox * this, int wide, int tall) */

void __thiscall vgui::CListBox::setSize(CListBox *this,int wide,int tall)

{
  vgui::Panel::setSize((int)this,wide);
  InternalLayout(this);
  return;
}


// vgui::CListBox::setPixelScroll  @ 000a9140  (line 122)

/* DWARF original prototype: void setPixelScroll(CListBox * this, int value) */

void __thiscall vgui::CListBox::setPixelScroll(CListBox *this,int value)

{
  int iVar1;
  
  iVar1 = ScrollBar2::getValue(&this->m_ScrollBar);
  this->m_ItemOffset = iVar1;
  InternalLayout(this);
  return;
}


// vgui::CListBox::InternalLayout  @ 000a8b60  (line 128)

/* DWARF original prototype: void InternalLayout(CListBox * this) */

void __thiscall vgui::CListBox::InternalLayout(CListBox *this)

{
  LBItem *pLVar1;
  Panel *pPVar2;
  int iVar3;
  uint uVar4;
  LBItem *pLVar5;
  LBItem *pLVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_48;
  byte local_41;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  int local_2c;
  int local_28;
  undefined1 local_24 [4];
  int local_20 [4];
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: bool bNeedScrollbar@[???]
                       Unresolved local var: int curItem@[???]
                       Unresolved local var: int curY@[???]
                       Unresolved local var: int maxItem@[???] */
  (**(code **)(*(int *)this + 0x14))(this,local_34,local_30,&local_2c,&local_28);
                    /* catch() { ... } // from try @ 000a8c6c with catch @ 000a8ba0 */
  vgui::Panel::setBounds((int)&this->m_ItemsPanel,0,0,local_2c + -0xf);
  iVar10 = 0xf;
  iVar9 = 0;
  iVar11 = local_28;
  vgui::Panel::setBounds((int)&this->m_ScrollBar,local_2c + -0xf,0,0xf);
  local_48 = this->m_iScrollMax;
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: LBItem * pItem@[???] */
  pLVar6 = (this->m_Items).m_pNext;
  pLVar1 = &this->m_Items;
  if (local_48 < 0) {
                    /* try { // try from 000a8d10 to 000b8d14 has its CatchHandler @ 000a8d00 */
    if (pLVar6 == pLVar1) goto LAB_000a8d35;
    pLVar5 = pLVar6;
    iVar7 = 0;
    do {
      local_48 = iVar7;
      pLVar5 = pLVar5->m_pNext;
      iVar7 = local_48 + 1;
    } while (pLVar5 != pLVar1);
  }
  else {
                    /* Unresolved local var: LBItem * pItem@[???] */
    if (pLVar6 == pLVar1) {
LAB_000a8d35:
      uVar4 = 0;
                    /* try { // try from 000a8d38 to 000b8d3c has its CatchHandler @ 000a8d69 */
      goto LAB_000a8cd5;
    }
  }
  iVar8 = 0;
  iVar7 = 0;
  local_41 = 0;
                    /* try { // try from 000a8c2a to 000b8c2e has its CatchHandler @ 000a8ba0 */
  do {
    while( true ) {
      pPVar2 = pLVar6->m_pPanel;
      iVar3 = *(int *)pPVar2;
      if (this->m_ItemOffset <= iVar7) break;
                    /* catch() { ... } // from try @ 000a8d4a with catch @ 000a8d00 */
      (**(code **)(iVar3 + 0x24))(pPVar2,0,iVar9,iVar10,iVar11);
      local_41 = 1;
LAB_000a8c3c:
      pLVar6 = pLVar6->m_pNext;
      iVar7 = iVar7 + 1;
      if (pLVar6 == pLVar1) goto LAB_000a8cd0;
    }
                    /* try { // try from 000a8c5a to 000b8c5e has its CatchHandler @ 000a8ce3 */
    if (local_48 <= iVar7) {
      (**(code **)(iVar3 + 0x24))(pPVar2,0);
      goto LAB_000a8c3c;
    }
                    /* Unresolved local var: int itemWidth@[???]
                       Unresolved local var: int itemHeight@[???] */
                    /* try { // try from 000a8c6c to 000b8cf4 has its CatchHandler @ 000a8ba0 */
    (**(code **)(iVar3 + 0x24))(pPVar2,1);
    (**(code **)(*(int *)pLVar6->m_pPanel + 0xc))(pLVar6->m_pPanel,local_24,local_20);
    iVar9 = iVar8;
    iVar10 = local_2c;
    iVar11 = local_20[0];
    (**(code **)(*(int *)pLVar6->m_pPanel + 0x10))(pLVar6->m_pPanel,0);
    iVar8 = iVar8 + local_20[0];
    if (iVar8 <= local_28) goto LAB_000a8c3c;
    pLVar6 = pLVar6->m_pNext;
    iVar7 = iVar7 + 1;
    local_41 = 1;
  } while (pLVar6 != pLVar1);
LAB_000a8cd0:
  uVar4 = (uint)local_41;
LAB_000a8cd5:
                    /* catch() { ... } // from try @ 000a8c5a with catch @ 000a8ce3 */
  vgui::Panel::setVisible(SUB41(&this->m_ScrollBar,0));
  (**(code **)(*(int *)this + 0x30))(this,uVar4);
  return;
}


// vgui::CListBox::paintBackground  @ 000a89a0  (line 181)

/* DWARF original prototype: void paintBackground(CListBox * this) */

void __thiscall vgui::CListBox::paintBackground(CListBox *this)

{
  return;
}


// vgui::CListBox::SetScrollRange  @ 000a90a0  (line 185)

/* DWARF original prototype: void SetScrollRange(CListBox * this, int maxScroll) */

void __thiscall vgui::CListBox::SetScrollRange(CListBox *this,int maxScroll)

{
  this->m_iScrollMax = maxScroll;
  ScrollBar2::setRange(&this->m_ScrollBar,0,maxScroll);
  InternalLayout(this);
  return;
}


// vgui::CListBox::GetScrollMax  @ 000a8dd0  (line 192)

/* DWARF original prototype: int GetScrollMax(CListBox * this) */

int __thiscall vgui::CListBox::GetScrollMax(CListBox *this)

{
  int iVar1;
  int iVar2;
  LBItem *pLVar3;
  
  if (-1 < this->m_iScrollMax) {
    return this->m_iScrollMax;
  }
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: LBItem * pItem@[???] */
  pLVar3 = (this->m_Items).m_pNext;
  if (&this->m_Items == pLVar3) {
    return -1;
  }
  iVar1 = 0;
  do {
    iVar2 = iVar1;
    pLVar3 = pLVar3->m_pNext;
    iVar1 = iVar2 + 1;
  } while (&this->m_Items != pLVar3);
  return iVar2;
}


