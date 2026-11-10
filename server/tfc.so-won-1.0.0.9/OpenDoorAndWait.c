// OpenDoorAndWait__12CBaseMonsterP9entvars_t  @ 000c2e70
longdouble OpenDoorAndWait__12CBaseMonsterP9entvars_t(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  float local_8;
  
  local_8 = 0.0;
  iVar2 = *(int *)(param_2 + 0x1e8);
  if (iVar2 == 0) {
    iVar2 = (*DAT_001755d4)(0);
    if (iVar2 == 0) {
      piVar3 = (int *)0x0;
      goto LAB_000c2eb2;
    }
  }
  piVar3 = *(int **)(iVar2 + 0xd8);
LAB_000c2eb2:
  if (piVar3 != (int *)0x0) {
    (**(code **)(piVar3[0xf2] + 0xb0))(piVar3,param_1,param_1,1,0);
    local_8 = *(float *)(param_2 + 0xe4) - *(float *)(param_2 + 0xe0);
    if (*(int *)(*piVar3 + 0x1ac) != 0) {
      iVar2 = 0;
LAB_000c2ef8:
      do {
        iVar2 = (*DAT_001754f8)(iVar2,"targetname",*(int *)(*piVar3 + 0x1ac) + (int)gpGlobals[0x26])
        ;
        iVar4 = iVar2 + 0xdc;
        if (iVar2 == 0) {
          iVar4 = 0;
        }
      } while (iVar4 == *piVar3);
      bVar1 = false;
      if (iVar2 == 0) {
LAB_000c2f44:
        bVar1 = true;
      }
      else {
        iVar4 = (*DAT_001755d8)(iVar2);
        if (iVar4 == 0) goto LAB_000c2f44;
      }
      if (!bVar1) {
        piVar5 = (int *)(iVar2 + 0xdc);
        if (iVar2 == 0) {
          piVar5 = (int *)0x0;
        }
        iVar4 = strcmp((char *)(*piVar5 + (int)gpGlobals[0x26]),
                       (char *)((int)gpGlobals[0x26] + *(int *)*piVar3));
        if (iVar4 == 0) {
          iVar4 = iVar2;
          if (iVar2 == 0) {
            iVar4 = (*DAT_001755d4)(0);
            if (iVar4 != 0) goto LAB_000c2fa4;
            iVar4 = 0;
          }
          else {
LAB_000c2fa4:
            iVar4 = *(int *)(iVar4 + 0xd8);
          }
          if (iVar4 != 0) {
            (**(code **)(*(int *)(iVar4 + 0x3c8) + 0xb0))(iVar4,param_1,param_1,1,0);
          }
        }
        goto LAB_000c2ef8;
      }
    }
  }
  return (longdouble)local_8 + (longdouble)*gpGlobals;
}


