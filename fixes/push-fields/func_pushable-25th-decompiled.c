// CPushable::Move  @ 00096b00  (line 918)

/* DWARF original prototype: void Move(CPushable * this, CBaseEntity * pOther, int push) */

void __thiscall CPushable::Move(CPushable *this,CBaseEntity *pOther,int push)

{
  float fVar1;
  entvars_t *peVar2;
  float fVar3;
  bool bVar4;
  entvars_t *peVar5;
  int32 iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  float fVar11;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???]
                       Unresolved local var: int playerTouch@[???]
                       Unresolved local var: float factor@[???]
                       Unresolved local var: cvar_t sv_pushable_fixed_tick_fudge@[???]
                       Unresolved local var: float length@[???] */
  peVar2 = pOther->pev;
  uVar10 = peVar2->flags & 0x200;
  if (((uVar10 != 0) && (peVar2->groundentity != (edict_t *)0x0)) &&
     (peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev,
     peVar5 == &peVar2->groundentity->v)) {
    if (peVar5->waterlevel < 1) {
      return;
    }
    (peVar5->velocity).z = (peVar2->velocity).z * 0.1 + (peVar5->velocity).z;
    return;
  }
  if ((peVar2->flags & 8U) == 0) {
    bVar4 = false;
    peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = 0.25;
    if (push == 0) goto LAB_00096b65;
LAB_00096d50:
    (peVar5->velocity).x = (peVar2->velocity).x * fVar1 + (peVar5->velocity).x;
    peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    fVar11 = (peVar5->velocity).y;
    fVar1 = fVar1 * (peVar2->velocity).y;
  }
  else {
    if (push != 0) {
      if ((peVar2->button & 0x20) != 0) {
        return;
      }
      peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      if (uVar10 == 0) {
        if (peVar5->waterlevel < 1) {
          return;
        }
        bVar4 = true;
        fVar1 = 0.1;
      }
      else {
        fVar1 = 1.0;
        bVar4 = true;
      }
      goto LAB_00096d50;
    }
    peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    if (uVar10 == 0) {
      if (peVar5->waterlevel < 1) {
        return;
      }
      bVar4 = true;
      fVar1 = 0.1;
    }
    else {
      bVar4 = true;
      fVar1 = 1.0;
    }
LAB_00096b65:
    if (0.0 <= sv_pushable_fixed_tick_fudge.value) {
      fVar1 = sv_pushable_fixed_tick_fudge.value * gpGlobals->frametime * fVar1;
    }
    fVar11 = (peVar5->velocity).x;
    fVar3 = (peVar2->velocity).x * fVar1;
    uVar10 = (uint)fVar11;
    uVar7 = (int)uVar10 >> 0x1f;
    uVar8 = (uint)((peVar2->velocity).x - fVar3);
    uVar9 = (int)uVar8 >> 0x1f;
    if ((int)((uVar10 ^ uVar7) - uVar7) < (int)((uVar8 ^ uVar9) - uVar9)) {
      (peVar5->velocity).x = fVar11 + fVar3;
      peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    }
    fVar11 = (peVar5->velocity).y;
    fVar1 = fVar1 * (peVar2->velocity).y;
    uVar10 = (int)fVar11 >> 0x1f;
    uVar7 = (uint)((peVar2->velocity).y - fVar1);
    uVar8 = (int)uVar7 >> 0x1f;
    if ((int)((uVar7 ^ uVar8) - uVar8) <= (int)(((int)fVar11 ^ uVar10) - uVar10)) goto LAB_00096c13;
  }
  (peVar5->velocity).y = fVar1 + fVar11;
  peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
  fVar11 = (peVar5->velocity).y;
LAB_00096c13:
  fVar1 = (peVar5->velocity).x;
  fVar1 = fVar11 * fVar11 + fVar1 * fVar1;
  fVar11 = SQRT(fVar1);
  if (NAN(fVar11)) {
    fVar11 = sqrtf(fVar1);
  }
  if (this->m_maxSpeed < fVar11) {
    peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    (peVar5->velocity).x = (this->m_maxSpeed * (peVar5->velocity).x) / fVar11;
    peVar5 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    (peVar5->velocity).y = ((peVar5->velocity).y * this->m_maxSpeed) / fVar11;
  }
  if (bVar4) {
    if (push != 0) {
      (peVar2->velocity).x =
           (((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->velocity).x;
      (peVar2->velocity).y =
           (((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->velocity).y;
    }
    if (0.7 < gpGlobals->time - this->m_soundTime) {
      this->m_soundTime = gpGlobals->time;
      peVar2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      if ((fVar11 <= 0.0) || ((peVar2->flags & 0x200) == 0)) {
        EMIT_SOUND_DYN(peVar2->pContainingEntity,1,m_soundNames[this->m_lastSound],0.0,0.0,0x20,100)
        ;
      }
      else {
        iVar6 = (*g_engfuncs.pfnRandomLong)(0,2);
        this->m_lastSound = iVar6;
        EMIT_SOUND_DYN(((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->
                       pContainingEntity,1,m_soundNames[iVar6],0.5,0.8,0,100);
      }
    }
  }
  return;
}
