// SortNodes__6CGraph  @ 000ce2b0
void SortNodes__6CGraph(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 *local_74;
  undefined4 *local_70;
  int local_60;
  undefined4 auStack_5c [4];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [4];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 auStack_34 [8];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x4c) = 0;
  local_74 = (undefined4 *)0x1;
  local_60 = 1;
  if (1 < *(int *)(param_1 + 0x18)) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x4c + local_60 * 0x58) = 0xffffffff;
      local_60 = local_60 + 1;
    } while (local_60 < *(int *)(param_1 + 0x18));
  }
  for (local_60 = 0; local_60 < *(int *)(param_1 + 0x18); local_60 = local_60 + 1) {
    iVar2 = *(int *)(param_1 + 0xc);
    if (0 < *(int *)(iVar2 + 0x20 + local_60 * 0x58)) {
      iVar3 = 0;
      do {
        iVar6 = *(int *)(*(int *)(param_1 + 0x10) + 4 +
                        (*(int *)(iVar2 + 0x24 + local_60 * 0x58) + iVar3) * 0x18) * 0x58;
        if (*(int *)(iVar2 + 0x4c + iVar6) == -1) {
          *(undefined4 **)(iVar2 + 0x4c + iVar6) = local_74;
          local_74 = (undefined4 *)((int)local_74 + 1);
        }
        iVar3 = iVar3 + 1;
        iVar2 = *(int *)(param_1 + 0xc);
      } while (iVar3 < *(int *)(iVar2 + 0x20 + local_60 * 0x58));
    }
  }
  local_60 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      if (*(int *)(*(int *)(param_1 + 0xc) + 0x4c + local_60 * 0x58) == -1) {
        *(undefined4 **)(*(int *)(param_1 + 0xc) + 0x4c + local_60 * 0x58) = local_74;
        local_74 = (undefined4 *)((int)local_74 + 1);
      }
      local_60 = local_60 + 1;
    } while (local_60 < *(int *)(param_1 + 0x18));
  }
  local_60 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    do {
      iVar2 = local_60 * 0x18;
      *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar2) =
           *(undefined4 *)
            (*(int *)(param_1 + 0xc) + 0x4c + *(int *)(*(int *)(param_1 + 0x10) + iVar2) * 0x58);
      *(undefined4 *)(*(int *)(param_1 + 0x10) + 4 + iVar2) =
           *(undefined4 *)
            (*(int *)(param_1 + 0xc) + 0x4c + *(int *)(*(int *)(param_1 + 0x10) + 4 + iVar2) * 0x58)
      ;
      local_60 = local_60 + 1;
    } while (local_60 < *(int *)(param_1 + 0x1c));
  }
  for (local_60 = 0; local_60 < *(int *)(param_1 + 0x18); local_60 = local_60 + 1) {
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x4c + local_60 * 0x58) != local_60) {
      iVar2 = local_60 * 0x58;
      do {
        iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x4c + local_60 * 0x58);
        puVar7 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar3 * 0x58);
        auStack_5c[0] = *puVar7;
        auStack_5c[1] = puVar7[1];
        auStack_5c[2] = puVar7[2];
        auStack_5c[3] = puVar7[3];
        uStack_4c = puVar7[4];
        uStack_48 = puVar7[5];
        puVar5 = auStack_44;
        local_74 = (undefined4 *)0x2;
        puVar4 = puVar7 + 6;
        do {
          *puVar5 = *(undefined1 *)puVar4;
          puVar5 = puVar5 + 1;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          bVar8 = local_74 != (undefined4 *)0x0;
          local_74 = (undefined4 *)((int)local_74 + -1);
        } while (bVar8);
        uStack_40 = puVar7[7];
        uStack_3c = puVar7[8];
        uStack_38 = puVar7[9];
        local_74 = auStack_34;
        iVar6 = 3;
        local_70 = puVar7 + 10;
        do {
          uVar1 = local_70[1];
          *local_74 = *local_70;
          local_74[1] = uVar1;
          local_74 = local_74 + 2;
          local_70 = local_70 + 2;
          bVar8 = iVar6 != 0;
          iVar6 = iVar6 + -1;
        } while (bVar8);
        uStack_14 = puVar7[0x12];
        uStack_10 = puVar7[0x13];
        uStack_c = *(undefined2 *)(puVar7 + 0x14);
        uStack_a = *(undefined2 *)((int)puVar7 + 0x52);
        uStack_8 = puVar7[0x15];
        puVar4 = (undefined4 *)(iVar2 + *(int *)(param_1 + 0xc));
        puVar7 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar3 * 0x58);
        for (iVar6 = 0x16; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar7 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar7 = puVar7 + 1;
        }
        puVar4 = auStack_5c;
        puVar7 = (undefined4 *)(iVar2 + *(int *)(param_1 + 0xc));
        for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar7 = puVar7 + 1;
        }
      } while (*(int *)(*(int *)(param_1 + 0xc) + 0x4c + iVar2) != local_60);
    }
  }
  return;
}


