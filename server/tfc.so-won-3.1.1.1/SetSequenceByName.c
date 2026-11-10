// SetSequenceByName__12CBaseMonsterPc  @ 000c2528
void SetSequenceByName__12CBaseMonsterPc(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = LookupSequence__14CBaseAnimatingPCc(param_1,param_2);
  if (iVar1 < 0) {
    (*DAT_0019f794)(2,"%s has no sequence named:%f\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98),
                    param_2);
    *(undefined4 *)(*param_1 + 0x128) = 0;
  }
  else {
    iVar2 = *param_1;
    if ((*(int *)(iVar2 + 0x128) != iVar1) || (param_1[0x11c] == 0)) {
      *(undefined4 *)(iVar2 + 0x130) = 0;
      iVar2 = *param_1;
    }
    *(int *)(iVar2 + 0x128) = iVar1;
    ResetSequenceInfo__14CBaseAnimating(param_1);
    (**(code **)(param_1[0x115] + 0x1a8))(param_1);
  }
  return;
}


