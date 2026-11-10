// LinkUserMessages__Fv  @ 000e2ba0
void LinkUserMessages__Fv(void)

{
  if (gmsgHealth == 0) {
    gmsgSelAmmo = (*DAT_0019f7cc)("SelAmmo",4);
    gmsgCurWeapon = (*DAT_0019f7cc)("CurWeapon",3);
    gmsgGeigerRange = (*DAT_0019f7cc)("Geiger",1);
    gmsgFlashlight = (*DAT_0019f7cc)("Flashlight",2);
    gmsgFlashBattery = (*DAT_0019f7cc)("FlashBat",1);
    gmsgHealth = (*DAT_0019f7cc)("Health",1);
    gmsgDamage = (*DAT_0019f7cc)("Damage",0xc);
    gmsgBattery = (*DAT_0019f7cc)("Battery",2);
    gmsgGrenades = (*DAT_0019f7cc)("SecAmmoVal",2);
    gmsgSetSecAmmoIcon = (*DAT_0019f7cc)("SecAmmoIcon",0xffffffff);
    gmsgTrain = (*DAT_0019f7cc)("Train",1);
    gmsgItems = (*DAT_0019f7cc)("Items",4);
    gmsgConcuss = (*DAT_0019f7cc)("Concuss",1);
    gmsgHudText = (*DAT_0019f7cc)("HudText",0xffffffff);
    gmsgSayText = (*DAT_0019f7cc)("SayText",0xffffffff);
    gmsgStatusIcon = (*DAT_0019f7cc)("StatusIcon",0xffffffff);
    gmsgTextMsg = (*DAT_0019f7cc)("TextMsg",0xffffffff);
    gmsgStatusText = (*DAT_0019f7cc)("StatusText",0xffffffff);
    gmsgStatusValue = (*DAT_0019f7cc)("StatusValue",3);
    gmsgWeaponList = (*DAT_0019f7cc)("WeaponList",0xffffffff);
    gmsgResetHUD = (*DAT_0019f7cc)("ResetHUD",1);
    gmsgInitHUD = (*DAT_0019f7cc)("InitHUD",0);
    gmsgViewMode = (*DAT_0019f7cc)("ViewMode",0);
    gmsgShowGameTitle = (*DAT_0019f7cc)("GameTitle",1);
    gmsgDeathMsg = (*DAT_0019f7cc)("DeathMsg",0xffffffff);
    gmsgScoreInfo = (*DAT_0019f7cc)("ScoreInfo",9);
    gmsgTeamInfo = (*DAT_0019f7cc)("TeamInfo",0xffffffff);
    gmsgTeamScore = (*DAT_0019f7cc)("TeamScore",0xffffffff);
    gmsgGameMode = (*DAT_0019f7cc)("GameMode",1);
    gmsgMOTD = (*DAT_0019f7cc)(&UNK_00151376,0xffffffff);
    gmsgServerName = (*DAT_0019f7cc)("ServerName",0xffffffff);
    gmsgAmmoPickup = (*DAT_0019f7cc)("AmmoPickup",2);
    gmsgWeapPickup = (*DAT_0019f7cc)("WeapPickup",1);
    gmsgItemPickup = (*DAT_0019f7cc)("ItemPickup",0xffffffff);
    gmsgHideWeapon = (*DAT_0019f7cc)("HideWeapon",1);
    gmsgSetFOV = (*DAT_0019f7cc)(&UNK_001513b2,1);
    gmsgShowMenu = (*DAT_0019f7cc)("ShowMenu",0xffffffff);
    gmsgShake = (*DAT_0019f7cc)("ScreenShake",6);
    gmsgFade = (*DAT_0019f7cc)("ScreenFade",10);
    gmsgAmmoX = (*DAT_0019f7cc)(&UNK_001513d9,2);
    gmsgBench = (*DAT_0019f7cc)("Bench",1);
    gmsgSpectator = (*DAT_0019f7cc)("Spectator",2);
    gmsgAllowSpec = (*DAT_0019f7cc)("AllowSpec",1);
    gmsgValidClasses = (*DAT_0019f7cc)("ValClass",10);
    gmsgTeamNames = (*DAT_0019f7cc)("TeamNames",0xffffffff);
    gmsgFeignState = (*DAT_0019f7cc)("Feign",1);
    gmsgDetpackState = (*DAT_0019f7cc)("Detpack",1);
    gmsgVGUIMenu = (*DAT_0019f7cc)("VGUIMenu",0xffffffff);
    gmsgBuildState = (*DAT_0019f7cc)("BuildSt",1);
    gmsgRandomPC = (*DAT_0019f7cc)("RandomPC",1);
  }
  return;
}


