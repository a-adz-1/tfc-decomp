// PlayerUse__11CBasePlayer  @ 000d6c88
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PlayerUse__11CBasePlayer(int *param_1)

{
  code *pcVar1;
  double dVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int **ppiVar10;
  int *piVar11;
  undefined2 in_FPUControlWord;
  int *local_70;
  int local_6c;
  int *piStack_68;
  int local_64;
  int local_54;
  float local_48;
  int *local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  if (*(int *)(*param_1 + 0x244) != 0) {
    return;
  }
  if (((param_1[0x1b6] | *(uint *)(*param_1 + 0x180) | param_1[0x1b7]) & 0x20) == 0) {
    return;
  }
  if ((param_1[0x1b6] & 0x20U) != 0) {
    piVar11 = param_1 + 0x223;
    piStack_68 = (int *)0xd6ce0;
    local_64 = (int)piVar11;
    iVar4 = __opP11CBaseEntity__7EHANDLE();
    if (iVar4 != 0) {
      piStack_68 = (int *)0xd6ced;
      local_64 = (int)piVar11;
      iVar4 = __rf__7EHANDLE();
      piStack_68 = (int *)0x0;
      local_6c = 0;
      local_70 = param_1;
      (**(code **)(*(int *)(iVar4 + 0x454) + 0xb8))(iVar4,param_1);
      __as__7EHANDLEP11CBaseEntity(piVar11,0);
      return;
    }
    if ((param_1[0x1c3] & 2U) != 0) {
      param_1[0x1c3] = param_1[0x1c3] & 0xfffffffd;
      param_1[0x221] = 0xc0;
      return;
    }
    iVar4 = *(int *)(*param_1 + 0x19c);
    if (iVar4 == 0) {
      local_64 = 0;
      piStack_68 = (int *)0xd6d54;
      iVar4 = (*DAT_0019f7b4)();
      if (iVar4 != 0) goto LAB_000d6d5d;
      piVar11 = (int *)0x0;
    }
    else {
LAB_000d6d5d:
      piVar11 = *(int **)(iVar4 + 0x7c);
    }
    if (((piVar11 != (int *)0x0) && ((*(byte *)(*param_1 + 0x180) & 2) == 0)) &&
       ((*(byte *)(*param_1 + 0x1a5) & 2) != 0)) {
      piStack_68 = (int *)0xd6d96;
      local_64 = (int)piVar11;
      uVar5 = (**(code **)(piVar11[0x115] + 0x20))();
      if ((uVar5 & 0x40) != 0) {
        local_64 = *param_1;
        local_6c = 0xd6db3;
        piStack_68 = piVar11;
        iVar4 = (**(code **)(piVar11[0x115] + 0x84))();
        if (iVar4 != 0) {
          *(byte *)(param_1 + 0x1c3) = *(byte *)(param_1 + 0x1c3) | 2;
          _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
          local_10 = (int)ROUND(*(float *)(*piVar11 + 0x1f8));
          dVar2 = (double)local_10 / (double)*(int *)(*piVar11 + 0x184);
          if (local_10 < 0) {
            uVar5 = 5;
          }
          else if (local_10 == 0) {
            uVar5 = 1;
          }
          else if ((byte)((_FUN_001503e0 < dVar2 |
                           (byte)((ushort)((ushort)(NAN(_FUN_001503e0) || NAN(dVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(_FUN_001503e0 == dVar2) << 0xe) >> 8)) - 1) <
                   0x40) {
            uVar5 = 4;
            if (0x3f < (byte)((0.66 < dVar2 | (byte)((ushort)((ushort)NAN(dVar2) << 10) >> 8) |
                              (byte)((ushort)((ushort)(dVar2 == 0.66) << 0xe) >> 8)) - 1)) {
              uVar5 = 3;
            }
          }
          else {
            uVar5 = 2;
          }
          param_1[0x221] = uVar5 | 0xc0;
          uVar7 = *(undefined4 *)(*param_1 + 0x208);
          local_64 = 100;
          piStack_68 = (int *)0x0;
          local_70 = (int *)0x3f4ccccd;
          ppiVar10 = &local_70;
          pcVar6 = "plats/train_use1.wav";
          local_6c = (int)local_70;
          goto LAB_000d70f9;
        }
      }
    }
  }
  piVar11 = (int *)0x0;
  local_44 = (int *)0x0;
  local_48 = 0.7;
  local_64 = *param_1 + 0x74;
  piStack_68 = (int *)0xd6e9b;
  UTIL_MakeVectors__FRC6Vector();
  puVar9 = &stack0xffffffa0;
  while( true ) {
    *(undefined4 *)(puVar9 + -4) = 0x42800000;
    *(int *)(puVar9 + -8) = *param_1 + 8;
    *(int **)(puVar9 + -0xc) = piVar11;
    *(undefined4 *)(puVar9 + -0x10) = 0xd6fd9;
    piVar11 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
    if (piVar11 == (int *)0x0) break;
    iVar4 = piVar11[0x115];
    *(int **)(puVar9 + -4) = piVar11;
    pcVar1 = *(code **)(iVar4 + 0x20);
    *(undefined4 *)(puVar9 + -8) = 0xd6ebc;
    uVar5 = (*pcVar1)();
    if ((uVar5 & 0x38) != 0) {
      *(int *)(puVar9 + -4) = *piVar11;
      *(float **)(puVar9 + -8) = &local_34;
      *(undefined4 *)(puVar9 + -0xc) = 0xd6ed3;
      VecBModelOrigin__FP9entvars_s();
      iVar4 = *param_1;
      local_40 = *(float *)(iVar4 + 8) + *(float *)(iVar4 + 0x174);
      local_3c = *(float *)(*param_1 + 0xc) + *(float *)(iVar4 + 0x178);
      local_38 = *(float *)(*param_1 + 0x10) + *(float *)(iVar4 + 0x17c);
      local_28 = local_34 - local_40;
      local_24 = local_30 - local_3c;
      local_20 = local_2c - local_38;
      local_34 = *(float *)(*piVar11 + 0xf4) * 0.5;
      local_30 = *(float *)(*piVar11 + 0xf8) * 0.5;
      local_2c = *(float *)(*piVar11 + 0xfc) * 0.5;
      *(float **)(puVar9 + -8) = &local_34;
      *(float **)(puVar9 + -0xc) = &local_1c;
      *(float **)(puVar9 + -0x10) = &local_40;
      *(undefined4 *)(puVar9 + -0x14) = 0xd6f73;
      local_1c = local_28;
      local_18 = local_24;
      local_14 = local_20;
      UTIL_ClampVectorToBox__FRC6VectorT0();
      local_1c = local_40;
      local_18 = local_3c;
      local_14 = local_38;
      fVar3 = local_38 * *(float *)(gpGlobals + 0x30) +
              local_3c * *(float *)(gpGlobals + 0x2c) + local_40 * *(float *)(gpGlobals + 0x28);
      puVar8 = puVar9 + -8;
      puVar9 = puVar9 + -8;
      if (0x3f < (byte)((fVar3 < local_48 |
                         (byte)((ushort)((ushort)(NAN(fVar3) || NAN(local_48)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar3 == local_48) << 0xe) >> 8)) - 1)) {
        puVar9 = puVar8;
        local_48 = fVar3;
        local_44 = piVar11;
      }
    }
  }
  if (local_44 == (int *)0x0) {
    if ((*(byte *)(param_1 + 0x1b6) & 0x20) == 0) {
      return;
    }
    uVar7 = *(undefined4 *)(*param_1 + 0x208);
    *(undefined4 *)(puVar9 + -4) = 100;
    *(undefined4 *)(puVar9 + -8) = 0;
    *(undefined4 *)(puVar9 + -0xc) = 0x3f4ccccd;
    ppiVar10 = (int **)(puVar9 + -0x10);
    *(undefined4 *)(puVar9 + -0x10) = 0x3ecccccd;
    pcVar6 = "common/wpn_denyselect.wav";
LAB_000d70f9:
    *(char **)((int)ppiVar10 + -4) = pcVar6;
    *(undefined4 *)((int)ppiVar10 + -8) = 3;
    *(undefined4 *)((int)ppiVar10 + -0xc) = uVar7;
    *(undefined4 *)((int)ppiVar10 + -0x10) = 0xd7102;
    EMIT_SOUND_DYN__FP7edict_siPCcffii();
    return;
  }
  iVar4 = local_44[0x115];
  *(int **)(puVar9 + -4) = local_44;
  pcVar1 = *(code **)(iVar4 + 0x20);
  *(undefined4 *)(puVar9 + -8) = 0xd7008;
  uVar5 = (*pcVar1)();
  if ((*(byte *)(param_1 + 0x1b6) & 0x20) != 0) {
    uVar7 = *(undefined4 *)(*param_1 + 0x208);
    *(undefined4 *)(puVar9 + -4) = 100;
    *(undefined4 *)(puVar9 + -8) = 0;
    *(undefined4 *)(puVar9 + -0xc) = 0x3f4ccccd;
    *(undefined4 *)(puVar9 + -0x10) = 0x3ecccccd;
    *(char **)(puVar9 + -0x14) = "common/wpn_select.wav";
    *(undefined4 *)(puVar9 + -0x18) = 3;
    *(undefined4 *)(puVar9 + -0x1c) = uVar7;
    *(undefined4 *)(puVar9 + -0x20) = 0xd703b;
    EMIT_SOUND_DYN__FP7edict_siPCcffii();
  }
  if (((*(byte *)(*param_1 + 0x180) & 0x20) == 0) || ((uVar5 & 0x10) == 0)) {
    if (((*(byte *)(param_1 + 0x1b6) & 0x20) == 0) || ((uVar5 & 0x28) == 0)) {
      if ((*(byte *)(param_1 + 0x1b7) & 0x20) == 0) {
        return;
      }
      iVar4 = local_44[0x115];
      *(int **)(puVar9 + -4) = local_44;
      pcVar1 = *(code **)(iVar4 + 0x20);
      *(undefined4 *)(puVar9 + -8) = 0xd70a5;
      uVar5 = (*pcVar1)();
      if ((uVar5 & 0x20) == 0) {
        return;
      }
      local_54 = local_44[0x115];
      *(undefined4 *)(puVar9 + -4) = 0;
      goto LAB_000d70bd;
    }
    if ((uVar5 & 0x10) != 0) goto LAB_000d706a;
  }
  else {
LAB_000d706a:
    *(byte *)(param_1 + 0x1c3) = *(byte *)(param_1 + 0x1c3) | 0x10;
  }
  local_54 = local_44[0x115];
  *(undefined4 *)(puVar9 + -4) = 0x3f800000;
LAB_000d70bd:
  *(undefined4 *)(puVar9 + -8) = 2;
  *(int **)(puVar9 + -0xc) = param_1;
  *(int **)(puVar9 + -0x10) = param_1;
  *(int **)(puVar9 + -0x14) = local_44;
  pcVar1 = *(code **)(local_54 + 0xb8);
  *(undefined4 *)(puVar9 + -0x18) = 0xd70d0;
  (*pcVar1)();
  return;
}


