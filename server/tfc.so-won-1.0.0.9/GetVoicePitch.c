// GetVoicePitch__12CTalkMonster  @ 000f21a0
int GetVoicePitch__12CTalkMonster(int param_1)

{
  int iVar1;
  
  iVar1 = (*DAT_00175628)(0,3);
  return iVar1 + *(int *)(param_1 + 0x618);
}


