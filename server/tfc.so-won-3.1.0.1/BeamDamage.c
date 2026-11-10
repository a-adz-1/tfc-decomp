// BeamDamage__5CBeamP11TraceResult  @ 000971b4
void BeamDamage__5CBeamP11TraceResult(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  RelinkBeam__5CBeam(param_1);
  fVar1 = *(float *)(param_2 + 0x10);
  if (((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 0x40) ||
     (*(int *)(param_2 + 0x30) == 0)) goto LAB_00097357;
  iVar3 = *(int *)(param_2 + 0x30);
  if (iVar3 == 0) {
    iVar3 = (*DAT_001a7f54)(0);
    if (iVar3 != 0) goto LAB_0009721b;
    iVar3 = 0;
  }
  else {
LAB_0009721b:
    iVar3 = *(int *)(iVar3 + 0x7c);
  }
  if (iVar3 != 0) {
    ClearMultiDamage__Fv();
    fStack_c = *(float *)(param_2 + 0x14) - *(float *)(*param_1 + 8);
    fStack_8 = *(float *)(param_2 + 0x18) - *(float *)(*param_1 + 0xc);
    fVar1 = *(float *)(param_2 + 0x1c) - *(float *)(*param_1 + 0x10);
    fStack_4 = SQRT(fVar1 * fVar1 + fStack_8 * fStack_8 + fStack_c * fStack_c);
    if ((byte)((byte)((ushort)((ushort)NAN(fStack_4) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_4 == 0.0) << 0xe) >> 8)) == 0x40) {
      fStack_c = 0.0;
      fStack_8 = 0.0;
      fStack_4 = 1.0;
    }
    else {
      fStack_4 = 1.0 / fStack_4;
      fStack_c = fStack_4 * fStack_c;
      fStack_8 = fStack_4 * fStack_8;
      fStack_4 = fStack_4 * fVar1;
    }
    iVar2 = *param_1;
    (**(code **)(*(int *)(iVar3 + 0x3d4) + 0x30))
              (iVar3,iVar2,(*gpGlobals - *(float *)(iVar2 + 0x1e4)) * *(float *)(iVar2 + 0x1e0),
               &fStack_c,param_2,0x400);
    ApplyMultiDamage__FP9entvars_sT0(*param_1,*param_1);
    if ((*(byte *)(*param_1 + 0x1a0) & 0x40) != 0) {
      iVar3 = (**(code **)(*(int *)(iVar3 + 0x3d4) + 0x8c))(iVar3);
      if (iVar3 != 0) {
        iVar3 = (*DAT_001a7fa8)(0,4);
        UTIL_DecalTrace__FP11TraceResulti(param_2,iVar3 + 0x1c);
      }
    }
  }
LAB_00097357:
  *(float *)(*param_1 + 0x1e4) = *gpGlobals;
  return;
}


