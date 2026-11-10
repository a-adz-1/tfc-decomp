// OpenDoorAndWait__12CBaseMonsterP9entvars_s  @ 000b0e2c
void OpenDoorAndWait__12CBaseMonsterP9entvars_s(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *local_8;
  
  iVar2 = *(int *)(param_2 + 0x208);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001a7f54)(0);
    if (iVar2 == 0) {
      piVar3 = (int *)0x0;
      goto LAB_000b0e76;
    }
  }
  piVar3 = *(int **)(iVar2 + 0x7c);
LAB_000b0e76:
  if (piVar3 != (int *)0x0) {
    (**(code **)(piVar3[0xf5] + 0xb0))(piVar3,param_1,param_1,1,0);
    if (*(int *)(*piVar3 + 0x1cc) != 0) {
      iVar2 = 0;
LAB_000b0ec4:
      do {
        iVar2 = (*DAT_001a7e78)(iVar2,"targetname",
                                *(int *)(*piVar3 + 0x1cc) + *(int *)(gpGlobals + 0x98));
        iVar4 = iVar2 + 0x80;
        if (iVar2 == 0) {
          iVar4 = 0;
        }
      } while (iVar4 == *piVar3);
      bVar1 = false;
      if (iVar2 == 0) {
LAB_000b0f21:
        bVar1 = true;
      }
      else {
        iVar4 = (*DAT_001a7f58)(iVar2);
        if (iVar4 == 0) goto LAB_000b0f21;
      }
      if (!bVar1) {
        local_8 = (int *)(iVar2 + 0x80);
        if (iVar2 == 0) {
          local_8 = (int *)0x0;
        }
        iVar4 = strcmp((char *)(*local_8 + *(int *)(gpGlobals + 0x98)),
                       (char *)(*(int *)(gpGlobals + 0x98) + *(int *)*piVar3));
        if (iVar4 == 0) {
          iVar4 = iVar2;
          if (iVar2 == 0) {
            iVar4 = (*DAT_001a7f54)(0);
            if (iVar4 != 0) goto LAB_000b0f9c;
            iVar4 = 0;
          }
          else {
LAB_000b0f9c:
            iVar4 = *(int *)(iVar4 + 0x7c);
          }
          if (iVar4 != 0) {
            (**(code **)(*(int *)(iVar4 + 0x3d4) + 0xb0))(iVar4,param_1,param_1,1,0);
          }
        }
        goto LAB_000b0ec4;
      }
    }
  }
  return;
}


