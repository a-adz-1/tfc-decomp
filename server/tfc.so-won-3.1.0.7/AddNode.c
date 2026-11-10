// AddNode__11CNodeViewerii  @ 000cb930
void AddNode__11CNodeViewerii(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int local_8;
  int *local_4;
  
  if (0x7f < *(int *)(param_1 + 0x450)) {
    return;
  }
  if (param_2 == param_3) {
    return;
  }
  local_8 = 0;
  if (*(int *)(param_1 + 0x450) < 1) goto LAB_000cbaaf;
  piVar4 = (int *)(param_1 + 0x654);
  local_4 = (int *)(param_1 + 0x454);
  uVar3 = *(uint *)(param_1 + 0x450) & 3;
  if (*(int *)(param_1 + 0x450) < 1) {
LAB_000cba04:
    if ((*local_4 == param_2) && (*piVar4 == param_3)) {
      return;
    }
    if ((*local_4 == param_3) && (*piVar4 == param_2)) {
      return;
    }
    piVar4 = piVar4 + 1;
    local_4 = local_4 + 1;
    local_8 = local_8 + 1;
    if (*(int *)(param_1 + 0x450) <= local_8) goto LAB_000cbaaf;
  }
  else if (uVar3 != 0) {
    if (1 < uVar3) {
      if (2 < uVar3) {
        if ((*(int *)(param_1 + 0x454) == param_2) && (*(int *)(param_1 + 0x654) == param_3)) {
          return;
        }
        if ((*local_4 == param_3) && (*piVar4 == param_2)) {
          return;
        }
        piVar4 = (int *)(param_1 + 0x658);
        local_4 = (int *)(param_1 + 0x458);
        local_8 = 1;
      }
      if ((*local_4 == param_2) && (*piVar4 == param_3)) {
        return;
      }
      if ((*local_4 == param_3) && (*piVar4 == param_2)) {
        return;
      }
      piVar4 = piVar4 + 1;
      local_4 = local_4 + 1;
      local_8 = local_8 + 1;
    }
    goto LAB_000cba04;
  }
  do {
    if ((*local_4 == param_2) && (*piVar4 == param_3)) {
      return;
    }
    if ((*local_4 == param_3) && (*piVar4 == param_2)) {
      return;
    }
    if ((local_4[1] == param_2) && (piVar4[1] == param_3)) {
      return;
    }
    if ((local_4[1] == param_3) && (piVar4[1] == param_2)) {
      return;
    }
    if ((local_4[2] == param_2) && (piVar4[2] == param_3)) {
      return;
    }
    if ((local_4[2] == param_3) && (piVar4[2] == param_2)) {
      return;
    }
    if ((local_4[3] == param_2) && (piVar4[3] == param_3)) {
      return;
    }
    if ((local_4[3] == param_3) && (piVar4[3] == param_2)) {
      return;
    }
    piVar4 = piVar4 + 4;
    local_4 = local_4 + 4;
    iVar2 = local_8 + 4;
    piVar1 = (int *)(local_8 + 0x454);
    local_8 = iVar2;
  } while (iVar2 < *piVar1);
LAB_000cbaaf:
  *(int *)(*(int *)(param_1 + 0x450) * 4 + 0x454 + param_1) = param_2;
  *(int *)(*(int *)(param_1 + 0x450) * 4 + 0x654 + param_1) = param_3;
  *(int *)(param_1 + 0x450) = *(int *)(param_1 + 0x450) + 1;
  return;
}


