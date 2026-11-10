// FValidateCover__12CBaseMonsterRC6Vector  @ 000c2828
undefined4 FValidateCover__12CBaseMonsterRC6Vector(void)

{
  return 1;
}


// FValidateCover__13CSquadMonsterRC6Vector  @ 000f3238
undefined4 FValidateCover__13CSquadMonsterRC6Vector(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x68c);
  if ((iVar1 != 0) &&
     (iVar1 = SquadMemberInRange__13CSquadMonsterRC6Vectorf(param_1,param_2,0x43000000), iVar1 != 0)
     ) {
    return 0;
  }
  return 1;
}


