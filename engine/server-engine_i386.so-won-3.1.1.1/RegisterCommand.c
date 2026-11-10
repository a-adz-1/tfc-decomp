// RegisterCommand__13SystemWrapperPcP13ISystemModulei  @ 00098a90
bool RegisterCommand__13SystemWrapperPcP13ISystemModulei
               (int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *__dest;
  char *local_8;
  
  local_8 = (char *)GetFirst__10ObjectList(param_1 + 0x56);
  while ((local_8 != (char *)0x0 && (iVar1 = strcasecmp(local_8,param_2), iVar1 != 0))) {
    local_8 = (char *)GetNext__10ObjectList(param_1 + 0x56);
  }
  if (local_8 == (char *)0x0) {
    __dest = (char *)Mem_ZeroMalloc(0x28);
    strncpy(__dest,param_2,0x20);
    __dest[0x1f] = '\0';
    *(undefined4 *)(__dest + 0x24) = param_3;
    *(undefined4 *)(__dest + 0x20) = param_4;
    Add__10ObjectListPv(param_1 + 0x56,__dest);
    Cmd_AddWrapperCommand(__dest,SystemWrapperCommandForwarder__Fv);
  }
  else {
    (**(code **)(*param_1 + 0x4c))
              (param_1,"WARNING! System::RegisterCommand: command \"%s\" already exists.\n",param_2)
    ;
  }
  return local_8 == (char *)0x0;
}


