// DamageThink__10CLightning  @ 00097374
void DamageThink__10CLightning(int *param_1)

{
  undefined4 uVar1;
  undefined1 local_3c [56];
  float local_4;
  
  local_4 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = local_4;
  uVar1 = GetEndPos__5CBeam(param_1,0,0,local_3c);
  uVar1 = GetStartPos__5CBeam(param_1,uVar1);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult(uVar1);
  BeamDamage__5CBeamP11TraceResult(param_1,local_3c);
  return;
}


