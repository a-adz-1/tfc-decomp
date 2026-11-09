// Ghidra decompilation of functions from tfc/weapons.h
// 66 functions, ordered by original source line

// CGrenade::~CGrenade  @ 00059db0  (line 20)

/* DWARF original prototype: void ~CGrenade(CGrenade * this, int __in_chrg) */

void __thiscall CGrenade::~CGrenade(CGrenade *this,int __in_chrg)

{
  return;
}


// CGrenade::BloodColor  @ 00059ac0  (line 51)

/* DWARF original prototype: int BloodColor(CGrenade * this) */

int __thiscall CGrenade::BloodColor(CGrenade *this)

{
  return -1;
}


// CBasePlayerItem::~CBasePlayerItem  @ 00059d60  (line 227)

/* DWARF original prototype: void ~CBasePlayerItem(CBasePlayerItem * this, int __in_chrg) */

void __thiscall CBasePlayerItem::~CBasePlayerItem(CBasePlayerItem *this,int __in_chrg)

{
  return;
}


// CBasePlayerItem::AddDuplicate  @ 00059ad0  (line 238)

/* DWARF original prototype: int AddDuplicate(CBasePlayerItem * this, CBasePlayerItem * pItem) */

int __thiscall CBasePlayerItem::AddDuplicate(CBasePlayerItem *this,CBasePlayerItem *pItem)

{
  return 0;
}


// CBasePlayerItem::iItemSlot  @ 00059ae0  (line 239)

/* DWARF original prototype: int iItemSlot(CBasePlayerItem * this) */

int __thiscall CBasePlayerItem::iItemSlot(CBasePlayerItem *this)

{
  return 0;
}


// CBasePlayerItem::GetItemInfo  @ 00059af0  (line 248)

/* DWARF original prototype: int GetItemInfo(CBasePlayerItem * this, ItemInfo * p) */

int __thiscall CBasePlayerItem::GetItemInfo(CBasePlayerItem *this,ItemInfo *p)

{
  return 0;
}


// CBasePlayerItem::CanDeploy  @ 00059b00  (line 249)

/* DWARF original prototype: BOOL CanDeploy(CBasePlayerItem * this) */

BOOL __thiscall CBasePlayerItem::CanDeploy(CBasePlayerItem *this)

{
  return 1;
}


// CBasePlayerItem::Deploy  @ 00059b10  (line 251)

/* DWARF original prototype: BOOL Deploy(CBasePlayerItem * this) */

BOOL __thiscall CBasePlayerItem::Deploy(CBasePlayerItem *this)

{
  return 1;
}


// CBasePlayerItem::CanHolster  @ 00059b20  (line 253)

/* DWARF original prototype: BOOL CanHolster(CBasePlayerItem * this) */

BOOL __thiscall CBasePlayerItem::CanHolster(CBasePlayerItem *this)

{
  return 1;
}


// CBasePlayerItem::UpdateItemInfo  @ 00059b30  (line 255)

/* DWARF original prototype: void UpdateItemInfo(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::UpdateItemInfo(CBasePlayerItem *this)

{
  return;
}


// CBasePlayerItem::ItemPreFrame  @ 00059b40  (line 257)

/* DWARF original prototype: void ItemPreFrame(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::ItemPreFrame(CBasePlayerItem *this)

{
  return;
}


// CBasePlayerItem::ItemPostFrame  @ 00059b50  (line 258)

/* DWARF original prototype: void ItemPostFrame(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::ItemPostFrame(CBasePlayerItem *this)

{
  return;
}


// CBasePlayerItem::PrimaryAmmoIndex  @ 00059b60  (line 264)

/* DWARF original prototype: int PrimaryAmmoIndex(CBasePlayerItem * this) */

int __thiscall CBasePlayerItem::PrimaryAmmoIndex(CBasePlayerItem *this)

{
  return -1;
}


// CBasePlayerItem::SecondaryAmmoIndex  @ 00059b70  (line 265)

/* DWARF original prototype: int SecondaryAmmoIndex(CBasePlayerItem * this) */

int __thiscall CBasePlayerItem::SecondaryAmmoIndex(CBasePlayerItem *this)

{
  return -1;
}


// CBasePlayerItem::UpdateClientData  @ 00059b80  (line 267)

/* DWARF original prototype: int UpdateClientData(CBasePlayerItem * this, CBasePlayer * pPlayer) */

int __thiscall CBasePlayerItem::UpdateClientData(CBasePlayerItem *this,CBasePlayer *pPlayer)

{
  return 0;
}


// CBasePlayerItem::GetWeaponPtr  @ 00059b90  (line 269)

/* DWARF original prototype: CBasePlayerItem * GetWeaponPtr(CBasePlayerItem * this) */

CBasePlayerItem * __thiscall CBasePlayerItem::GetWeaponPtr(CBasePlayerItem *this)

{
  return (CBasePlayerItem *)0x0;
}


// CBasePlayerWeapon::~CBasePlayerWeapon  @ 00059d70  (line 283)

/* DWARF original prototype: void ~CBasePlayerWeapon(CBasePlayerWeapon * this, int __in_chrg) */

void __thiscall CBasePlayerWeapon::~CBasePlayerWeapon(CBasePlayerWeapon *this,int __in_chrg)

{
  return;
}


// CBasePlayerWeapon::AddWeapon  @ 00059e60  (line 298)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int AddWeapon(CBasePlayerWeapon * this) */

int __thiscall CBasePlayerWeapon::AddWeapon(CBasePlayerWeapon *this)

{
  _func_int_varargs *p_Var1;
  
  p_Var1 = (this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
           _vptr_CBaseEntity[0x54];
  if (p_Var1 == ExtractClipAmmo) {
    return 1;
  }
  (*p_Var1)(this,this);
  return 1;
}


// CBasePlayerWeapon::UpdateItemInfo  @ 00059ba0  (line 304)

/* DWARF original prototype: void UpdateItemInfo(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::UpdateItemInfo(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::PrimaryAttack  @ 00059bb0  (line 325)

/* DWARF original prototype: void PrimaryAttack(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::PrimaryAttack(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::SecondaryAttack  @ 00059bc0  (line 326)

/* DWARF original prototype: void SecondaryAttack(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::SecondaryAttack(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::Reload  @ 00059bd0  (line 327)

/* DWARF original prototype: void Reload(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::Reload(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::WeaponIdle  @ 00059be0  (line 328)

/* DWARF original prototype: void WeaponIdle(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::WeaponIdle(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::ShouldWeaponIdle  @ 00059bf0  (line 331)

/* DWARF original prototype: BOOL ShouldWeaponIdle(CBasePlayerWeapon * this) */

BOOL __thiscall CBasePlayerWeapon::ShouldWeaponIdle(CBasePlayerWeapon *this)

{
  return 0;
}


// CBasePlayerWeapon::GetWeaponPtr  @ 00059c00  (line 338)

/* DWARF original prototype: CBasePlayerItem * GetWeaponPtr(CBasePlayerWeapon * this) */

CBasePlayerItem * __thiscall CBasePlayerWeapon::GetWeaponPtr(CBasePlayerWeapon *this)

{
  return &this->super_CBasePlayerItem;
}


// CBasePlayerAmmo::~CBasePlayerAmmo  @ 00059d90  (line 369)

/* DWARF original prototype: void ~CBasePlayerAmmo(CBasePlayerAmmo * this, int __in_chrg) */

void __thiscall CBasePlayerAmmo::~CBasePlayerAmmo(CBasePlayerAmmo *this,int __in_chrg)

{
  return;
}


// CBasePlayerAmmo::AddAmmo  @ 00059c10  (line 374)

/* DWARF original prototype: BOOL AddAmmo(CBasePlayerAmmo * this, CBaseEntity * pOther) */

BOOL __thiscall CBasePlayerAmmo::AddAmmo(CBasePlayerAmmo *this,CBaseEntity *pOther)

{
  return 1;
}


// CCrowbar::~CCrowbar  @ 00059d80  (line 490)

/* DWARF original prototype: void ~CCrowbar(CCrowbar * this, int __in_chrg) */

void __thiscall CCrowbar::~CCrowbar(CCrowbar *this,int __in_chrg)

{
  return;
}


// CCrowbar::iItemSlot  @ 00059c20  (line 495)

/* DWARF original prototype: int iItemSlot(CCrowbar * this) */

int __thiscall CCrowbar::iItemSlot(CCrowbar *this)

{
  return 1;
}


// CTFNailgun::~CTFNailgun  @ 0005e1d0  (line 535)

/* DWARF original prototype: void ~CTFNailgun(CTFNailgun * this, int __in_chrg) */

void __thiscall CTFNailgun::~CTFNailgun(CTFNailgun *this,int __in_chrg)

{
  return;
}


// CTFNailgun::iItemSlot  @ 000bb3f0  (line 541)

/* DWARF original prototype: int iItemSlot(CTFNailgun * this) */

int __thiscall CTFNailgun::iItemSlot(CTFNailgun *this)

{
  return 2;
}


// CTFSuperNailgun::~CTFSuperNailgun  @ 0005e210  (line 555)

/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */
/* DWARF original prototype: void ~CTFSuperNailgun(CTFSuperNailgun * this, int __in_chrg) */

void __thiscall CTFSuperNailgun::~CTFSuperNailgun(CTFSuperNailgun *this,int __in_chrg)

{
  return;
}


// CTFSuperNailgun::iItemSlot  @ 000bb400  (line 558)

/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */
/* DWARF original prototype: int iItemSlot(CTFSuperNailgun * this) */

int __thiscall CTFSuperNailgun::iItemSlot(CTFSuperNailgun *this)

{
  return 4;
}


// CTFRpgRocket::~CTFRpgRocket  @ 00059dc0  (line 590)

/* DWARF original prototype: void ~CTFRpgRocket(CTFRpgRocket * this, int __in_chrg) */

void __thiscall CTFRpgRocket::~CTFRpgRocket(CTFRpgRocket *this,int __in_chrg)

{
  return;
}


// CLaserSpot::~CLaserSpot  @ 00059da0  (line 603)

/* DWARF original prototype: void ~CLaserSpot(CLaserSpot * this, int __in_chrg) */

void __thiscall CLaserSpot::~CLaserSpot(CLaserSpot *this,int __in_chrg)

{
  return;
}


// CLaserSpot::ObjectCaps  @ 00059c30  (line 608)

/* DWARF original prototype: int ObjectCaps(CLaserSpot * this) */

int __thiscall CLaserSpot::ObjectCaps(CLaserSpot *this)

{
  return -0x80000000;
}


// CTFFlamethrower::~CTFFlamethrower  @ 0005e230  (line 716)

/* DWARF original prototype: void ~CTFFlamethrower(CTFFlamethrower * this, int __in_chrg) */

void __thiscall CTFFlamethrower::~CTFFlamethrower(CTFFlamethrower *this,int __in_chrg)

{
  return;
}


// CTFFlamethrower::iItemSlot  @ 000b9720  (line 722)

/* DWARF original prototype: int iItemSlot(CTFFlamethrower * this) */

int __thiscall CTFFlamethrower::iItemSlot(CTFFlamethrower *this)

{
  return 5;
}


// CTFIncendiaryC::~CTFIncendiaryC  @ 0005e240  (line 749)

/* DWARF original prototype: void ~CTFIncendiaryC(CTFIncendiaryC * this, int __in_chrg) */

void __thiscall CTFIncendiaryC::~CTFIncendiaryC(CTFIncendiaryC *this,int __in_chrg)

{
  return;
}


// CTFIncendiaryC::iItemSlot  @ 000baaa0  (line 755)

/* DWARF original prototype: int iItemSlot(CTFIncendiaryC * this) */

int __thiscall CTFIncendiaryC::iItemSlot(CTFIncendiaryC *this)

{
  return 4;
}


// CTFIncendiaryCRocket::~CTFIncendiaryCRocket  @ 00059dd0  (line 771)

/* DWARF original prototype: void ~CTFIncendiaryCRocket(CTFIncendiaryCRocket * this, int __in_chrg)
    */

void __thiscall
CTFIncendiaryCRocket::~CTFIncendiaryCRocket(CTFIncendiaryCRocket *this,int __in_chrg)

{
  return;
}


// CTFShotgun::~CTFShotgun  @ 0005e1c0  (line 783)

/* DWARF original prototype: void ~CTFShotgun(CTFShotgun * this, int __in_chrg) */

void __thiscall CTFShotgun::~CTFShotgun(CTFShotgun *this,int __in_chrg)

{
  return;
}


// CTFSuperShotgun::~CTFSuperShotgun  @ 0005e200  (line 809)

/* WARNING: Struct "CTFSuperShotgun": ignoring overlapping field "m_usFireSuperShotgun" */
/* DWARF original prototype: void ~CTFSuperShotgun(CTFSuperShotgun * this, int __in_chrg) */

void __thiscall CTFSuperShotgun::~CTFSuperShotgun(CTFSuperShotgun *this,int __in_chrg)

{
  return;
}


// CTFTranq::~CTFTranq  @ 0005e220  (line 822)

/* DWARF original prototype: void ~CTFTranq(CTFTranq * this, int __in_chrg) */

void __thiscall CTFTranq::~CTFTranq(CTFTranq *this,int __in_chrg)

{
  return;
}


// CTFTranq::iItemSlot  @ 000bedb0  (line 827)

/* DWARF original prototype: int iItemSlot(CTFTranq * this) */

int __thiscall CTFTranq::iItemSlot(CTFTranq *this)

{
  return 2;
}


// CTFRailgun::~CTFRailgun  @ 0005e250  (line 839)

/* DWARF original prototype: void ~CTFRailgun(CTFRailgun * this, int __in_chrg) */

void __thiscall CTFRailgun::~CTFRailgun(CTFRailgun *this,int __in_chrg)

{
  return;
}


// CTFRailgun::iItemSlot  @ 000bb940  (line 844)

/* DWARF original prototype: int iItemSlot(CTFRailgun * this) */

int __thiscall CTFRailgun::iItemSlot(CTFRailgun *this)

{
  return 2;
}


// CTFRpg::~CTFRpg  @ 0005e260  (line 856)

/* DWARF original prototype: void ~CTFRpg(CTFRpg * this, int __in_chrg) */

void __thiscall CTFRpg::~CTFRpg(CTFRpg *this,int __in_chrg)

{
  return;
}


// CTFRpg::iItemSlot  @ 000bc310  (line 862)

/* DWARF original prototype: int iItemSlot(CTFRpg * this) */

int __thiscall CTFRpg::iItemSlot(CTFRpg *this)

{
  return 5;
}


// CTFAutoRifle::~CTFAutoRifle  @ 0005e270  (line 878)

/* DWARF original prototype: void ~CTFAutoRifle(CTFAutoRifle * this, int __in_chrg) */

void __thiscall CTFAutoRifle::~CTFAutoRifle(CTFAutoRifle *this,int __in_chrg)

{
  return;
}


// CTFAutoRifle::iItemSlot  @ 000b7580  (line 883)

/* DWARF original prototype: int iItemSlot(CTFAutoRifle * this) */

int __thiscall CTFAutoRifle::iItemSlot(CTFAutoRifle *this)

{
  return 3;
}


// CTFAssaultC::~CTFAssaultC  @ 0005e280  (line 898)

/* DWARF original prototype: void ~CTFAssaultC(CTFAssaultC * this, int __in_chrg) */

void __thiscall CTFAssaultC::~CTFAssaultC(CTFAssaultC *this,int __in_chrg)

{
  return;
}


// CTFAssaultC::iItemSlot  @ 000b6e80  (line 903)

/* DWARF original prototype: int iItemSlot(CTFAssaultC * this) */

int __thiscall CTFAssaultC::iItemSlot(CTFAssaultC *this)

{
  return 3;
}


// CTFAssaultC::ShouldWeaponIdle  @ 000b6e90  (line 919)

/* DWARF original prototype: BOOL ShouldWeaponIdle(CTFAssaultC * this) */

BOOL __thiscall CTFAssaultC::ShouldWeaponIdle(CTFAssaultC *this)

{
  return 1;
}


// CTFGrenadeLauncher::~CTFGrenadeLauncher  @ 0005e1e0  (line 934)

/* DWARF original prototype: void ~CTFGrenadeLauncher(CTFGrenadeLauncher * this, int __in_chrg) */

void __thiscall CTFGrenadeLauncher::~CTFGrenadeLauncher(CTFGrenadeLauncher *this,int __in_chrg)

{
  return;
}


// CTFGrenadeLauncher::iItemSlot  @ 000ba3c0  (line 940)

/* DWARF original prototype: int iItemSlot(CTFGrenadeLauncher * this) */

int __thiscall CTFGrenadeLauncher::iItemSlot(CTFGrenadeLauncher *this)

{
  return 3;
}


// CTFPipebombLauncher::~CTFPipebombLauncher  @ 0005e290  (line 963)

/* DWARF original prototype: void ~CTFPipebombLauncher(CTFPipebombLauncher * this, int __in_chrg) */

void __thiscall CTFPipebombLauncher::~CTFPipebombLauncher(CTFPipebombLauncher *this,int __in_chrg)

{
  return;
}


// CTFPipebombLauncher::iItemSlot  @ 000ba3d0  (line 967)

/* DWARF original prototype: int iItemSlot(CTFPipebombLauncher * this) */

int __thiscall CTFPipebombLauncher::iItemSlot(CTFPipebombLauncher *this)

{
  return 3;
}


// CTFSniperRifle::~CTFSniperRifle  @ 0005e2a0  (line 972)

/* DWARF original prototype: void ~CTFSniperRifle(CTFSniperRifle * this, int __in_chrg) */

void __thiscall CTFSniperRifle::~CTFSniperRifle(CTFSniperRifle *this,int __in_chrg)

{
  return;
}


// CTFSniperRifle::iItemSlot  @ 000be660  (line 977)

/* DWARF original prototype: int iItemSlot(CTFSniperRifle * this) */

int __thiscall CTFSniperRifle::iItemSlot(CTFSniperRifle *this)

{
  return 3;
}


// CTFAxe::~CTFAxe  @ 0005e1f0  (line 999)

/* DWARF original prototype: void ~CTFAxe(CTFAxe * this, int __in_chrg) */

void __thiscall CTFAxe::~CTFAxe(CTFAxe *this,int __in_chrg)

{
  return;
}


// CTFAxe::iItemSlot  @ 000b9080  (line 1004)

/* DWARF original prototype: int iItemSlot(CTFAxe * this) */

int __thiscall CTFAxe::iItemSlot(CTFAxe *this)

{
  return 1;
}


// CTFAxe::IsUseable  @ 000b9090  (line 1016)

/* DWARF original prototype: BOOL IsUseable(CTFAxe * this) */

BOOL __thiscall CTFAxe::IsUseable(CTFAxe *this)

{
  return 1;
}


// CTFKnife::~CTFKnife  @ 0005e2b0  (line 1028)

/* DWARF original prototype: void ~CTFKnife(CTFKnife * this, int __in_chrg) */

void __thiscall CTFKnife::~CTFKnife(CTFKnife *this,int __in_chrg)

{
  return;
}


// CTFSpanner::~CTFSpanner  @ 0005e2c0  (line 1043)

/* DWARF original prototype: void ~CTFSpanner(CTFSpanner * this, int __in_chrg) */

void __thiscall CTFSpanner::~CTFSpanner(CTFSpanner *this,int __in_chrg)

{
  return;
}


// CTFMedikit::~CTFMedikit  @ 0005e2d0  (line 1058)

/* DWARF original prototype: void ~CTFMedikit(CTFMedikit * this, int __in_chrg) */

void __thiscall CTFMedikit::~CTFMedikit(CTFMedikit *this,int __in_chrg)

{
  return;
}


