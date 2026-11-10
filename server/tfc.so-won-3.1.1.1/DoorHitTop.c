// DoorHitTop__9CBaseDoor  @ 0009dd6c
void DoorHitTop__9CBaseDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int **ppiVar5;
  int *piStack_2c;
  undefined1 local_10 [12];
  
  piStack_2c = (int *)0x9dd7a;
  ppiVar5 = (int **)&stack0xffffffd8;
  if (-1 < *(int *)(*param_1 + 0x1a0)) {
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x149];
    if (((0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) &&
        ((char)param_1[0x14a] == '\0')) ||
       (ppiVar5 = (int **)&stack0xffffffd8, *(char *)((int)param_1 + 0x529) == '\0')) {
      *(undefined1 *)((int)param_1 + 0x529) = 1;
      piStack_2c = param_1;
      (**(code **)(param_1[0x115] + 0xcc))(local_10);
      (*DAT_0019f88c)(2,0,*(undefined2 *)((int)param_1 + 0x52e),0,local_10,&g_vecZero,0,0,
                      CONCAT11(*(undefined1 *)((int)param_1 + 0x4f9),
                               *(undefined1 *)((int)param_1 + 0x4fa)),0,0,0);
      ppiVar5 = &piStack_2c;
    }
  }
  param_1[0x11d] = 0;
  iVar3 = *param_1;
  *(undefined1 *)(param_1 + 0x14a) = 0;
  if ((*(uint *)(iVar3 + 0x1a0) & 0x20) == 0) {
    *(float *)(iVar3 + 0x104) = *(float *)(iVar3 + 0x100) + (float)param_1[0x120];
    param_1[3] = -0x10000;
    param_1[4] = (int)DoorGoDown__9CBaseDoor;
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x120]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x120] == -1.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
    }
  }
  else if ((*(uint *)(iVar3 + 0x1a0) & 0x100) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)DoorTouch__9CBaseDoorP11CBaseEntity;
  }
  if ((*(int *)(*param_1 + 0x1d0) != 0) && ((*(byte *)(*param_1 + 0x1a0) & 1) != 0)) {
    *(undefined4 *)((int)ppiVar5 + -4) = 0;
    *(undefined4 *)((int)ppiVar5 + -8) = 3;
    *(int **)((int)ppiVar5 + -0xc) = param_1;
    *(int **)((int)ppiVar5 + -0x10) = param_1 + 0x132;
    *(undefined4 *)((int)ppiVar5 + -0x14) = 0x9dee3;
    uVar4 = __opP11CBaseEntity__7EHANDLE();
    *(undefined4 *)((int)ppiVar5 + -0x10) = uVar4;
    *(int *)((int)ppiVar5 + -0x14) = *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26];
    *(undefined4 *)((int)ppiVar5 + -0x18) = 0x9df03;
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf();
  }
  *(undefined4 *)((int)ppiVar5 + -4) = 0;
  *(undefined4 *)((int)ppiVar5 + -8) = 3;
  *(int **)((int)ppiVar5 + -0xc) = param_1 + 0x132;
  *(undefined4 *)((int)ppiVar5 + -0x10) = 0x9df16;
  uVar4 = __opP11CBaseEntity__7EHANDLE();
  *(undefined4 *)((int)ppiVar5 + -0xc) = uVar4;
  *(int **)((int)ppiVar5 + -0x10) = param_1;
  *(undefined4 *)((int)ppiVar5 + -0x14) = 0x9df20;
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf();
  return;
}


