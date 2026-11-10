// GenericCyclerSpawn__7CCyclerPcG6VectorT2  @ 000b4774
void GenericCyclerSpawn__7CCyclerPcG6VectorT2
               (int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar4;
  undefined8 uVar3;
  
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    iVar1 = *param_1;
    (*DAT_0019f794)(4,"cycler at %.0f %.0f %0.f missing modelname",(double)*(float *)(iVar1 + 8),
                    (double)*(float *)(iVar1 + 0xc),(double)*(float *)(iVar1 + 0x10));
    (*DAT_0019f6f8)();
  }
  else {
    *(int *)*param_1 = (int)"cycler" - *(int *)(gpGlobals + 0x98);
    pcVar4 = param_2;
    (*g_engfuncs)();
    uVar3 = CONCAT44(pcVar4,param_2);
    uVar2 = *(undefined4 *)(*param_1 + 0x208);
    (*DAT_0019f6a8)();
    Spawn__7CCycler(param_1,uVar2,uVar3);
    UTIL_SetSize__FP9entvars_sRC6VectorT1(*param_1,param_3,param_4);
  }
  return;
}


