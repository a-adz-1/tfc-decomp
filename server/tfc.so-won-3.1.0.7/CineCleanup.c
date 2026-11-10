// CineCleanup__12CBaseMonster  @ 000e9218
undefined4 CineCleanup__12CBaseMonster(int *param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 local_18 [12];
  float local_c;
  float local_8;
  float local_4;
  
  piVar3 = (int *)param_1[0x1a2];
  if (piVar3 == (int *)0x0) {
    *(undefined4 *)(*param_1 + 0x108) = 4;
    *(undefined4 *)(*param_1 + 0x10c) = 3;
  }
  else {
    __as__7EHANDLEP11CBaseEntity(piVar3 + 0x13d,0);
    *(undefined4 *)(*param_1 + 0x108) = *(undefined4 *)(param_1[0x1a2] + 0x6b0);
    *(undefined4 *)(*param_1 + 0x10c) = *(undefined4 *)(param_1[0x1a2] + 0x6b4);
    *(undefined4 *)(*param_1 + 0x118) = *(undefined4 *)(param_1[0x1a2] + 0x6b8);
  }
  param_1[0x1a2] = 0;
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x13d,0);
  param_1[1] = 0;
  if (*(int *)(*param_1 + 0x170) == 1) {
    *(undefined4 *)(*param_1 + 0x160) = 0;
    *(undefined4 *)(*param_1 + 0x138) = 0;
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    SetState__12CBaseMonster12MONSTERSTATE(param_1,8);
    *(undefined4 *)(*param_1 + 0x170) = 2;
    iVar6 = *param_1;
    local_4 = *(float *)(iVar6 + 0xe4) + 2.0;
    local_c = *(float *)(iVar6 + 0xe8);
    local_8 = *(float *)(iVar6 + 0xec);
    UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar6,iVar6 + 0xdc,&local_c);
    if ((piVar3 == (int *)0x0) || ((*(byte *)(*piVar3 + 0x1a0) & 8) == 0)) {
      SUB_StartFadeOut__11CBaseEntity(param_1);
    }
    else {
      param_1[7] = 0;
      param_1[8] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
    }
    *(undefined4 *)(*param_1 + 0x138) = 0;
    *(undefined4 *)(*param_1 + 0x108) = 0;
    *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
    uVar5 = 0;
  }
  else {
    if ((piVar3 != (int *)0x0) && (piVar3[0x1a4] != 0)) {
      if (-1 < *(char *)(*piVar3 + 0x1a0)) {
        GetBonePosition__14CBaseAnimatingiR6VectorT2(param_1,0,&local_c,local_18);
        fVar1 = *(float *)(*param_1 + 8);
        fVar2 = *(float *)(*param_1 + 0xc);
        uVar5 = *(undefined4 *)(*param_1 + 0x10);
        fVar4 = SQRT((fVar2 - local_8) * (fVar2 - local_8) + (fVar1 - local_c) * (fVar1 - local_c));
        if (0x3f < (byte)((8.0 < fVar4 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar4 == 8.0) << 0xe) >> 8)) - 1)) {
          local_c = fVar1;
          local_8 = fVar2;
          local_4 = (float)uVar5;
        }
        *(float *)(*param_1 + 8) = local_c;
        *(float *)(*param_1 + 0xc) = local_8;
        *(float *)(*param_1 + 0x10) = *(float *)(*param_1 + 0x10) + 1.0;
        *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) | 2;
        iVar6 = (*DAT_001c1088)(*(undefined4 *)(*param_1 + 0x208));
        if (iVar6 < 0) {
          iVar6 = *param_1;
          *(float *)(iVar6 + 8) = fVar1;
          *(float *)(iVar6 + 0xc) = fVar2;
          *(undefined4 *)(iVar6 + 0x10) = uVar5;
        }
        else if (iVar6 == 0) {
          *(float *)(*param_1 + 0x10) = local_4;
          *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
        }
        UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
        *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 0x20;
      }
      param_1[0x156] = 0;
    }
    *(undefined4 *)(*param_1 + 400) = 0;
    if (*(float *)(*param_1 + 0x160) <= 0.0) {
      param_1[0x15a] = 8;
      *(byte *)((int)param_1 + 0x4e9) = *(byte *)((int)param_1 + 0x4e9) | 1;
      *(undefined4 *)(*param_1 + 0x170) = 1;
      FCheckAITrigger__12CBaseMonster(param_1);
      *(undefined4 *)(*param_1 + 0x170) = 0;
    }
    else {
      param_1[0x15a] = 1;
    }
    *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) & 0x7f;
    uVar5 = 1;
  }
  return uVar5;
}


