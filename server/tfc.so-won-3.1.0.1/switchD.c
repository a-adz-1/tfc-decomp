// switchD_0009038a::caseD_1  @ 000904ec
undefined4 switchD_0009038a::caseD_1(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_ESI;
  
  iVar1 = (**(code **)(*(int *)(unaff_EBX + 0x13b4) + 0x168))(0,0xe);
  if ((iVar1 == 0) && (iVar1 = (**(code **)(*(int *)(unaff_ESI + 0x3d4) + 0x1c4))(), iVar1 != 0)) {
    return *(undefined4 *)(unaff_EBX + 0x15e8);
  }
  return *(undefined4 *)(unaff_EBX + 0x15ec);
}


// switchD_0009038a::caseD_13  @ 00090614
undefined4 switchD_0009038a::caseD_13(void)

{
  int unaff_EBX;
  
  return *(undefined4 *)(unaff_EBX + 0x163c);
}


// switchD_0009516d::caseD_0  @ 00095234
void switchD_0009516d::caseD_0(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int *unaff_EDI;
  
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x13b4) + 0x10c))(unaff_EBX + -0x70b94);
  *(undefined4 *)(*unaff_EDI + 0x1ec) = uVar1;
  return;
}


// switchD_0009dc7b::caseD_0  @ 0009dd54
void switchD_0009dc7b::caseD_0(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = unaff_EBX + -0x6fbf3;
  (**(code **)(*(int *)(unaff_EBX + 0x13b4) + 4))(unaff_EBX + -0x6fbde);
  (**(code **)(*(int *)(unaff_EBX + 0x13b4) + 4))(unaff_EBX + -0x6fbc8);
  MaterialSoundPrecache__10CBreakable9Materials(*(undefined4 *)(unaff_EDI + 0x3e0));
  if (*(int *)(unaff_EDI + 0x3f0) != 0) {
    iVar2 = *(int *)(**(int **)(unaff_EBX + 0x13c0) + 0x98) + *(int *)(unaff_EDI + 0x3f0);
  }
  uVar1 = (*(code *)**(undefined4 **)(unaff_EBX + 0x13b4))(iVar2);
  *(undefined4 *)(unaff_EDI + 1000) = uVar1;
  if (*(int *)(unaff_EDI + 0x3f4) != 0) {
    UTIL_PrecacheOther__FPCc
              (*(int *)(unaff_EDI + 0x3f4) + *(int *)(**(int **)(unaff_EBX + 0x13c0) + 0x98));
  }
  return;
}


// switchD_000b718b::caseD_6  @ 000b7200
void switchD_000b718b::caseD_6(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_EDI;
  code *pcStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 in_stack_00000028;
  float in_stack_0000002c;
  undefined4 *in_stack_00000030;
  undefined4 in_stack_00000038;
  float fVar2;
  
  in_stack_0000002c = in_stack_0000002c * *(float *)(*(int *)(unaff_EBX + 0x15b8) + 0x138);
  uStack00000014 = *(undefined4 *)(unaff_EBP + 0x14);
  uStack00000018 = *(undefined4 *)(unaff_EBP + 0x18);
  uStack0000001c = *(undefined4 *)(unaff_EBP + 0x1c);
  pcStack00000010 = *(code **)(*(int *)(unaff_EDI + 0x3d4) + 0x40);
  fVar2 = in_stack_0000002c;
  uVar1 = (*pcStack00000010)();
  SpawnBlood__FG6Vectorif(&stack0x00000014,uVar1,fVar2);
  uStack00000014 = *in_stack_00000030;
  uStack00000018 = in_stack_00000030[1];
  uStack0000001c = in_stack_00000030[2];
  pcStack00000010 = *(code **)(*(int *)(unaff_EDI + 0x3d4) + 0x44);
  (*pcStack00000010)();
  AddMultiDamage__FP9entvars_sP11CBaseEntityfi(in_stack_00000028);
  return;
}


// switchD_000b79f0::caseD_4  @ 000b7ba2
undefined4 switchD_000b79f0::caseD_4(void)

{
  int unaff_EDI;
  
  return *(undefined4 *)(unaff_EDI + 0x4f8);
}


// switchD_000c5b26::caseD_1  @ 000c5b50
void switchD_000c5b26::caseD_1(void)

{
  undefined2 uVar1;
  int unaff_EBX;
  int *unaff_EDI;
  
  (**(code **)(*(int *)(unaff_EBX + 0x13b4) + 4))(unaff_EBX + -0x6b3a8);
  *(int *)(*unaff_EDI + 0x1e8) =
       (unaff_EBX + -0x6b3a8) - *(int *)(**(int **)(unaff_EBX + 0x13c0) + 0x98);
  (**(code **)(*(int *)(unaff_EBX + 0x13b4) + 4))(unaff_EBX + -0x6b550);
  (**(code **)(*(int *)(unaff_EBX + 0x13b4) + 4))(unaff_EBX + -0x6b538);
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x13b4) + 0x1e8))(1,unaff_EBX + -0x6b33c);
  *(undefined2 *)(unaff_EDI + 0x107) = uVar1;
  return;
}


// switchD_000c5b26::switchdataD_000c5b28  @ 000c5b28
void switchD_000c5b26::switchdataD_000c5b28(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// switchD_000ca4a0::caseD_0  @ 000ca618
void switchD_000ca4a0::caseD_0(void)

{
  int iVar1;
  int unaff_EBX;
  int *unaff_EDI;
  float in_stack_00000010;
  
  if (((*(byte *)(*unaff_EDI + 0x1a5) & 2) == 0) && (unaff_EDI[0x13a] - 7U < 2)) {
    unaff_EDI[0x13b] = unaff_EDI[0x13a];
  }
  else if (*(int *)(*unaff_EDI + 0x1c0) < 2) {
    unaff_EDI[0x13b] = 3;
  }
  else if ((byte)((byte)((ushort)((ushort)(NAN(in_stack_00000010) ||
                                          NAN(*(float *)(unaff_EBX + -0x6a9fc))) << 10) >> 8) |
                 (byte)((ushort)((ushort)(in_stack_00000010 == *(float *)(unaff_EBX + -0x6a9fc)) <<
                                0xe) >> 8)) == 0x40) {
    unaff_EDI[0x13b] = 0x32;
  }
  else {
    unaff_EDI[0x13b] = 6;
  }
  if (unaff_EDI[0x13b] - 3U < 0x30) {
                    /* WARNING: Could not recover jumptable at 0x000ca69d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0xda9c4 + (unaff_EDI[0x13b] - 3U) * 4)))();
    return;
  }
  if (unaff_EDI[0x13a] != unaff_EDI[0x13b]) {
    unaff_EDI[0x13a] = unaff_EDI[0x13b];
    iVar1 = LookupActivity__14CBaseAnimatingi();
    if (*(int *)(*unaff_EDI + 0x128) != iVar1) {
      *(undefined4 *)(*unaff_EDI + 300) = 0;
      *(int *)(*unaff_EDI + 0x128) = iVar1;
      *(undefined4 *)(*unaff_EDI + 0x130) = 0;
      ResetSequenceInfo__14CBaseAnimating();
    }
  }
  return;
}


// switchD_000ca531::switchdataD_000ca534  @ 000ca534
void switchD_000ca531::switchdataD_000ca534(void)

{
  int *piVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar7;
  uint in_EAX;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  char in_CH;
  int in_EDX;
  int unaff_EBX;
  int unaff_EBP;
  undefined1 *unaff_EDI;
  char in_CF;
  
  *(char *)(unaff_EBX + -0x54fbfff3) = *(char *)(unaff_EBX + -0x54fbfff3) + in_CH + in_CF;
  uVar2 = (undefined1)in_EAX;
  *unaff_EDI = uVar2;
  uVar4 = CONCAT22((short)((in_EAX | 0xdaaf800) >> 0x10),
                   CONCAT11((char)((in_EAX | 0xdaaf800) >> 8) + in_CH,uVar2)) | 0xdaae000;
  bVar7 = (char)(uVar4 >> 8) + (char)in_EDX;
  piVar1 = (int *)(unaff_EDI + 2);
  unaff_EDI[1] = uVar2;
  pcVar5 = (char *)(in_EDX + -0x7838fff3 + unaff_EBP * 4);
  *pcVar5 = *pcVar5 + (char)((uint)unaff_EBX >> 8);
  cVar3 = in((short)in_EDX);
  pcVar5 = (char *)(CONCAT31((int3)(CONCAT22((short)(uVar4 >> 0x10),CONCAT11(bVar7,uVar2)) >> 8),
                             cVar3) | 0xdaac800);
  *(char *)((int)pcVar5 * 2) = *(char *)((int)pcVar5 * 2) + (bVar7 | 200);
  *pcVar5 = *pcVar5 + cVar3;
  iVar6 = LookupActivity__14CBaseAnimatingi(piVar1,*(undefined4 *)(unaff_EDI + 0x4ee));
  if (iVar6 == -1) {
    *(undefined4 *)(unaff_EDI + 0x4ee) = 0x24;
  }
  if (*(int *)(unaff_EDI + 0x4ee) - 3U < 0x30) {
                    /* WARNING: Could not recover jumptable at 0x000ca69d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0xda9c4 + (*(int *)(unaff_EDI + 0x4ee) - 3U) * 4)))
              ();
    return;
  }
  if (*(int *)(unaff_EDI + 0x4ea) != *(int *)(unaff_EDI + 0x4ee)) {
    *(undefined4 *)(unaff_EDI + 0x4ea) = *(undefined4 *)(unaff_EDI + 0x4ee);
    iVar6 = LookupActivity__14CBaseAnimatingi(piVar1,*(undefined4 *)(unaff_EDI + 0x4ee));
    if (*(int *)(*piVar1 + 0x128) != iVar6) {
      *(undefined4 *)(*piVar1 + 300) = 0;
      *(int *)(*piVar1 + 0x128) = iVar6;
      *(undefined4 *)(*piVar1 + 0x130) = 0;
      ResetSequenceInfo__14CBaseAnimating(piVar1);
    }
  }
  return;
}


// switchD_000d75c0::caseD_1  @ 000d75e8
void switchD_000d75c0::caseD_1(void)

{
  TeamFortress_DisplayDetectionItems__11CBasePlayer();
  return;
}


// switchD_000d99c3::caseD_1  @ 000d9d00
void switchD_000d99c3::caseD_1(void)

{
  float fVar1;
  float fVar2;
  int unaff_EBX;
  int unaff_EDI;
  
  fVar1 = *(float *)**(undefined4 **)(unaff_EBX + 0x13c0);
  fVar2 = *(float *)(unaff_EDI + 0x4e0);
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    FUN_000da189();
    return;
  }
  return;
}


// switchD_000d99c3::caseD_18  @ 000da17c
void switchD_000d99c3::caseD_18(void)

{
  int iVar1;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x3ec) != 0) {
    iVar1 = HasConditions__12CBaseMonsteri();
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EDI + 0x4fc) = 4;
      caseD_4();
      return;
    }
  }
  return;
}


// switchD_000d99c3::caseD_4  @ 000da255
void switchD_000d99c3::caseD_4(void)

{
  return;
}


// switchD_000da316::caseD_1  @ 000dac28
void switchD_000da316::caseD_1(void)

{
  int unaff_EBX;
  int unaff_EBP;
  int in_stack_00000094;
  
  *(float *)(unaff_EBP + 0x4e0) =
       *(float *)**(undefined4 **)(unaff_EBX + 0x13c0) + *(float *)(in_stack_00000094 + 4);
  return;
}


// switchD_000dc650::caseD_3  @ 000dc764
void switchD_000dc650::caseD_3(void)

{
  int unaff_EBX;
  int *unaff_EDI;
  
  (**(code **)(*(int *)(unaff_EBX + 0x13b4) + 0xf4))(2,unaff_EBX + -0x691e4);
  (**(code **)(*(int *)(unaff_EBX + 0x13b4) + 0xf4))
            (2,unaff_EBX + -0x691b9,
             *(int *)(*unaff_EDI + 0x1cc) + *(int *)(**(int **)(unaff_EBX + 0x13c0) + 0x98));
  unaff_EDI[0x13e] = 6;
  if (unaff_EDI[0x13d] == 6) {
    (**(code **)(unaff_EDI[0xf5] + 0x16c))();
    ChangeSchedule__12CBaseMonsterP10Schedule_t();
  }
  return;
}


// switchD_000e7d2b::caseD_4e  @ 000e8138
void switchD_000e7d2b::caseD_4e(void)

{
  int unaff_EDI;
  
  __as__7EHANDLEP11CBaseEntity(unaff_EDI + 0x684,0);
  StartTask__12CBaseMonsterP6Task_t();
  return;
}


// switchD_000e819b::caseD_59  @ 000e8524
void switchD_000e819b::caseD_59(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar1 = IsTalking__12CTalkMonster();
  if (iVar1 != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(unaff_EDI + 0x684);
    if (iVar1 != 0) {
      __rf__7EHANDLE(unaff_EDI + 0x684);
      IdleHeadTurn__12CTalkMonsterR6Vector();
      goto LAB_000e859b;
    }
  }
  IdleHeadTurn__12CTalkMonsterR6Vector();
  FIdleHello__12CTalkMonster();
  iVar1 = (**(code **)(*(int *)(unaff_EBX + 0x13b4) + 0x168))(0,*(int *)(unaff_EDI + 0x620) * 0x14);
  if (iVar1 == 0) {
    FIdleSpeak__12CTalkMonster();
  }
LAB_000e859b:
  RunTask__12CBaseMonsterP6Task_t();
  if (*(int *)(unaff_EDI + 0x4fc) == 4) {
    IdleHeadTurn__12CTalkMonsterR6Vector();
  }
  return;
}


// switchD_000f7ac3::caseD_1  @ 000f7b34
void switchD_000f7ac3::caseD_1(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int unaff_EBX;
  int *unaff_EBP;
  longdouble lVar12;
  int in_stack_0000002c;
  int in_stack_00000030;
  int iStack00000034;
  int in_stack_00000038;
  
  iStack00000034 = unaff_EBP[0x39];
  unaff_EBP[0x35] = unaff_EBP[0x35] - in_stack_00000038;
  unaff_EBP[0x39] = unaff_EBP[0x39] - iStack00000034;
  unaff_EBP[0x37] = unaff_EBP[0x37] - in_stack_00000030;
  if (*(int *)(*unaff_EBP + 0x20c) != 9) goto LAB_000f7f09;
  iVar11 = 2;
  if (in_stack_00000038 < 0x14) {
    iVar11 = 3;
  }
  if (iStack00000034 < 10) {
    iVar11 = iVar11 + 1;
  }
  iVar11 = (int)ROUND(ROUND((longdouble)unaff_EBP[0x37] / (longdouble)iVar11));
  if (ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11) <=
      (float)*(double *)(unaff_EBX + -0x64a1c)) {
    in_stack_0000002c = (int)ROUND(ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11));
    if (in_stack_0000002c != 0) goto LAB_000f7c6c;
  }
  else {
    in_stack_0000002c = 0x14;
LAB_000f7c6c:
    ClientPrint__FP9entvars_siPCcN42(*unaff_EBP,1,unaff_EBX + -0x64a6f,0,0,0,0);
    unaff_EBP[0x37] = unaff_EBP[0x37] + in_stack_0000002c * -2;
  }
  if (ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11) <=
      (float)*(double *)(unaff_EBX + -0x64a14)) {
    in_stack_00000030 = (int)ROUND(ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11));
    if (in_stack_00000030 != 0) goto LAB_000f7d34;
  }
  else {
    in_stack_00000030 = 10;
LAB_000f7d34:
    ClientPrint__FP9entvars_siPCcN42(*unaff_EBP,1,unaff_EBX + -0x64a62,0,0,0,0);
    unaff_EBP[0x37] = unaff_EBP[0x37] + in_stack_00000030 * -2;
  }
  if (in_stack_00000038 < 0x14) {
    lVar12 = (longdouble)(0x14 - in_stack_00000038);
    if (ROUND((longdouble)iVar11) + (longdouble)in_stack_00000038 <= lVar12) {
      lVar12 = ROUND((longdouble)iVar11) + (longdouble)in_stack_00000038;
    }
    iVar1 = (int)ROUND(lVar12);
    if (iVar1 != 0) {
      ClientPrint__FP9entvars_siPCcN42(*unaff_EBP,1,unaff_EBX + -0x64a56,0,0,0,0);
      unaff_EBP[0x37] = unaff_EBP[0x37] - iVar1;
    }
    in_stack_00000038 = in_stack_00000038 + iVar1;
  }
  if (iStack00000034 < 10) {
    fVar2 = (float)(10 - iStack00000034);
    if (ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11) + (float)iStack00000034 <= fVar2) {
      fVar2 = ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11) + (float)iStack00000034;
    }
    iVar11 = (int)ROUND(fVar2);
    if (iVar11 != 0) {
      ClientPrint__FP9entvars_siPCcN42(*unaff_EBP,1,unaff_EBX + -0x64a4a,0,0,0,0);
      unaff_EBP[0x37] = unaff_EBP[0x37] + iVar11 * -2;
    }
    iStack00000034 = iStack00000034 + iVar11;
  }
LAB_000f7f09:
  if (((in_stack_00000038 != 0) || (iStack00000034 != 0)) || (in_stack_00000030 != 0)) {
    unaff_EBP[0x346] = unaff_EBP[0x346] + 1;
    if (3 < unaff_EBP[0x346]) {
      RemoveOldAmmobox__11CBasePlayer();
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*unaff_EBP + 0x208),3,unaff_EBX + -0x64a3c,0x3f800000,0x3f4ccccd,0,
               100);
    piVar10 = (int *)GetClassPtr__H1Z10CWeaponBox_PX01_PX01(0);
    (**(code **)(piVar10[0xf5] + 8))(piVar10);
    *(int *)(*piVar10 + 0x1d0) =
         (unaff_EBX + -0x65ffc) - *(int *)(**(int **)(unaff_EBX + 0x13c0) + 0x98);
    *(int *)*piVar10 = (unaff_EBX + -0x65ffc) - *(int *)(**(int **)(unaff_EBX + 0x13c0) + 0x98);
    *(undefined4 *)(*piVar10 + 400) = *(undefined4 *)(*unaff_EBP + 0x208);
    piVar10[0xfc] =
         (int)(*(float *)(unaff_EBX + -0x64a0c) + *(float *)**(undefined4 **)(unaff_EBX + 0x13c0));
    piVar10[0x48] = unaff_EBP[0x48];
    piVar10[0xfd] = *(int *)**(undefined4 **)(unaff_EBX + 0x13c0);
    piVar10[0x35] = in_stack_00000038;
    piVar10[0x39] = iStack00000034;
    piVar10[0x37] = in_stack_00000030;
    piVar10[0x33] = in_stack_0000002c;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar10,*unaff_EBP + 8);
    UTIL_MakeVectors__FRC6Vector(*unaff_EBP + 0x74);
    iVar11 = *piVar10;
    puVar8 = *(undefined4 **)(unaff_EBX + 0x13e8);
    *(undefined4 *)(iVar11 + 0x50) = *puVar8;
    *(undefined4 *)(iVar11 + 0x54) = puVar8[1];
    *(undefined4 *)(iVar11 + 0x58) = puVar8[2];
    iVar11 = *piVar10;
    piVar9 = *(int **)(unaff_EBX + 0x13c0);
    fVar2 = *(float *)(unaff_EBX + -0x64a08);
    fVar3 = *(float *)(*piVar9 + 0x2c);
    fVar4 = *(float *)(*piVar9 + 0x30);
    iVar1 = *piVar9;
    fVar5 = *(float *)(unaff_EBX + -0x64a04);
    fVar6 = *(float *)(iVar1 + 0x38);
    fVar7 = *(float *)(iVar1 + 0x3c);
    *(float *)(iVar11 + 0x20) =
         *(float *)(*piVar9 + 0x28) * fVar2 + *(float *)(iVar1 + 0x34) * fVar5;
    *(float *)(iVar11 + 0x24) = fVar3 * fVar2 + fVar6 * fVar5;
    *(float *)(iVar11 + 0x28) = fVar2 * fVar4 + fVar5 * fVar7;
    iVar11 = *(int *)(unaff_EBX + 0x1ba4);
    piVar10[3] = -0x10000;
    piVar10[4] = iVar11;
    *(float *)(*piVar10 + 0x104) =
         *(float *)(unaff_EBX + -0x64a00) + *(float *)**(undefined4 **)(unaff_EBX + 0x13c0);
  }
  return;
}


// switchD_000f7ac3::caseD_9  @ 000f7b40
void switchD_000f7ac3::caseD_9(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int unaff_EBX;
  int *unaff_EBP;
  longdouble lVar12;
  int in_stack_0000002c;
  int in_stack_00000030;
  int iStack00000034;
  int in_stack_00000038;
  
  iStack00000034 = unaff_EBP[0x39];
  unaff_EBP[0x35] = unaff_EBP[0x35] - in_stack_00000038;
  unaff_EBP[0x39] = unaff_EBP[0x39] - iStack00000034;
  unaff_EBP[0x37] = unaff_EBP[0x37] - in_stack_00000030;
  if (*(int *)(*unaff_EBP + 0x20c) != 9) goto LAB_000f7f09;
  iVar11 = 2;
  if (in_stack_00000038 < 0x14) {
    iVar11 = 3;
  }
  if (iStack00000034 < 10) {
    iVar11 = iVar11 + 1;
  }
  iVar11 = (int)ROUND(ROUND((longdouble)unaff_EBP[0x37] / (longdouble)iVar11));
  if (ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11) <=
      (float)*(double *)(unaff_EBX + -0x64a1c)) {
    in_stack_0000002c = (int)ROUND(ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11));
    if (in_stack_0000002c != 0) goto LAB_000f7c6c;
  }
  else {
    in_stack_0000002c = 0x14;
LAB_000f7c6c:
    ClientPrint__FP9entvars_siPCcN42(*unaff_EBP,1,unaff_EBX + -0x64a6f,0,0,0,0);
    unaff_EBP[0x37] = unaff_EBP[0x37] + in_stack_0000002c * -2;
  }
  if (ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11) <=
      (float)*(double *)(unaff_EBX + -0x64a14)) {
    in_stack_00000030 = (int)ROUND(ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11));
    if (in_stack_00000030 != 0) goto LAB_000f7d34;
  }
  else {
    in_stack_00000030 = 10;
LAB_000f7d34:
    ClientPrint__FP9entvars_siPCcN42(*unaff_EBP,1,unaff_EBX + -0x64a62,0,0,0,0);
    unaff_EBP[0x37] = unaff_EBP[0x37] + in_stack_00000030 * -2;
  }
  if (in_stack_00000038 < 0x14) {
    lVar12 = (longdouble)(0x14 - in_stack_00000038);
    if (ROUND((longdouble)iVar11) + (longdouble)in_stack_00000038 <= lVar12) {
      lVar12 = ROUND((longdouble)iVar11) + (longdouble)in_stack_00000038;
    }
    iVar1 = (int)ROUND(lVar12);
    if (iVar1 != 0) {
      ClientPrint__FP9entvars_siPCcN42(*unaff_EBP,1,unaff_EBX + -0x64a56,0,0,0,0);
      unaff_EBP[0x37] = unaff_EBP[0x37] - iVar1;
    }
    in_stack_00000038 = in_stack_00000038 + iVar1;
  }
  if (iStack00000034 < 10) {
    fVar2 = (float)(10 - iStack00000034);
    if (ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11) + (float)iStack00000034 <= fVar2) {
      fVar2 = ROUND(*(float *)(unaff_EBX + -0x64a24) * (float)iVar11) + (float)iStack00000034;
    }
    iVar11 = (int)ROUND(fVar2);
    if (iVar11 != 0) {
      ClientPrint__FP9entvars_siPCcN42(*unaff_EBP,1,unaff_EBX + -0x64a4a,0,0,0,0);
      unaff_EBP[0x37] = unaff_EBP[0x37] + iVar11 * -2;
    }
    iStack00000034 = iStack00000034 + iVar11;
  }
LAB_000f7f09:
  if (((in_stack_00000038 != 0) || (iStack00000034 != 0)) || (in_stack_00000030 != 0)) {
    unaff_EBP[0x346] = unaff_EBP[0x346] + 1;
    if (3 < unaff_EBP[0x346]) {
      RemoveOldAmmobox__11CBasePlayer();
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*unaff_EBP + 0x208),3,unaff_EBX + -0x64a3c,0x3f800000,0x3f4ccccd,0,
               100);
    piVar10 = (int *)GetClassPtr__H1Z10CWeaponBox_PX01_PX01(0);
    (**(code **)(piVar10[0xf5] + 8))(piVar10);
    *(int *)(*piVar10 + 0x1d0) =
         (unaff_EBX + -0x65ffc) - *(int *)(**(int **)(unaff_EBX + 0x13c0) + 0x98);
    *(int *)*piVar10 = (unaff_EBX + -0x65ffc) - *(int *)(**(int **)(unaff_EBX + 0x13c0) + 0x98);
    *(undefined4 *)(*piVar10 + 400) = *(undefined4 *)(*unaff_EBP + 0x208);
    piVar10[0xfc] =
         (int)(*(float *)(unaff_EBX + -0x64a0c) + *(float *)**(undefined4 **)(unaff_EBX + 0x13c0));
    piVar10[0x48] = unaff_EBP[0x48];
    piVar10[0xfd] = *(int *)**(undefined4 **)(unaff_EBX + 0x13c0);
    piVar10[0x35] = in_stack_00000038;
    piVar10[0x39] = iStack00000034;
    piVar10[0x37] = in_stack_00000030;
    piVar10[0x33] = in_stack_0000002c;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar10,*unaff_EBP + 8);
    UTIL_MakeVectors__FRC6Vector(*unaff_EBP + 0x74);
    iVar11 = *piVar10;
    puVar8 = *(undefined4 **)(unaff_EBX + 0x13e8);
    *(undefined4 *)(iVar11 + 0x50) = *puVar8;
    *(undefined4 *)(iVar11 + 0x54) = puVar8[1];
    *(undefined4 *)(iVar11 + 0x58) = puVar8[2];
    iVar11 = *piVar10;
    piVar9 = *(int **)(unaff_EBX + 0x13c0);
    fVar2 = *(float *)(unaff_EBX + -0x64a08);
    fVar3 = *(float *)(*piVar9 + 0x2c);
    fVar4 = *(float *)(*piVar9 + 0x30);
    iVar1 = *piVar9;
    fVar5 = *(float *)(unaff_EBX + -0x64a04);
    fVar6 = *(float *)(iVar1 + 0x38);
    fVar7 = *(float *)(iVar1 + 0x3c);
    *(float *)(iVar11 + 0x20) =
         *(float *)(*piVar9 + 0x28) * fVar2 + *(float *)(iVar1 + 0x34) * fVar5;
    *(float *)(iVar11 + 0x24) = fVar3 * fVar2 + fVar6 * fVar5;
    *(float *)(iVar11 + 0x28) = fVar2 * fVar4 + fVar5 * fVar7;
    iVar11 = *(int *)(unaff_EBX + 0x1ba4);
    piVar10[3] = -0x10000;
    piVar10[4] = iVar11;
    *(float *)(*piVar10 + 0x104) =
         *(float *)(unaff_EBX + -0x64a00) + *(float *)**(undefined4 **)(unaff_EBX + 0x13c0);
  }
  return;
}


// switchD_001165c6::caseD_0  @ 001165d8
void switchD_001165c6::caseD_0(void)

{
  int unaff_ESI;
  
  WindUp__11CTFAssaultC();
  *(undefined4 *)(unaff_ESI + 0x408) = 0x3f000000;
  *(undefined4 *)(unaff_ESI + 0x410) = 0x3f19999a;
  FUN_0011669e();
  return;
}


// switchD_001165c6::switchdataD_001165c8  @ 001165c8
/* WARNING: Control flow encountered bad instruction data */

void switchD_001165c6::switchdataD_001165c8(void)

{
  byte *in_EAX;
  
  *in_EAX = *in_EAX | (byte)in_EAX;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// switchD_0011fcc4::caseD_1  @ 0011fd90
void switchD_0011fcc4::caseD_1(void)

{
  int unaff_EBX;
  uint unaff_ESI;
  
  if (unaff_ESI < 4) {
                    /* WARNING: Could not recover jumptable at 0x0011fda2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0x852c0 + unaff_ESI * 4)))();
    return;
  }
  return;
}


// switchD_0011ff8e::caseD_3  @ 00120000
void switchD_0011ff8e::caseD_3(void)

{
  int unaff_EBX;
  undefined4 in_stack_00000028;
  
  (**(code **)((int)&__DT_REL[0x1167].r_info + **(int **)(unaff_EBX + 0x236c)))
            (4,unaff_EBX + -0x5fddb,in_stack_00000028,0x3f4ccccd,0,100);
  return;
}


