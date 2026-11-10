// SpectatorImpulseCommand__14CBaseSpectator  @ 000f1010
void SpectatorImpulseCommand__14CBaseSpectator(int *param_1)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = pGoal_426;
  if (*(int *)(*param_1 + 0x184) == 1) {
    bVar2 = false;
    iVar4 = pGoal_426;
    do {
      iVar4 = (*DAT_001c1058)(iVar4,"classname","info_player_deathmatch");
      if (iVar4 == iVar1) {
        (*DAT_001c1114)(1,"Could not find a spawn spot.\n");
        goto LAB_000f10a3;
      }
      bVar3 = false;
      if ((iVar4 == 0) || (iVar5 = (*DAT_001c1138)(iVar4), iVar5 == 0)) {
        bVar3 = true;
      }
    } while (bVar3);
    bVar2 = true;
LAB_000f10a3:
    if (bVar2) {
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
    (*DAT_001c1114)(1,"Unknown spectator impulse\n");
  }
  *(undefined4 *)(*param_1 + 0x184) = 0;
  return;
}


