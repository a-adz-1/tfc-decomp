// Ghidra decompilation of functions from cl_dll/vgui_ServerBrowser.cpp
// 33 functions, ordered by original source line

// anon_unknown.dwarf_18fb8b::StopHandler::actionPerformed  @ 00091ed0  (line 107)

/* DWARF original prototype: void actionPerformed(StopHandler * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_18fb8b::StopHandler::actionPerformed(StopHandler *this,Panel *panel)

{
  CHudServers *pCVar1;
  
  pCVar1 = g_pServers;
  if (g_pServers != (CHudServers *)0x0) {
    g_pServers->m_nRequesting = 0;
    pCVar1->m_nQuerying = 0;
    pCVar1->m_nDone = 1;
                    /* WARNING: Could not recover jumptable at 0x000a64a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(gEngfuncs.pNetAPI)->CancelAllRequests)();
    return;
  }
  return;
}


// anon_unknown.dwarf_18fb8b::CancelHandler::actionPerformed  @ 00091c40  (line 112)

/* DWARF original prototype: void actionPerformed(CancelHandler * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_18fb8b::CancelHandler::actionPerformed(CancelHandler *this,Panel *panel)

{
                    /* WARNING: Could not recover jumptable at 0x00091c49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.pfnClientCmd)("togglebrowser\n");
  return;
}


// anon_unknown.dwarf_18fb8b::ServerBrowserTablePanel::DoConnect  @ 00091ee0  (line 115)

/* DWARF original prototype: void DoConnect(ServerBrowserTablePanel * this) */

void __thiscall
anon_unknown.dwarf_18fb8b::ServerBrowserTablePanel::DoConnect(ServerBrowserTablePanel *this)

{
  int in_EAX;
  char *pcVar1;
  int in_GS_OFFSET;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: char * info@[???]
                       Unresolved local var: char * address@[???]
                       Unresolved local var: char[256] sz@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar1 = ServersGetInfo(in_EAX);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = (*(gEngfuncs.pNetAPI)->ValueForKey)(pcVar1,"address");
    __sprintf_chk(local_110,1,0x100,"connect %s\n",pcVar1);
    (*gEngfuncs.pfnClientCmd)(local_110);
    (*gEngfuncs.pfnClientCmd)("togglebrowser\n");
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// anon_unknown.dwarf_18fb8b::ServerBrowserTablePanel::getRowCount  @ 00091e40  (line 142)

/* DWARF original prototype: int getRowCount(ServerBrowserTablePanel * this) */

int __thiscall
anon_unknown.dwarf_18fb8b::ServerBrowserTablePanel::getRowCount(ServerBrowserTablePanel *this)

{
  int iVar1;
  int local_14;
  int local_10 [4];
  
                    /* Unresolved local var: int rowcount@[DW_OP_reg0(EAX)]
                       Unresolved local var: int height@[???]
                       Unresolved local var: int width@[???] */
  vgui::Panel::getSize((int *)this,local_10);
  iVar1 = (int)((float)local_14 - ((float)gHUD.m_scrinfo.iHeight / 480.0) * 20.0);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return (int)((float)iVar1 / (((float)gHUD.m_scrinfo.iHeight / 480.0) * 15.0));
}


// anon_unknown.dwarf_18fb8b::ServerBrowserTablePanel::getCellTall  @ 00091c00  (line 158)

/* DWARF original prototype: int getCellTall(ServerBrowserTablePanel * this, int row) */

int __thiscall
anon_unknown.dwarf_18fb8b::ServerBrowserTablePanel::getCellTall
          (ServerBrowserTablePanel *this,int row)

{
  return (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 15.0 - 2.0);
}


// anon_unknown.dwarf_18fb8b::ServerBrowserTablePanel::getCellRenderer  @ 00091f80  (line 163)

/* DWARF original prototype: Panel * getCellRenderer(ServerBrowserTablePanel * this, int column, int
   row, bool columnSelected, bool rowSelected, bool cellSelected) */

Panel * __thiscall
anon_unknown.dwarf_18fb8b::ServerBrowserTablePanel::getCellRenderer
          (ServerBrowserTablePanel *this,int column,int row,bool columnSelected,bool rowSelected,
          bool cellSelected)

{
  Label *pLVar1;
  char *pcVar2;
  int iVar3;
  int in_GS_OFFSET;
  char *pcVar4;
  char local_40 [31];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char * info@[???]
                       Unresolved local var: char * val@[???]
                       Unresolved local var: char * val2@[???]
                       Unresolved local var: char[32] sz@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar2 = ServersGetInfo(row);
  pLVar1 = this->m_pLabel;
  if (row == this->m_nMouseOverRow) {
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
    goto switchD_00092060_default;
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
    if ((pcVar4 == (char *)0x0) || (pcVar2 == (char *)0x0)) goto switchD_00092060_default;
    __sprintf_chk(local_40,1,0x20,"%s/%s",pcVar4,pcVar2);
    goto LAB_000920a1;
  case 4:
    pcVar4 = "ping";
    break;
  default:
    goto switchD_00092060_default;
  }
  pcVar2 = (*(gEngfuncs.pNetAPI)->ValueForKey)(pcVar2,pcVar4);
  if (pcVar2 != (char *)0x0) {
    strncpy(local_40,pcVar2,0x1f);
LAB_000920a1:
    local_21 = 0;
    (**(code **)(*(int *)this->m_pLabel + 0x204))(this->m_pLabel,local_40);
  }
switchD_00092060_default:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (Panel *)this->m_pLabel;
}


// anon_unknown.dwarf_18fb8b::ServerBrowserTablePanel::startCellEditing  @ 00091c30  (line 268)

/* DWARF original prototype: Panel * startCellEditing(ServerBrowserTablePanel * this, int column,
   int row) */

Panel * __thiscall
anon_unknown.dwarf_18fb8b::ServerBrowserTablePanel::startCellEditing
          (ServerBrowserTablePanel *this,int column,int row)

{
  return (Panel *)0x0;
}


// anon_unknown.dwarf_18fb8b::ConnectHandler::actionPerformed  @ 00092440  (line 283)

/* DWARF original prototype: void actionPerformed(ConnectHandler * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_18fb8b::ConnectHandler::actionPerformed(ConnectHandler *this,Panel *panel)

{
  char *pcVar1;
  int in_GS_OFFSET;
  char local_110 [256];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: char * info@[???]
                       Unresolved local var: char * address@[???]
                       Unresolved local var: char[256] sz@[???] */
  pcVar1 = ServersGetInfo(this->m_pBrowser->m_nMouseOverRow);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = (*(gEngfuncs.pNetAPI)->ValueForKey)(pcVar1,"address");
    __sprintf_chk(local_110,1,0x100,"connect %s\n",pcVar1);
    (*gEngfuncs.pfnClientCmd)(local_110);
    (*gEngfuncs.pfnClientCmd)("togglebrowser\n");
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// anon_unknown.dwarf_18fb8b::RefreshHandler::actionPerformed  @ 00091eb0  (line 300)

/* DWARF original prototype: void actionPerformed(RefreshHandler * this, Panel * panel) */

void __thiscall
anon_unknown.dwarf_18fb8b::RefreshHandler::actionPerformed(RefreshHandler *this,Panel *panel)

{
  ServersList();
  BroadcastServersList(0);
  return;
}


// LabelSortInputHandler::cursorMoved  @ 00092fa0  (line 406)

/* DWARF original prototype: void cursorMoved(LabelSortInputHandler * this, int x, int y, Panel *
   panel) */

void __thiscall
LabelSortInputHandler::cursorMoved(LabelSortInputHandler *this,int x,int y,Panel *panel)

{
  return;
}


// LabelSortInputHandler::cursorEntered  @ 00092fb0  (line 407)

/* DWARF original prototype: void cursorEntered(LabelSortInputHandler * this, Panel * panel) */

void __thiscall LabelSortInputHandler::cursorEntered(LabelSortInputHandler *this,Panel *panel)

{
  return;
}


// LabelSortInputHandler::cursorExited  @ 00092fc0  (line 408)

/* DWARF original prototype: void cursorExited(LabelSortInputHandler * this, Panel * Panel) */

void __thiscall LabelSortInputHandler::cursorExited(LabelSortInputHandler *this,Panel *Panel)

{
  return;
}


// LabelSortInputHandler::mousePressed  @ 00093040  (line 412)

/* DWARF original prototype: void mousePressed(LabelSortInputHandler * this, MouseCode code, Panel *
   panel) */

void __thiscall
LabelSortInputHandler::mousePressed(LabelSortInputHandler *this,MouseCode code,Panel *panel)

{
  SortServers(this->m_szSortKey);
  return;
}


// LabelSortInputHandler::mouseDoublePressed  @ 00093030  (line 417)

/* DWARF original prototype: void mouseDoublePressed(LabelSortInputHandler * this, MouseCode code,
   Panel * panel) */

void __thiscall
LabelSortInputHandler::mouseDoublePressed(LabelSortInputHandler *this,MouseCode code,Panel *panel)

{
  SortServers(this->m_szSortKey);
  return;
}


// LabelSortInputHandler::mouseReleased  @ 00092fd0  (line 420)

/* DWARF original prototype: void mouseReleased(LabelSortInputHandler * this, MouseCode code, Panel
   * panel) */

void __thiscall
LabelSortInputHandler::mouseReleased(LabelSortInputHandler *this,MouseCode code,Panel *panel)

{
  return;
}


// LabelSortInputHandler::mouseWheeled  @ 00092fe0  (line 421)

/* DWARF original prototype: void mouseWheeled(LabelSortInputHandler * this, int delta, Panel *
   panel) */

void __thiscall
LabelSortInputHandler::mouseWheeled(LabelSortInputHandler *this,int delta,Panel *panel)

{
  return;
}


// LabelSortInputHandler::keyPressed  @ 00092ff0  (line 422)

/* DWARF original prototype: void keyPressed(LabelSortInputHandler * this, KeyCode code, Panel *
   panel) */

void __thiscall
LabelSortInputHandler::keyPressed(LabelSortInputHandler *this,KeyCode code,Panel *panel)

{
  return;
}


// LabelSortInputHandler::keyTyped  @ 00093000  (line 423)

/* DWARF original prototype: void keyTyped(LabelSortInputHandler * this, KeyCode code, Panel *
   panel) */

void __thiscall
LabelSortInputHandler::keyTyped(LabelSortInputHandler *this,KeyCode code,Panel *panel)

{
  return;
}


// LabelSortInputHandler::keyReleased  @ 00093010  (line 424)

/* DWARF original prototype: void keyReleased(LabelSortInputHandler * this, KeyCode code, Panel *
   panel) */

void __thiscall
LabelSortInputHandler::keyReleased(LabelSortInputHandler *this,KeyCode code,Panel *panel)

{
  return;
}


// LabelSortInputHandler::keyFocusTicked  @ 00093020  (line 425)

/* DWARF original prototype: void keyFocusTicked(LabelSortInputHandler * this, Panel * panel) */

void __thiscall LabelSortInputHandler::keyFocusTicked(LabelSortInputHandler *this,Panel *panel)

{
  return;
}


// ServerBrowser::ServerBrowser  @ 000924f0  (line 467)

/* DWARF original prototype: void ServerBrowser(ServerBrowser * this, int x, int y, int wide, int
   tall) */

void __thiscall ServerBrowser::ServerBrowser(ServerBrowser *this,int x,int y,int wide,int tall)

{
  code *pcVar1;
  float fVar2;
  HeaderPanel *this_00;
  Label *pLVar3;
  TablePanel *pTVar4;
  undefined4 *puVar5;
  CommandButton *pCVar6;
  int iVar7;
  Label **ppLVar8;
  bool bVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  Label *local_48;
  Label *local_44;
  Label *local_30 [5];
  Label *local_1c [3];
  
  vgui::Panel::Panel((Panel *)this,x,y,wide,tall);
  (this->super_CTransparentPanel).m_iTransparency = 100;
  *(undefined ***)&this->super_CTransparentPanel = &PTR_setPos_000c7368;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CSBLabel *[5] pLabel@[???]
                       Unresolved local var: int bw@[???]
                       Unresolved local var: int bh@[???]
                       Unresolved local var: int by@[???]
                       Unresolved local var: int btnx@[???] */
  this_00 = operator_new(0xf8);
  vgui::HeaderPanel::HeaderPanel
            (this_00,0,0,wide,(int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 18.0));
  this->_headerPanel = this_00;
  vgui::Panel::setParent((Panel *)this_00);
  (**(code **)(*(int *)this->_headerPanel + 0x124))(this->_headerPanel,100,100,100,100);
  (**(code **)(*(int *)this->_headerPanel + 0x128))(this->_headerPanel,0,0,0,100);
  local_44 = operator_new(0x114);
  vgui::Label::Label(local_44,"Address");
                    /* Unresolved local var: int label_bg_r@[???]
                       Unresolved local var: int label_bg_g@[???]
                       Unresolved local var: int label_bg_b@[???]
                       Unresolved local var: int label_bg_a@[???]
                       Unresolved local var: int label_fg_r@[???]
                       Unresolved local var: int label_fg_g@[???]
                       Unresolved local var: int label_fg_b@[???]
                       Unresolved local var: int label_fg_a@[???] */
  *(undefined4 *)(local_44 + 0x110) = 0;
  *(undefined4 *)(local_44 + 0xd0) = 0x72646461;
  *(undefined4 *)(local_44 + 0xd4) = 0x737365;
  *(undefined ***)local_44 = &PTR_setPos_000c7134;
  vgui::Label::setContentAlignment((Alignment)local_44);
  vgui::Label::setFgColor((int)local_44,0xff,0,0);
  vgui::Panel::setBgColor((int)local_44,0x78,0x4b,0x20);
  vgui::Label::setFont((SchemeFont)local_44);
  local_30[0] = local_44;
  pLVar3 = operator_new(0x114);
  vgui::Label::Label(pLVar3,"Server");
                    /* Unresolved local var: int label_bg_r@[???]
                       Unresolved local var: int label_bg_g@[???]
                       Unresolved local var: int label_bg_b@[???]
                       Unresolved local var: int label_bg_a@[???]
                       Unresolved local var: int label_fg_r@[???]
                       Unresolved local var: int label_fg_g@[???]
                       Unresolved local var: int label_fg_b@[???]
                       Unresolved local var: int label_fg_a@[???] */
  *(undefined4 *)(pLVar3 + 0x110) = 0;
  *(undefined ***)pLVar3 = &PTR_setPos_000c7134;
  *(undefined4 *)(pLVar3 + 0xd0) = 0x74736f68;
  *(undefined4 *)(pLVar3 + 0xd4) = 0x656d616e;
  pLVar3[0xd8] = (Label)0x0;
  vgui::Label::setContentAlignment((Alignment)pLVar3);
  vgui::Label::setFgColor((int)pLVar3,0xff,0,0);
  vgui::Panel::setBgColor((int)pLVar3,0x78,0x4b,0x20);
  vgui::Label::setFont((SchemeFont)pLVar3);
  local_30[1] = pLVar3;
  pLVar3 = operator_new(0x114);
  vgui::Label::Label(pLVar3,"Map");
                    /* Unresolved local var: int label_bg_r@[???]
                       Unresolved local var: int label_bg_g@[???]
                       Unresolved local var: int label_bg_b@[???]
                       Unresolved local var: int label_bg_a@[???]
                       Unresolved local var: int label_fg_r@[???]
                       Unresolved local var: int label_fg_g@[???]
                       Unresolved local var: int label_fg_b@[???]
                       Unresolved local var: int label_fg_a@[???] */
  *(undefined4 *)(pLVar3 + 0xd0) = 0x70616d;
  *(undefined ***)pLVar3 = &PTR_setPos_000c7134;
  *(undefined4 *)(pLVar3 + 0x110) = 0;
  vgui::Label::setContentAlignment((Alignment)pLVar3);
  vgui::Label::setFgColor((int)pLVar3,0xff,0,0);
  vgui::Panel::setBgColor((int)pLVar3,0x78,0x4b,0x20);
  vgui::Label::setFont((SchemeFont)pLVar3);
  local_30[2] = pLVar3;
  pLVar3 = operator_new(0x114);
  vgui::Label::Label(pLVar3,"Current");
                    /* Unresolved local var: int label_bg_r@[???]
                       Unresolved local var: int label_bg_g@[???]
                       Unresolved local var: int label_bg_b@[???]
                       Unresolved local var: int label_bg_a@[???]
                       Unresolved local var: int label_fg_r@[???]
                       Unresolved local var: int label_fg_g@[???]
                       Unresolved local var: int label_fg_b@[???]
                       Unresolved local var: int label_fg_a@[???] */
  *(undefined4 *)(pLVar3 + 0x110) = 0;
  *(undefined4 *)(pLVar3 + 0xd0) = 0x72727563;
  *(undefined4 *)(pLVar3 + 0xd4) = 0x746e65;
  *(undefined ***)pLVar3 = &PTR_setPos_000c7134;
  vgui::Label::setContentAlignment((Alignment)pLVar3);
  vgui::Label::setFgColor((int)pLVar3,0xff,0,0);
  vgui::Panel::setBgColor((int)pLVar3,0x78,0x4b,0x20);
  vgui::Label::setFont((SchemeFont)pLVar3);
  local_30[3] = pLVar3;
  pLVar3 = operator_new(0x114);
  vgui::Label::Label(pLVar3,"Latency");
                    /* Unresolved local var: int label_bg_r@[???]
                       Unresolved local var: int label_bg_g@[???]
                       Unresolved local var: int label_bg_b@[???]
                       Unresolved local var: int label_bg_a@[???]
                       Unresolved local var: int label_fg_r@[???]
                       Unresolved local var: int label_fg_g@[???]
                       Unresolved local var: int label_fg_b@[???]
                       Unresolved local var: int label_fg_a@[???] */
  *(undefined4 *)(pLVar3 + 0x110) = 0;
  *(undefined ***)pLVar3 = &PTR_setPos_000c7134;
  *(undefined4 *)(pLVar3 + 0xd0) = 0x676e6970;
  pLVar3[0xd4] = (Label)0x0;
  vgui::Label::setContentAlignment((Alignment)pLVar3);
  vgui::Label::setFgColor((int)pLVar3,0xff,0,0);
  uVar12 = 200;
  uVar11 = 0x20;
  uVar10 = 0x4b;
  vgui::Panel::setBgColor((int)pLVar3,0x78,0x4b,0x20);
  vgui::Label::setFont((SchemeFont)pLVar3);
  local_30[4] = pLVar3;
  iVar7 = 0;
  do {
    ppLVar8 = local_30 + iVar7;
    iVar7 = iVar7 + 1;
    (**(code **)(*(int *)this->_headerPanel + 0x1fc))
              (this->_headerPanel,*ppLVar8,uVar10,uVar11,uVar12);
  } while (iVar7 != 5);
  (**(code **)(*(int *)this->_headerPanel + 0x200))
            (this->_headerPanel,0,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 200.0));
  (**(code **)(*(int *)this->_headerPanel + 0x200))
            (this->_headerPanel,1,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 400.0));
  (**(code **)(*(int *)this->_headerPanel + 0x200))
            (this->_headerPanel,2,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 500.0));
  (**(code **)(*(int *)this->_headerPanel + 0x200))
            (this->_headerPanel,3,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 570.0));
  (**(code **)(*(int *)this->_headerPanel + 0x200))
            (this->_headerPanel,4,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 640.0));
  pTVar4 = operator_new(0x10c);
  fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 18.0;
  vgui::TablePanel::TablePanel(pTVar4,0,(int)fVar2,wide,(int)((float)tall - fVar2),5);
  *(undefined ***)pTVar4 = &PTR_setPos_000c6dec;
  pLVar3 = operator_new(0xd0);
  vgui::Label::Label(pLVar3,"",0,0);
  *(Label **)(pTVar4 + 0x104) = pLVar3;
  *(undefined4 *)(pTVar4 + 0x108) = 0;
  this->_tablePanel = pTVar4;
  vgui::Panel::setParent((Panel *)pTVar4);
  (**(code **)(*(int *)this->_tablePanel + 0x21c))(this->_tablePanel,this->_headerPanel);
  (**(code **)(*(int *)this->_tablePanel + 0x124))(this->_tablePanel,100,100,100,100);
  (**(code **)(*(int *)this->_tablePanel + 0x128))(this->_tablePanel,0,0,0,100);
  pcVar1 = *(code **)(*(int *)this->_tablePanel + 0x70);
  puVar5 = operator_new(8);
  pTVar4 = this->_tablePanel;
  *puVar5 = &PTR_cursorMoved_000c7074;
  puVar5[1] = pTVar4;
  (*pcVar1)(pTVar4,puVar5);
  ppLVar8 = local_30;
  while( true ) {
    local_48 = local_44 + 0xd0;
    pLVar3 = *ppLVar8;
    ppLVar8 = ppLVar8 + 1;
    *(TablePanel **)(pLVar3 + 0x110) = this->_tablePanel;
    pcVar1 = *(code **)(*(int *)pLVar3 + 0x70);
    puVar5 = operator_new(0x48);
    iVar7 = *(int *)(pLVar3 + 0x110);
    *puVar5 = &PTR_cursorMoved_000c7100;
    puVar5[1] = iVar7;
    __strcpy_chk(puVar5 + 2,local_48,0x40);
    (*pcVar1)(local_44,puVar5);
    if (local_1c == ppLVar8) break;
    local_44 = *ppLVar8;
  }
  iVar7 = (int)((float)tall - ((float)gHUD.m_scrinfo.iHeight / 480.0) * 18.0);
  pCVar6 = operator_new(0x130);
  CommandButton::CommandButton(pCVar6,"Connect",10,iVar7,0x50,0xf,false);
  this->_connectButton = pCVar6;
  vgui::Panel::setParent((Panel *)pCVar6);
  pcVar1 = *(code **)(*(int *)this->_connectButton + 0x240);
  puVar5 = operator_new(8);
  puVar5[1] = this->_tablePanel;
  pCVar6 = this->_connectButton;
  *puVar5 = &PTR_actionPerformed_000c7044;
  (*pcVar1)(pCVar6,puVar5);
  pCVar6 = operator_new(0x130);
  CommandButton::CommandButton(pCVar6,"Refresh",0x5a,iVar7,0x50,0xf,false);
  this->_refreshButton = pCVar6;
  vgui::Panel::setParent((Panel *)pCVar6);
  pcVar1 = *(code **)(*(int *)this->_refreshButton + 0x240);
  puVar5 = operator_new(8);
  puVar5[1] = this->_tablePanel;
  pCVar6 = this->_refreshButton;
  *puVar5 = &PTR_actionPerformed_000c7050;
  (*pcVar1)(pCVar6,puVar5);
  pCVar6 = operator_new(0x130);
  CommandButton::CommandButton(pCVar6,"Stop",0xaa,iVar7,0x50,0xf,false);
  this->_stopButton = pCVar6;
  vgui::Panel::setParent((Panel *)pCVar6);
  pcVar1 = *(code **)(*(int *)this->_stopButton + 0x240);
  puVar5 = operator_new(8);
  puVar5[1] = this->_tablePanel;
  pCVar6 = this->_stopButton;
  *puVar5 = &PTR_actionPerformed_000c705c;
  (*pcVar1)(pCVar6,puVar5);
  pCVar6 = operator_new(0x130);
  CommandButton::CommandButton(pCVar6,"Close",0xfa,iVar7,0x50,0xf,false);
  this->_cancelButton = pCVar6;
  vgui::Panel::setParent((Panel *)pCVar6);
  pcVar1 = *(code **)(*(int *)this->_cancelButton + 0x240);
  puVar5 = operator_new(8);
  puVar5[1] = this->_tablePanel;
  pCVar6 = this->_cancelButton;
  *puVar5 = &PTR_actionPerformed_000c7068;
  (*pcVar1)(pCVar6,puVar5);
  bVar9 = SUB41(this,0);
  vgui::Panel::setPaintBorderEnabled(bVar9);
  vgui::Panel::setPaintBackgroundEnabled(bVar9);
  vgui::Panel::setPaintEnabled(bVar9);
  return;
}


// ServerBrowser::setSize  @ 00091c50  (line 566)

/* DWARF original prototype: void setSize(ServerBrowser * this, int wide, int tall) */

void __thiscall ServerBrowser::setSize(ServerBrowser *this,int wide,int tall)

{
  float fVar1;
  float fVar2;
  
  vgui::Panel::setSize((int)this,wide);
  (**(code **)(*(int *)this->_headerPanel + 0x10))
            (this->_headerPanel,0,0,wide,(int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 18.0));
  fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 18.0;
  fVar1 = (float)tall;
  (**(code **)(*(int *)this->_tablePanel + 0x10))
            (this->_tablePanel,0,(int)fVar2,wide,(int)((float)tall - fVar2));
  (**(code **)(*(int *)this->_connectButton + 0x10))
            (this->_connectButton,5,(int)(fVar1 - ((float)gHUD.m_scrinfo.iHeight / 480.0) * 18.0),
             0x4b,0xf);
  (**(code **)(*(int *)this->_refreshButton + 0x10))
            (this->_refreshButton,0x55,(int)(fVar1 - ((float)gHUD.m_scrinfo.iHeight / 480.0) * 18.0)
             ,0x4b,0xf);
  (**(code **)(*(int *)this->_stopButton + 0x10))
            (this->_stopButton,0xa5,(int)(fVar1 - ((float)gHUD.m_scrinfo.iHeight / 480.0) * 18.0),
             0x4b,0xf);
  (**(code **)(*(int *)this->_cancelButton + 0x10))
            (this->_cancelButton,0xf5,(int)(fVar1 - ((float)gHUD.m_scrinfo.iHeight / 480.0) * 18.0),
             0x4b,0xf);
  return;
}


// anon_unknown.dwarf_18fb8b::CBrowser_InputSignal::mousePressed  @ 00092240  (line 585)

/* DWARF original prototype: void mousePressed(CBrowser_InputSignal * this, MouseCode code, Panel *
   panel) */

void __thiscall
anon_unknown.dwarf_18fb8b::CBrowser_InputSignal::mousePressed
          (CBrowser_InputSignal *this,MouseCode code,Panel *panel)

{
  int *piVar1;
  undefined1 local_14 [4];
  int local_10;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int therow@[???] */
  if (code != MOUSE_LEFT) {
    return;
  }
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int therow@[???] */
  piVar1 = (int *)(**(code **)(*(int *)panel + 0x14c))(panel);
  (**(code **)(*piVar1 + 0x34))(piVar1,local_14,&local_10);
  (**(code **)(*(int *)panel + 0x8c))(panel,local_14,&local_10);
  this->m_pBrowser->m_nMouseOverRow =
       (int)((float)local_10 / (((float)gHUD.m_scrinfo.iHeight / 480.0) * 15.0));
  return;
}


// anon_unknown.dwarf_18fb8b::CBrowser_InputSignal::mouseDoublePressed  @ 000922f0  (line 602)

/* DWARF original prototype: void mouseDoublePressed(CBrowser_InputSignal * this, MouseCode code,
   Panel * panel) */

void __thiscall
anon_unknown.dwarf_18fb8b::CBrowser_InputSignal::mouseDoublePressed
          (CBrowser_InputSignal *this,MouseCode code,Panel *panel)

{
  int *piVar1;
  undefined1 local_14 [4];
  int local_10;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int therow@[???] */
  if (code != MOUSE_LEFT) {
    return;
  }
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int therow@[???] */
  piVar1 = (int *)(**(code **)(*(int *)panel + 0x14c))(panel);
  (**(code **)(*piVar1 + 0x34))(piVar1,local_14,&local_10);
  (**(code **)(*(int *)panel + 0x8c))(panel,local_14,&local_10);
  this->m_pBrowser->m_nMouseOverRow =
       (int)((float)local_10 / (((float)gHUD.m_scrinfo.iHeight / 480.0) * 15.0));
  ServerBrowserTablePanel::DoConnect((ServerBrowserTablePanel *)panel);
  return;
}


// (anonymous_namespace)::CBrowser_InputSignal::cursorMoved  @ 000923b0  (line 617)

/* (anonymous namespace)::CBrowser_InputSignal::cursorMoved(int, int, vgui::Panel*) */

void (anonymous_namespace)::CBrowser_InputSignal::cursorMoved
               (int param_1,int param_2,Panel *param_3)

{
  return;
}


// (anonymous_namespace)::CBrowser_InputSignal::mouseReleased  @ 000923c0  (line 617)

/* (anonymous namespace)::CBrowser_InputSignal::mouseReleased(vgui::MouseCode, vgui::Panel*) */

void (anonymous_namespace)::CBrowser_InputSignal::mouseReleased(MouseCode param_1,Panel *param_2)

{
  return;
}


// (anonymous_namespace)::CBrowser_InputSignal::mouseWheeled  @ 000923d0  (line 617)

/* (anonymous namespace)::CBrowser_InputSignal::mouseWheeled(int, vgui::Panel*) */

void (anonymous_namespace)::CBrowser_InputSignal::mouseWheeled(int param_1,Panel *param_2)

{
  return;
}


// (anonymous_namespace)::CBrowser_InputSignal::keyPressed  @ 000923e0  (line 617)

/* (anonymous namespace)::CBrowser_InputSignal::keyPressed(vgui::KeyCode, vgui::Panel*) */

void (anonymous_namespace)::CBrowser_InputSignal::keyPressed(KeyCode param_1,Panel *param_2)

{
  return;
}


// (anonymous_namespace)::CBrowser_InputSignal::keyTyped  @ 000923f0  (line 617)

/* (anonymous namespace)::CBrowser_InputSignal::keyTyped(vgui::KeyCode, vgui::Panel*) */

void (anonymous_namespace)::CBrowser_InputSignal::keyTyped(KeyCode param_1,Panel *param_2)

{
  return;
}


// (anonymous_namespace)::CBrowser_InputSignal::keyReleased  @ 00092400  (line 617)

/* (anonymous namespace)::CBrowser_InputSignal::keyReleased(vgui::KeyCode, vgui::Panel*) */

void (anonymous_namespace)::CBrowser_InputSignal::keyReleased(KeyCode param_1,Panel *param_2)

{
  return;
}


// (anonymous_namespace)::CBrowser_InputSignal::keyFocusTicked  @ 00092410  (line 617)

/* (anonymous namespace)::CBrowser_InputSignal::keyFocusTicked(vgui::Panel*) */

void (anonymous_namespace)::CBrowser_InputSignal::keyFocusTicked(Panel *param_1)

{
  return;
}


// (anonymous_namespace)::CBrowser_InputSignal::cursorEntered  @ 00092420  (line 617)

/* (anonymous namespace)::CBrowser_InputSignal::cursorEntered(vgui::Panel*) */

void (anonymous_namespace)::CBrowser_InputSignal::cursorEntered(Panel *param_1)

{
  return;
}


// (anonymous_namespace)::CBrowser_InputSignal::cursorExited  @ 00092430  (line 617)

/* (anonymous namespace)::CBrowser_InputSignal::cursorExited(vgui::Panel*) */

void (anonymous_namespace)::CBrowser_InputSignal::cursorExited(Panel *param_1)

{
  return;
}


