// SendWeaponAnim__17CBasePlayerWeaponii  @ 001109fc
void SendWeaponAnim__17CBasePlayerWeaponii(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  *(undefined4 *)(*(int *)param_1[0xfd] + 0x218) = param_2;
  if ((param_3 != 0) &&
     (iVar1 = (*DAT_001a804c)(*(undefined4 *)(*(int *)param_1[0xfd] + 0x208)), iVar1 != 0)) {
    return;
  }
  (*DAT_001a7ef8)(1,0x23,0,*(undefined4 *)(*(int *)param_1[0xfd] + 0x208));
  (*DAT_001a7f00)(param_2);
  (*DAT_001a7f00)(*(undefined4 *)(*param_1 + 0x114));
  (*DAT_001a7efc)();
  return;
}


