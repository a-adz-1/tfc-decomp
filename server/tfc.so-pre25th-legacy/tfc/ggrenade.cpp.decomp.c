// Ghidra decompilation of functions from tfc/ggrenade.cpp
// 21 functions, ordered by original source line

// grenade  @ 000dc570  (line 30)

void grenade(entvars_t *pev)

{
  undefined4 *puVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  puVar1 = CBaseEntity::operator_new(0x6d8,pev);
  *puVar1 = &PTR__CGrenade_001806e8;
  puVar1[1] = pev;
  return;
}


// CGrenade::CGrenade  @ 000dc5e0  (line 36)

/* DWARF original prototype: void CGrenade(CGrenade * this) */

void __thiscall CGrenade::CGrenade(CGrenade *this)

{
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGrenade_001806e8;
  return;
}


// CGrenade::Explode  @ 000db680  (line 45)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CGrenade * this, Vector vecSrc, Vector vecAim) */

void __thiscall CGrenade::Explode(CGrenade *this,Vector vecSrc,Vector vecAim)

{
  entvars_t *peVar1;
  TraceResult local_50;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult tr@[???] */
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_18.z = (peVar1->origin).z + -32.0;
  local_18.y = (peVar1->origin).y + 0.0;
  local_18.x = (peVar1->origin).x + 0.0;
  UTIL_TraceLine(&peVar1->origin,&local_18,ignore_monsters,peVar1->pContainingEntity,&local_50);
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x87])(this,&local_50,0x40);
  return;
}


// CGrenade::InNoGrenadeZone  @ 000dc5f0  (line 54)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL InNoGrenadeZone(CGrenade * this, Vector vecOrigin) */

BOOL __thiscall CGrenade::InNoGrenadeZone(CGrenade *this,Vector vecOrigin)

{
  int *piVar1;
  entvars_t *peVar2;
  globalvars_t *pgVar3;
  CBaseEntity *pStartEntity;
  CSprite *pCVar4;
  
                    /* Unresolved local var: CBaseEntity * pNoGrenade@[???] */
  pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"func_nogrenades");
  while( true ) {
    if (pStartEntity == (CBaseEntity *)0x0) {
      return 0;
    }
    peVar2 = *(entvars_t **)((int)pStartEntity + 4);
    if (((((peVar2->mins).x <= *(float *)vecOrigin.x) &&
         ((peVar2->mins).y <= *(float *)((int)vecOrigin.x + 4))) &&
        ((peVar2->mins).z <= *(float *)((int)vecOrigin.x + 8))) &&
       (((*(float *)vecOrigin.x <= (peVar2->maxs).x &&
         (*(float *)((int)vecOrigin.x + 4) <= (peVar2->maxs).y)) &&
        (*(float *)((int)vecOrigin.x + 8) <= (peVar2->maxs).z)))) break;
    pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"func_nogrenades");
  }
                    /* Unresolved local var: CSprite * pSprite@[???] */
  pCVar4 = CSprite::SpriteCreate("sprites/xflare1.spr",(Vector *)vecOrigin.x,1);
  peVar2 = (pCVar4->super_CPointEntity).super_CBaseEntity.pev;
  (pCVar4->super_CPointEntity).super_CBaseEntity.m_pfnThink.__pfn = CSprite::AnimateUntilDead;
  (pCVar4->super_CPointEntity).super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar2->framerate = 60.0;
  pgVar3 = gpGlobals;
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->dmgtime =
       pCVar4->m_maxFrame / 60.0 + gpGlobals->time;
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->nextthink = pgVar3->time;
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->rendermode = 5;
  (((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).x = 255.0;
  (((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).y = 255.0;
  (((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->rendercolor).z = 255.0;
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->renderamt = 255.0;
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->renderfx = 0xe;
  ((pCVar4->super_CPointEntity).super_CBaseEntity.pev)->scale = 0.25;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x40000000;
  return 1;
}


// CGrenade::Explode  @ 000dbcd0  (line 80)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Explode(CGrenade * this, TraceResult * pTrace, int bitsDamageType)
    */

void __thiscall CGrenade::Explode(CGrenade *this,TraceResult *pTrace,int bitsDamageType)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  vec_t vVar7;
  int iVar8;
  entvars_t *peVar9;
  int32 iVar10;
  edict_t *peVar11;
  entvars_t *peVar12;
  void *pvVar13;
  longdouble extraout_ST0;
  char *sample;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: float flRndSound@[???]
                       Unresolved local var: Vector OldPos@[???]
                       Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg7(EDI)]
                       Unresolved local var: int iContents@[???]
                       Unresolved local var: entvars_t * pevOwner@[???] */
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->model = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 0.0;
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  local_28 = (peVar12->origin).x;
  local_24 = (peVar12->origin).y;
  local_20 = (peVar12->origin).z;
  peVar11 = peVar12->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar11 == (edict_t *)0x0) {
    peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    if (peVar11 != (edict_t *)0x0) goto LAB_000dbd28;
    pvVar13 = (void *)0x0;
  }
  else {
LAB_000dbd28:
    pvVar13 = peVar11->pvPrivateData;
  }
  iVar8 = *(int *)((int)pvVar13 + 4);
  if ((((peVar12->origin).x == *(float *)(iVar8 + 8)) &&
      ((peVar12->origin).y == *(float *)(iVar8 + 0xc))) &&
     ((peVar12->origin).z == *(float *)(iVar8 + 0x10))) {
    g_iGrenadeInHand = 1;
  }
  if (pTrace->flFraction != 1.0) {
    fVar2 = (pTrace->vecPlaneNormal).z;
    fVar3 = (pTrace->vecEndPos).z;
    fVar4 = (pTrace->vecPlaneNormal).y;
    fVar5 = (pTrace->vecEndPos).y;
    (peVar12->origin).x = (pTrace->vecPlaneNormal).x * 32.0 + (pTrace->vecEndPos).x;
    (peVar12->origin).y = fVar4 * 32.0 + fVar5;
    (peVar12->origin).z = fVar2 * 32.0 + fVar3;
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
  }
  iVar8 = UTIL_PointContents(&peVar12->origin);
  if (iVar8 == -2) {
    peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev;
    (peVar12->origin).x = local_28;
    (peVar12->origin).y = local_24;
    (peVar12->origin).z = local_20;
    iVar8 = UTIL_PointContents(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                 super_CBaseDelay.super_CBaseEntity.pev)->origin);
    if (iVar8 == -2) goto LAB_000dc1c0;
  }
  iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.team_no;
  if ((*(int *)((int)pvVar13 + 0x138) != iVar6) && (iVar6 != 0)) {
LAB_000dc1c0:
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  if (this->m_flExplosionScale == 0.0) {
    this->m_flExplosionScale =
         (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->dmg - 50.0) * 0.6;
  }
  if (this->m_usExplode == 0) {
    (*g_engfuncs.pfnMessageBegin)
              (5,0x17,&(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                         super_CBaseDelay.super_CBaseEntity.pev)->origin).x,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(3);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).x);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).y);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).z);
    (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexFireball);
    (*g_engfuncs.pfnWriteByte)((int)this->m_flExplosionScale);
    (*g_engfuncs.pfnWriteByte)(0xf);
    (*g_engfuncs.pfnWriteByte)(3);
    (*g_engfuncs.pfnMessageEnd)();
  }
  else {
    (*g_engfuncs.pfnPlaybackEvent)
              (0,(edict_t *)0x0,this->m_usExplode,0.0,&local_28,&g_vecZero.x,0.0,0.0,0,0,0,0);
  }
  CSoundEnt::InsertSound
            (1,&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin,0x400,3.0);
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  peVar11 = peVar12->owner;
  peVar9 = (entvars_t *)0x0;
  if (peVar11 != (edict_t *)0x0) {
    peVar9 = &peVar11->v;
  }
  peVar12->owner = (edict_t *)0x0;
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x7f])(this,peVar12,peVar9,peVar12->dmg,0,bitsDamageType);
  vVar7 = g_vecZero.x;
  g_iGrenadeInHand = 0;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->effects;
  *piVar1 = *piVar1 | 0x80;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Smoke;
  peVar12 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  (peVar12->velocity).x = vVar7;
  (peVar12->velocity).y = g_vecZero.y;
  (peVar12->velocity).z = g_vecZero.z;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.3;
  if (this->m_usExplode != 0) {
    return;
  }
  (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  if (extraout_ST0 < (longdouble)0.5) {
    UTIL_DecalTrace(pTrace,0xb);
  }
  else {
    UTIL_DecalTrace(pTrace,0xc);
  }
  (*g_engfuncs.pfnRandomFloat)(0.0,1.0);
  iVar10 = (*g_engfuncs.pfnRandomLong)(0,2);
  if (iVar10 == 1) {
    sample = "weapons/debris2.wav";
  }
  else if (iVar10 == 2) {
    sample = "weapons/debris3.wav";
  }
  else {
    if (iVar10 != 0) goto LAB_000dc0eb;
    sample = "weapons/debris1.wav";
  }
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,2,sample,0.55,0.8,0,100);
LAB_000dc0eb:
                    /* Unresolved local var: int sparkCount@[???] */
                    /* Unresolved local var: int i@[???] */
  if (((iVar8 != -3) && (this->m_bDontSpark == 0)) &&
     (iVar10 = (*g_engfuncs.pfnRandomLong)(0,3), 0 < iVar10)) {
    iVar8 = 0;
    do {
      iVar8 = iVar8 + 1;
      CBaseEntity::Create("spark_shower",
                          &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->origin,&pTrace->vecPlaneNormal,
                          (edict_t *)0x0);
    } while (iVar8 != iVar10);
  }
  return;
}


// CGrenade::Smoke  @ 000db810  (line 199)

/* DWARF original prototype: void Smoke(CGrenade * this) */

void __thiscall CGrenade::Smoke(CGrenade *this)

{
  entvars_t *peVar1;
  Vector mins;
  Vector maxs;
  int iVar2;
  vec_t in_stack_ffffffc0;
  undefined8 in_stack_ffffffc4;
  int in_stack_ffffffcc;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  iVar2 = UTIL_PointContents(&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                               super_CBaseDelay.super_CBaseEntity.pev)->origin);
  if (iVar2 == -3) {
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    local_1c = (peVar1->origin).z;
    local_20 = (peVar1->origin).y;
    local_18 = (peVar1->origin).x + 64.0;
    local_14 = local_20 + 64.0;
    local_10 = local_1c + 64.0;
    local_24 = (peVar1->origin).x - 64.0;
    local_20 = local_20 - 64.0;
    local_1c = local_1c - 64.0;
    mins.y = (vec_t)&local_18;
    mins.x = (vec_t)&local_24;
    mins.z = 1.4013e-43;
    maxs.y = (vec_t)(int)in_stack_ffffffc4;
    maxs.z = (vec_t)(int)((ulonglong)in_stack_ffffffc4 >> 0x20);
    maxs.x = in_stack_ffffffc0;
    UTIL_Bubbles(mins,maxs,in_stack_ffffffcc);
  }
  else if (this->m_bDontSmoke == 0) {
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (this->m_flSmokeScale == 0.0) {
      this->m_flSmokeScale = (peVar1->dmg - 50.0) * 0.8;
    }
    (*g_engfuncs.pfnMessageBegin)(4,0x17,&(peVar1->origin).x,(edict_t *)0x0);
    (*g_engfuncs.pfnWriteByte)(5);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).x);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).y);
    (*g_engfuncs.pfnWriteCoord)
              ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                 super_CBaseEntity.pev)->origin).z);
    (*g_engfuncs.pfnWriteShort)((int)g_sModelIndexSmoke);
    (*g_engfuncs.pfnWriteByte)((int)this->m_flSmokeScale);
    (*g_engfuncs.pfnWriteByte)(0xc);
    (*g_engfuncs.pfnMessageEnd)();
  }
  UTIL_Remove((CBaseEntity *)this);
  return;
}


// CGrenade::Killed  @ 000db800  (line 224)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CGrenade * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CGrenade::Killed(CGrenade *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  int iVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  TraceResult TStack_5c;
  Vector VStack_24;
  Vector VStack_18;
  
  peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->owner;
  if ((((peVar3 != (edict_t *)0x0) ||
       (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 != (edict_t *)0x0)) &&
      (peVar3->pvPrivateData != (void *)0x0)) &&
     ((iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no, *(int *)((int)peVar3->pvPrivateData + 0x138) != iVar1 &&
      (iVar1 != 0)))) {
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  VStack_24.z = (peVar2->origin).z + 8.0;
  VStack_24.y = (peVar2->origin).y + 0.0;
  VStack_24.x = (peVar2->origin).x + 0.0;
  VStack_18.x = VStack_24.x + 0.0;
  VStack_18.y = VStack_24.y + 0.0;
  VStack_18.z = VStack_24.z - 32.0;
  UTIL_TraceLine(&VStack_24,&VStack_18,ignore_monsters,peVar2->pContainingEntity,&TStack_5c);
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x87])(this,&TStack_5c,0x40);
  return;
}


// CGrenade::DetonateUse  @ 000db580  (line 230)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DetonateUse(CGrenade * this, CBaseEntity * pActivator, CBaseEntity
   * pCaller, USE_TYPE useType, float value) */

void __thiscall
CGrenade::DetonateUse
          (CGrenade *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,float value)

{
  globalvars_t *pgVar1;
  
  pgVar1 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Detonate;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = pgVar1->time;
  return;
}


// CGrenade::PreDetonate  @ 000dc7c0  (line 236)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void PreDetonate(CGrenade * this) */

void __thiscall CGrenade::PreDetonate(CGrenade *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  
  CSoundEnt::InsertSound
            (0x20,&((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->origin,400,0.3);
  pgVar2 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Detonate;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = pgVar2->time + 1.0;
  return;
}


// CGrenade::Detonate  @ 000db700  (line 245)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Detonate(CGrenade * this) */

void __thiscall CGrenade::Detonate(CGrenade *this)

{
  int iVar1;
  entvars_t *peVar2;
  edict_t *peVar3;
  TraceResult local_5c;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg0(EAX)] */
  peVar3 = ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.pev)->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((((peVar3 != (edict_t *)0x0) ||
       (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 != (edict_t *)0x0)) &&
      (peVar3->pvPrivateData != (void *)0x0)) &&
     ((iVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.team_no, *(int *)((int)peVar3->pvPrivateData + 0x138) != iVar1 &&
      (iVar1 != 0)))) {
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  local_24.z = (peVar2->origin).z + 8.0;
  local_24.y = (peVar2->origin).y + 0.0;
  local_24.x = (peVar2->origin).x + 0.0;
  local_18.x = local_24.x + 0.0;
  local_18.y = local_24.y + 0.0;
  local_18.z = local_24.z - 32.0;
  UTIL_TraceLine(&local_24,&local_18,ignore_monsters,peVar2->pContainingEntity,&local_5c);
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x87])(this,&local_5c,0x40);
  return;
}


// CGrenade::ExplodeTouch  @ 000dc360  (line 269)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ExplodeTouch(CGrenade * this, CBaseEntity * pOther) */

void __thiscall CGrenade::ExplodeTouch(CGrenade *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  edict_t *pentIgnore;
  entvars_t *peVar4;
  float fVar5;
  TraceResult local_6c;
  Vector local_34;
  Vector local_28 [2];
  
                    /* Unresolved local var: TraceResult tr@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: entvars_t * pevOwner@[DW_OP_reg0(EAX)] */
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->enemy = pOther->pev->pContainingEntity;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
                    /* Unresolved local var: float flLen@[???] */
  fVar1 = (peVar3->velocity).x;
  fVar5 = (peVar3->velocity).y;
  fVar2 = (peVar3->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar5 * fVar5 + fVar1 * fVar1;
  fVar5 = SQRT(fVar1);
  peVar4 = peVar3;
  if (NAN(fVar5)) {
    fVar5 = sqrtf(fVar1);
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  fVar1 = 0.0;
  if (fVar5 == 0.0) {
    fVar2 = 1.0;
    fVar5 = fVar1;
  }
  else {
    fVar5 = 1.0 / fVar5;
    fVar2 = (peVar3->velocity).z * fVar5;
    fVar1 = fVar5 * (peVar3->velocity).x;
    fVar5 = (peVar3->velocity).y * fVar5;
  }
  pentIgnore = peVar4->pContainingEntity;
  local_34.z = (peVar4->origin).z - fVar2 * 32.0;
  local_34.y = (peVar4->origin).y - fVar5 * 32.0;
  local_34.x = (peVar4->origin).x - fVar1 * 32.0;
                    /* Unresolved local var: float flLen@[???] */
  fVar1 = (peVar4->velocity).x;
  fVar5 = (peVar4->velocity).y;
  fVar2 = (peVar4->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar5 * fVar5 + fVar1 * fVar1;
  fVar5 = SQRT(fVar1);
  if (NAN(fVar5)) {
    fVar5 = sqrtf(fVar1);
  }
  fVar1 = 0.0;
  if (fVar5 == 0.0) {
    fVar2 = 1.0;
    fVar5 = fVar1;
  }
  else {
    fVar5 = 1.0 / fVar5;
    fVar2 = (peVar4->velocity).z * fVar5;
    fVar1 = fVar5 * (peVar4->velocity).x;
    fVar5 = (peVar4->velocity).y * fVar5;
  }
  local_28[0].z = fVar2 * 64.0 + local_34.z;
  local_28[0].y = fVar5 * 64.0 + local_34.y;
  local_28[0].x = fVar1 * 64.0 + local_34.x;
  UTIL_TraceLine(&local_34,local_28,ignore_monsters,pentIgnore,&local_6c);
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if ((peVar3->owner != (edict_t *)0x0) && (pOther->pev->takedamage != 0.0)) {
    (*pOther->_vptr_CBaseEntity[0xd])(pOther,peVar3,&peVar3->owner->v,peVar3->dmg,0x40);
  }
  (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[0x87])(this,&local_6c,0x40);
  return;
}


// CGrenade::DangerSoundThink  @ 000dc250  (line 292)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DangerSoundThink(CGrenade * this) */

void __thiscall CGrenade::DangerSoundThink(CGrenade *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  entvars_t *peVar4;
  float fVar5;
  Vector local_18;
  
  iVar3 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x26])(this);
  if (iVar3 == 0) {
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = (peVar4->velocity).x;
  fVar5 = (peVar4->velocity).y;
  fVar2 = (peVar4->velocity).z;
  fVar1 = fVar2 * fVar2 + fVar5 * fVar5 + fVar1 * fVar1;
  fVar5 = SQRT(fVar1);
  if (NAN(fVar5)) {
    fVar5 = sqrtf(fVar1);
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  local_18.z = (peVar4->velocity).z * 0.5 + (peVar4->origin).z;
  local_18.y = (peVar4->velocity).y * 0.5 + (peVar4->origin).y;
  local_18.x = (peVar4->velocity).x * 0.5 + (peVar4->origin).x;
  CSoundEnt::InsertSound(0x20,&local_18,(int)fVar5,0.2);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.2;
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar4->waterlevel != 0) {
    (peVar4->velocity).x = (peVar4->velocity).x * 0.5;
    (peVar4->velocity).y = (peVar4->velocity).y * 0.5;
    (peVar4->velocity).z = (peVar4->velocity).z * 0.5;
  }
  return;
}


// CGrenade::BounceTouch  @ 000dbb20  (line 310)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void BounceTouch(CGrenade * this, CBaseEntity * pOther) */

void __thiscall CGrenade::BounceTouch(CGrenade *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar3->owner != pOther->pev->pContainingEntity) {
    if ((peVar3->flags & 0x200) == 0) {
      if (this->m_bDontPlaySound == 0) {
                    /* WARNING: Could not recover jumptable at 0x000dbb70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity._vptr_CBaseEntity[0x8a])();
        return;
      }
    }
    else {
      (peVar3->velocity).x = (peVar3->velocity).x * 0.6;
      (peVar3->velocity).y = (peVar3->velocity).y * 0.6;
      (peVar3->velocity).z = (peVar3->velocity).z * 0.6;
      peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
      fVar1 = (peVar3->velocity).x;
      fVar4 = (peVar3->velocity).y;
      fVar2 = (peVar3->velocity).z;
      fVar1 = fVar2 * fVar2 + fVar4 * fVar4 + fVar1 * fVar1;
      fVar4 = SQRT(fVar1);
      if (NAN(fVar4)) {
        fVar4 = sqrtf(fVar1);
      }
      if (fVar4 <= 30.0) {
        this->m_bDontPlaySound = 1;
        return;
      }
    }
  }
  return;
}


// CGrenade::SlideTouch  @ 000dbac0  (line 336)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SlideTouch(CGrenade * this, CBaseEntity * pOther) */

void __thiscall CGrenade::SlideTouch(CGrenade *this,CBaseEntity *pOther)

{
  entvars_t *peVar1;
  
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar1->owner != pOther->pev->pContainingEntity) {
    if ((peVar1->flags & 0x200) == 0) {
                    /* WARNING: Could not recover jumptable at 0x000dbb1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity._vptr_CBaseEntity[0x8a])();
      return;
    }
    (peVar1->velocity).x = (peVar1->velocity).x * 0.95;
    (peVar1->velocity).y = (peVar1->velocity).y * 0.95;
    (peVar1->velocity).z = (peVar1->velocity).z * 0.95;
  }
  return;
}


// CGrenade::BounceSound  @ 000dbbf0  (line 360)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void BounceSound(CGrenade * this) */

void __thiscall CGrenade::BounceSound(CGrenade *this)

{
  int32 iVar1;
  char *sample;
  
  iVar1 = (*g_engfuncs.pfnRandomLong)(0,2);
  if (iVar1 == 1) {
    sample = "weapons/grenade_hit2.wav";
  }
  else if (iVar1 == 2) {
    sample = "weapons/grenade_hit3.wav";
  }
  else {
    if (iVar1 != 0) {
      return;
    }
    sample = "weapons/grenade_hit1.wav";
  }
  EMIT_SOUND_DYN(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay
                  .super_CBaseEntity.pev)->pContainingEntity,2,sample,0.25,0.8,0,100);
  return;
}


// CGrenade::TumbleThink  @ 000db990  (line 370)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TumbleThink(CGrenade * this) */

void __thiscall CGrenade::TumbleThink(CGrenade *this)

{
  float fVar1;
  float fVar2;
  globalvars_t *pgVar3;
  int iVar4;
  entvars_t *peVar5;
  Vector local_18;
  
  iVar4 = (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity._vptr_CBaseEntity[0x26])(this);
  if (iVar4 == 0) {
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  CBaseAnimating::StudioFrameAdvance((CBaseAnimating *)this,0.0);
  pgVar3 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->nextthink = gpGlobals->time + 0.1;
  peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar1 = peVar5->dmgtime;
  fVar2 = pgVar3->time;
  if (fVar1 - 1.0 < fVar2) {
    fVar1 = fVar1 - fVar2;
    local_18.z = (peVar5->velocity).z * fVar1 + (peVar5->origin).z;
    local_18.y = (peVar5->velocity).y * fVar1 + (peVar5->origin).y;
    local_18.x = fVar1 * (peVar5->velocity).x + (peVar5->origin).x;
    CSoundEnt::InsertSound(0x20,&local_18,400,0.1);
    peVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (gpGlobals->time < peVar5->dmgtime) goto LAB_000db9ff;
  }
  else if (fVar2 < fVar1) goto LAB_000db9ff;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Detonate;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
LAB_000db9ff:
  if (peVar5->waterlevel != 0) {
    (peVar5->velocity).x = (peVar5->velocity).x * 0.5;
    (peVar5->velocity).y = (peVar5->velocity).y * 0.5;
    (peVar5->velocity).z = (peVar5->velocity).z * 0.5;
    ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->framerate = 0.2;
  }
  return;
}


// CGrenade::Spawn  @ 000db5b0  (line 397)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CGrenade * this) */

void __thiscall CGrenade::Spawn(CGrenade *this)

{
  entvars_t *peVar1;
  globalvars_t *pgVar2;
  Vector local_24;
  Vector local_18;
  
  pgVar2 = gpGlobals;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 10;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (string_t)("tf_gl_grenade" + (6 - (int)pgVar2->pStringBase));
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 2;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/grenade.mdl");
  local_18.x = 0.0;
  local_18.y = 0.0;
  local_18.z = 0.0;
  local_24.x = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  this->m_bDontSpark = 0;
  this->m_bDontPlaySound = 0;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_flSmokeScale = 0.0;
  this->m_flExplosionScale = 0.0;
  peVar1->dmg = 100.0;
  this->m_fRegisteredSound = 0;
  this->m_usExplode = 0;
  return;
}


// CGrenade::ShootContact  @ 000dc820  (line 417)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CGrenade::ShootContact(entvars_t *pevOwner,Vector vecStart,Vector vecVelocity)

{
  globalvars_t *pgVar1;
  edict_t *peVar2;
  CGrenade *pCVar3;
  undefined **ppuVar4;
  entvars_t *peVar5;
  longdouble extraout_ST0;
  Vector local_18;
  
                    /* Unresolved local var: CGrenade * pGrenade@[DW_OP_reg7(EDI)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar2 = (*g_engfuncs.pfnCreateEntity)();
  peVar5 = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    peVar5 = &peVar2->v;
  }
  if ((peVar5->pContainingEntity == (edict_t *)0x0) ||
     (pCVar3 = peVar5->pContainingEntity->pvPrivateData, pCVar3 == (CGrenade *)0x0)) {
    pCVar3 = CBaseEntity::operator_new(0x6d8,peVar5);
    (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGrenade_001806e8;
    (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = peVar5;
    ppuVar4 = &PTR__CGrenade_001806e8;
  }
  else {
    ppuVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
  }
  (*(code *)ppuVar4[2])(pCVar3);
  ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->gravity = 0.5;
  UTIL_SetOrigin((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,(Vector *)vecStart.x);
  peVar5 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar5->velocity).x = *(vec_t *)vecStart.y;
  (peVar5->velocity).y = *(vec_t *)((int)vecStart.y + 4);
  (peVar5->velocity).z = *(vec_t *)((int)vecStart.y + 8);
  peVar5 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_VecToAngles(&local_18,&peVar5->velocity);
  (peVar5->angles).x = local_18.x;
  (peVar5->angles).y = local_18.y;
  (peVar5->angles).z = local_18.z;
  ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->owner = pevOwner->pContainingEntity;
  pgVar1 = gpGlobals;
  (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = DangerSoundThink;
  peVar5 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar5->nextthink = pgVar1->time;
  peVar5 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnRandomFloat)(-100.0,-500.0);
  (peVar5->avelocity).x = (float)extraout_ST0;
  (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = ExplodeTouch;
  peVar5 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar5->dmg = gSkillData.plrDmgM203Grenade;
  return pCVar3;
}


// CGrenade::ShootTimed  @ 000dc960  (line 444)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CGrenade::ShootTimed(entvars_t *pevOwner,Vector vecStart,Vector vecVelocity,float time)

{
  globalvars_t *pgVar1;
  edict_t *peVar2;
  int32 iVar3;
  CGrenade *pCVar4;
  undefined **ppuVar5;
  entvars_t *peVar6;
  Vector local_18;
  
                    /* Unresolved local var: CGrenade * pGrenade@[DW_OP_reg3(EBX)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar2 = (*g_engfuncs.pfnCreateEntity)();
  peVar6 = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    peVar6 = &peVar2->v;
  }
  if ((peVar6->pContainingEntity == (edict_t *)0x0) ||
     (pCVar4 = peVar6->pContainingEntity->pvPrivateData, pCVar4 == (CGrenade *)0x0)) {
    pCVar4 = CBaseEntity::operator_new(0x6d8,peVar6);
    (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGrenade_001806e8;
    (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = peVar6;
    ppuVar5 = &PTR__CGrenade_001806e8;
  }
  else {
    ppuVar5 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity._vptr_CBaseEntity;
  }
  (*(code *)ppuVar5[2])(pCVar4);
  UTIL_SetOrigin((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,(Vector *)vecStart.x);
  peVar6 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar6->velocity).x = *(vec_t *)vecStart.y;
  (peVar6->velocity).y = *(vec_t *)((int)vecStart.y + 4);
  (peVar6->velocity).z = *(vec_t *)((int)vecStart.y + 8);
  peVar6 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  UTIL_VecToAngles(&local_18,&peVar6->velocity);
  (peVar6->angles).x = local_18.x;
  (peVar6->angles).y = local_18.y;
  (peVar6->angles).z = local_18.z;
  ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->owner = pevOwner->pContainingEntity;
  pgVar1 = gpGlobals;
  (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = BounceTouch;
  peVar6 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar6->dmgtime = vecStart.z + pgVar1->time;
  (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = TumbleThink;
  peVar6 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar6->nextthink = pgVar1->time + 0.1;
  if (vecStart.z < 0.1) {
    ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
     super_CBaseEntity.pev)->nextthink = pgVar1->time;
    peVar6 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    (peVar6->velocity).x = 0.0;
    (peVar6->velocity).y = 0.0;
    (peVar6->velocity).z = 0.0;
  }
  peVar6 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar3 = (*g_engfuncs.pfnRandomLong)(3,6);
  peVar6->sequence = iVar3;
  ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->framerate = 1.0;
  peVar6 = (pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar6->avelocity).x = 0.0;
  (peVar6->avelocity).y = 0.0;
  (peVar6->avelocity).z = 0.0;
  ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->gravity = 0.5;
  ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->friction = 0.8;
  (*g_engfuncs.pfnSetModel)
            (((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/w_grenade.mdl");
  ((pCVar4->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->dmg = 100.0;
  return pCVar4;
}


// CGrenade::ShootSatchelCharge  @ 000dcb40  (line 484)

/* WARNING: Type propagation algorithm not settling */

CGrenade * CGrenade::ShootSatchelCharge(entvars_t *pevOwner,Vector vecStart,Vector vecVelocity)

{
  globalvars_t *pgVar1;
  edict_t *peVar2;
  CGrenade *pCVar3;
  entvars_t *peVar4;
  Vector local_24;
  Vector local_18;
  
                    /* Unresolved local var: CGrenade * pGrenade@[DW_OP_reg7(EDI)]
                       Unresolved local var: entvars_t * pev@[???] */
  peVar2 = (*g_engfuncs.pfnCreateEntity)();
  peVar4 = (entvars_t *)0x0;
  if (peVar2 != (edict_t *)0x0) {
    peVar4 = &peVar2->v;
  }
  if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
     (pCVar3 = peVar4->pContainingEntity->pvPrivateData, pCVar3 == (CGrenade *)0x0)) {
    pCVar3 = CBaseEntity::operator_new(0x6d8,peVar4);
    (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGrenade_001806e8;
    (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = peVar4;
  }
  else {
    peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  pgVar1 = gpGlobals;
  peVar4->movetype = 10;
  ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (string_t)("tf_gl_grenade" + (6 - (int)pgVar1->pStringBase));
  ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 2;
  (*g_engfuncs.pfnSetModel)
            (((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/grenade.mdl");
  local_18.y = 0.0;
  local_18.z = 0.0;
  local_24.y = 0.0;
  local_24.z = 0.0;
  local_18.x = 0.0;
  local_24.x = 0.0;
  UTIL_SetSize((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->dmg = 200.0;
  UTIL_SetOrigin((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                 super_CBaseDelay.super_CBaseEntity.pev,(Vector *)vecStart.x);
  peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->velocity).x = *(vec_t *)vecStart.y;
  (peVar4->velocity).y = *(vec_t *)((int)vecStart.y + 4);
  (peVar4->velocity).z = *(vec_t *)((int)vecStart.y + 8);
  peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->angles).x = g_vecZero.x;
  (peVar4->angles).y = g_vecZero.y;
  (peVar4->angles).z = g_vecZero.z;
  ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->owner = pevOwner->pContainingEntity;
  peVar4 = (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = CBaseEntity::SUB_DoNothing;
  (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__pfn = DetonateUse;
  (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnUse.__delta = 0;
  (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = SlideTouch;
  (pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  peVar4->spawnflags = 1;
  ((pCVar3->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->friction = 0.9;
  return pCVar3;
}


// CGrenade::UseSatchelCharges  @ 000dccf0  (line 515)

void CGrenade::UseSatchelCharges(entvars_t *pevOwner,SATCHELCODE code)

{
  entvars_t *peVar1;
  CBaseEntity *pStartEntity;
  edict_t *peVar2;
  void *pvVar3;
  
                    /* Unresolved local var: edict_t * pentOwner@[DW_OP_reg3(EBX)]
                       Unresolved local var: CBaseEntity * pOwner@[DW_OP_reg6(ESI)]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pevOwner != (entvars_t *)0x0) {
    peVar2 = pevOwner->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar2 == (edict_t *)0x0) &&
       (peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar2 == (edict_t *)0x0)) {
      pvVar3 = (void *)0x0;
    }
    else {
      pvVar3 = peVar2->pvPrivateData;
    }
    peVar2 = *(edict_t **)(*(int *)((int)pvVar3 + 4) + 0x208);
    pStartEntity = UTIL_FindEntityByClassname((CBaseEntity *)0x0,"grenade");
    if (pStartEntity != (CBaseEntity *)0x0) {
      if (code == SATCHEL_DETONATE) {
        do {
          if (((pStartEntity->pev->spawnflags & 1) != 0) && (pStartEntity->pev->owner == peVar2)) {
            (*pStartEntity->_vptr_CBaseEntity[0x2d])(pStartEntity,pvVar3,pvVar3,1,0);
          }
          pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"grenade");
        } while (pStartEntity != (CBaseEntity *)0x0);
        return;
      }
      do {
        peVar1 = pStartEntity->pev;
        if (((peVar1->spawnflags & 1) != 0) && (peVar1->owner == peVar2)) {
          peVar1->owner = (edict_t *)0x0;
        }
        pStartEntity = UTIL_FindEntityByClassname(pStartEntity,"grenade");
      } while (pStartEntity != (CBaseEntity *)0x0);
    }
  }
  return;
}


