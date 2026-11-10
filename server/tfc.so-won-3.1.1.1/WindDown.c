// WindDown__11CTFAssaultCb  @ 0012a4c8
void WindDown__11CTFAssaultCb(int param_1,undefined1 param_2)

{
  byte *pbVar1;
  
  (*DAT_0019f88c)(7,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                  *(undefined2 *)(param_1 + 0x4da),0,&g_vecZero,&g_vecZero,0,0,0,0,param_2,0);
  *(undefined4 *)(param_1 + 0x4ac) = 0;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x85);
  *pbVar1 = *pbVar1 & 0xf7;
  TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x474));
  *(undefined4 *)(param_1 + 0x490) = 0x40000000;
  return;
}


