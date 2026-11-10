// SendAmmoPickupMessage__FP9entvars_sPci  @ 000e5400
void SendAmmoPickupMessage__FP9entvars_sPci(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (0 < param_3) {
    (*DAT_0019f758)(1,gmsgAmmoPickup,0,*(undefined4 *)(param_1 + 0x208));
    uVar1 = GetAmmoIndex__11CBasePlayerPCc(param_2);
    (*DAT_0019f760)(uVar1);
    (*DAT_0019f760)(param_3);
    (*DAT_0019f75c)();
  }
  return;
}


