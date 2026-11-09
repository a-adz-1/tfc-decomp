// anon_unknown.dwarf_2bc401::ScrollBarButton::ApplySchemeSettings  @ 00254a40
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void ApplySchemeSettings(ScrollBarButton * this, IScheme * pScheme) */

void __thiscall
anon_unknown.dwarf_2bc401::ScrollBarButton::ApplySchemeSettings
          (ScrollBarButton *this,IScheme *pScheme)

{
  _func_int_varargs *p_Var1;
  _func_int_varargs **pp_Var2;
  undefined4 uVar3;
  ScrollBarButton *pSVar4;
  undefined4 local_34;
  undefined4 local_2c;
  undefined4 local_24;
  undefined1 local_20 [16];
  
  vgui2::Button::ApplySchemeSettings(&this->super_Button,pScheme);
  p_Var1 = (this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[0xc1];
  uVar3 = (**(code **)(*(int *)pScheme + 0xc))(pScheme,"ScrollBarButtonBorder");
  (*p_Var1)(this,uVar3);
  p_Var1 = (this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[0xc2];
  uVar3 = (**(code **)(*(int *)pScheme + 0xc))(pScheme,"ScrollBarButtonDepressedBorder");
  (*p_Var1)(this,uVar3);
  pp_Var2 = (this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel;
  p_Var1 = pp_Var2[0xbd];
  (*pp_Var2[0x36])(local_20,this);
  (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[0x37])
            (local_20,this);
  uVar3 = local_2c;
  (*p_Var1)(this,local_24,local_2c);
  pp_Var2 = (this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel;
  p_Var1 = pp_Var2[0xbe];
  pSVar4 = this;
  (*pp_Var2[0x36])(local_20,this);
  (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[0x37])
            (local_20,this);
  (*p_Var1)(this,local_2c,local_34);
  pp_Var2 = (this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel;
  p_Var1 = pp_Var2[0xbc];
  (*pp_Var2[0x36])(local_20,this);
  (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[0x4e])
            (local_20,this,"DimBaseText",pScheme,pSVar4,uVar3,local_34);
  (*p_Var1)(this,local_34,uVar3);
  (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[0x8c])
            (this,4);
  if (this->m_pImage != (IImage *)0x0) {
    (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[0x97])
              (this,this->m_pImage,0);
  }
  return;
}


// anon_unknown.dwarf_2bc401::ScrollBarButton::OnMouseFocusTicked  @ 00254a00
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void OnMouseFocusTicked(ScrollBarButton * this) */

void __thiscall
anon_unknown.dwarf_2bc401::ScrollBarButton::OnMouseFocusTicked(ScrollBarButton *this)

{
  KeyValues *this_00;
  
  this_00 = KeyValues::operator_new(0x18);
  KeyValues::KeyValues(this_00,"MouseFocusTicked");
  vgui2::Panel::CallParentFunction((Panel *)this,this_00);
  return;
}


// anon_unknown.dwarf_2bc401::ScrollBarButton::OnMousePressed  @ 00254d10
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void OnMousePressed(ScrollBarButton * this, MouseCode code) */

void __thiscall
anon_unknown.dwarf_2bc401::ScrollBarButton::OnMousePressed(ScrollBarButton *this,MouseCode code)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  IInput *pIVar2;
  
  iVar1 = (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[0x31]
          )(this);
  if ((char)iVar1 != '\0') {
    iVar1 = (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel
              [0xb5])(this,code);
    if ((char)iVar1 != '\0') {
      iVar1 = (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel
                [0xb1])(this);
      if ((char)iVar1 != '\0') {
        (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[0xae])
                  (this,1);
        (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[4])
                  (this);
        pIVar2 = vgui2::input();
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)pIVar2 + 0xc);
        (**(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel)(this)
        ;
                    /* WARNING: Could not recover jumptable at 0x00254dba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)();
        return;
      }
    }
  }
  return;
}


// anon_unknown.dwarf_2bc401::ScrollBarButton::OnMouseReleased  @ 00254c80
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void OnMouseReleased(ScrollBarButton * this, MouseCode code) */

void __thiscall
anon_unknown.dwarf_2bc401::ScrollBarButton::OnMouseReleased(ScrollBarButton *this,MouseCode code)

{
  int iVar1;
  IInput *pIVar2;
  
  iVar1 = (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[0x31]
          )(this);
  if ((char)iVar1 != '\0') {
    iVar1 = (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel
              [0xb5])(this,code);
    if ((char)iVar1 != '\0') {
      iVar1 = (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel
                [0xb1])(this);
      if ((char)iVar1 != '\0') {
        (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[0xae])
                  (this,0);
        (*(this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel[4])
                  (this);
        pIVar2 = vgui2::input();
                    /* WARNING: Could not recover jumptable at 0x00254d0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*(int *)pIVar2 + 0xc))();
        return;
      }
    }
  }
  return;
}


// anon_unknown.dwarf_2bc401::ScrollBarButton::~ScrollBarButton  @ 00254bc0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void ~ScrollBarButton(ScrollBarButton * this, int __in_chrg) */

void __thiscall
anon_unknown.dwarf_2bc401::ScrollBarButton::~ScrollBarButton(ScrollBarButton *this,int __in_chrg)

{
  (this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_0029afc8;
  vgui2::Button::~Button(&this->super_Button,__in_chrg);
  return;
}


// anon_unknown.dwarf_2bc401::ScrollBarButton::~ScrollBarButton  @ 00254bd0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* DWARF original prototype: void ~ScrollBarButton(ScrollBarButton * this, int __in_chrg) */

void __thiscall
anon_unknown.dwarf_2bc401::ScrollBarButton::~ScrollBarButton(ScrollBarButton *this,int __in_chrg)

{
  int in_stack_ffffffe8;
  
  (this->super_Button).super_Label.super_Panel.super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_0029afc8;
  vgui2::Button::~Button(&this->super_Button,in_stack_ffffffe8);
  operator_delete(this);
  return;
}


// anon_unknown.dwarf_30150d::CaptionGripPanel::moved  @ 00271e50
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void moved(CaptionGripPanel * this, int dx, int dy) */

void __thiscall
anon_unknown.dwarf_30150d::CaptionGripPanel::moved(CaptionGripPanel *this,int dx,int dy)

{
  Frame *pFVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char *pcVar5;
  char cVar6;
  int iVar7;
  ISurface *pIVar8;
  IPanel *pIVar9;
  int iVar10;
  VPANEL VVar11;
  VPANEL VVar12;
  IClientPanel IVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int *newX;
  Color *newY;
  int local_98;
  int local_7c;
  IClientPanel local_6c;
  int local_5c [4];
  VPANEL local_4c [4];
  int local_3c;
  BuildGroup *local_38;
  Color local_34;
  Color local_30;
  int local_2c;
  char *local_28;
  int local_24;
  Color local_20 [4];
  
                    /* Unresolved local var: int newX@[???]
                       Unresolved local var: int newY@[???]
                       Unresolved local var: int wx@[???]
                       Unresolved local var: int wy@[???]
                       Unresolved local var: int ww@[???]
                       Unresolved local var: int wt@[???]
                       Unresolved local var: VPANEL root@[???] */
  pFVar1 = (this->super_GripPanel)._frame;
  iVar7 = (*(pFVar1->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[0xa7])
                    (pFVar1);
  if ((char)iVar7 == '\0') {
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
  local_6c._vptr_IClientPanel = (_func_int_varargs **)(dy + (this->super_GripPanel)._dragOrgPos[1]);
  pIVar8 = vgui2::surface();
  newY = &local_34;
  (*(pIVar8->super_IBaseInterface)._vptr_IBaseInterface[0x51])
            (pIVar8,&local_3c,&local_38,newY,&local_30);
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: bool snapped@[???] */
  vgui2::Panel::GetSize((Panel *)(this->super_GripPanel)._frame,local_5c,(int *)local_4c);
  local_7c = local_3c;
  if ((0x12 < (iVar7 - local_3c) + 9U) &&
     (local_7c = iVar7, ((iVar7 + local_5c[0]) - (local_3c + (int)local_34._color)) + 9U < 0x13)) {
    local_7c = (local_3c + (int)local_34._color) - local_5c[0];
  }
  IVar13._vptr_IClientPanel = (_func_int_varargs **)local_38;
  if ((0x12 < (uint)((int)local_6c._vptr_IClientPanel + (9 - (int)local_38))) &&
     (iVar7 = (int)local_38->_dragStartPanelPos + (int)local_30._color + -0x2c,
     IVar13._vptr_IClientPanel = local_6c._vptr_IClientPanel,
     (int)local_6c._vptr_IClientPanel + (local_4c[0] - iVar7) + 9 < 0x13)) {
    IVar13._vptr_IClientPanel = (_func_int_varargs **)(iVar7 - local_4c[0]);
  }
  local_6c._vptr_IClientPanel = IVar13._vptr_IClientPanel;
  pIVar8 = vgui2::surface();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: VPANEL child@[???]
                       Unresolved local var: int cx@[???]
                       Unresolved local var: int cy@[???]
                       Unresolved local var: int cw@[???]
                       Unresolved local var: int ct@[???] */
  iVar7 = (*(pIVar8->super_IBaseInterface)._vptr_IBaseInterface[4])(pIVar8);
  local_98 = 0;
  do {
    while( true ) {
      pIVar9 = vgui2::ipanel();
      iVar10 = (**(code **)(*(int *)pIVar9 + 0x48))(pIVar9,iVar7);
      if (iVar10 <= local_98) {
        vgui2::Panel::SetPos
                  ((Panel *)(this->super_GripPanel)._frame,local_7c,(int)local_6c._vptr_IClientPanel
                  );
        return;
      }
      pIVar9 = vgui2::ipanel();
      VVar11 = (**(code **)(*(int *)pIVar9 + 0x4c))(pIVar9,iVar7,local_98);
      pFVar1 = (this->super_GripPanel)._frame;
      VVar12 = (**(pFVar1->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel)
                         (pFVar1);
      IVar13._vptr_IClientPanel = local_6c._vptr_IClientPanel;
      if (VVar11 == VVar12) goto LAB_00272013;
      pIVar9 = vgui2::ipanel();
      cVar6 = (**(code **)(*(int *)pIVar9 + 0x40))(pIVar9,VVar11);
      if (cVar6 != '\0') break;
LAB_00271fd1:
                    /* Unresolved local var: bool snapped@[DW_OP_breg4(ESP): +60]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int bottom@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: bool horizSnappable@[???]
                       Unresolved local var: bool vertSnappable@[???]
                       Unresolved local var: bool snapped@[???] */
      newX = (int *)0x0;
      while( true ) {
        pIVar9 = vgui2::ipanel();
        iVar10 = (**(code **)(*(int *)pIVar9 + 0x48))(pIVar9,VVar11);
        IVar13._vptr_IClientPanel = local_6c._vptr_IClientPanel;
        if (iVar10 <= (int)newX) break;
        pIVar9 = vgui2::ipanel();
        piVar16 = (int *)((int)newX + 1);
        VVar12 = VVar11;
        (**(code **)(*(int *)pIVar9 + 0x4c))(pIVar9);
        tryToDock((CaptionGripPanel *)&local_6c,VVar12,newX,(int *)newY);
        newX = piVar16;
      }
LAB_00272013:
      local_6c._vptr_IClientPanel = IVar13._vptr_IClientPanel;
      local_98 = local_98 + 1;
    }
    pIVar9 = vgui2::ipanel();
    cVar6 = (**(code **)(*(int *)pIVar9 + 0x60))(pIVar9,VVar11);
    if (cVar6 == '\0') goto LAB_00271fd1;
    pIVar9 = vgui2::ipanel();
    (**(code **)(*(int *)pIVar9 + 0x2c))(pIVar9,VVar11,&local_2c,&local_28);
    pIVar9 = vgui2::ipanel();
    newY = local_20;
    (**(code **)(*(int *)pIVar9 + 0x18))(pIVar9,VVar11,&local_24);
    pcVar5 = local_28;
    iVar10 = local_2c;
    IVar13._vptr_IClientPanel = (_func_int_varargs **)(local_28 + (int)local_20[0]._color);
    iVar15 = local_24 + local_2c;
    vgui2::Panel::GetSize((Panel *)(this->super_GripPanel)._frame,(int *)local_4c,local_5c);
    if (((int)pcVar5 < (int)local_6c._vptr_IClientPanel) &&
       (bVar3 = true, (int)local_6c._vptr_IClientPanel < (int)IVar13._vptr_IClientPanel)) {
      if (local_7c <= iVar10) goto LAB_002721c0;
LAB_00272106:
      bVar2 = true;
      if (iVar15 <= local_7c) goto LAB_002721c0;
    }
    else {
      iVar14 = local_5c[0] + (int)local_6c._vptr_IClientPanel;
      if (((iVar14 <= (int)pcVar5) || (bVar3 = true, (int)IVar13._vptr_IClientPanel <= iVar14)) &&
         (bVar3 = false, (int)local_6c._vptr_IClientPanel < (int)pcVar5)) {
        bVar3 = (int)IVar13._vptr_IClientPanel < iVar14;
      }
      if (iVar10 < local_7c) goto LAB_00272106;
LAB_002721c0:
      iVar14 = local_4c[0] + local_7c;
      if (((iVar14 <= iVar10) || (bVar2 = true, iVar15 <= iVar14)) &&
         (bVar2 = false, local_7c < iVar10)) {
        bVar2 = iVar15 < iVar14;
      }
    }
    if ((!bVar3) && (!bVar2)) goto LAB_00271fd1;
    if ((iVar15 + 10 < local_7c) || (local_7c < iVar15 + -10)) {
      bVar4 = false;
      if (((iVar10 + -10 <= (int)(local_7c + local_4c[0])) &&
          ((int)(local_7c + local_4c[0]) <= iVar10 + 10)) && (bVar3)) {
        bVar4 = true;
        local_7c = iVar10 - local_4c[0];
      }
    }
    else {
      bVar4 = false;
      if (bVar3) {
        bVar4 = true;
        local_7c = iVar15;
      }
    }
    if (((int)((int)&((BuildGroup *)IVar13._vptr_IClientPanel)->_snapX + 2) <
         (int)local_6c._vptr_IClientPanel) ||
       ((int)local_6c._vptr_IClientPanel <
        (int)((int)&(((BuildGroup *)((int)IVar13._vptr_IClientPanel + -0xcc))->
                    m_RegisteredControlSettingsFiles).m_Memory.m_GrowSize + 2))) {
      if (((int)(pcVar5 + 10) < (int)local_6c._vptr_IClientPanel + local_5c[0]) ||
         (((int)local_6c._vptr_IClientPanel + local_5c[0] < (int)(pcVar5 + -10) || (!bVar2))))
      goto LAB_002722a8;
      IVar13._vptr_IClientPanel = (_func_int_varargs **)(pcVar5 + -local_5c[0]);
      goto LAB_00272013;
    }
    if (bVar2) goto LAB_00272013;
LAB_002722a8:
    if (!bVar4) goto LAB_00271fd1;
    local_98 = local_98 + 1;
  } while( true );
}


// anon_unknown.dwarf_30150d::CaptionGripPanel::tryToDock  @ 002718b0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void tryToDock(CaptionGripPanel * this, VPANEL window, int * newX, int
   * newY) */

void __thiscall
anon_unknown.dwarf_30150d::CaptionGripPanel::tryToDock
          (CaptionGripPanel *this,VPANEL window,int *newX,int *newY)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int in_EAX;
  int iVar5;
  IPanel *pIVar6;
  VPANEL VVar7;
  VPANEL VVar8;
  _func_int_varargs **pp_Var9;
  int iVar10;
  int iVar11;
  int *in_ECX;
  int iVar12;
  int in_EDX;
  int iVar13;
  _func_int_varargs **pp_Var14;
  int *piVar15;
  int *newX_00;
  int *in_stack_ffffff70;
  int local_7c;
  int local_5c [4];
  int local_4c [4];
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
  iVar5 = (**(code **)**(undefined4 **)(in_EAX + 0x70))(*(undefined4 **)(in_EAX + 0x70));
  if (iVar5 == in_EDX) {
    return;
  }
  pIVar6 = vgui2::ipanel();
  cVar4 = (**(code **)(*(int *)pIVar6 + 0x40))(pIVar6,in_EDX);
  if (cVar4 != '\0') {
    pIVar6 = vgui2::ipanel();
    cVar4 = (**(code **)(*(int *)pIVar6 + 0x60))(pIVar6,in_EDX);
    if (cVar4 != '\0') {
                    /* Unresolved local var: bool snapped@[DW_OP_breg4(ESP): +48] */
      pIVar6 = vgui2::ipanel();
      (**(code **)(*(int *)pIVar6 + 0x2c))(pIVar6,in_EDX,&local_3c,&local_38);
      pIVar6 = vgui2::ipanel();
      in_stack_ffffff70 = &local_30;
      (**(code **)(*(int *)pIVar6 + 0x18))(pIVar6,in_EDX,&local_34);
                    /* Unresolved local var: bool snapped@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int bottom@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: bool horizSnappable@[???]
                       Unresolved local var: bool vertSnappable@[???] */
      pp_Var9 = (_func_int_varargs **)(local_30 + local_38);
      iVar5 = local_34 + local_3c;
      vgui2::Panel::GetSize(*(Panel **)(in_EAX + 0x70),local_5c,local_4c);
      pp_Var14 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
      if (((((int)pp_Var14 <= local_38) || (bVar1 = true, (int)pp_Var9 <= (int)pp_Var14)) &&
          ((iVar11 = local_4c[0] + (int)pp_Var14, iVar11 <= local_38 ||
           (bVar1 = true, (int)pp_Var9 <= iVar11)))) && (bVar1 = false, (int)pp_Var14 < local_38)) {
        bVar1 = (int)pp_Var9 < iVar11;
      }
      iVar11 = *in_ECX;
      if (((iVar11 <= local_3c) || (bVar2 = true, iVar5 <= iVar11)) &&
         (((iVar13 = local_5c[0] + iVar11, iVar13 <= local_3c || (bVar2 = true, iVar5 <= iVar13)) &&
          (bVar2 = false, iVar11 < local_3c)))) {
        bVar2 = iVar5 < iVar13;
      }
      if ((bVar1) || (bVar2)) {
        if ((iVar5 + 10 < iVar11) || (iVar11 < iVar5 + -10)) {
          bVar3 = false;
          if (((local_3c + -10 <= iVar11 + local_5c[0]) && (iVar11 + local_5c[0] <= local_3c + 10))
             && (bVar1)) {
            bVar3 = true;
            *in_ECX = local_3c - local_5c[0];
            pp_Var14 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
          }
        }
        else {
          bVar3 = false;
          if (bVar1) {
            bVar3 = true;
            *in_ECX = iVar5;
            pp_Var14 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
          }
        }
        if (((int)pp_Var9 + 10 < (int)pp_Var14) || ((int)pp_Var14 < (int)pp_Var9 + -10)) {
          if ((local_4c[0] + (int)pp_Var14 <= local_38 + 10) &&
             ((local_38 + -10 <= local_4c[0] + (int)pp_Var14 && (bVar2)))) {
            (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel =
                 (_func_int_varargs **)(local_38 - local_4c[0]);
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
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: VPANEL child@[???]
                       Unresolved local var: int cx@[???]
                       Unresolved local var: int cy@[???]
                       Unresolved local var: int cw@[???]
                       Unresolved local var: int ct@[???]
                       Unresolved local var: bool snapped@[DW_OP_breg4(ESP): +40]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int bottom@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: bool horizSnappable@[???]
                       Unresolved local var: bool vertSnappable@[???]
                       Unresolved local var: bool snapped@[???] */
  local_7c = 0;
  do {
    while( true ) {
      pIVar6 = vgui2::ipanel();
      iVar5 = (**(code **)(*(int *)pIVar6 + 0x48))(pIVar6,in_EDX);
      if (iVar5 <= local_7c) {
        return;
      }
      pIVar6 = vgui2::ipanel();
      VVar7 = (**(code **)(*(int *)pIVar6 + 0x4c))(pIVar6,in_EDX,local_7c);
      VVar8 = (**(code **)**(undefined4 **)(in_EAX + 0x70))(*(undefined4 **)(in_EAX + 0x70));
      if (VVar7 == VVar8) goto LAB_002719b3;
      pIVar6 = vgui2::ipanel();
      cVar4 = (**(code **)(*(int *)pIVar6 + 0x40))(pIVar6,VVar7);
      if (cVar4 != '\0') break;
LAB_00271971:
      newX_00 = (int *)0x0;
      while( true ) {
        pIVar6 = vgui2::ipanel();
        iVar5 = (**(code **)(*(int *)pIVar6 + 0x48))(pIVar6,VVar7);
        if (iVar5 <= (int)newX_00) break;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: VPANEL child@[???] */
        pIVar6 = vgui2::ipanel();
        piVar15 = (int *)((int)newX_00 + 1);
        VVar8 = VVar7;
        (**(code **)(*(int *)pIVar6 + 0x4c))(pIVar6);
        tryToDock(this,VVar8,newX_00,in_stack_ffffff70);
        newX_00 = piVar15;
      }
LAB_002719b3:
      local_7c = local_7c + 1;
    }
    pIVar6 = vgui2::ipanel();
    cVar4 = (**(code **)(*(int *)pIVar6 + 0x60))(pIVar6,VVar7);
    if (cVar4 == '\0') goto LAB_00271971;
    pIVar6 = vgui2::ipanel();
    (**(code **)(*(int *)pIVar6 + 0x2c))(pIVar6,VVar7,&local_2c,&local_28);
    pIVar6 = vgui2::ipanel();
    in_stack_ffffff70 = local_20;
    (**(code **)(*(int *)pIVar6 + 0x18))(pIVar6,VVar7,&local_24);
    iVar11 = local_28;
    iVar5 = local_2c;
    iVar13 = local_24 + local_2c;
    pp_Var9 = (_func_int_varargs **)(local_28 + local_20[0]);
    vgui2::Panel::GetSize(*(Panel **)(in_EAX + 0x70),local_4c,local_5c);
    pp_Var14 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
    if ((((iVar11 < (int)pp_Var14) && (bVar1 = true, (int)pp_Var14 < (int)pp_Var9)) ||
        ((iVar12 = local_5c[0] + (int)pp_Var14, iVar11 < iVar12 &&
         (bVar1 = true, iVar12 < (int)pp_Var9)))) || (bVar1 = false, iVar11 <= (int)pp_Var14)) {
      iVar10 = *in_ECX;
      if (iVar5 < iVar10) goto LAB_00271a7c;
LAB_00271b60:
      iVar12 = local_4c[0] + iVar10;
      if (((iVar12 <= iVar5) || (bVar2 = true, iVar13 <= iVar12)) && (bVar2 = false, iVar10 < iVar5)
         ) {
        bVar2 = iVar13 < iVar12;
      }
    }
    else {
      iVar10 = *in_ECX;
      bVar1 = (int)pp_Var9 < iVar12;
      if (iVar10 <= iVar5) goto LAB_00271b60;
LAB_00271a7c:
      bVar2 = true;
      if (iVar13 <= iVar10) goto LAB_00271b60;
    }
    if ((!bVar1) && (!bVar2)) goto LAB_00271971;
    if ((iVar13 + 10 < iVar10) || (iVar10 < iVar13 + -10)) {
      bVar3 = false;
      if (((iVar5 + -10 <= iVar10 + local_4c[0]) && (iVar10 + local_4c[0] <= iVar5 + 10)) && (bVar1)
         ) {
        bVar3 = true;
        *in_ECX = iVar5 - local_4c[0];
        pp_Var14 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
      }
    }
    else {
      bVar3 = false;
      if (bVar1) {
        bVar3 = true;
        *in_ECX = iVar13;
        pp_Var14 = (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel;
      }
    }
    if (((int)pp_Var9 + 10 < (int)pp_Var14) || ((int)pp_Var14 < (int)pp_Var9 + -10)) {
      if ((iVar11 + 10 < (int)pp_Var14 + local_5c[0]) ||
         (((int)pp_Var14 + local_5c[0] < iVar11 + -10 || (!bVar2)))) goto LAB_00271c28;
      (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel =
           (_func_int_varargs **)(iVar11 - local_5c[0]);
      goto LAB_002719b3;
    }
    if (bVar2) {
      (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel = pp_Var9;
      goto LAB_002719b3;
    }
LAB_00271c28:
    if (!bVar3) goto LAB_00271971;
    local_7c = local_7c + 1;
  } while( true );
}


// anon_unknown.dwarf_30150d::CaptionGripPanel::~CaptionGripPanel  @ 00271320
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void ~CaptionGripPanel(CaptionGripPanel * this, int __in_chrg) */

void __thiscall
anon_unknown.dwarf_30150d::CaptionGripPanel::~CaptionGripPanel(CaptionGripPanel *this,int __in_chrg)

{
  (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_0029f048;
  vgui2::Panel::~Panel((Panel *)this,__in_chrg);
  return;
}


// anon_unknown.dwarf_30150d::CaptionGripPanel::~CaptionGripPanel  @ 00271880
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void ~CaptionGripPanel(CaptionGripPanel * this, int __in_chrg) */

void __thiscall
anon_unknown.dwarf_30150d::CaptionGripPanel::~CaptionGripPanel(CaptionGripPanel *this,int __in_chrg)

{
  int in_stack_ffffffe8;
  
  (this->super_GripPanel).super_Panel.super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_0029f048;
  vgui2::Panel::~Panel((Panel *)this,in_stack_ffffffe8);
  operator_delete(this);
  return;
}


// anon_unknown.dwarf_30150d::GripPanel::ApplySchemeSettings  @ 00270540
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void ApplySchemeSettings(GripPanel * this, IScheme * pScheme) */

void __thiscall
anon_unknown.dwarf_30150d::GripPanel::ApplySchemeSettings(GripPanel *this,IScheme *pScheme)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20 [16];
  
  vgui2::Panel::ApplySchemeSettings(&this->super_Panel,pScheme);
  pp_Var1 = (this->super_Panel).super_IClientPanel._vptr_IClientPanel;
  p_Var2 = pp_Var1[0x35];
  (*pp_Var1[0x4e])(local_20,this,"BorderBright",pScheme);
  (*p_Var2)(this,local_24);
  pp_Var1 = (this->super_Panel).super_IClientPanel._vptr_IClientPanel;
  p_Var2 = pp_Var1[0x34];
  (*pp_Var1[0x4e])(local_20,this,"BorderSelection",pScheme);
  (*p_Var2)(this,local_28);
  return;
}


// anon_unknown.dwarf_30150d::GripPanel::OnCursorMoved  @ 00271330
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void OnCursorMoved(GripPanel * this, int x, int y) */

void __thiscall anon_unknown.dwarf_30150d::GripPanel::OnCursorMoved(GripPanel *this,int x,int y)

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
  (*(this->super_Panel).super_IClientPanel._vptr_IClientPanel[99])(this,0);
  return;
}


// anon_unknown.dwarf_30150d::GripPanel::OnMouseCaptureLost  @ 0026f8b0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void OnMouseCaptureLost(GripPanel * this) */

void __thiscall anon_unknown.dwarf_30150d::GripPanel::OnMouseCaptureLost(GripPanel *this)

{
  vgui2::Panel::OnMouseCaptureLost(&this->super_Panel);
  this->_dragging = false;
  return;
}


// anon_unknown.dwarf_30150d::GripPanel::OnMousePressed  @ 00271610
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void OnMousePressed(GripPanel * this, MouseCode code) */

void __thiscall anon_unknown.dwarf_30150d::GripPanel::OnMousePressed(GripPanel *this,MouseCode code)

{
  code *pcVar1;
  char cVar2;
  IInput *pIVar3;
  int iVar4;
  IPanel *pIVar5;
  int iVar6;
  int local_24;
  int local_20 [4];
  
  if (code != MOUSE_LEFT) {
    return;
  }
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: VPANEL focus@[???] */
  this->_dragging = true;
  pIVar3 = vgui2::input();
  (**(code **)(*(int *)pIVar3 + 0x20))(pIVar3,&local_24,local_20);
  this->_dragStart[0] = local_24;
  this->_dragStart[1] = local_20[0];
  vgui2::Panel::GetPos((Panel *)this->_frame,this->_dragOrgPos,this->_dragOrgPos + 1);
  vgui2::Panel::GetSize((Panel *)this->_frame,this->_dragOrgSize,this->_dragOrgSize + 1);
  pIVar3 = vgui2::input();
  pcVar1 = *(code **)(*(int *)pIVar3 + 0xc);
  iVar4 = (**(this->super_Panel).super_IClientPanel._vptr_IClientPanel)(this);
  (*pcVar1)(pIVar3,iVar4);
  pIVar3 = vgui2::input();
  iVar4 = (**(code **)(*(int *)pIVar3 + 0x14))(pIVar3);
  if (iVar4 != 0) {
    pIVar5 = vgui2::ipanel();
    pcVar1 = *(code **)(*(int *)pIVar5 + 0x5c);
    iVar6 = (**(this->_frame->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel
            )(this->_frame);
    cVar2 = (*pcVar1)(pIVar5,iVar4,iVar6);
    if (cVar2 != '\0') goto LAB_002716fb;
  }
  (*(this->_frame->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[0xc])
            (this->_frame,0);
LAB_002716fb:
  (*(this->_frame->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[4])
            (this->_frame);
  return;
}


// anon_unknown.dwarf_30150d::GripPanel::OnMouseReleased  @ 0026f950
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void OnMouseReleased(GripPanel * this, MouseCode code) */

void __thiscall
anon_unknown.dwarf_30150d::GripPanel::OnMouseReleased(GripPanel *this,MouseCode code)

{
  IInput *pIVar1;
  
  this->_dragging = false;
  pIVar1 = vgui2::input();
                    /* WARNING: Could not recover jumptable at 0x0026f972. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)pIVar1 + 0xc))();
  return;
}


// anon_unknown.dwarf_30150d::GripPanel::Paint  @ 0026f5c0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void Paint(GripPanel * this) */

void __thiscall anon_unknown.dwarf_30150d::GripPanel::Paint(GripPanel *this)

{
  if (this->m_pImage != (IImage *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0026f5d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**this->m_pImage->_vptr_IImage)();
    return;
  }
  return;
}


// anon_unknown.dwarf_30150d::GripPanel::PaintBackground  @ 0026f5f0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void PaintBackground(GripPanel * this) */

void __thiscall anon_unknown.dwarf_30150d::GripPanel::PaintBackground(GripPanel *this)

{
  if (this->m_pImage != (IImage *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0026f606. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**this->m_pImage->_vptr_IImage)();
    return;
  }
  return;
}


// anon_unknown.dwarf_30150d::GripPanel::moved  @ 00271740
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void moved(GripPanel * this, int dx, int dy) */

void __thiscall anon_unknown.dwarf_30150d::GripPanel::moved(GripPanel *this,int dx,int dy)

{
  int iVar1;
  int y;
  int iVar2;
  int x;
  int local_3c [4];
  int local_2c [7];
  
                    /* Unresolved local var: int newX@[???]
                       Unresolved local var: int newY@[???]
                       Unresolved local var: int newWide@[???]
                       Unresolved local var: int newTall@[???]
                       Unresolved local var: int minWide@[???]
                       Unresolved local var: int minTall@[???] */
  iVar1 = (*(this->_frame->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel
            [0xa9])(this->_frame);
  if ((char)iVar1 != '\0') {
                    /* Unresolved local var: int newX@[???]
                       Unresolved local var: int newY@[???]
                       Unresolved local var: int newWide@[???]
                       Unresolved local var: int newTall@[???]
                       Unresolved local var: int minWide@[???]
                       Unresolved local var: int minTall@[???] */
    iVar1 = this->_dragOrgSize[0];
    iVar2 = this->_dragOrgSize[1];
    x = this->_dragOrgPos[0];
    y = this->_dragOrgPos[1];
    vgui2::Panel::GetMinimumSize((Panel *)this->_frame,local_3c,local_2c);
    iVar1 = dx * this->_dragMultX + iVar1;
    if (this->_dragMultX == -1) {
      if (iVar1 < local_3c[0]) {
        dx = this->_dragOrgSize[0] - local_3c[0];
      }
      x = x + dx;
    }
    iVar2 = iVar2 + dy * this->_dragMultY;
    if (this->_dragMultY == -1) {
      if (iVar2 < local_2c[0]) {
        dy = this->_dragOrgSize[1] - local_2c[0];
      }
      y = y + dy;
    }
    vgui2::Panel::SetPos((Panel *)this->_frame,x,y);
    vgui2::Panel::SetSize((Panel *)this->_frame,iVar1,iVar2);
    (*(this->_frame->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[0x3b])
              (this->_frame,0,0);
    (*(this->_frame->super_EditablePanel).super_Panel.super_IClientPanel._vptr_IClientPanel[4])
              (this->_frame);
  }
  return;
}


// anon_unknown.dwarf_30150d::GripPanel::~GripPanel  @ 002712e0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void ~GripPanel(GripPanel * this, int __in_chrg) */

void __thiscall anon_unknown.dwarf_30150d::GripPanel::~GripPanel(GripPanel *this,int __in_chrg)

{
  (this->super_Panel).super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_0029f048;
  vgui2::Panel::~Panel(&this->super_Panel,__in_chrg);
  return;
}


// anon_unknown.dwarf_30150d::GripPanel::~GripPanel  @ 002712f0
/* WARNING: Struct "Button": ignoring multiple overlapping fields */
/* WARNING: Struct "MenuItem": ignoring overlapping field "m_RegisterClass" */
/* WARNING: Struct "MenuButton": ignoring overlapping field "m_RegisterClass" */
/* DWARF original prototype: void ~GripPanel(GripPanel * this, int __in_chrg) */

void __thiscall anon_unknown.dwarf_30150d::GripPanel::~GripPanel(GripPanel *this,int __in_chrg)

{
  int in_stack_ffffffe8;
  
  (this->super_Panel).super_IClientPanel._vptr_IClientPanel =
       (_func_int_varargs **)&PTR_GetVPanel_0029f048;
  vgui2::Panel::~Panel(&this->super_Panel,in_stack_ffffffe8);
  operator_delete(this);
  return;
}


