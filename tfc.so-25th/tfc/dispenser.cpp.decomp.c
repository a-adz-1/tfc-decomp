// Ghidra decompilation of functions from tfc/dispenser.cpp
// 19 functions, ordered by original source line

// building_dispenser  @ 000861b0  (line 34)

void building_dispenser(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x6d0,pev);
  *puVar1 = &PTR__CTFDispenser_0014b4f8;
  puVar1[1] = pev;
  return;
}


// CTFDispenser::Spawn  @ 00085ed0  (line 39)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Spawn(CTFDispenser * this) */

void __thiscall CTFDispenser::Spawn(CTFDispenser *this)

{
  int *piVar1;
  _func_int_varargs *p_Var2;
  entvars_t *peVar3;
  ushort uVar4;
  int iVar5;
  Vector local_24;
  Vector local_18;
  
  p_Var2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity._vptr_CBaseEntity[3];
  if (p_Var2 == Precache) {
    (*g_engfuncs.pfnPrecacheModel)("models/dispenser.mdl");
    iVar5 = (*g_engfuncs.pfnPrecacheModel)("models/computergibs.mdl");
    this->m_iShardIndex = iVar5;
    uVar4 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/misc/tf_buildingevent.sc");
    (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.m_usBuildingEvent = uVar4;
  }
  else {
    (*p_Var2)(this);
  }
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->classname = (int)"building_dispenser" - (int)gpGlobals->pStringBase;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->solid = 2;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->movetype = 6;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 & 0xfffffdff;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar3->velocity).x = 0.0;
  (peVar3->velocity).y = 0.0;
  (peVar3->velocity).z = 8.0;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->max_health = 150.0;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar3->health = peVar3->max_health;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 0.0;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 | 0x20;
  (*g_engfuncs.pfnSetModel)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,"models/dispenser.mdl");
  local_18.x = 16.0;
  local_18.y = 16.0;
  local_18.z = 24.0;
  local_24.x = -16.0;
  local_24.y = -16.0;
  local_24.z = 0.0;
  UTIL_SetSize((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev,&local_24,&local_18);
  return;
}


// CTFDispenser::Remove  @ 00086220  (line 60)

/* DWARF original prototype: void Remove(CTFDispenser * this) */

void __thiscall CTFDispenser::Remove(CTFDispenser *this)

{
  entvars_t *peVar1;
  CBaseEntity *pCVar2;
  char *pcVar3;
  int iVar4;
  edict_t *peVar5;
  void *pvVar6;
  char *pcVar7;
  
                    /* Unresolved local var: CBasePlayer * pOwner@[???] */
  pCVar2 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                                super_CBaseDelay.super_CBaseEntity.real_owner);
  peVar5 = pCVar2->pev->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (peVar5 == (edict_t *)0x0) {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
    if (peVar5 == (edict_t *)0x0) {
      pvVar6 = (void *)0x0;
      goto LAB_0008624d;
    }
  }
  pvVar6 = peVar5->pvPrivateData;
LAB_0008624d:
  if (*(int *)((int)pvVar6 + 0xe58) == 0) {
    ClientPrint(*(entvars_t **)((int)pvVar6 + 4),4,"#Dispenser_destroyed",(char *)0x0,(char *)0x0,
                (char *)0x0,(char *)0x0);
  }
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  pcVar7 = "SPECTATOR";
  (*g_engfuncs.pfnPlaybackEvent)
            (6,peVar1->pContainingEntity,
             (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar1->origin).x,&g_vecZero.x,0.0,0.0,0x400,
             0,0,0);
  if (*(int *)((int)pvVar6 + 0x138) != 0) {
    pcVar7 = GetTeamName(*(int *)((int)pvVar6 + 0x138));
  }
  pcVar3 = (*g_engfuncs.pfnGetPlayerAuthId)(*(edict_t **)(*(int *)((int)pvVar6 + 4) + 0x208));
  iVar4 = (*g_engfuncs.pfnGetPlayerUserId)(*(edict_t **)(*(int *)((int)pvVar6 + 4) + 0x208));
  UTIL_LogPrintf("\"<-1><><>\" triggered \"Dispenser_destroyed\" against \"%s<%i><%s><%s>\"\n",
                 gpGlobals->pStringBase + *(int *)(*(int *)((int)pvVar6 + 4) + 0x1d0),iVar4,pcVar3,
                 pcVar7);
  *(undefined4 *)((int)pvVar6 + 0xe58) = 0;
  *(undefined4 *)((int)pvVar6 + 0x164) = 0;
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
  (*g_engfuncs.pfnWriteByte)(0x1e);
  (*g_engfuncs.pfnWriteByte)(0xf);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnMessageEnd)();
  dremove((CBaseEntity *)this);
  return;
}


// CTFDispenser::Precache  @ 00085230  (line 97)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Precache(CTFDispenser * this) */

void __thiscall CTFDispenser::Precache(CTFDispenser *this)

{
  ushort uVar1;
  int iVar2;
  
  (*g_engfuncs.pfnPrecacheModel)("models/dispenser.mdl");
  iVar2 = (*g_engfuncs.pfnPrecacheModel)("models/computergibs.mdl");
  this->m_iShardIndex = iVar2;
  uVar1 = (*g_engfuncs.pfnPrecacheEvent)(1,"events/misc/tf_buildingevent.sc");
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_usBuildingEvent = uVar1;
  return;
}


// CTFDispenser::CreateDispenser  @ 00086460  (line 108)

/* WARNING: Type propagation algorithm not settling */

CTFDispenser * CTFDispenser::CreateDispenser(Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner)

{
  edict_t *peVar1;
  CTFDispenser *pCVar2;
  entvars_t *peVar3;
  float fVar4;
  
                    /* Unresolved local var: CTFDispenser * pBase@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: entvars_t * pev@[???] */
  peVar1 = (*g_engfuncs.pfnCreateEntity)();
  peVar3 = (entvars_t *)0x0;
  if (peVar1 != (edict_t *)0x0) {
    peVar3 = &peVar1->v;
  }
  if ((peVar3->pContainingEntity == (edict_t *)0x0) ||
     (pCVar2 = peVar3->pContainingEntity->pvPrivateData, pCVar2 == (CTFDispenser *)0x0)) {
    pCVar2 = CBaseEntity::operator_new(0x6d0,peVar3);
    (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFDispenser_0014b4f8;
    (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.pev = peVar3;
  }
  else {
    peVar3 = (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  UTIL_SetOrigin(peVar3,(Vector *)vecOrigin.x);
  peVar3 = (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar3->angles).y = 0.0;
  (peVar3->angles).x = 0.0;
  (peVar3->angles).z = 0.0;
  peVar3 = (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar4 = UTIL_AngleMod(*(float *)(*(int *)((int)vecOrigin.z + 4) + 0x54) + 180.0);
  (peVar3->angles).y = fVar4;
  (*(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity._vptr_CBaseEntity[2])(pCVar2);
  EHANDLE::operator=(&(pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.real_owner,(CBaseEntity *)vecOrigin.z);
  (pCVar2->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.team_no = *(int *)((int)vecOrigin.z + 0x138);
  pCVar2->m_iDestroyed = 0;
  pCVar2->m_flNextUseTime = gpGlobals->time + 3.0;
  return pCVar2;
}


// CTFDispenser::Finished  @ 000854b0  (line 127)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Finished(CTFDispenser * this) */

void __thiscall CTFDispenser::Finished(CTFDispenser *this)

{
  EHANDLE *this_00;
  int *piVar1;
  char *pcVar2;
  string_t sVar3;
  entvars_t *peVar4;
  _2globalvars_t *p1Var5;
  _func_int_edict_t_ptr *p_Var6;
  _func_char_ptr_edict_t_ptr *p_Var7;
  CBaseEntity *pCVar8;
  double dVar9;
  
                    /* try { // try from 000854b7 to 000954bb has its CatchHandler @ 00085440 */
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.real_owner;
  pCVar8 = EHANDLE::operator->(this_00);
  pCVar8->has_dispenser = 1.0;
  pCVar8 = EHANDLE::operator->(this_00);
  ClientPrint(pCVar8->pev,1,"#Dispenser_finish",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
  pcVar2 = gpGlobals->pStringBase;
  pCVar8 = EHANDLE::operator->(this_00);
  sVar3 = pCVar8->pev->netname;
  pCVar8 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  teamsprint((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.team_no,pCVar8,1,"#Dispenser_built",pcVar2 + sVar3,(char *)0x0,
             (char *)0x0);
  pCVar8 = EHANDLE::operator->(this_00);
  if (pCVar8->team_no != 0) {
    pCVar8 = EHANDLE::operator->(this_00);
    GetTeamName(pCVar8->team_no);
  }
  p_Var7 = g_engfuncs.pfnGetPlayerAuthId;
  pCVar8 = EHANDLE::operator->(this_00);
  (*p_Var7)(pCVar8->pev->pContainingEntity);
  p_Var6 = g_engfuncs.pfnGetPlayerUserId;
  pCVar8 = EHANDLE::operator->(this_00);
  (*p_Var6)(pCVar8->pev->pContainingEntity);
  EHANDLE::operator->(this_00);
  UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Built_Dispenser\"\n");
  pCVar8 = EHANDLE::operator->(this_00);
  pCVar8->ammo_cells = pCVar8->ammo_cells + -100;
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->takedamage = 2.0;
  p1Var5 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__pfn = DispenserTouch;
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnTouch.__delta = 0;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = DispenserThink;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar4->nextthink = p1Var5->time + 0.1;
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_flNextRefillTime = p1Var5->time + 12.0;
  peVar4->movetype = 6;
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (peVar4->velocity).x = 0.0;
  (peVar4->velocity).y = 0.0;
  (peVar4->velocity).z = 8.0;
  piVar1 = &((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->flags;
  *piVar1 = *piVar1 & 0xfffffdff;
  pCVar8 = EHANDLE::operator->(this_00);
  dVar9 = ceil((double)pCVar8->ammo_shells * 0.25);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_shells = (int)dVar9;
  pCVar8 = EHANDLE::operator->(this_00);
  dVar9 = ceil((double)pCVar8->ammo_nails * 0.25);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_nails = (int)dVar9;
  pCVar8 = EHANDLE::operator->(this_00);
  dVar9 = ceil((double)pCVar8->ammo_rockets * 0.25);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_rockets = (int)dVar9;
  pCVar8 = EHANDLE::operator->(this_00);
  dVar9 = ceil((double)pCVar8->ammo_cells * 0.25);
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_cells = (int)dVar9;
  pCVar8 = EHANDLE::operator->(this_00);
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
  peVar4->armorvalue = ROUND(pCVar8->pev->armorvalue * 0.25);
  pCVar8 = EHANDLE::operator->(this_00);
  dVar9 = ceil((double)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.ammo_shells * 0.75);
  pCVar8->ammo_shells = (int)dVar9;
  pCVar8 = EHANDLE::operator->(this_00);
  dVar9 = ceil((double)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.ammo_nails * 0.75);
  pCVar8->ammo_nails = (int)dVar9;
  pCVar8 = EHANDLE::operator->(this_00);
  dVar9 = ceil((double)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.ammo_rockets * 0.75);
  pCVar8->ammo_rockets = (int)dVar9;
  pCVar8 = EHANDLE::operator->(this_00);
  dVar9 = ceil((double)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.ammo_cells * 0.75);
  pCVar8->ammo_cells = (int)dVar9;
  pCVar8 = EHANDLE::operator->(this_00);
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
  pCVar8->pev->armorvalue =
       ROUND(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->armorvalue * 0.75);
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_vOldOrigin.x = (peVar4->origin).x;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_vOldOrigin.y = (peVar4->origin).y;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_vOldOrigin.z = (peVar4->origin).z;
  EMIT_SOUND_DYN(peVar4->pContainingEntity,1,"weapons/turrset.wav",1.0,0.8,0,100);
  return;
}


// GetWeapon  @ 00086550  (line 174)

void GetWeapon(entvars_t *pevInflictor,entvars_t *pKiller,char *weapon)

{
  int *piVar1;
  edict_t *peVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  byte *__src;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  undefined1 local_38 [24];
  byte *local_20;
  
                    /* Unresolved local var: CBaseEntity * Killer@[???]
                       Unresolved local var: char * killer_weapon_name@[???]
                       Unresolved local var: int killer_index@[???] */
  bVar10 = 0;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pKiller->pContainingEntity == (edict_t *)0x0) {
    (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  }
  if ((pKiller->flags & 8) == 0) {
LAB_00086579:
    peVar2 = pevInflictor->pContainingEntity;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((((peVar2 == (edict_t *)0x0) &&
         (peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar2 == (edict_t *)0x0)) ||
        (peVar2->pvPrivateData == (void *)0x0)) ||
       (uVar5 = *(uint *)((int)peVar2->pvPrivateData + 0x418), uVar5 == 0)) {
      uVar5 = pevInflictor->classname;
    }
LAB_0008659c:
    bVar8 = CARRY4(uVar5,(uint)gpGlobals->pStringBase);
    __src = (byte *)(gpGlobals->pStringBase + uVar5);
    bVar9 = __src == (byte *)0x0;
  }
  else {
    (*g_engfuncs.pfnIndexOfEdict)(pKiller->pContainingEntity);
    if (pevInflictor == (entvars_t *)0x0) {
LAB_000866e8:
      __src = (byte *)"world";
      goto LAB_00086633;
    }
    if (pKiller != pevInflictor) goto LAB_00086579;
    peVar2 = pKiller->pContainingEntity;
                    /* Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
    if ((peVar2 == (edict_t *)0x0) &&
       (peVar2 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar2 == (edict_t *)0x0)) {
      pvVar3 = (void *)0x0;
    }
    else {
      pvVar3 = peVar2->pvPrivateData;
    }
    piVar1 = *(int **)((int)pvVar3 + 0x8fc);
    if (piVar1 == (int *)0x0) goto LAB_000866e8;
    uVar5 = piVar1[0x106];
    if (uVar5 != 0) goto LAB_0008659c;
                    /* Unresolved local var: ItemInfo II@[???] */
    iVar4 = (**(code **)(*piVar1 + 0x114))(piVar1,local_38);
    bVar8 = false;
    bVar9 = iVar4 == 0;
    __src = (byte *)"world";
    if (!bVar9) {
      __src = local_20;
    }
  }
  iVar4 = 7;
  pbVar6 = __src;
  pbVar7 = (byte *)0x1494b6;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar8 = *pbVar6 < *pbVar7;
    bVar9 = *pbVar6 == *pbVar7;
    pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
    pbVar7 = pbVar7 + (uint)bVar10 * -2 + 1;
  } while (bVar9);
  if (bVar9) {
    __src = __src + 7;
  }
  else {
    iVar4 = 10;
    bVar9 = false;
    pbVar6 = __src;
    pbVar7 = (byte *)"tf_weapon_";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pbVar6 < *pbVar7;
      bVar9 = *pbVar6 == *pbVar7;
      pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
      pbVar7 = pbVar7 + (uint)bVar10 * -2 + 1;
    } while (bVar9);
    if (bVar9) {
      __src = __src + 10;
    }
    else {
      iVar4 = 8;
      bVar9 = false;
      pbVar6 = __src;
      pbVar7 = (byte *)"monster_";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pbVar6 < *pbVar7;
        bVar9 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
        pbVar7 = pbVar7 + (uint)bVar10 * -2 + 1;
      } while (bVar9);
      if (bVar9) {
        __src = __src + 8;
      }
      else {
        iVar4 = 5;
        bVar9 = false;
        pbVar6 = __src;
        pbVar7 = &DAT_0014b358;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar8 = *pbVar6 < *pbVar7;
          bVar9 = *pbVar6 == *pbVar7;
          pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
          pbVar7 = pbVar7 + (uint)bVar10 * -2 + 1;
        } while (bVar9);
        if ((!bVar8 && !bVar9) == bVar8) {
          __src = __src + 5;
        }
      }
    }
  }
LAB_00086633:
  strcpy(weapon,(char *)__src);
  return;
}


// CTFDispenser::Killed  @ 00086710  (line 252)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Killed(CTFDispenser * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CTFDispenser::Killed(CTFDispenser *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  EHANDLE *this_00;
  entvars_t *peVar1;
  string_t sVar2;
  _2globalvars_t *p1Var3;
  _func_int_edict_t_ptr *p_Var4;
  _func_char_ptr_edict_t_ptr *p_Var5;
  CBaseEntity *pCVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  edict_t *peVar11;
  char *pcVar12;
  char *pcVar13;
  int in_GS_OFFSET;
  void *local_60;
  char *local_5c;
  char local_3e [30];
  int local_20;
  
                    /* Unresolved local var: char[30] weapon@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (this->m_iDestroyed != 0) goto LAB_0008675d;
                    /* Unresolved local var: char[30] weapon@[???] */
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.real_owner;
  pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  if (pCVar6[3].ammo_rockets == 0) {
    pCVar6 = EHANDLE::operator->(this_00);
    ClientPrint(pCVar6->pev,4,"#Dispenser_destroyed",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0
               );
  }
  pCVar6 = EHANDLE::operator->(this_00);
  pCVar6->has_dispenser = 0.0;
  pCVar6 = EHANDLE::operator_cast_to_CBaseEntity_(this_00);
  pCVar6[3].ammo_rockets = 0;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (*g_engfuncs.pfnPlaybackEvent)
            (6,peVar1->pContainingEntity,
             (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.m_usBuildingEvent,0.0,&(peVar1->origin).x,&g_vecZero.x,0.0,0.0,0x400,
             0,0,0);
  p1Var3 = gpGlobals;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__pfn = Dispenser_Explode;
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.m_pfnThink.__delta = 0;
  peVar1->nextthink = p1Var3->time + 0.1;
  if (pevAttacker != (entvars_t *)0x0) {
    iVar7 = EHANDLE::operator_int(this_00);
    if (iVar7 != 0) {
      peVar11 = pevAttacker->pContainingEntity;
                    /* Unresolved local var: CBasePlayer * pPlayer@[???]
                       Unresolved local var: CBaseEntity * pEnt@[???] */
      if (peVar11 == (edict_t *)0x0) {
        peVar11 = (*g_engfuncs.pfnPEntityOfEntOffset)(0);
        if (peVar11 != (edict_t *)0x0) goto LAB_00086889;
        local_60 = (void *)0x0;
      }
      else {
LAB_00086889:
        local_60 = peVar11->pvPrivateData;
      }
      GetWeapon(pevInflictor,pevAttacker,local_3e);
      if (pevAttacker == pevInflictor) {
        pCVar6 = EHANDLE::operator->(this_00);
        pcVar13 = "SPECTATOR";
        if (pCVar6->team_no != 0) {
          pCVar6 = EHANDLE::operator->(this_00);
          pcVar13 = GetTeamName(pCVar6->team_no);
        }
        p_Var5 = g_engfuncs.pfnGetPlayerAuthId;
        pCVar6 = EHANDLE::operator->(this_00);
        pcVar12 = (*p_Var5)(pCVar6->pev->pContainingEntity);
        p_Var4 = g_engfuncs.pfnGetPlayerUserId;
        pCVar6 = EHANDLE::operator->(this_00);
        iVar7 = (*p_Var4)(pCVar6->pev->pContainingEntity);
        pcVar8 = gpGlobals->pStringBase;
        pCVar6 = EHANDLE::operator->(this_00);
        UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Dispenser_Destroyed\"\n",
                       pcVar8 + pCVar6->pev->netname,iVar7,pcVar12,pcVar13);
      }
      else {
        pCVar6 = EHANDLE::operator->(this_00);
        if (pevAttacker != pCVar6->pev) {
          pCVar6 = EHANDLE::operator->(this_00);
          local_5c = "SPECTATOR";
          if (pCVar6->team_no != 0) {
            pCVar6 = EHANDLE::operator->(this_00);
            local_5c = GetTeamName(pCVar6->team_no);
          }
          p_Var5 = g_engfuncs.pfnGetPlayerAuthId;
          pCVar6 = EHANDLE::operator->(this_00);
          pcVar8 = (*p_Var5)(pCVar6->pev->pContainingEntity);
          p_Var4 = g_engfuncs.pfnGetPlayerUserId;
          pCVar6 = EHANDLE::operator->(this_00);
          iVar7 = (*p_Var4)(pCVar6->pev->pContainingEntity);
          pcVar13 = gpGlobals->pStringBase;
          pCVar6 = EHANDLE::operator->(this_00);
          sVar2 = pCVar6->pev->netname;
          pcVar12 = "SPECTATOR";
          if (*(int *)((int)local_60 + 0x138) != 0) {
            pcVar12 = GetTeamName(*(int *)((int)local_60 + 0x138));
          }
          pcVar9 = (*g_engfuncs.pfnGetPlayerAuthId)(pevAttacker->pContainingEntity);
          iVar10 = (*g_engfuncs.pfnGetPlayerUserId)(pevAttacker->pContainingEntity);
          UTIL_LogPrintf("\"%s<%i><%s><%s>\" triggered \"Dispenser_Destroyed\" against \"%s<%i><%s><%s>\" with \"%s\"\n"
                         ,gpGlobals->pStringBase + pevAttacker->netname,iVar10,pcVar9,pcVar12,
                         pcVar13 + sVar2,iVar7,pcVar8,local_5c,local_3e);
        }
      }
    }
  }
  this->m_iDestroyed = 1;
LAB_0008675d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CTFDispenser::Dispenser_Explode  @ 000852c0  (line 315)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Dispenser_Explode(CTFDispenser * this) */

void __thiscall CTFDispenser::Dispenser_Explode(CTFDispenser *this)

{
  EHANDLE *this_00;
  _func_int_varargs *p_Var1;
  float fVar2;
  CBaseEntity *pCVar3;
  
                    /* catch() { ... } // from try @ 00085313 with catch @ 000852c0
                       catch() { ... } // from try @ 000853c7 with catch @ 000852c0 */
  this_00 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.real_owner;
  (*g_engfuncs.pfnMessageBegin)
            (4,0x17,&(((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                       super_CBaseDelay.super_CBaseEntity.pev)->origin).x,(edict_t *)0x0);
  (*g_engfuncs.pfnWriteByte)(0x6b);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).x);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).y);
  (*g_engfuncs.pfnWriteCoord)
            ((((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev)->origin).z);
  (*g_engfuncs.pfnWriteCoord)(400.0);
  (*g_engfuncs.pfnWriteShort)(this->m_iShardIndex);
  (*g_engfuncs.pfnWriteShort)(10);
  (*g_engfuncs.pfnWriteByte)(0x19);
  (*g_engfuncs.pfnMessageEnd)();
  pCVar3 = EHANDLE::operator->(this_00);
  if (pCVar3->has_disconnected != 1) {
    fVar2 = (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.ammo_cells +
            (float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.ammo_rockets * 1.5 + 25.0;
    if (250.0 < fVar2) {
      fVar2 = 250.0;
    }
    p_Var1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity._vptr_CBaseEntity[0x7f];
    pCVar3 = EHANDLE::operator->(this_00);
    (*p_Var1)(this,(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.pev,pCVar3->pev,fVar2,0,0x4000040);
  }
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
  (*g_engfuncs.pfnWriteByte)(0x1e);
  (*g_engfuncs.pfnWriteByte)(0xf);
  (*g_engfuncs.pfnWriteByte)(3);
  (*g_engfuncs.pfnMessageEnd)();
  dremove((CBaseEntity *)this);
  return;
}


// CDispenserRefillThinker::~CDispenserRefillThinker  @ 00087000  (line 357)

/* DWARF original prototype: void ~CDispenserRefillThinker(CDispenserRefillThinker * this, int
   __in_chrg) */

void __thiscall
CDispenserRefillThinker::~CDispenserRefillThinker(CDispenserRefillThinker *this,int __in_chrg)

{
  return;
}


// CDispenserRefillThinker::Spawn  @ 00085280  (line 371)

/* DWARF original prototype: void Spawn(CDispenserRefillThinker * this) */

void __thiscall CDispenserRefillThinker::Spawn(CDispenserRefillThinker *this)

{
  ((this->super_CBaseEntity).pev)->classname =
       (string_t)("ak_timer" + (3 - (int)gpGlobals->pStringBase));
  (this->super_CBaseEntity).timer_type = 0xe;
  return;
}


// CDispenserRefillThinker::Think  @ 00086ef0  (line 378)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Think(CDispenserRefillThinker * this) */

void __thiscall CDispenserRefillThinker::Think(CDispenserRefillThinker *this)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  CBasePlayer *pPlayer;
  CTFDispenser *this_00;
  BOOL BVar4;
  float fVar5;
  
                    /* Unresolved local var: CBasePlayer * pl@[???]
                       Unresolved local var: CTFDispenser * disp@[???]
                       Unresolved local var: bool bDestroyTimer@[???] */
  pPlayer = (CBasePlayer *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hPlayer);
  this_00 = (CTFDispenser *)EHANDLE::operator_cast_to_CBaseEntity_(&this->m_hDispenser);
  if (((pPlayer != (CBasePlayer *)0x0) && (this_00 != (CTFDispenser *)0x0)) &&
     (this_00->m_flNextUseTime <= gpGlobals->time + 1.5)) {
                    /* Unresolved local var: Vector moved@[???] */
    peVar1 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    fVar2 = (peVar1->origin).z - (this->m_InitialUsePoint).z;
    fVar3 = (peVar1->origin).y - (this->m_InitialUsePoint).y;
    fVar5 = (peVar1->origin).x - (this->m_InitialUsePoint).x;
    fVar2 = fVar2 * fVar2 + fVar3 * fVar3 + fVar5 * fVar5;
    fVar5 = SQRT(fVar2);
    if (NAN(fVar5)) {
      fVar5 = sqrtf(fVar2);
    }
    if ((fVar5 <= 24.0) && (BVar4 = CTFDispenser::RefillPlayer(this_00,pPlayer), BVar4 != 0)) {
      ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + 1.0;
      return;
    }
  }
  UTIL_Remove(&this->super_CBaseEntity);
  return;
}


// CDispenserRefillThinker::StartRefillingPlayer  @ 00086b50  (line 430)

/* DWARF original prototype: void StartRefillingPlayer(CDispenserRefillThinker * this, CBaseEntity *
   pPlayer, CTFDispenser * pDispenser, float flStartTime) */

void __thiscall
CDispenserRefillThinker::StartRefillingPlayer
          (CDispenserRefillThinker *this,CBaseEntity *pPlayer,CTFDispenser *pDispenser,
          float flStartTime)

{
  entvars_t *peVar1;
  
  ((this->super_CBaseEntity).pev)->nextthink = gpGlobals->time + flStartTime;
  EHANDLE::operator=(&this->m_hDispenser,(CBaseEntity *)pDispenser);
  EHANDLE::operator=(&this->m_hPlayer,pPlayer);
  peVar1 = pPlayer->pev;
  (this->m_InitialUsePoint).x = (peVar1->origin).x;
  (this->m_InitialUsePoint).y = (peVar1->origin).y;
  (this->m_InitialUsePoint).z = (peVar1->origin).z;
  return;
}


// dispenser_refill_timer  @ 00086bc0  (line 438)

void dispenser_refill_timer(entvars_t *pev)

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
  puVar1 = CBaseEntity::operator_new(0x490,pev);
  *puVar1 = &PTR__CDispenserRefillThinker_0014b718;
  puVar1[1] = pev;
  return;
}


// CTFDispenser::DispenserTouch  @ 00086040  (line 443)

/* DWARF original prototype: void DispenserTouch(CTFDispenser * this, CBaseEntity * pOther) */

void __thiscall CTFDispenser::DispenserTouch(CTFDispenser *this,CBaseEntity *pOther)

{
  CBaseEntity *pCVar1;
  edict_t *peVar2;
  undefined4 *puVar3;
  entvars_t *peVar4;
  
  if ((pOther->pev->flags & 8) != 0) {
    if ((pOther->team_no != 0) &&
       (pOther->team_no !=
        (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
        super_CBaseEntity.team_no)) {
      pCVar1 = EHANDLE::operator->(&(this->super_CBaseMonster).super_CBaseToggle.
                                    super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                                    real_owner);
      ClientPrint(pCVar1->pev,4,"#Dispenser_used",(char *)0x0,(char *)0x0,(char *)0x0,(char *)0x0);
    }
    if (this->m_flNextUseTime <= gpGlobals->time) {
      pCVar1 = CBaseEntity::FindTimer((CBaseEntity *)this,0xe);
      if (pCVar1 == (CBaseEntity *)0x0) {
                    /* Unresolved local var: CDispenserRefillThinker * pTimer@[DW_OP_reg7(EDI)]
                       Unresolved local var: entvars_t * pev@[???] */
        peVar2 = (*g_engfuncs.pfnCreateEntity)();
        peVar4 = &peVar2->v;
        if (peVar2 == (edict_t *)0x0) {
          peVar4 = (entvars_t *)0x0;
        }
        if ((peVar4->pContainingEntity == (edict_t *)0x0) ||
           (puVar3 = peVar4->pContainingEntity->pvPrivateData, puVar3 == (undefined4 *)0x0)) {
          puVar3 = CBaseEntity::operator_new(0x490,peVar4);
          *puVar3 = &PTR__CDispenserRefillThinker_0014b718;
          puVar3[1] = peVar4;
        }
        else {
          peVar4 = (entvars_t *)puVar3[1];
        }
        peVar4->nextthink = gpGlobals->time + 0.2;
        EHANDLE::operator=((EHANDLE *)(puVar3 + 0x11d),(CBaseEntity *)this);
        EHANDLE::operator=((EHANDLE *)(puVar3 + 0x11f),pOther);
        peVar4 = pOther->pev;
        puVar3[0x121] = (peVar4->origin).x;
        puVar3[0x122] = (peVar4->origin).y;
        puVar3[0x123] = (peVar4->origin).z;
      }
      this->m_flNextUseTime = gpGlobals->time + 1.0;
    }
  }
  return;
}


// CTFDispenser::RefillPlayer  @ 00086c30  (line 473)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL RefillPlayer(CTFDispenser * this, CBasePlayer * pPlayer) */

BOOL __thiscall CTFDispenser::RefillPlayer(CTFDispenser *this,CBasePlayer *pPlayer)

{
  int *piVar1;
  float fVar2;
  entvars_t *peVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int shells;
  int iVar7;
  int iVar8;
  bool bVar9;
  int local_24;
  
                    /* Unresolved local var: int totalam@[???]
                       Unresolved local var: bool empty@[???]
                       Unresolved local var: CTFDispenser * building@[???]
                       Unresolved local var: int iShells@[???]
                       Unresolved local var: int iNails@[???]
                       Unresolved local var: int iRockets@[???]
                       Unresolved local var: int iCells@[???]
                       Unresolved local var: int am@[???] */
  iVar7 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_shells;
  iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_nails;
  iVar5 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_rockets;
  if ((iVar7 == 0) && (iVar6 == 0)) {
    local_24 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells;
    if (iVar5 == 0) {
      if (local_24 == 0) {
        if (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev)->armorvalue == 0.0) {
          ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.pev,1,"#Dispenser_empty",(char *)0x0,
                      (char *)0x0,(char *)0x0,(char *)0x0);
          return 0;
        }
        iVar5 = 0;
        iVar6 = 0;
      }
      else {
        iVar6 = 0;
      }
    }
  }
  else {
    local_24 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.ammo_cells;
  }
  iVar8 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_shells -
          (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_shells;
  shells = 0x14;
  if (iVar7 < 0x15) {
    shells = iVar7;
  }
  if (iVar8 <= shells) {
    shells = iVar8;
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_shells = iVar7 - shells;
  iVar7 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_nails -
          (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_nails;
  if (0x14 < iVar7) {
    iVar7 = 0x14;
  }
  if (iVar6 < iVar7) {
    iVar7 = iVar6;
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_nails = iVar6 - iVar7;
  iVar6 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_rockets -
          (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_rockets;
  if (10 < iVar6) {
    iVar6 = 10;
  }
  if (iVar5 < iVar6) {
    iVar6 = iVar5;
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_rockets = iVar5 - iVar6;
  iVar5 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxammo_cells;
  if (((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
       super_CBaseEntity.pev)->playerclass == 9) {
    iVar5 = iVar5 - (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_cells;
    if (0x4b < iVar5) {
      iVar5 = 0x4b;
    }
    if (local_24 < iVar5) {
      iVar5 = local_24;
    }
  }
  else {
    iVar5 = iVar5 - (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_cells;
    if (10 < iVar5) {
      iVar5 = 10;
    }
    if (local_24 < iVar5) {
      iVar5 = local_24;
    }
  }
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_cells = local_24 - iVar5;
  CBasePlayer::GiveTFAmmo(pPlayer,shells,iVar7,iVar6,iVar5);
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar4 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.maxarmor -
          ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev)->armorvalue;
  fVar2 = peVar3->armorvalue;
  if (fVar2 < fVar4) {
    fVar4 = fVar2;
  }
  if (20.0 < fVar4) {
    fVar4 = 20.0;
    iVar8 = 0x14;
  }
  else {
    iVar8 = (int)fVar4;
    fVar4 = (float)iVar8;
  }
  peVar3->armorvalue = fVar2 - fVar4;
  peVar3 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  peVar3->armorvalue = fVar4 + peVar3->armorvalue;
  peVar3 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  if (peVar3->armortype == 0.0) {
    peVar3->armortype = 0.3;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.items;
    *piVar1 = *piVar1 | 0x2000;
  }
  bVar9 = shells + iVar7 + iVar6 + iVar5 + iVar8 != 0;
  if (bVar9) {
    EMIT_SOUND_DYN(((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.pev)->pContainingEntity,3,
                   "items/ammopickup2.wav",1.0,0.8,0,100);
  }
  local_24 = (int)bVar9;
  return local_24;
}


// CTFDispenser::DispenserThink  @ 00085920  (line 542)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void DispenserThink(CTFDispenser * this) */

void __thiscall CTFDispenser::DispenserThink(CTFDispenser *this)

{
  int *piVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  entvars_t *peVar4;
  
  CBaseEntity::CheckBelowBuilding((CBaseEntity *)this,0x18);
  UpdateEntityEvents((CBaseEntity *)this);
  peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  fVar2 = peVar4->max_health;
  DoDamageEffects(peVar4,fVar2 * 0.66,fVar2 * 0.33);
  p1Var3 = gpGlobals;
  fVar2 = gpGlobals->time;
  if (fVar2 <= this->m_flNextRefillTime) {
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
  }
  else {
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells;
    *piVar1 = *piVar1 + 0x14;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_cells;
    *piVar1 = *piVar1 + 0x14;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_nails;
    *piVar1 = *piVar1 + 0x1e;
    piVar1 = &(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_rockets;
    *piVar1 = *piVar1 + 0xf;
    peVar4->armorvalue = peVar4->armorvalue + 50.0;
    if (400 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_shells) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_shells = 400;
    }
    if (600 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_nails) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_nails = 600;
    }
    if (300 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_rockets) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_rockets = 300;
    }
    if (400 < (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.ammo_cells) {
      (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_cells = 400;
    }
    peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if (500.0 < peVar4->armorvalue) {
      peVar4->armorvalue = 500.0;
      peVar4 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
               super_CBaseEntity.pev;
    }
    this->m_flNextRefillTime = p1Var3->time + 12.0;
    fVar2 = p1Var3->time;
  }
  peVar4->nextthink = fVar2 + 0.1;
  return;
}


// CTFDispenser::EngineerUse  @ 00085a70  (line 578)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: BOOL EngineerUse(CTFDispenser * this, CBasePlayer * pPlayer) */

BOOL __thiscall CTFDispenser::EngineerUse(CTFDispenser *this,CBasePlayer *pPlayer)

{
  entvars_t *peVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  char *param4;
  char *param3;
  char *param2;
  char *param1;
  int iVar7;
  
                    /* Unresolved local var: CBaseEntity * building@[???]
                       Unresolved local var: float metalcost@[???]
                       Unresolved local var: float am@[???]
                       Unresolved local var: int putInCount@[???] */
  peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  this->m_flNextUseTime = gpGlobals->time + 3.0;
  fVar2 = (peVar1->max_health - peVar1->health) / 5.0;
  if (fVar2 != 0.0) {
    ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev,1,"#Menu_RepairDisp",(char *)0x0,(char *)0x0,
                (char *)0x0,(char *)0x0);
    fVar3 = (float)(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                   super_CBaseDelay.super_CBaseEntity.ammo_cells;
    if (fVar3 < fVar2) {
      fVar2 = fVar3;
    }
    (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
    super_CBaseEntity.ammo_cells = (int)(fVar3 - fVar2);
    peVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    peVar1->health = fVar2 * 5.0 + peVar1->health;
    return 1;
  }
  iVar7 = 400 - (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_shells;
  iVar6 = 0x28;
  if ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_shells < 0x28) {
    iVar6 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_shells;
  }
  if (iVar7 <= iVar6) {
    iVar6 = iVar7;
  }
  fVar2 = (float)iVar6;
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_shells =
       (int)((float)(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_shells - fVar2);
  iVar6 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.ammo_nails;
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_shells =
       (int)((float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_shells + fVar2);
  iVar6 = 600 - iVar6;
  iVar7 = 0x28;
  if ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_nails < 0x28) {
    iVar7 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_nails;
  }
  if (iVar6 <= iVar7) {
    iVar7 = iVar6;
  }
  fVar3 = (float)iVar7;
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_nails =
       (int)((float)(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_nails - fVar3);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_nails =
       (int)((float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_nails + fVar3);
  iVar6 = 300 - (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_rockets;
  iVar7 = 10;
  if ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_rockets < 10) {
    iVar7 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_rockets;
  }
  if (iVar7 <= iVar6) {
    iVar6 = iVar7;
  }
  fVar4 = (float)iVar6;
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_rockets =
       (int)((float)(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_rockets - fVar4);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_rockets =
       (int)((float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_rockets + fVar4);
  iVar7 = 400 - (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
                super_CBaseEntity.ammo_cells;
  iVar6 = 0x28;
  if ((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity.ammo_cells < 0x28) {
    iVar6 = (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
            super_CBaseEntity.ammo_cells;
  }
  if (iVar7 <= iVar6) {
    iVar6 = iVar7;
  }
  fVar5 = (float)iVar6;
  (pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_cells =
       (int)((float)(pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_cells - fVar5);
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity.ammo_cells =
       (int)((float)(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                    super_CBaseDelay.super_CBaseEntity.ammo_cells + fVar5);
  if ((int)((float)(int)((float)(int)((float)(int)(fVar2 + 0.0) + fVar3) + fVar4) + fVar5) < 1) {
    ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev,1,"#Dispenser_AmmoNoMore",(char *)0x0,
                (char *)0x0,(char *)0x0,(char *)0x0);
  }
  else {
    ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                super_CBaseDelay.super_CBaseEntity.pev,1,"#Menu_AmmoDisp",(char *)0x0,(char *)0x0,
                (char *)0x0,(char *)0x0);
  }
  param4 = UTIL_dtos4((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.ammo_cells);
  param3 = UTIL_dtos3((int)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->armorvalue);
  param2 = UTIL_dtos2((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                      super_CBaseDelay.super_CBaseEntity.ammo_rockets);
  param1 = UTIL_dtos1((int)((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                            super_CBaseDelay.super_CBaseEntity.pev)->health);
  ClientPrint((pPlayer->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev,1,"#Dispenser_has",param1,param2,param3,param4);
  return 1;
}


// CTFDispenser::TeamFortress_TakeEMPBlast  @ 00085df0  (line 651)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CTFDispenser * this, entvars_t *
   pevGren) */

void __thiscall CTFDispenser::TeamFortress_TakeEMPBlast(CTFDispenser *this,entvars_t *pevGren)

{
  BOOL BVar1;
  CBaseEntity *pCVar2;
  edict_t *peVar3;
  CBaseEntity *pOther;
  
                    /* Unresolved local var: CBaseEntity * pThrower@[???]
                       Unresolved local var: CBaseEntity * pGrenade@[???] */
  peVar3 = pevGren->owner;
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if ((peVar3 == (edict_t *)0x0) &&
     (peVar3 = (*g_engfuncs.pfnPEntityOfEntOffset)(0), peVar3 == (edict_t *)0x0)) {
    pOther = (CBaseEntity *)0x0;
  }
  else {
    pOther = peVar3->pvPrivateData;
  }
                    /* Unresolved local var: CBaseEntity * pEnt@[???] */
  if (pevGren->pContainingEntity == (edict_t *)0x0) {
    (*g_engfuncs.pfnPEntityOfEntOffset)(0);
  }
  if (((((int)gpGlobals->teamplay & 0x1eU) == 0) ||
      (BVar1 = CBaseEntity::IsAlly((CBaseEntity *)this,pOther), BVar1 == 0)) ||
     (pCVar2 = EHANDLE::operator_cast_to_CBaseEntity_
                         (&(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.
                           super_CBaseDelay.super_CBaseEntity.real_owner), pCVar2 == pOther)) {
    (*(this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
      super_CBaseEntity._vptr_CBaseEntity[0xd])(this,pevGren,pOther->pev,0x43480000,0x40);
  }
  return;
}


