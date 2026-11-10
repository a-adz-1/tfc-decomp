// OpenDoorAndWait__12CBaseMonsterP9entvars_s  @ 000bc7a0
longdouble OpenDoorAndWait__12CBaseMonsterP9entvars_s(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *local_c;
  float local_8;
  
  local_8 = 0.0;
  iVar2 = *(int *)(param_2 + 0x208);
  if (iVar2 == 0) {
    iVar2 = (*DAT_0019f7b4)(0);
    if (iVar2 == 0) {
      local_c = (int *)0x0;
      goto LAB_000bc7ef;
    }
  }
  local_c = *(int **)(iVar2 + 0x7c);
LAB_000bc7ef:
  if (local_c != (int *)0x0) {
    (**(code **)(local_c[0x115] + 0xb8))(local_c,param_1,param_1,1,0);
    local_8 = *(float *)(param_2 + 0x104) - *(float *)(param_2 + 0x100);
    if (*(int *)(*local_c + 0x1cc) != 0) {
      iVar2 = 0;
LAB_000bc8b1:
      do {
        iVar2 = (*DAT_0019f6d8)(iVar2,"targetname",*(int *)(*local_c + 0x1cc) + (int)gpGlobals[0x26]
                               );
        piVar5 = (int *)(iVar2 + 0x80);
        piVar3 = piVar5;
        if (iVar2 == 0) {
          piVar3 = (int *)0x0;
        }
      } while (piVar3 == (int *)*local_c);
      bVar1 = false;
      if (iVar2 == 0) {
LAB_000bc91a:
        bVar1 = true;
      }
      else {
        iVar4 = (*DAT_0019f7b8)(iVar2);
        if (iVar4 == 0) goto LAB_000bc91a;
      }
      if (!bVar1) {
        if (iVar2 == 0) {
          piVar5 = (int *)0x0;
        }
        iVar4 = strcmp((char *)((int)gpGlobals[0x26] + *piVar5),
                       (char *)((int)gpGlobals[0x26] + *(int *)*local_c));
        if (iVar4 == 0) {
          iVar4 = iVar2;
          if (iVar2 == 0) {
            iVar4 = (*DAT_0019f7b4)(0);
            if (iVar4 != 0) goto LAB_000bc889;
            iVar4 = 0;
          }
          else {
LAB_000bc889:
            iVar4 = *(int *)(iVar4 + 0x7c);
          }
          if (iVar4 != 0) {
            (**(code **)(*(int *)(iVar4 + 0x454) + 0xb8))(iVar4,param_1,param_1,1,0);
          }
        }
        goto LAB_000bc8b1;
      }
    }
  }
  return (longdouble)local_8 + (longdouble)*gpGlobals;
}


