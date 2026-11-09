// Ghidra decompilation of functions from cl_dll/hud_msg.cpp
// 6 functions, ordered by original source line

// CHud::MsgFunc_ResetHUD  @ 0006fd70  (line 41)

/* DWARF original prototype: int MsgFunc_ResetHUD(CHud * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHud::MsgFunc_ResetHUD(CHud *this,char *pszName,int iSize,void *pbuf)

{
  HUDLIST *pHVar1;
  CHudBase *pCVar2;
  
                    /* Unresolved local var: HUDLIST * pList@[???] */
  for (pHVar1 = this->m_pHudList; pHVar1 != (HUDLIST *)0x0; pHVar1 = pHVar1->pNext) {
    pCVar2 = pHVar1->p;
    if (pCVar2 != (CHudBase *)0x0) {
      (*pCVar2->_vptr_CHudBase[6])(pCVar2);
    }
  }
  this->m_flMouseSensitivity = 0.0;
  this->m_iConcussionEffect = 0;
  return 1;
}


// CHud::MsgFunc_ViewMode  @ 0006fdb0  (line 67)

/* DWARF original prototype: void MsgFunc_ViewMode(CHud * this, char * pszName, int iSize, void *
   pbuf) */

void __thiscall CHud::MsgFunc_ViewMode(CHud *this,char *pszName,int iSize,void *pbuf)

{
  cam_thirdperson = 0;
  (*gEngfuncs.Cvar_SetValue)("cam_command",0.0);
  return;
}


// CHud::MsgFunc_InitHUD  @ 0006fdc0  (line 71)

/* DWARF original prototype: void MsgFunc_InitHUD(CHud * this, char * pszName, int iSize, void *
   pbuf) */

void __thiscall CHud::MsgFunc_InitHUD(CHud *this,char *pszName,int iSize,void *pbuf)

{
  HUDLIST *pHVar1;
  CHudBase *pCVar2;
  
                    /* Unresolved local var: HUDLIST * pList@[???] */
  for (pHVar1 = this->m_pHudList; pHVar1 != (HUDLIST *)0x0; pHVar1 = pHVar1->pNext) {
    pCVar2 = pHVar1->p;
    if (pCVar2 != (CHudBase *)0x0) {
      (*pCVar2->_vptr_CHudBase[7])(pCVar2);
    }
  }
  ClearEventList();
  (*gEngfuncs.pfnServerCmd)("sendevents");
  if (g_pParticleMan == (IParticleMan *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0006fe0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[5])();
  return;
}


// CHud::MsgFunc_GameMode  @ 0006fe20  (line 100)

/* DWARF original prototype: int MsgFunc_GameMode(CHud * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHud::MsgFunc_GameMode(CHud *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_Teamplay = iVar1;
  if (iVar1 == 0) {
    (*gEngfuncs.pfnClientCmd)("richpresence_gamemode\n");
  }
  else {
    (*gEngfuncs.pfnClientCmd)("richpresence_gamemode Teamplay\n");
  }
  (*gEngfuncs.pfnClientCmd)("richpresence_update\n");
  return 1;
}


// CHud::MsgFunc_Damage  @ 0006fe80  (line 116)

/* DWARF original prototype: int MsgFunc_Damage(CHud * this, char * pszName, int iSize, void * pbuf)
    */

int __thiscall CHud::MsgFunc_Damage(CHud *this,char *pszName,int iSize,void *pbuf)

{
                    /* Unresolved local var: int armor@[???]
                       Unresolved local var: int blood@[???]
                       Unresolved local var: Vector from@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float count@[???] */
  BEGIN_READ(pbuf,iSize);
  READ_BYTE();
  READ_BYTE();
  READ_COORD();
  READ_COORD();
  READ_COORD();
  return 1;
}


// CHud::MsgFunc_Concuss  @ 0006fec0  (line 140)

/* DWARF original prototype: int MsgFunc_Concuss(CHud * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHud::MsgFunc_Concuss(CHud *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_iConcussionEffect = iVar1;
  if (iVar1 == 0) {
    CHudStatusIcons::DisableIcon(&this->m_StatusIcons,"dmg_concuss");
    return 1;
  }
  CHudStatusIcons::EnableIcon(&this->m_StatusIcons,"dmg_concuss",0xff,0xa0,'\0');
  return 1;
}


