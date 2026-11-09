// CorpseFallThink__12CBaseMonster  @ 000c7d20
void CorpseFallThink__12CBaseMonster(int *param_1)

{
  if ((*(byte *)(*param_1 + 0x185) & 2) == 0) {
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  else {
    param_1[3] = 0;
    param_1[4] = 0;
    SetSequenceBox__FP12CBaseMonster(param_1);
    UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  }
  return;
}


