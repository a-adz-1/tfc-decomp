// Ghidra decompilation of functions from cl_dll/statusbar.cpp
// 9 functions, ordered by original source line

// __MsgFunc_StatusText  @ 0007b170  (line 29)

int __MsgFunc_StatusText(char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  char *__src;
  
                    /* Unresolved local var: int line@[???] */
  BEGIN_READ(pbuf,iSize);
  uVar1 = READ_BYTE();
  if (uVar1 < 4) {
    __src = READ_STRING();
    strncpy(gHUD.m_StatusBar.m_szStatusText[uVar1],__src,0x80);
    gHUD.m_StatusBar.super_CHudBase.m_iFlags = gHUD.m_StatusBar.super_CHudBase.m_iFlags | 1;
    gHUD.m_StatusBar.m_szStatusText[uVar1][0x7f] = '\0';
    gHUD.m_StatusBar.m_bReparseString = 1;
  }
  return 1;
}


// __MsgFunc_StatusValue  @ 0007b120  (line 30)

int __MsgFunc_StatusValue(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int index@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  if (iVar1 - 1U < 8) {
    iVar2 = READ_SHORT();
    gHUD.m_StatusBar.m_iStatusValues[iVar1] = iVar2;
    gHUD.m_StatusBar.m_bReparseString = 1;
  }
  return 1;
}


// CHudStatusBar::Init  @ 0007b1e0  (line 42)

/* DWARF original prototype: int Init(CHudStatusBar * this) */

int __thiscall CHudStatusBar::Init(CHudStatusBar *this)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  (*gEngfuncs.pfnHookUserMsg)("StatusText",__MsgFunc_StatusText);
  (*gEngfuncs.pfnHookUserMsg)("StatusValue",__MsgFunc_StatusValue);
  p_Var2 = (this->super_CHudBase)._vptr_CHudBase[6];
  if (p_Var2 == Reset) {
                    /* Unresolved local var: int i@[???] */
    piVar4 = this->m_iStatusValues;
    uVar5 = 0x20;
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 & 0xfffffffe;
    bVar7 = ((uint)piVar4 & 1) != 0;
    this->m_szStatusText[0][0] = '\0';
    this->m_szStatusText[1][0] = '\0';
    this->m_szStatusText[2][0] = '\0';
    if (bVar7) {
      *(undefined1 *)this->m_iStatusValues = 0;
      piVar4 = (int *)((int)this->m_iStatusValues + 1);
      uVar5 = 0x1f;
    }
    if (((uint)piVar4 & 2) != 0) {
      *(undefined2 *)piVar4 = 0;
      uVar5 = uVar5 - 2;
      piVar4 = (int *)((int)piVar4 + 2);
    }
    uVar6 = 0;
    do {
      *(undefined4 *)((int)piVar4 + uVar6) = 0;
      *(undefined4 *)((int)piVar4 + uVar6 + 4) = 0;
      uVar6 = uVar6 + 8;
    } while (uVar6 < (uVar5 & 0xfffffff8));
    puVar3 = (undefined4 *)((int)piVar4 + uVar6);
    if ((uVar5 & 4) != 0) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    if ((uVar5 & 2) != 0) {
      *(undefined2 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 2);
    }
    if (bVar7) {
      *(undefined1 *)puVar3 = 0;
    }
    this->m_pflNameColors[1] = g_ColorYellow;
    this->m_iStatusValues[0] = 1;
    this->m_pflNameColors[0] = g_ColorYellow;
    this->m_pflNameColors[2] = g_ColorYellow;
  }
  else {
    (*p_Var2)(this);
  }
  (*gEngfuncs.pfnRegisterVariable)("hud_centerid","0",1);
  return 1;
}


// CHudStatusBar::VidInit  @ 0007b010  (line 60)

/* DWARF original prototype: int VidInit(CHudStatusBar * this) */

int __thiscall CHudStatusBar::VidInit(CHudStatusBar *this)

{
  return 1;
}


// CHudStatusBar::Reset  @ 0007b020  (line 63)

/* DWARF original prototype: void Reset(CHudStatusBar * this) */

void __thiscall CHudStatusBar::Reset(CHudStatusBar *this)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  bool bVar6;
  
                    /* Unresolved local var: int i@[???] */
  uVar5 = 0x20;
  piVar4 = this->m_iStatusValues;
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 & 0xfffffffe;
  bVar6 = ((uint)piVar4 & 1) != 0;
  this->m_szStatusText[0][0] = '\0';
  this->m_szStatusText[1][0] = '\0';
  this->m_szStatusText[2][0] = '\0';
  if (bVar6) {
    piVar4 = (int *)((int)this->m_iStatusValues + 1);
    uVar5 = 0x1f;
    *(undefined1 *)this->m_iStatusValues = 0;
  }
  if (((uint)piVar4 & 2) != 0) {
    *(undefined2 *)piVar4 = 0;
    uVar5 = uVar5 - 2;
    piVar4 = (int *)((int)piVar4 + 2);
  }
  uVar2 = 0;
  do {
    *(undefined4 *)((int)piVar4 + uVar2) = 0;
    *(undefined4 *)((int)piVar4 + uVar2 + 4) = 0;
    uVar2 = uVar2 + 8;
  } while (uVar2 < (uVar5 & 0xfffffff8));
  puVar3 = (undefined4 *)((int)piVar4 + uVar2);
  if ((uVar5 & 4) != 0) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if ((uVar5 & 2) != 0) {
    *(undefined2 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 2);
  }
  if (bVar6) {
    *(undefined1 *)puVar3 = 0;
  }
  this->m_iStatusValues[0] = 1;
  this->m_pflNameColors[0] = g_ColorYellow;
  this->m_pflNameColors[1] = g_ColorYellow;
  this->m_pflNameColors[2] = g_ColorYellow;
  return;
}


// CHudStatusBar::ParseStatusString  @ 0007b360  (line 79)

/* DWARF original prototype: void ParseStatusString(CHudStatusBar * this, int line_num) */

void __thiscall CHudStatusBar::ParseStatusString(CHudStatusBar *this,int line_num)

{
  char (*pacVar1) [128];
  int clientIndex;
  char cVar2;
  uint uVar3;
  char (*pacVar4) [128];
  char *pcVar5;
  float *pfVar6;
  uint uVar7;
  char *__nptr;
  int in_GS_OFFSET;
  bool bVar8;
  char local_c0 [32];
  char local_a0 [4];
  int local_9c [35];
  
                    /* Unresolved local var: char[128] szBuffer@[???]
                       Unresolved local var: char * src@[???]
                       Unresolved local var: char * dst@[???]
                       Unresolved local var: char * src_start@[???]
                       Unresolved local var: char * dst_start@[???] */
  local_9c[0x1f] = *(int *)(in_GS_OFFSET + 0x14);
  uVar3 = 0;
  do {
    pcVar5 = local_a0 + uVar3;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    *(undefined4 *)((int)local_9c + uVar3) = 0;
    uVar3 = uVar3 + 8;
  } while (uVar3 < 0x80);
  CHudTextMessage::LocaliseTextString(this->m_szStatusText[line_num],local_a0,0x80);
  uVar3 = 0x80;
  pacVar1 = this->m_szStatusBar + line_num;
  bVar8 = ((uint)pacVar1 & 1) != 0;
  pacVar4 = pacVar1;
  if (bVar8) {
    this->m_szStatusBar[line_num][0] = '\0';
    pacVar4 = (char (*) [128])(this->m_szStatusBar[line_num] + 1);
    uVar3 = 0x7f;
  }
  if (((uint)pacVar4 & 2) != 0) {
    *(char *)((int)pacVar4 + 0) = '\0';
    *(char *)((int)pacVar4 + 1) = '\0';
    uVar3 = uVar3 - 2;
    pacVar4 = (char (*) [128])(*pacVar4 + 2);
  }
  uVar7 = 0;
  do {
    pcVar5 = *pacVar4 + uVar7;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = *pacVar4 + uVar7 + 4;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    uVar7 = uVar7 + 8;
  } while (uVar7 < (uVar3 & 0xfffffff8));
  pcVar5 = *pacVar4 + uVar7;
  if ((uVar3 & 4) != 0) {
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pcVar5 + 4;
  }
  if ((uVar3 & 2) != 0) {
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5 = pcVar5 + 2;
  }
  __nptr = local_a0;
  pacVar4 = pacVar1;
  if (bVar8) {
    *pcVar5 = '\0';
  }
LAB_0007b440:
  do {
    if (local_a0[0] == '\0') {
LAB_0007b4b9:
      if (local_9c[0x1f] == *(int *)(in_GS_OFFSET + 0x14)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
                    /* Unresolved local var: int index@[???] */
    while (local_a0[0] == '\n') {
      __nptr = __nptr + 1;
      local_a0[0] = *__nptr;
    }
    if ((0x7f < (int)__nptr - (int)local_a0) || (0x7f < (int)pacVar4 - (int)pacVar1))
    goto LAB_0007b4b9;
    uVar3 = strtol(__nptr,(char **)0x0,10);
    if ((uVar3 < 8) && (this->m_iStatusValues[uVar3] != 0)) {
      for (; local_a0[0] = *__nptr, (byte)(local_a0[0] - 0x30U) < 10; __nptr = __nptr + 1) {
      }
      if ((local_a0[0] != '\n') && (local_a0[0] != '\0')) {
        while (cVar2 = local_a0[0], local_a0[0] != '\n') {
          while( true ) {
            local_a0[0] = '\0';
            if (cVar2 == '\0') goto LAB_0007b440;
            if (cVar2 == '%') break;
            (*pacVar4)[0] = cVar2;
            __nptr = __nptr + 1;
            pacVar4 = (char (*) [128])(*pacVar4 + 1);
            cVar2 = *__nptr;
            if (cVar2 == '\n') {
              local_a0[0] = '\n';
              goto LAB_0007b440;
            }
          }
                    /* Unresolved local var: char valtype@[???] */
          cVar2 = __nptr[1];
          if (cVar2 == '%') {
            (*pacVar4)[0] = '%';
            __nptr = __nptr + 2;
            pacVar4 = (char (*) [128])(*pacVar4 + 1);
            local_a0[0] = *__nptr;
          }
          else {
            uVar3 = strtol(__nptr + 2,(char **)0x0,10);
            local_a0[0] = __nptr[2];
            __nptr = __nptr + 2;
            while ((byte)(local_a0[0] - 0x30U) < 10) {
              __nptr = __nptr + 1;
              local_a0[0] = *__nptr;
            }
            if (uVar3 < 8) {
                    /* Unresolved local var: int indexval@[???]
                       Unresolved local var: char[32] szRepString@[???] */
              clientIndex = this->m_iStatusValues[uVar3];
              if (cVar2 == 'i') {
                __sprintf_chk(local_c0,1,0x20,"%d",clientIndex);
                cVar2 = local_c0[0];
LAB_0007b64c:
                    /* Unresolved local var: char * cp@[???] */
                if ((cVar2 != '\0') && ((int)pacVar4 - (int)pacVar1 < 0x80)) {
                  pcVar5 = local_c0;
                  do {
                    (*pacVar4)[0] = cVar2;
                    pcVar5 = pcVar5 + 1;
                    pacVar4 = (char (*) [128])(*pacVar4 + 1);
                    cVar2 = *pcVar5;
                    if (cVar2 == '\0') break;
                  } while ((int)pacVar4 - (int)pacVar1 < 0x80);
                }
              }
              else if (cVar2 == 'p') {
                (*gEngfuncs.pfnGetPlayerInfo)(clientIndex,g_PlayerInfoList + clientIndex);
                if (g_PlayerInfoList[clientIndex].name == (char *)0x0) {
                  builtin_strncpy(local_c0,"******",7);
                  cVar2 = '*';
                }
                else {
                  strncpy(local_c0,g_PlayerInfoList[clientIndex].name,0x20);
                  pfVar6 = GetClientColor(clientIndex);
                  this->m_pflNameColors[line_num] = pfVar6;
                  cVar2 = local_c0[0];
                }
                goto LAB_0007b64c;
              }
              local_a0[0] = *__nptr;
            }
          }
        }
      }
    }
    else {
      local_a0[0] = *__nptr;
      if ((local_a0[0] != '\n') && (local_a0[0] != '\0')) {
        do {
          __nptr = __nptr + 1;
          local_a0[0] = *__nptr;
          if (local_a0[0] == '\0') goto LAB_0007b4b9;
        } while (local_a0[0] != '\n');
      }
    }
  } while( true );
}


// CHudStatusBar::Draw  @ 0007b6d0  (line 180)

/* DWARF original prototype: int Draw(CHudStatusBar * this, float fTime) */

int __thiscall CHudStatusBar::Draw(CHudStatusBar *this,float fTime)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  char (*pacVar7) [128];
  longdouble lVar8;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int Y_START@[???] */
  if (this->m_bReparseString != 0) {
    iVar2 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      this->m_pflNameColors[iVar2] = g_ColorYellow;
      iVar5 = iVar2 + 1;
      ParseStatusString(this,iVar2);
      iVar2 = iVar5;
    } while (iVar5 != 3);
    this->m_bReparseString = 0;
  }
                    /* Unresolved local var: int i@[???] */
  iVar5 = 0;
  iVar2 = gHUD.m_scrinfo.iHeight + -0x34;
  pacVar7 = this->m_szStatusBar;
  do {
                    /* Unresolved local var: int TextHeight@[???]
                       Unresolved local var: int TextWidth@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
    (*gEngfuncs.pfnDrawConsoleStringLen)(*pacVar7,local_20,&local_24);
    iVar3 = iVar2 - (local_24 * iVar5 + 4);
    if ((iVar5 == 2) &&
       (lVar8 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_centerid"), iVar1 = local_24,
       lVar8 != (longdouble)0)) {
      iVar6 = gHUD.m_scrinfo.iWidth - local_20[0];
      if (iVar6 < 2) {
        iVar6 = 2;
      }
      iVar6 = iVar6 >> 1;
      iVar3 = gHUD.m_scrinfo.iHeight / 2;
      lVar8 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("hud_centerid");
      pfVar4 = this->m_pflNameColors[2];
      iVar3 = (int)(lVar8 * (longdouble)iVar1 + (longdouble)iVar3);
      if (pfVar4 == (float *)0x0) {
        (*gEngfuncs.pfnDrawConsoleString)(iVar6,iVar3,*pacVar7);
        return 1;
      }
LAB_0007b761:
      (*gEngfuncs.pfnDrawSetTextColor)(*pfVar4,pfVar4[1],pfVar4[2]);
    }
    else {
      pfVar4 = this->m_pflNameColors[iVar5];
      iVar6 = 8;
      if (pfVar4 != (float *)0x0) goto LAB_0007b761;
    }
    iVar5 = iVar5 + 1;
    (*gEngfuncs.pfnDrawConsoleString)(iVar6,iVar3,*pacVar7);
    pacVar7 = pacVar7 + 1;
    if (iVar5 == 3) {
      return 1;
    }
  } while( true );
}


// CHudStatusBar::MsgFunc_StatusText  @ 0007b870  (line 231)

/* DWARF original prototype: int MsgFunc_StatusText(CHudStatusBar * this, char * pszName, int iSize,
   void * pbuf) */

int __thiscall
CHudStatusBar::MsgFunc_StatusText(CHudStatusBar *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  uint uVar2;
  char *__src;
  
                    /* Unresolved local var: int line@[???] */
  BEGIN_READ(pbuf,iSize);
  uVar2 = READ_BYTE();
  if (uVar2 < 4) {
    __src = READ_STRING();
    strncpy(this->m_szStatusText[uVar2],__src,0x80);
    this->m_szStatusText[uVar2][0x7f] = '\0';
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 | 1;
    this->m_bReparseString = 1;
  }
  return 1;
}


// CHudStatusBar::MsgFunc_StatusValue  @ 0007b8f0  (line 253)

/* DWARF original prototype: int MsgFunc_StatusValue(CHudStatusBar * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
CHudStatusBar::MsgFunc_StatusValue(CHudStatusBar *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int index@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  if (iVar1 - 1U < 8) {
    iVar2 = READ_SHORT();
    this->m_iStatusValues[iVar1] = iVar2;
    this->m_bReparseString = 1;
  }
  return 1;
}


