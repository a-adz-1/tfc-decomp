// FSetGraphPointers__6CGraph  @ 000c8988
undefined4 FSetGraphPointers__6CGraph(int param_1)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  undefined4 local_c;
  undefined1 local_8;
  
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    do {
      if (*(int *)(*(int *)(param_1 + 0x10) + 8 + iVar5 * 0x18) != 0) {
        local_c = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc + iVar5 * 0x18);
        local_8 = 0;
        iVar3 = (*DAT_0019f6d8)(0,"model",&local_c);
        bVar2 = false;
        if (iVar3 == 0) {
LAB_000c8a17:
          bVar2 = true;
        }
        else {
          iVar4 = (*DAT_0019f7b8)(iVar3);
          if (iVar4 == 0) goto LAB_000c8a17;
        }
        if (bVar2) {
          (*DAT_0019f794)(2,"**Could not find model %s\n",&local_c);
          *(undefined4 *)(*(int *)(param_1 + 0x10) + 8 + iVar5 * 0x18) = 0;
        }
        else {
          local_1c = iVar3 + 0x80;
          if (iVar3 == 0) {
            local_1c = 0;
          }
          *(int *)(*(int *)(param_1 + 0x10) + 8 + iVar5 * 0x18) = local_1c;
          iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 8 + iVar5 * 0x18);
          uVar1 = *(uint *)(iVar3 + 0x1a4);
          if ((uVar1 & 0x10000) == 0) {
            *(uint *)(iVar3 + 0x1a4) = uVar1 + 0x10000;
          }
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 4) = 1;
  return 1;
}


