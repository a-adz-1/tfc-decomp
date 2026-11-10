// PossessEntity__12CCineMonster  @ 000dc31c
void PossessEntity__12CCineMonster(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
  piVar2 = (int *)0x0;
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*(int *)(iVar1 + 0x3d4) + 0x4c))(iVar1);
  }
  if (piVar2 == (int *)0x0) {
    return;
  }
  piVar2[1] = (int)param_1;
  piVar2[0x186] = (int)param_1;
  __as__7EHANDLEP11CBaseEntity(piVar2 + 0x121,param_1);
  param_1[400] = *(int *)(*piVar2 + 0x108);
  param_1[0x191] = *(int *)(*piVar2 + 0x10c);
  param_1[0x192] = *(int *)(*piVar2 + 0x118);
  *(uint *)(*piVar2 + 0x118) = *(uint *)(*piVar2 + 0x118) | *(uint *)(*param_1 + 0x118);
  switch(param_1[0x18a]) {
  case 0:
    piVar2[0x185] = 1;
    break;
  case 1:
    piVar2[0x185] = 3;
    goto LAB_000dc40a;
  case 2:
    piVar2[0x185] = 4;
LAB_000dc40a:
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
    piVar2[0x185] = 1;
    param_1[399] = (int)(*gpGlobals + 1e+06);
  }
  piVar2[0x13e] = 6;
  if (param_1[0x187] != 0) {
    (**(code **)(param_1[0xf5] + 0x218))(param_1,piVar2,param_1[0x187],0);
    iVar1 = strcmp((char *)((int)gpGlobals[0x26] + param_1[0x187]),
                   (char *)((int)gpGlobals[0x26] + param_1[0x188]));
    if (iVar1 == 0) {
      *(undefined4 *)(*piVar2 + 0x138) = 0;
    }
  }
  return;
}


// PossessEntity__7CCineAI  @ 000dc540
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PossessEntity__7CCineAI(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
  piVar3 = (int *)0x0;
  if (iVar1 != 0) {
    piVar3 = (int *)(**(code **)(*(int *)(iVar1 + 0x3d4) + 0x4c))(iVar1);
  }
  if (piVar3 != (int *)0x0) {
    iVar1 = piVar3[0xf5];
    uVar2 = (**(code **)(param_1[0xf5] + 0x21c))(param_1,2);
    iVar1 = (**(code **)(iVar1 + 0x178))(piVar3,uVar2);
    if (iVar1 == 0) {
      (*DAT_001a7f34)(2,"(AI)Can\'t possess entity %s\n",*(int *)*piVar3 + (int)gpGlobals[0x26]);
    }
    else {
      piVar3[1] = (int)param_1;
      piVar3[0x186] = (int)param_1;
      __as__7EHANDLEP11CBaseEntity(piVar3 + 0x121,param_1);
      param_1[400] = *(int *)(*piVar3 + 0x108);
      param_1[0x191] = *(int *)(*piVar3 + 0x10c);
      param_1[0x192] = *(int *)(*piVar3 + 0x118);
      *(uint *)(*piVar3 + 0x118) = *(uint *)(*piVar3 + 0x118) | *(uint *)(*param_1 + 0x118);
      switch(param_1[0x18a]) {
      case 0:
      case 5:
        piVar3[0x185] = 1;
        break;
      case 1:
        piVar3[0x185] = 3;
        break;
      case 2:
        piVar3[0x185] = 4;
        break;
      default:
        (*DAT_001a7f34)(2,"aiscript:  invalid Move To Position value!");
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
        piVar3[0x185] = 1;
        param_1[399] = (int)((float)_FUN_0013bec0 + *gpGlobals);
        *(byte *)(*piVar3 + 0x1a5) = *(byte *)(*piVar3 + 0x1a5) & 0xfd;
      }
      (*DAT_001a7f34)(2,"\"%s\" found and used\n",*(int *)(*piVar3 + 0x1cc) + (int)gpGlobals[0x26]);
      piVar3[0x13e] = 6;
      if (piVar3[0x13d] == 6) {
        uVar2 = (**(code **)(piVar3[0xf5] + 0x16c))(piVar3,0x28);
        ChangeSchedule__12CBaseMonsterP10Schedule_t(piVar3,uVar2);
      }
    }
  }
  return;
}


