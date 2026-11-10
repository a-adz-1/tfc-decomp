// FillInNextAuthServer__11CServerList  @ 000cf3c0
bool FillInNextAuthServer__11CServerList(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[0x41];
  if (uVar1 != 0) {
    strcpy((char *)(param_1 + 1),(char *)(param_1[0x41] + 4));
    *param_1 = (uint)*(ushort *)(param_1[0x41] + 0x44);
    param_1[0x41] = *(uint *)param_1[0x41];
  }
  return uVar1 != 0;
}


