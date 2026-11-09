// Ghidra decompilation of functions from tfc/weapons.h
// 48 functions, ordered by original source line

// CGrenade::BloodColor  @ 000c4590  (line 51)

/* DWARF original prototype: int BloodColor(CGrenade * this) */

int __thiscall CGrenade::BloodColor(CGrenade *this)

{
  return -1;
}


// CBasePlayerItem::AddDuplicate  @ 0015cac0  (line 238)

/* DWARF original prototype: int AddDuplicate(CBasePlayerItem * this, CBasePlayerItem * pItem) */

int __thiscall CBasePlayerItem::AddDuplicate(CBasePlayerItem *this,CBasePlayerItem *pItem)

{
  return 0;
}


// CBasePlayerItem::iItemSlot  @ 0015cad0  (line 239)

/* DWARF original prototype: int iItemSlot(CBasePlayerItem * this) */

int __thiscall CBasePlayerItem::iItemSlot(CBasePlayerItem *this)

{
  return 0;
}


// CBasePlayerItem::GetItemInfo  @ 0015cae0  (line 248)

/* DWARF original prototype: int GetItemInfo(CBasePlayerItem * this, ItemInfo * p) */

int __thiscall CBasePlayerItem::GetItemInfo(CBasePlayerItem *this,ItemInfo *p)

{
  return 0;
}


// CBasePlayerItem::CanDeploy  @ 0015caf0  (line 249)

/* DWARF original prototype: BOOL CanDeploy(CBasePlayerItem * this) */

BOOL __thiscall CBasePlayerItem::CanDeploy(CBasePlayerItem *this)

{
  return 1;
}


// CBasePlayerItem::Deploy  @ 0015cb00  (line 251)

/* DWARF original prototype: BOOL Deploy(CBasePlayerItem * this) */

BOOL __thiscall CBasePlayerItem::Deploy(CBasePlayerItem *this)

{
  return 1;
}


// CBasePlayerItem::CanHolster  @ 000c1740  (line 253)

/* DWARF original prototype: BOOL CanHolster(CBasePlayerItem * this) */

BOOL __thiscall CBasePlayerItem::CanHolster(CBasePlayerItem *this)

{
  return 1;
}


// CBasePlayerItem::UpdateItemInfo  @ 0015cb10  (line 255)

/* DWARF original prototype: void UpdateItemInfo(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::UpdateItemInfo(CBasePlayerItem *this)

{
  return;
}


// CBasePlayerItem::ItemPreFrame  @ 000c1750  (line 257)

/* DWARF original prototype: void ItemPreFrame(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::ItemPreFrame(CBasePlayerItem *this)

{
  return;
}


// CBasePlayerItem::ItemPostFrame  @ 0015cb20  (line 258)

/* DWARF original prototype: void ItemPostFrame(CBasePlayerItem * this) */

void __thiscall CBasePlayerItem::ItemPostFrame(CBasePlayerItem *this)

{
  return;
}


// CBasePlayerItem::PrimaryAmmoIndex  @ 0015cb30  (line 264)

/* DWARF original prototype: int PrimaryAmmoIndex(CBasePlayerItem * this) */

int __thiscall CBasePlayerItem::PrimaryAmmoIndex(CBasePlayerItem *this)

{
  return -1;
}


// CBasePlayerItem::SecondaryAmmoIndex  @ 0015cb40  (line 265)

/* DWARF original prototype: int SecondaryAmmoIndex(CBasePlayerItem * this) */

int __thiscall CBasePlayerItem::SecondaryAmmoIndex(CBasePlayerItem *this)

{
  return -1;
}


// CBasePlayerItem::UpdateClientData  @ 0015cb50  (line 267)

/* DWARF original prototype: int UpdateClientData(CBasePlayerItem * this, CBasePlayer * pPlayer) */

int __thiscall CBasePlayerItem::UpdateClientData(CBasePlayerItem *this,CBasePlayer *pPlayer)

{
  return 0;
}


// CBasePlayerItem::GetWeaponPtr  @ 0015cb60  (line 269)

/* DWARF original prototype: CBasePlayerItem * GetWeaponPtr(CBasePlayerItem * this) */

CBasePlayerItem * __thiscall CBasePlayerItem::GetWeaponPtr(CBasePlayerItem *this)

{
  return (CBasePlayerItem *)0x0;
}


// CBasePlayerWeapon::AddWeapon  @ 000c1760  (line 298)

/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int AddWeapon(CBasePlayerWeapon * this) */

int __thiscall CBasePlayerWeapon::AddWeapon(CBasePlayerWeapon *this)

{
  (*(this->super_CBasePlayerItem).super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity.
    _vptr_CBaseEntity[0x54])(this,this);
  return 1;
}


// CBasePlayerWeapon::UpdateItemInfo  @ 000c1780  (line 304)

/* DWARF original prototype: void UpdateItemInfo(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::UpdateItemInfo(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::PrimaryAttack  @ 0015cb70  (line 325)

/* DWARF original prototype: void PrimaryAttack(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::PrimaryAttack(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::SecondaryAttack  @ 000c1790  (line 326)

/* DWARF original prototype: void SecondaryAttack(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::SecondaryAttack(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::Reload  @ 000c17a0  (line 327)

/* DWARF original prototype: void Reload(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::Reload(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::WeaponIdle  @ 000c17b0  (line 328)

/* DWARF original prototype: void WeaponIdle(CBasePlayerWeapon * this) */

void __thiscall CBasePlayerWeapon::WeaponIdle(CBasePlayerWeapon *this)

{
  return;
}


// CBasePlayerWeapon::ShouldWeaponIdle  @ 000c17c0  (line 331)

/* DWARF original prototype: BOOL ShouldWeaponIdle(CBasePlayerWeapon * this) */

BOOL __thiscall CBasePlayerWeapon::ShouldWeaponIdle(CBasePlayerWeapon *this)

{
  return 0;
}


// CBasePlayerWeapon::GetWeaponPtr  @ 000c17d0  (line 338)

/* DWARF original prototype: CBasePlayerItem * GetWeaponPtr(CBasePlayerWeapon * this) */

CBasePlayerItem * __thiscall CBasePlayerWeapon::GetWeaponPtr(CBasePlayerWeapon *this)

{
  return &this->super_CBasePlayerItem;
}


// CBasePlayerAmmo::AddAmmo  @ 0015cb80  (line 374)

/* DWARF original prototype: BOOL AddAmmo(CBasePlayerAmmo * this, CBaseEntity * pOther) */

BOOL __thiscall CBasePlayerAmmo::AddAmmo(CBasePlayerAmmo *this,CBaseEntity *pOther)

{
  return 1;
}


// CCrowbar::iItemSlot  @ 000c17e0  (line 495)

/* DWARF original prototype: int iItemSlot(CCrowbar * this) */

int __thiscall CCrowbar::iItemSlot(CCrowbar *this)

{
  return 1;
}


// CTFNailgun::iItemSlot  @ 0016a660  (line 541)

/* DWARF original prototype: int iItemSlot(CTFNailgun * this) */

int __thiscall CTFNailgun::iItemSlot(CTFNailgun *this)

{
  return 2;
}


// CTFSuperNailgun::iItemSlot  @ 0016a670  (line 558)

/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */
/* DWARF original prototype: int iItemSlot(CTFSuperNailgun * this) */

int __thiscall CTFSuperNailgun::iItemSlot(CTFSuperNailgun *this)

{
  return 4;
}


// CLaserSpot::ObjectCaps  @ 00137220  (line 608)

/* DWARF original prototype: int ObjectCaps(CLaserSpot * this) */

int __thiscall CLaserSpot::ObjectCaps(CLaserSpot *this)

{
  return -0x80000000;
}


// CTFSentrygun::Classify  @ 0011d840  (line 630)

/* DWARF original prototype: int Classify(CTFSentrygun * this) */

int __thiscall CTFSentrygun::Classify(CTFSentrygun *this)

{
  return 1;
}


// CTFSentrygun::BloodColor  @ 0011d850  (line 633)

/* DWARF original prototype: int BloodColor(CTFSentrygun * this) */

int __thiscall CTFSentrygun::BloodColor(CTFSentrygun *this)

{
  return -1;
}


// CTFSentrygunBase::Classify  @ 0011d860  (line 679)

/* DWARF original prototype: int Classify(CTFSentrygunBase * this) */

int __thiscall CTFSentrygunBase::Classify(CTFSentrygunBase *this)

{
  return 1;
}


// CTFDispenser::Classify  @ 000c6430  (line 694)

/* DWARF original prototype: int Classify(CTFDispenser * this) */

int __thiscall CTFDispenser::Classify(CTFDispenser *this)

{
  return 1;
}


// CTFDispenser::BloodColor  @ 000c6440  (line 695)

/* DWARF original prototype: int BloodColor(CTFDispenser * this) */

int __thiscall CTFDispenser::BloodColor(CTFDispenser *this)

{
  return -1;
}


// CTFFlamethrower::iItemSlot  @ 001688d0  (line 722)

/* DWARF original prototype: int iItemSlot(CTFFlamethrower * this) */

int __thiscall CTFFlamethrower::iItemSlot(CTFFlamethrower *this)

{
  return 5;
}


// CTFIncendiaryC::iItemSlot  @ 00169d20  (line 755)

/* DWARF original prototype: int iItemSlot(CTFIncendiaryC * this) */

int __thiscall CTFIncendiaryC::iItemSlot(CTFIncendiaryC *this)

{
  return 4;
}


// CTFTranq::iItemSlot  @ 0016dc20  (line 827)

/* DWARF original prototype: int iItemSlot(CTFTranq * this) */

int __thiscall CTFTranq::iItemSlot(CTFTranq *this)

{
  return 2;
}


// CTFRailgun::iItemSlot  @ 0016ab40  (line 844)

/* DWARF original prototype: int iItemSlot(CTFRailgun * this) */

int __thiscall CTFRailgun::iItemSlot(CTFRailgun *this)

{
  return 2;
}


// CTFRpg::iItemSlot  @ 0016b4a0  (line 862)

/* DWARF original prototype: int iItemSlot(CTFRpg * this) */

int __thiscall CTFRpg::iItemSlot(CTFRpg *this)

{
  return 5;
}


// CTFAutoRifle::iItemSlot  @ 00165b30  (line 883)

/* DWARF original prototype: int iItemSlot(CTFAutoRifle * this) */

int __thiscall CTFAutoRifle::iItemSlot(CTFAutoRifle *this)

{
  return 3;
}


// CTFAssaultC::iItemSlot  @ 00165460  (line 903)

/* DWARF original prototype: int iItemSlot(CTFAssaultC * this) */

int __thiscall CTFAssaultC::iItemSlot(CTFAssaultC *this)

{
  return 3;
}


// CTFAssaultC::ShouldWeaponIdle  @ 00165470  (line 919)

/* DWARF original prototype: BOOL ShouldWeaponIdle(CTFAssaultC * this) */

BOOL __thiscall CTFAssaultC::ShouldWeaponIdle(CTFAssaultC *this)

{
  return 1;
}


// CTFGrenadeLauncher::iItemSlot  @ 001695e0  (line 940)

/* DWARF original prototype: int iItemSlot(CTFGrenadeLauncher * this) */

int __thiscall CTFGrenadeLauncher::iItemSlot(CTFGrenadeLauncher *this)

{
  return 3;
}


// CTFPipebombLauncher::iItemSlot  @ 001695f0  (line 967)

/* DWARF original prototype: int iItemSlot(CTFPipebombLauncher * this) */

int __thiscall CTFPipebombLauncher::iItemSlot(CTFPipebombLauncher *this)

{
  return 3;
}


// CTFSniperRifle::iItemSlot  @ 0016d430  (line 977)

/* DWARF original prototype: int iItemSlot(CTFSniperRifle * this) */

int __thiscall CTFSniperRifle::iItemSlot(CTFSniperRifle *this)

{
  return 3;
}


// CTFAxe::iItemSlot  @ 00168190  (line 1004)

/* DWARF original prototype: int iItemSlot(CTFAxe * this) */

int __thiscall CTFAxe::iItemSlot(CTFAxe *this)

{
  return 1;
}


// CTFAxe::IsUseable  @ 001681a0  (line 1016)

/* DWARF original prototype: BOOL IsUseable(CTFAxe * this) */

BOOL __thiscall CTFAxe::IsUseable(CTFAxe *this)

{
  return 1;
}


// CDetpack::Classify  @ 000c45a0  (line 1112)

/* DWARF original prototype: int Classify(CDetpack * this) */

int __thiscall CDetpack::Classify(CDetpack *this)

{
  return 1;
}


// CTFTeleporter::Classify  @ 00164670  (line 1139)

/* DWARF original prototype: int Classify(CTFTeleporter * this) */

int __thiscall CTFTeleporter::Classify(CTFTeleporter *this)

{
  return 1;
}


// CTFTeleporter::BloodColor  @ 00164680  (line 1140)

/* DWARF original prototype: int BloodColor(CTFTeleporter * this) */

int __thiscall CTFTeleporter::BloodColor(CTFTeleporter *this)

{
  return -1;
}


