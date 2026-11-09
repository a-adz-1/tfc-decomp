// Ghidra decompilation of functions from game_shared/vgui_scrollbar2.cpp
// 22 functions, ordered by original source line

// anon_unknown.dwarf_1dbf7a::FooDefaultScrollBarIntChangeSignal::intChanged  @ 000a9c50  (line 30)

/* DWARF original prototype: void intChanged(FooDefaultScrollBarIntChangeSignal * this, int value,
   Panel * panel) */

void __thiscall
anon_unknown.dwarf_1dbf7a::FooDefaultScrollBarIntChangeSignal::intChanged
          (FooDefaultScrollBarIntChangeSignal *this,int value,Panel *panel)

{
  ScrollBar2 *pSVar1;
  _func_int_varargs *p_Var2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  IntChangeSignal *pIVar6;
  
  pSVar1 = this->_scrollBar;
  if (*(code **)(*(int *)pSVar1 + 0x238) != vgui::ScrollBar2::fireIntChangeSignal) {
                    /* WARNING: Could not recover jumptable at 0x000a9cf3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pSVar1 + 0x238))();
    return;
  }
  iVar3 = (pSVar1->_intChangeSignalDar)._count;
                    /* Unresolved local var: int i@[???] */
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      while( true ) {
        pIVar6 = (IntChangeSignal *)0x0;
        if (iVar5 < iVar3) {
          pIVar6 = (pSVar1->_intChangeSignalDar)._data[iVar5];
        }
        p_Var2 = *pIVar6->_vptr_IntChangeSignal;
        uVar4 = (**(code **)(*(int *)pSVar1->_slider + 0x200))(pSVar1->_slider);
        if (p_Var2 == intChanged) break;
        iVar5 = iVar5 + 1;
        (*p_Var2)(pIVar6,uVar4,pSVar1);
        iVar3 = (pSVar1->_intChangeSignalDar)._count;
        if (iVar3 <= iVar5) {
          return;
        }
      }
      iVar5 = iVar5 + 1;
      (**(code **)(*pIVar6[1]._vptr_IntChangeSignal + 0x238))(pIVar6[1]._vptr_IntChangeSignal);
      iVar3 = (pSVar1->_intChangeSignalDar)._count;
    } while (iVar5 < iVar3);
  }
  return;
}


// anon_unknown.dwarf_1dbf7a::FooDefaultButtonSignal::actionPerformed  @ 000a9970  (line 50)

/* DWARF original prototype: void actionPerformed(FooDefaultButtonSignal * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1dbf7a::FooDefaultButtonSignal::actionPerformed
          (FooDefaultButtonSignal *this,Panel *panel)

{
  code *UNRECOVERED_JUMPTABLE_00;
  Slider2 *pSVar1;
  int iVar2;
  
  UNRECOVERED_JUMPTABLE_00 = *(code **)(*(int *)this->_scrollBar + 0x22c);
  if (UNRECOVERED_JUMPTABLE_00 == vgui::ScrollBar2::doButtonPressed) {
    pSVar1 = this->_scrollBar->_slider;
    iVar2 = *(int *)pSVar1;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(iVar2 + 0x1fc);
    if (this->_buttonIndex == 0) {
      (**(code **)(iVar2 + 0x200))(pSVar1);
    }
    else {
      (**(code **)(iVar2 + 0x200))();
    }
                    /* WARNING: Could not recover jumptable at 0x000a99d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000a9a03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)();
  return;
}


// ScrollBarButton::paintBackground  @ 000aa930  (line 80)

/* DWARF original prototype: void paintBackground(ScrollBarButton * this) */

void __thiscall ScrollBarButton::paintBackground(ScrollBarButton *this)

{
  undefined4 local_14;
  undefined4 local_10 [3];
  
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  (**(code **)(*(int *)this + 0xe8))(this,&local_14,local_10);
  (**(code **)(*(int *)this + 0x178))(this,0,0,0,0);
  (**(code **)(*(int *)this + 0x17c))(this,0,0,local_14,local_10[0]);
  return;
}


// vgui::ScrollBar2::ScrollBar2  @ 000aa040  (line 102)

/* DWARF original prototype: void ScrollBar2(ScrollBar2 * this, int x, int y, int wide, int tall,
   bool vertical) */

void __thiscall
vgui::ScrollBar2::ScrollBar2(ScrollBar2 *this,int x,int y,int wide,int tall,bool vertical)

{
  IntChangeSignal **ppIVar1;
  code *pcVar2;
  char cVar3;
  IntChangeSignal **ppIVar4;
  Slider2 *pSVar5;
  undefined4 *puVar6;
  Button *pBVar7;
  BitmapTGA *pBVar8;
  int iVar9;
  int iVar10;
  Button **ppBVar11;
  int in_GS_OFFSET;
  bool bVar12;
  undefined4 uVar13;
  int local_40;
  int local_3c;
  Color local_38 [12];
  Color local_2c [12];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Panel::Panel(&this->super_Panel,x,y,wide,tall);
  *(undefined ***)this = &PTR_setPos_000cbc34;
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
  iVar9 = (this->_intChangeSignalDar)._count;
  *ppIVar4 = (IntChangeSignal *)0x0;
  ppIVar4[1] = (IntChangeSignal *)0x0;
  ppIVar4[2] = (IntChangeSignal *)0x0;
  ppIVar4[3] = (IntChangeSignal *)0x0;
  (this->_intChangeSignalDar)._capacity = 4;
  if (0 < iVar9) {
    iVar9 = (this->_intChangeSignalDar)._count;
    iVar10 = 0;
    ppIVar1 = (this->_intChangeSignalDar)._data;
    do {
      ppIVar4[iVar10] = ppIVar1[iVar10];
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar9);
  }
  ppIVar1 = (this->_intChangeSignalDar)._data;
  if (ppIVar1 != (IntChangeSignal **)0x0) {
    operator_delete__(ppIVar1);
  }
  (this->_intChangeSignalDar)._data = ppIVar4;
  this->_slider = (Slider2 *)0x0;
  this->_button[0] = (Button *)0x0;
  this->_button[1] = (Button *)0x0;
  if (vertical) {
    pSVar5 = operator_new(0xfc);
    iVar9 = tall + wide * -2;
    Slider2::Slider2(pSVar5,0,wide + -1,wide,iVar9 + 2,true);
    if (this->_slider != (Slider2 *)0x0) {
      vgui::Panel::removeChild(&this->super_Panel);
    }
    this->_slider = pSVar5;
    vgui::Panel::addChild(&this->super_Panel);
    pcVar2 = *(code **)(*(int *)this->_slider + 0x208);
    puVar6 = operator_new(8);
    pSVar5 = this->_slider;
    *puVar6 = &PTR_intChanged_000cb994;
    puVar6[1] = this;
    (*pcVar2)(pSVar5,puVar6);
    validate(this);
    pBVar7 = operator_new(0x134);
    vgui::Button::Button(pBVar7,"",0,0,wide,wide);
    *(undefined ***)pBVar7 = &PTR_setPos_000cb9cc;
    vgui::Color::Color(local_2c,0x3c,0x3c,0x3c,0);
    vgui::LineBorder::LineBorder((LineBorder *)(pBVar7 + 0xf0),local_2c);
                    /* Unresolved local var: Image * image@[???] */
    pBVar8 = vgui_LoadTGA("gfx/vgui/arrowup.tga");
    if (pBVar8 != (BitmapTGA *)0x0) {
      pcVar2 = *(code **)(*(int *)pBVar8 + 0xc);
      vgui::Color::Color(local_38,0x8c,0x8c,0x8c,0);
      (*pcVar2)(pBVar8,local_38);
      vgui::Label::setImage((Image *)pBVar7);
    }
    vgui::Panel::setBorder((Border *)pBVar7);
    if (this->_button[0] != (Button *)0x0) {
      vgui::Panel::removeChild(&this->super_Panel);
    }
    this->_button[0] = pBVar7;
    vgui::Panel::addChild(&this->super_Panel);
    pcVar2 = *(code **)(*(int *)this->_button[0] + 0x240);
    puVar6 = operator_new(0xc);
    pBVar7 = this->_button[0];
    *puVar6 = &PTR_actionPerformed_000cb9a0;
    puVar6[1] = this;
    puVar6[2] = 0;
    (*pcVar2)(pBVar7,puVar6);
    validate(this);
    pBVar7 = operator_new(0x134);
    vgui::Button::Button(pBVar7,"",0,wide + iVar9,wide,wide);
    *(undefined ***)pBVar7 = &PTR_setPos_000cb9cc;
    vgui::Color::Color(local_2c,0x3c,0x3c,0x3c,0);
    vgui::LineBorder::LineBorder((LineBorder *)(pBVar7 + 0xf0),local_2c);
                    /* Unresolved local var: Image * image@[???] */
    pBVar8 = vgui_LoadTGA("gfx/vgui/arrowdown.tga");
    if (pBVar8 != (BitmapTGA *)0x0) {
      pcVar2 = *(code **)(*(int *)pBVar8 + 0xc);
      vgui::Color::Color(local_38,0x8c,0x8c,0x8c,0);
      (*pcVar2)(pBVar8,local_38);
      vgui::Label::setImage((Image *)pBVar7);
    }
    vgui::Panel::setBorder((Border *)pBVar7);
  }
  else {
    pSVar5 = operator_new(0xfc);
    iVar9 = wide + tall * -2;
    Slider2::Slider2(pSVar5,tall,0,iVar9,tall,false);
    if (this->_slider != (Slider2 *)0x0) {
      vgui::Panel::removeChild(&this->super_Panel);
    }
    this->_slider = pSVar5;
    vgui::Panel::addChild(&this->super_Panel);
    pcVar2 = *(code **)(*(int *)this->_slider + 0x208);
    puVar6 = operator_new(8);
    pSVar5 = this->_slider;
    *puVar6 = &PTR_intChanged_000cb994;
    puVar6[1] = this;
    (*pcVar2)(pSVar5,puVar6);
    validate(this);
    pBVar7 = operator_new(0x134);
    iVar10 = tall + 1;
    vgui::Button::Button(pBVar7,"",0,0,iVar10,iVar10);
    *(undefined ***)pBVar7 = &PTR_setPos_000cb9cc;
    vgui::Color::Color(local_2c,0x3c,0x3c,0x3c,0);
    vgui::LineBorder::LineBorder((LineBorder *)(pBVar7 + 0xf0),local_2c);
                    /* Unresolved local var: Image * image@[???] */
    pBVar8 = vgui_LoadTGA("gfx/vgui/320_arrowlt.tga");
    if (pBVar8 != (BitmapTGA *)0x0) {
      pcVar2 = *(code **)(*(int *)pBVar8 + 0xc);
      vgui::Color::Color(local_38,0x8c,0x8c,0x8c,0);
      (*pcVar2)(pBVar8,local_38);
      vgui::Label::setImage((Image *)pBVar7);
    }
    vgui::Panel::setBorder((Border *)pBVar7);
    if (this->_button[0] != (Button *)0x0) {
      vgui::Panel::removeChild(&this->super_Panel);
    }
    this->_button[0] = pBVar7;
    vgui::Panel::addChild(&this->super_Panel);
    pcVar2 = *(code **)(*(int *)this->_button[0] + 0x240);
    puVar6 = operator_new(0xc);
    pBVar7 = this->_button[0];
    *puVar6 = &PTR_actionPerformed_000cb9a0;
    puVar6[1] = this;
    puVar6[2] = 0;
    (*pcVar2)(pBVar7,puVar6);
    validate(this);
    pBVar7 = operator_new(0x134);
    vgui::Button::Button(pBVar7,"",iVar9 + tall,0,iVar10,iVar10);
    *(undefined ***)pBVar7 = &PTR_setPos_000cb9cc;
    vgui::Color::Color(local_2c,0x3c,0x3c,0x3c,0);
    vgui::LineBorder::LineBorder((LineBorder *)(pBVar7 + 0xf0),local_2c);
                    /* Unresolved local var: Image * image@[???] */
    pBVar8 = vgui_LoadTGA("gfx/vgui/320_arrowrt.tga");
    if (pBVar8 != (BitmapTGA *)0x0) {
      pcVar2 = *(code **)(*(int *)pBVar8 + 0xc);
      vgui::Color::Color(local_38,0x8c,0x8c,0x8c,0);
      (*pcVar2)(pBVar8,local_38);
      vgui::Label::setImage((Image *)pBVar7);
    }
    vgui::Panel::setBorder((Border *)pBVar7);
  }
  if (this->_button[1] != (Button *)0x0) {
    vgui::Panel::removeChild(&this->super_Panel);
  }
  this->_button[1] = pBVar7;
  vgui::Panel::addChild(&this->super_Panel);
  pcVar2 = *(code **)(*(int *)this->_button[1] + 0x240);
  puVar6 = operator_new(0xc);
  *puVar6 = &PTR_actionPerformed_000cb9a0;
  puVar6[1] = this;
  puVar6[2] = 1;
  (*pcVar2)(this->_button[1],puVar6);
  validate(this);
  bVar12 = SUB41(this,0);
  vgui::Panel::setPaintBorderEnabled(bVar12);
  vgui::Panel::setPaintBackgroundEnabled(bVar12);
  uVar13 = 1;
  vgui::Panel::setPaintEnabled(bVar12);
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  this->_buttonPressedScrollValue = 0xf;
  if (this->_slider != (Slider2 *)0x0) {
    ppBVar11 = this->_button;
    iVar9 = 0;
    do {
                    /* Unresolved local var: int buttonOffset@[???]
                       Unresolved local var: int i@[???] */
      pBVar7 = *ppBVar11;
      if ((pBVar7 != (Button *)0x0) &&
         (cVar3 = (**(code **)(*(int *)pBVar7 + 0x28))(pBVar7,uVar13), cVar3 != '\0')) {
        cVar3 = (**(code **)(*(int *)this->_slider + 0x204))(this->_slider);
        iVar10 = *(int *)*ppBVar11;
        if (cVar3 == '\0') {
          iVar10 = (**(code **)(iVar10 + 0x18))(*ppBVar11);
          iVar9 = iVar9 + iVar10;
        }
        else {
          iVar10 = (**(code **)(iVar10 + 0x1c))();
          iVar9 = iVar9 + iVar10;
        }
      }
      ppBVar11 = ppBVar11 + 1;
    } while (&this->_slider != (Slider2 **)ppBVar11);
    (**(code **)(*(int *)this->_slider + 0x224))(this->_slider,iVar9);
  }
  vgui::Panel::getSize((int *)this,&local_40);
  setSize(this,local_40,local_3c);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// vgui::ScrollBar2::setSize  @ 000a9780  (line 131)

/* DWARF original prototype: void setSize(ScrollBar2 * this, int wide, int tall) */

void __thiscall vgui::ScrollBar2::setSize(ScrollBar2 *this,int wide,int tall)

{
  Slider2 *pSVar1;
  char cVar2;
  
  vgui::Panel::setSize((int)this,wide);
  if (((this->_slider != (Slider2 *)0x0) && (this->_button[0] != (Button *)0x0)) &&
     (this->_button[1] != (Button *)0x0)) {
    (**(code **)(*(int *)this + 0xe8))(this,&wide,&tall);
    cVar2 = (**(code **)(*(int *)this->_slider + 0x204))(this->_slider);
    pSVar1 = this->_slider;
    if (cVar2 != '\0') {
      (**(code **)(*(int *)pSVar1 + 0x10))(pSVar1,0,wide,wide,tall + wide * -2);
      (**(code **)(*(int *)this->_button[0] + 0x10))(this->_button[0],0,0,wide,wide);
      (**(code **)(*(int *)this->_button[1] + 0x10))(this->_button[1],0,tall - wide,wide,wide);
      return;
    }
    (**(code **)(*(int *)pSVar1 + 0x10))(pSVar1,tall,0,wide + tall * -2,tall);
    (**(code **)(*(int *)this->_button[0] + 0x10))(this->_button[0],0,0,tall,tall);
    (**(code **)(*(int *)this->_button[1] + 0x10))(this->_button[1],wide - tall,0,tall,tall);
  }
  return;
}


// vgui::ScrollBar2::performLayout  @ 000a9460  (line 168)

/* DWARF original prototype: void performLayout(ScrollBar2 * this) */

void __thiscall vgui::ScrollBar2::performLayout(ScrollBar2 *this)

{
  return;
}


// vgui::ScrollBar2::setValue  @ 000a9470  (line 173)

/* DWARF original prototype: void setValue(ScrollBar2 * this, int value) */

void __thiscall vgui::ScrollBar2::setValue(ScrollBar2 *this,int value)

{
                    /* WARNING: Could not recover jumptable at 0x000a9480. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* catch() { ... } // from try @ 000a9490 with catch @ 000a9480
                       catch() { ... } // from try @ 000a94d9 with catch @ 000a9480 */
  (**(code **)(*(int *)this->_slider + 0x1fc))();
  return;
}


// vgui::ScrollBar2::getValue  @ 000a9490  (line 178)

/* DWARF original prototype: int getValue(ScrollBar2 * this) */

int __thiscall vgui::ScrollBar2::getValue(ScrollBar2 *this)

{
  int iVar1;
  
                    /* try { // try from 000a9490 to 000b9494 has its CatchHandler @ 000a9480 */
                    /* WARNING: Could not recover jumptable at 0x000a94a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(*(int *)this->_slider + 0x200))();
  return iVar1;
}


// vgui::ScrollBar2::addIntChangeSignal  @ 000a9a10  (line 182)

/* DWARF original prototype: void addIntChangeSignal(ScrollBar2 * this, IntChangeSignal * s) */

void __thiscall vgui::ScrollBar2::addIntChangeSignal(ScrollBar2 *this,IntChangeSignal *s)

{
  code *UNRECOVERED_JUMPTABLE;
  int *piVar1;
  int iVar2;
  IntChangeSignal **ppIVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  IntChangeSignal **ppIVar9;
  byte bVar10;
  int in_stack_ffffffc8;
  uint local_20;
  
  bVar10 = 0;
  iVar5 = (this->_intChangeSignalDar)._count;
                    /* Unresolved local var: int i@[???] */
  if (0 < iVar5) {
    ppIVar3 = (this->_intChangeSignalDar)._data;
    if (s != *ppIVar3) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        if (iVar5 == iVar2) goto LAB_000a9a4e;
      } while (s != ppIVar3[iVar2]);
    }
    goto LAB_000a9b3a;
  }
LAB_000a9a4e:
                    /* Unresolved local var: int newCapacity@[???]
                       Unresolved local var: IntChangeSignal * * newData@[???] */
  uVar8 = (this->_intChangeSignalDar)._capacity;
  iVar2 = iVar5 + 1;
  if (iVar2 <= (int)uVar8) {
    (this->_intChangeSignalDar)._data[iVar5] = s;
    (this->_intChangeSignalDar)._count = (this->_intChangeSignalDar)._count + 1;
    goto LAB_000a9b3a;
  }
  if (uVar8 == 0) {
    if (1 < iVar2) {
      uVar8 = 1;
      goto LAB_000a9a80;
    }
    local_20 = 4;
    uVar8 = 1;
  }
  else {
LAB_000a9a80:
    do {
      local_20 = uVar8;
      uVar8 = local_20 * 2;
    } while ((int)uVar8 < iVar2);
    if (0x1fc00000 < uVar8) {
      __cxa_throw_bad_array_new_length();
      piVar1 = *(int **)(in_stack_ffffffc8 + 4);
      if (*(code **)(*piVar1 + 0x238) != fireIntChangeSignal) {
                    /* WARNING: Could not recover jumptable at 0x000a9cf3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*piVar1 + 0x238))(piVar1);
        return;
      }
      iVar5 = piVar1[0x32];
      iVar2 = 0;
      if (0 < iVar5) {
        do {
          while( true ) {
            puVar4 = (undefined4 *)0x0;
            if (iVar2 < iVar5) {
              puVar4 = *(undefined4 **)(piVar1[0x34] + iVar2 * 4);
            }
            UNRECOVERED_JUMPTABLE = *(code **)*puVar4;
            uVar6 = (**(code **)(*(int *)piVar1[0x31] + 0x200))((int *)piVar1[0x31]);
            if (UNRECOVERED_JUMPTABLE ==
                anon_unknown.dwarf_1dbf7a::FooDefaultScrollBarIntChangeSignal::intChanged) break;
            iVar2 = iVar2 + 1;
            (*UNRECOVERED_JUMPTABLE)(puVar4,uVar6,piVar1);
            iVar5 = piVar1[0x32];
            if (iVar5 <= iVar2) {
              return;
            }
          }
          iVar2 = iVar2 + 1;
          (**(code **)(*(int *)puVar4[1] + 0x238))((int *)puVar4[1]);
          iVar5 = piVar1[0x32];
        } while (iVar2 < iVar5);
      }
      return;
    }
    local_20 = local_20 * 8;
  }
  ppIVar3 = operator_new__(local_20);
  if (ppIVar3 == (IntChangeSignal **)0x0) {
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  ppIVar9 = ppIVar3;
  if (7 < local_20) {
    if (((uint)ppIVar3 & 1) != 0) {
      *(undefined1 *)ppIVar3 = 0;
      ppIVar9 = (IntChangeSignal **)((int)ppIVar3 + 1);
      local_20 = local_20 - 1;
    }
    if (((uint)ppIVar9 & 2) != 0) {
      *(undefined2 *)ppIVar9 = 0;
      ppIVar9 = (IntChangeSignal **)((int)ppIVar9 + 2);
      local_20 = local_20 - 2;
    }
    if (((uint)ppIVar9 & 4) != 0) {
      *ppIVar9 = (IntChangeSignal *)0x0;
      ppIVar9 = ppIVar9 + 1;
      local_20 = local_20 - 4;
    }
    for (uVar7 = local_20 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *ppIVar9 = (IntChangeSignal *)0x0;
      ppIVar9 = ppIVar9 + (uint)bVar10 * -2 + 1;
    }
    local_20 = local_20 & 3;
  }
  if ((local_20 & 4) != 0) {
    *ppIVar9 = (IntChangeSignal *)0x0;
    ppIVar9 = ppIVar9 + 1;
  }
  if ((local_20 & 2) != 0) {
    *(undefined2 *)ppIVar9 = 0;
    ppIVar9 = (IntChangeSignal **)((int)ppIVar9 + 2);
  }
  if ((local_20 & 1) != 0) {
    *(undefined1 *)ppIVar9 = 0;
  }
                    /* Unresolved local var: int i@[???] */
  iVar5 = (this->_intChangeSignalDar)._count;
  (this->_intChangeSignalDar)._capacity = uVar8;
  if (0 < iVar5) {
    ppIVar9 = (this->_intChangeSignalDar)._data;
    iVar2 = 0;
    do {
      ppIVar3[iVar2] = ppIVar9[iVar2];
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar5);
  }
  ppIVar9 = (this->_intChangeSignalDar)._data;
  if (ppIVar9 != (IntChangeSignal **)0x0) {
    operator_delete__(ppIVar9);
    iVar5 = (this->_intChangeSignalDar)._count;
  }
  (this->_intChangeSignalDar)._data = ppIVar3;
  ppIVar3[iVar5] = s;
  (this->_intChangeSignalDar)._count = (this->_intChangeSignalDar)._count + 1;
LAB_000a9b3a:
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)this->_slider + 0x208);
  puVar4 = operator_new(8);
  *puVar4 = &PTR_intChanged_000cb994;
  puVar4[1] = this;
                    /* WARNING: Could not recover jumptable at 0x000a9b74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// vgui::ScrollBar2::setRange  @ 000a94b0  (line 189)

/* DWARF original prototype: void setRange(ScrollBar2 * this, int min, int max) */

void __thiscall vgui::ScrollBar2::setRange(ScrollBar2 *this,int min,int max)

{
                    /* WARNING: Could not recover jumptable at 0x000a94c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_slider + 0x20c))();
  return;
}


// vgui::ScrollBar2::fireIntChangeSignal  @ 000a9d00  (line 193)

/* DWARF original prototype: void fireIntChangeSignal(ScrollBar2 * this) */

void __thiscall vgui::ScrollBar2::fireIntChangeSignal(ScrollBar2 *this)

{
  _func_int_varargs **pp_Var1;
  code *pcVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  _func_int_varargs *p_Var7;
  undefined4 *puVar8;
  int iVar9;
  IntChangeSignal *pIVar10;
  int local_38;
  int local_34;
  int local_28;
  int local_20;
  
                    /* Unresolved local var: int i@[???] */
  local_20 = 0;
  if (0 < (this->_intChangeSignalDar)._count) {
    do {
      if (local_20 < 0) {
        pIVar10 = (IntChangeSignal *)0x0;
      }
      else {
        pIVar10 = (this->_intChangeSignalDar)._data[local_20];
      }
      p_Var7 = *pIVar10->_vptr_IntChangeSignal;
      uVar6 = (**(code **)(*(int *)this->_slider + 0x200))(this->_slider);
      if (p_Var7 == anon_unknown.dwarf_1dbf7a::FooDefaultScrollBarIntChangeSignal::intChanged) {
        pp_Var1 = pIVar10[1]._vptr_IntChangeSignal;
        if (*(code **)(*pp_Var1 + 0x238) == fireIntChangeSignal) {
          p_Var7 = pp_Var1[0x32];
                    /* Unresolved local var: int i@[???] */
          local_28 = 0;
          if (0 < (int)p_Var7) {
            do {
              puVar8 = (undefined4 *)0x0;
              if (local_28 < (int)p_Var7) {
                puVar8 = *(undefined4 **)(pp_Var1[0x34] + local_28 * 4);
              }
              pcVar2 = *(code **)*puVar8;
              uVar6 = (**(code **)(*(int *)pp_Var1[0x31] + 0x200))(pp_Var1[0x31]);
              if (pcVar2 == anon_unknown.dwarf_1dbf7a::FooDefaultScrollBarIntChangeSignal::
                            intChanged) {
                piVar3 = (int *)puVar8[1];
                if (*(code **)(*piVar3 + 0x238) == fireIntChangeSignal) {
                  iVar9 = piVar3[0x32];
                    /* Unresolved local var: int i@[???] */
                  local_34 = 0;
                  if (0 < iVar9) {
                    do {
                      puVar8 = (undefined4 *)0x0;
                      if (local_34 < iVar9) {
                        puVar8 = *(undefined4 **)(piVar3[0x34] + local_34 * 4);
                      }
                      pcVar2 = *(code **)*puVar8;
                      uVar6 = (**(code **)(*(int *)piVar3[0x31] + 0x200))((int *)piVar3[0x31]);
                      if (pcVar2 == anon_unknown.dwarf_1dbf7a::FooDefaultScrollBarIntChangeSignal::
                                    intChanged) {
                        piVar4 = (int *)puVar8[1];
                        if (*(code **)(*piVar4 + 0x238) == fireIntChangeSignal) {
                          iVar9 = piVar4[0x32];
                    /* Unresolved local var: int i@[???] */
                          local_38 = 0;
                          if (0 < iVar9) {
                            do {
                              puVar8 = (undefined4 *)0x0;
                              if (local_38 < iVar9) {
                                puVar8 = *(undefined4 **)(piVar4[0x34] + local_38 * 4);
                              }
                              pcVar2 = *(code **)*puVar8;
                              uVar6 = (**(code **)(*(int *)piVar4[0x31] + 0x200))
                                                ((int *)piVar4[0x31]);
                              if (pcVar2 == anon_unknown.dwarf_1dbf7a::
                                            FooDefaultScrollBarIntChangeSignal::intChanged) {
                                piVar5 = (int *)puVar8[1];
                                if (*(code **)(*piVar5 + 0x238) == fireIntChangeSignal) {
                    /* Unresolved local var: int i@[???] */
                                  iVar9 = 0;
                                  if (0 < piVar5[0x32]) {
                                    do {
                                      while( true ) {
                                        puVar8 = *(undefined4 **)(piVar5[0x34] + iVar9 * 4);
                                        pcVar2 = *(code **)*puVar8;
                                        uVar6 = (**(code **)(*(int *)piVar5[0x31] + 0x200))
                                                          ((int *)piVar5[0x31]);
                                        if (pcVar2 == anon_unknown.dwarf_1dbf7a::
                                                      FooDefaultScrollBarIntChangeSignal::intChanged
                                           ) break;
                                        iVar9 = iVar9 + 1;
                                        (*pcVar2)(puVar8,uVar6,piVar5);
                                        if (piVar5[0x32] <= iVar9) goto LAB_000a9f27;
                                      }
                                      iVar9 = iVar9 + 1;
                                      (**(code **)(*(int *)puVar8[1] + 0x238))((int *)puVar8[1]);
                                    } while (iVar9 < piVar5[0x32]);
                                  }
                                }
                                else {
                                  (**(code **)(*piVar5 + 0x238))(piVar5);
                                }
                              }
                              else {
                                (*pcVar2)(puVar8,uVar6,piVar4);
                              }
LAB_000a9f27:
                              local_38 = local_38 + 1;
                              iVar9 = piVar4[0x32];
                            } while (local_38 < iVar9);
                          }
                        }
                        else {
                          (**(code **)(*piVar4 + 0x238))(piVar4);
                        }
                      }
                      else {
                        (*pcVar2)(puVar8,uVar6,piVar3);
                      }
                      local_34 = local_34 + 1;
                      iVar9 = piVar3[0x32];
                    } while (local_34 < iVar9);
                  }
                }
                else {
                  (**(code **)(*piVar3 + 0x238))(piVar3);
                }
              }
              else {
                (*pcVar2)(puVar8,uVar6,pp_Var1);
              }
              local_28 = local_28 + 1;
              p_Var7 = pp_Var1[0x32];
            } while (local_28 < (int)p_Var7);
          }
        }
        else {
          (**(code **)(*pp_Var1 + 0x238))(pp_Var1);
        }
      }
      else {
        (*p_Var7)(pIVar10,uVar6,this);
      }
      local_20 = local_20 + 1;
    } while (local_20 < (this->_intChangeSignalDar)._count);
  }
  return;
}


// vgui::ScrollBar2::isVertical  @ 000a94d0  (line 202)

/* DWARF original prototype: bool isVertical(ScrollBar2 * this) */

bool __thiscall vgui::ScrollBar2::isVertical(ScrollBar2 *this)

{
  undefined1 uVar1;
  
                    /* try { // try from 000a94d9 to 000b9509 has its CatchHandler @ 000a9480 */
                    /* WARNING: Could not recover jumptable at 0x000a94e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(int *)this->_slider + 0x204))();
  return (bool)uVar1;
}


// vgui::ScrollBar2::hasFullRange  @ 000a94f0  (line 207)

/* DWARF original prototype: bool hasFullRange(ScrollBar2 * this) */

bool __thiscall vgui::ScrollBar2::hasFullRange(ScrollBar2 *this)

{
  undefined1 uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000a9506. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(int *)this->_slider + 0x220))();
  return (bool)uVar1;
}


// vgui::ScrollBar2::setButton  @ 000a96e0  (line 212)

/* DWARF original prototype: void setButton(ScrollBar2 * this, Button * button, int index) */

void __thiscall vgui::ScrollBar2::setButton(ScrollBar2 *this,Button *button,int index)

{
  code *pcVar1;
  Button *pBVar2;
  undefined4 *puVar3;
  
  if (this->_button[index] != (Button *)0x0) {
    (**(code **)(*(int *)this + 0x4c))(this,this->_button[index]);
  }
  this->_button[index] = button;
  (**(code **)(*(int *)this + 0x44))(this,button);
  pcVar1 = *(code **)(*(int *)this->_button[index] + 0x240);
  puVar3 = operator_new(0xc);
  pBVar2 = this->_button[index];
  puVar3[1] = this;
  puVar3[2] = index;
  *puVar3 = &PTR_actionPerformed_000cb9a0;
  (*pcVar1)(pBVar2,puVar3);
                    /* WARNING: Could not recover jumptable at 0x000a977e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x234))();
  return;
}


// vgui::ScrollBar2::getButton  @ 000a9510  (line 229)

/* DWARF original prototype: Button * getButton(ScrollBar2 * this, int index) */

Button * __thiscall vgui::ScrollBar2::getButton(ScrollBar2 *this,int index)

{
  return this->_button[index];
}


// vgui::ScrollBar2::setSlider  @ 000a9660  (line 234)

/* DWARF original prototype: void setSlider(ScrollBar2 * this, Slider2 * slider) */

void __thiscall vgui::ScrollBar2::setSlider(ScrollBar2 *this,Slider2 *slider)

{
  code *pcVar1;
  Slider2 *pSVar2;
  undefined4 *puVar3;
  
                    /* try { // try from 000a966a to 000b96a8 has its CatchHandler @ 000a9620 */
  if (this->_slider != (Slider2 *)0x0) {
    (**(code **)(*(int *)this + 0x4c))(this,this->_slider);
  }
  this->_slider = slider;
  (**(code **)(*(int *)this + 0x44))(this,slider);
                    /* catch() { ... } // from try @ 000a9658 with catch @ 000a9697 */
  pcVar1 = *(code **)(*(int *)this->_slider + 0x208);
  puVar3 = operator_new(8);
  pSVar2 = this->_slider;
  puVar3[1] = this;
  *puVar3 = &PTR_intChanged_000cb994;
  (*pcVar1)(pSVar2,puVar3);
                    /* WARNING: Could not recover jumptable at 0x000a96d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x234))();
  return;
}


// vgui::ScrollBar2::getSlider  @ 000a9520  (line 249)

/* DWARF original prototype: Slider2 * getSlider(ScrollBar2 * this) */

Slider2 * __thiscall vgui::ScrollBar2::getSlider(ScrollBar2 *this)

{
  return this->_slider;
}


// vgui::ScrollBar2::doButtonPressed  @ 000a9900  (line 253)

/* DWARF original prototype: void doButtonPressed(ScrollBar2 * this, int buttonIndex) */

void __thiscall vgui::ScrollBar2::doButtonPressed(ScrollBar2 *this,int buttonIndex)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = *(int *)this->_slider;
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x1fc);
  if (buttonIndex == 0) {
    (**(code **)(iVar1 + 0x200))(this->_slider);
  }
  else {
    (**(code **)(iVar1 + 0x200))();
  }
                    /* WARNING: Could not recover jumptable at 0x000a9951. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// vgui::ScrollBar2::setButtonPressedScrollValue  @ 000a9530  (line 267)

/* DWARF original prototype: void setButtonPressedScrollValue(ScrollBar2 * this, int value) */

void __thiscall vgui::ScrollBar2::setButtonPressedScrollValue(ScrollBar2 *this,int value)

{
  this->_buttonPressedScrollValue = value;
  return;
}


// vgui::ScrollBar2::setRangeWindow  @ 000a9540  (line 272)

/* DWARF original prototype: void setRangeWindow(ScrollBar2 * this, int rangeWindow) */

void __thiscall vgui::ScrollBar2::setRangeWindow(ScrollBar2 *this,int rangeWindow)

{
                    /* WARNING: Could not recover jumptable at 0x000a9550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_slider + 0x214))();
  return;
}


// vgui::ScrollBar2::setRangeWindowEnabled  @ 000a9560  (line 277)

/* DWARF original prototype: void setRangeWindowEnabled(ScrollBar2 * this, bool state) */

void __thiscall vgui::ScrollBar2::setRangeWindowEnabled(ScrollBar2 *this,bool state)

{
                    /* WARNING: Could not recover jumptable at 0x000a9579. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_slider + 0x218))();
  return;
}


// vgui::ScrollBar2::validate  @ 000a9580  (line 281)

/* DWARF original prototype: void validate(ScrollBar2 * this) */

void __thiscall vgui::ScrollBar2::validate(ScrollBar2 *this)

{
  Button *pBVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  Button **ppBVar5;
  undefined4 local_24;
  undefined4 local_20 [4];
  
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
                    /* catch() { ... } // from try @ 000a95e9 with catch @ 000a9590 */
                    /* try { // try from 000a95a0 to 000b95a4 has its CatchHandler @ 000a9590 */
  if (this->_slider != (Slider2 *)0x0) {
    ppBVar5 = this->_button;
    iVar4 = 0;
    do {
                    /* Unresolved local var: int buttonOffset@[???]
                       Unresolved local var: int i@[???] */
      pBVar1 = *ppBVar5;
      if (pBVar1 != (Button *)0x0) {
        cVar2 = (**(code **)(*(int *)pBVar1 + 0x28))(pBVar1);
        if (cVar2 != '\0') {
                    /* try { // try from 000a9630 to 000b9634 has its CatchHandler @ 000a9620 */
          cVar2 = (**(code **)(*(int *)this->_slider + 0x204))(this->_slider);
          iVar3 = *(int *)*ppBVar5;
          if (cVar2 == '\0') {
            iVar3 = (**(code **)(iVar3 + 0x18))(*ppBVar5);
            iVar4 = iVar4 + iVar3;
                    /* try { // try from 000a9658 to 000b965c has its CatchHandler @ 000a9697 */
          }
          else {
            iVar3 = (**(code **)(iVar3 + 0x1c))();
            iVar4 = iVar4 + iVar3;
          }
        }
      }
      ppBVar5 = ppBVar5 + 1;
    } while (&this->_slider != (Slider2 **)ppBVar5);
                    /* try { // try from 000a95d7 to 000b95db has its CatchHandler @ 000a9608 */
    (**(code **)(*(int *)this->_slider + 0x224))(this->_slider,iVar4);
  }
                    /* try { // try from 000a95e9 to 000b9619 has its CatchHandler @ 000a9590 */
  (**(code **)(*(int *)this + 0xc))(this,&local_24,local_20);
                    /* catch() { ... } // from try @ 000a95d7 with catch @ 000a9608 */
  (**(code **)(*(int *)this + 8))(this,local_24,local_20[0]);
                    /* catch() { ... } // from try @ 000a9630 with catch @ 000a9620
                       catch() { ... } // from try @ 000a966a with catch @ 000a9620 */
  return;
}


