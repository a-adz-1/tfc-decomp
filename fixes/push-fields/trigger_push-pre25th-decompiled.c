// CTriggerPush::Touch  @ 001487a0  (line 1754)

/* DWARF original prototype: void Touch(CTriggerPush * this, CBaseEntity * pOther) */

void __thiscall CTriggerPush::Touch(CTriggerPush *this,CBaseEntity *pOther)

{
  float fVar1;
  float fVar2;
  entvars_t *peVar3;
  entvars_t *peVar4;
  uint uVar5;
  float fVar6;
  int iVar7;
  BOOL BVar8;
  
                    /* Unresolved local var: entvars_t * pevToucher@[???] */
  peVar3 = pOther->pev;
  if ((((0xc < (uint)peVar3->movetype) || ((1 << ((byte)peVar3->movetype & 0x1f) & 0x1181U) == 0))
      && (peVar3->solid != 4)) &&
     ((peVar3->solid != 0 &&
      ((iVar7 = (*pOther->_vptr_CBaseEntity[10])(pOther), iVar7 != 2 ||
       (BVar8 = ActivationSucceeded((CBaseEntity *)this,(CBasePlayer *)pOther,(CBaseEntity *)0x0),
       BVar8 != 0)))))) {
    peVar4 = (this->super_CBaseTrigger).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
             super_CBaseEntity.pev;
    if ((peVar4->spawnflags & 1) == 0) {
                    /* Unresolved local var: Vector vecPush@[???] */
      fVar1 = peVar4->speed;
      fVar2 = (peVar4->movedir).z * fVar1;
      fVar6 = (peVar4->movedir).y * fVar1;
      fVar1 = fVar1 * (peVar4->movedir).x;
      uVar5 = peVar3->flags;
      if ((uVar5 & 0x400000) != 0) {
        fVar2 = fVar2 + (peVar3->basevelocity).z;
        fVar6 = fVar6 + (peVar3->basevelocity).y;
        fVar1 = fVar1 + (peVar3->basevelocity).x;
      }
      (peVar3->basevelocity).x = fVar1;
      (peVar3->basevelocity).y = fVar6;
      (peVar3->basevelocity).z = fVar2;
      peVar3->flags = uVar5 | 0x400000;
      return;
    }
    fVar1 = peVar4->speed;
    fVar6 = (peVar4->movedir).z * fVar1 + (peVar3->velocity).z;
    fVar2 = (peVar4->movedir).y;
    (peVar3->velocity).x = fVar1 * (peVar4->movedir).x + (peVar3->velocity).x;
    (peVar3->velocity).y = fVar2 * fVar1 + (peVar3->velocity).y;
    (peVar3->velocity).z = fVar6;
    if (0.0 < fVar6) {
      peVar3->flags = peVar3->flags & 0xfffffdff;
    }
    UTIL_Remove((CBaseEntity *)this);
    return;
  }
  return;
}
