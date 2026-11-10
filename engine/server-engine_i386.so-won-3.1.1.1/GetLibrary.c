// GetLibrary__13SystemWrapperPc  @ 000985cc
char * GetLibrary__13SystemWrapperPc(int *param_1,char *param_2)

{
  int iVar1;
  char *__s;
  undefined4 uVar2;
  char *local_1008;
  char local_1004 [4094];
  undefined1 local_6;
  
  strncpy(local_1004,param_2,0xffe);
  local_6 = 0;
  COM_FixSlashes(local_1004);
  local_1008 = (char *)GetFirst__10ObjectList(param_1 + 0x51);
  while( true ) {
    if (local_1008 == (char *)0x0) {
      __s = (char *)Mem_Malloc(0x1008);
      if (__s == (char *)0x0) {
        (**(code **)(*param_1 + 0x50))
                  (param_1,"ERROR! System::GetLibrary: out of memory (%s).\n",param_2);
        __s = (char *)0x0;
      }
      else {
        snprintf(__s,0xfff,"%s",local_1004);
        FS_GetLocalCopy(__s);
        uVar2 = Sys_LoadModule__FPCc(__s);
        *(undefined4 *)(__s + 0x1000) = uVar2;
        if (*(int *)(__s + 0x1000) == 0) {
          (**(code **)(*param_1 + 0x50))
                    (param_1,"ERROR! System::GetLibrary: coulnd\'t load library (%s).\n",__s);
          Mem_Free(__s);
          __s = (char *)0x0;
        }
        else {
          uVar2 = Sys_GetFactory__FP10CSysModule(*(undefined4 *)(__s + 0x1000));
          *(undefined4 *)(__s + 0x1004) = uVar2;
          if (*(int *)(__s + 0x1004) == 0) {
            (**(code **)(*param_1 + 0x50))
                      (param_1,"ERROR! System::GetLibrary: coulnd\'t get object factory(%s).\n",__s)
            ;
            Mem_Free(__s);
            __s = (char *)0x0;
          }
          else {
            Add__10ObjectListPv(param_1 + 0x51,__s);
            (**(code **)(*param_1 + 0x50))(param_1,"Loaded library %s.\n",__s);
          }
        }
      }
      return __s;
    }
    iVar1 = strcasecmp(param_2,local_1008);
    if (iVar1 == 0) break;
    local_1008 = (char *)GetNext__10ObjectList(param_1 + 0x51);
  }
  return local_1008;
}


