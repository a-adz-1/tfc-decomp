// MonsterThink__12CBaseMonster  @ 000c1860
void MonsterThink__12CBaseMonster(int *param_1)

{
  int iVar1;
  longdouble lVar2;
  
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  (**(code **)(param_1[0xf2] + 0x108))(param_1);
  lVar2 = (longdouble)StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  if ((((param_1[0x13a] != 6) && (param_1[0x13a] != 8)) && (param_1[0x137] == 1)) &&
     (param_1[0xf8] != 0)) {
    if (param_1[0xf9] == 0) {
      iVar1 = LookupActivityHeaviest__14CBaseAnimatingi(param_1,param_1[0x137]);
    }
    else {
      iVar1 = LookupActivity__14CBaseAnimatingi(param_1,1);
    }
    if (iVar1 != -1) {
      *(int *)(*param_1 + 0x108) = iVar1;
      ResetSequenceInfo__14CBaseAnimating(param_1);
    }
  }
  DispatchAnimEvents__14CBaseAnimatingf(param_1,(float)lVar2);
  if (param_1[0x15f] != 0) {
    (**(code **)(param_1[0xf2] + 0x13c))(param_1,(float)lVar2);
  }
  return;
}


