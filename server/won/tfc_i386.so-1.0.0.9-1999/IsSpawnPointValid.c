// IsSpawnPointValid__FR6Vector  @ 000dc270
undefined4 IsSpawnPointValid__FR6Vector(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  do {
    piVar1 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf(piVar1,param_1,0x42c00000);
    if (piVar1 == (int *)0x0) {
      return 1;
    }
  } while ((*(byte *)(*piVar1 + 0x184) & 8) == 0);
  return 0;
}


