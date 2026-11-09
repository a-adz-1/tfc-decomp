// AlertMessage  @ 0007ad80
void AlertMessage(ALERT_TYPE atype,char *szFmt,...)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: va_list argptr@[???] */
  if (atype == at_logged) {
    if (svs.maxclients < 2) {
      if (developer.value != 0.0) goto switchD_0007adb0_default;
    }
    else {
      __vsnprintf_chk(AlertMessage::szOut,0x400,1,0x400,szFmt,&stack0x0000000c);
      Log_Printf("%s",AlertMessage::szOut);
    }
    return;
  }
  if (developer.value == 0.0) {
    return;
  }
  switch(atype) {
  case at_notice:
    Q_strcpy(AlertMessage::szOut,"NOTE:  ");
    break;
  case at_console:
    goto LAB_0007ae42;
  case at_aiconsole:
    if (developer.value < 2.0) {
      return;
    }
LAB_0007ae42:
    AlertMessage::szOut[0] = false;
    break;
  case at_warning:
    Q_strcpy(AlertMessage::szOut,"WARNING:  ");
    break;
  case at_error:
    Q_strcpy(AlertMessage::szOut,"ERROR:  ");
  }
switchD_0007adb0_default:
  iVar1 = Q_strlen(AlertMessage::szOut);
  iVar2 = Q_strlen(AlertMessage::szOut);
  __vsnprintf_chk(AlertMessage::szOut + iVar2,0x400 - iVar1,1,0xffffffff,szFmt,&stack0x0000000c);
  Con_Printf("%s",AlertMessage::szOut);
  return;
}


// AllocEngineString  @ 000757d0
int AllocEngineString(char *szValue)

{
  int size;
  char *pcVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: char * new_s@[???]
                       Unresolved local var: char * new_p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int l@[???] */
  iVar2 = Q_strlen(szValue);
  size = iVar2 + 1;
  pvVar3 = Hunk_Alloc(size);
  if (0 < size) {
    iVar5 = 0;
    iVar4 = (int)pvVar3 + 1;
    do {
      while ((pcVar1 = szValue + iVar5, *pcVar1 != '\\' || (iVar2 <= iVar5))) {
        iVar5 = iVar5 + 1;
        *(char *)(iVar4 + -1) = *pcVar1;
        iVar4 = iVar4 + 1;
        if (size <= iVar5) goto LAB_00075832;
      }
      if (szValue[iVar5 + 1] == 'n') {
        *(undefined1 *)(iVar4 + -1) = 10;
      }
      else {
        *(undefined1 *)(iVar4 + -1) = 0x5c;
      }
      iVar5 = iVar5 + 2;
      iVar4 = iVar4 + 1;
    } while (iVar5 < size);
  }
LAB_00075832:
  return (int)pvVar3 - (int)pr_strings;
}


// AngleIMatrix  @ 00060480
void AngleIMatrix(vec_t *angles,float (*matrix) [4])

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double local_2c;
  double local_24 [2];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincos((double)(angles[1] * 0.017453292),local_24,&local_2c);
  fVar1 = (float)local_24[0];
  fVar2 = (float)local_2c;
  sincos((double)(*angles * 0.017453292),local_24,&local_2c);
  fVar3 = (float)local_24[0];
  fVar4 = (float)local_2c;
  sincos((double)(angles[2] * 0.017453292),local_24,&local_2c);
  fVar5 = (float)local_24[0];
  fVar6 = (float)local_2c;
  (*matrix)[0] = fVar4 * fVar2;
  (*matrix)[1] = fVar4 * fVar1;
  (*matrix)[2] = -fVar3;
  matrix[1][0] = fVar2 * fVar3 * fVar5 - fVar1 * fVar6;
  matrix[1][1] = fVar2 * fVar6 + fVar3 * fVar5 * fVar1;
  matrix[1][2] = fVar4 * fVar5;
  matrix[2][0] = fVar1 * fVar5 + fVar2 * fVar3 * fVar6;
  matrix[2][1] = fVar3 * fVar6 * fVar1 - fVar5 * fVar2;
  matrix[2][2] = fVar6 * fVar4;
  (*matrix)[3] = 0.0;
  matrix[1][3] = 0.0;
  matrix[2][3] = 0.0;
  return;
}


// AngleMatrix  @ 00060330
void AngleMatrix(vec_t *angles,float (*matrix) [4])

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double local_2c;
  double local_24 [2];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincos((double)(angles[1] * 0.017453292),local_24,&local_2c);
  fVar1 = (float)local_24[0];
  fVar2 = (float)local_2c;
  sincos((double)(*angles * 0.017453292),local_24,&local_2c);
  fVar3 = (float)local_24[0];
  fVar4 = (float)local_2c;
  sincos((double)(angles[2] * 0.017453292),local_24,&local_2c);
  fVar5 = (float)local_24[0];
  fVar6 = (float)local_2c;
  (*matrix)[0] = fVar4 * fVar2;
  matrix[1][0] = fVar4 * fVar1;
  matrix[2][0] = -fVar3;
  (*matrix)[1] = fVar2 * fVar3 * fVar5 - fVar1 * fVar6;
  matrix[1][1] = fVar2 * fVar6 + fVar3 * fVar5 * fVar1;
  matrix[2][1] = fVar4 * fVar5;
  (*matrix)[2] = fVar1 * fVar5 + fVar2 * fVar3 * fVar6;
  matrix[1][2] = fVar3 * fVar6 * fVar1 - fVar5 * fVar2;
  matrix[2][2] = fVar6 * fVar4;
  (*matrix)[3] = 0.0;
  matrix[1][3] = 0.0;
  matrix[2][3] = 0.0;
  return;
}


// AngleQuaternion  @ 00075d10
void AngleQuaternion(vec_t *angles,vec_t *quaternion)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double local_2c;
  double local_24 [2];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincos((double)(angles[2] * 0.5),local_24,&local_2c);
  fVar1 = (float)local_24[0];
  fVar2 = (float)local_2c;
  sincos((double)(angles[1] * 0.5),local_24,&local_2c);
  fVar3 = (float)local_24[0];
  fVar4 = (float)local_2c;
  sincos((double)(*angles * 0.5),local_24,&local_2c);
  fVar5 = fVar4 * (float)local_24[0];
  fVar6 = fVar3 * (float)local_2c;
  *quaternion = fVar2 * fVar5 - fVar1 * fVar6;
  quaternion[1] = fVar5 * fVar1 + fVar6 * fVar2;
  fVar4 = (float)local_2c * fVar4;
  fVar3 = (float)local_24[0] * fVar3;
  quaternion[2] = fVar1 * fVar4 - fVar2 * fVar3;
  quaternion[3] = fVar3 * fVar1 + fVar4 * fVar2;
  return;
}


// AngleVectors  @ 00060020
void AngleVectors(vec_t *angles,vec_t *forward,vec_t *right,vec_t *up)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  vec_t *pvVar8;
  double local_1c;
  double local_14;
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  (*g_engdstAddrs.pfnAngleVectors)(&angles,&forward,&right,&up);
  pvVar8 = angles;
  sincos((double)(angles[1] * 0.017453292),&local_14,&local_1c);
  fVar1 = (float)local_14;
  fVar2 = (float)local_1c;
  sincos((double)(*pvVar8 * 0.017453292),&local_14,&local_1c);
  fVar3 = (float)local_14;
  fVar4 = (float)local_1c;
  sincos((double)(pvVar8[2] * 0.017453292),&local_14,&local_1c);
  fVar5 = (float)local_14;
  fVar7 = (float)local_1c;
  if (forward != (vec_t *)0x0) {
    *forward = fVar2 * fVar4;
    forward[1] = fVar1 * fVar4;
    forward[2] = -fVar3;
  }
  if (right != (vec_t *)0x0) {
    fVar6 = fVar3 * -fVar5;
    *right = fVar1 * fVar7 + fVar2 * fVar6;
    right[1] = fVar1 * fVar6 - fVar2 * fVar7;
    right[2] = -fVar5 * fVar4;
  }
  if (up != (vec_t *)0x0) {
    *up = fVar1 * fVar5 + fVar2 * fVar3 * fVar7;
    up[1] = fVar3 * fVar7 * fVar1 - fVar5 * fVar2;
    up[2] = fVar7 * fVar4;
  }
  return;
}


// AngleVectorsTranspose  @ 000601b0
void AngleVectorsTranspose(vec_t *angles,vec_t *forward,vec_t *right,vec_t *up)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double local_2c;
  double local_24 [2];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincos((double)(angles[1] * 0.017453292),local_24,&local_2c);
  fVar1 = (float)local_24[0];
  fVar2 = (float)local_2c;
  sincos((double)(*angles * 0.017453292),local_24,&local_2c);
  fVar3 = (float)local_24[0];
  fVar4 = (float)local_2c;
  sincos((double)(angles[2] * 0.017453292),local_24,&local_2c);
  fVar5 = (float)local_24[0];
  fVar6 = (float)local_2c;
  if (forward != (vec_t *)0x0) {
    *forward = fVar4 * fVar2;
    forward[1] = fVar3 * fVar5 * fVar2 - fVar1 * fVar6;
    forward[2] = fVar1 * fVar5 + fVar3 * fVar6 * fVar2;
  }
  if (right != (vec_t *)0x0) {
    *right = fVar4 * fVar1;
    right[1] = fVar2 * fVar6 + fVar3 * fVar5 * fVar1;
    right[2] = fVar3 * fVar6 * fVar1 - fVar2 * fVar5;
  }
  if (up != (vec_t *)0x0) {
    *up = -fVar3;
    up[1] = fVar5 * fVar4;
    up[2] = fVar6 * fVar4;
  }
  return;
}


// AnimationAutomove  @ 00078570
void AnimationAutomove(edict_t *pEdict,float flTime)

{
  return;
}


// BEnableAddonsFolder  @ 0004b190
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool BEnableAddonsFolder(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = COM_CheckParm("-addons");
  bVar2 = true;
  if (iVar1 == 0) {
    iVar1 = (*registry->_vptr_IRegistry[2])(registry,"addons_folder",0);
    bVar2 = 0 < iVar1;
  }
  return bVar2;
}


// BEnabledHDAddon  @ 0004b150
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool BEnabledHDAddon(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = COM_CheckParm("-nohdmodels");
  bVar2 = false;
  if (iVar1 == 0) {
    iVar1 = (*registry->_vptr_IRegistry[2])(registry,"hdmodels",0);
    bVar2 = 0 < iVar1;
  }
  return bVar2;
}


// BIsValveGame  @ 000957d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean BIsValveGame(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = strcasecmp(g_GameToAppIDMap[0].pGameDir,com_gamedir);
  if (iVar1 != 0) {
    iVar1 = strcasecmp(g_GameToAppIDMap[1].pGameDir,com_gamedir);
    if (iVar1 != 0) {
      iVar1 = strcasecmp(g_GameToAppIDMap[2].pGameDir,com_gamedir);
      if (iVar1 != 0) {
        iVar1 = strcasecmp(g_GameToAppIDMap[3].pGameDir,com_gamedir);
        if (iVar1 != 0) {
          iVar1 = strcasecmp(g_GameToAppIDMap[4].pGameDir,com_gamedir);
          if (iVar1 != 0) {
            iVar1 = strcasecmp(g_GameToAppIDMap[5].pGameDir,com_gamedir);
            if (iVar1 != 0) {
              iVar1 = strcasecmp(g_GameToAppIDMap[6].pGameDir,com_gamedir);
              if (iVar1 != 0) {
                iVar1 = strcasecmp(g_GameToAppIDMap[7].pGameDir,com_gamedir);
                if (iVar1 != 0) {
                  iVar1 = strcasecmp(g_GameToAppIDMap[8].pGameDir,com_gamedir);
                  if (iVar1 != 0) {
                    iVar1 = strcasecmp(g_GameToAppIDMap[9].pGameDir,com_gamedir);
                    if (iVar1 != 0) {
                      iVar1 = strcasecmp(g_GameToAppIDMap[10].pGameDir,com_gamedir);
                      return (uint)(iVar1 == 0);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return true;
}


// BaseSystemModule::BaseSystemModule  @ 000c35d0
/* DWARF original prototype: void BaseSystemModule(BaseSystemModule * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall
BaseSystemModule::BaseSystemModule(BaseSystemModule *this,int __in_chrg,void **__vtt_parm)

{
  int iVar1;
  
  iVar1 = *(int *)__in_chrg;
  *(int *)this = iVar1;
  *(undefined4 *)(this->m_Name + *(int *)(iVar1 + -0x48) + -0x1c) = *(undefined4 *)(__in_chrg + 4);
  ObjectList::ObjectList(&this->m_Listener);
  this->m_State = 0;
  return;
}


// BaseSystemModule::BaseSystemModule  @ 000c3610
/* DWARF original prototype: void BaseSystemModule(BaseSystemModule * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall
BaseSystemModule::BaseSystemModule(BaseSystemModule *this,int __in_chrg,void **__vtt_parm)

{
  *(undefined ***)this = &PTR__BaseSystemModule_000dea70;
  ObjectList::ObjectList(&this->m_Listener);
  this->m_State = 0;
  return;
}


// BaseSystemModule::ExecuteCommand  @ 000c3470
/* DWARF original prototype: void ExecuteCommand(BaseSystemModule * this, int commandID, char *
   commandLine) */

void __thiscall
BaseSystemModule::ExecuteCommand(BaseSystemModule *this,int commandID,char *commandLine)

{
                    /* WARNING: Could not recover jumptable at 0x000c3486. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)*this->m_System + 0x50))();
  return;
}


// BaseSystemModule::ExecuteCommand  @ 000c3490
/* virtual thunk to BaseSystemModule::ExecuteCommand(int, char*) */

void __thiscall BaseSystemModule::ExecuteCommand(BaseSystemModule *this,int param_1,char *param_2)

{
  ExecuteCommand((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x1c) + -0x1c),param_1
                 ,param_2);
  return;
}


// BaseSystemModule::FireSignal  @ 000c3830
/* DWARF original prototype: void FireSignal(BaseSystemModule * this, uint signal, void * data) */

void __thiscall BaseSystemModule::FireSignal(BaseSystemModule *this,uint signal,void *data)

{
  ObjectList *this_00;
  code *pcVar1;
  int *piVar2;
  char *pcVar3;
  int *piVar4;
  
                    /* Unresolved local var: ISystemModule * listener@[???] */
  this_00 = &this->m_Listener;
  piVar2 = ObjectList::GetFirst(this_00);
  do {
    if (piVar2 == (int *)0x0) {
      return;
    }
    while( true ) {
      pcVar3 = this->m_Name + *(int *)(*(int *)this + -0x48) + -0x1c;
      if (*(code **)(*piVar2 + 0x10) == ReceiveSignal) break;
      (**(code **)(*piVar2 + 0x10))(piVar2,pcVar3,signal,data);
      piVar2 = ObjectList::GetNext(this_00);
      if (piVar2 == (int *)0x0) {
        return;
      }
    }
    piVar4 = (int *)piVar2[1];
    pcVar1 = *(code **)(*piVar4 + 0x50);
    if (*(code **)(*(int *)pcVar3 + 0x30) == GetName) {
      pcVar3 = pcVar3 + 0x1c;
    }
    else {
      pcVar3 = (char *)(**(code **)(*(int *)pcVar3 + 0x30))(pcVar3);
      piVar4 = (int *)piVar2[1];
    }
    (*pcVar1)(piVar4,"WARNING! Unhandled signal (%i) from module %s.\n",signal,pcVar3);
    piVar2 = ObjectList::GetNext(this_00);
  } while( true );
}


// BaseSystemModule::GetName  @ 000c3410
/* DWARF original prototype: char * GetName(BaseSystemModule * this) */

char * __thiscall BaseSystemModule::GetName(BaseSystemModule *this)

{
  return this->m_Name;
}


// BaseSystemModule::GetName  @ 000c3420
/* virtual thunk to BaseSystemModule::GetName() */

void __thiscall BaseSystemModule::GetName(BaseSystemModule *this)

{
  GetName((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x38) + -0x1c));
  return;
}


// BaseSystemModule::GetSerial  @ 000c34a0
/* DWARF original prototype: int GetSerial(BaseSystemModule * this) */

int __thiscall BaseSystemModule::GetSerial(BaseSystemModule *this)

{
  return this->m_Serial;
}


// BaseSystemModule::GetSerial  @ 000c34b0
/* virtual thunk to BaseSystemModule::GetSerial() */

void __thiscall BaseSystemModule::GetSerial(BaseSystemModule *this)

{
  GetSerial((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x2c) + -0x1c));
  return;
}


// BaseSystemModule::GetState  @ 000c3510
/* DWARF original prototype: int GetState(BaseSystemModule * this) */

int __thiscall BaseSystemModule::GetState(BaseSystemModule *this)

{
  return this->m_State;
}


// BaseSystemModule::GetState  @ 000c3520
/* virtual thunk to BaseSystemModule::GetState() */

void __thiscall BaseSystemModule::GetState(BaseSystemModule *this)

{
  GetState((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x3c) + -0x1c));
  return;
}


// BaseSystemModule::GetStatusLine  @ 000c3450
/* DWARF original prototype: char * GetStatusLine(BaseSystemModule * this) */

char * __thiscall BaseSystemModule::GetStatusLine(BaseSystemModule *this)

{
  return "No status available.\n";
}


// BaseSystemModule::GetStatusLine  @ 000c3460
/* virtual thunk to BaseSystemModule::GetStatusLine() */

void __thiscall BaseSystemModule::GetStatusLine(BaseSystemModule *this)

{
  GetStatusLine((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x30) + -0x1c));
  return;
}


// BaseSystemModule::GetSystem  @ 000c34c0
/* DWARF original prototype: IBaseSystem * GetSystem(BaseSystemModule * this) */

IBaseSystem * __thiscall BaseSystemModule::GetSystem(BaseSystemModule *this)

{
  return this->m_System;
}


// BaseSystemModule::GetSystem  @ 000c34d0
/* virtual thunk to BaseSystemModule::GetSystem() */

void __thiscall BaseSystemModule::GetSystem(BaseSystemModule *this)

{
  GetSystem((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x28) + -0x1c));
  return;
}


// BaseSystemModule::GetType  @ 000c3430
/* DWARF original prototype: char * GetType(BaseSystemModule * this) */

char * __thiscall BaseSystemModule::GetType(BaseSystemModule *this)

{
  return "GenericModule";
}


// BaseSystemModule::GetType  @ 000c3440
/* virtual thunk to BaseSystemModule::GetType() */

void __thiscall BaseSystemModule::GetType(BaseSystemModule *this)

{
  GetType((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x34) + -0x1c));
  return;
}


// BaseSystemModule::GetVersion  @ 000c3530
/* DWARF original prototype: int GetVersion(BaseSystemModule * this) */

int __thiscall BaseSystemModule::GetVersion(BaseSystemModule *this)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if (build_number::b == 0) {
    iVar6 = 0;
    iVar7 = 0;
    do {
      iVar3 = Q_strncasecmp(date,mon[iVar6],3);
      if (iVar3 == 0) {
        bVar2 = 1 < iVar6;
        goto LAB_00035eda;
      }
      pcVar1 = mond + iVar6;
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + *pcVar1;
    } while (iVar6 != 0xb);
    bVar2 = true;
LAB_00035eda:
    lVar4 = strtol(date + 4,(char **)0x0,10);
    uVar5 = strtol(date + 7,(char **)0x0,10);
    iVar6 = (int)((float)(int)(uVar5 - 0x76d) * 365.25) + iVar7 + -1 + lVar4;
    if ((uVar5 & 3) == 0) {
      iVar6 = (iVar6 + 1) - (uint)!bVar2;
    }
    build_number::b = iVar6 + -0x88b3;
  }
  return build_number::b;
}


// BaseSystemModule::GetVersion  @ 000c3540
/* virtual thunk to BaseSystemModule::GetVersion() */

void __thiscall BaseSystemModule::GetVersion(BaseSystemModule *this)

{
  GetVersion((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x40) + -0x1c));
  return;
}


// BaseSystemModule::Init  @ 000c36e0
/* DWARF original prototype: bool Init(BaseSystemModule * this, IBaseSystem * system, int serial,
   char * name) */

bool __thiscall
BaseSystemModule::Init(BaseSystemModule *this,IBaseSystem *system,int serial,char *name)

{
  if (system != (IBaseSystem *)0x0) {
    this->m_System = system;
    this->m_State = 1;
    this->m_Serial = serial;
    *(undefined4 *)&this->m_SystemTime = 0;
    *(undefined4 *)((int)&this->m_SystemTime + 4) = 0;
    if (name != (char *)0x0) {
      strncpy(this->m_Name,name,0xfe);
      this->m_Name[0xfe] = '\0';
    }
    ObjectList::Init(&this->m_Listener);
    return true;
  }
  return false;
}


// BaseSystemModule::Init  @ 000c3760
/* virtual thunk to BaseSystemModule::Init(IBaseSystem*, int, char*) */

void __thiscall
BaseSystemModule::Init(BaseSystemModule *this,IBaseSystem *param_1,int param_2,char *param_3)

{
  Init((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x10) + -0x1c),param_1,param_2,
       param_3);
  return;
}


// BaseSystemModule::ReceiveSignal  @ 000c3550
/* DWARF original prototype: void ReceiveSignal(BaseSystemModule * this, ISystemModule * module,
   uint signal, void * data) */

void __thiscall
BaseSystemModule::ReceiveSignal(BaseSystemModule *this,ISystemModule *module,uint signal,void *data)

{
  code *UNRECOVERED_JUMPTABLE;
  _func_int_varargs *p_Var1;
  
  UNRECOVERED_JUMPTABLE = *(code **)((int)*this->m_System + 0x50);
  p_Var1 = (module->super_IBaseInterface)._vptr_IBaseInterface[0xc];
  if (p_Var1 != GetName) {
    (*p_Var1)(module);
  }
                    /* WARNING: Could not recover jumptable at 0x000c35a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// BaseSystemModule::ReceiveSignal  @ 000c35c0
/* virtual thunk to BaseSystemModule::ReceiveSignal(ISystemModule*, unsigned int, void*) */

void __thiscall
BaseSystemModule::ReceiveSignal
          (BaseSystemModule *this,ISystemModule *param_1,uint param_2,void *param_3)

{
  ReceiveSignal((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x18) + -0x1c),param_1,
                param_2,param_3);
  return;
}


// BaseSystemModule::RegisterListener  @ 000c38f0
/* DWARF original prototype: void RegisterListener(BaseSystemModule * this, ISystemModule * module)
    */

void __thiscall BaseSystemModule::RegisterListener(BaseSystemModule *this,ISystemModule *module)

{
  ObjectList *this_00;
  code *pcVar1;
  int *piVar2;
  _func_int_varargs **pp_Var3;
  _func_int_varargs *p_Var4;
  _func_int_varargs **pp_Var5;
  ISystemModule *pIVar6;
  IBaseSystem *pIVar7;
  
                    /* Unresolved local var: ISystemModule * listener@[???] */
  this_00 = &this->m_Listener;
  piVar2 = ObjectList::GetFirst(this_00);
  do {
    if (piVar2 == (int *)0x0) {
      ObjectList::Add(this_00,module);
      return;
    }
    if (*(code **)(*piVar2 + 0x24) == GetSerial) {
      pp_Var3 = (_func_int_varargs **)piVar2[0x48];
      p_Var4 = (module->super_IBaseInterface)._vptr_IBaseInterface[9];
      if (p_Var4 == GetSerial) goto LAB_000c392a;
LAB_000c3960:
      pp_Var5 = (_func_int_varargs **)(*p_Var4)(module);
      if (pp_Var3 == pp_Var5) {
LAB_000c3969:
                    /* Unresolved local var: ISystemModule * listener@[???] */
        pIVar7 = this->m_System;
        pcVar1 = *(code **)((int)*pIVar7 + 0x50);
        p_Var4 = (module->super_IBaseInterface)._vptr_IBaseInterface[0xc];
        if (p_Var4 == GetName) {
          pIVar6 = module + 7;
        }
        else {
          pIVar6 = (ISystemModule *)(*p_Var4)(module);
          pIVar7 = this->m_System;
        }
        (*pcVar1)(pIVar7,"WARNING! BaseSystemModule::RegisterListener: module %s already added.\n",
                  pIVar6);
        return;
      }
    }
    else {
      pp_Var3 = (_func_int_varargs **)(**(code **)(*piVar2 + 0x24))(piVar2);
      p_Var4 = (module->super_IBaseInterface)._vptr_IBaseInterface[9];
      if (p_Var4 != GetSerial) goto LAB_000c3960;
LAB_000c392a:
      if (pp_Var3 == module[0x48].super_IBaseInterface._vptr_IBaseInterface) goto LAB_000c3969;
    }
    piVar2 = ObjectList::GetNext(this_00);
  } while( true );
}


// BaseSystemModule::RegisterListener  @ 000c39c0
/* virtual thunk to BaseSystemModule::RegisterListener(ISystemModule*) */

void __thiscall BaseSystemModule::RegisterListener(BaseSystemModule *this,ISystemModule *param_1)

{
  RegisterListener((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x20) + -0x1c),
                   param_1);
  return;
}


// BaseSystemModule::RemoveListener  @ 000c39e0
/* DWARF original prototype: void RemoveListener(BaseSystemModule * this, ISystemModule * module) */

void __thiscall BaseSystemModule::RemoveListener(BaseSystemModule *this,ISystemModule *module)

{
  ObjectList *this_00;
  int *object;
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  _func_int_varargs **pp_Var3;
  
                    /* Unresolved local var: ISystemModule * listener@[???] */
  this_00 = &this->m_Listener;
  object = ObjectList::GetFirst(this_00);
  do {
    if (object == (int *)0x0) {
      return;
    }
    if (*(code **)(*object + 0x24) == GetSerial) {
      pp_Var1 = (_func_int_varargs **)object[0x48];
      p_Var2 = (module->super_IBaseInterface)._vptr_IBaseInterface[9];
      if (p_Var2 == GetSerial) goto LAB_000c3a22;
LAB_000c3a60:
      pp_Var3 = (_func_int_varargs **)(*p_Var2)(module);
      if (pp_Var1 == pp_Var3) {
LAB_000c3a69:
        ObjectList::Remove(this_00,object);
        return;
      }
    }
    else {
      pp_Var1 = (_func_int_varargs **)(**(code **)(*object + 0x24))(object);
      p_Var2 = (module->super_IBaseInterface)._vptr_IBaseInterface[9];
      if (p_Var2 != GetSerial) goto LAB_000c3a60;
LAB_000c3a22:
      if (pp_Var1 == module[0x48].super_IBaseInterface._vptr_IBaseInterface) goto LAB_000c3a69;
    }
    object = ObjectList::GetNext(this_00);
  } while( true );
}


// BaseSystemModule::RemoveListener  @ 000c3a90
/* virtual thunk to BaseSystemModule::RemoveListener(ISystemModule*) */

void __thiscall BaseSystemModule::RemoveListener(BaseSystemModule *this,ISystemModule *param_1)

{
  RemoveListener((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x24) + -0x1c),param_1
                );
  return;
}


// BaseSystemModule::RunFrame  @ 000c34e0
/* DWARF original prototype: void RunFrame(BaseSystemModule * this, double time) */

void __thiscall BaseSystemModule::RunFrame(BaseSystemModule *this,double time)

{
  this->m_SystemTime = time;
  return;
}


// BaseSystemModule::RunFrame  @ 000c3500
/* virtual thunk to BaseSystemModule::RunFrame(double) */

void __thiscall BaseSystemModule::RunFrame(BaseSystemModule *this,double param_1)

{
  RunFrame((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x14) + -0x1c),param_1);
  return;
}


// BaseSystemModule::ShutDown  @ 000c3780
/* DWARF original prototype: void ShutDown(BaseSystemModule * this) */

void __thiscall BaseSystemModule::ShutDown(BaseSystemModule *this)

{
  char cVar1;
  
  if (this->m_State != 4) {
    ObjectList::Clear(&this->m_Listener,false);
    this->m_State = 4;
    cVar1 = (**(code **)((int)*this->m_System + 0x98))
                      (this->m_System,this->m_Name + *(int *)(*(int *)this + -0x48) + -0x1c);
    if (cVar1 == '\0') {
      (**(code **)((int)*this->m_System + 0x50))
                (this->m_System,"ERROR! BaseSystemModule::ShutDown: faild to remove module %s.\n",
                 this->m_Name);
      return;
    }
  }
  return;
}


// BaseSystemModule::ShutDown  @ 000c3810
/* virtual thunk to BaseSystemModule::ShutDown() */

void __thiscall BaseSystemModule::ShutDown(BaseSystemModule *this)

{
  ShutDown((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x44) + -0x1c));
  return;
}


// BaseSystemModule::~BaseSystemModule  @ 000c3640
/* DWARF original prototype: void ~BaseSystemModule(BaseSystemModule * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall
BaseSystemModule::~BaseSystemModule(BaseSystemModule *this,int __in_chrg,void **__vtt_parm)

{
  int iVar1;
  
  iVar1 = *(int *)__in_chrg;
  *(int *)this = iVar1;
  *(undefined4 *)(this->m_Name + *(int *)(iVar1 + -0x48) + -0x1c) = *(undefined4 *)(__in_chrg + 4);
  ObjectList::~ObjectList(&this->m_Listener,__in_chrg);
  return;
}


// BaseSystemModule::~BaseSystemModule  @ 000c3670
/* DWARF original prototype: void ~BaseSystemModule(BaseSystemModule * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall
BaseSystemModule::~BaseSystemModule(BaseSystemModule *this,int __in_chrg,void **__vtt_parm)

{
  *(undefined ***)this = &PTR__BaseSystemModule_000dea70;
  ObjectList::~ObjectList(&this->m_Listener,__in_chrg);
  return;
}


// BaseSystemModule::~BaseSystemModule  @ 000c3690
/* virtual thunk to BaseSystemModule::~BaseSystemModule() */

void __thiscall BaseSystemModule::~BaseSystemModule(BaseSystemModule *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~BaseSystemModule((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0xc) + -0x1c),
                    in_stack_00000008,in_stack_0000000c);
  return;
}


// BaseSystemModule::~BaseSystemModule  @ 000c36a0
/* DWARF original prototype: void ~BaseSystemModule(BaseSystemModule * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall
BaseSystemModule::~BaseSystemModule(BaseSystemModule *this,int __in_chrg,void **__vtt_parm)

{
  int in_stack_ffffffe8;
  
  *(undefined ***)this = &PTR__BaseSystemModule_000dea70;
  ObjectList::~ObjectList(&this->m_Listener,in_stack_ffffffe8);
  operator_delete(this);
  return;
}


// BaseSystemModule::~BaseSystemModule  @ 000c36d0
/* virtual thunk to BaseSystemModule::~BaseSystemModule() */

void __thiscall BaseSystemModule::~BaseSystemModule(BaseSystemModule *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~BaseSystemModule((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0xc) + -0x1c),
                    in_stack_00000008,in_stack_0000000c);
  return;
}


// BoxOnPlaneSide  @ 0005f6e0
int BoxOnPlaneSide(vec_t *emins,vec_t *emaxs,mplane_t *p)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  
                    /* Unresolved local var: float dist1@[???]
                       Unresolved local var: float dist2@[???]
                       Unresolved local var: int sides@[???] */
  if (7 < p->signbits) {
    Sys_Error("BoxOnPlaneSide:  Bad signbits");
    fVar1 = 0.0;
    fVar2 = fVar1;
    goto LAB_0005f736;
  }
  fVar1 = p->normal[0];
  switch(p->signbits) {
  case '\0':
    fVar1 = p->normal[2] * emaxs[2] + p->normal[1] * emaxs[1] + fVar1 * *emaxs;
    fVar2 = p->normal[0] * *emins;
    break;
  case '\x01':
    fVar1 = p->normal[2] * emaxs[2] + p->normal[1] * emaxs[1] + fVar1 * *emins;
    fVar2 = p->normal[0] * *emaxs;
    break;
  case '\x02':
    fVar1 = p->normal[2] * emaxs[2] + p->normal[1] * emins[1] + fVar1 * *emaxs;
    fVar2 = p->normal[0] * *emins;
    goto LAB_0005f7d6;
  case '\x03':
    fVar1 = p->normal[2] * emaxs[2] + p->normal[1] * emins[1] + fVar1 * *emins;
    fVar2 = p->normal[0] * *emaxs;
LAB_0005f7d6:
    fVar2 = p->normal[2] * emins[2] + p->normal[1] * emaxs[1] + fVar2;
    goto LAB_0005f736;
  case '\x04':
    fVar1 = p->normal[2] * emins[2] + p->normal[1] * emaxs[1] + fVar1 * *emaxs;
    fVar2 = p->normal[0] * *emins;
    goto LAB_0005f826;
  case '\x05':
    fVar1 = p->normal[2] * emins[2] + p->normal[1] * emaxs[1] + fVar1 * *emins;
    fVar2 = p->normal[0] * *emaxs;
LAB_0005f826:
    fVar2 = p->normal[2] * emaxs[2] + p->normal[1] * emins[1] + fVar2;
    goto LAB_0005f736;
  case '\x06':
    fVar1 = p->normal[2] * emins[2] + p->normal[1] * emins[1] + fVar1 * *emaxs;
    fVar2 = p->normal[0] * *emins;
    goto LAB_0005f726;
  case '\a':
    fVar1 = p->normal[2] * emins[2] + p->normal[1] * emins[1] + fVar1 * *emins;
    fVar2 = p->normal[0] * *emaxs;
LAB_0005f726:
    fVar2 = p->normal[2] * emaxs[2] + p->normal[1] * emaxs[1] + fVar2;
    goto LAB_0005f736;
  }
  fVar2 = p->normal[2] * emins[2] + p->normal[1] * emins[1] + fVar2;
LAB_0005f736:
  uVar3 = (uint)(p->dist <= fVar1);
  if (fVar2 < p->dist) {
    uVar3 = uVar3 | 2;
  }
  return uVar3;
}


// BuildMapCycleListHints  @ 0007c6d0
int BuildMapCycleListHints(char **hints)

{
  FileHandle_t file;
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  size_t sVar6;
  char *pcVar7;
  size_t sVar8;
  char *pcVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  int in_GS_OFFSET;
  byte bVar13;
  char local_434 [260];
  char local_330 [260];
  uint local_22c [65];
  undefined1 local_127;
  char local_126 [262];
  int local_20;
  
                    /* Unresolved local var: char[262] szMap@[???]
                       Unresolved local var: uint length@[???]
                       Unresolved local var: char * pFileList@[???]
                       Unresolved local var: char[260] szMod@[???]
                       Unresolved local var: char[260] cszMapCycleTxtFile@[???]
                       Unresolved local var: FileHandle_t pFile@[???] */
  bVar13 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  COM_FileBase(com_gamedir,local_434);
  __snprintf_chk(local_330,0x104,1,0x104,"%s/%s",local_434,mapcyclefile.string);
  file = FS_Open(local_330,"rb");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("Unable to open %s\n",local_330);
    iVar5 = 0;
  }
  else {
    pcVar1 = GetCurrentSteamAppName();
    __snprintf_chk(local_22c,0x106,1,0x106,"%s\\%s\\%s%s\r\n",szReslistsBaseDir,pcVar1,
                   szCommonPreloads,szReslistsExt);
    puVar10 = local_22c;
    do {
      puVar4 = puVar10;
      uVar2 = *puVar4 + 0xfefefeff & ~*puVar4;
      uVar3 = uVar2 & 0x80808080;
      puVar10 = puVar4 + 1;
    } while (uVar3 == 0);
    if ((uVar2 & 0x8080) == 0) {
      puVar10 = (uint *)((int)puVar4 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    iVar5 = (-3 - (uint)CARRY1((byte)uVar3,(byte)uVar3)) - (int)local_22c;
    pcVar1 = (char *)((int)puVar10 + iVar5 + 1);
    puVar4 = malloc((size_t)pcVar1);
    *hints = (char *)puVar4;
    if (puVar4 == (uint *)0x0) {
      Con_Printf("Unable to allocate memory for map cycle hints list");
      iVar5 = 0;
    }
    else {
      puVar11 = local_22c;
      puVar12 = puVar4;
      if (((char *)0x7 < pcVar1) && (((uint)puVar4 & 4) != 0)) {
        puVar12 = puVar4 + 1;
        puVar11 = local_22c + 1;
        pcVar1 = (char *)((int)puVar10 + iVar5 + -3);
        *puVar4 = local_22c[0];
      }
      for (; pcVar1 != (char *)0x0; pcVar1 = pcVar1 + -1) {
        *(char *)puVar12 = (char)*puVar11;
        puVar11 = (uint *)((int)puVar11 + (uint)bVar13 * -2 + 1);
        puVar12 = (uint *)((int)puVar12 + (uint)bVar13 * -2 + 1);
      }
      uVar3 = FS_Size(file);
      if ((uVar3 != 0) && (pcVar1 = malloc(uVar3), pcVar1 != (char *)0x0)) {
        iVar5 = FS_Read(pcVar1,uVar3,1,file);
        if (iVar5 == 1) {
                    /* Unresolved local var: char[262] mapLine@[???] */
          while (pcVar1 = COM_Parse(pcVar1), com_token[0] != '\0') {
            strncpy((char *)local_22c,com_token,0x105);
            local_127 = 0;
            iVar5 = COM_TokenWaiting(pcVar1);
            if (iVar5 != 0) {
              pcVar1 = COM_Parse(pcVar1);
            }
            pcVar9 = szReslistsExt;
            pcVar7 = GetCurrentSteamAppName();
            __snprintf_chk(local_126,0x106,1,0x106,"%s\\%s\\%s%s\r\n",szReslistsBaseDir,pcVar7,
                           local_22c,pcVar9);
            pcVar9 = *hints;
            sVar6 = strlen(pcVar9);
            sVar8 = strlen(local_126);
            pcVar9 = realloc(pcVar9,sVar6 + 2 + sVar8);
            *hints = pcVar9;
            if (pcVar9 == (char *)0x0) {
              Con_Printf("Unable to reallocate memory for map cycle hints list");
              iVar5 = 0;
              goto LAB_0007c920;
            }
            strcat(pcVar9,local_126);
          }
        }
        free(pcVar1);
      }
      FS_Close(file);
      pcVar1 = GetCurrentSteamAppName();
      __snprintf_chk(local_22c,0x106,1,0x106,"%s\\%s\\mp_maps.txt\r\n",szReslistsBaseDir,pcVar1);
      pcVar1 = *hints;
      sVar6 = strlen(pcVar1);
      puVar10 = local_22c;
      do {
        puVar4 = puVar10;
        uVar3 = *puVar4 + 0xfefefeff & ~*puVar4;
        uVar2 = uVar3 & 0x80808080;
        puVar10 = puVar4 + 1;
      } while (uVar2 == 0);
      bVar13 = (byte)uVar2;
      if ((uVar3 & 0x8080) == 0) {
        bVar13 = (byte)(uVar2 >> 0x10);
        puVar10 = (uint *)((int)puVar4 + 6);
      }
      pcVar1 = realloc(pcVar1,(size_t)((int)puVar10 +
                                      sVar6 + (-(int)local_22c - (uint)CARRY1(bVar13,bVar13)) + -1))
      ;
      *hints = pcVar1;
      strcat(pcVar1,(char *)local_22c);
      iVar5 = 1;
    }
  }
LAB_0007c920:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CCallbackImpl<128>::GetCallbackSizeBytes  @ 000be8f0
/* DWARF original prototype: int GetCallbackSizeBytes(CCallbackImpl<128> * this) */

int __thiscall CCallbackImpl<128>::GetCallbackSizeBytes(CCallbackImpl<128> *this)

{
  return 0x80;
}


// CCallbackImpl<128>::Run  @ 000bf290
/* DWARF original prototype: void Run(CCallbackImpl<128> * this, void * pvParam, bool param_2,
   SteamAPICall_t param_3) */

void __thiscall
CCallbackImpl<128>::Run(CCallbackImpl<128> *this,void *pvParam,bool param_2,SteamAPICall_t param_3)

{
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  code *UNRECOVERED_JUMPTABLE_00;
  
  UNRECOVERED_JUMPTABLE = *(this->super_CCallbackBase)._vptr_CCallbackBase;
  if (UNRECOVERED_JUMPTABLE == CCallback<CSteam3Client,_GameServerChangeRequested_t,_false>::Run) {
    UNRECOVERED_JUMPTABLE_00 = *(code **)&this[1].super_CCallbackBase.m_nCallbackFlags;
    if (((uint)UNRECOVERED_JUMPTABLE_00 & 1) != 0) {
      UNRECOVERED_JUMPTABLE_00 =
           *(code **)(UNRECOVERED_JUMPTABLE_00 +
                     *(int *)(this[1].super_CCallbackBase.m_iCallback +
                             (int)this[1].super_CCallbackBase._vptr_CCallbackBase) + -1);
    }
                    /* WARNING: Could not recover jumptable at 0x000bf2c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000bf2d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CCallbackImpl<12>::GetCallbackSizeBytes  @ 000bea50
/* DWARF original prototype: int GetCallbackSizeBytes(CCallbackImpl<12> * this) */

int __thiscall CCallbackImpl<12>::GetCallbackSizeBytes(CCallbackImpl<12> *this)

{
  return 0xc;
}


// CCallbackImpl<12>::Run  @ 000bf330
/* DWARF original prototype: void Run(CCallbackImpl<12> * this, void * pvParam, bool param_2,
   SteamAPICall_t param_3) */

void __thiscall
CCallbackImpl<12>::Run(CCallbackImpl<12> *this,void *pvParam,bool param_2,SteamAPICall_t param_3)

{
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  code *UNRECOVERED_JUMPTABLE_00;
  
  UNRECOVERED_JUMPTABLE = *(this->super_CCallbackBase)._vptr_CCallbackBase;
  if (UNRECOVERED_JUMPTABLE == CCallback<CSteam3Server,_GSClientKick_t,_true>::Run) {
    UNRECOVERED_JUMPTABLE_00 = *(code **)&this[1].super_CCallbackBase.m_nCallbackFlags;
    if (((uint)UNRECOVERED_JUMPTABLE_00 & 1) != 0) {
      UNRECOVERED_JUMPTABLE_00 =
           *(code **)(UNRECOVERED_JUMPTABLE_00 +
                     *(int *)(this[1].super_CCallbackBase.m_iCallback +
                             (int)this[1].super_CCallbackBase._vptr_CCallbackBase) + -1);
    }
                    /* WARNING: Could not recover jumptable at 0x000bf364. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000bf379. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CCallbackImpl<140>::GetCallbackSizeBytes  @ 000bea90
/* DWARF original prototype: int GetCallbackSizeBytes(CCallbackImpl<140> * this) */

int __thiscall CCallbackImpl<140>::GetCallbackSizeBytes(CCallbackImpl<140> *this)

{
  return 0x8c;
}


// CCallbackImpl<140>::Run  @ 000bf380
/* DWARF original prototype: void Run(CCallbackImpl<140> * this, void * pvParam, bool param_2,
   SteamAPICall_t param_3) */

void __thiscall
CCallbackImpl<140>::Run(CCallbackImpl<140> *this,void *pvParam,bool param_2,SteamAPICall_t param_3)

{
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  code *UNRECOVERED_JUMPTABLE_00;
  
  UNRECOVERED_JUMPTABLE = *(this->super_CCallbackBase)._vptr_CCallbackBase;
  if (UNRECOVERED_JUMPTABLE == CCallback<CSteam3Server,_GSClientDeny_t,_true>::Run) {
    UNRECOVERED_JUMPTABLE_00 = *(code **)&this[1].super_CCallbackBase.m_nCallbackFlags;
    if (((uint)UNRECOVERED_JUMPTABLE_00 & 1) != 0) {
      UNRECOVERED_JUMPTABLE_00 =
           *(code **)(UNRECOVERED_JUMPTABLE_00 +
                     *(int *)(this[1].super_CCallbackBase.m_iCallback +
                             (int)this[1].super_CCallbackBase._vptr_CCallbackBase) + -1);
    }
                    /* WARNING: Could not recover jumptable at 0x000bf3b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000bf3c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CCallbackImpl<160>::GetCallbackSizeBytes  @ 000be980
/* DWARF original prototype: int GetCallbackSizeBytes(CCallbackImpl<160> * this) */

int __thiscall CCallbackImpl<160>::GetCallbackSizeBytes(CCallbackImpl<160> *this)

{
  return 0xa0;
}


// CCallbackImpl<160>::Run  @ 000bf2e0
/* DWARF original prototype: void Run(CCallbackImpl<160> * this, void * pvParam, bool param_2,
   SteamAPICall_t param_3) */

void __thiscall
CCallbackImpl<160>::Run(CCallbackImpl<160> *this,void *pvParam,bool param_2,SteamAPICall_t param_3)

{
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  code *UNRECOVERED_JUMPTABLE_00;
  
  UNRECOVERED_JUMPTABLE = *(this->super_CCallbackBase)._vptr_CCallbackBase;
  if (UNRECOVERED_JUMPTABLE == CCallback<CSteam3Server,_SteamNetworkingFakeIPResult_t,_true>::Run) {
    UNRECOVERED_JUMPTABLE_00 = *(code **)&this[1].super_CCallbackBase.m_nCallbackFlags;
    if (((uint)UNRECOVERED_JUMPTABLE_00 & 1) != 0) {
      UNRECOVERED_JUMPTABLE_00 =
           *(code **)(UNRECOVERED_JUMPTABLE_00 +
                     *(int *)(this[1].super_CCallbackBase.m_iCallback +
                             (int)this[1].super_CCallbackBase._vptr_CCallbackBase) + -1);
    }
                    /* WARNING: Could not recover jumptable at 0x000bf314. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000bf329. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// CCallbackImpl<16>::GetCallbackSizeBytes  @ 000be940
/* DWARF original prototype: int GetCallbackSizeBytes(CCallbackImpl<16> * this) */

int __thiscall CCallbackImpl<16>::GetCallbackSizeBytes(CCallbackImpl<16> *this)

{
  return 0x10;
}


// CCallbackImpl<16>::Run  @ 000be930
/* DWARF original prototype: void Run(CCallbackImpl<16> * this, void * pvParam, bool param_2,
   SteamAPICall_t param_3) */

void __thiscall
CCallbackImpl<16>::Run(CCallbackImpl<16> *this,void *pvParam,bool param_2,SteamAPICall_t param_3)

{
                    /* WARNING: Could not recover jumptable at 0x000be936. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(this->super_CCallbackBase)._vptr_CCallbackBase)();
  return;
}


// CCallbackImpl<1>::GetCallbackSizeBytes  @ 000be860
/* DWARF original prototype: int GetCallbackSizeBytes(CCallbackImpl<1> * this) */

int __thiscall CCallbackImpl<1>::GetCallbackSizeBytes(CCallbackImpl<1> *this)

{
  return 1;
}


// CCallbackImpl<1>::Run  @ 000be850
/* DWARF original prototype: void Run(CCallbackImpl<1> * this, void * pvParam, bool param_2,
   SteamAPICall_t param_3) */

void __thiscall
CCallbackImpl<1>::Run(CCallbackImpl<1> *this,void *pvParam,bool param_2,SteamAPICall_t param_3)

{
                    /* WARNING: Could not recover jumptable at 0x000be856. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(this->super_CCallbackBase)._vptr_CCallbackBase)();
  return;
}


// CCallbackImpl<264>::GetCallbackSizeBytes  @ 000be840
/* DWARF original prototype: int GetCallbackSizeBytes(CCallbackImpl<264> * this) */

int __thiscall CCallbackImpl<264>::GetCallbackSizeBytes(CCallbackImpl<264> *this)

{
  return 0x108;
}


// CCallbackImpl<264>::Run  @ 000bf230
/* DWARF original prototype: void Run(CCallbackImpl<264> * this, void * pvParam, bool param_2,
   SteamAPICall_t param_3) */

void __thiscall
CCallbackImpl<264>::Run(CCallbackImpl<264> *this,void *pvParam,bool param_2,SteamAPICall_t param_3)

{
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  int cubSize;
  
  UNRECOVERED_JUMPTABLE = *(this->super_CCallbackBase)._vptr_CCallbackBase;
  if (UNRECOVERED_JUMPTABLE != CSteam3Client::CCallbackInternal_OnGameRichPresenceJoinRequested::Run
     ) {
                    /* WARNING: Could not recover jumptable at 0x000bf284. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
                    /* Unresolved local var: CSteam3Client * pOuter@[???]
                       Unresolved local var: char * szConCommand@[???] */
  Con_Printf("OnGameRichPresenceJoinRequested\n");
  if ((pvParam != (void *)0x0) && (*(char *)((int)pvParam + 8) != '\0')) {
    UnsafeCmdLineProcessor((char *)((int)pvParam + 8),cubSize);
    return;
  }
  return;
}


// CCallbackImpl<8>::GetCallbackSizeBytes  @ 000be8b0
/* DWARF original prototype: int GetCallbackSizeBytes(CCallbackImpl<8> * this) */

int __thiscall CCallbackImpl<8>::GetCallbackSizeBytes(CCallbackImpl<8> *this)

{
  return 8;
}


// CCallbackImpl<8>::Run  @ 000be8a0
/* DWARF original prototype: void Run(CCallbackImpl<8> * this, void * pvParam, bool param_2,
   SteamAPICall_t param_3) */

void __thiscall
CCallbackImpl<8>::Run(CCallbackImpl<8> *this,void *pvParam,bool param_2,SteamAPICall_t param_3)

{
                    /* WARNING: Could not recover jumptable at 0x000be8a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(this->super_CCallbackBase)._vptr_CCallbackBase)();
  return;
}


// CDedicatedServerAPI::AddConsoleText  @ 0007b8f0
/* DWARF original prototype: void AddConsoleText(CDedicatedServerAPI * this, char * text) */

void __thiscall CDedicatedServerAPI::AddConsoleText(CDedicatedServerAPI *this,char *text)

{
  Cbuf_AddText(text);
  return;
}


// CDedicatedServerAPI::Init  @ 0007b950
/* DWARF original prototype: bool Init(CDedicatedServerAPI * this, char * basedir, char * cmdline,
   CreateInterfaceFn launcherFactory, CreateInterfaceFn filesystemFactory) */

bool __thiscall
CDedicatedServerAPI::Init
          (CDedicatedServerAPI *this,char *basedir,char *cmdline,CreateInterfaceFn launcherFactory,
          CreateInterfaceFn filesystemFactory)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *__dest;
  int in_GS_OFFSET;
  char local_120 [255];
  undefined1 local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  dedicated = (*launcherFactory)("VENGINE_DEDICATEDEXPORTS_API_VERSION001",(int *)0x0);
  if (dedicated != (IDedicatedExports *)0x0) {
    __dest = this->m_OrigCmd;
    strcpy(__dest,cmdline);
    pcVar2 = strstr(cmdline,"-nobreakpad");
    if (pcVar2 == (char *)0x0) {
      iVar3 = build_number();
      pcVar2 = va("%d",iVar3);
      SteamAPI_UseBreakpadCrashHandler(pcVar2,&DAT_000d0930,"01:34:04",0,0,0);
    }
    TraceInit("Sys_InitArgv( m_OrigCmd )","Sys_ShutdownArgv()",0);
    host_parms.argc = 1;
    argv[0] = "";
    while ((iVar3 = host_parms.argc, *__dest != '\0' && (host_parms.argc < 0x32))) {
      if (0x5d < (byte)(*__dest - 0x21U)) {
        do {
          __dest = __dest + 1;
          cVar1 = *__dest;
          if ((byte)(cVar1 - 0x21U) < 0x5e) break;
        } while (cVar1 != '\0');
        if (cVar1 == '\0') break;
      }
      iVar3 = host_parms.argc + 1;
      host_parms.argc = iVar3;
      *(char **)(iVar3 * 4 + 0x35c75c) = __dest;
      for (; (byte)(*__dest - 0x21U) < 0x5e; __dest = __dest + 1) {
      }
      if (*__dest == '\0') break;
      *__dest = '\0';
      __dest = __dest + 1;
    }
    host_parms.argv = argv;
    COM_InitArgv(iVar3,argv);
    host_parms.argc = com_argc;
    host_parms.argv = com_argv;
    (*eng->_vptr_IEngine[0x11])(eng,0);
    (**registry->_vptr_IRegistry)(registry);
    g_bIsDedicatedServer = true;
    TraceInit("FileSystem_Init(basedir, (void *)filesystemFactory)","FileSystem_Shutdown()",0);
    iVar3 = FileSystem_Init(basedir,filesystemFactory);
    if ((iVar3 != 0) && (iVar3 = (*game->_vptr_IGame[2])(game,0), (char)iVar3 != '\0')) {
      iVar3 = (*eng->_vptr_IEngine[2])(eng,1,basedir,cmdline);
      cVar1 = (char)iVar3;
      if (cVar1 != '\0') {
                    /* Unresolved local var: char[256] szCommand@[???] */
        __snprintf_chk(local_120,0xff,1,0x100,"exec %s\n",servercfgfile.string);
        local_21 = 0;
        Cbuf_InsertText(local_120);
        goto LAB_0007bac0;
      }
    }
  }
  cVar1 = '\0';
LAB_0007bac0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (bool)cVar1;
}


// CDedicatedServerAPI::RunFrame  @ 0007b920
/* DWARF original prototype: bool RunFrame(CDedicatedServerAPI * this) */

bool __thiscall CDedicatedServerAPI::RunFrame(CDedicatedServerAPI *this)

{
  int iVar1;
  
  iVar1 = (*eng->_vptr_IEngine[0x10])(eng);
  if (iVar1 == 0) {
    (*eng->_vptr_IEngine[8])(eng);
  }
  return iVar1 == 0;
}


// CDedicatedServerAPI::Shutdown  @ 0007b880
/* DWARF original prototype: int Shutdown(CDedicatedServerAPI * this) */

int __thiscall CDedicatedServerAPI::Shutdown(CDedicatedServerAPI *this)

{
  (*eng->_vptr_IEngine[3])(eng);
  (*game->_vptr_IGame[3])(game);
  TraceShutdown("FileSystem_Shutdown()",0);
  FileSystem_Shutdown();
  (*registry->_vptr_IRegistry[1])(registry);
  TraceShutdown("Sys_ShutdownArgv()",0);
  dedicated = (IDedicatedExports *)0x0;
  return giActive;
}


// CDedicatedServerAPI::UpdateStatus  @ 0007b900
/* DWARF original prototype: void UpdateStatus(CDedicatedServerAPI * this, float * fps, int *
   nActive, int * nMaxPlayers, char * pszMap) */

void __thiscall
CDedicatedServerAPI::UpdateStatus
          (CDedicatedServerAPI *this,float *fps,int *nActive,int *nMaxPlayers,char *pszMap)

{
  Host_GetHostInfo(fps,nActive,(int *)0x0,nMaxPlayers,pszMap);
  return;
}


// CDedicatedServerAPI::~CDedicatedServerAPI  @ 0007cad0
/* DWARF original prototype: void ~CDedicatedServerAPI(CDedicatedServerAPI * this, int __in_chrg) */

void __thiscall CDedicatedServerAPI::~CDedicatedServerAPI(CDedicatedServerAPI *this,int __in_chrg)

{
  return;
}


// CDedicatedServerAPI::~CDedicatedServerAPI  @ 0007cb10
/* DWARF original prototype: void ~CDedicatedServerAPI(CDedicatedServerAPI * this, int __in_chrg) */

void __thiscall CDedicatedServerAPI::~CDedicatedServerAPI(CDedicatedServerAPI *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// CEngine::CEngine  @ 0007f3d0
/* DWARF original prototype: void CEngine(CEngine * this) */

void __thiscall CEngine::CEngine(CEngine *this)

{
  this->m_fFrameTime = 0.0;
  (this->super_IEngine)._vptr_IEngine = (_func_int_varargs **)&PTR__CEngine_000d885c;
  this->m_nSubState = 0;
  this->m_nDLLState = 0;
  this->m_fOldTime = 0.0;
  this->m_bTrapMode = false;
  this->m_bDoneTrapping = false;
  this->m_nTrapKey = 0;
  this->m_nTrapButtons = 0;
  this->m_nQuitting = 0;
  return;
}


// CEngine::CheckDoneTrapping  @ 0007f190
/* DWARF original prototype: bool CheckDoneTrapping(CEngine * this, int * buttons, int * key) */

bool __thiscall CEngine::CheckDoneTrapping(CEngine *this,int *buttons,int *key)

{
  char cVar1;
  
  cVar1 = '\0';
  if ((this->m_bTrapMode == false) && (cVar1 = this->m_bDoneTrapping, (bool)cVar1 != false)) {
    *key = this->m_nTrapKey;
    *buttons = this->m_nTrapButtons;
    this->m_bDoneTrapping = false;
  }
  return (bool)cVar1;
}


// CEngine::Frame  @ 0007f270
/* DWARF original prototype: int Frame(CEngine * this) */

int __thiscall CEngine::Frame(CEngine *this)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  undefined4 uVar3;
  int iState;
  longdouble lVar4;
  double dVar5;
  int local_10 [2];
  
  iVar2 = (*game->_vptr_IGame[0xb])(game);
  if ((char)iVar2 == '\0') {
    uVar3 = 0x14;
    if (this->m_nDLLState == 2) {
      uVar3 = 0x32;
    }
    (*game->_vptr_IGame[5])(game,uVar3);
  }
  dVar5 = Sys_FloatTime();
  this->m_fCurTime = dVar5;
  lVar4 = (longdouble)dVar5 - (longdouble)this->m_fOldTime;
  this->m_fFrameTime = (double)lVar4;
  this->m_fOldTime = dVar5;
  if (lVar4 < (longdouble)0) {
    *(undefined4 *)&this->m_fFrameTime = 0x40000000;
    lVar4 = (longdouble)0.01;
    *(undefined4 *)((int)&this->m_fFrameTime + 4) = 0x3f847ae1;
  }
  if (this->m_nDLLState == 0) {
    iVar2 = 0;
  }
  else {
                    /* Unresolved local var: int dummy@[???]
                       Unresolved local var: int iState@[???] */
    iState = Host_Frame((float)lVar4,this->m_nDLLState,local_10);
    iVar2 = this->m_nDLLState;
    if (iState != iVar2) {
      p_Var1 = (this->super_IEngine)._vptr_IEngine[4];
      if (p_Var1 == SetState) {
        this->m_nDLLState = iState;
        GameSetState(iState);
      }
      else {
        (*p_Var1)(this,iState);
      }
      iVar2 = this->m_nDLLState;
      if (iVar2 == 3) {
        p_Var1 = (this->super_IEngine)._vptr_IEngine[0x11];
        if (p_Var1 == SetQuitting) {
          this->m_nQuitting = 1;
        }
        else {
          (*p_Var1)(this,1);
          iVar2 = this->m_nDLLState;
        }
      }
      else if (iVar2 == 5) {
        p_Var1 = (this->super_IEngine)._vptr_IEngine[0x11];
        if (p_Var1 == SetQuitting) {
          this->m_nQuitting = 2;
        }
        else {
          (*p_Var1)(this,2);
          iVar2 = this->m_nDLLState;
        }
      }
    }
  }
  return iVar2;
}


// CEngine::GetCurTime  @ 0007f0b0
/* DWARF original prototype: double GetCurTime(CEngine * this) */

double __thiscall CEngine::GetCurTime(CEngine *this)

{
  return this->m_fCurTime;
}


// CEngine::GetFrameTime  @ 0007f0a0
/* DWARF original prototype: double GetFrameTime(CEngine * this) */

double __thiscall CEngine::GetFrameTime(CEngine *this)

{
  return this->m_fFrameTime;
}


// CEngine::GetQuitting  @ 0007f110
/* DWARF original prototype: int GetQuitting(CEngine * this) */

int __thiscall CEngine::GetQuitting(CEngine *this)

{
  return this->m_nQuitting;
}


// CEngine::GetState  @ 0007f080
/* DWARF original prototype: int GetState(CEngine * this) */

int __thiscall CEngine::GetState(CEngine *this)

{
  return this->m_nDLLState;
}


// CEngine::GetSubState  @ 0007f090
/* DWARF original prototype: int GetSubState(CEngine * this) */

int __thiscall CEngine::GetSubState(CEngine *this)

{
  return this->m_nSubState;
}


// CEngine::IsTrapping  @ 0007f0f0
/* DWARF original prototype: bool IsTrapping(CEngine * this) */

bool __thiscall CEngine::IsTrapping(CEngine *this)

{
  return this->m_bTrapMode;
}


// CEngine::Load  @ 0007f200
/* DWARF original prototype: bool Load(CEngine * this, bool dedicated, char * basedir, char *
   cmdline) */

bool __thiscall CEngine::Load(CEngine *this,bool dedicated,char *basedir,char *cmdline)

{
  _func_int_varargs *p_Var1;
  void *pwnd;
  int iVar2;
  
                    /* Unresolved local var: bool success@[???] */
  p_Var1 = (this->super_IEngine)._vptr_IEngine[4];
  if (p_Var1 == SetState) {
    this->m_nDLLState = 1;
    GameSetState(1);
  }
  else {
    (*p_Var1)(this,1);
  }
  pwnd = (void *)(*game->_vptr_IGame[7])(game);
  iVar2 = Sys_InitGame(cmdline,basedir,pwnd,(uint)dedicated);
  return iVar2 != 0;
}


// CEngine::SetQuitting  @ 0007f100
/* DWARF original prototype: void SetQuitting(CEngine * this, int quittype) */

void __thiscall CEngine::SetQuitting(CEngine *this,int quittype)

{
  this->m_nQuitting = quittype;
  return;
}


// CEngine::SetState  @ 0007f170
/* DWARF original prototype: void SetState(CEngine * this, int iState) */

void __thiscall CEngine::SetState(CEngine *this,int iState)

{
  this->m_nDLLState = iState;
  GameSetState(iState);
  return;
}


// CEngine::SetSubState  @ 0007f150
/* DWARF original prototype: void SetSubState(CEngine * this, int iSubState) */

void __thiscall CEngine::SetSubState(CEngine *this,int iSubState)

{
  if (iSubState != 1) {
    GameSetSubState(iSubState);
    return;
  }
  return;
}


// CEngine::StartTrapMode  @ 0007f0d0
/* DWARF original prototype: void StartTrapMode(CEngine * this) */

void __thiscall CEngine::StartTrapMode(CEngine *this)

{
  if (this->m_bTrapMode == false) {
    this->m_bDoneTrapping = false;
    this->m_bTrapMode = true;
  }
  return;
}


// CEngine::Unload  @ 0007f130
/* DWARF original prototype: void Unload(CEngine * this) */

void __thiscall CEngine::Unload(CEngine *this)

{
  Sys_ShutdownGame();
  this->m_nDLLState = 0;
  return;
}


// CEngine::~CEngine  @ 0007f070
/* DWARF original prototype: void ~CEngine(CEngine * this, int __in_chrg) */

void __thiscall CEngine::~CEngine(CEngine *this,int __in_chrg)

{
  return;
}


// CEngine::~CEngine  @ 0007f120
/* DWARF original prototype: void ~CEngine(CEngine * this, int __in_chrg) */

void __thiscall CEngine::~CEngine(CEngine *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// CEngineAPI::Run  @ 0007b7c0
/* DWARF original prototype: int Run(CEngineAPI * this, void * instance, char * basedir, char *
   cmdline, char * postRestartCmdLineArgs, CreateInterfaceFn launcherFactory, CreateInterfaceFn
   filesystemFactory) */

int __thiscall
CEngineAPI::Run(CEngineAPI *this,void *instance,char *basedir,char *cmdline,
               char *postRestartCmdLineArgs,CreateInterfaceFn launcherFactory,
               CreateInterfaceFn filesystemFactory)

{
  return 0;
}


// CEngineAPI::~CEngineAPI  @ 0007cae0
/* DWARF original prototype: void ~CEngineAPI(CEngineAPI * this, int __in_chrg) */

void __thiscall CEngineAPI::~CEngineAPI(CEngineAPI *this,int __in_chrg)

{
  return;
}


// CEngineAPI::~CEngineAPI  @ 0007cb00
/* DWARF original prototype: void ~CEngineAPI(CEngineAPI * this, int __in_chrg) */

void __thiscall CEngineAPI::~CEngineAPI(CEngineAPI *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// CGame::CGame  @ 0007f4d0
/* DWARF original prototype: void CGame(CGame * this) */

void __thiscall CGame::CGame(CGame *this)

{
  (this->super_IGame)._vptr_IGame = (_func_int_varargs **)&PTR__CGame_000d88d4;
  this->m_bActiveApp = true;
  return;
}


// CGame::GetMainWindowAddress  @ 0007f430
/* DWARF original prototype: void * * GetMainWindowAddress(CGame * this) */

void ** __thiscall CGame::GetMainWindowAddress(CGame *this)

{
  return (void **)0x0;
}


// CGame::GetWindowRect  @ 0007f450
/* DWARF original prototype: void GetWindowRect(CGame * this, int * x, int * y, int * w, int * h) */

void __thiscall CGame::GetWindowRect(CGame *this,int *x,int *y,int *w,int *h)

{
  if (x != (int *)0x0) {
    *x = 0;
  }
  if (y != (int *)0x0) {
    *y = 0;
  }
  if (w != (int *)0x0) {
    *w = 0;
  }
  if (h != (int *)0x0) {
    *h = 0;
  }
  return;
}


// CGame::Init  @ 0007f420
/* DWARF original prototype: bool Init(CGame * this, void * pvInstance) */

bool __thiscall CGame::Init(CGame *this,void *pvInstance)

{
  return true;
}


// CGame::IsActiveApp  @ 0007f490
/* DWARF original prototype: bool IsActiveApp(CGame * this) */

bool __thiscall CGame::IsActiveApp(CGame *this)

{
  return this->m_bActiveApp;
}


// CGame::IsMultiplayer  @ 0007f4a0
/* DWARF original prototype: bool IsMultiplayer(CGame * this) */

bool __thiscall CGame::IsMultiplayer(CGame *this)

{
  return true;
}


// CGame::PlayAVIAndWait  @ 0007f510
/* DWARF original prototype: void PlayAVIAndWait(CGame * this, char * fileName) */

void __thiscall CGame::PlayAVIAndWait(CGame *this,char *fileName)

{
  return;
}


// CGame::PlayStartupVideos  @ 0007f500
/* DWARF original prototype: void PlayStartupVideos(CGame * this) */

void __thiscall CGame::PlayStartupVideos(CGame *this)

{
  return;
}


// CGame::SetActiveApp  @ 0007f4e0
/* DWARF original prototype: void SetActiveApp(CGame * this, bool active) */

void __thiscall CGame::SetActiveApp(CGame *this,bool active)

{
  this->m_bActiveApp = active;
  return;
}


// CGame::SetCursorVisible  @ 0007f520
/* DWARF original prototype: void SetCursorVisible(CGame * this, bool bState) */

void __thiscall CGame::SetCursorVisible(CGame *this,bool bState)

{
  return;
}


// CGame::SetWindowSize  @ 0007f440
/* DWARF original prototype: void SetWindowSize(CGame * this, int w, int h) */

void __thiscall CGame::SetWindowSize(CGame *this,int w,int h)

{
  return;
}


// CGame::SleepUntilInput  @ 0007f4b0
/* DWARF original prototype: void SleepUntilInput(CGame * this, int time) */

void __thiscall CGame::SleepUntilInput(CGame *this,int time)

{
  sleep(time);
  return;
}


// CGame::~CGame  @ 0007f410
/* DWARF original prototype: void ~CGame(CGame * this, int __in_chrg) */

void __thiscall CGame::~CGame(CGame *this,int __in_chrg)

{
  return;
}


// CGame::~CGame  @ 0007f4c0
/* DWARF original prototype: void ~CGame(CGame * this, int __in_chrg) */

void __thiscall CGame::~CGame(CGame *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// CIPRateLimit::CIPRateLimit  @ 000b53f0
/* DWARF original prototype: void CIPRateLimit(CIPRateLimit * this) */

void __thiscall CIPRateLimit::CIPRateLimit(CIPRateLimit *this)

{
  Node_t *pNVar1;
  
  (this->m_IPTree).m_LessFunc = LessIP;
  (this->m_IPTree).m_Elements.m_NumAllocated = 0x100;
  (this->m_IPTree).m_Elements.m_GrowSize = 0;
  pNVar1 = malloc(0x1c00);
  (this->m_IPTree).m_Root = -1;
  (this->m_IPTree).m_NumElements = 0;
  (this->m_IPTree).m_FirstFree = -1;
  (this->m_IPTree).m_TotalElements = 0;
  this->m_iGlobalCount = 0;
  (this->m_IPTree).m_Elements.m_pMemory = pNVar1;
  this->m_lLastTime = -1;
  return;
}


// CIPRateLimit::CheckIP  @ 000b5480
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: bool CheckIP(CIPRateLimit * this, netadr_t.conflict adr) */

bool __thiscall CIPRateLimit::CheckIP(CIPRateLimit *this,netadr_t_conflict adr)

{
  int *piVar1;
  float fVar2;
  bool bVar3;
  time_t tVar4;
  Node_t *pNVar5;
  int iVar6;
  int iVar7;
  Links_t *pLVar8;
  int iVar9;
  iprate_s local_34;
  iprate_s local_28 [2];
  
                    /* Unresolved local var: long curTime@[???]
                       Unresolved local var: ip_t clientIP@[???]
                       Unresolved local var: iprate_s findEntry@[???]
                       Unresolved local var: ip_t entry@[DW_OP_reg6(ESI)] */
  tVar4 = time((time_t *)0x0);
  if (0x200 < (uint)(this->m_IPTree).m_NumElements) {
                    /* Unresolved local var: ip_t tmp@[???]
                       Unresolved local var: int i@[???] */
    iVar6 = (this->m_IPTree).m_Root;
    while( true ) {
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar9 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar9 != 0)) {
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Left = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Right = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      iVar9 = CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Right;
      if (iVar6 != -1) {
        iVar9 = (this->m_IPTree).m_Elements.m_pMemory[iVar6].super_Links_t.m_Right;
      }
      if (iVar9 == -1) break;
      if (CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') {
        iVar9 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel)
        ;
        if (iVar9 != 0) {
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Left = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Right = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        if (iVar6 != -1) goto LAB_000b578e;
LAB_000b58d4:
        pLVar8 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel;
      }
      else {
        if (iVar6 == -1) goto LAB_000b58d4;
LAB_000b578e:
        pLVar8 = &(this->m_IPTree).m_Elements.m_pMemory[iVar6].super_Links_t;
      }
      iVar6 = (((Node_t *)pLVar8)->super_Links_t).m_Right;
    }
    iVar9 = 0;
LAB_000b5810:
    if (0x155 < (uint)(this->m_IPTree).m_NumElements) {
      do {
        if ((this->m_IPTree).m_TotalElements <= iVar9) break;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar7 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar7 != 0)) {
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Left = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Right = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          if (iVar6 != -1) goto LAB_000b583c;
LAB_000b5940:
          pLVar8 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel;
        }
        else {
          if (iVar6 == -1) goto LAB_000b5940;
LAB_000b583c:
          pLVar8 = &(this->m_IPTree).m_Elements.m_pMemory[iVar6].super_Links_t;
        }
        if (((iVar6 == (((Node_t *)pLVar8)->super_Links_t).m_Left) ||
            (pNVar5 = (this->m_IPTree).m_Elements.m_pMemory,
            tVar4 - pNVar5[iVar6].m_Data.lastTime < 0x79)) ||
           ((uchar  [4])pNVar5[iVar6].m_Data.ip == adr.ip)) goto LAB_000b58e0;
                    /* Unresolved local var: ip_t removeIPT@[???] */
        iVar7 = CUtlRBTree<CIPRateLimit::iprate_s,_int>::PrevInorder(&this->m_IPTree,iVar6);
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::RemoveAt(&this->m_IPTree,iVar6);
        iVar6 = iVar7;
        if ((uint)(this->m_IPTree).m_NumElements < 0x156) break;
      } while( true );
    }
  }
  local_34.count = 0;
                    /* Unresolved local var: int current@[???] */
  iVar6 = (this->m_IPTree).m_Root;
  local_34.lastTime = 0;
  local_34.ip._0_1_ = adr.ip[0];
  local_34.ip._1_1_ = adr.ip[1];
  local_34.ip._2_1_ = adr.ip[2];
  local_34.ip._3_1_ = adr.ip[3];
  if (iVar6 != -1) {
    pNVar5 = (this->m_IPTree).m_Elements.m_pMemory;
    do {
      while (bVar3 = (*(this->m_IPTree).m_LessFunc)(&local_34,&pNVar5[iVar6].m_Data), !bVar3) {
        bVar3 = (*(this->m_IPTree).m_LessFunc)
                          (&(this->m_IPTree).m_Elements.m_pMemory[iVar6].m_Data,&local_34);
        if (!bVar3) {
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel != '\0') ||
             (iVar9 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar9 == 0)) goto LAB_000b55b5;
          goto LAB_000b5573;
        }
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar9 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar9 != 0)) {
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Left = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Right = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pNVar5 = (this->m_IPTree).m_Elements.m_pMemory;
        iVar6 = pNVar5[iVar6].super_Links_t.m_Right;
        if (iVar6 == -1) goto LAB_000b554d;
      }
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar9 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar9 != 0)) {
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Left = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Right = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar5 = (this->m_IPTree).m_Elements.m_pMemory;
      iVar6 = pNVar5[iVar6].super_Links_t.m_Left;
    } while (iVar6 != -1);
  }
LAB_000b554d:
  if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar6 != 0)) {
    iVar6 = -1;
LAB_000b5573:
    CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Right = -1;
    CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Left = -1;
    CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
    if (iVar6 == -1) goto LAB_000b5988;
LAB_000b55b5:
    iVar9 = iVar6 * 0x1c;
    if (iVar6 == (this->m_IPTree).m_Elements.m_pMemory[iVar6].super_Links_t.m_Left)
    goto LAB_000b599f;
  }
  else {
LAB_000b5988:
    iVar9 = -0x1c;
    if (CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::s_Sentinel.m_Left == -1) {
LAB_000b599f:
                    /* Unresolved local var: iprate_s newEntry@[???] */
      local_28[0].count = 1;
      local_28[0].ip._0_1_ = adr.ip[0];
      local_28[0].ip._1_1_ = adr.ip[1];
      local_28[0].ip._2_1_ = adr.ip[2];
      local_28[0].ip._3_1_ = adr.ip[3];
      local_28[0].lastTime = tVar4;
      CUtlRBTree<CIPRateLimit::iprate_s,_int>::Insert(&this->m_IPTree,local_28);
      fVar2 = max_queries_window.value;
      goto LAB_000b55ff;
    }
  }
  fVar2 = max_queries_window.value;
  piVar1 = (int *)((int)&(((this->m_IPTree).m_Elements.m_pMemory)->m_Data).count + iVar9);
  *piVar1 = *piVar1 + 1;
  pNVar5 = (this->m_IPTree).m_Elements.m_pMemory;
  if ((float)(tVar4 - *(int *)((int)&(pNVar5->m_Data).lastTime + iVar9)) <= fVar2) {
                    /* Unresolved local var: float query_rate@[???] */
    if (max_queries_sec.value < (float)*(int *)((int)&(pNVar5->m_Data).count + iVar9) / fVar2) {
      return false;
    }
  }
  else {
    *(time_t *)((int)&(pNVar5->m_Data).lastTime + iVar9) = tVar4;
    *(undefined4 *)((int)&(((this->m_IPTree).m_Elements.m_pMemory)->m_Data).count + iVar9) = 1;
  }
LAB_000b55ff:
  iVar6 = this->m_iGlobalCount + 1;
  this->m_iGlobalCount = iVar6;
  if ((float)(tVar4 - this->m_lLastTime) <= fVar2) {
                    /* Unresolved local var: float query_rate@[???] */
    return (float)iVar6 / fVar2 <= max_queries_sec_global.value;
  }
  this->m_iGlobalCount = 1;
  this->m_lLastTime = tVar4;
  return true;
LAB_000b58e0:
  iVar9 = iVar9 + 1;
  iVar6 = CUtlRBTree<CIPRateLimit::iprate_s,_int>::PrevInorder(&this->m_IPTree,iVar6);
  goto LAB_000b5810;
}


// CIPRateLimit::LessIP  @ 000b53e0
bool CIPRateLimit::LessIP(iprate_s *lhs,iprate_s *rhs)

{
  return lhs->ip < rhs->ip;
}


// CIPRateLimit::~CIPRateLimit  @ 000b5450
/* DWARF original prototype: void ~CIPRateLimit(CIPRateLimit * this, int __in_chrg) */

void __thiscall CIPRateLimit::~CIPRateLimit(CIPRateLimit *this,int __in_chrg)

{
  Node_t *__ptr;
  
  if ((-1 < (this->m_IPTree).m_Elements.m_GrowSize) &&
     (__ptr = (this->m_IPTree).m_Elements.m_pMemory, __ptr != (Node_t *)0x0)) {
    free(__ptr);
    return;
  }
  return;
}


// CInitTracker::CInitTracker  @ 000b3440
/* DWARF original prototype: void CInitTracker(CInitTracker * this) */

void __thiscall CInitTracker::CInitTracker(CInitTracker *this)

{
  this->m_Funcs[0].m_Memory.m_pMemory = (InitFunc **)0x0;
  this->m_Funcs[0].m_Memory.m_NumAllocated = 0;
  this->m_Funcs[0].m_Memory.m_GrowSize = 0;
  this->m_Funcs[0].m_Size = 0;
  this->m_Funcs[1].m_Memory.m_pMemory = (InitFunc **)0x0;
  this->m_Funcs[1].m_Memory.m_NumAllocated = 0;
  this->m_Funcs[1].m_Memory.m_GrowSize = 0;
  this->m_Funcs[1].m_Size = 0;
  this->m_Funcs[2].m_Memory.m_pMemory = (InitFunc **)0x0;
  this->m_Funcs[2].m_Memory.m_NumAllocated = 0;
  this->m_Funcs[2].m_Memory.m_GrowSize = 0;
  this->m_Funcs[2].m_Size = 0;
  this->m_Funcs[3].m_Memory.m_pMemory = (InitFunc **)0x0;
  this->m_Funcs[3].m_Memory.m_NumAllocated = 0;
  this->m_Funcs[3].m_Memory.m_GrowSize = 0;
  this->m_Funcs[3].m_Size = 0;
                    /* Unresolved local var: int l@[???] */
  this->m_nNumFuncs[0] = 0;
  this->m_nNumFuncs[1] = 0;
  this->m_nNumFuncs[2] = 0;
  this->m_nNumFuncs[3] = 0;
  return;
}


// CInitTracker::Init  @ 000b34d0
/* DWARF original prototype: void Init(CInitTracker * this, char * init, char * shutdown, int
   listnum) */

void __thiscall CInitTracker::Init(CInitTracker *this,char *init,char *shutdown,int listnum)

{
  CUtlVector<CInitTracker::InitFunc*> *pCVar1;
  InitFunc *pIVar2;
  InitFunc **ppIVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  bool bVar8;
  int local_20;
  
                    /* Unresolved local var: InitFunc * f@[???] */
  pIVar2 = operator_new(0x24);
  pIVar2->referencecount = 1;
  pIVar2->warningprinted = false;
  *(undefined4 *)&pIVar2->inittime = 0;
  pIVar2->initname = init;
  *(undefined4 *)((int)&pIVar2->inittime + 4) = 0;
  *(undefined4 *)&pIVar2->shutdowntime = 0;
  *(undefined4 *)((int)&pIVar2->shutdowntime + 4) = 0;
  pIVar2->shutdownname = shutdown;
  piVar6 = this->m_nNumFuncs + listnum;
  pCVar1 = this->m_Funcs + listnum;
  iVar4 = this->m_Funcs[listnum].m_Size;
  iVar7 = (pCVar1->m_Memory).m_NumAllocated;
  pIVar2->sequence = *piVar6;
  iVar5 = iVar4 + 1;
  if (iVar5 <= iVar7) goto LAB_000b35bd;
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
  iVar7 = iVar5 - iVar7;
  local_20 = (pCVar1->m_Memory).m_GrowSize;
  if (iVar7 < local_20) {
    if ((0 < local_20) || (local_20 != 0)) goto LAB_000b3576;
    iVar5 = this->m_Funcs[listnum].m_Memory.m_NumAllocated;
    local_20 = 1;
    if (iVar5 != 0) {
      local_20 = iVar5;
    }
    local_20 = local_20 + iVar5;
    this->m_Funcs[listnum].m_Memory.m_NumAllocated = local_20;
  }
  else {
                    /* Unresolved local var: int growSize@[???] */
    bVar8 = local_20 < 0;
    local_20 = iVar7;
    if (bVar8) goto LAB_000b35bd;
LAB_000b3576:
    local_20 = local_20 + this->m_Funcs[listnum].m_Memory.m_NumAllocated;
    this->m_Funcs[listnum].m_Memory.m_NumAllocated = local_20;
  }
                    /* Unresolved local var: int growSize@[???] */
  ppIVar3 = this->m_Funcs[listnum].m_Memory.m_pMemory;
  if (ppIVar3 == (InitFunc **)0x0) {
    ppIVar3 = malloc(local_20 << 2);
    this->m_Funcs[listnum].m_Memory.m_pMemory = ppIVar3;
    iVar4 = this->m_Funcs[listnum].m_Size;
    iVar5 = iVar4 + 1;
  }
  else {
    ppIVar3 = realloc(ppIVar3,local_20 << 2);
    this->m_Funcs[listnum].m_Memory.m_pMemory = ppIVar3;
    iVar4 = this->m_Funcs[listnum].m_Size;
    iVar5 = iVar4 + 1;
  }
LAB_000b35bd:
                    /* Unresolved local var: int numToMove@[???] */
  this->m_Funcs[listnum].m_Size = iVar5;
  if (0 < iVar4) {
    ppIVar3 = (pCVar1->m_Memory).m_pMemory;
    memmove(ppIVar3 + 1,ppIVar3,iVar4 << 2);
  }
  ppIVar3 = (pCVar1->m_Memory).m_pMemory;
  if (ppIVar3 != (InitFunc **)0x0) {
    *ppIVar3 = pIVar2;
  }
  *piVar6 = *piVar6 + 1;
  return;
}


// CInitTracker::Shutdown  @ 000b3670
/* DWARF original prototype: void Shutdown(CInitTracker * this, char * shutdown, int listnum) */

void __thiscall CInitTracker::Shutdown(CInitTracker *this,char *shutdown,int listnum)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  InitFunc **ppIVar4;
  int iVar5;
  InitFunc *pIVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: InitFunc * f@[???] */
  iVar5 = this->m_nNumFuncs[listnum];
  if (iVar5 == 0) {
    Sys_Printf("Mismatched shutdown function %s\n");
    return;
  }
  if (0 < iVar5) {
    ppIVar4 = this->m_Funcs[listnum].m_Memory.m_pMemory;
    pIVar6 = *ppIVar4;
    if (pIVar6->referencecount == 0) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        if (iVar5 == iVar2) {
          if (pIVar6 != (InitFunc *)0x0) goto LAB_000b36d2;
          goto LAB_000b36d9;
        }
        pIVar6 = ppIVar4[iVar2];
      } while (pIVar6->referencecount == 0);
    }
    if (pIVar6 != (InitFunc *)0x0) {
      iVar2 = strcasecmp(pIVar6->shutdownname,shutdown);
      if ((iVar2 != 0) && (pIVar6->warningprinted == false)) {
        pIVar6->warningprinted = true;
        iVar5 = this->m_nNumFuncs[listnum];
        if (iVar5 < 1) goto LAB_000b3750;
      }
    }
LAB_000b36d2:
    ppIVar4 = this->m_Funcs[listnum].m_Memory.m_pMemory;
LAB_000b36d9:
    iVar2 = 0;
    do {
                    /* Unresolved local var: InitFunc * f@[???] */
      pIVar6 = ppIVar4[iVar2];
      iVar3 = strcasecmp(pIVar6->shutdownname,shutdown);
      if (iVar3 == 0) {
        piVar1 = &pIVar6->referencecount;
        *piVar1 = *piVar1 + -1;
        return;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar5);
  }
LAB_000b3750:
  Sys_Printf("Shutdown function %s not in list!!!\n");
  return;
}


// CInitTracker::~CInitTracker  @ 000b3360
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void ~CInitTracker(CInitTracker * this, int __in_chrg) */

void __thiscall CInitTracker::~CInitTracker(CInitTracker *this,int __in_chrg)

{
  CUtlVector<CInitTracker::InitFunc*> *pCVar1;
  InitFunc *pIVar2;
  InitFunc **ppIVar3;
  CUtlVector<CInitTracker::InitFunc*> *pCVar4;
  int iVar5;
  CUtlVector<CInitTracker::InitFunc*> *pCVar6;
  CInitTracker *pCVar7;
  
  pCVar1 = this->m_Funcs;
  pCVar6 = pCVar1;
  pCVar7 = this;
  do {
                    /* Unresolved local var: int l@[???]
                       Unresolved local var: int i@[???] */
    iVar5 = 0;
    if (0 < pCVar7->m_nNumFuncs[0]) {
      do {
        while (pIVar2 = (pCVar6->m_Memory).m_pMemory[iVar5], pIVar2->referencecount != 0) {
          iVar5 = iVar5 + 1;
          Sys_Printf("Missing shutdown function for %s : %s\n",pIVar2->initname,pIVar2->shutdownname
                    );
          operator_delete(pIVar2);
          if (pCVar7->m_nNumFuncs[0] <= iVar5) goto LAB_000b33c8;
        }
                    /* Unresolved local var: InitFunc * f@[???] */
        iVar5 = iVar5 + 1;
        operator_delete(pIVar2);
      } while (iVar5 < pCVar7->m_nNumFuncs[0]);
    }
LAB_000b33c8:
    pCVar6->m_Size = 0;
    pCVar6 = pCVar6 + 1;
    pCVar7->m_nNumFuncs[0] = 0;
    pCVar7 = (CInitTracker *)(pCVar7->m_nNumFuncs + 1);
    if ((CInitTracker *)pCVar6 == this + 1) {
      if (pCVar1 != (CUtlVector<CInitTracker::InitFunc*> *)0x0) {
        while (pCVar4 = pCVar6, pCVar1 != pCVar4) {
          pCVar6 = pCVar4 + -1;
          iVar5 = pCVar4[-1].m_Memory.m_GrowSize;
          pCVar4[-1].m_Size = 0;
          if (-1 < iVar5) {
            ppIVar3 = (pCVar6->m_Memory).m_pMemory;
            if (ppIVar3 != (InitFunc **)0x0) {
              free(ppIVar3);
              (pCVar6->m_Memory).m_pMemory = (InitFunc **)0x0;
            }
            iVar5 = pCVar4[-1].m_Memory.m_GrowSize;
            pCVar4[-1].m_Memory.m_NumAllocated = 0;
            if ((-1 < iVar5) &&
               (ppIVar3 = (pCVar6->m_Memory).m_pMemory, ppIVar3 != (InitFunc **)0x0)) {
              free(ppIVar3);
            }
          }
        }
      }
      return;
    }
  } while( true );
}


// CRegistry::CRegistry  @ 000c5730
/* DWARF original prototype: void CRegistry(CRegistry * this) */

void __thiscall CRegistry::CRegistry(CRegistry *this)

{
  (this->super_IRegistry)._vptr_IRegistry = (_func_int_varargs **)&PTR_Shutdown_000debe8;
  this->m_bValid = false;
  this->m_hKey = 0;
  return;
}


// CRegistry::ReadInt  @ 000c56d0
/* DWARF original prototype: int ReadInt(CRegistry * this, char * key, int defaultValue) */

int __thiscall CRegistry::ReadInt(CRegistry *this,char *key,int defaultValue)

{
  return defaultValue;
}


// CRegistry::ReadString  @ 000c56f0
/* DWARF original prototype: char * ReadString(CRegistry * this, char * key, char * defaultValue) */

char * __thiscall CRegistry::ReadString(CRegistry *this,char *key,char *defaultValue)

{
  return defaultValue;
}


// CRegistry::Shutdown  @ 000c5710
/* DWARF original prototype: void Shutdown(CRegistry * this) */

void __thiscall CRegistry::Shutdown(CRegistry *this)

{
  return;
}


// CRegistry::WriteInt  @ 000c56e0
/* DWARF original prototype: void WriteInt(CRegistry * this, char * key, int value) */

void __thiscall CRegistry::WriteInt(CRegistry *this,char *key,int value)

{
  return;
}


// CRegistry::WriteString  @ 000c5700
/* DWARF original prototype: void WriteString(CRegistry * this, char * key, char * value) */

void __thiscall CRegistry::WriteString(CRegistry *this,char *key,char *value)

{
  return;
}


// CRegistry::~CRegistry  @ 000c56c0
/* DWARF original prototype: void ~CRegistry(CRegistry * this, int __in_chrg) */

void __thiscall CRegistry::~CRegistry(CRegistry *this,int __in_chrg)

{
  return;
}


// CRegistry::~CRegistry  @ 000c5720
/* DWARF original prototype: void ~CRegistry(CRegistry * this, int __in_chrg) */

void __thiscall CRegistry::~CRegistry(CRegistry *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// CServerRemoteAccess::CServerRemoteAccess  @ 000b3b10
/* DWARF original prototype: void CServerRemoteAccess(CServerRemoteAccess * this) */

void __thiscall CServerRemoteAccess::CServerRemoteAccess(CServerRemoteAccess *this)

{
  (this->super_IGameServerData).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__CServerRemoteAccess_000dd08c;
  (this->m_ResponsePackets).m_Memory.m_pMemory = (ListElem_t *)0x0;
  (this->m_ResponsePackets).m_Memory.m_NumAllocated = 0;
  (this->m_ResponsePackets).m_Memory.m_GrowSize = 0;
  (this->m_ResponsePackets).m_Head = -1;
  (this->m_ResponsePackets).m_Tail = -1;
  (this->m_ResponsePackets).m_FirstFree = -1;
  (this->m_ResponsePackets).m_TotalElements = 0;
  (this->m_ResponsePackets).m_ElementCount = 0;
  (this->m_ResponsePackets).m_pElements = (ListElem_t *)0x0;
  this->m_iBytesSent = 0;
  this->m_iBytesReceived = 0;
  return;
}


// CServerRemoteAccess::ExecCommand  @ 000b3cb0
/* DWARF original prototype: void ExecCommand(CServerRemoteAccess * this, char * cmdString) */

void __thiscall CServerRemoteAccess::ExecCommand(CServerRemoteAccess *this,char *cmdString)

{
  Cbuf_AddText(cmdString);
  Cbuf_AddText("\n");
  Cbuf_Execute();
  return;
}


// CServerRemoteAccess::GetMapList  @ 000b40d0
/* DWARF original prototype: void GetMapList(CServerRemoteAccess * this, CUtlBuffer * value) */

void __thiscall CServerRemoteAccess::GetMapList(CServerRemoteAccess *this,CUtlBuffer *value)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  int in_GS_OFFSET;
  char local_2060 [64];
  char local_2020 [4096];
  char local_1020 [4096];
  int local_20;
  
                    /* Unresolved local var: char[64] mapwild@[???]
                       Unresolved local var: char * findfn@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  builtin_strncpy(local_2060,"maps/*.bsp",0xb);
  pcVar2 = Sys_FindFirst(local_2060,(char *)0x0);
  if (pcVar2 != (char *)0x0) {
    do {
                    /* Unresolved local var: char[4096] curDir@[???] */
      __snprintf_chk(local_2020,0x1000,1,0x1000,"maps/%s",pcVar2);
      FS_GetLocalPath(local_2020,local_2020,0x1000);
      pcVar3 = strstr(local_2020,com_gamedir);
      if (pcVar3 != (char *)0x0) {
                    /* Unresolved local var: char[4096] mapName@[???]
                       Unresolved local var: char * extension@[???] */
        __strcpy_chk(local_1020,pcVar2,0x1000);
        pcVar2 = strstr(local_1020,".bsp");
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
        CUtlBuffer::PutString(value,local_1020);
        CUtlBuffer::PutString(value,"\n");
      }
      pcVar2 = Sys_FindNext((char *)0x0);
    } while (pcVar2 != (char *)0x0);
  }
  Sys_FindClose();
  if ((value->m_Flags & 1) == 0) {
    bVar1 = CUtlBuffer::CheckPut(value,1);
    if (bVar1) {
      (value->m_Memory).m_pMemory[value->m_Put] = '\0';
      value->m_Put = value->m_Put + 1;
    }
  }
  else {
    CUtlBuffer::Printf(value,"%c",0);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CServerRemoteAccess::GetPlayerList  @ 000b3f50
/* DWARF original prototype: void GetPlayerList(CServerRemoteAccess * this, CUtlBuffer * value) */

void __thiscall CServerRemoteAccess::GetPlayerList(CServerRemoteAccess *this,CUtlBuffer *value)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  bool bVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  client_s *pcVar10;
  int iVar11;
  
                    /* Unresolved local var: client_t.conflict * client@[???] */
  iVar11 = 0;
                    /* Unresolved local var: int i@[???] */
  iVar7 = svs.maxclients;
  pcVar10 = svs.clients;
  if (0 < svs.maxclients) {
    do {
      while ((pcVar10->active == false || (pcVar10->name[0] == '\0'))) {
        iVar11 = iVar11 + 1;
        pcVar10 = pcVar10 + 1;
        if (iVar7 <= iVar11) goto LAB_000b4080;
      }
      iVar11 = iVar11 + 1;
      dVar5 = realtime - (double)(pcVar10->netchan).connect_time;
      fVar2 = (pcVar10->edict->v).frags;
      fVar3 = pcVar10->packet_loss;
      fVar4 = pcVar10->latency;
      pcVar8 = NET_AdrToString((pcVar10->netchan).remote_address);
      pcVar9 = SV_GetIDString(&pcVar10->network_userid);
      pcVar1 = pcVar10->name;
      pcVar10 = pcVar10 + 1;
      CUtlBuffer::Printf(value,"\"%s\" %s %s %d %d %d %d\n",pcVar1,pcVar9,pcVar8,
                         (int)(fVar4 * 1000.0),(int)fVar3,(int)fVar2,(int)dVar5);
      iVar7 = svs.maxclients;
    } while (iVar11 < svs.maxclients);
  }
LAB_000b4080:
  if ((value->m_Flags & 1) != 0) {
    CUtlBuffer::Printf(value,"%c",0);
    return;
  }
  bVar6 = CUtlBuffer::CheckPut(value,1);
  if (bVar6) {
    (value->m_Memory).m_pMemory[value->m_Put] = '\0';
    value->m_Put = value->m_Put + 1;
  }
  return;
}


// CServerRemoteAccess::GetUserBanList  @ 000b3e30
/* DWARF original prototype: void GetUserBanList(CServerRemoteAccess * this, CUtlBuffer * value) */

void __thiscall CServerRemoteAccess::GetUserBanList(CServerRemoteAccess *this,CUtlBuffer *value)

{
  float fVar1;
  uint uVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  userfilter_t *id;
  uint *puVar6;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < numuserfilters) {
    iVar5 = 0;
    id = userfilters;
    do {
      fVar1 = id->banTime;
      iVar5 = iVar5 + 1;
      pcVar4 = SV_GetIDString(&id->userid);
      CUtlBuffer::Printf(value,"%i %s : %.3f min\n",iVar5,pcVar4,(double)fVar1);
      id = id + 1;
    } while (iVar5 < numuserfilters);
  }
  if (0 < numipfilters) {
    iVar5 = 0;
    puVar6 = &ipfilters[0].compare;
    do {
                    /* Unresolved local var: char[4] b@[???] */
      uVar2 = *puVar6;
      iVar5 = iVar5 + 1;
      CUtlBuffer::Printf(value,"%i %i.%i.%i.%i : %.3f min\n",numuserfilters + iVar5,(int)(char)uVar2
                         ,(int)(char)(uVar2 >> 8),(int)(uVar2 << 8) >> 0x18,(int)uVar2 >> 0x18,
                         (double)(float)puVar6[2]);
      puVar6 = puVar6 + 4;
    } while (iVar5 < numipfilters);
  }
  if ((value->m_Flags & 1) != 0) {
    CUtlBuffer::Printf(value,"%c",0);
    return;
  }
  bVar3 = CUtlBuffer::CheckPut(value,1);
  if (bVar3) {
    (value->m_Memory).m_pMemory[value->m_Put] = '\0';
    value->m_Put = value->m_Put + 1;
  }
  return;
}


// CServerRemoteAccess::LookupStringValue  @ 000b3ce0
/* DWARF original prototype: char * LookupStringValue(CServerRemoteAccess * this, char * variable)
    */

char * __thiscall CServerRemoteAccess::LookupStringValue(CServerRemoteAccess *this,char *variable)

{
  cvar_t *pcVar1;
  int iVar2;
  client_s *pcVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: cvar_t * var@[???] */
  pcVar1 = Cvar_FindVar(variable);
  if (pcVar1 == (cvar_t *)0x0) {
    iVar2 = strcasecmp(variable,"map");
    if (iVar2 == 0) {
      pcVar4 = sv.name;
    }
    else {
                    /* Unresolved local var: cvar_t * var@[???] */
      iVar2 = strcasecmp(variable,"playercount");
      if (iVar2 == 0) {
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: int i@[???] */
        if (svs.maxclients < 1) {
          iVar2 = 0;
        }
        else {
          iVar2 = 0;
          pcVar3 = svs.clients;
          do {
            if (((pcVar3->active != false) || (pcVar3->spawned != false)) ||
               (pcVar3->connected != false)) {
              iVar2 = iVar2 + 1;
            }
            pcVar3 = pcVar3 + 1;
          } while (pcVar3 != svs.clients + svs.maxclients);
        }
      }
      else {
        iVar5 = strcasecmp(variable,"maxplayers");
        iVar2 = svs.maxclients;
        if (iVar5 != 0) {
          iVar2 = strcasecmp(variable,"gamedescription");
          if (iVar2 != 0) {
            return (char *)0x0;
          }
                    /* WARNING: Could not recover jumptable at 0x000b3dfe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          pcVar4 = (*gEntityInterface.pfnGetGameDescription)();
          return pcVar4;
        }
      }
      __snprintf_chk(LookupStringValue::s_ReturnBuf,0x1f,1,0x20,&DAT_000d153e,iVar2);
      pcVar4 = LookupStringValue::s_ReturnBuf;
    }
  }
  else {
    pcVar4 = pcVar1->string;
  }
  return pcVar4;
}


// CServerRemoteAccess::LookupValue  @ 000b4270
/* DWARF original prototype: bool LookupValue(CServerRemoteAccess * this, char * variable,
   CUtlBuffer * value) */

bool __thiscall
CServerRemoteAccess::LookupValue(CServerRemoteAccess *this,char *variable,CUtlBuffer *value)

{
  netadr_t a;
  bool bVar1;
  bool bVar2;
  cvar_t *pcVar3;
  int iVar4;
  int iVar5;
  byte *pString;
  client_s *pcVar6;
  long lVar7;
  char *pString_00;
  int in_GS_OFFSET;
  double dVar8;
  int local_214;
  char local_210 [512];
  int local_10;
  
                    /* Unresolved local var: char * strval@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: cvar_t * var@[???] */
  pcVar3 = Cvar_FindVar(variable);
  if (pcVar3 == (cvar_t *)0x0) {
    iVar5 = strcasecmp(variable,"map");
    if (iVar5 == 0) {
      pString_00 = sv.name;
      goto LAB_000b42b0;
    }
    iVar5 = strcasecmp(variable,"playercount");
    if (iVar5 != 0) {
                    /* Unresolved local var: cvar_t * var@[???] */
      iVar4 = strcasecmp(variable,"maxplayers");
      iVar5 = svs.maxclients;
      if (iVar4 == 0) goto LAB_000b454e;
      iVar5 = strcasecmp(variable,"gamedescription");
      if (iVar5 == 0) {
        pString_00 = (*gEntityInterface.pfnGetGameDescription)();
        goto LAB_000b42b0;
      }
      goto LAB_000b43a0;
    }
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: int i@[???] */
    if (svs.maxclients < 1) {
      iVar5 = 0;
    }
    else {
      iVar5 = 0;
      pcVar6 = svs.clients;
      do {
        if (((pcVar6->active != false) || (pcVar6->spawned != false)) ||
           (pcVar6->connected != false)) {
          iVar5 = iVar5 + 1;
        }
        pcVar6 = pcVar6 + 1;
      } while (pcVar6 != svs.clients + svs.maxclients);
    }
LAB_000b454e:
    __snprintf_chk(LookupStringValue::s_ReturnBuf,0x1f,1,0x20,&DAT_000d153e,iVar5);
    pString_00 = LookupStringValue::s_ReturnBuf;
LAB_000b42b8:
                    /* Unresolved local var: char * strval@[???] */
    CUtlBuffer::PutString(value,pString_00);
LAB_000b42c4:
    if ((value->m_Flags & 1) == 0) {
      bVar1 = CUtlBuffer::CheckPut(value,1);
      if (bVar1) {
        (value->m_Memory).m_pMemory[value->m_Put] = '\0';
        value->m_Put = value->m_Put + 1;
        bVar1 = true;
        goto LAB_000b42e5;
      }
    }
    else {
LAB_000b4340:
      CUtlBuffer::Printf(value,"%c",0);
    }
  }
  else {
    pString_00 = pcVar3->string;
LAB_000b42b0:
    if (pString_00 != (char *)0x0) goto LAB_000b42b8;
LAB_000b43a0:
    iVar5 = strcasecmp(variable,"stats");
    if (iVar5 == 0) {
                    /* Unresolved local var: char[512] stats@[???] */
      GetStatsString(local_210,0x200);
      CUtlBuffer::PutString(value,local_210);
      if ((value->m_Flags & 1) == 0) {
        bVar1 = CUtlBuffer::CheckPut(value,1);
        if (bVar1) {
          (value->m_Memory).m_pMemory[value->m_Put] = '\0';
          value->m_Put = value->m_Put + 1;
        }
        goto LAB_000b42e3;
      }
      goto LAB_000b4340;
    }
    iVar5 = strcasecmp(variable,"banlist");
    if (iVar5 != 0) {
      iVar5 = strcasecmp(variable,"playerlist");
      if (iVar5 == 0) {
        GetPlayerList(this,value);
        bVar1 = true;
        goto LAB_000b42e5;
      }
      iVar5 = strcasecmp(variable,"maplist");
      if (iVar5 == 0) {
        GetMapList(this,value);
        bVar1 = true;
        goto LAB_000b42e5;
      }
      iVar5 = strcasecmp(variable,"uptime");
      if (iVar5 != 0) {
        iVar5 = strcasecmp(variable,"ipaddress");
        if (iVar5 == 0) {
          a.ip[0] = net_local_adr.ip[0];
          a.ip[1] = net_local_adr.ip[1];
          a.ip[2] = net_local_adr.ip[2];
          a.ip[3] = net_local_adr.ip[3];
          a.type = net_local_adr.type;
          a.ipx[0] = net_local_adr.ipx[0];
          a.ipx[1] = net_local_adr.ipx[1];
          a.ipx[2] = net_local_adr.ipx[2];
          a.ipx[3] = net_local_adr.ipx[3];
          a.ipx[4] = net_local_adr.ipx[4];
          a.ipx[5] = net_local_adr.ipx[5];
          a.ipx[6] = net_local_adr.ipx[6];
          a.ipx[7] = net_local_adr.ipx[7];
          a.ipx[8] = net_local_adr.ipx[8];
          a.ipx[9] = net_local_adr.ipx[9];
          a.port = net_local_adr.port;
          pString_00 = NET_AdrToString(a);
          goto LAB_000b42b8;
        }
        iVar5 = strcasecmp(variable,"mapcycle");
        if (iVar5 != 0) {
          if ((value->m_Flags & 1) == 0) {
            bVar2 = CUtlBuffer::CheckPut(value,1);
            bVar1 = false;
            if (bVar2) {
              (value->m_Memory).m_pMemory[value->m_Put] = '\0';
              bVar1 = false;
              value->m_Put = value->m_Put + 1;
            }
          }
          else {
            CUtlBuffer::Printf(value,"%c",0);
            bVar1 = false;
          }
          goto LAB_000b42e5;
        }
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: void * mapcyclelist@[???] */
        local_214 = 0;
        pString = COM_LoadFileForMe(mapcyclefile.string,&local_214);
        if ((pString != (byte *)0x0) && (local_214 != 0)) {
          CUtlBuffer::PutString(value,(char *)pString);
          if ((value->m_Flags & 1) == 0) {
            bVar1 = CUtlBuffer::CheckPut(value,1);
            if (bVar1) {
              (value->m_Memory).m_pMemory[value->m_Put] = '\0';
              value->m_Put = value->m_Put + 1;
            }
          }
          else {
            CUtlBuffer::Printf(value,"%c",0);
          }
          COM_FreeFile(pString);
        }
        goto LAB_000b42e3;
      }
                    /* Unresolved local var: int timeSeconds@[???] */
      dVar8 = Sys_FloatTime();
      lVar7 = Host_GetStartTime();
      if ((value->m_Flags & 1) == 0) {
        bVar1 = CUtlBuffer::CheckPut(value,4);
        if (bVar1) {
          *(int *)((value->m_Memory).m_pMemory + value->m_Put) = (int)(dVar8 - (double)lVar7);
          value->m_Put = value->m_Put + 4;
        }
      }
      else {
        CUtlBuffer::Printf(value,"%d",(int)(dVar8 - (double)lVar7));
      }
      goto LAB_000b42c4;
    }
    GetUserBanList(this,value);
  }
LAB_000b42e3:
  bVar1 = true;
LAB_000b42e5:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar1;
}


// CServerRemoteAccess::ReadDataResponse  @ 000b3960
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int ReadDataResponse(CServerRemoteAccess * this, void * buffer, int
   bufferSize) */

int __thiscall
CServerRemoteAccess::ReadDataResponse(CServerRemoteAccess *this,void *buffer,int bufferSize)

{
  int *piVar1;
  uchar uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  ListElem_t *pLVar8;
  uint uVar9;
  uchar *puVar10;
  ListElem_t *pLVar11;
  uchar *puVar12;
  uchar *puVar13;
  
                    /* Unresolved local var: int i@[???] */
  iVar4 = (this->m_ResponsePackets).m_Head;
  if ((iVar4 < (this->m_ResponsePackets).m_TotalElements) && (-1 < iVar4)) {
    pLVar11 = (this->m_ResponsePackets).m_Memory.m_pMemory;
    pLVar8 = pLVar11 + iVar4;
    if ((iVar4 != pLVar8->m_Previous) || (iVar4 == pLVar8->m_Next)) {
      uVar7 = (pLVar8->m_Element).packet.m_Put;
                    /* Unresolved local var: CUtlBuffer * response@[???]
                       Unresolved local var: int bytesToCopy@[???] */
      if (bufferSize < (int)uVar7) {
        uVar7 = 0;
      }
      else {
        puVar10 = (pLVar8->m_Element).packet.m_Memory.m_pMemory;
        uVar9 = uVar7;
        if (7 < uVar7) {
          puVar13 = buffer;
          if (((uint)buffer & 1) != 0) {
            uVar2 = *puVar10;
            puVar13 = (uchar *)((int)buffer + 1);
            puVar10 = puVar10 + 1;
            *(uchar *)buffer = uVar2;
            uVar9 = uVar7 - 1;
          }
          puVar12 = puVar13;
          if (((uint)puVar13 & 2) != 0) {
            uVar3 = *(undefined2 *)puVar10;
            puVar12 = puVar13 + 2;
            puVar10 = puVar10 + 2;
            uVar9 = uVar9 - 2;
            *(undefined2 *)puVar13 = uVar3;
          }
          buffer = puVar12;
          if (((uint)puVar12 & 4) != 0) {
            uVar6 = *(undefined4 *)puVar10;
            buffer = puVar12 + 4;
            puVar10 = puVar10 + 4;
            uVar9 = uVar9 - 4;
            *(undefined4 *)puVar12 = uVar6;
          }
        }
        for (; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(uchar *)buffer = *puVar10;
          puVar10 = puVar10 + 1;
          buffer = (uchar *)((int)buffer + 1);
        }
        pLVar11 = (this->m_ResponsePackets).m_Memory.m_pMemory;
        pLVar8 = pLVar11 + iVar4;
      }
      this->m_iBytesSent = this->m_iBytesSent + uVar7;
      if ((-1 < (pLVar8->m_Element).packet.m_Memory.m_GrowSize) &&
         (puVar10 = (pLVar8->m_Element).packet.m_Memory.m_pMemory, puVar10 != (uchar *)0x0)) {
        free(puVar10);
        pLVar11 = (this->m_ResponsePackets).m_Memory.m_pMemory;
      }
      if (iVar4 < (this->m_ResponsePackets).m_TotalElements) {
        pLVar8 = pLVar11 + iVar4;
        iVar5 = pLVar8->m_Previous;
        if (iVar4 != iVar5) {
                    /* Unresolved local var: ListElem_t * oldElem@[???] */
          if (iVar5 == -1) {
            (this->m_ResponsePackets).m_Head = pLVar8->m_Next;
          }
          else {
            pLVar11[iVar5].m_Next = pLVar8->m_Next;
          }
          if (pLVar8->m_Next == -1) {
            (this->m_ResponsePackets).m_Tail = pLVar8->m_Previous;
          }
          else {
            (this->m_ResponsePackets).m_Memory.m_pMemory[pLVar8->m_Next].m_Previous =
                 pLVar8->m_Previous;
          }
          pLVar8->m_Next = iVar4;
          pLVar8->m_Previous = iVar4;
          pLVar8 = (this->m_ResponsePackets).m_Memory.m_pMemory;
          piVar1 = &(this->m_ResponsePackets).m_ElementCount;
          *piVar1 = *piVar1 + -1;
          pLVar8 = pLVar8 + iVar4;
        }
      }
      else {
        pLVar8 = pLVar11 + iVar4;
      }
      pLVar8->m_Next = (this->m_ResponsePackets).m_FirstFree;
      (this->m_ResponsePackets).m_FirstFree = iVar4;
      return uVar7;
    }
  }
  return 0;
}


// CServerRemoteAccess::RequestValue  @ 000b47a0
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void RequestValue(CServerRemoteAccess * this, int requestID, char *
   variable) */

void __thiscall
CServerRemoteAccess::RequestValue(CServerRemoteAccess *this,int requestID,char *variable)

{
  int *piVar1;
  uchar *puVar2;
  bool bVar3;
  ListElem_t *this_00;
  int iVar4;
  size_t __size;
  ListElem_t *pLVar5;
  int iVar6;
  int iVar7;
  CUtlBuffer *pCVar8;
  int iVar9;
  CUtlBuffer local_34;
  
                    /* Unresolved local var: CUtlBuffer value@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CUtlBuffer * response@[???] */
  CUtlBuffer::CUtlBuffer(&local_34,0,0x100,true);
  LookupValue(this,variable,&local_34);
                    /* Unresolved local var: int newNode@[DW_OP_reg7(EDI)]
                       Unresolved local var: int elem@[???] */
  iVar9 = (this->m_ResponsePackets).m_FirstFree;
  if (iVar9 == -1) {
    iVar9 = (this->m_ResponsePackets).m_TotalElements;
    if (iVar9 == (this->m_ResponsePackets).m_Memory.m_NumAllocated) {
      iVar7 = (this->m_ResponsePackets).m_Memory.m_GrowSize;
                    /* Unresolved local var: int growSize@[???] */
      if ((iVar7 == 0) && (iVar7 = 1, iVar9 != 0)) {
        iVar7 = iVar9;
      }
                    /* Unresolved local var: int growSize@[???] */
      pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
      (this->m_ResponsePackets).m_Memory.m_NumAllocated = iVar7 + iVar9;
      __size = (iVar7 + iVar9) * 0x20;
      if (pLVar5 == (ListElem_t *)0x0) {
        pLVar5 = malloc(__size);
        (this->m_ResponsePackets).m_Memory.m_pMemory = pLVar5;
      }
      else {
        pLVar5 = realloc(pLVar5,__size);
        iVar9 = (this->m_ResponsePackets).m_TotalElements;
        (this->m_ResponsePackets).m_Memory.m_pMemory = pLVar5;
      }
    }
    else {
      pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
    }
    iVar7 = iVar9 * 0x20;
    (this->m_ResponsePackets).m_TotalElements = iVar9 + 1;
    pLVar5[iVar9].m_Previous = iVar9;
    pLVar5[iVar9].m_Next = iVar9;
    pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
    this_00 = pLVar5 + iVar9;
    if (this_00 == (ListElem_t *)0x0) goto LAB_000b4a73;
LAB_000b4818:
    CUtlBuffer::CUtlBuffer((CUtlBuffer *)this_00,0,0,false);
    pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
    iVar4 = (int)&(pLVar5->m_Element).packet.m_Memory.m_pMemory + iVar7;
  }
  else {
    pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
    iVar7 = iVar9 * 0x20;
    (this->m_ResponsePackets).m_FirstFree = pLVar5[iVar9].m_Next;
    pLVar5[iVar9].m_Previous = iVar9;
    pLVar5[iVar9].m_Next = iVar9;
    pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
    this_00 = pLVar5 + iVar9;
    if (this_00 != (ListElem_t *)0x0) goto LAB_000b4818;
LAB_000b4a73:
    iVar4 = 0;
  }
                    /* Unresolved local var: ListElem_t * newElem@[???] */
  (this->m_ResponsePackets).m_pElements = pLVar5;
  if ((((this->m_ResponsePackets).m_TotalElements <= iVar9) || (iVar9 < 0)) ||
     (iVar6 = *(int *)(iVar4 + 0x18), iVar9 == iVar6)) goto LAB_000b488d;
                    /* Unresolved local var: ListElem_t * oldElem@[???] */
  if (iVar6 == -1) {
    (this->m_ResponsePackets).m_Head = *(int *)(iVar4 + 0x1c);
    iVar6 = *(int *)(iVar4 + 0x1c);
    if (iVar6 == -1) goto LAB_000b4aa2;
LAB_000b4871:
    (this->m_ResponsePackets).m_Memory.m_pMemory[iVar6].m_Previous = *(int *)(iVar4 + 0x18);
  }
  else {
    pLVar5[iVar6].m_Next = *(int *)(iVar4 + 0x1c);
    iVar6 = *(int *)(iVar4 + 0x1c);
    if (iVar6 != -1) goto LAB_000b4871;
LAB_000b4aa2:
    (this->m_ResponsePackets).m_Tail = *(int *)(iVar4 + 0x18);
  }
  *(int *)(iVar4 + 0x1c) = iVar9;
  *(int *)(iVar4 + 0x18) = iVar9;
  pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
  piVar1 = &(this->m_ResponsePackets).m_ElementCount;
  *piVar1 = *piVar1 + -1;
  iVar4 = (int)&(pLVar5->m_Element).packet.m_Memory.m_pMemory + iVar7;
LAB_000b488d:
  *(undefined4 *)(iVar4 + 0x1c) = 0xffffffff;
  *(int *)(iVar4 + 0x18) = (this->m_ResponsePackets).m_Tail;
  (this->m_ResponsePackets).m_Tail = iVar9;
  if (*(int *)(iVar4 + 0x18) == -1) {
    (this->m_ResponsePackets).m_Head = iVar9;
  }
  else {
    (this->m_ResponsePackets).m_Memory.m_pMemory[*(int *)(iVar4 + 0x18)].m_Next = iVar9;
  }
  piVar1 = &(this->m_ResponsePackets).m_ElementCount;
  *piVar1 = *piVar1 + 1;
  pCVar8 = (CUtlBuffer *)
           ((int)&(((this->m_ResponsePackets).m_Memory.m_pMemory)->m_Element).packet.m_Memory.
                  m_pMemory + iVar7);
  if (pCVar8 == (CUtlBuffer *)0x0) {
    pCVar8 = (CUtlBuffer *)0x0;
  }
  else {
    CUtlBuffer::CUtlBuffer(pCVar8,0,0,false);
    pCVar8 = (CUtlBuffer *)
             ((int)&(((this->m_ResponsePackets).m_Memory.m_pMemory)->m_Element).packet.m_Memory.
                    m_pMemory + iVar7);
  }
  if ((pCVar8->m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut(pCVar8,4);
    if (bVar3) {
      *(int *)((pCVar8->m_Memory).m_pMemory + pCVar8->m_Put) = requestID;
      pCVar8->m_Put = pCVar8->m_Put + 4;
    }
  }
  else {
    CUtlBuffer::Printf(pCVar8,"%d",requestID);
  }
  if ((pCVar8->m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut(pCVar8,4);
    if (bVar3) {
      puVar2 = (pCVar8->m_Memory).m_pMemory + pCVar8->m_Put;
      puVar2[0] = '\0';
      puVar2[1] = '\0';
      puVar2[2] = '\0';
      puVar2[3] = '\0';
      pCVar8->m_Put = pCVar8->m_Put + 4;
    }
  }
  else {
    CUtlBuffer::Printf(pCVar8,"%d",0);
  }
  CUtlBuffer::PutString(pCVar8,variable);
  iVar9 = local_34.m_Put;
  if ((pCVar8->m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut(pCVar8,4);
    if (bVar3) {
      *(int *)((pCVar8->m_Memory).m_pMemory + pCVar8->m_Put) = iVar9;
      pCVar8->m_Put = pCVar8->m_Put + 4;
    }
  }
  else {
    CUtlBuffer::Printf(pCVar8,"%d",local_34.m_Put);
  }
  if (local_34.m_Put != 0) {
    CUtlBuffer::Put(pCVar8,local_34.m_Memory.m_pMemory,local_34.m_Put);
  }
  if ((-1 < local_34.m_Memory.m_GrowSize) && (local_34.m_Memory.m_pMemory != (uchar *)0x0)) {
    free(local_34.m_Memory.m_pMemory);
  }
  return;
}


// CServerRemoteAccess::SendMessageToAdminUI  @ 000b4da0
/* WARNING: Variable defined which should be unmapped: newNode */
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void SendMessageToAdminUI(CServerRemoteAccess * this, char * message)
    */

void __thiscall CServerRemoteAccess::SendMessageToAdminUI(CServerRemoteAccess *this,char *message)

{
  int *piVar1;
  uchar *puVar2;
  bool bVar3;
  ListElem_t *this_00;
  int iVar4;
  size_t __size;
  ListElem_t *pLVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  CUtlBuffer *pCVar9;
  int newNode;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CUtlBuffer * response@[???] */
                    /* Unresolved local var: int elem@[???] */
  iVar7 = (this->m_ResponsePackets).m_FirstFree;
  if (iVar7 == -1) {
    iVar7 = (this->m_ResponsePackets).m_TotalElements;
    if (iVar7 == (this->m_ResponsePackets).m_Memory.m_NumAllocated) {
      iVar8 = (this->m_ResponsePackets).m_Memory.m_GrowSize;
                    /* Unresolved local var: int growSize@[???] */
      if ((iVar8 == 0) && (iVar8 = 1, iVar7 != 0)) {
        iVar8 = iVar7;
      }
                    /* Unresolved local var: int growSize@[???] */
      pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
      (this->m_ResponsePackets).m_Memory.m_NumAllocated = iVar8 + iVar7;
      __size = (iVar8 + iVar7) * 0x20;
      if (pLVar5 == (ListElem_t *)0x0) {
        pLVar5 = malloc(__size);
        (this->m_ResponsePackets).m_Memory.m_pMemory = pLVar5;
      }
      else {
        pLVar5 = realloc(pLVar5,__size);
        iVar7 = (this->m_ResponsePackets).m_TotalElements;
        (this->m_ResponsePackets).m_Memory.m_pMemory = pLVar5;
      }
    }
    else {
      pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
    }
    iVar8 = iVar7 * 0x20;
    (this->m_ResponsePackets).m_TotalElements = iVar7 + 1;
    pLVar5[iVar7].m_Previous = iVar7;
    pLVar5[iVar7].m_Next = iVar7;
    pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
    this_00 = pLVar5 + iVar7;
    if (this_00 == (ListElem_t *)0x0) goto LAB_000b4f93;
LAB_000b4de2:
    CUtlBuffer::CUtlBuffer((CUtlBuffer *)this_00,0,0,false);
    pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
    iVar6 = (int)&(pLVar5->m_Element).packet.m_Memory.m_pMemory + iVar8;
  }
  else {
    pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
    iVar8 = iVar7 * 0x20;
    (this->m_ResponsePackets).m_FirstFree = pLVar5[iVar7].m_Next;
    pLVar5[iVar7].m_Previous = iVar7;
    pLVar5[iVar7].m_Next = iVar7;
    pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
    this_00 = pLVar5 + iVar7;
    if (this_00 != (ListElem_t *)0x0) goto LAB_000b4de2;
LAB_000b4f93:
    iVar6 = 0;
  }
                    /* Unresolved local var: ListElem_t * newElem@[???] */
  (this->m_ResponsePackets).m_pElements = pLVar5;
  if ((((this->m_ResponsePackets).m_TotalElements <= iVar7) || (iVar7 < 0)) ||
     (iVar4 = *(int *)(iVar6 + 0x18), iVar7 == iVar4)) goto LAB_000b4e57;
                    /* Unresolved local var: ListElem_t * oldElem@[???] */
  if (iVar4 == -1) {
    (this->m_ResponsePackets).m_Head = *(int *)(iVar6 + 0x1c);
    iVar4 = *(int *)(iVar6 + 0x1c);
    if (iVar4 == -1) goto LAB_000b4fc2;
LAB_000b4e3b:
    (this->m_ResponsePackets).m_Memory.m_pMemory[iVar4].m_Previous = *(int *)(iVar6 + 0x18);
  }
  else {
    pLVar5[iVar4].m_Next = *(int *)(iVar6 + 0x1c);
    iVar4 = *(int *)(iVar6 + 0x1c);
    if (iVar4 != -1) goto LAB_000b4e3b;
LAB_000b4fc2:
    (this->m_ResponsePackets).m_Tail = *(int *)(iVar6 + 0x18);
  }
  *(int *)(iVar6 + 0x1c) = iVar7;
  *(int *)(iVar6 + 0x18) = iVar7;
  pLVar5 = (this->m_ResponsePackets).m_Memory.m_pMemory;
  piVar1 = &(this->m_ResponsePackets).m_ElementCount;
  *piVar1 = *piVar1 + -1;
  iVar6 = (int)&(pLVar5->m_Element).packet.m_Memory.m_pMemory + iVar8;
LAB_000b4e57:
  *(undefined4 *)(iVar6 + 0x1c) = 0xffffffff;
  *(int *)(iVar6 + 0x18) = (this->m_ResponsePackets).m_Tail;
  (this->m_ResponsePackets).m_Tail = iVar7;
  if (*(int *)(iVar6 + 0x18) == -1) {
    (this->m_ResponsePackets).m_Head = iVar7;
  }
  else {
    (this->m_ResponsePackets).m_Memory.m_pMemory[*(int *)(iVar6 + 0x18)].m_Next = iVar7;
  }
  piVar1 = &(this->m_ResponsePackets).m_ElementCount;
  *piVar1 = *piVar1 + 1;
  pCVar9 = (CUtlBuffer *)
           ((int)&(((this->m_ResponsePackets).m_Memory.m_pMemory)->m_Element).packet.m_Memory.
                  m_pMemory + iVar8);
  if (pCVar9 == (CUtlBuffer *)0x0) {
    pCVar9 = (CUtlBuffer *)0x0;
  }
  else {
    CUtlBuffer::CUtlBuffer(pCVar9,0,0,false);
    pCVar9 = (CUtlBuffer *)
             ((int)&(((this->m_ResponsePackets).m_Memory.m_pMemory)->m_Element).packet.m_Memory.
                    m_pMemory + iVar8);
  }
  if ((pCVar9->m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut(pCVar9,4);
    if (bVar3) {
      puVar2 = (pCVar9->m_Memory).m_pMemory + pCVar9->m_Put;
      puVar2[0] = '\0';
      puVar2[1] = '\0';
      puVar2[2] = '\0';
      puVar2[3] = '\0';
      pCVar9->m_Put = pCVar9->m_Put + 4;
    }
  }
  else {
    CUtlBuffer::Printf(pCVar9,"%d",0);
  }
  if ((pCVar9->m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut(pCVar9,4);
    if (bVar3) {
      puVar2 = (pCVar9->m_Memory).m_pMemory + pCVar9->m_Put;
      puVar2[0] = '\x01';
      puVar2[1] = '\0';
      puVar2[2] = '\0';
      puVar2[3] = '\0';
      pCVar9->m_Put = pCVar9->m_Put + 4;
    }
  }
  else {
    CUtlBuffer::Printf(pCVar9,"%d",1);
  }
  CUtlBuffer::PutString(pCVar9,message);
  return;
}


// CServerRemoteAccess::SetValue  @ 000b3b70
/* DWARF original prototype: void SetValue(CServerRemoteAccess * this, char * variable, char *
   value) */

void __thiscall CServerRemoteAccess::SetValue(CServerRemoteAccess *this,char *variable,char *value)

{
  int iVar1;
  FileHandle_t file;
  size_t sVar2;
  cvar_t *var;
  
  iVar1 = strcasecmp(variable,"map");
  if (iVar1 == 0) {
    Cbuf_AddText("changelevel ");
    Cbuf_AddText(value);
    Cbuf_AddText("\n");
    Cbuf_Execute();
    return;
  }
  iVar1 = strcasecmp(variable,"mapcycle");
  if (iVar1 != 0) {
                    /* Unresolved local var: cvar_t * var@[???] */
    var = Cvar_FindVar(variable);
    if (var == (cvar_t *)0x0) {
      return;
    }
    Cvar_DirectSet(var,value);
    return;
  }
                    /* Unresolved local var: FileHandle_t f@[???] */
  file = FS_Open(mapcyclefile.string,"wt");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("Couldn\'t write to read-only file %s, using file _dev_mapcycle.txt instead.\n",
               mapcyclefile.string);
    Cvar_DirectSet(&mapcyclefile,"_temp_mapcycle.txt");
    file = FS_Open(mapcyclefile.string,"wt");
    if (file == (FileHandle_t)0x0) {
      return;
    }
  }
  sVar2 = strlen(value);
  FS_Write(value,sVar2 + 1,1,file);
  FS_Close(file);
  return;
}


// CServerRemoteAccess::WriteDataRequest  @ 000b4b30
/* DWARF original prototype: void WriteDataRequest(CServerRemoteAccess * this, void * buffer, int
   bufferSize) */

void __thiscall
CServerRemoteAccess::WriteDataRequest(CServerRemoteAccess *this,void *buffer,int bufferSize)

{
  int *piVar1;
  bool bVar2;
  int requestID;
  int in_GS_OFFSET;
  int local_340;
  int local_33c;
  CUtlBuffer local_338;
  char local_320 [256];
  char local_220 [512];
  int local_20;
  
                    /* Unresolved local var: CUtlBuffer cmd@[???]
                       Unresolved local var: int requestID@[???]
                       Unresolved local var: int requestType@[???] */
  this->m_iBytesReceived = this->m_iBytesReceived + bufferSize;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  CUtlBuffer::CUtlBuffer(&local_338,buffer,bufferSize,false);
                    /* Unresolved local var: int i@[???] */
  if ((local_338.m_Flags & 1) == 0) {
                    /* Unresolved local var: int i@[???] */
    bVar2 = CUtlBuffer::CheckGet(&local_338,4);
    requestID = 0;
    if (bVar2) {
      piVar1 = (int *)(local_338.m_Memory.m_pMemory + local_338.m_Get);
      local_338.m_Get = local_338.m_Get + 4;
      requestID = *piVar1;
    }
  }
  else {
    CUtlBuffer::Scanf(&local_338,"%d",&local_340);
    requestID = local_340;
  }
                    /* Unresolved local var: int i@[???] */
  if ((local_338.m_Flags & 1) == 0) {
                    /* Unresolved local var: int i@[???] */
    bVar2 = CUtlBuffer::CheckGet(&local_338,4);
    local_33c = 0;
    if (bVar2) {
      local_33c = *(int *)(local_338.m_Memory.m_pMemory + local_338.m_Get);
      local_338.m_Get = local_338.m_Get + 4;
    }
  }
  else {
    CUtlBuffer::Scanf(&local_338,"%d",&local_33c);
  }
  if (local_33c == 1) {
                    /* Unresolved local var: char[256] variable@[???]
                       Unresolved local var: char[256] value@[???] */
    CUtlBuffer::GetString(&local_338,local_320);
    CUtlBuffer::GetString(&local_338,local_220);
    SetValue(this,local_320,local_220);
  }
  else if (local_33c == 2) {
                    /* Unresolved local var: char[512] command@[???] */
    CUtlBuffer::GetString(&local_338,local_220);
    Cbuf_AddText(local_220);
    Cbuf_AddText("\n");
    Cbuf_Execute();
  }
  else if (local_33c == 0) {
                    /* Unresolved local var: char[256] variable@[???] */
    CUtlBuffer::GetString(&local_338,local_220);
    RequestValue(this,requestID,local_220);
  }
  if ((-1 < local_338.m_Memory.m_GrowSize) && (local_338.m_Memory.m_pMemory != (uchar *)0x0)) {
    free(local_338.m_Memory.m_pMemory);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CServerRemoteAccess::~CServerRemoteAccess  @ 000b5390
/* DWARF original prototype: void ~CServerRemoteAccess(CServerRemoteAccess * this, int __in_chrg) */

void __thiscall CServerRemoteAccess::~CServerRemoteAccess(CServerRemoteAccess *this,int __in_chrg)

{
  (this->super_IGameServerData).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__CServerRemoteAccess_000dd08c;
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::~CUtlLinkedList
            (&this->m_ResponsePackets,__in_chrg);
  return;
}


// CServerRemoteAccess::~CServerRemoteAccess  @ 000b53b0
/* DWARF original prototype: void ~CServerRemoteAccess(CServerRemoteAccess * this, int __in_chrg) */

void __thiscall CServerRemoteAccess::~CServerRemoteAccess(CServerRemoteAccess *this,int __in_chrg)

{
  int in_stack_ffffffe8;
  
  (this->super_IGameServerData).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__CServerRemoteAccess_000dd08c;
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::~CUtlLinkedList
            (&this->m_ResponsePackets,in_stack_ffffffe8);
  operator_delete(this);
  return;
}


// CSteam3Client::ActivateInputSet  @ 000bd120
/* DWARF original prototype: void ActivateInputSet(CSteam3Client * this, bool bInMenu) */

void __thiscall CSteam3Client::ActivateInputSet(CSteam3Client *this,bool bInMenu)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  
  piVar1 = (int *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
  if (*piVar1 != 0) {
                    /* Unresolved local var: char * pszHandleName@[???]
                       Unresolved local var: InputActionSetHandle_t nHandle@[???]
                       Unresolved local var: bool bIsMultiplayer@[???] */
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
    (**(code **)(*(int *)*puVar2 + 0x38))((int *)*puVar2,0xffffffff,0xffffffff);
    if (bInMenu) {
      puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
      uVar4 = (**(code **)(*(int *)*puVar2 + 0x24))((int *)*puVar2,"HL_MenuDefault");
      puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
      (**(code **)(*(int *)*puVar2 + 0x28))((int *)*puVar2,0xffffffff,0xffffffff,uVar4);
      Host_GetMaxClients();
      return;
    }
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
    uVar4 = (**(code **)(*(int *)*puVar2 + 0x24))((int *)*puVar2,"HL_GameDefault");
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
    (**(code **)(*(int *)*puVar2 + 0x28))((int *)*puVar2,0xffffffff,0xffffffff,uVar4);
    iVar3 = Host_GetMaxClients();
    if (1 < iVar3) {
                    /* Unresolved local var: InputActionSetHandle_t nLayerHandle@[???] */
      puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
      uVar4 = (**(code **)(*(int *)*puVar2 + 0x24))((int *)*puVar2,"HL_LayerMultiplayer");
      puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
      (**(code **)(*(int *)*puVar2 + 0x30))((int *)*puVar2,0xffffffff,0xffffffff,uVar4);
    }
  }
  return;
}


// CSteam3Client::CSteam3Client  @ 000bf6f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void CSteam3Client(CSteam3Client * this) */

void __thiscall CSteam3Client::CSteam3Client(CSteam3Client *this)

{
  (this->super_CSteam3).m_bLoggedOn = false;
  (this->super_CSteam3).m_bLogOnResult = false;
  (this->super_CSteam3).m_hSteamPipe = 0;
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Client_000de868;
  (this->m_CallbackClientGameServerDeny).super_CCallbackImpl<16>.super_CCallbackBase.
  m_nCallbackFlags = '\0';
  (this->m_CallbackClientGameServerDeny).super_CCallbackImpl<16>.super_CCallbackBase.m_iCallback = 0
  ;
  (this->m_CallbackClientGameServerDeny).super_CCallbackImpl<16>.super_CCallbackBase.
  _vptr_CCallbackBase = (_func_int_varargs **)&PTR_Run_000de790;
  (this->m_CallbackClientGameServerDeny).m_pObj = (CSteam3Client *)0x0;
  (this->m_CallbackClientGameServerDeny).m_Func.__pfn =
       (_func___thiscall_void_CSteam3Client_ptr_ClientGameServerDeny_t_ptr *)0x0;
  (this->m_CallbackClientGameServerDeny).m_Func.__delta = 0;
  if (this == (CSteam3Client *)0x0) {
    _DAT_00000044 = 0;
    _DAT_0000003c = &PTR_Run_000de7e4;
    _DAT_00000048 = 0;
    _DAT_0000004c = 0;
    DAT_00000028 = 0;
    _DAT_0000002c = 0;
    _DAT_00000024 = &PTR_Run_000de7c8;
    _DAT_00000030 = 0;
    _DAT_00000034 = 0;
    _DAT_00000038 = 0;
    DAT_00000040 = 0;
    _DAT_00000050 = 0;
  }
  else {
    (this->m_CallbackClientGameServerDeny).m_pObj = this;
    (this->m_CallbackClientGameServerDeny).m_Func.__pfn = OnClientGameServerDeny;
    SteamAPI_RegisterCallback(&this->m_CallbackClientGameServerDeny,0x71);
    (this->m_CallbackGameServerChangeRequested).super_CCallbackImpl<128>.super_CCallbackBase.
    m_nCallbackFlags = '\0';
    (this->m_CallbackGameServerChangeRequested).super_CCallbackImpl<128>.super_CCallbackBase.
    m_iCallback = 0;
    (this->m_CallbackGameServerChangeRequested).super_CCallbackImpl<128>.super_CCallbackBase.
    _vptr_CCallbackBase = (_func_int_varargs **)&PTR_Run_000de7c8;
    (this->m_CallbackGameServerChangeRequested).m_pObj = this;
    (this->m_CallbackGameServerChangeRequested).m_Func.__pfn = OnGameServerChangeRequested;
    (this->m_CallbackGameServerChangeRequested).m_Func.__delta = 0;
    SteamAPI_RegisterCallback(&this->m_CallbackGameServerChangeRequested,0x14c);
    (this->m_CallbackGameOverlayActivated).super_CCallbackImpl<8>.super_CCallbackBase.
    m_nCallbackFlags = '\0';
    (this->m_CallbackGameOverlayActivated).super_CCallbackImpl<8>.super_CCallbackBase.m_iCallback =
         0;
    (this->m_CallbackGameOverlayActivated).super_CCallbackImpl<8>.super_CCallbackBase.
    _vptr_CCallbackBase = (_func_int_varargs **)&PTR_Run_000de7e4;
    (this->m_CallbackGameOverlayActivated).m_pObj = this;
    (this->m_CallbackGameOverlayActivated).m_Func.__pfn = OnGameOverlayActivated;
    (this->m_CallbackGameOverlayActivated).m_Func.__delta = 0;
    SteamAPI_RegisterCallback(&this->m_CallbackGameOverlayActivated,0x14b);
  }
  (this->m_steamcallback_OnNewUrlLaunchParameters).super_CCallbackImpl<1>.super_CCallbackBase.
  m_nCallbackFlags = '\0';
  (this->m_steamcallback_OnNewUrlLaunchParameters).super_CCallbackImpl<1>.super_CCallbackBase.
  m_iCallback = 0;
  (this->m_steamcallback_OnNewUrlLaunchParameters).super_CCallbackImpl<1>.super_CCallbackBase.
  _vptr_CCallbackBase = (_func_int_varargs **)&PTR_Run_000de800;
  SteamAPI_RegisterCallback(&this->m_steamcallback_OnNewUrlLaunchParameters,0x3f6);
  (this->m_steamcallback_OnGameRichPresenceJoinRequested).super_CCallbackImpl<264>.
  super_CCallbackBase.m_nCallbackFlags = '\0';
  (this->m_steamcallback_OnGameRichPresenceJoinRequested).super_CCallbackImpl<264>.
  super_CCallbackBase.m_iCallback = 0;
  (this->m_steamcallback_OnGameRichPresenceJoinRequested).super_CCallbackImpl<264>.
  super_CCallbackBase._vptr_CCallbackBase = (_func_int_varargs **)&PTR_Run_000de838;
  SteamAPI_RegisterCallback(&this->m_steamcallback_OnGameRichPresenceJoinRequested,0x151);
  return;
}


// CSteam3Client::InitClient  @ 000bd640
/* DWARF original prototype: void InitClient(CSteam3Client * this) */

void __thiscall CSteam3Client::InitClient(CSteam3Client *this)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  FILE *__stream;
  
  if ((this->super_CSteam3).m_bLoggedOn != false) {
    return;
  }
  (this->super_CSteam3).m_bLoggedOn = true;
  unlink("steam_appid.txt");
  pcVar2 = getenv("SteamAppId");
  if (pcVar2 == (char *)0x0) {
                    /* Unresolved local var: int nAppID@[???] */
    iVar5 = GetGameAppID();
    if (0 < iVar5) {
                    /* Unresolved local var: FILE * f@[???] */
      __stream = fopen("steam_appid.txt","w+");
      if (__stream != (FILE *)0x0) {
        __fprintf_chk(__stream,1,"%d\n",iVar5);
        fclose(__stream);
      }
    }
  }
  cVar1 = SteamAPI_Init();
  if (cVar1 != '\0') {
    piVar3 = (int *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
    if (*piVar3 != 0) {
      puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
      (*(code *)**(undefined4 **)*puVar4)((undefined4 *)*puVar4,0);
    }
    (this->super_CSteam3).m_bLogOnResult = false;
    return;
  }
  Sys_Error("Failed to initalize authentication interface. Exiting...\n");
  return;
}


// CSteam3Client::InitiateGameConnection  @ 000bd300
/* DWARF original prototype: int InitiateGameConnection(CSteam3Client * this, void * pData, int
   cbMaxData, uint64 steamID, uint32 unIPServer, uint16 usPortServer, bool bSecure) */

int __thiscall
CSteam3Client::InitiateGameConnection
          (CSteam3Client *this,void *pData,int cbMaxData,uint64 steamID,uint32 unIPServer,
          uint16 usPortServer,bool bSecure)

{
  int iVar1;
  undefined2 uVar2;
  netadr_t adr;
  uint64 uVar3;
  short sVar4;
  int32 iVar5;
  undefined4 *puVar6;
  int iVar7;
  qboolean qVar8;
  int iVar9;
  uint16 auVar10 [1];
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  int in_GS_OFFSET;
  byte bVar14;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
                    /* Unresolved local var: netadr_t.conflict server_adr@[???] */
  bVar14 = 0;
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
  uVar11 = unIPServer >> 0x18 | (unIPServer & 0xff0000) >> 8 | (unIPServer & 0xff00) << 8 |
           unIPServer << 0x18;
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
  auVar10[0] = usPortServer >> 8 | usPortServer << 8;
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  iVar5 = (*BigLong)(uVar11);
  sVar4 = (*BigShort)(auVar10[0]);
  if ((g_nFakeIP == 0) ||
     (adr.ip[0] = (char)iVar5, adr.ip[1] = (char)((uint)iVar5 >> 8),
     adr.ip[2] = (char)((uint)iVar5 >> 0x10), adr.ip[3] = (char)((uint)iVar5 >> 0x18), adr.type = 3,
     adr.ipx._0_4_ = local_2c, adr.ipx._4_4_ = local_28, adr.ipx[8] = (undefined1)local_24,
     adr.ipx[9] = local_24._1_1_, adr.port = sVar4, qVar8 = NET_IsLocalAddress(adr), qVar8 == false)
     ) {
    if (uVar11 != g_nCurrentGameConnectionIP) goto LAB_000bd394;
LAB_000bd4ee:
    if (((g_nCurrentGameConnectionPort != auVar10[0]) || (steamID != g_currentGameConnectionSteamID)
        ) || (InitiateGameConnection::g_currentGameConnectionSecure != bSecure)) goto LAB_000bd394;
  }
  else {
    uVar11 = g_nFakeIP;
    auVar10[0] = g_arFakePorts[0];
    if (g_nFakeIP == g_nCurrentGameConnectionIP) goto LAB_000bd4ee;
LAB_000bd394:
    if ((g_nCurrentGameConnectionIP != 0) || (g_nCurrentGameConnectionPort != 0)) {
      puVar6 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar6 + 0x10))
                ((int *)*puVar6,g_nCurrentGameConnectionIP,g_nCurrentGameConnectionPort);
    }
    InitiateGameConnection::g_currentGameConnectionSecure = bSecure;
    g_nCurrentGameConnectionPort = auVar10[0];
    g_nCurrentGameConnectionIP = uVar11;
    g_currentGameConnectionSteamID = steamID;
    puVar6 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
    InitiateGameConnection::g_cbCurrentGameConnectionBlob =
         (**(code **)(*(int *)*puVar6 + 0xc))
                   ((int *)*puVar6,InitiateGameConnection::g_currentGameConnectionBlob,0x400,
                    g_currentGameConnectionSteamID,g_nCurrentGameConnectionIP,
                    g_nCurrentGameConnectionPort,
                    InitiateGameConnection::g_currentGameConnectionSecure);
  }
  iVar7 = InitiateGameConnection::g_cbCurrentGameConnectionBlob;
  if (cbMaxData < InitiateGameConnection::g_cbCurrentGameConnectionBlob) {
    iVar7 = 0;
    uVar3 = g_currentGameConnectionSteamID;
  }
  else {
    pcVar12 = InitiateGameConnection::g_currentGameConnectionBlob;
    iVar9 = InitiateGameConnection::g_cbCurrentGameConnectionBlob;
    if (7 < (uint)InitiateGameConnection::g_cbCurrentGameConnectionBlob) {
      pcVar13 = pData;
      if (((uint)pData & 1) != 0) {
        pcVar13 = (char *)((int)pData + 1);
        pcVar12 = InitiateGameConnection::g_currentGameConnectionBlob + 1;
        iVar9 = InitiateGameConnection::g_cbCurrentGameConnectionBlob + -1;
        *(char *)pData = InitiateGameConnection::g_currentGameConnectionBlob[0];
      }
      pData = pcVar13;
      if (((uint)pcVar13 & 2) != 0) {
        uVar2 = *(undefined2 *)pcVar12;
        pData = pcVar13 + 2;
        pcVar12 = pcVar12 + 2;
        iVar9 = iVar9 + -2;
        *(undefined2 *)pcVar13 = uVar2;
      }
      if (((uint)pData & 4) != 0) {
        *(undefined4 *)pData = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar13 = (char *)((int)pData + 4);
        for (iVar9 = iVar9 + -4; uVar3 = g_currentGameConnectionSteamID, iVar9 != 0;
            iVar9 = iVar9 + -1) {
          *pcVar13 = *pcVar12;
          pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
          pcVar13 = pcVar13 + (uint)bVar14 * -2 + 1;
        }
        goto LAB_000bd436;
      }
    }
    for (; uVar3 = g_currentGameConnectionSteamID, iVar9 != 0; iVar9 = iVar9 + -1) {
      *(char *)pData = *pcVar12;
      pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
      pData = (char *)((int)pData + (uint)bVar14 * -2 + 1);
    }
  }
LAB_000bd436:
  g_currentGameConnectionSteamID._4_4_ = (undefined4)(uVar3 >> 0x20);
  g_currentGameConnectionSteamID._0_4_ = (undefined4)uVar3;
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
    g_currentGameConnectionSteamID = uVar3;
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}


// CSteam3Client::OnClientGameServerDeny  @ 000b9f20
/* DWARF original prototype: void OnClientGameServerDeny(CSteam3Client * this,
   ClientGameServerDeny_t * pClientGameServerDeny) */

void __thiscall
CSteam3Client::OnClientGameServerDeny
          (CSteam3Client *this,ClientGameServerDeny_t *pClientGameServerDeny)

{
  COM_ExplainDisconnection(true,"Invalid server version, unable to connect.");
  CL_Disconnect();
  return;
}


// CSteam3Client::OnGameOverlayActivated  @ 000b9e80
/* DWARF original prototype: void OnGameOverlayActivated(CSteam3Client * this,
   GameOverlayActivated_t * pGameOverlayActivated) */

void __thiscall
CSteam3Client::OnGameOverlayActivated
          (CSteam3Client *this,GameOverlayActivated_t *pGameOverlayActivated)

{
  return;
}


// CSteam3Client::OnGameRichPresenceJoinRequested  @ 000bc830
/* DWARF original prototype: void OnGameRichPresenceJoinRequested(CSteam3Client * this,
   GameRichPresenceJoinRequested_t * pCallback) */

void __thiscall
CSteam3Client::OnGameRichPresenceJoinRequested
          (CSteam3Client *this,GameRichPresenceJoinRequested_t *pCallback)

{
  int cubSize;
  
                    /* Unresolved local var: char * szConCommand@[???] */
  Con_Printf("OnGameRichPresenceJoinRequested\n");
  if ((pCallback != (GameRichPresenceJoinRequested_t *)0x0) && (pCallback->m_rgchConnect[0] != '\0')
     ) {
    UnsafeCmdLineProcessor(pCallback->m_rgchConnect,cubSize);
    return;
  }
  return;
}


// CSteam3Client::OnGameServerChangeRequested  @ 000ba180
/* CSteam3Client::OnGameServerChangeRequested(GameServerChangeRequested_t*) */

void CSteam3Client::OnGameServerChangeRequested(GameServerChangeRequested_t *param_1)

{
  return;
}


// CSteam3Client::OnNewUrlLaunchParameters  @ 000bc7a0
/* DWARF original prototype: void OnNewUrlLaunchParameters(CSteam3Client * this,
   NewUrlLaunchParameters_t * param_1) */

void __thiscall
CSteam3Client::OnNewUrlLaunchParameters(CSteam3Client *this,NewUrlLaunchParameters_t *param_1)

{
  undefined4 *puVar1;
  size_t size;
  char *pchUnsafeCmdLine;
  int cubSize;
  
                    /* Unresolved local var: int nBytes@[???]
                       Unresolved local var: char * szCmdLine@[???]
                       Unresolved local var: int nBytesWritten@[???] */
  Con_Printf("OnNewUrlLaunchParameters\n");
  puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
  size = (**(code **)(*(int *)*puVar1 + 0x68))((int *)*puVar1,0,0);
  pchUnsafeCmdLine = Mem_ZeroMalloc(size);
  if (pchUnsafeCmdLine != (char *)0x0) {
    puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamApps::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar1 + 0x68))((int *)*puVar1,pchUnsafeCmdLine,size);
    UnsafeCmdLineProcessor(pchUnsafeCmdLine,cubSize);
    Mem_Free(pchUnsafeCmdLine);
    return;
  }
  return;
}


// CSteam3Client::RunFrame  @ 000bd760
/* DWARF original prototype: void RunFrame(CSteam3Client * this) */

void __thiscall CSteam3Client::RunFrame(CSteam3Client *this)

{
  SteamAPI_RunCallbacks();
  return;
}


// CSteam3Client::SetRichPresenceGameMode  @ 000bc8b0
/* DWARF original prototype: void SetRichPresenceGameMode(CSteam3Client * this, char * pszString) */

void __thiscall CSteam3Client::SetRichPresenceGameMode(CSteam3Client *this,char *pszString)

{
  g_szRichPresenceGameMode[0] = '\0';
  if ((pszString != (char *)0x0) && (*pszString != '\0')) {
    Q_strncpy_s(g_szRichPresenceGameMode,pszString,0x20);
  }
  return;
}


// CSteam3Client::SetRichPresenceInfo  @ 000bc8f0
/* DWARF original prototype: void SetRichPresenceInfo(CSteam3Client * this, char * pszNiceMapName)
    */

void __thiscall CSteam3Client::SetRichPresenceInfo(CSteam3Client *this,char *pszNiceMapName)

{
  g_szRichPresenceNiceMap[0] = '\0';
  if ((pszNiceMapName != (char *)0x0) && (*pszNiceMapName != '\0')) {
    Q_strncpy_s(g_szRichPresenceNiceMap,pszNiceMapName,0x20);
  }
  return;
}


// CSteam3Client::SetRichPresenceOverride  @ 000bc870
/* DWARF original prototype: void SetRichPresenceOverride(CSteam3Client * this, char * pszString) */

void __thiscall CSteam3Client::SetRichPresenceOverride(CSteam3Client *this,char *pszString)

{
  g_szRichPresenceOverride[0] = '\0';
  if ((pszString != (char *)0x0) && (*pszString != '\0')) {
    Q_strncpy_s(g_szRichPresenceOverride,pszString,0x80);
  }
  return;
}


// CSteam3Client::ShowOnScreenKeyboard  @ 000bd2a0
/* DWARF original prototype: void ShowOnScreenKeyboard(CSteam3Client * this, int fieldX, int fieldY)
    */

void __thiscall CSteam3Client::ShowOnScreenKeyboard(CSteam3Client *this,int fieldX,int fieldY)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = (int *)SteamInternal_ContextInit(SteamUtils::s_CallbackCounterAndContext);
  if (*piVar1 != 0) {
                    /* Unresolved local var: int nWidth@[???]
                       Unresolved local var: int nHeight@[???] */
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamUtils::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar2 + 0x8c))((int *)*puVar2,0,0,0,0x500,fieldY + 0x24);
  }
  return;
}


// CSteam3Client::Shutdown  @ 000ba5f0
/* DWARF original prototype: void Shutdown(CSteam3Client * this) */

void __thiscall CSteam3Client::Shutdown(CSteam3Client *this)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if ((this->super_CSteam3).m_bLoggedOn == false) {
    return;
  }
                    /* Unresolved local var: ISteamNetworkingSockets * pSteamNetworkingSockets@[???]
                        */
  piVar1 = (int *)SteamInternal_ContextInit
                            (SteamNetworkingSockets_SteamAPI::s_CallbackCounterAndContext);
  if ((*piVar1 != 0) && (ip_fakeudpports[0] != (ISteamNetworkingFakeUDPPort *)0x0)) {
    (*(code *)**(undefined4 **)ip_fakeudpports[0])(ip_fakeudpports[0]);
    ip_fakeudpports[0] = (ISteamNetworkingFakeUDPPort *)0x0;
  }
  piVar1 = (int *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
  if (*piVar1 != 0) {
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamInput::s_CallbackCounterAndContext_1);
    (**(code **)(*(int *)*puVar2 + 4))((int *)*puVar2);
  }
  iVar3 = (*eng->_vptr_IEngine[0x10])(eng);
  if (iVar3 == 1) {
    SteamAPI_Shutdown();
  }
  (this->super_CSteam3).m_bLoggedOn = false;
  return;
}


// CSteam3Client::TerminateConnection  @ 000bd5a0
/* DWARF original prototype: void TerminateConnection(CSteam3Client * this) */

void __thiscall CSteam3Client::TerminateConnection(CSteam3Client *this)

{
  undefined4 *puVar1;
  
  if (g_nCurrentGameConnectionIP != 0) {
    puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar1 + 0x10))
              ((int *)*puVar1,g_nCurrentGameConnectionIP,g_nCurrentGameConnectionPort);
    g_nCurrentGameConnectionIP = 0;
    g_nCurrentGameConnectionPort = 0;
    g_currentGameConnectionSteamID._0_4_ = 0;
    g_currentGameConnectionSteamID._4_4_ = 0;
  }
  puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamUser::s_CallbackCounterAndContext);
  (**(code **)(*(int *)*puVar1 + 0x50))((int *)*puVar1,0,0,0,0);
  g_szRichPresenceNiceMap[0] = '\0';
  g_szRichPresenceOverride[0] = '\0';
  g_szRichPresenceGameMode[0] = '\0';
  return;
}


// CSteam3Client::UpdateRichPresence  @ 000bc930
/* DWARF original prototype: void UpdateRichPresence(CSteam3Client * this) */

void __thiscall CSteam3Client::UpdateRichPresence(CSteam3Client *this)

{
  code *pcVar1;
  netadr_t a;
  netadr_t adr;
  netadr_t a_00;
  netadr_t adr_00;
  char cVar2;
  undefined4 uVar3;
  short sVar4;
  char *pcVar5;
  qboolean qVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  uint *puVar14;
  uint *puVar15;
  char *pcVar16;
  int in_GS_OFFSET;
  char *local_2b4;
  undefined1 local_2a0 [32];
  undefined1 local_280 [32];
  undefined1 local_260 [63];
  undefined1 local_221;
  char local_220 [16];
  undefined4 auStack_210 [12];
  undefined4 local_1e0;
  int32 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 auStack_1cc [11];
  uint local_1a0 [31];
  undefined1 local_121;
  char local_120 [255];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char[128] connect_string@[???]
                       Unresolved local var: char[64] group_name@[???]
                       Unresolved local var: char[256] mapname@[???]
                       Unresolved local var: bool bInLevel@[???]
                       Unresolved local var: int nMaxPlayerCount@[???]
                       Unresolved local var: int nPlayerCount@[???]
                       Unresolved local var: char[32] szCurrentPlayerCount@[???]
                       Unresolved local var: char[32] szMaxPlayerCount@[???]
                       Unresolved local var: bool bPaused@[???]
                       Unresolved local var: char * pszPauseState@[???]
                       Unresolved local var: bool bIsCustom@[???]
                       Unresolved local var: char * pszNiceMapName@[???]
                       Unresolved local var: char * pszKnown@[???]
                       Unresolved local var: char[64] szGameState@[???]
                       Unresolved local var: char[64] szStatusState@[???] */
  cVar2 = ::cl.levelname[0];
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_1a0[0]._0_1_ = 0;
  local_121 = 0;
  local_260[0] = 0;
  local_221 = 0;
  local_21 = 0;
  local_120[0] = '\0';
  if (cls.state != ca_dedicated) {
    if (::cl.levelname[0] != '\0') {
      iVar11 = sscanf(::cl.levelname,"maps/%s.bsp",local_120);
      if (iVar11 == 1) {
                    /* Unresolved local var: char * bsp@[???] */
        local_21 = 0;
        pcVar5 = strstr(local_120,".bsp");
        if (pcVar5 != (char *)0x0) {
          *pcVar5 = '\0';
        }
      }
      else {
        local_120[0] = '\0';
      }
    }
    pcVar5 = ::cl.players[0].name;
    iVar11 = 0;
    if (-1 < ::cl.maxclients) {
      iVar11 = ::cl.maxclients;
    }
    iVar12 = 0;
    do {
                    /* Unresolved local var: int i@[???] */
      if (pcVar5 != (char *)0x0) {
        iVar12 = (iVar12 + 1) - (uint)(*pcVar5 == '\0');
      }
      pcVar5 = pcVar5 + 0x250;
    } while ((int *)pcVar5 != &::cl.instanced_baseline[0].iuser1);
    __snprintf_chk(local_2a0,0x20,1,0x20,&DAT_000d153e,iVar12);
    __snprintf_chk(local_280,0x20,1,0x20,&DAT_000d153e,iVar11);
    qVar6 = Host_IsSinglePlayerGame();
    if (((qVar6 == false) && (g_nCurrentGameConnectionIP != 0)) &&
       (g_nCurrentGameConnectionPort != 0)) {
                    /* Unresolved local var: netadr_t.conflict server_adr@[???] */
      local_1e0 = 3;
      local_1dc = (*BigLong)(g_nCurrentGameConnectionIP);
      sVar4 = (*BigShort)(g_nCurrentGameConnectionPort);
      local_1d0 = CONCAT22(sVar4,(undefined2)local_1d0);
      uVar3 = local_1d0;
      if ((g_nFakeIP != 0) &&
         (adr_00.ip[0] = (undefined1)local_1dc, adr_00.ip[1] = local_1dc._1_1_,
         adr_00.ip[2] = local_1dc._2_1_, adr_00.ip[3] = local_1dc._3_1_, adr_00.type = local_1e0,
         adr_00.ipx[0] = (undefined1)local_1d8, adr_00.ipx[1] = local_1d8._1_1_,
         adr_00.ipx[2] = local_1d8._2_1_, adr_00.ipx[3] = local_1d8._3_1_,
         adr_00.ipx[4] = (undefined1)local_1d4, adr_00.ipx[5] = local_1d4._1_1_,
         adr_00.ipx[6] = local_1d4._2_1_, adr_00.ipx[7] = local_1d4._3_1_,
         adr_00.ipx[8] = (undefined1)local_1d0, adr_00.ipx[9] = local_1d0._1_1_, adr_00.port = sVar4
         , local_1d0 = uVar3, qVar6 = NET_IsLocalAddress(adr_00), qVar6 != false)) {
        local_1dc = (*BigLong)(g_nFakeIP);
        sVar4 = (*BigShort)(g_arFakePorts[0]);
        local_1d0 = CONCAT22(sVar4,(undefined2)local_1d0);
      }
      a.ip[0] = (undefined1)local_1dc;
      a.ip[1] = local_1dc._1_1_;
      a.ip[2] = local_1dc._2_1_;
      a.ip[3] = local_1dc._3_1_;
      a.type = local_1e0;
      a.ipx[0] = (undefined1)local_1d8;
      a.ipx[1] = local_1d8._1_1_;
      a.ipx[2] = local_1d8._2_1_;
      a.ipx[3] = local_1d8._3_1_;
      a.ipx[4] = (undefined1)local_1d4;
      a.ipx[5] = local_1d4._1_1_;
      a.ipx[6] = local_1d4._2_1_;
      a.ipx[7] = local_1d4._3_1_;
      a.ipx[8] = (undefined1)local_1d0;
      a.ipx[9] = local_1d0._1_1_;
      a.port = local_1d0._2_2_;
      qVar6 = NET_IsReservedAdr(a);
      if ((qVar6 == false) &&
         (adr.ip[0] = (undefined1)local_1dc, adr.ip[1] = local_1dc._1_1_,
         adr.ip[2] = local_1dc._2_1_, adr.ip[3] = local_1dc._3_1_, adr.type = local_1e0,
         adr.ipx[0] = (undefined1)local_1d8, adr.ipx[1] = local_1d8._1_1_,
         adr.ipx[2] = local_1d8._2_1_, adr.ipx[3] = local_1d8._3_1_,
         adr.ipx[4] = (undefined1)local_1d4, adr.ipx[5] = local_1d4._1_1_,
         adr.ipx[6] = local_1d4._2_1_, adr.ipx[7] = local_1d4._3_1_,
         adr.ipx[8] = (undefined1)local_1d0, adr.ipx[9] = local_1d0._1_1_,
         adr.port = local_1d0._2_2_, qVar6 = NET_IsLocalAddress(adr), qVar6 == false)) {
        __snprintf_chk(local_260,0x40,1,0x40,&DAT_000ddf37,g_nCurrentGameConnectionIP,
                       g_nCurrentGameConnectionPort);
        a_00.ip[0] = (undefined1)local_1dc;
        a_00.ip[1] = local_1dc._1_1_;
        a_00.ip[2] = local_1dc._2_1_;
        a_00.ip[3] = local_1dc._3_1_;
        a_00.type = local_1e0;
        a_00.ipx[0] = (undefined1)local_1d8;
        a_00.ipx[1] = local_1d8._1_1_;
        a_00.ipx[2] = local_1d8._2_1_;
        a_00.ipx[3] = local_1d8._3_1_;
        a_00.ipx[4] = (undefined1)local_1d4;
        a_00.ipx[5] = local_1d4._1_1_;
        a_00.ipx[6] = local_1d4._2_1_;
        a_00.ipx[7] = local_1d4._3_1_;
        a_00.ipx[8] = (undefined1)local_1d0;
        a_00.ipx[9] = local_1d0._1_1_;
        a_00.port = local_1d0._2_2_;
        pcVar5 = NET_AdrToString(a_00);
        __snprintf_chk(local_1a0,0x80,1,0x80,"+connect %s",pcVar5);
      }
    }
    qVar6 = Host_IsServerActive();
    pcVar5 = "#HL_RP_Unpaused";
    if ((qVar6 != false) && (sv.paused != false)) {
      pcVar5 = "#HL_RP_Paused";
    }
    local_2b4 = g_szRichPresenceNiceMap;
    if ((g_szRichPresenceNiceMap[0] == '\0') &&
       (local_2b4 = CL_MapLocalizationString(local_120), local_2b4 == local_120)) {
      pcVar13 = "Unknown";
    }
    else {
      pcVar13 = "Known";
    }
    builtin_strncpy(local_220,"#HL_RP_MainMenu",0x10);
    uVar7 = 0;
    do {
      *(undefined4 *)((int)auStack_210 + uVar7) = 0;
      *(undefined4 *)((int)auStack_210 + uVar7 + 4) = 0;
      uVar7 = uVar7 + 8;
    } while (uVar7 < 0x30);
    local_1e0 = 0x5f4c4823;
    local_1dc = 0x74617453;
    local_1d8 = 0x4d5f7375;
    local_1d4 = 0x4d6e6961;
    local_1d0 = 0x756e65;
    uVar7 = 0;
    do {
      uVar10 = uVar7;
      *(undefined4 *)((int)auStack_1cc + uVar10) = 0;
      *(undefined4 *)((int)auStack_1cc + uVar10 + 4) = 0;
      uVar7 = uVar10 + 8;
    } while (uVar10 + 8 < 0x28);
    *(undefined4 *)((int)auStack_1cc + uVar10 + 8) = 0;
    if (cVar2 != '\0') {
                    /* Unresolved local var: char * pszGameMode@[???] */
      pcVar16 = g_szRichPresenceGameMode;
      if ((g_szRichPresenceGameMode[0] == '\0') && (pcVar16 = "Deathmatch", ::cl.gametype != 1)) {
        pcVar16 = "Singleplayer";
      }
      __snprintf_chk(local_220,0x40,1,0x40,&DAT_000dde70,pcVar16,pcVar13);
      __snprintf_chk(auStack_210 + 0xc,0x40,1,0x40,"#HL_Status_%s%s",pcVar16,pcVar13);
    }
    piVar8 = (int *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
    if (*piVar8 != 0) {
      puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
      pcVar13 = local_220;
      if (g_szRichPresenceOverride[0] != '\0') {
        pcVar13 = g_szRichPresenceOverride;
      }
      (**(code **)(*(int *)*puVar9 + 0xac))((int *)*puVar9,"steam_display",pcVar13);
      puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
      pcVar13 = (char *)(auStack_210 + 0xc);
      if (g_szRichPresenceOverride[0] != '\0') {
        pcVar13 = g_szRichPresenceOverride;
      }
      (**(code **)(*(int *)*puVar9 + 0xac))((int *)*puVar9,"status",pcVar13);
      puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar9 + 0xac))((int *)*puVar9,"steam_player_group",local_260);
      puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar9 + 0xac))((int *)*puVar9,"steam_player_group_size",local_2a0);
      puVar15 = local_1a0;
      do {
        puVar14 = puVar15;
        uVar10 = *puVar14 + 0xfefefeff & ~*puVar14;
        uVar7 = uVar10 & 0x80808080;
        puVar15 = puVar14 + 1;
      } while (uVar7 == 0);
      if ((uVar10 & 0x8080) == 0) {
        puVar15 = (uint *)((int)puVar14 + 6);
        uVar7 = uVar7 >> 0x10;
      }
      if ((int)puVar15 + ((-3 - (uint)CARRY1((byte)uVar7,(byte)uVar7)) - (int)local_1a0) < 2) {
        puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
        (**(code **)(*(int *)*puVar9 + 0xac))((int *)*puVar9,"connect","");
      }
      else {
        puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
        (**(code **)(*(int *)*puVar9 + 0xac))((int *)*puVar9,"connect",local_1a0);
      }
      puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar9 + 0xac))((int *)*puVar9,"game:raw_map_name",local_120);
      puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
      pcVar13 = g_szRichPresenceNiceMap;
      if (g_szRichPresenceNiceMap[0] == '\0') {
        pcVar13 = local_2b4;
      }
      (**(code **)(*(int *)*puVar9 + 0xac))((int *)*puVar9,"game:map_name",pcVar13);
      puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar9 + 0xac))((int *)*puVar9,"game:current_player_count",local_2a0);
      puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar9 + 0xac))((int *)*puVar9,"game:max_player_count",local_280);
      puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
      piVar8 = (int *)*puVar9;
      pcVar1 = *(code **)(*piVar8 + 0xac);
      pcVar13 = Cvar_VariableString("hostname");
      (*pcVar1)(piVar8,"game:server_name",pcVar13);
      puVar9 = (undefined4 *)SteamInternal_ContextInit(SteamFriends::s_CallbackCounterAndContext);
      (**(code **)(*(int *)*puVar9 + 0xac))((int *)*puVar9,"game:pause_state",pcVar5);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CSteam3Client::~CSteam3Client  @ 000bef10
/* DWARF original prototype: void ~CSteam3Client(CSteam3Client * this, int __in_chrg) */

void __thiscall CSteam3Client::~CSteam3Client(CSteam3Client *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->m_steamcallback_OnGameRichPresenceJoinRequested).super_CCallbackImpl<264>.
          super_CCallbackBase.m_nCallbackFlags;
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Client_000de868;
  (this->m_steamcallback_OnGameRichPresenceJoinRequested).super_CCallbackImpl<264>.
  super_CCallbackBase._vptr_CCallbackBase = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de81c;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_steamcallback_OnGameRichPresenceJoinRequested);
  }
  bVar1 = (this->m_steamcallback_OnNewUrlLaunchParameters).super_CCallbackImpl<1>.
          super_CCallbackBase.m_nCallbackFlags;
  (this->m_steamcallback_OnNewUrlLaunchParameters).super_CCallbackImpl<1>.super_CCallbackBase.
  _vptr_CCallbackBase = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de6cc;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_steamcallback_OnNewUrlLaunchParameters);
  }
  bVar1 = (this->m_CallbackGameOverlayActivated).super_CCallbackImpl<8>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGameOverlayActivated).super_CCallbackImpl<8>.super_CCallbackBase.
  _vptr_CCallbackBase = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de720;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGameOverlayActivated);
  }
  bVar1 = (this->m_CallbackGameServerChangeRequested).super_CCallbackImpl<128>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGameServerChangeRequested).super_CCallbackImpl<128>.super_CCallbackBase.
  _vptr_CCallbackBase = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de7ac;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGameServerChangeRequested);
  }
  bVar1 = (this->m_CallbackClientGameServerDeny).super_CCallbackImpl<16>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackClientGameServerDeny).super_CCallbackImpl<16>.super_CCallbackBase.
  _vptr_CCallbackBase = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de624;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CSteam3Client::~CSteam3Client  @ 000bf4a0
/* DWARF original prototype: void ~CSteam3Client(CSteam3Client * this, int __in_chrg) */

void __thiscall CSteam3Client::~CSteam3Client(CSteam3Client *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->m_steamcallback_OnGameRichPresenceJoinRequested).super_CCallbackImpl<264>.
          super_CCallbackBase.m_nCallbackFlags;
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Client_000de868;
  (this->m_steamcallback_OnGameRichPresenceJoinRequested).super_CCallbackImpl<264>.
  super_CCallbackBase._vptr_CCallbackBase = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de81c;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_steamcallback_OnGameRichPresenceJoinRequested);
  }
  bVar1 = (this->m_steamcallback_OnNewUrlLaunchParameters).super_CCallbackImpl<1>.
          super_CCallbackBase.m_nCallbackFlags;
  (this->m_steamcallback_OnNewUrlLaunchParameters).super_CCallbackImpl<1>.super_CCallbackBase.
  _vptr_CCallbackBase = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de6cc;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_steamcallback_OnNewUrlLaunchParameters);
  }
  bVar1 = (this->m_CallbackGameOverlayActivated).super_CCallbackImpl<8>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGameOverlayActivated).super_CCallbackImpl<8>.super_CCallbackBase.
  _vptr_CCallbackBase = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de720;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGameOverlayActivated);
  }
  bVar1 = (this->m_CallbackGameServerChangeRequested).super_CCallbackImpl<128>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGameServerChangeRequested).super_CCallbackImpl<128>.super_CCallbackBase.
  _vptr_CCallbackBase = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de7ac;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGameServerChangeRequested);
  }
  bVar1 = (this->m_CallbackClientGameServerDeny).super_CCallbackImpl<16>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackClientGameServerDeny).super_CCallbackImpl<16>.super_CCallbackBase.
  _vptr_CCallbackBase = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de624;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackClientGameServerDeny);
  }
  operator_delete(this);
  return;
}


// CSteam3Server::Activate  @ 000bbee0
/* DWARF original prototype: void Activate(CSteam3Server * this) */

void __thiscall CSteam3Server::Activate(CSteam3Server *this)

{
  code *pcVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  FILE *__stream;
  int *piVar8;
  byte bVar9;
  uint uVar10;
  int in_GS_OFFSET;
  bool bVar11;
  uint local_134;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: uint32 unIP@[???]
                       Unresolved local var: char[260] gamedir@[???]
                       Unresolved local var: EServerMode eSMode@[???]
                       Unresolved local var: int uPort@[???]
                       Unresolved local var: int nAppID@[???]
                       Unresolved local var: bool iHasPW@[???] */
  fVar2 = sv_lan.value;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((this->super_CSteam3).m_bLoggedOn == false) {
    bVar11 = net_local_adr.type == NA_IP;
    (this->super_CSteam3).m_bLoggedOn = true;
    local_134 = 0;
    if (bVar11) {
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
      local_134 = (uint)net_local_adr.ip >> 0x18 | ((uint)net_local_adr.ip & 0xff0000) >> 8 |
                  ((uint)net_local_adr.ip & 0xff00) << 8 | (int)net_local_adr.ip << 0x18;
    }
    this->m_bLanOnly = 0.0 < sv_lan.value;
    iVar4 = COM_CheckParm("-insecure");
    bVar9 = false;
    if (iVar4 == 0) {
      bVar9 = this->m_bLanOnly ^ 1;
    }
    this->m_bWantToBeSecure = (bool)bVar9;
    COM_FileBase(com_gamedir,local_124);
    uVar10 = (uint)iphostport.value;
    iVar4 = 3 - (uint)(this->m_bWantToBeSecure == false);
    if (this->m_bLanOnly != false) {
      iVar4 = 1;
    }
    if (uVar10 == 0) {
      uVar10 = (uint)hostport.value;
    }
    iVar5 = GetGameAppID();
                    /* Unresolved local var: FILE * f@[???] */
    if (((0 < iVar5) && (cls.state == ca_dedicated)) &&
       (__stream = fopen("steam_appid.txt","w+"), __stream != (FILE *)0x0)) {
      __fprintf_chk(__stream,1,"%d\n",iVar5);
      fclose(__stream);
    }
    cVar3 = SteamInternal_GameServer_Init
                      (local_134,0,uVar10 & 0xffff,0xffff,iVar4,gpszVersionString);
    if (cVar3 == '\0') {
      Sys_Error("Unable to initialize Steam.");
    }
    else {
      puVar6 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext)
      ;
      (**(code **)(*(int *)*puVar6 + 4))((int *)*puVar6,gpszProductString);
      puVar6 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext)
      ;
      (**(code **)(*(int *)*puVar6 + 0xc))((int *)*puVar6,local_124);
      puVar6 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext)
      ;
      (**(code **)(*(int *)*puVar6 + 0x10))((int *)*puVar6,cls.state == ca_dedicated);
      puVar6 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext)
      ;
      piVar8 = (int *)*puVar6;
      pcVar1 = *(code **)(*piVar8 + 8);
      pcVar7 = (*gEntityInterface.pfnGetGameDescription)();
      (*pcVar1)(piVar8,pcVar7);
                    /* Unresolved local var: bool bLanOnly@[???] */
                    /* Unresolved local var: bool bLanOnly@[???] */
      if (((sv_lan.value <= 0.0) && (iVar4 = PF_IsDedicatedServer(), iVar4 == 0)) &&
         (0.0 < sv_use_steam_networking.value)) {
        piVar8 = (int *)SteamInternal_ContextInit
                                  (SteamNetworkingUtils_SteamAPI::s_CallbackCounterAndContext);
        if (*piVar8 != 0) {
          puVar6 = (undefined4 *)
                   SteamInternal_ContextInit
                             (SteamNetworkingUtils_SteamAPI::s_CallbackCounterAndContext);
          (**(code **)(*(int *)*puVar6 + 0x34))((int *)*puVar6,5,SteamNetworkingSocketsDebugOutput);
        }
        Con_Printf("FakeIP enabled! Requesting a fake IP.\n");
        puVar6 = (undefined4 *)
                 SteamInternal_ContextInit
                           (SteamGameServerNetworkingSockets_SteamAPI::s_CallbackCounterAndContext_1
                           );
        (**(code **)(*(int *)*puVar6 + 0xa8))((int *)*puVar6,1);
      }
      puVar6 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext)
      ;
      (**(code **)(*(int *)*puVar6 + 0x18))((int *)*puVar6);
      (this->super_CSteam3).m_bLogOnResult = false;
      iVar4 = COM_CheckParm("-nomaster");
      if (iVar4 == 0) {
        if ((gfNoMasterServer == false) && (1 < svs.maxclients)) {
          puVar6 = (undefined4 *)
                   SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
          (**(code **)(*(int *)*puVar6 + 0x60))((int *)*puVar6,1);
                    /* Unresolved local var: bool bLanOnly@[???] */
                    /* Unresolved local var: bool bLanOnly@[???] */
          if ((sv_lan.value <= 0.0) &&
             ((iVar4 = PF_IsDedicatedServer(), iVar4 == 0 && (0.0 < sv_use_steam_networking.value)))
             ) {
            NET_InternalOpenOrCloseFakeUDPPorts(false,true);
          }
          if (*sv_password.string != '\0') {
            Q_stricmp(sv_password.string,"none");
          }
          NotifyOfLevelChange(this,true);
        }
      }
      else {
        Con_Printf("Master server communication disabled.\n");
        gfNoMasterServer = true;
      }
    }
  }
  else {
                    /* Unresolved local var: bool bLanOnly@[???] */
    if ((sv_lan.value != 0.0) != this->m_bLanOnly) {
      this->m_bLanOnly = sv_lan.value != 0.0;
      iVar4 = COM_CheckParm("-insecure");
      if (fVar2 == 0.0) {
        this->m_bWantToBeSecure = iVar4 == 0;
      }
      else {
        this->m_bWantToBeSecure = false;
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CSteam3Server::CSteam3Server  @ 000bb440
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void CSteam3Server(CSteam3Server * this) */

void __thiscall CSteam3Server::CSteam3Server(CSteam3Server *this)

{
  (this->super_CSteam3).m_bLoggedOn = false;
  (this->super_CSteam3).m_bLogOnResult = false;
  (this->super_CSteam3).m_hSteamPipe = 0;
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Server_000de854;
  (this->m_CallbackGSClientApprove).super_CCallbackImpl<16>.super_CCallbackBase.m_iCallback = 0;
  (this->m_CallbackGSClientApprove).super_CCallbackImpl<16>.super_CCallbackBase._vptr_CCallbackBase
       = (_func_int_varargs **)&PTR_Run_000de640;
  (this->m_CallbackGSClientApprove).m_pObj = (CSteam3Server *)0x0;
  (this->m_CallbackGSClientApprove).m_Func.__pfn =
       (_func___thiscall_void_CSteam3Server_ptr_GSClientApprove_t_ptr *)0x0;
  (this->m_CallbackGSClientApprove).m_Func.__delta = 0;
  (this->m_CallbackGSClientApprove).super_CCallbackImpl<16>.super_CCallbackBase.m_nCallbackFlags =
       '\x02';
  if (this == (CSteam3Server *)0x0) {
    _DAT_0000002c = 0;
    _DAT_00000024 = &PTR_Run_000de678;
    _DAT_00000030 = 0;
    _DAT_00000034 = 0;
    _DAT_00000038 = 0;
    _DAT_00000044 = 0;
    _DAT_00000054 = &PTR_Run_000de6e8;
    _DAT_00000060 = 0;
    _DAT_00000064 = 0;
    _DAT_00000068 = 0;
    _DAT_00000074 = 0;
    _DAT_0000006c = &PTR_Run_000de704;
    _DAT_00000090 = 0;
    _DAT_00000094 = 0;
    _DAT_00000098 = 0;
    _DAT_0000003c = &PTR_Run_000de6b0;
    _DAT_00000048 = 0;
    _DAT_000000a4 = 0;
    _DAT_0000004c = 0;
    _DAT_00000050 = 0;
    _DAT_0000005c = 0;
    _DAT_00000078 = 0;
    _DAT_0000007c = 0;
    _DAT_0000009c = &PTR_Run_000de774;
    DAT_00000028 = 2;
    DAT_00000040 = 2;
    DAT_00000058 = 2;
    _DAT_00000080 = 0;
    DAT_00000070 = 2;
    _DAT_0000008c = 0;
    _DAT_00000084 = &PTR_Run_000de73c;
    DAT_00000088 = 2;
    _DAT_000000a8 = 0;
    _DAT_000000ac = 0;
    _DAT_000000b0 = 0;
    DAT_000000a0 = 2;
  }
  else {
    (this->m_CallbackGSClientApprove).m_pObj = this;
    (this->m_CallbackGSClientApprove).m_Func.__pfn = OnGSClientApprove;
    SteamAPI_RegisterCallback(&this->m_CallbackGSClientApprove,0xc9);
    (this->m_CallbackGSClientDeny).super_CCallbackImpl<140>.super_CCallbackBase.m_iCallback = 0;
    (this->m_CallbackGSClientDeny).super_CCallbackImpl<140>.super_CCallbackBase._vptr_CCallbackBase
         = (_func_int_varargs **)&PTR_Run_000de678;
    (this->m_CallbackGSClientDeny).super_CCallbackImpl<140>.super_CCallbackBase.m_nCallbackFlags =
         '\x02';
    (this->m_CallbackGSClientDeny).m_pObj = this;
    (this->m_CallbackGSClientDeny).m_Func.__pfn = OnGSClientDeny;
    (this->m_CallbackGSClientDeny).m_Func.__delta = 0;
    SteamAPI_RegisterCallback(&this->m_CallbackGSClientDeny,0xca);
    (this->m_CallbackGSClientKick).super_CCallbackImpl<12>.super_CCallbackBase.m_iCallback = 0;
    (this->m_CallbackGSClientKick).super_CCallbackImpl<12>.super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000de6b0;
    (this->m_CallbackGSClientKick).super_CCallbackImpl<12>.super_CCallbackBase.m_nCallbackFlags =
         '\x02';
    (this->m_CallbackGSClientKick).m_pObj = this;
    (this->m_CallbackGSClientKick).m_Func.__pfn = OnGSClientKick;
    (this->m_CallbackGSClientKick).m_Func.__delta = 0;
    SteamAPI_RegisterCallback(&this->m_CallbackGSClientKick,0xcb);
    (this->m_CallbackGSPolicyResponse).super_CCallbackImpl<1>.super_CCallbackBase.m_iCallback = 0;
    (this->m_CallbackGSPolicyResponse).super_CCallbackImpl<1>.super_CCallbackBase.
    _vptr_CCallbackBase = (_func_int_varargs **)&PTR_Run_000de6e8;
    (this->m_CallbackGSPolicyResponse).super_CCallbackImpl<1>.super_CCallbackBase.m_nCallbackFlags =
         '\x02';
    (this->m_CallbackGSPolicyResponse).m_pObj = this;
    (this->m_CallbackGSPolicyResponse).m_Func.__pfn = OnGSPolicyResponse;
    (this->m_CallbackGSPolicyResponse).m_Func.__delta = 0;
    SteamAPI_RegisterCallback(&this->m_CallbackGSPolicyResponse,0x73);
    (this->m_CallbackLogonSuccess).super_CCallbackImpl<1>.super_CCallbackBase.m_iCallback = 0;
    (this->m_CallbackLogonSuccess).super_CCallbackImpl<1>.super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000de704;
    (this->m_CallbackLogonSuccess).super_CCallbackImpl<1>.super_CCallbackBase.m_nCallbackFlags =
         '\x02';
    (this->m_CallbackLogonSuccess).m_pObj = this;
    (this->m_CallbackLogonSuccess).m_Func.__pfn = OnLogonSuccess;
    (this->m_CallbackLogonSuccess).m_Func.__delta = 0;
    SteamAPI_RegisterCallback(&this->m_CallbackLogonSuccess,0x65);
    (this->m_CallbackLogonFailure).super_CCallbackImpl<8>.super_CCallbackBase.m_iCallback = 0;
    (this->m_CallbackLogonFailure).super_CCallbackImpl<8>.super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000de73c;
    (this->m_CallbackLogonFailure).m_Func.__pfn = OnLogonFailure;
    (this->m_CallbackLogonFailure).m_Func.__delta = 0;
    (this->m_CallbackLogonFailure).super_CCallbackImpl<8>.super_CCallbackBase.m_nCallbackFlags =
         '\x02';
    (this->m_CallbackLogonFailure).m_pObj = this;
    SteamAPI_RegisterCallback(&this->m_CallbackLogonFailure,0x66);
    (this->m_CallbackFakeIPResult).super_CCallbackImpl<160>.super_CCallbackBase.m_iCallback = 0;
    (this->m_CallbackFakeIPResult).m_Func.__delta = 0;
    (this->m_CallbackFakeIPResult).super_CCallbackImpl<160>.super_CCallbackBase._vptr_CCallbackBase
         = (_func_int_varargs **)&PTR_Run_000de774;
    (this->m_CallbackFakeIPResult).super_CCallbackImpl<160>.super_CCallbackBase.m_nCallbackFlags =
         '\x02';
    (this->m_CallbackFakeIPResult).m_pObj = this;
    (this->m_CallbackFakeIPResult).m_Func.__pfn = OnFakeIPResult;
    SteamAPI_RegisterCallback(&this->m_CallbackFakeIPResult,0x4c7);
  }
  (this->m_SteamIDGS).m_steamid.m_comp.m_EUniverse = 0;
  *(undefined1 *)((int)&(this->m_SteamIDGS).m_steamid + 4) = 0;
  *(undefined1 *)((int)&(this->m_SteamIDGS).m_steamid + 5) = 0;
  *(undefined1 *)((int)&(this->m_SteamIDGS).m_steamid + 6) = 0;
  this->m_bHasActivePlayers = false;
  this->m_bWantToBeSecure = false;
  this->m_bLanOnly = false;
  (this->m_SteamIDGS).m_steamid.m_comp.m_unAccountID = 1;
  return;
}


// CSteam3Server::ClientFindFromSteamID  @ 000bb3d0
/* DWARF original prototype: client_t.conflict * ClientFindFromSteamID(CSteam3Server * this,
   CSteamID * steamIDFind) */

client_t_conflict * __thiscall
CSteam3Server::ClientFindFromSteamID(CSteam3Server *this,CSteamID *steamIDFind)

{
  client_s *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: client_t.conflict * cl@[???]
                       Unresolved local var: int i@[???] */
  if (0 < svs.maxclients) {
    iVar2 = 0;
    pcVar1 = svs.clients;
    do {
      if ((((pcVar1->connected != false) || (pcVar1->active != false)) || (pcVar1->spawned != false)
          ) && (((pcVar1->network_userid).idtype == 1 &&
                (*(int *)((int)&(pcVar1->network_userid).m_SteamID + 4) ==
                 *(int *)((int)&steamIDFind->m_steamid + 4) &&
                 (uint32)(pcVar1->network_userid).m_SteamID ==
                 (steamIDFind->m_steamid).m_comp.m_unAccountID)))) {
        return (client_t_conflict *)pcVar1;
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 1;
    } while (iVar2 != svs.maxclients);
  }
  return (client_t_conflict *)0x0;
}


// CSteam3Server::GetSteamID  @ 000ba680
/* DWARF original prototype: uint64 GetSteamID(CSteam3Server * this) */

uint64 __thiscall CSteam3Server::GetSteamID(CSteam3Server *this)

{
  if (this->m_bLanOnly != false) {
    return 0x100000000000000;
  }
  return (this->m_SteamIDGS).m_steamid.m_unAll64Bits;
}


// CSteam3Server::NotifyBotConnect  @ 000bbb60
/* DWARF original prototype: bool NotifyBotConnect(CSteam3Server * this, client_t.conflict * client)
    */

bool __thiscall CSteam3Server::NotifyBotConnect(CSteam3Server *this,client_t_conflict *client)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 local_18;
  undefined4 local_14 [3];
  
  if (client != (client_t_conflict *)0x0) {
    bVar1 = (this->super_CSteam3).m_bLoggedOn;
    if (bVar1 != false) {
      (client->network_userid).idtype = 3;
      puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext)
      ;
      (**(code **)(*(int *)*puVar2 + 0x9c))(local_14,(int *)*puVar2);
      *(undefined4 *)&(client->network_userid).m_SteamID = local_18;
      *(undefined4 *)((int)&(client->network_userid).m_SteamID + 4) = local_14[0];
    }
    return bVar1;
  }
  return false;
}


// CSteam3Server::NotifyClientConnect  @ 000bb980
/* DWARF original prototype: bool NotifyClientConnect(CSteam3Server * this, client_t.conflict *
   client, void * pvSteam2Key, uint32 ucbSteam2Key) */

bool __thiscall
CSteam3Server::NotifyClientConnect
          (CSteam3Server *this,client_t_conflict *client,void *pvSteam2Key,uint32 ucbSteam2Key)

{
  uint uVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: CSteamID steamIDClient@[???]
                       Unresolved local var: bool bRet@[???] */
  if (client != (client_t_conflict *)0x0) {
    uVar2 = 0;
    if ((this->super_CSteam3).m_bLoggedOn != false) {
                    /* Unresolved local var: CSteamID steamIDClient@[???]
                       Unresolved local var: bool bRet@[???] */
      (client->network_userid).idtype = 1;
      local_14 = 0;
      local_10 = 0;
      puVar3 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext)
      ;
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
      uVar1 = (client->network_userid).clientip;
      uVar2 = (**(code **)(*(int *)*puVar3 + 0x98))
                        ((int *)*puVar3,
                         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                         uVar1 << 0x18,pvSteam2Key,ucbSteam2Key,&local_14);
      *(undefined4 *)&(client->network_userid).m_SteamID = local_14;
      *(undefined4 *)((int)&(client->network_userid).m_SteamID + 4) = local_10;
    }
    return (bool)uVar2;
  }
  return false;
}


// CSteam3Server::NotifyClientDisconnect  @ 000bbbe0
/* DWARF original prototype: void NotifyClientDisconnect(CSteam3Server * this, client_t.conflict *
   cl) */

void __thiscall CSteam3Server::NotifyClientDisconnect(CSteam3Server *this,client_t_conflict *cl)

{
  undefined4 *puVar1;
  
  if (((cl != (client_t_conflict *)0x0) && ((this->super_CSteam3).m_bLoggedOn != false)) &&
     (((cl->network_userid).idtype & 0xfffffffdU) == 1)) {
    puVar1 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar1 + 0xa0))
              ((int *)*puVar1,(int)(cl->network_userid).m_SteamID,
               *(undefined4 *)((int)&(cl->network_userid).m_SteamID + 4));
    return;
  }
  return;
}


// CSteam3Server::NotifyOfLevelChange  @ 000bbde0
/* DWARF original prototype: void NotifyOfLevelChange(CSteam3Server * this, bool bForce) */

void __thiscall CSteam3Server::NotifyOfLevelChange(CSteam3Server *this,bool bForce)

{
  cvar_s *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  
                    /* Unresolved local var: int maxplayers@[???]
                       Unresolved local var: bool iHasPW@[???] */
  bVar5 = false;
  SendUpdatedServerDetails(this);
  if (*sv_password.string != '\0') {
    iVar3 = Q_stricmp(sv_password.string,"none");
    bVar5 = iVar3 != 0;
  }
  puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  (**(code **)(*(int *)*puVar2 + 0x40))((int *)*puVar2,bVar5);
  puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  (**(code **)(*(int *)*puVar2 + 0x4c))((int *)*puVar2);
  pcVar1 = cvar_vars;
                    /* Unresolved local var: cvar_t * var@[???] */
  do {
    if (pcVar1 == (cvar_t *)0x0) {
      return;
    }
    if ((pcVar1->flags & 4U) != 0) {
      if ((pcVar1->flags & 0x20U) == 0) {
                    /* Unresolved local var: char * szVal@[???] */
        pcVar4 = pcVar1->string;
      }
      else {
        iVar3 = Q_strlen(pcVar1->string);
        if (0 < iVar3) {
          pcVar4 = "1";
          iVar3 = Q_stricmp(pcVar1->string,"none");
          if (iVar3 != 0) goto LAB_000bbe43;
        }
        pcVar4 = "0";
      }
LAB_000bbe43:
      puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext)
      ;
      (**(code **)(*(int *)*puVar2 + 0x50))((int *)*puVar2,pcVar1->name,pcVar4);
    }
    pcVar1 = pcVar1->next;
  } while( true );
}


// CSteam3Server::OnFakeIPResult  @ 000b9f10
/* DWARF original prototype: void OnFakeIPResult(CSteam3Server * this, SteamNetworkingFakeIPResult_t
   * pResult) */

void __thiscall
CSteam3Server::OnFakeIPResult(CSteam3Server *this,SteamNetworkingFakeIPResult_t *pResult)

{
  uchar uVar1;
  uchar uVar2;
  netadrtype_t nVar3;
  uchar auVar4 [4];
  ushort uVar5;
  qboolean qVar6;
  char *pcVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  long lVar11;
  hostent *phVar12;
  int in_GS_OFFSET;
  socklen_t sStack_2a4;
  short sStack_2a0;
  ushort uStack_29e;
  uchar auStack_29c [4];
  sockaddr asStack_290 [7];
  undefined1 uStack_211;
  char acStack_210 [511];
  undefined1 uStack_11;
  int iStack_10;
  
  iStack_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (noip != false) {
    Con_Printf("TCP/IP Disabled.\n");
    Q_memset(&net_local_adr,0,0x14);
    goto LAB_000b2159;
  }
  qVar6 = NET_ShouldUseSteamFakeIP();
  if (qVar6 != 0) {
    if ((g_nFakeIP == 0) && (Net_PollSteamFakeIPResult(), g_nFakeIP == 0)) {
      Q_memset(&net_local_adr,0,0x14);
    }
    else if ((net_local_adr.type != NA_IP) ||
            ((uVar10 = NET_NetAdr_GetIPHostByteOrder((netadr_t_conflict *)&net_local_adr),
             uVar10 != g_nFakeIP ||
             (uVar5 = NET_NetAdr_GetPort((netadr_t_conflict *)&net_local_adr),
             g_arFakePorts[0] != uVar5)))) {
      net_local_adr.type = NA_IP;
      NET_NetAdr_SetIP((netadr_t_conflict *)&net_local_adr,g_nFakeIP);
      NET_NetAdr_SetPort((netadr_t_conflict *)&net_local_adr,g_arFakePorts[0]);
      Con_Printf("Using FakeIP\n");
      uVar5 = net_local_adr.port;
      auVar4 = net_local_adr.ip;
      nVar3 = net_local_adr.type;
      uVar10 = (uint)net_local_adr.ip >> 0x18;
      uVar1 = net_local_adr.ip[1];
      uVar2 = net_local_adr.ip[2];
      Q_memset(NET_AdrToString::s,0,0x40);
      if (nVar3 == NA_LOOPBACK) {
        builtin_strncpy(NET_AdrToString::s,"loopback",9);
      }
      else if (nVar3 == NA_IP) {
        __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",(uint)auVar4 & 0xff,uVar1,
                       uVar2,uVar10,uVar5 >> 8 | uVar5 << 8);
      }
      Con_Printf("Server IP address %s\n",NET_AdrToString::s);
      uVar5 = net_local_adr.port;
      auVar4 = net_local_adr.ip;
      nVar3 = net_local_adr.type;
      uVar10 = (uint)net_local_adr.ip >> 0x18;
      uVar1 = net_local_adr.ip[1];
      uVar2 = net_local_adr.ip[2];
      Q_memset(NET_AdrToString::s,0,0x40);
      if (nVar3 == NA_LOOPBACK) {
        builtin_strncpy(NET_AdrToString::s,"loopback",9);
      }
      else if (nVar3 == NA_IP) {
        __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",(uint)auVar4 & 0xff,uVar1,
                       uVar2,uVar10,uVar5 >> 8 | uVar5 << 8);
      }
      pcVar7 = va("%s",NET_AdrToString::s);
      Cvar_Set("net_address",pcVar7);
      Steam_UpdateRichPresence();
    }
    goto LAB_000b2159;
  }
  iVar8 = Q_strcmp(ipname.string,"localhost");
  if (iVar8 == 0) {
    gethostname(acStack_210,0x200);
  }
  else {
    Q_strncpy(acStack_210,ipname.string,0x1ff);
  }
  uStack_11 = 0;
  Q_memset(&net_local_adr,0,0x14);
  iVar8 = Q_strcmp(acStack_210,"localhost");
  if ((iVar8 == 0) || (iVar8 = Q_strcmp(acStack_210,"127.0.0.1"), iVar8 == 0)) {
    Q_memset(&net_local_adr,0,0x14);
    net_local_adr.type = NA_LOOPBACK;
  }
  else {
    Q_memset(&sStack_2a0,0,0x10);
    sStack_2a0 = 2;
    uStack_29e = 0;
    Q_strncpy((char *)asStack_290,acStack_210,0x7f);
    uStack_211 = 0;
    pcVar7 = (char *)((int)&asStack_290[0].sa_family + 1);
    while ((char)asStack_290[0].sa_family != '\0') {
      if ((char)asStack_290[0].sa_family == ':') {
        pcVar7[-1] = '\0';
        lVar11 = strtol(pcVar7,(char **)0x0,10);
        uStack_29e = (ushort)lVar11 >> 8 | (ushort)lVar11 << 8;
      }
      asStack_290[0].sa_family._0_1_ = *pcVar7;
      pcVar7 = pcVar7 + 1;
    }
    auStack_29c = (uchar  [4])inet_addr((char *)asStack_290);
    if (auStack_29c == (uchar  [4])0xffffffff) {
      phVar12 = gethostbyname((char *)asStack_290);
      if (phVar12 == (hostent *)0x0) goto LAB_000b23ab;
      auStack_29c = *(uchar (*) [4])*phVar12->h_addr_list;
    }
    if (sStack_2a0 == 2) {
      net_local_adr.ip[0] = auStack_29c[0];
      net_local_adr.ip[1] = auStack_29c[1];
      net_local_adr.ip[2] = auStack_29c[2];
      net_local_adr.ip[3] = auStack_29c[3];
      net_local_adr.type = NA_IP;
      net_local_adr.port = uStack_29e;
    }
  }
LAB_000b23ab:
  sStack_2a4 = 0x10;
  iVar8 = getsockname(ip_sockets[1],asStack_290,&sStack_2a4);
  auVar4 = net_local_adr.ip;
  nVar3 = net_local_adr.type;
  if (iVar8 == 0) {
    uVar10 = (uint)net_local_adr.ip >> 0x18;
    uVar1 = net_local_adr.ip[1];
    net_local_adr.port._0_1_ = asStack_290[0].sa_data[0];
    net_local_adr.port._1_1_ = asStack_290[0].sa_data[1];
    uVar2 = net_local_adr.ip[2];
    Q_memset(NET_AdrToString::s,0,0x40);
    if (nVar3 == NA_LOOPBACK) {
      builtin_strncpy(NET_AdrToString::s,"loopback",9);
    }
    else if (nVar3 == NA_IP) {
      __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",(uint)auVar4 & 0xff,uVar1,uVar2
                     ,uVar10,(ushort)asStack_290[0].sa_data._0_2_ >> 8 |
                             asStack_290[0].sa_data._0_2_ << 8);
    }
    Con_Printf("Server IP address %s\n",NET_AdrToString::s);
    uVar5 = net_local_adr.port;
    auVar4 = net_local_adr.ip;
    nVar3 = net_local_adr.type;
    uVar10 = (uint)net_local_adr.ip >> 0x18;
    uVar1 = net_local_adr.ip[1];
    uVar2 = net_local_adr.ip[2];
    Q_memset(NET_AdrToString::s,0,0x40);
    if (nVar3 == NA_LOOPBACK) {
      builtin_strncpy(NET_AdrToString::s,"loopback",9);
    }
    else if (nVar3 == NA_IP) {
      __snprintf_chk(NET_AdrToString::s,0x40,1,0x40,"%i.%i.%i.%i:%i",(uint)auVar4 & 0xff,uVar1,uVar2
                     ,uVar10,uVar5 >> 8 | uVar5 << 8);
    }
    pcVar7 = va("%s",NET_AdrToString::s);
    Cvar_Set("net_address",pcVar7);
  }
  else {
    piVar9 = __errno_location();
    noip = true;
    pcVar7 = strerror(*piVar9);
    Con_Printf("Could not get TCP/IP address, TCP/IP disabled\nReason:  %s\n",pcVar7);
  }
LAB_000b2159:
  if (iStack_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CSteam3Server::OnGSClientApprove  @ 000ba300
/* DWARF original prototype: void OnGSClientApprove(CSteam3Server * this, GSClientApprove_t *
   pGSClientSteam2Accept) */

void __thiscall
CSteam3Server::OnGSClientApprove(CSteam3Server *this,GSClientApprove_t *pGSClientSteam2Accept)

{
  char cVar1;
  int iVar2;
  qboolean qVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  client_s *client;
  int in_GS_OFFSET;
  char local_210 [4];
  char acStack_20c [508];
  int local_10;
  
                    /* Unresolved local var: client_t.conflict * cl@[???] */
                    /* Unresolved local var: client_t.conflict * cl@[???]
                       Unresolved local var: int i@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = 0;
  client = svs.clients;
  if (0 < svs.maxclients) {
    do {
      if ((((client->connected != false) || (client->active != false)) || (client->spawned != false)
          ) && (((client->network_userid).idtype == 1 &&
                (*(int *)((int)&(client->network_userid).m_SteamID + 4) ==
                 *(int *)((int)&(pGSClientSteam2Accept->m_SteamID).m_steamid + 4) &&
                 (uint32)(client->network_userid).m_SteamID ==
                 (pGSClientSteam2Accept->m_SteamID).m_steamid.m_comp.m_unAccountID)))) {
        if (client != (client_t *)0x0) {
          qVar3 = SV_FilterUser(&client->network_userid);
          if (qVar3 == false) {
            iVar2 = SV_CheckForDuplicateSteamID(client);
            if (iVar2 == -1) {
                    /* Unresolved local var: char[512] msg@[???] */
              pcVar6 = SV_GetClientIDString(client);
              __snprintf_chk(local_210,0x200,1,0x200,"\"%s<%i><%s><>\" STEAM USERID validated\n",
                             client->name,client->userid,pcVar6);
              Con_DPrintf("%s",local_210);
              Log_Printf("%s",local_210);
            }
            else {
                    /* Unresolved local var: char[256] msg@[???] */
              uVar5 = 0;
              do {
                uVar4 = uVar5;
                *(undefined4 *)(local_210 + uVar4) =
                     *(undefined4 *)("Your UserID is already in use on this server.\n" + uVar4);
                uVar5 = uVar4 + 4;
              } while (uVar5 < 0x2c);
              cVar1 = "Your UserID is already in use on this server.\n"[uVar4 + 6];
              *(short *)(local_210 + uVar5) =
                   (short)*(undefined4 *)
                           ("Your UserID is already in use on this server.\n" + uVar4 + 4);
              acStack_20c[uVar4 + 2] = cVar1;
              SV_RejectConnection(&(client->netchan).remote_address,local_210);
              pcVar6 = SV_GetClientIDString(client);
              SV_DropClient(client,false,"STEAM UserID %s is already\nin use on this server\n",
                            pcVar6);
            }
          }
          else {
                    /* Unresolved local var: char[256] msg@[???] */
            uVar5 = 0;
            do {
              uVar4 = uVar5;
              *(undefined4 *)(local_210 + uVar4) =
                   *(undefined4 *)("You have been banned from this server\n" + uVar4);
              uVar5 = uVar4 + 4;
            } while (uVar5 < 0x24);
            cVar1 = "You have been banned from this server\n"[uVar4 + 6];
            *(short *)(local_210 + uVar5) =
                 (short)*(undefined4 *)("You have been banned from this server\n" + uVar4 + 4);
            acStack_20c[uVar4 + 2] = cVar1;
            SV_RejectConnection(&(client->netchan).remote_address,local_210);
            pcVar6 = SV_GetClientIDString(client);
            SV_DropClient(client,false,"STEAM UserID %s is in server ban list\n",pcVar6);
          }
        }
        break;
      }
      iVar2 = iVar2 + 1;
      client = client + 1;
    } while (svs.maxclients != iVar2);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CSteam3Server::OnGSClientDeny  @ 000bb260
/* DWARF original prototype: void OnGSClientDeny(CSteam3Server * this, GSClientDeny_t *
   pGSClientDeny) */

void __thiscall CSteam3Server::OnGSClientDeny(CSteam3Server *this,GSClientDeny_t *pGSClientDeny)

{
  client_s *cl;
  int iVar1;
  
                    /* Unresolved local var: client_t.conflict * cl@[???] */
                    /* Unresolved local var: client_t.conflict * cl@[???]
                       Unresolved local var: int i@[???] */
  if (0 < svs.maxclients) {
    iVar1 = 0;
    cl = svs.clients;
    do {
      if ((((cl->connected != false) || (cl->active != false)) || (cl->spawned != false)) &&
         (((cl->network_userid).idtype == 1 &&
          (*(int *)((int)&(cl->network_userid).m_SteamID + 4) ==
           *(int *)((int)&(pGSClientDeny->m_SteamID).m_steamid + 4) &&
           (uint32)(cl->network_userid).m_SteamID ==
           (pGSClientDeny->m_SteamID).m_steamid.m_comp.m_unAccountID)))) {
        if (cl == (client_s *)0x0) {
          return;
        }
        OnGSClientDenyHelper
                  (this,(client_t_conflict *)cl,pGSClientDeny->m_eDenyReason,
                   pGSClientDeny->m_rgchOptionalText);
        return;
      }
      iVar1 = iVar1 + 1;
      cl = cl + 1;
    } while (svs.maxclients != iVar1);
  }
  return;
}


// CSteam3Server::OnGSClientDenyHelper  @ 000baf50
/* DWARF original prototype: void OnGSClientDenyHelper(CSteam3Server * this, client_t.conflict * cl,
   EDenyReason eDenyReason, char * pchOptionalText) */

void __thiscall
CSteam3Server::OnGSClientDenyHelper
          (CSteam3Server *this,client_t_conflict *cl,EDenyReason eDenyReason,char *pchOptionalText)

{
  switch(eDenyReason) {
  default:
    goto switchD_000baf78_caseD_0;
  case k_EDenyInvalidVersion:
    Con_Printf("Client %s DENY REASON: k_EDenyInvalidVersion\n",cl->name);
    eDenyReason = (EDenyReason)s_Client_version_incompatible_with_000dd57c;
    break;
  case k_EDenyGeneric:
    Con_Printf("Client %s DENY REASON: k_EDenyGeneric\n",cl->name);
    goto switchD_000baf78_caseD_0;
  case k_EDenyNotLoggedOn:
    Con_Printf("Client %s DENY REASON: k_EDenyNotLoggedOn\n",cl->name);
    if (this->m_bLanOnly != false) {
      return;
    }
    eDenyReason = (EDenyReason)s_No_Steam_logon_000ddd69;
    break;
  case k_EDenyNoLicense:
    Con_Printf("Client %s DENY REASON: k_EDenyNoLicense\n",cl->name);
    eDenyReason = (EDenyReason)s_This_Steam_account_does_not_own_t_000dd684;
    break;
  case k_EDenyCheater:
    Con_Printf("Client %s DENY REASON: k_EDenyCheater\n",cl->name);
    eDenyReason = (EDenyReason)s_VAC_banned_from_secure_server_000dd704;
    break;
  case k_EDenyLoggedInElseWhere:
    Con_Printf("Client %s DENY REASON: k_EDenyLoggedInElseWhere\n",cl->name);
    if (this->m_bLanOnly != false) {
      return;
    }
    eDenyReason = (EDenyReason)s_This_Steam_account_is_being_used_000dd620;
    break;
  case k_EDenyUnknownText:
    Con_Printf("Client %s DENY REASON: k_EDenyUnknownText\n",cl->name);
    if ((pchOptionalText != (char *)0x0) &&
       (eDenyReason = (EDenyReason)pchOptionalText, *pchOptionalText != '\0')) break;
switchD_000baf78_caseD_0:
    eDenyReason = (EDenyReason)s_Client_dropped_by_server_000ddd79;
    break;
  case k_EDenyIncompatibleAnticheat:
    Con_Printf("Client %s DENY REASON: k_EDenyIncompatibleAnticheat\n",cl->name);
    eDenyReason = (EDenyReason)s_You_are_running_an_external_tool_000dd788;
    break;
  case k_EDenyMemoryCorruption:
    Con_Printf("Client %s DENY REASON: k_EDenyMemoryCorruption\n",cl->name);
    eDenyReason = (EDenyReason)s_Memory_corruption_detected__000ddd92;
    break;
  case k_EDenyIncompatibleSoftware:
    Con_Printf("Client %s DENY REASON: k_EDenyIncompatibleSoftware\n",cl->name);
    eDenyReason = (EDenyReason)s_You_are_running_software_that_is_000dd838;
    break;
  case k_EDenySteamConnectionLost:
    Con_Printf("Client %s DENY REASON: k_EDenySteamConnectionLost\n",cl->name);
    if (this->m_bLanOnly != false) {
      return;
    }
    eDenyReason = (EDenyReason)s_Steam_connection_lost_000dddae;
    break;
  case k_EDenySteamConnectionError:
    Con_Printf("Client %s DENY REASON: k_EDenySteamConnectionError\n",cl->name);
    if (this->m_bLanOnly != false) {
      return;
    }
    Con_Printf(
              "Steam auth rejected client \'%s\' (%llu) with reason SteamConnectionError, but we\'re ignoring that\n"
              );
    return;
  case k_EDenySteamResponseTimedOut:
    Con_Printf("Client %s DENY REASON: k_EDenySteamResponseTimedOut\n",cl->name);
    eDenyReason = (EDenyReason)s_Client_timed_out_while_answering_000dd984;
    break;
  case k_EDenySteamValidationStalled:
    Con_Printf("Client %s DENY REASON: k_EDenySteamValidationStalled\n",cl->name);
    if (this->m_bLanOnly != false) {
      *(undefined4 *)&(cl->network_userid).m_SteamID = 1;
      *(undefined4 *)((int)&(cl->network_userid).m_SteamID + 4) = 0;
    }
    return;
  }
  SV_DropClient((client_t *)cl,false,(char *)eDenyReason);
  return;
}


// CSteam3Server::OnGSClientKick  @ 000bb2f0
/* DWARF original prototype: void OnGSClientKick(CSteam3Server * this, GSClientKick_t *
   pGSClientKick) */

void __thiscall CSteam3Server::OnGSClientKick(CSteam3Server *this,GSClientKick_t *pGSClientKick)

{
  client_s *cl;
  int iVar1;
  
                    /* Unresolved local var: client_t.conflict * cl@[???] */
                    /* Unresolved local var: client_t.conflict * cl@[???]
                       Unresolved local var: int i@[???] */
  if (0 < svs.maxclients) {
    iVar1 = 0;
    cl = svs.clients;
    do {
      if ((((cl->connected != false) || (cl->active != false)) || (cl->spawned != false)) &&
         (((cl->network_userid).idtype == 1 &&
          (*(int *)((int)&(cl->network_userid).m_SteamID + 4) ==
           *(int *)((int)&(pGSClientKick->m_SteamID).m_steamid + 4) &&
           (uint32)(cl->network_userid).m_SteamID ==
           (pGSClientKick->m_SteamID).m_steamid.m_comp.m_unAccountID)))) {
        if (cl == (client_s *)0x0) {
          return;
        }
        OnGSClientDenyHelper(this,(client_t_conflict *)cl,pGSClientKick->m_eDenyReason,(char *)0x0);
        return;
      }
      iVar1 = iVar1 + 1;
      cl = cl + 1;
    } while (svs.maxclients != iVar1);
  }
  return;
}


// CSteam3Server::OnGSPolicyResponse  @ 000ba130
/* DWARF original prototype: void OnGSPolicyResponse(CSteam3Server * this, GSPolicyResponse_t *
   pPolicyResponse) */

void __thiscall
CSteam3Server::OnGSPolicyResponse(CSteam3Server *this,GSPolicyResponse_t *pPolicyResponse)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  cVar1 = (**(code **)(*(int *)*puVar2 + 0x24))((int *)*puVar2);
  if (cVar1 == '\0') {
    Con_Printf("   VAC secure mode disabled.\n");
    return;
  }
  Con_Printf("   VAC secure mode is activated.\n");
  return;
}


// CSteam3Server::OnLogonFailure  @ 000b9e90
/* DWARF original prototype: void OnLogonFailure(CSteam3Server * this, SteamServerConnectFailure_t *
   pLogonFailure) */

void __thiscall
CSteam3Server::OnLogonFailure(CSteam3Server *this,SteamServerConnectFailure_t *pLogonFailure)

{
  if ((this->super_CSteam3).m_bLogOnResult == false) {
    if (pLogonFailure->m_eResult == k_EResultServiceUnavailable) {
      if (this->m_bLanOnly == false) {
        Con_Printf("Connection to Steam servers successful (SU).\n");
        if (this->m_bWantToBeSecure != false) {
          Con_Printf("   VAC secure mode not available.\n");
        }
      }
    }
    else if (this->m_bLanOnly == false) {
      Con_Printf("Could not establish connection to Steam servers.\n");
      (this->super_CSteam3).m_bLogOnResult = true;
      return;
    }
  }
  (this->super_CSteam3).m_bLogOnResult = true;
  return;
}


// CSteam3Server::OnLogonSuccess  @ 000bbd50
/* DWARF original prototype: void OnLogonSuccess(CSteam3Server * this, SteamServersConnected_t *
   pLogonSuccess) */

void __thiscall
CSteam3Server::OnLogonSuccess(CSteam3Server *this,SteamServersConnected_t *pLogonSuccess)

{
  bool bVar1;
  undefined4 *puVar2;
  uint32 local_18;
  undefined4 local_14 [4];
  
  if ((this->super_CSteam3).m_bLogOnResult == false) {
    bVar1 = this->m_bLanOnly;
    (this->super_CSteam3).m_bLogOnResult = true;
    if (bVar1 == false) {
      Con_Printf("Connection to Steam servers successful.\n");
    }
  }
  else if (this->m_bLanOnly == false) {
    Con_Printf("Reconnected to Steam servers.\n");
  }
  puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  (**(code **)(*(int *)*puVar2 + 0x28))(local_14,(int *)*puVar2);
  (this->m_SteamIDGS).m_steamid.m_comp.m_unAccountID = local_18;
  *(undefined4 *)((int)&(this->m_SteamIDGS).m_steamid + 4) = local_14[0];
  SendUpdatedServerDetails(this);
  return;
}


// CSteam3Server::RunFrame  @ 000bc380
/* DWARF original prototype: void RunFrame(CSteam3Server * this) */

void __thiscall CSteam3Server::RunFrame(CSteam3Server *this)

{
  qboolean qVar1;
  netadr_t to;
  qboolean *pqVar2;
  char cVar3;
  CSteam3Server *in_EAX;
  undefined4 *puVar4;
  int *piVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int in_GS_OFFSET;
  bool bVar10;
  double dVar11;
  undefined4 uVar12;
  undefined4 local_1054;
  ushort local_103a;
  uint local_1038 [3];
  undefined4 local_102c;
  undefined4 local_1028;
  undefined4 local_1024;
  undefined1 local_1020 [4096];
  int local_20;
  
                    /* Unresolved local var: double fCurTime@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  dVar11 = Sys_FloatTime();
  if (1.0 < dVar11 - RunFrame::s_fLastRunFragsUpdate) {
                    /* Unresolved local var: bool bHasPlayers@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int maxplayers@[???]
                       Unresolved local var: bool iHasPW@[???] */
    if (svs.maxclients < 1) {
LAB_000bc437:
      bVar10 = false;
    }
    else {
      if (((svs.clients)->active == false) && ((svs.clients)->spawned == false)) {
        iVar7 = 0;
        qVar1 = (svs.clients)->connected;
        pqVar2 = &svs.clients[1].connected;
        while (qVar1 == false) {
          iVar7 = iVar7 + 1;
          if (iVar7 == svs.maxclients) goto LAB_000bc437;
          if ((((client_s *)(pqVar2 + -3))->active != false) || (pqVar2[-2] != false)) break;
          qVar1 = *pqVar2;
          pqVar2 = pqVar2 + 0x199a;
        }
      }
      bVar10 = true;
    }
    RunFrame::s_fLastRunFragsUpdate = dVar11;
    in_EAX->m_bHasActivePlayers = bVar10;
    bVar10 = false;
    SendUpdatedServerDetails(in_EAX);
    if (*sv_password.string != '\0') {
      iVar7 = Q_stricmp(sv_password.string,"none");
      bVar10 = iVar7 != 0;
    }
    iVar9 = 0;
    puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    iVar8 = 0;
    (**(code **)(*(int *)*puVar4 + 0x40))((int *)*puVar4,bVar10);
    iVar7 = svs.maxclients;
    if (0 < svs.maxclients) {
      do {
        if (*(int *)(((svs.clients)->netchan).remote_address.ip + iVar8 + -0x24) != 0) {
          puVar4 = (undefined4 *)
                   SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
          local_1054 = (undefined4)
                       (longlong)
                       ROUND(*(float *)(*(int *)((svs.clients)->userinfo + iVar8 + -0x1c) + 0x1e4));
          (**(code **)(*(int *)*puVar4 + 0xa4))
                    ((int *)*puVar4,*(undefined4 *)((svs.clients)->userinfo + iVar8 + -0xc),
                     *(undefined4 *)((svs.clients)->userinfo + iVar8 + -8),
                     (svs.clients)->name + iVar8,local_1054);
          iVar7 = svs.maxclients;
        }
        iVar9 = iVar9 + 1;
        iVar8 = iVar8 + 0x6668;
      } while (iVar9 < iVar7);
    }
    puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    cVar3 = (**(code **)(*(int *)*puVar4 + 0x2c))((int *)*puVar4);
    if (cVar3 != '\0') {
      uVar12 = 3;
      Con_Printf("%cMasterRequestRestart\n",3);
      iVar7 = COM_CheckParm("-autoupdate");
      if (iVar7 == 0) {
        Con_Printf("Your server needs to be restarted in order to receive the latest update.\n",
                   uVar12);
        Log_Printf("Your server needs to be restarted in order to receive the latest update.\n");
      }
      else {
        Con_Printf("Your server will be restarted on map change.\n",uVar12);
        Log_Printf("Your server will be restarted on map change.\n");
        g_bOutOfDateRestart = true;
      }
    }
  }
  if (0.1 < dVar11 - RunFrame::s_fLastRunCallback) {
    SteamGameServer_RunCallbacks();
    RunFrame::s_fLastRunCallback = dVar11;
  }
  if (0.01 < dVar11 - RunFrame::s_fLastRunSendPackets) {
    RunFrame::s_fLastRunSendPackets = dVar11;
                    /* Unresolved local var: uint16 port@[???]
                       Unresolved local var: uint32 ip@[???]
                       Unresolved local var: char[4096] szOutBuf@[???]
                       Unresolved local var: int iLen@[???] */
    puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    piVar5 = (int *)*puVar4;
    iVar7 = *piVar5;
    while (iVar7 = (**(code **)(iVar7 + 0x8c))(piVar5,local_1020,0x1000,local_1038,&local_103a),
          0 < iVar7) {
                    /* Unresolved local var: netadr_t.conflict netAdr@[???]
                       Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
      local_1038[0] =
           local_1038[0] >> 0x18 | (local_1038[0] & 0xff0000) >> 8 | (local_1038[0] & 0xff00) << 8 |
           local_1038[0] << 0x18;
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
      uVar6 = local_103a >> 8 | local_103a << 8;
      local_1024 = CONCAT22(uVar6,(undefined2)local_1024);
      uVar12 = local_1024;
      local_1038[1] = 3;
      to.ip[0] = (char)local_1038[0];
      to.ip[1] = (char)(local_1038[0] >> 8);
      to.ip[2] = (char)(local_1038[0] >> 0x10);
      to.ip[3] = (char)(local_1038[0] >> 0x18);
      to.type = 3;
      to.ipx[0] = (undefined1)local_102c;
      to.ipx[1] = local_102c._1_1_;
      to.ipx[2] = local_102c._2_1_;
      to.ipx[3] = local_102c._3_1_;
      to.ipx[4] = (undefined1)local_1028;
      to.ipx[5] = local_1028._1_1_;
      to.ipx[6] = local_1028._2_1_;
      to.ipx[7] = local_1028._3_1_;
      to.ipx[8] = (undefined1)local_1024;
      to.ipx[9] = local_1024._1_1_;
      to.port = uVar6;
      local_1038[2] = local_1038[0];
      local_1024 = uVar12;
      NET_SendPacket(NS_SERVER,iVar7,local_1020,to);
      puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext)
      ;
      piVar5 = (int *)*puVar4;
      iVar7 = *piVar5;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CSteam3Server::RunFrame  @ 000bc740
/* DWARF original prototype: void RunFrame(CSteam3Server * this) */

void __thiscall CSteam3Server::RunFrame(CSteam3Server *this)

{
                    /* Unresolved local var: double fCurTime@[???] */
  if (1 < svs.maxclients) {
    RunFrame(this);
    return;
  }
  return;
}


// CSteam3Server::SendUpdatedServerDetails  @ 000bbc50
/* DWARF original prototype: void SendUpdatedServerDetails(CSteam3Server * this) */

void __thiscall CSteam3Server::SendUpdatedServerDetails(CSteam3Server *this)

{
  int *piVar1;
  code *pcVar2;
  client_s *pcVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: int bot@[???]
                       Unresolved local var: int maxplayers@[???] */
                    /* Unresolved local var: int i@[???] */
  if (svs.maxclients < 1) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    pcVar3 = svs.clients;
    do {
      if (((pcVar3->active != false) || (pcVar3->spawned != false)) || (pcVar3->connected != false))
      {
        iVar6 = (iVar6 + 1) - (uint)(pcVar3->fakeclient == false);
      }
      pcVar3 = pcVar3 + 1;
    } while (pcVar3 != svs.clients + svs.maxclients);
  }
  iVar7 = svs.maxclients;
  if (-1 < (int)sv_visiblemaxplayers.value) {
    iVar7 = (int)sv_visiblemaxplayers.value;
  }
  puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  (**(code **)(*(int *)*puVar4 + 0x30))((int *)*puVar4,iVar7);
  puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  (**(code **)(*(int *)*puVar4 + 0x34))((int *)*puVar4,iVar6);
  puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  piVar1 = (int *)*puVar4;
  pcVar2 = *(code **)(*piVar1 + 0x38);
  pcVar5 = Cvar_VariableString("hostname");
  (*pcVar2)(piVar1,pcVar5);
  puVar4 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
  (**(code **)(*(int *)*puVar4 + 0x3c))((int *)*puVar4,0x4ff2a8);
  return;
}


// CSteam3Server::Shutdown  @ 000ba520
/* DWARF original prototype: void Shutdown(CSteam3Server * this) */

void __thiscall CSteam3Server::Shutdown(CSteam3Server *this)

{
  int *piVar1;
  undefined4 *puVar2;
  
  if ((this->super_CSteam3).m_bLoggedOn != false) {
                    /* Unresolved local var: ISteamNetworkingSockets * pSteamNetworkingSockets@[???]
                        */
    piVar1 = (int *)SteamInternal_ContextInit
                              (SteamGameServerNetworkingSockets_SteamAPI::
                               s_CallbackCounterAndContext_1);
    if (*piVar1 != 0) {
                    /* Unresolved local var: bool bLanOnly@[???] */
      if (sv_lan.value <= 0.0) {
                    /* Unresolved local var: bool bLanOnly@[???] */
        PF_IsDedicatedServer();
      }
      if (ip_fakeudpports[1] != (ISteamNetworkingFakeUDPPort *)0x0) {
        (*(code *)**(undefined4 **)ip_fakeudpports[1])(ip_fakeudpports[1]);
        ip_fakeudpports[1] = (ISteamNetworkingFakeUDPPort *)0x0;
      }
    }
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar2 + 0x60))((int *)*puVar2,0);
    puVar2 = (undefined4 *)SteamInternal_ContextInit(SteamGameServer::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar2 + 0x1c))((int *)*puVar2);
    SteamGameServer_Shutdown();
                    /* Unresolved local var: int i@[???] */
    (this->super_CSteam3).m_bLoggedOn = false;
    g_arFakePorts[0] = 0;
    g_nFakeIP = 0;
    if (ip_sockets[1] != 0) {
      NET_GetLocalAddress();
      return;
    }
  }
  return;
}


// CSteam3Server::~CSteam3Server  @ 000bf0e0
/* DWARF original prototype: void ~CSteam3Server(CSteam3Server * this, int __in_chrg) */

void __thiscall CSteam3Server::~CSteam3Server(CSteam3Server *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->m_CallbackFakeIPResult).super_CCallbackImpl<160>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Server_000de854;
  (this->m_CallbackFakeIPResult).super_CCallbackImpl<160>.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de758;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackFakeIPResult);
  }
  bVar1 = (this->m_CallbackLogonFailure).super_CCallbackImpl<8>.super_CCallbackBase.m_nCallbackFlags
  ;
  (this->m_CallbackLogonFailure).super_CCallbackImpl<8>.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de720;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackLogonFailure);
  }
  bVar1 = (this->m_CallbackLogonSuccess).super_CCallbackImpl<1>.super_CCallbackBase.m_nCallbackFlags
  ;
  (this->m_CallbackLogonSuccess).super_CCallbackImpl<1>.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de6cc;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackLogonSuccess);
  }
  bVar1 = (this->m_CallbackGSPolicyResponse).super_CCallbackImpl<1>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGSPolicyResponse).super_CCallbackImpl<1>.super_CCallbackBase._vptr_CCallbackBase
       = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de6cc;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSPolicyResponse);
  }
  bVar1 = (this->m_CallbackGSClientKick).super_CCallbackImpl<12>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGSClientKick).super_CCallbackImpl<12>.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de694;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSClientKick);
  }
  bVar1 = (this->m_CallbackGSClientDeny).super_CCallbackImpl<140>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGSClientDeny).super_CCallbackImpl<140>.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de65c;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSClientDeny);
  }
  bVar1 = (this->m_CallbackGSClientApprove).super_CCallbackImpl<16>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGSClientApprove).super_CCallbackImpl<16>.super_CCallbackBase._vptr_CCallbackBase
       = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de624;
  if ((bVar1 & 1) == 0) {
    return;
  }
  SteamAPI_UnregisterCallback();
  return;
}


// CSteam3Server::~CSteam3Server  @ 000bf550
/* DWARF original prototype: void ~CSteam3Server(CSteam3Server * this, int __in_chrg) */

void __thiscall CSteam3Server::~CSteam3Server(CSteam3Server *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->m_CallbackFakeIPResult).super_CCallbackImpl<160>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Server_000de854;
  (this->m_CallbackFakeIPResult).super_CCallbackImpl<160>.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de758;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackFakeIPResult);
  }
  bVar1 = (this->m_CallbackLogonFailure).super_CCallbackImpl<8>.super_CCallbackBase.m_nCallbackFlags
  ;
  (this->m_CallbackLogonFailure).super_CCallbackImpl<8>.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de720;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackLogonFailure);
  }
  bVar1 = (this->m_CallbackLogonSuccess).super_CCallbackImpl<1>.super_CCallbackBase.m_nCallbackFlags
  ;
  (this->m_CallbackLogonSuccess).super_CCallbackImpl<1>.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de6cc;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackLogonSuccess);
  }
  bVar1 = (this->m_CallbackGSPolicyResponse).super_CCallbackImpl<1>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGSPolicyResponse).super_CCallbackImpl<1>.super_CCallbackBase._vptr_CCallbackBase
       = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de6cc;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSPolicyResponse);
  }
  bVar1 = (this->m_CallbackGSClientKick).super_CCallbackImpl<12>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGSClientKick).super_CCallbackImpl<12>.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de694;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSClientKick);
  }
  bVar1 = (this->m_CallbackGSClientDeny).super_CCallbackImpl<140>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGSClientDeny).super_CCallbackImpl<140>.super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_000de65c;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSClientDeny);
  }
  bVar1 = (this->m_CallbackGSClientApprove).super_CCallbackImpl<16>.super_CCallbackBase.
          m_nCallbackFlags;
  (this->m_CallbackGSClientApprove).super_CCallbackImpl<16>.super_CCallbackBase._vptr_CCallbackBase
       = (_func_int_varargs **)&PTR___cxa_pure_virtual_000de624;
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSClientApprove);
  }
  operator_delete(this);
  return;
}


// CSteamID::BValidExternalSteamID  @ 000c4800
/* DWARF original prototype: bool BValidExternalSteamID(CSteamID * this) */

bool __thiscall CSteamID::BValidExternalSteamID(CSteamID *this)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  bool bVar4;
  
  bVar1 = *(byte *)((int)&this->m_steamid + 6);
  bVar3 = bVar1 & 0xf0;
  if (bVar3 == 0x50) {
    return false;
  }
  bVar4 = (bVar1 & 0xd0) != 0x40;
  bVar2 = bVar3 != 0xa0 && bVar4;
  if (bVar3 != 0xa0 && bVar4) {
    if ((this->m_steamid).m_comp.m_unAccountID == 0) {
      bVar2 = (*(byte *)((int)&this->m_steamid + 6) & 0xf) != 0 ||
              *(short *)((int)&this->m_steamid + 4) != 0;
    }
    return bVar2;
  }
  return true;
}


// CSteamID::CSteamID  @ 000c3ab0
/* DWARF original prototype: void CSteamID(CSteamID * this, char * pchSteamID, EUniverse
   eDefaultUniverse) */

void __thiscall CSteamID::CSteamID(CSteamID *this,char *pchSteamID,EUniverse eDefaultUniverse)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  uint32 local_28;
  undefined4 local_24;
  EUniverse local_20 [4];
  
                    /* Unresolved local var: uint32 nAccountID@[???]
                       Unresolved local var: uint32 nInstance@[???]
                       Unresolved local var: EUniverse eUniverse@[???]
                       Unresolved local var: EAccountType eAccountType@[???] */
  local_28 = 0;
  local_24 = 1;
  cVar1 = *pchSteamID;
  local_20[0] = eDefaultUniverse;
  if (cVar1 == '[') {
    cVar1 = pchSteamID[1];
    pchSteamID = pchSteamID + 1;
  }
  if (cVar1 == 'A') {
                    /* Unresolved local var: char * pchColon@[???] */
    if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
      pcVar2 = pchSteamID + 2;
    }
    else {
      pcVar2 = pchSteamID + 1;
    }
    pcVar3 = strchr(pcVar2,0x28);
    if (pcVar3 != (char *)0x0) {
      sscanf(pcVar3,"(%u)",&local_24);
    }
    pcVar3 = strchr(pcVar2,0x3a);
    if (pcVar3 == (char *)0x0) {
      sscanf(pcVar2,"%u",&local_28);
    }
    else if ((*pcVar3 == '\0') || (pcVar3 = strchr(pcVar3 + 1,0x3a), pcVar3 == (char *)0x0)) {
      sscanf(pcVar2,"%u:%u",local_20,&local_28);
    }
    else {
      sscanf(pcVar2,"%u:%u:%u",local_20,&local_28,&local_24);
    }
    if (local_28 == 0) {
      (this->m_steamid).m_comp.m_unAccountID = 0;
      *(undefined1 *)((int)&this->m_steamid + 4) = 0;
      *(undefined1 *)((int)&this->m_steamid + 5) = 0;
      (this->m_steamid).m_comp.m_EUniverse = (byte)local_20[0];
      *(undefined1 *)((int)&this->m_steamid + 6) = 0x40;
      return;
    }
    (this->m_steamid).m_comp.m_unAccountID = local_28;
    *(char *)((int)&this->m_steamid + 4) = (char)local_24;
    (this->m_steamid).m_comp.m_EUniverse = (byte)local_20[0];
    *(char *)((int)&this->m_steamid + 5) = (char)((uint)local_24 >> 8);
    *(byte *)((int)&this->m_steamid + 6) = (byte)((uint)local_24 >> 0x10) & 0xf | 0x40;
    return;
  }
  if (cVar1 == 'G') {
    if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\x03';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\x03';
    }
  }
  else if (cVar1 == 'C') {
    if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\x06';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\x06';
    }
  }
  else if (cVar1 == 'g') {
    local_24 = 0;
    if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\a';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\a';
    }
  }
  else {
    if (cVar1 == 'c') {
      local_24 = 0x80000;
      cVar1 = pchSteamID[1];
    }
    else if (cVar1 == 'L') {
      local_24 = 0x40000;
      cVar1 = pchSteamID[1];
    }
    else {
      if (cVar1 != 'T') {
        if (cVar1 == 'U') {
          if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
            pchSteamID = pchSteamID + 2;
            cVar4 = '\x01';
          }
          else {
            pchSteamID = pchSteamID + 1;
            cVar4 = '\x01';
          }
        }
        else {
          cVar4 = '\x01';
          if (cVar1 == 'i') {
            if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
              pchSteamID = pchSteamID + 2;
              cVar4 = '\0';
            }
            else {
              pchSteamID = pchSteamID + 1;
              cVar4 = '\0';
            }
          }
        }
        goto LAB_000c3b40;
      }
      cVar1 = pchSteamID[1];
      local_24 = 0;
    }
    if ((cVar1 == '-') || (cVar1 == ':')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\b';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\b';
    }
  }
LAB_000c3b40:
  pcVar2 = strchr(pchSteamID,0x3a);
  if (pcVar2 == (char *)0x0) {
    sscanf(pchSteamID,"%u",&local_28);
  }
  else {
    sscanf(pchSteamID + (*pchSteamID == '['),"%u:%u",local_20,&local_28);
    if (local_20[0] == k_EUniverseInvalid) {
      local_20[0] = eDefaultUniverse;
    }
  }
  (this->m_steamid).m_comp.m_EUniverse = (byte)local_20[0];
  *(char *)((int)&this->m_steamid + 4) = (char)local_24;
  (this->m_steamid).m_comp.m_unAccountID = local_28;
  *(char *)((int)&this->m_steamid + 5) = (char)((uint)local_24 >> 8);
  *(byte *)((int)&this->m_steamid + 6) = cVar4 << 4 | (byte)((uint)local_24 >> 0x10) & 0xf;
  return;
}


// CSteamID::Render  @ 000c42b0
/* DWARF original prototype: char * Render(CSteamID * this) */

char * __thiscall CSteamID::Render(CSteamID *this)

{
  char (*pacVar1) [37];
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  byte bVar5;
  uint32 uVar6;
  
                    /* Unresolved local var: int k_cBufLen@[???]
                       Unresolved local var: int k_cBufs@[???]
                       Unresolved local var: char * pchBuf@[???] */
  pacVar1 = Render::rgchBuf + Render::nBuf;
  Render::nBuf = (Render::nBuf + 1) % 4;
  bVar2 = *(byte *)((int)&this->m_steamid + 6) & 0xf0;
  if (bVar2 == 0x40) {
    uVar3 = (*(byte *)((int)&this->m_steamid + 6) & 0xf) << 0x10 |
            (uint)*(ushort *)((int)&this->m_steamid + 4);
    uVar6 = (this->m_steamid).m_comp.m_unAccountID;
    bVar2 = (this->m_steamid).m_comp.m_EUniverse;
    pcVar4 = "[A:%u:%u:%u]";
LAB_000c4406:
    __snprintf_chk(pacVar1,0x25,1,0xffffffff,pcVar4,bVar2,uVar6,uVar3);
    return *pacVar1;
  }
  if (bVar2 == 0x30) {
    uVar6 = (this->m_steamid).m_comp.m_unAccountID;
    bVar5 = (this->m_steamid).m_comp.m_EUniverse;
    pcVar4 = "[G:%u:%u]";
  }
  else {
    if (bVar2 == 0x20) {
      uVar3 = (*(byte *)((int)&this->m_steamid + 6) & 0xf) << 0x10 |
              (uint)*(ushort *)((int)&this->m_steamid + 4);
      uVar6 = (this->m_steamid).m_comp.m_unAccountID;
      bVar2 = (this->m_steamid).m_comp.m_EUniverse;
      pcVar4 = "[M:%u:%u:%u]";
      goto LAB_000c4406;
    }
    if (bVar2 == 0x50) {
      uVar6 = (this->m_steamid).m_comp.m_unAccountID;
      bVar5 = (this->m_steamid).m_comp.m_EUniverse;
      pcVar4 = "[P:%u:%u]";
    }
    else if (bVar2 == 0x60) {
      uVar6 = (this->m_steamid).m_comp.m_unAccountID;
      bVar5 = (this->m_steamid).m_comp.m_EUniverse;
      pcVar4 = "[C:%u:%u]";
    }
    else if (bVar2 == 0x70) {
      uVar6 = (this->m_steamid).m_comp.m_unAccountID;
      bVar5 = (this->m_steamid).m_comp.m_EUniverse;
      pcVar4 = "[g:%u:%u]";
    }
    else if (bVar2 == 0x80) {
      bVar2 = *(byte *)((int)&this->m_steamid + 6);
      if ((bVar2 & 8) == 0) {
        uVar6 = (this->m_steamid).m_comp.m_unAccountID;
        bVar5 = (this->m_steamid).m_comp.m_EUniverse;
        if ((bVar2 & 4) == 0) {
          pcVar4 = "[T:%u:%u]";
        }
        else {
          pcVar4 = "[L:%u:%u]";
        }
      }
      else {
        uVar6 = (this->m_steamid).m_comp.m_unAccountID;
        bVar5 = (this->m_steamid).m_comp.m_EUniverse;
        pcVar4 = "[c:%u:%u]";
      }
    }
    else if (bVar2 == 0) {
      uVar6 = (this->m_steamid).m_comp.m_unAccountID;
      bVar5 = (this->m_steamid).m_comp.m_EUniverse;
      pcVar4 = "[I:%u:%u]";
    }
    else if (bVar2 == 0x10) {
      uVar6 = (this->m_steamid).m_comp.m_unAccountID;
      bVar5 = (this->m_steamid).m_comp.m_EUniverse;
      pcVar4 = "[U:%u:%u]";
    }
    else {
      uVar6 = (this->m_steamid).m_comp.m_unAccountID;
      bVar5 = (this->m_steamid).m_comp.m_EUniverse;
      if (bVar2 == 0xa0) {
        pcVar4 = "[a:%u:%u]";
      }
      else {
        pcVar4 = "[i:%u:%u]";
      }
    }
  }
  __snprintf_chk(pacVar1,0x25,1,0xffffffff,pcVar4,bVar5,uVar6);
  return *pacVar1;
}


// CSteamID::Render  @ 000c4580
char * __thiscall CSteamID::Render(CSteamID *this,uint64 ulSteamID)

{
  char (*pacVar1) [37];
  byte bVar2;
  char *pcVar3;
  
                    /* Unresolved local var: CSteamID steamID@[???] */
                    /* Unresolved local var: int k_cBufLen@[???]
                       Unresolved local var: int k_cBufs@[???]
                       Unresolved local var: char * pchBuf@[???] */
  pacVar1 = Render::rgchBuf + Render::nBuf;
  Render::nBuf = (Render::nBuf + 1) % 4;
  bVar2 = (byte)(ulSteamID >> 0x10) & 0xf0;
  if (bVar2 == 0x40) {
    pcVar3 = "[A:%u:%u:%u]";
LAB_000c469f:
    __snprintf_chk(pacVar1,0x25,1,0xffffffff,pcVar3,(uint)ulSteamID >> 0x18,this,
                   (uint)ulSteamID & 0xfffff);
    return *pacVar1;
  }
  if (bVar2 == 0x30) {
    pcVar3 = "[G:%u:%u]";
  }
  else {
    if (bVar2 == 0x20) {
      pcVar3 = "[M:%u:%u:%u]";
      goto LAB_000c469f;
    }
    if (bVar2 == 0x50) {
      pcVar3 = "[P:%u:%u]";
    }
    else if (bVar2 == 0x60) {
      pcVar3 = "[C:%u:%u]";
    }
    else if (bVar2 == 0x70) {
                    /* catch() { ... } // from try @ 000c47d4 with catch @ 000c47a0
                       catch() { ... } // from try @ 000c4b23 with catch @ 000c47a0 */
      pcVar3 = "[g:%u:%u]";
    }
    else if (bVar2 == 0x80) {
      if ((ulSteamID & 0x80000) == 0) {
        if ((ulSteamID & 0x40000) == 0) {
          pcVar3 = "[T:%u:%u]";
        }
        else {
          pcVar3 = "[L:%u:%u]";
        }
      }
      else {
        pcVar3 = "[c:%u:%u]";
      }
    }
    else if ((ulSteamID & 0xf00000) == 0) {
      pcVar3 = "[I:%u:%u]";
    }
    else if (bVar2 == 0x10) {
                    /* try { // try from 000c47e4 to 000d49f8 has its CatchHandler @ 000c4b07 */
      pcVar3 = "[U:%u:%u]";
    }
    else if (bVar2 == 0xa0) {
      pcVar3 = "[a:%u:%u]";
    }
    else {
      pcVar3 = "[i:%u:%u]";
    }
  }
  __snprintf_chk(pacVar1,0x25,1,0xffffffff,pcVar3,(uint)ulSteamID >> 0x18,this);
  return *pacVar1;
}


// CSteamID::SetFromString  @ 000c3eb0
/* DWARF original prototype: void SetFromString(CSteamID * this, char * pchSteamID, EUniverse
   eDefaultUniverse) */

void __thiscall CSteamID::SetFromString(CSteamID *this,char *pchSteamID,EUniverse eDefaultUniverse)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  uint32 local_28;
  undefined4 local_24;
  EUniverse local_20 [4];
  
                    /* Unresolved local var: uint32 nAccountID@[???]
                       Unresolved local var: uint32 nInstance@[???]
                       Unresolved local var: EUniverse eUniverse@[???]
                       Unresolved local var: EAccountType eAccountType@[???] */
  local_28 = 0;
  local_24 = 1;
  cVar1 = *pchSteamID;
  local_20[0] = eDefaultUniverse;
  if (cVar1 == '[') {
    cVar1 = pchSteamID[1];
    pchSteamID = pchSteamID + 1;
  }
  if (cVar1 == 'A') {
                    /* Unresolved local var: char * pchColon@[???] */
    if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
      pcVar2 = pchSteamID + 2;
    }
    else {
      pcVar2 = pchSteamID + 1;
    }
    pcVar3 = strchr(pcVar2,0x28);
    if (pcVar3 != (char *)0x0) {
      sscanf(pcVar3,"(%u)",&local_24);
    }
    pcVar3 = strchr(pcVar2,0x3a);
    if (pcVar3 == (char *)0x0) {
      sscanf(pcVar2,"%u",&local_28);
    }
    else if ((*pcVar3 == '\0') || (pcVar3 = strchr(pcVar3 + 1,0x3a), pcVar3 == (char *)0x0)) {
      sscanf(pcVar2,"%u:%u",local_20,&local_28);
    }
    else {
      sscanf(pcVar2,"%u:%u:%u",local_20,&local_28,&local_24);
    }
    if (local_28 == 0) {
      (this->m_steamid).m_comp.m_unAccountID = 0;
      *(undefined1 *)((int)&this->m_steamid + 4) = 0;
      *(undefined1 *)((int)&this->m_steamid + 5) = 0;
      (this->m_steamid).m_comp.m_EUniverse = (byte)local_20[0];
      *(undefined1 *)((int)&this->m_steamid + 6) = 0x40;
      return;
    }
    (this->m_steamid).m_comp.m_unAccountID = local_28;
    *(char *)((int)&this->m_steamid + 4) = (char)local_24;
    (this->m_steamid).m_comp.m_EUniverse = (byte)local_20[0];
    *(char *)((int)&this->m_steamid + 5) = (char)((uint)local_24 >> 8);
    *(byte *)((int)&this->m_steamid + 6) = (byte)((uint)local_24 >> 0x10) & 0xf | 0x40;
    return;
  }
  if (cVar1 == 'G') {
    if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\x03';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\x03';
    }
  }
  else if (cVar1 == 'C') {
    if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\x06';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\x06';
    }
  }
  else if (cVar1 == 'g') {
    local_24 = 0;
    if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\a';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\a';
    }
  }
  else {
    if (cVar1 == 'c') {
      local_24 = 0x80000;
      cVar1 = pchSteamID[1];
    }
    else if (cVar1 == 'L') {
      local_24 = 0x40000;
      cVar1 = pchSteamID[1];
    }
    else {
      if (cVar1 != 'T') {
        if (cVar1 == 'U') {
          if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
            pchSteamID = pchSteamID + 2;
            cVar4 = '\x01';
          }
          else {
            pchSteamID = pchSteamID + 1;
            cVar4 = '\x01';
          }
        }
        else {
          cVar4 = '\x01';
          if (cVar1 == 'i') {
            if ((pchSteamID[1] == '-') || (pchSteamID[1] == ':')) {
              pchSteamID = pchSteamID + 2;
              cVar4 = '\0';
            }
            else {
              pchSteamID = pchSteamID + 1;
              cVar4 = '\0';
            }
          }
        }
        goto LAB_000c3f40;
      }
      cVar1 = pchSteamID[1];
      local_24 = 0;
    }
    if ((cVar1 == '-') || (cVar1 == ':')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\b';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\b';
    }
  }
LAB_000c3f40:
  pcVar2 = strchr(pchSteamID,0x3a);
  if (pcVar2 == (char *)0x0) {
    sscanf(pchSteamID,"%u",&local_28);
  }
  else {
    sscanf(pchSteamID + (*pchSteamID == '['),"%u:%u",local_20,&local_28);
    if (local_20[0] == k_EUniverseInvalid) {
      local_20[0] = eDefaultUniverse;
    }
  }
  (this->m_steamid).m_comp.m_EUniverse = (byte)local_20[0];
  *(char *)((int)&this->m_steamid + 4) = (char)local_24;
  (this->m_steamid).m_comp.m_unAccountID = local_28;
  *(char *)((int)&this->m_steamid + 5) = (char)((uint)local_24 >> 8);
  *(byte *)((int)&this->m_steamid + 6) = cVar4 << 4 | (byte)((uint)local_24 >> 0x10) & 0xf;
  return;
}


// CUtlBuffer::CUtlBuffer  @ 000c4c80
/* DWARF original prototype: void CUtlBuffer(CUtlBuffer * this, int growSize, int initSize, bool
   text) */

void __thiscall CUtlBuffer::CUtlBuffer(CUtlBuffer *this,int growSize,int initSize,bool text)

{
  uchar *puVar1;
  
  (this->m_Memory).m_pMemory = (uchar *)0x0;
  (this->m_Memory).m_NumAllocated = initSize;
  (this->m_Memory).m_GrowSize = growSize;
  if (initSize != 0) {
    puVar1 = malloc(initSize);
    (this->m_Memory).m_pMemory = puVar1;
  }
  this->m_Error = '\0';
  this->m_Get = 0;
  this->m_Put = 0;
  this->m_Flags = text;
  return;
}


// CUtlBuffer::CUtlBuffer  @ 000c4ce0
/* DWARF original prototype: void CUtlBuffer(CUtlBuffer * this, void * pBuffer, int size, bool text)
    */

void __thiscall CUtlBuffer::CUtlBuffer(CUtlBuffer *this,void *pBuffer,int size,bool text)

{
  (this->m_Memory).m_GrowSize = -1;
  (this->m_Memory).m_pMemory = pBuffer;
  this->m_Error = '\0';
  this->m_Get = 0;
  this->m_Put = 0;
  (this->m_Memory).m_NumAllocated = size;
  this->m_Flags = text;
  return;
}


// CUtlBuffer::CheckGet  @ 000c4f90
/* DWARF original prototype: bool CheckGet(CUtlBuffer * this, int size) */

bool __thiscall CUtlBuffer::CheckGet(CUtlBuffer *this,int size)

{
  bool bVar1;
  
  bVar1 = false;
  if ((this->m_Error == '\0') &&
     (bVar1 = true, (this->m_Memory).m_NumAllocated < size + this->m_Get)) {
    this->m_Error = '\x02';
    bVar1 = false;
  }
  return bVar1;
}


// CUtlBuffer::CheckPut  @ 000c55e0
/* DWARF original prototype: bool CheckPut(CUtlBuffer * this, int size) */

bool __thiscall CUtlBuffer::CheckPut(CUtlBuffer *this,int size)

{
  bool bVar1;
  int iVar2;
  size_t __size;
  uchar *puVar3;
  int iVar4;
  int iVar5;
  
  bVar1 = false;
  if (this->m_Error == '\0') {
                    /* Unresolved local var: int growSize@[???] */
    iVar5 = this->m_Put + size;
    while (iVar2 = (this->m_Memory).m_NumAllocated, iVar2 < iVar5) {
      while( true ) {
        iVar4 = (this->m_Memory).m_GrowSize;
        if (iVar4 < 0) {
          this->m_Error = this->m_Error | 1;
          return false;
        }
        if ((iVar4 == 0) && (iVar4 = 1, iVar2 != 0)) {
          iVar4 = iVar2;
        }
        __size = iVar2 + iVar4;
                    /* Unresolved local var: int growSize@[???] */
        puVar3 = (this->m_Memory).m_pMemory;
        (this->m_Memory).m_NumAllocated = __size;
        if (puVar3 == (uchar *)0x0) break;
        puVar3 = realloc(puVar3,__size);
        iVar5 = this->m_Put + size;
        (this->m_Memory).m_pMemory = puVar3;
        iVar2 = (this->m_Memory).m_NumAllocated;
        if (iVar5 <= iVar2) goto LAB_000c563d;
      }
      puVar3 = malloc(__size);
      (this->m_Memory).m_pMemory = puVar3;
    }
LAB_000c563d:
    bVar1 = true;
  }
  return bVar1;
}


// CUtlBuffer::EatWhiteSpace  @ 000c4e20
/* DWARF original prototype: void EatWhiteSpace(CUtlBuffer * this) */

void __thiscall CUtlBuffer::EatWhiteSpace(CUtlBuffer *this)

{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  
  if (((this->m_Flags & 1) != 0) && (this->m_Error == '\0')) {
    iVar1 = (this->m_Memory).m_NumAllocated;
                    /* Unresolved local var: int lastpos@[???] */
    iVar4 = this->m_Get;
    if (iVar4 < iVar1) {
      puVar2 = (this->m_Memory).m_pMemory;
      do {
        iVar3 = isspace((int)(char)puVar2[iVar4]);
        if (iVar3 == 0) {
          return;
        }
        iVar4 = iVar4 + 1;
        this->m_Get = iVar4;
      } while (iVar4 < iVar1);
    }
  }
  return;
}


// CUtlBuffer::EnsureCapacity  @ 000c4d20
/* DWARF original prototype: void EnsureCapacity(CUtlBuffer * this, int num) */

void __thiscall CUtlBuffer::EnsureCapacity(CUtlBuffer *this,int num)

{
  uchar *puVar1;
  
                    /* Unresolved local var: int growSize@[???] */
  if (((this->m_Memory).m_NumAllocated < num) && (-1 < (this->m_Memory).m_GrowSize)) {
                    /* Unresolved local var: int growSize@[???] */
    puVar1 = (this->m_Memory).m_pMemory;
    (this->m_Memory).m_NumAllocated = num;
    if (puVar1 != (uchar *)0x0) {
      puVar1 = realloc(puVar1,num);
      (this->m_Memory).m_pMemory = puVar1;
      return;
    }
    puVar1 = malloc(num);
    (this->m_Memory).m_pMemory = puVar1;
  }
  return;
}


// CUtlBuffer::Get  @ 000c4d80
/* DWARF original prototype: void Get(CUtlBuffer * this, void * pMem, int size) */

void __thiscall CUtlBuffer::Get(CUtlBuffer *this,void *pMem,int size)

{
  uchar uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  uchar *puVar5;
  uchar *puVar6;
  uchar *puVar7;
  
                    /* try { // try from 000c4d92 to 000d4d96 has its CatchHandler @ 000c4b30 */
  puVar5 = (this->m_Memory).m_pMemory + this->m_Get;
  iVar4 = size;
  if (7 < (uint)size) {
    puVar6 = pMem;
    if (((uint)pMem & 1) != 0) {
      uVar1 = *puVar5;
      puVar6 = (uchar *)((int)pMem + 1);
      puVar5 = puVar5 + 1;
      *(uchar *)pMem = uVar1;
      iVar4 = size + -1;
    }
    puVar7 = puVar6;
    if (((uint)puVar6 & 2) != 0) {
      uVar2 = *(undefined2 *)puVar5;
      puVar7 = puVar6 + 2;
      puVar5 = puVar5 + 2;
      iVar4 = iVar4 + -2;
      *(undefined2 *)puVar6 = uVar2;
    }
    pMem = puVar7;
    if (((uint)puVar7 & 4) != 0) {
      uVar3 = *(undefined4 *)puVar5;
      pMem = puVar7 + 4;
      puVar5 = puVar5 + 4;
      iVar4 = iVar4 + -4;
      *(undefined4 *)puVar7 = uVar3;
    }
  }
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(uchar *)pMem = *puVar5;
    puVar5 = puVar5 + 1;
    pMem = (uchar *)((int)pMem + 1);
  }
  this->m_Get = this->m_Get + size;
  return;
}


// CUtlBuffer::GetString  @ 000c4e70
/* DWARF original prototype: void GetString(CUtlBuffer * this, char * pString) */

void __thiscall CUtlBuffer::GetString(CUtlBuffer *this,char *pString)

{
  uint uVar1;
  uchar uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  size_t sVar8;
  uint uVar9;
  uchar *puVar10;
  uchar *puVar11;
  uchar *puVar12;
  byte bVar13;
  
  bVar13 = 0;
  if (this->m_Error == '\0') {
    if ((this->m_Flags & 1) == 0) {
                    /* Unresolved local var: int len@[???] */
      puVar10 = (this->m_Memory).m_pMemory + this->m_Get;
      sVar8 = strlen((char *)puVar10);
      uVar1 = sVar8 + 1;
      uVar9 = uVar1;
      if (7 < uVar1) {
        puVar12 = (uchar *)pString;
        if (((uint)pString & 1) != 0) {
          uVar2 = *puVar10;
          puVar12 = (uchar *)(pString + 1);
          puVar10 = puVar10 + 1;
          *pString = uVar2;
          uVar9 = sVar8;
        }
        puVar11 = puVar12;
        if (((uint)puVar12 & 2) != 0) {
          uVar3 = *(undefined2 *)puVar10;
          puVar11 = puVar12 + 2;
          puVar10 = puVar10 + 2;
          uVar9 = uVar9 - 2;
          *(undefined2 *)puVar12 = uVar3;
        }
        pString = (char *)puVar11;
        if (((uint)puVar11 & 4) != 0) {
          uVar5 = *(undefined4 *)puVar10;
          pString = (char *)(puVar11 + 4);
          puVar10 = puVar10 + 4;
          uVar9 = uVar9 - 4;
          *(undefined4 *)puVar11 = uVar5;
        }
      }
      for (; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pString = *puVar10;
        puVar10 = puVar10 + (uint)bVar13 * -2 + 1;
        pString = pString + (uint)bVar13 * -2 + 1;
      }
      this->m_Get = this->m_Get + uVar1;
      return;
    }
    iVar4 = (this->m_Memory).m_NumAllocated;
                    /* Unresolved local var: int lastpos@[???] */
    iVar7 = this->m_Get;
    if (iVar7 < iVar4) {
      puVar10 = (this->m_Memory).m_pMemory;
      do {
        iVar6 = isspace((int)(char)puVar10[iVar7]);
        if (iVar6 == 0) {
          puVar12 = (uchar *)pString;
          if (iVar7 < iVar4) goto LAB_000c4ed2;
          break;
        }
        iVar7 = iVar7 + 1;
        this->m_Get = iVar7;
      } while (iVar7 < iVar4);
    }
  }
LAB_000c4f00:
  *pString = '\0';
  return;
LAB_000c4ed2:
                    /* Unresolved local var: char c@[???] */
  uVar2 = puVar10[iVar7];
  iVar7 = isspace((int)(char)uVar2);
  pString = (char *)puVar12;
  if ((uVar2 == '\0') || (iVar7 != 0)) goto LAB_000c4f00;
  pString = (char *)(puVar12 + 1);
  *puVar12 = uVar2;
  iVar7 = this->m_Get + 1;
  this->m_Get = iVar7;
  if (iVar4 <= iVar7) goto LAB_000c4f00;
  puVar10 = (this->m_Memory).m_pMemory;
  puVar12 = (uchar *)pString;
  goto LAB_000c4ed2;
}


// CUtlBuffer::Printf  @ 000c55b0
/* DWARF original prototype: void Printf(CUtlBuffer * this, char * pFmt, ...) */

void __thiscall CUtlBuffer::Printf(CUtlBuffer *this,char *pFmt,...)

{
                    /* Unresolved local var: va_list args@[???] */
  VaPrintf(this,pFmt,&stack0x0000000c);
  return;
}


// CUtlBuffer::Put  @ 000c5230
/* DWARF original prototype: void Put(CUtlBuffer * this, void * pMem, int size) */

void __thiscall CUtlBuffer::Put(CUtlBuffer *this,void *pMem,int size)

{
  uchar uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  size_t __size;
  uchar *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uchar *puVar9;
  uchar *puVar10;
  byte bVar11;
  
  bVar11 = 0;
  if (this->m_Error != '\0') {
    return;
  }
  iVar8 = this->m_Put;
                    /* Unresolved local var: int growSize@[???] */
  iVar7 = size + iVar8;
  while (iVar4 = (this->m_Memory).m_NumAllocated, iVar4 < iVar7) {
    while( true ) {
      iVar6 = (this->m_Memory).m_GrowSize;
      if (iVar6 < 0) {
        this->m_Error = this->m_Error | 1;
        return;
      }
      if ((iVar6 == 0) && (iVar6 = 1, iVar4 != 0)) {
        iVar6 = iVar4;
      }
      __size = iVar4 + iVar6;
                    /* Unresolved local var: int growSize@[???] */
      puVar5 = (this->m_Memory).m_pMemory;
      (this->m_Memory).m_NumAllocated = __size;
      if (puVar5 == (uchar *)0x0) break;
      puVar5 = realloc(puVar5,__size);
      iVar8 = this->m_Put;
      iVar7 = size + iVar8;
      (this->m_Memory).m_pMemory = puVar5;
      iVar4 = (this->m_Memory).m_NumAllocated;
      if (iVar7 <= iVar4) goto LAB_000c529e;
    }
    puVar5 = malloc(__size);
    (this->m_Memory).m_pMemory = puVar5;
  }
LAB_000c529e:
  puVar5 = (this->m_Memory).m_pMemory + iVar8;
  iVar7 = size;
  if (7 < (uint)size) {
    puVar10 = puVar5;
    if (((uint)puVar5 & 1) != 0) {
      uVar1 = *(uchar *)pMem;
      puVar10 = puVar5 + 1;
      pMem = (void *)((int)pMem + 1);
      iVar7 = size + -1;
      *puVar5 = uVar1;
    }
    puVar9 = puVar10;
    if (((uint)puVar10 & 2) != 0) {
      uVar2 = *(undefined2 *)pMem;
      puVar9 = puVar10 + 2;
      pMem = (void *)((int)pMem + 2);
      iVar7 = iVar7 + -2;
      *(undefined2 *)puVar10 = uVar2;
    }
    puVar5 = puVar9;
    if (((uint)puVar9 & 4) != 0) {
      uVar3 = *(undefined4 *)pMem;
      puVar5 = puVar9 + 4;
      pMem = (void *)((int)pMem + 4);
      iVar7 = iVar7 + -4;
      *(undefined4 *)puVar9 = uVar3;
    }
  }
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = *(uchar *)pMem;
    pMem = (uchar *)((int)pMem + (uint)bVar11 * -2 + 1);
    puVar5 = puVar5 + (uint)bVar11 * -2 + 1;
  }
  this->m_Put = this->m_Put + size;
  return;
}


// CUtlBuffer::PutString  @ 000c5330
/* DWARF original prototype: void PutString(CUtlBuffer * this, char * pString) */

void __thiscall CUtlBuffer::PutString(CUtlBuffer *this,char *pString)

{
  uchar uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  size_t sVar4;
  int iVar5;
  uchar *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uchar *puVar12;
  uchar *puVar13;
  byte bVar14;
  
                    /* Unresolved local var: int len@[???] */
  bVar14 = 0;
  sVar4 = strlen(pString);
  uVar10 = sVar4 + 1;
  if ((this->m_Flags & 1) != 0) {
    uVar10 = sVar4;
  }
  if (this->m_Error != '\0') {
    return;
  }
  iVar11 = this->m_Put;
                    /* Unresolved local var: int growSize@[???] */
  iVar7 = uVar10 + iVar11;
  while (iVar5 = (this->m_Memory).m_NumAllocated, iVar5 < iVar7) {
    while( true ) {
      iVar9 = (this->m_Memory).m_GrowSize;
      if (iVar9 < 0) {
        this->m_Error = this->m_Error | 1;
        return;
      }
      if ((iVar9 == 0) && (iVar9 = 1, iVar5 != 0)) {
        iVar9 = iVar5;
      }
      sVar4 = iVar5 + iVar9;
                    /* Unresolved local var: int growSize@[???] */
      puVar6 = (this->m_Memory).m_pMemory;
      (this->m_Memory).m_NumAllocated = sVar4;
      if (puVar6 == (uchar *)0x0) break;
      puVar6 = realloc(puVar6,sVar4);
      iVar11 = this->m_Put;
      iVar7 = uVar10 + iVar11;
      (this->m_Memory).m_pMemory = puVar6;
      iVar5 = (this->m_Memory).m_NumAllocated;
      if (iVar7 <= iVar5) goto LAB_000c53ae;
    }
    puVar6 = malloc(sVar4);
    (this->m_Memory).m_pMemory = puVar6;
  }
LAB_000c53ae:
  puVar6 = (this->m_Memory).m_pMemory + iVar11;
  uVar8 = uVar10;
  if (7 < uVar10) {
    puVar13 = puVar6;
    if (((uint)puVar6 & 1) != 0) {
      uVar1 = *pString;
      puVar13 = puVar6 + 1;
      pString = pString + 1;
      uVar8 = uVar10 - 1;
      *puVar6 = uVar1;
    }
    puVar12 = puVar13;
    if (((uint)puVar13 & 2) != 0) {
      uVar2 = *(undefined2 *)pString;
      puVar12 = puVar13 + 2;
      pString = pString + 2;
      uVar8 = uVar8 - 2;
      *(undefined2 *)puVar13 = uVar2;
    }
    puVar6 = puVar12;
    if (((uint)puVar12 & 4) != 0) {
      uVar3 = *(undefined4 *)pString;
      puVar6 = puVar12 + 4;
      pString = pString + 4;
      uVar8 = uVar8 - 4;
      *(undefined4 *)puVar12 = uVar3;
    }
  }
  for (; uVar8 != 0; uVar8 = uVar8 - 1) {
    *puVar6 = *pString;
    pString = pString + (uint)bVar14 * -2 + 1;
    puVar6 = puVar6 + (uint)bVar14 * -2 + 1;
  }
  this->m_Put = this->m_Put + uVar10;
  return;
}


// CUtlBuffer::Scanf  @ 000c5200
/* DWARF original prototype: int Scanf(CUtlBuffer * this, char * pFmt, ...) */

int __thiscall CUtlBuffer::Scanf(CUtlBuffer *this,char *pFmt,...)

{
  int iVar1;
  
                    /* Unresolved local var: va_list args@[???]
                       Unresolved local var: int count@[DW_OP_reg0(EAX)] */
  iVar1 = VaScanf(this,pFmt,&stack0x0000000c);
  return iVar1;
}


// CUtlBuffer::SeekGet  @ 000c4fc0
/* DWARF original prototype: void SeekGet(CUtlBuffer * this, SeekType_t type, int offset) */

void __thiscall CUtlBuffer::SeekGet(CUtlBuffer *this,SeekType_t type,int offset)

{
  if (type == SEEK_CURRENT) {
    this->m_Get = this->m_Get + offset;
    return;
  }
  if (type != SEEK_HEAD) {
    if (type == SEEK_TAIL) {
      this->m_Get = (this->m_Memory).m_NumAllocated - offset;
      return;
    }
    return;
  }
  this->m_Get = offset;
  return;
}


// CUtlBuffer::SeekPut  @ 000c5670
/* DWARF original prototype: void SeekPut(CUtlBuffer * this, SeekType_t type, int offset) */

void __thiscall CUtlBuffer::SeekPut(CUtlBuffer *this,SeekType_t type,int offset)

{
  if (type == SEEK_CURRENT) {
    this->m_Put = this->m_Put + offset;
    return;
  }
  if (type != SEEK_HEAD) {
    if (type == SEEK_TAIL) {
      this->m_Put = (this->m_Memory).m_NumAllocated - offset;
      return;
    }
    return;
  }
  this->m_Put = offset;
  return;
}


// CUtlBuffer::VaPrintf  @ 000c5440
/* DWARF original prototype: void VaPrintf(CUtlBuffer * this, char * pFmt, va_list list) */

void __thiscall CUtlBuffer::VaPrintf(CUtlBuffer *this,char *pFmt,va_list list)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  size_t __size;
  uchar *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uchar *puVar9;
  int iVar10;
  uchar *puVar11;
  uchar *puVar12;
  int in_GS_OFFSET;
  byte bVar13;
  uchar local_820;
  uchar auStack_81f [2047];
  int local_20;
  
                    /* Unresolved local var: char[2048] temp@[???]
                       Unresolved local var: int len@[???] */
  bVar13 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  puVar9 = &local_820;
  iVar3 = __vsprintf_chk(puVar9,1,0x800,pFmt,list);
  uVar8 = iVar3 + (uint)((this->m_Flags & 1) == 0);
  if (this->m_Error == '\0') {
    iVar10 = this->m_Put;
    iVar3 = uVar8 + iVar10;
    while (iVar4 = (this->m_Memory).m_NumAllocated, iVar4 < iVar3) {
      while( true ) {
        iVar6 = (this->m_Memory).m_GrowSize;
        if (iVar6 < 0) {
          this->m_Error = this->m_Error | 1;
          goto LAB_000c54a7;
        }
                    /* Unresolved local var: int growSize@[???] */
        if ((iVar6 == 0) && (iVar6 = 1, iVar4 != 0)) {
          iVar6 = iVar4;
        }
        __size = iVar4 + iVar6;
                    /* Unresolved local var: int growSize@[???] */
        puVar5 = (this->m_Memory).m_pMemory;
        (this->m_Memory).m_NumAllocated = __size;
        if (puVar5 == (uchar *)0x0) break;
        puVar5 = realloc(puVar5,__size);
        iVar10 = this->m_Put;
        iVar3 = uVar8 + iVar10;
        (this->m_Memory).m_pMemory = puVar5;
        iVar4 = (this->m_Memory).m_NumAllocated;
        if (iVar3 <= iVar4) goto LAB_000c551c;
      }
      puVar5 = malloc(__size);
      (this->m_Memory).m_pMemory = puVar5;
    }
LAB_000c551c:
    puVar5 = (this->m_Memory).m_pMemory + iVar10;
    uVar7 = uVar8;
    if (7 < uVar8) {
      puVar12 = puVar5;
      if (((uint)puVar5 & 1) != 0) {
        puVar12 = puVar5 + 1;
        puVar9 = auStack_81f;
        uVar7 = uVar8 - 1;
        *puVar5 = local_820;
      }
      puVar11 = puVar12;
      if (((uint)puVar12 & 2) != 0) {
        uVar1 = *(undefined2 *)puVar9;
        puVar11 = puVar12 + 2;
        puVar9 = puVar9 + 2;
        uVar7 = uVar7 - 2;
        *(undefined2 *)puVar12 = uVar1;
      }
      puVar5 = puVar11;
      if (((uint)puVar11 & 4) != 0) {
        uVar2 = *(undefined4 *)puVar9;
        puVar5 = puVar11 + 4;
        puVar9 = puVar9 + 4;
        uVar7 = uVar7 - 4;
        *(undefined4 *)puVar11 = uVar2;
      }
    }
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar5 = *puVar9;
      puVar9 = puVar9 + (uint)bVar13 * -2 + 1;
      puVar5 = puVar5 + (uint)bVar13 * -2 + 1;
    }
    this->m_Put = this->m_Put + uVar8;
  }
LAB_000c54a7:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CUtlBuffer::VaScanf  @ 000c5010
/* DWARF original prototype: int VaScanf(CUtlBuffer * this, char * pFmt, va_list list) */

int __thiscall CUtlBuffer::VaScanf(CUtlBuffer *this,char *pFmt,va_list list)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  ulong *puVar4;
  float *pfVar5;
  long *plVar6;
  uchar *puVar7;
  ulong uVar8;
  long lVar9;
  int iVar10;
  int iVar11;
  double dVar12;
  int local_34;
  uchar *local_20 [4];
  
                    /* Unresolved local var: int numScanned@[???]
                       Unresolved local var: char c@[???]
                       Unresolved local var: char * pEnd@[???] */
  local_34 = 0;
  if ((this->m_Error == '\0') && ((this->m_Flags & 1) != 0)) {
    local_34 = 0;
LAB_000c5040:
                    /* Unresolved local var: int numScanned@[???]
                       Unresolved local var: char c@[???]
                       Unresolved local var: char * pEnd@[???] */
    pcVar1 = pFmt + 1;
    cVar2 = *pFmt;
    if (cVar2 != '\0') {
      iVar11 = this->m_Get;
      iVar3 = (this->m_Memory).m_NumAllocated;
      if (iVar3 <= iVar11) {
        this->m_Error = this->m_Error | 2;
        goto switchD_000c5080_caseD_65;
      }
      if (cVar2 == ' ') goto LAB_000c51b8;
      if (cVar2 == '%') {
                    /* Unresolved local var: char type@[???] */
        if (pFmt[1] == '\0') goto switchD_000c5080_caseD_65;
        switch(pFmt[1]) {
        case 'c':
                    /* Unresolved local var: char * ch@[???] */
          **(uchar **)list = (this->m_Memory).m_pMemory[iVar11];
          this->m_Get = this->m_Get + 1;
          goto LAB_000c50e2;
        case 'd':
        case 'i':
                    /* Unresolved local var: int * i@[???] */
          plVar6 = *(long **)list;
          lVar9 = strtol((char *)((this->m_Memory).m_pMemory + iVar11),(char **)local_20,10);
          *plVar6 = lVar9;
          break;
        default:
          goto switchD_000c5080_caseD_65;
        case 'f':
          pfVar5 = *(float **)list;
          dVar12 = strtod((char *)((this->m_Memory).m_pMemory + iVar11),(char **)local_20);
          *pfVar5 = (float)dVar12;
          break;
        case 's':
                    /* Unresolved local var: char * s@[???] */
          GetString(this,*(char **)list);
          goto LAB_000c50e2;
        case 'u':
                    /* Unresolved local var: uint * u@[???] */
          puVar4 = *(ulong **)list;
          uVar8 = strtoul((char *)((this->m_Memory).m_pMemory + iVar11),(char **)local_20,10);
          *puVar4 = uVar8;
        }
        puVar7 = (this->m_Memory).m_pMemory;
                    /* Unresolved local var: float * f@[???] */
        if (local_20[0] == puVar7 + this->m_Get) goto switchD_000c5080_caseD_65;
        this->m_Get = (int)local_20[0] - (int)puVar7;
LAB_000c50e2:
        list = list + 4;
        local_34 = local_34 + 1;
        pFmt = pFmt + 2;
      }
      else {
        if ((int)cVar2 != (uint)(this->m_Memory).m_pMemory[iVar11]) goto switchD_000c5080_caseD_65;
        this->m_Get = iVar11 + 1;
        pFmt = pcVar1;
      }
      goto LAB_000c5040;
    }
switchD_000c5080_caseD_65:
  }
  return local_34;
LAB_000c51b8:
  pFmt = pcVar1;
  if (((this->m_Flags & 1) != 0) && (this->m_Error == '\0')) {
    puVar7 = (this->m_Memory).m_pMemory;
    do {
                    /* Unresolved local var: int lastpos@[???] */
      iVar10 = isspace((int)(char)puVar7[iVar11]);
      if (iVar10 == 0) break;
      iVar11 = iVar11 + 1;
      this->m_Get = iVar11;
    } while (iVar11 < iVar3);
  }
  goto LAB_000c5040;
}


// CUtlVector<char*>::InsertBefore  @ 0004c760
/* DWARF original prototype: int InsertBefore(CUtlVector<char*> * this, int elem, char * * src) */

int __thiscall CUtlVector<char*>::InsertBefore(CUtlVector<char*> *this,int elem,char **src)

{
  int iVar1;
  int iVar2;
  char **ppcVar3;
  int iVar4;
  bool bVar5;
  
  iVar1 = (this->m_Memory).m_NumAllocated;
  iVar4 = this->m_Size + 1;
  if (iVar4 <= iVar1) {
LAB_0004c830:
    ppcVar3 = (this->m_Memory).m_pMemory;
    goto LAB_0004c7cb;
  }
  iVar2 = (this->m_Memory).m_GrowSize;
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
  if (iVar4 - iVar1 < iVar2) {
    if ((0 < iVar2) || (iVar2 != 0)) goto LAB_0004c7a3;
    iVar2 = 1;
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    iVar2 = iVar1 + iVar2;
    (this->m_Memory).m_NumAllocated = iVar2;
  }
  else {
                    /* Unresolved local var: int growSize@[???] */
    bVar5 = iVar2 < 0;
    iVar2 = iVar4 - iVar1;
    if (bVar5) goto LAB_0004c830;
LAB_0004c7a3:
    iVar2 = iVar2 + iVar1;
    (this->m_Memory).m_NumAllocated = iVar2;
  }
                    /* Unresolved local var: int growSize@[???] */
  ppcVar3 = (this->m_Memory).m_pMemory;
  if (ppcVar3 == (char **)0x0) {
    ppcVar3 = malloc(iVar2 << 2);
    (this->m_Memory).m_pMemory = ppcVar3;
  }
  else {
    ppcVar3 = realloc(ppcVar3,iVar2 << 2);
    iVar4 = this->m_Size + 1;
    (this->m_Memory).m_pMemory = ppcVar3;
  }
LAB_0004c7cb:
  this->m_Size = iVar4;
                    /* Unresolved local var: int numToMove@[???] */
  iVar4 = (iVar4 - elem) + -1;
  if (0 < iVar4) {
    memmove(ppcVar3 + elem + 1,ppcVar3 + elem,iVar4 * 4);
    ppcVar3 = (this->m_Memory).m_pMemory;
  }
  if (ppcVar3 + elem != (char **)0x0) {
    ppcVar3[elem] = *src;
  }
  return elem;
}


// CUtlVector<char*>::~CUtlVector  @ 0004c730
/* DWARF original prototype: void ~CUtlVector(CUtlVector<char*> * this, int __in_chrg) */

void __thiscall CUtlVector<char*>::~CUtlVector(CUtlVector<char*> *this,int __in_chrg)

{
  int iVar1;
  char **__ptr;
  
  iVar1 = (this->m_Memory).m_GrowSize;
  this->m_Size = 0;
  if ((-1 < iVar1) && (__ptr = (this->m_Memory).m_pMemory, __ptr != (char **)0x0)) {
    free(__ptr);
    return;
  }
  return;
}


// CVarGetFloat  @ 00075760
float CVarGetFloat(char *szVarName)

{
  cvar_s *pcVar1;
  int iVar2;
  float fVar3;
  char *apcStack_10 [3];
  
  apcStack_10[0] = szVarName;
  (*g_engdstAddrs.pfnGetCvarPointer)(apcStack_10);
  pcVar1 = cvar_vars;
  while( true ) {
    if (pcVar1 == (cvar_t *)0x0) {
      return 0.0;
    }
    iVar2 = Q_stricmp(apcStack_10[0],pcVar1->name);
    if (iVar2 == 0) break;
    pcVar1 = pcVar1->next;
  }
  fVar3 = Q_atof(pcVar1->string);
  return fVar3;
}


// CVarGetPointer  @ 00075780
cvar_t * CVarGetPointer(char *szVarName)

{
  cvar_s *pcVar1;
  int iVar2;
  
  (*g_engdstAddrs.pfnGetCvarPointer)(&szVarName);
  pcVar1 = cvar_vars;
  while( true ) {
    if (pcVar1 == (cvar_t *)0x0) {
      return (cvar_t *)0x0;
    }
    iVar2 = Q_stricmp(szVarName,pcVar1->name);
    if (iVar2 == 0) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}


// CVarGetString  @ 00075770
char * CVarGetString(char *szVarName)

{
  cvar_s *pcVar1;
  int iVar2;
  char *apcStack_10 [3];
  
  apcStack_10[0] = szVarName;
  (*g_engdstAddrs.pfnGetCvarPointer)(apcStack_10);
  pcVar1 = cvar_vars;
  while( true ) {
    if (pcVar1 == (cvar_t *)0x0) {
      return cvar_null_string;
    }
    iVar2 = Q_stricmp(apcStack_10[0],pcVar1->name);
    if (iVar2 == 0) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1->string;
}


// CVarRegister  @ 000757b0
void CVarRegister(cvar_t *pCvar)

{
  if (pCvar != (cvar_t *)0x0) {
    pCvar->flags = pCvar->flags | 8;
    Cvar_RegisterVariable(pCvar);
    return;
  }
  return;
}


// CVarSetFloat  @ 00075790
void CVarSetFloat(char *szVarName,float flValue)

{
  cvar_s *pcVar1;
  cvar_s *var;
  cvarhook_s *pcVar2;
  char *pcVar3;
  int iVar4;
  int in_GS_OFFSET;
  char *apcStack_40 [3];
  char *pcStack_34;
  char acStack_30 [32];
  int iStack_10;
  
  apcStack_40[0] = szVarName;
  iStack_10 = *(int *)(in_GS_OFFSET + 0x14);
  (*g_engdstAddrs.Cvar_SetValue)(apcStack_40,&flValue);
  if (ABS(flValue - (float)(int)flValue) < 1e-06) {
    __snprintf_chk(acStack_30,0x20,1,0x20,&DAT_000d153e,(int)flValue);
  }
  else {
    __snprintf_chk(acStack_30,0x20,1,0x20,"%f",(double)flValue);
  }
  pcVar3 = apcStack_40[0];
  pcStack_34 = apcStack_40[0];
  (*g_engdstAddrs.pfnGetCvarPointer)(&pcStack_34);
  for (var = cvar_vars; var != (cvar_s *)0x0; var = var->next) {
    iVar4 = Q_stricmp(pcStack_34,var->name);
    if (iVar4 == 0) {
      Cvar_DirectSet(var,acStack_30);
      if (cvar_hooks == (cvarhook_t *)0x0) goto LAB_00042fbc;
      pcVar1 = cvar_hooks->cvar;
      pcVar2 = cvar_hooks;
      goto joined_r0x00042fa5;
    }
  }
  Con_DPrintf("Cvar_Set: variable %s not found\n",pcVar3);
LAB_00042fbc:
  if (iStack_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
joined_r0x00042fa5:
  if (var == pcVar1) goto LAB_00042fe8;
  pcVar2 = pcVar2->next;
  if (pcVar2 == (cvarhook_s *)0x0) goto LAB_00042fbc;
  pcVar1 = pcVar2->cvar;
  goto joined_r0x00042fa5;
LAB_00042fe8:
  (*pcVar2->hook)(var);
  goto LAB_00042fbc;
}


// CVarSetString  @ 000757a0
void CVarSetString(char *szVarName,char *szValue)

{
  cvar_s *var;
  cvarhook_s *pcVar1;
  int iVar2;
  char *apcStack_10 [2];
  
  apcStack_10[0] = szVarName;
  (*g_engdstAddrs.pfnGetCvarPointer)(apcStack_10);
  var = cvar_vars;
  while( true ) {
    if (var == (cvar_s *)0x0) {
      Con_DPrintf("Cvar_Set: variable %s not found\n",szVarName);
      return;
    }
    iVar2 = Q_stricmp(apcStack_10[0],var->name);
    if (iVar2 == 0) break;
    var = var->next;
  }
  Cvar_DirectSet(var,szValue);
  pcVar1 = cvar_hooks;
  while( true ) {
    if (pcVar1 == (cvarhook_t *)0x0) {
      return;
    }
    if (pcVar1->cvar == var) break;
    pcVar1 = pcVar1->next;
  }
  (*pcVar1->hook)(var);
  return;
}


// CacheSystemCompare  @ 000ac2b0
int CacheSystemCompare(void *ppcs1,void *ppcs2)

{
  int iVar1;
  
                    /* Unresolved local var: cache_system_t * pcs1@[???]
                       Unresolved local var: cache_system_t * pcs2@[???] */
  iVar1 = strcasecmp((char *)(*(int *)ppcs1 + 8),(char *)(*(int *)ppcs2 + 8));
  return iVar1;
}


// CalcSurfaceExtents  @ 00063300
void CalcSurfaceExtents(msurface_t *s)

{
  ushort uVar1;
  mtexinfo_t *pmVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int *piVar9;
  short sVar10;
  mvertex_t *unaff_ESI;
  int iVar11;
  float fVar12;
  float fVar13;
  float local_80;
  float local_3c;
  float local_34;
  float local_30;
  
                    /* Unresolved local var: float[2] mins@[???]
                       Unresolved local var: float[2] maxs@[???]
                       Unresolved local var: float val@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int e@[???]
                       Unresolved local var: mvertex_t * v@[???]
                       Unresolved local var: mtexinfo_t * tex@[???]
                       Unresolved local var: int[2] bmins@[???]
                       Unresolved local var: int[2] bmaxs@[???] */
  local_34 = 999999.0;
  pmVar2 = s->texinfo;
  local_30 = -99999.0;
  if (s->numedges < 1) {
    sVar10 = -0x1869;
    iVar11 = 0xf423;
  }
  else {
    bVar8 = false;
    piVar9 = loadmodel->surfedges + s->firstedge;
    bVar7 = false;
    bVar6 = false;
    bVar5 = false;
    local_80 = -99999.0;
    local_3c = -99999.0;
    fVar13 = 999999.0;
    fVar12 = -99999.0;
    fVar3 = 999999.0;
    do {
      iVar11 = *piVar9;
      if (iVar11 < 0) {
        uVar1 = loadmodel->edges[-iVar11].v[1];
      }
      else {
        uVar1 = loadmodel->edges[iVar11].v[0];
      }
      unaff_ESI = loadmodel->vertexes + uVar1;
      fVar4 = pmVar2->vecs[0][2] * unaff_ESI->position[2] +
              pmVar2->vecs[0][1] * unaff_ESI->position[1] +
              pmVar2->vecs[0][0] * unaff_ESI->position[0] + pmVar2->vecs[0][3];
      if (fVar4 < fVar13) {
        bVar5 = true;
        fVar13 = fVar4;
      }
      if (fVar12 < fVar4) {
        bVar6 = true;
        fVar12 = fVar4;
      }
      fVar4 = unaff_ESI->position[2] * pmVar2->vecs[1][2] +
              unaff_ESI->position[1] * pmVar2->vecs[1][1] +
              unaff_ESI->position[0] * pmVar2->vecs[1][0] + pmVar2->vecs[1][3];
      if (fVar4 < fVar3) {
        bVar7 = true;
        fVar3 = fVar4;
      }
      if (local_80 < fVar4) {
        bVar8 = true;
        local_80 = fVar4;
        local_3c = fVar4;
      }
      piVar9 = piVar9 + 1;
    } while (loadmodel->surfedges + s->numedges + s->firstedge != piVar9);
    fVar4 = 999999.0;
    if (bVar5) {
      fVar4 = fVar13;
    }
    fVar13 = -99999.0;
    if (bVar6) {
      fVar13 = fVar12;
    }
    local_34 = 999999.0;
    if (bVar7) {
      local_34 = fVar3;
    }
    local_30 = local_3c;
    if (!bVar8) {
      local_30 = -99999.0;
    }
    fVar12 = floorf(fVar4 * 0.0625);
    iVar11 = (int)fVar12;
    fVar12 = ceilf(fVar13 * 0.0625);
    sVar10 = (short)(int)fVar12;
  }
  sVar10 = (sVar10 - (short)iVar11) * 0x10;
  s->texturemins[0] = (short)(iVar11 << 4);
  s->extents[0] = sVar10;
  if ((((byte)pmVar2->flags & 1) != 1) && (0x100 < sVar10)) {
    Sys_Error("Bad surface extents %d/%d at position (%d,%d,%d)",(int)sVar10,(int)s->extents[1],
              (int)unaff_ESI->position[0],(int)unaff_ESI->position[1],(int)unaff_ESI->position[2]);
  }
  fVar12 = floorf(local_34 * 0.0625);
  fVar13 = ceilf(local_30 * 0.0625);
  s->texturemins[1] = (short)((int)fVar12 << 4);
  sVar10 = ((short)(int)fVar13 - (short)(int)fVar12) * 0x10;
  s->extents[1] = sVar10;
  if ((((byte)pmVar2->flags & 1) != 1) && (0x100 < sVar10)) {
    Sys_Error("Bad surface extents %d/%d at position (%d,%d,%d)",(int)s->extents[0],
              (int)s->extents[1],(int)unaff_ESI->position[0],(int)unaff_ESI->position[1],
              (int)unaff_ESI->position[2]);
    return;
  }
  return;
}


// CheckChallengeNr  @ 00086dd0
qboolean CheckChallengeNr(netadr_t *adr,int nChallengeValue)

{
  qboolean qVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if ((adr != (netadr_t *)0x0) && (iVar2 = 0, nChallengeValue != -1)) {
    do {
      qVar1 = NET_CompareBaseAdr(*adr,g_rg_sv_challenges[iVar2].adr);
      if (qVar1 != false) {
        if (nChallengeValue != g_rg_sv_challenges[iVar2].challenge) {
          return false;
        }
        return (uint)((float)realtime <= (float)g_rg_sv_challenges[iVar2].time + 3600.0);
      }
                    /* Unresolved local var: int i@[???] */
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x400);
  }
  return false;
}


// CheckGore  @ 00055040
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CheckGore(void)

{
  int in_GS_OFFSET;
  undefined1 local_90 [128];
  int local_10;
  
                    /* Unresolved local var: char[128] szSubKey@[???]
                       Unresolved local var: int nBufferLen@[???]
                       Unresolved local var: char[128] szBuffer@[???]
                       Unresolved local var: qboolean bGore@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_90,0,0x80);
  if (bLowViolenceBuild == false) {
    Cvar_SetValue("violence_hblood",1.0);
    Cvar_SetValue("violence_hgibs",1.0);
    Cvar_SetValue("violence_ablood",1.0);
    Cvar_SetValue("violence_agibs",1.0);
  }
  else {
                    /* Unresolved local var: char[128] szSubKey@[???]
                       Unresolved local var: int nBufferLen@[???]
                       Unresolved local var: char[128] szBuffer@[???]
                       Unresolved local var: qboolean bGore@[???] */
    Cvar_SetValue("violence_hblood",0.0);
    Cvar_SetValue("violence_hgibs",0.0);
    Cvar_SetValue("violence_ablood",0.0);
    Cvar_SetValue("violence_agibs",0.0);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CheckIP  @ 000b9c50
int CheckIP(netadr_t_conflict adr)

{
  bool bVar1;
  
  bVar1 = CIPRateLimit::CheckIP(&rateChecker,adr);
  return (uint)bVar1;
}


// CheckLiblistForFallbackDir  @ 0004b5f0
void CheckLiblistForFallbackDir
               (char *pGameDir,bool bLanguage,char *pLanguage,bool bLowViolenceBuild)

{
  int iVar1;
  FileHandle_t file;
  char *pcVar2;
  char *pcVar3;
  int in_GS_OFFSET;
  undefined1 uVar4;
  byte bVar5;
  char *pcVar6;
  undefined4 local_14a4;
  char local_14a0 [128];
  char local_1420 [511];
  undefined1 local_1221;
  char local_1220 [511];
  undefined1 local_1021;
  char local_1020 [4095];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char[512] szTemp@[???]
                       Unresolved local var: bool bSuccess@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  bVar5 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  __snprintf_chk(local_1420,0x1ff,1,0x200,"%s/liblist.gam",pGameDir);
  COM_FixSlashes(local_1420);
  (**(code **)(*(int *)g_pFileSystem + 0x80))(g_pFileSystem,local_1420);
  iVar1 = strcasecmp(com_gamedir,pGameDir);
  if (iVar1 == 0) {
    file = FS_Open("liblist.gam","rt");
  }
  else {
    __snprintf_chk(local_1420,0x1ff,1,0x200,"../%s/liblist.gam",pGameDir);
    COM_FixSlashes(local_1420);
    file = FS_Open(local_1420,"rt");
  }
  if (file != (FileHandle_t)0x0) {
                    /* Unresolved local var: char[128] szFallback@[???]
                       Unresolved local var: char[512] szLine@[???]
                       Unresolved local var: int outputBufferSize@[???] */
    do {
      do {
        iVar1 = FS_EndOfFile(file);
        if (iVar1 != 0) goto LAB_0004b9a0;
        local_1220[0] = '\0';
        FS_ReadLine(local_1220,0x1ff,file);
        local_1021 = 0;
        iVar1 = strncasecmp(local_1220,"fallback_dir",0xc);
      } while (iVar1 != 0);
                    /* Unresolved local var: char * start@[???]
                       Unresolved local var: char * end@[???]
                       Unresolved local var: int bytesToCopy@[???] */
      pcVar2 = strchr(local_1220,0x22);
      if (pcVar2 == (char *)0x0) goto LAB_0004b9a0;
      pcVar3 = strchr(pcVar2 + 1,0x22);
      if ((pcVar3 == (char *)0x0) || (pcVar3 = pcVar3 + (-1 - (int)pcVar2), (char *)0x7e < pcVar3))
      goto LAB_0004b9a0;
    } while (pcVar3 == (char *)0x0);
    __strncpy_chk(local_14a0,pcVar2 + 1,pcVar3,0x80);
    local_14a0[(int)pcVar3] = '\0';
    iVar1 = strcasecmp(pGameDir,local_14a0);
    if (iVar1 != 0) {
      if (bLowViolenceBuild) {
        __snprintf_chk(local_1420,0x1ff,1,0x200,"%s/%s_lv",s_pBaseDir,local_14a0);
        local_1221 = 0;
        COM_FixSlashes(local_1420);
        (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1420,"GAME_FALLBACK");
      }
      iVar1 = COM_CheckParm("-addons");
      if ((iVar1 != 0) ||
         (iVar1 = (*registry->_vptr_IRegistry[2])(registry,"addons_folder",0), 0 < iVar1)) {
        __snprintf_chk(local_1420,0x1ff,1,0x200,"%s/%s_addon",s_pBaseDir,local_14a0);
        local_1221 = 0;
        COM_FixSlashes(local_1420);
        (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1420,"GAME_FALLBACK");
      }
      if ((pLanguage != (char *)0x0) && (bLanguage)) {
        __snprintf_chk(local_1420,0x1ff,1,0x200,"%s/%s_%s",s_pBaseDir,local_14a0,pLanguage);
        local_1221 = 0;
        COM_FixSlashes(local_1420);
        (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_1420,"GAME_FALLBACK");
        iVar1 = COM_CheckParm("-steam");
        if (iVar1 == 0) {
                    /* Unresolved local var: char[4096] baseDir@[???]
                       Unresolved local var: char * tempPtr@[???] */
          Q_strncpy(local_1020,s_pBaseDir,0xfff);
          local_21 = 0;
          pcVar2 = Q_strstr(local_1020,"\\game");
          if (pcVar2 != (char *)0x0) {
            *pcVar2 = '\0';
            __snprintf_chk(local_1420,0x1ff,1,0x200,"%s\\localization\\%s_%s",local_1020,local_14a0,
                           pLanguage);
            local_1221 = 0;
            COM_FixSlashes(local_1420);
            (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_1420,"GAME_FALLBACK");
          }
        }
      }
      iVar1 = COM_CheckParm("-nohdmodels");
      if ((iVar1 == 0) &&
         (iVar1 = (*registry->_vptr_IRegistry[2])(registry,"hdmodels",0), 0 < iVar1)) {
        __snprintf_chk(local_1420,0x1ff,1,0x200,"%s/%s_hd",s_pBaseDir,local_14a0);
        local_1221 = 0;
        COM_FixSlashes(local_1420);
        (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_1420,"GAME_FALLBACK");
      }
      pcVar6 = local_14a0;
      __snprintf_chk(local_1420,0x1ff,1,0x200,"%s/%s",s_pBaseDir,local_14a0);
      uVar4 = 1;
      local_1221 = 0;
      COM_FixSlashes(local_1420);
      (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_1420,"GAME_FALLBACK");
      iVar1 = 6;
      pcVar2 = local_14a0;
      pcVar3 = "valve";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        uVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + (uint)bVar5 * -2 + 1;
        pcVar3 = pcVar3 + (uint)bVar5 * -2 + 1;
      } while ((bool)uVar4);
      if (!(bool)uVar4) {
                    /* Unresolved local var: int BufLen@[???]
                       Unresolved local var: char * szFileName@[???] */
        local_14a4 = operator_new__(0x80);
        __snprintf_chk(local_14a4,0x7f,1,0x80,"Resource/%s_%%language%%.txt",local_14a0,pcVar6);
        local_14a4[0x7f] = '\0';
        CUtlVector<char*>::InsertBefore
                  (&g_fallbackLocalizationFiles,g_fallbackLocalizationFiles.m_Size,
                   (char **)&local_14a4);
        CheckLiblistForFallbackDir(local_14a0,bLanguage,pLanguage,bLowViolenceBuild);
      }
    }
LAB_0004b9a0:
    FS_Close(file);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CleanupName  @ 000a6130
void CleanupName(char *in,char *out)

{
  char *pcVar1;
  char cVar2;
  __int32_t **pp_Var3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  
                    /* Unresolved local var: int i@[???] */
  cVar2 = *in;
  if (cVar2 == '\0') {
    iVar6 = 0;
  }
  else {
                    /* Unresolved local var: int __res@[???] */
    pp_Var3 = __ctype_toupper_loc();
    *out = (char)(*pp_Var3)[cVar2];
    if (in[1] == '\0') {
      iVar6 = 1;
    }
    else {
      out[1] = (char)(*pp_Var3)[in[1]];
      if (in[2] == '\0') {
        iVar6 = 2;
      }
      else {
        out[2] = (char)(*pp_Var3)[in[2]];
        if (in[3] == '\0') {
          iVar6 = 3;
        }
        else {
          out[3] = (char)(*pp_Var3)[in[3]];
          if (in[4] == '\0') {
            iVar6 = 4;
          }
          else {
            out[4] = (char)(*pp_Var3)[in[4]];
            if (in[5] == '\0') {
              iVar6 = 5;
            }
            else {
              out[5] = (char)(*pp_Var3)[in[5]];
              if (in[6] == '\0') {
                iVar6 = 6;
              }
              else {
                out[6] = (char)(*pp_Var3)[in[6]];
                if (in[7] == '\0') {
                  iVar6 = 7;
                }
                else {
                  out[7] = (char)(*pp_Var3)[in[7]];
                  if (in[8] == '\0') {
                    iVar6 = 8;
                  }
                  else {
                    out[8] = (char)(*pp_Var3)[in[8]];
                    if (in[9] == '\0') {
                      iVar6 = 9;
                    }
                    else {
                      out[9] = (char)(*pp_Var3)[in[9]];
                      if (in[10] == '\0') {
                        iVar6 = 10;
                      }
                      else {
                        out[10] = (char)(*pp_Var3)[in[10]];
                        if (in[0xb] == '\0') {
                          iVar6 = 0xb;
                        }
                        else {
                          out[0xb] = (char)(*pp_Var3)[in[0xb]];
                          if (in[0xc] == '\0') {
                            iVar6 = 0xc;
                          }
                          else {
                            out[0xc] = (char)(*pp_Var3)[in[0xc]];
                            if (in[0xd] == '\0') {
                              iVar6 = 0xd;
                            }
                            else {
                              out[0xd] = (char)(*pp_Var3)[in[0xd]];
                              if (in[0xe] == '\0') {
                                iVar6 = 0xe;
                              }
                              else {
                                out[0xe] = (char)(*pp_Var3)[in[0xe]];
                                if (in[0xf] != '\0') {
                                  out[0xf] = (char)(*pp_Var3)[in[0xf]];
                                  return;
                                }
                                iVar6 = 0xf;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar4 = -iVar6 + 0x10;
  pcVar7 = out + iVar6;
  if (7 < uVar4) {
    if (((uint)pcVar7 & 1) != 0) {
      *pcVar7 = '\0';
      uVar4 = -iVar6 + 0xf;
      pcVar7 = pcVar7 + 1;
    }
    if (((uint)pcVar7 & 2) != 0) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      uVar4 = uVar4 - 2;
      pcVar7 = pcVar7 + 2;
    }
    if (7 < uVar4) {
      uVar5 = 0;
      do {
        pcVar1 = pcVar7 + uVar5;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        pcVar1 = pcVar7 + uVar5 + 4;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        uVar5 = uVar5 + 8;
      } while (uVar5 < (uVar4 & 0xfffffff8));
      pcVar7 = pcVar7 + uVar5;
    }
  }
  if ((uVar4 & 4) != 0) {
    pcVar7[0] = '\0';
    pcVar7[1] = '\0';
    pcVar7[2] = '\0';
    pcVar7[3] = '\0';
    pcVar7 = pcVar7 + 4;
  }
  if ((uVar4 & 2) != 0) {
    pcVar7[0] = '\0';
    pcVar7[1] = '\0';
    pcVar7 = pcVar7 + 2;
  }
  if ((uVar4 & 1) == 0) {
    return;
  }
  *pcVar7 = '\0';
  return;
}


// ClearIOStates  @ 0007c6c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClearIOStates(void)

{
  return;
}


// ClearLink  @ 000a81d0
void ClearLink(link_t *l)

{
  l->next = l;
  l->prev = l;
  return;
}


// ClientPrintf  @ 0006de80
void ClientPrintf(edict_t *pEdict,PRINT_TYPE ptype,char *szMsg)

{
  client_s *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
  iVar2 = NUM_FOR_EDICT(pEdict);
  pcVar1 = svs.clients;
  if ((iVar2 < 1) || (svs.maxclients < iVar2)) {
    Con_Printf("tried to sprint to a non-client\n");
    return;
  }
  if (svs.clients[iVar2 + -1].fakeclient != false) {
    return;
  }
  if (ptype == print_center) {
    MSG_WriteChar(&svs.clients[iVar2 + -1].netchan.message,0x1a);
  }
  else {
    if ((ptype != print_console) && (ptype != print_chat)) {
      Con_Printf("invalid PRINT_TYPE %i\n");
      return;
    }
    MSG_WriteByte(&svs.clients[iVar2 + -1].netchan.message,8);
  }
  MSG_WriteString(&pcVar1[iVar2 + -1].netchan.message,szMsg);
  return;
}


// ClipVelocity  @ 00099690
int ClipVelocity(vec_t *in,vec_t *normal,vec_t *out,float overbounce)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  
                    /* Unresolved local var: float backoff@[???]
                       Unresolved local var: float change@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int blocked@[???] */
  fVar1 = normal[2];
  uVar3 = (uint)(0.0 < fVar1);
  if (fVar1 == 0.0) {
    uVar3 = 0.0 < fVar1 | 2;
  }
  fVar1 = (fVar1 * in[2] + *in * *normal + in[1] * normal[1]) * overbounce;
  fVar2 = *in - *normal * fVar1;
  if ((fVar2 <= -0.1) || (0.1 <= fVar2)) {
    *out = fVar2;
  }
  else {
    *out = 0.0;
  }
  fVar2 = in[1] - normal[1] * fVar1;
  if ((fVar2 <= -0.1) || (0.1 <= fVar2)) {
    out[1] = fVar2;
  }
  else {
    out[1] = 0.0;
  }
  fVar1 = in[2] - fVar1 * normal[2];
  if ((-0.1 < fVar1) && (fVar1 < 0.1)) {
    out[2] = 0.0;
    return uVar3;
  }
  out[2] = fVar1;
  return uVar3;
}


// CloseSecurityModule  @ 000662c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CloseSecurityModule(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 auStack_1f8 [126];
  
                    /* Unresolved local var: cldll_func_dst_t.conflict cldstNull@[???]
                       Unresolved local var: cl_enginefunc_dst_t.conflict engdstNull@[???] */
  uVar2 = 0;
  do {
    uVar3 = uVar2;
    uVar1 = *(undefined4 *)((int)&PTR_NullDst_000d58c4 + uVar3);
    *(undefined4 *)((int)auStack_1f8 + uVar3) = *(undefined4 *)((int)&PTR_NullDst_000d58c0 + uVar3);
    *(undefined4 *)((int)auStack_1f8 + uVar3 + 4) = uVar1;
    uVar2 = uVar3 + 8;
  } while (uVar3 + 8 < 0x1e8);
  *(undefined4 *)((int)auStack_1f8 + uVar3 + 8) =
       *(undefined4 *)((int)&PTR_NullDst_000d58c8 + uVar3);
  if (g_modfuncs.m_pfnCloseMod != (PFN_CLOSEMOD)0x0) {
    (*g_modfuncs.m_pfnCloseMod)();
  }
  FreeBlob(&g_blobfootprintModule);
  if (g_pvModuleSpecial != (void *)0x0) {
    free(g_pvModuleSpecial);
    g_pvModuleSpecial = (void *)0x0;
  }
  Q_memset(&g_modfuncs,0,0x74);
  uVar2 = 0;
  do {
    uVar3 = uVar2;
    uVar1 = *(undefined4 *)((int)auStack_1f8 + uVar3 + 4);
    *(undefined4 *)((int)&g_engdstAddrs.pfnSPR_Load + uVar3) =
         *(undefined4 *)((int)auStack_1f8 + uVar3);
    *(undefined4 *)((int)&g_engdstAddrs.pfnSPR_Frames + uVar3) = uVar1;
    uVar2 = uVar3 + 8;
  } while (uVar3 + 8 < 0x1e8);
  *(undefined4 *)((int)&g_engdstAddrs.pfnSPR_Height + uVar3) =
       *(undefined4 *)((int)auStack_1f8 + uVar3 + 8);
  Q_memset(&g_module,0,0x14);
  return;
}


// CloseSecurityModule  @ 000664f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CloseSecurityModule(void)

{
                    /* Unresolved local var: cldll_func_dst_t.conflict cldstNull@[???]
                       Unresolved local var: cl_enginefunc_dst_t.conflict engdstNull@[???] */
  if (g_module.fLoaded != 0) {
    CloseSecurityModule();
    return;
  }
  return;
}


// CommatizeNumber  @ 000adf80
char * CommatizeNumber(int num,char *pout)

{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_84 [50];
  char local_52 [49];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_84,0,0x32);
  while (num != 0) {
                    /* Unresolved local var: char[50] tempbuf@[???]
                       Unresolved local var: int temp@[???] */
    iVar1 = num >> 0x1f;
    iVar2 = num / 1000 + iVar1;
    Q_strncpy(local_52,local_84,0x31);
    local_21 = 0;
    __snprintf_chk(local_84,0x32,1,0x32,",%03i%s",num + (iVar2 - iVar1) * -1000,local_52);
    num = iVar2 - iVar1;
  }
  iVar1 = Q_strlen(local_84);
  if (iVar1 < 1) {
    if (iVar1 == 0) {
LAB_000ae082:
      Q_strcpy(pout,"0");
      goto LAB_000ae0b4;
    }
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    while ((local_84[0] - 0x2cU & 0xfb) == 0) {
      iVar2 = iVar2 + 1;
      if (iVar1 == iVar2) goto LAB_000ae082;
      local_84[0] = local_84[iVar2];
    }
  }
  Q_strcpy(pout,local_84 + iVar2);
LAB_000ae0b4:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pout;
}


// CommonLoadSecurityModule  @ 00066390
void CommonLoadSecurityModule(void *nAddrModule)

{
  uint uVar1;
  engdata_t local_88;
  
                    /* Unresolved local var: engdata_t engdata@[???] */
  if (g_modfuncs.m_nVersion == 0x43210004) {
                    /* Unresolved local var: engdata_t engdata@[???] */
    if (g_modfuncs.m_pfnSetEngineVersion != (PFN_SETENGINEVERSION)0x0) {
      (*g_modfuncs.m_pfnSetEngineVersion)(3);
    }
    (*g_modfuncs.m_pfnLoadMod)(nAddrModule);
    (*g_modfuncs.m_pfnGetEngDstAddrs)((cl_enginefunc_dst_t *)&g_engdstAddrs);
    if (g_modfuncs.m_pfnSetModSHelpers != (PFN_SETMODSHELPERS)0x0) {
      (*g_modfuncs.m_pfnSetModSHelpers)(&g_modshelpers);
    }
    uVar1 = 0;
    do {
      *(undefined4 *)((int)&local_88.pcl_enginefuncs + uVar1) =
           *(undefined4 *)((int)&DAT_000d5ac0 + uVar1);
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x7c);
    (*g_modfuncs.m_pfnSetEngData)(&local_88);
    (*g_modfuncs.m_pfnModuleLoaded)();
    g_module.fLoaded = 1;
  }
  else {
                    /* Unresolved local var: cldll_func_dst_t.conflict cldstNull@[???]
                       Unresolved local var: cl_enginefunc_dst_t.conflict engdstNull@[???] */
    if (g_module.fLoaded != 0) {
      CloseSecurityModule();
      return;
    }
  }
  return;
}


// ComparePath1  @ 000adf40
int ComparePath1(char *path1,char *path2)

{
  char cVar1;
  
  for (; (cVar1 = *path1, cVar1 != '/' && cVar1 != '\\' && (cVar1 != '\0')); path1 = path1 + 1) {
    if (cVar1 != *path2) {
      return 0;
    }
    path2 = path2 + 1;
  }
  return 1;
}


// ConstructTutorMessageDecayBuffer  @ 000455d0
void ConstructTutorMessageDecayBuffer(void)

{
  return;
}


// ContinueLoadingProgressBar  @ 000b3340
void ContinueLoadingProgressBar(char *loadingType,int progressPoint,float progressFraction)

{
  return;
}


// ConvertNameToLocalPlatform  @ 0007a050
char * ConvertNameToLocalPlatform(char *pchInName)

{
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  size_t sVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  int in_GS_OFFSET;
  uint local_210 [127];
  undefined1 local_11;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*pchInName == '_') && (pchInName[1] == 'Z')) goto LAB_0007a165;
  pcVar2 = strchr(pchInName,0x40);
  if (pcVar2 == (char *)0x0) {
LAB_0007a2e0:
    pchInName = "unknown";
  }
  else {
                    /* Unresolved local var: char[512] szTempName@[???]
                       Unresolved local var: char * pchAt@[???]
                       Unresolved local var: char * pchClassName@[???]
                       Unresolved local var: char * pchFunctionName@[???] */
    strncpy((char *)local_210,pchInName,0x200);
    local_11 = 0;
    pcVar3 = strchr((char *)local_210,0x40);
    pcVar2 = pcVar3 + 1;
    *pcVar3 = '\0';
    puVar9 = local_210;
    do {
      puVar8 = puVar9;
      uVar4 = *puVar8 + 0xfefefeff & ~*puVar8;
      uVar5 = uVar4 & 0x80808080;
      puVar9 = puVar8 + 1;
    } while (uVar5 == 0);
    bVar1 = (byte)uVar5;
    if ((uVar4 & 0x8080) == 0) {
      bVar1 = (byte)(uVar5 >> 0x10);
      puVar9 = (uint *)((int)puVar8 + 6);
    }
    sVar6 = strlen(pcVar2);
    __snprintf_chk(ConvertNameToLocalPlatform::s_szNewName,0x200,1,0x200,"_ZN%d%s%d%sEv",sVar6,
                   pcVar2,(char *)((int)puVar9 + ((-3 - (uint)CARRY1(bVar1,bVar1)) - (int)local_210)
                                  ),local_210);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: void * addr@[DW_OP_reg0(EAX)] */
    iVar7 = dlsym(g_rgextdll[0].lDLLHandle,ConvertNameToLocalPlatform::s_szNewName);
    puVar9 = local_210;
    if (iVar7 == 0) {
      do {
        puVar8 = puVar9;
        uVar4 = *puVar8 + 0xfefefeff & ~*puVar8;
        uVar5 = uVar4 & 0x80808080;
        puVar9 = puVar8 + 1;
      } while (uVar5 == 0);
      bVar1 = (byte)uVar5;
      if ((uVar4 & 0x8080) == 0) {
        bVar1 = (byte)(uVar5 >> 0x10);
        puVar9 = (uint *)((int)puVar8 + 6);
      }
      sVar6 = strlen(pcVar2);
      __snprintf_chk(ConvertNameToLocalPlatform::s_szNewName,0x200,1,0x200,
                     "_ZN%d%s%d%sEP11CBaseEntity",sVar6,pcVar2,
                     (char *)((int)puVar9 + ((-3 - (uint)CARRY1(bVar1,bVar1)) - (int)local_210)),
                     local_210);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: void * addr@[DW_OP_reg0(EAX)] */
      iVar7 = dlsym(g_rgextdll[0].lDLLHandle,ConvertNameToLocalPlatform::s_szNewName);
      puVar9 = local_210;
      if (iVar7 == 0) {
        do {
          puVar8 = puVar9;
          uVar4 = *puVar8 + 0xfefefeff & ~*puVar8;
          uVar5 = uVar4 & 0x80808080;
          puVar9 = puVar8 + 1;
        } while (uVar5 == 0);
        bVar1 = (byte)uVar5;
        if ((uVar4 & 0x8080) == 0) {
          bVar1 = (byte)(uVar5 >> 0x10);
          puVar9 = (uint *)((int)puVar8 + 6);
        }
        sVar6 = strlen(pcVar2);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: void * addr@[DW_OP_reg0(EAX)] */
        __snprintf_chk(ConvertNameToLocalPlatform::s_szNewName,0x200,1,0x200,
                       "_ZN%d%s%d%sEP11CBaseEntityS1_8USE_TYPEf",sVar6,pcVar2,
                       (char *)((int)puVar9 + ((-3 - (uint)CARRY1(bVar1,bVar1)) - (int)local_210)),
                       local_210);
        iVar7 = dlsym(g_rgextdll[0].lDLLHandle,ConvertNameToLocalPlatform::s_szNewName);
        if (iVar7 == 0) goto LAB_0007a2e0;
      }
    }
    pchInName = ConvertNameToLocalPlatform::s_szNewName;
  }
LAB_0007a165:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pchInName;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CopyString  @ 00036fd0
char * CopyString(char *in)

{
  int iVar1;
  char *dest;
  
                    /* Unresolved local var: char * out@[???] */
  iVar1 = Q_strlen(in);
  dest = Z_Malloc(iVar1 + 1);
  Q_strcpy(dest,in);
  return dest;
}


// CreateEntityList  @ 0005b2d0
int CreateEntityList(SAVERESTOREDATA *pSaveData,int levelMask)

{
  edict_t *peVar1;
  char *pcVar2;
  ENTITYTABLE *pEVar3;
  code *pcVar4;
  int *piVar5;
  int iVar6;
  string_t className;
  int iVar7;
  int iVar8;
  edict_t *peVar9;
  int local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int movedCount@[???]
                       Unresolved local var: int active@[???]
                       Unresolved local var: edict_t * pent@[???] */
  if (0 < pSaveData->tableCount) {
    iVar7 = 0;
    iVar8 = 0;
LAB_0005b2f0:
    do {
      while( true ) {
        peVar9 = (edict_t *)0x0;
        piVar5 = (int *)((int)&pSaveData->pTable->id + iVar8);
        className = piVar5[5];
        if (((className != 0) && (piVar5[3] != 0)) && (iVar6 = *piVar5, 0 < iVar6)) break;
LAB_0005b340:
        piVar5[1] = (int)peVar9;
        iVar7 = iVar7 + 1;
        iVar6 = pSaveData->tableCount;
        iVar8 = iVar8 + 0x18;
        if (iVar6 <= iVar7) goto LAB_0005b34e;
      }
      if ((levelMask & piVar5[4]) != 0) {
        if (svs.maxclients < iVar6) {
          peVar9 = CreateNamedEntity(className);
LAB_0005b33a:
          piVar5 = (int *)((int)&pSaveData->pTable->id + iVar8);
          goto LAB_0005b340;
        }
        peVar9 = svs.clients[iVar6 + -1].edict;
        if (piVar5[4] < 0) {
          if ((svs.clients[iVar6 + -1].active != false) && (peVar9 != (edict_t *)0x0))
          goto LAB_0005b5ea;
        }
        else {
          iVar6 = iVar7;
          Sys_Error("ENTITY IS NOT A PLAYER: %d\n",iVar7);
          piVar5 = (int *)((int)&pSaveData->pTable->id + iVar8);
          if ((svs.clients[*piVar5 + -1].active != false) && (peVar9 != (edict_t *)0x0)) {
            className = piVar5[5];
                    /* Unresolved local var: ENTITYINIT pEntityInit@[???] */
            if (className == 0) {
              Sys_Error("Bad class!!\n",iVar6);
            }
LAB_0005b5ea:
            ReleaseEntityDLLFields(peVar9);
            InitEntityDLLFields(peVar9);
            pcVar2 = pr_strings;
            (peVar9->v).classname = className;
            pcVar4 = (code *)GetEntityInit(pcVar2 + className);
            if (pcVar4 == (code *)0x0) goto LAB_0005b33a;
            iVar7 = iVar7 + 1;
            (*pcVar4)(&peVar9->v);
            *(edict_t **)((int)&pSaveData->pTable->pent + iVar8) = peVar9;
            iVar6 = pSaveData->tableCount;
            iVar8 = iVar8 + 0x18;
            if (iVar6 <= iVar7) break;
            goto LAB_0005b2f0;
          }
        }
        iVar7 = iVar7 + 1;
        piVar5[1] = 0;
        iVar8 = iVar8 + 0x18;
        iVar6 = pSaveData->tableCount;
        if (iVar6 <= iVar7) break;
        goto LAB_0005b2f0;
      }
      if (svs.maxclients < iVar6) goto LAB_0005b340;
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x18;
      piVar5[1] = (int)svs.clients[iVar6 + -1].edict;
      iVar6 = pSaveData->tableCount;
    } while (iVar7 < iVar6);
LAB_0005b34e:
    if (0 < iVar6) {
      iVar8 = 0;
      local_34 = 0;
      do {
        while( true ) {
          pEVar3 = pSaveData->pTable;
          peVar9 = pEVar3[iVar8].pent;
          pSaveData->currentIndex = iVar8;
          iVar7 = pEVar3[iVar8].location;
          pSaveData->size = iVar7;
          pSaveData->pCurrentData = pSaveData->pBaseData + iVar7;
          if ((peVar9 != (edict_t *)0x0) && ((levelMask & pEVar3[iVar8].flags) != 0)) break;
LAB_0005b39c:
          iVar8 = iVar8 + 1;
          if (iVar6 <= iVar8) {
            return local_34;
          }
        }
        if ((pEVar3[iVar8].flags & 0x10000000U) != 0) {
          Con_DPrintf("Merging changes for global: %s\n",pr_strings + pEVar3[iVar8].classname);
          (*gEntityInterface.pfnRestore)(peVar9,pSaveData,1);
          ED_Free(peVar9);
          iVar6 = pSaveData->tableCount;
          goto LAB_0005b39c;
        }
        iVar7 = NUM_FOR_EDICT(peVar9);
        Con_DPrintf("Transferring %s (%d)\n",pr_strings + pSaveData->pTable[iVar8].classname,iVar7);
        iVar7 = (*gEntityInterface.pfnRestore)(peVar9,pSaveData,0);
        if (iVar7 < 0) {
LAB_0005b52f:
          ED_Free(peVar9);
          iVar6 = pSaveData->tableCount;
          goto LAB_0005b39c;
        }
        SV_LinkEdict(peVar9,false);
        pEVar3 = pSaveData->pTable + iVar8;
                    /* Unresolved local var: vec3_t point@[???] */
        if ((-1 < pEVar3->flags) &&
           ((((peVar9->v).movetype != 0xc || (peVar1 = (peVar9->v).aiment, peVar1 == (edict_t *)0x0)
             ) || (((peVar1->v).flags & 8) == 0)))) {
          g_groupmask = (peVar9->v).groupinfo;
          local_28 = ((peVar9->v).absmin[0] + (peVar9->v).absmax[0]) * 0.5;
          local_24 = ((peVar9->v).absmin[1] + (peVar9->v).absmax[1]) * 0.5;
          local_20 = ((peVar9->v).absmin[2] + (peVar9->v).absmax[2]) * 0.5;
          iVar7 = SV_PointContents(&local_28);
          if (iVar7 == -2) {
            Con_DPrintf("Suppressing %s\n",pr_strings + pSaveData->pTable[iVar8].classname);
            goto LAB_0005b52f;
          }
          pEVar3 = pSaveData->pTable + iVar8;
        }
        pEVar3->flags = 0x40000000;
        iVar8 = iVar8 + 1;
        iVar6 = pSaveData->tableCount;
        local_34 = local_34 + 1;
        if (iVar6 <= iVar8) {
          return local_34;
        }
      } while( true );
    }
  }
  return 0;
}


// CreateInterface  @ 000c4940
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
                    /* WARNING: Could not recover jumptable at 0x000c498c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar3 = (*pIVar1->m_CreateFn)();
  return pvVar3;
}


// CreateNamedEntity  @ 00070420
edict_t * CreateNamedEntity(int className)

{
  edict_t *ed;
  code *pcVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: edict_t * pedict@[???]
                       Unresolved local var: ENTITYINIT pEntityInit@[???] */
  if (className == 0) {
    Sys_Error("Spawned a NULL entity!");
  }
  ed = ED_Alloc();
  (ed->v).classname = className;
  pcVar1 = (code *)GetEntityInit(pr_strings + className);
  if (pcVar1 == (code *)0x0) {
    peVar2 = (edict_t *)0x0;
    ED_Free(ed);
    Con_DPrintf("Can\'t create entity: %s\n",pr_strings + className);
  }
  else {
    (*pcVar1)(&ed->v);
    peVar2 = ed;
  }
  return peVar2;
}


// CrossProduct  @ 00060bd0
void CrossProduct(vec_t *v1,vec_t *v2,vec_t *cross)

{
  *cross = v1[1] * v2[2] - v1[2] * v2[1];
  cross[1] = v1[2] * *v2 - *v1 * v2[2];
  cross[2] = *v1 * v2[1] - v1[1] * *v2;
  return;
}


// DirectoryCopy  @ 0005bc00
void DirectoryCopy(char *pPath,FileHandle_t pFile)

{
  char *pInput;
  FileHandle_t file;
  uint size;
  uint uVar1;
  int in_GS_OFFSET;
  uint local_62c;
  char local_628 [260];
  char local_524 [260];
  undefined1 local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: char * findfn@[???]
                       Unresolved local var: char[260] basefindfn@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: FILE * pCopy@[???]
                       Unresolved local var: char[260] szName@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pInput = Sys_FindFirst(pPath,local_628);
  if (pInput != (char *)0x0) {
    do {
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
      __snprintf_chk(local_524,0x104,1,0x104,&DAT_000dde77,Host_SaveGameDirectory::szDirectory,
                     pInput);
      COM_FixSlashes(local_524);
      file = FS_OpenPathID(local_524,"rb","GAMECONFIG");
      if (file == (FileHandle_t)0x0) {
        local_62c = 0;
      }
      else {
        local_62c = FS_Size(file);
      }
      FS_Write(pInput,0x104,1,pFile);
      FS_Write(&local_62c,4,1,pFile);
                    /* Unresolved local var: char[1024] buf@[???]
                       Unresolved local var: int size@[???] */
      for (uVar1 = local_62c; 0 < (int)uVar1; uVar1 = uVar1 - size) {
        size = 0x400;
        if ((int)uVar1 < 0x401) {
          size = uVar1;
        }
        FS_Read(local_420,size,1,file);
        FS_Write(local_420,size,1,pFile);
      }
      FS_Close(file);
      pInput = Sys_FindNext(local_628);
    } while (pInput != (char *)0x0);
  }
  Sys_FindClose();
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// DirectoryCount  @ 0005c880
int DirectoryCount(char *pPath)

{
  char *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: char * findfn@[???] */
  iVar2 = 0;
  pcVar1 = Sys_FindFirstPathID(pPath,"GAMECONFIG");
  while (pcVar1 != (char *)0x0) {
    iVar2 = iVar2 + 1;
    pcVar1 = Sys_FindNext((char *)0x0);
  }
  Sys_FindClose();
  return iVar2;
}


// DirectoryExtract  @ 0005c680
void DirectoryExtract(FileHandle_t pFile,int fileCount)

{
  char *pcVar1;
  char *pcVar2;
  FileHandle_t pOutput;
  int iVar3;
  int in_GS_OFFSET;
  int local_22c;
  char local_228 [260];
  char local_124 [259];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: FILE * pCopy@[???]
                       Unresolved local var: char[260] szName@[???]
                       Unresolved local var: char[260] fileName@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (0 < fileCount) {
    iVar3 = 0;
    do {
                    /* Unresolved local var: char * pchFileExtension@[???] */
      FS_Read(local_124,0x104,1,pFile);
      local_21 = 0;
      FS_Read(&local_22c,4,1,pFile);
      pcVar1 = COM_LastFileExtension(local_124);
      if (pcVar1 == (char *)0x0) {
LAB_0005c72c:
        FS_Seek(pFile,local_22c,FILESYSTEM_SEEK_CURRENT);
      }
      else {
        pcVar2 = Q_strstr(local_124,"\\");
        if (pcVar2 != (char *)0x0) goto LAB_0005c72c;
        pcVar2 = Q_strstr(local_124,":");
        if (pcVar2 != (char *)0x0) goto LAB_0005c72c;
        pcVar2 = Q_strstr(local_124,"..");
        if (pcVar2 != (char *)0x0) goto LAB_0005c72c;
        pcVar2 = Q_strstr(local_124,"~");
        if ((((pcVar2 != (char *)0x0) || (local_124[0] == '/')) || (*pcVar1 != 'H')) ||
           (pcVar1[1] != 'L')) goto LAB_0005c72c;
        pcVar1 = Host_SaveGameDirectory();
        __snprintf_chk(local_228,0x104,1,0x104,&DAT_000dde77,pcVar1,local_124);
        COM_FixSlashes(local_228);
        pOutput = FS_OpenPathID(local_228,"wb","GAMECONFIG");
        FileCopy(pOutput,pFile,local_22c);
        FS_Close(pOutput);
      }
      iVar3 = iVar3 + 1;
    } while (fileCount != iVar3);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// DispatchDirectUserMsg  @ 00045470
int DispatchDirectUserMsg(char *pszName,int iSize,void *pBuf)

{
  return 0;
}


// DoesSphereIntersect  @ 000783a0
qboolean DoesSphereIntersect(float *vSphereCenter,float fSphereRadiusSquared,float *vLinePt,
                            float *vLineDir)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
                    /* Unresolved local var: vec3_t P@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: float b@[???]
                       Unresolved local var: float c@[???]
                       Unresolved local var: float insideSqr@[???] */
  fVar4 = *vLinePt - *vSphereCenter;
  fVar6 = vLinePt[1] - vSphereCenter[1];
  fVar7 = vLinePt[2] - vSphereCenter[2];
  fVar1 = *vLineDir;
  fVar2 = vLineDir[1];
  fVar3 = vLineDir[2];
  fVar5 = fVar7 * fVar3 + fVar6 * fVar2 + fVar4 * fVar1;
  fVar5 = fVar5 + fVar5;
  return (uint)(1e-06 < fVar5 * fVar5 -
                        (fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2) * 4.0 *
                        ((fVar7 * fVar7 + fVar6 * fVar6 + fVar4 * fVar4) - fSphereRadiusSquared));
}


// EngCheckParm  @ 00074780
int EngCheckParm(char *pchCmdLineToken,char **pchNextVal)

{
  int iVar1;
  char *local_14;
  char **local_10 [4];
  
  local_14 = pchCmdLineToken;
  local_10[0] = pchNextVal;
                    /* Unresolved local var: int i@[???] */
  (*g_engdstAddrs.CheckParm)(&local_14,local_10);
  iVar1 = COM_CheckParm(local_14);
  if (local_10[0] != (char **)0x0) {
    if ((iVar1 != 0) && (iVar1 < com_argc + -1)) {
      *local_10[0] = com_argv[iVar1 + 1];
      return iVar1;
    }
    *local_10[0] = (char *)0x0;
  }
  return iVar1;
}


// EngineFprintf  @ 0007af40
void EngineFprintf(void *pfile,char *szFmt,...)

{
  AlertMessage(at_console,"EngineFprintf:  Obsolete API\n");
  return;
}


// EngineWrapper::DemoUpdateClientData  @ 0007cb50
/* DWARF original prototype: void DemoUpdateClientData(EngineWrapper * this, client_data_s * cdat)
    */

void __thiscall EngineWrapper::DemoUpdateClientData(EngineWrapper *this,client_data_s *cdat)

{
  return;
}


// EngineWrapper::EngineWrapper  @ 0007d1b0
/* DWARF original prototype: void EngineWrapper(EngineWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall EngineWrapper::EngineWrapper(EngineWrapper *this,int __in_chrg,void **__vtt_parm)

{
  _func_int_varargs **pp_Var1;
  void **in_stack_ffffffec;
  
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = (_func_int_varargs **)&DAT_000d8270;
  BaseSystemModule::BaseSystemModule(&this->super_BaseSystemModule,__in_chrg + 4,in_stack_ffffffec);
  pp_Var1 = *(_func_int_varargs ***)__in_chrg;
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = pp_Var1;
  *(undefined4 *)&this->super_BaseSystemModule = *(undefined4 *)(__in_chrg + 0xc);
  *(undefined4 *)(pp_Var1[-3] + -4 + (int)((this->super_BaseSystemModule).m_Name + -0x1c)) =
       *(undefined4 *)(__in_chrg + 0x10);
  return;
}


// EngineWrapper::EngineWrapper  @ 0007d200
/* DWARF original prototype: void EngineWrapper(EngineWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall EngineWrapper::EngineWrapper(EngineWrapper *this,int __in_chrg,void **__vtt_parm)

{
  void **in_stack_ffffffec;
  
  *(undefined **)&this->super_BaseSystemModule = &DAT_000d8228;
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = (_func_int_varargs **)&DAT_000d8270;
  BaseSystemModule::BaseSystemModule(&this->super_BaseSystemModule,0xd8378,in_stack_ffffffec);
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = (_func_int_varargs **)0xd8394;
  *(undefined4 *)&this->super_BaseSystemModule = 0xd8454;
  return;
}


// EngineWrapper::ExecuteCommand  @ 0007eef0
/* DWARF original prototype: void ExecuteCommand(EngineWrapper * this, int commandID, char *
   commandLine) */

void __thiscall EngineWrapper::ExecuteCommand(EngineWrapper *this,int commandID,char *commandLine)

{
  BaseSystemModule::ExecuteCommand(&this->super_BaseSystemModule,commandID,commandLine);
  return;
}


// EngineWrapper::ExecuteCommand  @ 0007ef00
/* virtual thunk to EngineWrapper::ExecuteCommand(int, char*) */

void __thiscall EngineWrapper::ExecuteCommand(EngineWrapper *this,int param_1,char *param_2)

{
  ExecuteCommand((EngineWrapper *)
                 ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-7] + -4 +
                 (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1,param_2);
  return;
}


// EngineWrapper::ExecuteCommand  @ 0007ef10
/* non-virtual thunk to EngineWrapper::ExecuteCommand(int, char*) */

void __thiscall EngineWrapper::ExecuteCommand(EngineWrapper *this,int param_1,char *param_2)

{
  ExecuteCommand((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1,
                 param_2);
  return;
}


// EngineWrapper::GetCvarFloat  @ 0007cd60
/* DWARF original prototype: float GetCvarFloat(EngineWrapper * this, char * szName) */

float __thiscall EngineWrapper::GetCvarFloat(EngineWrapper *this,char *szName)

{
  cvar_t *pcVar1;
  
                    /* Unresolved local var: cvar_t * cv@[DW_OP_reg0(EAX)] */
  pcVar1 = Cvar_FindVar(szName);
  if (pcVar1 != (cvar_t *)0x0) {
    return pcVar1->value;
  }
  return 0.0;
}


// EngineWrapper::GetCvarString  @ 0007cd90
/* DWARF original prototype: char * GetCvarString(EngineWrapper * this, char * szName) */

char * __thiscall EngineWrapper::GetCvarString(EngineWrapper *this,char *szName)

{
  cvar_t *pcVar1;
  char *pcVar2;
  
                    /* Unresolved local var: cvar_t * cv@[???] */
  pcVar1 = Cvar_FindVar(szName);
  if (pcVar1 == (cvar_t *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = pcVar1->string;
  }
  return pcVar2;
}


// EngineWrapper::GetName  @ 0007ee90
/* DWARF original prototype: char * GetName(EngineWrapper * this) */

char * __thiscall EngineWrapper::GetName(EngineWrapper *this)

{
  char *pcVar1;
  
  pcVar1 = BaseSystemModule::GetName(&this->super_BaseSystemModule);
  return pcVar1;
}


// EngineWrapper::GetName  @ 0007eea0
/* virtual thunk to EngineWrapper::GetName() */

void __thiscall EngineWrapper::GetName(EngineWrapper *this)

{
  GetName((EngineWrapper *)
          ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0xe] + -4 +
          (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetName  @ 0007eeb0
/* non-virtual thunk to EngineWrapper::GetName() */

void __thiscall EngineWrapper::GetName(EngineWrapper *this)

{
  GetName((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetSerial  @ 0007eec0
/* DWARF original prototype: int GetSerial(EngineWrapper * this) */

int __thiscall EngineWrapper::GetSerial(EngineWrapper *this)

{
  int iVar1;
  
  iVar1 = BaseSystemModule::GetSerial(&this->super_BaseSystemModule);
  return iVar1;
}


// EngineWrapper::GetSerial  @ 0007eed0
/* virtual thunk to EngineWrapper::GetSerial() */

void __thiscall EngineWrapper::GetSerial(EngineWrapper *this)

{
  GetSerial((EngineWrapper *)
            ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0xb] + -4 +
            (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetSerial  @ 0007eee0
/* non-virtual thunk to EngineWrapper::GetSerial() */

void __thiscall EngineWrapper::GetSerial(EngineWrapper *this)

{
  GetSerial((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetState  @ 0007efe0
/* DWARF original prototype: int GetState(EngineWrapper * this) */

int __thiscall EngineWrapper::GetState(EngineWrapper *this)

{
  int iVar1;
  
  iVar1 = BaseSystemModule::GetState(&this->super_BaseSystemModule);
  return iVar1;
}


// EngineWrapper::GetState  @ 0007eff0
/* virtual thunk to EngineWrapper::GetState() */

void __thiscall EngineWrapper::GetState(EngineWrapper *this)

{
  GetState((EngineWrapper *)
           ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0xf] + -4 +
           (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetState  @ 0007f000
/* non-virtual thunk to EngineWrapper::GetState() */

void __thiscall EngineWrapper::GetState(EngineWrapper *this)

{
  GetState((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetStatusLine  @ 0007cbd0
/* non-virtual thunk to EngineWrapper::GetStatusLine() */

void __thiscall EngineWrapper::GetStatusLine(EngineWrapper *this)

{
  SystemWrapper::GetStatusLine
            ((SystemWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetStatusLine  @ 0007cbe0
/* virtual thunk to EngineWrapper::GetStatusLine() */

void __thiscall EngineWrapper::GetStatusLine(EngineWrapper *this)

{
  SystemWrapper::GetStatusLine
            ((SystemWrapper *)
             ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0xc] + -4 +
             (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetSystem  @ 0007efb0
/* DWARF original prototype: IBaseSystem * GetSystem(EngineWrapper * this) */

IBaseSystem * __thiscall EngineWrapper::GetSystem(EngineWrapper *this)

{
  IBaseSystem *pIVar1;
  
  pIVar1 = BaseSystemModule::GetSystem(&this->super_BaseSystemModule);
  return pIVar1;
}


// EngineWrapper::GetSystem  @ 0007efc0
/* virtual thunk to EngineWrapper::GetSystem() */

void __thiscall EngineWrapper::GetSystem(EngineWrapper *this)

{
  GetSystem((EngineWrapper *)
            ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-10] + -4 +
            (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetSystem  @ 0007efd0
/* non-virtual thunk to EngineWrapper::GetSystem() */

void __thiscall EngineWrapper::GetSystem(EngineWrapper *this)

{
  GetSystem((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetTraceEntity  @ 0007cbb0
/* DWARF original prototype: int GetTraceEntity(EngineWrapper * this) */

int __thiscall EngineWrapper::GetTraceEntity(EngineWrapper *this)

{
  return 0;
}


// EngineWrapper::GetType  @ 0007cb20
/* DWARF original prototype: char * GetType(EngineWrapper * this) */

char * __thiscall EngineWrapper::GetType(EngineWrapper *this)

{
  return "enginewrapper002";
}


// EngineWrapper::GetType  @ 0007cb30
/* virtual thunk to EngineWrapper::GetType() */

void __thiscall EngineWrapper::GetType(EngineWrapper *this)

{
  GetType((EngineWrapper *)
          ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0xd] + -4 +
          (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetType  @ 0007cb40
/* non-virtual thunk to EngineWrapper::GetType() */

void __thiscall EngineWrapper::GetType(EngineWrapper *this)

{
  GetType((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetVersion  @ 0007f010
/* DWARF original prototype: int GetVersion(EngineWrapper * this) */

int __thiscall EngineWrapper::GetVersion(EngineWrapper *this)

{
  int iVar1;
  
  iVar1 = BaseSystemModule::GetVersion(&this->super_BaseSystemModule);
  return iVar1;
}


// EngineWrapper::GetVersion  @ 0007f020
/* virtual thunk to EngineWrapper::GetVersion() */

void __thiscall EngineWrapper::GetVersion(EngineWrapper *this)

{
  GetVersion((EngineWrapper *)
             ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0x10] + -4 +
             (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetVersion  @ 0007f030
/* non-virtual thunk to EngineWrapper::GetVersion() */

void __thiscall EngineWrapper::GetVersion(EngineWrapper *this)

{
  GetVersion((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::HudWeaponAnim  @ 0007cb70
/* DWARF original prototype: void HudWeaponAnim(EngineWrapper * this, int iAnim, int body) */

void __thiscall EngineWrapper::HudWeaponAnim(EngineWrapper *this,int iAnim,int body)

{
  return;
}


// EngineWrapper::Init  @ 0007ee00
/* DWARF original prototype: bool Init(EngineWrapper * this, IBaseSystem * system, int serial, char
   * name) */

bool __thiscall EngineWrapper::Init(EngineWrapper *this,IBaseSystem *system,int serial,char *name)

{
  bool bVar1;
  
  bVar1 = BaseSystemModule::Init(&this->super_BaseSystemModule,system,serial,name);
  return bVar1;
}


// EngineWrapper::Init  @ 0007ee10
/* virtual thunk to EngineWrapper::Init(IBaseSystem*, int, char*) */

void __thiscall
EngineWrapper::Init(EngineWrapper *this,IBaseSystem *param_1,int param_2,char *param_3)

{
  Init((EngineWrapper *)
       ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-4] + -4 +
       (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1,param_2,param_3);
  return;
}


// EngineWrapper::Init  @ 0007ee20
/* non-virtual thunk to EngineWrapper::Init(IBaseSystem*, int, char*) */

void __thiscall
EngineWrapper::Init(EngineWrapper *this,IBaseSystem *param_1,int param_2,char *param_3)

{
  Init((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1,param_2,
       param_3);
  return;
}


// EngineWrapper::ReceiveSignal  @ 0007ef20
/* DWARF original prototype: void ReceiveSignal(EngineWrapper * this, ISystemModule * module, uint
   signal, void * data) */

void __thiscall
EngineWrapper::ReceiveSignal(EngineWrapper *this,ISystemModule *module,uint signal,void *data)

{
  BaseSystemModule::ReceiveSignal(&this->super_BaseSystemModule,module,signal,data);
  return;
}


// EngineWrapper::ReceiveSignal  @ 0007ef30
/* virtual thunk to EngineWrapper::ReceiveSignal(ISystemModule*, unsigned int, void*) */

void __thiscall
EngineWrapper::ReceiveSignal(EngineWrapper *this,ISystemModule *param_1,uint param_2,void *param_3)

{
  ReceiveSignal((EngineWrapper *)
                ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-6] + -4 +
                (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1,param_2,param_3);
  return;
}


// EngineWrapper::ReceiveSignal  @ 0007ef40
/* non-virtual thunk to EngineWrapper::ReceiveSignal(ISystemModule*, unsigned int, void*) */

void __thiscall
EngineWrapper::ReceiveSignal(EngineWrapper *this,ISystemModule *param_1,uint param_2,void *param_3)

{
  ReceiveSignal((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1,
                param_2,param_3);
  return;
}


// EngineWrapper::RegisterListener  @ 0007ef50
/* DWARF original prototype: void RegisterListener(EngineWrapper * this, ISystemModule * module) */

void __thiscall EngineWrapper::RegisterListener(EngineWrapper *this,ISystemModule *module)

{
  BaseSystemModule::RegisterListener(&this->super_BaseSystemModule,module);
  return;
}


// EngineWrapper::RegisterListener  @ 0007ef60
/* virtual thunk to EngineWrapper::RegisterListener(ISystemModule*) */

void __thiscall EngineWrapper::RegisterListener(EngineWrapper *this,ISystemModule *param_1)

{
  RegisterListener((EngineWrapper *)
                   ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-8] + -4 +
                   (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1);
  return;
}


// EngineWrapper::RegisterListener  @ 0007ef70
/* non-virtual thunk to EngineWrapper::RegisterListener(ISystemModule*) */

void __thiscall EngineWrapper::RegisterListener(EngineWrapper *this,ISystemModule *param_1)

{
  RegisterListener((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1
                  );
  return;
}


// EngineWrapper::RemoveListener  @ 0007ef80
/* DWARF original prototype: void RemoveListener(EngineWrapper * this, ISystemModule * module) */

void __thiscall EngineWrapper::RemoveListener(EngineWrapper *this,ISystemModule *module)

{
  BaseSystemModule::RemoveListener(&this->super_BaseSystemModule,module);
  return;
}


// EngineWrapper::RemoveListener  @ 0007ef90
/* virtual thunk to EngineWrapper::RemoveListener(ISystemModule*) */

void __thiscall EngineWrapper::RemoveListener(EngineWrapper *this,ISystemModule *param_1)

{
  RemoveListener((EngineWrapper *)
                 ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-9] + -4 +
                 (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1);
  return;
}


// EngineWrapper::RemoveListener  @ 0007efa0
/* non-virtual thunk to EngineWrapper::RemoveListener(ISystemModule*) */

void __thiscall EngineWrapper::RemoveListener(EngineWrapper *this,ISystemModule *param_1)

{
  RemoveListener((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1);
  return;
}


// EngineWrapper::RunFrame  @ 0007ee60
/* DWARF original prototype: void RunFrame(EngineWrapper * this, double time) */

void __thiscall EngineWrapper::RunFrame(EngineWrapper *this,double time)

{
  BaseSystemModule::RunFrame(&this->super_BaseSystemModule,time);
  return;
}


// EngineWrapper::RunFrame  @ 0007ee70
/* virtual thunk to EngineWrapper::RunFrame(double) */

void __thiscall EngineWrapper::RunFrame(EngineWrapper *this,double param_1)

{
  RunFrame((EngineWrapper *)
           ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-5] + -4 +
           (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1);
  return;
}


// EngineWrapper::RunFrame  @ 0007ee80
/* non-virtual thunk to EngineWrapper::RunFrame(double) */

void __thiscall EngineWrapper::RunFrame(EngineWrapper *this,double param_1)

{
  RunFrame((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1);
  return;
}


// EngineWrapper::SetCvar  @ 0007cdc0
/* DWARF original prototype: void SetCvar(EngineWrapper * this, char * szName, char * szValue) */

void __thiscall EngineWrapper::SetCvar(EngineWrapper *this,char *szName,char *szValue)

{
  Cvar_Set(szName,szValue);
  return;
}


// EngineWrapper::ShutDown  @ 0007ee30
/* DWARF original prototype: void ShutDown(EngineWrapper * this) */

void __thiscall EngineWrapper::ShutDown(EngineWrapper *this)

{
  BaseSystemModule::ShutDown(&this->super_BaseSystemModule);
  return;
}


// EngineWrapper::ShutDown  @ 0007ee40
/* virtual thunk to EngineWrapper::ShutDown() */

void __thiscall EngineWrapper::ShutDown(EngineWrapper *this)

{
  ShutDown((EngineWrapper *)
           ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0x11] + -4 +
           (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::ShutDown  @ 0007ee50
/* non-virtual thunk to EngineWrapper::ShutDown() */

void __thiscall EngineWrapper::ShutDown(EngineWrapper *this)

{
  ShutDown((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::ValidStuffText  @ 0007cba0
/* DWARF original prototype: bool ValidStuffText(EngineWrapper * this, char * pMsg) */

bool __thiscall EngineWrapper::ValidStuffText(EngineWrapper *this,char *pMsg)

{
  return true;
}


// EngineWrapper::~EngineWrapper  @ 0007ccb0
/* DWARF original prototype: void ~EngineWrapper(EngineWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this,int __in_chrg,void **__vtt_parm)

{
  void **in_stack_ffffffec;
  
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = (_func_int_varargs **)0xd8394;
  *(undefined4 *)&this->super_BaseSystemModule = 0xd8454;
  BaseSystemModule::~BaseSystemModule(&this->super_BaseSystemModule,0xd8378,in_stack_ffffffec);
  return;
}


// EngineWrapper::~EngineWrapper  @ 0007cce0
/* virtual thunk to EngineWrapper::~EngineWrapper() */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~EngineWrapper((EngineWrapper *)
                 ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-3] + -4 +
                 (int)((this->super_BaseSystemModule).m_Name + -0x1c)),in_stack_00000008,
                 in_stack_0000000c);
  return;
}


// EngineWrapper::~EngineWrapper  @ 0007ccf0
/* non-virtual thunk to EngineWrapper::~EngineWrapper() */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~EngineWrapper((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),
                 in_stack_00000008,in_stack_0000000c);
  return;
}


// EngineWrapper::~EngineWrapper  @ 0007cd00
/* DWARF original prototype: void ~EngineWrapper(EngineWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this,int __in_chrg,void **__vtt_parm)

{
  void **in_stack_ffffffec;
  
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = (_func_int_varargs **)0xd8394;
  *(undefined4 *)&this->super_BaseSystemModule = 0xd8454;
  BaseSystemModule::~BaseSystemModule(&this->super_BaseSystemModule,0xd8378,in_stack_ffffffec);
  operator_delete(this);
  return;
}


// EngineWrapper::~EngineWrapper  @ 0007cd40
/* virtual thunk to EngineWrapper::~EngineWrapper() */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~EngineWrapper((EngineWrapper *)
                 ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-3] + -4 +
                 (int)((this->super_BaseSystemModule).m_Name + -0x1c)),in_stack_00000008,
                 in_stack_0000000c);
  return;
}


// EngineWrapper::~EngineWrapper  @ 0007cd50
/* non-virtual thunk to EngineWrapper::~EngineWrapper() */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~EngineWrapper((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),
                 in_stack_00000008,in_stack_0000000c);
  return;
}


// EngineWrapper::~EngineWrapper  @ 0007d240
/* DWARF original prototype: void ~EngineWrapper(EngineWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this,int __in_chrg,void **__vtt_parm)

{
  _func_int_varargs **pp_Var1;
  
  pp_Var1 = *(_func_int_varargs ***)__in_chrg;
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = pp_Var1;
  *(undefined4 *)&this->super_BaseSystemModule = *(undefined4 *)(__in_chrg + 0xc);
  *(undefined4 *)(pp_Var1[-3] + -4 + (int)((this->super_BaseSystemModule).m_Name + -0x1c)) =
       *(undefined4 *)(__in_chrg + 0x10);
  BaseSystemModule::~BaseSystemModule(&this->super_BaseSystemModule,__in_chrg + 4,__vtt_parm);
  return;
}


// EntOffsetOfPEntity  @ 000755f0
int EntOffsetOfPEntity(edict_t *pEdict)

{
  return (int)pEdict - (int)sv.edicts;
}


// EntityInSolid  @ 0005b230
int EntityInSolid(edict_t *pent)

{
  edict_t *peVar1;
  int iVar2;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t point@[???] */
  if ((((pent->v).movetype == 0xc) && (peVar1 = (pent->v).aiment, peVar1 != (edict_t *)0x0)) &&
     (((peVar1->v).flags & 8) != 0)) {
    return 0;
  }
  g_groupmask = (pent->v).groupinfo;
  local_18 = ((pent->v).absmin[0] + (pent->v).absmax[0]) * 0.5;
  local_14 = ((pent->v).absmin[1] + (pent->v).absmax[1]) * 0.5;
  local_10 = ((pent->v).absmin[2] + (pent->v).absmax[2]) * 0.5;
  iVar2 = SV_PointContents(&local_18);
  return (uint)(iVar2 == -2);
}


// EntityInit  @ 00059c80
void EntityInit(edict_t *pEdict,int className)

{
  char *pcVar1;
  code *UNRECOVERED_JUMPTABLE;
  
                    /* Unresolved local var: ENTITYINIT pEntityInit@[???] */
  if (className == 0) {
    Sys_Error("Bad class!!\n");
  }
  ReleaseEntityDLLFields(pEdict);
  InitEntityDLLFields(pEdict);
  pcVar1 = pr_strings;
  (pEdict->v).classname = className;
  UNRECOVERED_JUMPTABLE = (code *)GetEntityInit(pcVar1 + className);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00059cd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}


// EntityPatchRead  @ 0005ac10
void EntityPatchRead(SAVERESTOREDATA *pSaveData,char *level)

{
  FileHandle_t file;
  int iVar1;
  int in_GS_OFFSET;
  int local_12c;
  int local_128;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char[260] name@[???]
                       Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int entityId@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
  __snprintf_chk(local_124,0x104,1,0x104,"%s%s.HL3",Host_SaveGameDirectory::szDirectory,level);
  COM_FixSlashes(local_124);
  file = FS_OpenPathID(local_124,"rb","GAMECONFIG");
  if (file != (FileHandle_t)0x0) {
    iVar1 = 0;
    FS_Read(&local_12c,4,1,file);
    if (0 < local_12c) {
      do {
        iVar1 = iVar1 + 1;
        FS_Read(&local_128,4,1,file);
        pSaveData->pTable[local_128].flags = 0x40000000;
      } while (iVar1 < local_12c);
    }
    FS_Close(file);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// EntityPatchWrite  @ 0005a330
void EntityPatchWrite(SAVERESTOREDATA *pSaveData,char *level)

{
  ENTITYTABLE *pEVar1;
  bool bVar2;
  FileHandle_t file;
  ENTITYTABLE *pEVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  int local_12c;
  int local_128;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char[260] name@[???]
                       Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int size@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
  __snprintf_chk(local_124,0x104,1,0x104,"%s%s.HL3",Host_SaveGameDirectory::szDirectory,level);
  COM_FixSlashes(local_124);
  file = FS_OpenPathID(local_124,"wb","GAMECONFIG");
  if (file != (FileHandle_t)0x0) {
    iVar5 = pSaveData->tableCount;
    local_128 = 0;
    local_12c = 0;
    if (0 < iVar5) {
      pEVar3 = pSaveData->pTable;
      iVar4 = 0;
      pEVar1 = pEVar3 + iVar5;
      bVar2 = false;
      do {
        if ((pEVar3->flags & 0x40000000) != 0) {
          iVar4 = iVar4 + 1;
          bVar2 = true;
        }
        pEVar3 = pEVar3 + 1;
      } while (pEVar1 != pEVar3);
      local_12c = iVar5;
      if (bVar2) {
        local_128 = iVar4;
      }
    }
    FS_Write(&local_128,4,1,file);
    iVar5 = pSaveData->tableCount;
    local_12c = 0;
    if (0 < iVar5) {
      do {
        while ((pSaveData->pTable[local_12c].flags & 0x40000000) == 0) {
          local_12c = local_12c + 1;
          if (iVar5 <= local_12c) goto LAB_0005a4bf;
        }
        FS_Write(&local_12c,4,1,file);
        iVar5 = pSaveData->tableCount;
        local_12c = local_12c + 1;
      } while (local_12c < iVar5);
    }
LAB_0005a4bf:
    FS_Close(file);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// EntryInTable  @ 0005b120
int EntryInTable(SAVERESTOREDATA *pSaveData,char *pMapName,int index)

{
  int iVar1;
  int iVar2;
  LEVELLIST *s1;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = index + 1;
  if (iVar2 < pSaveData->connectionCount) {
    s1 = pSaveData->levelList + index + 1;
    do {
      iVar1 = Q_strcmp(s1->mapName,pMapName);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      s1 = s1 + 1;
    } while (iVar2 < pSaveData->connectionCount);
  }
  return -1;
}


// F  @ 0007bd60
void F(IEngineAPI **api)

{
  CreateInterfaceFn p_Var1;
  IEngineAPI *pIVar2;
  
  p_Var1 = Sys_GetFactoryThis();
  pIVar2 = (*p_Var1)("VENGINE_LAUNCHER_API_VERSION002",(int *)0x0);
  *api = pIVar2;
  return;
}


// FIsBlob  @ 0004c860
char FIsBlob(char *pstFileName)

{
  return '\0';
}


// FileCopy  @ 0005bb50
void FileCopy(FileHandle_t pOutput,FileHandle_t pInput,int fileSize)

{
  int size;
  int in_GS_OFFSET;
  undefined1 local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: char[1024] buf@[???]
                       Unresolved local var: int size@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (0 < fileSize) {
    do {
      size = 0x400;
      if (fileSize < 0x401) {
        size = fileSize;
      }
      fileSize = fileSize - size;
      FS_Read(local_420,size,1,pInput);
      FS_Write(local_420,size,1,pOutput);
    } while (0 < fileSize);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// FileSize  @ 0005bb30
int FileSize(FileHandle_t pFile)

{
  uint uVar1;
  
  if (pFile != (FileHandle_t)0x0) {
    uVar1 = FS_Size(pFile);
    return uVar1;
  }
  return 0;
}


// FindAddressInTable  @ 0007a010
char * FindAddressInTable(extensiondll_t *pDll,uint32 function)

{
  int iVar1;
  undefined1 local_1c [8];
  char *local_14;
  
                    /* Unresolved local var: Dl_info addrInfo@[???] */
  iVar1 = dladdr(function,local_1c);
  if (iVar1 != 0) {
    return local_14;
  }
  return (char *)0x0;
}


// FindEntityByString  @ 00070730
edict_t * FindEntityByString(edict_t *pEdictStartSearchAfter,char *pszField,char *pszValue)

{
  edict_t *peVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  edict_t *peVar5;
  char *s1;
  int iVar6;
  int local_24;
  
                    /* Unresolved local var: int iField@[???] */
  iVar2 = iGetIndex(pszField);
  if ((pszValue == (char *)0x0) || (iVar2 == -1)) {
    peVar5 = (edict_t *)0x0;
  }
  else {
    if (pEdictStartSearchAfter == (edict_t *)0x0) {
      iVar3 = 1;
    }
    else {
      iVar3 = NUM_FOR_EDICT(pEdictStartSearchAfter);
      iVar3 = iVar3 + 1;
    }
                    /* Unresolved local var: int e@[???]
                       Unresolved local var: char * t@[???]
                       Unresolved local var: edict_t * ed@[???] */
    peVar5 = sv.edicts;
    if (iVar3 < sv.num_edicts) {
      iVar6 = iVar3 * 0x324;
      local_24 = sv.num_edicts;
      do {
        peVar1 = (edict_t *)((int)peVar5->leafnums + iVar6 + -0x18);
        if (peVar1->free == false) {
          s1 = pr_strings + *(int *)((int)(peVar1->v).origin + iVar2 + -8);
          if ((s1 != (char *)0x0) && (pr_strings != s1)) {
            iVar4 = Q_strcmp(s1,pszValue);
            if (iVar4 == 0) {
              return peVar1;
            }
            local_24 = sv.num_edicts;
            peVar5 = sv.edicts;
          }
        }
        iVar3 = iVar3 + 1;
        iVar6 = iVar6 + 0x324;
      } while (iVar3 < local_24);
    }
  }
  return peVar5;
}


// FindEntityByVars  @ 00075710
edict_t * FindEntityByVars(entvars_t *pvars)

{
  edict_t *peVar1;
  edict_t *peVar2;
  edict_t *peVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  if (sv.num_edicts < 1) {
LAB_00075757:
    peVar3 = (edict_t *)0x0;
  }
  else {
                    /* Unresolved local var: edict_t * pEdict@[???] */
    peVar3 = sv.edicts;
    if (pvars != &(sv.edicts)->v) {
      iVar4 = 0;
      peVar2 = sv.edicts;
      do {
        peVar3 = peVar2 + 1;
        iVar4 = iVar4 + 1;
        if (iVar4 == sv.num_edicts) goto LAB_00075757;
        peVar1 = peVar2 + 1;
        peVar2 = peVar3;
      } while (pvars != &peVar1->v);
    }
  }
  return peVar3;
}


// FindEntityInSphere  @ 00070250
edict_t * FindEntityInSphere(edict_t *pEdictStartSearchAfter,float *org,float rad)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  edict_t *peVar6;
  client_s *pcVar7;
  
                    /* Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: float eorg@[???]
                       Unresolved local var: int e@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float distSquared@[???] */
  if (pEdictStartSearchAfter == (edict_t *)0x0) {
    iVar5 = 1;
  }
  else {
    iVar5 = NUM_FOR_EDICT(pEdictStartSearchAfter);
    iVar5 = iVar5 + 1;
  }
  fVar4 = rad * rad;
  if (iVar5 < sv.num_edicts) {
    pcVar7 = svs.clients + iVar5 + -1;
    peVar6 = sv.edicts + iVar5;
    do {
      if (((peVar6->free == false) && ((peVar6->v).classname != 0)) &&
         ((svs.maxclients < iVar5 || (pcVar7->active != false)))) {
        if (fVar4 < 0.0) {
          fVar1 = 0.0;
        }
        else {
          fVar1 = *org;
          fVar2 = (peVar6->v).absmin[0];
          if ((fVar1 < fVar2) || (fVar2 = (peVar6->v).absmax[0], fVar2 < fVar1)) {
            fVar1 = (fVar1 - fVar2) * (fVar1 - fVar2) + 0.0;
            if (fVar4 < fVar1) goto LAB_00070380;
          }
          else {
            fVar1 = 0.0;
          }
          fVar2 = org[1];
          fVar3 = (peVar6->v).absmin[1];
          if ((fVar2 < fVar3) || (fVar3 = (peVar6->v).absmax[1], fVar3 < fVar2)) {
            fVar2 = (fVar2 - fVar3) * (fVar2 - fVar3);
          }
          else {
            fVar2 = 0.0;
          }
          fVar1 = fVar2 + fVar1;
          if (fVar1 <= fVar4) {
            fVar2 = org[2];
            fVar3 = (peVar6->v).absmin[2];
            if ((fVar2 < fVar3) || (fVar3 = (peVar6->v).absmax[2], fVar3 < fVar2)) {
              fVar2 = (fVar2 - fVar3) * (fVar2 - fVar3);
            }
            else {
              fVar2 = 0.0;
            }
            fVar1 = fVar2 + fVar1;
          }
        }
LAB_00070380:
        if (fVar1 <= fVar4) {
          return peVar6;
        }
      }
      iVar5 = iVar5 + 1;
      peVar6 = peVar6 + 1;
      pcVar7 = pcVar7 + 1;
    } while (iVar5 != sv.num_edicts);
  }
  return sv.edicts;
}


// FindMiptex  @ 000a6f10
int FindMiptex(char *name)

{
  int iVar1;
  int iVar2;
  char (*pacVar3) [64];
  
                    /* Unresolved local var: int i@[???] */
  if (nummiptex < 1) {
    iVar2 = 0;
  }
  else {
    pacVar3 = miptex;
    iVar2 = 0;
    do {
      iVar1 = Q_strcasecmp(name,pacVar3);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      pacVar3 = pacVar3 + 1;
    } while (iVar2 < nummiptex);
    if (nummiptex == 0x200) {
      Sys_Error("Exceeded MAX_MAP_TEXTURES");
    }
  }
  Q_strncpy(miptex[iVar2],name,0x3f);
  miptex[iVar2][0x3f] = '\0';
  nummiptex = nummiptex + 1;
  return iVar2;
}


// FindNameInTable  @ 0007a040
uint32 FindNameInTable(extensiondll_t *pDll,char *pName)

{
  uint32 uVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: void * addr@[???] */
  uVar1 = dlsym();
  return uVar1;
}


// FindPassableSpace  @ 00058e30
int FindPassableSpace(edict_t *pEdict,vec_t *direction,float step)

{
  vec_t *veca;
  vec_t vVar1;
  vec_t vVar2;
  edict_t *peVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  iVar4 = 100;
  veca = (pEdict->v).origin;
  do {
    VectorMA(veca,step,direction,veca);
    peVar3 = SV_TestEntityPosition(pEdict);
    if (peVar3 == (edict_t *)0x0) {
      vVar1 = (pEdict->v).origin[1];
      vVar2 = (pEdict->v).origin[2];
      (pEdict->v).oldorigin[0] = (pEdict->v).origin[0];
      (pEdict->v).oldorigin[1] = vVar1;
      (pEdict->v).oldorigin[2] = vVar2;
      return 1;
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return 0;
}


// FloatNoSwap  @ 00039b10
float FloatNoSwap(float f)

{
  return f;
}


// FloatSwap  @ 00039ad0
float FloatSwap(float f)

{
                    /* Unresolved local var: anon_union_4_2_94730025 dat1@[???]
                       Unresolved local var: anon_union_4_2_94730025 dat2@[???] */
  return (float)((uint)CONCAT11((char)((uint)f >> 0x10),(char)((uint)f >> 0x18)) |
                 ((uint)f & 0xff00) << 8 | (int)f << 0x18);
}


// FloorDivMod  @ 00061210
void FloorDivMod(double numer,double denom,int *quotient,int *rem)

{
  int iVar1;
  uint uVar2;
  double dVar3;
  
                    /* Unresolved local var: int q@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: double x@[???] */
  if (denom <= 0.0) {
    Sys_Error("FloorDivMod: bad denominator %d\n",SUB84(denom,0),(int)((ulonglong)denom >> 0x20));
  }
  if (numer < 0.0) {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    dVar3 = ROUND(-numer / denom);
    uVar2 = (uint)dVar3;
    dVar3 = floor(-numer - dVar3 * denom);
    if ((int)dVar3 == 0) {
      uVar2 = -uVar2;
      iVar1 = 0;
    }
    else {
      uVar2 = ~uVar2;
      iVar1 = (int)denom - (int)dVar3;
    }
  }
  else {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    uVar2 = (uint)ROUND(numer / denom);
    dVar3 = floor(numer - denom * ROUND(numer / denom));
    iVar1 = (int)dVar3;
  }
  *quotient = uVar2;
  *rem = iVar1;
  return;
}


// ForwardSlashes  @ 000a6410
void ForwardSlashes(char *pname)

{
  char cVar1;
  
  cVar1 = *pname;
  do {
    if (cVar1 == '\0') {
      return;
    }
    while (cVar1 != '\\') {
      pname = pname + 1;
      cVar1 = *pname;
      if (cVar1 == '\0') {
        return;
      }
    }
    *pname = '/';
    pname = pname + 1;
    cVar1 = *pname;
  } while( true );
}


// FreeAllEntPrivateData  @ 00075570
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FreeAllEntPrivateData(void)

{
  void *p;
  edict_t *peVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < sv.num_edicts) {
    iVar2 = 0;
    iVar3 = 0;
    do {
      peVar1 = (edict_t *)((int)(sv.edicts)->leafnums + iVar3 + -0x18);
      p = peVar1->pvPrivateData;
      if (p != (void *)0x0) {
        if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
          (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(peVar1);
          p = peVar1->pvPrivateData;
        }
        Mem_Free(p);
      }
      peVar1->pvPrivateData = (void *)0x0;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x324;
    } while (iVar2 < sv.num_edicts);
  }
  return;
}


// FreeBlob  @ 0004c990
void FreeBlob(BlobFootprint_t *pblobfootprint)

{
  if (pblobfootprint->m_hDll == 0) {
    return;
  }
  dlclose();
  return;
}


// FreeEntPrivateData  @ 00075530
void FreeEntPrivateData(edict_t *pEdict)

{
  void *p;
  
  p = pEdict->pvPrivateData;
  if (p != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(pEdict);
      p = pEdict->pvPrivateData;
    }
    Mem_Free(p);
  }
  pEdict->pvPrivateData = (void *)0x0;
  return;
}


// FunctionFromName  @ 0007aba0
uint32 FunctionFromName(char *pName)

{
  char *pcVar1;
  uint32 uVar2;
  extensiondll_t *peVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uint32 function@[???]
                       Unresolved local var: char * pchFixedName@[???] */
  iVar4 = 0;
  peVar3 = g_rgextdll;
  pcVar1 = ConvertNameToLocalPlatform(pName);
  if (0 < g_iextdllMac) {
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: void * addr@[???] */
      uVar2 = dlsym(peVar3->lDLLHandle,pcVar1);
      if (uVar2 != 0) {
        return uVar2;
      }
      iVar4 = iVar4 + 1;
      peVar3 = peVar3 + 1;
    } while (iVar4 < g_iextdllMac);
  }
  Con_Printf("Can\'t find proc: %s\n",pcVar1);
  return 0;
}


// GameSetBackground  @ 00079fa0
void GameSetBackground(qboolean bNewSetting)

{
  gfBackground = bNewSetting;
  return;
}


// GameSetState  @ 00079f90
void GameSetState(int iState)

{
  giActive = iState;
  return;
}


// GameSetSubState  @ 00079f60
void GameSetSubState(int iSubState)

{
  if ((iSubState & 2U) == 0) {
    if (iSubState != 1) {
      giSubState = iSubState;
    }
    return;
  }
  giSubState = 1;
  return;
}


// GetAttachment  @ 00078660
void GetAttachment(edict_t *pEdict,int iAttachment,float *rgflOrigin,float *rgflAngles)

{
  int iVar1;
  studiohdr_t *psVar2;
  float local_18;
  vec_t local_14;
  vec_t local_10;
  
                    /* Unresolved local var: mstudioattachment_t * pattachment@[???]
                       Unresolved local var: vec3_t angles@[???] */
  psVar2 = Mod_Extradata(sv.models[(pEdict->v).modelindex]);
  local_10 = (pEdict->v).angles[2];
  local_14 = (pEdict->v).angles[1];
  local_18 = -(pEdict->v).angles[0];
  iVar1 = psVar2->attachmentindex + iAttachment * 0x58;
  pstudiohdr = psVar2;
  (*g_pSvBlendingAPI->SV_StudioSetupBones)
            (sv.models[(pEdict->v).modelindex],(pEdict->v).frame,(pEdict->v).sequence,&local_18,
             (pEdict->v).origin,(pEdict->v).controller,(pEdict->v).blending,
             *(int *)(psVar2->name + iVar1 + 0x1c),pEdict);
  if (rgflOrigin != (float *)0x0) {
    VectorTransform((vec_t *)(psVar2->name + iVar1 + 0x20),
                    bonetransform[*(int *)(psVar2->name + iVar1 + 0x1c)],rgflOrigin);
  }
  return;
}


// GetBaseDirectory  @ 0004b130
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * GetBaseDirectory(void)

{
  return s_pBaseDir;
}


// GetBonePosition  @ 00078580
void GetBonePosition(edict_t *pEdict,int iBone,float *rgflOrigin,float *rgflAngles)

{
  pstudiohdr = Mod_Extradata(sv.models[(pEdict->v).modelindex]);
  (*g_pSvBlendingAPI->SV_StudioSetupBones)
            (sv.models[(pEdict->v).modelindex],(pEdict->v).frame,(pEdict->v).sequence,
             (pEdict->v).angles,(pEdict->v).origin,(pEdict->v).controller,(pEdict->v).blending,iBone
             ,pEdict);
  if (rgflOrigin != (float *)0x0) {
    *rgflOrigin = bonetransform[iBone][0][3];
    rgflOrigin[1] = bonetransform[iBone][1][3];
    rgflOrigin[2] = bonetransform[iBone][2][3];
  }
  return;
}


// GetChallengeNr  @ 00086c60
int GetChallengeNr(netadr_t *adr)

{
  qboolean qVar1;
  int32 iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int local_24;
  int local_20;
  
                    /* Unresolved local var: int oldest@[???]
                       Unresolved local var: int oldestTime@[???]
                       Unresolved local var: int i@[???] */
  piVar5 = &g_rg_sv_challenges[0].time;
  iVar4 = 0;
  local_24 = 0x7fffffff;
  local_20 = 0;
  do {
    qVar1 = NET_CompareBaseAdr(*adr,g_rg_sv_challenges[iVar4].adr);
    if (qVar1 != false) {
      g_rg_sv_challenges[iVar4].time = (int)realtime;
      local_20 = iVar4;
      goto LAB_00086d1b;
    }
    if (*piVar5 < local_24) {
      local_24 = *piVar5;
      local_20 = iVar4;
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 7;
  } while (iVar4 != 0x400);
  iVar2 = RandomLong(0,0x8fff);
  uVar3 = RandomLong(0,0xffff);
  g_rg_sv_challenges[local_20].challenge = uVar3 | iVar2 << 0x10;
  g_rg_sv_challenges[local_20].adr.type = net_from.type;
  *&g_rg_sv_challenges[local_20].adr.ip = net_from.ip;
  *(undefined4 *)g_rg_sv_challenges[local_20].adr.ipx = net_from.ipx._0_4_;
  *(undefined4 *)(g_rg_sv_challenges[local_20].adr.ipx + 4) = net_from.ipx._4_4_;
  *(undefined4 *)(g_rg_sv_challenges[local_20].adr.ipx + 8) = net_from._16_4_;
  g_rg_sv_challenges[local_20].time = (int)realtime;
LAB_00086d1b:
  return g_rg_sv_challenges[local_20].challenge;
}


// GetCurrentSteamAppName  @ 0007bbf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * GetCurrentSteamAppName(void)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = "Counter-Strike";
  iVar1 = strcasecmp(com_gamedir,"cstrike");
  if (iVar1 != 0) {
    iVar1 = strcasecmp(com_gamedir,"cstrike_beta");
    if (iVar1 != 0) {
      pcVar2 = "Half-Life";
      iVar1 = strcasecmp(com_gamedir,"valve");
      if (iVar1 != 0) {
        pcVar2 = "Ricochet";
        iVar1 = strcasecmp(com_gamedir,"ricochet");
        if (iVar1 != 0) {
          pcVar2 = "Day of Defeat";
          iVar1 = strcasecmp(com_gamedir,"dod");
          if (iVar1 != 0) {
            pcVar2 = "Team Fortress Classic";
            iVar1 = strcasecmp(com_gamedir,"tfc");
            if (iVar1 != 0) {
              pcVar2 = "Deathmatch Classic";
              iVar1 = strcasecmp(com_gamedir,"dmc");
              if (iVar1 != 0) {
                pcVar2 = "Half-Life";
                iVar1 = strcasecmp(com_gamedir,"czero");
                if (iVar1 == 0) {
                  pcVar2 = "Condition Zero";
                }
              }
            }
          }
        }
      }
    }
  }
  return pcVar2;
}


// GetDispatch  @ 00079fb0
DISPATCHFUNCTION GetDispatch(char *pname)

{
  DISPATCHFUNCTION p_Var1;
  extensiondll_t *peVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DISPATCHFUNCTION pDispatch@[???] */
  iVar3 = 0;
  peVar2 = g_rgextdll;
  if (0 < g_iextdllMac) {
    do {
      p_Var1 = (DISPATCHFUNCTION)dlsym(peVar2->lDLLHandle,pname);
      if (p_Var1 != (DISPATCHFUNCTION)0x0) {
        return p_Var1;
      }
      iVar3 = iVar3 + 1;
      peVar2 = peVar2 + 1;
    } while (iVar3 < g_iextdllMac);
  }
  return (DISPATCHFUNCTION)0x0;
}


// GetEntityIllum  @ 00070810
int GetEntityIllum(edict_t *pEnt)

{
  int iVar1;
  
                    /* Unresolved local var: int iReturn@[DW_OP_reg0(EAX)]
                       Unresolved local var: colorVec cvFloorColor@[???]
                       Unresolved local var: int iIndex@[???] */
  if (pEnt == (edict_t *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = NUM_FOR_EDICT(pEnt);
    if (iVar1 <= svs.maxclients) {
      return (pEnt->v).light_level;
    }
    iVar1 = 0;
    if (2 < cls.state - ca_connected) {
      iVar1 = 0x80;
    }
  }
  return iVar1;
}


// GetEntityInit  @ 0007a2f0
int GetEntityInit(undefined4 param_1)

{
  int iVar1;
  extensiondll_t *peVar2;
  int iVar3;
  
  iVar3 = 0;
  peVar2 = g_rgextdll;
  if (0 < g_iextdllMac) {
    do {
      iVar1 = dlsym(peVar2->lDLLHandle,param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar3 = iVar3 + 1;
      peVar2 = peVar2 + 1;
    } while (iVar3 < g_iextdllMac);
  }
  return 0;
}


// GetFileSystemFactory  @ 0004b140
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * GetFileSystemFactory(void)

{
  return g_FileSystemFactory;
}


// GetGameAppID  @ 00095570
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int GetGameAppID(void)

{
  int iVar1;
  uint uVar2;
  int in_GS_OFFSET;
  char local_218 [260];
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char[260] gd@[???]
                       Unresolved local var: char[260] arg@[???]
                       Unresolved local var: int i@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  COM_ParseDirectoryFromCmd("-game",local_114,0x104,"valve");
  COM_FileBase(local_114,local_218);
  iVar1 = strcasecmp(g_GameToAppIDMap[0].pGameDir,local_218);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = strcasecmp(g_GameToAppIDMap[1].pGameDir,local_218);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = strcasecmp(g_GameToAppIDMap[2].pGameDir,local_218);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = strcasecmp(g_GameToAppIDMap[3].pGameDir,local_218);
        if (iVar1 == 0) {
          iVar1 = 3;
        }
        else {
          iVar1 = strcasecmp(g_GameToAppIDMap[4].pGameDir,local_218);
          if (iVar1 == 0) {
            iVar1 = 4;
          }
          else {
            iVar1 = strcasecmp(g_GameToAppIDMap[5].pGameDir,local_218);
            if (iVar1 == 0) {
              iVar1 = 5;
            }
            else {
              iVar1 = strcasecmp(g_GameToAppIDMap[6].pGameDir,local_218);
              if (iVar1 == 0) {
                iVar1 = 6;
              }
              else {
                iVar1 = strcasecmp(g_GameToAppIDMap[7].pGameDir,local_218);
                if (iVar1 == 0) {
                  iVar1 = 7;
                }
                else {
                  iVar1 = strcasecmp(g_GameToAppIDMap[8].pGameDir,local_218);
                  if (iVar1 == 0) {
                    iVar1 = 8;
                  }
                  else {
                    iVar1 = strcasecmp(g_GameToAppIDMap[9].pGameDir,local_218);
                    if (iVar1 == 0) {
                      iVar1 = 9;
                    }
                    else {
                      iVar1 = strcasecmp(g_GameToAppIDMap[10].pGameDir,local_218);
                      uVar2 = 0x46;
                      if (iVar1 != 0) goto LAB_000956d8;
                      iVar1 = 10;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar2 = g_GameToAppIDMap[iVar1].iAppID;
LAB_000956d8:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// GetIOFunction  @ 0007a350
FIELDIOFUNCTION GetIOFunction(char *pName)

{
  FIELDIOFUNCTION p_Var1;
  extensiondll_t *peVar2;
  int iVar3;
  
  iVar3 = 0;
  peVar2 = g_rgextdll;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DISPATCHFUNCTION pDispatch@[???] */
  if (0 < g_iextdllMac) {
    do {
      p_Var1 = (FIELDIOFUNCTION)dlsym(peVar2->lDLLHandle,pName);
      if (p_Var1 != (FIELDIOFUNCTION)0x0) {
        return p_Var1;
      }
      iVar3 = iVar3 + 1;
      peVar2 = peVar2 + 1;
    } while (iVar3 < g_iextdllMac);
  }
  return (FIELDIOFUNCTION)0x0;
}


// GetModelPtr  @ 000758b0
void * GetModelPtr(edict_t *pEdict)

{
  void *pvVar1;
  
  if (pEdict != (edict_t *)0x0) {
    pvVar1 = Mod_Extradata(sv.models[(pEdict->v).modelindex]);
    return pvVar1;
  }
  return (void *)0x0;
}


// GetModuleHandle  @ 00066280
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


// GetModuleHandle  @ 000c49b0
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


// GetRateRegistrySetting  @ 0007bd30
char * GetRateRegistrySetting(char *pchDef)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*registry->_vptr_IRegistry[4])(registry,"rate",pchDef);
  return pcVar1;
}


// GetStatsString  @ 00057e80
void GetStatsString(char *buf,int bufSize)

{
  float fVar1;
  float fVar2;
  double dVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  
                    /* Unresolved local var: float avgIn@[???]
                       Unresolved local var: float avgOut@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int players@[???] */
  iVar5 = 0;
  host_client = svs.clients;
  if (svs.maxclients < 1) {
    fVar1 = 0.0;
    fVar2 = fVar1;
  }
  else {
    fVar2 = 0.0;
    iVar4 = 0;
    fVar1 = fVar2;
    do {
      if ((((host_client->active != false) || (host_client->connected != false)) ||
          (host_client->spawned != false)) && (host_client->fakeclient == false)) {
        fVar1 = fVar1 + (host_client->netchan).flow[1].avgkbytespersec;
        iVar5 = iVar5 + 1;
        fVar2 = fVar2 + (host_client->netchan).flow[0].avgkbytespersec;
      }
      iVar4 = iVar4 + 1;
      host_client = host_client + 1;
    } while (iVar4 != svs.maxclients);
  }
  dVar3 = 1.0 / host_frametime;
  iVar4 = g_userid + -1;
  dVar6 = Sys_FloatTime();
  __snprintf_chk(buf,bufSize + -1,1,0xffffffff,"%5.2f %5.2f %5.2f %7i %5i %7.2f %7i",
                 (double)((float)cpuPercent * 100.0),(double)fVar1,(double)fVar2,
                 (int)(dVar6 - (double)startTime) / 0x3c,iVar4,dVar3,iVar5);
  buf[bufSize + -1] = '\0';
  return;
}


// GetTimesTutorMessageShown  @ 000455f0
int GetTimesTutorMessageShown(int id)

{
  return -1;
}


// GetVarsOfEnt  @ 00075700
entvars_t * GetVarsOfEnt(edict_t *pEdict)

{
  return &pEdict->v;
}


// GreatestCommonDivisor  @ 00061340
int GreatestCommonDivisor(int i1,int i2)

{
  int iVar1;
  
  while( true ) {
    iVar1 = i1;
    if (i2 < i1) {
      do {
        i1 = i2;
        if (i1 == 0) {
          return iVar1;
        }
        i2 = iVar1 % i1;
        iVar1 = i1;
      } while (i2 < i1);
    }
    if (i1 == 0) break;
    i2 = i2 % i1;
  }
  return i2;
}


// IBaseInterface::~IBaseInterface  @ 0007cac0
/* DWARF original prototype: void ~IBaseInterface(IBaseInterface * this, int __in_chrg) */

void __thiscall IBaseInterface::~IBaseInterface(IBaseInterface *this,int __in_chrg)

{
  return;
}


// IBaseInterface::~IBaseInterface  @ 0007caf0
/* DWARF original prototype: void ~IBaseInterface(IBaseInterface * this, int __in_chrg) */

void __thiscall IBaseInterface::~IBaseInterface(IBaseInterface *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// IGame::OnlyLegacyRender  @ 0007f4f0
/* DWARF original prototype: bool OnlyLegacyRender(IGame * this) */

bool __thiscall IGame::OnlyLegacyRender(IGame *this)

{
  return true;
}


// IndexOfEdict  @ 00075600
int IndexOfEdict(edict_t *pEdict)

{
  int iVar1;
  
                    /* Unresolved local var: int index@[???] */
  if (pEdict != (edict_t *)0x0) {
    iVar1 = ((int)pEdict - (int)sv.edicts >> 2) * 0x28c1979;
    if ((iVar1 < 0) || (iVar1 - sv.max_edicts != 0 && sv.max_edicts <= iVar1)) {
      Sys_Error("Bad entity in IndexOfEdict()");
    }
    return iVar1;
  }
  return 0;
}


// InitEntityDLLFields  @ 000754a0
void InitEntityDLLFields(edict_t *pEdict)

{
  (pEdict->v).pContainingEntity = pEdict;
  return;
}


// InsertLinkAfter  @ 000a8220
void InsertLinkAfter(link_t *l,link_t *after)

{
  link_s *plVar1;
  
  plVar1 = after->next;
  l->prev = after;
  l->next = plVar1;
  after->next = l;
  l->next->prev = l;
  return;
}


// InsertLinkBefore  @ 000a8200
void InsertLinkBefore(link_t *l,link_t *before)

{
  link_s *plVar1;
  
  l->next = before;
  plVar1 = before->prev;
  l->prev = plVar1;
  plVar1->next = l;
  l->next->prev = l;
  return;
}


// InterfaceReg::InterfaceReg  @ 000c49f0
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


// InterpolateAngles  @ 000606b0
void InterpolateAngles(float *start,float *end,float *output,float frac)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float ang1@[???]
                       Unresolved local var: float ang2@[???]
                       Unresolved local var: float d@[???] */
                    /* Unresolved local var: int i@[???] */
  fVar1 = *start;
  if (180.0 < fVar1) {
    *start = fVar1 - 360.0;
    fVar1 = start[1];
    if (180.0 < fVar1) goto LAB_000608d8;
LAB_000606ff:
    if (fVar1 < -180.0) {
      start[1] = fVar1 + 360.0;
    }
    fVar1 = start[2];
    if (180.0 < fVar1) goto LAB_0006072f;
LAB_000608f6:
    if (-180.0 <= fVar1) goto LAB_00060742;
    start[2] = fVar1 + 360.0;
    fVar1 = *end;
    if (180.0 < fVar1) goto LAB_00060921;
LAB_00060756:
    if (fVar1 < -180.0) {
      fVar1 = fVar1 + 360.0;
      *end = fVar1;
    }
    fVar2 = end[1];
    if (fVar2 <= 180.0) goto LAB_0006077d;
LAB_0006093e:
    end[1] = fVar2 - 360.0;
    fVar2 = end[2];
    if (fVar2 <= 180.0) goto LAB_0006095c;
LAB_000607af:
    end[2] = fVar2 - 360.0;
  }
  else {
    if (fVar1 < -180.0) {
      *start = fVar1 + 360.0;
    }
    fVar1 = start[1];
    if (fVar1 <= 180.0) goto LAB_000606ff;
LAB_000608d8:
    start[1] = fVar1 - 360.0;
    fVar1 = start[2];
    if (fVar1 <= 180.0) goto LAB_000608f6;
LAB_0006072f:
    start[2] = fVar1 - 360.0;
LAB_00060742:
                    /* Unresolved local var: int i@[???] */
    fVar1 = *end;
    if (fVar1 <= 180.0) goto LAB_00060756;
LAB_00060921:
    fVar1 = fVar1 - 360.0;
    *end = fVar1;
    fVar2 = end[1];
    if (180.0 < fVar2) goto LAB_0006093e;
LAB_0006077d:
    if (fVar2 < -180.0) {
      end[1] = fVar2 + 360.0;
    }
    fVar2 = end[2];
    if (180.0 < fVar2) goto LAB_000607af;
LAB_0006095c:
    if (fVar2 < -180.0) {
      end[2] = fVar2 + 360.0;
      fVar2 = *start;
      fVar1 = fVar1 - fVar2;
      goto joined_r0x000607d2;
    }
  }
  fVar2 = *start;
  fVar1 = fVar1 - fVar2;
joined_r0x000607d2:
  if (180.0 < fVar1) {
    fVar1 = fVar1 - 360.0;
  }
  else if (fVar1 < -180.0) {
    fVar1 = fVar1 + 360.0;
  }
  *output = fVar1 * frac + fVar2;
  fVar1 = end[1] - start[1];
  if (180.0 < fVar1) {
    fVar1 = fVar1 - 360.0;
  }
  else if (fVar1 < -180.0) {
    fVar1 = fVar1 + 360.0;
  }
  output[1] = fVar1 * frac + start[1];
  fVar1 = end[2] - start[2];
  if (fVar1 <= 180.0) {
    if (fVar1 < -180.0) {
      fVar1 = fVar1 + 360.0;
    }
  }
  else {
    fVar1 = fVar1 - 360.0;
  }
  output[2] = fVar1 * frac + start[2];
                    /* Unresolved local var: int i@[???] */
  fVar1 = *output;
  if (180.0 < fVar1) {
    *output = fVar1 - 360.0;
  }
  else if (fVar1 < -180.0) {
    *output = fVar1 + 360.0;
  }
  fVar1 = output[1];
  if (180.0 < fVar1) {
    output[1] = fVar1 - 360.0;
  }
  else if (fVar1 < -180.0) {
    output[1] = fVar1 + 360.0;
  }
  fVar1 = output[2];
  if (180.0 < fVar1) {
    output[2] = fVar1 - 360.0;
    return;
  }
  if (fVar1 < -180.0) {
    output[2] = fVar1 + 360.0;
  }
  return;
}


// Invert24To16  @ 00061380
fixed16_t Invert24To16(fixed16_t val)

{
  fixed16_t fVar1;
  
  if (val < 0x100) {
    fVar1 = -1;
  }
  else {
    fVar1 = (fixed16_t)(1.0995116e+12 / (float)val + 0.5);
  }
  return fVar1;
}


// InvertMatrix  @ 0005f880
int InvertMatrix(float *m,float *out)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  float *pfVar13;
  float local_90;
  float local_8c [32];
  
                    /* Unresolved local var: float[4][8] wtmp@[???]
                       Unresolved local var: float m0@[???]
                       Unresolved local var: float m1@[???]
                       Unresolved local var: float m2@[???]
                       Unresolved local var: float m3@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float * r0@[???]
                       Unresolved local var: float * r1@[???]
                       Unresolved local var: float * r2@[???]
                       Unresolved local var: float * r3@[???] */
  local_8c[4] = 1.0;
  local_8c[7] = 0.0;
  local_8c[0] = *m;
  local_8c[1] = m[4];
  local_8c[8] = m[1];
  local_8c[9] = m[5];
  local_8c[0x10] = m[2];
  local_8c[2] = m[8];
  local_8c[3] = m[0xc];
  local_8c[6] = 0.0;
  local_8c[5] = 0.0;
  local_8c[10] = m[9];
  local_8c[0xb] = m[0xd];
  local_8c[0xd] = 1.0;
  local_8c[0xf] = 0.0;
  local_8c[0xe] = 0.0;
  local_8c[0xc] = 0.0;
  local_90 = m[6];
  local_8c[0x18] = m[3];
  fVar3 = ABS(local_8c[0x10]);
  local_8c[0x11] = local_90;
  local_8c[0x12] = m[10];
  local_8c[0x13] = m[0xe];
  local_8c[0x16] = 1.0;
  local_8c[0x17] = 0.0;
  local_8c[0x15] = 0.0;
  local_8c[0x14] = 0.0;
  local_8c[0x19] = m[7];
  local_8c[0x1a] = m[0xb];
  local_8c[0x1b] = m[0xf];
  local_8c[0x1f] = 1.0;
  local_8c[0x1e] = 0.0;
  local_8c[0x1d] = 0.0;
  local_8c[0x1c] = 0.0;
  if (ABS(local_8c[0x18]) <= fVar3) {
    pfVar10 = local_8c + 0x18;
    pfVar12 = local_8c + 0x10;
    fVar4 = local_8c[0x18];
  }
  else {
                    /* Unresolved local var: float * _tmp@[???] */
    pfVar10 = local_8c + 0x10;
    pfVar12 = local_8c + 0x18;
    fVar4 = local_8c[0x10];
    local_8c[0x10] = local_8c[0x18];
    fVar3 = ABS(local_8c[0x18]);
    local_90 = m[7];
  }
  fVar2 = ABS(local_8c[8]);
  pfVar9 = local_8c + 8;
  fVar1 = local_8c[8];
  if (fVar2 < fVar3) {
                    /* Unresolved local var: float * _tmp@[???] */
    pfVar9 = pfVar12;
    pfVar12 = local_8c + 8;
    fVar1 = local_8c[0x10];
    local_8c[0x10] = local_8c[8];
    fVar2 = fVar3;
    local_8c[9] = local_90;
  }
  pfVar8 = pfVar9;
  pfVar13 = local_8c;
  fVar3 = local_8c[0];
  fVar5 = local_8c[9];
  fVar6 = local_8c[1];
  if (ABS(local_8c[0]) < fVar2) {
                    /* Unresolved local var: float * _tmp@[???] */
    pfVar8 = local_8c;
    pfVar13 = pfVar9;
    fVar3 = fVar1;
    fVar1 = local_8c[0];
    fVar5 = local_8c[1];
    fVar6 = local_8c[9];
  }
  if (fVar3 == 0.0) {
    return 0;
  }
  fVar1 = fVar1 / fVar3;
  fVar2 = local_8c[0x10] / fVar3;
  fVar4 = fVar4 / fVar3;
  pfVar8[1] = fVar5 - fVar1 * fVar6;
  pfVar12[1] = pfVar12[1] - fVar2 * fVar6;
  pfVar10[1] = pfVar10[1] - fVar6 * fVar4;
  fVar3 = pfVar13[2];
  pfVar8[2] = pfVar8[2] - fVar1 * fVar3;
  pfVar12[2] = pfVar12[2] - fVar2 * fVar3;
  pfVar10[2] = pfVar10[2] - fVar3 * fVar4;
  fVar3 = pfVar13[3];
  pfVar8[3] = pfVar8[3] - fVar1 * fVar3;
  pfVar12[3] = pfVar12[3] - fVar2 * fVar3;
  pfVar10[3] = pfVar10[3] - fVar3 * fVar4;
  fVar3 = pfVar13[4];
  if (fVar3 != 0.0) {
    pfVar8[4] = pfVar8[4] - fVar1 * fVar3;
    pfVar12[4] = pfVar12[4] - fVar2 * fVar3;
    pfVar10[4] = pfVar10[4] - fVar3 * fVar4;
  }
  fVar3 = pfVar13[5];
  if (fVar3 != 0.0) {
    pfVar8[5] = pfVar8[5] - fVar1 * fVar3;
    pfVar12[5] = pfVar12[5] - fVar2 * fVar3;
    pfVar10[5] = pfVar10[5] - fVar3 * fVar4;
  }
  fVar3 = pfVar13[6];
  if (fVar3 != 0.0) {
    pfVar8[6] = pfVar8[6] - fVar1 * fVar3;
    pfVar12[6] = pfVar12[6] - fVar2 * fVar3;
    pfVar10[6] = pfVar10[6] - fVar3 * fVar4;
  }
  fVar3 = pfVar13[7];
  if (fVar3 != 0.0) {
    pfVar8[7] = pfVar8[7] - fVar1 * fVar3;
    pfVar12[7] = pfVar12[7] - fVar2 * fVar3;
    pfVar10[7] = pfVar10[7] - fVar3 * fVar4;
  }
  fVar3 = pfVar10[1];
  fVar2 = ABS(fVar3);
  fVar4 = pfVar12[1];
  fVar1 = ABS(fVar4);
  pfVar9 = pfVar8;
  if (fVar2 <= fVar1) {
    fVar5 = pfVar8[1];
    pfVar11 = pfVar12;
    pfVar12 = pfVar10;
    fVar6 = fVar4;
    fVar7 = fVar4;
    fVar4 = fVar3;
    if (ABS(fVar5) < fVar1) goto LAB_0005fb76;
  }
  else {
    fVar5 = pfVar8[1];
    pfVar11 = pfVar10;
    pfVar10 = pfVar12;
    fVar6 = fVar3;
    fVar7 = fVar3;
    fVar3 = fVar4;
    if (ABS(fVar5) < fVar2) goto LAB_0005fb76;
  }
  pfVar9 = pfVar11;
  pfVar11 = pfVar8;
  pfVar12 = pfVar10;
  fVar7 = fVar5;
  fVar4 = fVar3;
  fVar5 = fVar6;
LAB_0005fb76:
  if (fVar7 != 0.0) {
    fVar5 = fVar5 / fVar7;
    fVar4 = fVar4 / fVar7;
    pfVar9[2] = pfVar9[2] - pfVar11[2] * fVar5;
    pfVar12[2] = pfVar12[2] - pfVar11[2] * fVar4;
    pfVar9[3] = pfVar9[3] - pfVar11[3] * fVar5;
    pfVar12[3] = pfVar12[3] - pfVar11[3] * fVar4;
    fVar3 = pfVar11[4];
    if (fVar3 != 0.0) {
      pfVar9[4] = pfVar9[4] - fVar5 * fVar3;
      pfVar12[4] = pfVar12[4] - fVar3 * fVar4;
    }
    fVar3 = pfVar11[5];
    if (fVar3 != 0.0) {
      pfVar9[5] = pfVar9[5] - fVar5 * fVar3;
      pfVar12[5] = pfVar12[5] - fVar3 * fVar4;
    }
    fVar3 = pfVar11[6];
    if (fVar3 != 0.0) {
      pfVar9[6] = pfVar9[6] - fVar5 * fVar3;
      pfVar12[6] = pfVar12[6] - fVar3 * fVar4;
    }
    fVar3 = pfVar11[7];
    if (fVar3 != 0.0) {
      pfVar9[7] = pfVar9[7] - fVar5 * fVar3;
      pfVar12[7] = pfVar12[7] - fVar4 * fVar3;
    }
    fVar3 = pfVar12[2];
    fVar4 = pfVar9[2];
    pfVar10 = pfVar9;
    fVar1 = fVar3;
    if (ABS(fVar3) <= ABS(fVar4)) {
      pfVar10 = pfVar12;
      pfVar12 = pfVar9;
      fVar1 = fVar4;
      fVar4 = fVar3;
    }
    if (fVar1 != 0.0) {
      fVar4 = fVar4 / fVar1;
      fVar2 = pfVar10[3] - pfVar12[3] * fVar4;
      pfVar10[3] = fVar2;
      fVar5 = pfVar10[4] - pfVar12[4] * fVar4;
      pfVar10[4] = fVar5;
      fVar6 = pfVar10[5] - pfVar12[5] * fVar4;
      pfVar10[5] = fVar6;
      fVar1 = pfVar10[6] - pfVar12[6] * fVar4;
      pfVar10[6] = fVar1;
      fVar3 = pfVar10[7] - fVar4 * pfVar12[7];
      pfVar10[7] = fVar3;
      if (fVar2 != 0.0) {
        fVar2 = 1.0 / fVar2;
        fVar5 = fVar5 * fVar2;
        pfVar10[4] = fVar5;
        pfVar10[5] = fVar6 * fVar2;
        pfVar10[6] = fVar1 * fVar2;
        pfVar10[7] = fVar3 * fVar2;
        fVar3 = pfVar12[3];
        fVar4 = 1.0 / pfVar12[2];
        pfVar12[4] = (pfVar12[4] - fVar5 * fVar3) * fVar4;
        pfVar12[5] = (pfVar12[5] - pfVar10[5] * fVar3) * fVar4;
        pfVar12[6] = (pfVar12[6] - pfVar10[6] * fVar3) * fVar4;
        pfVar12[7] = (pfVar12[7] - fVar3 * pfVar10[7]) * fVar4;
        fVar3 = pfVar11[3];
        pfVar11[4] = pfVar11[4] - pfVar10[4] * fVar3;
        pfVar11[5] = pfVar11[5] - pfVar10[5] * fVar3;
        pfVar11[6] = pfVar11[6] - pfVar10[6] * fVar3;
        pfVar11[7] = pfVar11[7] - fVar3 * pfVar10[7];
        fVar3 = pfVar13[3];
        pfVar13[4] = pfVar13[4] - pfVar10[4] * fVar3;
        pfVar13[5] = pfVar13[5] - pfVar10[5] * fVar3;
        pfVar13[6] = pfVar13[6] - pfVar10[6] * fVar3;
        pfVar13[7] = pfVar13[7] - fVar3 * pfVar10[7];
        fVar3 = pfVar11[2];
        fVar4 = 1.0 / pfVar11[1];
        pfVar11[4] = (pfVar11[4] - pfVar12[4] * fVar3) * fVar4;
        pfVar11[5] = (pfVar11[5] - pfVar12[5] * fVar3) * fVar4;
        pfVar11[6] = (pfVar11[6] - pfVar12[6] * fVar3) * fVar4;
        pfVar11[7] = (pfVar11[7] - fVar3 * pfVar12[7]) * fVar4;
        fVar3 = pfVar13[2];
        fVar4 = pfVar13[4] - pfVar12[4] * fVar3;
        pfVar13[4] = fVar4;
        fVar1 = pfVar13[5] - pfVar12[5] * fVar3;
        pfVar13[5] = fVar1;
        fVar2 = pfVar13[6] - pfVar12[6] * fVar3;
        pfVar13[6] = fVar2;
        fVar5 = pfVar13[7] - fVar3 * pfVar12[7];
        pfVar13[7] = fVar5;
        fVar3 = pfVar13[1];
        fVar6 = 1.0 / *pfVar13;
        fVar4 = (fVar4 - pfVar11[4] * fVar3) * fVar6;
        pfVar13[4] = fVar4;
        fVar1 = (fVar1 - pfVar11[5] * fVar3) * fVar6;
        pfVar13[5] = fVar1;
        fVar7 = (fVar2 - pfVar11[6] * fVar3) * fVar6;
        pfVar13[6] = fVar7;
        fVar6 = (fVar5 - fVar3 * pfVar11[7]) * fVar6;
        pfVar13[7] = fVar6;
        fVar3 = pfVar11[4];
        *out = fVar4;
        fVar4 = pfVar11[6];
        out[1] = fVar3;
        out[4] = fVar1;
        fVar3 = pfVar11[7];
        fVar1 = pfVar12[4];
        fVar2 = pfVar12[5];
        fVar5 = pfVar11[5];
        out[8] = fVar7;
        out[9] = fVar4;
        out[0xc] = fVar6;
        out[0xd] = fVar3;
        out[2] = fVar1;
        out[6] = fVar2;
        out[5] = fVar5;
        fVar3 = pfVar10[4];
        fVar4 = pfVar10[5];
        fVar1 = pfVar10[6];
        fVar2 = pfVar10[7];
        fVar5 = pfVar12[7];
        out[10] = pfVar12[6];
        out[3] = fVar3;
        out[0xe] = fVar5;
        out[7] = fVar4;
        out[0xb] = fVar1;
        out[0xf] = fVar2;
        return 1;
      }
    }
  }
  return 0;
}


// IsCZPlayerModel  @ 000b9ca0
qboolean IsCZPlayerModel(uint32 crc,char *filename)

{
  int iVar1;
  char *__s2;
  
  if (filename == (char *)0x0) {
    return 0;
  }
  if (crc == 0x35ac6fed) {
LAB_000b9e07:
    __s2 = "models/player/gign/gign.mdl";
    goto LAB_000b9d32;
  }
  if (crc < 0x35ac6fee) {
    if (crc != 0x1b6c4115) {
      if (crc < 0x1b6c4116) {
        if (crc == 0x68168db) goto LAB_000b9dc0;
        if (0x68168db < crc) {
          if (crc == 0xda8922a) goto LAB_000b9e18;
          if (crc != 0x1aaa3360) {
            return 0;
          }
          goto LAB_000b9e07;
        }
        if (crc != 0x2b95e5f) {
          return 0;
        }
        goto LAB_000b9e37;
      }
      if (crc == 0x270fb2d7) {
LAB_000b9d97:
        __s2 = "models/player/terror/terror.mdl";
        goto LAB_000b9d32;
      }
      if (0x270fb2d7 < crc) {
        if (crc == 0x27fb4d2f) {
          __s2 = "models/player/spetsnaz/spetsnaz.mdl";
          goto LAB_000b9d32;
        }
        if (crc != 0x29fe156c) {
          return 0;
        }
LAB_000b9d67:
        __s2 = "models/player/leet/leet.mdl";
        goto LAB_000b9d32;
      }
      if (crc != 0x1f3cd80b) {
        return 0;
      }
    }
    __s2 = "models/player/guerilla/guerilla.mdl";
  }
  else {
    if (crc != 0x72db74e4) {
      if (crc < 0x72db74e5) {
        if (crc == 0x43e67ff3) {
LAB_000b9daf:
          __s2 = "models/player/sas/sas.mdl";
          goto LAB_000b9d32;
        }
        if (crc < 0x43e67ff4) {
          if (crc != 0x3bcaa016) {
            return 0;
          }
          __s2 = "models/player/militia/militia.mdl";
          goto LAB_000b9d32;
        }
        if (crc != 0x4986827b) {
          if (crc != 0x56dd2d02) {
            return 0;
          }
LAB_000b9e18:
          __s2 = "models/player/gsg9/gsg9.mdl";
          goto LAB_000b9d32;
        }
      }
      else {
        if (crc == 0xc7f0dbf3) {
LAB_000b9dc0:
          __s2 = "models/player/urban/urban.mdl";
          goto LAB_000b9d32;
        }
        if (0xc7f0dbf3 < crc) {
          if (crc == 0xec43f76d) goto LAB_000b9d97;
          if (crc != 0xf141ae3f) {
            return 0;
          }
          goto LAB_000b9daf;
        }
        if (crc != 0xa37d8680) {
          if (crc != 0xc37369f6) {
            return 0;
          }
          goto LAB_000b9d67;
        }
      }
      __s2 = "models/player/arctic/arctic.mdl";
      goto LAB_000b9d32;
    }
LAB_000b9e37:
    __s2 = "models/player/vip/vip.mdl";
  }
LAB_000b9d32:
  iVar1 = strcasecmp(filename,__s2);
  return (uint)(iVar1 == 0);
}


// IsComment  @ 000a5050
int IsComment(char *pText)

{
  int iVar1;
  
  if (pText != (char *)0x0) {
                    /* Unresolved local var: int length@[???] */
    iVar1 = Q_strlen(pText);
    if (iVar1 < 2) {
      return (uint)(iVar1 < 1);
    }
    if ((*pText != '/') || (pText[1] != '/')) {
      return 0;
    }
  }
  return 1;
}


// IsEndOfText  @ 000a50c0
int IsEndOfText(char *pText)

{
  if (pText != (char *)0x0) {
    return (uint)(*pText == '}');
  }
  return 0;
}


// IsGameSubscribed  @ 000957c0
qboolean IsGameSubscribed(char *game)

{
  return false;
}


// IsSafeFileToDownload  @ 00090180
qboolean IsSafeFileToDownload(char *filename)

{
  char *pcVar1;
  qboolean qVar2;
  char *pcVar3;
  int in_GS_OFFSET;
  char local_1010 [4096];
  int local_10;
  
                    /* Unresolved local var: char * first@[???]
                       Unresolved local var: char * last@[???]
                       Unresolved local var: char[4096] lwrfilename@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (filename != (char *)0x0) {
    Q_strncpy(local_1010,filename,0x1000);
    Q_strlwr(local_1010);
    pcVar1 = Q_strstr(local_1010,":");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = Q_strstr(local_1010,"..");
      if (pcVar1 == (char *)0x0) {
        pcVar1 = Q_strstr(local_1010,"~");
        if (((pcVar1 == (char *)0x0) && (local_1010[0] != '/')) && (local_1010[0] != '\\')) {
          pcVar1 = strchr(local_1010,0x2e);
          pcVar3 = strrchr(local_1010,0x2e);
          if (pcVar1 == pcVar3) {
            pcVar1 = Q_stristr(local_1010,".cfg");
            if (pcVar1 == (char *)0x0) {
              pcVar1 = Q_stristr(local_1010,".rc");
              if (pcVar1 == (char *)0x0) {
                pcVar1 = Q_stristr(local_1010,".lst");
                if (pcVar1 == (char *)0x0) {
                  pcVar1 = Q_stristr(local_1010,".exe");
                  if (pcVar1 == (char *)0x0) {
                    pcVar1 = Q_stristr(local_1010,".vbs");
                    if (pcVar1 == (char *)0x0) {
                      pcVar1 = Q_stristr(local_1010,".com");
                      if (pcVar1 == (char *)0x0) {
                        pcVar1 = Q_stristr(local_1010,".bat");
                        if (pcVar1 == (char *)0x0) {
                          pcVar1 = Q_stristr(local_1010,".dll");
                          if (pcVar1 == (char *)0x0) {
                            pcVar1 = Q_stristr(local_1010,".ini");
                            if (pcVar1 == (char *)0x0) {
                              pcVar1 = Q_stristr(local_1010,".log");
                              if (pcVar1 == (char *)0x0) {
                                pcVar1 = Q_stristr(local_1010,"halflife.wad");
                                if (pcVar1 == (char *)0x0) {
                                  pcVar1 = Q_stristr(local_1010,"pak0.pak");
                                  if (pcVar1 == (char *)0x0) {
                                    pcVar1 = Q_stristr(local_1010,"xeno.wad");
                                    if (pcVar1 == (char *)0x0) {
                                      pcVar1 = Q_stristr(local_1010,".so");
                                      if (pcVar1 == (char *)0x0) {
                                        pcVar1 = Q_stristr(local_1010,".dylib");
                                        if (pcVar1 == (char *)0x0) {
                                          pcVar1 = Q_stristr(local_1010,".sys");
                                          if (pcVar1 == (char *)0x0) {
                                            pcVar1 = Q_stristr(local_1010,".asi");
                                            if (pcVar1 == (char *)0x0) {
                                              pcVar1 = Q_stristr(local_1010,".mix");
                                              if (pcVar1 == (char *)0x0) {
                                                pcVar1 = Q_stristr(local_1010,".flt");
                                                qVar2 = (qboolean)(pcVar1 == (char *)0x0);
                                                goto LAB_000901db;
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  qVar2 = false;
LAB_000901db:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// IsStartOfText  @ 000a50a0
int IsStartOfText(char *pText)

{
  if (pText != (char *)0x0) {
    return (uint)(*pText == '{');
  }
  return 0;
}


// IsToken  @ 000a5b80
int IsToken(char *pText,char *pTokenName)

{
  int iVar1;
  
  if ((pText != (char *)0x0) && (pTokenName != (char *)0x0)) {
    iVar1 = Q_strlen(pTokenName);
    iVar1 = Q_strnicmp(pText + 1,pTokenName,iVar1);
    return (uint)(iVar1 == 0);
  }
  return 0;
}


// IsWhiteSpace  @ 000a50e0
int IsWhiteSpace(char space)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((byte)(space - 9U) < 0x18) {
    uVar1 = (uint)((byte)(0x800013 >> (space - 9U & 0x1f)) & 1);
  }
  return uVar1;
}


// LandmarkOrigin  @ 0005b190
void LandmarkOrigin(SAVERESTOREDATA *pSaveData,vec_t *output,char *pLandmarkName)

{
  int iVar1;
  int iVar2;
  char *s1;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  s1 = pSaveData->levelList[0].landmarkName;
  if (0 < pSaveData->connectionCount) {
    do {
      iVar1 = Q_strcmp(s1,pLandmarkName);
      if (iVar1 == 0) {
        *output = pSaveData->levelList[iVar2].vecLandmarkOrigin[0];
        output[1] = pSaveData->levelList[iVar2].vecLandmarkOrigin[1];
        output[2] = pSaveData->levelList[iVar2].vecLandmarkOrigin[2];
        return;
      }
      iVar2 = iVar2 + 1;
      s1 = s1 + 0x50;
    } while (iVar2 < pSaveData->connectionCount);
  }
  *output = 0.0;
  output[1] = 0.0;
  output[2] = 0.0;
  return;
}


// Length  @ 00060c10
float Length(vec_t *v)

{
  float __x;
  float fVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float length@[???] */
  __x = v[2] * v[2] + v[1] * v[1] + *v * *v + 0.0;
  fVar1 = SQRT(__x);
  if (NAN(fVar1)) {
    fVar1 = sqrtf(__x);
  }
  return fVar1;
}


// LoadAdjacentEntities  @ 0005b680
void LoadAdjacentEntities(char *pOldLevel,char *pLandmarkName)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  SAVERESTOREDATA *pSaveData;
  int iVar5;
  LEVELLIST *pLVar6;
  char *pcVar7;
  char *s1;
  int iVar8;
  uint levelMask;
  int in_GS_OFFSET;
  int local_670;
  float local_66c;
  float local_664;
  float local_660;
  int local_658;
  undefined1 local_64c [68];
  undefined1 local_608 [16];
  int local_5f8;
  int local_5f4;
  float local_5f0;
  undefined1 local_594 [36];
  int local_570;
  char local_568 [32];
  char local_548 [36];
  float local_524 [321];
  int local_20;
  
                    /* Unresolved local var: SAVERESTOREDATA currentLevelData@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int test@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: int movedCount@[???]
                       Unresolved local var: SAVE_HEADER header@[???]
                       Unresolved local var: vec3_t landmarkOrigin@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_594,0,0x574);
  gGlobalVariables.pSaveData = local_594;
  (*gEntityInterface.pfnParmsChangeLevel)();
  if (0 < local_570) {
    s1 = local_568;
    local_658 = 0;
    local_670 = 0;
    do {
      iVar5 = 0;
      pcVar7 = local_568;
      if (0 < local_670) {
        do {
          iVar8 = Q_strcmp(s1,pcVar7);
          if (iVar8 == 0) {
            if (iVar5 < local_670) goto LAB_0005b73e;
            break;
          }
          iVar5 = iVar5 + 1;
          pcVar7 = pcVar7 + 0x50;
        } while (iVar5 != local_670);
      }
      pSaveData = LoadSaveData(s1);
      if (pSaveData != (SAVERESTOREDATA *)0x0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: SAVELIGHTSTYLE light@[???] */
        iVar8 = 0;
        iVar5 = 0;
        if (0 < pSaveData->tableCount) {
          do {
            iVar5 = iVar5 + 1;
            (*gEntityInterface.pfnSaveReadFields)
                      (pSaveData,"ETABLE",(void *)((int)&pSaveData->pTable->id + iVar8),
                       gEntityTableDescription,5);
            *(undefined4 *)((int)&pSaveData->pTable->pent + iVar8) = 0;
            iVar8 = iVar8 + 0x18;
          } while (iVar5 < pSaveData->tableCount);
        }
        pSaveData->size = 0;
        pSaveData->pBaseData = pSaveData->pCurrentData;
        (*gEntityInterface.pfnSaveReadFields)
                  (pSaveData,"Save Header",local_608,gSaveHeaderDescription,0xd);
        pSaveData->fUseLandmark = 1;
        pSaveData->vecLandmarkOffset[0] = 0.0;
        pSaveData->connectionCount = local_5f8;
        pSaveData->time = local_5f0;
        pSaveData->vecLandmarkOffset[1] = 0.0;
        pSaveData->vecLandmarkOffset[2] = 0.0;
        if (0 < local_5f8) {
          iVar5 = 0;
          pLVar6 = pSaveData->levelList;
          do {
            iVar5 = iVar5 + 1;
            (*gEntityInterface.pfnSaveReadFields)
                      (pSaveData,"ADJACENCY",pLVar6,gAdjacencyDescription,4);
            pLVar6 = pLVar6 + 1;
          } while (iVar5 < pSaveData->connectionCount);
        }
        iVar5 = 0;
        if (0 < local_5f4) {
          do {
            iVar5 = iVar5 + 1;
            (*gEntityInterface.pfnSaveReadFields)
                      (pSaveData,"LIGHTSTYLE",local_64c,gLightstyleDescription,2);
          } while (iVar5 < local_5f4);
        }
                    /* Unresolved local var: int i@[???] */
        pcVar7 = local_548;
        EntityPatchRead(pSaveData,s1);
        pSaveData->time = (float)sv.time;
        pSaveData->fUseLandmark = 1;
        if (0 < local_570) {
          iVar5 = 0;
          do {
            iVar8 = Q_strcmp(pcVar7,pLandmarkName);
            if (iVar8 == 0) {
              local_664 = local_524[iVar5 * 0x14];
              local_660 = local_524[iVar5 * 0x14 + 1];
              local_66c = local_524[iVar5 * 0x14 + 2];
              goto LAB_0005b984;
            }
            iVar5 = iVar5 + 1;
            pcVar7 = pcVar7 + 0x50;
          } while (iVar5 < local_570);
        }
        local_66c = 0.0;
        local_660 = 0.0;
        local_664 = 0.0;
LAB_0005b984:
                    /* Unresolved local var: int i@[???] */
        pcVar7 = pSaveData->levelList[0].landmarkName;
        if (0 < pSaveData->connectionCount) {
          iVar5 = 0;
          do {
            iVar8 = Q_strcmp(pcVar7,pLandmarkName);
            if (iVar8 == 0) {
              fVar1 = pSaveData->levelList[iVar5].vecLandmarkOrigin[0];
              fVar2 = pSaveData->levelList[iVar5].vecLandmarkOrigin[1];
              fVar3 = pSaveData->levelList[iVar5].vecLandmarkOrigin[2];
              goto LAB_0005b9d6;
            }
            iVar5 = iVar5 + 1;
            pcVar7 = pcVar7 + 0x50;
          } while (iVar5 < pSaveData->connectionCount);
        }
        fVar2 = 0.0;
        fVar1 = 0.0;
        fVar3 = 0.0;
LAB_0005b9d6:
        pSaveData->vecLandmarkOffset[0] = local_664 - fVar1;
        pSaveData->vecLandmarkOffset[1] = local_660 - fVar2;
        pSaveData->vecLandmarkOffset[2] = local_66c - fVar3;
        iVar5 = Q_strcmp(s1,pOldLevel);
                    /* Unresolved local var: int i@[???] */
        iVar8 = 0;
        levelMask = -(uint)(iVar5 == 0) & 0x80000000;
        if (0 < pSaveData->connectionCount) {
          do {
            pLVar6 = pSaveData->levelList + iVar8;
            while (iVar5 = Q_strcmp(pLVar6->mapName,sv.name), iVar5 != 0) {
              iVar8 = iVar8 + 1;
              pLVar6 = pLVar6 + 1;
              if (pSaveData->connectionCount <= iVar8) goto LAB_0005ba80;
            }
            if (iVar8 < 0) break;
            bVar4 = (byte)iVar8;
            iVar8 = iVar8 + 1;
            levelMask = levelMask | 1 << (bVar4 & 0x1f);
          } while (iVar8 < pSaveData->connectionCount);
        }
LAB_0005ba80:
        if (levelMask != 0) {
          local_658 = CreateEntityList(pSaveData,levelMask);
        }
        if (local_658 != 0) {
          EntityPatchWrite(pSaveData,s1);
        }
        if (pSaveData->pTokens != (char **)0x0) {
          Mem_Free(pSaveData->pTokens);
          pSaveData->pTokens = (char **)0x0;
          pSaveData->tokenCount = 0;
        }
        Mem_Free(pSaveData);
        gGlobalVariables.pSaveData = (void *)0x0;
      }
LAB_0005b73e:
      local_670 = local_670 + 1;
      s1 = s1 + 0x50;
    } while (local_670 < local_570);
  }
  gGlobalVariables.pSaveData = (void *)0x0;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// LoadEntityDLLs  @ 0007b060
void LoadEntityDLLs(char *szBaseDir)

{
  int iVar1;
  FileHandle_t file;
  char *pcVar2;
  char *pOutput;
  code *pcVar3;
  int in_GS_OFFSET;
  char *pcVar4;
  char *pcVar5;
  char *local_23ac;
  char local_23a8 [64];
  char local_2368 [63];
  undefined1 local_2329;
  char local_2328 [255];
  undefined1 local_2229;
  char local_2228 [260];
  undefined4 local_2124;
  undefined4 local_2120;
  undefined4 local_211c;
  char local_2020 [8192];
  int local_20;
  
                    /* Unresolved local var: char[260] szDllWildcard@[???]
                       Unresolved local var: APIFUNCTION pfnGetAPI@[???]
                       Unresolved local var: APIFUNCTION2 pfnGetAPI2@[???]
                       Unresolved local var: char * pszInputStream@[???]
                       Unresolved local var: char * pStreamPos@[???]
                       Unresolved local var: char[260] szDllListFile@[???]
                       Unresolved local var: int nFileSize@[???]
                       Unresolved local var: int nBytesRead@[???]
                       Unresolved local var: FileHandle_t hLibListFile@[???]
                       Unresolved local var: char[64] szGameDir@[???]
                       Unresolved local var: char[64] szKey@[???]
                       Unresolved local var: char[256] szValue@[???]
                       Unresolved local var: NEW_DLL_FUNCTIONS_FN pNewAPI@[???]
                       Unresolved local var: int interface_version@[???]
                       Unresolved local var: bool[8192] szDllFilename@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  SV_ResetModInfo();
  g_iextdllMac = 0;
  Q_memset(g_rgextdll,0,600);
  pcVar4 = (char *)0x3f;
  Q_strncpy(local_23a8,com_gamedir,0x3f);
  iVar1 = Q_stricmp(local_23a8,"valve");
  if (iVar1 != 0) {
    gmodinfo.bIsMod = true;
  }
  local_2124 = 0x6c62696c;
  local_2120 = 0x2e747369;
  local_211c = 0x6d6167;
  file = FS_Open((char *)&local_2124,"rb");
  if (file == (FileHandle_t)0x0) {
                    /* Unresolved local var: char * findfn@[???] */
    __snprintf_chk(local_2228,0x104,1,0x104,&DAT_000d7646,"valve/dlls");
                    /* Unresolved local var: char * psz@[???] */
    if (g_hfind != -1) {
      Sys_Error("Sys_FindFirst without close");
      FS_FindClose(g_hfind);
    }
    pcVar5 = (char *)0x0;
    pcVar4 = FS_FindFirst(local_2228,&g_hfind,(char *)0x0);
    while (pcVar4 != (char *)0x0) {
      pcVar5 = (char *)0x1;
      __snprintf_chk(local_2020,0x2000,1,0x2000,"%s/%s/%s",szBaseDir,"valve/dlls",pcVar4);
      LoadThisDll(local_2020);
                    /* Unresolved local var: char * psz@[???] */
      pcVar4 = FS_FindNext(g_hfind);
    }
    if (g_hfind != -1) {
      FS_FindClose(g_hfind);
      g_hfind = -1;
    }
  }
  else {
                    /* Unresolved local var: int index@[???] */
    pcVar2 = (char *)FS_Size(file);
    if ((pcVar2 == (char *)0x0) || (0x40000 < (int)pcVar2)) {
      pcVar4 = pcVar2;
      Sys_Error("Game listing file size is bogus [%s: size %i]","liblist.gam",pcVar2);
    }
    pOutput = Mem_Malloc((size_t)(pcVar2 + 1));
    if (pOutput == (char *)0x0) {
      Sys_Error("Could not allocate space for game listing file of %i bytes",pcVar2 + 1,pcVar4);
    }
    pcVar5 = (char *)0x1;
    pcVar4 = (char *)FS_Read(pOutput,(int)pcVar2,1,file);
    if (pcVar2 != pcVar4) {
      Sys_Error("Error reading in game listing file, expected %i bytes, read %i",pcVar2,pcVar4);
      pcVar5 = pcVar4;
    }
    pOutput[(int)pcVar2] = '\0';
                    /* Unresolved local var: char * pos@[???]
                       Unresolved local var: char * sep@[???] */
    com_ignorecolons = true;
    pcVar4 = pOutput;
    while( true ) {
      pcVar4 = COM_Parse(pcVar4);
      iVar1 = Q_strlen(com_token);
      if (iVar1 < 1) break;
      Q_strncpy(local_2368,com_token,0x3f);
      local_2329 = 0;
      pcVar4 = COM_Parse(pcVar4);
      pcVar5 = (char *)0xff;
      Q_strncpy(local_2328,com_token,0xff);
      local_2229 = 0;
      iVar1 = Q_stricmp(local_2368,"gamedll_linux");
      if (iVar1 == 0) {
        iVar1 = COM_CheckParm("-dll");
        if ((iVar1 != 0) && (iVar1 < com_argc + -1)) {
          pcVar5 = (char *)0xff;
          Q_strncpy(local_2328,com_argv[iVar1 + 1],0xff);
          local_2229 = 0;
        }
        if ((((local_2328[0] == '/') || (local_2328[0] == '\\')) ||
            (pcVar2 = Q_strstr(local_2328,":"), pcVar2 != (char *)0x0)) ||
           ((pcVar2 = Q_strstr(local_2328,".."), pcVar2 != (char *)0x0 &&
            (pcVar2 = Q_strstr(pcVar2 + 2,".."), pcVar2 != (char *)0x0)))) {
          Con_DPrintf("Skipping library with illegal characters in path: %s\n",local_2328);
        }
        else {
          pcVar2 = strchr(local_2328,0x5f);
          if (pcVar2 != (char *)0x0) {
            *pcVar2 = '\0';
            pcVar5 = (char *)0x100;
            __strcat_chk(local_2328,&DAT_000d764a);
          }
          pcVar2 = COM_LastFileExtension(local_2328);
          iVar1 = Q_stricmp(pcVar2,"so");
          if (iVar1 == 0) {
            FS_GetLocalPath(local_2328,local_2020,0x2000);
            pcVar5 = local_2328;
            Con_DPrintf("\nAdding:  %s/%s\n",local_23a8);
            LoadThisDll(local_2020);
          }
          else {
            Con_DPrintf("Skipping non-shared library:  %s\n",local_2328);
          }
        }
      }
      else {
        pcVar5 = local_2328;
        DLL_SetModKey(&gmodinfo,local_2368,local_2328);
      }
    }
    com_ignorecolons = false;
    Mem_Free(pOutput);
    FS_Close(file);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DISPATCHFUNCTION pDispatch@[???] */
  gNewDLLFunctions.pfnOnFreeEntPrivateData = (_func_void_edict_t_ptr *)0x0;
  gNewDLLFunctions.pfnGameShutdown = (_func_void *)0x0;
  gNewDLLFunctions.pfnShouldCollide = (_func_int_edict_t_ptr_edict_t_ptr *)0x0;
  gNewDLLFunctions.pfnCvarValue = (_func_void_edict_t_ptr_char_ptr *)0x0;
  gNewDLLFunctions.pfnCvarValue2 = (_func_void_edict_t_ptr_int_char_ptr_char_ptr *)0x0;
  if (0 < g_iextdllMac) {
    iVar1 = 0;
    do {
      pcVar3 = (code *)dlsym(g_rgextdll[iVar1].lDLLHandle,"GetNewDLLFunctions");
      if (pcVar3 != (code *)0x0) {
        local_23ac = (char *)0x1;
        (*pcVar3)(&gNewDLLFunctions,&local_23ac);
        break;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < g_iextdllMac);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DISPATCHFUNCTION pDispatch@[???] */
    if (0 < g_iextdllMac) {
      iVar1 = 0;
      do {
        pcVar3 = (code *)dlsym(g_rgextdll[iVar1].lDLLHandle,"GetEntityAPI2");
        if (pcVar3 != (code *)0x0) {
          local_23ac = &DAT_0000008c;
          iVar1 = (*pcVar3)(&gEntityInterface,&local_23ac);
          if (iVar1 != 0) goto LAB_0007b3bf;
          Con_Printf("==================\n");
          Con_Printf("Game DLL version mismatch\n");
          pcVar5 = &DAT_0000008c;
          pcVar4 = local_23ac;
          Con_Printf("DLL version is %i, engine version is %i\n",local_23ac,0x8c);
          if ((int)local_23ac < 0x8d) goto LAB_0007b4b7;
          Con_Printf("Engine appears to be outdated, check for updates\n",pcVar4,pcVar5);
          goto LAB_0007b4cb;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < g_iextdllMac);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DISPATCHFUNCTION pDispatch@[???] */
      if (0 < g_iextdllMac) {
        iVar1 = 0;
        do {
          pcVar3 = (code *)dlsym(g_rgextdll[iVar1].lDLLHandle,"GetEntityAPI");
          if (pcVar3 != (code *)0x0) {
            local_23ac = &DAT_0000008c;
            iVar1 = (*pcVar3)(&gEntityInterface,0x8c);
            if (iVar1 != 0) {
LAB_0007b3bf:
              pcVar4 = (*gEntityInterface.pfnGetGameDescription)();
              pcVar5 = "game";
              if (gmodinfo.bIsMod != false) {
                pcVar5 = "mod";
              }
              Con_DPrintf("Dll loaded for %s %s\n",pcVar5,pcVar4);
              if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
                __stack_chk_fail();
              }
              return;
            }
            Con_Printf("==================\n");
            Con_Printf("Game DLL version mismatch\n");
LAB_0007b4b7:
            pcVar4 = local_23a8;
            Con_Printf("The game DLL for %s appears to be outdated, check for updates\n",pcVar4,
                       pcVar5);
LAB_0007b4cb:
            Con_Printf("==================\n",pcVar4,pcVar5);
                    /* WARNING: Subroutine does not return */
            Host_Error("\n");
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < g_iextdllMac);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  Host_Error("Couldn\'t get DLL API from %s!",local_2020);
}


// LoadGame  @ 0005dc70
int LoadGame(char *pName)

{
  qboolean qVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int iRet@[???]
                       Unresolved local var: qboolean q@[???] */
  qVar1 = scr_skipupdate;
                    /* Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: GAME_HEADER gameHeader@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: char * pTempNumber@[???]
                       Unresolved local var: char * pchLoadExtension@[???]
                       Unresolved local var: char[5] szNumber@[???]
                       Unresolved local var: int nSlot@[???] */
  iVar3 = 0;
  scr_skipupdate = true;
  if ((pName != (char *)0x0) && (*pName != '\0')) {
    pcVar2 = Q_strstr(pName,"..");
    if (pcVar2 == (char *)0x0) {
      iVar3 = Host_Load(pName);
    }
    else {
      Con_Printf("Relative pathnames are not allowed.\n");
    }
  }
  scr_skipupdate = qVar1;
  return iVar3;
}


// LoadGamestate  @ 0005ad70
int LoadGamestate(char *level,int createPlayers)

{
  SAVERESTOREDATA *pSaveData;
  int *piVar1;
  code *pcVar2;
  int iVar3;
  edict_t *peVar4;
  string_t className;
  int iVar5;
  int iVar6;
  int in_GS_OFFSET;
  SAVE_HEADER local_94;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: SAVE_HEADER header@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: edict_t * pent@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pSaveData = LoadSaveData(level);
  if (pSaveData == (SAVERESTOREDATA *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    ParseSaveTables(pSaveData,&local_94,1);
    EntityPatchRead(pSaveData,level);
    Cvar_SetValue("skill",(float)local_94.skillLevel);
    Q_strncpy(sv.name,local_94.mapName,0x3f);
    sv.name[0x3f] = '\0';
    Cvar_Set("sv_skyname",local_94.skyName);
    Cvar_SetValue("sv_skycolor_r",(float)local_94.skyColor_r);
    Cvar_SetValue("sv_skycolor_g",(float)local_94.skyColor_g);
    Cvar_SetValue("sv_skycolor_b",(float)local_94.skyColor_b);
    Cvar_SetValue("sv_skyvec_x",local_94.skyVec_x);
    Cvar_SetValue("sv_skyvec_y",local_94.skyVec_y);
    Cvar_SetValue("sv_skyvec_z",local_94.skyVec_z);
    if (0 < pSaveData->tableCount) {
      iVar5 = 0;
      do {
        piVar1 = (int *)((int)&pSaveData->pTable->id + iVar5);
        className = piVar1[5];
        if (((className == 0) || (piVar1[3] == 0)) || ((piVar1[4] & 0x40000000U) != 0)) {
          piVar1[1] = 0;
        }
        else {
          iVar3 = *piVar1;
          peVar4 = sv.edicts;
          if (iVar3 == 0) goto LAB_0005b096;
          if (svs.maxclients < iVar3) {
            peVar4 = CreateNamedEntity(className);
LAB_0005b0fa:
            piVar1 = (int *)((int)&pSaveData->pTable->id + iVar5);
          }
          else {
            if (piVar1[4] < 0) {
              if ((svs.clients[iVar3 + -1].edict != (edict_t *)0x0) &&
                 (peVar4 = svs.clients[iVar3 + -1].edict, createPlayers != 0)) goto LAB_0005b096;
            }
            else {
              iVar3 = iVar6;
              Sys_Error("ENTITY IS NOT A PLAYER: %d\n",iVar6);
              piVar1 = (int *)((int)&pSaveData->pTable->id + iVar5);
              peVar4 = svs.clients[*piVar1 + -1].edict;
              if ((createPlayers != 0) && (peVar4 != (edict_t *)0x0)) {
                className = piVar1[5];
                    /* Unresolved local var: ENTITYINIT pEntityInit@[???] */
                if (className == 0) {
                  Sys_Error("Bad class!!\n",iVar3);
                }
LAB_0005b096:
                ReleaseEntityDLLFields(peVar4);
                InitEntityDLLFields(peVar4);
                (peVar4->v).classname = className;
                pcVar2 = (code *)GetEntityInit(pr_strings + className);
                if (pcVar2 == (code *)0x0) goto LAB_0005b0fa;
                (*pcVar2)(&peVar4->v);
                piVar1 = (int *)((int)&pSaveData->pTable->id + iVar5);
                goto LAB_0005b085;
              }
            }
            peVar4 = (edict_t *)0x0;
          }
LAB_0005b085:
          piVar1[1] = (int)peVar4;
        }
        iVar3 = pSaveData->tableCount;
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0x18;
      } while (iVar6 < iVar3);
      if (0 < iVar3) {
        iVar6 = 0;
        do {
          while( true ) {
            peVar4 = pSaveData->pTable[iVar6].pent;
            pSaveData->currentIndex = iVar6;
            iVar5 = pSaveData->pTable[iVar6].location;
            pSaveData->size = iVar5;
            pSaveData->pCurrentData = pSaveData->pBaseData + iVar5;
            if (peVar4 != (edict_t *)0x0) break;
LAB_0005afa1:
            iVar6 = iVar6 + 1;
            if (iVar3 <= iVar6) goto LAB_0005b000;
          }
          iVar5 = (*gEntityInterface.pfnRestore)(peVar4,pSaveData,0);
          if (-1 < iVar5) {
            SV_LinkEdict(peVar4,false);
            iVar3 = pSaveData->tableCount;
            goto LAB_0005afa1;
          }
          iVar5 = iVar6 + 1;
          pSaveData->pTable[iVar6].pent = (edict_t *)0x0;
          ED_Free(peVar4);
          iVar3 = pSaveData->tableCount;
          iVar6 = iVar5;
        } while (iVar5 < iVar3);
      }
    }
LAB_0005b000:
    if (pSaveData->pTokens != (char **)0x0) {
      Mem_Free(pSaveData->pTokens);
      pSaveData->pTokens = (char **)0x0;
      pSaveData->tokenCount = 0;
    }
    Mem_Free(pSaveData);
    iVar6 = 1;
    gGlobalVariables.pSaveData = (void *)0x0;
    sv.time = (double)local_94.time;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}


// LoadSaveData  @ 00059d00
SAVERESTOREDATA * LoadSaveData(char *level)

{
  char *pcVar1;
  FileHandle_t file;
  int iVar2;
  SAVERESTOREDATA *pSVar3;
  char **ppcVar4;
  SAVERESTOREDATA *pSVar5;
  SAVERESTOREDATA *pOutput;
  int in_GS_OFFSET;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char[260] name@[???]
                       Unresolved local var: char * pszTokenList@[???]
                       Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int tokenCount@[???]
                       Unresolved local var: int tokenSize@[???]
                       Unresolved local var: int tableCount@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
  __snprintf_chk(local_124,0x104,1,0x104,"%s%s.HL1",Host_SaveGameDirectory::szDirectory,level);
  COM_FixSlashes(local_124);
  Con_Printf("Loading game from %s...\n",local_124);
  file = FS_OpenPathID(local_124,"rb","GAMECONFIG");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("ERROR: couldn\'t open.\n");
    pSVar3 = (SAVERESTOREDATA *)0x0;
  }
  else {
    FS_Read(&local_138,4,1,file);
    if ((local_138 == 0x564c4156) && (FS_Read(&local_138,4,1,file), local_138 < 0x72)) {
      FS_Read(&local_134,4,1,file);
      FS_Read(&local_128,4,1,file);
      FS_Read(&local_130,4,1,file);
      FS_Read(&local_12c,4,1,file);
      if ((-1 < local_134) &&
         (((-1 < local_130 && (-1 < local_12c)) && (local_12c <= 0x7fffffff - local_134)))) {
        if ((((uint)(local_128 * 0x18) <= 0x7fffffffU - (local_134 + local_12c)) &&
            (iVar2 = local_128 * 0x18 + local_134 + local_12c, 0x573 < 0x7fffffffU - iVar2)) &&
           (pSVar3 = Mem_Calloc(iVar2 + 0x574,1), pSVar3 != (SAVERESTOREDATA *)0x0)) {
          pSVar3->tableCount = local_128;
          pSVar3->tokenCount = local_130;
          pSVar3->tokenSize = local_12c;
          pOutput = pSVar3 + 1;
          Q_strncpy(pSVar3->szCurrentMapName,level,0x1f);
          pSVar3->szCurrentMapName[0x1f] = '\0';
          if (0 < local_12c) {
            FS_Read(pOutput,pSVar3->tokenSize,1,file);
            ppcVar4 = pSVar3->pTokens;
            if (ppcVar4 == (char **)0x0) {
              ppcVar4 = Mem_Calloc(local_130,4);
              pSVar3->pTokens = ppcVar4;
            }
            local_138 = 0;
            if (0 < local_130) {
              while( true ) {
                pSVar5 = (SAVERESTOREDATA *)0x0;
                if (*(char *)&pOutput->pBaseData != '\0') {
                  pSVar5 = pOutput;
                }
                ppcVar4[local_138] = (char *)pSVar5;
                pSVar5 = pOutput;
                do {
                  pOutput = (SAVERESTOREDATA *)((int)&pSVar5->pBaseData + 1);
                  ppcVar4 = &pSVar5->pBaseData;
                  pSVar5 = pOutput;
                } while (*(char *)ppcVar4 != '\0');
                local_138 = local_138 + 1;
                if (local_130 <= local_138) break;
                ppcVar4 = pSVar3->pTokens;
              }
            }
          }
          pSVar3->pTable = (ENTITYTABLE *)pOutput;
          pSVar3->connectionCount = 0;
          pSVar3->size = 0;
          pcVar1 = pOutput->levelList[0].mapName + pSVar3->tableCount * 0x18 + -0x2c;
          pSVar3->pBaseData = pcVar1;
          pSVar3->pCurrentData = pcVar1;
          pSVar3->fUseLandmark = 1;
          pSVar3->time = 0.0;
          pSVar3->vecLandmarkOffset[0] = 0.0;
          pSVar3->bufferSize = local_134;
          pSVar3->vecLandmarkOffset[1] = 0.0;
          pSVar3->vecLandmarkOffset[2] = 0.0;
          gGlobalVariables.pSaveData = pSVar3;
          FS_Read(pSVar3->pBaseData,local_134,1,file);
          FS_Close(file);
          goto LAB_0005a064;
        }
      }
    }
    FS_Close(file);
    pSVar3 = (SAVERESTOREDATA *)0x0;
  }
LAB_0005a064:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pSVar3;
}


// LoadSecurityModuleFromDisk  @ 00066450
void LoadSecurityModuleFromDisk(char *pszDllName)

{
  BlobFootprint_t BVar1;
  void *nAddrModule;
  code *pcVar2;
  
                    /* Unresolved local var: void * nAddrModule@[???] */
                    /* Unresolved local var: void * pvPco@[???]
                       Unresolved local var: PTYPE pfP@[???] */
  g_modfuncs.m_nVersion = 0x43210004;
  NLoadBlobFile(pszDllName,&g_blobfootprintModule,&g_modfuncs,'\x01');
  BVar1 = g_blobfootprintModule;
  if (g_blobfootprintModule.m_hDll == 0) {
    return;
  }
  nAddrModule = malloc(0x10000);
  g_pvModuleSpecial = nAddrModule;
  pcVar2 = (code *)dlsym(BVar1.m_hDll,&DAT_000d5b3c);
  (*pcVar2)(nAddrModule);
  CommonLoadSecurityModule(nAddrModule);
  return;
}


// LoadThisDll  @ 0007ac90
void LoadThisDll(char *szDllFilename)

{
  extensiondll_t *dest;
  int iVar1;
  void *pvVar2;
  code *pcVar3;
  undefined4 uVar4;
  
                    /* Unresolved local var: void * hDLL@[???]
                       Unresolved local var: extensiondll_t * pextdll@[???]
                       Unresolved local var: PFN_GiveFnptrsToDll pfnGiveFnptrsToDll@[???] */
  pvVar2 = (void *)dlopen(szDllFilename,2);
  if (pvVar2 == (void *)0x0) {
    uVar4 = dlerror();
    Con_Printf("LoadLibrary failed on %s: %s\n",szDllFilename,uVar4);
    return;
  }
  pcVar3 = (code *)dlsym(pvVar2,"GiveFnptrsToDll");
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(&g_engfuncsExportedToDlls,&gGlobalVariables);
    iVar1 = g_iextdllMac;
    if (g_iextdllMac != 0x32) {
      dest = g_rgextdll + g_iextdllMac;
      g_iextdllMac = g_iextdllMac + 1;
      Q_memset(dest,0,0xc);
      g_rgextdll[iVar1].lDLLHandle = pvVar2;
      return;
    }
    Con_Printf("Too many DLLs, ignoring remainder\n");
    dlclose();
    return;
  }
  Con_Printf("Couldn\'t get GiveFnptrsToDll in %s\n",szDllFilename);
  dlclose();
  return;
}


// LongNoSwap  @ 00039ac0
int32 LongNoSwap(int32 l)

{
  return l;
}


// LongSwap  @ 00039a90
int32 LongSwap(int32 l)

{
                    /* Unresolved local var: byte b1@[???]
                       Unresolved local var: byte b2@[???]
                       Unresolved local var: byte b3@[???]
                       Unresolved local var: byte b4@[???] */
  return ((uint)l >> 8 & 0xff00) + ((uint)l >> 8 & 0xff) * 0x10000 + l * 0x1000000 +
         ((uint)l >> 0x18);
}


// MD5Final  @ 00044e20
void MD5Final(uchar *digest,MD5Context_t *ctx)

{
  uchar *in;
  uint uVar1;
  
                    /* Unresolved local var: uint count@[???]
                       Unresolved local var: uchar * p@[???] */
  in = ctx->in;
  uVar1 = ctx->bits[0] >> 3 & 0x3f;
  in[uVar1] = 0x80;
  if (0x3f - uVar1 < 8) {
    Q_memset(ctx->in + uVar1 + 1,0,0x3f - uVar1);
    MD5Transform(ctx->buf,(uint *)in);
    Q_memset(in,0,0x38);
  }
  else {
    Q_memset(ctx->in + uVar1 + 1,0,0x37 - uVar1);
  }
  *(uint *)(ctx->in + 0x38) = ctx->bits[0];
  *(uint *)(ctx->in + 0x3c) = ctx->bits[1];
  MD5Transform(ctx->buf,(uint *)in);
  Q_memcpy(digest,ctx,0x10);
  Q_memset(ctx,0,4);
  return;
}


// MD5Init  @ 000445d0
void MD5Init(MD5Context_t *ctx)

{
  ctx->buf[0] = 0x67452301;
  ctx->buf[1] = 0xefcdab89;
  ctx->buf[2] = 0x98badcfe;
  ctx->buf[3] = 0x10325476;
  ctx->bits[0] = 0;
  ctx->bits[1] = 0;
  return;
}


// MD5Transform  @ 00044600
void MD5Transform(uint *buf,uint *in)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
                    /* Unresolved local var: uint a@[???]
                       Unresolved local var: uint b@[???]
                       Unresolved local var: uint c@[???]
                       Unresolved local var: uint d@[???] */
  uVar21 = *in;
  uVar10 = ((buf[2] ^ buf[3]) & buf[1] ^ buf[3]) + *buf + 0xd76aa478 + uVar21;
  uVar11 = (uVar10 * 0x80 | uVar10 >> 0x19) + buf[1];
  uVar10 = in[1];
  uVar15 = in[2];
  uVar16 = ((buf[1] ^ buf[2]) & uVar11 ^ buf[2]) + buf[3] + 0xe8c7b756 + uVar10;
  uVar17 = (uVar16 * 0x1000 | uVar16 >> 0x14) + uVar11;
  uVar16 = in[3];
  uVar1 = ((buf[1] ^ uVar11) & uVar17 ^ buf[1]) + buf[2] + 0x242070db + uVar15;
  uVar2 = (uVar1 >> 0xf | uVar1 * 0x20000) + uVar17;
  uVar6 = ((uVar11 ^ uVar17) & uVar2 ^ uVar11) + buf[1] + 0xc1bdceee + uVar16;
  uVar1 = in[4];
  uVar7 = (uVar6 >> 10 | uVar6 * 0x400000) + uVar2;
  uVar11 = ((uVar17 ^ uVar2) & uVar7 ^ uVar17) + uVar11 + 0xf57c0faf + uVar1;
  uVar6 = in[5];
  uVar12 = (uVar11 * 0x80 | uVar11 >> 0x19) + uVar7;
  uVar17 = ((uVar2 ^ uVar7) & uVar12 ^ uVar2) + uVar17 + 0x4787c62a + uVar6;
  uVar11 = in[6];
  uVar18 = (uVar17 * 0x1000 | uVar17 >> 0x14) + uVar12;
  uVar17 = ((uVar7 ^ uVar12) & uVar18 ^ uVar7) + uVar2 + 0xa8304613 + uVar11;
  uVar2 = in[7];
  uVar3 = (uVar17 >> 0xf | uVar17 * 0x20000) + uVar18;
  uVar7 = ((uVar12 ^ uVar18) & uVar3 ^ uVar12) + uVar7 + 0xfd469501 + uVar2;
  uVar17 = in[8];
  uVar8 = (uVar7 >> 10 | uVar7 * 0x400000) + uVar3;
  uVar12 = ((uVar18 ^ uVar3) & uVar8 ^ uVar18) + uVar12 + 0x698098d8 + uVar17;
  uVar7 = in[9];
  uVar13 = (uVar12 * 0x80 | uVar12 >> 0x19) + uVar8;
  uVar18 = ((uVar3 ^ uVar8) & uVar13 ^ uVar3) + uVar18 + 0x8b44f7af + uVar7;
  uVar12 = in[10];
  uVar19 = (uVar18 * 0x1000 | uVar18 >> 0x14) + uVar13;
  uVar18 = ((uVar8 ^ uVar13) & uVar19 ^ uVar8) + (uVar3 - 0xa44f) + uVar12;
  uVar3 = in[0xb];
  uVar4 = (uVar18 >> 0xf | uVar18 * 0x20000) + uVar19;
  uVar8 = ((uVar13 ^ uVar19) & uVar4 ^ uVar13) + uVar8 + 0x895cd7be + uVar3;
  uVar18 = in[0xc];
  uVar9 = (uVar8 >> 10 | uVar8 * 0x400000) + uVar4;
  uVar13 = ((uVar19 ^ uVar4) & uVar9 ^ uVar19) + uVar13 + 0x6b901122 + uVar18;
  uVar8 = in[0xd];
  uVar14 = (uVar13 * 0x80 | uVar13 >> 0x19) + uVar9;
  uVar19 = ((uVar4 ^ uVar9) & uVar14 ^ uVar4) + uVar19 + 0xfd987193 + uVar8;
  uVar13 = in[0xe];
  uVar20 = (uVar19 * 0x1000 | uVar19 >> 0x14) + uVar14;
  uVar19 = ((uVar9 ^ uVar14) & uVar20 ^ uVar9) + uVar4 + 0xa679438e + uVar13;
  uVar4 = in[0xf];
  uVar5 = (uVar19 >> 0xf | uVar19 * 0x20000) + uVar20;
  uVar19 = ((uVar14 ^ uVar20) & uVar5 ^ uVar14) + uVar9 + 0x49b40821 + uVar4;
  uVar9 = (uVar19 >> 10 | uVar19 * 0x400000) + uVar5;
  uVar19 = ((uVar5 ^ uVar9) & uVar20 ^ uVar5) + uVar10 + 0xf61e2562 + uVar14;
  uVar19 = (uVar19 * 0x20 | uVar19 >> 0x1b) + uVar9;
  uVar14 = ((uVar9 ^ uVar19) & uVar5 ^ uVar9) + uVar11 + 0xc040b340 + uVar20;
  uVar14 = (uVar14 * 0x200 | uVar14 >> 0x17) + uVar19;
  uVar5 = ((uVar19 ^ uVar14) & uVar9 ^ uVar19) + uVar3 + 0x265e5a51 + uVar5;
  uVar5 = (uVar5 * 0x4000 | uVar5 >> 0x12) + uVar14;
  uVar9 = ((uVar14 ^ uVar5) & uVar19 ^ uVar14) + uVar21 + 0xe9b6c7aa + uVar9;
  uVar9 = (uVar9 >> 0xc | uVar9 * 0x100000) + uVar5;
  uVar19 = ((uVar5 ^ uVar9) & uVar14 ^ uVar5) + uVar6 + 0xd62f105d + uVar19;
  uVar19 = (uVar19 * 0x20 | uVar19 >> 0x1b) + uVar9;
  uVar14 = ((uVar9 ^ uVar19) & uVar5 ^ uVar9) + uVar12 + 0x2441453 + uVar14;
  uVar14 = (uVar14 * 0x200 | uVar14 >> 0x17) + uVar19;
  uVar5 = ((uVar19 ^ uVar14) & uVar9 ^ uVar19) + uVar4 + 0xd8a1e681 + uVar5;
  uVar5 = (uVar5 * 0x4000 | uVar5 >> 0x12) + uVar14;
  uVar9 = ((uVar14 ^ uVar5) & uVar19 ^ uVar14) + uVar1 + 0xe7d3fbc8 + uVar9;
  uVar9 = (uVar9 >> 0xc | uVar9 * 0x100000) + uVar5;
  uVar19 = ((uVar5 ^ uVar9) & uVar14 ^ uVar5) + uVar7 + 0x21e1cde6 + uVar19;
  uVar19 = (uVar19 * 0x20 | uVar19 >> 0x1b) + uVar9;
  uVar14 = ((uVar9 ^ uVar19) & uVar5 ^ uVar9) + uVar13 + 0xc33707d6 + uVar14;
  uVar14 = (uVar14 * 0x200 | uVar14 >> 0x17) + uVar19;
  uVar5 = ((uVar19 ^ uVar14) & uVar9 ^ uVar19) + uVar16 + 0xf4d50d87 + uVar5;
  uVar5 = (uVar5 * 0x4000 | uVar5 >> 0x12) + uVar14;
  uVar9 = ((uVar14 ^ uVar5) & uVar19 ^ uVar14) + uVar17 + 0x455a14ed + uVar9;
  uVar9 = (uVar9 >> 0xc | uVar9 * 0x100000) + uVar5;
  uVar19 = ((uVar5 ^ uVar9) & uVar14 ^ uVar5) + uVar8 + 0xa9e3e905 + uVar19;
  uVar19 = (uVar19 * 0x20 | uVar19 >> 0x1b) + uVar9;
  uVar14 = ((uVar9 ^ uVar19) & uVar5 ^ uVar9) + uVar15 + 0xfcefa3f8 + uVar14;
  uVar14 = (uVar14 * 0x200 | uVar14 >> 0x17) + uVar19;
  uVar5 = ((uVar19 ^ uVar14) & uVar9 ^ uVar19) + uVar2 + 0x676f02d9 + uVar5;
  uVar5 = (uVar5 * 0x4000 | uVar5 >> 0x12) + uVar14;
  uVar9 = uVar18 + 0x8d2a4c8a + uVar9 + (uVar19 & (uVar14 ^ uVar5) ^ uVar14);
  uVar9 = (uVar9 >> 0xc | uVar9 * 0x100000) + uVar5;
  uVar19 = (uVar14 ^ uVar5 ^ uVar9) + (uVar6 - 0x5c6be) + uVar19;
  uVar20 = (uVar19 * 0x10 | uVar19 >> 0x1c) + uVar9;
  uVar19 = (uVar5 ^ uVar9 ^ uVar20) + uVar17 + 0x8771f681 + uVar14;
  uVar19 = (uVar19 * 0x800 | uVar19 >> 0x15) + uVar20;
  uVar5 = (uVar9 ^ uVar20 ^ uVar19) + uVar3 + 0x6d9d6122 + uVar5;
  uVar5 = (uVar5 * 0x10000 | uVar5 >> 0x10) + uVar19;
  uVar9 = (uVar20 ^ uVar19 ^ uVar5) + uVar13 + 0xfde5380c + uVar9;
  uVar9 = (uVar9 >> 9 | uVar9 * 0x800000) + uVar5;
  uVar14 = (uVar19 ^ uVar5 ^ uVar9) + uVar10 + 0xa4beea44 + uVar20;
  uVar14 = (uVar14 * 0x10 | uVar14 >> 0x1c) + uVar9;
  uVar19 = (uVar5 ^ uVar9 ^ uVar14) + uVar1 + 0x4bdecfa9 + uVar19;
  uVar19 = (uVar19 * 0x800 | uVar19 >> 0x15) + uVar14;
  uVar5 = (uVar9 ^ uVar14 ^ uVar19) + uVar2 + 0xf6bb4b60 + uVar5;
  uVar5 = (uVar5 * 0x10000 | uVar5 >> 0x10) + uVar19;
  uVar9 = (uVar14 ^ uVar19 ^ uVar5) + uVar12 + 0xbebfbc70 + uVar9;
  uVar20 = (uVar9 >> 9 | uVar9 * 0x800000) + uVar5;
  uVar9 = (uVar19 ^ uVar5 ^ uVar20) + uVar8 + 0x289b7ec6 + uVar14;
  uVar9 = (uVar9 * 0x10 | uVar9 >> 0x1c) + uVar20;
  uVar19 = (uVar5 ^ uVar20 ^ uVar9) + uVar21 + 0xeaa127fa + uVar19;
  uVar14 = (uVar19 * 0x800 | uVar19 >> 0x15) + uVar9;
  uVar19 = (uVar20 ^ uVar9 ^ uVar14) + uVar16 + 0xd4ef3085 + uVar5;
  uVar5 = (uVar19 * 0x10000 | uVar19 >> 0x10) + uVar14;
  uVar19 = (uVar9 ^ uVar14 ^ uVar5) + uVar11 + 0x4881d05 + uVar20;
  uVar19 = (uVar19 >> 9 | uVar19 * 0x800000) + uVar5;
  uVar9 = (uVar14 ^ uVar5 ^ uVar19) + uVar7 + 0xd9d4d039 + uVar9;
  uVar20 = (uVar9 * 0x10 | uVar9 >> 0x1c) + uVar19;
  uVar9 = (uVar5 ^ uVar19 ^ uVar20) + uVar18 + 0xe6db99e5 + uVar14;
  uVar9 = (uVar9 * 0x800 | uVar9 >> 0x15) + uVar20;
  uVar5 = (uVar19 ^ uVar20 ^ uVar9) + uVar4 + 0x1fa27cf8 + uVar5;
  uVar5 = (uVar5 * 0x10000 | uVar5 >> 0x10) + uVar9;
  uVar19 = (uVar20 ^ uVar9 ^ uVar5) + uVar15 + 0xc4ac5665 + uVar19;
  uVar19 = (uVar19 >> 9 | uVar19 * 0x800000) + uVar5;
  uVar21 = ((~uVar9 | uVar19) ^ uVar5) + uVar21 + 0xf4292244 + uVar20;
  uVar14 = (uVar21 * 0x40 | uVar21 >> 0x1a) + uVar19;
  uVar21 = uVar2 + 0x432aff97 + uVar9 + ((~uVar5 | uVar14) ^ uVar19);
  uVar21 = (uVar21 * 0x400 | uVar21 >> 0x16) + uVar14;
  uVar2 = ((~uVar19 | uVar21) ^ uVar14) + uVar13 + 0xab9423a7 + uVar5;
  uVar13 = (uVar2 * 0x8000 | uVar2 >> 0x11) + uVar21;
  uVar6 = uVar6 + 0xfc93a039 + uVar19 + ((~uVar14 | uVar13) ^ uVar21);
  uVar2 = (uVar6 >> 0xb | uVar6 * 0x200000) + uVar13;
  uVar6 = ((~uVar21 | uVar2) ^ uVar13) + uVar18 + 0x655b59c3 + uVar14;
  uVar6 = (uVar6 * 0x40 | uVar6 >> 0x1a) + uVar2;
  uVar21 = uVar16 + 0x8f0ccc92 + uVar21 + ((~uVar13 | uVar6) ^ uVar2);
  uVar21 = (uVar21 * 0x400 | uVar21 >> 0x16) + uVar6;
  uVar16 = ((~uVar2 | uVar21) ^ uVar6) + (uVar12 - 0x100b83) + uVar13;
  uVar12 = (uVar16 * 0x8000 | uVar16 >> 0x11) + uVar21;
  uVar10 = ((~uVar6 | uVar12) ^ uVar21) + uVar10 + 0x85845dd1 + uVar2;
  uVar2 = (uVar10 >> 0xb | uVar10 * 0x200000) + uVar12;
  uVar10 = uVar17 + 0x6fa87e4f + uVar6 + ((~uVar21 | uVar2) ^ uVar12);
  uVar16 = (uVar10 * 0x40 | uVar10 >> 0x1a) + uVar2;
  uVar21 = ((~uVar12 | uVar16) ^ uVar2) + uVar4 + 0xfe2ce6e0 + uVar21;
  uVar10 = (uVar21 * 0x400 | uVar21 >> 0x16) + uVar16;
  uVar21 = uVar11 + 0xa3014314 + uVar12 + ((~uVar2 | uVar10) ^ uVar16);
  uVar21 = (uVar21 * 0x8000 | uVar21 >> 0x11) + uVar10;
  uVar6 = ((~uVar16 | uVar21) ^ uVar10) + uVar8 + 0x4e0811a1 + uVar2;
  uVar6 = (uVar6 >> 0xb | uVar6 * 0x200000) + uVar21;
  uVar16 = uVar1 + 0xf7537e82 + uVar16 + ((~uVar10 | uVar6) ^ uVar21);
  uVar16 = (uVar16 * 0x40 | uVar16 >> 0x1a) + uVar6;
  uVar10 = uVar3 + 0xbd3af235 + uVar10 + ((~uVar21 | uVar16) ^ uVar6);
  uVar10 = (uVar10 * 0x400 | uVar10 >> 0x16) + uVar16;
  uVar21 = uVar15 + 0x2ad7d2bb + uVar21 + ((~uVar6 | uVar10) ^ uVar16);
  uVar21 = (uVar21 * 0x8000 | uVar21 >> 0x11) + uVar10;
  uVar15 = ((~uVar16 | uVar21) ^ uVar10) + uVar7 + 0xeb86d391 + uVar6;
  *buf = uVar16 + *buf;
  buf[2] = uVar21 + buf[2];
  buf[1] = (uVar15 >> 0xb | uVar15 * 0x200000) + buf[1] + uVar21;
  buf[3] = uVar10 + buf[3];
  return;
}


// MD5Update  @ 00044cf0
void MD5Update(MD5Context_t *ctx,uchar *buf,uint len)

{
  uchar *in;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uchar *src;
  uint local_24;
  uchar *local_20;
  
                    /* Unresolved local var: uint t@[???] */
  local_20 = buf;
  local_24 = len;
  uVar2 = ctx->bits[0];
  uVar1 = uVar2 + len * 8;
  ctx->bits[0] = uVar1;
  uVar3 = ctx->bits[1];
  if (uVar1 < uVar2) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = uVar2 >> 3 & 0x3f;
  ctx->bits[1] = uVar3 + (len >> 0x1d);
                    /* Unresolved local var: uchar * p@[???] */
  in = ctx->in;
  if (uVar1 != 0) {
    uVar2 = 0x40 - uVar1;
    if (len < uVar2) {
      Q_memcpy(in + uVar1,buf,len);
      return;
    }
    Q_memcpy(in + uVar1,buf,uVar2);
    MD5Transform(ctx->buf,(uint *)in);
    local_24 = len - uVar2;
    local_20 = buf + uVar2;
  }
  src = local_20;
  uVar1 = local_24;
  if (0x3f < local_24) {
    do {
      uVar1 = uVar1 - 0x40;
      Q_memcpy(in,src,0x40);
      MD5Transform(ctx->buf,(uint *)in);
      src = src + 0x40;
    } while (0x3f < uVar1);
    local_20 = local_20 + (local_24 - 0x40 & 0xffffffc0) + 0x40;
    local_24 = local_24 & 0x3f;
  }
  Q_memcpy(in,local_20,local_24);
  return;
}


// MaskExceptions  @ 00079b10
void MaskExceptions(void)

{
  return;
}


// ModelFrameCount  @ 00078760
int ModelFrameCount(model_t *model)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int count@[???] */
  if (model == (model_t *)0x0) {
    return 1;
  }
  if (model->type == mod_sprite) {
                    /* Unresolved local var: msprite_t * psprite@[???] */
    iVar3 = *(int *)((int)(model->cache).data + 0xc);
  }
  else {
    if (model->type != mod_studio) {
      return 1;
    }
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudiobodyparts_t * pbodypart@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
    pvVar2 = Mod_Extradata(model);
    if (pvVar2 == (void *)0x0) {
      return 1;
    }
    if (*(int *)((int)pvVar2 + 0xcc) < 1) {
      return 1;
    }
    iVar4 = (int)pvVar2 + *(int *)((int)pvVar2 + 0xd0);
    iVar3 = 1;
    do {
      piVar1 = (int *)(iVar4 + 0x40);
      iVar4 = iVar4 + 0x4c;
      iVar3 = iVar3 * *piVar1;
    } while (*(int *)((int)pvVar2 + 0xd0) + *(int *)((int)pvVar2 + 0xcc) * 0x4c + (int)pvVar2 !=
             iVar4);
  }
  if (iVar3 < 1) {
    return 1;
  }
  return iVar3;
}


// ModelFrames  @ 0006dd50
int ModelFrames(int modelIndex)

{
  int iVar1;
  
                    /* Unresolved local var: model_t * pModel@[???] */
  if (0x1fe < modelIndex - 1U) {
    Con_DPrintf("Bad sprite index!\n");
    return 1;
  }
  iVar1 = ModelFrameCount(sv.models[modelIndex]);
  return iVar1;
}


// NLoadBlobFile  @ 0004c870
void * NLoadBlobFile(char *pstFileName,BlobFootprint_t *pblobfootprint,void *pv,char fLoadAsDll)

{
  void *pvVar1;
  code *pcVar2;
  int in_GS_OFFSET;
  undefined1 local_1020 [2048];
  char local_820 [2048];
  int local_20;
  
                    /* Unresolved local var: void * nRet@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (fLoadAsDll == '\0') {
    pvVar1 = (void *)0x0;
  }
  else {
                    /* Unresolved local var: char[2048] rgchNew@[???]
                       Unresolved local var: char[2048] rgchLocalPath@[???]
                       Unresolved local var: int32 hmoduleT@[???] */
    __strcpy_chk(local_1020,pstFileName,0x800);
    (**(code **)(*(int *)g_pFileSystem + 0x84))(g_pFileSystem,local_1020,local_820,0x800);
    pvVar1 = FS_LoadLibrary(local_820);
    pblobfootprint->m_hDll = (int32)pvVar1;
    if (pvVar1 != (void *)0x0) {
                    /* Unresolved local var: FTYPE pfF@[???] */
      pcVar2 = (code *)dlsym(pvVar1,&DAT_000d4316);
      if (pcVar2 == (code *)0x0) {
        dlclose(pvVar1);
        pvVar1 = (void *)0x0;
      }
      else {
        (*pcVar2)(pv);
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pvVar1;
}


// NameForFunction  @ 0007ac20
char * NameForFunction(uint32 function)

{
  int iVar1;
  int iVar2;
  undefined1 local_1c [8];
  char *local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * pName@[???] */
  iVar2 = 0;
  if (0 < g_iextdllMac) {
    do {
                    /* Unresolved local var: Dl_info addrInfo@[???] */
      iVar1 = dladdr(function,local_1c);
      if ((iVar1 != 0) && (local_14 != (char *)0x0)) {
        return local_14;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < g_iextdllMac);
  }
  Con_Printf("Can\'t find address: %08lx\n",function);
  return (char *)0x0;
}


// NetadrToSockadr  @ 000af360
void NetadrToSockadr(netadr_t *a,sockaddr *s)

{
  ushort uVar1;
  
  Q_memset(s,0,0x10);
  if (a->type == NA_BROADCAST) {
    s->sa_family = 2;
    uVar1 = a->port;
    s->sa_data[2] = -1;
    s->sa_data[3] = -1;
    s->sa_data[4] = -1;
    s->sa_data[5] = -1;
    *(ushort *)s->sa_data = uVar1;
    return;
  }
  if (a->type != NA_IP) {
    return;
  }
  s->sa_family = 2;
  *(undefined4 *)(s->sa_data + 2) = *(undefined4 *)a->ip;
  *(ushort *)s->sa_data = a->port;
  return;
}


// NormalizeAngles  @ 000605d0
void NormalizeAngles(float *angles)

{
  float fVar1;
  
                    /* Unresolved local var: int i@[???] */
  fVar1 = *angles;
  if (180.0 < fVar1) {
    *angles = fVar1 - 360.0;
    fVar1 = angles[1];
  }
  else {
    if (fVar1 < -180.0) {
      *angles = fVar1 + 360.0;
    }
    fVar1 = angles[1];
  }
  if (180.0 < fVar1) {
    angles[1] = fVar1 - 360.0;
    fVar1 = angles[2];
  }
  else {
    if (fVar1 < -180.0) {
      angles[1] = fVar1 + 360.0;
    }
    fVar1 = angles[2];
  }
  if (180.0 < fVar1) {
    angles[2] = fVar1 - 360.0;
    return;
  }
  if (fVar1 < -180.0) {
    angles[2] = fVar1 + 360.0;
  }
  return;
}


// NotifyDedicatedServerUI  @ 000b5030
void NotifyDedicatedServerUI(char *message)

{
  int *piVar1;
  uchar *puVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  ListElem_t *pLVar7;
  int iVar8;
  ListElem_t *pLVar9;
  
  iVar8 = g_ServerRemoteAccess.m_ResponsePackets.m_TotalElements;
  iVar5 = g_ServerRemoteAccess.m_ResponsePackets.m_FirstFree;
  pLVar9 = g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CUtlBuffer * response@[???]
                       Unresolved local var: int newNode@[DW_OP_reg6(ESI)]
                       Unresolved local var: int elem@[???] */
  if (g_ServerRemoteAccess.m_ResponsePackets.m_FirstFree == -1) {
    if (g_ServerRemoteAccess.m_ResponsePackets.m_TotalElements ==
        g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_NumAllocated) {
                    /* Unresolved local var: int growSize@[???] */
      iVar5 = g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_GrowSize;
      if ((g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_GrowSize == 0) &&
         (iVar5 = 1, g_ServerRemoteAccess.m_ResponsePackets.m_TotalElements != 0)) {
        iVar5 = g_ServerRemoteAccess.m_ResponsePackets.m_TotalElements;
      }
                    /* Unresolved local var: int growSize@[???] */
      g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_NumAllocated =
           iVar5 + g_ServerRemoteAccess.m_ResponsePackets.m_TotalElements;
      if (g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory == (ListElem_t *)0x0) {
        g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory =
             malloc(g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_NumAllocated * 0x20);
      }
      else {
        g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory =
             realloc(g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory,
                     g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_NumAllocated * 0x20);
        iVar8 = g_ServerRemoteAccess.m_ResponsePackets.m_TotalElements;
      }
    }
    pLVar9 = g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory;
    pLVar7 = g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory + iVar8;
    g_ServerRemoteAccess.m_ResponsePackets.m_TotalElements = iVar8 + 1;
    pLVar7->m_Previous = iVar8;
    pLVar7->m_Next = iVar8;
    iVar5 = iVar8;
  }
  else {
    pLVar7 = g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory +
             g_ServerRemoteAccess.m_ResponsePackets.m_FirstFree;
    iVar8 = pLVar7->m_Next;
    pLVar7->m_Next = g_ServerRemoteAccess.m_ResponsePackets.m_FirstFree;
    pLVar7->m_Previous = g_ServerRemoteAccess.m_ResponsePackets.m_FirstFree;
    g_ServerRemoteAccess.m_ResponsePackets.m_FirstFree = iVar8;
  }
  if (pLVar7 == (ListElem_t *)0x0) {
    pLVar7 = (ListElem_t *)0x0;
  }
  else {
    CUtlBuffer::CUtlBuffer((CUtlBuffer *)pLVar7,0,0,false);
    pLVar7 = g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory + iVar5;
    pLVar9 = g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory;
  }
                    /* Unresolved local var: ListElem_t * newElem@[???] */
  g_ServerRemoteAccess.m_ResponsePackets.m_pElements = pLVar9;
  if (((iVar5 < g_ServerRemoteAccess.m_ResponsePackets.m_TotalElements) && (-1 < iVar5)) &&
     (iVar8 = pLVar7->m_Previous, iVar5 != iVar8)) {
                    /* Unresolved local var: ListElem_t * oldElem@[???] */
    if (iVar8 == -1) {
      iVar8 = pLVar7->m_Next;
      iVar6 = -1;
      g_ServerRemoteAccess.m_ResponsePackets.m_Head = iVar8;
    }
    else {
      pLVar9[iVar8].m_Next = pLVar7->m_Next;
      iVar8 = pLVar7->m_Next;
      iVar6 = pLVar7->m_Previous;
    }
    if (iVar8 != -1) {
      pLVar9[iVar8].m_Previous = iVar6;
      iVar6 = g_ServerRemoteAccess.m_ResponsePackets.m_Tail;
    }
    pLVar7->m_Next = iVar5;
    pLVar7->m_Previous = iVar5;
    g_ServerRemoteAccess.m_ResponsePackets.m_ElementCount =
         g_ServerRemoteAccess.m_ResponsePackets.m_ElementCount + -1;
    g_ServerRemoteAccess.m_ResponsePackets.m_Tail = iVar6;
  }
  pLVar7->m_Next = -1;
  pLVar7->m_Previous = g_ServerRemoteAccess.m_ResponsePackets.m_Tail;
  iVar8 = iVar5;
  iVar6 = iVar5;
  if (g_ServerRemoteAccess.m_ResponsePackets.m_Tail != -1) {
    pLVar9 = pLVar9 + g_ServerRemoteAccess.m_ResponsePackets.m_Tail;
    g_ServerRemoteAccess.m_ResponsePackets.m_Tail = iVar5;
    pLVar9->m_Next = iVar5;
    iVar8 = g_ServerRemoteAccess.m_ResponsePackets.m_Head;
    iVar6 = g_ServerRemoteAccess.m_ResponsePackets.m_Tail;
  }
  g_ServerRemoteAccess.m_ResponsePackets.m_Tail = iVar6;
  g_ServerRemoteAccess.m_ResponsePackets.m_Head = iVar8;
  g_ServerRemoteAccess.m_ResponsePackets.m_ElementCount =
       g_ServerRemoteAccess.m_ResponsePackets.m_ElementCount + 1;
  if (pLVar7 == (ListElem_t *)0x0) {
    pLVar9 = (ListElem_t *)0x0;
  }
  else {
    CUtlBuffer::CUtlBuffer((CUtlBuffer *)pLVar7,0,0,false);
    pLVar9 = g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory + iVar5;
  }
  if (((pLVar9->m_Element).packet.m_Flags & 1) == 0) {
    bVar4 = CUtlBuffer::CheckPut((CUtlBuffer *)pLVar9,4);
    if (bVar4) {
      puVar2 = (pLVar9->m_Element).packet.m_Memory.m_pMemory + (pLVar9->m_Element).packet.m_Put;
      puVar2[0] = '\0';
      puVar2[1] = '\0';
      puVar2[2] = '\0';
      puVar2[3] = '\0';
      piVar1 = &(pLVar9->m_Element).packet.m_Put;
      *piVar1 = *piVar1 + 4;
    }
    bVar3 = (pLVar9->m_Element).packet.m_Flags;
  }
  else {
    CUtlBuffer::Printf((CUtlBuffer *)pLVar9,"%d",0);
    bVar3 = (pLVar9->m_Element).packet.m_Flags;
  }
  if ((bVar3 & 1) == 0) {
    bVar4 = CUtlBuffer::CheckPut((CUtlBuffer *)pLVar9,4);
    if (bVar4) {
      puVar2 = (pLVar9->m_Element).packet.m_Memory.m_pMemory + (pLVar9->m_Element).packet.m_Put;
      puVar2[0] = '\x01';
      puVar2[1] = '\0';
      puVar2[2] = '\0';
      puVar2[3] = '\0';
      piVar1 = &(pLVar9->m_Element).packet.m_Put;
      *piVar1 = *piVar1 + 4;
    }
  }
  else {
    CUtlBuffer::Printf((CUtlBuffer *)pLVar9,"%d",1);
  }
  CUtlBuffer::PutString((CUtlBuffer *)pLVar9,message);
  return;
}


// NullDst  @ 00066270
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NullDst(void)

{
  return;
}


// ObjectList::Add  @ 000c2c90
/* DWARF original prototype: bool Add(ObjectList * this, void * newObject) */

bool __thiscall ObjectList::Add(ObjectList *this,void *newObject)

{
  element_s *peVar1;
  
                    /* Unresolved local var: element_t * newElement@[???] */
  peVar1 = Mem_ZeroMalloc(0xc);
  if (peVar1 != (element_s *)0x0) {
    peVar1->object = newObject;
    if (this->tail != (element_t *)0x0) {
      peVar1->prev = this->tail;
      this->tail->next = peVar1;
    }
    this->tail = peVar1;
    if (this->head == (element_t *)0x0) {
      this->head = peVar1;
    }
    this->number = this->number + 1;
    return true;
  }
  return false;
}


// ObjectList::AddHead  @ 000c2d20
/* DWARF original prototype: bool AddHead(ObjectList * this, void * newObject) */

bool __thiscall ObjectList::AddHead(ObjectList *this,void *newObject)

{
  element_s *peVar1;
  
                    /* Unresolved local var: element_t * newElement@[???] */
  peVar1 = Mem_ZeroMalloc(0xc);
  if (peVar1 != (element_s *)0x0) {
    peVar1->object = newObject;
    if (this->head != (element_t *)0x0) {
      peVar1->next = this->head;
      this->head->prev = peVar1;
    }
    this->head = peVar1;
    if (this->tail == (element_t *)0x0) {
      this->tail = peVar1;
    }
    this->number = this->number + 1;
    return true;
  }
  return false;
}


// ObjectList::AddTail  @ 000c2df0
/* DWARF original prototype: bool AddTail(ObjectList * this, void * newObject) */

bool __thiscall ObjectList::AddTail(ObjectList *this,void *newObject)

{
  element_s *peVar1;
  
                    /* Unresolved local var: element_t * newElement@[???] */
  peVar1 = Mem_ZeroMalloc(0xc);
  if (peVar1 != (element_s *)0x0) {
    peVar1->object = newObject;
    if (this->tail != (element_t *)0x0) {
      peVar1->prev = this->tail;
      this->tail->next = peVar1;
    }
    this->tail = peVar1;
    if (this->head == (element_t *)0x0) {
      this->head = peVar1;
    }
    this->number = this->number + 1;
    return true;
  }
  return false;
}


// ObjectList::Clear  @ 000c2af0
/* DWARF original prototype: void Clear(ObjectList * this, bool freeElementsMemory) */

void __thiscall ObjectList::Clear(ObjectList *this,bool freeElementsMemory)

{
  element_s *peVar1;
  element_t *p;
  
                    /* Unresolved local var: element_t * ne@[???]
                       Unresolved local var: element_t * e@[???] */
  p = this->head;
  if (p != (element_t *)0x0) {
    if (freeElementsMemory) {
      do {
        peVar1 = p->next;
        if (p->object != (void *)0x0) {
          Mem_Free(p->object);
        }
        Mem_Free(p);
        p = peVar1;
      } while (peVar1 != (element_s *)0x0);
    }
    else {
      do {
        peVar1 = p->next;
        Mem_Free(p);
        p = peVar1;
      } while (peVar1 != (element_s *)0x0);
    }
  }
  this->current = (element_t *)0x0;
  this->tail = (element_t *)0x0;
  this->head = (element_t *)0x0;
  this->number = 0;
  return;
}


// ObjectList::Contains  @ 000c2a30
/* DWARF original prototype: bool Contains(ObjectList * this, void * object) */

bool __thiscall ObjectList::Contains(ObjectList *this,void *object)

{
  void *pvVar1;
  element_t *peVar2;
  
                    /* Unresolved local var: element_t * e@[???] */
  peVar2 = this->head;
  if (peVar2 == (element_t *)0x0) {
    return false;
  }
  pvVar1 = peVar2->object;
  while( true ) {
    if (object == pvVar1) {
      this->current = peVar2;
      return true;
    }
    peVar2 = peVar2->next;
    if (peVar2 == (element_s *)0x0) break;
    pvVar1 = peVar2->object;
  }
  return false;
}


// ObjectList::CountElements  @ 000c2a20
/* DWARF original prototype: int CountElements(ObjectList * this) */

int __thiscall ObjectList::CountElements(ObjectList *this)

{
  return this->number;
}


// ObjectList::GetFirst  @ 000c2aa0
/* DWARF original prototype: void * GetFirst(ObjectList * this) */

void * __thiscall ObjectList::GetFirst(ObjectList *this)

{
  element_t *peVar1;
  
  peVar1 = this->head;
  if (peVar1 != (element_t *)0x0) {
    this->current = peVar1->next;
    return peVar1->object;
  }
  this->current = (element_t *)0x0;
  return (void *)0x0;
}


// ObjectList::GetNext  @ 000c2ad0
/* DWARF original prototype: void * GetNext(ObjectList * this) */

void * __thiscall ObjectList::GetNext(ObjectList *this)

{
  element_t *peVar1;
  void *pvVar2;
  
                    /* Unresolved local var: void * retObj@[???] */
  peVar1 = this->current;
  if (peVar1 != (element_t *)0x0) {
    pvVar2 = peVar1->object;
    this->current = peVar1->next;
    return pvVar2;
  }
  return (void *)0x0;
}


// ObjectList::Init  @ 000c2a70
/* DWARF original prototype: void Init(ObjectList * this) */

void __thiscall ObjectList::Init(ObjectList *this)

{
  this->current = (element_t *)0x0;
  this->tail = (element_t *)0x0;
  this->head = (element_t *)0x0;
  this->number = 0;
  return;
}


// ObjectList::IsEmpty  @ 000c2a10
/* DWARF original prototype: bool IsEmpty(ObjectList * this) */

bool __thiscall ObjectList::IsEmpty(ObjectList *this)

{
  return this->head == (element_t *)0x0;
}


// ObjectList::ObjectList  @ 000c2cf0
/* DWARF original prototype: void ObjectList(ObjectList * this) */

void __thiscall ObjectList::ObjectList(ObjectList *this)

{
  (this->super_IObjectContainer)._vptr_IObjectContainer =
       (_func_int_varargs **)&PTR__ObjectList_000de8b4;
  this->current = (element_t *)0x0;
  this->tail = (element_t *)0x0;
  this->head = (element_t *)0x0;
  this->number = 0;
  return;
}


// ObjectList::Remove  @ 000c2b70
/* DWARF original prototype: bool Remove(ObjectList * this, void * object) */

bool __thiscall ObjectList::Remove(ObjectList *this,void *object)

{
  void *pvVar1;
  element_t *p;
  element_t *peVar2;
  
                    /* Unresolved local var: element_t * e@[???] */
  p = this->head;
  if (p != (element_t *)0x0) {
    pvVar1 = p->object;
    while( true ) {
      if (object == pvVar1) {
        if (p->prev != (element_s *)0x0) {
          p->prev->next = p->next;
        }
        if (p->next != (element_s *)0x0) {
          p->next->prev = p->prev;
        }
        if (this->head == p) {
          peVar2 = this->tail;
          this->head = p->next;
        }
        else {
          peVar2 = this->tail;
        }
        if (peVar2 == p) {
          peVar2 = this->current;
          this->tail = p->prev;
        }
        else {
          peVar2 = this->current;
        }
        if (peVar2 == p) {
          this->current = p->next;
        }
        Mem_Free(p);
        this->number = this->number + -1;
        return true;
      }
      p = p->next;
      if (p == (element_s *)0x0) break;
      pvVar1 = p->object;
    }
  }
  return false;
}


// ObjectList::RemoveHead  @ 000c2d80
/* DWARF original prototype: void * RemoveHead(ObjectList * this) */

void * __thiscall ObjectList::RemoveHead(ObjectList *this)

{
  element_s *peVar1;
  element_t *p;
  void *pvVar2;
  
                    /* Unresolved local var: void * retObj@[???] */
  p = this->head;
  if (p == (element_t *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
                    /* Unresolved local var: element_t * newHead@[???] */
    peVar1 = p->next;
    pvVar2 = p->object;
    if (peVar1 != (element_s *)0x0) {
      peVar1->prev = (element_s *)0x0;
      p = this->head;
    }
    if (this->tail == p) {
      this->tail = (element_t *)0x0;
    }
    Mem_Free(p);
    this->number = this->number + -1;
    this->head = peVar1;
  }
  return pvVar2;
}


// ObjectList::RemoveTail  @ 000c2e50
/* DWARF original prototype: void * RemoveTail(ObjectList * this) */

void * __thiscall ObjectList::RemoveTail(ObjectList *this)

{
  element_s *peVar1;
  element_t *p;
  void *pvVar2;
  
                    /* Unresolved local var: void * retObj@[???] */
  p = this->tail;
  if (p == (element_t *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
                    /* Unresolved local var: element_t * newTail@[???] */
    peVar1 = p->prev;
    pvVar2 = p->object;
    if (peVar1 != (element_s *)0x0) {
      peVar1->next = (element_s *)0x0;
      p = this->tail;
    }
    if (this->head == p) {
      this->head = (element_t *)0x0;
    }
    Mem_Free(p);
    this->number = this->number + -1;
    this->tail = peVar1;
  }
  return pvVar2;
}


// ObjectList::~ObjectList  @ 000c2c10
/* DWARF original prototype: void ~ObjectList(ObjectList * this, int __in_chrg) */

void __thiscall ObjectList::~ObjectList(ObjectList *this,int __in_chrg)

{
  element_t *p;
  element_s *peVar1;
  
                    /* Unresolved local var: element_t * ne@[???]
                       Unresolved local var: element_t * e@[???] */
  p = this->head;
  (this->super_IObjectContainer)._vptr_IObjectContainer =
       (_func_int_varargs **)&PTR__ObjectList_000de8b4;
  while (p != (element_t *)0x0) {
    peVar1 = p->next;
    Mem_Free(p);
    p = peVar1;
  }
  operator_delete(this);
  return;
}


// ObjectList::~ObjectList  @ 000c2c50
/* DWARF original prototype: void ~ObjectList(ObjectList * this, int __in_chrg) */

void __thiscall ObjectList::~ObjectList(ObjectList *this,int __in_chrg)

{
  element_s *peVar1;
  element_t *p;
  
  (this->super_IObjectContainer)._vptr_IObjectContainer =
       (_func_int_varargs **)&PTR__ObjectList_000de8b4;
                    /* Unresolved local var: element_t * ne@[???]
                       Unresolved local var: element_t * e@[???] */
  p = this->head;
  while (p != (element_t *)0x0) {
    peVar1 = p->next;
    Mem_Free(p);
    p = peVar1;
  }
  return;
}


// PEntityOfEntIndex  @ 00075650
edict_t * PEntityOfEntIndex(int iEntIndex)

{
  edict_t *peVar1;
  
  if ((-1 < iEntIndex) && (iEntIndex < sv.max_edicts)) {
    peVar1 = sv.edicts + iEntIndex;
                    /* Unresolved local var: edict_t * pEdict@[???] */
    if (peVar1 != (edict_t *)0x0) {
      if (peVar1->free != false) {
        return (edict_t *)0x0;
      }
      if (peVar1->pvPrivateData != (void *)0x0) {
        return peVar1;
      }
    }
    if (iEntIndex < svs.maxclients) {
      if (peVar1->free != false) {
        peVar1 = (edict_t *)0x0;
      }
      return peVar1;
    }
  }
  return (edict_t *)0x0;
}


// PEntityOfEntIndexAllEntities  @ 000756a0
edict_t * PEntityOfEntIndexAllEntities(int iEntIndex)

{
  edict_t *peVar1;
  
  if ((-1 < iEntIndex) && (iEntIndex < sv.max_edicts)) {
    peVar1 = sv.edicts + iEntIndex;
                    /* Unresolved local var: edict_t * pEdict@[???] */
    if (peVar1 != (edict_t *)0x0) {
      if (peVar1->free != false) {
        return (edict_t *)0x0;
      }
      if (peVar1->pvPrivateData != (void *)0x0) {
        return peVar1;
      }
    }
    if (iEntIndex <= svs.maxclients) {
      if (peVar1->free != false) {
        peVar1 = (edict_t *)0x0;
      }
      return peVar1;
    }
  }
  return (edict_t *)0x0;
}


// PEntityOfEntOffset  @ 000755e0
edict_t * PEntityOfEntOffset(int iEntOffset)

{
  return (edict_t *)((int)(sv.edicts)->leafnums + iEntOffset + -0x18);
}


// PVSFindEntities  @ 0006fe10
edict_t * PVSFindEntities(edict_t *pplayer)

{
  vec_t *emaxs;
  byte bVar1;
  mplane_t *p;
  model_s *pmVar2;
  mleaf_t *leaf;
  byte *pbVar3;
  int iVar4;
  mnode_t *pmVar5;
  int iVar6;
  int iVar7;
  mnode_t *pmVar8;
  int iVar9;
  edict_t *peVar10;
  uint uVar11;
  edict_t *peVar12;
  vec_t *emins;
  int local_3c;
  int local_38;
  edict_t *local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: edict_t * pchain@[???]
                       Unresolved local var: edict_t * pentPVS@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: byte * ppvs@[???]
                       Unresolved local var: mleaf_t * pleaf@[???] */
  local_28 = (pplayer->v).origin[0] + (pplayer->v).view_ofs[0];
  local_24 = (pplayer->v).origin[1] + (pplayer->v).view_ofs[1];
  local_20 = (pplayer->v).origin[2] + (pplayer->v).view_ofs[2];
  leaf = Mod_PointInLeaf(&local_28,sv.worldmodel);
  pbVar3 = Mod_LeafPVS(leaf,sv.worldmodel);
  pmVar2 = sv.worldmodel;
  iVar7 = 0;
                    /* Unresolved local var: mnode_t * node@[???]
                       Unresolved local var: int i@[???] */
  iVar6 = (sv.worldmodel)->numleafs;
  iVar4 = r_visframecount + 1;
  r_visframecount = iVar4;
  if (0 < iVar6) {
    iVar9 = 0x30;
    do {
      if (((int)(uint)pbVar3[iVar7 >> 3] >> ((byte)iVar7 & 7) & 1U) != 0) {
        iVar6 = (int)pmVar2->leafs->minmaxs + iVar9 + -8;
        do {
          if (iVar4 == *(int *)(iVar6 + 4)) break;
          *(int *)(iVar6 + 4) = iVar4;
          iVar6 = *(int *)(iVar6 + 0x14);
        } while (iVar6 != 0);
        iVar6 = pmVar2->numleafs;
      }
      iVar7 = iVar7 + 1;
      iVar9 = iVar9 + 0x30;
    } while (iVar7 < iVar6);
  }
  local_34 = sv.edicts;
  if (1 < sv.num_edicts) {
    local_38 = 0x324;
    local_3c = 1;
    iVar6 = sv.num_edicts;
    do {
      peVar10 = (edict_t *)((int)(sv.edicts)->leafnums + local_38 + -0x18);
      if (peVar10->free == false) {
        peVar12 = peVar10;
        if (((peVar10->v).movetype == 0xc) &&
           (peVar12 = (peVar10->v).aiment, peVar12 == (edict_t *)0x0)) {
          peVar12 = peVar10;
        }
        emaxs = (peVar12->v).absmax;
        emins = (peVar12->v).absmin;
        pmVar8 = (sv.worldmodel)->nodes;
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: mnode_t * splitNode@[???] */
        if (pmVar8->visframe == r_visframecount) {
          iVar4 = pmVar8->contents;
          iVar7 = pmVar8->visframe;
          iVar6 = sv.num_edicts;
          while (sv.num_edicts = iVar6, -1 < iVar4) {
            p = pmVar8->plane;
            bVar1 = p->type;
            if (bVar1 < 3) {
              if (p->dist <= emins[bVar1]) {
                uVar11 = 0;
LAB_0006ffb9:
                pmVar5 = PVSNode(pmVar8->children[0],emins,emaxs);
                if (pmVar5 == (mnode_t *)0x0) goto LAB_0006ffd4;
                goto LAB_0007004d;
              }
              uVar11 = 3;
              if (p->dist < emaxs[bVar1]) goto LAB_0006ffb9;
              pmVar8 = pmVar8->children[1];
              iVar9 = pmVar8->visframe;
              if (iVar9 != iVar7) goto LAB_0006ffed;
            }
            else {
              uVar11 = BoxOnPlaneSide(emins,emaxs,p);
              if ((uVar11 & 1) != 0) goto LAB_0006ffb9;
LAB_0006ffd4:
              iVar6 = sv.num_edicts;
              if ((uVar11 & 2) == 0) goto LAB_0006ffed;
              pmVar8 = pmVar8->children[1];
              iVar9 = pmVar8->visframe;
              if (iVar9 != r_visframecount) goto LAB_0006ffed;
            }
            iVar7 = iVar9;
            iVar6 = sv.num_edicts;
            iVar4 = pmVar8->contents;
          }
          if ((iVar4 != -2) && (pmVar8 != (mnode_t *)0x0)) {
LAB_0007004d:
            (peVar10->v).chain = local_34;
            iVar6 = sv.num_edicts;
            local_34 = peVar10;
          }
        }
      }
LAB_0006ffed:
      local_3c = local_3c + 1;
      local_38 = local_38 + 0x324;
    } while (local_3c < iVar6);
  }
  if (cl.worldmodel != (model_s *)0x0) {
    r_oldviewleaf = (mleaf_t *)0x0;
    R_MarkLeaves();
  }
  return local_34;
}


// PVSMark  @ 0006fd90
void PVSMark(model_t *pmodel,byte *ppvs)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: mnode_t * node@[???]
                       Unresolved local var: int i@[???] */
  iVar1 = r_visframecount + 1;
  iVar2 = pmodel->numleafs;
  r_visframecount = iVar1;
  if (0 < iVar2) {
    iVar3 = 0;
    iVar4 = 0x30;
    do {
      if (((int)(uint)ppvs[iVar3 >> 3] >> ((byte)iVar3 & 7) & 1U) != 0) {
        iVar2 = (int)pmodel->leafs->minmaxs + iVar4 + -8;
        do {
          if (iVar1 == *(int *)(iVar2 + 4)) break;
          *(int *)(iVar2 + 4) = iVar1;
          iVar2 = *(int *)(iVar2 + 0x14);
        } while (iVar2 != 0);
        iVar2 = pmodel->numleafs;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x30;
    } while (iVar3 < iVar2);
  }
  return;
}


// PVSNode  @ 0006f560
/* WARNING: Type propagation algorithm not settling */

mnode_t * PVSNode(mnode_t *node,vec_t *emins,vec_t *emaxs)

{
  byte bVar1;
  mplane_t *pmVar2;
  mnode_t *pmVar3;
  mnode_s *pmVar4;
  mnode_t *pmVar5;
  mnode_t *pmVar6;
  mnode_t *pmVar7;
  mnode_s *pmVar8;
  mnode_t *pmVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  mnode_s *pmVar13;
  uint uVar14;
  mnode_s *pmVar15;
  uint local_58;
  uint local_50;
  uint local_44;
  uint local_38;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: mnode_t * splitNode@[???] */
  iVar11 = node->visframe;
  if (iVar11 == r_visframecount) {
    iVar10 = node->contents;
    while (-1 < iVar10) {
      pmVar2 = node->plane;
      bVar1 = pmVar2->type;
      if (bVar1 < 3) {
        if (pmVar2->dist <= emins[bVar1]) {
          local_28 = 0;
LAB_0006f5c6:
          pmVar3 = node->children[0];
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: mnode_t * splitNode@[???] */
          iVar10 = pmVar3->visframe;
          if (iVar10 == iVar11) {
            iVar11 = pmVar3->contents;
            while (-1 < iVar11) {
              pmVar2 = pmVar3->plane;
              bVar1 = pmVar2->type;
              if (bVar1 < 3) {
                if (pmVar2->dist <= emins[bVar1]) {
                  local_24 = 0;
LAB_0006f622:
                  pmVar4 = pmVar3->children[0];
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: mnode_t * splitNode@[???] */
                  iVar11 = pmVar4->visframe;
                  if (iVar11 == iVar10) {
                    iVar10 = pmVar4->contents;
                    while (-1 < iVar10) {
                      pmVar2 = pmVar4->plane;
                      bVar1 = pmVar2->type;
                      if (bVar1 < 3) {
                        if (pmVar2->dist <= emins[bVar1]) {
                          local_20 = 0;
LAB_0006f67e:
                          pmVar5 = pmVar4->children[0];
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: mnode_t * splitNode@[???] */
                          iVar10 = pmVar5->visframe;
                          if (iVar10 == iVar11) {
                            iVar11 = pmVar5->contents;
                            while (-1 < iVar11) {
                              pmVar2 = pmVar5->plane;
                              bVar1 = pmVar2->type;
                              if (bVar1 < 3) {
                                if (pmVar2->dist <= emins[bVar1]) {
                                  local_2c = 0;
LAB_0006f6da:
                                  pmVar6 = pmVar5->children[0];
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: mnode_t * splitNode@[???] */
                                  iVar11 = pmVar6->visframe;
                                  if (iVar11 == iVar10) {
                                    iVar10 = pmVar6->contents;
                                    while (-1 < iVar10) {
                                      pmVar2 = pmVar6->plane;
                                      bVar1 = pmVar2->type;
                                      if (bVar1 < 3) {
                                        if (pmVar2->dist <= emins[bVar1]) {
                                          local_38 = 0;
LAB_0006f736:
                                          pmVar7 = pmVar6->children[0];
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: mnode_t * splitNode@[???] */
                                          iVar10 = pmVar7->visframe;
                                          if (iVar10 == iVar11) {
                                            iVar11 = pmVar7->contents;
                                            while (-1 < iVar11) {
                                              pmVar2 = pmVar7->plane;
                                              bVar1 = pmVar2->type;
                                              if (bVar1 < 3) {
                                                if (pmVar2->dist <= emins[bVar1]) {
                                                  local_44 = 0;
LAB_0006f79c:
                                                  pmVar8 = pmVar7->children[0];
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: mnode_t * splitNode@[???] */
                                                  if (pmVar8->visframe == iVar10) {
                                                    iVar11 = pmVar8->contents;
                                                    iVar10 = pmVar8->visframe;
                                                    while (-1 < iVar11) {
                                                      pmVar2 = pmVar8->plane;
                                                      bVar1 = pmVar2->type;
                                                      if (bVar1 < 3) {
                                                        if (pmVar2->dist <= emins[bVar1]) {
                                                          local_50 = 0;
LAB_0006f7fc:
                                                          pmVar13 = pmVar8->children[0];
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: mnode_t * splitNode@[???] */
                                                          iVar11 = pmVar13->visframe;
                                                          if (iVar11 == iVar10) {
                                                            do {
                                                              if (pmVar13->contents < 0) {
                                                                if ((pmVar13->contents != -2) &&
                                                                   (pmVar13 != (mnode_s *)0x0)) {
                                                                  return pmVar13;
                                                                }
                                                                break;
                                                              }
                                                              pmVar2 = pmVar13->plane;
                                                              bVar1 = pmVar2->type;
                                                              if (bVar1 < 3) {
                                                                if (pmVar2->dist <= emins[bVar1]) {
                                                                  local_58 = 0;
LAB_0006f852:
                                                                  pmVar15 = pmVar13->children[0];
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: mnode_t * splitNode@[???] */
                                                                  if (pmVar15->visframe == iVar11) {
                                                                    iVar11 = pmVar15->contents;
                                                                    iVar10 = pmVar15->visframe;
                                                                    while (-1 < iVar11) {
                                                                      pmVar2 = pmVar15->plane;
                                                                      bVar1 = pmVar2->type;
                                                                      if (bVar1 < 3) {
                                                                        if (pmVar2->dist <=
                                                                            emins[bVar1]) {
                                                                          uVar14 = 0;
LAB_0006f8ce:
                                                                          pmVar9 = PVSNode(pmVar15->
                                                  children[0],emins,emaxs);
                                                  if (pmVar9 != (mnode_t *)0x0) {
                                                    return pmVar9;
                                                  }
                                                  goto LAB_0006f8e9;
                                                  }
                                                  uVar14 = 3;
                                                  if (pmVar2->dist < emaxs[bVar1])
                                                  goto LAB_0006f8ce;
                                                  pmVar15 = pmVar15->children[1];
                                                  iVar12 = pmVar15->visframe;
                                                  if (iVar12 != iVar10) goto LAB_0006f901;
                                                  }
                                                  else {
                                                    uVar14 = BoxOnPlaneSide(emins,emaxs,pmVar2);
                                                    if ((uVar14 & 1) != 0) goto LAB_0006f8ce;
LAB_0006f8e9:
                                                    if ((uVar14 & 2) == 0) goto LAB_0006f901;
                                                    pmVar15 = pmVar15->children[1];
                                                    iVar12 = pmVar15->visframe;
                                                    if (iVar12 != r_visframecount)
                                                    goto LAB_0006f901;
                                                  }
                                                  iVar10 = iVar12;
                                                  iVar11 = pmVar15->contents;
                                                  }
                                                  if ((iVar11 != -2) && (pmVar15 != (mnode_s *)0x0))
                                                  {
                                                    return pmVar15;
                                                  }
                                                  }
                                                  goto LAB_0006f901;
                                                  }
                                                  iVar10 = iVar11;
                                                  if (pmVar2->dist < emaxs[bVar1]) {
                                                    local_58 = 3;
                                                    goto LAB_0006f852;
                                                  }
                                                  }
                                                  else {
                                                    local_58 = BoxOnPlaneSide(emins,emaxs,pmVar2);
                                                    iVar11 = r_visframecount;
                                                    if ((local_58 & 1) != 0) goto LAB_0006f852;
LAB_0006f901:
                                                    iVar10 = r_visframecount;
                                                    if ((local_58 & 2) == 0) break;
                                                  }
                                                  pmVar13 = pmVar13->children[1];
                                                  iVar11 = pmVar13->visframe;
                                                  } while (iVar11 == iVar10);
                                                  }
                                                  goto LAB_0006f920;
                                                  }
                                                  if (pmVar2->dist < emaxs[bVar1]) {
                                                    local_50 = 3;
                                                    goto LAB_0006f7fc;
                                                  }
                                                  }
                                                  else {
                                                    local_50 = BoxOnPlaneSide(emins,emaxs,pmVar2);
                                                    iVar10 = r_visframecount;
                                                    if ((local_50 & 1) != 0) goto LAB_0006f7fc;
LAB_0006f920:
                                                    iVar10 = r_visframecount;
                                                    if ((local_50 & 2) == 0) goto LAB_0006f960;
                                                  }
                                                  pmVar8 = pmVar8->children[1];
                                                  if (pmVar8->visframe != iVar10) goto LAB_0006f960;
                                                  iVar10 = pmVar8->visframe;
                                                  iVar11 = pmVar8->contents;
                                                  }
                                                  if ((iVar11 != -2) && (pmVar8 != (mnode_s *)0x0))
                                                  {
                                                    return pmVar8;
                                                  }
                                                  }
                                                  goto LAB_0006f960;
                                                }
                                                iVar11 = iVar10;
                                                if (pmVar2->dist < emaxs[bVar1]) {
                                                  local_44 = 3;
                                                  goto LAB_0006f79c;
                                                }
                                              }
                                              else {
                                                local_44 = BoxOnPlaneSide(emins,emaxs,pmVar2);
                                                iVar10 = r_visframecount;
                                                if ((local_44 & 1) != 0) goto LAB_0006f79c;
LAB_0006f960:
                                                iVar11 = r_visframecount;
                                                if ((local_44 & 2) == 0) goto LAB_0006f99b;
                                              }
                                              pmVar7 = pmVar7->children[1];
                                              iVar10 = pmVar7->visframe;
                                              if (iVar10 != iVar11) goto LAB_0006f99b;
                                              iVar11 = pmVar7->contents;
                                            }
                                            if ((iVar11 != -2) && (pmVar7 != (mnode_t *)0x0)) {
                                              return pmVar7;
                                            }
                                          }
                                          goto LAB_0006f99b;
                                        }
                                        iVar10 = iVar11;
                                        if (pmVar2->dist < emaxs[bVar1]) {
                                          local_38 = 3;
                                          goto LAB_0006f736;
                                        }
                                      }
                                      else {
                                        local_38 = BoxOnPlaneSide(emins,emaxs,pmVar2);
                                        iVar11 = r_visframecount;
                                        if ((local_38 & 1) != 0) goto LAB_0006f736;
LAB_0006f99b:
                                        iVar10 = r_visframecount;
                                        if ((local_38 & 2) == 0) goto LAB_0006f9d8;
                                      }
                                      pmVar6 = pmVar6->children[1];
                                      iVar11 = pmVar6->visframe;
                                      if (iVar11 != iVar10) goto LAB_0006f9d8;
                                      iVar10 = pmVar6->contents;
                                    }
                                    if ((iVar10 != -2) && (pmVar6 != (mnode_t *)0x0)) {
                                      return pmVar6;
                                    }
                                  }
                                  goto LAB_0006f9d8;
                                }
                                iVar11 = iVar10;
                                if (pmVar2->dist < emaxs[bVar1]) {
                                  local_2c = 3;
                                  goto LAB_0006f6da;
                                }
                              }
                              else {
                                local_2c = BoxOnPlaneSide(emins,emaxs,pmVar2);
                                iVar10 = r_visframecount;
                                if ((local_2c & 1) != 0) goto LAB_0006f6da;
LAB_0006f9d8:
                                iVar11 = r_visframecount;
                                if ((local_2c & 2) == 0) goto LAB_0006fa13;
                              }
                              pmVar5 = pmVar5->children[1];
                              iVar10 = pmVar5->visframe;
                              if (iVar10 != iVar11) goto LAB_0006fa13;
                              iVar11 = pmVar5->contents;
                            }
                            if ((iVar11 != -2) && (pmVar5 != (mnode_t *)0x0)) {
                              return pmVar5;
                            }
                          }
                          goto LAB_0006fa13;
                        }
                        iVar10 = iVar11;
                        if (pmVar2->dist < emaxs[bVar1]) {
                          local_20 = 3;
                          goto LAB_0006f67e;
                        }
                      }
                      else {
                        local_20 = BoxOnPlaneSide(emins,emaxs,pmVar2);
                        iVar11 = r_visframecount;
                        if ((local_20 & 1) != 0) goto LAB_0006f67e;
LAB_0006fa13:
                        iVar10 = r_visframecount;
                        if ((local_20 & 2) == 0) goto LAB_0006fa4e;
                      }
                      pmVar4 = pmVar4->children[1];
                      iVar11 = pmVar4->visframe;
                      if (iVar11 != iVar10) goto LAB_0006fa4e;
                      iVar10 = pmVar4->contents;
                    }
                    if ((iVar10 != -2) && (pmVar4 != (mnode_s *)0x0)) {
                      return pmVar4;
                    }
                  }
                  goto LAB_0006fa4e;
                }
                iVar11 = iVar10;
                if (pmVar2->dist < emaxs[bVar1]) {
                  local_24 = 3;
                  goto LAB_0006f622;
                }
              }
              else {
                local_24 = BoxOnPlaneSide(emins,emaxs,pmVar2);
                iVar10 = r_visframecount;
                if ((local_24 & 1) != 0) goto LAB_0006f622;
LAB_0006fa4e:
                iVar11 = r_visframecount;
                if ((local_24 & 2) == 0) goto LAB_0006fd2d;
              }
              pmVar3 = pmVar3->children[1];
              iVar10 = pmVar3->visframe;
              if (iVar10 != iVar11) goto LAB_0006fd2d;
              iVar11 = pmVar3->contents;
            }
            if ((iVar11 != -2) && (pmVar3 != (mnode_t *)0x0)) {
              return pmVar3;
            }
          }
          goto LAB_0006fd2d;
        }
        iVar10 = iVar11;
        if (pmVar2->dist < emaxs[bVar1]) {
          local_28 = 3;
          goto LAB_0006f5c6;
        }
      }
      else {
        local_28 = BoxOnPlaneSide(emins,emaxs,pmVar2);
        iVar11 = r_visframecount;
        if ((local_28 & 1) != 0) goto LAB_0006f5c6;
LAB_0006fd2d:
        iVar10 = r_visframecount;
        if ((local_28 & 2) == 0) {
          return (mnode_t *)0x0;
        }
      }
      node = node->children[1];
      iVar11 = node->visframe;
      if (iVar11 != iVar10) {
        return (mnode_t *)0x0;
      }
      iVar10 = node->contents;
    }
    if (iVar10 != -2) {
      return node;
    }
  }
  return (mnode_t *)0x0;
}


// ParseDirective  @ 000a5be0
int ParseDirective(char *pText)

{
  char *s1;
  int iVar1;
  float local_2c;
  float local_28;
  float local_24;
  
  if ((pText != (char *)0x0) && (*pText == '$')) {
                    /* Unresolved local var: float[8] tempFloat@[???] */
    s1 = pText + 1;
    iVar1 = Q_strlen("position");
    iVar1 = Q_strnicmp(s1,"position",iVar1);
    if (iVar1 == 0) {
      iVar1 = ParseFloats(pText,&local_2c,2);
      if (iVar1 != 0) {
        gMessageParms.x = local_2c;
        gMessageParms.y = local_28;
      }
    }
    else {
      iVar1 = Q_strlen("effect");
      iVar1 = Q_strnicmp(s1,"effect",iVar1);
      if (iVar1 == 0) {
        iVar1 = ParseFloats(pText,&local_2c,1);
        if (iVar1 != 0) {
          gMessageParms.effect = (int)local_2c;
        }
      }
      else {
        iVar1 = Q_strlen("fxtime");
        iVar1 = Q_strnicmp(s1,"fxtime",iVar1);
        if (iVar1 == 0) {
          iVar1 = ParseFloats(pText,&local_2c,1);
          if (iVar1 != 0) {
            gMessageParms.fxtime = local_2c;
          }
        }
        else {
          iVar1 = Q_strlen("color2");
          iVar1 = Q_strnicmp(s1,"color2",iVar1);
          if (iVar1 == 0) {
            iVar1 = ParseFloats(pText,&local_2c,3);
            if (iVar1 != 0) {
              gMessageParms.r2 = (byte)(int)local_2c;
              gMessageParms.g2 = (byte)(int)local_28;
              gMessageParms.b2 = (byte)(int)local_24;
            }
          }
          else {
            iVar1 = Q_strlen("color");
            iVar1 = Q_strnicmp(s1,"color",iVar1);
            if (iVar1 == 0) {
              iVar1 = ParseFloats(pText,&local_2c,3);
              if (iVar1 != 0) {
                gMessageParms.r1 = (byte)(int)local_2c;
                gMessageParms.g1 = (byte)(int)local_28;
                gMessageParms.b1 = (byte)(int)local_24;
              }
            }
            else {
              iVar1 = Q_strlen("fadein");
              iVar1 = Q_strnicmp(s1,"fadein",iVar1);
              if (iVar1 == 0) {
                iVar1 = ParseFloats(pText,&local_2c,1);
                if (iVar1 != 0) {
                  gMessageParms.fadein = local_2c;
                }
              }
              else {
                iVar1 = Q_strlen("fadeout");
                iVar1 = Q_strnicmp(s1,"fadeout",iVar1);
                if (iVar1 == 0) {
                  iVar1 = ParseFloats(pText,&local_2c,3);
                  if (iVar1 != 0) {
                    gMessageParms.fadeout = local_2c;
                  }
                }
                else {
                  iVar1 = Q_strlen("holdtime");
                  iVar1 = Q_strnicmp(s1,"holdtime",iVar1);
                  if (iVar1 == 0) {
                    iVar1 = ParseFloats(pText,&local_2c,3);
                    if (iVar1 != 0) {
                      gMessageParms.holdtime = local_2c;
                    }
                  }
                  else {
                    Con_DPrintf("Unknown token: %s\n",pText);
                  }
                }
              }
            }
          }
        }
      }
    }
    return 1;
  }
  return 0;
}


// ParseFloats  @ 000a51c0
int ParseFloats(char *pText,float *pFloat,int count)

{
  float *pfVar1;
  char cVar2;
  char *pcVar3;
  float fVar4;
  int local_20;
  
                    /* Unresolved local var: char * pTemp@[???]
                       Unresolved local var: int index@[???] */
                    /* Unresolved local var: int pos@[???] */
  local_20 = 0;
joined_r0x000a51de:
  if ((pText == (char *)0x0) || (count < 1)) {
    return (uint)(count == 0);
  }
  cVar2 = *pText;
  if (cVar2 != '\0') {
    if ((0x17 < (byte)(cVar2 - 9U)) || (((byte)(0x800013 >> (cVar2 - 9U & 0x1f)) & 1) != 1))
    goto LAB_000a5210;
    goto LAB_000a52ab;
  }
  goto LAB_000a5234;
LAB_000a5210:
  do {
    pText = pText + 1;
    cVar2 = *pText;
    while( true ) {
      if (cVar2 == '\0') goto LAB_000a5230;
      if ((byte)(cVar2 - 9U) < 0x18) break;
      pText = pText + 1;
      cVar2 = *pText;
    }
  } while (((byte)(0x800013 >> (cVar2 - 9U & 0x1f)) & 1) != 1);
  if (pText != (char *)0x0) {
LAB_000a52ab:
    do {
      pcVar3 = pText + 1;
                    /* Unresolved local var: int pos@[???] */
      if ((0x17 < (byte)(cVar2 - 9U)) || (((byte)(0x800013 >> (cVar2 - 9U & 0x1f)) & 1) != 1))
      break;
      cVar2 = *pcVar3;
      pText = pcVar3;
    } while (cVar2 != '\0');
LAB_000a5230:
    if (pText != (char *)0x0) {
LAB_000a5234:
      count = count + -1;
      pfVar1 = pFloat + local_20;
      fVar4 = Q_atof(pText);
      local_20 = local_20 + 1;
      *pfVar1 = fVar4;
    }
  }
  goto joined_r0x000a51de;
}


// ParseSaveTables  @ 0005a0c0
void ParseSaveTables(SAVERESTOREDATA *pSaveData,SAVE_HEADER *pHeader,int updateGlobals)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  LEVELLIST *pLVar7;
  int iVar8;
  int in_GS_OFFSET;
  int local_64;
  char local_60 [64];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: SAVELIGHTSTYLE light@[???] */
  iVar6 = 0;
  iVar8 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (0 < pSaveData->tableCount) {
    do {
      iVar6 = iVar6 + 1;
      (*gEntityInterface.pfnSaveReadFields)
                (pSaveData,"ETABLE",(void *)((int)&pSaveData->pTable->id + iVar8),
                 gEntityTableDescription,5);
      *(undefined4 *)((int)&pSaveData->pTable->pent + iVar8) = 0;
      iVar8 = iVar8 + 0x18;
    } while (iVar6 < pSaveData->tableCount);
  }
  pSaveData->size = 0;
  pSaveData->pBaseData = pSaveData->pCurrentData;
  (*gEntityInterface.pfnSaveReadFields)(pSaveData,"Save Header",pHeader,gSaveHeaderDescription,0xd);
  iVar6 = pHeader->connectionCount;
  pSaveData->connectionCount = iVar6;
  fVar1 = pHeader->time;
  pSaveData->fUseLandmark = 1;
  pSaveData->vecLandmarkOffset[0] = 0.0;
  pSaveData->time = fVar1;
  pSaveData->vecLandmarkOffset[1] = 0.0;
  pSaveData->vecLandmarkOffset[2] = 0.0;
  if (0 < iVar6) {
    iVar6 = 0;
    pLVar7 = pSaveData->levelList;
    do {
      iVar6 = iVar6 + 1;
      (*gEntityInterface.pfnSaveReadFields)(pSaveData,"ADJACENCY",pLVar7,gAdjacencyDescription,4);
      pLVar7 = pLVar7 + 1;
    } while (iVar6 < pSaveData->connectionCount);
  }
  if (updateGlobals == 0) {
    if (0 < pHeader->lightStyleCount) {
      iVar6 = 0;
      do {
        iVar6 = iVar6 + 1;
        (*gEntityInterface.pfnSaveReadFields)
                  (pSaveData,"LIGHTSTYLE",&local_64,gLightstyleDescription,2);
      } while (iVar6 < pHeader->lightStyleCount);
    }
  }
  else {
    uVar2 = 0;
    do {
      *(undefined4 *)((int)sv.lightstyles + uVar2) = 0;
      uVar3 = uVar2 + 8;
      *(undefined4 *)((int)sv.lightstyles + uVar2 + 4) = 0;
      uVar2 = uVar3;
    } while (uVar3 < 0x100);
    if (0 < pHeader->lightStyleCount) {
      iVar6 = 0;
      do {
        (*gEntityInterface.pfnSaveReadFields)
                  (pSaveData,"LIGHTSTYLE",&local_64,gLightstyleDescription,2);
        iVar8 = local_64;
        iVar4 = Q_strlen(local_60);
        pcVar5 = Hunk_Alloc(iVar4 + 1);
        sv.lightstyles[iVar8] = pcVar5;
        Q_strncpy(sv.lightstyles[local_64],local_60,3);
        iVar6 = iVar6 + 1;
        sv.lightstyles[local_64][3] = '\0';
      } while (iVar6 < pHeader->lightStyleCount);
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// PollDInputDevices  @ 00045570
void PollDInputDevices(void)

{
  return;
}


// ProcessTutorMessageDecayBuffer  @ 000455e0
void ProcessTutorMessageDecayBuffer(int *buffer,int bufferLength)

{
  return;
}


// PvAllocEntPrivateData  @ 000754b0
void * PvAllocEntPrivateData(edict_t *pEdict,int32 cb)

{
  void *pvVar1;
  
  pvVar1 = pEdict->pvPrivateData;
  if (pvVar1 != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(pEdict);
      pvVar1 = pEdict->pvPrivateData;
    }
    Mem_Free(pvVar1);
  }
  pEdict->pvPrivateData = (void *)0x0;
  if (cb < 1) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = Mem_Calloc(1,cb);
    pEdict->pvPrivateData = pvVar1;
  }
  return pvVar1;
}


// PvEntPrivateData  @ 00075510
void * PvEntPrivateData(edict_t *pEdict)

{
  if (pEdict != (edict_t *)0x0) {
    return pEdict->pvPrivateData;
  }
  return (void *)0x0;
}


// QuaternionMatrix  @ 000760f0
void QuaternionMatrix(vec_t *quaternion,float (*matrix) [4])

{
  float fVar1;
  float fVar2;
  
  fVar1 = quaternion[1];
  fVar2 = quaternion[2];
  (*matrix)[0] = (1.0 - (fVar1 + fVar1) * fVar1) - (fVar2 + fVar2) * fVar2;
  matrix[1][0] = (quaternion[3] + quaternion[3]) * quaternion[2] +
                 (*quaternion + *quaternion) * quaternion[1];
  matrix[2][0] = (*quaternion + *quaternion) * quaternion[2] -
                 (quaternion[3] + quaternion[3]) * quaternion[1];
  (*matrix)[1] = (*quaternion + *quaternion) * quaternion[1] -
                 (quaternion[3] + quaternion[3]) * quaternion[2];
  fVar1 = *quaternion;
  fVar2 = quaternion[2];
  matrix[1][1] = (1.0 - (fVar1 + fVar1) * fVar1) - (fVar2 + fVar2) * fVar2;
  matrix[2][1] = (quaternion[3] + quaternion[3]) * *quaternion +
                 (quaternion[1] + quaternion[1]) * quaternion[2];
  (*matrix)[2] = (quaternion[3] + quaternion[3]) * quaternion[1] +
                 (*quaternion + *quaternion) * quaternion[2];
  matrix[1][2] = (quaternion[1] + quaternion[1]) * quaternion[2] -
                 (quaternion[3] + quaternion[3]) * *quaternion;
  fVar1 = *quaternion;
  fVar2 = quaternion[1];
  matrix[2][2] = (1.0 - (fVar1 + fVar1) * fVar1) - (fVar2 + fVar2) * fVar2;
  return;
}


// QuaternionSlerp  @ 00075e20
void QuaternionSlerp(vec_t *p,vec_t *q,float t,vec_t *qt)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  double dVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: float b@[???] */
  fVar1 = *p;
  fVar2 = q[1];
  fVar3 = p[2];
  fVar4 = p[3];
  if ((q[3] + fVar4) * (q[3] + fVar4) +
      (q[2] + fVar3) * (q[2] + fVar3) +
      (p[1] + fVar2) * (p[1] + fVar2) + (*q + fVar1) * (*q + fVar1) + 0.0 <
      (fVar4 - q[3]) * (fVar4 - q[3]) +
      (fVar3 - q[2]) * (fVar3 - q[2]) +
      (p[1] - fVar2) * (p[1] - fVar2) + (fVar1 - *q) * (fVar1 - *q) + 0.0) {
    *q = -(vec_t)*(undefined8 *)q;
    q[1] = -q[1];
    q[2] = -q[2];
    q[3] = -q[3];
    fVar1 = *p;
    fVar2 = q[1];
    fVar3 = p[2];
    fVar4 = p[3];
  }
  cosom = fVar4 * q[3] + fVar3 * q[2] + p[1] * fVar2 + fVar1 * *q;
  if (cosom + 1.0 <= 1e-06) {
    *qt = -fVar2;
    fVar1 = *q;
    qt[1] = fVar1;
    qt[2] = -q[3];
    qt[3] = q[2];
    dVar6 = sin((double)((1.0 - t) * 1.5707964));
    sclp = (float)dVar6;
    dVar5 = sin((double)t * 1.5707963267948966);
    sclq = (float)dVar5;
    *qt = (float)dVar6 * *p + sclq * *qt;
    qt[1] = p[1] * sclp + fVar1 * sclq;
    qt[2] = sclq * qt[2] + sclp * p[2];
    return;
  }
  if (1e-06 < 1.0 - cosom) {
    dVar6 = acos((double)cosom);
    fVar2 = (float)dVar6;
    omega = fVar2;
    dVar6 = sin((double)fVar2);
    fVar3 = (float)dVar6;
    sinom = fVar3;
    dVar6 = sin((1.0 - (double)t) * (double)fVar2);
    fVar1 = (float)dVar6 / fVar3;
    sclp = fVar1;
    dVar6 = sin((double)(fVar2 * t));
    t = (float)dVar6 / fVar3;
  }
  else {
    fVar1 = 1.0 - t;
    sclp = fVar1;
  }
  sclq = t;
  *qt = t * *q + fVar1 * *p;
  qt[1] = p[1] * sclp + q[1] * sclq;
  qt[2] = p[2] * sclp + q[2] * sclq;
  qt[3] = q[3] * sclq + sclp * p[3];
  return;
}


// QueryClientCvarValue  @ 000745c0
void QueryClientCvarValue(edict_t *player,char *cvarName)

{
  sizebuf_t *sb;
  int iVar1;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
  iVar1 = NUM_FOR_EDICT(player);
  if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
    sb = &svs.clients[iVar1 + -1].netchan.message;
    MSG_WriteChar(sb,0x39);
    MSG_WriteString(sb,cvarName);
    return;
  }
  if (gNewDLLFunctions.pfnCvarValue != (_func_void_edict_t_ptr_char_ptr *)0x0) {
    (*gNewDLLFunctions.pfnCvarValue)(player,"Bad Player");
  }
  Con_Printf("tried to QueryClientCvarValue a non-client\n");
  return;
}


// QueryClientCvarValue2  @ 00074660
void QueryClientCvarValue2(edict_t *player,char *cvarName,int requestID)

{
  sizebuf_t *sb;
  int iVar1;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
  iVar1 = NUM_FOR_EDICT(player);
  if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
    sb = &svs.clients[iVar1 + -1].netchan.message;
    MSG_WriteChar(sb,0x3a);
    MSG_WriteLong(sb,requestID);
    MSG_WriteString(sb,cvarName);
    return;
  }
  if (gNewDLLFunctions.pfnCvarValue2 != (_func_void_edict_t_ptr_int_char_ptr_char_ptr *)0x0) {
    (*gNewDLLFunctions.pfnCvarValue2)(player,requestID,cvarName,"Bad Player");
  }
  Con_Printf("tried to QueryClientCvarValue a non-client\n");
  return;
}


// QueryClientCvarValueCmd  @ 00074300
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QueryClientCvarValueCmd(void)

{
  sizebuf_t *sb;
  edict_t *e;
  int iVar1;
  char *pcVar2;
  int iVar3;
  client_s *pcVar4;
  int iVar5;
  
  iVar1 = Cmd_Argc();
  if (iVar1 < 2) {
    pcVar2 = Cmd_Argv(0);
    Con_Printf("%s <player name> <cvar>\n",pcVar2);
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclients) {
    iVar5 = 0;
    iVar1 = svs.maxclients;
    pcVar4 = svs.clients;
    do {
      if ((pcVar4->active != false) || (pcVar4->connected != false)) {
        pcVar2 = Cmd_Argv(1);
        iVar3 = Q_strcasecmp(pcVar4->name,pcVar2);
        iVar1 = svs.maxclients;
        if (iVar3 == 0) {
          if (svs.maxclients <= iVar5) {
            return;
          }
          pcVar2 = Cmd_Argv(2);
          e = pcVar4->edict;
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
          iVar1 = NUM_FOR_EDICT(e);
          if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
            sb = &svs.clients[iVar1 + -1].netchan.message;
            MSG_WriteChar(sb,0x39);
            MSG_WriteString(sb,pcVar2);
            return;
          }
          if (gNewDLLFunctions.pfnCvarValue != (_func_void_edict_t_ptr_char_ptr *)0x0) {
            (*gNewDLLFunctions.pfnCvarValue)(e,"Bad Player");
          }
          Con_Printf("tried to QueryClientCvarValue a non-client\n");
          return;
        }
      }
      iVar5 = iVar5 + 1;
      pcVar4 = pcVar4 + 1;
    } while (iVar5 < iVar1);
  }
  return;
}


// QueryClientCvarValueCmd2  @ 00074430
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QueryClientCvarValueCmd2(void)

{
  sizebuf_t *sb;
  edict_t *e;
  int iVar1;
  char *pcVar2;
  int iVar3;
  long c;
  client_s *pcVar4;
  int iVar5;
  
  iVar1 = Cmd_Argc();
  if (iVar1 < 3) {
    pcVar2 = Cmd_Argv(0);
    Con_Printf("%s <player name> <cvar> <requestID>\n",pcVar2);
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int requestID@[???] */
  pcVar2 = Cmd_Argv(3);
  strtol(pcVar2,(char **)0x0,10);
  if (0 < svs.maxclients) {
    iVar5 = 0;
    iVar1 = svs.maxclients;
    pcVar4 = svs.clients;
    do {
      if ((pcVar4->active != false) || (pcVar4->connected != false)) {
        pcVar2 = Cmd_Argv(1);
        iVar3 = Q_strcasecmp(pcVar4->name,pcVar2);
        iVar1 = svs.maxclients;
        if (iVar3 == 0) {
          if (svs.maxclients <= iVar5) {
            return;
          }
          pcVar2 = Cmd_Argv(3);
          c = strtol(pcVar2,(char **)0x0,10);
          pcVar2 = Cmd_Argv(2);
          e = pcVar4->edict;
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
          iVar1 = NUM_FOR_EDICT(e);
          if ((0 < iVar1) && (iVar1 <= svs.maxclients)) {
            sb = &svs.clients[iVar1 + -1].netchan.message;
            MSG_WriteChar(sb,0x3a);
            MSG_WriteLong(sb,c);
            MSG_WriteString(sb,pcVar2);
            return;
          }
          if (gNewDLLFunctions.pfnCvarValue2 != (_func_void_edict_t_ptr_int_char_ptr_char_ptr *)0x0)
          {
            (*gNewDLLFunctions.pfnCvarValue2)(e,c,pcVar2,"Bad Player");
          }
          Con_Printf("tried to QueryClientCvarValue a non-client\n");
          return;
        }
      }
      iVar5 = iVar5 + 1;
      pcVar4 = pcVar4 + 1;
    } while (iVar5 < iVar1);
  }
  return;
}


// RadiusFromBounds  @ 00064420
float RadiusFromBounds(vec_t *mins,vec_t *maxs)

{
  float fVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t corner@[???] */
  local_18 = ABS(*mins);
  if (ABS(*mins) <= ABS(*maxs)) {
    local_18 = ABS(*maxs);
  }
  local_14 = ABS(mins[1]);
  if (ABS(mins[1]) <= ABS(maxs[1])) {
    local_14 = ABS(maxs[1]);
  }
  local_10 = ABS(mins[2]);
  if (ABS(mins[2]) <= ABS(maxs[2])) {
    local_10 = ABS(maxs[2]);
  }
  fVar1 = Length(&local_18);
  return fVar1;
}


// RandomFloat  @ 00073860
float RandomFloat(float flLow,float flHigh)

{
  float fVar1;
  int32 iVar2;
  
                    /* Unresolved local var: float fl@[???] */
  (*g_engdstAddrs.pfnRandomFloat)(&flLow,&flHigh);
                    /* Unresolved local var: float temp@[???] */
  iVar2 = ran1();
  fVar1 = 0.9999999;
  if ((float)iVar2 * 4.656613e-10 <= 0.9999999) {
    fVar1 = (float)iVar2 * 4.656613e-10;
  }
  return (flHigh - flLow) * fVar1 + flLow;
}


// RandomLong  @ 000738c0
int32 RandomLong(int32 lLow,int32 lHigh)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: uint32 maxAcceptable@[???]
                       Unresolved local var: uint32 x@[???]
                       Unresolved local var: uint32 n@[???] */
  (*g_engdstAddrs.pfnRandomLong)(&lLow,&lHigh);
  if (-1 < lHigh - lLow) {
    uVar1 = (lHigh - lLow) + 1;
    do {
      uVar2 = ran1();
    } while (0x7fffffffU - (int)(0x80000000 % (ulonglong)uVar1) < uVar2);
    lLow = lLow + uVar2 % uVar1;
  }
  return lLow;
}


// RegUserMsg  @ 0008fd80
int RegUserMsg(char *pszName,int iSize)

{
  UserMsg *pUVar1;
  int iVar2;
  UserMsg *pUVar3;
  
                    /* Unresolved local var: UserMsg * pUserMsgs@[???]
                       Unresolved local var: UserMsg * pNewMsg@[???]
                       Unresolved local var: int iFound@[???]
                       Unresolved local var: int iRet@[???] */
  if (0xff < giNextUserMsg) {
    Con_Printf("Not enough room to register message %s\n",pszName);
    return 0;
  }
  if (pszName != (char *)0x0) {
    iVar2 = Q_strlen(pszName);
    if (iVar2 < 0xc) {
      pUVar3 = sv_gpUserMsgs;
      if (iSize < 0xc1) {
        for (; pUVar3 != (UserMsg *)0x0; pUVar3 = pUVar3->next) {
          iVar2 = Q_strcmp(pszName,pUVar3->szName);
          if (iVar2 == 0) {
            return pUVar3->iMsg;
          }
        }
        pUVar3 = Mem_ZeroMalloc(0x20);
        pUVar3->iMsg = giNextUserMsg;
        giNextUserMsg = giNextUserMsg + 1;
        pUVar3->iSize = iSize;
        Q_strcpy(pUVar3->szName,pszName);
        if (pUVar3 != (UserMsg *)0x0) {
          pUVar1 = pUVar3;
          pUVar3->next = sv_gpNewUserMsgs;
          sv_gpNewUserMsgs = pUVar1;
          return pUVar3->iMsg;
        }
      }
    }
    else {
      Con_Printf("Message name too long: %s\n",pszName);
    }
  }
  return 0;
}


// RegisterTutorMessageShown  @ 00045600
void RegisterTutorMessageShown(void)

{
  return;
}


// ReleaseEntityDLLFields  @ 00075460
void ReleaseEntityDLLFields(edict_t *pEdict)

{
  void *p;
  
  p = pEdict->pvPrivateData;
  if (p != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(pEdict);
      p = pEdict->pvPrivateData;
    }
    Mem_Free(p);
  }
  pEdict->pvPrivateData = (void *)0x0;
  return;
}


// ReleaseEntityDlls  @ 0007a750
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ReleaseEntityDlls(void)

{
  int iVar1;
  extensiondll_t *peVar2;
  
                    /* Unresolved local var: extensiondll_t * pextdll@[???]
                       Unresolved local var: extensiondll_t * pextdllMac@[???] */
  iVar1 = g_iextdllMac;
  if (svs.dll_initialized == false) {
    return;
  }
  FreeAllEntPrivateData();
  if (gNewDLLFunctions.pfnGameShutdown != (_func_void *)0x0) {
    (*gNewDLLFunctions.pfnGameShutdown)();
  }
  Cvar_UnlinkExternals();
  for (peVar2 = g_rgextdll; peVar2 < g_rgextdll + iVar1; peVar2 = peVar2 + 1) {
    dlclose(peVar2->lDLLHandle);
    peVar2->lDLLHandle = (void *)0x0;
    if (peVar2->functionTable != (functiontable_t *)0x0) {
      Mem_Free(peVar2->functionTable);
    }
    peVar2->functionTable = (functiontable_t *)0x0;
  }
  svs.dll_initialized = false;
  return;
}


// RemoveLink  @ 000a81e0
void RemoveLink(link_t *l)

{
  l->next->prev = l->prev;
  l->prev->next = l->next;
  return;
}


// ReplyServerChallenge  @ 00086e90
void ReplyServerChallenge(netadr_t *adr)

{
  int c;
  int in_GS_OFFSET;
  sizebuf_t local_34;
  byte local_20 [16];
  int local_10;
  
                    /* Unresolved local var: char[16] buffer@[???]
                       Unresolved local var: sizebuf_t buf@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_34.buffername = "SVC_Challenge";
  local_34.data = local_20;
  local_34.maxsize = 0x10;
  local_34.cursize = 0;
  local_34.flags = 1;
  MSG_WriteLong(&local_34,-1);
  MSG_WriteByte(&local_34,0x41);
  c = GetChallengeNr(adr);
  MSG_WriteLong(&local_34,c);
  NET_SendPacket(NS_SERVER,local_34.cursize,local_34.data,*adr);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// RequireValidChallenge  @ 00086bd0
qboolean RequireValidChallenge(netadr_t *adr)

{
  qboolean qVar1;
  
  qVar1 = (qboolean)!NAN(sv_enableoldqueries.value);
  if (sv_enableoldqueries.value != 0.0) {
    qVar1 = false;
  }
  return qVar1;
}


// ResetTutorMessageDecayData  @ 00045610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ResetTutorMessageDecayData(void)

{
  return;
}


// SafeRead  @ 000a60e0
void SafeRead(FileHandle_t f,void *buffer,int count)

{
  int iVar1;
  
  iVar1 = FS_Read(buffer,count,1,f);
  if (count != iVar1) {
    Sys_Error("File read failure");
    return;
  }
  return;
}


// SaveExit  @ 00059aa0
void SaveExit(SAVERESTOREDATA *save)

{
  if (save != (SAVERESTOREDATA *)0x0) {
    if (save->pTokens != (char **)0x0) {
      Mem_Free(save->pTokens);
      save->pTokens = (char **)0x0;
      save->tokenCount = 0;
    }
    Mem_Free(save);
  }
  gGlobalVariables.pSaveData = (void *)0x0;
  return;
}


// SaveGame  @ 0005c640
BOOL SaveGame(char *pszSlot,char *pszComment)

{
  qboolean qVar1;
  BOOL BVar2;
  
                    /* Unresolved local var: qboolean qret@[DW_OP_reg0(EAX)]
                       Unresolved local var: qboolean q@[???] */
  qVar1 = scr_skipupdate;
  scr_skipupdate = true;
  BVar2 = SaveGameSlot(pszSlot,pszComment);
  scr_skipupdate = qVar1;
  return BVar2;
}


// SaveGameSlot  @ 0005be00
BOOL SaveGameSlot(char *pSaveName,char *pSaveComment)

{
  char cVar1;
  char *pcVar2;
  SAVERESTOREDATA *pSVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  FileHandle_t file;
  BOOL BVar7;
  int iVar8;
  int iVar9;
  int in_GS_OFFSET;
  undefined4 local_4a0;
  char local_49c [31];
  undefined1 local_47d;
  char local_47c [79];
  undefined1 local_42d;
  int local_42c;
  char local_428 [256];
  char local_328 [256];
  char local_228 [260];
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char[256] hlPath@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: char * pTokenData@[???]
                       Unresolved local var: int tag@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: GAME_HEADER gameHeader@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
  FS_CreateDirHierarchy(Host_SaveGameDirectory::szDirectory,"GAMECONFIG");
  pSVar3 = SaveGamestate();
  if (pSVar3 == (SAVERESTOREDATA *)0x0) {
    BVar7 = 0;
    goto LAB_0005c450;
  }
  if (pSVar3->pTokens != (char **)0x0) {
    Mem_Free(pSVar3->pTokens);
    pSVar3->pTokens = (char **)0x0;
    pSVar3->tokenCount = 0;
  }
  Mem_Free(pSVar3);
  gGlobalVariables.pSaveData = (void *)0x0;
  pSVar3 = SaveInit(0);
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: char * findfn@[???] */
  iVar9 = 0;
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
  __snprintf_chk(local_428,0x100,1,0x100,&DAT_000d3fb9,Host_SaveGameDirectory::szDirectory);
  COM_FixSlashes(local_428);
  pcVar4 = Sys_FindFirstPathID(local_428,"GAMECONFIG");
  if (pcVar4 != (char *)0x0) {
    iVar9 = 0;
    do {
      iVar9 = iVar9 + 1;
      pcVar4 = Sys_FindNext((char *)0x0);
    } while (pcVar4 != (char *)0x0);
  }
  Sys_FindClose();
  local_42c = iVar9;
  Q_strncpy(local_49c,sv.name,0x1f);
  local_47d = 0;
  Q_strncpy(local_47c,pSaveComment,0x4f);
  local_42d = 0;
  (*gEntityInterface.pfnSaveWriteFields)(pSVar3,"GameHeader",local_49c,gGameHeaderDescription,3);
  (*gEntityInterface.pfnSaveGlobalState)(pSVar3);
  pcVar4 = pSVar3->pCurrentData;
  if ((pSVar3->pTokens != (char **)0x0) && (0 < pSVar3->tokenCount)) {
    iVar9 = 0;
    pcVar6 = *pSVar3->pTokens;
    do {
      if (pcVar6 == (char *)0x0) {
        iVar5 = pSVar3->size + 1;
        pSVar3->size = iVar5;
        if (pSVar3->bufferSize < iVar5) goto LAB_0005c09f;
        pcVar6 = pSVar3->pCurrentData;
        pSVar3->pCurrentData = pcVar6 + 1;
        *pcVar6 = '\0';
        if (pSVar3->tokenCount <= iVar9 + 1) goto LAB_0005c082;
      }
      else {
                    /* Unresolved local var: char * pszToken@[???] */
        iVar5 = Q_strlen(pcVar6);
        iVar5 = iVar5 + 1 + pSVar3->size;
        pSVar3->size = iVar5;
        if (pSVar3->bufferSize < iVar5) {
LAB_0005c09f:
          Con_Printf("Token Table Save/Restore overflow!");
          pSVar3->size = pSVar3->bufferSize;
          pSVar3->tokenSize = (int)pSVar3->pCurrentData - (int)pcVar4;
          goto LAB_0005c0bd;
        }
        do {
          pcVar2 = pSVar3->pCurrentData;
          pSVar3->pCurrentData = pcVar2 + 1;
          cVar1 = *pcVar6;
          *pcVar2 = cVar1;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        if (pSVar3->tokenCount <= iVar9 + 1) goto LAB_0005c082;
      }
      iVar9 = iVar9 + 1;
      pcVar6 = pSVar3->pTokens[iVar9];
    } while( true );
  }
  iVar5 = pSVar3->size;
  iVar8 = 0;
  iVar9 = pSVar3->bufferSize;
  goto LAB_0005c091;
LAB_0005c082:
  iVar9 = pSVar3->bufferSize;
  iVar8 = (int)pSVar3->pCurrentData - (int)pcVar4;
  iVar5 = pSVar3->size;
LAB_0005c091:
  pSVar3->tokenSize = iVar8;
  if (iVar5 < iVar9) {
    pSVar3->size = iVar5 - iVar8;
  }
LAB_0005c0bd:
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
  __snprintf_chk(local_328,0xfc,1,0x100,&DAT_000dde77,Host_SaveGameDirectory::szDirectory,pSaveName)
  ;
  COM_DefaultExtension(local_328,".sav");
  COM_FixSlashes(local_328);
  Con_DPrintf("Saving game to %s...\n",local_328);
  iVar9 = Q_stricmp(pSaveName,"quick");
  if ((iVar9 != 0) || (iVar9 = Q_stricmp(pSaveName,"autosave"), iVar9 != 0)) {
                    /* Unresolved local var: char[260] newName@[???]
                       Unresolved local var: char[260] oldName@[???] */
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
    __snprintf_chk(local_228,0x104,1,0x104,"%s%s%02d.sav",Host_SaveGameDirectory::szDirectory,
                   pSaveName,1);
    COM_FixSlashes(local_228);
    FS_RemoveFile(local_228,"GAMECONFIG");
    pcVar6 = Host_SaveGameDirectory();
    __snprintf_chk(local_124,0x104,1,0x104,"%s%s.sav",pcVar6,pSaveName);
    COM_FixSlashes(local_124);
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
    __snprintf_chk(local_228,0x104,1,0x104,"%s%s%02d.sav",Host_SaveGameDirectory::szDirectory,
                   pSaveName,1);
    COM_FixSlashes(local_228);
    FS_Rename(local_124,local_228);
  }
  file = FS_OpenPathID(local_328,"wb","GAMECONFIG");
  local_4a0 = 0x5641534a;
  FS_Write(&local_4a0,4,1,file);
  local_4a0 = 0x71;
  FS_Write(&local_4a0,4,1,file);
  FS_Write(&pSVar3->size,4,1,file);
  FS_Write(&pSVar3->tokenCount,4,1,file);
  FS_Write(&pSVar3->tokenSize,4,1,file);
  FS_Write(pcVar4,pSVar3->tokenSize,1,file);
  FS_Write(pSVar3->pBaseData,pSVar3->size,1,file);
  DirectoryCopy(local_428,file);
  FS_Close(file);
  if (pSVar3 != (SAVERESTOREDATA *)0x0) {
    if (pSVar3->pTokens != (char **)0x0) {
      Mem_Free(pSVar3->pTokens);
      pSVar3->pTokens = (char **)0x0;
      pSVar3->tokenCount = 0;
    }
    Mem_Free(pSVar3);
  }
  gGlobalVariables.pSaveData = (void *)0x0;
  BVar7 = 1;
LAB_0005c450:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return BVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SaveGamestate  @ 0005a4f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

SAVERESTOREDATA * SaveGamestate(void)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  edict_t *peVar4;
  SAVERESTOREDATA *pSaveData;
  char **ppcVar5;
  char *pcVar6;
  FileHandle_t file;
  int iVar7;
  char *pcVar8;
  char *pInput;
  int in_GS_OFFSET;
  int local_1f0;
  char *local_1ec;
  int local_1e8;
  int local_1dc;
  int local_1d8;
  char local_1d4 [63];
  undefined1 local_195;
  undefined1 local_194 [4];
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  int local_180;
  float local_17c;
  char local_178 [31];
  undefined1 local_159;
  char local_158 [31];
  undefined1 local_139;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: char[256] name@[???]
                       Unresolved local var: char * pTableData@[???]
                       Unresolved local var: char * pTokenData@[???]
                       Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int dataSize@[???]
                       Unresolved local var: int tableSize@[???]
                       Unresolved local var: edict_t * pent@[???]
                       Unresolved local var: SAVE_HEADER header@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: SAVELIGHTSTYLE light@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (gEntityInterface.pfnParmsChangeLevel == (_func_void *)0x0) {
    pSaveData = (SAVERESTOREDATA *)0x0;
  }
  else {
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
    FS_CreateDirHierarchy(Host_SaveGameDirectory::szDirectory,"GAMECONFIG");
    pSaveData = SaveInit(0);
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
    iVar7 = 0;
    __snprintf_chk(local_120,0x100,1,0x100,"%s%s.HL1",Host_SaveGameDirectory::szDirectory,0x4ff2a8);
    COM_FixSlashes(local_120);
    (*gEntityInterface.pfnParmsChangeLevel)();
    local_190 = build_number();
    local_17c = (float)sv.time;
    local_18c = (int)skill.value;
    local_188 = pSaveData->tableCount;
    local_184 = pSaveData->connectionCount;
    Q_strncpy(local_158,sv_skyname.string,0x1f);
    local_139 = 0;
    local_130 = 0;
    local_134 = 0;
    local_138 = 0;
    pSaveData->time = 0.0;
    local_124 = 0;
    local_128 = 0;
    local_12c = 0;
    Q_strncpy(local_178,sv.name,0x1f);
    local_180 = 0;
    ppcVar5 = sv.lightstyles;
    bVar3 = false;
    local_159 = 0;
    do {
      if (*ppcVar5 != (char *)0x0) {
        iVar7 = iVar7 + 1;
        bVar3 = true;
      }
      ppcVar5 = ppcVar5 + 1;
    } while (ppcVar5 != (char **)&sv.num_edicts);
    local_1dc = 0x40;
    if (bVar3) {
      local_180 = iVar7;
    }
    (*gEntityInterface.pfnSaveWriteFields)
              (pSaveData,"Save Header",local_194,gSaveHeaderDescription,0xd);
    local_1dc = 0;
    pSaveData->time = local_17c;
    if (0 < pSaveData->connectionCount) {
      do {
        (*gEntityInterface.pfnSaveWriteFields)
                  (pSaveData,"ADJACENCY",pSaveData->levelList + local_1dc,gAdjacencyDescription,4);
        local_1dc = local_1dc + 1;
      } while (local_1dc < pSaveData->connectionCount);
    }
    local_1dc = 0;
    do {
      if (sv.lightstyles[local_1dc] != (char *)0x0) {
        local_1d8 = local_1dc;
        Q_strncpy(local_1d4,sv.lightstyles[local_1dc],0x3f);
        local_195 = 0;
        (*gEntityInterface.pfnSaveWriteFields)
                  (pSaveData,"LIGHTSTYLE",&local_1d8,gLightstyleDescription,2);
      }
      local_1dc = local_1dc + 1;
    } while (local_1dc < 0x40);
    local_1dc = 0;
    if (sv.num_edicts < 1) {
      local_1f0 = pSaveData->size;
      local_1dc = 0;
      local_1e8 = 0;
      pInput = pSaveData->pCurrentData;
      local_1ec = pInput;
    }
    else {
      do {
        while( true ) {
          peVar4 = sv.edicts;
          pSaveData->currentIndex = local_1dc;
          pSaveData->pTable[local_1dc].location = pSaveData->size;
          pSaveData->pTable[local_1dc].size = 0;
          if (((peVar4[local_1dc].free == false) &&
              ((*gEntityInterface.pfnSave)(peVar4 + local_1dc,pSaveData), 0 < local_1dc)) &&
             (local_1dc <= svs.maxclients)) break;
          local_1dc = local_1dc + 1;
          if (sv.num_edicts <= local_1dc) goto LAB_0005a8b0;
        }
        iVar7 = local_1dc + 1;
        piVar1 = &pSaveData->pTable[local_1dc].flags;
        *piVar1 = *piVar1 | 0x80000000;
        local_1dc = iVar7;
      } while (iVar7 < sv.num_edicts);
LAB_0005a8b0:
      local_1f0 = pSaveData->size;
      local_1dc = 0;
      local_1ec = pSaveData->pCurrentData;
      if (sv.num_edicts < 1) {
        local_1e8 = 0;
        pInput = local_1ec;
      }
      else {
        do {
          (*gEntityInterface.pfnSaveWriteFields)
                    (pSaveData,"ETABLE",pSaveData->pTable + local_1dc,gEntityTableDescription,5);
          local_1dc = local_1dc + 1;
        } while (local_1dc < sv.num_edicts);
        local_1e8 = pSaveData->size - local_1f0;
        pInput = pSaveData->pCurrentData;
      }
    }
    if ((pSaveData->pTokens == (char **)0x0) || (local_1dc = 0, pSaveData->tokenCount < 1)) {
      iVar7 = 0;
    }
    else {
      pcVar6 = *pSaveData->pTokens;
      pcVar8 = pInput;
      if (pcVar6 != (char *)0x0) goto LAB_0005a953;
      while( true ) {
        pSaveData->pCurrentData = pcVar8 + 1;
        *pcVar8 = '\0';
        local_1dc = local_1dc + 1;
        if (pSaveData->tokenCount <= local_1dc) break;
        while( true ) {
          pcVar8 = pSaveData->pCurrentData;
          pcVar6 = pSaveData->pTokens[local_1dc];
          if (pSaveData->pTokens[local_1dc] == (char *)0x0) break;
LAB_0005a953:
          while( true ) {
                    /* Unresolved local var: char * pszToken@[???] */
            pSaveData->pCurrentData = pcVar8 + 1;
            cVar2 = *pcVar6;
            *pcVar8 = cVar2;
            if (cVar2 == '\0') break;
            pcVar8 = pSaveData->pCurrentData;
            pcVar6 = pcVar6 + 1;
          }
          local_1dc = local_1dc + 1;
          if (pSaveData->tokenCount <= local_1dc) goto LAB_0005a996;
        }
      }
LAB_0005a996:
      iVar7 = (int)pSaveData->pCurrentData - (int)pInput;
    }
    pSaveData->tokenSize = iVar7;
    COM_CreatePath(local_120);
    file = FS_OpenPathID(local_120,"wb","GAMECONFIG");
    if (file == (FileHandle_t)0x0) {
      Con_Printf("Unable to open save game file %s.",local_120);
      pSaveData = (SAVERESTOREDATA *)0x0;
    }
    else {
      local_1dc = 0x564c4156;
      FS_Write(&local_1dc,4,1,file);
      local_1dc = 0x71;
      FS_Write(&local_1dc,4,1,file);
      FS_Write(&pSaveData->size,4,1,file);
      FS_Write(&pSaveData->tableCount,4,1,file);
      FS_Write(&pSaveData->tokenCount,4,1,file);
      FS_Write(&pSaveData->tokenSize,4,1,file);
      FS_Write(pInput,pSaveData->tokenSize,1,file);
      FS_Write(local_1ec,local_1e8,1,file);
      FS_Write(pSaveData->pBaseData,local_1f0,1,file);
      FS_Close(file);
      EntityPatchWrite(pSaveData,sv.name);
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      builtin_strncpy(Host_SaveGameDirectory::szDirectory,"SAVE/",6);
      __snprintf_chk(local_120,0x100,1,0x100,"%s%s.HL2",Host_SaveGameDirectory::szDirectory,0x4ff2a8
                    );
      COM_FixSlashes(local_120);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pSaveData;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SaveInit  @ 00059940
SAVERESTOREDATA * SaveInit(int size)

{
  int iVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  edict_t *peVar5;
  SAVERESTOREDATA *pSVar6;
  char **ppcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
                    /* Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * pEdict@[???] */
  if (size < 1) {
    size = 0x80000;
  }
  pSVar6 = Mem_Calloc(size + 0x574 + sv.num_edicts * 0x18,1);
  pSVar6->pTable = (ENTITYTABLE *)(pSVar6 + 1);
  pSVar6->tokenSize = 0;
  pSVar6->tokenCount = 0xfff;
  ppcVar7 = Mem_Calloc(0xfff,4);
  pSVar6->pTokens = ppcVar7;
  if (0 < sv.num_edicts) {
    iVar8 = 0;
    iVar9 = 0;
    iVar10 = 0;
    do {
      peVar5 = sv.edicts;
      *(int *)((int)&pSVar6->pTable->id + iVar8) = iVar10;
      iVar10 = iVar10 + 1;
      iVar1 = iVar9 + -0x18;
      iVar9 = iVar9 + 0x324;
      *(int *)((int)&pSVar6->pTable->pent + iVar8) = (int)peVar5->leafnums + iVar1;
      *(undefined4 *)((int)&pSVar6->pTable->flags + iVar8) = 0;
      *(undefined4 *)((int)&pSVar6->pTable->location + iVar8) = 0;
      *(undefined4 *)((int)&pSVar6->pTable->size + iVar8) = 0;
      *(undefined4 *)((int)&pSVar6->pTable->classname + iVar8) = 0;
      iVar8 = iVar8 + 0x18;
    } while (iVar10 < sv.num_edicts);
  }
  pSVar6->tableCount = sv.num_edicts;
  pSVar6->connectionCount = 0;
  iVar8 = sv.num_edicts;
  pSVar6->size = 0;
  pSVar6->bufferSize = size;
  pSVar6->pBaseData = (char *)(pSVar6->pTable + iVar8);
  pSVar6->pCurrentData = (char *)(pSVar6->pTable + iVar8);
  vVar4 = vec3_origin[2];
  vVar3 = vec3_origin[1];
  vVar2 = vec3_origin[0];
  pSVar6->time = gGlobalVariables.time;
  pSVar6->vecLandmarkOffset[0] = vVar2;
  pSVar6->vecLandmarkOffset[1] = vVar3;
  pSVar6->vecLandmarkOffset[2] = vVar4;
  pSVar6->fUseLandmark = 0;
  gGlobalVariables.pSaveData = pSVar6;
  return pSVar6;
}


// SaveReadComment  @ 00059b80
void SaveReadComment(FileHandle_t f,char *name)

{
  int iVar1;
  int in_GS_OFFSET;
  int local_88;
  GAME_HEADER local_84;
  int local_10;
  
                    /* Unresolved local var: GAME_HEADER gameHeader@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int tag@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int tokenCount@[???]
                       Unresolved local var: int tokenSize@[???]
                       Unresolved local var: char * pszTokenList@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  FS_Read(&local_88,4,1,f);
  if (local_88 == 0x5641534a) {
    FS_Read(&local_88,4,1,f);
    if (local_88 == 0x71) {
      iVar1 = SaveReadHeader(f,&local_84,0);
      if (iVar1 != 0) {
        Q_strcpy(name,local_84.comment);
      }
      goto LAB_00059bec;
    }
  }
  FS_Close(f);
LAB_00059bec:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SaveReadHeader  @ 000570f0
int __regparm3 SaveReadHeader(FileHandle_t pFile,GAME_HEADER *pHeader,int readGlobalState)

{
  SAVERESTOREDATA *p;
  int iVar1;
  char **ppcVar2;
  SAVERESTOREDATA *pSVar3;
  SAVERESTOREDATA *pOutput;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int tag@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int tokenCount@[???]
                       Unresolved local var: int tokenSize@[???]
                       Unresolved local var: char * pszTokenList@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
  FS_Read(&local_28,4,1,pFile);
  FS_Read(&local_24,4,1,pFile);
  FS_Read(local_20,4,1,pFile);
  if ((((-1 < local_28) && (-1 < local_24)) && (-1 < local_20[0])) &&
     ((local_20[0] <= 0x7fffffff - local_28 && (0x573 < 0x7fffffffU - (local_20[0] + local_28))))) {
    p = Mem_Calloc(local_20[0] + local_28 + 0x574,1);
    if (p != (SAVERESTOREDATA *)0x0) {
      p->tableCount = 0;
      pOutput = p + 1;
      p->pTable = (ENTITYTABLE *)0x0;
      p->connectionCount = 0;
      if (0 < local_20[0]) {
        p->tokenSize = local_20[0];
        p->tokenCount = local_24;
        FS_Read(pOutput,local_20[0],1,pFile);
        ppcVar2 = p->pTokens;
        if (ppcVar2 == (char **)0x0) {
          ppcVar2 = Mem_Calloc(local_24,4);
          p->pTokens = ppcVar2;
        }
        if (0 < local_24) {
          iVar1 = 0;
          while( true ) {
            pSVar3 = (SAVERESTOREDATA *)0x0;
            if (*(char *)&pOutput->pBaseData != '\0') {
              pSVar3 = pOutput;
            }
            ppcVar2[iVar1] = (char *)pSVar3;
            pSVar3 = pOutput;
            do {
              pOutput = (SAVERESTOREDATA *)((int)&pSVar3->pBaseData + 1);
              ppcVar2 = &pSVar3->pBaseData;
              pSVar3 = pOutput;
            } while (*(char *)ppcVar2 != '\0');
            iVar1 = iVar1 + 1;
            if (local_24 <= iVar1) break;
            ppcVar2 = p->pTokens;
          }
        }
      }
      p->pBaseData = (char *)pOutput;
      p->fUseLandmark = 0;
      p->pCurrentData = (char *)pOutput;
      p->bufferSize = local_28;
      p->size = 0;
      p->time = 0.0;
      FS_Read(pOutput,local_28,1,pFile);
      (*gEntityInterface.pfnSaveReadFields)(p,"GameHeader",pHeader,gGameHeaderDescription,3);
      if (readGlobalState != 0) {
        (*gEntityInterface.pfnRestoreGlobalState)(p);
      }
      if (p->pTokens != (char **)0x0) {
        Mem_Free(p->pTokens);
        p->pTokens = (char **)0x0;
        p->tokenCount = 0;
      }
      Mem_Free(p);
      gGlobalVariables.pSaveData = (void *)0x0;
      return 1;
    }
  }
  FS_Close(pFile);
  return 0;
}


// SaveReadHeader  @ 00059ae0
int SaveReadHeader(FileHandle_t pFile,GAME_HEADER *pHeader,int readGlobalState)

{
  int iVar1;
  int local_10 [2];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int tag@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int tokenCount@[???]
                       Unresolved local var: int tokenSize@[???]
                       Unresolved local var: char * pszTokenList@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
  FS_Read(local_10,4,1,pFile);
  if (local_10[0] == 0x5641534a) {
    FS_Read(local_10,4,1,pFile);
    if (local_10[0] == 0x71) {
      iVar1 = SaveReadHeader(pFile,pHeader,readGlobalState);
      return iVar1;
    }
  }
  FS_Close(pFile);
  return 0;
}


// SaveSpawnParms  @ 00075850
void SaveSpawnParms(edict_t *pEdict)

{
  uint uVar1;
  
                    /* Unresolved local var: int eoffset@[???]
                       Unresolved local var: client_t * client@[???] */
                    /* Unresolved local var: int b@[???] */
  uVar1 = (uint)((int)pEdict - (int)sv.edicts) / 0x324;
  if (sv.num_edicts <= (int)uVar1) {
    Sys_Error("NUM_FOR_EDICT: bad pointer");
  }
  if ((uVar1 != 0) && ((int)uVar1 <= svs.maxclients)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  Host_Error("Entity is not a client");
}


// SeedRandomNumberGenerator  @ 000736f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SeedRandomNumberGenerator(void)

{
  int32 iVar1;
  
  iVar1 = time((time_t *)0x0);
  idum = -iVar1;
  if (iVar1 == -1000 || idum < 1000) {
    if (idum < -999) {
      return;
    }
    iVar1 = -0x153ad38 - iVar1;
  }
  idum = iVar1;
  return;
}


// ServerPrint  @ 0006de60
void ServerPrint(char *szMsg)

{
  Con_Printf("%s",szMsg);
  return;
}


// SetCStrikeFlags  @ 0008e7d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SetCStrikeFlags(void)

{
  int iVar1;
  
  if (g_bCS_CZ_Flags_Initialized == 0) {
    iVar1 = strcasecmp(com_gamedir,"cstrike");
    if ((iVar1 == 0) || (iVar1 = strcasecmp(com_gamedir,"cstrike_beta"), iVar1 == 0)) {
      g_bIsCStrike = 1;
    }
    else {
      iVar1 = strcasecmp(com_gamedir,"czero");
      if (iVar1 == 0) {
        g_bIsCZero = 1;
      }
      else {
        iVar1 = strcasecmp(com_gamedir,"czeror");
        if (iVar1 == 0) {
          g_bIsCZeroRitual = 1;
        }
        else {
          iVar1 = strcasecmp(com_gamedir,"terror");
          if (iVar1 == 0) {
            g_bIsTerrorStrike = 1;
          }
          else {
            iVar1 = strcasecmp(com_gamedir,"tfc");
            if (iVar1 == 0) {
              g_bIsTFC = 1;
            }
            else {
              iVar1 = strcasecmp(com_gamedir,"valve");
              if (iVar1 == 0) {
                g_bIsHL1 = 1;
              }
            }
          }
        }
      }
    }
    g_bCS_CZ_Flags_Initialized = 1;
    return;
  }
  return;
}


// SetCareerAudioState  @ 00045620
void SetCareerAudioState(int state)

{
  return;
}


// SetLoadingProgressBarStatusText  @ 000b3350
void SetLoadingProgressBarStatusText(char *statusText)

{
  return;
}


// SetMinMaxSize  @ 0006d8e0
void SetMinMaxSize(edict_t *e,float *min,float *max,qboolean rotate)

{
  vec_t vVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  vec_t vVar5;
  
                    /* Unresolved local var: float * angles@[???]
                       Unresolved local var: vec3_t rmin@[???]
                       Unresolved local var: vec3_t rmax@[???]
                       Unresolved local var: float[2][3] bounds@[???]
                       Unresolved local var: float[2] xvector@[???]
                       Unresolved local var: float[2] yvector@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: vec3_t base@[???]
                       Unresolved local var: vec3_t transformed@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: int l@[???] */
  if (*max < *min) {
                    /* WARNING: Subroutine does not return */
    Host_Error("backwards mins/maxs");
  }
  if (min[1] <= max[1]) {
    fVar2 = min[2];
    fVar3 = max[2];
    if (fVar2 <= fVar3) {
      vVar4 = *max;
      vVar5 = max[1];
      vVar1 = *min;
      (e->v).mins[1] = min[1];
      (e->v).mins[2] = fVar2;
      (e->v).maxs[0] = vVar4;
      (e->v).maxs[1] = vVar5;
      (e->v).mins[0] = vVar1;
      (e->v).maxs[2] = fVar3;
      (e->v).size[0] = *max - *min;
      (e->v).size[1] = max[1] - min[1];
      (e->v).size[2] = max[2] - min[2];
      SV_LinkEdict(e,false);
      return;
    }
                    /* WARNING: Subroutine does not return */
    Host_Error("backwards mins/maxs");
  }
                    /* WARNING: Subroutine does not return */
  Host_Error("backwards mins/maxs");
}


// SetRateRegistrySetting  @ 0007bd00
void SetRateRegistrySetting(char *pchRate)

{
  (*registry->_vptr_IRegistry[5])(registry,"rate",pchRate);
  return;
}


// SetSteamNetworkingSocketsDebugOutputFunction  @ 000bb380
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SetSteamNetworkingSocketsDebugOutputFunction(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = (int *)SteamInternal_ContextInit
                            (SteamNetworkingUtils_SteamAPI::s_CallbackCounterAndContext);
  if (*piVar1 != 0) {
    puVar2 = (undefined4 *)
             SteamInternal_ContextInit(SteamNetworkingUtils_SteamAPI::s_CallbackCounterAndContext);
    (**(code **)(*(int *)*puVar2 + 0x34))((int *)*puVar2,5,SteamNetworkingSocketsDebugOutput);
  }
  return;
}


// ShortNoSwap  @ 00039a80
short ShortNoSwap(short l)

{
  return l;
}


// ShortSwap  @ 00039a60
short ShortSwap(short l)

{
                    /* Unresolved local var: byte b1@[???]
                       Unresolved local var: byte b2@[???] */
  return l * 0x100 + ((ushort)l >> 8);
}


// SkipSpace  @ 000a5110
char * SkipSpace(char *pText)

{
  char cVar1;
  
  if (pText != (char *)0x0) {
                    /* Unresolved local var: int pos@[???] */
    cVar1 = *pText;
    while (((cVar1 != '\0' && ((byte)(cVar1 - 9U) < 0x18)) &&
           (((byte)(0x800013 >> (cVar1 - 9U & 0x1f)) & 1) == 1))) {
      pText = pText + 1;
      cVar1 = *pText;
    }
    return pText;
  }
  return (char *)0x0;
}


// SkipText  @ 000a5160
char * SkipText(char *pText)

{
  byte bVar1;
  
  if (pText == (char *)0x0) {
    return (char *)0x0;
  }
                    /* Unresolved local var: int pos@[???] */
  bVar1 = *pText;
  if ((bVar1 & 0xdf) == 0) {
    return pText;
  }
  if ((1 < (byte)(bVar1 - 9)) && (bVar1 != 0xd)) {
    while( true ) {
      pText = pText + 1;
      bVar1 = *pText;
      if ((bVar1 & 0xdf) == 0) break;
      if ((byte)(bVar1 - 9) < 2) {
        return (char *)(byte *)pText;
      }
      if (bVar1 == 0xd) {
        return (char *)(byte *)pText;
      }
    }
  }
  return pText;
}


// SockadrToNetadr  @ 000af3f0
void SockadrToNetadr(sockaddr *s,netadr_t *a)

{
  if (s->sa_family != 2) {
    return;
  }
  a->type = NA_IP;
  *(undefined4 *)a->ip = *(undefined4 *)(s->sa_data + 2);
  a->port = *(ushort *)s->sa_data;
  return;
}


// StartLoadingProgressBar  @ 000b3330
void StartLoadingProgressBar(char *loadingType,int numProgressPoints)

{
  return;
}


// Steam3Client  @ 000be5a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CSteam3Client * Steam3Client(void)

{
  return &s_Steam3Client;
}


// Steam3Server  @ 000be590
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CSteam3Server * Steam3Server(void)

{
  return s_Steam3Server;
}


// SteamIDFromSteam2String  @ 000c4860
bool SteamIDFromSteam2String(char *pchSteam2ID,EUniverse eUniverse,CSteamID *pSteamIDOut)

{
  int iVar1;
  char local_19;
  short local_18 [2];
  int local_14;
  int local_10 [2];
  
                    /* Unresolved local var: TSteamGlobalUserID.conflict steam2ID@[???]
                       Unresolved local var: char * pchTSteam2ID@[???]
                       Unresolved local var: char * pchOptionalLeadString@[???]
                       Unresolved local var: char cExtraCharCheck@[???]
                       Unresolved local var: int cFieldConverted@[???] */
  local_10[0] = 0;
  local_14 = 0;
  local_18[0] = 0;
  iVar1 = strncasecmp(pchSteam2ID,"STEAM_",6);
  local_19 = '\0';
  if (iVar1 == 0) {
    pchSteam2ID = pchSteam2ID + 6;
  }
  iVar1 = sscanf(pchSteam2ID,"%hu:%u:%u%c",local_18,local_10,&local_14,&local_19);
  if (1 < iVar1 && local_19 == '\0') {
    if ((iVar1 == 2) && (local_18[0] != 1)) {
      return false;
    }
    *(undefined1 *)((int)&pSteamIDOut->m_steamid + 4) = 1;
    *(undefined1 *)((int)&pSteamIDOut->m_steamid + 5) = 0;
    *(undefined1 *)((int)&pSteamIDOut->m_steamid + 6) = 0x10;
    (pSteamIDOut->m_steamid).m_comp.m_unAccountID = local_10[0] + local_14 * 2;
    (pSteamIDOut->m_steamid).m_comp.m_EUniverse = (byte)eUniverse;
    return true;
  }
  return false;
}


// SteamNetworkingSocketsDebugOutput  @ 000be700
/* WARNING: Removing unreachable block (ram,0x000be7b0) */
/* WARNING: Removing unreachable block (ram,0x000be7be) */

void SteamNetworkingSocketsDebugOutput(ESteamNetworkingSocketsDebugOutputType nType,char *pszMsg)

{
  code *pcVar1;
  int iVar2;
  _Rep *this;
  string *this_00;
  undefined4 uVar3;
  allocator<char> *in_stack_ffffffd8;
  string local_10 [2];
  
                    /* Unresolved local var: SteamDebugOutput_t debugOutput@[???] */
                    /* Unresolved local var: int __e@[???] */
  this = (_Rep *)pthread_mutex_lock((pthread_mutex_t *)&g_SteamDebugOutputMutex);
  if (this == (_Rep *)0x0) {
    local_10[0]._M_dataplus._M_p = (_Alloc_hider)__cxa_begin_catch;
    strlen(pszMsg);
    std::string::assign((char *)local_10,(uint)pszMsg);
    if (g_SteamDebugOutputQueue.
        super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
        _M_finish ==
        g_SteamDebugOutputQueue.
        super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
        _M_end_of_storage) {
      std::vector<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>::
      _M_emplace_back_aux<const_SteamDebugOutput_t&>(&g_SteamDebugOutputQueue);
    }
    else {
      if (g_SteamDebugOutputQueue.
          super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
          _M_finish != (pointer)0x0) {
        this_00 = &(g_SteamDebugOutputQueue.
                    super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>.
                    _M_impl._M_finish)->m_sMsg;
        (g_SteamDebugOutputQueue.
         super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
        _M_finish)->m_nType = nType;
        std::string::string(this_00,local_10);
      }
      g_SteamDebugOutputQueue.
      super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl._M_finish
           = g_SteamDebugOutputQueue.
             super__Vector_base<SteamDebugOutput_t,_std::allocator<SteamDebugOutput_t>_>._M_impl.
             _M_finish + 1;
    }
    pthread_mutex_unlock((pthread_mutex_t *)&g_SteamDebugOutputMutex);
    if ((allocator *)((int)local_10[0]._M_dataplus._M_p + -0xc) !=
        (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
      LOCK();
      pcVar1 = (code *)((int)local_10[0]._M_dataplus._M_p + -4);
      iVar2 = *(int *)pcVar1;
      *(int *)pcVar1 = *(int *)pcVar1 + -1;
      UNLOCK();
      if (iVar2 < 1) {
        std::string::_Rep::_M_destroy((allocator *)((int)local_10[0]._M_dataplus._M_p + -0xc));
      }
    }
    return;
  }
  uVar3 = std::__throw_system_error((int)this);
  if (local_10[0]._M_dataplus._M_p != (_Alloc_hider)__cxa_begin_catch) {
    std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>::_Rep::_M_dispose
              (this,in_stack_ffffffd8);
  }
                    /* WARNING: Subroutine does not return */
  _Unwind_Resume(uVar3);
}


// StringToFilter  @ 0008fe70
qboolean StringToFilter(char *s,ipfilter_t *f)

{
  char cVar1;
  int iVar2;
  qboolean qVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int in_GS_OFFSET;
  uint local_a8;
  uint local_a4;
  char local_a0 [128];
  int local_20;
  
                    /* Unresolved local var: char[128] num@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: byte[4] b@[???]
                       Unresolved local var: byte[4] m@[???] */
  iVar6 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_a8 = 0;
  local_a4 = 0;
  do {
    cVar1 = *s;
    if (9 < (byte)(cVar1 - 0x30U)) {
      Con_Printf("Bad filter address: %s\n",s);
      qVar3 = false;
      goto LAB_0008ff0c;
    }
    iVar2 = 0;
    do {
      pcVar5 = s;
      iVar4 = iVar2;
      s = pcVar5 + 1;
      local_a0[iVar4] = cVar1;
      cVar1 = *s;
      iVar2 = iVar4 + 1;
    } while ((byte)(cVar1 - 0x30U) < 10);
    local_a0[iVar4 + 1] = '\0';
    iVar2 = Q_atoi(local_a0);
    *(char *)((int)&local_a8 + iVar6) = (char)iVar2;
    if ((char)iVar2 != '\0') {
      local_a0[iVar6 + -4] = -1;
    }
    if (*s == '\0') break;
    iVar6 = iVar6 + 1;
    s = pcVar5 + 2;
  } while (iVar6 != 4);
  f->mask = local_a4;
  f->compare = local_a8;
  qVar3 = true;
LAB_0008ff0c:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SuckOutClassname  @ 000747f0
bool __regparm3 SuckOutClassname(char *szInputStream,edict_t *pEdict)

{
  bool bVar1;
  int iVar2;
  char *data;
  int in_GS_OFFSET;
  KeyValueData local_120;
  char local_110 [255];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: bool[256] szKeyName@[???]
                       Unresolved local var: KeyValueData kvd@[???]
                       Unresolved local var: char * pszLastString@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_120.szClassName = (char *)0x0;
  local_120.szValue = "";
  local_120.fHandled = 0;
  local_120.szKeyName = local_110;
  do {
    data = COM_Parse(szInputStream);
    if ((data == (char *)0x0) || (com_token[0] == '}')) {
      bVar1 = false;
      goto LAB_0007488f;
    }
    Q_strncpy(local_110,com_token,0xff);
    local_11 = 0;
    szInputStream = COM_Parse(data);
    if (szInputStream == (char *)0x0) break;
    iVar2 = Q_strcmp(local_110,"classname");
  } while (iVar2 != 0);
  local_120.szValue = com_token;
  (*gEntityInterface.pfnKeyValue)(pEdict,&local_120);
  if (local_120.fHandled == 0) {
                    /* WARNING: Subroutine does not return */
    Host_Error("SuckOutClassname: parse error");
  }
  bVar1 = true;
LAB_0007488f:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SurfaceAtPoint  @ 0006e920
msurface_t * SurfaceAtPoint(model_t *pModel,mnode_t *node,vec_t *start,vec_t *end)

{
  float fVar1;
  float fVar2;
  float fVar3;
  mplane_t *pmVar4;
  mtexinfo_t *pmVar5;
  float fVar6;
  float fVar7;
  bool bVar8;
  msurface_t *pmVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float front@[???]
                       Unresolved local var: float back@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: msurface_t * surf@[???]
                       Unresolved local var: int s@[???]
                       Unresolved local var: int t@[???]
                       Unresolved local var: int ds@[???]
                       Unresolved local var: int dt@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: mtexinfo_t * tex@[???] */
  if (node->contents < 0) {
    pmVar9 = (msurface_t *)0x0;
  }
  else {
    pmVar4 = node->plane;
    fVar1 = *start;
    fVar2 = start[1];
    fVar3 = start[2];
    fVar6 = (fVar2 * pmVar4->normal[1] + fVar1 * pmVar4->normal[0] + fVar3 * pmVar4->normal[2]) -
            pmVar4->dist;
    fVar7 = (pmVar4->normal[2] * end[2] + pmVar4->normal[1] * end[1] + pmVar4->normal[0] * *end) -
            pmVar4->dist;
    bVar8 = fVar6 < 0.0;
    if (fVar7 < 0.0 == bVar8) {
      pmVar9 = SurfaceAtPoint(pModel,node->children[bVar8],start,end);
      return pmVar9;
    }
    fVar6 = fVar6 / (fVar6 - fVar7);
    fVar1 = (*end - fVar1) * fVar6 + fVar1;
    fVar2 = (end[1] - fVar2) * fVar6 + fVar2;
    fVar3 = fVar6 * (end[2] - fVar3) + fVar3;
    local_28 = fVar1;
    local_24 = fVar2;
    local_20 = fVar3;
    pmVar9 = SurfaceAtPoint(pModel,node->children[bVar8],start,&local_28);
    if (pmVar9 == (msurface_t *)0x0) {
      pmVar9 = pModel->surfaces + node->firstsurface;
      if (node->numsurfaces != 0) {
        uVar12 = 0;
        do {
          pmVar5 = pmVar9->texinfo;
          iVar11 = (int)(pmVar5->vecs[0][2] * fVar3 +
                         pmVar5->vecs[0][1] * fVar2 + pmVar5->vecs[0][0] * fVar1 +
                        pmVar5->vecs[0][3]);
          if (pmVar9->texturemins[0] <= iVar11) {
            iVar10 = (int)(pmVar5->vecs[1][2] * fVar3 +
                           pmVar5->vecs[1][1] * fVar2 + pmVar5->vecs[1][0] * fVar1 +
                          pmVar5->vecs[1][3]);
            if (((pmVar9->texturemins[1] <= iVar10) &&
                (iVar11 - pmVar9->texturemins[0] <= (int)pmVar9->extents[0])) &&
               (iVar10 - pmVar9->texturemins[1] <= (int)pmVar9->extents[1])) {
              return pmVar9;
            }
          }
          uVar12 = uVar12 + 1;
          pmVar9 = pmVar9 + 1;
        } while (uVar12 != node->numsurfaces);
      }
      pmVar9 = SurfaceAtPoint(pModel,node->children[!bVar8],&local_28,end);
    }
  }
  return pmVar9;
}


// SwapPic  @ 000a81a0
void SwapPic(qpic_t *pic)

{
  int32 iVar1;
  
  iVar1 = (*LittleLong)(pic->width);
  pic->width = iVar1;
  iVar1 = (*LittleLong)(pic->height);
  pic->height = iVar1;
  return;
}


// SystemWrapper::AddModule  @ 0007d010
/* DWARF original prototype: bool AddModule(SystemWrapper * this, ISystemModule * module, char *
   name) */

bool __thiscall SystemWrapper::AddModule(SystemWrapper *this,ISystemModule *module,char *name)

{
  char cVar1;
  int iVar2;
  
  if (module == (ISystemModule *)0x0) {
    cVar1 = '\0';
  }
  else {
    iVar2 = (*(module->super_IBaseInterface)._vptr_IBaseInterface[2])
                      (module,this,this->m_SerialCounter,name);
    cVar1 = (char)iVar2;
    if (cVar1 == '\0') {
      (**(code **)((int)this->super_IBaseSystem + 0x4c))
                (this,"ERROR! System::AddModule: couldn\'t initialize module %s.\n",name);
    }
    else {
      ObjectList::AddHead(&this->m_Modules,module);
      this->m_SerialCounter = this->m_SerialCounter + 1;
    }
  }
  return (bool)cVar1;
}


// SystemWrapper::CheckParam  @ 0007ce00
/* DWARF original prototype: char * CheckParam(SystemWrapper * this, char * param) */

char * __thiscall SystemWrapper::CheckParam(SystemWrapper *this,char *param)

{
  int iVar1;
  char *pcVar2;
  
                    /* Unresolved local var: int pos@[???] */
  iVar1 = COM_CheckParm(param);
  if (iVar1 != 0) {
    pcVar2 = "";
    if (iVar1 + 1 < com_argc) {
      pcVar2 = com_argv[iVar1 + 1];
    }
    return pcVar2;
  }
  return (char *)0x0;
}


// SystemWrapper::DPrintf  @ 0007cf60
/* DWARF original prototype: void DPrintf(SystemWrapper * this, char * fmt, ...) */

void __thiscall SystemWrapper::DPrintf(SystemWrapper *this,char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  __vsnprintf_chk(DPrintf::string,0x2000,1,0x2000,fmt,&stack0x0000000c);
  Con_DPrintf(DPrintf::string);
  return;
}


// SystemWrapper::DispatchCommand  @ 0007dcc0
/* DWARF original prototype: bool DispatchCommand(SystemWrapper * this, char * command) */

bool __thiscall SystemWrapper::DispatchCommand(SystemWrapper *this,char *command)

{
  char *__s;
  size_t __n;
  int iVar1;
  
                    /* Unresolved local var: command_t * cmd@[???] */
  if ((command != (char *)0x0) && (*command != '\0')) {
                    /* Unresolved local var: command_t * cmd@[???] */
    __s = ObjectList::GetFirst(&this->m_Commands);
    while( true ) {
      if (__s == (char *)0x0) {
        Cmd_ExecuteString(command,src_command);
        return true;
      }
      __n = strlen(__s);
      iVar1 = strncasecmp(__s,command,__n);
      if (iVar1 == 0) break;
      __s = ObjectList::GetNext(&this->m_Commands);
    }
    (**(code **)(**(int **)(__s + 0x24) + 0x14))
              (*(int **)(__s + 0x24),*(undefined4 *)(__s + 0x20),command);
    return true;
  }
  return true;
}


// SystemWrapper::Errorf  @ 0007d0b0
/* DWARF original prototype: void Errorf(SystemWrapper * this, char * fmt, ...) */

void __thiscall SystemWrapper::Errorf(SystemWrapper *this,char *fmt,...)

{
  code *pcVar1;
  
                    /* Unresolved local var: va_list argptr@[???] */
  __vsnprintf_chk(Errorf::string,0x400,1,0x400,fmt,&stack0x0000000c);
  (**(code **)((int)this->super_IBaseSystem + 0x4c))(this,"***** FATAL ERROR *****\n");
  (**(code **)((int)this->super_IBaseSystem + 0x4c))(this,&DAT_000d525e,Errorf::string);
  (**(code **)((int)this->super_IBaseSystem + 0x4c))(this,"*** STOPPING SYSTEM ***\n");
  pcVar1 = *(code **)((int)this->super_IBaseSystem + 0x9c);
  if (pcVar1 == Stop) {
    (this->super_BaseSystemModule).m_State = 4;
    return;
  }
  (*pcVar1)(this);
  return;
}


// SystemWrapper::ExecuteCommand  @ 0007ec30
/* DWARF original prototype: void ExecuteCommand(SystemWrapper * this, int commandID, char *
   commandLine) */

void __thiscall SystemWrapper::ExecuteCommand(SystemWrapper *this,int commandID,char *commandLine)

{
  if (commandID == 2) {
    CMD_LoadModule(this,commandLine);
    return;
  }
  if (commandID != 3) {
    if (commandID != 1) {
                    /* WARNING: Could not recover jumptable at 0x0007ec5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((int)this->super_IBaseSystem + 0x4c))();
      return;
    }
    CMD_Modules(this,commandLine);
    return;
  }
  CMD_UnloadModule(this,commandLine);
  return;
}


// SystemWrapper::ExecuteCommand  @ 0007eca0
/* virtual thunk to SystemWrapper::ExecuteCommand(int, char*) */

void __thiscall SystemWrapper::ExecuteCommand(SystemWrapper *this,int param_1,char *param_2)

{
  ExecuteCommand((SystemWrapper *)
                 ((this->super_BaseSystemModule).m_Name +
                 *(int *)((int)this->super_IBaseSystem + -0x1c) + -0x20),param_1,param_2);
  return;
}


// SystemWrapper::ExecuteCommand  @ 0007ecb0
/* non-virtual thunk to SystemWrapper::ExecuteCommand(int, char*) */

void __thiscall SystemWrapper::ExecuteCommand(SystemWrapper *this,int param_1,char *param_2)

{
  ExecuteCommand((SystemWrapper *)&this[-1].m_EngineWrapper,param_1,param_2);
  return;
}


// SystemWrapper::ExecuteFile  @ 0007ced0
/* DWARF original prototype: void ExecuteFile(SystemWrapper * this, char * filename) */

void __thiscall SystemWrapper::ExecuteFile(SystemWrapper *this,char *filename)

{
  int in_GS_OFFSET;
  char local_410 [1023];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[1024] cmd@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __snprintf_chk(local_410,0x3ff,1,0x400,"exec %s\n",filename);
  local_11 = 0;
  Cmd_ExecuteString(local_410,src_command);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SystemWrapper::ExecuteString  @ 0007da40
/* DWARF original prototype: void ExecuteString(SystemWrapper * this, char * commands) */

void __thiscall SystemWrapper::ExecuteString(SystemWrapper *this,char *commands)

{
  bool bVar1;
  char *pcVar2;
  char *__s;
  size_t __n;
  int iVar3;
  char cVar4;
  int in_GS_OFFSET;
  bool bVar5;
  char local_120;
  char local_11f [255];
  int local_20;
  
                    /* Unresolved local var: char[256] singleCmd@[???]
                       Unresolved local var: bool quotes@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char * c@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((commands != (char *)0x0) && (cVar4 = *commands, pcVar2 = commands, cVar4 != '\0')) {
    do {
      if ((cVar4 == '%') || (cVar4 < ' ')) {
        *pcVar2 = ' ';
      }
      pcVar2 = pcVar2 + 1;
    } while ((pcVar2 != (char *)0x0) &&
            (cVar4 = *pcVar2, cVar4 != '\0'
                    /* Unresolved local var: char * c@[???] */));
    cVar4 = *commands;
    iVar3 = 1;
                    /* Unresolved local var: command_t * cmd@[???] */
    bVar1 = false;
    local_120 = cVar4;
    pcVar2 = &local_120;
    do {
      while (commands = commands + 1, cVar4 != '\"') {
        if (cVar4 == ';') {
          if (bVar1) goto LAB_0007db39;
          *pcVar2 = '\0';
          if (local_120 == ' ') goto LAB_0007daf4;
LAB_0007db73:
          bVar5 = false;
          pcVar2 = &local_120;
          cVar4 = local_120;
        }
        else {
          if (cVar4 != '\0') goto LAB_0007db39;
          *pcVar2 = '\0';
          if (local_120 != ' ') goto LAB_0007db73;
LAB_0007daf4:
          pcVar2 = &local_120;
          do {
            pcVar2 = pcVar2 + 1;
          } while (*pcVar2 == ' ');
          bVar5 = pcVar2 == (char *)0x0;
          cVar4 = *pcVar2;
        }
        if ((cVar4 != '\0') && (!bVar5)) {
          __s = ObjectList::GetFirst(&this->m_Commands);
          while (__s != (char *)0x0) {
            __n = strlen(__s);
            iVar3 = strncasecmp(__s,pcVar2,__n);
            if (iVar3 == 0) {
              (**(code **)(**(int **)(__s + 0x24) + 0x14))
                        (*(int **)(__s + 0x24),*(undefined4 *)(__s + 0x20),pcVar2);
              goto LAB_0007db15;
            }
            __s = ObjectList::GetNext(&this->m_Commands);
          }
          Cmd_ExecuteString(pcVar2,src_command);
        }
LAB_0007db15:
        if (commands[-1] == '\0') goto LAB_0007da78;
        iVar3 = 1;
        cVar4 = *commands;
        local_120 = cVar4;
        pcVar2 = &local_120;
      }
      bVar1 = (bool)(bVar1 ^ 1);
LAB_0007db39:
      if (commands[-1] == '\0') goto LAB_0007da78;
      cVar4 = *commands;
      iVar3 = iVar3 + 1;
      pcVar2[1] = cVar4;
      pcVar2 = pcVar2 + 1;
    } while (iVar3 < 0x100);
    (**(code **)((int)this->super_IBaseSystem + 0x4c))
              (this,"WARNING! System::ExecuteString: Command token too long.\n");
  }
LAB_0007da78:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SystemWrapper::FindModule  @ 0007d980
/* DWARF original prototype: ISystemModule * FindModule(SystemWrapper * this, char * type, char *
   name) */

ISystemModule * __thiscall SystemWrapper::FindModule(SystemWrapper *this,char *type,char *name)

{
  ObjectList *this_00;
  ISystemModule *pIVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: ISystemModule * module@[???] */
  if ((type != (char *)0x0) && (*type != '\0')) {
    this_00 = &this->m_Modules;
    pIVar1 = ObjectList::GetFirst(this_00);
    if (pIVar1 != (ISystemModule *)0x0) {
      if (name == (char *)0x0) {
        do {
          pcVar2 = (char *)(*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xb])(pIVar1);
          iVar3 = strcasecmp(type,pcVar2);
          if (iVar3 == 0) {
            return pIVar1;
          }
          pIVar1 = ObjectList::GetNext(this_00);
        } while (pIVar1 != (ISystemModule *)0x0);
      }
      else {
        do {
          pcVar2 = (char *)(*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xb])(pIVar1);
          iVar3 = strcasecmp(type,pcVar2);
          if (iVar3 == 0) {
            pcVar2 = (char *)(*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xc])(pIVar1);
            iVar3 = strcasecmp(name,pcVar2);
            if (iVar3 == 0) {
              return pIVar1;
            }
          }
          pIVar1 = ObjectList::GetNext(this_00);
        } while (pIVar1 != (ISystemModule *)0x0);
      }
    }
  }
  return (ISystemModule *)0x0;
}


// SystemWrapper::FreeFile  @ 0007cfd0
/* DWARF original prototype: void FreeFile(SystemWrapper * this, uchar * fileHandle) */

void __thiscall SystemWrapper::FreeFile(SystemWrapper *this,uchar *fileHandle)

{
  COM_FreeFile(fileHandle);
  return;
}


// SystemWrapper::GetCommandMatches  @ 0007cc80
/* DWARF original prototype: void GetCommandMatches(SystemWrapper * this, char * string, ObjectList
   * pMatchList) */

void __thiscall
SystemWrapper::GetCommandMatches(SystemWrapper *this,char *string,ObjectList *pMatchList)

{
                    /* WARNING: Could not recover jumptable at 0x0007cc93. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(pMatchList->super_IObjectContainer)._vptr_IObjectContainer[5])();
  return;
}


// SystemWrapper::GetFileSystem  @ 0007cc30
/* DWARF original prototype: IFileSystem * GetFileSystem(SystemWrapper * this) */

IFileSystem * __thiscall SystemWrapper::GetFileSystem(SystemWrapper *this)

{
  return g_pFileSystem;
}


// SystemWrapper::GetLibrary  @ 0007e220
/* DWARF original prototype: library_t * GetLibrary(SystemWrapper * this, char * name) */

library_t * __thiscall SystemWrapper::GetLibrary(SystemWrapper *this,char *name)

{
  library_t *__s2;
  int iVar1;
  CSysModule *pModule;
  CreateInterfaceFn p_Var2;
  IBaseSystem IVar3;
  ObjectList *this_00;
  int in_GS_OFFSET;
  char *pcVar4;
  char local_1020 [4095];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char[4096] fixedname@[???]
                       Unresolved local var: library_t * lib@[???] */
  this_00 = &this->m_Libraries;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  strncpy(local_1020,name,0xfff);
  local_21 = 0;
  COM_FixSlashes(local_1020);
  __s2 = ObjectList::GetFirst(this_00);
  while (__s2 != (library_t *)0x0) {
    iVar1 = strcasecmp(name,__s2->name);
    if (iVar1 == 0) goto LAB_0007e355;
    __s2 = ObjectList::GetNext(this_00);
  }
  __s2 = Mem_Malloc(0x1008);
  if (__s2 == (library_t *)0x0) {
    (**(code **)((int)this->super_IBaseSystem + 0x50))
              (this,"ERROR! System::GetLibrary: out of memory (%s).\n",name);
    __s2 = (library_t *)0x0;
  }
  else {
    __snprintf_chk(__s2,0x1000,1,0x1000,"%s.so",local_1020);
    FS_GetLocalCopy(__s2->name);
    pModule = Sys_LoadModule(__s2->name);
    __s2->handle = pModule;
    if (pModule == (CSysModule *)0x0) {
      IVar3 = this->super_IBaseSystem;
      pcVar4 = "ERROR! System::GetLibrary: coulnd\'t load library (%s).\n";
    }
    else {
      p_Var2 = Sys_GetFactory(pModule);
      __s2->createInterfaceFn = p_Var2;
      if (p_Var2 != (CreateInterfaceFn)0x0) {
        ObjectList::Add(this_00,__s2);
        (**(code **)((int)this->super_IBaseSystem + 0x50))(this,"Loaded library %s.\n",__s2);
        goto LAB_0007e355;
      }
      IVar3 = this->super_IBaseSystem;
      pcVar4 = "ERROR! System::GetLibrary: coulnd\'t get object factory(%s).\n";
    }
    (**(code **)((int)IVar3 + 0x50))(this,pcVar4,__s2);
    Mem_Free(__s2);
    __s2 = (library_t *)0x0;
  }
LAB_0007e355:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return __s2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SystemWrapper::GetModule  @ 0007e3d0
/* DWARF original prototype: ISystemModule * GetModule(SystemWrapper * this, char * interfacename,
   char * library, char * instancename) */

ISystemModule * __thiscall
SystemWrapper::GetModule(SystemWrapper *this,char *interfacename,char *library,char *instancename)

{
  code *pcVar1;
  SystemWrapper *in_EAX;
  library_t *plVar2;
  ISystemModule *newObject;
  int iVar3;
  char *in_ECX;
  char *in_EDX;
  
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
  plVar2 = GetLibrary(in_EAX,in_ECX);
  if (plVar2 == (library_t *)0x0) {
    newObject = (ISystemModule *)0x0;
  }
  else {
    newObject = (*plVar2->createInterfaceFn)(in_EDX,(int *)0x0);
    if (newObject == (ISystemModule *)0x0) {
      (**(code **)((int)in_EAX->super_IBaseSystem + 0x4c))();
      newObject = (ISystemModule *)0x0;
    }
    else {
      pcVar1 = *(code **)((int)in_EAX->super_IBaseSystem + 0x90);
      if (pcVar1 == AddModule) {
        iVar3 = (*(newObject->super_IBaseInterface)._vptr_IBaseInterface[2])(newObject);
        if ((char)iVar3 == '\0') {
          (**(code **)((int)in_EAX->super_IBaseSystem + 0x4c))();
        }
        else {
          ObjectList::AddHead(&in_EAX->m_Modules,newObject);
          in_EAX->m_SerialCounter = in_EAX->m_SerialCounter + 1;
        }
      }
      else {
        (*pcVar1)();
      }
    }
  }
  return newObject;
}


// SystemWrapper::GetModule  @ 0007e4e0
/* DWARF original prototype: ISystemModule * GetModule(SystemWrapper * this, char * interfacename,
   char * library, char * instancename) */

ISystemModule * __thiscall
SystemWrapper::GetModule(SystemWrapper *this,char *interfacename,char *library,char *instancename)

{
  ObjectList *this_00;
  ISystemModule *pIVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
                    /* Unresolved local var: ISystemModule * module@[???] */
  if ((interfacename != (char *)0x0) && (*interfacename != '\0')) {
    this_00 = &this->m_Modules;
    pIVar1 = ObjectList::GetFirst(this_00);
    if (pIVar1 != (ISystemModule *)0x0) {
      if (instancename == (char *)0x0) {
        do {
          pcVar2 = (char *)(*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xb])(pIVar1);
          iVar3 = strcasecmp(interfacename,pcVar2);
          if (iVar3 == 0) {
            return pIVar1;
          }
          pIVar1 = ObjectList::GetNext(this_00);
        } while (pIVar1 != (ISystemModule *)0x0);
      }
      else {
        do {
          pcVar2 = (char *)(*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xb])(pIVar1);
          iVar3 = strcasecmp(interfacename,pcVar2);
          if (iVar3 == 0) {
            pcVar2 = (char *)(*(pIVar1->super_IBaseInterface)._vptr_IBaseInterface[0xc])(pIVar1);
            iVar3 = strcasecmp(instancename,pcVar2);
            if (iVar3 == 0) {
              return pIVar1;
            }
          }
          pIVar1 = ObjectList::GetNext(this_00);
        } while (pIVar1 != (ISystemModule *)0x0);
      }
    }
  }
  pIVar1 = GetModule((SystemWrapper *)instancename,interfacename,library,instancename);
  return pIVar1;
}


// SystemWrapper::GetStatusLine  @ 0007cbc0
/* DWARF original prototype: char * GetStatusLine(SystemWrapper * this) */

char * __thiscall SystemWrapper::GetStatusLine(SystemWrapper *this)

{
  return "No status available.\n";
}


// SystemWrapper::GetStatusLine  @ 0007cbf0
/* virtual thunk to SystemWrapper::GetStatusLine() */

void __thiscall SystemWrapper::GetStatusLine(SystemWrapper *this)

{
  GetStatusLine((SystemWrapper *)
                ((this->super_BaseSystemModule).m_Name +
                *(int *)((int)this->super_IBaseSystem + -0x30) + -0x20));
  return;
}


// SystemWrapper::GetStatusLine  @ 0007cc00
/* non-virtual thunk to SystemWrapper::GetStatusLine() */

void __thiscall SystemWrapper::GetStatusLine(SystemWrapper *this)

{
  GetStatusLine((SystemWrapper *)&this[-1].m_EngineWrapper);
  return;
}


// SystemWrapper::GetTick  @ 0007cc40
/* DWARF original prototype: uint GetTick(SystemWrapper * this) */

uint __thiscall SystemWrapper::GetTick(SystemWrapper *this)

{
  return this->m_Tick;
}


// SystemWrapper::GetTime  @ 0007cc20
/* DWARF original prototype: double GetTime(SystemWrapper * this) */

double __thiscall SystemWrapper::GetTime(SystemWrapper *this)

{
  return (this->super_BaseSystemModule).m_SystemTime;
}


// SystemWrapper::GetType  @ 0007cc50
/* DWARF original prototype: char * GetType(SystemWrapper * this) */

char * __thiscall SystemWrapper::GetType(SystemWrapper *this)

{
  return "basesystem002";
}


// SystemWrapper::GetType  @ 0007cc60
/* virtual thunk to SystemWrapper::GetType() */

void __thiscall SystemWrapper::GetType(SystemWrapper *this)

{
  GetType((SystemWrapper *)
          ((this->super_BaseSystemModule).m_Name +
          *(int *)((int)this->super_IBaseSystem + -0x34) + -0x20));
  return;
}


// SystemWrapper::GetType  @ 0007cc70
/* non-virtual thunk to SystemWrapper::GetType() */

void __thiscall SystemWrapper::GetType(SystemWrapper *this)

{
  GetType((SystemWrapper *)&this[-1].m_EngineWrapper);
  return;
}


// SystemWrapper::Init  @ 0007d5a0
/* DWARF original prototype: bool Init(SystemWrapper * this, IBaseSystem * system, int serial, char
   * name) */

bool __thiscall SystemWrapper::Init(SystemWrapper *this,IBaseSystem *system,int serial,char *name)

{
  IBaseSystem IVar1;
  code *pcVar2;
  IEngineWrapper *pIVar3;
  
  BaseSystemModule::Init(&this->super_BaseSystemModule,system,serial,name);
  ObjectList::Init(&this->m_Commands);
  ObjectList::Init(&this->m_Modules);
  ObjectList::Init(&this->m_Libraries);
  ObjectList::Init(&(this->super_BaseSystemModule).m_Listener);
  pIVar3 = operator_new(0x130);
  pIVar3[1]._vptr_IEngineWrapper = (_func_int_varargs **)&DAT_000d8228;
  pIVar3->_vptr_IEngineWrapper = (_func_int_varargs **)&DAT_000d8270;
  BaseSystemModule::BaseSystemModule((BaseSystemModule *)(pIVar3 + 1),0xd8378,(void **)serial);
  IVar1 = this->super_IBaseSystem;
  pIVar3->_vptr_IEngineWrapper = (_func_int_varargs **)(EngineWrapper::vtable + 0xc);
  pIVar3[1]._vptr_IEngineWrapper = (_func_int_varargs **)(EngineWrapper::vtable + 0xcc);
  this->m_EngineWrapper = pIVar3;
  pcVar2 = *(code **)((int)IVar1 + 0x90);
  if (pcVar2 != AddModule) {
    (*pcVar2)(this,pIVar3,"enginewrapper002");
  }
  (this->super_BaseSystemModule).m_State = 3;
  return true;
}


// SystemWrapper::Init  @ 0007d690
/* virtual thunk to SystemWrapper::Init(IBaseSystem*, int, char*) */

void __thiscall
SystemWrapper::Init(SystemWrapper *this,IBaseSystem *param_1,int param_2,char *param_3)

{
  Init((SystemWrapper *)
       ((this->super_BaseSystemModule).m_Name +
       *(int *)((int)this->super_IBaseSystem + -0x10) + -0x20),param_1,param_2,param_3);
  return;
}


// SystemWrapper::Init  @ 0007d6b0
/* non-virtual thunk to SystemWrapper::Init(IBaseSystem*, int, char*) */

void __thiscall
SystemWrapper::Init(SystemWrapper *this,IBaseSystem *param_1,int param_2,char *param_3)

{
  Init((SystemWrapper *)&this[-1].m_EngineWrapper,param_1,param_2,param_3);
  return;
}


// SystemWrapper::InitVGUI  @ 0007cca0
/* DWARF original prototype: bool InitVGUI(SystemWrapper * this, IVGuiModule * module) */

bool __thiscall SystemWrapper::InitVGUI(SystemWrapper *this,IVGuiModule *module)

{
  return false;
}


// SystemWrapper::LoadFile  @ 0007cfb0
/* DWARF original prototype: uchar * LoadFile(SystemWrapper * this, char * name, int * length) */

uchar * __thiscall SystemWrapper::LoadFile(SystemWrapper *this,char *name,int *length)

{
  byte *pbVar1;
  
                    /* Unresolved local var: uchar * buffer@[???] */
  pbVar1 = COM_LoadFile(name,5,length);
  return pbVar1;
}


// SystemWrapper::LogConsole  @ 0007cfe0
/* DWARF original prototype: void LogConsole(SystemWrapper * this, char * filename) */

void __thiscall SystemWrapper::LogConsole(SystemWrapper *this,char *filename)

{
  if (filename != (char *)0x0) {
    Cmd_ExecuteString("log on",src_command);
    return;
  }
  Cmd_ExecuteString("log off",src_command);
  return;
}


// SystemWrapper::Printf  @ 0007ce70
/* DWARF original prototype: void Printf(SystemWrapper * this, char * fmt, ...) */

void __thiscall SystemWrapper::Printf(SystemWrapper *this,char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  __vsnprintf_chk(Printf::string,0x2000,1,0x2000,fmt,&stack0x0000000c);
  Con_Printf("%s",Printf::string);
  return;
}


// SystemWrapper::RedirectOutput  @ 0007ce60
/* DWARF original prototype: void RedirectOutput(SystemWrapper * this, char * buffer, int maxSize)
    */

void __thiscall SystemWrapper::RedirectOutput(SystemWrapper *this,char *buffer,int maxSize)

{
  Con_Printf("WARNIG! SystemWrapper::RedirectOutput: not implemented.\n");
  return;
}


// SystemWrapper::RegisterCommand  @ 0007eab0
/* DWARF original prototype: bool RegisterCommand(SystemWrapper * this, char * name, ISystemModule *
   module, int commandID) */

bool __thiscall
SystemWrapper::RegisterCommand(SystemWrapper *this,char *name,ISystemModule *module,int commandID)

{
  ObjectList *this_00;
  char *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: command_t * cmd@[???] */
  this_00 = &this->m_Commands;
  pcVar1 = ObjectList::GetFirst(this_00);
  while( true ) {
    if (pcVar1 == (char *)0x0) {
      pcVar1 = Mem_ZeroMalloc(0x28);
      strncpy(pcVar1,name,0x20);
      pcVar1[0x1f] = '\0';
      *(ISystemModule **)(pcVar1 + 0x24) = module;
      *(int *)(pcVar1 + 0x20) = commandID;
      ObjectList::Add(this_00,pcVar1);
      Cmd_AddWrapperCommand(pcVar1,SystemWrapperCommandForwarder);
      return true;
    }
    iVar2 = strcasecmp(pcVar1,name);
    if (iVar2 == 0) break;
    pcVar1 = ObjectList::GetNext(this_00);
  }
  (**(code **)((int)this->super_IBaseSystem + 0x4c))
            (this,"WARNING! System::RegisterCommand: command \"%s\" already exists.\n",name);
  return false;
}


// SystemWrapper::RemoveModule  @ 0007ecc0
/* DWARF original prototype: bool RemoveModule(SystemWrapper * this, ISystemModule * module) */

bool __thiscall SystemWrapper::RemoveModule(SystemWrapper *this,ISystemModule *module)

{
  ObjectList *pOVar1;
  void *object;
  int *object_00;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: command_t * cmd@[???]
                       Unresolved local var: ISystemModule * mod@[???] */
  if (module == (ISystemModule *)0x0) {
    return true;
  }
  (*(module->super_IBaseInterface)._vptr_IBaseInterface[0xf])(module);
  pOVar1 = &this->m_Commands;
  object = ObjectList::GetFirst(pOVar1);
  while (object != (void *)0x0) {
    while( true ) {
      iVar2 = (**(code **)(**(int **)((int)object + 0x24) + 0x24))(*(int **)((int)object + 0x24));
      iVar3 = (*(module->super_IBaseInterface)._vptr_IBaseInterface[9])(module);
      if (iVar2 != iVar3) break;
      ObjectList::Remove(pOVar1,object);
      Mem_Free(object);
      object = ObjectList::GetNext(pOVar1);
      if (object == (void *)0x0) goto LAB_0007ed50;
    }
    object = ObjectList::GetNext(pOVar1);
  }
LAB_0007ed50:
  pOVar1 = &this->m_Modules;
  object_00 = ObjectList::GetFirst(pOVar1);
  while( true ) {
    if (object_00 == (int *)0x0) {
      return false;
    }
    iVar2 = (**(code **)(*object_00 + 0x24))(object_00);
    iVar3 = (*(module->super_IBaseInterface)._vptr_IBaseInterface[9])(module);
    if (iVar2 == iVar3) break;
    object_00 = ObjectList::GetNext(pOVar1);
  }
  ObjectList::Remove(pOVar1,object_00);
  return true;
}


// SystemWrapper::RunFrame  @ 0007d8c0
/* DWARF original prototype: void RunFrame(SystemWrapper * this, double time) */

void __thiscall SystemWrapper::RunFrame(SystemWrapper *this,double time)

{
  double dVar1;
  int *piVar2;
  
                    /* Unresolved local var: ISystemModule * module@[???] */
  dVar1 = (this->super_BaseSystemModule).m_SystemTime;
  this->m_Tick = this->m_Tick + 1;
  (this->super_BaseSystemModule).m_SystemTime = dVar1 + time;
  if ((this->super_BaseSystemModule).m_State == 3) {
                    /* Unresolved local var: ISystemModule * module@[???] */
    piVar2 = ObjectList::GetFirst(&this->m_Modules);
    while ((piVar2 != (int *)0x0 && ((this->super_BaseSystemModule).m_State != 4))) {
      (**(code **)(*piVar2 + 0xc))(piVar2,(this->super_BaseSystemModule).m_SystemTime);
      piVar2 = ObjectList::GetNext(&this->m_Modules);
    }
    this->m_LastTime = (this->super_BaseSystemModule).m_SystemTime;
    return;
  }
  return;
}


// SystemWrapper::RunFrame  @ 0007d950
/* virtual thunk to SystemWrapper::RunFrame(double) */

void __thiscall SystemWrapper::RunFrame(SystemWrapper *this,double param_1)

{
  RunFrame((SystemWrapper *)
           ((this->super_BaseSystemModule).m_Name +
           *(int *)((int)this->super_IBaseSystem + -0x14) + -0x20),param_1);
  return;
}


// SystemWrapper::RunFrame  @ 0007d970
/* non-virtual thunk to SystemWrapper::RunFrame(double) */

void __thiscall SystemWrapper::RunFrame(SystemWrapper *this,double param_1)

{
  RunFrame((SystemWrapper *)&this[-1].m_EngineWrapper,param_1);
  return;
}


// SystemWrapper::SetFPS  @ 0007ede0
/* DWARF original prototype: void SetFPS(SystemWrapper * this, float fps) */

void __thiscall SystemWrapper::SetFPS(SystemWrapper *this,float fps)

{
  return;
}


// SystemWrapper::SetStatusLine  @ 0007ce50
/* DWARF original prototype: void SetStatusLine(SystemWrapper * this, char * text) */

void __thiscall SystemWrapper::SetStatusLine(SystemWrapper *this,char *text)

{
  Con_Printf("TODO: SystemWrapper::SetStatusLine ?\n");
  return;
}


// SystemWrapper::SetTitle  @ 0007ce40
/* DWARF original prototype: void SetTitle(SystemWrapper * this, char * text) */

void __thiscall SystemWrapper::SetTitle(SystemWrapper *this,char *text)

{
  Con_Printf("TODO: SystemWrapper::SetTitle ?\n");
  return;
}


// SystemWrapper::ShowConsole  @ 0007edf0
/* DWARF original prototype: void ShowConsole(SystemWrapper * this, bool visible) */

void __thiscall SystemWrapper::ShowConsole(SystemWrapper *this,bool visible)

{
  return;
}


// SystemWrapper::ShutDown  @ 0007d780
/* DWARF original prototype: void ShutDown(SystemWrapper * this) */

void __thiscall SystemWrapper::ShutDown(SystemWrapper *this)

{
  IEngineWrapper *pIVar1;
  int *piVar2;
  void *p;
  void **in_stack_ffffffec;
  
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
  ObjectList::Clear(&(this->super_BaseSystemModule).m_Listener,false);
  ObjectList::Clear(&this->m_Commands,true);
  while( true ) {
    piVar2 = ObjectList::GetFirst(&this->m_Modules);
    if (piVar2 == (int *)0x0) break;
    (**(code **)(*piVar2 + 0x3c))(piVar2);
  }
  while( true ) {
    p = ObjectList::RemoveTail(&this->m_Libraries);
    if (p == (void *)0x0) break;
    if (*(CSysModule **)((int)p + 0x1000) != (CSysModule *)0x0) {
      Sys_UnloadModule(*(CSysModule **)((int)p + 0x1000));
    }
    Mem_Free(p);
  }
  pIVar1 = this->m_EngineWrapper;
  if (pIVar1 != (IEngineWrapper *)0x0) {
    if (pIVar1->_vptr_IEngineWrapper[1] == EngineWrapper::~EngineWrapper) {
      pIVar1->_vptr_IEngineWrapper = (_func_int_varargs **)(EngineWrapper::vtable + 0xc);
      pIVar1[1]._vptr_IEngineWrapper = (_func_int_varargs **)(EngineWrapper::vtable + 0xcc);
      BaseSystemModule::~BaseSystemModule
                ((BaseSystemModule *)(pIVar1 + 1),0xd8378,in_stack_ffffffec);
      operator_delete(pIVar1);
    }
    else {
      (*pIVar1->_vptr_IEngineWrapper[1])(pIVar1);
    }
  }
  Cmd_RemoveWrapperCmds();
  (this->super_BaseSystemModule).m_State = 4;
  return;
}


// SystemWrapper::ShutDown  @ 0007d870
/* virtual thunk to SystemWrapper::ShutDown() */

void __thiscall SystemWrapper::ShutDown(SystemWrapper *this)

{
  ShutDown((SystemWrapper *)
           ((this->super_BaseSystemModule).m_Name +
           *(int *)((int)this->super_IBaseSystem + -0x44) + -0x20));
  return;
}


// SystemWrapper::ShutDown  @ 0007d890
/* non-virtual thunk to SystemWrapper::ShutDown() */

void __thiscall SystemWrapper::ShutDown(SystemWrapper *this)

{
  ShutDown((SystemWrapper *)&this[-1].m_EngineWrapper);
  return;
}


// SystemWrapper::Stop  @ 0007cc10
/* DWARF original prototype: void Stop(SystemWrapper * this) */

void __thiscall SystemWrapper::Stop(SystemWrapper *this)

{
  (this->super_BaseSystemModule).m_State = 4;
  return;
}


// SystemWrapper::SystemWrapper  @ 0007d280
/* DWARF original prototype: void SystemWrapper(SystemWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall SystemWrapper::SystemWrapper(SystemWrapper *this,int __in_chrg,void **__vtt_parm)

{
  IBaseSystem IVar1;
  void **in_stack_ffffffcc;
  
  IVar1 = *(IBaseSystem *)(__in_chrg + 4);
  this->super_IBaseSystem = IVar1;
  *(undefined4 *)((this->super_BaseSystemModule).m_Name + *(int *)((int)IVar1 + -0x48) + -0x20) =
       *(undefined4 *)(__in_chrg + 8);
  BaseSystemModule::BaseSystemModule
            (&this->super_BaseSystemModule,__in_chrg + 0xc,in_stack_ffffffcc);
  IVar1 = *(IBaseSystem *)__in_chrg;
  this->super_IBaseSystem = IVar1;
  *(undefined4 *)((this->super_BaseSystemModule).m_Name + *(int *)((int)IVar1 + -0x48) + -0x20) =
       *(undefined4 *)(__in_chrg + 0x14);
  *(undefined4 *)&this->super_BaseSystemModule = *(undefined4 *)(__in_chrg + 0x18);
  ObjectList::ObjectList(&this->m_Modules);
  ObjectList::ObjectList(&this->m_Libraries);
  ObjectList::ObjectList(&this->m_Commands);
  return;
}


// SystemWrapper::SystemWrapper  @ 0007d370
/* DWARF original prototype: void SystemWrapper(SystemWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall SystemWrapper::SystemWrapper(SystemWrapper *this,int __in_chrg,void **__vtt_parm)

{
  void **in_stack_ffffffdc;
  
  this->super_IBaseSystem = (IBaseSystem)&DAT_000d85f0;
  BaseSystemModule::BaseSystemModule(&this->super_BaseSystemModule,0xd86a0,in_stack_ffffffdc);
  this->super_IBaseSystem = (IBaseSystem)0xd86f8;
  *(undefined4 *)&this->super_BaseSystemModule = 0xd87e4;
  ObjectList::ObjectList(&this->m_Modules);
  ObjectList::ObjectList(&this->m_Libraries);
  ObjectList::ObjectList(&this->m_Commands);
  return;
}


// SystemWrapper::~SystemWrapper  @ 0007d430
/* DWARF original prototype: void ~SystemWrapper(SystemWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall SystemWrapper::~SystemWrapper(SystemWrapper *this,int __in_chrg,void **__vtt_parm)

{
  IBaseSystem IVar1;
  int in_stack_ffffffe8;
  void **in_stack_ffffffec;
  
  IVar1 = *(IBaseSystem *)__in_chrg;
  this->super_IBaseSystem = IVar1;
  *(undefined4 *)((this->super_BaseSystemModule).m_Name + *(int *)((int)IVar1 + -0x48) + -0x20) =
       *(undefined4 *)(__in_chrg + 0x14);
  *(undefined4 *)&this->super_BaseSystemModule = *(undefined4 *)(__in_chrg + 0x18);
  ObjectList::~ObjectList(&this->m_Commands,in_stack_ffffffe8);
  ObjectList::~ObjectList(&this->m_Libraries,in_stack_ffffffe8);
  ObjectList::~ObjectList(&this->m_Modules,in_stack_ffffffe8);
  BaseSystemModule::~BaseSystemModule
            (&this->super_BaseSystemModule,__in_chrg + 0xc,in_stack_ffffffec);
  IVar1 = *(IBaseSystem *)(__in_chrg + 4);
  this->super_IBaseSystem = IVar1;
  *(undefined4 *)((this->super_BaseSystemModule).m_Name + *(int *)((int)IVar1 + -0x48) + -0x20) =
       *(undefined4 *)(__in_chrg + 8);
  return;
}


// SystemWrapper::~SystemWrapper  @ 0007d4a0
/* DWARF original prototype: void ~SystemWrapper(SystemWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall SystemWrapper::~SystemWrapper(SystemWrapper *this,int __in_chrg,void **__vtt_parm)

{
  int in_stack_ffffffe8;
  void **in_stack_ffffffec;
  
  this->super_IBaseSystem = (IBaseSystem)0xd86f8;
  *(undefined4 *)&this->super_BaseSystemModule = 0xd87e4;
  ObjectList::~ObjectList(&this->m_Commands,in_stack_ffffffe8);
  ObjectList::~ObjectList(&this->m_Libraries,in_stack_ffffffe8);
  ObjectList::~ObjectList(&this->m_Modules,in_stack_ffffffe8);
  BaseSystemModule::~BaseSystemModule(&this->super_BaseSystemModule,0xd86a0,in_stack_ffffffec);
  return;
}


// SystemWrapper::~SystemWrapper  @ 0007d500
/* virtual thunk to SystemWrapper::~SystemWrapper() */

void __thiscall SystemWrapper::~SystemWrapper(SystemWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~SystemWrapper((SystemWrapper *)
                 ((this->super_BaseSystemModule).m_Name +
                 *(int *)((int)this->super_IBaseSystem + -0xc) + -0x20),in_stack_00000008,
                 in_stack_0000000c);
  return;
}


// SystemWrapper::~SystemWrapper  @ 0007d510
/* non-virtual thunk to SystemWrapper::~SystemWrapper() */

void __thiscall SystemWrapper::~SystemWrapper(SystemWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~SystemWrapper((SystemWrapper *)&this[-1].m_EngineWrapper,in_stack_00000008,in_stack_0000000c);
  return;
}


// SystemWrapper::~SystemWrapper  @ 0007d520
/* DWARF original prototype: void ~SystemWrapper(SystemWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall SystemWrapper::~SystemWrapper(SystemWrapper *this,int __in_chrg,void **__vtt_parm)

{
  int in_stack_ffffffe8;
  void **in_stack_ffffffec;
  
  this->super_IBaseSystem = (IBaseSystem)0xd86f8;
  *(undefined4 *)&this->super_BaseSystemModule = 0xd87e4;
  ObjectList::~ObjectList(&this->m_Commands,in_stack_ffffffe8);
  ObjectList::~ObjectList(&this->m_Libraries,in_stack_ffffffe8);
  ObjectList::~ObjectList(&this->m_Modules,in_stack_ffffffe8);
  BaseSystemModule::~BaseSystemModule(&this->super_BaseSystemModule,0xd86a0,in_stack_ffffffec);
  operator_delete(this);
  return;
}


// SystemWrapper::~SystemWrapper  @ 0007d580
/* virtual thunk to SystemWrapper::~SystemWrapper() */

void __thiscall SystemWrapper::~SystemWrapper(SystemWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~SystemWrapper((SystemWrapper *)
                 ((this->super_BaseSystemModule).m_Name +
                 *(int *)((int)this->super_IBaseSystem + -0xc) + -0x20),in_stack_00000008,
                 in_stack_0000000c);
  return;
}


// SystemWrapper::~SystemWrapper  @ 0007d590
/* non-virtual thunk to SystemWrapper::~SystemWrapper() */

void __thiscall SystemWrapper::~SystemWrapper(SystemWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~SystemWrapper((SystemWrapper *)&this[-1].m_EngineWrapper,in_stack_00000008,in_stack_0000000c);
  return;
}


// SystemWrapperCommandForwarder  @ 0007dd70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SystemWrapperCommandForwarder(void)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  undefined2 *puVar4;
  int iVar5;
  char *pcVar6;
  char *__s;
  size_t __n;
  char cVar7;
  int in_GS_OFFSET;
  bool bVar8;
  char local_520;
  char local_51f [255];
  char local_420 [1023];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char[1024] cmd@[???] */
  pcVar6 = local_420;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar3 = Cmd_Argv(0);
  puVar4 = (undefined2 *)__stpcpy_chk(pcVar6,pcVar3,0x400);
  iVar5 = Cmd_Argc();
  if (1 < iVar5) {
    *puVar4 = 0x20;
    pcVar3 = Cmd_Args();
    __strcpy_chk((int)puVar4 + 1,pcVar3,0x400);
  }
                    /* Unresolved local var: char[256] singleCmd@[???]
                       Unresolved local var: bool quotes@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char * c@[???] */
  local_21 = 0;
  cVar7 = local_420[0];
  if (local_420[0] != '\0') {
    do {
      if ((cVar7 == '%') || (cVar7 < ' ')) {
        *pcVar6 = ' ';
      }
      pcVar6 = pcVar6 + 1;
    } while ((pcVar6 != (char *)0x0) &&
            (cVar7 = *pcVar6, cVar7 != '\0'
                    /* Unresolved local var: char * c@[???] */));
    pcVar6 = local_420;
    iVar5 = 1;
    bVar1 = false;
    pcVar3 = &local_520;
    local_520 = local_420[0];
    cVar7 = local_420[0];
    do {
      while (pcVar6 = pcVar6 + 1, cVar7 != '\"') {
        if (cVar7 == ';') {
          if (bVar1) goto LAB_0007deb8;
          *pcVar3 = '\0';
          if (local_520 == ' ') goto LAB_0007de75;
LAB_0007deeb:
          bVar8 = false;
          pcVar3 = &local_520;
          cVar2 = local_520;
        }
        else {
          if (cVar7 != '\0') goto LAB_0007deb8;
          *pcVar3 = '\0';
          if (local_520 != ' ') goto LAB_0007deeb;
LAB_0007de75:
          pcVar3 = &local_520;
          do {
            pcVar3 = pcVar3 + 1;
          } while (*pcVar3 == ' ');
          bVar8 = pcVar3 == (char *)0x0;
          cVar2 = *pcVar3;
        }
                    /* Unresolved local var: command_t * cmd@[???] */
        if ((cVar2 != '\0') && (!bVar8)) {
                    /* Unresolved local var: command_t * cmd@[???] */
          __s = ObjectList::GetFirst(&gSystemWrapper.m_Commands);
          while (__s != (char *)0x0) {
            __n = strlen(__s);
            iVar5 = strncasecmp(__s,pcVar3,__n);
            if (iVar5 == 0) {
              (**(code **)(**(int **)(__s + 0x24) + 0x14))
                        (*(int **)(__s + 0x24),*(undefined4 *)(__s + 0x20),pcVar3);
              goto LAB_0007de95;
            }
            __s = ObjectList::GetNext(&gSystemWrapper.m_Commands);
          }
          Cmd_ExecuteString(pcVar3,src_command);
        }
LAB_0007de95:
        if (cVar7 == '\0') goto LAB_0007ddf4;
        iVar5 = 1;
        local_520 = *pcVar6;
        pcVar3 = &local_520;
        cVar7 = local_520;
      }
      bVar1 = (bool)(bVar1 ^ 1);
LAB_0007deb8:
      cVar7 = *pcVar6;
      iVar5 = iVar5 + 1;
      pcVar3[1] = cVar7;
      pcVar3 = pcVar3 + 1;
    } while (iVar5 < 0x100);
    SystemWrapper::Printf
              (&gSystemWrapper,"WARNING! System::ExecuteString: Command token too long.\n");
  }
LAB_0007ddf4:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SzFromIndex  @ 000756f0
char * SzFromIndex(int iString)

{
  return pr_strings + iString;
}


// TextMessageGet  @ 000a5fc0
client_textmessage_t * TextMessageGet(char *pName)

{
  int iVar1;
  int iVar2;
  client_textmessage_t *pcVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  (*g_engdstAddrs.pfnTextMessageGet)(&pName);
  iVar1 = Q_stricmp(pName,"__NETMESSAGE__1");
  pcVar3 = gNetworkTextMessage;
  if (iVar1 != 0) {
    iVar1 = Q_stricmp(pName,"__NETMESSAGE__2");
    pcVar3 = gNetworkTextMessage + 1;
    if (iVar1 != 0) {
      iVar1 = Q_stricmp(pName,"__NETMESSAGE__3");
      pcVar3 = gNetworkTextMessage + 2;
      if (iVar1 != 0) {
        iVar1 = Q_stricmp(pName,"__NETMESSAGE__4");
        pcVar3 = gNetworkTextMessage + 3;
        if (iVar1 != 0) {
          if ((gMessageTable != (client_textmessage_t *)0x0) && (0 < gMessageTableCount)) {
            iVar1 = 0;
            iVar4 = 0;
            do {
              iVar2 = Q_stricmp(pName,*(char **)((int)&gMessageTable->pName + iVar1));
              if (iVar2 == 0) {
                return (client_textmessage_t *)((int)&gMessageTable->effect + iVar1);
              }
              iVar4 = iVar4 + 1;
              iVar1 = iVar1 + 0x2c;
            } while (iVar4 < gMessageTableCount);
          }
          pcVar3 = (client_textmessage_t *)0x0;
        }
      }
    }
  }
  return pcVar3;
}


// TextMessageInit  @ 000a5f80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void TextMessageInit(void)

{
  byte *pMemFile;
  int local_10 [4];
  
                    /* Unresolved local var: int fileSize@[???]
                       Unresolved local var: byte * pMemFile@[???] */
  if (gMessageTable != (client_textmessage_t *)0x0) {
    Mem_Free(gMessageTable);
    gMessageTable = (client_textmessage_t *)0x0;
  }
  pMemFile = COM_LoadTempFile("titles.txt",local_10);
  if (pMemFile != (byte *)0x0) {
    TextMessageParse(pMemFile,local_10[0]);
  }
  return;
}


// TextMessageParse  @ 000a53b0
void __regparm3 TextMessageParse(byte *pMemFile,int fileSize)

{
  byte *pbVar1;
  char *pcVar2;
  bool bVar3;
  client_textmessage_t *pcVar4;
  int iVar5;
  uint uVar6;
  size_t size;
  int iVar7;
  int iVar8;
  void *dest;
  char *pcVar9;
  int *piVar10;
  int in_GS_OFFSET;
  int local_f240;
  int local_f238;
  size_t local_f234;
  byte *local_f230;
  float local_f220;
  float local_f21c;
  float local_f218;
  undefined4 local_f200 [9];
  int aiStack_f1dc [10991];
  char local_4620;
  undefined1 local_461f [511];
  char local_4420;
  char local_441f [511];
  char local_4220 [511];
  undefined1 local_4021;
  char local_4020 [16384];
  int local_20;
  
                    /* Unresolved local var: char[512] buf@[???]
                       Unresolved local var: char[512] trim@[???]
                       Unresolved local var: char * pCurrentText@[???]
                       Unresolved local var: char * pNameHeap@[???]
                       Unresolved local var: char[512] currentName@[???]
                       Unresolved local var: char[16384] nameHeap@[???]
                       Unresolved local var: int lastNamePos@[???]
                       Unresolved local var: int mode@[???]
                       Unresolved local var: int lineNumber@[???]
                       Unresolved local var: int filePos@[???]
                       Unresolved local var: int lastLinePos@[???]
                       Unresolved local var: int messageCount@[???]
                       Unresolved local var: client_textmessage_t[1000] textMessages@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int nameHeapSize@[???]
                       Unresolved local var: int textHeapSize@[???]
                       Unresolved local var: int messageSize@[???]
                       Unresolved local var: int nameOffset@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: int filePos@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int last@[???]
                       Unresolved local var: int stop@[???] */
  if ((fileSize < 1) || (pMemFile == (byte *)0x0)) {
    iVar8 = 0;
    local_f240 = 0;
    Con_DPrintf("Parsed %d text messages\n",0);
    size = 0;
    local_f234 = 0;
  }
  else {
    local_f240 = 0;
    local_f238 = 0;
    bVar3 = false;
    local_f234 = 0;
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0x1ff;
      if (fileSize - iVar8 < 0x200) {
        iVar5 = fileSize;
      }
      iVar7 = iVar8;
      if (iVar5 <= iVar8) break;
      do {
        pbVar1 = pMemFile + iVar7;
        iVar7 = iVar7 + 1;
        if (iVar5 <= iVar7) break;
      } while (*pbVar1 != '\n');
      if (iVar7 == iVar8) break;
                    /* Unresolved local var: int size@[???] */
      iVar5 = iVar7 - iVar8;
      Q_memcpy(&local_4620,pMemFile + iVar8,iVar5);
      if (iVar5 < 0x200) {
        local_461f[iVar5 + -1] = 0;
      }
      if (999 < local_f240) {
        Sys_Error("tmessage::TextMessageParse : messageCount>=MAX_MESSAGES");
      }
      TrimSpace(&local_4620,&local_4420);
      if (bVar3) {
        if (bVar3) {
          if (local_4420 == '}') {
                    /* Unresolved local var: int length@[???] */
            iVar5 = Q_strlen(local_4220);
            if (0x4000 < (int)(iVar5 + local_f234)) {
              Con_DPrintf("Error parsing file!  length > %i bytes\n",0x4000);
              iVar8 = gMessageTableCount;
              goto LAB_000a563c;
            }
            Q_strcpy(local_4020 + local_f234,local_4220);
            pMemFile[iVar8 + -1] = '\0';
            uVar6 = 0;
            do {
              *(undefined4 *)((int)local_f200 + uVar6 + local_f240 * 0x2c) =
                   *(undefined4 *)((int)&gMessageParms.effect + uVar6);
              uVar6 = uVar6 + 4;
            } while (uVar6 < 0x2c);
            aiStack_f1dc[local_f240 * 0xb] = (int)(local_4020 + local_f234);
            iVar8 = Q_strlen(local_4220);
            local_f234 = local_f234 + 1 + iVar8;
            aiStack_f1dc[local_f240 * 0xb + 1] = (int)local_f230;
            bVar3 = false;
            local_f240 = local_f240 + 1;
          }
          else if (local_4420 == '{') {
            Con_DPrintf("Unexpected \'{\' found, line %d\n",local_f238);
            iVar8 = gMessageTableCount;
            goto LAB_000a563c;
          }
        }
      }
      else {
                    /* Unresolved local var: int length@[???] */
        iVar8 = Q_strlen(&local_4420);
        if (iVar8 < 2) {
          if (iVar8 == 1) goto LAB_000a54ee;
        }
        else if (local_4420 == '/') {
          if (local_441f[0] == '/') goto LAB_000a54b6;
LAB_000a5746:
          Q_strncpy(local_4220,&local_4420,0x1ff);
          local_4021 = 0;
        }
        else {
LAB_000a54ee:
          if (local_4420 == '$') {
                    /* Unresolved local var: float[8] tempFloat@[???] */
            iVar8 = Q_strlen("position");
            iVar8 = Q_strnicmp(local_441f,"position",iVar8);
            if (iVar8 == 0) {
              iVar8 = ParseFloats(&local_4420,&local_f220,2);
              if (iVar8 != 0) {
                gMessageParms.x = local_f220;
                gMessageParms.y = local_f21c;
              }
            }
            else {
              iVar8 = Q_strlen("effect");
              iVar8 = Q_strnicmp(local_441f,"effect",iVar8);
              if (iVar8 == 0) {
                iVar8 = ParseFloats(&local_4420,&local_f220,1);
                if (iVar8 != 0) {
                  gMessageParms.effect = (int)local_f220;
                }
              }
              else {
                iVar8 = Q_strlen("fxtime");
                iVar8 = Q_strnicmp(local_441f,"fxtime",iVar8);
                if (iVar8 == 0) {
                  iVar8 = ParseFloats(&local_4420,&local_f220,1);
                  if (iVar8 != 0) {
                    gMessageParms.fxtime = local_f220;
                  }
                }
                else {
                  iVar8 = Q_strlen("color2");
                  iVar8 = Q_strnicmp(local_441f,"color2",iVar8);
                  if (iVar8 == 0) {
                    iVar8 = ParseFloats(&local_4420,&local_f220,3);
                    if (iVar8 != 0) {
                      gMessageParms.r2 = (byte)(int)local_f220;
                      gMessageParms.g2 = (byte)(int)local_f21c;
                      gMessageParms.b2 = (byte)(int)local_f218;
                    }
                  }
                  else {
                    iVar8 = Q_strlen("color");
                    iVar8 = Q_strnicmp(local_441f,"color",iVar8);
                    if (iVar8 == 0) {
                      iVar8 = ParseFloats(&local_4420,&local_f220,3);
                      if (iVar8 != 0) {
                        gMessageParms.r1 = (byte)(int)local_f220;
                        gMessageParms.g1 = (byte)(int)local_f21c;
                        gMessageParms.b1 = (byte)(int)local_f218;
                      }
                    }
                    else {
                      iVar8 = Q_strlen("fadein");
                      iVar8 = Q_strnicmp(local_441f,"fadein",iVar8);
                      if (iVar8 == 0) {
                        iVar8 = ParseFloats(&local_4420,&local_f220,1);
                        if (iVar8 != 0) {
                          gMessageParms.fadein = local_f220;
                        }
                      }
                      else {
                        iVar8 = Q_strlen("fadeout");
                        iVar8 = Q_strnicmp(local_441f,"fadeout",iVar8);
                        if (iVar8 == 0) {
                          iVar8 = ParseFloats(&local_4420,&local_f220,3);
                          if (iVar8 != 0) {
                            gMessageParms.fadeout = local_f220;
                          }
                        }
                        else {
                          iVar8 = Q_strlen("holdtime");
                          iVar8 = Q_strnicmp(local_441f,"holdtime",iVar8);
                          if (iVar8 == 0) {
                            iVar8 = ParseFloats(&local_4420,&local_f220,3);
                            if (iVar8 != 0) {
                              gMessageParms.holdtime = local_f220;
                            }
                          }
                          else {
                            Con_DPrintf("Unknown token: %s\n",&local_4420);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else {
            if (local_4420 != '{') {
              if (local_4420 != '}') goto LAB_000a5746;
              Con_DPrintf("Unexpected \'}\' found, line %d\n",local_f238);
              iVar8 = gMessageTableCount;
              goto LAB_000a563c;
            }
            local_f230 = pMemFile + iVar7;
            bVar3 = true;
          }
        }
      }
LAB_000a54b6:
      local_f238 = local_f238 + 1;
      iVar8 = iVar7;
    } while (iVar7 < fileSize);
    Con_DPrintf("Parsed %d text messages\n",local_f240);
    if (local_f240 == 0) {
      iVar8 = 0;
      size = local_f234;
    }
    else {
      piVar10 = aiStack_f1dc + 1;
      iVar5 = 0;
      iVar8 = 0;
      do {
        pcVar9 = (char *)*piVar10;
        iVar8 = iVar8 + 1;
        piVar10 = piVar10 + 0xb;
        iVar7 = Q_strlen(pcVar9);
        iVar5 = iVar5 + 1 + iVar7;
      } while (iVar8 != local_f240);
      iVar8 = local_f240 * 0x2c;
      size = local_f234 + iVar5 + iVar8;
    }
  }
  gMessageTable = Mem_Malloc(size);
  Q_memcpy(gMessageTable,local_f200,iVar8);
  dest = (void *)((int)&gMessageTable->effect + iVar8);
  pcVar9 = (char *)(local_f234 + (int)dest);
  Q_memcpy(dest,local_4020,local_f234);
  pcVar2 = gMessageTable->pName;
  iVar5 = 0;
  iVar8 = local_f240;
  if (local_f240 != 0) {
    do {
      pcVar4 = gMessageTable;
      iVar7 = iVar5 + 1;
      gMessageTable[iVar5].pName = gMessageTable[iVar5].pName + ((int)dest - (int)pcVar2);
      Q_strcpy(pcVar9,pcVar4[iVar5].pMessage);
      gMessageTable[iVar5].pMessage = pcVar9;
      iVar8 = Q_strlen(pcVar9);
      pcVar9 = pcVar9 + iVar8 + 1;
      iVar5 = iVar7;
      iVar8 = local_f240;
    } while (local_f240 != iVar7);
  }
LAB_000a563c:
  gMessageTableCount = iVar8;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// TextMessageShutdown  @ 000a5f60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void TextMessageShutdown(void)

{
  if (gMessageTable != (client_textmessage_t *)0x0) {
    Mem_Free(gMessageTable);
    gMessageTable = (client_textmessage_t *)0x0;
  }
  return;
}


// TokenLine::CheckToken  @ 000c3170
/* DWARF original prototype: char * CheckToken(TokenLine * this, char * parm) */

char * __thiscall TokenLine::CheckToken(TokenLine *this,char *parm)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = this->m_tokenNumber;
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      if (this->m_token[iVar4] != (char *)0x0) {
        iVar2 = strcmp(parm,this->m_token[iVar4]);
        if (iVar2 == 0) {
                    /* Unresolved local var: char * ret@[???] */
          pcVar3 = "";
          if (iVar4 + 1 != iVar1) {
            pcVar3 = this->m_token[iVar4 + 1];
          }
          return pcVar3;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != iVar1);
  }
  return (char *)0x0;
}


// TokenLine::CountToken  @ 000c31e0
/* DWARF original prototype: int CountToken(TokenLine * this) */

int __thiscall TokenLine::CountToken(TokenLine *this)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char **ppcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
                    /* Unresolved local var: int c@[???] */
                    /* Unresolved local var: int i@[???] */
  uVar2 = this->m_tokenNumber;
  if ((int)uVar2 < 1) {
    iVar3 = 0;
  }
  else {
    uVar5 = -(((uint)this->m_token & 0xf) >> 2) & 3;
    if (uVar2 < uVar5) {
      uVar5 = uVar2;
    }
    uVar7 = uVar2;
    if (((int)uVar2 < 7) || (uVar7 = uVar5, uVar5 != 0)) {
      iVar8 = -(uint)(this->m_token[0] == (char *)0x0);
      iVar3 = iVar8 + 1;
      if (uVar7 == 1) {
        iVar8 = 1;
      }
      else {
        iVar3 = (iVar8 + 2) - (uint)(this->m_token[1] == (char *)0x0);
        if (uVar7 == 2) {
          iVar8 = 2;
        }
        else {
          iVar3 = (iVar3 + 1) - (uint)(this->m_token[2] == (char *)0x0);
          if (uVar7 == 3) {
            iVar8 = 3;
          }
          else {
            iVar3 = (iVar3 + 1) - (uint)(this->m_token[3] == (char *)0x0);
            if (uVar7 == 4) {
              iVar8 = 4;
            }
            else {
              iVar3 = (iVar3 + 1) - (uint)(this->m_token[4] == (char *)0x0);
              if (uVar7 == 5) {
                iVar8 = 5;
              }
              else {
                iVar8 = 6;
                iVar3 = (iVar3 + 1) - (uint)(this->m_token[5] == (char *)0x0);
              }
            }
          }
        }
      }
      uVar5 = uVar7;
      if (uVar2 == uVar7) {
        return iVar3;
      }
    }
    else {
      iVar8 = 0;
      iVar3 = 0;
    }
    uVar7 = ((uVar2 - uVar5) - 4 >> 2) + 1;
    iVar1 = uVar7 * 4;
    if (2 < (uVar2 - 1) - uVar5) {
      uVar6 = 0;
      iVar9 = 0;
      iVar10 = 0;
      iVar11 = 0;
      iVar12 = 0;
      ppcVar4 = this->m_token + uVar5;
      do {
        uVar6 = uVar6 + 1;
        iVar9 = iVar9 + (~-(uint)(*ppcVar4 == (char *)0x0) & 1);
        iVar10 = iVar10 + (~-(uint)(ppcVar4[1] == (char *)0x0) & 1);
        iVar11 = iVar11 + (~-(uint)(ppcVar4[2] == (char *)0x0) & 1);
        iVar12 = iVar12 + (~-(uint)(SUB124(SUB1612((undefined1  [16])0x0,4),8) == ppcVar4[3]) & 1);
        ppcVar4 = ppcVar4 + 4;
      } while (uVar6 < uVar7);
      iVar8 = iVar8 + iVar1;
      iVar3 = iVar3 + iVar9 + iVar11 + iVar10 + iVar12;
      if (uVar2 - uVar5 == iVar1) {
        return iVar3;
      }
    }
    iVar3 = (iVar3 + 1) - (uint)(this->m_token[iVar8] == (char *)0x0);
    if ((iVar8 + 1 < (int)uVar2) &&
       (iVar3 = (iVar3 + 1) - (uint)(this->m_token[iVar8 + 1] == (char *)0x0),
       iVar8 + 2 < (int)uVar2)) {
      iVar3 = (iVar3 + 1) - (uint)(this->m_token[iVar8 + 2] == (char *)0x0);
    }
  }
  return iVar3;
}


// TokenLine::GetLine  @ 000c3130
/* DWARF original prototype: char * GetLine(TokenLine * this) */

char * __thiscall TokenLine::GetLine(TokenLine *this)

{
  return this->m_fullLine;
}


// TokenLine::GetRestOfLine  @ 000c33c0
/* DWARF original prototype: char * GetRestOfLine(TokenLine * this, int i) */

char * __thiscall TokenLine::GetRestOfLine(TokenLine *this,int i)

{
  if (i < this->m_tokenNumber) {
    return this->m_token[i] + 0x800;
  }
  return (char *)0x0;
}


// TokenLine::GetToken  @ 000c3140
/* DWARF original prototype: char * GetToken(TokenLine * this, int i) */

char * __thiscall TokenLine::GetToken(TokenLine *this,int i)

{
  if (i < this->m_tokenNumber) {
    return this->m_token[i];
  }
  return (char *)0x0;
}


// TokenLine::SetLine  @ 000c2ee0
/* DWARF original prototype: bool SetLine(TokenLine * this, char * newLine) */

bool __thiscall TokenLine::SetLine(TokenLine *this,char *newLine)

{
  char cVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  byte bVar9;
  
                    /* Unresolved local var: char * charPointer@[???] */
  bVar9 = 0;
  this->m_tokenNumber = 0;
  if ((newLine == (char *)0x0) || (sVar2 = strlen(newLine), 0x7fe < sVar2)) {
    pcVar7 = this->m_fullLine;
    uVar5 = 0x800;
    bVar8 = ((uint)pcVar7 & 1) != 0;
    if (bVar8) {
      this->m_fullLine[0] = '\0';
      pcVar7 = this->m_fullLine + 1;
      uVar5 = 0x7ff;
    }
    if (((uint)pcVar7 & 2) != 0) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      uVar5 = uVar5 - 2;
      pcVar7 = pcVar7 + 2;
    }
    if (((uint)pcVar7 & 4) != 0) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      pcVar7[2] = '\0';
      pcVar7[3] = '\0';
      uVar5 = uVar5 - 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      pcVar7[2] = '\0';
      pcVar7[3] = '\0';
      pcVar7 = pcVar7 + (uint)bVar9 * -8 + 4;
    }
    if ((uVar5 & 2) != 0) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      pcVar7 = pcVar7 + 2;
    }
    if (bVar8) {
      *pcVar7 = '\0';
    }
    pcVar7 = this->m_tokenBuffer;
    uVar5 = 0x800;
    bVar8 = ((uint)pcVar7 & 1) != 0;
    if (bVar8) {
      this->m_tokenBuffer[0] = '\0';
      pcVar7 = this->m_tokenBuffer + 1;
      uVar5 = 0x7ff;
    }
    if (((uint)pcVar7 & 2) != 0) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      uVar5 = uVar5 - 2;
      pcVar7 = pcVar7 + 2;
    }
    if (((uint)pcVar7 & 4) != 0) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      pcVar7[2] = '\0';
      pcVar7[3] = '\0';
      uVar5 = uVar5 - 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      pcVar7[2] = '\0';
      pcVar7[3] = '\0';
      pcVar7 = pcVar7 + (uint)bVar9 * -8 + 4;
    }
    if ((uVar5 & 2) != 0) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      pcVar7 = pcVar7 + 2;
    }
    if (bVar8) {
      *pcVar7 = '\0';
    }
    return false;
  }
                    /* Unresolved local var: char * charPointer@[???] */
  pcVar7 = this->m_tokenBuffer;
  strncpy(this->m_fullLine,newLine,0x7ff);
  this->m_fullLine[0x7ff] = '\0';
  strncpy(pcVar7,newLine,0x7ff);
  this->m_tokenBuffer[0x7ff] = '\0';
  iVar4 = 0;
  while ((*pcVar7 != '\0' && (iVar4 < 0x80))) {
    if (0x5d < (byte)(*pcVar7 - 0x21U)) {
      do {
        pcVar7 = pcVar7 + 1;
        cVar1 = *pcVar7;
        if ((byte)(cVar1 - 0x21U) < 0x5e) break;
      } while (cVar1 != '\0');
      if (cVar1 == '\0') break;
    }
    this->m_token[iVar4] = pcVar7;
    cVar1 = *pcVar7;
    pcVar6 = pcVar7;
    if (cVar1 == '\"') {
      pcVar6 = pcVar7 + 1;
      this->m_token[iVar4] = pcVar6;
      if ((pcVar7[1] != '\"') && (pcVar7[1] != '\0')) {
        do {
          pcVar6 = pcVar6 + 1;
          if (*pcVar6 == '\0') break;
        } while (*pcVar6 != '\"');
      }
    }
    else {
      while ((byte)(cVar1 - 0x21U) < 0x5e) {
        pcVar6 = pcVar6 + 1;
        cVar1 = *pcVar6;
      }
    }
    iVar4 = iVar4 + 1;
    this->m_tokenNumber = iVar4;
    if (*pcVar6 == '\0') break;
    *pcVar6 = '\0';
    pcVar7 = pcVar6 + 1;
    iVar4 = this->m_tokenNumber;
  }
  return iVar4 != 0x80;
}


// TokenLine::TokenLine  @ 000c33f0
/* DWARF original prototype: void TokenLine(TokenLine * this, char * string) */

void __thiscall TokenLine::TokenLine(TokenLine *this,char *string)

{
  this->_vptr_TokenLine = (_func_int_varargs **)&PTR__TokenLine_000de8fc;
  SetLine(this,string);
  return;
}


// TokenLine::TokenLine  @ 000c3400
/* DWARF original prototype: void TokenLine(TokenLine * this) */

void __thiscall TokenLine::TokenLine(TokenLine *this)

{
  this->_vptr_TokenLine = (_func_int_varargs **)&PTR__TokenLine_000de8fc;
  return;
}


// TokenLine::~TokenLine  @ 000c2ec0
/* DWARF original prototype: void ~TokenLine(TokenLine * this, int __in_chrg) */

void __thiscall TokenLine::~TokenLine(TokenLine *this,int __in_chrg)

{
  return;
}


// TokenLine::~TokenLine  @ 000c2ed0
/* DWARF original prototype: void ~TokenLine(TokenLine * this, int __in_chrg) */

void __thiscall TokenLine::~TokenLine(TokenLine *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// TraceHull  @ 0006e650
void TraceHull(float *v1,float *v2,int fNoMonsters,int hullNumber,edict_t *pentToSkip,
              TraceResult *ptr)

{
  trace_t local_44;
  
                    /* Unresolved local var: trace_t trace@[???] */
  if (3 < (uint)hullNumber) {
    hullNumber = 0;
  }
  SV_Move(&local_44,v1,gHullMins[hullNumber],gHullMaxs[hullNumber],v2,fNoMonsters,pentToSkip,false);
  ptr->fAllSolid = local_44.allsolid;
  ptr->fStartSolid = local_44.startsolid;
  ptr->flFraction = local_44.fraction;
  ptr->fInOpen = local_44.inopen;
  ptr->flPlaneDist = local_44.plane.dist;
  ptr->vecEndPos[0] = local_44.endpos[0];
  ptr->vecEndPos[1] = local_44.endpos[1];
  ptr->fInWater = local_44.inwater;
  ptr->vecEndPos[2] = local_44.endpos[2];
  ptr->vecPlaneNormal[0] = local_44.plane.normal[0];
  ptr->vecPlaneNormal[1] = local_44.plane.normal[1];
  ptr->pHit = local_44.ent;
  ptr->vecPlaneNormal[2] = local_44.plane.normal[2];
  ptr->iHitgroup = local_44.hitgroup;
  return;
}


// TraceInit  @ 000b3790
void TraceInit(char *i,char *s,int listnum)

{
  InitFunc *pIVar1;
  int iVar2;
  InitFunc **ppIVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
                    /* Unresolved local var: InitFunc * f@[???] */
  pIVar1 = operator_new(0x24);
  iVar6 = g_InitTracker.m_Funcs[listnum].m_Size;
  pIVar1->referencecount = 1;
  pIVar1->warningprinted = false;
  *(undefined4 *)&pIVar1->inittime = 0;
  pIVar1->initname = i;
  *(undefined4 *)((int)&pIVar1->inittime + 4) = 0;
  *(undefined4 *)&pIVar1->shutdowntime = 0;
  *(undefined4 *)((int)&pIVar1->shutdowntime + 4) = 0;
  pIVar1->shutdownname = s;
  pIVar1->sequence = g_InitTracker.m_nNumFuncs[listnum];
  iVar5 = g_InitTracker.m_Funcs[listnum].m_Memory.m_NumAllocated;
  iVar4 = iVar6 + 1;
  if (iVar4 <= iVar5) goto LAB_000b3876;
  iVar2 = g_InitTracker.m_Funcs[listnum].m_Memory.m_GrowSize;
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
  iVar5 = iVar4 - iVar5;
  if (iVar5 < iVar2) {
    if ((0 < iVar2) || (iVar2 != 0)) goto LAB_000b3835;
    iVar5 = g_InitTracker.m_Funcs[listnum].m_Memory.m_NumAllocated;
    iVar2 = 1;
    if (iVar5 != 0) {
      iVar2 = iVar5;
    }
    iVar2 = iVar2 + iVar5;
    g_InitTracker.m_Funcs[listnum].m_Memory.m_NumAllocated = iVar2;
  }
  else {
                    /* Unresolved local var: int growSize@[???] */
    bVar7 = iVar2 < 0;
    iVar2 = iVar5;
    if (bVar7) goto LAB_000b3876;
LAB_000b3835:
    iVar2 = iVar2 + g_InitTracker.m_Funcs[listnum].m_Memory.m_NumAllocated;
    g_InitTracker.m_Funcs[listnum].m_Memory.m_NumAllocated = iVar2;
  }
                    /* Unresolved local var: int growSize@[???] */
  ppIVar3 = g_InitTracker.m_Funcs[listnum].m_Memory.m_pMemory;
  if (ppIVar3 == (InitFunc **)0x0) {
    ppIVar3 = malloc(iVar2 << 2);
    g_InitTracker.m_Funcs[listnum].m_Memory.m_pMemory = ppIVar3;
  }
  else {
    ppIVar3 = realloc(ppIVar3,iVar2 << 2);
    iVar6 = g_InitTracker.m_Funcs[listnum].m_Size;
    iVar4 = iVar6 + 1;
    g_InitTracker.m_Funcs[listnum].m_Memory.m_pMemory = ppIVar3;
  }
LAB_000b3876:
                    /* Unresolved local var: int numToMove@[???] */
  g_InitTracker.m_Funcs[listnum].m_Size = iVar4;
  if (0 < iVar6) {
    ppIVar3 = g_InitTracker.m_Funcs[listnum].m_Memory.m_pMemory;
    memmove(ppIVar3 + 1,ppIVar3,iVar6 << 2);
  }
  ppIVar3 = g_InitTracker.m_Funcs[listnum].m_Memory.m_pMemory;
  if (ppIVar3 != (InitFunc **)0x0) {
    *ppIVar3 = pIVar1;
  }
  g_InitTracker.m_nNumFuncs[listnum] = g_InitTracker.m_nNumFuncs[listnum] + 1;
  return;
}


// TraceModel  @ 0006e760
void TraceModel(float *v1,float *v2,int hullNumber,edict_t *pent,TraceResult *ptr)

{
  model_s *pmVar1;
  int unaff_EDI;
  int local_60;
  trace_t tStack_5c;
  
                    /* Unresolved local var: trace_t trace@[???]
                       Unresolved local var: int oldSolid@[???]
                       Unresolved local var: int oldMovetype@[???]
                       Unresolved local var: model_t * pmodel@[???] */
  if (3 < (uint)hullNumber) {
    hullNumber = 0;
  }
  pmVar1 = sv.models[(pent->v).modelindex];
  if (pmVar1 == (model_s *)0x0) {
    SV_ClipMoveToEntity(&tStack_5c,pent,v1,gHullMins[hullNumber],gHullMaxs[hullNumber],v2);
  }
  else {
    if (pmVar1->type == mod_brush) {
      local_60 = (pent->v).solid;
      (pent->v).solid = 4;
      unaff_EDI = (pent->v).movetype;
      (pent->v).movetype = 7;
    }
    SV_ClipMoveToEntity(&tStack_5c,pent,v1,gHullMins[hullNumber],gHullMaxs[hullNumber],v2);
    if (pmVar1->type == mod_brush) {
      (pent->v).movetype = unaff_EDI;
      (pent->v).solid = local_60;
    }
  }
  ptr->fAllSolid = tStack_5c.allsolid;
  ptr->fStartSolid = tStack_5c.startsolid;
  ptr->fInOpen = tStack_5c.inopen;
  ptr->fInWater = tStack_5c.inwater;
  ptr->pHit = tStack_5c.ent;
  ptr->flFraction = tStack_5c.fraction;
  ptr->flPlaneDist = tStack_5c.plane.dist;
  ptr->vecEndPos[0] = tStack_5c.endpos[0];
  ptr->vecEndPos[1] = tStack_5c.endpos[1];
  ptr->vecEndPos[2] = tStack_5c.endpos[2];
  ptr->vecPlaneNormal[0] = tStack_5c.plane.normal[0];
  ptr->vecPlaneNormal[1] = tStack_5c.plane.normal[1];
  ptr->vecPlaneNormal[2] = tStack_5c.plane.normal[2];
  ptr->iHitgroup = tStack_5c.hitgroup;
  return;
}


// TraceMonsterHull  @ 0006f210
int TraceMonsterHull(edict_t *pEdict,float *v1,float *v2,int fNoMonsters,edict_t *pentToSkip,
                    TraceResult *ptr)

{
  trace_t local_44;
  
                    /* Unresolved local var: trace_t trace@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  SV_Move(&local_44,v1,(pEdict->v).mins,(pEdict->v).maxs,v2,fNoMonsters,pentToSkip,
          (uint)(pEdict->v).flags >> 0x17 & true);
  if (ptr != (TraceResult *)0x0) {
    ptr->flFraction = local_44.fraction;
    ptr->fStartSolid = local_44.startsolid;
    ptr->fInOpen = local_44.inopen;
    ptr->flPlaneDist = local_44.plane.dist;
    ptr->vecEndPos[0] = local_44.endpos[0];
    ptr->fInWater = local_44.inwater;
    ptr->vecEndPos[1] = local_44.endpos[1];
    ptr->vecEndPos[2] = local_44.endpos[2];
    ptr->vecPlaneNormal[0] = local_44.plane.normal[0];
    ptr->pHit = local_44.ent;
    ptr->vecPlaneNormal[1] = local_44.plane.normal[1];
    ptr->vecPlaneNormal[2] = local_44.plane.normal[2];
    ptr->fAllSolid = local_44.allsolid;
    ptr->iHitgroup = local_44.hitgroup;
  }
  if (local_44.fraction != 1.0) {
    return 1;
  }
  return (uint)(local_44.allsolid != false);
}


// TraceShutdown  @ 000b3920
void TraceShutdown(char *s,int listnum)

{
  CInitTracker::Shutdown(&g_InitTracker,s,listnum);
  return;
}


// TraceSphere  @ 0006e750
void TraceSphere(float *v1,float *v2,int fNoMonsters,float radius,edict_t *pentToSkip,
                TraceResult *ptr)

{
  Sys_Error("TraceSphere not yet implemented!\n");
  return;
}


// TraceTexture  @ 0006eb80
char * TraceTexture(edict_t *pTextureEntity,float *v1,float *v2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  hull_s *phVar5;
  msurface_t *pmVar6;
  model_s *pModel;
  int iVar7;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: model_t * pmodel@[???]
                       Unresolved local var: msurface_t * psurf@[???]
                       Unresolved local var: int firstnode@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t end@[???] */
  if (pTextureEntity == (edict_t *)0x0) {
    iVar7 = 0;
    pModel = sv.worldmodel;
    local_64 = *v1;
    local_60 = v1[1];
    local_5c = v1[2];
    local_58 = *v2;
    local_54 = v2[1];
    local_50 = v2[2];
    if (sv.worldmodel == (model_s *)0x0) {
      return (char *)0x0;
    }
  }
  else {
                    /* Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: hull_t * phull@[???]
                       Unresolved local var: int modelindex@[???] */
    uVar1 = (pTextureEntity->v).modelindex;
    if (0x1ff < uVar1) {
      return (char *)0x0;
    }
    if (sv.model_precache[uVar1] == (char *)0x0) {
      return (char *)0x0;
    }
    pModel = sv.models[uVar1];
    if (pModel == (model_s *)0x0) {
      return (char *)0x0;
    }
    if (pModel->type != mod_brush) {
      return (char *)0x0;
    }
    phVar5 = SV_HullForBsp(pTextureEntity,vec3_origin,vec3_origin,&local_4c);
    fVar2 = *v1 - local_4c;
    fVar3 = v1[1] - local_48;
    fVar4 = v1[2] - local_44;
    local_4c = *v2 - local_4c;
    local_48 = v2[1] - local_48;
    local_44 = v2[2] - local_44;
    iVar7 = phVar5->firstclipnode;
    local_64 = fVar2;
    local_60 = fVar3;
    local_5c = fVar4;
    local_58 = local_4c;
    local_54 = local_48;
    local_50 = local_44;
    if ((((pTextureEntity->v).angles[0] != 0.0) || ((pTextureEntity->v).angles[1] != 0.0)) ||
       ((pTextureEntity->v).angles[2] != 0.0)) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
      AngleVectors((pTextureEntity->v).angles,&local_40,&local_34,&local_28);
      local_64 = local_38 * fVar4 + local_3c * fVar3 + local_40 * fVar2;
      local_60 = -(local_2c * fVar4 + local_30 * fVar3 + local_34 * fVar2);
      local_5c = fVar4 * local_20 + fVar3 * local_24 + fVar2 * local_28;
      local_58 = local_38 * local_44 + local_3c * local_48 + local_40 * local_4c;
      local_54 = -(local_2c * local_44 + local_30 * local_48 + local_34 * local_4c);
      local_50 = local_44 * local_20 + local_48 * local_24 + local_4c * local_28;
    }
  }
  if (((pModel->type == mod_brush) && (pModel->nodes != (mnode_t *)0x0)) &&
     (pmVar6 = SurfaceAtPoint(pModel,pModel->nodes + iVar7,&local_64,&local_58),
     pmVar6 != (msurface_t *)0x0)) {
    return pmVar6->texinfo->texture->name;
  }
  return (char *)0x0;
}


// TrimSpace  @ 000a52c0
void TrimSpace(char *source,char *dest)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: int start@[???]
                       Unresolved local var: int end@[???]
                       Unresolved local var: int length@[???] */
  iVar2 = Q_strlen(source);
  cVar3 = *source;
  pcVar4 = source;
  if (cVar3 == '\0') {
    iVar5 = 0;
  }
  else {
    iVar5 = 0;
    do {
      if ((0x17 < (byte)(cVar3 - 9U)) || (((byte)(0x800013 >> (cVar3 - 9U & 0x1f)) & 1) != 1))
      break;
      pcVar4 = pcVar4 + 1;
      cVar3 = *pcVar4;
      iVar5 = iVar5 + 1;
    } while (cVar3 != '\0');
  }
  iVar2 = iVar2 + -1;
  iVar1 = iVar2;
  if (iVar2 < 1) {
LAB_000a531c:
    iVar5 = (iVar2 + 1) - iVar5;
  }
  else {
    do {
      iVar2 = iVar1;
      if ((0x17 < (byte)(source[iVar2] - 9U)) ||
         (((byte)(0x800013 >> (source[iVar2] - 9U & 0x1f)) & 1) != 1)) goto LAB_000a531c;
      iVar1 = iVar2 + -1;
    } while (iVar2 + -1 != 0);
    iVar5 = iVar2 - iVar5;
  }
  if (iVar5 < 1) {
    *dest = '\0';
    return;
  }
  Q_strncpy(dest,pcVar4,iVar5);
  dest[iVar5] = '\0';
  return;
}


// UnsafeCmdLineProcessor  @ 000b9f80
void __regparm3 UnsafeCmdLineProcessor(char *pchUnsafeCmdLine,int cubSize)

{
  byte bVar1;
  netadr_t a;
  int iVar2;
  qboolean qVar3;
  char *pcVar4;
  byte *pbVar5;
  int in_GS_OFFSET;
  char local_12e [10];
  netadr_t local_124;
  char local_110 [255];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[10] szPrefix@[???]
                       Unresolved local var: size_t nPrefixLen@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  builtin_strncpy(local_12e,"+connect ",10);
  iVar2 = Q_strncmp(pchUnsafeCmdLine,local_12e,9);
  if ((iVar2 == 0) && (bVar1 = pchUnsafeCmdLine[9], bVar1 != 0)) {
                    /* Unresolved local var: char * pchAddress@[???]
                       Unresolved local var: netadr_t.conflict address@[???] */
    pbVar5 = (byte *)(pchUnsafeCmdLine + 9);
    do {
                    /* Unresolved local var: bool bConnectValid@[???] */
      if (10 < (byte)(bVar1 - 0x30)) {
        if ((0x19 < (byte)((bVar1 & 0xdf) + 0xbf) && bVar1 != 0x5f) && (1 < (byte)(bVar1 - 0x2d))) {
          Con_Printf("Rejecting unsafe cmdline\n");
          goto LAB_000ba0e0;
        }
      }
      pbVar5 = pbVar5 + 1;
      bVar1 = *pbVar5;
    } while (bVar1 != 0);
    local_124.type = NA_UNUSED;
    local_124.ipx[8] = '\0';
    local_124.ipx[9] = '\0';
    local_124.port = 0;
    local_124.ip[0] = '\0';
    local_124.ip[1] = '\0';
    local_124.ip[2] = '\0';
    local_124.ip[3] = '\0';
    local_124.ipx[0] = '\0';
    local_124.ipx[1] = '\0';
    local_124.ipx[2] = '\0';
    local_124.ipx[3] = '\0';
    local_124.ipx[4] = '\0';
    local_124.ipx[5] = '\0';
    local_124.ipx[6] = '\0';
    local_124.ipx[7] = '\0';
    qVar3 = NET_StringToAdr(pchUnsafeCmdLine + 9,&local_124);
    if (qVar3 == false) {
      Con_Printf("Invalid address to connect to from unsafe location! Ignoring.\n");
    }
    else {
                    /* Unresolved local var: char[256] szSanitizedConnect@[???] */
      a.ip[0] = local_124.ip[0];
      a.ip[1] = local_124.ip[1];
      a.ip[2] = local_124.ip[2];
      a.ip[3] = local_124.ip[3];
      a.type = local_124.type;
      a.ipx[0] = local_124.ipx[0];
      a.ipx[1] = local_124.ipx[1];
      a.ipx[2] = local_124.ipx[2];
      a.ipx[3] = local_124.ipx[3];
      a.ipx[4] = local_124.ipx[4];
      a.ipx[5] = local_124.ipx[5];
      a.ipx[6] = local_124.ipx[6];
      a.ipx[7] = local_124.ipx[7];
      a.ipx[8] = local_124.ipx[8];
      a.ipx[9] = local_124.ipx[9];
      a.port = local_124.port;
      pcVar4 = NET_AdrToString(a);
      __snprintf_chk(local_110,0x100,1,0x100,"\nconnect %s\n",pcVar4);
      local_11 = 0;
      Cbuf_AddText(local_110);
      Cbuf_AddText("\ncl_skipvid 1\n");
    }
  }
LAB_000ba0e0:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ValidChallenge  @ 00086f60
qboolean ValidChallenge(netadr_t *adr,int challengeNr)

{
  qboolean qVar1;
  int iVar2;
  int in_GS_OFFSET;
  sizebuf_t local_34;
  byte local_20 [16];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  qVar1 = false;
  if (sv.active != false) {
    if (svs.maxclients < 2) {
      qVar1 = false;
    }
    else if (sv_enableoldqueries.value == 0.0) {
                    /* Unresolved local var: int i@[???] */
      if ((adr != (netadr_t *)0x0) && (iVar2 = 0, challengeNr != -1)) {
        do {
          qVar1 = NET_CompareBaseAdr(*adr,g_rg_sv_challenges[iVar2].adr);
          if (qVar1 != false) {
            if ((challengeNr == g_rg_sv_challenges[iVar2].challenge) &&
               ((float)realtime <= (float)g_rg_sv_challenges[iVar2].time + 3600.0))
            goto LAB_00086f9e;
            break;
          }
                    /* Unresolved local var: int i@[???] */
          iVar2 = iVar2 + 1;
        } while (iVar2 != 0x400);
      }
                    /* Unresolved local var: char[16] buffer@[???]
                       Unresolved local var: sizebuf_t buf@[???] */
      local_34.buffername = "SVC_Challenge";
      local_34.data = local_20;
      local_34.maxsize = 0x10;
      local_34.cursize = 0;
      local_34.flags = 1;
      MSG_WriteLong(&local_34,-1);
      MSG_WriteByte(&local_34,0x41);
      iVar2 = GetChallengeNr(adr);
      MSG_WriteLong(&local_34,iVar2);
      NET_SendPacket(NS_SERVER,local_34.cursize,local_34.data,*adr);
      qVar1 = false;
    }
    else {
LAB_00086f9e:
      qVar1 = true;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ValidCmd  @ 000700a0
qboolean ValidCmd(char *pCmd)

{
  int iVar1;
  qboolean qVar2;
  
                    /* Unresolved local var: int len@[???] */
  iVar1 = Q_strlen(pCmd);
  qVar2 = false;
  if (iVar1 != 0) {
    qVar2 = (qboolean)(pCmd[iVar1 + -1] == '\n' || pCmd[iVar1 + -1] == ';');
  }
  return qVar2;
}


// ValidInfoChallenge  @ 00086bf0
qboolean ValidInfoChallenge(netadr_t *adr,char *nugget)

{
  int iVar1;
  
  if (((sv.active != false) && (nugget != (char *)0x0)) && (1 < svs.maxclients)) {
    if (sv_enableoldqueries.value != 0.0) {
      return true;
    }
    iVar1 = Q_stricmp(nugget,"Source Engine Query");
    return (uint)(iVar1 == 0);
  }
  return false;
}


// VectorAngles  @ 00060eb0
void VectorAngles(vec_t *forward,vec_t *angles)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  
                    /* Unresolved local var: float tmp@[???]
                       Unresolved local var: float yaw@[???]
                       Unresolved local var: float pitch@[???] */
  fVar1 = 0.0;
  if ((forward[1] == 0.0) && (*forward == 0.0)) {
    if (forward[2] <= 0.0) {
      fVar2 = 270.0;
    }
    else {
      fVar2 = 90.0;
    }
  }
  else {
    dVar4 = atan2((double)forward[1],(double)*forward);
    fVar1 = ((float)dVar4 * 180.0) / 3.1415927;
    if (fVar1 < 0.0) {
      fVar1 = fVar1 + 360.0;
    }
    fVar2 = forward[1] * forward[1] + *forward * *forward;
    fVar3 = SQRT(fVar2);
    if (NAN(fVar3)) {
      fVar3 = sqrtf(fVar2);
    }
    dVar4 = atan2((double)forward[2],(double)fVar3);
    fVar2 = ((float)dVar4 * 180.0) / 3.1415927;
    if (fVar2 < 0.0) {
      fVar2 = fVar2 + 360.0;
    }
  }
  *angles = fVar2;
  angles[1] = fVar1;
  angles[2] = 0.0;
  return;
}


// VectorCompare  @ 00060aa0
int VectorCompare(vec_t *v1,vec_t *v2)

{
  uint uVar1;
  
                    /* Unresolved local var: int i@[???] */
  if ((*v2 == *v1) && (v1[1] == v2[1])) {
    uVar1 = (uint)(!NAN(v2[2]) && !NAN(v1[2]));
    if (v2[2] != v1[2]) {
      uVar1 = 0;
    }
    return uVar1;
  }
  return 0;
}


// VectorInverse  @ 00060cb0
void VectorInverse(vec_t *v)

{
  *v = -*v;
  v[1] = -v[1];
  v[2] = -v[2];
  return;
}


// VectorMA  @ 00060af0
void VectorMA(vec_t *veca,float scale,vec_t *vecb,vec_t *vecc)

{
  *vecc = *vecb * scale + *veca;
  vecc[1] = vecb[1] * scale + veca[1];
  vecc[2] = scale * vecb[2] + veca[2];
  return;
}


// VectorMatrix  @ 00060d20
void VectorMatrix(vec_t *forward,vec_t *right,vec_t *up)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
                    /* Unresolved local var: vec3_t tmp@[???] */
  if ((*forward == 0.0) && (forward[1] == 0.0)) {
    right[1] = 0.0;
    *right = 1.0;
    right[2] = 0.0;
    *up = -forward[2];
    up[1] = 0.0;
    up[2] = 0.0;
    return;
  }
  fVar3 = forward[1] - forward[2] * 0.0;
  *right = fVar3;
  fVar1 = forward[2] * 0.0 - *forward;
  right[1] = fVar1;
  fVar2 = *forward * 0.0 - forward[1] * 0.0;
  right[2] = fVar2;
                    /* Unresolved local var: float length@[???]
                       Unresolved local var: float ilength@[???] */
  fVar2 = fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3;
  fVar3 = SQRT(fVar2);
  if (NAN(fVar3)) {
    fVar3 = sqrtf(fVar2);
  }
  if (fVar3 == 0.0) {
    fVar2 = right[1];
    fVar3 = right[2];
  }
  else {
    fVar3 = 1.0 / fVar3;
    *right = *right * fVar3;
    fVar2 = right[1] * fVar3;
    right[1] = fVar2;
    fVar3 = fVar3 * right[2];
    right[2] = fVar3;
  }
  fVar3 = fVar2 * forward[2] - fVar3 * forward[1];
  *up = fVar3;
  fVar1 = right[2] * *forward - *right * forward[2];
  up[1] = fVar1;
  fVar2 = *right * forward[1] - right[1] * *forward;
  up[2] = fVar2;
                    /* Unresolved local var: float length@[???]
                       Unresolved local var: float ilength@[???] */
  fVar3 = fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3;
  fVar2 = SQRT(fVar3);
  if (NAN(fVar2)) {
    fVar2 = sqrtf(fVar3);
  }
  if (fVar2 != 0.0) {
    fVar2 = 1.0 / fVar2;
    *up = *up * fVar2;
    up[1] = up[1] * fVar2;
    up[2] = fVar2 * up[2];
  }
  return;
}


// VectorNormalize  @ 00060c50
float VectorNormalize(vec_t *v)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: float length@[???]
                       Unresolved local var: float ilength@[???] */
  fVar1 = v[2] * v[2] + v[1] * v[1] + *v * *v;
  fVar2 = SQRT(fVar1);
  if (NAN(fVar2)) {
    fVar2 = sqrtf(fVar1);
  }
  if (fVar2 != 0.0) {
    fVar1 = 1.0 / fVar2;
    *v = *v * fVar1;
    v[1] = v[1] * fVar1;
    v[2] = fVar1 * v[2];
  }
  return fVar2;
}


// VectorScale  @ 00060cd0
void VectorScale(vec_t *in,vec_t scale,vec_t *out)

{
  *out = *in * scale;
  out[1] = in[1] * scale;
  out[2] = scale * in[2];
  return;
}


// VectorTransform  @ 00060a40
void VectorTransform(vec_t *in1,float (*in2) [4],vec_t *out)

{
  *out = in1[2] * (*in2)[2] + in1[1] * (*in2)[1] + *in1 * (*in2)[0] + (*in2)[3];
  out[1] = in1[2] * in2[1][2] + in1[1] * in2[1][1] + *in1 * in2[1][0] + in2[1][3];
  out[2] = in1[2] * in2[2][2] + in1[1] * in2[2][1] + *in1 * in2[2][0] + in2[2][3];
  return;
}


// anglemod  @ 0005f690
float anglemod(float a)

{
  return (float)((int)(a * 182.04445) & 0xffff) * 0.005493164;
}


// bsPutUChar  @ 000c8223
void bsPutUChar(void)

{
  int in_EAX;
  int iVar1;
  int in_EDX;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(in_EAX + 0x25c);
  if (iVar3 < 8) {
    uVar2 = *(uint *)(in_EAX + 600);
  }
  else {
    iVar1 = *(int *)(in_EAX + 0x4c);
    uVar2 = *(uint *)(in_EAX + 600);
    do {
      *(char *)(*(int *)(in_EAX + 0x2c) + iVar1) = (char)(uVar2 >> 0x18);
      iVar1 = *(int *)(in_EAX + 0x4c) + 1;
      *(int *)(in_EAX + 0x4c) = iVar1;
      uVar2 = *(int *)(in_EAX + 600) << 8;
      *(uint *)(in_EAX + 600) = uVar2;
      iVar3 = *(int *)(in_EAX + 0x25c) + -8;
      *(int *)(in_EAX + 0x25c) = iVar3;
    } while (7 < iVar3);
  }
  *(uint *)(in_EAX + 600) = in_EDX << (0x18U - (char)iVar3 & 0x1f) | uVar2;
  *(int *)(in_EAX + 0x25c) = iVar3 + 8;
  return;
}


// bsPutUInt32  @ 000c8080
void bsPutUInt32(void)

{
  int in_EAX;
  int iVar1;
  uint in_EDX;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(in_EAX + 0x25c);
  if (iVar3 < 8) {
    uVar2 = *(uint *)(in_EAX + 600);
  }
  else {
    iVar1 = *(int *)(in_EAX + 0x4c);
    uVar2 = *(uint *)(in_EAX + 600);
    do {
      *(char *)(*(int *)(in_EAX + 0x2c) + iVar1) = (char)(uVar2 >> 0x18);
      iVar1 = *(int *)(in_EAX + 0x4c) + 1;
      *(int *)(in_EAX + 0x4c) = iVar1;
      uVar2 = *(int *)(in_EAX + 600) << 8;
      *(uint *)(in_EAX + 600) = uVar2;
      iVar3 = *(int *)(in_EAX + 0x25c) + -8;
      *(int *)(in_EAX + 0x25c) = iVar3;
    } while (7 < iVar3);
  }
  uVar2 = (in_EDX >> 0x18) << (0x18U - (char)iVar3 & 0x1f) | uVar2;
  *(uint *)(in_EAX + 600) = uVar2;
  iVar3 = iVar3 + 8;
  *(int *)(in_EAX + 0x25c) = iVar3;
  if (7 < iVar3) {
    iVar1 = *(int *)(in_EAX + 0x4c);
    do {
      *(char *)(*(int *)(in_EAX + 0x2c) + iVar1) = (char)(uVar2 >> 0x18);
      iVar1 = *(int *)(in_EAX + 0x4c) + 1;
      *(int *)(in_EAX + 0x4c) = iVar1;
      uVar2 = *(int *)(in_EAX + 600) << 8;
      *(uint *)(in_EAX + 600) = uVar2;
      iVar3 = *(int *)(in_EAX + 0x25c) + -8;
      *(int *)(in_EAX + 0x25c) = iVar3;
    } while (7 < iVar3);
  }
  uVar2 = (in_EDX >> 0x10 & 0xff) << (0x18U - (char)iVar3 & 0x1f) | uVar2;
  *(uint *)(in_EAX + 600) = uVar2;
  iVar3 = iVar3 + 8;
  *(int *)(in_EAX + 0x25c) = iVar3;
  if (7 < iVar3) {
    iVar1 = *(int *)(in_EAX + 0x4c);
    do {
      *(char *)(*(int *)(in_EAX + 0x2c) + iVar1) = (char)(uVar2 >> 0x18);
      iVar1 = *(int *)(in_EAX + 0x4c) + 1;
      *(int *)(in_EAX + 0x4c) = iVar1;
      uVar2 = *(int *)(in_EAX + 600) << 8;
      *(uint *)(in_EAX + 600) = uVar2;
      iVar3 = *(int *)(in_EAX + 0x25c) + -8;
      *(int *)(in_EAX + 0x25c) = iVar3;
    } while (7 < iVar3);
  }
  uVar2 = (in_EDX >> 8 & 0xff) << (0x18U - (char)iVar3 & 0x1f) | uVar2;
  *(uint *)(in_EAX + 600) = uVar2;
  iVar3 = iVar3 + 8;
  *(int *)(in_EAX + 0x25c) = iVar3;
  if (7 < iVar3) {
    iVar1 = *(int *)(in_EAX + 0x4c);
    do {
      *(char *)(*(int *)(in_EAX + 0x2c) + iVar1) = (char)(uVar2 >> 0x18);
      iVar1 = *(int *)(in_EAX + 0x4c) + 1;
      *(int *)(in_EAX + 0x4c) = iVar1;
      uVar2 = *(int *)(in_EAX + 600) << 8;
      *(uint *)(in_EAX + 600) = uVar2;
      iVar3 = *(int *)(in_EAX + 0x25c) + -8;
      *(int *)(in_EAX + 0x25c) = iVar3;
    } while (7 < iVar3);
  }
  *(uint *)(in_EAX + 600) = (in_EDX & 0xff) << (0x18U - (char)iVar3 & 0x1f) | uVar2;
  *(int *)(in_EAX + 0x25c) = iVar3 + 8;
  return;
}


// fallbackSort  @ 000cdec0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fallbackSort(int param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int in_EAX;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int in_ECX;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int in_EDX;
  int iVar15;
  int local_b98;
  int local_b94;
  int local_b8c;
  int local_b88;
  int local_b84;
  int local_b80;
  int local_b7c;
  uint local_b74;
  int local_b70;
  int local_b68;
  int local_b5c;
  int local_b58;
  int local_b54;
  int local_b40 [257];
  int local_73c [256];
  int local_33c [100];
  int local_1ac [103];
  
  if (3 < param_2) {
    fwrite("        bucket sorting ...\n",1,0x1b,_stderr);
  }
  iVar6 = 0;
  do {
    local_b40[iVar6] = 0;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x101);
  for (iVar6 = 0; iVar6 < param_1; iVar6 = iVar6 + 1) {
    local_b40[*(byte *)(in_EDX + iVar6)] = local_b40[*(byte *)(in_EDX + iVar6)] + 1;
  }
  iVar6 = 0;
  do {
    local_73c[iVar6] = local_b40[iVar6];
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x100);
  piVar7 = local_b40 + 1;
  do {
    *piVar7 = *piVar7 + piVar7[-1];
    piVar7 = piVar7 + 1;
  } while (piVar7 != local_73c);
  for (iVar6 = 0; iVar6 < param_1; iVar6 = iVar6 + 1) {
    iVar8 = local_b40[*(byte *)(in_EDX + iVar6)];
    local_b40[*(byte *)(in_EDX + iVar6)] = iVar8 + -1;
    *(int *)(in_EAX + (iVar8 + -1) * 4) = iVar6;
  }
  for (iVar6 = 0; iVar6 < param_1 / 0x20 + 2; iVar6 = iVar6 + 1) {
    *(undefined4 *)(in_ECX + iVar6 * 4) = 0;
  }
  iVar6 = 0;
  do {
    puVar1 = (uint *)(in_ECX + (local_b40[iVar6] >> 3 & 0xfffffffcU));
    *puVar1 = *puVar1 | 1 << ((byte)local_b40[iVar6] & 0x1f);
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x100);
  iVar6 = param_1;
  do {
    local_b94._0_1_ = (byte)iVar6 & 0x1f;
    puVar1 = (uint *)(in_ECX + (iVar6 >> 3 & 0xfffffffcU));
    *puVar1 = *puVar1 | 1 << (byte)local_b94;
    puVar1 = (uint *)(in_ECX + (iVar6 + 1 >> 3 & 0xfffffffcU));
    *puVar1 = *puVar1 & ~(1 << ((byte)(iVar6 + 1) & 0x1f));
    iVar6 = iVar6 + 2;
  } while (iVar6 != param_1 + 0x40);
  local_b5c = 1;
LAB_000ce036:
  if (3 < param_2) {
    fprintf(_stderr,"        depth %6d has ",local_b5c);
  }
  if (0 < param_1) {
    iVar6 = 0;
    iVar8 = 0;
    do {
      local_b98._0_1_ = (byte)iVar8 & 0x1f;
      if ((*(uint *)(in_ECX + (iVar8 >> 5) * 4) & 1 << (byte)local_b98) != 0) {
        iVar6 = iVar8;
      }
      iVar12 = *(int *)(in_EAX + iVar8 * 4) - local_b5c;
      if (iVar12 < 0) {
        iVar12 = iVar12 + param_1;
      }
      *(int *)(in_EDX + iVar12 * 4) = iVar6;
      iVar8 = iVar8 + 1;
    } while (iVar8 != param_1);
  }
  local_b54 = 0;
  local_b58 = -1;
LAB_000ce0ad:
  uVar9 = local_b58 + 1;
  uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
  uVar13 = uVar9 & 0x1f;
  uVar14 = uVar3 & 1 << (sbyte)uVar13;
  while (uVar14 != 0) {
    if (uVar13 == 0) goto joined_r0x000ce56d;
    uVar9 = uVar9 + 1;
    uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
    uVar13 = uVar9 & 0x1f;
    uVar14 = uVar3 & 1 << (sbyte)uVar13;
  }
  goto LAB_000ce101;
joined_r0x000ce56d:
  while (uVar3 == 0xffffffff) {
    uVar9 = uVar9 + 0x20;
    uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
  }
  uVar3 = 1 << ((byte)uVar9 & 0x1f) & uVar3;
  while (uVar3 != 0) {
    uVar9 = uVar9 + 1;
    uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4) & 1 << ((byte)uVar9 & 0x1f);
  }
LAB_000ce101:
  iVar6 = uVar9 - 1;
  if (param_1 <= iVar6) goto LAB_000ce6a9;
  uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
  uVar14 = uVar9 & 0x1f;
  local_b70 = iVar6;
  if ((uVar3 & 1 << (sbyte)uVar14) != 0) goto LAB_000ce16a;
  do {
    if (uVar14 == 0) goto joined_r0x000ce5bb;
    uVar9 = uVar9 + 1;
    uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
    uVar14 = uVar9 & 0x1f;
  } while ((uVar3 & 1 << (sbyte)uVar14) == 0);
LAB_000ce163:
  local_b70 = uVar9 - 1;
LAB_000ce16a:
  local_b58 = local_b70;
  if (param_1 <= local_b70) goto LAB_000ce6a9;
  if (iVar6 < local_b70) {
    local_b54 = ((local_b54 + 1) - iVar6) + local_b70;
    local_1ac[0] = iVar6;
    local_33c[0] = local_b70;
    local_b7c = local_b70;
    local_b68 = 1;
    local_b74 = 0;
    local_b88 = iVar6;
    do {
      iVar8 = local_b68 + -1;
      if (local_b7c - local_b88 < 10) {
        if (local_b88 != local_b7c) {
          if ((3 < local_b7c - local_b88) && (local_b88 <= local_b7c + -4)) {
            local_b98 = local_b7c;
            do {
              iVar12 = *(int *)(in_EAX + -0x10 + local_b98 * 4);
              uVar3 = *(uint *)(in_EDX + iVar12 * 4);
              iVar10 = local_b98;
              if (local_b98 <= local_b7c) {
                iVar4 = *(int *)(in_EAX + local_b98 * 4);
                uVar14 = *(uint *)(in_EDX + iVar4 * 4);
                while (uVar14 < uVar3) {
                  *(int *)(in_EAX + -0x10 + iVar10 * 4) = iVar4;
                  iVar10 = iVar10 + 4;
                  if (local_b7c < iVar10) break;
                  iVar4 = *(int *)(in_EAX + iVar10 * 4);
                  uVar14 = *(uint *)(in_EDX + iVar4 * 4);
                }
              }
              *(int *)(in_EAX + -0x10 + iVar10 * 4) = iVar12;
              local_b98 = local_b98 + -1;
            } while (local_b98 != local_b88 + 3);
          }
          if (local_b88 < local_b7c) {
            iVar12 = local_b7c;
            local_b98 = local_b7c + -1;
            do {
              iVar10 = *(int *)(in_EAX + -4 + iVar12 * 4);
              uVar3 = *(uint *)(in_EDX + iVar10 * 4);
              if (iVar12 <= local_b7c) {
                iVar4 = *(int *)(in_EAX + iVar12 * 4);
                uVar14 = *(uint *)(in_EDX + iVar4 * 4);
                while (uVar14 < uVar3) {
                  *(int *)(in_EAX + -4 + iVar12 * 4) = iVar4;
                  iVar12 = iVar12 + 1;
                  if (local_b7c < iVar12) break;
                  iVar4 = *(int *)(in_EAX + iVar12 * 4);
                  uVar14 = *(uint *)(in_EDX + iVar4 * 4);
                }
              }
              *(int *)(in_EAX + -4 + iVar12 * 4) = iVar10;
              iVar10 = local_b98 + -1;
              iVar12 = local_b98;
              local_b98 = iVar10;
            } while (local_b88 <= iVar10);
          }
        }
LAB_000ce2c7:
        local_b68 = iVar8;
        if (iVar8 == 0) goto LAB_000ce645;
      }
      else {
        local_b74 = local_b74 * 0x1dc5 + 1 & 0x7fff;
        if (local_b74 == (local_b74 / 3) * 3) {
          local_b94 = *(int *)(in_EDX + *(int *)(in_EAX + local_b88 * 4) * 4);
        }
        else if (local_b74 % 3 == 1) {
          local_b94 = *(int *)(in_EDX + *(int *)(in_EAX + (local_b7c + local_b88 >> 1) * 4) * 4);
        }
        else {
          local_b94 = *(int *)(in_EDX + *(int *)(in_EAX + local_b7c * 4) * 4);
        }
        local_b84 = local_b7c;
        local_b80 = local_b88;
        iVar12 = local_b7c;
        iVar10 = local_b88;
LAB_000ce373:
        while (iVar4 = iVar10, local_b8c = iVar4 + 1, iVar15 = iVar12, iVar4 <= iVar12) {
          iVar10 = *(int *)(in_EAX + -4 + local_b8c * 4);
          iVar11 = *(int *)(in_EDX + iVar10 * 4);
          if (iVar11 == local_b94) {
            piVar7 = (int *)(in_EAX + local_b80 * 4);
            *(int *)(in_EAX + -4 + local_b8c * 4) = *piVar7;
            *piVar7 = iVar10;
            local_b80 = local_b80 + 1;
            iVar10 = local_b8c;
          }
          else {
            iVar10 = local_b8c;
            if (0 < iVar11 - local_b94) {
              piVar7 = (int *)(in_EAX + iVar12 * 4);
              do {
                iVar12 = iVar15 + -1;
                iVar10 = *piVar7;
                iVar11 = *(int *)(in_EDX + iVar10 * 4);
                if (iVar11 == local_b94) {
                  piVar2 = (int *)(in_EAX + local_b84 * 4);
                  *piVar7 = *piVar2;
                  *piVar2 = iVar10;
                  local_b84 = local_b84 + -1;
                }
                else if (iVar11 - local_b94 < 0) goto LAB_000ce527;
                piVar7 = piVar7 + -1;
                iVar15 = iVar12;
                if (iVar12 < iVar4) goto LAB_000ce386;
              } while( true );
            }
          }
        }
LAB_000ce386:
        if (local_b84 < local_b80) goto LAB_000ce2c7;
        iVar12 = local_b80 - local_b88;
        if (iVar4 - local_b80 < local_b80 - local_b88) {
          iVar12 = iVar4 - local_b80;
        }
        if (0 < iVar12) {
          iVar11 = iVar4 - iVar12;
          iVar10 = local_b88;
          do {
            uVar5 = *(undefined4 *)(in_EAX + iVar10 * 4);
            *(undefined4 *)(in_EAX + iVar10 * 4) = *(undefined4 *)(in_EAX + iVar11 * 4);
            *(undefined4 *)(in_EAX + iVar11 * 4) = uVar5;
            iVar10 = iVar10 + 1;
            iVar11 = iVar11 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        iVar12 = local_b7c - local_b84;
        if (local_b84 - iVar15 < local_b7c - local_b84) {
          iVar12 = local_b84 - iVar15;
        }
        if (0 < iVar12) {
          iVar11 = (local_b7c + 1) - iVar12;
          iVar10 = iVar4;
          do {
            uVar5 = *(undefined4 *)(in_EAX + iVar10 * 4);
            *(undefined4 *)(in_EAX + iVar10 * 4) = *(undefined4 *)(in_EAX + iVar11 * 4);
            *(undefined4 *)(in_EAX + iVar11 * 4) = uVar5;
            iVar10 = iVar10 + 1;
            iVar11 = iVar11 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        local_b80 = (local_b88 + -1 + iVar4) - local_b80;
        local_b84 = (iVar15 + local_b7c + 1) - local_b84;
        if (local_b7c - local_b84 < local_b80 - local_b88) {
          local_1ac[iVar8] = local_b88;
          local_33c[iVar8] = local_b80;
          local_1ac[local_b68] = local_b84;
          local_33c[local_b68] = local_b7c;
          local_b68 = local_b68 + 1;
        }
        else {
          local_1ac[iVar8] = local_b84;
          local_33c[iVar8] = local_b7c;
          local_1ac[local_b68] = local_b88;
          local_33c[local_b68] = local_b80;
          local_b68 = local_b68 + 1;
        }
      }
      if (99 < local_b68) {
        BZ2_bz__AssertH__fail(0x3ec);
      }
      local_b88 = local_1ac[local_b68 + -1];
      local_b7c = local_33c[local_b68 + -1];
    } while( true );
  }
  goto LAB_000ce0ad;
joined_r0x000ce5bb:
  while (uVar3 == 0) {
    uVar9 = uVar9 + 0x20;
    uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
  }
  local_b70 = uVar9 - 1;
  if ((1 << ((byte)uVar9 & 0x1f) & uVar3) != 0) goto LAB_000ce16a;
  do {
    uVar9 = uVar9 + 1;
  } while ((*(uint *)(in_ECX + ((int)uVar9 >> 5) * 4) & 1 << ((byte)uVar9 & 0x1f)) == 0);
  goto LAB_000ce163;
LAB_000ce6a9:
  if (3 < param_2) {
                    /* try { // try from 000ce74e to 000de80b has its CatchHandler @ 000ce819 */
    fprintf(_stderr,"%6d unresolved strings\n",local_b54);
  }
  local_b5c = local_b5c << 1;
  if ((local_b54 == 0) || (param_1 < local_b5c)) {
    if (3 < param_2) {
      fwrite("        reconstructing block ...\n",1,0x21,_stderr);
    }
    iVar6 = 0;
    for (iVar8 = 0; iVar8 < param_1; iVar8 = iVar8 + 1) {
      for (; local_73c[iVar6] == 0; iVar6 = iVar6 + 1) {
      }
      local_73c[iVar6] = local_73c[iVar6] + -1;
                    /* catch() { ... } // from try @ 000ce814 with catch @ 000ce700 */
      *(char *)(in_EDX + *(int *)(in_EAX + iVar8 * 4)) = (char)iVar6;
    }
    if (0xff < iVar6) {
      BZ2_bz__AssertH__fail();
      return;
    }
    return;
  }
  goto LAB_000ce036;
LAB_000ce527:
  if (iVar15 < iVar4) goto LAB_000ce386;
  iVar4 = *(int *)(in_EAX + -4 + local_b8c * 4);
  *(int *)(in_EAX + -4 + local_b8c * 4) = iVar10;
  *piVar7 = iVar4;
  iVar10 = local_b8c;
  goto LAB_000ce373;
LAB_000ce645:
  iVar8 = -1;
  do {
    iVar12 = *(int *)(in_EDX + *(int *)(in_EAX + iVar6 * 4) * 4);
    if (iVar8 != iVar12) {
      puVar1 = (uint *)(in_ECX + (iVar6 >> 3 & 0xfffffffcU));
      *puVar1 = *puVar1 | 1 << ((byte)iVar6 & 0x1f);
      iVar8 = iVar12;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 <= local_b70);
  goto LAB_000ce0ad;
}


// fran1  @ 00073820
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float fran1(void)

{
  float fVar1;
  int32 iVar2;
  
                    /* Unresolved local var: float temp@[???] */
  iVar2 = ran1();
  fVar1 = 0.9999999;
  if ((float)iVar2 * 4.656613e-10 <= 0.9999999) {
    fVar1 = (float)iVar2 * 4.656613e-10;
  }
  return fVar1;
}


// hudCheckParm  @ 00074720
int hudCheckParm(char *parm,char **ppnext)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[DW_OP_reg0(EAX)] */
  (*g_engdstAddrs.CheckParm)(&parm,&ppnext);
  iVar1 = COM_CheckParm(parm);
  if (ppnext != (char **)0x0) {
    if ((iVar1 != 0) && (iVar1 < com_argc + -1)) {
      *ppnext = com_argv[iVar1 + 1];
      return iVar1;
    }
    *ppnext = (char *)0x0;
  }
  return iVar1;
}


// iGetIndex  @ 000704c0
int iGetIndex(char *pszField)

{
  int iVar1;
  undefined1 *puVar2;
  int in_GS_OFFSET;
  char local_4b4 [511];
  undefined1 local_2b5;
  undefined1 local_2b4 [4];
  undefined1 local_2b0 [180];
  undefined1 local_1fc [4];
  undefined1 local_1f8 [4];
  undefined1 local_1f4 [264];
  undefined1 local_ec [4];
  undefined1 local_e8 [4];
  undefined1 local_e4 [4];
  undefined1 local_e0 [20];
  undefined1 local_cc [4];
  undefined1 local_c8 [4];
  undefined1 local_c4 [4];
  undefined1 local_c0 [176];
  int local_10;
  
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: char[512] sz@[???]
                       Unresolved local var: entvars_t t@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_strncpy(local_4b4,pszField,0x1ff);
  local_2b5 = 0;
  Q_strlwr(local_4b4);
  iVar1 = Q_strcmp(local_4b4,"classname");
  if (iVar1 == 0) {
    puVar2 = local_2b4;
  }
  else {
    iVar1 = Q_strcmp(local_4b4,"model");
    if (iVar1 == 0) {
      puVar2 = local_1fc;
    }
    else {
      iVar1 = Q_strcmp(local_4b4,"viewmodel");
      if (iVar1 == 0) {
        puVar2 = local_1f8;
      }
      else {
        iVar1 = Q_strcmp(local_4b4,"weaponmodel");
        if (iVar1 == 0) {
          puVar2 = local_1f4;
        }
        else {
          iVar1 = Q_strcmp(local_4b4,"netname");
          if (iVar1 == 0) {
            puVar2 = local_e4;
          }
          else {
            iVar1 = Q_strcmp(local_4b4,"target");
            if (iVar1 == 0) {
              puVar2 = local_ec;
            }
            else {
              iVar1 = Q_strcmp(local_4b4,"targetname");
              if (iVar1 == 0) {
                puVar2 = local_e8;
              }
              else {
                iVar1 = Q_strcmp(local_4b4,"message");
                if (iVar1 == 0) {
                  puVar2 = local_e0;
                }
                else {
                  iVar1 = Q_strcmp(local_4b4,"noise");
                  if (iVar1 == 0) {
                    puVar2 = local_cc;
                  }
                  else {
                    iVar1 = Q_strcmp(local_4b4,"noise1");
                    if (iVar1 == 0) {
                      puVar2 = local_c8;
                    }
                    else {
                      iVar1 = Q_strcmp(local_4b4,"noise2");
                      if (iVar1 == 0) {
                        puVar2 = local_c4;
                      }
                      else {
                        iVar1 = Q_strcmp(local_4b4,"noise3");
                        if (iVar1 == 0) {
                          puVar2 = local_c0;
                        }
                        else {
                          iVar1 = Q_strcmp(local_4b4,"globalname");
                          if (iVar1 != 0) {
                            iVar1 = -1;
                            goto LAB_00070527;
                          }
                          puVar2 = local_2b0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  iVar1 = (int)puVar2 - (int)local_2b4;
LAB_00070527:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// mainSort  @ 000ce7cf
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mainSort(int param_1,uint param_2,int param_3,int *param_4)

{
  uint *puVar1;
  uint *puVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 uVar6;
  byte bVar7;
  int in_EAX;
  int iVar8;
  byte *pbVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  int in_ECX;
  int iVar13;
  uint uVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  byte bVar18;
  byte *in_EDX;
  uint uVar19;
  undefined2 *puVar20;
  int iVar21;
  int iVar22;
  byte bVar23;
  int *piVar24;
  int iVar25;
  int iVar26;
  undefined2 uVar27;
  int iVar28;
  int iVar29;
  uint uVar30;
  bool bVar31;
  bool bVar32;
  uint local_1260;
  int local_1250;
  int local_124c;
  uint local_1248;
  int local_1240;
  int *local_123c;
  int *local_1238;
  int local_1234;
  int local_1230;
  int local_122c;
  int local_1228;
  uint local_1220;
  int *local_121c;
  int local_120c;
  int local_1204;
  int local_1200;
  uint *local_11fc;
  int local_11f4;
  int local_11e8;
  int local_11e4;
  int local_11d0;
  int local_11cc [256];
  uint local_dcc [256];
  int aiStack_9cc [256];
  int local_5cc [100];
  int local_43c [100];
  uint local_2ac [100];
  char local_11c [268];
  
  if (3 < param_3) {
                    /* try { // try from 000ce814 to 000de839 has its CatchHandler @ 000ce700 */
                    /* catch() { ... } // from try @ 000ce74e with catch @ 000ce819 */
    fwrite("        main sort initialise ...\n",1,0x21,_stderr);
  }
  iVar8 = 0x10000;
  do {
    *(undefined4 *)(param_1 + iVar8 * 4) = 0;
    iVar8 = iVar8 + -1;
  } while (iVar8 != -1);
  uVar19 = (uint)*in_EDX << 8;
  iVar13 = param_2 - 1;
  for (iVar8 = iVar13; 2 < iVar8; iVar8 = iVar8 + -4) {
    *(undefined2 *)(in_ECX + iVar8 * 2) = 0;
    uVar19 = (int)uVar19 >> 8 | (uint)in_EDX[iVar8] << 8;
    piVar15 = (int *)(param_1 + uVar19 * 4);
    *piVar15 = *piVar15 + 1;
    *(undefined2 *)(in_ECX + -2 + iVar8 * 2) = 0;
    uVar19 = (int)uVar19 >> 8 | (uint)in_EDX[iVar8 + -1] << 8;
    piVar15 = (int *)(param_1 + uVar19 * 4);
    *piVar15 = *piVar15 + 1;
    *(undefined2 *)(in_ECX + -4 + iVar8 * 2) = 0;
    uVar19 = (int)uVar19 >> 8 | (uint)in_EDX[iVar8 + -2] << 8;
    piVar15 = (int *)(param_1 + uVar19 * 4);
    *piVar15 = *piVar15 + 1;
    *(undefined2 *)(in_ECX + -6 + iVar8 * 2) = 0;
    uVar19 = (int)uVar19 >> 8 | (uint)in_EDX[iVar8 + -3] << 8;
    piVar15 = (int *)(param_1 + uVar19 * 4);
    *piVar15 = *piVar15 + 1;
  }
  for (; -1 < iVar8; iVar8 = iVar8 + -1) {
    *(undefined2 *)(in_ECX + iVar8 * 2) = 0;
    uVar19 = (int)uVar19 >> 8 | (uint)in_EDX[iVar8] << 8;
    piVar15 = (int *)(param_1 + uVar19 * 4);
    *piVar15 = *piVar15 + 1;
  }
  puVar20 = (undefined2 *)(in_ECX + param_2 * 2);
  iVar8 = 0;
  pbVar9 = in_EDX;
  do {
    pbVar9[param_2] = *pbVar9;
    *puVar20 = 0;
    iVar8 = iVar8 + 1;
    pbVar9 = pbVar9 + 1;
    puVar20 = puVar20 + 1;
  } while (iVar8 != 0x22);
  if (3 < param_3) {
    fwrite("        bucket sorting ...\n",1,0x1b,_stderr);
  }
  iVar8 = 1;
  do {
    piVar15 = (int *)(param_1 + iVar8 * 4);
    *piVar15 = *piVar15 + *(int *)(param_1 + -4 + iVar8 * 4);
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0x10001);
  bVar23 = *in_EDX;
  for (iVar8 = iVar13; uVar19 = (uint)bVar23 << 8, 2 < iVar8; iVar8 = iVar8 + -4) {
    bVar3 = in_EDX[iVar8];
    piVar15 = (int *)(param_1 + (uint)CONCAT11(bVar3,bVar23) * 4);
    iVar21 = *piVar15 + -1;
    *piVar15 = iVar21;
    *(int *)(in_EAX + iVar21 * 4) = iVar8;
    bVar23 = in_EDX[iVar8 + -1];
    piVar15 = (int *)(param_1 + (uint)CONCAT11(bVar23,bVar3) * 4);
    iVar21 = *piVar15 + -1;
    *piVar15 = iVar21;
    *(int *)(in_EAX + iVar21 * 4) = iVar8 + -1;
    bVar3 = in_EDX[iVar8 + -2];
    piVar15 = (int *)(param_1 + (uint)CONCAT11(bVar3,bVar23) * 4);
    iVar21 = *piVar15 + -1;
    *piVar15 = iVar21;
    *(int *)(in_EAX + iVar21 * 4) = iVar8 + -2;
    bVar23 = in_EDX[iVar8 + -3];
    piVar15 = (int *)(param_1 + (uint)CONCAT11(bVar23,bVar3) * 4);
    iVar21 = *piVar15 + -1;
    *piVar15 = iVar21;
    *(int *)(in_EAX + iVar21 * 4) = iVar8 + -3;
  }
  for (; -1 < iVar8; iVar8 = iVar8 + -1) {
    uVar14 = uVar19 >> 8;
    uVar19 = (uint)in_EDX[iVar8] << 8;
    piVar15 = (int *)(param_1 + (uVar14 | uVar19) * 4);
    iVar21 = *piVar15 + -1;
    *piVar15 = iVar21;
    *(int *)(in_EAX + iVar21 * 4) = iVar8;
  }
  iVar8 = 0;
  do {
    local_11c[iVar8] = '\0';
    aiStack_9cc[iVar8] = iVar8;
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0x100);
  iVar8 = 5;
  local_122c = 1;
  do {
    local_122c = local_122c * 3 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  do {
    do {
      local_122c = local_122c / 3;
    } while (0xff < local_122c);
    local_1234 = 0;
    local_1230 = local_122c;
    do {
      iVar8 = aiStack_9cc[local_1230];
      iVar21 = *(int *)(param_1 + (iVar8 + 1) * 0x400);
      iVar22 = *(int *)(param_1 + iVar8 * 0x400);
      piVar15 = aiStack_9cc + local_1234;
      piVar24 = aiStack_9cc + local_1230;
      local_1250 = local_122c + local_1234;
      iVar16 = local_1234;
      do {
        local_1240 = iVar16;
        iVar16 = *piVar15;
        if ((uint)(*(int *)(param_1 + (iVar16 + 1) * 0x400) - *(int *)(param_1 + iVar16 * 0x400)) <=
            (uint)(iVar21 - iVar22)) {
          local_1240 = local_1250;
          break;
        }
        *piVar24 = iVar16;
        piVar15 = piVar15 + -local_122c;
        piVar24 = piVar24 + -local_122c;
        local_1250 = local_122c + (local_1240 - local_122c);
        iVar16 = local_1240 - local_122c;
      } while (local_122c <= local_1250);
      aiStack_9cc[local_1240] = iVar8;
      local_1230 = local_1230 + 1;
      local_1234 = local_1234 + 1;
    } while (local_1230 != 0x100);
  } while (local_122c != 1);
  local_11e8 = 0;
  local_11e4 = 0;
LAB_000cebd1:
  iVar8 = aiStack_9cc[local_11e4];
  puVar10 = (uint *)(iVar8 * 0x400 + param_1);
  local_1200 = 0;
  local_11fc = puVar10;
LAB_000cec0b:
  if (local_1200 != iVar8) {
    uVar19 = *local_11fc;
    if ((uVar19 & 0x200000) == 0) {
      uVar14 = uVar19 & 0xffdfffff;
      iVar21 = (local_11fc[1] & 0xffdfffff) - 1;
      if ((int)uVar14 < iVar21) {
        if (3 < param_3) {
          fprintf(_stderr,"        qsort [0x%x, 0x%x]   done %d   this %d\n",iVar8,local_1200,
                  local_11e8,(iVar21 - uVar14) + 1);
        }
        local_2ac[0] = uVar14;
        local_43c[0] = iVar21;
        local_5cc[0] = 2;
        local_1238 = (int *)0x1;
        local_120c = 0;
LAB_000cece2:
        local_1220 = local_2ac[local_120c];
        local_1230 = local_43c[local_120c];
        iVar22 = local_5cc[local_120c];
        if (((int)(local_1230 - local_1220) < 0x14) || (0xe < iVar22)) {
          iVar16 = (local_1230 - local_1220) + 1;
          if (1 < iVar16) {
            iVar25 = 0;
            do {
              local_11f4 = iVar25;
              iVar25 = local_11f4 + 1;
            } while (*(int *)(incs + (local_11f4 + 1) * 4) < iVar16);
            do {
              iVar16 = *(int *)(incs + local_11f4 * 4);
              iVar25 = local_1220 + iVar16;
              if (iVar25 <= local_1230) {
                local_1228 = iVar25 - iVar16;
                iVar11 = -iVar16;
                local_121c = (int *)(in_EAX + ((2 - iVar16) + iVar25) * 4);
                local_1234 = iVar25;
                do {
                  iVar17 = *(int *)(in_EAX + local_1234 * 4);
                  iVar28 = iVar17 + iVar22;
                  local_1240 = local_1228 + iVar16;
                  piVar15 = local_121c + -2;
                  iVar26 = local_1228;
                  do {
                    local_123c = piVar15;
                    iVar29 = iVar22 + *local_123c;
                    bVar31 = in_EDX[iVar29] < in_EDX[iVar28];
                    bVar32 = in_EDX[iVar29] == in_EDX[iVar28];
                    if (bVar32) {
                      bVar31 = in_EDX[iVar29 + 1] < in_EDX[iVar28 + 1];
                      bVar32 = in_EDX[iVar29 + 1] == in_EDX[iVar28 + 1];
                      if (!bVar32) goto LAB_000cf3fb;
                      bVar31 = in_EDX[iVar29 + 2] < in_EDX[iVar28 + 2];
                      bVar32 = in_EDX[iVar29 + 2] == in_EDX[iVar28 + 2];
                      if (!bVar32) goto LAB_000cf3fb;
                      bVar31 = in_EDX[iVar29 + 3] < in_EDX[iVar28 + 3];
                      bVar32 = in_EDX[iVar29 + 3] == in_EDX[iVar28 + 3];
                      if (!bVar32) goto LAB_000cf3fb;
                      bVar31 = in_EDX[iVar29 + 4] < in_EDX[iVar28 + 4];
                      bVar32 = in_EDX[iVar29 + 4] == in_EDX[iVar28 + 4];
                      if (!bVar32) goto LAB_000cf3fb;
                      bVar31 = in_EDX[iVar29 + 5] < in_EDX[iVar28 + 5];
                      bVar32 = in_EDX[iVar29 + 5] == in_EDX[iVar28 + 5];
                      if (!bVar32) goto LAB_000cf3fb;
                      bVar31 = in_EDX[iVar29 + 6] < in_EDX[iVar28 + 6];
                      bVar32 = in_EDX[iVar29 + 6] == in_EDX[iVar28 + 6];
                      if (!bVar32) goto LAB_000cf3fb;
                      bVar31 = in_EDX[iVar29 + 7] < in_EDX[iVar28 + 7];
                      bVar32 = in_EDX[iVar29 + 7] == in_EDX[iVar28 + 7];
                      if (!bVar32) goto LAB_000cf3fb;
                      bVar31 = in_EDX[iVar29 + 8] < in_EDX[iVar28 + 8];
                      bVar32 = in_EDX[iVar29 + 8] == in_EDX[iVar28 + 8];
                      if (!bVar32) goto LAB_000cf3fb;
                      bVar31 = in_EDX[iVar29 + 9] < in_EDX[iVar28 + 9];
                      bVar32 = in_EDX[iVar29 + 9] == in_EDX[iVar28 + 9];
                      if (!bVar32) goto LAB_000cf3fb;
                      bVar31 = in_EDX[iVar29 + 10] < in_EDX[iVar28 + 10];
                      bVar32 = in_EDX[iVar29 + 10] == in_EDX[iVar28 + 10];
                      if (!bVar32) goto LAB_000cf3fb;
                      bVar31 = in_EDX[iVar29 + 0xb] < in_EDX[iVar28 + 0xb];
                      bVar32 = in_EDX[iVar29 + 0xb] == in_EDX[iVar28 + 0xb];
                      if (!bVar32) goto LAB_000cf3fb;
                      local_1260 = iVar29 + 0xc;
                      uVar19 = iVar28 + 0xc;
                      local_11d0 = param_2 + 8;
                      while( true ) {
                        bVar31 = in_EDX[local_1260] < in_EDX[uVar19];
                        bVar32 = in_EDX[local_1260] == in_EDX[uVar19];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + uVar19 * 2);
                        uVar5 = *(ushort *)(in_ECX + local_1260 * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                        bVar31 = in_EDX[local_1260 + 1] < in_EDX[uVar19 + 1];
                        bVar32 = in_EDX[local_1260 + 1] == in_EDX[uVar19 + 1];
                        if (!bVar32) {
LAB_000d011d:
                          bVar31 = !bVar31 && !bVar32;
                          goto LAB_000cf3fe;
                        }
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 1) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 1) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000d011d;
                        bVar31 = in_EDX[local_1260 + 2] < in_EDX[uVar19 + 2];
                        bVar32 = in_EDX[local_1260 + 2] == in_EDX[uVar19 + 2];
                        if (!bVar32) goto LAB_000d011d;
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 2) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 2) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000d011d;
                        bVar31 = in_EDX[local_1260 + 3] < in_EDX[uVar19 + 3];
                        bVar32 = in_EDX[local_1260 + 3] == in_EDX[uVar19 + 3];
                        if (!bVar32) goto LAB_000d011d;
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 3) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 3) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000d011d;
                        bVar31 = in_EDX[local_1260 + 4] < in_EDX[uVar19 + 4];
                        bVar32 = in_EDX[local_1260 + 4] == in_EDX[uVar19 + 4];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 4) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 4) * 2);
                        if (uVar5 != uVar4) {
                          bVar31 = uVar4 < uVar5;
                          goto LAB_000cf3fe;
                        }
                        bVar31 = in_EDX[local_1260 + 5] < in_EDX[uVar19 + 5];
                        bVar32 = in_EDX[local_1260 + 5] == in_EDX[uVar19 + 5];
                        if (!bVar32) {
LAB_000d00c6:
                          bVar31 = !bVar31 && !bVar32;
                          goto LAB_000cf3fe;
                        }
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 5) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 5) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000d00c6;
                        bVar31 = in_EDX[local_1260 + 6] < in_EDX[uVar19 + 6];
                        bVar32 = in_EDX[local_1260 + 6] == in_EDX[uVar19 + 6];
                        if (!bVar32) goto LAB_000d00c6;
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 6) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 6) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000d00c6;
                        bVar31 = in_EDX[local_1260 + 7] < in_EDX[uVar19 + 7];
                        bVar32 = in_EDX[local_1260 + 7] == in_EDX[uVar19 + 7];
                        if (!bVar32) goto LAB_000cf3fb;
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 7) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 7) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000cf3fb;
                        uVar30 = local_1260 + 8;
                        uVar19 = uVar19 + 8;
                        local_1260 = uVar30 - param_2;
                        if (uVar30 < param_2) {
                          local_1260 = uVar30;
                        }
                        if (param_2 <= uVar19) {
                          uVar19 = uVar19 - param_2;
                        }
                    /* catch() { ... } // from try @ 000cf959 with catch @ 000cf6f0 */
                        *param_4 = *param_4 + -1;
                        local_11d0 = local_11d0 + -8;
                        if (local_11d0 < 0) {
                          local_123c = (int *)(in_EAX + local_1240 * 4);
                          goto LAB_000cf726;
                        }
                      }
                      bVar31 = !bVar31 && !bVar32;
                    }
                    else {
LAB_000cf3fb:
                      bVar31 = !bVar31 && !bVar32;
                    }
LAB_000cf3fe:
                    if (!bVar31) {
                      local_123c = (int *)(in_EAX + local_1240 * 4);
                      break;
                    }
                    local_123c[iVar16] = *local_123c;
                    iVar26 = iVar26 + iVar11;
                    local_1240 = iVar26 + iVar16;
                    piVar15 = local_123c + -iVar16;
                  } while (iVar25 <= local_1240);
LAB_000cf726:
                  *local_123c = iVar17;
                  if (local_1230 < local_1234 + 1) break;
                  iVar26 = *(int *)(in_EAX + 4 + local_1234 * 4);
                  iVar28 = local_1228 + 1;
                    /* try { // try from 000cf764 to 000df768 has its CatchHandler @ 000cf8a4 */
                  local_1240 = iVar28 + iVar16;
                  iVar17 = iVar22 + iVar26;
                  piVar15 = local_121c + -1;
                  do {
                    local_1238 = piVar15;
                    iVar29 = iVar22 + *local_1238;
                    bVar31 = in_EDX[iVar29] < in_EDX[iVar17];
                    bVar32 = in_EDX[iVar29] == in_EDX[iVar17];
                    if (bVar32) {
                    /* try { // try from 000cf7d2 to 000df7d6 has its CatchHandler @ 000cf8ac */
                      bVar31 = in_EDX[iVar29 + 1] < in_EDX[iVar17 + 1];
                      bVar32 = in_EDX[iVar29 + 1] == in_EDX[iVar17 + 1];
                      if (!bVar32) goto LAB_000cf786;
                      bVar31 = in_EDX[iVar29 + 2] < in_EDX[iVar17 + 2];
                      bVar32 = in_EDX[iVar29 + 2] == in_EDX[iVar17 + 2];
                      if (!bVar32) goto LAB_000cf786;
                      bVar31 = in_EDX[iVar29 + 3] < in_EDX[iVar17 + 3];
                      bVar32 = in_EDX[iVar29 + 3] == in_EDX[iVar17 + 3];
                      if (!bVar32) goto LAB_000cf786;
                    /* try { // try from 000cf7f8 to 000df7fc has its CatchHandler @ 000cf8b5 */
                      bVar31 = in_EDX[iVar29 + 4] < in_EDX[iVar17 + 4];
                      bVar32 = in_EDX[iVar29 + 4] == in_EDX[iVar17 + 4];
                      if (!bVar32) goto LAB_000cf786;
                      bVar31 = in_EDX[iVar29 + 5] < in_EDX[iVar17 + 5];
                      bVar32 = in_EDX[iVar29 + 5] == in_EDX[iVar17 + 5];
                      if (!bVar32) goto LAB_000cf786;
                    /* try { // try from 000cf81e to 000df822 has its CatchHandler @ 000cf8a8 */
                      bVar31 = in_EDX[iVar29 + 6] < in_EDX[iVar17 + 6];
                      bVar32 = in_EDX[iVar29 + 6] == in_EDX[iVar17 + 6];
                      if (!bVar32) goto LAB_000cf786;
                      bVar31 = in_EDX[iVar29 + 7] < in_EDX[iVar17 + 7];
                      bVar32 = in_EDX[iVar29 + 7] == in_EDX[iVar17 + 7];
                      if (!bVar32) goto LAB_000cf786;
                      bVar31 = in_EDX[iVar29 + 8] < in_EDX[iVar17 + 8];
                      bVar32 = in_EDX[iVar29 + 8] == in_EDX[iVar17 + 8];
                      if (!bVar32) goto LAB_000cf786;
                      bVar31 = in_EDX[iVar29 + 9] < in_EDX[iVar17 + 9];
                      bVar32 = in_EDX[iVar29 + 9] == in_EDX[iVar17 + 9];
                      if (!bVar32) goto LAB_000cf786;
                      bVar31 = in_EDX[iVar29 + 10] < in_EDX[iVar17 + 10];
                      bVar32 = in_EDX[iVar29 + 10] == in_EDX[iVar17 + 10];
                      if (!bVar32) goto LAB_000cf786;
                      bVar31 = in_EDX[iVar29 + 0xb] < in_EDX[iVar17 + 0xb];
                      bVar32 = in_EDX[iVar29 + 0xb] == in_EDX[iVar17 + 0xb];
                      if (!bVar32) goto LAB_000cf786;
                      uVar19 = iVar29 + 0xc;
                      uVar30 = iVar17 + 0xc;
                    /* catch() { ... } // from try @ 000cf81e with catch @ 000cf8a8 */
                      local_1204 = param_2 + 8;
                    /* catch() { ... } // from try @ 000cf7d2 with catch @ 000cf8ac */
                    /* catch() { ... } // from try @ 000cf7f8 with catch @ 000cf8b5 */
                    /* catch() { ... } // from try @ 000cf79b with catch @ 000cf8bc */
                      while( true ) {
                        bVar31 = in_EDX[uVar19] < in_EDX[uVar30];
                        bVar32 = in_EDX[uVar19] == in_EDX[uVar30];
                    /* try { // try from 000cf8dd to 000df8e1 has its CatchHandler @ 000cf6f0 */
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + uVar30 * 2);
                        uVar5 = *(ushort *)(in_ECX + uVar19 * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                        bVar31 = in_EDX[uVar19 + 1] < in_EDX[uVar30 + 1];
                        bVar32 = in_EDX[uVar19 + 1] == in_EDX[uVar30 + 1];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 1) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 1) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                        bVar31 = in_EDX[uVar19 + 2] < in_EDX[uVar30 + 2];
                        bVar32 = in_EDX[uVar19 + 2] == in_EDX[uVar30 + 2];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 2) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 2) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                    /* try { // try from 000cf959 to 000df95d has its CatchHandler @ 000cf6f0 */
                        bVar31 = in_EDX[uVar19 + 3] < in_EDX[uVar30 + 3];
                        bVar32 = in_EDX[uVar19 + 3] == in_EDX[uVar30 + 3];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 3) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 3) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                        bVar31 = in_EDX[uVar19 + 4] < in_EDX[uVar30 + 4];
                        bVar32 = in_EDX[uVar19 + 4] == in_EDX[uVar30 + 4];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 4) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 4) * 2);
                    /* catch(type#1 @ 00010000) { ... } // from try @ 000cfbce with catch @ 000cf9b0
                        */
                        if (uVar5 != uVar4) {
                          bVar31 = uVar4 < uVar5;
                          goto LAB_000cf789;
                        }
                        bVar31 = in_EDX[uVar19 + 5] < in_EDX[uVar30 + 5];
                        bVar32 = in_EDX[uVar19 + 5] == in_EDX[uVar30 + 5];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 5) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 5) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                    /* try { // try from 000cf9ee to 000df9f2 has its CatchHandler @ 000cf9b0 */
                        bVar31 = in_EDX[uVar19 + 6] < in_EDX[uVar30 + 6];
                        bVar32 = in_EDX[uVar19 + 6] == in_EDX[uVar30 + 6];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 6) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 6) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                    /* try { // try from 000cfa14 to 000dfa18 has its CatchHandler @ 000cfb7c */
                        bVar31 = in_EDX[uVar19 + 7] < in_EDX[uVar30 + 7];
                        bVar32 = in_EDX[uVar19 + 7] == in_EDX[uVar30 + 7];
                        if (!bVar32) goto LAB_000cf786;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 7) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 7) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000cf786;
                        uVar19 = uVar19 + 8;
                        uVar30 = uVar30 + 8;
                        if (param_2 <= uVar19) {
                          uVar19 = uVar19 - param_2;
                        }
                        if (param_2 <= uVar30) {
                          uVar30 = uVar30 - param_2;
                        }
                        *param_4 = *param_4 + -1;
                        local_1204 = local_1204 + -8;
                        if (local_1204 < 0) {
                          local_1238 = (int *)(in_EAX + local_1240 * 4);
                          goto LAB_000cfab2;
                        }
                      }
                      bVar31 = !bVar31 && !bVar32;
                    }
                    else {
LAB_000cf786:
                      bVar31 = !bVar31 && !bVar32;
                    }
LAB_000cf789:
                    if (!bVar31) {
                      local_1238 = (int *)(in_EAX + local_1240 * 4);
                      break;
                    }
                    local_1238[iVar16] = *local_1238;
                    iVar28 = iVar28 + iVar11;
                    /* try { // try from 000cf79b to 000df79f has its CatchHandler @ 000cf8bc */
                    local_1240 = iVar28 + iVar16;
                    piVar15 = local_1238 + -iVar16;
                  } while (iVar25 <= local_1240);
LAB_000cfab2:
                  *local_1238 = iVar26;
                  if (local_1230 < local_1234 + 2) break;
                  iVar26 = *(int *)(in_EAX + 8 + local_1234 * 4);
                  iVar28 = local_1228 + 2;
                  local_1240 = iVar16 + iVar28;
                  iVar17 = iVar22 + iVar26;
                  piVar15 = local_121c;
                  do {
                    local_1238 = piVar15;
                    iVar29 = iVar22 + *local_1238;
                    bVar31 = in_EDX[iVar29] < in_EDX[iVar17];
                    bVar32 = in_EDX[iVar29] == in_EDX[iVar17];
                    if (bVar32) {
                      bVar31 = in_EDX[iVar29 + 1] < in_EDX[iVar17 + 1];
                      bVar32 = in_EDX[iVar29 + 1] == in_EDX[iVar17 + 1];
                      if (!bVar32) goto LAB_000cfb14;
                      bVar31 = in_EDX[iVar29 + 2] < in_EDX[iVar17 + 2];
                      bVar32 = in_EDX[iVar29 + 2] == in_EDX[iVar17 + 2];
                      if (!bVar32) goto LAB_000cfb14;
                    /* catch(type#1 @ 00010000) { ... } // from try @ 000cfa14 with catch @ 000cfb7c
                        */
                      bVar31 = in_EDX[iVar29 + 3] < in_EDX[iVar17 + 3];
                      bVar32 = in_EDX[iVar29 + 3] == in_EDX[iVar17 + 3];
                      if (!bVar32) goto LAB_000cfb14;
                      bVar31 = in_EDX[iVar29 + 4] < in_EDX[iVar17 + 4];
                      bVar32 = in_EDX[iVar29 + 4] == in_EDX[iVar17 + 4];
                      if (!bVar32) goto LAB_000cfb14;
                    /* try { // try from 000cfba0 to 000dfba4 has its CatchHandler @ 000cfbc4 */
                      bVar31 = in_EDX[iVar29 + 5] < in_EDX[iVar17 + 5];
                      bVar32 = in_EDX[iVar29 + 5] == in_EDX[iVar17 + 5];
                      if (!bVar32) goto LAB_000cfb14;
                      bVar31 = in_EDX[iVar29 + 6] < in_EDX[iVar17 + 6];
                      bVar32 = in_EDX[iVar29 + 6] == in_EDX[iVar17 + 6];
                      if (!bVar32) goto LAB_000cfb14;
                    /* catch(type#1 @ 00010000) { ... } // from try @ 000cfba0 with catch @ 000cfbc4
                        */
                      bVar31 = in_EDX[iVar29 + 7] < in_EDX[iVar17 + 7];
                      bVar32 = in_EDX[iVar29 + 7] == in_EDX[iVar17 + 7];
                    /* try { // try from 000cfbce to 000dfbd2 has its CatchHandler @ 000cf9b0 */
                      if (!bVar32) goto LAB_000cfb14;
                      bVar31 = in_EDX[iVar29 + 8] < in_EDX[iVar17 + 8];
                      bVar32 = in_EDX[iVar29 + 8] == in_EDX[iVar17 + 8];
                      if (!bVar32) goto LAB_000cfb14;
                      bVar31 = in_EDX[iVar29 + 9] < in_EDX[iVar17 + 9];
                      bVar32 = in_EDX[iVar29 + 9] == in_EDX[iVar17 + 9];
                      if (!bVar32) goto LAB_000cfb14;
                      bVar31 = in_EDX[iVar29 + 10] < in_EDX[iVar17 + 10];
                      bVar32 = in_EDX[iVar29 + 10] == in_EDX[iVar17 + 10];
                      if (!bVar32) goto LAB_000cfb14;
                      bVar31 = in_EDX[iVar29 + 0xb] < in_EDX[iVar17 + 0xb];
                      bVar32 = in_EDX[iVar29 + 0xb] == in_EDX[iVar17 + 0xb];
                      if (!bVar32) goto LAB_000cfb14;
                      uVar19 = iVar29 + 0xc;
                      uVar30 = iVar17 + 0xc;
                      local_1204 = param_2 + 8;
                      while( true ) {
                        bVar31 = in_EDX[uVar19] < in_EDX[uVar30];
                        bVar32 = in_EDX[uVar19] == in_EDX[uVar30];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + uVar30 * 2);
                        uVar5 = *(ushort *)(in_ECX + uVar19 * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                        bVar31 = in_EDX[uVar19 + 1] < in_EDX[uVar30 + 1];
                        bVar32 = in_EDX[uVar19 + 1] == in_EDX[uVar30 + 1];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 1) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 1) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                        bVar31 = in_EDX[uVar19 + 2] < in_EDX[uVar30 + 2];
                        bVar32 = in_EDX[uVar19 + 2] == in_EDX[uVar30 + 2];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 2) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 2) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                        bVar31 = in_EDX[uVar19 + 3] < in_EDX[uVar30 + 3];
                        bVar32 = in_EDX[uVar19 + 3] == in_EDX[uVar30 + 3];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 3) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 3) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                        bVar31 = in_EDX[uVar19 + 4] < in_EDX[uVar30 + 4];
                        bVar32 = in_EDX[uVar19 + 4] == in_EDX[uVar30 + 4];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 4) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 4) * 2);
                        if (uVar5 != uVar4) {
                          bVar31 = uVar4 < uVar5;
                          goto LAB_000cfb17;
                        }
                        bVar31 = in_EDX[uVar19 + 5] < in_EDX[uVar30 + 5];
                        bVar32 = in_EDX[uVar19 + 5] == in_EDX[uVar30 + 5];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 5) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 5) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                        bVar31 = in_EDX[uVar19 + 6] < in_EDX[uVar30 + 6];
                        bVar32 = in_EDX[uVar19 + 6] == in_EDX[uVar30 + 6];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 6) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 6) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) break;
                        bVar31 = in_EDX[uVar19 + 7] < in_EDX[uVar30 + 7];
                        bVar32 = in_EDX[uVar19 + 7] == in_EDX[uVar30 + 7];
                        if (!bVar32) goto LAB_000cfb14;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 7) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 7) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000cfb14;
                        uVar19 = uVar19 + 8;
                        uVar30 = uVar30 + 8;
                        if (param_2 <= uVar19) {
                          uVar19 = uVar19 - param_2;
                        }
                        if (param_2 <= uVar30) {
                          uVar30 = uVar30 - param_2;
                        }
                        *param_4 = *param_4 + -1;
                        local_1204 = local_1204 + -8;
                        if (local_1204 < 0) {
                          local_1238 = (int *)(in_EAX + local_1240 * 4);
                          goto LAB_000cfe46;
                        }
                      }
                      bVar31 = !bVar31 && !bVar32;
                    }
                    else {
LAB_000cfb14:
                      bVar31 = !bVar31 && !bVar32;
                    }
LAB_000cfb17:
                    if (!bVar31) {
                      local_1238 = (int *)(in_EAX + local_1240 * 4);
                      break;
                    }
                    local_1238[iVar16] = *local_1238;
                    iVar28 = iVar28 + iVar11;
                    local_1240 = iVar16 + iVar28;
                    piVar15 = local_1238 + -iVar16;
                  } while (iVar25 <= local_1240);
LAB_000cfe46:
                  *local_1238 = iVar26;
                  if (*param_4 < 0) {
                    return;
                  }
                  local_1234 = local_1234 + 3;
                  local_1228 = local_1228 + 3;
                  local_121c = local_121c + 3;
                } while (local_1234 <= local_1230);
              }
              local_11f4 = local_11f4 + -1;
            } while (local_11f4 != -1);
          }
          if (*param_4 < 0) {
            return;
          }
          if (local_120c == 0) goto LAB_000cf0aa;
          local_1238 = (int *)local_120c;
          local_120c = local_120c + -1;
        }
        else {
          bVar23 = in_EDX[iVar22 + *(int *)(in_EAX + ((int)(local_1230 + local_1220) >> 1) * 4)];
          bVar3 = in_EDX[iVar22 + *(int *)(in_EAX + local_1230 * 4)];
          bVar7 = in_EDX[iVar22 + *(int *)(in_EAX + local_1220 * 4)];
          bVar18 = bVar3;
          if (bVar7 <= bVar3) {
            bVar18 = bVar7;
            bVar7 = bVar3;
          }
          if ((bVar23 < bVar7) && (bVar7 = bVar23, bVar23 <= bVar18)) {
            bVar7 = bVar18;
          }
          uVar19 = (uint)bVar7;
          iVar16 = local_1230;
          local_1240 = local_1230;
          local_123c = (int *)local_1220;
          local_1248 = local_1220;
LAB_000cedb8:
          while (uVar30 = local_1248, local_1248 = uVar30 + 1, iVar25 = iVar16,
                (int)uVar30 <= iVar16) {
            iVar11 = *(int *)(in_EAX + -4 + local_1248 * 4);
            if (in_EDX[iVar11 + iVar22] == uVar19) {
              piVar15 = (int *)(in_EAX + (int)local_123c * 4);
              *(int *)(in_EAX + -4 + local_1248 * 4) = *piVar15;
              *piVar15 = iVar11;
              local_123c = (int *)((int)local_123c + 1);
            }
            else if (0 < (int)(in_EDX[iVar11 + iVar22] - uVar19)) {
              piVar15 = (int *)(in_EAX + iVar16 * 4);
              do {
                iVar16 = iVar25 + -1;
                iVar11 = *piVar15;
                if (in_EDX[iVar11 + iVar22] == uVar19) {
                  piVar24 = (int *)(in_EAX + local_1240 * 4);
                  *piVar15 = *piVar24;
                  *piVar24 = iVar11;
                  local_1240 = local_1240 + -1;
                }
                else if ((int)(in_EDX[iVar11 + iVar22] - uVar19) < 0) goto LAB_000cf083;
                piVar15 = piVar15 + -1;
                iVar25 = iVar16;
                if (iVar16 < (int)uVar30) goto joined_r0x000ceecc;
              } while( true );
            }
          }
joined_r0x000ceecc:
          if (local_1240 < (int)local_123c) {
            local_2ac[local_120c] = local_1220;
            local_43c[local_120c] = local_1230;
            local_5cc[local_120c] = iVar22 + 1;
          }
          else {
            iVar16 = (int)local_123c - local_1220;
            if ((int)(uVar30 - (int)local_123c) < (int)((int)local_123c - local_1220)) {
              iVar16 = uVar30 - (int)local_123c;
            }
            if (0 < iVar16) {
              iVar11 = uVar30 - iVar16;
              uVar19 = local_1220;
              do {
                uVar6 = *(undefined4 *)(in_EAX + uVar19 * 4);
                *(undefined4 *)(in_EAX + uVar19 * 4) = *(undefined4 *)(in_EAX + iVar11 * 4);
                *(undefined4 *)(in_EAX + iVar11 * 4) = uVar6;
                iVar11 = iVar11 + 1;
                uVar19 = uVar19 + 1;
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
            }
            iVar16 = local_1230 - local_1240;
            if (local_1240 - iVar25 < local_1230 - local_1240) {
              iVar16 = local_1240 - iVar25;
            }
            if (0 < iVar16) {
              iVar11 = (local_1230 + 1) - iVar16;
              uVar19 = uVar30;
              do {
                uVar6 = *(undefined4 *)(in_EAX + uVar19 * 4);
                *(undefined4 *)(in_EAX + uVar19 * 4) = *(undefined4 *)(in_EAX + iVar11 * 4);
                *(undefined4 *)(in_EAX + iVar11 * 4) = uVar6;
                iVar11 = iVar11 + 1;
                uVar19 = uVar19 + 1;
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
            }
            uVar12 = (uVar30 + local_1220) - (int)local_123c;
            iVar16 = uVar12 - 1;
            local_1240 = (iVar25 + local_1230) - local_1240;
            uVar19 = local_1240 + 1;
            local_1248 = iVar16 - local_1220;
            iVar17 = local_1230 - uVar19;
            iVar25 = iVar17;
            uVar30 = uVar19;
            iVar11 = iVar16;
            if ((int)local_1248 < iVar17) {
              iVar25 = local_1248;
              uVar30 = local_1220;
              iVar11 = local_1230;
              local_1248 = iVar17;
              local_1230 = iVar16;
              local_1220 = uVar19;
            }
            uVar19 = uVar12;
            iVar16 = local_1240;
            local_1250 = iVar22;
            local_124c = iVar22 + 1;
            if (iVar25 < (int)(local_1240 - uVar12)) {
              uVar19 = uVar30;
              iVar25 = local_1240 - uVar12;
              uVar30 = uVar12;
              iVar16 = local_1230;
              local_1250 = iVar22 + 1;
              local_124c = iVar22;
              local_1230 = local_1240;
            }
            uVar12 = uVar30;
            iVar17 = iVar11;
            local_1234 = iVar22;
            if (iVar25 <= (int)local_1248) {
              local_1234 = local_1250;
              uVar12 = local_1220;
              iVar17 = local_1230;
              local_1250 = iVar22;
              local_1230 = iVar11;
              local_1220 = uVar30;
            }
            local_2ac[local_120c] = uVar12;
            local_43c[local_120c] = local_1230;
            local_5cc[local_120c] = local_1250;
            local_2ac[(int)local_1238] = local_1220;
            local_43c[(int)local_1238] = iVar17;
            local_5cc[(int)local_1238] = local_1234;
            iVar22 = (int)local_1238 + 1;
            local_2ac[iVar22] = uVar19;
            local_43c[iVar22] = iVar16;
            local_5cc[iVar22] = local_124c;
            local_120c = (int)local_1238 + 1;
            local_1238 = (int *)((int)local_1238 + 2);
          }
        }
        if (99 < (int)local_1238) {
          BZ2_bz__AssertH__fail(0x3e9);
        }
        goto LAB_000cece2;
      }
    }
    goto LAB_000cf0d3;
  }
  goto LAB_000cf0e2;
LAB_000cf0aa:
  local_11e8 = local_11e8 + 1 + (iVar21 - uVar14);
  uVar19 = *local_11fc;
LAB_000cf0d3:
  *local_11fc = uVar19 | 0x200000;
LAB_000cf0e2:
  local_1200 = local_1200 + 1;
  local_11fc = local_11fc + 1;
  if (local_1200 == 0x100) goto code_r0x000cf103;
  goto LAB_000cec0b;
LAB_000cf083:
  if (iVar25 < (int)uVar30) goto joined_r0x000ceecc;
  iVar25 = *(int *)(in_EAX + -4 + local_1248 * 4);
  *(int *)(in_EAX + -4 + local_1248 * 4) = iVar11;
  *piVar15 = iVar25;
  goto LAB_000cedb8;
code_r0x000cf103:
  if (local_11c[iVar8] != '\0') {
    BZ2_bz__AssertH__fail(0x3ee);
  }
  iVar21 = 0;
  do {
    iVar22 = iVar21 * 0x100 + iVar8;
    local_dcc[iVar21] = *(uint *)(param_1 + iVar22 * 4) & 0xffdfffff;
    local_11cc[iVar21] = (*(uint *)(param_1 + 4 + iVar22 * 4) & 0xffdfffff) - 1;
    iVar21 = iVar21 + 1;
  } while (iVar21 != 0x100);
  uVar19 = local_dcc[iVar8];
  for (uVar14 = *puVar10 & 0xffdfffff; (int)uVar14 < (int)uVar19; uVar14 = uVar14 + 1) {
    iVar21 = *(int *)(in_EAX + uVar14 * 4) + -1;
    if (iVar21 < 0) {
      iVar21 = iVar21 + param_2;
    }
    bVar23 = in_EDX[iVar21];
    if (local_11c[bVar23] == '\0') {
      uVar19 = local_dcc[bVar23];
      *(int *)(in_EAX + uVar19 * 4) = iVar21;
      local_dcc[bVar23] = uVar19 + 1;
      uVar19 = local_dcc[iVar8];
    }
  }
  puVar2 = (uint *)(iVar8 * 0x400 + 0x400 + param_1);
  uVar14 = *puVar2 & 0xffdfffff;
  iVar21 = local_11cc[iVar8];
  while (uVar14 = uVar14 - 1, iVar21 < (int)uVar14) {
    iVar22 = *(int *)(in_EAX + uVar14 * 4) + -1;
    if (iVar22 < 0) {
      iVar22 = iVar22 + param_2;
    }
    bVar23 = in_EDX[iVar22];
    if (local_11c[bVar23] == '\0') {
      iVar21 = local_11cc[bVar23];
      *(int *)(in_EAX + iVar21 * 4) = iVar22;
      local_11cc[bVar23] = iVar21 + -1;
      iVar21 = local_11cc[iVar8];
    }
  }
  if ((uVar19 - 1 != iVar21) && ((uVar19 != 0 || (iVar13 != iVar21)))) {
    BZ2_bz__AssertH__fail(0x3ef);
  }
  iVar21 = 0;
  do {
    puVar1 = (uint *)(param_1 + (iVar21 * 0x100 + iVar8) * 4);
    *puVar1 = *puVar1 | 0x200000;
    iVar21 = iVar21 + 1;
  } while (iVar21 != 0x100);
  local_11c[iVar8] = '\x01';
  if (local_11e4 == 0xff) goto LAB_000cff70;
  iVar8 = (*puVar2 & 0xffdfffff) - (*puVar10 & 0xffdfffff);
  for (bVar23 = 0; 0xfffe < iVar8 >> (bVar23 & 0x1f); bVar23 = bVar23 + 1) {
  }
  piVar15 = (int *)(in_EAX + (((*puVar10 & 0xffdfffff) - 1) + iVar8) * 4);
  for (iVar21 = iVar8 + -1; -1 < iVar21; iVar21 = iVar21 + -1) {
    iVar22 = *piVar15;
    uVar27 = (undefined2)(iVar21 >> (bVar23 & 0x1f));
    *(undefined2 *)(in_ECX + iVar22 * 2) = uVar27;
    if (iVar22 < 0x22) {
      *(undefined2 *)(in_ECX + (iVar22 + param_2) * 2) = uVar27;
    }
    piVar15 = piVar15 + -1;
  }
  if (0xffff < iVar8 + -1 >> (bVar23 & 0x1f)) {
    BZ2_bz__AssertH__fail(0x3ea);
  }
  local_11e4 = local_11e4 + 1;
  if (local_11e4 == 0x100) {
LAB_000cff70:
    if (3 < param_3) {
      fprintf(_stderr,"        %d pointers, %d sorted, %d scanned\n",param_2,local_11e8,
              param_2 - local_11e8);
    }
    return;
  }
  goto LAB_000cebd1;
}


// memfgets  @ 000a4fa0
char * memfgets(byte *pMemFile,int fileSize,int *pFilePos,char *pBuffer,int bufferSize)

{
  byte *pbVar1;
  int iVar2;
  int count;
  int iVar3;
  
                    /* Unresolved local var: int filePos@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int last@[???]
                       Unresolved local var: int stop@[???] */
  iVar2 = *pFilePos;
  if (((pMemFile != (byte *)0x0 && pBuffer != (char *)0x0) && (iVar2 < fileSize)) &&
     ((iVar3 = iVar2, fileSize - iVar2 < bufferSize ||
      (fileSize = iVar2 + -1 + bufferSize, iVar2 < fileSize)))) {
    do {
      pbVar1 = pMemFile + iVar3;
      iVar3 = iVar3 + 1;
      if (fileSize <= iVar3) break;
    } while (*pbVar1 != '\n');
    if (iVar2 != iVar3) {
                    /* Unresolved local var: int size@[???] */
      count = iVar3 - iVar2;
      Q_memcpy(pBuffer,pMemFile + iVar2,count);
      if (count < bufferSize) {
        pBuffer[count] = '\0';
      }
      *pFilePos = iVar3;
      return pBuffer;
    }
  }
  return (char *)0x0;
}


// memsearch  @ 00040ba0
int memsearch(byte *start,int count,int search)

{
  byte bVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (count < 1) {
LAB_00040bcd:
    iVar2 = -1;
  }
  else {
    iVar2 = 0;
    bVar1 = *start;
    while (search != (uint)bVar1) {
      iVar2 = iVar2 + 1;
      if (count == iVar2) goto LAB_00040bcd;
      bVar1 = start[iVar2];
    }
  }
  return iVar2;
}


// myfeof  @ 000c586b
bool myfeof(void)

{
  FILE *in_EAX;
  int __c;
  
  __c = fgetc(in_EAX);
  if (__c != -1) {
    ungetc(__c,in_EAX);
  }
  return __c == -1;
}


// ran1  @ 00073740
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int32 ran1(void)

{
  int32 iVar1;
  int iVar2;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int32 k@[???] */
  if ((idum < 1) || (ran1::iy == 0)) {
    idum = -idum;
    iVar2 = 0x27;
    if (idum < 1) {
      idum = 1;
    }
    do {
      idum = idum * 0x41a7 + (idum / 0x1f31d) * -0x7fffffff;
      if (idum < 0) {
        idum = idum + 0x7fffffff;
      }
      if (iVar2 < 0x20) {
        ran1::iv[iVar2] = idum;
      }
      iVar2 = iVar2 + -1;
      ran1::iy = ran1::iv[0];
    } while (iVar2 != -1);
  }
  idum = idum * 0x41a7 + (idum / 0x1f31d) * -0x7fffffff;
  if (idum < 0) {
    idum = idum + 0x7fffffff;
  }
  if (ran1::iy < 0) {
    ran1::iy = ran1::iy + 0x3ffffff;
  }
  iVar1 = ran1::iv[ran1::iy >> 0x1a];
  ran1::iv[ran1::iy >> 0x1a] = idum;
  ran1::iy = iVar1;
  return iVar1;
}


// va  @ 00040ad0
char * va(char *format,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  va::current = va::current + 1U & 0xf;
  __vsnprintf_chk(va::string + va::current,0x400,1,0xffffffff,format,&stack0x00000008);
  return va::string[va::current];
}


// vstr  @ 00040b30
char * vstr(vec_t *v)

{
  vstr::idx = vstr::idx + 1U & 0xf;
  __snprintf_chk(vstr::string + vstr::idx,0x400,1,0xffffffff,"%.4f %.4f %.4f",(double)*v,
                 (double)v[1],(double)v[2]);
  return vstr::string[vstr::idx];
}


