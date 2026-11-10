// SpectatorImpulseCommand__14CBaseSpectator  @ 000ee5f0
void SpectatorImpulseCommand__14CBaseSpectator(int *param_1)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = pGoal_424;
  if (*(int *)(*param_1 + 0x164) == 1) {
    bVar3 = false;
    iVar4 = pGoal_424;
    do {
      iVar4 = (*DAT_001754f8)(iVar4,"classname","info_player_deathmatch");
      if (iVar4 == iVar1) {
        (*DAT_001755b4)(1,"Could not find a spawn spot.\n");
        goto LAB_000ee65d;
      }
      bVar2 = false;
      if (iVar4 == 0) {
LAB_000ee64d:
        bVar2 = true;
      }
      else {
        iVar5 = (*DAT_001755d8)(iVar4);
        if (iVar5 == 0) goto LAB_000ee64d;
      }
    } while (bVar2);
    bVar3 = true;
LAB_000ee65d:
    if (bVar3) {
      pGoal_424 = iVar4;
      UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,iVar4 + 0xe4);
      iVar4 = pGoal_424;
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(pGoal_424 + 300);
      *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar4 + 0x130);
      *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar4 + 0x134);
      *(undefined4 *)(*param_1 + 0x80) = 0;
    }
  }
  else {
    (*DAT_001755b4)(1,"Unknown spectator impulse\n");
  }
  *(undefined4 *)(*param_1 + 0x164) = 0;
  return;
}


