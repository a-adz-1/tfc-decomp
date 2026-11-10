// ClientPrecache__Fv  @ 00091bf4
void ClientPrecache__Fv(void)

{
  int iVar1;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (*DAT_0019f6a4)("player/sprayer.wav");
  (*DAT_0019f6a4)("player/plyrjmp8.wav");
  (*DAT_0019f6a4)("misc/talk.wav");
  (*DAT_0019f6a4)("player/pain1.wav");
  (*DAT_0019f6a4)("player/pain2.wav");
  (*DAT_0019f6a4)("player/pain3.wav");
  (*DAT_0019f6a4)("player/pain4.wav");
  (*DAT_0019f6a4)("player/pain5.wav");
  (*DAT_0019f6a4)("player/pain6.wav");
  (*DAT_0019f6a4)("player/axhit1.wav");
  (*DAT_0019f6a4)("player/drown1.wav");
  (*DAT_0019f6a4)("player/drown2.wav");
  (*DAT_0019f6a4)("player/h2odeath.wav");
  (*DAT_0019f6a4)("player/death1.wav");
  (*DAT_0019f6a4)("player/death2.wav");
  (*DAT_0019f6a4)("player/death3.wav");
  (*DAT_0019f6a4)("player/death4.wav");
  (*DAT_0019f6a4)("player/death5.wav");
  (*DAT_0019f6a4)("player/gib.wav");
  (*DAT_0019f6a4)("player/pl_fallpain2.wav");
  (*DAT_0019f6a4)("player/pl_fallpain3.wav");
  (*DAT_0019f6a4)("player/pl_step1.wav");
  (*DAT_0019f6a4)("player/pl_step2.wav");
  (*DAT_0019f6a4)("player/pl_step3.wav");
  (*DAT_0019f6a4)("player/pl_step4.wav");
  (*DAT_0019f6a4)("common/npc_step1.wav");
  (*DAT_0019f6a4)("common/npc_step2.wav");
  (*DAT_0019f6a4)("common/npc_step3.wav");
  (*DAT_0019f6a4)("common/npc_step4.wav");
  (*DAT_0019f6a4)("player/pl_metal1.wav");
  (*DAT_0019f6a4)("player/pl_metal2.wav");
  (*DAT_0019f6a4)("player/pl_metal3.wav");
  (*DAT_0019f6a4)("player/pl_metal4.wav");
  (*DAT_0019f6a4)("player/pl_dirt1.wav");
  (*DAT_0019f6a4)("player/pl_dirt2.wav");
  (*DAT_0019f6a4)("player/pl_dirt3.wav");
  (*DAT_0019f6a4)("player/pl_dirt4.wav");
  (*DAT_0019f6a4)("player/pl_duct1.wav");
  (*DAT_0019f6a4)("player/pl_duct2.wav");
  (*DAT_0019f6a4)("player/pl_duct3.wav");
  (*DAT_0019f6a4)("player/pl_duct4.wav");
  (*DAT_0019f6a4)("player/pl_grate1.wav");
  (*DAT_0019f6a4)("player/pl_grate2.wav");
  (*DAT_0019f6a4)("player/pl_grate3.wav");
  (*DAT_0019f6a4)("player/pl_grate4.wav");
  (*DAT_0019f6a4)("player/pl_slosh1.wav");
  (*DAT_0019f6a4)("player/pl_slosh2.wav");
  (*DAT_0019f6a4)("player/pl_slosh3.wav");
  (*DAT_0019f6a4)("player/pl_slosh4.wav");
  (*DAT_0019f6a4)("player/pl_tile1.wav");
  (*DAT_0019f6a4)("player/pl_tile2.wav");
  (*DAT_0019f6a4)("player/pl_tile3.wav");
  (*DAT_0019f6a4)("player/pl_tile4.wav");
  (*DAT_0019f6a4)("player/pl_tile5.wav");
  (*DAT_0019f6a4)("player/pl_swim1.wav");
  (*DAT_0019f6a4)("player/pl_swim2.wav");
  (*DAT_0019f6a4)("player/pl_swim3.wav");
  (*DAT_0019f6a4)("player/pl_swim4.wav");
  (*DAT_0019f6a4)("player/pl_ladder1.wav");
  (*DAT_0019f6a4)("player/pl_ladder2.wav");
  (*DAT_0019f6a4)("player/pl_ladder3.wav");
  (*DAT_0019f6a4)("player/pl_ladder4.wav");
  (*DAT_0019f6a4)("player/pl_wade1.wav");
  (*DAT_0019f6a4)("player/pl_wade2.wav");
  (*DAT_0019f6a4)("player/pl_wade3.wav");
  (*DAT_0019f6a4)("player/pl_wade4.wav");
  (*DAT_0019f6a4)("debris/wood1.wav");
  (*DAT_0019f6a4)("debris/wood2.wav");
  (*DAT_0019f6a4)("debris/wood3.wav");
  (*DAT_0019f6a4)("plats/train_use1.wav");
  (*DAT_0019f6a4)("buttons/spark5.wav");
  (*DAT_0019f6a4)("buttons/spark6.wav");
  (*DAT_0019f6a4)("debris/glass1.wav");
  (*DAT_0019f6a4)("debris/glass2.wav");
  (*DAT_0019f6a4)("debris/glass3.wav");
  (*DAT_0019f6a4)("misc/r_tele3.wav");
  (*DAT_0019f6a4)("misc/r_tele4.wav");
  (*DAT_0019f6a4)("items/medshot4.wav");
  (*DAT_0019f6a4)("items/medshot5.wav");
  (*DAT_0019f6a4)("items/r_item2.wav");
  (*DAT_0019f6a4)("weapons/building.wav");
  (*DAT_0019f6a4)("weapons/ax1.wav");
  (*DAT_0019f6a4)("weapons/timer.wav");
  (*DAT_0019f6a4)("items/itembk2.wav");
  (*DAT_0019f6a4)("items/flashlight1.wav");
  (*DAT_0019f6a4)("items/flashlight1.wav");
  (*DAT_0019f6a4)("common/bodysplat.wav");
  (*DAT_0019f6a4)("player/pl_pain2.wav");
  (*DAT_0019f6a4)("player/pl_pain4.wav");
  (*DAT_0019f6a4)("player/pl_pain5.wav");
  (*DAT_0019f6a4)("player/pl_pain6.wav");
  (*DAT_0019f6a4)("player/pl_pain7.wav");
  (*DAT_0019f6a4)("speech/saveme1.wav");
  (*DAT_0019f6a4)("speech/saveme2.wav");
  (*DAT_0019f6a4)("vox/stolen.wav");
  iVar1 = 1;
  do {
    if (*(int *)(sNewClassModelFiles + iVar1 * 4) != 0) {
      (*g_engfuncs)(*(int *)(sNewClassModelFiles + iVar1 * 4));
    }
    if (*(int *)(sOldClassModelFiles + iVar1 * 4) != 0) {
      (*g_engfuncs)(*(int *)(sOldClassModelFiles + iVar1 * 4));
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xc);
  iVar1 = 0;
  do {
    (*g_engfuncs)((&sNewWeaponPModels)[iVar1]);
    (*g_engfuncs)((&sOldWeaponPModels)[iVar1]);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x12);
  iVar1 = 1;
  local_c = 0xc1600000;
  local_8 = 0xc2440000;
  local_10 = 0xc22c0000;
  local_18 = 0x41300000;
  local_14 = 0x42440000;
  local_1c = 0x422c0000;
  do {
    if (*(int *)(sNewClassModelFiles + iVar1 * 4) != 0) {
      (*DAT_0019f8c8)(2,&local_10,&local_1c,*(int *)(sNewClassModelFiles + iVar1 * 4));
    }
    if (*(int *)(sOldClassModelFiles + iVar1 * 4) != 0) {
      (*DAT_0019f8c8)(2,&local_10,&local_1c,*(int *)(sOldClassModelFiles + iVar1 * 4));
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xc);
  iVar1 = 0;
  do {
    (*DAT_0019f8c8)(0,0,0,(&sNewWeaponPModels)[iVar1]);
    (*DAT_0019f8c8)(0,0,0,(&sOldWeaponPModels)[iVar1]);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x12);
  (*DAT_0019f8c8)(0,0,0,"models/w_grenade.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/spy_grenade.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/ngrenade.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/napalm.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/pipebomb.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/mirv_grenade.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/bomblet.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/emp_grenade.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/conc_grenade.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/caltrop.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/flag.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/ball.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/detpack.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/w_rpg.mdl");
  (*DAT_0019f8c8)(0,0,0,"models/rpgrocket.mdl");
  local_28 = 0xc2000000;
  local_34 = 0x42000000;
  local_30 = local_34;
  local_2c = local_34;
  local_24 = local_28;
  local_20 = local_28;
  (*DAT_0019f8c8)(2,&local_28,&local_34,"models/base.mdl");
  local_28 = 0xc1c00000;
  local_24 = local_28;
  local_20 = local_28;
  (*DAT_0019f8c8)(2,&local_28,&local_34,"models/sentry1.mdl");
  (*DAT_0019f8c8)(2,&local_28,&local_34,"models/sentry2.mdl");
  (*DAT_0019f8c8)(2,&local_28,&local_34,"models/sentry3.mdl");
  local_34 = 0x41800000;
  local_30 = 0x42800000;
  local_2c = local_34;
  (*DAT_0019f8c8)(2,&local_28,&local_34,"models/dispenser.mdl");
  (*DAT_0019f8c8)(0,0,0,"sprites/playerflame.spr");
  (*DAT_0019f8c8)(0,0,0,"sprites/fthrow.spr");
  UTIL_PrecacheOther__FPCc("detpack");
  (*DAT_0019f6a4)("ambience/flameburst1.wav");
  (*DAT_0019f6a4)("ambience/steamburst1.wav");
  (*DAT_0019f6a4)("misc/b1.wav");
  (*DAT_0019f6a4)("misc/b2.wav");
  (*DAT_0019f6a4)("misc/party1.wav");
  (*DAT_0019f6a4)("misc/party2.wav");
  (*DAT_0019f6a4)("common/wpn_hudoff.wav");
  (*DAT_0019f6a4)("common/wpn_hudon.wav");
  (*DAT_0019f6a4)("common/wpn_moveselect.wav");
  (*DAT_0019f6a4)("common/wpn_select.wav");
  (*DAT_0019f6a4)("common/wpn_denyselect.wav");
  return;
}


