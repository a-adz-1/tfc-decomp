// TF_AddFrags__11CBasePlayeri  @ 000e245c
void TF_AddFrags__11CBasePlayeri(int *param_1,int param_2)

{
  param_1[0x4b] = param_1[0x4b] + param_2;
  if (param_1[0x48] != 0) {
    (&teamfrags)[param_1[0x48]] = (&teamfrags)[param_1[0x48]] + param_2;
  }
  *(float *)(*param_1 + 0x164) = (float)param_1[0x4b];
  return;
}


