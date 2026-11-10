// StartSequence__12CCineMonsterP12CBaseMonsterii  @ 000eb4a4
undefined4
StartSequence__12CCineMonsterP12CBaseMonsterii
          (undefined4 param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_3 == 0) && (param_4 != 0)) {
    SequenceDone__12CCineMonsterP12CBaseMonster(param_1,param_2);
    uVar1 = 0;
  }
  else {
    uVar1 = LookupSequence__14CBaseAnimatingPCc(param_2,param_3 + *(int *)(gpGlobals + 0x98));
    *(undefined4 *)(*param_2 + 0x128) = uVar1;
    iVar2 = *param_2;
    if (*(int *)(iVar2 + 0x128) == -1) {
      (*DAT_0019f794)(4,"%s: unknown scripted sequence \"%s\"\n",
                      *(int *)(iVar2 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                      param_3 + *(int *)(gpGlobals + 0x98));
      *(undefined4 *)(*param_2 + 0x128) = 0;
      iVar2 = *param_2;
    }
    *(undefined4 *)(iVar2 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_2);
    uVar1 = 1;
  }
  return uVar1;
}


// StartSequence__7CCineAIP12CBaseMonsterii  @ 000eb3d0
undefined4
StartSequence__7CCineAIP12CBaseMonsterii(undefined4 param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_3 == 0) && (param_4 != 0)) {
    SequenceDone__12CCineMonsterP12CBaseMonster(param_1,param_2);
  }
  else {
    uVar1 = LookupSequence__14CBaseAnimatingPCc(param_2,param_3 + *(int *)(gpGlobals + 0x98));
    *(undefined4 *)(*param_2 + 0x128) = uVar1;
    iVar2 = *param_2;
    if (*(int *)(iVar2 + 0x128) == -1) {
      (*DAT_0019f794)(4,"%s: unknown aiscripted sequence \"%s\"\n",
                      *(int *)(iVar2 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                      param_3 + *(int *)(gpGlobals + 0x98));
      *(undefined4 *)(*param_2 + 0x128) = 0;
      iVar2 = *param_2;
    }
    *(undefined4 *)(iVar2 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_2);
  }
  return 1;
}


