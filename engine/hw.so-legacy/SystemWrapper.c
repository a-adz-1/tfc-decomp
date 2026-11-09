// SystemWrapper_ExecuteString  @ 0014c5c0
void SystemWrapper_ExecuteString(char *command)

{
  char *in_stack_00000008;
  
                    /* Unresolved local var: char[256] singleCmd@[???]
                       Unresolved local var: bool quotes@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char * c@[???] */
  if ((command != (char *)0x0) && (*command != '\0')) {
    SystemWrapper::ExecuteString((SystemWrapper *)command,in_stack_00000008);
    return;
  }
  return;
}


// SystemWrapper_Init  @ 0014b8c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SystemWrapper_Init(void)

{
  SystemWrapper::Init(&gSystemWrapper,&gSystemWrapper.super_IBaseSystem,0,"SystemWrapper");
  return;
}


// SystemWrapper_LoadModule  @ 0014c290
int SystemWrapper_LoadModule(char *interfacename,char *library,char *instancename)

{
  ISystemModule *pIVar1;
  library_t *plVar2;
  IBaseInterface *pIVar3;
  int iVar4;
  
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
  iVar4 = 1;
  pIVar1 = SystemWrapper::FindModule(&gSystemWrapper,interfacename,instancename);
  if (pIVar1 == (ISystemModule *)0x0) {
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
    iVar4 = 0;
    plVar2 = SystemWrapper::GetLibrary(&gSystemWrapper,library);
    if (plVar2 != (library_t *)0x0) {
      pIVar3 = (*plVar2->createInterfaceFn)(interfacename,(int *)0x0);
      if (pIVar3 == (IBaseInterface *)0x0) {
        (**(code **)((int)gSystemWrapper.super_IBaseSystem + 0x4c))
                  (&gSystemWrapper,
                   "ERROR! System::GetModule: interface \"%s\" not found in library %s.\n",
                   interfacename,plVar2);
      }
      else {
        iVar4 = 1;
        (**(code **)((int)gSystemWrapper.super_IBaseSystem + 0x90))
                  (&gSystemWrapper,pIVar3,instancename);
      }
    }
  }
  return iVar4;
}


// SystemWrapper_RunFrame  @ 0014b8f0
void SystemWrapper_RunFrame(double time)

{
  int *piVar1;
  
                    /* Unresolved local var: ISystemModule * module@[???] */
  gSystemWrapper.super_BaseSystemModule.m_SystemTime =
       time + gSystemWrapper.super_BaseSystemModule.m_SystemTime;
  gSystemWrapper.m_Tick = gSystemWrapper.m_Tick + 1;
  if (gSystemWrapper.super_BaseSystemModule.m_State == 3) {
                    /* Unresolved local var: ISystemModule * module@[???] */
    piVar1 = ObjectList::GetFirst(&gSystemWrapper.m_Modules);
    while ((piVar1 != (int *)0x0 && (gSystemWrapper.super_BaseSystemModule.m_State != 4))) {
      (**(code **)(*piVar1 + 0xc))(piVar1,gSystemWrapper.super_BaseSystemModule.m_SystemTime);
      piVar1 = ObjectList::GetNext(&gSystemWrapper.m_Modules);
    }
    gSystemWrapper.m_LastTime = gSystemWrapper.super_BaseSystemModule.m_SystemTime;
    return;
  }
  return;
}


// SystemWrapper_ShutDown  @ 0014b980
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SystemWrapper_ShutDown(void)

{
  SystemWrapper::ShutDown(&gSystemWrapper);
  return;
}


