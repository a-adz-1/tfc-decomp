// FindModule__13SystemWrapperPcT1  @ 00098dbc
int * FindModule__13SystemWrapperPcT1(int param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  int iVar2;
  int *local_8;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    local_8 = (int *)GetFirst__10ObjectList(param_1 + 0x130);
    while (local_8 != (int *)0x0) {
      pcVar1 = (char *)(**(code **)(*local_8 + 0x30))(local_8);
      iVar2 = strcasecmp(param_2,pcVar1);
      if (iVar2 == 0) {
        if (param_3 == (char *)0x0) {
          return local_8;
        }
        pcVar1 = (char *)(**(code **)(*local_8 + 0x34))(local_8);
        iVar2 = strcasecmp(param_3,pcVar1);
        if (iVar2 == 0) {
          return local_8;
        }
      }
      local_8 = (int *)GetNext__10ObjectList(param_1 + 0x130);
    }
  }
  return (int *)0x0;
}


