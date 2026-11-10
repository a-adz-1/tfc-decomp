// BeamDamageInstant__5CBeamP11TraceResultf  @ 000a5b44
void BeamDamageInstant__5CBeamP11TraceResultf(int *param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(*param_1 + 0x1e0) = param_3;
  *(float *)(*param_1 + 0x1e4) = *gpGlobals - 1.0;
  BeamDamage__5CBeamP11TraceResult(param_1,param_2);
  return;
}


