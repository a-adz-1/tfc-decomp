// Ghidra decompilation of functions from cl_dll/vgui_SchemeManager.cpp
// 17 functions, ordered by original source line

// Scheme_Init  @ 0008bec0  (line 30)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Scheme_Init(void)

{
  g_CV_BitmapFonts = (*gEngfuncs.pfnRegisterVariable)("bitmapfonts","1",0);
  return;
}


// CSchemeManager::CScheme::CScheme  @ 0008bef0  (line 74)

/* DWARF original prototype: void CScheme(CScheme * this) */

void __thiscall CSchemeManager::CScheme::CScheme(CScheme *this)

{
  this->schemeName[0] = '\0';
  this->fontName[0] = '\0';
  this->fontSize = 0;
  this->fontWeight = 0;
  this->font = (Font *)0x0;
  this->ownFontPointer = 0;
  return;
}


// CSchemeManager::CScheme::~CScheme  @ 0008bf20  (line 84)

/* DWARF original prototype: void ~CScheme(CScheme * this, int __in_chrg) */

void __thiscall CSchemeManager::CScheme::~CScheme(CScheme *this,int __in_chrg)

{
  if (this->ownFontPointer == 0) {
    return;
  }
  operator_delete(this->font);
  return;
}


// CSchemeManager::CSchemeManager  @ 0008bf40  (line 161)

/* DWARF original prototype: void CSchemeManager(CSchemeManager * this, int xRes, int yRes) */

void __thiscall CSchemeManager::CSchemeManager(CSchemeManager *this,int xRes,int yRes)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  byte *pbVar7;
  Font *pFVar8;
  long lVar9;
  int iVar10;
  CScheme *pCVar11;
  undefined **ppuVar12;
  int iVar13;
  CScheme *pCVar14;
  CScheme *pCVar15;
  CScheme *pCVar16;
  int in_GS_OFFSET;
  bool bVar17;
  byte bVar18;
  CScheme *local_694;
  int local_690;
  char local_685;
  char local_684;
  char local_683;
  char local_682;
  char local_681;
  byte *local_680;
  undefined1 local_670 [4];
  undefined1 local_66c [4];
  undefined1 local_668 [4];
  int local_664;
  char local_660 [63];
  undefined1 local_621;
  char local_620 [63];
  undefined1 local_5e1;
  char local_420 [1024];
  int local_20;
  
  bVar18 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: char[1024] token@[???]
                       Unresolved local var: char * pFile@[???]
                       Unresolved local var: char * pFileStart@[???]
                       Unresolved local var: byte * pFontData@[???]
                       Unresolved local var: int fontFileLength@[???]
                       Unresolved local var: char[512] fontFilename@[???]
                       Unresolved local var: int currentScheme@[???]
                       Unresolved local var: CScheme * pScheme@[???]
                       Unresolved local var: bool hasFgColor@[???]
                       Unresolved local var: bool hasBgColor@[???]
                       Unresolved local var: bool hasArmedFgColor@[???]
                       Unresolved local var: bool hasArmedBgColor@[???]
                       Unresolved local var: bool hasMouseDownFgColor@[???]
                       Unresolved local var: bool hasMouseDownBgColor@[???]
                       Unresolved local var: int numTmpSchemes@[???]
                       Unresolved local var: int resNum@[???]
                       Unresolved local var: byte * pFile@[???] */
  this->_vptr_CSchemeManager = (_func_int_varargs **)&PTR__CSchemeManager_000c6238;
  this->m_pSchemeList = (CScheme *)0x0;
  this->m_iNumSchemes = 0;
  if (xRes < 0x640) {
    if (0x4ff < xRes) {
      iVar1 = 7;
      goto LAB_0008cbf6;
    }
    if (0x47f < xRes) {
      iVar1 = 6;
      goto LAB_0008cbf6;
    }
    if (0x3ff < xRes) {
      iVar1 = 5;
      goto LAB_0008cbf6;
    }
    if (799 < xRes) {
      iVar1 = 4;
      goto LAB_0008cbf6;
    }
    if (0x27f < xRes) {
      iVar1 = 3;
      goto LAB_0008cbf6;
    }
    if (0x1ff < xRes) {
      iVar1 = 2;
      goto LAB_0008cbf6;
    }
    if (399 < xRes) {
      iVar1 = 1;
      goto LAB_0008cbf6;
    }
    if (0x13f < xRes) {
      iVar1 = 0;
      goto LAB_0008cbf6;
    }
LAB_0008bfec:
    bVar17 = CSchemeManager(int,int)::tmpSchemes == '\0';
    this->m_xRes = xRes;
    if ((bVar17) && (iVar1 = __cxa_guard_acquire(&CSchemeManager(int,int)::tmpSchemes), iVar1 != 0))
    {
      local_680 = (byte *)0x0;
LAB_0008c016:
      pCVar11 = CSchemeManager::lexical_block_0::tmpSchemes;
      do {
        pCVar11->schemeName[0] = '\0';
        pCVar14 = pCVar11 + 1;
        pCVar11->fontName[0] = '\0';
        pCVar11->fontSize = 0;
        pCVar11->fontWeight = 0;
        pCVar11->font = (Font *)0x0;
        pCVar11->ownFontPointer = 0;
        pCVar11 = pCVar14;
      } while (pCVar14 != (CScheme *)&CSchemeManager(int,int)::tmpSchemes);
      __cxa_guard_release(&CSchemeManager(int,int)::tmpSchemes);
      __cxa_atexit(__tcf_0,0,&__dso_handle);
      pCVar11 = CSchemeManager::lexical_block_0::tmpSchemes;
      for (iVar1 = 0x7c0; iVar1 != 0; iVar1 = iVar1 + -1) {
        pCVar11->schemeName[0] = '\0';
        pCVar11->schemeName[1] = '\0';
        pCVar11->schemeName[2] = '\0';
        pCVar11->schemeName[3] = '\0';
        pCVar11 = (CScheme *)((int)pCVar11 + ((uint)bVar18 * -2 + 1) * 4);
      }
      if (local_680 == (byte *)0x0) goto LAB_0008cad9;
      goto LAB_0008c0a3;
    }
    pCVar11 = CSchemeManager::lexical_block_0::tmpSchemes;
    for (iVar1 = 0x7c0; iVar1 != 0; iVar1 = iVar1 + -1) {
      pCVar11->schemeName[0] = '\0';
      pCVar11->schemeName[1] = '\0';
      pCVar11->schemeName[2] = '\0';
      pCVar11->schemeName[3] = '\0';
      pCVar11 = (CScheme *)((int)pCVar11 + ((uint)bVar18 * -2 + 1) * 4);
    }
LAB_0008cad9:
    (*gEngfuncs.Con_DPrintf)("Unable to find *_textscheme.txt\n");
  }
  else {
    iVar1 = 8;
LAB_0008cbf6:
    ppuVar12 = (undefined **)(g_ResArray + iVar1);
LAB_0008cc20:
    __sprintf_chk(local_420,1,0x100,"%s%d%s","",*ppuVar12,"_textscheme.txt");
    local_680 = (*gEngfuncs.COM_LoadFile)(local_420,5,(int *)0x0);
    if (local_680 == (byte *)0x0) goto LAB_0008cc10;
    bVar17 = CSchemeManager(int,int)::tmpSchemes == '\0';
    this->m_xRes = xRes;
    if (bVar17) {
      iVar1 = __cxa_guard_acquire(&CSchemeManager(int,int)::tmpSchemes);
      if (iVar1 == 0) {
        pCVar11 = CSchemeManager::lexical_block_0::tmpSchemes;
        for (iVar1 = 0x7c0; iVar1 != 0; iVar1 = iVar1 + -1) {
          pCVar11->schemeName[0] = '\0';
          pCVar11->schemeName[1] = '\0';
          pCVar11->schemeName[2] = '\0';
          pCVar11->schemeName[3] = '\0';
          pCVar11 = (CScheme *)((int)pCVar11 + ((uint)bVar18 * -2 + 1) * 4);
        }
        goto LAB_0008c0a3;
      }
      goto LAB_0008c016;
    }
    pCVar11 = CSchemeManager::lexical_block_0::tmpSchemes;
    for (iVar1 = 0x7c0; iVar1 != 0; iVar1 = iVar1 + -1) {
      pCVar11->schemeName[0] = '\0';
      pCVar11->schemeName[1] = '\0';
      pCVar11->schemeName[2] = '\0';
      pCVar11->schemeName[3] = '\0';
      pCVar11 = (CScheme *)((int)pCVar11 + ((uint)bVar18 * -2 + 1) * 4);
    }
LAB_0008c0a3:
    pcVar2 = (*gEngfuncs.COM_ParseFile)((char *)local_680,local_420);
    if (local_420[0] == '\0') {
      (*gEngfuncs.COM_FreeFile)(local_680);
    }
    else {
      pCVar11 = (CScheme *)0x0;
      local_694 = (CScheme *)0xffffffff;
      while( true ) {
                    /* Unresolved local var: char[64] paramName@[???]
                       Unresolved local var: char[64] paramValue@[???]
                       Unresolved local var: int tokenSize@[???] */
        strncpy(local_660,local_420,0x40);
        local_621 = 0;
        pcVar2 = (*gEngfuncs.COM_ParseFile)(pcVar2,local_420);
        iVar1 = strcasecmp(local_420,"=");
        if (iVar1 != 0) break;
        pcVar2 = (*gEngfuncs.COM_ParseFile)(pcVar2,local_420);
        strncpy(local_620,local_420,0x40);
        local_5e1 = 0;
        iVar1 = strcasecmp(local_660,"SchemeName");
        if (iVar1 == 0) {
          if (pCVar11 != (CScheme *)0x0) {
            if ((char)local_690 == '\0') {
              pCVar11->fgColor[3] = 0xff;
              pCVar11->fgColor[2] = 0xff;
              pCVar11->fgColor[1] = 0xff;
              pCVar11->fgColor[0] = 0xff;
            }
            if (local_684 == '\0') {
              *(undefined4 *)pCVar11->armedFgColor = *(undefined4 *)pCVar11->fgColor;
            }
            if (local_681 == '\0') {
              *(undefined4 *)pCVar11->mousedownFgColor = *(undefined4 *)pCVar11->armedFgColor;
            }
            if (local_685 == '\0') {
              pCVar11->bgColor[3] = '\0';
              pCVar11->bgColor[2] = '\0';
              pCVar11->bgColor[1] = '\0';
              pCVar11->bgColor[0] = '\0';
            }
            if (local_682 == '\0') {
              *(undefined4 *)pCVar11->armedBgColor = *(undefined4 *)pCVar11->bgColor;
            }
            if (local_683 == '\0') {
              *(undefined4 *)pCVar11->mousedownBgColor = *(undefined4 *)pCVar11->armedBgColor;
            }
            if (pCVar11->fontSize == 0) {
              pCVar11->fontSize = 0x11;
            }
            if (pCVar11->fontName[0] == '\0') {
              builtin_strncpy(pCVar11->fontName,"Arial",6);
            }
          }
          local_694 = (CScheme *)((int)local_694 + 1);
          pCVar11 = CSchemeManager::lexical_block_0::tmpSchemes + (int)local_694;
          strncpy(pCVar11->schemeName,local_620,0x20);
          CSchemeManager::lexical_block_0::tmpSchemes[(int)local_694].schemeName[0x1f] = '\0';
          local_683 = '\0';
          local_681 = '\0';
          local_682 = '\0';
          local_684 = '\0';
          local_685 = '\0';
          local_690._0_1_ = '\0';
        }
        else if (pCVar11 == (CScheme *)0x0) {
          (*gEngfuncs.Con_Printf)("font scheme text file MUST start with a \'SchemeName\'\n");
          goto LAB_0008c3a5;
        }
        iVar1 = strcasecmp(local_660,"FontName");
        if (iVar1 == 0) {
          strncpy(pCVar11->fontName,local_620,0x30);
          pCVar11->fontName[0x2f] = '\0';
        }
        else {
          iVar1 = strcasecmp(local_660,"FontSize");
          if (iVar1 == 0) {
            lVar9 = strtol(local_620,(char **)0x0,10);
            pCVar11->fontSize = lVar9;
          }
          else {
            iVar1 = strcasecmp(local_660,"FontWeight");
            if (iVar1 == 0) {
              lVar9 = strtol(local_620,(char **)0x0,10);
              pCVar11->fontWeight = lVar9;
            }
            else {
              iVar1 = strcasecmp(local_660,"FgColor");
              if (iVar1 == 0) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???] */
                sscanf(local_620,"%d %d %d %d",local_670,local_66c,local_668,&local_664);
                local_690._0_1_ = '\x01';
                pCVar11->fgColor[0] = local_670[0];
                pCVar11->fgColor[1] = local_66c[0];
                pCVar11->fgColor[2] = local_668[0];
                pCVar11->fgColor[3] = (byte)local_664;
              }
              else {
                iVar1 = strcasecmp(local_660,"BgColor");
                if (iVar1 == 0) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???] */
                  sscanf(local_620,"%d %d %d %d",local_670,local_66c,local_668,&local_664);
                  local_685 = '\x01';
                  pCVar11->bgColor[0] = local_670[0];
                  pCVar11->bgColor[1] = local_66c[0];
                  pCVar11->bgColor[2] = local_668[0];
                  pCVar11->bgColor[3] = (byte)local_664;
                }
                else {
                  iVar1 = strcasecmp(local_660,"FgColorArmed");
                  if (iVar1 == 0) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???] */
                    sscanf(local_620,"%d %d %d %d",local_670,local_66c,local_668,&local_664);
                    local_684 = '\x01';
                    pCVar11->armedFgColor[0] = local_670[0];
                    pCVar11->armedFgColor[1] = local_66c[0];
                    pCVar11->armedFgColor[2] = local_668[0];
                    pCVar11->armedFgColor[3] = (byte)local_664;
                  }
                  else {
                    iVar1 = strcasecmp(local_660,"BgColorArmed");
                    if (iVar1 == 0) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???] */
                      sscanf(local_620,"%d %d %d %d",local_670,local_66c,local_668,&local_664);
                      local_682 = '\x01';
                      pCVar11->armedBgColor[0] = local_670[0];
                      pCVar11->armedBgColor[1] = local_66c[0];
                      pCVar11->armedBgColor[2] = local_668[0];
                      pCVar11->armedBgColor[3] = (byte)local_664;
                    }
                    else {
                      iVar1 = strcasecmp(local_660,"FgColorMousedown");
                      if (iVar1 == 0) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???] */
                        sscanf(local_620,"%d %d %d %d",local_670,local_66c,local_668,&local_664);
                        local_681 = '\x01';
                        pCVar11->mousedownFgColor[0] = local_670[0];
                        pCVar11->mousedownFgColor[1] = local_66c[0];
                        pCVar11->mousedownFgColor[2] = local_668[0];
                        pCVar11->mousedownFgColor[3] = (byte)local_664;
                      }
                      else {
                        iVar1 = strcasecmp(local_660,"BgColorMousedown");
                        if (iVar1 == 0) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???] */
                          sscanf(local_620,"%d %d %d %d",local_670,local_66c,local_668,&local_664);
                          local_683 = '\x01';
                          pCVar11->mousedownBgColor[0] = local_670[0];
                          pCVar11->mousedownBgColor[1] = local_66c[0];
                          pCVar11->mousedownBgColor[2] = local_668[0];
                          pCVar11->mousedownBgColor[3] = (byte)local_664;
                        }
                        else {
                          iVar1 = strcasecmp(local_660,"BorderColor");
                          if (iVar1 == 0) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???] */
                            sscanf(local_620,"%d %d %d %d",local_670,local_66c,local_668,&local_664)
                            ;
                            local_683 = '\x01';
                            pCVar11->borderColor[0] = local_670[0];
                            pCVar11->borderColor[1] = local_66c[0];
                            pCVar11->borderColor[2] = local_668[0];
                            pCVar11->borderColor[3] = (byte)local_664;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        pcVar2 = (*gEngfuncs.COM_ParseFile)(pcVar2,local_420);
        if ((local_420[0] == '\0') || (0x3f < (int)local_694)) goto LAB_0008c3a5;
      }
      if (local_694 == (CScheme *)0xffffffff) {
        (*gEngfuncs.Con_Printf)
                  ("error parsing font scheme text file at file start - expected \'=\', found \'%s\'\'\n"
                   ,local_420);
      }
      else {
        (*gEngfuncs.Con_Printf)
                  ("error parsing font scheme text file at scheme \'%s\' - expected \'=\', found \'%s\'\'\n"
                   ,CSchemeManager::lexical_block_0::tmpSchemes + (int)local_694,local_420);
      }
LAB_0008c3a5:
      (*gEngfuncs.COM_FreeFile)(local_680);
      if (local_694 != (CScheme *)0xffffffff) {
        iVar1 = (int)local_694 + 1;
        uVar3 = 0xffffffff;
        this->m_iNumSchemes = iVar1;
        if (iVar1 < 0x1080001) {
          uVar3 = iVar1 * 0x7c + 4;
        }
        goto LAB_0008c3eb;
      }
    }
  }
  builtin_strncpy(CSchemeManager::lexical_block_0::tmpSchemes[0].schemeName,"Default Scheme",0xf);
  builtin_strncpy(CSchemeManager::lexical_block_0::tmpSchemes[0].schemeName,"Arial",6);
  iVar1 = 1;
  CSchemeManager::lexical_block_0::tmpSchemes[0].fontSize = 0;
  local_694 = (CScheme *)0x0;
  CSchemeManager::lexical_block_0::tmpSchemes[0].fgColor[3] = 0xff;
  CSchemeManager::lexical_block_0::tmpSchemes[0].fgColor[2] = 0xff;
  CSchemeManager::lexical_block_0::tmpSchemes[0].fgColor[1] = 0xff;
  CSchemeManager::lexical_block_0::tmpSchemes[0].fgColor[0] = 0xff;
  CSchemeManager::lexical_block_0::tmpSchemes[0].armedFgColor[3] = 0xff;
  CSchemeManager::lexical_block_0::tmpSchemes[0].armedFgColor[2] = 0xff;
  CSchemeManager::lexical_block_0::tmpSchemes[0].armedFgColor[1] = 0xff;
  CSchemeManager::lexical_block_0::tmpSchemes[0].armedFgColor[0] = 0xff;
  CSchemeManager::lexical_block_0::tmpSchemes[0].mousedownFgColor[3] = 0xff;
  CSchemeManager::lexical_block_0::tmpSchemes[0].mousedownFgColor[2] = 0xff;
  CSchemeManager::lexical_block_0::tmpSchemes[0].mousedownFgColor[1] = 0xff;
  CSchemeManager::lexical_block_0::tmpSchemes[0].mousedownFgColor[0] = 0xff;
  this->m_iNumSchemes = 1;
  uVar3 = 0x80;
LAB_0008c3eb:
  piVar4 = operator_new__(uVar3);
  iVar10 = 0;
  pCVar11 = (CScheme *)(piVar4 + 1);
  *piVar4 = iVar1;
  pCVar14 = pCVar11;
  do {
    iVar10 = iVar10 + 1;
    pCVar14->schemeName[0] = '\0';
    pCVar14->fontName[0] = '\0';
    pCVar14->fontSize = 0;
    pCVar14->fontWeight = 0;
    pCVar14->font = (Font *)0x0;
    pCVar14->ownFontPointer = 0;
    pCVar14 = pCVar14 + 1;
  } while ((int)local_694 + 1 != iVar10);
  iVar1 = this->m_iNumSchemes;
  this->m_pSchemeList = pCVar11;
  uVar3 = iVar1 * 0x7c;
  pCVar14 = CSchemeManager::lexical_block_0::tmpSchemes;
  pCVar16 = pCVar11;
  if (7 < uVar3) {
    if (((uint)pCVar11 & 1) != 0) {
      pCVar14 = (CScheme *)(CSchemeManager::lexical_block_0::tmpSchemes[0].schemeName + 1);
      uVar3 = uVar3 - 1;
      *(char *)(piVar4 + 1) = (char)CSchemeManager::lexical_block_0::tmpSchemes[0].schemeName._0_4_;
      pCVar16 = (CScheme *)((int)piVar4 + 5);
    }
    pCVar15 = pCVar16;
    if (((uint)pCVar16 & 2) != 0) {
      pcVar2 = pCVar14->schemeName;
      pCVar15 = (CScheme *)(pCVar16->schemeName + 2);
      pCVar14 = (CScheme *)(pCVar14->schemeName + 2);
      uVar3 = uVar3 - 2;
      *(undefined2 *)pCVar16->schemeName = *(undefined2 *)pcVar2;
    }
    pCVar16 = pCVar15;
    if (((uint)pCVar15 & 4) != 0) {
      pcVar2 = pCVar14->schemeName;
      pCVar16 = (CScheme *)(pCVar15->schemeName + 4);
      pCVar14 = (CScheme *)(pCVar14->schemeName + 4);
      uVar3 = uVar3 - 4;
      *(int *)pCVar15->schemeName = *(int *)pcVar2;
    }
  }
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    pCVar16->schemeName[0] = pCVar14->schemeName[0];
    pCVar14 = (CScheme *)((int)pCVar14 + (uint)bVar18 * -2 + 1);
    pCVar16 = (CScheme *)((int)pCVar16 + (uint)bVar18 * -2 + 1);
  }
  if (iVar1 < 1) {
LAB_0008c7ae:
    if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  iVar1 = 0;
  piVar4[0x17] = 0;
  local_690 = 0;
  do {
    pFVar8 = pCVar11->font;
    iVar10 = local_690;
    while( true ) {
      if (pFVar8 == (Font *)0x0) {
        local_664 = -1;
        if ((g_CV_BitmapFonts == (cvar_t *)0x0) || (g_CV_BitmapFonts->value == 0.0)) {
          pbVar7 = (byte *)0x0;
        }
        else {
                    /* Unresolved local var: int fontRes@[???] */
          iVar13 = this->m_xRes;
          uVar6 = 0x640;
          if ((((iVar13 < 0x640) && (uVar6 = 0x500, iVar13 < 0x500)) &&
              (uVar6 = 0x480, iVar13 < 0x480)) &&
             ((uVar6 = 0x400, iVar13 < 0x400 && (uVar6 = 800, iVar13 < 800)))) {
            uVar6 = 0x280;
          }
          __sprintf_chk(local_620,1,0x200,"gfx\\vgui\\fonts\\%d_%s.tga",uVar6,pCVar11);
          pbVar7 = (*gEngfuncs.COM_LoadFile)(local_620,5,&local_664);
          if (pbVar7 == (byte *)0x0) {
            (*gEngfuncs.Con_Printf)("Missing bitmap font: %s\n",local_620);
          }
        }
        pFVar8 = operator_new(0x10);
        pCVar11 = this->m_pSchemeList;
        vgui::Font::Font(pFVar8,pCVar11->fontName + iVar10,pbVar7,local_664,
                         *(int *)(pCVar11->fgColor + iVar10 + -0x10),0,0.0,
                         *(int *)(pCVar11->fgColor + iVar10 + -0xc),false,false,false,false);
        *(Font **)(this->m_pSchemeList->fgColor + iVar10 + -8) = pFVar8;
        pbVar7 = this->m_pSchemeList->fgColor + iVar10 + -4;
        pbVar7[0] = '\x01';
        pbVar7[1] = '\0';
        pbVar7[2] = '\0';
        pbVar7[3] = '\0';
        pCVar11 = (CScheme *)(this->m_pSchemeList->schemeName + iVar10);
      }
      iVar1 = iVar1 + 1;
      pCVar11->fgColor[3] = ~pCVar11->fgColor[3];
      pbVar7 = this->m_pSchemeList->bgColor + iVar10 + 3;
      *pbVar7 = ~*pbVar7;
      pbVar7 = this->m_pSchemeList->armedFgColor + iVar10 + 3;
      *pbVar7 = ~*pbVar7;
      pbVar7 = this->m_pSchemeList->armedBgColor + iVar10 + 3;
      *pbVar7 = ~*pbVar7;
      pbVar7 = this->m_pSchemeList->mousedownFgColor + iVar10 + 3;
      *pbVar7 = ~*pbVar7;
      pbVar7 = this->m_pSchemeList->mousedownBgColor + iVar10 + 3;
      *pbVar7 = ~*pbVar7;
      if (this->m_iNumSchemes <= iVar1) goto LAB_0008c7ae;
      local_690 = iVar10 + 0x7c;
      pbVar7 = this->m_pSchemeList[1].fgColor + iVar10 + -8;
                    /* Unresolved local var: int j@[???] */
      pbVar7[0] = '\0';
      pbVar7[1] = '\0';
      pbVar7[2] = '\0';
      pbVar7[3] = '\0';
      if (iVar1 < 1) break;
      local_694 = this->m_pSchemeList;
      pCVar11 = (CScheme *)(local_694[1].schemeName + iVar10);
      iVar13 = 0;
      do {
        while (((iVar5 = strcasecmp(pCVar11->fontName,local_694[iVar13].fontName), iVar5 == 0 &&
                (pCVar11->fontSize == local_694[iVar13].fontSize)) &&
               (pCVar11->fontWeight == local_694[iVar13].fontWeight))) {
          local_694 = local_694 + iVar13;
          iVar13 = iVar13 + 1;
          pCVar11->font = local_694->font;
          pbVar7 = this->m_pSchemeList[1].fgColor + iVar10 + -4;
          pbVar7[0] = '\0';
          pbVar7[1] = '\0';
          pbVar7[2] = '\0';
          pbVar7[3] = '\0';
          local_694 = this->m_pSchemeList;
          pCVar11 = (CScheme *)(local_694[1].schemeName + iVar10);
          if (iVar13 == iVar1) goto LAB_0008c580;
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 != iVar1);
LAB_0008c580:
      pFVar8 = pCVar11->font;
      iVar10 = local_690;
    }
    pCVar11 = (CScheme *)(this->m_pSchemeList[1].schemeName + iVar10);
  } while( true );
LAB_0008cc10:
  ppuVar12 = ppuVar12 + -1;
                    /* Unresolved local var: char[256] fname@[???] */
  if (ppuVar12 == &PTR__CSchemeManager_000c623c) goto LAB_0008bfec;
  goto LAB_0008cc20;
}


// __tcf_0  @ 0008bd80  (line 187)

void __tcf_0(void *param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = (char *)0x111624;
  do {
    while (*(int *)(pcVar2 + 0x5c) != 0) {
      pcVar1 = pcVar2 + 0x58;
      pcVar2 = pcVar2 + -0x7c;
      operator_delete(*(void **)pcVar1);
      if (pcVar2 == GetTGANameForRes::gd + 0xa4) {
        return;
      }
    }
    pcVar2 = pcVar2 + -0x7c;
  } while (pcVar2 != GetTGANameForRes::gd + 0xa4);
  return;
}


// CSchemeManager::~CSchemeManager  @ 0008bdc0  (line 445)

/* DWARF original prototype: void ~CSchemeManager(CSchemeManager * this, int __in_chrg) */

void __thiscall CSchemeManager::~CSchemeManager(CSchemeManager *this,int __in_chrg)

{
  CScheme *pCVar1;
  CScheme *pCVar2;
  
  pCVar1 = this->m_pSchemeList;
  this->_vptr_CSchemeManager = (_func_int_varargs **)&PTR__CSchemeManager_000c6238;
  if (pCVar1 == (CScheme *)0x0) {
    return;
  }
  pCVar2 = pCVar1 + *(int *)pCVar1[-1].borderColor;
  if (pCVar1 != pCVar2) {
    pCVar1 = pCVar2 + -1;
    do {
      while (pCVar2 = pCVar1, pCVar2->ownFontPointer != 0) {
        operator_delete(pCVar2->font);
        pCVar1 = pCVar2 + -1;
        if (this->m_pSchemeList == pCVar2) goto LAB_0008be1c;
      }
      pCVar1 = pCVar2 + -1;
    } while (this->m_pSchemeList != pCVar2);
  }
LAB_0008be1c:
  operator_delete__(pCVar2[-1].borderColor);
  return;
}


// CSchemeManager::~CSchemeManager  @ 0008be40  (line 445)

/* DWARF original prototype: void ~CSchemeManager(CSchemeManager * this, int __in_chrg) */

void __thiscall CSchemeManager::~CSchemeManager(CSchemeManager *this,int __in_chrg)

{
  CScheme *pCVar1;
  CScheme *pCVar2;
  
  pCVar1 = this->m_pSchemeList;
  this->_vptr_CSchemeManager = (_func_int_varargs **)&PTR__CSchemeManager_000c6238;
  if (pCVar1 != (CScheme *)0x0) {
    pCVar2 = pCVar1 + *(int *)pCVar1[-1].borderColor;
    if (pCVar1 != pCVar2) {
      pCVar1 = pCVar2 + -1;
      do {
        while (pCVar2 = pCVar1, pCVar2->ownFontPointer != 0) {
          operator_delete(pCVar2->font);
          pCVar1 = pCVar2 + -1;
          if (this->m_pSchemeList == pCVar2) goto LAB_0008be9c;
        }
        pCVar1 = pCVar2 + -1;
      } while (this->m_pSchemeList != pCVar2);
    }
LAB_0008be9c:
    operator_delete__(pCVar2[-1].borderColor);
  }
  operator_delete(this);
  return;
}


// CSchemeManager::getSchemeHandle  @ 0008cd60  (line 457)

/* DWARF original prototype: SchemeHandle_t getSchemeHandle(CSchemeManager * this, char *
   schemeName) */

SchemeHandle_t __thiscall CSchemeManager::getSchemeHandle(CSchemeManager *this,char *schemeName)

{
  int iVar1;
  int iVar2;
  int iVar3;
  CScheme *__s2;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = this->m_iNumSchemes;
  if (0 < iVar1) {
    __s2 = this->m_pSchemeList;
    iVar3 = 0;
    do {
      iVar2 = strcasecmp(schemeName,__s2->schemeName);
      if (iVar2 == 0) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      __s2 = __s2 + 1;
    } while (iVar3 != iVar1);
  }
  return 0;
}


// CSchemeManager::getSafeScheme  @ 0008cdc0  (line 474)

/* DWARF original prototype: CScheme * getSafeScheme(CSchemeManager * this, SchemeHandle_t
   schemeHandle) */

CScheme * __thiscall CSchemeManager::getSafeScheme(CSchemeManager *this,SchemeHandle_t schemeHandle)

{
  if (this->m_iNumSchemes <= schemeHandle) {
    return this->m_pSchemeList;
  }
  return this->m_pSchemeList + schemeHandle;
}


// CSchemeManager::getFont  @ 0008cdf0  (line 488)

/* DWARF original prototype: Font * getFont(CSchemeManager * this, SchemeHandle_t schemeHandle) */

Font * __thiscall CSchemeManager::getFont(CSchemeManager *this,SchemeHandle_t schemeHandle)

{
  if (this->m_iNumSchemes <= schemeHandle) {
    return this->m_pSchemeList->font;
  }
  return this->m_pSchemeList[schemeHandle].font;
}


// CSchemeManager::getFgColor  @ 0008ce20  (line 493)

/* DWARF original prototype: void getFgColor(CSchemeManager * this, SchemeHandle_t schemeHandle, int
   * r, int * g, int * b, int * a) */

void __thiscall
CSchemeManager::getFgColor
          (CSchemeManager *this,SchemeHandle_t schemeHandle,int *r,int *g,int *b,int *a)

{
  CScheme *pCVar1;
  
                    /* Unresolved local var: CScheme * pScheme@[???] */
  if (schemeHandle < this->m_iNumSchemes) {
    pCVar1 = this->m_pSchemeList + schemeHandle;
  }
  else {
    pCVar1 = this->m_pSchemeList;
  }
  *r = (uint)pCVar1->fgColor[0];
  *g = (uint)pCVar1->fgColor[1];
  *b = (uint)pCVar1->fgColor[2];
  *a = (uint)pCVar1->fgColor[3];
  return;
}


// CSchemeManager::getBgColor  @ 0008ce80  (line 502)

/* DWARF original prototype: void getBgColor(CSchemeManager * this, SchemeHandle_t schemeHandle, int
   * r, int * g, int * b, int * a) */

void __thiscall
CSchemeManager::getBgColor
          (CSchemeManager *this,SchemeHandle_t schemeHandle,int *r,int *g,int *b,int *a)

{
  CScheme *pCVar1;
  
                    /* Unresolved local var: CScheme * pScheme@[???] */
  if (schemeHandle < this->m_iNumSchemes) {
    pCVar1 = this->m_pSchemeList + schemeHandle;
  }
  else {
    pCVar1 = this->m_pSchemeList;
  }
  *r = (uint)pCVar1->bgColor[0];
  *g = (uint)pCVar1->bgColor[1];
  *b = (uint)pCVar1->bgColor[2];
  *a = (uint)pCVar1->bgColor[3];
  return;
}


// CSchemeManager::getFgArmedColor  @ 0008cee0  (line 511)

/* DWARF original prototype: void getFgArmedColor(CSchemeManager * this, SchemeHandle_t
   schemeHandle, int * r, int * g, int * b, int * a) */

void __thiscall
CSchemeManager::getFgArmedColor
          (CSchemeManager *this,SchemeHandle_t schemeHandle,int *r,int *g,int *b,int *a)

{
  CScheme *pCVar1;
  
                    /* Unresolved local var: CScheme * pScheme@[???] */
  if (schemeHandle < this->m_iNumSchemes) {
    pCVar1 = this->m_pSchemeList + schemeHandle;
  }
  else {
    pCVar1 = this->m_pSchemeList;
  }
  *r = (uint)pCVar1->armedFgColor[0];
  *g = (uint)pCVar1->armedFgColor[1];
  *b = (uint)pCVar1->armedFgColor[2];
  *a = (uint)pCVar1->armedFgColor[3];
  return;
}


// CSchemeManager::getBgArmedColor  @ 0008cf40  (line 520)

/* DWARF original prototype: void getBgArmedColor(CSchemeManager * this, SchemeHandle_t
   schemeHandle, int * r, int * g, int * b, int * a) */

void __thiscall
CSchemeManager::getBgArmedColor
          (CSchemeManager *this,SchemeHandle_t schemeHandle,int *r,int *g,int *b,int *a)

{
  CScheme *pCVar1;
  
                    /* Unresolved local var: CScheme * pScheme@[???] */
  if (schemeHandle < this->m_iNumSchemes) {
    pCVar1 = this->m_pSchemeList + schemeHandle;
  }
  else {
    pCVar1 = this->m_pSchemeList;
  }
  *r = (uint)pCVar1->armedBgColor[0];
  *g = (uint)pCVar1->armedBgColor[1];
  *b = (uint)pCVar1->armedBgColor[2];
  *a = (uint)pCVar1->armedBgColor[3];
  return;
}


// CSchemeManager::getFgMousedownColor  @ 0008cfa0  (line 529)

/* DWARF original prototype: void getFgMousedownColor(CSchemeManager * this, SchemeHandle_t
   schemeHandle, int * r, int * g, int * b, int * a) */

void __thiscall
CSchemeManager::getFgMousedownColor
          (CSchemeManager *this,SchemeHandle_t schemeHandle,int *r,int *g,int *b,int *a)

{
  CScheme *pCVar1;
  
                    /* Unresolved local var: CScheme * pScheme@[???] */
  if (schemeHandle < this->m_iNumSchemes) {
    pCVar1 = this->m_pSchemeList + schemeHandle;
  }
  else {
    pCVar1 = this->m_pSchemeList;
  }
  *r = (uint)pCVar1->mousedownFgColor[0];
  *g = (uint)pCVar1->mousedownFgColor[1];
  *b = (uint)pCVar1->mousedownFgColor[2];
  *a = (uint)pCVar1->mousedownFgColor[3];
  return;
}


// CSchemeManager::getBgMousedownColor  @ 0008d000  (line 538)

/* DWARF original prototype: void getBgMousedownColor(CSchemeManager * this, SchemeHandle_t
   schemeHandle, int * r, int * g, int * b, int * a) */

void __thiscall
CSchemeManager::getBgMousedownColor
          (CSchemeManager *this,SchemeHandle_t schemeHandle,int *r,int *g,int *b,int *a)

{
  CScheme *pCVar1;
  
                    /* Unresolved local var: CScheme * pScheme@[???] */
  if (schemeHandle < this->m_iNumSchemes) {
    pCVar1 = this->m_pSchemeList + schemeHandle;
  }
  else {
    pCVar1 = this->m_pSchemeList;
  }
  *r = (uint)pCVar1->mousedownBgColor[0];
  *g = (uint)pCVar1->mousedownBgColor[1];
  *b = (uint)pCVar1->mousedownBgColor[2];
  *a = (uint)pCVar1->mousedownBgColor[3];
  return;
}


// CSchemeManager::getBorderColor  @ 0008d060  (line 547)

/* DWARF original prototype: void getBorderColor(CSchemeManager * this, SchemeHandle_t schemeHandle,
   int * r, int * g, int * b, int * a) */

void __thiscall
CSchemeManager::getBorderColor
          (CSchemeManager *this,SchemeHandle_t schemeHandle,int *r,int *g,int *b,int *a)

{
  CScheme *pCVar1;
  
                    /* Unresolved local var: CScheme * pScheme@[???] */
  if (schemeHandle < this->m_iNumSchemes) {
    pCVar1 = this->m_pSchemeList + schemeHandle;
  }
  else {
    pCVar1 = this->m_pSchemeList;
  }
  *r = (uint)pCVar1->borderColor[0];
  *g = (uint)pCVar1->borderColor[1];
  *b = (uint)pCVar1->borderColor[2];
  *a = (uint)pCVar1->borderColor[3];
  return;
}


