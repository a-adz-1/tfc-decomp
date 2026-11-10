// DoorGoDown__9CBaseDoor  @ 0009445c
void DoorGoDown__9CBaseDoor(int *param_1)

{
  float fVar1;
  int iVar2;
  int **ppiVar3;
  int *piStack_20;
  undefined1 local_c [12];
  
  piStack_20 = (int *)0x94467;
  ppiVar3 = (int **)&stack0xffffffe4;
  if ((-1 < *(int *)(*param_1 + 0x1a0)) &&
     (ppiVar3 = (int **)&stack0xffffffe4, (float)param_1[0x129] < *gpGlobals)) {
    piStack_20 = param_1;
    (**(code **)(param_1[0xf5] + 0xc4))(local_c);
    (*DAT_001a802c)(2,0,(short)param_1[299],0,local_c,&g_vecZero,0,0,
                    CONCAT11(*(undefined1 *)((int)param_1 + 0x479),
                             *(undefined1 *)((int)param_1 + 0x47a)),0,0,0);
    ppiVar3 = &piStack_20;
  }
  param_1[0xfd] = 3;
  param_1[0x114] = -0x10000;
  param_1[0x115] = (int)DoorHitBottom__9CBaseDoor;
  iVar2 = *(int *)*param_1;
  fVar1 = gpGlobals[0x26];
  *(char **)((int)ppiVar3 + -4) = "func_door_rotating";
  *(int *)((int)ppiVar3 + -8) = iVar2 + (int)fVar1;
  *(undefined4 *)((int)ppiVar3 + -0xc) = 0x94534;
  iVar2 = strcmp(*(char **)((int)ppiVar3 + -8),*(char **)((int)ppiVar3 + -4));
  if (iVar2 == 0) {
    *(int *)((int)ppiVar3 + 0x10) = param_1[0x10a];
    *(int *)((int)ppiVar3 + 0x14) = param_1[0x10b];
    *(int *)((int)ppiVar3 + 0x18) = param_1[0x10c];
    *(undefined4 *)((int)ppiVar3 + -4) = *(undefined4 *)(*param_1 + 0x1f8);
    *(undefined1 **)((int)ppiVar3 + -8) = (undefined1 *)((int)ppiVar3 + 0x10);
    *(int **)((int)ppiVar3 + -0xc) = param_1;
    *(undefined4 *)((int)ppiVar3 + -0x10) = 0x94572;
    AngularMove__11CBaseToggleG6Vectorf();
  }
  else {
    *(int *)((int)ppiVar3 + 0x10) = param_1[0x104];
    *(int *)((int)ppiVar3 + 0x14) = param_1[0x105];
    *(int *)((int)ppiVar3 + 0x18) = param_1[0x106];
    *(undefined4 *)((int)ppiVar3 + -4) = *(undefined4 *)(*param_1 + 0x1f8);
    *(undefined1 **)((int)ppiVar3 + -8) = (undefined1 *)((int)ppiVar3 + 0x10);
    *(int **)((int)ppiVar3 + -0xc) = param_1;
    *(undefined4 *)((int)ppiVar3 + -0x10) = 0x945ab;
    LinearMove__11CBaseToggleG6Vectorf();
  }
  return;
}


