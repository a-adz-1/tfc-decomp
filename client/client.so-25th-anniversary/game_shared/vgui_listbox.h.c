// Ghidra decompilation of functions from game_shared/vgui_listbox.h
// 1 functions, ordered by original source line

// vgui::CListBox::ListBoxSignal::intChanged  @ 000a9170  (line 83)

/* DWARF original prototype: void intChanged(ListBoxSignal * this, int value, Panel * panel) */

void __thiscall
vgui::CListBox::ListBoxSignal::intChanged(ListBoxSignal *this,int value,Panel *panel)

{
  CListBox *this_00;
  int iVar1;
  
  this_00 = this->m_pListBox;
  if (*(code **)(*(int *)this_00 + 0x1fc) == setPixelScroll) {
    iVar1 = ScrollBar2::getValue(&this_00->m_ScrollBar);
    this_00->m_ItemOffset = iVar1;
    InternalLayout(this_00);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000a91be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this_00 + 0x1fc))();
  return;
}


