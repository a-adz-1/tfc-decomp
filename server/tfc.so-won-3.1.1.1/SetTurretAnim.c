// SetTurretAnim__11CBaseTurret11TURRET_ANIM  @ 0011ce6c
void SetTurretAnim__11CBaseTurret11TURRET_ANIM(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x128) == param_2) {
    return;
  }
  if ((param_2 < 3) && (0 < param_2)) {
    if (*(int *)(iVar1 + 0x128) - 1U < 2) goto LAB_0011cebc;
    *(undefined4 *)(iVar1 + 0x130) = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 0x130) = 0;
  }
  iVar1 = *param_1;
LAB_0011cebc:
  *(int *)(iVar1 + 0x128) = param_2;
  ResetSequenceInfo__14CBaseAnimating(param_1);
  if (param_2 == 4) {
    *(undefined4 *)(*param_1 + 0x130) = 0x437f0000;
    *(undefined4 *)(*param_1 + 0x138) = 0xbf800000;
  }
  else if (param_2 == 5) {
    *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
  }
  return;
}


