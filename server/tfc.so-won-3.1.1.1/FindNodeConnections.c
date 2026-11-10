// FindNodeConnections__11CNodeVieweri  @ 000ca7c0
void FindNodeConnections__11CNodeVieweri(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int local_2c;
  int local_28;
  int iStack_14;
  
  local_28 = param_2;
  local_2c = *(int *)(param_1 + 0x458) + 1;
  pcVar4 = (char *)(*(int *)(*(int *)(param_1 + 0x864) * 8 + DAT_0019fb2c + 0x28 + param_2 * 0x58) +
                   iRam0019fb34);
  while (iVar1 = local_28, 0 < local_2c) {
    cVar2 = *pcVar4;
    if (cVar2 < '\0') {
      iVar1 = *(int *)(param_1 + 0x458);
      if (local_2c <= -cVar2) break;
      local_2c = local_2c - -cVar2;
      pcVar4 = pcVar4 + 1;
    }
    else {
      if (cVar2 + 1 < local_2c) {
        local_2c = (local_2c - cVar2) + -1;
      }
      else {
        local_28 = pcVar4[1] + param_2;
        if (local_28 < DAT_0019fb38) {
          if (local_28 < 0) {
            local_28 = local_28 + DAT_0019fb38;
          }
        }
        else {
          local_28 = local_28 - DAT_0019fb38;
        }
        local_2c = 0;
      }
      pcVar4 = pcVar4 + 2;
    }
  }
  local_28 = iVar1;
  AddNode__11CNodeViewerii(param_1,param_2,local_28);
  iStack_14 = 0;
  do {
    if (*(int *)(DAT_0019fb2c + 0x20 + param_2 * 0x58) <= iStack_14) {
      return;
    }
    iVar1 = DAT_0019fb30 + (iStack_14 + *(int *)(DAT_0019fb2c + 0x24 + param_2 * 0x58)) * 0x18;
    iVar3 = *(int *)(iVar1 + 4);
    local_28 = *(int *)(param_1 + 0x458) + 1;
    pcVar4 = (char *)(*(int *)(*(int *)(param_1 + 0x864) * 8 + DAT_0019fb2c + 0x28 + iVar3 * 0x58) +
                     iRam0019fb34);
    local_2c = iVar3;
    while (0 < local_28) {
      cVar2 = *pcVar4;
      if (cVar2 < '\0') {
        if (local_28 <= -cVar2) {
          FUN_000ca980();
          return;
        }
        local_28 = local_28 - -cVar2;
        pcVar4 = pcVar4 + 1;
      }
      else {
        if (cVar2 + 1 < local_28) {
          local_28 = (local_28 - cVar2) + -1;
        }
        else {
          local_2c = pcVar4[1] + iVar3;
          if (local_2c < DAT_0019fb38) {
            if (local_2c < 0) {
              local_2c = local_2c + DAT_0019fb38;
            }
          }
          else {
            local_2c = local_2c - DAT_0019fb38;
          }
          local_28 = 0;
        }
        pcVar4 = pcVar4 + 2;
      }
    }
    AddNode__11CNodeViewerii(param_1,*(undefined4 *)(iVar1 + 4),local_2c);
    iStack_14 = iStack_14 + 1;
  } while( true );
}


