// FindShortestPath__6CGraphPiiiii  @ 000c4680
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FindShortestPath__6CGraphPiiiii
              (int *param_1,int *param_2,int param_3,int param_4,int param_5,uint param_6)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  int local_368;
  int local_358;
  uint uStack_33c;
  int local_338;
  int local_334;
  float fStack_32c;
  int aiStack_328 [201];
  
  if ((*param_1 == 0) || (param_1[1] == 0)) {
    (*DAT_0019f794)(2,"Graph not ready!\n");
  }
  else if ((param_3 < 0) || (param_1[6] < param_3)) {
    (*DAT_0019f794)(2,"Can\'t build a path, iStart is %d!\n",param_3);
  }
  else {
    if (param_3 == param_4) {
      *param_2 = param_4;
      param_2[1] = param_4;
      return 2;
    }
    if (param_1[2] != 0) {
      local_338 = 1;
      *param_2 = param_3;
      local_334 = param_3;
      do {
        local_358 = local_334;
        pcVar9 = (char *)(*(int *)((uint)((param_6 & 0x340) != 0) * 4 + param_5 * 8 +
                                  param_1[3] + 0x28 + local_334 * 0x58) + param_1[5]);
        local_368 = param_4 + 1;
        while (0 < local_368) {
          cVar2 = *pcVar9;
          if (cVar2 < '\0') {
            if (local_368 <= -cVar2) {
              local_358 = param_4;
              break;
            }
            local_368 = local_368 - -cVar2;
            pcVar9 = pcVar9 + 1;
          }
          else {
            if (cVar2 + 1 < local_368) {
              local_368 = (local_368 - cVar2) + -1;
            }
            else {
              local_358 = local_334 + pcVar9[1];
              iVar6 = param_1[6];
              if (local_358 < iVar6) {
                if (local_358 < 0) {
                  local_358 = local_358 + iVar6;
                }
              }
              else {
                local_358 = local_358 - iVar6;
              }
              local_368 = 0;
            }
            pcVar9 = pcVar9 + 2;
          }
        }
        if (local_334 == local_358) {
          return 0;
        }
        if (9 < local_338) {
          return local_338;
        }
        local_334 = local_358;
        param_2[local_338] = local_358;
        local_338 = local_338 + 1;
        if (local_358 == param_4) {
          return local_338;
        }
      } while( true );
    }
    __14CQueuePriority(aiStack_328);
    switch(param_5) {
    case 0:
      uStack_33c = 1;
      break;
    case 1:
      uStack_33c = 2;
      break;
    case 2:
      uStack_33c = 4;
      break;
    case 3:
      uStack_33c = 8;
    }
    iVar6 = 0;
    if (0 < param_1[6]) {
      do {
        iVar10 = iVar6 + 1;
        *(undefined4 *)(param_1[3] + 0x48 + iVar6 * 0x58) = 0xbf800000;
        iVar6 = iVar10;
      } while (iVar10 < param_1[6]);
    }
    *(undefined4 *)(param_1[3] + 0x48 + param_3 * 0x58) = 0;
    *(int *)(param_1[3] + 0x4c + param_3 * 0x58) = param_3;
    Insert__14CQueuePriorityif(aiStack_328,param_3,0);
    while ((aiStack_328[0] != 0 &&
           (iVar6 = Remove__14CQueuePriorityRf(aiStack_328,&fStack_32c), iVar6 != param_4))) {
      iVar10 = param_1[3] + iVar6 * 0x58;
      if (0 < *(int *)(iVar10 + 0x20)) {
        iVar11 = 0;
        do {
          iVar8 = iVar6 * 0x58;
          iVar3 = param_1[4];
          iVar4 = *(int *)(iVar3 + 4 + (iVar11 + *(int *)(iVar8 + 0x24 + param_1[3])) * 0x18);
          iVar7 = (iVar11 + *(int *)(param_1[3] + 0x24 + iVar8)) * 0x18;
          if (((uStack_33c & *(uint *)(iVar3 + 0x10 + iVar7)) == uStack_33c) &&
             ((*(int *)(iVar3 + 8 + iVar7) == 0 ||
              (iVar7 = HandleLinkEnt__6CGraphiP9entvars_siQ26CGraph9NODEQUERY
                                 (param_1,iVar6,*(undefined4 *)(iVar3 + 8 + iVar7),param_6,1),
              iVar7 != 0)))) {
            iVar3 = param_1[3];
            fVar5 = fStack_32c +
                    *(float *)(param_1[4] + 0x14 + (iVar11 + *(int *)(iVar3 + 0x24 + iVar8)) * 0x18)
            ;
            iVar7 = iVar4 * 0x58;
            fVar1 = *(float *)(iVar3 + 0x48 + iVar7);
            if ((fVar1 < (float)_FUN_0014e548) ||
               (fVar1 = fVar1 - 0.001,
               0x3f < (byte)((fVar1 < fVar5 |
                              (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar5)) << 10) >> 8) |
                             (byte)((ushort)((ushort)(fVar1 == fVar5) << 0xe) >> 8)) - 1))) {
              *(float *)(iVar3 + 0x48 + iVar7) = fVar5;
              *(int *)(param_1[3] + 0x4c + iVar7) = iVar6;
              Insert__14CQueuePriorityif(aiStack_328,iVar4,fVar5);
            }
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < *(int *)(iVar10 + 0x20));
      }
    }
    if (_FUN_0014e548 <= (double)*(float *)(param_1[3] + 0x48 + param_4 * 0x58)) {
      local_338 = 1;
      for (iVar6 = param_4; iVar10 = local_338, iVar6 != param_3;
          iVar6 = *(int *)(param_1[3] + 0x4c + iVar6 * 0x58)) {
        local_338 = local_338 + 1;
      }
      while (iVar10 = iVar10 + -1, -1 < iVar10) {
        param_2[iVar10] = param_4;
        param_4 = *(int *)(param_1[3] + 0x4c + param_4 * 0x58);
      }
      return local_338;
    }
  }
  return 0;
}


