// AddNode__11CNodeViewerii  @ 000c0650
void AddNode__11CNodeViewerii(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int local_8;
  int *local_4;
  
  if (0x7f < *(int *)(param_1 + 0x3e0)) {
    return;
  }
  if (param_2 == param_3) {
    return;
  }
  local_8 = 0;
  if (*(int *)(param_1 + 0x3e0) < 1) goto LAB_000c07cf;
  piVar4 = (int *)(param_1 + 0x5e4);
  local_4 = (int *)(param_1 + 0x3e4);
  uVar3 = *(uint *)(param_1 + 0x3e0) & 3;
  if (*(int *)(param_1 + 0x3e0) < 1) {
LAB_000c0724:
    if ((*local_4 == param_2) && (*piVar4 == param_3)) {
      return;
    }
    if ((*local_4 == param_3) && (*piVar4 == param_2)) {
      return;
    }
    piVar4 = piVar4 + 1;
    local_4 = local_4 + 1;
    local_8 = local_8 + 1;
    if (*(int *)(param_1 + 0x3e0) <= local_8) goto LAB_000c07cf;
  }
  else if (uVar3 != 0) {
    if (1 < uVar3) {
      if (2 < uVar3) {
        if ((*(int *)(param_1 + 0x3e4) == param_2) && (*(int *)(param_1 + 0x5e4) == param_3)) {
          return;
        }
        if ((*local_4 == param_3) && (*piVar4 == param_2)) {
          return;
        }
        piVar4 = (int *)(param_1 + 0x5e8);
        local_4 = (int *)(param_1 + 1000);
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
    goto LAB_000c0724;
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
    piVar1 = (int *)(local_8 + 0x3e4);
    local_8 = iVar2;
  } while (iVar2 < *piVar1);
LAB_000c07cf:
  *(int *)(*(int *)(param_1 + 0x3e0) * 4 + 0x3e4 + param_1) = param_2;
  *(int *)(*(int *)(param_1 + 0x3e0) * 4 + 0x5e4 + param_1) = param_3;
  *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 1;
  return;
}


