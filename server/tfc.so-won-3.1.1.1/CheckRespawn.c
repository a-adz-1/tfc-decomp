// CheckRespawn__15CBasePlayerItem  @ 00125e20
void CheckRespawn__15CBasePlayerItem(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x84))(g_pGameRules,param_1);
  if (iVar1 == 1) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0xc0))(param_1);
  }
  return;
}


