// SystemWrapper::CMD_LoadModule  @ 0007e5b0
/* DWARF original prototype: void CMD_LoadModule(SystemWrapper * this, char * cmdLine) */

void __thiscall SystemWrapper::CMD_LoadModule(SystemWrapper *this,char *cmdLine)

{
  ObjectList *this_00;
  int iVar1;
  SystemWrapper *this_01;
  char *pcVar2;
  char *pcVar3;
  int *piVar4;
  code *pcVar5;
  int in_GS_OFFSET;
  char *__s2;
  char *in_stack_ffffedbc;
  char *in_stack_ffffedc0;
  TokenLine local_1228;
  int local_20;
  
                    /* Unresolved local var: TokenLine params@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  TokenLine::TokenLine(&local_1228,cmdLine);
  iVar1 = TokenLine::CountToken(&local_1228);
  if (iVar1 < 2) {
    __s2 = "Syntax: loadmodule <module> [<library>] [<name>]\n";
    (**(code **)((int)this->super_IBaseSystem + 0x4c))(this);
    goto LAB_0007e700;
  }
  iVar1 = TokenLine::CountToken(&local_1228);
  if (iVar1 == 2) {
    pcVar5 = *(code **)((int)this->super_IBaseSystem + 0x94);
    pcVar2 = TokenLine::GetToken(&local_1228,1);
    __s2 = (char *)0x1;
    pcVar3 = TokenLine::GetToken(&local_1228,1);
    if (pcVar5 != GetModule) {
LAB_0007e8b0:
      (*pcVar5)(this,pcVar3,pcVar2,0);
      __s2 = pcVar3;
      goto LAB_0007e700;
    }
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
    if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
      piVar4 = ObjectList::GetFirst(&this->m_Modules);
      while (piVar4 != (int *)0x0) {
        __s2 = (char *)(**(code **)(*piVar4 + 0x2c))(piVar4);
        iVar1 = strcasecmp(pcVar3,__s2);
        if (iVar1 == 0) goto LAB_0007e700;
        piVar4 = ObjectList::GetNext(&this->m_Modules);
      }
    }
  }
  else {
    iVar1 = TokenLine::CountToken(&local_1228);
    if (iVar1 != 3) {
      pcVar5 = *(code **)((int)this->super_IBaseSystem + 0x94);
      this_01 = (SystemWrapper *)TokenLine::GetToken(&local_1228,3);
      pcVar2 = TokenLine::GetToken(&local_1228,2);
      __s2 = (char *)0x1;
      pcVar3 = TokenLine::GetToken(&local_1228,1);
      if (pcVar5 == GetModule) {
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
        if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
          this_00 = &this->m_Modules;
          piVar4 = ObjectList::GetFirst(this_00);
          if (piVar4 != (int *)0x0) {
            if (this_01 == (SystemWrapper *)0x0) {
              do {
                __s2 = (char *)(**(code **)(*piVar4 + 0x2c))(piVar4);
                iVar1 = strcasecmp(pcVar3,__s2);
                if (iVar1 == 0) goto LAB_0007e700;
                piVar4 = ObjectList::GetNext(this_00);
              } while (piVar4 != (int *)0x0);
            }
            else {
              do {
                __s2 = (char *)(**(code **)(*piVar4 + 0x2c))(piVar4);
                iVar1 = strcasecmp(pcVar3,__s2);
                if (iVar1 == 0) {
                  __s2 = (char *)(**(code **)(*piVar4 + 0x30))(piVar4);
                  iVar1 = strcasecmp((char *)this_01,__s2);
                  if (iVar1 == 0) goto LAB_0007e700;
                }
                piVar4 = ObjectList::GetNext(this_00);
              } while (piVar4 != (int *)0x0);
            }
          }
        }
        GetModule(this_01,__s2,in_stack_ffffedbc,in_stack_ffffedc0);
      }
      else {
        (*pcVar5)(this,pcVar3,pcVar2,this_01);
        __s2 = pcVar3;
      }
      goto LAB_0007e700;
    }
    pcVar5 = *(code **)((int)this->super_IBaseSystem + 0x94);
    pcVar2 = TokenLine::GetToken(&local_1228,2);
    __s2 = (char *)0x1;
    pcVar3 = TokenLine::GetToken(&local_1228,1);
    if (pcVar5 != GetModule) goto LAB_0007e8b0;
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
    if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
      piVar4 = ObjectList::GetFirst(&this->m_Modules);
      while (piVar4 != (int *)0x0) {
        __s2 = (char *)(**(code **)(*piVar4 + 0x2c))(piVar4);
        iVar1 = strcasecmp(pcVar3,__s2);
        if (iVar1 == 0) goto LAB_0007e700;
        piVar4 = ObjectList::GetNext(&this->m_Modules);
      }
    }
  }
  GetModule((SystemWrapper *)0x0,__s2,in_stack_ffffedbc,in_stack_ffffedc0);
LAB_0007e700:
  TokenLine::~TokenLine(&local_1228,(int)__s2);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SystemWrapper::CMD_Modules  @ 0007eb80
/* DWARF original prototype: void CMD_Modules(SystemWrapper * this, char * cmdLine) */

void __thiscall SystemWrapper::CMD_Modules(SystemWrapper *this,char *cmdLine)

{
  ObjectList *this_00;
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
                    /* Unresolved local var: ISystemModule * module@[???] */
  this_00 = &this->m_Modules;
  piVar2 = ObjectList::GetFirst(this_00);
  while (piVar2 != (int *)0x0) {
                    /* Unresolved local var: char * status@[???]
                       Unresolved local var: char * type@[???]
                       Unresolved local var: char * name@[???] */
    uVar3 = (**(code **)(*piVar2 + 0x28))(piVar2);
    uVar4 = (**(code **)(*piVar2 + 0x2c))(piVar2);
    uVar5 = (**(code **)(*piVar2 + 0x30))(piVar2);
    (**(code **)((int)this->super_IBaseSystem + 0x4c))(this,"%s(%s):%s",uVar5,uVar4,uVar3);
    piVar2 = ObjectList::GetNext(this_00);
  }
  pcVar1 = *(code **)((int)this->super_IBaseSystem + 0x4c);
  iVar6 = ObjectList::CountElements(this_00);
  (*pcVar1)(this,"--- %i modules in total ---\n",iVar6);
  return;
}


// SystemWrapper::CMD_UnloadModule  @ 0007dfa0
/* DWARF original prototype: void CMD_UnloadModule(SystemWrapper * this, char * cmdLine) */

void __thiscall SystemWrapper::CMD_UnloadModule(SystemWrapper *this,char *cmdLine)

{
  ObjectList *this_00;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  char *__in_chrg;
  TokenLine local_1228;
  int local_20;
  
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: TokenLine params@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  TokenLine::TokenLine(&local_1228,cmdLine);
  iVar1 = TokenLine::CountToken(&local_1228);
  if (iVar1 < 2) {
    __in_chrg = "Syntax: unloadmodule <module> [<name>]\n";
    (**(code **)((int)this->super_IBaseSystem + 0x4c))(this);
  }
  else {
    iVar1 = TokenLine::CountToken(&local_1228);
    if (iVar1 == 2) {
      pcVar2 = TokenLine::GetToken(&local_1228,1);
                    /* Unresolved local var: ISystemModule * module@[???] */
      if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
        __in_chrg = ObjectList::GetFirst(&this->m_Modules);
        while ((int *)__in_chrg != (int *)0x0) {
          pcVar3 = (char *)(**(code **)(*(int *)__in_chrg + 0x2c))(__in_chrg);
          iVar1 = strcasecmp(pcVar2,pcVar3);
          if (iVar1 == 0) goto LAB_0007e0e4;
          __in_chrg = ObjectList::GetNext(&this->m_Modules);
        }
      }
    }
    else {
      iVar1 = TokenLine::CountToken(&local_1228);
      if (iVar1 == 3) {
        pcVar2 = TokenLine::GetToken(&local_1228,2);
        pcVar3 = TokenLine::GetToken(&local_1228,1);
                    /* Unresolved local var: ISystemModule * module@[???] */
        if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
          this_00 = &this->m_Modules;
          __in_chrg = ObjectList::GetFirst(this_00);
          if ((int *)__in_chrg != (int *)0x0) {
            if (pcVar2 == (char *)0x0) {
              do {
                pcVar2 = (char *)(**(code **)(*(int *)__in_chrg + 0x2c))(__in_chrg);
                iVar1 = strcasecmp(pcVar3,pcVar2);
                if (iVar1 == 0) goto LAB_0007e0e4;
                __in_chrg = ObjectList::GetNext(this_00);
              } while ((int *)__in_chrg != (int *)0x0);
            }
            else {
              do {
                pcVar4 = (char *)(**(code **)(*(int *)__in_chrg + 0x2c))(__in_chrg);
                iVar1 = strcasecmp(pcVar3,pcVar4);
                if (iVar1 == 0) {
                  pcVar4 = (char *)(**(code **)(*(int *)__in_chrg + 0x30))(__in_chrg);
                  iVar1 = strcasecmp(pcVar2,pcVar4);
                  if (iVar1 == 0) goto LAB_0007e0e4;
                }
                __in_chrg = ObjectList::GetNext(this_00);
              } while ((int *)__in_chrg != (int *)0x0);
            }
          }
        }
      }
    }
    __in_chrg = "Module not found.\n";
    (**(code **)((int)this->super_IBaseSystem + 0x4c))(this);
  }
LAB_0007e02d:
  TokenLine::~TokenLine(&local_1228,(int)__in_chrg);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_0007e0e4:
  (**(code **)((int)this->super_IBaseSystem + 0x98))(this);
  goto LAB_0007e02d;
}


