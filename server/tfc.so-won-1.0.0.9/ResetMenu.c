// ResetMenu__11CBasePlayer  @ 000be230
void ResetMenu__11CBasePlayer(int *param_1)

{
  (*DAT_00175578)(1,gmsgShowMenu,0,*(undefined4 *)(*param_1 + 0x1e8));
  (*DAT_00175588)(0);
  (*DAT_00175584)(0);
  (*DAT_00175580)(0);
  (*DAT_00175598)(&DAT_001348e6);
  (*DAT_0017557c)();
  *(undefined1 *)(param_1 + 0x263) = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x45] = 0x3f800000;
  return;
}


