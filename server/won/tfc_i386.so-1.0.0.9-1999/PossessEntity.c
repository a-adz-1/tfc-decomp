// PossessEntity__12CCineMonster  @ 000e7430
void PossessEntity__12CCineMonster(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11e);
  piVar2 = (int *)0x0;
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*(int *)(iVar1 + 0x3c8) + 0x4c))(iVar1);
  }
  if (piVar2 == (int *)0x0) {
    return;
  }
  piVar2[1] = (int)param_1;
  piVar2[0x183] = (int)param_1;
  __as__7EHANDLEP11CBaseEntity(piVar2 + 0x11e,param_1);
  param_1[0x18d] = *(int *)(*piVar2 + 0xe8);
  param_1[0x18e] = *(int *)(*piVar2 + 0xec);
  param_1[399] = *(int *)(*piVar2 + 0xf8);
  *(uint *)(*piVar2 + 0xf8) = *(uint *)(*piVar2 + 0xf8) | *(uint *)(*param_1 + 0xf8);
  iVar1 = param_1[0x187];
  if (iVar1 == 1) {
    piVar2[0x182] = 3;
  }
  else {
    if (iVar1 < 2) {
      if (iVar1 == 0) {
        piVar2[0x182] = 1;
      }
      goto LAB_000e75d6;
    }
    if (iVar1 != 2) {
      if (iVar1 == 4) {
        UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar2,*param_1 + 8);
        *(undefined4 *)(*piVar2 + 0x8c) = *(undefined4 *)(*param_1 + 0x54);
        iVar1 = *piVar2;
        *(undefined4 *)(iVar1 + 0x5c) = 0;
        *(undefined4 *)(iVar1 + 0x60) = 0;
        *(undefined4 *)(iVar1 + 100) = 0;
        iVar1 = *piVar2;
        *(undefined4 *)(iVar1 + 0x20) = 0;
        *(undefined4 *)(iVar1 + 0x24) = 0;
        *(undefined4 *)(iVar1 + 0x28) = 0;
        *(byte *)(*piVar2 + 0xf8) = *(byte *)(*piVar2 + 0xf8) | 0x20;
        *(undefined4 *)(*piVar2 + 0x54) = *(undefined4 *)(*param_1 + 0x54);
        piVar2[0x182] = 1;
        param_1[0x18c] = (int)(*gpGlobals + 1e+06);
      }
      goto LAB_000e75d6;
    }
    piVar2[0x182] = 4;
  }
  DelayStart__12CCineMonsteri(param_1,1);
LAB_000e75d6:
  piVar2[0x13b] = 6;
  if (param_1[0x184] != 0) {
    (**(code **)(param_1[0xf2] + 0x218))(param_1,piVar2,param_1[0x184],0);
    iVar1 = strcmp((char *)((int)gpGlobals[0x26] + param_1[0x184]),
                   (char *)((int)gpGlobals[0x26] + param_1[0x185]));
    if (iVar1 == 0) {
      *(undefined4 *)(*piVar2 + 0x118) = 0;
    }
  }
  return;
}


// PossessEntity__7CCineAI  @ 000e7640
void PossessEntity__7CCineAI(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11e);
  piVar3 = (int *)0x0;
  if (iVar1 != 0) {
    piVar3 = (int *)(**(code **)(*(int *)(iVar1 + 0x3c8) + 0x4c))(iVar1);
  }
  if (piVar3 != (int *)0x0) {
    iVar1 = piVar3[0xf2];
    uVar2 = (**(code **)(param_1[0xf2] + 0x21c))(param_1,2);
    iVar1 = (**(code **)(iVar1 + 0x178))(piVar3,uVar2);
    if (iVar1 == 0) {
      (*DAT_001755b4)(2,"(AI)Can\'t possess entity %s\n",*(int *)*piVar3 + (int)gpGlobals[0x26]);
    }
    else {
      piVar3[1] = (int)param_1;
      piVar3[0x183] = (int)param_1;
      __as__7EHANDLEP11CBaseEntity(piVar3 + 0x11e,param_1);
      param_1[0x18d] = *(int *)(*piVar3 + 0xe8);
      param_1[0x18e] = *(int *)(*piVar3 + 0xec);
      param_1[399] = *(int *)(*piVar3 + 0xf8);
      *(uint *)(*piVar3 + 0xf8) = *(uint *)(*piVar3 + 0xf8) | *(uint *)(*param_1 + 0xf8);
      switch(param_1[0x187]) {
      case 0:
      case 5:
        piVar3[0x182] = 1;
        break;
      case 1:
        piVar3[0x182] = 3;
        break;
      case 2:
        piVar3[0x182] = 4;
        break;
      default:
        (*DAT_001755b4)(2,"aiscript:  invalid Move To Position value!");
        break;
      case 4:
        UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar3,*param_1 + 8);
        *(undefined4 *)(*piVar3 + 0x8c) = *(undefined4 *)(*param_1 + 0x54);
        iVar1 = *piVar3;
        *(undefined4 *)(iVar1 + 0x5c) = 0;
        *(undefined4 *)(iVar1 + 0x60) = 0;
        *(undefined4 *)(iVar1 + 100) = 0;
        iVar1 = *piVar3;
        *(undefined4 *)(iVar1 + 0x20) = 0;
        *(undefined4 *)(iVar1 + 0x24) = 0;
        *(undefined4 *)(iVar1 + 0x28) = 0;
        *(byte *)(*piVar3 + 0xf8) = *(byte *)(*piVar3 + 0xf8) | 0x20;
        *(undefined4 *)(*piVar3 + 0x54) = *(undefined4 *)(*param_1 + 0x54);
        piVar3[0x182] = 1;
        param_1[0x18c] = (int)(*gpGlobals + 1e+06);
        *(byte *)(*piVar3 + 0x185) = *(byte *)(*piVar3 + 0x185) & 0xfd;
      }
      (*DAT_001755b4)(2,"\"%s\" found and used\n",*(int *)(*piVar3 + 0x1ac) + (int)gpGlobals[0x26]);
      piVar3[0x13b] = 6;
      if (piVar3[0x13a] == 6) {
        uVar2 = (**(code **)(piVar3[0xf2] + 0x16c))(piVar3,0x28);
        ChangeSchedule__12CBaseMonsterP10Schedule_t(piVar3,uVar2);
      }
    }
  }
  return;
}


