// CheckNode__6CGraphG6Vectori  @ 000c4718
void CheckNode__6CGraphG6Vectori(int param_1,float *param_2,int param_3)

{
  float *pfVar1;
  bool bVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uStack_6c;
  uint uStack_68;
  uint uStack_64;
  uint uStack_60;
  uint local_5c;
  uint local_58;
  undefined1 local_48 [16];
  float local_38;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(*(int *)(param_1 + 0x24) + 0xc + param_3 * 0x10) != *(int *)(param_1 + 0x1860)) {
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0xc + param_3 * 0x10) =
         *(undefined4 *)(param_1 + 0x1860);
    iVar5 = param_3 * 0x58;
    pfVar1 = (float *)(*(int *)(param_1 + 0xc) + 0xc + iVar5);
    local_c = *param_2 - *pfVar1;
    local_8 = param_2[1] - pfVar1[1];
    local_4 = param_2[2] - pfVar1[2];
    fVar3 = SQRT(local_4 * local_4 + local_8 * local_8 + local_c * local_c);
    if ((fVar3 < *(float *)(param_1 + 0x1828)) &&
       (UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_2,*(int *)(param_1 + 0xc) + 0xc + iVar5,1,0,local_48),
       (byte)((byte)((ushort)((ushort)NAN(local_38) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_38 == 1.0) << 0xe) >> 8)) == 0x40)) {
      *(int *)(param_1 + 0x182c) = param_3;
      *(float *)(param_1 + 0x1828) = fVar3;
      iVar4 = (((int)ROUND(*param_2) - (int)ROUND(*(float *)(param_1 + 0x1864))) * 0x100) /
              (((int)ROUND(*(float *)(param_1 + 0x1870)) - (int)ROUND(*(float *)(param_1 + 0x1864)))
              + 1);
      uVar6 = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0x18 + iVar5);
      local_58 = iVar4 * 2 - uVar6;
      if (iVar4 < (int)uVar6) {
        local_5c = uVar6;
        if ((int)local_58 < 0) {
          local_58 = 0;
        }
      }
      else {
        bVar2 = 0xff < (int)local_58;
        local_5c = local_58;
        local_58 = uVar6;
        if (bVar2) {
          local_5c = 0xff;
        }
      }
      if ((int)local_5c < (int)*(uint *)(param_1 + 0x183c)) {
        *(uint *)(param_1 + 0x183c) = local_5c;
      }
      if ((int)*(uint *)(param_1 + 0x1830) < (int)local_58) {
        *(uint *)(param_1 + 0x1830) = local_58;
      }
      iVar5 = (((int)ROUND(param_2[1]) - (int)ROUND(*(float *)(param_1 + 0x1868))) * 0x100) /
              (((int)ROUND(*(float *)(param_1 + 0x1874)) - (int)ROUND(*(float *)(param_1 + 0x1868)))
              + 1);
      uVar6 = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0x19 + param_3 * 0x58);
      uStack_60 = iVar5 * 2 - uVar6;
      if (iVar5 < (int)uVar6) {
        uStack_64 = uVar6;
        if ((int)uStack_60 < 0) {
          uStack_60 = 0;
        }
      }
      else {
        bVar2 = 0xff < (int)uStack_60;
        uStack_64 = uStack_60;
        uStack_60 = uVar6;
        if (bVar2) {
          uStack_64 = 0xff;
        }
      }
      if ((int)uStack_64 < (int)*(uint *)(param_1 + 0x1840)) {
        *(uint *)(param_1 + 0x1840) = uStack_64;
      }
      if ((int)*(uint *)(param_1 + 0x1834) < (int)uStack_60) {
        *(uint *)(param_1 + 0x1834) = uStack_60;
      }
      iVar5 = (((int)ROUND(param_2[2]) - (int)ROUND(*(float *)(param_1 + 0x186c))) * 0x100) /
              (((int)ROUND(*(float *)(param_1 + 0x1878)) - (int)ROUND(*(float *)(param_1 + 0x186c)))
              + 1);
      uVar6 = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0x1a + param_3 * 0x58);
      uStack_68 = iVar5 * 2 - uVar6;
      if (iVar5 < (int)uVar6) {
        uStack_6c = uVar6;
        if ((int)uStack_68 < 0) {
          uStack_68 = 0;
        }
      }
      else {
        bVar2 = 0xff < (int)uStack_68;
        uStack_6c = uStack_68;
        uStack_68 = uVar6;
        if (bVar2) {
          uStack_6c = 0xff;
        }
      }
      if ((int)uStack_6c < (int)*(uint *)(param_1 + 0x1844)) {
        *(uint *)(param_1 + 0x1844) = uStack_6c;
      }
      if ((int)*(uint *)(param_1 + 0x1838) < (int)uStack_68) {
        *(uint *)(param_1 + 0x1838) = uStack_68;
      }
      iVar5 = (int)ROUND(*(float *)(param_1 + 0x1864));
      iVar4 = ((int)ROUND(*(float *)(param_1 + 0x1870)) - iVar5) + 1;
      *(int *)(param_1 + 0x1848) = (((int)ROUND(*param_2 - fVar3) - iVar5) * 0x100) / iVar4;
      *(int *)(param_1 + 0x1854) = (((int)ROUND(fVar3 + *param_2) - iVar5) * 0x100) / iVar4;
      iVar5 = (int)ROUND(*(float *)(param_1 + 0x1868));
      iVar4 = ((int)ROUND(*(float *)(param_1 + 0x1874)) - iVar5) + 1;
      *(int *)(param_1 + 0x184c) = (((int)ROUND(param_2[1] - fVar3) - iVar5) * 0x100) / iVar4;
      *(int *)(param_1 + 0x1858) = (((int)ROUND(fVar3 + param_2[1]) - iVar5) * 0x100) / iVar4;
      iVar5 = (int)ROUND(*(float *)(param_1 + 0x186c));
      iVar4 = ((int)ROUND(*(float *)(param_1 + 0x1878)) - iVar5) + 1;
      *(int *)(param_1 + 0x1850) = (((int)ROUND(param_2[2] - fVar3) - iVar5) * 0x100) / iVar4;
      *(int *)(param_1 + 0x185c) = (((int)ROUND(fVar3 + param_2[2]) - iVar5) * 0x100) / iVar4;
    }
  }
  return;
}


