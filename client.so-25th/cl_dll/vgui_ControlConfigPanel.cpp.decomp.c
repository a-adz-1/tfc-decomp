// Ghidra decompilation of functions from cl_dll/vgui_ControlConfigPanel.cpp
// 11 functions, ordered by original source line

// anon_unknown.dwarf_161546::FooTablePanel::getRowCount  @ 00088210  (line 36)

/* DWARF original prototype: int getRowCount(FooTablePanel * this) */

int __thiscall anon_unknown.dwarf_161546::FooTablePanel::getRowCount(FooTablePanel *this)

{
  return (this->_controlConfigPanel->_cvarDar)._count;
}


// anon_unknown.dwarf_161546::FooTablePanel::getCellTall  @ 00088230  (line 43)

/* DWARF original prototype: int getCellTall(FooTablePanel * this, int row) */

int __thiscall anon_unknown.dwarf_161546::FooTablePanel::getCellTall(FooTablePanel *this,int row)

{
  return 0xc;
}


// anon_unknown.dwarf_161546::FooTablePanel::getCellRenderer  @ 00088290  (line 44)

/* DWARF original prototype: Panel * getCellRenderer(FooTablePanel * this, int column, int row, bool
   columnSelected, bool rowSelected, bool cellSelected) */

Panel * __thiscall
anon_unknown.dwarf_161546::FooTablePanel::getCellRenderer
          (FooTablePanel *this,int column,int row,bool columnSelected,bool rowSelected,
          bool cellSelected)

{
  ControlConfigPanel *pCVar1;
  Label *pLVar2;
  char *pcVar3;
  undefined1 *puVar4;
  int in_GS_OFFSET;
  undefined4 uVar5;
  char *in_stack_fffffdb0;
  vgui local_220 [128];
  vgui local_1a0 [128];
  undefined1 local_120 [128];
  undefined1 local_a0 [128];
  int local_20;
  
                    /* Unresolved local var: char[128] cvar@[???]
                       Unresolved local var: char[128] desc@[???]
                       Unresolved local var: char[128] bind@[???]
                       Unresolved local var: char[128] bindAlt@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (row < 0) {
    vgui::vgui_strcpy(local_220,(char *)0x80,0,in_stack_fffffdb0);
    pcVar3 = (char *)0x0;
  }
  else {
    pCVar1 = this->_controlConfigPanel;
    pcVar3 = (char *)0x0;
    if (row < (pCVar1->_cvarDar)._count) {
      pcVar3 = (pCVar1->_cvarDar)._data[row];
    }
    vgui::vgui_strcpy(local_220,(char *)0x80,(int)pcVar3,in_stack_fffffdb0);
    pcVar3 = (char *)0x0;
    if (row < (pCVar1->_descDar)._count) {
      pcVar3 = (pCVar1->_descDar)._data[row];
    }
  }
  vgui::vgui_strcpy(local_1a0,(char *)0x80,(int)pcVar3,in_stack_fffffdb0);
  pLVar2 = this->_label;
  if (cellSelected) {
    (**(code **)(*(int *)pLVar2 + 0x120))(pLVar2,3);
    (**(code **)(*(int *)this->_label + 0x11c))(this->_label,5);
    if (column == 1) goto LAB_0008844a;
LAB_0008838c:
    if (column != 2) {
      pLVar2 = this->_label;
      if (column == 0) {
        (**(code **)(*(int *)pLVar2 + 0x204))(pLVar2,local_1a0);
        (**(code **)(*(int *)this->_label + 0x21c))(this->_label,3);
      }
      else {
        (**(code **)(*(int *)pLVar2 + 0x204))(pLVar2,"");
      }
      goto LAB_000883c3;
    }
    puVar4 = local_a0;
    __sprintf_chk(local_120,1,0x80,"%s : Bind",local_220);
  }
  else {
    if (rowSelected) {
      uVar5 = 4;
    }
    else {
      uVar5 = 5;
    }
    (**(code **)(*(int *)pLVar2 + 0x120))(pLVar2,uVar5);
    (**(code **)(*(int *)this->_label + 0x11c))(this->_label,3);
    if (column != 1) goto LAB_0008838c;
LAB_0008844a:
    puVar4 = local_120;
    __sprintf_chk(puVar4,1,0x80,"%s : Bind",local_220);
  }
  __sprintf_chk(local_a0,1,0x80,"%s : BindAlt",local_220);
  (**(code **)(*(int *)this->_label + 0x204))(this->_label,puVar4);
  (**(code **)(*(int *)this->_label + 0x21c))(this->_label,4);
LAB_000883c3:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (Panel *)this->_label;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// anon_unknown.dwarf_161546::FooTablePanel::startCellEditing  @ 00088240  (line 97)

/* DWARF original prototype: Panel * startCellEditing(FooTablePanel * this, int column, int row) */

Panel * __thiscall
anon_unknown.dwarf_161546::FooTablePanel::startCellEditing(FooTablePanel *this,int column,int row)

{
  (**(code **)(*(int *)this->_textEntry + 0x1fc))(this->_textEntry,&DAT_000c4620,4);
  (**(code **)(*(int *)this->_textEntry + 0xa4))(this->_textEntry);
  return (Panel *)this->_textEntry;
}


// ControlConfigPanel::ControlConfigPanel  @ 000885a0  (line 106)

/* DWARF original prototype: void ControlConfigPanel(ControlConfigPanel * this, int x, int y, int
   wide, int tall) */

void __thiscall
ControlConfigPanel::ControlConfigPanel(ControlConfigPanel *this,int x,int y,int wide,int tall)

{
  char **ppcVar1;
  code *pcVar2;
  char **ppcVar3;
  Label *pLVar4;
  HeaderPanel *this_00;
  ScrollPanel *this_01;
  int *piVar5;
  int iVar6;
  TablePanel *this_02;
  TextEntry *this_03;
  undefined4 uVar7;
  int iVar8;
  int in_GS_OFFSET;
  bool bVar9;
  Color local_2c [12];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Panel::Panel(&this->super_Panel,x,y,wide,tall);
  (this->_cvarDar)._count = 0;
  (this->_cvarDar)._capacity = 0;
  *(undefined ***)this = &PTR_setPos_000c4964;
  (this->_cvarDar)._data = (char **)0x0;
                    /* Unresolved local var: int newCapacity@[???]
                       Unresolved local var: char * * newData@[???] */
  ppcVar3 = operator_new__(0x10);
  if (ppcVar3 != (char **)0x0) {
                    /* Unresolved local var: int i@[???] */
    iVar6 = (this->_cvarDar)._count;
    *ppcVar3 = (char *)0x0;
    ppcVar3[1] = (char *)0x0;
    ppcVar3[2] = (char *)0x0;
    ppcVar3[3] = (char *)0x0;
    (this->_cvarDar)._capacity = 4;
    if (0 < iVar6) {
      iVar6 = (this->_cvarDar)._count;
      iVar8 = 0;
      ppcVar1 = (this->_cvarDar)._data;
      do {
        ppcVar3[iVar8] = ppcVar1[iVar8];
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar6);
    }
    ppcVar1 = (this->_cvarDar)._data;
    if (ppcVar1 != (char **)0x0) {
      operator_delete__(ppcVar1);
    }
    (this->_cvarDar)._data = ppcVar3;
    (this->_descDar)._count = 0;
    (this->_descDar)._capacity = 0;
    (this->_descDar)._data = (char **)0x0;
                    /* Unresolved local var: int newCapacity@[???]
                       Unresolved local var: char * * newData@[???] */
    ppcVar3 = operator_new__(0x10);
    if (ppcVar3 != (char **)0x0) {
                    /* Unresolved local var: int i@[???] */
      iVar6 = (this->_descDar)._count;
      *ppcVar3 = (char *)0x0;
      ppcVar3[1] = (char *)0x0;
      ppcVar3[2] = (char *)0x0;
      ppcVar3[3] = (char *)0x0;
      (this->_descDar)._capacity = 4;
      if (0 < iVar6) {
        iVar6 = (this->_descDar)._count;
        iVar8 = 0;
        ppcVar1 = (this->_descDar)._data;
        do {
          ppcVar3[iVar8] = ppcVar1[iVar8];
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar6);
      }
      ppcVar1 = (this->_descDar)._data;
      if (ppcVar1 != (char **)0x0) {
        operator_delete__(ppcVar1);
      }
      (this->_descDar)._data = ppcVar3;
      bVar9 = SUB41(this,0);
      vgui::Panel::setPaintBorderEnabled(bVar9);
      vgui::Panel::setPaintBackgroundEnabled(bVar9);
      vgui::Panel::setPaintEnabled(bVar9);
      pLVar4 = operator_new(0xd0);
      vgui::Label::Label(pLVar4,"Action");
      this->_actionLabel = pLVar4;
      vgui::Panel::setBgColor((SchemeColor)pLVar4);
      (**(code **)(*(int *)this->_actionLabel + 0x11c))(this->_actionLabel,5);
      pLVar4 = operator_new(0xd0);
      vgui::Label::Label(pLVar4,"Key / Button");
      this->_keyButtonLabel = pLVar4;
      vgui::Panel::setBgColor((SchemeColor)pLVar4);
      (**(code **)(*(int *)this->_keyButtonLabel + 0x11c))(this->_keyButtonLabel,5);
      pLVar4 = operator_new(0xd0);
      vgui::Label::Label(pLVar4,"Alternate");
      this->_alternateLabel = pLVar4;
      vgui::Panel::setBgColor((SchemeColor)pLVar4);
      (**(code **)(*(int *)this->_alternateLabel + 0x11c))(this->_alternateLabel,5);
      this_00 = operator_new(0xf8);
      vgui::HeaderPanel::HeaderPanel(this_00,0,0,wide,0x14);
      this->_headerPanel = this_00;
      vgui::Panel::setParent((Panel *)this_00);
      (**(code **)(*(int *)this->_headerPanel + 0x1fc))(this->_headerPanel,this->_actionLabel);
      (**(code **)(*(int *)this->_headerPanel + 0x1fc))(this->_headerPanel,this->_keyButtonLabel);
      (**(code **)(*(int *)this->_headerPanel + 0x1fc))(this->_headerPanel,this->_alternateLabel);
      (**(code **)(*(int *)this->_headerPanel + 0x200))(this->_headerPanel,0,wide / 2);
      iVar6 = wide + 3;
      if (-1 < wide) {
        iVar6 = wide;
      }
      (**(code **)(*(int *)this->_headerPanel + 0x200))
                (this->_headerPanel,1,wide / 2 + (iVar6 >> 2));
      (**(code **)(*(int *)this->_headerPanel + 0x200))(this->_headerPanel,2,wide);
      this_01 = operator_new(0xd0);
      vgui::ScrollPanel::ScrollPanel(this_01,0,0x14,wide,tall + -0x14);
      this->_scrollPanel = this_01;
      vgui::Panel::setParent((Panel *)this_01);
      (**(code **)(*(int *)this->_scrollPanel + 0xd8))(this->_scrollPanel,0);
      (**(code **)(*(int *)this->_scrollPanel + 0xdc))(this->_scrollPanel,0);
      (**(code **)(*(int *)this->_scrollPanel + 0xe0))(this->_scrollPanel,0);
      piVar5 = (int *)(**(code **)(*(int *)this->_scrollPanel + 0x204))(this->_scrollPanel);
      (**(code **)(*piVar5 + 0xd8))(piVar5,0);
      piVar5 = (int *)(**(code **)(*(int *)this->_scrollPanel + 0x204))(this->_scrollPanel);
      (**(code **)(*piVar5 + 0xdc))(piVar5,0);
      piVar5 = (int *)(**(code **)(*(int *)this->_scrollPanel + 0x204))(this->_scrollPanel);
      (**(code **)(*piVar5 + 0xe0))(piVar5,0);
      (**(code **)(*(int *)this->_scrollPanel + 0x1fc))(this->_scrollPanel,0,1);
      piVar5 = (int *)(**(code **)(*(int *)this->_scrollPanel + 0x204))(this->_scrollPanel);
      iVar6 = (**(code **)(*piVar5 + 0x18))(piVar5);
      this_02 = operator_new(0x110);
      vgui::TablePanel::TablePanel(this_02,0,0,iVar6,800,3);
      *(undefined ***)this_02 = &PTR_setPos_000c470c;
      *(ControlConfigPanel **)(this_02 + 0x10c) = this;
      pLVar4 = operator_new(0xd0);
      vgui::Label::Label(pLVar4,"You are a dumb monkey",0,0,100,0x14);
      *(Label **)(this_02 + 0x104) = pLVar4;
      vgui::Panel::setBgColor((SchemeColor)pLVar4);
      (**(code **)(**(int **)(this_02 + 0x104) + 0x11c))(*(int **)(this_02 + 0x104),3);
      (**(code **)(**(int **)(this_02 + 0x104) + 0x208))(*(int **)(this_02 + 0x104),3);
      this_03 = operator_new(0xf4);
      vgui::TextEntry::TextEntry(this_03,"",0,0,100,0x14);
      iVar6 = *(int *)this_02;
      *(TextEntry **)(this_02 + 0x108) = this_03;
      this->_tablePanel = this_02;
      pcVar2 = *(code **)(iVar6 + 0x40);
      uVar7 = (**(code **)(*(int *)this->_scrollPanel + 0x204))(this->_scrollPanel);
      (*pcVar2)(this->_tablePanel,uVar7);
      (**(code **)(*(int *)this->_tablePanel + 0x21c))(this->_tablePanel,this->_headerPanel);
      pcVar2 = *(code **)(*(int *)this->_tablePanel + 0x134);
      vgui::Color::Color(local_2c,200,0,0,0xff);
      (*pcVar2)(this->_tablePanel,local_2c);
      pcVar2 = *(code **)(*(int *)this->_tablePanel + 0x138);
      vgui::Color::Color(local_2c,sc_primary2);
      (*pcVar2)(this->_tablePanel,local_2c);
      (**(code **)(*(int *)this->_tablePanel + 0x204))(this->_tablePanel,1,1);
      (**(code **)(*(int *)this->_tablePanel + 0x208))(this->_tablePanel,1,1);
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  exit(0);
}


// ControlConfigPanel::AddCVar  @ 00088cf0  (line 155)

/* WARNING: Removing unreachable block (ram,0x00088fa9) */
/* WARNING: Removing unreachable block (ram,0x00088f77) */
/* WARNING: Removing unreachable block (ram,0x00088f3a) */
/* WARNING: Removing unreachable block (ram,0x00088eee) */
/* DWARF original prototype: void AddCVar(ControlConfigPanel * this, char * cvar, char * desc) */

void __thiscall ControlConfigPanel::AddCVar(ControlConfigPanel *this,char *cvar,char *desc)

{
  char *pcVar1;
  char **ppcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char **ppcVar8;
  byte bVar9;
  char *in_stack_ffffffc8;
  
  bVar9 = 0;
  pcVar1 = (char *)vgui::vgui_strdup((vgui *)cvar,in_stack_ffffffc8);
  iVar4 = (this->_cvarDar)._count;
                    /* Unresolved local var: int newCapacity@[???]
                       Unresolved local var: char * * newData@[???] */
  uVar7 = (this->_cvarDar)._capacity;
  iVar3 = iVar4 + 1;
  if ((int)uVar7 < iVar3) {
    if (uVar7 == 0) {
      if (1 < iVar3) {
        uVar7 = 1;
        goto LAB_00088d40;
      }
      uVar6 = 4;
      uVar7 = 1;
    }
    else {
LAB_00088d40:
      do {
        uVar6 = uVar7;
        uVar7 = uVar6 * 2;
      } while ((int)uVar7 < iVar3);
      if (0x1fc00000 < uVar7) goto LAB_00089049;
      uVar6 = uVar6 * 8;
    }
    ppcVar2 = operator_new__(uVar6);
    if (ppcVar2 == (char **)0x0) goto LAB_0008903d;
    ppcVar8 = ppcVar2;
    if (uVar6 < 8) {
      if ((uVar6 & 4) == 0) goto LAB_00088d81;
      *ppcVar2 = (char *)0x0;
      ppcVar8 = ppcVar2 + 1;
    }
    else {
      uVar5 = uVar6;
      if (((uint)ppcVar2 & 1) != 0) {
        *(undefined1 *)ppcVar2 = 0;
        ppcVar8 = (char **)((int)ppcVar2 + 1);
        uVar5 = uVar6 - 1;
      }
      if (((uint)ppcVar8 & 2) != 0) {
        *(undefined2 *)ppcVar8 = 0;
        uVar5 = uVar5 - 2;
        ppcVar8 = (char **)((int)ppcVar8 + 2);
      }
      if (((uint)ppcVar8 & 4) != 0) {
        *ppcVar8 = (char *)0x0;
        uVar5 = uVar5 - 4;
        ppcVar8 = ppcVar8 + 1;
      }
      uVar6 = uVar5 & 3;
      for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *ppcVar8 = (char *)0x0;
        ppcVar8 = ppcVar8 + (uint)bVar9 * -2 + 1;
      }
LAB_00088d81:
      if ((uVar6 & 2) != 0) {
        *(undefined2 *)ppcVar8 = 0;
        ppcVar8 = (char **)((int)ppcVar8 + 2);
      }
    }
    if ((uVar6 & 1) != 0) {
      *(undefined1 *)ppcVar8 = 0;
    }
                    /* Unresolved local var: int i@[???] */
    iVar4 = (this->_cvarDar)._count;
    (this->_cvarDar)._capacity = uVar7;
    if (0 < iVar4) {
      ppcVar8 = (this->_cvarDar)._data;
      iVar3 = 0;
      do {
        ppcVar2[iVar3] = ppcVar8[iVar3];
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar4);
    }
    ppcVar8 = (this->_cvarDar)._data;
    if (ppcVar8 != (char **)0x0) {
      operator_delete__(ppcVar8);
      iVar4 = (this->_cvarDar)._count;
    }
    (this->_cvarDar)._data = ppcVar2;
  }
  else {
    ppcVar2 = (this->_cvarDar)._data;
  }
  ppcVar2[iVar4] = pcVar1;
  (this->_cvarDar)._count = (this->_cvarDar)._count + 1;
  pcVar1 = (char *)vgui::vgui_strdup((vgui *)desc,in_stack_ffffffc8);
  iVar4 = (this->_descDar)._count;
                    /* Unresolved local var: int newCapacity@[???]
                       Unresolved local var: char * * newData@[???] */
  uVar7 = (this->_descDar)._capacity;
  iVar3 = iVar4 + 1;
  if (iVar3 <= (int)uVar7) {
    ppcVar2 = (this->_descDar)._data;
    goto LAB_00088eba;
  }
  if (uVar7 == 0) {
    if (1 < iVar3) {
      uVar7 = 1;
      goto LAB_00088e30;
    }
    uVar6 = 4;
    uVar7 = 1;
  }
  else {
LAB_00088e30:
    do {
      uVar6 = uVar7;
      uVar7 = uVar6 * 2;
    } while ((int)uVar7 < iVar3);
    if (0x1fc00000 < uVar7) {
LAB_00089049:
      __cxa_throw_bad_array_new_length();
      return;
    }
    uVar6 = uVar6 * 8;
  }
  ppcVar2 = operator_new__(uVar6);
  if (ppcVar2 == (char **)0x0) {
LAB_0008903d:
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  ppcVar8 = ppcVar2;
  if (uVar6 < 8) {
    if ((uVar6 & 4) == 0) goto LAB_00088e6d;
    *ppcVar2 = (char *)0x0;
    ppcVar8 = ppcVar2 + 1;
  }
  else {
    uVar5 = uVar6;
    if (((uint)ppcVar2 & 1) != 0) {
      *(undefined1 *)ppcVar2 = 0;
      ppcVar8 = (char **)((int)ppcVar2 + 1);
      uVar5 = uVar6 - 1;
    }
    if (((uint)ppcVar8 & 2) != 0) {
      *(undefined2 *)ppcVar8 = 0;
      uVar5 = uVar5 - 2;
      ppcVar8 = (char **)((int)ppcVar8 + 2);
    }
    if (((uint)ppcVar8 & 4) != 0) {
      *ppcVar8 = (char *)0x0;
      uVar5 = uVar5 - 4;
      ppcVar8 = ppcVar8 + 1;
    }
    uVar6 = uVar5 & 3;
    for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *ppcVar8 = (char *)0x0;
      ppcVar8 = ppcVar8 + (uint)bVar9 * -2 + 1;
    }
LAB_00088e6d:
    if ((uVar6 & 2) != 0) {
      *(undefined2 *)ppcVar8 = 0;
      ppcVar8 = (char **)((int)ppcVar8 + 2);
    }
  }
  if ((uVar6 & 1) != 0) {
    *(undefined1 *)ppcVar8 = 0;
  }
                    /* Unresolved local var: int i@[???] */
  iVar4 = (this->_descDar)._count;
  (this->_descDar)._capacity = uVar7;
  if (0 < iVar4) {
    ppcVar8 = (this->_descDar)._data;
    iVar3 = 0;
    do {
      ppcVar2[iVar3] = ppcVar8[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  ppcVar8 = (this->_descDar)._data;
  if (ppcVar8 != (char **)0x0) {
    operator_delete__(ppcVar8);
    iVar4 = (this->_descDar)._count;
  }
  (this->_descDar)._data = ppcVar2;
LAB_00088eba:
  ppcVar2[iVar4] = pcVar1;
  (this->_descDar)._count = (this->_descDar)._count + 1;
  return;
}


// ControlConfigPanel::GetCVarCount  @ 00089050  (line 162)

/* DWARF original prototype: int GetCVarCount(ControlConfigPanel * this) */

int __thiscall ControlConfigPanel::GetCVarCount(ControlConfigPanel *this)

{
  return (this->_cvarDar)._count;
}


// ControlConfigPanel::GetCVar  @ 00089060  (line 166)

/* DWARF original prototype: void GetCVar(ControlConfigPanel * this, int index, char * cvar, int
   cvarLen, char * desc, int descLen) */

void __thiscall
ControlConfigPanel::GetCVar
          (ControlConfigPanel *this,int index,char *cvar,int cvarLen,char *desc,int descLen)

{
  char *pcVar1;
  char *in_stack_ffffffe0;
  
  if (index < 0) {
    vgui::vgui_strcpy((vgui *)cvar,(char *)cvarLen,0,in_stack_ffffffe0);
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = (char *)0x0;
    if (index < (this->_cvarDar)._count) {
      pcVar1 = (this->_cvarDar)._data[index];
    }
    vgui::vgui_strcpy((vgui *)cvar,(char *)cvarLen,(int)pcVar1,in_stack_ffffffe0);
    pcVar1 = (char *)0x0;
    if (index < (this->_descDar)._count) {
      pcVar1 = (this->_descDar)._data[index];
    }
  }
  vgui::vgui_strcpy((vgui *)desc,(char *)descLen,(int)pcVar1,(char *)cvarLen);
  return;
}


// ControlConfigPanel::AddCVarFromInputStream  @ 000891a0  (line 172)

/* WARNING: Removing unreachable block (ram,0x000894f7) */
/* WARNING: Removing unreachable block (ram,0x00089529) */
/* WARNING: Removing unreachable block (ram,0x000894ba) */
/* WARNING: Removing unreachable block (ram,0x0008947a) */
/* DWARF original prototype: void AddCVarFromInputStream(ControlConfigPanel * this, InputStream *
   is) */

void __thiscall ControlConfigPanel::AddCVarFromInputStream(ControlConfigPanel *this,InputStream *is)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char **ppcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char **ppcVar9;
  int in_GS_OFFSET;
  byte bVar10;
  undefined1 auStack_260 [4];
  undefined1 auStack_25c [12];
  undefined4 uStack_250;
  char *pcVar11;
  char local_229;
  DataInputStream local_228 [8];
  vgui local_220 [128];
  vgui local_1a0 [128];
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: DataInputStream dis@[???]
                       Unresolved local var: bool success@[???] */
  bVar10 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (is != (InputStream *)0x0) {
    uStack_250 = 0x891e0;
    vgui::DataInputStream::DataInputStream(local_228,is);
    while( true ) {
                    /* Unresolved local var: char[256] buf@[???]
                       Unresolved local var: char[128] cvar@[???]
                       Unresolved local var: char[128] desc@[???] */
      uStack_250 = 0x89208;
      vgui::DataInputStream::readLine((char *)local_228,(int)local_120,(bool *)0x100);
      if (local_229 == '\0') break;
      pcVar11 = "\"%[^\"]\" \"%[^\"]\"";
      uStack_250 = 0x8923e;
      iVar2 = sscanf(local_120,"\"%[^\"]\" \"%[^\"]\"");
      if (iVar2 == 2) {
        uStack_250 = 0x8924f;
        pcVar3 = (char *)vgui::vgui_strdup(local_220,pcVar11);
        iVar5 = (this->_cvarDar)._count;
                    /* Unresolved local var: int newCapacity@[???]
                       Unresolved local var: char * * newData@[???] */
        uVar8 = (this->_cvarDar)._capacity;
        iVar2 = iVar5 + 1;
        if ((int)uVar8 < iVar2) {
          if (uVar8 == 0) {
            if (1 < iVar2) {
              uVar8 = 1;
              goto LAB_00089280;
            }
            uVar7 = 4;
            uVar8 = 1;
          }
          else {
LAB_00089280:
            do {
              uVar7 = uVar8;
              uVar8 = uVar7 * 2;
            } while ((int)uVar8 < iVar2);
            if (0x1fc00000 < uVar8) goto LAB_000895d4;
            uVar7 = uVar7 * 8;
          }
          uStack_250 = 0x892a1;
          ppcVar4 = operator_new__(uVar7);
          if (ppcVar4 == (char **)0x0) goto LAB_000895c8;
          ppcVar9 = ppcVar4;
          if (uVar7 < 8) {
            if ((uVar7 & 4) == 0) goto LAB_000892c1;
            *ppcVar4 = (char *)0x0;
            ppcVar9 = ppcVar4 + 1;
          }
          else {
            uVar6 = uVar7;
            if (((uint)ppcVar4 & 1) != 0) {
              *(undefined1 *)ppcVar4 = 0;
              ppcVar9 = (char **)((int)ppcVar4 + 1);
              uVar6 = uVar7 - 1;
            }
            if (((uint)ppcVar9 & 2) != 0) {
              *(undefined2 *)ppcVar9 = 0;
              uVar6 = uVar6 - 2;
              ppcVar9 = (char **)((int)ppcVar9 + 2);
            }
            if (((uint)ppcVar9 & 4) != 0) {
              *ppcVar9 = (char *)0x0;
              uVar6 = uVar6 - 4;
              ppcVar9 = ppcVar9 + 1;
            }
            uVar7 = uVar6 & 3;
            for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *ppcVar9 = (char *)0x0;
              ppcVar9 = ppcVar9 + (uint)bVar10 * -2 + 1;
            }
LAB_000892c1:
            if ((uVar7 & 2) != 0) {
              *(undefined2 *)ppcVar9 = 0;
              ppcVar9 = (char **)((int)ppcVar9 + 2);
            }
          }
          if ((uVar7 & 1) != 0) {
            *(undefined1 *)ppcVar9 = 0;
          }
                    /* Unresolved local var: int i@[???] */
          iVar5 = (this->_cvarDar)._count;
          (this->_cvarDar)._capacity = uVar8;
          if (0 < iVar5) {
            ppcVar9 = (this->_cvarDar)._data;
            iVar2 = 0;
            do {
              ppcVar4[iVar2] = ppcVar9[iVar2];
              iVar2 = iVar2 + 1;
            } while (iVar2 < iVar5);
          }
          ppcVar9 = (this->_cvarDar)._data;
          if (ppcVar9 != (char **)0x0) {
            uStack_250 = 0x8930d;
            operator_delete__(ppcVar9);
            iVar5 = (this->_cvarDar)._count;
          }
          (this->_cvarDar)._data = ppcVar4;
        }
        else {
          ppcVar4 = (this->_cvarDar)._data;
        }
        ppcVar4[iVar5] = pcVar3;
        (this->_cvarDar)._count = (this->_cvarDar)._count + 1;
        uStack_250 = 0x89335;
        pcVar3 = (char *)vgui::vgui_strdup(local_1a0,pcVar11);
        iVar5 = (this->_descDar)._count;
                    /* Unresolved local var: int newCapacity@[???]
                       Unresolved local var: char * * newData@[???] */
        uVar8 = (this->_descDar)._capacity;
        iVar2 = iVar5 + 1;
        if ((int)uVar8 < iVar2) {
          if (uVar8 == 0) {
            if (1 < iVar2) {
              uVar8 = 1;
              goto LAB_00089370;
            }
            uVar7 = 4;
            uVar8 = 1;
          }
          else {
LAB_00089370:
            do {
              uVar7 = uVar8;
              uVar8 = uVar7 * 2;
            } while ((int)uVar8 < iVar2);
            if (0x1fc00000 < uVar8) {
LAB_000895d4:
              uStack_250 = 0x895d9;
              __cxa_throw_bad_array_new_length();
              piVar1 = *(int **)(pcVar11 + 0xd0);
              if (piVar1 == (int *)0x0) {
                return;
              }
              (**(code **)(*piVar1 + 8))(piVar1,auStack_260,auStack_25c);
              return;
            }
            uVar7 = uVar7 * 8;
          }
          uStack_250 = 0x89391;
          ppcVar4 = operator_new__(uVar7);
          if (ppcVar4 == (char **)0x0) {
LAB_000895c8:
                    /* WARNING: Subroutine does not return */
            uStack_250 = 0x895d4;
            exit(0);
          }
          ppcVar9 = ppcVar4;
          if (uVar7 < 8) {
            if ((uVar7 & 4) == 0) goto LAB_000893b1;
            *ppcVar4 = (char *)0x0;
            ppcVar9 = ppcVar4 + 1;
          }
          else {
            uVar6 = uVar7;
            if (((uint)ppcVar4 & 1) != 0) {
              *(undefined1 *)ppcVar4 = 0;
              ppcVar9 = (char **)((int)ppcVar4 + 1);
              uVar6 = uVar7 - 1;
            }
            if (((uint)ppcVar9 & 2) != 0) {
              *(undefined2 *)ppcVar9 = 0;
              uVar6 = uVar6 - 2;
              ppcVar9 = (char **)((int)ppcVar9 + 2);
            }
            if (((uint)ppcVar9 & 4) != 0) {
              *ppcVar9 = (char *)0x0;
              uVar6 = uVar6 - 4;
              ppcVar9 = ppcVar9 + 1;
            }
            uVar7 = uVar6 & 3;
            for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *ppcVar9 = (char *)0x0;
              ppcVar9 = ppcVar9 + (uint)bVar10 * -2 + 1;
            }
LAB_000893b1:
            if ((uVar7 & 2) != 0) {
              *(undefined2 *)ppcVar9 = 0;
              ppcVar9 = (char **)((int)ppcVar9 + 2);
            }
          }
          if ((uVar7 & 1) != 0) {
            *(undefined1 *)ppcVar9 = 0;
          }
                    /* Unresolved local var: int i@[???] */
          iVar5 = (this->_descDar)._count;
          (this->_descDar)._capacity = uVar8;
          if (0 < iVar5) {
            ppcVar9 = (this->_descDar)._data;
            iVar2 = 0;
            do {
              ppcVar4[iVar2] = ppcVar9[iVar2];
              iVar2 = iVar2 + 1;
            } while (iVar2 < iVar5);
          }
          ppcVar9 = (this->_descDar)._data;
          if (ppcVar9 != (char **)0x0) {
            uStack_250 = 0x893fd;
            operator_delete__(ppcVar9);
            iVar5 = (this->_descDar)._count;
          }
          (this->_descDar)._data = ppcVar4;
        }
        else {
          ppcVar4 = (this->_descDar)._data;
        }
        ppcVar4[iVar5] = pcVar3;
        (this->_descDar)._count = (this->_descDar)._count + 1;
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    uStack_250 = 0x895c8;
    __stack_chk_fail();
  }
  return;
}


// ControlConfigPanel::GetCVarBind  @ 00089110  (line 198)

/* DWARF original prototype: void GetCVarBind(ControlConfigPanel * this, char * cvar, char * bind,
   int bindLen, char * bindAlt, int bindAltLen) */

void __thiscall
ControlConfigPanel::GetCVarBind
          (ControlConfigPanel *this,char *cvar,char *bind,int bindLen,char *bindAlt,int bindAltLen)

{
  __sprintf_chk(bind,1,0xffffffff,"%s : Bind",cvar);
  __sprintf_chk();
  return;
}


// ControlConfigPanel::SetCVarBind  @ 00089190  (line 204)

/* DWARF original prototype: void SetCVarBind(ControlConfigPanel * this, char * cvar, char * bind,
   char * bindAlt) */

void __thiscall
ControlConfigPanel::SetCVarBind(ControlConfigPanel *this,char *cvar,char *bind,char *bindAlt)

{
  return;
}


