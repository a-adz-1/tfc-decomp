// AddTransitionToList__12CChangeLevelP9LEVELLISTiPCcT3P7edict_s  @ 00103d14
undefined4
AddTransitionToList__12CChangeLevelP9LEVELLISTiPCcT3P7edict_s
          (char *param_1,uint param_2,char *param_3,char *param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  
  if ((((param_1 == (char *)0x0) || (param_3 == (char *)0x0)) || (param_4 == (char *)0x0)) ||
     (param_5 == 0)) {
LAB_00103edc:
    uVar3 = 0;
  }
  else {
    iVar4 = 0;
    if (0 < (int)param_2) {
      piVar6 = (int *)(param_1 + 0x40);
      uVar1 = param_2 & 3;
      pcVar5 = param_1;
      if (uVar1 != 0) {
        if (1 < uVar1) {
          if (2 < uVar1) {
            if ((*(int *)(param_1 + 0x40) == param_5) &&
               (iVar4 = strcmp(param_1,param_3), iVar4 == 0)) goto LAB_00103edc;
            pcVar5 = param_1 + 0x50;
            piVar6 = (int *)(param_1 + 0x90);
            iVar4 = 1;
          }
          if ((*piVar6 == param_5) && (iVar2 = strcmp(pcVar5,param_3), iVar2 == 0))
          goto LAB_00103edc;
          pcVar5 = pcVar5 + 0x50;
          piVar6 = piVar6 + 0x14;
          iVar4 = iVar4 + 1;
        }
        if ((*piVar6 == param_5) && (iVar2 = strcmp(pcVar5,param_3), iVar2 == 0)) goto LAB_00103edc;
        pcVar5 = pcVar5 + 0x50;
        piVar6 = piVar6 + 0x14;
        iVar4 = iVar4 + 1;
        if ((int)param_2 <= iVar4) goto LAB_00103e98;
      }
      do {
        if (((((*piVar6 == param_5) && (iVar2 = strcmp(pcVar5,param_3), iVar2 == 0)) ||
             ((piVar6[0x14] == param_5 && (iVar2 = strcmp(pcVar5 + 0x50,param_3), iVar2 == 0)))) ||
            ((piVar6[0x28] == param_5 && (iVar2 = strcmp(pcVar5 + 0xa0,param_3), iVar2 == 0)))) ||
           ((piVar6[0x3c] == param_5 && (iVar2 = strcmp(pcVar5 + 0xf0,param_3), iVar2 == 0))))
        goto LAB_00103edc;
        pcVar5 = pcVar5 + 0x140;
        piVar6 = piVar6 + 0x50;
        iVar4 = iVar4 + 4;
      } while (iVar4 < (int)param_2);
    }
LAB_00103e98:
    strcpy(param_1 + param_2 * 0x50,param_3);
    strcpy(param_1 + param_2 * 0x50 + 0x20,param_4);
    *(int *)(param_1 + param_2 * 0x50 + 0x40) = param_5;
    if (param_5 == 0) {
      param_5 = 0;
    }
    else {
      param_5 = param_5 + 0x80;
    }
    *(undefined4 *)(param_1 + param_2 * 0x50 + 0x44) = *(undefined4 *)(param_5 + 8);
    *(undefined4 *)(param_1 + param_2 * 0x50 + 0x48) = *(undefined4 *)(param_5 + 0xc);
    *(undefined4 *)(param_1 + param_2 * 0x50 + 0x4c) = *(undefined4 *)(param_5 + 0x10);
    uVar3 = 1;
  }
  return uVar3;
}


