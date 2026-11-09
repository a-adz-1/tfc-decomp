// AddTransitionToList__12CChangeLevelP9LEVELLISTiPCcT3P7edict_s  @ 00111490
undefined4
AddTransitionToList__12CChangeLevelP9LEVELLISTiPCcT3P7edict_s
          (int param_1,int param_2,char *param_3,char *param_4,int param_5)

{
  char *__dest;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((((param_1 == 0) || (param_3 == (char *)0x0)) || (param_4 == (char *)0x0)) || (param_5 == 0))
  {
LAB_00111510:
    uVar2 = 0;
  }
  else {
    iVar3 = 0;
    if (0 < param_2) {
      do {
        if (*(int *)(param_1 + 0x40 + iVar3 * 0x50) == param_5) {
          iVar1 = strcmp((char *)(iVar3 * 0x50 + param_1),param_3);
          if (iVar1 == 0) goto LAB_00111510;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_2);
    }
    __dest = (char *)(param_2 * 0x50 + param_1);
    strcpy(__dest,param_3);
    strcpy(__dest + 0x20,param_4);
    *(int *)(param_1 + 0x40 + param_2 * 0x50) = param_5;
    if (param_5 == 0) {
      param_5 = 0;
    }
    else {
      param_5 = param_5 + 0xdc;
    }
    param_1 = param_2 * 0x50 + param_1;
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_5 + 8);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_5 + 0xc);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_5 + 0x10);
    uVar2 = 1;
  }
  return uVar2;
}


