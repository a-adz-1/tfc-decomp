// CorpseFallThink__12CBaseMonster  @ 000c17fc
void CorpseFallThink__12CBaseMonster(int *param_1)

{
  if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  else {
    param_1[3] = 0;
    param_1[4] = 0;
    SetSequenceBox__FP12CBaseMonster(param_1);
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  }
  return;
}


