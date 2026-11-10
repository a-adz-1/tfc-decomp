// SendAmmoPickupMessage__FP9entvars_sPci  @ 000d0e10
void SendAmmoPickupMessage__FP9entvars_sPci(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (0 < param_3) {
    (*DAT_001a7ef8)(1,gmsgAmmoPickup,0,*(undefined4 *)(param_1 + 0x208));
    uVar1 = GetAmmoIndex__11CBasePlayerPCc(param_2);
    (*DAT_001a7f00)(uVar1);
    (*DAT_001a7f00)(param_3);
    (*DAT_001a7efc)();
  }
  return;
}


