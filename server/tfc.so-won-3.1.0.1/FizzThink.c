// FizzThink__9CBubbling  @ 000959d4
void FizzThink__9CBubbling(int *param_1)

{
  float fVar1;
  short sVar2;
  int iVar3;
  undefined1 local_c [12];
  
  VecBModelOrigin__FP9entvars_s(local_c,*param_1);
  (*DAT_001a7ef8)(5,0x17,local_c,0);
  (*DAT_001a7f00)(0x69);
  sVar2 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f08)((int)sVar2);
  (*DAT_001a7f08)((int)(short)param_1[0xf8]);
  (*DAT_001a7f00)(param_1[0xf6]);
  (*DAT_001a7efc)();
  if (param_1[0xf7] < 0x14) {
    iVar3 = *param_1;
    fVar1 = (*gpGlobals + 2.5) - (float)param_1[0xf7] * 0.1;
  }
  else {
    iVar3 = *param_1;
    fVar1 = *gpGlobals + 0.5;
  }
  *(float *)(iVar3 + 0x104) = fVar1;
  return;
}


