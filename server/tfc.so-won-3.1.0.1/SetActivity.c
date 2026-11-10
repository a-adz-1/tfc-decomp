// SetActivity__12CBaseMonster8Activity  @ 000b0aa4
void SetActivity__12CBaseMonster8Activity(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,param_2);
  if (iVar1 < 0) {
    (*DAT_001a7f34)(2,"%s has no sequence for act:%d\n",
                    *(int *)*param_1 + *(int *)(gpGlobals + 0x98),param_2);
    *(undefined4 *)(*param_1 + 0x128) = 0;
  }
  else {
    if (((*(int *)(*param_1 + 0x128) != iVar1) || (param_1[0xfc] == 0)) &&
       ((1 < param_1[0x13a] - 3U || (1 < param_2 - 3U)))) {
      *(undefined4 *)(*param_1 + 0x130) = 0;
    }
    *(int *)(*param_1 + 0x128) = iVar1;
    ResetSequenceInfo__14CBaseAnimating(param_1);
    (**(code **)(param_1[0xf5] + 0x1a0))(param_1);
  }
  param_1[0x13a] = param_2;
  param_1[0x13b] = param_2;
  return;
}


// SetActivity__12CTalkMonster8Activity  @ 000e7ca0
void SetActivity__12CTalkMonster8Activity(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 1) {
    iVar1 = IsTalking__12CTalkMonster(param_1);
    if (iVar1 != 0) {
      param_2 = 0x17;
    }
  }
  if (param_2 == 0x17) {
    iVar1 = LookupActivity__14CBaseAnimatingi(param_1,0x17);
    if (iVar1 == -1) {
      param_2 = 1;
    }
  }
  SetActivity__12CBaseMonster8Activity(param_1,param_2);
  return;
}


// SetActivity__13CActAnimating8Activity  @ 00114330
void SetActivity__13CActAnimating8Activity(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,param_2);
  if (iVar1 != -1) {
    *(int *)(*param_1 + 0x128) = iVar1;
    param_1[0xfd] = param_2;
    *(undefined4 *)(*param_1 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  return;
}


