// W_Precache__Fv  @ 001237cc
void W_Precache__Fv(void)

{
  memset(_15CBasePlayerItem_ItemInfoArray,0,0x580);
  memset(&_15CBasePlayerItem_AmmoInfoArray,0,0x100);
  giAmmoIndex = 0;
  (*g_engfuncs)("models/grenade.mdl");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_shotgun");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_axe");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_knife");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_medikit");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_spanner");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_ng");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_superng");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_rpg");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_ic");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_flamethrower");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_tranq");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_sniperrifle");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_autorifle");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_railgun");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_ac");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_gl");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_pl");
  UTIL_PrecacheOtherWeapon__FPCc("tf_weapon_supershotgun");
  UTIL_PrecacheOther__FPCc("building_sentrygun");
  UTIL_PrecacheOther__FPCc("building_dispenser");
  UTIL_PrecacheOther__FPCc("tf_weapon_normalgrenade");
  UTIL_PrecacheOther__FPCc("tf_weapon_genericprimedgrenade");
  UTIL_PrecacheOther__FPCc("tf_weapon_concussiongrenade");
  UTIL_PrecacheOther__FPCc("tf_weapon_mirvgrenade");
  UTIL_PrecacheOther__FPCc("tf_weapon_nailgrenade");
  UTIL_PrecacheOther__FPCc("tf_weapon_napalmgrenade");
  UTIL_PrecacheOther__FPCc("tf_weapon_gasgrenade");
  UTIL_PrecacheOther__FPCc("tf_weapon_empgrenade");
  UTIL_PrecacheOther__FPCc("tf_weapon_caltropgrenade");
  UTIL_PrecacheOther__FPCc("tf_weapon_caltrop");
  UTIL_PrecacheOther__FPCc("weaponbox");
  g_sModelIndexFireball = (*g_engfuncs)("sprites/explode01.spr");
  g_sModelIndexWExplosion = (*g_engfuncs)("sprites/WXplo1.spr");
  g_sModelIndexSmoke = (*g_engfuncs)("sprites/steam1.spr");
  g_sModelIndexBubbles = (*g_engfuncs)("sprites/bubble.spr");
  g_sModelIndexBloodSpray = (*g_engfuncs)("sprites/bloodspray.spr");
  g_sModelIndexBloodDrop = (*g_engfuncs)("sprites/blood.spr");
  g_sModelIndexLaser = (*g_engfuncs)(g_pModelNameLaser);
  g_sModelIndexLaserDot = (*g_engfuncs)("sprites/laserdot.spr");
  g_sModelIndexNail = (*g_engfuncs)("models/nail.mdl");
  g_sModelIndexNapalm = (*g_engfuncs)("sprites/explode1.spr");
  g_sModelIndexPlayerFlame = (*g_engfuncs)("sprites/playerflame.spr");
  g_sModelIndexSaveMe = (*g_engfuncs)("sprites/saveme.spr");
  (*DAT_0019f6a4)("weapons/debris1.wav");
  (*DAT_0019f6a4)("weapons/debris2.wav");
  (*DAT_0019f6a4)("weapons/debris3.wav");
  (*DAT_0019f6a4)("weapons/grenade_hit1.wav");
  (*DAT_0019f6a4)("weapons/grenade_hit2.wav");
  (*DAT_0019f6a4)("weapons/grenade_hit3.wav");
  (*DAT_0019f6a4)("weapons/bullet_hit1.wav");
  (*DAT_0019f6a4)("weapons/bullet_hit2.wav");
  (*DAT_0019f6a4)("items/weapondrop1.wav");
  return;
}


