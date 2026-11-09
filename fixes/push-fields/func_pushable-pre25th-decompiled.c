// CPushable::Move  @ 000d4610  (line 918)

/* DWARF original prototype: void Move(CPushable * this, CBaseEntity * pOther, int push) */

void __thiscall CPushable::Move(CPushable *this,CBaseEntity *pOther,int push)

{
  float fVar1;
  entvars_t *peVar2;
  bool bVar3;
  entvars_t *peVar4;
  int32 iVar5;
  uint uVar6;
  float fVar7;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???]
                       Unresolved local var: int playerTouch@[???]
                       Unresolved local var: float factor@[???]
                       Unresolved local var: float length@[???] */
  peVar2 = pOther->pev;
  uVar6 = peVar2->flags & 0x200;
  if (((uVar6 == 0) || (peVar2->groundentity == (edict_t *)0x0)) ||
     (peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev,
     peVar4 != &peVar2->groundentity->v)) {
    if ((peVar2->flags & 8U) == 0) {
      peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      bVar3 = false;
      fVar1 = 0.25;
    }
    else {
      if ((push != 0) && ((peVar2->button & 0x28) == 0)) {
        return;
      }
      peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      if (uVar6 == 0) {
        if (peVar4->waterlevel < 1) {
          return;
        }
        bVar3 = true;
        fVar1 = 0.1;
      }
      else {
        bVar3 = true;
        fVar1 = 1.0;
      }
    }
    (peVar4->velocity).x = (peVar2->velocity).x * fVar1 + (peVar4->velocity).x;
    peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    (peVar4->velocity).y = fVar1 * (peVar2->velocity).y + (peVar4->velocity).y;
    peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = (peVar4->velocity).x;
    fVar7 = (peVar4->velocity).y;
    fVar1 = fVar7 * fVar7 + fVar1 * fVar1;
    fVar7 = SQRT(fVar1);
    if (NAN(fVar7)) {
      fVar7 = sqrtf(fVar1);
    }
    if ((push != 0) && (this->m_maxSpeed < fVar7)) {
      peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      (peVar4->velocity).x = (this->m_maxSpeed * (peVar4->velocity).x) / fVar7;
      peVar4 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
      (peVar4->velocity).y = ((peVar4->velocity).y * this->m_maxSpeed) / fVar7;
    }
    if (bVar3) {
      (peVar2->velocity).x =
           (((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->velocity).x;
      (peVar2->velocity).y =
           (((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->velocity).y;
      if (0.7 < gpGlobals->time - this->m_soundTime) {
        this->m_soundTime = gpGlobals->time;
        peVar2 = (this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev;
        if ((fVar7 <= 0.0) || ((peVar2->flags & 0x200) == 0)) {
          EMIT_SOUND_DYN(peVar2->pContainingEntity,1,m_soundNames[this->m_lastSound],0.0,0.0,0x20,
                         100);
        }
        else {
          iVar5 = (*g_engfuncs.pfnRandomLong)(0,2);
          this->m_lastSound = iVar5;
          EMIT_SOUND_DYN(((this->super_CBreakable).super_CBaseDelay.super_CBaseEntity.pev)->
                         pContainingEntity,1,m_soundNames[iVar5],0.5,0.8,0,100);
        }
      }
    }
  }
  else if (0 < peVar4->waterlevel) {
    (peVar4->velocity).z = (peVar2->velocity).z * 0.1 + (peVar4->velocity).z;
  }
  return;
}
