// RetireWeapon__17CBasePlayerWeapon  @ 00111374
void RetireWeapon__17CBasePlayerWeapon(int param_1)

{
  *(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0xbc) = 0;
  *(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0xc0) = 0;
  (**(code **)(*g_pGameRules + 0x1c))(g_pGameRules,*(undefined4 *)(param_1 + 0x3f4),param_1);
  return;
}


