// Bench_FindSpot__Fi  @ 00088a64
int * Bench_FindSpot__Fi(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  do {
    piVar1 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar1,"trigger_camera");
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
  } while ((int)ROUND(*(float *)(*piVar1 + 0x1f8)) != param_1);
  return piVar1;
}


// Bench_StopTrain__Fv  @ 000c32e0
void Bench_StopTrain__Fv(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (*DAT_001a7e78)(0,"targetname","slider");
  if (iVar1 != 0) {
    piVar2 = (int *)GetClassPtr__H1Z10CFuncTrain_PX01_PX01(iVar1 + 0x80);
    if (piVar2 != (int *)0x0) {
      *(byte *)(*piVar2 + 0x118) = *(byte *)(*piVar2 + 0x118) | 0x20;
      *(undefined4 *)(*piVar2 + 0x108) = 0;
      iVar1 = *piVar2;
      *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
      *(undefined4 *)(iVar1 + 0x24) = DAT_001a7e04;
      *(undefined4 *)(iVar1 + 0x28) = DAT_001a7e08;
      *(undefined4 *)(*piVar2 + 0x1f8) = 0;
      *(float *)(*piVar2 + 0x104) = *gpGlobals + 0.1;
      piVar2[3] = 0;
      piVar2[4] = 0;
    }
  }
  return;
}


