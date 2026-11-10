// RemoveOldAmmobox__11CBasePlayer  @ 001085ac
void RemoveOldAmmobox__11CBasePlayer(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  piVar2 = (int *)0x0;
  while (piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,"tf_ammobox"),
        piVar3 != (int *)0x0) {
    iVar1 = *(int *)(*piVar3 + 400);
    if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x7c);
    }
    if ((iVar1 == param_1) &&
       ((piVar2 == (int *)0x0 || ((float)piVar3[0x11d] < (float)piVar2[0x11d])))) {
      piVar2 = piVar3;
    }
  }
  if (piVar2 != (int *)0x0) {
    *(undefined4 *)(*piVar2 + 0x104) = *gpGlobals;
  }
  return;
}


