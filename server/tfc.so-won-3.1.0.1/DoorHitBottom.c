// DoorHitBottom__9CBaseDoor  @ 000945b8
void DoorHitBottom__9CBaseDoor(int *param_1)

{
  undefined4 uVar1;
  int **ppiVar2;
  int *piStack_20;
  undefined1 local_c [12];
  
  piStack_20 = (int *)0x945c3;
  ppiVar2 = (int **)&stack0xffffffe4;
  if ((-1 < *(int *)(*param_1 + 0x1a0)) &&
     (ppiVar2 = (int **)&stack0xffffffe4, (float)param_1[0x129] < *gpGlobals)) {
    piStack_20 = param_1;
    (**(code **)(param_1[0xf5] + 0xc4))(local_c);
    (*DAT_001a802c)(2,0,(short)param_1[300],0,local_c,&g_vecZero,0,0,
                    CONCAT11(*(undefined1 *)((int)param_1 + 0x479),
                             *(undefined1 *)((int)param_1 + 0x47a)),0,0,0);
    ppiVar2 = &piStack_20;
  }
  param_1[0xfd] = 1;
  *(undefined1 *)(param_1 + 0x12a) = 0;
  *(undefined1 *)((int)param_1 + 0x4a9) = 0;
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
  *(int **)((int)ppiVar2 + -0xc) = param_1 + 0x112;
  *(undefined4 *)((int)ppiVar2 + -0x10) = 0x946a4;
  uVar1 = __opP11CBaseEntity__7EHANDLE();
  *(undefined4 *)((int)ppiVar2 + -0xc) = uVar1;
  *(int **)((int)ppiVar2 + -0x10) = param_1;
  *(undefined4 *)((int)ppiVar2 + -0x14) = 0x946ae;
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf();
  if ((*(int *)(*param_1 + 0x1d0) != 0) && (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0)) {
    *(undefined4 *)((int)ppiVar2 + -4) = 0;
    *(undefined4 *)((int)ppiVar2 + -8) = 3;
    *(int **)((int)ppiVar2 + -0xc) = param_1;
    *(int **)((int)ppiVar2 + -0x10) = param_1 + 0x112;
    *(undefined4 *)((int)ppiVar2 + -0x14) = 0x946d3;
    uVar1 = __opP11CBaseEntity__7EHANDLE();
    *(undefined4 *)((int)ppiVar2 + -0x10) = uVar1;
    *(int *)((int)ppiVar2 + -0x14) = *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26];
    *(undefined4 *)((int)ppiVar2 + -0x18) = 0x946f3;
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf();
  }
  return;
}


