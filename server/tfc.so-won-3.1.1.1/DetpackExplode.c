// DetpackExplode__8CDetpack  @ 0009a14c
void DetpackExplode__8CDetpack(int *param_1)

{
  float fVar1;
  code *pcVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  undefined1 *puVar6;
  int iVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  int *piVar11;
  undefined4 auStackY_108 [2];
  int *local_90;
  float local_60;
  float local_5c;
  float local_58;
  undefined1 local_54 [16];
  float local_44;
  int local_24;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  puVar10 = &stack0xffffff1c;
  iVar7 = *(int *)(*param_1 + 0x198);
  if ((iVar7 == 0) && (iVar7 = (*DAT_0019f7b4)(0), iVar7 == 0)) {
    local_90 = (int *)0x0;
    iVar7 = *param_1;
  }
  else {
    local_90 = *(int **)(iVar7 + 0x7c);
    iVar7 = *param_1;
  }
  iVar7 = UTIL_PointContents__FRC6Vector(iVar7 + 8);
  if (((iVar7 == -2) || (iVar7 == -6)) || (local_90[0x1e] == 1)) {
    ClientPrint__FP9entvars_siPCcN42(*local_90,1,"#Detpack_fizzle",0,0,0,0);
    if (local_90[0x48] == 0) {
      pcVar8 = "SPECTATOR";
    }
    else {
      pcVar8 = (char *)GetTeamName__Fi(local_90[0x48]);
    }
    uVar9 = (*DAT_0019f8dc)(*(undefined4 *)(*local_90 + 0x208),pcVar8);
    uVar9 = (*DAT_0019f864)(*(undefined4 *)(*local_90 + 0x208),uVar9);
    UTIL_LogPrintf__FPce
              ("\"<-1><><>\" triggered \"Detpack_Fizzle\" against \"%s<%i><%s><%s>\"\n",
               *(int *)(*local_90 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar9);
  }
  else {
    UTIL_ClientPrintAll__FiPCcN41(1,"#FITH",0,0,0,0);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),1,"weapons/mortarhit.wav",0x3f800000,0x3f4ccccd,0,
               100);
    if (birthday != 0) {
      UTIL_ClientPrintAll__FiPCcN41
                (1,"#SpreadsCheer",*(int *)(*local_90 + 0x1d0) + *(int *)(gpGlobals + 0x98),0,0,0);
    }
    if (local_90[0x48] == 0) {
      pcVar8 = "SPECTATOR";
    }
    else {
      pcVar8 = (char *)GetTeamName__Fi(local_90[0x48]);
    }
    uVar9 = (*DAT_0019f8dc)(*(undefined4 *)(*local_90 + 0x208),pcVar8);
    uVar9 = (*DAT_0019f864)(*(undefined4 *)(*local_90 + 0x208),uVar9);
    UTIL_LogPrintf__FPce
              ("\"%s<%i><%s><%s>\" triggered \"Detpack_Explode\"\n",
               *(int *)(*local_90 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar9);
    local_14 = 16.0;
    local_1c = 0.0;
    local_18 = 0.0;
    iVar7 = *param_1;
    local_8 = *(float *)(iVar7 + 0x10) + 16.0;
    piVar11 = (int *)0x0;
    local_10 = *(undefined4 *)(iVar7 + 8);
    local_c = *(undefined4 *)(iVar7 + 0xc);
    puVar6 = &stack0xffffff1c;
    while( true ) {
      puVar10 = puVar6;
      *(undefined4 *)(puVar10 + -4) = 0x44bb8000;
      *(undefined4 **)(puVar10 + -8) = &local_10;
      *(int **)(puVar10 + -0xc) = piVar11;
      *(undefined4 *)(puVar10 + -0x10) = 0x9a5d3;
      piVar11 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
      if (piVar11 == (int *)0x0) break;
      iVar7 = piVar11[0x115];
      *(int **)(puVar10 + -4) = piVar11;
      *(float **)(puVar10 + -8) = &local_60;
      pcVar2 = *(code **)(iVar7 + 0xcc);
      *(undefined4 *)(puVar10 + -0xc) = 0x9a353;
      (*pcVar2)();
      iVar7 = *piVar11;
      local_1c = local_60 + *(float *)(iVar7 + 0x174);
      local_18 = local_5c + *(float *)(iVar7 + 0x178);
      local_14 = local_58 + *(float *)(iVar7 + 0x17c);
      *(undefined1 **)(puVar10 + -8) = local_54;
      *(undefined4 *)(puVar10 + -0xc) = *(undefined4 *)(*param_1 + 0x208);
      *(undefined4 *)(puVar10 + -0x10) = 0;
      *(float **)(puVar10 + -0x14) = &local_1c;
      *(undefined4 **)(puVar10 + -0x18) = &local_10;
      *(undefined4 *)(puVar10 + -0x1c) = 0x9a3a0;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
      if (((byte)((1.0 < local_44 | (byte)((ushort)((ushort)NAN(local_44) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_44 == 1.0) << 0xe) >> 8)) - 1) < 0x40) ||
         (puVar6 = puVar10 + -4, local_24 == *(int *)(*piVar11 + 0x208))) {
        iVar7 = *(int *)*piVar11;
        iVar3 = *(int *)(gpGlobals + 0x98);
        *(char **)(puVar10 + -8) = "info_tfgoal";
        *(int *)(puVar10 + -0xc) = iVar7 + iVar3;
        *(undefined4 *)(puVar10 + -0x10) = 0x9a3e4;
        iVar7 = strcmp(*(char **)(puVar10 + -0xc),*(char **)(puVar10 + -8));
        if (iVar7 == 0) {
          puVar6 = puVar10 + -4;
          if (((*(byte *)(piVar11 + 0x8a) & 2) != 0) &&
             (puVar6 = puVar10 + -4,
             (byte)((byte)((ushort)((ushort)NAN((float)piVar11[0x95]) << 10) >> 8) |
                   (byte)((ushort)((ushort)((float)piVar11[0x95] == 0.0) << 0xe) >> 8)) == 0x40)) {
            *(int **)(puVar10 + -8) = piVar11;
            *(int **)(puVar10 + -0xc) = local_90;
            *(int **)(puVar10 + -0x10) = piVar11;
            *(undefined4 *)(puVar10 + -0x14) = 0x9a41e;
            ActivateDoResults__FP11CBaseEntityP11CBasePlayerT0();
            puVar6 = puVar10 + -4;
          }
        }
        else {
          iVar7 = *piVar11;
          fVar1 = *(float *)(iVar7 + 0x16c);
          puVar6 = puVar10 + -4;
          if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
            iVar3 = *param_1;
            local_60 = *(float *)(iVar7 + 8) - *(float *)(iVar3 + 8);
            local_5c = *(float *)(iVar7 + 0xc) - *(float *)(iVar3 + 0xc);
            local_58 = *(float *)(iVar7 + 0x10) - *(float *)(iVar3 + 0x10);
            fVar1 = SQRT(local_58 * local_58 + local_5c * local_5c + local_60 * local_60);
            puVar6 = puVar10 + -4;
            if ((byte)(700.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == 700.0) << 0xe) >> 8)) != 1) {
              fVar1 = *(float *)(iVar3 + 8) -
                      ((*(float *)(*piVar11 + 0xdc) + *(float *)(*piVar11 + 0xe8)) * 0.5 +
                      *(float *)(*piVar11 + 8));
              fVar5 = *(float *)(iVar3 + 0xc) -
                      ((*(float *)(*piVar11 + 0xe0) + *(float *)(*piVar11 + 0xec)) * 0.5 +
                      *(float *)(*piVar11 + 0xc));
              fVar4 = *(float *)(iVar3 + 0x10) -
                      ((*(float *)(*piVar11 + 0xe4) + *(float *)(*piVar11 + 0xf0)) * 0.5 +
                      *(float *)(*piVar11 + 0x10));
              fVar1 = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar1 * fVar1) * 0.5;
              if (fVar1 < 0.0) {
                fVar1 = 0.0;
              }
              fVar1 = 700.0 - fVar1;
              puVar6 = puVar10 + -4;
              if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
                iVar7 = piVar11[0x115];
                *(undefined4 *)(puVar10 + -8) = 0x40;
                *(float *)(puVar10 + -0xc) = fVar1 + fVar1;
                *(int *)(puVar10 + -0x10) = *local_90;
                *(int *)(puVar10 + -0x14) = iVar3;
                *(int **)(puVar10 + -0x18) = piVar11;
                pcVar2 = *(code **)(iVar7 + 0x38);
                *(undefined4 *)(puVar10 + -0x1c) = 0x9a5b8;
                (*pcVar2)();
                puVar6 = puVar10 + -4;
              }
            }
          }
        }
      }
    }
    iVar7 = *param_1;
    *(undefined4 *)(puVar10 + -4) = 0;
    *(int *)(puVar10 + -8) = iVar7 + 8;
    *(undefined4 *)(puVar10 + -0xc) = 0x17;
    *(undefined4 *)(puVar10 + -0x10) = 5;
    *(undefined4 *)(puVar10 + -0x14) = 0x9a5fd;
    (*DAT_0019f758)();
    *(undefined4 *)(puVar10 + -4) = 3;
    *(undefined4 *)(puVar10 + -8) = 0x9a610;
    (*DAT_0019f760)();
    *(undefined4 *)(puVar10 + -8) = *(undefined4 *)(*param_1 + 8);
    *(code **)(puVar10 + -0xc) = FUN_0009a62c;
    (*DAT_0019f774)();
    *(undefined4 *)(puVar10 + -0xc) = *(undefined4 *)(*param_1 + 0xc);
    *(undefined4 *)(puVar10 + -0x10) = 0x9a648;
    (*DAT_0019f774)();
    *(undefined4 *)(puVar10 + -0x10) = *(undefined4 *)(*param_1 + 0x10);
    *(undefined4 *)(puVar10 + -0x14) = 0x9a664;
    (*DAT_0019f774)();
    *(int *)(puVar10 + -0x14) = (int)g_sModelIndexFireball;
    *(undefined4 *)(puVar10 + -0x18) = 0x9a67c;
    (*DAT_0019f768)();
    *(undefined4 *)(puVar10 + -0x18) = 0x32;
    *(undefined4 *)(puVar10 + -0x1c) = 0x9a68c;
    (*DAT_0019f760)();
    *(undefined4 *)(puVar10 + -0x1c) = 0xf;
    *(undefined4 *)(puVar10 + -0x20) = 0x9a69c;
    (*DAT_0019f760)();
    *(undefined4 *)(puVar10 + -0x20) = 3;
    *(undefined4 *)(puVar10 + -0x24) = 0x9a6ac;
    (*DAT_0019f760)();
    *(undefined4 *)(puVar10 + -4) = 0x9a6bd;
    (*DAT_0019f75c)();
  }
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x42]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x42] == 1.0) << 0xe) >> 8)) != 0x40)
  goto LAB_0009a7ed;
  iVar7 = *(int *)(*param_1 + 400);
  if (iVar7 == 0) {
    *(undefined4 *)(puVar10 + -4) = 0;
    *(undefined4 *)(puVar10 + -8) = 0x9a7b5;
    iVar7 = (*DAT_0019f7b4)();
    if (iVar7 != 0) goto LAB_0009a7be;
    iVar7 = 0;
  }
  else {
LAB_0009a7be:
    iVar7 = *(int *)(iVar7 + 0x7c);
  }
  *(byte *)(iVar7 + 0x86) = *(byte *)(iVar7 + 0x86) & 0xfe;
  *(int *)(puVar10 + -4) = iVar7;
  *(undefined4 *)(puVar10 + -8) = 0x9a7d3;
  TeamFortress_SetSpeed__11CBasePlayer();
  *(undefined4 *)(puVar10 + -8) = 10;
  *(int *)(puVar10 + -0xc) = iVar7;
  *(undefined4 *)(puVar10 + -0x10) = 0x9a7db;
  iVar7 = FindTimer__11CBaseEntityi();
  if (iVar7 != 0) {
    *(int *)(puVar10 + -4) = iVar7;
    *(undefined4 *)(puVar10 + -8) = 0x9a7ea;
    dremove__FP11CBaseEntity();
  }
LAB_0009a7ed:
  if (param_1[0x1b0] != 0) {
    *(int *)(puVar10 + -4) = param_1[0x1b0];
    *(undefined4 *)(puVar10 + -8) = 0x9a800;
    dremove__FP11CBaseEntity();
  }
  *(int **)(puVar10 + -4) = param_1;
  *(undefined4 *)(puVar10 + -8) = 0x9a80c;
  dremove__FP11CBaseEntity();
  return;
}


