// DestroyBuilding__FP11CBaseEntityPc  @ 000a6d80
void DestroyBuilding__FP11CBaseEntityPc(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  while (piVar2 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar2,param_2),
        piVar2 != (int *)0x0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(piVar2 + 0x51);
    if (iVar1 == param_1) {
      iVar1 = UTIL_PointContents__FRC6Vector(*piVar2 + 8);
      if ((iVar1 == -2) || (iVar1 == -6)) {
        *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 100;
        TeamFortress_CheckClassStats__11CBasePlayer(param_1);
      }
      (**(code **)(piVar2[0x115] + 0x38))(piVar2,*piVar2,*piVar2,0x43fa0000,0);
    }
  }
  return;
}


