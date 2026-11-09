// CHudMessage::MsgFunc_GameTitle  @ 0009d160
/* DWARF original prototype: int MsgFunc_GameTitle(CHudMessage * this, char * pszName, int iSize,
   void * pbuf) */

int __thiscall CHudMessage::MsgFunc_GameTitle(CHudMessage *this,char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  client_textmessage_s *pcVar2;
  
  pcVar2 = (*gEngfuncs.pfnTextMessageGet)("GAMETITLE");
  this->m_pGameTitle = pcVar2;
  if (pcVar2 != (client_textmessage_s *)0x0) {
    this->m_gameTitleTime = gHUD.m_flTime;
    uVar1 = (this->super_CHudBase).m_iFlags;
    if ((uVar1 & 1) == 0) {
      (this->super_CHudBase).m_iFlags = uVar1 | 1;
    }
  }
  return 1;
}


// CHudMessage::MsgFunc_HudText  @ 0009d100
/* DWARF original prototype: int MsgFunc_HudText(CHudMessage * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudMessage::MsgFunc_HudText(CHudMessage *this,char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  char *pName;
  
                    /* Unresolved local var: char * pString@[???] */
  BEGIN_READ(pbuf,iSize);
  pName = READ_STRING();
  MessageAdd(this,pName,gHUD.m_flTime);
  (this->m_parms).time = gHUD.m_flTime;
  uVar1 = (this->super_CHudBase).m_iFlags;
  if ((uVar1 & 1) == 0) {
    (this->super_CHudBase).m_iFlags = uVar1 | 1;
  }
  return 1;
}


