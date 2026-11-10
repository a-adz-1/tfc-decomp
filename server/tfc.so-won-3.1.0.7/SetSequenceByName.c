// SetSequenceByName__12CBaseMonsterPc  @ 000bbdd0
void SetSequenceByName__12CBaseMonsterPc(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = LookupSequence__14CBaseAnimatingPCc(param_1,param_2);
  if (iVar1 < 0) {
    (*DAT_001c1114)(2,"%s has no sequence named:%f\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98),
                    param_2);
    *(undefined4 *)(*param_1 + 0x128) = 0;
  }
  else {
    if ((*(int *)(*param_1 + 0x128) != iVar1) || (param_1[0x118] == 0)) {
      *(undefined4 *)(*param_1 + 0x130) = 0;
    }
    *(int *)(*param_1 + 0x128) = iVar1;
    ResetSequenceInfo__14CBaseAnimating(param_1);
    (**(code **)(param_1[0x111] + 0x1a8))(param_1);
  }
  return;
}


