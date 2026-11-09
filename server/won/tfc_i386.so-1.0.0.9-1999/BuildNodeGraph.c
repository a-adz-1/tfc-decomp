// BuildNodeGraph__9CTestHull  @ 000cc090
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BuildNodeGraph__9CTestHull(int *param_1)

{
  float *pfVar1;
  float *pfVar2;
  byte *pbVar3;
  size_t __size;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  void *__ptr;
  FILE *__stream;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined2 in_FPUControlWord;
  int local_594;
  int iStack_55c;
  int iStack_530;
  int iStack_52c;
  int local_528;
  int iStack_514;
  int iStack_510;
  float fStack_508;
  float fStack_4fc;
  undefined4 uStack_4f8;
  float fStack_4f0;
  int iStack_4dc;
  float fStack_4bc;
  float fStack_4b8;
  float fStack_4b4;
  undefined4 uStack_4b0;
  float fStack_4ac;
  undefined4 uStack_4a8;
  float fStack_4a0;
  undefined4 local_484;
  undefined2 local_47c;
  undefined2 uStack_47a;
  float fStack_478;
  float fStack_474;
  float fStack_470;
  char local_43c [1080];
  
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
  __ptr = calloc(0x18,DAT_001758d8 << 7);
  if (__ptr == (void *)0x0) {
    puVar11 = &stack0xfffffa54;
  }
  else {
    (*DAT_0017564c)();
    strcat(local_43c,"/maps");
    mkdir(local_43c,0x1ff);
    strcat(local_43c,"/graphs");
    mkdir(local_43c,0x1ff);
    strcat(local_43c,"/");
    strcat(local_43c,(char *)(gpGlobals[3] + gpGlobals[0x26]));
    strcat(local_43c,".nrp");
    __stream = fopen(local_43c,"w+");
    if (__stream == (FILE *)0x0) {
      (*DAT_001755b4)();
      if (__ptr == (void *)0x0) {
        return;
      }
      free(__ptr);
      return;
    }
    fprintf(__stream,"Node Graph Report for map:  %s.bsp\n");
    fprintf(__stream,"%d Total Nodes\n\n");
    local_528 = 0;
    if (0 < DAT_001758d8) {
      do {
        iVar8 = local_528 * 0x58;
        *(undefined4 *)(DAT_001758cc + 0x20 + iVar8) = 0;
        *(undefined4 *)(DAT_001758cc + 0x24 + iVar8) = 0;
        memset((void *)(iVar8 + DAT_001758cc + 0x28),0,0x20);
        fprintf(__stream,"Node#         %4d\n");
        _local_47c = CONCAT22(uStack_47a,in_FPUControlWord);
        local_484 = CONCAT22(uStack_47a,CONCAT11(0xc,(char)in_FPUControlWord));
        fprintf(__stream,"Location      %4d,%4d,%4d\n",(int)ROUND(*(float *)(DAT_001758cc + iVar8)),
                (int)ROUND(*(float *)(DAT_001758cc + 4 + iVar8)),
                (int)ROUND(*(float *)(DAT_001758cc + 8 + iVar8)));
        fprintf(__stream,"HintType:     %4d\n");
        fprintf(__stream,"HintActivity: %4d\n");
        fprintf(__stream,"HintYaw:      %4f\n");
        fprintf(__stream,
                "-------------------------------------------------------------------------------\n")
        ;
        local_528 = local_528 + 1;
      } while (local_528 < DAT_001758d8);
    }
    fprintf(__stream,"\n\n");
    local_528 = 0;
    if (0 < DAT_001758d8) {
      do {
        if ((*(byte *)(DAT_001758cc + 0x1c + local_528 * 0x58) & 2) == 0) {
          iVar8 = UTIL_PointContents__FRC6Vector();
          if (iVar8 == -3) {
            pbVar3 = (byte *)(DAT_001758cc + 0x1c + local_528 * 0x58);
            *pbVar3 = *pbVar3 | 4;
          }
          else {
            pbVar3 = (byte *)(DAT_001758cc + 0x1c + local_528 * 0x58);
            *pbVar3 = *pbVar3 | 1;
            UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
            UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
            iVar8 = DAT_001758cc;
            if ((((byte)(fStack_4fc < fStack_4ac |
                         (byte)((ushort)((ushort)(NAN(fStack_4fc) || NAN(fStack_4ac)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fStack_4fc == fStack_4ac) << 0xe) >> 8)) == 1) &&
                (iStack_4dc != 0)) && ((*(byte *)(iStack_4dc + 0x263) & 2) != 0)) {
              uStack_4a8 = uStack_4f8;
              fStack_4a0 = fStack_4f0;
            }
            *(float *)(DAT_001758cc + 8 + local_528 * 0x58) = fStack_4a0 + 8.0;
            *(float *)(iVar8 + 0x14 + local_528 * 0x58) = fStack_4a0 + 8.0;
          }
        }
        local_528 = local_528 + 1;
      } while (local_528 < DAT_001758d8);
    }
    iStack_530 = LinkVisibleNodes__6CGraphP5CLinkP8_IO_FILEPi();
    if (iStack_530 == 0) {
      (*DAT_001755b4)();
      param_1[3] = -0x10000;
      param_1[4] = (int)ShowBadNode__9CTestHull;
      iVar10 = DAT_001758cc;
      iVar8 = *param_1;
      iVar9 = iStack_510 * 0x58;
      *(undefined4 *)(iVar8 + 8) = *(undefined4 *)(DAT_001758cc + iVar9);
      *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)(iVar10 + 4 + iVar9);
      *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(iVar10 + 8 + iVar9);
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
      if (__stream == (FILE *)0x0) {
        return;
      }
      fclose(__stream);
      return;
    }
    fprintf(__stream,
            "----------------------------------------------------------------------------\n");
    fprintf(__stream,"Walk Rejection:\n");
    local_528 = 0;
    if (0 < DAT_001758d8) {
      do {
        pfVar1 = (float *)(DAT_001758cc + local_528 * 0x58);
        fprintf(__stream,
                "-------------------------------------------------------------------------------\n")
        ;
        fprintf(__stream,"Node %4d:\n\n");
        iStack_52c = 0;
        if (0 < (int)pfVar1[8]) {
          do {
            *(undefined4 *)((int)__ptr + (iStack_52c + (int)pfVar1[9]) * 0x18 + 0x10) = 0xf;
            bVar7 = false;
            iVar8 = 0;
            do {
              if ((!bVar7) || (1 < iVar8 - 1U)) {
                if (iVar8 == 1) {
                  fStack_508 = 16.0;
                  fStack_4fc = -16.0;
LAB_000cc898:
                  UTIL_SetSize__FP9entvars_tRC6VectorT1();
                }
                else if (iVar8 < 2) {
                  if (iVar8 == 0) {
                    fStack_508 = 12.0;
                    fStack_4fc = -12.0;
                    goto LAB_000cc898;
                  }
                }
                else if ((iVar8 == 2) || (iVar8 == 3)) {
                  fStack_508 = 32.0;
                  fStack_4fc = _FUN_00137430;
                  goto LAB_000cc898;
                }
                UTIL_SetOrigin__FP9entvars_tRC6Vector();
                if ((*(byte *)(*param_1 + 0x185) & 2) == 0) {
                  (*DAT_001755b4)();
                }
                if (iStack_52c < 0) {
                  (*DAT_001755b4)();
                  goto LAB_000ccef2;
                }
                pfVar2 = (float *)(DAT_001758cc +
                                  *(int *)((int)__ptr + (iStack_52c + (int)pfVar1[9]) * 0x18 + 4) *
                                  0x58);
                fStack_478 = *pfVar2;
                fStack_474 = pfVar2[1];
                fStack_470 = pfVar2[2];
                if (iVar8 < 3) {
                  uVar4 = *(undefined4 *)(*param_1 + 0x184);
                  if (((uint)pfVar1[7] & 4) != 0) {
                    pbVar3 = (byte *)(*param_1 + 0x184);
                    *pbVar3 = *pbVar3 | 2;
                  }
                  UTIL_VecToYaw__FRC6Vector();
                  fVar5 = fStack_478 - *(float *)(*param_1 + 8);
                  fStack_508 = fStack_474 - *(float *)(*param_1 + 0xc);
                  fVar5 = SQRT(fStack_508 * fStack_508 + fVar5 * fVar5);
                  local_594 = 0;
                  if ((byte)(0.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) == 1) {
                    do {
                      iVar10 = (*DAT_0017552c)();
                      if (iVar10 == 0) goto LAB_000ccb80;
                      local_594 = local_594 + 0x10;
                    } while ((float)local_594 < fVar5);
                  }
                  iVar10 = *param_1;
                  fVar5 = *(float *)(iVar10 + 8) - fStack_478;
                  fStack_508 = *(float *)(iVar10 + 0xc) - fStack_474;
                  fVar6 = *(float *)(iVar10 + 0x10) - fStack_470;
                  fVar5 = SQRT(fVar6 * fVar6 + fStack_508 * fStack_508 + fVar5 * fVar5);
                  if ((byte)(64.0 < fVar5 | (byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar5 == 64.0) << 0xe) >> 8)) == 1) {
LAB_000ccb80:
                    if (iVar8 == 1) {
                      fprintf(__stream,"NODE_HUMAN_HULL step %f\n");
                      pbVar3 = (byte *)((int)__ptr + (iStack_52c + (int)pfVar1[9]) * 0x18 + 0x10);
                      *pbVar3 = *pbVar3 & 0xf9;
                      bVar7 = true;
                    }
                    else if (iVar8 < 2) {
                      if (iVar8 == 0) {
                        fprintf(__stream,"NODE_SMALL_HULL step %f\n");
                        pbVar3 = (byte *)((int)__ptr + (iStack_52c + (int)pfVar1[9]) * 0x18 + 0x10);
                        *pbVar3 = *pbVar3 & 0xf8;
                        bVar7 = true;
                      }
                    }
                    else if (iVar8 == 2) {
                      fprintf(__stream,"NODE_LARGE_HULL step %f\n");
                      pbVar3 = (byte *)((int)__ptr + (iStack_52c + (int)pfVar1[9]) * 0x18 + 0x10);
                      *pbVar3 = *pbVar3 & 0xfb;
                    }
                  }
                  *(undefined4 *)(*param_1 + 0x184) = uVar4;
                }
                else {
                  uStack_4b0 = 0;
                  fStack_4ac = 0.0;
                  uStack_4a8 = 0x42000000;
                  fStack_4bc = *pfVar1 + 0.0;
                  fStack_4b8 = pfVar1[1] + 0.0;
                  fStack_4b4 = pfVar1[2] + 32.0;
                  UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult(&fStack_4bc)
                  ;
                  if ((fStack_508 != 0.0) || (fStack_4fc < 1.0)) {
                    pbVar3 = (byte *)((int)__ptr + (iStack_52c + (int)pfVar1[9]) * 0x18 + 0x10);
                    *pbVar3 = *pbVar3 & 0xf7;
                  }
                }
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < 4);
            if (*(int *)((int)__ptr + (iStack_52c + (int)pfVar1[9]) * 0x18 + 0x10) == 0) {
              fprintf(__stream,"Rejected Node %3d - Unreachable by ");
              puVar12 = (undefined4 *)
                        ((int)__ptr + ((int)pfVar1[9] + (int)pfVar1[8]) * 0x18 + -0x18);
              puVar13 = (undefined4 *)((int)__ptr + (iStack_52c + (int)pfVar1[9]) * 0x18);
              for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
                *puVar13 = *puVar12;
                puVar12 = puVar12 + 1;
                puVar13 = puVar13 + 1;
              }
              fprintf(__stream,"Any Hull\n");
              pfVar1[8] = (float)((int)pfVar1[8] + -1);
              iStack_530 = iStack_530 + -1;
              iStack_52c = iStack_52c + -1;
            }
            iStack_52c = iStack_52c + 1;
          } while (iStack_52c < (int)pfVar1[8]);
        }
        local_528 = local_528 + 1;
      } while (local_528 < DAT_001758d8);
    }
    fprintf(__stream,
            "-------------------------------------------------------------------------------\n\n\n")
    ;
    iVar8 = RejectInlineLinks__6CGraphP5CLinkP8_IO_FILE();
    __size = iStack_530 - iVar8;
    DAT_001758d0 = calloc(0x18,__size);
    if (DAT_001758d0 == (void *)0x0) {
      (*DAT_001755b4)();
LAB_000ccef2:
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
      if (__stream == (FILE *)0x0) {
        return;
      }
      fclose(__stream);
      return;
    }
    iStack_55c = 0;
    DAT_001758dc = __size;
    for (local_528 = 0; local_528 < DAT_001758d8; local_528 = local_528 + 1) {
      iVar10 = local_528 * 0x58;
      iVar8 = *(int *)(DAT_001758cc + 0x24 + iVar10);
      *(int *)(DAT_001758cc + 0x24 + iVar10) = iStack_55c;
      iStack_52c = 0;
      if (0 < *(int *)(DAT_001758cc + 0x20 + iVar10)) {
        do {
          puVar12 = (undefined4 *)((int)__ptr + (iVar8 + iStack_52c) * 0x18);
          puVar13 = (undefined4 *)(iStack_55c * 0x18 + (int)DAT_001758d0);
          for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar13 = *puVar12;
            puVar12 = puVar12 + 1;
            puVar13 = puVar13 + 1;
          }
          iStack_55c = iStack_55c + 1;
          iStack_52c = iStack_52c + 1;
        } while (iStack_52c < *(int *)(DAT_001758cc + 0x20 + local_528 * 0x58));
      }
    }
    SortNodes__6CGraph();
    BuildLinkLookups__6CGraph();
    bVar7 = true;
    fprintf(__stream,
            "\n\n-------------------------------------------------------------------------------\n")
    ;
    fprintf(__stream,"Link Pairings:\n");
    for (local_528 = 0; local_528 < DAT_001758d8; local_528 = local_528 + 1) {
      iStack_52c = 0;
      if (0 < *(int *)(DAT_001758cc + 0x20 + local_528 * 0x58)) {
        do {
          HashSearch__6CGraphiiRi();
          if (iStack_514 < 0) {
            bVar7 = false;
            fprintf(__stream,"WARNING: Node %3d does not connect back to Node %3d\n");
          }
          iStack_52c = iStack_52c + 1;
        } while (iStack_52c < *(int *)(DAT_001758cc + 0x20 + local_528 * 0x58));
      }
    }
    if (bVar7) {
      fprintf(__stream,"\nAll Connections are Paired!\n");
    }
    fprintf(__stream,
            "-------------------------------------------------------------------------------\n");
    fprintf(__stream,
            "\n\n-------------------------------------------------------------------------------\n")
    ;
    fprintf(__stream,"Total Number of Connections in Pool: %d\n");
    fprintf(__stream,
            "-------------------------------------------------------------------------------\n");
    fprintf(__stream,"Connection Pool: %d bytes\n");
    fprintf(__stream,
            "-------------------------------------------------------------------------------\n");
    (*DAT_001755b4)(2,"%d Nodes, %d Connections\n",DAT_001758d8,__size);
    BuildRegionTables__6CGraph();
    local_528 = 0;
    if (0 < DAT_001758d8) {
      do {
        iVar8 = local_528 * 0x58;
        if ((*(byte *)(DAT_001758cc + 0x1c + iVar8) & 1) != 0) {
          *(float *)(DAT_001758cc + 8 + iVar8) = *(float *)(DAT_001758cc + 8 + iVar8) - 8.0;
        }
        local_528 = local_528 + 1;
      } while (local_528 < DAT_001758d8);
    }
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
    if (__stream != (FILE *)0x0) {
      fclose(__stream);
    }
    WorldGraph = 1;
    DAT_001758c4 = 1;
    _DAT_001758c8 = 0;
    ComputeStaticRoutingTables__6CGraph();
    FSaveGraph__6CGraphPc();
    puVar11 = &stack0xfffffa48;
  }
  *(undefined4 *)(puVar11 + -4) = 0xcd34b;
  (*DAT_001755b4)();
  return;
}


