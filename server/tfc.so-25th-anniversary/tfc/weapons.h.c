// Ghidra decompilation of functions from tfc/weapons.h
// 83 functions, ordered by original source line

// CGrenade::~CGrenade  @ 0009ff50  (line 20)

/* DWARF original prototype: void ~CGrenade(CGrenade * this, int __in_chrg) */

void __thiscall CGrenade::~CGrenade(CGrenade *this,int __in_chrg)

{
  return;
}


// CGrenade::BloodColor  @ 00085200  (line 51)

/* DWARF original prototype: int BloodColor(CGrenade * this) */

int __thiscall CGrenade::BloodColor(CGrenade *this)

{
  return -1;
}


// CBasePlayerItem::~CBasePlayerItem  @ 0012bb40  (line 227)

/* DWARF original prototype: void ~CBasePlayerItem(CBasePlayerItem * this, int __in_chrg) */

void __thiscall CBasePlayerItem::~CBasePlayerItem(CBasePlayerItem *this,int __in_chrg)

{
  return;
}


// CBasePlayerItem::AddDuplicate  @ 0012ba50  (line 238)

/* DWARF original prototype: int AddDuplicate(CBasePlayerItem * this, CBasePlayerItem * pItem) */

int __thiscall CBasePlayerItem::AddDuplicate(CBasePlayerItem *this,CBasePlayerItem *pItem)

{
  return 0;
}


// CBasePlayerItem::iItemSlot  @ 0012ba60  (line 239)

/* DWARF original prototype: int iItemSlot(CBasePlayerItem * this) */

int __thiscall CBasePlayerItem::iItemSlot(CBasePlayerItem *this)

{
  return 0;
}


// CBasePlayerItem::GetItemInfo  @ 0012ba70  (line 248)

/* DWARF original prototype: int GetItemInfo(CBasePlayerItem * this, ItemInfo * p) */

int __thiscall CBasePlayerItem::GetItemInfo(CBasePlayerItem *this,ItemInfo *p)

{
  return 0;
}


// CBasePlayerItem::CanDeploy  @ 0012ba80  (line 249)

/* DWARF original prototype: BOOL CanDeploy(CBasePlayerItem * this) */

BOOL __thiscall CBasePlayerItem::CanDeploy(CBasePlayerItem *this)

{
  return 1;
}


// CBasePlayerItem::Deploy  @ 0012ba90  (line 251)

/* DWARF original prototype: BOOL Deploy(CBasePlayerItem * this) */

BOOL __thiscall CBasePlayerItem::Deploy(CBasePlayerItem *this)

{
  return 1;
}


// CBasePlayerItem::CanHolster  @ 00082040  (line 253)

/* DWARF original prototype: BOOL CanHolster(CBasePlayerItem * this) */

BOOL __thiscall CBasePlayerItem::CanHolster(CBasePlayerItem *this)

{
  return 1;
}


// CBasePlayerItem::UpdateItemInfo  @ 0012baa0  (line 255)

/* DWARF original prototype: void UpdateItemInfo(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::UpdateItemInfo(CBasePlayerItem *this)

{
  return;
}


// CBasePlayerItem::ItemPreFrame  @ 00082050  (line 257)

/* DWARF original prototype: void ItemPreFrame(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::ItemPreFrame(CBasePlayerItem *this)

{
  return;
}


// CBasePlayerItem::ItemPostFrame  @ 0012bab0  (line 258)

/* DWARF original prototype: void ItemPostFrame(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::ItemPostFrame(CBasePlayerItem *this)

{
  return;
}


// CBasePlayerItem::PrimaryAmmoIndex  @ 0012bac0  (line 264)

/* DWARF original prototype: int PrimaryAmmoIndex(CBasePlayerItem * this) */

int __thiscall CBasePlayerItem::PrimaryAmmoIndex(CBasePlayerItem *this)

{
  return -1;
}


// CBasePlayerItem::SecondaryAmmoIndex  @ 0012bad0  (line 265)

/* DWARF original prototype: int SecondaryAmmoIndex(CBasePlayerItem * this) */

int __thiscall CBasePlayerItem::SecondaryAmmoIndex(CBasePlayerItem *this)

{
  return -1;
}


// CBasePlayerItem::UpdateClientData  @ 0012bae0  (line 267)

/* DWARF original prototype: int UpdateClientData(CBasePlayerItem * this, CBasePlayer * pPlayer) */

int __thiscall CBasePlayerItem::UpdateClientData(CBasePlayerItem *this,CBasePlayer *pPlayer)

{
  return 0;
}


// CBasePlayerItem::GetWeaponPtr  @ 0012baf0  (line 269)

/* DWARF original prototype: CBasePlayerItem * GetWeaponPtr(CBasePlayerItem * this) */

CBasePlayerItem * __thiscall CBasePlayerItem::GetWeaponPtr(CBasePlayerItem *this)

{
  return (CBasePlayerItem *)0x0;
}


// CBasePlayerWeapon::~CBasePlayerWeapon  @ 0012bb50  (line 283)

/* DWARF original prototype: void ~CBasePlayerWeapon(CBasePlayerWeapon * this, int __in_chrg) */

void __thiscall CBasePlayerWeapon::~CBasePlayerWeapon(CBasePlayerWeapon *this,int __in_chrg)

{
  return;
}


// CBasePlayerWeapon::AddWeapon  @ 00082060  (line 298)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int AddWeapon(CBasePlayerWeapon * this) */

int __thiscall CBasePlayerWeapon::AddWeapon(CBasePlayerWeapon *this)

{
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x54])(this,this);
  return 1;
}


// CBasePlayerWeapon::UpdateItemInfo  @ 00082080  (line 304)

/* DWARF original prototype: void UpdateItemInfo(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::UpdateItemInfo(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::PrimaryAttack  @ 0012bb00  (line 325)

/* DWARF original prototype: void PrimaryAttack(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::PrimaryAttack(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::SecondaryAttack  @ 00082090  (line 326)

/* DWARF original prototype: void SecondaryAttack(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::SecondaryAttack(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::Reload  @ 000820a0  (line 327)

/* DWARF original prototype: void Reload(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::Reload(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::WeaponIdle  @ 000820b0  (line 328)

/* DWARF original prototype: void WeaponIdle(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::WeaponIdle(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::ShouldWeaponIdle  @ 000820c0  (line 331)

/* DWARF original prototype: BOOL ShouldWeaponIdle(CBasePlayerWeapon * this) */

BOOL __thiscall CBasePlayerWeapon::ShouldWeaponIdle(CBasePlayerWeapon *this)

{
  return 0;
}


// CBasePlayerWeapon::GetWeaponPtr  @ 000820d0  (line 338)

/* DWARF original prototype: CBasePlayerItem * GetWeaponPtr(CBasePlayerWeapon * this) */

CBasePlayerItem * __thiscall CBasePlayerWeapon::GetWeaponPtr(CBasePlayerWeapon *this)

{
  return &this->super_CBasePlayerItem;
}


// CBasePlayerAmmo::~CBasePlayerAmmo  @ 0012bb30  (line 369)

/* DWARF original prototype: void ~CBasePlayerAmmo(CBasePlayerAmmo * this, int __in_chrg) */

void __thiscall CBasePlayerAmmo::~CBasePlayerAmmo(CBasePlayerAmmo *this,int __in_chrg)

{
  return;
}


// CBasePlayerAmmo::AddAmmo  @ 0012bb10  (line 374)

/* DWARF original prototype: BOOL AddAmmo(CBasePlayerAmmo * this, CBaseEntity * pOther) */

BOOL __thiscall CBasePlayerAmmo::AddAmmo(CBasePlayerAmmo *this,CBaseEntity *pOther)

{
  return 1;
}


// CWeaponBox::~CWeaponBox  @ 0012bb20  (line 455)

/* DWARF original prototype: void ~CWeaponBox(CWeaponBox * this, int __in_chrg) */

void __thiscall CWeaponBox::~CWeaponBox(CWeaponBox *this,int __in_chrg)

{
  return;
}


// CCrowbar::~CCrowbar  @ 000820f0  (line 490)

/* DWARF original prototype: void ~CCrowbar(CCrowbar * this, int __in_chrg) */

void __thiscall CCrowbar::~CCrowbar(CCrowbar *this,int __in_chrg)

{
  return;
}


// CCrowbar::iItemSlot  @ 000820e0  (line 495)

/* DWARF original prototype: int iItemSlot(CCrowbar * this) */

int __thiscall CCrowbar::iItemSlot(CCrowbar *this)

{
  return 1;
}


// CTFGrenade::~CTFGrenade  @ 001047d0  (line 514)

/* DWARF original prototype: void ~CTFGrenade(CTFGrenade * this, int __in_chrg) */

void __thiscall CTFGrenade::~CTFGrenade(CTFGrenade *this,int __in_chrg)

{
  return;
}


// CTFNailgun::~CTFNailgun  @ 00138fa0  (line 535)

/* DWARF original prototype: void ~CTFNailgun(CTFNailgun * this, int __in_chrg) */

void __thiscall CTFNailgun::~CTFNailgun(CTFNailgun *this,int __in_chrg)

{
  return;
}


// CTFNailgun::iItemSlot  @ 00138f80  (line 541)

/* DWARF original prototype: int iItemSlot(CTFNailgun * this) */

int __thiscall CTFNailgun::iItemSlot(CTFNailgun *this)

{
  return 2;
}


// CTFSuperNailgun::~CTFSuperNailgun  @ 00138fb0  (line 555)

/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */
/* DWARF original prototype: void ~CTFSuperNailgun(CTFSuperNailgun * this, int __in_chrg) */

void __thiscall CTFSuperNailgun::~CTFSuperNailgun(CTFSuperNailgun *this,int __in_chrg)

{
  return;
}


// CTFSuperNailgun::iItemSlot  @ 00138f90  (line 558)

/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */
/* DWARF original prototype: int iItemSlot(CTFSuperNailgun * this) */

int __thiscall CTFSuperNailgun::iItemSlot(CTFSuperNailgun *this)

{
  return 4;
}


// CTFNailgunNail::~CTFNailgunNail  @ 00104820  (line 570)

/* DWARF original prototype: void ~CTFNailgunNail(CTFNailgunNail * this, int __in_chrg) */

void __thiscall CTFNailgunNail::~CTFNailgunNail(CTFNailgunNail *this,int __in_chrg)

{
  return;
}


// CTFRpgRocket::~CTFRpgRocket  @ 001047f0  (line 590)

/* DWARF original prototype: void ~CTFRpgRocket(CTFRpgRocket * this, int __in_chrg) */

void __thiscall CTFRpgRocket::~CTFRpgRocket(CTFRpgRocket *this,int __in_chrg)

{
  return;
}


// CLaserSpot::~CLaserSpot  @ 001047c0  (line 603)

/* DWARF original prototype: void ~CLaserSpot(CLaserSpot * this, int __in_chrg) */

void __thiscall CLaserSpot::~CLaserSpot(CLaserSpot *this,int __in_chrg)

{
  return;
}


// CLaserSpot::ObjectCaps  @ 00104780  (line 608)

/* DWARF original prototype: int ObjectCaps(CLaserSpot * this) */

int __thiscall CLaserSpot::ObjectCaps(CLaserSpot *this)

{
  return -0x80000000;
}


// CTFSentrygun::~CTFSentrygun  @ 000e8220  (line 624)

/* DWARF original prototype: void ~CTFSentrygun(CTFSentrygun * this, int __in_chrg) */

void __thiscall CTFSentrygun::~CTFSentrygun(CTFSentrygun *this,int __in_chrg)

{
  return;
}


// CTFSentrygun::Classify  @ 000e81f0  (line 630)

/* DWARF original prototype: int Classify(CTFSentrygun * this) */

int __thiscall CTFSentrygun::Classify(CTFSentrygun *this)

{
  return 1;
}


// CTFSentrygun::BloodColor  @ 000e8200  (line 633)

/* DWARF original prototype: int BloodColor(CTFSentrygun * this) */

int __thiscall CTFSentrygun::BloodColor(CTFSentrygun *this)

{
  return -1;
}


// CTFSentrygunBase::~CTFSentrygunBase  @ 000e8230  (line 671)

/* DWARF original prototype: void ~CTFSentrygunBase(CTFSentrygunBase * this, int __in_chrg) */

void __thiscall CTFSentrygunBase::~CTFSentrygunBase(CTFSentrygunBase *this,int __in_chrg)

{
  return;
}


// CTFSentrygunBase::Classify  @ 000e8210  (line 679)

/* DWARF original prototype: int Classify(CTFSentrygunBase * this) */

int __thiscall CTFSentrygunBase::Classify(CTFSentrygunBase *this)

{
  return 1;
}


// CTFDispenser::~CTFDispenser  @ 00087010  (line 684)

/* DWARF original prototype: void ~CTFDispenser(CTFDispenser * this, int __in_chrg) */

void __thiscall CTFDispenser::~CTFDispenser(CTFDispenser *this,int __in_chrg)

{
  return;
}


// CTFDispenser::Classify  @ 00086fe0  (line 694)

/* DWARF original prototype: int Classify(CTFDispenser * this) */

int __thiscall CTFDispenser::Classify(CTFDispenser *this)

{
  return 1;
}


// CTFDispenser::BloodColor  @ 00086ff0  (line 695)

/* DWARF original prototype: int BloodColor(CTFDispenser * this) */

int __thiscall CTFDispenser::BloodColor(CTFDispenser *this)

{
  return -1;
}


// CTFFlamethrower::~CTFFlamethrower  @ 00137280  (line 716)

/* DWARF original prototype: void ~CTFFlamethrower(CTFFlamethrower * this, int __in_chrg) */

void __thiscall CTFFlamethrower::~CTFFlamethrower(CTFFlamethrower *this,int __in_chrg)

{
  return;
}


// CTFFlamethrower::iItemSlot  @ 00137270  (line 722)

/* DWARF original prototype: int iItemSlot(CTFFlamethrower * this) */

int __thiscall CTFFlamethrower::iItemSlot(CTFFlamethrower *this)

{
  return 5;
}


// CTFFlamethrowerBurst::~CTFFlamethrowerBurst  @ 00104810  (line 738)

/* DWARF original prototype: void ~CTFFlamethrowerBurst(CTFFlamethrowerBurst * this, int __in_chrg)
    */

void __thiscall
CTFFlamethrowerBurst::~CTFFlamethrowerBurst(CTFFlamethrowerBurst *this,int __in_chrg)

{
  return;
}


// CTFIncendiaryC::~CTFIncendiaryC  @ 00138630  (line 749)

/* DWARF original prototype: void ~CTFIncendiaryC(CTFIncendiaryC * this, int __in_chrg) */

void __thiscall CTFIncendiaryC::~CTFIncendiaryC(CTFIncendiaryC *this,int __in_chrg)

{
  return;
}


// CTFIncendiaryC::iItemSlot  @ 00138620  (line 755)

/* DWARF original prototype: int iItemSlot(CTFIncendiaryC * this) */

int __thiscall CTFIncendiaryC::iItemSlot(CTFIncendiaryC *this)

{
  return 4;
}


// CTFIncendiaryCRocket::~CTFIncendiaryCRocket  @ 00104800  (line 771)

/* DWARF original prototype: void ~CTFIncendiaryCRocket(CTFIncendiaryCRocket * this, int __in_chrg)
    */

void __thiscall
CTFIncendiaryCRocket::~CTFIncendiaryCRocket(CTFIncendiaryCRocket *this,int __in_chrg)

{
  return;
}


// CTFShotgun::~CTFShotgun  @ 0013aee0  (line 783)

/* DWARF original prototype: void ~CTFShotgun(CTFShotgun * this, int __in_chrg) */

void __thiscall CTFShotgun::~CTFShotgun(CTFShotgun *this,int __in_chrg)

{
  return;
}


// CTFSuperShotgun::~CTFSuperShotgun  @ 0013aef0  (line 809)

/* WARNING: Struct "CTFSuperShotgun": ignoring overlapping field "m_usFireSuperShotgun" */
/* DWARF original prototype: void ~CTFSuperShotgun(CTFSuperShotgun * this, int __in_chrg) */

void __thiscall CTFSuperShotgun::~CTFSuperShotgun(CTFSuperShotgun *this,int __in_chrg)

{
  return;
}


// CTFTranq::~CTFTranq  @ 0013cae0  (line 822)

/* DWARF original prototype: void ~CTFTranq(CTFTranq * this, int __in_chrg) */

void __thiscall CTFTranq::~CTFTranq(CTFTranq *this,int __in_chrg)

{
  return;
}


// CTFTranq::iItemSlot  @ 0013cad0  (line 827)

/* DWARF original prototype: int iItemSlot(CTFTranq * this) */

int __thiscall CTFTranq::iItemSlot(CTFTranq *this)

{
  return 2;
}


// CTFRailgun::~CTFRailgun  @ 00139500  (line 839)

/* DWARF original prototype: void ~CTFRailgun(CTFRailgun * this, int __in_chrg) */

void __thiscall CTFRailgun::~CTFRailgun(CTFRailgun *this,int __in_chrg)

{
  return;
}


// CTFRailgun::iItemSlot  @ 001394f0  (line 844)

/* DWARF original prototype: int iItemSlot(CTFRailgun * this) */

int __thiscall CTFRailgun::iItemSlot(CTFRailgun *this)

{
  return 2;
}


// CTFRpg::~CTFRpg  @ 00139ee0  (line 856)

/* DWARF original prototype: void ~CTFRpg(CTFRpg * this, int __in_chrg) */

void __thiscall CTFRpg::~CTFRpg(CTFRpg *this,int __in_chrg)

{
  return;
}


// CTFRpg::iItemSlot  @ 00139ed0  (line 862)

/* DWARF original prototype: int iItemSlot(CTFRpg * this) */

int __thiscall CTFRpg::iItemSlot(CTFRpg *this)

{
  return 5;
}


// CTFAutoRifle::~CTFAutoRifle  @ 00134400  (line 878)

/* DWARF original prototype: void ~CTFAutoRifle(CTFAutoRifle * this, int __in_chrg) */

void __thiscall CTFAutoRifle::~CTFAutoRifle(CTFAutoRifle *this,int __in_chrg)

{
  return;
}


// CTFAutoRifle::iItemSlot  @ 001343f0  (line 883)

/* DWARF original prototype: int iItemSlot(CTFAutoRifle * this) */

int __thiscall CTFAutoRifle::iItemSlot(CTFAutoRifle *this)

{
  return 3;
}


// CTFAssaultC::~CTFAssaultC  @ 00133d00  (line 898)

/* DWARF original prototype: void ~CTFAssaultC(CTFAssaultC * this, int __in_chrg) */

void __thiscall CTFAssaultC::~CTFAssaultC(CTFAssaultC *this,int __in_chrg)

{
  return;
}


// CTFAssaultC::iItemSlot  @ 00133ce0  (line 903)

/* DWARF original prototype: int iItemSlot(CTFAssaultC * this) */

int __thiscall CTFAssaultC::iItemSlot(CTFAssaultC *this)

{
  return 3;
}


// CTFAssaultC::ShouldWeaponIdle  @ 00133cf0  (line 919)

/* DWARF original prototype: BOOL ShouldWeaponIdle(CTFAssaultC * this) */

BOOL __thiscall CTFAssaultC::ShouldWeaponIdle(CTFAssaultC *this)

{
  return 1;
}


// CTFGrenadeLauncher::~CTFGrenadeLauncher  @ 00137f40  (line 934)

/* DWARF original prototype: void ~CTFGrenadeLauncher(CTFGrenadeLauncher * this, int __in_chrg) */

void __thiscall CTFGrenadeLauncher::~CTFGrenadeLauncher(CTFGrenadeLauncher *this,int __in_chrg)

{
  return;
}


// CTFGrenadeLauncher::iItemSlot  @ 00137f20  (line 940)

/* DWARF original prototype: int iItemSlot(CTFGrenadeLauncher * this) */

int __thiscall CTFGrenadeLauncher::iItemSlot(CTFGrenadeLauncher *this)

{
  return 3;
}


// CTFPipebombLauncher::~CTFPipebombLauncher  @ 00137f50  (line 963)

/* DWARF original prototype: void ~CTFPipebombLauncher(CTFPipebombLauncher * this, int __in_chrg) */

void __thiscall CTFPipebombLauncher::~CTFPipebombLauncher(CTFPipebombLauncher *this,int __in_chrg)

{
  return;
}


// CTFPipebombLauncher::iItemSlot  @ 00137f30  (line 967)

/* DWARF original prototype: int iItemSlot(CTFPipebombLauncher * this) */

int __thiscall CTFPipebombLauncher::iItemSlot(CTFPipebombLauncher *this)

{
  return 3;
}


// CTFSniperRifle::~CTFSniperRifle  @ 0013c260  (line 972)

/* DWARF original prototype: void ~CTFSniperRifle(CTFSniperRifle * this, int __in_chrg) */

void __thiscall CTFSniperRifle::~CTFSniperRifle(CTFSniperRifle *this,int __in_chrg)

{
  return;
}


// CTFSniperRifle::iItemSlot  @ 0013c250  (line 977)

/* DWARF original prototype: int iItemSlot(CTFSniperRifle * this) */

int __thiscall CTFSniperRifle::iItemSlot(CTFSniperRifle *this)

{
  return 3;
}


// CTFAxe::~CTFAxe  @ 00136bb0  (line 999)

/* DWARF original prototype: void ~CTFAxe(CTFAxe * this, int __in_chrg) */

void __thiscall CTFAxe::~CTFAxe(CTFAxe *this,int __in_chrg)

{
  return;
}


// CTFAxe::iItemSlot  @ 00136b90  (line 1004)

/* DWARF original prototype: int iItemSlot(CTFAxe * this) */

int __thiscall CTFAxe::iItemSlot(CTFAxe *this)

{
  return 1;
}


// CTFAxe::IsUseable  @ 00136ba0  (line 1016)

/* DWARF original prototype: BOOL IsUseable(CTFAxe * this) */

BOOL __thiscall CTFAxe::IsUseable(CTFAxe *this)

{
  return 1;
}


// CTFKnife::~CTFKnife  @ 00136bd0  (line 1028)

/* DWARF original prototype: void ~CTFKnife(CTFKnife * this, int __in_chrg) */

void __thiscall CTFKnife::~CTFKnife(CTFKnife *this,int __in_chrg)

{
  return;
}


// CTFSpanner::~CTFSpanner  @ 00136be0  (line 1043)

/* DWARF original prototype: void ~CTFSpanner(CTFSpanner * this, int __in_chrg) */

void __thiscall CTFSpanner::~CTFSpanner(CTFSpanner *this,int __in_chrg)

{
  return;
}


// CTFMedikit::~CTFMedikit  @ 00136bc0  (line 1058)

/* DWARF original prototype: void ~CTFMedikit(CTFMedikit * this, int __in_chrg) */

void __thiscall CTFMedikit::~CTFMedikit(CTFMedikit *this,int __in_chrg)

{
  return;
}


// CDetpack::~CDetpack  @ 00085220  (line 1107)

/* DWARF original prototype: void ~CDetpack(CDetpack * this, int __in_chrg) */

void __thiscall CDetpack::~CDetpack(CDetpack *this,int __in_chrg)

{
  return;
}


// CDetpack::Classify  @ 00085210  (line 1112)

/* DWARF original prototype: int Classify(CDetpack * this) */

int __thiscall CDetpack::Classify(CDetpack *this)

{
  return 1;
}


// CTFTeleporter::~CTFTeleporter  @ 00132f00  (line 1129)

/* DWARF original prototype: void ~CTFTeleporter(CTFTeleporter * this, int __in_chrg) */

void __thiscall CTFTeleporter::~CTFTeleporter(CTFTeleporter *this,int __in_chrg)

{
  return;
}


// CTFTeleporter::Classify  @ 00132ee0  (line 1139)

/* DWARF original prototype: int Classify(CTFTeleporter * this) */

int __thiscall CTFTeleporter::Classify(CTFTeleporter *this)

{
  return 1;
}


// CTFTeleporter::BloodColor  @ 00132ef0  (line 1140)

/* DWARF original prototype: int BloodColor(CTFTeleporter * this) */

int __thiscall CTFTeleporter::BloodColor(CTFTeleporter *this)

{
  return -1;
}


