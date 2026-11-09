// yuv420_2_rgb8888  @ 001cb910
void yuv420_2_rgb8888(uint8_t *dst_ptr_,uint8_t *y_ptr,uint8_t *u_ptr,uint8_t *v_ptr,int32_t width,
                     int32_t height,int32_t y_span,int32_t uv_span,int32_t dst_span,uint32_t *tables
                     ,int32_t dither)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  byte *local_48;
  uint *local_44;
  byte *local_40;
  byte *local_3c;
  uint *local_38;
  byte *local_34;
  
                    /* Unresolved local var: uint32_t * dst_ptr@[???] */
  iVar11 = height + -1;
  if (0 < iVar11) {
    iVar7 = uv_span - (width >> 1);
    iVar1 = (dst_span >> 2) * 4;
    do {
      iVar11 = iVar11 + width * -0x10000;
      uVar4 = iVar11 + 0x10000;
      if ((int)uVar4 < 0) {
        local_3c = y_ptr + y_span;
        uVar4 = -iVar11 - 0x10001U >> 0x11;
        iVar3 = uVar4 + 1;
        local_34 = v_ptr + iVar3;
        local_44 = (uint *)dst_ptr_;
        local_40 = u_ptr;
        local_48 = y_ptr;
        local_38 = (uint *)(dst_ptr_ + iVar1);
        do {
                    /* Unresolved local var: uint32_t uv@[DW_OP_reg3(EBX)]
                       Unresolved local var: uint32_t y0@[???]
                       Unresolved local var: uint32_t y1@[???] */
          pbVar2 = v_ptr + 1;
          iVar8 = tables[*v_ptr + 0x200] + tables[*local_40 + 0x100];
          uVar12 = tables[*local_3c] + iVar8;
                    /* Unresolved local var: int tmp@[???] */
          uVar5 = uVar12 & 0x40080100;
          uVar9 = tables[*local_48] + iVar8;
          uVar6 = uVar5 - ((int)uVar5 >> 8) | uVar12;
          uVar6 = ((int)(~(uVar6 >> 1) & 0x40080100) >> 8) + uVar6;
          if (uVar5 == 0) {
            uVar6 = uVar12;
          }
                    /* Unresolved local var: int tmp@[???] */
          uVar12 = uVar9 & 0x40080100;
          uVar5 = uVar12 - ((int)uVar12 >> 8) | uVar9;
          uVar5 = ((int)(~(uVar5 >> 1) & 0x40080100) >> 8) + uVar5;
          if (uVar12 == 0) {
            uVar5 = uVar9;
          }
          *local_38 = (uVar6 & 0x7f800) << 5 | uVar6 >> 0xe & 0xff00 | uVar6 & 0xff;
          *local_44 = (uVar5 & 0x7f800) << 5 | uVar5 >> 0xe & 0xff00 | uVar5 & 0xff;
          uVar5 = tables[local_3c[1]] + iVar8;
          uVar9 = iVar8 + tables[local_48[1]];
                    /* Unresolved local var: int tmp@[???] */
          uVar12 = uVar5 & 0x40080100;
          uVar6 = uVar12 - ((int)uVar12 >> 8) | uVar5;
          uVar6 = uVar6 + ((int)(~(uVar6 >> 1) & 0x40080100) >> 8);
                    /* Unresolved local var: int tmp@[???] */
          if (uVar12 == 0) {
            uVar6 = uVar5;
          }
          uVar12 = uVar9 & 0x40080100;
          uVar5 = uVar12 - ((int)uVar12 >> 8) | uVar9;
          uVar5 = uVar5 + ((int)(~(uVar5 >> 1) & 0x40080100) >> 8);
          if (uVar12 == 0) {
            uVar5 = uVar9;
          }
          local_38[1] = (uVar6 & 0x7f800) << 5 | uVar6 >> 0xe & 0xff00 | uVar6 & 0xff;
          local_44[1] = (uVar5 & 0x7f800) << 5 | uVar5 >> 0xe & 0xff00 | uVar5 & 0xff;
          local_3c = local_3c + 2;
          v_ptr = pbVar2;
          local_48 = local_48 + 2;
          local_44 = local_44 + 2;
          local_40 = local_40 + 1;
          local_38 = local_38 + 2;
        } while (pbVar2 != local_34);
        u_ptr = u_ptr + iVar3;
        y_ptr = y_ptr + iVar3 * 2;
        dst_ptr_ = dst_ptr_ + iVar3 * 8;
        uVar4 = iVar11 + 0x30000 + uVar4 * 0x20000;
      }
      else {
        local_34 = v_ptr;
      }
      if (uVar4 >> 0x10 == 0) {
                    /* Unresolved local var: uint32_t uv@[???]
                       Unresolved local var: uint32_t y0@[???]
                       Unresolved local var: uint32_t y1@[???] */
        uVar6 = tables[y_ptr[y_span]] + tables[*local_34 + 0x200] + tables[*u_ptr + 0x100];
                    /* Unresolved local var: int tmp@[???] */
        uVar5 = tables[*local_34 + 0x200] + tables[*u_ptr + 0x100] + tables[*y_ptr];
        uVar9 = uVar6 & 0x40080100;
        if (uVar9 != 0) {
          uVar6 = uVar6 | uVar9 - ((int)uVar9 >> 8);
          uVar6 = uVar6 + ((int)(~(uVar6 >> 1) & 0x40080100) >> 8);
        }
                    /* Unresolved local var: int tmp@[???] */
        uVar9 = uVar5 & 0x40080100;
        if (uVar9 != 0) {
          uVar5 = uVar5 | uVar9 - ((int)uVar9 >> 8);
          uVar5 = uVar5 + ((int)(~(uVar5 >> 1) & 0x40080100) >> 8);
        }
        *(uint *)(dst_ptr_ + iVar1) = (uVar5 & 0x7f800) << 5 | uVar5 >> 0xe & 0xff00 | uVar5 & 0xff;
        *(uint *)dst_ptr_ = (uVar6 & 0x7f800) << 5 | uVar6 >> 0xe & 0xff00 | uVar6 & 0xff;
        dst_ptr_ = dst_ptr_ + 4;
        y_ptr = y_ptr + 1;
      }
      dst_ptr_ = dst_ptr_ + ((dst_span >> 2) * 2 - width) * 4;
      iVar11 = (short)uVar4 + -2;
      y_ptr = y_ptr + (y_span * 2 - width);
      u_ptr = u_ptr + iVar7;
      v_ptr = local_34 + iVar7;
    } while (0 < iVar11);
  }
  if (iVar11 == 0) {
    uVar4 = width * -0x10000 + 0x10000;
    if ((int)uVar4 < 0) {
      iVar11 = (~uVar4 >> 0x11) + 1;
      local_40 = v_ptr + iVar11;
      local_48 = u_ptr;
      local_44 = (uint *)y_ptr;
      puVar10 = (uint *)dst_ptr_;
      do {
                    /* Unresolved local var: uint32_t uv@[DW_OP_reg0(EAX)]
                       Unresolved local var: uint32_t y0@[???]
                       Unresolved local var: uint32_t y1@[???] */
        pbVar2 = v_ptr + 1;
        uVar12 = tables[(byte)*local_44] + tables[*v_ptr + 0x200] + tables[*local_48 + 0x100];
                    /* Unresolved local var: int tmp@[???] */
        uVar9 = uVar12 & 0x40080100;
        uVar5 = tables[*v_ptr + 0x200] + tables[*local_48 + 0x100] +
                tables[*(byte *)((int)local_44 + 1)];
        uVar6 = uVar9 - ((int)uVar9 >> 8) | uVar12;
        uVar6 = ((int)(~(uVar6 >> 1) & 0x40080100) >> 8) + uVar6;
        if (uVar9 == 0) {
          uVar6 = uVar12;
        }
                    /* Unresolved local var: int tmp@[???] */
        uVar12 = uVar5 & 0x40080100;
        uVar9 = uVar12 - ((int)uVar12 >> 8) | uVar5;
        uVar9 = ((int)(~(uVar9 >> 1) & 0x40080100) >> 8) + uVar9;
        if (uVar12 == 0) {
          uVar9 = uVar5;
        }
        *puVar10 = (uVar6 & 0x7f800) << 5 | uVar6 >> 0xe & 0xff00 | uVar6 & 0xff;
        puVar10[1] = (uVar9 & 0x7f800) << 5 | uVar9 >> 0xe & 0xff00 | uVar9 & 0xff;
        puVar10 = puVar10 + 2;
        v_ptr = pbVar2;
        local_48 = local_48 + 1;
        local_44 = (uint *)((int)local_44 + 2);
      } while (pbVar2 != local_40);
      u_ptr = u_ptr + iVar11;
      y_ptr = y_ptr + iVar11 * 2;
      dst_ptr_ = dst_ptr_ + iVar11 * 8;
      uVar4 = (~uVar4 >> 0x11) * 0x20000 + width * -0x10000 + 0x30000;
    }
    else {
      local_40 = v_ptr;
    }
    if (uVar4 == 0) {
                    /* Unresolved local var: uint32_t uv@[???]
                       Unresolved local var: uint32_t y0@[???] */
      uVar4 = tables[*local_40 + 0x200] + tables[*u_ptr + 0x100] + tables[*y_ptr];
                    /* Unresolved local var: int tmp@[???] */
      uVar6 = uVar4 & 0x40080100;
      if (uVar6 != 0) {
        uVar4 = uVar4 | uVar6 - ((int)uVar6 >> 8);
        uVar4 = uVar4 + ((int)(~(uVar4 >> 1) & 0x40080100) >> 8);
      }
      *(uint *)dst_ptr_ = uVar4 & 0xff | (uVar4 & 0x7f800) << 5 | uVar4 >> 0xe & 0xff00;
    }
  }
  return;
}


