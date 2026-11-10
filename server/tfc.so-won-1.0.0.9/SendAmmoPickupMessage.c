// SendAmmoPickupMessage__FP9entvars_tPci  @ 000de210
void SendAmmoPickupMessage__FP9entvars_tPci(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (0 < param_3) {
    (*DAT_00175578)(1,gmsgAmmoPickup,0,*(undefined4 *)(param_1 + 0x1e8));
    uVar1 = GetAmmoIndex__11CBasePlayerPCc(param_2);
    (*DAT_00175580)(uVar1);
    (*DAT_00175580)(param_3);
    (*DAT_0017557c)();
  }
  return;
}


