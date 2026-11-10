// switchD_000995ef::caseD_1  @ 0009974c
undefined4 switchD_000995ef::caseD_1(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_ESI;
  
  iVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x168))(0,0xe);
  if ((iVar1 == 0) && (iVar1 = (**(code **)(*(int *)(unaff_ESI + 0x454) + 0x1cc))(), iVar1 != 0)) {
    return *(undefined4 *)(unaff_EBX + 0x1658);
  }
  return *(undefined4 *)(unaff_EBX + 0x165c);
}


// switchD_000995ef::caseD_27  @ 00099898
undefined4 switchD_000995ef::caseD_27(void)

{
  int unaff_EBX;
  
  return *(undefined4 *)(unaff_EBX + 0x16c0);
}


// switchD_0009d28f::caseD_0  @ 0009d494
void switchD_0009d28f::caseD_0(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBX;
  int *unaff_EDI;
  
  uVar2 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x10c))(unaff_EBX + -0x51eac);
  *(undefined4 *)(*unaff_EDI + 0x1ec) = uVar2;
  if (*(byte *)((int)unaff_EDI + 0x4fa) < 9) {
                    /* WARNING: Could not recover jumptable at 0x0009d4d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX -
              *(int *)(unaff_EBX + -0xfeddc + (uint)*(byte *)((int)unaff_EDI + 0x4fa) * 4)))();
    return;
  }
  uVar2 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x10c))(unaff_EBX + -0x51eac);
  *(undefined4 *)(*unaff_EDI + 0x1f0) = uVar2;
  if ((char)unaff_EDI[0x148] != '\0') {
    uVar2 = ButtonSound__Fi((char)unaff_EDI[0x148]);
    (**(code **)(*(int *)(unaff_EBX + 0x1360) + 4))(uVar2);
    iVar3 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x10c))(uVar2);
    unaff_EDI[0x13f] = iVar3;
  }
  if (*(char *)((int)unaff_EDI + 0x522) != '\0') {
    uVar2 = ButtonSound__Fi(*(undefined1 *)((int)unaff_EDI + 0x522));
    (**(code **)(*(int *)(unaff_EBX + 0x1360) + 4))(uVar2);
    iVar3 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x10c))(uVar2);
    unaff_EDI[0x141] = iVar3;
  }
  uVar4 = *(byte *)((int)unaff_EDI + 0x521) - 1;
  if (uVar4 < 9) {
                    /* WARNING: Could not recover jumptable at 0x0009d725. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0xfeb88 + uVar4 * 4)))();
    return;
  }
  unaff_EDI[0x140] = 0;
  uVar4 = *(byte *)((int)unaff_EDI + 0x523) - 1;
  if (uVar4 < 8) {
                    /* WARNING: Could not recover jumptable at 0x0009d813. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0xfea98 + uVar4 * 4)))();
    return;
  }
  unaff_EDI[0x142] = 0;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x1e8))(1,unaff_EBX + -0x51cec);
  *(undefined2 *)((int)unaff_EDI + 0x52a) = uVar1;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x1e8))(1,unaff_EBX + -0x51cd4);
  *(undefined2 *)(unaff_EDI + 0x14b) = uVar1;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x1e8))(1,unaff_EBX + -0x51cba);
  *(undefined2 *)((int)unaff_EDI + 0x52e) = uVar1;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x1e8))(1,unaff_EBX + -0x51ca0);
  *(undefined2 *)(unaff_EDI + 0x14c) = uVar1;
  return;
}


// switchD_0009d28f::caseD_5  @ 0009d380
void switchD_0009d28f::caseD_5(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBX;
  int *unaff_EDI;
  
  (**(code **)(*(int *)(unaff_EBX + 0x1360) + 4))(unaff_EBX + -0x51e4c);
  uVar2 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x10c))(unaff_EBX + -0x51e4c);
  *(undefined4 *)(*unaff_EDI + 0x1ec) = uVar2;
  if (*(byte *)((int)unaff_EDI + 0x4fa) < 9) {
                    /* WARNING: Could not recover jumptable at 0x0009d4d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX -
              *(int *)(unaff_EBX + -0xfeddc + (uint)*(byte *)((int)unaff_EDI + 0x4fa) * 4)))();
    return;
  }
  uVar2 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x10c))(unaff_EBX + -0x51eac);
  *(undefined4 *)(*unaff_EDI + 0x1f0) = uVar2;
  if ((char)unaff_EDI[0x148] != '\0') {
    uVar2 = ButtonSound__Fi((char)unaff_EDI[0x148]);
    (**(code **)(*(int *)(unaff_EBX + 0x1360) + 4))(uVar2);
    iVar3 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x10c))(uVar2);
    unaff_EDI[0x13f] = iVar3;
  }
  if (*(char *)((int)unaff_EDI + 0x522) != '\0') {
    uVar2 = ButtonSound__Fi(*(undefined1 *)((int)unaff_EDI + 0x522));
    (**(code **)(*(int *)(unaff_EBX + 0x1360) + 4))(uVar2);
    iVar3 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x10c))(uVar2);
    unaff_EDI[0x141] = iVar3;
  }
  uVar4 = *(byte *)((int)unaff_EDI + 0x521) - 1;
  if (uVar4 < 9) {
                    /* WARNING: Could not recover jumptable at 0x0009d725. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0xfeb88 + uVar4 * 4)))();
    return;
  }
  unaff_EDI[0x140] = 0;
  uVar4 = *(byte *)((int)unaff_EDI + 0x523) - 1;
  if (uVar4 < 8) {
                    /* WARNING: Could not recover jumptable at 0x0009d813. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0xfea98 + uVar4 * 4)))();
    return;
  }
  unaff_EDI[0x142] = 0;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x1e8))(1,unaff_EBX + -0x51cec);
  *(undefined2 *)((int)unaff_EDI + 0x52a) = uVar1;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x1e8))(1,unaff_EBX + -0x51cd4);
  *(undefined2 *)(unaff_EDI + 0x14b) = uVar1;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x1e8))(1,unaff_EBX + -0x51cba);
  *(undefined2 *)((int)unaff_EDI + 0x52e) = uVar1;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x1e8))(1,unaff_EBX + -0x51ca0);
  *(undefined2 *)(unaff_EDI + 0x14c) = uVar1;
  return;
}


// switchD_0009eb07::caseD_1  @ 0009eb30
void switchD_0009eb07::caseD_1(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int *unaff_EDI;
  
  (**(code **)(*(int *)(unaff_EBX + 0x1360) + 4))(unaff_EBX + -0x51e9c);
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x10c))(unaff_EBX + -0x51e9c);
  *(undefined4 *)(*unaff_EDI + 0x1ec) = uVar1;
  return;
}


// switchD_0009eb07::caseD_2  @ 0009eb54
void switchD_0009eb07::caseD_2(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int *unaff_EDI;
  
  (**(code **)(*(int *)(unaff_EBX + 0x1360) + 4))(unaff_EBX + -0x51e88);
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x10c))(unaff_EBX + -0x51e88);
  *(undefined4 *)(*unaff_EDI + 0x1ec) = uVar1;
  return;
}


// switchD_0009eb07::caseD_7  @ 0009ec08
void switchD_0009eb07::caseD_7(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int *unaff_EDI;
  
  (**(code **)(*(int *)(unaff_EBX + 0x1360) + 4))(unaff_EBX + -0x51e24);
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x10c))(unaff_EBX + -0x51e24);
  *(undefined4 *)(*unaff_EDI + 0x1ec) = uVar1;
  return;
}


// switchD_000bf67e::caseD_0  @ 000bf840
void switchD_000bf67e::caseD_0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  code *pcVar7;
  float *pfVar8;
  int *piVar9;
  undefined4 *puVar10;
  float fVar11;
  int iVar12;
  int in_ECX;
  int iVar13;
  int unaff_EBX;
  int unaff_EBP;
  uint uVar14;
  undefined2 in_FPUControlWord;
  unkbyte10 Var15;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  longdouble lVar20;
  longdouble lVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  
  *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
  *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
  *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
  *(undefined4 *)(unaff_EBP + -0xe4) = *(undefined4 *)(in_ECX + 0x454);
  (**(code **)(*(int *)(unaff_EBP + -0xe4) + 0x34))();
  do {
    if (*(int *)(unaff_EBP + -0xcc) == 1) {
      puVar10 = *(undefined4 **)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x74) = *puVar10;
      *(undefined4 *)(unaff_EBP + -0x70) = puVar10[1];
      *(undefined4 *)(unaff_EBP + -0x6c) = puVar10[2];
      *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x1c);
      dVar6 = *(double *)(unaff_EBX + -0x4e320);
      *(undefined2 *)(unaff_EBP + -0xc0) = in_FPUControlWord;
      *(uint *)(unaff_EBP + -200) =
           CONCAT22((short)((uint)*(undefined4 *)(unaff_EBP + -0xc0) >> 0x10),
                    CONCAT11(0xc,(char)*(undefined4 *)(unaff_EBP + -0xc0)));
      *(int *)(unaff_EBP + -0xe4) =
           (int)ROUND((float)dVar6 * *(float *)(unaff_EBP + 0x1c) * *(float *)(unaff_EBP + -0x28));
      in_FPUControlWord = *(undefined2 *)(unaff_EBP + -0xc0);
      UTIL_BubbleTrail__FG6VectorT0i
                (unaff_EBP + -0x74,unaff_EBP + -0x68,*(undefined4 *)(unaff_EBP + -0xe4));
    }
    *(int *)(unaff_EBP + -0xcc) = *(int *)(unaff_EBP + -0xcc) + 1;
    if (*(uint *)(unaff_EBP + 0xc) < *(uint *)(unaff_EBP + -0xcc)) {
      ApplyMultiDamage__FP9entvars_sT0
                (**(undefined4 **)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x2c));
      return;
    }
    do {
      Var15 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x16c))(0xbf000000,0x3f000000);
      pcVar7 = *(code **)(*(int *)(unaff_EBX + 0x1360) + 0x16c);
      *(unkbyte10 *)(unaff_EBP + -0xe0) = Var15;
      lVar16 = (longdouble)(*pcVar7)(0xbf000000,0x3f000000);
      *(float *)(unaff_EBP + -0xd0) = (float)(*(longdouble *)(unaff_EBP + -0xe0) + lVar16);
      Var15 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x16c))(0xbf000000,0x3f000000);
      pcVar7 = *(code **)(*(int *)(unaff_EBX + 0x1360) + 0x16c);
      *(unkbyte10 *)(unaff_EBP + -0xe0) = Var15;
      lVar17 = (longdouble)(*pcVar7)(0xbf000000,0x3f000000);
      lVar17 = *(longdouble *)(unaff_EBP + -0xe0) + lVar17;
      lVar19 = lVar17 * lVar17 +
               (longdouble)*(float *)(unaff_EBP + -0xd0) * (longdouble)*(float *)(unaff_EBP + -0xd0)
      ;
      lVar16 = (longdouble)1;
    } while ((byte)(lVar16 < lVar19 |
                    (byte)((ushort)((ushort)(NAN(lVar16) || NAN(lVar19)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(lVar16 == lVar19) << 0xe) >> 8)) == 1);
    pfVar8 = *(float **)(unaff_EBP + 0x14);
    lVar18 = (longdouble)*(float *)(unaff_EBP + -0xd0) * (longdouble)**(float **)(unaff_EBP + 0x18);
    lVar20 = (longdouble)*(float *)(unaff_EBP + -0x44) * lVar18;
    lVar21 = (longdouble)*(float *)(unaff_EBP + -0x40) * lVar18;
    lVar18 = lVar18 * (longdouble)*(float *)(unaff_EBP + -0x3c);
    *(float *)(unaff_EBP + -0x74) = (float)lVar20;
    *(float *)(unaff_EBP + -0x70) = (float)lVar21;
    *(float *)(unaff_EBP + -0x6c) = (float)lVar18;
    lVar20 = lVar20 + (longdouble)*pfVar8;
    lVar21 = lVar21 + (longdouble)pfVar8[1];
    lVar18 = lVar18 + (longdouble)pfVar8[2];
    *(float *)(unaff_EBP + -0x68) = (float)lVar20;
    *(float *)(unaff_EBP + -100) = (float)lVar21;
    *(float *)(unaff_EBP + -0x60) = (float)lVar18;
    lVar17 = lVar17 * (longdouble)(*(float **)(unaff_EBP + 0x18))[1];
    lVar16 = (longdouble)*(float *)(unaff_EBP + -0x50) * lVar17;
    lVar20 = lVar20 + lVar16;
    lVar19 = (longdouble)*(float *)(unaff_EBP + -0x4c) * lVar17;
    lVar21 = lVar21 + lVar19;
    lVar17 = lVar17 * (longdouble)*(float *)(unaff_EBP + -0x48);
    lVar18 = lVar18 + lVar17;
    pfVar8 = *(float **)(unaff_EBP + 0x10);
    *(float *)(unaff_EBP + -0x80) = (float)lVar16;
    *(float *)(unaff_EBP + -0x7c) = (float)lVar19;
    *(float *)(unaff_EBP + -0x78) = (float)lVar17;
    *(float *)(unaff_EBP + -0x5c) = (float)lVar20;
    lVar20 = lVar20 * (longdouble)*(float *)(unaff_EBP + 0x1c);
    *(float *)(unaff_EBP + -0x58) = (float)lVar21;
    lVar21 = lVar21 * (longdouble)*(float *)(unaff_EBP + 0x1c);
    *(float *)(unaff_EBP + -0x54) = (float)lVar18;
    lVar18 = lVar18 * (longdouble)*(float *)(unaff_EBP + 0x1c);
    *(float *)(unaff_EBP + -0x68) = (float)lVar20;
    *(float *)(unaff_EBP + -100) = (float)lVar21;
    *(float *)(unaff_EBP + -0x60) = (float)lVar18;
    fVar1 = pfVar8[1];
    fVar2 = pfVar8[2];
    *(float *)(unaff_EBP + -0x74) = (float)(lVar20 + (longdouble)*pfVar8);
    *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EBP + -0x74);
    *(float *)(unaff_EBP + -0x70) = (float)(lVar21 + (longdouble)fVar1);
    *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x70);
    *(float *)(unaff_EBP + -0x6c) = (float)(lVar18 + (longdouble)fVar2);
    *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + -0x6c);
    pfVar8 = *(float **)(unaff_EBP + 0x10);
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (pfVar8,*(undefined4 *)(unaff_EBP + -0xd4),0,
               *(undefined4 *)(**(int **)(unaff_EBP + 8) + 0x208),*(undefined4 *)(unaff_EBP + -0xe8)
              );
    if ((*(int *)(unaff_EBP + 0x24) != 0) &&
       (iVar12 = *(int *)(unaff_EBX + 0x3850), iVar13 = *(int *)(unaff_EBP + 0x24),
       *(int *)(unaff_EBX + 0x3850) = *(int *)(unaff_EBX + 0x3850) + 1, iVar12 % iVar13 == 0)) {
      uVar14 = *(int *)(unaff_EBP + 0x20) - 2;
      if ((*(byte *)(**(int **)(unaff_EBP + 8) + 0x1a4) & 8) == 0) {
        *(undefined4 *)(unaff_EBP + -0x74) = **(undefined4 **)(unaff_EBP + 0x10);
        *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(*(int *)(unaff_EBP + 0x10) + 4);
        *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(*(int *)(unaff_EBP + 0x10) + 8);
      }
      else {
        fVar1 = *(float *)(unaff_EBX + -0x4e328);
        *(undefined4 *)(unaff_EBP + -0xa4) = 0;
        *(undefined4 *)(unaff_EBP + -0xa0) = 0;
        *(float *)(unaff_EBP + -0x9c) = fVar1;
        fVar1 = fVar1 + pfVar8[2];
        fVar2 = *pfVar8;
        fVar3 = pfVar8[1];
        *(float *)(unaff_EBP + -0x98) = fVar2;
        *(float *)(unaff_EBP + -0x94) = fVar3;
        *(float *)(unaff_EBP + -0x90) = fVar1;
        piVar9 = *(int **)(unaff_EBX + 0x136c);
        fVar11 = *(float *)(*piVar9 + 0x40) + *(float *)(*piVar9 + 0x40);
        fVar4 = *(float *)(*piVar9 + 0x44);
        fVar4 = fVar4 + fVar4;
        fVar5 = *(float *)(*piVar9 + 0x48);
        fVar5 = fVar5 + fVar5;
        fVar2 = fVar2 + fVar11;
        fVar3 = fVar3 + fVar4;
        fVar1 = fVar1 + fVar5;
        *(float *)(unaff_EBP + -0xb0) = fVar11;
        *(float *)(unaff_EBP + -0xac) = fVar4;
        *(float *)(unaff_EBP + -0xa8) = fVar5;
        *(float *)(unaff_EBP + -0x8c) = fVar2;
        *(float *)(unaff_EBP + -0x88) = fVar3;
        *(float *)(unaff_EBP + -0x84) = fVar1;
        iVar12 = *piVar9;
        fVar4 = *(float *)(unaff_EBX + -0x4e324);
        fVar11 = *(float *)(iVar12 + 0x28) * fVar4;
        fVar5 = *(float *)(iVar12 + 0x2c) * fVar4;
        fVar4 = fVar4 * *(float *)(iVar12 + 0x30);
        *(float *)(unaff_EBP + -0xbc) = fVar11;
        *(float *)(unaff_EBP + -0xb8) = fVar5;
        *(float *)(unaff_EBP + -0xb4) = fVar4;
        *(float *)(unaff_EBP + -0x68) = fVar2 + fVar11;
        *(float *)(unaff_EBP + -100) = fVar3 + fVar5;
        *(float *)(unaff_EBP + -0x60) = fVar1 + fVar4;
        *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x68);
        *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -100);
        *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x60);
      }
      if (uVar14 < 9) {
                    /* WARNING: Could not recover jumptable at 0x000bf494. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0xdce18 + uVar14 * 4)))();
        return;
      }
      (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xb8))(5,0x17,unaff_EBP + -0x74,0);
      (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xc0))(6);
      (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xd4))(*(undefined4 *)(unaff_EBP + -0x74));
      (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xd4))(*(undefined4 *)(unaff_EBP + -0x70));
      (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xd4))(*(undefined4 *)(unaff_EBP + -0x6c));
      (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xd4))(*(undefined4 *)(unaff_EBP + -0x24));
      (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xd4))(*(undefined4 *)(unaff_EBP + -0x20));
      (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xd4))(*(undefined4 *)(unaff_EBP + -0x1c));
      (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xbc))();
    }
    fVar1 = *(float *)(unaff_EBP + -0x28);
    if ((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40) {
      iVar12 = *(int *)(unaff_EBP + -8);
      if ((iVar12 == 0) &&
         (iVar12 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x114))(0), iVar12 == 0)) {
        iVar12 = 0;
      }
      else {
        iVar12 = *(int *)(iVar12 + 0x7c);
      }
      if (*(int *)(unaff_EBP + 0x28) == 0) {
        if (*(uint *)(unaff_EBP + 0x20) < 0xb) {
                    /* WARNING: Could not recover jumptable at 0x000bf67e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0xdcc30 + *(int *)(unaff_EBP + 0x20) * 4)))()
          ;
          return;
        }
        *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
        *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
        *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
        iVar13 = *(int *)(iVar12 + 0x454);
        uVar23 = 2;
        uVar22 = *(undefined4 *)(unaff_EBP + -0xe8);
        fVar1 = *(float *)(*(int *)(unaff_EBX + 0x158c) + 0xcc);
      }
      else {
        fVar1 = (float)*(int *)(unaff_EBP + 0x28);
        if (*(uint *)(unaff_EBP + 0xc) < 2) {
          *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
          *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
          *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
          *(undefined4 *)(unaff_EBP + -0xe4) = 0x1002;
          if (0x10 < *(int *)(unaff_EBP + 0x28)) {
            *(undefined4 *)(unaff_EBP + -0xe4) = 0x2002;
          }
          FUN_000bf838(fVar1,unaff_EBP + -0x74,*(undefined4 *)(unaff_EBP + -0xe8),
                       *(undefined4 *)(unaff_EBP + -0xe4));
          return;
        }
        *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
        *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
        *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
        iVar13 = *(int *)(iVar12 + 0x454);
        *(undefined4 *)(unaff_EBP + -0xe4) = 0x1002;
        if (0x10 < *(int *)(unaff_EBP + 0x28)) {
          *(undefined4 *)(unaff_EBP + -0xe4) = 0x2002;
        }
        uVar23 = *(undefined4 *)(unaff_EBP + -0xe4);
        uVar22 = *(undefined4 *)(unaff_EBP + -0xe8);
      }
      (**(code **)(iVar13 + 0x34))
                (iVar12,*(undefined4 *)(unaff_EBP + 0x2c),fVar1,unaff_EBP + -0x74,uVar22,uVar23);
    }
  } while( true );
}


// switchD_000bf67e::caseD_9  @ 000bf7c4
void switchD_000bf67e::caseD_9(void)

{
  int unaff_EBX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
  *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
  *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
  FUN_000bf838(*(undefined4 *)(*(int *)(unaff_EBX + 0x158c) + 0x10c));
  return;
}


// switchD_000bf67e::switchdataD_000bf680  @ 000bf680
uint switchD_000bf67e::switchdataD_000bf680(void)

{
  uint uVar1;
  char *in_EAX;
  char in_DL;
  bool in_OF;
  longdouble in_ST0;
  
  if (!in_OF) {
    return CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX + in_DL) | 0xdcc0400;
  }
  *in_EAX = *in_EAX + (char)in_EAX;
  uVar1 = FUN_000bf838((float)in_ST0);
  return uVar1;
}


// switchD_000c04c4::caseD_7  @ 000c05dc
undefined4 switchD_000c04c4::caseD_7(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_EDI;
  
  if ((((*(byte *)(unaff_EDI + 0x4fa) & 2) == 0) || ((*(byte *)(unaff_EDI + 0x628) & 2) == 0)) &&
     (*(int *)(unaff_EBP + -4) == 0)) {
    uVar1 = 0;
  }
  else {
    (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xf4))(2,unaff_EBX + -0x4e176);
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
              (*(int *)(unaff_EDI + 0x684) + *(int *)(**(int **)(unaff_EBX + 0x136c) + 0x98));
    *(undefined4 *)(unaff_EDI + 0x680) = 0;
    uVar1 = 1;
  }
  return uVar1;
}


// switchD_000c355a::caseD_2  @ 000c369c
undefined4 switchD_000c355a::caseD_2(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int unaff_EDI;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(unaff_EDI + 0x4fc);
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_EDI + 0x578) = 3;
    (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xf4))(2,unaff_EBX + -0x4dff0);
    uVar2 = caseD_4();
    return uVar2;
  }
  return *(undefined4 *)(unaff_EDI + 0x578);
}


// switchD_000c355a::caseD_4  @ 000c36ee
undefined4 switchD_000c355a::caseD_4(void)

{
  int unaff_EDI;
  
  return *(undefined4 *)(unaff_EDI + 0x578);
}


// switchD_000c355a::switchdataD_000c355c  @ 000c355c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 switchD_000c355a::switchdataD_000c355c(void)

{
  uint in_EAX;
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  char in_DH;
  char unaff_BL;
  int unaff_EBP;
  int unaff_EDI;
  int iVar6;
  byte bVar5;
  
  uVar1 = in_EAX ^ 0x8d;
  (&stack0x0000000d)[in_ECX * 4] = (&stack0x0000000d)[in_ECX * 4] + in_DH;
  bVar5 = (char)((uVar1 | 0xd8c1400) >> 8) + unaff_BL + (char)_DAT_0d8bc200;
  piVar2 = (int *)CONCAT22((short)((uVar1 | 0xd8c1400) >> 0x10),CONCAT11(bVar5,(char)uVar1));
  *piVar2 = *piVar2 + (int)piVar2;
  if (*piVar2 != 0) {
    *(undefined4 *)(unaff_EDI + 0x578) = 2;
    uVar3 = caseD_4();
    return uVar3;
  }
  if (((bVar5 & 1) == 0) && ((bVar5 & 2) == 0)) {
    if ((uVar1 & 0x20000) == 0) {
      if (((uint)piVar2 & 0x40040) != 0) {
        *(undefined4 *)(unaff_EDI + 0x578) = 3;
        uVar3 = caseD_4();
        return uVar3;
      }
    }
    else {
      puVar4 = (undefined4 *)(**(code **)(*(int *)(unaff_EDI + 0x454) + 0x1d4))();
      if (puVar4 != (undefined4 *)0x0) {
        iVar6 = unaff_EBP + -0xc;
        *(undefined4 *)(unaff_EBP + -0xc) = *puVar4;
        *(undefined4 *)(unaff_EBP + -8) = puVar4[1];
        *(undefined4 *)(unaff_EBP + -4) = puVar4[2];
        MakeIdealYaw__12CBaseMonsterG6Vector();
        if ((*(byte *)(puVar4 + 3) & 0x21) != 0) {
          *(undefined4 *)(unaff_EDI + 0x578) = 3;
          uVar3 = caseD_4(iVar6);
          return uVar3;
        }
      }
    }
    return *(undefined4 *)(unaff_EDI + 0x578);
  }
  iVar6 = unaff_EBP + -0xc;
  *(undefined4 *)(unaff_EBP + -0xc) = *(undefined4 *)(unaff_EDI + 0x644);
  *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(unaff_EDI + 0x648);
  *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(unaff_EDI + 0x64c);
  MakeIdealYaw__12CBaseMonsterG6Vector();
  *(undefined4 *)(unaff_EDI + 0x578) = 3;
  uVar3 = caseD_4(iVar6);
  return uVar3;
}


// switchD_000cd33f::caseD_0  @ 000cd47c
void switchD_000cd33f::caseD_0(void)

{
  int unaff_EBX;
  int *unaff_EDI;
  
  *(int *)(*unaff_EDI + 0x1e8) =
       (unaff_EBX + -0x4ced6) - *(int *)(**(int **)(unaff_EBX + 0x136c) + 0x98);
  if (*(byte *)((int)unaff_EDI + 0x4f9) < 9) {
                    /* WARNING: Could not recover jumptable at 0x000cd4b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX -
              *(int *)(unaff_EBX + -0xcedfc + (uint)*(byte *)((int)unaff_EDI + 0x4f9) * 4)))();
    return;
  }
  *(int *)(*unaff_EDI + 0x1ec) =
       (unaff_EBX + -0x4ced6) - *(int *)(**(int **)(unaff_EBX + 0x136c) + 0x98);
  return;
}


// switchD_000e6d74::caseD_18  @ 000e7474
void switchD_000e6d74::caseD_18(void)

{
  int iVar1;
  int unaff_EDI;
  undefined4 uVar2;
  
  if (*(int *)(unaff_EDI + 0x46c) != 0) {
    uVar2 = 0x40000000;
    iVar1 = HasConditions__12CBaseMonsteri();
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EDI + 0x57c) = 4;
      caseD_4(uVar2);
      return;
    }
  }
  return;
}


// switchD_000e6d74::caseD_4  @ 000e755a
void switchD_000e6d74::caseD_4(void)

{
  return;
}


// switchD_000e759b::caseD_1  @ 000e8124
void switchD_000e759b::caseD_1(void)

{
  int unaff_EBX;
  int unaff_EBP;
  int unaff_EDI;
  
  *(float *)(unaff_EDI + 0x560) =
       *(float *)**(undefined4 **)(unaff_EBX + 0x136c) + *(float *)(*(int *)(unaff_EBP + 0xc) + 4);
  return;
}


// switchD_000f6b7a::caseD_4e  @ 000f6f54
void switchD_000f6b7a::caseD_4e(void)

{
  int unaff_EDI;
  
  __as__7EHANDLEP11CBaseEntity(unaff_EDI + 0x704,0);
  StartTask__12CBaseMonsterP6Task_t();
  return;
}


// switchD_0011f955::caseD_d  @ 0011fee4
undefined4 switchD_0011f955::caseD_d(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int unaff_EBP;
  
  BufferField__5CSavePCciT1
            (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(*(int *)(unaff_EBP + -0x184) + 4),
             *(short *)(*(int *)(unaff_EBP + -0x184) + 0xc) * 2,*(undefined4 *)(unaff_EBP + -0x158))
  ;
  while( true ) {
    do {
      *(int *)(unaff_EBP + -0x154) = *(int *)(unaff_EBP + -0x154) + 1;
      if (*(int *)(unaff_EBP + 0x18) <= *(int *)(unaff_EBP + -0x154)) {
        return 1;
      }
      iVar1 = *(int *)(unaff_EBP + -0x154) * 0x10 + *(int *)(unaff_EBP + 0x14);
      *(int *)(unaff_EBP + -0x184) = iVar1;
      *(undefined4 *)(unaff_EBP + -0x158) = *(undefined4 *)(unaff_EBP + 0x10);
      *(int *)(unaff_EBP + -0x158) = *(int *)(unaff_EBP + -0x158) + *(int *)(iVar1 + 8);
      iVar1 = DataEmpty__5CSavePCci
                        (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x158),
                         (int)*(short *)(iVar1 + 0xc) *
                         *(int *)(**(int **)(unaff_EBP + -0x184) * 4 + -0x2a110 + unaff_EBX));
    } while (iVar1 != 0);
    if (**(uint **)(unaff_EBP + -0x184) < 0x12) break;
    (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0xf4))(4,unaff_EBX + -0x432ff);
  }
                    /* WARNING: Could not recover jumptable at 0x0011f955. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)(unaff_EBX -
                    *(int *)(unaff_EBX + -0x7c958 + **(uint **)(unaff_EBP + -0x184) * 4)))();
  return uVar2;
}


// switchD_0011fc25::caseD_2  @ 0011fce8
void switchD_0011fc25::caseD_2(void)

{
  undefined4 uVar1;
  uint uVar2;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0x1360) + 0x114))
                    (*(undefined4 *)(*(int *)(unaff_EBP + -0x158) + unaff_ESI * 4));
  uVar1 = EntityIndex__18CSaveRestoreBufferP7edict_s(*(undefined4 *)(unaff_EBP + 8),uVar1);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x17c) + unaff_ESI * 4) = uVar1;
  do {
    unaff_ESI = unaff_ESI + 1;
    if (*(short *)(*(int *)(unaff_EBP + -0x184) + 0xc) <= unaff_ESI) {
      FUN_0011ff28();
      return;
    }
    uVar2 = **(int **)(unaff_EBP + -0x184) - 2;
  } while (4 < uVar2);
                    /* WARNING: Could not recover jumptable at 0x0011fc25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0x7c688 + uVar2 * 4)))();
  return;
}


// switchD_00132f87::caseD_2  @ 00133118
void switchD_00132f87::caseD_2(void)

{
  int unaff_EBX;
  uint unaff_ESI;
  
  if (unaff_ESI < 4) {
                    /* WARNING: Could not recover jumptable at 0x0013312a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0x69184 + unaff_ESI * 4)))();
    return;
  }
  return;
}


// switchD_00133292::caseD_1  @ 001332c8
void switchD_00133292::caseD_1(void)

{
  FUN_00133675(0x3f4ccccd,0,100);
  return;
}


// switchD_00133b1f::caseD_43  @ 00133b9c
void switchD_00133b1f::caseD_43(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int *in_EDX;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  undefined2 in_FPUControlWord;
  
  fVar2 = *(float *)(unaff_EBX + -0x4079c);
  if (unaff_ESI != 0) {
    fVar2 = *(float *)(unaff_EBX + -0x407a0);
  }
  if (unaff_ESI == 0) {
    FUN_00133bdc();
    return;
  }
  *(undefined4 *)(*in_EDX + 0x94) = 400;
  iVar3 = **(int **)(unaff_EBX + 0x240c);
  iVar1 = *(int *)(iVar3 + 0x94);
  *(undefined2 *)(unaff_EBP + -0x2c) = in_FPUControlWord;
  *(uint *)(unaff_EBP + -0x34) =
       CONCAT22((short)((uint)*(undefined4 *)(unaff_EBP + -0x2c) >> 0x10),
                CONCAT11(0xc,(char)*(undefined4 *)(unaff_EBP + -0x2c)));
  *(int *)(unaff_EBP + -0x48) = (int)ROUND(*(float *)(unaff_EBP + -0x44) + (float)iVar1);
  *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(unaff_EBP + -0x48);
  if ((*(byte *)(**(int **)(unaff_EBX + 0x240c) + 0xb9) & 0x40) != 0) {
    *(float *)(unaff_EBP + -0x28) = (float)*(double *)(unaff_EBX + -0x40788) * fVar2;
  }
  PM_PlayStepSound();
  return;
}


// switchD_00137416::default  @ 001377d4
void switchD_00137416::default(void)

{
  return;
}


// switchD_001383b2::caseD_0  @ 001386df
void switchD_001383b2::caseD_0(void)

{
  return;
}


// switchD_00138d31::caseD_43  @ 00138d84
undefined4 switchD_00138d31::caseD_43(void)

{
  return 0;
}


