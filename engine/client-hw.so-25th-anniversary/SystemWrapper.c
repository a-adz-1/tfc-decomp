// SystemWrapper_ExecuteString  @ 000e8d20
void SystemWrapper_ExecuteString(char *command)

{
  SystemWrapper::ExecuteString(&gSystemWrapper,command);
  return;
}


// SystemWrapper_Init  @ 000e87d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SystemWrapper_Init(void)

{
  IEngineWrapper *pIVar1;
  void **__vtt_parm;
  
  __vtt_parm = (void **)0x0;
  BaseSystemModule::Init
            (&gSystemWrapper.super_BaseSystemModule,&gSystemWrapper.super_IBaseSystem,0,
             "SystemWrapper");
  ObjectList::Init(&gSystemWrapper.m_Commands);
  ObjectList::Init(&gSystemWrapper.m_Modules);
  ObjectList::Init(&gSystemWrapper.m_Libraries);
  ObjectList::Init(&gSystemWrapper.super_BaseSystemModule.m_Listener);
  pIVar1 = operator_new(0x130);
  pIVar1[1]._vptr_IEngineWrapper = (_func_int_varargs **)&DAT_0025cbc4;
  pIVar1->_vptr_IEngineWrapper = (_func_int_varargs **)&DAT_0025cc0c;
  BaseSystemModule::BaseSystemModule((BaseSystemModule *)(pIVar1 + 1),0x25cd14,__vtt_parm);
  pIVar1->_vptr_IEngineWrapper = (_func_int_varargs **)(EngineWrapper::vtable + 0xc);
  pIVar1[1]._vptr_IEngineWrapper = (_func_int_varargs **)(EngineWrapper::vtable + 0xcc);
  gSystemWrapper.m_EngineWrapper = pIVar1;
  gSystemWrapper.super_BaseSystemModule.m_State = 3;
  return;
}


// SystemWrapper_LoadModule  @ 000e9a40
int SystemWrapper_LoadModule(char *interfacename,char *library,char *instancename)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  library_t *plVar5;
  
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
  if (((interfacename != (char *)0x0) && (*interfacename != '\0')) &&
     (piVar2 = ObjectList::GetFirst(&gSystemWrapper.m_Modules), piVar2 != (int *)0x0)) {
    if (instancename == (char *)0x0) {
      do {
        pcVar3 = (char *)(**(code **)(*piVar2 + 0x2c))(piVar2);
        iVar4 = strcasecmp(interfacename,pcVar3);
        if (iVar4 == 0) {
          return 1;
        }
        piVar2 = ObjectList::GetNext(&gSystemWrapper.m_Modules);
      } while (piVar2 != (int *)0x0);
    }
    else {
      do {
        pcVar3 = (char *)(**(code **)(*piVar2 + 0x2c))(piVar2);
        iVar4 = strcasecmp(interfacename,pcVar3);
        if (iVar4 == 0) {
          pcVar3 = (char *)(**(code **)(*piVar2 + 0x30))(piVar2);
          iVar4 = strcasecmp(instancename,pcVar3);
          if (iVar4 == 0) {
            return 1;
          }
        }
        piVar2 = ObjectList::GetNext(&gSystemWrapper.m_Modules);
      } while (piVar2 != (int *)0x0);
    }
  }
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
  plVar5 = SystemWrapper::GetLibrary(&gSystemWrapper,library);
  if (plVar5 != (library_t *)0x0) {
    piVar2 = (*plVar5->createInterfaceFn)(interfacename,(int *)0x0);
    if (piVar2 != (int *)0x0) {
      cVar1 = (**(code **)(*piVar2 + 8))
                        (piVar2,&gSystemWrapper,gSystemWrapper.m_SerialCounter,instancename);
      if (cVar1 == '\0') {
        SystemWrapper::Printf
                  (&gSystemWrapper,"ERROR! System::AddModule: couldn\'t initialize module %s.\n",
                   instancename);
      }
      else {
        ObjectList::AddHead(&gSystemWrapper.m_Modules,piVar2);
        gSystemWrapper.m_SerialCounter = gSystemWrapper.m_SerialCounter + 1;
      }
      return 1;
    }
    SystemWrapper::Printf
              (&gSystemWrapper,
               "ERROR! System::GetModule: interface \"%s\" not found in library %s.\n",interfacename
               ,plVar5);
  }
  return 0;
}


// SystemWrapper_RunFrame  @ 000e8d40
void SystemWrapper_RunFrame(double time)

{
  int *piVar1;
  
                    /* Unresolved local var: ISystemModule * module@[???] */
  gSystemWrapper.super_BaseSystemModule.m_SystemTime =
       gSystemWrapper.super_BaseSystemModule.m_SystemTime + time;
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


// SystemWrapper_ShutDown  @ 000e89b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SystemWrapper_ShutDown(void)

{
  SystemWrapper::ShutDown(&gSystemWrapper);
  return;
}


