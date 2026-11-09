// Ghidra decompilation of functions from tfc/client.cpp
// 47 functions, ordered by original source line

// set_suicide_frame  @ 000b6aa0  (line 117)

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


// ClientConnect  @ 000b6b10  (line 136)

BOOL ClientConnect(edict_t *pEntity,char *pszName,char *pszAddress,char *szRejectReason)

{
  int iVar1;
  
  iVar1 = (*g_pGameRules->_vptr_CGameRules[0xb])
                    (g_pGameRules,pEntity,pszName,pszAddress,szRejectReason);
  return iVar1;
}


// ClientDisconnect  @ 000b6b50  (line 155)

void ClientDisconnect(edict_t *pEntity)

{
  _func_void_int *p_Var1;
  int iVar2;
  CSound *this;
  char local_10c [256];
  
                    /* Unresolved local var: char[256] text@[???]
                       Unresolved local var: CSound * pSound@[???] */
  if (g_fGameOver == 0) {
    sprintf(local_10c,"- %s has left the game\n",gpGlobals->pStringBase + (pEntity->v).netname);
    (*g_engfuncs.pfnMessageBegin)(2,gmsgSayText,(float *)0x0,(edict_t *)0x0);
    p_Var1 = g_engfuncs.pfnWriteByte;
    iVar2 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
    (*p_Var1)(iVar2);
    (*g_engfuncs.pfnWriteString)(local_10c);
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
  return;
}


// respawn  @ 000b6cb0  (line 189)

/* WARNING: Type propagation algorithm not settling */

void respawn(entvars_t *pev,BOOL fCopyCorpse)

{
  CBasePlayer *this;
  edict_t *peVar1;
  
  if (cease_fire != 0) {
    return;
  }
  if ((gpGlobals->coop == 0.0) && (gpGlobals->deathmatch == 0.0)) {
                    /* WARNING: Could not recover jumptable at 0x000b6d4b. Too many branches */
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
                    /* WARNING: Could not recover jumptable at 0x000b6d1b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[2])();
  return;
}


// ClientKill  @ 000b6db0  (line 221)

void ClientKill(edict_t *pEntity)

{
  CBaseEntity *pCVar1;
  edict_t *peVar2;
  CBasePlayer *this;
  CBaseEntity *this_00;
  
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pl@[DW_OP_reg6(ESI)] */
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
                    /* Unresolved local var: CBaseEntity * pEntity@[DW_OP_reg0(EAX)] */
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


// ClientPutInServer  @ 000b6ec0  (line 266)

/* WARNING: Type propagation algorithm not settling */

void ClientPutInServer(edict_t *pEntity)

{
  int *piVar1;
  int iVar2;
  globalvars_t *pgVar3;
  char *pcVar4;
  int iVar5;
  CBasePlayer *this;
  edict_t *peVar6;
  entvars_t *peVar7;
  
  peVar7 = &pEntity->v;
                    /* Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg6(ESI)]
                       Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: char * infobuffer@[???] */
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
  pgVar3 = gpGlobals;
                    /* Unresolved local var: int i@[???] */
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.has_disconnected = 0;
  if (-1 < pgVar3->maxClients) {
    iVar5 = 0;
    peVar6 = g_IpStorage[0].pEdict;
    while( true ) {
      if (peVar6 == pEntity) {
        iVar2 = g_IpStorage[iVar5].ip;
        g_IpStorage[iVar5].pEdict = (edict_t *)0x0;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.ip = iVar2;
        g_IpStorage[iVar5].ip = 0;
        return;
      }
      iVar5 = iVar5 + 1;
      if (pgVar3->maxClients < iVar5) break;
      peVar6 = g_IpStorage[iVar5].pEdict;
    }
  }
  return;
}


// FailedSpamCheck  @ 000b7010  (line 309)

int FailedSpamCheck(edict_t *pEntity,int teamonly)

{
  float fVar1;
  float fVar2;
  void *pvVar3;
  globalvars_t *pgVar4;
  _func_void_int *p_Var5;
  int iVar6;
  char local_48 [60];
  
                    /* Unresolved local var: CBasePlayer * pTalker@[DW_OP_reg3(EBX)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if (((pEntity != (edict_t *)0x0) ||
      (pEntity = (*g_engfuncs.pfnPEntityOfEntOffset)(0), pEntity != (edict_t *)0x0)) &&
     (pgVar4 = gpGlobals, pvVar3 = pEntity->pvPrivateData, pvVar3 != (void *)0x0)) {
    fVar1 = *(float *)((int)pvVar3 + 0xe78);
    fVar2 = gpGlobals->time;
    if (fVar2 < fVar1) {
                    /* Unresolved local var: char[60] szMsg@[???]
                       Unresolved local var: int iRemainingTime@[???] */
      fVar1 = fVar1 + tfc_spam_penalty2.value;
      *(float *)((int)pvVar3 + 0xe78) = fVar1;
      sprintf(local_48,"You may not speak for %d seconds for spamming.\n",
              (int)(fVar1 - pgVar4->time));
      (*g_engfuncs.pfnMessageBegin)
                (1,gmsgSayText,(float *)0x0,*(edict_t **)(*(int *)((int)pvVar3 + 4) + 0x208));
      p_Var5 = g_engfuncs.pfnWriteByte;
      iVar6 = (*g_engfuncs.pfnIndexOfEdict)(*(edict_t **)(*(int *)((int)pvVar3 + 4) + 0x208));
      (*p_Var5)(iVar6);
      (*g_engfuncs.pfnWriteString)(local_48);
      (*g_engfuncs.pfnMessageEnd)();
      *(float *)((int)pvVar3 + 0xe7c) = gpGlobals->time;
      return 1;
    }
    if (fVar1 == -1.0) {
      iVar6 = *(int *)((int)pvVar3 + 0xe80);
    }
    else {
      iVar6 = 0;
      *(undefined4 *)((int)pvVar3 + 0xe80) = 0;
      *(undefined4 *)((int)pvVar3 + 0xe78) = 0xbf800000;
      fVar2 = pgVar4->time;
    }
    fVar2 = fVar2 - *(float *)((int)pvVar3 + 0xe7c);
    if (2.0 <= fVar2) {
      iVar6 = (int)((float)iVar6 - fVar2);
      *(int *)((int)pvVar3 + 0xe80) = iVar6;
      if (iVar6 < 0) {
        *(undefined4 *)((int)pvVar3 + 0xe80) = 0;
        fVar1 = 0.0;
      }
      else {
        fVar1 = (float)iVar6;
      }
    }
    else {
      *(int *)((int)pvVar3 + 0xe80) = iVar6 + 1;
      if (teamonly == 0) {
        *(int *)((int)pvVar3 + 0xe80) = iVar6 + 2;
        if ((float)(iVar6 + 2) <= tfc_spam_limit.value) {
          return 0;
        }
        goto LAB_000b7118;
      }
      fVar1 = (float)(iVar6 + 1);
    }
    if (tfc_spam_limit.value < fVar1) {
LAB_000b7118:
      *(float *)((int)pvVar3 + 0xe78) = pgVar4->time + tfc_spam_penalty1.value;
      return 1;
    }
  }
  return 0;
}


// Host_Say  @ 000b7230  (line 384)

void Host_Say(edict_t *pEntity,int teamonly)

{
  _func_int_varargs *p_Var1;
  globalvars_t *pgVar2;
  _func_void_int *p_Var3;
  bool bVar4;
  char cVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  size_t sVar11;
  CBasePlayer *pReceiver;
  entvars_t *peVar12;
  int iVar13;
  char *pcVar14;
  CBaseEntity *pCVar15;
  void *pvVar16;
  edict_t *peVar17;
  uint *puVar18;
  uint *puVar19;
  char *pcVar20;
  longdouble extraout_ST0;
  CBasePlayer *local_1a8;
  uint *local_1a4;
  char local_19c [256];
  uint local_9c [31];
  char acStack_1e [14];
  
                    /* Unresolved local var: CBasePlayer * client@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[128] text@[???]
                       Unresolved local var: char[256] szTemp@[???]
                       Unresolved local var: char * cpSay@[???]
                       Unresolved local var: char * cpSayTeam@[???]
                       Unresolved local var: char * pcmd@[???]
                       Unresolved local var: float spectChat@[???]
                       Unresolved local var: CBasePlayer * pTalker@[DW_OP_breg4(ESP): +52]
                       Unresolved local var: char * pc@[???]
                       Unresolved local var: char * temp@[???] */
  pcVar6 = (*g_engfuncs.pfnCmd_Argv)(0);
  (*g_engfuncs.pfnCVarGetFloat)("tfc_spectchat");
  iVar7 = (*g_engfuncs.pfnCmd_Argc)();
  if (iVar7 == 0) {
    return;
  }
  iVar7 = strcasecmp(pcVar6,"say");
  if ((iVar7 == 0) || (iVar7 = strcasecmp(pcVar6,"say_team"), iVar7 == 0)) {
    iVar7 = (*g_engfuncs.pfnCmd_Argc)();
    if (iVar7 < 2) {
      return;
    }
    pcVar8 = (*g_engfuncs.pfnCmd_Args)();
  }
  else {
    iVar7 = (*g_engfuncs.pfnCmd_Argc)();
    if (iVar7 < 2) {
      pcVar8 = local_19c;
      strcpy(pcVar8,pcVar6);
    }
    else {
      pcVar20 = (*g_engfuncs.pfnCmd_Args)();
      pcVar8 = local_19c;
      sprintf(pcVar8,"%s %s",pcVar6,pcVar20);
    }
  }
  iVar7 = FailedSpamCheck(pEntity,teamonly);
  if (iVar7 != 0) {
    return;
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar17 = pEntity;
  if ((pEntity == (edict_t *)0x0) &&
     (peVar17 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar17 == (edict_t *)0x0)) {
    local_1a8 = (CBasePlayer *)0x0;
  }
  else {
    local_1a8 = peVar17->pvPrivateData;
  }
  pcVar6 = pcVar8;
  if (*pcVar8 == '\"') {
    pcVar6 = pcVar8 + 1;
    sVar11 = strlen(pcVar6);
    pcVar8[sVar11] = '\0';
  }
  if (pcVar6 != (char *)0x0) {
    cVar5 = *pcVar6;
    pcVar8 = pcVar6;
    while( true ) {
      if (cVar5 == '\0') {
        return;
      }
      cVar5 = *pcVar8;
      iVar7 = isprint((int)cVar5);
      if (((iVar7 != 0) && (iVar7 = isspace((int)cVar5), iVar7 == 0)) ||
         (pcVar8 = pcVar8 + 1, pcVar8 == (char *)0x0)) break;
      cVar5 = *pcVar8;
    }
                    /* Unresolved local var: char * pApersand@[???] */
    if (*pcVar6 != '\0') {
      pcVar8 = pcVar6 + 2;
      do {
        if (pcVar8[-2] == '%') {
          sVar11 = strlen(pcVar6);
          if (0x7c < sVar11) break;
          cVar5 = pcVar8[-1];
          if (cVar5 == 'h') {
                    /* Unresolved local var: int iValue@[???] */
            pcVar8[-2] = '\0';
            pcVar20 = UTIL_VarArgs("%d%s",(int)((local_1a8->super_CBaseMonster).super_CBaseToggle.
                                                super_CBaseAnimating.super_CBaseDelay.
                                                super_CBaseEntity.pev)->health,pcVar8);
            strcat(pcVar6,pcVar20);
            cVar5 = pcVar8[-1];
          }
          if (cVar5 == 'a') {
                    /* Unresolved local var: int iValue@[???] */
            pcVar8[-2] = '\0';
            pcVar20 = UTIL_VarArgs("%d%s",(int)((local_1a8->super_CBaseMonster).super_CBaseToggle.
                                                super_CBaseAnimating.super_CBaseDelay.
                                                super_CBaseEntity.pev)->armorvalue,pcVar8);
            strcat(pcVar6,pcVar20);
            cVar5 = pcVar8[-1];
          }
          if (cVar5 == 'i') {
            pcVar8[-2] = '\0';
            iVar7 = EHANDLE::operator_int(&local_1a8->m_hLastIDTarget);
            if (iVar7 == 0) {
              pcVar20 = UTIL_VarArgs("%s",pcVar8);
              strcat(pcVar6,pcVar20);
            }
            else {
              pcVar20 = gpGlobals->pStringBase;
              pCVar15 = EHANDLE::operator->(&local_1a8->m_hLastIDTarget);
              pcVar20 = UTIL_VarArgs("%s%s",pcVar20 + pCVar15->pev->netname,pcVar8);
              strcat(pcVar6,pcVar20);
            }
          }
        }
        if ((pcVar8 == (char *)0x1) ||
           (pcVar20 = pcVar8 + -1, pcVar8 = pcVar8 + 1, *pcVar20 == '\0')) break;
      } while( true );
    }
  }
  pgVar2 = gpGlobals;
  local_1a8->m_flLastTalkTime = gpGlobals->time;
  if (((local_1a8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->iuser1 == 0) {
    if (teamonly != 0) {
      sprintf((char *)local_9c,"%c(TEAM) %s: ",2,pgVar2->pStringBase + (pEntity->v).netname);
      goto LAB_000b740e;
    }
  }
  else if (((float)extraout_ST0 == 0.0) || (teamonly != 0)) {
    sprintf((char *)local_9c,"%c(SPEC) %s: ",2,pgVar2->pStringBase + (pEntity->v).netname);
    goto LAB_000b740e;
  }
  sprintf((char *)local_9c,"%c%s: ",2,pgVar2->pStringBase + (pEntity->v).netname);
LAB_000b740e:
  local_1a4 = local_9c;
  puVar19 = local_1a4;
  do {
    puVar18 = puVar19;
    uVar9 = *puVar18 + 0xfefefeff & ~*puVar18;
    uVar10 = uVar9 & 0x80808080;
    puVar19 = puVar18 + 1;
  } while (uVar10 == 0);
  if ((uVar9 & 0x8080) == 0) {
    puVar19 = (uint *)((int)puVar18 + 6);
    uVar10 = uVar10 >> 0x10;
  }
  sVar11 = strlen(pcVar6);
  if ((int)(acStack_1e + -((int)puVar19 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)))) <
      (int)sVar11) {
    pcVar6[(int)(acStack_1e + -((int)puVar19 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10))))] =
         '\0';
  }
  strcat((char *)local_1a4,pcVar6);
  puVar19 = local_1a4;
  do {
    puVar18 = puVar19;
    uVar9 = *puVar18 + 0xfefefeff & ~*puVar18;
    uVar10 = uVar9 & 0x80808080;
    puVar19 = puVar18 + 1;
  } while (uVar10 == 0);
  if ((uVar9 & 0x8080) == 0) {
    puVar19 = (uint *)((int)puVar18 + 6);
    uVar10 = uVar10 >> 0x10;
  }
  *(undefined2 *)((int)puVar19 + (-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10))) = 10;
                    /* Unresolved local var: int i@[???] */
  if (0 < gpGlobals->maxClients) {
    iVar7 = 1;
    do {
      pReceiver = UTIL_PlayerByIndex(iVar7);
      if ((((pReceiver != (CBasePlayer *)0x0) &&
           (peVar12 = (pReceiver->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev, pEntity != peVar12->pContainingEntity)
           ) && ((peVar12->flags & 8) != 0)) &&
         (bVar4 = CVoiceGameMgr::PlayerHasBlockedPlayer
                            ((CVoiceGameMgr *)(g_pGameRules + 6),pReceiver,local_1a8), !bVar4)) {
        if (((local_1a8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
             .super_CBaseEntity.pev)->iuser1 == 0) {
          if (teamonly != 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[DW_OP_reg0(EAX)] */
            p_Var1 = g_pGameRules->_vptr_CGameRules[0x32];
            peVar17 = pEntity;
            if (pEntity == (edict_t *)0x0) {
              peVar17 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
              pvVar16 = (void *)0x0;
              if (peVar17 != (edict_t *)0x0) goto LAB_000b7818;
            }
            else {
LAB_000b7818:
              pvVar16 = peVar17->pvPrivateData;
            }
            iVar13 = (*p_Var1)(g_pGameRules,pReceiver,pvVar16);
            if (iVar13 != 1) goto LAB_000b74d0;
            if (((local_1a8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev)->iuser1 != 0) goto LAB_000b7539;
          }
          peVar12 = (pReceiver->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
        }
        else {
LAB_000b7539:
          peVar12 = (pReceiver->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev;
          if ((((float)extraout_ST0 == 0.0) || (teamonly != 0)) && (peVar12->iuser1 == 0))
          goto LAB_000b74d0;
        }
        (*g_engfuncs.pfnMessageBegin)(1,gmsgSayText,(float *)0x0,peVar12->pContainingEntity);
        p_Var3 = g_engfuncs.pfnWriteByte;
        iVar13 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
        (*p_Var3)(iVar13);
        (*g_engfuncs.pfnWriteString)((char *)local_1a4);
        (*g_engfuncs.pfnMessageEnd)();
      }
LAB_000b74d0:
      iVar7 = iVar7 + 1;
    } while (iVar7 <= gpGlobals->maxClients);
  }
  (*g_engfuncs.pfnMessageBegin)(1,gmsgSayText,(float *)0x0,(pEntity->v).pContainingEntity);
  p_Var3 = g_engfuncs.pfnWriteByte;
  iVar7 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
  (*p_Var3)(iVar7);
  pcVar20 = "say_team";
  (*g_engfuncs.pfnWriteString)((char *)local_1a4);
  (*g_engfuncs.pfnMessageEnd)();
  (*g_engfuncs.pfnServerPrint)((char *)local_1a4);
  pcVar8 = "SPECTATOR";
  if (teamonly == 0) {
    pcVar20 = "say";
  }
  iVar7 = (local_1a8->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  if (iVar7 != 0) {
    pcVar8 = GetTeamName(iVar7);
  }
  pcVar14 = (*g_engfuncs.pfnGetPlayerAuthId)(pEntity);
  iVar7 = (*g_engfuncs.pfnGetPlayerUserId)(pEntity);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" %s \"%s\"\n",gpGlobals->pStringBase + (pEntity->v).netname,
                 iVar7,pcVar14,pcVar8,pcVar20,pcVar6);
  return;
}


// Host_Tell  @ 000b7930  (line 571)

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
  uint *puVar10;
  uint *puVar11;
  char *pcVar12;
  char *pcVar13;
  edict_t *peVar14;
  uint uVar15;
  uint uVar16;
  char *pcVar17;
  globalvars_t *pgVar18;
  char *pcVar19;
  char *pcVar20;
  void *local_1a8;
  char local_19c [254];
  undefined1 local_9e;
  undefined1 local_9d;
  uint local_9c [31];
  undefined1 local_1e;
  undefined1 local_1d;
  
                    /* Unresolved local var: CBasePlayer * client@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char[128] text@[???]
                       Unresolved local var: char[256] logText@[???]
                       Unresolved local var: char * pTellName@[DW_OP_breg4(ESP): +72]
                       Unresolved local var: int copylen@[???]
                       Unresolved local var: char * pc@[???]
                       Unresolved local var: CBaseEntity * pEnt@[DW_OP_breg4(ESP): +68]
                       Unresolved local var: CBasePlayer * pTalker@[???] */
  iVar5 = (*g_engfuncs.pfnCmd_Argc)();
  if (iVar5 < 3) {
    return;
  }
  iVar5 = FailedSpamCheck(pEntity,1);
  if (iVar5 != 0) {
    return;
  }
  pcVar6 = (*g_engfuncs.pfnCmd_Args)();
  if (pcVar6 != (char *)0x0) {
    cVar1 = *pcVar6;
    pcVar20 = pcVar6;
    while( true ) {
      if (cVar1 == '\0') {
        return;
      }
      cVar1 = *pcVar20;
      iVar5 = isprint((int)cVar1);
      if (((iVar5 != 0) && (iVar5 = isspace((int)cVar1), iVar5 == 0)) ||
         (pcVar20 = pcVar20 + 1, pcVar20 == (char *)0x0)) break;
      cVar1 = *pcVar20;
    }
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar14 = pEntity;
  if ((pEntity == (edict_t *)0x0) &&
     (peVar14 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar14 == (edict_t *)0x0)) {
    local_1a8 = (void *)0x0;
  }
  else {
    local_1a8 = peVar14->pvPrivateData;
  }
  pgVar18 = gpGlobals;
  *(float *)((int)local_1a8 + 0xe7c) = gpGlobals->time;
  sprintf((char *)local_9c,"%c(TELL) %s: ",2,pgVar18->pStringBase + (pEntity->v).netname);
  pcVar20 = (*g_engfuncs.pfnCmd_Argv)(1);
  pcVar20 = strstr(pcVar6,pcVar20);
  puVar11 = local_9c;
  if (pcVar20 == (char *)0x0) {
    do {
      puVar10 = puVar11;
      uVar15 = *puVar10 + 0xfefefeff & ~*puVar10;
      uVar16 = uVar15 & 0x80808080;
      puVar11 = puVar10 + 1;
    } while (uVar16 == 0);
    if ((uVar15 & 0x8080) == 0) {
      puVar11 = (uint *)((int)puVar10 + 6);
      uVar16 = uVar16 >> 0x10;
    }
    uVar16 = (int)puVar11 + ((-3 - (uint)CARRY1((byte)uVar16,(byte)uVar16)) - (int)local_9c);
    if ((int)(0x7f - uVar16) < 1) goto LAB_000b7b16;
    strncat((char *)local_9c,pcVar6,0x7f - uVar16);
    puVar11 = local_9c;
    do {
      uVar16 = *puVar11;
      puVar11 = puVar11 + 1;
      uVar16 = uVar16 + 0xfefefeff & ~uVar16 & 0x80808080;
    } while (uVar16 == 0);
  }
  else {
    do {
      puVar10 = puVar11;
      uVar15 = *puVar10 + 0xfefefeff & ~*puVar10;
      uVar16 = uVar15 & 0x80808080;
      puVar11 = puVar10 + 1;
    } while (uVar16 == 0);
    if ((uVar15 & 0x8080) == 0) {
      puVar11 = (uint *)((int)puVar10 + 6);
      uVar16 = uVar16 >> 0x10;
    }
    uVar16 = (int)puVar11 + ((-3 - (uint)CARRY1((byte)uVar16,(byte)uVar16)) - (int)local_9c);
    if ((int)(0x7f - uVar16) < 1) goto LAB_000b7b16;
    pcVar6 = (*g_engfuncs.pfnCmd_Argv)(1);
    sVar7 = strlen(pcVar6);
    strncat((char *)local_9c,pcVar20 + sVar7,0x7f - uVar16);
    puVar11 = local_9c;
    do {
      uVar16 = *puVar11;
      puVar11 = puVar11 + 1;
      uVar16 = uVar16 + 0xfefefeff & ~uVar16 & 0x80808080;
    } while (uVar16 == 0);
  }
  if ((uVar16 & 0x8080) == 0) {
    puVar11 = (uint *)((int)puVar11 + 2);
    uVar16 = uVar16 >> 0x10;
  }
  uVar16 = (int)puVar11 + ((-3 - (uint)CARRY1((byte)uVar16,(byte)uVar16)) - (int)local_9c);
LAB_000b7b16:
  if (uVar16 < 0x7f) {
    *(undefined2 *)((int)local_9c + uVar16) = 10;
  }
  else {
    local_1e = 10;
    local_1d = 0;
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < gpGlobals->maxClients) {
    iVar5 = 1;
    do {
      pCVar9 = UTIL_PlayerByIndex(iVar5);
      pgVar18 = gpGlobals;
      if (((pCVar9 != (CBasePlayer *)0x0) &&
          (peVar2 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev, pEntity != peVar2->pContainingEntity))
         && (((peVar2->flags & 8) != 0 &&
             ((*(int *)(*(int *)((int)local_1a8 + 4) + 0x244) == 0 || (peVar2->iuser1 != 0)))))) {
        pcVar6 = (*g_engfuncs.pfnCmd_Argv)(1);
        pgVar18 = gpGlobals;
        peVar2 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        iVar8 = strcmp(gpGlobals->pStringBase + peVar2->netname,pcVar6);
        if (iVar8 == 0) {
          (*g_engfuncs.pfnMessageBegin)(1,gmsgSayText,(float *)0x0,peVar2->pContainingEntity);
          p_Var4 = g_engfuncs.pfnWriteByte;
          iVar5 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
          (*p_Var4)(iVar5);
          pcVar19 = "SPECTATOR";
          (*g_engfuncs.pfnWriteString)((char *)local_9c);
          (*g_engfuncs.pfnMessageEnd)();
          pcVar6 = (*g_engfuncs.pfnCmd_Argv)(1);
          sVar7 = strlen(pcVar6);
          iVar5 = (pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.team_no;
          if (iVar5 != 0) {
            pcVar19 = GetTeamName(iVar5);
          }
          pcVar12 = (*g_engfuncs.pfnGetPlayerAuthId)
                              (((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          iVar5 = (*g_engfuncs.pfnGetPlayerUserId)
                            (((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity);
          pcVar6 = gpGlobals->pStringBase;
          sVar3 = ((pCVar9->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev)->netname;
          pcVar17 = "SPECTATOR";
          if (*(int *)((int)local_1a8 + 0x138) != 0) {
            pcVar17 = GetTeamName(*(int *)((int)local_1a8 + 0x138));
          }
          pcVar13 = (*g_engfuncs.pfnGetPlayerAuthId)(pEntity);
          iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pEntity);
          snprintf(local_19c,0xff,"\"%s<%i><%s><%s>\" tell \"%s<%i><%s><%s>\" message \"%s\"\n",
                   gpGlobals->pStringBase + (pEntity->v).netname,iVar8,pcVar13,pcVar17,
                   pcVar6 + sVar3,iVar5,pcVar12,pcVar19,pcVar20 + sVar7 + 1);
          local_9e = 10;
          local_9d = 0;
          (*g_engfuncs.pfnServerPrint)(local_19c);
          UTIL_LogPrintf(local_19c);
          return;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= pgVar18->maxClients);
  }
  return;
}


// Bench_FindSpot  @ 000b7e40  (line 697)

CBaseEntity * Bench_FindSpot(int spot)

{
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pSpot@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"trigger_camera");
  while ((pStartEntity != (CBaseEntity *)0x0 && ((int)pStartEntity->pev->speed != spot))) {
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"trigger_camera");
  }
  return pStartEntity;
}


// ClientCommand  @ 000b7ea0  (line 725)

/* WARNING: Type propagation algorithm not settling */

void ClientCommand(edict_t *pEntity)

{
  float fVar1;
  CBasePlayer *this;
  Vector vecPosition;
  Vector vecPosition_00;
  Vector vecViewAngle;
  Vector vecViewAngle_00;
  char *pcVar2;
  BOOL BVar3;
  char *pcVar4;
  char *pcVar5;
  edict_t *peVar6;
  entvars_t *peVar7;
  long iTeam;
  long lVar8;
  int iVar9;
  int iVar10;
  undefined1 uVar11;
  bool bVar12;
  bool bVar13;
  byte bVar14;
  longdouble extraout_ST0;
  undefined4 in_stack_ffffff88;
  vec_t in_stack_ffffff8c;
  vec_t local_5c;
  vec_t local_58;
  vec_t local_54;
  vec_t local_4c;
  vec_t local_48;
  vec_t local_44;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  char local_21;
  char local_20;
  undefined1 local_1f;
  
  bVar14 = 0;
                    /* Unresolved local var: char * pcmd@[???]
                       Unresolved local var: char * pstr@[???]
                       Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[???] */
  pcVar2 = (*g_engfuncs.pfnCmd_Argv)(0);
  this = pEntity->pvPrivateData;
  if (this == (CBasePlayer *)0x0) {
    return;
  }
  iVar9 = 8;
  uVar11 = false;
  pcVar4 = pcVar2;
  pcVar5 = "special";
  do {
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    uVar11 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while ((bool)uVar11);
  if ((bool)uVar11) {
LAB_000b7f04:
    CBasePlayer::UseSpecialSkill(this);
LAB_000b7f0c:
    iVar9 = 9;
    pcVar4 = pcVar2;
    pcVar5 = "flaginfo";
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      uVar11 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
    } while ((bool)uVar11);
    if ((bool)uVar11) {
LAB_000b83e1:
      CBasePlayer::TeamFortress_DisplayDetectionItems(this);
      return;
    }
  }
  else {
    iVar9 = 9;
    pcVar4 = pcVar2;
    pcVar5 = "_special";
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      uVar11 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
    } while ((bool)uVar11);
    if ((bool)uVar11) goto LAB_000b7f04;
    iVar9 = 4;
    pcVar4 = pcVar2;
    pcVar5 = "say";
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      uVar11 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
    } while ((bool)uVar11);
    if (!(bool)uVar11) {
      iVar9 = 9;
      pcVar4 = pcVar2;
      pcVar5 = "say_team";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        uVar11 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
      } while ((bool)uVar11);
      if ((bool)uVar11) {
        Host_Say(pEntity,1);
      }
      else {
        iVar9 = 0xb;
        pcVar4 = pcVar2;
        pcVar5 = "fullupdate";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          uVar11 = *pcVar4 == *pcVar5;
          pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
          pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
        } while ((bool)uVar11);
        if ((bool)uVar11) {
          CBasePlayer::ForceClientDllUpdate(this);
        }
        else {
          iVar9 = 5;
          pcVar4 = pcVar2;
          pcVar5 = "tell";
          do {
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            uVar11 = *pcVar4 == *pcVar5;
            pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
            pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
          } while ((bool)uVar11);
          if ((bool)uVar11) {
            Host_Tell(pEntity);
          }
          else {
            iVar9 = 5;
            bVar12 = false;
            pcVar4 = pcVar2;
            pcVar5 = "give";
            do {
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              bVar12 = *pcVar4 == *pcVar5;
              pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
              pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
            } while (bVar12);
            if (bVar12) {
              (*g_engfuncs.pfnCVarGetFloat)("sv_cheats");
              uVar11 = extraout_ST0 == (longdouble)0;
              if (!(bool)uVar11) {
                pcVar4 = (*g_engfuncs.pfnCmd_Argv)(1);
                CBasePlayer::GiveNamedItem(this,pcVar4);
              }
            }
            else {
              iVar9 = 4;
              peVar7 = &pEntity->v;
              bVar12 = peVar7 == (entvars_t *)0x0;
              pcVar4 = pcVar2;
              pcVar5 = "fov";
              do {
                if (iVar9 == 0) break;
                iVar9 = iVar9 + -1;
                bVar12 = *pcVar4 == *pcVar5;
                pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
                pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
              } while (bVar12);
              if (bVar12) {
                iVar9 = (*g_engfuncs.pfnCmd_Argc)();
                if (iVar9 < 2) {
                  pcVar4 = UTIL_VarArgs("\"fov\" is \"%d\"\n",this->m_iFOV);
                  uVar11 = 1;
                  ClientPrint(peVar7,1,pcVar4,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
                }
                else {
                  pcVar4 = (*g_engfuncs.pfnCmd_Argv)(1);
                  uVar11 = 1;
                  lVar8 = strtol(pcVar4,(char **)0x0,10);
                  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev;
                  this->m_iFOV = lVar8;
                  peVar7->fov = (float)lVar8;
                }
              }
              else {
                iVar9 = 9;
                uVar11 = false;
                pcVar4 = pcVar2;
                pcVar5 = "spectate";
                do {
                  if (iVar9 == 0) break;
                  iVar9 = iVar9 + -1;
                  uVar11 = *pcVar4 == *pcVar5;
                  pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
                  pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
                } while ((bool)uVar11);
                if ((bool)uVar11) {
                  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.pev;
                  if ((peVar7->flags & 0x100000) == 0) {
                    if (allow_spectators.value == 0.0) {
                      uVar11 = 0;
                      if ((peVar7->playerclass == 0) && (uVar11 = peVar7->team == 0, (bool)uVar11))
                      goto LAB_000b8781;
                    }
                    else {
                    /* Unresolved local var: int allow_change@[???] */
                      fVar1 = this->m_fNextTeamOrClassChange;
                      if (fVar1 == 0.0) {
                        iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.team_no;
LAB_000b82c0:
                    /* Unresolved local var: edict_t * pentSpawnSpot@[???] */
                        pcVar4 = GetTeamName(iVar9);
                        pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)
                                           (((this->super_CBaseMonster).super_CBaseToggle.
                                             super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity
                                            .pev)->pContainingEntity);
                        iVar9 = (*g_engfuncs.pfnGetPlayerUserId)
                                          (((this->super_CBaseMonster).super_CBaseToggle.
                                            super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                           pev)->pContainingEntity);
                        UTIL_LogPrintf("\"%s<%i><%s><%s>\" joined team \"SPECTATOR\"\n",
                                       gpGlobals->pStringBase +
                                       ((this->super_CBaseMonster).super_CBaseToggle.
                                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                                       ->netname,iVar9);
                        fVar1 = gpGlobals->time;
                        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.team_no = 0;
                        this->m_fNextTeamOrClassChange = fVar1 + 1.0;
                        peVar6 = EntSelectSpawnPoint(pEntity);
                        if (peVar6 == (edict_t *)0x0) {
                          local_4c = vRam00000050;
                          local_48 = vRam00000054;
                          local_44 = vRam00000058;
                          peVar7 = (entvars_t *)0x0;
                        }
                        else {
                          local_4c = (peVar6->v).angles.x;
                          local_48 = (peVar6->v).angles.y;
                          local_44 = (peVar6->v).angles.z;
                          peVar7 = &peVar6->v;
                        }
                        uVar11 = peVar7 == (entvars_t *)0x0;
                        local_30 = (peVar7->origin).x;
                        local_2c = (peVar7->origin).y;
                        local_28 = (peVar7->origin).z;
                        vecPosition.y = (vec_t)&local_4c;
                        vecPosition.x = (vec_t)&local_30;
                        vecPosition.z = (vec_t)pcVar5;
                        vecViewAngle.y = (vec_t)in_stack_ffffff88;
                        vecViewAngle.x = (vec_t)pcVar4;
                        vecViewAngle.z = in_stack_ffffff8c;
                        CBasePlayer::StartObserver(this,vecPosition,vecViewAngle);
                      }
                      else {
                        uVar11 = gpGlobals->time == fVar1;
                        if (fVar1 < gpGlobals->time) {
                          iVar9 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                  super_CBaseDelay.super_CBaseEntity.team_no;
                          uVar11 = iVar9 == 0;
                          if (!(bool)uVar11) goto LAB_000b82c0;
                        }
                      }
                    }
                  }
                  else {
                    /* Unresolved local var: edict_t * pentSpawnSpot@[???] */
                    pcVar4 = GetTeamName((this->super_CBaseMonster).super_CBaseToggle.
                                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                         team_no);
                    pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)
                                       (((this->super_CBaseMonster).super_CBaseToggle.
                                         super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev
                                        )->pContainingEntity);
                    iVar9 = (*g_engfuncs.pfnGetPlayerUserId)
                                      (((this->super_CBaseMonster).super_CBaseToggle.
                                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)
                                       ->pContainingEntity);
                    UTIL_LogPrintf("\"%s<%i><%s><%s>\" joined team \"SPECTATOR\"\n",
                                   gpGlobals->pStringBase +
                                   ((this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                                   netname,iVar9);
                    peVar6 = EntSelectSpawnPoint(pEntity);
                    if (peVar6 == (edict_t *)0x0) {
                      local_5c = vRam00000050;
                      local_58 = vRam00000054;
                      local_54 = vRam00000058;
                      peVar7 = (entvars_t *)0x0;
                    }
                    else {
                      local_5c = (peVar6->v).angles.x;
                      local_58 = (peVar6->v).angles.y;
                      local_54 = (peVar6->v).angles.z;
                      peVar7 = &peVar6->v;
                    }
                    uVar11 = peVar7 == (entvars_t *)0x0;
                    local_3c = (peVar7->origin).x;
                    local_38 = (peVar7->origin).y;
                    local_34 = (peVar7->origin).z;
                    vecPosition_00.y = (vec_t)&local_5c;
                    vecPosition_00.x = (vec_t)&local_3c;
                    vecPosition_00.z = (vec_t)pcVar5;
                    vecViewAngle_00.y = (vec_t)in_stack_ffffff88;
                    vecViewAngle_00.x = (vec_t)pcVar4;
                    vecViewAngle_00.z = in_stack_ffffff8c;
                    CBasePlayer::StartObserver(this,vecPosition_00,vecViewAngle_00);
                  }
                }
                else {
                  iVar9 = 9;
                  pcVar4 = pcVar2;
                  pcVar5 = "specmode";
                  do {
                    if (iVar9 == 0) break;
                    iVar9 = iVar9 + -1;
                    uVar11 = *pcVar4 == *pcVar5;
                    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
                    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
                  } while ((bool)uVar11);
                  if ((bool)uVar11) {
                    uVar11 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                              super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0;
                    if (!(bool)uVar11) {
                      pcVar4 = (*g_engfuncs.pfnCmd_Argv)(1);
                      uVar11 = 1;
                      lVar8 = strtol(pcVar4,(char **)0x0,10);
                      CBasePlayer::Observer_SetMode(this,lVar8);
                    }
                  }
                  else {
                    iVar9 = 0xb;
                    pcVar4 = pcVar2;
                    pcVar5 = "follownext";
                    do {
                      if (iVar9 == 0) break;
                      iVar9 = iVar9 + -1;
                      uVar11 = *pcVar4 == *pcVar5;
                      pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
                      pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
                    } while ((bool)uVar11);
                    if ((bool)uVar11) {
                      uVar11 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->iuser1 == 0;
                      if (!(bool)uVar11) {
                        pcVar4 = (*g_engfuncs.pfnCmd_Argv)(1);
                        lVar8 = strtol(pcVar4,(char **)0x0,10);
                        uVar11 = lVar8 == 0;
                        CBasePlayer::Observer_FindNextPlayer(this,!(bool)uVar11);
                      }
                    }
                    else {
                      iVar9 = 6;
                      pcVar4 = pcVar2;
                      pcVar5 = "scout";
                      do {
                        if (iVar9 == 0) break;
                        iVar9 = iVar9 + -1;
                        uVar11 = *pcVar4 == *pcVar5;
                        pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
                        pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
                      } while ((bool)uVar11);
                      if ((bool)uVar11) {
                        CBasePlayer::ChangeClass(this,1);
                      }
                      else {
                        iVar9 = 7;
                        pcVar4 = pcVar2;
                        pcVar5 = "sniper";
                        do {
                          if (iVar9 == 0) break;
                          iVar9 = iVar9 + -1;
                          uVar11 = *pcVar4 == *pcVar5;
                          pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
                          pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
                        } while ((bool)uVar11);
                        if ((bool)uVar11) {
                          CBasePlayer::ChangeClass(this,2);
                        }
                        else {
                          iVar9 = 8;
                          pcVar4 = pcVar2;
                          pcVar5 = "soldier";
                          do {
                            if (iVar9 == 0) break;
                            iVar9 = iVar9 + -1;
                            uVar11 = *pcVar4 == *pcVar5;
                            pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
                            pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
                          } while ((bool)uVar11);
                          if ((bool)uVar11) {
                            CBasePlayer::ChangeClass(this,3);
                          }
                          else {
                            iVar9 = 8;
                            pcVar4 = pcVar2;
                            pcVar5 = "demoman";
                            do {
                              if (iVar9 == 0) break;
                              iVar9 = iVar9 + -1;
                              uVar11 = *pcVar4 == *pcVar5;
                              pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
                              pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
                            } while ((bool)uVar11);
                            if ((bool)uVar11) {
                              CBasePlayer::ChangeClass(this,4);
                            }
                            else {
                              iVar9 = 6;
                              pcVar4 = pcVar2;
                              pcVar5 = "medic";
                              do {
                                if (iVar9 == 0) break;
                                iVar9 = iVar9 + -1;
                                uVar11 = *pcVar4 == *pcVar5;
                                pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
                                pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
                              } while ((bool)uVar11);
                              if ((bool)uVar11) {
                                CBasePlayer::ChangeClass(this,5);
                              }
                              else {
                                BVar3 = FStrEq(pcVar2,"hvyweap");
                                if ((BVar3 == 0) && (BVar3 = FStrEq(pcVar2,"hwguy"), BVar3 == 0)) {
                                  BVar3 = FStrEq(pcVar2,"pyro");
                                  uVar11 = BVar3 == 0;
                                  if ((bool)uVar11) {
                                    BVar3 = FStrEq(pcVar2,"spy");
                                    uVar11 = BVar3 == 0;
                                    if ((bool)uVar11) {
                                      BVar3 = FStrEq(pcVar2,"engineer");
                                      uVar11 = BVar3 == 0;
                                      if ((bool)uVar11) {
                                        BVar3 = FStrEq(pcVar2,"randompc");
                                        if (BVar3 == 0) {
                                          BVar3 = FStrEq(pcVar2,"civilian");
                                          if (BVar3 == 0) {
                                            BVar3 = FStrEq(pcVar2,"changeclass");
                                            if (BVar3 == 0) {
                                              BVar3 = FStrEq(pcVar2,"changeteam");
                                              uVar11 = BVar3 == 0;
                                              if (!(bool)uVar11) goto LAB_000b8781;
                                              BVar3 = FStrEq(pcVar2,"closemenus");
                                              uVar11 = BVar3 == 0;
                                              if ((bool)uVar11) {
                                                BVar3 = FStrEq(pcVar2,"jointeam");
                                                if (BVar3 == 0) {
                                                  BVar3 = FStrEq(pcVar2,"admin");
                                                  uVar11 = BVar3 == 0;
                                                  if ((bool)uVar11) {
                                                    if ((this->super_CBaseMonster).super_CBaseToggle
                                                        .super_CBaseAnimating.super_CBaseDelay.
                                                        super_CBaseEntity.is_admin == 1) {
                                                      BVar3 = FStrEq(pcVar2,"adm_countplayers");
                                                      uVar11 = BVar3 == 0;
                                                      if ((bool)uVar11) {
                                                        BVar3 = FStrEq(pcVar2,"adm_ceasefire");
                                                        uVar11 = BVar3 == 0;
                                                        if ((bool)uVar11) {
                                                          BVar3 = FStrEq(pcVar2,"adm_deal");
                                                          if (((BVar3 == 0) &&
                                                              (BVar3 = FStrEq(pcVar2,"adm_next"),
                                                              BVar3 == 0)) &&
                                                             (BVar3 = FStrEq(pcVar2,"next"),
                                                             BVar3 == 0)) {
                                                            BVar3 = FStrEq(pcVar2,"adm_kick");
                                                            if (((BVar3 == 0) &&
                                                                (BVar3 = FStrEq(pcVar2,"kick"),
                                                                BVar3 == 0)) ||
                                                               (uVar11 = (this->super_CBaseMonster).
                                                                         super_CBaseToggle.
                                                                         super_CBaseAnimating.
                                                                         super_CBaseDelay.
                                                                         super_CBaseEntity.
                                                                         admin_mode == 1,
                                                               !(bool)uVar11)) {
                                                              BVar3 = FStrEq(pcVar2,"adm_ban");
                                                              if (((BVar3 == 0) &&
                                                                  (BVar3 = FStrEq(pcVar2,"ban"),
                                                                  BVar3 == 0)) ||
                                                                 (uVar11 = (this->super_CBaseMonster
                                                                           ).super_CBaseToggle.
                                                                           super_CBaseAnimating.
                                                                           super_CBaseDelay.
                                                                           super_CBaseEntity.
                                                                           admin_mode == 1,
                                                                 !(bool)uVar11)) {
                                                                BVar3 = FStrEq(pcVar2,
                                                  "adm_listplayers");
                                                  uVar11 = BVar3 == 0;
                                                  if ((bool)uVar11) {
                                                    BVar3 = FStrEq(pcVar2,"adm_changelevel");
                                                    uVar11 = BVar3 == 0;
                                                    if ((bool)uVar11) goto LAB_000b8ed4;
                                                    CBasePlayer::Admin_Changelevel(this);
                                                  }
                                                  else {
                                                    CBasePlayer::Admin_ListIPs(this);
                                                  }
                                                  }
                                                  else {
                                                    CBasePlayer::Admin_DoBan(this);
                                                  }
                                                  }
                                                  else {
                                                    CBasePlayer::Admin_DoKick(this);
                                                  }
                                                  }
                                                  else {
                                                    uVar11 = 0;
                                                    CBasePlayer::Admin_CycleDeal(this);
                                                  }
                                                  }
                                                  else {
                                                    Admin_CeaseFire();
                                                  }
                                                  }
                                                  else {
                                                    CBasePlayer::Admin_CountPlayers(this);
                                                  }
                                                  }
                                                  else {
LAB_000b8ed4:
                                                    iVar9 = (*g_pGameRules->_vptr_CGameRules[0x18])
                                                                      (g_pGameRules,this,pcVar2);
                                                    uVar11 = 0;
                                                    if (iVar9 == 0) {
                                                      iVar9 = (*(this->super_CBaseMonster).
                                                                super_CBaseToggle.
                                                                super_CBaseAnimating.
                                                                super_CBaseDelay.super_CBaseEntity.
                                                                _vptr_CBaseEntity[0x22])(this);
                                                      if (iVar9 == 0) {
                                                        return;
                                                      }
                                                      uVar11 = 0;
                                                      if ((((this->super_CBaseMonster).
                                                            super_CBaseToggle.super_CBaseAnimating.
                                                            super_CBaseDelay.super_CBaseEntity.
                                                            is_building == 0) &&
                                                          (uVar11 = 0,
                                                          (this->super_CBaseMonster).
                                                          super_CBaseToggle.super_CBaseAnimating.
                                                          super_CBaseDelay.super_CBaseEntity.
                                                          is_detpacking == 0)) &&
                                                         (uVar11 = 0,
                                                         (this->super_CBaseMonster).
                                                         super_CBaseToggle.super_CBaseAnimating.
                                                         super_CBaseDelay.super_CBaseEntity.
                                                         is_feigning == 0)) {
                                                        BVar3 = FStrEq(pcVar2,"use");
                                                        uVar11 = BVar3 == 0;
                                                        if ((bool)uVar11) {
                                                          pcVar4 = strstr(pcVar2,"weapon_");
                                                          if (((pcVar4 == (char *)0x0) ||
                                                              (pcVar2 != pcVar4)) &&
                                                             ((pcVar4 = strstr(pcVar2,"tf_weapon_"),
                                                              pcVar4 == (char *)0x0 ||
                                                              (pcVar2 != pcVar4)))) {
                                                            BVar3 = FStrEq(pcVar2,"lastinv");
                                                            uVar11 = BVar3 == 0;
                                                            if ((bool)uVar11) {
                                                              BVar3 = FStrEq(pcVar2,"primeone");
                                                              uVar11 = BVar3 == 0;
                                                              if ((bool)uVar11) {
                                                                BVar3 = FStrEq(pcVar2,"primetwo");
                                                                if (BVar3 == 0) {
                                                                  BVar3 = FStrEq(pcVar2,"+gren1");
                                                                  uVar11 = BVar3 == 0;
                                                                  if (!(bool)uVar11)
                                                                  goto LAB_000b940a;
                                                                  BVar3 = FStrEq(pcVar2,"+gren2");
                                                                  if (BVar3 == 0) {
                                                                    BVar3 = FStrEq(pcVar2,"detstart"
                                                                                  );
                                                                    if (BVar3 == 0) {
                                                                      BVar3 = FStrEq(pcVar2,"+det5")
                                                                      ;
                                                                      uVar11 = BVar3 == 0;
                                                                      if ((bool)uVar11) {
                                                                        BVar3 = FStrEq(pcVar2,
                                                  "+det20");
                                                  uVar11 = BVar3 == 0;
                                                  if (!(bool)uVar11) goto LAB_000b9335;
                                                  BVar3 = FStrEq(pcVar2,"+det50");
                                                  uVar11 = BVar3 == 0;
                                                  if ((bool)uVar11) {
                                                    BVar3 = FStrEq(pcVar2,"discard");
                                                    if ((BVar3 == 0) &&
                                                       (BVar3 = FStrEq(pcVar2,"drop"), BVar3 == 0))
                                                    {
                                                      uVar11 = ((this->super_CBaseMonster).
                                                                super_CBaseToggle.
                                                                super_CBaseAnimating.
                                                                super_CBaseDelay.super_CBaseEntity.
                                                               pev)->playerclass == 0;
                                                      if (!(bool)uVar11) {
                                                        BVar3 = FStrEq(pcVar2,"saveme");
                                                        uVar11 = BVar3 == 0;
                                                        if (!(bool)uVar11) {
                                                          CBasePlayer::TeamFortress_SaveMe(this);
                                                        }
                                                      }
                                                    }
                                                    else {
                                                      uVar11 = 0;
                                                      CBasePlayer::TeamFortress_Discard(this);
                                                    }
                                                  }
                                                  else {
                                                    CBasePlayer::TeamFortress_SetDetpack(this,0x32);
                                                  }
                                                  }
                                                  else {
                                                    CBasePlayer::TeamFortress_SetDetpack(this,5);
                                                  }
                                                  }
                                                  else {
                                                    iVar9 = (*g_engfuncs.pfnCmd_Argc)();
                                                    uVar11 = iVar9 == 1;
                                                    if (iVar9 < 2) {
LAB_000b9335:
                                                      CBasePlayer::TeamFortress_SetDetpack
                                                                (this,0x14);
                                                    }
                                                    else {
                    /* Unresolved local var: int time@[???] */
                                                      pcVar4 = (*g_engfuncs.pfnCmd_Argv)(1);
                                                      iVar9 = strtol(pcVar4,(char **)0x0,10);
                                                      uVar11 = iVar9 == 0x32;
                                                      if (iVar9 < 0x33) {
                                                        uVar11 = iVar9 == 4;
                                                        if (iVar9 < 5) {
                                                          iVar9 = 5;
                                                        }
                                                      }
                                                      else {
                                                        iVar9 = 0x32;
                                                      }
                                                      CBasePlayer::TeamFortress_SetDetpack
                                                                (this,iVar9);
                                                    }
                                                  }
                                                  goto LAB_000b7f0c;
                                                  }
                                                  }
                                                  uVar11 = 0;
                                                  CBasePlayer::TeamFortress_PrimeGrenade(this,2);
                                                  }
                                                  else {
LAB_000b940a:
                                                    CBasePlayer::TeamFortress_PrimeGrenade(this,1);
                                                  }
                                                  }
                                                  else {
                                                    CBasePlayer::SelectLastItem(this);
                                                  }
                                                  }
                                                  else {
                                                    uVar11 = 1;
                                                    CBasePlayer::SelectItem(this,pcVar2);
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = (*g_engfuncs.pfnCmd_Argv)(1);
                                                    CBasePlayer::SelectItem(this,pcVar4);
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = (*g_engfuncs.pfnCmd_Argv)(1);
                                                    CBasePlayer::AdminAccess(this,pcVar4);
                                                  }
                                                }
                                                else {
                                                  iVar9 = (*g_engfuncs.pfnCmd_Argc)();
                                                  uVar11 = iVar9 == 1;
                                                  if (1 < iVar9) {
                    /* Unresolved local var: int iTeamNo@[DW_OP_reg0(EAX)] */
                                                    pcVar4 = (*g_engfuncs.pfnCmd_Argv)(1);
                                                    lVar8 = strtol(pcVar4,(char **)0x0,10);
                                                    uVar11 = lVar8 == 5;
                                                    if ((bool)uVar11) {
                                                      CBasePlayer::TeamFortress_TeamPutPlayerInTeam
                                                                (this);
                                                    }
                                                    else {
                                                      uVar11 = number_of_teams == (float)lVar8;
                                                      if (((float)lVar8 <= number_of_teams) &&
                                                         (uVar11 = lVar8 == 0, 0 < lVar8)) {
                                                        CBasePlayer::TeamFortress_TeamSet
                                                                  (this,lVar8);
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                              else {
                                                CBasePlayer::ResetMenu(this);
                                              }
                                            }
                                            else {
                                              peVar7 = (this->super_CBaseMonster).super_CBaseToggle.
                                                       super_CBaseAnimating.super_CBaseDelay.
                                                       super_CBaseEntity.pev;
                                              uVar11 = peVar7->iuser1 == 0;
                                              if ((bool)uVar11) {
                                                uVar11 = peVar7->playerclass == 0;
                                                if (!(bool)uVar11) {
                                                  CBasePlayer::Menu_Class(this);
                                                }
                                              }
                                              else {
LAB_000b8781:
                                                CBasePlayer::Menu_Team(this);
                                              }
                                            }
                                          }
                                          else {
                                            BVar3 = TeamFortress_TeamIsCivilian
                                                              ((float)(this->super_CBaseMonster).
                                                                      super_CBaseToggle.
                                                                      super_CBaseAnimating.
                                                                      super_CBaseDelay.
                                                                      super_CBaseEntity.team_no);
                                            uVar11 = BVar3 == 0;
                                            if (!(bool)uVar11) {
                                              CBasePlayer::ChangeClass(this,0xb);
                                            }
                                          }
                                        }
                                        else {
                                          BVar3 = CBasePlayer::PositionAvailable(this);
                                          uVar11 = BVar3 == 0;
                                          if ((bool)uVar11) {
                                            ClientPrint(peVar7,1,"#Game_enoughofclass",(char *)0x0,
                                                        (char *)0x0,(char *)0x0,(char *)0x0);
                                            CBasePlayer::Menu_Class(this);
                                          }
                                          else {
                                            CBasePlayer::ChangeClass(this,10);
                                          }
                                        }
                                      }
                                      else {
                                        CBasePlayer::ChangeClass(this,9);
                                      }
                                    }
                                    else {
                                      CBasePlayer::ChangeClass(this,8);
                                    }
                                  }
                                  else {
                                    CBasePlayer::ChangeClass(this,7);
                                  }
                                }
                                else {
                                  uVar11 = 0;
                                  CBasePlayer::ChangeClass(this,6);
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
      }
      goto LAB_000b7f0c;
    }
    uVar11 = 1;
    Host_Say(pEntity,0);
    iVar9 = 9;
    pcVar4 = pcVar2;
    pcVar5 = "flaginfo";
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      uVar11 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
    } while ((bool)uVar11);
    if ((bool)uVar11) goto LAB_000b83e1;
  }
  peVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar9 = peVar7->playerclass;
  bVar12 = iVar9 == 0;
  if (!bVar12) {
    iVar10 = 10;
    pcVar4 = pcVar2;
    pcVar5 = "dropitems";
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      bVar12 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
    } while (bVar12);
    if (bVar12) {
      CBasePlayer::DropGoalItems(this);
      return;
    }
    bVar12 = false;
    if (iVar9 == 9) {
      iVar10 = 10;
      bVar12 = true;
      pcVar4 = pcVar2;
      pcVar5 = "detsentry";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        bVar12 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
      } while (bVar12);
      if (bVar12) {
        DestroyBuilding((CBaseEntity *)this,"building_sentrygun");
        return;
      }
      iVar10 = 0x13;
      bVar12 = false;
      pcVar4 = pcVar2;
      pcVar5 = "detentryteleporter";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        bVar12 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
      } while (bVar12);
      if (bVar12) {
        DestroyTeleporter((CBaseEntity *)this,4);
        return;
      }
      iVar10 = 0x12;
      bVar12 = false;
      pcVar4 = pcVar2;
      pcVar5 = "detexitteleporter";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        bVar12 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
      } while (bVar12);
      if (bVar12) {
        DestroyTeleporter((CBaseEntity *)this,5);
        return;
      }
      iVar10 = 0xd;
      bVar12 = false;
      pcVar4 = pcVar2;
      pcVar5 = "detdispenser";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        bVar12 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
      } while (bVar12);
      if (bVar12) {
LAB_000b84a4:
        DestroyBuilding((CBaseEntity *)this,"building_dispenser");
        return;
      }
      iVar10 = 0xd;
      uVar11 = 0;
      pcVar4 = pcVar2;
      pcVar5 = "detdispensor";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        uVar11 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
      } while ((bool)uVar11);
      if ((bool)uVar11) goto LAB_000b84a4;
      iVar10 = 10;
      uVar11 = 0;
      pcVar4 = pcVar2;
      pcVar5 = "dismantle";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        uVar11 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
      } while ((bool)uVar11);
      if ((bool)uVar11) {
        iVar9 = (*g_engfuncs.pfnCmd_Argc)();
        if (iVar9 < 2) {
          return;
        }
                    /* Unresolved local var: int iBuildingID@[DW_OP_reg0(EAX)] */
        pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
        lVar8 = strtol(pcVar2,(char **)0x0,10);
        if (lVar8 == 1) {
          CBasePlayer::Menu_Engineer_Input(this,9.0);
          return;
        }
        if (lVar8 == 2) {
          CBasePlayer::Menu_Engineer_Input(this,3.0);
          return;
        }
        if (lVar8 != 4) {
          if (lVar8 != 5) {
            return;
          }
          CBasePlayer::Menu_Engineer_Input(this,11.0);
          return;
        }
        CBasePlayer::Menu_Engineer_Input(this,10.0);
        return;
      }
      iVar10 = 0xd;
      bVar12 = false;
      pcVar4 = pcVar2;
      pcVar5 = "rotatesentry";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        bVar12 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
      } while (bVar12);
      if (bVar12) {
        CBasePlayer::Menu_Engineer_Input(this,4.0);
        return;
      }
      iVar10 = 0x10;
      bVar13 = false;
      pcVar4 = pcVar2;
      pcVar5 = "rotatesentry180";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        bVar13 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
      } while (bVar13);
      bVar12 = false;
      if (bVar13) {
        CBasePlayer::Menu_Engineer_Input(this,6.0);
        return;
      }
    }
  }
  iVar10 = 8;
  pcVar4 = pcVar2;
  pcVar5 = "detpipe";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    bVar12 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while (bVar12);
  if (bVar12) {
    if (this->m_pActiveItem == (CBasePlayerItem *)0x0) {
      return;
    }
    if (0.0 < (float)this->m_pActiveItem[1].super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                     m_pGoalEnt) {
      return;
    }
    CBasePlayer::ExplodeOldPipebomb(this,1,0);
    return;
  }
  iVar10 = 10;
  bVar12 = false;
  pcVar4 = pcVar2;
  pcVar5 = "throwgren";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    bVar12 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while (bVar12);
  if (bVar12) {
LAB_000b86e0:
    CBasePlayer::TeamFortress_ThrowPrimedGrenade(this);
    return;
  }
  iVar10 = 7;
  uVar11 = 0;
  pcVar4 = pcVar2;
  pcVar5 = "-gren1";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    uVar11 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while ((bool)uVar11);
  if ((bool)uVar11) goto LAB_000b86e0;
  iVar10 = 7;
  uVar11 = 0;
  pcVar4 = pcVar2;
  pcVar5 = "-gren2";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    uVar11 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while ((bool)uVar11);
  if ((bool)uVar11) goto LAB_000b86e0;
  iVar10 = 8;
  uVar11 = 0;
  pcVar4 = pcVar2;
  pcVar5 = "detstop";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    uVar11 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while ((bool)uVar11);
  if ((bool)uVar11) {
LAB_000b8758:
    CBasePlayer::TeamFortress_DetpackStop(this);
    return;
  }
  iVar10 = 6;
  uVar11 = 0;
  pcVar4 = pcVar2;
  pcVar5 = "-det5";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    uVar11 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while ((bool)uVar11);
  if ((bool)uVar11) goto LAB_000b8758;
  iVar10 = 7;
  uVar11 = 0;
  pcVar4 = pcVar2;
  pcVar5 = "-det20";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    uVar11 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while ((bool)uVar11);
  if ((bool)uVar11) goto LAB_000b8758;
  iVar10 = 7;
  uVar11 = 0;
  pcVar4 = pcVar2;
  pcVar5 = "-det50";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    uVar11 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while ((bool)uVar11);
  if ((bool)uVar11) goto LAB_000b8758;
  iVar10 = 6;
  uVar11 = 0;
  pcVar4 = pcVar2;
  pcVar5 = "build";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    uVar11 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while ((bool)uVar11);
  if (((bool)uVar11) && (iVar9 == 9)) {
    iVar9 = (*g_engfuncs.pfnCmd_Argc)();
    if (iVar9 != 1) {
      pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
      lVar8 = strtol(pcVar2,(char **)0x0,10);
      CBasePlayer::TeamFortress_EngineerBuild(this,lVar8);
      return;
    }
    CBasePlayer::TeamFortress_EngineerBuild(this,0);
    return;
  }
  bVar12 = false;
  iVar10 = 9;
  pcVar4 = pcVar2;
  pcVar5 = "disguise";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    bVar12 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while (bVar12);
  if ((bVar12) && (iVar9 == 8)) {
    iVar9 = (*g_engfuncs.pfnCmd_Argc)();
    if (iVar9 == 1) {
      CBasePlayer::TeamFortress_SpyGoUndercover(this);
      return;
    }
    iVar9 = (*g_engfuncs.pfnCmd_Argc)();
    if (iVar9 != 2) {
      iVar9 = (*g_engfuncs.pfnCmd_Argc)();
      if (iVar9 != 3) {
        return;
      }
      pcVar2 = (*g_engfuncs.pfnCmd_Argv)(2);
      lVar8 = strtol(pcVar2,(char **)0x0,10);
      pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
      iTeam = strtol(pcVar2,(char **)0x0,10);
      CBasePlayer::TeamFortress_SpyDisguise(this,iTeam,lVar8);
      return;
    }
    pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
    lVar8 = strtol(pcVar2,(char **)0x0,10);
    CBasePlayer::TeamFortress_SpyDisguise(this,lVar8,0);
    return;
  }
  bVar12 = false;
  iVar10 = 0xf;
  pcVar4 = pcVar2;
  pcVar5 = "disguise_enemy";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    bVar12 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while (bVar12);
  if ((bVar12) && (iVar9 == 8)) {
    iVar9 = (*g_engfuncs.pfnCmd_Argc)();
    if (iVar9 != 1) {
      pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
      lVar8 = strtol(pcVar2,(char **)0x0,10);
      CBasePlayer::TeamFortress_SpyDisguiseEnemy(this,1,lVar8);
      return;
    }
    CBasePlayer::TeamFortress_SpyDisguiseEnemy(this,1,0);
    return;
  }
  bVar12 = false;
  iVar10 = 0x12;
  pcVar4 = pcVar2;
  pcVar5 = "disguise_friendly";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    bVar12 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while (bVar12);
  if ((bVar12) && (iVar9 == 8)) {
    iVar9 = (*g_engfuncs.pfnCmd_Argc)();
    if (iVar9 != 1) {
      pcVar2 = (*g_engfuncs.pfnCmd_Argv)(1);
      lVar8 = strtol(pcVar2,(char **)0x0,10);
      CBasePlayer::TeamFortress_SpyDisguiseEnemy(this,0,lVar8);
      return;
    }
    CBasePlayer::TeamFortress_SpyDisguiseEnemy(this,0,0);
    return;
  }
  bVar12 = false;
  iVar10 = 6;
  pcVar4 = pcVar2;
  pcVar5 = "feign";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    bVar12 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while (bVar12);
  if ((bVar12) && (iVar9 == 8)) {
    CBasePlayer::TeamFortress_SpyFeignDeath(this,0);
    return;
  }
  bVar12 = false;
  iVar10 = 7;
  pcVar4 = pcVar2;
  pcVar5 = "sfeign";
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    bVar12 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar14 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar14 * -2 + 1;
  } while (bVar12);
  if ((bVar12) && (iVar9 == 8)) {
    CBasePlayer::TeamFortress_SpyFeignDeath(this,1);
    return;
  }
  BVar3 = FStrEq(pcVar2,"timeleft");
  if (BVar3 == 0) {
    BVar3 = FStrEq(pcVar2,"sendevents");
    if (BVar3 == 0) {
      return;
    }
    if (this->m_bSentBuildingEvents != 0) {
      return;
    }
    SendBuildingEventInfo(this);
    this->m_bSentBuildingEvents = 1;
    return;
  }
  if (gpGlobals->time <= (float)this->m_iTimeCheckAllowed) {
    return;
  }
  if (timelimit.value == 0.0) {
    ClientPrint(peVar7,3,"#Game_no_timelimit",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    goto LAB_000b814b;
  }
                    /* Unresolved local var: int iTimeRemaining@[???]
                       Unresolved local var: int iMinutes@[???]
                       Unresolved local var: int iSeconds@[???]
                       Unresolved local var: char[5] secs@[???]
                       Unresolved local var: char * temp@[???] */
  iVar9 = (int)(timelimit.value * 60.0 - gpGlobals->time);
  if (iVar9 < 0) {
    iVar10 = 0;
    pcVar2 = UTIL_dtos2(0);
LAB_000b8de1:
    local_21 = '0';
    local_20 = *pcVar2;
  }
  else {
    iVar10 = iVar9 / 0x3c;
    pcVar2 = UTIL_dtos2(iVar9 % 0x3c);
    if (iVar9 % 0x3c < 10) goto LAB_000b8de1;
    local_21 = *pcVar2;
    local_20 = pcVar2[1];
  }
  local_1f = 0;
  pcVar2 = UTIL_dtos1(iVar10);
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,3,"#Game_timelimit",pcVar2,&local_21,(char *)0x0,(char *)0x0);
LAB_000b814b:
  this->m_iTimeCheckAllowed = (int)(gpGlobals->time + 1.0);
  return;
}


// ClientUserInfoChanged  @ 000b9430  (line 1179)

void ClientUserInfoChanged(edict_t *pEntity,char *infobuffer)

{
  string_t sVar1;
  _func_int_varargs *p_Var2;
  edict_t *peVar3;
  void *pvVar4;
  _func_void_int *p_Var5;
  _func_void_int_char_ptr_char_ptr_char_ptr *p_Var6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  CBasePlayer *this;
  CGameRules *pCVar10;
  char *pcVar11;
  char local_21c [255];
  undefined1 local_11d;
  char local_11c [268];
  
  if (pEntity->pvPrivateData != (void *)0x0) {
    sVar1 = (pEntity->v).netname;
    if ((sVar1 != 0) && (gpGlobals->pStringBase[sVar1] != '\0')) {
      pcVar7 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"name");
      iVar8 = strcmp(gpGlobals->pStringBase + (pEntity->v).netname,pcVar7);
      if (iVar8 != 0) {
                    /* Unresolved local var: char[256] sName@[???]
                       Unresolved local var: char * pName@[???]
                       Unresolved local var: char[256] text@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg7(EDI)] */
        pcVar7 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"name");
        strncpy(local_21c,pcVar7,0xff);
        p_Var6 = g_engfuncs.pfnSetClientKeyValue;
        local_11d = 0;
        pcVar7 = local_21c;
                    /* Unresolved local var: char * pApersand@[???] */
        while (local_21c[0] != '\0') {
          if (*pcVar7 == '%') {
            *pcVar7 = ' ';
          }
          pcVar7 = pcVar7 + 1;
          if (pcVar7 == (char *)0x0) break;
          local_21c[0] = *pcVar7;
        }
        iVar8 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
        (*p_Var6)(iVar8,infobuffer,"name",local_21c);
        pcVar7 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"name");
        sprintf(local_11c,"* %s changed name to %s\n",gpGlobals->pStringBase + (pEntity->v).netname,
                pcVar7);
        (*g_engfuncs.pfnMessageBegin)(2,gmsgSayText,(float *)0x0,(edict_t *)0x0);
        p_Var5 = g_engfuncs.pfnWriteByte;
        iVar8 = (*g_engfuncs.pfnIndexOfEdict)(pEntity);
        (*p_Var5)(iVar8);
        (*g_engfuncs.pfnWriteString)(local_11c);
        (*g_engfuncs.pfnMessageEnd)();
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
        pvVar4 = pEntity->pvPrivateData;
        pcVar7 = (*g_engfuncs.pfnInfoKeyValue)(infobuffer,"name");
        iVar8 = *(int *)((int)pvVar4 + 0x138);
        pcVar11 = "SPECTATOR";
        if (iVar8 != 0) {
          pcVar11 = GetTeamName(iVar8);
        }
        pcVar9 = (*g_engfuncs.pfnGetPlayerAuthId)(pEntity);
        iVar8 = (*g_engfuncs.pfnGetPlayerUserId)(pEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" changed name to \"%s\"\n",
                       gpGlobals->pStringBase + (pEntity->v).netname,iVar8,pcVar9,pcVar11,pcVar7);
      }
    }
    p_Var2 = g_pGameRules->_vptr_CGameRules[0x19];
    peVar3 = (pEntity->v).pContainingEntity;
                    /* Unresolved local var: entvars_t * pev@[???] */
    if ((peVar3 == (edict_t *)0x0) ||
       (this = peVar3->pvPrivateData, pCVar10 = g_pGameRules, this == (CBasePlayer *)0x0)) {
      this = CBaseEntity::operator_new(0xecc,&pEntity->v);
      CBasePlayer::CBasePlayer(this);
      pCVar10 = g_pGameRules;
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.pev = &pEntity->v;
    }
    (*p_Var2)(pCVar10,this,infobuffer);
  }
  return;
}


// ServerDeactivate  @ 000b96a0  (line 1229)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ServerDeactivate(void)

{
  if (g_serveractive != 1) {
    return;
  }
  g_serveractive = 0;
  return;
}


// ServerActivate  @ 000b96c0  (line 1245)

void ServerActivate(edict_t *pEdictList,int edictCount,int clientMax)

{
  entvars_t *peVar1;
  int *piVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CBaseEntity * pClass@[???] */
  g_serveractive = 1;
  if (0 < edictCount) {
    iVar3 = 0;
    do {
      while (((pEdictList->free != 0 || (iVar3 < clientMax)) ||
             (piVar2 = pEdictList->pvPrivateData, piVar2 == (int *)0x0))) {
LAB_000b9700:
        iVar3 = iVar3 + 1;
        pEdictList = pEdictList + 1;
        if (iVar3 == edictCount) goto LAB_000b9770;
      }
      if (-1 < *(int *)(piVar2[1] + 0x1a4)) {
        (**(code **)(*piVar2 + 0x20))(piVar2);
        goto LAB_000b9700;
      }
      iVar3 = iVar3 + 1;
      peVar1 = &pEdictList->v;
      pEdictList = pEdictList + 1;
      (*g_engfuncs.pfnAlertMessage)
                (at_console,"Can\'t instance %s\n",gpGlobals->pStringBase + peVar1->classname);
    } while (iVar3 != edictCount);
  }
LAB_000b9770:
  ParseTFMapSettings();
  LinkUserMessages();
  (*g_engfuncs.pfnCVarSetFloat)("sv_maxspeed",400.0);
  (*g_engfuncs.pfnServerCommand)("sv_maxspeed 400\n");
  if (ServerActivate::lexical_block_0::firstTime != 0) {
    (*g_engfuncs.pfnAddServerCommand)("tf_ceasefire",Admin_CeaseFire);
    ServerActivate::lexical_block_0::firstTime = 0;
  }
  return;
}


// PlayerPreThink  @ 000b97d0  (line 1304)

void PlayerPreThink(edict_t *pEntity)

{
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg0(EAX)] */
  if ((pEntity != (edict_t *)0x0) && (pEntity->pvPrivateData != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000b97eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pEntity->pvPrivateData + 0x220))();
    return;
  }
  return;
}


// PlayerPostThink  @ 000b9800  (line 1320)

void PlayerPostThink(edict_t *pEntity)

{
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg0(EAX)] */
  if ((pEntity != (edict_t *)0x0) && (pEntity->pvPrivateData != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000b981b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pEntity->pvPrivateData + 0x224))();
    return;
  }
  return;
}


// ParmsNewLevel  @ 000b9830  (line 1332)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ParmsNewLevel(void)

{
  return;
}


// ParmsChangeLevel  @ 000b9840  (line 1336)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ParmsChangeLevel(void)

{
  void *pvVar1;
  int iVar2;
  
                    /* Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
  pvVar1 = gpGlobals->pSaveData;
  if (pvVar1 != (void *)0x0) {
    iVar2 = BuildChangeList((LEVELLIST *)((int)pvVar1 + 0x2c),0x10);
    *(int *)((int)pvVar1 + 0x24) = iVar2;
  }
  return;
}


// StartFrame  @ 000b9870  (line 1348)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void StartFrame(void)

{
  int *piVar1;
  float fVar2;
  globalvars_t *pgVar3;
  longdouble extraout_ST0;
  
  if (g_pGameRules != (CGameRules *)0x0) {
    (*g_pGameRules->_vptr_CGameRules[1])(g_pGameRules);
  }
  pgVar3 = gpGlobals;
  if (g_fGameOver == 0) {
    piVar1 = &gpGlobals->maxClients;
    gpGlobals->teamplay = teamplay.value;
    if (*piVar1 < 8) {
      (*g_engfuncs.pfnCVarGetFloat)("deathmatch");
      pgVar3->deathmatch = (float)extraout_ST0;
    }
    else {
      pgVar3->deathmatch = 1.0;
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
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
      if (ROUND(fVar2) != ROUND(fOldPrematch)) {
        cb_prematch_time = fVar2 + gpGlobals->time;
        g_fNextPrematchAlert = 0.0;
        fOldPrematch = fVar2;
      }
      Display_Prematch();
    }
                    /* Unresolved local var: float fNewCeaseFire@[???] */
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    if ((initial_cease_fire != 0) &&
       (fVar2 = tfc_clanbattle_ceasefire.value * 60.0, ROUND(fVar2) != ROUND(fOldCeaseFire))) {
      cb_ceasefire_time = fVar2 + gpGlobals->time;
      fOldCeaseFire = fVar2;
    }
    if (last_cease_fire != 0) {
      Check_Ceasefire();
    }
    g_ulFrameCount = g_ulFrameCount + 1;
    g_iSkillLevel = 1;
  }
  return;
}


// ClientPrecache  @ 000b9b10  (line 1420)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClientPrecache(void)

{
  char **ppcVar1;
  float *pfVar2;
  int iVar3;
  float local_5c [4];
  float local_4c [4];
  float local_3c [13];
  
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
  if (sNewClassModelFiles[1] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sNewClassModelFiles[1]);
  }
  if (sOldClassModelFiles[1] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sOldClassModelFiles[1]);
  }
  if (sNewClassModelFiles[2] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sNewClassModelFiles[2]);
  }
  if (sOldClassModelFiles[2] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sOldClassModelFiles[2]);
  }
  if (sNewClassModelFiles[3] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sNewClassModelFiles[3]);
  }
  if (sOldClassModelFiles[3] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sOldClassModelFiles[3]);
  }
  if (sNewClassModelFiles[4] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sNewClassModelFiles[4]);
  }
  if (sOldClassModelFiles[4] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sOldClassModelFiles[4]);
  }
  if (sNewClassModelFiles[5] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sNewClassModelFiles[5]);
  }
  if (sOldClassModelFiles[5] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sOldClassModelFiles[5]);
  }
  if (sNewClassModelFiles[6] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sNewClassModelFiles[6]);
  }
  if (sOldClassModelFiles[6] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sOldClassModelFiles[6]);
  }
  if (sNewClassModelFiles[7] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sNewClassModelFiles[7]);
  }
  if (sOldClassModelFiles[7] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sOldClassModelFiles[7]);
  }
  if (sNewClassModelFiles[8] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sNewClassModelFiles[8]);
  }
  if (sOldClassModelFiles[8] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sOldClassModelFiles[8]);
  }
  if (sNewClassModelFiles[9] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sNewClassModelFiles[9]);
  }
  if (sOldClassModelFiles[9] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sOldClassModelFiles[9]);
  }
  if (sNewClassModelFiles[10] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sNewClassModelFiles[10]);
  }
  if (sOldClassModelFiles[10] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sOldClassModelFiles[10]);
  }
  if (sNewClassModelFiles[0xb] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sNewClassModelFiles[0xb]);
  }
  if (sOldClassModelFiles[0xb] != (char *)0x0) {
    (*g_engfuncs.pfnPrecacheModel)(sOldClassModelFiles[0xb]);
  }
  iVar3 = 0;
  do {
    (*g_engfuncs.pfnPrecacheModel)(sNewWeaponPModels[iVar3]);
    ppcVar1 = sOldWeaponPModels + iVar3;
    iVar3 = iVar3 + 1;
    (*g_engfuncs.pfnPrecacheModel)(*ppcVar1);
  } while (iVar3 != 0x12);
  local_5c[0] = -43.0;
  local_5c[1] = -14.0;
  local_5c[2] = -49.0;
  local_4c[0] = 43.0;
  local_4c[1] = 11.0;
  local_4c[2] = 49.0;
  if (sNewClassModelFiles[1] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sNewClassModelFiles[1]);
  }
  if (sOldClassModelFiles[1] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sOldClassModelFiles[1]);
  }
  if (sNewClassModelFiles[2] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sNewClassModelFiles[2]);
  }
  if (sOldClassModelFiles[2] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sOldClassModelFiles[2]);
  }
  if (sNewClassModelFiles[3] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sNewClassModelFiles[3]);
  }
  if (sOldClassModelFiles[3] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sOldClassModelFiles[3]);
  }
  if (sNewClassModelFiles[4] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sNewClassModelFiles[4]);
  }
  if (sOldClassModelFiles[4] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sOldClassModelFiles[4]);
  }
  if (sNewClassModelFiles[5] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sNewClassModelFiles[5]);
  }
  if (sOldClassModelFiles[5] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sOldClassModelFiles[5]);
  }
  if (sNewClassModelFiles[6] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sNewClassModelFiles[6]);
  }
  if (sOldClassModelFiles[6] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sOldClassModelFiles[6]);
  }
  if (sNewClassModelFiles[7] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sNewClassModelFiles[7]);
  }
  if (sOldClassModelFiles[7] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sOldClassModelFiles[7]);
  }
  if (sNewClassModelFiles[8] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sNewClassModelFiles[8]);
  }
  if (sOldClassModelFiles[8] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sOldClassModelFiles[8]);
  }
  if (sNewClassModelFiles[9] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sNewClassModelFiles[9]);
  }
  if (sOldClassModelFiles[9] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sOldClassModelFiles[9]);
  }
  if (sNewClassModelFiles[10] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sNewClassModelFiles[10]);
  }
  if (sOldClassModelFiles[10] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sOldClassModelFiles[10]);
  }
  if (sNewClassModelFiles[0xb] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sNewClassModelFiles[0xb]);
  }
  if (sOldClassModelFiles[0xb] != (char *)0x0) {
    (*g_engfuncs.pfnForceUnmodified)
              (force_model_specifybounds,local_5c,local_4c,sOldClassModelFiles[0xb]);
  }
  iVar3 = 0;
  do {
    (*g_engfuncs.pfnForceUnmodified)
              (force_exactfile,(float *)0x0,(float *)0x0,sNewWeaponPModels[iVar3]);
    ppcVar1 = sOldWeaponPModels + iVar3;
    iVar3 = iVar3 + 1;
    (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,*ppcVar1);
  } while (iVar3 != 0x12);
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
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/detpack.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/w_rpg.mdl");
  pfVar2 = local_3c + 3;
  (*g_engfuncs.pfnForceUnmodified)(force_exactfile,(float *)0x0,(float *)0x0,"models/rpgrocket.mdl")
  ;
  local_3c[0] = -32.0;
  local_3c[1] = -32.0;
  local_3c[2] = -32.0;
  local_3c[3] = 32.0;
  local_3c[4] = 32.0;
  local_3c[5] = 32.0;
  (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,local_3c,pfVar2,"models/base.mdl");
  local_3c[0] = -24.0;
  local_3c[1] = -24.0;
  local_3c[2] = -24.0;
  (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,local_3c,pfVar2,"models/sentry1.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,local_3c,pfVar2,"models/sentry2.mdl");
  (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,local_3c,pfVar2,"models/sentry3.mdl");
  local_3c[3] = 16.0;
  local_3c[4] = 64.0;
  local_3c[5] = 16.0;
  (*g_engfuncs.pfnForceUnmodified)(force_model_specifybounds,local_3c,pfVar2,"models/dispenser.mdl")
  ;
  local_3c[9] = 29.0;
  local_3c[10] = 26.0;
  local_3c[0xb] = 12.0;
  local_3c[6] = -29.0;
  local_3c[7] = -29.0;
  local_3c[8] = -1.0;
  (*g_engfuncs.pfnForceUnmodified)
            (force_model_specifybounds,local_3c + 6,local_3c + 9,"models/teleporter.mdl");
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


// GetGameDescription  @ 000baa10  (line 1666)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * GetGameDescription(void)

{
  return "Team Fortress Classic";
}


// Sys_Error  @ 000baa20  (line 1678)

void Sys_Error(char *error_string)

{
  return;
}


// PlayerCustomization  @ 000baa30  (line 1690)

void PlayerCustomization(edict_t *pEntity,customization_t *pCust)

{
  resourcetype_t rVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pPlayer@[DW_OP_reg1(ECX)] */
  if ((pEntity == (edict_t *)0x0) || (pEntity->pvPrivateData == (CBasePlayer *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000baaaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_console,"PlayerCustomization:  Couldn\'t get player!\n");
    return;
  }
  if (pCust == (customization_t *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000baacf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnAlertMessage)(at_console,"PlayerCustomization:  NULL customization!\n");
    return;
  }
  rVar1 = (pCust->resource).type;
  if (-1 < (int)rVar1) {
    if ((int)rVar1 < 3) {
      return;
    }
    if (rVar1 == t_decal) {
      CBasePlayer::SetCustomDecalFrames(pEntity->pvPrivateData,pCust->nUserData2);
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000baa6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnAlertMessage)(at_console,"PlayerCustomization:  Unknown customization type!\n");
  return;
}


// SpectatorConnect  @ 000baae0  (line 1730)

void SpectatorConnect(edict_t *pEntity)

{
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBaseSpectator * pPlayer@[DW_OP_reg0(EAX)] */
  if ((pEntity != (edict_t *)0x0) && (pEntity->pvPrivateData != (CBaseSpectator *)0x0)) {
    CBaseSpectator::SpectatorConnect(pEntity->pvPrivateData);
    return;
  }
  return;
}


// SpectatorDisconnect  @ 000bab10  (line 1746)

void SpectatorDisconnect(edict_t *pEntity)

{
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBaseSpectator * pPlayer@[DW_OP_reg0(EAX)] */
  if ((pEntity != (edict_t *)0x0) && (pEntity->pvPrivateData != (CBaseSpectator *)0x0)) {
    CBaseSpectator::SpectatorDisconnect(pEntity->pvPrivateData);
    return;
  }
  return;
}


// SpectatorThink  @ 000bab40  (line 1762)

void SpectatorThink(edict_t *pEntity)

{
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBaseSpectator * pPlayer@[DW_OP_reg0(EAX)] */
  if ((pEntity != (edict_t *)0x0) && (pEntity->pvPrivateData != (CBaseSpectator *)0x0)) {
    CBaseSpectator::SpectatorThink(pEntity->pvPrivateData);
    return;
  }
  return;
}


// SetupVisibility  @ 000bab70  (line 1789)

/* WARNING: Variable defined which should be unmapped: pPlayer */

void SetupVisibility(edict_t *pViewEntity,edict_t *pClient,uchar **pvs,uchar **pas)

{
  uchar *puVar1;
  int iVar2;
  CBaseEntity *pCVar3;
  EHANDLE *this;
  float local_2c;
  float local_28;
  float local_24;
  CBasePlayer *pPlayer;
  
                    /* Unresolved local var: Vector org@[???]
                       Unresolved local var: edict_t * pView@[???] */
  if (pViewEntity == (edict_t *)0x0) {
    pViewEntity = pClient;
  }
  if (((pClient->v).flags & 0x100000) == 0) {
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if (*(int *)(*(int *)((int)pClient->pvPrivateData + 4) + 0x248) != 0) {
      this = (EHANDLE *)((int)pClient->pvPrivateData + 0x6bc);
      iVar2 = EHANDLE::operator_int(this);
      if (iVar2 != 0) {
        pCVar3 = EHANDLE::operator->(this);
        pViewEntity = pCVar3->pev->pContainingEntity;
      }
    }
    local_24 = (pViewEntity->v).origin.z + (pViewEntity->v).view_ofs.z;
    local_28 = (pViewEntity->v).origin.y + (pViewEntity->v).view_ofs.y;
    local_2c = (pViewEntity->v).origin.x + (pViewEntity->v).view_ofs.x;
    if (((pViewEntity->v).flags & 0x4000) != 0) {
      local_2c = local_2c + 0.0;
      local_28 = local_28 + 0.0;
      local_24 = local_24 - 18.0;
    }
    puVar1 = (*g_engfuncs.pfnSetFatPVS)(&local_2c);
    *pvs = puVar1;
    puVar1 = (*g_engfuncs.pfnSetFatPAS)(&local_2c);
    *pas = puVar1;
  }
  else {
    *pvs = (uchar *)0x0;
    *pas = (uchar *)0x0;
  }
  return;
}


// AddToFullPack  @ 000bac90  (line 1842)

/* WARNING: Variable defined which should be unmapped: pPlayer */

int AddToFullPack(entity_state_s *state,int e,edict_t *ent,edict_t *host,int hostflags,int player,
                 uchar *pSet)

{
  uchar *puVar1;
  uint uVar2;
  uint uVar3;
  edict_t *peVar4;
  uint uVar5;
  entity_state_s *peVar6;
  Vector *pVVar7;
  void *pvVar8;
  int iVar9;
  bool bVar10;
  CBasePlayer *pPlayer;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  peVar4 = ent;
  if ((ent == (edict_t *)0x0) &&
     (peVar4 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar4 == (edict_t *)0x0)) {
    pvVar8 = (void *)0x0;
  }
  else {
    pvVar8 = peVar4->pvPrivateData;
  }
  if ((((ent == host) || (iVar9 = 0, ((ent->v).effects & 0x80) == 0)) &&
      (iVar9 = 0, (ent->v).modelindex != 0)) &&
     (gpGlobals->pStringBase + (ent->v).model != (char *)0x0)) {
    uVar5 = (ent->v).flags;
    if (ent != host) {
      if ((uVar5 & 0x4000000) != 0) {
        return 0;
      }
      iVar9 = (*g_engfuncs.pfnCheckVisibility)(ent,pSet);
      if (iVar9 == 0) {
        return 0;
      }
      uVar5 = (ent->v).flags;
    }
    if ((((uVar5 & 0x100) == 0) || ((hostflags & 1U) == 0)) || (iVar9 = 0, (ent->v).owner != host))
    {
      iVar9 = (host->v).groupinfo;
      if (iVar9 != 0) {
        UTIL_SetGroupTrace(iVar9,0);
        uVar5 = (ent->v).groupinfo;
        if (uVar5 != 0) {
          if (g_groupop == 0) {
            if (((host->v).groupinfo & uVar5) == 0) {
              return 0;
            }
          }
          else if ((g_groupop == 1) && (((host->v).groupinfo & uVar5) != 0)) {
            return 0;
          }
        }
        UTIL_UnsetGroupTrace();
      }
      bVar10 = ((uint)state & 1) != 0;
      uVar5 = 0x154;
      peVar6 = state;
      if (bVar10) {
        *(undefined1 *)&state->entityType = 0;
        peVar6 = (entity_state_s *)((int)&state->entityType + 1);
        uVar5 = 0x153;
      }
      if (((uint)peVar6 & 2) != 0) {
        *(undefined2 *)&peVar6->entityType = 0;
        uVar5 = uVar5 - 2;
        peVar6 = (entity_state_s *)((int)&peVar6->entityType + 2);
      }
      uVar2 = 0;
      do {
        uVar3 = uVar2;
        puVar1 = peVar6->controller + (uVar3 - 0x68);
        puVar1[0] = '\0';
        puVar1[1] = '\0';
        puVar1[2] = '\0';
        puVar1[3] = '\0';
        puVar1 = peVar6->controller + (uVar3 - 100);
        puVar1[0] = '\0';
        puVar1[1] = '\0';
        puVar1[2] = '\0';
        puVar1[3] = '\0';
        puVar1 = peVar6->controller + (uVar3 - 0x60);
        puVar1[0] = '\0';
        puVar1[1] = '\0';
        puVar1[2] = '\0';
        puVar1[3] = '\0';
        puVar1 = peVar6->controller + (uVar3 - 0x5c);
        puVar1[0] = '\0';
        puVar1[1] = '\0';
        puVar1[2] = '\0';
        puVar1[3] = '\0';
        uVar2 = uVar3 + 0x10;
      } while (uVar3 + 0x10 < (uVar5 & 0xfffffff0));
      pVVar7 = (Vector *)(peVar6->controller + (uVar3 - 0x58));
      if ((uVar5 & 8) != 0) {
        *(uchar *)&pVVar7->x = '\0';
        *(uchar *)((int)&pVVar7->x + 1) = '\0';
        *(uchar *)((int)&pVVar7->x + 2) = '\0';
        *(uchar *)((int)&pVVar7->x + 3) = '\0';
        *(uchar *)&pVVar7->y = '\0';
        *(uchar *)((int)&pVVar7->y + 1) = '\0';
        *(uchar *)((int)&pVVar7->y + 2) = '\0';
        *(uchar *)((int)&pVVar7->y + 3) = '\0';
        pVVar7 = (Vector *)&pVVar7->z;
      }
      if ((uVar5 & 4) != 0) {
        pVVar7->x = 0.0;
        pVVar7 = (Vector *)&pVVar7->y;
      }
      if ((uVar5 & 2) != 0) {
        *(undefined2 *)&pVVar7->x = 0;
        pVVar7 = (Vector *)((int)&pVVar7->x + 2);
      }
      if (bVar10) {
        *(uchar *)&pVVar7->x = '\0';
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
      if ((pvVar8 == (void *)0x0) || (iVar9 = *(int *)((int)pvVar8 + 0x2c0), iVar9 == 0)) {
        iVar9 = (ent->v).skin;
      }
      state->skin = (short)iVar9;
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
      if ((pvVar8 == (void *)0x0) || (*(int *)((int)pvVar8 + 700) == 0)) {
        state->body = (ent->v).body;
      }
      else {
        state->body = *(int *)((int)pvVar8 + 700);
      }
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
      peVar4 = (ent->v).aiment;
      if (peVar4 != (edict_t *)0x0) {
        iVar9 = (*g_engfuncs.pfnIndexOfEdict)(peVar4);
        state->aiment = iVar9;
      }
      state->owner = 0;
      peVar4 = (ent->v).owner;
                    /* Unresolved local var: int owner@[DW_OP_reg0(EAX)] */
      if (((peVar4 != (edict_t *)0x0) && (iVar9 = (*g_engfuncs.pfnIndexOfEdict)(peVar4), 0 < iVar9))
         && (iVar9 <= gpGlobals->maxClients)) {
        state->owner = iVar9;
      }
      iVar9 = 1;
      state->fuser1 = 0.0;
      if (player != 0) {
        (state->basevelocity).x = (ent->v).basevelocity.x;
        (state->basevelocity).y = (ent->v).basevelocity.y;
        (state->basevelocity).z = (ent->v).basevelocity.z;
        if ((pvVar8 == (void *)0x0) || ((*(byte *)((int)pvVar8 + 0x2c4) & 1) == 0)) {
          iVar9 = (*g_engfuncs.pfnModelIndex)(gpGlobals->pStringBase + (ent->v).weaponmodel);
          state->weaponmodel = iVar9;
        }
        else {
          state->weaponmodel = 0;
        }
        iVar9 = 1;
        state->gaitsequence = (ent->v).gaitsequence;
        state->spectator = (ent->v).flags & 0x4000000;
        state->friction = (ent->v).friction;
        state->gravity = (ent->v).gravity;
        state->team = (ent->v).team;
        state->playerclass = (ent->v).playerclass;
        state->usehull = (uint)(((ent->v).flags & 0x4000) != 0);
        state->health = (int)(ent->v).health;
        if ((pvVar8 != (void *)0x0) && (*(int *)((int)pvVar8 + 0x2b8) != 0)) {
          state->fuser1 = 1.0;
          iVar9 = 1;
        }
      }
    }
  }
  return iVar9;
}


// CreateBaseline  @ 000bb2d0  (line 2041)

void CreateBaseline(int player,int eindex,entity_state_s *baseline,edict_s *entity,
                   int playermodelindex,Vector player_mins,Vector player_maxs)

{
  vec_t vVar1;
  float fVar2;
  
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
    vVar1 = (entity->v).maxs.z;
    baseline->colormap = 0;
    (baseline->maxs).z = vVar1;
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
  vVar1 = *(vec_t *)((int)player_mins.y + 8);
  baseline->friction = 1.0;
  baseline->movetype = 3;
  (baseline->maxs).z = vVar1;
  baseline->colormap = eindex;
  baseline->modelindex = playermodelindex;
  fVar2 = (entity->v).scale;
  baseline->solid = 3;
  baseline->framerate = 1.0;
  baseline->gravity = 1.0;
  baseline->scale = fVar2;
  baseline->playerclass = (entity->v).playerclass;
  baseline->fov = (entity->v).fov;
  return;
}


// CreateBaseline  @ 000b6520  (line 2042)

void __regparm3
CreateBaseline(int player,int eindex,entity_state_s *baseline,edict_s *entity,int playermodelindex,
              Vector player_mins,Vector player_maxs)

{
  undefined4 uVar1;
  
  *(undefined4 *)(player + 0x10) = *(undefined4 *)(eindex + 0x88);
  *(undefined4 *)(player + 0x14) = *(undefined4 *)(eindex + 0x8c);
  *(undefined4 *)(player + 0x18) = *(undefined4 *)(eindex + 0x90);
  *(undefined4 *)(player + 0x1c) = *(undefined4 *)(eindex + 0xd0);
  *(undefined4 *)(player + 0x20) = *(undefined4 *)(eindex + 0xd4);
  *(undefined4 *)(player + 0x24) = *(undefined4 *)(eindex + 0xd8);
  *(undefined4 *)(player + 0x30) = *(undefined4 *)(eindex + 0x1b0);
  *(short *)(player + 0x38) = (short)*(undefined4 *)(eindex + 400);
  *(uint *)(player + 0x48) = (uint)*(byte *)(eindex + 0x1c8);
  *(uint *)(player + 0x4c) = (int)*(float *)(eindex + 0x1cc) & 0xff;
  *(char *)(player + 0x50) = (char)(int)*(float *)(eindex + 0x1d0);
  *(char *)(player + 0x51) = (char)(int)*(float *)(eindex + 0x1d4);
  *(char *)(player + 0x52) = (char)(int)*(float *)(eindex + 0x1d8);
  *(uint *)(player + 0x54) = (uint)*(byte *)(eindex + 0x1dc);
  *(undefined4 *)(player + 0x7c) = *(undefined4 *)(eindex + 0x15c);
  *(undefined4 *)(player + 0x80) = *(undefined4 *)(eindex + 0x160);
  *(undefined4 *)(player + 0x84) = *(undefined4 *)(eindex + 0x164);
  *(undefined4 *)(player + 0x88) = *(undefined4 *)(eindex + 0x168);
  *(undefined4 *)(player + 0x8c) = *(undefined4 *)(eindex + 0x16c);
  uVar1 = *(undefined4 *)(eindex + 0x170);
  *(undefined4 *)(player + 0x34) = 0;
  *(undefined4 *)(player + 0x90) = uVar1;
  *(undefined4 *)(player + 0x28) = *(undefined4 *)(eindex + 0x134);
  *(undefined4 *)(player + 0x58) = *(undefined4 *)(eindex + 0x188);
  *(undefined4 *)(player + 0x40) = *(undefined4 *)(eindex + 0x1c4);
  *(short *)(player + 0x3a) = (short)*(undefined4 *)(eindex + 0x18c);
  *(undefined4 *)(player + 0x60) = *(undefined4 *)(eindex + 0x1b8);
  *(undefined4 *)(player + 0xa0) = *(undefined4 *)(eindex + 0x19c);
  return;
}


// Entity_FieldInit  @ 000bb4a0  (line 2115)

void Entity_FieldInit(delta_s *pFields)

{
  entity_field_alias[0].field = (*g_engfuncs.pfnDeltaFindField)(pFields,entity_field_alias[0].name);
  entity_field_alias[1].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c4fa4);
  entity_field_alias[2].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c4fc8);
  entity_field_alias[3].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c4fec);
  entity_field_alias[4].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c5010);
  entity_field_alias[5].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c5034);
  return;
}


// Entity_Encode  @ 000b6800  (line 2133)

void Entity_Encode(delta_s *pFields,uchar *from,uchar *to)

{
  int iVar1;
  _func_void_delta_s_ptr_int *UNRECOVERED_JUMPTABLE;
  int iVar2;
  
                    /* Unresolved local var: entity_state_t * f@[???]
                       Unresolved local var: entity_state_t * t@[???]
                       Unresolved local var: int localplayer@[???] */
  if (Entity_Encode::lexical_block_0::initialized == 0) {
    entity_field_alias[0].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,entity_field_alias[0].name);
    entity_field_alias[1].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,entity_field_alias[1].name);
    entity_field_alias[2].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,entity_field_alias[2].name);
    entity_field_alias[3].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,entity_field_alias[3].name);
    entity_field_alias[4].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,entity_field_alias[4].name);
    entity_field_alias[5].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,entity_field_alias[5].name);
    Entity_Encode::lexical_block_0::initialized = 1;
    iVar2 = *(int *)(to + 4);
    iVar1 = (*g_engfuncs.pfnGetCurrentPlayer)();
    if (iVar2 + -1 == iVar1) goto LAB_000b6a5e;
  }
  else {
    iVar2 = *(int *)(to + 4);
    iVar1 = (*g_engfuncs.pfnGetCurrentPlayer)();
    if (iVar2 + -1 == iVar1) {
LAB_000b6a5e:
      (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[0].field);
      (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[1].field);
      (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[2].field);
    }
  }
  if ((*(float *)(to + 0xfc) == 0.0) || (*(float *)(to + 0x100) == 0.0)) {
    if (*(int *)(to + 0x58) != 0xc) goto LAB_000b685a;
LAB_000b6950:
    iVar2 = 0;
    if (*(int *)(to + 0x94) != 0) {
      (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[0].field);
      (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[1].field);
      UNRECOVERED_JUMPTABLE = g_engfuncs.pfnDeltaUnsetFieldByIndex;
      goto LAB_000b68a2;
    }
  }
  else {
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[0].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[1].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[2].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[3].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[4].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[5].field);
    if (*(int *)(to + 0x58) == 0xc) goto LAB_000b6950;
LAB_000b685a:
    iVar2 = *(int *)(to + 0x94);
  }
  if (*(int *)(from + 0x94) == iVar2) {
    return;
  }
  (*g_engfuncs.pfnDeltaSetFieldByIndex)(pFields,entity_field_alias[0].field);
  (*g_engfuncs.pfnDeltaSetFieldByIndex)(pFields,entity_field_alias[1].field);
  UNRECOVERED_JUMPTABLE = g_engfuncs.pfnDeltaSetFieldByIndex;
LAB_000b68a2:
                    /* WARNING: Could not recover jumptable at 0x000b68b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pFields,entity_field_alias[2].field);
  return;
}


// Player_FieldInit  @ 000bb540  (line 2190)

void Player_FieldInit(delta_s *pFields)

{
  player_field_alias[0].field = (*g_engfuncs.pfnDeltaFindField)(pFields,player_field_alias[0].name);
  player_field_alias[1].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c5084);
  player_field_alias[2].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c50a8);
  return;
}


// Player_Encode  @ 000b6640  (line 2204)

void Player_Encode(delta_s *pFields,uchar *from,uchar *to)

{
  int iVar1;
  _func_void_delta_s_ptr_int *UNRECOVERED_JUMPTABLE;
  int iVar2;
  
                    /* Unresolved local var: entity_state_t * f@[???]
                       Unresolved local var: entity_state_t * t@[???]
                       Unresolved local var: int localplayer@[???] */
  if (Player_Encode::lexical_block_0::initialized == 0) {
    player_field_alias[0].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,player_field_alias[0].name);
    player_field_alias[1].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,player_field_alias[1].name);
    player_field_alias[2].field =
         (*g_engfuncs.pfnDeltaFindField)(pFields,player_field_alias[2].name);
    Player_Encode::lexical_block_0::initialized = 1;
    iVar2 = *(int *)(to + 4);
    iVar1 = (*g_engfuncs.pfnGetCurrentPlayer)();
    if (iVar2 + -1 != iVar1) goto LAB_000b667e;
LAB_000b6761:
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[0].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[1].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[2].field);
    if (*(int *)(to + 0x58) != 0xc) goto LAB_000b6688;
LAB_000b67b0:
    iVar2 = 0;
    if (*(int *)(to + 0x94) != 0) {
      (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[0].field);
      (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,entity_field_alias[1].field);
      UNRECOVERED_JUMPTABLE = g_engfuncs.pfnDeltaUnsetFieldByIndex;
      goto LAB_000b66cc;
    }
  }
  else {
    iVar2 = *(int *)(to + 4);
    iVar1 = (*g_engfuncs.pfnGetCurrentPlayer)();
    if (iVar2 + -1 == iVar1) goto LAB_000b6761;
LAB_000b667e:
    if (*(int *)(to + 0x58) == 0xc) goto LAB_000b67b0;
LAB_000b6688:
    iVar2 = *(int *)(to + 0x94);
  }
  if (*(int *)(from + 0x94) == iVar2) {
    return;
  }
  (*g_engfuncs.pfnDeltaSetFieldByIndex)(pFields,entity_field_alias[0].field);
  (*g_engfuncs.pfnDeltaSetFieldByIndex)(pFields,entity_field_alias[1].field);
  UNRECOVERED_JUMPTABLE = g_engfuncs.pfnDeltaSetFieldByIndex;
LAB_000b66cc:
                    /* WARNING: Could not recover jumptable at 0x000b66df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(pFields,entity_field_alias[2].field);
  return;
}


// Custom_Entity_FieldInit  @ 000bb5a0  (line 2266)

void Custom_Entity_FieldInit(delta_s *pFields)

{
  custom_entity_field_alias[0].field =
       (*g_engfuncs.pfnDeltaFindField)(pFields,custom_entity_field_alias[0].name);
  custom_entity_field_alias[1].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c4d84);
  custom_entity_field_alias[2].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c4da8);
  custom_entity_field_alias[3].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c4dcc);
  custom_entity_field_alias[4].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c4df0);
  custom_entity_field_alias[5].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c4e14);
  custom_entity_field_alias[6].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c4e38);
  custom_entity_field_alias[7].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c4e5c);
  custom_entity_field_alias[8].field = (*g_engfuncs.pfnDeltaFindField)(pFields,(char *)0x1c4e80);
  return;
}


// Custom_Encode  @ 000bb680  (line 2287)

void Custom_Encode(delta_s *pFields,uchar *from,uchar *to)

{
  uint uVar1;
  
                    /* Unresolved local var: entity_state_t * f@[???]
                       Unresolved local var: entity_state_t * t@[???]
                       Unresolved local var: int beamType@[???] */
  if (Custom_Encode::lexical_block_0::initialized == 0) {
    Custom_Entity_FieldInit(pFields);
    Custom_Encode::lexical_block_0::initialized = 1;
  }
  uVar1 = *(uint *)(to + 0x48) & 0xf;
  if (uVar1 < 2) {
    if (uVar1 == 0) goto LAB_000bb727;
  }
  else {
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[0].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[1].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[2].field);
  }
  (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[3].field);
  (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[4].field);
  (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[5].field);
LAB_000bb727:
  if (1 < uVar1 - 1) {
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[6].field);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[7].field);
  }
  if ((int)*(float *)(from + 0x5c) == (int)*(float *)(to + 0x5c)) {
                    /* WARNING: Could not recover jumptable at 0x000bb7c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(pFields,custom_entity_field_alias[8].field);
    return;
  }
  return;
}


// RegisterEncoders  @ 000bb7d0  (line 2339)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void RegisterEncoders(void)

{
  (*g_engfuncs.pfnDeltaAddEncoder)("Entity_Encode",Entity_Encode);
  (*g_engfuncs.pfnDeltaAddEncoder)("Custom_Encode",Custom_Encode);
  (*g_engfuncs.pfnDeltaAddEncoder)("Player_Encode",Player_Encode);
  return;
}


// GetWeaponData  @ 000bb820  (line 2353)

int GetWeaponData(edict_s *player,weapon_data_s *info)

{
  float fVar1;
  void *pvVar2;
  int *piVar3;
  int *piVar4;
  edict_t *peVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  weapon_data_s *pwVar9;
  bool bVar10;
  byte bVar11;
  uint local_48 [14];
  
  bVar11 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: weapon_data_t * item@[???]
                       Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pl@[DW_OP_breg4(ESP): +24]
                       Unresolved local var: CBasePlayerWeapon * gun@[???]
                       Unresolved local var: ItemInfo II@[???] */
  peVar5 = (player->v).pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar5 == (edict_t *)0x0) &&
     (peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar5 == (edict_t *)0x0)) {
    bVar10 = ((uint)info & 1) != 0;
    uVar7 = 0xb00;
    if (bVar10) {
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
      info = (weapon_data_s *)((int)info + (uint)bVar11 * -8 + 4);
    }
    if ((uVar7 & 2) != 0) {
      *(undefined2 *)&info->m_iId = 0;
      info = (weapon_data_s *)((int)&info->m_iId + 2);
    }
    if (bVar10) {
      *(undefined1 *)&info->m_iId = 0;
    }
  }
  else {
    pvVar2 = peVar5->pvPrivateData;
    bVar10 = ((uint)info & 1) != 0;
    uVar7 = 0xb00;
    pwVar9 = info;
    if (bVar10) {
      *(undefined1 *)&info->m_iId = 0;
      pwVar9 = (weapon_data_s *)((int)&info->m_iId + 1);
      uVar7 = 0xaff;
    }
    if (((uint)pwVar9 & 2) != 0) {
      *(undefined2 *)&pwVar9->m_iId = 0;
      uVar7 = uVar7 - 2;
      pwVar9 = (weapon_data_s *)((int)&pwVar9->m_iId + 2);
    }
    if (((uint)pwVar9 & 4) != 0) {
      pwVar9->m_iId = 0;
      uVar7 = uVar7 - 4;
      pwVar9 = (weapon_data_s *)&pwVar9->m_iClip;
    }
    for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      pwVar9->m_iId = 0;
      pwVar9 = (weapon_data_s *)((int)pwVar9 + (uint)bVar11 * -8 + 4);
    }
    if ((uVar7 & 2) != 0) {
      *(undefined2 *)&pwVar9->m_iId = 0;
      pwVar9 = (weapon_data_s *)((int)&pwVar9->m_iId + 2);
    }
    if (bVar10) {
      *(undefined1 *)&pwVar9->m_iId = 0;
    }
    if (pvVar2 != (void *)0x0) {
                    /* Unresolved local var: CBasePlayerItem * pPlayerItem@[???] */
      iVar8 = 0;
      do {
        for (piVar3 = *(int **)((int)pvVar2 + iVar8 * 4 + 0x8e4); piVar3 != (int *)0x0;
            piVar3 = (int *)piVar3[0x125]) {
          piVar4 = (int *)(**(code **)(*piVar3 + 0x14c))(piVar3);
          if (piVar4 != (int *)0x0) {
            uVar7 = 0;
            do {
              uVar6 = uVar7;
              *(undefined4 *)((int)local_48 + uVar6) = 0;
              *(undefined4 *)((int)local_48 + uVar6 + 4) = 0;
              *(undefined4 *)((int)local_48 + uVar6 + 8) = 0;
              *(undefined4 *)((int)local_48 + uVar6 + 0xc) = 0;
              uVar7 = uVar6 + 0x10;
            } while (uVar7 < 0x20);
            *(undefined4 *)((int)local_48 + uVar7) = 0;
            *(undefined4 *)((int)local_48 + uVar6 + 0x14) = 0;
            *(undefined4 *)((int)local_48 + uVar6 + 0x18) = 0;
            (**(code **)(*piVar4 + 0x114))(piVar4,local_48);
            if (local_48[8] < 0x20) {
              pwVar9 = info + local_48[8];
              pwVar9->m_iId = local_48[8];
              pwVar9->m_iClip = piVar4[0x137];
              fVar1 = (float)piVar4[0x12d];
              if (fVar1 <= -0.001) {
                fVar1 = -0.001;
              }
              pwVar9->m_flPumpTime = fVar1;
              fVar1 = (float)piVar4[299];
              if (fVar1 <= -0.001) {
                fVar1 = -0.001;
              }
              pwVar9->m_flTimeWeaponIdle = fVar1;
              fVar1 = (float)piVar4[0x129];
              if (fVar1 <= -0.001) {
                fVar1 = -0.001;
              }
              pwVar9->m_flNextPrimaryAttack = fVar1;
              fVar1 = (float)piVar4[0x12a];
              if (fVar1 <= -0.001) {
                fVar1 = -0.001;
              }
              pwVar9->m_flNextSecondaryAttack = fVar1;
              fVar1 = -0.001;
              if (-0.001 < (float)piVar4[300]) {
                fVar1 = (float)piVar4[300];
              }
              pwVar9->m_flNextReload = fVar1;
              fVar1 = (float)piVar4[0x130];
              if ((float)piVar4[0x130] <= -1.0) {
                fVar1 = -1.0;
              }
              pwVar9->m_fNextAimBonus = fVar1;
              pwVar9->m_fInReload = piVar4[0x133];
              pwVar9->m_fInSpecialReload = piVar4[0x134];
              pwVar9->m_fReloadTime = (float)piVar4[0x12e];
              pwVar9->m_fAimedDamage = (float)piVar4[0x12f];
              pwVar9->m_fInZoom = piVar4[0x131];
              pwVar9->m_iWeaponState = piVar4[0x132];
            }
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 != 6);
    }
  }
  return 1;
}


// UpdateClientData  @ 000bbae0  (line 2426)

void UpdateClientData(edict_s *ent,int sendweapons,clientdata_s *cd)

{
  entvars_t *peVar1;
  int iVar2;
  char *__src;
  int *piVar3;
  CBaseEntity *pCVar4;
  edict_t *peVar5;
  bool bVar6;
  uint uVar7;
  uint uVar8;
  entvars_t *peVar9;
  entvars_t *peVar10;
  void *pvVar11;
  int local_48 [14];
  
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pl@[???]
                       Unresolved local var: entvars_t * pevOrg@[???] */
  peVar5 = (ent->v).pContainingEntity;
  peVar1 = &ent->v;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar5 == (edict_t *)0x0) {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar5 != (edict_t *)0x0) goto LAB_000bbb07;
    pvVar11 = (void *)0x0;
  }
  else {
LAB_000bbb07:
    pvVar11 = peVar5->pvPrivateData;
  }
  if (*(int *)(*(int *)((int)pvVar11 + 4) + 0x244) == 4) {
    iVar2 = EHANDLE::operator_int((EHANDLE *)((int)pvVar11 + 0x6bc));
    if (iVar2 != 0) {
      pCVar4 = EHANDLE::operator->((EHANDLE *)((int)pvVar11 + 0x6bc));
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
      peVar10 = pCVar4->pev;
      peVar5 = peVar10->pContainingEntity;
      peVar9 = peVar1;
      if (peVar5 == (edict_t *)0x0) {
        peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
        if (peVar5 == (edict_t *)0x0) {
          bVar6 = false;
          pvVar11 = (void *)0x0;
          goto LAB_000bbb28;
        }
      }
      pvVar11 = peVar5->pvPrivateData;
      bVar6 = sendweapons != 0 && pvVar11 != (void *)0x0;
      goto LAB_000bbb28;
    }
  }
  bVar6 = pvVar11 != (void *)0x0 && sendweapons != 0;
  peVar9 = (entvars_t *)0x0;
  peVar10 = peVar1;
LAB_000bbb28:
  cd->flags = peVar10->flags;
  cd->health = peVar10->health;
  iVar2 = (*g_engfuncs.pfnModelIndex)(gpGlobals->pStringBase + peVar10->viewmodel);
  cd->viewmodel = iVar2;
  cd->waterlevel = peVar10->waterlevel;
  cd->watertype = peVar10->watertype;
  cd->weapons = peVar10->weapons;
  (cd->origin).x = (peVar10->origin).x;
  (cd->origin).y = (peVar10->origin).y;
  (cd->origin).z = (peVar10->origin).z;
  (cd->velocity).x = (peVar10->velocity).x;
  (cd->velocity).y = (peVar10->velocity).y;
  (cd->velocity).z = (peVar10->velocity).z;
  (cd->view_ofs).x = (peVar10->view_ofs).x;
  (cd->view_ofs).y = (peVar10->view_ofs).y;
  (cd->view_ofs).z = (peVar10->view_ofs).z;
  (cd->punchangle).x = (peVar10->punchangle).x;
  (cd->punchangle).y = (peVar10->punchangle).y;
  (cd->punchangle).z = (peVar10->punchangle).z;
  cd->bInDuck = peVar10->bInDuck;
  cd->flTimeStepSound = peVar10->flTimeStepSound;
  cd->flDuckTime = peVar10->flDuckTime;
  cd->flSwimTime = peVar10->flSwimTime;
  cd->waterjumptime = (int)peVar10->teleport_time;
  __src = (*g_engfuncs.pfnGetPhysicsInfoString)(ent);
  strcpy(cd->physinfo,__src);
  cd->maxspeed = peVar10->maxspeed;
  cd->fov = peVar10->fov;
  cd->weaponanim = peVar10->weaponanim;
  cd->pushmsec = peVar10->pushmsec;
  if (peVar9 == (entvars_t *)0x0) {
    cd->iuser1 = peVar10->iuser1;
    cd->iuser2 = peVar10->iuser2;
    cd->iuser3 = peVar10->iuser3;
    cd->iuser4 = peVar10->iuser4;
  }
  else {
    cd->iuser1 = peVar9->iuser1;
    cd->iuser2 = peVar9->iuser2;
    cd->iuser3 = peVar9->iuser2;
  }
  cd->deadflag = peVar10->deadflag;
  if (bVar6) {
    cd->ammo_shells = *(int *)((int)pvVar11 + 0xe4);
    cd->ammo_nails = *(int *)((int)pvVar11 + 0xec);
    cd->ammo_cells = *(int *)((int)pvVar11 + 0xf4);
    cd->ammo_rockets = *(int *)((int)pvVar11 + 0xfc);
    cd->m_flNextAttack = *(float *)((int)pvVar11 + 0x674);
    piVar3 = *(int **)((int)pvVar11 + 0x8fc);
    if (piVar3 != (int *)0x0) {
                    /* Unresolved local var: CBasePlayerWeapon * gun@[???] */
      piVar3 = (int *)(**(code **)(*piVar3 + 0x14c))(piVar3);
      if (piVar3 != (int *)0x0) {
                    /* Unresolved local var: ItemInfo II@[???] */
        uVar8 = 0;
        do {
          uVar7 = uVar8;
          *(undefined4 *)((int)local_48 + uVar7) = 0;
          *(undefined4 *)((int)local_48 + uVar7 + 4) = 0;
          *(undefined4 *)((int)local_48 + uVar7 + 8) = 0;
          *(undefined4 *)((int)local_48 + uVar7 + 0xc) = 0;
          uVar8 = uVar7 + 0x10;
        } while (uVar8 < 0x20);
        *(undefined4 *)((int)local_48 + uVar8) = 0;
        *(undefined4 *)((int)local_48 + uVar7 + 0x14) = 0;
        *(undefined4 *)((int)local_48 + uVar7 + 0x18) = 0;
        (**(code **)(*piVar3 + 0x114))(piVar3,local_48);
        cd->m_iId = local_48[8];
      }
    }
  }
  return;
}


// CmdStart  @ 000bbe10  (line 2525)

void CmdStart(edict_t *player,usercmd_s *cmd,uint random_seed)

{
  void *pvVar1;
  int groupmask;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pl@[DW_OP_reg3(EBX)] */
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


// CmdEnd  @ 000bbe80  (line 2548)

void CmdEnd(edict_t *player)

{
  void *pvVar1;
  int iVar2;
  edict_t *peVar3;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: entvars_t * pev@[???]
                       Unresolved local var: CBasePlayer * pl@[DW_OP_reg3(EBX)] */
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


// ConnectionlessPacket  @ 000bbf50  (line 2579)

int ConnectionlessPacket
              (netadr_s *net_from,char *args,char *response_buffer,int *response_buffer_size)

{
                    /* Unresolved local var: int max_buffer_size@[???] */
  *response_buffer_size = 0;
  return 0;
}


// GetHullBounds  @ 000bbf60  (line 2616)

int GetHullBounds(int hullnumber,float *mins,float *maxs)

{
                    /* Unresolved local var: int iret@[???] */
  return (uint)((uint)hullnumber < 3);
}


// CreateInstancedBaselines  @ 000bbf70  (line 2633)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CreateInstancedBaselines(void)

{
  uint uVar1;
  uint uVar2;
  edict_t *peVar3;
  CBaseEntity *pEntity;
  CTFCaltrop *this;
  entvars_t *peVar4;
  int playermodelindex;
  entvars_t *playermodelindex_00;
  Vector in_stack_fffffe4c;
  Vector in_stack_fffffe58;
  vec_t avStack_19c [87];
  float local_40;
  float local_3c;
  link_s *local_38;
  link_s *local_34;
  int local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  link_s *local_20;
  
                    /* Unresolved local var: int iret@[???]
                       Unresolved local var: entity_state_t state@[???]
                       Unresolved local var: Vector fake@[???]
                       Unresolved local var: CTFCaltrop * pc@[DW_OP_reg7(EDI)]
                       Unresolved local var: CWeaponBox * wb@[DW_OP_reg3(EBX)] */
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)((int)&((entvars_t *)&stack0xfffffe60)->classname + uVar2) = 0;
    *(undefined4 *)((int)avStack_19c + uVar2) = 0;
    *(undefined4 *)((int)avStack_19c + uVar2 + 4) = 0;
    *(undefined4 *)((int)avStack_19c + uVar2 + 8) = 0;
    uVar1 = uVar2 + 0x10;
  } while (uVar2 + 0x10 < 0x150);
  *(undefined4 *)((int)&((Vector *)&(((entvars_t *)&stack0xfffffe60)->origin).z)->x + uVar2) = 0;
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar4 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar4 = &peVar3->v;
  }
  if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
     (this = peVar4->pContainingEntity->pvPrivateData, this == (CTFCaltrop *)0x0)) {
    this = CBaseEntity::operator_new(0x478,peVar4);
    (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFCaltrop_001903c8;
    (this->super_CBaseEntity).pev = peVar4;
  }
                    /* Unresolved local var: entvars_t * pev@[???] */
  playermodelindex = 0;
  CTFCaltrop::ScatterDrop(this,(CBaseEntity *)0x0);
  local_3c = 0.0;
  local_38 = (link_s *)0x0;
  avStack_19c[0x55] = 0.0;
  avStack_19c[0x56] = 0.0;
  local_40 = 0.0;
  avStack_19c[0x54] = 0.0;
  CreateBaseline((int)&stack0xfffffe60,(int)((this->super_CBaseEntity).pev)->pContainingEntity,
                 (entity_state_s *)(avStack_19c + 0x54),(edict_s *)&local_40,playermodelindex,
                 in_stack_fffffe4c,in_stack_fffffe58);
  playermodelindex_00 = (entvars_t *)&stack0xfffffe60;
  (*g_engfuncs.pfnCreateInstancedBaseline)
            (((this->super_CBaseEntity).pev)->classname,(entity_state_s *)&stack0xfffffe60);
  peVar3 = (*g_engfuncs.pfnCreateEntity)();
  peVar4 = (entvars_t *)0x0;
  if (peVar3 != (edict_t *)0x0) {
    peVar4 = &peVar3->v;
  }
  if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
     (pEntity = peVar4->pContainingEntity->pvPrivateData, pEntity == (CBaseEntity *)0x0)) {
    playermodelindex_00 = peVar4;
    pEntity = CBaseEntity::operator_new(0x598,peVar4);
    pEntity->_vptr_CBaseEntity = (_func_int_varargs **)&PTR__CWeaponBox_001986c8;
    pEntity->pev = peVar4;
  }
  else {
    peVar4 = pEntity->pev;
  }
  peVar4->classname = (int)"weaponbox" - (int)gpGlobals->pStringBase;
  (*pEntity->_vptr_CBaseEntity[2])(pEntity);
  local_24 = 0.0;
  local_20 = (link_s *)0x0;
  local_30 = 0;
  local_2c = 0.0;
  local_28 = 0.0;
  local_34 = (link_s *)0x0;
  CreateBaseline((int)&stack0xfffffe60,(int)pEntity->pev->pContainingEntity,
                 (entity_state_s *)&local_34,(edict_s *)&local_28,(int)playermodelindex_00,
                 in_stack_fffffe4c,in_stack_fffffe58);
  (*g_engfuncs.pfnCreateInstancedBaseline)
            (pEntity->pev->classname,(entity_state_s *)&stack0xfffffe60);
  UTIL_Remove(&this->super_CBaseEntity);
  UTIL_Remove(pEntity);
  return;
}


// InconsistentFile  @ 000bc180  (line 2676)

int InconsistentFile(edict_t *player,char *filename,char *disconnect_message)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*g_engfuncs.pfnCVarGetFloat)("mp_consistency");
  if (lVar1 != (longdouble)1) {
    return 0;
  }
  sprintf(disconnect_message,"Server is enforcing file consistency for %s\n",filename);
  return 1;
}


// AllowLagCompensation  @ 000bc1d0  (line 2702)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int AllowLagCompensation(void)

{
  return 1;
}


// ShouldCollide  @ 000bc1e0  (line 2716)

int ShouldCollide(edict_t *pentTouched,edict_t *pentOther)

{
  return 1;
}


