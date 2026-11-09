// Ghidra decompilation of functions from cl_dll/status_icons.cpp
// 8 functions, ordered by original source line

// __MsgFunc_StatusIcon  @ 0007adc0  (line 28)

int __MsgFunc_StatusIcon(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  char *pszIconName;
  int iVar2;
  int iVar3;
  uint uVar4;
  
                    /* Unresolved local var: int ShouldEnable@[???]
                       Unresolved local var: char * pszIconName@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  pszIconName = READ_STRING();
  if (iVar1 != 0) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???] */
    iVar1 = READ_BYTE();
    iVar2 = READ_BYTE();
    iVar3 = READ_BYTE();
    CHudStatusIcons::EnableIcon
              (&gHUD.m_StatusIcons,pszIconName,(uchar)iVar1,(uchar)iVar2,(uchar)iVar3);
    gHUD.m_StatusIcons.super_CHudBase.m_iFlags = gHUD.m_StatusIcons.super_CHudBase.m_iFlags | 1;
    return 1;
  }
                    /* Unresolved local var: int i@[???] */
  iVar1 = strcasecmp(gHUD.m_StatusIcons.m_IconList[0].szSpriteName,pszIconName);
  if (iVar1 == 0) {
    iVar1 = 0xfaa64;
  }
  else {
    iVar1 = strcasecmp(gHUD.m_StatusIcons.m_IconList[1].szSpriteName,pszIconName);
    if (iVar1 == 0) {
      iVar1 = 0xfaa94;
    }
    else {
      iVar1 = strcasecmp(gHUD.m_StatusIcons.m_IconList[2].szSpriteName,pszIconName);
      if (iVar1 == 0) {
        iVar1 = 0xfaac4;
      }
      else {
        iVar2 = strcasecmp(gHUD.m_StatusIcons.m_IconList[3].szSpriteName,pszIconName);
        iVar1 = 0xfaaf4;
        if (iVar2 != 0) {
          return 1;
        }
      }
    }
  }
  uVar4 = 0;
  do {
    *(undefined4 *)(iVar1 + uVar4) = 0;
    *(undefined4 *)(iVar1 + 4 + uVar4) = 0;
    uVar4 = uVar4 + 8;
  } while (uVar4 < 0x30);
  return 1;
}


// CHudStatusIcons::Init  @ 0007a950  (line 31)

/* DWARF original prototype: int Init(CHudStatusIcons * this) */

int __thiscall CHudStatusIcons::Init(CHudStatusIcons *this)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  uint uVar3;
  uint uVar4;
  N15CHudStatusIcons13icon_sprite_tE *pNVar5;
  char *pcVar6;
  bool bVar7;
  
  (*gEngfuncs.pfnHookUserMsg)("StatusIcon",__MsgFunc_StatusIcon);
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  p_Var2 = (this->super_CHudBase)._vptr_CHudBase[6];
  if (p_Var2 == Reset) {
    pNVar5 = this->m_IconList;
    uVar4 = 0xc0;
    bVar7 = ((uint)pNVar5 & 1) != 0;
    if (bVar7) {
      this->m_IconList[0].szSpriteName[0] = '\0';
      pNVar5 = (N15CHudStatusIcons13icon_sprite_tE *)(this->m_IconList[0].szSpriteName + 1);
      uVar4 = 0xbf;
    }
    if (((uint)pNVar5 & 2) != 0) {
      pNVar5->szSpriteName[0] = '\0';
      pNVar5->szSpriteName[1] = '\0';
      uVar4 = uVar4 - 2;
      pNVar5 = (N15CHudStatusIcons13icon_sprite_tE *)(pNVar5->szSpriteName + 2);
    }
    uVar3 = 0;
    do {
      pcVar6 = pNVar5->szSpriteName + uVar3;
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      pcVar6 = pNVar5->szSpriteName + uVar3 + 4;
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      uVar3 = uVar3 + 8;
    } while (uVar3 < (uVar4 & 0xfffffff8));
    pcVar6 = pNVar5->szSpriteName + uVar3;
    if ((uVar4 & 4) != 0) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      pcVar6 = pcVar6 + 4;
    }
    if ((uVar4 & 2) != 0) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6 = pcVar6 + 2;
    }
    if (bVar7) {
      *pcVar6 = '\0';
    }
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 & 0xfffffffe;
  }
  else {
    (*p_Var2)(this);
  }
  return 1;
}


// CHudStatusIcons::VidInit  @ 0007a6b0  (line 45)

/* DWARF original prototype: int VidInit(CHudStatusIcons * this) */

int __thiscall CHudStatusIcons::VidInit(CHudStatusIcons *this)

{
  return 1;
}


// CHudStatusIcons::Reset  @ 0007a6c0  (line 48)

/* DWARF original prototype: void Reset(CHudStatusIcons * this) */

void __thiscall CHudStatusIcons::Reset(CHudStatusIcons *this)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  N15CHudStatusIcons13icon_sprite_tE *pNVar4;
  char *pcVar5;
  bool bVar6;
  
  uVar3 = 0xc0;
  pNVar4 = this->m_IconList;
  bVar6 = ((uint)pNVar4 & 1) != 0;
  if (bVar6) {
    pNVar4 = (N15CHudStatusIcons13icon_sprite_tE *)(this->m_IconList[0].szSpriteName + 1);
    uVar3 = 0xbf;
    this->m_IconList[0].szSpriteName[0] = '\0';
  }
  if (((uint)pNVar4 & 2) != 0) {
    pNVar4->szSpriteName[0] = '\0';
    pNVar4->szSpriteName[1] = '\0';
    uVar3 = uVar3 - 2;
    pNVar4 = (N15CHudStatusIcons13icon_sprite_tE *)(pNVar4->szSpriteName + 2);
  }
  uVar2 = 0;
  do {
    pcVar5 = pNVar4->szSpriteName + uVar2;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pNVar4->szSpriteName + uVar2 + 4;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    uVar2 = uVar2 + 8;
  } while (uVar2 < (uVar3 & 0xfffffff8));
  pcVar5 = pNVar4->szSpriteName + uVar2;
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
  if (bVar6) {
    *pcVar5 = '\0';
  }
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 & 0xfffffffe;
  return;
}


// CHudStatusIcons::Draw  @ 0007a760  (line 55)

/* DWARF original prototype: int Draw(CHudStatusIcons * this, float flTime) */

int __thiscall CHudStatusIcons::Draw(CHudStatusIcons *this,float flTime)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  iVar3 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar3 != 0) {
    return 1;
  }
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
                    /* Unresolved local var: int i@[???] */
  iVar3 = this->m_IconList[0].spr;
  iVar4 = gHUD.m_scrinfo.iHeight / 2;
  if (iVar3 == 0) {
    iVar3 = this->m_IconList[1].spr;
  }
  else {
    iVar4 = iVar4 - ((this->m_IconList[0].rc.bottom - this->m_IconList[0].rc.top) + 5);
    (*gEngfuncs.pfnSPR_Set)
              (iVar3,(uint)this->m_IconList[0].r,(uint)this->m_IconList[0].g,
               (uint)this->m_IconList[0].b);
    (*gEngfuncs.pfnSPR_DrawAdditive)(0,5,iVar4,&this->m_IconList[0].rc);
    iVar3 = this->m_IconList[1].spr;
  }
  if (iVar3 == 0) {
    iVar3 = this->m_IconList[2].spr;
  }
  else {
    iVar4 = iVar4 - ((this->m_IconList[1].rc.bottom - this->m_IconList[1].rc.top) + 5);
    (*gEngfuncs.pfnSPR_Set)
              (iVar3,(uint)this->m_IconList[1].r,(uint)this->m_IconList[1].g,
               (uint)this->m_IconList[1].b);
    (*gEngfuncs.pfnSPR_DrawAdditive)(0,5,iVar4,&this->m_IconList[1].rc);
    iVar3 = this->m_IconList[2].spr;
  }
  if (iVar3 == 0) {
    iVar3 = this->m_IconList[3].spr;
  }
  else {
    iVar4 = iVar4 - ((this->m_IconList[2].rc.bottom - this->m_IconList[2].rc.top) + 5);
    (*gEngfuncs.pfnSPR_Set)
              (iVar3,(uint)this->m_IconList[2].r,(uint)this->m_IconList[2].g,
               (uint)this->m_IconList[2].b);
    (*gEngfuncs.pfnSPR_DrawAdditive)(0,5,iVar4,&this->m_IconList[2].rc);
    iVar3 = this->m_IconList[3].spr;
  }
  if (iVar3 != 0) {
    iVar1 = this->m_IconList[3].rc.top;
    iVar2 = this->m_IconList[3].rc.bottom;
    (*gEngfuncs.pfnSPR_Set)
              (iVar3,(uint)this->m_IconList[3].r,(uint)this->m_IconList[3].g,
               (uint)this->m_IconList[3].b);
    (*gEngfuncs.pfnSPR_DrawAdditive)(0,5,iVar4 - ((iVar2 - iVar1) + 5),&this->m_IconList[3].rc);
    return 1;
  }
  return 1;
}


// CHudStatusIcons::MsgFunc_StatusIcon  @ 0007ac60  (line 85)

/* DWARF original prototype: int MsgFunc_StatusIcon(CHudStatusIcons * this, char * pszName, int
   iSize, void * pbuf) */

int __thiscall
CHudStatusIcons::MsgFunc_StatusIcon(CHudStatusIcons *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  N15CHudStatusIcons13icon_sprite_tE *__s1;
  bool bVar8;
  
                    /* Unresolved local var: int ShouldEnable@[???]
                       Unresolved local var: char * pszIconName@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  pcVar3 = READ_STRING();
  if (iVar2 == 0) {
                    /* Unresolved local var: int i@[???] */
    __s1 = this->m_IconList;
    iVar2 = strcasecmp(__s1->szSpriteName,pcVar3);
    if (iVar2 != 0) {
      __s1 = this->m_IconList + 1;
      iVar2 = strcasecmp(__s1->szSpriteName,pcVar3);
      if (iVar2 != 0) {
        __s1 = this->m_IconList + 2;
        iVar2 = strcasecmp(__s1->szSpriteName,pcVar3);
        if (iVar2 != 0) {
          __s1 = this->m_IconList + 3;
          iVar2 = strcasecmp(__s1->szSpriteName,pcVar3);
          if (iVar2 != 0) {
            return 1;
          }
        }
      }
    }
    bVar8 = ((uint)__s1 & 1) != 0;
    uVar7 = 0x30;
    if (bVar8) {
      __s1->szSpriteName[0] = '\0';
      uVar7 = 0x2f;
      __s1 = (N15CHudStatusIcons13icon_sprite_tE *)(__s1->szSpriteName + 1);
    }
    if (((uint)__s1 & 2) != 0) {
      __s1->szSpriteName[0] = '\0';
      __s1->szSpriteName[1] = '\0';
      uVar7 = uVar7 - 2;
      __s1 = (N15CHudStatusIcons13icon_sprite_tE *)(__s1->szSpriteName + 2);
    }
    uVar6 = 0;
    do {
      pcVar3 = __s1->szSpriteName + uVar6;
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = __s1->szSpriteName + uVar6 + 4;
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      uVar6 = uVar6 + 8;
    } while (uVar6 < (uVar7 & 0xfffffff8));
    pcVar3 = __s1->szSpriteName + uVar6;
    if ((uVar7 & 4) != 0) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = pcVar3 + 4;
    }
    if ((uVar7 & 2) != 0) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3 = pcVar3 + 2;
    }
    if (bVar8) {
      *pcVar3 = '\0';
    }
  }
  else {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???] */
    iVar2 = READ_BYTE();
    iVar4 = READ_BYTE();
    iVar5 = READ_BYTE();
    EnableIcon(this,pcVar3,(uchar)iVar2,(uchar)iVar4,(uchar)iVar5);
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 | 1;
  }
  return 1;
}


// CHudStatusIcons::EnableIcon  @ 0007aa20  (line 108)

/* DWARF original prototype: void EnableIcon(CHudStatusIcons * this, char * pszIconName, uchar red,
   uchar green, uchar blue) */

void __thiscall
CHudStatusIcons::EnableIcon
          (CHudStatusIcons *this,char *pszIconName,uchar red,uchar green,uchar blue)

{
  int iVar1;
  int iVar2;
  wrect_t *pwVar3;
  char *pcVar4;
  cl_entity_s *pcVar5;
  HANDLE_SPRITE HVar6;
  N15CHudStatusIcons13icon_sprite_tE *__s1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int spr_index@[???] */
  __s1 = this->m_IconList;
  iVar1 = strcasecmp(__s1->szSpriteName,pszIconName);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = strcasecmp(this->m_IconList[1].szSpriteName,pszIconName);
    if (iVar1 == 0) {
      iVar1 = 1;
      __s1 = this->m_IconList + 1;
    }
    else {
      iVar1 = strcasecmp(this->m_IconList[2].szSpriteName,pszIconName);
      if (iVar1 == 0) {
        iVar1 = 2;
        __s1 = this->m_IconList + 2;
      }
      else {
        iVar1 = strcasecmp(this->m_IconList[3].szSpriteName,pszIconName);
        if (iVar1 == 0) {
          iVar1 = 3;
          __s1 = this->m_IconList + 3;
        }
        else {
          if (this->m_IconList[0].spr == 0) {
            iVar1 = 0;
          }
          else if (this->m_IconList[1].spr == 0) {
            iVar1 = 1;
          }
          else if (this->m_IconList[2].spr == 0) {
            iVar1 = 2;
          }
          else {
            iVar1 = 0;
            if (this->m_IconList[3].spr != 0) goto LAB_0007aaf1;
            iVar1 = 3;
          }
          __s1 = this->m_IconList + iVar1;
        }
      }
    }
  }
LAB_0007aaf1:
  iVar2 = CHud::GetSpriteIndex(&gHUD,pszIconName);
  HVar6 = 0;
  if (-1 < iVar2) {
    HVar6 = gHUD.m_rghSprites[iVar2];
  }
  this->m_IconList[iVar1].spr = HVar6;
  pwVar3 = gHUD.m_rgrcRects + iVar2;
  this->m_IconList[iVar1].rc.left = pwVar3->left;
  this->m_IconList[iVar1].rc.right = pwVar3->right;
  this->m_IconList[iVar1].rc.top = pwVar3->top;
  iVar2 = pwVar3->bottom;
  this->m_IconList[iVar1].b = blue;
  this->m_IconList[iVar1].rc.bottom = iVar2;
  this->m_IconList[iVar1].r = red;
  this->m_IconList[iVar1].g = green;
  __strcpy_chk(__s1,pszIconName,0x18);
  pcVar4 = strstr(__s1->szSpriteName,"grenade");
  if (pcVar4 != (char *)0x0) {
                    /* Unresolved local var: cl_entity_t.conflict * pthisplayer@[???] */
    pcVar5 = (*gEngfuncs.GetLocalPlayer)();
    (*(gEngfuncs.pEventAPI)->EV_PlaySound)
              (pcVar5->index,&(pcVar5->origin).x,6,"weapons/timer.wav",1.0,0.8,0,100);
  }
  return;
}


// CHudStatusIcons::DisableIcon  @ 0007aef0  (line 152)

/* DWARF original prototype: void DisableIcon(CHudStatusIcons * this, char * pszIconName) */

void __thiscall CHudStatusIcons::DisableIcon(CHudStatusIcons *this,char *pszIconName)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  N15CHudStatusIcons13icon_sprite_tE *__s1;
  char *pcVar4;
  bool bVar5;
  
                    /* Unresolved local var: int i@[???] */
  __s1 = this->m_IconList;
  iVar1 = strcasecmp(__s1->szSpriteName,pszIconName);
  if (iVar1 != 0) {
    __s1 = this->m_IconList + 1;
    iVar1 = strcasecmp(__s1->szSpriteName,pszIconName);
    if (iVar1 != 0) {
      __s1 = this->m_IconList + 2;
      iVar1 = strcasecmp(__s1->szSpriteName,pszIconName);
      if (iVar1 != 0) {
        __s1 = this->m_IconList + 3;
        iVar1 = strcasecmp(__s1->szSpriteName,pszIconName);
        if (iVar1 != 0) {
          return;
        }
      }
    }
  }
  bVar5 = ((uint)__s1 & 1) != 0;
  uVar3 = 0x30;
  if (bVar5) {
    __s1->szSpriteName[0] = '\0';
    uVar3 = 0x2f;
    __s1 = (N15CHudStatusIcons13icon_sprite_tE *)(__s1->szSpriteName + 1);
  }
  if (((uint)__s1 & 2) != 0) {
    __s1->szSpriteName[0] = '\0';
    __s1->szSpriteName[1] = '\0';
    uVar3 = uVar3 - 2;
    __s1 = (N15CHudStatusIcons13icon_sprite_tE *)(__s1->szSpriteName + 2);
  }
  uVar2 = 0;
  do {
    pcVar4 = __s1->szSpriteName + uVar2;
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4 = __s1->szSpriteName + uVar2 + 4;
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    uVar2 = uVar2 + 8;
  } while (uVar2 < (uVar3 & 0xfffffff8));
  pcVar4 = __s1->szSpriteName + uVar2;
  if ((uVar3 & 4) != 0) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4 = pcVar4 + 4;
  }
  if ((uVar3 & 2) != 0) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4 = pcVar4 + 2;
  }
  if (bVar5) {
    *pcVar4 = '\0';
  }
  return;
}


