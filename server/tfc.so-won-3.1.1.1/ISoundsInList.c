// ISoundsInList__9CSoundEnti  @ 000f2f10
int ISoundsInList__9CSoundEnti(int param_1,int param_2)

{
  int iVar1;
  int unaff_ESI;
  
  if (param_2 == 1) {
    unaff_ESI = *(int *)(param_1 + 0x458);
  }
  else if (param_2 == 2) {
    unaff_ESI = *(int *)(param_1 + 0x45c);
  }
  else {
    (*DAT_0019f794)(1,"Unknown Sound List Type!\n");
  }
  if (unaff_ESI == -1) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      unaff_ESI = *(int *)(unaff_ESI * 0x20 + param_1 + 0x480);
    } while (unaff_ESI != -1);
  }
  return iVar1;
}


