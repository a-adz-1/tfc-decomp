// DoTriggerWork__FP11CBaseEntityP11CBasePlayer  @ 0010df68
void DoTriggerWork__FP11CBaseEntityP11CBasePlayer(int *param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (param_1[0xdf] != 0) {
    iVar4 = param_1[0xdf] + *(int *)(gpGlobals + 0x98);
    iVar5 = 0;
    while( true ) {
      iVar5 = (*DAT_0019f6d8)(iVar5,"targetname",iVar4);
      bVar1 = false;
      if ((iVar5 == 0) || (iVar4 = (*DAT_0019f7b8)(iVar5), iVar4 == 0)) {
        bVar1 = true;
      }
      if (bVar1) break;
      iVar4 = iVar5;
      if ((iVar5 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined4 *)(iVar4 + 0x7c);
      }
      UTIL_Remove__FP11CBaseEntity(uVar2);
      iVar4 = param_1[0xdf] + *(int *)(gpGlobals + 0x98);
    }
  }
  if (*(int *)(*param_1 + 0x1c8) == 0) {
    return;
  }
  iVar4 = *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98);
  iVar5 = 0;
  while( true ) {
    iVar5 = (*DAT_0019f6d8)(iVar5,"targetname",iVar4);
    bVar1 = false;
    if ((iVar5 == 0) || (iVar4 = (*DAT_0019f7b8)(iVar5), iVar4 == 0)) {
      bVar1 = true;
    }
    if (bVar1) break;
    iVar4 = iVar5;
    if ((iVar5 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(iVar4 + 0x7c);
    }
    if ((*(byte *)(*piVar3 + 0x1a7) & 0x40) == 0) {
      (**(code **)(piVar3[0x115] + 0xb8))(piVar3,param_2,param_1,3,0);
    }
    iVar4 = *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98);
  }
  return;
}


