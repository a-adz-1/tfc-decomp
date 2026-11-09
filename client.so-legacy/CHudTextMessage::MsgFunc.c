// CHudTextMessage::MsgFunc_TextMsg  @ 000a6a90
/* DWARF original prototype: int MsgFunc_TextMsg(CHudTextMessage * this, char * pszName, int iSize,
   void * pbuf) */

int __thiscall
CHudTextMessage::MsgFunc_TextMsg(CHudTextMessage *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  client_textmessage_s *pcVar8;
  char *pcVar9;
  
                    /* Unresolved local var: int msg_dest@[???]
                       Unresolved local var: char * msg_text@[???]
                       Unresolved local var: char * sstr1@[???]
                       Unresolved local var: char * sstr2@[???]
                       Unresolved local var: char * sstr3@[???]
                       Unresolved local var: char * sstr4@[???]
                       Unresolved local var: char * psz@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar4 = READ_BYTE();
  pcVar5 = READ_STRING();
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[DW_OP_reg0(EAX)] */
    if ((((*pcVar5 == '#') &&
         (pcVar8 = (*gEngfuncs.pfnTextMessageGet)(pcVar5 + 1), pcVar8 != (client_textmessage_s *)0x0
         )) && (pcVar9 = pcVar8->pMessage, pcVar9 != (char *)0x0)) &&
       (pcVar5 = pcVar9, pcVar8->effect < 0)) {
      iVar4 = -pcVar8->effect;
    }
  }
  strncpy(MsgFunc_TextMsg::lexical_block_0::szBuf[0],pcVar5,0x80);
  MsgFunc_TextMsg::lexical_block_0::szBuf[0][0x7f] = '\0';
  pcVar5 = READ_STRING();
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[DW_OP_reg0(EAX)] */
    if (((*pcVar5 == '#') &&
        (pcVar8 = (*gEngfuncs.pfnTextMessageGet)(pcVar5 + 1), pcVar8 != (client_textmessage_s *)0x0)
        ) && (pcVar8->pMessage != (char *)0x0)) {
      pcVar5 = pcVar8->pMessage;
    }
  }
  strncpy(MsgFunc_TextMsg::lexical_block_0::szBuf[1],pcVar5,0x80);
                    /* Unresolved local var: int s@[???] */
  MsgFunc_TextMsg::lexical_block_0::szBuf[1][0x7f] = '\0';
  pcVar5 = MsgFunc_TextMsg::lexical_block_0::szBuf[1];
  do {
    pcVar9 = pcVar5;
    uVar6 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar7 = uVar6 & 0x80808080;
    pcVar5 = pcVar9 + 4;
  } while (uVar7 == 0);
  if ((uVar6 & 0x8080) == 0) {
    pcVar5 = pcVar9 + 6;
    uVar7 = uVar7 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar7,(byte)uVar7);
  if ((pcVar5[iVar1 + -4] == '\r') || (pcVar5[iVar1 + -4] == '\n')) {
    pcVar5[iVar1 + -4] = '\0';
  }
  pcVar5 = READ_STRING();
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[DW_OP_reg0(EAX)] */
    if (((*pcVar5 == '#') &&
        (pcVar8 = (*gEngfuncs.pfnTextMessageGet)(pcVar5 + 1), pcVar8 != (client_textmessage_s *)0x0)
        ) && (pcVar8->pMessage != (char *)0x0)) {
      pcVar5 = pcVar8->pMessage;
    }
  }
  strncpy(MsgFunc_TextMsg::lexical_block_0::szBuf[2],pcVar5,0x80);
                    /* Unresolved local var: int s@[???] */
  MsgFunc_TextMsg::lexical_block_0::szBuf[2][0x7f] = '\0';
  pcVar5 = MsgFunc_TextMsg::lexical_block_0::szBuf[2];
  do {
    pcVar9 = pcVar5;
    uVar6 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar7 = uVar6 & 0x80808080;
    pcVar5 = pcVar9 + 4;
  } while (uVar7 == 0);
  if ((uVar6 & 0x8080) == 0) {
    pcVar5 = pcVar9 + 6;
    uVar7 = uVar7 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar7,(byte)uVar7);
  if ((pcVar5[iVar1 + -4] == '\r') || (pcVar5[iVar1 + -4] == '\n')) {
    pcVar5[iVar1 + -4] = '\0';
  }
  pcVar5 = READ_STRING();
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[DW_OP_reg0(EAX)] */
    if (((*pcVar5 == '#') &&
        (pcVar8 = (*gEngfuncs.pfnTextMessageGet)(pcVar5 + 1), pcVar8 != (client_textmessage_s *)0x0)
        ) && (pcVar8->pMessage != (char *)0x0)) {
      pcVar5 = pcVar8->pMessage;
    }
  }
  strncpy(MsgFunc_TextMsg::lexical_block_0::szBuf[3],pcVar5,0x80);
                    /* Unresolved local var: int s@[???] */
  MsgFunc_TextMsg::lexical_block_0::szBuf[3][0x7f] = '\0';
  pcVar5 = MsgFunc_TextMsg::lexical_block_0::szBuf[3];
  do {
    pcVar9 = pcVar5;
    uVar6 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar7 = uVar6 & 0x80808080;
    pcVar5 = pcVar9 + 4;
  } while (uVar7 == 0);
  if ((uVar6 & 0x8080) == 0) {
    pcVar5 = pcVar9 + 6;
    uVar7 = uVar7 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar7,(byte)uVar7);
  if ((pcVar5[iVar1 + -4] == '\r') || (pcVar5[iVar1 + -4] == '\n')) {
    pcVar5[iVar1 + -4] = '\0';
  }
  pcVar5 = READ_STRING();
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[DW_OP_reg0(EAX)] */
    if (((*pcVar5 == '#') &&
        (pcVar8 = (*gEngfuncs.pfnTextMessageGet)(pcVar5 + 1), pcVar8 != (client_textmessage_s *)0x0)
        ) && (pcVar8->pMessage != (char *)0x0)) {
      pcVar5 = pcVar8->pMessage;
    }
  }
  strncpy(MsgFunc_TextMsg::lexical_block_0::szBuf[4],pcVar5,0x80);
                    /* Unresolved local var: int s@[???] */
  MsgFunc_TextMsg::lexical_block_0::szBuf[4][0x7f] = '\0';
  pcVar5 = MsgFunc_TextMsg::lexical_block_0::szBuf[4];
  do {
    pcVar9 = pcVar5;
    uVar6 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar7 = uVar6 & 0x80808080;
    pcVar5 = pcVar9 + 4;
  } while (uVar7 == 0);
  if ((uVar6 & 0x8080) == 0) {
    pcVar5 = pcVar9 + 6;
    uVar7 = uVar7 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar7,(byte)uVar7);
  if ((pcVar5[iVar1 + -4] == '\r') || (pcVar5[iVar1 + -4] == '\n')) {
    pcVar5[iVar1 + -4] = '\0';
  }
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar2 = TeamFortressViewport::AllowedToPrintText(gViewPort), bVar2)) {
    if (iVar4 == 2) {
      safe_sprintf(MsgFunc_TextMsg::lexical_block_0::szBuf[5],0x80,
                   MsgFunc_TextMsg::lexical_block_0::szBuf[0],0x131540,0x1315c0,0x131640,0x1316c0);
                    /* Unresolved local var: char * ch@[???] */
      if (MsgFunc_TextMsg::lexical_block_0::szBuf[5][0] != '\0') {
        pcVar5 = MsgFunc_TextMsg::lexical_block_0::szBuf[5];
        cVar3 = MsgFunc_TextMsg::lexical_block_0::szBuf[5][0];
        do {
          if (cVar3 == '\r') {
            *pcVar5 = '\n';
          }
          pcVar5 = pcVar5 + 1;
          cVar3 = *pcVar5;
        } while (cVar3 != '\0');
      }
LAB_000a6dc0:
      (*gEngfuncs.pfnConsolePrint)((char *)0x131740);
      return 1;
    }
    if (iVar4 < 3) {
      if (iVar4 == 1) {
        MsgFunc_TextMsg::lexical_block_0::szBuf[5][0] = '\x01';
        safe_sprintf(MsgFunc_TextMsg::lexical_block_0::szBuf[5] + 1,0x80,
                     MsgFunc_TextMsg::lexical_block_0::szBuf[0],0x131540,0x1315c0,0x131640,0x1316c0)
        ;
                    /* Unresolved local var: char * ch@[???] */
        if (MsgFunc_TextMsg::lexical_block_0::szBuf[5][0] != '\0') {
          pcVar5 = MsgFunc_TextMsg::lexical_block_0::szBuf[5];
          cVar3 = MsgFunc_TextMsg::lexical_block_0::szBuf[5][0];
          do {
            while (cVar3 == '\r') {
              *pcVar5 = '\n';
              pcVar5 = pcVar5 + 1;
              cVar3 = *pcVar5;
              if (cVar3 == '\0') goto LAB_000a6dc0;
            }
            pcVar5 = pcVar5 + 1;
            cVar3 = *pcVar5;
          } while (cVar3 != '\0');
        }
        goto LAB_000a6dc0;
      }
    }
    else {
      if (iVar4 == 3) {
        safe_sprintf(MsgFunc_TextMsg::lexical_block_0::szBuf[5],0x80,
                     MsgFunc_TextMsg::lexical_block_0::szBuf[0],0x131540,0x1315c0,0x131640,0x1316c0)
        ;
                    /* Unresolved local var: char * ch@[???] */
        if (MsgFunc_TextMsg::lexical_block_0::szBuf[5][0] != '\0') {
          pcVar5 = MsgFunc_TextMsg::lexical_block_0::szBuf[5];
          cVar3 = MsgFunc_TextMsg::lexical_block_0::szBuf[5][0];
          do {
            while (cVar3 == '\r') {
              *pcVar5 = '\n';
              pcVar5 = pcVar5 + 1;
              cVar3 = *pcVar5;
              if (cVar3 == '\0') goto LAB_000a6fb7;
            }
            pcVar5 = pcVar5 + 1;
            cVar3 = *pcVar5;
          } while (cVar3 != '\0');
        }
LAB_000a6fb7:
        CHudSayText::SayTextPrint
                  (&gHUD.m_SayText,MsgFunc_TextMsg::lexical_block_0::szBuf[5],0x80,-1);
        return 1;
      }
      if (iVar4 == 4) {
        safe_sprintf(MsgFunc_TextMsg::lexical_block_0::szBuf[5],0x80,
                     MsgFunc_TextMsg::lexical_block_0::szBuf[0],0x131540,0x1315c0,0x131640,0x1316c0)
        ;
                    /* Unresolved local var: char * ch@[???] */
        if (MsgFunc_TextMsg::lexical_block_0::szBuf[5][0] != '\0') {
          pcVar5 = MsgFunc_TextMsg::lexical_block_0::szBuf[5];
          cVar3 = MsgFunc_TextMsg::lexical_block_0::szBuf[5][0];
          do {
            while (cVar3 == '\r') {
              *pcVar5 = '\n';
              pcVar5 = pcVar5 + 1;
              cVar3 = *pcVar5;
              if (cVar3 == '\0') goto LAB_000a6e67;
            }
            pcVar5 = pcVar5 + 1;
            cVar3 = *pcVar5;
          } while (cVar3 != '\0');
        }
LAB_000a6e67:
        (*gEngfuncs.pfnCenterPrint)((char *)0x131740);
        return 1;
      }
    }
  }
  return 1;
}


