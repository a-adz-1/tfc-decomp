// OpenDoorAndWait__12CBaseMonsterP9entvars_s  @ 000bc08c
void OpenDoorAndWait__12CBaseMonsterP9entvars_s(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piStack_8;
  
  iVar2 = *(int *)(param_2 + 0x208);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001c1134)(0);
    if (iVar2 == 0) {
      piVar3 = (int *)0x0;
      goto LAB_000bc0d6;
    }
  }
  piVar3 = *(int **)(iVar2 + 0x7c);
LAB_000bc0d6:
  if (piVar3 != (int *)0x0) {
    (**(code **)(piVar3[0x111] + 0xb8))(piVar3,param_1,param_1,1,0);
    if (*(int *)(*piVar3 + 0x1cc) != 0) {
      iVar2 = 0;
LAB_000bc124:
      do {
        iVar2 = (*DAT_001c1058)(iVar2,"targetname",
                                *(int *)(*piVar3 + 0x1cc) + *(int *)(gpGlobals + 0x98));
        iVar4 = iVar2 + 0x80;
        if (iVar2 == 0) {
          iVar4 = 0;
        }
      } while (iVar4 == *piVar3);
      bVar1 = false;
      if (iVar2 == 0) {
LAB_000bc181:
        bVar1 = true;
      }
      else {
        iVar4 = (*DAT_001c1138)(iVar2);
        if (iVar4 == 0) goto LAB_000bc181;
      }
      if (!bVar1) {
        piStack_8 = (int *)(iVar2 + 0x80);
        if (iVar2 == 0) {
          piStack_8 = (int *)0x0;
        }
        iVar4 = strcmp((char *)(*piStack_8 + *(int *)(gpGlobals + 0x98)),
                       (char *)(*(int *)(gpGlobals + 0x98) + *(int *)*piVar3));
        if (iVar4 == 0) {
          iVar4 = iVar2;
          if (iVar2 == 0) {
            iVar4 = (*DAT_001c1134)(0);
            if (iVar4 != 0) goto LAB_000bc1fc;
            iVar4 = 0;
          }
          else {
LAB_000bc1fc:
            iVar4 = *(int *)(iVar4 + 0x7c);
          }
          if (iVar4 != 0) {
            (**(code **)(*(int *)(iVar4 + 0x444) + 0xb8))(iVar4,param_1,param_1,1,0);
          }
        }
        goto LAB_000bc124;
      }
    }
  }
  return;
}


