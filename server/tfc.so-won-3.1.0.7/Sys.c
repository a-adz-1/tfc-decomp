// Sys_Error__FPCc  @ 000932ec
void Sys_Error__FPCc(void)

{
  return;
}


// Sys_FreeModule__FP18HInterfaceModule_t  @ 00136944
void Sys_FreeModule__FP18HInterfaceModule_t(int param_1)

{
  if (param_1 != 0) {
    dlclose(param_1);
  }
  return;
}


// Sys_GetFactoryThis__Fv  @ 00136964
code * Sys_GetFactoryThis__Fv(void)

{
  return CreateInterface;
}


// Sys_GetFactory__FP18HInterfaceModule_t  @ 0013697c
undefined4 Sys_GetFactory__FP18HInterfaceModule_t(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = dlsym(param_1,"CreateInterface");
  }
  return uVar1;
}


// Sys_LoadModule__FPCc  @ 001368bc
void Sys_LoadModule__FPCc(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *__buf;
  char local_800 [1022];
  char acStack_402 [1026];
  
  __buf = acStack_402 + 2;
  getcwd(__buf,0x400);
  uVar2 = 0xffffffff;
  pcVar3 = __buf;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (acStack_402[~uVar2] == '/') {
    uVar2 = 0xffffffff;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *__buf;
      __buf = __buf + 1;
    } while (cVar1 != '\0');
    acStack_402[~uVar2] = '\0';
  }
  sprintf(local_800,"%s/%s",acStack_402 + 2,param_1);
  dlopen(local_800,2);
  return;
}


