// Ghidra decompilation of functions from public/interface.cpp
// 10 functions, ordered by original source line

// GetModuleHandle  @ 00177780  (line 11)

void * GetModuleHandle(char *name)

{
  void *pvVar1;
  
                    /* Unresolved local var: void * handle@[???] */
  pvVar1 = (void *)0x0;
  if (name != (char *)0x0) {
    pvVar1 = (void *)dlopen(name,2);
    if (pvVar1 != (void *)0x0) {
      dlclose(pvVar1);
    }
  }
  return pvVar1;
}


// InterfaceReg::InterfaceReg  @ 001777c0  (line 43)

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


// CreateInterface  @ 001777e0  (line 57)

IBaseInterface * CreateInterface(char *pName,int *pReturnCode)

{
  InterfaceReg *pIVar1;
  int iVar2;
  IBaseInterface *pIVar3;
  
  pIVar1 = InterfaceReg::s_pInterfaceRegs;
  while( true ) {
    if (pIVar1 == (InterfaceReg *)0x0) {
      if (pReturnCode != (int *)0x0) {
        *pReturnCode = 1;
      }
      return (IBaseInterface *)0x0;
    }
    iVar2 = strcmp(pIVar1->m_pName,pName);
    if (iVar2 == 0) break;
    pIVar1 = pIVar1->m_pNext;
  }
  if (pReturnCode != (int *)0x0) {
    *pReturnCode = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0017782c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar3 = (*pIVar1->m_CreateFn)();
  return pIVar3;
}


// CreateInterfaceLocal  @ 00177710  (line 81)

IBaseInterface * CreateInterfaceLocal(char *pName,int *pReturnCode)

{
  InterfaceReg *pIVar1;
  int iVar2;
  IBaseInterface *pIVar3;
  
  pIVar1 = InterfaceReg::s_pInterfaceRegs;
  while( true ) {
    if (pIVar1 == (InterfaceReg *)0x0) {
      if (pReturnCode != (int *)0x0) {
        *pReturnCode = 1;
      }
      return (IBaseInterface *)0x0;
    }
    iVar2 = strcmp(pIVar1->m_pName,pName);
    if (iVar2 == 0) break;
    pIVar1 = pIVar1->m_pNext;
  }
  if (pReturnCode != (int *)0x0) {
    *pReturnCode = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0017775c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar3 = (*pIVar1->m_CreateFn)();
  return pIVar3;
}


// Sys_GetProcAddress  @ 00177850  (line 131)

void * Sys_GetProcAddress(void *pModuleHandle,char *pName)

{
  void *pvVar1;
  
  pvVar1 = (void *)dlsym();
  return pvVar1;
}


// Sys_LoadModule  @ 00177860  (line 141)

CSysModule * Sys_LoadModule(char *pModuleName)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  CSysModule *pCVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint *puVar7;
  char local_c0c [1020];
  char acStack_810 [4];
  uint local_80c [256];
  char local_40c [1028];
  
                    /* Unresolved local var: void * hDLL@[???]
                       Unresolved local var: char[1024] szAbsoluteModuleName@[???] */
  local_c0c[0] = '\0';
  if (*pModuleName == '/') {
    snprintf(local_c0c,0x400,"%s",pModuleName);
    pCVar4 = (CSysModule *)dlopen(pModuleName,2);
  }
  else {
                    /* Unresolved local var: char[1024] szCwd@[???]
                       Unresolved local var: char[1024] szAbsoluteModuleName@[???] */
    getcwd((char *)local_80c,0x400);
    puVar7 = local_80c;
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
    iVar1 = -(int)local_80c - (uint)CARRY1((byte)uVar3,(byte)uVar3);
    if (*(char *)((int)puVar7 + (int)(acStack_810 + iVar1)) == '/') {
      *(char *)((int)puVar7 + (int)(acStack_810 + iVar1)) = '\0';
    }
    snprintf(local_40c,0x400,"%s/%s",local_80c,pModuleName);
    pCVar4 = (CSysModule *)dlopen(local_40c,2);
  }
  if (pCVar4 != (CSysModule *)0x0) {
    return pCVar4;
  }
                    /* Unresolved local var: char[512] str@[???] */
  uVar5 = dlerror();
  printf("Error:%s\n",uVar5);
  snprintf(local_40c,0x200,"%s.so",local_c0c);
  pCVar4 = (CSysModule *)dlopen(local_40c,2);
  return pCVar4;
}


// Sys_UnloadModule  @ 001779c0  (line 194)

void Sys_UnloadModule(CSysModule *pModule)

{
                    /* Unresolved local var: void * hDLL@[???] */
  if (pModule != (CSysModule *)0x0) {
    dlclose();
    return;
  }
  return;
}


// Sys_GetFactory  @ 001779e0  (line 214)

CreateInterfaceFn Sys_GetFactory(CSysModule *pModule)

{
  CreateInterfaceFn p_Var1;
  
                    /* Unresolved local var: void * hDLL@[???] */
  p_Var1 = (CreateInterfaceFn)0x0;
  if (pModule != (CSysModule *)0x0) {
    p_Var1 = (CreateInterfaceFn)dlsym(pModule,"CreateInterface");
  }
  return p_Var1;
}


// Sys_GetFactoryThis  @ 00177a10  (line 246)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CreateInterfaceFn Sys_GetFactoryThis(void)

{
  return CreateInterfaceLocal;
}


// Sys_GetFactory  @ 00177a20  (line 254)

CreateInterfaceFn Sys_GetFactory(char *pModuleName)

{
  CreateInterfaceFn p_Var1;
  int iVar2;
  
                    /* Unresolved local var: void * handle@[???] */
  iVar2 = 0;
  if (pModuleName != (char *)0x0) {
    iVar2 = dlopen(pModuleName,2);
    if (iVar2 != 0) {
      dlclose(iVar2);
    }
  }
  p_Var1 = (CreateInterfaceFn)dlsym(iVar2,"CreateInterface");
  return p_Var1;
}


