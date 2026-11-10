// UseSatchelCharges__8CGrenadeP9entvars_sQ28CGrenade11SATCHELCODE  @ 000b1a90
void UseSatchelCharges__8CGrenadeP9entvars_sQ28CGrenade11SATCHELCODE(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x208);
    if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(iVar2 + 0x7c);
    }
    iVar2 = *(int *)(*piVar3 + 0x208);
    piVar4 = (int *)0x0;
    while (piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"grenade"),
          piVar4 != (int *)0x0) {
      iVar1 = *piVar4;
      if (((*(byte *)(iVar1 + 0x1a0) & 1) != 0) && (*(int *)(iVar1 + 0x198) == iVar2)) {
        if (param_2 == 0) {
          (**(code **)(piVar4[0x115] + 0xb8))(piVar4,piVar3,piVar3,1,0);
        }
        else {
          *(undefined4 *)(iVar1 + 0x198) = 0;
        }
      }
    }
  }
  return;
}


