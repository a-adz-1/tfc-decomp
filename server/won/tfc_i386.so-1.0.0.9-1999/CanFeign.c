// CanFeign__11CBasePlayer  @ 000ee7c0
undefined4 CanFeign__11CBasePlayer(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  do {
    piVar2 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                              (piVar2,*param_1 + 8,0x42800000);
    if (piVar2 == (int *)0x0) {
      return 1;
    }
  } while (((((*(byte *)(*piVar2 + 0x184) & 8) == 0) ||
            (iVar1 = (**(code **)(piVar2[0xf2] + 0x88))(piVar2), iVar1 == 0)) || (piVar2 == param_1)
           ) && (iVar1 = (**(code **)(piVar2[0xf2] + 0x28))(piVar2), iVar1 != 1));
  return 0;
}


