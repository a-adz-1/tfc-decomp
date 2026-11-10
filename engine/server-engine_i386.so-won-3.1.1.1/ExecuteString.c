// ExecuteString__13SystemWrapperPc  @ 00099208
void ExecuteString__13SystemWrapperPc(int *param_1,char *param_2)

{
  bool bVar1;
  char *local_114;
  char *local_110;
  uint local_10c;
  char local_104 [256];
  
  bVar1 = false;
  local_10c = 0;
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    COM_RemoveEvilChars__FPc(param_2);
    local_110 = param_2;
    local_114 = local_104;
    while( true ) {
      *local_114 = *local_110;
      local_10c = local_10c + 1;
      if (0xff < local_10c) break;
      if (*local_110 == '\"') {
        bVar1 = (bool)(bVar1 ^ 1);
      }
      if (((*local_110 == ';') && (!bVar1)) || (*local_110 == '\0')) {
        *local_114 = '\0';
        for (local_114 = local_104; *local_114 == ' '; local_114 = local_114 + 1) {
        }
        DispatchCommand__13SystemWrapperPc(param_1,local_114);
        local_114 = local_104;
        local_10c = 0;
      }
      else {
        local_114 = local_114 + 1;
      }
      if (*local_110 == '\0') {
        return;
      }
      local_110 = local_110 + 1;
    }
    (**(code **)(*param_1 + 0x4c))
              (param_1,"WARNING! System::ExecuteString: Command token too long.\n");
  }
  return;
}


