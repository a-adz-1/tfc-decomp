// CHud::MsgFunc_Concuss  @ 00094bb0
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


// CHud::MsgFunc_Damage  @ 00094b70
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


// CHud::MsgFunc_GameMode  @ 00094b40
/* DWARF original prototype: int MsgFunc_GameMode(CHud * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHud::MsgFunc_GameMode(CHud *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_Teamplay = iVar1;
  return 1;
}


// CHud::MsgFunc_InitHUD  @ 00094ae0
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
                    /* WARNING: Could not recover jumptable at 0x00094b2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[5])();
  return;
}


// CHud::MsgFunc_Logo  @ 00083490
/* DWARF original prototype: int MsgFunc_Logo(CHud * this, char * pszName, int iSize, void * pbuf)
    */

int __thiscall CHud::MsgFunc_Logo(CHud *this,char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  this->m_iLogo = iVar1;
  return 1;
}


// CHud::MsgFunc_ResetHUD  @ 00094a90
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


// CHud::MsgFunc_SetFOV  @ 00083680
/* DWARF original prototype: int MsgFunc_SetFOV(CHud * this, char * pszName, int iSize, void * pbuf)
    */

int __thiscall CHud::MsgFunc_SetFOV(CHud *this,char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  longdouble lVar5;
  
                    /* Unresolved local var: int newfov@[???]
                       Unresolved local var: int def_fov@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar3 = READ_BYTE();
  lVar5 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("default_fov");
  if ((cl_lw == (cvar_t *)0x0) || (cl_lw->value == 0.0)) {
    fVar2 = (float)iVar3;
    iVar4 = (int)lVar5;
    g_lastFOV = fVar2;
    if (iVar3 == 0) {
      this->m_iFOV = iVar4;
    }
    else {
      this->m_iFOV = iVar3;
      if (iVar3 != iVar4) {
        fVar1 = sensitivity->value;
        lVar5 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("zoom_sensitivity_ratio");
        this->m_flMouseSensitivity = (float)((longdouble)((fVar2 / (float)iVar4) * fVar1) * lVar5);
        return 1;
      }
    }
    this->m_flMouseSensitivity = 0.0;
  }
  return 1;
}


// CHud::MsgFunc_ViewMode  @ 00094ad0
/* DWARF original prototype: void MsgFunc_ViewMode(CHud * this, char * pszName, int iSize, void *
   pbuf) */

void __thiscall CHud::MsgFunc_ViewMode(CHud *this,char *pszName,int iSize,void *pbuf)

{
  cam_thirdperson = 0;
  (*gEngfuncs.Cvar_SetValue)("cam_command",0.0);
  return;
}


