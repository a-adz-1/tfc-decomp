// SetSentryAnim__12CTFSentrygun13TFTURRET_ANIM  @ 000eeeb0
void SetSentryAnim__12CTFSentrygun13TFTURRET_ANIM(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x128) == param_2) {
    return;
  }
  if ((param_2 < 3) && (0 < param_2)) {
    if (*(int *)(iVar1 + 0x128) - 1U < 2) goto LAB_000eef00;
    *(undefined4 *)(iVar1 + 0x130) = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 0x130) = 0;
  }
  iVar1 = *param_1;
LAB_000eef00:
  *(int *)(iVar1 + 0x128) = param_2;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  return;
}


