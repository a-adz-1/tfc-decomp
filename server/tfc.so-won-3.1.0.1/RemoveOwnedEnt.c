// RemoveOwnedEnt__11CBasePlayerPc  @ 000d6638
void RemoveOwnedEnt__11CBasePlayerPc(int *param_1,undefined4 param_2)

{
  byte *pbVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  while (piVar2 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar2,param_2),
        piVar2 != (int *)0x0) {
    if (*(int *)(*piVar2 + 0x198) == *(int *)(*param_1 + 0x208)) {
      pbVar1 = (byte *)(*piVar2 + 0x1a7);
      *pbVar1 = *pbVar1 | 0x40;
    }
  }
  return;
}


