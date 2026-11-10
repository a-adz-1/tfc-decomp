// WindDown__11CTFAssaultC  @ 00116504
void WindDown__11CTFAssaultC(int param_1)

{
  byte *pbVar1;
  
  (*DAT_001a802c)(7,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                  *(undefined2 *)(param_1 + 0x45a),0,**(int **)(param_1 + 0x3f4) + 8,&g_vecZero,0,0,
                  0,0,*(int *)(param_1 + 0x42c) == 2,0);
  *(undefined4 *)(param_1 + 0x42c) = 0;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x85);
  *pbVar1 = *pbVar1 & 0xf7;
  TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x3f4));
  *(undefined4 *)(param_1 + 0x410) = 0x40000000;
  return;
}


