// ClientPrecache__Fv  @ 00092348
void ClientPrecache__Fv(void)

{
  int iVar1;
  int iVar2;
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
  undefined4 local_4;
  
  (*DAT_001c1024)("player/sprayer.wav");
  (*DAT_001c1024)("player/plyrjmp8.wav");
  (*DAT_001c1024)("misc/talk.wav");
  (*DAT_001c1024)("player/pain1.wav");
  (*DAT_001c1024)("player/pain2.wav");
  (*DAT_001c1024)("player/pain3.wav");
  (*DAT_001c1024)("player/pain4.wav");
  (*DAT_001c1024)("player/pain5.wav");
  (*DAT_001c1024)("player/pain6.wav");
  (*DAT_001c1024)("player/axhit1.wav");
  (*DAT_001c1024)("player/drown1.wav");
  (*DAT_001c1024)("player/drown2.wav");
  (*DAT_001c1024)("player/h2odeath.wav");
  (*DAT_001c1024)("player/death1.wav");
  (*DAT_001c1024)("player/death2.wav");
  (*DAT_001c1024)("player/death3.wav");
  (*DAT_001c1024)("player/death4.wav");
  (*DAT_001c1024)("player/death5.wav");
  (*DAT_001c1024)("player/gib.wav");
  (*DAT_001c1024)("player/pl_fallpain2.wav");
  (*DAT_001c1024)("player/pl_fallpain3.wav");
  (*DAT_001c1024)("player/pl_step1.wav");
  (*DAT_001c1024)("player/pl_step2.wav");
  (*DAT_001c1024)("player/pl_step3.wav");
  (*DAT_001c1024)("player/pl_step4.wav");
  (*DAT_001c1024)("common/npc_step1.wav");
  (*DAT_001c1024)("common/npc_step2.wav");
  (*DAT_001c1024)("common/npc_step3.wav");
  (*DAT_001c1024)("common/npc_step4.wav");
  (*DAT_001c1024)("player/pl_metal1.wav");
  (*DAT_001c1024)("player/pl_metal2.wav");
  (*DAT_001c1024)("player/pl_metal3.wav");
  (*DAT_001c1024)("player/pl_metal4.wav");
  (*DAT_001c1024)("player/pl_dirt1.wav");
  (*DAT_001c1024)("player/pl_dirt2.wav");
  (*DAT_001c1024)("player/pl_dirt3.wav");
  (*DAT_001c1024)("player/pl_dirt4.wav");
  (*DAT_001c1024)("player/pl_duct1.wav");
  (*DAT_001c1024)("player/pl_duct2.wav");
  (*DAT_001c1024)("player/pl_duct3.wav");
  (*DAT_001c1024)("player/pl_duct4.wav");
  (*DAT_001c1024)("player/pl_grate1.wav");
  (*DAT_001c1024)("player/pl_grate2.wav");
  (*DAT_001c1024)("player/pl_grate3.wav");
  (*DAT_001c1024)("player/pl_grate4.wav");
  (*DAT_001c1024)("player/pl_slosh1.wav");
  (*DAT_001c1024)("player/pl_slosh2.wav");
  (*DAT_001c1024)("player/pl_slosh3.wav");
  (*DAT_001c1024)("player/pl_slosh4.wav");
  (*DAT_001c1024)("player/pl_tile1.wav");
  (*DAT_001c1024)("player/pl_tile2.wav");
  (*DAT_001c1024)("player/pl_tile3.wav");
  (*DAT_001c1024)("player/pl_tile4.wav");
  (*DAT_001c1024)("player/pl_tile5.wav");
  (*DAT_001c1024)("player/pl_swim1.wav");
  (*DAT_001c1024)("player/pl_swim2.wav");
  (*DAT_001c1024)("player/pl_swim3.wav");
  (*DAT_001c1024)("player/pl_swim4.wav");
  (*DAT_001c1024)("player/pl_ladder1.wav");
  (*DAT_001c1024)("player/pl_ladder2.wav");
  (*DAT_001c1024)("player/pl_ladder3.wav");
  (*DAT_001c1024)("player/pl_ladder4.wav");
  (*DAT_001c1024)("player/pl_wade1.wav");
  (*DAT_001c1024)("player/pl_wade2.wav");
  (*DAT_001c1024)("player/pl_wade3.wav");
  (*DAT_001c1024)("player/pl_wade4.wav");
  (*DAT_001c1024)("debris/wood1.wav");
  (*DAT_001c1024)("debris/wood2.wav");
  (*DAT_001c1024)("debris/wood3.wav");
  (*DAT_001c1024)("plats/train_use1.wav");
  (*DAT_001c1024)("buttons/spark5.wav");
  (*DAT_001c1024)("buttons/spark6.wav");
  (*DAT_001c1024)("debris/glass1.wav");
  (*DAT_001c1024)("debris/glass2.wav");
  (*DAT_001c1024)("debris/glass3.wav");
  (*DAT_001c1024)("misc/r_tele3.wav");
  (*DAT_001c1024)("misc/r_tele4.wav");
  (*DAT_001c1024)("items/medshot4.wav");
  (*DAT_001c1024)("items/medshot5.wav");
  (*DAT_001c1024)("items/r_item2.wav");
  (*DAT_001c1024)("weapons/building.wav");
  (*DAT_001c1024)("weapons/ax1.wav");
  (*DAT_001c1024)("weapons/timer.wav");
  (*DAT_001c1024)("items/itembk2.wav");
  (*DAT_001c1024)("items/flashlight1.wav");
  (*DAT_001c1024)("items/flashlight1.wav");
  (*DAT_001c1024)("common/bodysplat.wav");
  (*DAT_001c1024)("player/pl_pain2.wav");
  (*DAT_001c1024)("player/pl_pain4.wav");
  (*DAT_001c1024)("player/pl_pain5.wav");
  (*DAT_001c1024)("player/pl_pain6.wav");
  (*DAT_001c1024)("player/pl_pain7.wav");
  (*DAT_001c1024)("speech/saveme1.wav");
  (*DAT_001c1024)("speech/saveme2.wav");
  (*DAT_001c1024)("vox/stolen.wav");
  if (sNewClassModelFiles._4_4_ != 0) {
    (*g_engfuncs)(sNewClassModelFiles._4_4_);
  }
  if (sOldClassModelFiles._4_4_ != 0) {
    (*g_engfuncs)(sOldClassModelFiles._4_4_);
  }
  if (sNewClassModelFiles._8_4_ != 0) {
    (*g_engfuncs)(sNewClassModelFiles._8_4_);
  }
  if (sOldClassModelFiles._8_4_ != 0) {
    (*g_engfuncs)(sOldClassModelFiles._8_4_);
  }
  if (sNewClassModelFiles._12_4_ != 0) {
    (*g_engfuncs)(sNewClassModelFiles._12_4_);
  }
  if (sOldClassModelFiles._12_4_ != 0) {
    (*g_engfuncs)(sOldClassModelFiles._12_4_);
  }
  iVar2 = 0x10;
  iVar1 = 4;
  do {
    if (*(int *)(sNewClassModelFiles + iVar2) != 0) {
      (*g_engfuncs)(*(undefined4 *)(sNewClassModelFiles + iVar2));
    }
    if (*(int *)(sOldClassModelFiles + iVar2) != 0) {
      (*g_engfuncs)(*(undefined4 *)(sOldClassModelFiles + iVar2));
    }
    if (*(int *)(sNewClassModelFiles + iVar2 + 4) != 0) {
      (*g_engfuncs)(*(undefined4 *)(sNewClassModelFiles + iVar2 + 4));
    }
    if (*(int *)(sOldClassModelFiles + iVar2 + 4) != 0) {
      (*g_engfuncs)(*(undefined4 *)(sOldClassModelFiles + iVar2 + 4));
    }
    if (*(int *)(sNewClassModelFiles + iVar2 + 8) != 0) {
      (*g_engfuncs)(*(undefined4 *)(sNewClassModelFiles + iVar2 + 8));
    }
    if (*(int *)(sOldClassModelFiles + iVar2 + 8) != 0) {
      (*g_engfuncs)(*(undefined4 *)(sOldClassModelFiles + iVar2 + 8));
    }
    if (*(int *)(sNewClassModelFiles + iVar2 + 0xc) != 0) {
      (*g_engfuncs)(*(undefined4 *)(sNewClassModelFiles + iVar2 + 0xc));
    }
    if (*(int *)(sOldClassModelFiles + iVar2 + 0xc) != 0) {
      (*g_engfuncs)(*(undefined4 *)(sOldClassModelFiles + iVar2 + 0xc));
    }
    iVar2 = iVar2 + 0x10;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0xc);
  iVar1 = 0;
  do {
    (*g_engfuncs)((&sNewWeaponPModels)[iVar1]);
    (*g_engfuncs)((&sOldWeaponPModels)[iVar1]);
    (*g_engfuncs)((&PTR_s_models_p_crowbar_mdl_00159b84)[iVar1]);
    (*g_engfuncs)((&PTR_s_models_p_crowbar2_mdl_00159be4)[iVar1]);
    (*g_engfuncs)((&PTR_s_models_p_egon_mdl_00159b88)[iVar1]);
    (*g_engfuncs)((&PTR_s_models_p_egon2_mdl_00159be8)[iVar1]);
    iVar1 = iVar1 + 3;
  } while (iVar1 < 0x12);
  local_8 = 0xc1700000;
  local_4 = 0xc2440000;
  local_c = 0xc2280000;
  local_14 = 0x41300000;
  local_10 = 0x42440000;
  local_18 = 0x42280000;
  if (sNewClassModelFiles._4_4_ != 0) {
    (*DAT_001c1248)(2,&local_c,&local_18,sNewClassModelFiles._4_4_);
  }
  if (sOldClassModelFiles._4_4_ != 0) {
    (*DAT_001c1248)(2,&local_c,&local_18,sOldClassModelFiles._4_4_);
  }
  iVar2 = 8;
  iVar1 = 2;
  do {
    if (*(int *)(sNewClassModelFiles + iVar2) != 0) {
      (*DAT_001c1248)(2,&local_c,&local_18,*(undefined4 *)(sNewClassModelFiles + iVar2));
    }
    if (*(int *)(sOldClassModelFiles + iVar2) != 0) {
      (*DAT_001c1248)(2,&local_c,&local_18,*(undefined4 *)(sOldClassModelFiles + iVar2));
    }
    if (*(int *)(sNewClassModelFiles + iVar2 + 4) != 0) {
      (*DAT_001c1248)(2,&local_c,&local_18,*(undefined4 *)(sNewClassModelFiles + iVar2 + 4));
    }
    if (*(int *)(sOldClassModelFiles + iVar2 + 4) != 0) {
      (*DAT_001c1248)(2,&local_c,&local_18,*(undefined4 *)(sOldClassModelFiles + iVar2 + 4));
    }
    iVar2 = iVar2 + 8;
    iVar1 = iVar1 + 2;
  } while (iVar1 < 0xc);
  iVar1 = 0;
  do {
    (*DAT_001c1248)(0,0,0,(&sNewWeaponPModels)[iVar1]);
    (*DAT_001c1248)(0,0,0,(&sOldWeaponPModels)[iVar1]);
    (*DAT_001c1248)(0,0,0,(&PTR_s_models_p_crowbar_mdl_00159b84)[iVar1]);
    (*DAT_001c1248)(0,0,0,(&PTR_s_models_p_crowbar2_mdl_00159be4)[iVar1]);
    (*DAT_001c1248)(0,0,0,(&PTR_s_models_p_egon_mdl_00159b88)[iVar1]);
    (*DAT_001c1248)(0,0,0,(&PTR_s_models_p_egon2_mdl_00159be8)[iVar1]);
    iVar1 = iVar1 + 3;
  } while (iVar1 < 0x12);
  (*DAT_001c1248)(0,0,0,"models/w_grenade.mdl");
  (*DAT_001c1248)(0,0,0,"models/spy_grenade.mdl");
  (*DAT_001c1248)(0,0,0,"models/ngrenade.mdl");
  (*DAT_001c1248)(0,0,0,"models/napalm.mdl");
  (*DAT_001c1248)(0,0,0,"models/pipebomb.mdl");
  (*DAT_001c1248)(0,0,0,"models/mirv_grenade.mdl");
  (*DAT_001c1248)(0,0,0,"models/bomblet.mdl");
  (*DAT_001c1248)(0,0,0,"models/emp_grenade.mdl");
  (*DAT_001c1248)(0,0,0,"models/conc_grenade.mdl");
  (*DAT_001c1248)(0,0,0,"models/caltrop.mdl");
  (*DAT_001c1248)(0,0,0,"models/flag.mdl");
  (*DAT_001c1248)(0,0,0,"models/ball.mdl");
  (*DAT_001c1248)(0,0,0,"models/detpack.mdl");
  (*DAT_001c1248)(0,0,0,"models/w_rpg.mdl");
  (*DAT_001c1248)(0,0,0,"models/rpgrocket.mdl");
  local_24 = 0xc2000000;
  local_30 = 0x42000000;
  local_2c = local_30;
  local_28 = local_30;
  local_20 = local_24;
  local_1c = local_24;
  (*DAT_001c1248)(2,&local_24,&local_30,"models/base.mdl");
  local_24 = 0xc1c00000;
  local_20 = local_24;
  local_1c = local_24;
  (*DAT_001c1248)(2,&local_24,&local_30,"models/sentry1.mdl");
  (*DAT_001c1248)(2,&local_24,&local_30,"models/sentry2.mdl");
  (*DAT_001c1248)(2,&local_24,&local_30,"models/sentry3.mdl");
  local_30 = 0x41800000;
  local_2c = 0x42800000;
  local_28 = local_30;
  (*DAT_001c1248)(2,&local_24,&local_30,"models/dispenser.mdl");
  (*DAT_001c1248)(0,0,0,"sprites/playerflame.spr");
  (*DAT_001c1248)(0,0,0,"sprites/fthrow.spr");
  UTIL_PrecacheOther__FPCc("detpack");
  (*DAT_001c1024)("ambience/flameburst1.wav");
  (*DAT_001c1024)("ambience/steamburst1.wav");
  (*DAT_001c1024)("misc/b1.wav");
  (*DAT_001c1024)("misc/b2.wav");
  (*DAT_001c1024)("misc/party1.wav");
  (*DAT_001c1024)("misc/party2.wav");
  (*DAT_001c1024)("common/wpn_hudoff.wav");
  (*DAT_001c1024)("common/wpn_hudon.wav");
  (*DAT_001c1024)("common/wpn_moveselect.wav");
  (*DAT_001c1024)("common/wpn_select.wav");
  (*DAT_001c1024)("common/wpn_denyselect.wav");
  return;
}


