// LinkUserMessages__Fv  @ 000d76fc
void LinkUserMessages__Fv(void)

{
  if (gmsgHealth == 0) {
    gmsgSelAmmo = (*DAT_001a7f6c)("SelAmmo",4);
    gmsgCurWeapon = (*DAT_001a7f6c)("CurWeapon",3);
    gmsgGeigerRange = (*DAT_001a7f6c)("Geiger",1);
    gmsgFlashlight = (*DAT_001a7f6c)("Flashlight",2);
    gmsgFlashBattery = (*DAT_001a7f6c)(FUN_0013b694,1);
    gmsgHealth = (*DAT_001a7f6c)("Health",1);
    gmsgDamage = (*DAT_001a7f6c)("Damage",0xc);
    gmsgBattery = (*DAT_001a7f6c)("Battery",2);
    gmsgGrenades = (*DAT_001a7f6c)("SecAmmoVal",2);
    gmsgSetSecAmmoIcon = (*DAT_001a7f6c)("SecAmmoIcon",0xffffffff);
    gmsgTrain = (*DAT_001a7f6c)("Train",1);
    gmsgItems = (*DAT_001a7f6c)(&UNK_0013b6d0,4);
    gmsgConcuss = (*DAT_001a7f6c)("Concuss",1);
    gmsgHudText = (*DAT_001a7f6c)(&UNK_0013b6de,0xffffffff);
    gmsgSayText = (*DAT_001a7f6c)("SayText",0xffffffff);
    gmsgStatusIcon = (*DAT_001a7f6c)("StatusIcon",0xffffffff);
    gmsgTextMsg = (*DAT_001a7f6c)(&UNK_0013b6f9,0xffffffff);
    gmsgStatusText = (*DAT_001a7f6c)("StatusText",0xffffffff);
    gmsgStatusValue = (*DAT_001a7f6c)("StatusValue",3);
    gmsgWeaponList = (*DAT_001a7f6c)("WeaponList",0xffffffff);
    gmsgResetHUD = (*DAT_001a7f6c)("ResetHUD",1);
    gmsgInitHUD = (*DAT_001a7f6c)("InitHUD",0);
    gmsgShowGameTitle = (*DAT_001a7f6c)("GameTitle",1);
    gmsgDeathMsg = (*DAT_001a7f6c)("DeathMsg",0xffffffff);
    gmsgScoreInfo = (*DAT_001a7f6c)("ScoreInfo",9);
    gmsgTeamInfo = (*DAT_001a7f6c)("TeamInfo",0xffffffff);
    gmsgTeamScore = (*DAT_001a7f6c)("TeamScore",0xffffffff);
    gmsgGameMode = (*DAT_001a7f6c)("GameMode",1);
    gmsgMOTD = (*DAT_001a7f6c)(&UNK_0013b76d,0xffffffff);
    gmsgServerName = (*DAT_001a7f6c)("ServerName",0xffffffff);
    gmsgAmmoPickup = (*DAT_001a7f6c)("AmmoPickup",2);
    gmsgWeapPickup = (*DAT_001a7f6c)("WeapPickup",1);
    gmsgItemPickup = (*DAT_001a7f6c)("ItemPickup",0xffffffff);
    gmsgHideWeapon = (*DAT_001a7f6c)("HideWeapon",1);
    gmsgSetFOV = (*DAT_001a7f6c)(&UNK_0013b7a9,1);
    gmsgShowMenu = (*DAT_001a7f6c)("ShowMenu",0xffffffff);
    gmsgShake = (*DAT_001a7f6c)("ScreenShake",6);
    gmsgFade = (*DAT_001a7f6c)("ScreenFade",10);
    gmsgAmmoX = (*DAT_001a7f6c)(&UNK_0013b7d0,2);
    gmsgBench = (*DAT_001a7f6c)("Bench",1);
    gmsgSpectator = (*DAT_001a7f6c)("Spectator",2);
    gmsgAllowSpec = (*DAT_001a7f6c)("AllowSpec",1);
    gmsgValidClasses = (*DAT_001a7f6c)("ValClass",10);
    gmsgTeamNames = (*DAT_001a7f6c)("TeamNames",0xffffffff);
    gmsgFeignState = (*DAT_001a7f6c)("Feign",1);
    gmsgDetpackState = (*DAT_001a7f6c)("Detpack",1);
    gmsgVGUIMenu = (*DAT_001a7f6c)("VGUIMenu",0xffffffff);
    gmsgBuildState = (*DAT_001a7f6c)("BuildSt",1);
    gmsgRandomPC = (*DAT_001a7f6c)("RandomPC",1);
  }
  return;
}


