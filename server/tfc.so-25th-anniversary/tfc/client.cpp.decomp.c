// Ghidra decompilation of functions from tfc/client.cpp
// 46 functions, ordered by original source line

// set_suicide_frame  @ 00076ff0  (line 117)

void set_suicide_frame(entvars_t *pev)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar1 = 0x1e;
  bVar4 = gpGlobals->pStringBase + pev->model == (char *)0x0;
  pcVar2 = gpGlobals->pStringBase + pev->model;
  pcVar3 = "models/player/scout/scout.mdl";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    pev->solid = 0;
    pev->movetype = 6;
    pev->deadflag = 2;
    pev->nextthink = -1.0;
  }
  return;
}


// ClientConnect  @ 00077060  (line 136)

BOOL ClientConnect(edict_t *pEntity,char *pszName,char *pszAddress,char *szRejectReason)

{
  int iVar1;
  
  iVar1 = (*g_pGameRules->_vptr_CGameRules[0xb])
                    (g_pGameRules,pEntity,pszName,pszAddress,szRejectReason);
  return iVar1;
}


// ClientDisconnect  @ 000770a0  (line 155)

void ClientDisconnect(edict_t *pEntity)

{
  _func_void_int *p_Var1;
  int iVar2;
  CSound *this;
  int in_GS_OFFSET;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: char[256] text@[???]
                       Unresolved local var: CSound * pSound@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (g_fGameOver == 0) {
    __sprintf_chk(local_110,1,0x100,"- %s has left the game\n",
                  gpGlobals->pStringBase + (pEntity->v).netname);
    (*g_engfuncs.pfnMessageBegin)(2,gmsgSayText,(float *)0x0,(edict_t *)0x0);
    p_Var1 = g_engfuncs.pfnWriteByte;
    iVar2 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
    (*p_Var1)(iVar2);
    (*g_engfuncs.pfnWriteString)(local_110);
    (*g_engfuncs.pfnMessageEnd)();
    iVar2 = CSoundEnt::ClientSoundIndex(pEntity);
    this = CSoundEnt::SoundPointerForIndex(iVar2);
    if (this != (CSound *)0x0) {
      CSound::Reset(this);
    }
    (pEntity->v).solid = 0;
    (pEntity->v).takedamage = 0.0;
    UTIL_SetOrigin(&pEntity->v,&(pEntity->v).origin);
    EMIT_SOUND_DYN(pEntity,4,"player/gib.wav",1.0,0.0,0,100);
    (*g_pGameRules->_vptr_CGameRules[0xd])(g_pGameRules,pEntity);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// respawn  @ 00077230  (line 189)

/* WARNING: Type propagation algorithm not settling */

void respawn(entvars_t *pev,BOOL fCopyCorpse)

{
  CBasePlayer *this;
  edict_t *peVar1;
  
  if (cease_fire != 0) {
    return;
  }
  if ((gpGlobals->coop == 0.0) && (gpGlobals->deathmatch == 0.0)) {
                    /* WARNING: Could not recover jumptable at 0x000772f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnServerCommand)("reload\n");
    return;
  }
  if (fCopyCorpse != 0) {
    CopyToBodyQue(pev);
  }
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity == (edict_t *)0x0) ||
     (this = pev->pContainingEntity->pvPrivateData, this == (CBasePlayer *)0x0)) {
    this = CBaseEntity::operator_new(0xecc,pev);
    CBasePlayer::CBasePlayer(this);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = pev;
  }
                    /* WARNING: Could not recover jumptable at 0x000772b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[2])();
  return;
}


// ClientKill  @ 00077340  (line 221)

void ClientKill(edict_t *pEntity)

{
  CBaseEntity *pCVar1;
  edict_t *peVar2;
  CBasePlayer *this;
  CBaseEntity *this_00;
  
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pl@[???] */
  peVar2 = (pEntity->v).pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar2 == (edict_t *)0x0) &&
     (peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar2 == (edict_t *)0x0)) {
    this_00 = (CBaseEntity *)0x0;
  }
  else {
    this_00 = peVar2->pvPrivateData;
  }
  if (((pEntity->v).playerclass != 0) &&
     ((float)this_00[1].replacement_model_body <= gpGlobals->time)) {
    this_00[1].replacement_model_body = (int)(gpGlobals->time + 5.0);
    (pEntity->v).health = 0.0;
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
    if (((this_00->tfstate & 0x10) != 0) &&
       (pCVar1 = CBaseEntity::FindTimer(this_00,2), pCVar1 != (CBaseEntity *)0x0)) {
                    /* Unresolved local var: CBaseEntity * pEntity@[???] */
      peVar2 = pCVar1->pev->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if ((peVar2 == (edict_t *)0x0) &&
         (peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar2 == (edict_t *)0x0)) {
        this = (CBasePlayer *)0x0;
      }
      else {
        this = peVar2->pvPrivateData;
      }
      CBasePlayer::TF_AddFrags(this,1);
    }
    (*this_00->_vptr_CBaseEntity[0xf])(this_00,0,&pEntity->v,1);
  }
  return;
}


// ClientPutInServer  @ 00077450  (line 266)

/* WARNING: Type propagation algorithm not settling */

void ClientPutInServer(edict_t *pEntity)

{
  int *piVar1;
  int iVar2;
  _2globalvars_t *p1Var3;
  char *pcVar4;
  int iVar5;
  CBasePlayer *this;
  edict_t *peVar6;
  entvars_t *peVar7;
  
  peVar7 = &pEntity->v;
                    /* Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg6(ESI)]
                       Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: char * infobuffer@[???] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (peVar7 == (entvars_t *)0x0) {
    peVar6 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar6 != (edict_t *)0x0) {
      peVar7 = &peVar6->v;
    }
  }
  if ((peVar7->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar7->pContainingEntity->pvPrivateData, this == (CBasePlayer *)0x0)) {
    this = CBaseEntity::operator_new(0xecc,peVar7);
    CBasePlayer::CBasePlayer(this);
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = peVar7;
  }
  CBasePlayer::SetCustomDecalFrames(this,-1);
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.lastpc = 0;
  peVar7->playerclass = 0;
  pcVar4 = (*g_engfuncs.pfnGetInfoKeyBuffer)
                     (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
  (*g_pGameRules->_vptr_CGameRules[0x19])(g_pGameRules,this,pcVar4);
  if (tfc_clanbattle.value != 0.0) {
    CBasePlayer::ConnectDuringBattle(this);
  }
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[2])(this);
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x20;
  p1Var3 = gpGlobals;
                    /* Unresolved local var: int i@[???] */
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.has_disconnected = 0;
  if (-1 < p1Var3->maxClients) {
    iVar5 = 0;
    peVar6 = g_IpStorage[0].pEdict;
    while( true ) {
      if (pEntity == peVar6) {
        iVar2 = g_IpStorage[iVar5].ip;
        g_IpStorage[iVar5].pEdict = (edict_t *)0x0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ip = iVar2;
        g_IpStorage[iVar5].ip = 0;
        return;
      }
      iVar5 = iVar5 + 1;
      if (p1Var3->maxClients < iVar5) break;
      peVar6 = g_IpStorage[iVar5].pEdict;
    }
  }
  return;
}


// FailedSpamCheck  @ 000775a0  (line 309)

int FailedSpamCheck(edict_t *pEntity,int teamonly)

{
  float fVar1;
  float fVar2;
  void *pvVar3;
  _2globalvars_t *p1Var4;
  _func_void_int *p_Var5;
  int iVar6;
  int in_GS_OFFSET;
  char local_4c [60];
  int local_10;
  
                    /* Unresolved local var: CBasePlayer * pTalker@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((pEntity == (edict_t *)0x0) &&
      (pEntity = (*g_engfuncs.pfnPEntityOfEntOffset)(0), pEntity == (edict_t *)0x0)) ||
     (p1Var4 = gpGlobals, pvVar3 = pEntity->pvPrivateData, pvVar3 == (void *)0x0)) {
LAB_00077650:
    iVar6 = 0;
  }
  else {
    fVar1 = *(float *)((int)pvVar3 + 0xe78);
    fVar2 = gpGlobals->time;
    if (fVar2 < fVar1) {
                    /* Unresolved local var: char[60] szMsg@[???]
                       Unresolved local var: int iRemainingTime@[???] */
      fVar1 = fVar1 + tfc_spam_penalty2.value;
      *(float *)((int)pvVar3 + 0xe78) = fVar1;
      __sprintf_chk(local_4c,1,0x3c,"You may not speak for %d seconds for spamming.\n",
                    (int)(fVar1 - p1Var4->time));
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgSayText,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar3 + 4) + 0x208));
      p_Var5 = g_engfuncs.pfnWriteByte;
      iVar6 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(*(int *)((int)pvVar3 + 4) + 0x208));
      (*p_Var5)(iVar6);
      (*g_engfuncs.pfnWriteString)(local_4c);
      (*g_engfuncs.pfnMessageEnd)();
      iVar6 = 1;
      *(float *)((int)pvVar3 + 0xe7c) = gpGlobals->time;
      goto LAB_00077652;
    }
    if (fVar1 == -1.0) {
      iVar6 = *(int *)((int)pvVar3 + 0xe80);
    }
    else {
      iVar6 = 0;
      *(undefined4 *)((int)pvVar3 + 0xe80) = 0;
      *(undefined4 *)((int)pvVar3 + 0xe78) = 0xbf800000;
      fVar2 = p1Var4->time;
    }
    fVar1 = tfc_spam_limit.value;
    fVar2 = fVar2 - *(float *)((int)pvVar3 + 0xe7c);
    if (2.0 <= fVar2) {
      iVar6 = (int)((float)iVar6 - fVar2);
      if (iVar6 < 0) {
        *(undefined4 *)((int)pvVar3 + 0xe80) = 0;
        fVar1 = 0.0;
      }
      else {
        *(int *)((int)pvVar3 + 0xe80) = iVar6;
        fVar1 = (float)iVar6;
      }
LAB_000776ca:
      if (fVar1 <= tfc_spam_limit.value) goto LAB_00077650;
    }
    else {
      if (teamonly != 0) {
        *(int *)((int)pvVar3 + 0xe80) = iVar6 + 1;
        fVar1 = (float)(iVar6 + 1);
        goto LAB_000776ca;
      }
      *(int *)((int)pvVar3 + 0xe80) = iVar6 + 2;
      if ((float)(iVar6 + 2) <= fVar1) goto LAB_00077650;
    }
    iVar6 = 1;
    *(float *)((int)pvVar3 + 0xe78) = p1Var4->time + tfc_spam_penalty1.value;
  }
LAB_00077652:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Host_Say  @ 00077810  (line 384)

void Host_Say(edict_t *pEntity,int teamonly)

{
  char cVar1;
  entvars_t *peVar2;
  _func_int_varargs *p_Var3;
  _2globalvars_t *p1Var4;
  _func_void_int *p_Var5;
  char cVar6;
  bool bVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  size_t sVar13;
  undefined2 *puVar14;
  CBasePlayer *pReceiver;
  void *pvVar15;
  int iVar16;
  char *pcVar17;
  CBaseEntity *pCVar18;
  edict_t *peVar19;
  uint *puVar20;
  uint *puVar21;
  int in_GS_OFFSET;
  longdouble extraout_ST0;
  char *pcVar22;
  CBasePlayer *local_1c0;
  uint local_1a0 [31];
  char acStack_122 [258];
  int local_20;
  
                    /* Unresolved local var: CBasePlayer * client@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[128] text@[???]
                       Unresolved local var: char[256] szTemp@[???]
                       Unresolved local var: char * cpSay@[???]
                       Unresolved local var: char * cpSayTeam@[???]
                       Unresolved local var: char * pcmd@[???]
                       Unresolved local var: float spectChat@[???]
                       Unresolved local var: CBasePlayer * pTalker@[???]
                       Unresolved local var: char * pc@[???]
                       Unresolved local var: char * temp@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar8 = (*g_engfuncs.pfnCmd_Argv)(0);
  (*g_engfuncs.pfnCVarGetFloat)("tfc_spectchat");
  iVar9 = (*g_engfuncs.pfnCmd_Argc)();
  if (iVar9 == 0) goto LAB_00077cc0;
  iVar9 = strcasecmp(pcVar8,"say");
  if ((iVar9 == 0) || (iVar9 = strcasecmp(pcVar8,"say_team"), iVar9 == 0)) {
    iVar9 = (*g_engfuncs.pfnCmd_Argc)();
    if (iVar9 < 2) goto LAB_00077cc0;
    pcVar10 = (*g_engfuncs.pfnCmd_Args)();
  }
  else {
    iVar9 = (*g_engfuncs.pfnCmd_Argc)();
    if (iVar9 < 2) {
      pcVar10 = acStack_122 + 2;
      __sprintf_chk(pcVar10,1,0x100,"%s",pcVar8);
    }
    else {
      pcVar22 = (*g_engfuncs.pfnCmd_Args)();
      pcVar10 = acStack_122 + 2;
      __sprintf_chk(pcVar10,1,0x100,"%s %s",pcVar8,pcVar22);
    }
  }
  iVar9 = FailedSpamCheck(pEntity,teamonly);
  if (iVar9 != 0) goto LAB_00077cc0;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar19 = pEntity;
  if ((pEntity == (edict_t *)0x0) &&
     (peVar19 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar19 == (edict_t *)0x0)) {
    local_1c0 = (CBasePlayer *)0x0;
  }
  else {
    local_1c0 = peVar19->pvPrivateData;
  }
  pcVar8 = pcVar10;
  if (*pcVar10 == '\"') {
    pcVar8 = pcVar10 + 1;
    sVar13 = strlen(pcVar8);
    pcVar10[sVar13] = '\0';
  }
  if (pcVar8 != (char *)0x0) {
    cVar6 = *pcVar8;
    cVar1 = cVar6;
    pcVar10 = pcVar8;
    while (cVar1 != '\0') {
      iVar9 = isprint((int)cVar1);
      if (((iVar9 != 0) && (iVar9 = isspace((int)cVar1), iVar9 == 0)) ||
         (pcVar10 = pcVar10 + 1, pcVar10 == (char *)0x0)) {
                    /* Unresolved local var: char * pApersand@[???] */
        pcVar10 = pcVar8 + 2;
        goto LAB_0007793e;
      }
      cVar1 = *pcVar10;
    }
    goto LAB_00077cc0;
  }
  goto LAB_00077954;
  while( true ) {
    if (pcVar10 == (char *)0x1) break;
    cVar6 = pcVar10[-1];
    pcVar10 = pcVar10 + 1;
    if (cVar6 == '\0') break;
LAB_0007793e:
    if (cVar6 == '%') {
      sVar13 = strlen(pcVar8);
      if (0x7c < sVar13) break;
      cVar6 = pcVar10[-1];
      if (cVar6 == 'h') {
                    /* Unresolved local var: int iValue@[???] */
        pcVar10[-2] = '\0';
        pcVar22 = UTIL_VarArgs("%d%s",(int)((local_1c0->super_CBaseMonster).super_CBaseToggle.
                                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                           pev)->health,pcVar10);
        strcat(pcVar8,pcVar22);
        cVar6 = pcVar10[-1];
      }
      if (cVar6 == 'a') {
                    /* Unresolved local var: int iValue@[???] */
        pcVar10[-2] = '\0';
        pcVar22 = UTIL_VarArgs("%d%s",(int)((local_1c0->super_CBaseMonster).super_CBaseToggle.
                                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                           pev)->armorvalue,pcVar10);
        strcat(pcVar8,pcVar22);
        cVar6 = pcVar10[-1];
      }
      if (cVar6 == 'i') {
        pcVar10[-2] = '\0';
        iVar9 = EHANDLE::operator_int(&local_1c0->m_hLastIDTarget);
        if (iVar9 == 0) {
          pcVar22 = UTIL_VarArgs("%s",pcVar10);
          strcat(pcVar8,pcVar22);
        }
        else {
          pcVar22 = gpGlobals->pStringBase;
          pCVar18 = EHANDLE::operator->(&local_1c0->m_hLastIDTarget);
          pcVar22 = UTIL_VarArgs("%s%s",pcVar22 + pCVar18->pev->netname,pcVar10);
          strcat(pcVar8,pcVar22);
        }
      }
    }
  }
LAB_00077954:
  p1Var4 = gpGlobals;
  peVar2 = (local_1c0->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_1c0->m_flLastTalkTime = gpGlobals->time;
  if (peVar2->iuser1 == 0) {
    if (teamonly == 0) goto LAB_0007799d;
    pcVar22 = "%c(TEAM) %s: ";
    pcVar10 = p1Var4->pStringBase + (pEntity->v).netname;
  }
  else if (((float)extraout_ST0 == 0.0) || (teamonly != 0)) {
    pcVar22 = "%c(SPEC) %s: ";
    pcVar10 = p1Var4->pStringBase + (pEntity->v).netname;
  }
  else {
LAB_0007799d:
    pcVar22 = "%c%s: ";
    pcVar10 = p1Var4->pStringBase + (pEntity->v).netname;
  }
  __sprintf_chk(local_1a0,1,0x80,pcVar22,2,pcVar10);
  puVar20 = local_1a0;
  do {
    puVar21 = puVar20;
    uVar11 = *puVar21 + 0xfefefeff & ~*puVar21;
    uVar12 = uVar11 & 0x80808080;
    puVar20 = puVar21 + 1;
  } while (uVar12 == 0);
  if ((uVar11 & 0x8080) == 0) {
    puVar20 = (uint *)((int)puVar21 + 6);
    uVar12 = uVar12 >> 0x10;
  }
  sVar13 = strlen(pcVar8);
  puVar21 = local_1a0;
  if ((int)(acStack_122 + -(int)((int)puVar20 + (-3 - (uint)CARRY1((byte)uVar12,(byte)uVar12)))) <
      (int)sVar13) {
    pcVar8[(int)(acStack_122 + -(int)((int)puVar20 + (-3 - (uint)CARRY1((byte)uVar12,(byte)uVar12)))
                )] = '\0';
  }
  do {
    puVar20 = puVar21;
    uVar11 = *puVar20 + 0xfefefeff & ~*puVar20;
    uVar12 = uVar11 & 0x80808080;
    puVar21 = puVar20 + 1;
  } while (uVar12 == 0);
  if ((uVar11 & 0x8080) == 0) {
    puVar21 = (uint *)((int)puVar20 + 6);
    uVar12 = uVar12 >> 0x10;
  }
  puVar14 = (undefined2 *)
            __stpcpy_chk((char *)((int)puVar21 + (-3 - (uint)CARRY1((byte)uVar12,(byte)uVar12))),
                         pcVar8,0x80);
  *puVar14 = 10;
                    /* Unresolved local var: int i@[???] */
  if (0 < gpGlobals->maxClients) {
    iVar9 = 1;
    do {
      pReceiver = UTIL_PlayerByIndex(iVar9);
      if (((pReceiver != (CBasePlayer *)0x0) &&
          (peVar2 = (pReceiver->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev, pEntity != peVar2->pContainingEntity))
         && (((peVar2->flags & 8) != 0 &&
             (bVar7 = CVoiceGameMgr::PlayerHasBlockedPlayer
                                ((CVoiceGameMgr *)(g_pGameRules + 6),pReceiver,local_1c0), !bVar7)))
         ) {
        iVar16 = ((local_1c0->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->iuser1;
        if ((iVar16 == 0) && (teamonly != 0)) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
          p_Var3 = g_pGameRules->_vptr_CGameRules[0x32];
          peVar19 = pEntity;
          if (pEntity == (edict_t *)0x0) {
            peVar19 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
            pvVar15 = (void *)0x0;
            if (peVar19 != (edict_t *)0x0) goto LAB_00077b54;
          }
          else {
LAB_00077b54:
            pvVar15 = peVar19->pvPrivateData;
          }
          iVar16 = (*p_Var3)(g_pGameRules,pReceiver,pvVar15);
          if (iVar16 != 1) goto LAB_00077ad8;
          iVar16 = ((local_1c0->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->iuser1;
        }
        peVar2 = (pReceiver->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        if (((iVar16 == 0) || ((float)extraout_ST0 != 0.0 && teamonly == 0)) ||
           (peVar2->iuser1 != 0)) {
          (*g_engfuncs.pfnMessageBegin)(1,gmsgSayText,(float *)0x0,peVar2->pContainingEntity);
          p_Var5 = g_engfuncs.pfnWriteByte;
          iVar16 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
          (*p_Var5)(iVar16);
          (*g_engfuncs.pfnWriteString)((char *)local_1a0);
          (*g_engfuncs.pfnMessageEnd)();
        }
      }
LAB_00077ad8:
      iVar9 = iVar9 + 1;
    } while (iVar9 <= gpGlobals->maxClients);
  }
  (*g_engfuncs.pfnMessageBegin)(1,gmsgSayText,(float *)0x0,(pEntity->v).pContainingEntity);
  p_Var5 = g_engfuncs.pfnWriteByte;
  iVar9 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
  (*p_Var5)(iVar9);
  pcVar22 = "say_team";
  (*g_engfuncs.pfnWriteString)((char *)local_1a0);
  (*g_engfuncs.pfnMessageEnd)();
  pcVar10 = "SPECTATOR";
  (*g_engfuncs.pfnServerPrint)((char *)local_1a0);
  if (teamonly == 0) {
    pcVar22 = "say";
  }
  iVar9 = (local_1c0->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  if (iVar9 != 0) {
    pcVar10 = GetTeamName(iVar9);
  }
  pcVar17 = (*g_engfuncs.pfnGetPlayerAuthId)(pEntity);
  iVar9 = (*g_engfuncs.pfnGetPlayerUserId)(pEntity);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" %s \"%s\"\n",gpGlobals->pStringBase + (pEntity->v).netname,
                 iVar9,pcVar17,pcVar10,pcVar22,pcVar8);
LAB_00077cc0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Host_Tell  @ 00077f70  (line 571)

void Host_Tell(edict_t *pEntity)

{
  char cVar1;
  entvars_t *peVar2;
  string_t sVar3;
  _func_void_int *p_Var4;
  int iVar5;
  char *pcVar6;
  size_t sVar7;
  int iVar8;
  CBasePlayer *pCVar9;
  edict_t *peVar10;
  uint *puVar11;
  uint *puVar12;
  char *pcVar13;
  char *pcVar14;
  uint uVar15;
  uint uVar16;
  _2globalvars_t *p1Var17;
  void *pvVar18;
  char *pcVar19;
  char *pcVar20;
  char *pcVar21;
  int in_GS_OFFSET;
  uint local_1a0 [31];
  undefined1 local_122;
  undefined1 local_121;
  char local_120 [254];
  undefined1 local_22;
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: CBasePlayer * client@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[128] text@[???]
                       Unresolved local var: char[256] logText@[???]
                       Unresolved local var: char * pTellName@[???]
                       Unresolved local var: int copylen@[???]
                       Unresolved local var: char * pc@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CBasePlayer * pTalker@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar5 = (*g_engfuncs.pfnCmd_Argc)();
  if ((iVar5 < 3) || (iVar5 = FailedSpamCheck(pEntity,1), iVar5 != 0)) goto LAB_00077fb3;
  pcVar6 = (*g_engfuncs.pfnCmd_Args)();
  if (pcVar6 != (char *)0x0) {
    cVar1 = *pcVar6;
    pcVar21 = pcVar6;
    while (cVar1 != '\0') {
      iVar5 = isprint((int)cVar1);
      if (((iVar5 != 0) && (iVar5 = isspace((int)cVar1), iVar5 == 0)) ||
         (pcVar21 = pcVar21 + 1, pcVar21 == (char *)0x0)) goto LAB_00078045;
      cVar1 = *pcVar21;
    }
    goto LAB_00077fb3;
  }
LAB_00078045:
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar10 = pEntity;
  if (pEntity == (edict_t *)0x0) {
    pvVar18 = (void *)0x0;
    peVar10 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar10 != (edict_t *)0x0) goto LAB_0007804f;
  }
  else {
LAB_0007804f:
    pvVar18 = peVar10->pvPrivateData;
  }
  p1Var17 = gpGlobals;
  *(float *)((int)pvVar18 + 0xe7c) = gpGlobals->time;
  __sprintf_chk(local_1a0,1,0x80,"%c(TELL) %s: ",2,p1Var17->pStringBase + (pEntity->v).netname);
  pcVar21 = (*g_engfuncs.pfnCmd_Argv)(1);
  pcVar21 = strstr(pcVar6,pcVar21);
  puVar12 = local_1a0;
  if (pcVar21 == (char *)0x0) {
    do {
      puVar11 = puVar12;
      uVar15 = *puVar11 + 0xfefefeff & ~*puVar11;
      uVar16 = uVar15 & 0x80808080;
      puVar12 = puVar11 + 1;
    } while (uVar16 == 0);
    if ((uVar15 & 0x8080) == 0) {
      puVar12 = (uint *)((int)puVar11 + 6);
      uVar16 = uVar16 >> 0x10;
    }
    uVar16 = (int)puVar12 + ((-3 - (uint)CARRY1((byte)uVar16,(byte)uVar16)) - (int)local_1a0);
    if (0 < (int)(0x7f - uVar16)) {
      __strncat_chk(local_1a0,pcVar6,0x7f - uVar16,0x80);
      puVar12 = local_1a0;
      do {
        uVar16 = *puVar12;
        puVar12 = puVar12 + 1;
        uVar16 = uVar16 + 0xfefefeff & ~uVar16 & 0x80808080;
      } while (uVar16 == 0);
      goto LAB_00078165;
    }
  }
  else {
    do {
      puVar11 = puVar12;
      uVar15 = *puVar11 + 0xfefefeff & ~*puVar11;
      uVar16 = uVar15 & 0x80808080;
      puVar12 = puVar11 + 1;
    } while (uVar16 == 0);
    if ((uVar15 & 0x8080) == 0) {
      puVar12 = (uint *)((int)puVar11 + 6);
      uVar16 = uVar16 >> 0x10;
    }
    uVar16 = (int)puVar12 + ((-3 - (uint)CARRY1((byte)uVar16,(byte)uVar16)) - (int)local_1a0);
    if (0 < (int)(0x7f - uVar16)) {
      pcVar6 = (*g_engfuncs.pfnCmd_Argv)(1);
      sVar7 = strlen(pcVar6);
      __strncat_chk(local_1a0,pcVar21 + sVar7,0x7f - uVar16,0x80);
      puVar12 = local_1a0;
      do {
        uVar16 = *puVar12;
        puVar12 = puVar12 + 1;
        uVar16 = uVar16 + 0xfefefeff & ~uVar16 & 0x80808080;
      } while (uVar16 == 0);
LAB_00078165:
      if ((uVar16 & 0x8080) == 0) {
        puVar12 = (uint *)((int)puVar12 + 2);
        uVar16 = uVar16 >> 0x10;
      }
      uVar16 = (int)puVar12 + ((-3 - (uint)CARRY1((byte)uVar16,(byte)uVar16)) - (int)local_1a0);
    }
  }
  if (uVar16 < 0x7f) {
    __strcat_chk(local_1a0,"\n",0x80);
  }
  else {
    local_122 = 10;
    local_121 = 0;
  }
                    /* Unresolved local var: int i@[???] */
  iVar5 = 1;
  if (0 < gpGlobals->maxClients) {
    do {
      pCVar9 = UTIL_PlayerByIndex(iVar5);
      p1Var17 = gpGlobals;
      if (((pCVar9 != (CBasePlayer *)0x0) &&
          (peVar2 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev, pEntity != peVar2->pContainingEntity))
         && (((peVar2->flags & 8) != 0 &&
             ((*(int *)(*(int *)((int)pvVar18 + 4) + 0x244) == 0 || (peVar2->iuser1 != 0)))))) {
        pcVar6 = (*g_engfuncs.pfnCmd_Argv)(1);
        p1Var17 = gpGlobals;
        peVar2 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        iVar8 = strcmp(gpGlobals->pStringBase + peVar2->netname,pcVar6);
        if (iVar8 == 0) {
          (*g_engfuncs.pfnMessageBegin)(1,gmsgSayText,(float *)0x0,peVar2->pContainingEntity);
          p_Var4 = g_engfuncs.pfnWriteByte;
          iVar5 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
          (*p_Var4)(iVar5);
          pcVar20 = "SPECTATOR";
          (*g_engfuncs.pfnWriteString)((char *)local_1a0);
          (*g_engfuncs.pfnMessageEnd)();
          pcVar6 = (*g_engfuncs.pfnCmd_Argv)(1);
          sVar7 = strlen(pcVar6);
          iVar5 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.team_no;
          if (iVar5 != 0) {
            pcVar20 = GetTeamName(iVar5);
          }
          pcVar13 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar5 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          sVar3 = ((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->netname;
          pcVar6 = gpGlobals->pStringBase;
          pcVar19 = "SPECTATOR";
          if (*(int *)((int)pvVar18 + 0x138) != 0) {
            pcVar19 = GetTeamName(*(int *)((int)pvVar18 + 0x138));
          }
          pcVar14 = (*g_engfuncs.pfnGetPlayerAuthId)(pEntity);
          iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pEntity);
          __snprintf_chk(local_120,0xff,1,0x100,
                         "\"%s<%i><%s><%s>\" tell \"%s<%i><%s><%s>\" message \"%s\"\n",
                         gpGlobals->pStringBase + (pEntity->v).netname,iVar8,pcVar14,pcVar19,
                         pcVar6 + sVar3,iVar5,pcVar13,pcVar20,pcVar21 + sVar7 + 1);
          local_22 = 10;
          local_21 = 0;
          (*g_engfuncs.pfnServerPrint)(local_120);
          UTIL_LogPrintf(local_120);
          break;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= p1Var17->maxClients);
  }
LAB_00077fb3:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// Bench_FindSpot  @ 000784e0  (line 697)

CBaseEntity * Bench_FindSpot(int spot)

{
  float fVar1;
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pSpot@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"trigger_camera");
  if (pStartEntity == (CBaseEntity *)0x0) {
LAB_0007853c:
    pStartEntity = (CBaseEntity *)0x0;
  }
  else {
    fVar1 = pStartEntity->pev->speed;
    while (spot != (int)fVar1) {
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"trigger_camera");
      if (pStartEntity == (CBaseEntity *)0x0) goto LAB_0007853c;
      fVar1 = pStartEntity->pev->speed;
    }
  }
  return pStartEntity;
}


// ClientCommand  @ 00078550  (line 725)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ClientCommand(edict_t *pEntity)

{
  float fVar1;
  Vector vecPosition;
  Vector vecViewAngle;
  byte *__s1;
  char *pcVar2;
  char *pcVar3;
  edict_t *peVar4;
  int d;
  long iTeam;
  long lVar5;
  byte *pbVar6;
  BOOL BVar7;
  int iVar8;
  uint uVar9;
  entvars_t *peVar10;
  CBasePlayer *this;
  byte *pbVar11;
  int in_GS_OFFSET;
  bool bVar12;
  bool bVar13;
  undefined1 uVar14;
  bool bVar15;
  bool bVar16;
  byte bVar17;
  longdouble extraout_ST0;
  undefined4 in_stack_ffffff98;
  vec_t in_stack_ffffff9c;
  entvars_t *local_54;
  vec_t local_40;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  char local_25;
  char local_24;
  undefined1 local_23;
  int local_20;
  
                    /* Unresolved local var: char * pcmd@[???]
                       Unresolved local var: char * pstr@[???]
                       Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???] */
  bVar17 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  __s1 = (byte *)(*g_engfuncs.pfnCmd_Argv)(0);
  this = pEntity->pvPrivateData;
  if (this == (CBasePlayer *)0x0) goto LAB_00078830;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  bVar13 = false;
  if (pEntity == (edict_t *)0x0) {
    peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    bVar13 = peVar4 == (edict_t *)0x0;
    if (bVar13) {
      this = (CBasePlayer *)0x0;
      bVar13 = true;
    }
    else {
      this = peVar4->pvPrivateData;
    }
  }
  iVar8 = 8;
  pbVar6 = __s1;
  pbVar11 = (byte *)0x149280;
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar13 = *pbVar6 == *pbVar11;
    pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
    pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
  } while (bVar13);
  if (bVar13) {
LAB_000787b0:
    uVar14 = 1;
    CBasePlayer::UseSpecialSkill(this);
LAB_000787b8:
    iVar8 = 9;
    pbVar6 = __s1;
    pbVar11 = (byte *)"flaginfo";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      uVar14 = *pbVar6 == *pbVar11;
      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
    } while ((bool)uVar14);
    if (!(bool)uVar14) {
      local_54 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
      uVar9 = local_54->playerclass;
      bVar13 = false;
      uVar14 = uVar9 == 0;
      if (!(bool)uVar14) {
LAB_000788a0:
        iVar8 = 10;
        pbVar6 = __s1;
        pbVar11 = (byte *)"dropitems";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          uVar14 = *pbVar6 == *pbVar11;
          pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
          pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
        } while ((bool)uVar14);
        if ((bool)uVar14) {
          CBasePlayer::DropGoalItems(this);
          goto LAB_00078830;
        }
        bVar13 = uVar9 < 9;
        uVar14 = false;
        if (uVar9 == 9) {
          iVar8 = 10;
          bVar15 = true;
          pbVar6 = __s1;
          pbVar11 = (byte *)"detsentry";
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar13 = *pbVar6 < *pbVar11;
            bVar15 = *pbVar6 == *pbVar11;
            pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
            pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
          } while (bVar15);
          if (bVar15) {
            DestroyBuilding((CBaseEntity *)this,"building_sentrygun");
            goto LAB_00078830;
          }
          iVar8 = 0x13;
          bVar15 = false;
          pbVar6 = __s1;
          pbVar11 = (byte *)"detentryteleporter";
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar13 = *pbVar6 < *pbVar11;
            bVar15 = *pbVar6 == *pbVar11;
            pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
            pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
          } while (bVar15);
          if (bVar15) {
            DestroyTeleporter((CBaseEntity *)this,4);
            goto LAB_00078830;
          }
          iVar8 = 0x12;
          bVar15 = false;
          pbVar6 = __s1;
          pbVar11 = (byte *)"detexitteleporter";
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar13 = *pbVar6 < *pbVar11;
            bVar15 = *pbVar6 == *pbVar11;
            pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
            pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
          } while (bVar15);
          if (bVar15) {
            DestroyTeleporter((CBaseEntity *)this,5);
            goto LAB_00078830;
          }
          iVar8 = 0xd;
          bVar15 = false;
          pbVar6 = __s1;
          pbVar11 = (byte *)"detdispenser";
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar13 = *pbVar6 < *pbVar11;
            bVar15 = *pbVar6 == *pbVar11;
            pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
            pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
          } while (bVar15);
          if (!bVar15) {
            iVar8 = 0xd;
            pbVar6 = __s1;
            pbVar11 = (byte *)"detdispensor";
            do {
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              bVar13 = *pbVar6 < *pbVar11;
              bVar15 = *pbVar6 == *pbVar11;
              pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
              pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
            } while (bVar15);
            if (!bVar15) {
              iVar8 = 10;
              pbVar6 = __s1;
              pbVar11 = (byte *)0x1532a7;
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar13 = *pbVar6 < *pbVar11;
                bVar15 = *pbVar6 == *pbVar11;
                pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
              } while (bVar15);
              if (bVar15) {
                iVar8 = (*g_engfuncs.pfnCmd_Argc)();
                if (1 < iVar8) {
                    /* Unresolved local var: int iBuildingID@[???] */
                  pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
                  lVar5 = strtol(pcVar2,(char **)0x0,10);
                  if (lVar5 == 1) {
                    CBasePlayer::Menu_Engineer_Input(this,9.0);
                  }
                  else if (lVar5 == 2) {
                    CBasePlayer::Menu_Engineer_Input(this,3.0);
                  }
                  else if (lVar5 == 4) {
                    CBasePlayer::Menu_Engineer_Input(this,10.0);
                  }
                  else if (lVar5 == 5) {
                    CBasePlayer::Menu_Engineer_Input(this,11.0);
                  }
                }
                goto LAB_00078830;
              }
              iVar8 = 0xd;
              bVar15 = false;
              pbVar6 = __s1;
              pbVar11 = (byte *)"rotatesentry";
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar13 = *pbVar6 < *pbVar11;
                bVar15 = *pbVar6 == *pbVar11;
                pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
              } while (bVar15);
              if (bVar15) {
                CBasePlayer::Menu_Engineer_Input(this,4.0);
                goto LAB_00078830;
              }
              iVar8 = 0x10;
              bVar15 = false;
              pbVar6 = __s1;
              pbVar11 = (byte *)"rotatesentry180";
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar13 = *pbVar6 < *pbVar11;
                bVar15 = *pbVar6 == *pbVar11;
                pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
              } while (bVar15);
              uVar14 = false;
              if (bVar15) {
                CBasePlayer::Menu_Engineer_Input(this,6.0);
                goto LAB_00078830;
              }
              goto LAB_000787e1;
            }
          }
          DestroyBuilding((CBaseEntity *)this,"building_dispenser");
          goto LAB_00078830;
        }
      }
LAB_000787e1:
      iVar8 = 8;
      pbVar6 = __s1;
      pbVar11 = (byte *)"detpipe";
      do {
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        bVar13 = *pbVar6 < *pbVar11;
        uVar14 = *pbVar6 == *pbVar11;
        pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
        pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
      } while ((bool)uVar14);
      if ((bool)uVar14) {
        if ((this->m_pActiveItem != (CBasePlayerItem *)0x0) &&
           ((float)this->m_pActiveItem[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                   m_pGoalEnt <= 0.0)) {
          CBasePlayer::ExplodeOldPipebomb(this,1,0);
        }
        goto LAB_00078830;
      }
      iVar8 = 10;
      bVar15 = false;
      pbVar6 = __s1;
      pbVar11 = (byte *)"throwgren";
      do {
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        bVar13 = *pbVar6 < *pbVar11;
        bVar15 = *pbVar6 == *pbVar11;
        pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
        pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
      } while (bVar15);
      if (!bVar15) {
        iVar8 = 7;
        pbVar6 = __s1;
        pbVar11 = &DAT_0014945b;
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar13 = *pbVar6 < *pbVar11;
          bVar15 = *pbVar6 == *pbVar11;
          pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
          pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
        } while (bVar15);
        if (!bVar15) {
          iVar8 = 7;
          pbVar6 = __s1;
          pbVar11 = &DAT_00149462;
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar13 = *pbVar6 < *pbVar11;
            bVar15 = *pbVar6 == *pbVar11;
            pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
            pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
          } while (bVar15);
          if (!bVar15) {
            iVar8 = 8;
            pbVar6 = __s1;
            pbVar11 = (byte *)"detstop";
            do {
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              bVar13 = *pbVar6 < *pbVar11;
              bVar15 = *pbVar6 == *pbVar11;
              pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
              pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
            } while (bVar15);
            if (!bVar15) {
              iVar8 = 6;
              pbVar6 = __s1;
              pbVar11 = &DAT_00149471;
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar13 = *pbVar6 < *pbVar11;
                bVar15 = *pbVar6 == *pbVar11;
                pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
              } while (bVar15);
              if (!bVar15) {
                iVar8 = 7;
                pbVar6 = __s1;
                pbVar11 = &DAT_00149477;
                do {
                  if (iVar8 == 0) break;
                  iVar8 = iVar8 + -1;
                  bVar13 = *pbVar6 < *pbVar11;
                  bVar15 = *pbVar6 == *pbVar11;
                  pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                  pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                } while (bVar15);
                if (!bVar15) {
                  iVar8 = 7;
                  pbVar6 = __s1;
                  pbVar11 = &DAT_0014947e;
                  do {
                    if (iVar8 == 0) break;
                    iVar8 = iVar8 + -1;
                    bVar13 = *pbVar6 < *pbVar11;
                    bVar15 = *pbVar6 == *pbVar11;
                    pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                    pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                  } while (bVar15);
                  if (!bVar15) {
                    iVar8 = 6;
                    pbVar6 = __s1;
                    pbVar11 = (byte *)0x14d51c;
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar13 = *pbVar6 < *pbVar11;
                      bVar15 = *pbVar6 == *pbVar11;
                      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                    } while (bVar15);
                    bVar12 = uVar9 < 9;
                    if ((uVar9 == 9) && (bVar12 = false, (!bVar13 && !bVar15) == bVar13)) {
                      iVar8 = (*g_engfuncs.pfnCmd_Argc)();
                      if (iVar8 == 1) {
                        CBasePlayer::TeamFortress_EngineerBuild(this,0);
                      }
                      else {
                        pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
                        lVar5 = strtol(pcVar2,(char **)0x0,10);
                        CBasePlayer::TeamFortress_EngineerBuild(this,lVar5);
                      }
                      goto LAB_00078830;
                    }
                    bVar13 = false;
                    iVar8 = 9;
                    pbVar6 = __s1;
                    pbVar11 = (byte *)"disguise";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar12 = *pbVar6 < *pbVar11;
                      bVar13 = *pbVar6 == *pbVar11;
                      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                    } while (bVar13);
                    bVar16 = uVar9 != 8;
                    bVar15 = false;
                    if (((!bVar12 && !bVar13) == bVar12) && (bVar15 = bVar16, !bVar16)) {
                      iVar8 = (*g_engfuncs.pfnCmd_Argc)();
                      if (iVar8 == 1) {
                        CBasePlayer::TeamFortress_SpyGoUndercover(this);
                      }
                      else {
                        iVar8 = (*g_engfuncs.pfnCmd_Argc)();
                        if (iVar8 == 2) {
                          pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
                          lVar5 = strtol(pcVar2,(char **)0x0,10);
                          CBasePlayer::TeamFortress_SpyDisguise(this,lVar5,0);
                        }
                        else {
                          iVar8 = (*g_engfuncs.pfnCmd_Argc)();
                          if (iVar8 == 3) {
                            pcVar2 = (*g_engfuncs.pfnCmd_Argv)(2);
                            lVar5 = strtol(pcVar2,(char **)0x0,10);
                            pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
                            iTeam = strtol(pcVar2,(char **)0x0,10);
                            CBasePlayer::TeamFortress_SpyDisguise(this,iTeam,lVar5);
                          }
                        }
                      }
                      goto LAB_00078830;
                    }
                    iVar8 = 0xf;
                    pbVar6 = __s1;
                    pbVar11 = (byte *)"disguise_enemy";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar15 = *pbVar6 == *pbVar11;
                      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                    } while (bVar15);
                    bVar13 = false;
                    if ((bVar15) && (bVar13 = bVar16, !bVar16)) {
                      iVar8 = (*g_engfuncs.pfnCmd_Argc)();
                      if (iVar8 == 1) {
                        CBasePlayer::TeamFortress_SpyDisguiseEnemy(this,1,0);
                      }
                      else {
                        pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
                        lVar5 = strtol(pcVar2,(char **)0x0,10);
                        CBasePlayer::TeamFortress_SpyDisguiseEnemy(this,1,lVar5);
                      }
                      goto LAB_00078830;
                    }
                    iVar8 = 0x12;
                    pbVar6 = __s1;
                    pbVar11 = (byte *)"disguise_friendly";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar13 = *pbVar6 == *pbVar11;
                      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                    } while (bVar13);
                    bVar15 = false;
                    if ((bVar13) && (bVar15 = bVar16, !bVar16)) {
                      iVar8 = (*g_engfuncs.pfnCmd_Argc)();
                      if (iVar8 == 1) {
                        CBasePlayer::TeamFortress_SpyDisguiseEnemy(this,0,0);
                      }
                      else {
                        pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
                        lVar5 = strtol(pcVar2,(char **)0x0,10);
                        CBasePlayer::TeamFortress_SpyDisguiseEnemy(this,0,lVar5);
                      }
                      goto LAB_00078830;
                    }
                    iVar8 = 6;
                    pbVar6 = __s1;
                    pbVar11 = &DAT_0014951f;
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar15 = *pbVar6 == *pbVar11;
                      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                    } while (bVar15);
                    bVar13 = false;
                    if ((bVar15) && (bVar13 = bVar16, !bVar16)) {
                      CBasePlayer::TeamFortress_SpyFeignDeath(this,0);
                      goto LAB_00078830;
                    }
                    iVar8 = 7;
                    pbVar6 = __s1;
                    pbVar11 = &DAT_0014951e;
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar13 = *pbVar6 == *pbVar11;
                      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                    } while (bVar13);
                    bVar15 = false;
                    if ((bVar13) && (bVar15 = bVar16, !bVar16)) {
                      CBasePlayer::TeamFortress_SpyFeignDeath(this,1);
                      goto LAB_00078830;
                    }
                    iVar8 = 9;
                    pbVar6 = __s1;
                    pbVar11 = (byte *)0x14edfa;
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar15 = *pbVar6 == *pbVar11;
                      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                    } while (bVar15);
                    if (!bVar15) {
                      iVar8 = strcmp((char *)__s1,"sendevents");
                      if ((iVar8 == 0) && (this->m_bSentBuildingEvents == 0)) {
                        SendBuildingEventInfo(this);
                        this->m_bSentBuildingEvents = 1;
                      }
                      goto LAB_00078830;
                    }
                    if (gpGlobals->time <= (float)this->m_iTimeCheckAllowed) goto LAB_00078830;
                    if (timelimit.value == 0.0) {
                      ClientPrint(local_54,3,"#Game_no_timelimit",(char *)0x0,(char *)0x0,
                                  (char *)0x0,(char *)0x0);
                    }
                    else {
                    /* Unresolved local var: int iTimeRemaining@[???]
                       Unresolved local var: int iMinutes@[???]
                       Unresolved local var: int iSeconds@[???]
                       Unresolved local var: char[5] secs@[???]
                       Unresolved local var: char * temp@[???] */
                      iVar8 = (int)(timelimit.value * 60.0 - gpGlobals->time);
                      if (iVar8 < 0) {
                        d = 0;
                        pcVar2 = UTIL_dtos2(0);
LAB_0007952d:
                        local_25 = '0';
                        local_24 = *pcVar2;
                      }
                      else {
                        d = iVar8 / 0x3c;
                        pcVar2 = UTIL_dtos2(iVar8 % 0x3c);
                        if (iVar8 % 0x3c < 10) goto LAB_0007952d;
                        local_25 = *pcVar2;
                        local_24 = pcVar2[1];
                      }
                      local_23 = 0;
                      pcVar2 = UTIL_dtos1(d);
                      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.pev,3,"#Game_timelimit",pcVar2,
                                  &local_25,(char *)0x0,(char *)0x0);
                    }
                    this->m_iTimeCheckAllowed = (int)(gpGlobals->time + 1.0);
                    goto LAB_00078830;
                  }
                }
              }
            }
            CBasePlayer::TeamFortress_DetpackStop(this);
            goto LAB_00078830;
          }
        }
      }
      CBasePlayer::TeamFortress_ThrowPrimedGrenade(this);
      goto LAB_00078830;
    }
  }
  else {
    iVar8 = 9;
    bVar13 = false;
    pbVar6 = __s1;
    pbVar11 = (byte *)"_special";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar13 = *pbVar6 == *pbVar11;
      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
    } while (bVar13);
    if (bVar13) goto LAB_000787b0;
    iVar8 = 4;
    bVar13 = false;
    pbVar6 = __s1;
    pbVar11 = &DAT_001491fe;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar13 = *pbVar6 == *pbVar11;
      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
    } while (bVar13);
    if (bVar13) {
      uVar14 = 1;
      Host_Say(pEntity,0);
      goto LAB_000787b8;
    }
    iVar8 = 9;
    uVar14 = false;
    pbVar6 = __s1;
    pbVar11 = (byte *)"say_team";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      uVar14 = *pbVar6 == *pbVar11;
      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
    } while ((bool)uVar14);
    if ((bool)uVar14) {
      Host_Say(pEntity,1);
      goto LAB_000787b8;
    }
    iVar8 = 0xb;
    pbVar6 = __s1;
    pbVar11 = (byte *)"fullupdate";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      uVar14 = *pbVar6 == *pbVar11;
      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
    } while ((bool)uVar14);
    if ((bool)uVar14) {
      CBasePlayer::ForceClientDllUpdate(this);
      goto LAB_000787b8;
    }
    iVar8 = 5;
    pbVar6 = __s1;
    pbVar11 = &DAT_00149293;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      uVar14 = *pbVar6 == *pbVar11;
      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
    } while ((bool)uVar14);
    if ((bool)uVar14) {
      Host_Tell(pEntity);
      goto LAB_000787b8;
    }
    iVar8 = 5;
    bVar13 = false;
    pbVar6 = __s1;
    pbVar11 = &DAT_00149298;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar13 = *pbVar6 == *pbVar11;
      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
    } while (bVar13);
    if (bVar13) {
      (*g_engfuncs.pfnCVarGetFloat)("sv_cheats");
      uVar14 = extraout_ST0 == (longdouble)0;
      if (!(bool)uVar14) {
        pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
        CBasePlayer::GiveNamedItem(this,pcVar2);
      }
      goto LAB_000787b8;
    }
    iVar8 = 4;
    bVar13 = false;
    pbVar6 = __s1;
    pbVar11 = &DAT_001492a7;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar13 = *pbVar6 == *pbVar11;
      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
    } while (bVar13);
    if (bVar13) {
      iVar8 = (*g_engfuncs.pfnCmd_Argc)();
      if (iVar8 < 2) {
        pcVar2 = UTIL_VarArgs("\"fov\" is \"%d\"\n",this->m_iFOV);
        uVar14 = 1;
        ClientPrint(&pEntity->v,1,pcVar2,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      }
      else {
        pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
        uVar14 = 1;
        lVar5 = strtol(pcVar2,(char **)0x0,10);
        peVar10 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev;
        this->m_iFOV = lVar5;
        peVar10->fov = (float)lVar5;
      }
      goto LAB_000787b8;
    }
    iVar8 = 9;
    uVar14 = false;
    pbVar6 = __s1;
    pbVar11 = (byte *)"spectate";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      uVar14 = *pbVar6 == *pbVar11;
      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
    } while ((bool)uVar14);
    if (!(bool)uVar14) {
      iVar8 = 9;
      pbVar6 = __s1;
      pbVar11 = (byte *)"specmode";
      do {
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        uVar14 = *pbVar6 == *pbVar11;
        pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
        pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
      } while ((bool)uVar14);
      if ((bool)uVar14) {
        uVar14 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->iuser1 == 0;
        if (!(bool)uVar14) {
          pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
          uVar14 = 1;
          lVar5 = strtol(pcVar2,(char **)0x0,10);
          CBasePlayer::Observer_SetMode(this,lVar5);
        }
      }
      else {
        iVar8 = 0xb;
        pbVar6 = __s1;
        pbVar11 = (byte *)"follownext";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          uVar14 = *pbVar6 == *pbVar11;
          pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
          pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
        } while ((bool)uVar14);
        if ((bool)uVar14) {
          uVar14 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0;
          if (!(bool)uVar14) {
            pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
            lVar5 = strtol(pcVar2,(char **)0x0,10);
            uVar14 = lVar5 == 0;
            CBasePlayer::Observer_FindNextPlayer(this,!(bool)uVar14);
          }
        }
        else {
          iVar8 = 6;
          pbVar6 = __s1;
          pbVar11 = (byte *)0x1530ca;
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            uVar14 = *pbVar6 == *pbVar11;
            pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
            pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
          } while ((bool)uVar14);
          if ((bool)uVar14) {
            CBasePlayer::ChangeClass(this,1);
          }
          else {
            iVar8 = 7;
            pbVar6 = __s1;
            pbVar11 = (byte *)0x157d4b;
            do {
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              uVar14 = *pbVar6 == *pbVar11;
              pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
              pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
            } while ((bool)uVar14);
            if ((bool)uVar14) {
              CBasePlayer::ChangeClass(this,2);
            }
            else {
              iVar8 = 8;
              pbVar6 = __s1;
              pbVar11 = (byte *)0x1530e3;
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                uVar14 = *pbVar6 == *pbVar11;
                pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
              } while ((bool)uVar14);
              if ((bool)uVar14) {
                CBasePlayer::ChangeClass(this,3);
              }
              else {
                iVar8 = 8;
                pbVar6 = __s1;
                pbVar11 = (byte *)0x1530f1;
                do {
                  if (iVar8 == 0) break;
                  iVar8 = iVar8 + -1;
                  uVar14 = *pbVar6 == *pbVar11;
                  pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                  pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                } while ((bool)uVar14);
                if ((bool)uVar14) {
                  CBasePlayer::ChangeClass(this,4);
                }
                else {
                  iVar8 = 6;
                  pbVar6 = __s1;
                  pbVar11 = (byte *)0x1530ff;
                  do {
                    if (iVar8 == 0) break;
                    iVar8 = iVar8 + -1;
                    uVar14 = *pbVar6 == *pbVar11;
                    pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                    pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                  } while ((bool)uVar14);
                  if ((bool)uVar14) {
                    CBasePlayer::ChangeClass(this,5);
                  }
                  else {
                    iVar8 = 8;
                    pbVar6 = __s1;
                    pbVar11 = &DAT_001492d7;
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      uVar14 = *pbVar6 == *pbVar11;
                      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                    } while ((bool)uVar14);
                    if (!(bool)uVar14) {
                      iVar8 = strcmp((char *)__s1,"hwguy");
                      uVar14 = iVar8 == 0;
                      if (!(bool)uVar14) {
                        iVar8 = 5;
                        pbVar6 = __s1;
                        pbVar11 = (byte *)0x153117;
                        do {
                          if (iVar8 == 0) break;
                          iVar8 = iVar8 + -1;
                          uVar14 = *pbVar6 == *pbVar11;
                          pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
                          pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
                        } while ((bool)uVar14);
                        if ((bool)uVar14) {
                          CBasePlayer::ChangeClass(this,7);
                        }
                        else {
                          iVar8 = strcmp((char *)__s1,"spy");
                          uVar14 = iVar8 == 0;
                          if ((bool)uVar14) {
                            CBasePlayer::ChangeClass(this,8);
                          }
                          else {
                            iVar8 = strcmp((char *)__s1,"engineer");
                            uVar14 = iVar8 == 0;
                            if ((bool)uVar14) {
                              CBasePlayer::ChangeClass(this,9);
                            }
                            else {
                              iVar8 = strcmp((char *)__s1,"randompc");
                              if (iVar8 == 0) {
                                BVar7 = CBasePlayer::PositionAvailable(this);
                                uVar14 = BVar7 == 0;
                                if ((bool)uVar14) {
                                  ClientPrint(&pEntity->v,1,"#Game_enoughofclass",(char *)0x0,
                                              (char *)0x0,(char *)0x0,(char *)0x0);
                                  CBasePlayer::Menu_Class(this);
                                }
                                else {
                                  CBasePlayer::ChangeClass(this,10);
                                }
                              }
                              else {
                                iVar8 = strcmp((char *)__s1,"civilian");
                                if (iVar8 == 0) {
                                  BVar7 = TeamFortress_TeamIsCivilian
                                                    ((float)(this->super_CBaseMonster).
                                                            super_CBaseToggle.super_CBaseAnimating.
                                                            super_CBaseDelay.super_CBaseEntity.
                                                            team_no);
                                  uVar14 = BVar7 == 0;
                                  if (!(bool)uVar14) {
                                    CBasePlayer::ChangeClass(this,0xb);
                                  }
                                }
                                else {
                                  iVar8 = strcmp((char *)__s1,"changeclass");
                                  if (iVar8 == 0) {
                                    peVar10 = (this->super_CBaseMonster).super_CBaseToggle.
                                              super_CBaseAnimating.super_CBaseDelay.
                                              super_CBaseEntity.pev;
                                    uVar14 = peVar10->iuser1 == 0;
                                    if ((bool)uVar14) {
                                      uVar14 = peVar10->playerclass == 0;
                                      if (!(bool)uVar14) {
                                        CBasePlayer::Menu_Class(this);
                                      }
                                    }
                                    else {
LAB_00078ebc:
                                      CBasePlayer::Menu_Team(this);
                                    }
                                  }
                                  else {
                                    iVar8 = strcmp((char *)__s1,"changeteam");
                                    uVar14 = true;
                                    if (iVar8 == 0) goto LAB_00078ebc;
                                    iVar8 = strcmp((char *)__s1,"closemenus");
                                    uVar14 = iVar8 == 0;
                                    if ((bool)uVar14) {
                                      CBasePlayer::ResetMenu(this);
                                    }
                                    else {
                                      iVar8 = strcmp((char *)__s1,"jointeam");
                                      if (iVar8 == 0) {
                                        iVar8 = (*g_engfuncs.pfnCmd_Argc)();
                                        uVar14 = iVar8 == 1;
                                        if (1 < iVar8) {
                    /* Unresolved local var: int iTeamNo@[???] */
                                          pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
                                          lVar5 = strtol(pcVar2,(char **)0x0,10);
                                          uVar14 = lVar5 == 5;
                                          if ((bool)uVar14) {
                                            CBasePlayer::TeamFortress_TeamPutPlayerInTeam(this);
                                          }
                                          else {
                                            uVar14 = number_of_teams == (float)lVar5;
                                            if (((float)lVar5 <= number_of_teams) &&
                                               (uVar14 = lVar5 == 0, 0 < lVar5)) {
                                              CBasePlayer::TeamFortress_TeamSet(this,lVar5);
                                            }
                                          }
                                        }
                                      }
                                      else {
                                        iVar8 = strcmp((char *)__s1,"admin");
                                        uVar14 = iVar8 == 0;
                                        if ((bool)uVar14) {
                                          pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
                                          CBasePlayer::AdminAccess(this,pcVar2);
                                        }
                                        else if ((this->super_CBaseMonster).super_CBaseToggle.
                                                 super_CBaseAnimating.super_CBaseDelay.
                                                 super_CBaseEntity.is_admin == 1) {
                                          iVar8 = strcmp((char *)__s1,"adm_countplayers");
                                          uVar14 = iVar8 == 0;
                                          if ((bool)uVar14) {
                                            CBasePlayer::Admin_CountPlayers(this);
                                          }
                                          else {
                                            iVar8 = strcmp((char *)__s1,"adm_ceasefire");
                                            uVar14 = iVar8 == 0;
                                            if ((bool)uVar14) {
                                              Admin_CeaseFire();
                                            }
                                            else {
                                              iVar8 = strcmp((char *)__s1,"adm_deal");
                                              uVar14 = iVar8 == 0;
                                              if (!(bool)uVar14) {
                                                iVar8 = strcmp((char *)__s1,"adm_next");
                                                uVar14 = iVar8 == 0;
                                                if (!(bool)uVar14) {
                                                  iVar8 = strcmp((char *)__s1,"next");
                                                  uVar14 = iVar8 == 0;
                                                  if (!(bool)uVar14) {
                                                    iVar8 = strcmp((char *)__s1,"adm_kick");
                                                    if ((iVar8 == 0) ||
                                                       (iVar8 = strcmp((char *)__s1,"kick"),
                                                       iVar8 == 0)) {
                                                      uVar14 = (this->super_CBaseMonster).
                                                               super_CBaseToggle.
                                                               super_CBaseAnimating.super_CBaseDelay
                                                               .super_CBaseEntity.admin_mode == 1;
                                                      if ((bool)uVar14) {
                                                        CBasePlayer::Admin_DoKick(this);
                                                        goto LAB_000787b8;
                                                      }
                                                      iVar8 = strcmp((char *)__s1,"adm_ban");
                                                      if (iVar8 != 0) goto LAB_000799b9;
                                                    }
                                                    else {
                                                      iVar8 = strcmp((char *)__s1,"adm_ban");
                                                      if (iVar8 != 0) {
LAB_000799b9:
                                                        iVar8 = strcmp((char *)__s1,"ban");
                                                        if (iVar8 != 0) goto LAB_00079943;
                                                      }
                                                      uVar14 = (this->super_CBaseMonster).
                                                               super_CBaseToggle.
                                                               super_CBaseAnimating.super_CBaseDelay
                                                               .super_CBaseEntity.admin_mode == 1;
                                                      if ((bool)uVar14) {
                                                        CBasePlayer::Admin_DoBan(this);
                                                        goto LAB_000787b8;
                                                      }
                                                    }
LAB_00079943:
                                                    iVar8 = strcmp((char *)__s1,"adm_listplayers");
                                                    uVar14 = iVar8 == 0;
                                                    if ((bool)uVar14) {
                                                      CBasePlayer::Admin_ListIPs(this);
                                                    }
                                                    else {
                                                      iVar8 = strcmp((char *)__s1,"adm_changelevel")
                                                      ;
                                                      uVar14 = iVar8 == 0;
                                                      if (!(bool)uVar14) goto LAB_0007965f;
                                                      CBasePlayer::Admin_Changelevel(this);
                                                    }
                                                    goto LAB_000787b8;
                                                  }
                                                }
                                              }
                                              CBasePlayer::Admin_CycleDeal(this);
                                            }
                                          }
                                        }
                                        else {
LAB_0007965f:
                                          iVar8 = (*g_pGameRules->_vptr_CGameRules[0x18])
                                                            (g_pGameRules,this,__s1);
                                          uVar14 = 0;
                                          if (iVar8 == 0) {
                                            iVar8 = (*(this->super_CBaseMonster).super_CBaseToggle.
                                                      super_CBaseAnimating.super_CBaseDelay.
                                                      super_CBaseEntity._vptr_CBaseEntity[0x22])
                                                              (this);
                                            if (iVar8 == 0) goto LAB_00078830;
                                            uVar14 = 0;
                                            if ((((this->super_CBaseMonster).super_CBaseToggle.
                                                  super_CBaseAnimating.super_CBaseDelay.
                                                  super_CBaseEntity.is_building == 0) &&
                                                (uVar14 = 0,
                                                (this->super_CBaseMonster).super_CBaseToggle.
                                                super_CBaseAnimating.super_CBaseDelay.
                                                super_CBaseEntity.is_detpacking == 0)) &&
                                               (uVar14 = 0,
                                               (this->super_CBaseMonster).super_CBaseToggle.
                                               super_CBaseAnimating.super_CBaseDelay.
                                               super_CBaseEntity.is_feigning == 0)) {
                                              iVar8 = strcmp((char *)__s1,"use");
                                              uVar14 = iVar8 == 0;
                                              if ((bool)uVar14) {
                                                pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
                                                CBasePlayer::SelectItem(this,pcVar2);
                                              }
                                              else {
                                                pbVar6 = (byte *)strstr((char *)__s1,"weapon_");
                                                if (((pbVar6 == (byte *)0x0) || (__s1 != pbVar6)) &&
                                                   ((pbVar6 = (byte *)strstr((char *)__s1,
                                                                             "tf_weapon_"),
                                                    pbVar6 == (byte *)0x0 || (__s1 != pbVar6)))) {
                                                  iVar8 = strcmp((char *)__s1,"lastinv");
                                                  uVar14 = iVar8 == 0;
                                                  if ((bool)uVar14) {
                                                    CBasePlayer::SelectLastItem(this);
                                                  }
                                                  else {
                                                    iVar8 = strcmp((char *)__s1,"primeone");
                                                    if (iVar8 == 0) {
LAB_00079abf:
                                                      uVar14 = 1;
                                                      CBasePlayer::TeamFortress_PrimeGrenade(this,1)
                                                      ;
                                                    }
                                                    else {
                                                      iVar8 = strcmp((char *)__s1,"primetwo");
                                                      uVar14 = iVar8 == 0;
                                                      if (!(bool)uVar14) {
                                                        iVar8 = strcmp((char *)__s1,"+gren1");
                                                        if (iVar8 == 0) goto LAB_00079abf;
                                                        iVar8 = strcmp((char *)__s1,"+gren2");
                                                        uVar14 = iVar8 == 0;
                                                        if (!(bool)uVar14) {
                                                          iVar8 = strcmp((char *)__s1,"detstart");
                                                          if (iVar8 == 0) {
                                                            iVar8 = (*g_engfuncs.pfnCmd_Argc)();
                                                            uVar14 = iVar8 == 1;
                                                            if (iVar8 < 2) {
LAB_00079afa:
                                                              CBasePlayer::TeamFortress_SetDetpack
                                                                        (this,0x14);
                                                            }
                                                            else {
                    /* Unresolved local var: int time@[???] */
                                                              pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
                                                              iVar8 = strtol(pcVar2,(char **)0x0,10)
                                                              ;
                                                              uVar14 = iVar8 == 0x32;
                                                              if (iVar8 < 0x33) {
                                                                uVar14 = iVar8 == 4;
                                                                if (iVar8 < 5) {
                                                                  iVar8 = 5;
                                                                }
                                                              }
                                                              else {
                                                                iVar8 = 0x32;
                                                              }
                                                              CBasePlayer::TeamFortress_SetDetpack
                                                                        (this,iVar8);
                                                            }
                                                          }
                                                          else {
                                                            iVar8 = strcmp((char *)__s1,"+det5");
                                                            uVar14 = iVar8 == 0;
                                                            if ((bool)uVar14) {
                                                              CBasePlayer::TeamFortress_SetDetpack
                                                                        (this,5);
                                                            }
                                                            else {
                                                              iVar8 = strcmp((char *)__s1,"+det20");
                                                              uVar14 = true;
                                                              if (iVar8 == 0) goto LAB_00079afa;
                                                              iVar8 = strcmp((char *)__s1,"+det50");
                                                              uVar14 = iVar8 == 0;
                                                              if ((bool)uVar14) {
                                                                CBasePlayer::TeamFortress_SetDetpack
                                                                          (this,0x32);
                                                              }
                                                              else {
                                                                iVar8 = strcmp((char *)__s1,
                                                                               "discard");
                                                                uVar14 = iVar8 == 0;
                                                                if (!(bool)uVar14) {
                                                                  iVar8 = strcmp((char *)__s1,"drop"
                                                                                );
                                                                  uVar14 = iVar8 == 0;
                                                                  if (!(bool)uVar14) {
                                                                    local_54 = (this->
                                                  super_CBaseMonster).super_CBaseToggle.
                                                  super_CBaseAnimating.super_CBaseDelay.
                                                  super_CBaseEntity.pev;
                                                  uVar9 = local_54->playerclass;
                                                  uVar14 = uVar9 == 0;
                                                  if (!(bool)uVar14) {
                                                    iVar8 = strcmp((char *)__s1,"saveme");
                                                    uVar14 = iVar8 == 0;
                                                    if (!(bool)uVar14) goto LAB_0007887e;
                                                    CBasePlayer::TeamFortress_SaveMe(this);
                                                  }
                                                  goto LAB_000787b8;
                                                  }
                                                  }
                                                  CBasePlayer::TeamFortress_Discard(this);
                                                  }
                                                  }
                                                  }
                                                  goto LAB_000787b8;
                                                  }
                                                  }
                                                  CBasePlayer::TeamFortress_PrimeGrenade(this,2);
                                                  }
                                                  }
                                                }
                                                else {
                                                  uVar14 = 1;
                                                  CBasePlayer::SelectItem(this,(char *)__s1);
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        goto LAB_000787b8;
                      }
                    }
                    CBasePlayer::ChangeClass(this,6);
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_000787b8;
    }
    local_54 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    if ((local_54->flags & 0x100000) != 0) {
                    /* Unresolved local var: edict_t * pentSpawnSpot@[???] */
      pcVar2 = GetTeamName((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.team_no);
      pcVar3 = (*g_engfuncs.pfnGetPlayerAuthId)
                         (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar8 = (*g_engfuncs.pfnGetPlayerUserId)
                        (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" joined team \"SPECTATOR\"\n",
                     gpGlobals->pStringBase +
                     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar8);
      peVar4 = EntSelectSpawnPoint(pEntity);
      uVar14 = peVar4 == (edict_t *)0x0;
      if ((bool)uVar14) {
        peVar10 = (entvars_t *)0x0;
        local_34 = _DAT_00000050;
        local_30 = _DAT_00000054;
        local_2c = _DAT_00000058;
      }
      else {
        local_34 = (peVar4->v).angles.x;
        peVar10 = &peVar4->v;
        local_30 = (peVar4->v).angles.y;
        local_2c = (peVar4->v).angles.z;
      }
      local_40 = (peVar10->origin).x;
      local_3c = (peVar10->origin).y;
      local_38 = (peVar10->origin).z;
LAB_00078794:
      vecPosition.y = (vec_t)&local_34;
      vecPosition.x = (vec_t)&local_40;
      vecPosition.z = (vec_t)pcVar3;
      vecViewAngle.y = (vec_t)in_stack_ffffff98;
      vecViewAngle.x = (vec_t)pcVar2;
      vecViewAngle.z = in_stack_ffffff9c;
      CBasePlayer::StartObserver(this,vecPosition,vecViewAngle);
      goto LAB_000787b8;
    }
    if (allow_spectators.value != 0.0) {
                    /* Unresolved local var: int allow_change@[???] */
      fVar1 = this->m_fNextTeamOrClassChange;
      if (fVar1 != 0.0) {
        uVar14 = gpGlobals->time == fVar1;
        if (fVar1 < gpGlobals->time) {
          iVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.team_no;
          uVar14 = iVar8 == 0;
          if (!(bool)uVar14) goto LAB_000786b1;
        }
        goto LAB_000787b8;
      }
      iVar8 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.team_no;
LAB_000786b1:
                    /* Unresolved local var: edict_t * pentSpawnSpot@[???] */
      pcVar2 = GetTeamName(iVar8);
      pcVar3 = (*g_engfuncs.pfnGetPlayerAuthId)
                         (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      iVar8 = (*g_engfuncs.pfnGetPlayerUserId)
                        (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                          super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
      UTIL_LogPrintf("\"%s<%i><%s><%s>\" joined team \"SPECTATOR\"\n",
                     gpGlobals->pStringBase +
                     ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev)->netname,iVar8);
      fVar1 = gpGlobals->time;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.team_no = 0;
      this->m_fNextTeamOrClassChange = fVar1 + 1.0;
      peVar4 = EntSelectSpawnPoint(pEntity);
      uVar14 = peVar4 == (edict_t *)0x0;
      if ((bool)uVar14) {
        peVar10 = (entvars_t *)0x0;
        local_34 = _DAT_00000050;
        local_30 = _DAT_00000054;
        local_2c = _DAT_00000058;
      }
      else {
        local_34 = (peVar4->v).angles.x;
        peVar10 = &peVar4->v;
        local_30 = (peVar4->v).angles.y;
        local_2c = (peVar4->v).angles.z;
      }
      local_40 = (peVar10->origin).x;
      local_3c = (peVar10->origin).y;
      local_38 = (peVar10->origin).z;
      goto LAB_00078794;
    }
    uVar9 = local_54->playerclass;
    uVar14 = false;
    if (uVar9 == 0) {
      uVar14 = local_54->team == 0;
      if ((bool)uVar14) goto LAB_00078ebc;
      goto LAB_000787b8;
    }
LAB_0007887e:
    iVar8 = 9;
    pbVar6 = __s1;
    pbVar11 = (byte *)"flaginfo";
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      uVar14 = *pbVar6 == *pbVar11;
      pbVar6 = pbVar6 + (uint)bVar17 * -2 + 1;
      pbVar11 = pbVar11 + (uint)bVar17 * -2 + 1;
    } while ((bool)uVar14);
    if (!(bool)uVar14) goto LAB_000788a0;
  }
  CBasePlayer::TeamFortress_DisplayDetectionItems(this);
LAB_00078830:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ClientUserInfoChanged  @ 00079b90  (line 1179)

void ClientUserInfoChanged(edict_t *pEntity,char *infobuffer)

{
  string_t sVar1;
  _func_int_varargs *p_Var2;
  _func_void_int *p_Var3;
  _func_void_int_char_ptr_char_ptr_char_ptr *p_Var4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  CBasePlayer *this;
  edict_t *peVar8;
  entvars_t *pev;
  char *pcVar9;
  void *pvVar10;
  int in_GS_OFFSET;
  char local_220 [255];
  undefined1 local_121;
  char local_120 [256];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (pEntity->pvPrivateData != (void *)0x0) {
    sVar1 = (pEntity->v).netname;
    if ((sVar1 != 0) && (gpGlobals->pStringBase[sVar1] != '\0')) {
      pcVar5 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"name");
      iVar6 = strcmp(gpGlobals->pStringBase + (pEntity->v).netname,pcVar5);
      if (iVar6 != 0) {
                    /* Unresolved local var: char[256] sName@[???]
                       Unresolved local var: char * pName@[???]
                       Unresolved local var: char[256] text@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???] */
        pcVar5 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"name");
        strncpy(local_220,pcVar5,0xff);
        p_Var4 = g_engfuncs.pfnSetClientKeyValue;
                    /* Unresolved local var: char * pApersand@[???] */
        local_121 = 0;
        pcVar5 = local_220;
        do {
          while( true ) {
            if (*pcVar5 == '\0') goto LAB_00079cd0;
            if (*pcVar5 != '%') break;
            *pcVar5 = ' ';
            pcVar5 = pcVar5 + 1;
            if (pcVar5 == (char *)0x0) goto LAB_00079cd0;
          }
          pcVar5 = pcVar5 + 1;
        } while (pcVar5 != (char *)0x0);
LAB_00079cd0:
        iVar6 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
        (*p_Var4)(iVar6,infobuffer,"name",local_220);
        pcVar5 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"name");
        __sprintf_chk(local_120,1,0x100,"* %s changed name to %s\n",
                      gpGlobals->pStringBase + (pEntity->v).netname,pcVar5);
        (*g_engfuncs.pfnMessageBegin)(2,gmsgSayText,(float *)0x0,(edict_t *)0x0);
        p_Var3 = g_engfuncs.pfnWriteByte;
        iVar6 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
        (*p_Var3)(iVar6);
        (*g_engfuncs.pfnWriteString)(local_120);
        (*g_engfuncs.pfnMessageEnd)();
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        peVar8 = pEntity;
        if ((pEntity == (edict_t *)0x0) &&
           (peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar8 == (edict_t *)0x0)) {
          pvVar10 = (void *)0x0;
        }
        else {
          pvVar10 = peVar8->pvPrivateData;
        }
        pcVar5 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"name");
        pcVar9 = "SPECTATOR";
        if (*(int *)((int)pvVar10 + 0x138) != 0) {
          pcVar9 = GetTeamName(*(int *)((int)pvVar10 + 0x138));
        }
        pcVar7 = (*g_engfuncs.pfnGetPlayerAuthId)(pEntity);
        iVar6 = (*g_engfuncs.pfnGetPlayerUserId)(pEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" changed name to \"%s\"\n",
                       gpGlobals->pStringBase + (pEntity->v).netname,iVar6,pcVar7,pcVar9,pcVar5);
      }
    }
    pev = &pEntity->v;
                    /* Unresolved local var: entvars_t * pev@[???] */
    p_Var2 = g_pGameRules->_vptr_CGameRules[0x19];
    if (pev == (entvars_t *)0x0) {
      peVar8 = (*g_engfuncs.pfnCreateEntity)();
      if (peVar8 != (edict_t *)0x0) {
        pev = &peVar8->v;
      }
    }
    if ((pev->pContainingEntity == (edict_t *)0x0) ||
       (this = pev->pContainingEntity->pvPrivateData, this == (CBasePlayer *)0x0)) {
      this = CBaseEntity::operator_new(0xecc,pev);
      CBasePlayer::CBasePlayer(this);
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = pev;
    }
    (*p_Var2)(g_pGameRules,this,infobuffer);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ServerDeactivate  @ 00079e90  (line 1229)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ServerDeactivate(void)

{
  if (g_serveractive != 1) {
    return;
  }
  g_serveractive = 0;
  return;
}


// ServerActivate  @ 00079eb0  (line 1245)

void ServerActivate(edict_t *pEdictList,int edictCount,int clientMax)

{
  int *piVar1;
  edict_t *peVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CBaseEntity * pClass@[???] */
  iVar3 = 0;
  g_serveractive = 1;
  if (0 < edictCount) {
    do {
      while (((pEdictList->free != 0 || (iVar3 < clientMax)) ||
             (piVar1 = pEdictList->pvPrivateData, piVar1 == (int *)0x0))) {
LAB_00079ef0:
        iVar3 = iVar3 + 1;
        pEdictList = pEdictList + 1;
        if (edictCount == iVar3) goto LAB_00079f60;
      }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if (((pEdictList != (edict_t *)0x0) ||
          ((peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar2 != (edict_t *)0x0 &&
           (piVar1 = peVar2->pvPrivateData, piVar1 != (int *)0x0)))) &&
         (-1 < *(int *)(piVar1[1] + 0x1a4))) {
        (**(code **)(*piVar1 + 0x20))(piVar1);
        goto LAB_00079ef0;
      }
      iVar3 = iVar3 + 1;
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Can\'t instance %s\n",
                 gpGlobals->pStringBase + (pEdictList->v).classname);
      pEdictList = pEdictList + 1;
    } while (edictCount != iVar3);
  }
LAB_00079f60:
  ParseTFMapSettings();
  LinkUserMessages();
  (*g_engfuncs.pfnCVarSetFloat)("sv_maxspeed",400.0);
  (*g_engfuncs.pfnServerCommand)("sv_maxspeed 400\n");
  if (ServerActivate::firstTime != 0) {
    (*g_engfuncs.pfnAddServerCommand)("tf_ceasefire",Admin_CeaseFire);
    ServerActivate::firstTime = 0;
  }
  return;
}


// PlayerPreThink  @ 00079ff0  (line 1304)

void PlayerPreThink(edict_t *pEntity)

{
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???] */
  if ((pEntity != (edict_t *)0x0) && (pEntity->pvPrivateData != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0007a005. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pEntity->pvPrivateData + 0x220))();
    return;
  }
  return;
}


// PlayerPostThink  @ 0007a020  (line 1320)

void PlayerPostThink(edict_t *pEntity)

{
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???] */
  if ((pEntity != (edict_t *)0x0) && (pEntity->pvPrivateData != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0007a035. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pEntity->pvPrivateData + 0x224))();
    return;
  }
  return;
}


// ParmsNewLevel  @ 0007a050  (line 1331)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ParmsNewLevel(void)

{
  return;
}


// ParmsChangeLevel  @ 0007a060  (line 1336)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ParmsChangeLevel(void)

{
  void *pvVar1;
  int iVar2;
  
                    /* Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
  pvVar1 = gpGlobals->pSaveData;
  if (pvVar1 != (void *)0x0) {
    iVar2 = BuildChangeList((_LEVELLIST *)((int)pvVar1 + 0x2c),0x10);
    *(int *)((int)pvVar1 + 0x24) = iVar2;
  }
  return;
}


// StartFrame  @ 0007a090  (line 1348)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void StartFrame(void)

{
  int *piVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  longdouble extraout_ST0;
  float fVar4;
  float fVar5;
  
  if (g_pGameRules != (CGameRules *)0x0) {
    (*g_pGameRules->_vptr_CGameRules[1])(g_pGameRules);
  }
  p1Var3 = gpGlobals;
  if (g_fGameOver == 0) {
    piVar1 = &gpGlobals->maxClients;
    gpGlobals->teamplay = teamplay.value;
    if (*piVar1 < 8) {
      (*g_engfuncs.pfnCVarGetFloat)("deathmatch");
      p1Var3->deathmatch = (float)extraout_ST0;
    }
    else {
      p1Var3->deathmatch = 1.0;
    }
    if (((tfc_balance_teams.value != 0.0) || (tfc_balance_scores.value != 0.0)) &&
       (flNextEqualisationCalc < gpGlobals->time)) {
      CalculateTeamEqualiser();
      flNextEqualisationCalc = gpGlobals->time + 10.0;
    }
    if (cb_prematch_time != 0.0) {
                    /* Unresolved local var: float fNewPrematch@[???] */
      fVar2 = tfc_clanbattle_prematch.value * 60.0;
      if (fVar2 == 0.0) {
        fVar2 = tfc_prematch.value * 60.0;
      }
      fVar4 = ceilf(fVar2);
      fVar5 = ceilf(fOldPrematch);
      if (fVar4 != fVar5) {
        cb_prematch_time = fVar2 + gpGlobals->time;
        g_fNextPrematchAlert = 0.0;
        fOldPrematch = fVar2;
      }
      Display_Prematch();
    }
    if (initial_cease_fire != 0) {
                    /* Unresolved local var: float fNewCeaseFire@[???] */
      fVar2 = tfc_clanbattle_ceasefire.value * 60.0;
      fVar4 = ceilf(fVar2);
      fVar5 = ceilf(fOldCeaseFire);
      if (fVar4 != fVar5) {
        cb_ceasefire_time = fVar2 + gpGlobals->time;
        fOldCeaseFire = fVar2;
      }
    }
    if (last_cease_fire != 0) {
      Check_Ceasefire();
    }
    g_ulFrameCount = g_ulFrameCount + 1;
    g_iSkillLevel = 1;
  }
  return;
}


// ClientPrecache  @ 0007a2c0  (line 1420)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientPrecache(void)

{
  float *pfVar1;
  float *pfVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  float local_54 [18];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector modelMins@[???]
                       Unresolved local var: Vector modelMaxs@[???]
                       Unresolved local var: Vector mins@[???]
                       Unresolved local var: Vector maxs@[???] */
  (*g_engfuncs.pfnPrecacheSound)("player/sprayer.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/plyrjmp8.wav");
  (*g_engfuncs.pfnPrecacheSound)("misc/talk.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pain1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pain2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pain3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pain4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pain5.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pain6.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/axhit1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/drown1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/drown2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/h2odeath.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/death1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/death2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/death3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/death4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/death5.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/gib.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_fallpain2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_fallpain3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_step1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_step2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_step3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_step4.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/npc_step1.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/npc_step2.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/npc_step3.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/npc_step4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_metal1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_metal2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_metal3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_metal4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_dirt1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_dirt2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_dirt3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_dirt4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_duct1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_duct2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_duct3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_duct4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_grate1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_grate2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_grate3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_grate4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_slosh1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_slosh2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_slosh3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_slosh4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_tile1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_tile2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_tile3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_tile4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_tile5.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_swim1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_swim2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_swim3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_swim4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_ladder1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_ladder2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_ladder3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_ladder4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_wade1.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_wade2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_wade3.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_wade4.wav");
  (*g_engfuncs.pfnPrecacheSound)("debris/wood1.wav");
  (*g_engfuncs.pfnPrecacheSound)("debris/wood2.wav");
  (*g_engfuncs.pfnPrecacheSound)("debris/wood3.wav");
  (*g_engfuncs.pfnPrecacheSound)("plats/train_use1.wav");
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark5.wav");
  (*g_engfuncs.pfnPrecacheSound)("buttons/spark6.wav");
  (*g_engfuncs.pfnPrecacheSound)("debris/glass1.wav");
  (*g_engfuncs.pfnPrecacheSound)("debris/glass2.wav");
  (*g_engfuncs.pfnPrecacheSound)("debris/glass3.wav");
  (*g_engfuncs.pfnPrecacheSound)("misc/r_tele3.wav");
  (*g_engfuncs.pfnPrecacheSound)("misc/r_tele4.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/medshot4.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/medshot5.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/r_item2.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/building.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/ax1.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/timer.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/itembk2.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/flashlight1.wav");
  (*g_engfuncs.pfnPrecacheSound)("items/flashlight1.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/bodysplat.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_pain2.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_pain4.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_pain5.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_pain6.wav");
  (*g_engfuncs.pfnPrecacheSound)("player/pl_pain7.wav");
  (*g_engfuncs.pfnPrecacheSound)("speech/saveme1.wav");
  (*g_engfuncs.pfnPrecacheSound)("speech/saveme2.wav");
  (*g_engfuncs.pfnPrecacheSound)("vox/stolen.wav");
  iVar4 = 0;
  do {
    pcVar3 = *(char **)((int)sNewClassModelFiles + iVar4 + 4);
    if (pcVar3 != (char *)0x0) {
      (*g_engfuncs.pfnPrecacheModel)(pcVar3);
    }
    pcVar3 = *(char **)((int)sOldClassModelFiles + iVar4 + 4);
    if (pcVar3 != (char *)0x0) {
      (*g_engfuncs.pfnPrecacheModel)(pcVar3);
    }
    iVar4 = iVar4 + 4;
  } while (iVar4 != 0x2c);
  iVar4 = 0;
  do {
    iVar5 = iVar4 + 4;
    (*g_engfuncs.pfnPrecacheModel)(*(char **)((int)sNewWeaponPModels + iVar4));
    (*g_engfuncs.pfnPrecacheModel)(*(char **)((int)sOldWeaponPModels + iVar4));
    iVar4 = iVar5;
  } while (iVar5 != 0x48);
  local_54[0] = -43.0;
  iVar4 = 0;
  local_54[1] = -14.0;
  local_54[2] = -49.0;
  local_54[3] = 43.0;
  local_54[4] = 11.0;
  local_54[5] = 49.0;
  do {
    pcVar3 = *(char **)((int)sNewClassModelFiles + iVar4 + 4);
    if (pcVar3 != (char *)0x0) {
      (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,local_54,local_54 + 3,pcVar3);
    }
    pcVar3 = *(char **)((int)sOldClassModelFiles + iVar4 + 4);
    if (pcVar3 != (char *)0x0) {
      (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,local_54,local_54 + 3,pcVar3);
    }
    iVar4 = iVar4 + 4;
  } while (iVar4 != 0x2c);
  iVar4 = 0;
  do {
    iVar5 = iVar4 + 4;
    (*g_engfuncs.pfnForceUnmodified)
              (force_exactfile,(float *)0x0,(float *)0x0,*(char **)((int)sNewWeaponPModels + iVar4))
    ;
    (*g_engfuncs.pfnForceUnmodified)
              (force_exactfile,(float *)0x0,(float *)0x0,*(char **)((int)sOldWeaponPModels + iVar4))
    ;
    iVar4 = iVar5;
  } while (iVar5 != 0x48);
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/w_grenade.mdl")
  ;
  (*g_engfuncs.pfnForceUnmodified)
            (force_exactfile,(float *)0x0,(float *)0x0,"models/spy_grenade.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/ngrenade.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/napalm.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/pipebomb.mdl");
  (*g_engfuncs.pfnForceUnmodified)
            (force_exactfile,(float *)0x0,(float *)0x0,"models/mirv_grenade.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/bomblet.mdl");
  (*g_engfuncs.pfnForceUnmodified)
            (force_exactfile,(float *)0x0,(float *)0x0,"models/emp_grenade.mdl");
  (*g_engfuncs.pfnForceUnmodified)
            (force_exactfile,(float *)0x0,(float *)0x0,"models/conc_grenade.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/caltrop.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/flag.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/ball.mdl");
  pfVar1 = local_54 + 6;
  pfVar2 = local_54 + 9;
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/detpack.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/w_rpg.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/rpgrocket.mdl")
  ;
  local_54[6] = -32.0;
  local_54[7] = -32.0;
  local_54[8] = -32.0;
  local_54[9] = 32.0;
  local_54[10] = 32.0;
  local_54[0xb] = 32.0;
  (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,pfVar1,pfVar2,"models/base.mdl");
  local_54[6] = -24.0;
  local_54[7] = -24.0;
  local_54[8] = -24.0;
  (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,pfVar1,pfVar2,"models/sentry1.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,pfVar1,pfVar2,"models/sentry2.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,pfVar1,pfVar2,"models/sentry3.mdl");
  local_54[9] = 16.0;
  local_54[10] = 64.0;
  local_54[0xb] = 16.0;
  (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,pfVar1,pfVar2,"models/dispenser.mdl");
  local_54[0xf] = 29.0;
  local_54[0x10] = 26.0;
  local_54[0x11] = 12.0;
  local_54[0xc] = -29.0;
  local_54[0xd] = -29.0;
  local_54[0xe] = -1.0;
  (*g_engfuncs.pfnForceUnmodified)
            (force_model_specifybounds,local_54 + 0xc,local_54 + 0xf,"models/teleporter.mdl");
  (*g_engfuncs.pfnForceUnmodified)
            (force_exactfile,(float *)0x0,(float *)0x0,"sprites/playerflame.spr");
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"sprites/fthrow.spr");
  UTIL_PrecacheOther("detpack");
  (*g_engfuncs.pfnPrecacheSound)("ambience/flameburst1.wav");
  (*g_engfuncs.pfnPrecacheSound)("ambience/steamburst1.wav");
  (*g_engfuncs.pfnPrecacheSound)("misc/b1.wav");
  (*g_engfuncs.pfnPrecacheSound)("misc/b2.wav");
  (*g_engfuncs.pfnPrecacheSound)("misc/party1.wav");
  (*g_engfuncs.pfnPrecacheSound)("misc/party2.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/wpn_hudoff.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/wpn_hudon.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/wpn_moveselect.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/wpn_select.wav");
  (*g_engfuncs.pfnPrecacheSound)("common/wpn_denyselect.wav");
  return;
}


// GetGameDescription  @ 0007ad10  (line 1666)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * GetGameDescription(void)

{
  return "Team Fortress Classic";
}


// Sys_Error  @ 0007ad20  (line 1676)

void Sys_Error(char *error_string)

{
  return;
}


// PlayerCustomization  @ 0007ad30  (line 1690)

void PlayerCustomization(edict_t *pEntity,customization_t *pCust)

{
  resourcetype_t rVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???] */
  if ((pEntity == (edict_t *)0x0) || (pEntity->pvPrivateData == (CBasePlayer *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0007adaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_console,"PlayerCustomization:  Couldn\'t get player!\n");
    return;
  }
  if (pCust == (customization_t *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0007adc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_console,"PlayerCustomization:  NULL customization!\n");
    return;
  }
  rVar1 = (pCust->resource).type;
  if (t_model < rVar1) {
    if (rVar1 == t_decal) {
      CBasePlayer::SetCustomDecalFrames(pEntity->pvPrivateData,pCust->nUserData2);
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x0007ad82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_console,"PlayerCustomization:  Unknown customization type!\n");
    return;
  }
  return;
}


// SpectatorConnect  @ 0007add0  (line 1730)

void SpectatorConnect(edict_t *pEntity)

{
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBaseSpectator * pPlayer@[???] */
  if ((pEntity != (edict_t *)0x0) && (pEntity->pvPrivateData != (CBaseSpectator *)0x0)) {
    CBaseSpectator::Spawn(pEntity->pvPrivateData);
    return;
  }
  return;
}


// SpectatorDisconnect  @ 0007ae00  (line 1746)

void SpectatorDisconnect(edict_t *pEntity)

{
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBaseSpectator * pPlayer@[???] */
  if ((pEntity != (edict_t *)0x0) && (pEntity->pvPrivateData != (CBaseSpectator *)0x0)) {
    CBaseSpectator::SpectatorDisconnect(pEntity->pvPrivateData);
    return;
  }
  return;
}


// SpectatorThink  @ 0007ae30  (line 1762)

void SpectatorThink(edict_t *pEntity)

{
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBaseSpectator * pPlayer@[???] */
  if ((pEntity != (edict_t *)0x0) && (pEntity->pvPrivateData != (CBaseSpectator *)0x0)) {
    CBaseSpectator::SpectatorThink(pEntity->pvPrivateData);
    return;
  }
  return;
}


// SetupVisibility  @ 0007ae60  (line 1789)

void SetupVisibility(edict_t *pViewEntity,edict_t *pClient,uchar **pvs,uchar **pas)

{
  uchar *puVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  void *pvVar4;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector org@[???]
                       Unresolved local var: edict_t * pView@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???] */
  if (pViewEntity == (edict_t *)0x0) {
    pViewEntity = pClient;
  }
  if (((pClient->v).flags & 0x100000) == 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((pClient == (edict_t *)0x0) &&
       (pClient = (*g_engfuncs.pfnPEntityOfEntOffset)(0), pClient == (edict_t *)0x0)) {
      pvVar4 = (void *)0x0;
    }
    else {
      pvVar4 = pClient->pvPrivateData;
    }
    if (*(int *)(*(int *)((int)pvVar4 + 4) + 0x248) != 0) {
      iVar2 = EHANDLE::operator_int((EHANDLE *)((int)pvVar4 + 0x6bc));
      if (iVar2 != 0) {
        pCVar3 = EHANDLE::operator->((EHANDLE *)((int)pvVar4 + 0x6bc));
        pViewEntity = pCVar3->pev->pContainingEntity;
      }
    }
    local_10 = (pViewEntity->v).origin.z + (pViewEntity->v).view_ofs.z;
    local_14 = (pViewEntity->v).origin.y + (pViewEntity->v).view_ofs.y;
    local_18 = (pViewEntity->v).origin.x + (pViewEntity->v).view_ofs.x;
    if (((pViewEntity->v).flags & 0x4000) != 0) {
      local_18 = local_18 + 0.0;
      local_14 = local_14 + 0.0;
      local_10 = local_10 - 18.0;
    }
    puVar1 = (*g_engfuncs.pfnSetFatPVS)(&local_18);
    *pvs = puVar1;
    puVar1 = (*g_engfuncs.pfnSetFatPAS)(&local_18);
    *pas = puVar1;
    return;
  }
  *pvs = (uchar *)0x0;
  *pas = (uchar *)0x0;
  return;
}


// AddToFullPack  @ 0007afa0  (line 1842)

int AddToFullPack(entity_state_s *state,int e,edict_t *ent,edict_t *host,int hostflags,int player,
                 uchar *pSet)

{
  int *piVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  edict_t *peVar6;
  uint uVar7;
  entity_state_s *peVar8;
  byte *pbVar9;
  void *pvVar10;
  bool bVar11;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar6 = ent;
  if ((ent == (edict_t *)0x0) &&
     (peVar6 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar6 == (edict_t *)0x0)) {
    pvVar10 = (void *)0x0;
  }
  else {
    pvVar10 = peVar6->pvPrivateData;
  }
  if ((((((ent->v).effects & 0x80) == 0) || (ent == host)) && ((ent->v).modelindex != 0)) &&
     (gpGlobals->pStringBase + (ent->v).model != (char *)0x0)) {
    uVar7 = (ent->v).flags;
    if ((uVar7 & 0x4000000) == 0) {
      if (ent != host) {
        iVar4 = (*g_engfuncs.pfnCheckVisibility)(ent,pSet);
        if (iVar4 == 0) {
          return 0;
        }
        uVar7 = (ent->v).flags;
      }
    }
    else if (ent != host) {
      return 0;
    }
    if ((((uVar7 & 0x100) == 0) || ((hostflags & 1U) == 0)) || (host != (ent->v).owner)) {
      iVar4 = (host->v).groupinfo;
      if (iVar4 != 0) {
        UTIL_SetGroupTrace(iVar4,0);
        uVar7 = (ent->v).groupinfo;
        if (uVar7 != 0) {
          if (g_groupop == 0) {
            if (((host->v).groupinfo & uVar7) == 0) {
              return 0;
            }
          }
          else if ((g_groupop == 1) && (((host->v).groupinfo & uVar7) != 0)) {
            return 0;
          }
        }
        UTIL_UnsetGroupTrace();
      }
      bVar11 = ((uint)state & 1) != 0;
      uVar7 = 0x154;
      peVar8 = state;
      if (bVar11) {
        *(undefined1 *)&state->entityType = 0;
        peVar8 = (entity_state_s *)((int)&state->entityType + 1);
        uVar7 = 0x153;
      }
      if (((uint)peVar8 & 2) != 0) {
        *(undefined2 *)&peVar8->entityType = 0;
        uVar7 = uVar7 - 2;
        peVar8 = (entity_state_s *)((int)&peVar8->entityType + 2);
      }
      uVar2 = 0;
      do {
        uVar5 = uVar2;
        pbVar9 = peVar8->controller + (uVar5 - 0x68);
        pbVar9[0] = '\0';
        pbVar9[1] = '\0';
        pbVar9[2] = '\0';
        pbVar9[3] = '\0';
        pbVar9 = peVar8->controller + (uVar5 - 100);
        pbVar9[0] = '\0';
        pbVar9[1] = '\0';
        pbVar9[2] = '\0';
        pbVar9[3] = '\0';
        uVar2 = uVar5 + 8;
      } while (uVar5 + 8 < (uVar7 & 0xfffffff8));
      pbVar9 = peVar8->controller + (uVar5 - 0x60);
      if ((uVar7 & 4) != 0) {
        pbVar9[0] = '\0';
        pbVar9[1] = '\0';
        pbVar9[2] = '\0';
        pbVar9[3] = '\0';
        pbVar9 = pbVar9 + 4;
      }
      if ((uVar7 & 2) != 0) {
        pbVar9[0] = '\0';
        pbVar9[1] = '\0';
        pbVar9 = pbVar9 + 2;
      }
      if (bVar11) {
        *pbVar9 = '\0';
      }
      state->entityType = 1;
      state->number = e;
      if (((ent->v).flags & 0x20000000) != 0) {
        state->entityType = 2;
      }
      state->animtime = (float)(int)((ent->v).animtime * 1000.0) / 1000.0;
      (state->origin).x = (ent->v).origin.x;
      (state->origin).y = (ent->v).origin.y;
      (state->origin).z = (ent->v).origin.z;
      (state->angles).x = (ent->v).angles.x;
      (state->angles).y = (ent->v).angles.y;
      (state->angles).z = (ent->v).angles.z;
      (state->mins).x = (ent->v).mins.x;
      (state->mins).y = (ent->v).mins.y;
      (state->mins).z = (ent->v).mins.z;
      (state->maxs).x = (ent->v).maxs.x;
      (state->maxs).y = (ent->v).maxs.y;
      (state->maxs).z = (ent->v).maxs.z;
      (state->startpos).x = (ent->v).startpos.x;
      (state->startpos).y = (ent->v).startpos.y;
      (state->startpos).z = (ent->v).startpos.z;
      (state->endpos).x = (ent->v).endpos.x;
      (state->endpos).y = (ent->v).endpos.y;
      (state->endpos).z = (ent->v).endpos.z;
      state->impacttime = (ent->v).impacttime;
      state->starttime = (ent->v).starttime;
      state->modelindex = (ent->v).modelindex;
      state->frame = (ent->v).frame;
      if ((pvVar10 == (void *)0x0) || (*(int *)((int)pvVar10 + 0x2c0) == 0)) {
        sVar3 = (short)(ent->v).skin;
      }
      else {
        sVar3 = (short)*(int *)((int)pvVar10 + 0x2c0);
      }
      state->skin = sVar3;
      state->effects = (ent->v).effects;
      if ((((player == 0) && ((ent->v).animtime != 0.0)) && ((ent->v).velocity.x == 0.0)) &&
         (((ent->v).velocity.y == 0.0 && ((ent->v).velocity.z == 0.0)))) {
        state->eflags = state->eflags | 1;
      }
      state->scale = (ent->v).scale;
      state->solid = (short)(ent->v).solid;
      state->colormap = (ent->v).colormap;
      state->movetype = (ent->v).movetype;
      state->sequence = (ent->v).sequence;
      state->framerate = (ent->v).framerate;
      if ((pvVar10 == (void *)0x0) || (iVar4 = *(int *)((int)pvVar10 + 700), iVar4 == 0)) {
        iVar4 = (ent->v).body;
      }
      state->body = iVar4;
      state->controller[0] = (ent->v).controller[0];
      state->controller[1] = (ent->v).controller[1];
      state->controller[2] = (ent->v).controller[2];
      state->controller[3] = (ent->v).controller[3];
      state->blending[0] = (ent->v).blending[0];
      state->blending[1] = (ent->v).blending[1];
      state->rendermode = (ent->v).rendermode;
      state->renderamt = (int)(ent->v).renderamt;
      state->renderfx = (ent->v).renderfx;
      (state->rendercolor).r = (byte)(int)(ent->v).rendercolor.x;
      (state->rendercolor).g = (byte)(int)(ent->v).rendercolor.y;
      (state->rendercolor).b = (byte)(int)(ent->v).rendercolor.z;
      state->aiment = 0;
      peVar6 = (ent->v).aiment;
      if (peVar6 != (edict_t *)0x0) {
        iVar4 = (*g_engfuncs.pfnIndexOfEdict)(peVar6);
        state->aiment = iVar4;
      }
      state->owner = 0;
      peVar6 = (ent->v).owner;
                    /* Unresolved local var: int owner@[???] */
      if (((peVar6 != (edict_t *)0x0) && (iVar4 = (*g_engfuncs.pfnIndexOfEdict)(peVar6), 0 < iVar4))
         && (iVar4 <= gpGlobals->maxClients)) {
        state->owner = iVar4;
      }
      state->fuser1 = 0.0;
      if (player != 0) {
        (state->basevelocity).x = (ent->v).basevelocity.x;
        (state->basevelocity).y = (ent->v).basevelocity.y;
        (state->basevelocity).z = (ent->v).basevelocity.z;
        if ((pvVar10 == (void *)0x0) || ((*(byte *)((int)pvVar10 + 0x2c4) & 1) == 0)) {
          iVar4 = (*g_engfuncs.pfnModelIndex)(gpGlobals->pStringBase + (ent->v).weaponmodel);
          state->weaponmodel = iVar4;
        }
        else {
          state->weaponmodel = 0;
        }
        state->gaitsequence = (ent->v).gaitsequence;
        state->spectator = (ent->v).flags & 0x4000000;
        state->friction = (ent->v).friction;
        state->gravity = (ent->v).gravity;
        state->team = (ent->v).team;
        state->playerclass = (ent->v).playerclass;
        state->usehull = (uint)(ent->v).flags >> 0xe & 1;
        state->health = (int)(ent->v).health;
        if ((pvVar10 != (void *)0x0) && (*(int *)((int)pvVar10 + 0x2b8) != 0)) {
          state->fuser1 = 1.0;
        }
      }
      if ((((ent != (edict_t *)0x0) && (piVar1 = ent->pvPrivateData, piVar1 != (int *)0x0)) &&
          (iVar4 = (**(code **)(*piVar1 + 0x28))(piVar1), iVar4 != 0)) &&
         (iVar4 = (**(code **)(*piVar1 + 0x28))(piVar1), iVar4 != 1)) {
        state->eflags = state->eflags | 2;
        return 1;
      }
      state->eflags = state->eflags & 0xfd;
      return 1;
    }
  }
  return 0;
}


// CreateBaseline  @ 0007b5e0  (line 2047)

void CreateBaseline(int player,int eindex,entity_state_s *baseline,edict_s *entity,
                   int playermodelindex,Vector player_mins,Vector player_maxs)

{
  float fVar1;
  vec_t vVar2;
  
  (baseline->origin).x = (entity->v).origin.x;
  (baseline->origin).y = (entity->v).origin.y;
  (baseline->origin).z = (entity->v).origin.z;
  (baseline->angles).x = (entity->v).angles.x;
  (baseline->angles).y = (entity->v).angles.y;
  (baseline->angles).z = (entity->v).angles.z;
  baseline->frame = (entity->v).frame;
  baseline->skin = (short)(entity->v).skin;
  baseline->rendermode = (uint)(byte)(entity->v).rendermode;
  baseline->renderamt = (int)(entity->v).renderamt & 0xff;
  (baseline->rendercolor).r = (byte)(int)(entity->v).rendercolor.x;
  (baseline->rendercolor).g = (byte)(int)(entity->v).rendercolor.y;
  (baseline->rendercolor).b = (byte)(int)(entity->v).rendercolor.z;
  baseline->renderfx = (uint)(byte)(entity->v).renderfx;
  if (player == 0) {
    (baseline->mins).x = (entity->v).mins.x;
    (baseline->mins).y = (entity->v).mins.y;
    (baseline->mins).z = (entity->v).mins.z;
    (baseline->maxs).x = (entity->v).maxs.x;
    (baseline->maxs).y = (entity->v).maxs.y;
    vVar2 = (entity->v).maxs.z;
    baseline->colormap = 0;
    (baseline->maxs).z = vVar2;
    baseline->modelindex = (entity->v).modelindex;
    baseline->movetype = (entity->v).movetype;
    baseline->scale = (entity->v).scale;
    baseline->solid = (short)(entity->v).solid;
    baseline->framerate = (entity->v).framerate;
    baseline->gravity = (entity->v).gravity;
    return;
  }
  (baseline->mins).x = *(vec_t *)player_mins.x;
  (baseline->mins).y = *(vec_t *)((int)player_mins.x + 4);
  (baseline->mins).z = *(vec_t *)((int)player_mins.x + 8);
  (baseline->maxs).x = *(vec_t *)player_mins.y;
  (baseline->maxs).y = *(vec_t *)((int)player_mins.y + 4);
  vVar2 = *(vec_t *)((int)player_mins.y + 8);
  baseline->friction = 1.0;
  baseline->movetype = 3;
  (baseline->maxs).z = vVar2;
  baseline->colormap = eindex;
  baseline->modelindex = playermodelindex;
  fVar1 = (entity->v).scale;
  baseline->solid = 3;
  baseline->framerate = 1.0;
  baseline->scale = fVar1;
  baseline->gravity = 1.0;
  baseline->playerclass = (entity->v).playerclass;
  baseline->fov = (entity->v).fov;
  return;
}


// Entity_FieldInit  @ 0007b7c0  (line 2121)

void Entity_FieldInit(delta_s *pFields)

{
  entity_field_alias[0].field = (*g_engfuncs.pfnDeltaFindField)(pFields,entity_field_alias[0].name);
  entity_field_alias[1].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1928c4);
  entity_field_alias[2].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1928e8);
  entity_field_alias[3].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x19290c);
  entity_field_alias[4].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x192930);
  entity_field_alias[5].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x192954);
  return;
}


// Entity_Encode  @ 0007b860  (line 2139)

void Entity_Encode(delta_s *pFields,uchar *from,uchar *to)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
                    /* Unresolved local var: entity_state_t * f@[???]
                       Unresolved local var: entity_state_t * t@[???]
                       Unresolved local var: int localplayer@[???] */
  if (Entity_Encode::initialized == 0) {
    Entity_FieldInit(pFields);
    Entity_Encode::initialized = 1;
    iVar2 = *(int *)(to + 4);
    iVar1 = (*g_engfuncs.pfnGetCurrentPlayer)();
    if (iVar2 + -1 != iVar1) goto LAB_0007b8a1;
  }
  else {
    iVar2 = *(int *)(to + 4);
    iVar1 = (*g_engfuncs.pfnGetCurrentPlayer)();
    if (iVar2 + -1 != iVar1) goto LAB_0007b8a1;
  }
  (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[0].field);
  (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[1].field);
  (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[2].field);
LAB_0007b8a1:
  if ((*(float *)(to + 0xfc) == 0.0) || (*(float *)(to + 0x100) == 0.0)) {
    iVar1 = *(int *)(to + 0x58);
    iVar2 = *(int *)(to + 0x94);
  }
  else {
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[0].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[1].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[2].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[3].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[4].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[5].field);
    iVar2 = *(int *)(to + 0x94);
    iVar1 = *(int *)(to + 0x58);
  }
  if ((iVar1 == 0xc) && (bVar3 = iVar2 != 0, iVar2 = 0, bVar3)) {
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[0].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[1].field);
                    /* WARNING: Could not recover jumptable at 0x0007b9fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[2].field);
    return;
  }
  if (*(int *)(from + 0x94) != iVar2) {
    (*g_engfuncs.pfnDeltaSetFieldByIndex)(pFields,entity_field_alias[0].field);
    (*g_engfuncs.pfnDeltaSetFieldByIndex)(pFields,entity_field_alias[1].field);
                    /* WARNING: Could not recover jumptable at 0x0007b913. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnDeltaSetFieldByIndex)(pFields,entity_field_alias[2].field);
    return;
  }
  return;
}


// Player_FieldInit  @ 0007ba90  (line 2196)

void Player_FieldInit(delta_s *pFields)

{
  player_field_alias[0].field = (*g_engfuncs.pfnDeltaFindField)(pFields,player_field_alias[0].name);
  player_field_alias[1].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x192844);
  player_field_alias[2].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x192868);
  return;
}


// Player_Encode  @ 00076e20  (line 2210)

void Player_Encode(delta_s *pFields,uchar *from,uchar *to)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
                    /* Unresolved local var: entity_state_t * f@[???]
                       Unresolved local var: entity_state_t * t@[???]
                       Unresolved local var: int localplayer@[???] */
  if (Player_Encode::initialized == 0) {
    player_field_alias[0].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,player_field_alias[0].name);
    player_field_alias[1].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,player_field_alias[1].name);
    player_field_alias[2].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,player_field_alias[2].name);
    Player_Encode::initialized = 1;
    iVar2 = *(int *)(to + 4);
    iVar1 = (*g_engfuncs.pfnGetCurrentPlayer)();
    if (iVar2 + -1 == iVar1) goto LAB_00076f44;
  }
  else {
    iVar2 = *(int *)(to + 4);
    iVar1 = (*g_engfuncs.pfnGetCurrentPlayer)();
    if (iVar2 + -1 == iVar1) {
LAB_00076f44:
      (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[0].field);
      (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[1].field);
      (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[2].field);
      iVar2 = *(int *)(to + 0x94);
      iVar1 = *(int *)(to + 0x58);
      goto joined_r0x00076e6a;
    }
  }
  iVar1 = *(int *)(to + 0x58);
  iVar2 = *(int *)(to + 0x94);
joined_r0x00076e6a:
  if ((iVar1 == 0xc) && (bVar3 = iVar2 != 0, iVar2 = 0, bVar3)) {
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[0].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[1].field);
                    /* WARNING: Could not recover jumptable at 0x00076fdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[2].field);
    return;
  }
  if (*(int *)(from + 0x94) != iVar2) {
    (*g_engfuncs.pfnDeltaSetFieldByIndex)(pFields,entity_field_alias[0].field);
    (*g_engfuncs.pfnDeltaSetFieldByIndex)(pFields,entity_field_alias[1].field);
                    /* WARNING: Could not recover jumptable at 0x00076ebc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnDeltaSetFieldByIndex)(pFields,entity_field_alias[2].field);
    return;
  }
  return;
}


// Custom_Entity_FieldInit  @ 0007baf0  (line 2272)

void Custom_Entity_FieldInit(delta_s *pFields)

{
  custom_entity_field_alias[0].field =
       (*g_engfuncs.pfnDeltaFindField)(pFields,custom_entity_field_alias[0].name);
  custom_entity_field_alias[1].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1926e4);
  custom_entity_field_alias[2].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x192708);
  custom_entity_field_alias[3].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x19272c);
  custom_entity_field_alias[4].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x192750);
  custom_entity_field_alias[5].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x192774);
  custom_entity_field_alias[6].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x192798);
  custom_entity_field_alias[7].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1927bc);
  custom_entity_field_alias[8].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1927e0);
  return;
}


// Custom_Encode  @ 0007bbd0  (line 2293)

void Custom_Encode(delta_s *pFields,uchar *from,uchar *to)

{
  uint uVar1;
  
                    /* Unresolved local var: entity_state_t * f@[???]
                       Unresolved local var: entity_state_t * t@[???]
                       Unresolved local var: int beamType@[???] */
  if (Custom_Encode::initialized == 0) {
    Custom_Entity_FieldInit(pFields);
    Custom_Encode::initialized = 1;
  }
  uVar1 = *(uint *)(to + 0x48) & 0xf;
  if (uVar1 < 2) {
    if (uVar1 == 0) goto LAB_0007bc78;
  }
  else {
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[0].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[1].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[2].field);
  }
  (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[3].field);
  (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[4].field);
  (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[5].field);
LAB_0007bc78:
  if (1 < uVar1 - 1) {
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[6].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[7].field);
  }
  if ((int)*(float *)(from + 0x5c) == (int)*(float *)(to + 0x5c)) {
                    /* WARNING: Could not recover jumptable at 0x0007bd10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[8].field);
    return;
  }
  return;
}


// RegisterEncoders  @ 0007bd20  (line 2345)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void RegisterEncoders(void)

{
  (*g_engfuncs.pfnDeltaAddEncoder)("Entity_Encode",Entity_Encode);
  (*g_engfuncs.pfnDeltaAddEncoder)("Custom_Encode",Custom_Encode);
  (*g_engfuncs.pfnDeltaAddEncoder)("Player_Encode",Player_Encode);
  return;
}


// GetWeaponData  @ 0007bd70  (line 2359)

int GetWeaponData(edict_s *player,weapon_data_s *info)

{
  float fVar1;
  void *pvVar2;
  int *piVar3;
  int *piVar4;
  edict_t *peVar5;
  uint uVar6;
  uint uVar7;
  weapon_data_s *pwVar8;
  bool bVar9;
  byte bVar10;
  undefined4 *local_54;
  uint local_48 [14];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: weapon_data_t * item@[???]
                       Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pl@[???]
                       Unresolved local var: CBasePlayerWeapon * gun@[???]
                       Unresolved local var: ItemInfo II@[???] */
  bVar10 = 0;
  peVar5 = (player->v).pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar5 == (edict_t *)0x0) &&
     (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
    bVar9 = ((uint)info & 1) != 0;
    uVar7 = 0xb00;
    if (bVar9) {
      *(undefined1 *)&info->m_iId = 0;
      info = (weapon_data_s *)((int)&info->m_iId + 1);
      uVar7 = 0xaff;
    }
    if (((uint)info & 2) != 0) {
      *(undefined2 *)&info->m_iId = 0;
      uVar7 = uVar7 - 2;
      info = (weapon_data_s *)((int)&info->m_iId + 2);
    }
    if (((uint)info & 4) != 0) {
      info->m_iId = 0;
      uVar7 = uVar7 - 4;
      info = (weapon_data_s *)&info->m_iClip;
    }
    for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      info->m_iId = 0;
      info = (weapon_data_s *)((int)info + (uint)bVar10 * -8 + 4);
    }
    if ((uVar7 & 2) != 0) {
      *(undefined2 *)&info->m_iId = 0;
      info = (weapon_data_s *)((int)&info->m_iId + 2);
    }
    if (bVar9) {
      *(undefined1 *)&info->m_iId = 0;
    }
  }
  else {
    bVar9 = ((uint)info & 1) != 0;
    pvVar2 = peVar5->pvPrivateData;
    uVar7 = 0xb00;
    pwVar8 = info;
    if (bVar9) {
      *(undefined1 *)&info->m_iId = 0;
      pwVar8 = (weapon_data_s *)((int)&info->m_iId + 1);
      uVar7 = 0xaff;
    }
    if (((uint)pwVar8 & 2) != 0) {
      *(undefined2 *)&pwVar8->m_iId = 0;
      uVar7 = uVar7 - 2;
      pwVar8 = (weapon_data_s *)((int)&pwVar8->m_iId + 2);
    }
    if (((uint)pwVar8 & 4) != 0) {
      pwVar8->m_iId = 0;
      uVar7 = uVar7 - 4;
      pwVar8 = (weapon_data_s *)&pwVar8->m_iClip;
    }
    for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      pwVar8->m_iId = 0;
      pwVar8 = (weapon_data_s *)((int)pwVar8 + (uint)bVar10 * -8 + 4);
    }
    if ((uVar7 & 2) != 0) {
      *(undefined2 *)&pwVar8->m_iId = 0;
      pwVar8 = (weapon_data_s *)((int)&pwVar8->m_iId + 2);
    }
    if (bVar9) {
      *(undefined1 *)&pwVar8->m_iId = 0;
    }
    local_54 = (undefined4 *)((int)pvVar2 + 0x8e4);
                    /* Unresolved local var: CBasePlayerItem * pPlayerItem@[???] */
    if (pvVar2 != (void *)0x0) {
      do {
        for (piVar3 = (int *)*local_54; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x125]) {
          piVar4 = (int *)(**(code **)(*piVar3 + 0x14c))(piVar3);
          uVar7 = 0;
          if (piVar4 != (int *)0x0) {
            do {
              *(undefined4 *)((int)local_48 + uVar7) = 0;
              *(undefined4 *)((int)local_48 + uVar7 + 4) = 0;
              uVar7 = uVar7 + 8;
            } while (uVar7 < 0x28);
            *(undefined4 *)((int)local_48 + uVar7) = 0;
            (**(code **)(*piVar4 + 0x114))(piVar4,local_48);
            if (local_48[8] < 0x20) {
              pwVar8 = info + local_48[8];
              pwVar8->m_iId = local_48[8];
              pwVar8->m_iClip = piVar4[0x137];
              fVar1 = (float)piVar4[0x12d];
              if (fVar1 < -0.001) {
                fVar1 = -0.001;
              }
              pwVar8->m_flPumpTime = fVar1;
              fVar1 = (float)piVar4[299];
              if (fVar1 < -0.001) {
                fVar1 = -0.001;
              }
              pwVar8->m_flTimeWeaponIdle = fVar1;
              fVar1 = (float)piVar4[0x129];
              if (fVar1 < -0.001) {
                fVar1 = -0.001;
              }
              pwVar8->m_flNextPrimaryAttack = fVar1;
              fVar1 = (float)piVar4[0x12a];
              if (fVar1 < -0.001) {
                fVar1 = -0.001;
              }
              pwVar8->m_flNextSecondaryAttack = fVar1;
              fVar1 = -0.001;
              if (-0.001 <= (float)piVar4[300]) {
                fVar1 = (float)piVar4[300];
              }
              pwVar8->m_flNextReload = fVar1;
              fVar1 = -1.0;
              if (-1.0 <= (float)piVar4[0x130]) {
                fVar1 = (float)piVar4[0x130];
              }
              pwVar8->m_fNextAimBonus = fVar1;
              pwVar8->m_fInReload = piVar4[0x133];
              pwVar8->m_fInSpecialReload = piVar4[0x134];
              pwVar8->m_fReloadTime = (float)piVar4[0x12e];
              pwVar8->m_fAimedDamage = (float)piVar4[0x12f];
              pwVar8->m_fInZoom = piVar4[0x131];
              pwVar8->m_iWeaponState = piVar4[0x132];
            }
          }
        }
        local_54 = local_54 + 1;
      } while (local_54 != (undefined4 *)((int)pvVar2 + 0x8fc));
    }
  }
  return 1;
}


// UpdateClientData  @ 0007c030  (line 2432)

void UpdateClientData(edict_s *ent,int sendweapons,clientdata_s *cd)

{
  _2globalvars_t *p1Var1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  CBaseEntity *pCVar6;
  edict_t *peVar7;
  bool bVar8;
  entvars_t *peVar9;
  uint uVar10;
  entvars_t *peVar11;
  void *pvVar12;
  int local_48 [14];
  
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pl@[???]
                       Unresolved local var: entvars_t * pevOrg@[???] */
  peVar7 = (ent->v).pContainingEntity;
  peVar9 = &ent->v;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar7 == (edict_t *)0x0) {
    peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar7 != (edict_t *)0x0) goto LAB_0007c053;
    pvVar12 = (void *)0x0;
  }
  else {
LAB_0007c053:
    pvVar12 = peVar7->pvPrivateData;
  }
  peVar11 = peVar9;
  if (*(int *)(*(int *)((int)pvVar12 + 4) + 0x244) == 4) {
    iVar3 = EHANDLE::operator_int((EHANDLE *)((int)pvVar12 + 0x6bc));
    if (iVar3 == 0) {
      bVar8 = pvVar12 != (void *)0x0 && sendweapons != 0;
      peVar9 = (entvars_t *)0x0;
    }
    else {
      pCVar6 = EHANDLE::operator->((EHANDLE *)((int)pvVar12 + 0x6bc));
      peVar11 = pCVar6->pev;
      peVar7 = peVar11->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      if (peVar7 == (edict_t *)0x0) {
        peVar7 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
        if (peVar7 == (edict_t *)0x0) {
          pvVar12 = (void *)0x0;
          bVar8 = false;
          goto LAB_0007c07c;
        }
      }
      pvVar12 = peVar7->pvPrivateData;
      bVar8 = pvVar12 != (void *)0x0 && sendweapons != 0;
    }
  }
  else {
    bVar8 = pvVar12 != (void *)0x0 && sendweapons != 0;
    peVar9 = (entvars_t *)0x0;
  }
LAB_0007c07c:
  cd->flags = peVar11->flags;
  p1Var1 = gpGlobals;
  cd->health = peVar11->health;
  iVar3 = (*g_engfuncs.pfnModelIndex)(p1Var1->pStringBase + peVar11->viewmodel);
  cd->viewmodel = iVar3;
  cd->waterlevel = peVar11->waterlevel;
  cd->watertype = peVar11->watertype;
  cd->weapons = peVar11->weapons;
  (cd->origin).x = (peVar11->origin).x;
  (cd->origin).y = (peVar11->origin).y;
  (cd->origin).z = (peVar11->origin).z;
  (cd->velocity).x = (peVar11->velocity).x;
  (cd->velocity).y = (peVar11->velocity).y;
  (cd->velocity).z = (peVar11->velocity).z;
  (cd->view_ofs).x = (peVar11->view_ofs).x;
  (cd->view_ofs).y = (peVar11->view_ofs).y;
  (cd->view_ofs).z = (peVar11->view_ofs).z;
  (cd->punchangle).x = (peVar11->punchangle).x;
  (cd->punchangle).y = (peVar11->punchangle).y;
  (cd->punchangle).z = (peVar11->punchangle).z;
  cd->bInDuck = peVar11->bInDuck;
  cd->flTimeStepSound = peVar11->flTimeStepSound;
  cd->flDuckTime = peVar11->flDuckTime;
  cd->flSwimTime = peVar11->flSwimTime;
  cd->waterjumptime = (int)peVar11->teleport_time;
  pcVar4 = (*g_engfuncs.pfnGetPhysicsInfoString)(ent);
  __strcpy_chk(cd->physinfo,pcVar4,0x100);
  cd->maxspeed = peVar11->maxspeed;
  cd->fov = peVar11->fov;
  cd->weaponanim = peVar11->weaponanim;
  cd->pushmsec = peVar11->pushmsec;
  if (peVar9 == (entvars_t *)0x0) {
    cd->iuser1 = peVar11->iuser1;
    cd->iuser2 = peVar11->iuser2;
    cd->iuser3 = peVar11->iuser3;
    cd->iuser4 = peVar11->iuser4;
  }
  else {
    cd->iuser1 = peVar9->iuser1;
    cd->iuser2 = peVar9->iuser2;
    cd->iuser3 = peVar9->iuser2;
  }
  cd->deadflag = peVar11->deadflag;
  if (bVar8) {
    cd->ammo_shells = *(int *)((int)pvVar12 + 0xe4);
    cd->ammo_nails = *(int *)((int)pvVar12 + 0xec);
    cd->ammo_cells = *(int *)((int)pvVar12 + 0xf4);
    cd->ammo_rockets = *(int *)((int)pvVar12 + 0xfc);
    cd->m_flNextAttack = *(float *)((int)pvVar12 + 0x674);
    piVar5 = *(int **)((int)pvVar12 + 0x8fc);
    if (piVar5 != (int *)0x0) {
                    /* Unresolved local var: CBasePlayerWeapon * gun@[???] */
      piVar5 = (int *)(**(code **)(*piVar5 + 0x14c))(piVar5);
      if (piVar5 != (int *)0x0) {
                    /* Unresolved local var: ItemInfo II@[???] */
        uVar2 = 0;
        do {
          uVar10 = uVar2;
          *(undefined4 *)((int)local_48 + uVar10) = 0;
          *(undefined4 *)((int)local_48 + uVar10 + 4) = 0;
          uVar2 = uVar10 + 8;
        } while (uVar10 + 8 < 0x28);
        *(undefined4 *)((int)local_48 + uVar10 + 8) = 0;
        (**(code **)(*piVar5 + 0x114))(piVar5,local_48);
        cd->m_iId = local_48[8];
      }
    }
  }
  return;
}


// CmdStart  @ 0007c370  (line 2531)

void CmdStart(edict_t *player,usercmd_s *cmd,uint random_seed)

{
  void *pvVar1;
  int groupmask;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pl@[???] */
  peVar2 = (player->v).pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar2 != (edict_t *)0x0) ||
      (peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar2 != (edict_t *)0x0)) &&
     (pvVar1 = peVar2->pvPrivateData, pvVar1 != (void *)0x0)) {
    groupmask = *(int *)(*(int *)((int)pvVar1 + 4) + 0x240);
    if (groupmask != 0) {
      UTIL_SetGroupTrace(groupmask,0);
    }
    *(uint *)((int)pvVar1 + 0x6d0) = random_seed;
  }
  return;
}


// CmdEnd  @ 0007c3e0  (line 2554)

void CmdEnd(edict_t *player)

{
  void *pvVar1;
  int iVar2;
  edict_t *peVar3;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pl@[???] */
  peVar3 = (player->v).pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((peVar3 != (edict_t *)0x0) ||
      (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 != (edict_t *)0x0)) &&
     (pvVar1 = peVar3->pvPrivateData, pvVar1 != (void *)0x0)) {
    if (*(int *)(*(int *)((int)pvVar1 + 4) + 0x240) == 0) {
      iVar2 = *(int *)(*(int *)((int)pvVar1 + 4) + 0x170);
    }
    else {
      UTIL_UnsetGroupTrace();
      iVar2 = *(int *)(*(int *)((int)pvVar1 + 4) + 0x170);
    }
    if (iVar2 == 5) {
      local_18.y = 16.0;
      local_18.z = -32.0;
      local_24.y = -16.0;
      local_24.z = -36.0;
      local_18.x = 16.0;
      local_24.x = -16.0;
      UTIL_SetSize(*(entvars_t **)((int)pvVar1 + 4),&local_24,&local_18);
      return;
    }
  }
  return;
}


// ConnectionlessPacket  @ 0007c4b0  (line 2585)

int ConnectionlessPacket
              (netadr_s *net_from,char *args,char *response_buffer,int *response_buffer_size)

{
                    /* Unresolved local var: int max_buffer_size@[???] */
  *response_buffer_size = 0;
  return 0;
}


// GetHullBounds  @ 0007c4c0  (line 2608)

int GetHullBounds(int hullnumber,float *mins,float *maxs)

{
                    /* Unresolved local var: int iret@[???] */
  return (uint)((uint)hullnumber < 3);
}


// CreateInstancedBaselines  @ 0007c4d0  (line 2639)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CreateInstancedBaselines(void)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  edict_t *peVar4;
  CTFCaltrop *this;
  entvars_t *peVar5;
  int in_GS_OFFSET;
  CBaseEntity *local_180;
  entity_state_s local_174;
  int local_20;
  
                    /* Unresolved local var: int iret@[???]
                       Unresolved local var: entity_state_t state@[???]
                       Unresolved local var: Vector fake@[???]
                       Unresolved local var: CTFCaltrop * pc@[DW_OP_reg6(ESI)]
                       Unresolved local var: CWeaponBox * wb@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = 0;
  do {
    uVar3 = uVar2;
    pbVar1 = local_174.controller + (uVar3 - 0x68);
    pbVar1[0] = '\0';
    pbVar1[1] = '\0';
    pbVar1[2] = '\0';
    pbVar1[3] = '\0';
    pbVar1 = local_174.controller + (uVar3 - 100);
    pbVar1[0] = '\0';
    pbVar1[1] = '\0';
    pbVar1[2] = '\0';
    pbVar1[3] = '\0';
    uVar2 = uVar3 + 8;
  } while (uVar3 + 8 < 0x150);
  pbVar1 = local_174.controller + (uVar3 - 0x60);
  pbVar1[0] = '\0';
  pbVar1[1] = '\0';
  pbVar1[2] = '\0';
  pbVar1[3] = '\0';
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar4 = (*g_engfuncs.pfnCreateEntity)();
  peVar5 = (entvars_t *)0x0;
  if (peVar4 != (edict_t *)0x0) {
    peVar5 = &peVar4->v;
  }
  if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar5->pContainingEntity->pvPrivateData, this == (CTFCaltrop *)0x0)) {
    this = CBaseEntity::operator_new(0x478,peVar5);
    (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltrop_0015f204;
    (this->super_CBaseEntity).pev = peVar5;
  }
  CTFCaltrop::ScatterDrop(this,(CBaseEntity *)0x0);
  peVar4 = ((this->super_CBaseEntity).pev)->pContainingEntity;
  local_174.origin.x = (peVar4->v).origin.x;
  local_174.frame = (peVar4->v).frame;
  local_174.origin.y = (peVar4->v).origin.y;
  local_174.origin.z = (peVar4->v).origin.z;
  local_174.angles.x = (peVar4->v).angles.x;
  local_174.angles.y = (peVar4->v).angles.y;
  local_174.angles.z = (peVar4->v).angles.z;
  local_174.skin = (short)(peVar4->v).skin;
  local_174.rendermode = (int)(byte)(peVar4->v).rendermode;
  local_174.renderamt = (int)(peVar4->v).renderamt & 0xff;
  local_174.rendercolor.r = (byte)(int)(peVar4->v).rendercolor.x;
  local_174.rendercolor.g = (byte)(int)(peVar4->v).rendercolor.y;
  local_174.rendercolor.b = (byte)(int)(peVar4->v).rendercolor.z;
  local_174.renderfx = (int)(byte)(peVar4->v).renderfx;
  local_174.mins.x = (peVar4->v).mins.x;
  local_174.mins.y = (peVar4->v).mins.y;
  local_174.scale = (peVar4->v).scale;
  local_174.framerate = (peVar4->v).framerate;
  local_174.gravity = (peVar4->v).gravity;
  local_174.mins.z = (peVar4->v).mins.z;
  local_174.maxs.x = (peVar4->v).maxs.x;
  local_174.colormap = 0;
  local_174.maxs.y = (peVar4->v).maxs.y;
  local_174.maxs.z = (peVar4->v).maxs.z;
  local_174.modelindex = (peVar4->v).modelindex;
  local_174.movetype = (peVar4->v).movetype;
  local_174.solid = (short)(peVar4->v).solid;
  (*g_engfuncs.pfnCreateInstancedBaseline)(((this->super_CBaseEntity).pev)->classname,&local_174);
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar4 = (*g_engfuncs.pfnCreateEntity)();
  peVar5 = &peVar4->v;
  if (peVar4 == (edict_t *)0x0) {
    peVar5 = (entvars_t *)0x0;
  }
  if (peVar5->pContainingEntity != (edict_t *)0x0) {
    local_180 = peVar5->pContainingEntity->pvPrivateData;
    if (local_180 != (CBaseEntity *)0x0) {
      peVar5 = local_180->pev;
      goto LAB_0007c6dd;
    }
  }
  local_180 = CBaseEntity::operator_new(0x598,peVar5);
  local_180->_vptr_CBaseEntity = (_func_int_varargs **)&PTR__CWeaponBox_001670e8;
  local_180->pev = peVar5;
LAB_0007c6dd:
  peVar5->classname = (int)"weaponbox" - (int)gpGlobals->pStringBase;
  (*local_180->_vptr_CBaseEntity[2])(local_180);
  peVar4 = local_180->pev->pContainingEntity;
  local_174.origin.x = (peVar4->v).origin.x;
  local_174.frame = (peVar4->v).frame;
  local_174.origin.y = (peVar4->v).origin.y;
  local_174.origin.z = (peVar4->v).origin.z;
  local_174.angles.x = (peVar4->v).angles.x;
  local_174.angles.y = (peVar4->v).angles.y;
  local_174.angles.z = (peVar4->v).angles.z;
  local_174.skin = (short)(peVar4->v).skin;
  local_174.rendermode = (int)(byte)(peVar4->v).rendermode;
  local_174.renderamt = (int)(peVar4->v).renderamt & 0xff;
  local_174.rendercolor.r = (byte)(int)(peVar4->v).rendercolor.x;
  local_174.rendercolor.g = (byte)(int)(peVar4->v).rendercolor.y;
  local_174.rendercolor.b = (byte)(int)(peVar4->v).rendercolor.z;
  local_174.renderfx = (int)(byte)(peVar4->v).renderfx;
  local_174.mins.x = (peVar4->v).mins.x;
  local_174.mins.y = (peVar4->v).mins.y;
  local_174.scale = (peVar4->v).scale;
  local_174.framerate = (peVar4->v).framerate;
  local_174.gravity = (peVar4->v).gravity;
  local_174.mins.z = (peVar4->v).mins.z;
  local_174.maxs.x = (peVar4->v).maxs.x;
  local_174.maxs.y = (peVar4->v).maxs.y;
  local_174.maxs.z = (peVar4->v).maxs.z;
  local_174.colormap = 0;
  local_174.modelindex = (peVar4->v).modelindex;
  local_174.movetype = (peVar4->v).movetype;
  local_174.solid = (short)(peVar4->v).solid;
  (*g_engfuncs.pfnCreateInstancedBaseline)(local_180->pev->classname,&local_174);
  UTIL_Remove(&this->super_CBaseEntity);
  UTIL_Remove(local_180);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// InconsistentFile  @ 0007c8e0  (line 2682)

int InconsistentFile(edict_t *player,char *filename,char *disconnect_message)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("mp_consistency");
  if (lVar1 != (longdouble)1) {
    return 0;
  }
  __sprintf_chk(disconnect_message,1,0xffffffff,"Server is enforcing file consistency for %s\n",
                filename);
  return 1;
}


// AllowLagCompensation  @ 0007c940  (line 2708)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int AllowLagCompensation(void)

{
  return 1;
}


// ShouldCollide  @ 0007c950  (line 2722)

int ShouldCollide(edict_t *pentTouched,edict_t *pentOther)

{
  return 1;
}


