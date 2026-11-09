// Ghidra decompilation of functions from tfc/effects.h
// 3 functions, ordered by original source line

// CSprite::ObjectCaps  @ 000d01f0  (line 37)

/* DWARF original prototype: int ObjectCaps(CSprite * this) */

int __thiscall CSprite::ObjectCaps(CSprite *this)

{
                    /* Unresolved local var: int flags@[???] */
  return (((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8000U) << 0x10;
}


// CBeam::ObjectCaps  @ 000d0210  (line 105)

/* DWARF original prototype: int ObjectCaps(CBeam * this) */

int __thiscall CBeam::ObjectCaps(CBeam *this)

{
                    /* Unresolved local var: int flags@[???] */
  return (((this->super_CBaseEntity).pev)->spawnflags & 0x8000U) << 0x10;
}


// CBeam::Center  @ 000d0440  (line 140)

/* DWARF original prototype: Vector Center(CBeam * this) */

Vector * __thiscall CBeam::Center(Vector *__return_storage_ptr__,CBeam *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Vector *pVVar5;
  edict_t *peVar6;
  entvars_t *peVar7;
  uint uVar8;
  Vector *pVVar9;
  
  peVar7 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: int type@[DW_OP_reg2(EDX)]
                       Unresolved local var: edict_t * pent@[???] */
  uVar8 = peVar7->rendermode & 0xf;
  if ((uVar8 == 3) || (uVar8 == 0)) {
    pVVar9 = &peVar7->angles;
  }
  else {
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
    peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->skin & 0xfff);
    if (peVar6 == (edict_t *)0x0) {
      peVar7 = (this->super_CBaseEntity).pev;
      pVVar9 = &peVar7->angles;
    }
    else {
      peVar7 = (this->super_CBaseEntity).pev;
      pVVar9 = &(peVar6->v).origin;
    }
    uVar8 = peVar7->rendermode & 0xf;
  }
  if (uVar8 == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar6 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->sequence & 0xfff);
    peVar7 = &peVar6->v;
  }
  pVVar5 = &peVar7->origin;
  fVar1 = pVVar5->z;
  fVar2 = pVVar9->z;
  fVar3 = pVVar5->y;
  fVar4 = pVVar9->y;
  __return_storage_ptr__->x = (pVVar5->x + pVVar9->x) * 0.5;
  __return_storage_ptr__->y = (fVar3 + fVar4) * 0.5;
  __return_storage_ptr__->z = (fVar1 + fVar2) * 0.5;
  return __return_storage_ptr__;
}


