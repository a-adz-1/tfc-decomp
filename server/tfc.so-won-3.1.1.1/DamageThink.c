// DamageThink__10CLightning  @ 000a0830
void DamageThink__10CLightning(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_40 [56];
  float local_8;
  
  local_8 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = local_8;
  iVar3 = *param_1;
  uVar1 = *(uint *)(iVar3 + 0x148) & 0xf;
  if ((uVar1 != 0) && (uVar1 != 3)) {
    iVar2 = (*DAT_0019f7c0)(*(uint *)(iVar3 + 0x110) & 0xfff,0,0,local_40);
    if (iVar2 != 0) {
      iVar2 = iVar2 + 0x88;
      iVar3 = *param_1;
      goto LAB_000a08b1;
    }
    iVar3 = *param_1;
  }
  iVar2 = iVar3 + 0x50;
LAB_000a08b1:
  if ((*(uint *)(iVar3 + 0x148) & 0xf) == 2) {
    iVar3 = (*DAT_0019f7c0)(*(uint *)(iVar3 + 0x128) & 0xfff,iVar2);
    iVar3 = iVar3 + 0x88;
  }
  else {
    iVar3 = iVar3 + 8;
  }
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult(iVar3);
  BeamDamage__5CBeamP11TraceResult(param_1,local_40);
  return;
}


