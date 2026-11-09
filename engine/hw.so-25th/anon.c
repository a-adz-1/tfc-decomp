// anon_unknown.dwarf_3d51fd::ScrollBarButton::ApplySchemeSettings  @ 00221590
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void ApplySchemeSettings(ScrollBarButton * this, IScheme * pScheme) */

void __thiscall
anon_unknown.dwarf_3d51fd::ScrollBarButton::ApplySchemeSettings
          (ScrollBarButton *this,IScheme *pScheme)

{
  IBorder *pIVar1;
  Color local_2c;
  Color local_28;
  Color local_24;
  
  vgui2::Button::ApplySchemeSettings(&this->super_Button,pScheme);
  pIVar1 = (IBorder *)(**(code **)(*(int *)pScheme + 0xc))(pScheme,"ScrollBarButtonBorder");
  vgui2::Button::SetDefaultBorder(&this->super_Button,pIVar1);
  pIVar1 = (IBorder *)(**(code **)(*(int *)pScheme + 0xc))(pScheme,"ScrollBarButtonDepressedBorder")
  ;
  vgui2::Button::SetDepressedBorder(&this->super_Button,pIVar1);
  vgui2::Panel::GetBgColor((Panel *)&stack0xffffffe0);
  vgui2::Label::GetFgColor((Label *)&stack0xffffffe0);
  vgui2::Button::SetArmedColor(&this->super_Button,local_24,local_24);
  vgui2::Panel::GetBgColor((Panel *)&stack0xffffffe0);
  vgui2::Label::GetFgColor((Label *)&stack0xffffffe0);
  vgui2::Button::SetDepressedColor(&this->super_Button,local_28,local_28);
  vgui2::Panel::GetBgColor((Panel *)&stack0xffffffe0);
  vgui2::Panel::GetSchemeColor((Panel *)&stack0xffffffe0,(char *)this,(IScheme *)"DimBaseText");
  vgui2::Button::SetDefaultColor(&this->super_Button,local_2c,local_2c);
  vgui2::Label::SetContentAlignment((Label *)this,a_center);
  if (this->m_pImage != (IImage *)0x0) {
    vgui2::Label::AddImage((Label *)this,this->m_pImage,0);
  }
  return;
}


// anon_unknown.dwarf_3d51fd::ScrollBarButton::OnMouseFocusTicked  @ 00220670
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void OnMouseFocusTicked(ScrollBarButton * this) */

void __thiscall
anon_unknown.dwarf_3d51fd::ScrollBarButton::OnMouseFocusTicked(ScrollBarButton *this)

{
  KeyValues *this_00;
  
  this_00 = KeyValues::operator_new(0x18);
  KeyValues::KeyValues(this_00,"MouseFocusTicked");
  vgui2::Panel::CallParentFunction((Panel *)this,this_00);
  return;
}


// anon_unknown.dwarf_3d51fd::ScrollBarButton::OnMousePressed  @ 00220970
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void OnMousePressed(ScrollBarButton * this, MouseCode code) */

void __thiscall
anon_unknown.dwarf_3d51fd::ScrollBarButton::OnMousePressed(ScrollBarButton *this,MouseCode code)

{
  bool bVar1;
  IInput *pIVar2;
  
  bVar1 = vgui2::Panel::IsEnabled((Panel *)this);
  if (bVar1) {
    bVar1 = vgui2::Button::IsMouseClickEnabled(&this->super_Button,code);
    if (bVar1) {
      bVar1 = vgui2::Button::IsUseCaptureMouseEnabled(&this->super_Button);
      if (bVar1) {
        vgui2::Button::SetSelected(&this->super_Button,true);
        vgui2::Panel::Repaint((Panel *)this);
        pIVar2 = vgui2::input();
                    /* WARNING: Could not recover jumptable at 0x002209f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*(int *)pIVar2 + 0xc))();
        return;
      }
    }
  }
  return;
}


// anon_unknown.dwarf_3d51fd::ScrollBarButton::OnMouseReleased  @ 002206d0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void OnMouseReleased(ScrollBarButton * this, MouseCode code) */

void __thiscall
anon_unknown.dwarf_3d51fd::ScrollBarButton::OnMouseReleased(ScrollBarButton *this,MouseCode code)

{
  bool bVar1;
  IInput *pIVar2;
  
  bVar1 = vgui2::Panel::IsEnabled((Panel *)this);
  if (bVar1) {
    bVar1 = vgui2::Button::IsMouseClickEnabled(&this->super_Button,code);
    if (bVar1) {
      bVar1 = vgui2::Button::IsUseCaptureMouseEnabled(&this->super_Button);
      if (bVar1) {
        vgui2::Button::SetSelected(&this->super_Button,false);
        vgui2::Panel::Repaint((Panel *)this);
        pIVar2 = vgui2::input();
                    /* WARNING: Could not recover jumptable at 0x00220751. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*(int *)pIVar2 + 0xc))();
        return;
      }
    }
  }
  return;
}


// anon_unknown.dwarf_3d51fd::ScrollBarButton::~ScrollBarButton  @ 00220630
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void ~ScrollBarButton(ScrollBarButton * this, int __in_chrg) */

void __thiscall
anon_unknown.dwarf_3d51fd::ScrollBarButton::~ScrollBarButton(ScrollBarButton *this,int __in_chrg)

{
  (this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_002795ac;
  vgui2::Button::~Button(&this->super_Button,__in_chrg);
  return;
}


// anon_unknown.dwarf_3d51fd::ScrollBarButton::~ScrollBarButton  @ 00220640
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void ~ScrollBarButton(ScrollBarButton * this, int __in_chrg) */

void __thiscall
anon_unknown.dwarf_3d51fd::ScrollBarButton::~ScrollBarButton(ScrollBarButton *this,int __in_chrg)

{
  int in_stack_ffffffe8;
  
  (this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_002795ac;
  vgui2::Button::~Button(&this->super_Button,in_stack_ffffffe8);
  operator_delete(this);
  return;
}


// anon_unknown.dwarf_4434aa::CaptionGripPanel::moved  @ 00247730
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void moved(CaptionGripPanel * this, int dx, int dy) */

void __thiscall
anon_unknown.dwarf_4434aa::CaptionGripPanel::moved(CaptionGripPanel *this,int dx,int dy)

{
  Frame *pFVar1;
  _func_int_varargs *p_Var2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  ISurface *pIVar8;
  IPanel *pIVar9;
  int iVar10;
  VPANEL VVar11;
  VPANEL VVar12;
  bool bVar13;
  int iVar14;
  IClientPanel IVar15;
  int iVar16;
  int *piVar17;
  int *newX;
  VPANEL *newY;
  int local_64;
  int local_4c;
  IClientPanel local_48;
  int local_44;
  _func_int_varargs **local_40;
  VPANEL local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  VPANEL local_28;
  HCursor local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int newX@[???]
                       Unresolved local var: int newY@[???]
                       Unresolved local var: int wx@[???]
                       Unresolved local var: int wy@[???]
                       Unresolved local var: int ww@[???]
                       Unresolved local var: int wt@[???]
                       Unresolved local var: VPANEL root@[???] */
  pFVar1 = (this->super_GripPanel)._frame;
  p_Var2 = (pFVar1->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[0xa7];
  if (p_Var2 == vgui2::Frame::IsMoveable) {
    cVar6 = pFVar1->_moveable;
  }
  else {
    iVar7 = (*p_Var2)(pFVar1);
    cVar6 = (char)iVar7;
  }
  if (cVar6 == '\0') {
    return;
  }
                    /* Unresolved local var: int newX@[???]
                       Unresolved local var: int newY@[???]
                       Unresolved local var: int wx@[???]
                       Unresolved local var: int wy@[???]
                       Unresolved local var: int ww@[???]
                       Unresolved local var: int wt@[???]
                       Unresolved local var: VPANEL root@[???] */
  iVar7 = dx + (this->super_GripPanel)._dragOrgPos[0];
  local_48._vptr_IClientPanel = (_func_int_varargs **)(dy + (this->super_GripPanel)._dragOrgPos[1]);
  pIVar8 = vgui2::surface();
  newY = &local_3c;
  (*(pIVar8->super_IBaseInterface)._vptr_IBaseInterface[0x51])
            (pIVar8,&local_44,&local_40,newY,&local_38);
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: bool snapped@[???] */
  vgui2::Panel::GetSize((Panel *)(this->super_GripPanel)._frame,(int *)&local_24,local_20);
  local_4c = local_44;
  if ((0x12 < (iVar7 - local_44) + 9U) &&
     (local_4c = iVar7, ((iVar7 + local_24) - (local_44 + local_3c)) + 9 < 0x13)) {
    local_4c = (local_44 + local_3c) - local_24;
  }
  if ((uint)((int)local_48._vptr_IClientPanel + (9 - (int)local_40)) < 0x13) {
    local_48._vptr_IClientPanel = local_40;
  }
  else if ((uint)((int)local_48._vptr_IClientPanel + (local_20[0] - (local_38 + (int)local_40)) + 9)
           < 0x13) {
    local_48._vptr_IClientPanel = (_func_int_varargs **)((local_38 + (int)local_40) - local_20[0]);
  }
  pIVar8 = vgui2::surface();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: VPANEL child@[???]
                       Unresolved local var: int cx@[???]
                       Unresolved local var: int cy@[???]
                       Unresolved local var: int cw@[???]
                       Unresolved local var: int ct@[???] */
  iVar7 = (*(pIVar8->super_IBaseInterface)._vptr_IBaseInterface[4])(pIVar8);
  local_64 = 0;
  do {
    while( true ) {
      pIVar9 = vgui2::ipanel();
      iVar10 = (**(code **)(*(int *)pIVar9 + 0x48))(pIVar9,iVar7);
      if (iVar10 <= local_64) {
        vgui2::Panel::SetPos
                  ((Panel *)(this->super_GripPanel)._frame,local_4c,(int)local_48._vptr_IClientPanel
                  );
        return;
      }
      pIVar9 = vgui2::ipanel();
      VVar11 = (**(code **)(*(int *)pIVar9 + 0x4c))(pIVar9,iVar7,local_64);
      pFVar1 = (this->super_GripPanel)._frame;
      p_Var2 = *(pFVar1->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
      if (p_Var2 == vgui2::Panel::GetVPanel) {
        VVar12 = (pFVar1->super_EditablePanel).super_Panel._vpanel;
      }
      else {
        VVar12 = (*p_Var2)(pFVar1);
      }
      IVar15._vptr_IClientPanel = local_48._vptr_IClientPanel;
      if (VVar11 == VVar12) goto LAB_0024790b;
      pIVar9 = vgui2::ipanel();
      cVar6 = (**(code **)(*(int *)pIVar9 + 0x40))(pIVar9,VVar11);
      if (cVar6 != '\0') break;
LAB_002478c7:
                    /* Unresolved local var: bool snapped@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int bottom@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: bool horizSnappable@[???]
                       Unresolved local var: bool vertSnappable@[???] */
      newX = (int *)0x0;
      while( true ) {
        pIVar9 = vgui2::ipanel();
        iVar10 = (**(code **)(*(int *)pIVar9 + 0x48))(pIVar9,VVar11);
        IVar15._vptr_IClientPanel = local_48._vptr_IClientPanel;
        if (iVar10 <= (int)newX) break;
        pIVar9 = vgui2::ipanel();
        piVar17 = (int *)((int)newX + 1);
        VVar12 = VVar11;
        (**(code **)(*(int *)pIVar9 + 0x4c))(pIVar9);
        tryToDock((CaptionGripPanel *)&local_48,VVar12,newX,(int *)newY);
        newX = piVar17;
      }
LAB_0024790b:
      local_48._vptr_IClientPanel = IVar15._vptr_IClientPanel;
      local_64 = local_64 + 1;
    }
    pIVar9 = vgui2::ipanel();
    cVar6 = (**(code **)(*(int *)pIVar9 + 0x60))(pIVar9,VVar11);
    if (cVar6 == '\0') goto LAB_002478c7;
    pIVar9 = vgui2::ipanel();
    (**(code **)(*(int *)pIVar9 + 0x2c))(pIVar9,VVar11,&local_34,&local_30);
    pIVar9 = vgui2::ipanel();
    newY = &local_28;
    (**(code **)(*(int *)pIVar9 + 0x18))(pIVar9,VVar11,&local_2c);
    iVar5 = local_30;
    iVar10 = local_34;
    iVar14 = local_2c + local_34;
    IVar15._vptr_IClientPanel = (_func_int_varargs **)(local_28 + local_30);
    vgui2::Panel::GetSize((Panel *)(this->super_GripPanel)._frame,(int *)&local_24,local_20);
    if ((((int)IVar15._vptr_IClientPanel <= (int)local_48._vptr_IClientPanel) ||
        (bVar13 = true, (int)local_48._vptr_IClientPanel <= iVar5)) &&
       ((iVar16 = local_20[0] + (int)local_48._vptr_IClientPanel,
        (int)IVar15._vptr_IClientPanel <= iVar16 || (bVar13 = true, iVar16 <= iVar5)))) {
      bVar13 = (int)IVar15._vptr_IClientPanel < iVar16 && (int)local_48._vptr_IClientPanel < iVar5;
                    /* try { // try from 00247b20 to 00257b9a has its CatchHandler @ 00247bb1 */
    }
    if (((local_4c <= iVar10) || (bVar3 = true, iVar14 <= local_4c)) &&
       (((iVar16 = local_24 + local_4c, iVar14 <= iVar16 || (bVar3 = true, iVar16 <= iVar10)) &&
        ((iVar10 <= local_4c || (bVar3 = true, iVar16 <= iVar14)))))) {
      if (!bVar13) goto LAB_002478c7;
      bVar3 = false;
    }
    if ((iVar14 + 10 < local_4c) || (local_4c < iVar14 + -10)) {
      bVar4 = false;
      if (iVar10 + -10 <= (int)(local_4c + local_24)) {
                    /* catch() { ... } // from try @ 00247b20 with catch @ 00247bb1 */
        if ((iVar10 + 10 < (int)(local_4c + local_24)) || (!bVar13)) {
          bVar4 = false;
        }
        else {
                    /* try { // try from 00247bbe to 00257bc2 has its CatchHandler @ 00247ab0 */
          bVar4 = true;
          local_4c = iVar10 - local_24;
        }
      }
    }
    else {
      bVar4 = false;
      if (bVar13) {
        bVar4 = true;
        local_4c = iVar14;
      }
    }
    if (((int)IVar15._vptr_IClientPanel + 10 < (int)local_48._vptr_IClientPanel) ||
       ((int)local_48._vptr_IClientPanel < (int)IVar15._vptr_IClientPanel + -10)) {
      if ((iVar5 + 10 < (int)local_48._vptr_IClientPanel + local_20[0]) ||
         (((int)local_48._vptr_IClientPanel + local_20[0] < iVar5 + -10 || (!bVar3))))
      goto LAB_00247a80;
      IVar15._vptr_IClientPanel = (_func_int_varargs **)(iVar5 - local_20[0]);
      goto LAB_0024790b;
    }
    if (bVar3) goto LAB_0024790b;
LAB_00247a80:
    if (!bVar4) goto LAB_002478c7;
    local_64 = local_64 + 1;
  } while( true );
}


// anon_unknown.dwarf_4434aa::CaptionGripPanel::tryToDock  @ 00247180
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void tryToDock(CaptionGripPanel * this, VPANEL window, int * newX, int
   * newY) */

void __thiscall
anon_unknown.dwarf_4434aa::CaptionGripPanel::tryToDock
          (CaptionGripPanel *this,VPANEL window,int *newX,int *newY)

{
  undefined4 *puVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int in_EAX;
  IPanel *pIVar5;
  int iVar6;
  VPANEL VVar7;
  int iVar8;
  _func_int_varargs **pp_Var9;
  _func_int_varargs **pp_Var10;
  VPANEL VVar11;
  bool bVar12;
  int *in_ECX;
  int in_EDX;
  int iVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int *newX_00;
  int *in_stack_ffffff90;
  int local_64;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int cx@[???]
                       Unresolved local var: int cy@[???]
                       Unresolved local var: int cw@[???]
                       Unresolved local var: int ct@[???] */
  puVar1 = *(undefined4 **)(in_EAX + 0x74);
  if (*(code **)*puVar1 == vgui2::Panel::GetVPanel) {
    iVar6 = puVar1[8];
  }
  else {
    iVar6 = (**(code **)*puVar1)(puVar1);
  }
  if (iVar6 == in_EDX) {
    return;
  }
  pIVar5 = vgui2::ipanel();
  cVar4 = (**(code **)(*(int *)pIVar5 + 0x40))(pIVar5,in_EDX);
  if (cVar4 != '\0') {
    pIVar5 = vgui2::ipanel();
    cVar4 = (**(code **)(*(int *)pIVar5 + 0x60))(pIVar5,in_EDX);
    if (cVar4 != '\0') {
      pIVar5 = vgui2::ipanel();
      (**(code **)(*(int *)pIVar5 + 0x2c))(pIVar5,in_EDX,&local_44,&local_40);
      pIVar5 = vgui2::ipanel();
      in_stack_ffffff90 = &local_38;
      (**(code **)(*(int *)pIVar5 + 0x18))(pIVar5,in_EDX,&local_3c);
      iVar6 = local_3c + local_44;
      pp_Var9 = (_func_int_varargs **)(local_38 + local_40);
      vgui2::Panel::GetSize(*(Panel **)(in_EAX + 0x74),&local_24,local_20);
      pp_Var10 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
                    /* catch() { ... } // from try @ 002473a8 with catch @ 00247340 */
      if ((((int)pp_Var9 <= (int)pp_Var10) || (bVar12 = true, (int)pp_Var10 <= local_40)) &&
         ((iVar15 = local_20[0] + (int)pp_Var10, (int)pp_Var9 <= iVar15 ||
          (bVar12 = true, iVar15 <= local_40)))) {
        bVar12 = (int)pp_Var9 < iVar15 && (int)pp_Var10 < local_40;
      }
      iVar15 = *in_ECX;
      if (((iVar6 <= iVar15) || (bVar2 = true, iVar15 <= local_44)) &&
         (((iVar8 = local_24 + iVar15, iVar6 <= iVar8 || (bVar2 = true, iVar8 <= local_44)) &&
          ((iVar8 <= iVar6 || (bVar2 = true, local_44 <= iVar15)))))) {
        if (!bVar12) goto LAB_002471d3;
        bVar2 = false;
      }
                    /* try { // try from 00247377 to 0025737b has its CatchHandler @ 00247397 */
      if ((iVar6 + 10 < iVar15) || (iVar15 < iVar6 + -10)) {
        bVar3 = false;
        if (local_44 + -10 <= iVar15 + local_24) {
          if ((local_44 + 10 < iVar15 + local_24) || (!bVar12)) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
            *in_ECX = local_44 - local_24;
            pp_Var10 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
          }
        }
      }
      else {
        bVar3 = false;
        if (bVar12) {
                    /* catch() { ... } // from try @ 00247377 with catch @ 00247397 */
          bVar3 = true;
          *in_ECX = iVar6;
          pp_Var10 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
        }
      }
                    /* try { // try from 002473a8 to 002573ac has its CatchHandler @ 00247340 */
      if (((int)pp_Var9 + 10 < (int)pp_Var10) || ((int)pp_Var10 < (int)pp_Var9 + -10)) {
        if (((int)pp_Var10 + local_20[0] <= local_40 + 10) &&
           ((local_40 + -10 <= (int)pp_Var10 + local_20[0] && (bVar2)))) {
          (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel =
               (_func_int_varargs **)(local_40 - local_20[0]);
          return;
        }
      }
      else if (bVar2) {
        (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel = pp_Var9;
        return;
      }
      if (bVar3) {
        return;
      }
    }
  }
LAB_002471d3:
                    /* Unresolved local var: bool snapped@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int bottom@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: bool horizSnappable@[???]
                       Unresolved local var: bool vertSnappable@[???] */
  local_64 = 0;
  do {
    while( true ) {
                    /* Unresolved local var: int i@[???] */
      pIVar5 = vgui2::ipanel();
      iVar6 = (**(code **)(*(int *)pIVar5 + 0x48))(pIVar5,in_EDX);
      if (iVar6 <= local_64) {
        return;
      }
                    /* Unresolved local var: VPANEL child@[???] */
      pIVar5 = vgui2::ipanel();
      VVar7 = (**(code **)(*(int *)pIVar5 + 0x4c))(pIVar5,in_EDX,local_64);
                    /* Unresolved local var: int cx@[???]
                       Unresolved local var: int cy@[???]
                       Unresolved local var: int cw@[???]
                       Unresolved local var: int ct@[???] */
      puVar1 = *(undefined4 **)(in_EAX + 0x74);
      if (*(code **)*puVar1 == vgui2::Panel::GetVPanel) {
        VVar11 = puVar1[8];
      }
      else {
        VVar11 = (**(code **)*puVar1)(puVar1);
      }
      if (VVar7 == VVar11) goto LAB_0024728b;
      pIVar5 = vgui2::ipanel();
      cVar4 = (**(code **)(*(int *)pIVar5 + 0x40))(pIVar5,VVar7);
      if (cVar4 != '\0') break;
LAB_0024724b:
                    /* Unresolved local var: bool snapped@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int bottom@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: bool horizSnappable@[???]
                       Unresolved local var: bool vertSnappable@[???] */
      newX_00 = (int *)0x0;
      while( true ) {
        pIVar5 = vgui2::ipanel();
        iVar6 = (**(code **)(*(int *)pIVar5 + 0x48))(pIVar5,VVar7);
        if (iVar6 <= (int)newX_00) break;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: VPANEL child@[???] */
        pIVar5 = vgui2::ipanel();
        piVar16 = (int *)((int)newX_00 + 1);
        VVar11 = VVar7;
        (**(code **)(*(int *)pIVar5 + 0x4c))(pIVar5);
        tryToDock(this,VVar11,newX_00,in_stack_ffffff90);
        newX_00 = piVar16;
      }
LAB_0024728b:
      local_64 = local_64 + 1;
    }
    pIVar5 = vgui2::ipanel();
    cVar4 = (**(code **)(*(int *)pIVar5 + 0x60))(pIVar5,VVar7);
    if (cVar4 == '\0') goto LAB_0024724b;
    pIVar5 = vgui2::ipanel();
    (**(code **)(*(int *)pIVar5 + 0x2c))(pIVar5,VVar7,&local_34,&local_30);
    pIVar5 = vgui2::ipanel();
    in_stack_ffffff90 = &local_28;
    (**(code **)(*(int *)pIVar5 + 0x18))(pIVar5,VVar7,&local_2c);
    iVar15 = local_30;
    iVar6 = local_34;
    iVar8 = local_34 + local_2c;
    pp_Var9 = (_func_int_varargs **)(local_28 + local_30);
    vgui2::Panel::GetSize(*(Panel **)(in_EAX + 0x74),&local_24,local_20);
    pp_Var10 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
    if ((((int)pp_Var10 <= iVar15) || (bVar12 = true, (int)pp_Var9 <= (int)pp_Var10)) &&
       ((iVar14 = local_20[0] + (int)pp_Var10, iVar14 <= iVar15 ||
        (bVar12 = true, (int)pp_Var9 <= iVar14)))) {
      bVar12 = (int)pp_Var9 < iVar14 && (int)pp_Var10 < iVar15;
    }
    iVar14 = *in_ECX;
    if ((((iVar8 <= iVar14) || (bVar2 = true, iVar14 <= iVar6)) &&
        ((iVar13 = local_24 + iVar14, iVar13 <= iVar6 || (bVar2 = true, iVar8 <= iVar13)))) &&
       ((iVar13 <= iVar8 || (bVar2 = true, iVar6 <= iVar14)))) {
      if (!bVar12) goto LAB_0024724b;
      bVar2 = false;
    }
    if ((iVar8 + 10 < iVar14) || (iVar14 < iVar8 + -10)) {
      bVar3 = false;
      if (iVar6 + -10 <= iVar14 + local_24) {
        if ((iVar6 + 10 < iVar14 + local_24) || (!bVar12)) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
          *in_ECX = iVar6 - local_24;
          pp_Var10 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
        }
      }
    }
    else {
      bVar3 = false;
      if (bVar12) {
        bVar3 = true;
        *in_ECX = iVar8;
        pp_Var10 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
      }
    }
    if (((int)pp_Var9 + 10 < (int)pp_Var10) || ((int)pp_Var10 < (int)pp_Var9 + -10)) {
      if ((iVar15 + 10 < (int)pp_Var10 + local_20[0]) ||
         (((int)pp_Var10 + local_20[0] < iVar15 + -10 || (!bVar2)))) goto LAB_00247578;
      (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel =
           (_func_int_varargs **)(iVar15 - local_20[0]);
      goto LAB_0024728b;
    }
    if (bVar2) {
      (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel = pp_Var9;
      goto LAB_0024728b;
    }
LAB_00247578:
    if (!bVar3) goto LAB_0024724b;
    local_64 = local_64 + 1;
  } while( true );
}


// anon_unknown.dwarf_4434aa::CaptionGripPanel::~CaptionGripPanel  @ 00245b00
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void ~CaptionGripPanel(CaptionGripPanel * this, int __in_chrg) */

void __thiscall
anon_unknown.dwarf_4434aa::CaptionGripPanel::~CaptionGripPanel(CaptionGripPanel *this,int __in_chrg)

{
  (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_0027d2ec;
  vgui2::Panel::~Panel((Panel *)this,__in_chrg);
  return;
}


// anon_unknown.dwarf_4434aa::CaptionGripPanel::~CaptionGripPanel  @ 00245b10
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void ~CaptionGripPanel(CaptionGripPanel * this, int __in_chrg) */

void __thiscall
anon_unknown.dwarf_4434aa::CaptionGripPanel::~CaptionGripPanel(CaptionGripPanel *this,int __in_chrg)

{
  int in_stack_ffffffe8;
  
  (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_0027d2ec;
  vgui2::Panel::~Panel((Panel *)this,in_stack_ffffffe8);
  operator_delete(this);
  return;
}


// anon_unknown.dwarf_4434aa::GripPanel::ApplySchemeSettings  @ 00248930
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void ApplySchemeSettings(GripPanel * this, IScheme * pScheme) */

void __thiscall
anon_unknown.dwarf_4434aa::GripPanel::ApplySchemeSettings(GripPanel *this,IScheme *pScheme)

{
  Color local_10;
  
  vgui2::Panel::ApplySchemeSettings(&this->super_Panel,pScheme);
  vgui2::Panel::GetSchemeColor((Panel *)&local_10,(char *)this,(IScheme *)"BorderBright");
  vgui2::Panel::SetFgColor(&this->super_Panel,local_10);
  vgui2::Panel::GetSchemeColor((Panel *)&local_10,(char *)this,(IScheme *)"BorderSelection");
  vgui2::Panel::SetBgColor(&this->super_Panel,local_10);
  return;
}


// anon_unknown.dwarf_4434aa::GripPanel::OnCursorMoved  @ 00245fc0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void OnCursorMoved(GripPanel * this, int x, int y) */

void __thiscall anon_unknown.dwarf_4434aa::GripPanel::OnCursorMoved(GripPanel *this,int x,int y)

{
  char cVar1;
  IInput *pIVar2;
  
  if (this->_dragging == false) {
    return;
  }
  pIVar2 = vgui2::input();
  cVar1 = (**(code **)(*(int *)pIVar2 + 0x2c))(pIVar2,0);
  if (cVar1 != '\0') {
    pIVar2 = vgui2::input();
    (**(code **)(*(int *)pIVar2 + 0x20))(pIVar2,&x,&y);
    (*(this->super_Panel).super_IClientPanel._vptr_IClientPanel[0x87])
              (this,x - this->_dragStart[0],y - this->_dragStart[1]);
    (*(this->_frame->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[4])
              (this->_frame);
    return;
  }
  this->_dragging = false;
  pIVar2 = vgui2::input();
  (**(code **)(*(int *)pIVar2 + 0xc))(pIVar2,0);
  return;
}


// anon_unknown.dwarf_4434aa::GripPanel::OnMouseCaptureLost  @ 00245cf0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void OnMouseCaptureLost(GripPanel * this) */

void __thiscall anon_unknown.dwarf_4434aa::GripPanel::OnMouseCaptureLost(GripPanel *this)

{
  vgui2::Panel::OnMouseCaptureLost(&this->super_Panel);
  this->_dragging = false;
  return;
}


// anon_unknown.dwarf_4434aa::GripPanel::OnMousePressed  @ 002465c0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void OnMousePressed(GripPanel * this, MouseCode code) */

void __thiscall anon_unknown.dwarf_4434aa::GripPanel::OnMousePressed(GripPanel *this,MouseCode code)

{
  code *pcVar1;
  Frame *pFVar2;
  _func_int_varargs *p_Var3;
  char cVar4;
  IInput *pIVar5;
  int iVar6;
  IPanel *pIVar7;
  VPANEL VVar8;
  int local_24;
  int local_20 [4];
  
  if (code != MOUSE_LEFT) {
    return;
  }
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: VPANEL focus@[???] */
  this->_dragging = true;
  pIVar5 = vgui2::input();
  (**(code **)(*(int *)pIVar5 + 0x20))(pIVar5,&local_24,local_20);
  this->_dragStart[0] = local_24;
  this->_dragStart[1] = local_20[0];
  vgui2::Panel::GetPos((Panel *)this->_frame,this->_dragOrgPos,this->_dragOrgPos + 1);
  vgui2::Panel::GetSize((Panel *)this->_frame,this->_dragOrgSize,this->_dragOrgSize + 1);
  pIVar5 = vgui2::input();
  (**(code **)(*(int *)pIVar5 + 0xc))(pIVar5,(this->super_Panel)._vpanel);
  pIVar5 = vgui2::input();
  iVar6 = (**(code **)(*(int *)pIVar5 + 0x14))(pIVar5);
  if (iVar6 != 0) {
    pIVar7 = vgui2::ipanel();
    pcVar1 = *(code **)(*(int *)pIVar7 + 0x5c);
    pFVar2 = this->_frame;
    p_Var3 = *(pFVar2->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
    if (p_Var3 == vgui2::Panel::GetVPanel) {
      VVar8 = (pFVar2->super_EditablePanel).super_Panel._vpanel;
    }
    else {
      VVar8 = (*p_Var3)(pFVar2);
    }
    cVar4 = (*pcVar1)(pIVar7,iVar6,VVar8);
    if (cVar4 != '\0') goto LAB_002466a6;
  }
  (*(this->_frame->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[0xc])
            (this->_frame,0);
LAB_002466a6:
  (*(this->_frame->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[4])
            (this->_frame);
  return;
}


// anon_unknown.dwarf_4434aa::GripPanel::OnMouseReleased  @ 00245c00
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void OnMouseReleased(GripPanel * this, MouseCode code) */

void __thiscall
anon_unknown.dwarf_4434aa::GripPanel::OnMouseReleased(GripPanel *this,MouseCode code)

{
  IInput *pIVar1;
  
  this->_dragging = false;
  pIVar1 = vgui2::input();
                    /* WARNING: Could not recover jumptable at 0x00245c25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)pIVar1 + 0xc))();
  return;
}


// anon_unknown.dwarf_4434aa::GripPanel::PaintBackground  @ 00245670
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void PaintBackground(GripPanel * this) */

void __thiscall anon_unknown.dwarf_4434aa::GripPanel::PaintBackground(GripPanel *this)

{
  if (this->m_pImage != (IImage *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00245684. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**this->m_pImage->_vptr_IImage)();
    return;
  }
  return;
}


// anon_unknown.dwarf_4434aa::GripPanel::moved  @ 00246710
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void moved(GripPanel * this, int dx, int dy) */

void __thiscall anon_unknown.dwarf_4434aa::GripPanel::moved(GripPanel *this,int dx,int dy)

{
  Frame *pFVar1;
  _func_int_varargs *p_Var2;
  char cVar3;
  int iVar4;
  int y;
  int iVar5;
  int iVar6;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int newX@[???]
                       Unresolved local var: int newY@[???]
                       Unresolved local var: int newWide@[???]
                       Unresolved local var: int newTall@[???]
                       Unresolved local var: int minWide@[???]
                       Unresolved local var: int minTall@[???] */
  pFVar1 = this->_frame;
  p_Var2 = (pFVar1->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[0xa9];
  if (p_Var2 == vgui2::Frame::IsSizeable) {
    cVar3 = pFVar1->_sizeable;
  }
  else {
    iVar4 = (*p_Var2)(pFVar1);
    cVar3 = (char)iVar4;
  }
  if (cVar3 != '\0') {
                    /* Unresolved local var: int newX@[???]
                       Unresolved local var: int newY@[???]
                       Unresolved local var: int newWide@[???]
                       Unresolved local var: int newTall@[???]
                       Unresolved local var: int minWide@[???]
                       Unresolved local var: int minTall@[???] */
    iVar4 = this->_dragOrgPos[0];
    iVar6 = this->_dragOrgSize[0];
    y = this->_dragOrgPos[1];
    iVar5 = this->_dragOrgSize[1];
    vgui2::Panel::GetMinimumSize((Panel *)this->_frame,&local_24,local_20);
    iVar6 = iVar6 + dx * this->_dragMultX;
    if (this->_dragMultX == -1) {
      if (iVar6 < local_24) {
        dx = this->_dragOrgSize[0] - local_24;
      }
      iVar4 = iVar4 + dx;
    }
    iVar5 = iVar5 + dy * this->_dragMultY;
    if (this->_dragMultY == -1) {
      if (iVar5 < local_20[0]) {
        dy = this->_dragOrgSize[1] - local_20[0];
      }
      y = y + dy;
    }
    vgui2::Panel::SetPos((Panel *)this->_frame,iVar4,y);
    vgui2::Panel::SetSize((Panel *)this->_frame,iVar6,iVar5);
    (*(this->_frame->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[0x3b])
              (this->_frame,0,0);
    (*(this->_frame->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[4])
              (this->_frame);
  }
  return;
}


// anon_unknown.dwarf_4434aa::GripPanel::~GripPanel  @ 00245ac0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void ~GripPanel(GripPanel * this, int __in_chrg) */

void __thiscall anon_unknown.dwarf_4434aa::GripPanel::~GripPanel(GripPanel *this,int __in_chrg)

{
  (this->super_Panel).super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_0027d2ec;
  vgui2::Panel::~Panel(&this->super_Panel,__in_chrg);
  return;
}


// anon_unknown.dwarf_4434aa::GripPanel::~GripPanel  @ 00245ad0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void ~GripPanel(GripPanel * this, int __in_chrg) */

void __thiscall anon_unknown.dwarf_4434aa::GripPanel::~GripPanel(GripPanel *this,int __in_chrg)

{
  int in_stack_ffffffe8;
  
  (this->super_Panel).super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_0027d2ec;
  vgui2::Panel::~Panel(&this->super_Panel,in_stack_ffffffe8);
  operator_delete(this);
  return;
}


