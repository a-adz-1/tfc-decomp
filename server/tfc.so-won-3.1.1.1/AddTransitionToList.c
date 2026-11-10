// AddTransitionToList__12CChangeLevelP9LEVELLISTiPCcT3P7edict_s  @ 001187cc
undefined4
AddTransitionToList__12CChangeLevelP9LEVELLISTiPCcT3P7edict_s
          (int param_1,int param_2,char *param_3,char *param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *__dest;
  
  if ((((param_1 == 0) || (param_3 == (char *)0x0)) || (param_4 == (char *)0x0)) || (param_5 == 0))
  {
LAB_001187f9:
    uVar1 = 0;
  }
  else {
    if (0 < param_2) {
      iVar3 = 0;
      do {
        if (*(int *)(param_1 + 0x40 + iVar3 * 0x50) == param_5) {
          iVar2 = strcmp((char *)(iVar3 * 0x50 + param_1),param_3);
          if (iVar2 == 0) goto LAB_001187f9;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_2);
    }
    __dest = (char *)(param_1 + param_2 * 0x50);
    strcpy(__dest,param_3);
    strcpy(__dest + 0x20,param_4);
    *(int *)(param_1 + 0x40 + param_2 * 0x50) = param_5;
    iVar3 = param_5 + 0x80;
    if (param_5 == 0) {
      iVar3 = 0;
    }
    *(undefined4 *)(__dest + 0x44) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(__dest + 0x48) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(__dest + 0x4c) = *(undefined4 *)(iVar3 + 0x10);
    uVar1 = 1;
  }
  return uVar1;
}


