// Ghidra decompilation of functions from cl_dll/vgui_ConsolePanel.cpp
// 7 functions, ordered by original source line

// anon_unknown.dwarf_16061f::Handler::actionPerformed  @ 00087e60  (line 33)

/* DWARF original prototype: void actionPerformed(Handler * this, Panel * panel) */

void __thiscall anon_unknown.dwarf_16061f::Handler::actionPerformed(Handler *this,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x00087e6d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_consolePanel + 0x208))();
  return;
}


// ConsolePanel::ConsolePanel  @ 00087fc0  (line 42)

/* DWARF original prototype: void ConsolePanel(ConsolePanel * this, int x, int y, int wide, int
   tall) */

void __thiscall ConsolePanel::ConsolePanel(ConsolePanel *this,int x,int y,int wide,int tall)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  EtchedBorder *this_00;
  TextGrid *this_01;
  LoweredBorder *this_02;
  TextEntry *this_03;
  undefined4 *puVar2;
  
  vgui::Panel::Panel(&this->super_Panel,x,y,wide,tall);
  *(undefined ***)this = &PTR_setPos_000c4414;
  this_00 = operator_new(0x38);
  vgui::EtchedBorder::EtchedBorder(this_00);
  vgui::Panel::setBorder((Border *)this);
  this_01 = operator_new(0xe8);
  vgui::TextGrid::TextGrid(this_01,0x50,0x15,5,5,200,100);
  iVar1 = *(int *)this_01;
  this->_textGrid = this_01;
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0xd4);
  this_02 = operator_new(0x38);
  vgui::LoweredBorder::LoweredBorder(this_02);
  (*UNRECOVERED_JUMPTABLE)(this->_textGrid,this_02);
  (**(code **)(*(int *)this->_textGrid + 0x40))(this->_textGrid,this);
  this_03 = operator_new(0xf4);
  vgui::TextEntry::TextEntry(this_03,"",5,5,200,0x14);
  this->_textEntry = this_03;
  vgui::Panel::setParent((Panel *)this_03);
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)this->_textEntry + 0x238);
  puVar2 = operator_new(8);
  *puVar2 = &PTR_actionPerformed_000c4408;
  puVar2[1] = this;
                    /* WARNING: Could not recover jumptable at 0x00088139. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ConsolePanel::print  @ 00087e80  (line 56)

/* DWARF original prototype: int print(ConsolePanel * this, char * text) */

int __thiscall ConsolePanel::print(ConsolePanel *this,char *text)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)this->_textGrid + 0x20c))(this->_textGrid,&DAT_000c4b6e,text);
  return iVar1;
}


// ConsolePanel::vprintf  @ 00087eb0  (line 62)

/* DWARF original prototype: int vprintf(ConsolePanel * this, char * format, va_list argList) */

int __thiscall ConsolePanel::vprintf(ConsolePanel *this,char *format,va_list argList)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00087ec6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(*(int *)this->_textGrid + 0x208))();
  return iVar1;
}


// ConsolePanel::printf  @ 00087f60  (line 66)

/* DWARF original prototype: int printf(ConsolePanel * this, char * format, ...) */

int __thiscall ConsolePanel::printf(ConsolePanel *this,char *format,...)

{
  int iVar1;
  
                    /* Unresolved local var: va_list argList@[???]
                       Unresolved local var: int ret@[???] */
  if (*(code **)(*(int *)this + 0x200) == vprintf) {
    iVar1 = (**(code **)(*(int *)this->_textGrid + 0x208))(this->_textGrid,format,&stack0x0000000c);
    return iVar1;
  }
  iVar1 = (**(code **)(*(int *)this + 0x200))(this,format,&stack0x0000000c);
  return iVar1;
}


// ConsolePanel::doExecCommand  @ 00087ed0  (line 75)

/* DWARF original prototype: void doExecCommand(ConsolePanel * this) */

void __thiscall ConsolePanel::doExecCommand(ConsolePanel *this)

{
  int in_GS_OFFSET;
  char local_810 [2048];
  int local_10;
  
                    /* Unresolved local var: char[2048] buf@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  (**(code **)(*(int *)this->_textEntry + 0x200))(this->_textEntry,0,local_810,0x800);
  (**(code **)(*(int *)this->_textEntry + 0x1fc))(this->_textEntry,0,0);
  (*gEngfuncs.pfnClientCmd)(local_810);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ConsolePanel::setSize  @ 00088160  (line 83)

/* DWARF original prototype: void setSize(ConsolePanel * this, int wide, int tall) */

void __thiscall ConsolePanel::setSize(ConsolePanel *this,int wide,int tall)

{
  vgui::Panel::setSize((int)this,wide);
  (**(code **)(*(int *)this + 0xe8))(this,&wide,&tall);
  (**(code **)(*(int *)this->_textGrid + 0x10))(this->_textGrid,5,5,wide + -10,tall + -0x23);
  (**(code **)(*(int *)this->_textEntry + 0x10))(this->_textEntry,5,tall + -0x19,wide + -10,0x14);
  return;
}


