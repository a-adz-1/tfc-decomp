// ResetMenu__11CBasePlayer  @ 000ac7a8
void ResetMenu__11CBasePlayer(int *param_1)

{
  (*DAT_001a7ef8)(1,gmsgShowMenu,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f08)(0);
  (*DAT_001a7f04)(0);
  (*DAT_001a7f00)(0);
  (*DAT_001a7f18)(&DAT_00136f46);
  (*DAT_001a7efc)();
  *(undefined1 *)(param_1 + 0x269) = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x44] = 0x3f800000;
  return;
}


