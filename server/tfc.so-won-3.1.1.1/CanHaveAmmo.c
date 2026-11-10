// CanHaveAmmo__10CGameRulesP11CBasePlayerPCci  @ 000b01d4
undefined4
CanHaveAmmo__10CGameRulesP11CBasePlayerPCci
          (undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (((param_3 != 0) && (iVar1 = GetAmmoIndex__11CBasePlayerPCc(param_3), -1 < iVar1)) &&
     (iVar1 = AmmoInventory__11CBasePlayeri(param_2,iVar1), iVar1 < param_4)) {
    return 1;
  }
  return 0;
}


