// Ghidra decompilation of functions from game_shared/vgui_slider2.cpp
// 26 functions, ordered by original source line

// anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::cursorMoved  @ 000ab820  (line 29)

/* DWARF original prototype: void cursorMoved(FooDefaultSliderSignal * this, int x, int y, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::cursorMoved
          (FooDefaultSliderSignal *this,int x,int y,Panel *panel)

{
  Slider2 *pSVar1;
  _func_int_varargs *p_Var2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  IntChangeSignal *pIVar7;
  int local_2c;
  int local_28;
  int local_24;
  int local_20 [4];
  
  pSVar1 = this->_slider;
  if (*(code **)(*(int *)pSVar1 + 0x230) != vgui::Slider2::privateCursorMoved) {
    (**(code **)(*(int *)pSVar1 + 0x230))(pSVar1,x,y,panel);
    return;
  }
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  local_2c = x;
  local_28 = y;
  if (pSVar1->_dragging == false) {
    return;
  }
  piVar3 = (int *)(**(code **)(*(int *)pSVar1 + 0x14c))(pSVar1);
  (**(code **)(*piVar3 + 0x34))(piVar3,&local_2c,&local_28);
  (**(code **)(*(int *)pSVar1 + 0x8c))(pSVar1,&local_2c,&local_28);
  (**(code **)(*(int *)pSVar1 + 0xe8))(pSVar1,&local_24,local_20);
  if (pSVar1->_vertical == false) {
    iVar4 = local_2c - pSVar1->_dragStartPos[0];
    iVar6 = pSVar1->_nobDragStartPos[0] + iVar4;
    iVar4 = iVar4 + pSVar1->_nobDragStartPos[1];
    pSVar1->_nobPos[0] = iVar6;
    pSVar1->_nobPos[1] = iVar4;
    iVar5 = iVar4;
    if (iVar4 <= local_24) goto LAB_000ab90a;
  }
  else {
                    /* try { // try from 000ab9da to 000bb9de has its CatchHandler @ 000abdd2 */
    iVar4 = local_28 - pSVar1->_dragStartPos[1];
                    /* try { // try from 000ab9ec to 000bba10 has its CatchHandler @ 000abda6 */
    iVar6 = pSVar1->_nobDragStartPos[0] + iVar4;
    iVar4 = iVar4 + pSVar1->_nobDragStartPos[1];
    pSVar1->_nobPos[0] = iVar6;
    pSVar1->_nobPos[1] = iVar4;
    iVar5 = iVar4;
    local_24 = local_20[0];
    if (iVar4 <= local_20[0]) goto LAB_000ab90a;
  }
  iVar4 = local_24;
  iVar6 = iVar4 - (iVar5 - iVar6);
  pSVar1->_nobPos[0] = iVar6;
  pSVar1->_nobPos[1] = iVar4;
LAB_000ab90a:
  if (iVar6 < 0) {
    pSVar1->_nobPos[1] = iVar4 - iVar6;
    pSVar1->_nobPos[0] = 0;
  }
  (**(code **)(*(int *)pSVar1 + 0x22c))(pSVar1);
  (**(code **)(*(int *)pSVar1 + 0x30))(pSVar1);
  iVar5 = *(int *)pSVar1;
  if (*(code **)(iVar5 + 0x23c) == vgui::Slider2::fireIntChangeSignal) {
    iVar4 = (pSVar1->_intChangeSignalDar)._count;
                    /* Unresolved local var: int i@[???] */
    if (0 < iVar4) {
      iVar6 = 0;
      while( true ) {
        pIVar7 = (IntChangeSignal *)0x0;
        if (iVar6 < iVar4) {
          pIVar7 = (pSVar1->_intChangeSignalDar)._data[iVar6];
        }
        p_Var2 = *pIVar7->_vptr_IntChangeSignal;
        if (*(code **)(iVar5 + 0x200) == vgui::Slider2::getValue) {
          iVar5 = pSVar1->_value;
        }
        else {
          iVar5 = (**(code **)(iVar5 + 0x200))(pSVar1);
        }
        iVar6 = iVar6 + 1;
        (*p_Var2)(pIVar7,iVar5,pSVar1);
        iVar4 = (pSVar1->_intChangeSignalDar)._count;
        if (iVar4 <= iVar6) break;
        iVar5 = *(int *)pSVar1;
      }
    }
  }
  else {
    (**(code **)(iVar5 + 0x23c))(pSVar1);
  }
  return;
}


// anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::mousePressed  @ 000ab700  (line 36)

/* DWARF original prototype: void mousePressed(FooDefaultSliderSignal * this, MouseCode code, Panel
   * panel) */

void __thiscall
anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::mousePressed
          (FooDefaultSliderSignal *this,MouseCode code,Panel *panel)

{
  Slider2 *pSVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  int local_14;
  int local_10;
  
  pSVar1 = this->_slider;
  pcVar2 = *(code **)(*(int *)pSVar1 + 0x234);
  if (pcVar2 != vgui::Slider2::privateMousePressed) {
    (*pcVar2)(pSVar1,code,panel);
    return;
  }
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  piVar3 = (int *)(**(code **)(*(int *)pSVar1 + 0x14c))(pSVar1);
  (**(code **)(*piVar3 + 0x34))(piVar3,&local_14,&local_10);
  (**(code **)(*(int *)pSVar1 + 0x8c))(pSVar1,&local_14,&local_10);
  if (pSVar1->_vertical == false) {
    iVar4 = local_14;
    if (local_14 < pSVar1->_nobPos[0]) {
      return;
    }
  }
  else {
    iVar4 = local_10;
    if (local_10 < pSVar1->_nobPos[0]) {
      return;
    }
  }
  if (iVar4 < pSVar1->_nobPos[1]) {
    pSVar1->_dragging = true;
    piVar3 = (int *)(**(code **)(*(int *)pSVar1 + 0x14c))(pSVar1);
    (**(code **)(*piVar3 + 0x38))(piVar3,pSVar1);
    pSVar1->_nobDragStartPos[0] = pSVar1->_nobPos[0];
    pSVar1->_nobDragStartPos[1] = pSVar1->_nobPos[1];
    pSVar1->_dragStartPos[0] = local_14;
    pSVar1->_dragStartPos[1] = local_10;
  }
  return;
}


// anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::mouseReleased  @ 000ab400  (line 40)

/* DWARF original prototype: void mouseReleased(FooDefaultSliderSignal * this, MouseCode code, Panel
   * panel) */

void __thiscall
anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::mouseReleased
          (FooDefaultSliderSignal *this,MouseCode code,Panel *panel)

{
  Slider2 *pSVar1;
  code *UNRECOVERED_JUMPTABLE;
  int *piVar2;
  
  pSVar1 = this->_slider;
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)pSVar1 + 0x238);
  if (UNRECOVERED_JUMPTABLE == vgui::Slider2::privateMouseReleased) {
    pSVar1->_dragging = false;
    piVar2 = (int *)(**(code **)(*(int *)pSVar1 + 0x14c))(pSVar1);
                    /* WARNING: Could not recover jumptable at 0x000ab454. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar2 + 0x38))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000ab477. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::mouseWheeled  @ 000aa9b0  (line 44)

/* DWARF original prototype: void mouseWheeled(FooDefaultSliderSignal * this, int delta, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::mouseWheeled
          (FooDefaultSliderSignal *this,int delta,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::keyReleased  @ 000aa9c0  (line 47)

/* DWARF original prototype: void keyReleased(FooDefaultSliderSignal * this, KeyCode code, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::keyReleased
          (FooDefaultSliderSignal *this,KeyCode code,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::keyFocusTicked  @ 000aa9d0  (line 48)

/* DWARF original prototype: void keyFocusTicked(FooDefaultSliderSignal * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1dec6c::FooDefaultSliderSignal::keyFocusTicked
          (FooDefaultSliderSignal *this,Panel *panel)

{
  return;
}


// vgui::Slider2::Slider2  @ 000aba20  (line 52)

/* DWARF original prototype: void Slider2(Slider2 * this, int x, int y, int wide, int tall, bool
   vertical) */

void __thiscall vgui::Slider2::Slider2(Slider2 *this,int x,int y,int wide,int tall,bool vertical)

{
  IntChangeSignal **ppIVar1;
  float fVar2;
  float fVar3;
  IntChangeSignal **ppIVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_24;
  int local_20;
  
                    /* try { // try from 000aba34 to 000bba38 has its CatchHandler @ 000abdc6 */
                    /* try { // try from 000aba46 to 000bbc42 has its CatchHandler @ 000abda6 */
  vgui::Panel::Panel(&this->super_Panel,x,y,wide,tall);
  *(undefined ***)this = &PTR_setPos_000cbf28;
  (this->_intChangeSignalDar)._count = 0;
  (this->_intChangeSignalDar)._capacity = 0;
  (this->_intChangeSignalDar)._data = (IntChangeSignal **)0x0;
                    /* Unresolved local var: int newCapacity@[???]
                       Unresolved local var: IntChangeSignal * * newData@[???] */
  ppIVar4 = operator_new__(0x10);
  if (ppIVar4 == (IntChangeSignal **)0x0) {
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
                    /* Unresolved local var: int i@[???] */
  iVar5 = (this->_intChangeSignalDar)._count;
  *ppIVar4 = (IntChangeSignal *)0x0;
  ppIVar4[1] = (IntChangeSignal *)0x0;
  ppIVar4[2] = (IntChangeSignal *)0x0;
  ppIVar4[3] = (IntChangeSignal *)0x0;
  (this->_intChangeSignalDar)._capacity = 4;
  if (0 < iVar5) {
    iVar5 = (this->_intChangeSignalDar)._count;
    iVar7 = 0;
    ppIVar1 = (this->_intChangeSignalDar)._data;
    do {
      ppIVar4[iVar7] = ppIVar1[iVar7];
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar5);
  }
  ppIVar1 = (this->_intChangeSignalDar)._data;
  if (ppIVar1 != (IntChangeSignal **)0x0) {
    operator_delete__(ppIVar1);
  }
  (this->_intChangeSignalDar)._data = ppIVar4;
  this->_vertical = vertical;
  this->_value = 0;
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: float fwide@[???]
                       Unresolved local var: float ftall@[???]
                       Unresolved local var: float frange@[???]
                       Unresolved local var: float fvalue@[???]
                       Unresolved local var: float fper@[???]
                       Unresolved local var: float frangewindow@[???] */
  this->_rangeWindow = 0;
  this->_dragging = false;
  this->_range[0] = 0;
  this->_range[1] = 299;
  this->_rangeWindowEnabled = false;
  this->_buttonOffset = 0;
  vgui::Panel::getPaintSize((int *)this,&local_24);
  fVar2 = (float)(this->_range[1] - this->_range[0]);
  if ((float)this->_rangeWindow < 0.0) {
    fVar3 = fVar2;
    if (this->_rangeWindowEnabled != false) goto LAB_000abc0a;
  }
  else {
    fVar3 = (float)this->_rangeWindow;
    if (this->_rangeWindowEnabled == false) {
      fVar3 = fVar2;
    }
  }
  if (0.0 < fVar3) {
    if (this->_vertical == false) {
      local_20 = local_24;
    }
                    /* Unresolved local var: float fnobsize@[???]
                       Unresolved local var: float freepixels@[???]
                       Unresolved local var: float firstpixel@[???] */
    fVar2 = ((float)local_20 - fVar3) * ((float)(this->_value - this->_range[0]) / fVar2);
    this->_nobPos[0] = (int)fVar2;
    iVar5 = (int)(fVar2 + fVar3);
    this->_nobPos[1] = iVar5;
    if (local_20 < iVar5) {
      this->_nobPos[1] = local_20;
      this->_nobPos[0] = local_20 - (int)fVar3;
    }
  }
LAB_000abc0a:
  vgui::Panel::repaint();
  puVar6 = operator_new(8);
  puVar6[1] = this;
  *puVar6 = &PTR_cursorMoved_000cbef4;
  vgui::Panel::addInputSignal((InputSignal *)this);
  return;
}


// vgui::Slider2::setSize  @ 000abc80  (line 67)

/* DWARF original prototype: void setSize(Slider2 * this, int wide, int tall) */

void __thiscall vgui::Slider2::setSize(Slider2 *this,int wide,int tall)

{
  code *pcVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int local_14;
  int local_10 [3];
  
                    /* try { // try from 000abc84 to 000bbc88 has its CatchHandler @ 000abdc4 */
  vgui::Panel::setSize((int)this,wide);
  pcVar1 = *(code **)(*(int *)this + 0x228);
  if (pcVar1 != recomputeNobPosFromValue) {
                    /* catch() { ... } // from try @ 000abc84 with catch @ 000abdc4 */
    (*pcVar1)(this,wide,tall);
    return;
  }
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: float fwide@[???]
                       Unresolved local var: float ftall@[???]
                       Unresolved local var: float frange@[???]
                       Unresolved local var: float fvalue@[???]
                       Unresolved local var: float fper@[???]
                       Unresolved local var: float frangewindow@[???] */
  (**(code **)(*(int *)this + 0xe8))(this,&local_14,local_10);
                    /* try { // try from 000abccf to 000bbd4f has its CatchHandler @ 000abda6 */
  fVar2 = (float)(this->_range[1] - this->_range[0]);
  if ((float)this->_rangeWindow < 0.0) {
                    /* try { // try from 000abdb3 to 000bbdb7 has its CatchHandler @ 000ab5f0 */
    fVar3 = fVar2;
    if (this->_rangeWindowEnabled != false) goto LAB_000abd8c;
  }
  else {
    fVar3 = (float)this->_rangeWindow;
    if (this->_rangeWindowEnabled == false) {
      fVar3 = fVar2;
    }
  }
  if (0.0 < fVar3) {
    if (this->_vertical == false) {
      local_10[0] = local_14;
    }
                    /* Unresolved local var: float fnobsize@[???]
                       Unresolved local var: float freepixels@[???]
                       Unresolved local var: float firstpixel@[???] */
    fVar2 = ((float)local_10[0] - fVar3) * ((float)(this->_value - this->_range[0]) / fVar2);
    this->_nobPos[0] = (int)fVar2;
    iVar4 = (int)(fVar2 + fVar3);
    this->_nobPos[1] = iVar4;
    if (local_10[0] < iVar4) {
      this->_nobPos[1] = local_10[0];
      this->_nobPos[0] = local_10[0] - (int)fVar3;
                    /* try { // try from 000abd73 to 000bbd77 has its CatchHandler @ 000abdb8 */
    }
  }
LAB_000abd8c:
  (**(code **)(*(int *)this + 0x30))(this);
  return;
}


// vgui::Slider2::isVertical  @ 000aa9e0  (line 74)

/* DWARF original prototype: bool isVertical(Slider2 * this) */

bool __thiscall vgui::Slider2::isVertical(Slider2 *this)

{
  return this->_vertical;
}


// vgui::Slider2::setValue  @ 000ab480  (line 78)

/* DWARF original prototype: void setValue(Slider2 * this, int value) */

void __thiscall vgui::Slider2::setValue(Slider2 *this,int value)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  int iVar3;
  int iVar4;
  IntChangeSignal *pIVar5;
  
                    /* Unresolved local var: int oldValue@[???] */
  iVar3 = this->_value;
  iVar2 = this->_range[0];
  if (this->_range[0] < value) {
    iVar2 = value;
  }
  if (this->_range[1] <= iVar2) {
    iVar2 = this->_range[1];
  }
  this->_value = iVar2;
  (**(code **)(*(int *)this + 0x228))(this);
  if (iVar3 != this->_value) {
                    /* Unresolved local var: int oldValue@[???] */
    iVar3 = *(int *)this;
    if (*(code **)(iVar3 + 0x23c) != fireIntChangeSignal) {
                    /* WARNING: Could not recover jumptable at 0x000ab54b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar3 + 0x23c))();
      return;
    }
    iVar2 = (this->_intChangeSignalDar)._count;
                    /* Unresolved local var: int i@[???] */
    if (0 < iVar2) {
      iVar4 = 0;
      while( true ) {
        pIVar5 = (IntChangeSignal *)0x0;
        if (iVar4 < iVar2) {
          pIVar5 = (this->_intChangeSignalDar)._data[iVar4];
        }
        p_Var1 = *pIVar5->_vptr_IntChangeSignal;
        if (*(code **)(iVar3 + 0x200) == getValue) {
          iVar3 = this->_value;
        }
        else {
          iVar3 = (**(code **)(iVar3 + 0x200))(this);
        }
        iVar4 = iVar4 + 1;
        (*p_Var1)(pIVar5,iVar3,this);
        iVar2 = (this->_intChangeSignalDar)._count;
        if (iVar2 <= iVar4) break;
        iVar3 = *(int *)this;
      }
    }
  }
  return;
}


// vgui::Slider2::getValue  @ 000aa9f0  (line 102)

/* DWARF original prototype: int getValue(Slider2 * this) */

int __thiscall vgui::Slider2::getValue(Slider2 *this)

{
  return this->_value;
}


// vgui::Slider2::recomputeNobPosFromValue  @ 000aaa00  (line 106)

/* DWARF original prototype: void recomputeNobPosFromValue(Slider2 * this) */

void __thiscall vgui::Slider2::recomputeNobPosFromValue(Slider2 *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int local_14;
  int local_10 [3];
  
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: float fwide@[???]
                       Unresolved local var: float ftall@[???]
                       Unresolved local var: float frange@[???]
                       Unresolved local var: float fvalue@[???]
                       Unresolved local var: float fper@[???]
                       Unresolved local var: float frangewindow@[???] */
  (**(code **)(*(int *)this + 0xe8))(this,&local_14,local_10);
  fVar1 = (float)(this->_range[1] - this->_range[0]);
  if ((float)this->_rangeWindow < 0.0) {
    fVar2 = fVar1;
    if (this->_rangeWindowEnabled != false) {
      (**(code **)(*(int *)this + 0x30))(this);
      return;
    }
  }
  else {
    fVar2 = (float)this->_rangeWindow;
    if (this->_rangeWindowEnabled == false) {
      fVar2 = fVar1;
    }
  }
  if (0.0 < fVar2) {
    if (this->_vertical == false) {
      local_10[0] = local_14;
    }
                    /* Unresolved local var: float fnobsize@[???]
                       Unresolved local var: float freepixels@[???]
                       Unresolved local var: float firstpixel@[???] */
    fVar1 = ((float)local_10[0] - fVar2) * ((float)(this->_value - this->_range[0]) / fVar1);
    this->_nobPos[0] = (int)fVar1;
    iVar3 = (int)(fVar1 + fVar2);
    this->_nobPos[1] = iVar3;
    if (local_10[0] < iVar3) {
      this->_nobPos[1] = local_10[0];
      this->_nobPos[0] = local_10[0] - (int)fVar2;
    }
  }
  (**(code **)(*(int *)this + 0x30))(this);
  return;
}


// vgui::Slider2::recomputeValueFromNobPos  @ 000aab20  (line 168)

/* DWARF original prototype: void recomputeValueFromNobPos(Slider2 * this) */

void __thiscall vgui::Slider2::recomputeValueFromNobPos(Slider2 *this)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int local_14;
  int local_10 [2];
  
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: float fwide@[???]
                       Unresolved local var: float ftall@[???]
                       Unresolved local var: float frange@[???]
                       Unresolved local var: float fvalue@[???]
                       Unresolved local var: float fnob@[???]
                       Unresolved local var: float frangewindow@[???] */
  (**(code **)(*(int *)this + 0xe8))(this,&local_14,local_10);
  iVar1 = this->_range[1];
  iVar5 = this->_range[0];
  fVar4 = (float)(iVar1 - iVar5);
  fVar2 = (float)(this->_value - iVar5);
  if ((float)this->_rangeWindow < 0.0) {
    fVar3 = fVar4;
    if (this->_rangeWindowEnabled != false) goto LAB_000aabd2;
  }
  else {
    fVar3 = (float)this->_rangeWindow;
    if (this->_rangeWindowEnabled == false) {
      fVar3 = fVar4;
    }
  }
  if (0.0 < fVar3) {
    if (this->_vertical == false) {
                    /* Unresolved local var: float fnobsize@[???] */
      fVar2 = ((float)this->_nobPos[0] / ((float)local_14 - fVar3)) * fVar4;
    }
    else {
                    /* Unresolved local var: float fnobsize@[???] */
      fVar2 = ((float)this->_nobPos[0] / ((float)local_10[0] - fVar3)) * fVar4;
    }
  }
LAB_000aabd2:
  iVar5 = (int)((float)iVar5 + fVar2 + 0.5);
  if (iVar1 < iVar5) {
    iVar5 = iVar1;
  }
  this->_value = iVar5;
  return;
}


// vgui::Slider2::hasFullRange  @ 000aac30  (line 210)

/* DWARF original prototype: bool hasFullRange(Slider2 * this) */

bool __thiscall vgui::Slider2::hasFullRange(Slider2 *this)

{
  longdouble lVar1;
  int local_14;
  int local_10 [3];
  
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: float fwide@[???]
                       Unresolved local var: float ftall@[???]
                       Unresolved local var: float frange@[???]
                       Unresolved local var: float frangewindow@[???] */
  (**(code **)(*(int *)this + 0xe8))(this,&local_14,local_10);
  lVar1 = (longdouble)this->_rangeWindow;
  if (lVar1 < (longdouble)0) {
    if (this->_rangeWindowEnabled != false) {
      return false;
    }
  }
  else if (this->_rangeWindowEnabled != false) {
    if (lVar1 <= (longdouble)0) {
      return false;
    }
    goto LAB_000aac7e;
  }
  lVar1 = (longdouble)(this->_range[1] - this->_range[0]);
  if (lVar1 <= (longdouble)0) {
    return false;
  }
LAB_000aac7e:
  if (this->_vertical == false) {
    return lVar1 <= (longdouble)this->_buttonOffset + (longdouble)local_14;
  }
  return lVar1 <= (longdouble)this->_buttonOffset + (longdouble)local_10[0];
}


// vgui::Slider2::addIntChangeSignal  @ 000ab170  (line 251)

/* DWARF original prototype: void addIntChangeSignal(Slider2 * this, IntChangeSignal * s) */

void __thiscall vgui::Slider2::addIntChangeSignal(Slider2 *this,IntChangeSignal *s)

{
  code *pcVar1;
  int iVar2;
  IntChangeSignal **ppIVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  IntChangeSignal **ppIVar7;
  undefined4 *puVar8;
  byte bVar9;
  int *piStack_38;
  uint local_20;
  
  bVar9 = 0;
  iVar6 = (this->_intChangeSignalDar)._count;
                    /* Unresolved local var: int i@[???] */
  if (0 < iVar6) {
    ppIVar3 = (this->_intChangeSignalDar)._data;
    if (s == *ppIVar3) {
      return;
    }
    iVar2 = 0;
    while (iVar2 = iVar2 + 1, iVar6 != iVar2) {
      if (s == ppIVar3[iVar2]) {
        return;
      }
    }
  }
                    /* Unresolved local var: int newCapacity@[???]
                       Unresolved local var: IntChangeSignal * * newData@[???] */
  uVar5 = (this->_intChangeSignalDar)._capacity;
  iVar2 = iVar6 + 1;
  if (iVar2 <= (int)uVar5) {
    (this->_intChangeSignalDar)._data[iVar6] = s;
    (this->_intChangeSignalDar)._count = (this->_intChangeSignalDar)._count + 1;
    return;
  }
  if (uVar5 == 0) {
    if (iVar2 < 2) {
      local_20 = 4;
      uVar5 = 1;
      goto LAB_000ab1f9;
    }
    uVar5 = 1;
  }
  do {
    local_20 = uVar5;
    uVar5 = local_20 * 2;
  } while ((int)uVar5 < iVar2);
  if (0x1fc00000 < uVar5) {
    __cxa_throw_bad_array_new_length();
    if (0 < piStack_38[0x36]) {
      iVar6 = 0;
      do {
        if (iVar6 < 0) {
          puVar8 = (undefined4 *)0x0;
        }
        else {
          puVar8 = *(undefined4 **)(piStack_38[0x38] + iVar6 * 4);
        }
        pcVar1 = *(code **)*puVar8;
        if (*(code **)(*piStack_38 + 0x200) == getValue) {
          iVar2 = piStack_38[0x3b];
        }
        else {
          iVar2 = (**(code **)(*piStack_38 + 0x200))(piStack_38);
        }
        iVar6 = iVar6 + 1;
        (*pcVar1)(puVar8,iVar2,piStack_38);
      } while (iVar6 < piStack_38[0x36]);
    }
    return;
  }
  local_20 = local_20 * 8;
LAB_000ab1f9:
  ppIVar3 = operator_new__(local_20);
  if (ppIVar3 != (IntChangeSignal **)0x0) {
    ppIVar7 = ppIVar3;
    if (7 < local_20) {
      if (((uint)ppIVar3 & 1) != 0) {
        *(undefined1 *)ppIVar3 = 0;
        ppIVar7 = (IntChangeSignal **)((int)ppIVar3 + 1);
        local_20 = local_20 - 1;
      }
      if (((uint)ppIVar7 & 2) != 0) {
        *(undefined2 *)ppIVar7 = 0;
        ppIVar7 = (IntChangeSignal **)((int)ppIVar7 + 2);
        local_20 = local_20 - 2;
      }
      if (((uint)ppIVar7 & 4) != 0) {
        *ppIVar7 = (IntChangeSignal *)0x0;
        ppIVar7 = ppIVar7 + 1;
        local_20 = local_20 - 4;
      }
      for (uVar4 = local_20 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *ppIVar7 = (IntChangeSignal *)0x0;
        ppIVar7 = ppIVar7 + (uint)bVar9 * -2 + 1;
      }
      local_20 = local_20 & 3;
    }
    if ((local_20 & 4) != 0) {
      *ppIVar7 = (IntChangeSignal *)0x0;
      ppIVar7 = ppIVar7 + 1;
    }
    if ((local_20 & 2) != 0) {
      *(undefined2 *)ppIVar7 = 0;
      ppIVar7 = (IntChangeSignal **)((int)ppIVar7 + 2);
    }
    if ((local_20 & 1) != 0) {
      *(undefined1 *)ppIVar7 = 0;
    }
                    /* Unresolved local var: int i@[???] */
    iVar6 = (this->_intChangeSignalDar)._count;
    (this->_intChangeSignalDar)._capacity = uVar5;
    if (0 < iVar6) {
      ppIVar7 = (this->_intChangeSignalDar)._data;
      iVar2 = 0;
      do {
        ppIVar3[iVar2] = ppIVar7[iVar2];
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar6);
    }
    ppIVar7 = (this->_intChangeSignalDar)._data;
    if (ppIVar7 != (IntChangeSignal **)0x0) {
      operator_delete__(ppIVar7);
      iVar6 = (this->_intChangeSignalDar)._count;
    }
    (this->_intChangeSignalDar)._data = ppIVar3;
    ppIVar3[iVar6] = s;
    (this->_intChangeSignalDar)._count = (this->_intChangeSignalDar)._count + 1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  exit(0);
}


// vgui::Slider2::fireIntChangeSignal  @ 000ab380  (line 256)

/* DWARF original prototype: void fireIntChangeSignal(Slider2 * this) */

void __thiscall vgui::Slider2::fireIntChangeSignal(Slider2 *this)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  int iVar3;
  IntChangeSignal *pIVar4;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < (this->_intChangeSignalDar)._count) {
    iVar3 = 0;
    do {
      if (iVar3 < 0) {
        pIVar4 = (IntChangeSignal *)0x0;
      }
      else {
        pIVar4 = (this->_intChangeSignalDar)._data[iVar3];
      }
      p_Var1 = *pIVar4->_vptr_IntChangeSignal;
      if (*(code **)(*(int *)this + 0x200) == getValue) {
        iVar2 = this->_value;
      }
      else {
        iVar2 = (**(code **)(*(int *)this + 0x200))(this);
      }
      iVar3 = iVar3 + 1;
      (*p_Var1)(pIVar4,iVar2,this);
    } while (iVar3 < (this->_intChangeSignalDar)._count);
  }
  return;
}


// vgui::Slider2::paintBackground  @ 000aad00  (line 264)

/* DWARF original prototype: void paintBackground(Slider2 * this) */

void __thiscall vgui::Slider2::paintBackground(Slider2 *this)

{
  int local_14;
  undefined4 local_10 [3];
  
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  (**(code **)(*(int *)this + 0xe8))(this,&local_14,local_10);
  if (this->_vertical == false) {
    (**(code **)(*(int *)this + 0x174))(this,8);
    (**(code **)(*(int *)this + 0x17c))(this,0,0,local_14,local_10[0]);
    (**(code **)(*(int *)this + 0x174))(this,1);
    (**(code **)(*(int *)this + 0x180))(this,0,0,local_14,local_10[0]);
    (**(code **)(*(int *)this + 0x174))(this,4);
    (**(code **)(*(int *)this + 0x17c))(this,this->_nobPos[0],0,this->_nobPos[1],local_10[0]);
    (**(code **)(*(int *)this + 0x174))(this,1);
    (**(code **)(*(int *)this + 0x180))(this,this->_nobPos[0],0,this->_nobPos[1],local_10[0]);
    return;
  }
  (**(code **)(*(int *)this + 0x178))(this,0x28,0x28,0x28,0);
  (**(code **)(*(int *)this + 0x17c))(this,0,0,local_14,local_10[0]);
  (**(code **)(*(int *)this + 0x178))(this,0,0,0,0);
  (**(code **)(*(int *)this + 0x17c))(this,0,this->_nobPos[0],local_14,this->_nobPos[1]);
  (**(code **)(*(int *)this + 0x178))(this,0x3c,0x3c,0x3c,0);
  (**(code **)(*(int *)this + 0x17c))(this,0,this->_nobPos[0],local_14,this->_nobPos[0] + 1);
  (**(code **)(*(int *)this + 0x17c))(this,0,this->_nobPos[1],local_14,this->_nobPos[1] + 1);
  (**(code **)(*(int *)this + 0x17c))(this,0,this->_nobPos[0] + 1,1,this->_nobPos[1]);
  (**(code **)(*(int *)this + 0x17c))
            (this,local_14 + -1,this->_nobPos[0] + 1,local_14,this->_nobPos[1]);
  return;
}


// vgui::Slider2::setRange  @ 000aafc0  (line 304)

/* DWARF original prototype: void setRange(Slider2 * this, int min, int max) */

void __thiscall vgui::Slider2::setRange(Slider2 *this,int min,int max)

{
  if (max < min) {
    max = min;
  }
  this->_range[0] = min;
  this->_range[1] = max;
  return;
}


// vgui::Slider2::getRange  @ 000aafe0  (line 320)

/* DWARF original prototype: void getRange(Slider2 * this, int * min, int * max) */

void __thiscall vgui::Slider2::getRange(Slider2 *this,int *min,int *max)

{
  *min = this->_range[0];
  *max = this->_range[1];
  return;
}


// vgui::Slider2::privateCursorMoved  @ 000ab550  (line 326)

/* DWARF original prototype: void privateCursorMoved(Slider2 * this, int x, int y, Panel * panel) */

void __thiscall vgui::Slider2::privateCursorMoved(Slider2 *this,int x,int y,Panel *panel)

{
  _func_int_varargs *p_Var1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  IntChangeSignal *pIVar6;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  if (this->_dragging == false) {
    return;
  }
  piVar2 = (int *)(**(code **)(*(int *)this + 0x14c))(this);
  (**(code **)(*piVar2 + 0x34))(piVar2,&x,&y);
  (**(code **)(*(int *)this + 0x8c))(this,&x,&y);
  (**(code **)(*(int *)this + 0xe8))(this,&local_24,local_20);
  if (this->_vertical == false) {
    iVar3 = x - this->_dragStartPos[0];
    iVar5 = this->_nobDragStartPos[0] + iVar3;
    iVar3 = iVar3 + this->_nobDragStartPos[1];
    this->_nobPos[0] = iVar5;
    this->_nobPos[1] = iVar3;
    iVar4 = iVar3;
    if (iVar3 <= local_24) goto LAB_000ab611_1;
  }
  else {
    iVar3 = y - this->_dragStartPos[1];
    iVar5 = this->_nobDragStartPos[0] + iVar3;
    iVar3 = iVar3 + this->_nobDragStartPos[1];
    this->_nobPos[0] = iVar5;
    this->_nobPos[1] = iVar3;
    iVar4 = iVar3;
    local_24 = local_20[0];
    if (iVar3 <= local_20[0]) goto LAB_000ab611_1;
  }
  iVar3 = local_24;
  iVar5 = iVar3 - (iVar4 - iVar5);
  this->_nobPos[0] = iVar5;
  this->_nobPos[1] = iVar3;
LAB_000ab611_1:
  if (iVar5 < 0) {
    this->_nobPos[1] = iVar3 - iVar5;
    this->_nobPos[0] = 0;
  }
  (**(code **)(*(int *)this + 0x22c))(this);
  (**(code **)(*(int *)this + 0x30))(this);
  iVar4 = *(int *)this;
  if (*(code **)(iVar4 + 0x23c) == fireIntChangeSignal) {
    iVar3 = (this->_intChangeSignalDar)._count;
    if (0 < iVar3) {
      iVar5 = 0;
      while( true ) {
        pIVar6 = (IntChangeSignal *)0x0;
        if (iVar5 < iVar3) {
          pIVar6 = (this->_intChangeSignalDar)._data[iVar5];
        }
        p_Var1 = *pIVar6->_vptr_IntChangeSignal;
        if (*(code **)(iVar4 + 0x200) == getValue) {
          iVar4 = this->_value;
        }
        else {
          iVar4 = (**(code **)(iVar4 + 0x200))(this);
        }
        iVar5 = iVar5 + 1;
        (*p_Var1)(pIVar6,iVar4,this);
        iVar3 = (this->_intChangeSignalDar)._count;
        if (iVar3 <= iVar5) break;
        iVar4 = *(int *)this;
      }
    }
  }
  else {
    (**(code **)(iVar4 + 0x23c))(this);
  }
  return;
}


// vgui::Slider2::privateMousePressed  @ 000ab000  (line 379)

/* DWARF original prototype: void privateMousePressed(Slider2 * this, MouseCode code, Panel * panel)
    */

void __thiscall vgui::Slider2::privateMousePressed(Slider2 *this,MouseCode code,Panel *panel)

{
  int *piVar1;
  int local_14;
  int local_10;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  piVar1 = (int *)(**(code **)(*(int *)this + 0x14c))(this);
  (**(code **)(*piVar1 + 0x34))(piVar1,&local_14,&local_10);
  (**(code **)(*(int *)this + 0x8c))(this,&local_14,&local_10);
  if (this->_vertical == false) {
    if ((this->_nobPos[0] <= local_14) && (local_14 < this->_nobPos[1])) goto LAB_000ab094;
  }
  else if ((this->_nobPos[0] <= local_10) && (local_10 < this->_nobPos[1])) {
LAB_000ab094:
    this->_dragging = true;
    piVar1 = (int *)(**(code **)(*(int *)this + 0x14c))(this);
    (**(code **)(*piVar1 + 0x38))(piVar1,this);
    this->_nobDragStartPos[0] = this->_nobPos[0];
    this->_nobDragStartPos[1] = this->_nobPos[1];
    this->_dragStartPos[0] = local_14;
    this->_dragStartPos[1] = local_10;
    return;
  }
  return;
}


// vgui::Slider2::privateMouseReleased  @ 000ab0f0  (line 412)

/* DWARF original prototype: void privateMouseReleased(Slider2 * this, MouseCode code, Panel *
   panel) */

void __thiscall vgui::Slider2::privateMouseReleased(Slider2 *this,MouseCode code,Panel *panel)

{
  int *piVar1;
  
  this->_dragging = false;
  piVar1 = (int *)(**(code **)(*(int *)this + 0x14c))(this);
                    /* WARNING: Could not recover jumptable at 0x000ab11b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x38))();
  return;
}


// vgui::Slider2::getNobPos  @ 000ab120  (line 418)

/* DWARF original prototype: void getNobPos(Slider2 * this, int * min, int * max) */

void __thiscall vgui::Slider2::getNobPos(Slider2 *this,int *min,int *max)

{
  *min = this->_nobPos[0];
  *max = this->_nobPos[1];
  return;
}


// vgui::Slider2::setRangeWindow  @ 000ab140  (line 425)

/* DWARF original prototype: void setRangeWindow(Slider2 * this, int rangeWindow) */

void __thiscall vgui::Slider2::setRangeWindow(Slider2 *this,int rangeWindow)

{
  this->_rangeWindow = rangeWindow;
  return;
}


// vgui::Slider2::setRangeWindowEnabled  @ 000ab150  (line 430)

/* DWARF original prototype: void setRangeWindowEnabled(Slider2 * this, bool state) */

void __thiscall vgui::Slider2::setRangeWindowEnabled(Slider2 *this,bool state)

{
  this->_rangeWindowEnabled = state;
  return;
}


// vgui::Slider2::setButtonOffset  @ 000ab160  (line 435)

/* DWARF original prototype: void setButtonOffset(Slider2 * this, int buttonOffset) */

void __thiscall vgui::Slider2::setButtonOffset(Slider2 *this,int buttonOffset)

{
  this->_buttonOffset = buttonOffset;
  return;
}


