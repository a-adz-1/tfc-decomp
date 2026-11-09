// AddNode__11CNodeViewerii  @ 000cfcd0
void AddNode__11CNodeViewerii(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x3d4) < 0x80) && (param_2 != param_3)) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x3d4)) {
      do {
        if ((*(int *)(iVar1 * 4 + param_1 + 0x3d8) == param_2) &&
           (*(int *)(iVar1 * 4 + param_1 + 0x5d8) == param_3)) {
          return;
        }
        if ((*(int *)(iVar1 * 4 + param_1 + 0x3d8) == param_3) &&
           (*(int *)(iVar1 * 4 + param_1 + 0x5d8) == param_2)) {
          return;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x3d4));
    }
    *(int *)(*(int *)(param_1 + 0x3d4) * 4 + 0x3d8 + param_1) = param_2;
    *(int *)(*(int *)(param_1 + 0x3d4) * 4 + 0x5d8 + param_1) = param_3;
    *(int *)(param_1 + 0x3d4) = *(int *)(param_1 + 0x3d4) + 1;
  }
  return;
}


