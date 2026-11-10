// CheckNode__6CGraphG6Vectori  @ 000c4c18
void CheckNode__6CGraphG6Vectori(int param_1,float *param_2,int param_3)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_64;
  uint local_60;
  uint local_5c;
  undefined1 local_4c [16];
  float local_3c;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(int *)(*(int *)(param_1 + 0x24) + 0xc + param_3 * 0x10) != *(int *)(param_1 + 0x1860)) {
    *(int *)(*(int *)(param_1 + 0x24) + 0xc + param_3 * 0x10) = *(int *)(param_1 + 0x1860);
    iVar2 = param_3 * 0x58 + *(int *)(param_1 + 0xc);
    local_10 = *param_2 - *(float *)(iVar2 + 0xc);
    local_c = param_2[1] - *(float *)(iVar2 + 0x10);
    local_8 = param_2[2] - *(float *)(iVar2 + 0x14);
    fVar1 = SQRT(local_8 * local_8 + local_c * local_c + local_10 * local_10);
    if ((fVar1 < *(float *)(param_1 + 0x1828)) &&
       (local_14 = fVar1,
       UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                 (param_2,iVar2 + 0xc,1,0,local_4c),
       (byte)((byte)((ushort)((ushort)NAN(local_3c) << 10) >> 8) |
             (byte)((ushort)((ushort)(local_3c == 1.0) << 0xe) >> 8)) == 0x40)) {
      *(int *)(param_1 + 0x182c) = param_3;
      *(float *)(param_1 + 0x1828) = fVar1;
      iVar2 = (((int)ROUND(*param_2) - (int)ROUND(*(float *)(param_1 + 0x1864))) * 0x100) /
              (((int)ROUND(*(float *)(param_1 + 0x1870)) - (int)ROUND(*(float *)(param_1 + 0x1864)))
              + 1);
      local_5c = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0x18 + param_3 * 0x58);
      uVar4 = iVar2 * 2 - local_5c;
      if (iVar2 < (int)local_5c) {
        uVar3 = local_5c;
        local_5c = uVar4;
        if ((int)uVar4 < 0) {
          local_5c = 0;
        }
      }
      else {
        uVar3 = 0xff;
        if ((int)uVar4 < 0x100) {
          uVar3 = uVar4;
        }
      }
      if ((int)uVar3 < (int)*(uint *)(param_1 + 0x183c)) {
        *(uint *)(param_1 + 0x183c) = uVar3;
      }
      if ((int)*(uint *)(param_1 + 0x1830) < (int)local_5c) {
        *(uint *)(param_1 + 0x1830) = local_5c;
      }
      iVar2 = (((int)ROUND(param_2[1]) - (int)ROUND(*(float *)(param_1 + 0x1868))) * 0x100) /
              (((int)ROUND(*(float *)(param_1 + 0x1874)) - (int)ROUND(*(float *)(param_1 + 0x1868)))
              + 1);
      local_60 = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0x19 + param_3 * 0x58);
      uVar4 = iVar2 * 2 - local_60;
      if (iVar2 < (int)local_60) {
        uVar3 = local_60;
        local_60 = uVar4;
        if ((int)uVar4 < 0) {
          local_60 = 0;
        }
      }
      else {
        uVar3 = 0xff;
        if ((int)uVar4 < 0x100) {
          uVar3 = uVar4;
        }
      }
      if ((int)uVar3 < (int)*(uint *)(param_1 + 0x1840)) {
        *(uint *)(param_1 + 0x1840) = uVar3;
      }
      if ((int)*(uint *)(param_1 + 0x1834) < (int)local_60) {
        *(uint *)(param_1 + 0x1834) = local_60;
      }
      iVar2 = (((int)ROUND(param_2[2]) - (int)ROUND(*(float *)(param_1 + 0x186c))) * 0x100) /
              (((int)ROUND(*(float *)(param_1 + 0x1878)) - (int)ROUND(*(float *)(param_1 + 0x186c)))
              + 1);
      local_64 = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0x1a + param_3 * 0x58);
      uVar4 = iVar2 * 2 - local_64;
      if (iVar2 < (int)local_64) {
        uVar3 = local_64;
        local_64 = uVar4;
        if ((int)uVar4 < 0) {
          local_64 = 0;
        }
      }
      else {
        uVar3 = 0xff;
        if ((int)uVar4 < 0x100) {
          uVar3 = uVar4;
        }
      }
      if ((int)uVar3 < (int)*(uint *)(param_1 + 0x1844)) {
        *(uint *)(param_1 + 0x1844) = uVar3;
      }
      if ((int)*(uint *)(param_1 + 0x1838) < (int)local_64) {
        *(uint *)(param_1 + 0x1838) = local_64;
      }
      iVar2 = (int)ROUND(*(float *)(param_1 + 0x1864));
      iVar5 = ((int)ROUND(*(float *)(param_1 + 0x1870)) - iVar2) + 1;
      *(int *)(param_1 + 0x1848) = (((int)ROUND(*param_2 - fVar1) - iVar2) * 0x100) / iVar5;
      *(int *)(param_1 + 0x1854) = (((int)ROUND(*param_2 + fVar1) - iVar2) * 0x100) / iVar5;
      iVar2 = (int)ROUND(*(float *)(param_1 + 0x1868));
      iVar5 = ((int)ROUND(*(float *)(param_1 + 0x1874)) - iVar2) + 1;
      *(int *)(param_1 + 0x184c) = (((int)ROUND(param_2[1] - fVar1) - iVar2) * 0x100) / iVar5;
      *(int *)(param_1 + 0x1858) = (((int)ROUND(param_2[1] + fVar1) - iVar2) * 0x100) / iVar5;
      iVar2 = (int)ROUND(*(float *)(param_1 + 0x186c));
      iVar5 = ((int)ROUND(*(float *)(param_1 + 0x1878)) - iVar2) + 1;
      *(int *)(param_1 + 0x1850) = (((int)ROUND(param_2[2] - fVar1) - iVar2) * 0x100) / iVar5;
      *(int *)(param_1 + 0x185c) = (((int)ROUND(param_2[2] + fVar1) - iVar2) * 0x100) / iVar5;
    }
  }
  return;
}


