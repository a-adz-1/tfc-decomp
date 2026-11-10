// SendWeaponAnim__17CBasePlayerWeaponii  @ 001259d8
void SendWeaponAnim__17CBasePlayerWeaponii(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  *(undefined4 *)(*(int *)param_1[0x11d] + 0x218) = param_2;
  if ((param_3 != 0) &&
     (iVar1 = (*DAT_0019f8ac)(*(undefined4 *)(*(int *)param_1[0x11d] + 0x208)), iVar1 != 0)) {
    return;
  }
  (*DAT_0019f758)(1,0x23,0,*(undefined4 *)(*(int *)param_1[0x11d] + 0x208));
  (*DAT_0019f760)(param_2);
  (*DAT_0019f760)(*(undefined4 *)(*param_1 + 0x114));
  (*DAT_0019f75c)();
  return;
}


