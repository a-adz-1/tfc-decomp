// end_fde_sort  @ 00120890
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 end_fde_sort(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puStack_28;
  uint local_c;
  
  iVar1 = param_1[1];
  if (iVar1 != param_2) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  fde_split(param_1,param_1 + 2);
  if (param_1[3] + param_1[1] != iVar1) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  puVar2 = (undefined4 *)param_1[2];
  local_c = param_1[3];
  uVar7 = local_c;
  do {
    if (uVar7 == 0) {
      if (1 < local_c) {
        puStack_28 = puVar2 + local_c;
        do {
          puStack_28 = puStack_28 + -1;
          local_c = local_c - 1;
          uVar4 = *puVar2;
          *puVar2 = *puStack_28;
          *puStack_28 = uVar4;
          uVar7 = 0;
          if (1 < local_c) {
            do {
              uVar8 = uVar7 * 2 + 2;
              if (uVar8 < local_c) {
                iVar1 = *(int *)(puVar2[uVar7 * 2 + 2] + 8);
                if ((iVar1 == *(int *)(puVar2[uVar7 * 2 + 1] + 8) ||
                     iVar1 - *(int *)(puVar2[uVar7 * 2 + 1] + 8) < 0) ||
                   (iVar5 = puVar2[uVar7], iVar1 - *(int *)(iVar5 + 8) < 1)) goto LAB_00120a10;
                puVar2[uVar7] = puVar2[uVar7 * 2 + 2];
                puVar2[uVar7 * 2 + 2] = iVar5;
              }
              else {
LAB_00120a10:
                iVar1 = puVar2[uVar7];
                iVar5 = *(int *)(iVar1 + 8);
                iVar6 = *(int *)(puVar2[uVar7 * 2 + 1] + 8);
                if (iVar6 == iVar5 || iVar6 - iVar5 < 0) break;
                puVar2[uVar7] = puVar2[uVar7 * 2 + 1];
                puVar2[uVar7 * 2 + 1] = iVar1;
                uVar8 = uVar7 * 2 + 1;
              }
              uVar7 = uVar8;
            } while (uVar8 * 2 + 1 < local_c);
          }
        } while (1 < local_c);
      }
      fde_merge(param_1,param_1 + 2);
      free((void *)param_1[2]);
      return *param_1;
    }
    uVar7 = uVar7 - 1;
    uVar8 = uVar7;
    while (iVar1 = uVar8 * 2, iVar1 + 1U < local_c) {
      if (iVar1 + 2U < local_c) {
        iVar5 = *(int *)(puVar2[uVar8 * 2 + 2] + 8);
        if ((iVar5 == *(int *)(puVar2[uVar8 * 2 + 1] + 8) ||
             iVar5 - *(int *)(puVar2[uVar8 * 2 + 1] + 8) < 0) ||
           (iVar6 = puVar2[uVar8], iVar5 - *(int *)(iVar6 + 8) < 1)) goto LAB_00120948;
        puVar2[uVar8] = puVar2[uVar8 * 2 + 2];
        puVar2[uVar8 * 2 + 2] = iVar6;
        uVar8 = iVar1 + 2;
      }
      else {
LAB_00120948:
        iVar5 = puVar2[uVar8];
        iVar6 = *(int *)(iVar5 + 8);
        iVar3 = *(int *)(puVar2[uVar8 * 2 + 1] + 8);
        if (iVar3 == iVar6 || iVar3 - iVar6 < 0) break;
        puVar2[uVar8] = puVar2[uVar8 * 2 + 1];
        puVar2[uVar8 * 2 + 1] = iVar5;
        uVar8 = iVar1 + 1;
      }
    }
  } while( true );
}


