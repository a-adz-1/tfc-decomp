// DetpackExplode__8CDetpack  @ 00090cbc
void DetpackExplode__8CDetpack(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  code *pcVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined1 *puVar10;
  int *piVar11;
  undefined4 auStackY_f8 [2];
  int aiStack_b8 [9];
  int aiStack_94 [2];
  float afStack_8c [18];
  float afStack_44 [8];
  int aiStack_24 [2];
  float afStack_1c [7];
  
  puVar10 = &stack0xffffff2c;
  iVar9 = *(int *)(*param_1 + 0x198);
  if ((iVar9 == 0) && (iVar9 = (*DAT_001a7f54)(0), iVar9 == 0)) {
    piVar11 = (int *)0x0;
  }
  else {
    piVar11 = *(int **)(iVar9 + 0x7c);
  }
  iVar9 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
  if (((iVar9 == -2) || (iVar9 == -6)) || (piVar11[0x1e] == 1)) {
    ClientPrint__FP9entvars_siPCcN42(*piVar11,1,"#Detpack_fizzle",0,0,0,0);
  }
  else {
    UTIL_ClientPrintAll__FiPCcN41(1,"#FITH",0,0,0,0);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"weapons/mortarhit.wav",0x3f800000,0x3f4ccccd,0,
               100);
    if (birthday != 0) {
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#SpreadsCheer",*(int *)(*piVar11 + 0x1d0) + *(int *)(gpGlobals + 0x98),0,0,0);
    }
    piVar11 = (int *)0x0;
    puVar8 = &stack0xffffff2c;
    while( true ) {
      puVar10 = puVar8;
      *(undefined4 *)(puVar10 + -4) = 0x44bb8000;
      *(undefined1 **)(puVar10 + -8) = puVar10 + 200;
      *(int **)(puVar10 + -0xc) = piVar11;
      *(undefined4 *)(puVar10 + -0x10) = 0x91169;
      piVar11 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
      if (piVar11 == (int *)0x0) break;
      *(undefined1 **)(puVar10 + 0x44) = puVar10 + 0x78;
      iVar9 = piVar11[0xf5];
      *(int **)(puVar10 + -4) = piVar11;
      *(undefined1 **)(puVar10 + -8) = puVar10 + 0x78;
      pcVar5 = *(code **)(iVar9 + 0xc4);
      *(code **)(puVar10 + 0x44) = pcVar5;
      *(undefined4 *)(puVar10 + -0xc) = 0x90e72;
      (*pcVar5)();
      iVar9 = *piVar11;
      fVar1 = *(float *)(iVar9 + 0x178);
      fVar2 = *(float *)(iVar9 + 0x17c);
      *(float *)(puVar10 + 0xb8) = *(float *)(puVar10 + 0x74) + *(float *)(iVar9 + 0x174);
      *(float *)(puVar10 + 0xbc) = *(float *)(puVar10 + 0x78) + fVar1;
      *(float *)(puVar10 + 0xc0) = *(float *)(puVar10 + 0x7c) + fVar2;
      *(undefined1 **)(puVar10 + 0x40) = puVar10 + 0x80;
      *(undefined1 **)(puVar10 + -8) = puVar10 + 0x80;
      iVar9 = **(int **)(puVar10 + 0xd4);
      *(int *)(puVar10 + 0x2c) = iVar9;
      uVar7 = *(undefined4 *)(iVar9 + 0x208);
      *(undefined4 *)(puVar10 + 0x40) = uVar7;
      *(undefined4 *)(puVar10 + -0xc) = uVar7;
      *(undefined4 *)(puVar10 + -0x10) = 0;
      *(undefined1 **)(puVar10 + 0x40) = puVar10 + 0xb8;
      *(undefined1 **)(puVar10 + -0x14) = puVar10 + 0xb8;
      *(undefined1 **)(puVar10 + 0x40) = puVar10 + 0xc4;
      *(undefined1 **)(puVar10 + -0x18) = puVar10 + 0xc4;
      *(undefined4 *)(puVar10 + -0x1c) = 0x90efa;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
      fVar1 = *(float *)(puVar10 + 0x90);
      if (((byte)((1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) - 1) < 0x40) ||
         (puVar8 = puVar10 + -4, *(int *)(puVar10 + 0xb0) == *(int *)(*piVar11 + 0x208))) {
        iVar9 = *(int *)*piVar11;
        iVar6 = *(int *)(gpGlobals + 0x98);
        *(char **)(puVar10 + -8) = "info_tfgoal";
        *(int *)(puVar10 + -0xc) = iVar9 + iVar6;
        *(undefined4 *)(puVar10 + -0x10) = 0x90f4a;
        iVar9 = strcmp(*(char **)(puVar10 + -0xc),*(char **)(puVar10 + -8));
        if (iVar9 == 0) {
          puVar8 = puVar10 + -4;
          if (((*(byte *)(piVar11 + 0x88) & 2) != 0) &&
             (puVar8 = puVar10 + -4,
             (byte)((byte)((ushort)((ushort)NAN((float)piVar11[0x93]) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)piVar11[0x93] == 0.0) << 0xe) >> 8)) == 0x40)) {
            *(int **)(puVar10 + -8) = piVar11;
            *(undefined4 *)(puVar10 + -0xc) = *(undefined4 *)(puVar10 + 0x44);
            *(int **)(puVar10 + -0x10) = piVar11;
            *(undefined4 *)(puVar10 + -0x14) = 0x90f86;
            ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0();
            puVar8 = puVar10 + -4;
          }
        }
        else {
          iVar9 = *piVar11;
          fVar1 = *(float *)(iVar9 + 0x16c);
          puVar8 = puVar10 + -4;
          if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
            iVar6 = **(int **)(puVar10 + 0xd4);
            fVar1 = *(float *)(iVar9 + 8) - *(float *)(iVar6 + 8);
            fVar3 = *(float *)(iVar9 + 0xc) - *(float *)(iVar6 + 0xc);
            fVar2 = *(float *)(iVar9 + 0x10) - *(float *)(iVar6 + 0x10);
            *(float *)(puVar10 + 0x74) = fVar1;
            *(float *)(puVar10 + 0x78) = fVar3;
            *(float *)(puVar10 + 0x7c) = fVar2;
            *(float *)(puVar10 + 0x70) = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
            fVar1 = *(float *)(puVar10 + 0x70);
            puVar8 = puVar10 + -4;
            if ((byte)(700.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 700.0) << 0xe) >> 8)) != 1) {
              fVar1 = *(float *)(*piVar11 + 0xe0);
              fVar2 = *(float *)(*piVar11 + 0xec);
              fVar3 = *(float *)(*piVar11 + 0xe4);
              fVar4 = *(float *)(*piVar11 + 0xf0);
              *(float *)(puVar10 + 0x4c) = *(float *)(*piVar11 + 0xdc) + *(float *)(*piVar11 + 0xe8)
              ;
              *(float *)(puVar10 + 0x50) = fVar1 + fVar2;
              *(float *)(puVar10 + 0x54) = fVar3 + fVar4;
              *(float *)(puVar10 + 0x58) = *(float *)(puVar10 + 0x4c) * 0.5;
              *(float *)(puVar10 + 0x5c) = *(float *)(puVar10 + 0x50) * 0.5;
              *(float *)(puVar10 + 0x60) = *(float *)(puVar10 + 0x54) * 0.5;
              fVar1 = *(float *)(*piVar11 + 0xc);
              fVar2 = *(float *)(*piVar11 + 0x10);
              *(float *)(puVar10 + 100) =
                   *(float *)(*piVar11 + 8) + *(float *)(puVar10 + 0x4c) * 0.5;
              *(float *)(puVar10 + 0x68) = fVar1 + *(float *)(puVar10 + 0x50) * 0.5;
              *(float *)(puVar10 + 0x6c) = fVar2 + *(float *)(puVar10 + 0x60);
              fVar1 = *(float *)(iVar6 + 8) - *(float *)(puVar10 + 100);
              fVar3 = *(float *)(iVar6 + 0xc) - *(float *)(puVar10 + 0x68);
              fVar2 = *(float *)(iVar6 + 0x10) - *(float *)(puVar10 + 0x6c);
              *(float *)(puVar10 + 0x4c) = fVar1;
              *(float *)(puVar10 + 0x50) = fVar3;
              *(float *)(puVar10 + 0x54) = fVar2;
              *(float *)(puVar10 + 0x70) = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
              *(float *)(puVar10 + 0x48) = *(float *)(puVar10 + 0x70) * 0.5;
              fVar1 = *(float *)(puVar10 + 0x48);
              if (fVar1 < 0.0) {
                fVar1 = 0.0;
              }
              fVar1 = 700.0 - fVar1;
              puVar8 = puVar10 + -4;
              if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
                iVar9 = piVar11[0xf5];
                *(undefined4 *)(puVar10 + -8) = 0x40;
                *(float *)(puVar10 + -0xc) = fVar1 + fVar1;
                uVar7 = **(undefined4 **)(puVar10 + 0x44);
                *(undefined4 *)(puVar10 + 0x28) = uVar7;
                *(undefined4 *)(puVar10 + -0x10) = uVar7;
                uVar7 = **(undefined4 **)(puVar10 + 0xd4);
                *(undefined4 *)(puVar10 + 0x24) = uVar7;
                *(undefined4 *)(puVar10 + -0x14) = uVar7;
                *(int **)(puVar10 + -0x18) = piVar11;
                pcVar5 = *(code **)(iVar9 + 0x34);
                *(code **)(puVar10 + 0x40) = pcVar5;
                *(undefined4 *)(puVar10 + -0x1c) = 0x9114f;
                (*pcVar5)();
                puVar8 = puVar10 + -4;
              }
            }
          }
        }
      }
    }
    iVar9 = **(int **)(puVar10 + 0xd8);
    *(int *)(puVar10 + 0x44) = iVar9 + 8;
    *(undefined4 *)(puVar10 + -4) = 0;
    *(int *)(puVar10 + -8) = iVar9 + 8;
    *(undefined4 *)(puVar10 + -0xc) = 0x17;
    *(undefined4 *)(puVar10 + -0x10) = 5;
    *(code **)(puVar10 + 0x44) = DAT_001a7ef8;
    *(undefined4 *)(puVar10 + -0x14) = 0x911a1;
    (*DAT_001a7ef8)();
    *(undefined4 *)(puVar10 + -4) = 3;
    *(code **)(puVar10 + 0x44) = DAT_001a7f00;
    *(undefined4 *)(puVar10 + -8) = 0x911ba;
    (*DAT_001a7f00)();
    iVar9 = **(int **)(puVar10 + 0xd8);
    *(int *)(puVar10 + 0x24) = iVar9;
    *(undefined4 *)(puVar10 + -8) = *(undefined4 *)(iVar9 + 8);
    *(code **)(puVar10 + 0x44) = DAT_001a7f14;
    *(undefined4 *)(puVar10 + -0xc) = 0x911e6;
    (*DAT_001a7f14)();
    iVar9 = **(int **)(puVar10 + 0xd8);
    *(int *)(puVar10 + 0x20) = iVar9;
    *(undefined4 *)(puVar10 + -0xc) = *(undefined4 *)(iVar9 + 0xc);
    *(code **)(puVar10 + 0x44) = DAT_001a7f14;
    *(undefined4 *)(puVar10 + -0x10) = 0x91212;
    (*DAT_001a7f14)();
    iVar9 = **(int **)(puVar10 + 0xd8);
    *(int *)(puVar10 + 0x1c) = iVar9;
    *(undefined4 *)(puVar10 + -0x10) = *(undefined4 *)(iVar9 + 0x10);
    *(code **)(puVar10 + 0x44) = DAT_001a7f14;
    *(undefined4 *)(puVar10 + -0x14) = 0x9123e;
    (*DAT_001a7f14)();
    *(int *)(puVar10 + 0x44) = (int)g_sModelIndexFireball;
    *(int *)(puVar10 + -0x14) = (int)g_sModelIndexFireball;
    *(code **)(puVar10 + 0x44) = DAT_001a7f08;
    *(undefined4 *)(puVar10 + -0x18) = 0x91262;
    (*DAT_001a7f08)();
    *(undefined4 *)(puVar10 + -0x18) = 0x32;
    *(code **)(puVar10 + 0x44) = DAT_001a7f00;
    *(undefined4 *)(puVar10 + -0x1c) = 0x91278;
    (*DAT_001a7f00)();
    *(undefined4 *)(puVar10 + -0x1c) = 0xf;
    *(code **)(puVar10 + 0x44) = DAT_001a7f00;
    *(undefined4 *)(puVar10 + -0x20) = 0x9128e;
    (*DAT_001a7f00)();
    *(undefined4 *)(puVar10 + -0x20) = 3;
    *(code **)(puVar10 + 0x44) = DAT_001a7f00;
    *(undefined4 *)(puVar10 + -0x24) = 0x912a4;
    (*DAT_001a7f00)();
    *(undefined4 *)(puVar10 + -4) = 0x912b5;
    (*DAT_001a7efc)();
  }
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*(int *)(puVar10 + 0xd8) + 0x108)) << 10) >> 8)
            | (byte)((ushort)((ushort)(*(float *)(*(int *)(puVar10 + 0xd8) + 0x108) == 1.0) << 0xe)
                    >> 8)) != 0x40) goto LAB_0009135d;
  iVar9 = *(int *)(**(int **)(puVar10 + 0xd8) + 400);
  if (iVar9 == 0) {
    *(undefined4 *)(puVar10 + -4) = 0;
    *(undefined4 *)(puVar10 + -8) = 0x91326;
    iVar9 = (*DAT_001a7f54)();
    if (iVar9 != 0) goto LAB_0009132f;
    iVar9 = 0;
  }
  else {
LAB_0009132f:
    iVar9 = *(int *)(iVar9 + 0x7c);
  }
  *(byte *)(iVar9 + 0x86) = *(byte *)(iVar9 + 0x86) & 0xfe;
  *(int *)(puVar10 + -4) = iVar9;
  *(undefined4 *)(puVar10 + -8) = 0x91343;
  TeamFortress_SetSpeed__11CBasePlayer();
  *(undefined4 *)(puVar10 + -8) = 10;
  *(int *)(puVar10 + -0xc) = iVar9;
  *(undefined4 *)(puVar10 + -0x10) = 0x9134b;
  iVar9 = FindTimer__11CBaseEntityi();
  if (iVar9 != 0) {
    *(int *)(puVar10 + -4) = iVar9;
    *(undefined4 *)(puVar10 + -8) = 0x9135a;
    dremove__FP11CBaseEntity();
  }
LAB_0009135d:
  if (*(int *)(*(int *)(puVar10 + 0xd8) + 0x640) != 0) {
    uVar7 = *(undefined4 *)(*(int *)(puVar10 + 0xd8) + 0x640);
    *(undefined4 *)(puVar10 + 0x14) = uVar7;
    *(undefined4 *)(puVar10 + -4) = uVar7;
    *(undefined4 *)(puVar10 + -8) = 0x9137d;
    dremove__FP11CBaseEntity();
  }
  *(undefined4 *)(puVar10 + -4) = *(undefined4 *)(puVar10 + 0xd8);
  *(undefined4 *)(puVar10 + -8) = 0x9138d;
  dremove__FP11CBaseEntity();
  return;
}


