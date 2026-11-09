// VGUI2_DrawString  @ 001d1040
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
  
                    /* Unresolved local var: wchar_t * localizedString@[???]
                       Unresolved local var: wchar_t * fixString@[DW_OP_reg3(EBX)] */
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x19])
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
    if (__s != (wchar_t *)0x0) goto LAB_001d10d8;
  }
  pIVar2 = vgui2::localize();
  __s = VGUI2_Find_String::tmpString;
  (**(code **)(*(int *)pIVar2 + 0x14))(pIVar2,str,VGUI2_Find_String::tmpString,0x1000);
LAB_001d10d8:
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
                    /* Unresolved local var: int totalWidth@[???] */
  iVar4 = 0;
                    /* Unresolved local var: uint i@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
  sVar3 = wcslen(__s);
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x13])(pIVar1,__s,sVar3);
  pIVar1 = vgui2::surface();
  (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x16])(pIVar1);
  for (uVar5 = 0; sVar3 = wcslen(__s), uVar5 < sVar3; uVar5 = uVar5 + 1) {
    pIVar1 = vgui2::surface();
    (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x40])
              (pIVar1,font,__s[uVar5],&local_28,&local_24,local_20);
    iVar4 = iVar4 + local_24 + local_28 + local_20[0];
  }
  return iVar4;
}


// VGUI2_DrawStringClient  @ 001d11d0
int VGUI2_DrawStringClient(int x,int y,char *str,int r,int g,int b)

{
  ILocalize *pIVar1;
  int iVar2;
  size_t sVar3;
  int x_00;
  uint uVar4;
  wchar_t *__s;
  
                    /* Unresolved local var: wchar_t * localizedString@[DW_OP_reg7(EDI)]
                       Unresolved local var: int xpos@[???] */
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x19])
            (g_BaseUISurface._engineSurface);
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  if ((str != (char *)0x0) && (*str == '#')) {
    pIVar1 = vgui2::localize();
    __s = (wchar_t *)(**(code **)(*(int *)pIVar1 + 0x10))(pIVar1,str);
    if (__s != (wchar_t *)0x0) goto LAB_001d1221;
  }
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  pIVar1 = vgui2::localize();
  __s = VGUI2_Find_String::tmpString;
  (**(code **)(*(int *)pIVar1 + 0x14))(pIVar1,str,VGUI2_Find_String::tmpString,0x1000);
LAB_001d1221:
  x_00 = x;
                    /* Unresolved local var: uint i@[???] */
  for (uVar4 = 0; sVar3 = wcslen(__s), uVar4 < sVar3; uVar4 = uVar4 + 1) {
                    /* Unresolved local var: int next@[???] */
    iVar2 = VGUI2_Draw_CharacterAdd(x_00,y,__s[uVar4],r,g,b,_creditsFont);
    x_00 = x_00 + iVar2;
  }
  return x_00 - x;
}


// VGUI2_DrawStringReverseClient  @ 001d12b0
int VGUI2_DrawStringReverseClient(int x,int y,char *str,int r,int g,int b)

{
  ILocalize *pIVar1;
  size_t sVar2;
  ISurface *pIVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  int iVar6;
  wchar_t *__s;
  int x_00;
  int local_30;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: wchar_t * localizedString@[DW_OP_reg6(ESI)]
                       Unresolved local var: int len@[???]
                       Unresolved local var: wchar_t * szIt@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int z@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int safe_index@[???]
                       Unresolved local var: int xpos@[???] */
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x19])
            (g_BaseUISurface._engineSurface);
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  if ((str != (char *)0x0) && (*str == '#')) {
    pIVar1 = vgui2::localize();
    __s = (wchar_t *)(**(code **)(*(int *)pIVar1 + 0x10))(pIVar1,str);
    if (__s != (wchar_t *)0x0) goto LAB_001d1301;
  }
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  pIVar1 = vgui2::localize();
  __s = VGUI2_Find_String::tmpString;
  (**(code **)(*(int *)pIVar1 + 0x14))(pIVar1,str,VGUI2_Find_String::tmpString,0x1000);
LAB_001d1301:
  sVar2 = wcslen(__s);
  if (sVar2 < 0x80000000) {
    if (sVar2 == 0) {
      return x;
    }
    if (sVar2 - 2 == -1) {
      local_30 = sVar2 * 4 + -4;
      iVar6 = 0;
    }
    else {
      local_30 = sVar2 * 4 + -4;
      iVar6 = (sVar2 - 2) * 4;
    }
  }
  else {
    iVar6 = -0xc;
    local_30 = -8;
  }
  pIVar3 = vgui2::surface();
  (*(pIVar3->super_IBaseInterface)._vptr_IBaseInterface[0x40])
            (pIVar3,_creditsFont,*(undefined4 *)((int)__s + iVar6),&local_28,&local_24,local_20);
  iVar6 = local_24 + local_28 + local_20[0];
  pwVar4 = (wchar_t *)(local_30 + (int)__s);
  x_00 = x - iVar6;
  if (pwVar4 != __s + -1) {
    do {
                    /* Unresolved local var: int next@[???] */
      pwVar5 = pwVar4 + -1;
      iVar6 = VGUI2_Draw_CharacterAdd(x_00,y,*pwVar4,r,g,b,_creditsFont);
      x_00 = x_00 - iVar6;
      pwVar4 = pwVar5;
    } while (pwVar5 != __s + -1);
    iVar6 = local_24 + local_28 + local_20[0];
  }
  return iVar6 + (x - x_00);
}


// VGUI2_Draw_Character  @ 001d0e70
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
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x19])
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
  return local_14 + local_18 + local_10[0];
}


// VGUI2_Draw_CharacterAdd  @ 001d0f40
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
  (*((g_BaseUISurface._engineSurface)->super_IBaseInterface)._vptr_IBaseInterface[0x19])
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
  return local_14 + local_18 + local_10[0];
}


// VGUI2_Draw_Init  @ 001d0d50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGUI2_Draw_Init(void)

{
  code *pcVar1;
  ISchemeManager *pIVar2;
  ISchemeManager *pIVar3;
  undefined4 uVar4;
  int *piVar5;
  char *__nptr;
  long lVar6;
  
                    /* Unresolved local var: IScheme * pScheme@[???] */
  pIVar2 = vgui2::scheme();
  pcVar1 = *(code **)(*(int *)pIVar2 + 0x20);
  pIVar3 = vgui2::scheme();
  uVar4 = (**(code **)(*(int *)pIVar3 + 0x10))(pIVar3);
  piVar5 = (int *)(*pcVar1)(pIVar2,uVar4);
  if (_consoleFont == 0) {
    _consoleFont = (**(code **)(*piVar5 + 0x10))(piVar5,"EngineFont",1);
  }
  if (_creditsFont != 0) {
    return;
  }
  __nptr = (char *)(**(code **)(*piVar5 + 8))(piVar5,"UseScaledCreditsFont");
  lVar6 = strtol(__nptr,(char **)0x0,10);
  if (lVar6 == 0) {
    _creditsFont = (**(code **)(*piVar5 + 0x10))(piVar5,"Legacy_CreditsFont");
    return;
  }
  _creditsFont = (**(code **)(*piVar5 + 0x10))(piVar5,"CreditsFont",1);
  return;
}


// VGUI2_Draw_SetTextColor  @ 001d1470
void VGUI2_Draw_SetTextColor(int r,int g,int b)

{
  _col._color[3] = 0xff;
  _col._color[0] = (uchar)r;
  _col._color[1] = (uchar)g;
  _col._color[2] = (uchar)b;
  return;
}


// VGUI2_Draw_SetTextColorAlpha  @ 001d14a0
void VGUI2_Draw_SetTextColorAlpha(int r,int g,int b,int a)

{
  _col._color[0] = (uchar)r;
  _col._color[1] = (uchar)g;
  _col._color[2] = (uchar)b;
  _col._color[3] = (uchar)a;
  return;
}


// VGUI2_Draw_StringLen  @ 001d14d0
int VGUI2_Draw_StringLen(char *psz,uint font)

{
  ILocalize *pIVar1;
  ISurface *pIVar2;
  size_t sVar3;
  uint uVar4;
  wchar_t *__s;
  int iVar5;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: wchar_t * localizedString@[DW_OP_reg6(ESI)]
                       Unresolved local var: int totalWidth@[???] */
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  if ((psz != (char *)0x0) && (*psz == '#')) {
    pIVar1 = vgui2::localize();
    __s = (wchar_t *)(**(code **)(*(int *)pIVar1 + 0x10))(pIVar1,psz);
    if (__s != (wchar_t *)0x0) goto LAB_001d1510;
  }
                    /* Unresolved local var: wchar_t * localizedString@[???] */
  pIVar1 = vgui2::localize();
  __s = VGUI2_Find_String::tmpString;
  (**(code **)(*(int *)pIVar1 + 0x14))(pIVar1,psz,VGUI2_Find_String::tmpString,0x1000);
LAB_001d1510:
  iVar5 = 0;
                    /* Unresolved local var: int a@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int c@[???] */
                    /* Unresolved local var: uint i@[???] */
  for (uVar4 = 0; sVar3 = wcslen(__s), uVar4 < sVar3; uVar4 = uVar4 + 1) {
    pIVar2 = vgui2::surface();
    (*(pIVar2->super_IBaseInterface)._vptr_IBaseInterface[0x40])
              (pIVar2,font,__s[uVar4],&local_28,&local_24,local_20);
    iVar5 = iVar5 + local_24 + local_28 + local_20[0];
  }
  return iVar5;
}


// VGUI2_Draw_StringLenW  @ 001d15a0
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
  
                    /* Unresolved local var: int totalWidth@[???] */
  iVar5 = 0;
                    /* Unresolved local var: uint i@[???] */
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
    iVar5 = iVar5 + local_24 + local_28 + local_20[0];
  }
  return iVar5;
}


// VGUI2_Find_String  @ 001d1690
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
  (**(code **)(*(int *)pIVar1 + 0x14))(pIVar1,str,VGUI2_Find_String::tmpString,0x1000);
  return VGUI2_Find_String::tmpString;
}


// VGUI2_GetConsoleFont  @ 001d0e50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint VGUI2_GetConsoleFont(void)

{
  return _consoleFont;
}


// VGUI2_GetCreditsFont  @ 001d0e60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint VGUI2_GetCreditsFont(void)

{
  return _creditsFont;
}


// VGUI2_GetFontTall  @ 001d1620
int VGUI2_GetFontTall(uint font)

{
  ISurface *pIVar1;
  int iVar2;
  
                    /* Unresolved local var: wchar_t ch@[???] */
  pIVar1 = vgui2::surface();
  iVar2 = (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x3f])(pIVar1,font);
  return iVar2;
}


// VGUI2_GetFontWide  @ 001d1640
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
  return local_14 + local_18 + local_10[0];
}


// VGUI2_MessageFontInfo  @ 001d16f0
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
      pWidth[iVar2] = local_24._0_2_ + local_28._0_2_ + (short)local_20._0_4_;
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x100);
  }
                    /* Unresolved local var: wchar_t ch@[???] */
  pIVar1 = vgui2::surface();
  iVar2 = (*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0x3f])(pIVar1,font);
  return iVar2;
}


// VGUI2_OnDisconnectFromServer  @ 001a44d0
void VGUI2_OnDisconnectFromServer(int eLoginFailure)

{
  if (staticGameUIFuncs != (IGameUI *)0x0) {
    (**(code **)(*(int *)staticGameUIFuncs + 0x58))(staticGameUIFuncs,eLoginFailure,&DAT_0027abd7);
  }
  return;
}


// VGUI2_ResetCurrentTexture  @ 001d0e40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void VGUI2_ResetCurrentTexture(void)

{
  g_BaseUISurface.m_iCurrentTexture = 0;
  return;
}


