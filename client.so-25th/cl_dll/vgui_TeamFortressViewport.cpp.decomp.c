// Ghidra decompilation of functions from cl_dll/vgui_TeamFortressViewport.cpp
// 82 functions, ordered by original source line

// GetVGUITGAName  @ 00093690  (line 174)

char * GetVGUITGAName(char *pszName)

{
  undefined4 uVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  undefined1 local_110 [256];
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] sz@[???]
                       Unresolved local var: char * gamedir@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = 0x140;
  if (0x27f < gHUD.m_scrinfo.iWidth) {
    uVar1 = 0x280;
  }
  __sprintf_chk(local_110,1,0x100,pszName,uVar1);
  pcVar2 = (*gEngfuncs.pfnGetGameDirectory)();
  __sprintf_chk(GetVGUITGAName::gd,1,0x100,&DAT_000c7587,pcVar2,local_110);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return GetVGUITGAName::gd;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CCommandMenu::AddButton  @ 00093750  (line 196)

/* DWARF original prototype: void AddButton(CCommandMenu * this, CommandButton * pButton) */

void __thiscall CCommandMenu::AddButton(CCommandMenu *this,CommandButton *pButton)

{
  int iVar1;
  CommandButton *this_00;
  
  this_00 = pButton;
  iVar1 = this->m_iButtons;
  if (99 < iVar1) {
    return;
  }
  this->m_aButtons[iVar1] = pButton;
  this->m_iButtons = iVar1 + 1;
  (**(code **)(*(int *)pButton + 0x40))(pButton,this);
  (**(code **)(*(int *)pButton + 0x208))(pButton,3);
  iVar1 = this->m_iButtons;
  if (iVar1 < 10) {
    pButton._0_1_ = (char)iVar1 + '0';
  }
  else {
    if (iVar1 != 10) {
      return;
    }
    pButton._0_1_ = '0';
  }
  CommandButton::setBoundKey(this_00,(char)pButton);
  return;
}


// CCommandMenu::RemoveAllButtons  @ 000937f0  (line 217)

/* DWARF original prototype: void RemoveAllButtons(CCommandMenu * this) */

void __thiscall CCommandMenu::RemoveAllButtons(CCommandMenu *this)

{
  (**(code **)(*(int *)this + 0x108))(this);
  this->m_iButtons = 0;
  return;
}


// CCommandMenu::KeyInput  @ 00093810  (line 244)

/* DWARF original prototype: bool KeyInput(CCommandMenu * this, int keyNum) */

bool __thiscall CCommandMenu::KeyInput(CCommandMenu *this,int keyNum)

{
  CCommandMenu **ppCVar1;
  CommandButton *pCVar2;
  TeamFortressViewport *pTVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  CCommandMenu *pCVar7;
  
  iVar6 = 0;
                    /* Unresolved local var: int i@[???] */
  if (0 < this->m_iButtons) {
    do {
      iVar5 = (**(code **)(*(int *)this->m_aButtons[iVar6] + 0x260))(this->m_aButtons[iVar6]);
      if ((iVar5 == 0) &&
         (cVar4 = CommandButton::getBoundKey(this->m_aButtons[iVar6]), pTVar3 = gViewPort,
         cVar4 == keyNum)) {
        pCVar2 = this->m_aButtons[iVar6];
        pCVar7 = pCVar2->m_pSubMenu;
        if (pCVar7 != (CCommandMenu *)0x0) {
                    /* Unresolved local var: int i@[???] */
          if (0 < gViewPort->m_iNumMenus) {
            iVar6 = 0;
            do {
              ppCVar1 = pTVar3->m_pCommandMenus + iVar6;
              iVar6 = iVar6 + 1;
              (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
            } while (iVar6 < pTVar3->m_iNumMenus);
          }
          pTVar3->m_pCurrentCommandMenu = pCVar7;
          do {
            (**(code **)(*(int *)pCVar7 + 0x24))(pCVar7,1);
            pCVar7 = pCVar7->m_pParentMenu;
          } while (pCVar7 != (CCommandMenu *)0x0);
          return false;
        }
        (**(code **)(*(int *)pCVar2 + 600))(pCVar2);
        return true;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < this->m_iButtons);
  }
  return false;
}


// CCommandMenu::ClearButtonsOfArmedState  @ 00093900  (line 277)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ClearButtonsOfArmedState(CCommandMenu * this) */

void __thiscall CCommandMenu::ClearButtonsOfArmedState(CCommandMenu *this)

{
  CCommandMenu *pCVar1;
  CCommandMenu *pCVar2;
  CCommandMenu *pCVar3;
  CommandButton *pCVar4;
  CCommandMenu *pCVar5;
  CCommandMenu *pCVar6;
  CCommandMenu *pCVar7;
  CCommandMenu *pCVar8;
  CCommandMenu *pCVar9;
  CCommandMenu *this_00;
  int iVar10;
  int iVar11;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < this->m_iButtons) {
    local_50 = 0;
    do {
      (**(code **)(*(int *)this->m_aButtons[local_50] + 0x234))(this->m_aButtons[local_50],0);
      pCVar1 = this->m_aButtons[local_50]->m_pSubMenu;
                    /* Unresolved local var: int i@[???] */
      if ((pCVar1 != (CCommandMenu *)0x0) && (0 < pCVar1->m_iButtons)) {
        local_4c = 0;
        do {
          (**(code **)(*(int *)pCVar1->m_aButtons[local_4c] + 0x234))
                    (pCVar1->m_aButtons[local_4c],0);
          pCVar2 = pCVar1->m_aButtons[local_4c]->m_pSubMenu;
                    /* Unresolved local var: int i@[???] */
          if ((pCVar2 != (CCommandMenu *)0x0) && (0 < pCVar2->m_iButtons)) {
            local_48 = 0;
            do {
              (**(code **)(*(int *)pCVar2->m_aButtons[local_48] + 0x234))
                        (pCVar2->m_aButtons[local_48],0);
              pCVar3 = pCVar2->m_aButtons[local_48]->m_pSubMenu;
                    /* Unresolved local var: int i@[???] */
              if ((pCVar3 != (CCommandMenu *)0x0) && (0 < pCVar3->m_iButtons)) {
                local_44 = 0;
                do {
                  pCVar4 = *(CommandButton **)((int)pCVar3->m_aButtons + local_44 * 4);
                  (**(code **)(*(int *)pCVar4 + 0x234))(pCVar4,0);
                  pCVar5 = (*(CommandButton **)((int)pCVar3->m_aButtons + local_44 * 4))->m_pSubMenu
                  ;
                    /* Unresolved local var: int i@[???] */
                  if ((pCVar5 != (CCommandMenu *)0x0) && (0 < pCVar5->m_iButtons)) {
                    local_40 = 0;
                    do {
                      pCVar4 = *(CommandButton **)((int)pCVar5->m_aButtons + local_40 * 4);
                      (**(code **)(*(int *)pCVar4 + 0x234))(pCVar4,0);
                      pCVar6 = (*(CommandButton **)((int)pCVar5->m_aButtons + local_40 * 4))->
                               m_pSubMenu;
                    /* Unresolved local var: int i@[???] */
                      if ((pCVar6 != (CCommandMenu *)0x0) && (0 < pCVar6->m_iButtons)) {
                        local_3c = 0;
                        do {
                          pCVar4 = *(CommandButton **)((int)pCVar6->m_aButtons + local_3c * 4);
                          (**(code **)(*(int *)pCVar4 + 0x234))(pCVar4,0);
                          pCVar7 = (*(CommandButton **)((int)pCVar6->m_aButtons + local_3c * 4))->
                                   m_pSubMenu;
                    /* Unresolved local var: int i@[???] */
                          if ((pCVar7 != (CCommandMenu *)0x0) && (0 < pCVar7->m_iButtons)) {
                            local_38 = 0;
                            do {
                              pCVar4 = *(CommandButton **)((int)pCVar7->m_aButtons + local_38 * 4);
                              (**(code **)(*(int *)pCVar4 + 0x234))(pCVar4,0);
                              pCVar8 = (*(CommandButton **)((int)pCVar7->m_aButtons + local_38 * 4))
                                       ->m_pSubMenu;
                    /* Unresolved local var: int i@[???] */
                              if ((pCVar8 != (CCommandMenu *)0x0) && (0 < pCVar8->m_iButtons)) {
                                iVar11 = 0;
                                do {
                                  pCVar4 = *(CommandButton **)((int)pCVar8->m_aButtons + iVar11 * 4)
                                  ;
                                  (**(code **)(*(int *)pCVar4 + 0x234))(pCVar4,0);
                                  pCVar9 = (*(CommandButton **)
                                             ((int)pCVar8->m_aButtons + iVar11 * 4))->m_pSubMenu;
                    /* Unresolved local var: int i@[???] */
                                  if ((pCVar9 != (CCommandMenu *)0x0) && (0 < pCVar9->m_iButtons)) {
                                    iVar10 = 0;
                                    do {
                                      pCVar4 = *(CommandButton **)
                                                ((int)pCVar9->m_aButtons + iVar10 * 4);
                                      (**(code **)(*(int *)pCVar4 + 0x234))(pCVar4,0);
                                      this_00 = (*(CommandButton **)
                                                  ((int)pCVar9->m_aButtons + iVar10 * 4))->
                                                m_pSubMenu;
                                      if (this_00 != (CCommandMenu *)0x0) {
                                        ClearButtonsOfArmedState(this_00);
                                      }
                                      iVar10 = iVar10 + 1;
                                    } while (iVar10 < pCVar9->m_iButtons);
                                  }
                                  iVar11 = iVar11 + 1;
                                } while (iVar11 < pCVar8->m_iButtons);
                              }
                              local_38 = local_38 + 1;
                            } while (local_38 < pCVar7->m_iButtons);
                          }
                          local_3c = local_3c + 1;
                        } while (local_3c < pCVar6->m_iButtons);
                      }
                      local_40 = local_40 + 1;
                    } while (local_40 < pCVar5->m_iButtons);
                  }
                  local_44 = local_44 + 1;
                } while (local_44 < pCVar3->m_iButtons);
              }
              local_48 = local_48 + 1;
            } while (local_48 < pCVar2->m_iButtons);
          }
          local_4c = local_4c + 1;
        } while (local_4c < pCVar1->m_iButtons);
      }
      local_50 = local_50 + 1;
    } while (local_50 < this->m_iButtons);
  }
  return;
}


// CCommandMenu::FindButtonWithSubmenu  @ 00093c80  (line 295)

/* DWARF original prototype: CommandButton * FindButtonWithSubmenu(CCommandMenu * this, CCommandMenu
   * pSubMenu) */

CommandButton * __thiscall
CCommandMenu::FindButtonWithSubmenu(CCommandMenu *this,CCommandMenu *pSubMenu)

{
  CommandButton *pCVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (this->m_iButtons < 1) {
LAB_00093cc4:
    pCVar1 = (CommandButton *)0x0;
  }
  else {
    pCVar1 = this->m_aButtons[0];
    if (pSubMenu != pCVar1->m_pSubMenu) {
      iVar2 = 0;
      do {
        if (iVar2 + 1 == this->m_iButtons) goto LAB_00093cc4;
        pCVar1 = this->m_aButtons[iVar2 + 1];
        iVar2 = iVar2 + 1;
      } while (pSubMenu != pCVar1->m_pSubMenu);
    }
  }
  return pCVar1;
}


// CCommandMenu::RecalculateVisibles  @ 000930e0  (line 306)

/* DWARF original prototype: bool RecalculateVisibles(CCommandMenu * this, int iYOffset, bool
   bHideAll) */

bool __thiscall CCommandMenu::RecalculateVisibles(CCommandMenu *this,int iYOffset,bool bHideAll)

{
  float fVar1;
  bool bVar2;
  char cVar3;
  int *in_EAX;
  CCommandMenu *pCVar4;
  int iVar5;
  int in_EDX;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int in_stack_ffffffc8;
  undefined4 in_stack_ffffffcc;
  bool local_1d;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iCurrentY@[???]
                       Unresolved local var: int iVisibleButtons@[???] */
  if (in_EAX[0x96] < 1) {
    local_1d = false;
    fVar1 = 0.0;
    iVar12 = 0;
  }
  else {
    piVar10 = in_EAX + 0x32;
    iVar12 = 0;
    iVar8 = 0;
    do {
      while( true ) {
        pCVar4 = (CCommandMenu *)*piVar10;
                    /* Unresolved local var: int iClass@[???] */
        if ((pCVar4->m_aButtons[10] == (CommandButton *)0x0) ||
           (pCVar4->m_aButtons[10] == (CommandButton *)g_iPlayerClass)) break;
LAB_00093118:
        in_stack_ffffffc8 = 0;
        (**(code **)(*(int *)pCVar4 + 0x24))();
        if (*(int *)(*piVar10 + 0xf8) != 0) {
          RecalculateVisibles(pCVar4,in_stack_ffffffc8,SUB41(in_stack_ffffffcc,0));
        }
LAB_0009313d:
        iVar8 = iVar8 + 1;
        piVar10 = piVar10 + 1;
        if (in_EAX[0x96] <= iVar8) goto LAB_000931ad;
      }
      iVar5 = (**(code **)(*(int *)pCVar4 + 0x260))();
      if (iVar5 != 0) {
        pCVar4 = (CCommandMenu *)*piVar10;
        goto LAB_00093118;
      }
      piVar6 = (int *)*piVar10;
      if (piVar6[0x3e] != 0) {
        bVar2 = RecalculateVisibles(pCVar4,in_stack_ffffffc8,SUB41(in_stack_ffffffcc,0));
        if (bVar2) {
          piVar6 = (int *)*piVar10;
          goto LAB_0009318f;
        }
        in_stack_ffffffc8 = 0;
        (**(code **)(*(int *)*piVar10 + 0x24))((int *)*piVar10);
        goto LAB_0009313d;
      }
LAB_0009318f:
      iVar8 = iVar8 + 1;
      in_stack_ffffffc8 = 1;
      iVar12 = iVar12 + 1;
      piVar10 = piVar10 + 1;
      (**(code **)(*piVar6 + 0x24))(piVar6);
    } while (iVar8 < in_EAX[0x96]);
LAB_000931ad:
    local_1d = iVar12 != 0;
    fVar1 = (float)iVar12;
  }
  iVar5 = (int)(((float)in_EAX[0x98] - 1.0) * fVar1 + 1.0);
  iVar8 = in_EAX[3];
  (**(code **)(*in_EAX + 8))();
  if (in_EDX != 0) {
    in_EAX[0x31] = in_EDX;
  }
  if (0 < in_EAX[0x96]) {
    iVar11 = 0;
    iVar9 = 0;
    do {
      pCVar4 = (CCommandMenu *)in_EAX[iVar9 + 0x32];
      cVar3 = (**(code **)(*(int *)pCVar4 + 0x28))();
      if (cVar3 != '\0') {
        puVar7 = (undefined4 *)in_EAX[iVar9 + 0x32];
        if (puVar7[0x3e] != 0) {
          RecalculateVisibles(pCVar4,iVar8,SUB41(iVar5,0));
          puVar7 = (undefined4 *)in_EAX[iVar9 + 0x32];
        }
        if (in_EAX[0x97] == 0) {
          iVar8 = 0;
          iVar5 = iVar11;
          (**(code **)*puVar7)(puVar7);
        }
        else {
          iVar8 = 0;
          iVar5 = (int)(((float)in_EAX[0x98] - 1.0) * (float)(iVar12 + -1) - (float)iVar11);
          (**(code **)*puVar7)(puVar7);
        }
        iVar11 = (int)(((float)in_EAX[0x98] - 1.0) + (float)iVar11);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < in_EAX[0x96]);
  }
  return local_1d;
}


// CCommandMenu::RecalculateVisibles  @ 00093310  (line 306)

/* DWARF original prototype: bool RecalculateVisibles(CCommandMenu * this, int iYOffset, bool
   bHideAll) */

bool __thiscall CCommandMenu::RecalculateVisibles(CCommandMenu *this,int iYOffset,bool bHideAll)

{
  float fVar1;
  bool bVar2;
  char cVar3;
  int *in_EAX;
  CCommandMenu *pCVar4;
  int iVar5;
  char in_DL;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int in_stack_ffffffc8;
  undefined4 in_stack_ffffffcc;
  bool local_1d;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iCurrentY@[???]
                       Unresolved local var: int iVisibleButtons@[???] */
  if (in_EAX[0x96] < 1) {
    local_1d = false;
    fVar1 = 0.0;
    iVar10 = 0;
  }
  else {
    piVar8 = in_EAX + 0x32;
    iVar10 = 0;
    iVar11 = 0;
LAB_00093378:
    do {
      pCVar4 = (CCommandMenu *)*piVar8;
                    /* Unresolved local var: int iClass@[???] */
      if ((pCVar4->m_aButtons[10] == (CommandButton *)0x0) ||
         (pCVar4->m_aButtons[10] == (CommandButton *)g_iPlayerClass)) {
        iVar5 = (**(code **)(*(int *)pCVar4 + 0x260))();
        if ((iVar5 != 0) || (in_DL != '\0')) {
          pCVar4 = (CCommandMenu *)*piVar8;
          goto LAB_00093348;
        }
        piVar6 = (int *)*piVar8;
        if (piVar6[0x3e] == 0) {
LAB_000933bf:
          iVar11 = iVar11 + 1;
          in_stack_ffffffc8 = 1;
          iVar10 = iVar10 + 1;
          piVar8 = piVar8 + 1;
          (**(code **)(*piVar6 + 0x24))(piVar6);
          if (in_EAX[0x96] <= iVar11) break;
          goto LAB_00093378;
        }
        bVar2 = RecalculateVisibles(pCVar4,in_stack_ffffffc8,SUB41(in_stack_ffffffcc,0));
        if (bVar2) {
          piVar6 = (int *)*piVar8;
          goto LAB_000933bf;
        }
        in_stack_ffffffc8 = 0;
        (**(code **)(*(int *)*piVar8 + 0x24))((int *)*piVar8);
      }
      else {
LAB_00093348:
        in_stack_ffffffc8 = 0;
        (**(code **)(*(int *)pCVar4 + 0x24))();
        if (*(int *)(*piVar8 + 0xf8) != 0) {
          RecalculateVisibles(pCVar4,in_stack_ffffffc8,SUB41(in_stack_ffffffcc,0));
        }
      }
      iVar11 = iVar11 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar11 < in_EAX[0x96]);
    local_1d = iVar10 != 0;
    fVar1 = (float)iVar10;
  }
  iVar5 = (int)(((float)in_EAX[0x98] - 1.0) * fVar1 + 1.0);
  iVar11 = in_EAX[3];
  (**(code **)(*in_EAX + 8))();
  if (0 < in_EAX[0x96]) {
    iVar12 = 0;
    iVar9 = 0;
    do {
      pCVar4 = (CCommandMenu *)in_EAX[iVar9 + 0x32];
      cVar3 = (**(code **)(*(int *)pCVar4 + 0x28))();
      if (cVar3 != '\0') {
        puVar7 = (undefined4 *)in_EAX[iVar9 + 0x32];
        if (puVar7[0x3e] != 0) {
          RecalculateVisibles(pCVar4,iVar11,SUB41(iVar5,0));
          puVar7 = (undefined4 *)in_EAX[iVar9 + 0x32];
        }
        if (in_EAX[0x97] == 0) {
          iVar11 = 0;
          iVar5 = iVar12;
          (**(code **)*puVar7)(puVar7);
        }
        else {
          iVar5 = (int)(((float)in_EAX[0x98] - 1.0) * (float)(iVar10 + -1) - (float)iVar12);
          iVar11 = 0;
          (**(code **)*puVar7)(puVar7);
        }
        iVar12 = (int)(((float)in_EAX[0x98] - 1.0) + (float)iVar12);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < in_EAX[0x96]);
  }
  return local_1d;
}


// CCommandMenu::RecalculateVisibles  @ 00093cd0  (line 307)

/* DWARF original prototype: bool RecalculateVisibles(CCommandMenu * this, int iYOffset, bool
   bHideAll) */

bool __thiscall CCommandMenu::RecalculateVisibles(CCommandMenu *this,int iYOffset,bool bHideAll)

{
  float fVar1;
  bool bVar2;
  char cVar3;
  CCommandMenu *pCVar4;
  int iVar5;
  CommandButton *pCVar6;
  CommandButton **ppCVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int in_stack_ffffffc8;
  undefined4 in_stack_ffffffcc;
  bool local_1d;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iCurrentY@[???]
                       Unresolved local var: int iVisibleButtons@[???] */
  if (this->m_iButtons < 1) {
    local_1d = false;
    fVar1 = 0.0;
    iVar9 = 0;
  }
  else {
    ppCVar7 = this->m_aButtons;
    iVar9 = 0;
    iVar10 = 0;
LAB_00093d38:
    do {
      pCVar4 = (CCommandMenu *)*ppCVar7;
                    /* Unresolved local var: int iClass@[???] */
      if ((pCVar4->m_aButtons[10] == (CommandButton *)0x0) ||
         ((CommandButton *)g_iPlayerClass == pCVar4->m_aButtons[10])) {
        iVar5 = (**(code **)(*(int *)pCVar4 + 0x260))();
        if ((iVar5 != 0) || (bHideAll)) {
          pCVar4 = (CCommandMenu *)*ppCVar7;
          goto LAB_00093d08;
        }
        pCVar6 = *ppCVar7;
        if (pCVar6->m_pSubMenu == (CCommandMenu *)0x0) {
LAB_00093d7f:
          iVar10 = iVar10 + 1;
          in_stack_ffffffc8 = 1;
          iVar9 = iVar9 + 1;
          ppCVar7 = ppCVar7 + 1;
          (**(code **)(*(int *)pCVar6 + 0x24))(pCVar6);
          if (this->m_iButtons <= iVar10) break;
          goto LAB_00093d38;
        }
        bVar2 = RecalculateVisibles(pCVar4,in_stack_ffffffc8,SUB41(in_stack_ffffffcc,0));
        if (bVar2) {
          pCVar6 = *ppCVar7;
          goto LAB_00093d7f;
        }
        in_stack_ffffffc8 = 0;
        (**(code **)(*(int *)*ppCVar7 + 0x24))(*ppCVar7);
      }
      else {
LAB_00093d08:
        in_stack_ffffffc8 = 0;
        (**(code **)(*(int *)pCVar4 + 0x24))();
        if ((*ppCVar7)->m_pSubMenu != (CCommandMenu *)0x0) {
          RecalculateVisibles(pCVar4,in_stack_ffffffc8,SUB41(in_stack_ffffffcc,0));
        }
      }
      iVar10 = iVar10 + 1;
      ppCVar7 = ppCVar7 + 1;
    } while (iVar10 < this->m_iButtons);
    local_1d = iVar9 != 0;
    fVar1 = (float)iVar9;
  }
  iVar5 = (int)((this->m_flButtonSizeY - 1.0) * fVar1 + 1.0);
  iVar10 = *(int *)&this->field_0xc;
  (**(code **)(*(int *)this + 8))(this);
  if (iYOffset != 0) {
    this->m_iYOffset = iYOffset;
  }
  if (0 < this->m_iButtons) {
    iVar11 = 0;
    iVar8 = 0;
    do {
      pCVar4 = (CCommandMenu *)this->m_aButtons[iVar8];
      cVar3 = (**(code **)(*(int *)pCVar4 + 0x28))();
      if (cVar3 != '\0') {
        pCVar6 = this->m_aButtons[iVar8];
        if (pCVar6->m_pSubMenu != (CCommandMenu *)0x0) {
          RecalculateVisibles(pCVar4,iVar10,SUB41(iVar5,0));
          pCVar6 = this->m_aButtons[iVar8];
        }
        if (this->m_iDirection == 0) {
          iVar10 = 0;
          iVar5 = iVar11;
          (*(code *)**(undefined4 **)pCVar6)(pCVar6);
        }
        else {
          iVar5 = (int)((this->m_flButtonSizeY - 1.0) * (float)(iVar9 + -1) - (float)iVar11);
          iVar10 = 0;
          (*(code *)**(undefined4 **)pCVar6)(pCVar6);
        }
        iVar11 = (int)((this->m_flButtonSizeY - 1.0) + (float)iVar11);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < this->m_iButtons);
  }
  return local_1d;
}


// CCommandMenu::RecalculatePositions  @ 00093f20  (line 379)

/* DWARF original prototype: void RecalculatePositions(CCommandMenu * this, int iYOffset) */

void __thiscall CCommandMenu::RecalculatePositions(CCommandMenu *this,int iYOffset)

{
  CommandButton **ppCVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iAdjustment;
  
                    /* Unresolved local var: int iTop@[???]
                       Unresolved local var: int iAdjust@[???]
                       Unresolved local var: int iBottom@[???] */
  iVar4 = this->m_iYOffset + iYOffset;
  this->m_iYOffset = iVar4;
  if (this->m_iDirection != 0) {
    iVar4 = gHUD.m_scrinfo.iHeight - (iVar4 + *(int *)&this->field_0x10);
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  iVar2 = *(int *)&this->field_0x10 + iVar4;
  iVar3 = iVar4;
  iAdjustment = 0;
  if (gHUD.m_scrinfo.iHeight < iVar2) {
    iAdjustment = 0;
    do {
      iAdjustment = (int)((float)iAdjustment + (this->m_flButtonSizeY - 1.0));
    } while (iAdjustment < iVar2 - gHUD.m_scrinfo.iHeight);
    iVar3 = iVar4 - iAdjustment;
    if (iVar3 < 0) {
      iVar3 = 0;
      iAdjustment = iVar4;
    }
  }
  (*(code *)**(undefined4 **)this)(this,*(undefined4 *)&this->field_0x4,iVar3);
                    /* Unresolved local var: int i@[???] */
  if (0 < this->m_iButtons) {
    iVar4 = 0;
    do {
      ppCVar1 = this->m_aButtons + iVar4;
      iVar4 = iVar4 + 1;
      CommandButton::UpdateSubMenus(*ppCVar1,iAdjustment);
    } while (iVar4 < this->m_iButtons);
  }
  return;
}


// CCommandMenu::MakeVisible  @ 00093ff0  (line 425)

/* DWARF original prototype: void MakeVisible(CCommandMenu * this, CCommandMenu * pChildMenu) */

void __thiscall CCommandMenu::MakeVisible(CCommandMenu *this,CCommandMenu *pChildMenu)

{
  do {
    (**(code **)(*(int *)this + 0x24))(this,1);
    this = this->m_pParentMenu;
  } while (this != (CCommandMenu *)0x0);
  return;
}


// TeamFortressViewport::CreateSubMenu  @ 00094020  (line 449)

/* DWARF original prototype: CCommandMenu * CreateSubMenu(TeamFortressViewport * this, CommandButton
   * pButton, CCommandMenu * pParentMenu, int iYOffset, int iXOffset) */

CCommandMenu * __thiscall
TeamFortressViewport::CreateSubMenu
          (TeamFortressViewport *this,CommandButton *pButton,CCommandMenu *pParentMenu,int iYOffset,
          int iXOffset)

{
  code *pcVar1;
  float fVar2;
  CCommandMenu *pNewMenu;
  undefined4 *puVar3;
  CImageLabel *this_00;
  int iVar4;
  int iVar5;
  int local_34;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int iXPos@[???]
                       Unresolved local var: int iYPos@[???]
                       Unresolved local var: int iWide@[???]
                       Unresolved local var: int iTall@[???]
                       Unresolved local var: int iDirection@[???]
                       Unresolved local var: CCommandMenu * pMenu@[???]
                       Unresolved local var: InputSignal * pISignal@[???]
                       Unresolved local var: CImageLabel * pLabel@[???] */
  local_20[0] = 0;
  local_24 = 0;
  fVar2 = ((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0;
  if (pParentMenu == (CCommandMenu *)0x0) {
    local_34 = 0;
  }
  else {
    local_24 = (int)((float)iXOffset +
                    (fVar2 - 1.0) + (float)this->m_pCurrentCommandMenu->m_iXOffset);
    local_20[0] = iYOffset + this->m_pCurrentCommandMenu->m_iYOffset;
    local_34 = pParentMenu->m_iDirection;
  }
  pNewMenu = operator_new(0x268);
  iVar5 = local_20[0];
  iVar4 = local_24;
  vgui::Panel::Panel(&pNewMenu->super_Panel,local_24,local_20[0],(int)fVar2,0);
  pNewMenu->m_iXOffset = iVar4;
  *(undefined ***)pNewMenu = &PTR_setPos_000c56ec;
  pNewMenu->m_iYOffset = iVar5;
  pNewMenu->m_pParentMenu = pParentMenu;
  pNewMenu->m_iButtons = 0;
  pNewMenu->m_iDirection = local_34;
  vgui::Panel::setParent(&pNewMenu->super_Panel);
  CommandButton::AddSubMenu(pButton,pNewMenu);
  (**(code **)(*(int *)pButton + 0x208))(pButton,3);
  pNewMenu->m_flButtonSizeY = this->m_pCurrentCommandMenu->m_flButtonSizeY;
  puVar3 = operator_new(0xc);
  *puVar3 = &PTR_cursorMoved_000c8158;
  puVar3[1] = pNewMenu;
  puVar3[2] = pButton;
  (**(code **)(*(int *)pButton + 0x70))(pButton,puVar3);
  this_00 = operator_new(0xd4);
  fVar2 = ((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0;
  CImageLabel::CImageLabel
            (this_00,"arrowright",
             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * (fVar2 - fVar2 * 0.125)),
             (int)(((((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0) / 6.0) *
                  ((float)gHUD.m_scrinfo.iHeight / 480.0)));
  vgui::Panel::setParent((Panel *)this_00);
  (**(code **)(*(int *)this_00 + 0x70))(this_00,puVar3);
  (**(code **)(*(int *)this_00 + 4))(this_00,&local_24,local_20);
  pcVar1 = (code *)**(undefined4 **)this_00;
  iVar4 = (**(code **)(*(int *)pButton + 0x18))(pButton);
  iVar5 = (**(code **)(*(int *)this_00 + 0x230))(this_00);
  (*pcVar1)(this_00,(iVar4 - iVar5) + -4,0xfffffffc);
  if (pButton->m_bNoHighlight == false) {
    pcVar1 = *(code **)(*(int *)this_00 + 0x70);
    puVar3 = operator_new(0xc);
    puVar3[1] = pButton;
    *puVar3 = &PTR_cursorMoved_000c4d6c;
    puVar3[2] = pButton;
    (*pcVar1)(this_00,puVar3);
  }
  return pNewMenu;
}


// TeamFortressViewport::operator_new  @ 000942e0  (line 495)

/* DWARF original name: operator new */

void * TeamFortressViewport::operator_new(size_t stAllocateBlock)

{
  undefined4 *puVar1;
  uint uVar2;
  size_t sVar3;
  undefined4 *puVar4;
  byte bVar5;
  
                    /* Unresolved local var: void * mem@[???] */
  bVar5 = 0;
  puVar1 = operator_new(stAllocateBlock);
  puVar4 = puVar1;
  if (7 < stAllocateBlock) {
    sVar3 = stAllocateBlock;
    if (((uint)puVar1 & 1) != 0) {
      *(undefined1 *)puVar1 = 0;
      puVar4 = (undefined4 *)((int)puVar1 + 1);
      sVar3 = stAllocateBlock - 1;
    }
    if (((uint)puVar4 & 2) != 0) {
      *(undefined2 *)puVar4 = 0;
      sVar3 = sVar3 - 2;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    }
    if (((uint)puVar4 & 4) != 0) {
      *puVar4 = 0;
      sVar3 = sVar3 - 4;
      puVar4 = puVar4 + 1;
    }
    stAllocateBlock = sVar3 & 3;
    for (uVar2 = sVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
    }
  }
  if ((stAllocateBlock & 4) != 0) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if ((stAllocateBlock & 2) != 0) {
    *(undefined2 *)puVar4 = 0;
    puVar4 = (undefined4 *)((int)puVar4 + 2);
  }
  if ((stAllocateBlock & 1) != 0) {
    *(undefined1 *)puVar4 = 0;
  }
  return puVar1;
}


// CViewPortInputHandler::cursorMoved  @ 0009c2a0  (line 514)

/* DWARF original prototype: void cursorMoved(CViewPortInputHandler * this, int x, int y, Panel *
   panel) */

void __thiscall
CViewPortInputHandler::cursorMoved(CViewPortInputHandler *this,int x,int y,Panel *panel)

{
  return;
}


// CViewPortInputHandler::cursorEntered  @ 0009c2b0  (line 515)

/* DWARF original prototype: void cursorEntered(CViewPortInputHandler * this, Panel * panel) */

void __thiscall CViewPortInputHandler::cursorEntered(CViewPortInputHandler *this,Panel *panel)

{
  return;
}


// CViewPortInputHandler::cursorExited  @ 0009c2c0  (line 516)

/* DWARF original prototype: void cursorExited(CViewPortInputHandler * this, Panel * panel) */

void __thiscall CViewPortInputHandler::cursorExited(CViewPortInputHandler *this,Panel *panel)

{
  return;
}


// CViewPortInputHandler::mousePressed  @ 0009c2d0  (line 519)

/* DWARF original prototype: void mousePressed(CViewPortInputHandler * this, MouseCode code, Panel *
   panel) */

void __thiscall
CViewPortInputHandler::mousePressed(CViewPortInputHandler *this,MouseCode code,Panel *panel)

{
  if (code == MOUSE_LEFT) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0009c2e9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.pfnClientCmd)("ForceCloseCommandMenu\n");
  return;
}


// CViewPortInputHandler::mouseReleased  @ 0009c2f0  (line 526)

/* DWARF original prototype: void mouseReleased(CViewPortInputHandler * this, MouseCode code, Panel
   * panel) */

void __thiscall
CViewPortInputHandler::mouseReleased(CViewPortInputHandler *this,MouseCode code,Panel *panel)

{
  return;
}


// CViewPortInputHandler::mouseDoublePressed  @ 0009c300  (line 530)

/* DWARF original prototype: void mouseDoublePressed(CViewPortInputHandler * this, MouseCode code,
   Panel * panel) */

void __thiscall
CViewPortInputHandler::mouseDoublePressed(CViewPortInputHandler *this,MouseCode code,Panel *panel)

{
  return;
}


// CViewPortInputHandler::mouseWheeled  @ 0009c310  (line 531)

/* DWARF original prototype: void mouseWheeled(CViewPortInputHandler * this, int delta, Panel *
   panel) */

void __thiscall
CViewPortInputHandler::mouseWheeled(CViewPortInputHandler *this,int delta,Panel *panel)

{
  return;
}


// CViewPortInputHandler::keyPressed  @ 0009c320  (line 532)

/* DWARF original prototype: void keyPressed(CViewPortInputHandler * this, KeyCode code, Panel *
   panel) */

void __thiscall
CViewPortInputHandler::keyPressed(CViewPortInputHandler *this,KeyCode code,Panel *panel)

{
  return;
}


// CViewPortInputHandler::keyTyped  @ 0009c330  (line 533)

/* DWARF original prototype: void keyTyped(CViewPortInputHandler * this, KeyCode code, Panel *
   panel) */

void __thiscall
CViewPortInputHandler::keyTyped(CViewPortInputHandler *this,KeyCode code,Panel *panel)

{
  return;
}


// CViewPortInputHandler::keyReleased  @ 0009c340  (line 534)

/* DWARF original prototype: void keyReleased(CViewPortInputHandler * this, KeyCode code, Panel *
   panel) */

void __thiscall
CViewPortInputHandler::keyReleased(CViewPortInputHandler *this,KeyCode code,Panel *panel)

{
  return;
}


// CViewPortInputHandler::keyFocusTicked  @ 0009c350  (line 535)

/* DWARF original prototype: void keyFocusTicked(CViewPortInputHandler * this, Panel * panel) */

void __thiscall CViewPortInputHandler::keyFocusTicked(CViewPortInputHandler *this,Panel *panel)

{
  return;
}


// TeamFortressViewport::TeamFortressViewport  @ 0009b5f0  (line 540)

/* DWARF original prototype: void TeamFortressViewport(TeamFortressViewport * this, int x, int y,
   int wide, int tall) */

void __thiscall
TeamFortressViewport::TeamFortressViewport(TeamFortressViewport *this,int x,int y,int wide,int tall)

{
  CSchemeManager *this_00;
  code *pcVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int *piVar5;
  SchemeHandle_t SVar6;
  Font *pFVar7;
  int *piVar8;
  CTeamMenuPanel *this_01;
  CClassMenuPanel *this_02;
  SpectatorPanel *this_03;
  int iVar9;
  CCommandMenu *this_04;
  ServerBrowser *this_05;
  int iVar10;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int aiStack_20 [4];
  
  this_00 = &this->m_SchemeManager;
  vgui::Panel::Panel(&this->super_Panel,x,y,wide,tall);
  *(undefined ***)this = &PTR_setPos_000c9af8;
  CSchemeManager::CSchemeManager(this_00,wide,tall);
  this->m_iInitialized = 0;
  this->m_pTeamMenu = (CTeamMenuPanel *)0x0;
  this->m_pClassMenu = (CClassMenuPanel *)0x0;
  this->m_pScoreBoard = (ScorePanel *)0x0;
  this->m_pSpectatorPanel = (SpectatorPanel *)0x0;
  this->m_pCurrentMenu = (CMenuPanel *)0x0;
  this->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
  gViewPort = this;
  Initialize(this);
  puVar4 = operator_new(8);
  *puVar4 = &PTR_cursorMoved_000c9ac4;
  vgui::Panel::addInputSignal((InputSignal *)this);
  piVar5 = (int *)vgui::App::getInstance();
  piVar5 = (int *)(**(code **)(*piVar5 + 0x54))(piVar5,puVar4);
  SVar6 = CSchemeManager::getSchemeHandle(this_00,"Primary Button Text");
  pcVar1 = *(code **)(*piVar5 + 8);
  pFVar7 = CSchemeManager::getFont(this_00,SVar6);
  (*pcVar1)(piVar5,1,pFVar7);
  CSchemeManager::getFgColor(this_00,SVar6,&iStack_2c,&iStack_28,&iStack_24,aiStack_20);
  (**(code **)*piVar5)(piVar5,3,iStack_2c,iStack_28,iStack_24,aiStack_20[0]);
  CSchemeManager::getBgColor(this_00,SVar6,&iStack_2c,&iStack_28,&iStack_24,aiStack_20);
  (**(code **)*piVar5)(piVar5,5,iStack_2c,iStack_28,iStack_24,aiStack_20[0]);
  CSchemeManager::getFgArmedColor(this_00,SVar6,&iStack_2c,&iStack_28,&iStack_24,aiStack_20);
  (**(code **)*piVar5)(piVar5,7,iStack_2c,iStack_28,iStack_24,aiStack_20[0]);
  CSchemeManager::getBgArmedColor(this_00,SVar6,&iStack_2c,&iStack_28,&iStack_24,aiStack_20);
  (**(code **)*piVar5)(piVar5,4,iStack_2c,iStack_28,iStack_24,aiStack_20[0]);
  CSchemeManager::getBorderColor(this_00,SVar6,&iStack_2c,&iStack_28,&iStack_24,aiStack_20);
  (**(code **)*piVar5)(piVar5,6,0xb2,0x76,0,0);
  SVar6 = CSchemeManager::getSchemeHandle(this_00,"Scoreboard Text");
  pcVar1 = *(code **)(*piVar5 + 8);
  pFVar7 = CSchemeManager::getFont(this_00,SVar6);
  (*pcVar1)(piVar5,2,pFVar7);
  SVar6 = CSchemeManager::getSchemeHandle(this_00,"CommandMenu Text");
  pcVar1 = *(code **)(*piVar5 + 8);
  pFVar7 = CSchemeManager::getFont(this_00,SVar6);
  (*pcVar1)(piVar5,3,pFVar7);
  piVar8 = (int *)vgui::App::getInstance();
  (**(code **)(*piVar8 + 0x50))(piVar8,piVar5);
  this_01 = operator_new(0x124);
  CTeamMenuPanel::CTeamMenuPanel(this_01,100,0,0,0,gHUD.m_scrinfo.iWidth,gHUD.m_scrinfo.iHeight);
  this->m_pTeamMenu = this_01;
  vgui::Panel::setParent((Panel *)this_01);
  (**(code **)(*(int *)&(this->m_pTeamMenu->super_CMenuPanel).super_CTransparentPanel + 0x24))
            (this->m_pTeamMenu,0);
  this_02 = operator_new(0xdf0);
  CClassMenuPanel::CClassMenuPanel(this_02,100,0,0,0,gHUD.m_scrinfo.iWidth,gHUD.m_scrinfo.iHeight);
  this->m_pClassMenu = this_02;
  vgui::Panel::setParent((Panel *)this_02);
  (**(code **)(*(int *)&(this->m_pClassMenu->super_CMenuPanel).super_CTransparentPanel + 0x24))
            (this->m_pClassMenu,0);
  this_03 = operator_new(0x100);
  SpectatorPanel::SpectatorPanel(this_03,0,0,gHUD.m_scrinfo.iWidth,gHUD.m_scrinfo.iHeight);
  this->m_pSpectatorPanel = this_03;
  vgui::Panel::setParent(&this_03->super_Panel);
  (**(code **)(*(int *)this->m_pSpectatorPanel + 0x24))(this->m_pSpectatorPanel,0);
  SpectatorPanel::Initialize(this->m_pSpectatorPanel);
  CreateScoreBoard(this);
  this->m_iNumMenus = 0;
  this->m_iUser3 = 0;
  this->m_iUser2 = 0;
  this->m_iUser1 = 0;
  this->m_iCurrentTeamNumber = 0;
  fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
  iVar9 = CreateCommandMenu(this,"commandmenu.txt",0,(int)(fVar2 * 4.0),false,
                            ((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0,fVar2,0);
  this->m_StandardMenu = iVar9;
  iVar9 = CreateCommandMenu(this,"spectatormenu.txt",1,0x40,true,
                            ((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0,
                            ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0 * 0.5,0);
  this->m_SpectatorOptionsMenu = iVar9;
  fVar2 = ((float)gHUD.m_scrinfo.iWidth / 640.0) * 200.0;
  iVar9 = CreateCommandMenu(this,"spectcammenu.txt",1,0x40,true,fVar2,
                            ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0 * 0.5,
                            (int)((float)gHUD.m_scrinfo.iWidth - (fVar2 + 15.0)));
  this->m_SpectatorCameraMenu = iVar9;
  this->m_PlayerMenu = this->m_iNumMenus;
  this->m_iNumMenus = this->m_iNumMenus + 1;
  fVar3 = (float)gHUD.m_scrinfo.iWidth;
  fVar2 = fVar3 / 640.0;
  this_04 = operator_new(0x268);
  iVar10 = (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 157.0);
  vgui::Panel::Panel(&this_04->super_Panel,iVar10,0x40,
                     (int)(((fVar3 - (fVar2 * 200.0 + 15.0)) - fVar2 * 39.0) - fVar2 * 164.0),300);
  this_04->m_pParentMenu = (CCommandMenu *)0x0;
  this_04->m_iYOffset = 0x40;
  this_04->m_iButtons = 0;
  this_04->m_iDirection = 1;
  iVar9 = this->m_PlayerMenu;
  *(undefined ***)this_04 = &PTR_setPos_000c56ec;
  this_04->m_iXOffset = iVar10;
  this->m_pCommandMenus[iVar9] = this_04;
  vgui::Panel::setParent(&this_04->super_Panel);
  (**(code **)(*(int *)this->m_pCommandMenus[this->m_PlayerMenu] + 0x24))
            (this->m_pCommandMenus[this->m_PlayerMenu],0);
  this->m_pCommandMenus[this->m_PlayerMenu]->m_flButtonSizeY =
       ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0 * 0.5;
  this->m_pCommandMenus[this->m_PlayerMenu]->m_iSpectCmdMenu = 1;
  UpdatePlayerMenu(this,this->m_PlayerMenu);
  this_05 = operator_new(0xe4);
  ServerBrowser::ServerBrowser(this_05,0,0,gHUD.m_scrinfo.iWidth,gHUD.m_scrinfo.iHeight);
  this->m_pServerBrowser = this_05;
  vgui::Panel::setParent((Panel *)this_05);
  (**(code **)(*(int *)&this->m_pServerBrowser->super_CTransparentPanel + 0x24))
            (this->m_pServerBrowser,0);
  return;
}


// TeamFortressViewport::Initialize  @ 00099d20  (line 639)

/* DWARF original prototype: void Initialize(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::Initialize(TeamFortressViewport *this)

{
  CCommandMenu **ppCVar1;
  CTeamMenuPanel *pCVar2;
  CClassMenuPanel *pCVar3;
  SpectatorPanel *pSVar4;
  CMenuPanel *pCVar5;
  code *pcVar6;
  ScorePanel *pSVar7;
  TeamFortressViewport *pTVar8;
  char (*pacVar9) [32];
  char (*pacVar10) [32];
  int *piVar11;
  int *piVar12;
  undefined4 uVar13;
  CVoiceStatus *this_00;
  int iVar14;
  
  pCVar2 = this->m_pTeamMenu;
  if (pCVar2 != (CTeamMenuPanel *)0x0) {
    (**(code **)(*(int *)&(pCVar2->super_CMenuPanel).super_CTransparentPanel + 0x214))(pCVar2);
  }
  pCVar3 = this->m_pClassMenu;
  if (pCVar3 != (CClassMenuPanel *)0x0) {
    (**(code **)(*(int *)&(pCVar3->super_CMenuPanel).super_CTransparentPanel + 0x214))(pCVar3);
  }
  if (((this->m_pScoreBoard != (ScorePanel *)0x0) &&
      (ScorePanel::Initialize(this->m_pScoreBoard), gHUD.m_iIntermission == 0)) &&
     (pSVar7 = this->m_pScoreBoard, pSVar7 != (ScorePanel *)0x0)) {
    (**(code **)(*(int *)pSVar7 + 0x24))(pSVar7,0);
    this_00 = GetClientVoiceMgr();
    CVoiceStatus::StopSquelchMode(this_00);
    UpdateCursorState(this);
  }
  pSVar4 = this->m_pSpectatorPanel;
  if (pSVar4 != (SpectatorPanel *)0x0) {
    (**(code **)(*(int *)pSVar4 + 0x24))(pSVar4,0);
  }
  pCVar5 = this->m_pCurrentMenu;
  while (pCVar5 != (CMenuPanel *)0x0) {
    pcVar6 = *(code **)(*(int *)&pCVar5->super_CTransparentPanel + 0x204);
    if (pcVar6 == CMenuPanel::Close) {
      (**(code **)(*(int *)&pCVar5->super_CTransparentPanel + 0x24))(pCVar5,0);
      pCVar5->m_iIsActive = 0;
      if (pCVar5->m_iRemoveMe != 0) {
        (**(code **)(*(int *)gViewPort + 0x4c))(gViewPort,pCVar5);
      }
    }
    else {
      (*pcVar6)(pCVar5);
    }
    pTVar8 = gViewPort;
    pCVar5 = this->m_pCurrentMenu->m_pNextMenu;
    gViewPort->m_pCurrentMenu = pCVar5;
    if (pCVar5 == (CMenuPanel *)0x0) {
      (*gEngfuncs.pfnClientCmd)("closemenus;");
    }
    else {
      iVar14 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
      if (iVar14 == 0) {
        (**(code **)(*(int *)&pTVar8->m_pCurrentMenu->super_CTransparentPanel + 0x200))
                  (pTVar8->m_pCurrentMenu);
      }
    }
    UpdateCursorState(this);
    pCVar5 = this->m_pCurrentMenu;
  }
  if (this->m_iInitialized != 0) {
    if (this->m_pCommandMenus[this->m_StandardMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_StandardMenu]);
    }
    if (this->m_pCommandMenus[this->m_SpectatorOptionsMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorOptionsMenu]);
    }
    if (this->m_pCommandMenus[this->m_SpectatorCameraMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorCameraMenu]);
    }
    if (this->m_pCommandMenus[this->m_PlayerMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_PlayerMenu]);
    }
                    /* Unresolved local var: int i@[???] */
    this->m_flMenuOpenTime = 0.0;
    if (0 < this->m_iNumMenus) {
      iVar14 = 0;
      do {
        ppCVar1 = this->m_pCommandMenus + iVar14;
        iVar14 = iVar14 + 1;
        (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
      } while (iVar14 < this->m_iNumMenus);
    }
    this->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
    UpdateCursorState(this);
  }
  this->m_iRandomPC = 0;
  g_iPlayerClass = 0;
  this->m_iGotAllMOTD = 1;
  piVar11 = this->m_iValidClasses;
  this->m_flScoreBoardLastUpdated = 0.0;
  this->m_flSpectatorPanelLastUpdated = 0.0;
  g_iTeamNumber = 0;
  this->m_sMapName[0] = '\0';
  this->m_szServerName[0] = '\0';
  pacVar9 = this->m_sTeamNames;
  do {
                    /* Unresolved local var: int i@[???] */
    *piVar11 = 0;
    pacVar10 = pacVar9 + 1;
    piVar11 = piVar11 + 1;
    (*pacVar9)[0] = '\0';
    pacVar9 = pacVar10;
  } while (this->m_sDetpackStrings != pacVar10);
  piVar11 = (int *)vgui::App::getInstance();
  pcVar6 = *(code **)(*piVar11 + 0x8c);
  piVar12 = (int *)vgui::App::getInstance();
  piVar12 = (int *)(**(code **)(*piVar12 + 0x54))(piVar12);
  uVar13 = (**(code **)(*piVar12 + 0x14))(piVar12,1);
  (*pcVar6)(piVar11,uVar13);
  return;
}


// TeamFortressViewport::CreateCommandMenu  @ 00096d40  (line 691)

/* DWARF original prototype: int CreateCommandMenu(TeamFortressViewport * this, char * menuFile, int
   direction, int yOffset, bool flatDesign, float flButtonSizeX, float flButtonSizeY, int xOffset)
    */

int __thiscall
TeamFortressViewport::CreateCommandMenu
          (TeamFortressViewport *this,char *menuFile,int direction,int yOffset,bool flatDesign,
          float flButtonSizeX,float flButtonSizeY,int xOffset)

{
  CCommandMenu **ppCVar1;
  int iVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  CCommandMenu *pCVar7;
  byte *pbVar8;
  uint uVar9;
  char *pcVar10;
  CommandButton *this_00;
  undefined4 *puVar11;
  cvar_s *pcVar12;
  CImageLabel *pCVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  char *pcVar18;
  int in_GS_OFFSET;
  undefined1 uVar19;
  bool bVar20;
  byte bVar21;
  int *piVar22;
  undefined1 *puVar23;
  char *pcStack_658;
  int iStack_648;
  int iStack_640;
  int iStack_628;
  undefined1 auStack_624 [4];
  undefined4 uStack_620;
  undefined4 uStack_61c;
  undefined4 uStack_618;
  undefined4 uStack_614;
  undefined4 uStack_610;
  undefined4 uStack_60c;
  undefined4 uStack_608;
  undefined4 uStack_604;
  undefined4 uStack_600;
  undefined4 auStack_5fc [6];
  undefined1 uStack_5e1;
  undefined4 uStack_5e0;
  undefined4 auStack_5dc [7];
  undefined4 uStack_5c0;
  char acStack_5bc [4];
  char acStack_5b8 [4];
  char acStack_5b4 [19];
  undefined1 uStack_5a1;
  undefined4 uStack_5a0;
  undefined4 auStack_59c [30];
  undefined1 uStack_521;
  undefined4 uStack_520;
  undefined4 auStack_51c [62];
  undefined1 uStack_421;
  char acStack_420 [1024];
  int local_20;
  
                    /* Unresolved local var: int newIndex@[???]
                       Unresolved local var: char[1024] token@[???]
                       Unresolved local var: char * pfile@[???]
                       Unresolved local var: char[32] szLastButtonText@[???] */
  bVar21 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = this->m_iNumMenus;
  pCVar7 = operator_new(0x268);
  iVar17 = (int)flButtonSizeX;
  vgui::Panel::Panel(&pCVar7->super_Panel,xOffset,yOffset,iVar17,300);
  pCVar7->m_iYOffset = yOffset;
  pCVar7->m_iButtons = 0;
  pCVar7->m_iXOffset = xOffset;
  pCVar7->m_pParentMenu = (CCommandMenu *)0x0;
  *(undefined ***)pCVar7 = &PTR_setPos_000c56ec;
  pCVar7->m_iDirection = direction;
  this->m_pCommandMenus[iVar2] = pCVar7;
  vgui::Panel::setParent(&pCVar7->super_Panel);
  (**(code **)(*(int *)this->m_pCommandMenus[iVar2] + 0x24))(this->m_pCommandMenus[iVar2],0);
  this->m_pCommandMenus[iVar2]->m_flButtonSizeY = flButtonSizeY;
  this->m_pCommandMenus[iVar2]->m_iSpectCmdMenu = direction;
  this->m_iNumMenus = this->m_iNumMenus + 1;
  pbVar8 = (*gEngfuncs.COM_LoadFile)(menuFile,5,(int *)0x0);
  if (pbVar8 == (byte *)0x0) {
    (*gEngfuncs.Con_DPrintf)("Unable to open %s\n",menuFile);
    if (0 < this->m_iNumMenus) {
      iVar17 = 0;
      do {
        ppCVar1 = this->m_pCommandMenus + iVar17;
        iVar17 = iVar17 + 1;
        (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
      } while (iVar17 < this->m_iNumMenus);
    }
    this->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
  }
  else {
    CHudTextMessage::LocaliseTextString("#DetpackSet_For5Seconds",this->m_sDetpackStrings[0],0x20);
    CHudTextMessage::LocaliseTextString("#DetpackSet_For20Seconds",this->m_sDetpackStrings[1],0x20);
    CHudTextMessage::LocaliseTextString("#DetpackSet_For50Seconds",this->m_sDetpackStrings[2],0x20);
    uStack_60c = 0;
    uStack_608 = 0;
    this->m_pCurrentCommandMenu = this->m_pCommandMenus[iVar2];
    uStack_620 = 0x656c6966;
    uStack_61c = 0x61747320;
    uStack_618 = 0x7472;
    uStack_614 = 0;
    uStack_610 = 0;
    uStack_604 = 0;
    pcStack_658 = (*gEngfuncs.COM_ParseFile)((char *)pbVar8,acStack_420);
    while ((acStack_420[0] != '\0' && (this->m_iNumMenus < 0x50))) {
      do {
        if (acStack_420[0] == '}') break;
        uStack_600 = 0;
        uVar6 = 0;
        do {
          uVar9 = uVar6;
          *(undefined4 *)((int)auStack_5fc + uVar9) = 0;
          *(undefined4 *)((int)auStack_5fc + uVar9 + 4) = 0;
          uVar6 = uVar9 + 8;
        } while (uVar9 + 8 < 0x18);
        *(undefined4 *)((int)auStack_5fc + uVar9 + 8) = 0;
        uStack_5e0 = 0;
        uVar6 = 0;
        do {
          uVar9 = uVar6;
          *(undefined4 *)((int)auStack_5dc + uVar9) = 0;
          *(undefined4 *)((int)auStack_5dc + uVar9 + 4) = 0;
          uVar6 = uVar9 + 8;
        } while (uVar9 + 8 < 0x18);
        *(undefined4 *)((int)auStack_5dc + uVar9 + 8) = 0;
        uStack_5c0 = 0;
        uVar6 = 0;
        do {
          uVar9 = uVar6;
          pcVar10 = acStack_5bc + uVar9;
          pcVar10[0] = '\0';
          pcVar10[1] = '\0';
          pcVar10[2] = '\0';
          pcVar10[3] = '\0';
          pcVar10 = acStack_5bc + uVar9 + 4;
          pcVar10[0] = '\0';
          pcVar10[1] = '\0';
          pcVar10[2] = '\0';
          pcVar10[3] = '\0';
          uVar6 = uVar9 + 8;
        } while (uVar9 + 8 < 0x18);
        pcVar10 = acStack_5bc + uVar9 + 8;
        pcVar10[0] = '\0';
        pcVar10[1] = '\0';
        pcVar10[2] = '\0';
        pcVar10[3] = '\0';
        uStack_5a0 = 0;
        uVar6 = 0;
        do {
          uVar9 = uVar6;
          *(undefined4 *)((int)auStack_59c + uVar9) = 0;
          *(undefined4 *)((int)auStack_59c + uVar9 + 4) = 0;
          uVar6 = uVar9 + 8;
        } while (uVar9 + 8 < 0x78);
        *(undefined4 *)((int)auStack_59c + uVar9 + 8) = 0;
        uStack_520 = 0;
        uVar6 = 0;
        do {
          uVar9 = uVar6;
          *(undefined4 *)((int)auStack_51c + uVar9) = 0;
          *(undefined4 *)((int)auStack_51c + uVar9 + 4) = 0;
          uVar6 = uVar9 + 8;
        } while (uVar9 + 8 < 0xf8);
        *(undefined4 *)((int)auStack_51c + uVar9 + 8) = 0;
        if (this->m_pCurrentCommandMenu == (CCommandMenu *)0x0) {
          (*gEngfuncs.Con_Printf)("Error in %s file after \'%s\'.\n",menuFile,&uStack_620);
          this->m_iInitialized = 0;
          goto LAB_00097500;
        }
        uVar19 = 1;
        strncpy((char *)&uStack_5c0,acStack_420,0x20);
        iVar16 = 7;
        uStack_5a1 = 0;
        pcVar10 = (char *)&uStack_5c0;
        pcVar18 = "CUSTOM";
        do {
          if (iVar16 == 0) break;
          iVar16 = iVar16 + -1;
          uVar19 = *pcVar10 == *pcVar18;
          pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
          pcVar18 = pcVar18 + (uint)bVar21 * -2 + 1;
        } while ((bool)uVar19);
        if ((bool)uVar19) {
          bVar20 = false;
          pcStack_658 = (*gEngfuncs.COM_ParseFile)(pcStack_658,acStack_420);
          iStack_640 = 0;
          bVar5 = false;
          iStack_648 = -1;
          bVar4 = true;
        }
        else {
          iVar16 = 4;
          bVar20 = false;
          pcVar10 = (char *)&uStack_5c0;
          pcVar18 = "MAP";
          do {
            if (iVar16 == 0) break;
            iVar16 = iVar16 + -1;
            bVar20 = *pcVar10 == *pcVar18;
            pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
            pcVar18 = pcVar18 + (uint)bVar21 * -2 + 1;
          } while (bVar20);
          if (bVar20) {
            pcVar10 = (*gEngfuncs.COM_ParseFile)(pcStack_658,acStack_420);
            strncpy((char *)&uStack_520,acStack_420,0x100);
            uStack_421 = 0;
            pcStack_658 = (*gEngfuncs.COM_ParseFile)(pcVar10,acStack_420);
LAB_000971d9:
            bVar20 = false;
            bVar5 = false;
            iStack_648 = -1;
            bVar4 = false;
            iStack_640 = 0;
          }
          else {
            iVar16 = 4;
            bVar20 = false;
            pcVar10 = (char *)&uStack_5c0;
            pcVar18 = "TEAM";
            do {
              if (iVar16 == 0) break;
              iVar16 = iVar16 + -1;
              bVar20 = *pcVar10 == *pcVar18;
              pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
              pcVar18 = pcVar18 + (uint)bVar21 * -2 + 1;
            } while (bVar20);
            if (bVar20) {
              bVar20 = false;
              iStack_648 = strtol(acStack_5bc,(char **)0x0,10);
              pcStack_658 = (*gEngfuncs.COM_ParseFile)(pcStack_658,acStack_420);
              bVar5 = false;
              bVar4 = false;
              iStack_640 = 0;
            }
            else {
              iVar16 = 6;
              bVar20 = false;
              pcVar10 = (char *)&uStack_5c0;
              pcVar18 = "TOGGLE";
              do {
                if (iVar16 == 0) break;
                iVar16 = iVar16 + -1;
                bVar20 = *pcVar10 == *pcVar18;
                pcVar10 = pcVar10 + (uint)bVar21 * -2 + 1;
                pcVar18 = pcVar18 + (uint)bVar21 * -2 + 1;
              } while (bVar20);
              if (bVar20) {
                bVar20 = true;
                pcStack_658 = (*gEngfuncs.COM_ParseFile)(pcStack_658,acStack_420);
                bVar5 = true;
                iStack_648 = -1;
                bVar4 = false;
                iStack_640 = 0;
              }
              else {
                iVar16 = strcmp(acStack_420,sTFClasses[1]);
                if (iVar16 == 0) {
                  iStack_640 = 1;
                }
                else {
                  iVar16 = strcmp(acStack_420,sTFClasses[2]);
                  if (iVar16 == 0) {
                    iStack_640 = 2;
                  }
                  else {
                    iVar16 = strcmp(acStack_420,sTFClasses[3]);
                    if (iVar16 == 0) {
                      iStack_640 = 3;
                    }
                    else {
                      iVar16 = strcmp(acStack_420,sTFClasses[4]);
                      if (iVar16 == 0) {
                        iStack_640 = 4;
                      }
                      else {
                        iVar16 = strcmp(acStack_420,sTFClasses[5]);
                        if (iVar16 == 0) {
                          iStack_640 = 5;
                        }
                        else {
                          iVar16 = strcmp(acStack_420,sTFClasses[6]);
                          if (iVar16 == 0) {
                            iStack_640 = 6;
                          }
                          else {
                            iVar16 = strcmp(acStack_420,sTFClasses[7]);
                            if (iVar16 == 0) {
                              iStack_640 = 7;
                            }
                            else {
                              iVar16 = strcmp(acStack_420,sTFClasses[8]);
                              if (iVar16 == 0) {
                                iStack_640 = 8;
                              }
                              else {
                                iVar16 = strcmp(acStack_420,sTFClasses[9]);
                                if (iVar16 != 0) goto LAB_000971d9;
                                iStack_640 = 9;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                bVar20 = false;
                pcStack_658 = (*gEngfuncs.COM_ParseFile)(pcStack_658,acStack_420);
                bVar5 = false;
                iStack_648 = -1;
                bVar4 = false;
              }
            }
          }
        }
        strncpy((char *)&uStack_5e0,acStack_420,0x20);
        uStack_5e1 = 0;
        pcVar10 = (*gEngfuncs.COM_ParseFile)(pcStack_658,acStack_420);
        CHudTextMessage::LocaliseTextString(acStack_420,(char *)&uStack_600,0x20);
        __strcpy_chk(&uStack_620,&uStack_600,0x20);
        pcStack_658 = (*gEngfuncs.COM_ParseFile)(pcVar10,acStack_420);
        strncpy((char *)&uStack_5a0,acStack_420,0x80);
        uStack_521 = 0;
        iVar16 = (int)((float)this->m_pCurrentCommandMenu->m_iButtons *
                      (((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0 - 1.0));
        if (bVar4) {
          this_00 = CreateCustomButton(this,(char *)&uStack_600,(char *)&uStack_5a0,iVar16);
          pcStack_658 = (*gEngfuncs.COM_ParseFile)(pcStack_658,acStack_420);
          bVar20 = false;
          if (acStack_420[0] == '{') {
            __strcpy_chk(&uStack_5a0,acStack_420,0x80);
            bVar20 = true;
          }
        }
        else if ((char)uStack_520 == '\0') {
          if (iStack_648 == -1) {
            if ((direction == 0) && (bVar20)) {
              this_00 = operator_new(0x140);
              iVar14 = (int)flButtonSizeY;
              CommandButton::CommandButton
                        (this_00,(char *)&uStack_600,xOffset,iVar16,iVar17,iVar14,false,flatDesign);
              *(undefined ***)this_00 = &PTR_setPos_000c9524;
              *(undefined ***)(this_00 + 1) = &PTR_cursorMoved_000c97c0;
              pcVar12 = (*gEngfuncs.pfnGetCvarPointer)((char *)&uStack_5a0);
              *(cvar_s **)&this_00[1].field_0x4 = pcVar12;
              pCVar13 = operator_new(0xd4);
              CImageLabel::CImageLabel(pCVar13,"checked",0,0);
              *(CImageLabel **)&this_00[1].field_0x8 = pCVar13;
              vgui::Panel::setParent((Panel *)pCVar13);
              (**(code **)(**(int **)&this_00[1].field_0x8 + 0x70))
                        (*(int **)&this_00[1].field_0x8,this_00 + 1);
              pCVar13 = operator_new(0xd4);
              CImageLabel::CImageLabel(pCVar13,"unchecked",0,0);
              *(CImageLabel **)&this_00[1].field_0xc = pCVar13;
              vgui::Panel::setParent((Panel *)pCVar13);
              (**(code **)(**(int **)&this_00[1].field_0xc + 0xfc))
                        (*(int **)&this_00[1].field_0xc,1);
              (**(code **)(**(int **)&this_00[1].field_0xc + 0x70))
                        (*(int **)&this_00[1].field_0xc,this_00 + 1);
              puVar23 = auStack_624;
              piVar22 = &iStack_628;
              vgui::Label::getTextSize((int *)this_00,piVar22);
              puVar11 = (undefined4 *)**(int **)&this_00[1].field_0x8;
              pcVar3 = (code *)*puVar11;
              iVar15 = (*(code *)puVar11[7])(*(int **)&this_00[1].field_0x8,piVar22,puVar23);
              (*pcVar3)(*(undefined4 *)&this_00[1].field_0x8,iStack_628,(iVar14 - iVar15) / 2);
              puVar11 = (undefined4 *)**(int **)&this_00[1].field_0xc;
              pcVar3 = (code *)*puVar11;
              iVar15 = (*(code *)puVar11[7])(*(int **)&this_00[1].field_0xc);
              (*pcVar3)(*(undefined4 *)&this_00[1].field_0xc,iStack_628,(iVar14 - iVar15) / 2);
              vgui::Label::setFgColor((SchemeColor)this_00);
            }
            else if (direction == 1) {
              if (bVar5) {
                this_00 = operator_new(0x13c);
                CommandButton::CommandButton
                          (this_00,(char *)&uStack_600,xOffset,iVar16,iVar17,(int)flButtonSizeY,
                           false,flatDesign);
                *(undefined ***)this_00 = &PTR_setPos_000c97f4;
                *(undefined ***)(this_00 + 1) = &PTR_cursorMoved_000c9a90;
                pcVar12 = (*gEngfuncs.pfnGetCvarPointer)((char *)&uStack_5a0);
                *(cvar_s **)&this_00[1].field_0x4 = pcVar12;
                pCVar13 = operator_new(0xd4);
                CImageLabel::CImageLabel(pCVar13,"checked",0,0);
                *(CImageLabel **)&this_00[1].field_0x8 = pCVar13;
                vgui::Panel::setParent((Panel *)pCVar13);
                (**(code **)(**(int **)&this_00[1].field_0x8 + 0x70))
                          (*(int **)&this_00[1].field_0x8,this_00 + 1);
                puVar23 = auStack_624;
                piVar22 = &iStack_628;
                vgui::Label::getTextSize((int *)this_00,piVar22);
                puVar11 = (undefined4 *)**(int **)&this_00[1].field_0x8;
                pcVar3 = (code *)*puVar11;
                iVar14 = (*(code *)puVar11[7])(*(int **)&this_00[1].field_0x8,piVar22,puVar23);
                (*pcVar3)(*(undefined4 *)&this_00[1].field_0x8,iStack_628,
                          ((int)flButtonSizeY - iVar14) / 2);
              }
              else {
                this_00 = operator_new(0x130);
                CommandButton::CommandButton
                          (this_00,(char *)&uStack_600,xOffset,iVar16,iVar17,(int)flButtonSizeY,
                           false);
                *(undefined ***)this_00 = &PTR_setPos_000c7ee8;
                CommandButton::Init(this_00);
                CommandButton::setText(this_00,(char *)&uStack_600);
              }
            }
            else {
              this_00 = operator_new(0x130);
              CommandButton::CommandButton
                        (this_00,iStack_640,(char *)&uStack_600,xOffset,iVar16,iVar17,
                         (int)flButtonSizeY,flatDesign);
            }
            bVar20 = true;
          }
          else {
            this_00 = operator_new(0x134);
            CommandButton::CommandButton
                      (this_00,(char *)&uStack_600,xOffset,iVar16,iVar17,(int)flButtonSizeY,false,
                       flatDesign);
            *(undefined ***)this_00 = &PTR_setPos_000c92b4;
            bVar20 = true;
            *(int *)(this_00 + 1) = iStack_648;
          }
        }
        else {
          this_00 = operator_new(0x230);
          CommandButton::CommandButton
                    (this_00,(char *)&uStack_600,xOffset,iVar16,iVar17,(int)flButtonSizeY,false);
          *(undefined ***)this_00 = &PTR_setPos_000c9044;
          __sprintf_chk(&this_00->field_0x12d,1,0x103,"maps/%s.bsp",&uStack_520);
          bVar20 = true;
        }
        if (this_00 != (CommandButton *)0x0) {
          pCVar7 = this->m_pCurrentCommandMenu;
          iVar14 = pCVar7->m_iButtons;
          if (iVar14 < 100) {
            pCVar7->m_aButtons[iVar14] = this_00;
            pCVar7->m_iButtons = iVar14 + 1;
            (**(code **)(*(int *)this_00 + 0x40))(this_00,pCVar7);
            (**(code **)(*(int *)this_00 + 0x208))(this_00,3);
            iVar14 = pCVar7->m_iButtons;
            if (iVar14 < 10) {
              CommandButton::setBoundKey(this_00,(char)iVar14 + '0');
            }
            else if (iVar14 == 10) {
              CommandButton::setBoundKey(this_00,'0');
            }
          }
          CommandButton::setBoundKey(this_00,(char)uStack_5e0);
          CommandButton::setParentMenu(this_00,this->m_pCurrentCommandMenu);
          (**(code **)(*(int *)this_00 + 0x208))(this_00,3);
        }
        if ((char)uStack_5a0 == '{') {
          iVar14 = this->m_iNumMenus;
          if (iVar14 < 0x50) {
            pCVar7 = CreateSubMenu(this,this_00,this->m_pCurrentCommandMenu,iVar16,0);
            this->m_pCommandMenus[iVar14] = pCVar7;
            pCVar7 = this->m_pCommandMenus[this->m_iNumMenus];
            this->m_iNumMenus = this->m_iNumMenus + 1;
            this->m_pCurrentCommandMenu = pCVar7;
          }
          else {
            (*gEngfuncs.Con_Printf)("Too many menus in %s past \'%s\'\n",menuFile,&uStack_620);
          }
        }
        else if (!bVar4) {
          if (bVar5) {
            pcVar3 = *(code **)(*(int *)this_00 + 0x240);
            puVar11 = operator_new(8);
            *puVar11 = &PTR_actionPerformed_000c818c;
            pcVar12 = (*gEngfuncs.pfnGetCvarPointer)((char *)&uStack_5a0);
            puVar11[1] = pcVar12;
            (*pcVar3)(this_00,puVar11);
          }
          else {
            pcVar3 = *(code **)(*(int *)this_00 + 0x240);
            puVar11 = operator_new(0x108);
            *puVar11 = &PTR_actionPerformed_000c3f68;
            strncpy((char *)(puVar11 + 1),(char *)&uStack_5a0,0x100);
            *(undefined1 *)((int)puVar11 + 0x103) = 0;
            puVar11[0x41] = 0;
            (*pcVar3)(this_00,puVar11);
          }
          pcVar3 = *(code **)(*(int *)this_00 + 0x70);
          puVar11 = operator_new(0xc);
          pCVar7 = this->m_pCurrentCommandMenu;
          *puVar11 = &PTR_cursorMoved_000c8158;
          puVar11[2] = this_00;
          puVar11[1] = pCVar7;
          (*pcVar3)(this_00,puVar11);
        }
        if (bVar20) {
          pcStack_658 = (*gEngfuncs.COM_ParseFile)(pcStack_658,acStack_420);
        }
      } while (acStack_420[0] != '\0');
      this->m_pCurrentCommandMenu = this->m_pCurrentCommandMenu->m_pParentMenu;
      pcStack_658 = (*gEngfuncs.COM_ParseFile)(pcStack_658,acStack_420);
    }
    this->m_pCurrentMenu = (CMenuPanel *)0x0;
    (*gEngfuncs.pfnClientCmd)("closemenus;");
    if (0 < this->m_iNumMenus) {
      iVar17 = 0;
      do {
        ppCVar1 = this->m_pCommandMenus + iVar17;
        iVar17 = iVar17 + 1;
        (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
      } while (iVar17 < this->m_iNumMenus);
    }
    this->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
    (*gEngfuncs.COM_FreeFile)(pcStack_658);
    this->m_iInitialized = 1;
  }
LAB_00097500:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// TeamFortressViewport::CreateDisguiseSubmenu  @ 00094390  (line 948)

/* DWARF original prototype: CCommandMenu * CreateDisguiseSubmenu(TeamFortressViewport * this,
   CommandButton * pButton, CCommandMenu * pParentMenu, char * commandText, int iYOffset, int
   iXOffset) */

CCommandMenu * __thiscall
TeamFortressViewport::CreateDisguiseSubmenu
          (TeamFortressViewport *this,CommandButton *pButton,CCommandMenu *pParentMenu,
          char *commandText,int iYOffset,int iXOffset)

{
  code *pcVar1;
  CCommandMenu *pCVar2;
  char *text;
  CommandButton *this_00;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_GS_OFFSET;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: CCommandMenu * pMenu@[???] */
                    /* Unresolved local var: int i@[???] */
  iVar5 = 1;
                    /* Unresolved local var: CommandButton * pDisguiseButton@[???]
                       Unresolved local var: char[256] sz@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pCVar2 = CreateSubMenu(this,pButton,pParentMenu,iYOffset,iXOffset);
  iVar3 = this->m_iNumMenus;
  this->m_pCommandMenus[iVar3] = pCVar2;
  this->m_iNumMenus = iVar3 + 1;
  do {
    while( true ) {
      text = CHudTextMessage::BufferedLocaliseTextString(sLocalisedClasses[iVar5]);
      this_00 = operator_new(0x130);
      iVar3 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
      CommandButton::CommandButton
                (this_00,text,0,iVar3,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar3,
                 false);
      __sprintf_chk(local_120,1,0x100,"%s %d",commandText,iVar5);
      pcVar1 = *(code **)(*(int *)this_00 + 0x240);
      puVar4 = operator_new(0x108);
      *puVar4 = &PTR_actionPerformed_000c3f68;
      strncpy((char *)(puVar4 + 1),local_120,0x100);
      puVar4[0x41] = 0;
      *(undefined1 *)((int)puVar4 + 0x103) = 0;
      (*pcVar1)(this_00,puVar4);
      iVar3 = pCVar2->m_iButtons;
      if (iVar3 < 100) break;
LAB_00094410:
      iVar5 = iVar5 + 1;
      if (iVar5 == 10) goto LAB_000945a0;
    }
    pCVar2->m_aButtons[iVar3] = this_00;
    pCVar2->m_iButtons = iVar3 + 1;
    (**(code **)(*(int *)this_00 + 0x40))(this_00,pCVar2);
    (**(code **)(*(int *)this_00 + 0x208))(this_00,3);
    iVar3 = pCVar2->m_iButtons;
    if (iVar3 < 10) {
      CommandButton::setBoundKey(this_00,(char)iVar3 + '0');
      goto LAB_00094410;
    }
    if (iVar3 != 10) goto LAB_00094410;
    iVar5 = iVar5 + 1;
    CommandButton::setBoundKey(this_00,'0');
  } while (iVar5 != 10);
LAB_000945a0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pCVar2;
}


// TeamFortressViewport::CreateCustomButton  @ 000945f0  (line 976)

/* DWARF original prototype: CommandButton * CreateCustomButton(TeamFortressViewport * this, char *
   pButtonText, char * pButtonName, int iYOffset) */

CommandButton * __thiscall
TeamFortressViewport::CreateCustomButton
          (TeamFortressViewport *this,char *pButtonText,char *pButtonName,int iYOffset)

{
  code *pcVar1;
  float fVar2;
  char cVar3;
  undefined4 *puVar4;
  CCommandMenu *pCVar5;
  CommandButton *pCVar6;
  TeamFortressViewport *pTVar7;
  int iVar8;
  int iVar9;
  CCommandMenu *pCVar10;
  int iVar11;
  char *pcVar12;
  int in_GS_OFFSET;
  bool bVar13;
  char *pcVar14;
  TeamFortressViewport *local_130;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: CommandButton * pButton@[???]
                       Unresolved local var: CCommandMenu * pMenu@[???] */
  iVar8 = 0xc;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar13 = true;
  pcVar14 = pButtonName;
  pcVar12 = "!CHANGETEAM";
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar13 = *pcVar14 == *pcVar12;
    pcVar14 = pcVar14 + 1;
    pcVar12 = pcVar12 + 1;
  } while (bVar13);
  if (bVar13) {
    local_130 = operator_new(0x130);
    fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
    CommandButton::CommandButton
              ((CommandButton *)local_130,pButtonText,0,(int)(fVar2 + fVar2),
               (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),(int)fVar2,false);
                    /* Unresolved local var: int i@[???] */
    pCVar5 = CreateSubMenu(this,(CommandButton *)local_130,this->m_pCurrentCommandMenu,iYOffset,0);
    iVar8 = this->m_iNumMenus;
    this->m_pCommandMenus[iVar8] = pCVar5;
    this->m_iNumMenus = iVar8 + 1;
    iVar8 = 0;
    do {
                    /* Unresolved local var: char[256] sz@[???] */
      iVar11 = iVar8 + 1;
      __sprintf_chk(local_120,1,0x100,"jointeam %d",iVar11);
      pCVar6 = operator_new(0x134);
      iVar9 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
      CommandButton::CommandButton
                (pCVar6,"teamname",0,iVar9,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),
                 iVar9,false);
      *(undefined ***)pCVar6 = &PTR_setPos_000c81a4;
      *(int *)(pCVar6 + 1) = iVar11;
      this->m_pTeamButtons[iVar8] = pCVar6;
      puVar4 = operator_new(0x108);
      strncpy((char *)(puVar4 + 1),local_120,0x100);
      puVar4[0x41] = 0;
      *(undefined1 *)((int)puVar4 + 0x103) = 0;
      *puVar4 = &PTR_actionPerformed_000c64ac;
      vgui::Button::addActionSignal((ActionSignal *)this->m_pTeamButtons[iVar8]);
      iVar9 = pCVar5->m_iButtons;
      if (iVar9 < 100) {
        pCVar6 = this->m_pTeamButtons[iVar8];
        pCVar5->m_aButtons[iVar9] = pCVar6;
        pCVar5->m_iButtons = iVar9 + 1;
        (**(code **)(*(int *)pCVar6 + 0x40))(pCVar6,pCVar5);
        (**(code **)(*(int *)pCVar6 + 0x208))(pCVar6,3);
        iVar8 = pCVar5->m_iButtons;
        if (iVar8 < 10) {
          CommandButton::setBoundKey(pCVar6,(char)iVar8 + '0');
        }
        else if (iVar8 == 10) {
          CommandButton::setBoundKey(pCVar6,'0');
        }
      }
      iVar8 = iVar11;
    } while (iVar11 != 4);
    pcVar14 = CHudTextMessage::BufferedLocaliseTextString("#Team_AutoAssign");
    pCVar6 = operator_new(0x134);
    iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
    CommandButton::CommandButton
              (pCVar6,pcVar14,0,iVar8,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,
               false);
    *(undefined4 *)(pCVar6 + 1) = 5;
    *(undefined ***)pCVar6 = &PTR_setPos_000c81a4;
    this->m_pTeamButtons[4] = pCVar6;
    puVar4 = operator_new(0x108);
    *puVar4 = &PTR_actionPerformed_000c3f68;
    strncpy((char *)(puVar4 + 1),"jointeam 5",0x100);
    puVar4[0x41] = 0;
    *(undefined1 *)((int)puVar4 + 0x103) = 0;
    vgui::Button::addActionSignal((ActionSignal *)this->m_pTeamButtons[4]);
    iVar8 = pCVar5->m_iButtons;
    if (iVar8 < 100) {
      pCVar6 = this->m_pTeamButtons[4];
      pCVar5->m_aButtons[iVar8] = pCVar6;
      pCVar5->m_iButtons = iVar8 + 1;
      (**(code **)(*(int *)pCVar6 + 0x40))(pCVar6,pCVar5);
      (**(code **)(*(int *)pCVar6 + 0x208))(pCVar6,3);
      iVar8 = pCVar5->m_iButtons;
      if (iVar8 < 10) {
        CommandButton::setBoundKey(pCVar6,(char)iVar8 + '0');
      }
      else if (iVar8 == 10) {
        CommandButton::setBoundKey(pCVar6,'0');
      }
    }
    pcVar14 = CHudTextMessage::BufferedLocaliseTextString("#Menu_Spectate");
    pCVar6 = operator_new(0x130);
    iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
    CommandButton::CommandButton
              (pCVar6,pcVar14,0,iVar8,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,
               false);
    *(undefined ***)pCVar6 = &PTR_setPos_000c8684;
    this->m_pTeamButtons[5] = pCVar6;
    pButtonText = operator_new(0x108);
    *(undefined ***)pButtonText = &PTR_actionPerformed_000c3f68;
    strncpy(&((TeamFortressViewport *)pButtonText)->field_0x4,"spectate",0x100);
    *(undefined1 *)((int)((TeamFortressViewport *)pButtonText)->m_pCommandMenus + 0x3b) = 0;
    ((TeamFortressViewport *)pButtonText)->m_pCommandMenus[0xf] = (CCommandMenu *)0x0;
    pButtonName = (char *)this->m_pTeamButtons[5];
    vgui::Button::addActionSignal((ActionSignal *)pButtonName);
    iVar8 = pCVar5->m_iButtons;
    if (iVar8 < 100) {
      pTVar7 = (TeamFortressViewport *)this->m_pTeamButtons[5];
      pCVar5->m_aButtons[iVar8] = (CommandButton *)pTVar7;
      pCVar5->m_iButtons = iVar8 + 1;
      (**(code **)(*(int *)pTVar7 + 0x40))(pTVar7,pCVar5);
      pButtonText = (char *)0x3;
      pButtonName = (char *)pTVar7;
      (**(code **)(*(int *)pTVar7 + 0x208))(pTVar7,3);
      iVar8 = pCVar5->m_iButtons;
      if (iVar8 < 10) {
        cVar3 = (char)iVar8 + '0';
        pButtonText = (char *)(int)cVar3;
        CommandButton::setBoundKey((CommandButton *)pTVar7,cVar3);
        pButtonName = (char *)pTVar7;
      }
      else if (iVar8 == 10) {
        pButtonText = (char *)0x30;
        CommandButton::setBoundKey((CommandButton *)pTVar7,'0');
        pButtonName = (char *)pTVar7;
      }
    }
    goto LAB_000949c0;
  }
  iVar8 = 0xd;
  bVar13 = false;
  pcVar14 = pButtonName;
  pcVar12 = "!CHANGECLASS";
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar13 = *pcVar14 == *pcVar12;
    pcVar14 = pcVar14 + 1;
    pcVar12 = pcVar12 + 1;
  } while (bVar13);
  if (bVar13) {
    local_130 = operator_new(0x134);
    iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
    CommandButton::CommandButton
              ((CommandButton *)local_130,pButtonText,0,iVar8,
               (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
    *(undefined ***)local_130 = &PTR_setPos_000c5240;
    local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0xffffffff;
    pCVar5 = CreateSubMenu(this,(CommandButton *)local_130,this->m_pCurrentCommandMenu,iYOffset,0);
    iVar8 = this->m_iNumMenus;
    this->m_pCommandMenus[iVar8] = pCVar5;
    this->m_iNumMenus = iVar8 + 1;
                    /* Unresolved local var: int i@[???] */
    pCVar10 = (CCommandMenu *)0x1;
    do {
                    /* Unresolved local var: char[256] sz@[???]
                       Unresolved local var: ClassButton * pClassButton@[???] */
      CHudTextMessage::LocaliseTextString(sLocalisedClasses[(int)pCVar10],local_120,0x100);
      pTVar7 = operator_new(0x134);
      iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
      CommandButton::CommandButton
                ((CommandButton *)pTVar7,local_120,0,iVar8,
                 (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
      pcVar14 = sTFClassSelection[(int)pCVar10];
      *(undefined ***)pTVar7 = &PTR_setPos_000c5240;
      pTVar7->m_pCommandMenus[0x1a] = pCVar10;
      __sprintf_chk(local_120,1,0x100,&DAT_000c4b6e,pcVar14);
      pcVar1 = *(code **)(*(int *)pTVar7 + 0x240);
      pButtonText = operator_new(0x108);
      strncpy(&((TeamFortressViewport *)pButtonText)->field_0x4,local_120,0x100);
      ((TeamFortressViewport *)pButtonText)->m_pCommandMenus[0xf] = (CCommandMenu *)0x0;
      *(undefined1 *)((int)((TeamFortressViewport *)pButtonText)->m_pCommandMenus + 0x3b) = 0;
      *(undefined ***)pButtonText = &PTR_actionPerformed_000c5ddc;
      pButtonName = (char *)pTVar7;
      (*pcVar1)(pTVar7,pButtonText);
      iVar8 = pCVar5->m_iButtons;
      if (iVar8 < 100) {
        pCVar5->m_aButtons[iVar8] = (CommandButton *)pTVar7;
        pCVar5->m_iButtons = iVar8 + 1;
        (**(code **)(*(int *)pTVar7 + 0x40))(pTVar7,pCVar5);
        pButtonText = (char *)0x3;
        pButtonName = (char *)pTVar7;
        (**(code **)(*(int *)pTVar7 + 0x208))(pTVar7,3);
        iVar8 = pCVar5->m_iButtons;
        if (iVar8 < 10) {
          cVar3 = (char)iVar8 + '0';
          pButtonText = (char *)(int)cVar3;
          CommandButton::setBoundKey((CommandButton *)pTVar7,cVar3);
          pButtonName = (char *)pTVar7;
        }
        else if (iVar8 == 10) {
          pButtonText = (char *)0x30;
          CommandButton::setBoundKey((CommandButton *)pTVar7,'0');
          pButtonName = (char *)pTVar7;
        }
      }
      pCVar10 = (CCommandMenu *)&pCVar10->field_0x1;
    } while (pCVar10 != (CCommandMenu *)0xb);
    goto LAB_000949c0;
  }
  iVar8 = 0xd;
  bVar13 = false;
  pcVar14 = pButtonName;
  pcVar12 = "!MAPBRIEFING";
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar13 = *pcVar14 == *pcVar12;
    pcVar14 = pcVar14 + 1;
    pcVar12 = pcVar12 + 1;
  } while (bVar13);
  if (bVar13) {
    fVar2 = (float)gHUD.m_scrinfo.iHeight;
    iVar8 = this->m_pCurrentCommandMenu->m_iButtons;
    local_130 = operator_new(0x130);
    CommandButton::CommandButton
              ((CommandButton *)local_130,pButtonText,0,(int)((float)iVar8 * (fVar2 / 480.0) * 30.0)
               ,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),
               (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0),false);
    puVar4 = operator_new(8);
    *puVar4 = &PTR_actionPerformed_000c3f74;
    puVar4[1] = 4;
  }
  else {
    iVar8 = 0xb;
    bVar13 = false;
    pcVar14 = pButtonName;
    pcVar12 = "!CLASSDESC";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar13 = *pcVar14 == *pcVar12;
      pcVar14 = pcVar14 + 1;
      pcVar12 = pcVar12 + 1;
    } while (bVar13);
    if (bVar13) {
      fVar2 = (float)gHUD.m_scrinfo.iHeight;
      iVar8 = this->m_pCurrentCommandMenu->m_iButtons;
      local_130 = operator_new(0x134);
      CommandButton::CommandButton
                ((CommandButton *)local_130,pButtonText,0,
                 (int)((float)iVar8 * (fVar2 / 480.0) * 30.0),
                 (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),
                 (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0),false);
      *(undefined ***)local_130 = &PTR_setPos_000c5240;
      local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x0;
      puVar4 = operator_new(8);
      *puVar4 = &PTR_actionPerformed_000c3f74;
      puVar4[1] = 6;
    }
    else {
      iVar8 = 0xc;
      bVar13 = false;
      pcVar14 = pButtonName;
      pcVar12 = "!SERVERINFO";
      do {
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        bVar13 = *pcVar14 == *pcVar12;
        pcVar14 = pcVar14 + 1;
        pcVar12 = pcVar12 + 1;
      } while (bVar13);
      if (!bVar13) {
        iVar8 = 5;
        pcVar14 = pButtonName;
        pcVar12 = "!SPY";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar13 = *pcVar14 == *pcVar12;
          pcVar14 = pcVar14 + 1;
          pcVar12 = pcVar12 + 1;
        } while (bVar13);
        if (bVar13) {
          local_130 = operator_new(0x138);
          iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
          pButtonName = (char *)local_130;
          CommandButton::CommandButton
                    ((CommandButton *)local_130,pButtonText,0,iVar8,
                     (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
          *(undefined ***)local_130 = &PTR_setPos_000c88f4;
          local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x0;
          goto LAB_000949c0;
        }
        iVar8 = 7;
        bVar13 = false;
        pcVar14 = pButtonName;
        pcVar12 = "!FEIGN";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar13 = *pcVar14 == *pcVar12;
          pcVar14 = pcVar14 + 1;
          pcVar12 = pcVar12 + 1;
        } while (bVar13);
        if (bVar13) {
          local_130 = operator_new(0x134);
          iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
          CommandButton::CommandButton
                    ((CommandButton *)local_130,pButtonText,0,iVar8,
                     (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
          *(undefined ***)local_130 = &PTR_setPos_000c8414;
          local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x0;
LAB_00095538:
          puVar4 = operator_new(0x108);
          *puVar4 = &PTR_actionPerformed_000c3f68;
          pcVar14 = "feign";
LAB_0009555e:
          strncpy((char *)(puVar4 + 1),pcVar14,0x100);
          puVar4[0x41] = 0;
          *(undefined1 *)((int)puVar4 + 0x103) = 0;
          vgui::Button::addActionSignal((ActionSignal *)local_130);
          pcVar1 = *(code **)(*(int *)local_130 + 0x70);
          pButtonText = operator_new(0xc);
          pCVar5 = this->m_pCurrentCommandMenu;
          *(undefined ***)pButtonText = &PTR_cursorMoved_000c8158;
          *(CCommandMenu **)&((TeamFortressViewport *)pButtonText)->field_0x4 = pCVar5;
          *(TeamFortressViewport **)&((TeamFortressViewport *)pButtonText)->field_0x8 = local_130;
          pButtonName = (char *)local_130;
          (*pcVar1)(local_130,pButtonText);
        }
        else {
          iVar8 = 0xd;
          bVar13 = false;
          pcVar14 = pButtonName;
          pcVar12 = "!FEIGNSILENT";
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar13 = *pcVar14 == *pcVar12;
            pcVar14 = pcVar14 + 1;
            pcVar12 = pcVar12 + 1;
          } while (bVar13);
          if (bVar13) {
            local_130 = operator_new(0x134);
            iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
            CommandButton::CommandButton
                      ((CommandButton *)local_130,pButtonText,0,iVar8,
                       (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
            *(undefined ***)local_130 = &PTR_setPos_000c8414;
            local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x0;
            puVar4 = operator_new(0x108);
            *puVar4 = &PTR_actionPerformed_000c3f68;
            pcVar14 = "sfeign";
            goto LAB_0009555e;
          }
          iVar8 = 0xb;
          bVar13 = false;
          pcVar14 = pButtonName;
          pcVar12 = "!FEIGNSTOP";
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar13 = *pcVar14 == *pcVar12;
            pcVar14 = pcVar14 + 1;
            pcVar12 = pcVar12 + 1;
          } while (bVar13);
          if (bVar13) {
            local_130 = operator_new(0x134);
            iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
            CommandButton::CommandButton
                      ((CommandButton *)local_130,pButtonText,0,iVar8,
                       (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
            *(undefined ***)local_130 = &PTR_setPos_000c8414;
            local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
            goto LAB_00095538;
          }
          iVar8 = 0xf;
          bVar13 = false;
          pcVar14 = pButtonName;
          pcVar12 = "!DISGUISEENEMY";
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar13 = *pcVar14 == *pcVar12;
            pcVar14 = pcVar14 + 1;
            pcVar12 = pcVar12 + 1;
          } while (bVar13);
          if (bVar13) {
            local_130 = operator_new(0x138);
            iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
            CommandButton::CommandButton
                      ((CommandButton *)local_130,pButtonText,0,iVar8,
                       (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
            *(undefined ***)local_130 = &PTR_setPos_000c88f4;
            local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x2;
            pcVar14 = "disguise_enemy";
          }
          else {
            iVar8 = 0x12;
            bVar13 = false;
            pcVar14 = pButtonName;
            pcVar12 = "!DISGUISEFRIENDLY";
            do {
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              bVar13 = *pcVar14 == *pcVar12;
              pcVar14 = pcVar14 + 1;
              pcVar12 = pcVar12 + 1;
            } while (bVar13);
            if (!bVar13) {
              iVar8 = 10;
              pcVar14 = pButtonName;
              pcVar12 = "!DISGUISE";
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar13 = *pcVar14 == *pcVar12;
                pcVar14 = pcVar14 + 1;
                pcVar12 = pcVar12 + 1;
              } while (bVar13);
              if (bVar13) {
                    /* Unresolved local var: CCommandMenu * pDisguiseMenu@[???] */
                local_130 = operator_new(0x138);
                iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
                CommandButton::CommandButton
                          ((CommandButton *)local_130,pButtonText,0,iVar8,
                           (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
                *(undefined ***)local_130 = &PTR_setPos_000c88f4;
                local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0xc;
                pCVar5 = CreateSubMenu(this,(CommandButton *)local_130,this->m_pCurrentCommandMenu,
                                       iYOffset,0);
                iVar8 = this->m_iNumMenus;
                this->m_pCommandMenus[iVar8] = pCVar5;
                    /* Unresolved local var: int i@[???] */
                iVar9 = 1;
                this->m_iNumMenus = iVar8 + 1;
                do {
                    /* Unresolved local var: char[256] sz@[???] */
                  pCVar6 = operator_new(0x138);
                  iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
                  CommandButton::CommandButton
                            (pCVar6,"Disguise",0,iVar8,
                             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
                  *(uint *)(pCVar6 + 1) = (uint)(iVar9 != 4) * 4 + 8;
                  *(undefined ***)pCVar6 = &PTR_setPos_000c88f4;
                  this->m_pDisguiseButtons[iVar9] = pCVar6;
                  iVar8 = pCVar5->m_iButtons;
                  if (iVar8 < 100) {
                    pCVar5->m_aButtons[iVar8] = pCVar6;
                    pCVar5->m_iButtons = iVar8 + 1;
                    (**(code **)(*(int *)pCVar6 + 0x40))(pCVar6,pCVar5);
                    (**(code **)(*(int *)pCVar6 + 0x208))(pCVar6,3);
                    iVar8 = pCVar5->m_iButtons;
                    if (iVar8 < 10) {
                      CommandButton::setBoundKey(pCVar6,(char)iVar8 + '0');
                      pCVar6 = this->m_pDisguiseButtons[iVar9];
                    }
                    else {
                      if (iVar8 == 10) {
                        CommandButton::setBoundKey(pCVar6,'0');
                      }
                      pCVar6 = this->m_pDisguiseButtons[iVar9];
                    }
                  }
                  CommandButton::setParentMenu(pCVar6,pCVar5);
                  __sprintf_chk(local_120,1,0x100,"disguise %d",iVar9);
                  pButtonText = (char *)this->m_pDisguiseButtons[iVar9];
                  iVar9 = iVar9 + 1;
                  pButtonName = (char *)this;
                  CreateDisguiseSubmenu
                            (this,(CommandButton *)pButtonText,pCVar5,local_120,iYOffset,
                             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0 - 1.0));
                } while (iVar9 != 5);
                goto LAB_000949c0;
              }
              iVar8 = 0xe;
              bVar13 = false;
              pcVar14 = pButtonName;
              pcVar12 = "!DETPACKSTART";
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar13 = *pcVar14 == *pcVar12;
                pcVar14 = pcVar14 + 1;
                pcVar12 = pcVar12 + 1;
              } while (bVar13);
              if (bVar13) {
                    /* Unresolved local var: CommandButton * pDetButton@[???] */
                local_130 = operator_new(0x134);
                fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                CommandButton::CommandButton
                          ((CommandButton *)local_130,pButtonText,0,(int)(fVar2 + fVar2),
                           (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),(int)fVar2,false);
                local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x2;
                *(undefined ***)local_130 = &PTR_setPos_000c8b64;
                pCVar5 = CreateSubMenu(this,(CommandButton *)local_130,this->m_pCurrentCommandMenu,
                                       iYOffset,0);
                iVar8 = this->m_iNumMenus;
                this->m_pCommandMenus[iVar8] = pCVar5;
                this->m_iNumMenus = iVar8 + 1;
                pCVar6 = operator_new(0x130);
                iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
                CommandButton::CommandButton
                          (pCVar6,this->m_sDetpackStrings[0],0,iVar8,
                           (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
                puVar4 = operator_new(0x108);
                *puVar4 = &PTR_actionPerformed_000c3f68;
                strncpy((char *)(puVar4 + 1),"detstart 5",0x100);
                puVar4[0x41] = 0;
                *(undefined1 *)((int)puVar4 + 0x103) = 0;
                vgui::Button::addActionSignal((ActionSignal *)pCVar6);
                iVar8 = pCVar5->m_iButtons;
                if (iVar8 < 100) {
                  pCVar5->m_aButtons[iVar8] = pCVar6;
                  pCVar5->m_iButtons = iVar8 + 1;
                  (**(code **)(*(int *)pCVar6 + 0x40))(pCVar6,pCVar5);
                  (**(code **)(*(int *)pCVar6 + 0x208))(pCVar6,3);
                  iVar8 = pCVar5->m_iButtons;
                  if (iVar8 < 10) {
                    CommandButton::setBoundKey(pCVar6,(char)iVar8 + '0');
                  }
                  else if (iVar8 == 10) {
                    CommandButton::setBoundKey(pCVar6,'0');
                  }
                }
                pCVar6 = operator_new(0x130);
                iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
                CommandButton::CommandButton
                          (pCVar6,this->m_sDetpackStrings[1],0,iVar8,
                           (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
                puVar4 = operator_new(0x108);
                *puVar4 = &PTR_actionPerformed_000c3f68;
                strncpy((char *)(puVar4 + 1),"detstart 20",0x100);
                puVar4[0x41] = 0;
                *(undefined1 *)((int)puVar4 + 0x103) = 0;
                vgui::Button::addActionSignal((ActionSignal *)pCVar6);
                iVar8 = pCVar5->m_iButtons;
                if (iVar8 < 100) {
                  pCVar5->m_aButtons[iVar8] = pCVar6;
                  pCVar5->m_iButtons = iVar8 + 1;
                  (**(code **)(*(int *)pCVar6 + 0x40))(pCVar6,pCVar5);
                  (**(code **)(*(int *)pCVar6 + 0x208))(pCVar6,3);
                  iVar8 = pCVar5->m_iButtons;
                  if (iVar8 < 10) {
                    CommandButton::setBoundKey(pCVar6,(char)iVar8 + '0');
                  }
                  else if (iVar8 == 10) {
                    CommandButton::setBoundKey(pCVar6,'0');
                  }
                }
                pTVar7 = operator_new(0x130);
                iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
                CommandButton::CommandButton
                          ((CommandButton *)pTVar7,this->m_sDetpackStrings[2],0,iVar8,
                           (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
                pButtonText = operator_new(0x108);
                *(undefined ***)pButtonText = &PTR_actionPerformed_000c3f68;
                strncpy(&((TeamFortressViewport *)pButtonText)->field_0x4,"detstart 50",0x100);
                ((TeamFortressViewport *)pButtonText)->m_pCommandMenus[0xf] = (CCommandMenu *)0x0;
                *(undefined1 *)((int)((TeamFortressViewport *)pButtonText)->m_pCommandMenus + 0x3b)
                     = 0;
                pButtonName = (char *)pTVar7;
                vgui::Button::addActionSignal((ActionSignal *)pTVar7);
                iVar8 = pCVar5->m_iButtons;
                if (iVar8 < 100) {
                  pCVar5->m_aButtons[iVar8] = (CommandButton *)pTVar7;
                  pCVar5->m_iButtons = iVar8 + 1;
                  (**(code **)(*(int *)pTVar7 + 0x40))(pTVar7,pCVar5);
                  pButtonText = (char *)0x3;
                  pButtonName = (char *)pTVar7;
                  (**(code **)(*(int *)pTVar7 + 0x208))(pTVar7,3);
                  iVar8 = pCVar5->m_iButtons;
                  if (iVar8 < 10) {
                    cVar3 = (char)iVar8 + '0';
                    pButtonText = (char *)(int)cVar3;
                    CommandButton::setBoundKey((CommandButton *)pTVar7,cVar3);
                    pButtonName = (char *)pTVar7;
                  }
                  else if (iVar8 == 10) {
                    pButtonText = (char *)0x30;
                    CommandButton::setBoundKey((CommandButton *)pTVar7,'0');
                    pButtonName = (char *)pTVar7;
                  }
                }
                goto LAB_000949c0;
              }
              iVar8 = 0xd;
              bVar13 = false;
              pcVar14 = pButtonName;
              pcVar12 = "!DETPACKSTOP";
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar13 = *pcVar14 == *pcVar12;
                pcVar14 = pcVar14 + 1;
                pcVar12 = pcVar12 + 1;
              } while (bVar13);
              if (bVar13) {
                local_130 = operator_new(0x134);
                iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
                CommandButton::CommandButton
                          ((CommandButton *)local_130,pButtonText,0,iVar8,
                           (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
                *(undefined ***)local_130 = &PTR_setPos_000c8b64;
                local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
                puVar4 = operator_new(0x108);
                *puVar4 = &PTR_actionPerformed_000c3f68;
                pcVar14 = "detstop";
              }
              else {
                iVar8 = 7;
                bVar13 = false;
                pcVar14 = pButtonName;
                pcVar12 = "!BUILD";
                do {
                  if (iVar8 == 0) break;
                  iVar8 = iVar8 + -1;
                  bVar13 = *pcVar14 == *pcVar12;
                  pcVar14 = pcVar14 + 1;
                  pcVar12 = pcVar12 + 1;
                } while (bVar13);
                if (bVar13) {
                  local_130 = operator_new(0x138);
                  fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                  pButtonName = (char *)local_130;
                  CommandButton::CommandButton
                            ((CommandButton *)local_130,pButtonText,0,(int)(fVar2 + fVar2),
                             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),(int)fVar2,false)
                  ;
                  *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                  local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x4;
                  local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x0;
                  goto LAB_000949c0;
                }
                iVar8 = 0xd;
                bVar13 = false;
                pcVar14 = pButtonName;
                pcVar12 = "!BUILDSENTRY";
                do {
                  if (iVar8 == 0) break;
                  iVar8 = iVar8 + -1;
                  bVar13 = *pcVar14 == *pcVar12;
                  pcVar14 = pcVar14 + 1;
                  pcVar12 = pcVar12 + 1;
                } while (bVar13);
                if (bVar13) {
                  local_130 = operator_new(0x138);
                  fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                  CommandButton::CommandButton
                            ((CommandButton *)local_130,pButtonText,0,(int)(fVar2 + fVar2),
                             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),(int)fVar2,false)
                  ;
                  *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                  local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x8;
                  local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x1;
                  puVar4 = operator_new(0x108);
                  *puVar4 = &PTR_actionPerformed_000c3f68;
                  pcVar14 = "build 2";
                }
                else {
                  iVar8 = 0x10;
                  bVar13 = false;
                  pcVar14 = pButtonName;
                  pcVar12 = "!BUILDDISPENSER";
                  do {
                    if (iVar8 == 0) break;
                    iVar8 = iVar8 + -1;
                    bVar13 = *pcVar14 == *pcVar12;
                    pcVar14 = pcVar14 + 1;
                    pcVar12 = pcVar12 + 1;
                  } while (bVar13);
                  if (bVar13) {
                    local_130 = operator_new(0x138);
                    fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                    CommandButton::CommandButton
                              ((CommandButton *)local_130,pButtonText,0,(int)(fVar2 + fVar2),
                               (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),(int)fVar2,
                               false);
                    *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                    local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x8;
                    local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x0;
                    puVar4 = operator_new(0x108);
                    *puVar4 = &PTR_actionPerformed_000c3f68;
                    pcVar14 = "build 1";
                  }
                  else {
                    iVar8 = 0x11;
                    bVar13 = false;
                    pcVar14 = pButtonName;
                    pcVar12 = "!ROTATESENTRY180";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar13 = *pcVar14 == *pcVar12;
                      pcVar14 = pcVar14 + 1;
                      pcVar12 = pcVar12 + 1;
                    } while (bVar13);
                    if (bVar13) {
                      local_130 = operator_new(0x138);
                      fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                      CommandButton::CommandButton
                                ((CommandButton *)local_130,pButtonText,0,(int)(fVar2 + fVar2),
                                 (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),(int)fVar2,
                                 false);
                      *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                      local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
                      local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x1;
                      puVar4 = operator_new(0x108);
                      *puVar4 = &PTR_actionPerformed_000c3f68;
                      pcVar14 = "rotatesentry180";
                    }
                    else {
                      iVar8 = 0xe;
                      bVar13 = false;
                      pcVar14 = pButtonName;
                      pcVar12 = "!ROTATESENTRY";
                      do {
                        if (iVar8 == 0) break;
                        iVar8 = iVar8 + -1;
                        bVar13 = *pcVar14 == *pcVar12;
                        pcVar14 = pcVar14 + 1;
                        pcVar12 = pcVar12 + 1;
                      } while (bVar13);
                      if (bVar13) {
                        local_130 = operator_new(0x138);
                        fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                        CommandButton::CommandButton
                                  ((CommandButton *)local_130,pButtonText,0,(int)(fVar2 + fVar2),
                                   (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),(int)fVar2,
                                   false);
                        *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                        local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
                        local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x1;
                        puVar4 = operator_new(0x108);
                        *puVar4 = &PTR_actionPerformed_000c3f68;
                        pcVar14 = "rotatesentry";
                      }
                      else {
                        iVar8 = 0x14;
                        bVar13 = false;
                        pcVar14 = pButtonName;
                        pcVar12 = "!DISMANTLEDISPENSER";
                        do {
                          if (iVar8 == 0) break;
                          iVar8 = iVar8 + -1;
                          bVar13 = *pcVar14 == *pcVar12;
                          pcVar14 = pcVar14 + 1;
                          pcVar12 = pcVar12 + 1;
                        } while (bVar13);
                        if (bVar13) {
                          local_130 = operator_new(0x138);
                          fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                          CommandButton::CommandButton
                                    ((CommandButton *)local_130,pButtonText,0,(int)(fVar2 + fVar2),
                                     (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),
                                     (int)fVar2,false);
                          *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                          local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
                          local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x0;
                          puVar4 = operator_new(0x108);
                          *puVar4 = &PTR_actionPerformed_000c3f68;
                          pcVar14 = "dismantle 1";
                        }
                        else {
                          iVar8 = 0x11;
                          bVar13 = false;
                          pcVar14 = pButtonName;
                          pcVar12 = "!DISMANTLESENTRY";
                          do {
                            if (iVar8 == 0) break;
                            iVar8 = iVar8 + -1;
                            bVar13 = *pcVar14 == *pcVar12;
                            pcVar14 = pcVar14 + 1;
                            pcVar12 = pcVar12 + 1;
                          } while (bVar13);
                          if (!bVar13) {
                            iVar8 = strcmp(pButtonName,"!DETONATEDISPENSER");
                            if (iVar8 == 0) {
                              local_130 = operator_new(0x138);
                              fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                              CommandButton::CommandButton
                                        ((CommandButton *)local_130,pButtonText,0,
                                         (int)(fVar2 + fVar2),
                                         (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),
                                         (int)fVar2,false);
                              *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                              local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
                              local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x0;
                              puVar4 = operator_new(0x108);
                              *puVar4 = &PTR_actionPerformed_000c3f68;
                              pcVar14 = "detdispenser";
                            }
                            else {
                              iVar8 = strcmp(pButtonName,"!DETONATESENTRY");
                              if (iVar8 == 0) {
                                local_130 = operator_new(0x138);
                                fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                                CommandButton::CommandButton
                                          ((CommandButton *)local_130,pButtonText,0,
                                           (int)(fVar2 + fVar2),
                                           (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),
                                           (int)fVar2,false);
                                *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                                local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
                                local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x1;
                                puVar4 = operator_new(0x108);
                                *puVar4 = &PTR_actionPerformed_000c3f68;
                                pcVar14 = "detsentry";
                                goto LAB_0009555e;
                              }
                              iVar8 = strcmp(pButtonName,"!BUILDENTRYTELEPORTER");
                              if (iVar8 == 0) {
                                local_130 = operator_new(0x138);
                                fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                                CommandButton::CommandButton
                                          ((CommandButton *)local_130,pButtonText,0,
                                           (int)(fVar2 + fVar2),
                                           (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),
                                           (int)fVar2,false);
                                *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                                local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x8;
                                local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x2;
                                puVar4 = operator_new(0x108);
                                *puVar4 = &PTR_actionPerformed_000c3f68;
                                pcVar14 = "build 4";
                              }
                              else {
                                iVar8 = strcmp(pButtonName,"!DISMANTLEENTRYTELEPORTER");
                                if (iVar8 == 0) {
                                  local_130 = operator_new(0x138);
                                  fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                                  CommandButton::CommandButton
                                            ((CommandButton *)local_130,pButtonText,0,
                                             (int)(fVar2 + fVar2),
                                             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),
                                             (int)fVar2,false);
                                  *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                                  local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
                                  local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x2;
                                  puVar4 = operator_new(0x108);
                                  *puVar4 = &PTR_actionPerformed_000c3f68;
                                  pcVar14 = "dismantle 4";
                                  goto LAB_0009555e;
                                }
                                iVar8 = strcmp(pButtonName,"!DETONATEENTRYTELEPORTER");
                                if (iVar8 == 0) {
                                  local_130 = operator_new(0x138);
                                  fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                                  CommandButton::CommandButton
                                            ((CommandButton *)local_130,pButtonText,0,
                                             (int)(fVar2 + fVar2),
                                             (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),
                                             (int)fVar2,false);
                                  *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                                  local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
                                  local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x2;
                                  puVar4 = operator_new(0x108);
                                  *puVar4 = &PTR_actionPerformed_000c3f68;
                                  pcVar14 = "detentryteleporter";
                                }
                                else {
                                  iVar8 = strcmp(pButtonName,"!BUILDEXITTELEPORTER");
                                  if (iVar8 == 0) {
                                    local_130 = operator_new(0x138);
                                    fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                                    CommandButton::CommandButton
                                              ((CommandButton *)local_130,pButtonText,0,
                                               (int)(fVar2 + fVar2),
                                               (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0)
                                               ,(int)fVar2,false);
                                    *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                                    local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x8;
                                    local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x3;
                                    puVar4 = operator_new(0x108);
                                    *puVar4 = &PTR_actionPerformed_000c3f68;
                                    pcVar14 = "build 5";
                                    goto LAB_0009555e;
                                  }
                                  iVar8 = strcmp(pButtonName,"!DISMANTLEEXITTELEPORTER");
                                  if (iVar8 == 0) {
                                    local_130 = operator_new(0x138);
                                    fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                                    CommandButton::CommandButton
                                              ((CommandButton *)local_130,pButtonText,0,
                                               (int)(fVar2 + fVar2),
                                               (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0)
                                               ,(int)fVar2,false);
                                    *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                                    local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
                                    local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x3;
                                    puVar4 = operator_new(0x108);
                                    *puVar4 = &PTR_actionPerformed_000c3f68;
                                    pcVar14 = "dismantle 5";
                                  }
                                  else {
                                    iVar8 = strcmp(pButtonName,"!DETONATEEXITTELEPORTER");
                                    if (iVar8 == 0) {
                                      local_130 = operator_new(0x138);
                                      fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                                      CommandButton::CommandButton
                                                ((CommandButton *)local_130,pButtonText,0,
                                                 (int)(fVar2 + fVar2),
                                                 (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) *
                                                      160.0),(int)fVar2,false);
                                      *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                                      local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
                                      local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x3;
                                      puVar4 = operator_new(0x108);
                                      *puVar4 = &PTR_actionPerformed_000c3f68;
                                      pcVar14 = "detexitteleporter";
                                      goto LAB_0009555e;
                                    }
                                    pcVar14 = "!BUILDSTOP";
                                    iVar8 = strcmp(pButtonName,"!BUILDSTOP");
                                    if (iVar8 != 0) {
                                      local_130 = (TeamFortressViewport *)0x0;
                                      pButtonText = pcVar14;
                                      goto LAB_000949c0;
                                    }
                                    local_130 = operator_new(0x138);
                                    fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                                    CommandButton::CommandButton
                                              ((CommandButton *)local_130,pButtonText,0,
                                               (int)(fVar2 + fVar2),
                                               (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0)
                                               ,(int)fVar2,false);
                                    *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                                    local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x2;
                                    local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x0;
                                    puVar4 = operator_new(0x108);
                                    *puVar4 = &PTR_actionPerformed_000c3f68;
                                    pcVar14 = "build";
                                  }
                                }
                              }
                            }
                            strncpy((char *)(puVar4 + 1),pcVar14,0x100);
                            *(undefined1 *)((int)puVar4 + 0x103) = 0;
                            puVar4[0x41] = 0;
                            vgui::Button::addActionSignal((ActionSignal *)local_130);
                            pcVar1 = *(code **)(*(int *)local_130 + 0x70);
                            pButtonText = operator_new(0xc);
                            pCVar5 = this->m_pCurrentCommandMenu;
                            *(undefined ***)pButtonText = &PTR_cursorMoved_000c8158;
                            *(CCommandMenu **)&((TeamFortressViewport *)pButtonText)->field_0x4 =
                                 pCVar5;
                            *(TeamFortressViewport **)
                             &((TeamFortressViewport *)pButtonText)->field_0x8 = local_130;
                            pButtonName = (char *)local_130;
                            (*pcVar1)(local_130,pButtonText);
                            goto LAB_000949c0;
                          }
                          local_130 = operator_new(0x138);
                          fVar2 = ((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0;
                          CommandButton::CommandButton
                                    ((CommandButton *)local_130,pButtonText,0,(int)(fVar2 + fVar2),
                                     (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),
                                     (int)fVar2,false);
                          *(undefined ***)local_130 = &PTR_setPos_000c8dd4;
                          local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x1;
                          local_130->m_pCommandMenus[0x1b] = (CCommandMenu *)0x1;
                          puVar4 = operator_new(0x108);
                          *puVar4 = &PTR_actionPerformed_000c3f68;
                          pcVar14 = "dismantle 2";
                        }
                      }
                    }
                  }
                }
              }
              goto LAB_0009555e;
            }
            local_130 = operator_new(0x138);
            iVar8 = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0);
            CommandButton::CommandButton
                      ((CommandButton *)local_130,pButtonText,0,iVar8,
                       (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),iVar8,false);
            *(undefined ***)local_130 = &PTR_setPos_000c88f4;
            local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x3;
            pcVar14 = "disguise_friendly";
          }
          pButtonText = (char *)local_130;
          CreateDisguiseSubmenu
                    (this,(CommandButton *)local_130,this->m_pCurrentCommandMenu,pcVar14,iYOffset,0)
          ;
          pButtonName = (char *)this;
        }
        goto LAB_000949c0;
      }
      fVar2 = (float)gHUD.m_scrinfo.iHeight;
      iVar8 = this->m_pCurrentCommandMenu->m_iButtons;
      local_130 = operator_new(0x134);
      CommandButton::CommandButton
                ((CommandButton *)local_130,pButtonText,0,
                 (int)((float)iVar8 * (fVar2 / 480.0) * 30.0),
                 (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0),
                 (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0),false);
      *(undefined ***)local_130 = &PTR_setPos_000c5240;
      local_130->m_pCommandMenus[0x1a] = (CCommandMenu *)0x0;
      puVar4 = operator_new(8);
      *puVar4 = &PTR_actionPerformed_000c3f74;
      puVar4[1] = 5;
    }
  }
  vgui::Button::addActionSignal((ActionSignal *)local_130);
  pcVar1 = *(code **)(*(int *)local_130 + 0x70);
  pButtonText = operator_new(0xc);
  pCVar5 = this->m_pCurrentCommandMenu;
  *(undefined ***)pButtonText = &PTR_cursorMoved_000c8158;
  *(CCommandMenu **)&((TeamFortressViewport *)pButtonText)->field_0x4 = pCVar5;
  *(TeamFortressViewport **)&((TeamFortressViewport *)pButtonText)->field_0x8 = local_130;
  pButtonName = (char *)local_130;
  (*pcVar1)(local_130,pButtonText);
LAB_000949c0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pButtonName,pButtonText);
  }
  return (CommandButton *)local_130;
}


// TeamFortressViewport::ToggleServerBrowser  @ 00099850  (line 1270)

/* DWARF original prototype: void ToggleServerBrowser(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::ToggleServerBrowser(TeamFortressViewport *this)

{
  ServerBrowser *pSVar1;
  char cVar2;
  
  if ((this->m_iInitialized != 0) &&
     (pSVar1 = this->m_pServerBrowser, pSVar1 != (ServerBrowser *)0x0)) {
    cVar2 = (**(code **)(*(int *)&pSVar1->super_CTransparentPanel + 0x28))(pSVar1);
    pSVar1 = this->m_pServerBrowser;
    if (cVar2 != '\0') {
      (**(code **)(*(int *)&pSVar1->super_CTransparentPanel + 0x24))(pSVar1,0);
      UpdateCursorState(this);
      return;
    }
    (**(code **)(*(int *)&pSVar1->super_CTransparentPanel + 0x24))(pSVar1,1);
    UpdateCursorState(this);
    return;
  }
  return;
}


// TeamFortressViewport::ShowCommandMenu  @ 0009a3d0  (line 1291)

/* DWARF original prototype: void ShowCommandMenu(TeamFortressViewport * this, int menuIndex) */

void __thiscall TeamFortressViewport::ShowCommandMenu(TeamFortressViewport *this,int menuIndex)

{
  CCommandMenu **ppCVar1;
  CMenuPanel *pCVar2;
  CCommandMenu *pCVar3;
  bool bVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  if ((this->m_iInitialized != 0) && (this->m_pCurrentMenu == (CMenuPanel *)0x0)) {
    if (this->m_pCurrentCommandMenu == this->m_pCommandMenus[menuIndex]) {
      if (this->m_pCommandMenus[this->m_StandardMenu] != (CCommandMenu *)0x0) {
        CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_StandardMenu]);
      }
      if (this->m_pCommandMenus[this->m_SpectatorOptionsMenu] != (CCommandMenu *)0x0) {
        CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorOptionsMenu]);
      }
      if (this->m_pCommandMenus[this->m_SpectatorCameraMenu] != (CCommandMenu *)0x0) {
        CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorCameraMenu]);
      }
      if (this->m_pCommandMenus[this->m_PlayerMenu] != (CCommandMenu *)0x0) {
        CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_PlayerMenu]);
      }
                    /* Unresolved local var: int i@[???] */
      this->m_flMenuOpenTime = 0.0;
      if (0 < this->m_iNumMenus) {
        iVar7 = 0;
        do {
          ppCVar1 = this->m_pCommandMenus + iVar7;
          iVar7 = iVar7 + 1;
          (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
        } while (iVar7 < this->m_iNumMenus);
      }
      this->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
      UpdateCursorState(this);
      return;
    }
    if (gHUD.m_iIntermission == 0) {
      UpdateCommandMenu(this,menuIndex);
      pCVar2 = this->m_pCurrentMenu;
      while (pCVar2 != (CMenuPanel *)0x0) {
        HideTopMenu(this);
        pCVar2 = this->m_pCurrentMenu;
      }
                    /* Unresolved local var: int i@[???] */
      pCVar3 = this->m_pCommandMenus[menuIndex];
      if (0 < this->m_iNumMenus) {
        iVar7 = 0;
        do {
          ppCVar1 = this->m_pCommandMenus + iVar7;
          iVar7 = iVar7 + 1;
          (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
        } while (iVar7 < this->m_iNumMenus);
      }
      this->m_pCurrentCommandMenu = pCVar3;
      for (; pCVar3 != (CCommandMenu *)0x0; pCVar3 = pCVar3->m_pParentMenu) {
        (**(code **)(*(int *)pCVar3 + 0x24))(pCVar3,1);
      }
                    /* Unresolved local var: int i@[???] */
      iVar7 = 2;
      this->m_flMenuOpenTime = gHUD.m_flTime;
      UpdateCursorState(this);
      while (iVar5 = (*gEngfuncs.Cmd_Argc)(), iVar7 < iVar5) {
                    /* Unresolved local var: char * param@[???] */
        pcVar6 = (*gEngfuncs.Cmd_Argv)(iVar7 + -1);
        if (((pcVar6 == (char *)0x0) ||
            (bVar4 = CCommandMenu::KeyInput(this->m_pCurrentCommandMenu,(int)*pcVar6), !bVar4)) ||
           (this->m_iInitialized == 0)) {
          iVar7 = iVar7 + 1;
        }
        else {
          if (this->m_pCommandMenus[this->m_StandardMenu] != (CCommandMenu *)0x0) {
            CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_StandardMenu]);
          }
          if (this->m_pCommandMenus[this->m_SpectatorOptionsMenu] != (CCommandMenu *)0x0) {
            CCommandMenu::ClearButtonsOfArmedState
                      (this->m_pCommandMenus[this->m_SpectatorOptionsMenu]);
          }
          if (this->m_pCommandMenus[this->m_SpectatorCameraMenu] != (CCommandMenu *)0x0) {
            CCommandMenu::ClearButtonsOfArmedState
                      (this->m_pCommandMenus[this->m_SpectatorCameraMenu]);
          }
          if (this->m_pCommandMenus[this->m_PlayerMenu] != (CCommandMenu *)0x0) {
            CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_PlayerMenu]);
          }
                    /* Unresolved local var: int i@[???] */
          this->m_flMenuOpenTime = 0.0;
          if (0 < this->m_iNumMenus) {
            iVar5 = 0;
            do {
              ppCVar1 = this->m_pCommandMenus + iVar5;
              iVar5 = iVar5 + 1;
              (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
            } while (iVar5 < this->m_iNumMenus);
          }
          iVar7 = iVar7 + 1;
          this->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
          UpdateCursorState(this);
        }
      }
    }
  }
  return;
}


// TeamFortressViewport::InputSignalHideCommandMenu  @ 00099c30  (line 1338)

/* DWARF original prototype: void InputSignalHideCommandMenu(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::InputSignalHideCommandMenu(TeamFortressViewport *this)

{
  CCommandMenu **ppCVar1;
  int iVar2;
  
  if ((this->m_iInitialized != 0) && (this->m_flMenuOpenTime + 0.3 <= gHUD.m_flTime)) {
    if (this->m_pCommandMenus[this->m_StandardMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_StandardMenu]);
    }
    if (this->m_pCommandMenus[this->m_SpectatorOptionsMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorOptionsMenu]);
    }
    if (this->m_pCommandMenus[this->m_SpectatorCameraMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorCameraMenu]);
    }
    if (this->m_pCommandMenus[this->m_PlayerMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_PlayerMenu]);
    }
                    /* Unresolved local var: int i@[???] */
    this->m_flMenuOpenTime = 0.0;
    if (0 < this->m_iNumMenus) {
      iVar2 = 0;
      do {
        ppCVar1 = this->m_pCommandMenus + iVar2;
        iVar2 = iVar2 + 1;
        (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
      } while (iVar2 < this->m_iNumMenus);
    }
    this->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
    UpdateCursorState(this);
    return;
  }
  return;
}


// TeamFortressViewport::HideCommandMenu  @ 00099b50  (line 1353)

/* DWARF original prototype: void HideCommandMenu(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::HideCommandMenu(TeamFortressViewport *this)

{
  CCommandMenu **ppCVar1;
  int iVar2;
  
  if (this->m_iInitialized != 0) {
    if (this->m_pCommandMenus[this->m_StandardMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_StandardMenu]);
    }
    if (this->m_pCommandMenus[this->m_SpectatorOptionsMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorOptionsMenu]);
    }
    if (this->m_pCommandMenus[this->m_SpectatorCameraMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorCameraMenu]);
    }
    if (this->m_pCommandMenus[this->m_PlayerMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_PlayerMenu]);
    }
                    /* Unresolved local var: int i@[???] */
    this->m_flMenuOpenTime = 0.0;
    if (0 < this->m_iNumMenus) {
      iVar2 = 0;
      do {
        ppCVar1 = this->m_pCommandMenus + iVar2;
        iVar2 = iVar2 + 1;
        (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
      } while (iVar2 < this->m_iNumMenus);
    }
    this->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
    UpdateCursorState(this);
    return;
  }
  return;
}


// TeamFortressViewport::ShowScoreBoard  @ 000998d0  (line 1387)

/* DWARF original prototype: void ShowScoreBoard(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::ShowScoreBoard(TeamFortressViewport *this)

{
  int iVar1;
  
  if (this->m_pScoreBoard != (ScorePanel *)0x0) {
    iVar1 = (*gEngfuncs.GetMaxClients)();
    if (1 < iVar1) {
      ScorePanel::Open(this->m_pScoreBoard);
      UpdateCursorState(this);
      return;
    }
  }
  return;
}


// TeamFortressViewport::IsScoreBoardVisible  @ 00097e80  (line 1404)

/* DWARF original prototype: bool IsScoreBoardVisible(TeamFortressViewport * this) */

bool __thiscall TeamFortressViewport::IsScoreBoardVisible(TeamFortressViewport *this)

{
  undefined1 uVar1;
  
  if (this->m_pScoreBoard != (ScorePanel *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00097e97. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(int *)this->m_pScoreBoard + 0x28))();
    return (bool)uVar1;
  }
  return false;
}


// TeamFortressViewport::HideScoreBoard  @ 00099a10  (line 1414)

/* DWARF original prototype: void HideScoreBoard(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::HideScoreBoard(TeamFortressViewport *this)

{
  ScorePanel *pSVar1;
  CVoiceStatus *this_00;
  
  if ((gHUD.m_iIntermission == 0) && (pSVar1 = this->m_pScoreBoard, pSVar1 != (ScorePanel *)0x0)) {
    (**(code **)(*(int *)pSVar1 + 0x24))(pSVar1,0);
    this_00 = GetClientVoiceMgr();
    CVoiceStatus::StopSquelchMode(this_00);
    UpdateCursorState(this);
    return;
  }
  return;
}


// TeamFortressViewport::InputPlayerSpecial  @ 0009a6a0  (line 1434)

/* DWARF original prototype: void InputPlayerSpecial(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::InputPlayerSpecial(TeamFortressViewport *this)

{
  if (this->m_iInitialized != 0) {
    if (1 < g_iPlayerClass - 8U) {
                    /* WARNING: Could not recover jumptable at 0x0009a6cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*gEngfuncs.pfnClientCmd)("_special");
      return;
    }
    ShowCommandMenu(this,gViewPort->m_StandardMenu);
    if (this->m_pCurrentCommandMenu != (CCommandMenu *)0x0) {
      CCommandMenu::KeyInput(this->m_pCurrentCommandMenu,0x37);
    }
  }
  return;
}


// TeamFortressViewport::SetCurrentCommandMenu  @ 00097eb0  (line 1456)

/* DWARF original prototype: void SetCurrentCommandMenu(TeamFortressViewport * this, CCommandMenu *
   pNewMenu) */

void __thiscall
TeamFortressViewport::SetCurrentCommandMenu(TeamFortressViewport *this,CCommandMenu *pNewMenu)

{
  CCommandMenu **ppCVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < this->m_iNumMenus) {
    iVar2 = 0;
    do {
      ppCVar1 = this->m_pCommandMenus + iVar2;
      iVar2 = iVar2 + 1;
      (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
    } while (iVar2 < this->m_iNumMenus);
  }
  this->m_pCurrentCommandMenu = pNewMenu;
  for (; pNewMenu != (CCommandMenu *)0x0; pNewMenu = pNewMenu->m_pParentMenu) {
    (**(code **)(*(int *)pNewMenu + 0x24))(pNewMenu,1);
  }
  return;
}


// TeamFortressViewport::UpdateCommandMenu  @ 00098260  (line 1467)

/* DWARF original prototype: void UpdateCommandMenu(TeamFortressViewport * this, int menuIndex) */

void __thiscall TeamFortressViewport::UpdateCommandMenu(TeamFortressViewport *this,int menuIndex)

{
  CommandButton **ppCVar1;
  CCommandMenu *pCVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iAdjustment;
  TeamFortressViewport *in_stack_ffffffd4;
  int in_stack_ffffffd8;
  undefined1 in_stack_ffffffdc;
  
  if (this->m_PlayerMenu == menuIndex) {
    pCVar2 = this->m_pCommandMenus[menuIndex];
    (**(code **)(*(int *)pCVar2 + 0x108))(pCVar2);
    pCVar2->m_iButtons = 0;
    in_stack_ffffffd8 = this->m_PlayerMenu;
    in_stack_ffffffd4 = this;
    UpdatePlayerMenu(this,in_stack_ffffffd8);
  }
  CCommandMenu::RecalculateVisibles
            ((CCommandMenu *)in_stack_ffffffd4,in_stack_ffffffd8,(bool)in_stack_ffffffdc);
  pCVar2 = this->m_pCommandMenus[menuIndex];
                    /* Unresolved local var: int iTop@[???]
                       Unresolved local var: int iAdjust@[???]
                       Unresolved local var: int iBottom@[???] */
  iVar5 = pCVar2->m_iYOffset;
  if (pCVar2->m_iDirection != 0) {
    iVar5 = gHUD.m_scrinfo.iHeight - (iVar5 + *(int *)&pCVar2->field_0x10);
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  iVar3 = *(int *)&pCVar2->field_0x10 + iVar5;
  iVar4 = iVar5;
  iAdjustment = 0;
  if (gHUD.m_scrinfo.iHeight < iVar3) {
    iAdjustment = 0;
    do {
      iAdjustment = (int)((float)iAdjustment + (pCVar2->m_flButtonSizeY - 1.0));
    } while (iAdjustment < iVar3 - gHUD.m_scrinfo.iHeight);
    iVar4 = iVar5 - iAdjustment;
    if (iVar4 < 0) {
      iVar4 = 0;
      iAdjustment = iVar5;
    }
  }
  (*(code *)**(undefined4 **)pCVar2)(pCVar2,*(undefined4 *)&pCVar2->field_0x4,iVar4);
                    /* Unresolved local var: int i@[???] */
  if (0 < pCVar2->m_iButtons) {
    iVar5 = 0;
    do {
      ppCVar1 = pCVar2->m_aButtons + iVar5;
      iVar5 = iVar5 + 1;
      CommandButton::UpdateSubMenus(*ppCVar1,iAdjustment);
    } while (iVar5 < pCVar2->m_iButtons);
  }
  return;
}


// TeamFortressViewport::UpdatePlayerMenu  @ 00097f30  (line 1481)

/* DWARF original prototype: void UpdatePlayerMenu(TeamFortressViewport * this, int menuIndex) */

void __thiscall TeamFortressViewport::UpdatePlayerMenu(TeamFortressViewport *this,int menuIndex)

{
  char *text;
  int iVar1;
  code *pcVar2;
  float fVar3;
  float fVar4;
  TeamFortressViewport *pTVar5;
  bool bVar6;
  cl_entity_s *ent;
  CommandButton *this_00;
  CCommandMenu *pCVar7;
  undefined4 *puVar8;
  int iVar9;
  hud_player_info_s *phVar10;
  
                    /* Unresolved local var: cl_entity_t * pEnt@[???]
                       Unresolved local var: float flLabelSize@[???] */
  pTVar5 = gViewPort;
                    /* Unresolved local var: int i@[???] */
  iVar9 = 1;
  fVar4 = (float)gHUD.m_scrinfo.iWidth;
  fVar3 = fVar4 / 640.0;
  phVar10 = (hud_player_info_s *)0xf551c;
  do {
    (*gEngfuncs.pfnGetPlayerInfo)(iVar9,phVar10);
    if (phVar10->thisplayer != '\0') {
      pTVar5->m_pScoreBoard->m_iPlayerNum = iVar9;
    }
    iVar9 = iVar9 + 1;
    phVar10 = phVar10 + 1;
  } while (iVar9 != 0x40);
  iVar9 = 1;
  do {
    while( true ) {
                    /* Unresolved local var: SpectButton * pButton@[???] */
      ent = (*gEngfuncs.GetEntityByIndex)(iVar9);
      bVar6 = CHudSpectator::IsActivePlayer(&gHUD.m_Spectator,ent);
      if (bVar6) break;
                    /* Unresolved local var: int i@[???]
                       catch() { ... } // from try @ 00097fed with catch @ 00097fc0
                       catch() { ... } // from try @ 00098015 with catch @ 00097fc0
                       catch() { ... } // from try @ 0009807b with catch @ 00097fc0
                       catch() { ... } // from try @ 00098097 with catch @ 00097fc0
                       catch() { ... } // from try @ 000980fb with catch @ 00097fc0 */
      iVar9 = iVar9 + 1;
      if (iVar9 == 0x40) {
        return;
      }
    }
    this_00 = operator_new(0x130);
    text = g_PlayerInfoList[ent->index].name;
    CommandButton::CommandButton
              (this_00,text,(int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 157.0),
               (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 160.0 * (float)(iVar9 + -1) + 64.0),
               (int)(((fVar4 - (fVar3 * 200.0 + 15.0)) - fVar3 * 39.0) - fVar3 * 164.0),
               (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 30.0 * 0.5),false);
    *(undefined ***)this_00 = &PTR_setPos_000c7ee8;
    CommandButton::Init(this_00);
    CommandButton::setText(this_00,text);
    CommandButton::setBoundKey(this_00,-1);
    (**(code **)(*(int *)this_00 + 0x21c))(this_00,4);
    pCVar7 = this->m_pCommandMenus[menuIndex];
    iVar1 = pCVar7->m_iButtons;
    if (iVar1 < 100) {
      pCVar7->m_aButtons[iVar1] = this_00;
      pCVar7->m_iButtons = iVar1 + 1;
      (**(code **)(*(int *)this_00 + 0x40))(this_00,pCVar7);
      (**(code **)(*(int *)this_00 + 0x208))(this_00,3);
      iVar1 = pCVar7->m_iButtons;
      if (iVar1 < 10) {
        CommandButton::setBoundKey(this_00,(char)iVar1 + '0');
        pCVar7 = this->m_pCommandMenus[menuIndex];
      }
      else {
        if (iVar1 == 10) {
          CommandButton::setBoundKey(this_00,'0');
        }
        pCVar7 = this->m_pCommandMenus[menuIndex];
      }
    }
    iVar9 = iVar9 + 1;
    CommandButton::setParentMenu(this_00,pCVar7);
    (**(code **)(*(int *)this_00 + 0x208))(this_00,3);
    pcVar2 = *(code **)(*(int *)this_00 + 0x240);
    puVar8 = operator_new(0x104);
    iVar1 = ent->index;
    *puVar8 = &PTR_actionPerformed_000c8198;
    strncpy((char *)(puVar8 + 1),g_PlayerInfoList[iVar1].name,0x100);
    *(undefined1 *)((int)puVar8 + 0x103) = 0;
    (*pcVar2)(this_00,puVar8);
    pcVar2 = *(code **)(*(int *)this_00 + 0x70);
    puVar8 = operator_new(0xc);
    pCVar7 = this->m_pCommandMenus[menuIndex];
    *puVar8 = &PTR_cursorMoved_000c8158;
    puVar8[1] = pCVar7;
    puVar8[2] = this_00;
    (*pcVar2)(this_00,puVar8);
  } while (iVar9 != 0x40);
  return;
}


// TeamFortressViewport::UpdateSpectatorPanel  @ 00098390  (line 1525)

/* DWARF original prototype: void UpdateSpectatorPanel(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::UpdateSpectatorPanel(TeamFortressViewport *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  SpectatorPanel *pSVar4;
  Label *pLVar5;
  DropDownButton *pDVar6;
  bool bVar7;
  int iVar8;
  char cVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  float *pfVar15;
  uint *puVar16;
  uint *puVar17;
  int in_GS_OFFSET;
  bool bVar18;
  char *pcVar19;
  undefined1 local_260 [63];
  undefined1 local_221;
  char local_220 [127];
  undefined1 local_1a1;
  undefined1 local_1a0 [128];
  uint auStack_120 [31];
  undefined1 uStack_a1;
  char local_a0 [128];
  int local_20;
  
  iVar8 = g_iUser1;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  this->m_iUser2 = g_iUser2;
  iVar10 = g_iUser3;
  this->m_iUser1 = iVar8;
  this->m_iUser3 = iVar10;
  pSVar4 = this->m_pSpectatorPanel;
  if (pSVar4 == (SpectatorPanel *)0x0) goto LAB_0009842b;
  if (((iVar8 == 0) || ((gHUD.m_pCvarDraw)->value == 0.0)) || (gHUD.m_iIntermission != 0)) {
    cVar9 = (**(code **)(*(int *)pSVar4 + 0x28))(pSVar4);
    if (cVar9 != '\0') {
      (**(code **)(*(int *)this->m_pSpectatorPanel + 0x24))(this->m_pSpectatorPanel,0);
      SpectatorPanel::ShowMenu(this->m_pSpectatorPanel,false);
    }
  }
  else {
                    /* Unresolved local var: char[128] bottomText@[???]
                       Unresolved local var: char[128] helpString2@[???]
                       Unresolved local var: char[128] tempString@[???]
                       Unresolved local var: char * name@[???]
                       Unresolved local var: char * pBottomText@[???]
                       Unresolved local var: int player@[???]
                       Unresolved local var: char[64] szText@[???] */
    CHudSpectator::CheckSettings(&gHUD.m_Spectator);
    cVar9 = (**(code **)(*(int *)this->m_pSpectatorPanel + 0x28))(this->m_pSpectatorPanel);
    if (cVar9 == '\0') {
      (**(code **)(*(int *)this->m_pSpectatorPanel + 0x24))(this->m_pSpectatorPanel,1);
      SpectatorPanel::ShowMenu(this->m_pSpectatorPanel,false);
      pcVar12 = CHudTextMessage::BufferedLocaliseTextString("#Spec_Duck");
      __snprintf_chk(auStack_120,0x7f,1,0x80,&DAT_000bfb94,4,pcVar12);
      uStack_a1 = 0;
      puVar17 = auStack_120;
      do {
        puVar16 = puVar17;
        uVar13 = *puVar16 + 0xfefefeff & ~*puVar16;
        uVar14 = uVar13 & 0x80808080;
        puVar17 = puVar16 + 1;
      } while (uVar14 == 0);
      if ((uVar13 & 0x8080) == 0) {
        puVar17 = (uint *)((int)puVar16 + 6);
        uVar14 = uVar14 >> 0x10;
      }
      CHudTextMessage::MsgFunc_TextMsg
                (&gHUD.m_TextMessage,(char *)0x0,
                 (int)puVar17 + (-(int)auStack_120 - (uint)CARRY1((byte)uVar14,(byte)uVar14)) + -2,
                 auStack_120);
    }
    pcVar12 = local_220;
    __sprintf_chk(pcVar12,1,0x80,"#Spec_Mode%d",g_iUser1);
    __sprintf_chk(local_1a0,1,0x80,"#Spec_Mode%d",g_iUser1);
    iVar10 = (*gEngfuncs.IsSpectateOnly)();
    if (iVar10 != 0) {
                    /* try { // try from 00098823 to 000a884d has its CatchHandler @ 000985a0 */
      __strcat_chk(local_1a0," - HLTV",0x80);
    }
    if ((g_iUser2 < 1) || (iVar10 = (*gEngfuncs.GetMaxClients)(), iVar10 < g_iUser2)) {
      if (g_iUser1 != 5) goto LAB_000987a0;
      bVar18 = false;
      iVar10 = 0;
LAB_0009872e:
      if ((gHUD.m_Spectator.m_pip)->value != 0.0) goto LAB_00098542;
LAB_00098742:
      bVar7 = bVar18;
      pcVar12 = CHudTextMessage::BufferedLocaliseTextString(pcVar12);
    }
    else {
      if (g_iUser1 == 3) {
LAB_000987a0:
        iVar10 = 0;
        bVar18 = false;
        goto LAB_00098742;
      }
      iVar10 = g_iUser2;
      if (g_iUser1 == 5) {
        bVar18 = g_iUser2 != 0;
        goto LAB_0009872e;
      }
      bVar18 = g_iUser2 != 0;
LAB_00098542:
      bVar7 = (bool)(g_PlayerInfoList[iVar10].name != (char *)0x0 & bVar18);
      if (!bVar7) goto LAB_00098742;
      strncpy(pcVar12,g_PlayerInfoList[iVar10].name,0x80);
      local_1a1 = 0;
    }
    if ((g_iUser1 == 4) && (bVar7)) {
                    /* Unresolved local var: float * color@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???] */
      pfVar15 = GetClientColor(iVar10);
      fVar1 = *pfVar15;
      fVar2 = pfVar15[1];
      fVar3 = pfVar15[2];
      pLVar5 = this->m_pSpectatorPanel->m_BottomMainLabel;
                    /* try { // try from 0009896c to 000a8970 has its CatchHandler @ 00098cc2 */
      (**(code **)(*(int *)pLVar5 + 0x124))
                (pLVar5,(int)(fVar1 * 255.0),(int)(fVar2 * 255.0),(int)(fVar3 * 255.0),0);
                    /* try { // try from 00098984 to 000a8a74 has its CatchHandler @ 000985a0 */
      pDVar6 = this->m_pSpectatorPanel->m_BottomMainButton;
      (**(code **)(*(int *)&(pDVar6->super_ColorButton).super_CommandButton + 0x124))
                (pDVar6,(int)(fVar1 * 255.0),(int)(fVar2 * 255.0),(int)(fVar3 * 255.0),0);
    }
    else {
      pLVar5 = this->m_pSpectatorPanel->m_BottomMainLabel;
      (**(code **)(*(int *)pLVar5 + 0x124))(pLVar5,0x8f,0x8f,0x36,0);
      pDVar6 = this->m_pSpectatorPanel->m_BottomMainButton;
      (**(code **)(*(int *)&(pDVar6->super_ColorButton).super_CommandButton + 0x124))
                (pDVar6,0x8f,0x8f,0x36,0);
    }
    if ((gHUD.m_Spectator.m_autoDirector)->value != 0.0) {
                    /* Unresolved local var: char[128] tempString@[???] */
                    /* try { // try from 000987bc to 000a87c0 has its CatchHandler @ 00098cd8 */
                    /* try { // try from 000987d3 to 000a87fd has its CatchHandler @ 000985a0 */
      __sprintf_chk(local_a0,1,0x80,"#Spec_Auto %s",local_1a0);
      __strcpy_chk(local_1a0,local_a0,0x80);
    }
    pLVar5 = this->m_pSpectatorPanel->m_BottomMainLabel;
    (**(code **)(*(int *)pLVar5 + 0x204))(pLVar5,&DAT_000c4b6e,pcVar12);
    pDVar6 = this->m_pSpectatorPanel->m_BottomMainButton;
    (**(code **)(*(int *)&(pDVar6->super_ColorButton).super_CommandButton + 0x264))(pDVar6,pcVar12);
    iVar10 = (*gEngfuncs.IsSpectateOnly)();
    pcVar12 = (char *)gHUD.m_Spectator.m_iSpectatorNumber;
    if (iVar10 == 0) {
      pcVar11 = (*gEngfuncs.pfnGetLevelName)();
                    /* try { // try from 0009876c to 000a8770 has its CatchHandler @ 00098ce2 */
      pcVar12 = local_a0;
      COM_FileBase(pcVar11,pcVar12);
                    /* try { // try from 00098783 to 000a87ad has its CatchHandler @ 000985a0 */
      pcVar11 = CHudTextMessage::BufferedLocaliseTextString("#Spec_Map");
      pcVar19 = "%s: %s";
    }
    else {
      pcVar11 = CHudTextMessage::BufferedLocaliseTextString("#Spectators");
      pcVar19 = "%s: %d";
    }
                    /* Unresolved local var: char[64] szMapName@[???] */
    __snprintf_chk(local_260,0x3f,1,0x40,pcVar19,pcVar11,pcVar12);
    local_221 = 0;
    pLVar5 = this->m_pSpectatorPanel->m_ExtraInfo;
    (**(code **)(*(int *)pLVar5 + 0x204))(pLVar5,local_260);
    SpectatorPanel::Update(gViewPort->m_pSpectatorPanel);
  }
  this->m_flSpectatorPanelLastUpdated = gHUD.m_flTime + 1.0;
LAB_0009842b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// TeamFortressViewport::CreateScoreBoard  @ 00098ba0  (line 1666)

/* DWARF original prototype: void CreateScoreBoard(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::CreateScoreBoard(TeamFortressViewport *this)

{
  ScorePanel *this_00;
  int y;
  int x;
  int local_24;
  int local_20;
  
                    /* Unresolved local var: int xdent@[???]
                       Unresolved local var: int ydent@[???] */
  if (gHUD.m_scrinfo.iWidth == 0x200) {
    local_20 = 0x3c;
    x = 0x1e;
    y = 0x1e;
    local_24 = 0x3c;
  }
  else if (gHUD.m_scrinfo.iWidth == 400) {
    local_24 = 0x28;
    y = 0x14;
    x = 0;
    local_20 = 0;
  }
  else {
    x = (int)(((float)gHUD.m_scrinfo.iWidth / 640.0) * 104.0);
    y = (int)(((float)gHUD.m_scrinfo.iHeight / 480.0) * 40.0);
    local_24 = y * 2;
    local_20 = x * 2;
  }
  this_00 = operator_new(0x269cc);
  ScorePanel::ScorePanel
            (this_00,x,y,gHUD.m_scrinfo.iWidth - local_20,gHUD.m_scrinfo.iHeight - local_24);
  this->m_pScoreBoard = this_00;
  vgui::Panel::setParent(&this_00->super_Panel);
  (**(code **)(*(int *)this->m_pScoreBoard + 0x24))(this->m_pScoreBoard,0);
  return;
}


// TeamFortressViewport::CreateServerBrowser  @ 00098d00  (line 1685)

/* DWARF original prototype: void CreateServerBrowser(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::CreateServerBrowser(TeamFortressViewport *this)

{
  ServerBrowser *this_00;
  
  this_00 = operator_new(0xe4);
  ServerBrowser::ServerBrowser(this_00,0,0,gHUD.m_scrinfo.iWidth,gHUD.m_scrinfo.iHeight);
  this->m_pServerBrowser = this_00;
  vgui::Panel::setParent((Panel *)this_00);
  (**(code **)(*(int *)&this->m_pServerBrowser->super_CTransparentPanel + 0x24))
            (this->m_pServerBrowser,0);
  return;
}


// TeamFortressViewport::SetCurrentMenu  @ 00098d80  (line 1695)

/* DWARF original prototype: void SetCurrentMenu(TeamFortressViewport * this, CMenuPanel * pMenu) */

void __thiscall TeamFortressViewport::SetCurrentMenu(TeamFortressViewport *this,CMenuPanel *pMenu)

{
  int iVar1;
  
  this->m_pCurrentMenu = pMenu;
  if (pMenu == (CMenuPanel *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00098ddd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEngfuncs.pfnClientCmd)("closemenus;");
    return;
  }
  iVar1 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
  if (iVar1 != 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00098dc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)&this->m_pCurrentMenu->super_CTransparentPanel + 0x200))();
  return;
}


// TeamFortressViewport::CreateTextWindow  @ 00098df0  (line 1714)

/* DWARF original prototype: CMenuPanel * CreateTextWindow(TeamFortressViewport * this, int
   iTextToShow) */

CMenuPanel * __thiscall
TeamFortressViewport::CreateTextWindow(TeamFortressViewport *this,int iTextToShow)

{
  uint uVar1;
  char *in_EAX;
  CMenuPanel *pCVar2;
  char *pcVar3;
  char *pcVar4;
  size_t sVar5;
  byte *szMOTD;
  undefined4 *puVar6;
  char *pcVar7;
  uint uVar8;
  int in_GS_OFFSET;
  char local_160 [63];
  undefined1 local_121;
  char local_120 [4];
  undefined2 local_11c;
  int local_20;
  
                    /* Unresolved local var: char[256] sz@[???]
                       Unresolved local var: char * cText@[???]
                       Unresolved local var: char * pfile@[???]
                       Unresolved local var: int MAX_TITLE_LENGTH@[???]
                       Unresolved local var: char[64] cTitle@[???]
                       Unresolved local var: CMenuPanel * pMOTDPanel@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (iTextToShow == 3) {
    if ((this->m_szServerName == (char *)0x0) || (this->m_szServerName[0] == '\0')) {
      builtin_strncpy(local_160,"Half-Life",10);
    }
    else {
      strncpy(local_160,this->m_szServerName,0x40);
    }
    local_121 = 0;
    in_EAX = this->m_szMOTD;
  }
  else {
    if (iTextToShow == 1) {
      pcVar7 = this->m_sMapName;
      if ((pcVar7 == (char *)0x0) || (this->m_sMapName[0] == '\0')) {
                    /* Unresolved local var: char * level@[???]
                       Unresolved local var: char * ch@[???] */
        pcVar3 = (*gEngfuncs.pfnGetLevelName)();
        if (pcVar3 == (char *)0x0) goto switchD_00099082_caseD_0;
        __strcpy_chk(local_120,pcVar3,0x100);
        pcVar4 = strchr(local_120,0x2e);
        *pcVar4 = '\0';
        __strcat_chk(local_120,".txt",0x100);
        __strcpy_chk(pcVar7,pcVar3,0x40);
        pcVar3 = strchr(pcVar7,0x2e);
        if (pcVar3 != (char *)0x0) {
          *pcVar3 = '\0';
        }
        pcVar3 = strchr(pcVar7,0x2f);
        if (pcVar3 != (char *)0x0) {
          sVar5 = strlen(pcVar3);
          memmove(pcVar7,pcVar3 + 1,sVar5 + 1);
        }
      }
      else {
        builtin_strncpy(local_120,"maps",4);
        local_11c._0_1_ = 0x2f;
        puVar6 = (undefined4 *)__stpcpy_chk((int)&local_11c + 1,pcVar7,0x100);
        *puVar6 = 0x7478742e;
        *(undefined1 *)(puVar6 + 1) = 0;
      }
      szMOTD = (*gEngfuncs.COM_LoadFile)(local_120,5,(int *)0x0);
      if (szMOTD != (byte *)0x0) {
        strncpy(local_160,pcVar7,0x40);
        local_121 = 0;
        pCVar2 = CMessageWindowPanel_Create
                           ((char *)szMOTD,local_160,(uint)(g_iPlayerClass == 0),0,0,0,
                            gHUD.m_scrinfo.iWidth,gHUD.m_scrinfo.iHeight);
        (**(code **)(*(int *)&pCVar2->super_CTransparentPanel + 0x40))(pCVar2,this);
        (*gEngfuncs.COM_FreeFile)(szMOTD);
        goto LAB_00098e93;
      }
switchD_00099082_caseD_0:
      pCVar2 = (CMenuPanel *)0x0;
      goto LAB_00098e93;
    }
    if (iTextToShow == 2) {
                    /* Unresolved local var: char * pfile@[???] */
      switch(g_iPlayerClass) {
      default:
        goto switchD_00099082_caseD_0;
      case 1:
        pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Help_scout");
        CHudTextMessage::LocaliseTextString("#Title_scout",local_160,0x40);
        break;
      case 2:
        pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Help_sniper");
        CHudTextMessage::LocaliseTextString("#Title_sniper",local_160,0x40);
        break;
      case 3:
        pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Help_soldier");
        CHudTextMessage::LocaliseTextString("#Title_soldier",local_160,0x40);
        break;
      case 4:
        pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Help_demoman");
        CHudTextMessage::LocaliseTextString("#Title_demoman",local_160,0x40);
        break;
      case 5:
        pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Help_medic");
        CHudTextMessage::LocaliseTextString("#Title_medic",local_160,0x40);
        break;
      case 6:
        pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Help_hwguy");
        CHudTextMessage::LocaliseTextString("#Title_hwguy",local_160,0x40);
        break;
      case 7:
        pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Help_pyro");
        CHudTextMessage::LocaliseTextString("#Title_pyro",local_160,0x40);
        break;
      case 8:
        pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Help_spy");
        CHudTextMessage::LocaliseTextString("#Title_spy",local_160,0x40);
        break;
      case 9:
        pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Help_engineer");
        CHudTextMessage::LocaliseTextString("#Title_engineer",local_160,0x40);
        break;
      case 0xb:
        pcVar7 = CHudTextMessage::BufferedLocaliseTextString("#Help_civilian");
        CHudTextMessage::LocaliseTextString("#Title_civilian",local_160,0x40);
      }
      if (g_iPlayerClass == 0xb) {
        uVar1 = 0;
        do {
          uVar8 = uVar1;
          *(undefined4 *)(local_120 + uVar8) = *(undefined4 *)("classes/long_civilian.txt" + uVar8);
          uVar1 = uVar8 + 4;
        } while (uVar8 + 4 < 0x18);
        *(undefined2 *)((int)&local_11c + uVar8) =
             *(undefined2 *)("classes/long_civilian.txt" + uVar8 + 4);
      }
      else {
        __sprintf_chk(local_120,1,0x100,"classes/long_%s.txt",sTFClassSelection[g_iPlayerClass]);
      }
      in_EAX = (char *)(*gEngfuncs.COM_LoadFile)(local_120,5,(int *)0x0);
      if (in_EAX == (char *)0x0) {
        in_EAX = pcVar7;
      }
    }
    else if (iTextToShow == 4) {
                    /* Unresolved local var: char * pfile@[???] */
      CHudTextMessage::LocaliseTextString("#Spec_Help_Title",local_160,0x40);
      local_121 = 0;
      in_EAX = CHudTextMessage::BufferedLocaliseTextString("#Spec_Help_Text");
    }
  }
  pCVar2 = CMessageWindowPanel_Create
                     (in_EAX,local_160,(uint)(g_iPlayerClass == 0),0,0,0,gHUD.m_scrinfo.iWidth,
                      gHUD.m_scrinfo.iHeight);
  (**(code **)(*(int *)&pCVar2->super_CTransparentPanel + 0x40))(pCVar2,this);
LAB_00098e93:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pCVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// TeamFortressViewport::ShowVGUIMenu  @ 0009a370  (line 1843)

/* DWARF original prototype: void ShowVGUIMenu(TeamFortressViewport * this, int iMenu) */

void __thiscall TeamFortressViewport::ShowVGUIMenu(TeamFortressViewport *this,int iMenu)

{
  CMenuPanel *pCVar1;
  int iVar2;
  
                    /* Unresolved local var: CMenuPanel * pNewMenu@[???] */
  iVar2 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
  if ((iVar2 == 0) && ((gHUD.m_iIntermission == 0 || (iMenu == 5)))) {
    pCVar1 = this->m_pCurrentMenu;
    while( true ) {
      if (pCVar1 == (CMenuPanel *)0x0) {
        ShowVGUIMenu(this,iMenu);
        return;
      }
                    /* Unresolved local var: CMenuPanel * pMenu@[???] */
      if (iMenu == pCVar1->m_iMenuID) break;
      pCVar1 = pCVar1->m_pNextMenu;
    }
  }
  return;
}


// TeamFortressViewport::ShowVGUIMenu  @ 0009a010  (line 1868)

/* DWARF original prototype: void ShowVGUIMenu(TeamFortressViewport * this, int iMenu) */

void __thiscall TeamFortressViewport::ShowVGUIMenu(TeamFortressViewport *this,int iMenu)

{
  CCommandMenu **ppCVar1;
  code *pcVar2;
  CMenuPanel *pCVar3;
  CTeamMenuPanel *pCVar4;
  CClassMenuPanel *pCVar5;
  CClassMenuPanel *pCVar6;
  TeamFortressViewport *in_EAX;
  CClassMenuPanel *pCVar7;
  int in_EDX;
  CMenuPanel *pCVar8;
  int iVar9;
  
                    /* Unresolved local var: CMenuPanel * pNewMenu@[???] */
  switch(in_EDX) {
  case 0:
  case 1:
  case 7:
  case 8:
    goto switchD_0009a024_caseD_0;
  case 2:
    iVar9 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
    if (iVar9 == 0) {
      pCVar4 = in_EAX->m_pTeamMenu;
      pcVar2 = *(code **)(*(int *)&(pCVar4->super_CMenuPanel).super_CTransparentPanel + 0x1fc);
      if (pcVar2 == CTeamMenuPanel::Reset) {
        (pCVar4->super_CMenuPanel).m_pNextMenu = (CMenuPanel *)0x0;
        (pCVar4->super_CMenuPanel).m_iIsActive = 0;
        (pCVar4->super_CMenuPanel).m_flOpenTime = 0.0;
        pCVar4->m_iCurrentInfo = 0;
      }
      else {
        (*pcVar2)(pCVar4);
      }
      pCVar7 = (CClassMenuPanel *)in_EAX->m_pTeamMenu;
      break;
    }
    goto switchD_0009a024_caseD_0;
  case 3:
    iVar9 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
    if (iVar9 == 0) {
      pCVar7 = in_EAX->m_pClassMenu;
      pcVar2 = *(code **)(*(int *)&(pCVar7->super_CMenuPanel).super_CTransparentPanel + 0x1fc);
      if (pcVar2 == CClassMenuPanel::Reset) {
        (pCVar7->super_CMenuPanel).m_pNextMenu = (CMenuPanel *)0x0;
        (pCVar7->super_CMenuPanel).m_iIsActive = 0;
        (pCVar7->super_CMenuPanel).m_flOpenTime = 0.0;
        pCVar7->m_iCurrentInfo = 0;
      }
      else {
        (*pcVar2)(pCVar7);
      }
      pCVar7 = in_EAX->m_pClassMenu;
      break;
    }
    goto switchD_0009a024_caseD_0;
  case 4:
    pCVar7 = (CClassMenuPanel *)CreateTextWindow(in_EAX,1);
    break;
  case 5:
    pCVar7 = (CClassMenuPanel *)CreateTextWindow(in_EAX,3);
    break;
  case 6:
    pCVar7 = (CClassMenuPanel *)CreateTextWindow(in_EAX,2);
    break;
  case 9:
    pCVar7 = (CClassMenuPanel *)CreateTextWindow(in_EAX,4);
    break;
  default:
    goto switchD_0009a024_default;
  }
  if (pCVar7 != (CClassMenuPanel *)0x0) {
    if (in_EAX->m_iInitialized != 0) {
      if (in_EAX->m_pCommandMenus[in_EAX->m_StandardMenu] != (CCommandMenu *)0x0) {
        CCommandMenu::ClearButtonsOfArmedState(in_EAX->m_pCommandMenus[in_EAX->m_StandardMenu]);
      }
      if (in_EAX->m_pCommandMenus[in_EAX->m_SpectatorOptionsMenu] != (CCommandMenu *)0x0) {
        CCommandMenu::ClearButtonsOfArmedState
                  (in_EAX->m_pCommandMenus[in_EAX->m_SpectatorOptionsMenu]);
      }
      if (in_EAX->m_pCommandMenus[in_EAX->m_SpectatorCameraMenu] != (CCommandMenu *)0x0) {
        CCommandMenu::ClearButtonsOfArmedState
                  (in_EAX->m_pCommandMenus[in_EAX->m_SpectatorCameraMenu]);
      }
      if (in_EAX->m_pCommandMenus[in_EAX->m_PlayerMenu] != (CCommandMenu *)0x0) {
        CCommandMenu::ClearButtonsOfArmedState(in_EAX->m_pCommandMenus[in_EAX->m_PlayerMenu]);
      }
                    /* Unresolved local var: int i@[???] */
      in_EAX->m_flMenuOpenTime = 0.0;
      if (0 < in_EAX->m_iNumMenus) {
        iVar9 = 0;
        do {
          ppCVar1 = in_EAX->m_pCommandMenus + iVar9;
          iVar9 = iVar9 + 1;
          (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
        } while (iVar9 < in_EAX->m_iNumMenus);
      }
      in_EAX->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
      UpdateCursorState(in_EAX);
    }
    (pCVar7->super_CMenuPanel).m_iIsActive = 1;
    (pCVar7->super_CMenuPanel).m_iMenuID = in_EDX;
    (**(code **)(*(int *)&(pCVar7->super_CMenuPanel).super_CTransparentPanel + 0x40))(pCVar7);
    pCVar8 = in_EAX->m_pCurrentMenu;
    if (pCVar8 == (CMenuPanel *)0x0) {
      in_EAX->m_pCurrentMenu = &pCVar7->super_CMenuPanel;
      (**(code **)(*(int *)&(pCVar7->super_CMenuPanel).super_CTransparentPanel + 0x200))(pCVar7);
      UpdateCursorState(in_EAX);
    }
    else {
      if ((pCVar8->m_iMenuID != 3) || (in_EDX != 2)) {
        pCVar3 = pCVar8->m_pNextMenu;
        if (pCVar8->m_pNextMenu == (CMenuPanel *)0x0) {
          pCVar8->m_pNextMenu = &pCVar7->super_CMenuPanel;
          return;
        }
        do {
          pCVar8 = pCVar3;
          pCVar3 = pCVar8->m_pNextMenu;
        } while (pCVar3 != (CMenuPanel *)0x0);
        pCVar8->m_pNextMenu = &pCVar7->super_CMenuPanel;
        return;
      }
                    /* Unresolved local var: CMenuPanel * temp@[???] */
      pcVar2 = *(code **)(*(int *)&pCVar8->super_CTransparentPanel + 0x204);
      if (pcVar2 == CMenuPanel::Close) {
        (**(code **)(*(int *)&pCVar8->super_CTransparentPanel + 0x24))(pCVar8,0);
        pCVar8->m_iIsActive = 0;
        if (pCVar8->m_iRemoveMe != 0) {
          (**(code **)(*(int *)gViewPort + 0x4c))(gViewPort,pCVar8);
        }
      }
      else {
        (*pcVar2)(pCVar8);
      }
      in_EAX->m_pCurrentMenu = &pCVar7->super_CMenuPanel;
      pCVar6 = (CClassMenuPanel *)(pCVar7->super_CMenuPanel).m_pNextMenu;
      while (pCVar5 = pCVar6, pCVar5 != (CClassMenuPanel *)0x0) {
        pCVar7 = pCVar5;
        pCVar6 = (CClassMenuPanel *)(pCVar5->super_CMenuPanel).m_pNextMenu;
      }
      (pCVar7->super_CMenuPanel).m_pNextMenu = pCVar8;
      (**(code **)(*(int *)&in_EAX->m_pCurrentMenu->super_CTransparentPanel + 0x200))
                (in_EAX->m_pCurrentMenu);
      UpdateCursorState(in_EAX);
    }
  }
switchD_0009a024_caseD_0:
switchD_0009a024_default:
  return;
}


// TeamFortressViewport::HideVGUIMenu  @ 00099a60  (line 1935)

/* DWARF original prototype: void HideVGUIMenu(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::HideVGUIMenu(TeamFortressViewport *this)

{
  CMenuPanel *pCVar1;
  code *pcVar2;
  TeamFortressViewport *pTVar3;
  int iVar4;
  
  pCVar1 = this->m_pCurrentMenu;
  while (pCVar1 != (CMenuPanel *)0x0) {
    pcVar2 = *(code **)(*(int *)&pCVar1->super_CTransparentPanel + 0x204);
    if (pcVar2 == CMenuPanel::Close) {
      (**(code **)(*(int *)&pCVar1->super_CTransparentPanel + 0x24))(pCVar1,0);
      pCVar1->m_iIsActive = 0;
      if (pCVar1->m_iRemoveMe != 0) {
        (**(code **)(*(int *)gViewPort + 0x4c))(gViewPort,pCVar1);
      }
    }
    else {
      (*pcVar2)(pCVar1);
    }
    pTVar3 = gViewPort;
    pCVar1 = this->m_pCurrentMenu->m_pNextMenu;
    gViewPort->m_pCurrentMenu = pCVar1;
    if (pCVar1 == (CMenuPanel *)0x0) {
      (*gEngfuncs.pfnClientCmd)("closemenus;");
    }
    else {
      iVar4 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
      if (iVar4 == 0) {
        (**(code **)(*(int *)&pTVar3->m_pCurrentMenu->super_CTransparentPanel + 0x200))
                  (pTVar3->m_pCurrentMenu);
      }
    }
    UpdateCursorState(this);
    pCVar1 = this->m_pCurrentMenu;
  }
  return;
}


// TeamFortressViewport::HideTopMenu  @ 00099920  (line 1944)

/* DWARF original prototype: void HideTopMenu(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::HideTopMenu(TeamFortressViewport *this)

{
  CMenuPanel *pCVar1;
  code *pcVar2;
  TeamFortressViewport *pTVar3;
  int iVar4;
  
  pCVar1 = this->m_pCurrentMenu;
  if (pCVar1 != (CMenuPanel *)0x0) {
    pcVar2 = *(code **)(*(int *)&pCVar1->super_CTransparentPanel + 0x204);
    if (pcVar2 == CMenuPanel::Close) {
      (**(code **)(*(int *)&pCVar1->super_CTransparentPanel + 0x24))(pCVar1,0);
      pCVar1->m_iIsActive = 0;
      if (pCVar1->m_iRemoveMe != 0) {
        (**(code **)(*(int *)gViewPort + 0x4c))(gViewPort,pCVar1);
      }
    }
    else {
      (*pcVar2)(pCVar1);
    }
    pTVar3 = gViewPort;
    pCVar1 = this->m_pCurrentMenu->m_pNextMenu;
    gViewPort->m_pCurrentMenu = pCVar1;
    if (pCVar1 == (CMenuPanel *)0x0) {
      (*gEngfuncs.pfnClientCmd)("closemenus;");
      UpdateCursorState(this);
      return;
    }
    iVar4 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
    if (iVar4 == 0) {
      (**(code **)(*(int *)&pTVar3->m_pCurrentMenu->super_CTransparentPanel + 0x200))
                (pTVar3->m_pCurrentMenu);
      UpdateCursorState(this);
      return;
    }
  }
  UpdateCursorState(this);
  return;
}


// TeamFortressViewport::AllowedToPrintText  @ 000993b0  (line 1961)

/* DWARF original prototype: bool AllowedToPrintText(TeamFortressViewport * this) */

bool __thiscall TeamFortressViewport::AllowedToPrintText(TeamFortressViewport *this)

{
  int iVar1;
  
  if ((this->m_pCurrentMenu != (CMenuPanel *)0x0) && (g_iPlayerClass == 0)) {
                    /* Unresolved local var: int iId@[???] */
    iVar1 = this->m_pCurrentMenu->m_iMenuID;
    return 1 < iVar1 - 5U && 1 < iVar1 - 2U;
  }
  return true;
}


// TeamFortressViewport::ShowTeamMenu  @ 00099400  (line 1976)

/* DWARF original prototype: CMenuPanel * ShowTeamMenu(TeamFortressViewport * this) */

CMenuPanel * __thiscall TeamFortressViewport::ShowTeamMenu(TeamFortressViewport *this)

{
  CTeamMenuPanel *pCVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
  if (iVar3 == 0) {
    pCVar1 = this->m_pTeamMenu;
    pcVar2 = *(code **)(*(int *)&(pCVar1->super_CMenuPanel).super_CTransparentPanel + 0x1fc);
    if (pcVar2 == CTeamMenuPanel::Reset) {
      (pCVar1->super_CMenuPanel).m_pNextMenu = (CMenuPanel *)0x0;
      (pCVar1->super_CMenuPanel).m_iIsActive = 0;
      (pCVar1->super_CMenuPanel).m_flOpenTime = 0.0;
      pCVar1->m_iCurrentInfo = 0;
    }
    else {
      (*pcVar2)(pCVar1);
    }
    return &this->m_pTeamMenu->super_CMenuPanel;
  }
  return (CMenuPanel *)0x0;
}


// TeamFortressViewport::CreateTeamMenu  @ 00099480  (line 1986)

/* DWARF original prototype: void CreateTeamMenu(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::CreateTeamMenu(TeamFortressViewport *this)

{
  CTeamMenuPanel *this_00;
  
  this_00 = operator_new(0x124);
  CTeamMenuPanel::CTeamMenuPanel(this_00,100,0,0,0,gHUD.m_scrinfo.iWidth,gHUD.m_scrinfo.iHeight);
  this->m_pTeamMenu = this_00;
  vgui::Panel::setParent((Panel *)this_00);
  (**(code **)(*(int *)&(this->m_pTeamMenu->super_CMenuPanel).super_CTransparentPanel + 0x24))
            (this->m_pTeamMenu,0);
  return;
}


// TeamFortressViewport::ShowClassMenu  @ 00099510  (line 1998)

/* DWARF original prototype: CMenuPanel * ShowClassMenu(TeamFortressViewport * this) */

CMenuPanel * __thiscall TeamFortressViewport::ShowClassMenu(TeamFortressViewport *this)

{
  CClassMenuPanel *pCVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
  if (iVar3 == 0) {
    pCVar1 = this->m_pClassMenu;
    pcVar2 = *(code **)(*(int *)&(pCVar1->super_CMenuPanel).super_CTransparentPanel + 0x1fc);
    if (pcVar2 == CClassMenuPanel::Reset) {
      (pCVar1->super_CMenuPanel).m_pNextMenu = (CMenuPanel *)0x0;
      (pCVar1->super_CMenuPanel).m_iIsActive = 0;
      (pCVar1->super_CMenuPanel).m_flOpenTime = 0.0;
      pCVar1->m_iCurrentInfo = 0;
    }
    else {
      (*pcVar2)(pCVar1);
    }
    return &this->m_pClassMenu->super_CMenuPanel;
  }
  return (CMenuPanel *)0x0;
}


// TeamFortressViewport::CreateClassMenu  @ 00099590  (line 2008)

/* DWARF original prototype: void CreateClassMenu(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::CreateClassMenu(TeamFortressViewport *this)

{
  CClassMenuPanel *this_00;
  
  this_00 = operator_new(0xdf0);
  CClassMenuPanel::CClassMenuPanel(this_00,100,0,0,0,gHUD.m_scrinfo.iWidth,gHUD.m_scrinfo.iHeight);
  this->m_pClassMenu = this_00;
  vgui::Panel::setParent((Panel *)this_00);
  (**(code **)(*(int *)&(this->m_pClassMenu->super_CMenuPanel).super_CTransparentPanel + 0x24))
            (this->m_pClassMenu,0);
  return;
}


// TeamFortressViewport::CreateSpectatorMenu  @ 00099620  (line 2021)

/* DWARF original prototype: void CreateSpectatorMenu(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::CreateSpectatorMenu(TeamFortressViewport *this)

{
  SpectatorPanel *this_00;
  
  this_00 = operator_new(0x100);
  SpectatorPanel::SpectatorPanel(this_00,0,0,gHUD.m_scrinfo.iWidth,gHUD.m_scrinfo.iHeight);
  this->m_pSpectatorPanel = this_00;
  vgui::Panel::setParent(&this_00->super_Panel);
  (**(code **)(*(int *)this->m_pSpectatorPanel + 0x24))(this->m_pSpectatorPanel,0);
  SpectatorPanel::Initialize(this->m_pSpectatorPanel);
  return;
}


// TeamFortressViewport::UpdateOnPlayerInfo  @ 000996b0  (line 2035)

/* DWARF original prototype: void UpdateOnPlayerInfo(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::UpdateOnPlayerInfo(TeamFortressViewport *this)

{
  CTeamMenuPanel *pCVar1;
  CClassMenuPanel *pCVar2;
  
  pCVar1 = this->m_pTeamMenu;
  if (pCVar1 != (CTeamMenuPanel *)0x0) {
    (**(code **)(*(int *)&(pCVar1->super_CMenuPanel).super_CTransparentPanel + 0x210))(pCVar1);
  }
  pCVar2 = this->m_pClassMenu;
  if (pCVar2 != (CClassMenuPanel *)0x0) {
    (**(code **)(*(int *)&(pCVar2->super_CMenuPanel).super_CTransparentPanel + 0x210))(pCVar2);
  }
  if (this->m_pScoreBoard != (ScorePanel *)0x0) {
    ScorePanel::Update(this->m_pScoreBoard);
    return;
  }
  return;
}


// TeamFortressViewport::UpdateCursorState  @ 00099710  (line 2045)

/* DWARF original prototype: void UpdateCursorState(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::UpdateCursorState(TeamFortressViewport *this)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  CVoiceStatus *this_00;
  int iVar5;
  code *pcVar6;
  undefined4 uVar7;
  
  if ((((this->m_pSpectatorPanel->m_menuVisible == false) &&
       (this->m_pCurrentMenu == (CMenuPanel *)0x0)) &&
      (cVar1 = (**(code **)(*(int *)&(this->m_pTeamMenu->super_CMenuPanel).super_CTransparentPanel +
                           0x28))(this->m_pTeamMenu), cVar1 == '\0')) &&
     (cVar1 = (**(code **)(*(int *)&this->m_pServerBrowser->super_CTransparentPanel + 0x28))
                        (this->m_pServerBrowser), cVar1 == '\0')) {
    this_00 = GetClientVoiceMgr();
    bVar2 = CVoiceStatus::IsInSquelchMode(this_00);
    if ((!bVar2) &&
       ((this->m_pCurrentCommandMenu == (CCommandMenu *)0x0 ||
        ((gHUD.m_pCvarStealMouse)->value == 0.0)))) {
      iVar5 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
      if (iVar5 == 0) {
        IN_ResetMouse();
      }
      if (g_iVisibleMouse != 0) {
        IN_ResetRelativeMouseState();
      }
      g_iVisibleMouse = 0;
      piVar3 = (int *)vgui::App::getInstance();
      pcVar6 = *(code **)(*piVar3 + 0x8c);
      piVar4 = (int *)vgui::App::getInstance();
      piVar4 = (int *)(**(code **)(*piVar4 + 0x54))(piVar4);
      iVar5 = *piVar4;
      uVar7 = 1;
      goto LAB_00099764;
    }
  }
  g_iVisibleMouse = 1;
  piVar3 = (int *)vgui::App::getInstance();
  pcVar6 = *(code **)(*piVar3 + 0x8c);
  piVar4 = (int *)vgui::App::getInstance();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x54))(piVar4);
  iVar5 = *piVar4;
  uVar7 = 2;
LAB_00099764:
  uVar7 = (**(code **)(iVar5 + 0x14))(piVar4,uVar7);
  (*pcVar6)(piVar3,uVar7);
  return;
}


// TeamFortressViewport::UpdateHighlights  @ 0009a710  (line 2081)

/* DWARF original prototype: void UpdateHighlights(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::UpdateHighlights(TeamFortressViewport *this)

{
  CCommandMenu *pCVar1;
  
  for (pCVar1 = this->m_pCurrentCommandMenu; pCVar1 != (CCommandMenu *)0x0;
      pCVar1 = pCVar1->m_pParentMenu) {
    (**(code **)(*(int *)pCVar1 + 0x24))(pCVar1,1);
  }
  return;
}


// TeamFortressViewport::GetAllPlayersInfo  @ 0009a750  (line 2087)

/* DWARF original prototype: void GetAllPlayersInfo(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::GetAllPlayersInfo(TeamFortressViewport *this)

{
  int iVar1;
  hud_player_info_s *phVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = 1;
  phVar2 = (hud_player_info_s *)0xf551c;
  do {
    (*gEngfuncs.pfnGetPlayerInfo)(iVar1,phVar2);
    if (phVar2->thisplayer != '\0') {
      this->m_pScoreBoard->m_iPlayerNum = iVar1;
    }
    iVar1 = iVar1 + 1;
    phVar2 = phVar2 + 1;
  } while (iVar1 != 0x40);
  return;
}


// TeamFortressViewport::paintBackground  @ 000989d0  (line 2098)

/* DWARF original prototype: void paintBackground(TeamFortressViewport * this) */

void __thiscall TeamFortressViewport::paintBackground(TeamFortressViewport *this)

{
  ScorePanel *pSVar1;
  CClassMenuPanel *pCVar2;
  char cVar3;
  int *piVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [8];
  
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???]
                       Unresolved local var: int[4] extents@[???] */
  piVar4 = (int *)(**(code **)(*(int *)this + 0x20))(this);
  (**(code **)(*piVar4 + 0xc))(piVar4,&local_28,&local_24);
  (**(code **)(*(int *)this + 8))(this,local_28,local_24);
  if (this->m_pScoreBoard != (ScorePanel *)0x0) {
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
    piVar4 = (int *)(**(code **)(*(int *)this + 0x14c))(this);
    (**(code **)(*piVar4 + 0x34))(piVar4,&local_20,&local_1c);
    pSVar1 = this->m_pScoreBoard;
    (**(code **)(*(int *)pSVar1 + 0x200))(pSVar1,local_20,local_1c,pSVar1);
  }
  if (this->m_iCurrentTeamNumber != g_iTeamNumber) {
    UpdateCommandMenu(this,this->m_StandardMenu);
    pCVar2 = this->m_pClassMenu;
    if (pCVar2 != (CClassMenuPanel *)0x0) {
      (**(code **)(*(int *)&(pCVar2->super_CMenuPanel).super_CTransparentPanel + 0x210))(pCVar2);
    }
    this->m_iCurrentTeamNumber = g_iTeamNumber;
  }
  if (this->m_iCurrentPlayerClass != g_iPlayerClass) {
    UpdateCommandMenu(this,this->m_StandardMenu);
    this->m_iCurrentPlayerClass = g_iPlayerClass;
  }
                    /* try { // try from 00098b6d to 000a8b71 has its CatchHandler @ 00098c9f */
                    /* try { // try from 00098b90 to 000a8cd3 has its CatchHandler @ 000985a0 */
  if (((this->m_iUser1 != g_iUser1) || (this->m_iUser2 != g_iUser2)) ||
     (this->m_flSpectatorPanelLastUpdated < gHUD.m_flTime)) {
                    /* try { // try from 00098ae5 to 000a8ae9 has its CatchHandler @ 00098cb9 */
    UpdateSpectatorPanel(this);
  }
  cVar3 = (**(code **)(*(int *)this->m_pScoreBoard + 0x28))(this->m_pScoreBoard);
                    /* try { // try from 00098afc to 000a8b40 has its CatchHandler @ 00098cbb */
  if ((cVar3 != '\0') && (this->m_flScoreBoardLastUpdated < gHUD.m_flTime)) {
    ScorePanel::Update(this->m_pScoreBoard);
    this->m_flScoreBoardLastUpdated = gHUD.m_flTime + 0.5;
  }
  (**(code **)(*(int *)this + 0x38))(this,&local_1c,local_18,local_14,local_10);
  VGui_ViewportPaintBackground(&local_1c);
  return;
}


// CDragNDropHandler::cursorMoved  @ 00093050  (line 2151)

/* DWARF original prototype: void cursorMoved(CDragNDropHandler * this, int x, int y, Panel * panel)
    */

void __thiscall CDragNDropHandler::cursorMoved(CDragNDropHandler *this,int x,int y,Panel *panel)

{
  int *piVar1;
  int iVar2;
  
  if (this->m_bDragging != false) {
    piVar1 = (int *)vgui::App::getInstance();
    (**(code **)(*piVar1 + 0x34))(piVar1,&x,&y);
    (*(code *)**(undefined4 **)this->m_pPanel)
              (this->m_pPanel,(x - this->m_iaDragStart[0]) + this->m_iaDragOrgPos[0],
               (y - this->m_iaDragStart[1]) + this->m_iaDragOrgPos[1]);
    iVar2 = (**(code **)(*(int *)this->m_pPanel + 0x20))(this->m_pPanel);
    if (iVar2 != 0) {
      piVar1 = (int *)(**(code **)(*(int *)this->m_pPanel + 0x20))(this->m_pPanel);
      (**(code **)(*piVar1 + 0x30))(piVar1);
      return;
    }
  }
  return;
}


// CDragNDropHandler::mousePressed  @ 000935b0  (line 2165)

/* DWARF original prototype: void mousePressed(CDragNDropHandler * this, MouseCode code, Panel *
   panel) */

void __thiscall CDragNDropHandler::mousePressed(CDragNDropHandler *this,MouseCode code,Panel *panel)

{
  bool bVar1;
  DragNDropPanel *pDVar2;
  int iVar3;
  int *piVar4;
  int local_14;
  int local_10 [2];
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  piVar4 = (int *)vgui::App::getInstance();
  (**(code **)(*piVar4 + 0x34))(piVar4,&local_14,local_10);
  this->m_bDragging = true;
  this->m_iaDragStart[0] = local_14;
  this->m_iaDragStart[1] = local_10[0];
  (**(code **)(*(int *)this->m_pPanel + 4))
            (this->m_pPanel,this->m_iaDragOrgPos,this->m_iaDragOrgPos + 1);
  piVar4 = (int *)vgui::App::getInstance();
  (**(code **)(*piVar4 + 0x38))(piVar4,panel);
  pDVar2 = this->m_pPanel;
  bVar1 = this->m_bDragging;
  iVar3 = *(int *)pDVar2;
  if (*(code **)(iVar3 + 0x1fc) == DragNDropPanel::setDragged) {
    pDVar2->m_bBeingDragged = bVar1;
    if (bVar1 == false) {
      (**(code **)(iVar3 + 0xd4))(pDVar2,0);
    }
    else {
      (**(code **)(iVar3 + 0xd4))(pDVar2,pDVar2->m_pBorder);
    }
  }
  else {
    (**(code **)(iVar3 + 0x1fc))(pDVar2,bVar1);
  }
  (**(code **)(*(int *)this->m_pPanel + 0xa4))(this->m_pPanel);
  return;
}


// CDragNDropHandler::mouseReleased  @ 00093550  (line 2179)

/* DWARF original prototype: void mouseReleased(CDragNDropHandler * this, MouseCode code, Panel *
   panel) */

void __thiscall
CDragNDropHandler::mouseReleased(CDragNDropHandler *this,MouseCode code,Panel *panel)

{
  DragNDropPanel *pDVar1;
  code *pcVar2;
  int *piVar3;
  
  this->m_bDragging = false;
  pDVar1 = this->m_pPanel;
  pcVar2 = *(code **)(*(int *)pDVar1 + 0x1fc);
  if (pcVar2 == DragNDropPanel::setDragged) {
    pDVar1->m_bBeingDragged = false;
    (**(code **)(*(int *)pDVar1 + 0xd4))(pDVar1,0);
  }
  else {
    (*pcVar2)(pDVar1,0);
  }
  piVar3 = (int *)vgui::App::getInstance();
                    /* WARNING: Could not recover jumptable at 0x0009359b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar3 + 0x38))();
  return;
}


// TeamFortressViewport::SlotInput  @ 0009a7a0  (line 2190)

/* DWARF original prototype: bool SlotInput(TeamFortressViewport * this, int iSlot) */

bool __thiscall TeamFortressViewport::SlotInput(TeamFortressViewport *this,int iSlot)

{
  undefined1 uVar1;
  
  if (this->m_pCurrentMenu != (CMenuPanel *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009a7ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(int *)&this->m_pCurrentMenu->super_CTransparentPanel + 0x208))();
    return (bool)uVar1;
  }
  return false;
}


// TeamFortressViewport::KeyInput  @ 0009a7d0  (line 2198)

/* DWARF original prototype: int KeyInput(TeamFortressViewport * this, int down, int keynum, char *
   pszCurrentBinding) */

int __thiscall
TeamFortressViewport::KeyInput
          (TeamFortressViewport *this,int down,int keynum,char *pszCurrentBinding)

{
  CCommandMenu **ppCVar1;
  CMenuPanel *pCVar2;
  CCommandMenu *this_00;
  bool bVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  byte bVar8;
  TeamFortressViewport *in_stack_ffffffc4;
  int in_stack_ffffffc8;
  
  bVar8 = 0;
                    /* Unresolved local var: CMenuPanel * pNewMenu@[???] */
  if (((((this->m_iUser1 != 0) && (iVar4 = (*gEngfuncs.Con_IsVisible)(), iVar4 == 0)) && (down != 0)
       ) && ((keynum == 0xd || (keynum == 0xa9)))) &&
     ((iVar4 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)(), iVar4 == 0 && (gHUD.m_iIntermission == 0)))
     ) {
    for (pCVar2 = this->m_pCurrentMenu; pCVar2 != (CMenuPanel *)0x0; pCVar2 = pCVar2->m_pNextMenu) {
                    /* Unresolved local var: CMenuPanel * pMenu@[???] */
      if (pCVar2->m_iMenuID == 2) goto LAB_0009a7fb;
    }
    ShowVGUIMenu(in_stack_ffffffc4,in_stack_ffffffc8);
  }
  if (this->m_pCurrentMenu != (CMenuPanel *)0x0) {
LAB_0009a7fb:
    iVar4 = (*gEngfuncs.Con_IsVisible)();
    if (iVar4 == 0) {
                    /* Unresolved local var: int iMenuID@[???] */
      pCVar2 = this->m_pCurrentMenu;
      iVar4 = pCVar2->m_iMenuID;
      if (iVar4 - 2U < 2) {
        if (keynum == 0x1b) {
          iVar5 = g_iTeamNumber;
          if (iVar4 != 2) {
            iVar5 = g_iPlayerClass;
          }
          if (iVar5 != 0) goto LAB_0009aa30;
        }
        else {
                    /* Unresolved local var: int i@[???] */
          if ((keynum == 0x30) && (down != 0)) {
            iVar4 = 0x30;
            goto LAB_0009aa00;
          }
        }
        bVar3 = down != 0;
        if ((keynum == 0x31) && (bVar3)) {
          iVar4 = 0x31;
LAB_0009aa00:
          if (pCVar2 != (CMenuPanel *)0x0) {
            (**(code **)(*(int *)&pCVar2->super_CTransparentPanel + 0x208))(pCVar2,iVar4 + -0x30);
            return 0;
          }
          return 0;
        }
        if ((keynum == 0x32) && (bVar3)) {
          iVar4 = 0x32;
          goto LAB_0009aa00;
        }
        if ((keynum == 0x33) && (bVar3)) {
          iVar4 = 0x33;
          goto LAB_0009aa00;
        }
        if ((keynum == 0x34) && (bVar3)) {
          iVar4 = 0x34;
          goto LAB_0009aa00;
        }
        if ((keynum == 0x35) && (bVar3)) {
          iVar4 = 0x35;
          goto LAB_0009aa00;
        }
        if ((keynum == 0x36) && (bVar3)) {
          iVar4 = 0x36;
          goto LAB_0009aa00;
        }
        if ((keynum == 0x37) && (bVar3)) {
          iVar4 = 0x37;
          goto LAB_0009aa00;
        }
        if ((keynum == 0x38) && (bVar3)) {
          iVar4 = 0x38;
          goto LAB_0009aa00;
        }
        if ((keynum == 0x39) && (bVar3)) {
          iVar4 = 0x39;
          goto LAB_0009aa00;
        }
      }
      if (down == 0) {
        return 1;
      }
      bVar3 = true;
      if (keynum - 0xdU < 0x14) {
        bVar3 = (bool)((byte)(0x84001 >> ((byte)(keynum - 0xdU) & 0x1f)) & 1 ^ 1);
      }
      if ((bVar3 <= (keynum == 0xa9)) && (iVar4 - 4U < 3)) {
LAB_0009aa30:
        HideTopMenu(this);
        return 0;
      }
      bVar3 = false;
      bVar7 = pszCurrentBinding == (char *)0x0;
      if (!bVar7) {
        iVar5 = 6;
        pbVar6 = &DAT_000c2cc8;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar3 = (byte)*pszCurrentBinding < *pbVar6;
          bVar7 = *pszCurrentBinding == *pbVar6;
          pszCurrentBinding = pszCurrentBinding + (uint)bVar8 * -2 + 1;
          pbVar6 = pbVar6 + (uint)bVar8 * -2 + 1;
        } while (bVar7);
        if ((iVar4 == 2) && ((!bVar3 && !bVar7) == bVar3)) {
          (**(code **)(*(int *)&(this->m_pTeamMenu->super_CMenuPanel).super_CTransparentPanel +
                      0x208))(this->m_pTeamMenu,5);
          return 0;
        }
      }
      this_00 = this->m_pCurrentCommandMenu;
      goto joined_r0x0009a8d4;
    }
  }
  if (down == 0) {
    return 1;
  }
  this_00 = this->m_pCurrentCommandMenu;
joined_r0x0009a8d4:
  if (this_00 == (CCommandMenu *)0x0) {
    return 1;
  }
  if (keynum == 0x1b) {
    if (this->m_iInitialized == 0) {
      return 0;
    }
    if (this->m_pCommandMenus[this->m_StandardMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_StandardMenu]);
    }
    if (this->m_pCommandMenus[this->m_SpectatorOptionsMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorOptionsMenu]);
    }
    if (this->m_pCommandMenus[this->m_SpectatorCameraMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorCameraMenu]);
    }
    if (this->m_pCommandMenus[this->m_PlayerMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_PlayerMenu]);
    }
                    /* Unresolved local var: int i@[???] */
    this->m_flMenuOpenTime = 0.0;
    if (0 < this->m_iNumMenus) {
                    /* try { // try from 0009ab4c to 000aab50 has its CatchHandler @ 0009abac */
      iVar4 = 0;
      do {
        ppCVar1 = this->m_pCommandMenus + iVar4;
                    /* try { // try from 0009ab58 to 000aab5c has its CatchHandler @ 0009a980 */
        iVar4 = iVar4 + 1;
        (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
      } while (iVar4 < this->m_iNumMenus);
    }
  }
  else {
    if (9 < keynum - 0x30U) {
      return 1;
    }
    bVar3 = CCommandMenu::KeyInput(this_00,keynum);
    if (!bVar3) {
      return 0;
    }
                    /* catch() { ... } // from try @ 0009aa55 with catch @ 0009a980
                       catch() { ... } // from try @ 0009ab58 with catch @ 0009a980
                       catch() { ... } // from try @ 0009ab7f with catch @ 0009a980 */
    if (this->m_iInitialized == 0) {
      return 0;
    }
    if (this->m_pCommandMenus[this->m_StandardMenu] != (CCommandMenu *)0x0) {
                    /* catch() { ... } // from try @ 0009ab6f with catch @ 0009ab9a */
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_StandardMenu]);
    }
                    /* catch() { ... } // from try @ 0009ab4c with catch @ 0009abac */
    if (this->m_pCommandMenus[this->m_SpectatorOptionsMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorOptionsMenu]);
    }
    if (this->m_pCommandMenus[this->m_SpectatorCameraMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_SpectatorCameraMenu]);
    }
    if (this->m_pCommandMenus[this->m_PlayerMenu] != (CCommandMenu *)0x0) {
      CCommandMenu::ClearButtonsOfArmedState(this->m_pCommandMenus[this->m_PlayerMenu]);
    }
                    /* Unresolved local var: int i@[???] */
    this->m_flMenuOpenTime = 0.0;
    if (0 < this->m_iNumMenus) {
      iVar4 = 0;
      do {
        ppCVar1 = this->m_pCommandMenus + iVar4;
        iVar4 = iVar4 + 1;
        (**(code **)(*(int *)*ppCVar1 + 0x24))(*ppCVar1,0);
      } while (iVar4 < this->m_iNumMenus);
    }
  }
                    /* try { // try from 0009ab6f to 000aab73 has its CatchHandler @ 0009ab9a */
  this->m_pCurrentCommandMenu = (CCommandMenu *)0x0;
                    /* try { // try from 0009ab7f to 000aabbd has its CatchHandler @ 0009a980 */
  UpdateCursorState(this);
  return 0;
}


// TeamFortressViewport::MsgFunc_ValClass  @ 0009acb0  (line 2285)

/* DWARF original prototype: int MsgFunc_ValClass(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_ValClass
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  BEGIN_READ(pbuf,iSize);
  piVar2 = this->m_iValidClasses;
  do {
                    /* Unresolved local var: int i@[???] */
    iVar1 = READ_SHORT();
    piVar3 = piVar2 + 1;
    *piVar2 = iVar1;
    piVar2 = piVar3;
  } while (piVar3 != &this->m_iIsFeigning);
  UpdateCommandMenu(this,this->m_StandardMenu);
  return 1;
}


// TeamFortressViewport::MsgFunc_TeamNames  @ 0009ad10  (line 2298)

/* DWARF original prototype: int MsgFunc_TeamNames(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_TeamNames
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  CommandButton *pCVar1;
  CTeamMenuPanel *pCVar2;
  int iVar3;
  char *msg;
  int iVar4;
  char (*dst_buffer) [32];
  CommandButton **ppCVar5;
  
                    /* Unresolved local var: int i@[???] */
  iVar4 = 0;
  dst_buffer = this->m_sTeamNames;
  ppCVar5 = this->m_pDisguiseButtons;
  BEGIN_READ(pbuf,iSize);
  iVar3 = READ_BYTE();
  this->m_iNumberOfTeams = iVar3;
  while (ppCVar5 = ppCVar5 + 1, dst_buffer = dst_buffer + 1, iVar4 < iVar3) {
                    /* Unresolved local var: int teamNum@[???] */
    msg = READ_STRING();
    iVar4 = iVar4 + 1;
    CHudTextMessage::LocaliseTextString(msg,*dst_buffer,0x20);
    pCVar1 = ppCVar5[-7];
    if (pCVar1 != (CommandButton *)0x0) {
      (**(code **)(*(int *)pCVar1 + 0x264))(pCVar1,dst_buffer);
    }
    if ((iVar4 < 5) && (pCVar1 = *ppCVar5, pCVar1 != (CommandButton *)0x0)) {
      (**(code **)(*(int *)pCVar1 + 0x264))(pCVar1,dst_buffer);
    }
    iVar3 = this->m_iNumberOfTeams;
  }
  pCVar2 = this->m_pTeamMenu;
  if (pCVar2 != (CTeamMenuPanel *)0x0) {
    (**(code **)(*(int *)&(pCVar2->super_CMenuPanel).super_CTransparentPanel + 0x210))(pCVar2);
  }
                    /* try { // try from 0009adc0 to 000aadf0 has its CatchHandler @ 0009ad90 */
  return 1;
}


// TeamFortressViewport::MsgFunc_Feign  @ 0009add0  (line 2330)

/* DWARF original prototype: int MsgFunc_Feign(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_Feign(TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_iIsFeigning = iVar1;
  UpdateCommandMenu(this,this->m_StandardMenu);
  return 1;
}


// TeamFortressViewport::MsgFunc_Detpack  @ 0009ae20  (line 2342)

/* DWARF original prototype: int MsgFunc_Detpack(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_Detpack(TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_iIsSettingDetpack = iVar1;
  UpdateCommandMenu(this,this->m_StandardMenu);
  return 1;
}


// TeamFortressViewport::MsgFunc_VGUIMenu  @ 0009ae70  (line 2354)

/* DWARF original prototype: int MsgFunc_VGUIMenu(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_VGUIMenu
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  CMenuPanel *pCVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int iMenu@[???] */
  BEGIN_READ(pbuf,iSize);
                    /* try { // try from 0009ae88 to 000aae8c has its CatchHandler @ 0009b0c4 */
  iVar2 = READ_BYTE();
  if (iVar2 == 4) {
                    /* try { // try from 0009af03 to 000aaf5b has its CatchHandler @ 0009ad90 */
    iSize = (int)READ_STRING();
    pbuf = this->m_sMapName;
    strncpy(pbuf,(char *)iSize,0x40);
    this->m_sMapName[0x3f] = '\0';
  }
                    /* Unresolved local var: CMenuPanel * pNewMenu@[???] */
  iVar3 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
                    /* try { // try from 0009aea1 to 000aaeba has its CatchHandler @ 0009ad90 */
  if ((iVar3 == 0) && ((gHUD.m_iIntermission == 0 || (iVar2 == 5)))) {
    pCVar1 = this->m_pCurrentMenu;
    while( true ) {
      if (pCVar1 == (CMenuPanel *)0x0) {
                    /* try { // try from 0009aeea to 000aaeee has its CatchHandler @ 0009b0c2 */
        ShowVGUIMenu(pbuf,iSize);
        return 1;
      }
                    /* Unresolved local var: CMenuPanel * pMenu@[???] */
      if (iVar2 == pCVar1->m_iMenuID) break;
      pCVar1 = pCVar1->m_pNextMenu;
    }
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_MOTD  @ 0009af40  (line 2373)

/* DWARF original prototype: int MsgFunc_MOTD(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_MOTD(TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  CMenuPanel *pCVar1;
  int iVar2;
  size_t sVar3;
  char *iMenu;
  TeamFortressViewport *this_00;
  
                    /* Unresolved local var: int roomInArray@[???] */
  if (this->m_iGotAllMOTD != 0) {
    this->m_szMOTD[0] = '\0';
  }
  this_00 = (TeamFortressViewport *)this->m_szMOTD;
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  this->m_iGotAllMOTD = iVar2;
  sVar3 = strlen((char *)this_00);
  iMenu = READ_STRING();
  iVar2 = 0x5ff - sVar3;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  __strncat_chk(this_00,iMenu,iVar2,0x600);
  iVar2 = this->m_iGotAllMOTD;
  this->m_szMOTD[0x5ff] = '\0';
  if (((iVar2 != 0) && (iVar2 = (*gEngfuncs.IsSpectateOnly)(), iVar2 == 0)) &&
     (iVar2 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)(), iVar2 == 0)) {
    pCVar1 = this->m_pCurrentMenu;
    while( true ) {
      if (pCVar1 == (CMenuPanel *)0x0) {
        ShowVGUIMenu(this_00,(int)iMenu);
        return 1;
      }
      if (pCVar1->m_iMenuID == 5) break;
      pCVar1 = pCVar1->m_pNextMenu;
    }
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_BuildSt  @ 0009b030  (line 2396)

/* DWARF original prototype: int MsgFunc_BuildSt(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_BuildSt(TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_SHORT();
  this->m_iBuildState = iVar1;
  UpdateCommandMenu(this,this->m_StandardMenu);
  return 1;
}


// TeamFortressViewport::MsgFunc_RandomPC  @ 0009b080  (line 2408)

/* DWARF original prototype: int MsgFunc_RandomPC(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_RandomPC
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_iRandomPC = iVar1;
  return 1;
}


// TeamFortressViewport::MsgFunc_ServerName  @ 0009b0b0  (line 2417)

/* DWARF original prototype: int MsgFunc_ServerName(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_ServerName
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  char *__src;
  
                    /* catch() { ... } // from try @ 0009b04b with catch @ 0009b0b3 */
  BEGIN_READ(pbuf,iSize);
  __src = READ_STRING();
  strncpy(this->m_szServerName,__src,0x40);
  this->m_szServerName[0x3f] = '\0';
  return 1;
}


// TeamFortressViewport::MsgFunc_ScoreInfo  @ 0009b100  (line 2427)

/* DWARF original prototype: int MsgFunc_ScoreInfo(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_ScoreInfo
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  CTeamMenuPanel *pCVar1;
  CClassMenuPanel *pCVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  
                    /* Unresolved local var: short cl@[???]
                       Unresolved local var: short frags@[???]
                       Unresolved local var: short deaths@[???]
                       Unresolved local var: short playerclass@[???]
                       Unresolved local var: short teamnumber@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar8 = READ_BYTE();
  sVar4 = READ_SHORT();
  sVar5 = READ_SHORT();
  sVar6 = READ_SHORT();
  sVar7 = READ_SHORT();
  sVar3 = (short)iVar8;
  if ((ushort)(sVar3 - 1U) < 0x40) {
    g_PlayerExtraInfo[sVar3].frags = sVar4;
    g_PlayerExtraInfo[sVar3].deaths = sVar5;
    g_PlayerExtraInfo[sVar3].playerclass = sVar6;
    if (sVar7 < 0) {
      g_PlayerExtraInfo[sVar3].teamnumber = 0;
    }
    else {
      g_PlayerExtraInfo[sVar3].teamnumber = sVar7;
    }
    pCVar1 = this->m_pTeamMenu;
    if (pCVar1 != (CTeamMenuPanel *)0x0) {
      (**(code **)(*(int *)&(pCVar1->super_CMenuPanel).super_CTransparentPanel + 0x210))(pCVar1);
    }
    pCVar2 = this->m_pClassMenu;
    if (pCVar2 != (CClassMenuPanel *)0x0) {
      (**(code **)(*(int *)&(pCVar2->super_CMenuPanel).super_CTransparentPanel + 0x210))(pCVar2);
    }
    if (this->m_pScoreBoard != (ScorePanel *)0x0) {
      ScorePanel::Update(this->m_pScoreBoard);
    }
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_TeamScore  @ 0009b1f0  (line 2459)

/* DWARF original prototype: int MsgFunc_TeamScore(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_TeamScore
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  short sVar2;
  char *__s1;
  int iVar3;
  int iVar4;
  team_info_t *__s2;
  
                    /* Unresolved local var: char * TeamName@[???]
                       Unresolved local var: int i@[???] */
  BEGIN_READ(pbuf,iSize);
  __s1 = READ_STRING();
  iVar1 = this->m_pScoreBoard->m_iNumTeams;
  if (0 < iVar1) {
    __s2 = g_TeamInfo;
    iVar4 = 1;
    do {
      __s2 = __s2 + 1;
      iVar3 = strcasecmp(__s1,__s2->name);
      if (iVar3 == 0) {
        g_TeamInfo[iVar4].scores_overriden = 1;
        sVar2 = READ_SHORT();
        g_TeamInfo[iVar4].frags = sVar2;
        sVar2 = READ_SHORT();
        g_TeamInfo[iVar4].deaths = sVar2;
        return 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= iVar1);
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_TeamInfo  @ 0009b280  (line 2487)

/* DWARF original prototype: int MsgFunc_TeamInfo(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_TeamInfo
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  char *__src;
  
                    /* Unresolved local var: short cl@[???] */
  if (this->m_pScoreBoard != (ScorePanel *)0x0) {
    BEGIN_READ(pbuf,iSize);
    iVar1 = READ_BYTE();
    if ((ushort)((short)iVar1 - 1U) < 0x40) {
      __src = READ_STRING();
      strncpy(g_PlayerExtraInfo[(short)iVar1].teamname,__src,0x10);
    }
    ScorePanel::RebuildTeams(this->m_pScoreBoard);
  }
  return 1;
}


// TeamFortressViewport::DeathMsg  @ 0009b320  (line 2508)

/* DWARF original prototype: void DeathMsg(TeamFortressViewport * this, int killer, int victim) */

void __thiscall TeamFortressViewport::DeathMsg(TeamFortressViewport *this,int killer,int victim)

{
  ScorePanel::DeathMsg(this->m_pScoreBoard,killer,victim);
  return;
}


// TeamFortressViewport::MsgFunc_Spectator  @ 0009b340  (line 2512)

/* DWARF original prototype: int MsgFunc_Spectator(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_Spectator
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: short cl@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  if ((ushort)((short)iVar1 - 1U) < 0x40) {
    iVar2 = READ_BYTE();
    g_IsSpectator[(short)iVar1] = iVar2;
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_AllowSpec  @ 0009b380  (line 2525)

/* DWARF original prototype: int MsgFunc_AllowSpec(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_AllowSpec
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  CTeamMenuPanel *pCVar1;
  int iVar2;
  
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  this->m_iAllowSpectators = iVar2;
  UpdateCommandMenu(this,this->m_StandardMenu);
  pCVar1 = this->m_pTeamMenu;
  if (pCVar1 != (CTeamMenuPanel *)0x0) {
    (**(code **)(*(int *)&(pCVar1->super_CMenuPanel).super_CTransparentPanel + 0x210))(pCVar1);
  }
  return 1;
}


// TeamFortressViewport::MsgFunc_ResetFade  @ 0009b3e0  (line 2549)

/* DWARF original prototype: int MsgFunc_ResetFade(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_ResetFade
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  screenfade_s local_24;
  
                    /* Unresolved local var: screenfade_t sf@[???] */
  if (gpGlobals != (_2globalvars_t *)0x0) {
    (*gEngfuncs.pfnGetScreenFade)(&local_24);
    local_24.fadeFlags = 0;
    local_24.fader = '\0';
    local_24.fadeg = '\0';
    local_24.fadeb = '\0';
    local_24.fadealpha = '\0';
    local_24.fadeSpeed = 0.0;
    local_24.fadeReset = gpGlobals->time + 0.0;
    local_24.fadeEnd = local_24.fadeReset + 0.1;
    (*gEngfuncs.pfnSetScreenFade)(&local_24);
    return 1;
  }
  return 0;
}


// TeamFortressViewport::MsgFunc_SpecFade  @ 0009b460  (line 2577)

/* DWARF original prototype: int MsgFunc_SpecFade(TeamFortressViewport * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
TeamFortressViewport::MsgFunc_SpecFade
          (TeamFortressViewport *this,char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int team_no;
  int iVar6;
  Vector *pVVar7;
  ushort local_3c;
  screenfade_s local_24;
  
                    /* Unresolved local var: int iIndex@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar5 = READ_BYTE();
  if ((g_iUser1 == 4) && (iVar5 == g_iUser2)) {
                    /* Unresolved local var: int iFade@[???]
                       Unresolved local var: int iTeam@[???]
                       Unresolved local var: float flTime@[???]
                       Unresolved local var: int iAlpha@[???]
                       Unresolved local var: Vector team@[???]
                       Unresolved local var: screenfade_t sf@[???] */
    iVar5 = READ_BYTE();
    team_no = READ_BYTE();
    iVar6 = READ_SHORT();
    fVar4 = (float)iVar6 / 100.0;
    iVar6 = READ_BYTE();
    pVVar7 = GetTeamColor(team_no);
    fVar1 = pVVar7->x;
    fVar2 = pVVar7->y;
    fVar3 = pVVar7->z;
    (*gEngfuncs.pfnGetScreenFade)(&local_24);
    local_24.fadealpha = (byte)iVar6;
    local_24.fader = (byte)(int)fVar1;
    local_24.fadeSpeed = 0.0;
    local_24.fadeg = (byte)(int)fVar2;
    local_24.fadeb = (byte)(int)fVar3;
    if (iVar5 == 0) {
      local_24.fadeFlags = 1;
      if (fVar4 != 0.0) {
        local_3c = (ushort)iVar6 & 0xff;
        local_24.fadeSpeed = -(float)local_3c / fVar4;
      }
      local_24.fadeEnd = gpGlobals->time + fVar4;
      local_24.fadeReset = local_24.fadeEnd + fVar4;
      local_24.fadeTotalEnd = local_24.fadeEnd;
    }
    else {
      local_24.fadeFlags = 0;
      if (fVar4 != 0.0) {
        local_3c = (ushort)iVar6 & 0xff;
        local_24.fadeSpeed = (float)local_3c / fVar4;
      }
      local_24.fadeReset = gpGlobals->time + 0.0;
      local_24.fadeEnd = local_24.fadeReset + fVar4;
    }
    (*gEngfuncs.pfnSetScreenFade)(&local_24);
  }
                    /* catch() { ... } // from try @ 0009bc81 with catch @ 0009b4a0 */
  return 1;
}


