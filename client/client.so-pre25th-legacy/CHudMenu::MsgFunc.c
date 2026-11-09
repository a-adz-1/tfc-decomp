// CHudMenu::MsgFunc_ShowMenu  @ 0009a490
/* DWARF original prototype: int MsgFunc_ShowMenu(CHudMenu * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHudMenu::MsgFunc_ShowMenu(CHudMenu *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  char *local_10;
  
                    /* Unresolved local var: char * temp@[???]
                       Unresolved local var: int DisplayTime@[???]
                       Unresolved local var: int NeedMore@[???] */
  local_10 = (char *)0x0;
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_SHORT();
  this->m_bitsValidSlots = iVar2;
  iVar2 = READ_CHAR();
  iVar3 = READ_BYTE();
  if (iVar2 < 1) {
    this->m_flShutoffTime = -1.0;
  }
  else {
    this->m_flShutoffTime = (float)iVar2 + gHUD.m_flTime;
  }
  if (this->m_bitsValidSlots == 0) {
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 & 0xfffffffe;
    this->m_fMenuDisplayed = 0;
  }
  else {
    puVar8 = (uint *)g_szPrelocalisedMenuString;
    if (this->m_fWaitingForMore == 0) {
      pcVar4 = READ_STRING();
      strncpy(g_szPrelocalisedMenuString,pcVar4,0x200);
    }
    else {
      do {
        puVar7 = puVar8;
        uVar5 = *puVar7 + 0xfefefeff & ~*puVar7;
        uVar6 = uVar5 & 0x80808080;
        puVar8 = puVar7 + 1;
      } while (uVar6 == 0);
      if ((uVar5 & 0x8080) == 0) {
        puVar8 = (uint *)((int)puVar7 + 6);
        uVar6 = uVar6 >> 0x10;
      }
      pcVar4 = READ_STRING();
      strncat(g_szPrelocalisedMenuString,pcVar4,
              0x200 - ((int)puVar8 + (-0x12aee3 - (uint)CARRY1((byte)uVar6,(byte)uVar6))));
    }
    g_szPrelocalisedMenuString[0x1ff] = '\0';
    if (iVar3 == 0) {
      g_szPrelocalisedMenuString[0x1ff] = '\0';
      pcVar4 = CHudTextMessage::BufferedLocaliseTextString(g_szPrelocalisedMenuString);
      strcpy(g_szMenuString,pcVar4);
      iVar2 = KB_ConvertString(g_szMenuString,&local_10);
      pcVar4 = local_10;
      if (iVar2 != 0) {
        strcpy(g_szMenuString,local_10);
        free(pcVar4);
      }
    }
    this->m_fMenuDisplayed = 1;
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 | 1;
  }
  this->m_fWaitingForMore = iVar3;
  return 1;
}


