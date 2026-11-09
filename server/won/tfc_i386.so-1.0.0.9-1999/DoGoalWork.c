// DoGoalWork__FP11CBaseEntityP11CBasePlayer  @ 0010af60
void DoGoalWork__FP11CBaseEntityP11CBasePlayer(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if (*(int *)(param_1 + 0x254) != 0) {
    iVar1 = Findgoal__Fi(*(undefined4 *)(param_1 + 0x254));
    if (iVar1 != 0) {
      ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0(iVar1,param_2,param_1);
    }
  }
  if (*(int *)(param_1 + 600) != 0) {
    iVar1 = Findgoal__Fi(*(undefined4 *)(param_1 + 600));
    if (iVar1 != 0) {
      InactivateGoal__FP11CBaseEntity(iVar1);
    }
  }
  if (*(int *)(param_1 + 0x260) != 0) {
    iVar1 = Findgoal__Fi(*(undefined4 *)(param_1 + 0x260));
    if (iVar1 != 0) {
      RestoreGoal__FP11CBaseEntity(iVar1);
    }
  }
  if (*(int *)(param_1 + 0x25c) != 0) {
    iVar1 = Findgoal__Fi(*(undefined4 *)(param_1 + 0x25c));
    if (iVar1 != 0) {
      RemoveGoal__FP11CBaseEntity(iVar1);
    }
  }
  if (*(int *)(param_1 + 0x29c) == 0) goto LAB_0010b0c6;
  piVar2 = (int *)Finditem__Fi(*(undefined4 *)(param_1 + 0x29c));
  if (piVar2 == (int *)0x0) goto LAB_0010b0c6;
  iVar1 = *(int *)(*piVar2 + 0x178);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 != 0) goto LAB_0010b048;
    uVar3 = 0;
  }
  else {
LAB_0010b048:
    uVar3 = *(undefined4 *)(iVar1 + 0xd8);
  }
  if (piVar2[0x86] == 1) {
    tfgoalitem_RemoveFromPlayer__FP11CBaseEntityP11CBasePlayeri(piVar2,uVar3,1);
  }
  piVar4 = (int *)CreateTimer__11CBaseEntityi(piVar2,100);
  piVar4[0x24] = 3;
  piVar4[3] = -0x10000;
  piVar4[4] = (int)ReturnItem__11CBaseEntity;
  *(float *)(*piVar4 + 0xe4) = *gpGlobals + 0.1;
  *(undefined4 *)(*piVar2 + 0xec) = 0;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar2,*piVar2 + 8);
LAB_0010b0c6:
  if (*(int *)(param_1 + 0x2a8) != 0) {
    iVar1 = Findteamspawn__Fi(*(undefined4 *)(param_1 + 0x2a8));
    if (iVar1 != 0) {
      InactivateSpawn__FP11CBaseEntity(iVar1);
    }
  }
  if (*(int *)(param_1 + 0x2ac) != 0) {
    iVar1 = Findteamspawn__Fi(*(undefined4 *)(param_1 + 0x2ac));
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x218) == 3)) {
      ActivateSpawn__FP11CBaseEntity(iVar1);
    }
  }
  return;
}


