// PlayAnim__10CTFMedikiti  @ 00118c68
void PlayAnim__10CTFMedikiti(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    uVar2 = 2;
  }
  else {
    if (param_2 != 1) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x3d4);
    uVar2 = 3;
  }
  (**(code **)(iVar1 + 0x160))(param_1,uVar2,1);
  return;
}


// PlayAnim__10CTFSpanneri  @ 00117abc
void PlayAnim__10CTFSpanneri(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x3d4);
    uVar2 = 1;
  }
  else {
    if (param_2 != 1) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x3d4);
    uVar2 = 3;
  }
  (**(code **)(iVar1 + 0x160))(param_1,uVar2,1);
  return;
}


// PlayAnim__6CTFAxei  @ 001170f0
void PlayAnim__6CTFAxei(void)

{
  return;
}


// PlayAnim__8CTFKnifei  @ 00117d34
void PlayAnim__8CTFKnifei(int param_1,int param_2)

{
  if ((param_2 == 0) || (param_2 == 1)) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,2,1);
  }
  return;
}


