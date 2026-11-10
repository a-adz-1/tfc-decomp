// Heap_SiftDown__14CQueuePriorityi  @ 000cd760
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void Heap_SiftDown__14CQueuePriorityi(int *param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = param_2 * 2 + 1;
  iVar4 = param_1[param_2 * 2 + 1];
  fVar5 = (float)param_1[param_2 * 2 + 2];
  if (iVar6 < *param_1) {
    do {
      iVar1 = param_2 * 2 + 2;
      iVar7 = iVar6;
      if (iVar1 < *param_1) {
        fVar2 = (float)param_1[iVar1 * 2 + 2];
        fVar3 = (float)param_1[iVar6 * 2 + 2];
        if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) {
          iVar7 = iVar1;
        }
      }
      fVar2 = (float)param_1[iVar7 * 2 + 2];
      if ((byte)((fVar5 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar5) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar5 == fVar2) << 0xe) >> 8)) - 1) < 0x40) break;
      iVar6 = param_1[iVar7 * 2 + 2];
      param_1[param_2 * 2 + 1] = param_1[iVar7 * 2 + 1];
      param_1[param_2 * 2 + 2] = iVar6;
      iVar6 = iVar7 * 2 + 1;
      param_2 = iVar7;
    } while (iVar6 < *param_1);
  }
  param_1[param_2 * 2 + 1] = iVar4;
  param_1[param_2 * 2 + 2] = (int)fVar5;
  return;
}


// Heap_SiftUp__14CQueuePriority  @ 000cd800
void Heap_SiftUp__14CQueuePriority(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = *param_1 + -1;
  while( true ) {
    if (iVar6 == 0) {
      return;
    }
    iVar7 = (iVar6 + -1) / 2;
    fVar1 = (float)param_1[iVar7 * 2 + 2];
    fVar2 = (float)param_1[iVar6 * 2 + 2];
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) break;
    iVar3 = param_1[iVar6 * 2 + 1];
    iVar4 = param_1[iVar6 * 2 + 2];
    iVar5 = param_1[iVar7 * 2 + 2];
    param_1[iVar6 * 2 + 1] = param_1[iVar7 * 2 + 1];
    param_1[iVar6 * 2 + 2] = iVar5;
    param_1[iVar7 * 2 + 1] = iVar3;
    param_1[iVar7 * 2 + 2] = iVar4;
    iVar6 = iVar7;
  }
  return;
}


