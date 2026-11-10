// SetActivity__12CBaseMonster8Activity  @ 000c25d0
void SetActivity__12CBaseMonster8Activity(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,param_2);
  if (iVar1 < 0) {
    (*DAT_0019f794)(2,FUN_0014dc60,*(int *)*param_1 + *(int *)(gpGlobals + 0x98),param_2);
    *(undefined4 *)(*param_1 + 0x128) = 0;
  }
  else {
    iVar2 = *param_1;
    if (((*(int *)(iVar2 + 0x128) != iVar1) || (param_1[0x11c] == 0)) &&
       ((1 < param_1[0x15a] - 3U || (1 < param_2 - 3U)))) {
      *(undefined4 *)(iVar2 + 0x130) = 0;
      iVar2 = *param_1;
    }
    *(int *)(iVar2 + 0x128) = iVar1;
    ResetSequenceInfo__14CBaseAnimating(param_1);
    (**(code **)(param_1[0x115] + 0x1a8))(param_1);
  }
  param_1[0x15a] = param_2;
  param_1[0x15b] = param_2;
  return;
}


// SetActivity__12CTalkMonster8Activity  @ 000f91b8
void SetActivity__12CTalkMonster8Activity(void)

{
  FUN_000f91c3();
  return;
}


// SetActivity__13CActAnimating8Activity  @ 00129cec
void SetActivity__13CActAnimating8Activity(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,param_2);
  if (iVar1 != -1) {
    *(int *)(*param_1 + 0x128) = iVar1;
    param_1[0x11d] = param_2;
    *(undefined4 *)(*param_1 + 0x130) = 0;
    ResetSequenceInfo__14CBaseAnimating(param_1);
  }
  return;
}


