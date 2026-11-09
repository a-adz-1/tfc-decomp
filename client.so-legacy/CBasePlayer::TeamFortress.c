// CBasePlayer::TeamFortress_CalcEMPDmgRad  @ 0007daf0
/* DWARF original prototype: void TeamFortress_CalcEMPDmgRad(CBasePlayer * this, float * damage,
   float * radius) */

void __thiscall
CBasePlayer::TeamFortress_CalcEMPDmgRad(CBasePlayer *this,float *damage,float *radius)

{
  return;
}


// CBasePlayer::TeamFortress_CheckClassStats  @ 0007e7d0
/* DWARF original prototype: void TeamFortress_CheckClassStats(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_CheckClassStats(CBasePlayer *this)

{
  return;
}


// CBasePlayer::TeamFortress_Concuss  @ 0007db20
/* DWARF original prototype: void TeamFortress_Concuss(CBasePlayer * this, entvars_t * pevGren) */

void __thiscall CBasePlayer::TeamFortress_Concuss(CBasePlayer *this,entvars_t *pevGren)

{
  return;
}


// CBasePlayer::TeamFortress_DisplayLegalClasses  @ 0007e720
/* DWARF original prototype: void TeamFortress_DisplayLegalClasses(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_DisplayLegalClasses(CBasePlayer *this)

{
  return;
}


// CBasePlayer::TeamFortress_ExecClassScript  @ 0007e730
/* DWARF original prototype: void TeamFortress_ExecClassScript(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_ExecClassScript(CBasePlayer *this)

{
  return;
}


// CBasePlayer::TeamFortress_ExecMapScript  @ 0007e740
/* DWARF original prototype: void TeamFortress_ExecMapScript(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_ExecMapScript(CBasePlayer *this)

{
  return;
}


// CBasePlayer::TeamFortress_PrimeGrenade  @ 0007e820
/* DWARF original prototype: void TeamFortress_PrimeGrenade(CBasePlayer * this, int iWhichType) */

void __thiscall CBasePlayer::TeamFortress_PrimeGrenade(CBasePlayer *this,int iWhichType)

{
  return;
}


// CBasePlayer::TeamFortress_PrintClassName  @ 0007e6c0
/* DWARF original prototype: void TeamFortress_PrintClassName(CBasePlayer * this, int pc) */

void __thiscall CBasePlayer::TeamFortress_PrintClassName(CBasePlayer *this,int pc)

{
  return;
}


// CBasePlayer::TeamFortress_RemoveTimers  @ 0007e7b0
/* DWARF original prototype: void TeamFortress_RemoveTimers(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_RemoveTimers(CBasePlayer *this)

{
  return;
}


// CBasePlayer::TeamFortress_SetEquipment  @ 0007e6e0
/* DWARF original prototype: void TeamFortress_SetEquipment(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetEquipment(CBasePlayer *this)

{
  return;
}


// CBasePlayer::TeamFortress_SetHealth  @ 0007e6f0
/* DWARF original prototype: void TeamFortress_SetHealth(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetHealth(CBasePlayer *this)

{
  return;
}


// CBasePlayer::TeamFortress_SetSkin  @ 0007e700
/* DWARF original prototype: void TeamFortress_SetSkin(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetSkin(CBasePlayer *this)

{
  return;
}


// CBasePlayer::TeamFortress_SetSpeed  @ 00080f50
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void TeamFortress_SetSpeed(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_SetSpeed(CBasePlayer *this)

{
  uint uVar1;
  entvars_t *peVar2;
  int iVar3;
  float fVar4;
  
                    /* Unresolved local var: int playerclass@[???]
                       Unresolved local var: float maxfbspeed@[???] */
  uVar1 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
          super_CBaseEntity.tfstate;
  peVar2 = (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
  iVar3 = peVar2->playerclass;
  if (((uVar1 & 0x10000) == 0) && (iVar3 != 0)) {
    fVar4 = 400.0;
    if ((((iVar3 != 1) &&
         ((((fVar4 = 300.0, iVar3 != 2 && (fVar4 = 240.0, iVar3 != 3)) &&
           (fVar4 = 280.0, iVar3 != 4)) &&
          ((fVar4 = 320.0, iVar3 != 5 && (fVar4 = 230.0, iVar3 != 6)))))) &&
        (fVar4 = 300.0, iVar3 != 7)) && (fVar4 = 240.0, iVar3 != 0xb)) {
      fVar4 = 300.0;
    }
    if (((uVar1 & 0x800) != 0) && (80.0 < fVar4)) {
      fVar4 = 80.0;
    }
    peVar2->maxspeed = fVar4;
    return;
  }
  (peVar2->velocity).x = g_vecZero.x;
  (peVar2->velocity).y = g_vecZero.y;
  (peVar2->velocity).z = g_vecZero.z;
  (*g_engfuncs.pfnSetClientMaxspeed)
            (((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
              super_CBaseEntity.pev)->pContainingEntity,1.0);
  ((this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
   super_CBaseEntity.pev)->maxspeed = 1.0;
  return;
}


// CBasePlayer::TeamFortress_SetupRespawn  @ 0007e7c0
/* DWARF original prototype: void TeamFortress_SetupRespawn(CBasePlayer * this, BOOL bSuicided) */

void __thiscall CBasePlayer::TeamFortress_SetupRespawn(CBasePlayer *this,BOOL bSuicided)

{
  return;
}


// CBasePlayer::TeamFortress_TakeConcussionBlast  @ 0007db10
/* DWARF original prototype: void TeamFortress_TakeConcussionBlast(CBasePlayer * this, entvars_t *
   pevGren, float bouncemax) */

void __thiscall
CBasePlayer::TeamFortress_TakeConcussionBlast(CBasePlayer *this,entvars_t *pevGren,float bouncemax)

{
  return;
}


// CBasePlayer::TeamFortress_TakeEMPBlast  @ 0007db00
/* DWARF original prototype: void TeamFortress_TakeEMPBlast(CBasePlayer * this, entvars_t * pevGren)
    */

void __thiscall CBasePlayer::TeamFortress_TakeEMPBlast(CBasePlayer *this,entvars_t *pevGren)

{
  return;
}


// CBasePlayer::TeamFortress_TeamPutPlayerInTeam  @ 0007e750
/* DWARF original prototype: BOOL TeamFortress_TeamPutPlayerInTeam(CBasePlayer * this) */

BOOL __thiscall CBasePlayer::TeamFortress_TeamPutPlayerInTeam(CBasePlayer *this)

{
  return 1;
}


// CBasePlayer::TeamFortress_TeamSet  @ 0007e760
/* DWARF original prototype: BOOL TeamFortress_TeamSet(CBasePlayer * this, int tno) */

BOOL __thiscall CBasePlayer::TeamFortress_TeamSet(CBasePlayer *this,int tno)

{
  return 1;
}


// CBasePlayer::TeamFortress_TeamShowMemberClasses  @ 0007e770
/* DWARF original prototype: void TeamFortress_TeamShowMemberClasses(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_TeamShowMemberClasses(CBasePlayer *this)

{
  return;
}


// CBasePlayer::TeamFortress_ThrowPrimedGrenade  @ 0007e810
/* DWARF original prototype: void TeamFortress_ThrowPrimedGrenade(CBasePlayer * this) */

void __thiscall CBasePlayer::TeamFortress_ThrowPrimedGrenade(CBasePlayer *this)

{
  return;
}


