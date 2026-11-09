// handle_compress.clone.2  @ 000c58cb
undefined4 handle_compress_clone_2(void)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  int *in_EAX;
  byte *pbVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  iVar10 = in_EAX[2];
  bVar2 = false;
  bVar5 = false;
LAB_000c58e1:
  do {
    if (iVar10 == 1) goto LAB_000c594b;
  } while (iVar10 != 2);
  iVar10 = in_EAX[1];
  iVar11 = in_EAX[0x11];
LAB_000c5a00:
  if (iVar10 != 2) goto LAB_000c5a09;
  bVar3 = 0;
  while ((iVar11 < in_EAX[0x12] && (puVar8 = (undefined4 *)*in_EAX, puVar8[1] != 0))) {
    pbVar6 = (byte *)*puVar8;
    uVar12 = (uint)*pbVar6;
    uVar1 = in_EAX[0xd];
    if (uVar12 == uVar1) {
      if (in_EAX[0xe] == 0xff) {
LAB_000c5c2c:
        add_pair_to_block();
        puVar8 = (undefined4 *)*in_EAX;
LAB_000c5b81:
        in_EAX[0xd] = uVar12;
        in_EAX[0xe] = 1;
        pbVar6 = (byte *)*puVar8;
      }
      else {
        in_EAX[0xe] = in_EAX[0xe] + 1;
      }
    }
    else {
      if (in_EAX[0xe] != 1) {
        if (uVar1 < 0x100) goto LAB_000c5c2c;
        goto LAB_000c5b81;
      }
      in_EAX[0x98] = in_EAX[0x98] << 8 ^
                     *(uint *)(BZ2_crc32Table + (uVar1 & 0xff ^ (uint)in_EAX[0x98] >> 0x18) * 4);
      *(undefined1 *)((int)in_EAX + uVar1 + 0x58) = 1;
      *(char *)(in_EAX[9] + iVar11) = (char)uVar1;
      in_EAX[0x11] = in_EAX[0x11] + 1;
      in_EAX[0xd] = uVar12;
      puVar8 = (undefined4 *)*in_EAX;
      pbVar6 = (byte *)*puVar8;
    }
    *puVar8 = pbVar6 + 1;
    puVar8[1] = puVar8[1] + -1;
    iVar10 = puVar8[2];
    puVar8[2] = iVar10 + 1;
    if (iVar10 + 1 == 0) {
      puVar8[3] = puVar8[3] + 1;
    }
    iVar11 = in_EAX[0x11];
    bVar3 = 1;
  }
LAB_000c58fb:
  bVar5 = (bool)(bVar5 | bVar3);
  if (in_EAX[1] != 2) goto LAB_000c5909;
LAB_000c5b22:
  if (in_EAX[0x12] <= in_EAX[0x11]) {
    BZ2_compressBlock();
    in_EAX[2] = 1;
LAB_000c594b:
    do {
      iVar7 = *in_EAX;
      iVar10 = *(int *)(iVar7 + 0x14);
      bVar3 = 0;
      while (bVar4 = bVar3, iVar10 != 0) {
        while( true ) {
          if (in_EAX[0x13] <= in_EAX[0x14]) {
            bVar2 = (bool)(bVar2 | bVar3);
            iVar10 = in_EAX[1];
            goto joined_r0x000c5afc;
          }
          **(undefined1 **)(iVar7 + 0x10) = *(undefined1 *)(in_EAX[0xb] + in_EAX[0x14]);
          in_EAX[0x14] = in_EAX[0x14] + 1;
          iVar7 = *in_EAX;
          iVar10 = *(int *)(iVar7 + 0x14) + -1;
          *(int *)(iVar7 + 0x14) = iVar10;
          *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + 1;
          iVar11 = *(int *)(iVar7 + 0x18) + 1;
          *(int *)(iVar7 + 0x18) = iVar11;
          bVar3 = 1;
          bVar4 = 1;
          if (iVar11 != 0) break;
          *(int *)(iVar7 + 0x1c) = *(int *)(iVar7 + 0x1c) + 1;
          if (iVar10 == 0) goto LAB_000c599b;
        }
      }
LAB_000c599b:
      bVar2 = (bool)(bVar2 | bVar4);
      iVar7 = in_EAX[0x13];
      if (in_EAX[0x14] < iVar7) goto LAB_000c5b57;
      iVar10 = in_EAX[1];
joined_r0x000c5afc:
      if (((iVar10 == 4) && (in_EAX[3] == 0)) && ((0xff < (uint)in_EAX[0xd] || (in_EAX[0xe] < 1))))
      goto LAB_000c5b57;
      in_EAX[0x11] = 0;
      in_EAX[0x13] = 0;
      in_EAX[0x14] = 0;
      in_EAX[0x98] = -1;
      iVar11 = 0;
      do {
        *(undefined1 *)((int)in_EAX + iVar11 + 0x58) = 0;
        iVar11 = iVar11 + 1;
      } while (iVar11 != 0x100);
      in_EAX[0x9b] = in_EAX[0x9b] + 1;
      in_EAX[2] = 2;
      iVar11 = 0;
      if (iVar10 != 3) goto LAB_000c5a00;
      if ((in_EAX[3] == 0) && ((iVar7 = 0x100, 0xff < (uint)in_EAX[0xd] || (in_EAX[0xe] < 1))))
      goto LAB_000c5b57;
LAB_000c5a09:
      if ((iVar11 < in_EAX[0x12]) && (piVar9 = (int *)*in_EAX, piVar9[1] != 0)) {
        if (in_EAX[3] != 0) {
          pbVar6 = (byte *)*piVar9;
          goto LAB_000c5a8f;
        }
      }
      else {
LAB_000c5909:
        if (in_EAX[3] != 0) goto LAB_000c5b22;
      }
      if ((uint)in_EAX[0xd] < 0x100) {
        add_pair_to_block();
      }
      in_EAX[0xd] = 0x100;
      in_EAX[0xe] = 0;
      BZ2_compressBlock();
      in_EAX[2] = 1;
    } while( true );
  }
  iVar7 = 0;
  if (*(int *)(*in_EAX + 4) == 0) {
LAB_000c5b57:
    return CONCAT31((int3)((uint)iVar7 >> 8),bVar2 || bVar5);
  }
  iVar10 = in_EAX[2];
  goto LAB_000c58e1;
  while( true ) {
    pbVar6 = (byte *)(*piVar9 + 1);
    *piVar9 = (int)pbVar6;
    iVar10 = piVar9[1];
    piVar9[1] = iVar10 + -1;
    iVar11 = piVar9[2];
    piVar9[2] = iVar11 + 1;
    if (iVar11 + 1 == 0) {
      piVar9[3] = piVar9[3] + 1;
    }
    iVar7 = in_EAX[3];
    in_EAX[3] = iVar7 + -1;
    iVar11 = in_EAX[0x11];
    if (((in_EAX[0x12] <= iVar11) || (iVar10 + -1 == 0)) || (iVar7 + -1 == 0)) break;
LAB_000c5a8f:
    uVar12 = (uint)*pbVar6;
    uVar1 = in_EAX[0xd];
    if (uVar12 == uVar1) {
      if (in_EAX[0xe] == 0xff) {
LAB_000c5ae4:
        add_pair_to_block();
        piVar9 = (int *)*in_EAX;
LAB_000c5a3f:
        in_EAX[0xd] = uVar12;
        in_EAX[0xe] = 1;
      }
      else {
        in_EAX[0xe] = in_EAX[0xe] + 1;
      }
    }
    else {
      if (in_EAX[0xe] != 1) {
        if (uVar1 < 0x100) goto LAB_000c5ae4;
        goto LAB_000c5a3f;
      }
      in_EAX[0x98] = in_EAX[0x98] << 8 ^
                     *(uint *)(BZ2_crc32Table + (uVar1 & 0xff ^ (uint)in_EAX[0x98] >> 0x18) * 4);
      *(undefined1 *)((int)in_EAX + uVar1 + 0x58) = 1;
      *(char *)(in_EAX[9] + iVar11) = (char)uVar1;
      in_EAX[0x11] = in_EAX[0x11] + 1;
      in_EAX[0xd] = uVar12;
      piVar9 = (int *)*in_EAX;
    }
  }
  bVar3 = 1;
  goto LAB_000c58fb;
}


