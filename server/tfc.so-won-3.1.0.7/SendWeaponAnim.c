// SendWeaponAnim__17CBasePlayerWeaponii  @ 0012054c
void SendWeaponAnim__17CBasePlayerWeaponii(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  *(undefined4 *)(*(int *)param_1[0x119] + 0x218) = param_2;
  if ((param_3 != 0) &&
     (iVar1 = (*DAT_001c122c)(*(undefined4 *)(*(int *)param_1[0x119] + 0x208)), iVar1 != 0)) {
    return;
  }
  (*DAT_001c10d8)(1,0x23,0,*(undefined4 *)(*(int *)param_1[0x119] + 0x208));
  (*DAT_001c10e0)(param_2);
  (*DAT_001c10e0)(*(undefined4 *)(*param_1 + 0x114));
  (*DAT_001c10dc)();
  return;
}


