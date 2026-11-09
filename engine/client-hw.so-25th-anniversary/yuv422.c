// yuv422_2_rgb8888  @ 001cbf10
void yuv422_2_rgb8888(uint8_t *dst_ptr,uint8_t *y_ptr,uint8_t *u_ptr,uint8_t *v_ptr,int32_t width,
                     int32_t height,int32_t y_span,int32_t uv_span,int32_t dst_span,uint32_t *tables
                     ,int32_t dither)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint8_t *puVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  byte *local_3c;
  byte *local_38;
  byte *local_34;
  uint8_t *local_2c;
  
  iVar9 = height + -1;
  if (0 < iVar9) {
    iVar13 = dst_span + width * -4;
    iVar4 = uv_span - (width >> 1);
    do {
      iVar9 = iVar9 + width * -0x10000;
      uVar7 = iVar9 + 0x10000;
      if ((int)uVar7 < 0) {
        uVar7 = -iVar9 - 0x10001U >> 0x11;
        iVar5 = uVar7 + 1;
        iVar14 = 0;
        puVar11 = dst_ptr;
        do {
                    /* Unresolved local var: uint32_t uv@[DW_OP_reg0(EAX)]
                       Unresolved local var: uint32_t y0@[???]
                       Unresolved local var: uint32_t y1@[???] */
          uVar1 = tables[u_ptr[iVar14] + 0x100];
          uVar2 = tables[v_ptr[iVar14] + 0x200];
          uVar12 = tables[y_ptr[iVar14 * 2]] + uVar2 + uVar1;
          uVar3 = tables[y_ptr[iVar14 * 2 + 1]];
                    /* Unresolved local var: int tmp@[???] */
          uVar10 = uVar12 & 0x40080100;
          puVar11[3] = '\0';
          uVar6 = uVar2 + uVar1 + uVar3;
          uVar8 = uVar10 - ((int)uVar10 >> 8) | uVar12;
          uVar8 = ((int)(~(uVar8 >> 1) & 0x40080100) >> 8) + uVar8;
                    /* Unresolved local var: int tmp@[???] */
          if (uVar10 == 0) {
            uVar8 = uVar12;
          }
          *puVar11 = (uint8_t)uVar8;
          uVar10 = uVar6 & 0x40080100;
          uVar12 = uVar10 - ((int)uVar10 >> 8) | uVar6;
          if (uVar10 != 0) {
            uVar6 = ((int)(~(uVar12 >> 1) & 0x40080100) >> 8) + uVar12;
          }
          iVar14 = iVar14 + 1;
          puVar11[2] = (uint8_t)(uVar8 >> 0xb);
          puVar11[4] = (uint8_t)uVar6;
          puVar11[1] = (uint8_t)(uVar8 >> 0x16);
          puVar11[5] = (uint8_t)(uVar6 >> 0x16);
          puVar11[6] = (uint8_t)(uVar6 >> 0xb);
          puVar11[7] = '\0';
          puVar11 = puVar11 + 8;
        } while (iVar5 != iVar14);
        u_ptr = u_ptr + iVar5;
        v_ptr = v_ptr + iVar5;
        y_ptr = y_ptr + iVar5 * 2;
        dst_ptr = dst_ptr + iVar5 * 8;
        uVar7 = iVar9 + 0x30000 + uVar7 * 0x20000;
      }
      if (uVar7 >> 0x10 == 0) {
                    /* Unresolved local var: uint32_t uv@[???]
                       Unresolved local var: uint32_t y0@[???] */
        uVar6 = tables[*v_ptr + 0x200] + tables[*u_ptr + 0x100] + tables[*y_ptr];
                    /* Unresolved local var: int tmp@[???] */
        uVar8 = uVar6 & 0x40080100;
        if (uVar8 != 0) {
          uVar6 = uVar6 | uVar8 - ((int)uVar8 >> 8);
          uVar6 = uVar6 + ((int)(~(uVar6 >> 1) & 0x40080100) >> 8);
        }
        *dst_ptr = (uint8_t)uVar6;
        dst_ptr[2] = (uint8_t)(uVar6 >> 0xb);
        dst_ptr[1] = (uint8_t)(uVar6 >> 0x16);
        dst_ptr[3] = '\0';
        dst_ptr = dst_ptr + 4;
        y_ptr = y_ptr + 1;
      }
      local_2c = dst_ptr + iVar13;
      local_3c = y_ptr + (y_span - width);
      local_34 = u_ptr + iVar4;
      local_38 = v_ptr + iVar4;
      iVar9 = (short)uVar7 + -1;
      if (iVar9 == 0) {
        return;
      }
      iVar9 = iVar9 + width * -0x10000;
      uVar7 = iVar9 + 0x10000;
      if ((int)uVar7 < 0) {
        uVar7 = -iVar9 - 0x10001U >> 0x11;
        iVar5 = uVar7 + 1;
        iVar14 = 0;
        puVar11 = local_2c;
        do {
                    /* Unresolved local var: uint32_t uv@[DW_OP_reg0(EAX)]
                       Unresolved local var: uint32_t y0@[???]
                       Unresolved local var: uint32_t y1@[???] */
          uVar1 = tables[local_34[iVar14] + 0x100];
          uVar2 = tables[local_38[iVar14] + 0x200];
          uVar12 = tables[local_3c[iVar14 * 2]] + uVar2 + uVar1;
          uVar3 = tables[local_3c[iVar14 * 2 + 1]];
                    /* Unresolved local var: int tmp@[???] */
          uVar10 = uVar12 & 0x40080100;
          puVar11[3] = '\0';
          uVar6 = uVar2 + uVar1 + uVar3;
          uVar8 = uVar10 - ((int)uVar10 >> 8) | uVar12;
          uVar8 = ((int)(~(uVar8 >> 1) & 0x40080100) >> 8) + uVar8;
                    /* Unresolved local var: int tmp@[???] */
          if (uVar10 == 0) {
            uVar8 = uVar12;
          }
          *puVar11 = (uint8_t)uVar8;
          uVar10 = uVar6 & 0x40080100;
          uVar12 = uVar10 - ((int)uVar10 >> 8) | uVar6;
          if (uVar10 != 0) {
            uVar6 = ((int)(~(uVar12 >> 1) & 0x40080100) >> 8) + uVar12;
          }
          iVar14 = iVar14 + 1;
          puVar11[2] = (uint8_t)(uVar8 >> 0xb);
          puVar11[4] = (uint8_t)uVar6;
          puVar11[1] = (uint8_t)(uVar8 >> 0x16);
          puVar11[5] = (uint8_t)(uVar6 >> 0x16);
          puVar11[6] = (uint8_t)(uVar6 >> 0xb);
          puVar11[7] = '\0';
          puVar11 = puVar11 + 8;
        } while (iVar5 != iVar14);
        local_34 = local_34 + iVar5;
        local_38 = local_38 + iVar5;
        local_3c = local_3c + iVar5 * 2;
        local_2c = local_2c + iVar5 * 8;
        uVar7 = iVar9 + 0x30000 + uVar7 * 0x20000;
      }
      if (uVar7 >> 0x10 == 0) {
                    /* Unresolved local var: uint32_t uv@[???]
                       Unresolved local var: uint32_t y0@[???] */
        uVar6 = tables[*local_38 + 0x200] + tables[*local_34 + 0x100] + tables[*local_3c];
                    /* Unresolved local var: int tmp@[???] */
        uVar8 = uVar6 & 0x40080100;
        if (uVar8 != 0) {
          uVar6 = uVar6 | uVar8 - ((int)uVar8 >> 8);
          uVar6 = uVar6 + ((int)(~(uVar6 >> 1) & 0x40080100) >> 8);
        }
        *local_2c = (uint8_t)uVar6;
        local_2c[2] = (uint8_t)(uVar6 >> 0xb);
        local_2c[1] = (uint8_t)(uVar6 >> 0x16);
        local_2c[3] = '\0';
        local_3c = local_3c + 1;
        local_2c = local_2c + 4;
      }
      dst_ptr = local_2c + iVar13;
      iVar9 = (short)uVar7 + -1;
      y_ptr = local_3c + (y_span - width);
      u_ptr = local_34 + iVar4;
      v_ptr = local_38 + iVar4;
    } while (0 < iVar9);
  }
  return;
}


