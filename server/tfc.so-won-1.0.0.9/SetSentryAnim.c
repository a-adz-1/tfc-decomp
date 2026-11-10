// SetSentryAnim__12CTFSentrygun13TFTURRET_ANIM  @ 000e96b0
void SetSentryAnim__12CTFSentrygun13TFTURRET_ANIM(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x108) != param_2) {
    if ((param_2 < 3) && (0 < param_2)) {
      if (1 < *(int *)(iVar1 + 0x108) - 1U) {
        *(undefined4 *)(iVar1 + 0x110) = 0;
      }
    }
    else {
      *(undefined4 *)(*param_1 + 0x110) = 0;
    }
    *(int *)(*param_1 + 0x108) = param_2;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  return;
}


