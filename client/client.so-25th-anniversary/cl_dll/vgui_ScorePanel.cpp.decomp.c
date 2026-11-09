// Ghidra decompilation of functions from cl_dll/vgui_ScorePanel.cpp
// 18 functions, ordered by original source line

// ScorePanel::HitTestPanel::internalMousePressed  @ 0008d0c0  (line 82)

/* DWARF original prototype: void internalMousePressed(HitTestPanel * this, MouseCode code) */

void __thiscall ScorePanel::HitTestPanel::internalMousePressed(HitTestPanel *this,MouseCode code)

{
  int *piVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < *(int *)&this->field_0x40) {
    iVar2 = 0;
    do {
      if (iVar2 < 0) {
        piVar1 = (int *)0x0;
      }
      else {
        piVar1 = *(int **)(*(int *)&this->field_0x48 + iVar2 * 4);
      }
      iVar2 = iVar2 + 1;
      (**(code **)(*piVar1 + 0xc))(piVar1,code,this);
    } while (iVar2 < *(int *)&this->field_0x40);
  }
  return;
}


// ScorePanel::ScorePanel  @ 0008e510  (line 94)

/* WARNING: Removing unreachable block (ram,0x0008f71c) */
/* WARNING: Removing unreachable block (ram,0x0008f70b) */
/* WARNING: Removing unreachable block (ram,0x0008f521) */
/* WARNING: Removing unreachable block (ram,0x0008f52e) */
/* DWARF original prototype: void ScorePanel(ScorePanel * this, int x, int y, int wide, int tall) */

void __thiscall ScorePanel::ScorePanel(ScorePanel *this,int x,int y,int wide,int tall)

{
  CSchemeManager *this_00;
  Color *this_01;
  Color CVar1;
  char cVar2;
  code *pcVar3;
  float fVar4;
  TeamFortressViewport *pTVar5;
  int iVar6;
  int iVar7;
  Label *this_02;
  CGrid *this_03;
  Image *pIVar8;
  TextImage *pTVar9;
  CListBox *this_04;
  HitTestPanel *this_05;
  SchemeHandle_t schemeHandle;
  SchemeHandle_t schemeHandle_00;
  Font *pFVar10;
  Font *pFVar11;
  BitmapTGA *pBVar12;
  LineBorder *pLVar13;
  int iVar14;
  int *piVar15;
  CommandButton *pCVar16;
  undefined4 *puVar17;
  char *pcVar18;
  Label *this_06;
  SBColumnInfo *this_07;
  Panel *pPVar19;
  int iVar20;
  CGrid *this_08;
  Color *pCVar21;
  char *pcVar22;
  CGrid *this_09;
  extra_player_info_t *peVar23;
  team_info_t *ptVar24;
  int in_GS_OFFSET;
  byte bVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  int local_500;
  SBColumnInfo *local_4fc;
  Panel *local_4f8;
  undefined1 local_4c4 [4];
  undefined1 local_4c0 [4];
  undefined4 local_4bc;
  undefined1 local_4b8 [4];
  int local_4b4;
  int local_4b0;
  int local_4ac;
  int local_4a8;
  int local_4a4;
  int local_4a0;
  int local_49c;
  int local_498;
  int local_494;
  int local_490;
  code *local_48c;
  undefined4 local_488;
  undefined4 local_484;
  Color local_480 [4];
  undefined4 local_47c;
  undefined4 local_478;
  code *local_474;
  undefined4 local_470;
  undefined4 local_46c;
  Color local_468 [4];
  undefined4 local_464;
  undefined4 local_460;
  Color local_45c [4];
  undefined4 local_458;
  undefined4 local_454;
  code *local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_440;
  code *local_438;
  undefined4 local_434;
  undefined4 local_430;
  code *local_42c;
  undefined4 local_428;
  undefined4 local_424;
  char local_420 [511];
  Color aCStack_221 [513];
  int local_20;
  
  bVar25 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Panel::Panel(&this->super_Panel,x,y,wide,tall);
  (this->super_CDefaultInputSignal).super_InputSignal._vptr_InputSignal =
       (_func_int_varargs **)&PTR_cursorMoved_000c6930;
  this_02 = &this->m_TitleLabel;
  *(undefined ***)this = &PTR_setPos_000c6724;
  vgui::Panel::Panel((Panel *)this_02,0,0,10,10);
  *(code **)&this->m_TitleLabel = vgui::Panel::drawPrintChar;
  iVar20 = 7;
  vgui::Label::init((int)this_02,(char *)0x1,true);
  this_03 = &this->m_HeaderGrid;
  vgui::CGrid::CGrid(this_03);
  pPVar19 = (Panel *)this->m_HeaderLabels;
  this_06 = (Label *)pPVar19;
  do {
    vgui::Label::Label(this_06,"");
    *(undefined ***)this_06 = &PTR_setPos_000c6964;
    pIVar8 = operator_new(0x2c);
    vgui::Image::Image(pIVar8);
    *(undefined ***)pIVar8 = &PTR_setPos_000c64b8;
    pTVar9 = operator_new(0x48);
    vgui::TextImage::TextImage(pTVar9,"");
    *(TextImage **)(pIVar8 + 0x24) = pTVar9;
    pTVar9 = operator_new(0x48);
    vgui::TextImage::TextImage(pTVar9,"");
    *(TextImage **)(pIVar8 + 0x28) = pTVar9;
    *(Image **)(this_06 + 0xd0) = pIVar8;
    vgui::Color::Color(local_480,0xff,0xaa,0,0);
    local_48c = isalnum;
    local_488 = local_47c;
    local_484 = local_478;
    (**(code **)(**(int **)(*(int *)(this_06 + 0xd0) + 0x28) + 0xc))
              (*(int **)(*(int *)(this_06 + 0xd0) + 0x28),&local_48c);
    iVar20 = iVar20 + -1;
    *(undefined4 *)(this_06 + 0xd4) = 0xfffffffe;
    this_06[0xe4] = (Label)0x1;
    *(undefined4 *)(this_06 + 0xdc) = 0;
    *(undefined4 *)(this_06 + 0xe0) = 0;
    this_06 = this_06 + 0xe8;
  } while (iVar20 != -1);
  this_04 = &this->m_PlayerList;
  vgui::CListBox::CListBox(this_04);
  iVar20 = 0x49;
  this_09 = (CGrid *)&this->field_0xd20;
  this_08 = this_09;
  do {
    vgui::CGrid::CGrid(this_08);
    iVar20 = iVar20 + -1;
    this_08 = this_08 + 1;
  } while (iVar20 != -1);
  local_500 = 7;
  local_4f8 = (Panel *)this->m_PlayerEntries;
  local_4fc = (SBColumnInfo *)local_4f8;
  while( true ) {
    iVar20 = 0x49;
    this_07 = local_4fc;
    do {
      vgui::Label::Label((Label *)this_07,"");
      *(undefined ***)this_07 = &PTR_setPos_000c6964;
      pIVar8 = operator_new(0x2c);
      vgui::Image::Image(pIVar8);
      *(undefined ***)pIVar8 = &PTR_setPos_000c64b8;
      pTVar9 = operator_new(0x48);
      vgui::TextImage::TextImage(pTVar9,"");
      *(TextImage **)(pIVar8 + 0x24) = pTVar9;
      pTVar9 = operator_new(0x48);
      vgui::TextImage::TextImage(pTVar9,"");
      *(TextImage **)(pIVar8 + 0x28) = pTVar9;
      *(Image **)((int)this_07 + 0xd0) = pIVar8;
      vgui::Color::Color(local_468,0xff,0xaa,0,0);
      local_474 = isalnum;
      local_470 = local_464;
      local_46c = local_460;
      (**(code **)(**(int **)(*(int *)((int)this_07 + 0xd0) + 0x28) + 0xc))
                (*(int **)(*(int *)((int)this_07 + 0xd0) + 0x28),&local_474);
      iVar20 = iVar20 + -1;
      *(undefined4 *)((int)this_07 + 0xd4) = 0xfffffffe;
      *(Label *)((int)this_07 + 0xe4) = (Label)0x1;
      *(undefined4 *)((int)this_07 + 0xdc) = 0;
      *(undefined4 *)((int)this_07 + 0xe0) = 0;
      this_07 = (SBColumnInfo *)((int)this_07 + 0xe8);
    } while (iVar20 != -1);
    local_500 = local_500 + -1;
    if (local_500 == -1) break;
    local_4fc = (SBColumnInfo *)((int)local_4fc + 0x4310);
  }
  this_05 = &this->m_HitTestPanel;
  vgui::Panel::Panel(&this_05->super_Panel);
  pTVar5 = gViewPort;
                    /* Unresolved local var: CSchemeManager * pSchemes@[???]
                       Unresolved local var: SchemeHandle_t hTitleScheme@[???]
                       Unresolved local var: SchemeHandle_t hSmallScheme@[???]
                       Unresolved local var: Font * tfont@[???]
                       Unresolved local var: Font * smallfont@[???]
                       Unresolved local var: LineBorder * border@[???]
                       Unresolved local var: int xpos@[???]
                       Unresolved local var: int ex@[???]
                       Unresolved local var: int ey@[???]
                       Unresolved local var: int ew@[???]
                       Unresolved local var: int eh@[???]
                       Unresolved local var: int headerX@[???]
                       Unresolved local var: int headerY@[???]
                       Unresolved local var: int headerWidth@[???]
                       Unresolved local var: int headerHeight@[???] */
  *(undefined ***)&this->m_HitTestPanel = &PTR_setPos_000c6520;
  this_00 = &pTVar5->m_SchemeManager;
  schemeHandle = CSchemeManager::getSchemeHandle(this_00,"Scoreboard Title Text");
  schemeHandle_00 = CSchemeManager::getSchemeHandle(this_00,"Scoreboard Small Text");
  pFVar10 = CSchemeManager::getFont(this_00,schemeHandle);
  pFVar11 = CSchemeManager::getFont(this_00,schemeHandle_00);
  uVar28 = 0x60;
  uVar27 = 0;
  uVar26 = 0;
  vgui::Panel::setBgColor((int)this,0,0,0);
  this->m_pCurrentHighlightLabel = (CLabelHeader *)0x0;
  this->m_iHighlightRow = -1;
  pBVar12 = vgui_LoadTGANoInvertAlpha("gfx/vgui/640_scoreboardtracker.tga");
  this->m_pTrackerIcon = pBVar12;
  vgui::Label::setFont((Font *)this_02);
  vgui::Label::setText((char *)this_02,"",uVar26,uVar27,uVar28);
  vgui::Panel::setBgColor((int)this_02,0,0,0);
  vgui::Label::setFgColor((SchemeColor)this_02);
  vgui::Label::setContentAlignment((Alignment)this_02);
  this_01 = aCStack_221 + 1;
  vgui::Color::Color(this_01,0x3c,0x3c,0x3c,0x80);
  pLVar13 = operator_new(0x44);
  vgui::LineBorder::LineBorder(pLVar13,this_01);
  vgui::Panel::setBorder((Border *)this);
  vgui::Panel::setPaintBorderEnabled(SUB41(this,0));
  iVar20 = g_ColumnInfo[0].m_Width + 3;
  if (0x27f < gHUD.m_scrinfo.iWidth) {
    iVar20 = (int)((float)iVar20 * ((float)gHUD.m_scrinfo.iWidth / 640.0));
  }
  vgui::Panel::setBounds((int)this_02,iVar20,4,wide);
  vgui::Label::setContentFitted(SUB41(this_02,0));
  vgui::Panel::setParent((Panel *)this_02);
  vgui::CGrid::SetDimensions(this_03,8,1);
  vgui::CGrid::SetSpacing(this_03,0,0);
  local_4fc = g_ColumnInfo;
  local_500 = 0;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int xwide@[???]
                       Unresolved local var: int yres@[???] */
    pcVar18 = local_4fc->m_pTitle;
    if (pcVar18 != (char *)0x0) {
      if (*pcVar18 == '#') {
        pcVar3 = *(code **)(*(int *)pPVar19 + 0x22c);
        pcVar18 = CHudTextMessage::BufferedLocaliseTextString(pcVar18);
        if (pcVar3 == CLabelHeader::setText) {
                    /* Unresolved local var: char[512] buf@[???]
                       Unresolved local var: int len@[???] */
          pcVar22 = local_420;
          iVar20 = __stpcpy_chk(pcVar22,pcVar18,0x200);
          iVar20 = iVar20 - (int)pcVar22;
          while (iVar20 != 0) {
            iVar20 = iVar20 + -1;
            iVar14 = isspace((int)pcVar22[iVar20]);
            if (iVar14 == 0) break;
            pcVar22[iVar20] = '\0';
          }
                    /* Unresolved local var: Font * font@[???] */
          (**(code **)(**(int **)(*(int *)(pPVar19 + 0xd0) + 0x24) + 0x74))
                    (*(int **)(*(int *)(pPVar19 + 0xd0) + 0x24),pcVar22);
          piVar15 = (int *)(**(code **)(**(int **)(*(int *)(pPVar19 + 0xd0) + 0x24) + 0x6c))
                                     (*(int **)(*(int *)(pPVar19 + 0xd0) + 0x24));
          *(undefined4 *)(pPVar19 + 0xd8) = 0;
          cVar2 = local_420[0];
                    /* Unresolved local var: char * ch@[???] */
          if (local_420[0] == '\0') goto LAB_0008f6f6;
          do {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
            (**(code **)(*piVar15 + 8))(piVar15,(int)cVar2,&local_4b4,&local_4b0,&local_4ac);
            pcVar22 = pcVar22 + 1;
            iVar20 = local_4b0 + local_4b4 + local_4ac + *(int *)(pPVar19 + 0xd8);
            cVar2 = *pcVar22;
            *(int *)(pPVar19 + 0xd8) = iVar20;
          } while (cVar2 != '\0');
LAB_0008ec5c:
          fVar4 = (float)iVar20;
          goto LAB_0008ec64;
        }
        (*pcVar3)(pPVar19,pcVar18);
      }
      else {
        pcVar3 = *(code **)(*(int *)pPVar19 + 0x22c);
        if (pcVar3 == CLabelHeader::setText) {
                    /* Unresolved local var: char[512] buf@[???]
                       Unresolved local var: int len@[???] */
          iVar20 = __stpcpy_chk(this_01,pcVar18,0x200);
          iVar20 = iVar20 - (int)this_01;
          while (iVar20 != 0) {
            iVar20 = iVar20 + -1;
            iVar14 = isspace((int)(char)this_01[iVar20]);
            if (iVar14 == 0) break;
            this_01[iVar20] = (Color)0x0;
          }
                    /* Unresolved local var: Font * font@[???] */
          (**(code **)(**(int **)(*(int *)(pPVar19 + 0xd0) + 0x24) + 0x74))
                    (*(int **)(*(int *)(pPVar19 + 0xd0) + 0x24),this_01);
          piVar15 = (int *)(**(code **)(**(int **)(*(int *)(pPVar19 + 0xd0) + 0x24) + 0x6c))
                                     (*(int **)(*(int *)(pPVar19 + 0xd0) + 0x24));
          *(undefined4 *)(pPVar19 + 0xd8) = 0;
          pCVar21 = this_01;
          CVar1 = aCStack_221[1];
                    /* Unresolved local var: char * ch@[???] */
          if (aCStack_221[1] != (Color)0x0) {
            do {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
              (**(code **)(*piVar15 + 8))(piVar15,(int)(char)CVar1,&local_4a8,&local_4a4,&local_4a0)
              ;
              CVar1 = pCVar21[1];
              iVar20 = local_4a4 + local_4a8 + local_4a0 + *(int *)(pPVar19 + 0xd8);
              *(int *)(pPVar19 + 0xd8) = iVar20;
              pCVar21 = pCVar21 + 1;
            } while (CVar1 != (Color)0x0);
            goto LAB_0008ec5c;
          }
LAB_0008f6f6:
          fVar4 = 0.0;
LAB_0008ec64:
          *(int *)(pPVar19 + 0xd8) = (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 5.0 + fVar4);
        }
        else {
          (*pcVar3)(pPVar19,pcVar18);
        }
      }
    }
    iVar20 = local_4fc->m_Width;
    if (gHUD.m_scrinfo.iWidth < 0x280) {
      if (gHUD.m_scrinfo.iWidth == 400) {
        if (local_500 == 1) {
          iVar20 = iVar20 + -0x1c;
        }
        else if (local_500 == 0) {
          iVar20 = iVar20 + -8;
        }
      }
    }
    else {
      iVar20 = (int)((float)iVar20 * ((float)gHUD.m_scrinfo.iWidth / 640.0));
    }
    vgui::CGrid::SetColumnWidth(this_03,local_500,iVar20);
    vgui::CGrid::SetEntry(this_03,local_500,0,pPVar19);
    (**(code **)(*(int *)pPVar19 + 0x128))(pPVar19,0,0,0,0xff);
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???] */
    if (*(code **)(*(int *)pPVar19 + 0x11c) == CLabelHeader::setFgColor) {
      vgui::Label::setFgColor((SchemeColor)pPVar19);
      vgui::Panel::getFgColor((int *)pPVar19,&local_49c,&local_498,&local_494);
      iVar7 = local_490;
      iVar6 = local_494;
      iVar14 = local_498;
      iVar20 = local_49c;
      if (*(code **)(*(int *)pPVar19 + 0x124) == CLabelHeader::setFgColor) {
                    /* Unresolved local var: Color color@[???] */
        vgui::Label::setFgColor((int)pPVar19,local_49c,local_498,local_494);
        vgui::Color::Color(local_45c,iVar20,iVar14,iVar6,iVar7);
        piVar15 = *(int **)(pPVar19 + 0xd0);
        local_44c = local_458;
        local_450 = isalnum;
        local_448 = local_454;
        if (*(code **)(*piVar15 + 0xc) == CTextImage2::setColor) {
          local_424 = local_454;
          local_42c = isalnum;
          local_428 = local_458;
          (**(code **)(*(int *)piVar15[9] + 0xc))((int *)piVar15[9],&local_42c);
        }
        else {
          (**(code **)(*piVar15 + 0xc))(piVar15,&local_450);
        }
        local_440 = local_458;
        local_434 = local_458;
        local_438 = isalnum;
        local_430 = local_454;
        (**(code **)(**(int **)(*(int *)(pPVar19 + 0xd0) + 0x28) + 0xc))
                  (*(int **)(*(int *)(pPVar19 + 0xd0) + 0x28),&local_438);
        (**(code **)(*(int *)pPVar19 + 0x30))(pPVar19);
      }
      else {
        (**(code **)(*(int *)pPVar19 + 0x124))(pPVar19,local_49c,local_498,local_494,local_490);
      }
    }
    else {
      (**(code **)(*(int *)pPVar19 + 0x11c))(pPVar19,3);
    }
    if (*(code **)(*(int *)pPVar19 + 0x20c) == CLabelHeader::setFont) {
      (**(code **)(**(int **)(*(int *)(pPVar19 + 0xd0) + 0x24) + 0x7c))
                (*(int **)(*(int *)(pPVar19 + 0xd0) + 0x24),pFVar11);
    }
    else {
      (**(code **)(*(int *)pPVar19 + 0x20c))(pPVar19,pFVar11);
    }
    (**(code **)(*(int *)pPVar19 + 0x21c))(pPVar19,local_4fc->m_Alignment);
    iVar20 = 0xc;
    if (0x1df < gHUD.m_scrinfo.iHeight) {
      iVar20 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 12.0);
    }
    (**(code **)(*(int *)pPVar19 + 8))(pPVar19,0x32,iVar20);
    local_500 = local_500 + 1;
    pPVar19 = pPVar19 + 0xe8;
    local_4fc = local_4fc + 1;
    if (local_500 == 8) {
      vgui::CGrid::GetEntryBox(this_03,6,0,&local_4ac,&local_4a8,&local_4a4,&local_4a0);
      vgui::CGrid::SetColumnWidth
                (this_03,7,
                 (int)(((float)wide - ((float)gHUD.m_scrinfo.iWidth / 640.0) * 4.0) -
                      (float)(local_4a4 + local_4ac)));
      vgui::CGrid::AutoSetRowHeights(this_03);
      vgui::CGrid::GetRowHeight(this_03,0);
      fVar4 = ((float)gHUD.m_scrinfo.iWidth / 640.0) * 4.0;
      vgui::Panel::setBounds
                ((int)this_03,(int)fVar4,(int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 22.0),
                 (int)((float)wide - (fVar4 + fVar4)));
      vgui::Panel::setParent(&this_03->super_Panel);
      vgui::Panel::setBgColor((int)this_03,0,0,0);
      vgui::Panel::getBounds((int *)this_03,&local_49c,&local_498,&local_494);
      vgui::Panel::setBounds((int)this_04,local_49c,local_490 + local_498,local_494);
      vgui::Panel::setBgColor((int)this_04,0,0,0);
      vgui::Panel::setParent(&this_04->super_Panel);
      iVar20 = 0;
                    /* Unresolved local var: int row@[???]
                       Unresolved local var: CGrid * pGridRow@[???]
                       Unresolved local var: int col@[???] */
      local_4fc = (SBColumnInfo *)this_09;
      do {
        vgui::CGrid::SetDimensions(this_09,8,1);
        iVar14 = 0;
        pPVar19 = local_4f8;
        do {
          (**(code **)(*(int *)pPVar19 + 0x220))(pPVar19,0);
          *(int *)(pPVar19 + 0xd4) = iVar20;
          (**(code **)(*(int *)pPVar19 + 0x70))(pPVar19,&this->super_CDefaultInputSignal);
          vgui::CGrid::SetEntry(this_09,iVar14,0,pPVar19);
          iVar14 = iVar14 + 1;
          pPVar19 = pPVar19 + 0x4310;
        } while (iVar14 != 8);
        (**(code **)(*(int *)local_4fc + 0x128))(this_09,0,0,0,0xff);
        vgui::CGrid::SetSpacing(this_09,0,0);
        vgui::CGrid::CopyColumnWidths(this_09,this_03);
        vgui::CGrid::AutoSetRowHeights(this_09);
        pcVar3 = *(code **)(*(int *)local_4fc + 8);
        iVar14 = vgui::CGrid::CalcDrawHeight(this_09);
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???] */
        (**(code **)(*(int *)this_09 + 0x14))(this_09,local_4c4,local_4c0,&local_4bc,local_4b8);
        (*pcVar3)(this_09,local_4bc,iVar14);
        vgui::CGrid::RepositionContents(this_09);
        vgui::CListBox::AddItem(this_04,&this_09->super_Panel);
        iVar20 = iVar20 + 1;
        this_09 = this_09 + 1;
        local_4fc = (SBColumnInfo *)((int)local_4fc + 0xe0);
        local_4f8 = local_4f8 + 0xe8;
      } while (iVar20 != 0x4a);
      vgui::Panel::setBgColor((int)this_05,0,0,0);
      vgui::Panel::setParent(&this_05->super_Panel);
      vgui::Panel::setBounds((int)this_05,0,0,wide);
      vgui::Panel::addInputSignal((InputSignal *)this_05);
      pCVar16 = operator_new(0x130);
      fVar4 = (float)gHUD.m_scrinfo.iHeight / 480.0;
      CommandButton::CommandButton
                (pCVar16,"x",(int)((float)wide - ((float)gHUD.m_scrinfo.iWidth / 640.0) * 16.0),
                 (int)(fVar4 + fVar4),(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 12.0),
                 (int)(fVar4 * 12.0),false);
      this->m_pCloseButton = pCVar16;
      vgui::Panel::setParent((Panel *)pCVar16);
      pcVar3 = *(code **)(*(int *)this->m_pCloseButton + 0x240);
      puVar17 = operator_new(0x108);
      strncpy((char *)(puVar17 + 1),"-showscores",0x100);
      puVar17[0x41] = 1;
      pCVar16 = this->m_pCloseButton;
      *(undefined1 *)((int)puVar17 + 0x103) = 0;
      *puVar17 = &PTR_actionPerformed_000c64ac;
      (*pcVar3)(pCVar16,puVar17);
      (**(code **)(*(int *)this->m_pCloseButton + 0x128))(this->m_pCloseButton,0,0,0,0xff);
      (**(code **)(*(int *)this->m_pCloseButton + 0x124))(this->m_pCloseButton,0xff,0xff,0xff,0);
      (**(code **)(*(int *)this->m_pCloseButton + 0x20c))(this->m_pCloseButton,pFVar10);
      CommandButton::setBoundKey(this->m_pCloseButton,-1);
      (**(code **)(*(int *)this->m_pCloseButton + 0x21c))(this->m_pCloseButton,4);
      this->m_iLastKilledBy = 0;
      this->m_fLastKillTime = 0;
      this->m_iPlayerNum = 0;
      this->m_iNumTeams = 0;
      peVar23 = g_PlayerExtraInfo;
      for (iVar20 = 0x1c7; iVar20 != 0; iVar20 = iVar20 + -1) {
        peVar23->frags = 0;
        peVar23->deaths = 0;
        peVar23 = (extra_player_info_t *)((int)peVar23 + ((uint)bVar25 * -2 + 1) * 4);
      }
      ptVar24 = g_TeamInfo;
      for (iVar20 = 0x28a; iVar20 != 0; iVar20 = iVar20 + -1) {
        ptVar24->name[0] = '\0';
        ptVar24->name[1] = '\0';
        ptVar24->name[2] = '\0';
        ptVar24->name[3] = '\0';
        ptVar24 = (team_info_t *)((int)ptVar24 + ((uint)bVar25 * -2 + 1) * 4);
      }
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  } while( true );
}


// ScorePanel::Initialize  @ 0008d5e0  (line 243)

/* WARNING: Removing unreachable block (ram,0x0008d650) */
/* WARNING: Removing unreachable block (ram,0x0008d66a) */
/* WARNING: Removing unreachable block (ram,0x0008d670) */
/* WARNING: Removing unreachable block (ram,0x0008d62d) */
/* WARNING: Removing unreachable block (ram,0x0008d63a) */
/* DWARF original prototype: void Initialize(ScorePanel * this) */

void __thiscall ScorePanel::Initialize(ScorePanel *this)

{
  int iVar1;
  extra_player_info_t *peVar2;
  team_info_t *ptVar3;
  
  this->m_iPlayerNum = 0;
  this->m_iLastKilledBy = 0;
  this->m_iNumTeams = 0;
  this->m_fLastKillTime = 0;
  peVar2 = g_PlayerExtraInfo;
  for (iVar1 = 0x1c7; iVar1 != 0; iVar1 = iVar1 + -1) {
    peVar2->frags = 0;
    peVar2->deaths = 0;
    peVar2 = (extra_player_info_t *)&peVar2->playerclass;
  }
  ptVar3 = g_TeamInfo;
  for (iVar1 = 0x28a; iVar1 != 0; iVar1 = iVar1 + -1) {
    ptVar3->name[0] = '\0';
    ptVar3->name[1] = '\0';
    ptVar3->name[2] = '\0';
    ptVar3->name[3] = '\0';
    ptVar3 = (team_info_t *)(ptVar3->name + 4);
  }
  return;
}


// HACK_GetPlayerUniqueID  @ 0008d680  (line 254)

bool HACK_GetPlayerUniqueID(int iPlayer,char *playerID)

{
  qboolean qVar1;
  
  qVar1 = (*gEngfuncs.GetPlayerUniqueID)(iPlayer,playerID);
  return qVar1 != 0;
}


// ScorePanel::Update  @ 00090cb0  (line 262)

/* DWARF original prototype: void Update(ScorePanel * this) */

void __thiscall ScorePanel::Update(ScorePanel *this)

{
  bool *pbVar1;
  CommandButton *pCVar2;
  TeamFortressViewport *this_00;
  uint uVar3;
  bool *pbVar4;
  int *piVar5;
  cl_entity_s *pcVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  extra_player_info_t *peVar11;
  hud_player_info_t *phVar12;
  int in_GS_OFFSET;
  bool bVar13;
  int local_84;
  int local_80;
  undefined1 local_70 [80];
  int local_20;
  
                    /* Unresolved local var: int i@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (gViewPort->m_szServerName != (char *)0x0) {
                    /* Unresolved local var: char[80] sz@[???] */
    __sprintf_chk(local_70,1,0x50,&DAT_000c4b6e,gViewPort->m_szServerName);
    vgui::Label::setText((char *)&this->m_TitleLabel,local_70);
  }
  this_00 = gViewPort;
  this->m_iRows = 0;
  TeamFortressViewport::GetAllPlayersInfo(this_00);
  piVar5 = this->m_iSortedRows;
  uVar7 = 0x128;
  bVar13 = ((uint)piVar5 & 1) != 0;
  if (bVar13) {
    piVar5 = (int *)((int)this->m_iSortedRows + 1);
    uVar7 = 0x127;
    *(undefined1 *)this->m_iSortedRows = 0;
  }
  if (((uint)piVar5 & 2) != 0) {
    *(undefined2 *)piVar5 = 0;
    uVar7 = uVar7 - 2;
    piVar5 = (int *)((int)piVar5 + 2);
  }
  uVar3 = 0;
  do {
    *(undefined4 *)((int)piVar5 + uVar3) = 0;
    *(undefined4 *)((int)piVar5 + uVar3 + 4) = 0;
    uVar3 = uVar3 + 8;
  } while (uVar3 < (uVar7 & 0xfffffff8));
  puVar8 = (undefined4 *)((int)piVar5 + uVar3);
  if ((uVar7 & 4) != 0) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  if ((uVar7 & 2) != 0) {
    *(undefined2 *)puVar8 = 0;
    puVar8 = (undefined4 *)((int)puVar8 + 2);
  }
  if (bVar13) {
    *(undefined1 *)puVar8 = 0;
  }
  piVar5 = this->m_iIsATeam;
  uVar7 = 0x128;
  bVar13 = ((uint)piVar5 & 1) != 0;
  if (bVar13) {
    *(undefined1 *)this->m_iIsATeam = 0;
    piVar5 = (int *)((int)this->m_iIsATeam + 1);
    uVar7 = 0x127;
  }
  if (((uint)piVar5 & 2) != 0) {
    *(undefined2 *)piVar5 = 0;
    uVar7 = uVar7 - 2;
    piVar5 = (int *)((int)piVar5 + 2);
  }
  uVar3 = 0;
  do {
    *(undefined4 *)((int)piVar5 + uVar3) = 0;
    *(undefined4 *)((int)piVar5 + uVar3 + 4) = 0;
    uVar3 = uVar3 + 8;
  } while (uVar3 < (uVar7 & 0xfffffff8));
  puVar8 = (undefined4 *)((int)piVar5 + uVar3);
  if ((uVar7 & 4) != 0) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  if ((uVar7 & 2) != 0) {
    *(undefined2 *)puVar8 = 0;
    puVar8 = (undefined4 *)((int)puVar8 + 2);
  }
  if (bVar13) {
    *(undefined1 *)puVar8 = 0;
  }
  pbVar4 = this->m_bHasBeenSorted;
  uVar7 = 0x40;
  bVar13 = ((uint)pbVar4 & 1) != 0;
  if (bVar13) {
    this->m_bHasBeenSorted[0] = false;
    pbVar4 = this->m_bHasBeenSorted + 1;
    uVar7 = 0x3f;
  }
  if (((uint)pbVar4 & 2) != 0) {
    pbVar4[0] = false;
    pbVar4[1] = false;
    uVar7 = uVar7 - 2;
    pbVar4 = pbVar4 + 2;
  }
  uVar3 = 0;
  do {
    pbVar1 = pbVar4 + uVar3;
    pbVar1[0] = false;
    pbVar1[1] = false;
    pbVar1[2] = false;
    pbVar1[3] = false;
    pbVar1 = pbVar4 + uVar3 + 4;
    pbVar1[0] = false;
    pbVar1[1] = false;
    pbVar1[2] = false;
    pbVar1[3] = false;
    uVar3 = uVar3 + 8;
  } while (uVar3 < (uVar7 & 0xfffffff8));
  pbVar4 = pbVar4 + uVar3;
  if ((uVar7 & 4) != 0) {
    pbVar4[0] = false;
    pbVar4[1] = false;
    pbVar4[2] = false;
    pbVar4[3] = false;
    pbVar4 = pbVar4 + 4;
  }
  if ((uVar7 & 2) != 0) {
    pbVar4[0] = false;
    pbVar4[1] = false;
    pbVar4 = pbVar4 + 2;
  }
  if (bVar13) {
    *pbVar4 = false;
  }
  if (gHUD.m_Teamplay == 0) {
    while( true ) {
      local_80 = 0;
      phVar12 = g_PlayerInfoList;
      peVar11 = g_PlayerExtraInfo;
      local_84 = 99999;
      iVar9 = -99999;
                    /* Unresolved local var: int i@[???] */
      iVar10 = 1;
      do {
        phVar12 = phVar12 + 1;
        peVar11 = peVar11 + 1;
                    /* Unresolved local var: cl_entity_t * ent@[???] */
        if ((((this->m_bHasBeenSorted[iVar10] == false) && (phVar12->name != (char *)0x0)) &&
            (iVar9 <= peVar11->frags)) &&
           (pcVar6 = (*gEngfuncs.GetEntityByIndex)(iVar10), pcVar6 != (cl_entity_s *)0x0)) {
                    /* Unresolved local var: extra_player_info_t * pl_info@[???] */
          if ((iVar9 < peVar11->frags) || (peVar11->deaths < local_84)) {
            iVar9 = (int)peVar11->frags;
            local_84 = (int)peVar11->deaths;
            local_80 = iVar10;
          }
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 != 0x40);
                    /* Unresolved local var: bool bCreatedTeam@[???]
                       Unresolved local var: int highest_frags@[???]
                       Unresolved local var: int lowest_deaths@[???]
                       Unresolved local var: int best_player@[???] */
      if (local_80 == 0) break;
      iVar9 = this->m_iRows;
      this->m_iSortedRows[iVar9] = local_80;
      this->m_bHasBeenSorted[local_80] = true;
      this->m_iRows = iVar9 + 1;
    }
  }
  else {
    SortTeams(this);
  }
  vgui::CListBox::SetScrollRange(&this->m_PlayerList,this->m_iRows);
  FillGrid(this);
  pCVar2 = this->m_pCloseButton;
  if (gViewPort->m_pSpectatorPanel->m_menuVisible == false) {
    (**(code **)(*(int *)pCVar2 + 0x24))(pCVar2,0);
  }
  else {
    (**(code **)(*(int *)pCVar2 + 0x24))(pCVar2,1);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ScorePanel::SortTeams  @ 0008d8b0  (line 312)

/* DWARF original prototype: void SortTeams(ScorePanel * this) */

void __thiscall ScorePanel::SortTeams(ScorePanel *this)

{
  short sVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  short *psVar6;
  cl_entity_s *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  team_info_t *__s2;
  int iVar12;
  extra_player_info_t *peVar13;
  char *__s1;
  hud_player_info_t *phVar14;
  hud_player_info_t *local_2c;
  int local_28;
  int local_24;
  
                    /* Unresolved local var: int i@[???] */
  iVar8 = this->m_iNumTeams;
  if (0 < iVar8) {
    piVar3 = &g_TeamInfo[1].scores_overriden;
    do {
      if (*piVar3 == 0) {
        *(short *)((int)piVar3 + -0xe) = 0;
        *(short *)(piVar3 + -4) = 0;
      }
      *(short *)((int)piVar3 + -10) = 0;
      piVar4 = piVar3 + 10;
      *(short *)(piVar3 + -3) = 0;
      piVar3 = piVar4;
    } while (piVar4 != &g_TeamInfo[iVar8 + 1].scores_overriden);
  }
  local_2c = g_PlayerInfoList;
  __s1 = g_PlayerExtraInfo[1].teamname;
  do {
                    /* Unresolved local var: int j@[???] */
    local_2c = local_2c + 1;
    if (((local_2c->name != (char *)0x0) && (*__s1 != '\0')) && (0 < iVar8)) {
      __s2 = g_TeamInfo;
      iVar10 = 1;
      do {
        __s2 = __s2 + 1;
        iVar5 = strcasecmp(__s1,__s2->name);
        if (iVar5 == 0) {
          if (g_TeamInfo[iVar10].scores_overriden == 0) {
            g_TeamInfo[iVar10].frags =
                 g_TeamInfo[iVar10].frags + ((extra_player_info_t *)(__s1 + -0xc))->frags;
            g_TeamInfo[iVar10].deaths = g_TeamInfo[iVar10].deaths + *(short *)(__s1 + -10);
          }
          g_TeamInfo[iVar10].ping = g_TeamInfo[iVar10].ping + local_2c->ping;
          g_TeamInfo[iVar10].packetloss =
               g_TeamInfo[iVar10].packetloss + (ushort)local_2c->packetloss;
          g_TeamInfo[iVar10].ownteam = (ushort)(local_2c->thisplayer != '\0');
          g_TeamInfo[iVar10].teamnumber = (int)*(short *)(__s1 + -2);
          break;
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 <= iVar8);
    }
    __s1 = __s1 + 0x1c;
  } while (__s1 != g_PlayerExtraInfo[0x40].teamname);
  if (0 < iVar8) {
    psVar6 = &g_TeamInfo[1].ping;
    do {
      sVar1 = psVar6[3];
      *(int *)(psVar6 + 4) = 0;
      if (0 < sVar1) {
        *psVar6 = *psVar6 / sVar1;
        psVar6[1] = psVar6[1] / sVar1;
      }
      psVar6 = psVar6 + 0x14;
    } while (psVar6 != &g_TeamInfo[iVar8 + 1].ping);
    do {
      psVar6 = &g_TeamInfo[1].deaths;
      iVar5 = 99999;
      local_2c = (hud_player_info_t *)0x0;
      iVar10 = -99999;
      iVar9 = 1;
      do {
        if (((0 < psVar6[4]) && (*(int *)(psVar6 + 5) == 0)) &&
           (iVar11 = (int)psVar6[-1], iVar10 <= iVar11)) {
          if (iVar10 < iVar11) {
            iVar12 = (int)*psVar6;
          }
          else {
            iVar12 = (int)*psVar6;
            if (iVar5 <= iVar12) goto LAB_0008da50;
          }
                    /* Unresolved local var: int highest_frags@[???]
                       Unresolved local var: int lowest_deaths@[???]
                       Unresolved local var: int best_team@[???] */
          iVar10 = iVar11;
          iVar5 = iVar12;
          local_2c = (hud_player_info_t *)iVar9;
        }
LAB_0008da50:
        iVar9 = iVar9 + 1;
        psVar6 = psVar6 + 0x14;
      } while (iVar9 != iVar8 + 1);
      if (local_2c == (hud_player_info_t *)0x0) break;
      iVar8 = this->m_iRows;
      *(undefined4 *)
       ((int)&__DT_REL[0x1687].r_offset +
       (int)(&this->m_PlayerEntries[0][0].super_Label + iVar8 * 4)) = 1;
      *(hud_player_info_t **)
       ((int)&__DT_REL[0x1662].r_offset +
       (int)(&this->m_PlayerEntries[0][0].super_Label + iVar8 * 4)) = local_2c;
      g_TeamInfo[(int)local_2c].already_drawn = 1;
      this->m_iRows = iVar8 + 1;
      SortPlayers(this,0,g_TeamInfo[(int)local_2c].name);
      iVar8 = this->m_iNumTeams;
    } while (0 < iVar8);
  }
  bVar2 = false;
  do {
                    /* Unresolved local var: bool bCreatedTeam@[???]
                       Unresolved local var: int highest_frags@[???]
                       Unresolved local var: int lowest_deaths@[???]
                       Unresolved local var: int best_player@[???] */
    peVar13 = g_PlayerExtraInfo + 1;
    local_24 = 0;
    phVar14 = g_PlayerInfoList + 1;
    local_28 = 99999;
                    /* Unresolved local var: int i@[???] */
    iVar8 = -99999;
    iVar10 = 1;
    do {
                    /* Unresolved local var: cl_entity_t * ent@[???] */
      while (((iVar5 = iVar10, this->m_bHasBeenSorted[iVar5] != false ||
              (phVar14->name == (char *)0x0)) ||
             ((peVar13->frags < iVar8 ||
              (pcVar7 = (*gEngfuncs.GetEntityByIndex)(iVar5), pcVar7 == (cl_entity_s *)0x0))))) {
LAB_0008dab8:
        phVar14 = phVar14 + 1;
        peVar13 = peVar13 + 1;
        iVar10 = iVar5 + 1;
        if (iVar5 + 1 == 0x40) goto LAB_0008db11;
      }
      psVar6 = &peVar13->frags;
                    /* Unresolved local var: extra_player_info_t * pl_info@[???] */
      if (iVar8 < *psVar6) {
        iVar10 = (int)peVar13->deaths;
      }
      else {
        iVar10 = (int)peVar13->deaths;
        if (local_28 <= peVar13->deaths) goto LAB_0008dab8;
      }
      local_28 = iVar10;
      phVar14 = phVar14 + 1;
      peVar13 = peVar13 + 1;
      iVar8 = (int)*psVar6;
      iVar10 = iVar5 + 1;
      local_24 = iVar5;
    } while (iVar5 + 1 != 0x40);
LAB_0008db11:
    if (local_24 == 0) {
      return;
    }
    iVar8 = this->m_iRows;
    if (!bVar2) {
      this->m_iIsATeam[iVar8] = 2;
      iVar8 = iVar8 + 1;
    }
    bVar2 = true;
    this->m_iSortedRows[iVar8] = local_24;
    this->m_bHasBeenSorted[local_24] = true;
    this->m_iRows = iVar8 + 1;
  } while( true );
}


// ScorePanel::SortPlayers  @ 0008d6b0  (line 415)

/* DWARF original prototype: void SortPlayers(ScorePanel * this, int iTeam, char * team) */

void __thiscall ScorePanel::SortPlayers(ScorePanel *this,int iTeam,char *team)

{
  cl_entity_s *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__s1;
  extra_player_info_t *peVar5;
  hud_player_info_t *phVar6;
  int local_28;
  int local_24;
  bool local_1d;
  
                    /* Unresolved local var: bool bCreatedTeam@[???] */
  local_1d = false;
  if (team == (char *)0x0) goto LAB_0008d7de;
  do {
                    /* Unresolved local var: int highest_frags@[???]
                       Unresolved local var: int lowest_deaths@[???]
                       Unresolved local var: int best_player@[???] */
    phVar6 = g_PlayerInfoList + 1;
    __s1 = g_PlayerExtraInfo[1].teamname;
    local_28 = 0;
                    /* Unresolved local var: int i@[???] */
    local_24 = 99999;
    iVar3 = -99999;
    iVar2 = 1;
    do {
                    /* Unresolved local var: cl_entity_t * ent@[???] */
      while ((((iVar4 = iVar2, this->m_bHasBeenSorted[iVar4] != false ||
               (phVar6->name == (char *)0x0)) ||
              (((extra_player_info_t *)(__s1 + -0xc))->frags < iVar3)) ||
             ((pcVar1 = (*gEngfuncs.GetEntityByIndex)(iVar4), pcVar1 == (cl_entity_s *)0x0 ||
              (iVar2 = strcasecmp(__s1,team), iVar2 != 0))))) {
LAB_0008d6f8:
        phVar6 = phVar6 + 1;
        __s1 = __s1 + 0x1c;
        iVar2 = iVar4 + 1;
        if (iVar4 + 1 == 0x40) goto LAB_0008d780;
      }
                    /* Unresolved local var: extra_player_info_t * pl_info@[???] */
      peVar5 = (extra_player_info_t *)(__s1 + -0xc);
      if (iVar3 < peVar5->frags) {
        iVar2 = (int)*(short *)(__s1 + -10);
      }
      else {
        iVar2 = (int)*(short *)(__s1 + -10);
        if (local_24 <= *(short *)(__s1 + -10)) goto LAB_0008d6f8;
      }
      local_24 = iVar2;
      phVar6 = phVar6 + 1;
      __s1 = __s1 + 0x1c;
      iVar3 = (int)peVar5->frags;
      iVar2 = iVar4 + 1;
      local_28 = iVar4;
    } while (iVar4 + 1 != 0x40);
LAB_0008d780:
    while( true ) {
      if (local_28 == 0) {
        if (team != (char *)0x0) {
          iVar3 = this->m_iRows;
          this->m_iRows = iVar3 + 1;
          this->m_iIsATeam[iVar3] = 3;
        }
        return;
      }
      iVar3 = this->m_iRows;
      if (local_1d < (iTeam != 0)) {
        local_1d = true;
        this->m_iIsATeam[iVar3] = iTeam;
        iVar3 = iVar3 + 1;
      }
      this->m_iSortedRows[iVar3] = local_28;
      this->m_bHasBeenSorted[local_28] = true;
      this->m_iRows = iVar3 + 1;
      if (team != (char *)0x0) break;
LAB_0008d7de:
      phVar6 = g_PlayerInfoList;
      peVar5 = g_PlayerExtraInfo;
      local_28 = 0;
      iVar2 = 1;
      local_24 = 99999;
      iVar3 = -99999;
      do {
        phVar6 = phVar6 + 1;
        peVar5 = peVar5 + 1;
        if (((this->m_bHasBeenSorted[iVar2] == false) && (phVar6->name != (char *)0x0)) &&
           ((iVar3 <= peVar5->frags &&
            (pcVar1 = (*gEngfuncs.GetEntityByIndex)(iVar2), pcVar1 != (cl_entity_s *)0x0)))) {
          if ((iVar3 < peVar5->frags) || (peVar5->deaths < local_24)) {
            iVar3 = (int)peVar5->frags;
            local_28 = iVar2;
            local_24 = (int)peVar5->deaths;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x40);
    }
  } while( true );
}


// ScorePanel::RebuildTeams  @ 00090ff0  (line 473)

/* WARNING: Removing unreachable block (ram,0x000911e1) */
/* WARNING: Removing unreachable block (ram,0x000911d1) */
/* WARNING: Removing unreachable block (ram,0x00091162) */
/* WARNING: Removing unreachable block (ram,0x00091144) */
/* WARNING: Removing unreachable block (ram,0x00091155) */
/* DWARF original prototype: void RebuildTeams(ScorePanel * this) */

void __thiscall ScorePanel::RebuildTeams(ScorePanel *this)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  team_info_t *__s2;
  int iVar6;
  char *__s1;
  hud_player_info_t *local_24;
  
                    /* Unresolved local var: int i@[???] */
  iVar5 = this->m_iNumTeams;
  if (0 < iVar5) {
    psVar2 = &g_TeamInfo[1].players;
    do {
      *psVar2 = 0;
      psVar2 = psVar2 + 0x14;
    } while (psVar2 != &g_TeamInfo[iVar5 + 1].players);
  }
  iVar5 = 0;
  TeamFortressViewport::GetAllPlayersInfo(gViewPort);
  local_24 = g_PlayerInfoList;
  this->m_iNumTeams = 0;
  __s1 = g_PlayerExtraInfo[1].teamname;
  do {
                    /* Unresolved local var: int j@[???] */
    local_24 = local_24 + 1;
    if ((local_24->name != (char *)0x0) && (*__s1 != '\0')) {
      if (iVar5 < 1) {
        iVar6 = 1;
LAB_00091192:
        this->m_iNumTeams = iVar6;
        strncpy(g_TeamInfo[iVar6].name,__s1,0x10);
        sVar1 = 1;
        g_TeamInfo[iVar6].players = 0;
        iVar5 = this->m_iNumTeams;
      }
      else if (g_TeamInfo[1].name[0] == '\0') {
        iVar6 = 1;
        sVar1 = g_TeamInfo[1].players + 1;
      }
      else {
        __s2 = g_TeamInfo + 1;
        iVar6 = 1;
        do {
          iVar3 = strcasecmp(__s1,__s2->name);
          if (iVar3 == 0) break;
          iVar6 = iVar6 + 1;
          if (iVar5 < iVar6) goto LAB_00091192;
          __s2 = __s2 + 1;
        } while (__s2->name[0] != '\0');
        sVar1 = g_TeamInfo[iVar6].players + 1;
      }
      g_TeamInfo[iVar6].players = sVar1;
    }
    __s1 = __s1 + 0x1c;
  } while (__s1 != g_PlayerExtraInfo[0x40].teamname);
  if (0 < iVar5) {
    iVar6 = 0x111808;
    iVar3 = 1;
    do {
      while (0 < *(short *)(iVar6 + 0x1a)) {
        iVar3 = iVar3 + 1;
        iVar6 = iVar6 + 0x28;
        if (iVar5 < iVar3) goto LAB_00091177;
      }
      uVar4 = 0;
      do {
        *(undefined4 *)(iVar6 + uVar4) = 0;
        *(undefined4 *)(iVar6 + 4 + uVar4) = 0;
        uVar4 = uVar4 + 8;
      } while (uVar4 < 0x28);
      iVar3 = iVar3 + 1;
      iVar6 = iVar6 + 0x28;
      iVar5 = this->m_iNumTeams;
    } while (iVar3 <= iVar5);
  }
LAB_00091177:
  Update(this);
  return;
}


// ScorePanel::FillGrid  @ 0008f940  (line 533)

/* DWARF original prototype: void FillGrid(ScorePanel * this) */

void __thiscall ScorePanel::FillGrid(ScorePanel *this)

{
  CSchemeManager *this_00;
  char cVar1;
  float fVar2;
  bool bVar3;
  SchemeHandle_t schemeHandle;
  SchemeHandle_t schemeHandle_00;
  SchemeHandle_t schemeHandle_01;
  Font *pFVar4;
  Font *pFVar5;
  Font *pFVar6;
  int *piVar7;
  CVoiceStatus *pCVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  code *pcVar12;
  undefined4 uVar13;
  char (*pacVar14) [32];
  int iVar15;
  int iVar16;
  CGrid *this_01;
  CGrid *pCVar17;
  Label *pLVar18;
  Label *pLVar19;
  int in_GS_OFFSET;
  char *pcVar20;
  undefined4 uVar21;
  int local_308;
  int *local_304;
  team_info_t *local_300;
  int local_2f8;
  hud_player_info_t *local_2f4;
  CGrid *local_2f0;
  Label *local_2e8;
  int local_2c4;
  int local_2c0;
  int local_2bc;
  int local_2b8;
  int local_2b4;
  int local_2b0;
  Color local_2ac [4];
  undefined4 local_2a8;
  undefined4 local_2a4;
  code *local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  char cStack_221;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  int local_20;
  
                    /* Unresolved local var: CSchemeManager * pSchemes@[???]
                       Unresolved local var: SchemeHandle_t hScheme@[???]
                       Unresolved local var: SchemeHandle_t hTitleScheme@[???]
                       Unresolved local var: SchemeHandle_t hSmallScheme@[???]
                       Unresolved local var: Font * sfont@[???]
                       Unresolved local var: Font * tfont@[???]
                       Unresolved local var: Font * smallfont@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: bool bNextRowIsGap@[???]
                       Unresolved local var: int row@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  this_00 = &gViewPort->m_SchemeManager;
  schemeHandle = CSchemeManager::getSchemeHandle(this_00,"Scoreboard Text");
  schemeHandle_00 = CSchemeManager::getSchemeHandle(this_00,"Scoreboard Title Text");
  schemeHandle_01 = CSchemeManager::getSchemeHandle(this_00,"Scoreboard Small Text");
  pFVar4 = CSchemeManager::getFont(this_00,schemeHandle);
  pFVar5 = CSchemeManager::getFont(this_00,schemeHandle_00);
  pFVar6 = CSchemeManager::getFont(this_00,schemeHandle_01);
  piVar7 = (int *)(**(code **)(*(int *)this + 0x14c))(this);
  (**(code **)(*piVar7 + 0x34))(piVar7,&local_2c4,&local_2c0);
  (**(code **)(*(int *)this + 0x200))(this,local_2c4,local_2c0,this);
  pCVar8 = GetClientVoiceMgr();
  bVar3 = CVoiceStatus::IsInSquelchMode(pCVar8);
  if (!bVar3) {
    this->m_iHighlightRow = -1;
  }
  local_2f8 = 0;
  this_01 = (CGrid *)&this->field_0xd20;
  local_304 = this->m_iSortedRows;
                    /* Unresolved local var: CGrid * pGridRow@[???]
                       Unresolved local var: bool bRowIsGap@[???]
                       Unresolved local var: int col@[???]
                       Unresolved local var: CLabelHeader * pLabel@[???]
                       Unresolved local var: int rowheight@[???]
                       Unresolved local var: char[128] sz@[???]
                       Unresolved local var: hud_player_info_t * pl_info@[???]
                       Unresolved local var: team_info_t * team_info@[???]
                       Unresolved local var: char[512] buf@[???]
                       Unresolved local var: int len@[???] */
  local_2f0 = this_01;
  local_2e8 = (Label *)this->m_PlayerEntries;
  do {
    vgui::CGrid::SetRowUnderline(local_2f0,0,false,0,0,0,0,0);
    if (local_2f8 < this->m_iRows) {
      local_308 = 0;
      pLVar18 = local_2e8;
      do {
        (**(code **)(*(int *)pLVar18 + 0x24))(pLVar18,1);
        (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x28) + 0x74))
                  (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x28),"");
        (**(code **)(*(int *)pLVar18 + 0x1fc))(pLVar18,0);
        if (*(code **)(*(int *)pLVar18 + 0x20c) == CLabelHeader::setFont) {
          (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x24) + 0x7c))
                    (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x24),pFVar4);
        }
        else {
          (**(code **)(*(int *)pLVar18 + 0x20c))(pLVar18,pFVar4);
        }
        iVar9 = 0xf;
        *(undefined4 *)(pLVar18 + 0xdc) = 0;
        *(undefined4 *)(pLVar18 + 0xe0) = 0;
        if (0x1e0 < gHUD.m_scrinfo.iHeight) {
          iVar9 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 13.0);
        }
        pcVar12 = *(code **)(*(int *)pLVar18 + 8);
        uVar10 = (**(code **)(*(int *)pLVar18 + 0x18))(pLVar18);
        (*pcVar12)(pLVar18,uVar10,iVar9);
        (**(code **)(*(int *)pLVar18 + 0x128))(pLVar18,0,0,0,0xff);
        iVar9 = local_304[0x4a];
        if (iVar9 == 3) {
          if (*(code **)(*(int *)pLVar18 + 0x22c) == CLabelHeader::setText) {
                    /* Unresolved local var: char[512] buf@[???]
                       Unresolved local var: int len@[???] */
            local_220 = (code *)CONCAT22(local_220._2_2_,0x20);
            iVar9 = isspace(0x20);
            if (iVar9 != 0) {
              local_220 = (code *)((uint)local_220 & 0xffffff00);
            }
                    /* Unresolved local var: Font * font@[???] */
            (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x24) + 0x74))
                      (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x24),&local_220);
            piVar7 = (int *)(**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x24) + 0x6c))
                                      (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x24));
            *(undefined4 *)(pLVar18 + 0xd8) = 0;
            pcVar20 = (char *)&local_220;
            cVar1 = (char)local_220;
                    /* Unresolved local var: char * ch@[???] */
            if ((char)local_220 == '\0') goto LAB_00090068;
            do {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
              (**(code **)(*piVar7 + 8))(piVar7,(int)cVar1,&local_2b8,&local_2b4,&local_2b0);
              cVar1 = pcVar20[1];
              iVar9 = local_2b4 + local_2b8 + local_2b0 + *(int *)(pLVar18 + 0xd8);
              *(int *)(pLVar18 + 0xd8) = iVar9;
              pcVar20 = pcVar20 + 1;
            } while (cVar1 != '\0');
LAB_00090001:
            fVar2 = (float)iVar9;
            goto LAB_00090009;
          }
          (**(code **)(*(int *)pLVar18 + 0x22c))(pLVar18,&DAT_000cae23);
        }
        else {
          if (iVar9 == 1) {
            iVar9 = *local_304;
            local_300 = g_TeamInfo + iVar9;
            iVar16 = g_TeamInfo[iVar9].teamnumber % iNumberOfTeamColors;
                    /* Unresolved local var: Color color@[???] */
            iVar11 = iTeamColors[iVar16][2];
            iVar15 = iTeamColors[iVar16][1];
            iVar16 = iTeamColors[iVar16][0];
            uVar10 = 0;
            if (*(code **)(*(int *)pLVar18 + 0x124) == CLabelHeader::setFgColor) {
              vgui::Label::setFgColor((int)pLVar18,iVar16,iVar15,iVar11);
              uVar10 = 0;
              vgui::Color::Color(local_2ac,iVar16,iVar15,iVar11,0);
              piVar7 = *(int **)(pLVar18 + 0xd0);
              local_2a0 = isalnum;
              local_29c = local_2a8;
              local_298 = local_2a4;
              if (*(code **)(*piVar7 + 0xc) == CTextImage2::setColor) {
                local_220 = isalnum;
                local_21c = local_2a8;
                local_218 = local_2a4;
                (**(code **)(*(int *)piVar7[9] + 0xc))((int *)piVar7[9],&local_220);
              }
              else {
                (**(code **)(*piVar7 + 0xc))(piVar7,&local_2a0);
              }
              local_29c = local_2a8;
              local_21c = local_2a8;
              local_220 = isalnum;
              local_218 = local_2a4;
              (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x28) + 0xc))
                        (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x28),&local_220);
              (**(code **)(*(int *)pLVar18 + 0x30))(pLVar18);
            }
            else {
              (**(code **)(*(int *)pLVar18 + 0x124))(pLVar18);
            }
            iVar15 = 0x14;
            if (0x1df < gHUD.m_scrinfo.iHeight) {
              iVar15 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 20.0);
            }
            pcVar12 = *(code **)(*(int *)pLVar18 + 8);
            uVar21 = (**(code **)(*(int *)pLVar18 + 0x18))(pLVar18);
            (*pcVar12)(pLVar18,uVar21,iVar15,iVar11,uVar10);
            if (*(code **)(*(int *)pLVar18 + 0x20c) == CLabelHeader::setFont) {
              (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x24) + 0x7c))
                        (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x24),pFVar5);
            }
            else {
              (**(code **)(*(int *)pLVar18 + 0x20c))(pLVar18,pFVar5);
            }
            iVar9 = g_TeamInfo[iVar9].teamnumber % iNumberOfTeamColors;
            vgui::CGrid::SetRowUnderline
                      (local_2f0,0,true,(int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 3.0),
                       iTeamColors[iVar9][0],iTeamColors[iVar9][1],iTeamColors[iVar9][2],0);
            local_2f4 = (hud_player_info_t *)0x0;
LAB_0008feb0:
            if (local_308 - 1U < 2) goto LAB_00090425;
LAB_0008febe:
            if (local_308 != 0) {
              (**(code **)(*(int *)pLVar18 + 0x21c))(pLVar18,5);
              goto LAB_0008fedf;
            }
            (**(code **)(*(int *)local_2e8 + 0x21c))(pLVar18,4);
            local_2a0 = (code *)((uint)local_2a0 & 0xffffff00);
            goto switchD_0009007d_caseD_0;
          }
          if (iVar9 != 2) {
            pcVar12 = *(code **)(*(int *)pLVar18 + 0x124);
            iVar15 = (int)g_PlayerExtraInfo[*local_304].teamnumber % iNumberOfTeamColors;
                    /* Unresolved local var: Color color@[???] */
            iVar9 = iTeamColors[iVar15][2];
            iVar11 = iTeamColors[iVar15][1];
            iVar15 = iTeamColors[iVar15][0];
            uVar10 = 0;
            if (pcVar12 == CLabelHeader::setFgColor) {
              vgui::Label::setFgColor((int)pLVar18,iVar15,iVar11,iVar9);
              uVar10 = 0;
              vgui::Color::Color(local_2ac,iVar15,iVar11,iVar9,0);
              piVar7 = *(int **)(pLVar18 + 0xd0);
              local_2a0 = isalnum;
              local_29c = local_2a8;
              local_298 = local_2a4;
              if (*(code **)(*piVar7 + 0xc) == CTextImage2::setColor) {
                local_220 = isalnum;
                local_21c = local_2a8;
                local_218 = local_2a4;
                (**(code **)(*(int *)piVar7[9] + 0xc))((int *)piVar7[9],&local_220);
              }
              else {
                (**(code **)(*piVar7 + 0xc))(piVar7,&local_2a0);
              }
              local_29c = local_2a8;
              local_21c = local_2a8;
              local_220 = isalnum;
              local_218 = local_2a4;
              (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x28) + 0xc))
                        (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x28),&local_220);
              (**(code **)(*(int *)pLVar18 + 0x30))(pLVar18);
            }
            else {
              (*pcVar12)(pLVar18);
            }
            iVar15 = *local_304;
            local_2f4 = g_PlayerInfoList + iVar15;
            if (g_PlayerInfoList[iVar15].thisplayer == '\0') {
              local_300 = (team_info_t *)0x0;
              if (((iVar15 == this->m_iLastKilledBy) && (this->m_fLastKillTime != 0)) &&
                 (fVar2 = (float)this->m_fLastKillTime, gHUD.m_flTime < fVar2)) {
                (**(code **)(*(int *)pLVar18 + 0x128))
                          (pLVar18,0xff,0,0,(int)(255.0 - (fVar2 - gHUD.m_flTime) * 15.0));
              }
            }
            else {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???] */
              if (*(code **)(*(int *)pLVar18 + 0x11c) == CLabelHeader::setFgColor) {
                vgui::Label::setFgColor((SchemeColor)pLVar18);
                vgui::Panel::getFgColor((int *)pLVar18,&local_2bc,&local_2b8,&local_2b4);
                iVar16 = local_2b0;
                iVar15 = local_2b4;
                iVar11 = local_2b8;
                iVar9 = local_2bc;
                    /* Unresolved local var: Color color@[???] */
                if (*(code **)(*(int *)pLVar18 + 0x124) == CLabelHeader::setFgColor) {
                  vgui::Label::setFgColor((int)pLVar18,local_2bc,local_2b8,local_2b4);
                  vgui::Color::Color(local_2ac,iVar9,iVar11,iVar15,iVar16);
                  piVar7 = *(int **)(pLVar18 + 0xd0);
                  local_2a0 = isalnum;
                  local_29c = local_2a8;
                  local_298 = local_2a4;
                  if (*(code **)(*piVar7 + 0xc) == CTextImage2::setColor) {
                    local_220 = isalnum;
                    local_21c = local_2a8;
                    local_218 = local_2a4;
                    (**(code **)(*(int *)piVar7[9] + 0xc))((int *)piVar7[9],&local_220);
                  }
                  else {
                    (**(code **)(*piVar7 + 0xc))(piVar7,&local_2a0);
                  }
                  local_29c = local_2a8;
                  local_21c = local_2a8;
                  local_220 = isalnum;
                  local_218 = local_2a4;
                  (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x28) + 0xc))
                            (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x28),&local_220);
                  (**(code **)(*(int *)pLVar18 + 0x30))(pLVar18);
                }
                else {
                  (**(code **)(*(int *)pLVar18 + 0x124))
                            (pLVar18,local_2bc,local_2b8,local_2b4,local_2b0);
                }
              }
              else {
                (**(code **)(*(int *)pLVar18 + 0x11c))(pLVar18,2,iVar11,iVar9,uVar10);
              }
              iVar9 = (int)g_PlayerExtraInfo[*local_304].teamnumber % iNumberOfTeamColors;
              (**(code **)(*(int *)pLVar18 + 0x128))
                        (pLVar18,iTeamColors[iVar9][0],iTeamColors[iVar9][1],iTeamColors[iVar9][2],
                         0xc4);
              local_300 = (team_info_t *)0x0;
            }
            goto LAB_0008feb0;
          }
          pcVar12 = *(code **)(*(int *)pLVar18 + 0x124);
                    /* Unresolved local var: Color color@[???] */
          uVar21 = 0;
          uVar10 = 100;
          if (pcVar12 == CLabelHeader::setFgColor) {
            vgui::Label::setFgColor((int)pLVar18,100,100,100);
            uVar21 = 0;
            uVar10 = 100;
            vgui::Color::Color(local_2ac,100,100,100,0);
            piVar7 = *(int **)(pLVar18 + 0xd0);
            local_2a0 = isalnum;
            local_29c = local_2a8;
            local_298 = local_2a4;
            if (*(code **)(*piVar7 + 0xc) == CTextImage2::setColor) {
              local_220 = isalnum;
              local_21c = local_2a8;
              local_218 = local_2a4;
              (**(code **)(*(int *)piVar7[9] + 0xc))((int *)piVar7[9],&local_220);
            }
            else {
              (**(code **)(*piVar7 + 0xc))(piVar7,&local_2a0);
            }
            local_29c = local_2a8;
            local_21c = local_2a8;
            local_220 = isalnum;
            local_218 = local_2a4;
            (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x28) + 0xc))
                      (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x28),&local_220);
            (**(code **)(*(int *)pLVar18 + 0x30))(pLVar18);
          }
          else {
            (*pcVar12)();
          }
          iVar9 = 0x14;
          if (0x1df < gHUD.m_scrinfo.iHeight) {
            iVar9 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 20.0);
          }
          pcVar12 = *(code **)(*(int *)pLVar18 + 8);
          uVar13 = (**(code **)(*(int *)pLVar18 + 0x18))(pLVar18);
          (*pcVar12)(pLVar18,uVar13,iVar9,uVar10,uVar21);
          if (*(code **)(*(int *)pLVar18 + 0x20c) == CLabelHeader::setFont) {
            (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x24) + 0x7c))
                      (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x24),pFVar5);
          }
          else {
            (**(code **)(*(int *)pLVar18 + 0x20c))(pLVar18,pFVar5);
          }
          vgui::CGrid::SetRowUnderline
                    (local_2f0,0,true,(int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 3.0),100,100,
                     100,0);
          local_300 = (team_info_t *)0x0;
          local_2f4 = (hud_player_info_t *)0x0;
          if (1 < local_308 - 1U) goto LAB_0008febe;
LAB_00090425:
          (**(code **)(*(int *)pLVar18 + 0x21c))(pLVar18,3);
LAB_0008fedf:
          local_2a0 = (code *)((uint)local_2a0 & 0xffffff00);
          iVar9 = local_304[0x4a];
          if (iVar9 != 0) {
                    /* Unresolved local var: char[128] sz2@[???] */
            if (local_308 == 3) {
              if (iVar9 == 1) {
                iVar9 = (int)local_300->frags;
                goto LAB_000900ab;
              }
            }
            else if (local_308 < 4) {
              if (local_308 == 1) {
                if (iVar9 == 2) {
                  pacVar14 = (char (*) [32])
                             CHudTextMessage::BufferedLocaliseTextString("#Spectators");
                }
                else {
                  pacVar14 = gViewPort->m_sTeamNames + local_300->teamnumber;
                }
                __sprintf_chk(&local_220,1,0x80,pacVar14);
                __strcpy_chk(&local_2a0,&local_220,0x80);
                if (local_304[0x4a] == 1) {
                  if (local_300->players == 1) {
                    pcVar20 = "#Player";
                  }
                  else {
                    pcVar20 = "#Player_plural";
                  }
                  pcVar20 = CHudTextMessage::BufferedLocaliseTextString(pcVar20);
                  __sprintf_chk(&local_220,1,0x80,"(%d %s)",(int)local_300->players,pcVar20);
                  (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x28) + 0x74))
                            (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x28),&local_220);
                  (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x28) + 0x7c))
                            (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x28),pFVar6);
                }
              }
            }
            else if (local_308 == 4) {
              if (iVar9 == 1) {
                iVar9 = (int)local_300->deaths;
                goto LAB_000900ab;
              }
            }
            else if ((local_308 == 5) && (iVar9 == 1)) {
              iVar9 = (int)local_300->ping;
              goto LAB_000900ab;
            }
            goto switchD_0009007d_caseD_0;
          }
                    /* Unresolved local var: bool bShowClass@[???] */
          switch(local_308) {
          case 1:
            __sprintf_chk(&local_2a0,1,0x80,&DAT_000c6338,local_2f4->name);
            break;
          case 2:
            if ((((gViewPort != (TeamFortressViewport *)0x0) &&
                 (iVar9 = EV_TFC_IsAllyTeam(g_iTeamNumber,
                                            (int)g_PlayerExtraInfo[*local_304].teamnumber),
                 iVar9 != 0)) && (g_iTeamNumber != 0)) || (g_iUser1 != 0)) {
                    /* Unresolved local var: bool bNoClass@[???] */
              if ((g_PlayerExtraInfo[*local_304].playerclass != 0) ||
                 (gViewPort->m_iValidClasses[g_PlayerExtraInfo[*local_304].teamnumber] == -1)) {
                pcVar20 = CHudTextMessage::BufferedLocaliseTextString
                                    (sLocalisedClasses[g_PlayerExtraInfo[*local_304].playerclass]);
                __sprintf_chk(&local_2a0,1,0x80,&DAT_000c4b6e,pcVar20);
                break;
              }
            }
            local_2a0 = (code *)((uint)local_2a0 & 0xffffff00);
            break;
          case 3:
            if (g_PlayerExtraInfo[*local_304].teamnumber == 0) break;
            iVar9 = (int)g_PlayerExtraInfo[*local_304].frags;
LAB_000900ab:
            __sprintf_chk(&local_2a0,1,0x80,"%d",iVar9);
            pcVar12 = *(code **)(*(int *)pLVar18 + 0x22c);
            if (pcVar12 == CLabelHeader::setText) goto LAB_0008ff44;
            goto LAB_000900f0;
          case 4:
            if (g_PlayerExtraInfo[*local_304].teamnumber != 0) {
              iVar9 = (int)g_PlayerExtraInfo[*local_304].deaths;
              goto LAB_000900ab;
            }
            break;
          case 5:
            if (g_PlayerExtraInfo[*local_304].teamnumber != 0) {
              iVar9 = (int)g_PlayerInfoList[*local_304].ping;
              goto LAB_000900ab;
            }
            break;
          case 6:
            iVar9 = *local_304;
            pCVar8 = GetClientVoiceMgr();
            CVoiceStatus::UpdateSpeakerImage(pCVar8,pLVar18,iVar9);
          }
switchD_0009007d_caseD_0:
          pcVar12 = *(code **)(*(int *)pLVar18 + 0x22c);
          if (pcVar12 == CLabelHeader::setText) {
LAB_0008ff44:
            iVar9 = __stpcpy_chk(&local_220,&local_2a0,0x200);
            iVar9 = iVar9 - (int)&local_220;
            while (iVar9 != 0) {
              iVar9 = iVar9 + -1;
              iVar11 = isspace((int)*(char *)((int)&local_220 + iVar9));
              if (iVar11 == 0) break;
              *(char *)((int)&local_220 + iVar9) = '\0';
            }
                    /* Unresolved local var: Font * font@[???] */
            (**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x24) + 0x74))
                      (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x24),&local_220);
            piVar7 = (int *)(**(code **)(**(int **)(*(int *)(pLVar18 + 0xd0) + 0x24) + 0x6c))
                                      (*(int **)(*(int *)(pLVar18 + 0xd0) + 0x24));
            *(undefined4 *)(pLVar18 + 0xd8) = 0;
            pcVar20 = (char *)&local_220;
            cVar1 = (char)local_220;
                    /* Unresolved local var: char * ch@[???] */
            if ((char)local_220 != '\0') {
              do {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
                (**(code **)(*piVar7 + 8))(piVar7,(int)cVar1,&local_2b8,&local_2b4,&local_2b0);
                cVar1 = pcVar20[1];
                iVar9 = local_2b4 + local_2b8 + local_2b0 + *(int *)(pLVar18 + 0xd8);
                *(int *)(pLVar18 + 0xd8) = iVar9;
                pcVar20 = pcVar20 + 1;
              } while (cVar1 != '\0');
              goto LAB_00090001;
            }
LAB_00090068:
            fVar2 = 0.0;
LAB_00090009:
            *(int *)(pLVar18 + 0xd8) = (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 5.0 + fVar2);
          }
          else {
LAB_000900f0:
            (*pcVar12)(pLVar18,&local_2a0);
          }
        }
        local_308 = local_308 + 1;
        pLVar18 = pLVar18 + 0x4310;
      } while (local_308 != 8);
    }
    else {
      pLVar18 = local_2e8;
      do {
                    /* Unresolved local var: int col@[???] */
        pLVar19 = pLVar18 + 0x4310;
        (**(code **)(*(int *)pLVar18 + 0x24))(pLVar18,0);
        pLVar18 = pLVar19;
      } while (local_2e8 + 0x21880 != pLVar19);
    }
    local_2f8 = local_2f8 + 1;
    local_2f0 = local_2f0 + 1;
    local_2e8 = local_2e8 + 0xe8;
    local_304 = local_304 + 1;
    if (local_2f8 == 0x4a) {
      do {
                    /* Unresolved local var: CGrid * pGridRow@[???] */
        vgui::CGrid::AutoSetRowHeights(this_01);
        pcVar12 = *(code **)(*(int *)this_01 + 8);
        iVar9 = vgui::CGrid::CalcDrawHeight(this_01);
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???] */
        (**(code **)(*(int *)this_01 + 0x14))(this_01,&local_2bc,&local_2b8,&local_2b4,&local_2b0);
        (*pcVar12)(this_01,local_2b4,iVar9);
        pCVar17 = this_01 + 1;
        vgui::CGrid::RepositionContents(this_01);
        this_01 = pCVar17;
      } while (pCVar17 != (CGrid *)this->m_PlayerEntries);
      vgui::Panel::getSize((int *)&this->m_PlayerList,&local_2c4);
      vgui::CListBox::setSize(&this->m_PlayerList,local_2c4,local_2c0);
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  } while( true );
}


// ScorePanel::DeathMsg  @ 0008dbf0  (line 879)

/* DWARF original prototype: void DeathMsg(ScorePanel * this, int killer, int victim) */

void __thiscall ScorePanel::DeathMsg(ScorePanel *this,int killer,int victim)

{
  int iVar1;
  float fVar2;
  int iVar3;
  
  iVar1 = this->m_iPlayerNum;
  iVar3 = iVar1;
  if (iVar1 == victim) {
    if (killer != 0) {
      iVar3 = killer;
    }
  }
  else if (killer != 0) {
    return;
  }
  fVar2 = gHUD.m_flTime + 10.0;
  this->m_iLastKilledBy = iVar3;
  this->m_fLastKillTime = (int)fVar2;
  if (iVar1 != killer) {
    return;
  }
  this->m_iLastKilledBy = iVar1;
  return;
}


// ScorePanel::Open  @ 00091210  (line 893)

/* DWARF original prototype: void Open(ScorePanel * this) */

void __thiscall ScorePanel::Open(ScorePanel *this)

{
  RebuildTeams(this);
  (**(code **)(*(int *)this + 0x24))(this,1);
  vgui::Panel::setVisible((bool)((char)this + '`'));
  return;
}


// ScorePanel::mousePressed  @ 0008d1e0  (line 900)

/* DWARF original prototype: void mousePressed(ScorePanel * this, MouseCode code, Panel * panel) */

void __thiscall ScorePanel::mousePressed(ScorePanel *this,MouseCode code,Panel *panel)

{
  int iPlayer;
  bool bVar1;
  int in_EAX;
  CVoiceStatus *pCVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint *puVar6;
  int in_GS_OFFSET;
  uint local_910 [64];
  undefined1 local_810 [1024];
  undefined1 local_410 [1024];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: int iPlayer@[???] */
                    /* Unresolved local var: hud_player_info_t * pl_info@[???] */
  if ((((-1 < *(int *)(in_EAX + 0x9b4)) &&
       (iPlayer = *(int *)(in_EAX + 0x26734 + *(int *)(in_EAX + 0x9b4) * 4), 0 < iPlayer)) &&
      (iPlayer * 0x1c != -0xf5500)) &&
     ((g_PlayerInfoList[iPlayer].name != (char *)0x0 && (*g_PlayerInfoList[iPlayer].name != '\0'))))
  {
                    /* Unresolved local var: char[256] string@[???] */
    pCVar2 = GetClientVoiceMgr();
    bVar1 = CVoiceStatus::IsPlayerBlocked(pCVar2,iPlayer);
    if (bVar1) {
                    /* Unresolved local var: char[1024] string1@[???] */
      pCVar2 = GetClientVoiceMgr();
      CVoiceStatus::SetPlayerBlockedState(pCVar2,iPlayer,false);
      pcVar4 = g_PlayerInfoList[iPlayer].name;
      pcVar3 = CHudTextMessage::BufferedLocaliseTextString("#Unmuted");
      __sprintf_chk(local_410,1,0x400,pcVar3,pcVar4);
      puVar6 = local_910;
      __sprintf_chk(puVar6,1,0x100,"%c** %s\n",3,local_410);
      do {
        uVar5 = *puVar6;
        puVar6 = puVar6 + 1;
        uVar5 = uVar5 + 0xfefefeff & ~uVar5 & 0x80808080;
      } while (uVar5 == 0);
    }
    else {
                    /* Unresolved local var: char[1024] string1@[???]
                       Unresolved local var: char[1024] string2@[???] */
      pCVar2 = GetClientVoiceMgr();
      CVoiceStatus::SetPlayerBlockedState(pCVar2,iPlayer,true);
      pcVar4 = g_PlayerInfoList[iPlayer].name;
      pcVar3 = CHudTextMessage::BufferedLocaliseTextString("#Muted");
      __sprintf_chk(local_810,1,0x400,pcVar3,pcVar4);
      pcVar4 = CHudTextMessage::BufferedLocaliseTextString("#No_longer_hear_that_player");
      __sprintf_chk(local_410,1,0x400,pcVar4);
      puVar6 = local_910;
      __sprintf_chk(puVar6,1,0x100,"%c** %s %s\n",3,local_810,local_410);
      do {
        uVar5 = *puVar6;
        puVar6 = puVar6 + 1;
        uVar5 = uVar5 + 0xfefefeff & ~uVar5 & 0x80808080;
      } while (uVar5 == 0);
    }
    if ((uVar5 & 0x8080) == 0) {
      puVar6 = (uint *)((int)puVar6 + 2);
      uVar5 = uVar5 >> 0x10;
    }
    CHudTextMessage::MsgFunc_TextMsg
              (&gHUD.m_TextMessage,(char *)0x0,
               (int)puVar6 + (-(int)local_910 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) + -2,
               local_910);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ScorePanel::mousePressed  @ 0008d430  (line 901)

/* DWARF original prototype: void mousePressed(ScorePanel * this, MouseCode code, Panel * panel) */

void __thiscall ScorePanel::mousePressed(ScorePanel *this,MouseCode code,Panel *panel)

{
  bool bVar1;
  CVoiceStatus *pCVar2;
  
  if (gHUD.m_iIntermission != 0) {
    return;
  }
  pCVar2 = GetClientVoiceMgr();
  bVar1 = CVoiceStatus::IsInSquelchMode(pCVar2);
  if (bVar1) {
    mousePressed(this,code,panel);
    return;
  }
  pCVar2 = GetClientVoiceMgr();
  this._0_1_ = (bool)((char)this + '`');
  CVoiceStatus::StartSquelchMode(pCVar2);
  vgui::Panel::setVisible(this._0_1_);
  return;
}


// ScorePanel::cursorMoved  @ 0008d4b0  (line 954)

/* DWARF original prototype: void cursorMoved(ScorePanel * this, int x, int y, Panel * panel) */

void __thiscall ScorePanel::cursorMoved(ScorePanel *this,int x,int y,Panel *panel)

{
  bool bVar1;
  CVoiceStatus *this_00;
  int iVar2;
  int iVar3;
  CLabelHeader *pCVar4;
  CGrid *this_01;
  int local_24;
  int local_20 [4];
  
  this_00 = GetClientVoiceMgr();
  bVar1 = CVoiceStatus::IsInSquelchMode(this_00);
  if (bVar1) {
    this_01 = (CGrid *)&this->field_0xd20;
    iVar3 = 0;
    do {
                    /* Unresolved local var: int row@[???]
                       Unresolved local var: int col@[???] */
      bVar1 = vgui::CGrid::getCellAtPoint(this_01,x,y,&local_24,local_20);
      if (bVar1) {
                    /* Unresolved local var: CLabelHeader * label@[???]
                       Unresolved local var: hud_player_info_t * pl_info@[???] */
        pCVar4 = this->m_PlayerEntries[local_20[0]] + iVar3;
        if (pCVar4 != this->m_pCurrentHighlightLabel) {
          this->m_pCurrentHighlightLabel = (CLabelHeader *)0x0;
          this->m_iHighlightRow = -1;
        }
        if (pCVar4 == (CLabelHeader *)0x0) {
          return;
        }
        if (*(int *)((int)&__DT_REL[0x1687].r_offset +
                    (int)(&this->m_PlayerEntries[0][0].super_Label + iVar3 * 4)) != 0) {
          return;
        }
        iVar2 = *(int *)((int)&__DT_REL[0x1662].r_offset +
                        (int)(&this->m_PlayerEntries[0][0].super_Label + iVar3 * 4));
        if (g_PlayerInfoList[iVar2].name == (char *)0x0) {
          return;
        }
        if (*g_PlayerInfoList[iVar2].name == '\0') {
          return;
        }
        if ((g_PlayerInfoList[iVar2].thisplayer != '\0') &&
           (iVar2 = (*gEngfuncs.IsSpectateOnly)(), iVar2 == 0)) {
          return;
        }
        this->m_pCurrentHighlightLabel = pCVar4;
        this->m_iHighlightRow = iVar3;
        return;
      }
                    /* Unresolved local var: int i@[???] */
      iVar3 = iVar3 + 1;
      this_01 = this_01 + 1;
    } while (iVar3 != 0x4a);
  }
  return;
}


// ScorePanel::MouseOverCell  @ 0008dc60  (line 976)

/* DWARF original prototype: void MouseOverCell(ScorePanel * this, int row, int col) */

void __thiscall ScorePanel::MouseOverCell(ScorePanel *this,int row,int col)

{
  int iVar1;
  CLabelHeader *pCVar2;
  
                    /* Unresolved local var: CLabelHeader * label@[???]
                       Unresolved local var: hud_player_info_t * pl_info@[???] */
  pCVar2 = this->m_PlayerEntries[col] + row;
  if (pCVar2 != this->m_pCurrentHighlightLabel) {
    this->m_pCurrentHighlightLabel = (CLabelHeader *)0x0;
    this->m_iHighlightRow = -1;
  }
  if ((pCVar2 != (CLabelHeader *)0x0) &&
     (*(int *)((int)&__DT_REL[0x1687].r_offset +
              (int)(&this->m_PlayerEntries[0][0].super_Label + row * 4)) == 0)) {
    iVar1 = *(int *)((int)&__DT_REL[0x1662].r_offset +
                    (int)(&this->m_PlayerEntries[0][0].super_Label + row * 4));
    if (((g_PlayerInfoList[iVar1].name != (char *)0x0) && (*g_PlayerInfoList[iVar1].name != '\0'))
       && ((g_PlayerInfoList[iVar1].thisplayer == '\0' ||
           (iVar1 = (*gEngfuncs.IsSpectateOnly)(), iVar1 != 0)))) {
      this->m_pCurrentHighlightLabel = pCVar2;
      this->m_iHighlightRow = row;
    }
  }
  return;
}


// CLabelHeader::paintBackground  @ 0008d110  (line 1009)

/* DWARF original prototype: void paintBackground(CLabelHeader * this) */

void __thiscall CLabelHeader::paintBackground(CLabelHeader *this)

{
  int in_GS_OFFSET;
  Color local_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  code *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
                    /* Unresolved local var: Color oldBg@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Color::Color(local_28);
  (**(code **)(*(int *)this + 0x13c))(this,local_28);
  if (gViewPort->m_pScoreBoard->m_iHighlightRow == this->_row) {
    (**(code **)(*(int *)this + 0x128))(this,0x86,0x5b,0x13,0);
  }
  vgui::Panel::paintBackground();
  local_1c = isalnum;
  local_18 = local_24;
  local_14 = local_20;
  (**(code **)(*(int *)this + 0x134))(this,&local_1c);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CLabelHeader::paint  @ 0008de70  (line 1028)

/* DWARF original prototype: void paint(CLabelHeader * this) */

void __thiscall CLabelHeader::paint(CLabelHeader *this)

{
  CTextImage2 *pCVar1;
  TextImage *pTVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_GS_OFFSET;
  int *local_84;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  Color local_50 [12];
  Color local_44 [4];
  undefined4 local_40;
  undefined4 local_3c;
  code *local_38;
  undefined4 local_34;
  undefined4 local_30;
  code *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
                    /* Unresolved local var: Color oldFg@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int iwide@[???]
                       Unresolved local var: int itall@[???]
                       Unresolved local var: int x1@[???]
                       Unresolved local var: int y1@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  vgui::Color::Color(local_50);
  (**(code **)(*(int *)this + 0x140))(this,local_50);
  if (gViewPort->m_pScoreBoard->m_iHighlightRow == this->_row) {
                    /* Unresolved local var: Color color@[???] */
    if (*(code **)(*(int *)this + 0x124) == setFgColor) {
      vgui::Label::setFgColor((int)this,0xff,0xff,0xff);
      vgui::Color::Color(local_44,0xff,0xff,0xff,0);
      pCVar1 = this->_dualImage;
      local_38 = isalnum;
      local_34 = local_40;
      local_30 = local_3c;
      if (*(code **)(*(int *)pCVar1 + 0xc) == CTextImage2::setColor) {
        local_28 = local_40;
        local_2c = isalnum;
        local_24 = local_3c;
        (**(code **)(*(int *)pCVar1->_image[0] + 0xc))(pCVar1->_image[0],&local_2c);
      }
      else {
        (**(code **)(*(int *)pCVar1 + 0xc))(pCVar1,&local_38);
      }
      local_34 = local_40;
      pTVar2 = this->_dualImage->_image[1];
      local_28 = local_40;
      local_2c = isalnum;
      local_24 = local_3c;
      (**(code **)(*(int *)pTVar2 + 0xc))(pTVar2,&local_2c);
      (**(code **)(*(int *)this + 0x30))(this);
    }
    else {
      (**(code **)(*(int *)this + 0x124))();
    }
  }
  if (*(code **)(*(int *)this + 0x210) == getTextSize) {
    pCVar1 = this->_dualImage;
    if (*(code **)(*(int *)pCVar1 + 8) == CTextImage2::getSize) {
                    /* Unresolved local var: int w1@[???]
                       Unresolved local var: int w2@[???]
                       Unresolved local var: int t1@[???]
                       Unresolved local var: int t2@[???] */
      (**(code **)(*(int *)pCVar1->_image[0] + 100))(pCVar1->_image[0],&local_60,&local_58);
      (**(code **)(*(int *)pCVar1->_image[1] + 100))(pCVar1->_image[1],&local_5c,&local_54);
      local_68 = local_5c + local_60;
      local_64 = local_54;
      if (local_54 <= local_58) {
        local_64 = local_58;
      }
      (**(code **)(*(int *)pCVar1 + 0x14))(pCVar1,local_68,local_64);
    }
    else {
      (**(code **)(*(int *)pCVar1 + 8))(pCVar1,&local_68,&local_64);
    }
  }
  else {
    (**(code **)(*(int *)this + 0x210))(this,&local_68,&local_64);
  }
  local_84 = &local_58;
  calcAlignment(this,local_68,local_64,&local_70,&local_6c);
  iVar5 = local_6c;
  iVar4 = local_70;
  pCVar1 = this->_dualImage;
  if ((code *)**(undefined4 **)pCVar1 == CTextImage2::setPos) {
                    /* Unresolved local var: int swide@[???]
                       Unresolved local var: int stall@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
    (*(code *)**(undefined4 **)pCVar1->_image[0])(pCVar1->_image[0],local_70,local_6c);
    (**(code **)(*(int *)pCVar1->_image[0] + 8))(pCVar1->_image[0],&local_60,&local_5c);
    (**(code **)(*(int *)pCVar1->_image[1] + 8))(pCVar1->_image[1],local_84,&local_54);
    (*(code *)**(undefined4 **)pCVar1->_image[1])
              (pCVar1->_image[1],local_58 + iVar4,
               (int)(((double)iVar5 + (double)local_5c * 0.9) - (double)local_54));
  }
  else {
    (*(code *)**(undefined4 **)pCVar1)(pCVar1,local_70,local_6c);
  }
  pTVar2 = this->_dualImage->_image[1];
  (**(code **)(*(int *)pTVar2 + 4))(pTVar2,local_84,&local_54);
  pTVar2 = this->_dualImage->_image[1];
  (*(code *)**(undefined4 **)pTVar2)(pTVar2,this->_gap,local_54);
  pCVar1 = this->_dualImage;
  if (*(code **)(*(int *)pCVar1 + 0x5c) == CTextImage2::doPaint) {
    (**(code **)(*(int *)pCVar1->_image[0] + 0x5c))(pCVar1->_image[0],this);
    (**(code **)(*(int *)pCVar1->_image[1] + 0x5c))(pCVar1->_image[1],this);
  }
  else {
    (**(code **)(*(int *)pCVar1 + 0x5c))(pCVar1,this);
  }
  if (*(int *)&this->field_0xcc != 0) {
                    /* Unresolved local var: Color imgColor@[???] */
    vgui::Color::Color((Color *)&local_38);
    (**(code **)(*(int *)this + 0x140))(this,(Color *)&local_38);
    if (this->_useFgColorAsImageColor != false) {
      local_28 = local_34;
      local_2c = isalnum;
      local_24 = local_30;
      (**(code **)(**(int **)&this->field_0xcc + 0xc))(*(int **)&this->field_0xcc,&local_2c);
    }
    (**(code **)(**(int **)&this->field_0xcc + 8))(*(int **)&this->field_0xcc,&local_68,&local_64);
    calcAlignment(this,local_68,local_64,&local_70,&local_6c);
    (**(code **)**(undefined4 **)&this->field_0xcc)
              (*(undefined4 **)&this->field_0xcc,local_70,local_6c);
    (**(code **)(**(int **)&this->field_0xcc + 0x5c))(*(int **)&this->field_0xcc,this);
  }
  pcVar3 = *(code **)(*(int *)this + 0x124);
  iVar4 = vgui::Color::operator[]((int)local_50);
  iVar5 = vgui::Color::operator[]((int)local_50);
  iVar6 = vgui::Color::operator[]((int)local_50);
  iVar7 = vgui::Color::operator[]((int)local_50);
                    /* Unresolved local var: Color color@[???] */
  if (pcVar3 == setFgColor) {
    vgui::Label::setFgColor((int)this,iVar7,iVar6,iVar5);
    vgui::Color::Color(local_44,iVar7,iVar6,iVar5,iVar4);
    pCVar1 = this->_dualImage;
    local_38 = isalnum;
    local_34 = local_40;
    local_30 = local_3c;
    if (*(code **)(*(int *)pCVar1 + 0xc) == CTextImage2::setColor) {
      local_28 = local_40;
      local_2c = isalnum;
      local_24 = local_3c;
      (**(code **)(*(int *)pCVar1->_image[0] + 0xc))(pCVar1->_image[0],&local_2c);
    }
    else {
      (**(code **)(*(int *)pCVar1 + 0xc))(pCVar1,&local_38);
    }
    local_34 = local_40;
    pTVar2 = this->_dualImage->_image[1];
    local_28 = local_40;
    local_2c = isalnum;
    local_24 = local_3c;
    (**(code **)(*(int *)pTVar2 + 0xc))(pTVar2,&local_2c);
    (**(code **)(*(int *)this + 0x30))(this);
  }
  else {
    (*pcVar3)(this);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CLabelHeader::calcAlignment  @ 0008dd20  (line 1070)

/* DWARF original prototype: void calcAlignment(CLabelHeader * this, int iwide, int itall, int * x,
   int * y) */

void __thiscall CLabelHeader::calcAlignment(CLabelHeader *this,int iwide,int itall,int *x,int *y)

{
  uint uVar1;
  int iVar2;
  int local_14;
  int local_10;
  
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  (**(code **)(*(int *)this + 0xc))(this,&local_14,&local_10);
  *x = 0;
  *y = 0;
  if (*(uint *)&this->field_0xc4 < 9) {
    uVar1 = 1 << ((byte)*(uint *)&this->field_0xc4 & 0x1f);
    if ((uVar1 & 0x124) == 0) {
      if ((uVar1 & 0x92) != 0) {
        *x = (local_14 - iwide) / 2;
        goto LAB_0008dd86;
      }
      if ((uVar1 & 0x49) != 0) {
        *x = 0;
        if (8 < *(uint *)&this->field_0xc4) {
          iVar2 = 0;
          goto LAB_0008ddcc;
        }
        uVar1 = 1 << ((byte)*(uint *)&this->field_0xc4 & 0x1f);
      }
    }
    else {
      *x = local_14 - iwide;
LAB_0008dd86:
      if (8 < *(uint *)&this->field_0xc4) goto LAB_0008ddc0;
      uVar1 = 1 << ((byte)*(uint *)&this->field_0xc4 & 0x1f);
    }
    if ((uVar1 & 0x1c0) == 0) {
      if ((uVar1 & 0x38) == 0) {
        if ((uVar1 & 7) != 0) {
          *y = 0;
        }
      }
      else {
        *y = (local_10 - itall) / 2;
      }
    }
    else {
      *y = local_10 - itall;
    }
  }
LAB_0008ddc0:
  iVar2 = *x;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
LAB_0008ddcc:
  *x = iVar2;
  *x = iVar2 + this->_offset[0];
  *y = *y + this->_offset[1];
  return;
}


