/***
*
*	Team Fortress Classic: client stubs for the server's classes
*
*	The weapons code is shared with the server. On the client, everything it
*	calls that only makes sense on the server is a stub here, so the weapons
*	can be predicted locally.
*
*	Reconstructed from client.so (25th Anniversary), DWARF-guided: the same
*	functions, in the same order, with the same return values.
*
****/
#include	"extdll.h"
#include	"util.h"
#include	"cbase.h"
#include	"player.h"
#include	"weapons.h"
#include	"nodes.h"
#include	"soundent.h"
#include	"skill.h"
#include	"tf_defs.h"

// Globals used by game logic
const Vector g_vecZero = Vector( 0, 0, 0 );
int gmsgWeapPickup = 0;
enginefuncs_t g_engfuncs;
globalvars_t  *gpGlobals;

ItemInfo CBasePlayerItem::ItemInfoArray[MAX_WEAPONS];

int CBaseEntity :: TakeHealth( float flHealth, int bitsDamageType ) { return 1; }
int CBaseEntity :: TakeDamage( entvars_t* pevInflictor, entvars_t* pevAttacker, float flDamage, int bitsDamageType ) { return 1; }
int CBaseEntity::ShouldToggle( USE_TYPE useType, BOOL currentState ) { return 0; }
CBaseEntity * CBaseEntity::Create( char *szName, const Vector &vecOrigin, const Vector &vecAngles, edict_t *pentOwner ) { return 0; }
void CBaseEntity::SUB_Remove( void ) { }
void CBaseEntity::Timer_Tranquilisation( void ) { }
CBaseEntity *CBaseEntity::CreateTimer( int iTimerType ) { return 0; }
BOOL CBaseEntity::IsAlly( CBaseEntity *pTest ) { return 1; }
void CBaseEntity::TeamFortress_EMPExplode( entvars_t *pevGren, float damage, float radius ) { }
const char *CBaseEntity::DB_GetItemName( void ) { return ""; }
edict_t *DBG_EntOfVars( const entvars_t *pev ) { return 0; }
void DBG_AssertFunction(BOOL fExpr,	const char*	szExpr,	const char*	szFile,	int szLine,	const char*	szMessage) { }
void UTIL_PrecacheOther( const char *szClassname ) { }
void UTIL_BloodDrips( const Vector &origin, const Vector &direction, int color, int amount ) { }
void UTIL_DecalTrace( TraceResult *pTrace, int decalNumber ) { }
void UTIL_GunshotDecalTrace( TraceResult *pTrace, int decalNumber ) { }
void UTIL_MakeVectors( const Vector &vecAngles ) { }
BOOL UTIL_IsValidEntity( edict_t *pent ) { return 1; }
void UTIL_SetOrigin( entvars_t *, const Vector &org ) { }
void UTIL_LogPrintf(char *,...) { }
void UTIL_ClientPrintAll( int,char const *,char const *,char const *,char const *,char const *) { }
void ClientPrint( entvars_t *client, int msg_dest, const char *msg_name, const char *param1, const char *param2, const char *param3, const char *param4 ) { }
void *CBaseEntity::operator new( size_t stAllocateBlock, entvars_t *pev ) { return NULL; }
CTFNailgunNail *CTFNailgunNail::CreateTranqNail( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CBaseEntity *pLauncher ) { return 0; }
void CGrenade::Explode( Vector, Vector ) { }
CGrenade::CGrenade() { }
CTFNailgunNail *CTFNailgunNail::CreateNail( BOOL bFake, Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CBaseEntity *pLauncher, BOOL bSuper ) { return NULL; }
CTFNailgunNail *CTFNailgunNail::CreateSuperNail( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CBaseEntity *pLauncher ) { return 0; }
CTFNailgunNail *CTFNailgunNail::CreateRailgunNail( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CBaseEntity *pLauncher ) { return 0; }
CTFIncendiaryCRocket *CTFIncendiaryCRocket::CreateRpgRocket( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CTFIncendiaryC *pLauncher ) { return 0; }
CTFFlamethrowerBurst *CTFFlamethrowerBurst::CreateBurst( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CTFFlamethrower *pLauncher ) { return 0; }
CTFRpgRocket *CTFRpgRocket::CreateRpgRocket( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CTFRpg *pLauncher ) { return 0; }
void CTFRpgRocket::RocketTouch( CBaseEntity *pOther ) { }
CTFGrenade *CTFGrenade::CreateTFGrenade( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CTFGrenadeLauncher *pLauncher ) { return 0; }
CTFGrenade *CTFGrenade::CreateTFPipebomb( Vector vecOrigin, Vector vecAngles, CBaseEntity *pOwner, CTFGrenadeLauncher *pLauncher ) { return NULL; }
void CLaserSpot::Suspend( float flSuspendTime ) { }
void CLaserSpot::Revive( void ) { }
CBaseEntity* CBaseMonster :: CheckTraceHullAttack( float flDist, int iDamage, int iDmgType ) { return NULL; }
void CBaseMonster :: Eat ( float flFullDuration ) { }
BOOL CBaseMonster :: FShouldEat ( void ) { return 1; }
void CBaseMonster :: Listen ( void ) { }
float CBaseMonster :: FLSoundVolume ( CSound *pSound ) { return 0; }
BOOL CBaseMonster :: FValidateHintType ( short sHint ) { return 0; }
float CBaseAnimating :: StudioFrameAdvance ( float flInterval ) { return 0.0; }
void CBaseMonster :: MonsterUse ( CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value ) { }
void CBaseMonster :: RouteClear ( void ) { }
void CBaseMonster :: RouteNew ( void ) { }
BOOL CBaseMonster :: FRouteClear ( void ) { return 0; }
BOOL CBaseMonster :: FRefreshRoute ( void ) { return 0; }
BOOL CBaseMonster::MoveToEnemy( Activity movementAct, float waitTime ) { return 0; }
BOOL CBaseMonster::MoveToLocation( Activity movementAct, float waitTime, const Vector &goal ) { return 0; }
BOOL CBaseMonster::MoveToTarget( Activity movementAct, float waitTime ) { return 0; }
BOOL CBaseMonster::MoveToNode( Activity movementAct, float waitTime, const Vector &goal ) { return 0; }
int ShouldSimplify( int routeType ) { return 1; }
void CBaseMonster :: RouteSimplify( CBaseEntity *pTargetEnt ) { }
void CBaseMonster :: PushEnemy( CBaseEntity *pEnemy, Vector &vecLastKnownPos ) { }
BOOL CBaseMonster :: PopEnemy( ) { return 0; }
void CBaseMonster :: SetSequenceByName ( char *szSequence ) { }
BOOL CBaseMonster :: CheckMeleeAttack2 ( float flDot, float flDist ) { return 0; }
int CBaseMonster :: CheckLocalMove ( const Vector &vecStart, const Vector &vecEnd, CBaseEntity *pTarget, float *pflDist ) { return 0; }
float CBaseMonster :: OpenDoorAndWait( entvars_t *pevDoor ) { return 0.0; }
void CBaseMonster :: AdvanceRoute ( float distance ) { }
int CBaseMonster :: RouteClassify( int iMoveFlag ) { return 0; }
BOOL CBaseMonster :: BuildRoute ( const Vector &vecGoal, int iMoveFlag, CBaseEntity *pTarget ) { return 0; }
void CBaseMonster :: InsertWaypoint ( Vector vecLocation, int afMoveFlags ) { }
void CBaseMonster :: MonsterInitThink ( void ) { }
void CBaseMonster :: MovementComplete( void ) { }
int CBaseMonster::TaskIsRunning( void ) { return 0; }
BOOL CBaseMonster :: FTriangulate ( const Vector &vecStart , const Vector &vecEnd, float flDist, CBaseEntity *pTargetEnt, Vector *pApex ) { return 0; }
BOOL CBaseMonster:: ShouldAdvanceRoute( float flWaypointDist ) { return 0; }
BOOL CBaseMonster :: BuildNearestRoute ( Vector vecThreat, Vector vecViewOffset, float flMinDist, float flMaxDist ) { return 0; }
void CBaseMonster :: MakeIdealYaw( Vector vecTarget ) { }
float	CBaseMonster::FlYawDiff ( void ) { return 0.0; }
float CBaseMonster::ChangeYaw ( int yawSpeed ) { return 0.0; }
float	CBaseMonster::VecToYaw ( Vector vecDir ) { return 0.0; }
int CBaseAnimating :: LookupActivity ( int activity ) { return 0; }
int CBaseAnimating :: LookupActivityHeaviest ( int activity ) { return 0; }
void CBaseMonster :: SetEyePosition ( void ) { }
int CBaseAnimating :: LookupSequence ( const char *label ) { return 0; }
void CBaseAnimating :: ResetSequenceInfo ( ) { }
BOOL CBaseAnimating :: GetSequenceFlags( ) { return 0; }
float CBaseAnimating :: SetBoneController ( int iController, float flValue ) { return 0; }
void CBaseAnimating :: InitBoneControllers ( void ) { }
void CBaseAnimating :: DispatchAnimEvents ( float flInterval ) { }
float CBaseAnimating :: SetBlending ( int iBlender, float flValue ) { return 0.0; }
void CBaseAnimating :: GetBonePosition ( int iBone, Vector &origin, Vector &angles ) { }
void CBaseAnimating :: GetAttachment ( int iAttachment, Vector &origin, Vector &angles ) { }
int CBaseAnimating :: FindTransition( int iEndingSequence, int iGoalSequence, int *piDir ) { return -1; }
void CBaseAnimating :: GetAutomovement( Vector &origin, Vector &angles, float flInterval ) { }
void CBaseAnimating :: SetBodygroup( int iGroup, int iValue ) { }
int CBaseAnimating :: GetBodygroup( int iGroup ) { return 0; }
Vector CBaseMonster :: GetGunPosition( void ) { return g_vecZero; }
void CBaseEntity::FireBullets(ULONG cShots, Vector vecSrc, Vector vecDirShooting, Vector vecSpread, float flDistance, int iBulletType, int iTracerFreq, int iDamage, entvars_t *pevAttacker ) { }
void CBaseEntity :: TraceBleed( float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType ) { }
void CBaseMonster :: MakeDamageBloodDecal ( int cCount, float flNoise, TraceResult *ptr, const Vector &vecDir ) { }
BOOL CBaseMonster :: FGetNodeRoute ( Vector vecDest ) { return 1; }
int CBaseMonster :: FindHintNode ( void ) { return -1; }
BOOL CBaseMonster :: FCheckAITrigger ( void ) { return 0; }
BOOL CBaseMonster :: FindLateralCover ( const Vector &vecThreat, const Vector &vecViewOffset ) { return 0; }
Vector CBaseMonster :: ShootAtEnemy( const Vector &shootOrigin ) { return g_vecZero; }
BOOL CBaseMonster :: FacingIdeal( void ) { return 0; }
void CBaseMonster::CorpseFallThink( void ) { }
BOOL CBaseMonster :: BBoxFlat ( void ) { return 1; }
BOOL CBaseMonster :: GetEnemy ( void ) { return 0; }
void CBaseMonster::PlaySentence( const char *pszSentence, float duration, float volume, float attenuation ) { }
void CBaseMonster::PlayScriptedSentence( const char *pszSentence, float duration, float volume, float attenuation, BOOL bConcurrent, CBaseEntity *pListener ) { }
CBaseEntity* CBaseMonster :: DropItem ( char *pszItemName, const Vector &vecPos, const Vector &vecAng ) { return NULL; }
void CBaseMonster :: RadiusDamage(entvars_t* pevInflictor, entvars_t*	pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType ) { }
void CBaseMonster :: RadiusDamage( Vector vecSrc, entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType ) { }
Activity CBaseMonster :: GetDeathActivity ( void ) { return ACT_DIE_HEADSHOT; }
MONSTERSTATE CBaseMonster :: GetIdealState ( void ) { return MONSTERSTATE_ALERT; }
Schedule_t* CBaseMonster :: GetScheduleOfType ( int Type ) { return NULL; }
Schedule_t *CBaseMonster::ScheduleFromName( const char *pName ) { return NULL;}
void CBaseMonster :: Killed( entvars_t *pevInflictor, entvars_t *pevAttacker, int iGib ) {}
int TrainSpeed(int iSpeed, int iMax) { 	return 0; }
void CBasePlayer::PackDeadPlayerItems( void ) { }
void CBasePlayer::RemoveAllItems( BOOL removeSuit ) { }
void CBasePlayer::WaterMove() { }
BOOL CBasePlayer::IsOnLadder( void ) { return 0; }
void CBasePlayer::PlayerDeathThink(void) { }
void CBasePlayer::StartDeathCam( void ) { }
void CBasePlayer::PlayerUse ( void ) { }
int CBasePlayer :: TakeHealth( float flHealth, int bitsDamageType ) { return 0; }
void CBasePlayer :: TraceAttack( entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType) { }
int CBasePlayer :: TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType ) { return 0; }
void CBasePlayer::SetAnimation( PLAYER_ANIM playerAnim ) { }
void CBasePlayer::StartObserver( Vector vecPosition, Vector vecViewAngle ) { }
void CBasePlayer::PlayStepSound( int step, float fvol ) { }
void CBasePlayer::UpdateStepSound( void ) { }
void CBasePlayer::CheckTimeBasedDamage() { }
void CBasePlayer :: UpdateGeigerCounter( void ) { }
void CBasePlayer::CheckSuitUpdate() { }
void CBasePlayer::SetSuitUpdate(char *name, int fgroup, int iNoRepeatTime) { }
void CBasePlayer::CheckPowerups( void ) { }
void CBasePlayer :: UpdatePlayerSound ( void ) { }
void CBasePlayer::RenewItems(void) { }
void CBasePlayer::SelectNextItem( int iItem ) { }
BOOL CBasePlayer::HasWeapons( void ) { return 0; }
void CBasePlayer::SelectPrevItem( int iItem ) { }
void CBasePlayer::GiveNamedItem( char *szName ) { }
void CBasePlayer :: FlashlightTurnOn( void ) { }
void CBasePlayer :: FlashlightTurnOff( void ) { }
void CBasePlayer :: ForceClientDllUpdate( void ) { }
void CBasePlayer::CheatImpulseCommands( int iImpulse ) { }
int CBasePlayer :: GiveAmmo( int iCount, char *szName, int iMax, int *pIndex ) { return -1; }
BOOL CBasePlayer::GiveTFAmmo( int shells, int nails, int rockets, int cells ) { return 1; }
void CBasePlayer::ItemPreFrame() { }
void CBasePlayer::ItemPostFrame() { }
int CBasePlayer::GetAmmoIndex(const char *psz) { return -1; }
void CBasePlayer::SendAmmoUpdate(void) { }
void CBasePlayer :: UpdateClientData( void ) { }
void CBasePlayer::UpdateLowPriorityClientData( void ) { }
void CBasePlayer :: EnableControl(BOOL fControl) { }
int CBasePlayer::AmmoInventory( int iAmmoIndex ) { return -1; }
int CBasePlayer :: Illumination( void ) { return 0; }
Vector CBasePlayer :: GetAutoaimVector( float flDelta ) { return g_vecZero; }
Vector CBasePlayer :: AutoaimDeflection( Vector &vecSrc, float flDist, float flDelta  ) { return g_vecZero; }
void CBasePlayer :: ResetAutoaim( ) { }
void CBasePlayer :: SetCustomDecalFrames( int nFrames ) { }
void CBasePlayer::DropPlayerItem ( char *pszItemName ) { }
BOOL CBasePlayer::HasPlayerItem( CBasePlayerItem *pCheckItem ) { return 0; }
BOOL CBasePlayer::HasNamedPlayerItem( char *pszItemName ) { return 0; }
BOOL CBasePlayer :: SwitchWeapon( CBasePlayerItem *pWeapon ) { return 0; }
void CBasePlayer::TeamFortress_PrintClassName( int iClass ) { }
void CBasePlayer::ChangeClass( int iClass ) { }
void CBasePlayer::TeamFortress_SetEquipment( void ) { }
void CBasePlayer::TeamFortress_SetHealth( void ) { }
void CBasePlayer::TeamFortress_SetSkin( void ) { }
BOOL CBasePlayer::IsLegalClass( int iClass ) { return 1; }
void CBasePlayer::TeamFortress_DisplayLegalClasses( void ) { }
void CBasePlayer::TeamFortress_ExecClassScript( void ) { }
void CBasePlayer::TeamFortress_ExecMapScript( void ) { }
BOOL CBasePlayer::CantChange( int iClassNo, BOOL showMessage ) { return 0; }
BOOL CBasePlayer::TeamFortress_TeamSet( int tno ) { return 1; }
void CBasePlayer::TeamFortress_TeamShowMemberClasses( void ) { }
void CBasePlayer::Engineer_RemoveBuildings( void ) { }
void CBasePlayer::TF_AddFrags( int iFrags ) { }
void CBasePlayer::TeamFortress_RemoveTimers( void ) { }
void CBasePlayer::TeamFortress_SetupRespawn( BOOL bSuicided ) { }
void CBasePlayer::TeamFortress_CheckClassStats( void ) { }
void CBasePlayer::ForceRespawn( void ) { }
void CBasePlayer::DropGoalItems( void ) { }
void CBasePlayer::UseSpecialSkill( void ) { }
void CBasePlayer::TeamFortress_ThrowPrimedGrenade( void ) { }
void CBasePlayer::TeamFortress_PrimeGrenade( int iType ) { }
void CBasePlayer::CheckUncoveringSpies( CBasePlayer *pPlayer ) { }
void CBasePlayer::ClientHearVox( const char *pSentence ) { }
void CBasePlayer::PlayerTouch( CBaseEntity *pOther ) { }
void CBasePlayer::TeamFortress_CalcEMPDmgRad( float &damage, float &radius ) { }
void CBasePlayer::TeamFortress_TakeConcussionBlast( entvars_t *pevGren, float bouncemax ) { }
void ClearMultiDamage(void) { }
void AddMultiDamage( entvars_t *pevInflictor, CBaseEntity *pEntity, float flDamage, int bitsDamageType) { }
void SpawnBlood(Vector vecSpot, int bloodColor, float flDamage) { }
int DamageDecal( CBaseEntity *pEntity, int bitsDamageType ) { return 0; }
void DecalGunshot( TraceResult *pTrace, int iBulletType ) { }
void EjectBrass ( const Vector &vecOrigin, const Vector &vecVelocity, float rotation, int model, int soundtype ) { }
void AddAmmoNameToAmmoRegistry( const char *szAmmoname ) { }
void CBasePlayerItem :: FallInit( void ) { }
void CBasePlayerItem::FallThink ( void ) { }
void CBasePlayerItem::Materialize( void ) { }
void CBasePlayerItem::AttemptToMaterialize( void ) { }
void CBasePlayerItem::DefaultTouch( CBaseEntity *pOther ) { }
void CBasePlayerItem::DestroyItem( void ) { }
CBaseEntity* CBasePlayerItem::Respawn( void ) { return NULL; }
void CBasePlayerItem::AttachToPlayer ( CBasePlayer *pPlayer ) { }
BOOL CBasePlayerWeapon :: AddPrimaryAmmo( int iCount, char *szName, int iMaxClip, int iMaxCarry ) { return 1; }
BOOL CBasePlayerWeapon :: AddSecondaryAmmo( int iCount, char *szName, int iMax ) { return 1; }
BOOL CBasePlayerWeapon::DefaultReload( int iClipSize, int iAnim, float fDelay ) { return 1; }
void CBasePlayerAmmo::Materialize( void ) { }
int CBasePlayerWeapon::SecondaryAmmoIndex( void ) {	return -1; }
CBaseEntity* CBasePlayerAmmo::Respawn( void ) { return this; }
void CBasePlayerAmmo :: DefaultTouch( CBaseEntity *pOther ) { }
void CCrowbar::Smack( void ) { }
int CBasePlayerWeapon::ExtractClipAmmo( CBasePlayerWeapon *pWeapon ) { return 0; }
float CBasePlayerWeapon::GetNextAttackDelay( float delay ) { return delay; }
int CCrowbar::GetItemInfo( ItemInfo *p ) { return 1; }
BOOL CCrowbar::Deploy( void ) { return 1; }
void CCrowbar::Holster( int skiplocal ) { }
void CCrowbar::PrimaryAttack( void ) { }
int	CBaseEntity :: Intersects( CBaseEntity *pOther ) { return 0; }
void CBaseEntity :: MakeDormant( void ) { }
int CBaseEntity :: IsDormant( void ) { return 0; }
void CCrowbar::SwingAgain( void ) { }
int CCrowbar::Swing( int fFirst ) { return 0; }

// Stubs the compiler folded into one copy (same empty body)
BOOL CBaseMonster :: CheckMeleeAttack1 ( float flDot, float flDist ) { return FALSE; }
BOOL CBaseMonster :: CheckRangeAttack1 ( float flDot, float flDist ) { return FALSE; }
BOOL CBaseMonster :: CheckRangeAttack2 ( float flDot, float flDist ) { return FALSE; }
BOOL CBaseMonster :: FindCover ( Vector vecThreat, Vector vecViewOffset, float flMinDist, float flMaxDist ) { return FALSE; }
void CBaseMonster :: Move ( float flInterval ) { }
void CBaseMonster::MoveExecute( CBaseEntity *pTargetEnt, const Vector &vecDir, float flInterval ) { }
void CBaseEntity::TraceAttack(entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType) { }
void CBaseMonster :: SetActivity ( Activity NewActivity ) { }
int	CBaseEntity :: DamageDecal( int bitsDamageType ) { return -1; }
int  CBasePlayer::Classify ( void ) { return 0; }
int CBaseMonster :: ISoundMask ( void ) { return 0; }
BOOL CBaseMonster :: HasAlienGibs( void ) { return FALSE; }
BOOL CBaseMonster :: HasHumanGibs( void ) { return FALSE; }
BOOL CBaseMonster :: FCanActiveIdle ( void ) { return FALSE; }
BOOL CBaseMonster :: FCanCheckAttacks ( void ) { return FALSE; }
int CBaseMonster :: IgnoreConditions ( void ) { return 0; }
int CBaseMonster :: CanPlaySequence( BOOL fDisregardMonsterState, int interruptLevel ) { return FALSE; }
CBaseEntity *CBaseEntity::GetNextTarget( void ) { return NULL; }
CSound* CBaseMonster :: PBestScent ( void ) { return NULL; }
CSound* CBaseMonster :: PBestSound ( void ) { return NULL; }
Schedule_t *CBaseMonster :: GetSchedule ( void ) { return NULL; }
CBaseEntity *CBaseMonster :: BestVisibleEnemy ( void ) { return NULL; }
void ApplyMultiDamage(entvars_t *pevInflictor, entvars_t *pevAttacker ) { }
void CBaseDelay :: KeyValue( struct KeyValueData_s * ) { }
void CBasePlayer :: BarnacleVictimBitten ( entvars_t *pevBarnacle ) { }
void CBaseMonster :: HandleAnimEvent( MonsterEvent_t *pEvent ) { }
void CBaseMonster :: RunTask ( Task_t *pTask ) { }
void CBaseMonster :: KeyValue( KeyValueData *pkvd ) { }
void CBaseMonster :: StartTask ( Task_t *pTask ) { }
int CBasePlayerWeapon::PrimaryAmmoIndex( void ) { return -1; }
BOOL CBaseEntity :: FVisible ( CBaseEntity *pEntity ) { return FALSE; }
BOOL CBaseEntity :: FVisible ( const Vector &vecOrigin ) { return FALSE; }
int CBasePlayer::AddPlayerItem( CBasePlayerItem *pItem ) { return FALSE; }
int CBasePlayer::RemovePlayerItem( CBasePlayerItem *pItem ) { return FALSE; }
int CBasePlayer::Save( CSave &save ) { return 0; }
int CBasePlayer::Restore( CRestore &restore ) { return 0; }
int CBaseMonster :: CheckEnemy ( CBaseEntity *pEnemy ) { return 0; }
BOOL CBaseMonster :: FInViewCone ( CBaseEntity *pEntity ) { return FALSE; }
BOOL CBaseMonster :: FInViewCone ( Vector *pOrigin ) { return FALSE; }
int CBaseMonster::IRelationship ( CBaseEntity *pTarget ) { return 0; }
int CBasePlayerWeapon::AddToPlayer( CBasePlayer *pPlayer ) { return FALSE; }
int CBasePlayerWeapon::ExtractAmmo( CBasePlayerWeapon *pWeapon ) { return 0; }
int CBasePlayerWeapon::AddDuplicate( CBasePlayerItem *pOriginal ) { return 0; }
int CBasePlayerWeapon::UpdateClientData( CBasePlayer *pPlayer ) { return 0; }
BOOL UTIL_GetNextBestWeapon( CBasePlayer *pPlayer, CBasePlayerItem *pCurrentWeapon ) { return TRUE; }
int CBasePlayerWeapon::Save( class CSave & ) { return 1; }
int CBasePlayerWeapon::Restore( class CRestore & ) { return 1; }
BOOL CBaseEntity :: IsInWorld( void ) { return TRUE; }
BOOL CBasePlayer :: FBecomeProne ( void ) { return TRUE; }
BOOL CBasePlayerWeapon :: IsUseable( void ) { return TRUE; }
void CBaseMonster :: Look ( int iDistance ) { }
void CBaseEntity::SetObjectCollisionBox( void ) { }
void CBasePlayer :: DeathSound( void ) { }
void CBasePlayer::ImpulseCommands( ) { }
void CBasePlayer :: BarnacleVictimReleased ( void ) { }
void CBasePlayer::Duck( ) { }
void CBasePlayer::Jump() { }
void CBasePlayer :: Precache( void ) { }
void CBasePlayer::PreThink(void) { }
void CBasePlayer::PostThink() { }
void CBaseMonster::BecomeDead( void ) {}
void CBaseMonster :: GibMonster( void ) { }
void CBaseMonster::FadeMonster( void ) { }
void CBaseMonster :: MonsterInit ( void ) { }
void CBaseMonster :: MonsterThink ( void ) { }
void CBaseMonster :: StartMonster ( void ) { }
void CBaseMonster::ReportAIState( void ) { }
void CBaseMonster :: MonsterInitDead( void ) { }
void CBaseMonster :: RunAI ( void ) {}
void CBasePlayerItem :: SetObjectCollisionBox( void ) { }
void CBasePlayerItem::Drop( void ) { }
void CBasePlayerItem::Kill( void ) { }
void CBasePlayerWeapon::RetireWeapon( void ) { }

// TFC additions to the stand-ins
float cb_prematch_time = 0;

// gib and blood options, registered in tf_events.cpp
cvar_t *cl_localblood;
cvar_t *cl_gibvelscale;
cvar_t *cl_giblife;
cvar_t *cl_gibcount;

CBaseEntity *CBaseEntity::FindTimer( int iTimerType ) { return NULL; }
void CBaseEntity::TeamFortress_CalcEMPDmgRad( float &damage, float &radius ) { }
void CBaseEntity::TeamFortress_TakeConcussionBlast( entvars_t *pevGren, float bouncemax ) { }
void CBaseEntity::TeamFortress_TakeEMPBlast( entvars_t *pevGren ) { }
void CBaseEntity::TeamFortress_EMPRemove( void ) { }
void CBasePlayer::TeamFortress_Concuss( entvars_t *pevGren ) { }
void CBasePlayer::TeamFortress_TakeEMPBlast( entvars_t *pevGren ) { }
BOOL CBasePlayer::EngineerUse( CBasePlayer *pPlayer ) { return FALSE; }
void CBasePlayer::PainSound( void ) { }
void CBaseMonster::SentenceStop( void ) { }
void CBasePlayerWeapon::DB_LogShots( int iShots ) { }
void CLaserSpot::Spawn( void ) { }
void CLaserSpot::Precache( void ) { }
CBasePlayer::CBasePlayer( void ) { }

void CBaseToggle :: KeyValue( struct KeyValueData_s * ) { }
void CBaseMonster :: BarnacleVictimBitten ( entvars_t *pevBarnacle ) { }
CBaseEntity *FindEntityForward( CBaseEntity *pMe ) { return NULL; }
int CBaseDelay::Save( class CSave & ) { return 1; }
int CBaseDelay::Restore( class CRestore & ) { return 1; }
int CBaseEntity::Save( CSave &save ) { return 1; }
int CBaseEntity::Restore( CRestore &restore ) { return 1; }
int CBaseToggle::Save( class CSave & ) { return 1; }
int CBaseToggle::Restore( class CRestore & ) { return 1; }
int CBaseMonster::Save( class CSave & ) { return 1; }
int CBaseMonster::Restore( class CRestore & ) { return 1; }
int CBaseAnimating::Save( class CSave & ) { return 1; }
int CBaseAnimating::Restore( class CRestore & ) { return 1; }
int CBasePlayerItem::AddToPlayer( CBasePlayer *pPlayer ) { return TRUE; }
int CBasePlayerItem::Save( class CSave & ) { return 1; }
int CBasePlayerItem::Restore( class CRestore & ) { return 1; }
void CBaseMonster :: BarnacleVictimReleased ( void ) { }
void CBasePlayerAmmo::Spawn( void ) { }
void CBasePlayerItem :: CheckRespawn ( void ) { }
void CGrenade::BounceSound( void ) { }
void CGrenade::Spawn( void ) { }
void CBaseMonster :: TraceAttack( entvars_t *pevAttacker, float flDamage, Vector vecDir, TraceResult *ptr, int bitsDamageType) { }
void CBaseMonster :: CheckAttacks ( CBaseEntity *pTarget, float flDist ) { }
BOOL CBaseMonster :: FBecomeProne ( void ) { return TRUE; }
int CBaseMonster :: TakeDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int bitsDamageType ) { return 0; }
int CBaseMonster :: TakeHealth (float flHealth, int bitsDamageType) { return 0; }
BOOL CBasePlayer :: FlashlightIsOn( void ) { return FALSE; }
BOOL CBaseMonster :: ShouldFadeOnDeath( void ) { return FALSE; }
int CBasePlayer :: GetCustomDecalFrames( void ) { return -1; }
void CBasePlayerItem::Holster( int skiplocal ) { }
void CGrenade::Killed( entvars_t *pevInflictor, entvars_t *pevAttacker, int iGib ) { }
void CGrenade::Explode( TraceResult *pTrace, int bitsDamageType ) { }

void CTFRpgRocket::Spawn( void ) { }
void CTFRpgRocket::Precache( void ) { }
void CTFIncendiaryCRocket::Spawn( void ) { }
void CTFIncendiaryCRocket::Precache( void ) { }
void CCrowbar::Spawn( void ) { }
void CCrowbar::Precache( void ) { }
void CGrenade::setModel( void ) { }
BOOL CGrenade::setBirthdayModel( void ) { return FALSE; }
void CBasePlayer::Ignite( entvars_t *pevInflictor, entvars_t *pevAttacker ) { }
BOOL CBasePlayer::SwitchWeapon( const char *szWeaponName ) { return FALSE; }
BOOL CBasePlayer::TeamFortress_TeamPutPlayerInTeam( void ) { return FALSE; }
void CTFRpgRocket::RadiusDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType ) { }
void CTFIncendiaryCRocket::RadiusDamage( entvars_t *pevInflictor, entvars_t *pevAttacker, float flDamage, int iClassIgnore, int bitsDamageType ) { }
void CBaseEntity::KeyValue( KeyValueData *pkvd ) { }
