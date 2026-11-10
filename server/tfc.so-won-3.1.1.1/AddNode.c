// AddNode__11CNodeViewerii  @ 000cad28
void AddNode__11CNodeViewerii(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 0x460);
  if ((iVar2 < 0x80) && (param_2 != param_3)) {
    iVar4 = 0;
    iVar5 = param_1 + 0x664;
    if (0 < iVar2) {
      do {
        iVar1 = iVar4 * 4;
        iVar3 = *(int *)(iVar1 + param_1 + 0x464);
        if ((iVar3 == param_2) && (*(int *)(iVar1 + iVar5) == param_3)) {
          return;
        }
        if ((iVar3 == param_3) && (*(int *)(iVar1 + iVar5) == param_2)) {
          return;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
    *(int *)(param_1 + 0x464 + iVar2 * 4) = param_2;
    *(int *)(*(int *)(param_1 + 0x460) * 4 + iVar5) = param_3;
    *(int *)(param_1 + 0x460) = *(int *)(param_1 + 0x460) + 1;
  }
  return;
}


