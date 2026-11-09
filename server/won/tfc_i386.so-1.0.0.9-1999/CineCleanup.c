// CineCleanup__12CBaseMonster  @ 000e8160
undefined4 CineCleanup__12CBaseMonster(int *param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 local_1c [12];
  float local_10;
  float local_c;
  float local_8;
  
  piVar3 = (int *)param_1[0x183];
  if (piVar3 == (int *)0x0) {
    *(undefined4 *)(*param_1 + 0xe8) = 4;
    *(undefined4 *)(*param_1 + 0xec) = 3;
  }
  else {
    __as__7EHANDLEP11CBaseEntity(piVar3 + 0x11e,0);
    *(undefined4 *)(*param_1 + 0xe8) = *(undefined4 *)(param_1[0x183] + 0x634);
    *(undefined4 *)(*param_1 + 0xec) = *(undefined4 *)(param_1[0x183] + 0x638);
    *(undefined4 *)(*param_1 + 0xf8) = *(undefined4 *)(param_1[0x183] + 0x63c);
  }
  param_1[0x183] = 0;
  __as__7EHANDLEP11CBaseEntity(param_1 + 0x11e,0);
  param_1[1] = 0;
  if (*(int *)(*param_1 + 0x150) == 1) {
    *(undefined4 *)(*param_1 + 0x140) = 0;
    *(undefined4 *)(*param_1 + 0x118) = 0;
    *(undefined4 *)(*param_1 + 0xec) = 0;
    SetState__12CBaseMonster12MONSTERSTATE(param_1,8);
    *(undefined4 *)(*param_1 + 0x150) = 2;
    iVar5 = *param_1;
    local_8 = *(float *)(iVar5 + 0xc4) + 2.0;
    local_10 = *(float *)(iVar5 + 200);
    local_c = *(float *)(iVar5 + 0xcc);
    UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar5,iVar5 + 0xbc,&local_10);
    if ((piVar3 == (int *)0x0) || ((*(byte *)(*piVar3 + 0x180) & 8) == 0)) {
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
    *(undefined4 *)(*param_1 + 0x118) = 0;
    *(undefined4 *)(*param_1 + 0xe8) = 0;
    *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x20;
    uVar4 = 0;
  }
  else {
    if ((piVar3 != (int *)0x0) && (piVar3[0x185] != 0)) {
      if (-1 < *(char *)(*piVar3 + 0x180)) {
        GetBonePosition__14CBaseAnimatingiR6VectorT2(param_1,0,&local_10,local_1c);
        fVar1 = *(float *)(*param_1 + 8);
        fVar2 = *(float *)(*param_1 + 0xc);
        uVar4 = *(undefined4 *)(*param_1 + 0x10);
        if (SQRT((fVar2 - local_c) * (fVar2 - local_c) + (fVar1 - local_10) * (fVar1 - local_10)) <
            8.0) {
          local_10 = fVar1;
          local_c = fVar2;
          local_8 = (float)uVar4;
        }
        *(float *)(*param_1 + 8) = local_10;
        *(float *)(*param_1 + 0xc) = local_c;
        *(float *)(*param_1 + 0x10) = *(float *)(*param_1 + 0x10) + 1.0;
        *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) | 2;
        iVar5 = (*DAT_00175528)(*(undefined4 *)(*param_1 + 0x1e8));
        if (iVar5 < 0) {
          iVar5 = *param_1;
          *(float *)(iVar5 + 8) = fVar1;
          *(float *)(iVar5 + 0xc) = fVar2;
          *(undefined4 *)(iVar5 + 0x10) = uVar4;
        }
        else if (iVar5 == 0) {
          *(float *)(*param_1 + 0x10) = local_8;
          *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
        }
        UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
        *(byte *)(*param_1 + 0xf8) = *(byte *)(*param_1 + 0xf8) | 0x20;
      }
      param_1[0x137] = 0;
    }
    *(undefined4 *)(*param_1 + 0x170) = 0;
    fVar1 = *(float *)(*param_1 + 0x140);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      param_1[0x13b] = 1;
    }
    else {
      param_1[0x13b] = 8;
      *(byte *)((int)param_1 + 0x46d) = *(byte *)((int)param_1 + 0x46d) | 1;
      *(undefined4 *)(*param_1 + 0x150) = 1;
      FCheckAITrigger__12CBaseMonster(param_1);
      *(undefined4 *)(*param_1 + 0x150) = 0;
    }
    *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) & 0x7f;
    uVar4 = 1;
  }
  return uVar4;
}


