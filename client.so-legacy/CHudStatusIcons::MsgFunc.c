// CHudStatusIcons::MsgFunc_StatusIcon  @ 0009ee40
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
  icon_sprite_t *piVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
                    /* Unresolved local var: int ShouldEnable@[???]
                       Unresolved local var: char * pszIconName@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  pcVar3 = READ_STRING();
  if (iVar2 == 0) {
                    /* Unresolved local var: int i@[???] */
    iVar2 = strcasecmp(this->m_IconList[0].szSpriteName,pcVar3);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = strcasecmp(this->m_IconList[1].szSpriteName,pcVar3);
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      else {
        iVar2 = strcasecmp(this->m_IconList[2].szSpriteName,pcVar3);
        if (iVar2 == 0) {
          iVar2 = 2;
        }
        else {
          iVar2 = strcasecmp(this->m_IconList[3].szSpriteName,pcVar3);
          if (iVar2 != 0) {
            return 1;
          }
          iVar2 = 3;
        }
      }
    }
    uVar7 = 0x30;
    piVar6 = this->m_IconList + iVar2;
    bVar9 = ((uint)piVar6 & 1) != 0;
    if (bVar9) {
      this->m_IconList[iVar2].szSpriteName[0] = '\0';
      piVar6 = (icon_sprite_t *)(this->m_IconList[iVar2].szSpriteName + 1);
      uVar7 = 0x2f;
    }
    if (((uint)piVar6 & 2) != 0) {
      piVar6->szSpriteName[0] = '\0';
      piVar6->szSpriteName[1] = '\0';
      uVar7 = uVar7 - 2;
      piVar6 = (icon_sprite_t *)(piVar6->szSpriteName + 2);
    }
    uVar8 = 0;
    do {
      pcVar3 = piVar6->szSpriteName + uVar8;
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = piVar6->szSpriteName + uVar8 + 4;
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = piVar6->szSpriteName + uVar8 + 8;
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = piVar6->szSpriteName + uVar8 + 0xc;
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      uVar8 = uVar8 + 0x10;
    } while (uVar8 < (uVar7 & 0xfffffff0));
    pcVar3 = piVar6->szSpriteName + uVar8;
    if ((uVar7 & 8) != 0) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3[4] = '\0';
      pcVar3[5] = '\0';
      pcVar3[6] = '\0';
      pcVar3[7] = '\0';
      pcVar3 = pcVar3 + 8;
    }
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
    if (bVar9) {
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


