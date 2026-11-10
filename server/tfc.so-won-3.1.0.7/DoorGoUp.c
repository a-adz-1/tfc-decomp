// DoorGoUp__9CBaseDoor  @ 0009e4a4
void DoorGoUp__9CBaseDoor(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int **ppiVar9;
  int *piStack_5c;
  undefined1 local_c [12];
  
  piStack_5c = (int *)0x9e4b0;
  ppiVar9 = (int **)&stack0xffffffa8;
  if (((-1 < *(int *)(*param_1 + 0x1a0)) &&
      (ppiVar9 = (int **)&stack0xffffffa8, (char)param_1[0x146] == '\0')) &&
     (ppiVar9 = (int **)&stack0xffffffa8, (float)param_1[0x145] < *gpGlobals)) {
    piStack_5c = param_1;
    (**(code **)(param_1[0x111] + 0xcc))(local_c);
    (*DAT_001c120c)(2,0,*(undefined2 *)((int)param_1 + 0x51a),0,local_c,&g_vecZero,0,0,
                    CONCAT11(*(undefined1 *)((int)param_1 + 0x4e9),
                             *(undefined1 *)((int)param_1 + 0x4ea)),0,0,0);
    ppiVar9 = &piStack_5c;
  }
  param_1[0x119] = 2;
  param_1[0x130] = -0x10000;
  param_1[0x131] = (int)DoorHitTop__9CBaseDoor;
  iVar7 = *(int *)*param_1;
  fVar4 = gpGlobals[0x26];
  *(char **)((int)ppiVar9 + -4) = "func_door_rotating";
  *(int *)((int)ppiVar9 + -8) = iVar7 + (int)fVar4;
  *(undefined4 *)((int)ppiVar9 + -0xc) = 0x9e588;
  iVar7 = strcmp(*(char **)((int)ppiVar9 + -8),*(char **)((int)ppiVar9 + -4));
  if (iVar7 == 0) {
    *(undefined4 *)((int)ppiVar9 + 0x14) = 0x3f800000;
    *(int **)((int)ppiVar9 + -4) = param_1 + 0x12e;
    *(undefined4 *)((int)ppiVar9 + -8) = 0x9e5a7;
    iVar7 = __opP11CBaseEntity__7EHANDLE();
    if (iVar7 != 0) {
      *(int **)((int)ppiVar9 + -4) = param_1 + 0x12e;
      *(undefined4 *)((int)ppiVar9 + -8) = 0x9e5b8;
      puVar8 = (undefined4 *)__rf__7EHANDLE();
      *(undefined4 *)((int)ppiVar9 + 0x18) = *puVar8;
      iVar7 = *param_1;
      if ((*(byte *)(iVar7 + 0x1a0) & 0x10) == 0) {
        fVar4 = *(float *)(iVar7 + 0x48);
        if ((byte)(0.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar4 == 0.0) << 0xe) >> 8)) != 0x40) {
          iVar5 = *(int *)((int)ppiVar9 + 0x18);
          iVar6 = *(int *)((int)ppiVar9 + 0x18);
          fVar4 = *(float *)(iVar5 + 0xc);
          fVar1 = *(float *)(iVar7 + 0xc);
          fVar2 = *(float *)(iVar5 + 0x10);
          fVar3 = *(float *)(iVar7 + 0x10);
          *(float *)((int)ppiVar9 + 0x4c) = *(float *)(iVar6 + 8) - *(float *)(iVar7 + 8);
          *(float *)((int)ppiVar9 + 0x50) = fVar4 - fVar1;
          *(float *)((int)ppiVar9 + 0x54) = fVar2 - fVar3;
          *(undefined4 *)((int)ppiVar9 + 0x40) = *(undefined4 *)(iVar6 + 0x50);
          *(undefined4 *)((int)ppiVar9 + 0x44) = *(undefined4 *)(iVar6 + 0x54);
          *(undefined4 *)((int)ppiVar9 + 0x48) = *(undefined4 *)(iVar6 + 0x58);
          *(undefined4 *)((int)ppiVar9 + 0x40) = 0;
          *(undefined4 *)((int)ppiVar9 + 0x48) = 0;
          *(undefined1 **)((int)ppiVar9 + 0x10) = (undefined1 *)((int)ppiVar9 + 0x40);
          *(undefined1 **)((int)ppiVar9 + -4) = (undefined1 *)((int)ppiVar9 + 0x40);
          *(undefined4 *)((int)ppiVar9 + -8) = 0x9e650;
          UTIL_MakeVectors__FRC6Vector();
          *(int *)((int)ppiVar9 + -8) = iVar6 + 0x50;
          *(undefined4 *)((int)ppiVar9 + -0xc) = 0x9e656;
          UTIL_MakeVectors__FRC6Vector();
          *(float ***)((int)ppiVar9 + 0x10) = &gpGlobals;
          *(float **)((int)ppiVar9 + 0x10) = gpGlobals;
          fVar4 = *(float *)(*(int *)((int)ppiVar9 + 0x10) + 0x28);
          fVar1 = gpGlobals[0xb];
          fVar2 = gpGlobals[0xc];
          *(float *)((int)ppiVar9 + 0x1c) = fVar4 * 10.0;
          *(float *)((int)ppiVar9 + 0x20) = fVar1 * 10.0;
          *(float *)((int)ppiVar9 + 0x24) = fVar2 * 10.0;
          fVar3 = *(float *)(*(int *)((int)ppiVar9 + 0x18) + 8) + fVar4 * 10.0;
          fVar2 = *(float *)(iVar5 + 0xc) + fVar1 * 10.0;
          fVar4 = *(float *)(iVar5 + 0x10);
          *(float *)((int)ppiVar9 + 0x28) = fVar3;
          *(float *)((int)ppiVar9 + 0x2c) = fVar2;
          *(float *)((int)ppiVar9 + 0x30) = fVar4 + *(float *)((int)ppiVar9 + 0x24);
          fVar2 = fVar2 - *(float *)(*param_1 + 0xc);
          fVar1 = *(float *)(*param_1 + 0x10);
          *(float *)((int)ppiVar9 + 0x34) = fVar3 - *(float *)(*param_1 + 8);
          *(float *)((int)ppiVar9 + 0x38) = fVar2;
          *(float *)((int)ppiVar9 + 0x3c) = (fVar4 + *(float *)((int)ppiVar9 + 0x24)) - fVar1;
          if (*(float *)((int)ppiVar9 + 0x4c) * fVar2 -
              *(float *)((int)ppiVar9 + 0x50) * *(float *)((int)ppiVar9 + 0x34) < 0.0) {
            *(undefined4 *)((int)ppiVar9 + 0x14) = 0xbf800000;
          }
        }
      }
    }
    fVar4 = (float)param_1[0x12a];
    fVar1 = (float)param_1[299];
    *(float *)((int)ppiVar9 + 0x1c) = *(float *)((int)ppiVar9 + 0x14) * (float)param_1[0x129];
    *(float *)((int)ppiVar9 + 0x20) = *(float *)((int)ppiVar9 + 0x14) * fVar4;
    *(float *)((int)ppiVar9 + 0x24) = *(float *)((int)ppiVar9 + 0x14) * fVar1;
    *(undefined4 *)((int)ppiVar9 + -4) = *(undefined4 *)(*param_1 + 0x1f8);
    *(undefined1 **)((int)ppiVar9 + -8) = (undefined1 *)((int)ppiVar9 + 0x1c);
    *(int **)((int)ppiVar9 + -0xc) = param_1;
    *(undefined4 *)((int)ppiVar9 + -0x10) = 0x9e755;
    AngularMove__11CBaseToggleG6Vectorf();
  }
  else {
    *(int *)((int)ppiVar9 + 0x1c) = param_1[0x123];
    *(int *)((int)ppiVar9 + 0x20) = param_1[0x124];
    *(int *)((int)ppiVar9 + 0x24) = param_1[0x125];
    *(undefined4 *)((int)ppiVar9 + -4) = *(undefined4 *)(*param_1 + 0x1f8);
    *(undefined1 **)((int)ppiVar9 + -8) = (undefined1 *)((int)ppiVar9 + 0x1c);
    *(int **)((int)ppiVar9 + -0xc) = param_1;
    *(undefined4 *)((int)ppiVar9 + -0x10) = 0x9e790;
    LinearMove__11CBaseToggleG6Vectorf();
  }
  return;
}


