// yuv444_2_rgb8888  @ 001cc370
void yuv444_2_rgb8888(uint8_t *dst_ptr,uint8_t *y_ptr,uint8_t *u_ptr,uint8_t *v_ptr,int32_t width,
                     int32_t height,int32_t y_span,int32_t uv_span,int32_t dst_span,uint32_t *tables
                     ,int32_t dither)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint8_t *puVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  byte *local_40;
  byte *local_3c;
  byte *local_38;
  uint8_t *local_30;
  
  iVar5 = height + -1;
  if (0 < iVar5) {
    iVar12 = dst_span + width * -4;
    iVar10 = uv_span - width;
    do {
      iVar5 = iVar5 + width * -0x10000;
      uVar6 = iVar5 + 0x10000;
      if ((int)uVar6 < 0) {
        iVar13 = 0;
        uVar6 = -iVar5 - 0x10001U >> 0x11;
        iVar7 = uVar6 + 1;
        iVar4 = iVar7 * 2;
        puVar11 = dst_ptr;
        do {
                    /* Unresolved local var: uint32_t uv@[???]
                       Unresolved local var: uint32_t y0@[???]
                       Unresolved local var: uint32_t y1@[???] */
          uVar1 = tables[u_ptr[iVar13] + 0x100];
          uVar2 = tables[v_ptr[iVar13] + 0x200];
          uVar3 = tables[y_ptr[iVar13]];
          puVar11[3] = '\0';
          uVar8 = uVar2 + uVar1 + uVar3;
                    /* Unresolved local var: int tmp@[???] */
          uVar9 = uVar8 & 0x40080100;
          uVar14 = uVar9 - ((int)uVar9 >> 8) | uVar8;
          uVar14 = ((int)(~(uVar14 >> 1) & 0x40080100) >> 8) + uVar14;
          if (uVar9 == 0) {
            uVar14 = uVar8;
          }
          *puVar11 = (uint8_t)uVar14;
          puVar11[2] = (uint8_t)(uVar14 >> 0xb);
          puVar11[1] = (uint8_t)(uVar14 >> 0x16);
          uVar8 = tables[v_ptr[iVar13 + 1] + 0x200] + tables[u_ptr[iVar13 + 1] + 0x100] +
                  tables[y_ptr[iVar13 + 1]];
                    /* Unresolved local var: int tmp@[???] */
          uVar9 = uVar8 & 0x40080100;
          uVar14 = uVar9 - ((int)uVar9 >> 8) | uVar8;
          uVar14 = ((int)(~(uVar14 >> 1) & 0x40080100) >> 8) + uVar14;
          if (uVar9 == 0) {
            uVar14 = uVar8;
          }
          iVar13 = iVar13 + 2;
          puVar11[4] = (uint8_t)uVar14;
          puVar11[5] = (uint8_t)(uVar14 >> 0x16);
          puVar11[6] = (uint8_t)(uVar14 >> 0xb);
          puVar11[7] = '\0';
          puVar11 = puVar11 + 8;
        } while (iVar4 != iVar13);
        u_ptr = u_ptr + iVar4;
        v_ptr = v_ptr + iVar4;
        y_ptr = y_ptr + iVar4;
        dst_ptr = dst_ptr + iVar7 * 8;
        uVar6 = iVar5 + 0x30000 + uVar6 * 0x20000;
      }
      if (uVar6 >> 0x10 == 0) {
                    /* Unresolved local var: uint32_t uv@[???]
                       Unresolved local var: uint32_t y0@[???] */
        uVar8 = tables[*v_ptr + 0x200] + tables[*u_ptr + 0x100] + tables[*y_ptr];
                    /* Unresolved local var: int tmp@[???] */
        uVar14 = uVar8 & 0x40080100;
        if (uVar14 != 0) {
          uVar8 = uVar8 | uVar14 - ((int)uVar14 >> 8);
          uVar8 = uVar8 + ((int)(~(uVar8 >> 1) & 0x40080100) >> 8);
        }
        *dst_ptr = (uint8_t)uVar8;
        dst_ptr[1] = (uint8_t)(uVar8 >> 0x16);
        dst_ptr[2] = (uint8_t)(uVar8 >> 0xb);
        dst_ptr[3] = '\0';
        dst_ptr = dst_ptr + 4;
        y_ptr = y_ptr + 1;
        u_ptr = u_ptr + 1;
        v_ptr = v_ptr + 1;
      }
      local_30 = dst_ptr + iVar12;
      local_40 = y_ptr + (y_span - width);
      local_3c = u_ptr + iVar10;
      local_38 = v_ptr + iVar10;
      iVar5 = (short)uVar6 + -1;
      if (iVar5 == 0) {
        return;
      }
      iVar5 = iVar5 + width * -0x10000;
      uVar6 = iVar5 + 0x10000;
      if ((int)uVar6 < 0) {
        iVar13 = 0;
        uVar6 = -iVar5 - 0x10001U >> 0x11;
        iVar7 = uVar6 + 1;
        iVar4 = iVar7 * 2;
        puVar11 = local_30;
        do {
                    /* Unresolved local var: uint32_t uv@[???]
                       Unresolved local var: uint32_t y0@[???]
                       Unresolved local var: uint32_t y1@[???] */
          uVar1 = tables[local_3c[iVar13] + 0x100];
          uVar2 = tables[local_38[iVar13] + 0x200];
          uVar3 = tables[local_40[iVar13]];
          puVar11[3] = '\0';
          uVar8 = uVar3 + uVar2 + uVar1;
                    /* Unresolved local var: int tmp@[???] */
          uVar9 = uVar8 & 0x40080100;
          uVar14 = uVar9 - ((int)uVar9 >> 8) | uVar8;
          uVar14 = ((int)(~(uVar14 >> 1) & 0x40080100) >> 8) + uVar14;
          if (uVar9 == 0) {
            uVar14 = uVar8;
          }
          *puVar11 = (uint8_t)uVar14;
          puVar11[2] = (uint8_t)(uVar14 >> 0xb);
          puVar11[1] = (uint8_t)(uVar14 >> 0x16);
          uVar8 = tables[local_38[iVar13 + 1] + 0x200] + tables[local_3c[iVar13 + 1] + 0x100] +
                  tables[local_40[iVar13 + 1]];
                    /* Unresolved local var: int tmp@[???] */
          uVar9 = uVar8 & 0x40080100;
          uVar14 = uVar9 - ((int)uVar9 >> 8) | uVar8;
          uVar14 = ((int)(~(uVar14 >> 1) & 0x40080100) >> 8) + uVar14;
          if (uVar9 == 0) {
            uVar14 = uVar8;
          }
          iVar13 = iVar13 + 2;
          puVar11[4] = (uint8_t)uVar14;
          puVar11[5] = (uint8_t)(uVar14 >> 0x16);
          puVar11[6] = (uint8_t)(uVar14 >> 0xb);
          puVar11[7] = '\0';
          puVar11 = puVar11 + 8;
        } while (iVar4 != iVar13);
        local_3c = local_3c + iVar4;
        local_38 = local_38 + iVar4;
        local_40 = local_40 + iVar4;
        local_30 = local_30 + iVar7 * 8;
        uVar6 = iVar5 + 0x30000 + uVar6 * 0x20000;
      }
      if (uVar6 >> 0x10 == 0) {
                    /* Unresolved local var: uint32_t uv@[???]
                       Unresolved local var: uint32_t y0@[???] */
        uVar8 = tables[*local_38 + 0x200] + tables[*local_3c + 0x100] + tables[*local_40];
                    /* Unresolved local var: int tmp@[???] */
        uVar14 = uVar8 & 0x40080100;
        if (uVar14 != 0) {
          uVar8 = uVar8 | uVar14 - ((int)uVar14 >> 8);
          uVar8 = uVar8 + ((int)(~(uVar8 >> 1) & 0x40080100) >> 8);
        }
        *local_30 = (uint8_t)uVar8;
        local_30[2] = (uint8_t)(uVar8 >> 0xb);
        local_30[1] = (uint8_t)(uVar8 >> 0x16);
        local_30[3] = '\0';
        local_40 = local_40 + 1;
        local_3c = local_3c + 1;
        local_38 = local_38 + 1;
        local_30 = local_30 + 4;
      }
      iVar5 = (short)uVar6 + -1;
      dst_ptr = local_30 + iVar12;
                    /* catch() { ... } // from try @ 001cc9d3 with catch @ 001cc7f0 */
      y_ptr = local_40 + (y_span - width);
      u_ptr = local_3c + iVar10;
      v_ptr = local_38 + iVar10;
    } while (0 < iVar5);
  }
  return;
}


