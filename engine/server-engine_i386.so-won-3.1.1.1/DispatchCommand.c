// DispatchCommand__13SystemWrapperPc  @ 00099380
undefined4 DispatchCommand__13SystemWrapperPc(int param_1,char *param_2)

{
  size_t __n;
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *local_8;
  
  uVar3 = 0x9938e;
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    local_8 = (char *)GetFirst__10ObjectList(param_1 + 0x158);
    while (local_8 != (char *)0x0) {
      __n = strlen(local_8);
      pcVar2 = param_2;
      iVar1 = strncasecmp(local_8,param_2,__n);
      if (iVar1 == 0) {
        (**(code **)(**(int **)(local_8 + 0x24) + 0x18))
                  (*(undefined4 *)(local_8 + 0x24),*(undefined4 *)(local_8 + 0x20),param_2);
        return 1;
      }
      local_8 = (char *)GetNext__10ObjectList(param_1 + 0x158,pcVar2,__n,uVar3);
    }
    Cmd_ExecuteString(param_2,1);
  }
  return 1;
}


