// Direction__6CBlood  @ 000a3adc
undefined4 * Direction__6CBlood(undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if ((*(byte *)(iVar1 + 0x1a0) & 1) == 0) {
    *param_1 = *(undefined4 *)(iVar1 + 0x44);
    param_1[1] = *(undefined4 *)(iVar1 + 0x48);
    param_1[2] = *(undefined4 *)(iVar1 + 0x4c);
  }
  else {
    UTIL_RandomBloodVector__Fv(param_1);
  }
  return param_1;
}


