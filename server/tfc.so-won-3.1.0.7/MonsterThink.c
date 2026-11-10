// MonsterThink__12CBaseMonster  @ 000ba5b0
void MonsterThink__12CBaseMonster(int *param_1)

{
  int iVar1;
  longdouble lVar2;
  
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  (**(code **)(param_1[0x111] + 0x110))(param_1);
  lVar2 = (longdouble)StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  if ((((param_1[0x159] != 6) && (param_1[0x159] != 8)) && (param_1[0x156] == 1)) &&
     (param_1[0x117] != 0)) {
    if (param_1[0x118] == 0) {
      iVar1 = LookupActivityHeaviest__14CBaseAnimatingi(param_1,param_1[0x156]);
    }
    else {
      iVar1 = LookupActivity__14CBaseAnimatingi(param_1,1);
    }
    if (iVar1 != -1) {
      *(int *)(*param_1 + 0x128) = iVar1;
      ResetSequenceInfo__14CBaseAnimating(param_1);
    }
  }
  DispatchAnimEvents__14CBaseAnimatingf(param_1,(float)lVar2);
  if (param_1[0x17e] != 0) {
    (**(code **)(param_1[0x111] + 0x144))(param_1,(float)lVar2);
  }
  return;
}


