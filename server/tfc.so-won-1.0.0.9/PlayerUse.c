// PlayerUse__11CBasePlayer  @ 000d92f0
void PlayerUse__11CBasePlayer(int *param_1)

{
  code *pcVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int **ppiVar9;
  undefined2 in_FPUControlWord;
  int *piStack_70;
  int aiStack_6c [2];
  int *piStack_64;
  int iStack_60;
  float fStack_48;
  int *piStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  if (((*(uint *)(*param_1 + 0x160) | param_1[0x18d] | param_1[0x18e]) & 0x20) == 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x18d) & 0x20) != 0) {
    piVar6 = param_1 + 0x1f8;
    piStack_64 = (int *)0xd9331;
    iStack_60 = (int)piVar6;
    iVar3 = __opP11CBaseEntity__7EHANDLE();
    if (iVar3 != 0) {
      piStack_64 = (int *)0xd933e;
      iStack_60 = (int)piVar6;
      iVar3 = __rf__7EHANDLE();
      piStack_64 = (int *)0x0;
      aiStack_6c[1] = 0;
      aiStack_6c[0] = (int)param_1;
      piStack_70 = param_1;
      (**(code **)(*(int *)(iVar3 + 0x3c8) + 0xb0))(iVar3);
      __as__7EHANDLEP11CBaseEntity(piVar6,0);
      return;
    }
    if ((*(byte *)(param_1 + 0x19a) & 2) != 0) {
      *(byte *)(param_1 + 0x19a) = *(byte *)(param_1 + 0x19a) & 0xfd;
      param_1[0x1f6] = 0xc0;
      return;
    }
    iVar3 = *(int *)(*param_1 + 0x17c);
    if (iVar3 == 0) {
      iStack_60 = 0;
      piStack_64 = (int *)0xd93a5;
      iVar3 = (*DAT_001755d4)();
      if (iVar3 != 0) goto LAB_000d93ae;
      piVar6 = (int *)0x0;
    }
    else {
LAB_000d93ae:
      piVar6 = *(int **)(iVar3 + 0xd8);
    }
    if (((piVar6 != (int *)0x0) && ((*(byte *)(*param_1 + 0x160) & 2) == 0)) &&
       ((*(byte *)(*param_1 + 0x185) & 2) != 0)) {
      piStack_64 = (int *)0xd93f2;
      iStack_60 = (int)piVar6;
      uVar4 = (**(code **)(piVar6[0xf2] + 0x1c))();
      if ((uVar4 & 0x40) != 0) {
        iStack_60 = *param_1;
        aiStack_6c[1] = 0xd940f;
        piStack_64 = piVar6;
        iVar3 = (**(code **)(piVar6[0xf2] + 0x80))();
        if (iVar3 != 0) {
          *(byte *)(param_1 + 0x19a) = *(byte *)(param_1 + 0x19a) | 2;
          iStack_60 = *(undefined4 *)(*piVar6 + 0x164);
          _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
          uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
          piStack_64 = (int *)(int)ROUND(*(float *)(*piVar6 + 0x1d8));
          aiStack_6c[1] = 0xd944b;
          iVar3 = TrainSpeed__Fii();
          param_1[0x1f6] = iVar3;
          *(byte *)(param_1 + 0x1f6) = *(byte *)(param_1 + 0x1f6) | 0xc0;
          uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
          iStack_60 = 100;
          piStack_64 = (int *)0x0;
          aiStack_6c[1] = 0x3f4ccccd;
          aiStack_6c[0] = 0x3f4ccccd;
          ppiVar9 = &piStack_70;
          piStack_70 = (int *)0x139ae8;
          goto LAB_000d96e4;
        }
      }
    }
  }
  piVar6 = (int *)0x0;
  piStack_44 = (int *)0x0;
  fStack_48 = 0.7;
  iStack_60 = *param_1 + 0x74;
  piStack_64 = (int *)0xd94ab;
  UTIL_MakeVectors__FRC6Vector();
  puVar8 = &stack0xffffffa4;
  while( true ) {
    *(undefined4 *)(puVar8 + -4) = 0x42800000;
    *(int *)(puVar8 + -8) = *param_1 + 8;
    *(int **)(puVar8 + -0xc) = piVar6;
    *(undefined4 *)(puVar8 + -0x10) = 0xd95da;
    piVar6 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
    if (piVar6 == (int *)0x0) break;
    iVar3 = piVar6[0xf2];
    *(int **)(puVar8 + -4) = piVar6;
    pcVar1 = *(code **)(iVar3 + 0x1c);
    *(undefined4 *)(puVar8 + -8) = 0xd94cc;
    uVar4 = (*pcVar1)();
    if ((uVar4 & 0x38) != 0) {
      *(int *)(puVar8 + -4) = *piVar6;
      *(float **)(puVar8 + -8) = &fStack_34;
      *(undefined4 *)(puVar8 + -0xc) = 0xd94e0;
      VecBModelOrigin__FP9entvars_t();
      iVar3 = *param_1;
      fStack_40 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x154);
      fStack_3c = *(float *)(*param_1 + 0xc) + *(float *)(iVar3 + 0x158);
      fStack_38 = *(float *)(*param_1 + 0x10) + *(float *)(iVar3 + 0x15c);
      fStack_28 = fStack_34 - fStack_40;
      fStack_24 = fStack_30 - fStack_3c;
      fStack_20 = fStack_2c - fStack_38;
      fStack_34 = *(float *)(*piVar6 + 0xd4) * 0.5;
      fStack_30 = *(float *)(*piVar6 + 0xd8) * 0.5;
      fStack_2c = *(float *)(*piVar6 + 0xdc) * 0.5;
      *(float **)(puVar8 + -8) = &fStack_34;
      *(float **)(puVar8 + -0xc) = &fStack_1c;
      *(float **)(puVar8 + -0x10) = &fStack_40;
      *(undefined4 *)(puVar8 + -0x14) = 0xd957c;
      fStack_1c = fStack_28;
      fStack_18 = fStack_24;
      fStack_14 = fStack_20;
      UTIL_ClampVectorToBox__FRC6VectorT0();
      fStack_1c = fStack_40;
      fStack_18 = fStack_3c;
      fStack_14 = fStack_38;
      puVar7 = puVar8 + -8;
      puVar8 = puVar8 + -8;
      fVar2 = fStack_38 * *(float *)(gpGlobals + 0x30) +
              fStack_3c * *(float *)(gpGlobals + 0x2c) + fStack_40 * *(float *)(gpGlobals + 0x28);
      if (fStack_48 < fVar2) {
        puVar8 = puVar7;
        fStack_48 = fVar2;
        piStack_44 = piVar6;
      }
    }
  }
  if (piStack_44 == (int *)0x0) {
    if ((*(byte *)(param_1 + 0x18d) & 0x20) == 0) {
      return;
    }
    uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
    *(undefined4 *)(puVar8 + -4) = 100;
    *(undefined4 *)(puVar8 + -8) = 0;
    *(undefined4 *)(puVar8 + -0xc) = 0x3f4ccccd;
    *(undefined4 *)(puVar8 + -0x10) = 0x3ecccccd;
    ppiVar9 = (int **)(puVar8 + -0x14);
    *(char **)(puVar8 + -0x14) = "common/wpn_denyselect.wav";
LAB_000d96e4:
    *(undefined4 *)((int)ppiVar9 + -4) = 3;
    *(undefined4 *)((int)ppiVar9 + -8) = uVar5;
    *(undefined4 *)((int)ppiVar9 + -0xc) = 0xd96ec;
    EMIT_SOUND_DYN__FP7edict_siPCcffii();
    return;
  }
  iVar3 = piStack_44[0xf2];
  *(int **)(puVar8 + -4) = piStack_44;
  pcVar1 = *(code **)(iVar3 + 0x1c);
  *(undefined4 *)(puVar8 + -8) = 0xd95fe;
  uVar4 = (*pcVar1)();
  if ((*(byte *)(param_1 + 0x18d) & 0x20) != 0) {
    uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
    *(undefined4 *)(puVar8 + -4) = 100;
    *(undefined4 *)(puVar8 + -8) = 0;
    *(undefined4 *)(puVar8 + -0xc) = 0x3f4ccccd;
    *(undefined4 *)(puVar8 + -0x10) = 0x3ecccccd;
    *(char **)(puVar8 + -0x14) = "common/wpn_select.wav";
    *(undefined4 *)(puVar8 + -0x18) = 3;
    *(undefined4 *)(puVar8 + -0x1c) = uVar5;
    *(undefined4 *)(puVar8 + -0x20) = 0xd962f;
    EMIT_SOUND_DYN__FP7edict_siPCcffii();
  }
  if (((*(byte *)(*param_1 + 0x160) & 0x20) == 0) || ((uVar4 & 0x10) == 0)) {
    if (((*(byte *)(param_1 + 0x18d) & 0x20) == 0) || ((uVar4 & 0x28) == 0)) {
      if ((*(byte *)(param_1 + 0x18e) & 0x20) == 0) {
        return;
      }
      iVar3 = piStack_44[0xf2];
      *(int **)(puVar8 + -4) = piStack_44;
      pcVar1 = *(code **)(iVar3 + 0x1c);
      *(undefined4 *)(puVar8 + -8) = 0xd9695;
      uVar4 = (*pcVar1)();
      if ((uVar4 & 0x20) == 0) {
        return;
      }
      iVar3 = piStack_44[0xf2];
      *(undefined4 *)(puVar8 + -4) = 0;
      goto LAB_000d96a4;
    }
    if ((uVar4 & 0x10) != 0) goto LAB_000d965e;
  }
  else {
LAB_000d965e:
    *(byte *)(param_1 + 0x19a) = *(byte *)(param_1 + 0x19a) | 0x10;
  }
  iVar3 = piStack_44[0xf2];
  *(undefined4 *)(puVar8 + -4) = 0x3f800000;
LAB_000d96a4:
  *(undefined4 *)(puVar8 + -8) = 2;
  *(int **)(puVar8 + -0xc) = param_1;
  *(int **)(puVar8 + -0x10) = param_1;
  *(int **)(puVar8 + -0x14) = piStack_44;
  pcVar1 = *(code **)(iVar3 + 0xb0);
  *(undefined4 *)(puVar8 + -0x18) = 0xd96b1;
  (*pcVar1)();
  return;
}


