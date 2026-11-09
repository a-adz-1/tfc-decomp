// CheckNode__6CGraphG6Vectori  @ 000ca1d0
void CheckNode__6CGraphG6Vectori(int param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  undefined1 local_4c [16];
  float local_3c;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(int *)(*(int *)(param_1 + 0x24) + 0xc + param_3 * 0x10) != *(int *)(param_1 + 0x1860)) {
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0xc + param_3 * 0x10) =
         *(undefined4 *)(param_1 + 0x1860);
    iVar7 = param_3 * 0x58;
    pfVar1 = (float *)(*(int *)(param_1 + 0xc) + 0xc + iVar7);
    local_10 = *param_2 - *pfVar1;
    local_c = param_2[1] - pfVar1[1];
    local_8 = param_2[2] - pfVar1[2];
    fVar4 = SQRT(local_8 * local_8 + local_c * local_c + local_10 * local_10);
    fVar2 = *(float *)(param_1 + 0x1828);
    if (((byte)(fVar4 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar4 == fVar2) << 0xe) >> 8)) == 1) &&
       (UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_2,*(int *)(param_1 + 0xc) + 0xc + iVar7,1,0,local_4c),
       (byte)((byte)((ushort)((ushort)NAN(local_3c) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_3c == 1.0) << 0xe) >> 8)) == 0x40)) {
      *(int *)(param_1 + 0x182c) = param_3;
      *(float *)(param_1 + 0x1828) = fVar4;
      iVar5 = (((int)ROUND(*param_2) - (int)ROUND(*(float *)(param_1 + 0x1864))) * 0x100) /
              (((int)ROUND(*(float *)(param_1 + 0x1870)) - (int)ROUND(*(float *)(param_1 + 0x1864)))
              + 1);
      uVar6 = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0x18 + iVar7);
      local_5c = iVar5 * 2 - uVar6;
      if (iVar5 < (int)uVar6) {
        local_60 = uVar6;
        if ((int)local_5c < 0) {
          local_5c = 0;
        }
      }
      else {
        bVar3 = 0xff < (int)local_5c;
        local_60 = local_5c;
        local_5c = uVar6;
        if (bVar3) {
          local_60 = 0xff;
        }
      }
      if ((int)local_60 < (int)*(uint *)(param_1 + 0x183c)) {
        *(uint *)(param_1 + 0x183c) = local_60;
      }
      if ((int)*(uint *)(param_1 + 0x1830) < (int)local_5c) {
        *(uint *)(param_1 + 0x1830) = local_5c;
      }
      iVar7 = (((int)ROUND(param_2[1]) - (int)ROUND(*(float *)(param_1 + 0x1868))) * 0x100) /
              (((int)ROUND(*(float *)(param_1 + 0x1874)) - (int)ROUND(*(float *)(param_1 + 0x1868)))
              + 1);
      uVar6 = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0x19 + param_3 * 0x58);
      local_64 = iVar7 * 2 - uVar6;
      if (iVar7 < (int)uVar6) {
        local_68 = uVar6;
        if ((int)local_64 < 0) {
          local_64 = 0;
        }
      }
      else {
        bVar3 = 0xff < (int)local_64;
        local_68 = local_64;
        local_64 = uVar6;
        if (bVar3) {
          local_68 = 0xff;
        }
      }
      if ((int)local_68 < (int)*(uint *)(param_1 + 0x1840)) {
        *(uint *)(param_1 + 0x1840) = local_68;
      }
      if ((int)*(uint *)(param_1 + 0x1834) < (int)local_64) {
        *(uint *)(param_1 + 0x1834) = local_64;
      }
      iVar7 = (((int)ROUND(param_2[2]) - (int)ROUND(*(float *)(param_1 + 0x186c))) * 0x100) /
              (((int)ROUND(*(float *)(param_1 + 0x1878)) - (int)ROUND(*(float *)(param_1 + 0x186c)))
              + 1);
      uVar6 = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0x1a + param_3 * 0x58);
      local_6c = iVar7 * 2 - uVar6;
      if (iVar7 < (int)uVar6) {
        local_70 = uVar6;
        if ((int)local_6c < 0) {
          local_6c = 0;
        }
      }
      else {
        bVar3 = 0xff < (int)local_6c;
        local_70 = local_6c;
        local_6c = uVar6;
        if (bVar3) {
          local_70 = 0xff;
        }
      }
      if ((int)local_70 < (int)*(uint *)(param_1 + 0x1844)) {
        *(uint *)(param_1 + 0x1844) = local_70;
      }
      if ((int)*(uint *)(param_1 + 0x1838) < (int)local_6c) {
        *(uint *)(param_1 + 0x1838) = local_6c;
      }
      iVar7 = (int)ROUND(*(float *)(param_1 + 0x1864));
      iVar5 = ((int)ROUND(*(float *)(param_1 + 0x1870)) - iVar7) + 1;
      *(int *)(param_1 + 0x1848) = (((int)ROUND(*param_2 - fVar4) - iVar7) * 0x100) / iVar5;
      *(int *)(param_1 + 0x1854) = (((int)ROUND(fVar4 + *param_2) - iVar7) * 0x100) / iVar5;
      iVar7 = (int)ROUND(*(float *)(param_1 + 0x1868));
      iVar5 = ((int)ROUND(*(float *)(param_1 + 0x1874)) - iVar7) + 1;
      *(int *)(param_1 + 0x184c) = (((int)ROUND(param_2[1] - fVar4) - iVar7) * 0x100) / iVar5;
      *(int *)(param_1 + 0x1858) = (((int)ROUND(fVar4 + param_2[1]) - iVar7) * 0x100) / iVar5;
      iVar7 = (int)ROUND(*(float *)(param_1 + 0x186c));
      iVar5 = ((int)ROUND(*(float *)(param_1 + 0x1878)) - iVar7) + 1;
      *(int *)(param_1 + 0x1850) = (((int)ROUND(param_2[2] - fVar4) - iVar7) * 0x100) / iVar5;
      *(int *)(param_1 + 0x185c) = (((int)ROUND(fVar4 + param_2[2]) - iVar7) * 0x100) / iVar5;
    }
  }
  return;
}


