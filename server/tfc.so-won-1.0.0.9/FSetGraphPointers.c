// FSetGraphPointers__6CGraph  @ 000cde10
undefined4 FSetGraphPointers__6CGraph(int param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_c;
  undefined1 local_8;
  
  iVar5 = 0;
  do {
    if (*(int *)(param_1 + 0x1c) <= iVar5) {
      *(undefined4 *)(param_1 + 4) = 1;
      return 1;
    }
    if (*(int *)(*(int *)(param_1 + 0x10) + 8 + iVar5 * 0x18) != 0) {
      local_c = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc + iVar5 * 0x18);
      local_8 = 0;
      iVar3 = (*DAT_001754f8)(0,"model",&local_c);
      bVar2 = false;
      if (iVar3 == 0) {
LAB_000cde6e:
        bVar2 = true;
      }
      else {
        iVar4 = (*DAT_001755d8)(iVar3);
        if (iVar4 == 0) goto LAB_000cde6e;
      }
      if (bVar2) {
        (*DAT_001755b4)(2,"**Could not find model %s\n",&local_c);
        *(undefined4 *)(*(int *)(param_1 + 0x10) + 8 + iVar5 * 0x18) = 0;
      }
      else {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = iVar3 + 0xdc;
        }
        *(int *)(*(int *)(param_1 + 0x10) + 8 + iVar5 * 0x18) = iVar3;
        iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 8 + iVar5 * 0x18);
        if ((*(byte *)(iVar3 + 0x186) & 1) == 0) {
          piVar1 = (int *)(iVar3 + 0x184);
          *piVar1 = *piVar1 + 0x10000;
        }
      }
    }
    iVar5 = iVar5 + 1;
  } while( true );
}


