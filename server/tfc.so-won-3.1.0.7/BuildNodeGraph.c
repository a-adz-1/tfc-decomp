// BuildNodeGraph__9CTestHull  @ 000c6d10
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BuildNodeGraph__9CTestHull(int *param_1)

{
  byte *pbVar1;
  size_t __size;
  float fVar2;
  undefined4 uVar3;
  float fVar4;
  bool bVar5;
  void *__ptr;
  FILE *__stream;
  int iVar6;
  float *pfVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  bool bVar13;
  undefined2 in_FPUControlWord;
  longdouble lVar14;
  int local_1168;
  int local_115c;
  int iStack_1158;
  int iStack_114c;
  int local_112c;
  int local_1128;
  int local_1124;
  int iStack_1110;
  int local_110c;
  float local_1108;
  float local_1104;
  float local_1100;
  float local_10fc;
  float local_10f8;
  undefined4 local_10f4;
  undefined4 local_10f0;
  float local_10ec;
  int local_10d8;
  float local_10d0;
  float local_10cc;
  float local_10c8;
  undefined4 local_10c4;
  undefined4 local_10c0;
  float local_10bc;
  undefined4 local_10b8;
  undefined4 uStack_10b4;
  float fStack_10b0;
  undefined4 uStack_10ac;
  float local_10a8;
  undefined4 local_10a4;
  undefined4 local_10a0;
  float local_109c;
  undefined4 local_1080;
  undefined4 local_1078;
  float fStack_1074;
  float fStack_1070;
  float fStack_106c;
  char local_1038 [4152];
  
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  __ptr = calloc(0x18,DAT_001c1498 << 7);
  if (__ptr == (void *)0x0) {
    (*DAT_001c1114)(2,"**Could not malloc TempPool!\n");
  }
  else {
    (*DAT_001c11ac)(local_1038);
    strcat(local_1038,"/maps");
    mkdir(local_1038,0x1ff);
    strcat(local_1038,"/graphs");
    mkdir(local_1038,0x1ff);
    strcat(local_1038,"/");
    strcat(local_1038,(char *)(gpGlobals[3] + gpGlobals[0x26]));
    strcat(local_1038,".nrp");
    __stream = fopen(local_1038,"w+");
    if (__stream == (FILE *)0x0) {
      (*DAT_001c1114)(2,"Couldn\'t create %s!\n",local_1038);
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
    }
    else {
      fprintf(__stream,"Node Graph Report for map:  %s.bsp\n",gpGlobals[3] + gpGlobals[0x26]);
      fprintf(__stream,"%d Total Nodes\n\n",DAT_001c1498);
      local_1124 = 0;
      if (0 < DAT_001c1498) {
        iVar11 = 0;
        do {
          *(undefined4 *)(DAT_001c148c + 0x20 + iVar11) = 0;
          *(undefined4 *)(DAT_001c148c + 0x24 + iVar11) = 0;
          memset((void *)(DAT_001c148c + iVar11 + 0x28),0,0x20);
          fprintf(__stream,"Node#         %4d\n",local_1124);
          local_1078 = CONCAT22(local_1078._2_2_,in_FPUControlWord);
          local_1080 = CONCAT22(local_1078._2_2_,CONCAT11(0xc,(char)in_FPUControlWord));
          fprintf(__stream,"Location      %4d,%4d,%4d\n",
                  (int)ROUND(*(float *)(DAT_001c148c + iVar11)),
                  (int)ROUND(*(float *)(DAT_001c148c + 4 + iVar11)),
                  (int)ROUND(*(float *)(DAT_001c148c + 8 + iVar11)));
          fprintf(__stream,"HintType:     %4d\n",(int)*(short *)(DAT_001c148c + 0x50 + iVar11));
          fprintf(__stream,"HintActivity: %4d\n",(int)*(short *)(DAT_001c148c + 0x52 + iVar11));
          fprintf(__stream,"HintYaw:      %4f\n");
          fprintf(__stream,
                  "-------------------------------------------------------------------------------\n"
                 );
          iVar11 = iVar11 + 0x58;
          local_1124 = local_1124 + 1;
        } while (local_1124 < DAT_001c1498);
      }
      fprintf(__stream,"\n\n");
      local_1124 = 0;
      if (0 < DAT_001c1498) {
        iVar11 = 0;
        do {
          if ((*(byte *)(DAT_001c148c + 0x1c + iVar11) & 2) == 0) {
            iVar6 = UTIL_PointContents__FRC6Vector(DAT_001c148c + iVar11);
            if (iVar6 == -3) {
              pbVar1 = (byte *)(DAT_001c148c + 0x1c + iVar11);
              *pbVar1 = *pbVar1 | 4;
            }
            else {
              pbVar1 = (byte *)(DAT_001c148c + 0x1c + iVar11);
              *pbVar1 = *pbVar1 | 1;
              local_10d0 = 0.0;
              local_10cc = 0.0;
              local_10c8 = 384.0;
              puVar9 = (undefined4 *)(DAT_001c148c + iVar11);
              local_10c4 = *puVar9;
              local_10c0 = puVar9[1];
              local_10bc = (float)puVar9[2] - 384.0;
              UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                        (DAT_001c148c + iVar11,&local_10c4,1,g_pBodyQueueHead,&local_10b8);
              local_10c4 = 0;
              local_10c0 = 0;
              local_10bc = 384.0;
              pfVar7 = (float *)(DAT_001c148c + iVar11);
              local_10d0 = *pfVar7;
              local_10cc = pfVar7[1];
              local_10c8 = pfVar7[2] - 384.0;
              UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                        (DAT_001c148c + iVar11,&local_10d0,0,g_pBodyQueueHead,&local_1108);
              iVar6 = DAT_001c148c;
              if (((local_10f8 < local_10a8) && (local_10d8 != 0)) &&
                 ((*(byte *)(local_10d8 + 0x227) & 2) != 0)) {
                local_10a4 = local_10f4;
                local_10a0 = local_10f0;
                local_109c = local_10ec;
              }
              *(float *)(DAT_001c148c + 8 + iVar11) = local_109c + 8.0;
              *(float *)(iVar6 + 0x14 + iVar11) = local_109c + 8.0;
            }
          }
          iVar11 = iVar11 + 0x58;
          local_1124 = local_1124 + 1;
        } while (local_1124 < DAT_001c1498);
      }
      local_112c = LinkVisibleNodes__6CGraphP5CLinkP8_IO_FILEPi
                             (&WorldGraph,__ptr,__stream,&local_110c);
      if (local_112c == 0) {
        (*DAT_001c1114)(2,"**ConnectVisibleNodes FAILED!\n");
        param_1[3] = -0x10000;
        param_1[4] = (int)ShowBadNode__9CTestHull;
        iVar6 = DAT_001c148c;
        iVar11 = *param_1;
        local_110c = local_110c * 0x58;
        *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(DAT_001c148c + local_110c);
        *(undefined4 *)(iVar11 + 0xc) = *(undefined4 *)(iVar6 + 4 + local_110c);
        *(undefined4 *)(iVar11 + 0x10) = *(undefined4 *)(iVar6 + 8 + local_110c);
      }
      else {
        fprintf(__stream,
                "----------------------------------------------------------------------------\n");
        fprintf(__stream,"Walk Rejection:\n");
        local_1124 = 0;
        if (0 < DAT_001c1498) {
          local_115c = 0;
          do {
            puVar9 = (undefined4 *)(local_115c + DAT_001c148c);
            fprintf(__stream,
                    "-------------------------------------------------------------------------------\n"
                   );
            fprintf(__stream,"Node %4d:\n\n",local_1124);
            iVar11 = 0;
            if (0 < (int)puVar9[8]) {
              do {
                *(undefined4 *)((int)__ptr + (puVar9[9] + iVar11) * 0x18 + 0x10) = 0xf;
                bVar5 = false;
                local_1128 = 0;
                do {
                  if ((!bVar5) || (1 < local_1128 - 1U)) {
                    switch(local_1128) {
                    case 0:
                      local_1104 = _FUN_00149a2c;
                      local_1100 = 24.0;
                      local_10f8 = -12.0;
                      iVar6 = *param_1;
                      break;
                    case 1:
                      local_1104 = 16.0;
                      local_1100 = 72.0;
                      local_10f8 = -16.0;
                      iVar6 = *param_1;
                      break;
                    case 2:
                      local_1104 = 32.0;
                      local_1100 = 64.0;
                      local_10f8 = -32.0;
                      iVar6 = *param_1;
                      break;
                    case 3:
                      local_1104 = 32.0;
                      local_1100 = 64.0;
                      local_10f8 = -32.0;
                      iVar6 = *param_1;
                      break;
                    default:
                      goto switchD_000c75f5_default;
                    }
                    local_10f4 = 0;
                    local_1108 = local_1104;
                    local_10fc = local_10f8;
                    UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar6,&local_10fc,&local_1108);
switchD_000c75f5_default:
                    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,puVar9);
                    if ((*(byte *)(*param_1 + 0x1a5) & 2) == 0) {
                      (*DAT_001c1114)(2,"OFFGROUND!\n");
                    }
                    if (iVar11 < 0) {
                      (*DAT_001c1114)(2,"**** j = %d ****\n",iVar11);
                      if (__ptr != (void *)0x0) {
                        free(__ptr);
                      }
                      goto joined_r0x000c782d;
                    }
                    pfVar7 = (float *)(DAT_001c148c +
                                      *(int *)((int)__ptr + (puVar9[9] + iVar11) * 0x18 + 4) * 0x58)
                    ;
                    fStack_1074 = *pfVar7;
                    fStack_1070 = pfVar7[1];
                    fStack_106c = pfVar7[2];
                    if (local_1128 < 3) {
                      uVar3 = *(undefined4 *)(*param_1 + 0x1a4);
                      bVar13 = (*(byte *)(puVar9 + 7) & 4) != 0;
                      if (bVar13) {
                        pbVar1 = (byte *)(*param_1 + 0x1a4);
                        *pbVar1 = *pbVar1 | 2;
                      }
                      iVar6 = *param_1;
                      local_1108 = *pfVar7 - *(float *)(iVar6 + 8);
                      local_1104 = pfVar7[1] - *(float *)(iVar6 + 0xc);
                      local_1100 = pfVar7[2] - *(float *)(iVar6 + 0x10);
                      lVar14 = (longdouble)UTIL_VecToYaw__FRC6Vector(&local_1108);
                      iVar6 = *param_1;
                      local_1108 = fStack_1074 - *(float *)(iVar6 + 8);
                      local_1104 = fStack_1070 - *(float *)(iVar6 + 0xc);
                      local_1100 = fStack_106c - *(float *)(iVar6 + 0x10);
                      fVar4 = SQRT(local_1104 * local_1104 + local_1108 * local_1108);
                      iVar6 = 0;
                      if (0.0 < fVar4) {
                        do {
                          fVar2 = 16.0;
                          if (fVar4 - 1.0 <= (float)iVar6 + 16.0) {
                            fVar2 = (fVar4 - (float)iVar6) - 1.0;
                          }
                          iVar8 = (*DAT_001c108c)(*(undefined4 *)(*param_1 + 0x208),(float)lVar14,
                                                  fVar2,!bVar13);
                          if (iVar8 == 0) goto LAB_000c7af8;
                          iVar6 = iVar6 + 0x10;
                          fVar2 = (float)iVar6;
                        } while (0x3f < (byte)((fVar4 < fVar2 |
                                                (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar2))
                                                               << 10) >> 8) |
                                               (byte)((ushort)((ushort)(fVar4 == fVar2) << 0xe) >> 8
                                                     )) - 1));
                      }
                      iVar8 = *param_1;
                      local_1108 = *(float *)(iVar8 + 8) - fStack_1074;
                      local_1104 = *(float *)(iVar8 + 0xc) - fStack_1070;
                      local_1100 = *(float *)(iVar8 + 0x10) - fStack_106c;
                      local_10fc = SQRT(local_1100 * local_1100 +
                                        local_1104 * local_1104 + local_1108 * local_1108);
                      if (64.0 < local_10fc) {
LAB_000c7af8:
                        if (local_1128 == 1) {
                          fprintf(__stream,"NODE_HUMAN_HULL step %f\n",iVar6);
                          pbVar1 = (byte *)((int)__ptr + (puVar9[9] + iVar11) * 0x18 + 0x10);
                          *pbVar1 = *pbVar1 & 0xf9;
                          bVar5 = true;
                        }
                        else if (local_1128 < 2) {
                          if (local_1128 == 0) {
                            fprintf(__stream,"NODE_SMALL_HULL step %f\n",iVar6);
                            pbVar1 = (byte *)((int)__ptr + (puVar9[9] + iVar11) * 0x18 + 0x10);
                            *pbVar1 = *pbVar1 & 0xf8;
                            bVar5 = true;
                          }
                        }
                        else if (local_1128 == 2) {
                          fprintf(__stream,"NODE_LARGE_HULL step %f\n",iVar6);
                          pbVar1 = (byte *)((int)__ptr + (puVar9[9] + iVar11) * 0x18 + 0x10);
                          *pbVar1 = *pbVar1 & 0xfb;
                        }
                      }
                      *(undefined4 *)(*param_1 + 0x1a4) = uVar3;
                    }
                    else {
                      local_10c4 = 0;
                      local_10c0 = 0;
                      local_10bc = 32.0;
                      local_10d0 = pfVar7[3];
                      local_10cc = pfVar7[4];
                      local_10c8 = pfVar7[5] + 32.0;
                      uStack_10ac = 0;
                      local_10a8 = 0.0;
                      local_10a4 = 0x42000000;
                      local_10b8 = *puVar9;
                      uStack_10b4 = puVar9[1];
                      fStack_10b0 = (float)puVar9[2] + 32.0;
                      UTIL_TraceHull__FRC6VectorT015IGNORE_MONSTERSiP7edict_sP11TraceResult
                                (&local_10b8,&local_10d0,1,2,*(undefined4 *)(*param_1 + 0x208),
                                 &local_1108);
                      if ((local_1104 != 0.0) ||
                         (0x3f < (byte)((1.0 < local_10f8 |
                                         (byte)((ushort)((ushort)NAN(local_10f8) << 10) >> 8) |
                                        (byte)((ushort)((ushort)(local_10f8 == 1.0) << 0xe) >> 8)) -
                                       1))) {
                        pbVar1 = (byte *)((int)__ptr + (puVar9[9] + iVar11) * 0x18 + 0x10);
                        *pbVar1 = *pbVar1 & 0xf7;
                      }
                    }
                  }
                  local_1128 = local_1128 + 1;
                } while (local_1128 < 4);
                iVar6 = (puVar9[9] + iVar11) * 0x18;
                if (*(int *)((int)__ptr + iVar6 + 0x10) == 0) {
                  fprintf(__stream,"Rejected Node %3d - Unreachable by ",
                          *(undefined4 *)((int)__ptr + iVar6 + 4));
                  puVar10 = (undefined4 *)((int)__ptr + (puVar9[9] + puVar9[8]) * 0x18 + -0x18);
                  puVar12 = (undefined4 *)((int)__ptr + (puVar9[9] + iVar11) * 0x18);
                  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *puVar12 = *puVar10;
                    puVar10 = puVar10 + 1;
                    puVar12 = puVar12 + 1;
                  }
                  fprintf(__stream,"Any Hull\n");
                  puVar9[8] = puVar9[8] + -1;
                  local_112c = local_112c + -1;
                  iVar11 = iVar11 + -1;
                }
                iVar11 = iVar11 + 1;
              } while (iVar11 < (int)puVar9[8]);
            }
            local_115c = local_115c + 0x58;
            local_1124 = local_1124 + 1;
          } while (local_1124 < DAT_001c1498);
        }
        fprintf(__stream,
                "-------------------------------------------------------------------------------\n\n\n"
               );
        iVar11 = RejectInlineLinks__6CGraphP5CLinkP8_IO_FILE(&WorldGraph,__ptr,__stream);
        __size = local_112c - iVar11;
        DAT_001c1490 = calloc(0x18,__size);
        if (DAT_001c1490 != (void *)0x0) {
          iStack_114c = 0;
          local_1124 = 0;
          DAT_001c149c = __size;
          if (0 < DAT_001c1498) {
            iStack_1158 = 0;
            do {
              iVar11 = *(int *)(DAT_001c148c + 0x24 + iStack_1158);
              *(int *)(DAT_001c148c + 0x24 + iStack_1158) = iStack_114c;
              iVar6 = 0;
              if (0 < *(int *)(DAT_001c148c + 0x20 + iStack_1158)) {
                local_1168 = iStack_114c * 0x18;
                do {
                  puVar9 = (undefined4 *)((int)__ptr + (iVar11 + iVar6) * 0x18);
                  puVar10 = (undefined4 *)(local_1168 + (int)DAT_001c1490);
                  for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *puVar10 = *puVar9;
                    puVar9 = puVar9 + 1;
                    puVar10 = puVar10 + 1;
                  }
                  local_1168 = local_1168 + 0x18;
                  iStack_114c = iStack_114c + 1;
                  iVar6 = iVar6 + 1;
                } while (iVar6 < *(int *)(DAT_001c148c + 0x20 + iStack_1158));
              }
              iStack_1158 = iStack_1158 + 0x58;
              local_1124 = local_1124 + 1;
            } while (local_1124 < DAT_001c1498);
          }
          SortNodes__6CGraph(&WorldGraph);
          BuildLinkLookups__6CGraph(&WorldGraph);
          bVar5 = true;
          fprintf(__stream,
                  "\n\n-------------------------------------------------------------------------------\n"
                 );
          fprintf(__stream,"Link Pairings:\n");
          local_1124 = 0;
          if (0 < DAT_001c1498) {
            iVar11 = 0;
            do {
              iVar6 = 0;
              if (0 < *(int *)(DAT_001c148c + 0x20 + iVar11)) {
                do {
                  HashSearch__6CGraphiiRi
                            (&WorldGraph,
                             *(undefined4 *)
                              ((int)DAT_001c1490 +
                              (*(int *)(DAT_001c148c + iVar11 + 0x24) + iVar6) * 0x18 + 4),
                             local_1124,&iStack_1110);
                  if (iStack_1110 < 0) {
                    bVar5 = false;
                    fprintf(__stream,"WARNING: Node %3d does not connect back to Node %3d\n",
                            *(undefined4 *)
                             ((int)DAT_001c1490 +
                             (*(int *)(DAT_001c148c + iVar11 + 0x24) + iVar6) * 0x18 + 4),local_1124
                           );
                  }
                  iVar6 = iVar6 + 1;
                } while (iVar6 < *(int *)(DAT_001c148c + 0x20 + iVar11));
              }
              iVar11 = iVar11 + 0x58;
              local_1124 = local_1124 + 1;
            } while (local_1124 < DAT_001c1498);
          }
          if (bVar5) {
            fprintf(__stream,"\nAll Connections are Paired!\n");
          }
          fprintf(__stream,
                  "-------------------------------------------------------------------------------\n"
                 );
          fprintf(__stream,
                  "\n\n-------------------------------------------------------------------------------\n"
                 );
          fprintf(__stream,"Total Number of Connections in Pool: %d\n",__size);
          fprintf(__stream,
                  "-------------------------------------------------------------------------------\n"
                 );
          fprintf(__stream,"Connection Pool: %d bytes\n",__size * 0x18);
          fprintf(__stream,
                  "-------------------------------------------------------------------------------\n"
                 );
          (*DAT_001c1114)(2,"%d Nodes, %d Connections\n",DAT_001c1498,__size);
          BuildRegionTables__6CGraph(&WorldGraph);
          local_1124 = 0;
          if (0 < DAT_001c1498) {
            iVar11 = 0;
            do {
              if ((*(byte *)(DAT_001c148c + 0x1c + iVar11) & 1) != 0) {
                *(float *)(DAT_001c148c + 8 + iVar11) = *(float *)(DAT_001c148c + 8 + iVar11) - 8.0;
              }
              iVar11 = iVar11 + 0x58;
              local_1124 = local_1124 + 1;
            } while (local_1124 < DAT_001c1498);
          }
          if (__ptr != (void *)0x0) {
            free(__ptr);
          }
          if (__stream != (FILE *)0x0) {
            fclose(__stream);
          }
          WorldGraph = 1;
          DAT_001c1484 = 1;
          uRam001c1488 = 0;
          ComputeStaticRoutingTables__6CGraph(&WorldGraph);
          FSaveGraph__6CGraphPc(&WorldGraph,gpGlobals[3] + gpGlobals[0x26]);
          (*DAT_001c1114)(1,"Done.\n");
          return;
        }
        (*DAT_001c1114)(2,"Couldn\'t malloc LinkPool!\n");
      }
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
joined_r0x000c782d:
      if (__stream != (FILE *)0x0) {
        fclose(__stream);
      }
    }
  }
  return;
}


