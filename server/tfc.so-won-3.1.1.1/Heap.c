// Heap_SiftDown__14CQueuePriorityi  @ 000cb22c
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void Heap_SiftDown__14CQueuePriorityi(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int local_30;
  int local_2c;
  
  local_30 = param_2 * 2;
  iVar5 = local_30 + 1;
  iVar3 = param_1[param_2 * 2 + 1];
  fVar4 = (float)param_1[param_2 * 2 + 2];
  local_2c = *param_1;
  if (iVar5 < local_2c) {
    do {
      local_30 = local_30 + 2;
      iVar6 = iVar5;
      if (local_30 < local_2c) {
        fVar1 = (float)param_1[iVar5 * 2 + 2];
        fVar2 = (float)param_1[local_30 * 2 + 2];
        if (0x3f < (byte)((fVar1 < fVar2 |
                           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
          iVar6 = local_30;
        }
      }
      fVar1 = (float)param_1[iVar6 * 2 + 2];
      if ((byte)((fVar4 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar1)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar4 == fVar1) << 0xe) >> 8)) - 1) < 0x40) break;
      iVar5 = param_1[iVar6 * 2 + 2];
      param_1[param_2 * 2 + 1] = param_1[iVar6 * 2 + 1];
      param_1[param_2 * 2 + 2] = iVar5;
      local_30 = iVar6 * 2;
      iVar5 = local_30 + 1;
      local_2c = *param_1;
      param_2 = iVar6;
    } while (iVar5 < local_2c);
  }
  param_1[param_2 * 2 + 1] = iVar3;
  param_1[param_2 * 2 + 2] = (int)fVar4;
  return;
}


// Heap_SiftUp__14CQueuePriority  @ 000cb198
void Heap_SiftUp__14CQueuePriority(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *param_1 + -1;
  while( true ) {
    if (iVar4 == 0) {
      return;
    }
    iVar5 = (iVar4 + -1) / 2;
    if ((float)param_1[iVar5 * 2 + 2] <= (float)param_1[iVar4 * 2 + 2]) break;
    iVar1 = param_1[iVar4 * 2 + 1];
    iVar2 = (param_1 + iVar4 * 2 + 1)[1];
    iVar3 = (param_1 + iVar5 * 2 + 1)[1];
    param_1[iVar4 * 2 + 1] = param_1[iVar5 * 2 + 1];
    param_1[iVar4 * 2 + 2] = iVar3;
    param_1[iVar5 * 2 + 1] = iVar1;
    param_1[iVar5 * 2 + 2] = iVar2;
    iVar4 = iVar5;
  }
  return;
}


