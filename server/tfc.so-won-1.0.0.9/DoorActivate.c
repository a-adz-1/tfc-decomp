// DoorActivate__9CBaseDoor  @ 000a9d20
undefined4 DoorActivate__9CBaseDoor(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar2 = UTIL_IsMasterTriggered__Fi(param_1[0x11a]);
  if (iVar2 == 0) {
LAB_000a9d83:
    uVar3 = 0;
  }
  else {
    piVar1 = param_1 + 0x10f;
    iVar2 = __opP11CBaseEntity__7EHANDLE(piVar1);
    if (iVar2 != 0) {
      iVar2 = __rf__7EHANDLE(piVar1);
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x28))(iVar2);
      if (iVar2 == 2) {
        uVar3 = __opP11CBaseEntity__7EHANDLE(piVar1,0);
        iVar2 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,uVar3);
        if (iVar2 == 0) goto LAB_000a9d83;
      }
    }
    if (((*(byte *)(*param_1 + 0x180) & 0x20) == 0) || (param_1[0xfa] != 0)) {
      piVar1 = param_1 + 0x10f;
      iVar2 = __opP11CBaseEntity__7EHANDLE(piVar1);
      if (iVar2 != 0) {
        piVar4 = (int *)__rf__7EHANDLE(piVar1);
        if ((*(byte *)(*piVar4 + 0x184) & 8) != 0) {
          iVar2 = __rf__7EHANDLE(piVar1);
          (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x38))(iVar2,(float)*(byte *)(param_1 + 0x11b),0);
        }
      }
      PlayLockSounds__FP9entvars_tP10locksoundsii(*param_1,param_1 + 0x11c,0,0);
      DoorGoUp__9CBaseDoor(param_1);
    }
    else {
      DoorGoDown__9CBaseDoor(param_1);
    }
    uVar3 = 1;
  }
  return uVar3;
}


