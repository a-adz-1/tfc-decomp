// WindDown__11CTFAssaultCb  @ 0012624c
void WindDown__11CTFAssaultCb(int param_1,undefined1 param_2)

{
  byte *pbVar1;
  
  (*DAT_001c120c)(7,*(undefined4 *)(**(int **)(param_1 + 0x464) + 0x208),
                  *(undefined2 *)(param_1 + 0x4ca),0,&g_vecZero,&g_vecZero,0,0,0,0,param_2,0);
  *(undefined4 *)(param_1 + 0x49c) = 0;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x85);
  *pbVar1 = *pbVar1 & 0xf7;
  TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x464));
  *(undefined4 *)(param_1 + 0x480) = 0x40000000;
  return;
}


