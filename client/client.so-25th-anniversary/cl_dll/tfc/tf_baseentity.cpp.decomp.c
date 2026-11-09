// Ghidra decompilation of functions from cl_dll/tfc/tf_baseentity.cpp
// 226 functions, ordered by original source line

// CBaseEntity::TakeHealth  @ 00058580  (line 26)

/* DWARF original prototype: int TakeHealth(CBaseEntity * this, float flHealth, int bitsDamageType)
    */

int __thiscall CBaseEntity::TakeHealth(CBaseEntity *this,float flHealth,int bitsDamageType)

{
  return 1;
}


// CBaseEntity::TakeDamage  @ 00058590  (line 27)

/* DWARF original prototype: int TakeDamage(CBaseEntity * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBaseEntity::TakeDamage
          (CBaseEntity *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  return 1;
}


// CBaseEntity::ShouldToggle  @ 00058890  (line 36)

/* DWARF original prototype: int ShouldToggle(CBaseEntity * this, USE_TYPE useType, BOOL
   currentState) */

int __thiscall CBaseEntity::ShouldToggle(CBaseEntity *this,USE_TYPE useType,BOOL currentState)

{
  return 0;
}


// CBaseEntity::Create  @ 000588a0  (line 36)

/* CBaseEntity::Create(char*, Vector const&, Vector const&, edict_s*) */

undefined4 CBaseEntity::Create(char *param_1,Vector *param_2,Vector *param_3,edict_s *param_4)

{
  return 0;
}


// CBaseEntity::SUB_Remove  @ 000588b0  (line 36)

/* CBaseEntity::SUB_Remove() */

void CBaseEntity::SUB_Remove(void)

{
  return;
}


// CBaseEntity::Timer_Tranquilisation  @ 000588c0  (line 36)

/* CBaseEntity::Timer_Tranquilisation() */

void CBaseEntity::Timer_Tranquilisation(void)

{
  return;
}


// CBaseEntity::CreateTimer  @ 000588d0  (line 36)

/* CBaseEntity::CreateTimer(int) */

undefined4 CBaseEntity::CreateTimer(int param_1)

{
  return 0;
}


// CBaseEntity::IsAlly  @ 000588e0  (line 36)

/* CBaseEntity::IsAlly(CBaseEntity*) */

undefined4 CBaseEntity::IsAlly(CBaseEntity *param_1)

{
  return 1;
}


// CBaseEntity::TeamFortress_EMPExplode  @ 000585a0  (line 39)

/* DWARF original prototype: void TeamFortress_EMPExplode(CBaseEntity * this, entvars_t * pevGren,
   float damage, float radius) */

void __thiscall
CBaseEntity::TeamFortress_EMPExplode(CBaseEntity *this,entvars_t *pevGren,float damage,float radius)

{
  return;
}


// CBaseEntity::DB_GetItemName  @ 000585b0  (line 50)

/* DWARF original prototype: char * DB_GetItemName(CBaseEntity * this) */

char * __thiscall CBaseEntity::DB_GetItemName(CBaseEntity *this)

{
  return "";
}


// CBaseEntity::operator_new  @ 000588f0  (line 51)

/* DWARF original name: operator new */

void * CBaseEntity::operator_new(size_t stAllocateBlock,entvars_t *pev)

{
  return (void *)0x0;
}


// DBG_EntOfVars  @ 00058900  (line 51)

/* DBG_EntOfVars(entvars_s const*) */

undefined4 DBG_EntOfVars(entvars_s *param_1)

{
  return 0;
}


// DBG_AssertFunction  @ 00058910  (line 64)

void DBG_AssertFunction(BOOL fExpr,char *szExpr,char *szFile,int szLine,char *szMessage)

{
  return;
}


// UTIL_PrecacheOther  @ 00058920  (line 64)

/* UTIL_PrecacheOther(char const*) */

void UTIL_PrecacheOther(char *param_1)

{
  return;
}


// UTIL_BloodDrips  @ 00058930  (line 64)

/* UTIL_BloodDrips(Vector const&, Vector const&, int, int) */

void UTIL_BloodDrips(Vector *param_1,Vector *param_2,int param_3,int param_4)

{
  return;
}


// UTIL_DecalTrace  @ 00058940  (line 64)

/* UTIL_DecalTrace(TraceResult*, int) */

void UTIL_DecalTrace(TraceResult *param_1,int param_2)

{
  return;
}


// UTIL_GunshotDecalTrace  @ 00058950  (line 64)

/* UTIL_GunshotDecalTrace(TraceResult*, int) */

void UTIL_GunshotDecalTrace(TraceResult *param_1,int param_2)

{
  return;
}


// UTIL_MakeVectors  @ 00058960  (line 64)

/* UTIL_MakeVectors(Vector const&) */

void UTIL_MakeVectors(Vector *param_1)

{
  return;
}


// UTIL_IsValidEntity  @ 00058970  (line 64)

/* UTIL_IsValidEntity(edict_s*) */

undefined4 UTIL_IsValidEntity(edict_s *param_1)

{
  return 1;
}


// UTIL_SetOrigin  @ 00058980  (line 64)

/* UTIL_SetOrigin(entvars_s*, Vector const&) */

void UTIL_SetOrigin(entvars_s *param_1,Vector *param_2)

{
  return;
}


// UTIL_LogPrintf  @ 00058990  (line 75)

void UTIL_LogPrintf(char *param_1,...)

{
  return;
}


// UTIL_ClientPrintAll  @ 000589a0  (line 76)

void UTIL_ClientPrintAll(int param_1,char *param_2,char *param_3,char *param_4,char *param_5,
                        char *param_6)

{
  return;
}


// ClientPrint  @ 000589b0  (line 77)

void ClientPrint(entvars_t *client,int msg_dest,char *msg_name,char *param1,char *param2,
                char *param3,char *param4)

{
  return;
}


// CGrenade::CGrenade  @ 000589c0  (line 85)

/* DWARF original prototype: void CGrenade(CGrenade * this) */

void __thiscall CGrenade::CGrenade(CGrenade *this)

{
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CGrenade_000c0484;
  return;
}


// CTFNailgunNail::CreateTranqNail  @ 000589d0  (line 85)

/* CTFNailgunNail::CreateTranqNail(Vector, Vector, CBaseEntity*, CBaseEntity*) */

undefined4
CTFNailgunNail::CreateTranqNail
          (Vector param_1,Vector param_2,CBaseEntity *param_3,CBaseEntity *param_4)

{
  return 0;
}


// CGrenade::Explode  @ 000585c0  (line 90)

/* DWARF original prototype: void Explode(CGrenade * this, 11TraceResult * param_1, int param_2) */

void __thiscall CGrenade::Explode(CGrenade *this,_1TraceResult *param_1,int param_2)

{
  return;
}


// CTFNailgunNail::CreateNail  @ 000589e0  (line 96)

CTFNailgunNail *
CTFNailgunNail::CreateNail
          (BOOL fSendClientNail,Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,
          CBaseEntity *pLauncher,BOOL fCreateClientNail)

{
  return (CTFNailgunNail *)0x0;
}


// CTFNailgunNail::CreateSuperNail  @ 000589f0  (line 96)

/* CTFNailgunNail::CreateSuperNail(Vector, Vector, CBaseEntity*, CBaseEntity*) */

undefined4
CTFNailgunNail::CreateSuperNail
          (Vector param_1,Vector param_2,CBaseEntity *param_3,CBaseEntity *param_4)

{
  return 0;
}


// CTFNailgunNail::CreateRailgunNail  @ 00058a00  (line 96)

/* CTFNailgunNail::CreateRailgunNail(Vector, Vector, CBaseEntity*, CBaseEntity*) */

undefined4
CTFNailgunNail::CreateRailgunNail
          (Vector param_1,Vector param_2,CBaseEntity *param_3,CBaseEntity *param_4)

{
  return 0;
}


// CTFIncendiaryCRocket::CreateRpgRocket  @ 00058a10  (line 96)

/* CTFIncendiaryCRocket::CreateRpgRocket(Vector, Vector, CBaseEntity*, CTFIncendiaryC*) */

undefined4
CTFIncendiaryCRocket::CreateRpgRocket
          (Vector param_1,Vector param_2,CBaseEntity *param_3,CTFIncendiaryC *param_4)

{
  return 0;
}


// CTFFlamethrowerBurst::CreateBurst  @ 00058a20  (line 96)

/* CTFFlamethrowerBurst::CreateBurst(Vector, Vector, CBaseEntity*, CTFFlamethrower*) */

undefined4
CTFFlamethrowerBurst::CreateBurst
          (Vector param_1,Vector param_2,CBaseEntity *param_3,CTFFlamethrower *param_4)

{
  return 0;
}


// CTFRpgRocket::CreateRpgRocket  @ 00058a30  (line 96)

/* CTFRpgRocket::CreateRpgRocket(Vector, Vector, CBaseEntity*, CTFRpg*) */

undefined4
CTFRpgRocket::CreateRpgRocket(Vector param_1,Vector param_2,CBaseEntity *param_3,CTFRpg *param_4)

{
  return 0;
}


// CTFRpgRocket::RocketTouch  @ 00058a40  (line 96)

/* CTFRpgRocket::RocketTouch(CBaseEntity*) */

void CTFRpgRocket::RocketTouch(CBaseEntity *param_1)

{
  return;
}


// CTFGrenade::CreateTFGrenade  @ 00058a50  (line 96)

/* CTFGrenade::CreateTFGrenade(Vector, Vector, CBaseEntity*, CTFGrenadeLauncher*) */

undefined4
CTFGrenade::CreateTFGrenade
          (Vector param_1,Vector param_2,CBaseEntity *param_3,CTFGrenadeLauncher *param_4)

{
  return 0;
}


// CTFGrenade::CreateTFPipebomb  @ 00058a60  (line 118)

CTFGrenade *
CTFGrenade::CreateTFPipebomb
          (Vector vecOrigin,Vector vecAngles,CBaseEntity *pOwner,CTFGrenadeLauncher *pLauncher)

{
  return (CTFGrenade *)0x0;
}


// CLaserSpot::Suspend  @ 00058a70  (line 118)

/* CLaserSpot::Suspend(float) */

void CLaserSpot::Suspend(float param_1)

{
  return;
}


// CLaserSpot::Revive  @ 00058a80  (line 118)

/* CLaserSpot::Revive() */

void CLaserSpot::Revive(void)

{
  return;
}


// CBaseMonster::CheckTraceHullAttack  @ 00058a90  (line 126)

/* DWARF original prototype: CBaseEntity * CheckTraceHullAttack(CBaseMonster * this, float flDist,
   int iDamage, int iDmgType) */

CBaseEntity * __thiscall
CBaseMonster::CheckTraceHullAttack(CBaseMonster *this,float flDist,int iDamage,int iDmgType)

{
  return (CBaseEntity *)0x0;
}


// CBaseMonster::Eat  @ 00058aa0  (line 126)

/* CBaseMonster::Eat(float) */

void CBaseMonster::Eat(float param_1)

{
  return;
}


// CBaseMonster::FShouldEat  @ 00058ab0  (line 126)

/* CBaseMonster::FShouldEat() */

undefined4 CBaseMonster::FShouldEat(void)

{
  return 1;
}


// CBaseMonster::Listen  @ 00058ac0  (line 126)

/* CBaseMonster::Listen() */

void CBaseMonster::Listen(void)

{
  return;
}


// CBaseMonster::FLSoundVolume  @ 00058ad0  (line 126)

/* CBaseMonster::FLSoundVolume(CSound*) */

longdouble CBaseMonster::FLSoundVolume(CSound *param_1)

{
  return (longdouble)0;
}


// CBaseMonster::FValidateHintType  @ 000585d0  (line 133)

/* DWARF original prototype: BOOL FValidateHintType(CBaseMonster * this, short sHint) */

BOOL __thiscall CBaseMonster::FValidateHintType(CBaseMonster *this,short sHint)

{
  return 0;
}


// CBaseAnimating::StudioFrameAdvance  @ 00058ae0  (line 138)

/* DWARF original prototype: float StudioFrameAdvance(CBaseAnimating * this, float flInterval) */

float __thiscall CBaseAnimating::StudioFrameAdvance(CBaseAnimating *this,float flInterval)

{
  return 0.0;
}


// CBaseMonster::MonsterUse  @ 00058af0  (line 140)

/* DWARF original prototype: void MonsterUse(CBaseMonster * this, CBaseEntity * pActivator,
   CBaseEntity * pCaller, USE_TYPE useType, float value) */

void __thiscall
CBaseMonster::MonsterUse
          (CBaseMonster *this,CBaseEntity *pActivator,CBaseEntity *pCaller,USE_TYPE useType,
          float value)

{
  return;
}


// CBaseMonster::RouteClear  @ 00058b00  (line 140)

/* CBaseMonster::RouteClear() */

void CBaseMonster::RouteClear(void)

{
  return;
}


// CBaseMonster::RouteNew  @ 00058b10  (line 140)

/* CBaseMonster::RouteNew() */

void CBaseMonster::RouteNew(void)

{
  return;
}


// CBaseMonster::FRouteClear  @ 00058b20  (line 140)

/* CBaseMonster::FRouteClear() */

undefined4 CBaseMonster::FRouteClear(void)

{
  return 0;
}


// CBaseMonster::FRefreshRoute  @ 00058b30  (line 140)

/* CBaseMonster::FRefreshRoute() */

undefined4 CBaseMonster::FRefreshRoute(void)

{
  return 0;
}


// CBaseMonster::MoveToEnemy  @ 00058b40  (line 140)

/* CBaseMonster::MoveToEnemy(Activity, float) */

undefined4 CBaseMonster::MoveToEnemy(Activity param_1,float param_2)

{
  return 0;
}


// CBaseMonster::MoveToLocation  @ 00058b50  (line 140)

/* CBaseMonster::MoveToLocation(Activity, float, Vector const&) */

undefined4 CBaseMonster::MoveToLocation(Activity param_1,float param_2,Vector *param_3)

{
  return 0;
}


// CBaseMonster::MoveToTarget  @ 00058b60  (line 148)

/* DWARF original prototype: BOOL MoveToTarget(CBaseMonster * this, Activity movementAct, float
   waitTime) */

BOOL __thiscall CBaseMonster::MoveToTarget(CBaseMonster *this,Activity movementAct,float waitTime)

{
  return 0;
}


// CBaseMonster::MoveToNode  @ 00058b70  (line 149)

/* DWARF original prototype: BOOL MoveToNode(CBaseMonster * this, Activity movementAct, float
   waitTime, Vector * goal) */

BOOL __thiscall
CBaseMonster::MoveToNode(CBaseMonster *this,Activity movementAct,float waitTime,Vector *goal)

{
  return 0;
}


// ShouldSimplify  @ 00058b80  (line 150)

int ShouldSimplify(int routeType)

{
  return 1;
}


// CBaseMonster::RouteSimplify  @ 00058b90  (line 150)

/* CBaseMonster::RouteSimplify(CBaseEntity*) */

void CBaseMonster::RouteSimplify(CBaseEntity *param_1)

{
  return;
}


// CBaseMonster::PushEnemy  @ 00058ba0  (line 150)

/* CBaseMonster::PushEnemy(CBaseEntity*, Vector&) */

void CBaseMonster::PushEnemy(CBaseEntity *param_1,Vector *param_2)

{
  return;
}


// CBaseMonster::PopEnemy  @ 00058bb0  (line 150)

/* CBaseMonster::PopEnemy() */

undefined4 CBaseMonster::PopEnemy(void)

{
  return 0;
}


// CBaseMonster::SetSequenceByName  @ 00058bc0  (line 150)

/* CBaseMonster::SetSequenceByName(char*) */

void CBaseMonster::SetSequenceByName(char *param_1)

{
  return;
}


// CBaseMonster::CheckMeleeAttack2  @ 000585e0  (line 156)

/* DWARF original prototype: BOOL CheckMeleeAttack2(CBaseMonster * this, float flDot, float flDist)
    */

BOOL __thiscall CBaseMonster::CheckMeleeAttack2(CBaseMonster *this,float flDot,float flDist)

{
  return 0;
}


// CBaseMonster::CheckLocalMove  @ 000585f0  (line 164)

/* DWARF original prototype: int CheckLocalMove(CBaseMonster * this, Vector * vecStart, Vector *
   vecEnd, CBaseEntity * pTarget, float * pflDist) */

int __thiscall
CBaseMonster::CheckLocalMove
          (CBaseMonster *this,Vector *vecStart,Vector *vecEnd,CBaseEntity *pTarget,float *pflDist)

{
  return 0;
}


// CBaseMonster::OpenDoorAndWait  @ 00058bd0  (line 165)

/* DWARF original prototype: float OpenDoorAndWait(CBaseMonster * this, entvars_t * pevDoor) */

float __thiscall CBaseMonster::OpenDoorAndWait(CBaseMonster *this,entvars_t *pevDoor)

{
  return 0.0;
}


// CBaseMonster::AdvanceRoute  @ 00058be0  (line 165)

/* CBaseMonster::AdvanceRoute(float) */

void CBaseMonster::AdvanceRoute(float param_1)

{
  return;
}


// CBaseMonster::RouteClassify  @ 00058bf0  (line 165)

/* CBaseMonster::RouteClassify(int) */

undefined4 CBaseMonster::RouteClassify(int param_1)

{
  return 0;
}


// CBaseMonster::BuildRoute  @ 00058c00  (line 168)

/* DWARF original prototype: BOOL BuildRoute(CBaseMonster * this, Vector * vecGoal, int iMoveFlag,
   CBaseEntity * pTarget) */

BOOL __thiscall
CBaseMonster::BuildRoute(CBaseMonster *this,Vector *vecGoal,int iMoveFlag,CBaseEntity *pTarget)

{
  return 0;
}


// CBaseMonster::InsertWaypoint  @ 00058c10  (line 169)

/* DWARF original prototype: void InsertWaypoint(CBaseMonster * this, Vector vecLocation, int
   afMoveFlags) */

void __thiscall CBaseMonster::InsertWaypoint(CBaseMonster *this,Vector vecLocation,int afMoveFlags)

{
  return;
}


// CBaseMonster::MonsterInitThink  @ 00058c20  (line 169)

/* CBaseMonster::MonsterInitThink() */

void CBaseMonster::MonsterInitThink(void)

{
  return;
}


// CBaseMonster::MovementComplete  @ 00058c30  (line 169)

/* CBaseMonster::MovementComplete() */

void CBaseMonster::MovementComplete(void)

{
  return;
}


// CBaseMonster::TaskIsRunning  @ 00058c40  (line 169)

/* CBaseMonster::TaskIsRunning() */

undefined4 CBaseMonster::TaskIsRunning(void)

{
  return 0;
}


// CBaseMonster::FTriangulate  @ 00058600  (line 170)

/* DWARF original prototype: BOOL FTriangulate(CBaseMonster * this, Vector * vecStart, Vector *
   vecEnd, float flDist, CBaseEntity * pTargetEnt, Vector * pApex) */

BOOL __thiscall
CBaseMonster::FTriangulate
          (CBaseMonster *this,Vector *vecStart,Vector *vecEnd,float flDist,CBaseEntity *pTargetEnt,
          Vector *pApex)

{
  return 0;
}


// CBaseMonster::ShouldAdvanceRoute  @ 00058610  (line 172)

/* DWARF original prototype: BOOL ShouldAdvanceRoute(CBaseMonster * this, float flWaypointDist) */

BOOL __thiscall CBaseMonster::ShouldAdvanceRoute(CBaseMonster *this,float flWaypointDist)

{
  return 0;
}


// CBaseMonster::BuildNearestRoute  @ 00058620  (line 181)

/* DWARF original prototype: BOOL BuildNearestRoute(CBaseMonster * this, Vector vecThreat, Vector
   vecViewOffset, float flMinDist, float flMaxDist) */

BOOL __thiscall
CBaseMonster::BuildNearestRoute
          (CBaseMonster *this,Vector vecThreat,Vector vecViewOffset,float flMinDist,float flMaxDist)

{
  return 0;
}


// CBaseMonster::MakeIdealYaw  @ 00058c50  (line 187)

/* DWARF original prototype: void MakeIdealYaw(CBaseMonster * this, Vector vecTarget) */

void __thiscall CBaseMonster::MakeIdealYaw(CBaseMonster *this,Vector vecTarget)

{
  return;
}


// CBaseMonster::FlYawDiff  @ 00058c60  (line 188)

/* DWARF original prototype: float FlYawDiff(CBaseMonster * this) */

float __thiscall CBaseMonster::FlYawDiff(CBaseMonster *this)

{
  return 0.0;
}


// CBaseMonster::ChangeYaw  @ 00058630  (line 189)

/* DWARF original prototype: float ChangeYaw(CBaseMonster * this, int yawSpeed) */

float __thiscall CBaseMonster::ChangeYaw(CBaseMonster *this,int yawSpeed)

{
  return 0.0;
}


// CBaseMonster::VecToYaw  @ 00058c70  (line 190)

/* DWARF original prototype: float VecToYaw(CBaseMonster * this, Vector vecDir) */

float __thiscall CBaseMonster::VecToYaw(CBaseMonster *this,Vector vecDir)

{
  return 0.0;
}


// CBaseAnimating::LookupActivity  @ 00058c80  (line 190)

/* CBaseAnimating::LookupActivity(int) */

undefined4 CBaseAnimating::LookupActivity(int param_1)

{
  return 0;
}


// CBaseAnimating::LookupActivityHeaviest  @ 00058c90  (line 190)

/* CBaseAnimating::LookupActivityHeaviest(int) */

undefined4 CBaseAnimating::LookupActivityHeaviest(int param_1)

{
  return 0;
}


// CBaseMonster::SetEyePosition  @ 00058ca0  (line 190)

/* CBaseMonster::SetEyePosition() */

void CBaseMonster::SetEyePosition(void)

{
  return;
}


// CBaseAnimating::LookupSequence  @ 00058cb0  (line 190)

/* CBaseAnimating::LookupSequence(char const*) */

undefined4 CBaseAnimating::LookupSequence(char *param_1)

{
  return 0;
}


// CBaseAnimating::ResetSequenceInfo  @ 00058cc0  (line 190)

/* CBaseAnimating::ResetSequenceInfo() */

void CBaseAnimating::ResetSequenceInfo(void)

{
  return;
}


// CBaseAnimating::GetSequenceFlags  @ 00058cd0  (line 190)

/* CBaseAnimating::GetSequenceFlags() */

undefined4 CBaseAnimating::GetSequenceFlags(void)

{
  return 0;
}


// CBaseAnimating::SetBoneController  @ 00058ce0  (line 190)

/* CBaseAnimating::SetBoneController(int, float) */

longdouble CBaseAnimating::SetBoneController(int param_1,float param_2)

{
  return (longdouble)0;
}


// CBaseAnimating::InitBoneControllers  @ 00058cf0  (line 190)

/* CBaseAnimating::InitBoneControllers() */

void CBaseAnimating::InitBoneControllers(void)

{
  return;
}


// CBaseAnimating::DispatchAnimEvents  @ 00058640  (line 197)

/* DWARF original prototype: void DispatchAnimEvents(CBaseAnimating * this, float flInterval) */

void __thiscall CBaseAnimating::DispatchAnimEvents(CBaseAnimating *this,float flInterval)

{
  return;
}


// CBaseAnimating::SetBlending  @ 00058d00  (line 201)

/* DWARF original prototype: float SetBlending(CBaseAnimating * this, int iBlender, float flValue)
    */

float __thiscall CBaseAnimating::SetBlending(CBaseAnimating *this,int iBlender,float flValue)

{
  return 0.0;
}


// CBaseAnimating::GetBonePosition  @ 00058d10  (line 201)

/* CBaseAnimating::GetBonePosition(int, Vector&, Vector&) */

void CBaseAnimating::GetBonePosition(int param_1,Vector *param_2,Vector *param_3)

{
  return;
}


// CBaseAnimating::GetAttachment  @ 00058d20  (line 203)

/* DWARF original prototype: void GetAttachment(CBaseAnimating * this, int iAttachment, Vector *
   origin, Vector * angles) */

void __thiscall
CBaseAnimating::GetAttachment(CBaseAnimating *this,int iAttachment,Vector *origin,Vector *angles)

{
  return;
}


// CBaseAnimating::FindTransition  @ 00058d30  (line 204)

/* DWARF original prototype: int FindTransition(CBaseAnimating * this, int iEndingSequence, int
   iGoalSequence, int * piDir) */

int __thiscall
CBaseAnimating::FindTransition
          (CBaseAnimating *this,int iEndingSequence,int iGoalSequence,int *piDir)

{
  return -1;
}


// CBaseAnimating::GetAutomovement  @ 00058650  (line 205)

/* DWARF original prototype: void GetAutomovement(CBaseAnimating * this, Vector * origin, Vector *
   angles, float flInterval) */

void __thiscall
CBaseAnimating::GetAutomovement(CBaseAnimating *this,Vector *origin,Vector *angles,float flInterval)

{
  return;
}


// CBaseAnimating::SetBodygroup  @ 00058d40  (line 206)

/* DWARF original prototype: void SetBodygroup(CBaseAnimating * this, int iGroup, int iValue) */

void __thiscall CBaseAnimating::SetBodygroup(CBaseAnimating *this,int iGroup,int iValue)

{
  return;
}


// CBaseAnimating::GetBodygroup  @ 00058d50  (line 206)

/* CBaseAnimating::GetBodygroup(int) */

undefined4 CBaseAnimating::GetBodygroup(int param_1)

{
  return 0;
}


// CBaseMonster::GetGunPosition  @ 00058d60  (line 208)

/* DWARF original prototype: Vector GetGunPosition(CBaseMonster * this) */

Vector * __thiscall CBaseMonster::GetGunPosition(Vector *__return_storage_ptr__,CBaseMonster *this)

{
  __return_storage_ptr__->x = g_vecZero.x;
  __return_storage_ptr__->y = g_vecZero.y;
  __return_storage_ptr__->z = g_vecZero.z;
  return __return_storage_ptr__;
}


// CBaseEntity::FireBullets  @ 00058d90  (line 210)

/* DWARF original prototype: void FireBullets(CBaseEntity * this, ULONG cShots, Vector vecSrc,
   Vector vecDirShooting, Vector vecSpread, float flDistance, int iBulletType, int iTracerFreq, int
   iDamage, entvars_t * pevAttacker) */

void __thiscall
CBaseEntity::FireBullets
          (CBaseEntity *this,ULONG cShots,Vector vecSrc,Vector vecDirShooting,Vector vecSpread,
          float flDistance,int iBulletType,int iTracerFreq,int iDamage,entvars_t *pevAttacker)

{
  return;
}


// CBaseEntity::TraceBleed  @ 00058660  (line 211)

/* DWARF original prototype: void TraceBleed(CBaseEntity * this, float flDamage, Vector vecDir,
   11TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBaseEntity::TraceBleed
          (CBaseEntity *this,float flDamage,Vector vecDir,_1TraceResult *ptr,int bitsDamageType)

{
  return;
}


// CBaseMonster::MakeDamageBloodDecal  @ 00058da0  (line 212)

/* DWARF original prototype: void MakeDamageBloodDecal(CBaseMonster * this, int cCount, float
   flNoise, 11TraceResult * ptr, Vector * vecDir) */

void __thiscall
CBaseMonster::MakeDamageBloodDecal
          (CBaseMonster *this,int cCount,float flNoise,_1TraceResult *ptr,Vector *vecDir)

{
  return;
}


// CBaseMonster::FGetNodeRoute  @ 00058db0  (line 213)

/* DWARF original prototype: BOOL FGetNodeRoute(CBaseMonster * this, Vector vecDest) */

BOOL __thiscall CBaseMonster::FGetNodeRoute(CBaseMonster *this,Vector vecDest)

{
  return 1;
}


// CBaseMonster::FindHintNode  @ 00058dc0  (line 213)

/* CBaseMonster::FindHintNode() */

undefined4 CBaseMonster::FindHintNode(void)

{
  return 0xffffffff;
}


// CBaseMonster::FCheckAITrigger  @ 00058dd0  (line 213)

/* CBaseMonster::FCheckAITrigger() */

undefined4 CBaseMonster::FCheckAITrigger(void)

{
  return 0;
}


// CBaseMonster::FindLateralCover  @ 00058de0  (line 219)

/* DWARF original prototype: BOOL FindLateralCover(CBaseMonster * this, Vector * vecThreat, Vector *
   vecViewOffset) */

BOOL __thiscall
CBaseMonster::FindLateralCover(CBaseMonster *this,Vector *vecThreat,Vector *vecViewOffset)

{
  return 0;
}


// CBaseMonster::ShootAtEnemy  @ 00058df0  (line 220)

/* DWARF original prototype: Vector ShootAtEnemy(CBaseMonster * this, Vector * shootOrigin) */

Vector * __thiscall
CBaseMonster::ShootAtEnemy(Vector *__return_storage_ptr__,CBaseMonster *this,Vector *shootOrigin)

{
  __return_storage_ptr__->x = g_vecZero.x;
  __return_storage_ptr__->y = g_vecZero.y;
  __return_storage_ptr__->z = g_vecZero.z;
  return __return_storage_ptr__;
}


// CBaseMonster::FacingIdeal  @ 00058e20  (line 220)

/* CBaseMonster::FacingIdeal() */

undefined4 CBaseMonster::FacingIdeal(void)

{
  return 0;
}


// CBaseMonster::CorpseFallThink  @ 00058e30  (line 220)

/* CBaseMonster::CorpseFallThink() */

void CBaseMonster::CorpseFallThink(void)

{
  return;
}


// CBaseMonster::BBoxFlat  @ 00058e40  (line 220)

/* CBaseMonster::BBoxFlat() */

undefined4 CBaseMonster::BBoxFlat(void)

{
  return 1;
}


// CBaseMonster::GetEnemy  @ 00058e50  (line 220)

/* CBaseMonster::GetEnemy() */

undefined4 CBaseMonster::GetEnemy(void)

{
  return 0;
}


// CBaseMonster::PlaySentence  @ 00058670  (line 223)

/* DWARF original prototype: void PlaySentence(CBaseMonster * this, char * pszSentence, float
   duration, float volume, float attenuation) */

void __thiscall
CBaseMonster::PlaySentence
          (CBaseMonster *this,char *pszSentence,float duration,float volume,float attenuation)

{
  return;
}


// CBaseMonster::PlayScriptedSentence  @ 00058680  (line 224)

/* DWARF original prototype: void PlayScriptedSentence(CBaseMonster * this, char * pszSentence,
   float duration, float volume, float attenuation, BOOL bConcurrent, CBaseEntity * pListener) */

void __thiscall
CBaseMonster::PlayScriptedSentence
          (CBaseMonster *this,char *pszSentence,float duration,float volume,float attenuation,
          BOOL bConcurrent,CBaseEntity *pListener)

{
  return;
}


// CBaseMonster::DropItem  @ 00058e60  (line 231)

/* DWARF original prototype: CBaseEntity * DropItem(CBaseMonster * this, char * pszItemName, Vector
   * vecPos, Vector * vecAng) */

CBaseEntity * __thiscall
CBaseMonster::DropItem(CBaseMonster *this,char *pszItemName,Vector *vecPos,Vector *vecAng)

{
  return (CBaseEntity *)0x0;
}


// CBaseMonster::RadiusDamage  @ 00058690  (line 233)

/* DWARF original prototype: void RadiusDamage(CBaseMonster * this, entvars_t * pevInflictor,
   entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType) */

void __thiscall
CBaseMonster::RadiusDamage
          (CBaseMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int iClassIgnore,int bitsDamageType)

{
  return;
}


// CBaseMonster::RadiusDamage  @ 000586a0  (line 234)

/* DWARF original prototype: void RadiusDamage(CBaseMonster * this, Vector vecSrc, entvars_t *
   pevInflictor, entvars_t * pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType) */

void __thiscall
CBaseMonster::RadiusDamage
          (CBaseMonster *this,Vector vecSrc,entvars_t *pevInflictor,entvars_t *pevAttacker,
          float flDamage,int iClassIgnore,int bitsDamageType)

{
  return;
}


// CBaseMonster::GetDeathActivity  @ 000586b0  (line 239)

/* DWARF original prototype: Activity GetDeathActivity(CBaseMonster * this) */

Activity __thiscall CBaseMonster::GetDeathActivity(CBaseMonster *this)

{
  return ACT_DIE_HEADSHOT;
}


// CBaseMonster::GetIdealState  @ 000586c0  (line 240)

/* DWARF original prototype: MONSTERSTATE GetIdealState(CBaseMonster * this) */

MONSTERSTATE __thiscall CBaseMonster::GetIdealState(CBaseMonster *this)

{
  return MONSTERSTATE_ALERT;
}


// CBaseMonster::GetScheduleOfType  @ 000586d0  (line 241)

/* DWARF original prototype: Schedule_t * GetScheduleOfType(CBaseMonster * this, int Type) */

Schedule_t * __thiscall CBaseMonster::GetScheduleOfType(CBaseMonster *this,int Type)

{
  return (Schedule_t *)0x0;
}


// CBaseMonster::ScheduleFromName  @ 000586e0  (line 245)

/* DWARF original prototype: Schedule_t * ScheduleFromName(CBaseMonster * this, char * pName) */

Schedule_t * __thiscall CBaseMonster::ScheduleFromName(CBaseMonster *this,char *pName)

{
  return (Schedule_t *)0x0;
}


// CBaseMonster::Killed  @ 000586f0  (line 248)

/* DWARF original prototype: void Killed(CBaseMonster * this, entvars_t * pevInflictor, entvars_t *
   pevAttacker, int iGib) */

void __thiscall
CBaseMonster::Killed(CBaseMonster *this,entvars_t *pevInflictor,entvars_t *pevAttacker,int iGib)

{
  return;
}


// CBasePlayer::CBasePlayer  @ 00058e70  (line 254)

/* DWARF original prototype: void CBasePlayer(CBasePlayer * this) */

void __thiscall CBasePlayer::CBasePlayer(CBasePlayer *this)

{
  (this->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBasePlayer_000c0e4c;
  return;
}


// CBasePlayer::~CBasePlayer  @ 00058700  (line 255)

/* DWARF original prototype: void ~CBasePlayer(CBasePlayer * this, int __in_chrg) */

void __thiscall CBasePlayer::~CBasePlayer(CBasePlayer *this,int __in_chrg)

{
  return;
}


// TrainSpeed  @ 00058e80  (line 257)

int TrainSpeed(int iSpeed,int iMax)

{
  return 0;
}


// CBasePlayer::PackDeadPlayerItems  @ 00058e90  (line 257)

/* CBasePlayer::PackDeadPlayerItems() */

void CBasePlayer::PackDeadPlayerItems(void)

{
  return;
}


// CBasePlayer::RemoveAllItems  @ 00058ea0  (line 257)

/* CBasePlayer::RemoveAllItems(int) */

void CBasePlayer::RemoveAllItems(int param_1)

{
  return;
}


// CBasePlayer::WaterMove  @ 00058eb0  (line 257)

/* CBasePlayer::WaterMove() */

void CBasePlayer::WaterMove(void)

{
  return;
}


// CBasePlayer::IsOnLadder  @ 00058ec0  (line 257)

/* CBasePlayer::IsOnLadder() */

undefined4 CBasePlayer::IsOnLadder(void)

{
  return 0;
}


// CBasePlayer::PlayerDeathThink  @ 00058ed0  (line 257)

/* CBasePlayer::PlayerDeathThink() */

void CBasePlayer::PlayerDeathThink(void)

{
  return;
}


// CBasePlayer::StartDeathCam  @ 00058ee0  (line 257)

/* CBasePlayer::StartDeathCam() */

void CBasePlayer::StartDeathCam(void)

{
  return;
}


// CBasePlayer::PlayerUse  @ 00058ef0  (line 257)

/* CBasePlayer::PlayerUse() */

void CBasePlayer::PlayerUse(void)

{
  return;
}


// CBasePlayer::TakeHealth  @ 00058710  (line 259)

/* DWARF original prototype: int TakeHealth(CBasePlayer * this, float flHealth, int bitsDamageType)
    */

int __thiscall CBasePlayer::TakeHealth(CBasePlayer *this,float flHealth,int bitsDamageType)

{
  return 0;
}


// CBasePlayer::TraceAttack  @ 00058720  (line 260)

/* DWARF original prototype: void TraceAttack(CBasePlayer * this, entvars_t * pevAttacker, float
   flDamage, Vector vecDir, 11TraceResult * ptr, int bitsDamageType) */

void __thiscall
CBasePlayer::TraceAttack
          (CBasePlayer *this,entvars_t *pevAttacker,float flDamage,Vector vecDir,_1TraceResult *ptr,
          int bitsDamageType)

{
  return;
}


// CBasePlayer::TakeDamage  @ 00058730  (line 261)

/* DWARF original prototype: int TakeDamage(CBasePlayer * this, entvars_t * pevInflictor, entvars_t
   * pevAttacker, float flDamage, int bitsDamageType) */

int __thiscall
CBasePlayer::TakeDamage
          (CBasePlayer *this,entvars_t *pevInflictor,entvars_t *pevAttacker,float flDamage,
          int bitsDamageType)

{
  return 0;
}


// CBasePlayer::SetAnimation  @ 00058740  (line 264)

/* DWARF original prototype: void SetAnimation(CBasePlayer * this, PLAYER_ANIM playerAnim) */

void __thiscall CBasePlayer::SetAnimation(CBasePlayer *this,PLAYER_ANIM playerAnim)

{
  return;
}


// CBasePlayer::StartObserver  @ 00058750  (line 269)

/* DWARF original prototype: void StartObserver(CBasePlayer * this, Vector vecPosition, Vector
   vecViewAngle) */

void __thiscall CBasePlayer::StartObserver(CBasePlayer *this,Vector vecPosition,Vector vecViewAngle)

{
  return;
}


// CBasePlayer::PlayStepSound  @ 00058f00  (line 274)

/* DWARF original prototype: void PlayStepSound(CBasePlayer * this, int step, float fvol) */

void __thiscall CBasePlayer::PlayStepSound(CBasePlayer *this,int step,float fvol)

{
  return;
}


// CBasePlayer::UpdateStepSound  @ 00058f10  (line 274)

/* CBasePlayer::UpdateStepSound() */

void CBasePlayer::UpdateStepSound(void)

{
  return;
}


// CBasePlayer::CheckTimeBasedDamage  @ 00058f20  (line 274)

/* CBasePlayer::CheckTimeBasedDamage() */

void CBasePlayer::CheckTimeBasedDamage(void)

{
  return;
}


// CBasePlayer::UpdateGeigerCounter  @ 00058f30  (line 274)

/* CBasePlayer::UpdateGeigerCounter() */

void CBasePlayer::UpdateGeigerCounter(void)

{
  return;
}


// CBasePlayer::CheckSuitUpdate  @ 00058f40  (line 274)

/* CBasePlayer::CheckSuitUpdate() */

void CBasePlayer::CheckSuitUpdate(void)

{
  return;
}


// CBasePlayer::SetSuitUpdate  @ 00058f50  (line 280)

/* DWARF original prototype: void SetSuitUpdate(CBasePlayer * this, char * name, int fgroup, int
   iNoRepeatTime) */

void __thiscall
CBasePlayer::SetSuitUpdate(CBasePlayer *this,char *name,int fgroup,int iNoRepeatTime)

{
  return;
}


// CBasePlayer::CheckPowerups  @ 00058f60  (line 280)

/* CBasePlayer::CheckPowerups() */

void CBasePlayer::CheckPowerups(void)

{
  return;
}


// CBasePlayer::UpdatePlayerSound  @ 00058f70  (line 280)

/* CBasePlayer::UpdatePlayerSound() */

void CBasePlayer::UpdatePlayerSound(void)

{
  return;
}


// CBasePlayer::RenewItems  @ 00058f80  (line 280)

/* CBasePlayer::RenewItems() */

void CBasePlayer::RenewItems(void)

{
  return;
}


// CBasePlayer::SelectNextItem  @ 00058f90  (line 280)

/* CBasePlayer::SelectNextItem(int) */

void CBasePlayer::SelectNextItem(int param_1)

{
  return;
}


// CBasePlayer::HasWeapons  @ 00058fa0  (line 280)

/* CBasePlayer::HasWeapons() */

undefined4 CBasePlayer::HasWeapons(void)

{
  return 0;
}


// CBasePlayer::SelectPrevItem  @ 00058fb0  (line 280)

/* CBasePlayer::SelectPrevItem(int) */

void CBasePlayer::SelectPrevItem(int param_1)

{
  return;
}


// CBasePlayer::GiveNamedItem  @ 00058fc0  (line 280)

/* CBasePlayer::GiveNamedItem(char*) */

void CBasePlayer::GiveNamedItem(char *param_1)

{
  return;
}


// CBasePlayer::FlashlightTurnOn  @ 00058fd0  (line 280)

/* CBasePlayer::FlashlightTurnOn() */

void CBasePlayer::FlashlightTurnOn(void)

{
  return;
}


// CBasePlayer::FlashlightTurnOff  @ 00058fe0  (line 280)

/* CBasePlayer::FlashlightTurnOff() */

void CBasePlayer::FlashlightTurnOff(void)

{
  return;
}


// CBasePlayer::ForceClientDllUpdate  @ 00058ff0  (line 280)

/* CBasePlayer::ForceClientDllUpdate() */

void CBasePlayer::ForceClientDllUpdate(void)

{
  return;
}


// CBasePlayer::CheatImpulseCommands  @ 00059000  (line 280)

/* CBasePlayer::CheatImpulseCommands(int) */

void CBasePlayer::CheatImpulseCommands(int param_1)

{
  return;
}


// CBasePlayer::GiveAmmo  @ 00058760  (line 301)

/* DWARF original prototype: int GiveAmmo(CBasePlayer * this, int iCount, char * szName, int iMax,
   int * pIndex) */

int __thiscall CBasePlayer::GiveAmmo(CBasePlayer *this,int iCount,char *szName,int iMax,int *pIndex)

{
  return -1;
}


// CBasePlayer::GiveTFAmmo  @ 00059010  (line 302)

/* DWARF original prototype: BOOL GiveTFAmmo(CBasePlayer * this, int shells, int nails, int rockets,
   int cells) */

BOOL __thiscall
CBasePlayer::GiveTFAmmo(CBasePlayer *this,int shells,int nails,int rockets,int cells)

{
  return 1;
}


// CBasePlayer::ItemPreFrame  @ 00059020  (line 302)

/* CBasePlayer::ItemPreFrame() */

void CBasePlayer::ItemPreFrame(void)

{
  return;
}


// CBasePlayer::ItemPostFrame  @ 00059030  (line 302)

/* CBasePlayer::ItemPostFrame() */

void CBasePlayer::ItemPostFrame(void)

{
  return;
}


// CBasePlayer::GetAmmoIndex  @ 00059040  (line 302)

/* CBasePlayer::GetAmmoIndex(char const*) */

undefined4 CBasePlayer::GetAmmoIndex(char *param_1)

{
  return 0xffffffff;
}


// CBasePlayer::SendAmmoUpdate  @ 00059050  (line 302)

/* CBasePlayer::SendAmmoUpdate() */

void CBasePlayer::SendAmmoUpdate(void)

{
  return;
}


// CBasePlayer::UpdateClientData  @ 00059060  (line 302)

/* CBasePlayer::UpdateClientData() */

void CBasePlayer::UpdateClientData(void)

{
  return;
}


// CBasePlayer::UpdateLowPriorityClientData  @ 00059070  (line 302)

/* CBasePlayer::UpdateLowPriorityClientData() */

void CBasePlayer::UpdateLowPriorityClientData(void)

{
  return;
}


// CBasePlayer::EnableControl  @ 00059080  (line 302)

/* CBasePlayer::EnableControl(int) */

void CBasePlayer::EnableControl(int param_1)

{
  return;
}


// CBasePlayer::AmmoInventory  @ 00058770  (line 305)

/* DWARF original prototype: int AmmoInventory(CBasePlayer * this, int iAmmoIndex) */

int __thiscall CBasePlayer::AmmoInventory(CBasePlayer *this,int iAmmoIndex)

{
  return -1;
}


// CBasePlayer::Illumination  @ 00058780  (line 313)

/* DWARF original prototype: int Illumination(CBasePlayer * this) */

int __thiscall CBasePlayer::Illumination(CBasePlayer *this)

{
  return 0;
}


// CBasePlayer::GetAutoaimVector  @ 00059090  (line 315)

/* DWARF original prototype: Vector GetAutoaimVector(CBasePlayer * this, float flDelta) */

Vector * __thiscall
CBasePlayer::GetAutoaimVector(Vector *__return_storage_ptr__,CBasePlayer *this,float flDelta)

{
  __return_storage_ptr__->x = g_vecZero.x;
  __return_storage_ptr__->y = g_vecZero.y;
  __return_storage_ptr__->z = g_vecZero.z;
  return __return_storage_ptr__;
}


// CBasePlayer::AutoaimDeflection  @ 000590c0  (line 316)

/* DWARF original prototype: Vector AutoaimDeflection(CBasePlayer * this, Vector * vecSrc, float
   flDist, float flDelta) */

Vector * __thiscall
CBasePlayer::AutoaimDeflection
          (Vector *__return_storage_ptr__,CBasePlayer *this,Vector *vecSrc,float flDist,
          float flDelta)

{
  __return_storage_ptr__->x = g_vecZero.x;
  __return_storage_ptr__->y = g_vecZero.y;
  __return_storage_ptr__->z = g_vecZero.z;
  return __return_storage_ptr__;
}


// CBasePlayer::ResetAutoaim  @ 000590f0  (line 316)

/* CBasePlayer::ResetAutoaim() */

void CBasePlayer::ResetAutoaim(void)

{
  return;
}


// CBasePlayer::SetCustomDecalFrames  @ 00059100  (line 316)

/* CBasePlayer::SetCustomDecalFrames(int) */

void CBasePlayer::SetCustomDecalFrames(int param_1)

{
  return;
}


// CBasePlayer::DropPlayerItem  @ 00059110  (line 316)

/* CBasePlayer::DropPlayerItem(char*) */

void CBasePlayer::DropPlayerItem(char *param_1)

{
  return;
}


// CBasePlayer::HasPlayerItem  @ 00059120  (line 316)

/* CBasePlayer::HasPlayerItem(CBasePlayerItem*) */

undefined4 CBasePlayer::HasPlayerItem(CBasePlayerItem *param_1)

{
  return 0;
}


// CBasePlayer::HasNamedPlayerItem  @ 00059130  (line 316)

/* CBasePlayer::HasNamedPlayerItem(char*) */

undefined4 CBasePlayer::HasNamedPlayerItem(char *param_1)

{
  return 0;
}


// CBasePlayer::SwitchWeapon  @ 00059140  (line 316)

/* CBasePlayer::SwitchWeapon(CBasePlayerItem*) */

undefined4 CBasePlayer::SwitchWeapon(CBasePlayerItem *param_1)

{
  return 0;
}


// CBasePlayer::TeamFortress_PrintClassName  @ 00059150  (line 316)

/* CBasePlayer::TeamFortress_PrintClassName(int) */

void CBasePlayer::TeamFortress_PrintClassName(int param_1)

{
  return;
}


// CBasePlayer::ChangeClass  @ 00059160  (line 316)

/* CBasePlayer::ChangeClass(int) */

void CBasePlayer::ChangeClass(int param_1)

{
  return;
}


// CBasePlayer::TeamFortress_SetEquipment  @ 00059170  (line 316)

/* CBasePlayer::TeamFortress_SetEquipment() */

void CBasePlayer::TeamFortress_SetEquipment(void)

{
  return;
}


// CBasePlayer::TeamFortress_SetHealth  @ 00059180  (line 316)

/* CBasePlayer::TeamFortress_SetHealth() */

void CBasePlayer::TeamFortress_SetHealth(void)

{
  return;
}


// CBasePlayer::TeamFortress_SetSkin  @ 00059190  (line 316)

/* CBasePlayer::TeamFortress_SetSkin() */

void CBasePlayer::TeamFortress_SetSkin(void)

{
  return;
}


// CBasePlayer::IsLegalClass  @ 000591a0  (line 316)

/* CBasePlayer::IsLegalClass(int) */

undefined4 CBasePlayer::IsLegalClass(int param_1)

{
  return 1;
}


// CBasePlayer::TeamFortress_DisplayLegalClasses  @ 000591b0  (line 316)

/* CBasePlayer::TeamFortress_DisplayLegalClasses() */

void CBasePlayer::TeamFortress_DisplayLegalClasses(void)

{
  return;
}


// CBasePlayer::TeamFortress_ExecClassScript  @ 000591c0  (line 316)

/* CBasePlayer::TeamFortress_ExecClassScript() */

void CBasePlayer::TeamFortress_ExecClassScript(void)

{
  return;
}


// CBasePlayer::TeamFortress_ExecMapScript  @ 000591d0  (line 316)

/* CBasePlayer::TeamFortress_ExecMapScript() */

void CBasePlayer::TeamFortress_ExecMapScript(void)

{
  return;
}


// CBasePlayer::CantChange  @ 00058790  (line 325)

/* DWARF original prototype: BOOL CantChange(CBasePlayer * this, int iClassNo, BOOL showMessage) */

BOOL __thiscall CBasePlayer::CantChange(CBasePlayer *this,int iClassNo,BOOL showMessage)

{
  return 0;
}


// CBasePlayer::TeamFortress_TeamSet  @ 000591e0  (line 336)

/* DWARF original prototype: BOOL TeamFortress_TeamSet(CBasePlayer * this, int tno) */

BOOL __thiscall CBasePlayer::TeamFortress_TeamSet(CBasePlayer *this,int tno)

{
  return 1;
}


// CBasePlayer::TeamFortress_TeamShowMemberClasses  @ 000591f0  (line 336)

/* CBasePlayer::TeamFortress_TeamShowMemberClasses() */

void CBasePlayer::TeamFortress_TeamShowMemberClasses(void)

{
  return;
}


// CBasePlayer::Engineer_RemoveBuildings  @ 00059200  (line 336)

/* CBasePlayer::Engineer_RemoveBuildings() */

void CBasePlayer::Engineer_RemoveBuildings(void)

{
  return;
}


// CBasePlayer::TF_AddFrags  @ 00059210  (line 336)

/* CBasePlayer::TF_AddFrags(int) */

void CBasePlayer::TF_AddFrags(int param_1)

{
  return;
}


// CBasePlayer::TeamFortress_RemoveTimers  @ 00059220  (line 336)

/* CBasePlayer::TeamFortress_RemoveTimers() */

void CBasePlayer::TeamFortress_RemoveTimers(void)

{
  return;
}


// CBasePlayer::TeamFortress_SetupRespawn  @ 00059230  (line 336)

/* CBasePlayer::TeamFortress_SetupRespawn(int) */

void CBasePlayer::TeamFortress_SetupRespawn(int param_1)

{
  return;
}


// CBasePlayer::TeamFortress_CheckClassStats  @ 00059240  (line 336)

/* CBasePlayer::TeamFortress_CheckClassStats() */

void CBasePlayer::TeamFortress_CheckClassStats(void)

{
  return;
}


// CBasePlayer::ForceRespawn  @ 00059250  (line 336)

/* CBasePlayer::ForceRespawn() */

void CBasePlayer::ForceRespawn(void)

{
  return;
}


// CBasePlayer::DropGoalItems  @ 00059260  (line 336)

/* CBasePlayer::DropGoalItems() */

void CBasePlayer::DropGoalItems(void)

{
  return;
}


// CBasePlayer::UseSpecialSkill  @ 00059270  (line 336)

/* CBasePlayer::UseSpecialSkill() */

void CBasePlayer::UseSpecialSkill(void)

{
  return;
}


// CBasePlayer::TeamFortress_ThrowPrimedGrenade  @ 00059280  (line 336)

/* CBasePlayer::TeamFortress_ThrowPrimedGrenade() */

void CBasePlayer::TeamFortress_ThrowPrimedGrenade(void)

{
  return;
}


// CBasePlayer::TeamFortress_PrimeGrenade  @ 00059290  (line 336)

/* CBasePlayer::TeamFortress_PrimeGrenade(int) */

void CBasePlayer::TeamFortress_PrimeGrenade(int param_1)

{
  return;
}


// CBasePlayer::CheckUncoveringSpies  @ 000592a0  (line 336)

/* CBasePlayer::CheckUncoveringSpies(CBasePlayer*) */

void CBasePlayer::CheckUncoveringSpies(CBasePlayer *param_1)

{
  return;
}


// CBasePlayer::ClientHearVox  @ 000592b0  (line 336)

/* CBasePlayer::ClientHearVox(char const*) */

void CBasePlayer::ClientHearVox(char *param_1)

{
  return;
}


// CBasePlayer::PlayerTouch  @ 000592c0  (line 336)

/* CBasePlayer::PlayerTouch(CBaseEntity*) */

void CBasePlayer::PlayerTouch(CBaseEntity *param_1)

{
  return;
}


// CBasePlayer::TeamFortress_CalcEMPDmgRad  @ 000587a0  (line 348)

/* DWARF original prototype: void TeamFortress_CalcEMPDmgRad(CBasePlayer * this, float * damage,
   float * radius) */

void __thiscall
CBasePlayer::TeamFortress_CalcEMPDmgRad(CBasePlayer *this,float *damage,float *radius)

{
  return;
}


// CBasePlayer::TeamFortress_TakeConcussionBlast  @ 000587b0  (line 350)

/* DWARF original prototype: void TeamFortress_TakeConcussionBlast(CBasePlayer * this, entvars_t *
   pevGren, float bouncemax) */

void __thiscall
CBasePlayer::TeamFortress_TakeConcussionBlast(CBasePlayer *this,entvars_t *pevGren,float bouncemax)

{
  return;
}


// ClearMultiDamage  @ 000592d0  (line 358)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClearMultiDamage(void)

{
  return;
}


// AddMultiDamage  @ 000592e0  (line 360)

void AddMultiDamage(entvars_t *pevInflictor,CBaseEntity *pEntity,float flDamage,int bitsDamageType)

{
  return;
}


// SpawnBlood  @ 000592f0  (line 361)

void SpawnBlood(Vector vecSpot,int bloodColor,float flDamage)

{
  return;
}


// DamageDecal  @ 00059300  (line 361)

/* DamageDecal(CBaseEntity*, int) */

undefined4 DamageDecal(CBaseEntity *param_1,int param_2)

{
  return 0;
}


// DecalGunshot  @ 00059310  (line 361)

/* DecalGunshot(TraceResult*, int) */

void DecalGunshot(TraceResult *param_1,int param_2)

{
  return;
}


// EjectBrass  @ 00059320  (line 364)

void EjectBrass(Vector *vecOrigin,Vector *vecVelocity,float rotation,int model,int soundtype)

{
  return;
}


// AddAmmoNameToAmmoRegistry  @ 00059330  (line 364)

/* AddAmmoNameToAmmoRegistry(char const*) */

void AddAmmoNameToAmmoRegistry(char *param_1)

{
  return;
}


// CBasePlayerItem::FallInit  @ 00059340  (line 364)

/* CBasePlayerItem::FallInit() */

void CBasePlayerItem::FallInit(void)

{
  return;
}


// CBasePlayerItem::FallThink  @ 00059350  (line 364)

/* CBasePlayerItem::FallThink() */

void CBasePlayerItem::FallThink(void)

{
  return;
}


// CBasePlayerItem::Materialize  @ 00059360  (line 364)

/* CBasePlayerItem::Materialize() */

void CBasePlayerItem::Materialize(void)

{
  return;
}


// CBasePlayerItem::AttemptToMaterialize  @ 00059370  (line 364)

/* CBasePlayerItem::AttemptToMaterialize() */

void CBasePlayerItem::AttemptToMaterialize(void)

{
  return;
}


// CBasePlayerItem::DefaultTouch  @ 00059380  (line 364)

/* CBasePlayerItem::DefaultTouch(CBaseEntity*) */

void CBasePlayerItem::DefaultTouch(CBaseEntity *param_1)

{
  return;
}


// CBasePlayerItem::DestroyItem  @ 00059390  (line 364)

/* CBasePlayerItem::DestroyItem() */

void CBasePlayerItem::DestroyItem(void)

{
  return;
}


// CBasePlayerItem::Respawn  @ 000587c0  (line 376)

/* DWARF original prototype: CBaseEntity * Respawn(CBasePlayerItem * this) */

CBaseEntity * __thiscall CBasePlayerItem::Respawn(CBasePlayerItem *this)

{
  return (CBaseEntity *)0x0;
}


// CBasePlayerItem::AttachToPlayer  @ 000587d0  (line 383)

/* DWARF original prototype: void AttachToPlayer(CBasePlayerItem * this, CBasePlayer * pPlayer) */

void __thiscall CBasePlayerItem::AttachToPlayer(CBasePlayerItem *this,CBasePlayer *pPlayer)

{
  return;
}


// CBasePlayerWeapon::AddPrimaryAmmo  @ 000593a0  (line 387)

/* DWARF original prototype: BOOL AddPrimaryAmmo(CBasePlayerWeapon * this, int iCount, char *
   szName, int iMaxClip, int iMaxCarry) */

BOOL __thiscall
CBasePlayerWeapon::AddPrimaryAmmo
          (CBasePlayerWeapon *this,int iCount,char *szName,int iMaxClip,int iMaxCarry)

{
  return 1;
}


// CBasePlayerWeapon::AddSecondaryAmmo  @ 000593b0  (line 388)

/* DWARF original prototype: BOOL AddSecondaryAmmo(CBasePlayerWeapon * this, int iCount, char *
   szName, int iMax) */

BOOL __thiscall
CBasePlayerWeapon::AddSecondaryAmmo(CBasePlayerWeapon *this,int iCount,char *szName,int iMax)

{
  return 1;
}


// CBasePlayerWeapon::DefaultReload  @ 000593c0  (line 390)

/* DWARF original prototype: BOOL DefaultReload(CBasePlayerWeapon * this, int iClipSize, int iAnim,
   float fDelay) */

BOOL __thiscall
CBasePlayerWeapon::DefaultReload(CBasePlayerWeapon *this,int iClipSize,int iAnim,float fDelay)

{
  return 1;
}


// CBasePlayerAmmo::Materialize  @ 000593d0  (line 390)

/* CBasePlayerAmmo::Materialize() */

void CBasePlayerAmmo::Materialize(void)

{
  return;
}


// CBasePlayerWeapon::SecondaryAmmoIndex  @ 000587e0  (line 392)

/* DWARF original prototype: int SecondaryAmmoIndex(CBasePlayerWeapon * this) */

int __thiscall CBasePlayerWeapon::SecondaryAmmoIndex(CBasePlayerWeapon *this)

{
  return -1;
}


// CBasePlayerAmmo::Respawn  @ 000587f0  (line 394)

/* DWARF original prototype: CBaseEntity * Respawn(CBasePlayerAmmo * this) */

CBaseEntity * __thiscall CBasePlayerAmmo::Respawn(CBasePlayerAmmo *this)

{
  return &this->super_CBaseEntity;
}


// CBasePlayerAmmo::DefaultTouch  @ 000593e0  (line 396)

/* DWARF original prototype: void DefaultTouch(CBasePlayerAmmo * this, CBaseEntity * pOther) */

void __thiscall CBasePlayerAmmo::DefaultTouch(CBasePlayerAmmo *this,CBaseEntity *pOther)

{
  return;
}


// CCrowbar::Smack  @ 000593f0  (line 396)

/* CCrowbar::Smack() */

void CCrowbar::Smack(void)

{
  return;
}


// CBasePlayerWeapon::ExtractClipAmmo  @ 00058800  (line 398)

/* DWARF original prototype: int ExtractClipAmmo(CBasePlayerWeapon * this, CBasePlayerWeapon *
   pWeapon) */

int __thiscall
CBasePlayerWeapon::ExtractClipAmmo(CBasePlayerWeapon *this,CBasePlayerWeapon *pWeapon)

{
  return 0;
}


// CBasePlayerWeapon::GetNextAttackDelay  @ 00058810  (line 401)

/* DWARF original prototype: float GetNextAttackDelay(CBasePlayerWeapon * this, float delay) */

float __thiscall CBasePlayerWeapon::GetNextAttackDelay(CBasePlayerWeapon *this,float delay)

{
  return delay;
}


// CCrowbar::GetItemInfo  @ 00058820  (line 405)

/* DWARF original prototype: int GetItemInfo(CCrowbar * this, ItemInfo * p) */

int __thiscall CCrowbar::GetItemInfo(CCrowbar *this,ItemInfo *p)

{
  return 1;
}


// CCrowbar::Deploy  @ 00058830  (line 406)

/* DWARF original prototype: BOOL Deploy(CCrowbar * this) */

BOOL __thiscall CCrowbar::Deploy(CCrowbar *this)

{
  return 1;
}


// CCrowbar::Holster  @ 00058840  (line 407)

/* DWARF original prototype: void Holster(CCrowbar * this, int skiplocal) */

void __thiscall CCrowbar::Holster(CCrowbar *this,int skiplocal)

{
  return;
}


// CCrowbar::PrimaryAttack  @ 00058850  (line 408)

/* DWARF original prototype: void PrimaryAttack(CCrowbar * this) */

void __thiscall CCrowbar::PrimaryAttack(CCrowbar *this)

{
  return;
}


// CBaseEntity::Intersects  @ 00058860  (line 408)

/* CBaseEntity::Intersects(CBaseEntity*) */

undefined4 CBaseEntity::Intersects(CBaseEntity *param_1)

{
  return 0;
}


// CBaseEntity::MakeDormant  @ 00058870  (line 408)

/* CBaseEntity::MakeDormant() */

void CBaseEntity::MakeDormant(void)

{
  return;
}


// CBaseEntity::IsDormant  @ 00058880  (line 408)

/* CBaseEntity::IsDormant() */

undefined4 CBaseEntity::IsDormant(void)

{
  return 0;
}


// CCrowbar::SwingAgain  @ 00059400  (line 410)

/* DWARF original prototype: void SwingAgain(CCrowbar * this) */

void __thiscall CCrowbar::SwingAgain(CCrowbar *this)

{
  return;
}


// CCrowbar::Swing  @ 00059410  (line 411)

/* DWARF original prototype: int Swing(CCrowbar * this, int fFirst) */

int __thiscall CCrowbar::Swing(CCrowbar *this,int fFirst)

{
  return 0;
}


