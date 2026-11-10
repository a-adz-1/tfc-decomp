// DefaultTouch__15CBasePlayerAmmoP11CBaseEntity  @ 001111b0
void DefaultTouch__15CBasePlayerAmmoP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    iVar1 = (**(code **)(param_1[0xf5] + 0x100))(param_1,param_2);
    if (iVar1 == 0) {
      if (gEvilImpulse101 == 0) {
        return;
      }
    }
    else {
      iVar1 = (**(code **)(*g_pGameRules + 0xb0))(g_pGameRules,param_1);
      if (iVar1 == 3) {
        (**(code **)(param_1[0xf5] + 0xb8))(param_1);
        return;
      }
    }
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// DefaultTouch__15CBasePlayerItemP11CBaseEntity  @ 0011024c
void DefaultTouch__15CBasePlayerItemP11CBaseEntity(void)

{
  FUN_00110255();
  return;
}


