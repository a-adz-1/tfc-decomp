// Ghidra decompilation of functions from cl_dll/saytext.cpp
// 8 functions, ordered by original source line

// __MsgFunc_SayText  @ 0007a130  (line 49)

int __MsgFunc_SayText(char *pszName,int iSize,void *pbuf)

{
  char *__needle;
  bool bVar1;
  int clientIndex;
  char *__haystack;
  char *pcVar2;
  size_t sVar3;
  float *pfVar4;
  size_t __n;
  int line;
  
                    /* Unresolved local var: int client_index@[???] */
  __n = iSize - 1;
  BEGIN_READ(pbuf,iSize);
  clientIndex = READ_BYTE();
  __haystack = READ_STRING();
                    /* Unresolved local var: int i@[???] */
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar1 = TeamFortressViewport::AllowedToPrintText(gViewPort), !bVar1)) {
    (*gEngfuncs.pfnConsolePrint)(__haystack);
    return 1;
  }
  if (g_szLineBuffer[0][0] == '\0') {
    line = 0;
  }
  else if (g_szLineBuffer[1][0] == '\0') {
    line = 1;
  }
  else if (g_szLineBuffer[2][0] == '\0') {
    line = 2;
  }
  else if (g_szLineBuffer[3][0] == '\0') {
    line = 3;
  }
  else {
    if (g_szLineBuffer[4][0] != '\0') {
      while( true ) {
        (*gEngfuncs.pfnConsolePrint)(g_szLineBuffer[0]);
        g_szLineBuffer[5][0] = '\0';
        memmove(g_szLineBuffer,g_szLineBuffer + 1,0x500);
        memmove(g_pflNameColors,g_pflNameColors + 1,0x14);
        memmove(g_iNameLengths,g_iNameLengths + 1,0x14);
        g_szLineBuffer[4][0] = '\0';
        if (g_szLineBuffer[0][0] != ' ') break;
        g_szLineBuffer[0][0] = '\x02';
      }
    }
    line = 4;
  }
  g_iNameLengths[line] = 0;
  g_pflNameColors[line] = (float *)0x0;
  if ((*__haystack == '\x02') && (0 < clientIndex)) {
                    /* Unresolved local var: char * pName@[???] */
    (*gEngfuncs.pfnGetPlayerInfo)(clientIndex,g_PlayerInfoList + clientIndex);
    __needle = g_PlayerInfoList[clientIndex].name;
                    /* Unresolved local var: char * nameInString@[???] */
    if ((__needle != (char *)0x0) && (pcVar2 = strstr(__haystack,__needle), pcVar2 != (char *)0x0))
    {
      sVar3 = strlen(__needle);
      g_iNameLengths[line] = (int)(pcVar2 + (sVar3 - (int)__haystack));
      pfVar4 = GetClientColor(clientIndex);
      g_pflNameColors[line] = pfVar4;
    }
  }
  if ((int)__n < 0x100) {
    __n = 0x100;
  }
  strncpy(g_szLineBuffer[line],__haystack,__n);
  CHudSayText::EnsureTextFitsInOneLineAndWrapIfHaveTo(&gHUD.m_SayText,line);
  if (line == 0) {
    flScrollTime = (gHUD.m_SayText.m_HUD_saytext_time)->value + gHUD.m_flTime;
  }
  gHUD.m_SayText.super_CHudBase.m_iFlags = gHUD.m_SayText.super_CHudBase.m_iFlags | 1;
  (*gEngfuncs.pfnPlaySoundByName)("misc/talk.wav",1.0);
  Y_START = gHUD.m_scrinfo.iHeight + -0x3c + line_height * -7;
  return 1;
}


// CHudSayText::Init  @ 00079660  (line 52)

/* DWARF original prototype: int Init(CHudSayText * this) */

int __thiscall CHudSayText::Init(CHudSayText *this)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  uint uVar3;
  uint uVar4;
  cvar_s *pcVar5;
  int iVar6;
  char (*pacVar7) [256];
  byte bVar8;
  
  bVar8 = 0;
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  (*gEngfuncs.pfnHookUserMsg)("SayText",__MsgFunc_SayText);
  p_Var2 = (this->super_CHudBase)._vptr_CHudBase[7];
  if (p_Var2 == InitHUDData) {
    pacVar7 = g_szLineBuffer;
    for (iVar6 = 0x180; uVar4 = 0, iVar6 != 0; iVar6 = iVar6 + -1) {
      *(char *)((int)pacVar7 + 0) = '\0';
      *(char *)((int)pacVar7 + 1) = '\0';
      *(char *)((int)pacVar7 + 2) = '\0';
      *(char *)((int)pacVar7 + 3) = '\0';
      pacVar7 = (char (*) [256])((int)pacVar7 + ((uint)bVar8 * -2 + 1) * 4);
    }
    do {
      *(undefined4 *)((int)g_pflNameColors + uVar4) = 0;
      uVar3 = uVar4 + 8;
      *(undefined4 *)((int)g_pflNameColors + uVar4 + 4) = 0;
      uVar4 = uVar3;
    } while (uVar3 < 0x18);
    uVar4 = 0;
    do {
      *(undefined4 *)((int)g_iNameLengths + uVar4) = 0;
      uVar3 = uVar4 + 8;
      *(undefined4 *)((int)g_iNameLengths + uVar4 + 4) = 0;
      uVar4 = uVar3;
    } while (uVar3 < 0x18);
  }
  else {
    (*p_Var2)(this);
  }
  pcVar5 = (*gEngfuncs.pfnRegisterVariable)("hud_saytext","1",0);
  this->m_HUD_saytext = pcVar5;
  pcVar5 = (*gEngfuncs.pfnRegisterVariable)("hud_saytext_time","5",0);
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 2;
  this->m_HUD_saytext_time = pcVar5;
  return 1;
}


// CHudSayText::VidInit  @ 00079600  (line 78)

/* DWARF original prototype: int VidInit(CHudSayText * this) */

int __thiscall CHudSayText::VidInit(CHudSayText *this)

{
  return 1;
}


// ScrollTextUp  @ 00079a20  (line 82)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ScrollTextUp(void)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    (*gEngfuncs.pfnConsolePrint)(g_szLineBuffer[0]);
    g_szLineBuffer[5][0] = '\0';
    memmove(g_szLineBuffer,g_szLineBuffer + 1,0x500);
    memmove(g_pflNameColors,g_pflNameColors + 1,0x14);
    memmove(g_iNameLengths,g_iNameLengths + 1,0x14);
    g_szLineBuffer[4][0] = '\0';
    if (g_szLineBuffer[0][0] != ' ') break;
    g_szLineBuffer[0][0] = '\x02';
    iVar1 = iVar1 + 1;
  }
  return iVar1 + 1;
}


// CHudSayText::Draw  @ 00079740  (line 100)

/* DWARF original prototype: int Draw(CHudSayText * this, float flTime) */

int __thiscall CHudSayText::Draw(CHudSayText *this,float flTime)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  bool bVar7;
  size_t sVar8;
  int iVar9;
  uint uVar10;
  char (*pacVar11) [256];
  undefined1 *puVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int in_GS_OFFSET;
  
                    /* Unresolved local var: int y@[???] */
  iVar15 = Y_START;
  piVar13 = (int *)&stack0xffffffb4;
  iVar2 = *(int *)(in_GS_OFFSET + 0x14);
  if (((gViewPort == (TeamFortressViewport *)0x0) ||
      (bVar7 = TeamFortressViewport::AllowedToPrintText(gViewPort), puVar12 = &stack0xffffffb4,
      bVar7)) && (puVar12 = &stack0xffffffb4, this->m_HUD_saytext->value != 0.0)) {
    fVar6 = flTime + this->m_HUD_saytext_time->value;
    if (fVar6 < flScrollTime) {
      flScrollTime = fVar6;
    }
    if (flScrollTime <= flTime) {
      if (g_szLineBuffer[0][0] == '\0') {
        piVar1 = &(this->super_CHudBase).m_iFlags;
        *piVar1 = *piVar1 & 0xfffffffe;
      }
      else {
        while( true ) {
          flScrollTime = fVar6;
          (*gEngfuncs.pfnConsolePrint)(g_szLineBuffer[0]);
          g_szLineBuffer[5][0] = '\0';
          memmove(g_szLineBuffer,g_szLineBuffer + 1,0x500);
          memmove(g_pflNameColors,g_pflNameColors + 1,0x14);
          memmove(g_iNameLengths,g_iNameLengths + 1,0x14);
          g_szLineBuffer[4][0] = '\0';
          if (g_szLineBuffer[0][0] != ' ') break;
          g_szLineBuffer[0][0] = '\x02';
          fVar6 = flScrollTime;
        }
      }
    }
    pacVar11 = g_szLineBuffer;
    iVar14 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      if ((*pacVar11)[0] != '\0') {
        if (((*pacVar11)[0] == '\x02') &&
           (puVar3 = *(undefined4 **)((int)g_pflNameColors + iVar14), puVar3 != (undefined4 *)0x0))
        {
                    /* Unresolved local var: char * buf@[???] */
          *piVar13 = (int)pacVar11;
          piVar13[-1] = 0x797fd;
          sVar8 = strlen((char *)*piVar13);
                    /* Unresolved local var: int x@[???] */
          iVar5 = -(sVar8 + 0x1e & 0xfffffff0);
          uVar10 = (int)piVar13 + iVar5 + 0x1b & 0xfffffff0;
          iVar4 = *(int *)((int)g_iNameLengths + iVar14);
          if (iVar4 < 0x41) {
            *(int *)((int)piVar13 + iVar5 + 8) = iVar4;
            *(char (**) [256])((int)piVar13 + iVar5 + 4) = pacVar11;
            *(uint *)((int)piVar13 + iVar5) = uVar10;
            *(undefined4 *)((int)piVar13 + iVar5 + -4) = 0x79839;
            strncpy(*(char **)((int)piVar13 + iVar5),*(char **)((int)piVar13 + iVar5 + 4),
                    *(size_t *)((int)piVar13 + iVar5 + 8));
            iVar9 = 0x3f;
            if (iVar4 < 0x40) {
              iVar9 = iVar4;
            }
          }
          else {
            *(undefined4 *)((int)piVar13 + iVar5 + 8) = 0x40;
            *(char (**) [256])((int)piVar13 + iVar5 + 4) = pacVar11;
            *(uint *)((int)piVar13 + iVar5) = uVar10;
            *(undefined4 *)((int)piVar13 + iVar5 + -4) = 0x79960;
            strncpy(*(char **)((int)piVar13 + iVar5),*(char **)((int)piVar13 + iVar5 + 4),
                    *(size_t *)((int)piVar13 + iVar5 + 8));
            iVar9 = 0x3f;
          }
          *(undefined1 *)(uVar10 + iVar9) = 0;
          *(undefined4 *)((int)piVar13 + iVar5 + 8) = puVar3[2];
          *(undefined4 *)((int)piVar13 + iVar5 + 4) = puVar3[1];
          *(undefined4 *)((int)piVar13 + iVar5) = *puVar3;
          *(undefined4 *)((int)piVar13 + iVar5 + -4) = 0x79876;
          (*gEngfuncs.pfnDrawSetTextColor)
                    (*(float *)((int)piVar13 + iVar5),*(float *)((int)piVar13 + iVar5 + 4),
                     *(float *)((int)piVar13 + iVar5 + 8));
          *(int *)((int)piVar13 + iVar5 + 4) = iVar15;
          *(undefined4 *)((int)piVar13 + iVar5) = 10;
          *(uint *)((int)piVar13 + iVar5 + 8) = uVar10 + 1;
          *(undefined4 *)((int)piVar13 + iVar5 + -4) = 0x79891;
          iVar9 = (*gEngfuncs.pfnDrawConsoleString)
                            (*(int *)((int)piVar13 + iVar5),*(int *)((int)piVar13 + iVar5 + 4),
                             *(char **)((int)piVar13 + iVar5 + 8));
          *(char (**) [256])((int)piVar13 + iVar5) = pacVar11;
          *(undefined4 *)((int)piVar13 + iVar5 + -4) = 0x7989c;
          sVar8 = strlen(*(char **)((int)piVar13 + iVar5));
          iVar4 = *(int *)((int)g_iNameLengths + iVar14);
          *(uint *)((int)piVar13 + iVar5) = uVar10;
          *(char **)((int)piVar13 + iVar5 + 4) = *pacVar11 + iVar4;
          *(size_t *)((int)piVar13 + iVar5 + 8) = sVar8;
          *(undefined4 *)((int)piVar13 + iVar5 + -4) = 0x798ba;
          strncpy(*(char **)((int)piVar13 + iVar5),*(char **)((int)piVar13 + iVar5 + 4),
                  *(size_t *)((int)piVar13 + iVar5 + 8));
          *(char **)((int)piVar13 + iVar5) = *pacVar11 + iVar4;
          *(undefined4 *)((int)piVar13 + iVar5 + -4) = 0x798c5;
          sVar8 = strlen(*(char **)((int)piVar13 + iVar5));
          *(undefined1 *)((uVar10 - 1) + sVar8) = 0;
          *(uint *)((int)piVar13 + iVar5 + 8) = uVar10;
          *(int *)((int)piVar13 + iVar5 + 4) = iVar15;
          *(int *)((int)piVar13 + iVar5) = iVar9;
          *(undefined4 *)((int)piVar13 + iVar5 + -4) = 0x798e1;
          (*gEngfuncs.pfnDrawConsoleString)
                    (*(int *)((int)piVar13 + iVar5),*(int *)((int)piVar13 + iVar5 + 4),
                     *(char **)((int)piVar13 + iVar5 + 8));
          piVar13 = (int *)((int)piVar13 + iVar5);
        }
        else {
          piVar13[2] = (int)pacVar11;
          piVar13[1] = iVar15;
          *piVar13 = 10;
          piVar13[-1] = 0x79925;
          (*gEngfuncs.pfnDrawConsoleString)(*piVar13,piVar13[1],(char *)piVar13[2]);
        }
      }
      iVar14 = iVar14 + 4;
      pacVar11 = pacVar11 + 1;
      iVar15 = iVar15 + line_height;
      puVar12 = (undefined1 *)piVar13;
    } while (iVar14 != 0x14);
  }
  if (iVar2 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar12 + -4) = &UNK_00079a13;
  __stack_chk_fail();
}


// CHudSayText::MsgFunc_SayText  @ 0007a3e0  (line 167)

/* DWARF original prototype: int MsgFunc_SayText(CHudSayText * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudSayText::MsgFunc_SayText(CHudSayText *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  char *__needle;
  bool bVar2;
  int clientIndex;
  char *__haystack;
  char *pcVar3;
  size_t sVar4;
  float *pfVar5;
  size_t __n;
  int line;
  
                    /* Unresolved local var: int client_index@[???] */
  __n = iSize - 1;
  BEGIN_READ(pbuf,iSize);
  clientIndex = READ_BYTE();
  __haystack = READ_STRING();
                    /* Unresolved local var: int i@[???] */
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar2 = TeamFortressViewport::AllowedToPrintText(gViewPort), !bVar2)) {
    (*gEngfuncs.pfnConsolePrint)(__haystack);
    return 1;
  }
  if (g_szLineBuffer[0][0] == '\0') {
    line = 0;
  }
  else if (g_szLineBuffer[1][0] == '\0') {
    line = 1;
  }
  else if (g_szLineBuffer[2][0] == '\0') {
    line = 2;
  }
  else if (g_szLineBuffer[3][0] == '\0') {
    line = 3;
  }
  else {
    if (g_szLineBuffer[4][0] != '\0') {
      while( true ) {
        (*gEngfuncs.pfnConsolePrint)(g_szLineBuffer[0]);
        g_szLineBuffer[5][0] = '\0';
        memmove(g_szLineBuffer,g_szLineBuffer + 1,0x500);
        memmove(g_pflNameColors,g_pflNameColors + 1,0x14);
        memmove(g_iNameLengths,g_iNameLengths + 1,0x14);
        g_szLineBuffer[4][0] = '\0';
        if (g_szLineBuffer[0][0] != ' ') break;
        g_szLineBuffer[0][0] = '\x02';
      }
    }
    line = 4;
  }
  g_iNameLengths[line] = 0;
  g_pflNameColors[line] = (float *)0x0;
  if ((*__haystack == '\x02') && (0 < clientIndex)) {
                    /* Unresolved local var: char * pName@[???] */
    (*gEngfuncs.pfnGetPlayerInfo)(clientIndex,g_PlayerInfoList + clientIndex);
    __needle = g_PlayerInfoList[clientIndex].name;
                    /* Unresolved local var: char * nameInString@[???] */
    if ((__needle != (char *)0x0) && (pcVar3 = strstr(__haystack,__needle), pcVar3 != (char *)0x0))
    {
      sVar4 = strlen(__needle);
      g_iNameLengths[line] = (int)(pcVar3 + (sVar4 - (int)__haystack));
      pfVar5 = GetClientColor(clientIndex);
      g_pflNameColors[line] = pfVar5;
    }
  }
  if ((int)__n < 0x100) {
    __n = 0x100;
  }
  strncpy(g_szLineBuffer[line],__haystack,__n);
  EnsureTextFitsInOneLineAndWrapIfHaveTo(this,line);
  if (line == 0) {
    flScrollTime = this->m_HUD_saytext_time->value + gHUD.m_flTime;
  }
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  (*gEngfuncs.pfnPlaySoundByName)("misc/talk.wav",1.0);
  Y_START = gHUD.m_scrinfo.iHeight + -0x3c + line_height * -7;
  return 1;
}


// CHudSayText::SayTextPrint  @ 00079ea0  (line 177)

/* DWARF original prototype: void SayTextPrint(CHudSayText * this, char * pszBuf, int iBufSize, int
   clientIndex) */

void __thiscall
CHudSayText::SayTextPrint(CHudSayText *this,char *pszBuf,int iBufSize,int clientIndex)

{
  int *piVar1;
  char *__needle;
  bool bVar2;
  char *pcVar3;
  size_t sVar4;
  float *pfVar5;
  int line;
  
                    /* Unresolved local var: int i@[???] */
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar2 = TeamFortressViewport::AllowedToPrintText(gViewPort), !bVar2)) {
                    /* WARNING: Could not recover jumptable at 0x0007a0eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEngfuncs.pfnConsolePrint)(pszBuf);
    return;
  }
  if (g_szLineBuffer[0][0] == '\0') {
    line = 0;
  }
  else if (g_szLineBuffer[1][0] == '\0') {
    line = 1;
  }
  else if (g_szLineBuffer[2][0] == '\0') {
    line = 2;
  }
  else if (g_szLineBuffer[3][0] == '\0') {
    line = 3;
  }
  else {
    if (g_szLineBuffer[4][0] != '\0') {
      while( true ) {
        (*gEngfuncs.pfnConsolePrint)(g_szLineBuffer[0]);
        g_szLineBuffer[5][0] = '\0';
        memmove(g_szLineBuffer,g_szLineBuffer + 1,0x500);
        memmove(g_pflNameColors,g_pflNameColors + 1,0x14);
        memmove(g_iNameLengths,g_iNameLengths + 1,0x14);
        g_szLineBuffer[4][0] = '\0';
        if (g_szLineBuffer[0][0] != ' ') break;
        g_szLineBuffer[0][0] = '\x02';
      }
    }
    line = 4;
  }
  g_iNameLengths[line] = 0;
  g_pflNameColors[line] = (float *)0x0;
  if ((*pszBuf == '\x02') && (0 < clientIndex)) {
                    /* Unresolved local var: char * pName@[???] */
    (*gEngfuncs.pfnGetPlayerInfo)(clientIndex,g_PlayerInfoList + clientIndex);
    __needle = g_PlayerInfoList[clientIndex].name;
                    /* Unresolved local var: char * nameInString@[???] */
    if ((__needle != (char *)0x0) && (pcVar3 = strstr(pszBuf,__needle), pcVar3 != (char *)0x0)) {
      sVar4 = strlen(__needle);
      g_iNameLengths[line] = (int)(pcVar3 + (sVar4 - (int)pszBuf));
      pfVar5 = GetClientColor(clientIndex);
      g_pflNameColors[line] = pfVar5;
    }
  }
  if (iBufSize < 0x100) {
    iBufSize = 0x100;
  }
  strncpy(g_szLineBuffer[line],pszBuf,iBufSize);
  EnsureTextFitsInOneLineAndWrapIfHaveTo(this,line);
  if (line == 0) {
    flScrollTime = this->m_HUD_saytext_time->value + gHUD.m_flTime;
  }
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  (*gEngfuncs.pfnPlaySoundByName)("misc/talk.wav",1.0);
  Y_START = gHUD.m_scrinfo.iHeight + -0x3c + line_height * -7;
  return;
}


// CHudSayText::EnsureTextFitsInOneLineAndWrapIfHaveTo  @ 00079ad0  (line 238)

/* DWARF original prototype: void EnsureTextFitsInOneLineAndWrapIfHaveTo(CHudSayText * this, int
   line) */

void __thiscall CHudSayText::EnsureTextFitsInOneLineAndWrapIfHaveTo(CHudSayText *this,int line)

{
  undefined2 uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  size_t sVar5;
  int iVar6;
  char *__s;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  byte bVar11;
  char local_26;
  undefined1 local_25;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int line_width@[???] */
  bVar11 = 0;
  local_24 = 0;
  pcVar8 = g_szLineBuffer[line];
  (*gEngfuncs.pfnDrawConsoleStringLen)(pcVar8,&local_24,&line_height);
  if (gHUD.m_scrinfo.iWidth + -0x28 <= local_24 + 9) {
                    /* Unresolved local var: int length@[???]
                       Unresolved local var: int tmp_len@[???]
                       Unresolved local var: char * last_break@[???] */
    local_20[0] = 0;
                    /* Unresolved local var: char * x@[???] */
    local_26 = g_szLineBuffer[line][0];
    if (local_26 != '\0') {
      __s = (char *)0x0;
      iVar7 = 10;
                    /* Unresolved local var: char[2] buf@[???] */
      pcVar9 = pcVar8;
      do {
        if (local_26 == '/') {
          if (pcVar9[1] == '(') {
            cVar2 = pcVar9[2];
            pcVar9 = pcVar9 + 2;
            if ((cVar2 != ')') && (cVar2 != '\0')) {
              do {
                pcVar9 = pcVar9 + 1;
                cVar2 = *pcVar9;
                if (cVar2 == '\0') break;
              } while (cVar2 != ')');
            }
            if (cVar2 == '\0') {
              return;
            }
            local_26 = pcVar9[1];
            pcVar9 = pcVar9 + 1;
            if (local_26 == '\0') {
              return;
            }
            goto LAB_00079b48;
          }
        }
        else {
LAB_00079b48:
          if ((local_26 == ' ') && (pcVar9 != pcVar8)) {
            __s = pcVar9;
          }
        }
        local_25 = 0;
        (*gEngfuncs.pfnDrawConsoleStringLen)(&local_26,local_20,&line_height);
        iVar7 = iVar7 + local_20[0];
        if (gHUD.m_scrinfo.iWidth + -0x27 <= iVar7) {
                    /* Unresolved local var: int j@[???] */
          if (__s == (char *)0x0) {
            __s = pcVar9 + -1;
          }
          if (g_szLineBuffer[0][0] == '\0') goto LAB_00079d90;
          if (g_szLineBuffer[1][0] == '\0') goto LAB_00079e10;
          if (g_szLineBuffer[2][0] == '\0') goto LAB_00079e20;
          if (g_szLineBuffer[3][0] == '\0') {
            iVar7 = 3;
            goto LAB_00079d02;
          }
          if (g_szLineBuffer[4][0] != '\0') {
            iVar7 = 0;
            while( true ) {
              (*gEngfuncs.pfnConsolePrint)(g_szLineBuffer[0]);
              g_szLineBuffer[5][0] = '\0';
              memmove(g_szLineBuffer,g_szLineBuffer + 1,0x500);
              memmove(g_pflNameColors,g_pflNameColors + 1,0x14);
              memmove(g_iNameLengths,g_iNameLengths + 1,0x14);
              g_szLineBuffer[4][0] = '\0';
              if (g_szLineBuffer[0][0] != ' ') break;
                    /* Unresolved local var: int linesmoved@[???] */
              g_szLineBuffer[0][0] = '\x02';
              iVar7 = iVar7 + 1;
            }
            __s = __s + (iVar7 + 1) * -0x100;
            if (g_szLineBuffer[0][0] == '\0') {
LAB_00079d90:
              iVar7 = 0;
              cVar2 = *__s;
            }
            else {
              if (g_szLineBuffer[1][0] == '\0') {
LAB_00079e10:
                iVar7 = 1;
              }
              else if (g_szLineBuffer[2][0] == '\0') {
LAB_00079e20:
                iVar7 = 2;
              }
              else {
                iVar7 = 4 - (uint)(g_szLineBuffer[3][0] == '\0');
              }
LAB_00079d02:
              cVar2 = *__s;
            }
            if (cVar2 == ' ') {
                    /* Unresolved local var: int linelen@[???]
                       Unresolved local var: int remaininglen@[???] */
              pcVar9 = g_szLineBuffer[iVar7];
              pcVar8 = pcVar9;
              do {
                pcVar10 = pcVar8;
                uVar3 = *(uint *)pcVar10 + 0xfefefeff & ~*(uint *)pcVar10;
                uVar4 = uVar3 & 0x80808080;
                pcVar8 = pcVar10 + 4;
              } while (uVar4 == 0);
              if ((uVar3 & 0x8080) == 0) {
                pcVar8 = pcVar10 + 6;
                uVar4 = uVar4 >> 0x10;
              }
              sVar5 = strlen(__s);
              if ((int)((int)(pcVar8 + ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)pcVar9))
                       - sVar5) < 0x101) {
                uVar3 = sVar5 + 1;
                pcVar9 = pcVar9 + (int)(pcVar8 + ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) -
                                                 (int)pcVar9));
                pcVar8 = __s;
                if (7 < uVar3) {
                  pcVar10 = pcVar9;
                  if (((uint)pcVar9 & 1) != 0) {
                    pcVar10 = pcVar9 + 1;
                    pcVar8 = __s + 1;
                    *pcVar9 = *__s;
                    uVar3 = sVar5;
                  }
                  pcVar9 = pcVar10;
                  if (((uint)pcVar10 & 2) != 0) {
                    uVar1 = *(undefined2 *)pcVar8;
                    pcVar9 = pcVar10 + 2;
                    pcVar8 = pcVar8 + 2;
                    uVar3 = uVar3 - 2;
                    *(undefined2 *)pcVar10 = uVar1;
                  }
                  if (((uint)pcVar9 & 4) != 0) {
                    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
                    pcVar8 = pcVar8 + 4;
                    pcVar9 = pcVar9 + 4;
                    for (iVar6 = uVar3 - 4; iVar6 != 0; iVar6 = iVar6 + -1) {
                      *pcVar9 = *pcVar8;
                      pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
                      pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
                    }
                    goto LAB_00079d73;
                  }
                }
                for (; uVar3 != 0; uVar3 = uVar3 - 1) {
                  *pcVar9 = *pcVar8;
                  pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
                  pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
                }
              }
            }
            else {
              pcVar9 = g_szLineBuffer[iVar7];
              pcVar8 = pcVar9;
              do {
                pcVar10 = pcVar8;
                uVar3 = *(uint *)pcVar10 + 0xfefefeff & ~*(uint *)pcVar10;
                uVar4 = uVar3 & 0x80808080;
                pcVar8 = pcVar10 + 4;
              } while (uVar4 == 0);
              if ((uVar3 & 0x8080) == 0) {
                pcVar8 = pcVar10 + 6;
                uVar4 = uVar4 >> 0x10;
              }
              sVar5 = strlen(__s);
              pcVar8 = pcVar8 + ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)pcVar9);
              if (pcVar8 + (-2 - sVar5) < (char *)0x100) {
                pcVar9[(int)pcVar8] = ' ';
                strcpy(pcVar8 + iVar7 * 0x100 + 0x108881,__s);
              }
            }
LAB_00079d73:
            *__s = '\0';
            EnsureTextFitsInOneLineAndWrapIfHaveTo(this,iVar7);
            return;
          }
          iVar7 = 4;
          goto LAB_00079d02;
        }
        local_26 = pcVar9[1];
        pcVar9 = pcVar9 + 1;
      } while (local_26 != '\0');
    }
  }
  return;
}


