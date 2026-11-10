// FillInNextAuthServer__11CServerList  @ 00096f7c
bool FillInNextAuthServer__11CServerList(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[0x41];
  if (uVar1 != 0) {
    strcpy((char *)(param_1 + 1),(char *)(uVar1 + 4));
    *param_1 = (uint)(ushort)((uint *)param_1[0x41])[0x11];
    param_1[0x41] = *(uint *)param_1[0x41];
  }
  return uVar1 != 0;
}


