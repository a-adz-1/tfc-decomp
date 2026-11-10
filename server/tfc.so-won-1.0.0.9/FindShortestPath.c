// FindShortestPath__6CGraphPiiiii  @ 000c9d60
int FindShortestPath__6CGraphPiiiii
              (int *param_1,int *param_2,int param_3,int param_4,int param_5,uint param_6)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_354;
  uint local_330;
  float local_32c;
  int local_328 [201];
  
  if ((*param_1 == 0) || (param_1[1] == 0)) {
    (*DAT_001755b4)(2,"Graph not ready!\n");
  }
  else if ((param_3 < 0) || (param_1[6] < param_3)) {
    (*DAT_001755b4)(2,"Can\'t build a path, iStart is %d!\n",param_3);
  }
  else {
    if (param_3 == param_4) {
      *param_2 = param_4;
      param_2[1] = param_4;
      return 2;
    }
    if (param_1[2] == 0) {
      __14CQueuePriority(local_328);
      if (param_5 == 1) {
        local_330 = 2;
      }
      else if (param_5 < 2) {
        if (param_5 == 0) {
          local_330 = 1;
        }
      }
      else if (param_5 == 2) {
        local_330 = 4;
      }
      else if (param_5 == 3) {
        local_330 = 8;
      }
      iVar6 = 0;
      if (0 < param_1[6]) {
        do {
          *(undefined4 *)(param_1[3] + 0x48 + iVar6 * 0x58) = 0xbf800000;
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_1[6]);
      }
      *(undefined4 *)(param_1[3] + 0x48 + param_3 * 0x58) = 0;
      *(int *)(param_1[3] + 0x4c + param_3 * 0x58) = param_3;
      Insert__14CQueuePriorityif(local_328,param_3,0);
      while ((local_328[0] != 0 &&
             (iVar6 = Remove__14CQueuePriorityRf(local_328,&local_32c), iVar6 != param_4))) {
        iVar9 = param_1[3] + iVar6 * 0x58;
        if (0 < *(int *)(iVar9 + 0x20)) {
          iVar8 = iVar6 * 0x58;
          iVar10 = 0;
          do {
            iVar2 = param_1[3];
            iVar3 = param_1[4];
            iVar4 = *(int *)(iVar3 + 4 + (*(int *)(iVar2 + 0x24 + iVar8) + iVar10) * 0x18);
            iVar7 = (*(int *)(iVar2 + 0x24 + iVar8) + iVar10) * 0x18;
            if (((local_330 & *(uint *)(iVar3 + 0x10 + iVar7)) == local_330) &&
               ((*(int *)(iVar3 + 8 + iVar7) == 0 ||
                (iVar7 = HandleLinkEnt__6CGraphiP9entvars_tiQ26CGraph9NODEQUERY
                                   (param_1,iVar6,
                                    *(undefined4 *)
                                     (iVar3 + 8 + (*(int *)(iVar2 + 0x24 + iVar8) + iVar10) * 0x18),
                                    param_6,1), iVar7 != 0)))) {
              fVar5 = local_32c +
                      *(float *)(param_1[4] + 0x14 +
                                (*(int *)(param_1[3] + 0x24 + iVar6 * 0x58) + iVar10) * 0x18);
              fVar1 = *(float *)(param_1[3] + 0x48 + iVar4 * 0x58);
              if ((fVar1 < -0.5) || (fVar5 < fVar1 - 0.001)) {
                *(float *)(param_1[3] + 0x48 + iVar4 * 0x58) = fVar5;
                *(int *)(param_1[3] + 0x4c + iVar4 * 0x58) = iVar6;
                Insert__14CQueuePriorityif(local_328,iVar4,fVar5);
              }
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < *(int *)(iVar9 + 0x20));
        }
      }
      if (-0.5 <= *(float *)(param_1[3] + 0x48 + param_4 * 0x58)) {
        local_354 = 1;
        iVar6 = local_354;
        if (param_4 != param_3) {
          iVar9 = param_4;
          do {
            local_354 = local_354 + 1;
            iVar9 = *(int *)(param_1[3] + 0x4c + iVar9 * 0x58);
            iVar6 = local_354;
          } while (iVar9 != param_3);
        }
        while (iVar6 = iVar6 + -1, -1 < iVar6) {
          param_2[iVar6] = param_4;
          param_4 = *(int *)(param_1[3] + 0x4c + param_4 * 0x58);
        }
        return local_354;
      }
    }
    else {
      *param_2 = param_3;
      local_354 = 1;
      while( true ) {
        if (param_3 == param_4) {
          return local_354;
        }
        iVar6 = NextNodeInRoute__6CGraphiiii(param_1,param_3,param_4,param_5,(param_6 & 0x340) != 0)
        ;
        if (param_3 == iVar6) break;
        if (9 < local_354) {
          return local_354;
        }
        param_2[local_354] = iVar6;
        local_354 = local_354 + 1;
        param_3 = iVar6;
      }
    }
  }
  return 0;
}


