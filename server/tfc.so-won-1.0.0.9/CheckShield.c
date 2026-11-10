// CheckShield__12CTFSentrygun  @ 000e9720
void CheckShield__12CTFSentrygun(int *param_1)

{
  int iVar1;
  
  *(float *)(*param_1 + 300) = *(float *)(*param_1 + 300) - 40.0;
  if (*(float *)(*param_1 + 300) <= 0.0) {
    *(undefined4 *)(*param_1 + 0x13c) = 0;
    *(undefined4 *)(*param_1 + 300) = 0;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x130) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x134) = DAT_00175484;
    *(undefined4 *)(iVar1 + 0x138) = DAT_00175488;
  }
  return;
}


