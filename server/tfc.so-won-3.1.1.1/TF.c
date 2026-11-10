// TF_AddFrags__11CBasePlayeri  @ 000e40ac
void TF_AddFrags__11CBasePlayeri(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + param_1[0x4b];
  param_1[0x4b] = iVar2;
  if (param_1[0x48] == 0) {
    iVar1 = *param_1;
  }
  else {
    (&teamfrags)[param_1[0x48]] = (&teamfrags)[param_1[0x48]] + param_2;
    iVar1 = *param_1;
    iVar2 = param_1[0x4b];
  }
  *(float *)(iVar1 + 0x164) = (float)iVar2;
  return;
}


