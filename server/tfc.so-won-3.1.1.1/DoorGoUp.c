// DoorGoUp__9CBaseDoor  @ 0009da78
void DoorGoUp__9CBaseDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int **ppiVar6;
  int *piStack_80;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  
  piStack_80 = (int *)0x9da86;
  ppiVar6 = (int **)&stack0xffffff84;
  if ((-1 < *(int *)(*param_1 + 0x1a0)) &&
     (ppiVar6 = (int **)&stack0xffffff84, (char)param_1[0x14a] == '\0')) {
    fVar1 = *gpGlobals;
    fVar2 = (float)param_1[0x149];
    ppiVar6 = (int **)&stack0xffffff84;
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      piStack_80 = param_1;
      (**(code **)(param_1[0x115] + 0xcc))(&local_10);
      (*DAT_0019f88c)(2,0,*(undefined2 *)((int)param_1 + 0x52a),0,&local_10,&g_vecZero,0,0,
                      CONCAT11(*(undefined1 *)((int)param_1 + 0x4f9),
                               *(undefined1 *)((int)param_1 + 0x4fa)),0,0,0);
      ppiVar6 = &piStack_80;
    }
  }
  param_1[0x11d] = 2;
  param_1[0x134] = -0x10000;
  param_1[0x135] = (int)DoorHitTop__9CBaseDoor;
  iVar4 = *(int *)*param_1;
  fVar1 = gpGlobals[0x26];
  *(char **)((int)ppiVar6 + -4) = "func_door_rotating";
  *(int *)((int)ppiVar6 + -8) = iVar4 + (int)fVar1;
  *(undefined4 *)((int)ppiVar6 + -0xc) = 0x9db7f;
  iVar4 = strcmp(*(char **)((int)ppiVar6 + -8),*(char **)((int)ppiVar6 + -4));
  if (iVar4 == 0) {
    local_44 = 1.0;
    *(int **)((int)ppiVar6 + -4) = param_1 + 0x132;
    *(undefined4 *)((int)ppiVar6 + -8) = 0x9dba2;
    iVar4 = __opP11CBaseEntity__7EHANDLE();
    if (iVar4 != 0) {
      *(int **)((int)ppiVar6 + -4) = param_1 + 0x132;
      *(undefined4 *)((int)ppiVar6 + -8) = 0x9dbb3;
      piVar5 = (int *)__rf__7EHANDLE();
      iVar4 = *piVar5;
      iVar3 = *param_1;
      if ((*(byte *)(iVar3 + 0x1a0) & 0x10) == 0) {
        fVar1 = *(float *)(iVar3 + 0x48);
        if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
          local_10 = *(float *)(iVar4 + 8) - *(float *)(iVar3 + 8);
          local_c = *(float *)(iVar4 + 0xc) - *(float *)(iVar3 + 0xc);
          local_8 = *(float *)(iVar4 + 0x10) - *(float *)(iVar3 + 0x10);
          local_18 = *(undefined4 *)(iVar4 + 0x54);
          local_1c = 0;
          local_14 = 0;
          *(undefined4 **)((int)ppiVar6 + -4) = &local_1c;
          *(undefined4 *)((int)ppiVar6 + -8) = 0x9dc37;
          UTIL_MakeVectors__FRC6Vector();
          *(int *)((int)ppiVar6 + -8) = iVar4 + 0x50;
          *(undefined4 *)((int)ppiVar6 + -0xc) = 0x9dc3d;
          UTIL_MakeVectors__FRC6Vector();
          local_34 = gpGlobals[10] * 10.0 + *(float *)(iVar4 + 8);
          local_30 = gpGlobals[0xb] * 10.0 + *(float *)(iVar4 + 0xc);
          local_2c = gpGlobals[0xc] * 10.0 + *(float *)(iVar4 + 0x10);
          iVar4 = *param_1;
          local_28 = local_34 - *(float *)(iVar4 + 8);
          local_24 = local_30 - *(float *)(iVar4 + 0xc);
          local_20 = local_2c - *(float *)(iVar4 + 0x10);
          if (local_24 * local_10 - local_28 * local_c < 0.0) {
            local_44 = -1.0;
          }
        }
      }
    }
    local_40 = local_44 * (float)param_1[0x12d];
    local_3c = local_44 * (float)param_1[0x12e];
    local_38 = local_44 * (float)param_1[0x12f];
    *(undefined4 *)((int)ppiVar6 + -4) = *(undefined4 *)(*param_1 + 0x1f8);
    *(float **)((int)ppiVar6 + -8) = &local_40;
    *(int **)((int)ppiVar6 + -0xc) = param_1;
    *(undefined4 *)((int)ppiVar6 + -0x10) = 0x9dd27;
    AngularMove__11CBaseToggleG6Vectorf();
  }
  else {
    local_40 = (float)param_1[0x127];
    local_3c = (float)param_1[0x128];
    local_38 = (float)param_1[0x129];
    *(undefined4 *)((int)ppiVar6 + -4) = *(undefined4 *)(*param_1 + 0x1f8);
    *(float **)((int)ppiVar6 + -8) = &local_40;
    *(int **)((int)ppiVar6 + -0xc) = param_1;
    *(undefined4 *)((int)ppiVar6 + -0x10) = 0x9dd62;
    LinearMove__11CBaseToggleG6Vectorf();
  }
  return;
}


