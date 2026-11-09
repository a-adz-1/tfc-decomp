// anon_unknown.dwarf_140ae9::Handler::actionPerformed  @ 000ada90
/* DWARF original prototype: void actionPerformed(Handler * this, Panel * panel) */

void __thiscall anon_unknown.dwarf_140ae9::Handler::actionPerformed(Handler *this,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x000adaa3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_consolePanel + 0x208))();
  return;
}


// anon_unknown.dwarf_141b59::FooTablePanel::getCellRenderer  @ 000ade60
/* DWARF original prototype: Panel * getCellRenderer(FooTablePanel * this, int column, int row, bool
   columnSelected, bool rowSelected, bool cellSelected) */

Panel * __thiscall
anon_unknown.dwarf_141b59::FooTablePanel::getCellRenderer
          (FooTablePanel *this,int column,int row,bool columnSelected,bool rowSelected,
          bool cellSelected)

{
  ControlConfigPanel *pCVar1;
  Label *pLVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *in_stack_fffffdd0;
  vgui local_21c [128];
  vgui local_19c [128];
  char local_11c [128];
  char local_9c [140];
  
                    /* Unresolved local var: char[128] cvar@[???]
                       Unresolved local var: char[128] desc@[???]
                       Unresolved local var: char[128] bind@[???]
                       Unresolved local var: char[128] bindAlt@[???] */
  pCVar1 = this->_controlConfigPanel;
  if (row < 0) {
    vgui::vgui_strcpy(local_21c,(char *)0x80,0,in_stack_fffffdd0);
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = (char *)0x0;
    if (row < (pCVar1->_cvarDar)._count) {
      pcVar3 = (pCVar1->_cvarDar)._data[row];
    }
    vgui::vgui_strcpy(local_21c,(char *)0x80,(int)pcVar3,in_stack_fffffdd0);
    pcVar3 = (char *)0x0;
    if (row < (pCVar1->_descDar)._count) {
      pcVar3 = (pCVar1->_descDar)._data[row];
    }
  }
  vgui::vgui_strcpy(local_19c,(char *)0x80,(int)pcVar3,in_stack_fffffdd0);
  pLVar2 = this->_label;
  if (cellSelected) {
    (**(code **)(*(int *)pLVar2 + 0x120))(pLVar2,3);
    (**(code **)(*(int *)this->_label + 0x11c))(this->_label,5);
    if (column == 1) goto LAB_000ae00a;
LAB_000adf4d:
    if (column != 2) {
      pLVar2 = this->_label;
      if (column == 0) {
        (**(code **)(*(int *)pLVar2 + 0x204))(pLVar2,local_19c);
        (**(code **)(*(int *)this->_label + 0x21c))(this->_label,3);
      }
      else {
        (**(code **)(*(int *)pLVar2 + 0x204))(pLVar2,"");
      }
      goto LAB_000adf99;
    }
    pcVar3 = local_9c;
    sprintf(local_11c,"%s : Bind",local_21c);
  }
  else {
    if (rowSelected) {
      uVar4 = 4;
    }
    else {
      uVar4 = 5;
    }
    (**(code **)(*(int *)pLVar2 + 0x120))(pLVar2,uVar4);
    (**(code **)(*(int *)this->_label + 0x11c))(this->_label,3);
    if (column != 1) goto LAB_000adf4d;
LAB_000ae00a:
    pcVar3 = local_11c;
    sprintf(pcVar3,"%s : Bind",local_21c);
  }
  sprintf(local_9c,"%s : BindAlt",local_21c);
  (**(code **)(*(int *)this->_label + 0x204))(this->_label,pcVar3);
  (**(code **)(*(int *)this->_label + 0x21c))(this->_label,4);
LAB_000adf99:
  return (Panel *)this->_label;
}


// anon_unknown.dwarf_141b59::FooTablePanel::getCellTall  @ 000ade00
/* DWARF original prototype: int getCellTall(FooTablePanel * this, int row) */

int __thiscall anon_unknown.dwarf_141b59::FooTablePanel::getCellTall(FooTablePanel *this,int row)

{
  return 0xc;
}


// anon_unknown.dwarf_141b59::FooTablePanel::getRowCount  @ 000adde0
/* DWARF original prototype: int getRowCount(FooTablePanel * this) */

int __thiscall anon_unknown.dwarf_141b59::FooTablePanel::getRowCount(FooTablePanel *this)

{
  return (this->_controlConfigPanel->_cvarDar)._count;
}


// anon_unknown.dwarf_141b59::FooTablePanel::startCellEditing  @ 000ade10
/* DWARF original prototype: Panel * startCellEditing(FooTablePanel * this, int column, int row) */

Panel * __thiscall
anon_unknown.dwarf_141b59::FooTablePanel::startCellEditing(FooTablePanel *this,int column,int row)

{
  (**(code **)(*(int *)this->_textEntry + 0x1fc))(this->_textEntry,&DAT_000e7509,4);
  (**(code **)(*(int *)this->_textEntry + 0xa4))(this->_textEntry);
  return (Panel *)this->_textEntry;
}


// anon_unknown.dwarf_1672f3::CBrowser_InputSignal::cursorEntered  @ 000b6db0
/* DWARF original prototype: void cursorEntered(CBrowser_InputSignal * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1672f3::CBrowser_InputSignal::cursorEntered
          (CBrowser_InputSignal *this,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1672f3::CBrowser_InputSignal::cursorExited  @ 000b6dc0
/* DWARF original prototype: void cursorExited(CBrowser_InputSignal * this, Panel * Panel) */

void __thiscall
anon_unknown.dwarf_1672f3::CBrowser_InputSignal::cursorExited
          (CBrowser_InputSignal *this,Panel *Panel)

{
  return;
}


// anon_unknown.dwarf_1672f3::CBrowser_InputSignal::cursorMoved  @ 000b6da0
/* DWARF original prototype: void cursorMoved(CBrowser_InputSignal * this, int x, int y, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1672f3::CBrowser_InputSignal::cursorMoved
          (CBrowser_InputSignal *this,int x,int y,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1672f3::CBrowser_InputSignal::keyFocusTicked  @ 000b6e20
/* DWARF original prototype: void keyFocusTicked(CBrowser_InputSignal * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1672f3::CBrowser_InputSignal::keyFocusTicked
          (CBrowser_InputSignal *this,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1672f3::CBrowser_InputSignal::keyPressed  @ 000b6df0
/* DWARF original prototype: void keyPressed(CBrowser_InputSignal * this, KeyCode code, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1672f3::CBrowser_InputSignal::keyPressed
          (CBrowser_InputSignal *this,KeyCode code,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1672f3::CBrowser_InputSignal::keyReleased  @ 000b6e10
/* DWARF original prototype: void keyReleased(CBrowser_InputSignal * this, KeyCode code, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1672f3::CBrowser_InputSignal::keyReleased
          (CBrowser_InputSignal *this,KeyCode code,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1672f3::CBrowser_InputSignal::keyTyped  @ 000b6e00
/* DWARF original prototype: void keyTyped(CBrowser_InputSignal * this, KeyCode code, Panel * panel)
    */

void __thiscall
anon_unknown.dwarf_1672f3::CBrowser_InputSignal::keyTyped
          (CBrowser_InputSignal *this,KeyCode code,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1672f3::CBrowser_InputSignal::mouseDoublePressed  @ 000b7440
/* DWARF original prototype: void mouseDoublePressed(CBrowser_InputSignal * this, MouseCode code,
   Panel * panel) */

void __thiscall
anon_unknown.dwarf_1672f3::CBrowser_InputSignal::mouseDoublePressed
          (CBrowser_InputSignal *this,MouseCode code,Panel *panel)

{
  int *piVar1;
  char *pcVar2;
  char local_124 [256];
  undefined1 local_24 [4];
  int local_20 [4];
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int therow@[???] */
  if (code == MOUSE_LEFT) {
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int therow@[???] */
    piVar1 = (int *)(**(code **)(*(int *)panel + 0x14c))(panel);
    (**(code **)(*piVar1 + 0x34))(piVar1,local_24,local_20);
    (**(code **)(*(int *)panel + 0x8c))(panel,local_24,local_20);
    this->m_pBrowser->m_nMouseOverRow =
         (int)((float)local_20[0] / (((float)gHUD.m_scrinfo.iHeight / 480.0) * 15.0));
                    /* Unresolved local var: char * info@[???]
                       Unresolved local var: char * address@[???]
                       Unresolved local var: char[256] sz@[???] */
    pcVar2 = ServersGetInfo(this->m_pBrowser->m_nMouseOverRow);
    if (pcVar2 != (char *)0x0) {
      pcVar2 = (*(gEngfuncs.pNetAPI)->ValueForKey)(pcVar2,"address");
      sprintf(local_124,"connect %s\n",pcVar2);
      (*gEngfuncs.pfnClientCmd)(local_124);
      (*gEngfuncs.pfnClientCmd)("togglebrowser\n");
    }
  }
  return;
}


// anon_unknown.dwarf_1672f3::CBrowser_InputSignal::mousePressed  @ 000b73b0
/* DWARF original prototype: void mousePressed(CBrowser_InputSignal * this, MouseCode code, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1672f3::CBrowser_InputSignal::mousePressed
          (CBrowser_InputSignal *this,MouseCode code,Panel *panel)

{
  int *piVar1;
  undefined1 local_14 [4];
  int local_10;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int therow@[???] */
  if (code == MOUSE_LEFT) {
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int therow@[???] */
    piVar1 = (int *)(**(code **)(*(int *)panel + 0x14c))(panel);
    (**(code **)(*piVar1 + 0x34))(piVar1,local_14,&local_10);
    (**(code **)(*(int *)panel + 0x8c))(panel,local_14,&local_10);
    this->m_pBrowser->m_nMouseOverRow =
         (int)((float)local_10 / (((float)gHUD.m_scrinfo.iHeight / 480.0) * 15.0));
  }
  return;
}


// anon_unknown.dwarf_1672f3::CBrowser_InputSignal::mouseReleased  @ 000b6dd0
/* DWARF original prototype: void mouseReleased(CBrowser_InputSignal * this, MouseCode code, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1672f3::CBrowser_InputSignal::mouseReleased
          (CBrowser_InputSignal *this,MouseCode code,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1672f3::CBrowser_InputSignal::mouseWheeled  @ 000b6de0
/* DWARF original prototype: void mouseWheeled(CBrowser_InputSignal * this, int delta, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1672f3::CBrowser_InputSignal::mouseWheeled
          (CBrowser_InputSignal *this,int delta,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1672f3::CancelHandler::actionPerformed  @ 000b6ee0
/* DWARF original prototype: void actionPerformed(CancelHandler * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1672f3::CancelHandler::actionPerformed(CancelHandler *this,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x000b6eee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.pfnClientCmd)("togglebrowser\n");
  return;
}


// anon_unknown.dwarf_1672f3::ConnectHandler::actionPerformed  @ 000b7570
/* DWARF original prototype: void actionPerformed(ConnectHandler * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1672f3::ConnectHandler::actionPerformed(ConnectHandler *this,Panel *panel)

{
  char *pcVar1;
  char local_10c [264];
  
                    /* Unresolved local var: char * info@[???]
                       Unresolved local var: char * address@[???]
                       Unresolved local var: char[256] sz@[???] */
  pcVar1 = ServersGetInfo(this->m_pBrowser->m_nMouseOverRow);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = (*(gEngfuncs.pNetAPI)->ValueForKey)(pcVar1,"address");
    sprintf(local_10c,"connect %s\n",pcVar1);
    (*gEngfuncs.pfnClientCmd)(local_10c);
    (*gEngfuncs.pfnClientCmd)("togglebrowser\n");
  }
  return;
}


// anon_unknown.dwarf_1672f3::RefreshHandler::actionPerformed  @ 000b7380
/* DWARF original prototype: void actionPerformed(RefreshHandler * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1672f3::RefreshHandler::actionPerformed(RefreshHandler *this,Panel *panel)

{
  ServersList();
  BroadcastServersList(0);
  return;
}


// anon_unknown.dwarf_1672f3::ServerBrowserTablePanel::getCellRenderer  @ 000b70f0
/* DWARF original prototype: Panel * getCellRenderer(ServerBrowserTablePanel * this, int column, int
   row, bool columnSelected, bool rowSelected, bool cellSelected) */

Panel * __thiscall
anon_unknown.dwarf_1672f3::ServerBrowserTablePanel::getCellRenderer
          (ServerBrowserTablePanel *this,int column,int row,bool columnSelected,bool rowSelected,
          bool cellSelected)

{
  Label *pLVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char local_3c [31];
  undefined1 local_1d;
  
                    /* Unresolved local var: char * info@[???]
                       Unresolved local var: char * val@[???]
                       Unresolved local var: char * val2@[???]
                       Unresolved local var: char[32] sz@[???] */
  pcVar2 = ServersGetInfo(row);
  pLVar1 = this->m_pLabel;
  if (this->m_nMouseOverRow == row) {
    (**(code **)(*(int *)pLVar1 + 0x124))(pLVar1,200,0xf0,0x3f,100);
  }
  else {
    (**(code **)(*(int *)pLVar1 + 0x124))(pLVar1,0xff,0xff,0xff,0);
  }
  (**(code **)(*(int *)this->m_pLabel + 0x128))(this->m_pLabel,0,0,0,200);
  (**(code **)(*(int *)this->m_pLabel + 0x21c))(this->m_pLabel,3);
  (**(code **)(*(int *)this->m_pLabel + 0x208))(this->m_pLabel,2);
  if (pcVar2 == (char *)0x0) {
    if (row == 0 && column == 0) {
      iVar3 = ServersIsQuerying();
      pLVar1 = this->m_pLabel;
      if (iVar3 == 0) {
        (**(code **)(*(int *)pLVar1 + 0x204))(pLVar1,"Press \'Refresh\' to search for servers...");
      }
      else {
        (**(code **)(*(int *)pLVar1 + 0x204))(pLVar1,"Waiting for servers to respond...");
      }
    }
    else {
      (**(code **)(*(int *)this->m_pLabel + 0x204))(this->m_pLabel,"");
    }
    goto switchD_000b71e0_default;
  }
  switch(column) {
  case 0:
    pcVar4 = "address";
    break;
  case 1:
    pcVar4 = "hostname";
    break;
  case 2:
    pcVar4 = "map";
    break;
  case 3:
    pcVar4 = (*(gEngfuncs.pNetAPI)->ValueForKey)(pcVar2,"current");
    pcVar2 = (*(gEngfuncs.pNetAPI)->ValueForKey)(pcVar2,"max");
    if ((pcVar2 == (char *)0x0) || (pcVar4 == (char *)0x0)) goto switchD_000b71e0_default;
    sprintf(local_3c,"%s/%s",pcVar4,pcVar2);
    goto LAB_000b72bd;
  case 4:
    pcVar4 = "ping";
    break;
  default:
    goto switchD_000b71e0_default;
  }
  pcVar2 = (*(gEngfuncs.pNetAPI)->ValueForKey)(pcVar2,pcVar4);
  if (pcVar2 != (char *)0x0) {
    strncpy(local_3c,pcVar2,0x1f);
LAB_000b72bd:
    local_1d = 0;
    (**(code **)(*(int *)this->m_pLabel + 0x204))(this->m_pLabel,local_3c);
  }
switchD_000b71e0_default:
  return (Panel *)this->m_pLabel;
}


// anon_unknown.dwarf_1672f3::ServerBrowserTablePanel::getCellTall  @ 000b6ea0
/* DWARF original prototype: int getCellTall(ServerBrowserTablePanel * this, int row) */

int __thiscall
anon_unknown.dwarf_1672f3::ServerBrowserTablePanel::getCellTall
          (ServerBrowserTablePanel *this,int row)

{
  return (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 15.0 - 2.0);
}


// anon_unknown.dwarf_1672f3::ServerBrowserTablePanel::getRowCount  @ 000b6e30
/* DWARF original prototype: int getRowCount(ServerBrowserTablePanel * this) */

int __thiscall
anon_unknown.dwarf_1672f3::ServerBrowserTablePanel::getRowCount(ServerBrowserTablePanel *this)

{
  int iVar1;
  int local_14;
  undefined1 local_10 [16];
  
                    /* Unresolved local var: int rowcount@[???]
                       Unresolved local var: int height@[???]
                       Unresolved local var: int width@[???] */
  (**(code **)(*(int *)this + 0xc))(this,local_10,&local_14);
  iVar1 = (int)((float)local_14 - ((float)gHUD.m_scrinfo.iHeight / 480.0) * 20.0);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return (int)((float)iVar1 / (((float)gHUD.m_scrinfo.iHeight / 480.0) * 15.0));
}


// anon_unknown.dwarf_1672f3::ServerBrowserTablePanel::startCellEditing  @ 000b6ed0
/* DWARF original prototype: Panel * startCellEditing(ServerBrowserTablePanel * this, int column,
   int row) */

Panel * __thiscall
anon_unknown.dwarf_1672f3::ServerBrowserTablePanel::startCellEditing
          (ServerBrowserTablePanel *this,int column,int row)

{
  return (Panel *)0x0;
}


// anon_unknown.dwarf_1672f3::StopHandler::actionPerformed  @ 000b73a0
/* DWARF original prototype: void actionPerformed(StopHandler * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1672f3::StopHandler::actionPerformed(StopHandler *this,Panel *panel)

{
  CHudServers *pCVar1;
  
  pCVar1 = g_pServers;
  if (g_pServers != (CHudServers *)0x0) {
    g_pServers->m_nRequesting = 0;
    pCVar1->m_nQuerying = 0;
    pCVar1->m_nDone = 1;
                    /* WARNING: Could not recover jumptable at 0x000cacec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(gEngfuncs.pNetAPI)->CancelAllRequests)();
    return;
  }
  return;
}


// anon_unknown.dwarf_1a1ea2::FooDefaultButtonSignal::actionPerformed  @ 000cd990
/* DWARF original prototype: void actionPerformed(FooDefaultButtonSignal * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1a1ea2::FooDefaultButtonSignal::actionPerformed
          (FooDefaultButtonSignal *this,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x000cd9aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_scrollBar + 0x22c))();
  return;
}


// anon_unknown.dwarf_1a1ea2::FooDefaultScrollBarIntChangeSignal::intChanged  @ 000cd970
/* DWARF original prototype: void intChanged(FooDefaultScrollBarIntChangeSignal * this, int value,
   Panel * panel) */

void __thiscall
anon_unknown.dwarf_1a1ea2::FooDefaultScrollBarIntChangeSignal::intChanged
          (FooDefaultScrollBarIntChangeSignal *this,int value,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x000cd983. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_scrollBar + 0x238))();
  return;
}


// anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::cursorEntered  @ 000ce9a0
/* DWARF original prototype: void cursorEntered(FooDefaultSliderSignal * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::cursorEntered
          (FooDefaultSliderSignal *this,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::cursorExited  @ 000ce9b0
/* DWARF original prototype: void cursorExited(FooDefaultSliderSignal * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::cursorExited
          (FooDefaultSliderSignal *this,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::cursorMoved  @ 000ce980
/* DWARF original prototype: void cursorMoved(FooDefaultSliderSignal * this, int x, int y, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::cursorMoved
          (FooDefaultSliderSignal *this,int x,int y,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x000ce993. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_slider + 0x230))();
  return;
}


// anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::keyFocusTicked  @ 000cea50
/* DWARF original prototype: void keyFocusTicked(FooDefaultSliderSignal * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::keyFocusTicked
          (FooDefaultSliderSignal *this,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::keyPressed  @ 000cea20
/* DWARF original prototype: void keyPressed(FooDefaultSliderSignal * this, KeyCode code, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::keyPressed
          (FooDefaultSliderSignal *this,KeyCode code,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::keyReleased  @ 000cea40
/* DWARF original prototype: void keyReleased(FooDefaultSliderSignal * this, KeyCode code, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::keyReleased
          (FooDefaultSliderSignal *this,KeyCode code,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::keyTyped  @ 000cea30
/* DWARF original prototype: void keyTyped(FooDefaultSliderSignal * this, KeyCode code, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::keyTyped
          (FooDefaultSliderSignal *this,KeyCode code,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::mouseDoublePressed  @ 000ce9c0
/* DWARF original prototype: void mouseDoublePressed(FooDefaultSliderSignal * this, MouseCode code,
   Panel * panel) */

void __thiscall
anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::mouseDoublePressed
          (FooDefaultSliderSignal *this,MouseCode code,Panel *panel)

{
  return;
}


// anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::mousePressed  @ 000ce9d0
/* DWARF original prototype: void mousePressed(FooDefaultSliderSignal * this, MouseCode code, Panel
   * panel) */

void __thiscall
anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::mousePressed
          (FooDefaultSliderSignal *this,MouseCode code,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x000ce9e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_slider + 0x234))();
  return;
}


// anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::mouseReleased  @ 000ce9f0
/* DWARF original prototype: void mouseReleased(FooDefaultSliderSignal * this, MouseCode code, Panel
   * panel) */

void __thiscall
anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::mouseReleased
          (FooDefaultSliderSignal *this,MouseCode code,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x000cea03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this->_slider + 0x238))();
  return;
}


// anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::mouseWheeled  @ 000cea10
/* DWARF original prototype: void mouseWheeled(FooDefaultSliderSignal * this, int delta, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_1a384b::FooDefaultSliderSignal::mouseWheeled
          (FooDefaultSliderSignal *this,int delta,Panel *panel)

{
  return;
}


