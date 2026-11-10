// FizzThink__9CBubbling  @ 0009f5f8
void FizzThink__9CBubbling(int *param_1)

{
  float fVar1;
  short sVar2;
  undefined1 local_10 [12];
  
  VecBModelOrigin__FP9entvars_s(local_10,*param_1);
  (*DAT_0019f758)(5,0x17,local_10,0);
  (*DAT_0019f760)(0x69);
  sVar2 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f768)((int)sVar2);
  (*DAT_0019f768)((int)(short)param_1[0x118]);
  (*DAT_0019f760)(param_1[0x116]);
  (*DAT_0019f75c)();
  if (param_1[0x117] < 0x14) {
    fVar1 = (*gpGlobals + 2.5) - (float)param_1[0x117] * 0.1;
  }
  else {
    fVar1 = *gpGlobals + 0.5;
  }
  *(float *)(*param_1 + 0x104) = fVar1;
  return;
}


