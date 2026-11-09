// PlayAnim__10CTFMedikiti  @ 000fa2b0
void PlayAnim__10CTFMedikiti(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x3c8);
    uVar2 = 2;
  }
  else {
    if (param_2 != 1) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x3c8);
    uVar2 = 3;
  }
  (**(code **)(iVar1 + 0x15c))(param_1,uVar2);
  return;
}


// PlayAnim__10CTFSpanneri  @ 000f95e0
void PlayAnim__10CTFSpanneri(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x3c8);
    uVar2 = 1;
  }
  else {
    if (param_2 != 1) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x3c8);
    uVar2 = 3;
  }
  (**(code **)(iVar1 + 0x15c))(param_1,uVar2);
  return;
}


// PlayAnim__6CTFAxei  @ 000f8950
void PlayAnim__6CTFAxei(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_2 == 0) {
    uVar2 = (*(int *)(param_1 + 0x460) / 3 + (*(int *)(param_1 + 0x460) >> 0x1f)) -
            (*(int *)(param_1 + 0x460) >> 0x1f);
    iVar1 = *(int *)(param_1 + 0x460) + uVar2 * -3;
    *(int *)(param_1 + 0x460) = *(int *)(param_1 + 0x460) + 1;
    if (iVar1 == 1) {
      iVar1 = *(int *)(param_1 + 0x3c8);
      uVar4 = 5;
    }
    else if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      iVar1 = *(int *)(param_1 + 0x3c8);
      uVar4 = 4;
    }
    else {
      if (iVar1 != 2) {
        return;
      }
      iVar1 = *(int *)(param_1 + 0x3c8);
      uVar4 = 7;
    }
  }
  else {
    if (param_2 != 1) {
      return;
    }
    uVar2 = *(int *)(param_1 + 0x460) - (*(int *)(param_1 + 0x460) >> 0x1f) & 0xfffffffe;
    iVar1 = *(int *)(param_1 + 0x460) - uVar2;
    iVar3 = iVar1 + 1;
    *(int *)(param_1 + 0x460) = *(int *)(param_1 + 0x460) + 1;
    if (iVar3 == 1) {
      iVar1 = *(int *)(param_1 + 0x3c8);
      uVar4 = 6;
    }
    else if (iVar3 < 2) {
      if (iVar1 != -1) {
        return;
      }
      iVar1 = *(int *)(param_1 + 0x3c8);
      uVar4 = 3;
    }
    else {
      if (iVar3 != 2) {
        return;
      }
      iVar1 = *(int *)(param_1 + 0x3c8);
      uVar4 = 8;
    }
  }
  (**(code **)(iVar1 + 0x15c))(param_1,uVar4,uVar2);
  return;
}


// PlayAnim__8CTFKnifei  @ 000f97f0
void PlayAnim__8CTFKnifei(int param_1,int param_2)

{
  if ((param_2 == 0) || (param_2 == 1)) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,2);
  }
  return;
}


