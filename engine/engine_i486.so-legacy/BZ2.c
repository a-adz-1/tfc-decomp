// BZ2_blockSort  @ 000e0299
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BZ2_blockSort(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_40;
  int local_20 [4];
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar4 = *(int *)(param_1 + 0x44);
  iVar2 = *(int *)(param_1 + 0x268);
  iVar3 = *(int *)(param_1 + 0x30);
  if (9999 < iVar4) {
    local_40 = 0;
    if (0 < iVar3) {
      if (iVar3 < 0x65) {
        local_40 = ((iVar3 + -1) / 3) * iVar4;
      }
      else {
        local_40 = iVar4 * 0x21;
      }
    }
    local_20[0] = local_40;
    mainSort(*(undefined4 *)(param_1 + 0x18),iVar4,iVar2,local_20);
    if (2 < iVar2) {
      fprintf(_stderr,"      %d work, %d block, ratio %5.2f\n",local_40 - local_20[0],iVar4,
              (double)(local_40 - local_20[0]) / (double)iVar4);
    }
    if (-1 < local_20[0]) goto LAB_000e033a;
    if (1 < iVar2) {
      fwrite("    too repetitive; using fallback sorting algorithm\n",1,0x35,_stderr);
    }
  }
  fallbackSort(iVar4,iVar2);
LAB_000e033a:
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  if (*(int *)(param_1 + 0x44) < 1) {
LAB_000e0368:
    BZ2_bz__AssertH__fail(0x3eb);
    return;
  }
  if (*piVar1 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      if (*(int *)(param_1 + 0x44) <= iVar4) goto LAB_000e0368;
    } while (piVar1[iVar4] != 0);
  }
  *(int *)(param_1 + 0x1c) = iVar4;
  return;
}


// BZ2_bsInitWrite  @ 000d83d3
void BZ2_bsInitWrite(int param_1)

{
  *(undefined4 *)(param_1 + 0x25c) = 0;
  *(undefined4 *)(param_1 + 600) = 0;
  return;
}


// BZ2_bzBuffToBuffCompress  @ 000d7e0f
int BZ2_bzBuffToBuffCompress
              (int param_1,int *param_2,int param_3,undefined4 param_4,int param_5,int param_6,
              int param_7)

{
  int iVar1;
  int iVar2;
  int local_4c;
  undefined4 local_48;
  int local_3c;
  int local_38;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (((((param_2 == (int *)0x0) || (param_1 == 0)) || (param_5 < 1)) ||
      ((param_3 == 0 || (param_6 < 0)))) || ((9 < param_5 || ((param_7 < 0 || (4 < param_6)))))) {
    iVar1 = -2;
  }
  else {
    iVar1 = -2;
    if (param_7 < 0xfb) {
      if (param_7 == 0) {
        param_7 = 0x1e;
      }
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      iVar1 = BZ2_bzCompressInit(&local_4c,param_5,param_6,param_7);
      if (iVar1 == 0) {
        local_4c = param_3;
        local_3c = param_1;
        local_48 = param_4;
        local_38 = *param_2;
        iVar2 = BZ2_bzCompress(&local_4c,2);
        if (iVar2 == 3) {
          BZ2_bzCompressEnd(&local_4c);
          iVar1 = -8;
        }
        else if (iVar2 == 4) {
          *param_2 = *param_2 - local_38;
          BZ2_bzCompressEnd(&local_4c);
        }
        else {
          BZ2_bzCompressEnd(&local_4c);
          iVar1 = iVar2;
        }
      }
    }
  }
  return iVar1;
}


// BZ2_bzBuffToBuffDecompress  @ 000d7f31
int BZ2_bzBuffToBuffDecompress
              (int param_1,int *param_2,int param_3,undefined4 param_4,uint param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int local_4c;
  undefined4 local_48;
  int local_3c;
  int local_38;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if ((((param_2 == (int *)0x0) || (param_1 == 0)) || (1 < param_5)) ||
     (((param_3 == 0 || (4 < param_6)) || (param_6 < 0)))) {
    iVar1 = -2;
  }
  else {
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    iVar1 = BZ2_bzDecompressInit(&local_4c,param_6,param_5);
    if (iVar1 == 0) {
      local_4c = param_3;
      local_3c = param_1;
      local_48 = param_4;
      local_38 = *param_2;
      iVar2 = BZ2_bzDecompress(&local_4c);
      if (iVar2 == 0) {
        if (local_38 == 0) {
          BZ2_bzDecompressEnd(&local_4c);
          iVar1 = -8;
        }
        else {
          BZ2_bzDecompressEnd(&local_4c);
          iVar1 = -7;
        }
      }
      else if (iVar2 == 4) {
        *param_2 = *param_2 - local_38;
        BZ2_bzDecompressEnd(&local_4c);
      }
      else {
        BZ2_bzDecompressEnd(&local_4c);
        iVar1 = iVar2;
      }
    }
  }
  return iVar1;
}


// BZ2_bzCompress  @ 000d6070
int BZ2_bzCompress(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  
  if (param_1 == 0) {
    return -2;
  }
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 == (int *)0x0) {
    return -2;
  }
  iVar2 = *piVar1;
  if (iVar2 != param_1) {
    return -2;
  }
  while (iVar3 = piVar1[1], iVar3 == 2) {
    if (param_2 == 0) {
      cVar4 = handle_compress_clone_2();
      return (-(uint)(cVar4 == '\0') & 0xfffffffd) + 1;
    }
    if (param_2 == 1) {
      piVar1[3] = *(int *)(iVar2 + 4);
      piVar1[1] = 3;
    }
    else {
      if (param_2 != 2) {
        return -2;
      }
      piVar1[3] = *(int *)(iVar2 + 4);
      piVar1[1] = 4;
    }
  }
  if (iVar3 < 3) {
    if (iVar3 == 1) {
      return -1;
    }
  }
  else {
    if (iVar3 == 3) {
      if (param_2 != 1) {
        return -1;
      }
      if (piVar1[3] != *(int *)(iVar2 + 4)) {
        return -1;
      }
      handle_compress_clone_2();
      if (piVar1[3] != 0) {
        return 2;
      }
      if (((uint)piVar1[0xd] < 0x100) && (0 < piVar1[0xe])) {
        return 2;
      }
      if (piVar1[0x14] < piVar1[0x13]) {
        return 2;
      }
      piVar1[1] = 2;
      return 1;
    }
    if (iVar3 == 4) {
      if (param_2 != 2) {
        return -1;
      }
      if (piVar1[3] != *(int *)(iVar2 + 4)) {
        return -1;
      }
      cVar4 = handle_compress_clone_2();
      if (cVar4 == '\0') {
        return -1;
      }
      if (piVar1[3] != 0) {
        return 3;
      }
      if (((uint)piVar1[0xd] < 0x100) && (0 < piVar1[0xe])) {
        return 3;
      }
      if (piVar1[0x14] < piVar1[0x13]) {
        return 3;
      }
      piVar1[1] = 1;
      return 4;
    }
  }
  return 0;
}


// BZ2_bzCompressEnd  @ 000d61cd
undefined4 BZ2_bzCompressEnd(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0xfffffffe;
  if (((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x20), piVar1 != (int *)0x0)) &&
     (*piVar1 == param_1)) {
    if (piVar1[4] != 0) {
      (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),piVar1[4]);
    }
    if (piVar1[5] != 0) {
      (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),piVar1[5]);
    }
    if (piVar1[6] != 0) {
      (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),piVar1[6]);
    }
    (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
    uVar2 = 0;
  }
  return uVar2;
}


// BZ2_bzCompressInit  @ 000d5e1e
undefined4 BZ2_bzCompressInit(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_2 < 1) || (param_1 == 0)) || (param_4 < 0)) || (9 < param_2)) {
    uVar1 = 0xfffffffe;
  }
  else {
    uVar1 = 0xfffffffe;
    if (param_4 < 0xfb) {
      if (param_4 == 0) {
        param_4 = 0x1e;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(code **)(param_1 + 0x24) = default_bzalloc;
      }
      if (*(int *)(param_1 + 0x28) == 0) {
        *(code **)(param_1 + 0x28) = default_bzfree;
      }
      piVar2 = (int *)(**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x2c),0xd9b0,1);
      uVar1 = 0xfffffffd;
      if (piVar2 != (int *)0x0) {
        *piVar2 = param_1;
        piVar2[4] = 0;
        piVar2[5] = 0;
        piVar2[6] = 0;
        iVar3 = (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x2c),param_2 * 400000,1);
        piVar2[4] = iVar3;
        iVar3 = (**(code **)(param_1 + 0x24))
                          (*(undefined4 *)(param_1 + 0x2c),param_2 * 400000 + 0x88,1);
        piVar2[5] = iVar3;
        iVar4 = (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x2c),0x40004,1);
        piVar2[6] = iVar4;
        iVar3 = piVar2[4];
        if (iVar3 != 0) {
          if ((piVar2[5] != 0) && (iVar4 != 0)) {
            piVar2[0x9b] = 0;
            piVar2[2] = 2;
            piVar2[1] = 2;
            piVar2[0x99] = 0;
            piVar2[0x9c] = param_2;
            piVar2[0x12] = param_2 * 100000 + -0x13;
            piVar2[0x9a] = param_3;
            piVar2[0xc] = param_4;
            piVar2[9] = piVar2[5];
            piVar2[10] = iVar3;
            piVar2[0xb] = 0;
            piVar2[8] = iVar3;
            *(int **)(param_1 + 0x20) = piVar2;
            *(undefined4 *)(param_1 + 8) = 0;
            *(undefined4 *)(param_1 + 0xc) = 0;
            *(undefined4 *)(param_1 + 0x18) = 0;
            *(undefined4 *)(param_1 + 0x1c) = 0;
            piVar2[0xd] = 0x100;
            piVar2[0xe] = 0;
            piVar2[0x11] = 0;
            piVar2[0x13] = 0;
            piVar2[0x14] = 0;
            piVar2[0x98] = -1;
            iVar3 = 0;
            do {
              *(undefined1 *)((int)piVar2 + iVar3 + 0x58) = 0;
              iVar3 = iVar3 + 1;
            } while (iVar3 != 0x100);
            piVar2[0x9b] = 1;
            return 0;
          }
          (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),iVar3);
        }
        if (piVar2[5] != 0) {
          (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),piVar2[5]);
        }
        if (piVar2[6] != 0) {
          (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),piVar2[6]);
        }
        (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),piVar2);
        uVar1 = 0xfffffffd;
      }
    }
  }
  return uVar1;
}


// BZ2_bzDecompress  @ 000d6366
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int BZ2_bzDecompress(int param_1)

{
  ushort uVar1;
  int *piVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int local_40;
  byte *local_38;
  uint local_34;
  uint local_2c;
  
  if (((param_1 == 0) || (piVar2 = *(int **)(param_1 + 0x20), piVar2 == (int *)0x0)) ||
     (*piVar2 != param_1)) {
    return -2;
  }
LAB_000d638f:
  iVar4 = piVar2[1];
  if (iVar4 == 1) {
    return -1;
  }
  do {
    if (iVar4 == 2) {
      if ((char)piVar2[10] != '\0') {
        if ((char)piVar2[4] == '\0') {
          iVar4 = *piVar2;
          goto LAB_000d63c2;
        }
        iVar4 = *piVar2;
        goto LAB_000d6961;
      }
      if ((char)piVar2[4] == '\0') {
        local_2c = piVar2[0x318];
        iVar4 = piVar2[3];
        local_40 = piVar2[0x110];
        iVar9 = piVar2[0x313];
        uVar18 = piVar2[0xe];
        local_38 = *(byte **)(*piVar2 + 0x10);
        iVar10 = *(int *)(*piVar2 + 0x14);
        iVar17 = piVar2[0x3e90] + 1;
        iVar12 = iVar10;
        local_34 = piVar2[0xf];
        bVar3 = *(byte *)(piVar2 + 2);
        do {
          iVar19 = local_40;
          if (iVar4 < 1) goto LAB_000d6dc1;
LAB_000d65c9:
          if (iVar12 == 0) {
            iVar12 = 0;
LAB_000d662b:
            iVar17 = *piVar2;
            uVar16 = *(uint *)(iVar17 + 0x18);
            uVar11 = (uVar16 + iVar10) - iVar12;
            *(uint *)(iVar17 + 0x18) = uVar11;
            if (uVar11 < uVar16) {
              *(int *)(iVar17 + 0x1c) = *(int *)(iVar17 + 0x1c) + 1;
            }
            piVar2[0x318] = local_2c;
            *(byte *)(piVar2 + 2) = bVar3;
            piVar2[3] = iVar4;
            piVar2[0x110] = local_40;
            piVar2[0xf] = local_34;
            piVar2[0x313] = iVar9;
            piVar2[0xe] = uVar18;
            *(byte **)(iVar17 + 0x10) = local_38;
            *(int *)(iVar17 + 0x14) = iVar12;
            goto LAB_000d6680;
          }
          if (iVar4 != 1) {
            do {
              *local_38 = bVar3;
              local_2c = *(uint *)(BZ2_crc32Table + (local_2c >> 0x18 ^ (uint)bVar3) * 4) ^
                         local_2c << 8;
              iVar4 = iVar4 + -1;
              local_38 = local_38 + 1;
              iVar12 = iVar12 + -1;
              if (iVar12 == 0) {
                iVar12 = 0;
                goto LAB_000d662b;
              }
            } while (iVar4 != 1);
          }
          while( true ) {
            *local_38 = bVar3;
            local_2c = local_2c << 8 ^
                       *(uint *)(BZ2_crc32Table + ((uint)bVar3 ^ local_2c >> 0x18) * 4);
            local_38 = local_38 + 1;
            iVar12 = iVar12 + -1;
            iVar19 = local_40;
LAB_000d6dc1:
            if (iVar17 == iVar19) {
              iVar4 = 0;
              local_40 = iVar19;
              goto LAB_000d662b;
            }
            bVar3 = (byte)local_34;
            uVar16 = *(uint *)(iVar9 + uVar18 * 4);
            uVar18 = uVar16 >> 8;
            local_40 = iVar19 + 1;
            uVar16 = uVar16 & 0xff;
            if ((local_34 == uVar16) && (uVar16 = local_34, iVar17 != local_40)) break;
            local_34 = uVar16;
            if (iVar12 == 0) {
              iVar4 = 1;
              goto LAB_000d662b;
            }
          }
          uVar16 = *(uint *)(iVar9 + uVar18 * 4);
          uVar18 = uVar16 >> 8;
          local_40 = iVar19 + 2;
          uVar11 = local_34;
          if ((iVar17 == local_40) || (uVar11 = uVar16 & 0xff, local_34 != uVar11)) {
            local_34 = uVar11;
            iVar4 = 2;
            goto LAB_000d65c9;
          }
          uVar16 = *(uint *)(iVar9 + uVar18 * 4);
          uVar18 = uVar16 >> 8;
          local_40 = iVar19 + 3;
          uVar11 = local_34;
          if ((iVar17 == local_40) || (uVar11 = uVar16 & 0xff, local_34 != uVar11)) {
            local_34 = uVar11;
            iVar4 = 3;
            goto LAB_000d65c9;
          }
          uVar18 = *(uint *)(iVar9 + uVar18 * 4);
          iVar4 = (uVar18 & 0xff) + 4;
          uVar16 = *(uint *)(iVar9 + (uVar18 >> 8) * 4);
          uVar18 = uVar16 >> 8;
          local_40 = iVar19 + 5;
          local_34 = uVar16 & 0xff;
        } while( true );
      }
      iVar4 = *piVar2;
      goto LAB_000d66a8;
    }
  } while (iVar4 < 10);
  goto LAB_000d6547;
LAB_000d66a8:
  if (*(int *)(iVar4 + 0x14) != 0) {
    if (piVar2[3] == 0) {
      iVar9 = piVar2[0x110];
      iVar10 = piVar2[0x3e90] + 1;
      if (iVar9 == iVar10) goto LAB_000d64e1;
      piVar2[3] = 1;
      *(char *)(piVar2 + 2) = (char)piVar2[0xf];
      iVar12 = piVar2[0x313];
      uVar18 = *(uint *)(iVar12 + piVar2[0xe] * 4);
      uVar16 = uVar18 >> 8;
      piVar2[0xe] = uVar16;
      if (piVar2[5] == 0) {
        piVar2[5] = (&BZ2_rNums)[piVar2[6]];
        iVar17 = piVar2[6] + 1;
        if (iVar17 == 0x200) {
          iVar17 = 0;
        }
        piVar2[6] = iVar17;
      }
      iVar17 = piVar2[5] + -1;
      piVar2[5] = iVar17;
      piVar2[0x110] = iVar9 + 1;
      if (iVar10 != iVar9 + 1) {
        local_2c._0_1_ = (byte)uVar18;
        uVar18 = (uint)(iVar17 == 1 ^ (byte)local_2c);
        if (uVar18 == piVar2[0xf]) {
          piVar2[3] = 2;
          uVar18 = *(uint *)(iVar12 + uVar16 * 4);
          uVar16 = uVar18 >> 8;
          piVar2[0xe] = uVar16;
          if (iVar17 == 0) {
            piVar2[5] = (&BZ2_rNums)[piVar2[6]];
            iVar17 = piVar2[6] + 1;
            if (iVar17 == 0x200) {
              iVar17 = 0;
            }
            piVar2[6] = iVar17;
          }
          iVar17 = piVar2[5] + -1;
          piVar2[5] = iVar17;
          piVar2[0x110] = iVar9 + 2;
          if (iVar10 == iVar9 + 2) goto LAB_000d66a8;
          uVar18 = (uint)(byte)(iVar17 == 1 ^ (byte)uVar18);
          if (uVar18 == piVar2[0xf]) {
            piVar2[3] = 3;
            uVar18 = *(uint *)(iVar12 + uVar16 * 4);
            uVar16 = uVar18 >> 8;
            piVar2[0xe] = uVar16;
            if (iVar17 == 0) {
              piVar2[5] = (&BZ2_rNums)[piVar2[6]];
              iVar17 = piVar2[6] + 1;
              if (iVar17 == 0x200) {
                iVar17 = 0;
              }
              piVar2[6] = iVar17;
            }
            iVar17 = piVar2[5] + -1;
            piVar2[5] = iVar17;
            piVar2[0x110] = iVar9 + 3;
            if (iVar10 != iVar9 + 3) {
              local_34._0_1_ = (byte)uVar18;
              uVar18 = (uint)(iVar17 == 1 ^ (byte)local_34);
              if (uVar18 == piVar2[0xf]) {
                uVar18 = *(uint *)(iVar12 + uVar16 * 4);
                local_38._0_1_ = (byte)uVar18;
                uVar18 = uVar18 >> 8;
                piVar2[0xe] = uVar18;
                if (iVar17 == 0) {
                  piVar2[5] = (&BZ2_rNums)[piVar2[6]];
                  iVar10 = piVar2[6] + 1;
                  if (iVar10 == 0x200) {
                    iVar10 = 0;
                  }
                  piVar2[6] = iVar10;
                }
                iVar10 = piVar2[5] + -1;
                piVar2[5] = iVar10;
                piVar2[0x110] = iVar9 + 4;
                piVar2[3] = (iVar10 == 1 ^ (byte)local_38) + 4;
                uVar18 = *(uint *)(iVar12 + uVar18 * 4);
                uVar16 = uVar18 & 0xff;
                piVar2[0xf] = uVar16;
                piVar2[0xe] = uVar18 >> 8;
                if (iVar10 == 0) {
                  piVar2[5] = (&BZ2_rNums)[piVar2[6]];
                  iVar10 = piVar2[6] + 1;
                  if (iVar10 == 0x200) {
                    iVar10 = 0;
                  }
                  piVar2[6] = iVar10;
                }
                iVar10 = piVar2[5];
                piVar2[5] = iVar10 + -1;
                piVar2[0xf] = iVar10 + -1 == 1 ^ uVar16;
                piVar2[0x110] = iVar9 + 5;
              }
              else {
                piVar2[0xf] = uVar18;
              }
            }
            goto LAB_000d66a8;
          }
        }
        piVar2[0xf] = uVar18;
      }
    }
    else {
      **(undefined1 **)(iVar4 + 0x10) = (char)piVar2[2];
      piVar2[0x318] =
           piVar2[0x318] << 8 ^
           *(uint *)(BZ2_crc32Table +
                    ((uint)*(byte *)(piVar2 + 2) ^ (uint)piVar2[0x318] >> 0x18) * 4);
      piVar2[3] = piVar2[3] + -1;
      iVar4 = *piVar2;
      *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
      *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + -1;
      iVar9 = *(int *)(iVar4 + 0x18) + 1;
      *(int *)(iVar4 + 0x18) = iVar9;
      if (iVar9 == 0) {
        *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 1;
      }
    }
    goto LAB_000d66a8;
  }
  goto LAB_000d6680;
LAB_000d6961:
  if (*(int *)(iVar4 + 0x14) != 0) {
    if (piVar2[3] == 0) {
      iVar9 = piVar2[0x110];
      iVar10 = piVar2[0x3e90] + 1;
      if (iVar9 == iVar10) goto LAB_000d64e1;
      piVar2[3] = 1;
      *(char *)(piVar2 + 2) = (char)piVar2[0xf];
      uVar18 = piVar2[0xe];
      iVar17 = 0x100;
      iVar12 = 0;
      do {
        iVar19 = iVar17 + iVar12 >> 1;
        if ((int)uVar18 < piVar2[iVar19 + 0x111]) {
          iVar17 = iVar19;
          iVar19 = iVar12;
        }
        iVar12 = iVar19;
      } while (iVar17 - iVar12 != 1);
      iVar17 = piVar2[0x315];
      iVar19 = piVar2[0x314];
      piVar2[0xe] = (*(byte *)(iVar17 + (uVar18 >> 1)) >> (((byte)uVar18 & 1) << 2) & 0xf) << 0x10 |
                    (uint)*(ushort *)(iVar19 + uVar18 * 2);
      if (piVar2[5] == 0) {
        piVar2[5] = (&BZ2_rNums)[piVar2[6]];
        iVar14 = piVar2[6] + 1;
        iVar13 = 0;
        if (iVar14 != 0x200) {
          iVar13 = iVar14;
        }
        piVar2[6] = iVar13;
      }
      iVar14 = piVar2[5] + -1;
      piVar2[5] = iVar14;
      piVar2[0x110] = iVar9 + 1;
      if (iVar10 != iVar9 + 1) {
        uVar18 = (uint)(byte)(iVar14 == 1 ^ (byte)iVar12);
        if (uVar18 == piVar2[0xf]) {
          piVar2[3] = 2;
          uVar18 = piVar2[0xe];
          iVar13 = 0x100;
          iVar12 = 0;
          do {
            iVar6 = iVar13 + iVar12 >> 1;
            if ((int)uVar18 < piVar2[iVar6 + 0x111]) {
              iVar13 = iVar6;
              iVar6 = iVar12;
            }
            iVar12 = iVar6;
          } while (iVar13 - iVar12 != 1);
          piVar2[0xe] = (*(byte *)(iVar17 + (uVar18 >> 1)) >> ((char)uVar18 * '\x04' & 4U) & 0xf) <<
                        0x10 | (uint)*(ushort *)(iVar19 + uVar18 * 2);
          if (iVar14 == 0) {
            piVar2[5] = (&BZ2_rNums)[piVar2[6]];
            iVar14 = piVar2[6] + 1;
            iVar13 = 0;
            if (iVar14 != 0x200) {
              iVar13 = iVar14;
            }
            piVar2[6] = iVar13;
          }
          iVar14 = piVar2[5] + -1;
          piVar2[5] = iVar14;
          piVar2[0x110] = iVar9 + 2;
          if (iVar10 == iVar9 + 2) goto LAB_000d6961;
          uVar18 = (uint)(byte)(iVar14 == 1 ^ (byte)iVar12);
          if (uVar18 == piVar2[0xf]) {
            piVar2[3] = 3;
            uVar18 = piVar2[0xe];
            uVar11 = 0x100;
            uVar16 = 0;
            do {
              uVar15 = (int)(uVar11 + uVar16) >> 1;
              if ((int)uVar18 < piVar2[uVar15 + 0x111]) {
                uVar11 = uVar15;
                uVar15 = uVar16;
              }
              uVar16 = uVar15;
            } while (uVar11 - uVar16 != 1);
            piVar2[0xe] = (*(byte *)(iVar17 + (uVar18 >> 1)) >> ((char)uVar18 * '\x04' & 4U) & 0xf)
                          << 0x10 | (uint)*(ushort *)(iVar19 + uVar18 * 2);
            if (iVar14 == 0) {
              piVar2[5] = (&BZ2_rNums)[piVar2[6]];
              iVar12 = piVar2[6] + 1;
              iVar14 = 0;
              if (iVar12 != 0x200) {
                iVar14 = iVar12;
              }
              piVar2[6] = iVar14;
            }
            iVar12 = piVar2[5] + -1;
            piVar2[5] = iVar12;
            piVar2[0x110] = iVar9 + 3;
            if (iVar10 == iVar9 + 3) goto LAB_000d6961;
            uVar18 = (iVar12 == 1 ^ uVar16) & 0xff;
            if (uVar18 == piVar2[0xf]) {
              uVar18 = piVar2[0xe];
              local_38 = (byte *)0x100;
              iVar10 = 0;
              do {
                iVar14 = (int)local_38 + iVar10 >> 1;
                pbVar7 = (byte *)iVar14;
                if (piVar2[iVar14 + 0x111] <= (int)uVar18) {
                  pbVar7 = local_38;
                  iVar10 = iVar14;
                }
                local_38 = pbVar7;
              } while ((int)pbVar7 - iVar10 != 1);
              uVar16 = (uint)*(ushort *)(iVar19 + uVar18 * 2);
              uVar18 = (*(byte *)(iVar17 + (uVar18 >> 1)) >> ((char)uVar18 * '\x04' & 4U) & 0xf) <<
                       0x10 | uVar16;
              piVar2[0xe] = uVar18;
              if (iVar12 == 0) {
                piVar2[5] = (&BZ2_rNums)[piVar2[6]];
                iVar14 = piVar2[6] + 1;
                iVar12 = 0;
                if (iVar14 != 0x200) {
                  iVar12 = iVar14;
                }
                piVar2[6] = iVar12;
              }
              iVar12 = piVar2[5] + -1;
              piVar2[5] = iVar12;
              piVar2[0x110] = iVar9 + 4;
              piVar2[3] = (byte)(iVar12 == 1 ^ (byte)iVar10) + 4;
              local_38 = (byte *)0x100;
              uVar11 = 0;
              do {
                uVar15 = (int)((int)local_38 + uVar11) >> 1;
                pbVar7 = (byte *)uVar15;
                if (piVar2[uVar15 + 0x111] <= (int)uVar18) {
                  pbVar7 = local_38;
                  uVar11 = uVar15;
                }
                local_38 = pbVar7;
              } while ((int)pbVar7 - uVar11 != 1);
              piVar2[0xf] = uVar11;
              piVar2[0xe] = (*(byte *)(iVar17 + (uVar18 >> 1)) >> (sbyte)((uVar16 & 1) << 2) & 0xf)
                            << 0x10 | (uint)*(ushort *)(iVar19 + uVar18 * 2);
              if (iVar12 == 0) {
                piVar2[5] = (&BZ2_rNums)[piVar2[6]];
                iVar12 = piVar2[6] + 1;
                iVar10 = 0;
                if (iVar12 != 0x200) {
                  iVar10 = iVar12;
                }
                piVar2[6] = iVar10;
              }
              iVar10 = piVar2[5];
              piVar2[5] = iVar10 + -1;
              piVar2[0xf] = iVar10 + -1 == 1 ^ uVar11;
              piVar2[0x110] = iVar9 + 5;
              goto LAB_000d6961;
            }
          }
        }
        piVar2[0xf] = uVar18;
      }
    }
    else {
      **(undefined1 **)(iVar4 + 0x10) = (char)piVar2[2];
      piVar2[0x318] =
           piVar2[0x318] << 8 ^
           *(uint *)(BZ2_crc32Table +
                    ((uint)*(byte *)(piVar2 + 2) ^ (uint)piVar2[0x318] >> 0x18) * 4);
      piVar2[3] = piVar2[3] + -1;
      iVar4 = *piVar2;
      *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
      *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + -1;
      iVar9 = *(int *)(iVar4 + 0x18) + 1;
      *(int *)(iVar4 + 0x18) = iVar9;
      if (iVar9 == 0) {
        *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 1;
      }
    }
    goto LAB_000d6961;
  }
  goto LAB_000d6680;
LAB_000d63c2:
  if (*(int *)(iVar4 + 0x14) != 0) {
    if (piVar2[3] == 0) {
      iVar9 = piVar2[0x110];
      iVar10 = piVar2[0x3e90] + 1;
      if (iVar9 == iVar10) goto LAB_000d64e1;
      piVar2[3] = 1;
      uVar18 = piVar2[0xf];
      *(char *)(piVar2 + 2) = (char)uVar18;
      uVar16 = piVar2[0xe];
      uVar15 = 0x100;
      uVar11 = 0;
      do {
        uVar5 = (int)(uVar15 + uVar11) >> 1;
        if ((int)uVar16 < piVar2[uVar5 + 0x111]) {
          uVar15 = uVar5;
          uVar5 = uVar11;
        }
        uVar11 = uVar5;
      } while (uVar15 - uVar11 != 1);
      iVar12 = piVar2[0x314];
      iVar17 = piVar2[0x315];
      uVar1 = *(ushort *)(iVar12 + uVar16 * 2);
      uVar16 = (*(byte *)(iVar17 + (uVar16 >> 1)) >> (((byte)uVar16 & 1) << 2) & 0xf) << 0x10 |
               (uint)uVar1;
      piVar2[0xe] = uVar16;
      piVar2[0x110] = iVar9 + 1;
      if (iVar10 != iVar9 + 1) {
        if (uVar18 == (uVar11 & 0xff)) {
          piVar2[3] = 2;
          uVar15 = 0x100;
          uVar11 = 0;
          do {
            uVar5 = (int)(uVar15 + uVar11) >> 1;
            if ((int)uVar16 < piVar2[uVar5 + 0x111]) {
              uVar15 = uVar5;
              uVar5 = uVar11;
            }
            uVar11 = uVar5;
          } while (uVar15 - uVar11 != 1);
          uVar15 = (uint)*(ushort *)(iVar12 + uVar16 * 2);
          uVar16 = (*(byte *)(iVar17 + (uVar16 >> 1)) >> ((char)uVar1 * '\x04' & 4U) & 0xf) << 0x10
                   | uVar15;
          piVar2[0xe] = uVar16;
          piVar2[0x110] = iVar9 + 2;
          if (iVar10 != iVar9 + 2) {
            if (uVar18 == (uVar11 & 0xff)) {
              piVar2[3] = 3;
              uVar5 = 0x100;
              uVar11 = 0;
              do {
                uVar8 = (int)(uVar5 + uVar11) >> 1;
                if ((int)uVar16 < piVar2[uVar8 + 0x111]) {
                  uVar5 = uVar8;
                  uVar8 = uVar11;
                }
                uVar11 = uVar8;
              } while (uVar5 - uVar11 != 1);
              uVar1 = *(ushort *)(iVar12 + uVar16 * 2);
              uVar16 = (*(byte *)(iVar17 + (uVar16 >> 1)) >> (sbyte)((uVar15 & 1) << 2) & 0xf) <<
                       0x10 | (uint)uVar1;
              piVar2[0xe] = uVar16;
              piVar2[0x110] = iVar9 + 3;
              if (iVar10 != iVar9 + 3) {
                if (uVar18 == (uVar11 & 0xff)) {
                  uVar11 = 0x100;
                  uVar18 = 0;
                  do {
                    uVar15 = (int)(uVar11 + uVar18) >> 1;
                    if ((int)uVar16 < piVar2[uVar15 + 0x111]) {
                      uVar11 = uVar15;
                      uVar15 = uVar18;
                    }
                    uVar18 = uVar15;
                  } while (uVar11 - uVar18 != 1);
                  uVar11 = (uint)*(ushort *)(iVar12 + uVar16 * 2);
                  uVar16 = (*(byte *)(iVar17 + (uVar16 >> 1)) >> ((char)uVar1 * '\x04' & 4U) & 0xf)
                           << 0x10 | uVar11;
                  piVar2[0xe] = uVar16;
                  piVar2[0x110] = iVar9 + 4;
                  piVar2[3] = (uVar18 & 0xff) + 4;
                  iVar19 = 0x100;
                  iVar10 = 0;
                  do {
                    iVar14 = iVar19 + iVar10 >> 1;
                    if ((int)uVar16 < piVar2[iVar14 + 0x111]) {
                      iVar19 = iVar14;
                      iVar14 = iVar10;
                    }
                    iVar10 = iVar14;
                  } while (iVar19 - iVar10 != 1);
                  piVar2[0xf] = iVar10;
                  piVar2[0xe] = (*(byte *)(iVar17 + (uVar16 >> 1)) >> (sbyte)((uVar11 & 1) << 2) &
                                0xf) << 0x10 | (uint)*(ushort *)(iVar12 + uVar16 * 2);
                  piVar2[0x110] = iVar9 + 5;
                }
                else {
                  piVar2[0xf] = uVar11 & 0xff;
                }
              }
            }
            else {
              piVar2[0xf] = uVar11 & 0xff;
            }
          }
        }
        else {
          piVar2[0xf] = uVar11 & 0xff;
        }
      }
    }
    else {
      **(undefined1 **)(iVar4 + 0x10) = (char)piVar2[2];
      piVar2[0x318] =
           piVar2[0x318] << 8 ^
           *(uint *)(BZ2_crc32Table +
                    ((uint)*(byte *)(piVar2 + 2) ^ (uint)piVar2[0x318] >> 0x18) * 4);
      piVar2[3] = piVar2[3] + -1;
      iVar4 = *piVar2;
      *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
      *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + -1;
      iVar9 = *(int *)(iVar4 + 0x18) + 1;
      *(int *)(iVar4 + 0x18) = iVar9;
      if (iVar9 == 0) {
        *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 1;
      }
    }
    goto LAB_000d63c2;
  }
LAB_000d6680:
  if (piVar2[0x110] == piVar2[0x3e90] + 1) {
LAB_000d64e1:
    if (piVar2[3] == 0) {
      uVar18 = piVar2[0x318];
      piVar2[0x318] = ~uVar18;
      if (2 < piVar2[0xc]) {
        fprintf(_stderr," {0x%x, 0x%x}",piVar2[0x316],~uVar18);
      }
      if (1 < piVar2[0xc]) {
        fputc(0x5d,_stderr);
      }
      if (piVar2[0x318] != piVar2[0x316]) {
        return -4;
      }
      piVar2[0x319] = (piVar2[0x319] << 1 | (uint)(piVar2[0x319] < 0)) ^ piVar2[0x318];
      piVar2[1] = 0xe;
LAB_000d6547:
      iVar4 = BZ2_decompress(piVar2);
      if (iVar4 == 4) {
        if (2 < piVar2[0xc]) {
          fprintf(_stderr,"\n    combined CRCs: stored = 0x%x, computed = 0x%x",piVar2[0x317],
                  piVar2[0x319]);
        }
        if (piVar2[0x319] == piVar2[0x317]) {
          return 4;
        }
        return -4;
      }
      if (piVar2[1] != 2) {
        return iVar4;
      }
      goto LAB_000d638f;
    }
  }
  return 0;
}


// BZ2_bzDecompressEnd  @ 000d712f
undefined4 BZ2_bzDecompressEnd(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0xfffffffe;
  if (((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x20), piVar1 != (int *)0x0)) &&
     (*piVar1 == param_1)) {
    if (piVar1[0x313] != 0) {
      (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),piVar1[0x313]);
    }
    if (piVar1[0x314] != 0) {
      (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),piVar1[0x314]);
    }
    if (piVar1[0x315] != 0) {
      (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),piVar1[0x315]);
    }
    (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
    uVar2 = 0;
  }
  return uVar2;
}


// BZ2_bzDecompressInit  @ 000d6247
undefined4 BZ2_bzDecompressInit(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = 0xfffffffe;
  if (((param_1 != 0) && (param_3 < 2)) && (param_2 < 5)) {
    if (*(int *)(param_1 + 0x24) == 0) {
      *(code **)(param_1 + 0x24) = default_bzalloc;
    }
    if (*(int *)(param_1 + 0x28) == 0) {
      *(code **)(param_1 + 0x28) = default_bzfree;
    }
    piVar2 = (int *)(**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x2c),0xfa74,1);
    uVar1 = 0xfffffffd;
    if (piVar2 != (int *)0x0) {
      *piVar2 = param_1;
      *(int **)(param_1 + 0x20) = piVar2;
      piVar2[1] = 10;
      piVar2[8] = 0;
      piVar2[7] = 0;
      piVar2[0x319] = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(char *)(piVar2 + 10) = (char)param_3;
      piVar2[0x315] = 0;
      piVar2[0x314] = 0;
      piVar2[0x313] = 0;
      piVar2[0xb] = 0;
      piVar2[0xc] = param_2;
      uVar1 = 0;
    }
  }
  return uVar1;
}


// BZ2_bzRead  @ 000d7b83
int BZ2_bzRead(int *param_1,undefined4 *param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  
  if (param_1 != (int *)0x0) {
    *param_1 = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    param_2[0x4f1] = 0;
  }
  if (((param_3 == 0) || (param_2 == (undefined4 *)0x0)) || (param_4 < 0)) {
    if (param_1 != (int *)0x0) {
      *param_1 = -2;
    }
    if (param_2 != (undefined4 *)0x0) {
      param_2[0x4f1] = 0xfffffffe;
    }
    return 0;
  }
  if (*(char *)(param_2 + 0x4e4) != '\0') {
    if (param_1 != (int *)0x0) {
      *param_1 = -1;
    }
    param_2[0x4f1] = 0xffffffff;
    return 0;
  }
  if (param_4 != 0) {
    param_2[0x4ea] = param_4;
    param_2[0x4e9] = param_3;
    do {
      iVar2 = ferror((FILE *)*param_2);
      if (iVar2 != 0) {
LAB_000d7d36:
        if (param_1 != (int *)0x0) {
          *param_1 = -6;
        }
        param_2[0x4f1] = 0xfffffffa;
        return 0;
      }
      if ((param_2[0x4e6] == 0) && (cVar1 = myfeof(), cVar1 == '\0')) {
        sVar3 = fread(param_2 + 1,1,5000,(FILE *)*param_2);
        iVar2 = ferror((FILE *)*param_2);
        if (iVar2 != 0) goto LAB_000d7d36;
        param_2[0x4e3] = sVar3;
        param_2[0x4e6] = sVar3;
        param_2[0x4e5] = param_2 + 1;
      }
      iVar2 = BZ2_bzDecompress(param_2 + 0x4e5);
      if ((iVar2 != 4) && (iVar2 != 0)) {
        if (param_1 != (int *)0x0) {
          *param_1 = iVar2;
        }
        param_2[0x4f1] = iVar2;
        return 0;
      }
      if (iVar2 == 0) {
        cVar1 = myfeof();
        if ((cVar1 != '\0') && (param_2[0x4e6] == 0)) {
          if (param_2[0x4ea] != 0) {
            if (param_1 != (int *)0x0) {
              *param_1 = -7;
            }
            param_2[0x4f1] = 0xfffffff9;
            return 0;
          }
          break;
        }
      }
      else if (iVar2 == 4) {
        if (param_1 != (int *)0x0) {
          *param_1 = 4;
        }
        param_2[0x4f1] = 4;
        return param_4 - param_2[0x4ea];
      }
    } while (param_2[0x4ea] != 0);
  }
  if (param_1 != (int *)0x0) {
    *param_1 = 0;
  }
  param_2[0x4f1] = 0;
  return param_4;
}


// BZ2_bzReadClose  @ 000d7afd
void BZ2_bzReadClose(undefined4 *param_1,void *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
  }
  if (param_2 == (void *)0x0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = 0;
      return;
    }
  }
  else {
    *(undefined4 *)((int)param_2 + 0x13c4) = 0;
    if (*(char *)((int)param_2 + 0x1390) == '\0') {
      if (*(char *)((int)param_2 + 0x13c8) == '\0') {
        free(param_2);
        return;
      }
      BZ2_bzDecompressEnd((int)param_2 + 0x1394);
      free(param_2);
      return;
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = 0xffffffff;
    }
    *(undefined4 *)((int)param_2 + 0x13c4) = 0xffffffff;
  }
  return;
}


// BZ2_bzReadGetUnused  @ 000d7d8b
void BZ2_bzReadGetUnused(undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_2 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = 0xfffffffe;
      return;
    }
  }
  else {
    if (*(int *)(param_2 + 0x13c4) == 4) {
      if ((param_4 != (undefined4 *)0x0) && (param_3 != (undefined4 *)0x0)) {
        if (param_1 != (undefined4 *)0x0) {
          *param_1 = 0;
        }
        *(undefined4 *)(param_2 + 0x13c4) = 0;
        *param_4 = *(undefined4 *)(param_2 + 0x1398);
        *param_3 = *(undefined4 *)(param_2 + 0x1394);
        return;
      }
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = 0xfffffffe;
      }
      *(undefined4 *)(param_2 + 0x13c4) = 0xfffffffe;
      return;
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = 0xffffffff;
    }
    *(undefined4 *)(param_2 + 0x13c4) = 0xffffffff;
  }
  return;
}


// BZ2_bzReadOpen  @ 000d7720
undefined4 *
BZ2_bzReadOpen(int *param_1,FILE *param_2,uint param_3,uint param_4,int param_5,uint param_6)

{
  int iVar1;
  undefined4 *__ptr;
  uint uVar2;
  
  if (param_1 != (int *)0x0) {
    *param_1 = 0;
  }
  if ((((param_4 < 2) && (param_2 != (FILE *)0x0)) && (param_3 < 5)) &&
     (((param_6 == 0 || (param_5 != 0)) && ((param_6 < 0x1389 || (param_5 == 0)))))) {
    iVar1 = ferror(param_2);
    if (iVar1 == 0) {
      __ptr = malloc(0x13cc);
      if (__ptr == (undefined4 *)0x0) {
        __ptr = (undefined4 *)0x0;
        if (param_1 != (int *)0x0) {
          *param_1 = -3;
        }
      }
      else {
        if (param_1 != (int *)0x0) {
          *param_1 = 0;
        }
        __ptr[0x4f1] = 0;
        *(undefined1 *)(__ptr + 0x4f2) = 0;
        *__ptr = param_2;
        __ptr[0x4e3] = 0;
        *(undefined1 *)(__ptr + 0x4e4) = 0;
        __ptr[0x4ee] = 0;
        __ptr[0x4ef] = 0;
        __ptr[0x4f0] = 0;
        if (0 < (int)param_6) {
          uVar2 = 0;
          do {
            *(undefined1 *)((int)__ptr + uVar2 + 4) = *(undefined1 *)(param_5 + uVar2);
            uVar2 = uVar2 + 1;
            __ptr[0x4e3] = uVar2;
          } while (uVar2 != param_6);
        }
        iVar1 = BZ2_bzDecompressInit(__ptr + 0x4e5,param_3,param_4);
        if (iVar1 == 0) {
          __ptr[0x4e6] = __ptr[0x4e3];
          __ptr[0x4e5] = __ptr + 1;
          *(undefined1 *)(__ptr + 0x4f2) = 1;
        }
        else {
          if (param_1 != (int *)0x0) {
            *param_1 = iVar1;
          }
          __ptr[0x4f1] = iVar1;
          free(__ptr);
          __ptr = (undefined4 *)0x0;
        }
      }
    }
    else {
      __ptr = (undefined4 *)0x0;
      if (param_1 != (int *)0x0) {
        *param_1 = -6;
      }
    }
  }
  else {
    __ptr = (undefined4 *)0x0;
    if (param_1 != (int *)0x0) {
      *param_1 = -2;
      return __ptr;
    }
  }
  return __ptr;
}


// BZ2_bzWrite  @ 000d7303
void BZ2_bzWrite(int *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  size_t sVar2;
  size_t __n;
  
  if (param_1 != (int *)0x0) {
    *param_1 = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    param_2[0x4f1] = 0;
  }
  if (((param_3 == 0) || (param_2 == (undefined4 *)0x0)) || (param_4 < 0)) {
    if (param_1 != (int *)0x0) {
      *param_1 = -2;
    }
    if (param_2 != (undefined4 *)0x0) {
      param_2[0x4f1] = 0xfffffffe;
    }
  }
  else {
    if (*(char *)(param_2 + 0x4e4) == '\0') {
      if (param_1 != (int *)0x0) {
        *param_1 = -1;
      }
      param_2[0x4f1] = 0xffffffff;
      return;
    }
    iVar1 = ferror((FILE *)*param_2);
    if (iVar1 == 0) {
      if (param_4 != 0) {
        param_2[0x4e6] = param_4;
        param_2[0x4e5] = param_3;
        do {
          param_2[0x4ea] = 5000;
          param_2[0x4e9] = param_2 + 1;
          iVar1 = BZ2_bzCompress(param_2 + 0x4e5,0);
          if (iVar1 != 1) {
            if (param_1 != (int *)0x0) {
              *param_1 = iVar1;
            }
            param_2[0x4f1] = iVar1;
            return;
          }
          if (((uint)param_2[0x4ea] < 5000) &&
             ((__n = 5000 - param_2[0x4ea], sVar2 = fwrite(param_2 + 1,1,__n,(FILE *)*param_2),
              __n != sVar2 || (iVar1 = ferror((FILE *)*param_2), iVar1 != 0)))) goto LAB_000d742f;
        } while (param_2[0x4e6] != 0);
      }
      if (param_1 != (int *)0x0) {
        *param_1 = 0;
      }
      param_2[0x4f1] = 0;
    }
    else {
LAB_000d742f:
      if (param_1 != (int *)0x0) {
        *param_1 = -6;
      }
      param_2[0x4f1] = 0xfffffffa;
    }
  }
  return;
}


// BZ2_bzWriteClose  @ 000d76dd
void BZ2_bzWriteClose(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5)

{
  BZ2_bzWriteClose64(param_1,param_2,param_3,param_4,0,param_5,0);
  return;
}


// BZ2_bzWriteClose64  @ 000d7472
void BZ2_bzWriteClose64(int *param_1,undefined4 *param_2,int param_3,undefined4 *param_4,
                       undefined4 *param_5,undefined4 *param_6,undefined4 *param_7)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  size_t __n;
  
  if (param_2 == (undefined4 *)0x0) {
    if (param_1 != (int *)0x0) {
      *param_1 = 0;
      return;
    }
  }
  else {
    if (*(char *)(param_2 + 0x4e4) != '\0') {
      iVar1 = ferror((FILE *)*param_2);
      if (iVar1 == 0) {
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = 0;
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = 0;
        }
        if (param_6 != (undefined4 *)0x0) {
          *param_6 = 0;
        }
        if (param_7 != (undefined4 *)0x0) {
          *param_7 = 0;
        }
        if (param_3 == 0) {
          if (param_2[0x4f1] == 0) {
            do {
              param_2[0x4ea] = 5000;
              param_2[0x4e9] = param_2 + 1;
              iVar1 = BZ2_bzCompress(param_2 + 0x4e5,2);
              if (1 < iVar1 - 3U) {
                if (param_1 != (int *)0x0) {
                  *param_1 = iVar1;
                }
                param_2[0x4f1] = iVar1;
                return;
              }
              if (((uint)param_2[0x4ea] < 5000) &&
                 ((__n = 5000 - param_2[0x4ea], sVar2 = fwrite(param_2 + 1,1,__n,(FILE *)*param_2),
                  __n != sVar2 || (iVar3 = ferror((FILE *)*param_2), iVar3 != 0))))
              goto joined_r0x000d75d3;
            } while (iVar1 != 4);
          }
          iVar1 = ferror((FILE *)*param_2);
          if (iVar1 == 0) {
            fflush((FILE *)*param_2);
            iVar1 = ferror((FILE *)*param_2);
            if (iVar1 != 0) goto joined_r0x000d75d3;
          }
        }
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = param_2[0x4e7];
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = param_2[0x4e8];
        }
        if (param_6 != (undefined4 *)0x0) {
          *param_6 = param_2[0x4eb];
        }
        if (param_7 != (undefined4 *)0x0) {
          *param_7 = param_2[0x4ec];
        }
        if (param_1 != (int *)0x0) {
          *param_1 = 0;
        }
        param_2[0x4f1] = 0;
        BZ2_bzCompressEnd(param_2 + 0x4e5);
        free(param_2);
        return;
      }
joined_r0x000d75d3:
      if (param_1 != (int *)0x0) {
        *param_1 = -6;
      }
      param_2[0x4f1] = 0xfffffffa;
      return;
    }
    if (param_1 != (int *)0x0) {
      *param_1 = -1;
    }
    param_2[0x4f1] = 0xffffffff;
  }
  return;
}


// BZ2_bzWriteOpen  @ 000d71b2
undefined4 * BZ2_bzWriteOpen(int *param_1,FILE *param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined4 *__ptr;
  
  if (param_1 != (int *)0x0) {
    *param_1 = 0;
  }
  if ((((param_2 == (FILE *)0x0) || (0xfa < param_5)) || (8 < param_3 - 1U)) || (4 < param_4)) {
    __ptr = (undefined4 *)0x0;
    if (param_1 != (int *)0x0) {
      *param_1 = -2;
      return __ptr;
    }
  }
  else {
    iVar1 = ferror(param_2);
    if (iVar1 == 0) {
      __ptr = malloc(0x13cc);
      if (__ptr == (undefined4 *)0x0) {
        __ptr = (undefined4 *)0x0;
        if (param_1 != (int *)0x0) {
          *param_1 = -3;
        }
      }
      else {
        if (param_1 != (int *)0x0) {
          *param_1 = 0;
        }
        __ptr[0x4f1] = 0;
        *(undefined1 *)(__ptr + 0x4f2) = 0;
        __ptr[0x4e3] = 0;
        *__ptr = param_2;
        *(undefined1 *)(__ptr + 0x4e4) = 1;
        __ptr[0x4ee] = 0;
        __ptr[0x4ef] = 0;
        __ptr[0x4f0] = 0;
        if (param_5 == 0) {
          param_5 = 0x1e;
        }
        iVar1 = BZ2_bzCompressInit(__ptr + 0x4e5,param_3,param_4,param_5);
        if (iVar1 == 0) {
          __ptr[0x4e6] = 0;
          *(undefined1 *)(__ptr + 0x4f2) = 1;
        }
        else {
          if (param_1 != (int *)0x0) {
            *param_1 = iVar1;
          }
          __ptr[0x4f1] = iVar1;
          free(__ptr);
          __ptr = (undefined4 *)0x0;
        }
      }
    }
    else {
      __ptr = (undefined4 *)0x0;
      if (param_1 != (int *)0x0) {
        *param_1 = -6;
      }
    }
  }
  return __ptr;
}


// BZ2_bz__AssertH__fail  @ 000d5dba
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BZ2_bz__AssertH__fail(int param_1)

{
  fprintf(_stderr,
          "\n\nbzip2/libbzip2: internal error number %d.\nThis is a bug in bzip2/libbzip2, %s.\nPlease report it to me at: jseward@acm.org.  If this happened\nwhen you were using some program which uses libbzip2 as a\ncomponent, you should also report this bug to the author(s)\nof that program.  Please make an effort to report this bug;\ntimely and accurate bug reports eventually lead to higher\nquality software.  Thanks.  Julian Seward, 30 December 2001.\n\n"
          ,param_1,"1.0.2, 30-Dec-2001");
  if (param_1 == 0x3ef) {
    fwrite("\n*** A special note about internal error number 1007 ***\n\nExperience suggests that a common cause of i.e. 1007\nis unreliable memory or other hardware.  The 1007 assertion\njust happens to cross-check the results of huge numbers of\nmemory reads/writes, and so acts (unintendedly) as a stress\ntest of your memory system.\n\nI suggest the following: try compressing the file again,\npossibly monitoring progress in detail with the -vv flag.\n\n* If the error cannot be reproduced, and/or happens at different\n  points in compression, you may have a flaky memory system.\n  Try a memory-test program.  I have used Memtest86\n  (www.memtest86.com).  At the time of writing it is free (GPLd).\n  Memtest86 tests memory much more thorougly than your BIOSs\n  power-on test, and may find failures that the BIOS doesn\'t.\n\n* If the error can be repeatably reproduced, this is a bug in\n  bzip2, and I would very much like to hear about it.  Please\n  let me know, and, ideally, save a copy of the file causing the\n  problem -- without which I will be unable to investigate it.\n\n"
           ,1,0x420,_stderr);
  }
                    /* WARNING: Subroutine does not return */
  exit(3);
}


// BZ2_bzclose  @ 000d8100
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BZ2_bzclose(undefined4 *param_1)

{
  FILE *__stream;
  int local_10 [2];
  
  __stream = (FILE *)*param_1;
  if (*(char *)(param_1 + 0x4e4) == '\0') {
    BZ2_bzReadClose(local_10,param_1);
  }
  else {
    BZ2_bzWriteClose(local_10,param_1,0,0,0);
    if (local_10[0] != 0) {
      BZ2_bzWriteClose(0,param_1,1,0,0);
    }
  }
  if ((__stream != _stdin) && (__stream != _stdout)) {
    fclose(__stream);
  }
  return;
}


// BZ2_bzdopen  @ 000d8058
void BZ2_bzdopen(void)

{
  undefined4 uStack00000004;
  
  uStack00000004 = 1;
  bzopen_or_bzdopen();
  return;
}


// BZ2_bzerror  @ 000d819e
undefined * BZ2_bzerror(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x13c4) < 1) {
    iVar1 = *(int *)(param_1 + 0x13c4);
  }
  *param_2 = iVar1;
  return (&bzerrorstrings)[-iVar1];
}


// BZ2_bzflush  @ 000d80fd
undefined4 BZ2_bzflush(void)

{
  return 0;
}


// BZ2_bzlibVersion  @ 000d8032
char * BZ2_bzlibVersion(void)

{
  return "1.0.2, 30-Dec-2001";
}


// BZ2_bzopen  @ 000d8038
void BZ2_bzopen(void)

{
  undefined4 uStack00000004;
  
  uStack00000004 = 0;
  bzopen_or_bzdopen();
  return;
}


// BZ2_bzread  @ 000d8075
undefined4 BZ2_bzread(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int local_10 [4];
  
  uVar1 = 0;
  if (((*(int *)(param_1 + 0x13c4) != 4) &&
      (uVar1 = BZ2_bzRead(local_10,param_1,param_2,param_3), local_10[0] != 4)) &&
     (local_10[0] != 0)) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// BZ2_bzwrite  @ 000d80c0
undefined4 BZ2_bzwrite(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int local_10 [3];
  
  BZ2_bzWrite(local_10,param_1,param_2,param_3);
  if (local_10[0] != 0) {
    param_3 = 0xffffffff;
  }
  return param_3;
}


// BZ2_compressBlock  @ 000d83ec
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BZ2_compressBlock(int param_1,char param_2)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  int iVar47;
  int iVar48;
  int *piVar49;
  char cVar50;
  char cVar51;
  byte bVar52;
  int iVar53;
  char cVar54;
  uint uVar55;
  int iVar56;
  int iVar57;
  int iVar58;
  int iVar59;
  uint uVar60;
  int iVar61;
  int iVar62;
  int iVar63;
  undefined1 *puVar64;
  undefined4 *puVar65;
  byte *pbVar66;
  int iVar67;
  uint uVar68;
  uint uVar69;
  uint uVar70;
  uint uVar71;
  uint uVar72;
  uint uVar73;
  uint uVar74;
  uint uVar75;
  uint uVar76;
  uint uVar77;
  uint uVar78;
  uint uVar79;
  uint uVar80;
  uint uVar81;
  uint uVar82;
  uint uVar83;
  uint uVar84;
  uint uVar85;
  uint uVar86;
  uint uVar87;
  uint uVar88;
  uint uVar89;
  uint uVar90;
  uint uVar91;
  uint uVar92;
  uint uVar93;
  uint uVar94;
  uint uVar95;
  uint uVar96;
  uint uVar97;
  uint uVar98;
  uint uVar99;
  uint uVar100;
  uint uVar101;
  uint uVar102;
  uint uVar103;
  uint uVar104;
  uint uVar105;
  uint uVar106;
  uint uVar107;
  uint uVar108;
  uint uVar109;
  uint uVar110;
  uint uVar111;
  uint uVar112;
  uint uVar113;
  uint uVar114;
  byte bVar115;
  int iVar116;
  char *pcVar117;
  uint uVar118;
  byte bVar119;
  int local_184;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
  int local_160;
  uint local_15c;
  int local_154;
  undefined4 local_138;
  char local_38 [16];
  int local_28;
  int local_24;
  undefined4 local_20;
  
  iVar58 = *(int *)(param_1 + 0x44);
  if (0 < iVar58) {
    uVar60 = ~*(uint *)(param_1 + 0x260);
    *(uint *)(param_1 + 0x260) = uVar60;
    uVar55 = (*(int *)(param_1 + 0x264) << 1 | (uint)(*(int *)(param_1 + 0x264) < 0)) ^ uVar60;
    *(uint *)(param_1 + 0x264) = uVar55;
    if (1 < *(int *)(param_1 + 0x26c)) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
    }
    if (1 < *(int *)(param_1 + 0x268)) {
      fprintf(_stderr,"    block %d: crc = 0x%8x, combined CRC = 0x%8x, size = %d\n",
              *(int *)(param_1 + 0x26c),uVar60,uVar55,iVar58);
    }
    BZ2_blockSort(param_1);
    iVar58 = *(int *)(param_1 + 0x44);
  }
  *(int *)(param_1 + 0x2c) = iVar58 + *(int *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x26c) == 1) {
    *(undefined4 *)(param_1 + 0x25c) = 0;
    *(undefined4 *)(param_1 + 600) = 0;
    bsPutUChar();
    bsPutUChar();
    bsPutUChar();
    bsPutUChar();
  }
  if (0 < *(int *)(param_1 + 0x44)) {
    bsPutUChar();
    bsPutUChar();
    bsPutUChar();
    bsPutUChar();
    bsPutUChar();
    bsPutUChar();
    bsPutUInt32();
    while (7 < *(int *)(param_1 + 0x25c)) {
      *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
           *(undefined1 *)(param_1 + 0x25b);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
      *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
    }
    *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;
    iVar58 = *(int *)(param_1 + 0x1c);
    while (iVar59 = *(int *)(param_1 + 0x25c), 7 < iVar59) {
      *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
           *(undefined1 *)(param_1 + 0x25b);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
      *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
    }
    *(uint *)(param_1 + 600) = *(uint *)(param_1 + 600) | iVar58 << (8U - (char)iVar59 & 0x1f);
    *(int *)(param_1 + 0x25c) = iVar59 + 0x18;
    iVar58 = *(int *)(param_1 + 0x20);
    iVar59 = *(int *)(param_1 + 0x24);
    iVar53 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x54) = 0;
    local_154 = param_1;
    iVar56 = 0;
    iVar61 = param_1;
    do {
      if (*(char *)(iVar61 + 0x58) != '\0') {
        *(char *)(iVar61 + 0x158) = (char)iVar56;
        iVar56 = iVar56 + 1;
        *(int *)(param_1 + 0x54) = iVar56;
      }
      iVar61 = iVar61 + 1;
    } while (iVar61 != param_1 + 0x100);
    iVar61 = iVar56 + 1;
    if (-1 < iVar61) {
      iVar62 = 0;
      do {
        *(undefined4 *)(param_1 + 0x278 + iVar62 * 4) = 0;
        iVar62 = iVar62 + 1;
      } while (iVar62 <= iVar61);
    }
    if (0 < iVar56) {
      iVar62 = 0;
      do {
        *(char *)((int)&local_138 + iVar62) = (char)iVar62;
        iVar62 = iVar62 + 1;
      } while (iVar62 != iVar56);
    }
    iVar62 = *(int *)(param_1 + 0x44);
    iVar63 = 0;
    iVar116 = 0;
    for (iVar67 = 0; cVar51 = local_138._1_1_, iVar67 < iVar62; iVar67 = iVar67 + 1) {
      iVar57 = *(int *)(iVar58 + iVar67 * 4) + -1;
      if (iVar57 < 0) {
        iVar57 = iVar57 + iVar62;
      }
      cVar50 = *(char *)(param_1 + 0x158 + (uint)*(byte *)(iVar59 + iVar57));
      if (cVar50 == (char)local_138) {
        iVar116 = iVar116 + 1;
      }
      else {
        if (iVar116 != 0) {
          uVar55 = iVar116 - 1;
          while( true ) {
            iVar63 = iVar63 + 1;
            if ((uVar55 & 1) == 0) {
              *(undefined2 *)(iVar53 + -2 + iVar63 * 2) = 0;
              *(int *)(param_1 + 0x278) = *(int *)(param_1 + 0x278) + 1;
            }
            else {
              *(undefined2 *)(iVar53 + -2 + iVar63 * 2) = 1;
              *(int *)(param_1 + 0x27c) = *(int *)(param_1 + 0x27c) + 1;
            }
            if ((int)uVar55 < 2) break;
            uVar55 = (int)(uVar55 - 2) >> 1;
          }
        }
        local_138._1_1_ = (char)local_138;
        pcVar117 = (char *)((int)&local_138 + 1);
        if (cVar50 != cVar51) {
          pcVar117 = (char *)((int)&local_138 + 1);
          cVar54 = cVar51;
          do {
            pcVar117 = pcVar117 + 1;
            cVar51 = *pcVar117;
            *pcVar117 = cVar54;
            cVar54 = cVar51;
          } while (cVar50 != cVar51);
        }
        local_138._0_1_ = cVar51;
        *(short *)(iVar53 + iVar63 * 2) = (short)((int)pcVar117 - (int)&local_138) + 1;
        iVar63 = iVar63 + 1;
        piVar49 = (int *)(param_1 + 0x27c + ((int)pcVar117 - (int)&local_138) * 4);
        *piVar49 = *piVar49 + 1;
        iVar116 = 0;
      }
    }
    if (iVar116 != 0) {
      uVar55 = iVar116 - 1;
      while( true ) {
        iVar63 = iVar63 + 1;
        if ((uVar55 & 1) == 0) {
          *(undefined2 *)(iVar53 + -2 + iVar63 * 2) = 0;
          *(int *)(param_1 + 0x278) = *(int *)(param_1 + 0x278) + 1;
        }
        else {
          *(undefined2 *)(iVar53 + -2 + iVar63 * 2) = 1;
          *(int *)(param_1 + 0x27c) = *(int *)(param_1 + 0x27c) + 1;
        }
        if ((int)uVar55 < 2) break;
        uVar55 = (int)(uVar55 - 2) >> 1;
      }
    }
    local_184._0_2_ = (undefined2)iVar61;
    *(undefined2 *)(iVar53 + iVar63 * 2) = (undefined2)local_184;
    piVar49 = (int *)(param_1 + 0x278 + iVar61 * 4);
    *piVar49 = *piVar49 + 1;
    *(int *)(param_1 + 0x274) = iVar63 + 1;
    if (2 < *(int *)(param_1 + 0x268)) {
      fprintf(_stderr,"      %d in block, %d after MTF & 1-2 coding, %d+2 syms in use\n",iVar62,
              iVar63 + 1,iVar56);
      iVar56 = *(int *)(param_1 + 0x54);
    }
    iVar58 = iVar56 + 2;
    iVar59 = 0;
    do {
      if (0 < iVar58) {
        puVar64 = (undefined1 *)(param_1 + 0x9324 + iVar59 * 0x102);
        iVar61 = 0;
        do {
          *puVar64 = 0xf;
          iVar61 = iVar61 + 1;
          puVar64 = puVar64 + 1;
        } while (iVar61 < iVar58);
      }
      iVar59 = iVar59 + 1;
    } while (iVar59 != 6);
    if (*(int *)(param_1 + 0x274) < 1) {
      BZ2_bz__AssertH__fail(0xbb9);
    }
    local_184 = *(int *)(param_1 + 0x274);
    local_15c = 2;
    if (((199 < local_184) && (local_15c = 3, 599 < local_184)) &&
       (local_15c = 4, 0x4af < local_184)) {
      local_15c = (0x95f < local_184) + 5;
    }
    local_170 = 0;
    uVar55 = local_15c;
    do {
      iVar59 = local_170 + -1;
      iVar61 = 0;
      if (0 < local_184 / (int)uVar55) {
        do {
          if (iVar56 + 1 <= iVar59) break;
          iVar59 = iVar59 + 1;
          iVar61 = iVar61 + *(int *)(param_1 + 0x278 + iVar59 * 4);
        } while (iVar61 < local_184 / (int)uVar55);
      }
      if (((local_170 < iVar59) && (uVar55 != local_15c)) &&
         ((uVar55 != 1 && ((int)(local_15c - uVar55) % 2 == 1)))) {
        iVar61 = iVar61 - *(int *)(param_1 + 0x278 + iVar59 * 4);
        iVar59 = iVar59 + -1;
      }
      if (2 < *(int *)(param_1 + 0x268)) {
        fprintf(_stderr,"      initial group %d, [%d .. %d], has %d syms (%4.1f%%)\n",uVar55,
                local_170,iVar59,iVar61,
                (double)(((float)iVar61 * 100.0) / (float)*(int *)(param_1 + 0x274)));
      }
      uVar55 = uVar55 - 1;
      if (0 < iVar58) {
        puVar64 = (undefined1 *)(param_1 + 0x9324 + uVar55 * 0x102);
        iVar62 = 0;
        do {
          while ((iVar59 < iVar62 || (iVar62 < local_170))) {
            *puVar64 = 0xf;
            iVar62 = iVar62 + 1;
            puVar64 = puVar64 + 1;
            if (iVar58 <= iVar62) goto LAB_000d8acc;
          }
          *puVar64 = 0;
          iVar62 = iVar62 + 1;
          puVar64 = puVar64 + 1;
        } while (iVar62 < iVar58);
      }
LAB_000d8acc:
      if ((int)uVar55 < 1) goto LAB_000d8b28;
      local_170 = iVar59 + 1;
      local_184 = local_184 - iVar61;
    } while( true );
  }
LAB_000d8763:
  if (param_2 != '\0') {
    bsPutUChar();
    bsPutUChar();
    bsPutUChar();
    bsPutUChar();
    bsPutUChar();
    bsPutUChar();
    bsPutUInt32();
    if (1 < *(int *)(param_1 + 0x268)) {
      fprintf(_stderr,"    final combined CRC = 0x%x\n   ",*(undefined4 *)(param_1 + 0x264));
    }
    while (0 < *(int *)(param_1 + 0x25c)) {
      *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
           *(undefined1 *)(param_1 + 0x25b);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
      *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
    }
  }
  return;
LAB_000d8b28:
  local_16c = 1;
  iVar59 = param_1 + 0x9324;
  do {
    iVar56 = 0;
    do {
      (&local_138)[iVar56] = 0;
      iVar56 = iVar56 + 1;
    } while (iVar56 < (int)local_15c);
    iVar56 = 0;
    do {
      if (0 < iVar58) {
        puVar65 = (undefined4 *)(param_1 + 0xb160 + iVar56 * 0x408);
        iVar61 = 0;
        do {
          *puVar65 = 0;
          iVar61 = iVar61 + 1;
          puVar65 = puVar65 + 1;
        } while (iVar61 < iVar58);
      }
      iVar56 = iVar56 + 1;
    } while (iVar56 < (int)local_15c);
    if ((local_15c == 6) && (iVar56 = param_1, iVar61 = param_1, 0 < iVar58)) {
      do {
        *(uint *)(iVar61 + 0xc990) =
             (uint)*(byte *)(iVar56 + 0x9426) << 0x10 | (uint)*(byte *)(iVar56 + 0x9324);
        *(uint *)(iVar61 + 0xc994) =
             (uint)*(byte *)(iVar56 + 0x962a) << 0x10 | (uint)*(byte *)(iVar56 + 0x9528);
        *(uint *)(iVar61 + 0xc998) =
             (uint)*(byte *)(iVar56 + 0x982e) << 0x10 | (uint)*(byte *)(iVar56 + 0x972c);
        iVar56 = iVar56 + 1;
        iVar61 = iVar61 + 0x10;
      } while (iVar56 != iVar58 + param_1);
    }
    iVar56 = *(int *)(param_1 + 0x274);
    if (iVar56 < 1) {
      local_160 = 0;
      local_17c = 0;
    }
    else {
      local_160 = 0;
      local_17c = 0;
      iVar61 = 0;
      do {
        iVar62 = iVar61 + 0x31;
        iVar63 = iVar62;
        if (iVar56 <= iVar62) {
          iVar63 = iVar56 + -1;
        }
        iVar67 = 0;
        do {
          *(undefined2 *)((int)&local_28 + iVar67 * 2) = 0;
          iVar67 = iVar67 + 1;
        } while (iVar67 < (int)local_15c);
        iVar67 = iVar61;
        if ((local_15c == 6) && (iVar63 - iVar61 == 0x31)) {
          uVar60 = (uint)*(ushort *)(iVar53 + iVar61 * 2);
          uVar55 = (uint)*(ushort *)(iVar53 + 2 + iVar61 * 2);
          iVar67 = param_1 + uVar55 * 0x10;
          iVar116 = param_1 + uVar60 * 0x10;
          uVar118 = (uint)*(ushort *)(iVar53 + 4 + iVar61 * 2);
          iVar57 = param_1 + uVar118 * 0x10;
          uVar68 = (uint)*(ushort *)(iVar53 + 6 + iVar61 * 2);
          iVar2 = param_1 + uVar68 * 0x10;
          uVar69 = (uint)*(ushort *)(iVar53 + 8 + iVar61 * 2);
          iVar3 = param_1 + uVar69 * 0x10;
          uVar70 = (uint)*(ushort *)(iVar53 + 10 + iVar61 * 2);
          iVar4 = param_1 + uVar70 * 0x10;
          uVar71 = (uint)*(ushort *)(iVar53 + 0xc + iVar61 * 2);
          iVar5 = param_1 + uVar71 * 0x10;
          uVar72 = (uint)*(ushort *)(iVar53 + 0xe + iVar61 * 2);
          iVar6 = param_1 + uVar72 * 0x10;
          uVar73 = (uint)*(ushort *)(iVar53 + 0x10 + iVar61 * 2);
          iVar7 = param_1 + uVar73 * 0x10;
          uVar74 = (uint)*(ushort *)(iVar53 + 0x12 + iVar61 * 2);
          iVar8 = param_1 + uVar74 * 0x10;
          uVar75 = (uint)*(ushort *)(iVar53 + 0x14 + iVar61 * 2);
          iVar9 = param_1 + uVar75 * 0x10;
          uVar76 = (uint)*(ushort *)(iVar53 + 0x16 + iVar61 * 2);
          iVar10 = param_1 + uVar76 * 0x10;
          uVar77 = (uint)*(ushort *)(iVar53 + 0x18 + iVar61 * 2);
          iVar11 = param_1 + uVar77 * 0x10;
          uVar78 = (uint)*(ushort *)(iVar53 + 0x1a + iVar61 * 2);
          iVar12 = param_1 + uVar78 * 0x10;
          uVar79 = (uint)*(ushort *)(iVar53 + 0x1c + iVar61 * 2);
          iVar13 = param_1 + uVar79 * 0x10;
          uVar80 = (uint)*(ushort *)(iVar53 + 0x1e + iVar61 * 2);
          iVar14 = param_1 + uVar80 * 0x10;
          uVar81 = (uint)*(ushort *)(iVar53 + 0x20 + iVar61 * 2);
          iVar15 = param_1 + uVar81 * 0x10;
          uVar82 = (uint)*(ushort *)(iVar53 + 0x22 + iVar61 * 2);
          iVar16 = param_1 + uVar82 * 0x10;
          uVar83 = (uint)*(ushort *)(iVar53 + 0x24 + iVar61 * 2);
          iVar17 = param_1 + uVar83 * 0x10;
          uVar84 = (uint)*(ushort *)(iVar53 + 0x26 + iVar61 * 2);
          iVar18 = param_1 + uVar84 * 0x10;
          uVar85 = (uint)*(ushort *)(iVar53 + 0x28 + iVar61 * 2);
          iVar19 = param_1 + uVar85 * 0x10;
          uVar86 = (uint)*(ushort *)(iVar53 + 0x2a + iVar61 * 2);
          iVar20 = param_1 + uVar86 * 0x10;
          uVar87 = (uint)*(ushort *)(iVar53 + 0x2c + iVar61 * 2);
          iVar21 = param_1 + uVar87 * 0x10;
          uVar88 = (uint)*(ushort *)(iVar53 + 0x2e + iVar61 * 2);
          iVar22 = param_1 + uVar88 * 0x10;
          uVar89 = (uint)*(ushort *)(iVar53 + 0x30 + iVar61 * 2);
          iVar23 = param_1 + uVar89 * 0x10;
          uVar90 = (uint)*(ushort *)(iVar53 + 0x32 + iVar61 * 2);
          iVar24 = param_1 + uVar90 * 0x10;
          uVar91 = (uint)*(ushort *)(iVar53 + 0x34 + iVar61 * 2);
          iVar25 = param_1 + uVar91 * 0x10;
          uVar92 = (uint)*(ushort *)(iVar53 + 0x36 + iVar61 * 2);
          iVar26 = param_1 + uVar92 * 0x10;
          uVar93 = (uint)*(ushort *)(iVar53 + 0x38 + iVar61 * 2);
          iVar27 = param_1 + uVar93 * 0x10;
          uVar94 = (uint)*(ushort *)(iVar53 + 0x3a + iVar61 * 2);
          iVar28 = param_1 + uVar94 * 0x10;
          uVar95 = (uint)*(ushort *)(iVar53 + 0x3c + iVar61 * 2);
          iVar29 = param_1 + uVar95 * 0x10;
          uVar96 = (uint)*(ushort *)(iVar53 + 0x3e + iVar61 * 2);
          iVar30 = param_1 + uVar96 * 0x10;
          uVar97 = (uint)*(ushort *)(iVar53 + 0x40 + iVar61 * 2);
          iVar31 = param_1 + uVar97 * 0x10;
          uVar98 = (uint)*(ushort *)(iVar53 + 0x42 + iVar61 * 2);
          iVar32 = param_1 + uVar98 * 0x10;
          uVar99 = (uint)*(ushort *)(iVar53 + 0x44 + iVar61 * 2);
          iVar33 = param_1 + uVar99 * 0x10;
          uVar100 = (uint)*(ushort *)(iVar53 + 0x46 + iVar61 * 2);
          iVar34 = param_1 + uVar100 * 0x10;
          uVar101 = (uint)*(ushort *)(iVar53 + 0x48 + iVar61 * 2);
          iVar35 = param_1 + uVar101 * 0x10;
          uVar102 = (uint)*(ushort *)(iVar53 + 0x4a + iVar61 * 2);
          iVar36 = param_1 + uVar102 * 0x10;
          uVar103 = (uint)*(ushort *)(iVar53 + 0x4c + iVar61 * 2);
          iVar37 = param_1 + uVar103 * 0x10;
          uVar104 = (uint)*(ushort *)(iVar53 + 0x4e + iVar61 * 2);
          iVar38 = param_1 + uVar104 * 0x10;
          uVar105 = (uint)*(ushort *)(iVar53 + 0x50 + iVar61 * 2);
          iVar39 = param_1 + uVar105 * 0x10;
          uVar106 = (uint)*(ushort *)(iVar53 + 0x52 + iVar61 * 2);
          iVar40 = param_1 + uVar106 * 0x10;
          uVar107 = (uint)*(ushort *)(iVar53 + 0x54 + iVar61 * 2);
          iVar41 = param_1 + uVar107 * 0x10;
          uVar108 = (uint)*(ushort *)(iVar53 + 0x56 + iVar61 * 2);
          iVar42 = param_1 + uVar108 * 0x10;
          uVar109 = (uint)*(ushort *)(iVar53 + 0x58 + iVar61 * 2);
          iVar43 = param_1 + uVar109 * 0x10;
          uVar110 = (uint)*(ushort *)(iVar53 + 0x5a + iVar61 * 2);
          iVar44 = param_1 + uVar110 * 0x10;
          uVar111 = (uint)*(ushort *)(iVar53 + 0x5c + iVar61 * 2);
          iVar45 = param_1 + uVar111 * 0x10;
          uVar112 = (uint)*(ushort *)(iVar53 + 0x5e + iVar61 * 2);
          iVar46 = param_1 + uVar112 * 0x10;
          uVar113 = (uint)*(ushort *)(iVar53 + 0x60 + iVar61 * 2);
          iVar47 = param_1 + uVar113 * 0x10;
          uVar114 = (uint)*(ushort *)(iVar53 + iVar62 * 2);
          iVar48 = param_1 + uVar114 * 0x10;
          local_20 = *(int *)(iVar67 + 0xc998) + *(int *)(iVar116 + 0xc998) +
                     *(int *)(iVar57 + 0xc998) + *(int *)(iVar2 + 0xc998) + *(int *)(iVar3 + 0xc998)
                     + *(int *)(iVar4 + 0xc998) + *(int *)(iVar5 + 0xc998) +
                     *(int *)(iVar6 + 0xc998) + *(int *)(iVar7 + 0xc998) + *(int *)(iVar8 + 0xc998)
                     + *(int *)(iVar9 + 0xc998) + *(int *)(iVar10 + 0xc998) +
                     *(int *)(iVar11 + 0xc998) + *(int *)(iVar12 + 0xc998) +
                     *(int *)(iVar13 + 0xc998) + *(int *)(iVar14 + 0xc998) +
                     *(int *)(iVar15 + 0xc998) + *(int *)(iVar16 + 0xc998) +
                     *(int *)(iVar17 + 0xc998) + *(int *)(iVar18 + 0xc998) +
                     *(int *)(iVar19 + 0xc998) + *(int *)(iVar20 + 0xc998) +
                     *(int *)(iVar21 + 0xc998) + *(int *)(iVar22 + 0xc998) +
                     *(int *)(iVar23 + 0xc998) + *(int *)(iVar24 + 0xc998) +
                     *(int *)(iVar25 + 0xc998) + *(int *)(iVar26 + 0xc998) +
                     *(int *)(iVar27 + 0xc998) + *(int *)(iVar28 + 0xc998) +
                     *(int *)(iVar29 + 0xc998) + *(int *)(iVar30 + 0xc998) +
                     *(int *)(iVar31 + 0xc998) + *(int *)(iVar32 + 0xc998) +
                     *(int *)(iVar33 + 0xc998) + *(int *)(iVar34 + 0xc998) +
                     *(int *)(iVar35 + 0xc998) + *(int *)(iVar36 + 0xc998) +
                     *(int *)(iVar37 + 0xc998) + *(int *)(iVar38 + 0xc998) +
                     *(int *)(iVar39 + 0xc998) + *(int *)(iVar40 + 0xc998) +
                     *(int *)(iVar41 + 0xc998) + *(int *)(iVar42 + 0xc998) +
                     *(int *)(iVar43 + 0xc998) + *(int *)(iVar44 + 0xc998) +
                     *(int *)(iVar45 + 0xc998) + *(int *)(iVar46 + 0xc998) +
                     *(int *)(iVar47 + 0xc998) + *(int *)(iVar48 + 0xc998);
          local_28 = *(int *)(param_1 + 0xc990 + uVar55 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar60 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar118 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar68 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar69 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar70 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar71 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar72 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar73 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar74 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar75 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar76 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar77 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar78 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar79 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar80 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar81 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar82 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar83 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar84 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar85 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar86 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar87 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar88 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar89 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar90 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar91 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar92 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar93 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar94 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar95 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar96 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar97 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar98 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar99 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar100 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar101 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar102 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar103 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar104 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar105 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar106 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar107 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar108 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar109 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar110 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar111 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar112 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar113 * 0x10) +
                     *(int *)(param_1 + 0xc990 + uVar114 * 0x10);
          local_24 = *(int *)(iVar67 + 0xc994) + *(int *)(iVar116 + 0xc994) +
                     *(int *)(iVar57 + 0xc994) + *(int *)(iVar2 + 0xc994) + *(int *)(iVar3 + 0xc994)
                     + *(int *)(iVar4 + 0xc994) + *(int *)(iVar5 + 0xc994) +
                     *(int *)(iVar6 + 0xc994) + *(int *)(iVar7 + 0xc994) + *(int *)(iVar8 + 0xc994)
                     + *(int *)(iVar9 + 0xc994) + *(int *)(iVar10 + 0xc994) +
                     *(int *)(iVar11 + 0xc994) + *(int *)(iVar12 + 0xc994) +
                     *(int *)(iVar13 + 0xc994) + *(int *)(iVar14 + 0xc994) +
                     *(int *)(iVar15 + 0xc994) + *(int *)(iVar16 + 0xc994) +
                     *(int *)(iVar17 + 0xc994) + *(int *)(iVar18 + 0xc994) +
                     *(int *)(iVar19 + 0xc994) + *(int *)(iVar20 + 0xc994) +
                     *(int *)(iVar21 + 0xc994) + *(int *)(iVar22 + 0xc994) +
                     *(int *)(iVar23 + 0xc994) + *(int *)(iVar24 + 0xc994) +
                     *(int *)(iVar25 + 0xc994) + *(int *)(iVar26 + 0xc994) +
                     *(int *)(iVar27 + 0xc994) + *(int *)(iVar28 + 0xc994) +
                     *(int *)(iVar29 + 0xc994) + *(int *)(iVar30 + 0xc994) +
                     *(int *)(iVar31 + 0xc994) + *(int *)(iVar32 + 0xc994) +
                     *(int *)(iVar33 + 0xc994) + *(int *)(iVar34 + 0xc994) +
                     *(int *)(iVar35 + 0xc994) + *(int *)(iVar36 + 0xc994) +
                     *(int *)(iVar37 + 0xc994) + *(int *)(iVar38 + 0xc994) +
                     *(int *)(iVar39 + 0xc994) + *(int *)(iVar40 + 0xc994) +
                     *(int *)(iVar41 + 0xc994) + *(int *)(iVar42 + 0xc994) +
                     *(int *)(iVar43 + 0xc994) + *(int *)(iVar44 + 0xc994) +
                     *(int *)(iVar45 + 0xc994) + *(int *)(iVar46 + 0xc994) +
                     *(int *)(iVar47 + 0xc994) + *(int *)(iVar48 + 0xc994);
        }
        else {
          for (; iVar67 <= iVar63; iVar67 = iVar67 + 1) {
            pbVar66 = (byte *)(param_1 + 0x9324 + (uint)*(ushort *)(iVar53 + iVar67 * 2));
            iVar116 = 0;
            do {
              psVar1 = (short *)((int)&local_28 + iVar116 * 2);
              *psVar1 = *psVar1 + (ushort)*pbVar66;
              iVar116 = iVar116 + 1;
              pbVar66 = pbVar66 + 0x102;
            } while (iVar116 < (int)local_15c);
          }
        }
        local_184 = -1;
        uVar55 = 999999999;
        iVar67 = 0;
        do {
          uVar60 = (uint)*(ushort *)((int)&local_28 + iVar67 * 2);
          if (uVar60 < uVar55) {
            uVar55 = uVar60;
            local_184 = iVar67;
          }
          iVar67 = iVar67 + 1;
        } while (iVar67 < (int)local_15c);
        local_17c = local_17c + uVar55;
        (&local_138)[local_184] = (&local_138)[local_184] + 1;
        *(byte *)(param_1 + 0x680 + local_160) = (byte)local_184;
        local_160 = local_160 + 1;
        if ((local_15c == 6) && (iVar63 - iVar61 == 0x31)) {
          local_184 = local_184 * 0x102;
          piVar49 = (int *)(param_1 + (*(ushort *)(iVar53 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 2 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 4 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 6 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 8 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 10 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0xc + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0xe + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x10 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x12 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x14 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x16 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x18 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x1a + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x1c + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x1e + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x20 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x22 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x24 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x26 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x28 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x2a + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x2c + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x2e + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x30 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x32 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x34 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x36 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x38 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x3a + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x3c + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x3e + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x40 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x42 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x44 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x46 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x48 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x4a + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x4c + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x4e + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x50 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x52 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x54 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x56 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x58 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x5a + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x5c + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x5e + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 +
                           (*(ushort *)(iVar53 + 0x60 + iVar61 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
          piVar49 = (int *)(param_1 + (*(ushort *)(iVar53 + iVar62 * 2) + 0x2c58 + local_184) * 4);
          *piVar49 = *piVar49 + 1;
        }
        else if (iVar61 <= iVar63) {
          do {
            piVar49 = (int *)(param_1 + 0xb160 +
                             (local_184 * 0x102 + (uint)*(ushort *)(iVar53 + iVar61 * 2)) * 4);
            *piVar49 = *piVar49 + 1;
            iVar61 = iVar61 + 1;
          } while (iVar61 <= iVar63);
        }
        iVar61 = iVar63 + 1;
      } while (iVar61 < iVar56);
    }
    if (2 < *(int *)(param_1 + 0x268)) {
      local_17c = local_17c >> 3;
      fprintf(_stderr,"      pass %d: size is %d, grp uses are ",local_16c,local_17c);
      iVar56 = 0;
      do {
        fprintf(_stderr,"%d ",(&local_138)[iVar56],local_17c);
        iVar56 = iVar56 + 1;
      } while (iVar56 < (int)local_15c);
      fputc(10,_stderr);
    }
    iVar62 = 0;
    iVar61 = 0;
    iVar56 = 0;
    do {
      BZ2_hbMakeCodeLengths(iVar59 + iVar62,param_1 + 0xb160 + iVar61,iVar58,0x14);
      iVar56 = iVar56 + 1;
      iVar61 = iVar61 + 0x408;
      iVar62 = iVar62 + 0x102;
    } while (iVar56 < (int)local_15c);
    local_16c = local_16c + 1;
  } while (local_16c != 5);
  if (0x4652 < local_160) {
    BZ2_bz__AssertH__fail(0xbbb);
  }
  iVar56 = 0;
  do {
    local_38[iVar56] = (char)iVar56;
    iVar56 = iVar56 + 1;
  } while (iVar56 < (int)local_15c);
  if (local_160 != 0) {
    iVar56 = 0;
    do {
      cVar51 = *(char *)(param_1 + 0x680 + iVar56);
      iVar61 = 0;
      while (cVar51 != local_38[0]) {
        cVar50 = local_38[iVar61 + 1];
        local_38[iVar61 + 1] = local_38[0];
        iVar61 = iVar61 + 1;
        local_38[0] = cVar50;
      }
      *(char *)(param_1 + 0x4cd2 + iVar56) = (char)iVar61;
      iVar56 = iVar56 + 1;
    } while (iVar56 != local_160);
  }
  local_174 = 0;
  local_184 = 0;
  local_168 = iVar59;
  do {
    if (iVar58 < 1) {
      bVar119 = 0x20;
      bVar115 = 0;
    }
    else {
      pbVar66 = (byte *)(param_1 + 0x9324 + local_184 * 0x102);
      bVar119 = 0x20;
      bVar115 = 0;
      iVar56 = 0;
      do {
        bVar52 = *pbVar66;
        if (bVar115 < bVar52) {
          bVar115 = bVar52;
        }
        if (bVar52 < bVar119) {
          bVar119 = bVar52;
        }
        iVar56 = iVar56 + 1;
        pbVar66 = pbVar66 + 1;
      } while (iVar56 < iVar58);
      if (0x14 < bVar115) {
        BZ2_bz__AssertH__fail(0xbbc);
      }
      if (bVar119 == 0) {
        BZ2_bz__AssertH__fail(0xbbd);
      }
    }
    BZ2_hbAssignCodes(param_1 + 0x9930 + local_174,local_168,bVar119,bVar115,iVar58);
    local_184 = local_184 + 1;
    local_174 = local_174 + 0x408;
    local_168 = local_168 + 0x102;
  } while (local_184 < (int)local_15c);
  iVar56 = 0;
  do {
    local_38[iVar56] = '\0';
    pcVar117 = (char *)(param_1 + 0x58 + iVar56 * 0x10);
    iVar61 = 0;
    do {
      if (*pcVar117 != '\0') {
        local_38[iVar56] = '\x01';
      }
      iVar61 = iVar61 + 1;
      pcVar117 = pcVar117 + 1;
    } while (iVar61 != 0x10);
    iVar56 = iVar56 + 1;
  } while (iVar56 != 0x10);
  iVar56 = *(int *)(param_1 + 0x4c);
  iVar62 = 0;
  iVar61 = iVar56;
  do {
    if (local_38[iVar62] == '\0') {
      iVar63 = *(int *)(param_1 + 0x25c);
      if (7 < iVar63) {
        iVar67 = *(int *)(param_1 + 600);
        do {
          *(char *)(*(int *)(param_1 + 0x2c) + iVar61) = (char)((uint)iVar67 >> 0x18);
          iVar61 = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 0x4c) = iVar61;
          iVar67 = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 600) = iVar67;
          iVar63 = *(int *)(param_1 + 0x25c) + -8;
          *(int *)(param_1 + 0x25c) = iVar63;
        } while (7 < iVar63);
      }
      *(int *)(param_1 + 0x25c) = iVar63 + 1;
    }
    else {
      iVar63 = *(int *)(param_1 + 0x25c);
      if (7 < iVar63) {
        iVar67 = *(int *)(param_1 + 600);
        do {
          *(char *)(*(int *)(param_1 + 0x2c) + iVar61) = (char)((uint)iVar67 >> 0x18);
          iVar61 = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 0x4c) = iVar61;
          iVar67 = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 600) = iVar67;
          iVar63 = *(int *)(param_1 + 0x25c) + -8;
          *(int *)(param_1 + 0x25c) = iVar63;
        } while (7 < iVar63);
      }
      local_184._0_1_ = 0x1f - (char)iVar63;
      *(uint *)(param_1 + 600) = *(uint *)(param_1 + 600) | 1 << ((byte)local_184 & 0x1f);
      *(int *)(param_1 + 0x25c) = iVar63 + 1;
    }
    iVar62 = iVar62 + 1;
  } while (iVar62 != 0x10);
  iVar62 = 0;
  do {
    if (local_38[iVar62] != '\0') {
      pcVar117 = (char *)(param_1 + 0x58 + iVar62 * 0x10);
      local_184 = 0;
      do {
        if (*pcVar117 == '\0') {
          iVar63 = *(int *)(param_1 + 0x25c);
          if (7 < iVar63) {
            iVar67 = *(int *)(param_1 + 600);
            do {
              *(char *)(*(int *)(param_1 + 0x2c) + iVar61) = (char)((uint)iVar67 >> 0x18);
              iVar61 = *(int *)(param_1 + 0x4c) + 1;
              *(int *)(param_1 + 0x4c) = iVar61;
              iVar67 = *(int *)(param_1 + 600) << 8;
              *(int *)(param_1 + 600) = iVar67;
              iVar63 = *(int *)(param_1 + 0x25c) + -8;
              *(int *)(param_1 + 0x25c) = iVar63;
            } while (7 < iVar63);
          }
          *(int *)(param_1 + 0x25c) = iVar63 + 1;
        }
        else {
          local_178 = *(int *)(param_1 + 0x25c);
          if (7 < local_178) {
            iVar63 = *(int *)(param_1 + 600);
            do {
              *(char *)(*(int *)(param_1 + 0x2c) + iVar61) = (char)((uint)iVar63 >> 0x18);
              iVar61 = *(int *)(param_1 + 0x4c) + 1;
              *(int *)(param_1 + 0x4c) = iVar61;
              iVar63 = *(int *)(param_1 + 600) << 8;
              *(int *)(param_1 + 600) = iVar63;
              local_178 = *(int *)(param_1 + 0x25c) + -8;
              *(int *)(param_1 + 0x25c) = local_178;
            } while (7 < local_178);
          }
          *(uint *)(param_1 + 600) =
               *(uint *)(param_1 + 600) | 1 << (0x1fU - (char)local_178 & 0x1f);
          *(int *)(param_1 + 0x25c) = local_178 + 1;
        }
        local_184 = local_184 + 1;
        pcVar117 = pcVar117 + 1;
      } while (local_184 != 0x10);
    }
    iVar62 = iVar62 + 1;
  } while (iVar62 != 0x10);
  local_174 = iVar61;
  if (2 < *(int *)(param_1 + 0x268)) {
    fprintf(_stderr,"      bytes: mapping %d, ",iVar61 - iVar56);
    iVar61 = *(int *)(param_1 + 0x4c);
    local_174 = iVar61;
  }
  while (iVar62 = local_174, iVar56 = *(int *)(param_1 + 0x25c), 7 < iVar56) {
    *(undefined1 *)(*(int *)(param_1 + 0x2c) + iVar61) = *(undefined1 *)(param_1 + 0x25b);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
    *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
    *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
    iVar61 = *(int *)(param_1 + 0x4c);
  }
  *(uint *)(param_1 + 600) = *(uint *)(param_1 + 600) | local_15c << (0x1dU - (char)iVar56 & 0x1f);
  *(int *)(param_1 + 0x25c) = iVar56 + 3;
  while (iVar56 = *(int *)(param_1 + 0x25c), 7 < iVar56) {
    *(undefined1 *)(*(int *)(param_1 + 0x2c) + iVar61) = *(undefined1 *)(param_1 + 0x25b);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
    *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
    *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
    iVar61 = *(int *)(param_1 + 0x4c);
  }
  *(uint *)(param_1 + 600) = *(uint *)(param_1 + 600) | local_160 << (0x11U - (char)iVar56 & 0x1f);
  iVar56 = iVar56 + 0xf;
  *(int *)(param_1 + 0x25c) = iVar56;
  local_174 = iVar61;
  if (local_160 != 0) {
    iVar63 = param_1;
    while( true ) {
      if (*(char *)(iVar63 + 0x4cd2) != '\0') {
        uVar55 = *(uint *)(param_1 + 600);
        iVar67 = 0;
        while( true ) {
          while (7 < iVar56) {
            *(char *)(*(int *)(param_1 + 0x2c) + iVar61) = (char)(uVar55 >> 0x18);
            iVar61 = *(int *)(param_1 + 0x4c) + 1;
            *(int *)(param_1 + 0x4c) = iVar61;
            uVar55 = *(int *)(param_1 + 600) << 8;
            *(uint *)(param_1 + 600) = uVar55;
            iVar56 = *(int *)(param_1 + 0x25c) + -8;
            *(int *)(param_1 + 0x25c) = iVar56;
          }
          local_17c._0_1_ = 0x1f - (char)iVar56;
          uVar55 = uVar55 | 1 << ((byte)local_17c & 0x1f);
          *(uint *)(param_1 + 600) = uVar55;
          iVar56 = iVar56 + 1;
          *(int *)(param_1 + 0x25c) = iVar56;
          iVar67 = iVar67 + 1;
          if ((int)(uint)*(byte *)(iVar63 + 0x4cd2) <= iVar67) break;
          iVar61 = *(int *)(param_1 + 0x4c);
        }
      }
      if (7 < iVar56) {
        iVar67 = *(int *)(param_1 + 600);
        do {
          *(char *)(*(int *)(param_1 + 0x2c) + iVar61) = (char)((uint)iVar67 >> 0x18);
          iVar61 = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 0x4c) = iVar61;
          iVar67 = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 600) = iVar67;
          iVar56 = *(int *)(param_1 + 0x25c) + -8;
          *(int *)(param_1 + 0x25c) = iVar56;
        } while (7 < iVar56);
      }
      iVar56 = iVar56 + 1;
      *(int *)(param_1 + 0x25c) = iVar56;
      iVar63 = iVar63 + 1;
      if (iVar63 == local_160 + param_1) break;
      iVar61 = *(int *)(param_1 + 0x4c);
    }
    local_174 = *(int *)(param_1 + 0x4c);
  }
  if (2 < *(int *)(param_1 + 0x268)) {
    fprintf(_stderr,"selectors %d, ",local_174 - iVar62);
    local_174 = *(int *)(param_1 + 0x4c);
  }
  iVar56 = local_174;
  local_168 = 0;
  do {
    uVar55 = (uint)*(byte *)(local_154 + 0x9324);
    iVar61 = *(int *)(param_1 + 0x25c);
    if (7 < iVar61) {
      while( true ) {
        *(undefined1 *)(*(int *)(param_1 + 0x2c) + local_174) = *(undefined1 *)(param_1 + 0x25b);
        *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
        *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
        iVar61 = *(int *)(param_1 + 0x25c) + -8;
        *(int *)(param_1 + 0x25c) = iVar61;
        if (iVar61 < 8) break;
        local_174 = *(int *)(param_1 + 0x4c);
      }
      local_174 = *(int *)(param_1 + 0x4c);
    }
    *(uint *)(param_1 + 600) = *(uint *)(param_1 + 600) | uVar55 << (0x1bU - (char)iVar61 & 0x1f);
    iVar61 = iVar61 + 5;
    *(int *)(param_1 + 0x25c) = iVar61;
    if (0 < iVar58) {
      pbVar66 = (byte *)(param_1 + 0x9324 + local_168 * 0x102);
      local_184 = 0;
      while( true ) {
        uVar60 = (uint)*pbVar66;
        if ((int)uVar55 < (int)uVar60) {
          uVar118 = *(uint *)(param_1 + 600);
          while( true ) {
            while (7 < iVar61) {
              *(char *)(*(int *)(param_1 + 0x2c) + local_174) = (char)(uVar118 >> 0x18);
              local_174 = *(int *)(param_1 + 0x4c) + 1;
              *(int *)(param_1 + 0x4c) = local_174;
              uVar118 = *(int *)(param_1 + 600) << 8;
              *(uint *)(param_1 + 600) = uVar118;
              iVar61 = *(int *)(param_1 + 0x25c) + -8;
              *(int *)(param_1 + 0x25c) = iVar61;
            }
            local_178._0_1_ = 0x1e - (char)iVar61;
            uVar118 = uVar118 | 2 << ((byte)local_178 & 0x1f);
            *(uint *)(param_1 + 600) = uVar118;
            iVar61 = iVar61 + 2;
            *(int *)(param_1 + 0x25c) = iVar61;
            uVar55 = uVar55 + 1;
            uVar60 = (uint)*pbVar66;
            if ((int)uVar60 <= (int)uVar55) break;
            local_174 = *(int *)(param_1 + 0x4c);
          }
        }
        if ((int)uVar60 < (int)uVar55) {
          uVar60 = *(uint *)(param_1 + 600);
          while( true ) {
            while (7 < iVar61) {
              *(char *)(*(int *)(param_1 + 0x2c) + local_174) = (char)(uVar60 >> 0x18);
              local_174 = *(int *)(param_1 + 0x4c) + 1;
              *(int *)(param_1 + 0x4c) = local_174;
              uVar60 = *(int *)(param_1 + 600) << 8;
              *(uint *)(param_1 + 600) = uVar60;
              iVar61 = *(int *)(param_1 + 0x25c) + -8;
              *(int *)(param_1 + 0x25c) = iVar61;
            }
            uVar60 = uVar60 | 3 << (0x1eU - (char)iVar61 & 0x1f);
            *(uint *)(param_1 + 600) = uVar60;
            iVar61 = iVar61 + 2;
            *(int *)(param_1 + 0x25c) = iVar61;
            uVar55 = uVar55 - 1;
            if ((int)uVar55 <= (int)(uint)*pbVar66) break;
            local_174 = *(int *)(param_1 + 0x4c);
          }
        }
        else {
          iVar61 = *(int *)(param_1 + 0x25c);
        }
        if (7 < iVar61) {
          iVar62 = *(int *)(param_1 + 0x4c);
          iVar63 = *(int *)(param_1 + 600);
          do {
            *(char *)(*(int *)(param_1 + 0x2c) + iVar62) = (char)((uint)iVar63 >> 0x18);
            iVar62 = *(int *)(param_1 + 0x4c) + 1;
            *(int *)(param_1 + 0x4c) = iVar62;
            iVar63 = *(int *)(param_1 + 600) << 8;
            *(int *)(param_1 + 600) = iVar63;
            iVar61 = *(int *)(param_1 + 0x25c) + -8;
            *(int *)(param_1 + 0x25c) = iVar61;
          } while (7 < iVar61);
        }
        iVar61 = iVar61 + 1;
        *(int *)(param_1 + 0x25c) = iVar61;
        local_184 = local_184 + 1;
        pbVar66 = pbVar66 + 1;
        if (iVar58 <= local_184) break;
        local_174 = *(int *)(param_1 + 0x4c);
      }
      local_174 = *(int *)(param_1 + 0x4c);
    }
    local_168 = local_168 + 1;
    local_154 = local_154 + 0x102;
  } while (local_168 < (int)local_15c);
  if (2 < *(int *)(param_1 + 0x268)) {
    fprintf(_stderr,"code lengths %d, ",local_174 - iVar56);
    local_174 = *(int *)(param_1 + 0x4c);
  }
  iVar58 = *(int *)(param_1 + 0x274);
  local_184 = 0;
  if (0 < iVar58) {
    iVar56 = 0;
    do {
      iVar61 = iVar56 + 0x31;
      iVar62 = iVar58 + -1;
      if (iVar61 < iVar58) {
        iVar62 = iVar61;
      }
      if (local_15c <= *(byte *)(param_1 + 0x680 + local_184)) {
        BZ2_bz__AssertH__fail(0xbbe);
      }
      if ((local_15c == 6) && (iVar62 - iVar56 == 0x31)) {
        uVar55 = (uint)*(byte *)(param_1 + 0x680 + local_184);
        iVar63 = uVar55 * 0x102 + iVar59;
        iVar67 = uVar55 * 0x408 + param_1 + 0x9930;
        uVar55 = (uint)*(ushort *)(iVar53 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 2 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 4 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 6 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 8 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 10 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0xc + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0xe + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x10 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x12 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x14 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x16 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x18 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x1a + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x1c + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x1e + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x20 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x22 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x24 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x26 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x28 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x2a + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x2c + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x2e + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x30 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x32 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x34 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x36 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x38 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x3a + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x3c + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x3e + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x40 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x42 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x44 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x46 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x48 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x4a + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x4c + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x4e + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x50 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x52 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x54 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x56 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x58 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x5a + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x5c + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x5e + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar116 = *(int *)(param_1 + 0x25c), 7 < iVar116) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar116) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar116 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + 0x60 + iVar56 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar56 = *(int *)(param_1 + 0x25c), 7 < iVar56) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar56) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar56 + (uint)bVar115;
        uVar55 = (uint)*(ushort *)(iVar53 + iVar61 * 2);
        iVar58 = *(int *)(iVar67 + uVar55 * 4);
        bVar115 = *(byte *)(iVar63 + uVar55);
        while (iVar56 = *(int *)(param_1 + 0x25c), 7 < iVar56) {
          *(undefined1 *)(*(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x4c)) =
               *(undefined1 *)(param_1 + 0x25b);
          *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
          *(int *)(param_1 + 600) = *(int *)(param_1 + 600) << 8;
          *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -8;
        }
        *(uint *)(param_1 + 600) =
             *(uint *)(param_1 + 600) | iVar58 << ((' ' - (char)iVar56) - bVar115 & 0x1f);
        *(uint *)(param_1 + 0x25c) = iVar56 + (uint)bVar115;
      }
      else if (iVar56 <= iVar62) {
        iVar58 = *(int *)(param_1 + 0x25c);
        uVar55 = *(uint *)(param_1 + 600);
        do {
          uVar60 = (uint)*(ushort *)(iVar53 + iVar56 * 2);
          iVar63 = (uint)*(byte *)(param_1 + 0x680 + local_184) * 0x102;
          iVar61 = *(int *)(param_1 + 0x9930 + (iVar63 + uVar60) * 4);
          bVar115 = *(byte *)(param_1 + iVar63 + uVar60 + 0x9324);
          if (iVar58 < 8) {
            uVar55 = *(uint *)(param_1 + 600);
          }
          else {
            iVar63 = *(int *)(param_1 + 0x4c);
            do {
              *(char *)(*(int *)(param_1 + 0x2c) + iVar63) = (char)(uVar55 >> 0x18);
              iVar63 = *(int *)(param_1 + 0x4c) + 1;
              *(int *)(param_1 + 0x4c) = iVar63;
              uVar55 = *(int *)(param_1 + 600) << 8;
              *(uint *)(param_1 + 600) = uVar55;
              iVar58 = *(int *)(param_1 + 0x25c) + -8;
              *(int *)(param_1 + 0x25c) = iVar58;
            } while (7 < iVar58);
          }
          uVar55 = uVar55 | iVar61 << ((' ' - (char)iVar58) - bVar115 & 0x1f);
          *(uint *)(param_1 + 600) = uVar55;
          iVar58 = iVar58 + (uint)bVar115;
          *(int *)(param_1 + 0x25c) = iVar58;
          iVar56 = iVar56 + 1;
        } while (iVar56 <= iVar62);
      }
      iVar56 = iVar62 + 1;
      local_184 = local_184 + 1;
      iVar58 = *(int *)(param_1 + 0x274);
    } while (iVar56 < iVar58);
  }
  if (local_184 != local_160) {
    BZ2_bz__AssertH__fail(0xbbf);
  }
  if (2 < *(int *)(param_1 + 0x268)) {
    fprintf(_stderr,"codes %d\n",*(int *)(param_1 + 0x4c) - local_174);
  }
  goto LAB_000d8763;
}


// BZ2_decompress  @ 000dbb00
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 BZ2_decompress(undefined4 *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  int iVar7;
  char cVar8;
  byte bVar9;
  int *piVar10;
  undefined4 *puVar11;
  char *pcVar12;
  uint uVar13;
  ushort *puVar14;
  uint uVar15;
  undefined1 *puVar16;
  int iVar17;
  int local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  int local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  int local_78;
  int local_74;
  uint local_70;
  int local_6c;
  int local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  int local_58;
  undefined4 *local_54;
  undefined4 *local_50;
  undefined4 *local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  byte *local_38;
  byte abStack_23 [19];
  
  puVar11 = (undefined4 *)*param_1;
  if (param_1[1] == 10) {
    param_1[0x3e85] = 0;
    param_1[0x3e86] = 0;
    param_1[0x3e87] = 0;
    param_1[0x3e88] = 0;
    param_1[0x3e89] = 0;
    param_1[0x3e8a] = 0;
    param_1[0x3e8b] = 0;
    param_1[0x3e8c] = 0;
    param_1[0x3e8d] = 0;
    param_1[0x3e8e] = 0;
    param_1[0x3e8f] = 0;
    param_1[0x3e90] = 0;
    param_1[0x3e91] = 0;
    param_1[0x3e92] = 0;
    param_1[0x3e93] = 0;
    param_1[0x3e94] = 0;
    param_1[0x3e95] = 0;
    param_1[0x3e96] = 0;
    param_1[0x3e97] = 0;
    param_1[0x3e98] = 0;
    param_1[0x3e99] = 0;
    param_1[0x3e9a] = 0;
    param_1[0x3e9b] = 0;
    param_1[0x3e9c] = 0;
    local_4c = (undefined4 *)0x0;
    local_50 = (undefined4 *)0x0;
    local_54 = (undefined4 *)0x0;
    local_58 = 0;
    local_5c = 0;
    local_8c = 0;
    local_94 = 0;
    local_98 = 0;
    local_3c = 0;
    local_80 = 0;
    local_44 = 0;
    local_78 = 0;
    local_88 = 0;
    local_48 = 0;
    local_7c = 0;
    local_68 = 0;
    local_6c = 0;
    local_64 = 0;
    local_60 = 0;
    local_70 = 0;
    local_40 = 0;
    local_74 = 0;
    local_84 = 0;
    local_90 = 0;
  }
  else {
    local_90 = param_1[0x3e85];
    local_84 = param_1[0x3e86];
    local_74 = param_1[0x3e87];
    local_40 = param_1[0x3e88];
    local_70 = param_1[0x3e89];
    local_60 = param_1[0x3e8a];
    local_64 = param_1[0x3e8b];
    local_6c = param_1[0x3e8c];
    local_68 = param_1[0x3e8d];
    local_7c = param_1[0x3e8e];
    local_48 = param_1[0x3e8f];
    local_88 = param_1[0x3e90];
    local_78 = param_1[0x3e91];
    local_44 = param_1[0x3e92];
    local_80 = param_1[0x3e93];
    local_3c = param_1[0x3e94];
    local_98 = param_1[0x3e95];
    local_94 = param_1[0x3e96];
    local_8c = param_1[0x3e97];
    local_5c = param_1[0x3e98];
    local_58 = param_1[0x3e99];
    local_54 = (undefined4 *)param_1[0x3e9a];
    local_50 = (undefined4 *)param_1[0x3e9b];
    local_4c = (undefined4 *)param_1[0x3e9c];
  }
  iVar4 = local_6c;
  switch(param_1[1]) {
  case 10:
    goto switchD_000dbd4e_caseD_a;
  case 0xb:
    goto switchD_000dbd4e_caseD_b;
  case 0xc:
    goto switchD_000dbd4e_caseD_c;
  case 0xd:
    goto switchD_000dbd4e_caseD_d;
  case 0xe:
    goto switchD_000dbd4e_caseD_e;
  case 0xf:
    goto switchD_000dbd4e_caseD_f;
  case 0x10:
    goto switchD_000dbd4e_caseD_10;
  case 0x11:
    goto switchD_000dbd4e_caseD_11;
  case 0x12:
    goto switchD_000dbd4e_caseD_12;
  case 0x13:
    goto switchD_000dbd4e_caseD_13;
  case 0x14:
    goto switchD_000dbd4e_caseD_14;
  case 0x15:
    iVar7 = param_1[8];
    goto LAB_000dd32b;
  case 0x16:
    iVar7 = param_1[8];
    goto LAB_000dd3d5;
  case 0x17:
    iVar7 = param_1[8];
    goto LAB_000dd380;
  case 0x18:
    iVar7 = param_1[8];
    goto LAB_000dcc98;
  case 0x19:
    iVar7 = param_1[8];
    goto LAB_000dcc43;
  case 0x1a:
    iVar7 = param_1[8];
    goto LAB_000dcbee;
  case 0x1b:
    iVar7 = param_1[8];
    goto LAB_000dcb99;
  case 0x1c:
    goto switchD_000dbd4e_caseD_1c;
  case 0x1d:
    goto switchD_000dbd4e_caseD_1d;
  case 0x1e:
    goto switchD_000dbd4e_caseD_1e;
  case 0x1f:
    iVar7 = param_1[8];
    goto LAB_000dca6b;
  case 0x20:
    iVar7 = param_1[8];
    goto LAB_000dd2d7;
  case 0x21:
    goto switchD_000dbd4e_caseD_21;
  case 0x22:
    goto switchD_000dbd4e_caseD_22;
  case 0x23:
    goto switchD_000dbd4e_caseD_23;
  case 0x24:
switchD_000dbd4e_caseD_24:
    param_1[1] = 0x24;
    while (iVar4 = param_1[8], iVar4 < local_98) {
      puVar11 = (undefined4 *)*param_1;
      iVar7 = puVar11[1];
      if (iVar7 == 0) goto LAB_000dd423;
      pbVar6 = (byte *)*puVar11;
      param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
      param_1[8] = iVar4 + 8;
      *puVar11 = pbVar6 + 1;
      puVar11[1] = iVar7 + -1;
      iVar4 = puVar11[2];
      puVar11[2] = iVar4 + 1;
      if (iVar4 + 1 == 0) {
        puVar11[3] = puVar11[3] + 1;
      }
    }
    param_1[8] = iVar4 - local_98;
    local_94 = (uint)param_1[7] >> ((byte)(iVar4 - local_98) & 0x1f) &
               (1 << ((byte)local_98 & 0x1f)) - 1U;
    while (uVar2 = 0xfffffffc, iVar4 = local_6c, local_98 < 0x15) {
      if ((int)local_94 <= (int)local_54[local_98]) goto LAB_000dd952;
      local_98 = local_98 + 1;
switchD_000dbd4e_caseD_25:
      param_1[1] = 0x25;
      while (iVar4 = param_1[8], iVar4 < 1) {
        puVar11 = (undefined4 *)*param_1;
        iVar7 = puVar11[1];
        if (iVar7 == 0) goto LAB_000dd423;
        pbVar6 = (byte *)*puVar11;
        param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
        param_1[8] = iVar4 + 8;
        *puVar11 = pbVar6 + 1;
        puVar11[1] = iVar7 + -1;
        iVar4 = puVar11[2];
        puVar11[2] = iVar4 + 1;
        if (iVar4 + 1 == 0) {
          puVar11[3] = puVar11[3] + 1;
        }
      }
      param_1[8] = iVar4 + -1;
      local_8c = (uint)param_1[7] >> ((byte)(iVar4 + -1) & 0x1f) & 1;
      local_94 = local_94 << 1 | local_8c;
    }
    goto LAB_000dbc44;
  case 0x25:
    goto switchD_000dbd4e_caseD_25;
  case 0x26:
    goto switchD_000dbd4e_caseD_26;
  case 0x27:
    goto switchD_000dbd4e_caseD_27;
  case 0x28:
    goto switchD_000dbd4e_caseD_28;
  case 0x29:
    goto switchD_000dbd4e_caseD_29;
  case 0x2a:
    iVar7 = param_1[8];
    goto LAB_000dcd41;
  case 0x2b:
    iVar7 = param_1[8];
    goto LAB_000dccec;
  case 0x2c:
    goto switchD_000dbd4e_caseD_2c;
  case 0x2d:
    goto switchD_000dbd4e_caseD_2d;
  case 0x2e:
    goto switchD_000dbd4e_caseD_2e;
  case 0x2f:
    goto switchD_000dbd4e_caseD_2f;
  case 0x30:
    iVar7 = param_1[8];
    goto LAB_000dcdeb;
  case 0x31:
    iVar7 = param_1[8];
    goto LAB_000dcd96;
  case 0x32:
    iVar7 = param_1[8];
    goto LAB_000dc8f0;
  default:
    BZ2_bz__AssertH__fail(0xfa1);
    BZ2_bz__AssertH__fail(0xfa2);
    uVar2 = 0;
    goto LAB_000dbc44;
  }
code_r0x000dd43d:
  local_84 = local_84 + 1;
  if ((int)local_70 <= (int)local_84) goto LAB_000dd450;
  goto LAB_000dd2d7;
LAB_000dd952:
  uVar2 = 0xfffffffc;
  iVar4 = local_6c;
  if (0x101 < local_94 - local_50[local_98]) goto LAB_000dbc44;
  local_7c = local_4c[local_94 - local_50[local_98]];
  while( true ) {
    iVar4 = local_6c;
    if (local_7c == local_64) {
      if ((int)param_1[0xd] < 0) {
        local_64 = local_7c;
        uVar2 = 0xfffffffc;
        goto LAB_000dbc44;
      }
      if ((int)param_1[0xd] < local_88) {
        param_1[3] = 0;
        *(undefined1 *)(param_1 + 2) = 0;
        param_1[0x318] = 0xffffffff;
        param_1[1] = 2;
        if (1 < (int)param_1[0xc]) {
          fwrite("rt+rld",1,6,_stderr);
        }
        param_1[0x111] = 0;
        iVar7 = 1;
        do {
          param_1[iVar7 + 0x111] = param_1[iVar7 + 0xf];
          iVar7 = iVar7 + 1;
        } while (iVar7 != 0x101);
        iVar7 = 1;
        do {
          param_1[iVar7 + 0x111] = param_1[iVar7 + 0x111] + param_1[iVar7 + 0x110];
          iVar7 = iVar7 + 1;
        } while (iVar7 != 0x101);
        if (*(char *)(param_1 + 10) == '\0') {
          iVar7 = param_1[0x313];
          local_90 = 0;
          do {
            uVar13 = (uint)*(byte *)(iVar7 + local_90 * 4);
            puVar1 = (uint *)(iVar7 + param_1[uVar13 + 0x111] * 4);
            *puVar1 = *puVar1 | local_90 << 8;
            param_1[uVar13 + 0x111] = param_1[uVar13 + 0x111] + 1;
            local_90 = local_90 + 1;
          } while ((int)local_90 < local_88);
          uVar13 = *(uint *)(iVar7 + param_1[0xd] * 4) >> 8;
          param_1[0xe] = uVar13;
          param_1[0x110] = 0;
          if (*(char *)(param_1 + 4) == '\0') {
            uVar13 = *(uint *)(iVar7 + uVar13 * 4);
            param_1[0xf] = uVar13 & 0xff;
            param_1[0xe] = uVar13 >> 8;
            param_1[0x110] = 1;
            local_64 = local_7c;
            uVar2 = 0;
          }
          else {
            param_1[5] = 0;
            param_1[6] = 0;
            uVar13 = *(uint *)(iVar7 + uVar13 * 4);
            param_1[0xe] = uVar13 >> 8;
            param_1[0x110] = 1;
            param_1[6] = 1;
            iVar7 = BZ2_rNums + -1;
            param_1[5] = iVar7;
            param_1[0xf] = uVar13 & 0xff ^ (uint)(iVar7 == 1);
            local_64 = local_7c;
            uVar2 = 0;
          }
        }
        else {
          iVar7 = 0;
          do {
            param_1[iVar7 + 0x212] = param_1[iVar7 + 0x111];
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x101);
          uVar13 = 0;
          do {
            pbVar6 = (byte *)(uVar13 * 2 + param_1[0x314]);
            uVar15 = (uint)*pbVar6;
            iVar7 = param_1[uVar15 + 0x212];
            *(short *)pbVar6 = (short)iVar7;
            if ((uVar13 & 1) == 0) {
              pbVar6 = (byte *)(((int)uVar13 >> 1) + param_1[0x315]);
              *pbVar6 = *pbVar6 & 0xf0 | (byte)((uint)iVar7 >> 0x10);
            }
            else {
              pbVar6 = (byte *)(((int)uVar13 >> 1) + param_1[0x315]);
              *pbVar6 = *pbVar6 & 0xf | (byte)((iVar7 >> 0x10) << 4);
            }
            param_1[uVar15 + 0x212] = param_1[uVar15 + 0x212] + 1;
            uVar13 = uVar13 + 1;
          } while ((int)uVar13 < local_88);
          uVar13 = param_1[0xd];
          local_84 = (*(byte *)(param_1[0x315] + ((int)uVar13 >> 1)) >> ((char)uVar13 * '\x04' & 4U)
                     & 0xf) << 0x10 | (uint)*(ushort *)(param_1[0x314] + uVar13 * 2);
          do {
            local_90 = local_84;
            puVar14 = (ushort *)(local_90 * 2 + param_1[0x314]);
            pbVar6 = (byte *)(((int)local_90 >> 1) + param_1[0x315]);
            local_84 = (*pbVar6 >> ((char)local_90 * '\x04' & 4U) & 0xf) << 0x10 | (uint)*puVar14;
            *puVar14 = (ushort)uVar13;
            if ((local_90 & 1) == 0) {
              *pbVar6 = *pbVar6 & 0xf0 | (byte)(uVar13 >> 0x10);
            }
            else {
              *pbVar6 = *pbVar6 & 0xf | (byte)(((int)uVar13 >> 0x10) << 4);
            }
            uVar13 = local_90;
          } while (local_90 != param_1[0xd]);
          param_1[0xe] = local_90;
          param_1[0x110] = 0;
          if (*(char *)(param_1 + 4) == '\0') {
            uVar2 = BZ2_indexIntoF(local_90,param_1 + 0x111);
            param_1[0xf] = uVar2;
            uVar13 = param_1[0xe];
            param_1[0xe] = (*(byte *)(param_1[0x315] + (uVar13 >> 1)) >>
                            ((char)uVar13 * '\x04' & 4U) & 0xf) << 0x10 |
                           (uint)*(ushort *)(param_1[0x314] + uVar13 * 2);
            param_1[0x110] = param_1[0x110] + 1;
            local_64 = local_7c;
            uVar2 = 0;
          }
          else {
            param_1[5] = 0;
            param_1[6] = 0;
            uVar13 = BZ2_indexIntoF(local_90,param_1 + 0x111);
            param_1[0xf] = uVar13;
            param_1[0xe] = (*(byte *)(param_1[0x315] + ((uint)param_1[0xe] >> 1)) >>
                            ((char)param_1[0xe] * '\x04' & 4U) & 0xf) << 0x10 |
                           (uint)*(ushort *)(param_1[0x314] + param_1[0xe] * 2);
            param_1[0x110] = param_1[0x110] + 1;
            if (param_1[5] == 0) {
              param_1[5] = (&BZ2_rNums)[param_1[6]];
              iVar7 = param_1[6] + 1;
              iVar17 = 0;
              if (iVar7 != 0x200) {
                iVar17 = iVar7;
              }
              param_1[6] = iVar17;
            }
            iVar7 = param_1[5];
            param_1[5] = iVar7 + -1;
            param_1[0xf] = iVar7 + -1 == 1 ^ uVar13;
            local_64 = local_7c;
            uVar2 = 0;
          }
        }
        goto LAB_000dbc44;
      }
      local_64 = local_7c;
      goto LAB_000dd450;
    }
    if (1 < local_7c) break;
    local_44 = 1;
    local_78 = -1;
    do {
      if (local_7c == 0) {
        iVar4 = local_78 + local_44;
      }
      else {
        iVar4 = local_78 + local_44 * 2;
        if (local_7c != 1) {
          iVar4 = local_78;
        }
      }
      local_78 = iVar4;
      local_44 = local_44 << 1;
      if (local_68 == 0) {
        iVar4 = local_6c + 1;
        uVar2 = 0xfffffffc;
        if ((int)local_60 <= iVar4) goto LAB_000dbc44;
        local_5c = (uint)*(byte *)((int)param_1 + local_6c + 0x1ebd);
        local_58 = param_1[local_5c + 15999];
        local_54 = param_1 + local_5c * 0x102 + 0x2c5b;
        local_4c = param_1 + local_5c * 0x102 + 0x3873;
        local_50 = param_1 + local_5c * 0x102 + 0x3267;
        local_68 = 0x32;
        local_6c = iVar4;
      }
      local_68 = local_68 + -1;
      local_98 = local_58;
switchD_000dbd4e_caseD_26:
      param_1[1] = 0x26;
      while (iVar4 = param_1[8], iVar4 < local_98) {
        puVar11 = (undefined4 *)*param_1;
        iVar7 = puVar11[1];
        if (iVar7 == 0) goto LAB_000dd423;
        pbVar6 = (byte *)*puVar11;
        param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
        param_1[8] = iVar4 + 8;
        *puVar11 = pbVar6 + 1;
        puVar11[1] = iVar7 + -1;
        iVar4 = puVar11[2];
        puVar11[2] = iVar4 + 1;
        if (iVar4 + 1 == 0) {
          puVar11[3] = puVar11[3] + 1;
        }
      }
      param_1[8] = iVar4 - local_98;
      local_94 = (uint)param_1[7] >> ((byte)(iVar4 - local_98) & 0x1f) &
                 (1 << ((byte)local_98 & 0x1f)) - 1U;
      while( true ) {
        uVar2 = 0xfffffffc;
        iVar4 = local_6c;
        if (0x14 < local_98) goto LAB_000dbc44;
        if ((int)local_94 <= (int)local_54[local_98]) break;
        local_98 = local_98 + 1;
switchD_000dbd4e_caseD_27:
        param_1[1] = 0x27;
        while (iVar4 = param_1[8], iVar4 < 1) {
          puVar11 = (undefined4 *)*param_1;
          iVar7 = puVar11[1];
          if (iVar7 == 0) goto LAB_000dd423;
          pbVar6 = (byte *)*puVar11;
          param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
          param_1[8] = iVar4 + 8;
          *puVar11 = pbVar6 + 1;
          puVar11[1] = iVar7 + -1;
          iVar4 = puVar11[2];
          puVar11[2] = iVar4 + 1;
          if (iVar4 + 1 == 0) {
            puVar11[3] = puVar11[3] + 1;
          }
        }
        param_1[8] = iVar4 + -1;
        local_8c = (uint)param_1[7] >> ((byte)(iVar4 + -1) & 0x1f) & 1;
        local_94 = local_94 << 1 | local_8c;
      }
      if (0x101 < local_94 - local_50[local_98]) goto LAB_000dbc44;
      local_7c = local_4c[local_94 - local_50[local_98]];
    } while (local_7c < 2);
    local_78 = local_78 + 1;
    bVar9 = *(byte *)((int)param_1 + *(byte *)((int)param_1 + param_1[0x79f] + 0xe7c) + 0xd7c);
    param_1[bVar9 + 0x10] = param_1[bVar9 + 0x10] + local_78;
    if (*(char *)(param_1 + 10) == '\0') {
      iVar7 = local_88 * 4;
      for (; 0 < local_78; local_78 = local_78 + -1) {
        if (local_48 <= local_88) goto LAB_000ddaf5;
        *(uint *)(param_1[0x313] + iVar7) = (uint)bVar9;
        local_88 = local_88 + 1;
        iVar7 = iVar7 + 4;
      }
    }
    else {
      iVar7 = local_88 * 2;
      for (; 0 < local_78; local_78 = local_78 + -1) {
        if (local_48 <= local_88) goto LAB_000ddaf5;
        *(ushort *)(param_1[0x314] + iVar7) = (ushort)bVar9;
        local_88 = local_88 + 1;
        iVar7 = iVar7 + 2;
      }
    }
  }
  uVar2 = 0xfffffffc;
  if (local_48 <= local_88) goto LAB_000dbc44;
  uVar13 = local_7c - 1;
  if (uVar13 < 0x10) {
    iVar7 = param_1[0x79f];
    bVar9 = *(byte *)((int)param_1 + iVar7 + 0xe7c + uVar13);
    local_38 = (byte *)(uint)bVar9;
    iVar4 = iVar7 + -1 + local_7c;
    iVar17 = iVar4 + (uVar13 >> 2) * -4;
    for (; iVar4 != iVar17; iVar4 = iVar4 + -4) {
      *(undefined1 *)((int)param_1 + iVar4 + 0xe7c) = *(undefined1 *)((int)param_1 + iVar4 + 0xe7b);
      *(undefined1 *)((int)param_1 + iVar4 + 0xe7b) = *(undefined1 *)((int)param_1 + iVar4 + 0xe7a);
      *(undefined1 *)((int)param_1 + iVar4 + 0xe7a) = *(undefined1 *)((int)param_1 + iVar4 + 0xe79);
      *(undefined1 *)((int)param_1 + iVar4 + 0xe79) = *(undefined1 *)((int)param_1 + iVar4 + 0xe78);
    }
    iVar4 = (uVar13 >> 2) * -4 + uVar13;
    puVar5 = (undefined1 *)((int)param_1 + iVar4 + 0xe7c + iVar7 + -1);
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar5[1] = *puVar5;
      puVar5 = puVar5 + -1;
    }
    *(byte *)((int)param_1 + iVar7 + 0xe7c) = bVar9;
  }
  else {
    uVar15 = uVar13 >> 4;
    iVar7 = param_1[uVar15 + 0x79f];
    iVar4 = iVar7 + (uVar13 & 0xf);
    bVar9 = *(byte *)((int)param_1 + iVar4 + 0xe7c);
    local_38 = (byte *)(uint)bVar9;
    puVar5 = (undefined1 *)((int)param_1 + iVar4 + 0xe7b);
    for (; iVar7 < iVar4; iVar4 = iVar4 + -1) {
      puVar5[1] = *puVar5;
      puVar5 = puVar5 + -1;
    }
    param_1[uVar15 + 0x79f] = iVar7 + 1;
    piVar10 = param_1 + uVar15 + 0x79f;
    do {
      iVar4 = *piVar10;
      *piVar10 = iVar4 + -1;
      *(undefined1 *)((int)param_1 + iVar4 + 0xe7b) =
           *(undefined1 *)((int)param_1 + piVar10[-1] + 0xe8b);
      uVar15 = uVar15 - 1;
      piVar10 = piVar10 + -1;
    } while (0 < (int)uVar15);
    iVar4 = param_1[0x79f];
    iVar7 = iVar4 + -1;
    param_1[0x79f] = iVar7;
    *(byte *)((int)param_1 + iVar4 + 0xe7b) = bVar9;
    if (iVar7 == 0) {
      iVar4 = 0xfff;
      puVar11 = param_1;
      do {
        puVar5 = (undefined1 *)((int)param_1 + puVar11[0x7ae] + 0xe8b);
        puVar16 = (undefined1 *)((int)param_1 + iVar4 + 0xe7c);
        iVar7 = 0xf;
        do {
          *puVar16 = *puVar5;
          iVar7 = iVar7 + -1;
          puVar5 = puVar5 + -1;
          puVar16 = puVar16 + -1;
        } while (iVar7 != -1);
        iVar7 = iVar4 + -0xf;
        iVar4 = iVar4 + -0x10;
        puVar11[0x7ae] = iVar7;
        puVar11 = puVar11 + -1;
      } while (iVar4 != 0xeff);
    }
  }
  bVar9 = *(byte *)((int)param_1 + (int)local_38 + 0xd7cU);
  param_1[bVar9 + 0x10] = param_1[bVar9 + 0x10] + 1;
  if (*(char *)(param_1 + 10) == '\0') {
    *(uint *)(param_1[0x313] + local_88 * 4) = (uint)bVar9;
  }
  else {
    *(ushort *)(param_1[0x314] + local_88 * 2) = (ushort)bVar9;
  }
  local_88 = local_88 + 1;
  if (local_68 == 0) {
    iVar4 = local_6c + 1;
    uVar2 = 0xfffffffc;
    if ((int)local_60 <= iVar4) goto LAB_000dbc44;
    local_5c = (uint)*(byte *)((int)param_1 + local_6c + 0x1ebd);
    local_58 = param_1[local_5c + 15999];
    local_54 = param_1 + local_5c * 0x102 + 0x2c5b;
    local_4c = param_1 + local_5c * 0x102 + 0x3873;
    local_50 = param_1 + local_5c * 0x102 + 0x3267;
    local_68 = 0x32;
    local_6c = iVar4;
  }
  local_68 = local_68 + -1;
  local_98 = local_58;
switchD_000dbd4e_caseD_28:
  param_1[1] = 0x28;
  while (iVar4 = param_1[8], iVar4 < local_98) {
    puVar11 = (undefined4 *)*param_1;
    iVar7 = puVar11[1];
    if (iVar7 == 0) goto LAB_000dd423;
    pbVar6 = (byte *)*puVar11;
    param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
    param_1[8] = iVar4 + 8;
    *puVar11 = pbVar6 + 1;
    puVar11[1] = iVar7 + -1;
    iVar4 = puVar11[2];
    puVar11[2] = iVar4 + 1;
    if (iVar4 + 1 == 0) {
      puVar11[3] = puVar11[3] + 1;
    }
  }
  param_1[8] = iVar4 - local_98;
  local_94 = (uint)param_1[7] >> ((byte)(iVar4 - local_98) & 0x1f) &
             (1 << ((byte)local_98 & 0x1f)) - 1U;
  while( true ) {
    uVar2 = 0xfffffffc;
    iVar4 = local_6c;
    if (0x14 < local_98) goto LAB_000dbc44;
    if ((int)local_94 <= (int)local_54[local_98]) break;
    local_98 = local_98 + 1;
switchD_000dbd4e_caseD_29:
    param_1[1] = 0x29;
    while (iVar4 = param_1[8], iVar4 < 1) {
      puVar11 = (undefined4 *)*param_1;
      iVar7 = puVar11[1];
      if (iVar7 == 0) goto LAB_000dd423;
      pbVar6 = (byte *)*puVar11;
      param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
      param_1[8] = iVar4 + 8;
      *puVar11 = pbVar6 + 1;
      puVar11[1] = iVar7 + -1;
      iVar4 = puVar11[2];
      puVar11[2] = iVar4 + 1;
      if (iVar4 + 1 == 0) {
        puVar11[3] = puVar11[3] + 1;
      }
    }
    param_1[8] = iVar4 + -1;
    local_8c = (uint)param_1[7] >> ((byte)(iVar4 + -1) & 0x1f) & 1;
    local_94 = local_94 << 1 | local_8c;
  }
  goto LAB_000dd952;
LAB_000dd450:
  uVar2 = 0xfffffffc;
  iVar4 = local_6c;
  goto LAB_000dbc44;
LAB_000ddaf5:
  uVar2 = 0xfffffffc;
  goto LAB_000dbc44;
LAB_000dd423:
  uVar2 = 0;
  iVar4 = local_6c;
  goto LAB_000dbc44;
switchD_000dbd4e_caseD_a:
  param_1[1] = 10;
  while (iVar7 = param_1[8], iVar7 < 8) {
    iVar17 = puVar11[1];
    if (iVar17 == 0) goto LAB_000dd423;
    pbVar6 = (byte *)*puVar11;
    param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
    param_1[8] = iVar7 + 8;
    *puVar11 = pbVar6 + 1;
    puVar11[1] = iVar17 + -1;
    iVar7 = puVar11[2];
    puVar11[2] = iVar7 + 1;
    if (iVar7 + 1 == 0) {
      puVar11[3] = puVar11[3] + 1;
    }
  }
  param_1[8] = iVar7 + -8;
  uVar2 = 0xfffffffb;
  if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) != 'B') goto LAB_000dbc44;
switchD_000dbd4e_caseD_b:
  param_1[1] = 0xb;
  while (iVar7 = param_1[8], iVar7 < 8) {
    iVar17 = puVar11[1];
    if (iVar17 == 0) goto LAB_000dd423;
    pbVar6 = (byte *)*puVar11;
    param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
    param_1[8] = iVar7 + 8;
    *puVar11 = pbVar6 + 1;
    puVar11[1] = iVar17 + -1;
    iVar7 = puVar11[2];
    puVar11[2] = iVar7 + 1;
    if (iVar7 + 1 == 0) {
      puVar11[3] = puVar11[3] + 1;
    }
  }
  param_1[8] = iVar7 + -8;
  uVar2 = 0xfffffffb;
  if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) == 'Z') {
switchD_000dbd4e_caseD_c:
    param_1[1] = 0xc;
    while (iVar7 = param_1[8], iVar7 < 8) {
      iVar17 = puVar11[1];
      if (iVar17 == 0) goto LAB_000dd423;
      pbVar6 = (byte *)*puVar11;
      param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
      param_1[8] = iVar7 + 8;
      *puVar11 = pbVar6 + 1;
      puVar11[1] = iVar17 + -1;
      iVar7 = puVar11[2];
      puVar11[2] = iVar7 + 1;
      if (iVar7 + 1 == 0) {
        puVar11[3] = puVar11[3] + 1;
      }
    }
    param_1[8] = iVar7 + -8;
    uVar2 = 0xfffffffb;
    if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) == 'h') {
switchD_000dbd4e_caseD_d:
      param_1[1] = 0xd;
      while (iVar7 = param_1[8], iVar7 < 8) {
        iVar17 = puVar11[1];
        if (iVar17 == 0) goto LAB_000dd423;
        pbVar6 = (byte *)*puVar11;
        param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
        param_1[8] = iVar7 + 8;
        *puVar11 = pbVar6 + 1;
        puVar11[1] = iVar17 + -1;
        iVar7 = puVar11[2];
        puVar11[2] = iVar7 + 1;
        if (iVar7 + 1 == 0) {
          puVar11[3] = puVar11[3] + 1;
        }
      }
      uVar13 = (uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f) & 0xff;
      param_1[8] = iVar7 + -8;
      param_1[9] = uVar13;
      uVar2 = 0xfffffffb;
      if (uVar13 - 0x31 < 9) {
        iVar7 = uVar13 - 0x30;
        param_1[9] = iVar7;
        if (*(char *)(param_1 + 10) == '\0') {
          iVar7 = (*(code *)puVar11[9])(puVar11[0xb],iVar7 * 400000,1);
          param_1[0x313] = iVar7;
        }
        else {
          uVar2 = (*(code *)puVar11[9])(puVar11[0xb],iVar7 * 200000,1);
          param_1[0x314] = uVar2;
          iVar7 = (*(code *)puVar11[9])(puVar11[0xb],param_1[9] * 100000 >> 1,1);
          param_1[0x315] = iVar7;
          uVar2 = 0xfffffffd;
          if (param_1[0x314] == 0) goto LAB_000dbc44;
        }
        uVar2 = 0xfffffffd;
        if (iVar7 != 0) {
switchD_000dbd4e_caseD_e:
          param_1[1] = 0xe;
          while (iVar7 = param_1[8], iVar7 < 8) {
            puVar11 = (undefined4 *)*param_1;
            iVar17 = puVar11[1];
            if (iVar17 == 0) goto LAB_000dd423;
            pbVar6 = (byte *)*puVar11;
            param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
            param_1[8] = iVar7 + 8;
            *puVar11 = pbVar6 + 1;
            puVar11[1] = iVar17 + -1;
            iVar7 = puVar11[2];
            puVar11[2] = iVar7 + 1;
            if (iVar7 + 1 == 0) {
              puVar11[3] = puVar11[3] + 1;
            }
          }
          iVar7 = iVar7 + -8;
          param_1[8] = iVar7;
          cVar8 = (char)((uint)param_1[7] >> ((byte)iVar7 & 0x1f));
          if (cVar8 == '\x17') {
LAB_000dcd41:
            param_1[1] = 0x2a;
            while (iVar7 < 8) {
              puVar11 = (undefined4 *)*param_1;
              iVar17 = puVar11[1];
              if (iVar17 == 0) goto LAB_000dd423;
              pbVar6 = (byte *)*puVar11;
              param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
              iVar7 = iVar7 + 8;
              param_1[8] = iVar7;
              *puVar11 = pbVar6 + 1;
              puVar11[1] = iVar17 + -1;
              iVar17 = puVar11[2];
              puVar11[2] = iVar17 + 1;
              if (iVar17 + 1 == 0) {
                puVar11[3] = puVar11[3] + 1;
              }
            }
            iVar7 = iVar7 + -8;
            param_1[8] = iVar7;
            uVar2 = 0xfffffffc;
            if ((char)((uint)param_1[7] >> ((byte)iVar7 & 0x1f)) == 'r') {
LAB_000dccec:
              param_1[1] = 0x2b;
              while (iVar7 < 8) {
                puVar11 = (undefined4 *)*param_1;
                iVar17 = puVar11[1];
                if (iVar17 == 0) goto LAB_000dd423;
                pbVar6 = (byte *)*puVar11;
                param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                iVar7 = iVar7 + 8;
                param_1[8] = iVar7;
                *puVar11 = pbVar6 + 1;
                puVar11[1] = iVar17 + -1;
                iVar17 = puVar11[2];
                puVar11[2] = iVar17 + 1;
                if (iVar17 + 1 == 0) {
                  puVar11[3] = puVar11[3] + 1;
                }
              }
              param_1[8] = iVar7 + -8;
              uVar2 = 0xfffffffc;
              if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) == 'E') {
switchD_000dbd4e_caseD_2c:
                param_1[1] = 0x2c;
                while (iVar7 = param_1[8], iVar7 < 8) {
                  puVar11 = (undefined4 *)*param_1;
                  iVar17 = puVar11[1];
                  if (iVar17 == 0) goto LAB_000dd423;
                  pbVar6 = (byte *)*puVar11;
                  param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                  param_1[8] = iVar7 + 8;
                  *puVar11 = pbVar6 + 1;
                  puVar11[1] = iVar17 + -1;
                  iVar7 = puVar11[2];
                  puVar11[2] = iVar7 + 1;
                  if (iVar7 + 1 == 0) {
                    puVar11[3] = puVar11[3] + 1;
                  }
                }
                param_1[8] = iVar7 + -8;
                uVar2 = 0xfffffffc;
                if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) == '8') {
switchD_000dbd4e_caseD_2d:
                  param_1[1] = 0x2d;
                  while (iVar7 = param_1[8], iVar7 < 8) {
                    puVar11 = (undefined4 *)*param_1;
                    iVar17 = puVar11[1];
                    if (iVar17 == 0) goto LAB_000dd423;
                    pbVar6 = (byte *)*puVar11;
                    param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                    param_1[8] = iVar7 + 8;
                    *puVar11 = pbVar6 + 1;
                    puVar11[1] = iVar17 + -1;
                    iVar7 = puVar11[2];
                    puVar11[2] = iVar7 + 1;
                    if (iVar7 + 1 == 0) {
                      puVar11[3] = puVar11[3] + 1;
                    }
                  }
                  param_1[8] = iVar7 + -8;
                  uVar2 = 0xfffffffc;
                  if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) == 'P') {
switchD_000dbd4e_caseD_2e:
                    param_1[1] = 0x2e;
                    while (iVar7 = param_1[8], iVar7 < 8) {
                      puVar11 = (undefined4 *)*param_1;
                      iVar17 = puVar11[1];
                      if (iVar17 == 0) goto LAB_000dd423;
                      pbVar6 = (byte *)*puVar11;
                      param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                      param_1[8] = iVar7 + 8;
                      *puVar11 = pbVar6 + 1;
                      puVar11[1] = iVar17 + -1;
                      iVar7 = puVar11[2];
                      puVar11[2] = iVar7 + 1;
                      if (iVar7 + 1 == 0) {
                        puVar11[3] = puVar11[3] + 1;
                      }
                    }
                    param_1[8] = iVar7 + -8;
                    uVar2 = 0xfffffffc;
                    if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) == -0x70) {
                      param_1[0x317] = 0;
switchD_000dbd4e_caseD_2f:
                      param_1[1] = 0x2f;
                      while (iVar7 = param_1[8], iVar7 < 8) {
                        puVar11 = (undefined4 *)*param_1;
                        iVar17 = puVar11[1];
                        if (iVar17 == 0) goto LAB_000dd423;
                        pbVar6 = (byte *)*puVar11;
                        param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                        param_1[8] = iVar7 + 8;
                        *puVar11 = pbVar6 + 1;
                        puVar11[1] = iVar17 + -1;
                        iVar7 = puVar11[2];
                        puVar11[2] = iVar7 + 1;
                        if (iVar7 + 1 == 0) {
                          puVar11[3] = puVar11[3] + 1;
                        }
                      }
                      iVar7 = iVar7 + -8;
                      param_1[8] = iVar7;
                      param_1[0x317] =
                           (uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 0xff | param_1[0x317] << 8;
LAB_000dcdeb:
                      param_1[1] = 0x30;
                      while (iVar7 < 8) {
                        puVar11 = (undefined4 *)*param_1;
                        iVar17 = puVar11[1];
                        if (iVar17 == 0) goto LAB_000dd423;
                        pbVar6 = (byte *)*puVar11;
                        param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                        iVar7 = iVar7 + 8;
                        param_1[8] = iVar7;
                        *puVar11 = pbVar6 + 1;
                        puVar11[1] = iVar17 + -1;
                        iVar17 = puVar11[2];
                        puVar11[2] = iVar17 + 1;
                        if (iVar17 + 1 == 0) {
                          puVar11[3] = puVar11[3] + 1;
                        }
                      }
                      iVar7 = iVar7 + -8;
                      param_1[8] = iVar7;
                      param_1[0x317] =
                           (uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 0xff | param_1[0x317] << 8;
LAB_000dcd96:
                      param_1[1] = 0x31;
                      while (iVar7 < 8) {
                        puVar11 = (undefined4 *)*param_1;
                        iVar17 = puVar11[1];
                        if (iVar17 == 0) goto LAB_000dd423;
                        pbVar6 = (byte *)*puVar11;
                        param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                        iVar7 = iVar7 + 8;
                        param_1[8] = iVar7;
                        *puVar11 = pbVar6 + 1;
                        puVar11[1] = iVar17 + -1;
                        iVar17 = puVar11[2];
                        puVar11[2] = iVar17 + 1;
                        if (iVar17 + 1 == 0) {
                          puVar11[3] = puVar11[3] + 1;
                        }
                      }
                      iVar7 = iVar7 + -8;
                      param_1[8] = iVar7;
                      param_1[0x317] =
                           (uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 0xff | param_1[0x317] << 8;
LAB_000dc8f0:
                      param_1[1] = 0x32;
                      while (iVar7 < 8) {
                        puVar11 = (undefined4 *)*param_1;
                        iVar17 = puVar11[1];
                        if (iVar17 == 0) goto LAB_000dd423;
                        pbVar6 = (byte *)*puVar11;
                        param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                        iVar7 = iVar7 + 8;
                        param_1[8] = iVar7;
                        *puVar11 = pbVar6 + 1;
                        puVar11[1] = iVar17 + -1;
                        iVar17 = puVar11[2];
                        puVar11[2] = iVar17 + 1;
                        if (iVar17 + 1 == 0) {
                          puVar11[3] = puVar11[3] + 1;
                        }
                      }
                      param_1[8] = iVar7 + -8;
                      param_1[0x317] =
                           (uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f) & 0xff |
                           param_1[0x317] << 8;
                      param_1[1] = 1;
                      uVar2 = 4;
                    }
                  }
                }
              }
            }
          }
          else {
            uVar2 = 0xfffffffc;
            if (cVar8 == '1') {
switchD_000dbd4e_caseD_f:
              param_1[1] = 0xf;
              while (iVar7 = param_1[8], iVar7 < 8) {
                puVar11 = (undefined4 *)*param_1;
                iVar17 = puVar11[1];
                if (iVar17 == 0) goto LAB_000dd423;
                pbVar6 = (byte *)*puVar11;
                param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                param_1[8] = iVar7 + 8;
                *puVar11 = pbVar6 + 1;
                puVar11[1] = iVar17 + -1;
                iVar7 = puVar11[2];
                puVar11[2] = iVar7 + 1;
                if (iVar7 + 1 == 0) {
                  puVar11[3] = puVar11[3] + 1;
                }
              }
              param_1[8] = iVar7 + -8;
              uVar2 = 0xfffffffc;
              if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) == 'A') {
switchD_000dbd4e_caseD_10:
                param_1[1] = 0x10;
                while (iVar7 = param_1[8], iVar7 < 8) {
                  puVar11 = (undefined4 *)*param_1;
                  iVar17 = puVar11[1];
                  if (iVar17 == 0) goto LAB_000dd423;
                  pbVar6 = (byte *)*puVar11;
                  param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                  param_1[8] = iVar7 + 8;
                  *puVar11 = pbVar6 + 1;
                  puVar11[1] = iVar17 + -1;
                  iVar7 = puVar11[2];
                  puVar11[2] = iVar7 + 1;
                  if (iVar7 + 1 == 0) {
                    puVar11[3] = puVar11[3] + 1;
                  }
                }
                param_1[8] = iVar7 + -8;
                uVar2 = 0xfffffffc;
                if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) == 'Y') {
switchD_000dbd4e_caseD_11:
                  param_1[1] = 0x11;
                  while (iVar7 = param_1[8], iVar7 < 8) {
                    puVar11 = (undefined4 *)*param_1;
                    iVar17 = puVar11[1];
                    if (iVar17 == 0) goto LAB_000dd423;
                    pbVar6 = (byte *)*puVar11;
                    param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                    param_1[8] = iVar7 + 8;
                    *puVar11 = pbVar6 + 1;
                    puVar11[1] = iVar17 + -1;
                    iVar7 = puVar11[2];
                    puVar11[2] = iVar7 + 1;
                    if (iVar7 + 1 == 0) {
                      puVar11[3] = puVar11[3] + 1;
                    }
                  }
                  param_1[8] = iVar7 + -8;
                  uVar2 = 0xfffffffc;
                  if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) == '&') {
switchD_000dbd4e_caseD_12:
                    param_1[1] = 0x12;
                    while (iVar7 = param_1[8], iVar7 < 8) {
                      puVar11 = (undefined4 *)*param_1;
                      iVar17 = puVar11[1];
                      if (iVar17 == 0) goto LAB_000dd423;
                      pbVar6 = (byte *)*puVar11;
                      param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                      param_1[8] = iVar7 + 8;
                      *puVar11 = pbVar6 + 1;
                      puVar11[1] = iVar17 + -1;
                      iVar7 = puVar11[2];
                      puVar11[2] = iVar7 + 1;
                      if (iVar7 + 1 == 0) {
                        puVar11[3] = puVar11[3] + 1;
                      }
                    }
                    param_1[8] = iVar7 + -8;
                    uVar2 = 0xfffffffc;
                    if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) == 'S') {
switchD_000dbd4e_caseD_13:
                      param_1[1] = 0x13;
                      while (iVar7 = param_1[8], iVar7 < 8) {
                        puVar11 = (undefined4 *)*param_1;
                        iVar17 = puVar11[1];
                        if (iVar17 == 0) goto LAB_000dd423;
                        pbVar6 = (byte *)*puVar11;
                        param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                        param_1[8] = iVar7 + 8;
                        *puVar11 = pbVar6 + 1;
                        puVar11[1] = iVar17 + -1;
                        iVar7 = puVar11[2];
                        puVar11[2] = iVar7 + 1;
                        if (iVar7 + 1 == 0) {
                          puVar11[3] = puVar11[3] + 1;
                        }
                      }
                      param_1[8] = iVar7 + -8;
                      uVar2 = 0xfffffffc;
                      if ((char)((uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f)) == 'Y') {
                        iVar7 = param_1[0xb];
                        param_1[0xb] = iVar7 + 1;
                        if (1 < (int)param_1[0xc]) {
                          fprintf(_stderr,"\n    [%d: huff+mtf ",iVar7 + 1);
                        }
                        param_1[0x316] = 0;
switchD_000dbd4e_caseD_14:
                        param_1[1] = 0x14;
                        while (iVar7 = param_1[8], iVar7 < 8) {
                          puVar11 = (undefined4 *)*param_1;
                          iVar17 = puVar11[1];
                          if (iVar17 == 0) goto LAB_000dd423;
                          pbVar6 = (byte *)*puVar11;
                          param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                          param_1[8] = iVar7 + 8;
                          *puVar11 = pbVar6 + 1;
                          puVar11[1] = iVar17 + -1;
                          iVar7 = puVar11[2];
                          puVar11[2] = iVar7 + 1;
                          if (iVar7 + 1 == 0) {
                            puVar11[3] = puVar11[3] + 1;
                          }
                        }
                        iVar7 = iVar7 + -8;
                        param_1[8] = iVar7;
                        param_1[0x316] =
                             (uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 0xff | param_1[0x316] << 8;
LAB_000dd32b:
                        param_1[1] = 0x15;
                        while (iVar7 < 8) {
                          puVar11 = (undefined4 *)*param_1;
                          iVar17 = puVar11[1];
                          if (iVar17 == 0) goto LAB_000dd423;
                          pbVar6 = (byte *)*puVar11;
                          param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                          iVar7 = iVar7 + 8;
                          param_1[8] = iVar7;
                          *puVar11 = pbVar6 + 1;
                          puVar11[1] = iVar17 + -1;
                          iVar17 = puVar11[2];
                          puVar11[2] = iVar17 + 1;
                          if (iVar17 + 1 == 0) {
                            puVar11[3] = puVar11[3] + 1;
                          }
                        }
                        iVar7 = iVar7 + -8;
                        param_1[8] = iVar7;
                        param_1[0x316] =
                             (uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 0xff | param_1[0x316] << 8;
LAB_000dd3d5:
                        param_1[1] = 0x16;
                        while (iVar7 < 8) {
                          puVar11 = (undefined4 *)*param_1;
                          iVar17 = puVar11[1];
                          if (iVar17 == 0) goto LAB_000dd423;
                          pbVar6 = (byte *)*puVar11;
                          param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                          iVar7 = iVar7 + 8;
                          param_1[8] = iVar7;
                          *puVar11 = pbVar6 + 1;
                          puVar11[1] = iVar17 + -1;
                          iVar17 = puVar11[2];
                          puVar11[2] = iVar17 + 1;
                          if (iVar17 + 1 == 0) {
                            puVar11[3] = puVar11[3] + 1;
                          }
                        }
                        iVar7 = iVar7 + -8;
                        param_1[8] = iVar7;
                        param_1[0x316] =
                             (uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 0xff | param_1[0x316] << 8;
LAB_000dd380:
                        param_1[1] = 0x17;
                        while (iVar7 < 8) {
                          puVar11 = (undefined4 *)*param_1;
                          iVar17 = puVar11[1];
                          if (iVar17 == 0) goto LAB_000dd423;
                          pbVar6 = (byte *)*puVar11;
                          param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                          iVar7 = iVar7 + 8;
                          param_1[8] = iVar7;
                          *puVar11 = pbVar6 + 1;
                          puVar11[1] = iVar17 + -1;
                          iVar17 = puVar11[2];
                          puVar11[2] = iVar17 + 1;
                          if (iVar17 + 1 == 0) {
                            puVar11[3] = puVar11[3] + 1;
                          }
                        }
                        iVar7 = iVar7 + -8;
                        param_1[8] = iVar7;
                        param_1[0x316] =
                             (uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 0xff | param_1[0x316] << 8;
LAB_000dcc98:
                        param_1[1] = 0x18;
                        while (iVar7 < 1) {
                          puVar11 = (undefined4 *)*param_1;
                          iVar17 = puVar11[1];
                          if (iVar17 == 0) goto LAB_000dd423;
                          pbVar6 = (byte *)*puVar11;
                          param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                          iVar7 = iVar7 + 8;
                          param_1[8] = iVar7;
                          *puVar11 = pbVar6 + 1;
                          puVar11[1] = iVar17 + -1;
                          iVar17 = puVar11[2];
                          puVar11[2] = iVar17 + 1;
                          if (iVar17 + 1 == 0) {
                            puVar11[3] = puVar11[3] + 1;
                          }
                        }
                        iVar7 = iVar7 + -1;
                        param_1[8] = iVar7;
                        *(byte *)(param_1 + 4) =
                             (byte)((uint)param_1[7] >> ((byte)iVar7 & 0x1f)) & 1;
                        param_1[0xd] = 0;
LAB_000dcc43:
                        param_1[1] = 0x19;
                        while (iVar7 < 8) {
                          puVar11 = (undefined4 *)*param_1;
                          iVar17 = puVar11[1];
                          if (iVar17 == 0) goto LAB_000dd423;
                          pbVar6 = (byte *)*puVar11;
                          param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                          iVar7 = iVar7 + 8;
                          param_1[8] = iVar7;
                          *puVar11 = pbVar6 + 1;
                          puVar11[1] = iVar17 + -1;
                          iVar17 = puVar11[2];
                          puVar11[2] = iVar17 + 1;
                          if (iVar17 + 1 == 0) {
                            puVar11[3] = puVar11[3] + 1;
                          }
                        }
                        iVar7 = iVar7 + -8;
                        param_1[8] = iVar7;
                        param_1[0xd] = (uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 0xff |
                                       param_1[0xd] << 8;
LAB_000dcbee:
                        param_1[1] = 0x1a;
                        while (iVar7 < 8) {
                          puVar11 = (undefined4 *)*param_1;
                          iVar17 = puVar11[1];
                          if (iVar17 == 0) goto LAB_000dd423;
                          pbVar6 = (byte *)*puVar11;
                          param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                          iVar7 = iVar7 + 8;
                          param_1[8] = iVar7;
                          *puVar11 = pbVar6 + 1;
                          puVar11[1] = iVar17 + -1;
                          iVar17 = puVar11[2];
                          puVar11[2] = iVar17 + 1;
                          if (iVar17 + 1 == 0) {
                            puVar11[3] = puVar11[3] + 1;
                          }
                        }
                        iVar7 = iVar7 + -8;
                        param_1[8] = iVar7;
                        param_1[0xd] = (uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 0xff |
                                       param_1[0xd] << 8;
LAB_000dcb99:
                        param_1[1] = 0x1b;
                        while (iVar7 < 8) {
                          puVar11 = (undefined4 *)*param_1;
                          iVar17 = puVar11[1];
                          if (iVar17 == 0) goto LAB_000dd423;
                          pbVar6 = (byte *)*puVar11;
                          param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                          iVar7 = iVar7 + 8;
                          param_1[8] = iVar7;
                          *puVar11 = pbVar6 + 1;
                          puVar11[1] = iVar17 + -1;
                          iVar17 = puVar11[2];
                          puVar11[2] = iVar17 + 1;
                          if (iVar17 + 1 == 0) {
                            puVar11[3] = puVar11[3] + 1;
                          }
                        }
                        param_1[8] = iVar7 + -8;
                        uVar13 = (uint)param_1[7] >> ((byte)(iVar7 + -8) & 0x1f) & 0xff |
                                 param_1[0xd] << 8;
                        param_1[0xd] = uVar13;
                        uVar2 = 0xfffffffc;
                        if ((-1 < (int)uVar13) && ((int)uVar13 <= param_1[9] * 100000 + 10)) {
                          local_90 = 0;
switchD_000dbd4e_caseD_1c:
                          local_38 = (byte *)((int)param_1 + local_90 + 0xd6c);
                          do {
                            param_1[1] = 0x1c;
                            while (iVar7 = param_1[8], iVar7 < 1) {
                              puVar11 = (undefined4 *)*param_1;
                              iVar17 = puVar11[1];
                              if (iVar17 == 0) goto LAB_000dd423;
                              pbVar6 = (byte *)*puVar11;
                              param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                              param_1[8] = iVar7 + 8;
                              *puVar11 = pbVar6 + 1;
                              puVar11[1] = iVar17 + -1;
                              iVar7 = puVar11[2];
                              puVar11[2] = iVar7 + 1;
                              if (iVar7 + 1 == 0) {
                                puVar11[3] = puVar11[3] + 1;
                              }
                            }
                            param_1[8] = iVar7 + -1;
                            *local_38 = (byte)((uint)param_1[7] >> ((byte)(iVar7 + -1) & 0x1f)) & 1;
                            local_90 = local_90 + 1;
                            local_38 = local_38 + 1;
                          } while ((int)local_90 < 0x10);
                          iVar7 = 0;
                          do {
                            *(undefined1 *)((int)param_1 + iVar7 + 0xc6c) = 0;
                            iVar7 = iVar7 + 1;
                          } while (iVar7 != 0x100);
                          local_90 = 0;
                          do {
                            if (*(char *)((int)param_1 + local_90 + 0xd6c) != '\0') {
                              local_84 = 0;
switchD_000dbd4e_caseD_1d:
                              local_38 = (byte *)((int)param_1 + local_90 * 0x10 + local_84 + 0xc6c)
                              ;
                              do {
                                param_1[1] = 0x1d;
                                while (iVar7 = param_1[8], iVar7 < 1) {
                                  puVar11 = (undefined4 *)*param_1;
                                  iVar17 = puVar11[1];
                                  if (iVar17 == 0) goto LAB_000dd423;
                                  pbVar6 = (byte *)*puVar11;
                                  param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                                  param_1[8] = iVar7 + 8;
                                  *puVar11 = pbVar6 + 1;
                                  puVar11[1] = iVar17 + -1;
                                  iVar7 = puVar11[2];
                                  puVar11[2] = iVar7 + 1;
                                  if (iVar7 + 1 == 0) {
                                    puVar11[3] = puVar11[3] + 1;
                                  }
                                }
                                param_1[8] = iVar7 + -1;
                                if (((uint)param_1[7] >> ((byte)(iVar7 + -1) & 0x1f) & 1) != 0) {
                                  *local_38 = 1;
                                }
                                local_84 = local_84 + 1;
                                local_38 = local_38 + 1;
                              } while ((int)local_84 < 0x10);
                            }
                            local_90 = local_90 + 1;
                          } while ((int)local_90 < 0x10);
                          param_1[0x31a] = 0;
                          iVar7 = 0;
                          iVar17 = 0;
                          do {
                            if (*(char *)((int)param_1 + iVar7 + 0xc6c) != '\0') {
                              *(char *)((int)param_1 + iVar17 + 0xd7c) = (char)iVar7;
                              iVar17 = iVar17 + 1;
                              param_1[0x31a] = iVar17;
                            }
                            iVar7 = iVar7 + 1;
                          } while (iVar7 != 0x100);
                          uVar2 = 0xfffffffc;
                          if (iVar17 != 0) {
                            local_40 = iVar17 + 2;
switchD_000dbd4e_caseD_1e:
                            param_1[1] = 0x1e;
                            while (iVar7 = param_1[8], iVar7 < 3) {
                              puVar11 = (undefined4 *)*param_1;
                              iVar17 = puVar11[1];
                              if (iVar17 == 0) goto LAB_000dd423;
                              pbVar6 = (byte *)*puVar11;
                              param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                              param_1[8] = iVar7 + 8;
                              *puVar11 = pbVar6 + 1;
                              puVar11[1] = iVar17 + -1;
                              iVar7 = puVar11[2];
                              puVar11[2] = iVar7 + 1;
                              if (iVar7 + 1 == 0) {
                                puVar11[3] = puVar11[3] + 1;
                              }
                            }
                            iVar7 = iVar7 + -3;
                            param_1[8] = iVar7;
                            local_70 = (uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 7;
                            uVar2 = 0xfffffffc;
                            if (local_70 - 2 < 5) {
LAB_000dca6b:
                              param_1[1] = 0x1f;
                              while (iVar7 < 0xf) {
                                puVar11 = (undefined4 *)*param_1;
                                iVar17 = puVar11[1];
                                if (iVar17 == 0) goto LAB_000dd423;
                                pbVar6 = (byte *)*puVar11;
                                param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                                iVar7 = iVar7 + 8;
                                param_1[8] = iVar7;
                                *puVar11 = pbVar6 + 1;
                                puVar11[1] = iVar17 + -1;
                                iVar17 = puVar11[2];
                                puVar11[2] = iVar17 + 1;
                                if (iVar17 + 1 == 0) {
                                  puVar11[3] = puVar11[3] + 1;
                                }
                              }
                              iVar7 = iVar7 + -0xf;
                              param_1[8] = iVar7;
                              uVar2 = 0xfffffffc;
                              local_60 = (uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 0x7fff;
                              if (local_60 != 0) {
                                local_84 = 0;
                                local_90 = 0;
LAB_000dd2d7:
                                while( true ) {
                                  param_1[1] = 0x20;
                                  while (iVar7 < 1) {
                                    puVar11 = (undefined4 *)*param_1;
                                    iVar17 = puVar11[1];
                                    if (iVar17 == 0) goto LAB_000dd423;
                                    pbVar6 = (byte *)*puVar11;
                                    param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                                    iVar7 = iVar7 + 8;
                                    param_1[8] = iVar7;
                                    *puVar11 = pbVar6 + 1;
                                    puVar11[1] = iVar17 + -1;
                                    iVar17 = puVar11[2];
                                    puVar11[2] = iVar17 + 1;
                                    if (iVar17 + 1 == 0) {
                                      puVar11[3] = puVar11[3] + 1;
                                    }
                                  }
                                  iVar7 = iVar7 + -1;
                                  param_1[8] = iVar7;
                                  if (((uint)param_1[7] >> ((byte)iVar7 & 0x1f) & 1) != 0)
                                  goto code_r0x000dd43d;
                                  *(undefined1 *)((int)param_1 + local_90 + 0x650e) =
                                       (undefined1)local_84;
                                  local_90 = local_90 + 1;
                                  if ((int)local_60 <= (int)local_90) break;
                                  local_84 = 0;
                                }
                                if (0 < (int)local_70) {
                                  uVar13 = 0;
                                  bVar9 = 0;
                                  do {
                                    abStack_23[uVar13 + 1] = bVar9;
                                    bVar9 = bVar9 + 1;
                                    uVar13 = (uint)bVar9;
                                  } while ((int)uVar13 < (int)local_70);
                                }
                                if ((int)local_60 < 1) {
                                  local_74 = 0;
                                  local_90 = 0;
                                }
                                else {
                                  uVar13 = 0;
                                  do {
                                    bVar9 = *(byte *)((int)param_1 + uVar13 + 0x650e);
                                    abStack_23[1] = abStack_23[bVar9 + 1];
                                    for (; bVar9 != 0; bVar9 = bVar9 - 1) {
                                      abStack_23[bVar9 + 1] = abStack_23[bVar9];
                                    }
                                    *(byte *)((int)param_1 + uVar13 + 0x1ebc) = abStack_23[1];
                                    uVar13 = uVar13 + 1;
                                  } while (uVar13 != local_60);
                                  local_90 = local_60;
                                  local_74 = 0;
                                }
                                for (; local_74 < (int)local_70; local_74 = local_74 + 1) {
switchD_000dbd4e_caseD_21:
                                  param_1[1] = 0x21;
                                  while (iVar7 = param_1[8], iVar7 < 5) {
                                    puVar11 = (undefined4 *)*param_1;
                                    iVar17 = puVar11[1];
                                    if (iVar17 == 0) goto LAB_000dd423;
                                    pbVar6 = (byte *)*puVar11;
                                    param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                                    param_1[8] = iVar7 + 8;
                                    *puVar11 = pbVar6 + 1;
                                    puVar11[1] = iVar17 + -1;
                                    iVar7 = puVar11[2];
                                    puVar11[2] = iVar7 + 1;
                                    if (iVar7 + 1 == 0) {
                                      puVar11[3] = puVar11[3] + 1;
                                    }
                                  }
                                  param_1[8] = iVar7 + -5;
                                  local_80 = (uint)param_1[7] >> ((byte)(iVar7 + -5) & 0x1f) & 0x1f;
                                  for (local_90 = 0; (int)local_90 < local_40;
                                      local_90 = local_90 + 1) {
                                    while( true ) {
                                      uVar2 = 0xfffffffc;
                                      if (0x13 < local_80 - 1) goto LAB_000dbc44;
switchD_000dbd4e_caseD_22:
                                      param_1[1] = 0x22;
                                      while (iVar7 = param_1[8], iVar7 < 1) {
                                        puVar11 = (undefined4 *)*param_1;
                                        iVar17 = puVar11[1];
                                        if (iVar17 == 0) goto LAB_000dd423;
                                        pbVar6 = (byte *)*puVar11;
                                        param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                                        param_1[8] = iVar7 + 8;
                                        *puVar11 = pbVar6 + 1;
                                        puVar11[1] = iVar17 + -1;
                                        iVar7 = puVar11[2];
                                        puVar11[2] = iVar7 + 1;
                                        if (iVar7 + 1 == 0) {
                                          puVar11[3] = puVar11[3] + 1;
                                        }
                                      }
                                      param_1[8] = iVar7 + -1;
                                      if (((uint)param_1[7] >> ((byte)(iVar7 + -1) & 0x1f) & 1) == 0
                                         ) break;
switchD_000dbd4e_caseD_23:
                                      param_1[1] = 0x23;
                                      while (iVar7 = param_1[8], iVar7 < 1) {
                                        puVar11 = (undefined4 *)*param_1;
                                        iVar17 = puVar11[1];
                                        if (iVar17 == 0) goto LAB_000dd423;
                                        pbVar6 = (byte *)*puVar11;
                                        param_1[7] = (uint)*pbVar6 | param_1[7] << 8;
                                        param_1[8] = iVar7 + 8;
                                        *puVar11 = pbVar6 + 1;
                                        puVar11[1] = iVar17 + -1;
                                        iVar7 = puVar11[2];
                                        puVar11[2] = iVar7 + 1;
                                        if (iVar7 + 1 == 0) {
                                          puVar11[3] = puVar11[3] + 1;
                                        }
                                      }
                                      param_1[8] = iVar7 + -1;
                                      uVar13 = local_80 + 1;
                                      local_80 = local_80 - 1;
                                      if (((uint)param_1[7] >> ((byte)(iVar7 + -1) & 0x1f) & 1) == 0
                                         ) {
                                        local_80 = uVar13;
                                      }
                                    }
                                    *(undefined1 *)
                                     ((int)param_1 + local_90 + 0xab60 + local_74 * 0x102) =
                                         (undefined1)local_80;
                                  }
                                }
                                iVar4 = 0;
                                local_90 = 0;
                                for (local_74 = 0; local_74 < (int)local_70; local_74 = local_74 + 1
                                    ) {
                                  if (local_40 < 1) {
                                    uVar13 = 0;
                                    uVar15 = 0x20;
                                  }
                                  else {
                                    pbVar6 = (byte *)((int)param_1 + local_74 * 0x102 + 0xab60);
                                    iVar7 = 0;
                                    uVar13 = 0;
                                    uVar15 = 0x20;
                                    do {
                                      uVar3 = (uint)*pbVar6;
                                      if (uVar13 < uVar3) {
                                        uVar13 = uVar3;
                                      }
                                      if (uVar3 < uVar15) {
                                        uVar15 = uVar3;
                                      }
                                      iVar7 = iVar7 + 1;
                                      pbVar6 = pbVar6 + 1;
                                    } while (iVar7 != local_40);
                                  }
                                  BZ2_hbCreateDecodeTables
                                            ((int)param_1 + iVar4 + 0xb16c,
                                             (int)param_1 + iVar4 + 0xc99c,
                                             (int)param_1 + iVar4 + 0xe1cc,
                                             (int)param_1 + local_90 + 0xab60,uVar15,uVar13,local_40
                                            );
                                  param_1[local_74 + 15999] = uVar15;
                                  local_90 = local_90 + 0x102;
                                  iVar4 = iVar4 + 0x408;
                                }
                                local_64 = param_1[0x31a] + 1;
                                local_48 = param_1[9] * 100000;
                                iVar4 = 0;
                                do {
                                  param_1[iVar4 + 0x10] = 0;
                                  iVar4 = iVar4 + 1;
                                } while (iVar4 != 0x100);
                                iVar4 = 0xff0;
                                puVar11 = param_1;
                                do {
                                  pcVar12 = (char *)((int)param_1 + iVar4 + 0xe8b);
                                  iVar7 = 0xf;
                                  do {
                                    *pcVar12 = (char)iVar4 + (char)iVar7;
                                    iVar7 = iVar7 + -1;
                                    pcVar12 = pcVar12 + -1;
                                  } while (iVar7 != -1);
                                  puVar11[0x7ae] = iVar4;
                                  iVar4 = iVar4 + -0x10;
                                  puVar11 = puVar11 + -1;
                                } while (iVar4 != 0xef0);
                                local_90 = 0x100;
                                if ((int)local_60 < 1) {
                                  local_88 = 0;
                                  local_68 = 0;
                                  local_6c = 0;
                                  uVar2 = 0xfffffffc;
                                  iVar4 = local_6c;
                                  goto LAB_000dbc44;
                                }
                                local_5c = (uint)*(byte *)(param_1 + 0x7af);
                                local_98 = param_1[local_5c + 15999];
                                local_54 = param_1 + local_5c * 0x102 + 0x2c5b;
                                local_4c = param_1 + local_5c * 0x102 + 0x3873;
                                local_50 = param_1 + local_5c * 0x102 + 0x3267;
                                local_88 = 0;
                                local_68 = 0x31;
                                local_6c = 0;
                                local_58 = local_98;
                                goto switchD_000dbd4e_caseD_24;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_000dbc44:
  local_6c = iVar4;
  param_1[0x3e85] = local_90;
  param_1[0x3e86] = local_84;
  param_1[0x3e87] = local_74;
  param_1[0x3e88] = local_40;
  param_1[0x3e89] = local_70;
  param_1[0x3e8a] = local_60;
  param_1[0x3e8b] = local_64;
  param_1[0x3e8c] = local_6c;
  param_1[0x3e8d] = local_68;
  param_1[0x3e8e] = local_7c;
  param_1[0x3e8f] = local_48;
  param_1[0x3e90] = local_88;
  param_1[0x3e91] = local_78;
  param_1[0x3e92] = local_44;
  param_1[0x3e93] = local_80;
  param_1[0x3e94] = local_3c;
  param_1[0x3e95] = local_98;
  param_1[0x3e96] = local_94;
  param_1[0x3e97] = local_8c;
  param_1[0x3e98] = local_5c;
  param_1[0x3e99] = local_58;
  param_1[0x3e9a] = local_54;
  param_1[0x3e9b] = local_50;
  param_1[0x3e9c] = local_4c;
  return uVar2;
}


// BZ2_hbAssignCodes  @ 000e08b1
void BZ2_hbAssignCodes(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_4 < (int)param_3) {
    return;
  }
  iVar2 = 0;
  do {
    iVar1 = 0;
    if (0 < param_5) {
      do {
        while (*(byte *)(param_2 + iVar1) == param_3) {
          *(int *)(param_1 + iVar1 * 4) = iVar2;
          iVar2 = iVar2 + 1;
          iVar1 = iVar1 + 1;
          if (iVar1 == param_5) goto LAB_000e08f2;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 != param_5);
    }
LAB_000e08f2:
    param_3 = param_3 + 1;
    if (param_4 < (int)param_3) {
      return;
    }
    iVar2 = iVar2 * 2;
  } while( true );
}


// BZ2_hbCreateDecodeTables  @ 000e0904
void BZ2_hbCreateDecodeTables
               (int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,int param_7
               )

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((int)param_5 <= param_6) {
    iVar4 = 0;
    uVar3 = param_5;
    do {
      iVar2 = 0;
      if (0 < param_7) {
        do {
          while (*(byte *)(param_4 + iVar2) != uVar3) {
            iVar2 = iVar2 + 1;
            if (iVar2 == param_7) goto LAB_000e0954;
          }
          *(int *)(param_3 + iVar4 * 4) = iVar2;
          iVar4 = iVar4 + 1;
          iVar2 = iVar2 + 1;
        } while (iVar2 != param_7);
      }
LAB_000e0954:
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 <= param_6);
  }
  iVar4 = 0;
  do {
    *(undefined4 *)(param_2 + iVar4 * 4) = 0;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x17);
  if (0 < param_7) {
    iVar4 = 0;
    do {
      piVar1 = (int *)(param_2 + 4 + (uint)*(byte *)(param_4 + iVar4) * 4);
      *piVar1 = *piVar1 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 != param_7);
  }
  iVar4 = 1;
  do {
    piVar1 = (int *)(param_2 + iVar4 * 4);
    *piVar1 = *piVar1 + *(int *)(param_2 + -4 + iVar4 * 4);
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x17);
  iVar4 = 0;
  do {
    *(undefined4 *)(param_1 + iVar4 * 4) = 0;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x17);
  if ((int)param_5 <= param_6) {
    iVar4 = 0;
    uVar3 = param_5;
    do {
      iVar4 = (iVar4 + *(int *)(param_2 + 4 + uVar3 * 4)) - *(int *)(param_2 + uVar3 * 4);
      *(int *)(param_1 + uVar3 * 4) = iVar4 + -1;
      iVar4 = iVar4 * 2;
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 <= param_6);
  }
  while (param_5 = param_5 + 1, (int)param_5 <= param_6) {
    *(int *)(param_2 + param_5 * 4) =
         (*(int *)(param_1 + -4 + param_5 * 4) + 1) * 2 - *(int *)(param_2 + param_5 * 4);
  }
  return;
}


// BZ2_hbMakeCodeLengths  @ 000e0440
void BZ2_hbMakeCodeLengths(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int local_1474;
  int local_146c;
  int local_144c [516];
  uint local_c3c [516];
  int local_42c [263];
  
  if (0 < param_3) {
    iVar5 = 0;
    do {
      iVar5 = iVar5 + 1;
      iVar13 = *(int *)(param_2 + -4 + iVar5 * 4);
      uVar11 = 0x100;
      if (iVar13 != 0) {
        uVar11 = iVar13 << 8;
      }
      local_c3c[iVar5] = uVar11;
    } while (iVar5 != param_3);
  }
  do {
    local_42c[0] = 0;
    local_c3c[0] = 0;
    local_144c[0] = -2;
    iVar5 = param_3;
    if (0 < param_3) {
      iVar13 = 1;
      do {
        local_144c[iVar13] = -1;
        local_42c[iVar13] = iVar13;
        uVar9 = local_c3c[iVar13];
        iVar12 = local_42c[iVar13 >> 1];
        uVar11 = local_c3c[iVar12];
        iVar6 = iVar13 >> 1;
        iVar10 = iVar13;
        while (iVar7 = iVar6, (int)uVar9 < (int)uVar11) {
          local_42c[iVar10] = iVar12;
          iVar6 = iVar7 >> 1;
          iVar12 = local_42c[iVar6];
          iVar10 = iVar7;
          uVar11 = local_c3c[iVar12];
        }
        local_42c[iVar10] = iVar13;
        iVar13 = iVar13 + 1;
      } while (iVar13 <= param_3);
      if (param_3 < 0x104) {
        if (param_3 < 2) goto LAB_000e07a9;
      }
      else {
        BZ2_bz__AssertH__fail(0x7d1);
      }
      iVar13 = param_3 + -1;
      local_1474 = param_3;
      local_146c = param_3 + -2;
      do {
        iVar12 = local_42c[1];
        iVar5 = local_42c[iVar13 + 1];
        local_42c[1] = iVar5;
        iVar10 = 1;
        if (1 < iVar13) {
          uVar11 = local_c3c[iVar5];
          iVar6 = 2;
          do {
            iVar7 = iVar6;
            if (iVar6 < iVar13) {
              iVar1 = local_42c[iVar6];
              uVar9 = local_c3c[iVar1];
              if ((int)local_c3c[local_42c[iVar6 + 1]] < (int)uVar9) {
                iVar7 = iVar6 + 1;
                iVar1 = local_42c[iVar6 + 1];
                uVar9 = local_c3c[local_42c[iVar6 + 1]];
              }
            }
            else {
              iVar1 = local_42c[iVar6];
              uVar9 = local_c3c[iVar1];
            }
            if ((int)uVar11 < (int)uVar9) break;
            local_42c[iVar10] = iVar1;
            iVar6 = iVar7 * 2;
            iVar10 = iVar7;
          } while (iVar6 <= iVar13);
        }
        local_42c[iVar10] = iVar5;
        iVar10 = local_42c[1];
        iVar5 = local_42c[iVar13];
        local_42c[1] = iVar5;
        iVar6 = 1;
        if (1 < local_146c) {
          uVar11 = local_c3c[iVar5];
          iVar7 = 2;
          do {
            if (iVar7 < local_146c) {
              iVar1 = iVar7 + 1;
              iVar2 = local_42c[iVar1];
              uVar3 = local_c3c[iVar2];
              iVar8 = local_42c[iVar7];
              uVar9 = local_c3c[iVar8];
              if ((int)uVar9 <= (int)uVar3) goto LAB_000e068e;
            }
            else {
              iVar8 = local_42c[iVar7];
              uVar9 = local_c3c[iVar8];
LAB_000e068e:
              iVar1 = iVar7;
              iVar2 = iVar8;
              uVar3 = uVar9;
            }
            if ((int)uVar11 < (int)uVar3) break;
            local_42c[iVar6] = iVar2;
            iVar7 = iVar1 * 2;
            iVar6 = iVar1;
          } while (iVar7 <= local_146c);
        }
        local_42c[iVar6] = iVar5;
        local_1474 = local_1474 + 1;
        local_144c[iVar10] = local_1474;
        local_144c[iVar12] = local_1474;
        uVar11 = local_c3c[iVar12] & 0xff;
        uVar9 = local_c3c[iVar10] & 0xff;
        if (uVar11 < uVar9) {
          uVar11 = uVar9;
        }
        uVar9 = uVar11 + 1 | (local_c3c[iVar10] & 0xffffff00) + (local_c3c[iVar12] & 0xffffff00);
        local_c3c[local_1474] = uVar9;
        local_144c[local_1474] = -1;
        local_42c[iVar13] = local_1474;
        iVar5 = local_42c[iVar13 >> 1];
        uVar11 = local_c3c[iVar5];
        iVar10 = iVar13 >> 1;
        iVar12 = iVar13;
        while (iVar6 = iVar10, (int)uVar9 < (int)uVar11) {
          local_42c[iVar12] = iVar5;
          iVar10 = iVar6 >> 1;
          iVar5 = local_42c[iVar10];
          iVar12 = iVar6;
          uVar11 = local_c3c[iVar5];
        }
        local_42c[iVar12] = local_1474;
        local_146c = local_146c + -1;
        iVar13 = iVar13 + -1;
        iVar5 = param_3 + 1 + param_3 + -2;
      } while (iVar13 != 0);
    }
LAB_000e07a9:
    if (0x203 < iVar5) {
      BZ2_bz__AssertH__fail(0x7d2);
    }
    if (param_3 < 1) {
      return;
    }
    bVar4 = false;
    iVar5 = 1;
    do {
      iVar12 = 0;
      for (iVar13 = local_144c[iVar5]; -1 < iVar13; iVar13 = local_144c[iVar13]) {
        iVar12 = iVar12 + 1;
      }
      *(char *)(param_1 + -1 + iVar5) = (char)iVar12;
      if (param_4 < iVar12) {
        bVar4 = true;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= param_3);
    if (!bVar4) {
      return;
    }
    if (1 < param_3) {
      iVar5 = 1;
      do {
        local_c3c[iVar5] =
             ((((int)local_c3c[iVar5] >> 8) - ((int)local_c3c[iVar5] >> 0x1f) >> 1) + 1) * 0x100;
        iVar5 = iVar5 + 1;
      } while (iVar5 != param_3);
    }
  } while( true );
}


// BZ2_indexIntoF  @ 000d633b
void BZ2_indexIntoF(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0x100;
  iVar1 = 0;
  do {
    iVar3 = iVar2 + iVar1 >> 1;
    if (param_1 < *(int *)(param_2 + iVar3 * 4)) {
      iVar2 = iVar3;
      iVar3 = iVar1;
    }
    iVar1 = iVar3;
  } while (iVar2 - iVar1 != 1);
  return;
}


