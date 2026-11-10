// WindUp__11CTFAssaultC  @ 0012a558
void WindUp__11CTFAssaultC(int param_1)

{
  byte *pbVar1;
  
  if (((*(byte *)(**(int **)(param_1 + 0x474) + 0x180) ^ 1) & 1) == 0) {
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4d8),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x4ac) = 1;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x85);
    *pbVar1 = *pbVar1 | 8;
    TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x474));
  }
  return;
}


