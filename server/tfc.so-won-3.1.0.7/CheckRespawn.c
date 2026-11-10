// CheckRespawn__15CBasePlayerItem  @ 0011fc58
void CheckRespawn__15CBasePlayerItem(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*g_pGameRules + 0x84))(g_pGameRules,param_1);
  if (iVar1 == 1) {
    (**(code **)(*(int *)(param_1 + 0x444) + 0xc0))(param_1);
  }
  return;
}


