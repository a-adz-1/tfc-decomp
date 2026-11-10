// LookupSequence__14CBaseAnimatingPCc  @ 000c1f08
void LookupSequence__14CBaseAnimatingPCc(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
  LookupSequence__FPvPCc(uVar1,param_2);
  return;
}


// LookupSequence__FPvPCc  @ 00087af4
int LookupSequence__FPvPCc(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xa8);
    if (0 < *(int *)(param_1 + 0xa4)) {
      iVar3 = 0;
      do {
        iVar2 = strcasecmp((char *)(iVar3 * 0xb0 + param_1 + iVar1),param_2);
        if (iVar2 == 0) {
          return iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0xa4));
    }
    iVar1 = -1;
  }
  return iVar1;
}


