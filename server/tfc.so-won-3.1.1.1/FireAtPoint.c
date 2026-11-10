// FireAtPoint__6CLaserR11TraceResult  @ 000a4b50
void FireAtPoint__6CLaserR11TraceResult(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(param_2 + 0x1c);
  if ((undefined4 *)param_1[0x116] != (undefined4 *)0x0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*(undefined4 *)param_1[0x116],param_2 + 0x14);
  }
  BeamDamage__5CBeamP11TraceResult(param_1,param_2);
  iVar2 = *param_1;
  if ((*(uint *)(iVar2 + 0x148) & 0xf) == 2) {
    iVar1 = (*DAT_0019f7c0)(*(uint *)(iVar2 + 0x128) & 0xfff);
    iVar1 = iVar1 + 0x88;
    iVar2 = *param_1;
  }
  else {
    iVar1 = iVar2 + 8;
  }
  if ((*(uint *)(iVar2 + 0x1a0) & 0x30) != 0) {
    if ((*(uint *)(iVar2 + 0x1a0) & 0x10) != 0) {
      UTIL_Sparks__FRC6Vector(iVar1);
      iVar2 = *param_1;
    }
    if ((*(byte *)(iVar2 + 0x1a0) & 0x20) != 0) {
      UTIL_Sparks__FRC6Vector(param_2 + 0x14);
    }
  }
  return;
}


