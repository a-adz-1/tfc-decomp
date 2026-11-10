// GetVoicePitch__12CTalkMonster  @ 000f5a28
int GetVoicePitch__12CTalkMonster(int param_1)

{
  int iVar1;
  
  iVar1 = (*DAT_001c1188)(0,3);
  return iVar1 + *(int *)(param_1 + 0x694);
}


