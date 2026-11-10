// PlayStepSound__11CBasePlayerif  @ 000d7250
void PlayStepSound__11CBasePlayerif(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  bool bVar4;
  int local_18;
  
  iVar1 = (**(code **)(*g_pGameRules + 0xd8))(g_pGameRules,param_1,param_3);
  if (iVar1 == 0) {
    return;
  }
  local_18 = (*DAT_0019f808)(0,1);
  local_18 = local_18 + param_1[0x217] * 2;
  param_1[0x217] = (uint)(param_1[0x217] == 0);
  switch(param_2) {
  default:
    switch(local_18) {
    case 0:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_step1.wav";
      break;
    case 1:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_step3.wav";
      break;
    case 2:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_step2.wav";
      break;
    case 3:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_step4.wav";
      break;
    default:
      goto switchD_000d7326_default;
    }
    break;
  case 1:
    switch(local_18) {
    case 0:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_metal1.wav";
      break;
    case 1:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_metal3.wav";
      break;
    case 2:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_metal2.wav";
      break;
    case 3:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_metal4.wav";
      break;
    default:
      goto switchD_000d7326_default;
    }
    break;
  case 2:
    switch(local_18) {
    case 0:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_dirt1.wav";
      break;
    case 1:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_dirt3.wav";
      break;
    case 2:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_dirt2.wav";
      break;
    case 3:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_dirt4.wav";
      break;
    default:
      goto switchD_000d7326_default;
    }
    break;
  case 3:
    switch(local_18) {
    case 0:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_duct1.wav";
      break;
    case 1:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_duct3.wav";
      break;
    case 2:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_duct2.wav";
      break;
    case 3:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_duct4.wav";
      break;
    default:
      goto switchD_000d7326_default;
    }
    break;
  case 4:
    switch(local_18) {
    case 0:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_grate1.wav";
      break;
    case 1:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_grate3.wav";
      break;
    case 2:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_grate2.wav";
      break;
    case 3:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_grate4.wav";
      break;
    default:
      goto switchD_000d7326_default;
    }
    break;
  case 5:
    iVar1 = (*DAT_0019f808)(0,4);
    if (iVar1 == 0) {
      local_18 = 4;
    }
    switch(local_18) {
    case 0:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_tile1.wav";
      break;
    case 1:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = (char *)FUN_001505a8;
      break;
    case 2:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_tile2.wav";
      break;
    case 3:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_tile4.wav";
      break;
    case 4:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_tile5.wav";
      break;
    default:
      goto switchD_000d7326_default;
    }
    break;
  case 6:
    switch(local_18) {
    case 0:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_slosh1.wav";
      break;
    case 1:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_slosh3.wav";
      break;
    case 2:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_slosh2.wav";
      break;
    case 3:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_slosh4.wav";
      break;
    default:
      goto switchD_000d7326_default;
    }
    break;
  case 7:
    if (iSkipStep_836 == 0) {
      iSkipStep_836 = 1;
      return;
    }
    bVar4 = iSkipStep_836 == 3;
    iSkipStep_836 = iSkipStep_836 + 1;
    if (bVar4) {
      iSkipStep_836 = 0;
    }
    switch(local_18) {
    case 0:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_wade1.wav";
      break;
    case 1:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_wade2.wav";
      break;
    case 2:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_wade3.wav";
      break;
    case 3:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_wade4.wav";
      break;
    default:
      goto switchD_000d7326_default;
    }
    break;
  case 8:
    switch(local_18) {
    case 0:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_ladder1.wav";
      break;
    case 1:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_ladder3.wav";
      break;
    case 2:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_ladder2.wav";
      break;
    case 3:
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/pl_ladder4.wav";
      break;
    default:
      goto switchD_000d7326_default;
    }
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar3,4,pcVar2,param_3,0x3f4ccccd,0,100);
switchD_000d7326_default:
  return;
}


