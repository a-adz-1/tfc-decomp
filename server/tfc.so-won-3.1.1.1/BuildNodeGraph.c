// BuildNodeGraph__9CTestHull  @ 000c6bf4
void BuildNodeGraph__9CTestHull(int *param_1)

{
  float *pfVar1;
  byte *pbVar2;
  size_t __size;
  uint uVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  void *__ptr;
  FILE *__stream;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined2 in_FPUControlWord;
  int local_1150;
  int local_1138;
  int local_1134;
  int local_1130;
  int local_112c;
  int local_1114;
  int local_1110;
  float local_1108;
  float local_10fc;
  undefined4 local_10f8;
  float local_10f0;
  int local_10dc;
  undefined4 local_10bc;
  undefined4 local_10b8;
  float local_10b4;
  undefined4 local_10b0;
  float local_10ac;
  undefined4 local_10a8;
  float local_10a0;
  undefined4 local_1084;
  undefined2 local_107c;
  undefined2 uStack_107a;
  float local_1078;
  float local_1074;
  float local_1070;
  char local_103c [4152];
  
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  __ptr = calloc(0x18,DAT_0019fb38 << 7);
  if (__ptr == (void *)0x0) {
    puVar10 = &stack0xffffee0c;
  }
  else {
    (*DAT_0019f82c)();
    strcat(local_103c,"/maps");
    mkdir(local_103c,0x1ff);
    strcat(local_103c,"/graphs");
    mkdir(local_103c,0x1ff);
    strcat(local_103c,"/");
    strcat(local_103c,(char *)(gpGlobals[3] + gpGlobals[0x26]));
    strcat(local_103c,".nrp");
    __stream = fopen(local_103c,"w+");
    if (__stream == (FILE *)0x0) {
      (*DAT_0019f794)();
      free(__ptr);
      return;
    }
    fprintf(__stream,"Node Graph Report for map:  %s.bsp\n");
    fprintf(__stream,"%d Total Nodes\n\n");
    for (local_112c = 0; local_112c < DAT_0019fb38; local_112c = local_112c + 1) {
      iVar9 = local_112c * 0x58;
      *(undefined4 *)(DAT_0019fb2c + 0x20 + iVar9) = 0;
      *(undefined4 *)(DAT_0019fb2c + 0x24 + iVar9) = 0;
      memset((void *)(iVar9 + DAT_0019fb2c + 0x28),0,0x20);
      fprintf(__stream,"Node#         %4d\n");
      _local_107c = CONCAT22(uStack_107a,in_FPUControlWord);
      local_1084 = CONCAT22(uStack_107a,CONCAT11(0xc,(char)in_FPUControlWord));
      fprintf(__stream,(char *)FUN_0014eaa8,(int)ROUND(*(float *)(DAT_0019fb2c + iVar9)),
              (int)ROUND(*(float *)(DAT_0019fb2c + 4 + iVar9)),
              (int)ROUND(*(float *)(DAT_0019fb2c + 8 + iVar9)));
      fprintf(__stream,"HintType:     %4d\n");
      fprintf(__stream,"HintActivity: %4d\n");
      fprintf(__stream,"HintYaw:      %4f\n");
      fprintf(__stream,
              "-------------------------------------------------------------------------------\n");
    }
    fprintf(__stream,"\n\n");
    local_112c = 0;
    if (0 < DAT_0019fb38) {
      do {
        iVar9 = local_112c * 0x58;
        if ((*(byte *)(DAT_0019fb2c + 0x1c + iVar9) & 2) == 0) {
          iVar7 = UTIL_PointContents__FRC6Vector();
          if (iVar7 == -3) {
            pbVar2 = (byte *)(DAT_0019fb2c + 0x1c + iVar9);
            *pbVar2 = *pbVar2 | 4;
          }
          else {
            pbVar2 = (byte *)(DAT_0019fb2c + 0x1c + iVar9);
            *pbVar2 = *pbVar2 | 1;
            UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
            UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
            iVar9 = DAT_0019fb2c;
            if (((0x3f < (byte)((local_10ac < local_10fc |
                                 (byte)((ushort)((ushort)(NAN(local_10ac) || NAN(local_10fc)) << 10)
                                       >> 8) |
                                (byte)((ushort)((ushort)(local_10ac == local_10fc) << 0xe) >> 8)) -
                               1)) && (local_10dc != 0)) &&
               ((*(byte *)(local_10dc + 0x227) & 2) != 0)) {
              local_10a8 = local_10f8;
              local_10a0 = local_10f0;
            }
            *(float *)(DAT_0019fb2c + 8 + local_112c * 0x58) = local_10a0 + 8.0;
            *(float *)(iVar9 + 0x14 + local_112c * 0x58) = local_10a0 + 8.0;
          }
        }
        local_112c = local_112c + 1;
      } while (local_112c < DAT_0019fb38);
    }
    local_1138 = LinkVisibleNodes__6CGraphP5CLinkP8_IO_FILEPi();
    if (local_1138 == 0) {
      (*DAT_0019f794)();
      param_1[3] = -0x10000;
      param_1[4] = (int)ShowBadNode__9CTestHull;
      iVar7 = DAT_0019fb2c;
      iVar9 = *param_1;
      iVar8 = local_1110 * 0x58;
      *(undefined4 *)(iVar9 + 8) = *(undefined4 *)(DAT_0019fb2c + iVar8);
      *(undefined4 *)(iVar9 + 0xc) = *(undefined4 *)(iVar7 + 4 + iVar8);
      *(undefined4 *)(iVar9 + 0x10) = *(undefined4 *)(iVar7 + 8 + iVar8);
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
    for (local_112c = 0; local_112c < DAT_0019fb38; local_112c = local_112c + 1) {
      puVar12 = (undefined4 *)(DAT_0019fb2c + local_112c * 0x58);
      fprintf(__stream,
              "-------------------------------------------------------------------------------\n");
      fprintf(__stream,"Node %4d:\n\n");
      local_1130 = 0;
      if (0 < (int)puVar12[8]) {
        do {
          bVar6 = false;
          local_1134 = 0;
          *(undefined4 *)((int)__ptr + (local_1130 + puVar12[9]) * 0x18 + 0x10) = 0xf;
          do {
            if ((!bVar6) || (1 < local_1134 - 1U)) {
              switch(local_1134) {
              case 0:
                local_1108 = 12.0;
                local_10fc = -12.0;
                break;
              case 1:
                local_1108 = 16.0;
                local_10fc = -16.0;
                break;
              case 2:
                local_1108 = 32.0;
                local_10fc = -32.0;
                break;
              case 3:
                local_1108 = 32.0;
                local_10fc = -32.0;
                break;
              default:
                goto LAB_000c7566;
              }
              UTIL_SetSize__FP9entvars_sRC6VectorT1();
LAB_000c7566:
              UTIL_SetOrigin__FP9entvars_sRC6Vector();
              if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
                (*DAT_0019f794)();
              }
              if (local_1130 < 0) {
                (*DAT_0019f794)();
                goto LAB_000c7c7b;
              }
              pfVar1 = (float *)(DAT_0019fb2c +
                                *(int *)((int)__ptr + (local_1130 + puVar12[9]) * 0x18 + 4) * 0x58);
              local_1078 = *pfVar1;
              local_1074 = pfVar1[1];
              local_1070 = pfVar1[2];
              if (local_1134 < 3) {
                uVar3 = *(uint *)(*param_1 + 0x1a4);
                if ((*(byte *)(puVar12 + 7) & 4) != 0) {
                  *(uint *)(*param_1 + 0x1a4) = uVar3 | 2;
                }
                UTIL_VecToYaw__FRC6Vector();
                fVar4 = local_1078 - *(float *)(*param_1 + 8);
                local_1108 = local_1074 - *(float *)(*param_1 + 0xc);
                fVar4 = SQRT(local_1108 * local_1108 + fVar4 * fVar4);
                iVar9 = 0;
                if (0.0 < fVar4) {
                  do {
                    iVar7 = (*DAT_0019f70c)();
                    if (iVar7 == 0) goto LAB_000c789d;
                    iVar9 = iVar9 + 0x10;
                    fVar5 = (float)iVar9;
                  } while (0x3f < (byte)((fVar4 < fVar5 |
                                          (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar5)) << 10)
                                                >> 8) |
                                         (byte)((ushort)((ushort)(fVar4 == fVar5) << 0xe) >> 8)) - 1
                                        ));
                }
                iVar9 = *param_1;
                fVar4 = *(float *)(iVar9 + 8) - local_1078;
                local_1108 = *(float *)(iVar9 + 0xc) - local_1074;
                fVar5 = *(float *)(iVar9 + 0x10) - local_1070;
                if (64.0 < SQRT(fVar5 * fVar5 + local_1108 * local_1108 + fVar4 * fVar4)) {
LAB_000c789d:
                  if (local_1134 == 1) {
                    fprintf(__stream,"NODE_HUMAN_HULL step %f\n");
                    bVar6 = true;
                    pbVar2 = (byte *)((int)__ptr + (local_1130 + puVar12[9]) * 0x18 + 0x10);
                    *pbVar2 = *pbVar2 & 0xf9;
                  }
                  else if (local_1134 < 2) {
                    if (local_1134 == 0) {
                      fprintf(__stream,"NODE_SMALL_HULL step %f\n");
                      bVar6 = true;
                      pbVar2 = (byte *)((int)__ptr + (local_1130 + puVar12[9]) * 0x18 + 0x10);
                      *pbVar2 = *pbVar2 & 0xf8;
                    }
                  }
                  else if (local_1134 == 2) {
                    fprintf(__stream,"NODE_LARGE_HULL step %f\n");
                    pbVar2 = (byte *)((int)__ptr + (local_1130 + puVar12[9]) * 0x18 + 0x10);
                    *pbVar2 = *pbVar2 & 0xfb;
                  }
                }
                *(uint *)(*param_1 + 0x1a4) = uVar3;
              }
              else {
                local_10b0 = 0;
                local_10ac = 0.0;
                local_10a8 = 0x42000000;
                local_10b4 = (float)puVar12[2] + 32.0;
                local_10bc = *puVar12;
                local_10b8 = puVar12[1];
                UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult(&local_10bc);
                if ((local_1108 != 0.0) ||
                   (0x3f < (byte)((1.0 < local_10fc |
                                   (byte)((ushort)((ushort)NAN(local_10fc) << 10) >> 8) |
                                  (byte)((ushort)((ushort)(local_10fc == 1.0) << 0xe) >> 8)) - 1)))
                {
                  pbVar2 = (byte *)((int)__ptr + (local_1130 + puVar12[9]) * 0x18 + 0x10);
                  *pbVar2 = *pbVar2 & 0xf7;
                }
              }
            }
            local_1134 = local_1134 + 1;
          } while (local_1134 < 4);
          if (*(int *)((int)__ptr + (local_1130 + puVar12[9]) * 0x18 + 0x10) == 0) {
            fprintf(__stream,"Rejected Node %3d - Unreachable by ");
            puVar11 = (undefined4 *)((int)__ptr + (puVar12[9] + puVar12[8]) * 0x18 + -0x18);
            puVar13 = (undefined4 *)((int)__ptr + (puVar12[9] + local_1130) * 0x18);
            for (iVar9 = 6; iVar9 != 0; iVar9 = iVar9 + -1) {
              *puVar13 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar13 = puVar13 + 1;
            }
            fprintf(__stream,"Any Hull\n");
            puVar12[8] = puVar12[8] + -1;
            local_1138 = local_1138 + -1;
            local_1130 = local_1130 + -1;
          }
          local_1130 = local_1130 + 1;
        } while (local_1130 < (int)puVar12[8]);
      }
    }
    fprintf(__stream,
            "-------------------------------------------------------------------------------\n\n\n")
    ;
    iVar9 = RejectInlineLinks__6CGraphP5CLinkP8_IO_FILE();
    __size = local_1138 - iVar9;
    DAT_0019fb30 = calloc(0x18,__size);
    if (DAT_0019fb30 == (void *)0x0) {
      (*DAT_0019f794)();
LAB_000c7c7b:
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
      if (__stream == (FILE *)0x0) {
        return;
      }
      fclose(__stream);
      return;
    }
    local_1150 = 0;
    local_112c = 0;
    DAT_0019fb3c = __size;
    if (0 < DAT_0019fb38) {
      do {
        iVar9 = local_112c * 0x58;
        local_1130 = 0;
        iVar7 = *(int *)(DAT_0019fb2c + 0x24 + iVar9);
        *(int *)(DAT_0019fb2c + 0x24 + iVar9) = local_1150;
        if (0 < *(int *)(DAT_0019fb2c + 0x20 + iVar9)) {
          do {
            puVar12 = (undefined4 *)((int)__ptr + (iVar7 + local_1130) * 0x18);
            puVar11 = (undefined4 *)(local_1150 * 0x18 + (int)DAT_0019fb30);
            for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar11 = *puVar12;
              puVar12 = puVar12 + 1;
              puVar11 = puVar11 + 1;
            }
            local_1150 = local_1150 + 1;
            local_1130 = local_1130 + 1;
          } while (local_1130 < *(int *)(DAT_0019fb2c + 0x20 + iVar9));
        }
        local_112c = local_112c + 1;
      } while (local_112c < DAT_0019fb38);
    }
    SortNodes__6CGraph();
    BuildLinkLookups__6CGraph();
    bVar6 = true;
    fprintf(__stream,
            "\n\n-------------------------------------------------------------------------------\n")
    ;
    fprintf(__stream,"Link Pairings:\n");
    local_112c = 0;
    if (0 < DAT_0019fb38) {
      do {
        local_1130 = 0;
        if (0 < *(int *)(DAT_0019fb2c + 0x20 + local_112c * 0x58)) {
          do {
            HashSearch__6CGraphiiRi();
            if (local_1114 < 0) {
              bVar6 = false;
              fprintf(__stream,(char *)FUN_0014ed60);
            }
            local_1130 = local_1130 + 1;
          } while (local_1130 < *(int *)(DAT_0019fb2c + 0x20 + local_112c * 0x58));
        }
        local_112c = local_112c + 1;
      } while (local_112c < DAT_0019fb38);
    }
    if (bVar6) {
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
    (*DAT_0019f794)(2,"%d Nodes, %d Connections\n",DAT_0019fb38,__size);
    BuildRegionTables__6CGraph();
    local_112c = 0;
    if (0 < DAT_0019fb38) {
      do {
        iVar9 = local_112c * 0x58;
        if ((*(byte *)(DAT_0019fb2c + 0x1c + iVar9) & 1) != 0) {
          *(float *)(DAT_0019fb2c + 8 + iVar9) = *(float *)(DAT_0019fb2c + 8 + iVar9) - 8.0;
        }
        local_112c = local_112c + 1;
      } while (local_112c < DAT_0019fb38);
    }
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
    if (__stream != (FILE *)0x0) {
      fclose(__stream);
    }
    WorldGraph = 1;
    DAT_0019fb24 = 1;
    DAT_0019fb28 = 0;
    ComputeStaticRoutingTables__6CGraph();
    FSaveGraph__6CGraphPc();
    puVar10 = &stack0xffffee00;
  }
  *(undefined4 *)(puVar10 + -4) = 0xc8167;
  (*DAT_0019f794)();
  return;
}


