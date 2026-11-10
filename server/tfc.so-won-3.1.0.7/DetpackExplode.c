// DetpackExplode__8CDetpack  @ 0009ab28
void DetpackExplode__8CDetpack(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  code *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  int *piVar12;
  undefined4 auStackY_118 [2];
  int aiStack_c8 [13];
  int aiStack_94 [2];
  float local_8c [18];
  float afStack_44 [8];
  int aiStack_24 [2];
  float afStack_1c [7];
  
  puVar11 = &stack0xffffff0c;
  iVar8 = *(int *)(*param_1 + 0x198);
  if ((iVar8 == 0) && (iVar8 = (*DAT_001c1134)(0), iVar8 == 0)) {
    piVar12 = (int *)0x0;
  }
  else {
    piVar12 = *(int **)(iVar8 + 0x7c);
  }
  iVar8 = UTIL_PointContents__FRC6Vector(*param_1 + 8);
  if (((iVar8 == -2) || (iVar8 == -6)) || (piVar12[0x1e] == 1)) {
    ClientPrint__FP9entvars_siPCcN42(*piVar12,1,"#Detpack_fizzle",0,0,0,0);
    if (piVar12[0x48] == 0) {
      pcVar9 = "SPECTATOR";
    }
    else {
      pcVar9 = (char *)GetTeamName__Fi(piVar12[0x48]);
    }
    uVar10 = (*DAT_001c11f4)(*(undefined4 *)(*piVar12 + 0x208),pcVar9);
    uVar10 = (*DAT_001c11e4)(*(undefined4 *)(*piVar12 + 0x208),uVar10);
    UTIL_LogPrintf__FPce
              ("\"<-1><><>\" triggered \"Detpack_Fizzle\" against \"%s<%i><%u><%s>\"\n",
               *(int *)(*piVar12 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar10);
  }
  else {
    UTIL_ClientPrintAll__FiPCcN41(1,"#FITH",0,0,0,0);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"weapons/mortarhit.wav",0x3f800000,0x3f4ccccd,0,
               100);
    if (birthday != 0) {
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#SpreadsCheer",*(int *)(*piVar12 + 0x1d0) + *(int *)(gpGlobals + 0x98),0,0,0);
    }
    if (piVar12[0x48] == 0) {
      pcVar9 = "SPECTATOR";
    }
    else {
      pcVar9 = (char *)GetTeamName__Fi(piVar12[0x48]);
    }
    uVar10 = (*DAT_001c11f4)(*(undefined4 *)(*piVar12 + 0x208),pcVar9);
    uVar10 = (*DAT_001c11e4)(*(undefined4 *)(*piVar12 + 0x208),uVar10);
    UTIL_LogPrintf__FPce
              ("\"%s<%i><%u><%s>\" triggered \"Detpack_Explode\"\n",
               *(int *)(*piVar12 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar10);
    piVar12 = (int *)0x0;
    puVar7 = &stack0xffffff0c;
    while( true ) {
      puVar11 = puVar7;
      *(undefined4 *)(puVar11 + -4) = 0x44bb8000;
      *(undefined1 **)(puVar11 + -8) = puVar11 + 0xe8;
      *(int **)(puVar11 + -0xc) = piVar12;
      *(undefined4 *)(puVar11 + -0x10) = 0x9b0de;
      piVar12 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
      if (piVar12 == (int *)0x0) break;
      *(undefined1 **)(puVar11 + 100) = puVar11 + 0x98;
      iVar8 = piVar12[0x111];
      *(int **)(puVar11 + -4) = piVar12;
      *(undefined1 **)(puVar11 + -8) = puVar11 + 0x98;
      pcVar5 = *(code **)(iVar8 + 0xcc);
      *(code **)(puVar11 + 100) = pcVar5;
      *(undefined4 *)(puVar11 + -0xc) = 0x9adb5;
      (*pcVar5)();
      iVar8 = *piVar12;
      fVar1 = *(float *)(iVar8 + 0x178);
      fVar2 = *(float *)(iVar8 + 0x17c);
      *(float *)(puVar11 + 0xd8) = *(float *)(puVar11 + 0x94) + *(float *)(iVar8 + 0x174);
      *(float *)(puVar11 + 0xdc) = *(float *)(puVar11 + 0x98) + fVar1;
      *(float *)(puVar11 + 0xe0) = *(float *)(puVar11 + 0x9c) + fVar2;
      *(undefined1 **)(puVar11 + 0x60) = puVar11 + 0xa0;
      *(undefined1 **)(puVar11 + -8) = puVar11 + 0xa0;
      iVar8 = **(int **)(puVar11 + 0xf4);
      *(int *)(puVar11 + 0x3c) = iVar8;
      uVar10 = *(undefined4 *)(iVar8 + 0x208);
      *(undefined4 *)(puVar11 + 0x60) = uVar10;
      *(undefined4 *)(puVar11 + -0xc) = uVar10;
      *(undefined4 *)(puVar11 + -0x10) = 0;
      *(undefined1 **)(puVar11 + 0x60) = puVar11 + 0xd8;
      *(undefined1 **)(puVar11 + -0x14) = puVar11 + 0xd8;
      *(undefined1 **)(puVar11 + 0x60) = puVar11 + 0xe4;
      *(undefined1 **)(puVar11 + -0x18) = puVar11 + 0xe4;
      *(undefined4 *)(puVar11 + -0x1c) = 0x9ae43;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
      fVar1 = *(float *)(puVar11 + 0xb0);
      if (((byte)((1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) - 1) < 0x40) ||
         (puVar7 = puVar11 + -4, *(int *)(puVar11 + 0xd0) == *(int *)(*piVar12 + 0x208))) {
        iVar8 = *(int *)*piVar12;
        iVar6 = *(int *)(gpGlobals + 0x98);
        *(char **)(puVar11 + -8) = "info_tfgoal";
        *(int *)(puVar11 + -0xc) = iVar8 + iVar6;
        *(undefined4 *)(puVar11 + -0x10) = 0x9ae93;
        iVar8 = strcmp(*(char **)(puVar11 + -0xc),*(char **)(puVar11 + -8));
        if (iVar8 == 0) {
          puVar7 = puVar11 + -4;
          if (((*(byte *)(piVar12 + 0x8a) & 2) != 0) &&
             (puVar7 = puVar11 + -4,
             (byte)((byte)((ushort)((ushort)NAN((float)piVar12[0x95]) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)piVar12[0x95] == 0.0) << 0xe) >> 8)) == 0x40)) {
            *(int **)(puVar11 + -8) = piVar12;
            *(undefined4 *)(puVar11 + -0xc) = *(undefined4 *)(puVar11 + 100);
            *(int **)(puVar11 + -0x10) = piVar12;
            *(undefined4 *)(puVar11 + -0x14) = 0x9aecf;
            ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0();
            puVar7 = puVar11 + -4;
          }
        }
        else {
          iVar8 = *piVar12;
          fVar1 = *(float *)(iVar8 + 0x16c);
          puVar7 = puVar11 + -4;
          if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
            iVar6 = **(int **)(puVar11 + 0xf4);
            fVar1 = *(float *)(iVar8 + 8) - *(float *)(iVar6 + 8);
            fVar3 = *(float *)(iVar8 + 0xc) - *(float *)(iVar6 + 0xc);
            fVar2 = *(float *)(iVar8 + 0x10) - *(float *)(iVar6 + 0x10);
            *(float *)(puVar11 + 0x94) = fVar1;
            *(float *)(puVar11 + 0x98) = fVar3;
            *(float *)(puVar11 + 0x9c) = fVar2;
            *(float *)(puVar11 + 0x90) = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
            fVar1 = *(float *)(puVar11 + 0x90);
            puVar7 = puVar11 + -4;
            if ((byte)(700.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 700.0) << 0xe) >> 8)) != 1) {
              fVar1 = *(float *)(*piVar12 + 0xe0);
              fVar2 = *(float *)(*piVar12 + 0xec);
              fVar3 = *(float *)(*piVar12 + 0xe4);
              fVar4 = *(float *)(*piVar12 + 0xf0);
              *(float *)(puVar11 + 0x6c) = *(float *)(*piVar12 + 0xdc) + *(float *)(*piVar12 + 0xe8)
              ;
              *(float *)(puVar11 + 0x70) = fVar1 + fVar2;
              *(float *)(puVar11 + 0x74) = fVar3 + fVar4;
              *(float *)(puVar11 + 0x78) = *(float *)(puVar11 + 0x6c) * 0.5;
              *(float *)(puVar11 + 0x7c) = *(float *)(puVar11 + 0x70) * 0.5;
              *(float *)(puVar11 + 0x80) = *(float *)(puVar11 + 0x74) * 0.5;
              fVar1 = *(float *)(*piVar12 + 0xc);
              fVar2 = *(float *)(*piVar12 + 0x10);
              *(float *)(puVar11 + 0x84) =
                   *(float *)(*piVar12 + 8) + *(float *)(puVar11 + 0x6c) * 0.5;
              *(float *)(puVar11 + 0x88) = fVar1 + *(float *)(puVar11 + 0x70) * 0.5;
              *(float *)(puVar11 + 0x8c) = fVar2 + *(float *)(puVar11 + 0x80);
              fVar1 = *(float *)(iVar6 + 8) - *(float *)(puVar11 + 0x84);
              fVar3 = *(float *)(iVar6 + 0xc) - *(float *)(puVar11 + 0x88);
              fVar2 = *(float *)(iVar6 + 0x10) - *(float *)(puVar11 + 0x8c);
              *(float *)(puVar11 + 0x6c) = fVar1;
              *(float *)(puVar11 + 0x70) = fVar3;
              *(float *)(puVar11 + 0x74) = fVar2;
              *(float *)(puVar11 + 0x90) = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
              *(float *)(puVar11 + 0x68) = *(float *)(puVar11 + 0x90) * 0.5;
              fVar1 = *(float *)(puVar11 + 0x68);
              if (fVar1 < 0.0) {
                fVar1 = 0.0;
              }
              fVar1 = 700.0 - fVar1;
              puVar7 = puVar11 + -4;
              if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
                iVar8 = piVar12[0x111];
                *(undefined4 *)(puVar11 + -8) = 0x40;
                *(float *)(puVar11 + -0xc) = fVar1 + fVar1;
                uVar10 = **(undefined4 **)(puVar11 + 100);
                *(undefined4 *)(puVar11 + 0x38) = uVar10;
                *(undefined4 *)(puVar11 + -0x10) = uVar10;
                uVar10 = **(undefined4 **)(puVar11 + 0xf4);
                *(undefined4 *)(puVar11 + 0x34) = uVar10;
                *(undefined4 *)(puVar11 + -0x14) = uVar10;
                *(int **)(puVar11 + -0x18) = piVar12;
                pcVar5 = *(code **)(iVar8 + 0x38);
                *(code **)(puVar11 + 0x60) = pcVar5;
                *(undefined4 *)(puVar11 + -0x1c) = 0x9b0c4;
                (*pcVar5)();
                puVar7 = puVar11 + -4;
              }
            }
          }
        }
      }
    }
    iVar8 = **(int **)(puVar11 + 0xf8);
    *(int *)(puVar11 + 100) = iVar8 + 8;
    *(undefined4 *)(puVar11 + -4) = 0;
    *(int *)(puVar11 + -8) = iVar8 + 8;
    *(undefined4 *)(puVar11 + -0xc) = 0x17;
    *(undefined4 *)(puVar11 + -0x10) = 5;
    *(code **)(puVar11 + 100) = DAT_001c10d8;
    *(undefined4 *)(puVar11 + -0x14) = 0x9b116;
    (*DAT_001c10d8)();
    *(undefined4 *)(puVar11 + -4) = 3;
    *(code **)(puVar11 + 100) = DAT_001c10e0;
    *(undefined4 *)(puVar11 + -8) = 0x9b12f;
    (*DAT_001c10e0)();
    iVar8 = **(int **)(puVar11 + 0xf8);
    *(int *)(puVar11 + 0x34) = iVar8;
    *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(iVar8 + 8);
    *(code **)(puVar11 + 100) = DAT_001c10f4;
    *(undefined4 *)(puVar11 + -0xc) = 0x9b15b;
    (*DAT_001c10f4)();
    iVar8 = **(int **)(puVar11 + 0xf8);
    *(int *)(puVar11 + 0x30) = iVar8;
    *(undefined4 *)(puVar11 + -0xc) = *(undefined4 *)(iVar8 + 0xc);
    *(code **)(puVar11 + 100) = DAT_001c10f4;
    *(undefined4 *)(puVar11 + -0x10) = 0x9b187;
    (*DAT_001c10f4)();
    iVar8 = **(int **)(puVar11 + 0xf8);
    *(int *)(puVar11 + 0x2c) = iVar8;
    *(undefined4 *)(puVar11 + -0x10) = *(undefined4 *)(iVar8 + 0x10);
    *(code **)(puVar11 + 100) = DAT_001c10f4;
    *(undefined4 *)(puVar11 + -0x14) = 0x9b1b3;
    (*DAT_001c10f4)();
    *(int *)(puVar11 + 100) = (int)g_sModelIndexFireball;
    *(int *)(puVar11 + -0x14) = (int)g_sModelIndexFireball;
    *(code **)(puVar11 + 100) = DAT_001c10e8;
    *(undefined4 *)(puVar11 + -0x18) = 0x9b1d7;
    (*DAT_001c10e8)();
    *(undefined4 *)(puVar11 + -0x18) = 0x32;
    *(code **)(puVar11 + 100) = DAT_001c10e0;
    *(undefined4 *)(puVar11 + -0x1c) = 0x9b1ed;
    (*DAT_001c10e0)();
    *(undefined4 *)(puVar11 + -0x1c) = 0xf;
    *(code **)(puVar11 + 100) = DAT_001c10e0;
    *(undefined4 *)(puVar11 + -0x20) = 0x9b206;
    (*DAT_001c10e0)();
    *(undefined4 *)(puVar11 + -0x20) = 3;
    *(code **)(puVar11 + 100) = DAT_001c10e0;
    *(undefined4 *)(puVar11 + -0x24) = 0x9b21f;
    (*DAT_001c10e0)();
    *(undefined4 *)(puVar11 + -4) = 0x9b230;
    (*DAT_001c10dc)();
  }
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*(int *)(puVar11 + 0xf8) + 0x108)) << 10) >> 8)
            | (byte)((ushort)((ushort)(*(float *)(*(int *)(puVar11 + 0xf8) + 0x108) == 1.0) << 0xe)
                    >> 8)) != 0x40) goto LAB_0009b3b5;
  iVar8 = *(int *)(**(int **)(puVar11 + 0xf8) + 400);
  if (iVar8 == 0) {
    *(undefined4 *)(puVar11 + -4) = 0;
    *(undefined4 *)(puVar11 + -8) = 0x9b37d;
    iVar8 = (*DAT_001c1134)();
    if (iVar8 != 0) goto LAB_0009b386;
    iVar8 = 0;
  }
  else {
LAB_0009b386:
    iVar8 = *(int *)(iVar8 + 0x7c);
  }
  *(byte *)(iVar8 + 0x86) = *(byte *)(iVar8 + 0x86) & 0xfe;
  *(int *)(puVar11 + -4) = iVar8;
  *(undefined4 *)(puVar11 + -8) = 0x9b39b;
  TeamFortress_SetSpeed__11CBasePlayer();
  *(undefined4 *)(puVar11 + -8) = 10;
  *(int *)(puVar11 + -0xc) = iVar8;
  *(undefined4 *)(puVar11 + -0x10) = 0x9b3a3;
  iVar8 = FindTimer__11CBaseEntityi();
  if (iVar8 != 0) {
    *(int *)(puVar11 + -4) = iVar8;
    *(undefined4 *)(puVar11 + -8) = 0x9b3b2;
    dremove__FP11CBaseEntity();
  }
LAB_0009b3b5:
  if (*(int *)(*(int *)(puVar11 + 0xf8) + 0x6b0) != 0) {
    uVar10 = *(undefined4 *)(*(int *)(puVar11 + 0xf8) + 0x6b0);
    *(undefined4 *)(puVar11 + 0x14) = uVar10;
    *(undefined4 *)(puVar11 + -4) = uVar10;
    *(undefined4 *)(puVar11 + -8) = 0x9b3d5;
    dremove__FP11CBaseEntity();
  }
  *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(puVar11 + 0xf8);
  *(undefined4 *)(puVar11 + -8) = 0x9b3e5;
  dremove__FP11CBaseEntity();
  return;
}


