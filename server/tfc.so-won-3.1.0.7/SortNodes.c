// SortNodes__6CGraph  @ 000c95c4
void SortNodes__6CGraph(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_78;
  int local_64;
  int local_5c;
  undefined4 local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined2 local_8;
  undefined2 local_6;
  undefined4 local_4;
  
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x4c) = 0;
  local_5c = 1;
  iVar4 = 1;
  if (1 < *(int *)(param_1 + 0x18)) {
    iVar3 = 0x58;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x4c + iVar3) = 0xffffffff;
      iVar3 = iVar3 + 0x58;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x18));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    iVar3 = 0;
    do {
      for (local_78 = 0; iVar2 = *(int *)(param_1 + 0xc), local_78 < *(int *)(iVar2 + 0x20 + iVar3);
          local_78 = local_78 + 1) {
        iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 4 +
                        (local_78 + *(int *)(iVar2 + 0x24 + iVar3)) * 0x18) * 0x58;
        if (*(int *)(iVar2 + 0x4c + iVar1) == -1) {
          *(int *)(iVar2 + 0x4c + iVar1) = local_5c;
          local_5c = local_5c + 1;
        }
      }
      iVar3 = iVar3 + 0x58;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x18));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    iVar3 = 0;
    do {
      if (*(int *)(*(int *)(param_1 + 0xc) + 0x4c + iVar3) == -1) {
        *(int *)(*(int *)(param_1 + 0xc) + 0x4c + iVar3) = local_5c;
        local_5c = local_5c + 1;
      }
      iVar3 = iVar3 + 0x58;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x18));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    iVar3 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x10) + iVar3) =
           *(undefined4 *)
            (*(int *)(param_1 + 0xc) + 0x4c + *(int *)(*(int *)(param_1 + 0x10) + iVar3) * 0x58);
      *(undefined4 *)(*(int *)(param_1 + 0x10) + 4 + iVar3) =
           *(undefined4 *)
            (*(int *)(param_1 + 0xc) + 0x4c + *(int *)(*(int *)(param_1 + 0x10) + 4 + iVar3) * 0x58)
      ;
      iVar3 = iVar3 + 0x18;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x1c));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    local_64 = 0;
    do {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x4c + local_64);
      while (iVar3 != iVar4) {
        iVar3 = *(int *)(param_1 + 0xc);
        puVar6 = (undefined4 *)(iVar3 + *(int *)(iVar3 + 0x4c + local_64) * 0x58);
        local_58[0] = *puVar6;
        local_58[1] = puVar6[1];
        local_58[2] = puVar6[2];
        local_58[3] = puVar6[3];
        local_48 = puVar6[4];
        local_44 = puVar6[5];
        local_40 = *(undefined1 *)(puVar6 + 6);
        local_3f = *(undefined1 *)((int)puVar6 + 0x19);
        local_3e = *(undefined1 *)((int)puVar6 + 0x1a);
        local_3c = puVar6[7];
        local_38 = puVar6[8];
        local_34 = puVar6[9];
        local_30 = puVar6[10];
        local_2c = puVar6[0xb];
        local_28 = puVar6[0xc];
        local_24 = puVar6[0xd];
        local_20 = puVar6[0xe];
        local_1c = puVar6[0xf];
        local_18 = puVar6[0x10];
        local_14 = puVar6[0x11];
        local_10 = puVar6[0x12];
        local_c = puVar6[0x13];
        local_8 = *(undefined2 *)(puVar6 + 0x14);
        local_6 = *(undefined2 *)((int)puVar6 + 0x52);
        local_4 = puVar6[0x15];
        puVar5 = (undefined4 *)(local_64 + iVar3);
        for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        puVar6 = local_58;
        puVar5 = (undefined4 *)(local_64 + *(int *)(param_1 + 0xc));
        for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar5 = puVar5 + 1;
        }
        iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x4c + local_64);
      }
      local_64 = local_64 + 0x58;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x18));
  }
  return;
}


