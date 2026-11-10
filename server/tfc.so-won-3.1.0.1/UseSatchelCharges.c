// UseSatchelCharges__8CGrenadeP9entvars_sQ28CGrenade11SATCHELCODE  @ 000a7a58
void UseSatchelCharges__8CGrenadeP9entvars_sQ28CGrenade11SATCHELCODE(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x208);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = *(int **)(iVar1 + 0x7c);
    }
    iVar1 = *(int *)(*piVar2 + 0x208);
    piVar3 = (int *)0x0;
    while (piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,"grenade"),
          piVar3 != (int *)0x0) {
      if (((*(byte *)(*piVar3 + 0x1a0) & 1) != 0) && (*(int *)(*piVar3 + 0x198) == iVar1)) {
        if (param_2 == 0) {
          (**(code **)(piVar3[0xf5] + 0xb0))(piVar3,piVar2,piVar2,1,0);
        }
        else {
          *(undefined4 *)(*piVar3 + 0x198) = 0;
        }
      }
    }
  }
  return;
}


