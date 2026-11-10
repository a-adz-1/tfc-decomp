// RejectInlineLinks__6CGraphP5CLinkP8_IO_FILE  @ 000c61bc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int RejectInlineLinks__6CGraphP5CLinkP8_IO_FILE(int param_1,int param_2,FILE *param_3)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  int iVar7;
  float *pfVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_60;
  int local_4c;
  int iStack_48;
  int iStack_44;
  int local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_24;
  float fStack_20;
  
  if (param_3 != (FILE *)0x0) {
    fprintf(param_3,"----------------------------------------------------------------------------\n"
           );
    fprintf(param_3,"InLine Rejection:\n");
    fprintf(param_3,"----------------------------------------------------------------------------\n"
           );
  }
  local_4c = 0;
  local_40 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    local_60 = 0;
    do {
      pfVar8 = (float *)(local_60 + *(int *)(param_1 + 0xc));
      if (param_3 != (FILE *)0x0) {
        fprintf(param_3,"Node %3d:\n");
      }
      iStack_44 = 0;
      if (0 < (int)pfVar8[8]) {
        do {
          pfVar1 = (float *)(*(int *)(param_1 + 0xc) +
                            *(int *)(param_2 + 4 + (iStack_44 + (int)pfVar8[9]) * 0x18) * 0x58);
          fStack_24 = *pfVar1 - *pfVar8;
          fStack_20 = pfVar1[1] - pfVar8[1];
          fVar3 = SQRT(fStack_20 * fStack_20 + fStack_24 * fStack_24);
          fVar2 = SQRT(fStack_20 * fStack_20 + fStack_24 * fStack_24);
          if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
            fStack_24 = 0.0;
            fStack_20 = 0.0;
          }
          else {
            fStack_24 = (1.0 / fVar2) * fStack_24;
            fStack_20 = (1.0 / fVar2) * fStack_20;
          }
          *(float *)(param_2 + 0x14 + (iStack_44 + (int)pfVar8[9]) * 0x18) = fVar3;
          bVar6 = false;
          iStack_48 = 0;
          if (0 < (int)pfVar8[8]) {
            do {
              if (iStack_48 != iStack_44) {
                pfVar1 = (float *)(*(int *)(param_1 + 0xc) +
                                  *(int *)(param_2 + 4 + (iStack_48 + (int)pfVar8[9]) * 0x18) * 0x58
                                  );
                fVar2 = *pfVar1 - *pfVar8;
                fVar4 = pfVar1[1] - pfVar8[1];
                fVar5 = SQRT(fVar4 * fVar4 + fVar2 * fVar2);
                if ((byte)((byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) == 0x40) {
                  fStack_3c = 0.0;
                  fStack_38 = 0.0;
                }
                else {
                  fStack_3c = (1.0 / fVar5) * fVar2;
                  fStack_38 = (1.0 / fVar5) * fVar4;
                }
                fVar5 = fStack_20 * fStack_38 + fStack_24 * fStack_3c;
                if (((float)_FUN_00149550 <= fVar5) && (SQRT(fVar4 * fVar4 + fVar2 * fVar2) < fVar3)
                   ) {
                  if (param_3 != (FILE *)0x0) {
                    fprintf(param_3,"REJECTED NODE %3d through Node %3d, Dot = %8f\n",
                            *(undefined4 *)(param_2 + 4 + (iStack_44 + (int)pfVar8[9]) * 0x18),
                            *(undefined4 *)(param_2 + 4 + (iStack_48 + (int)pfVar8[9]) * 0x18),
                            (double)fVar5);
                  }
                  puVar9 = (undefined4 *)
                           (param_2 + -0x18 + ((int)pfVar8[9] + (int)pfVar8[8]) * 0x18);
                  puVar10 = (undefined4 *)(param_2 + (iStack_44 + (int)pfVar8[9]) * 0x18);
                  for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
                    *puVar10 = *puVar9;
                    puVar9 = puVar9 + 1;
                    puVar10 = puVar10 + 1;
                  }
                  pfVar8[8] = (float)((int)pfVar8[8] + -1);
                  iStack_44 = iStack_44 + -1;
                  local_4c = local_4c + 1;
                  bVar6 = true;
                }
              }
              iStack_48 = iStack_48 + 1;
            } while ((iStack_48 < (int)pfVar8[8]) && (!bVar6));
          }
          iStack_44 = iStack_44 + 1;
        } while (iStack_44 < (int)pfVar8[8]);
      }
      if (param_3 != (FILE *)0x0) {
        fprintf(param_3,
                "----------------------------------------------------------------------------\n\n");
      }
      local_60 = local_60 + 0x58;
      local_40 = local_40 + 1;
    } while (local_40 < *(int *)(param_1 + 0x18));
  }
  return local_4c;
}


