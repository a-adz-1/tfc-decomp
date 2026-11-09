// ClassIsRestricted__Ffi  @ 0010e930
undefined4 ClassIsRestricted__Ffi(float param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((byte)(param_1 < 0.0 | (byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1 == 0.0) << 0xe) >> 8)) == 0x40) {
LAB_0010ea8e:
    uVar3 = 0;
  }
  else {
    iVar6 = 0;
    fVar1 = (float)cr_scout._12_4_;
    if ((((((param_2 == 1) || (fVar1 = (float)cr_sniper._12_4_, param_2 == 2)) ||
          (fVar1 = (float)cr_soldier._12_4_, param_2 == 3)) ||
         (((fVar1 = (float)cr_demoman._12_4_, param_2 == 4 ||
           (fVar1 = (float)cr_medic._12_4_, param_2 == 5)) ||
          ((fVar1 = (float)cr_hwguy._12_4_, param_2 == 6 ||
           ((fVar1 = (float)cr_pyro._12_4_, param_2 == 7 ||
            (fVar1 = (float)cr_spy._12_4_, param_2 == 8)))))))) ||
        (fVar1 = (float)cr_engineer._12_4_, param_2 == 9)) ||
       (fVar1 = (float)cr_random._12_4_, param_2 == 10)) {
      iVar6 = (int)ROUND(fVar1);
    }
    if (iVar6 < 1) {
LAB_0010ea89:
      if (iVar6 != -1) goto LAB_0010ea8e;
    }
    else {
      iVar5 = 0;
      for (iVar4 = 1; iVar4 <= *(int *)(gpGlobals + 0x90); iVar4 = iVar4 + 1) {
        iVar2 = UTIL_PlayerByIndex__Fi(iVar4);
        if ((iVar2 != 0) &&
           ((byte)((byte)((ushort)((ushort)(NAN(param_1) || NAN((float)*(int *)(iVar2 + 0x120))) <<
                                  10) >> 8) |
                  (byte)((ushort)((ushort)(param_1 == (float)*(int *)(iVar2 + 0x120)) << 0xe) >> 8))
            == 0x40)) {
          if (param_2 == 10) {
            if ((*(byte *)(iVar2 + 0x88) & 8) != 0) {
LAB_0010ea76:
              iVar5 = iVar5 + 1;
            }
          }
          else if (((*(int *)(iVar2 + 0x2c) == param_2) || (*(int *)(iVar2 + 0x30) == param_2)) &&
                  ((*(byte *)(iVar2 + 0x88) & 8) == 0)) goto LAB_0010ea76;
        }
      }
      if (iVar5 < iVar6) goto LAB_0010ea89;
    }
    uVar3 = 1;
  }
  return uVar3;
}


