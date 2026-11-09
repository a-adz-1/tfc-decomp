// DoTriggerWork__FP11CBaseEntityP11CBasePlayer  @ 0010b570
void DoTriggerWork__FP11CBaseEntityP11CBasePlayer(int *param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1[200] != 0) {
    iVar3 = param_1[200] + *(int *)(gpGlobals + 0x98);
    iVar5 = 0;
    while( true ) {
      iVar5 = (*DAT_001754f8)(iVar5,"targetname",iVar3);
      bVar1 = false;
      if ((iVar5 == 0) || (iVar3 = (*DAT_001755d8)(iVar5), iVar3 == 0)) {
        bVar1 = true;
      }
      if (bVar1) break;
      iVar3 = iVar5;
      if ((iVar5 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined4 *)(iVar3 + 0xd8);
      }
      UTIL_Remove__FP11CBaseEntity(uVar2);
      iVar3 = param_1[200] + *(int *)(gpGlobals + 0x98);
    }
  }
  if (*(int *)(*param_1 + 0x1a8) != 0) {
    iVar3 = *(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98);
    iVar5 = 0;
    while( true ) {
      iVar5 = (*DAT_001754f8)(iVar5,"targetname",iVar3);
      bVar1 = false;
      if ((iVar5 == 0) || (iVar3 = (*DAT_001755d8)(iVar5), iVar3 == 0)) {
        bVar1 = true;
      }
      if (bVar1) break;
      iVar3 = iVar5;
      if ((iVar5 == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = *(int **)(iVar3 + 0xd8);
      }
      if ((*(byte *)(*piVar4 + 0x187) & 0x40) == 0) {
        (**(code **)(piVar4[0xf2] + 0xb0))(piVar4,param_2,param_1,3,0);
      }
      iVar3 = *(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98);
    }
  }
  return;
}


