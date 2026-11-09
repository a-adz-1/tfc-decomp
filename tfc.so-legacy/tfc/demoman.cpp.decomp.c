// Ghidra decompilation of functions from tfc/demoman.cpp
// 11 functions, ordered by original source line

// detpack  @ 000c3520  (line 21)

/* WARNING: Type propagation algorithm not settling */

void detpack(entvars_t *pev)

{
  CGrenade *this;
  edict_t *peVar1;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar1 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar1 != (edict_t *)0x0) {
      pev = &peVar1->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  this = CBaseEntity::operator_new(0x6e4,pev);
  CGrenade::CGrenade(this);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CDetpack_0017bbe8;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CDetpack::Spawn  @ 000c33b0  (line 24)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CDetpack * this) */

void __thiscall CDetpack::Spawn(CDetpack *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  Vector local_24;
  Vector local_18;
  
  (**(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity + 0xc))(this);
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  this->bAlternateLight = 0;
  this->bTicked = 0;
  peVar1->movetype = 6;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->solid = 2;
  this->m_pBlinkSprite = (CSprite *)0x0;
  if (birthday == 0) {
    (*g_engfuncs.pfnSetModel)
              (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/detpack.mdl");
  }
  else {
    (*g_engfuncs.pfnSetModel)
              (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,"models/presentlg.mdl");
  }
  pgVar2 = gpGlobals;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = DetpackTouch;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = DetpackThink;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  local_18.x = 4.0;
  local_18.y = 4.0;
  local_18.z = 4.0;
  local_24.x = -4.0;
  peVar1->nextthink = pgVar2->time + 0.1;
  local_24.y = -4.0;
  local_24.z = -4.0;
  UTIL_SetSize((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  peVar1 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar1,&peVar1->origin);
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.weaponmode = 0.0;
  EMIT_SOUND_DYN(((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,
                 "weapons/mine_activate.wav",1.0,0.8,0,100);
  return;
}


// CDetpack::DetpackTouch  @ 000c3140  (line 53)

/* DWARF original prototype: void DetpackTouch(CDetpack * this, CBaseEntity * pOther) */

void __thiscall CDetpack::DetpackTouch(CDetpack *this,CBaseEntity *pOther)

{
  char *pcVar1;
  string_t sVar2;
  int iVar3;
  BOOL BVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  edict_t *peVar8;
  char *pcVar9;
  CBaseEntity *this_00;
  char *local_28;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg7(EDI)] */
  peVar8 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar8 == (edict_t *)0x0) {
    peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar8 == (edict_t *)0x0) {
      this_00 = (CBaseEntity *)0x0;
      goto LAB_000c316f;
    }
  }
  this_00 = peVar8->pvPrivateData;
LAB_000c316f:
  iVar3 = (*pOther->_vptr_CBaseEntity[10])(pOther);
  if ((iVar3 == 2) && (pOther->pev->playerclass == 1)) {
    iVar3 = (*pOther->_vptr_CBaseEntity[0x22])(pOther);
    if (iVar3 != 0) {
      BVar4 = CBaseEntity::IsAlly(this_00,pOther);
      if (BVar4 == 0) {
        pcVar1 = gpGlobals->pStringBase;
        if (birthday == 1) {
          UTIL_ClientPrintAll(1,"#Detpack_disarm_bday",pcVar1 + pOther->pev->netname,
                              pcVar1 + this_00->pev->netname,(char *)0x0,(char *)0x0);
        }
        else {
          UTIL_ClientPrintAll(1,"#Detpack_disarm",pcVar1 + this_00->pev->netname,
                              pcVar1 + pOther->pev->netname,(char *)0x0,(char *)0x0);
        }
        local_28 = "SPECTATOR";
        if (this_00->team_no != 0) {
          local_28 = GetTeamName(this_00->team_no);
        }
        pcVar5 = (*g_engfuncs.pfnGetPlayerAuthId)(this_00->pev->pContainingEntity);
        iVar3 = (*g_engfuncs.pfnGetPlayerUserId)(this_00->pev->pContainingEntity);
        pcVar1 = gpGlobals->pStringBase;
        sVar2 = this_00->pev->netname;
        pcVar9 = "SPECTATOR";
        if (pOther->team_no != 0) {
          pcVar9 = GetTeamName(pOther->team_no);
        }
        pcVar6 = (*g_engfuncs.pfnGetPlayerAuthId)(pOther->pev->pContainingEntity);
        iVar7 = (*g_engfuncs.pfnGetPlayerUserId)(pOther->pev->pContainingEntity);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Detpack_Disarmed\" against \"%s<%i><%s><%s>\"\n"
                       ,gpGlobals->pStringBase + pOther->pev->netname,iVar7,pcVar6,pcVar9,
                       pcVar1 + sVar2,iVar3,pcVar5,local_28);
        CBasePlayer::TF_AddFrags((CBasePlayer *)pOther,1);
        dremove((CBaseEntity *)this);
        return;
      }
    }
  }
  return;
}


// CDetpack::TeamFortress_TakeEMPBlast  @ 000c30a0  (line 125)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CDetpack * this, entvars_t * pevGren) */

void __thiscall CDetpack::TeamFortress_TakeEMPBlast(CDetpack *this,entvars_t *pevGren)

{
  float fVar1;
  entvars_t *peVar2;
  longdouble lVar3;
  
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  fVar1 = gpGlobals->time;
  lVar3 = (longdouble)(*g_engfuncs.pfnRandomFloat)(0.0,2.0);
  peVar2->health = (float)((longdouble)(fVar1 + 1.0) + lVar3);
  return;
}


// CDetpack::DetpackThink  @ 000c3e00  (line 130)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DetpackThink(CDetpack * this) */

void __thiscall CDetpack::DetpackThink(CDetpack *this)

{
  float fVar1;
  char *param1;
  edict_t *peVar2;
  CSprite *pCVar3;
  entvars_t *peVar4;
  int d;
  void *pvVar5;
  Vector local_18;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg7(EDI)]
                       Unresolved local var: int iSecondsLeft@[???] */
  fVar1 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev)->health;
  if ((fVar1 != 0.0) && (fVar1 <= gpGlobals->time + 0.9)) {
    DetpackExplode(this);
    return;
  }
  CBaseEntity::CheckBelowBuilding((CBaseEntity *)this,8);
  peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  peVar2 = peVar4->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar2 == (edict_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar2 == (edict_t *)0x0) {
      pvVar5 = (void *)0x0;
      goto LAB_000c3e66;
    }
  }
  pvVar5 = peVar2->pvPrivateData;
LAB_000c3e66:
  d = (int)(peVar4->health - gpGlobals->time);
  peVar4->nextthink = gpGlobals->time + 1.0;
  if (d < 0xb) {
    param1 = UTIL_dtos1(d);
    ClientPrint(*(entvars_t **)((int)pvVar5 + 4),1,"#Detpack_countdown",param1,(char *)0x0,
                (char *)0x0,(char *)0x0);
    if (d < 6) {
      if (this->bTicked == 0) {
        EMIT_SOUND_DYN(((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->
                       pContainingEntity,1,"weapons/mine_charge.wav",1.0,0.8,0,100);
        this->bTicked = 1;
        peVar4 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev;
        local_18.z = (peVar4->origin).z + 64.0;
        local_18.y = (peVar4->origin).y + 0.0;
        local_18.x = (peVar4->origin).x + 0.0;
        pCVar3 = CSprite::SpriteCreate("sprites/flare3.spr",&local_18,0);
        this->m_pBlinkSprite = pCVar3;
        ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 3;
        (((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = 255.0;
        (((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = 0.0;
        (((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = 0.0;
        ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 0.0;
        ((pCVar3->super_CPointEntity).super_CBaseEntity.pev)->renderfx = 0xe;
      }
      else if (d != 5) {
        if (this->bAlternateLight != 0) {
          this->bAlternateLight = 0;
          ((this->m_pBlinkSprite->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 0.0;
          return;
        }
        this->bAlternateLight = 1;
        ((this->m_pBlinkSprite->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 64.0;
      }
    }
  }
  return;
}


// CDetpack::Precache  @ 000c30e0  (line 176)

/* DWARF original prototype: void Precache(CDetpack * this) */

void __thiscall CDetpack::Precache(CDetpack *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/presentlg.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/detpack.mdl");
  (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
  (*g_engfuncs.pfnPrecacheSound)("weapons/mortarhit.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/mine_activate.wav");
                    /* WARNING: Could not recover jumptable at 0x000c3135. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/mine_charge.wav");
  return;
}


// CDetpack::Remove  @ 000c35a0  (line 188)

/* DWARF original prototype: void Remove(CDetpack * this) */

void __thiscall CDetpack::Remove(CDetpack *this)

{
  char *pcVar1;
  int iVar2;
  edict_t *peVar3;
  void *pvVar4;
  char *pcVar5;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_reg6(ESI)] */
  peVar3 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar3 == (edict_t *)0x0) {
      pvVar4 = (void *)0x0;
      goto LAB_000c35bf;
    }
  }
  pvVar4 = peVar3->pvPrivateData;
LAB_000c35bf:
  *(int *)((int)pvVar4 + 0xdc) = *(int *)((int)pvVar4 + 0xdc) + 1;
  pcVar5 = "SPECTATOR";
  ClientPrint(*(entvars_t **)((int)pvVar4 + 4),4,"#Detpack_blocking_door_destroyed",(char *)0x0,
              (char *)0x0,(char *)0x0,(char *)0x0);
  if (*(int *)((int)pvVar4 + 0x138) != 0) {
    pcVar5 = GetTeamName(*(int *)((int)pvVar4 + 0x138));
  }
  pcVar1 = (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)((int)pvVar4 + 4) + 0x208));
  iVar2 = (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)((int)pvVar4 + 4) + 0x208));
  UTIL_LogPrintf("\"<-1><><>\" triggered \"Detpack_blocking_door_destroyed\" against \"%s<%i><%s><%s>\"\n"
                 ,gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar4 + 4) + 0x1d0),iVar2,pcVar1,
                 pcVar5);
  if (this->m_pBlinkSprite != (CSprite *)0x0) {
    dremove((CBaseEntity *)this->m_pBlinkSprite);
  }
  (*g_engfuncs.pfnMessageBegin)
            (5,0x17,&(((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev)->origin).x,
             (edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->origin).x);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->origin).y);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev)->origin).z);
  (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexSmoke);
  (*g_engfuncs.pfnWriteByte)(0x1e);
  (*g_engfuncs.pfnWriteByte)(0xf);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnMessageEnd)();
  dremove((CBaseEntity *)this);
  return;
}


// CDetpack::DetpackExplode  @ 000c3760  (line 224)

/* DWARF original prototype: void DetpackExplode(CDetpack * this) */

void __thiscall CDetpack::DetpackExplode(CDetpack *this)

{
  float fVar1;
  float fVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  entvars_t *peVar5;
  float *pfVar6;
  int iVar7;
  edict_t *peVar8;
  entvars_t *peVar9;
  CBaseEntity *pCVar10;
  void *pvVar11;
  float *pfVar12;
  char *pcVar13;
  char *pcVar14;
  bool bVar15;
  byte bVar16;
  float fVar17;
  float afStackY_b4 [2];
  float local_84;
  void *local_80;
  float local_70 [8];
  float local_50 [6];
  float local_38 [10];
  
  bVar16 = 0;
  pfVar12 = (float *)&stack0xffffff54;
                    /* Unresolved local var: CBasePlayer * pOwner@[DW_OP_breg4(ESP): +44]
                       Unresolved local var: int iPos@[???] */
  peVar9 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  peVar8 = peVar9->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar8 == (edict_t *)0x0) {
    peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar9 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar8 != (edict_t *)0x0) goto LAB_000c3782;
    local_80 = (void *)0x0;
  }
  else {
LAB_000c3782:
    local_80 = peVar8->pvPrivateData;
  }
  iVar7 = UTIL_PointContents(&peVar9->origin);
  if (((iVar7 == -6) || (iVar7 == -2)) || (*(int *)((int)local_80 + 0x7c) == 1)) {
    ClientPrint(*(entvars_t **)((int)local_80 + 4),1,"#Detpack_fizzle",(char *)0x0,(char *)0x0,
                (char *)0x0,(char *)0x0);
    if (*(int *)((int)local_80 + 0x138) != 0) {
      GetTeamName(*(int *)((int)local_80 + 0x138));
    }
    (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)((int)local_80 + 4) + 0x208));
    (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)((int)local_80 + 4) + 0x208));
    UTIL_LogPrintf("\"<-1><><>\" triggered \"Detpack_Fizzle\" against \"%s<%i><%s><%s>\"\n");
  }
  else {
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: CBaseEntity * pEntity@[???] */
    UTIL_ClientPrintAll(1,"#FITH",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    EMIT_SOUND_DYN(((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating
                    .super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,
                   "weapons/mortarhit.wav",1.0,0.8,0,100);
    if (birthday != 0) {
      UTIL_ClientPrintAll(1,"#SpreadsCheer",
                          gpGlobals->pStringBase + *(int *)(*(int *)((int)local_80 + 4) + 0x1d0),
                          (char *)0x0,(char *)0x0,(char *)0x0);
    }
    if (*(int *)((int)local_80 + 0x138) != 0) {
      GetTeamName(*(int *)((int)local_80 + 0x138));
    }
    (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)((int)local_80 + 4) + 0x208));
    (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)((int)local_80 + 4) + 0x208));
    pCVar10 = (CBaseEntity *)0x0;
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Detpack_Explode\"\n");
    pfVar6 = (float *)&stack0xffffff54;
LAB_000c38e0:
    pfVar12 = pfVar6;
    *pfVar12 = (float)pCVar10;
    pfVar12[2] = 1500.0;
    pfVar12[1] = (float)(pfVar12 + 0x1b);
    pfVar12[-1] = 1.122462e-39;
    pCVar10 = UTIL_FindEntityInSphere((CBaseEntity *)*pfVar12,(Vector *)pfVar12[1],pfVar12[2]);
    if (pCVar10 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSpot@[???] */
      pp_Var3 = pCVar10->_vptr_CBaseEntity;
      peVar9 = pCVar10->pev;
      *pfVar12 = (float)(pfVar12 + 0x21);
      pfVar12[1] = (float)pCVar10;
      p_Var4 = pp_Var3[0x32];
      pfVar12[-1] = 1.122512e-39;
      (*p_Var4)();
      fVar1 = (peVar9->view_ofs).z;
      fVar17 = (peVar9->view_ofs).y;
      fVar2 = (peVar9->view_ofs).x;
      pfVar12[3] = (float)(pfVar12 + 0xb);
      peVar8 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity;
      pfVar12[0x1d] = pfVar12[0x20] + fVar2;
      pfVar12[0x1e] = pfVar12[0x21] + fVar17;
      pfVar12[0x1f] = pfVar12[0x22] + fVar1;
      pfVar12[1] = 0.0;
      pfVar12[2] = (float)peVar8;
      *pfVar12 = (float)(pfVar12 + 0x1d);
      pfVar12[-1] = (float)(pfVar12 + 0x1a);
      pfVar12[-2] = 1.122657e-39;
      UTIL_TraceLine((Vector *)pfVar12[-1],(Vector *)*pfVar12,(IGNORE_MONSTERS)pfVar12[1],
                     (edict_t *)pfVar12[2],(TraceResult *)pfVar12[3]);
      peVar9 = pCVar10->pev;
      if ((1.0 <= pfVar12[0xf]) ||
         (pfVar6 = pfVar12 + -1, (edict_t *)pfVar12[0x17] == peVar9->pContainingEntity)) {
        iVar7 = 0xc;
        bVar15 = gpGlobals->pStringBase + peVar9->classname == (char *)0x0;
        pcVar13 = gpGlobals->pStringBase + peVar9->classname;
        pcVar14 = "info_tfgoal";
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar15 = *pcVar13 == *pcVar14;
          pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
        } while (bVar15);
        if (bVar15) {
          pfVar6 = pfVar12 + -1;
          if (((pCVar10->goal_activation & 2) != 0) &&
             (pfVar6 = pfVar12 + -1, pCVar10->search_time == 0.0)) {
            pfVar12[1] = (float)pCVar10;
            pfVar12[-1] = (float)pCVar10;
            *pfVar12 = pfVar12[10];
            pfVar12[-2] = 1.12285e-39;
            ActivateDoResults((CBaseEntity *)pfVar12[-1],(CBasePlayer *)*pfVar12,
                              (CBaseEntity *)pfVar12[1]);
            pfVar6 = pfVar12 + -1;
          }
        }
        else {
          pfVar6 = pfVar12 + -1;
          if (peVar9->takedamage != 0.0) {
            peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
            fVar1 = (peVar9->origin).z - (peVar5->origin).z;
            fVar2 = (peVar9->origin).y - (peVar5->origin).y;
            fVar17 = (peVar9->origin).x - (peVar5->origin).x;
            fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar17 * fVar17;
            fVar17 = SQRT(fVar1);
            if (NAN(fVar17)) {
              pfVar12[-1] = fVar1;
              pfVar12[-2] = 1.124256e-39;
              fVar17 = sqrtf(pfVar12[-1]);
            }
            pfVar6 = pfVar12 + -1;
            if (fVar17 <= 700.0) {
                    /* Unresolved local var: Vector vecOrg@[???]
                       Unresolved local var: float flPoints@[???] */
              peVar9 = pCVar10->pev;
              peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
              fVar1 = (peVar5->origin).z -
                      (((peVar9->mins).z + (peVar9->maxs).z) * 0.5 + (peVar9->origin).z);
              fVar2 = (peVar5->origin).y -
                      (((peVar9->mins).y + (peVar9->maxs).y) * 0.5 + (peVar9->origin).y);
              fVar17 = (peVar5->origin).x -
                       (((peVar9->mins).x + (peVar9->maxs).x) * 0.5 + (peVar9->origin).x);
              fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar17 * fVar17;
              fVar17 = SQRT(fVar1);
              if (NAN(fVar17)) {
                pfVar12[-1] = fVar1;
                pfVar12[-2] = 1.124235e-39;
                fVar17 = sqrtf(pfVar12[-1]);
              }
              if (0.0 <= fVar17 * 0.5) {
                fVar1 = 700.0 - fVar17 * 0.5;
                pfVar6 = pfVar12 + -1;
                if (fVar1 == 0.0) goto LAB_000c38e0;
              }
              else {
                fVar1 = 700.0;
              }
              pp_Var3 = pCVar10->_vptr_CBaseEntity;
              pfVar12[3] = 8.96831e-44;
              pfVar12[2] = fVar1 + fVar1;
              pfVar12[1] = *(float *)((int)pfVar12[10] + 4);
              peVar9 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
              pfVar12[-1] = (float)pCVar10;
              *pfVar12 = (float)peVar9;
              p_Var4 = pp_Var3[0xd];
              pfVar12[-2] = 1.123659e-39;
              (*p_Var4)();
              pfVar6 = pfVar12 + -1;
            }
          }
        }
      }
      goto LAB_000c38e0;
    }
    pfVar12[3] = 0.0;
    peVar9 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    *pfVar12 = 7.00649e-45;
    pfVar12[2] = (float)&peVar9->origin;
    pfVar12[1] = 3.22299e-44;
    pfVar12[-1] = 1.123726e-39;
    (*g_engfuncs.pfnMessageBegin)
              ((int)*pfVar12,(int)pfVar12[1],(float *)pfVar12[2],(edict_t *)pfVar12[3]);
    *pfVar12 = 4.2039e-45;
    pfVar12[-1] = 1.123745e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar12);
    *pfVar12 = (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev)->origin).x;
    pfVar12[-1] = 1.123766e-39;
    (*g_engfuncs.pfnWriteCoord)(*pfVar12);
    *pfVar12 = (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev)->origin).y;
    pfVar12[-1] = 1.123787e-39;
    (*g_engfuncs.pfnWriteCoord)(*pfVar12);
    *pfVar12 = (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev)->origin).z;
    pfVar12[-1] = 1.123808e-39;
    (*g_engfuncs.pfnWriteCoord)(*pfVar12);
    *pfVar12 = (float)(int)g_sModelIndexFireball;
    pfVar12[-1] = 1.12383e-39;
    (*g_engfuncs.pfnWriteShort)((int)*pfVar12);
    *pfVar12 = 7.00649e-44;
    pfVar12[-1] = 1.123848e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar12);
    *pfVar12 = 2.10195e-44;
    pfVar12[-1] = 1.123867e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar12);
    *pfVar12 = 4.2039e-45;
    pfVar12[-1] = 1.123885e-39;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar12);
    pfVar12[-1] = 1.123893e-39;
    (*g_engfuncs.pfnMessageEnd)();
  }
  if ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.weaponmode != 1.0) goto LAB_000c3ada;
                    /* Unresolved local var: CBasePlayer * pEnemy@[DW_OP_reg3(EBX)]
                       Unresolved local var: CBaseEntity * pTimer@[???] */
  peVar8 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar8 == (edict_t *)0x0) {
    *pfVar12 = 0.0;
    pfVar12[-1] = 1.1242e-39;
    peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)((int)*pfVar12);
    if (peVar8 != (edict_t *)0x0) goto LAB_000c3b11;
    pvVar11 = (void *)0x0;
  }
  else {
LAB_000c3b11:
    pvVar11 = peVar8->pvPrivateData;
  }
  *(uint *)((int)pvVar11 + 0x9c) = *(uint *)((int)pvVar11 + 0x9c) & 0xfffeffff;
  *pfVar12 = (float)pvVar11;
  pfVar12[-1] = 1.123244e-39;
  CBasePlayer::TeamFortress_SetSpeed((CBasePlayer *)*pfVar12);
  pfVar12[1] = 1.4013e-44;
  *pfVar12 = (float)pvVar11;
  pfVar12[-1] = 1.123268e-39;
  pCVar10 = CBaseEntity::FindTimer((CBaseEntity *)*pfVar12,(int)pfVar12[1]);
  if (pCVar10 != (CBaseEntity *)0x0) {
    *pfVar12 = (float)pCVar10;
    pfVar12[-1] = 1.123285e-39;
    dremove((CBaseEntity *)*pfVar12);
  }
LAB_000c3ada:
  if (this->m_pBlinkSprite != (CSprite *)0x0) {
    *pfVar12 = (float)this->m_pBlinkSprite;
    pfVar12[-1] = 1.123163e-39;
    dremove((CBaseEntity *)*pfVar12);
  }
  *pfVar12 = (float)this;
  pfVar12[-1] = 1.123174e-39;
  dremove((CBaseEntity *)*pfVar12);
  return;
}


// CBasePlayer::TeamFortress_SetDetpack  @ 000c40a0  (line 322)

/* DWARF original prototype: void TeamFortress_SetDetpack(CBasePlayer * this, int iTimer) */

void __thiscall CBasePlayer::TeamFortress_SetDetpack(CBasePlayer *this,int iTimer)

{
  int *piVar1;
  float fVar2;
  entvars_t *peVar3;
  globalvars_t *pgVar4;
  char *pcVar5;
  CBaseEntity *pCVar6;
  int iVar7;
  CBasePlayer *pStartEntity;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  
  bVar12 = 0;
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CBaseEntity * pTimer@[???] */
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.weapons_carried & 0x20000) == 0) {
    return;
  }
  pStartEntity = (CBasePlayer *)0x0;
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_detpack < 1) {
    return;
  }
  do {
    pStartEntity = (CBasePlayer *)
                   UTIL_FindEntityInSphere
                             ((CBaseEntity *)pStartEntity,
                              &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.pev)->origin,65.0);
    if (pStartEntity == (CBasePlayer *)0x0) {
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      if ((peVar3->flags & 0x200) == 0) {
        ClientPrint(peVar3,1,"#Detpack_air",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
        return;
      }
      pCVar6 = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"detpack");
      pgVar4 = gpGlobals;
      while (gpGlobals = pgVar4, pCVar6 != (CBaseEntity *)0x0) {
        peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (pCVar6->pev->owner == peVar3->pContainingEntity) {
          ClientPrint(peVar3,1,"#Detpack_oneactive",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0)
          ;
          return;
        }
        pCVar6 = UTIL_FindEntityByClassname(pCVar6,"detpack");
        pgVar4 = gpGlobals;
      }
      if (4 < iTimer) {
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.ammo_detpack;
        *piVar1 = *piVar1 + -1;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.is_detpacking = 1;
        fVar2 = pgVar4->time;
        piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.tfstate;
        *piVar1 = *piVar1 | 0x10000;
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.immune_to_check = fVar2 + 10.0;
        TeamFortress_SetSpeed(this);
        (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
          _vptr_CBaseEntity[0x49])(this->m_pActiveItem,0);
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->weaponmodel = 0;
        pcVar5 = UTIL_dtos1(iTimer);
        ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev,1,"#Detpack_set",pcVar5,(char *)0x0,
                    (char *)0x0,(char *)0x0);
        pCVar6 = CBaseEntity::CreateTimer((CBaseEntity *)this,9);
        pCVar6->pev->nextthink = gpGlobals->time + 3.0;
        (pCVar6->m_pfnThink).__pfn = CBaseEntity::Timer_DetpackSet;
        (pCVar6->m_pfnThink).__delta = 0;
        pCVar6->pev->health = (float)iTimer;
        return;
      }
      pcVar5 = "#Detpack_fivesec";
      goto LAB_000c4197;
    }
    peVar3 = (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    pcVar5 = gpGlobals->pStringBase + peVar3->classname;
    bVar10 = pcVar5 == (char *)0x0;
    iVar7 = 7;
    pcVar8 = pcVar5;
    pcVar9 = "player";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar10 = *pcVar8 == *pcVar9;
      pcVar8 = pcVar8 + (uint)bVar12 * -2 + 1;
      pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
    } while (bVar10);
    bVar11 = false;
    if (((bVar10) && (bVar11 = this == pStartEntity, !bVar11)) &&
       (bVar11 = false, (peVar3->effects & 0x80) == 0)) {
      pcVar5 = "#Detpack_someone";
LAB_000c41e1:
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,pcVar5,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      return;
    }
    iVar7 = 0x13;
    pcVar8 = pcVar5;
    pcVar9 = "building_sentrygun";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar11 = *pcVar8 == *pcVar9;
      pcVar8 = pcVar8 + (uint)bVar12 * -2 + 1;
      pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
    } while (bVar11);
    if (bVar11) {
      pcVar5 = "#Detpack_sentry";
      goto LAB_000c4197;
    }
    iVar7 = 0x13;
    bVar10 = false;
    pcVar8 = pcVar5;
    pcVar9 = "building_dispenser";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar10 = *pcVar8 == *pcVar9;
      pcVar8 = pcVar8 + (uint)bVar12 * -2 + 1;
      pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
    } while (bVar10);
    if (bVar10) {
      pcVar5 = "#Detpack_dispenser";
      goto LAB_000c41e1;
    }
    iVar7 = 0x14;
    bVar10 = false;
    pcVar8 = pcVar5;
    pcVar9 = "building_teleporter";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar10 = *pcVar8 == *pcVar9;
      pcVar8 = pcVar8 + (uint)bVar12 * -2 + 1;
      pcVar9 = pcVar9 + (uint)bVar12 * -2 + 1;
    } while (bVar10);
    if (bVar10) {
      pcVar5 = "#Detpack_teleporter";
      goto LAB_000c4197;
    }
    iVar7 = 8;
    bVar10 = false;
    pcVar8 = "detpack";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar10 = *pcVar5 == *pcVar8;
      pcVar5 = pcVar5 + (uint)bVar12 * -2 + 1;
      pcVar8 = pcVar8 + (uint)bVar12 * -2 + 1;
    } while (bVar10);
  } while (!bVar10);
  pcVar5 = "#Detpack_stack";
LAB_000c4197:
  ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,pcVar5,(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  return;
}


// CBasePlayer::TeamFortress_DetpackStop  @ 000c4470  (line 415)

/* DWARF original prototype: void TeamFortress_DetpackStop(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_DetpackStop(CBasePlayer *this)

{
  int *piVar1;
  CBaseEntity *te;
  
                    /* Unresolved local var: CBaseEntity * pTimer@[???] */
  te = CBaseEntity::FindTimer((CBaseEntity *)this,9);
  if (te != (CBaseEntity *)0x0) {
    ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.pev,1,"#Detpack_retrieve",(char *)0x0,(char *)0x0,(char *)0x0,
                (char *)0x0);
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_detpack;
    *piVar1 = *piVar1 + 1;
    dremove(te);
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.tfstate;
    *piVar1 = *piVar1 & 0xfffeffff;
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.is_detpacking = 0;
    TeamFortress_SetSpeed(this);
                    /* WARNING: Could not recover jumptable at 0x000c4503. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x47])();
    return;
  }
  return;
}


// CBasePlayer::TeamFortress_RemoveDetpacks  @ 000c4510  (line 439)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL TeamFortress_RemoveDetpacks(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::TeamFortress_RemoveDetpacks(CBasePlayer *this)

{
  CBaseEntity *pStartEntity;
  BOOL BVar1;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"detpack");
  BVar1 = 0;
  if (pStartEntity != (CBaseEntity *)0x0) {
    while (pStartEntity->pev->owner !=
           ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->pContainingEntity) {
      pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"detpack");
      if (pStartEntity == (CBaseEntity *)0x0) {
        return 0;
      }
    }
    dremove(pStartEntity);
    BVar1 = 1;
  }
  return BVar1;
}


