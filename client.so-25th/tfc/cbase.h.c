// Ghidra decompilation of functions from tfc/cbase.h
// 71 functions, ordered by original source line

// CBaseEntity::~CBaseEntity  @ 00059420  (line 153)

/* DWARF original prototype: void ~CBaseEntity(CBaseEntity * this, int __in_chrg) */

void __thiscall CBaseEntity::~CBaseEntity(CBaseEntity *this,int __in_chrg)

{
  return;
}


// CBaseEntity::Spawn  @ 00059430  (line 156)

/* DWARF original prototype: void Spawn(CBaseEntity * this) */

void __thiscall CBaseEntity::Spawn(CBaseEntity *this)

{
  return;
}


// CBaseEntity::Precache  @ 00059440  (line 157)

/* DWARF original prototype: void Precache(CBaseEntity * this) */

void __thiscall CBaseEntity::Precache(CBaseEntity *this)

{
  return;
}


// CBaseEntity::ObjectCaps  @ 00059450  (line 163)

/* DWARF original prototype: int ObjectCaps(CBaseEntity * this) */

int __thiscall CBaseEntity::ObjectCaps(CBaseEntity *this)

{
  return 2;
}


// CBaseEntity::Activate  @ 00059460  (line 164)

/* DWARF original prototype: void Activate(CBaseEntity * this) */

void __thiscall CBaseEntity::Activate(CBaseEntity *this)

{
  return;
}


// CBaseEntity::Classify  @ 00059470  (line 171)

/* DWARF original prototype: int Classify(CBaseEntity * this) */

int __thiscall CBaseEntity::Classify(CBaseEntity *this)

{
  return 0;
}


// CBaseEntity::DeathNotice  @ 00059480  (line 172)

/* DWARF original prototype: void DeathNotice(CBaseEntity * this, entvars_t * pevChild) */

void __thiscall CBaseEntity::DeathNotice(CBaseEntity *this,entvars_t *pevChild)

{
  return;
}


// CBaseEntity::BloodColor  @ 00059490  (line 181)

/* DWARF original prototype: int BloodColor(CBaseEntity * this) */

int __thiscall CBaseEntity::BloodColor(CBaseEntity *this)

{
  return -1;
}


// CBaseEntity::IsTriggered  @ 000594a0  (line 183)

/* DWARF original prototype: int IsTriggered(CBaseEntity * this) */

int __thiscall CBaseEntity::IsTriggered(CBaseEntity *this)

{
  return 1;
}


// CBaseEntity::MyMonsterPointer  @ 000594b0  (line 184)

/* DWARF original prototype: CBaseMonster * MyMonsterPointer(CBaseEntity * this) */

CBaseMonster * __thiscall CBaseEntity::MyMonsterPointer(CBaseEntity *this)

{
  return (CBaseMonster *)0x0;
}


// CBaseEntity::MySquadMonsterPointer  @ 000594c0  (line 185)

/* DWARF original prototype: CSquadMonster * MySquadMonsterPointer(CBaseEntity * this) */

CSquadMonster * __thiscall CBaseEntity::MySquadMonsterPointer(CBaseEntity *this)

{
  return (CSquadMonster *)0x0;
}


// CBaseEntity::GetToggleState  @ 000594d0  (line 186)

/* DWARF original prototype: int GetToggleState(CBaseEntity * this) */

int __thiscall CBaseEntity::GetToggleState(CBaseEntity *this)

{
  return 0;
}


// CBaseEntity::AddPlayerItem  @ 000594e0  (line 187)

/* DWARF original prototype: BOOL AddPlayerItem(CBaseEntity * this, CBasePlayerItem * pItem) */

BOOL __thiscall CBaseEntity::AddPlayerItem(CBaseEntity *this,CBasePlayerItem *pItem)

{
  return 0;
}


// CBaseEntity::RemovePlayerItem  @ 000594f0  (line 188)

/* DWARF original prototype: BOOL RemovePlayerItem(CBaseEntity * this, CBasePlayerItem * pItem) */

BOOL __thiscall CBaseEntity::RemovePlayerItem(CBaseEntity *this,CBasePlayerItem *pItem)

{
  return 0;
}


// CBaseEntity::GiveAmmo  @ 00059500  (line 189)

/* DWARF original prototype: int GiveAmmo(CBaseEntity * this, int iAmount, char * szName, int iMax,
   int * pIndex) */

int __thiscall
CBaseEntity::GiveAmmo(CBaseEntity *this,int iAmount,char *szName,int iMax,int *pIndex)

{
  return -1;
}


// CBaseEntity::GetDelay  @ 00059510  (line 190)

/* DWARF original prototype: float GetDelay(CBaseEntity * this) */

float __thiscall CBaseEntity::GetDelay(CBaseEntity *this)

{
  return 0.0;
}


// CBaseEntity::IsMoving  @ 00059520  (line 191)

/* DWARF original prototype: int IsMoving(CBaseEntity * this) */

int __thiscall CBaseEntity::IsMoving(CBaseEntity *this)

{
  float fVar1;
  entvars_t *peVar2;
  uint uVar3;
  
  peVar2 = this->pev;
  if (((peVar2->velocity).x == g_vecZero.x) && ((peVar2->velocity).y == g_vecZero.y)) {
    fVar1 = (peVar2->velocity).z;
    uVar3 = (uint)(NAN(g_vecZero.z) || NAN(fVar1));
    if (g_vecZero.z != fVar1) {
      uVar3 = 1;
    }
    return uVar3;
  }
  return 1;
}


// CBaseEntity::OverrideReset  @ 00059580  (line 192)

/* DWARF original prototype: void OverrideReset(CBaseEntity * this) */

void __thiscall CBaseEntity::OverrideReset(CBaseEntity *this)

{
  return;
}


// CBaseEntity::SetToggleState  @ 00059590  (line 195)

/* DWARF original prototype: void SetToggleState(CBaseEntity * this, int state) */

void __thiscall CBaseEntity::SetToggleState(CBaseEntity *this,int state)

{
  return;
}


// CBaseEntity::StartSneaking  @ 000595a0  (line 196)

/* DWARF original prototype: void StartSneaking(CBaseEntity * this) */

void __thiscall CBaseEntity::StartSneaking(CBaseEntity *this)

{
  return;
}


// CBaseEntity::StopSneaking  @ 000595b0  (line 197)

/* DWARF original prototype: void StopSneaking(CBaseEntity * this) */

void __thiscall CBaseEntity::StopSneaking(CBaseEntity *this)

{
  return;
}


// CBaseEntity::OnControls  @ 000595c0  (line 198)

/* DWARF original prototype: BOOL OnControls(CBaseEntity * this, entvars_t * pev) */

BOOL __thiscall CBaseEntity::OnControls(CBaseEntity *this,entvars_t *pev)

{
  return 0;
}


// CBaseEntity::IsSneaking  @ 000595d0  (line 199)

/* DWARF original prototype: BOOL IsSneaking(CBaseEntity * this) */

BOOL __thiscall CBaseEntity::IsSneaking(CBaseEntity *this)

{
  return 0;
}


// CBaseEntity::IsAlive  @ 000595e0  (line 200)

/* DWARF original prototype: BOOL IsAlive(CBaseEntity * this) */

BOOL __thiscall CBaseEntity::IsAlive(CBaseEntity *this)

{
  uint uVar1;
  
  uVar1 = 0;
  if (this->pev->deadflag == 0) {
    uVar1 = (uint)(0.0 < this->pev->health);
  }
  return uVar1;
}


// CBaseEntity::IsBSPModel  @ 00059610  (line 201)

/* DWARF original prototype: BOOL IsBSPModel(CBaseEntity * this) */

BOOL __thiscall CBaseEntity::IsBSPModel(CBaseEntity *this)

{
  if (this->pev->solid != 4) {
    return (uint)(this->pev->movetype == 0xd);
  }
  return 1;
}


// CBaseEntity::ReflectGauss  @ 00059ea0  (line 202)

/* DWARF original prototype: BOOL ReflectGauss(CBaseEntity * this) */

BOOL __thiscall CBaseEntity::ReflectGauss(CBaseEntity *this)

{
  uint uVar1;
  entvars_t *peVar2;
  
  if (this->_vptr_CBaseEntity[0x23] == IsBSPModel) {
    peVar2 = this->pev;
    if (peVar2->solid == 4) goto LAB_00059ee3;
    uVar1 = (uint)(peVar2->movetype == 0xd);
  }
  else {
    uVar1 = (*this->_vptr_CBaseEntity[0x23])(this);
  }
  if (uVar1 == 0) {
    return 0;
  }
  peVar2 = this->pev;
LAB_00059ee3:
  uVar1 = (uint)!NAN(peVar2->takedamage);
  if (peVar2->takedamage != 0.0) {
    uVar1 = 0;
  }
  return uVar1;
}


// CBaseEntity::HasTarget  @ 00059de0  (line 203)

/* DWARF original prototype: BOOL HasTarget(CBaseEntity * this, string_t targetname) */

BOOL __thiscall CBaseEntity::HasTarget(CBaseEntity *this,string_t targetname)

{
  int iVar1;
  
  iVar1 = strcmp(gpGlobals->pStringBase + targetname,gpGlobals->pStringBase + this->pev->targetname)
  ;
  return (uint)(iVar1 == 0);
}


// CBaseEntity::IsPlayer  @ 00059640  (line 205)

/* DWARF original prototype: BOOL IsPlayer(CBaseEntity * this) */

BOOL __thiscall CBaseEntity::IsPlayer(CBaseEntity *this)

{
  return 0;
}


// CBaseEntity::IsNetClient  @ 00059650  (line 206)

/* DWARF original prototype: BOOL IsNetClient(CBaseEntity * this) */

BOOL __thiscall CBaseEntity::IsNetClient(CBaseEntity *this)

{
  return 0;
}


// CBaseEntity::Think  @ 00059660  (line 218)

/* DWARF original prototype: void Think(CBaseEntity * this) */

void __thiscall CBaseEntity::Think(CBaseEntity *this)

{
  _func___thiscall_void_CBaseEntity_ptr *UNRECOVERED_JUMPTABLE;
  CBaseEntity *pCVar1;
  
  UNRECOVERED_JUMPTABLE = (this->m_pfnThink).__pfn;
  if (UNRECOVERED_JUMPTABLE == (_func___thiscall_void_CBaseEntity_ptr *)0x0) {
    return;
  }
  pCVar1 = (CBaseEntity *)((int)&this->_vptr_CBaseEntity + (this->m_pfnThink).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x00059679. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(pCVar1);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0005968a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(UNRECOVERED_JUMPTABLE + (int)pCVar1->_vptr_CBaseEntity + -1))();
  return;
}


// CBaseEntity::Touch  @ 000596a0  (line 219)

/* DWARF original prototype: void Touch(CBaseEntity * this, CBaseEntity * pOther) */

void __thiscall CBaseEntity::Touch(CBaseEntity *this,CBaseEntity *pOther)

{
  _func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *UNRECOVERED_JUMPTABLE;
  CBaseEntity *pCVar1;
  
  UNRECOVERED_JUMPTABLE = (this->m_pfnTouch).__pfn;
  if (UNRECOVERED_JUMPTABLE == (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0) {
    return;
  }
  pCVar1 = (CBaseEntity *)((int)&this->_vptr_CBaseEntity + (this->m_pfnTouch).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x000596c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(pCVar1,pOther);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000596d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(UNRECOVERED_JUMPTABLE + (int)pCVar1->_vptr_CBaseEntity + -1))();
  return;
}


// CBaseEntity::Use  @ 000596f0  (line 220)

/* DWARF original prototype: void Use(CBaseEntity * this, CBaseEntity * pActivator, CBaseEntity *
   pCaller, USE_TYPE useType, float value) */

void __thiscall
CBaseEntity::Use(CBaseEntity *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
                float value)

{
  CBaseEntity *pCVar1;
  _func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float
  *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (this->m_pfnUse).__pfn;
  if (UNRECOVERED_JUMPTABLE !=
      (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float *)0x0) {
    pCVar1 = (CBaseEntity *)((int)&this->_vptr_CBaseEntity + (this->m_pfnUse).__delta);
    if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
      UNRECOVERED_JUMPTABLE =
           *(_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr_CBaseEntity_ptr_USE_TYPE_float **
            )(UNRECOVERED_JUMPTABLE + (int)pCVar1->_vptr_CBaseEntity + -1);
    }
                    /* WARNING: Could not recover jumptable at 0x00059745. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(pCVar1,pActivator,pCaller,useType,value);
    return;
  }
  return;
}


// CBaseEntity::Blocked  @ 00059780  (line 225)

/* DWARF original prototype: void Blocked(CBaseEntity * this, CBaseEntity * pOther) */

void __thiscall CBaseEntity::Blocked(CBaseEntity *this,CBaseEntity *pOther)

{
  _func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *UNRECOVERED_JUMPTABLE;
  CBaseEntity *pCVar1;
  
  UNRECOVERED_JUMPTABLE = (this->m_pfnBlocked).__pfn;
  if (UNRECOVERED_JUMPTABLE == (_func___thiscall_void_CBaseEntity_ptr_CBaseEntity_ptr *)0x0) {
    return;
  }
  pCVar1 = (CBaseEntity *)((int)&this->_vptr_CBaseEntity + (this->m_pfnBlocked).__delta);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x000597a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(pCVar1,pOther);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000597b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(UNRECOVERED_JUMPTABLE + (int)pCVar1->_vptr_CBaseEntity + -1))();
  return;
}


// CBaseEntity::Respawn  @ 000597d0  (line 250)

/* DWARF original prototype: CBaseEntity * Respawn(CBaseEntity * this) */

CBaseEntity * __thiscall CBaseEntity::Respawn(CBaseEntity *this)

{
  return (CBaseEntity *)0x0;
}


// CBaseEntity::UpdateOwner  @ 000597e0  (line 327)

/* DWARF original prototype: void UpdateOwner(CBaseEntity * this) */

void __thiscall CBaseEntity::UpdateOwner(CBaseEntity *this)

{
  return;
}


// CBaseEntity::FBecomeProne  @ 000597f0  (line 333)

/* DWARF original prototype: BOOL FBecomeProne(CBaseEntity * this) */

BOOL __thiscall CBaseEntity::FBecomeProne(CBaseEntity *this)

{
  return 0;
}


// CBaseEntity::Center  @ 00059800  (line 338)

/* DWARF original prototype: Vector Center(CBaseEntity * this) */

Vector * __thiscall CBaseEntity::Center(Vector *__return_storage_ptr__,CBaseEntity *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  entvars_t *peVar5;
  
  peVar5 = this->pev;
  fVar1 = (peVar5->absmax).z;
  fVar2 = (peVar5->absmin).z;
  fVar3 = (peVar5->absmax).y;
  fVar4 = (peVar5->absmin).y;
  __return_storage_ptr__->x = ((peVar5->absmax).x + (peVar5->absmin).x) * 0.5;
  __return_storage_ptr__->y = (fVar3 + fVar4) * 0.5;
  __return_storage_ptr__->z = (fVar1 + fVar2) * 0.5;
  return __return_storage_ptr__;
}


// CBaseEntity::EyePosition  @ 00059850  (line 339)

/* DWARF original prototype: Vector EyePosition(CBaseEntity * this) */

Vector * __thiscall CBaseEntity::EyePosition(Vector *__return_storage_ptr__,CBaseEntity *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  entvars_t *peVar5;
  
  peVar5 = this->pev;
  fVar1 = (peVar5->origin).z;
  fVar2 = (peVar5->view_ofs).z;
  fVar3 = (peVar5->origin).y;
  fVar4 = (peVar5->view_ofs).y;
  __return_storage_ptr__->x = (peVar5->origin).x + (peVar5->view_ofs).x;
  __return_storage_ptr__->y = fVar3 + fVar4;
  __return_storage_ptr__->z = fVar1 + fVar2;
  return __return_storage_ptr__;
}


// CBaseEntity::EarPosition  @ 00059890  (line 340)

/* DWARF original prototype: Vector EarPosition(CBaseEntity * this) */

Vector * __thiscall CBaseEntity::EarPosition(Vector *__return_storage_ptr__,CBaseEntity *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  entvars_t *peVar5;
  
  peVar5 = this->pev;
  fVar1 = (peVar5->origin).z;
  fVar2 = (peVar5->view_ofs).z;
  fVar3 = (peVar5->origin).y;
  fVar4 = (peVar5->view_ofs).y;
  __return_storage_ptr__->x = (peVar5->origin).x + (peVar5->view_ofs).x;
  __return_storage_ptr__->y = fVar3 + fVar4;
  __return_storage_ptr__->z = fVar1 + fVar2;
  return __return_storage_ptr__;
}


// CBaseEntity::BodyTarget  @ 000598d0  (line 341)

/* DWARF original prototype: Vector BodyTarget(CBaseEntity * this, Vector * posSrc) */

Vector * __thiscall
CBaseEntity::BodyTarget(Vector *__return_storage_ptr__,CBaseEntity *this,Vector *posSrc)

{
  (*this->_vptr_CBaseEntity[0x32])(__return_storage_ptr__,this);
  return __return_storage_ptr__;
}


// CBaseEntity::Illumination  @ 00059900  (line 343)

/* DWARF original prototype: int Illumination(CBaseEntity * this) */

int __thiscall CBaseEntity::Illumination(CBaseEntity *this)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00059911. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*g_engfuncs.pfnGetEntityIllum)(this->pev->pContainingEntity);
  return iVar1;
}


// CBaseEntity::EngineerUse  @ 00059920  (line 687)

/* DWARF original prototype: BOOL EngineerUse(CBaseEntity * this, CBasePlayer * pPlayer) */

BOOL __thiscall CBaseEntity::EngineerUse(CBaseEntity *this,CBasePlayer *pPlayer)

{
  return 0;
}


// CBaseEntity::Finished  @ 00059930  (line 693)

/* DWARF original prototype: void Finished(CBaseEntity * this) */

void __thiscall CBaseEntity::Finished(CBaseEntity *this)

{
  return;
}


// CBaseEntity::TeamFortress_Concuss  @ 00059940  (line 705)

/* DWARF original prototype: void TeamFortress_Concuss(CBaseEntity * this, entvars_t * pevGren) */

void __thiscall CBaseEntity::TeamFortress_Concuss(CBaseEntity *this,entvars_t *pevGren)

{
  return;
}


// CBaseDelay::~CBaseDelay  @ 00059d20  (line 822)

/* DWARF original prototype: void ~CBaseDelay(CBaseDelay * this, int __in_chrg) */

void __thiscall CBaseDelay::~CBaseDelay(CBaseDelay *this,int __in_chrg)

{
  return;
}


// CBaseAnimating::~CBaseAnimating  @ 00059d30  (line 839)

/* DWARF original prototype: void ~CBaseAnimating(CBaseAnimating * this, int __in_chrg) */

void __thiscall CBaseAnimating::~CBaseAnimating(CBaseAnimating *this,int __in_chrg)

{
  return;
}


// CBaseAnimating::HandleAnimEvent  @ 00059950  (line 855)

/* DWARF original prototype: void HandleAnimEvent(CBaseAnimating * this, MonsterEvent_t * pEvent) */

void __thiscall CBaseAnimating::HandleAnimEvent(CBaseAnimating *this,MonsterEvent_t *pEvent)

{
  return;
}


// CBaseToggle::~CBaseToggle  @ 00059d40  (line 895)

/* DWARF original prototype: void ~CBaseToggle(CBaseToggle * this, int __in_chrg) */

void __thiscall CBaseToggle::~CBaseToggle(CBaseToggle *this,int __in_chrg)

{
  return;
}


// CBaseToggle::GetToggleState  @ 00059960  (line 927)

/* DWARF original prototype: int GetToggleState(CBaseToggle * this) */

int __thiscall CBaseToggle::GetToggleState(CBaseToggle *this)

{
  return this->m_toggle_state;
}


// CBaseToggle::GetDelay  @ 00059970  (line 928)

/* DWARF original prototype: float GetDelay(CBaseToggle * this) */

float __thiscall CBaseToggle::GetDelay(CBaseToggle *this)

{
  return this->m_flWait;
}


// CBaseMonster::~CBaseMonster  @ 00059d50  (line 1082)

/* DWARF original prototype: void ~CBaseMonster(CBaseMonster * this, int __in_chrg) */

void __thiscall CBaseMonster::~CBaseMonster(CBaseMonster *this,int __in_chrg)

{
  return;
}


// CBaseMonster::BloodColor  @ 00059980  (line 1186)

/* DWARF original prototype: int BloodColor(CBaseMonster * this) */

int __thiscall CBaseMonster::BloodColor(CBaseMonster *this)

{
  return this->m_bloodColor;
}


// CBaseMonster::MyMonsterPointer  @ 00059990  (line 1188)

/* DWARF original prototype: CBaseMonster * MyMonsterPointer(CBaseMonster * this) */

CBaseMonster * __thiscall CBaseMonster::MyMonsterPointer(CBaseMonster *this)

{
  return this;
}


// CBaseMonster::IsAlive  @ 000599a0  (line 1193)

/* DWARF original prototype: BOOL IsAlive(CBaseMonster * this) */

BOOL __thiscall CBaseMonster::IsAlive(CBaseMonster *this)

{
  return (uint)(((this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
                pev)->deadflag != 2);
}


// CBaseMonster::GetStoppedActivity  @ 000599c0  (line 1224)

/* DWARF original prototype: Activity GetStoppedActivity(CBaseMonster * this) */

Activity __thiscall CBaseMonster::GetStoppedActivity(CBaseMonster *this)

{
  return ACT_IDLE;
}


// CBaseMonster::Stop  @ 00059e20  (line 1225)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void Stop(CBaseMonster * this) */

void __thiscall CBaseMonster::Stop(CBaseMonster *this)

{
  _func_int_varargs *p_Var1;
  Activity AVar2;
  
  p_Var1 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[0x53];
  if (p_Var1 == GetStoppedActivity) {
    this->m_IdealActivity = ACT_IDLE;
    return;
  }
  AVar2 = (*p_Var1)(this);
  this->m_IdealActivity = AVar2;
  return;
}


// CBaseMonster::ScheduleChange  @ 000599d0  (line 1252)

/* DWARF original prototype: void ScheduleChange(CBaseMonster * this) */

void __thiscall CBaseMonster::ScheduleChange(CBaseMonster *this)

{
  return;
}


// CBaseMonster::CanPlaySentence  @ 000599e0  (line 1255)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int CanPlaySentence(CBaseMonster * this, BOOL fDisregardState) */

int __thiscall CBaseMonster::CanPlaySentence(CBaseMonster *this,BOOL fDisregardState)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000599ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity[0x22])();
  return iVar1;
}


// CBaseMonster::SetYawSpeed  @ 000599f0  (line 1290)

/* DWARF original prototype: void SetYawSpeed(CBaseMonster * this) */

void __thiscall CBaseMonster::SetYawSpeed(CBaseMonster *this)

{
  return;
}


// CBaseMonster::FValidateCover  @ 00059a00  (line 1298)

/* DWARF original prototype: BOOL FValidateCover(CBaseMonster * this, Vector * vecCoverLocation) */

BOOL __thiscall CBaseMonster::FValidateCover(CBaseMonster *this,Vector *vecCoverLocation)

{
  return 1;
}


// CBaseMonster::CoverRadius  @ 00059a10  (line 1299)

/* DWARF original prototype: float CoverRadius(CBaseMonster * this) */

float __thiscall CBaseMonster::CoverRadius(CBaseMonster *this)

{
  return 784.0;
}


// CBaseMonster::CheckAmmo  @ 00059a20  (line 1302)

/* DWARF original prototype: void CheckAmmo(CBaseMonster * this) */

void __thiscall CBaseMonster::CheckAmmo(CBaseMonster *this)

{
  return;
}


// CBaseMonster::HearingSensitivity  @ 00059a30  (line 1327)

/* DWARF original prototype: float HearingSensitivity(CBaseMonster * this) */

float __thiscall CBaseMonster::HearingSensitivity(CBaseMonster *this)

{
  return 1.0;
}


// CBaseMonster::PrescheduleThink  @ 00059a40  (line 1347)

/* DWARF original prototype: void PrescheduleThink(CBaseMonster * this) */

void __thiscall CBaseMonster::PrescheduleThink(CBaseMonster *this)

{
  return;
}


// CBaseMonster::BodyTarget  @ 0005a000  (line 1369)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: Vector BodyTarget(CBaseMonster * this, Vector * posSrc) */

Vector * __thiscall
CBaseMonster::BodyTarget(Vector *__return_storage_ptr__,CBaseMonster *this,Vector *posSrc)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  entvars_t *peVar6;
  _func_int_varargs *p_Var7;
  _func_int_varargs **pp_Var8;
  float **ppfVar9;
  undefined4 uStack_50;
  float *local_4c;
  CBaseMonster *local_48;
  Vector *local_40;
  Vector *local_3c;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  ppfVar9 = &local_4c;
  pp_Var8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
            _vptr_CBaseEntity;
  if (pp_Var8[0x33] == CBaseEntity::EyePosition) {
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    local_10 = (peVar6->origin).z + (peVar6->view_ofs).z;
    local_14 = (peVar6->origin).y + (peVar6->view_ofs).y;
    local_1c = (peVar6->origin).x + (peVar6->view_ofs).x;
    fVar5 = local_10;
    fVar4 = local_14;
    local_18 = local_1c;
  }
  else {
    local_4c = &local_18;
    local_3c = __return_storage_ptr__;
    local_48 = this;
    uStack_50 = 0x5a0f1;
    (*pp_Var8[0x33])();
    pp_Var8 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
              _vptr_CBaseEntity;
    ppfVar9 = (float **)&uStack_50;
    __return_storage_ptr__ = local_40;
    fVar5 = local_14;
    fVar4 = local_18;
  }
  fVar5 = fVar5 * 0.25;
  p_Var7 = pp_Var8[0x32];
  fVar4 = fVar4 * 0.25;
  local_1c = local_1c * 0.25;
  if (p_Var7 == CBaseEntity::Center) {
    peVar6 = (this->super_CBaseToggle).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.pev;
    fVar1 = ((peVar6->absmax).z + (peVar6->absmin).z) * 0.5;
    fVar2 = ((peVar6->absmax).y + (peVar6->absmin).y) * 0.5;
    fVar3 = ((peVar6->absmax).x + (peVar6->absmin).x) * 0.5;
  }
  else {
    ppfVar9[6] = (float *)local_1c;
    ppfVar9[5] = (float *)fVar4;
    ppfVar9[4] = (float *)fVar5;
    ppfVar9[7] = &__return_storage_ptr__->x;
    ppfVar9[1] = (float *)this;
    *ppfVar9 = (float *)(ppfVar9 + 10);
    ppfVar9[-1] = (float *)0x5a12f;
    (*p_Var7)();
    fVar1 = (float)ppfVar9[0xb];
    fVar2 = (float)ppfVar9[10];
    fVar3 = (float)ppfVar9[9];
    local_1c = (float)ppfVar9[5];
    fVar4 = (float)ppfVar9[4];
    __return_storage_ptr__ = (Vector *)ppfVar9[6];
    fVar5 = (float)ppfVar9[3];
  }
  __return_storage_ptr__->x = fVar3 * 0.75 + local_1c;
  __return_storage_ptr__->y = fVar2 * 0.75 + fVar4;
  __return_storage_ptr__->z = fVar1 * 0.75 + fVar5;
  return __return_storage_ptr__;
}


// CBaseMonster::IsMoving  @ 00059a50  (line 1379)

/* DWARF original prototype: int IsMoving(CBaseMonster * this) */

int __thiscall CBaseMonster::IsMoving(CBaseMonster *this)

{
  return (uint)(this->m_movementGoal != 0);
}


// CBaseMonster::DeathSound  @ 00059a70  (line 1384)

/* DWARF original prototype: void DeathSound(CBaseMonster * this) */

void __thiscall CBaseMonster::DeathSound(CBaseMonster *this)

{
  return;
}


// CBaseMonster::AlertSound  @ 00059a80  (line 1385)

/* DWARF original prototype: void AlertSound(CBaseMonster * this) */

void __thiscall CBaseMonster::AlertSound(CBaseMonster *this)

{
  return;
}


// CBaseMonster::IdleSound  @ 00059a90  (line 1386)

/* DWARF original prototype: void IdleSound(CBaseMonster * this) */

void __thiscall CBaseMonster::IdleSound(CBaseMonster *this)

{
  return;
}


// CBaseMonster::PainSound  @ 00059aa0  (line 1387)

/* DWARF original prototype: void PainSound(CBaseMonster * this) */

void __thiscall CBaseMonster::PainSound(CBaseMonster *this)

{
  return;
}


// CBaseMonster::StopFollowing  @ 00059ab0  (line 1389)

/* DWARF original prototype: void StopFollowing(CBaseMonster * this, BOOL clearSchedule) */

void __thiscall CBaseMonster::StopFollowing(CBaseMonster *this,BOOL clearSchedule)

{
  return;
}


