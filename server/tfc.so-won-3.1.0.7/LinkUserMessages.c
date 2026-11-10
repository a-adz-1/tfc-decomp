// LinkUserMessages__Fv  @ 000e346c
void LinkUserMessages__Fv(void)

{
  if (gmsgHealth == 0) {
    gmsgSelAmmo = (*DAT_001c114c)("SelAmmo",4);
    gmsgCurWeapon = (*DAT_001c114c)("CurWeapon",3);
    gmsgGeigerRange = (*DAT_001c114c)("Geiger",1);
    gmsgFlashlight = (*DAT_001c114c)("Flashlight",2);
    gmsgFlashBattery = (*DAT_001c114c)("FlashBat",1);
    gmsgHealth = (*DAT_001c114c)("Health",1);
    gmsgDamage = (*DAT_001c114c)("Damage",0xc);
    gmsgBattery = (*DAT_001c114c)("Battery",2);
    gmsgGrenades = (*DAT_001c114c)("SecAmmoVal",2);
    gmsgSetSecAmmoIcon = (*DAT_001c114c)("SecAmmoIcon",0xffffffff);
    gmsgTrain = (*DAT_001c114c)("Train",1);
    gmsgItems = (*DAT_001c114c)(&UNK_0014c0b0,4);
    gmsgConcuss = (*DAT_001c114c)("Concuss",1);
    gmsgHudText = (*DAT_001c114c)(&UNK_0014c0be,0xffffffff);
    gmsgSayText = (*DAT_001c114c)("SayText",0xffffffff);
    gmsgStatusIcon = (*DAT_001c114c)("StatusIcon",0xffffffff);
    gmsgTextMsg = (*DAT_001c114c)(&UNK_0014c0d9,0xffffffff);
    gmsgStatusText = (*DAT_001c114c)("StatusText",0xffffffff);
    gmsgStatusValue = (*DAT_001c114c)("StatusValue",3);
    gmsgWeaponList = (*DAT_001c114c)("WeaponList",0xffffffff);
    gmsgResetHUD = (*DAT_001c114c)("ResetHUD",1);
    gmsgInitHUD = (*DAT_001c114c)("InitHUD",0);
    gmsgShowGameTitle = (*DAT_001c114c)("GameTitle",1);
    gmsgDeathMsg = (*DAT_001c114c)("DeathMsg",0xffffffff);
    gmsgScoreInfo = (*DAT_001c114c)("ScoreInfo",9);
    gmsgTeamInfo = (*DAT_001c114c)("TeamInfo",0xffffffff);
    gmsgTeamScore = (*DAT_001c114c)("TeamScore",0xffffffff);
    gmsgGameMode = (*DAT_001c114c)("GameMode",1);
    gmsgMOTD = (*DAT_001c114c)(&UNK_0014c14d,0xffffffff);
    gmsgServerName = (*DAT_001c114c)("ServerName",0xffffffff);
    gmsgAmmoPickup = (*DAT_001c114c)("AmmoPickup",2);
    gmsgWeapPickup = (*DAT_001c114c)("WeapPickup",1);
    gmsgItemPickup = (*DAT_001c114c)("ItemPickup",0xffffffff);
    gmsgHideWeapon = (*DAT_001c114c)("HideWeapon",1);
    gmsgSetFOV = (*DAT_001c114c)(&UNK_0014c189,1);
    gmsgShowMenu = (*DAT_001c114c)("ShowMenu",0xffffffff);
    gmsgShake = (*DAT_001c114c)("ScreenShake",6);
    gmsgFade = (*DAT_001c114c)("ScreenFade",10);
    gmsgAmmoX = (*DAT_001c114c)(&UNK_0014c1b0,2);
    gmsgBench = (*DAT_001c114c)("Bench",1);
    gmsgSpectator = (*DAT_001c114c)("Spectator",2);
    gmsgAllowSpec = (*DAT_001c114c)("AllowSpec",1);
    gmsgValidClasses = (*DAT_001c114c)("ValClass",10);
    gmsgTeamNames = (*DAT_001c114c)("TeamNames",0xffffffff);
    gmsgFeignState = (*DAT_001c114c)("Feign",1);
    gmsgDetpackState = (*DAT_001c114c)("Detpack",1);
    gmsgVGUIMenu = (*DAT_001c114c)("VGUIMenu",0xffffffff);
    gmsgBuildState = (*DAT_001c114c)("BuildSt",1);
    gmsgRandomPC = (*DAT_001c114c)("RandomPC",1);
  }
  return;
}


