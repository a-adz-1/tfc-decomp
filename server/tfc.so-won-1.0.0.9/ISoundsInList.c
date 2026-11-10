// ISoundsInList__9CSoundEnti  @ 000ee3e0
int ISoundsInList__9CSoundEnti(int param_1,int param_2)

{
  int iVar1;
  int unaff_EBX;
  
  if (param_2 == 1) {
    unaff_EBX = *(int *)(param_1 + 0x3cc);
  }
  else if (param_2 == 2) {
    unaff_EBX = *(int *)(param_1 + 0x3d0);
  }
  else {
    (*DAT_001755b4)(1,"Unknown Sound List Type!\n");
  }
  if (unaff_EBX == -1) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    if (unaff_EBX != -1) {
      do {
        iVar1 = iVar1 + 1;
        unaff_EBX = *(int *)(unaff_EBX * 0x20 + param_1 + 0x3f4);
      } while (unaff_EBX != -1);
    }
  }
  return iVar1;
}


