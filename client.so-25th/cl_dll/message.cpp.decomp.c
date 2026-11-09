// Ghidra decompilation of functions from cl_dll/message.cpp
// 16 functions, ordered by original source line

// __MsgFunc_HudText  @ 00079260  (line 28)

int __MsgFunc_HudText(char *pszName,int iSize,void *pbuf)

{
  char *__s;
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  byte bVar6;
  
  bVar6 = 0;
                    /* Unresolved local var: char * pString@[???]
                       Unresolved local var: bool bIsEnding@[???]
                       Unresolved local var: char * HL1_ENDING_STR@[???] */
  BEGIN_READ(pbuf,iSize);
  __s = READ_STRING();
  sVar1 = strlen(__s);
  if (sVar1 == 4) {
    iVar2 = 5;
    bVar5 = true;
    pcVar3 = "END3";
    pcVar4 = __s;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
      pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
    } while (bVar5);
    if (bVar5) {
      gHUD.m_Message.m_bEndAfterMessage = true;
    }
  }
  CHudMessage::MessageAdd(&gHUD.m_Message,__s,gHUD.m_flTime);
  gHUD.m_Message.m_parms.time = gHUD.m_flTime;
  if ((gHUD.m_Message.super_CHudBase.m_iFlags & 1U) == 0) {
    gHUD.m_Message.super_CHudBase.m_iFlags = gHUD.m_Message.super_CHudBase.m_iFlags | 1;
  }
  return 1;
}


// __MsgFunc_GameTitle  @ 000776c0  (line 29)

int __MsgFunc_GameTitle(char *pszName,int iSize,void *pbuf)

{
  gHUD.m_Message.m_pGameTitle = (*gEngfuncs.pfnTextMessageGet)("GAMETITLE");
  if (gHUD.m_Message.m_pGameTitle != (client_textmessage_s *)0x0) {
    gHUD.m_Message.m_gameTitleTime = gHUD.m_flTime;
    if ((gHUD.m_Message.super_CHudBase.m_iFlags & 1U) == 0) {
      gHUD.m_Message.super_CHudBase.m_iFlags = gHUD.m_Message.super_CHudBase.m_iFlags | 1;
    }
  }
  return 1;
}


// CHudMessage::Init  @ 000778b0  (line 37)

/* DWARF original prototype: int Init(CHudMessage * this) */

int __thiscall CHudMessage::Init(CHudMessage *this)

{
  _func_int_varargs *p_Var1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  client_textmessage_t **ppcVar5;
  float *pfVar6;
  bool bVar7;
  
  (*gEngfuncs.pfnHookUserMsg)("HudText",__MsgFunc_HudText);
  (*gEngfuncs.pfnHookUserMsg)("GameTitle",__MsgFunc_GameTitle);
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  p_Var1 = (this->super_CHudBase)._vptr_CHudBase[6];
  if (p_Var1 == Reset) {
    ppcVar5 = this->m_pMessages;
    uVar3 = 0x40;
    bVar7 = ((uint)ppcVar5 & 1) != 0;
    if (bVar7) {
      *(undefined1 *)this->m_pMessages = 0;
      ppcVar5 = (client_textmessage_t **)((int)this->m_pMessages + 1);
      uVar3 = 0x3f;
    }
    if (((uint)ppcVar5 & 2) != 0) {
      *(undefined2 *)ppcVar5 = 0;
      uVar3 = uVar3 - 2;
      ppcVar5 = (client_textmessage_t **)((int)ppcVar5 + 2);
    }
    uVar2 = 0;
    do {
      *(undefined4 *)((int)ppcVar5 + uVar2) = 0;
      *(undefined4 *)((int)ppcVar5 + uVar2 + 4) = 0;
      uVar2 = uVar2 + 8;
    } while (uVar2 < (uVar3 & 0xfffffff8));
    puVar4 = (undefined4 *)((int)ppcVar5 + uVar2);
    if ((uVar3 & 4) != 0) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    if ((uVar3 & 2) != 0) {
      *(undefined2 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    }
    if (bVar7) {
      *(undefined1 *)puVar4 = 0;
    }
    pfVar6 = this->m_startTime;
    uVar3 = 0x40;
    bVar7 = ((uint)pfVar6 & 1) != 0;
    if (bVar7) {
      *(undefined1 *)this->m_startTime = 0;
      pfVar6 = (float *)((int)this->m_startTime + 1);
      uVar3 = 0x3f;
    }
    if (((uint)pfVar6 & 2) != 0) {
      *(undefined2 *)pfVar6 = 0;
      uVar3 = uVar3 - 2;
      pfVar6 = (float *)((int)pfVar6 + 2);
    }
    uVar2 = 0;
    do {
      *(undefined4 *)((int)pfVar6 + uVar2) = 0;
      *(undefined4 *)((int)pfVar6 + uVar2 + 4) = 0;
      uVar2 = uVar2 + 8;
    } while (uVar2 < (uVar3 & 0xfffffff8));
    puVar4 = (undefined4 *)((int)pfVar6 + uVar2);
    if ((uVar3 & 4) != 0) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    if ((uVar3 & 2) != 0) {
      *(undefined2 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    }
    if (bVar7) {
      *(undefined1 *)puVar4 = 0;
    }
    this->m_bEndAfterMessage = false;
    this->m_gameTitleTime = 0.0;
    this->m_pGameTitle = (client_textmessage_t *)0x0;
  }
  else {
    (*p_Var1)(this);
  }
  return 1;
}


// CHudMessage::VidInit  @ 00077710  (line 49)

/* DWARF original prototype: int VidInit(CHudMessage * this) */

int __thiscall CHudMessage::VidInit(CHudMessage *this)

{
  int iVar1;
  
  iVar1 = CHud::GetSpriteIndex(&gHUD,"title_half");
  this->m_HUD_title_half = iVar1;
  iVar1 = CHud::GetSpriteIndex(&gHUD,"title_life");
  this->m_HUD_title_life = iVar1;
  return 1;
}


// CHudMessage::Reset  @ 00077760  (line 58)

/* DWARF original prototype: void Reset(CHudMessage * this) */

void __thiscall CHudMessage::Reset(CHudMessage *this)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  client_textmessage_t **ppcVar4;
  float *pfVar5;
  bool bVar6;
  
  uVar2 = 0x40;
  ppcVar4 = this->m_pMessages;
  bVar6 = ((uint)ppcVar4 & 1) != 0;
  if (bVar6) {
    ppcVar4 = (client_textmessage_t **)((int)this->m_pMessages + 1);
    uVar2 = 0x3f;
    *(undefined1 *)this->m_pMessages = 0;
  }
  if (((uint)ppcVar4 & 2) != 0) {
    *(undefined2 *)ppcVar4 = 0;
    uVar2 = uVar2 - 2;
    ppcVar4 = (client_textmessage_t **)((int)ppcVar4 + 2);
  }
  uVar1 = 0;
  do {
    *(undefined4 *)((int)ppcVar4 + uVar1) = 0;
    *(undefined4 *)((int)ppcVar4 + uVar1 + 4) = 0;
    uVar1 = uVar1 + 8;
  } while (uVar1 < (uVar2 & 0xfffffff8));
  puVar3 = (undefined4 *)((int)ppcVar4 + uVar1);
  if ((uVar2 & 4) != 0) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if ((uVar2 & 2) != 0) {
    *(undefined2 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 2);
  }
  if (bVar6) {
    *(undefined1 *)puVar3 = 0;
  }
  pfVar5 = this->m_startTime;
  uVar2 = 0x40;
  bVar6 = ((uint)pfVar5 & 1) != 0;
  if (bVar6) {
    *(undefined1 *)this->m_startTime = 0;
    pfVar5 = (float *)((int)this->m_startTime + 1);
    uVar2 = 0x3f;
  }
  if (((uint)pfVar5 & 2) != 0) {
    *(undefined2 *)pfVar5 = 0;
    uVar2 = uVar2 - 2;
    pfVar5 = (float *)((int)pfVar5 + 2);
  }
  uVar1 = 0;
  do {
    *(undefined4 *)((int)pfVar5 + uVar1) = 0;
    *(undefined4 *)((int)pfVar5 + uVar1 + 4) = 0;
    uVar1 = uVar1 + 8;
  } while (uVar1 < (uVar2 & 0xfffffff8));
  puVar3 = (undefined4 *)((int)pfVar5 + uVar1);
  if ((uVar2 & 4) != 0) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if ((uVar2 & 2) != 0) {
    *(undefined2 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 2);
  }
  if (bVar6) {
    *(undefined1 *)puVar3 = 0;
  }
  this->m_bEndAfterMessage = false;
  this->m_gameTitleTime = 0.0;
  this->m_pGameTitle = (client_textmessage_t *)0x0;
  return;
}


// CHudMessage::FadeBlend  @ 00077a40  (line 69)

/* DWARF original prototype: float FadeBlend(CHudMessage * this, float fadein, float fadeout, float
   hold, float localTime) */

float __thiscall
CHudMessage::FadeBlend(CHudMessage *this,float fadein,float fadeout,float hold,float localTime)

{
                    /* Unresolved local var: float fadeTime@[???]
                       Unresolved local var: float fadeBlend@[???] */
  if (0.0 <= localTime) {
    if (localTime < fadein) {
      return 1.0 - (fadein - localTime) / fadein;
    }
    if (localTime <= fadein + hold) {
      return 1.0;
    }
    if (0.0 < fadeout) {
      return 1.0 - (localTime - (fadein + hold)) / fadeout;
    }
  }
  return 0.0;
}


// CHudMessage::XPosition  @ 00077ab0  (line 95)

/* DWARF original prototype: int XPosition(CHudMessage * this, float x, int width, int totalWidth)
    */

int __thiscall CHudMessage::XPosition(CHudMessage *this,float x,int width,int totalWidth)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int xPos@[???] */
  if (x == -1.0) {
    iVar2 = (gHUD.m_scrinfo.iWidth - width) / 2;
  }
  else if (0.0 <= x) {
    iVar2 = (int)((float)gHUD.m_scrinfo.iWidth * x);
  }
  else {
    iVar2 = (int)((float)gHUD.m_scrinfo.iWidth * (x + 1.0) - (float)totalWidth);
  }
  if (gHUD.m_scrinfo.iWidth < iVar2 + width) {
    return gHUD.m_scrinfo.iWidth - width;
  }
  iVar1 = 0;
  if (-1 < iVar2) {
    iVar1 = iVar2;
  }
  return iVar1;
}


// CHudMessage::YPosition  @ 00077b50  (line 120)

/* DWARF original prototype: int YPosition(CHudMessage * this, float y, int height) */

int __thiscall CHudMessage::YPosition(CHudMessage *this,float y,int height)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int yPos@[???] */
  if (y == -1.0) {
    fVar1 = (float)(gHUD.m_scrinfo.iHeight - height) * 0.5;
  }
  else if (0.0 <= y) {
    fVar1 = (float)gHUD.m_scrinfo.iHeight * y;
  }
  else {
    fVar1 = (float)gHUD.m_scrinfo.iHeight * (y + 1.0) - (float)height;
  }
  iVar2 = (int)fVar1;
  if (gHUD.m_scrinfo.iHeight < iVar2 + height) {
    return gHUD.m_scrinfo.iHeight - height;
  }
  iVar3 = 0;
  if (-1 < iVar2) {
    iVar3 = iVar2;
  }
  return iVar3;
}


// CHudMessage::MessageScanNextChar  @ 00077c00  (line 144)

/* DWARF original prototype: void MessageScanNextChar(CHudMessage * this) */

void __thiscall CHudMessage::MessageScanNextChar(CHudMessage *this)

{
  float fVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  client_textmessage_t *pcVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint local_30;
  uint local_2c;
  uint local_28;
  
                    /* Unresolved local var: int srcRed@[???]
                       Unresolved local var: int srcGreen@[???]
                       Unresolved local var: int srcBlue@[???]
                       Unresolved local var: int destRed@[???]
                       Unresolved local var: int destGreen@[???]
                       Unresolved local var: int destBlue@[???]
                       Unresolved local var: int blend@[???] */
  pcVar5 = (this->m_parms).pMessage;
  iVar7 = pcVar5->effect;
  bVar2 = pcVar5->r1;
  bVar3 = pcVar5->g1;
  bVar4 = pcVar5->b1;
  if (iVar7 < 0) {
LAB_00077c80:
    iVar10 = (int)((uint)bVar2 * 0xff) >> 8;
    iVar8 = (int)((uint)bVar3 * 0xff) >> 8;
    iVar7 = (int)((uint)bVar4 * 0xff) >> 8;
  }
  else {
    if (iVar7 < 2) {
LAB_00077cd4:
      iVar7 = (this->m_parms).fadeBlend;
      local_28 = 0;
      local_2c = 0;
      local_30 = 0;
    }
    else {
      if (iVar7 != 2) goto LAB_00077c80;
      fVar6 = (this->m_parms).charTime + pcVar5->fadein;
      (this->m_parms).charTime = fVar6;
      fVar1 = (this->m_parms).time;
      if (fVar1 < fVar6) {
        iVar7 = 0;
        iVar8 = 0;
        iVar10 = 0;
        goto LAB_00077ca4;
      }
                    /* Unresolved local var: float deltaTime@[???] */
      if ((this->m_parms).fadeTime < fVar1) goto LAB_00077cd4;
      if (pcVar5->fxtime < fVar1 - fVar6) goto LAB_00077c80;
      local_30 = (uint)pcVar5->r2;
      local_2c = (uint)pcVar5->g2;
      local_28 = (uint)pcVar5->b2;
      iVar7 = (int)(255.0 - ((fVar1 - fVar6) * (1.0 / pcVar5->fxtime) * 255.0 + 0.5));
    }
    if (iVar7 < 0x100) {
      iVar8 = 0;
      if (-1 < iVar7) {
        iVar8 = iVar7;
      }
      iVar9 = 0xff - iVar8;
      iVar10 = (int)((uint)bVar2 * iVar9 + iVar8 * local_30) >> 8;
      iVar7 = (int)((uint)bVar4 * iVar9 + local_28 * iVar8) >> 8;
      iVar8 = (int)((uint)bVar3 * iVar9 + local_2c * iVar8) >> 8;
    }
    else {
      iVar10 = (int)(local_30 * 0xff) >> 8;
      iVar8 = (int)(local_2c * 0xff) >> 8;
      iVar7 = (int)(local_28 * 0xff) >> 8;
    }
  }
LAB_00077ca4:
  (this->m_parms).r = iVar10;
  (this->m_parms).g = iVar8;
  (this->m_parms).b = iVar7;
  if ((((pcVar5->effect == 1) && ((this->m_parms).charTime != 0.0)) &&
      (iVar7 = (this->m_parms).x, -1 < iVar7)) &&
     ((iVar8 = (this->m_parms).y, -1 < iVar8 &&
      (iVar10 = (this->m_parms).text,
      gHUD.m_scrinfo.charWidths[iVar10] + iVar7 <= gHUD.m_scrinfo.iWidth)))) {
    (*gEngfuncs.pfnDrawCharacter)
              (iVar7,iVar8,iVar10,(int)pcVar5->r2,(int)pcVar5->g2,(int)pcVar5->b2);
  }
  return;
}


// CHudMessage::MessageScanStart  @ 00077e50  (line 208)

/* DWARF original prototype: void MessageScanStart(CHudMessage * this) */

void __thiscall CHudMessage::MessageScanStart(CHudMessage *this)

{
  float fVar1;
  float fVar2;
  client_textmessage_t *pcVar3;
  float fVar4;
  int iVar5;
  
  pcVar3 = (this->m_parms).pMessage;
  iVar5 = pcVar3->effect;
  if (-1 < iVar5) {
    if (iVar5 < 2) {
      fVar4 = pcVar3->fadein + pcVar3->holdtime;
      (this->m_parms).fadeTime = fVar4;
      fVar1 = (this->m_parms).time;
      fVar2 = pcVar3->fadein;
      if (fVar1 < fVar2) {
        (this->m_parms).fadeBlend = (int)((1.0 / fVar2) * (fVar2 - fVar1) * 255.0);
      }
      else if (fVar1 <= fVar4) {
        (this->m_parms).fadeBlend = 0;
      }
      else if (pcVar3->fadeout <= 0.0) {
        (this->m_parms).fadeBlend = 0xff;
      }
      else {
        (this->m_parms).fadeBlend = (int)(((fVar1 - fVar4) / pcVar3->fadeout) * 255.0);
      }
      (this->m_parms).charTime = 0.0;
      if ((pcVar3->effect == 1) && (iVar5 = rand(), iVar5 % 100 < 10)) {
        (this->m_parms).charTime = 1.0;
        return;
      }
    }
    else if (iVar5 == 2) {
      fVar2 = (float)(this->m_parms).length * pcVar3->fadein + pcVar3->holdtime;
      (this->m_parms).fadeTime = fVar2;
      fVar1 = (this->m_parms).time;
      if ((fVar1 <= fVar2) || (pcVar3->fadeout <= 0.0)) {
        (this->m_parms).fadeBlend = 0;
        return;
      }
      (this->m_parms).fadeBlend = (int)(((fVar1 - fVar2) / pcVar3->fadeout) * 255.0);
    }
  }
  return;
}


// CHudMessage::MessageDrawScan  @ 00077ff0  (line 249)

/* DWARF original prototype: void MessageDrawScan(CHudMessage * this, client_textmessage_t *
   pMessage, float time) */

void __thiscall
CHudMessage::MessageDrawScan(CHudMessage *this,client_textmessage_t *pMessage,float time)

{
  float fVar1;
  byte bVar2;
  short sVar3;
  char *pcVar4;
  client_textmessage_t *pcVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int in_GS_OFFSET;
  int local_b0;
  int local_a4;
  uint local_98;
  uint local_8c;
  int local_88;
  byte *local_84;
  byte local_70 [80];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: char * pText@[???]
                       Unresolved local var: uchar[80] line@[???] */
  iVar12 = 1;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar4 = pMessage->pMessage;
  (this->m_parms).time = time;
  (this->m_parms).lines = 1;
  (this->m_parms).pMessage = pMessage;
  (this->m_parms).totalWidth = 0;
  iVar7 = (int)*pcVar4;
  if (*pcVar4 == '\0') {
    iVar10 = 0;
  }
  else {
    iVar8 = 0;
    iVar10 = 0;
LAB_00078072:
    do {
      if ((char)iVar7 == '\n') {
        iVar12 = iVar12 + 1;
        (this->m_parms).lines = iVar12;
        if ((this->m_parms).totalWidth < iVar8) {
          (this->m_parms).totalWidth = iVar8;
          iVar10 = iVar10 + 1;
          iVar8 = 0;
          iVar7 = (int)pcVar4[iVar10];
          if (pcVar4[iVar10] == '\0') break;
          goto LAB_00078072;
        }
        iVar8 = 0;
      }
      else {
        iVar8 = iVar8 + gHUD.m_scrinfo.charWidths[iVar7];
      }
      iVar10 = iVar10 + 1;
      iVar7 = (int)pcVar4[iVar10];
    } while (pcVar4[iVar10] != '\0');
  }
  (this->m_parms).length = iVar10;
  iVar12 = iVar12 * gHUD.m_scrinfo.iCharHeight;
  (this->m_parms).totalHeight = iVar12;
  fVar1 = pMessage->y;
                    /* Unresolved local var: int yPos@[???] */
  if (fVar1 == -1.0) {
    fVar1 = (float)(gHUD.m_scrinfo.iHeight - iVar12) * 0.5;
  }
  else if (0.0 <= fVar1) {
    fVar1 = (float)gHUD.m_scrinfo.iHeight * fVar1;
  }
  else {
    fVar1 = (float)gHUD.m_scrinfo.iHeight * (fVar1 + 1.0) - (float)iVar12;
  }
  iVar7 = (int)fVar1;
  if (gHUD.m_scrinfo.iHeight < iVar12 + iVar7) {
    iVar7 = gHUD.m_scrinfo.iHeight - iVar12;
  }
  else if (iVar7 < 0) {
    iVar7 = 0;
  }
  (this->m_parms).y = iVar7;
  local_84 = (byte *)pMessage->pMessage;
  (this->m_parms).charTime = 0.0;
  MessageScanStart(this);
  if (0 < (this->m_parms).lines) {
    local_a4 = (this->m_parms).y;
    local_88 = 0;
    do {
      (this->m_parms).lineLength = 0;
      iVar7 = 0;
      iVar12 = 0;
      (this->m_parms).width = 0;
      bVar2 = *local_84;
      if ((bVar2 != 0) && (bVar2 != 10)) {
        while( true ) {
                    /* Unresolved local var: uchar c@[???] */
          local_70[iVar12] = bVar2;
          sVar3 = gHUD.m_scrinfo.charWidths[bVar2];
          iVar12 = iVar12 + 1;
          local_84 = local_84 + 1;
          (this->m_parms).lineLength = iVar12;
          iVar7 = iVar7 + sVar3;
          (this->m_parms).width = iVar7;
          bVar2 = *local_84;
          if (bVar2 == 0) break;
          if ((bVar2 == 10) || (iVar12 == 0x4f)) break;
        }
      }
      local_84 = local_84 + 1;
      local_70[iVar12] = 0;
      fVar1 = pMessage->x;
                    /* Unresolved local var: int xPos@[???] */
      if (fVar1 == -1.0) {
        local_b0 = (gHUD.m_scrinfo.iWidth - iVar7) / 2;
LAB_000781ea:
        if (local_b0 + iVar7 <= gHUD.m_scrinfo.iWidth) goto LAB_000781f5;
LAB_000785b2:
        local_b0 = gHUD.m_scrinfo.iWidth - iVar7;
      }
      else {
        if (fVar1 < 0.0) {
          local_b0 = (int)((float)gHUD.m_scrinfo.iWidth * (fVar1 + 1.0) -
                          (float)(this->m_parms).totalWidth);
          goto LAB_000781ea;
        }
        local_b0 = (int)((float)gHUD.m_scrinfo.iWidth * fVar1);
        if (gHUD.m_scrinfo.iWidth < local_b0 + iVar7) goto LAB_000785b2;
LAB_000781f5:
        if (local_b0 < 0) {
          local_b0 = 0;
        }
      }
      (this->m_parms).x = local_b0;
      if (iVar12 != 0) {
        iVar7 = 0;
        do {
          uVar11 = (uint)local_70[iVar7];
          (this->m_parms).text = uVar11;
          iVar10 = gHUD.m_scrinfo.charWidths[uVar11] + local_b0;
                    /* Unresolved local var: int srcRed@[???]
                       Unresolved local var: int srcGreen@[???]
                       Unresolved local var: int srcBlue@[???]
                       Unresolved local var: int destRed@[???]
                       Unresolved local var: int destGreen@[???]
                       Unresolved local var: int destBlue@[???]
                       Unresolved local var: int blend@[???] */
          pcVar5 = (this->m_parms).pMessage;
          uVar13 = (uint)pcVar5->r1;
          iVar12 = pcVar5->effect;
          uVar16 = (uint)pcVar5->g1;
          uVar14 = (uint)pcVar5->b1;
          if (iVar12 < 0) {
LAB_00078478:
            iVar8 = (int)(uVar13 * 0xff) >> 8;
            iVar12 = (int)(uVar16 * 0xff) >> 8;
            iVar17 = (int)(uVar14 * 0xff) >> 8;
          }
          else if (iVar12 < 2) {
LAB_00078424:
            iVar12 = (this->m_parms).fadeBlend;
            local_8c = 0;
            local_98 = 0;
            uVar15 = 0;
LAB_0007843a:
            if (iVar12 < 0x100) {
              iVar17 = 0;
              if (-1 < iVar12) {
                iVar17 = iVar12;
              }
              iVar9 = 0xff - iVar17;
              iVar8 = (int)(uVar15 * iVar17 + uVar13 * iVar9) >> 8;
              iVar12 = (int)(local_98 * iVar17 + uVar16 * iVar9) >> 8;
              iVar17 = (int)(local_8c * iVar17 + uVar14 * iVar9) >> 8;
            }
            else {
              iVar8 = (int)(uVar15 * 0xff) >> 8;
              iVar12 = (int)(local_98 * 0xff) >> 8;
              iVar17 = (int)(local_8c * 0xff) >> 8;
            }
          }
          else {
            if (iVar12 != 2) goto LAB_00078478;
            fVar6 = (this->m_parms).charTime + pcVar5->fadein;
            (this->m_parms).charTime = fVar6;
            fVar1 = (this->m_parms).time;
            if (fVar1 < fVar6) {
              iVar17 = 0;
              iVar12 = 0;
              iVar8 = 0;
            }
            else {
                    /* Unresolved local var: float deltaTime@[???] */
              if ((this->m_parms).fadeTime < fVar1) goto LAB_00078424;
              if (fVar1 - fVar6 <= pcVar5->fxtime) {
                local_98 = (uint)pcVar5->g2;
                uVar15 = (uint)pcVar5->r2;
                local_8c = (uint)pcVar5->b2;
                iVar12 = (int)(255.0 - ((fVar1 - fVar6) * (1.0 / pcVar5->fxtime) * 255.0 + 0.5));
                goto LAB_0007843a;
              }
              iVar8 = (int)(uVar13 * 0xff) >> 8;
              iVar12 = (int)(uVar16 * 0xff) >> 8;
              iVar17 = (int)(uVar14 * 0xff) >> 8;
            }
          }
          (this->m_parms).r = iVar8;
          (this->m_parms).g = iVar12;
          (this->m_parms).b = iVar17;
          if (((pcVar5->effect == 1) && ((this->m_parms).charTime != 0.0)) && (-1 < local_b0)) {
            if (-1 < local_a4) {
              if (gHUD.m_scrinfo.charWidths[uVar11] + local_b0 <= gHUD.m_scrinfo.iWidth) {
                (*gEngfuncs.pfnDrawCharacter)
                          (local_b0,local_a4,uVar11,(int)pcVar5->r2,(int)pcVar5->g2,(int)pcVar5->b2)
                ;
                local_a4 = (this->m_parms).y;
                goto LAB_00078228;
              }
              iVar12 = (this->m_parms).x;
              if ((iVar12 < 0) || (gHUD.m_scrinfo.iWidth < iVar10)) goto LAB_0007824a;
              goto LAB_000783d0;
            }
          }
          else {
LAB_00078228:
                    /* Unresolved local var: int next@[???] */
            iVar12 = (this->m_parms).x;
            if (((-1 < iVar12) && (-1 < local_a4)) && (iVar10 <= gHUD.m_scrinfo.iWidth)) {
LAB_000783d0:
              (*gEngfuncs.pfnDrawCharacter)
                        (iVar12,local_a4,(this->m_parms).text,(this->m_parms).r,(this->m_parms).g,
                         (this->m_parms).b);
              local_a4 = (this->m_parms).y;
            }
          }
LAB_0007824a:
          iVar7 = iVar7 + 1;
          (this->m_parms).x = iVar10;
          local_b0 = iVar10;
        } while (iVar7 < (this->m_parms).lineLength);
      }
      local_a4 = local_a4 + gHUD.m_scrinfo.iCharHeight;
      local_88 = local_88 + 1;
      (this->m_parms).y = local_a4;
    } while (local_88 < (this->m_parms).lines);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHudMessage::Draw  @ 000786b0  (line 321)

/* DWARF original prototype: int Draw(CHudMessage * this, float fTime) */

int __thiscall CHudMessage::Draw(CHudMessage *this,float fTime)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  client_textmessage_t *pcVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  size_t sVar8;
  int iVar9;
  int iVar10;
  wrect_t *pwVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  HANDLE_SPRITE HVar15;
  float fVar16;
  int local_40;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int drawn@[???]
                       Unresolved local var: client_textmessage_t * pMessage@[???]
                       Unresolved local var: float endTime@[???] */
  fVar3 = gHUD.m_flTime;
  fVar16 = this->m_gameTitleTime;
  if (fVar16 <= 0.0) {
    local_40 = 0;
    goto LAB_00078724;
  }
                    /* Unresolved local var: float localTime@[???]
                       Unresolved local var: float brightness@[???] */
  fVar6 = gHUD.m_flTime - fVar16;
  if (gHUD.m_flTime < fVar16) {
    this->m_gameTitleTime = gHUD.m_flTime;
  }
  pcVar4 = this->m_pGameTitle;
  fVar16 = pcVar4->fadein;
  fVar7 = pcVar4->holdtime + fVar16;
  fVar2 = pcVar4->fadeout;
  if (fVar7 + fVar2 < fVar6) {
    this->m_gameTitleTime = 0.0;
    local_40 = 0;
    goto LAB_00078724;
  }
                    /* Unresolved local var: int halfWidth@[???]
                       Unresolved local var: int fullWidth@[???]
                       Unresolved local var: int fullHeight@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: float fadeTime@[???]
                       Unresolved local var: float fadeBlend@[???] */
  if (fVar6 < 0.0) {
LAB_00078e28:
    fVar16 = 0.0;
  }
  else if (fVar16 <= fVar6) {
    if (fVar6 <= fVar7) {
      fVar16 = 1.0;
    }
    else {
      if (fVar2 <= 0.0) goto LAB_00078e28;
      fVar16 = 1.0 - (fVar6 - fVar7) / fVar2;
    }
  }
  else {
    fVar16 = 1.0 - (fVar16 - fVar6) / fVar16;
  }
  iVar5 = this->m_HUD_title_half;
  fVar3 = pcVar4->x;
                    /* Unresolved local var: int xPos@[???] */
  pwVar11 = gHUD.m_rgrcRects + iVar5;
  iVar9 = pwVar11->right - pwVar11->left;
  iVar14 = (iVar9 + gHUD.m_rgrcRects[this->m_HUD_title_life].right) -
           gHUD.m_rgrcRects[this->m_HUD_title_life].left;
  iVar10 = pwVar11->bottom - pwVar11->top;
  if (fVar3 == -1.0) {
    iVar12 = (gHUD.m_scrinfo.iWidth - iVar14) / 2;
LAB_00078bbb:
    if (iVar14 + iVar12 <= gHUD.m_scrinfo.iWidth) goto LAB_00078bc6;
LAB_00078ea3:
    iVar14 = gHUD.m_scrinfo.iWidth - iVar14;
  }
  else {
    if (fVar3 < 0.0) {
      iVar12 = (int)((float)gHUD.m_scrinfo.iWidth * (fVar3 + 1.0) - (float)iVar14);
      goto LAB_00078bbb;
    }
    iVar12 = (int)((float)gHUD.m_scrinfo.iWidth * fVar3);
    if (gHUD.m_scrinfo.iWidth < iVar14 + iVar12) goto LAB_00078ea3;
LAB_00078bc6:
    iVar14 = 0;
    if (-1 < iVar12) {
      iVar14 = iVar12;
    }
  }
  fVar3 = pcVar4->y;
                    /* Unresolved local var: int yPos@[???] */
  if (fVar3 == -1.0) {
    fVar3 = (float)(gHUD.m_scrinfo.iHeight - iVar10) * 0.5;
LAB_00078c15:
    iVar12 = (int)fVar3;
    if (iVar10 + iVar12 <= gHUD.m_scrinfo.iHeight) goto LAB_00078c23;
LAB_00078e62:
    local_40 = gHUD.m_scrinfo.iHeight - iVar10;
  }
  else {
    if (fVar3 < 0.0) {
      fVar3 = (float)gHUD.m_scrinfo.iHeight * (fVar3 + 1.0) - (float)iVar10;
      goto LAB_00078c15;
    }
    iVar12 = (int)((float)gHUD.m_scrinfo.iHeight * fVar3);
    if (gHUD.m_scrinfo.iHeight < iVar10 + iVar12) goto LAB_00078e62;
LAB_00078c23:
    local_40 = 0;
    if (-1 < iVar12) {
      local_40 = iVar12;
    }
  }
  if (iVar5 < 0) {
    HVar15 = 0;
  }
  else {
    HVar15 = gHUD.m_rghSprites[iVar5];
  }
  (*gEngfuncs.pfnSPR_Set)
            (HVar15,(int)((float)pcVar4->r1 * fVar16),(int)((float)pcVar4->g1 * fVar16),
             (int)((float)pcVar4->b1 * fVar16));
  (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar14,local_40,gHUD.m_rgrcRects + this->m_HUD_title_half);
  pcVar4 = this->m_pGameTitle;
  if (this->m_HUD_title_life < 0) {
    HVar15 = 0;
  }
  else {
    HVar15 = gHUD.m_rghSprites[this->m_HUD_title_life];
  }
  (*gEngfuncs.pfnSPR_Set)
            (HVar15,(int)((float)pcVar4->r1 * fVar16),(int)((float)pcVar4->g1 * fVar16),
             (int)((float)pcVar4->b1 * fVar16));
  (*gEngfuncs.pfnSPR_DrawAdditive)
            (0,iVar9 + iVar14,local_40,gHUD.m_rgrcRects + this->m_HUD_title_life);
  local_40 = 1;
  fVar3 = gHUD.m_flTime;
LAB_00078724:
  fVar16 = NAN;
  if ((this->m_pMessages[0] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[0])) {
    this->m_startTime[0] = (((this->m_parms).time + fVar3) - this->m_startTime[0]) + 0.2;
  }
  if ((this->m_pMessages[1] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[1])) {
    this->m_startTime[1] = (((this->m_parms).time + fVar3) - this->m_startTime[1]) + 0.2;
  }
  if ((this->m_pMessages[2] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[2])) {
    this->m_startTime[2] = (((this->m_parms).time + fVar3) - this->m_startTime[2]) + 0.2;
  }
  if ((this->m_pMessages[3] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[3])) {
    this->m_startTime[3] = (((this->m_parms).time + fVar3) - this->m_startTime[3]) + 0.2;
  }
  if ((this->m_pMessages[4] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[4])) {
    this->m_startTime[4] = (((this->m_parms).time + fVar3) - this->m_startTime[4]) + 0.2;
  }
  if ((this->m_pMessages[5] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[5])) {
    this->m_startTime[5] = (((this->m_parms).time + fVar3) - this->m_startTime[5]) + 0.2;
  }
  if ((this->m_pMessages[6] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[6])) {
    this->m_startTime[6] = (((this->m_parms).time + fVar3) - this->m_startTime[6]) + 0.2;
  }
  if ((this->m_pMessages[7] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[7])) {
    this->m_startTime[7] = (((this->m_parms).time + fVar3) - this->m_startTime[7]) + 0.2;
  }
  if ((this->m_pMessages[8] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[8])) {
    this->m_startTime[8] = (((this->m_parms).time + fVar3) - this->m_startTime[8]) + 0.2;
  }
  if ((this->m_pMessages[9] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[9])) {
    this->m_startTime[9] = (((this->m_parms).time + fVar3) - this->m_startTime[9]) + 0.2;
  }
  if ((this->m_pMessages[10] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[10])) {
    this->m_startTime[10] = (((this->m_parms).time + fVar3) - this->m_startTime[10]) + 0.2;
  }
  if ((this->m_pMessages[0xb] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[0xb])) {
    this->m_startTime[0xb] = (((this->m_parms).time + fVar3) - this->m_startTime[0xb]) + 0.2;
  }
  if ((this->m_pMessages[0xc] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[0xc])) {
    this->m_startTime[0xc] = (((this->m_parms).time + fVar3) - this->m_startTime[0xc]) + 0.2;
  }
  if ((this->m_pMessages[0xd] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[0xd])) {
    this->m_startTime[0xd] = (((this->m_parms).time + fVar3) - this->m_startTime[0xd]) + 0.2;
  }
  if ((this->m_pMessages[0xe] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[0xe])) {
    this->m_startTime[0xe] = (((this->m_parms).time + fVar3) - this->m_startTime[0xe]) + 0.2;
  }
  if ((this->m_pMessages[0xf] != (client_textmessage_t *)0x0) && (fVar3 < this->m_startTime[0xf])) {
    this->m_startTime[0xf] = ((fVar3 + (this->m_parms).time) - this->m_startTime[0xf]) + 0.2;
  }
  pfVar13 = this->m_startTime;
  do {
    pcVar4 = (client_textmessage_t *)pfVar13[-0x10];
    if (pcVar4 != (client_textmessage_t *)0x0) {
      iVar5 = pcVar4->effect;
      if (-1 < iVar5) {
        if (iVar5 < 2) {
          fVar16 = *pfVar13 + pcVar4->fadein + pcVar4->fadeout + pcVar4->holdtime;
        }
        else if (iVar5 == 2) {
          sVar8 = strlen(pcVar4->pMessage);
          fVar16 = (float)sVar8 * pcVar4->fadein + *pfVar13 + pcVar4->fadeout + pcVar4->holdtime;
        }
      }
      if (fVar16 < fTime) {
        pfVar13[-0x10] = 0.0;
        if (this->m_bEndAfterMessage != false) {
          (*gEngfuncs.pfnClientCmd)("wait\nwait\nwait\nwait\nwait\nwait\nwait\ndisconnect\n");
        }
      }
      else {
                    /* Unresolved local var: float messageTime@[???] */
        MessageDrawScan(this,pcVar4,fTime - *pfVar13);
        local_40 = local_40 + 1;
      }
    }
    pfVar13 = pfVar13 + 1;
  } while ((message_parms_t *)pfVar13 != &this->m_parms);
  (this->m_parms).time = gHUD.m_flTime;
  if (local_40 == 0) {
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 & 0xfffffffe;
  }
  return 1;
}


// CHudMessage::MessageAdd  @ 00078f20  (line 429)

/* DWARF original prototype: void MessageAdd(CHudMessage * this, char * pName, float time) */

void __thiscall CHudMessage::MessageAdd(CHudMessage *this,char *pName,float time)

{
  client_textmessage_t *pcVar1;
  float fVar2;
  client_textmessage_t *pcVar3;
  int iVar4;
  client_textmessage_t **ppcVar5;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: client_textmessage_t * tempMessage@[???] */
  if (this->m_pMessages[0] == (client_textmessage_t *)0x0) {
    local_20 = 0;
  }
  else if (this->m_pMessages[1] == (client_textmessage_t *)0x0) {
    local_20 = 1;
  }
  else if (this->m_pMessages[2] == (client_textmessage_t *)0x0) {
    local_20 = 2;
  }
  else if (this->m_pMessages[3] == (client_textmessage_t *)0x0) {
    local_20 = 3;
  }
  else if (this->m_pMessages[4] == (client_textmessage_t *)0x0) {
    local_20 = 4;
  }
  else if (this->m_pMessages[5] == (client_textmessage_t *)0x0) {
    local_20 = 5;
  }
  else if (this->m_pMessages[6] == (client_textmessage_t *)0x0) {
    local_20 = 6;
  }
  else if (this->m_pMessages[7] == (client_textmessage_t *)0x0) {
    local_20 = 7;
  }
  else if (this->m_pMessages[8] == (client_textmessage_t *)0x0) {
    local_20 = 8;
  }
  else if (this->m_pMessages[9] == (client_textmessage_t *)0x0) {
    local_20 = 9;
  }
  else if (this->m_pMessages[10] == (client_textmessage_t *)0x0) {
    local_20 = 10;
  }
  else if (this->m_pMessages[0xb] == (client_textmessage_t *)0x0) {
    local_20 = 0xb;
  }
  else if (this->m_pMessages[0xc] == (client_textmessage_t *)0x0) {
    local_20 = 0xc;
  }
  else if (this->m_pMessages[0xd] == (client_textmessage_t *)0x0) {
    local_20 = 0xd;
  }
  else if (this->m_pMessages[0xe] == (client_textmessage_t *)0x0) {
    local_20 = 0xe;
  }
  else {
    if (this->m_pMessages[0xf] != (client_textmessage_t *)0x0) {
      return;
    }
    local_20 = 0xf;
  }
  if (*pName == '#') {
    pcVar3 = (*gEngfuncs.pfnTextMessageGet)(pName + 1);
  }
  else {
    pcVar3 = (*gEngfuncs.pfnTextMessageGet)(pName);
  }
  if (pcVar3 == (client_textmessage_s *)0x0) {
    g_pCustomMessage.effect = 2;
    pcVar3 = &g_pCustomMessage;
    g_pCustomMessage.a1 = 'd';
    g_pCustomMessage.pName = g_pCustomName;
    g_pCustomMessage.b1 = 'd';
    g_pCustomMessage.g1 = 'd';
    g_pCustomMessage.r1 = 'd';
    g_pCustomMessage.r2 = 0xf0;
    g_pCustomMessage.g2 = 'n';
    g_pCustomMessage.b2 = '\0';
    g_pCustomMessage.a2 = '\0';
    g_pCustomMessage.x = -1.0;
    g_pCustomMessage.y = 0.7;
    g_pCustomMessage.fadein = 0.01;
    g_pCustomMessage.fadeout = 1.5;
    g_pCustomMessage.fxtime = 0.25;
    g_pCustomMessage.holdtime = 5.0;
    __strcpy_chk(g_pCustomText,pName,0x400);
    g_pCustomMessage.pMessage = g_pCustomText;
  }
  ppcVar5 = this->m_pMessages;
  do {
    pcVar1 = *ppcVar5;
    if (pcVar1 != (client_textmessage_t *)0x0) {
      iVar4 = strcmp(pcVar3->pMessage,pcVar1->pMessage);
      if (iVar4 == 0) {
        return;
      }
      fVar2 = pcVar3->y - pcVar1->y;
      if (fVar2 <= 0.0) {
        fVar2 = 0.0 - fVar2;
      }
      if (fVar2 < 0.0001) {
        fVar2 = pcVar3->x - pcVar1->x;
        if (fVar2 <= 0.0) {
          fVar2 = 0.0 - fVar2;
        }
        if (fVar2 < 0.0001) {
          *ppcVar5 = (client_textmessage_t *)0x0;
        }
      }
    }
    ppcVar5 = ppcVar5 + 1;
  } while (ppcVar5 != (client_textmessage_t **)this->m_startTime);
  this->m_startTime[local_20] = time;
  this->m_pMessages[local_20] = pcVar3;
  return;
}


// CHudMessage::MsgFunc_HudText  @ 00079310  (line 494)

/* DWARF original prototype: int MsgFunc_HudText(CHudMessage * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudMessage::MsgFunc_HudText(CHudMessage *this,char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  char *__s;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  
                    /* Unresolved local var: char * pString@[???]
                       Unresolved local var: bool bIsEnding@[???]
                       Unresolved local var: char * HL1_ENDING_STR@[???] */
  bVar7 = 0;
  BEGIN_READ(pbuf,iSize);
  __s = READ_STRING();
  sVar2 = strlen(__s);
  if (sVar2 == 4) {
    iVar3 = 5;
    bVar6 = true;
    pcVar4 = "END3";
    pcVar5 = __s;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if (bVar6) {
      this->m_bEndAfterMessage = true;
    }
  }
  MessageAdd(this,__s,gHUD.m_flTime);
  uVar1 = (this->super_CHudBase).m_iFlags;
  (this->m_parms).time = gHUD.m_flTime;
  if ((uVar1 & 1) == 0) {
    (this->super_CHudBase).m_iFlags = uVar1 | 1;
  }
  return 1;
}


// CHudMessage::MsgFunc_GameTitle  @ 000793c0  (line 520)

/* DWARF original prototype: int MsgFunc_GameTitle(CHudMessage * this, char * pszName, int iSize,
   void * pbuf) */

int __thiscall CHudMessage::MsgFunc_GameTitle(CHudMessage *this,char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  client_textmessage_s *pcVar2;
  
  pcVar2 = (*gEngfuncs.pfnTextMessageGet)("GAMETITLE");
  this->m_pGameTitle = pcVar2;
  if (pcVar2 != (client_textmessage_s *)0x0) {
    uVar1 = (this->super_CHudBase).m_iFlags;
    this->m_gameTitleTime = gHUD.m_flTime;
    if ((uVar1 & 1) == 0) {
      (this->super_CHudBase).m_iFlags = uVar1 | 1;
    }
  }
  return 1;
}


// CHudMessage::MessageAdd  @ 00079410  (line 534)

/* DWARF original prototype: void MessageAdd(CHudMessage * this, client_textmessage_t * newMessage)
    */

void __thiscall CHudMessage::MessageAdd(CHudMessage *this,client_textmessage_t *newMessage)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (this->super_CHudBase).m_iFlags;
  (this->m_parms).time = gHUD.m_flTime;
  if ((uVar1 & 1) == 0) {
    (this->super_CHudBase).m_iFlags = uVar1 | 1;
  }
                    /* Unresolved local var: int i@[???] */
  if (this->m_pMessages[0] == (client_textmessage_t *)0x0) {
    iVar2 = 0;
  }
  else if (this->m_pMessages[1] == (client_textmessage_t *)0x0) {
    iVar2 = 1;
  }
  else if (this->m_pMessages[2] == (client_textmessage_t *)0x0) {
    iVar2 = 2;
  }
  else if (this->m_pMessages[3] == (client_textmessage_t *)0x0) {
    iVar2 = 3;
  }
  else if (this->m_pMessages[4] == (client_textmessage_t *)0x0) {
    iVar2 = 4;
  }
  else if (this->m_pMessages[5] == (client_textmessage_t *)0x0) {
    iVar2 = 5;
  }
  else if (this->m_pMessages[6] == (client_textmessage_t *)0x0) {
    iVar2 = 6;
  }
  else if (this->m_pMessages[7] == (client_textmessage_t *)0x0) {
    iVar2 = 7;
  }
  else if (this->m_pMessages[8] == (client_textmessage_t *)0x0) {
    iVar2 = 8;
  }
  else if (this->m_pMessages[9] == (client_textmessage_t *)0x0) {
    iVar2 = 9;
  }
  else if (this->m_pMessages[10] == (client_textmessage_t *)0x0) {
    iVar2 = 10;
  }
  else if (this->m_pMessages[0xb] == (client_textmessage_t *)0x0) {
    iVar2 = 0xb;
  }
  else if (this->m_pMessages[0xc] == (client_textmessage_t *)0x0) {
    iVar2 = 0xc;
  }
  else if (this->m_pMessages[0xd] == (client_textmessage_t *)0x0) {
    iVar2 = 0xd;
  }
  else if (this->m_pMessages[0xe] == (client_textmessage_t *)0x0) {
    iVar2 = 0xe;
  }
  else {
    if (this->m_pMessages[0xf] != (client_textmessage_t *)0x0) {
      return;
    }
    iVar2 = 0xf;
  }
  this->m_pMessages[iVar2] = newMessage;
  this->m_startTime[iVar2] = gHUD.m_flTime;
  return;
}


