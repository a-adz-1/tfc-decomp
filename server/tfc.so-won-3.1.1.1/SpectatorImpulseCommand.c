// SpectatorImpulseCommand__14CBaseSpectator  @ 000f3368
void SpectatorImpulseCommand__14CBaseSpectator(int *param_1)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = pGoal_426;
  if (*(int *)(*param_1 + 0x184) == 1) {
    bVar3 = false;
    iVar4 = pGoal_426;
    do {
      iVar4 = (*DAT_0019f6d8)(iVar4,"classname","info_player_deathmatch");
      if (iVar4 == iVar1) {
        (*DAT_0019f794)(1,"Could not find a spawn spot.\n");
        goto LAB_000f33f4;
      }
      bVar2 = false;
      if (iVar4 == 0) {
LAB_000f33e4:
        bVar2 = true;
      }
      else {
        iVar5 = (*DAT_0019f7b8)(iVar4);
        if (iVar5 == 0) goto LAB_000f33e4;
      }
    } while (bVar2);
    bVar3 = true;
LAB_000f33f4:
    if (bVar3) {
      pGoal_426 = iVar4;
      UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,iVar4 + 0x88);
      iVar4 = pGoal_426;
      iVar1 = *param_1;
      *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(pGoal_426 + 0xd0);
      *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar4 + 0xd4);
      *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar4 + 0xd8);
      *(undefined4 *)(*param_1 + 0xa0) = 0;
    }
  }
  else {
    (*DAT_0019f794)(1,"Unknown spectator impulse\n");
  }
  *(undefined4 *)(*param_1 + 0x184) = 0;
  return;
}


