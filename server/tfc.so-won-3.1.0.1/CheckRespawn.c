// CheckRespawn__15CBasePlayerItem  @ 0011010c
void CheckRespawn__15CBasePlayerItem(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x84))(g_pGameRules,param_1);
  if (iVar1 == 1) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0xb8))(param_1);
  }
  return;
}


