// SystemWrapper::CMD_LoadModule  @ 0014bbb0
/* DWARF original prototype: void CMD_LoadModule(SystemWrapper * this, char * cmdLine) */

void __thiscall SystemWrapper::CMD_LoadModule(SystemWrapper *this,char *cmdLine)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  code *pcVar5;
  TokenLine local_1224;
  
                    /* Unresolved local var: TokenLine params@[???] */
  TokenLine::TokenLine(&local_1224,cmdLine);
  iVar1 = TokenLine::CountToken(&local_1224);
  if (iVar1 < 2) {
    pcVar4 = "Syntax: loadmodule <module> [<library>] [<name>]\n";
    (**(code **)((int)this->super_IBaseSystem + 0x4c))(this);
    TokenLine::~TokenLine(&local_1224,(int)pcVar4);
    return;
  }
  iVar1 = TokenLine::CountToken(&local_1224);
  if (iVar1 == 2) {
    pcVar5 = *(code **)((int)this->super_IBaseSystem + 0x94);
    iVar1 = 1;
  }
  else {
    iVar1 = TokenLine::CountToken(&local_1224);
    pcVar5 = *(code **)((int)this->super_IBaseSystem + 0x94);
    if (iVar1 != 3) {
      pcVar2 = TokenLine::GetToken(&local_1224,3);
      pcVar3 = TokenLine::GetToken(&local_1224,2);
      pcVar4 = TokenLine::GetToken(&local_1224,1);
      (*pcVar5)(this,pcVar4,pcVar3,pcVar2);
      goto LAB_0014bc77;
    }
    iVar1 = 2;
  }
  pcVar2 = TokenLine::GetToken(&local_1224,iVar1);
  pcVar4 = TokenLine::GetToken(&local_1224,1);
  (*pcVar5)(this,pcVar4,pcVar2,0);
LAB_0014bc77:
  TokenLine::~TokenLine(&local_1224,(int)pcVar4);
  return;
}


// SystemWrapper::CMD_Modules  @ 0014beb0
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


// SystemWrapper::CMD_UnloadModule  @ 0014c0d0
/* DWARF original prototype: void CMD_UnloadModule(SystemWrapper * this, char * cmdLine) */

void __thiscall SystemWrapper::CMD_UnloadModule(SystemWrapper *this,char *cmdLine)

{
  int iVar1;
  char *type;
  ISystemModule *__in_chrg;
  char *pcVar2;
  TokenLine local_1214;
  
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: TokenLine params@[???] */
  TokenLine::TokenLine(&local_1214,cmdLine);
  iVar1 = TokenLine::CountToken(&local_1214);
  if (iVar1 < 2) {
    pcVar2 = "Syntax: unloadmodule <module> [<name>]\n";
    (**(code **)((int)this->super_IBaseSystem + 0x4c))(this);
    goto LAB_0014c159;
  }
  iVar1 = TokenLine::CountToken(&local_1214);
  if (iVar1 == 2) {
    pcVar2 = TokenLine::GetToken(&local_1214,1);
    __in_chrg = FindModule(this,pcVar2,(char *)0x0);
LAB_0014c1a3:
    if (__in_chrg != (ISystemModule *)0x0) {
      (**(code **)((int)this->super_IBaseSystem + 0x98))(this);
      TokenLine::~TokenLine(&local_1214,(int)__in_chrg);
      return;
    }
  }
  else {
    iVar1 = TokenLine::CountToken(&local_1214);
    if (iVar1 == 3) {
      pcVar2 = TokenLine::GetToken(&local_1214,2);
      type = TokenLine::GetToken(&local_1214,1);
      __in_chrg = FindModule(this,type,pcVar2);
      goto LAB_0014c1a3;
    }
  }
  pcVar2 = "Module not found.\n";
  (**(code **)((int)this->super_IBaseSystem + 0x4c))(this);
LAB_0014c159:
  TokenLine::~TokenLine(&local_1214,(int)pcVar2);
  return;
}


