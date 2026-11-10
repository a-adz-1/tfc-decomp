// PlayStepSound__11CBasePlayerif  @ 000d78f4
void PlayStepSound__11CBasePlayerif(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  iVar1 = (**(code **)(*g_pGameRules + 0xd8))(g_pGameRules,param_1,param_3);
  if (iVar1 == 0) {
    return;
  }
  iVar1 = (*DAT_001c1188)(0,1);
  iVar1 = iVar1 + param_1[0x20d] * 2;
  param_1[0x20d] = (uint)(param_1[0x20d] == 0);
  switch(param_2) {
  default:
    switch(iVar1) {
    case 0:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_step1.wav";
      break;
    case 1:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_step3.wav";
      break;
    case 2:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_step2.wav";
      break;
    case 3:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_step4.wav";
      break;
    default:
      goto switchD_000d79aa_default;
    }
    break;
  case 1:
    switch(iVar1) {
    case 0:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_metal1.wav";
      break;
    case 1:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_metal3.wav";
      break;
    case 2:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_metal2.wav";
      break;
    case 3:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_metal4.wav";
      break;
    default:
      goto switchD_000d79aa_default;
    }
    break;
  case 2:
    switch(iVar1) {
    case 0:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_dirt1.wav";
      break;
    case 1:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = (char *)FUN_0014b1ac;
      break;
    case 2:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_dirt2.wav";
      break;
    case 3:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_dirt4.wav";
      break;
    default:
      goto switchD_000d79aa_default;
    }
    break;
  case 3:
    switch(iVar1) {
    case 0:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_duct1.wav";
      break;
    case 1:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_duct3.wav";
      break;
    case 2:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_duct2.wav";
      break;
    case 3:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_duct4.wav";
      break;
    default:
      goto switchD_000d79aa_default;
    }
    break;
  case 4:
    switch(iVar1) {
    case 0:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_grate1.wav";
      break;
    case 1:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_grate3.wav";
      break;
    case 2:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_grate2.wav";
      break;
    case 3:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_grate4.wav";
      break;
    default:
      goto switchD_000d79aa_default;
    }
    break;
  case 5:
    iVar2 = (*DAT_001c1188)(0,4);
    if (iVar2 == 0) {
      iVar1 = 4;
    }
    switch(iVar1) {
    case 0:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_tile1.wav";
      break;
    case 1:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_tile3.wav";
      break;
    case 2:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_tile2.wav";
      break;
    case 3:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_tile4.wav";
      break;
    case 4:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_tile5.wav";
      break;
    default:
      goto switchD_000d79aa_default;
    }
    break;
  case 6:
    switch(iVar1) {
    case 0:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_slosh1.wav";
      break;
    case 1:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_slosh3.wav";
      break;
    case 2:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_slosh2.wav";
      break;
    case 3:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_slosh4.wav";
      break;
    default:
      goto switchD_000d79aa_default;
    }
    break;
  case 7:
    if (iSkipStep_834 == 0) {
      iSkipStep_834 = 1;
      return;
    }
    iSkipStep_834 = iSkipStep_834 + 1;
    if (iSkipStep_834 == 4) {
      iSkipStep_834 = 0;
    }
    switch(iVar1) {
    case 0:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_wade1.wav";
      break;
    case 1:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_wade2.wav";
      break;
    case 2:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_wade3.wav";
      break;
    case 3:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_wade4.wav";
      break;
    default:
      goto switchD_000d79aa_default;
    }
    break;
  case 8:
    switch(iVar1) {
    case 0:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_ladder1.wav";
      break;
    case 1:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_ladder3.wav";
      break;
    case 2:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_ladder2.wav";
      break;
    case 3:
      uVar4 = *(undefined4 *)(*param_1 + 0x208);
      pcVar3 = "player/pl_ladder4.wav";
      break;
    default:
      goto switchD_000d79aa_default;
    }
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar4,4,pcVar3,param_3,0x3f4ccccd,0,100);
switchD_000d79aa_default:
  return;
}


