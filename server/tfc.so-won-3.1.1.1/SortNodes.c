// SortNodes__6CGraph  @ 000c8c44
void SortNodes__6CGraph(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  bool bVar9;
  int local_94;
  undefined1 *local_88;
  undefined4 *local_84;
  undefined4 *local_78;
  int local_64;
  int local_60;
  undefined4 local_5c [6];
  undefined1 local_44 [16];
  undefined4 local_34 [12];
  
  local_60 = 1;
  local_64 = 1;
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x4c) = 0;
  iVar4 = *(int *)(param_1 + 0x18);
  if (1 < iVar4) {
    do {
      iVar7 = local_64 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x4c + local_64 * 0x58) = 0xffffffff;
      iVar4 = *(int *)(param_1 + 0x18);
      local_64 = iVar7;
    } while (iVar7 < iVar4);
  }
  local_64 = 0;
  if (0 < iVar4) {
    do {
      local_94 = 0;
      iVar4 = local_64 * 0x58;
      local_84 = *(undefined4 **)(param_1 + 0xc);
      if (0 < *(int *)((int)local_84 + 0x20 + iVar4)) {
        do {
          iVar7 = *(int *)(*(int *)(param_1 + 0x10) + 4 +
                          (local_94 + *(int *)(iVar4 + 0x24 + (int)local_84)) * 0x18) * 0x58;
          if (*(int *)((int)local_84 + 0x4c + iVar7) == -1) {
            *(int *)((int)local_84 + 0x4c + iVar7) = local_60;
            local_60 = local_60 + 1;
            local_84 = *(undefined4 **)(param_1 + 0xc);
          }
          local_94 = local_94 + 1;
        } while (local_94 < *(int *)((int)local_84 + 0x20 + iVar4));
      }
      local_64 = local_64 + 1;
      iVar4 = *(int *)(param_1 + 0x18);
    } while (local_64 < iVar4);
  }
  local_64 = 0;
  if (0 < iVar4) {
    do {
      if (*(int *)(*(int *)(param_1 + 0xc) + 0x4c + local_64 * 0x58) == -1) {
        *(int *)(*(int *)(param_1 + 0xc) + 0x4c + local_64 * 0x58) = local_60;
        local_60 = local_60 + 1;
        iVar4 = *(int *)(param_1 + 0x18);
      }
      local_64 = local_64 + 1;
    } while (local_64 < iVar4);
  }
  local_64 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    do {
      iVar4 = local_64 * 0x18;
      *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar4) =
           *(undefined4 *)
            (*(int *)(param_1 + 0xc) + 0x4c + *(int *)(*(int *)(param_1 + 0x10) + iVar4) * 0x58);
      *(undefined4 *)(*(int *)(param_1 + 0x10) + 4 + iVar4) =
           *(undefined4 *)
            (*(int *)(param_1 + 0xc) + 0x4c + *(int *)(*(int *)(param_1 + 0x10) + 4 + iVar4) * 0x58)
      ;
      local_64 = local_64 + 1;
    } while (local_64 < *(int *)(param_1 + 0x1c));
  }
  for (local_64 = 0; local_64 < *(int *)(param_1 + 0x18); local_64 = local_64 + 1) {
    iVar4 = local_64 * 0x58;
    local_84 = *(undefined4 **)(param_1 + 0xc);
    if (*(int *)((int)local_84 + 0x4c + iVar4) != local_64) {
      do {
        iVar2 = *(int *)((int)local_84 + 0x4c + iVar4);
        iVar7 = (int)local_84 + iVar2 * 0x58;
        local_88 = local_44;
        local_84 = (undefined4 *)0x2;
        puVar5 = (undefined1 *)(iVar7 + 0x18);
        do {
          uVar1 = *puVar5;
          puVar5 = puVar5 + 1;
          *local_88 = uVar1;
          local_88 = local_88 + 1;
          bVar9 = local_84 != (undefined4 *)0x0;
          local_84 = (undefined4 *)((int)local_84 + -1);
        } while (bVar9);
        local_88 = (undefined1 *)0x3;
        local_84 = (undefined4 *)(iVar7 + 0x28);
        local_78 = local_34;
        do {
          uVar3 = local_84[1];
          *local_78 = *local_84;
          local_78[1] = uVar3;
          local_78 = local_78 + 2;
          local_84 = local_84 + 2;
          bVar9 = local_88 != (undefined1 *)0x0;
          local_88 = (undefined1 *)((int)local_88 + -1);
        } while (bVar9);
        puVar6 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar4);
        puVar8 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar2 * 0x58);
        for (iVar7 = 0x16; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
        }
        puVar6 = local_5c;
        puVar8 = (undefined4 *)(iVar4 + *(int *)(param_1 + 0xc));
        for (iVar7 = 0x16; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
        }
        local_84 = *(undefined4 **)(param_1 + 0xc);
      } while (*(int *)((int)local_84 + 0x4c + iVar4) != local_64);
    }
  }
  return;
}


