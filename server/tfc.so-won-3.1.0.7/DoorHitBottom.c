// DoorHitBottom__9CBaseDoor  @ 0009eab8
void DoorHitBottom__9CBaseDoor(int *param_1)

{
  undefined4 uVar1;
  int **ppiVar2;
  int *piStack_20;
  undefined1 local_c [12];
  
  piStack_20 = (int *)0x9eac3;
  ppiVar2 = (int **)&stack0xffffffe4;
  if ((-1 < *(int *)(*param_1 + 0x1a0)) &&
     (ppiVar2 = (int **)&stack0xffffffe4, (float)param_1[0x145] < *gpGlobals)) {
    piStack_20 = param_1;
    (**(code **)(param_1[0x111] + 0xcc))(local_c);
    (*DAT_001c120c)(2,0,(short)param_1[0x148],0,local_c,&g_vecZero,0,0,
                    CONCAT11(*(undefined1 *)((int)param_1 + 0x4e9),
                             *(undefined1 *)((int)param_1 + 0x4ea)),0,0,0);
    ppiVar2 = &piStack_20;
  }
  param_1[0x119] = 1;
  *(undefined1 *)(param_1 + 0x146) = 0;
  *(undefined1 *)((int)param_1 + 0x519) = 0;
  if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)DoorTouch__9CBaseDoorP11CBaseEntity;
  }
  else {
    param_1[5] = 0;
    param_1[6] = 0;
  }
  *(undefined4 *)((int)ppiVar2 + -4) = 0;
  *(undefined4 *)((int)ppiVar2 + -8) = 3;
  *(int **)((int)ppiVar2 + -0xc) = param_1 + 0x12e;
  *(undefined4 *)((int)ppiVar2 + -0x10) = 0x9eba4;
  uVar1 = __opP11CBaseEntity__7EHANDLE();
  *(undefined4 *)((int)ppiVar2 + -0xc) = uVar1;
  *(int **)((int)ppiVar2 + -0x10) = param_1;
  *(undefined4 *)((int)ppiVar2 + -0x14) = 0x9ebae;
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf();
  if ((*(int *)(*param_1 + 0x1d0) != 0) && (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0)) {
    *(undefined4 *)((int)ppiVar2 + -4) = 0;
    *(undefined4 *)((int)ppiVar2 + -8) = 3;
    *(int **)((int)ppiVar2 + -0xc) = param_1;
    *(int **)((int)ppiVar2 + -0x10) = param_1 + 0x12e;
    *(undefined4 *)((int)ppiVar2 + -0x14) = 0x9ebd3;
    uVar1 = __opP11CBaseEntity__7EHANDLE();
    *(undefined4 *)((int)ppiVar2 + -0x10) = uVar1;
    *(int *)((int)ppiVar2 + -0x14) = *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26];
    *(undefined4 *)((int)ppiVar2 + -0x18) = 0x9ebf3;
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf();
  }
  return;
}


