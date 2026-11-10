// WindUp__11CTFAssaultC  @ 00116484
void WindUp__11CTFAssaultC(int param_1)

{
  byte *pbVar1;
  
  (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                  *(undefined2 *)(param_1 + 0x458),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
  *(undefined4 *)(param_1 + 0x42c) = 1;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x85);
  *pbVar1 = *pbVar1 | 8;
  TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x3f4));
  return;
}


