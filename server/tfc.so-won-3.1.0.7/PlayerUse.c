// PlayerUse__11CBasePlayer  @ 000d7250
void PlayerUse__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  code *pcVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  int **ppiVar12;
  int *piVar13;
  undefined2 in_FPUControlWord;
  int *apiStack_70 [2];
  int local_68;
  int *piStack_64;
  int iStack_60;
  float local_4c [18];
  undefined2 local_4;
  undefined2 uStack_2;
  
  if (*(int *)(*param_1 + 0x244) != 0) {
    return;
  }
  if (((*(uint *)(*param_1 + 0x180) | param_1[0x1ad] | param_1[0x1ae]) & 0x20) == 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x1ad) & 0x20) != 0) {
    piVar13 = param_1 + 0x219;
    piStack_64 = (int *)0xd72a9;
    iStack_60 = (int)piVar13;
    iVar7 = __opP11CBaseEntity__7EHANDLE();
    if (iVar7 != 0) {
      piStack_64 = (int *)0xd72b6;
      iStack_60 = (int)piVar13;
      iVar7 = __rf__7EHANDLE();
      piStack_64 = (int *)0x0;
      local_68 = 0;
      apiStack_70[1] = param_1;
      apiStack_70[0] = param_1;
      (**(code **)(*(int *)(iVar7 + 0x444) + 0xb8))(iVar7);
      __as__7EHANDLEP11CBaseEntity(piVar13,0);
      return;
    }
    if ((*(byte *)(param_1 + 0x1ba) & 2) != 0) {
      *(byte *)(param_1 + 0x1ba) = *(byte *)(param_1 + 0x1ba) & 0xfd;
      param_1[0x217] = 0xc0;
      return;
    }
    iVar7 = *(int *)(*param_1 + 0x19c);
    if (iVar7 == 0) {
      iStack_60 = 0;
      piStack_64 = (int *)0xd731c;
      iVar7 = (*DAT_001c1134)();
      if (iVar7 != 0) goto LAB_000d7325;
      piVar13 = (int *)0x0;
    }
    else {
LAB_000d7325:
      piVar13 = *(int **)(iVar7 + 0x7c);
    }
    if (((piVar13 != (int *)0x0) && ((*(byte *)(*param_1 + 0x180) & 2) == 0)) &&
       ((*(byte *)(*param_1 + 0x1a5) & 2) != 0)) {
      piStack_64 = (int *)0xd735e;
      iStack_60 = (int)piVar13;
      uVar8 = (**(code **)(piVar13[0x111] + 0x20))();
      if ((uVar8 & 0x40) != 0) {
        iStack_60 = *param_1;
        local_68 = 0xd737b;
        piStack_64 = piVar13;
        iVar7 = (**(code **)(piVar13[0x111] + 0x84))();
        if (iVar7 != 0) {
          *(byte *)(param_1 + 0x1ba) = *(byte *)(param_1 + 0x1ba) | 2;
          iStack_60 = *(undefined4 *)(*piVar13 + 0x184);
          _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
          local_4c[0x10] = (float)CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
          piStack_64 = (int *)(int)ROUND(*(float *)(*piVar13 + 0x1f8));
          local_68 = 0xd73cc;
          iVar7 = TrainSpeed__Fii();
          param_1[0x217] = iVar7;
          *(byte *)(param_1 + 0x217) = *(byte *)(param_1 + 0x217) | 0xc0;
          uVar10 = *(undefined4 *)(*param_1 + 0x208);
          apiStack_70[0] = (int *)0x14b098;
          apiStack_70[1] = (int *)0x3f4ccccd;
          iStack_60 = 100;
          piStack_64 = (int *)0x0;
          ppiVar12 = apiStack_70;
          local_68 = (int)apiStack_70[1];
          goto LAB_000d7696;
        }
      }
    }
  }
  piVar13 = (int *)0x0;
  iStack_60 = *param_1 + 0x74;
  piStack_64 = (int *)0xd7435;
  UTIL_MakeVectors__FRC6Vector();
  puVar6 = &stack0xffffffa4;
  while( true ) {
    puVar11 = puVar6;
    *(undefined4 *)(puVar11 + -4) = 0x42800000;
    *(int *)(puVar11 + -8) = *param_1 + 8;
    *(int **)(puVar11 + -0xc) = piVar13;
    *(undefined4 *)(puVar11 + -0x10) = 0xd759b;
    piVar13 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
    if (piVar13 == (int *)0x0) break;
    iVar7 = piVar13[0x111];
    *(int **)(puVar11 + -4) = piVar13;
    pcVar5 = *(code **)(iVar7 + 0x20);
    *(undefined4 *)(puVar11 + -8) = 0xd7458;
    uVar8 = (*pcVar5)();
    puVar6 = puVar11;
    if ((uVar8 & 0x38) != 0) {
      *(int *)(puVar11 + -4) = *piVar13;
      *(float **)(puVar11 + -8) = local_4c + 7;
      *(undefined4 *)(puVar11 + -0xc) = 0xd746c;
      VecBModelOrigin__FP9entvars_s();
      iVar7 = *param_1;
      fVar1 = *(float *)(*param_1 + 0xc);
      fVar2 = *(float *)(iVar7 + 0x178);
      fVar3 = *(float *)(*param_1 + 0x10);
      fVar4 = *(float *)(iVar7 + 0x17c);
      *(float *)(puVar11 + 0x1c) = *(float *)(iVar7 + 8) + *(float *)(iVar7 + 0x174);
      *(float *)(puVar11 + 0x20) = fVar1 + fVar2;
      *(float *)(puVar11 + 0x24) = fVar3 + fVar4;
      *(float *)(puVar11 + 0x34) = *(float *)(puVar11 + 0x28) - *(float *)(puVar11 + 0x1c);
      *(float *)(puVar11 + 0x38) = *(float *)(puVar11 + 0x2c) - *(float *)(puVar11 + 0x20);
      *(float *)(puVar11 + 0x3c) = *(float *)(puVar11 + 0x30) - *(float *)(puVar11 + 0x24);
      *(undefined4 *)(puVar11 + 0x40) = *(undefined4 *)(puVar11 + 0x34);
      *(undefined4 *)(puVar11 + 0x44) = *(undefined4 *)(puVar11 + 0x38);
      *(undefined4 *)(puVar11 + 0x48) = *(undefined4 *)(puVar11 + 0x3c);
      fVar1 = *(float *)(*piVar13 + 0xf8);
      fVar2 = *(float *)(*piVar13 + 0xfc);
      *(float *)(puVar11 + 0x28) = *(float *)(*piVar13 + 0xf4) * 0.5;
      *(float *)(puVar11 + 0x2c) = fVar1 * 0.5;
      *(float *)(puVar11 + 0x30) = fVar2 * 0.5;
      *(float **)(puVar11 + -8) = local_4c + 7;
      *(undefined1 **)(puVar11 + 0xc) = puVar11 + 0x40;
      *(undefined1 **)(puVar11 + -0xc) = puVar11 + 0x40;
      *(undefined4 *)(puVar11 + -0x10) = *(undefined4 *)(puVar11 + 0x10);
      *(undefined4 *)(puVar11 + -0x14) = 0xd7525;
      UTIL_ClampVectorToBox__FRC6VectorT0();
      *(undefined4 *)(puVar11 + 0x3c) = *(undefined4 *)(puVar11 + 0x18);
      *(undefined4 *)(puVar11 + 0x40) = *(undefined4 *)(puVar11 + 0x1c);
      *(undefined4 *)(puVar11 + 0x44) = *(undefined4 *)(puVar11 + 0x20);
      *(int *)(puVar11 + 8) = gpGlobals;
      fVar2 = *(float *)(puVar11 + 0x44) * *(float *)(gpGlobals + 0x30) +
              *(float *)(puVar11 + 0x40) * *(float *)(gpGlobals + 0x2c) +
              *(float *)(puVar11 + 0x3c) * *(float *)(*(int *)(puVar11 + 8) + 0x28);
      fVar1 = *(float *)(puVar11 + 0x10);
      puVar6 = puVar11 + -8;
      if (0x3f < (byte)((fVar2 < fVar1 |
                         (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
        *(int **)(puVar11 + 0x14) = piVar13;
        *(float *)(puVar11 + 0x10) = fVar2;
        puVar6 = puVar11 + -8;
      }
    }
  }
  iVar7 = *(int *)(puVar11 + 0x1c);
  if (iVar7 == 0) {
    if ((*(byte *)(param_1 + 0x1ad) & 0x20) == 0) {
      return;
    }
    uVar10 = *(undefined4 *)(*param_1 + 0x208);
    *(undefined4 *)(puVar11 + -4) = 100;
    *(undefined4 *)(puVar11 + -8) = 0;
    *(undefined4 *)(puVar11 + -0xc) = 0x3f4ccccd;
    *(undefined4 *)(puVar11 + -0x10) = 0x3ecccccd;
    ppiVar12 = (int **)(puVar11 + -0x14);
    *(char **)(puVar11 + -0x14) = "common/wpn_denyselect.wav";
LAB_000d7696:
    *(undefined4 *)((int)ppiVar12 + -4) = 3;
    *(undefined4 *)((int)ppiVar12 + -8) = uVar10;
    *(undefined4 *)((int)ppiVar12 + -0xc) = 0xd769e;
    EMIT_SOUND_DYN__FP7edict_siPCcffii();
    return;
  }
  iVar9 = *(int *)(iVar7 + 0x444);
  *(int *)(puVar11 + -4) = iVar7;
  pcVar5 = *(code **)(iVar9 + 0x20);
  *(undefined4 *)(puVar11 + -8) = 0xd75c0;
  uVar8 = (*pcVar5)();
  if ((*(byte *)(param_1 + 0x1ad) & 0x20) != 0) {
    uVar10 = *(undefined4 *)(*param_1 + 0x208);
    *(undefined4 *)(puVar11 + -4) = 100;
    *(undefined4 *)(puVar11 + -8) = 0;
    *(undefined4 *)(puVar11 + -0xc) = 0x3f4ccccd;
    *(undefined4 *)(puVar11 + -0x10) = 0x3ecccccd;
    *(char **)(puVar11 + -0x14) = "common/wpn_select.wav";
    *(undefined4 *)(puVar11 + -0x18) = 3;
    *(undefined4 *)(puVar11 + -0x1c) = uVar10;
    *(undefined4 *)(puVar11 + -0x20) = 0xd75f3;
    EMIT_SOUND_DYN__FP7edict_siPCcffii();
  }
  if (((*(byte *)(*param_1 + 0x180) & 0x20) == 0) || ((uVar8 & 0x10) == 0)) {
    if (((*(byte *)(param_1 + 0x1ad) & 0x20) == 0) || ((uVar8 & 0x28) == 0)) {
      if ((*(byte *)(param_1 + 0x1ae) & 0x20) == 0) {
        return;
      }
      iVar9 = *(int *)(iVar7 + 0x444);
      *(int *)(puVar11 + -4) = iVar7;
      pcVar5 = *(code **)(iVar9 + 0x20);
      *(undefined4 *)(puVar11 + -8) = 0xd764d;
      uVar8 = (*pcVar5)();
      if ((uVar8 & 0x20) == 0) {
        return;
      }
      iVar9 = *(int *)(iVar7 + 0x444);
      *(undefined4 *)(puVar11 + -4) = 0;
      goto LAB_000d765c;
    }
    if ((uVar8 & 0x10) != 0) goto LAB_000d7622;
  }
  else {
LAB_000d7622:
    *(byte *)(param_1 + 0x1ba) = *(byte *)(param_1 + 0x1ba) | 0x10;
  }
  iVar9 = *(int *)(iVar7 + 0x444);
  *(undefined4 *)(puVar11 + -4) = 0x3f800000;
LAB_000d765c:
  *(undefined4 *)(puVar11 + -8) = 2;
  *(int **)(puVar11 + -0xc) = param_1;
  *(int **)(puVar11 + -0x10) = param_1;
  *(int *)(puVar11 + -0x14) = iVar7;
  pcVar5 = *(code **)(iVar9 + 0xb8);
  *(undefined4 *)(puVar11 + -0x18) = 0xd7669;
  (*pcVar5)();
  return;
}


