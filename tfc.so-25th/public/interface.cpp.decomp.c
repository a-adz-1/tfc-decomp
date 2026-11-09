// Ghidra decompilation of functions from public/interface.cpp
// 9 functions, ordered by original source line

// GetModuleHandle  @ 00146d70  (line 11)

void * GetModuleHandle(char *name)

{
  void *pvVar1;
  
                    /* Unresolved local var: void * handle@[???] */
  if ((name != (char *)0x0) && (pvVar1 = (void *)dlopen(name,2), pvVar1 != (void *)0x0)) {
    dlclose(pvVar1);
    return pvVar1;
  }
  return (void *)0x0;
}


// InterfaceReg::InterfaceReg  @ 00146db0  (line 43)

/* DWARF original prototype: void InterfaceReg(InterfaceReg * this, InstantiateInterfaceFn fn, char
   * pName) */

void __thiscall InterfaceReg::InterfaceReg(InterfaceReg *this,InstantiateInterfaceFn fn,char *pName)

{
  InterfaceReg *pIVar1;
  
  this->m_pName = pName;
  this->m_CreateFn = fn;
  pIVar1 = s_pInterfaceRegs;
  s_pInterfaceRegs = this;
  this->m_pNext = pIVar1;
  return;
}


// CreateInterface  @ 00146d00  (line 57)

void * CreateInterface(char *pName,int *pReturnCode)

{
  InterfaceReg *pIVar1;
  int iVar2;
  void *pvVar3;
  
  pIVar1 = InterfaceReg::s_pInterfaceRegs;
  while( true ) {
    if (pIVar1 == (InterfaceReg *)0x0) {
      if (pReturnCode != (int *)0x0) {
        *pReturnCode = 1;
      }
      return (void *)0x0;
    }
    iVar2 = strcmp(pIVar1->m_pName,pName);
    if (iVar2 == 0) break;
    pIVar1 = pIVar1->m_pNext;
  }
  if (pReturnCode != (int *)0x0) {
    *pReturnCode = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00146d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar3 = (*pIVar1->m_CreateFn)();
  return pvVar3;
}


// Sys_GetProcAddress  @ 00146dd0  (line 134)

void * Sys_GetProcAddress(void *pModuleHandle,char *pName)

{
  void *pvVar1;
  
  pvVar1 = (void *)dlsym();
  return pvVar1;
}


// Sys_LoadModule  @ 00146de0  (line 144)

CSysModule * Sys_LoadModule(char *pModuleName)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  CSysModule *pCVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint *puVar7;
  int in_GS_OFFSET;
  char local_c10 [1020];
  char acStack_814 [4];
  uint local_810 [256];
  undefined1 local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: void * hDLL@[???]
                       Unresolved local var: char[1024] szAbsoluteModuleName@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_c10[0] = '\0';
  if (*pModuleName == '/') {
    snprintf(local_c10,0x400,"%s",pModuleName);
    pCVar4 = (CSysModule *)dlopen(pModuleName,2);
  }
  else {
                    /* Unresolved local var: char[1024] szCwd@[???]
                       Unresolved local var: char[1024] szAbsoluteModuleName@[???] */
    getcwd((char *)local_810,0x400);
    puVar7 = local_810;
    do {
      puVar6 = puVar7;
      uVar2 = *puVar6 + 0xfefefeff & ~*puVar6;
      uVar3 = uVar2 & 0x80808080;
      puVar7 = puVar6 + 1;
    } while (uVar3 == 0);
    if ((uVar2 & 0x8080) == 0) {
      puVar7 = (uint *)((int)puVar6 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    iVar1 = -(int)local_810 - (uint)CARRY1((byte)uVar3,(byte)uVar3);
    if (*(char *)((int)puVar7 + (int)(acStack_814 + iVar1)) == '/') {
      *(char *)((int)puVar7 + (int)(acStack_814 + iVar1)) = '\0';
    }
    __snprintf_chk(local_410,0x400,1,0x400,"%s/%s",local_810,pModuleName);
    pCVar4 = (CSysModule *)dlopen(local_410,2);
  }
  if (pCVar4 == (CSysModule *)0x0) {
                    /* Unresolved local var: char[512] str@[???] */
    uVar5 = dlerror();
    __printf_chk(1,"Error:%s\n",uVar5);
    __snprintf_chk(local_410,0x200,1,0x200,"%s.so",local_c10);
    pCVar4 = (CSysModule *)dlopen(local_410,2);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pCVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// Sys_UnloadModule  @ 00146f90  (line 197)

void Sys_UnloadModule(CSysModule *pModule)

{
                    /* Unresolved local var: void * hDLL@[???] */
  if (pModule != (CSysModule *)0x0) {
    dlclose();
    return;
  }
  return;
}


// Sys_GetFactory  @ 00146fb0  (line 217)

CreateInterfaceFn Sys_GetFactory(CSysModule *pModule)

{
  CreateInterfaceFn p_Var1;
  
                    /* Unresolved local var: void * hDLL@[???] */
  if (pModule == (CSysModule *)0x0) {
    p_Var1 = (CreateInterfaceFn)0x0;
  }
  else {
    p_Var1 = (CreateInterfaceFn)dlsym(pModule,"CreateInterface");
  }
  return p_Var1;
}


// Sys_GetFactoryThis  @ 00146fe0  (line 252)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CreateInterfaceFn Sys_GetFactoryThis(void)

{
  return CreateInterface;
}


// Sys_GetFactory  @ 00146ff0  (line 260)

CreateInterfaceFn Sys_GetFactory(char *pModuleName)

{
  int iVar1;
  CreateInterfaceFn p_Var2;
  
                    /* Unresolved local var: void * handle@[???] */
  if (pModuleName != (char *)0x0) {
    iVar1 = dlopen(pModuleName,2);
    if (iVar1 != 0) {
      dlclose(iVar1);
      goto LAB_0014701b;
    }
  }
  iVar1 = 0;
LAB_0014701b:
  p_Var2 = (CreateInterfaceFn)dlsym(iVar1,"CreateInterface");
  return p_Var2;
}


