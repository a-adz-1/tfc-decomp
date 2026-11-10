// UseSatchelCharges__8CGrenadeP9entvars_tQ28CGrenade11SATCHELCODE  @ 000b9fe0
void UseSatchelCharges__8CGrenadeP9entvars_tQ28CGrenade11SATCHELCODE(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x1e8);
    if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = *(int **)(iVar1 + 0xd8);
    }
    iVar1 = *(int *)(*piVar2 + 0x1e8);
    piVar3 = (int *)0x0;
    while (piVar3 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar3,"grenade"),
          piVar3 != (int *)0x0) {
      if (((*(byte *)(*piVar3 + 0x180) & 1) != 0) && (*(int *)(*piVar3 + 0x178) == iVar1)) {
        if (param_2 == 0) {
          (**(code **)(piVar3[0xf2] + 0xb0))(piVar3,piVar2,piVar2,1,0);
        }
        else {
          *(undefined4 *)(*piVar3 + 0x178) = 0;
        }
      }
    }
  }
  return;
}


