// DoorHitTop__9CBaseDoor  @ 0009429c
void DoorHitTop__9CBaseDoor(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int **ppiVar3;
  int *piStack_28;
  undefined1 auStack_c [12];
  
  piStack_28 = (int *)0x942a7;
  ppiVar3 = (int **)&stack0xffffffdc;
  if ((-1 < *(int *)(*param_1 + 0x1a0)) &&
     ((((float)param_1[0x129] < *gpGlobals && ((char)param_1[0x12a] == '\0')) ||
      (ppiVar3 = (int **)&stack0xffffffdc, *(char *)((int)param_1 + 0x4a9) == '\0')))) {
    *(undefined1 *)((int)param_1 + 0x4a9) = 1;
    piStack_28 = param_1;
    (**(code **)(param_1[0xf5] + 0xc4))(auStack_c);
    (*DAT_001a802c)(2,0,*(undefined2 *)((int)param_1 + 0x4ae),0,auStack_c,&g_vecZero,0,0,
                    CONCAT11(*(undefined1 *)((int)param_1 + 0x479),
                             *(undefined1 *)((int)param_1 + 0x47a)),0,0,0);
    ppiVar3 = &piStack_28;
  }
  param_1[0xfd] = 0;
  *(undefined1 *)(param_1 + 0x12a) = 0;
  if ((*(byte *)(*param_1 + 0x1a0) & 0x20) == 0) {
    *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + (float)param_1[0x100];
    *(undefined2 *)((int)ppiVar3 + 0xc) = 0;
    *(uint *)((int)ppiVar3 + 0xc) = *(uint *)((int)ppiVar3 + 0xc) | 0xffff0000;
    *(code **)((int)ppiVar3 + 0x10) = DoorGoDown__9CBaseDoor;
    iVar1 = *(int *)((int)ppiVar3 + 0x10);
    param_1[3] = *(int *)((int)ppiVar3 + 0xc);
    param_1[4] = iVar1;
    if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x100]) << 10) >> 8) |
              (byte)((ushort)((ushort)((float)param_1[0x100] == -1.0) << 0xe) >> 8)) == 0x40) {
      *(undefined4 *)(*param_1 + 0x104) = 0xbf800000;
    }
  }
  else if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
    param_1[5] = -0x10000;
    param_1[6] = (int)DoorTouch__9CBaseDoorP11CBaseEntity;
  }
  if ((*(int *)(*param_1 + 0x1d0) != 0) && ((*(byte *)(*param_1 + 0x1a0) & 1) != 0)) {
    *(undefined4 *)((int)ppiVar3 + -4) = 0;
    *(undefined4 *)((int)ppiVar3 + -8) = 3;
    *(int **)((int)ppiVar3 + -0xc) = param_1;
    *(int **)((int)ppiVar3 + -0x10) = param_1 + 0x112;
    *(undefined4 *)((int)ppiVar3 + -0x14) = 0x94412;
    uVar2 = __opP11CBaseEntity__7EHANDLE();
    *(undefined4 *)((int)ppiVar3 + -0x10) = uVar2;
    *(int *)((int)ppiVar3 + -0x14) = *(int *)(*param_1 + 0x1d0) + (int)gpGlobals[0x26];
    *(undefined4 *)((int)ppiVar3 + -0x18) = 0x94432;
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf();
  }
  *(undefined4 *)((int)ppiVar3 + -4) = 0;
  *(undefined4 *)((int)ppiVar3 + -8) = 3;
  *(int **)((int)ppiVar3 + -0xc) = param_1 + 0x112;
  *(undefined4 *)((int)ppiVar3 + -0x10) = 0x94445;
  uVar2 = __opP11CBaseEntity__7EHANDLE();
  *(undefined4 *)((int)ppiVar3 + -0xc) = uVar2;
  *(int **)((int)ppiVar3 + -0x10) = param_1;
  *(undefined4 *)((int)ppiVar3 + -0x14) = 0x9444f;
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf();
  return;
}


