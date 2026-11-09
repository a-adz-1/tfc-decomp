// FacingIdeal__12CBaseMonster  @ 000c79f0
bool FacingIdeal__12CBaseMonster(undefined4 param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)FlYawDiff__12CBaseMonster(param_1);
  return ABS(lVar1) <= (longdouble)0.006;
}


