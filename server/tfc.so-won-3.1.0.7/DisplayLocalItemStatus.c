// DisplayLocalItemStatus__11CBasePlayerP11CBaseEntity  @ 00105fd0
void DisplayLocalItemStatus__11CBasePlayerP11CBaseEntity(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = (int *)(param_2 + 0x2c0);
  do {
    if (*piVar2 != 0) {
      iVar1 = Finditem__Fi(*piVar2);
      if (iVar1 == 0) {
        ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Item_missing",0,0,0,0);
      }
      else {
        DisplayItemStatus__FP11CBaseEntityP11CBasePlayerT0(param_2,param_1,iVar1);
      }
    }
    if (piVar2[1] != 0) {
      iVar1 = Finditem__Fi(piVar2[1]);
      if (iVar1 == 0) {
        ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Item_missing",0,0,0,0);
      }
      else {
        DisplayItemStatus__FP11CBaseEntityP11CBasePlayerT0(param_2,param_1,iVar1);
      }
    }
    piVar2 = piVar2 + 2;
    iVar3 = iVar3 + 2;
  } while (iVar3 < 4);
  return;
}


