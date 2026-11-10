// LinkUserMessages__Fv  @ 000e32d0
void LinkUserMessages__Fv(void)

{
  gmsgSelAmmo = (*DAT_001755ec)("SelAmmo",4);
  gmsgCurWeapon = (*DAT_001755ec)("CurWeapon",3);
  gmsgGeigerRange = (*DAT_001755ec)("Geiger",1);
  gmsgFlashlight = (*DAT_001755ec)("Flashlight",2);
  gmsgFlashBattery = (*DAT_001755ec)("FlashBat",1);
  gmsgHealth = (*DAT_001755ec)("Health",1);
  gmsgDamage = (*DAT_001755ec)("Damage",0xc);
  gmsgBattery = (*DAT_001755ec)("Battery",2);
  gmsgGrenades = (*DAT_001755ec)("SecAmmoVal",2);
  gmsgSetSecAmmoIcon = (*DAT_001755ec)("SecAmmoIcon",0xffffffff);
  gmsgTrain = (*DAT_001755ec)("Train",1);
  gmsgItems = (*DAT_001755ec)("Items",4);
  gmsgConcuss = (*DAT_001755ec)("Concuss",1);
  gmsgHudText = (*DAT_001755ec)("HudText",0xffffffff);
  gmsgSayText = (*DAT_001755ec)("SayText",0xffffffff);
  gmsgStatusIcon = (*DAT_001755ec)("StatusIcon",0xffffffff);
  gmsgTextMsg = (*DAT_001755ec)("TextMsg",0xffffffff);
  gmsgStatusText = (*DAT_001755ec)("StatusText",0xffffffff);
  gmsgStatusValue = (*DAT_001755ec)("StatusValue",3);
  gmsgWeaponList = (*DAT_001755ec)("WeaponList",0xffffffff);
  gmsgResetHUD = (*DAT_001755ec)("ResetHUD",1);
  gmsgInitHUD = (*DAT_001755ec)("InitHUD",0);
  gmsgShowGameTitle = (*DAT_001755ec)("GameTitle",1);
  gmsgDeathMsg = (*DAT_001755ec)("DeathMsg",0xffffffff);
  gmsgScoreInfo = (*DAT_001755ec)("ScoreInfo",5);
  gmsgTeamInfo = (*DAT_001755ec)("TeamInfo",0xffffffff);
  gmsgTeamScore = (*DAT_001755ec)("TeamScore",0xffffffff);
  gmsgGameMode = (*DAT_001755ec)("GameMode",1);
  gmsgMOTD = (*DAT_001755ec)(&DAT_0013abad,0xffffffff);
  gmsgAmmoPickup = (*DAT_001755ec)("AmmoPickup",2);
  gmsgWeapPickup = (*DAT_001755ec)("WeapPickup",1);
  gmsgItemPickup = (*DAT_001755ec)("ItemPickup",0xffffffff);
  gmsgHideWeapon = (*DAT_001755ec)("HideWeapon",1);
  gmsgSetFOV = (*DAT_001755ec)("SetFOV",1);
  gmsgShowMenu = (*DAT_001755ec)("ShowMenu",0xffffffff);
  gmsgShake = (*DAT_001755ec)("ScreenShake",6);
  gmsgFade = (*DAT_001755ec)("ScreenFade",10);
  gmsgAmmoX = (*DAT_001755ec)("AmmoX",2);
  return;
}


