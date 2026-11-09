// CBaseUI::Key_Event  @ 0021cd40
/* DWARF original prototype: int Key_Event(CBaseUI * this, int down, int keynum, char *
   pszCurrentBinding) */

int __thiscall CBaseUI::Key_Event(CBaseUI *this,int down,int keynum,char *pszCurrentBinding)

{
  char cVar1;
  uint uVar2;
  ISurface *pIVar3;
  char *pcVar4;
  
  if ((toggleconsole_key == 0) || (uVar2 = 0, toggleconsole_key != keynum)) {
    if ((keynum != 0x1b) || (down == 0)) {
      if (((this->m_bHidingGameUI != false) && (keynum == 0xf1)) && (down != 0)) {
        this->m_bHidingGameUI = false;
        return 1;
      }
      pIVar3 = vgui2::surface();
      uVar2 = (*(pIVar3->super_IBaseInterface)._vptr_IBaseInterface[0x55])(pIVar3);
      uVar2 = uVar2 & 0xff;
    }
    else {
                    /* Unresolved local var: char * levelName@[???] */
      pcVar4 = (*gEngfuncs.pfnGetLevelName)();
      cVar1 = (**(code **)(*(int *)staticGameUIFuncs + 0x30))(staticGameUIFuncs);
      if (((cVar1 == '\0') || (pcVar4 == (char *)0x0)) || (*pcVar4 == '\0')) {
        (*(this->super_IBaseUI).super_IBaseInterface._vptr_IBaseInterface[9])(this);
        return 1;
      }
      (*(this->super_IBaseUI).super_IBaseInterface._vptr_IBaseInterface[8])(this);
      uVar2 = 1;
    }
  }
  return uVar2;
}


