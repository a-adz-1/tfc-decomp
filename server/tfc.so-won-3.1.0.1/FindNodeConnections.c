// FindNodeConnections__11CNodeVieweri  @ 000c0568
void FindNodeConnections__11CNodeVieweri(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = NextNodeInRoute__6CGraphiiii
                    (&WorldGraph,param_2,*(undefined4 *)(param_1 + 0x3d8),
                     *(undefined4 *)(param_1 + 0x7e4),0);
  AddNode__11CNodeViewerii(param_1,param_2,uVar2);
  iVar3 = 0;
  if (0 < *(int *)(DAT_001a82ac + 0x20 + param_2 * 0x58)) {
    do {
      iVar1 = DAT_001a82b0 + (iVar3 + *(int *)(param_2 * 0x58 + DAT_001a82ac + 0x24)) * 0x18;
      uVar2 = NextNodeInRoute__6CGraphiiii
                        (&WorldGraph,*(undefined4 *)(iVar1 + 4),*(undefined4 *)(param_1 + 0x3d8),
                         *(undefined4 *)(param_1 + 0x7e4),0);
      AddNode__11CNodeViewerii(param_1,*(undefined4 *)(iVar1 + 4),uVar2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(DAT_001a82ac + 0x20 + param_2 * 0x58));
  }
  return;
}


