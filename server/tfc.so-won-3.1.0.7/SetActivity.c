// SetActivity__12CBaseMonster8Activity  @ 000bbd04
void SetActivity__12CBaseMonster8Activity(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,param_2);
  if (iVar1 < 0) {
    (*DAT_001c1114)(2,"%s has no sequence for act:%d\n",
                    *(int *)*param_1 + *(int *)(gpGlobals + 0x98),param_2);
    *(undefined4 *)(*param_1 + 0x128) = 0;
  }
  else {
    if (((*(int *)(*param_1 + 0x128) != iVar1) || (param_1[0x118] == 0)) &&
       ((1 < param_1[0x156] - 3U || (1 < param_2 - 3U)))) {
      *(undefined4 *)(*param_1 + 0x130) = 0;
    }
    *(int *)(*param_1 + 0x128) = iVar1;
    ResetSequenceInfo__14CBaseAnimating(param_1);
    (**(code **)(param_1[0x111] + 0x1a8))(param_1);
  }
  param_1[0x156] = param_2;
  param_1[0x157] = param_2;
  return;
}


// SetActivity__12CTalkMonster8Activity  @ 000f4974
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


// SetActivity__13CActAnimating8Activity  @ 00123f28
void SetActivity__13CActAnimating8Activity(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,param_2);
  if (iVar1 != -1) {
    *(int *)(*param_1 + 0x128) = iVar1;
    param_1[0x119] = param_2;
    *(undefined4 *)(*param_1 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  return;
}


