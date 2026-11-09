// VGUI2_DrawString  @ 0021c160
int VGUI2_DrawString(int x,int y,char *str,uint font)

{
  ISurface *pIVar1;
  ILocalize *pIVar2;
  size_t sVar3;
  int iVar4;
  wchar_t *__s;
  uint uVar5;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: wchar_t * localizedString@[DW_OP_reg3(EBX)]
                       Unresolved local var: wchar_t * fixString@[???] */
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x18])
            (g_BaseUISurface._engineSurface);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xe])(pIVar1,font);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x11])(pIVar1,x,y);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x10])(pIVar1,_col._color);
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  if ((str != (char *)0x0) && (*str == '#')) {
    pIVar2 = vgui2::localize();
    __s = (wchar_t *)(**(code **)(*(int *)pIVar2 + 0x10))(pIVar2,str);
    if (__s != (wchar_t *)0x0) goto LAB_0021c1f8;
  }
  pIVar2 = vgui2::localize();
  __s = VGUI2_Find_String::lexical_block_0::tmpString;
  (**(code **)(*(int *)pIVar2 + 0x14))
            (pIVar2,str,VGUI2_Find_String::lexical_block_0::tmpString,0x1000);
LAB_0021c1f8:
                    /* Unresolved local var: uint i@[???] */
  sVar3 = wcslen(__s);
  if (sVar3 != 0) {
    uVar5 = 0;
    do {
      iVar4 = iswprint(__s[uVar5]);
      if (iVar4 == 0) {
        __s[uVar5] = L' ';
        sVar3 = wcslen(__s);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < sVar3);
  }
  pIVar1 = vgui2::surface();
  iVar4 = 0;
  sVar3 = wcslen(__s);
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x13])(pIVar1,__s,sVar3);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x16])(pIVar1);
  for (uVar5 = 0; sVar3 = wcslen(__s), uVar5 < sVar3; uVar5 = uVar5 + 1) {
                    /* Unresolved local var: int totalWidth@[???]
                       Unresolved local var: uint i@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
    pIVar1 = vgui2::surface();
    (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x40])
              (pIVar1,font,__s[uVar5],&local_28,&local_24,local_20);
    iVar4 = iVar4 + local_28 + local_24 + local_20[0];
  }
  return iVar4;
}


// VGUI2_DrawStringClient  @ 0021c2f0
int VGUI2_DrawStringClient(int x,int y,char *str,int r,int g,int b)

{
  ILocalize *pIVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  int x_00;
  wchar_t *__s;
  
                    /* Unresolved local var: wchar_t * localizedString@[DW_OP_reg7(EDI)]
                       Unresolved local var: int xpos@[???]
                       Unresolved local var: uint i@[???] */
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x18])
            (g_BaseUISurface._engineSurface);
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  if ((str != (char *)0x0) && (*str == '#')) {
    pIVar1 = vgui2::localize();
    __s = (wchar_t *)(**(code **)(*(int *)pIVar1 + 0x10))(pIVar1,str);
    if (__s != (wchar_t *)0x0) goto LAB_0021c341;
  }
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  pIVar1 = vgui2::localize();
  __s = VGUI2_Find_String::lexical_block_0::tmpString;
  (**(code **)(*(int *)pIVar1 + 0x14))
            (pIVar1,str,VGUI2_Find_String::lexical_block_0::tmpString,0x1000);
LAB_0021c341:
  x_00 = x;
  for (uVar4 = 0; sVar3 = wcslen(__s), uVar4 < sVar3; uVar4 = uVar4 + 1) {
                    /* Unresolved local var: int next@[???] */
    iVar2 = VGUI2_Draw_CharacterAdd(x_00,y,__s[uVar4],r,g,b,_creditsFont);
    x_00 = x_00 + iVar2;
  }
  return x_00 - x;
}


// VGUI2_DrawStringReverseClient  @ 0021c3d0
int VGUI2_DrawStringReverseClient(int x,int y,char *str,int r,int g,int b)

{
  wchar_t ch;
  ILocalize *pIVar1;
  size_t sVar2;
  ISurface *pIVar3;
  int iVar4;
  wchar_t *pwVar5;
  int x_00;
  wchar_t *local_50;
  int local_4c [4];
  int local_3c [4];
  int local_2c [7];
  
                    /* Unresolved local var: wchar_t * localizedString@[DW_OP_breg4(ESP): +44]
                       Unresolved local var: wchar_t * szIt@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int z@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int xpos@[???]
                       Unresolved local var: wchar_t * localizedString@[???] */
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x18])
            (g_BaseUISurface._engineSurface);
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  if ((str != (char *)0x0) && (*str == '#')) {
    pIVar1 = vgui2::localize();
    local_50 = (wchar_t *)(**(code **)(*(int *)pIVar1 + 0x10))(pIVar1,str);
    if (local_50 != (wchar_t *)0x0) goto LAB_0021c436;
  }
  pIVar1 = vgui2::localize();
  (**(code **)(*(int *)pIVar1 + 0x14))
            (pIVar1,str,VGUI2_Find_String::lexical_block_0::tmpString,0x1000);
  local_50 = VGUI2_Find_String::lexical_block_0::tmpString;
LAB_0021c436:
  sVar2 = wcslen(local_50);
  pIVar3 = vgui2::surface();
  pwVar5 = local_50 + (sVar2 - 1);
  (*(pIVar3->super_IBaseInterface)._vptr_IBaseInterface[0x40])
            (pIVar3,_creditsFont,local_50[sVar2 - 2],local_4c,local_3c,local_2c);
  iVar4 = local_4c[0] + local_3c[0] + local_2c[0];
  x_00 = x - iVar4;
  if (pwVar5 != local_50 + -1) {
    do {
                    /* Unresolved local var: int next@[???] */
      ch = *pwVar5;
      pwVar5 = pwVar5 + -1;
      iVar4 = VGUI2_Draw_CharacterAdd(x_00,y,ch,r,g,b,_creditsFont);
      x_00 = x_00 - iVar4;
    } while (pwVar5 != local_50 + -1);
    iVar4 = local_3c[0] + local_4c[0] + local_2c[0];
  }
  return iVar4 + (x - x_00);
}


// VGUI2_Draw_Character  @ 0021bf90
int VGUI2_Draw_Character(int x,int y,int ch,uint font)

{
  ISurface *pIVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10 [2];
  
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x18])
            (g_BaseUISurface._engineSurface);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xe])(pIVar1,font);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x11])(pIVar1,x,y);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x10])(pIVar1,_col._color);
  iVar2 = iswprint(ch);
  if (iVar2 != 0) {
    pIVar1 = vgui2::surface();
    (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x14])(pIVar1,ch);
    pIVar1 = vgui2::surface();
    (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x16])(pIVar1);
  }
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x40])
            (pIVar1,font,ch,&local_18,&local_14,local_10);
  return local_18 + local_14 + local_10[0];
}


// VGUI2_Draw_CharacterAdd  @ 0021c060
int VGUI2_Draw_CharacterAdd(int x,int y,int ch,int r,int g,int b,uint font)

{
  ISurface *pIVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10 [2];
  
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int z@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int tall@[???] */
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x18])
            (g_BaseUISurface._engineSurface);
  _col._color[1] = (uchar)g;
  _col._color[0] = (uchar)r;
  _col._color[2] = (uchar)b;
  _col._color[3] = 0xff;
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xe])(pIVar1,font);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x11])(pIVar1,x,y);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x10])(pIVar1,_col._color);
  iVar2 = iswprint(ch);
  if (iVar2 != 0) {
    pIVar1 = vgui2::surface();
    (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x15])(pIVar1,ch);
  }
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x3f])(pIVar1,font);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x40])
            (pIVar1,font,ch,&local_18,&local_14,local_10);
  return local_18 + local_14 + local_10[0];
}


// VGUI2_Draw_Init  @ 0021bed0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGUI2_Draw_Init(void)

{
  code *pcVar1;
  ISchemeManager *pIVar2;
  ISchemeManager *pIVar3;
  undefined4 uVar4;
  int *piVar5;
  
                    /* Unresolved local var: IScheme * pScheme@[???] */
  pIVar2 = vgui2::scheme();
  pcVar1 = *(code **)(*(int *)pIVar2 + 0x20);
  pIVar3 = vgui2::scheme();
  uVar4 = (**(code **)(*(int *)pIVar3 + 0x10))(pIVar3);
  piVar5 = (int *)(*pcVar1)(pIVar2,uVar4);
  if (_consoleFont == 0) {
    _consoleFont = (**(code **)(*piVar5 + 0x10))(piVar5,"EngineFont",1);
  }
  if (_creditsFont == 0) {
    _creditsFont = (**(code **)(*piVar5 + 0x10))(piVar5,"Legacy_CreditsFont",1);
  }
  return;
}


// VGUI2_Draw_SetTextColor  @ 0021c540
void VGUI2_Draw_SetTextColor(int r,int g,int b)

{
  _col._color[3] = 0xff;
  _col._color[0] = (uchar)r;
  _col._color[1] = (uchar)g;
  _col._color[2] = (uchar)b;
  return;
}


// VGUI2_Draw_SetTextColorAlpha  @ 0021c570
void VGUI2_Draw_SetTextColorAlpha(int r,int g,int b,int a)

{
  _col._color[0] = (uchar)r;
  _col._color[1] = (uchar)g;
  _col._color[2] = (uchar)b;
  _col._color[3] = (uchar)a;
  return;
}


// VGUI2_Draw_StringLen  @ 0021c5a0
int VGUI2_Draw_StringLen(char *psz,uint font)

{
  ILocalize *pIVar1;
  ISurface *pIVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  wchar_t *__s;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: wchar_t * localizedString@[DW_OP_reg7(EDI)]
                       Unresolved local var: int totalWidth@[???]
                       Unresolved local var: wchar_t * localizedString@[???] */
  if ((psz != (char *)0x0) && (*psz == '#')) {
    pIVar1 = vgui2::localize();
    __s = (wchar_t *)(**(code **)(*(int *)pIVar1 + 0x10))(pIVar1,psz);
    if (__s != (wchar_t *)0x0) goto LAB_0021c5e0;
  }
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  pIVar1 = vgui2::localize();
  __s = VGUI2_Find_String::lexical_block_0::tmpString;
  (**(code **)(*(int *)pIVar1 + 0x14))
            (pIVar1,psz,VGUI2_Find_String::lexical_block_0::tmpString,0x1000);
LAB_0021c5e0:
  iVar5 = 0;
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
                    /* Unresolved local var: uint i@[???] */
  for (uVar4 = 0; sVar3 = wcslen(__s), uVar4 < sVar3; uVar4 = uVar4 + 1) {
    pIVar2 = vgui2::surface();
    (*(pIVar2->super_IBaseInterface)._vptr_IBaseInterface[0x40])
              (pIVar2,font,__s[uVar4],&local_28,&local_24,local_20);
    iVar5 = iVar5 + local_28 + local_24 + local_20[0];
  }
  return iVar5;
}


// VGUI2_Draw_StringLenW  @ 0021c670
int VGUI2_Draw_StringLenW(wchar_t *wsz,uint font)

{
  wchar_t *pwVar1;
  ISurface *pIVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int totalWidth@[???]
                       Unresolved local var: uint i@[???] */
  iVar5 = 0;
  uVar4 = 0;
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
  while( true ) {
    sVar3 = wcslen(wsz);
    if (sVar3 <= uVar4) break;
    pIVar2 = vgui2::surface();
    pwVar1 = wsz + uVar4;
    uVar4 = uVar4 + 1;
    (*(pIVar2->super_IBaseInterface)._vptr_IBaseInterface[0x40])
              (pIVar2,font,*pwVar1,&local_28,&local_24,local_20);
    iVar5 = iVar5 + local_28 + local_24 + local_20[0];
  }
  return iVar5;
}


// VGUI2_Find_String  @ 0021c760
wchar_t * VGUI2_Find_String(char *str)

{
  ILocalize *pIVar1;
  wchar_t *pwVar2;
  
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  if ((str != (char *)0x0) && (*str == '#')) {
    pIVar1 = vgui2::localize();
    pwVar2 = (wchar_t *)(**(code **)(*(int *)pIVar1 + 0x10))(pIVar1,str);
    if (pwVar2 != (wchar_t *)0x0) {
      return pwVar2;
    }
  }
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  pIVar1 = vgui2::localize();
  (**(code **)(*(int *)pIVar1 + 0x14))
            (pIVar1,str,VGUI2_Find_String::lexical_block_0::tmpString,0x1000);
  return VGUI2_Find_String::lexical_block_0::tmpString;
}


// VGUI2_GetConsoleFont  @ 0021bf70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint VGUI2_GetConsoleFont(void)

{
  return _consoleFont;
}


// VGUI2_GetCreditsFont  @ 0021bf80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint VGUI2_GetCreditsFont(void)

{
  return _creditsFont;
}


// VGUI2_GetFontTall  @ 0021c6f0
int VGUI2_GetFontTall(uint font)

{
  ISurface *pIVar1;
  int iVar2;
  
                    /* Unresolved local var: wchar_t ch@[???] */
  pIVar1 = vgui2::surface();
  iVar2 = (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x3f])(pIVar1,font);
  return iVar2;
}


// VGUI2_GetFontWide  @ 0021c710
int VGUI2_GetFontWide(wchar_t ch,uint font)

{
  ISurface *pIVar1;
  int local_18;
  int local_14;
  int local_10 [4];
  
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x40])
            (pIVar1,font,ch,&local_18,&local_14,local_10);
  return local_18 + local_14 + local_10[0];
}


// VGUI2_MessageFontInfo  @ 0021c7c0
int VGUI2_MessageFontInfo(short *pWidth,uint font)

{
  ISurface *pIVar1;
  int iVar2;
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [16];
  
                    /* Unresolved local var: int i@[???] */
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xe])(pIVar1,font);
  if (pWidth != (short *)0x0) {
    iVar2 = 0;
    do {
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
      pIVar1 = vgui2::surface();
      (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x40])
                (pIVar1,font,iVar2,local_28,local_24,local_20);
      pWidth[iVar2] = local_28._0_2_ + local_24._0_2_ + (short)local_20._0_4_;
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x100);
  }
                    /* Unresolved local var: wchar_t ch@[???] */
  pIVar1 = vgui2::surface();
  iVar2 = (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x3f])(pIVar1,font);
  return iVar2;
}


// VGUI2_OnDisconnectFromServer  @ 001f3af0
void VGUI2_OnDisconnectFromServer(int eLoginFailure)

{
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    (**(code **)(*(int *)staticGameUIFuncs + 0x58))(staticGameUIFuncs,eLoginFailure,&DAT_0029c4a3);
  }
  return;
}


// VGUI2_ResetCurrentTexture  @ 0021bf60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGUI2_ResetCurrentTexture(void)

{
  g_BaseUISurface.m_iCurrentTexture = 0;
  return;
}


