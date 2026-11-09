// Ghidra decompilation of functions from cl_dll/text_message.cpp
// 8 functions, ordered by original source line

// __MsgFunc_TextMsg  @ 00082600  (line 31)

int __MsgFunc_TextMsg(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHudTextMessage::MsgFunc_TextMsg(&gHUD.m_TextMessage,pszName,iSize,pbuf);
  return iVar1;
}


// CHudTextMessage::Init  @ 00081ce0  (line 34)

/* DWARF original prototype: int Init(CHudTextMessage * this) */

int __thiscall CHudTextMessage::Init(CHudTextMessage *this)

{
  _func_int_varargs *p_Var1;
  
  (*gEngfuncs.pfnHookUserMsg)("TextMsg",__MsgFunc_TextMsg);
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  p_Var1 = (this->super_CHudBase)._vptr_CHudBase[6];
  if (p_Var1 == CHudBase::Reset) {
    return 1;
  }
  (*p_Var1)(this);
  return 1;
}


// CHudTextMessage::LocaliseTextString  @ 00081d40  (line 48)

char * CHudTextMessage::LocaliseTextString(char *msg,char *dst_buffer,int buffer_size)

{
  char cVar1;
  client_textmessage_s *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: char * dst@[???] */
                    /* Unresolved local var: char * src@[???] */
  cVar1 = *msg;
  pcVar4 = dst_buffer;
  iVar6 = buffer_size;
  do {
    while( true ) {
      if ((iVar6 < 1) || (cVar1 == '\0')) {
        dst_buffer[buffer_size + -1] = '\0';
        return dst_buffer;
      }
      if (cVar1 == '#') break;
      *pcVar4 = cVar1;
      pcVar4[1] = '\0';
LAB_00081d6f:
                    /* Unresolved local var: char * wdst@[???]
                       Unresolved local var: char * word_start@[???]
                       Unresolved local var: client_textmessage_t * clmsg@[???] */
      cVar1 = msg[1];
      msg = msg + 1;
      pcVar4 = pcVar4 + 1;
      iVar6 = iVar6 + -1;
    }
    pcVar3 = LocaliseTextString::lexical_block_0::lexical_block_0_0::word_buf;
    cVar1 = msg[1];
    pcVar5 = msg + 1;
    if (0x39 < (byte)(cVar1 + 0xbfU)) goto LAB_00081dc1;
    do {
      do {
        *pcVar3 = cVar1;
        pcVar5 = pcVar5 + 1;
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar5;
      } while ((byte)(cVar1 + 0xbfU) < 0x3a);
LAB_00081dc1:
    } while ((byte)(cVar1 - 0x30U) < 10);
    *pcVar3 = '\0';
    pcVar2 = (*gEngfuncs.pfnTextMessageGet)
                       (LocaliseTextString::lexical_block_0::lexical_block_0_0::word_buf);
    if ((pcVar2 == (client_textmessage_s *)0x0) ||
       (pcVar3 = pcVar2->pMessage, pcVar3 == (char *)0x0)) {
      *pcVar4 = *msg;
      goto LAB_00081d6f;
    }
    for (; *pcVar3 != '\0'; pcVar3 = pcVar3 + 1) {
                    /* Unresolved local var: char * wsrc@[???] */
      *pcVar4 = *pcVar3;
      pcVar4 = pcVar4 + 1;
    }
    iVar6 = iVar6 + -1;
    *pcVar4 = '\0';
    cVar1 = *pcVar5;
    msg = pcVar5;
  } while( true );
}


// CHudTextMessage::BufferedLocaliseTextString  @ 00081e40  (line 95)

char * CHudTextMessage::BufferedLocaliseTextString(char *msg)

{
  char cVar1;
  client_textmessage_s *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: char * dst@[???]
                       Unresolved local var: char * src@[???] */
  cVar1 = *msg;
  if (cVar1 != '\0') {
    pcVar4 = BufferedLocaliseTextString::dst_buffer;
    iVar5 = 0x400;
    do {
      if (cVar1 == '#') {
        pcVar3 = LocaliseTextString::lexical_block_0::lexical_block_0_0::word_buf;
        cVar1 = msg[1];
        pcVar6 = msg + 1;
        if (0x39 < (byte)(cVar1 + 0xbfU)) goto LAB_00081eb1;
        do {
          do {
            *pcVar3 = cVar1;
            pcVar6 = pcVar6 + 1;
            pcVar3 = pcVar3 + 1;
            cVar1 = *pcVar6;
          } while ((byte)(cVar1 + 0xbfU) < 0x3a);
LAB_00081eb1:
        } while ((byte)(cVar1 - 0x30U) < 10);
        *pcVar3 = '\0';
        pcVar2 = (*gEngfuncs.pfnTextMessageGet)
                           (LocaliseTextString::lexical_block_0::lexical_block_0_0::word_buf);
        if ((pcVar2 == (client_textmessage_s *)0x0) ||
           (pcVar3 = pcVar2->pMessage, pcVar3 == (char *)0x0)) {
          *pcVar4 = *msg;
          goto LAB_00081e6f;
        }
        for (; *pcVar3 != '\0'; pcVar3 = pcVar3 + 1) {
                    /* Unresolved local var: char * wsrc@[???] */
          *pcVar4 = *pcVar3;
          pcVar4 = pcVar4 + 1;
        }
        *pcVar4 = '\0';
        cVar1 = *pcVar6;
        msg = pcVar6;
      }
      else {
        *pcVar4 = cVar1;
        pcVar4[1] = '\0';
LAB_00081e6f:
                    /* Unresolved local var: char * wdst@[???]
                       Unresolved local var: char * word_start@[???]
                       Unresolved local var: client_textmessage_t * clmsg@[???] */
        msg = msg + 1;
        pcVar4 = pcVar4 + 1;
        cVar1 = *msg;
      }
    } while ((iVar5 != 1) && (iVar5 = iVar5 + -1, cVar1 != '\0'));
  }
  BufferedLocaliseTextString::dst_buffer[0x3ff] = '\0';
  return BufferedLocaliseTextString::dst_buffer;
}


// CHudTextMessage::LookupString  @ 00081f20  (line 103)

/* DWARF original prototype: char * LookupString(CHudTextMessage * this, char * msg, int * msg_dest)
    */

char * __thiscall CHudTextMessage::LookupString(CHudTextMessage *this,char *msg,int *msg_dest)

{
  client_textmessage_s *pcVar1;
  char *pcVar2;
  
  if (msg == (char *)0x0) {
    return "";
  }
                    /* Unresolved local var: client_textmessage_t * clmsg@[???] */
  if (((*msg == '#') &&
      (pcVar1 = (*gEngfuncs.pfnTextMessageGet)(msg + 1), pcVar1 != (client_textmessage_s *)0x0)) &&
     (pcVar2 = pcVar1->pMessage, pcVar2 != (char *)0x0)) {
    if ((msg_dest != (int *)0x0) && (pcVar1->effect < 0)) {
      *msg_dest = -pcVar1->effect;
      pcVar2 = pcVar1->pMessage;
    }
    return pcVar2;
  }
  return msg;
}


// StripEndNewlineFromString  @ 00081f90  (line 133)

void StripEndNewlineFromString(char *str)

{
  char cVar1;
  size_t sVar2;
  
                    /* Unresolved local var: int s@[???] */
  sVar2 = strlen(str);
  cVar1 = str[sVar2 - 1];
  if ((cVar1 != '\n') && (cVar1 != '\r')) {
    return;
  }
  str[sVar2 - 1] = '\0';
  return;
}


// ConvertCRtoNL  @ 00081fc0  (line 142)

char * ConvertCRtoNL(char *str)

{
  char *pcVar1;
  char cVar2;
  
  pcVar1 = str;
                    /* Unresolved local var: char * ch@[???] */
  cVar2 = *str;
  do {
    if (cVar2 == '\0') {
      return pcVar1;
    }
    while (cVar2 != '\r') {
      str = str + 1;
      cVar2 = *str;
      if (cVar2 == '\0') {
        return pcVar1;
      }
    }
    *str = '\n';
    str = str + 1;
    cVar2 = *str;
  } while( true );
}


// CHudTextMessage::MsgFunc_TextMsg  @ 00081ff0  (line 162)

/* DWARF original prototype: int MsgFunc_TextMsg(CHudTextMessage * this, char * pszName, int iSize,
   void * pbuf) */

int __thiscall
CHudTextMessage::MsgFunc_TextMsg(CHudTextMessage *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  client_textmessage_s *pcVar7;
  char cVar8;
  char *pcVar9;
  
                    /* Unresolved local var: int msg_dest@[???]
                       Unresolved local var: char * msg_text@[???]
                       Unresolved local var: char * sstr1@[???]
                       Unresolved local var: char * sstr2@[???]
                       Unresolved local var: char * sstr3@[???]
                       Unresolved local var: char * sstr4@[???]
                       Unresolved local var: char * psz@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar3 = READ_BYTE();
  pcVar4 = READ_STRING();
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[???] */
    if ((((*pcVar4 == '#') &&
         (pcVar7 = (*gEngfuncs.pfnTextMessageGet)(pcVar4 + 1), pcVar7 != (client_textmessage_s *)0x0
         )) && (pcVar9 = pcVar7->pMessage, pcVar9 != (char *)0x0)) &&
       (pcVar4 = pcVar9, pcVar7->effect < 0)) {
      iVar3 = -pcVar7->effect;
    }
  }
  strncpy(MsgFunc_TextMsg::szBuf[0],pcVar4,0x80);
  MsgFunc_TextMsg::szBuf[0][0x7f] = '\0';
  pcVar4 = READ_STRING();
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[???] */
    if (((*pcVar4 == '#') &&
        (pcVar7 = (*gEngfuncs.pfnTextMessageGet)(pcVar4 + 1), pcVar7 != (client_textmessage_s *)0x0)
        ) && (pcVar7->pMessage != (char *)0x0)) {
      pcVar4 = pcVar7->pMessage;
    }
  }
  strncpy(MsgFunc_TextMsg::szBuf[1],pcVar4,0x80);
                    /* Unresolved local var: int s@[???] */
  MsgFunc_TextMsg::szBuf[1][0x7f] = '\0';
  pcVar4 = MsgFunc_TextMsg::szBuf[1];
  do {
    pcVar9 = pcVar4;
    uVar5 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar6 = uVar5 & 0x80808080;
    pcVar4 = pcVar9 + 4;
  } while (uVar6 == 0);
  if ((uVar5 & 0x8080) == 0) {
    pcVar4 = pcVar9 + 6;
    uVar6 = uVar6 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar6,(byte)uVar6);
  if ((pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] == '\n') ||
     (pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] == '\r')) {
    pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] = '\0';
  }
  pcVar4 = READ_STRING();
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[???] */
    if (((*pcVar4 == '#') &&
        (pcVar7 = (*gEngfuncs.pfnTextMessageGet)(pcVar4 + 1), pcVar7 != (client_textmessage_s *)0x0)
        ) && (pcVar7->pMessage != (char *)0x0)) {
      pcVar4 = pcVar7->pMessage;
    }
  }
  strncpy(MsgFunc_TextMsg::szBuf[2],pcVar4,0x80);
                    /* Unresolved local var: int s@[???] */
  MsgFunc_TextMsg::szBuf[2][0x7f] = '\0';
  pcVar4 = MsgFunc_TextMsg::szBuf[2];
  do {
    pcVar9 = pcVar4;
    uVar5 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar6 = uVar5 & 0x80808080;
    pcVar4 = pcVar9 + 4;
  } while (uVar6 == 0);
  if ((uVar5 & 0x8080) == 0) {
    pcVar4 = pcVar9 + 6;
    uVar6 = uVar6 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar6,(byte)uVar6);
  if ((pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] == '\n') ||
     (pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] == '\r')) {
    pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] = '\0';
  }
  pcVar4 = READ_STRING();
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[???] */
    if (((*pcVar4 == '#') &&
        (pcVar7 = (*gEngfuncs.pfnTextMessageGet)(pcVar4 + 1), pcVar7 != (client_textmessage_s *)0x0)
        ) && (pcVar7->pMessage != (char *)0x0)) {
      pcVar4 = pcVar7->pMessage;
    }
  }
  strncpy(MsgFunc_TextMsg::szBuf[3],pcVar4,0x80);
                    /* Unresolved local var: int s@[???] */
  MsgFunc_TextMsg::szBuf[3][0x7f] = '\0';
  pcVar4 = MsgFunc_TextMsg::szBuf[3];
  do {
    pcVar9 = pcVar4;
    uVar5 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar6 = uVar5 & 0x80808080;
    pcVar4 = pcVar9 + 4;
  } while (uVar6 == 0);
  if ((uVar5 & 0x8080) == 0) {
    pcVar4 = pcVar9 + 6;
    uVar6 = uVar6 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar6,(byte)uVar6);
  if ((pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] == '\n') ||
     (pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] == '\r')) {
    pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] = '\0';
  }
  pcVar4 = READ_STRING();
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[???] */
    if (((*pcVar4 == '#') &&
        (pcVar7 = (*gEngfuncs.pfnTextMessageGet)(pcVar4 + 1), pcVar7 != (client_textmessage_s *)0x0)
        ) && (pcVar7->pMessage != (char *)0x0)) {
      pcVar4 = pcVar7->pMessage;
    }
  }
  strncpy(MsgFunc_TextMsg::szBuf[4],pcVar4,0x80);
                    /* Unresolved local var: int s@[???] */
  MsgFunc_TextMsg::szBuf[4][0x7f] = '\0';
  pcVar4 = MsgFunc_TextMsg::szBuf[4];
  do {
    pcVar9 = pcVar4;
    uVar5 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar6 = uVar5 & 0x80808080;
    pcVar4 = pcVar9 + 4;
  } while (uVar6 == 0);
  if ((uVar5 & 0x8080) == 0) {
    pcVar4 = pcVar9 + 6;
    uVar6 = uVar6 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar6,(byte)uVar6);
  if ((pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] == '\n') ||
     (pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] == '\r')) {
    pcVar4[(int)MsgFunc_TextMsg::szBuf + iVar1 + -0x10e544] = '\0';
  }
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar2 = TeamFortressViewport::AllowedToPrintText(gViewPort), bVar2)) {
    if (iVar3 == 2) {
      safe_sprintf(MsgFunc_TextMsg::szBuf[5],0x80,MsgFunc_TextMsg::szBuf[0],0x10e5c0,0x10e640,
                   0x10e6c0,0x10e740);
                    /* Unresolved local var: char * ch@[???] */
      pcVar4 = MsgFunc_TextMsg::szBuf[5];
      cVar8 = MsgFunc_TextMsg::szBuf[5][0];
      while (cVar8 != '\0') {
        if (cVar8 == '\r') {
          *pcVar4 = '\n';
        }
        pcVar4 = pcVar4 + 1;
        cVar8 = *pcVar4;
      }
LAB_00082398:
      (*gEngfuncs.pfnConsolePrint)((char *)0x10e7c0);
      return 1;
    }
    if (iVar3 < 3) {
      if (iVar3 == 1) {
        MsgFunc_TextMsg::szBuf[5][0] = '\x01';
        safe_sprintf(MsgFunc_TextMsg::szBuf[5] + 1,0x7f,MsgFunc_TextMsg::szBuf[0],0x10e5c0,0x10e640,
                     0x10e6c0,0x10e740);
                    /* Unresolved local var: char * ch@[???] */
        pcVar4 = MsgFunc_TextMsg::szBuf[5];
        cVar8 = MsgFunc_TextMsg::szBuf[5][0];
        while (cVar8 != '\0') {
          while (cVar8 != '\r') {
            pcVar4 = pcVar4 + 1;
            cVar8 = *pcVar4;
            if (cVar8 == '\0') goto LAB_00082398;
          }
          *pcVar4 = '\n';
          pcVar4 = pcVar4 + 1;
          cVar8 = *pcVar4;
        }
        goto LAB_00082398;
      }
    }
    else {
      if (iVar3 == 3) {
        safe_sprintf(MsgFunc_TextMsg::szBuf[5],0x80,MsgFunc_TextMsg::szBuf[0],0x10e5c0,0x10e640,
                     0x10e6c0,0x10e740);
                    /* Unresolved local var: char * ch@[???] */
        pcVar4 = MsgFunc_TextMsg::szBuf[5];
        cVar8 = MsgFunc_TextMsg::szBuf[5][0];
        while (cVar8 != '\0') {
          while (cVar8 != '\r') {
            pcVar4 = pcVar4 + 1;
            cVar8 = *pcVar4;
            if (cVar8 == '\0') goto LAB_00082420;
          }
          *pcVar4 = '\n';
          pcVar4 = pcVar4 + 1;
          cVar8 = *pcVar4;
        }
LAB_00082420:
        CHudSayText::SayTextPrint(&gHUD.m_SayText,MsgFunc_TextMsg::szBuf[5],0x80,-1);
        return 1;
      }
      if (iVar3 == 4) {
        safe_sprintf(MsgFunc_TextMsg::szBuf[5],0x80,MsgFunc_TextMsg::szBuf[0],0x10e5c0,0x10e640,
                     0x10e6c0,0x10e740);
                    /* Unresolved local var: char * ch@[???] */
        pcVar4 = MsgFunc_TextMsg::szBuf[5];
        cVar8 = MsgFunc_TextMsg::szBuf[5][0];
        while (cVar8 != '\0') {
          while (cVar8 != '\r') {
            pcVar4 = pcVar4 + 1;
            cVar8 = *pcVar4;
            if (cVar8 == '\0') goto LAB_00082308;
          }
          *pcVar4 = '\n';
          pcVar4 = pcVar4 + 1;
          cVar8 = *pcVar4;
        }
LAB_00082308:
        (*gEngfuncs.pfnCenterPrint)((char *)0x10e7c0);
      }
    }
  }
  return 1;
}


