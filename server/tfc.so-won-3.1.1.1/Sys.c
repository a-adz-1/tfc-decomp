// Sys_Error__FPCc  @ 000947e8
void Sys_Error__FPCc(void)

{
  return;
}


// Sys_FreeModule__FP18HInterfaceModule_t  @ 0013b410
void Sys_FreeModule__FP18HInterfaceModule_t(int param_1)

{
  if (param_1 != 0) {
    dlclose(param_1);
  }
  return;
}


// Sys_GetFactoryThis__Fv  @ 0013b3f0
code * Sys_GetFactoryThis__Fv(void)

{
  return CreateInterface;
}


// Sys_GetFactory__FP18HInterfaceModule_t  @ 0013b3bc
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


// Sys_LoadModule__FPCc  @ 0013b434
void Sys_LoadModule__FPCc(undefined4 param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  char acStack_804 [1024];
  uint local_404 [256];
  
  getcwd((char *)local_404,0x400);
  puVar2 = local_404;
  do {
    puVar3 = puVar2;
    uVar1 = *puVar3;
    if ((uVar1 & 0xff) == 0) goto LAB_0013b48c;
    if ((uVar1 & 0xff00) == 0) goto LAB_0013b48b;
    if ((uVar1 & 0xff0000) == 0) goto LAB_0013b48a;
    puVar2 = puVar3 + 1;
  } while ((uVar1 & 0xff000000) != 0);
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_0013b48a:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_0013b48b:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_0013b48c:
  puVar2 = local_404;
  if (*(char *)((int)puVar3 + -1) == '/') {
    do {
      puVar3 = puVar2;
      uVar1 = *puVar3;
      if ((char)uVar1 == '\0') goto LAB_0013b4bc;
      if ((char)(uVar1 >> 8) == '\0') goto LAB_0013b4bb;
      if ((uVar1 & 0xff0000) == 0) goto LAB_0013b4ba;
      puVar2 = puVar3 + 1;
    } while ((uVar1 & 0xff000000) != 0);
    puVar3 = (uint *)((int)puVar3 + 1);
LAB_0013b4ba:
    puVar3 = (uint *)((int)puVar3 + 1);
LAB_0013b4bb:
    puVar3 = (uint *)((int)puVar3 + 1);
LAB_0013b4bc:
    *(char *)((int)puVar3 + -1) = '\0';
  }
  sprintf(acStack_804,"%s/%s",local_404,param_1);
  dlopen(acStack_804,2);
  return;
}


