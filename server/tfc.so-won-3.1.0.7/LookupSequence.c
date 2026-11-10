// LookupSequence__14CBaseAnimatingPCc  @ 000bee9c
void LookupSequence__14CBaseAnimatingPCc(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001c1148)(*(undefined4 *)(*param_1 + 0x208));
  LookupSequence__FPvPCc(uVar1,param_2);
  return;
}


// LookupSequence__FPvPCc  @ 00087754
int LookupSequence__FPvPCc(int param_1,char *param_2)

{
  int iVar1;
  char *__s1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    __s1 = (char *)(param_1 + *(int *)(param_1 + 0xa8));
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0xa4)) {
      do {
        iVar2 = strcasecmp(__s1,param_2);
        if (iVar2 == 0) {
          return iVar1;
        }
        __s1 = __s1 + 0xb0;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0xa4));
    }
    iVar1 = -1;
  }
  return iVar1;
}


