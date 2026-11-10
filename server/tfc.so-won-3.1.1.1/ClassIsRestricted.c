// ClassIsRestricted__Ffi  @ 00113620
undefined4 ClassIsRestricted__Ffi(float param_1,int param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iStack_14;
  
  if ((byte)(param_1 < 0.0 | (byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1 == 0.0) << 0xe) >> 8)) == 0x40) {
LAB_00113798:
    uVar3 = 0;
  }
  else {
    iStack_14 = 0;
    if (param_2 == 1) {
      puVar1 = cr_scout;
LAB_001136f0:
      iStack_14 = (int)ROUND(*(float *)(puVar1 + 0xc));
    }
    else {
      if (param_2 == 2) {
        puVar1 = cr_sniper;
        goto LAB_001136f0;
      }
      if (param_2 == 3) {
        puVar1 = cr_soldier;
        goto LAB_001136f0;
      }
      if (param_2 == 4) {
        puVar1 = cr_demoman;
        goto LAB_001136f0;
      }
      if (param_2 == 5) {
        puVar1 = cr_medic;
        goto LAB_001136f0;
      }
      if (param_2 == 6) {
        puVar1 = cr_hwguy;
        goto LAB_001136f0;
      }
      if (param_2 == 7) {
        puVar1 = cr_pyro;
        goto LAB_001136f0;
      }
      if (param_2 == 8) {
        puVar1 = cr_spy;
        goto LAB_001136f0;
      }
      if (param_2 == 9) {
        puVar1 = cr_engineer;
        goto LAB_001136f0;
      }
      if (param_2 == 10) {
        puVar1 = cr_random;
        goto LAB_001136f0;
      }
    }
    if (iStack_14 < 1) {
LAB_00113792:
      if (iStack_14 != -1) goto LAB_00113798;
    }
    else {
      iVar5 = 0;
      iVar4 = 1;
      if (0 < *(int *)(gpGlobals + 0x90)) {
        do {
          piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar4);
          if ((piVar2 != (int *)0x0) &&
             ((byte)((byte)((ushort)((ushort)(NAN(param_1) || NAN((float)piVar2[0x48])) << 10) >> 8)
                    | (byte)((ushort)((ushort)(param_1 == (float)piVar2[0x48]) << 0xe) >> 8)) ==
              0x40)) {
            if (param_2 == 10) {
              if ((*(byte *)(piVar2 + 0x21) & 8) != 0) {
LAB_0011377b:
                iVar5 = iVar5 + 1;
              }
            }
            else if (((*(int *)(*piVar2 + 0x20c) == param_2) || (piVar2[0xb] == param_2)) &&
                    ((*(byte *)(piVar2 + 0x21) & 8) == 0)) goto LAB_0011377b;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= *(int *)(gpGlobals + 0x90));
      }
      if (iVar5 < iStack_14) goto LAB_00113792;
    }
    uVar3 = 1;
  }
  return uVar3;
}


