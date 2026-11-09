// Ghidra decompilation of functions from tfc/effects.h
// 6 functions, ordered by original source line

// CSprite::~CSprite  @ 000920a0  (line 28)

/* DWARF original prototype: void ~CSprite(CSprite * this, int __in_chrg) */

void __thiscall CSprite::~CSprite(CSprite *this,int __in_chrg)

{
  return;
}


// CSprite::ObjectCaps  @ 00091fa0  (line 37)

/* DWARF original prototype: int ObjectCaps(CSprite * this) */

int __thiscall CSprite::ObjectCaps(CSprite *this)

{
                    /* Unresolved local var: int flags@[???] */
  return (((this->super_CPointEntity).super_CBaseEntity.pev)->spawnflags & 0x8000U) << 0x10;
}


// CBeam::~CBeam  @ 00091ff0  (line 97)

/* DWARF original prototype: void ~CBeam(CBeam * this, int __in_chrg) */

void __thiscall CBeam::~CBeam(CBeam *this,int __in_chrg)

{
  return;
}


// CBeam::ObjectCaps  @ 00091fc0  (line 105)

/* DWARF original prototype: int ObjectCaps(CBeam * this) */

int __thiscall CBeam::ObjectCaps(CBeam *this)

{
                    /* Unresolved local var: int flags@[???] */
  return (((this->super_CBaseEntity).pev)->spawnflags & 0x8000U) << 0x10;
}


// CBeam::Center  @ 000920f0  (line 140)

/* DWARF original prototype: Vector Center(CBeam * this) */

Vector * __thiscall CBeam::Center(Vector *__return_storage_ptr__,CBeam *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  edict_t *peVar5;
  Vector *pVVar6;
  entvars_t *peVar7;
  uint uVar8;
  Vector *pVVar9;
  
  peVar7 = (this->super_CBaseEntity).pev;
                    /* Unresolved local var: int type@[???]
                       Unresolved local var: edict_t * pent@[???] */
  uVar8 = peVar7->rendermode & 0xf;
  if ((uVar8 == 0) || (uVar8 == 3)) {
    pVVar9 = &peVar7->angles;
  }
  else {
    peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->skin & 0xfff);
    if (peVar5 == (edict_t *)0x0) {
      peVar7 = (this->super_CBaseEntity).pev;
      pVVar9 = &peVar7->angles;
      uVar8 = peVar7->rendermode & 0xf;
    }
    else {
      peVar7 = (this->super_CBaseEntity).pev;
      pVVar9 = &(peVar5->v).origin;
      uVar8 = peVar7->rendermode & 0xf;
    }
  }
  if (uVar8 == 2) {
                    /* Unresolved local var: edict_t * pent@[???] */
    peVar5 = (*g_engfuncs.pfnPEntityOfEntIndex)(peVar7->sequence & 0xfff);
    peVar7 = &peVar5->v;
  }
  pVVar6 = &peVar7->origin;
  fVar1 = pVVar6->z;
  fVar2 = pVVar9->z;
  fVar3 = pVVar6->y;
  fVar4 = pVVar9->y;
  __return_storage_ptr__->x = (pVVar6->x + pVVar9->x) * 0.5;
  __return_storage_ptr__->y = (fVar3 + fVar4) * 0.5;
  __return_storage_ptr__->z = (fVar1 + fVar2) * 0.5;
  return __return_storage_ptr__;
}


// CLaser::~CLaser  @ 000920c0  (line 180)

/* DWARF original prototype: void ~CLaser(CLaser * this, int __in_chrg) */

void __thiscall CLaser::~CLaser(CLaser *this,int __in_chrg)

{
  return;
}


