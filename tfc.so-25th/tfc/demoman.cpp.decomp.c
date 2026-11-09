// Ghidra decompilation of functions from tfc/demoman.cpp
// 11 functions, ordered by original source line

// detpack  @ 00084150  (line 21)

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
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CDetpack_0014b054;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.pev = pev;
  return;
}


// CDetpack::Spawn  @ 00083f70  (line 24)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CDetpack * this) */

void __thiscall CDetpack::Spawn(CDetpack *this)

{
  code *pcVar1;
  entvars_t *peVar2;
  _2globalvars_t *p1Var3;
  Vector local_24;
  Vector local_18;
  
  pcVar1 = *(code **)((int)(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                           super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity
                     + 0xc);
  if (pcVar1 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/presentlg.mdl");
    (*g_engfuncs.pfnPrecacheModel)("models/detpack.mdl");
    (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
    (*g_engfuncs.pfnPrecacheSound)("weapons/mortarhit.wav");
    (*g_engfuncs.pfnPrecacheSound)("weapons/mine_activate.wav");
    (*g_engfuncs.pfnPrecacheSound)("weapons/mine_charge.wav");
  }
  else {
    (*pcVar1)(this);
  }
  this->bAlternateLight = 0;
  this->bTicked = 0;
  ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
   .super_CBaseEntity.pev)->movetype = 6;
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
  p1Var3 = gpGlobals;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = DetpackTouch;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnTouch + 4) = 0;
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = DetpackThink;
  *(int *)((int)&(this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.m_pfnThink + 4) = 0;
  local_18.x = 4.0;
  local_18.y = 4.0;
  local_18.z = 4.0;
  local_24.x = -4.0;
  peVar2->nextthink = p1Var3->time + 0.1;
  local_24.y = -4.0;
  local_24.z = -4.0;
  UTIL_SetSize((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
               super_CBaseDelay.super_CBaseEntity.pev,&local_24,&local_18);
  peVar2 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
           super_CBaseDelay.super_CBaseEntity.pev;
  UTIL_SetOrigin(peVar2,&peVar2->origin);
  (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.weaponmode = 0.0;
  EMIT_SOUND_DYN(((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                  super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,1,
                 "weapons/mine_activate.wav",1.0,0.8,0,100);
  return;
}


// CDetpack::DetpackTouch  @ 00083d00  (line 53)

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
  char *pcVar10;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???] */
  peVar8 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar8 == (edict_t *)0x0) {
    peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar8 == (edict_t *)0x0) {
      this_00 = (CBaseEntity *)0x0;
      goto LAB_00083d2f;
    }
  }
  this_00 = peVar8->pvPrivateData;
LAB_00083d2f:
  iVar3 = (*pOther->_vptr_CBaseEntity[10])(pOther);
  if ((iVar3 == 2) && (pOther->pev->playerclass == 1)) {
    iVar3 = (*pOther->_vptr_CBaseEntity[0x22])(pOther);
    if (iVar3 != 0) {
      BVar4 = CBaseEntity::IsAlly(this_00,pOther);
      if (BVar4 == 0) {
        pcVar10 = gpGlobals->pStringBase;
        if (birthday == 1) {
          UTIL_ClientPrintAll(1,"#Detpack_disarm_bday",pcVar10 + pOther->pev->netname,
                              pcVar10 + this_00->pev->netname,(char *)0x0,(char *)0x0);
        }
        else {
          UTIL_ClientPrintAll(1,"#Detpack_disarm",pcVar10 + this_00->pev->netname,
                              pcVar10 + pOther->pev->netname,(char *)0x0,(char *)0x0);
        }
        pcVar10 = "SPECTATOR";
        if (this_00->team_no != 0) {
          pcVar10 = GetTeamName(this_00->team_no);
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
                       pcVar1 + sVar2,iVar3,pcVar5,pcVar10);
        CBasePlayer::TF_AddFrags((CBasePlayer *)pOther,1);
        dremove((CBaseEntity *)this);
        return;
      }
    }
  }
  return;
}


// CDetpack::TeamFortress_TakeEMPBlast  @ 00083c60  (line 125)

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
  peVar2->health = (float)(lVar3 + (longdouble)(fVar1 + 1.0));
  return;
}


// CDetpack::DetpackThink  @ 00084a10  (line 130)

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
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???]
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
      goto LAB_00084a7f;
    }
  }
  pvVar5 = peVar2->pvPrivateData;
LAB_00084a7f:
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


// CDetpack::Precache  @ 00083ca0  (line 176)

/* DWARF original prototype: void Precache(CDetpack * this) */

void __thiscall CDetpack::Precache(CDetpack *this)

{
  (*g_engfuncs.pfnPrecacheModel)("models/presentlg.mdl");
  (*g_engfuncs.pfnPrecacheModel)("models/detpack.mdl");
  (*g_engfuncs.pfnPrecacheModel)("sprites/flare3.spr");
  (*g_engfuncs.pfnPrecacheSound)("weapons/mortarhit.wav");
  (*g_engfuncs.pfnPrecacheSound)("weapons/mine_activate.wav");
                    /* WARNING: Could not recover jumptable at 0x00083cf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnPrecacheSound)("weapons/mine_charge.wav");
  return;
}


// CDetpack::Remove  @ 000841d0  (line 188)

/* DWARF original prototype: void Remove(CDetpack * this) */

void __thiscall CDetpack::Remove(CDetpack *this)

{
  char *pcVar1;
  int iVar2;
  edict_t *peVar3;
  void *pvVar4;
  char *pcVar5;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???] */
  peVar3 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar3 == (edict_t *)0x0) {
    peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar3 == (edict_t *)0x0) {
      pvVar4 = (void *)0x0;
      goto LAB_000841ef;
    }
  }
  pvVar4 = peVar3->pvPrivateData;
LAB_000841ef:
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


// CDetpack::DetpackExplode  @ 000843a0  (line 224)

/* DWARF original prototype: void DetpackExplode(CDetpack * this) */

void __thiscall CDetpack::DetpackExplode(CDetpack *this)

{
  float fVar1;
  float fVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  entvars_t *peVar5;
  float *pfVar6;
  uint uVar7;
  edict_t *peVar8;
  int iVar9;
  entvars_t *peVar10;
  CBaseEntity *pCVar11;
  void *pvVar12;
  float *pfVar13;
  char *pcVar14;
  char *pcVar15;
  bool bVar16;
  byte bVar17;
  float fVar18;
  float afStackY_a4 [2];
  float local_74;
  void *local_70;
  float local_64 [15];
  float local_28 [6];
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???]
                       Unresolved local var: int iPos@[???] */
  bVar17 = 0;
  pfVar13 = (float *)&stack0xffffff64;
  peVar10 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev;
  peVar8 = peVar10->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar8 == (edict_t *)0x0) {
    peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar10 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev;
    if (peVar8 != (edict_t *)0x0) goto LAB_000843c2;
    local_70 = (void *)0x0;
  }
  else {
LAB_000843c2:
    local_70 = peVar8->pvPrivateData;
  }
  uVar7 = UTIL_PointContents(&peVar10->origin);
  if (((uVar7 & 0xfffffffb) == 0xfffffffa) || (*(int *)((int)local_70 + 0x7c) == 1)) {
    ClientPrint(*(entvars_t **)((int)local_70 + 4),1,"#Detpack_fizzle",(char *)0x0,(char *)0x0,
                (char *)0x0,(char *)0x0);
    if (*(int *)((int)local_70 + 0x138) != 0) {
      GetTeamName(*(int *)((int)local_70 + 0x138));
    }
    (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)((int)local_70 + 4) + 0x208));
    (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)((int)local_70 + 4) + 0x208));
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
                          gpGlobals->pStringBase + *(int *)(*(int *)((int)local_70 + 4) + 0x1d0),
                          (char *)0x0,(char *)0x0,(char *)0x0);
    }
    if (*(int *)((int)local_70 + 0x138) != 0) {
      GetTeamName(*(int *)((int)local_70 + 0x138));
    }
    (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)((int)local_70 + 4) + 0x208));
    (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)((int)local_70 + 4) + 0x208));
    pCVar11 = (CBaseEntity *)0x0;
    UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Detpack_Explode\"\n");
    pfVar6 = (float *)&stack0xffffff64;
LAB_00084510:
    pfVar13 = pfVar6;
    *pfVar13 = (float)pCVar11;
    pfVar13[2] = 1500.0;
    pfVar13[1] = (float)(pfVar13 + 0xc);
    pfVar13[-1] = 7.59493e-40;
    pCVar11 = UTIL_FindEntityInSphere((CBaseEntity *)*pfVar13,(Vector *)pfVar13[1],pfVar13[2]);
    if (pCVar11 != (CBaseEntity *)0x0) {
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSpot@[???] */
      peVar10 = pCVar11->pev;
      pp_Var3 = pCVar11->_vptr_CBaseEntity;
      *pfVar13 = (float)(pfVar13 + 0x12);
      pfVar13[1] = (float)pCVar11;
      p_Var4 = pp_Var3[0x32];
      pfVar13[-1] = 7.5954e-40;
      (*p_Var4)();
      fVar1 = (peVar10->view_ofs).z;
      fVar18 = (peVar10->view_ofs).y;
      fVar2 = (peVar10->view_ofs).x;
      pfVar13[3] = (float)(pfVar13 + 0x11);
      peVar8 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity;
      pfVar13[0xe] = pfVar13[0x11] + fVar2;
      pfVar13[0xf] = pfVar13[0x12] + fVar18;
      pfVar13[1] = 0.0;
      pfVar13[0x10] = pfVar13[0x13] + fVar1;
      pfVar13[2] = (float)peVar8;
      *pfVar13 = (float)(pfVar13 + 0xe);
      pfVar13[-1] = (float)(pfVar13 + 0xb);
      pfVar13[-2] = 7.59666e-40;
      UTIL_TraceLine((Vector *)pfVar13[-1],(Vector *)*pfVar13,(IGNORE_MONSTERS)pfVar13[1],
                     (edict_t *)pfVar13[2],(_1TraceResult *)pfVar13[3]);
      peVar10 = pCVar11->pev;
      if ((1.0 <= pfVar13[0x15]) ||
         (pfVar6 = pfVar13 + -1, (edict_t *)pfVar13[0x1d] == peVar10->pContainingEntity)) {
        bVar16 = gpGlobals->pStringBase + peVar10->classname == (char *)0x0;
        iVar9 = 0xc;
        pcVar14 = gpGlobals->pStringBase + peVar10->classname;
        pcVar15 = "info_tfgoal";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar16 = *pcVar14 == *pcVar15;
          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
          pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
        } while (bVar16);
        if (bVar16) {
          pfVar6 = pfVar13 + -1;
          if (((pCVar11->goal_activation & 2) != 0) &&
             (pfVar6 = pfVar13 + -1, pCVar11->search_time == 0.0)) {
            pfVar13[1] = (float)pCVar11;
            pfVar13[-1] = (float)pCVar11;
            *pfVar13 = pfVar13[10];
            pfVar13[-2] = 7.59826e-40;
            ActivateDoResults((CBaseEntity *)pfVar13[-1],(CBasePlayer *)*pfVar13,
                              (CBaseEntity *)pfVar13[1]);
            pfVar6 = pfVar13 + -1;
          }
        }
        else {
          pfVar6 = pfVar13 + -1;
          if (peVar10->takedamage != 0.0) {
            peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                     super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
            fVar1 = (peVar10->origin).z - (peVar5->origin).z;
            fVar2 = (peVar10->origin).y - (peVar5->origin).y;
            fVar18 = (peVar10->origin).x - (peVar5->origin).x;
            fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar18 * fVar18;
            fVar18 = SQRT(fVar1);
            if (NAN(fVar18)) {
              pfVar13[-1] = fVar1;
              pfVar13[-2] = 7.6122e-40;
              fVar18 = sqrtf(pfVar13[-1]);
            }
            pfVar6 = pfVar13 + -1;
            if (fVar18 <= 700.0) {
                    /* Unresolved local var: Vector vecOrg@[???]
                       Unresolved local var: float flPoints@[???] */
              peVar10 = pCVar11->pev;
              peVar5 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                       super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
              fVar1 = (peVar5->origin).z -
                      (((peVar10->mins).z + (peVar10->maxs).z) * 0.5 + (peVar10->origin).z);
              fVar2 = (peVar5->origin).y -
                      (((peVar10->mins).y + (peVar10->maxs).y) * 0.5 + (peVar10->origin).y);
              fVar18 = (peVar5->origin).x -
                       (((peVar10->mins).x + (peVar10->maxs).x) * 0.5 + (peVar10->origin).x);
              fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar18 * fVar18;
              fVar18 = SQRT(fVar1);
              if (NAN(fVar18)) {
                pfVar13[-1] = fVar1;
                pfVar13[-2] = 7.61241e-40;
                fVar18 = sqrtf(pfVar13[-1]);
              }
              if (fVar18 * 0.5 < 0.0) {
                fVar1 = 1400.0;
              }
              else {
                fVar1 = 700.0 - fVar18 * 0.5;
                pfVar6 = pfVar13 + -1;
                if (fVar1 == 0.0) goto LAB_00084510;
                fVar1 = fVar1 + fVar1;
              }
              pp_Var3 = pCVar11->_vptr_CBaseEntity;
              pfVar13[2] = fVar1;
              pfVar13[3] = 8.96831e-44;
              pfVar13[1] = *(float *)((int)pfVar13[10] + 4);
              peVar10 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.
                        super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
              pfVar13[-1] = (float)pCVar11;
              *pfVar13 = (float)peVar10;
              p_Var4 = pp_Var3[0xd];
              pfVar13[-2] = 7.6096e-40;
              (*p_Var4)();
              pfVar6 = pfVar13 + -1;
            }
          }
        }
      }
      goto LAB_00084510;
    }
    pfVar13[3] = 0.0;
    peVar10 = (this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
              super_CBaseDelay.super_CBaseEntity.pev;
    pfVar13[1] = 3.22299e-44;
    *pfVar13 = 7.00649e-45;
    pfVar13[2] = (float)&peVar10->origin;
    pfVar13[-1] = 7.60678e-40;
    (*g_engfuncs.pfnMessageBegin)
              ((int)*pfVar13,(int)pfVar13[1],(float *)pfVar13[2],(edict_t *)pfVar13[3]);
    *pfVar13 = 4.2039e-45;
    pfVar13[-1] = 7.60696e-40;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar13);
    *pfVar13 = (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev)->origin).x;
    pfVar13[-1] = 7.60723e-40;
    (*g_engfuncs.pfnWriteCoord)(*pfVar13);
    *pfVar13 = (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev)->origin).y;
    pfVar13[-1] = 7.6075e-40;
    (*g_engfuncs.pfnWriteCoord)(*pfVar13);
    *pfVar13 = (((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev)->origin).z;
    pfVar13[-1] = 7.60776e-40;
    (*g_engfuncs.pfnWriteCoord)(*pfVar13);
    *pfVar13 = (float)(int)g_sModelIndexFireball;
    pfVar13[-1] = 7.60799e-40;
    (*g_engfuncs.pfnWriteShort)((int)*pfVar13);
    *pfVar13 = 7.00649e-44;
    pfVar13[-1] = 7.60817e-40;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar13);
    *pfVar13 = 2.10195e-44;
    pfVar13[-1] = 7.60835e-40;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar13);
    *pfVar13 = 4.2039e-45;
    pfVar13[-1] = 7.60853e-40;
    (*g_engfuncs.pfnWriteByte)((int)*pfVar13);
    pfVar13[-1] = 7.60862e-40;
    (*g_engfuncs.pfnMessageEnd)();
  }
  if ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
      super_CBaseDelay.super_CBaseEntity.weaponmode != 1.0) goto LAB_000846db;
                    /* Unresolved local var: CBasePlayer * pEnemy@[???]
                       Unresolved local var: CBaseEntity * pTimer@[???] */
  peVar8 = ((this->super_CGrenade).super_CBaseMonster.super_CBaseToggle.super_CBaseAnimating.
            super_CBaseDelay.super_CBaseEntity.pev)->enemy;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar8 == (edict_t *)0x0) {
    *pfVar13 = 0.0;
    pfVar13[-1] = 7.61185e-40;
    peVar8 = (*g_engfuncs.pfnPEntityOfEntOffset)((int)*pfVar13);
    if (peVar8 != (edict_t *)0x0) goto LAB_00084711;
    pvVar12 = (void *)0x0;
  }
  else {
LAB_00084711:
    pvVar12 = peVar8->pvPrivateData;
  }
  *(uint *)((int)pvVar12 + 0x9c) = *(uint *)((int)pvVar12 + 0x9c) & 0xfffeffff;
  *pfVar13 = (float)pvVar12;
  pfVar13[-1] = 7.60214e-40;
  CBasePlayer::TeamFortress_SetSpeed((CBasePlayer *)*pfVar13);
  pfVar13[1] = 1.4013e-44;
  *pfVar13 = (float)pvVar12;
  pfVar13[-1] = 7.60231e-40;
  pCVar11 = CBaseEntity::FindTimer((CBaseEntity *)*pfVar13,(int)pfVar13[1]);
  if (pCVar11 != (CBaseEntity *)0x0) {
    *pfVar13 = (float)pCVar11;
    pfVar13[-1] = 7.60248e-40;
    dremove((CBaseEntity *)*pfVar13);
  }
LAB_000846db:
  if (this->m_pBlinkSprite != (CSprite *)0x0) {
    *pfVar13 = (float)this->m_pBlinkSprite;
    pfVar13[-1] = 7.60127e-40;
    dremove((CBaseEntity *)*pfVar13);
  }
  *pfVar13 = (float)this;
  pfVar13[-1] = 7.60139e-40;
  dremove((CBaseEntity *)*pfVar13);
  return;
}


// CBasePlayer::TeamFortress_SetDetpack  @ 00084cb0  (line 322)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SetDetpack(CBasePlayer * this, int iTimer) */

void __thiscall CBasePlayer::TeamFortress_SetDetpack(CBasePlayer *this,int iTimer)

{
  int *piVar1;
  float fVar2;
  entvars_t *peVar3;
  uint uVar4;
  _2globalvars_t *p1Var5;
  CBasePlayer *pStartEntity;
  CBaseEntity *pCVar6;
  char *param1;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  byte bVar15;
  
                    /* Unresolved local var: CBaseEntity * pEntity@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???]
                       Unresolved local var: CBaseEntity * pTimer@[???] */
  bVar15 = 0;
  if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.weapons_carried & 0x20000) == 0) {
    return;
  }
  if ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_detpack < 1) {
    return;
  }
  pStartEntity = (CBasePlayer *)0x0;
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
      p1Var5 = gpGlobals;
      while( true ) {
        gpGlobals = p1Var5;
        if (pCVar6 == (CBaseEntity *)0x0) {
          if (iTimer < 5) {
            ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,1,"#Detpack_fivesec",(char *)0x0,
                        (char *)0x0,(char *)0x0,(char *)0x0);
          }
          else {
            piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.ammo_detpack;
            *piVar1 = *piVar1 + -1;
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.is_detpacking = 1;
            fVar2 = p1Var5->time;
            piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.tfstate;
            *piVar1 = *piVar1 | 0x10000;
            (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.immune_to_check = fVar2 + 10.0;
            TeamFortress_SetSpeed(this);
            (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity[0x49])(this->m_pActiveItem,0);
            ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->weaponmodel = 0;
            param1 = UTIL_dtos1(iTimer);
            ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                        super_CBaseDelay.super_CBaseEntity.pev,1,"#Detpack_set",param1,(char *)0x0,
                        (char *)0x0,(char *)0x0);
            pCVar6 = CBaseEntity::CreateTimer((CBaseEntity *)this,9);
            pCVar6->pev->nextthink = gpGlobals->time + 3.0;
            (pCVar6->m_pfnThink).__pfn = CBaseEntity::Timer_DetpackSet;
            (pCVar6->m_pfnThink).__delta = 0;
            pCVar6->pev->health = (float)iTimer;
          }
          return;
        }
        peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev;
        if (pCVar6->pev->owner == peVar3->pContainingEntity) break;
        pCVar6 = UTIL_FindEntityByClassname(pCVar6,"detpack");
        p1Var5 = gpGlobals;
      }
      ClientPrint(peVar3,1,"#Detpack_oneactive",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
      return;
    }
    peVar3 = (pStartEntity->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
             super_CBaseDelay.super_CBaseEntity.pev;
    iVar7 = 7;
    uVar4 = peVar3->classname;
    bVar11 = CARRY4(uVar4,(uint)gpGlobals->pStringBase);
    pbVar8 = (byte *)(gpGlobals->pStringBase + uVar4);
    bVar13 = pbVar8 == (byte *)0x0;
    pbVar9 = pbVar8;
    pbVar10 = (byte *)"player";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar11 = *pbVar9 < *pbVar10;
      bVar13 = *pbVar9 == *pbVar10;
      pbVar9 = pbVar9 + (uint)bVar15 * -2 + 1;
      pbVar10 = pbVar10 + (uint)bVar15 * -2 + 1;
    } while (bVar13);
    bVar12 = (!bVar11 && !bVar13) < bVar11;
    bVar14 = false;
    if ((!bVar11 && !bVar13) == bVar11) {
      bVar12 = pStartEntity < this;
      bVar14 = pStartEntity == this;
      if (!bVar14) {
        bVar12 = false;
        bVar14 = false;
        if ((peVar3->effects & 0x80) == 0) {
          ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,"#Detpack_someone",(char *)0x0,
                      (char *)0x0,(char *)0x0,(char *)0x0);
          return;
        }
      }
    }
    iVar7 = 0x13;
    pbVar9 = pbVar8;
    pbVar10 = (byte *)"building_sentrygun";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar12 = *pbVar9 < *pbVar10;
      bVar14 = *pbVar9 == *pbVar10;
      pbVar9 = pbVar9 + (uint)bVar15 * -2 + 1;
      pbVar10 = pbVar10 + (uint)bVar15 * -2 + 1;
    } while (bVar14);
    bVar11 = (!bVar12 && !bVar14) < bVar12;
    if ((!bVar12 && !bVar14) == bVar12) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Detpack_sentry",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      return;
    }
    iVar7 = 0x13;
    bVar13 = false;
    pbVar9 = pbVar8;
    pbVar10 = (byte *)"building_dispenser";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar11 = *pbVar9 < *pbVar10;
      bVar13 = *pbVar9 == *pbVar10;
      pbVar9 = pbVar9 + (uint)bVar15 * -2 + 1;
      pbVar10 = pbVar10 + (uint)bVar15 * -2 + 1;
    } while (bVar13);
    bVar14 = (!bVar11 && !bVar13) < bVar11;
    if ((!bVar11 && !bVar13) == bVar11) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Detpack_dispenser",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      return;
    }
    iVar7 = 0x14;
    bVar11 = false;
    pbVar9 = pbVar8;
    pbVar10 = (byte *)"building_teleporter";
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar14 = *pbVar9 < *pbVar10;
      bVar11 = *pbVar9 == *pbVar10;
      pbVar9 = pbVar9 + (uint)bVar15 * -2 + 1;
      pbVar10 = pbVar10 + (uint)bVar15 * -2 + 1;
    } while (bVar11);
    if ((!bVar14 && !bVar11) == bVar14) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Detpack_teleporter",(char *)0x0,(char *)0x0,(char *)0x0
                  ,(char *)0x0);
      return;
    }
    iVar7 = 8;
    bVar11 = false;
    pbVar9 = (byte *)0x1621b9;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar11 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + (uint)bVar15 * -2 + 1;
      pbVar9 = pbVar9 + (uint)bVar15 * -2 + 1;
    } while (bVar11);
    if (bVar11) {
      ClientPrint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev,1,"#Detpack_stack",(char *)0x0,(char *)0x0,(char *)0x0,
                  (char *)0x0);
      return;
    }
  } while( true );
}


// CBasePlayer::TeamFortress_DetpackStop  @ 000850f0  (line 415)

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
                    /* WARNING: Could not recover jumptable at 0x00085183. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(this->m_pActiveItem->super_CBaseAnimating).super_CBaseDelay.super_CBaseEntity.
      _vptr_CBaseEntity[0x47])();
    return;
  }
  return;
}


// CBasePlayer::TeamFortress_RemoveDetpacks  @ 00085190  (line 439)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL TeamFortress_RemoveDetpacks(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::TeamFortress_RemoveDetpacks(CBasePlayer *this)

{
  CBaseEntity *pStartEntity;
  
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"detpack");
  while( true ) {
    if (pStartEntity == (CBaseEntity *)0x0) {
      return 0;
    }
    if (pStartEntity->pev->owner ==
        ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
         super_CBaseEntity.pev)->pContainingEntity) break;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"detpack");
  }
  dremove(pStartEntity);
  return 1;
}


