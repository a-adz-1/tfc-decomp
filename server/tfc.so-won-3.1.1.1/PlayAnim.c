// PlayAnim__10CTFMedikiti  @ 0012c8a4
void PlayAnim__10CTFMedikiti(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x454);
    uVar2 = 2;
  }
  else {
    if (param_2 != 1) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x454);
    uVar2 = 3;
  }
  (**(code **)(iVar1 + 0x168))(param_1,uVar2,1);
  return;
}


// PlayAnim__10CTFSpanneri  @ 0012cd70
void PlayAnim__10CTFSpanneri(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x454);
    uVar2 = 1;
  }
  else {
    if (param_2 != 1) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x454);
    uVar2 = 3;
  }
  (**(code **)(iVar1 + 0x168))(param_1,uVar2,1);
  return;
}


// PlayAnim__6CTFAxei  @ 0012d0e8
void PlayAnim__6CTFAxei(void)

{
  return;
}


// PlayAnim__8CTFKnifei  @ 0012cad4
void PlayAnim__8CTFKnifei(int param_1,int param_2)

{
  if ((param_2 == 0) || (param_2 == 1)) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,2,1);
  }
  return;
}


