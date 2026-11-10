// FizzThink__9CBubbling  @ 000ab540
void FizzThink__9CBubbling(int *param_1)

{
  float fVar1;
  short sVar2;
  int iVar3;
  undefined1 local_10 [12];
  
  VecBModelOrigin__FP9entvars_t(local_10,*param_1);
  (*DAT_00175578)(5,0x17,local_10,0);
  (*DAT_00175580)(0x69);
  sVar2 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x1e8));
  (*DAT_00175588)((int)sVar2);
  (*DAT_00175588)((int)(short)param_1[0xf5]);
  (*DAT_00175580)(param_1[0xf3]);
  (*DAT_0017557c)();
  if (param_1[0xf4] < 0x14) {
    iVar3 = *param_1;
    fVar1 = (*gpGlobals + 2.5) - (float)param_1[0xf4] * 0.1;
  }
  else {
    iVar3 = *param_1;
    fVar1 = *gpGlobals + 0.5;
  }
  *(float *)(iVar3 + 0xe4) = fVar1;
  return;
}


