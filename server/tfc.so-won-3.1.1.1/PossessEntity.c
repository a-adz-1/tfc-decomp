// PossessEntity__12CCineMonster  @ 000e9658
void PossessEntity__12CCineMonster(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x141);
  piVar2 = (int *)0x0;
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*(int *)(iVar1 + 0x454) + 0x50))(iVar1);
  }
  if (piVar2 == (int *)0x0) {
    return;
  }
  piVar2[1] = (int)param_1;
  piVar2[0x1a6] = (int)param_1;
  __as__7EHANDLEP11CBaseEntity(piVar2 + 0x141,param_1);
  param_1[0x1b0] = *(int *)(*piVar2 + 0x108);
  param_1[0x1b1] = *(int *)(*piVar2 + 0x10c);
  param_1[0x1b2] = *(int *)(*piVar2 + 0x118);
  *(uint *)(*piVar2 + 0x118) = *(uint *)(*piVar2 + 0x118) | *(uint *)(*param_1 + 0x118);
  switch(param_1[0x1aa]) {
  case 0:
    piVar2[0x1a5] = 1;
    break;
  case 1:
    piVar2[0x1a5] = 3;
    goto LAB_000e974a;
  case 2:
    piVar2[0x1a5] = 4;
LAB_000e974a:
    DelayStart__12CCineMonsteri(param_1,1);
    break;
  case 4:
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar2,*param_1 + 8);
    *(undefined4 *)(*piVar2 + 0xac) = *(undefined4 *)(*param_1 + 0x54);
    iVar1 = *piVar2;
    *(undefined4 *)(iVar1 + 0x5c) = 0;
    *(undefined4 *)(iVar1 + 0x60) = 0;
    *(undefined4 *)(iVar1 + 100) = 0;
    iVar1 = *piVar2;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0;
    *(byte *)(*piVar2 + 0x118) = *(byte *)(*piVar2 + 0x118) | 0x20;
    *(undefined4 *)(*piVar2 + 0x54) = *(undefined4 *)(*param_1 + 0x54);
    piVar2[0x1a5] = 1;
    param_1[0x1af] = (int)(*gpGlobals + 1e+06);
  }
  piVar2[0x15e] = 6;
  if (param_1[0x1a7] != 0) {
    (**(code **)(param_1[0x115] + 0x220))(param_1,piVar2,param_1[0x1a7],0);
    iVar1 = strcmp((char *)((int)gpGlobals[0x26] + param_1[0x1a7]),
                   (char *)((int)gpGlobals[0x26] + param_1[0x1a8]));
    if (iVar1 == 0) {
      *(undefined4 *)(*piVar2 + 0x138) = 0;
    }
  }
  return;
}


// PossessEntity__7CCineAI  @ 000e986c
void PossessEntity__7CCineAI(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x141);
  piVar3 = (int *)0x0;
  if (iVar1 != 0) {
    piVar3 = (int *)(**(code **)(*(int *)(iVar1 + 0x454) + 0x50))(iVar1);
  }
  if (piVar3 != (int *)0x0) {
    iVar1 = piVar3[0x115];
    uVar2 = (**(code **)(param_1[0x115] + 0x224))(param_1,2);
    iVar1 = (**(code **)(iVar1 + 0x180))(piVar3,uVar2);
    if (iVar1 == 0) {
      (*DAT_0019f794)(2,"(AI)Can\'t possess entity %s\n",*(int *)*piVar3 + (int)gpGlobals[0x26]);
    }
    else {
      piVar3[1] = (int)param_1;
      piVar3[0x1a6] = (int)param_1;
      __as__7EHANDLEP11CBaseEntity(piVar3 + 0x141,param_1);
      param_1[0x1b0] = *(int *)(*piVar3 + 0x108);
      param_1[0x1b1] = *(int *)(*piVar3 + 0x10c);
      param_1[0x1b2] = *(int *)(*piVar3 + 0x118);
      *(uint *)(*piVar3 + 0x118) = *(uint *)(*piVar3 + 0x118) | *(uint *)(*param_1 + 0x118);
      switch(param_1[0x1aa]) {
      case 0:
      case 5:
        piVar3[0x1a5] = 1;
        break;
      case 1:
        piVar3[0x1a5] = 3;
        break;
      case 2:
        piVar3[0x1a5] = 4;
        break;
      default:
        (*DAT_0019f794)(2,"aiscript:  invalid Move To Position value!");
        break;
      case 4:
        UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar3,*param_1 + 8);
        *(undefined4 *)(*piVar3 + 0xac) = *(undefined4 *)(*param_1 + 0x54);
        iVar1 = *piVar3;
        *(undefined4 *)(iVar1 + 0x5c) = 0;
        *(undefined4 *)(iVar1 + 0x60) = 0;
        *(undefined4 *)(iVar1 + 100) = 0;
        iVar1 = *piVar3;
        *(undefined4 *)(iVar1 + 0x20) = 0;
        *(undefined4 *)(iVar1 + 0x24) = 0;
        *(undefined4 *)(iVar1 + 0x28) = 0;
        *(byte *)(*piVar3 + 0x118) = *(byte *)(*piVar3 + 0x118) | 0x20;
        *(undefined4 *)(*piVar3 + 0x54) = *(undefined4 *)(*param_1 + 0x54);
        piVar3[0x1a5] = 1;
        param_1[0x1af] = (int)(*gpGlobals + 1e+06);
        *(byte *)(*piVar3 + 0x1a5) = *(byte *)(*piVar3 + 0x1a5) & 0xfd;
      }
      (*DAT_0019f794)(2,"\"%s\" found and used\n",*(int *)(*piVar3 + 0x1cc) + (int)gpGlobals[0x26]);
      piVar3[0x15e] = 6;
      if (piVar3[0x15d] == 6) {
        uVar2 = (**(code **)(piVar3[0x115] + 0x174))(piVar3,0x28);
        ChangeSchedule__12CBaseMonsterP10Schedule_t(piVar3,uVar2);
      }
    }
  }
  return;
}


