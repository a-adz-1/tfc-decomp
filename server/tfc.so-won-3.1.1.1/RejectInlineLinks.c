// RejectInlineLinks__6CGraphP5CLinkP8_IO_FILE  @ 000c630c
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int RejectInlineLinks__6CGraphP5CLinkP8_IO_FILE(int param_1,int param_2,FILE *param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float fVar10;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  float local_40;
  float local_28;
  float local_24;
  
  if (param_3 != (FILE *)0x0) {
    fprintf(param_3,"----------------------------------------------------------------------------\n"
           );
    fprintf(param_3,"InLine Rejection:\n");
    fprintf(param_3,"----------------------------------------------------------------------------\n"
           );
  }
  local_50 = 0;
  local_44 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      pfVar1 = (float *)(*(int *)(param_1 + 0xc) + local_44 * 0x58);
      if (param_3 != (FILE *)0x0) {
        fprintf(param_3,"Node %3d:\n");
      }
      local_48 = 0;
      if (0 < (int)pfVar1[8]) {
        do {
          pfVar2 = (float *)(*(int *)(param_1 + 0xc) +
                            *(int *)(param_2 + 4 + (local_48 + (int)pfVar1[9]) * 0x18) * 0x58);
          local_28 = *pfVar2 - *pfVar1;
          local_24 = pfVar2[1] - pfVar1[1];
          fVar3 = SQRT(local_24 * local_24 + local_28 * local_28);
          fVar10 = SQRT(local_24 * local_24 + local_28 * local_28);
          if ((byte)((byte)((ushort)((ushort)NAN(fVar10) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar10 == 0.0) << 0xe) >> 8)) == 0x40) {
            local_28 = 0.0;
            local_24 = 0.0;
          }
          else {
            local_28 = local_28 * (1.0 / fVar10);
            local_24 = (1.0 / fVar10) * local_24;
          }
          *(float *)(param_2 + 0x14 + (local_48 + (int)pfVar1[9]) * 0x18) = fVar3;
          local_4c = 0;
          fVar10 = pfVar1[8];
          if (0 < (int)fVar10) {
            bVar6 = false;
            do {
              if (local_4c != local_48) {
                pfVar2 = (float *)(*(int *)(param_1 + 0xc) +
                                  *(int *)(param_2 + 4 + (local_4c + (int)pfVar1[9]) * 0x18) * 0x58)
                ;
                fVar10 = *pfVar2 - *pfVar1;
                fVar4 = pfVar2[1] - pfVar1[1];
                fVar5 = SQRT(fVar4 * fVar4 + fVar10 * fVar10);
                if ((byte)((byte)((ushort)((ushort)NAN(fVar5) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar5 == 0.0) << 0xe) >> 8)) == 0x40) {
                  fVar5 = 0.0;
                  local_40 = 0.0;
                }
                else {
                  local_40 = fVar10 * (1.0 / fVar5);
                  fVar5 = (1.0 / fVar5) * fVar4;
                }
                fVar5 = local_24 * fVar5 + local_28 * local_40;
                if ((0.998 <= fVar5) && (SQRT(fVar10 * fVar10 + fVar4 * fVar4) < fVar3)) {
                  if (param_3 != (FILE *)0x0) {
                    fprintf(param_3,"REJECTED NODE %3d through Node %3d, Dot = %8f\n",
                            *(undefined4 *)(param_2 + 4 + (local_48 + (int)pfVar1[9]) * 0x18),
                            *(undefined4 *)(param_2 + 4 + (local_4c + (int)pfVar1[9]) * 0x18),
                            (double)fVar5);
                  }
                  puVar8 = (undefined4 *)
                           (param_2 + -0x18 + ((int)pfVar1[9] + (int)pfVar1[8]) * 0x18);
                  puVar9 = (undefined4 *)(param_2 + ((int)pfVar1[9] + local_48) * 0x18);
                  for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
                    *puVar9 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar9 = puVar9 + 1;
                  }
                  bVar6 = true;
                  pfVar1[8] = (float)((int)pfVar1[8] + -1);
                  local_48 = local_48 + -1;
                  local_50 = local_50 + 1;
                }
              }
              local_4c = local_4c + 1;
              fVar10 = pfVar1[8];
            } while ((local_4c < (int)fVar10) && (!bVar6));
          }
          local_48 = local_48 + 1;
        } while (local_48 < (int)fVar10);
      }
      if (param_3 != (FILE *)0x0) {
        fprintf(param_3,
                "----------------------------------------------------------------------------\n\n");
      }
      local_44 = local_44 + 1;
    } while (local_44 < *(int *)(param_1 + 0x18));
  }
  return local_50;
}


