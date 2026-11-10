// StartSequence__12CCineMonsterP12CBaseMonsterii  @ 000dc8c8
undefined4
StartSequence__12CCineMonsterP12CBaseMonsterii
          (undefined4 param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_3 == 0) && (param_4 != 0)) {
    SequenceDone__12CCineMonsterP12CBaseMonster(param_1,param_2);
    uVar1 = 0;
  }
  else {
    uVar1 = LookupSequence__14CBaseAnimatingPCc(param_2,*(int *)(gpGlobals + 0x98) + param_3);
    *(undefined4 *)(*param_2 + 0x128) = uVar1;
    if (*(int *)(*param_2 + 0x128) == -1) {
      (*DAT_001a7f34)(4,"%s: unknown scripted sequence \"%s\"\n",
                      *(int *)(*param_2 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                      param_3 + *(int *)(gpGlobals + 0x98));
      *(undefined4 *)(*param_2 + 0x128) = 0;
    }
    *(undefined4 *)(*param_2 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_2);
    uVar1 = 1;
  }
  return uVar1;
}


// StartSequence__7CCineAIP12CBaseMonsterii  @ 000dc994
undefined4
StartSequence__7CCineAIP12CBaseMonsterii(undefined4 param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_3 == 0) && (param_4 != 0)) {
    SequenceDone__12CCineMonsterP12CBaseMonster(param_1,param_2);
  }
  else {
    uVar1 = LookupSequence__14CBaseAnimatingPCc(param_2,*(int *)(gpGlobals + 0x98) + param_3);
    *(undefined4 *)(*param_2 + 0x128) = uVar1;
    if (*(int *)(*param_2 + 0x128) == -1) {
      (*DAT_001a7f34)(4,FUN_0013bf80,*(int *)(*param_2 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                      param_3 + *(int *)(gpGlobals + 0x98));
      *(undefined4 *)(*param_2 + 0x128) = 0;
    }
    *(undefined4 *)(*param_2 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_2);
  }
  return 1;
}


