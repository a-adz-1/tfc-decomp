// CBaseUI::Key_Event  @ 001d1c20
/* DWARF original prototype: int Key_Event(CBaseUI * this, int down, int keynum, char *
   pszCurrentBinding) */

int __thiscall CBaseUI::Key_Event(CBaseUI *this,int down,int keynum,char *pszCurrentBinding)

{
  char cVar1;
  char *pcVar2;
  ISurface *pIVar3;
  uint uVar4;
  
  if ((toggleconsole_key == keynum) && (toggleconsole_key != 0)) {
    return 0;
  }
  if ((keynum == 0x1b) && (down != 0)) {
                    /* Unresolved local var: char * levelName@[???] */
    pcVar2 = (*gEngfuncs.pfnGetLevelName)();
    cVar1 = (**(code **)(*(int *)staticGameUIFuncs + 0x30))(staticGameUIFuncs);
    if ((pcVar2 != (char *)0x0) && ((cVar1 != '\0' && (*pcVar2 != '\0')))) {
      (*(this->super_IBaseUI).super_IBaseInterface._vptr_IBaseInterface[8])(this);
      return 1;
    }
    (*(this->super_IBaseUI).super_IBaseInterface._vptr_IBaseInterface[9])(this);
    return 1;
  }
  if (((this->m_bHidingGameUI != false) && (keynum == 0xf1)) && (down != 0)) {
    this->m_bHidingGameUI = false;
    return 1;
  }
  pIVar3 = vgui2::surface();
  uVar4 = (*(pIVar3->super_IBaseInterface)._vptr_IBaseInterface[0x55])(pIVar3);
  return uVar4 & 0xff;
}


