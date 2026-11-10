// FireAtPoint__6CLaserR11TraceResult  @ 00098744
void FireAtPoint__6CLaserR11TraceResult(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(param_2 + 0x1c);
  if (param_1[0xf6] != 0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*(undefined4 *)param_1[0xf6],param_2 + 0x14);
  }
  BeamDamage__5CBeamP11TraceResult(param_1,param_2);
  uVar2 = GetStartPos__5CBeam(param_1,param_2 + 0x14);
  DoSparks__5CBeamRC6VectorT1(param_1,uVar2);
  return;
}


