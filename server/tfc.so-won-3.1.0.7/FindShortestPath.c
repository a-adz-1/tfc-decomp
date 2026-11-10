// FindShortestPath__6CGraphPiiiii  @ 000c4148
int FindShortestPath__6CGraphPiiiii
              (int *param_1,int *param_2,int param_3,int param_4,undefined4 param_5,uint param_6)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *local_344;
  uint local_334;
  uint local_32c;
  float local_328;
  int local_324 [201];
  
  if ((*param_1 == 0) || (param_1[1] == 0)) {
    (*DAT_001c1114)(2,"Graph not ready!\n");
    return 0;
  }
  if ((param_3 < 0) || (param_1[6] < param_3)) {
    (*DAT_001c1114)(2,"Can\'t build a path, iStart is %d!\n",param_3);
    return 0;
  }
  if (param_3 == param_4) {
    *param_2 = param_4;
    param_2[1] = param_4;
    return 2;
  }
  if (param_1[2] != 0) {
    *param_2 = param_3;
    iVar10 = 1;
    while( true ) {
      if (param_3 == param_4) {
        return iVar10;
      }
      local_344 = param_2 + 1;
      iVar7 = NextNodeInRoute__6CGraphiiii(param_1,param_3,param_4,param_5,(param_6 & 0x340) != 0);
      if (param_3 == iVar7) break;
      if (9 < iVar10) {
        return iVar10;
      }
      *local_344 = iVar7;
      iVar10 = iVar10 + 1;
      param_3 = iVar7;
      param_2 = local_344;
    }
    return 0;
  }
  __14CQueuePriority(local_324);
  switch(param_5) {
  case 0:
    local_32c = 1;
    break;
  case 1:
    local_32c = 2;
    break;
  case 2:
    local_32c = 4;
    break;
  case 3:
    local_32c = 8;
  }
  local_334 = 0;
  if (0 < param_1[6]) {
    iVar10 = 0;
    do {
      *(undefined4 *)(param_1[3] + 0x48 + iVar10) = 0xbf800000;
      iVar10 = iVar10 + 0x58;
      local_334 = local_334 + 1;
    } while ((int)local_334 < param_1[6]);
  }
  *(undefined4 *)(param_1[3] + 0x48 + param_3 * 0x58) = 0;
  *(int *)(param_1[3] + 0x4c + param_3 * 0x58) = param_3;
  Insert__14CQueuePriorityif(local_324,param_3,0);
  while ((local_324[0] != 0 &&
         (iVar10 = Remove__14CQueuePriorityRf(local_324,&local_328), iVar10 != param_4))) {
    iVar7 = iVar10 * 0x58;
    iVar2 = param_1[3];
    local_334 = 0;
    if (0 < *(int *)(iVar2 + iVar7 + 0x20)) {
      do {
        iVar3 = param_1[3];
        iVar4 = param_1[4];
        iVar5 = *(int *)(iVar4 + 4 + (local_334 + *(int *)(iVar3 + 0x24 + iVar7)) * 0x18);
        iVar8 = (local_334 + *(int *)(iVar3 + 0x24 + iVar7)) * 0x18;
        if (((local_32c & *(uint *)(iVar4 + 0x10 + iVar8)) == local_32c) &&
           ((*(int *)(iVar4 + 8 + iVar8) == 0 ||
            (iVar8 = HandleLinkEnt__6CGraphiP9entvars_siQ26CGraph9NODEQUERY
                               (param_1,iVar10,
                                *(undefined4 *)
                                 (iVar4 + 8 + (local_334 + *(int *)(iVar3 + 0x24 + iVar7)) * 0x18),
                                param_6,1), iVar8 != 0)))) {
          fVar6 = local_328 +
                  *(float *)(param_1[4] + 0x14 +
                            (local_334 + *(int *)(param_1[3] + 0x24 + iVar7)) * 0x18);
          fVar1 = *(float *)(param_1[3] + 0x48 + iVar5 * 0x58);
          if ((fVar1 < -0.5) ||
             (fVar1 = fVar1 - 0.001,
             0x3f < (byte)((fVar1 < fVar6 |
                            (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar6)) << 10) >> 8) |
                           (byte)((ushort)((ushort)(fVar1 == fVar6) << 0xe) >> 8)) - 1))) {
            *(float *)(param_1[3] + 0x48 + iVar5 * 0x58) = fVar6;
            *(int *)(param_1[3] + 0x4c + iVar5 * 0x58) = iVar10;
            Insert__14CQueuePriorityif(local_324,iVar5,fVar6);
          }
        }
        local_334 = local_334 + 1;
      } while ((int)local_334 < *(int *)(iVar2 + iVar7 + 0x20));
    }
  }
  fVar1 = *(float *)(param_1[3] + 0x48 + param_4 * 0x58);
  if (0x3f < (byte)((-0.5 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == -0.5) << 0xe) >> 8)) - 1)) {
    return 0;
  }
  iVar10 = 1;
  if (param_4 != param_3) {
    iVar7 = param_4;
    do {
      iVar10 = iVar10 + 1;
      iVar7 = *(int *)(param_1[3] + 0x4c + iVar7 * 0x58);
    } while (iVar7 != param_3);
  }
  local_334 = iVar10 - 1;
  if ((int)local_334 < 0) {
    return iVar10;
  }
  param_2 = param_2 + local_334;
  uVar9 = ~local_334 & 3;
  if (-1 < (int)local_334) {
    if (uVar9 == 0) goto LAB_000c46b4;
    if (uVar9 < 3) {
      if (uVar9 < 2) {
        *param_2 = param_4;
        param_4 = *(int *)(param_1[3] + 0x4c + param_4 * 0x58);
        param_2 = param_2 + -1;
        local_334 = iVar10 - 2;
      }
      *param_2 = param_4;
      param_4 = *(int *)(param_1[3] + 0x4c + param_4 * 0x58);
      param_2 = param_2 + -1;
      local_334 = local_334 - 1;
    }
  }
  *param_2 = param_4;
  param_4 = *(int *)(param_1[3] + 0x4c + param_4 * 0x58);
  param_2 = param_2 + -1;
  local_334 = local_334 - 1;
  if ((int)local_334 < 0) {
    return iVar10;
  }
LAB_000c46b4:
  do {
    *param_2 = param_4;
    iVar7 = *(int *)(param_1[3] + 0x4c + param_4 * 0x58);
    param_2[-1] = iVar7;
    iVar7 = *(int *)(param_1[3] + 0x4c + iVar7 * 0x58);
    param_2[-2] = iVar7;
    iVar7 = *(int *)(param_1[3] + 0x4c + iVar7 * 0x58);
    param_2[-3] = iVar7;
    param_4 = *(int *)(param_1[3] + 0x4c + iVar7 * 0x58);
    param_2 = param_2 + -4;
    local_334 = local_334 - 4;
  } while (-1 < (int)local_334);
  return iVar10;
}


