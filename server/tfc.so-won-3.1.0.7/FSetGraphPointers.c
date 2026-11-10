// FSetGraphPointers__6CGraph  @ 000c8f0c
undefined4 FSetGraphPointers__6CGraph(int param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  local_c = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    iVar5 = 0;
    do {
      if (*(int *)(*(int *)(param_1 + 0x10) + 8 + iVar5) != 0) {
        local_8 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc + iVar5);
        local_4 = 0;
        iVar3 = (*DAT_001c1058)(0,"model",&local_8);
        bVar2 = false;
        if (iVar3 == 0) {
LAB_000c8f9b:
          bVar2 = true;
        }
        else {
          iVar4 = (*DAT_001c1138)(iVar3);
          if (iVar4 == 0) goto LAB_000c8f9b;
        }
        if (bVar2) {
          (*DAT_001c1114)(2,"**Could not find model %s\n",&local_8);
          *(undefined4 *)(*(int *)(param_1 + 0x10) + 8 + iVar5) = 0;
        }
        else {
          iVar4 = iVar3 + 0x80;
          if (iVar3 == 0) {
            iVar4 = 0;
          }
          *(int *)(*(int *)(param_1 + 0x10) + 8 + iVar5) = iVar4;
          iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 8 + iVar5);
          if ((*(byte *)(iVar3 + 0x1a6) & 1) == 0) {
            piVar1 = (int *)(iVar3 + 0x1a4);
            *piVar1 = *piVar1 + 0x10000;
          }
        }
      }
      iVar5 = iVar5 + 0x18;
      local_c = local_c + 1;
    } while (local_c < *(int *)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 4) = 1;
  return 1;
}


