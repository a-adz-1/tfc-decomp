// ClassIsRestricted__Ffi  @ 00100b48
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ClassIsRestricted__Ffi(float param_1,int param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((byte)(param_1 < _FUN_00141730 |
             (byte)((ushort)((ushort)(NAN(param_1) || NAN(_FUN_00141730)) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1 == _FUN_00141730) << 0xe) >> 8)) == 0x40) {
LAB_00100cb7:
    uVar3 = 0;
  }
  else {
    iVar4 = 0;
    if (param_2 == 1) {
      puVar1 = cr_scout;
LAB_00100c19:
      iVar4 = (int)ROUND(*(float *)(puVar1 + 0xc));
    }
    else {
      if (param_2 == 2) {
        puVar1 = cr_sniper;
        goto LAB_00100c19;
      }
      if (param_2 == 3) {
        puVar1 = cr_soldier;
        goto LAB_00100c19;
      }
      if (param_2 == 4) {
        puVar1 = cr_demoman;
        goto LAB_00100c19;
      }
      if (param_2 == 5) {
        puVar1 = cr_medic;
        goto LAB_00100c19;
      }
      if (param_2 == 6) {
        puVar1 = cr_hwguy;
        goto LAB_00100c19;
      }
      if (param_2 == 7) {
        puVar1 = cr_pyro;
        goto LAB_00100c19;
      }
      if (param_2 == 8) {
        puVar1 = cr_spy;
        goto LAB_00100c19;
      }
      if (param_2 == 9) {
        puVar1 = cr_engineer;
        goto LAB_00100c19;
      }
      if (param_2 == 10) {
        puVar1 = cr_random;
        goto LAB_00100c19;
      }
    }
    if (iVar4 < 1) {
LAB_00100cb2:
      if (iVar4 != -1) goto LAB_00100cb7;
    }
    else {
      iVar6 = 0;
      for (iVar5 = 1; iVar5 <= *(int *)(gpGlobals + 0x90); iVar5 = iVar5 + 1) {
        piVar2 = (int *)UTIL_PlayerByIndex__Fi(iVar5);
        if ((piVar2 != (int *)0x0) &&
           ((byte)((byte)((ushort)((ushort)(NAN(param_1) || NAN((float)piVar2[0x48])) << 10) >> 8) |
                  (byte)((ushort)((ushort)(param_1 == (float)piVar2[0x48]) << 0xe) >> 8)) == 0x40))
        {
          if (param_2 == 10) {
            if ((*(byte *)(piVar2 + 0x21) & 8) != 0) {
LAB_00100c9c:
              iVar6 = iVar6 + 1;
            }
          }
          else if (((*(int *)(*piVar2 + 0x20c) == param_2) || (piVar2[0xb] == param_2)) &&
                  ((*(byte *)(piVar2 + 0x21) & 8) == 0)) goto LAB_00100c9c;
        }
      }
      if (iVar6 < iVar4) goto LAB_00100cb2;
    }
    uVar3 = 1;
  }
  return uVar3;
}


