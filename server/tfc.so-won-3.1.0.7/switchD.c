// switchD_0009a176::caseD_1  @ 0009a2d8
undefined4 switchD_0009a176::caseD_1(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_ESI;
  
  iVar1 = (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 0x168))(0,0xe);
  if ((iVar1 == 0) && (iVar1 = (**(code **)(*(int *)(unaff_ESI + 0x444) + 0x1cc))(), iVar1 != 0)) {
    return *(undefined4 *)(unaff_EBX + 0x18c0);
  }
  return *(undefined4 *)(unaff_EBX + 0x18c4);
}


// switchD_0009a176::caseD_15  @ 0009a410
undefined4 switchD_0009a176::caseD_15(void)

{
  int unaff_EBX;
  
  return *(undefined4 *)(unaff_EBX + 0x191c);
}


// switchD_0009dd65::caseD_0  @ 0009de58
void switchD_0009dd65::caseD_0(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBX;
  int *unaff_EDI;
  
  uVar2 = (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 0x10c))(unaff_EBX + -0x78d48);
  *(undefined4 *)(*unaff_EDI + 0x1ec) = uVar2;
  if (*(byte *)((int)unaff_EDI + 0x4ea) < 9) {
                    /* WARNING: Could not recover jumptable at 0x0009de94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX -
              *(int *)(unaff_EBX + -0x11fb68 + (uint)*(byte *)((int)unaff_EDI + 0x4ea) * 4)))();
    return;
  }
  uVar2 = (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 0x10c))(unaff_EBX + -0x78d48);
  *(undefined4 *)(*unaff_EDI + 0x1f0) = uVar2;
  if ((char)unaff_EDI[0x144] != '\0') {
    uVar2 = ButtonSound__Fi((char)unaff_EDI[0x144]);
    (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 4))(uVar2);
    iVar3 = (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 0x10c))(uVar2);
    unaff_EDI[0x13b] = iVar3;
  }
  if (*(char *)((int)unaff_EDI + 0x512) != '\0') {
    uVar2 = ButtonSound__Fi(*(undefined1 *)((int)unaff_EDI + 0x512));
    (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 4))(uVar2);
    iVar3 = (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 0x10c))(uVar2);
    unaff_EDI[0x13d] = iVar3;
  }
  uVar4 = *(byte *)((int)unaff_EDI + 0x511) - 1;
  if (uVar4 < 9) {
                    /* WARNING: Could not recover jumptable at 0x0009e015. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0x11f9e8 + uVar4 * 4)))();
    return;
  }
  unaff_EDI[0x13c] = 0;
  uVar4 = *(byte *)((int)unaff_EDI + 0x513) - 1;
  if (uVar4 < 8) {
                    /* WARNING: Could not recover jumptable at 0x0009e103. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0x11f8f8 + uVar4 * 4)))();
    return;
  }
  unaff_EDI[0x13e] = 0;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 0x1e8))(1,unaff_EBX + -0x78b88);
  *(undefined2 *)((int)unaff_EDI + 0x51a) = uVar1;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 0x1e8))(1,unaff_EBX + -0x78b70);
  *(undefined2 *)(unaff_EDI + 0x147) = uVar1;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 0x1e8))(1,unaff_EBX + -0x78b56);
  *(undefined2 *)((int)unaff_EDI + 0x51e) = uVar1;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 0x1e8))(1,unaff_EBX + -0x78b3c);
  *(undefined2 *)(unaff_EDI + 0x148) = uVar1;
  return;
}


// switchD_000a9172::caseD_7  @ 000a93d7
void switchD_000a9172::caseD_7(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EBX;
  float *unaff_EBP;
  uint uVar5;
  code *pcStack00000014;
  int *in_stack_00000020;
  float fVar6;
  float local_4;
  
  if (unaff_EBP[0x115] == 1.4013e-45) {
    fVar6 = *(float *)(*(int *)(unaff_EBX + 0x171c) + 4) * *(float *)(unaff_EBX + -0x77c30);
  }
  else {
    fVar6 = 0.0;
  }
  local_4 = 0.0;
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xb8);
  (*pcStack00000014)();
  local_4 = 1.5134e-43;
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xc0);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xd4);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xd4);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xd4);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xd4);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xd4);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xd4);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xd4);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xd4);
  local_4 = fVar6;
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xd4);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xc0);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 200);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xc0);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xc0);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xc0);
  (*pcStack00000014)();
  pcStack00000014 = *(code **)(*(int *)(unaff_EBX + 0x15c8) + 0xbc);
  (*pcStack00000014)();
  local_4 = 7.17465e-43;
  puVar4 = &stack0x00000020;
  uVar2 = UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i();
  if ((uVar2 != 0) && (iVar3 = 0, 0 < (int)uVar2)) {
    uVar5 = uVar2 & 3;
    if (uVar5 != 0) {
      if (1 < uVar5) {
        if (2 < uVar5) {
          *(byte *)(*in_stack_00000020 + 0x1a5) = *(byte *)(*in_stack_00000020 + 0x1a5) & 0xfd;
          *(undefined4 *)(*in_stack_00000020 + 0x19c) = 0;
          puVar4 = (undefined4 *)&stack0x00000024;
        }
        *(byte *)(*(int *)*puVar4 + 0x1a5) = *(byte *)(*(int *)*puVar4 + 0x1a5) & 0xfd;
        *(undefined4 *)(*(int *)*puVar4 + 0x19c) = 0;
        puVar4 = puVar4 + 1;
        iVar3 = (2 < uVar5) + 1;
      }
      *(byte *)(*(int *)*puVar4 + 0x1a5) = *(byte *)(*(int *)*puVar4 + 0x1a5) & 0xfd;
      *(undefined4 *)(*(int *)*puVar4 + 0x19c) = 0;
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + 1;
      if ((int)uVar2 <= iVar3) goto LAB_000a98fa;
    }
    do {
      *(byte *)(*(int *)*puVar4 + 0x1a5) = *(byte *)(*(int *)*puVar4 + 0x1a5) & 0xfd;
      *(undefined4 *)(*(int *)*puVar4 + 0x19c) = 0;
      *(byte *)(*(int *)puVar4[1] + 0x1a5) = *(byte *)(*(int *)puVar4[1] + 0x1a5) & 0xfd;
      *(undefined4 *)(*(int *)puVar4[1] + 0x19c) = 0;
      *(byte *)(*(int *)puVar4[2] + 0x1a5) = *(byte *)(*(int *)puVar4[2] + 0x1a5) & 0xfd;
      *(undefined4 *)(*(int *)puVar4[2] + 0x19c) = 0;
      *(byte *)(*(int *)puVar4[3] + 0x1a5) = *(byte *)(*(int *)puVar4[3] + 0x1a5) & 0xfd;
      *(undefined4 *)(*(int *)puVar4[3] + 0x19c) = 0;
      puVar4 = puVar4 + 4;
      iVar3 = iVar3 + 4;
    } while (iVar3 < (int)uVar2);
  }
LAB_000a98fa:
  *(undefined4 *)((int)*unaff_EBP + 0x1cc) = 0;
  *(undefined4 *)((int)*unaff_EBP + 0x10c) = 0;
  local_4 = 0.0;
  SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf();
  fVar6 = *(float *)(unaff_EBX + 0x17cc);
  unaff_EBP[3] = -NAN;
  unaff_EBP[4] = fVar6;
  *(float *)((int)*unaff_EBP + 0x104) =
       (float)*(double *)(unaff_EBX + -0x77c20) + *(float *)((int)*unaff_EBP + 0x100);
  if (unaff_EBP[0x119] != 0.0) {
    local_4 = *unaff_EBP;
    VecBModelOrigin__FP9entvars_s();
    Create__11CBaseEntityPcRC6VectorT2P7edict_s();
    register0x00000010 = (BADSPACEBASE *)&local_4;
  }
  *(float **)((int)register0x00000010 + -4) = unaff_EBP;
  *(undefined4 *)((int)register0x00000010 + -8) = 0xa99a9;
  iVar3 = ExplosionMagnitude__10CBreakable();
  if (0 < iVar3) {
    fVar6 = unaff_EBP[0x111];
    *(float **)((int)register0x00000010 + -4) = unaff_EBP;
    *(undefined1 **)((int)register0x00000010 + -8) = (undefined1 *)((int)register0x00000010 + 0x438)
    ;
    pcVar1 = *(code **)((int)fVar6 + 0xcc);
    *(undefined4 *)((int)register0x00000010 + -0xc) = 0xa99c7;
    (*pcVar1)();
    *(undefined4 *)((int)register0x00000010 + -0xc) = 1;
    fVar6 = *unaff_EBP;
    *(undefined4 *)((int)register0x00000010 + -0x10) = *(undefined4 *)((int)fVar6 + 0x184);
    *(undefined4 *)((int)register0x00000010 + -0x14) = *(undefined4 *)((int)fVar6 + 0x208);
    *(int *)((int)register0x00000010 + -0x18) = (int)fVar6 + 0x50;
    *(undefined1 **)((int)register0x00000010 + -0x1c) =
         (undefined1 *)((int)register0x00000010 + 0x438);
    *(undefined4 *)((int)register0x00000010 + -0x20) = 0xa99e4;
    ExplosionCreate__FRC6VectorT0P7edict_sii();
  }
  return;
}


// switchD_000cd67e::caseD_0  @ 000cd744
void switchD_000cd67e::caseD_0(void)

{
  int unaff_EBX;
  int *unaff_EDI;
  
  *(int *)(*unaff_EDI + 0x1ec) =
       (unaff_EBX + -0x739c6) - *(int *)(**(int **)(unaff_EBX + 0x15d4) + 0x98);
  return;
}


// switchD_000d839a::caseD_43  @ 000d842c
undefined4 switchD_000d839a::caseD_43(void)

{
  double dVar1;
  float *pfVar2;
  int unaff_EBX;
  int unaff_EBP;
  float in_stack_00000024;
  undefined4 *in_stack_000000e8;
  
  if (unaff_EBP == 0) {
    pfVar2 = (float *)**(undefined4 **)(unaff_EBX + 0x15d4);
    dVar1 = *(double *)(unaff_EBX + -0x72610);
  }
  else {
    pfVar2 = (float *)**(undefined4 **)(unaff_EBX + 0x15d4);
    dVar1 = *(double *)(unaff_EBX + -0x72618);
  }
  in_stack_000000e8[0x1bd] = (float)dVar1 + *pfVar2;
  in_stack_000000e8[0x1bd] = in_stack_00000024 + (float)in_stack_000000e8[0x1bd];
  return *in_stack_000000e8;
}


// switchD_000e5a5f::caseD_1  @ 000e5d9c
void switchD_000e5a5f::caseD_1(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_EDI;
  
  fVar1 = *(float *)**(undefined4 **)(unaff_EBX + 0x15d4);
  fVar2 = *(float *)(unaff_EDI + 0x550);
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    iVar3 = HasConditions__12CBaseMonsteri();
    if (iVar3 == 0) {
      *(undefined4 *)(unaff_EDI + 0x56c) = 4;
      caseD_4();
      return;
    }
  }
  return;
}


// switchD_000e5a5f::caseD_18  @ 000e6218
void switchD_000e5a5f::caseD_18(void)

{
  int iVar1;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x45c) != 0) {
    iVar1 = HasConditions__12CBaseMonsteri();
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EDI + 0x56c) = 4;
      caseD_4();
      return;
    }
  }
  return;
}


// switchD_000e5a5f::caseD_4  @ 000e62f1
void switchD_000e5a5f::caseD_4(void)

{
  return;
}


// switchD_000e63b2::caseD_1  @ 000e6cc4
void switchD_000e63b2::caseD_1(void)

{
  int unaff_EBX;
  int unaff_EBP;
  int in_stack_00000094;
  
  *(float *)(unaff_EBP + 0x550) =
       *(float *)**(undefined4 **)(unaff_EBX + 0x15d4) + *(float *)(in_stack_00000094 + 4);
  return;
}


// switchD_000f4e6f::caseD_59  @ 000f51f8
void switchD_000f4e6f::caseD_59(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar1 = IsTalking__12CTalkMonster();
  if (iVar1 != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(unaff_EDI + 0x6f4);
    if (iVar1 != 0) {
      __rf__7EHANDLE(unaff_EDI + 0x6f4);
      IdleHeadTurn__12CTalkMonsterR6Vector();
      goto LAB_000f526f;
    }
  }
  IdleHeadTurn__12CTalkMonsterR6Vector();
  FIdleHello__12CTalkMonster();
  iVar1 = (**(code **)(*(int *)(unaff_EBX + 0x15c8) + 0x168))(0,*(int *)(unaff_EDI + 0x690) * 0x14);
  if (iVar1 == 0) {
    FIdleSpeak__12CTalkMonster();
  }
LAB_000f526f:
  RunTask__12CBaseMonsterP6Task_t();
  if (*(int *)(unaff_EDI + 0x56c) == 4) {
    IdleHeadTurn__12CTalkMonsterR6Vector();
  }
  return;
}


// switchD_0011dc43::caseD_4  @ 0011dcc4
void switchD_0011dc43::caseD_4(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int in_stack_00000010;
  undefined4 *in_stack_00000014;
  int *in_stack_00000024;
  short *in_stack_00000028;
  int in_stack_00000030;
  undefined4 in_stack_00000140;
  
  uVar1 = __opP11CBaseEntity__7EHANDLE(in_stack_00000010 + in_stack_00000030 * 8);
  uVar1 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity(in_stack_00000140,uVar1);
  *in_stack_00000014 = uVar1;
  do {
    in_stack_00000030 = in_stack_00000030 + 1;
    if (*in_stack_00000028 <= in_stack_00000030) {
      FUN_0011ddc9((int)*in_stack_00000028);
      return;
    }
  } while (4 < *in_stack_00000024 - 2U);
                    /* WARNING: Could not recover jumptable at 0x0011dc43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0x9fdb8 + (*in_stack_00000024 - 2U) * 4)))();
  return;
}


// switchD_00124347::caseD_1  @ 001243fc
void switchD_00124347::caseD_1(void)

{
  return;
}


// switchD_0012ed30::caseD_6  @ 0012f174
void switchD_0012ed30::caseD_6(void)

{
  int unaff_EBX;
  uint unaff_ESI;
  
  if (unaff_ESI < 4) {
                    /* WARNING: Could not recover jumptable at 0x0012f186. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0x8e878 + unaff_ESI * 4)))();
    return;
  }
  return;
}


// switchD_0012ee0e::caseD_0  @ 0012ee20
void switchD_0012ee0e::caseD_0(void)

{
  FUN_0012f38f(0x3f4ccccd,0,100);
  return;
}


// switchD_0012eeb2::caseD_0  @ 0012eec4
void switchD_0012eeb2::caseD_0(void)

{
  FUN_0012f38f(0x3f4ccccd,0,100);
  return;
}


// switchD_0012eeb2::caseD_2  @ 0012ef04
void switchD_0012eeb2::caseD_2(void)

{
  FUN_0012f38f(0x3f4ccccd,0,100);
  return;
}


// switchD_0012f3c7::caseD_43  @ 0012f41c
undefined4 switchD_0012f3c7::caseD_43(void)

{
  return 0;
}


