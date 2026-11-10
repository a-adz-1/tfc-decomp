// DisplayLocalItemStatus__11CBasePlayerP11CBaseEntity  @ 00107210
void DisplayLocalItemStatus__11CBasePlayerP11CBaseEntity(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (*(int *)(iVar2 * 4 + param_2 + 0x2b8) != 0) {
      iVar1 = Finditem__Fi(*(undefined4 *)(iVar2 * 4 + param_2 + 0x2b8));
      if (iVar1 == 0) {
        ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Item_missing",0,0,0,0);
      }
      else {
        DisplayItemStatus__FP11CBaseEntityP11CBasePlayerT0(param_2,param_1,iVar1);
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return;
}


