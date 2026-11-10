// ResetMenu__11CBasePlayer  @ 000b7908
void ResetMenu__11CBasePlayer(int *param_1)

{
  (*DAT_001c10d8)(1,gmsgShowMenu,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001c10e8)(0);
  (*DAT_001c10e4)(0);
  (*DAT_001c10e0)(0);
  (*DAT_001c10f8)(&DAT_00147806);
  (*DAT_001c10dc)();
  *(undefined1 *)(param_1 + 0x286) = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x44] = 0x3f800000;
  return;
}


