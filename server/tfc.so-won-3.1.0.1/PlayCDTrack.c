// PlayCDTrack__Fi  @ 00102648
void PlayCDTrack__Fi(int param_1)

{
  int iVar1;
  code *pcVar2;
  char *pcVar3;
  char acStack_40 [64];
  
  iVar1 = (*DAT_001a7f60)(1);
  if (iVar1 != 0) {
    if (param_1 + 1U < 0x20) {
      if (param_1 != -1) {
        sprintf(acStack_40,"cd play %3d\n",param_1);
        (*DAT_001a7ee4)(iVar1,acStack_40);
        return;
      }
      pcVar3 = "cd pause\n";
      pcVar2 = DAT_001a7ee4;
    }
    else {
      pcVar3 = "TriggerCDAudio - Track %d out of range\n";
      iVar1 = 1;
      pcVar2 = DAT_001a7f34;
    }
    (*pcVar2)(iVar1,pcVar3);
  }
  return;
}


