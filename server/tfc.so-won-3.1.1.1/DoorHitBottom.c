// DoorHitBottom__9CBaseDoor  @ 0009e088
void DoorHitBottom__9CBaseDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int **ppiVar4;
  int *piStack_24;
  undefined1 local_10 [12];
  
  piStack_24 = (int *)0x9e096;
  ppiVar4 = (int **)&stack0xffffffe0;
  if (-1 < *(int *)(*param_1 + 0x1a0)) {
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x149];
    ppiVar4 = (int **)&stack0xffffffe0;
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      piStack_24 = param_1;
      (**(code **)(param_1[0x115] + 0xcc))(local_10);
      (*DAT_0019f88c)(2,0,(short)param_1[0x14c],0,local_10,&g_vecZero,0,0,
                      CONCAT11(*(undefined1 *)((int)param_1 + 0x4f9),
                               *(undefined1 *)((int)param_1 + 0x4fa)),0,0,0);
      ppiVar4 = &piStack_24;
    }
  }
  param_1[0x11d] = 1;
  *(undefined1 *)(param_1 + 0x14a) = 0;
  *(undefined1 *)((int)param_1 + 0x529) = 0;
  if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)DoorTouch__9CBaseDoorP11CBaseEntity;
  }
  else {
    param_1[5] = 0;
    param_1[6] = 0;
  }
  *(undefined4 *)((int)ppiVar4 + -4) = 0;
  *(undefined4 *)((int)ppiVar4 + -8) = 3;
  *(int **)((int)ppiVar4 + -0xc) = param_1 + 0x132;
  *(undefined4 *)((int)ppiVar4 + -0x10) = 0x9e17c;
  uVar3 = __opP11CBaseEntity__7EHANDLE();
  *(undefined4 *)((int)ppiVar4 + -0xc) = uVar3;
  *(int **)((int)ppiVar4 + -0x10) = param_1;
  *(undefined4 *)((int)ppiVar4 + -0x14) = 0x9e186;
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf();
  if ((*(int *)(*param_1 + 0x1d0) != 0) && (((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) != 0)) {
    *(undefined4 *)((int)ppiVar4 + -4) = 0;
    *(undefined4 *)((int)ppiVar4 + -8) = 3;
    *(int **)((int)ppiVar4 + -0xc) = param_1;
    *(int **)((int)ppiVar4 + -0x10) = param_1 + 0x132;
    *(undefined4 *)((int)ppiVar4 + -0x14) = 0x9e1ab;
    uVar3 = __opP11CBaseEntity__7EHANDLE();
    *(undefined4 *)((int)ppiVar4 + -0x10) = uVar3;
    *(int *)((int)ppiVar4 + -0x14) = *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26];
    *(undefined4 *)((int)ppiVar4 + -0x18) = 0x9e1cb;
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf();
  }
  return;
}


