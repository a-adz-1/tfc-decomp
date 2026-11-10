// DoTriggerWork__FP11CBaseEntityP11CBasePlayer  @ 0010b2f4
void DoTriggerWork__FP11CBaseEntityP11CBasePlayer(int *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1[0xdb] != 0) {
    iVar2 = param_1[0xdb] + *(int *)(gpGlobals + 0x98);
    iVar5 = 0;
    while( true ) {
      iVar5 = (*DAT_001c1058)(iVar5,"targetname",iVar2);
      bVar1 = false;
      if ((iVar5 == 0) || (iVar2 = (*DAT_001c1138)(iVar5), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) break;
      iVar2 = iVar5;
      if ((iVar5 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined4 *)(iVar2 + 0x7c);
      }
      UTIL_Remove__FP11CBaseEntity(uVar3);
      iVar2 = param_1[0xdb] + *(int *)(gpGlobals + 0x98);
    }
  }
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    iVar2 = *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98);
    iVar5 = 0;
    while( true ) {
      iVar5 = (*DAT_001c1058)(iVar5,"targetname",iVar2);
      bVar1 = false;
      if ((iVar5 == 0) || (iVar2 = (*DAT_001c1138)(iVar5), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) break;
      iVar2 = iVar5;
      if ((iVar5 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = *(int **)(iVar2 + 0x7c);
      }
      if ((*(byte *)(*piVar4 + 0x1a7) & 0x40) == 0) {
        (**(code **)(piVar4[0x111] + 0xb8))(piVar4,param_2,param_1,3,0);
      }
      iVar2 = *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98);
    }
  }
  return;
}


