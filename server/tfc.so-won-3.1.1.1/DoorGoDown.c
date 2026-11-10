// DoorGoDown__9CBaseDoor  @ 0009df2c
void DoorGoDown__9CBaseDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int **ppiVar4;
  int *piStack_24;
  int local_10;
  int local_c;
  int local_8;
  
  piStack_24 = (int *)0x9df3a;
  ppiVar4 = (int **)&stack0xffffffe0;
  if (-1 < *(int *)(*param_1 + 0x1a0)) {
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x149];
    ppiVar4 = (int **)&stack0xffffffe0;
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      piStack_24 = param_1;
      (**(code **)(param_1[0x115] + 0xcc))(&local_10);
      (*DAT_0019f88c)(2,0,(short)param_1[0x14b],0,&local_10,&g_vecZero,0,0,
                      CONCAT11(*(undefined1 *)((int)param_1 + 0x4f9),
                               *(undefined1 *)((int)param_1 + 0x4fa)),0,0,0);
      ppiVar4 = &piStack_24;
    }
  }
  param_1[0x11d] = 3;
  param_1[0x134] = -0x10000;
  param_1[0x135] = (int)DoorHitBottom__9CBaseDoor;
  iVar3 = *(int *)*param_1;
  fVar1 = gpGlobals[0x26];
  *(char **)((int)ppiVar4 + -4) = "func_door_rotating";
  *(int *)((int)ppiVar4 + -8) = iVar3 + (int)fVar1;
  *(undefined4 *)((int)ppiVar4 + -0xc) = 0x9e00a;
  iVar3 = strcmp(*(char **)((int)ppiVar4 + -8),*(char **)((int)ppiVar4 + -4));
  if (iVar3 == 0) {
    local_10 = param_1[0x12a];
    local_c = param_1[299];
    local_8 = param_1[300];
    *(undefined4 *)((int)ppiVar4 + -4) = *(undefined4 *)(*param_1 + 0x1f8);
    *(int **)((int)ppiVar4 + -8) = &local_10;
    *(int **)((int)ppiVar4 + -0xc) = param_1;
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x9e049;
    AngularMove__11CBaseToggleG6Vectorf();
  }
  else {
    local_10 = param_1[0x124];
    local_c = param_1[0x125];
    local_8 = param_1[0x126];
    *(undefined4 *)((int)ppiVar4 + -4) = *(undefined4 *)(*param_1 + 0x1f8);
    *(int **)((int)ppiVar4 + -8) = &local_10;
    *(int **)((int)ppiVar4 + -0xc) = param_1;
    *(undefined4 *)((int)ppiVar4 + -0x10) = 0x9e07c;
    LinearMove__11CBaseToggleG6Vectorf();
  }
  return;
}


