// DamageThink__10CLightning  @ 000acb70
void DamageThink__10CLightning(int *param_1)

{
  undefined4 uVar1;
  undefined1 local_40 [56];
  float local_8;
  
  local_8 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0xe4) = local_8;
  uVar1 = GetEndPos__5CBeam(param_1,0,0,local_40);
  uVar1 = GetStartPos__5CBeam(param_1,uVar1);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult(uVar1);
  BeamDamage__5CBeamP11TraceResult(param_1,local_40);
  return;
}


