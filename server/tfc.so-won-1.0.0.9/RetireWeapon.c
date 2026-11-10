// RetireWeapon__17CBasePlayerWeapon  @ 0011bfd0
void RetireWeapon__17CBasePlayerWeapon(int param_1)

{
  *(undefined4 *)(**(int **)(param_1 + 1000) + 0x9c) = 0;
  *(undefined4 *)(**(int **)(param_1 + 1000) + 0xa0) = 0;
  (**(code **)(*g_pGameRules + 0x1c))(g_pGameRules,*(undefined4 *)(param_1 + 1000),param_1);
  return;
}


