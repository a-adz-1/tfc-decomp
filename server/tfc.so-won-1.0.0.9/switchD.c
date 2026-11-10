// switchD_000aad78::caseD_0  @ 000aae80
void switchD_000aad78::caseD_0(void)

{
  undefined4 uVar1;
  int *unaff_EBX;
  
  uVar1 = (*DAT_001755cc)("common/null.wav");
  *(undefined4 *)(*unaff_EBX + 0x1cc) = uVar1;
  return;
}


// switchD_000c6449::caseD_0  @ 000c6690
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switchD_000c6449::caseD_0(void)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  undefined1 uVar6;
  float fVar7;
  int iVar8;
  int in_ECX;
  undefined4 uVar9;
  int unaff_EBP;
  float *unaff_EDI;
  undefined2 in_FPUControlWord;
  longdouble lVar10;
  longdouble lVar11;
  longdouble lVar12;
  
code_r0x000c6690:
  *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
  *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
  *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
  *(undefined4 *)(unaff_EBP + -0xe8) = *(undefined4 *)(in_ECX + 0x3c8);
  (**(code **)(*(int *)(unaff_EBP + -0xe8) + 0x30))
            (in_ECX,*(undefined4 *)(unaff_EBP + 0x2c),0x42480000,unaff_EBP + -0x74,unaff_EBP + -0x38
             ,0x80);
  *(float *)(unaff_EBP + -0x74) = *unaff_EDI;
  *(float *)(unaff_EBP + -0x70) = unaff_EDI[1];
  *(float *)(unaff_EBP + -0x6c) = unaff_EDI[2];
  *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x80);
  *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x7c);
  *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x78);
  TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i
            (unaff_EBP + -0x38,unaff_EBP + -0x74,unaff_EBP + -0x68,*(undefined4 *)(unaff_EBP + 0x20)
            );
  bVar5 = false;
  if ((*(int *)(unaff_EBP + -8) == 0) ||
     (iVar8 = (*DAT_001755d8)(*(int *)(unaff_EBP + -8)), iVar8 == 0)) {
    bVar5 = true;
  }
  if (!bVar5) {
    iVar8 = *(int *)(unaff_EBP + -8) + 0xdc;
    if (*(int *)(unaff_EBP + -8) == 0) {
      iVar8 = 0;
    }
    if (*(int *)(iVar8 + 0x128) != 0) {
      iVar8 = (*DAT_00175628)(0,2);
      UTIL_DecalTrace__FP11TraceResulti(unaff_EBP + -0x38,iVar8 + 0x19);
    }
  }
LAB_000c675e:
  while( true ) {
    do {
      if (*(int *)(unaff_EBP + -0xd8) == 1) {
        *(float *)(unaff_EBP + -0x74) = *unaff_EDI;
        *(float *)(unaff_EBP + -0x70) = unaff_EDI[1];
        *(float *)(unaff_EBP + -0x6c) = unaff_EDI[2];
        *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x24);
        *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x20);
        *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x1c);
        *(undefined2 *)(unaff_EBP + -0xc0) = in_FPUControlWord;
        *(uint *)(unaff_EBP + -200) =
             CONCAT22((short)((uint)*(undefined4 *)(unaff_EBP + -0xc0) >> 0x10),
                      CONCAT11(0xc,(char)*(undefined4 *)(unaff_EBP + -0xc0)));
        *(int *)(unaff_EBP + -0xe8) =
             (int)ROUND(*(float *)(unaff_EBP + 0x1c) * *(float *)(unaff_EBP + -0x28) * 0.00390625);
        in_FPUControlWord = *(undefined2 *)(unaff_EBP + -0xc0);
        UTIL_BubbleTrail__FG6VectorT0i
                  (unaff_EBP + -0x74,unaff_EBP + -0x68,*(undefined4 *)(unaff_EBP + -0xe8));
      }
      *(int *)(unaff_EBP + -0xd8) = *(int *)(unaff_EBP + -0xd8) + 1;
      if (*(uint *)(unaff_EBP + 0xc) < *(uint *)(unaff_EBP + -0xd8)) {
        ApplyMultiDamage__FP9entvars_tT0
                  (**(undefined4 **)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x2c));
        uVar6 = (undefined1)DAT_00154ce4;
        if (0 < *(int *)(unaff_EBP + -0xd4)) {
          (*DAT_00175578)(5,0x17);
          (*DAT_00175580)(0x7e);
          (*DAT_00175594)(*unaff_EDI);
          (*DAT_00175594)(unaff_EDI[1]);
          (*DAT_00175594)(unaff_EDI[2]);
          *(float *)(unaff_EBP + -0xcc) = **(float **)(unaff_EBP + 0x14) * 10.0;
          (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0xcc));
          *(float *)(unaff_EBP + -0xcc) = *(float *)(*(int *)(unaff_EBP + 0x14) + 4) * 10.0;
          (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0xcc));
          *(float *)(unaff_EBP + -0xcc) = *(float *)(*(int *)(unaff_EBP + 0x14) + 8) * 10.0;
          (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0xcc));
          *(float *)(unaff_EBP + -0xcc) = (float)_FUN_00135eb0 * **(float **)(unaff_EBP + 0x18);
          (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0xcc));
          *(float *)(unaff_EBP + -0xcc) =
               (float)_FUN_00135eb0 * *(float *)(*(int *)(unaff_EBP + 0x18) + 4);
          (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0xcc));
          (*DAT_00175580)(*(undefined4 *)(unaff_EBP + -0xd4));
          (*DAT_00175580)(uVar6);
          (*DAT_0017557c)();
        }
        return;
      }
      do {
        lVar10 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
        *(float *)(unaff_EBP + -0xe0) = (float)lVar10;
        lVar10 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
        *(float *)(unaff_EBP + -0xdc) = (float)(lVar10 + (longdouble)*(float *)(unaff_EBP + -0xe0));
        lVar10 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
        *(float *)(unaff_EBP + -0xe4) = (float)lVar10;
        lVar11 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
        lVar11 = (longdouble)*(float *)(unaff_EBP + -0xe4) + lVar11;
        lVar12 = lVar11 * lVar11 +
                 (longdouble)*(float *)(unaff_EBP + -0xdc) *
                 (longdouble)*(float *)(unaff_EBP + -0xdc);
        lVar10 = (longdouble)1;
      } while ((byte)(lVar10 < lVar12 |
                      (byte)((ushort)((ushort)(NAN(lVar10) || NAN(lVar12)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(lVar10 == lVar12) << 0xe) >> 8)) == 1);
      fVar7 = *(float *)(unaff_EBP + -0xdc) * **(float **)(unaff_EBP + 0x18);
      fVar4 = fVar7 * *(float *)(unaff_EBP + -0x44);
      fVar3 = fVar7 * *(float *)(unaff_EBP + -0x40);
      *(float *)(unaff_EBP + -0x74) = fVar4;
      *(float *)(unaff_EBP + -0x70) = fVar3;
      *(float *)(unaff_EBP + -0x6c) = fVar7 * *(float *)(unaff_EBP + -0x3c);
      pfVar2 = *(float **)(unaff_EBP + 0x14);
      fVar7 = pfVar2[1];
      fVar1 = pfVar2[2];
      *(float *)(unaff_EBP + -0x68) = *pfVar2 + fVar4;
      *(float *)(unaff_EBP + -100) = fVar7 + fVar3;
      *(float *)(unaff_EBP + -0x60) = fVar1 + *(float *)(unaff_EBP + -0x6c);
      lVar11 = lVar11 * (longdouble)*(float *)(*(int *)(unaff_EBP + 0x18) + 4);
      lVar10 = lVar11 * (longdouble)*(float *)(unaff_EBP + -0x50);
      lVar12 = lVar11 * (longdouble)*(float *)(unaff_EBP + -0x4c);
      *(float *)(unaff_EBP + -0x80) = (float)lVar10;
      *(float *)(unaff_EBP + -0x7c) = (float)lVar12;
      *(float *)(unaff_EBP + -0x78) = (float)(lVar11 * (longdouble)*(float *)(unaff_EBP + -0x48));
      *(float *)(unaff_EBP + -0x5c) = (float)((longdouble)*(float *)(unaff_EBP + -0x68) + lVar10);
      *(float *)(unaff_EBP + -0x58) = (float)((longdouble)*(float *)(unaff_EBP + -100) + lVar12);
      *(float *)(unaff_EBP + -0x54) = *(float *)(unaff_EBP + -0x60) + *(float *)(unaff_EBP + -0x78);
      *(float *)(unaff_EBP + -0x68) = *(float *)(unaff_EBP + 0x1c) * *(float *)(unaff_EBP + -0x5c);
      *(float *)(unaff_EBP + -100) = *(float *)(unaff_EBP + 0x1c) * *(float *)(unaff_EBP + -0x58);
      *(float *)(unaff_EBP + -0x60) = *(float *)(unaff_EBP + 0x1c) * *(float *)(unaff_EBP + -0x54);
      fVar7 = unaff_EDI[1];
      fVar1 = unaff_EDI[2];
      *(float *)(unaff_EBP + -0x74) = *unaff_EDI + *(float *)(unaff_EBP + -0x68);
      *(float *)(unaff_EBP + -0x70) = fVar7 + *(float *)(unaff_EBP + -100);
      *(float *)(unaff_EBP + -0x6c) = fVar1 + *(float *)(unaff_EBP + -0x60);
      *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EBP + -0x74);
      *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x70);
      *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + -0x6c);
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
      *(undefined4 *)(unaff_EBP + -0xd0) = 0;
      if ((*(int *)(unaff_EBP + 0x24) != 0) &&
         (iVar8 = tracerCount_789 % *(int *)(unaff_EBP + 0x24),
         tracerCount_789 = tracerCount_789 + 1, iVar8 == 0)) {
        if ((*(byte *)(**(int **)(unaff_EBP + 8) + 0x184) & 8) == 0) {
          *(float *)(unaff_EBP + -0x74) = *unaff_EDI;
          *(float *)(unaff_EBP + -0x70) = unaff_EDI[1];
          fVar7 = unaff_EDI[2];
        }
        else {
          *(undefined4 *)(unaff_EBP + -0xa4) = 0;
          *(undefined4 *)(unaff_EBP + -0xa0) = 0;
          *(undefined4 *)(unaff_EBP + -0x9c) = 0xc0800000;
          fVar7 = unaff_EDI[1];
          fVar1 = unaff_EDI[2];
          *(float *)(unaff_EBP + -0x98) = *unaff_EDI + *(float *)(unaff_EBP + -0xa4);
          *(float *)(unaff_EBP + -0x94) = fVar7 + *(float *)(unaff_EBP + -0xa0);
          *(float *)(unaff_EBP + -0x90) = fVar1 + *(float *)(unaff_EBP + -0x9c);
          iVar8 = gpGlobals;
          fVar7 = *(float *)(gpGlobals + 0x44);
          fVar1 = *(float *)(gpGlobals + 0x48);
          *(float *)(unaff_EBP + -0xb0) =
               *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40);
          *(float *)(unaff_EBP + -0xac) = fVar7 + fVar7;
          *(float *)(unaff_EBP + -0xa8) = fVar1 + fVar1;
          *(float *)(unaff_EBP + -0x8c) =
               *(float *)(unaff_EBP + -0x98) + *(float *)(unaff_EBP + -0xb0);
          *(float *)(unaff_EBP + -0x88) =
               *(float *)(unaff_EBP + -0x94) + *(float *)(unaff_EBP + -0xac);
          *(float *)(unaff_EBP + -0x84) =
               *(float *)(unaff_EBP + -0x90) + *(float *)(unaff_EBP + -0xa8);
          fVar1 = *(float *)(iVar8 + 0x28) * 16.0;
          fVar3 = *(float *)(iVar8 + 0x2c) * 16.0;
          fVar7 = *(float *)(iVar8 + 0x30);
          *(float *)(unaff_EBP + -0xbc) = fVar1;
          *(float *)(unaff_EBP + -0xb8) = fVar3;
          *(float *)(unaff_EBP + -0xb4) = fVar7 * 16.0;
          *(float *)(unaff_EBP + -0x68) = *(float *)(unaff_EBP + -0x8c) + fVar1;
          *(float *)(unaff_EBP + -100) = *(float *)(unaff_EBP + -0x88) + fVar3;
          *(float *)(unaff_EBP + -0x60) =
               *(float *)(unaff_EBP + -0x84) + *(float *)(unaff_EBP + -0xb4);
          *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x68);
          *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -100);
          fVar7 = *(float *)(unaff_EBP + -0x60);
        }
        *(float *)(unaff_EBP + -0x6c) = fVar7;
        if (*(int *)(unaff_EBP + 0x24) != 1) {
          *(undefined4 *)(unaff_EBP + -0xd0) = 1;
        }
        if (*(int *)(unaff_EBP + 0x20) != 6) {
          (*DAT_00175578)(5,0x17,unaff_EBP + -0x74,0);
          (*DAT_00175580)(6);
          (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x74));
          (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x70));
          (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x6c));
          (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x24));
          (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x20));
          (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x1c));
          (*DAT_0017557c)();
        }
      }
      fVar7 = *(float *)(unaff_EBP + -0x28);
    } while ((byte)(1.0 < fVar7 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar7 == 1.0) << 0xe) >> 8)) == 0x40);
    iVar8 = *(int *)(unaff_EBP + -8);
    if ((iVar8 == 0) && (iVar8 = (*DAT_001755d4)(0), iVar8 == 0)) {
      in_ECX = 0;
    }
    else {
      in_ECX = *(int *)(iVar8 + 0xd8);
    }
    if (*(int *)(unaff_EBP + 0x28) == 0) break;
    if (*(uint *)(unaff_EBP + 0xc) < 2) {
      *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
      *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
      *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
      uVar9 = 0x1002;
      if (0x10 < *(int *)(unaff_EBP + 0x28)) {
        uVar9 = 0x2002;
      }
      (**(code **)(*(int *)(in_ECX + 0x3c8) + 0x30))
                (in_ECX,*(undefined4 *)(unaff_EBP + 0x2c),(float)*(int *)(unaff_EBP + 0x28),
                 unaff_EBP + -0x74,unaff_EBP + -0x38,uVar9);
      goto LAB_000c6644;
    }
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
    uVar9 = 0x1002;
    if (0x10 < *(int *)(unaff_EBP + 0x28)) {
      uVar9 = 0x2002;
    }
    (**(code **)(*(int *)(in_ECX + 0x3c8) + 0x30))
              (in_ECX,*(undefined4 *)(unaff_EBP + 0x2c),(float)*(int *)(unaff_EBP + 0x28),
               unaff_EBP + -0x74,unaff_EBP + -0x38,uVar9);
    *(int *)(unaff_EBP + -0xd4) = *(int *)(unaff_EBP + -0xd4) + 1;
  }
  switch(*(undefined4 *)(unaff_EBP + 0x20)) {
  case 0:
    goto code_r0x000c6690;
  default:
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
    *(undefined4 *)(unaff_EBP + -0xe8) = *(undefined4 *)(in_ECX + 0x3c8);
    FUN_000c661e(unaff_EBP + -0x38,2);
    return;
  case 2:
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
    *(undefined4 *)(unaff_EBP + -0xe8) = *(undefined4 *)(in_ECX + 0x3c8);
    FUN_000c661e(unaff_EBP + -0x38,2);
    return;
  case 3:
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
    *(undefined4 *)(unaff_EBP + -0xe8) = *(undefined4 *)(in_ECX + 0x3c8);
    FUN_000c661e(unaff_EBP + -0x38,2);
    return;
  case 4:
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
    (**(code **)(*(int *)(in_ECX + 0x3c8) + 0x30))
              (in_ECX,*(undefined4 *)(unaff_EBP + 0x2c),_DAT_00177a7c,unaff_EBP + -0x74,
               unaff_EBP + -0x38,2);
    if (*(int *)(unaff_EBP + -0xd0) == 0) {
      DecalGunshot__FP11TraceResulti(unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + 0x20));
    }
    goto LAB_000c675e;
  case 8:
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
    *(undefined4 *)(unaff_EBP + -0xe8) = *(undefined4 *)(in_ECX + 0x3c8);
    uVar9 = _DAT_00177aa8;
    break;
  case 9:
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
    *(undefined4 *)(unaff_EBP + -0xe8) = *(undefined4 *)(in_ECX + 0x3c8);
    uVar9 = _DAT_00177aac;
    break;
  case 10:
    goto switchD_000c6449_caseD_a;
  }
  (**(code **)(*(int *)(unaff_EBP + -0xe8) + 0x30))
            (in_ECX,*(undefined4 *)(unaff_EBP + 0x2c),uVar9,unaff_EBP + -0x74,unaff_EBP + -0x38,2);
LAB_000c6644:
  *(float *)(unaff_EBP + -0x74) = *unaff_EDI;
  *(float *)(unaff_EBP + -0x70) = unaff_EDI[1];
  *(float *)(unaff_EBP + -0x6c) = unaff_EDI[2];
  *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x80);
  *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x7c);
  *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x78);
  TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i
            (unaff_EBP + -0x38,(float *)(unaff_EBP + -0x74),unaff_EBP + -0x68,
             *(undefined4 *)(unaff_EBP + 0x20));
  DecalGunshot__FP11TraceResulti(unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + 0x20));
  goto LAB_000c675e;
switchD_000c6449_caseD_a:
  *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
  *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
  *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
  *(undefined4 *)(unaff_EBP + -0xe8) = *(undefined4 *)(in_ECX + 0x3c8);
  (**(code **)(*(int *)(unaff_EBP + -0xe8) + 0x30))
            (in_ECX,*(undefined4 *)(unaff_EBP + 0x2c),_DAT_00177ab0,unaff_EBP + -0x74,
             unaff_EBP + -0x38,2);
  if (*(int *)(unaff_EBP + -0xd0) != 0) goto LAB_000c675e;
  goto LAB_000c6644;
}


// switchD_000c6449::caseD_2  @ 000c6490
void switchD_000c6449::caseD_2(void)

{
  int in_ECX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x5c);
  *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x58);
  *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x54);
  *(undefined4 *)(unaff_EBP + -0xe8) = *(undefined4 *)(in_ECX + 0x3c8);
  FUN_000c661e(unaff_EBP + -0x38,2);
  return;
}


// switchD_000c7368::caseD_a  @ 000c73c0
undefined4 switchD_000c7368::caseD_a(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int unaff_EDI;
  
  if (((*(byte *)(unaff_EBX + 0x46e) & 0x20) == 0) && (unaff_EDI == 0)) {
    uVar1 = 0;
  }
  else {
    (*DAT_001755b4)(2,"AI Trigger Fire Target\n");
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
              (*(int *)(unaff_EBX + 0x5f8) + *(int *)(gpGlobals + 0x98));
    *(undefined4 *)(unaff_EBX + 0x5f4) = 0;
    uVar1 = 1;
  }
  return uVar1;
}


// switchD_000c7368::caseD_b  @ 000c73e0
undefined4 switchD_000c7368::caseD_b(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int unaff_EDI;
  
  if ((((((*(byte *)(unaff_EBX + 0x46e) & 0x20) == 0) || (*(int *)(unaff_EBX + 0x4e8) == 2)) ||
       (*(int *)(unaff_EBX + 0x4e8) == 5)) || (*(int *)(unaff_EBX + 0x4e8) == 6)) &&
     (unaff_EDI == 0)) {
    uVar1 = 0;
  }
  else {
    (*DAT_001755b4)(2,"AI Trigger Fire Target\n");
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
              (*(int *)(unaff_EBX + 0x5f8) + *(int *)(gpGlobals + 0x98));
    *(undefined4 *)(unaff_EBX + 0x5f4) = 0;
    uVar1 = 1;
  }
  return uVar1;
}


// switchD_000c830b::caseD_3  @ 000c8340
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switchD_000c830b::caseD_3(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 uVar3;
  
  *(float *)(unaff_EBP + 0x10) = *(float *)(unaff_EBP + 0x10) * _DAT_00177ad4;
  *(undefined4 *)(unaff_EBP + -0xc) = *(undefined4 *)(unaff_EDI + 0x14);
  *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(unaff_EDI + 0x18);
  *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(unaff_EDI + 0x1c);
  uVar3 = *(undefined4 *)(unaff_EBP + 0x10);
  uVar2 = (**(code **)(*(int *)(unaff_ESI + 0x3c8) + 0x40))();
  SpawnBlood__FG6Vectorif(unaff_EBP + -0xc,uVar2,uVar3);
  puVar1 = *(undefined4 **)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -0xc) = *puVar1;
  *(undefined4 *)(unaff_EBP + -8) = puVar1[1];
  *(undefined4 *)(unaff_EBP + -4) = puVar1[2];
  (**(code **)(*(int *)(unaff_ESI + 0x3c8) + 0x44))();
  AddMultiDamage__FP9entvars_tP11CBaseEntityfi(*(undefined4 *)(unaff_EBP + 0xc));
  return;
}


// switchD_000c830b::caseD_6  @ 000c8360
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void switchD_000c830b::caseD_6(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 uVar3;
  
  *(float *)(unaff_EBP + 0x10) = *(float *)(unaff_EBP + 0x10) * _DAT_00177ad8;
  *(undefined4 *)(unaff_EBP + -0xc) = *(undefined4 *)(unaff_EDI + 0x14);
  *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(unaff_EDI + 0x18);
  *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(unaff_EDI + 0x1c);
  uVar3 = *(undefined4 *)(unaff_EBP + 0x10);
  uVar2 = (**(code **)(*(int *)(unaff_ESI + 0x3c8) + 0x40))();
  SpawnBlood__FG6Vectorif(unaff_EBP + -0xc,uVar2,uVar3);
  puVar1 = *(undefined4 **)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -0xc) = *puVar1;
  *(undefined4 *)(unaff_EBP + -8) = puVar1[1];
  *(undefined4 *)(unaff_EBP + -4) = puVar1[2];
  (**(code **)(*(int *)(unaff_ESI + 0x3c8) + 0x44))();
  AddMultiDamage__FP9entvars_tP11CBaseEntityfi(*(undefined4 *)(unaff_EBP + 0xc));
  return;
}


// switchD_000c8bb4::caseD_4  @ 000c8d4a
undefined4 switchD_000c8bb4::caseD_4(void)

{
  int unaff_ESI;
  
  return *(undefined4 *)(unaff_ESI + 0x4ec);
}


// switchD_000d1028::caseD_0  @ 000d11e0
void switchD_000d1028::caseD_0(void)

{
  char *pcVar1;
  int iVar2;
  int *unaff_EBX;
  
  *(int *)(*unaff_EBX + 0x1c8) = (int)"common/null.wav" - *(int *)(gpGlobals + 0x98);
  switch(*(undefined1 *)((int)unaff_EBX + 0x46d)) {
  default:
    iVar2 = *unaff_EBX;
    pcVar1 = "common/null.wav";
    break;
  case 1:
    (*DAT_001754c4)("plats/bigstop1.wav");
    iVar2 = *unaff_EBX;
    pcVar1 = "plats/bigstop1.wav";
    break;
  case 2:
    (*DAT_001754c4)("plats/bigstop2.wav");
    iVar2 = *unaff_EBX;
    pcVar1 = "plats/bigstop2.wav";
    break;
  case 3:
    (*DAT_001754c4)("plats/freightstop1.wav");
    iVar2 = *unaff_EBX;
    pcVar1 = "plats/freightstop1.wav";
    break;
  case 4:
    (*DAT_001754c4)("plats/heavystop2.wav");
    iVar2 = *unaff_EBX;
    pcVar1 = "plats/heavystop2.wav";
    break;
  case 5:
    (*DAT_001754c4)("plats/rackstop1.wav");
    iVar2 = *unaff_EBX;
    pcVar1 = "plats/rackstop1.wav";
    break;
  case 6:
    (*DAT_001754c4)("plats/railstop1.wav");
    iVar2 = *unaff_EBX;
    pcVar1 = "plats/railstop1.wav";
    break;
  case 7:
    (*DAT_001754c4)("plats/squeekstop1.wav");
    iVar2 = *unaff_EBX;
    pcVar1 = "plats/squeekstop1.wav";
    break;
  case 8:
    (*DAT_001754c4)("plats/talkstop1.wav");
    iVar2 = *unaff_EBX;
    pcVar1 = "plats/talkstop1.wav";
  }
  *(int *)(iVar2 + 0x1cc) = (int)pcVar1 - *(int *)(gpGlobals + 0x98);
  return;
}


// switchD_000d1028::caseD_1  @ 000d1030
void switchD_000d1028::caseD_1(void)

{
  (*DAT_001754c4)("plats/bigmove1.wav");
  FUN_000d11c9();
  return;
}


// switchD_000d1028::caseD_3  @ 000d1070
void switchD_000d1028::caseD_3(void)

{
  (*DAT_001754c4)("plats/elevmove1.wav");
  FUN_000d11c9();
  return;
}


// switchD_000d120a::caseD_0  @ 000d1320
void switchD_000d120a::caseD_0(void)

{
  int *unaff_EBX;
  
  *(int *)(*unaff_EBX + 0x1cc) = (int)"common/null.wav" - *(int *)(gpGlobals + 0x98);
  return;
}


// switchD_000d120a::caseD_2  @ 000d1240
void switchD_000d120a::caseD_2(void)

{
  int *unaff_EBX;
  
  (*DAT_001754c4)("plats/bigstop2.wav");
  *(int *)(*unaff_EBX + 0x1cc) = (int)"plats/bigstop2.wav" - *(int *)(gpGlobals + 0x98);
  return;
}


// switchD_000d43c1::caseD_1  @ 000d43f0
void switchD_000d43c1::caseD_1(void)

{
  int *unaff_EBX;
  
  (*DAT_001754c4)("plats/ttrain1.wav");
  *(char **)(*unaff_EBX + 0x1c8) = "?plats/ttrain1.wav" + (1 - *(int *)(gpGlobals + 0x98));
  (*DAT_001754c4)("plats/ttrain_brake1.wav");
  (*DAT_001754c4)("plats/ttrain_start1.wav");
  return;
}


// switchD_000d43c1::default  @ 000d43d0
void switchD_000d43c1::default(void)

{
  int *unaff_EBX;
  
  *(undefined4 *)(*unaff_EBX + 0x1c8) = 0;
  (*DAT_001754c4)("plats/ttrain_brake1.wav");
  (*DAT_001754c4)("plats/ttrain_start1.wav");
  return;
}


// switchD_000d7fcd::caseD_0  @ 000d8150
void switchD_000d7fcd::caseD_0(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (((*(byte *)(*unaff_ESI + 0x185) & 2) == 0) && (unaff_ESI[0x137] - 7U < 2)) {
    unaff_ESI[0x138] = unaff_ESI[0x137];
  }
  else if (*(int *)(*unaff_ESI + 0x1a0) < 2) {
    unaff_ESI[0x138] = 3;
  }
  else if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(unaff_EBP + -0x48)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(unaff_EBP + -0x48) == 0.0) << 0xe) >> 8)) ==
           0x40) {
    unaff_ESI[0x138] = 0x32;
  }
  else {
    unaff_ESI[0x138] = 6;
  }
  switch(unaff_ESI[0x138]) {
  case 3:
    if ((unaff_ESI[0x137] == 0x1c) && (unaff_ESI[0xf8] == 0)) {
      iVar3 = *(int *)(*unaff_ESI + 0x108);
    }
    else {
      if ((unaff_ESI[0xb] == 2) && ((*(byte *)((int)unaff_ESI + 0x89) & 8) != 0)) {
        iVar2 = 5;
        if ((*(byte *)(*unaff_ESI + 0x185) & 0x40) != 0) {
          iVar2 = 6;
        }
      }
      else {
        iVar2 = 1;
        if ((*(byte *)(*unaff_ESI + 0x185) & 0x40) != 0) {
          iVar2 = 2;
        }
      }
      if ((iVar2 == unaff_ESI[0x32d]) && (unaff_ESI[0x32e] != 0)) {
        iVar3 = unaff_ESI[0x32e];
      }
      else {
        sprintf((char *)(unaff_EBP + -0x40),*(char **)(g_PlayerAnimationNames + iVar2 * 4),
                unaff_ESI + 0x325);
        iVar3 = LookupSequence__14CBaseAnimatingPCc();
        unaff_ESI[0x32e] = iVar3;
        unaff_ESI[0x32d] = iVar2;
      }
      if (iVar3 == -1) {
        iVar3 = 0;
      }
      unaff_ESI[0x137] = 3;
    }
    break;
  default:
    if (unaff_ESI[0x137] == unaff_ESI[0x138]) {
      return;
    }
    unaff_ESI[0x137] = unaff_ESI[0x138];
    iVar2 = LookupActivity__14CBaseAnimatingi();
    if (*(int *)(*unaff_ESI + 0x108) == iVar2) {
      return;
    }
    *(undefined4 *)(*unaff_ESI + 0x10c) = 0;
    *(int *)(*unaff_ESI + 0x108) = iVar2;
    goto LAB_000d8458;
  case 0x1c:
    iVar2 = 3;
    if ((*(byte *)(*unaff_ESI + 0x185) & 0x40) != 0) {
      iVar2 = 4;
    }
    if ((iVar2 == unaff_ESI[0x32d]) && (unaff_ESI[0x32e] != 0)) {
      iVar3 = unaff_ESI[0x32e];
    }
    else {
      sprintf((char *)(unaff_EBP + -0x40),*(char **)(g_PlayerAnimationNames + iVar2 * 4),
              unaff_ESI + 0x325);
      iVar3 = LookupSequence__14CBaseAnimatingPCc();
      unaff_ESI[0x32d] = iVar2;
      unaff_ESI[0x32e] = iVar3;
    }
    if (iVar3 == -1) {
      iVar3 = 0;
    }
    if (((*(int *)(*unaff_ESI + 0x108) != iVar3) || (unaff_ESI[0xf9] == 0)) &&
       (*(undefined4 *)(*unaff_ESI + 0x110) = 0, unaff_ESI[0xf9] == 0)) {
      *(byte *)(*unaff_ESI + 0xf8) = *(byte *)(*unaff_ESI + 0xf8) | 0x20;
    }
    unaff_ESI[0x137] = unaff_ESI[0x138];
    *(int *)(*unaff_ESI + 0x108) = iVar3;
    ResetSequenceInfo__14CBaseAnimating();
  }
  if ((((*(byte *)(*unaff_ESI + 0x185) & 0x40) == 0) &&
      (fVar1 = *(float *)(unaff_EBP + -0x48),
      (byte)(220.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 220.0) << 0xe) >> 8)) != 1)) &&
     (fVar1 = *(float *)(unaff_EBP + -0x48),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
    uVar4 = LookupSequence__14CBaseAnimatingPCc();
  }
  else {
    uVar4 = LookupActivity__14CBaseAnimatingi();
  }
  *(undefined4 *)(*unaff_ESI + 0x10c) = uVar4;
  if (*(int *)(*unaff_ESI + 0x108) != iVar3) {
    *(int *)(*unaff_ESI + 0x108) = iVar3;
LAB_000d8458:
    *(undefined4 *)(*unaff_ESI + 0x110) = 0;
    ResetSequenceInfo__14CBaseAnimating();
  }
  return;
}


// switchD_000d81d8::caseD_3  @ 000d82f0
void switchD_000d81d8::caseD_3(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *unaff_ESI;
  int iVar4;
  
  if ((unaff_ESI[0x137] == 0x1c) && (unaff_ESI[0xf8] == 0)) {
    iVar2 = *(int *)(*unaff_ESI + 0x108);
  }
  else {
    if ((unaff_ESI[0xb] == 2) && ((*(byte *)((int)unaff_ESI + 0x89) & 8) != 0)) {
      iVar4 = 5;
      if ((*(byte *)(*unaff_ESI + 0x185) & 0x40) != 0) {
        iVar4 = 6;
      }
    }
    else {
      iVar4 = 1;
      if ((*(byte *)(*unaff_ESI + 0x185) & 0x40) != 0) {
        iVar4 = 2;
      }
    }
    if ((iVar4 == unaff_ESI[0x32d]) && (unaff_ESI[0x32e] != 0)) {
      iVar2 = unaff_ESI[0x32e];
    }
    else {
      sprintf((char *)(unaff_EBP + -0x40),*(char **)(g_PlayerAnimationNames + iVar4 * 4),
              unaff_ESI + 0x325);
      iVar2 = LookupSequence__14CBaseAnimatingPCc();
      unaff_ESI[0x32e] = iVar2;
      unaff_ESI[0x32d] = iVar4;
    }
    if (iVar2 == -1) {
      iVar2 = 0;
    }
    unaff_ESI[0x137] = 3;
  }
  if ((((*(byte *)(*unaff_ESI + 0x185) & 0x40) == 0) &&
      (fVar1 = *(float *)(unaff_EBP + -0x48),
      (byte)(220.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 220.0) << 0xe) >> 8)) != 1)) &&
     (fVar1 = *(float *)(unaff_EBP + -0x48),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
    uVar3 = LookupSequence__14CBaseAnimatingPCc();
  }
  else {
    uVar3 = LookupActivity__14CBaseAnimatingi();
  }
  *(undefined4 *)(*unaff_ESI + 0x10c) = uVar3;
  if (*(int *)(*unaff_ESI + 0x108) != iVar2) {
    *(int *)(*unaff_ESI + 0x108) = iVar2;
    *(undefined4 *)(*unaff_ESI + 0x110) = 0;
    ResetSequenceInfo__14CBaseAnimating();
  }
  return;
}


// switchD_000daa06::caseD_43  @ 000daab0
void switchD_000daa06::caseD_43(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int unaff_EBP;
  int unaff_EDI;
  
  fVar2 = 0.5;
  if ((unaff_EDI == 0) || (fVar2 = 0.2, unaff_EDI == 0)) {
    fVar3 = 0.3;
  }
  else {
    fVar2 = 0.2;
    fVar3 = 0.4;
  }
  *(float *)(unaff_EBP + -0xb4) = fVar3 + *gpGlobals;
  *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x670) = *(undefined4 *)(unaff_EBP + -0xb4);
  piVar1 = *(int **)(unaff_EBP + 8);
  piVar1[0x19c] = (int)(*(float *)(unaff_EBP + -0xc0) + (float)piVar1[0x19c]);
  if ((*(byte *)(*piVar1 + 0x185) & 0x40) != 0) {
    *(float *)(unaff_EBP + -0xb4) = fVar2 * 0.35;
  }
  PlayStepSound__11CBasePlayerif(*(undefined4 *)(unaff_EBP + 8));
  return;
}


// switchD_000daa06::caseD_4d  @ 000daa50
void switchD_000daa06::caseD_4d(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int unaff_EBP;
  int unaff_EDI;
  
  fVar2 = 0.5;
  if ((unaff_EDI == 0) || (fVar2 = 0.2, unaff_EDI == 0)) {
    fVar3 = 0.3;
  }
  else {
    fVar2 = 0.2;
    fVar3 = 0.4;
  }
  *(float *)(unaff_EBP + -0xb4) = fVar3 + *gpGlobals;
  *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x670) = *(undefined4 *)(unaff_EBP + -0xb4);
  piVar1 = *(int **)(unaff_EBP + 8);
  piVar1[0x19c] = (int)(*(float *)(unaff_EBP + -0xc0) + (float)piVar1[0x19c]);
  if ((*(byte *)(*piVar1 + 0x185) & 0x40) != 0) {
    *(float *)(unaff_EBP + -0xb4) = fVar2 * 0.35;
  }
  PlayStepSound__11CBasePlayerif(*(undefined4 *)(unaff_EBP + 8));
  return;
}


// switchD_000e3184::caseD_1  @ 000e3190
void switchD_000e3184::caseD_1(void)

{
  TeamFortress_DisplayDetectionItems__11CBasePlayer();
  default();
  return;
}


// switchD_000e3184::default  @ 000e32c6
void switchD_000e3184::default(void)

{
  return;
}


// switchD_000e3b89::caseD_3  @ 000e3bb0
void switchD_000e3b89::caseD_3(void)

{
  int *unaff_EBX;
  int *unaff_ESI;
  
  Prime__14CTFNailGrenadeP11CBaseEntity();
  *unaff_ESI = *unaff_ESI + -1;
  *(byte *)(unaff_EBX + 0x22) = *(byte *)(unaff_EBX + 0x22) | 1;
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*unaff_EBX + 0x1e8),1,"weapons/ax1.wav",0x3f666666,0x3f4ccccd,0,100);
  return;
}


// switchD_000e4f8a::caseD_18  @ 000e5580
void switchD_000e4f8a::caseD_18(void)

{
  int iVar1;
  int unaff_ESI;
  undefined4 uVar2;
  
  if (*(int *)(unaff_ESI + 0x3e0) != 0) {
    uVar2 = 0x40000000;
    iVar1 = HasConditions__12CBaseMonsteri();
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_ESI + 0x4f0) = 4;
      caseD_4(uVar2);
      return;
    }
  }
  return;
}


// switchD_000e4f8a::caseD_4  @ 000e5656
void switchD_000e4f8a::caseD_4(void)

{
  return;
}


// switchD_000e4f8a::caseD_4c  @ 000e53e0
void switchD_000e4f8a::caseD_4c(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI[0xf8] != 0) {
    fVar1 = *(float *)(*unaff_ESI + 0x110);
    if ((byte)((255.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 255.0) << 0xe) >> 8)) - 1) < 0x40) {
      *(undefined4 *)(*unaff_ESI + 0x150) = 2;
      unaff_ESI[3] = 0;
      unaff_ESI[4] = 0;
      *(undefined4 *)(*unaff_ESI + 0x118) = 0;
      iVar4 = BBoxFlat__12CBaseMonster();
      if (iVar4 == 0) {
        *(undefined4 *)(unaff_EBP + -0x28) = 0x40800000;
        *(undefined4 *)(unaff_EBP + -0x24) = 0x40800000;
        *(undefined4 *)(unaff_EBP + -0x20) = 0x3f800000;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0xc0800000;
        *(undefined4 *)(unaff_EBP + -0x18) = 0xc0800000;
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        iVar4 = *unaff_ESI;
      }
      else {
        iVar4 = *unaff_ESI;
        fVar1 = *(float *)(iVar4 + 0xc4);
        uVar2 = *(undefined4 *)(iVar4 + 0xcc);
        *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar4 + 200);
        *(undefined4 *)(unaff_EBP + -0x24) = uVar2;
        *(float *)(unaff_EBP + -0x20) = fVar1 + 1.0;
        uVar2 = *(undefined4 *)(iVar4 + 0xc0);
        uVar3 = *(undefined4 *)(iVar4 + 0xc4);
        *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar4 + 0xbc);
        *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
        *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
      }
      UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar4,unaff_EBP + -0x1c,unaff_EBP + -0x28);
      iVar4 = (**(code **)(unaff_ESI[0xf2] + 0x10c))();
      if (iVar4 != 0) {
        SUB_StartFadeOut__11CBaseEntity();
        caseD_4();
        return;
      }
      InsertSound__9CSoundEntiRC6Vectorif(8,*unaff_ESI + 8,0x180,0x41f00000);
      caseD_4();
      return;
    }
  }
  return;
}


// switchD_000e570b::caseD_1  @ 000e5e40
void switchD_000e570b::caseD_1(void)

{
  int unaff_EBP;
  int unaff_EDI;
  
  *(float *)(unaff_EDI + 0x4d4) = *gpGlobals + *(float *)(*(int *)(unaff_EBP + 0xc) + 4);
  return;
}


// switchD_000e570b::caseD_1a  @ 000e5860
void switchD_000e570b::caseD_1a(void)

{
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 0x5ac) = 0xffffffff;
  FUN_000e69ca();
  return;
}


// switchD_000e570b::caseD_1f  @ 000e5d30
void switchD_000e570b::caseD_1f(void)

{
  int *unaff_EDI;
  
  *(undefined4 *)(*unaff_EDI + 0x8c) =
       *(undefined4 *)(DAT_001758cc + 0x54 + unaff_EDI[0x16b] * 0x58);
  SetTurnActivity__12CBaseMonster();
  return;
}


// switchD_000e570b::caseD_21  @ 000e5d60
void switchD_000e570b::caseD_21(void)

{
  int unaff_EBP;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EDI + 0x5a0);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EDI + 0x5a4);
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EDI + 0x5a8);
  MakeIdealYaw__12CBaseMonsterG6Vector();
  SetTurnActivity__12CBaseMonster();
  return;
}


// switchD_000e570b::caseD_45  @ 000e5b70
void switchD_000e570b::caseD_45(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int unaff_EBP;
  int *unaff_EDI;
  
  iVar1 = __opP11CBaseEntity__7EHANDLE(unaff_EDI + 0x11c);
  if (iVar1 == 0) {
    iVar1 = *unaff_EDI;
  }
  else {
    piVar2 = (int *)__rf__7EHANDLE(unaff_EDI + 0x11c);
    iVar1 = *piVar2;
  }
  iVar3 = FindLateralCover__12CBaseMonsterRC6VectorT1();
  if (iVar3 == 0) {
    *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar1 + 0x154);
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar1 + 0x158);
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar1 + 0x15c);
    iVar1 = unaff_EDI[0xf2];
    (**(code **)(iVar1 + 0x1b0))();
    iVar1 = (**(code **)(iVar1 + 0x1a8))();
    if (iVar1 != 0) {
      unaff_EDI[0x136] = (int)(*gpGlobals + *(float *)(*(int *)(unaff_EBP + 0xc) + 4));
      FUN_000e699d();
      return;
    }
    SetConditions__12CBaseMonsteri();
    return;
  }
  unaff_EDI[0x136] = (int)(*gpGlobals + *(float *)(*(int *)(unaff_EBP + 0xc) + 4));
  FUN_000e699d();
  return;
}


// switchD_000e570b::caseD_4a  @ 000e5c10
void switchD_000e570b::caseD_4a(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_EDI;
  
  iVar1 = *unaff_EDI;
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar1 + 0x154);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar1 + 0x158);
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar1 + 0x15c);
  iVar1 = unaff_EDI[0xf2];
  (**(code **)(iVar1 + 0x1b0))();
  iVar1 = (**(code **)(iVar1 + 0x1a8))();
  if (iVar1 != 0) {
    unaff_EDI[0x136] = (int)(*gpGlobals + *(float *)(*(int *)(unaff_EBP + 0xc) + 4));
    FUN_000e699d();
    return;
  }
  SetConditions__12CBaseMonsteri();
  return;
}


// switchD_000e570b::caseD_5  @ 000e5f40
void switchD_000e570b::caseD_5(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int unaff_EBP;
  int *unaff_EDI;
  
  piVar4 = (int *)__rf__7EHANDLE(unaff_EDI + 0x11e);
  iVar5 = *piVar4;
  fVar1 = *(float *)(iVar5 + 8) - *(float *)(*unaff_EDI + 8);
  fVar3 = *(float *)(iVar5 + 0xc) - *(float *)(*unaff_EDI + 0xc);
  fVar2 = *(float *)(iVar5 + 0x10) - *(float *)(*unaff_EDI + 0x10);
  *(float *)(unaff_EBP + -0x24) = fVar1;
  *(float *)(unaff_EBP + -0x20) = fVar3;
  *(float *)(unaff_EBP + -0x1c) = fVar2;
  *(float *)(unaff_EBP + -0x18) = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
  if ((*(float *)(unaff_EBP + -0x18) < 1.0) ||
     (iVar5 = LookupActivity__14CBaseAnimatingi(), iVar5 == -1)) {
    iVar5 = HasConditions__12CBaseMonsteri();
    if (iVar5 == 0) {
      unaff_EDI[0x13c] = 4;
      FUN_000e69ca();
      return;
    }
  }
  else {
    iVar5 = __opP11CBaseEntity__7EHANDLE(unaff_EDI + 0x11e);
    if ((iVar5 == 0) || (iVar5 = MoveToTarget__12CBaseMonster8Activityf(), iVar5 == 0)) {
      SetConditions__12CBaseMonsteri();
      (*DAT_001755b4)(2,"%s Failed to reach target!!!\n",
                      *(int *)*unaff_EDI + *(int *)(gpGlobals + 0x98));
      RouteClear__12CBaseMonster();
      FUN_000e69ca();
      return;
    }
  }
  iVar5 = HasConditions__12CBaseMonsteri();
  if (iVar5 == 0) {
    unaff_EDI[0x13c] = 4;
  }
  return;
}


// switchD_000e570b::caseD_52  @ 000e5e60
void switchD_000e570b::caseD_52(void)

{
  int unaff_EBP;
  int unaff_EDI;
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_0017562c)(0x3dcccccd,*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 4));
  *(float *)(unaff_EDI + 0x4d4) = (float)(lVar1 + (longdouble)*gpGlobals);
  return;
}


// switchD_000e570b::caseD_9  @ 000e6120
void switchD_000e570b::caseD_9(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int unaff_EBP;
  int *unaff_EDI;
  
  iVar5 = BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity();
  if (iVar5 == 0) {
    *(int *)(unaff_EBP + -0x24) = unaff_EDI[0x16e];
    *(int *)(unaff_EBP + -0x20) = unaff_EDI[0x16f];
    *(int *)(unaff_EBP + -0x1c) = unaff_EDI[0x170];
    iVar5 = *unaff_EDI;
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar5 + 0x154);
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar5 + 0x158);
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar5 + 0x15c);
    iVar1 = unaff_EDI[0xf2];
    fVar2 = (float)unaff_EDI[0x16e] - *(float *)(iVar5 + 8);
    fVar4 = (float)unaff_EDI[0x16f] - *(float *)(iVar5 + 0xc);
    fVar3 = (float)unaff_EDI[0x170] - *(float *)(iVar5 + 0x10);
    *(float *)(unaff_EBP + -0x30) = fVar2;
    *(float *)(unaff_EBP + -0x2c) = fVar4;
    *(float *)(unaff_EBP + -0x28) = fVar3;
    *(float *)(unaff_EBP + -0x34) = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2);
    iVar5 = (**(code **)(iVar1 + 0x1a4))();
    if (iVar5 == 0) {
      FUN_000e650b();
      return;
    }
  }
  iVar5 = HasConditions__12CBaseMonsteri();
  if (iVar5 == 0) {
    unaff_EDI[0x13c] = 4;
  }
  return;
}


// switchD_000ed60e::caseD_44  @ 000ed680
longdouble switchD_000ed60e::caseD_44(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  longdouble lVar4;
  char *pcVar5;
  
  *(undefined4 *)(unaff_EBP + -0x74) = 0x3f666666;
  *(undefined4 *)(unaff_EBP + -0x78) = 0x3dcccccd;
  *(char **)(unaff_EBP + -0x68) = "player/pl_dirt1.wav";
  *(char **)(unaff_EBP + -100) = "player/pl_dirt2.wav";
  *(char **)(unaff_EBP + -0x60) = "player/pl_dirt3.wav";
  if ((unaff_ESI == (undefined4 *)0x0) ||
     (iVar2 = strcmp((char *)(*(int *)*unaff_ESI + *(int *)(gpGlobals + 0x98)),"func_breakable"),
     iVar2 != 0)) {
    if (((*(char *)(unaff_EBP + -0x6d) == 'P') &&
        (fVar1 = *(float *)(*(int *)(unaff_EBP + 8) + 0x10),
        (byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) != 0x40)) &&
       (iVar2 = (*DAT_00175628)(0,1), iVar2 != 0)) {
      UTIL_Sparks__FRC6Vector(*(int *)(unaff_EBP + 8) + 0x14);
      lVar4 = (longdouble)(*DAT_0017562c)(0x3f333333,0x3f800000);
      *(float *)(unaff_EBP + -0x80) = (float)lVar4;
      iVar2 = (*DAT_00175628)(0,1);
      if (iVar2 == 0) {
        uVar3 = *(undefined4 *)(unaff_EBP + -0x80);
        pcVar5 = "buttons/spark5.wav";
      }
      else {
        if (iVar2 != 1) goto LAB_000ed93d;
        uVar3 = *(undefined4 *)(unaff_EBP + -0x80);
        pcVar5 = "buttons/spark6.wav";
      }
      uVar3 = (*DAT_001755d4)(0,*(int *)(unaff_EBP + 8) + 0x14,pcVar5,uVar3,0x3f4ccccd,0,100);
      UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii(uVar3);
    }
  }
  else {
    *(float *)(unaff_EBP + -0x74) = *(float *)(unaff_EBP + -0x74) / 1.5;
    *(float *)(unaff_EBP + -0x78) = *(float *)(unaff_EBP + -0x78) * 0.5;
  }
LAB_000ed93d:
  iVar2 = (*DAT_00175628)(0,0xf);
  iVar2 = (*DAT_00175628)(0,2,*(undefined4 *)(unaff_EBP + -0x74),*(undefined4 *)(unaff_EBP + -0x7c),
                          0,iVar2 + 0x60);
  uVar3 = (*DAT_001755d4)(0,*(int *)(unaff_EBP + 8) + 0x14,
                          *(undefined4 *)(unaff_EBP + -0x68 + iVar2 * 4));
  UTIL_EmitAmbientSound__FP7edict_sRC6VectorPCcffii(uVar3);
  return (longdouble)*(float *)(unaff_EBP + -0x78);
}


// switchD_000edbfd::caseD_b  @ 000edcb0
/* WARNING: Removing unreachable block (ram,0x000edcea) */

void switchD_000edbfd::caseD_b(void)

{
  float *pfVar1;
  int iVar2;
  int *unaff_ESI;
  longdouble in_ST0;
  longdouble lVar3;
  longdouble in_ST1;
  
  iVar2 = SENTENCEG_PlayRndSz__FP7edict_sPCcffii
                    (*(undefined4 *)(*unaff_ESI + 0x1e8),"C3A1_",(float)in_ST1,(float)in_ST0);
  if (iVar2 < 0) {
    (*DAT_001755b4)(1,"Level Design Error!\nSPEAKER has bad sentence group name: %s\n","C3A1_");
  }
  lVar3 = (longdouble)(*DAT_0017562c)(0x41700000,0x43070000);
  pfVar1 = gpGlobals;
  *(float *)(*unaff_ESI + 0xe4) = (float)(lVar3 + (longdouble)*gpGlobals);
  _12CTalkMonster_g_talkWaitTime = *pfVar1 + 5.0;
  return;
}


// switchD_000f131d::caseD_4e  @ 000f16d0
void switchD_000f131d::caseD_4e(void)

{
  int unaff_ESI;
  
  __as__7EHANDLEP11CBaseEntity(unaff_ESI + 0x678,0);
  StartTask__12CBaseMonsterP6Task_t();
  return;
}


// switchD_000f170d::caseD_59  @ 000f1a00
void switchD_000f170d::caseD_59(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = IsTalking__12CTalkMonster();
  if (iVar1 != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(unaff_ESI + 0x678);
    if (iVar1 != 0) {
      __rf__7EHANDLE(unaff_ESI + 0x678);
      IdleHeadTurn__12CTalkMonsterR6Vector();
      goto LAB_000f1a78;
    }
  }
  IdleHeadTurn__12CTalkMonsterR6Vector();
  FIdleHello__12CTalkMonster();
  iVar1 = (*DAT_00175628)(0,*(int *)(unaff_ESI + 0x614) * 0x14);
  if (iVar1 == 0) {
    FIdleSpeak__12CTalkMonster();
  }
LAB_000f1a78:
  RunTask__12CBaseMonsterP6Task_t();
  if (*(int *)(unaff_ESI + 0x4f0) == 4) {
    IdleHeadTurn__12CTalkMonsterR6Vector();
  }
  return;
}


// switchD_00104c84::caseD_3  @ 00104e60
void switchD_00104c84::caseD_3(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *unaff_EBX;
  int unaff_EBP;
  short unaff_DI;
  short sVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  
  UTIL_MakeVectors__FRC6Vector(*unaff_EBX + 0x50);
  iVar3 = *unaff_EBX;
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar3 + 8);
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar3 + 0xc);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar3 + 0x10);
  lVar5 = (longdouble)(*DAT_0017562c)(0,0x43000000);
  *(float *)(unaff_EBP + -0x20) = (float)(lVar5 + (longdouble)*(float *)(unaff_EBP + -0x20));
  lVar5 = (longdouble)(*DAT_0017562c)(0xc3000000,0x43000000);
  lVar6 = lVar5 * (longdouble)*(float *)(gpGlobals + 0x40);
  lVar7 = lVar5 * (longdouble)*(float *)(gpGlobals + 0x44);
  fVar1 = *(float *)(gpGlobals + 0x48);
  *(float *)(unaff_EBP + -0x34) = (float)lVar6;
  *(float *)(unaff_EBP + -0x30) = (float)lVar7;
  *(float *)(unaff_EBP + -0x2c) = (float)(lVar5 * (longdouble)fVar1);
  *(float *)(unaff_EBP + -0x10) = (float)((longdouble)*(float *)(unaff_EBP + -0x28) + lVar6);
  *(float *)(unaff_EBP + -0xc) = (float)((longdouble)*(float *)(unaff_EBP + -0x24) + lVar7);
  *(float *)(unaff_EBP + -8) = *(float *)(unaff_EBP + -0x20) + *(float *)(unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -8);
  iVar3 = *unaff_EBX;
  *(float *)(unaff_EBP + -0x44) =
       SQRT(*(float *)(iVar3 + 0x28) * *(float *)(iVar3 + 0x28) +
            *(float *)(iVar3 + 0x24) * *(float *)(iVar3 + 0x24) +
            *(float *)(iVar3 + 0x20) * *(float *)(iVar3 + 0x20));
  iVar3 = (*DAT_00175628)(0,3);
  sVar4 = g_sModelIndexGrenade;
  if (iVar3 != 1) {
    if (iVar3 < 2) {
      sVar4 = g_sModelIndexMirvGrenade;
      if (iVar3 != 0) {
        sVar4 = unaff_DI;
      }
    }
    else {
      sVar4 = g_sModelIndexNapalmGrenade;
      if ((iVar3 != 2) && (sVar4 = g_sModelIndexNailGrenade, iVar3 != 3)) {
        sVar4 = unaff_DI;
      }
    }
  }
  iVar3 = UTIL_PointContents__FRC6Vector(unaff_EBP + -0x28);
  if (iVar3 != -2) {
    iVar3 = *unaff_EBX;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar3 + 0x74);
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar3 + 0x78);
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar3 + 0x7c);
    lVar5 = (longdouble)(*DAT_0017562c)(0xc2480000,0x42480000);
    lVar5 = (longdouble)
            UTIL_AngleMod__Ff((float)(lVar5 + (longdouble)*(float *)(unaff_EBP + -0x18)));
    *(float *)(unaff_EBP + -0x18) = (float)lVar5;
    UTIL_MakeVectors__FRC6Vector(unaff_EBP + -0x1c);
    lVar5 = (longdouble)(*DAT_0017562c)(0x43480000,0x43c80000);
    lVar5 = lVar5 + (longdouble)*(float *)(unaff_EBP + -0x44);
    fVar1 = *(float *)(gpGlobals + 0x2c);
    fVar2 = *(float *)(gpGlobals + 0x30);
    *(float *)(unaff_EBP + -0x34) = (float)(lVar5 * (longdouble)*(float *)(gpGlobals + 0x28));
    *(float *)(unaff_EBP + -0x30) = (float)(lVar5 * (longdouble)fVar1);
    *(float *)(unaff_EBP + -0x2c) = (float)(lVar5 * (longdouble)fVar2);
    EjectBrass__FRC6VectorT0fii(unaff_EBP + -0x28,unaff_EBP + -0x34,0,(int)sVar4,0);
  }
  return;
}


// switchD_00104c84::caseD_5  @ 00105090
void switchD_00104c84::caseD_5(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined1 uVar5;
  int iVar6;
  int *unaff_EBX;
  int unaff_EBP;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  
  UTIL_MakeVectors__FRC6Vector(*unaff_EBX + 0x74);
  iVar6 = gpGlobals;
  *(undefined4 *)(gpGlobals + 0x30) = 0;
  fVar3 = *(float *)(iVar6 + 0x28) * -200.0;
  fVar4 = *(float *)(iVar6 + 0x2c) * -200.0;
  fVar1 = *(float *)(iVar6 + 0x30);
  *(float *)(unaff_EBP + -0x40) = fVar3;
  *(float *)(unaff_EBP + -0x3c) = fVar4;
  *(float *)(unaff_EBP + -0x38) = fVar1 * -200.0;
  iVar6 = *unaff_EBX;
  fVar1 = *(float *)(iVar6 + 0xc);
  fVar2 = *(float *)(iVar6 + 0x10);
  *(float *)(unaff_EBP + -0x10) = *(float *)(iVar6 + 8) + fVar3;
  *(float *)(unaff_EBP + -0xc) = fVar1 + fVar4;
  *(float *)(unaff_EBP + -8) = fVar2 + *(float *)(unaff_EBP + -0x38);
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -8);
  lVar7 = (longdouble)(*DAT_0017562c)(0xc2c80000,0x42c80000);
  iVar6 = gpGlobals;
  lVar8 = lVar7 * (longdouble)*(float *)(gpGlobals + 0x40);
  lVar9 = lVar7 * (longdouble)*(float *)(gpGlobals + 0x44);
  fVar1 = *(float *)(gpGlobals + 0x48);
  *(float *)(unaff_EBP + -0x10) = (float)lVar8;
  *(float *)(unaff_EBP + -0xc) = (float)lVar9;
  *(float *)(unaff_EBP + -8) = (float)(lVar7 * (longdouble)fVar1);
  *(float *)(unaff_EBP + -0x40) = (float)((longdouble)*(float *)(unaff_EBP + -0x34) + lVar8);
  *(float *)(unaff_EBP + -0x3c) = (float)((longdouble)*(float *)(unaff_EBP + -0x30) + lVar9);
  *(float *)(unaff_EBP + -0x38) = *(float *)(unaff_EBP + -0x2c) + *(float *)(unaff_EBP + -8);
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x40);
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x3c);
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x38);
  *(float *)(unaff_EBP + -4) = *(float *)(*unaff_EBX + 0x15c) * 0.8 + *(float *)(unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -4);
  UTIL_VecToAngles__FRC6Vector(unaff_EBP + -0x40,iVar6 + 0x28);
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x40);
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x3c);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x38);
  lVar7 = (longdouble)(*DAT_0017562c)(0xc0c00000,0x40c00000);
  *(float *)(unaff_EBP + -0x18) = (float)(lVar7 + (longdouble)*(float *)(unaff_EBP + -0x18));
  iVar6 = UTIL_PointContents__FRC6Vector(unaff_EBP + -0x34);
  if (iVar6 != -2) {
    iVar6 = 0;
    do {
      UTIL_MakeVectors__FRC6Vector(unaff_EBP + -0x1c);
      fVar3 = (float)(iVar6 * -0x14 + 600);
      fVar1 = *(float *)(gpGlobals + 0x2c);
      fVar2 = *(float *)(gpGlobals + 0x30);
      *(float *)(unaff_EBP + -0x40) = fVar3 * *(float *)(gpGlobals + 0x28);
      *(float *)(unaff_EBP + -0x3c) = fVar3 * fVar1;
      *(float *)(unaff_EBP + -0x38) = fVar3 * fVar2;
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x40);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x3c);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x38);
      (*DAT_00175578)(1,0x17,0,*(undefined4 *)(*unaff_EBX + 0x1e8));
      (*DAT_00175580)(0x77);
      (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x34));
      (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x30));
      (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x2c));
      (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x28));
      (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x24));
      (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -0x20));
      (*DAT_00175588)((int)g_sModelIndexNail);
      (*DAT_00175580)(6);
      uVar5 = (*DAT_001755dc)(*(undefined4 *)(*unaff_EBX + 0x1e8));
      (*DAT_00175580)(uVar5);
      (*DAT_0017557c)();
      lVar7 = (longdouble)(*DAT_0017562c)(0x40800000,0x41000000);
      *(float *)(unaff_EBP + -0x18) = (float)(lVar7 + (longdouble)*(float *)(unaff_EBP + -0x18));
      lVar7 = (longdouble)(*DAT_0017562c)(0xc1200000,0x41200000);
      *(float *)(unaff_EBP + -0x2c) = (float)(lVar7 + (longdouble)*(float *)(unaff_EBP + -0x2c));
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
  }
  return;
}


// switchD_00104c84::caseD_6  @ 00105340
void switchD_00104c84::caseD_6(void)

{
  int iVar1;
  int *unaff_EBX;
  int unaff_EBP;
  longdouble lVar2;
  
  iVar1 = *unaff_EBX;
  *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(iVar1 + 0x74);
  *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(iVar1 + 0x78);
  *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(iVar1 + 0x7c);
  lVar2 = (longdouble)(*DAT_0017562c)(0xc1700000,0x41700000);
  *(float *)(unaff_EBP + -0x40) = (float)(lVar2 + (longdouble)*(float *)(unaff_EBP + -0x40));
  lVar2 = (longdouble)(*DAT_0017562c)(0xc2480000,0x42480000);
  *(float *)(unaff_EBP + -0x3c) = (float)(lVar2 + (longdouble)*(float *)(unaff_EBP + -0x3c));
  lVar2 = (longdouble)(*DAT_0017562c)(0xc1c80000,0x41c80000);
  *(float *)(unaff_EBP + -0x38) = (float)(lVar2 + (longdouble)*(float *)(unaff_EBP + -0x38));
  UTIL_VecToAngles__FRC6Vector(unaff_EBP + -0x34,unaff_EBP + -0x40);
  iVar1 = DAT_00154ce4;
  if (-1 < DAT_00154ce4) {
    (*DAT_00175564)(*(undefined4 *)(*unaff_EBX + 0x1e8),"play weapons/sbarrel1.wav\n");
    (*DAT_00175578)(1,0x17,0,*(undefined4 *)(*unaff_EBX + 0x1e8));
    (*DAT_00175580)(0x7e);
    (*DAT_00175594)(*(undefined4 *)(*unaff_EBX + 8));
    (*DAT_00175594)(*(undefined4 *)(*unaff_EBX + 0xc));
    (*DAT_00175594)(*(undefined4 *)(*unaff_EBX + 0x10));
    *(float *)(unaff_EBP + -4) = *(float *)(unaff_EBP + -0x40) * 10.0;
    (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -4));
    *(float *)(unaff_EBP + -4) = *(float *)(unaff_EBP + -0x3c) * 10.0;
    (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -4));
    *(float *)(unaff_EBP + -4) = *(float *)(unaff_EBP + -0x38) * 10.0;
    (*DAT_00175594)(*(undefined4 *)(unaff_EBP + -4));
    (*DAT_00175594)(0x42a00000);
    (*DAT_00175594)(0x42a00000);
    (*DAT_00175580)(6);
    (*DAT_00175580)(iVar1);
    (*DAT_0017557c)();
  }
  return;
}


// switchD_00119b08::caseD_3  @ 00119c00
undefined4 switchD_00119b08::caseD_3(void)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  float fVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  float *unaff_EBX;
  int unaff_EBP;
  float *unaff_ESI;
  int *unaff_EDI;
  undefined4 uVar7;
  
code_r0x00119c00:
  iVar5 = EntityFromIndex__18CSaveRestoreBufferi(*(undefined4 *)(unaff_EBP + 8),*unaff_EBX);
  if (iVar5 == 0) goto LAB_00119d4d;
  *unaff_ESI = *(float *)(iVar5 + 0xd8);
LAB_00119d81:
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
  if ((int)(short)unaff_EDI[3] <= *(int *)(unaff_EBP + -0x1c)) {
    return *(undefined4 *)(unaff_EBP + -0x20);
  }
  iVar5 = *(int *)(unaff_EBP + -0x1c) * *(int *)(gSizes + *unaff_EDI * 4);
  unaff_ESI = (float *)(iVar5 + *(int *)(unaff_EBP + 0xc) + unaff_EDI[2]);
  unaff_EBX = (float *)(*(int *)(unaff_EBP + 0x24) + iVar5);
  switch(*unaff_EDI) {
  case 0:
    *unaff_ESI = *unaff_EBX;
    goto LAB_00119d81;
  case 1:
  case 0x10:
  case 0x11:
    __s = *(char **)(unaff_EBP + 0x24);
    iVar5 = 0;
    if (0 < *(int *)(unaff_EBP + -0x1c)) {
      do {
        for (; *__s != '\0'; __s = __s + 1) {
        }
        __s = __s + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(unaff_EBP + -0x1c));
    }
    sVar2 = strlen(__s);
    if (sVar2 != 0) {
      fVar3 = (float)(*DAT_001755cc)(__s);
      *unaff_ESI = fVar3;
      if ((fVar3 != 0.0) && (*(int *)(*(int *)(unaff_EBP + 8) + 8) != 0)) {
        if (*unaff_EDI == 0x10) {
          iVar5 = *(int *)(gpGlobals + 0x98);
          pcVar4 = g_engfuncs;
        }
        else {
          if (*unaff_EDI != 0x11) goto LAB_00119d81;
          iVar5 = *(int *)(gpGlobals + 0x98);
          pcVar4 = DAT_001754c4;
        }
        (*pcVar4)((int)fVar3 + iVar5);
      }
      goto LAB_00119d81;
    }
    break;
  case 2:
    iVar5 = EntityFromIndex__18CSaveRestoreBufferi(*(undefined4 *)(unaff_EBP + 8),*unaff_EBX);
    if (iVar5 != 0) {
      fVar3 = (float)(*DAT_001755d8)(iVar5);
      *unaff_ESI = fVar3;
      goto LAB_00119d81;
    }
    break;
  case 3:
    goto code_r0x00119c00;
  case 4:
    iVar5 = *(int *)(gSizes + *unaff_EDI * 4);
    iVar1 = *(int *)(unaff_EBP + -0x1c);
    iVar6 = EntityFromIndex__18CSaveRestoreBufferi(*(undefined4 *)(unaff_EBP + 8),*unaff_EBX);
    if (iVar6 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined4 *)(iVar6 + 0xd8);
    }
    __as__7EHANDLEP11CBaseEntity((float *)((int)unaff_ESI + (8 - iVar5) * iVar1),uVar7);
    goto LAB_00119d81;
  case 5:
    iVar5 = EntityFromIndex__18CSaveRestoreBufferi(*(undefined4 *)(unaff_EBP + 8),*unaff_EBX);
    if (iVar5 != 0) {
      *unaff_ESI = (float)(iVar5 + 0xdc);
      goto LAB_00119d81;
    }
    break;
  case 6:
    fVar3 = (float)EntityFromIndex__18CSaveRestoreBufferi(*(undefined4 *)(unaff_EBP + 8),*unaff_EBX)
    ;
    *unaff_ESI = fVar3;
    goto LAB_00119d81;
  case 7:
    *unaff_ESI = *unaff_EBX;
    unaff_ESI[1] = unaff_EBX[1];
    unaff_ESI[2] = unaff_EBX[2];
    goto LAB_00119d81;
  case 8:
    *unaff_ESI = *unaff_EBX + *(float *)(unaff_EBP + -0xc);
    unaff_ESI[1] = unaff_EBX[1] + *(float *)(unaff_EBP + -8);
    unaff_ESI[2] = unaff_EBX[2] + *(float *)(unaff_EBP + -4);
    goto LAB_00119d81;
  case 9:
  case 10:
  case 0xc:
    *unaff_ESI = *unaff_EBX;
    goto LAB_00119d81;
  case 0xb:
    sVar2 = strlen((char *)unaff_EBX);
    if (sVar2 != 0) {
      fVar3 = (float)(*DAT_001755f8)(unaff_EBX);
      *unaff_ESI = fVar3;
      goto LAB_00119d81;
    }
    break;
  case 0xd:
    *(undefined2 *)unaff_ESI = *(undefined2 *)unaff_EBX;
    goto LAB_00119d81;
  case 0xe:
    *(undefined1 *)unaff_ESI = *(undefined1 *)unaff_EBX;
    goto LAB_00119d81;
  case 0xf:
    *unaff_ESI = *(float *)(unaff_EBP + -0x24) + *unaff_EBX;
    goto LAB_00119d81;
  default:
    goto switchD_00119b08_default;
  }
LAB_00119d4d:
  *unaff_ESI = 0.0;
  goto LAB_00119d81;
switchD_00119b08_default:
  (*DAT_001755b4)(4,"Bad field type\n");
  goto LAB_00119d81;
}


// switchD_00119b08::default  @ 00119d70
undefined4 switchD_00119b08::default(void)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  char *__s;
  size_t sVar4;
  float fVar5;
  code *pcVar6;
  int iVar7;
  float *__s_00;
  int unaff_EBP;
  int *unaff_EDI;
  undefined4 uVar8;
  
code_r0x00119d70:
  (*DAT_001755b4)(4,"Bad field type\n");
LAB_00119d81:
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
  if ((int)(short)unaff_EDI[3] <= *(int *)(unaff_EBP + -0x1c)) {
    return *(undefined4 *)(unaff_EBP + -0x20);
  }
  iVar3 = *(int *)(unaff_EBP + -0x1c) * *(int *)(gSizes + *unaff_EDI * 4);
  pfVar1 = (float *)(iVar3 + *(int *)(unaff_EBP + 0xc) + unaff_EDI[2]);
  __s_00 = (float *)(*(int *)(unaff_EBP + 0x24) + iVar3);
  switch(*unaff_EDI) {
  case 0:
    *pfVar1 = *__s_00;
    goto LAB_00119d81;
  case 1:
  case 0x10:
  case 0x11:
    __s = *(char **)(unaff_EBP + 0x24);
    iVar3 = 0;
    if (0 < *(int *)(unaff_EBP + -0x1c)) {
      do {
        for (; *__s != '\0'; __s = __s + 1) {
        }
        __s = __s + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(unaff_EBP + -0x1c));
    }
    sVar4 = strlen(__s);
    if (sVar4 != 0) {
      fVar5 = (float)(*DAT_001755cc)(__s);
      *pfVar1 = fVar5;
      if ((fVar5 != 0.0) && (*(int *)(*(int *)(unaff_EBP + 8) + 8) != 0)) {
        if (*unaff_EDI == 0x10) {
          iVar3 = *(int *)(gpGlobals + 0x98);
          pcVar6 = g_engfuncs;
        }
        else {
          if (*unaff_EDI != 0x11) goto LAB_00119d81;
          iVar3 = *(int *)(gpGlobals + 0x98);
          pcVar6 = DAT_001754c4;
        }
        (*pcVar6)((int)fVar5 + iVar3);
      }
      goto LAB_00119d81;
    }
    break;
  case 2:
    iVar3 = EntityFromIndex__18CSaveRestoreBufferi(*(undefined4 *)(unaff_EBP + 8),*__s_00);
    if (iVar3 != 0) {
      fVar5 = (float)(*DAT_001755d8)(iVar3);
      *pfVar1 = fVar5;
      goto LAB_00119d81;
    }
    break;
  case 3:
    iVar3 = EntityFromIndex__18CSaveRestoreBufferi(*(undefined4 *)(unaff_EBP + 8),*__s_00);
    if (iVar3 != 0) {
      *pfVar1 = *(float *)(iVar3 + 0xd8);
      goto LAB_00119d81;
    }
    break;
  case 4:
    iVar3 = *(int *)(gSizes + *unaff_EDI * 4);
    iVar2 = *(int *)(unaff_EBP + -0x1c);
    iVar7 = EntityFromIndex__18CSaveRestoreBufferi(*(undefined4 *)(unaff_EBP + 8),*__s_00);
    if (iVar7 == 0) {
      uVar8 = 0;
    }
    else {
      uVar8 = *(undefined4 *)(iVar7 + 0xd8);
    }
    __as__7EHANDLEP11CBaseEntity((float *)((int)pfVar1 + (8 - iVar3) * iVar2),uVar8);
    goto LAB_00119d81;
  case 5:
    iVar3 = EntityFromIndex__18CSaveRestoreBufferi(*(undefined4 *)(unaff_EBP + 8),*__s_00);
    if (iVar3 != 0) {
      *pfVar1 = (float)(iVar3 + 0xdc);
      goto LAB_00119d81;
    }
    break;
  case 6:
    fVar5 = (float)EntityFromIndex__18CSaveRestoreBufferi(*(undefined4 *)(unaff_EBP + 8),*__s_00);
    *pfVar1 = fVar5;
    goto LAB_00119d81;
  case 7:
    *pfVar1 = *__s_00;
    pfVar1[1] = __s_00[1];
    pfVar1[2] = __s_00[2];
    goto LAB_00119d81;
  case 8:
    *pfVar1 = *__s_00 + *(float *)(unaff_EBP + -0xc);
    pfVar1[1] = __s_00[1] + *(float *)(unaff_EBP + -8);
    pfVar1[2] = __s_00[2] + *(float *)(unaff_EBP + -4);
    goto LAB_00119d81;
  case 9:
  case 10:
  case 0xc:
    *pfVar1 = *__s_00;
    goto LAB_00119d81;
  case 0xb:
    sVar4 = strlen((char *)__s_00);
    if (sVar4 != 0) {
      fVar5 = (float)(*DAT_001755f8)(__s_00);
      *pfVar1 = fVar5;
      goto LAB_00119d81;
    }
    break;
  case 0xd:
    *(undefined2 *)pfVar1 = *(undefined2 *)__s_00;
    goto LAB_00119d81;
  case 0xe:
    *(undefined1 *)pfVar1 = *(undefined1 *)__s_00;
    goto LAB_00119d81;
  case 0xf:
    goto switchD_00119b08_caseD_f;
  default:
    goto code_r0x00119d70;
  }
  *pfVar1 = 0.0;
  goto LAB_00119d81;
switchD_00119b08_caseD_f:
  *pfVar1 = *(float *)(unaff_EBP + -0x24) + *__s_00;
  goto LAB_00119d81;
}


