// SetTurretAnim__11CBaseTurret11TURRET_ANIM  @ 001151b0
void SetTurretAnim__11CBaseTurret11TURRET_ANIM(int *param_1,int param_2)

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
    if (param_2 == 4) {
      *(undefined4 *)(*param_1 + 0x110) = 0x437f0000;
      *(undefined4 *)(*param_1 + 0x118) = 0xbf800000;
    }
    else if (param_2 == 5) {
      *(undefined4 *)(*param_1 + 0x118) = 0x3f800000;
    }
  }
  return;
}


