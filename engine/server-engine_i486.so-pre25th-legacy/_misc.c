// AlertMessage  @ 00096ba0
void AlertMessage(ALERT_TYPE atype,char *szFmt,...)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: va_list argptr@[???] */
  if ((atype == at_logged) && (1 < svs.maxclients)) {
    vsnprintf(AlertMessage::szOut,0x400,szFmt,&stack0x0000000c);
    Log_Printf("%s",AlertMessage::szOut);
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
    goto LAB_00096cc2;
  case at_aiconsole:
    if (developer.value < 2.0) {
      return;
    }
LAB_00096cc2:
    AlertMessage::szOut[0] = false;
    break;
  case at_warning:
    Q_strcpy(AlertMessage::szOut,"WARNING:  ");
    break;
  case at_error:
    Q_strcpy(AlertMessage::szOut,"ERROR:  ");
  }
  iVar1 = Q_strlen(AlertMessage::szOut);
  iVar2 = Q_strlen(AlertMessage::szOut);
  vsnprintf(AlertMessage::szOut + iVar2,0x400 - iVar1,szFmt,&stack0x0000000c);
  Con_Printf("%s",AlertMessage::szOut);
  return;
}


// AllocEngineString  @ 00092450
int AllocEngineString(char *szValue)

{
  int size;
  char *pcVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: char * new_s@[???]
                       Unresolved local var: char * new_p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int l@[???] */
  iVar2 = Q_strlen(szValue);
  size = iVar2 + 1;
  pvVar3 = Hunk_Alloc(size);
  if (0 < size) {
    iVar6 = (int)pvVar3 + 1;
    iVar4 = 0;
    do {
      while ((pcVar1 = szValue + iVar4, *pcVar1 == '\\' && (iVar4 < iVar2))) {
        iVar5 = iVar4 + 1;
        iVar4 = iVar4 + 2;
        *(byte *)(iVar6 + -1) = ((szValue[iVar5] != 'n') - 1U & 0xae) + 0x5c;
        iVar6 = iVar6 + 1;
        if (size <= iVar4) goto LAB_000924b0;
      }
      iVar4 = iVar4 + 1;
      *(char *)(iVar6 + -1) = *pcVar1;
      iVar6 = iVar6 + 1;
    } while (iVar4 < size);
  }
LAB_000924b0:
  return (int)pvVar3 - (int)pr_strings;
}


// AngleIMatrix  @ 0007fed0
void AngleIMatrix(vec_t *angles,float (*matrix) [4])

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_24;
  float local_20 [4];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincosf(angles[1] * 0.017453292,local_20,&local_24);
  fVar3 = local_20[0];
  fVar1 = local_24;
  sincosf(*angles * 0.017453292,local_20,&local_24);
  fVar4 = local_20[0];
  fVar2 = local_24;
  sincosf(angles[2] * 0.017453292,local_20,&local_24);
  (*matrix)[0] = fVar2 * fVar1;
  (*matrix)[1] = fVar2 * fVar3;
  (*matrix)[3] = 0.0;
  (*matrix)[2] = -fVar4;
  matrix[1][3] = 0.0;
  matrix[2][3] = 0.0;
  matrix[1][0] = local_20[0] * fVar4 * fVar1 - fVar3 * local_24;
  matrix[1][1] = local_24 * fVar1 + local_20[0] * fVar4 * fVar3;
  matrix[1][2] = fVar2 * local_20[0];
  matrix[2][0] = local_20[0] * fVar3 + fVar4 * local_24 * fVar1;
  matrix[2][1] = fVar4 * local_24 * fVar3 - fVar1 * local_20[0];
  matrix[2][2] = local_24 * fVar2;
  return;
}


// AngleMatrix  @ 0007fdb0
void AngleMatrix(vec_t *angles,float (*matrix) [4])

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_24;
  float local_20 [4];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincosf(angles[1] * 0.017453292,local_20,&local_24);
  fVar3 = local_20[0];
  fVar1 = local_24;
  sincosf(*angles * 0.017453292,local_20,&local_24);
  fVar4 = local_20[0];
  fVar2 = local_24;
  sincosf(angles[2] * 0.017453292,local_20,&local_24);
  (*matrix)[0] = fVar2 * fVar1;
  matrix[1][0] = fVar2 * fVar3;
  (*matrix)[3] = 0.0;
  matrix[2][0] = -fVar4;
  matrix[1][3] = 0.0;
  matrix[2][3] = 0.0;
  (*matrix)[1] = local_20[0] * fVar4 * fVar1 - fVar3 * local_24;
  matrix[1][1] = local_24 * fVar1 + local_20[0] * fVar4 * fVar3;
  matrix[2][1] = fVar2 * local_20[0];
  (*matrix)[2] = local_20[0] * fVar3 + fVar4 * local_24 * fVar1;
  matrix[1][2] = fVar4 * local_24 * fVar3 - fVar1 * local_20[0];
  matrix[2][2] = local_24 * fVar2;
  return;
}


// AngleQuaternion  @ 00092960
void AngleQuaternion(vec_t *angles,vec_t *quaternion)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_24;
  float local_20 [4];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincosf(angles[2] * 0.5,local_20,&local_24);
  fVar5 = local_20[0];
  fVar3 = local_24;
  sincosf(angles[1] * 0.5,local_20,&local_24);
  fVar6 = local_20[0];
  fVar4 = local_24;
  sincosf(*angles * 0.5,local_20,&local_24);
  fVar2 = fVar4 * local_20[0];
  fVar1 = fVar6 * local_24;
  *quaternion = fVar2 * fVar3 - fVar1 * fVar5;
  quaternion[1] = fVar2 * fVar5 + fVar1 * fVar3;
  local_24 = local_24 * fVar4;
  local_20[0] = local_20[0] * fVar6;
  quaternion[2] = local_24 * fVar5 - local_20[0] * fVar3;
  quaternion[3] = fVar3 * local_24 + local_20[0] * fVar5;
  return;
}


// AngleVectors  @ 0007fac0
void AngleVectors(vec_t *angles,vec_t *forward,vec_t *right,vec_t *up)

{
  float fVar1;
  vec_t *pvVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  (*g_engdstAddrs.pfnAngleVectors)(&angles,&forward,&right,&up);
  pvVar2 = angles;
  sincosf(angles[1] * 0.017453292,&local_10,&local_14);
  fVar5 = local_10;
  fVar3 = local_14;
  sincosf(*pvVar2 * 0.017453292,&local_10,&local_14);
  fVar6 = local_10;
  fVar4 = local_14;
  sincosf(pvVar2[2] * 0.017453292,&local_10,&local_14);
  if (forward != (vec_t *)0x0) {
    *forward = fVar4 * fVar3;
    forward[1] = fVar4 * fVar5;
    forward[2] = -fVar6;
  }
  if (right != (vec_t *)0x0) {
    fVar1 = -local_10 * fVar6;
    *right = local_14 * fVar5 + fVar3 * fVar1;
    right[1] = fVar1 * fVar5 - fVar3 * local_14;
    right[2] = -local_10 * fVar4;
  }
  if (up != (vec_t *)0x0) {
    *up = local_10 * fVar5 + fVar3 * fVar6 * local_14;
    up[1] = fVar6 * local_14 * fVar5 - local_10 * fVar3;
    up[2] = local_14 * fVar4;
  }
  return;
}


// AngleVectorsTranspose  @ 0007fc20
void AngleVectorsTranspose(vec_t *angles,vec_t *forward,vec_t *right,vec_t *up)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_24;
  float local_20 [4];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincosf(angles[1] * 0.017453292,local_20,&local_24);
  fVar3 = local_20[0];
  fVar1 = local_24;
  sincosf(*angles * 0.017453292,local_20,&local_24);
  fVar4 = local_20[0];
  fVar2 = local_24;
  sincosf(angles[2] * 0.017453292,local_20,&local_24);
  if (forward != (vec_t *)0x0) {
    *forward = fVar2 * fVar1;
    forward[1] = local_20[0] * fVar4 * fVar1 - fVar3 * local_24;
    forward[2] = local_20[0] * fVar3 + local_24 * fVar4 * fVar1;
  }
  if (right != (vec_t *)0x0) {
    *right = fVar2 * fVar3;
    right[1] = local_24 * fVar1 + local_20[0] * fVar4 * fVar3;
    right[2] = local_24 * fVar4 * fVar3 - fVar1 * local_20[0];
  }
  if (up != (vec_t *)0x0) {
    *up = -fVar4;
    up[1] = local_20[0] * fVar2;
    up[2] = fVar2 * local_24;
  }
  return;
}


// AnimationAutomove  @ 00094b40
void AnimationAutomove(edict_t *pEdict,float flTime)

{
  return;
}


// BEnableAddonsFolder  @ 0006df40
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


// BEnabledHDAddon  @ 0006df00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

bool BEnabledHDAddon(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = COM_CheckParm("-nohdmodels");
  bVar2 = false;
  if (iVar1 == 0) {
    iVar1 = (*registry->_vptr_IRegistry[2])(registry,"hdmodels",1);
    bVar2 = 0 < iVar1;
  }
  return bVar2;
}


// BIsValveGame  @ 000ae380
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean BIsValveGame(void)

{
  int iVar1;
  qboolean qVar2;
  
                    /* Unresolved local var: int i@[???] */
  qVar2 = true;
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
                      qVar2 = (qboolean)(iVar1 == 0);
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
  return qVar2;
}


// BaseSystemModule::BaseSystemModule  @ 000d3c30
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


// BaseSystemModule::BaseSystemModule  @ 000d3c70
/* DWARF original prototype: void BaseSystemModule(BaseSystemModule * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall
BaseSystemModule::BaseSystemModule(BaseSystemModule *this,int __in_chrg,void **__vtt_parm)

{
  *(undefined ***)this = &PTR__BaseSystemModule_000ee148;
  ObjectList::ObjectList(&this->m_Listener);
  this->m_State = 0;
  return;
}


// BaseSystemModule::ExecuteCommand  @ 000d3830
/* virtual thunk to BaseSystemModule::ExecuteCommand(int, char*) */

void __thiscall BaseSystemModule::ExecuteCommand(BaseSystemModule *this,int param_1,char *param_2)

{
  ExecuteCommand((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x1c) + -0x1c),param_1
                 ,param_2);
  return;
}


// BaseSystemModule::ExecuteCommand  @ 000d3840
/* DWARF original prototype: void ExecuteCommand(BaseSystemModule * this, int commandID, char *
   commandLine) */

void __thiscall
BaseSystemModule::ExecuteCommand(BaseSystemModule *this,int commandID,char *commandLine)

{
                    /* WARNING: Could not recover jumptable at 0x000d3859. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)*this->m_System + 0x50))();
  return;
}


// BaseSystemModule::FireSignal  @ 000d3cd0
/* DWARF original prototype: void FireSignal(BaseSystemModule * this, uint signal, void * data) */

void __thiscall BaseSystemModule::FireSignal(BaseSystemModule *this,uint signal,void *data)

{
  int *piVar1;
  
                    /* Unresolved local var: ISystemModule * listener@[???] */
  piVar1 = ObjectList::GetFirst(&this->m_Listener);
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))
              (piVar1,this->m_Name + *(int *)(*(int *)this + -0x48) + -0x1c,signal,data);
    piVar1 = ObjectList::GetNext(&this->m_Listener);
  }
  return;
}


// BaseSystemModule::GetName  @ 000d37d0
/* virtual thunk to BaseSystemModule::GetName() */

void __thiscall BaseSystemModule::GetName(BaseSystemModule *this)

{
  GetName((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x38) + -0x1c));
  return;
}


// BaseSystemModule::GetName  @ 000d37e0
/* DWARF original prototype: char * GetName(BaseSystemModule * this) */

char * __thiscall BaseSystemModule::GetName(BaseSystemModule *this)

{
  return this->m_Name;
}


// BaseSystemModule::GetSerial  @ 000d3860
/* virtual thunk to BaseSystemModule::GetSerial() */

void __thiscall BaseSystemModule::GetSerial(BaseSystemModule *this)

{
  GetSerial((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x2c) + -0x1c));
  return;
}


// BaseSystemModule::GetSerial  @ 000d3870
/* DWARF original prototype: int GetSerial(BaseSystemModule * this) */

int __thiscall BaseSystemModule::GetSerial(BaseSystemModule *this)

{
  return this->m_Serial;
}


// BaseSystemModule::GetState  @ 000d3940
/* virtual thunk to BaseSystemModule::GetState() */

void __thiscall BaseSystemModule::GetState(BaseSystemModule *this)

{
  GetState((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x3c) + -0x1c));
  return;
}


// BaseSystemModule::GetState  @ 000d3950
/* DWARF original prototype: int GetState(BaseSystemModule * this) */

int __thiscall BaseSystemModule::GetState(BaseSystemModule *this)

{
  return this->m_State;
}


// BaseSystemModule::GetStatusLine  @ 000d3810
/* virtual thunk to BaseSystemModule::GetStatusLine() */

void __thiscall BaseSystemModule::GetStatusLine(BaseSystemModule *this)

{
  GetStatusLine((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x30) + -0x1c));
  return;
}


// BaseSystemModule::GetStatusLine  @ 000d3820
/* DWARF original prototype: char * GetStatusLine(BaseSystemModule * this) */

char * __thiscall BaseSystemModule::GetStatusLine(BaseSystemModule *this)

{
  return "No status available.\n";
}


// BaseSystemModule::GetSystem  @ 000d3880
/* virtual thunk to BaseSystemModule::GetSystem() */

void __thiscall BaseSystemModule::GetSystem(BaseSystemModule *this)

{
  GetSystem((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x28) + -0x1c));
  return;
}


// BaseSystemModule::GetSystem  @ 000d3890
/* DWARF original prototype: IBaseSystem * GetSystem(BaseSystemModule * this) */

IBaseSystem * __thiscall BaseSystemModule::GetSystem(BaseSystemModule *this)

{
  return this->m_System;
}


// BaseSystemModule::GetType  @ 000d37f0
/* virtual thunk to BaseSystemModule::GetType() */

void __thiscall BaseSystemModule::GetType(BaseSystemModule *this)

{
  GetType((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x34) + -0x1c));
  return;
}


// BaseSystemModule::GetType  @ 000d3800
/* DWARF original prototype: char * GetType(BaseSystemModule * this) */

char * __thiscall BaseSystemModule::GetType(BaseSystemModule *this)

{
  return "GenericModule";
}


// BaseSystemModule::GetVersion  @ 000d3a70
/* virtual thunk to BaseSystemModule::GetVersion() */

void __thiscall BaseSystemModule::GetVersion(BaseSystemModule *this)

{
  GetVersion((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x40) + -0x1c));
  return;
}


// BaseSystemModule::GetVersion  @ 000d3a80
/* DWARF original prototype: int GetVersion(BaseSystemModule * this) */

int __thiscall BaseSystemModule::GetVersion(BaseSystemModule *this)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  
  if (build_number::b != 0) {
    return build_number::b;
  }
  iVar2 = Q_strncasecmp(date,mon[0],3);
  if (iVar2 == 0) {
    iVar2 = 0;
    uVar5 = 0;
  }
  else {
    iVar2 = (int)mond[0];
    iVar3 = Q_strncasecmp(date,mon[1],3);
    if (iVar3 == 0) {
      uVar5 = 1;
    }
    else {
      iVar2 = iVar2 + mond[1];
      iVar3 = Q_strncasecmp(date,mon[2],3);
      if (iVar3 == 0) {
        uVar5 = 2;
      }
      else {
        iVar2 = iVar2 + mond[2];
        iVar3 = Q_strncasecmp(date,mon[3],3);
        if (iVar3 == 0) {
          uVar5 = 3;
        }
        else {
          iVar2 = iVar2 + mond[3];
          iVar3 = Q_strncasecmp(date,mon[4],3);
          if (iVar3 == 0) {
            uVar5 = 4;
          }
          else {
            iVar2 = iVar2 + mond[4];
            iVar3 = Q_strncasecmp(date,mon[5],3);
            if (iVar3 == 0) {
              uVar5 = 5;
            }
            else {
              iVar2 = iVar2 + mond[5];
              iVar3 = Q_strncasecmp(date,mon[6],3);
              if (iVar3 == 0) {
                uVar5 = 6;
              }
              else {
                iVar2 = iVar2 + mond[6];
                iVar3 = Q_strncasecmp(date,mon[7],3);
                if (iVar3 == 0) {
                  uVar5 = 7;
                }
                else {
                  iVar2 = iVar2 + mond[7];
                  iVar3 = Q_strncasecmp(date,mon[8],3);
                  if (iVar3 == 0) {
                    uVar5 = 8;
                  }
                  else {
                    iVar2 = iVar2 + mond[8];
                    iVar3 = Q_strncasecmp(date,mon[9],3);
                    if (iVar3 == 0) {
                      uVar5 = 9;
                    }
                    else {
                      iVar2 = iVar2 + mond[9];
                      iVar3 = Q_strncasecmp(date,mon[10],3);
                      if (iVar3 != 0) {
                        bVar1 = true;
                        iVar2 = iVar2 + mond[10];
                        goto LAB_0005ade2;
                      }
                      uVar5 = 10;
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
  bVar1 = 1 < uVar5;
LAB_0005ade2:
  lVar4 = strtol(date + 4,(char **)0x0,10);
  uVar5 = strtol(date + 7,(char **)0x0,10);
  iVar2 = iVar2 + -1 + lVar4 + (int)((float)(int)(uVar5 - 0x76d) * 365.25);
  if ((uVar5 & 3) == 0) {
    iVar2 = (iVar2 + 1) - (uint)!bVar1;
  }
  build_number::b = iVar2 + -0x88b3;
  return iVar2 + -0x88b3;
}


// BaseSystemModule::Init  @ 000d39e0
/* virtual thunk to BaseSystemModule::Init(IBaseSystem*, int, char*) */

void __thiscall
BaseSystemModule::Init(BaseSystemModule *this,IBaseSystem *param_1,int param_2,char *param_3)

{
  Init((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x10) + -0x1c),param_1,param_2,
       param_3);
  return;
}


// BaseSystemModule::Init  @ 000d39f0
/* DWARF original prototype: bool Init(BaseSystemModule * this, IBaseSystem * system, int serial,
   char * name) */

bool __thiscall
BaseSystemModule::Init(BaseSystemModule *this,IBaseSystem *system,int serial,char *name)

{
  bool bVar1;
  
  bVar1 = false;
  if (system != (IBaseSystem *)0x0) {
    this->m_State = 1;
    this->m_System = system;
    this->m_Serial = serial;
    *(undefined4 *)&this->m_SystemTime = 0;
    *(undefined4 *)((int)&this->m_SystemTime + 4) = 0;
    if (name != (char *)0x0) {
      strncpy(this->m_Name,name,0xfe);
      this->m_Name[0xfe] = '\0';
    }
    ObjectList::Init(&this->m_Listener);
    bVar1 = true;
  }
  return bVar1;
}


// BaseSystemModule::ReceiveSignal  @ 000d38d0
/* virtual thunk to BaseSystemModule::ReceiveSignal(ISystemModule*, unsigned int, void*) */

void __thiscall
BaseSystemModule::ReceiveSignal
          (BaseSystemModule *this,ISystemModule *param_1,uint param_2,void *param_3)

{
  ReceiveSignal((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x18) + -0x1c),param_1,
                param_2,param_3);
  return;
}


// BaseSystemModule::ReceiveSignal  @ 000d38e0
/* DWARF original prototype: void ReceiveSignal(BaseSystemModule * this, ISystemModule * module,
   uint signal, void * data) */

void __thiscall
BaseSystemModule::ReceiveSignal(BaseSystemModule *this,ISystemModule *module,uint signal,void *data)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)((int)*this->m_System + 0x50);
  (*(module->super_IBaseInterface)._vptr_IBaseInterface[0xc])(module);
                    /* WARNING: Could not recover jumptable at 0x000d3934. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// BaseSystemModule::RegisterListener  @ 000d3ad0
/* virtual thunk to BaseSystemModule::RegisterListener(ISystemModule*) */

void __thiscall BaseSystemModule::RegisterListener(BaseSystemModule *this,ISystemModule *param_1)

{
  RegisterListener((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x20) + -0x1c),
                   param_1);
  return;
}


// BaseSystemModule::RegisterListener  @ 000d3ae0
/* DWARF original prototype: void RegisterListener(BaseSystemModule * this, ISystemModule * module)
    */

void __thiscall BaseSystemModule::RegisterListener(BaseSystemModule *this,ISystemModule *module)

{
  ObjectList *this_00;
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: ISystemModule * listener@[???] */
  this_00 = &this->m_Listener;
  piVar2 = ObjectList::GetFirst(this_00);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      ObjectList::Add(this_00,module);
      return;
    }
    iVar3 = (**(code **)(*piVar2 + 0x24))(piVar2);
    iVar4 = (*(module->super_IBaseInterface)._vptr_IBaseInterface[9])(module);
    if (iVar3 == iVar4) break;
    piVar2 = ObjectList::GetNext(this_00);
  }
                    /* Unresolved local var: ISystemModule * listener@[???] */
  pcVar1 = *(code **)((int)*this->m_System + 0x50);
  iVar3 = (*(module->super_IBaseInterface)._vptr_IBaseInterface[0xc])(module);
  (*pcVar1)(this->m_System,"WARNING! BaseSystemModule::RegisterListener: module %s already added.\n"
            ,iVar3);
  return;
}


// BaseSystemModule::RemoveListener  @ 000d3960
/* virtual thunk to BaseSystemModule::RemoveListener(ISystemModule*) */

void __thiscall BaseSystemModule::RemoveListener(BaseSystemModule *this,ISystemModule *param_1)

{
  RemoveListener((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x24) + -0x1c),param_1
                );
  return;
}


// BaseSystemModule::RemoveListener  @ 000d3970
/* DWARF original prototype: void RemoveListener(BaseSystemModule * this, ISystemModule * module) */

void __thiscall BaseSystemModule::RemoveListener(BaseSystemModule *this,ISystemModule *module)

{
  int *object;
  int iVar1;
  int iVar2;
  ObjectList *this_00;
  
                    /* Unresolved local var: ISystemModule * listener@[???] */
  this_00 = &this->m_Listener;
  object = ObjectList::GetFirst(this_00);
  while( true ) {
    if (object == (int *)0x0) {
      return;
    }
    iVar1 = (**(code **)(*object + 0x24))(object);
    iVar2 = (*(module->super_IBaseInterface)._vptr_IBaseInterface[9])(module);
    if (iVar1 == iVar2) break;
    object = ObjectList::GetNext(this_00);
  }
  ObjectList::Remove(this_00,object);
  return;
}


// BaseSystemModule::RunFrame  @ 000d38a0
/* virtual thunk to BaseSystemModule::RunFrame(double) */

void __thiscall BaseSystemModule::RunFrame(BaseSystemModule *this,double param_1)

{
  RunFrame((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x14) + -0x1c),param_1);
  return;
}


// BaseSystemModule::RunFrame  @ 000d38b0
/* DWARF original prototype: void RunFrame(BaseSystemModule * this, double time) */

void __thiscall BaseSystemModule::RunFrame(BaseSystemModule *this,double time)

{
  this->m_SystemTime = time;
  return;
}


// BaseSystemModule::ShutDown  @ 000d3b70
/* virtual thunk to BaseSystemModule::ShutDown() */

void __thiscall BaseSystemModule::ShutDown(BaseSystemModule *this)

{
  ShutDown((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0x44) + -0x1c));
  return;
}


// BaseSystemModule::ShutDown  @ 000d3b80
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


// BaseSystemModule::~BaseSystemModule  @ 000d3a90
/* virtual thunk to BaseSystemModule::~BaseSystemModule() */

void __thiscall BaseSystemModule::~BaseSystemModule(BaseSystemModule *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~BaseSystemModule((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0xc) + -0x1c),
                    in_stack_00000008,in_stack_0000000c);
  return;
}


// BaseSystemModule::~BaseSystemModule  @ 000d3aa0
/* DWARF original prototype: void ~BaseSystemModule(BaseSystemModule * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall
BaseSystemModule::~BaseSystemModule(BaseSystemModule *this,int __in_chrg,void **__vtt_parm)

{
  int in_stack_ffffffe8;
  
  *(undefined ***)this = &PTR__BaseSystemModule_000ee148;
  ObjectList::~ObjectList(&this->m_Listener,in_stack_ffffffe8);
  *(undefined ***)this = &PTR__IBaseInterface_000e7cf0;
  return;
}


// BaseSystemModule::~BaseSystemModule  @ 000d3bf0
/* virtual thunk to BaseSystemModule::~BaseSystemModule() */

void __thiscall BaseSystemModule::~BaseSystemModule(BaseSystemModule *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~BaseSystemModule((BaseSystemModule *)(this->m_Name + *(int *)(*(int *)this + -0xc) + -0x1c),
                    in_stack_00000008,in_stack_0000000c);
  return;
}


// BaseSystemModule::~BaseSystemModule  @ 000d3c00
/* DWARF original prototype: void ~BaseSystemModule(BaseSystemModule * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall
BaseSystemModule::~BaseSystemModule(BaseSystemModule *this,int __in_chrg,void **__vtt_parm)

{
  int in_stack_ffffffe8;
  
  *(undefined ***)this = &PTR__BaseSystemModule_000ee148;
  ObjectList::~ObjectList(&this->m_Listener,in_stack_ffffffe8);
  *(undefined ***)this = &PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// BaseSystemModule::~BaseSystemModule  @ 000d3ca0
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


// BoxOnPlaneSide  @ 0007f100
int BoxOnPlaneSide(vec_t *emins,vec_t *emaxs,mplane_t *p)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  
                    /* Unresolved local var: float dist1@[???]
                       Unresolved local var: float dist2@[???]
                       Unresolved local var: int sides@[???] */
  if (p->signbits < 8) {
    fVar1 = p->normal[0];
    fVar2 = p->normal[1];
    fVar3 = p->normal[2];
    switch(p->signbits) {
    case '\0':
      fVar4 = emaxs[2] * fVar3 + emaxs[1] * fVar2 + fVar1 * *emaxs;
      fVar1 = fVar3 * emins[2] + fVar2 * emins[1] + fVar1 * *emins;
      break;
    case '\x01':
      fVar4 = emaxs[2] * fVar3 + emaxs[1] * fVar2 + fVar1 * *emins;
      fVar1 = fVar3 * emins[2] + fVar2 * emins[1] + fVar1 * *emaxs;
      break;
    case '\x02':
      fVar4 = emaxs[2] * fVar3 + emins[1] * fVar2 + fVar1 * *emaxs;
      fVar1 = fVar3 * emins[2] + fVar2 * emaxs[1] + fVar1 * *emins;
      break;
    case '\x03':
      fVar4 = emaxs[2] * fVar3 + emins[1] * fVar2 + fVar1 * *emins;
      fVar1 = fVar3 * emins[2] + fVar2 * emaxs[1] + fVar1 * *emaxs;
      break;
    case '\x04':
      fVar4 = emins[2] * fVar3 + emaxs[1] * fVar2 + fVar1 * *emaxs;
      fVar1 = fVar3 * emaxs[2] + fVar2 * emins[1] + fVar1 * *emins;
      break;
    case '\x05':
      fVar4 = emins[2] * fVar3 + emaxs[1] * fVar2 + fVar1 * *emins;
      fVar1 = fVar3 * emaxs[2] + fVar2 * emins[1] + fVar1 * *emaxs;
      break;
    case '\x06':
      fVar4 = emins[2] * fVar3 + emins[1] * fVar2 + fVar1 * *emaxs;
      fVar1 = fVar3 * emaxs[2] + fVar2 * emaxs[1] + fVar1 * *emins;
      break;
    case '\a':
      fVar4 = emins[2] * fVar3 + emins[1] * fVar2 + fVar1 * *emins;
      fVar1 = fVar3 * emaxs[2] + fVar2 * emaxs[1] + fVar1 * *emaxs;
    }
  }
  else {
    Sys_Error("BoxOnPlaneSide:  Bad signbits");
    fVar1 = 0.0;
    fVar4 = fVar1;
  }
  uVar5 = (uint)(p->dist <= fVar4);
  if (fVar1 < p->dist) {
    uVar5 = uVar5 | 2;
  }
  return uVar5;
}


// BuildMapCycleListHints  @ 00098770
int BuildMapCycleListHints(char **hints)

{
  FileHandle_t file;
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  char *pcVar6;
  size_t sVar7;
  uint *puVar8;
  uint *puVar9;
  uint local_430 [65];
  undefined1 local_32b;
  char local_32a [262];
  char local_224 [260];
  char local_120 [272];
  
                    /* Unresolved local var: char[262] szMap@[???]
                       Unresolved local var: uint length@[???]
                       Unresolved local var: char * pFileList@[???]
                       Unresolved local var: char[260] szMod@[???]
                       Unresolved local var: char[260] cszMapCycleTxtFile@[???]
                       Unresolved local var: FileHandle_t pFile@[???] */
  COM_FileBase(com_gamedir,local_224);
  snprintf(local_120,0x104,"%s/%s",local_224,mapcyclefile.string);
  file = FS_Open(local_120,"rb");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("Unable to open %s\n",local_120);
    return 0;
  }
  pcVar1 = GetCurrentSteamAppName();
  snprintf((char *)local_430,0x106,"%s\\%s\\%s%s\r\n",szReslistsBaseDir,pcVar1,szCommonPreloads,
           szReslistsExt);
  puVar9 = local_430;
  do {
    puVar8 = puVar9;
    uVar2 = *puVar8 + 0xfefefeff & ~*puVar8;
    uVar3 = uVar2 & 0x80808080;
    puVar9 = puVar8 + 1;
  } while (uVar3 == 0);
  if ((uVar2 & 0x8080) == 0) {
    puVar9 = (uint *)((int)puVar8 + 6);
    uVar3 = uVar3 >> 0x10;
  }
  pcVar1 = malloc((size_t)((int)puVar9 +
                          (-(int)local_430 - (uint)CARRY1((byte)uVar3,(byte)uVar3)) + -2));
  *hints = pcVar1;
  if (pcVar1 == (char *)0x0) {
    Con_Printf("Unable to allocate memory for map cycle hints list");
    iVar4 = 0;
  }
  else {
    strcpy(pcVar1,(char *)local_430);
    uVar3 = FS_Size(file);
    if ((uVar3 != 0) && (pcVar1 = malloc(uVar3), pcVar1 != (char *)0x0)) {
      iVar4 = FS_Read(pcVar1,uVar3,1,file);
      if (iVar4 == 1) {
                    /* Unresolved local var: char[262] mapLine@[???] */
        while (pcVar1 = COM_Parse(pcVar1), com_token[0] != '\0') {
          strncpy((char *)local_430,com_token,0x105);
          local_32b = 0;
          iVar4 = COM_TokenWaiting(pcVar1);
          if (iVar4 != 0) {
            pcVar1 = COM_Parse(pcVar1);
          }
          pcVar6 = GetCurrentSteamAppName();
          snprintf(local_32a,0x106,"%s\\%s\\%s%s\r\n",szReslistsBaseDir,pcVar6,local_430,
                   szReslistsExt);
          pcVar6 = *hints;
          sVar5 = strlen(pcVar6);
          sVar7 = strlen(local_32a);
          pcVar6 = realloc(pcVar6,sVar5 + 2 + sVar7);
          *hints = pcVar6;
          if (pcVar6 == (char *)0x0) {
            Con_Printf("Unable to reallocate memory for map cycle hints list");
            return 0;
          }
          strcat(pcVar6,local_32a);
        }
      }
      free(pcVar1);
    }
    FS_Close(file);
    pcVar1 = GetCurrentSteamAppName();
    snprintf((char *)local_430,0x106,"%s\\%s\\mp_maps.txt\r\n",szReslistsBaseDir,pcVar1);
    pcVar1 = *hints;
    sVar5 = strlen(pcVar1);
    puVar9 = local_430;
    do {
      puVar8 = puVar9;
      uVar2 = *puVar8 + 0xfefefeff & ~*puVar8;
      uVar3 = uVar2 & 0x80808080;
      puVar9 = puVar8 + 1;
    } while (uVar3 == 0);
    if ((uVar2 & 0x8080) == 0) {
      puVar9 = (uint *)((int)puVar8 + 6);
      uVar3 = uVar3 >> 0x10;
    }
    pcVar1 = realloc(pcVar1,(size_t)((int)puVar9 +
                                    sVar5 + (-(int)local_430 - (uint)CARRY1((byte)uVar3,(byte)uVar3)
                                            ) + -1));
    *hints = pcVar1;
    strcat(pcVar1,(char *)local_430);
    iVar4 = 1;
  }
  return iVar4;
}


// CDedicatedServerAPI::AddConsoleText  @ 00097ad0
/* DWARF original prototype: void AddConsoleText(CDedicatedServerAPI * this, char * text) */

void __thiscall CDedicatedServerAPI::AddConsoleText(CDedicatedServerAPI *this,char *text)

{
  Cbuf_AddText(text);
  return;
}


// CDedicatedServerAPI::Init  @ 00098050
/* DWARF original prototype: bool Init(CDedicatedServerAPI * this, char * basedir, char * cmdline,
   CreateInterfaceFn launcherFactory, CreateInterfaceFn filesystemFactory) */

bool __thiscall
CDedicatedServerAPI::Init
          (CDedicatedServerAPI *this,char *basedir,char *cmdline,CreateInterfaceFn launcherFactory,
          CreateInterfaceFn filesystemFactory)

{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  char local_10c [255];
  undefined1 local_d;
  
  bVar3 = false;
  dedicated = (IDedicatedExports *)
              (*launcherFactory)("VENGINE_DEDICATEDEXPORTS_API_VERSION001",(int *)0x0);
  if (dedicated != (IDedicatedExports *)0x0) {
    strcpy(this->m_OrigCmd,cmdline);
    pcVar1 = strstr(cmdline,"-nobreakpad");
    if (pcVar1 == (char *)0x0) {
      iVar2 = build_number();
      pcVar1 = va("%d",iVar2);
      SteamAPI_UseBreakpadCrashHandler(pcVar1,"Aug 19 2020","13:23:27",0,0,0);
    }
    TraceInit("Sys_InitArgv( m_OrigCmd )","Sys_ShutdownArgv()",0);
    Sys_InitArgv(this->m_OrigCmd);
    (*eng->_vptr_IEngine[0x11])(eng,0);
    (**registry->_vptr_IRegistry)(registry);
    g_bIsDedicatedServer = true;
    bVar3 = false;
    TraceInit("FileSystem_Init(basedir, (void *)filesystemFactory)","FileSystem_Shutdown()",0);
    iVar2 = FileSystem_Init(basedir,filesystemFactory);
    if (iVar2 != 0) {
      iVar2 = (*game->_vptr_IGame[2])(game,0);
      if ((char)iVar2 != '\0') {
        iVar2 = (*eng->_vptr_IEngine[2])(eng,1,basedir,cmdline);
        if ((char)iVar2 != '\0') {
                    /* Unresolved local var: char[256] szCommand@[???] */
          snprintf(local_10c,0xff,"exec %s\n",servercfgfile.string);
          bVar3 = true;
          local_d = 0;
          Cbuf_InsertText(local_10c);
        }
      }
    }
  }
  return bVar3;
}


// CDedicatedServerAPI::RunFrame  @ 00097ba0
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


// CDedicatedServerAPI::Shutdown  @ 00097ae0
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


// CDedicatedServerAPI::UpdateStatus  @ 00097ab0
/* DWARF original prototype: void UpdateStatus(CDedicatedServerAPI * this, float * fps, int *
   nActive, int * nMaxPlayers, char * pszMap) */

void __thiscall
CDedicatedServerAPI::UpdateStatus
          (CDedicatedServerAPI *this,float *fps,int *nActive,int *nMaxPlayers,char *pszMap)

{
  Host_GetHostInfo(fps,nActive,(int *)0x0,nMaxPlayers,pszMap);
  return;
}


// CDedicatedServerAPI::~CDedicatedServerAPI  @ 00098af0
/* DWARF original prototype: void ~CDedicatedServerAPI(CDedicatedServerAPI * this, int __in_chrg) */

void __thiscall CDedicatedServerAPI::~CDedicatedServerAPI(CDedicatedServerAPI *this,int __in_chrg)

{
  (this->super_IDedicatedServerAPI).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  return;
}


// CDedicatedServerAPI::~CDedicatedServerAPI  @ 00098b20
/* DWARF original prototype: void ~CDedicatedServerAPI(CDedicatedServerAPI * this, int __in_chrg) */

void __thiscall CDedicatedServerAPI::~CDedicatedServerAPI(CDedicatedServerAPI *this,int __in_chrg)

{
  (this->super_IDedicatedServerAPI).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// CEngine::CEngine  @ 0009aa00
/* DWARF original prototype: void CEngine(CEngine * this) */

void __thiscall CEngine::CEngine(CEngine *this)

{
  this->m_fFrameTime = 0.0;
  (this->super_IEngine)._vptr_IEngine = (_func_int_varargs **)&PTR__CEngine_000e8988;
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


// CEngine::CheckDoneTrapping  @ 0009a9d0
/* DWARF original prototype: bool CheckDoneTrapping(CEngine * this, int * buttons, int * key) */

bool __thiscall CEngine::CheckDoneTrapping(CEngine *this,int *buttons,int *key)

{
  bool bVar1;
  
  bVar1 = false;
  if ((this->m_bTrapMode == false) && (this->m_bDoneTrapping != false)) {
    *key = this->m_nTrapKey;
    *buttons = this->m_nTrapButtons;
    bVar1 = true;
    this->m_bDoneTrapping = false;
  }
  return bVar1;
}


// CEngine::Frame  @ 0009a820
/* DWARF original prototype: int Frame(CEngine * this) */

int __thiscall CEngine::Frame(CEngine *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  longdouble lVar4;
  double dVar5;
  int local_10 [2];
  
  iVar1 = (*game->_vptr_IGame[0xb])(game);
  if ((char)iVar1 == '\0') {
    uVar2 = 0x32;
    if (this->m_nDLLState != 2) {
      uVar2 = 0x14;
    }
    (*game->_vptr_IGame[5])(game,uVar2);
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
  iVar1 = 0;
  if (this->m_nDLLState != 0) {
                    /* Unresolved local var: int dummy@[???]
                       Unresolved local var: int iState@[???] */
    iVar3 = Host_Frame((float)lVar4,this->m_nDLLState,local_10);
    iVar1 = this->m_nDLLState;
    if (iVar1 != iVar3) {
      (*(this->super_IEngine)._vptr_IEngine[4])(this,iVar3);
      iVar1 = this->m_nDLLState;
      if (iVar1 == 3) {
        (*(this->super_IEngine)._vptr_IEngine[0x11])(this,1);
        iVar1 = this->m_nDLLState;
      }
      else if (iVar1 == 5) {
        (*(this->super_IEngine)._vptr_IEngine[0x11])(this,2);
        iVar1 = this->m_nDLLState;
      }
    }
  }
  return iVar1;
}


// CEngine::GetCurTime  @ 0009a770
/* DWARF original prototype: double GetCurTime(CEngine * this) */

double __thiscall CEngine::GetCurTime(CEngine *this)

{
  return this->m_fCurTime;
}


// CEngine::GetFrameTime  @ 0009a760
/* DWARF original prototype: double GetFrameTime(CEngine * this) */

double __thiscall CEngine::GetFrameTime(CEngine *this)

{
  return this->m_fFrameTime;
}


// CEngine::GetQuitting  @ 0009a7d0
/* DWARF original prototype: int GetQuitting(CEngine * this) */

int __thiscall CEngine::GetQuitting(CEngine *this)

{
  return this->m_nQuitting;
}


// CEngine::GetState  @ 0009a740
/* DWARF original prototype: int GetState(CEngine * this) */

int __thiscall CEngine::GetState(CEngine *this)

{
  return this->m_nDLLState;
}


// CEngine::GetSubState  @ 0009a750
/* DWARF original prototype: int GetSubState(CEngine * this) */

int __thiscall CEngine::GetSubState(CEngine *this)

{
  return this->m_nSubState;
}


// CEngine::IsTrapping  @ 0009a7b0
/* DWARF original prototype: bool IsTrapping(CEngine * this) */

bool __thiscall CEngine::IsTrapping(CEngine *this)

{
  return this->m_bTrapMode;
}


// CEngine::Load  @ 0009a910
/* DWARF original prototype: bool Load(CEngine * this, bool dedicated, char * basedir, char *
   cmdline) */

bool __thiscall CEngine::Load(CEngine *this,bool dedicated,char *basedir,char *cmdline)

{
  void *pwnd;
  int iVar1;
  
                    /* Unresolved local var: bool success@[???] */
  (*(this->super_IEngine)._vptr_IEngine[4])(this,1);
  pwnd = (void *)(*game->_vptr_IGame[7])(game);
  iVar1 = Sys_InitGame(cmdline,basedir,pwnd,(uint)dedicated);
  return iVar1 != 0;
}


// CEngine::SetQuitting  @ 0009a7c0
/* DWARF original prototype: void SetQuitting(CEngine * this, int quittype) */

void __thiscall CEngine::SetQuitting(CEngine *this,int quittype)

{
  this->m_nQuitting = quittype;
  return;
}


// CEngine::SetState  @ 0009a7e0
/* DWARF original prototype: void SetState(CEngine * this, int iState) */

void __thiscall CEngine::SetState(CEngine *this,int iState)

{
  this->m_nDLLState = iState;
  GameSetState(iState);
  return;
}


// CEngine::SetSubState  @ 0009a800
/* DWARF original prototype: void SetSubState(CEngine * this, int iSubState) */

void __thiscall CEngine::SetSubState(CEngine *this,int iSubState)

{
  if (iSubState != 1) {
    GameSetSubState(iSubState);
    return;
  }
  return;
}


// CEngine::StartTrapMode  @ 0009a790
/* DWARF original prototype: void StartTrapMode(CEngine * this) */

void __thiscall CEngine::StartTrapMode(CEngine *this)

{
  if (this->m_bTrapMode == false) {
    this->m_bDoneTrapping = false;
    this->m_bTrapMode = true;
  }
  return;
}


// CEngine::Unload  @ 0009a970
/* DWARF original prototype: void Unload(CEngine * this) */

void __thiscall CEngine::Unload(CEngine *this)

{
  Sys_ShutdownGame();
  this->m_nDLLState = 0;
  return;
}


// CEngine::~CEngine  @ 0009a730
/* DWARF original prototype: void ~CEngine(CEngine * this, int __in_chrg) */

void __thiscall CEngine::~CEngine(CEngine *this,int __in_chrg)

{
  (this->super_IEngine)._vptr_IEngine = (_func_int_varargs **)&PTR__IEngine_000e89e8;
  return;
}


// CEngine::~CEngine  @ 0009a990
/* DWARF original prototype: void ~CEngine(CEngine * this, int __in_chrg) */

void __thiscall CEngine::~CEngine(CEngine *this,int __in_chrg)

{
  (this->super_IEngine)._vptr_IEngine = (_func_int_varargs **)&PTR__IEngine_000e89e8;
  operator_delete(this);
  return;
}


// CEngineAPI::Run  @ 00097a80
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


// CEngineAPI::~CEngineAPI  @ 00098b00
/* DWARF original prototype: void ~CEngineAPI(CEngineAPI * this, int __in_chrg) */

void __thiscall CEngineAPI::~CEngineAPI(CEngineAPI *this,int __in_chrg)

{
  (this->super_IEngineAPI).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  return;
}


// CEngineAPI::~CEngineAPI  @ 00098b10
/* DWARF original prototype: void ~CEngineAPI(CEngineAPI * this, int __in_chrg) */

void __thiscall CEngineAPI::~CEngineAPI(CEngineAPI *this,int __in_chrg)

{
  (this->super_IEngineAPI).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// CGame::CGame  @ 0009ab60
/* DWARF original prototype: void CGame(CGame * this) */

void __thiscall CGame::CGame(CGame *this)

{
  (this->super_IGame)._vptr_IGame = (_func_int_varargs **)&PTR__CGame_000e8a68;
  this->m_bActiveApp = true;
  return;
}


// CGame::CreateGameWindow  @ 0009aa60
/* DWARF original prototype: bool CreateGameWindow(CGame * this) */

bool __thiscall CGame::CreateGameWindow(CGame *this)

{
  return true;
}


// CGame::GetMainWindow  @ 0009aaa0
/* DWARF original prototype: void * GetMainWindow(CGame * this) */

void * __thiscall CGame::GetMainWindow(CGame *this)

{
  return (void *)0x0;
}


// CGame::GetMainWindowAddress  @ 0009aab0
/* DWARF original prototype: void * * GetMainWindowAddress(CGame * this) */

void ** __thiscall CGame::GetMainWindowAddress(CGame *this)

{
  return (void **)0x0;
}


// CGame::GetWindowRect  @ 0009aae0
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


// CGame::Init  @ 0009aa80
/* DWARF original prototype: bool Init(CGame * this, void * pvInstance) */

bool __thiscall CGame::Init(CGame *this,void *pvInstance)

{
  return true;
}


// CGame::IsActiveApp  @ 0009ab20
/* DWARF original prototype: bool IsActiveApp(CGame * this) */

bool __thiscall CGame::IsActiveApp(CGame *this)

{
  return this->m_bActiveApp;
}


// CGame::IsMultiplayer  @ 0009ab30
/* DWARF original prototype: bool IsMultiplayer(CGame * this) */

bool __thiscall CGame::IsMultiplayer(CGame *this)

{
  return true;
}


// CGame::PlayAVIAndWait  @ 0009aba0
/* DWARF original prototype: void PlayAVIAndWait(CGame * this, char * fileName) */

void __thiscall CGame::PlayAVIAndWait(CGame *this,char *fileName)

{
  return;
}


// CGame::PlayStartupVideos  @ 0009ab90
/* DWARF original prototype: void PlayStartupVideos(CGame * this) */

void __thiscall CGame::PlayStartupVideos(CGame *this)

{
  return;
}


// CGame::SetActiveApp  @ 0009ab70
/* DWARF original prototype: void SetActiveApp(CGame * this, bool active) */

void __thiscall CGame::SetActiveApp(CGame *this,bool active)

{
  this->m_bActiveApp = active;
  return;
}


// CGame::SetCursorVisible  @ 0009abb0
/* DWARF original prototype: void SetCursorVisible(CGame * this, bool bState) */

void __thiscall CGame::SetCursorVisible(CGame *this,bool bState)

{
  return;
}


// CGame::SetWindowSize  @ 0009aad0
/* DWARF original prototype: void SetWindowSize(CGame * this, int w, int h) */

void __thiscall CGame::SetWindowSize(CGame *this,int w,int h)

{
  return;
}


// CGame::SetWindowXY  @ 0009aac0
/* DWARF original prototype: void SetWindowXY(CGame * this, int x, int y) */

void __thiscall CGame::SetWindowXY(CGame *this,int x,int y)

{
  return;
}


// CGame::Shutdown  @ 0009aa90
/* DWARF original prototype: bool Shutdown(CGame * this) */

bool __thiscall CGame::Shutdown(CGame *this)

{
  return true;
}


// CGame::SleepUntilInput  @ 0009ab50
/* DWARF original prototype: void SleepUntilInput(CGame * this, int time) */

void __thiscall CGame::SleepUntilInput(CGame *this,int time)

{
  sleep(time);
  return;
}


// CGame::~CGame  @ 0009aa70
/* DWARF original prototype: void ~CGame(CGame * this, int __in_chrg) */

void __thiscall CGame::~CGame(CGame *this,int __in_chrg)

{
  (this->super_IGame)._vptr_IGame = (_func_int_varargs **)&PTR__IGame_000e8ac8;
  return;
}


// CGame::~CGame  @ 0009ab40
/* DWARF original prototype: void ~CGame(CGame * this, int __in_chrg) */

void __thiscall CGame::~CGame(CGame *this,int __in_chrg)

{
  (this->super_IGame)._vptr_IGame = (_func_int_varargs **)&PTR__IGame_000e8ac8;
  operator_delete(this);
  return;
}


// CIPRateLimit::CIPRateLimit  @ 000c9de0
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


// CIPRateLimit::CheckIP  @ 000c9e80
/* DWARF original prototype: bool CheckIP(CIPRateLimit * this, netadr_t.conflict adr) */

bool __thiscall CIPRateLimit::CheckIP(CIPRateLimit *this,netadr_t_conflict adr)

{
  int *piVar1;
  float fVar2;
  bool bVar3;
  time_t tVar4;
  Links_t *pLVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  Node_t *pNVar11;
  int local_50;
  iprate_s local_3c;
  iprate_s local_2c [2];
  
                    /* Unresolved local var: long curTime@[???]
                       Unresolved local var: ip_t clientIP@[???]
                       Unresolved local var: iprate_s findEntry@[???]
                       Unresolved local var: ip_t entry@[DW_OP_reg7(EDI)] */
  tVar4 = time((time_t *)0x0);
  if (0x200 < (uint)(this->m_IPTree).m_NumElements) {
                    /* Unresolved local var: ip_t tmp@[???]
                       Unresolved local var: int i@[???] */
    iVar7 = (this->m_IPTree).m_Root;
    while( true ) {
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar6 != 0)) {
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
      if (iVar7 != -1) {
        pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
      }
      if ((((Node_t *)pLVar5)->super_Links_t).m_Right == -1) break;
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar6 != 0)) {
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
      if (iVar7 != -1) {
        pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
      }
      iVar7 = (((Node_t *)pLVar5)->super_Links_t).m_Right;
    }
    local_50 = 0;
    while ((0x155 < (uint)(this->m_IPTree).m_NumElements &&
           (local_50 < (this->m_IPTree).m_TotalElements))) {
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar6 != 0)) {
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
      if (iVar7 != -1) {
        pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
      }
      if (((iVar7 == (((Node_t *)pLVar5)->super_Links_t).m_Left) ||
          (pNVar11 = (this->m_IPTree).m_Elements.m_pMemory,
          tVar4 - pNVar11[iVar7].m_Data.lastTime < 0x79)) ||
         (adr.ip == (uchar  [4])pNVar11[iVar7].m_Data.ip)) {
        local_50 = local_50 + 1;
                    /* Unresolved local var: int parent@[???] */
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar6 != 0)) {
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
        if (iVar7 != -1) {
          pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
        }
        if ((((Node_t *)pLVar5)->super_Links_t).m_Left == -1) {
                    /* Unresolved local var: int parent@[???] */
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar6 != 0)) {
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1
            ;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                 -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
          iVar6 = iVar7;
          if (iVar7 != -1) {
            pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
          }
          while( true ) {
            iVar7 = (((Node_t *)pLVar5)->super_Links_t).m_Parent;
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar8 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel), iVar8 != 0)) {
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                   -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
            if (iVar6 != -1) {
              pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar6].super_Links_t;
            }
            iVar8 = (((Node_t *)pLVar5)->super_Links_t).m_Parent;
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar9 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel), iVar9 != 0)) {
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                   -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
            if (iVar8 != -1) {
              pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar8].super_Links_t;
            }
            if ((iVar6 != (((Node_t *)pLVar5)->super_Links_t).m_Left) || (iVar7 == -1)) break;
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel), iVar6 != 0)) {
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                   -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
            iVar6 = iVar7;
          }
        }
        else {
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar6 != 0)) {
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                 -1;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1
            ;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
          if (iVar7 != -1) {
            pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
          }
          iVar7 = (((Node_t *)pLVar5)->super_Links_t).m_Left;
          while( true ) {
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel), iVar6 != 0)) {
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                   -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
            if (iVar7 != -1) {
              pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
            }
            if ((((Node_t *)pLVar5)->super_Links_t).m_Right == -1) break;
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel), iVar6 != 0)) {
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                   -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
            if (iVar7 != -1) {
              pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
            }
            iVar7 = (((Node_t *)pLVar5)->super_Links_t).m_Right;
          }
        }
      }
      else {
                    /* Unresolved local var: ip_t removeIPT@[???]
                       Unresolved local var: int parent@[???] */
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar6 != 0)) {
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
        if (iVar7 != -1) {
          pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
        }
        if ((((Node_t *)pLVar5)->super_Links_t).m_Left == -1) {
                    /* Unresolved local var: int parent@[???] */
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar6 != 0)) {
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1
            ;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                 -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
          if (iVar7 != -1) {
            pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
          }
          iVar8 = iVar7;
          iVar6 = (((Node_t *)pLVar5)->super_Links_t).m_Parent;
          while( true ) {
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar9 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel), iVar9 != 0)) {
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                   -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
            if (iVar8 != -1) {
              pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar8].super_Links_t;
            }
            iVar9 = (((Node_t *)pLVar5)->super_Links_t).m_Parent;
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar10 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                              s_Sentinel), iVar10 != 0)) {
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                   -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
            if (iVar9 != -1) {
              pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar9].super_Links_t;
            }
            if ((iVar8 != (((Node_t *)pLVar5)->super_Links_t).m_Left) || (iVar6 == -1)) break;
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar8 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel), iVar8 != 0)) {
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                   -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            iVar8 = iVar6;
            iVar6 = (this->m_IPTree).m_Elements.m_pMemory[iVar6].super_Links_t.m_Parent;
          }
        }
        else {
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar6 != 0)) {
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1
            ;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                 -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
          if (iVar7 != -1) {
            pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar7].super_Links_t;
          }
          iVar6 = (((Node_t *)pLVar5)->super_Links_t).m_Left;
          while( true ) {
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar8 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel), iVar8 != 0)) {
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                   -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
            if (iVar6 != -1) {
              pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar6].super_Links_t;
            }
            if ((((Node_t *)pLVar5)->super_Links_t).m_Right == -1) break;
            if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
               (iVar8 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                             s_Sentinel), iVar8 != 0)) {
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left =
                   -1;
              CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                   -1;
              __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
            }
            pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
            if (iVar6 != -1) {
              pLVar5 = &(this->m_IPTree).m_Elements.m_pMemory[iVar6].super_Links_t;
            }
            iVar6 = (((Node_t *)pLVar5)->super_Links_t).m_Right;
          }
        }
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::RemoveAt(&this->m_IPTree,iVar7);
        iVar7 = iVar6;
      }
    }
  }
                    /* Unresolved local var: int current@[???] */
  iVar7 = (this->m_IPTree).m_Root;
  local_3c.count = 0;
  local_3c.lastTime = 0;
  local_3c.ip._0_1_ = adr.ip[0];
  local_3c.ip._1_1_ = adr.ip[1];
  local_3c.ip._2_1_ = adr.ip[2];
  local_3c.ip._3_1_ = adr.ip[3];
  local_50 = -0x1c;
  if (iVar7 != -1) {
    pNVar11 = (this->m_IPTree).m_Elements.m_pMemory;
    do {
      while( true ) {
        local_50 = iVar7 * 0x1c;
        bVar3 = (*(this->m_IPTree).m_LessFunc)(&local_3c,&pNVar11[iVar7].m_Data);
        if (bVar3) break;
        bVar3 = (*(this->m_IPTree).m_LessFunc)
                          (&(this->m_IPTree).m_Elements.m_pMemory[iVar7].m_Data,&local_3c);
        if (!bVar3) goto LAB_000ca022;
        if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
           (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                         s_Sentinel), iVar6 != 0)) {
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1;
          CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent = -1;
          __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
        }
        pNVar11 = (this->m_IPTree).m_Elements.m_pMemory;
        iVar7 = pNVar11[iVar7].super_Links_t.m_Right;
        if (iVar7 == -1) goto LAB_000ca019;
      }
      if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
         (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                       s_Sentinel), iVar6 != 0)) {
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1;
        CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent = -1;
        __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
      }
      pNVar11 = (this->m_IPTree).m_Elements.m_pMemory;
      iVar7 = pNVar11[iVar7].super_Links_t.m_Left;
    } while (iVar7 != -1);
LAB_000ca019:
    local_50 = -0x1c;
  }
LAB_000ca022:
  if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
     (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel),
     iVar6 != 0)) {
    CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1;
    CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
    CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent = -1;
    __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
  }
  fVar2 = max_queries_window.value;
  pLVar5 = &CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel;
  if (iVar7 != -1) {
    pLVar5 = (Links_t *)
             ((int)&(((this->m_IPTree).m_Elements.m_pMemory)->super_Links_t).m_Left + local_50);
  }
  if (iVar7 == pLVar5->m_Left) {
                    /* Unresolved local var: iprate_s newEntry@[???] */
                    /* Unresolved local var: int newnode@[DW_OP_reg0(EAX)]
                       Unresolved local var: int parent@[???]
                       Unresolved local var: bool leftchild@[???]
                       Unresolved local var: int current@[???] */
    iVar7 = (this->m_IPTree).m_Root;
    bVar3 = false;
    local_2c[0].count = 1;
    local_2c[0].ip._0_1_ = adr.ip[0];
    local_2c[0].ip._1_1_ = adr.ip[1];
    local_2c[0].ip._2_1_ = adr.ip[2];
    local_2c[0].ip._3_1_ = adr.ip[3];
    local_2c[0].lastTime = tVar4;
    if (iVar7 != -1) {
      pNVar11 = (this->m_IPTree).m_Elements.m_pMemory;
      iVar6 = iVar7;
      do {
        iVar7 = iVar6;
        bVar3 = (*(this->m_IPTree).m_LessFunc)(local_2c,&pNVar11[iVar7].m_Data);
        if (bVar3) {
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar6 != 0)) {
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1
            ;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                 -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pNVar11 = (this->m_IPTree).m_Elements.m_pMemory;
          bVar3 = true;
          iVar6 = pNVar11[iVar7].super_Links_t.m_Left;
        }
        else {
          if ((CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel == '\0') &&
             (iVar6 = __cxa_guard_acquire(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::
                                           s_Sentinel), iVar6 != 0)) {
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Left = -1;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Right = -1
            ;
            CUtlRBTree<CIPRateLimit::iprate_s,_int>::Links::lexical_block_0::s_Sentinel.m_Parent =
                 -1;
            __cxa_guard_release(&CUtlRBTree<CIPRateLimit::iprate_s,int>::Links(int)::s_Sentinel);
          }
          pNVar11 = (this->m_IPTree).m_Elements.m_pMemory;
          bVar3 = false;
          iVar6 = pNVar11[iVar7].super_Links_t.m_Right;
        }
      } while (iVar6 != -1);
    }
    iVar7 = CUtlRBTree<CIPRateLimit::iprate_s,_int>::InsertAt(&this->m_IPTree,iVar7,bVar3);
    pNVar11 = (this->m_IPTree).m_Elements.m_pMemory + iVar7;
    fVar2 = max_queries_window.value;
    if (pNVar11 != (Node_t *)0xfffffff0) {
      (pNVar11->m_Data).ip = local_2c[0].ip;
      (pNVar11->m_Data).lastTime = local_2c[0].lastTime;
      (pNVar11->m_Data).count = local_2c[0].count;
      fVar2 = max_queries_window.value;
    }
  }
  else {
    piVar1 = (int *)((int)&(((this->m_IPTree).m_Elements.m_pMemory)->m_Data).count + local_50);
    *piVar1 = *piVar1 + 1;
    pNVar11 = (this->m_IPTree).m_Elements.m_pMemory;
    if (fVar2 < (float)(tVar4 - *(int *)((int)&(pNVar11->m_Data).lastTime + local_50))) {
      *(time_t *)((int)&(pNVar11->m_Data).lastTime + local_50) = tVar4;
      *(undefined4 *)((int)&(((this->m_IPTree).m_Elements.m_pMemory)->m_Data).count + local_50) = 1;
    }
    else {
                    /* Unresolved local var: float query_rate@[???] */
      if (max_queries_sec.value < (float)*(int *)((int)&(pNVar11->m_Data).count + local_50) / fVar2)
      {
        return false;
      }
    }
  }
  iVar7 = this->m_iGlobalCount + 1;
  this->m_iGlobalCount = iVar7;
  if (fVar2 < (float)(tVar4 - this->m_lLastTime)) {
    this->m_iGlobalCount = 1;
    this->m_lLastTime = tVar4;
    return true;
  }
                    /* Unresolved local var: float query_rate@[???] */
  return (float)iVar7 / fVar2 <= max_queries_sec_global.value;
}


// CIPRateLimit::LessIP  @ 000c9dd0
bool CIPRateLimit::LessIP(iprate_s *lhs,iprate_s *rhs)

{
  return lhs->ip < rhs->ip;
}


// CIPRateLimit::~CIPRateLimit  @ 000c9e40
/* DWARF original prototype: void ~CIPRateLimit(CIPRateLimit * this, int __in_chrg) */

void __thiscall CIPRateLimit::~CIPRateLimit(CIPRateLimit *this,int __in_chrg)

{
  Node_t *__ptr;
  
  if (-1 < (this->m_IPTree).m_Elements.m_GrowSize) {
    __ptr = (this->m_IPTree).m_Elements.m_pMemory;
    if (__ptr != (Node_t *)0x0) {
      free(__ptr);
      (this->m_IPTree).m_Elements.m_pMemory = (Node_t *)0x0;
    }
    (this->m_IPTree).m_Elements.m_NumAllocated = 0;
  }
  return;
}


// CInitTracker::CInitTracker  @ 000c7bc0
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


// CInitTracker::Init  @ 000c7f60
/* DWARF original prototype: void Init(CInitTracker * this, char * init, char * shutdown, int
   listnum) */

void __thiscall CInitTracker::Init(CInitTracker *this,char *init,char *shutdown,int listnum)

{
  int iVar1;
  undefined4 *puVar2;
  CUtlVector<CInitTracker::InitFunc*> *this_00;
  int in_stack_ffffffd8;
  InitFunc **in_stack_ffffffdc;
  
                    /* Unresolved local var: InitFunc * f@[???] */
  this_00 = (CUtlVector<CInitTracker::InitFunc*> *)0x24;
  puVar2 = operator_new(0x24);
  *puVar2 = init;
  puVar2[1] = shutdown;
  iVar1 = this->m_nNumFuncs[listnum];
  *(undefined8 *)(puVar2 + 5) = 0;
  puVar2[2] = 1;
  *(undefined8 *)(puVar2 + 7) = 0;
  puVar2[3] = iVar1;
  *(undefined1 *)(puVar2 + 4) = 0;
  CUtlVector<CInitTracker::InitFunc*>::InsertBefore(this_00,in_stack_ffffffd8,in_stack_ffffffdc);
  this->m_nNumFuncs[listnum] = this->m_nNumFuncs[listnum] + 1;
  return;
}


// CInitTracker::Shutdown  @ 000c7c50
/* DWARF original prototype: void Shutdown(CInitTracker * this, char * shutdown, int listnum) */

void __thiscall CInitTracker::Shutdown(CInitTracker *this,char *shutdown,int listnum)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  InitFunc **ppIVar5;
  InitFunc *pIVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: InitFunc * f@[???] */
  iVar4 = this->m_nNumFuncs[listnum];
  if (iVar4 == 0) {
    Sys_Printf("Mismatched shutdown function %s\n");
    return;
  }
  if (0 < iVar4) {
    ppIVar5 = this->m_Funcs[listnum].m_Memory.m_pMemory;
    pIVar6 = *ppIVar5;
    if (pIVar6->referencecount == 0) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        if (iVar2 == iVar4) goto LAB_000c7c9e;
        pIVar6 = ppIVar5[iVar2];
      } while (pIVar6->referencecount == 0);
    }
    iVar2 = strcasecmp(pIVar6->shutdownname,shutdown);
    if ((iVar2 != 0) && (pIVar6->warningprinted == false)) {
      pIVar6->warningprinted = true;
      iVar4 = this->m_nNumFuncs[listnum];
      if (iVar4 < 1) goto LAB_000c7ce0;
      ppIVar5 = this->m_Funcs[listnum].m_Memory.m_pMemory;
    }
LAB_000c7c9e:
    iVar2 = 0;
    do {
                    /* Unresolved local var: InitFunc * f@[???] */
      pIVar6 = ppIVar5[iVar2];
      iVar3 = strcasecmp(pIVar6->shutdownname,shutdown);
      if (iVar3 == 0) {
        piVar1 = &pIVar6->referencecount;
        *piVar1 = *piVar1 + -1;
        return;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != iVar4);
  }
LAB_000c7ce0:
  Sys_Printf("Shutdown function %s not in list!!!\n");
  return;
}


// CInitTracker::~CInitTracker  @ 000c7ac0
/* DWARF original prototype: void ~CInitTracker(CInitTracker * this, int __in_chrg) */

void __thiscall CInitTracker::~CInitTracker(CInitTracker *this,int __in_chrg)

{
  InitFunc *pIVar1;
  void *__ptr;
  int iVar2;
  CInitTracker *pCVar3;
  int iVar4;
  CInitTracker *pCVar5;
  
                    /* Unresolved local var: int l@[???]
                       Unresolved local var: int i@[???] */
  iVar4 = 0;
  do {
    iVar2 = 0;
    if (0 < this->m_nNumFuncs[iVar4]) {
      do {
        pIVar1 = this->m_Funcs[iVar4].m_Memory.m_pMemory[iVar2];
        if (pIVar1->referencecount != 0) {
          Sys_Printf("Missing shutdown function for %s : %s\n",pIVar1->initname,pIVar1->shutdownname
                    );
        }
        iVar2 = iVar2 + 1;
        operator_delete(pIVar1);
      } while (iVar2 < this->m_nNumFuncs[iVar4]);
    }
    this->m_Funcs[iVar4].m_Size = 0;
    this->m_nNumFuncs[iVar4] = 0;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 4);
  if (this != (CInitTracker *)0xfffffff0) {
    pCVar5 = this + 1;
    pCVar3 = pCVar5;
    do {
      iVar4 = pCVar3[-1].m_Funcs[3].m_Memory.m_GrowSize;
      pCVar3[-1].m_Funcs[3].m_Size = 0;
      if (-1 < iVar4) {
        __ptr = *(void **)((int)this + (int)((int)pCVar3 + (0x4c - (int)pCVar5)));
        if (__ptr == (void *)0x0) {
          *(undefined4 *)((int)this + (int)((int)pCVar3 + (0x50 - (int)pCVar5))) = 0;
        }
        else {
          free(__ptr);
          *(undefined4 *)((int)this + (int)((int)pCVar3 + (0x4c - (int)pCVar5))) = 0;
          iVar4 = pCVar3[-1].m_Funcs[3].m_Memory.m_GrowSize;
          *(undefined4 *)((int)this + (int)((int)pCVar3 + (0x50 - (int)pCVar5))) = 0;
          if (iVar4 < 0) goto LAB_000c7b81;
        }
        *(undefined4 *)((int)this + (int)((int)pCVar3 + (0x50 - (int)pCVar5))) = 0;
      }
LAB_000c7b81:
      pCVar3 = (CInitTracker *)(pCVar3[-1].m_Funcs + 3);
    } while ((CInitTracker *)this->m_Funcs != pCVar3);
  }
  return;
}


// CRegistry::CRegistry  @ 000d5870
/* DWARF original prototype: void CRegistry(CRegistry * this) */

void __thiscall CRegistry::CRegistry(CRegistry *this)

{
  (this->super_IRegistry)._vptr_IRegistry = (_func_int_varargs **)&PTR_Init_000ee2c8;
  this->m_bValid = false;
  this->m_hKey = 0;
  return;
}


// CRegistry::Init  @ 000d5840
/* DWARF original prototype: void Init(CRegistry * this) */

void __thiscall CRegistry::Init(CRegistry *this)

{
  return;
}


// CRegistry::ReadInt  @ 000d5800
/* DWARF original prototype: int ReadInt(CRegistry * this, char * key, int defaultValue) */

int __thiscall CRegistry::ReadInt(CRegistry *this,char *key,int defaultValue)

{
  return defaultValue;
}


// CRegistry::ReadString  @ 000d5820
/* DWARF original prototype: char * ReadString(CRegistry * this, char * key, char * defaultValue) */

char * __thiscall CRegistry::ReadString(CRegistry *this,char *key,char *defaultValue)

{
  return defaultValue;
}


// CRegistry::Shutdown  @ 000d5850
/* DWARF original prototype: void Shutdown(CRegistry * this) */

void __thiscall CRegistry::Shutdown(CRegistry *this)

{
  return;
}


// CRegistry::WriteInt  @ 000d5810
/* DWARF original prototype: void WriteInt(CRegistry * this, char * key, int value) */

void __thiscall CRegistry::WriteInt(CRegistry *this,char *key,int value)

{
  return;
}


// CRegistry::WriteString  @ 000d5830
/* DWARF original prototype: void WriteString(CRegistry * this, char * key, char * value) */

void __thiscall CRegistry::WriteString(CRegistry *this,char *key,char *value)

{
  return;
}


// CRegistry::~CRegistry  @ 000d57f0
/* DWARF original prototype: void ~CRegistry(CRegistry * this, int __in_chrg) */

void __thiscall CRegistry::~CRegistry(CRegistry *this,int __in_chrg)

{
  (this->super_IRegistry)._vptr_IRegistry = (_func_int_varargs **)&PTR_Init_000ee2c8;
  return;
}


// CRegistry::~CRegistry  @ 000d5860
/* DWARF original prototype: void ~CRegistry(CRegistry * this, int __in_chrg) */

void __thiscall CRegistry::~CRegistry(CRegistry *this,int __in_chrg)

{
  (this->super_IRegistry)._vptr_IRegistry = (_func_int_varargs **)&PTR_Init_000ee2c8;
  operator_delete(this);
  return;
}


// CServerRemoteAccess::CServerRemoteAccess  @ 000c8390
/* DWARF original prototype: void CServerRemoteAccess(CServerRemoteAccess * this) */

void __thiscall CServerRemoteAccess::CServerRemoteAccess(CServerRemoteAccess *this)

{
  (this->super_IGameServerData).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__CServerRemoteAccess_000ed168;
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


// CServerRemoteAccess::ExecCommand  @ 000c8540
/* DWARF original prototype: void ExecCommand(CServerRemoteAccess * this, char * cmdString) */

void __thiscall CServerRemoteAccess::ExecCommand(CServerRemoteAccess *this,char *cmdString)

{
  Cbuf_AddText(cmdString);
  Cbuf_AddText("\n");
  Cbuf_Execute();
  return;
}


// CServerRemoteAccess::GetMapList  @ 000c8210
/* DWARF original prototype: void GetMapList(CServerRemoteAccess * this, CUtlBuffer * value) */

void __thiscall CServerRemoteAccess::GetMapList(CServerRemoteAccess *this,CUtlBuffer *value)

{
  bool bVar1;
  CUtlBuffer *in_EAX;
  char *pcVar2;
  char *pcVar3;
  char local_205c [4096];
  char local_105c [4096];
  char local_5c [76];
  
                    /* Unresolved local var: char[64] mapwild@[???]
                       Unresolved local var: char * findfn@[???] */
  builtin_strncpy(local_5c,"maps/*.bsp",0xb);
  pcVar2 = Sys_FindFirst(local_5c,(char *)0x0);
  if (pcVar2 != (char *)0x0) {
                    /* Unresolved local var: char[4096] curDir@[???]
                       Unresolved local var: char[4096] mapName@[???]
                       Unresolved local var: char * extension@[DW_OP_reg0(EAX)] */
    do {
      snprintf(local_205c,0x1000,"maps/%s",pcVar2);
      FS_GetLocalPath(local_205c,local_205c,0x1000);
      pcVar3 = strstr(local_205c,com_gamedir);
      if (pcVar3 != (char *)0x0) {
        strcpy(local_105c,pcVar2);
        pcVar2 = strstr(local_105c,".bsp");
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
        CUtlBuffer::PutString(in_EAX,local_105c);
        CUtlBuffer::PutString(in_EAX,"\n");
      }
      pcVar2 = Sys_FindNext((char *)0x0);
    } while (pcVar2 != (char *)0x0);
  }
  Sys_FindClose();
  if ((in_EAX->m_Flags & 1) == 0) {
    bVar1 = CUtlBuffer::CheckPut(in_EAX,1);
    if (bVar1) {
      (in_EAX->m_Memory).m_pMemory[in_EAX->m_Put] = '\0';
      in_EAX->m_Put = in_EAX->m_Put + 1;
    }
    return;
  }
  CUtlBuffer::Printf(in_EAX,"%c",0);
  return;
}


// CServerRemoteAccess::GetMapList  @ 000c92b0
/* DWARF original prototype: void GetMapList(CServerRemoteAccess * this, CUtlBuffer * value) */

void __thiscall CServerRemoteAccess::GetMapList(CServerRemoteAccess *this,CUtlBuffer *value)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  char local_205c [4096];
  char local_105c [4096];
  char local_5c [76];
  
                    /* Unresolved local var: char[64] mapwild@[???]
                       Unresolved local var: char * findfn@[???] */
  builtin_strncpy(local_5c,"maps/*.bsp",0xb);
  pcVar2 = Sys_FindFirst(local_5c,(char *)0x0);
  if (pcVar2 != (char *)0x0) {
                    /* Unresolved local var: char[4096] curDir@[???]
                       Unresolved local var: char[4096] mapName@[???]
                       Unresolved local var: char * extension@[DW_OP_reg0(EAX)] */
    do {
      snprintf(local_205c,0x1000,"maps/%s",pcVar2);
      FS_GetLocalPath(local_205c,local_205c,0x1000);
      pcVar3 = strstr(local_205c,com_gamedir);
      if (pcVar3 != (char *)0x0) {
        strcpy(local_105c,pcVar2);
        pcVar2 = strstr(local_105c,".bsp");
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
        CUtlBuffer::PutString(value,local_105c);
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
    return;
  }
  CUtlBuffer::Printf(value,"%c",0);
  return;
}


// CServerRemoteAccess::GetPlayerList  @ 000c9120
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
  
                    /* Unresolved local var: client_t.conflict * client@[???]
                       Unresolved local var: int i@[???] */
  if (0 < svs.maxclients) {
    iVar11 = 0;
    iVar7 = svs.maxclients;
    pcVar10 = svs.clients;
    do {
      while ((pcVar10->active == false || (pcVar10->name[0] == '\0'))) {
        iVar11 = iVar11 + 1;
        pcVar10 = pcVar10 + 1;
        if (iVar7 <= iVar11) goto LAB_000c9254;
      }
      iVar11 = iVar11 + 1;
      dVar5 = realtime - (double)(pcVar10->netchan).connect_time;
      fVar4 = pcVar10->latency;
      fVar2 = pcVar10->packet_loss;
      fVar3 = (pcVar10->edict->v).frags;
      pcVar8 = NET_AdrToString((pcVar10->netchan).remote_address);
      pcVar9 = SV_GetIDString(&pcVar10->network_userid);
      pcVar1 = pcVar10->name;
      pcVar10 = pcVar10 + 1;
      CUtlBuffer::Printf(value,"\"%s\" %s %s %d %d %d %d\n",pcVar1,pcVar9,pcVar8,
                         (int)(fVar4 * 1000.0),(int)fVar2,(int)fVar3,(int)dVar5);
      iVar7 = svs.maxclients;
    } while (iVar11 < svs.maxclients);
  }
LAB_000c9254:
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


// CServerRemoteAccess::GetUserBanList  @ 000c8ff0
/* DWARF original prototype: void GetUserBanList(CServerRemoteAccess * this, CUtlBuffer * value) */

void __thiscall CServerRemoteAccess::GetUserBanList(CServerRemoteAccess *this,CUtlBuffer *value)

{
  float fVar1;
  uint uVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < numuserfilters) {
    pfVar7 = &userfilters[0].banTime;
    iVar6 = 0;
    do {
      fVar1 = *pfVar7;
      iVar5 = iVar6 + 1;
      pfVar7 = pfVar7 + 6;
      pcVar4 = SV_GetIDString(&userfilters[iVar6].userid);
      CUtlBuffer::Printf(value,"%i %s : %.3f min\n",iVar5,pcVar4,(double)fVar1);
      iVar6 = iVar5;
    } while (iVar5 < numuserfilters);
  }
  if (0 < numipfilters) {
    iVar6 = 0;
    do {
                    /* Unresolved local var: char[4] b@[???] */
      iVar5 = iVar6 + 1;
      uVar2 = ipfilters[iVar6].compare;
      CUtlBuffer::Printf(value,"%i %i.%i.%i.%i : %.3f min\n",numuserfilters + iVar5,(int)(char)uVar2
                         ,(int)(char)(uVar2 >> 8),(int)(uVar2 << 8) >> 0x18,(int)uVar2 >> 0x18,
                         (double)ipfilters[iVar6].banTime);
      iVar6 = iVar5;
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


// CServerRemoteAccess::LookupStringValue  @ 000c8570
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
      iVar2 = strcasecmp(variable,"playercount");
      if (iVar2 == 0) {
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: int i@[???] */
        iVar2 = 0;
        if (0 < svs.maxclients) {
          iVar5 = 0;
          pcVar3 = svs.clients;
          do {
            if (((pcVar3->active != false) || (pcVar3->spawned != false)) ||
               (pcVar3->connected != false)) {
              iVar2 = iVar2 + 1;
            }
            iVar5 = iVar5 + 1;
            pcVar3 = pcVar3 + 1;
          } while (iVar5 != svs.maxclients);
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
                    /* WARNING: Could not recover jumptable at 0x000c8683. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          pcVar4 = (*gEntityInterface.pfnGetGameDescription)();
          return pcVar4;
        }
      }
      snprintf(LookupStringValue::lexical_block_0::s_ReturnBuf,0x1f,"%d",iVar2);
      pcVar4 = LookupStringValue::lexical_block_0::s_ReturnBuf;
    }
  }
  else {
    pcVar4 = pcVar1->string;
  }
  return pcVar4;
}


// CServerRemoteAccess::LookupValue  @ 000c86a0
/* DWARF original prototype: bool LookupValue(CServerRemoteAccess * this, char * variable,
   CUtlBuffer * value) */

bool __thiscall
CServerRemoteAccess::LookupValue(CServerRemoteAccess *this,char *variable,CUtlBuffer *value)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  uint uVar5;
  netadr_t a;
  bool bVar6;
  CServerRemoteAccess *in_EAX;
  char *pcVar7;
  long lVar8;
  int iVar9;
  uchar *pString;
  char *pcVar10;
  CUtlBuffer *in_ECX;
  CServerRemoteAccess *in_EDX;
  client_s *pcVar11;
  float *pfVar12;
  int iVar13;
  double dVar14;
  CServerRemoteAccess *this_00;
  char local_22c [512];
  int local_2c [7];
  
                    /* Unresolved local var: char * strval@[???] */
  pcVar7 = LookupStringValue(in_EAX,(char *)in_EDX);
  if (pcVar7 == (char *)0x0) {
    iVar9 = strcasecmp((char *)in_EDX,"stats");
    if (iVar9 == 0) {
                    /* Unresolved local var: char[512] stats@[???] */
      GetStatsString(local_22c,0x200);
      CUtlBuffer::PutString(in_ECX,local_22c);
      bVar4 = in_ECX->m_Flags;
    }
    else {
      iVar9 = strcasecmp((char *)in_EDX,"banlist");
      if (iVar9 == 0) {
                    /* Unresolved local var: int i@[???] */
        if (0 < numuserfilters) {
          pfVar12 = &userfilters[0].banTime;
          iVar9 = 0;
          do {
            fVar1 = *pfVar12;
            iVar13 = iVar9 + 1;
            pfVar12 = pfVar12 + 6;
            pcVar7 = SV_GetIDString(&userfilters[iVar9].userid);
            CUtlBuffer::Printf(in_ECX,"%i %s : %.3f min\n",iVar13,pcVar7,SUB84((double)fVar1,0),
                               (int)((ulonglong)(double)fVar1 >> 0x20));
            iVar9 = iVar13;
          } while (iVar13 < numuserfilters);
        }
        if (0 < numipfilters) {
          iVar9 = 0;
          do {
                    /* Unresolved local var: char[4] b@[???] */
            iVar13 = iVar9 + 1;
            uVar5 = ipfilters[iVar9].compare;
            CUtlBuffer::Printf(in_ECX,"%i %i.%i.%i.%i : %.3f min\n",iVar13 + numuserfilters,
                               (int)(char)uVar5,(int)(char)(uVar5 >> 8),(int)(uVar5 << 8) >> 0x18,
                               (int)uVar5 >> 0x18,(double)ipfilters[iVar9].banTime);
            iVar9 = iVar13;
          } while (iVar13 < numipfilters);
        }
      }
      else {
        iVar9 = strcasecmp((char *)in_EDX,"playerlist");
        if (iVar9 == 0) {
                    /* Unresolved local var: client_t.conflict * client@[???]
                       Unresolved local var: int i@[???] */
          if (0 < svs.maxclients) {
            iVar13 = 0;
            iVar9 = svs.maxclients;
            pcVar11 = svs.clients;
            do {
              if ((pcVar11->active != false) && (pcVar11->name[0] != '\0')) {
                dVar14 = realtime - (double)(pcVar11->netchan).connect_time;
                fVar3 = pcVar11->latency;
                fVar1 = pcVar11->packet_loss;
                fVar2 = (pcVar11->edict->v).frags;
                pcVar7 = NET_AdrToString((pcVar11->netchan).remote_address);
                pcVar10 = SV_GetIDString(&pcVar11->network_userid);
                CUtlBuffer::Printf(in_ECX,"\"%s\" %s %s %d %d %d %d\n",pcVar11->name,pcVar10,pcVar7,
                                   (int)(fVar3 * 1000.0),(int)fVar1,(int)fVar2,(int)dVar14);
                iVar9 = svs.maxclients;
              }
              iVar13 = iVar13 + 1;
              pcVar11 = pcVar11 + 1;
            } while (iVar13 < iVar9);
          }
        }
        else {
          pcVar7 = "maplist";
          this_00 = in_EDX;
          iVar9 = strcasecmp((char *)in_EDX,"maplist");
          if (iVar9 == 0) {
            GetMapList(this_00,(CUtlBuffer *)pcVar7);
            return true;
          }
          iVar9 = strcasecmp((char *)in_EDX,"uptime");
          if (iVar9 == 0) {
                    /* Unresolved local var: int timeSeconds@[???] */
            dVar14 = Sys_FloatTime();
            lVar8 = Host_GetStartTime();
            if ((in_ECX->m_Flags & 1) == 0) {
              bVar6 = CUtlBuffer::CheckPut(in_ECX,4);
              if (bVar6) {
                *(int *)((in_ECX->m_Memory).m_pMemory + in_ECX->m_Put) =
                     (int)(dVar14 - (double)lVar8);
                in_ECX->m_Put = in_ECX->m_Put + 4;
              }
            }
            else {
              CUtlBuffer::Printf(in_ECX,"%d",(int)(dVar14 - (double)lVar8));
            }
          }
          else {
            iVar9 = strcasecmp((char *)in_EDX,"ipaddress");
            if (iVar9 != 0) {
              iVar9 = strcasecmp((char *)in_EDX,"mapcycle");
              if (iVar9 != 0) {
                if ((in_ECX->m_Flags & 1) != 0) {
                  CUtlBuffer::Printf(in_ECX,"%c",0);
                  return false;
                }
                bVar6 = CUtlBuffer::CheckPut(in_ECX,1);
                if (!bVar6) {
                  return false;
                }
                (in_ECX->m_Memory).m_pMemory[in_ECX->m_Put] = '\0';
                in_ECX->m_Put = in_ECX->m_Put + 1;
                return false;
              }
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: void * mapcyclelist@[???] */
              local_2c[0] = 0;
              pString = COM_LoadFileForMe(mapcyclefile.string,local_2c);
              if (pString == (uchar *)0x0) {
                return true;
              }
              if (local_2c[0] == 0) {
                return true;
              }
              CUtlBuffer::PutString(in_ECX,(char *)pString);
              if ((in_ECX->m_Flags & 1) == 0) {
                bVar6 = CUtlBuffer::CheckPut(in_ECX,1);
                if (bVar6) {
                  (in_ECX->m_Memory).m_pMemory[in_ECX->m_Put] = '\0';
                  in_ECX->m_Put = in_ECX->m_Put + 1;
                }
              }
              else {
                CUtlBuffer::Printf(in_ECX,"%c",0);
              }
              COM_FreeFile(pString);
              return true;
            }
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
            pcVar7 = NET_AdrToString(a);
            CUtlBuffer::PutString(in_ECX,pcVar7);
          }
        }
      }
      bVar4 = in_ECX->m_Flags;
    }
  }
  else {
    CUtlBuffer::PutString(in_ECX,pcVar7);
    bVar4 = in_ECX->m_Flags;
  }
  if ((bVar4 & 1) == 0) {
    bVar6 = CUtlBuffer::CheckPut(in_ECX,1);
    if (bVar6) {
      (in_ECX->m_Memory).m_pMemory[in_ECX->m_Put] = '\0';
      in_ECX->m_Put = in_ECX->m_Put + 1;
      return true;
    }
  }
  else {
    CUtlBuffer::Printf(in_ECX,"%c",0);
  }
  return true;
}


// CServerRemoteAccess::LookupValue  @ 000c9430
/* DWARF original prototype: bool LookupValue(CServerRemoteAccess * this, char * variable,
   CUtlBuffer * value) */

bool __thiscall
CServerRemoteAccess::LookupValue(CServerRemoteAccess *this,char *variable,CUtlBuffer *value)

{
  byte bVar1;
  netadr_t a;
  bool bVar2;
  char *pString;
  int iVar3;
  uchar *pString_00;
  long lVar4;
  double dVar5;
  char local_21c [512];
  int local_1c [4];
  
                    /* Unresolved local var: char * strval@[???] */
  pString = LookupStringValue(this,variable);
  if (pString == (char *)0x0) {
    iVar3 = strcasecmp(variable,"stats");
    if (iVar3 == 0) {
                    /* Unresolved local var: char[512] stats@[???] */
      GetStatsString(local_21c,0x200);
      CUtlBuffer::PutString(value,local_21c);
      bVar1 = value->m_Flags;
      goto joined_r0x000c94e5;
    }
    iVar3 = strcasecmp(variable,"banlist");
    if (iVar3 == 0) {
      GetUserBanList(this,value);
      return true;
    }
    iVar3 = strcasecmp(variable,"playerlist");
    if (iVar3 == 0) {
      GetPlayerList(this,value);
      return true;
    }
    iVar3 = strcasecmp(variable,"maplist");
    if (iVar3 == 0) {
      GetMapList(this,value);
      return true;
    }
    iVar3 = strcasecmp(variable,"uptime");
    if (iVar3 != 0) {
      iVar3 = strcasecmp(variable,"ipaddress");
      if (iVar3 != 0) {
        iVar3 = strcasecmp(variable,"mapcycle");
        if (iVar3 != 0) {
          if ((value->m_Flags & 1) != 0) {
            CUtlBuffer::Printf(value,"%c",0);
            return false;
          }
          bVar2 = CUtlBuffer::CheckPut(value,1);
          if (!bVar2) {
            return false;
          }
          (value->m_Memory).m_pMemory[value->m_Put] = '\0';
          value->m_Put = value->m_Put + 1;
          return false;
        }
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: void * mapcyclelist@[???] */
        local_1c[0] = 0;
        pString_00 = COM_LoadFileForMe(mapcyclefile.string,local_1c);
        if (pString_00 == (uchar *)0x0) {
          return true;
        }
        if (local_1c[0] == 0) {
          return true;
        }
        CUtlBuffer::PutString(value,(char *)pString_00);
        if ((value->m_Flags & 1) == 0) {
          bVar2 = CUtlBuffer::CheckPut(value,1);
          if (bVar2) {
            (value->m_Memory).m_pMemory[value->m_Put] = '\0';
            value->m_Put = value->m_Put + 1;
          }
        }
        else {
          CUtlBuffer::Printf(value,"%c",0);
        }
        COM_FreeFile(pString_00);
        return true;
      }
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
      pString = NET_AdrToString(a);
      goto LAB_000c9474;
    }
                    /* Unresolved local var: int timeSeconds@[???] */
    dVar5 = Sys_FloatTime();
    lVar4 = Host_GetStartTime();
    if ((value->m_Flags & 1) == 0) {
      bVar2 = CUtlBuffer::CheckPut(value,4);
      if (bVar2) {
        *(int *)((value->m_Memory).m_pMemory + value->m_Put) = (int)(dVar5 - (double)lVar4);
        value->m_Put = value->m_Put + 4;
      }
    }
    else {
      CUtlBuffer::Printf(value,"%d",(int)(dVar5 - (double)lVar4));
    }
  }
  else {
LAB_000c9474:
    CUtlBuffer::PutString(value,pString);
  }
  bVar1 = value->m_Flags;
joined_r0x000c94e5:
  if ((bVar1 & 1) == 0) {
    bVar2 = CUtlBuffer::CheckPut(value,1);
    if (bVar2) {
      (value->m_Memory).m_pMemory[value->m_Put] = '\0';
      value->m_Put = value->m_Put + 1;
    }
  }
  else {
    CUtlBuffer::Printf(value,"%c",0);
  }
  return true;
}


// CServerRemoteAccess::ReadDataResponse  @ 000c99b0
/* WARNING: Variable defined which should be unmapped: i */
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: int ReadDataResponse(CServerRemoteAccess * this, void * buffer, int
   bufferSize) */

int __thiscall
CServerRemoteAccess::ReadDataResponse(CServerRemoteAccess *this,void *buffer,int bufferSize)

{
  uchar uVar1;
  undefined2 uVar2;
  int elem;
  uchar *__ptr;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  ListElem_t *pLVar6;
  uchar *local_38;
  int local_30;
  undefined4 *local_2c;
  uint local_20;
  int i;
  
  elem = (this->m_ResponsePackets).m_Head;
  if ((elem < 0) || ((this->m_ResponsePackets).m_TotalElements <= elem)) {
    uVar4 = 0;
  }
  else {
    pLVar6 = (this->m_ResponsePackets).m_Memory.m_pMemory + elem;
    if ((elem != pLVar6->m_Previous) || (uVar4 = 0, elem == pLVar6->m_Next)) {
      uVar4 = (pLVar6->m_Element).packet.m_Put;
                    /* Unresolved local var: CUtlBuffer * response@[???]
                       Unresolved local var: int bytesToCopy@[???] */
      if (bufferSize < (int)uVar4) {
        uVar4 = 0;
      }
      else {
        local_38 = (pLVar6->m_Element).packet.m_Memory.m_pMemory;
        local_2c = buffer;
        local_20 = uVar4;
        if (7 < uVar4) {
          if (((uint)buffer & 1) != 0) {
            uVar1 = *local_38;
            local_38 = local_38 + 1;
            *(uchar *)buffer = uVar1;
            local_2c = (undefined4 *)((int)buffer + 1);
            local_20 = uVar4 - 1;
          }
          if (((uint)local_2c & 2) != 0) {
            uVar2 = *(undefined2 *)local_38;
            local_38 = local_38 + 2;
            *(undefined2 *)local_2c = uVar2;
            local_2c = (undefined4 *)((int)local_2c + 2);
            local_20 = local_20 - 2;
          }
          if (((uint)local_2c & 4) != 0) {
            uVar3 = *(undefined4 *)local_38;
            local_38 = local_38 + 4;
            *local_2c = uVar3;
            local_2c = local_2c + 1;
            local_20 = local_20 - 4;
          }
          for (uVar5 = local_20 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *local_2c = *(undefined4 *)local_38;
            local_38 = local_38 + 4;
            local_2c = local_2c + 1;
          }
          local_20 = local_20 & 3;
        }
        local_30 = 0;
        if ((local_20 & 4) != 0) {
          *local_2c = *(undefined4 *)local_38;
          local_30 = 4;
        }
        if ((local_20 & 2) != 0) {
          *(undefined2 *)((int)local_2c + local_30) = *(undefined2 *)(local_38 + local_30);
          local_30 = local_30 + 2;
        }
        if ((local_20 & 1) != 0) {
          *(uchar *)((int)local_2c + local_30) = local_38[local_30];
        }
        pLVar6 = (this->m_ResponsePackets).m_Memory.m_pMemory + elem;
      }
      this->m_iBytesSent = this->m_iBytesSent + uVar4;
      if (-1 < (pLVar6->m_Element).packet.m_Memory.m_GrowSize) {
        __ptr = (pLVar6->m_Element).packet.m_Memory.m_pMemory;
        if (__ptr != (uchar *)0x0) {
          free(__ptr);
          (pLVar6->m_Element).packet.m_Memory.m_pMemory = (uchar *)0x0;
        }
        (pLVar6->m_Element).packet.m_Memory.m_NumAllocated = 0;
        pLVar6 = (this->m_ResponsePackets).m_Memory.m_pMemory + elem;
      }
      if ((elem < (this->m_ResponsePackets).m_TotalElements) && (elem != pLVar6->m_Previous)) {
        CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::Unlink
                  (&this->m_ResponsePackets,elem);
        pLVar6 = (this->m_ResponsePackets).m_Memory.m_pMemory + elem;
      }
      pLVar6->m_Next = (this->m_ResponsePackets).m_FirstFree;
      (this->m_ResponsePackets).m_FirstFree = elem;
    }
  }
  return uVar4;
}


// CServerRemoteAccess::RequestValue  @ 000c8be0
/* DWARF original prototype: void RequestValue(CServerRemoteAccess * this, int requestID, char *
   variable) */

void __thiscall
CServerRemoteAccess::RequestValue(CServerRemoteAccess *this,int requestID,char *variable)

{
  int *piVar1;
  uchar *puVar2;
  bool bVar3;
  int iVar4;
  ListElem_t *this_00;
  CServerRemoteAccess *this_01;
  char *variable_00;
  CUtlBuffer *value;
  IBaseInterface local_3c;
  int local_34;
  int local_2c;
  
                    /* Unresolved local var: CUtlBuffer value@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: CUtlBuffer * response@[???] */
  this_01 = (CServerRemoteAccess *)&local_3c;
  value = (CUtlBuffer *)0x100;
  variable_00 = (char *)0x0;
  CUtlBuffer::CUtlBuffer((CUtlBuffer *)this_01,0,0x100,true);
  LookupValue(this_01,variable_00,value);
  iVar4 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::InsertBefore
                    ((CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int> *)this_01,
                     (int)variable_00);
  this_00 = (this->m_ResponsePackets).m_Memory.m_pMemory + iVar4;
  if (((this_00->m_Element).packet.m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut((CUtlBuffer *)this_00,4);
    if (bVar3) {
      *(int *)((this_00->m_Element).packet.m_Memory.m_pMemory + (this_00->m_Element).packet.m_Put) =
           requestID;
      piVar1 = &(this_00->m_Element).packet.m_Put;
      *piVar1 = *piVar1 + 4;
    }
  }
  else {
    CUtlBuffer::Printf((CUtlBuffer *)this_00,"%d",requestID);
  }
  if (((this_00->m_Element).packet.m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut((CUtlBuffer *)this_00,4);
    if (bVar3) {
      puVar2 = (this_00->m_Element).packet.m_Memory.m_pMemory + (this_00->m_Element).packet.m_Put;
      puVar2[0] = '\0';
      puVar2[1] = '\0';
      puVar2[2] = '\0';
      puVar2[3] = '\0';
      piVar1 = &(this_00->m_Element).packet.m_Put;
      *piVar1 = *piVar1 + 4;
    }
  }
  else {
    CUtlBuffer::Printf((CUtlBuffer *)this_00,"%d",0);
  }
  CUtlBuffer::PutString((CUtlBuffer *)this_00,variable);
  iVar4 = local_2c;
  if (((this_00->m_Element).packet.m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut((CUtlBuffer *)this_00,4);
    if (bVar3) {
      *(int *)((this_00->m_Element).packet.m_Memory.m_pMemory + (this_00->m_Element).packet.m_Put) =
           iVar4;
      piVar1 = &(this_00->m_Element).packet.m_Put;
      *piVar1 = *piVar1 + 4;
    }
  }
  else {
    CUtlBuffer::Printf((CUtlBuffer *)this_00,"%d",local_2c);
  }
  if (local_2c != 0) {
    CUtlBuffer::Put((CUtlBuffer *)this_00,local_3c._vptr_IBaseInterface,local_2c);
  }
  if ((-1 < local_34) && (local_3c._vptr_IBaseInterface != (_func_int_varargs **)0x0)) {
    free(local_3c._vptr_IBaseInterface);
  }
  return;
}


// CServerRemoteAccess::SendMessageToAdminUI  @ 000c97e0
/* DWARF original prototype: void SendMessageToAdminUI(CServerRemoteAccess * this, char * message)
    */

void __thiscall CServerRemoteAccess::SendMessageToAdminUI(CServerRemoteAccess *this,char *message)

{
  int *piVar1;
  uchar *puVar2;
  bool bVar3;
  int iVar4;
  ListElem_t *this_00;
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int> *in_stack_ffffffe4;
  int in_stack_ffffffe8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CUtlBuffer * response@[???] */
  iVar4 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::InsertBefore
                    (in_stack_ffffffe4,in_stack_ffffffe8);
  this_00 = (this->m_ResponsePackets).m_Memory.m_pMemory + iVar4;
  if (((this_00->m_Element).packet.m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut((CUtlBuffer *)this_00,4);
    if (bVar3) {
      puVar2 = (this_00->m_Element).packet.m_Memory.m_pMemory + (this_00->m_Element).packet.m_Put;
      puVar2[0] = '\0';
      puVar2[1] = '\0';
      puVar2[2] = '\0';
      puVar2[3] = '\0';
      piVar1 = &(this_00->m_Element).packet.m_Put;
      *piVar1 = *piVar1 + 4;
    }
  }
  else {
    CUtlBuffer::Printf((CUtlBuffer *)this_00,"%d",0);
  }
  if (((this_00->m_Element).packet.m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut((CUtlBuffer *)this_00,4);
    if (bVar3) {
      puVar2 = (this_00->m_Element).packet.m_Memory.m_pMemory + (this_00->m_Element).packet.m_Put;
      puVar2[0] = '\x01';
      puVar2[1] = '\0';
      puVar2[2] = '\0';
      puVar2[3] = '\0';
      piVar1 = &(this_00->m_Element).packet.m_Put;
      *piVar1 = *piVar1 + 4;
    }
  }
  else {
    CUtlBuffer::Printf((CUtlBuffer *)this_00,"%d",1);
  }
  CUtlBuffer::PutString((CUtlBuffer *)this_00,message);
  return;
}


// CServerRemoteAccess::SetValue  @ 000c83f0
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
  if (iVar1 == 0) {
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
                    /* Unresolved local var: cvar_t * var@[???] */
  var = Cvar_FindVar(variable);
  if (var == (cvar_t *)0x0) {
    return;
  }
  Cvar_DirectSet(var,value);
  return;
}


// CServerRemoteAccess::WriteDataRequest  @ 000c8db0
/* DWARF original prototype: void WriteDataRequest(CServerRemoteAccess * this, void * buffer, int
   bufferSize) */

void __thiscall
CServerRemoteAccess::WriteDataRequest(CServerRemoteAccess *this,void *buffer,int bufferSize)

{
  bool bVar1;
  int requestID;
  char local_34c [512];
  char local_14c [256];
  CUtlBuffer local_4c;
  int local_2c [7];
  
                    /* Unresolved local var: CUtlBuffer cmd@[???]
                       Unresolved local var: int requestID@[???]
                       Unresolved local var: int requestType@[???] */
  this->m_iBytesReceived = this->m_iBytesReceived + bufferSize;
  CUtlBuffer::CUtlBuffer(&local_4c,buffer,bufferSize,false);
                    /* Unresolved local var: int i@[???] */
  if ((local_4c.m_Flags & 1) == 0) {
    bVar1 = CUtlBuffer::CheckGet(&local_4c,4);
    if (!bVar1) {
      local_2c[0] = 0;
      goto LAB_000c8ebb;
    }
                    /* Unresolved local var: int i@[???] */
    local_2c[0] = *(int *)(local_4c.m_Memory.m_pMemory + local_4c.m_Get);
    local_4c.m_Get = local_4c.m_Get + 4;
                    /* Unresolved local var: int i@[???] */
    if ((local_4c.m_Flags & 1) == 0) goto LAB_000c8ec5;
LAB_000c8e55:
    requestID = local_2c[0];
    CUtlBuffer::Scanf(&local_4c,"%d",local_2c);
joined_r0x000c8f68:
    if (local_2c[0] == 1) {
                    /* Unresolved local var: char[256] variable@[???]
                       Unresolved local var: char[256] value@[???] */
      CUtlBuffer::GetString(&local_4c,local_34c);
      CUtlBuffer::GetString(&local_4c,local_14c);
      SetValue(this,local_34c,local_14c);
      goto LAB_000c8f03;
    }
    if (local_2c[0] == 2) {
                    /* Unresolved local var: char[512] command@[???] */
      CUtlBuffer::GetString(&local_4c,local_34c);
      Cbuf_AddText(local_34c);
      Cbuf_AddText("\n");
      Cbuf_Execute();
      goto LAB_000c8f03;
    }
    if (local_2c[0] != 0) goto LAB_000c8f03;
  }
  else {
    CUtlBuffer::Scanf(&local_4c,"%d",local_2c);
LAB_000c8ebb:
    if ((local_4c.m_Flags & 1) != 0) goto LAB_000c8e55;
LAB_000c8ec5:
    requestID = local_2c[0];
    bVar1 = CUtlBuffer::CheckGet(&local_4c,4);
    if (bVar1) {
                    /* Unresolved local var: int i@[???] */
      local_2c[0] = *(int *)(local_4c.m_Memory.m_pMemory + local_4c.m_Get);
      local_4c.m_Get = local_4c.m_Get + 4;
      goto joined_r0x000c8f68;
    }
    local_2c[0] = 0;
  }
                    /* Unresolved local var: char[256] variable@[???] */
  CUtlBuffer::GetString(&local_4c,local_34c);
  RequestValue(this,requestID,local_34c);
LAB_000c8f03:
  if ((-1 < local_4c.m_Memory.m_GrowSize) && (local_4c.m_Memory.m_pMemory != (uchar *)0x0)) {
    free(local_4c.m_Memory.m_pMemory);
  }
  return;
}


// CServerRemoteAccess::~CServerRemoteAccess  @ 000c9ca0
/* DWARF original prototype: void ~CServerRemoteAccess(CServerRemoteAccess * this, int __in_chrg) */

void __thiscall CServerRemoteAccess::~CServerRemoteAccess(CServerRemoteAccess *this,int __in_chrg)

{
  ListElem_t *__ptr;
  
  (this->super_IGameServerData).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__CServerRemoteAccess_000ed168;
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::RemoveAll(&this->m_ResponsePackets);
  if (-1 < (this->m_ResponsePackets).m_Memory.m_GrowSize) {
    __ptr = (this->m_ResponsePackets).m_Memory.m_pMemory;
    if (__ptr != (ListElem_t *)0x0) {
      free(__ptr);
      (this->m_ResponsePackets).m_Memory.m_pMemory = (ListElem_t *)0x0;
    }
    (this->m_ResponsePackets).m_Memory.m_NumAllocated = 0;
  }
  (this->super_IGameServerData).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  return;
}


// CServerRemoteAccess::~CServerRemoteAccess  @ 000c9cf0
/* DWARF original prototype: void ~CServerRemoteAccess(CServerRemoteAccess * this, int __in_chrg) */

void __thiscall CServerRemoteAccess::~CServerRemoteAccess(CServerRemoteAccess *this,int __in_chrg)

{
  ListElem_t *__ptr;
  
  (this->super_IGameServerData).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__CServerRemoteAccess_000ed168;
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::RemoveAll(&this->m_ResponsePackets);
  if (-1 < (this->m_ResponsePackets).m_Memory.m_GrowSize) {
    __ptr = (this->m_ResponsePackets).m_Memory.m_pMemory;
    if (__ptr != (ListElem_t *)0x0) {
      free(__ptr);
      (this->m_ResponsePackets).m_Memory.m_pMemory = (ListElem_t *)0x0;
    }
    (this->m_ResponsePackets).m_Memory.m_NumAllocated = 0;
  }
  (this->super_IGameServerData).super_IBaseInterface._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// CSteam3::~CSteam3  @ 000d0570
/* DWARF original prototype: void ~CSteam3(CSteam3 * this, int __in_chrg) */

void __thiscall CSteam3::~CSteam3(CSteam3 *this,int __in_chrg)

{
  this->_vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3_000edb38;
  return;
}


// CSteam3::~CSteam3  @ 000d0970
/* DWARF original prototype: void ~CSteam3(CSteam3 * this, int __in_chrg) */

void __thiscall CSteam3::~CSteam3(CSteam3 *this,int __in_chrg)

{
  this->_vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3_000edb38;
  operator_delete(this);
  return;
}


// CSteam3Client::InitClient  @ 000cfdf0
/* DWARF original prototype: void InitClient(CSteam3Client * this) */

void __thiscall CSteam3Client::InitClient(CSteam3Client *this)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  FILE *__stream;
  
  if ((this->super_CSteam3).m_bLoggedOn != false) {
    return;
  }
  (this->super_CSteam3).m_bLoggedOn = true;
  unlink("steam_appid.txt");
  pcVar2 = getenv("SteamAppId");
  if (pcVar2 == (char *)0x0) {
                    /* Unresolved local var: int nAppID@[???] */
    iVar3 = GetGameAppID();
    if (0 < iVar3) {
                    /* Unresolved local var: FILE * f@[???] */
      __stream = fopen("steam_appid.txt","w+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%d\n",iVar3);
        fclose(__stream);
      }
    }
  }
  cVar1 = SteamAPI_Init();
  if (cVar1 != '\0') {
    (this->super_CSteam3).m_bLogOnResult = false;
    return;
  }
  Sys_Error("Failed to initalize authentication interface. Exiting...\n");
  return;
}


// CSteam3Client::InitiateGameConnection  @ 000cfd20
/* DWARF original prototype: int InitiateGameConnection(CSteam3Client * this, void * pData, int
   cbMaxData, uint64 steamID, uint32 unIPServer, uint16 usPortServer, bool bSecure) */

int __thiscall
CSteam3Client::InitiateGameConnection
          (CSteam3Client *this,void *pData,int cbMaxData,uint64 steamID,uint32 unIPServer,
          uint16 usPortServer,bool bSecure)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)SteamUser();
                    /* Unresolved local var: ushort __v@[DW_OP_reg3(EBX)]
                       Unresolved local var: ushort __x@[???] */
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
  iVar2 = (**(code **)(*piVar1 + 0xc))
                    (piVar1,pData,cbMaxData,steamID,
                     unIPServer >> 0x18 | (unIPServer & 0xff0000) >> 8 | (unIPServer & 0xff00) << 8
                     | unIPServer << 0x18,usPortServer >> 8 | usPortServer << 8,bSecure);
  return iVar2;
}


// CSteam3Client::OnClientGameServerDeny  @ 000ce910
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


// CSteam3Client::OnGameOverlayActivated  @ 000ce840
/* DWARF original prototype: void OnGameOverlayActivated(CSteam3Client * this,
   GameOverlayActivated_t * pGameOverlayActivated) */

void __thiscall
CSteam3Client::OnGameOverlayActivated
          (CSteam3Client *this,GameOverlayActivated_t *pGameOverlayActivated)

{
  return;
}


// CSteam3Client::OnGameServerChangeRequested  @ 000ce830
/* DWARF original prototype: void OnGameServerChangeRequested(CSteam3Client * this,
   GameServerChangeRequested_t * pGameServerChangeRequested) */

void __thiscall
CSteam3Client::OnGameServerChangeRequested
          (CSteam3Client *this,GameServerChangeRequested_t *pGameServerChangeRequested)

{
  return;
}


// CSteam3Client::RunFrame  @ 000cfed0
/* DWARF original prototype: void RunFrame(CSteam3Client * this) */

void __thiscall CSteam3Client::RunFrame(CSteam3Client *this)

{
  SteamAPI_RunCallbacks();
  return;
}


// CSteam3Client::Shutdown  @ 000ce930
/* DWARF original prototype: void Shutdown(CSteam3Client * this) */

void __thiscall CSteam3Client::Shutdown(CSteam3Client *this)

{
  if ((this->super_CSteam3).m_bLoggedOn != false) {
    SteamAPI_Shutdown();
    (this->super_CSteam3).m_bLoggedOn = false;
  }
  return;
}


// CSteam3Client::TerminateConnection  @ 000cfdb0
/* DWARF original prototype: void TerminateConnection(CSteam3Client * this, uint32 unIPServer,
   uint16 usPortServer) */

void __thiscall
CSteam3Client::TerminateConnection(CSteam3Client *this,uint32 unIPServer,uint16 usPortServer)

{
  int *piVar1;
  
  piVar1 = (int *)SteamUser();
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
                    /* WARNING: Could not recover jumptable at 0x000cfdee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x10))();
  return;
}


// CSteam3Client::~CSteam3Client  @ 000d0980
/* DWARF original prototype: void ~CSteam3Client(CSteam3Client * this, int __in_chrg) */

void __thiscall CSteam3Client::~CSteam3Client(CSteam3Client *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->m_CallbackGameOverlayActivated).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Client_000eda90;
  (this->m_CallbackGameOverlayActivated).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edb50;
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackGameServerChangeRequested).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGameServerChangeRequested).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb68;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackGameOverlayActivated);
    bVar1 = (this->m_CallbackGameServerChangeRequested).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGameServerChangeRequested).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb68;
  }
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackClientGameServerDeny).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackClientGameServerDeny).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb80;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackGameServerChangeRequested);
    bVar1 = (this->m_CallbackClientGameServerDeny).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackClientGameServerDeny).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb80;
  }
  if ((bVar1 & 1) == 0) {
    (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3_000edb38;
    return;
  }
  SteamAPI_UnregisterCallback(&this->m_CallbackClientGameServerDeny);
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3_000edb38;
  return;
}


// CSteam3Client::~CSteam3Client  @ 000d0b30
/* DWARF original prototype: void ~CSteam3Client(CSteam3Client * this, int __in_chrg) */

void __thiscall CSteam3Client::~CSteam3Client(CSteam3Client *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->m_CallbackGameOverlayActivated).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Client_000eda90;
  (this->m_CallbackGameOverlayActivated).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edb50;
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackGameServerChangeRequested).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGameServerChangeRequested).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb68;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackGameOverlayActivated);
    bVar1 = (this->m_CallbackGameServerChangeRequested).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGameServerChangeRequested).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb68;
  }
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackClientGameServerDeny).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackClientGameServerDeny).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb80;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackGameServerChangeRequested);
    bVar1 = (this->m_CallbackClientGameServerDeny).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackClientGameServerDeny).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb80;
  }
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackClientGameServerDeny);
  }
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3_000edb38;
  operator_delete(this);
  return;
}


// CSteam3Server::Activate  @ 000cf880
/* DWARF original prototype: void Activate(CSteam3Server * this) */

void __thiscall CSteam3Server::Activate(CSteam3Server *this)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  FILE *__stream;
  byte bVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  undefined1 uVar11;
  bool bVar12;
  bool bVar13;
  undefined1 uVar14;
  bool bVar15;
  byte bVar16;
  uint local_134;
  uint local_130;
  char local_120 [272];
  
  bVar16 = 0;
                    /* Unresolved local var: uint32 unIP@[???]
                       Unresolved local var: uint16 usPort@[???]
                       Unresolved local var: int iPort@[???]
                       Unresolved local var: uint32 unFlags@[???]
                       Unresolved local var: char[260] gamedir@[???]
                       Unresolved local var: EServerMode eSMode@[???]
                       Unresolved local var: int uPort@[???]
                       Unresolved local var: int nAppID@[???]
                       Unresolved local var: double fMasterHeartbeatTimeout@[???]
                       Unresolved local var: bool iHasPW@[???] */
  if ((this->super_CSteam3).m_bLoggedOn == false) {
    (this->super_CSteam3).m_bLoggedOn = true;
    iVar3 = COM_CheckParm("-sport");
    local_130 = 0x6914;
    if (0 < iVar3) {
      local_130 = strtol(com_argv[iVar3 + 1],(char **)0x0,10);
      local_130 = local_130 & 0xffff;
    }
    local_134 = 0;
    if (net_local_adr.type == NA_IP) {
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
      local_134 = (uint)net_local_adr.ip >> 0x18 | ((uint)net_local_adr.ip & 0xff0000) >> 8 |
                  ((uint)net_local_adr.ip & 0xff00) << 8 | (int)net_local_adr.ip << 0x18;
    }
    this->m_bLanOnly = 0.0 < sv_lan.value;
    iVar3 = COM_CheckParm("-insecure");
    pcVar6 = sv_password.string;
    bVar7 = false;
    if (iVar3 == 0) {
      bVar7 = this->m_bLanOnly ^ 1;
    }
    this->m_bWantToBeSecure = (bool)bVar7;
    Q_strlen(pcVar6);
    COM_FileBase(com_gamedir,local_120);
    uVar9 = (uint)iphostport.value;
    iVar3 = 3 - (uint)(this->m_bWantToBeSecure == false);
    if (this->m_bLanOnly != false) {
      iVar3 = 1;
    }
    if (uVar9 == 0) {
      uVar9 = (uint)hostport.value;
    }
    iVar4 = GetGameAppID();
                    /* Unresolved local var: FILE * f@[???] */
    if (((0 < iVar4) && (cls.state == ca_dedicated)) &&
       (__stream = fopen("steam_appid.txt","w+"), __stream != (FILE *)0x0)) {
      fprintf(__stream,"%d\n",iVar4);
      fclose(__stream);
    }
    cVar2 = SteamGameServer_Init(local_134,local_130,uVar9 & 0xffff,0xffff,iVar3,gpszVersionString);
    if (cVar2 == '\0') {
      Sys_Error("Unable to initialize Steam.");
    }
    else {
      piVar5 = (int *)SteamGameServer();
      (**(code **)(*piVar5 + 4))(piVar5,gpszProductString);
      piVar5 = (int *)SteamGameServer();
      (**(code **)(*piVar5 + 0xc))(piVar5,local_120);
      piVar5 = (int *)SteamGameServer();
      (**(code **)(*piVar5 + 0x10))(piVar5,cls.state == ca_dedicated);
      piVar5 = (int *)SteamGameServer();
      pcVar1 = *(code **)(*piVar5 + 8);
      pcVar6 = (*gEntityInterface.pfnGetGameDescription)();
      (*pcVar1)(piVar5,pcVar6);
      piVar5 = (int *)SteamGameServer();
      (**(code **)(*piVar5 + 0x18))(piVar5);
      (this->super_CSteam3).m_bLogOnResult = false;
      iVar3 = COM_CheckParm("-nomaster");
      if (iVar3 == 0) {
        if (gfNoMasterServer == false) {
          uVar11 = svs.maxclients == 0;
          uVar14 = svs.maxclients == 1;
          if (1 < svs.maxclients) {
            piVar5 = (int *)SteamGameServer();
            (**(code **)(*piVar5 + 0x9c))(piVar5,1);
            iVar3 = 4;
            pbVar8 = (byte *)com_gamedir;
            pbVar10 = &DAT_000e7958;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              uVar11 = *pbVar8 < *pbVar10;
              uVar14 = *pbVar8 == *pbVar10;
              pbVar8 = pbVar8 + (uint)bVar16 * -2 + 1;
              pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
            } while ((bool)uVar14);
            iVar3 = 0x96;
            bVar12 = (!(bool)uVar11 && !(bool)uVar14) < (byte)uVar11;
            bVar15 = (!(bool)uVar11 && !(bool)uVar14) == (bool)uVar11;
            if (!bVar15) {
              iVar3 = 4;
              pbVar8 = (byte *)com_gamedir;
              pbVar10 = &DAT_000e7954;
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar12 = *pbVar8 < *pbVar10;
                bVar15 = *pbVar8 == *pbVar10;
                pbVar8 = pbVar8 + (uint)bVar16 * -2 + 1;
                pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
              } while (bVar15);
              iVar3 = 400;
              bVar13 = (!bVar12 && !bVar15) < bVar12;
              bVar12 = (!bVar12 && !bVar15) == bVar12;
              if (!bVar12) {
                iVar3 = 8;
                pbVar8 = (byte *)com_gamedir;
                pbVar10 = (byte *)"cstrike";
                do {
                  if (iVar3 == 0) break;
                  iVar3 = iVar3 + -1;
                  bVar13 = *pbVar8 < *pbVar10;
                  bVar12 = *pbVar8 == *pbVar10;
                  pbVar8 = pbVar8 + (uint)bVar16 * -2 + 1;
                  pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
                } while (bVar12);
                iVar3 = (-(uint)((!bVar13 && !bVar12) == bVar13) & 200) + 200;
              }
            }
            piVar5 = (int *)SteamGameServer();
            (**(code **)(*piVar5 + 0xa0))(piVar5,iVar3);
            if (*sv_password.string != '\0') {
              Q_stricmp(sv_password.string,"none");
            }
            NotifyOfLevelChange(this,true);
          }
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
    bVar12 = sv_lan.value != 0.0;
    if (this->m_bLanOnly != bVar12) {
      this->m_bLanOnly = bVar12;
      iVar3 = COM_CheckParm("-insecure");
      this->m_bWantToBeSecure = iVar3 == 0 && !bVar12;
    }
  }
  return;
}


// CSteam3Server::CSteam3Server  @ 000cef60
/* DWARF original prototype: void CSteam3Server(CSteam3Server * this) */

void __thiscall CSteam3Server::CSteam3Server(CSteam3Server *this)

{
  (this->super_CSteam3).m_bLoggedOn = false;
  (this->super_CSteam3).m_bLogOnResult = false;
  (this->super_CSteam3).m_hSteamPipe = 0;
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Server_000eda78;
  (this->m_CallbackGSClientApprove).super_CCallbackBase.m_iCallback = 0;
  (this->m_CallbackGSClientApprove).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edb20;
  (this->m_CallbackGSClientApprove).super_CCallbackBase.m_nCallbackFlags = '\x02';
  (this->m_CallbackGSClientApprove).m_pObj = this;
  (this->m_CallbackGSClientApprove).m_Func.__pfn = OnGSClientApprove;
  (this->m_CallbackGSClientApprove).m_Func.__delta = 0;
  SteamAPI_RegisterCallback(&this->m_CallbackGSClientApprove,0xc9);
  (this->m_CallbackGSClientDeny).super_CCallbackBase.m_iCallback = 0;
  (this->m_CallbackGSClientDeny).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edb08;
  (this->m_CallbackGSClientDeny).super_CCallbackBase.m_nCallbackFlags = '\x02';
  (this->m_CallbackGSClientDeny).m_pObj = this;
  (this->m_CallbackGSClientDeny).m_Func.__pfn = OnGSClientDeny;
  (this->m_CallbackGSClientDeny).m_Func.__delta = 0;
  SteamAPI_RegisterCallback(&this->m_CallbackGSClientDeny,0xca);
  (this->m_CallbackGSClientKick).super_CCallbackBase.m_iCallback = 0;
  (this->m_CallbackGSClientKick).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edaf0;
  (this->m_CallbackGSClientKick).super_CCallbackBase.m_nCallbackFlags = '\x02';
  (this->m_CallbackGSClientKick).m_pObj = this;
  (this->m_CallbackGSClientKick).m_Func.__pfn = OnGSClientKick;
  (this->m_CallbackGSClientKick).m_Func.__delta = 0;
  SteamAPI_RegisterCallback(&this->m_CallbackGSClientKick,0xcb);
  (this->m_CallbackGSPolicyResponse).super_CCallbackBase.m_iCallback = 0;
  (this->m_CallbackGSPolicyResponse).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edad8;
  (this->m_CallbackGSPolicyResponse).super_CCallbackBase.m_nCallbackFlags = '\x02';
  (this->m_CallbackGSPolicyResponse).m_pObj = this;
  (this->m_CallbackGSPolicyResponse).m_Func.__pfn = OnGSPolicyResponse;
  (this->m_CallbackGSPolicyResponse).m_Func.__delta = 0;
  SteamAPI_RegisterCallback(&this->m_CallbackGSPolicyResponse,0x73);
  (this->m_CallbackLogonSuccess).m_Func.__delta = 0;
  (this->m_CallbackLogonSuccess).super_CCallbackBase.m_iCallback = 0;
  (this->m_CallbackLogonSuccess).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edac0;
  (this->m_CallbackLogonSuccess).super_CCallbackBase.m_nCallbackFlags = '\x02';
  (this->m_CallbackLogonSuccess).m_pObj = this;
  (this->m_CallbackLogonSuccess).m_Func.__pfn = OnLogonSuccess;
  SteamAPI_RegisterCallback(&this->m_CallbackLogonSuccess,0x65);
  (this->m_CallbackLogonFailure).m_Func.__pfn = OnLogonFailure;
  (this->m_CallbackLogonFailure).m_Func.__delta = 0;
  (this->m_CallbackLogonFailure).super_CCallbackBase.m_iCallback = 0;
  (this->m_CallbackLogonFailure).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edaa8;
  (this->m_CallbackLogonFailure).super_CCallbackBase.m_nCallbackFlags = '\x02';
  (this->m_CallbackLogonFailure).m_pObj = this;
  SteamAPI_RegisterCallback(&this->m_CallbackLogonFailure,0x66);
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


// CSteam3Server::ClientFindFromSteamID  @ 000ceef0
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


// CSteam3Server::GetSteamID  @ 000ceb80
/* DWARF original prototype: uint64 GetSteamID(CSteam3Server * this) */

uint64 __thiscall CSteam3Server::GetSteamID(CSteam3Server *this)

{
  if (this->m_bLanOnly != false) {
    return 0x100000000000000;
  }
  return (this->m_SteamIDGS).m_steamid.m_unAll64Bits;
}


// CSteam3Server::NotifyBotConnect  @ 000cf290
/* DWARF original prototype: bool NotifyBotConnect(CSteam3Server * this, client_t.conflict * client)
    */

bool __thiscall CSteam3Server::NotifyBotConnect(CSteam3Server *this,client_t_conflict *client)

{
  bool bVar1;
  int *piVar2;
  undefined4 local_18;
  undefined4 local_14 [4];
  
  bVar1 = false;
  if ((client != (client_t_conflict *)0x0) && ((this->super_CSteam3).m_bLoggedOn != false)) {
    (client->network_userid).idtype = 3;
    piVar2 = (int *)SteamGameServer();
    (**(code **)(*piVar2 + 100))(local_14,piVar2);
    *(undefined4 *)&(client->network_userid).m_SteamID = local_18;
    bVar1 = true;
    *(undefined4 *)((int)&(client->network_userid).m_SteamID + 4) = local_14[0];
  }
  return bVar1;
}


// CSteam3Server::NotifyClientConnect  @ 000cf120
/* DWARF original prototype: bool NotifyClientConnect(CSteam3Server * this, client_t.conflict *
   client, void * pvSteam2Key, uint32 ucbSteam2Key) */

bool __thiscall
CSteam3Server::NotifyClientConnect
          (CSteam3Server *this,client_t_conflict *client,void *pvSteam2Key,uint32 ucbSteam2Key)

{
  uint uVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: CSteamID steamIDClient@[???]
                       Unresolved local var: bool bRet@[???] */
  uVar2 = 0;
  if ((client != (client_t_conflict *)0x0) && ((this->super_CSteam3).m_bLoggedOn != false)) {
    (client->network_userid).idtype = 1;
    local_14 = 0;
    local_10 = 0;
    piVar3 = (int *)SteamGameServer();
                    /* Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
    uVar1 = (client->network_userid).clientip;
    uVar2 = (**(code **)(*piVar3 + 0x60))
                      (piVar3,uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                              uVar1 << 0x18,pvSteam2Key,ucbSteam2Key,&local_14);
    *(undefined4 *)&(client->network_userid).m_SteamID = local_14;
    *(undefined4 *)((int)&(client->network_userid).m_SteamID + 4) = local_10;
  }
  return (bool)uVar2;
}


// CSteam3Server::NotifyClientDisconnect  @ 000cf2f0
/* DWARF original prototype: void NotifyClientDisconnect(CSteam3Server * this, client_t.conflict *
   cl) */

void __thiscall CSteam3Server::NotifyClientDisconnect(CSteam3Server *this,client_t_conflict *cl)

{
  int iVar1;
  int *piVar2;
  
  if (((cl != (client_t_conflict *)0x0) && ((this->super_CSteam3).m_bLoggedOn != false)) &&
     ((iVar1 = (cl->network_userid).idtype, iVar1 == 3 || (iVar1 == 1)))) {
    piVar2 = (int *)SteamGameServer();
    (**(code **)(*piVar2 + 0x68))
              (piVar2,(int)(cl->network_userid).m_SteamID,
               *(undefined4 *)((int)&(cl->network_userid).m_SteamID + 4));
    return;
  }
  return;
}


// CSteam3Server::NotifyOfLevelChange  @ 000cf7a0
/* DWARF original prototype: void NotifyOfLevelChange(CSteam3Server * this, bool bForce) */

void __thiscall CSteam3Server::NotifyOfLevelChange(CSteam3Server *this,bool bForce)

{
  cvar_s *pcVar1;
  int *piVar2;
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
  piVar2 = (int *)SteamGameServer();
  (**(code **)(*piVar2 + 0x40))(piVar2,bVar5);
  piVar2 = (int *)SteamGameServer();
  (**(code **)(*piVar2 + 0x4c))(piVar2);
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
          if (iVar3 != 0) goto LAB_000cf7f3;
        }
        pcVar4 = "0";
      }
LAB_000cf7f3:
      piVar2 = (int *)SteamGameServer();
      (**(code **)(*piVar2 + 0x50))(piVar2,pcVar1->name,pcVar4);
    }
    pcVar1 = pcVar1->next;
  } while( true );
}


// CSteam3Server::OnGSClientApprove  @ 000ce990
/* DWARF original prototype: void OnGSClientApprove(CSteam3Server * this, GSClientApprove_t *
   pGSClientSteam2Accept) */

void __thiscall
CSteam3Server::OnGSClientApprove(CSteam3Server *this,GSClientApprove_t *pGSClientSteam2Accept)

{
  int iVar1;
  qboolean qVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  client_s *client;
  char local_20c [4];
  char acStack_208 [508];
  
                    /* Unresolved local var: client_t.conflict * cl@[DW_OP_reg3(EBX)]
                       Unresolved local var: client_t.conflict * cl@[???]
                       Unresolved local var: int i@[???] */
  if (0 < svs.maxclients) {
    iVar1 = 0;
    client = svs.clients;
    do {
      if ((((client->connected != false) || (client->active != false)) || (client->spawned != false)
          ) && (((client->network_userid).idtype == 1 &&
                (*(int *)((int)&(client->network_userid).m_SteamID + 4) ==
                 *(int *)((int)&(pGSClientSteam2Accept->m_SteamID).m_steamid + 4) &&
                 (uint32)(client->network_userid).m_SteamID ==
                 (pGSClientSteam2Accept->m_SteamID).m_steamid.m_comp.m_unAccountID)))) {
        if (client == (client_t *)0x0) {
          return;
        }
        qVar2 = SV_FilterUser(&client->network_userid);
        if (qVar2 == false) {
          iVar1 = SV_CheckForDuplicateSteamID(client);
          if (iVar1 != -1) {
                    /* Unresolved local var: char[256] msg@[???] */
            uVar4 = 0;
            do {
              uVar3 = uVar4;
              *(undefined4 *)(local_20c + uVar3) =
                   *(undefined4 *)("Your UserID is already in use on this server.\n" + uVar3);
              uVar4 = uVar3 + 4;
            } while (uVar4 < 0x2c);
            *(short *)(local_20c + uVar4) =
                 (short)*(undefined4 *)
                         ("Your UserID is already in use on this server.\n" + uVar3 + 4);
            acStack_208[uVar3 + 2] = "Your UserID is already in use on this server.\n"[uVar3 + 6];
            SV_RejectConnection(&(client->netchan).remote_address,local_20c);
            pcVar5 = SV_GetClientIDString(client);
            SV_DropClient(client,false,"STEAM UserID %s is already\nin use on this server\n",pcVar5)
            ;
            return;
          }
                    /* Unresolved local var: char[512] msg@[???] */
          pcVar5 = SV_GetClientIDString(client);
          snprintf(local_20c,0x200,"\"%s<%i><%s><>\" STEAM USERID validated\n",client->name,
                   client->userid,pcVar5);
          Con_DPrintf("%s",local_20c);
          Log_Printf("%s",local_20c);
          return;
        }
                    /* Unresolved local var: char[256] msg@[???] */
        uVar4 = 0;
        do {
          uVar3 = uVar4;
          *(undefined4 *)(local_20c + uVar3) =
               *(undefined4 *)("You have been banned from this server\n" + uVar3);
          uVar4 = uVar3 + 4;
        } while (uVar4 < 0x24);
        *(short *)(local_20c + uVar4) =
             (short)*(undefined4 *)("You have been banned from this server\n" + uVar3 + 4);
        acStack_208[uVar3 + 2] = "You have been banned from this server\n"[uVar3 + 6];
        SV_RejectConnection(&(client->netchan).remote_address,local_20c);
        pcVar5 = SV_GetClientIDString(client);
        SV_DropClient(client,false,"STEAM UserID %s is in server ban list\n",pcVar5);
        return;
      }
      iVar1 = iVar1 + 1;
      client = client + 1;
    } while (iVar1 != svs.maxclients);
  }
  return;
}


// CSteam3Server::OnGSClientDeny  @ 000cee60
/* DWARF original prototype: void OnGSClientDeny(CSteam3Server * this, GSClientDeny_t *
   pGSClientDeny) */

void __thiscall CSteam3Server::OnGSClientDeny(CSteam3Server *this,GSClientDeny_t *pGSClientDeny)

{
  client_s *cl;
  int iVar1;
  
                    /* Unresolved local var: client_t.conflict * cl@[DW_OP_reg0(EAX)]
                       Unresolved local var: client_t.conflict * cl@[???]
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
    } while (iVar1 != svs.maxclients);
  }
  return;
}


// CSteam3Server::OnGSClientDenyHelper  @ 000cebb0
/* DWARF original prototype: void OnGSClientDenyHelper(CSteam3Server * this, client_t.conflict * cl,
   EDenyReason eDenyReason, char * pchOptionalText) */

void __thiscall
CSteam3Server::OnGSClientDenyHelper
          (CSteam3Server *this,client_t_conflict *cl,EDenyReason eDenyReason,char *pchOptionalText)

{
  switch(eDenyReason) {
  case k_EDenyInvalidVersion:
    SV_DropClient((client_t *)cl,false,
                  "Client version incompatible with server. \nPlease exit and restart");
    return;
  case k_EDenyNotLoggedOn:
    if (this->m_bLanOnly == false) {
      SV_DropClient((client_t *)cl,false,"No Steam logon\n");
      return;
    }
    break;
  case k_EDenyNoLicense:
    SV_DropClient((client_t *)cl,false,
                  "This Steam account does not own this game. \nPlease login to the correct Steam account."
                 );
    return;
  case k_EDenyCheater:
    SV_DropClient((client_t *)cl,false,"VAC banned from secure server\n");
    return;
  case k_EDenyLoggedInElseWhere:
    if (this->m_bLanOnly == false) {
      SV_DropClient((client_t *)cl,false,"This Steam account is being used in another location\n");
      return;
    }
    break;
  case k_EDenyUnknownText:
    if ((pchOptionalText != (char *)0x0) && (*pchOptionalText != '\0')) {
      SV_DropClient((client_t *)cl,false,pchOptionalText);
      return;
    }
  default:
    SV_DropClient((client_t *)cl,false,"Client dropped by server");
    return;
  case k_EDenyIncompatibleAnticheat:
    SV_DropClient((client_t *)cl,false,
                  "You are running an external tool that is incompatible with Secure servers.");
    return;
  case k_EDenyMemoryCorruption:
    SV_DropClient((client_t *)cl,false,"Memory corruption detected.");
    return;
  case k_EDenyIncompatibleSoftware:
    SV_DropClient((client_t *)cl,false,
                  "You are running software that is not compatible with Secure servers.");
    return;
  case k_EDenySteamConnectionLost:
    if (this->m_bLanOnly == false) {
      SV_DropClient((client_t *)cl,false,"Steam connection lost\n");
      return;
    }
    break;
  case k_EDenySteamConnectionError:
    if (this->m_bLanOnly == false) {
      SV_DropClient((client_t *)cl,false,"Unable to connect to Steam\n");
      return;
    }
    break;
  case k_EDenySteamResponseTimedOut:
    SV_DropClient((client_t *)cl,false,
                  "Client timed out while answering challenge.\n---> Please make sure that you have opened the appropriate ports on any firewall you are connected behind.\n---> See http://support.steampowered.com for help with firewall configuration."
                 );
    return;
  case k_EDenySteamValidationStalled:
    if (this->m_bLanOnly != false) {
      *(undefined4 *)&(cl->network_userid).m_SteamID = 1;
      *(undefined4 *)((int)&(cl->network_userid).m_SteamID + 4) = 0;
    }
  }
  return;
}


// CSteam3Server::OnGSClientKick  @ 000cedd0
/* DWARF original prototype: void OnGSClientKick(CSteam3Server * this, GSClientKick_t *
   pGSClientKick) */

void __thiscall CSteam3Server::OnGSClientKick(CSteam3Server *this,GSClientKick_t *pGSClientKick)

{
  client_s *cl;
  int iVar1;
  
                    /* Unresolved local var: client_t.conflict * cl@[DW_OP_reg0(EAX)]
                       Unresolved local var: client_t.conflict * cl@[???]
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
    } while (iVar1 != svs.maxclients);
  }
  return;
}


// CSteam3Server::OnGSPolicyResponse  @ 000ce8d0
/* DWARF original prototype: void OnGSPolicyResponse(CSteam3Server * this, GSPolicyResponse_t *
   pPolicyResponse) */

void __thiscall
CSteam3Server::OnGSPolicyResponse(CSteam3Server *this,GSPolicyResponse_t *pPolicyResponse)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)SteamGameServer();
  cVar1 = (**(code **)(*piVar2 + 0x24))(piVar2);
  if (cVar1 == '\0') {
    Con_Printf("   VAC secure mode disabled.\n");
    return;
  }
  Con_Printf("   VAC secure mode is activated.\n");
  return;
}


// CSteam3Server::OnLogonFailure  @ 000ce850
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


// CSteam3Server::OnLogonSuccess  @ 000cfc80
/* DWARF original prototype: void OnLogonSuccess(CSteam3Server * this, SteamServersConnected_t *
   pLogonSuccess) */

void __thiscall
CSteam3Server::OnLogonSuccess(CSteam3Server *this,SteamServersConnected_t *pLogonSuccess)

{
  bool bVar1;
  int *piVar2;
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
  piVar2 = (int *)SteamGameServer();
  (**(code **)(*piVar2 + 0x28))(local_14,piVar2);
  (this->m_SteamIDGS).m_steamid.m_comp.m_unAccountID = local_18;
  *(undefined4 *)((int)&(this->m_SteamIDGS).m_steamid + 4) = local_14[0];
  SendUpdatedServerDetails(this);
  return;
}


// CSteam3Server::RunFrame  @ 000cf410
/* DWARF original prototype: void RunFrame(CSteam3Server * this) */

void __thiscall CSteam3Server::RunFrame(CSteam3Server *this)

{
  netadr_t to;
  client_s *pcVar1;
  char cVar2;
  client_s *pcVar3;
  int *piVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  double dVar10;
  undefined4 uVar11;
  undefined4 local_105c;
  undefined1 local_1038 [4096];
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  ushort local_1e [7];
  
                    /* Unresolved local var: double fCurTime@[???] */
  if (1 < svs.maxclients) {
    dVar10 = Sys_FloatTime();
    if (1.0 < dVar10 - RunFrame::lexical_block_0::s_fLastRunFragsUpdate) {
                    /* Unresolved local var: bool bHasPlayers@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int maxplayers@[???]
                       Unresolved local var: bool iHasPW@[???] */
      bVar9 = false;
      if (0 < svs.maxclients) {
        bVar9 = true;
        if ((((svs.clients)->active == false) && ((svs.clients)->spawned == false)) &&
           ((svs.clients)->connected == false)) {
          iVar6 = 0;
          pcVar3 = svs.clients;
          do {
            iVar6 = iVar6 + 1;
            if (iVar6 == svs.maxclients) {
              bVar9 = false;
              goto LAB_000cf4bb;
            }
          } while (((pcVar3[1].active == false) && (pcVar3[1].spawned == false)) &&
                  (pcVar1 = pcVar3 + 1, pcVar3 = pcVar3 + 1, pcVar1->connected == false));
          bVar9 = true;
        }
      }
LAB_000cf4bb:
      RunFrame::lexical_block_0::s_fLastRunFragsUpdate = dVar10;
      this->m_bHasActivePlayers = bVar9;
      bVar9 = false;
      SendUpdatedServerDetails(this);
      if (*sv_password.string != '\0') {
        iVar6 = Q_stricmp(sv_password.string,"none");
        bVar9 = iVar6 != 0;
      }
      piVar4 = (int *)SteamGameServer();
      (**(code **)(*piVar4 + 0x40))(piVar4,bVar9);
      if (0 < svs.maxclients) {
        iVar8 = 0;
        iVar6 = svs.maxclients;
        iVar7 = 0;
        do {
          while (*(int *)(((svs.clients)->netchan).remote_address.ip + iVar7 + -0x24) != 0) {
            piVar4 = (int *)SteamGameServer();
            iVar8 = iVar8 + 1;
            local_105c = (undefined4)
                         (longlong)
                         ROUND(*(float *)(*(int *)((svs.clients)->userinfo + iVar7 + -0x1c) + 0x1e4)
                              );
            (**(code **)(*piVar4 + 0x6c))
                      (piVar4,*(undefined4 *)((svs.clients)->userinfo + iVar7 + -0xc),
                       *(undefined4 *)((svs.clients)->userinfo + iVar7 + -8),
                       (svs.clients)->name + iVar7,local_105c);
            iVar6 = svs.maxclients;
            iVar7 = iVar7 + 0x4ef8;
            if (svs.maxclients <= iVar8) goto LAB_000cf598;
          }
          iVar8 = iVar8 + 1;
          iVar7 = iVar7 + 0x4ef8;
        } while (iVar8 < iVar6);
      }
LAB_000cf598:
      piVar4 = (int *)SteamGameServer();
      cVar2 = (**(code **)(*piVar4 + 0x2c))(piVar4);
      if (cVar2 != '\0') {
        uVar11 = 3;
        Con_Printf("%cMasterRequestRestart\n",3);
        iVar6 = COM_CheckParm("-autoupdate");
        if (iVar6 == 0) {
          Con_Printf("Your server needs to be restarted in order to receive the latest update.\n",
                     uVar11);
          Log_Printf("Your server needs to be restarted in order to receive the latest update.\n");
        }
        else {
          Con_Printf("Your server will be restarted on map change.\n",uVar11);
          Log_Printf("Your server will be restarted on map change.\n");
          g_bOutOfDateRestart = true;
        }
      }
    }
    if (0.1 < dVar10 - RunFrame::lexical_block_0::s_fLastRunCallback) {
      SteamGameServer_RunCallbacks();
      RunFrame::lexical_block_0::s_fLastRunCallback = dVar10;
    }
    if (0.01 < dVar10 - RunFrame::lexical_block_0::s_fLastRunSendPackets) {
                    /* Unresolved local var: uint16 port@[???]
                       Unresolved local var: uint32 ip@[???]
                       Unresolved local var: char[4096] szOutBuf@[???]
                       Unresolved local var: int iLen@[???] */
      RunFrame::lexical_block_0::s_fLastRunSendPackets = dVar10;
      piVar4 = (int *)SteamGameServer();
      iVar6 = *piVar4;
      while( true ) {
        iVar6 = (**(code **)(iVar6 + 0x98))(piVar4,local_1038,0x1000,&local_24,local_1e);
        if (iVar6 < 1) break;
                    /* Unresolved local var: netadr_t.conflict netAdr@[???]
                       Unresolved local var: uint __v@[???]
                       Unresolved local var: uint __x@[???] */
        local_34 = local_24 >> 0x18 | (local_24 & 0xff0000) >> 8 | (local_24 & 0xff00) << 8 |
                   local_24 << 0x18;
                    /* Unresolved local var: ushort __v@[???]
                       Unresolved local var: ushort __x@[???] */
        uVar5 = local_1e[0] >> 8 | local_1e[0] << 8;
        local_28 = CONCAT22(uVar5,(undefined2)local_28);
        uVar11 = local_28;
        local_38 = 3;
        to.ip[0] = (char)local_34;
        to.ip[1] = (char)(local_34 >> 8);
        to.ip[2] = (char)(local_34 >> 0x10);
        to.ip[3] = (char)(local_34 >> 0x18);
        to.type = 3;
        to.ipx[0] = (undefined1)local_30;
        to.ipx[1] = local_30._1_1_;
        to.ipx[2] = local_30._2_1_;
        to.ipx[3] = local_30._3_1_;
        to.ipx[4] = (undefined1)local_2c;
        to.ipx[5] = local_2c._1_1_;
        to.ipx[6] = local_2c._2_1_;
        to.ipx[7] = local_2c._3_1_;
        to.ipx[8] = (undefined1)local_28;
        to.ipx[9] = local_28._1_1_;
        to.port = uVar5;
        local_28 = uVar11;
        local_24 = local_34;
        NET_SendPacket(NS_SERVER,iVar6,local_1038,to);
        piVar4 = (int *)SteamGameServer();
        iVar6 = *piVar4;
      }
      return;
    }
  }
  return;
}


// CSteam3Server::SendUpdatedServerDetails  @ 000cf350
/* DWARF original prototype: void SendUpdatedServerDetails(CSteam3Server * this) */

void __thiscall CSteam3Server::SendUpdatedServerDetails(CSteam3Server *this)

{
  code *pcVar1;
  client_s *pcVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: int bot@[???]
                       Unresolved local var: int maxplayers@[???]
                       Unresolved local var: int i@[???] */
  iVar6 = 0;
  if (0 < svs.maxclients) {
    iVar5 = 0;
    pcVar2 = svs.clients;
    do {
      if (((pcVar2->active != false) || (pcVar2->spawned != false)) || (pcVar2->connected != false))
      {
        iVar6 = (iVar6 + 1) - (uint)(pcVar2->fakeclient == false);
      }
      iVar5 = iVar5 + 1;
      pcVar2 = pcVar2 + 1;
    } while (iVar5 != svs.maxclients);
  }
  iVar5 = (int)sv_visiblemaxplayers.value;
  if ((int)sv_visiblemaxplayers.value < 0) {
    iVar5 = svs.maxclients;
  }
  piVar3 = (int *)SteamGameServer();
  (**(code **)(*piVar3 + 0x30))(piVar3,iVar5);
  piVar3 = (int *)SteamGameServer();
  (**(code **)(*piVar3 + 0x34))(piVar3,iVar6);
  piVar3 = (int *)SteamGameServer();
  pcVar1 = *(code **)(*piVar3 + 0x38);
  pcVar4 = Cvar_VariableString("hostname");
  (*pcVar1)(piVar3,pcVar4);
  piVar3 = (int *)SteamGameServer();
  (**(code **)(*piVar3 + 0x3c))(piVar3,0x506a28);
  return;
}


// CSteam3Server::Shutdown  @ 000ce950
/* DWARF original prototype: void Shutdown(CSteam3Server * this) */

void __thiscall CSteam3Server::Shutdown(CSteam3Server *this)

{
  int *piVar1;
  
  if ((this->super_CSteam3).m_bLoggedOn != false) {
    piVar1 = (int *)SteamGameServer();
    (**(code **)(*piVar1 + 0x9c))(piVar1,0);
    piVar1 = (int *)SteamGameServer();
    (**(code **)(*piVar1 + 0x1c))(piVar1);
    SteamGameServer_Shutdown();
    (this->super_CSteam3).m_bLoggedOn = false;
  }
  return;
}


// CSteam3Server::~CSteam3Server  @ 000d0a10
/* DWARF original prototype: void ~CSteam3Server(CSteam3Server * this, int __in_chrg) */

void __thiscall CSteam3Server::~CSteam3Server(CSteam3Server *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->m_CallbackLogonFailure).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Server_000eda78;
  (this->m_CallbackLogonFailure).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edaa8;
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackLogonSuccess).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackLogonSuccess).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edac0;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackLogonFailure);
    bVar1 = (this->m_CallbackLogonSuccess).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackLogonSuccess).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edac0;
  }
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackGSPolicyResponse).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSPolicyResponse).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edad8;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackLogonSuccess);
    bVar1 = (this->m_CallbackGSPolicyResponse).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSPolicyResponse).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edad8;
  }
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackGSClientKick).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientKick).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edaf0;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSPolicyResponse);
    bVar1 = (this->m_CallbackGSClientKick).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientKick).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edaf0;
  }
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackGSClientDeny).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientDeny).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb08;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSClientKick);
    bVar1 = (this->m_CallbackGSClientDeny).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientDeny).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb08;
  }
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackGSClientApprove).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientApprove).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb20;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSClientDeny);
    bVar1 = (this->m_CallbackGSClientApprove).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientApprove).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb20;
  }
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSClientApprove);
    (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3_000edb38;
    return;
  }
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3_000edb38;
  return;
}


// CSteam3Server::~CSteam3Server  @ 000d0bc0
/* DWARF original prototype: void ~CSteam3Server(CSteam3Server * this, int __in_chrg) */

void __thiscall CSteam3Server::~CSteam3Server(CSteam3Server *this,int __in_chrg)

{
  byte bVar1;
  
  bVar1 = (this->m_CallbackLogonFailure).super_CCallbackBase.m_nCallbackFlags;
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3Server_000eda78;
  (this->m_CallbackLogonFailure).super_CCallbackBase._vptr_CCallbackBase =
       (_func_int_varargs **)&PTR_Run_000edaa8;
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackLogonSuccess).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackLogonSuccess).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edac0;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackLogonFailure);
    bVar1 = (this->m_CallbackLogonSuccess).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackLogonSuccess).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edac0;
  }
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackGSPolicyResponse).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSPolicyResponse).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edad8;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackLogonSuccess);
    bVar1 = (this->m_CallbackGSPolicyResponse).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSPolicyResponse).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edad8;
  }
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackGSClientKick).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientKick).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edaf0;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSPolicyResponse);
    bVar1 = (this->m_CallbackGSClientKick).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientKick).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edaf0;
  }
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackGSClientDeny).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientDeny).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb08;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSClientKick);
    bVar1 = (this->m_CallbackGSClientDeny).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientDeny).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb08;
  }
  if ((bVar1 & 1) == 0) {
    bVar1 = (this->m_CallbackGSClientApprove).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientApprove).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb20;
  }
  else {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSClientDeny);
    bVar1 = (this->m_CallbackGSClientApprove).super_CCallbackBase.m_nCallbackFlags;
    (this->m_CallbackGSClientApprove).super_CCallbackBase._vptr_CCallbackBase =
         (_func_int_varargs **)&PTR_Run_000edb20;
  }
  if ((bVar1 & 1) != 0) {
    SteamAPI_UnregisterCallback(&this->m_CallbackGSClientApprove);
  }
  (this->super_CSteam3)._vptr_CSteam3 = (_func_int_varargs **)&PTR__CSteam3_000edb38;
  operator_delete(this);
  return;
}


// CSteamID::BValidExternalSteamID  @ 000d4920
/* DWARF original prototype: bool BValidExternalSteamID(CSteamID * this) */

bool __thiscall CSteamID::BValidExternalSteamID(CSteamID *this)

{
  bool bVar1;
  byte bVar2;
  
  bVar1 = false;
  bVar2 = *(byte *)((int)&this->m_steamid + 6) & 0xf0;
  if ((((bVar2 != 0x50) && (bVar1 = true, bVar2 != 0x60)) && (bVar2 != 0x40)) &&
     ((bVar2 != 0xa0 && ((this->m_steamid).m_comp.m_unAccountID == 0)))) {
    return (*(byte *)((int)&this->m_steamid + 6) & 0xf) != 0 ||
           *(short *)((int)&this->m_steamid + 4) != 0;
  }
  return bVar1;
}


// CSteamID::CSteamID  @ 000d4110
/* DWARF original prototype: void CSteamID(CSteamID * this, char * pchSteamID, EUniverse
   eDefaultUniverse) */

void __thiscall CSteamID::CSteamID(CSteamID *this,char *pchSteamID,EUniverse eDefaultUniverse)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  uint32 auStack_4c [4];
  undefined4 auStack_3c [4];
  EUniverse aEStack_2c [7];
  
  auStack_4c[0] = 0;
  auStack_3c[0] = 1;
  cVar1 = *pchSteamID;
  aEStack_2c[0] = eDefaultUniverse;
  if (cVar1 == '[') {
    cVar1 = pchSteamID[1];
    pchSteamID = pchSteamID + 1;
  }
  if (cVar1 == 'A') {
    if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
      pcVar2 = pchSteamID + 2;
    }
    else {
      pcVar2 = pchSteamID + 1;
    }
    pcVar3 = strchr(pcVar2,0x28);
    if (pcVar3 != (char *)0x0) {
      sscanf(pcVar3,"(%u)",auStack_3c);
    }
    pcVar3 = strchr(pcVar2,0x3a);
    if (pcVar3 == (char *)0x0) {
      sscanf(pcVar2,"%u",auStack_4c);
    }
    else if ((*pcVar3 == '\0') || (pcVar3 = strchr(pcVar3 + 1,0x3a), pcVar3 == (char *)0x0)) {
      sscanf(pcVar2,"%u:%u",aEStack_2c,auStack_4c);
    }
    else {
      sscanf(pcVar2,"%u:%u:%u",aEStack_2c,auStack_4c,auStack_3c);
    }
    if (auStack_4c[0] == 0) {
      (this->m_steamid).m_comp.m_unAccountID = 0;
      *(undefined1 *)((int)&this->m_steamid + 4) = 0;
      *(undefined1 *)((int)&this->m_steamid + 5) = 0;
      (this->m_steamid).m_comp.m_EUniverse = (byte)aEStack_2c[0];
      *(undefined1 *)((int)&this->m_steamid + 6) = 0x40;
      return;
    }
    (this->m_steamid).m_comp.m_unAccountID = auStack_4c[0];
    *(char *)((int)&this->m_steamid + 4) = (char)auStack_3c[0];
    (this->m_steamid).m_comp.m_EUniverse = (byte)aEStack_2c[0];
    *(char *)((int)&this->m_steamid + 5) = (char)((uint)auStack_3c[0] >> 8);
    *(byte *)((int)&this->m_steamid + 6) = (byte)((uint)auStack_3c[0] >> 0x10) & 0xf | 0x40;
    return;
  }
  if (cVar1 == 'G') {
    if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\x03';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\x03';
    }
  }
  else if (cVar1 == 'C') {
    if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\x06';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\x06';
    }
  }
  else if (cVar1 == 'g') {
    auStack_3c[0] = 0;
    if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
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
      auStack_3c[0] = 0x80000;
      cVar1 = pchSteamID[1];
    }
    else if (cVar1 == 'L') {
      auStack_3c[0] = 0x40000;
      cVar1 = pchSteamID[1];
    }
    else {
      if (cVar1 != 'T') {
        if (cVar1 == 'U') {
          if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
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
            if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
              pchSteamID = pchSteamID + 2;
              cVar4 = '\0';
            }
            else {
              pchSteamID = pchSteamID + 1;
              cVar4 = '\0';
            }
          }
        }
        goto LAB_000d3dc0;
      }
      cVar1 = pchSteamID[1];
      auStack_3c[0] = 0;
    }
    if ((cVar1 == ':') || (cVar1 == '-')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\b';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\b';
    }
  }
LAB_000d3dc0:
  pcVar2 = strchr(pchSteamID,0x3a);
  if (pcVar2 == (char *)0x0) {
    sscanf(pchSteamID,"%u",auStack_4c);
  }
  else {
    sscanf(pchSteamID + (*pchSteamID == '['),"%u:%u",aEStack_2c,auStack_4c);
    if (aEStack_2c[0] == k_EUniverseInvalid) {
      aEStack_2c[0] = eDefaultUniverse;
    }
  }
  (this->m_steamid).m_comp.m_EUniverse = (byte)aEStack_2c[0];
  *(char *)((int)&this->m_steamid + 4) = (char)auStack_3c[0];
  (this->m_steamid).m_comp.m_unAccountID = auStack_4c[0];
  *(char *)((int)&this->m_steamid + 5) = (char)((uint)auStack_3c[0] >> 8);
  *(byte *)((int)&this->m_steamid + 6) = cVar4 << 4 | (byte)((uint)auStack_3c[0] >> 0x10) & 0xf;
  return;
}


// CSteamID::Render  @ 000d4200
/* DWARF original prototype: char * Render(CSteamID * this) */

char * __thiscall CSteamID::Render(CSteamID *this)

{
  char (*__s) [37];
  uint32 uVar1;
  uint uVar2;
  byte bVar3;
  
                    /* Unresolved local var: int k_cBufLen@[???]
                       Unresolved local var: int k_cBufs@[???]
                       Unresolved local var: char * pchBuf@[???] */
  __s = Render::lexical_block_0::rgchBuf + Render::lexical_block_0::nBuf;
  Render::lexical_block_0::nBuf = (Render::lexical_block_0::nBuf + 1) % 4;
  bVar3 = *(byte *)((int)&this->m_steamid + 6) & 0xf0;
  if (bVar3 == 0x40) {
    snprintf(*__s,0x25,"[A:%u:%u:%u]",(uint)(this->m_steamid).m_comp.m_EUniverse,
             (this->m_steamid).m_comp.m_unAccountID,
             (*(byte *)((int)&this->m_steamid + 6) & 0xf) << 0x10 |
             (uint)*(ushort *)((int)&this->m_steamid + 4));
  }
  else if (bVar3 == 0x30) {
    snprintf(*__s,0x25,"[G:%u:%u]",(uint)(this->m_steamid).m_comp.m_EUniverse,
             (this->m_steamid).m_comp.m_unAccountID);
  }
  else if (bVar3 == 0x20) {
    snprintf(*__s,0x25,"[M:%u:%u:%u]",(uint)(this->m_steamid).m_comp.m_EUniverse,
             (this->m_steamid).m_comp.m_unAccountID,
             (*(byte *)((int)&this->m_steamid + 6) & 0xf) << 0x10 |
             (uint)*(ushort *)((int)&this->m_steamid + 4));
  }
  else if (bVar3 == 0x50) {
    snprintf(*__s,0x25,"[P:%u:%u]",(uint)(this->m_steamid).m_comp.m_EUniverse,
             (this->m_steamid).m_comp.m_unAccountID);
  }
  else if (bVar3 == 0x60) {
    snprintf(*__s,0x25,"[C:%u:%u]",(uint)(this->m_steamid).m_comp.m_EUniverse,
             (this->m_steamid).m_comp.m_unAccountID);
  }
  else if (bVar3 == 0x70) {
    snprintf(*__s,0x25,"[g:%u:%u]",(uint)(this->m_steamid).m_comp.m_EUniverse,
             (this->m_steamid).m_comp.m_unAccountID);
  }
  else if (bVar3 == 0x80) {
    bVar3 = *(byte *)((int)&this->m_steamid + 6);
    if ((bVar3 & 8) == 0) {
      uVar1 = (this->m_steamid).m_comp.m_unAccountID;
      uVar2 = (uint)(this->m_steamid).m_comp.m_EUniverse;
      if ((bVar3 & 4) == 0) {
        snprintf(*__s,0x25,"[T:%u:%u]",uVar2,uVar1);
      }
      else {
        snprintf(*__s,0x25,"[L:%u:%u]",uVar2,uVar1);
      }
    }
    else {
      snprintf(*__s,0x25,"[c:%u:%u]",(uint)(this->m_steamid).m_comp.m_EUniverse,
               (this->m_steamid).m_comp.m_unAccountID);
    }
  }
  else if (bVar3 == 0) {
    snprintf(*__s,0x25,"[I:%u:%u]",(uint)(this->m_steamid).m_comp.m_EUniverse,
             (this->m_steamid).m_comp.m_unAccountID);
  }
  else if (bVar3 == 0x10) {
    uVar2 = (*(byte *)((int)&this->m_steamid + 6) & 0xf) << 0x10 |
            (uint)*(ushort *)((int)&this->m_steamid + 4);
    if (uVar2 == 1) {
      snprintf(*__s,0x25,"[U:%u:%u]",(uint)(this->m_steamid).m_comp.m_EUniverse,
               (this->m_steamid).m_comp.m_unAccountID);
    }
    else {
      snprintf(*__s,0x25,"[U:%u:%u:%u]",(uint)(this->m_steamid).m_comp.m_EUniverse,
               (this->m_steamid).m_comp.m_unAccountID,uVar2);
    }
  }
  else {
    uVar1 = (this->m_steamid).m_comp.m_unAccountID;
    uVar2 = (uint)(this->m_steamid).m_comp.m_EUniverse;
    if (bVar3 == 0xa0) {
      snprintf(*__s,0x25,"[a:%u:%u]",uVar2,uVar1);
    }
    else {
      snprintf(*__s,0x25,"[i:%u:%u]",uVar2,uVar1);
    }
  }
  return *__s;
}


// CSteamID::Render  @ 000d45b0
char * __thiscall CSteamID::Render(CSteamID *this,uint64 ulSteamID)

{
  char (*__s) [37];
  byte bVar1;
  
                    /* Unresolved local var: CSteamID steamID@[???]
                       Unresolved local var: int k_cBufLen@[???]
                       Unresolved local var: char * pchBuf@[???]
                       Unresolved local var: int k_cBufs@[???] */
  __s = Render::lexical_block_0::rgchBuf + Render::lexical_block_0::nBuf;
  Render::lexical_block_0::nBuf = (Render::lexical_block_0::nBuf + 1) % 4;
  bVar1 = (byte)(ulSteamID >> 0x10) & 0xf0;
  if (bVar1 == 0x40) {
    snprintf(*__s,0x25,"[A:%u:%u:%u]",(uint)ulSteamID >> 0x18,this,(uint)ulSteamID & 0xfffff);
  }
  else if (bVar1 == 0x30) {
    snprintf(*__s,0x25,"[G:%u:%u]",(uint)ulSteamID >> 0x18,this);
  }
  else if (bVar1 == 0x20) {
    snprintf(*__s,0x25,"[M:%u:%u:%u]",(uint)ulSteamID >> 0x18,this,(uint)ulSteamID & 0xfffff);
  }
  else if (bVar1 == 0x50) {
    snprintf(*__s,0x25,"[P:%u:%u]",(uint)ulSteamID >> 0x18,this);
  }
  else if (bVar1 == 0x60) {
    snprintf(*__s,0x25,"[C:%u:%u]",(uint)ulSteamID >> 0x18,this);
  }
  else if (bVar1 == 0x70) {
    snprintf(*__s,0x25,"[g:%u:%u]",(uint)ulSteamID >> 0x18,this);
  }
  else if (bVar1 == 0x80) {
    if ((ulSteamID & 0x80000) == 0) {
      if ((ulSteamID & 0x40000) == 0) {
        snprintf(*__s,0x25,"[T:%u:%u]",(uint)ulSteamID >> 0x18,this);
      }
      else {
        snprintf(*__s,0x25,"[L:%u:%u]",(uint)ulSteamID >> 0x18,this);
      }
    }
    else {
      snprintf(*__s,0x25,"[c:%u:%u]",(uint)ulSteamID >> 0x18,this);
    }
  }
  else if ((ulSteamID & 0xf00000) == 0) {
    snprintf(*__s,0x25,"[I:%u:%u]",(uint)ulSteamID >> 0x18,this);
  }
  else if (bVar1 == 0x10) {
    if (((uint)ulSteamID & 0xfffff) == 1) {
      snprintf(*__s,0x25,"[U:%u:%u]",(uint)ulSteamID >> 0x18,this);
    }
    else {
      snprintf(*__s,0x25,"[U:%u:%u:%u]",(uint)ulSteamID >> 0x18,this,(uint)ulSteamID & 0xfffff);
    }
  }
  else if (bVar1 == 0xa0) {
    snprintf(*__s,0x25,"[a:%u:%u]",(uint)ulSteamID >> 0x18,this);
  }
  else {
    snprintf(*__s,0x25,"[i:%u:%u]",(uint)ulSteamID >> 0x18,this);
  }
  return *__s;
}


// CSteamID::SetFromSteam2String  @ 000d4120
/* DWARF original prototype: bool SetFromSteam2String(CSteamID * this, char * pchSteam2ID, EUniverse
   eUniverse) */

bool __thiscall CSteamID::SetFromSteam2String(CSteamID *this,char *pchSteam2ID,EUniverse eUniverse)

{
  int iVar1;
  char *__s;
  short local_1c [2];
  int local_18;
  int local_14;
  char local_d [5];
  
                    /* Unresolved local var: TSteamGlobalUserID.conflict steam2ID@[???]
                       Unresolved local var: char * pchTSteam2ID@[???]
                       Unresolved local var: char * pchOptionalLeadString@[???]
                       Unresolved local var: char cExtraCharCheck@[???]
                       Unresolved local var: int cFieldConverted@[???] */
  local_18 = 0;
  local_14 = 0;
  local_1c[0] = 0;
  iVar1 = strncasecmp(pchSteam2ID,"STEAM_",6);
  local_d[0] = '\0';
  __s = pchSteam2ID + 6;
  if (iVar1 != 0) {
    __s = pchSteam2ID;
  }
  iVar1 = sscanf(__s,"%hu:%u:%u%c",local_1c,&local_14,&local_18,local_d);
  if ((((iVar1 != -1) && (local_d[0] == '\0')) && (1 < iVar1)) &&
     ((iVar1 != 2 || (local_1c[0] == 1)))) {
    (this->m_steamid).m_comp.m_unAccountID = local_14 + local_18 * 2;
    *(undefined1 *)((int)&this->m_steamid + 4) = 1;
    *(undefined1 *)((int)&this->m_steamid + 5) = 0;
    *(undefined1 *)((int)&this->m_steamid + 6) = 0x10;
    (this->m_steamid).m_comp.m_EUniverse = (byte)eUniverse;
    return true;
  }
  return false;
}


// CSteamID::SetFromString  @ 000d3d30
/* DWARF original prototype: void SetFromString(CSteamID * this, char * pchSteamID, EUniverse
   eDefaultUniverse) */

void __thiscall CSteamID::SetFromString(CSteamID *this,char *pchSteamID,EUniverse eDefaultUniverse)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  uint32 local_4c [4];
  undefined4 local_3c [4];
  EUniverse local_2c [7];
  
                    /* Unresolved local var: uint32 nAccountID@[???]
                       Unresolved local var: uint32 nInstance@[???]
                       Unresolved local var: EUniverse eUniverse@[???]
                       Unresolved local var: EAccountType eAccountType@[???] */
  local_4c[0] = 0;
  local_3c[0] = 1;
  cVar1 = *pchSteamID;
  local_2c[0] = eDefaultUniverse;
  if (cVar1 == '[') {
    cVar1 = pchSteamID[1];
    pchSteamID = pchSteamID + 1;
  }
  if (cVar1 == 'A') {
                    /* Unresolved local var: char * pchColon@[DW_OP_reg0(EAX)] */
    if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
      pcVar2 = pchSteamID + 2;
    }
    else {
      pcVar2 = pchSteamID + 1;
    }
    pcVar3 = strchr(pcVar2,0x28);
    if (pcVar3 != (char *)0x0) {
      sscanf(pcVar3,"(%u)",local_3c);
    }
    pcVar3 = strchr(pcVar2,0x3a);
    if (pcVar3 == (char *)0x0) {
      sscanf(pcVar2,"%u",local_4c);
    }
    else if ((*pcVar3 == '\0') || (pcVar3 = strchr(pcVar3 + 1,0x3a), pcVar3 == (char *)0x0)) {
      sscanf(pcVar2,"%u:%u",local_2c,local_4c);
    }
    else {
      sscanf(pcVar2,"%u:%u:%u",local_2c,local_4c,local_3c);
    }
    if (local_4c[0] == 0) {
      (this->m_steamid).m_comp.m_unAccountID = 0;
      *(undefined1 *)((int)&this->m_steamid + 4) = 0;
      *(undefined1 *)((int)&this->m_steamid + 5) = 0;
      (this->m_steamid).m_comp.m_EUniverse = (byte)local_2c[0];
      *(undefined1 *)((int)&this->m_steamid + 6) = 0x40;
      return;
    }
    (this->m_steamid).m_comp.m_unAccountID = local_4c[0];
    *(char *)((int)&this->m_steamid + 4) = (char)local_3c[0];
    (this->m_steamid).m_comp.m_EUniverse = (byte)local_2c[0];
    *(char *)((int)&this->m_steamid + 5) = (char)((uint)local_3c[0] >> 8);
    *(byte *)((int)&this->m_steamid + 6) = (byte)((uint)local_3c[0] >> 0x10) & 0xf | 0x40;
    return;
  }
  if (cVar1 == 'G') {
    if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\x03';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\x03';
    }
  }
  else if (cVar1 == 'C') {
    if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\x06';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\x06';
    }
  }
  else if (cVar1 == 'g') {
    local_3c[0] = 0;
    if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
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
      local_3c[0] = 0x80000;
      cVar1 = pchSteamID[1];
    }
    else if (cVar1 == 'L') {
      local_3c[0] = 0x40000;
      cVar1 = pchSteamID[1];
    }
    else {
      if (cVar1 != 'T') {
        if (cVar1 == 'U') {
          if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
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
            if ((pchSteamID[1] == ':') || (pchSteamID[1] == '-')) {
              pchSteamID = pchSteamID + 2;
              cVar4 = '\0';
            }
            else {
              pchSteamID = pchSteamID + 1;
              cVar4 = '\0';
            }
          }
        }
        goto LAB_000d3dc0;
      }
      cVar1 = pchSteamID[1];
      local_3c[0] = 0;
    }
    if ((cVar1 == ':') || (cVar1 == '-')) {
      pchSteamID = pchSteamID + 2;
      cVar4 = '\b';
    }
    else {
      pchSteamID = pchSteamID + 1;
      cVar4 = '\b';
    }
  }
LAB_000d3dc0:
  pcVar2 = strchr(pchSteamID,0x3a);
  if (pcVar2 == (char *)0x0) {
    sscanf(pchSteamID,"%u",local_4c);
  }
  else {
    sscanf(pchSteamID + (*pchSteamID == '['),"%u:%u",local_2c,local_4c);
    if (local_2c[0] == k_EUniverseInvalid) {
      local_2c[0] = eDefaultUniverse;
    }
  }
  (this->m_steamid).m_comp.m_EUniverse = (byte)local_2c[0];
  *(char *)((int)&this->m_steamid + 4) = (char)local_3c[0];
  (this->m_steamid).m_comp.m_unAccountID = local_4c[0];
  *(char *)((int)&this->m_steamid + 5) = (char)((uint)local_3c[0] >> 8);
  *(byte *)((int)&this->m_steamid + 6) = cVar4 << 4 | (byte)((uint)local_3c[0] >> 0x10) & 0xf;
  return;
}


// CUtlBuffer::CUtlBuffer  @ 000d4ce0
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


// CUtlBuffer::CUtlBuffer  @ 000d4d40
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


// CUtlBuffer::CheckGet  @ 000d50c0
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


// CUtlBuffer::CheckPut  @ 000d5340
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
                    /* Unresolved local var: int growSize@[???] */
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
        puVar3 = (this->m_Memory).m_pMemory;
        (this->m_Memory).m_NumAllocated = __size;
        if (puVar3 == (uchar *)0x0) break;
        puVar3 = realloc(puVar3,__size);
        iVar5 = this->m_Put + size;
        (this->m_Memory).m_pMemory = puVar3;
        iVar2 = (this->m_Memory).m_NumAllocated;
        if (iVar5 <= iVar2) goto LAB_000d539e;
      }
      puVar3 = malloc(__size);
      (this->m_Memory).m_pMemory = puVar3;
    }
LAB_000d539e:
    bVar1 = true;
  }
  return bVar1;
}


// CUtlBuffer::EatWhiteSpace  @ 000d4ed0
/* WARNING: Variable defined which should be unmapped: lastpos */
/* DWARF original prototype: void EatWhiteSpace(CUtlBuffer * this) */

void __thiscall CUtlBuffer::EatWhiteSpace(CUtlBuffer *this)

{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  int lastpos;
  
  if (((this->m_Flags & 1) != 0) && (this->m_Error == '\0')) {
    iVar1 = (this->m_Memory).m_NumAllocated;
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


// CUtlBuffer::EnsureCapacity  @ 000d4d80
/* DWARF original prototype: void EnsureCapacity(CUtlBuffer * this, int num) */

void __thiscall CUtlBuffer::EnsureCapacity(CUtlBuffer *this,int num)

{
  int iVar1;
  int iVar2;
  size_t __size;
  uchar *puVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = (this->m_Memory).m_NumAllocated;
  if (iVar1 < num) {
    iVar2 = (this->m_Memory).m_GrowSize;
    iVar4 = num - iVar1;
                    /* Unresolved local var: int growSize@[DW_OP_reg1(ECX)] */
    if (iVar2 < 0) {
      iVar5 = iVar2;
      if (0 < iVar4) {
        return;
      }
    }
    else {
      iVar5 = iVar4;
      if (((iVar4 < 1) && (iVar5 = iVar2, iVar2 == 0)) && (iVar5 = 1, iVar1 != 0)) {
        iVar5 = iVar1;
      }
    }
    __size = iVar1 + iVar5;
    puVar3 = (this->m_Memory).m_pMemory;
    (this->m_Memory).m_NumAllocated = __size;
    if (puVar3 != (uchar *)0x0) {
      puVar3 = realloc(puVar3,__size);
      (this->m_Memory).m_pMemory = puVar3;
      return;
    }
                    /* Unresolved local var: int growSize@[???] */
    puVar3 = malloc(__size);
    (this->m_Memory).m_pMemory = puVar3;
  }
  return;
}


// CUtlBuffer::Get  @ 000d4e00
/* DWARF original prototype: void Get(CUtlBuffer * this, void * pMem, int size) */

void __thiscall CUtlBuffer::Get(CUtlBuffer *this,void *pMem,int size)

{
  uchar uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uchar *puVar7;
  
  puVar7 = (this->m_Memory).m_pMemory + this->m_Get;
  uVar4 = size;
  if (7 < (uint)size) {
    uVar6 = size;
    if (((uint)pMem & 1) != 0) {
      uVar1 = *puVar7;
      puVar7 = puVar7 + 1;
      *(uchar *)pMem = uVar1;
      pMem = (void *)((int)pMem + 1);
      uVar6 = size - 1;
    }
    if (((uint)pMem & 2) != 0) {
      uVar2 = *(undefined2 *)puVar7;
      uVar6 = uVar6 - 2;
      puVar7 = puVar7 + 2;
      *(undefined2 *)pMem = uVar2;
      pMem = (void *)((int)pMem + 2);
    }
    if (((uint)pMem & 4) != 0) {
      uVar3 = *(undefined4 *)puVar7;
      uVar6 = uVar6 - 4;
      puVar7 = puVar7 + 4;
      *(undefined4 *)pMem = uVar3;
      pMem = (void *)((int)pMem + 4);
    }
    uVar4 = uVar6 & 3;
    for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pMem = *(undefined4 *)puVar7;
      puVar7 = puVar7 + 4;
      pMem = (undefined4 *)((int)pMem + 4);
    }
  }
  iVar5 = 0;
  if ((uVar4 & 4) != 0) {
    *(undefined4 *)pMem = *(undefined4 *)puVar7;
    iVar5 = 4;
  }
  if ((uVar4 & 2) != 0) {
    *(undefined2 *)((int)pMem + iVar5) = *(undefined2 *)(puVar7 + iVar5);
    iVar5 = iVar5 + 2;
  }
  if ((uVar4 & 1) != 0) {
    *(uchar *)((int)pMem + iVar5) = puVar7[iVar5];
  }
  this->m_Get = this->m_Get + size;
  return;
}


// CUtlBuffer::GetString  @ 000d4f20
/* WARNING: Variable defined which should be unmapped: lastpos */
/* DWARF original prototype: void GetString(CUtlBuffer * this, char * pString) */

void __thiscall CUtlBuffer::GetString(CUtlBuffer *this,char *pString)

{
  uint uVar1;
  uchar uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  size_t sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uchar *puVar11;
  byte bVar12;
  int lastpos;
  
  bVar12 = 0;
  if (this->m_Error == '\0') {
    if ((this->m_Flags & 1) == 0) {
                    /* Unresolved local var: int len@[???] */
      puVar11 = (this->m_Memory).m_pMemory + this->m_Get;
      sVar6 = strlen((char *)puVar11);
      uVar1 = sVar6 + 1;
      uVar10 = uVar1;
      if (7 < uVar1) {
        uVar8 = uVar1;
        if (((uint)pString & 1) != 0) {
          uVar2 = *puVar11;
          puVar11 = puVar11 + 1;
          *pString = uVar2;
          pString = pString + 1;
          uVar8 = sVar6;
        }
        if (((uint)pString & 2) != 0) {
          uVar3 = *(undefined2 *)puVar11;
          uVar8 = uVar8 - 2;
          puVar11 = puVar11 + 2;
          *(undefined2 *)pString = uVar3;
          pString = pString + 2;
        }
        if (((uint)pString & 4) != 0) {
          uVar4 = *(undefined4 *)puVar11;
          uVar8 = uVar8 - 4;
          puVar11 = puVar11 + 4;
          *(undefined4 *)pString = uVar4;
          pString = pString + 4;
        }
        uVar10 = uVar8 & 3;
        for (uVar8 = uVar8 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined4 *)pString = *(undefined4 *)puVar11;
          puVar11 = puVar11 + (uint)bVar12 * -8 + 4;
          pString = pString + (uint)bVar12 * -8 + 4;
        }
      }
      iVar7 = 0;
      if ((uVar10 & 4) != 0) {
        iVar7 = 4;
        *(undefined4 *)pString = *(undefined4 *)puVar11;
      }
      if ((uVar10 & 2) != 0) {
        *(undefined2 *)(pString + iVar7) = *(undefined2 *)(puVar11 + iVar7);
        iVar7 = iVar7 + 2;
      }
      if ((uVar10 & 1) == 0) {
        this->m_Get = this->m_Get + uVar1;
      }
      else {
        pString[iVar7] = puVar11[iVar7];
        this->m_Get = this->m_Get + uVar1;
      }
      return;
    }
                    /* Unresolved local var: int lastpos@[???] */
    iVar7 = (this->m_Memory).m_NumAllocated;
    if ((this->m_Flags & 1) == 0) {
      iVar9 = this->m_Get;
joined_r0x000d4fe5:
      do {
        if (iVar7 <= iVar9) goto LAB_000d4f90;
        uVar2 = (this->m_Memory).m_pMemory[iVar9];
        iVar9 = isspace((int)(char)uVar2);
                    /* Unresolved local var: char c@[???] */
        if ((uVar2 == '\0') || (iVar9 != 0)) goto LAB_000d4f90;
        *pString = uVar2;
        pString = pString + 1;
        iVar9 = this->m_Get + 1;
        this->m_Get = iVar9;
      } while( true );
    }
    iVar9 = this->m_Get;
    if (iVar9 < iVar7) {
      puVar11 = (this->m_Memory).m_pMemory;
      do {
        iVar5 = isspace((int)(char)puVar11[iVar9]);
        if (iVar5 == 0) goto joined_r0x000d4fe5;
        iVar9 = iVar9 + 1;
        this->m_Get = iVar9;
      } while (iVar9 < iVar7);
    }
  }
LAB_000d4f90:
  *pString = '\0';
  return;
}


// CUtlBuffer::Printf  @ 000d5780
/* DWARF original prototype: void Printf(CUtlBuffer * this, char * pFmt, ...) */

void __thiscall CUtlBuffer::Printf(CUtlBuffer *this,char *pFmt,...)

{
                    /* Unresolved local var: va_list args@[???] */
  VaPrintf(this,pFmt,&stack0x0000000c);
  return;
}


// CUtlBuffer::Put  @ 000d53d0
/* DWARF original prototype: void Put(CUtlBuffer * this, void * pMem, int size) */

void __thiscall CUtlBuffer::Put(CUtlBuffer *this,void *pMem,int size)

{
  uchar uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uchar *puVar8;
  byte bVar9;
  
  bVar9 = 0;
  bVar4 = CheckPut(this,size);
  if (bVar4) {
    puVar8 = (this->m_Memory).m_pMemory + this->m_Put;
    uVar5 = size;
    if (7 < (uint)size) {
      uVar6 = size;
      if (((uint)puVar8 & 1) != 0) {
        uVar1 = *(uchar *)pMem;
        pMem = (void *)((int)pMem + 1);
        *puVar8 = uVar1;
        puVar8 = puVar8 + 1;
        uVar6 = size - 1;
      }
      if (((uint)puVar8 & 2) != 0) {
        uVar2 = *(undefined2 *)pMem;
        uVar6 = uVar6 - 2;
        pMem = (void *)((int)pMem + 2);
        *(undefined2 *)puVar8 = uVar2;
        puVar8 = puVar8 + 2;
      }
      if (((uint)puVar8 & 4) != 0) {
        uVar3 = *(undefined4 *)pMem;
        uVar6 = uVar6 - 4;
        pMem = (void *)((int)pMem + 4);
        *(undefined4 *)puVar8 = uVar3;
        puVar8 = puVar8 + 4;
      }
      uVar5 = uVar6 & 3;
      for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)puVar8 = *(undefined4 *)pMem;
        pMem = (undefined4 *)((int)pMem + ((uint)bVar9 * -2 + 1) * 4);
        puVar8 = puVar8 + ((uint)bVar9 * -2 + 1) * 4;
      }
    }
    iVar7 = 0;
    if ((uVar5 & 4) != 0) {
      *(undefined4 *)puVar8 = *(undefined4 *)pMem;
      iVar7 = 4;
    }
    if ((uVar5 & 2) != 0) {
      *(undefined2 *)(puVar8 + iVar7) = *(undefined2 *)((int)pMem + iVar7);
      iVar7 = iVar7 + 2;
    }
    if ((uVar5 & 1) == 0) {
      this->m_Put = this->m_Put + size;
    }
    else {
      puVar8[iVar7] = *(uchar *)((int)pMem + iVar7);
      this->m_Put = this->m_Put + size;
    }
  }
  return;
}


// CUtlBuffer::PutString  @ 000d54f0
/* DWARF original prototype: void PutString(CUtlBuffer * this, char * pString) */

void __thiscall CUtlBuffer::PutString(CUtlBuffer *this,char *pString)

{
  uchar uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  bool bVar4;
  size_t sVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint size;
  uchar *puVar9;
  byte bVar10;
  
  bVar10 = 0;
                    /* Unresolved local var: int len@[???] */
  sVar5 = strlen(pString);
  size = sVar5 + 1;
  if ((this->m_Flags & 1) != 0) {
    size = sVar5;
  }
  bVar4 = CheckPut(this,size);
  if (bVar4) {
    puVar9 = (this->m_Memory).m_pMemory + this->m_Put;
    uVar6 = size;
    if (7 < size) {
      uVar7 = size;
      if (((uint)puVar9 & 1) != 0) {
        uVar1 = *pString;
        pString = pString + 1;
        *puVar9 = uVar1;
        puVar9 = puVar9 + 1;
        uVar7 = size - 1;
      }
      if (((uint)puVar9 & 2) != 0) {
        uVar2 = *(undefined2 *)pString;
        uVar7 = uVar7 - 2;
        pString = pString + 2;
        *(undefined2 *)puVar9 = uVar2;
        puVar9 = puVar9 + 2;
      }
      if (((uint)puVar9 & 4) != 0) {
        uVar3 = *(undefined4 *)pString;
        uVar7 = uVar7 - 4;
        pString = pString + 4;
        *(undefined4 *)puVar9 = uVar3;
        puVar9 = puVar9 + 4;
      }
      uVar6 = uVar7 & 3;
      for (uVar7 = uVar7 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)puVar9 = *(undefined4 *)pString;
        pString = pString + (uint)bVar10 * -8 + 4;
        puVar9 = puVar9 + (uint)bVar10 * -8 + 4;
      }
    }
    iVar8 = 0;
    if ((uVar6 & 4) != 0) {
      *(undefined4 *)puVar9 = *(undefined4 *)pString;
      iVar8 = 4;
    }
    if ((uVar6 & 2) != 0) {
      *(undefined2 *)(puVar9 + iVar8) = *(undefined2 *)(pString + iVar8);
      iVar8 = iVar8 + 2;
    }
    if ((uVar6 & 1) == 0) {
      this->m_Put = this->m_Put + size;
    }
    else {
      puVar9[iVar8] = pString[iVar8];
      this->m_Put = this->m_Put + size;
    }
  }
  return;
}


// CUtlBuffer::Scanf  @ 000d5310
/* DWARF original prototype: int Scanf(CUtlBuffer * this, char * pFmt, ...) */

int __thiscall CUtlBuffer::Scanf(CUtlBuffer *this,char *pFmt,...)

{
  int iVar1;
  
                    /* Unresolved local var: va_list args@[???]
                       Unresolved local var: int count@[DW_OP_reg0(EAX)] */
  iVar1 = VaScanf(this,pFmt,&stack0x0000000c);
  return iVar1;
}


// CUtlBuffer::SeekGet  @ 000d50f0
/* DWARF original prototype: void SeekGet(CUtlBuffer * this, SeekType_t type, int offset) */

void __thiscall CUtlBuffer::SeekGet(CUtlBuffer *this,SeekType_t type,int offset)

{
  if (type == SEEK_CURRENT) {
    this->m_Get = this->m_Get + offset;
    return;
  }
  if (type == SEEK_TAIL) {
    this->m_Get = (this->m_Memory).m_NumAllocated - offset;
  }
  else if (type == SEEK_HEAD) {
    this->m_Get = offset;
    return;
  }
  return;
}


// CUtlBuffer::SeekPut  @ 000d57b0
/* DWARF original prototype: void SeekPut(CUtlBuffer * this, SeekType_t type, int offset) */

void __thiscall CUtlBuffer::SeekPut(CUtlBuffer *this,SeekType_t type,int offset)

{
  if (type == SEEK_CURRENT) {
    this->m_Put = this->m_Put + offset;
    return;
  }
  if (type == SEEK_TAIL) {
    this->m_Put = (this->m_Memory).m_NumAllocated - offset;
  }
  else if (type == SEEK_HEAD) {
    this->m_Put = offset;
    return;
  }
  return;
}


// CUtlBuffer::VaPrintf  @ 000d5620
/* DWARF original prototype: void VaPrintf(CUtlBuffer * this, char * pFmt, va_list list) */

void __thiscall CUtlBuffer::VaPrintf(CUtlBuffer *this,char *pFmt,va_list list)

{
  undefined2 uVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint size;
  uchar *__s;
  uchar *puVar7;
  byte bVar8;
  uchar local_81c;
  uchar auStack_81b [2059];
  
  bVar8 = 0;
                    /* Unresolved local var: char[2048] temp@[???]
                       Unresolved local var: int len@[???] */
  __s = &local_81c;
  iVar4 = vsprintf((char *)__s,pFmt,list);
  size = iVar4 + (uint)((this->m_Flags & 1) == 0);
  bVar3 = CheckPut(this,size);
  if (bVar3) {
    puVar7 = (this->m_Memory).m_pMemory + this->m_Put;
    uVar5 = size;
    if (7 < size) {
      uVar6 = size;
      if (((uint)puVar7 & 1) != 0) {
        __s = auStack_81b;
        *puVar7 = local_81c;
        puVar7 = puVar7 + 1;
        uVar6 = size - 1;
      }
      if (((uint)puVar7 & 2) != 0) {
        uVar1 = *(undefined2 *)__s;
        uVar6 = uVar6 - 2;
        __s = __s + 2;
        *(undefined2 *)puVar7 = uVar1;
        puVar7 = puVar7 + 2;
      }
      if (((uint)puVar7 & 4) != 0) {
        uVar2 = *(undefined4 *)__s;
        uVar6 = uVar6 - 4;
        __s = __s + 4;
        *(undefined4 *)puVar7 = uVar2;
        puVar7 = puVar7 + 4;
      }
      uVar5 = uVar6 & 3;
      for (uVar6 = uVar6 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)puVar7 = *(undefined4 *)__s;
        __s = __s + (uint)bVar8 * -8 + 4;
        puVar7 = puVar7 + (uint)bVar8 * -8 + 4;
      }
    }
    iVar4 = 0;
    if ((uVar5 & 4) != 0) {
      *(undefined4 *)puVar7 = *(undefined4 *)__s;
      iVar4 = 4;
    }
    if ((uVar5 & 2) != 0) {
      *(undefined2 *)(puVar7 + iVar4) = *(undefined2 *)(__s + iVar4);
      iVar4 = iVar4 + 2;
    }
    if ((uVar5 & 1) == 0) {
      this->m_Put = this->m_Put + size;
    }
    else {
      puVar7[iVar4] = __s[iVar4];
      this->m_Put = this->m_Put + size;
    }
  }
  return;
}


// CUtlBuffer::VaScanf  @ 000d5130
/* DWARF original prototype: int VaScanf(CUtlBuffer * this, char * pFmt, va_list list) */

int __thiscall CUtlBuffer::VaScanf(CUtlBuffer *this,char *pFmt,va_list list)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uchar *puVar4;
  ulong *puVar5;
  float *pfVar6;
  long *plVar7;
  int iVar8;
  ulong uVar9;
  long lVar10;
  int iVar11;
  double dVar12;
  int local_34;
  uchar *local_20 [4];
  
                    /* Unresolved local var: int numScanned@[???]
                       Unresolved local var: char c@[???]
                       Unresolved local var: char * pEnd@[???] */
  local_34 = 0;
  if ((this->m_Error == '\0') && ((this->m_Flags & 1) != 0)) {
LAB_000d5189:
    cVar2 = *pFmt;
    pcVar1 = pFmt + 1;
    if (cVar2 != '\0') {
      iVar11 = this->m_Get;
      iVar3 = (this->m_Memory).m_NumAllocated;
      if (iVar3 <= iVar11) {
        this->m_Error = this->m_Error | 2;
        return local_34;
      }
      if (cVar2 == ' ') goto code_r0x000d51aa;
      if (cVar2 == '%') {
                    /* Unresolved local var: char type@[???] */
        if (pFmt[1] == '\0') {
          return local_34;
        }
        switch(pFmt[1]) {
        case 'c':
                    /* Unresolved local var: char * ch@[???] */
          **(uchar **)list = (this->m_Memory).m_pMemory[iVar11];
          this->m_Get = this->m_Get + 1;
          goto LAB_000d5242;
        case 'd':
        case 'i':
                    /* Unresolved local var: int * i@[???] */
          plVar7 = *(long **)list;
          lVar10 = strtol((char *)((this->m_Memory).m_pMemory + iVar11),(char **)local_20,10);
          *plVar7 = lVar10;
          break;
        default:
          goto switchD_000d51f9_caseD_65;
        case 'f':
          pfVar6 = *(float **)list;
          dVar12 = strtod((char *)((this->m_Memory).m_pMemory + iVar11),(char **)local_20);
          *pfVar6 = (float)dVar12;
          break;
        case 's':
                    /* Unresolved local var: char * s@[???] */
          GetString(this,*(char **)list);
          goto LAB_000d5242;
        case 'u':
                    /* Unresolved local var: uint * u@[???] */
          puVar5 = *(ulong **)list;
          uVar9 = strtoul((char *)((this->m_Memory).m_pMemory + iVar11),(char **)local_20,10);
          *puVar5 = uVar9;
        }
                    /* Unresolved local var: float * f@[???] */
        puVar4 = (this->m_Memory).m_pMemory;
        if (local_20[0] == puVar4 + this->m_Get) {
          return local_34;
        }
        this->m_Get = (int)local_20[0] - (int)puVar4;
LAB_000d5242:
        list = list + 4;
        local_34 = local_34 + 1;
        pFmt = pFmt + 2;
      }
      else {
        if ((int)cVar2 != (uint)(this->m_Memory).m_pMemory[iVar11]) {
          return local_34;
        }
        this->m_Get = iVar11 + 1;
        pFmt = pcVar1;
      }
      goto LAB_000d5189;
    }
  }
switchD_000d51f9_caseD_65:
  return local_34;
code_r0x000d51aa:
  pFmt = pcVar1;
  if (((this->m_Flags & 1) != 0) && (this->m_Error == '\0')) {
    puVar4 = (this->m_Memory).m_pMemory;
    do {
      iVar8 = isspace((int)(char)puVar4[iVar11]);
      if (iVar8 == 0) break;
                    /* Unresolved local var: int lastpos@[???] */
      iVar11 = iVar11 + 1;
      this->m_Get = iVar11;
    } while (iVar11 < iVar3);
  }
  goto LAB_000d5189;
}


// CUtlVector<char*>::~CUtlVector  @ 0006f480
/* DWARF original prototype: void ~CUtlVector(CUtlVector<char*> * this, int __in_chrg) */

void __thiscall CUtlVector<char*>::~CUtlVector(CUtlVector<char*> *this,int __in_chrg)

{
  int iVar1;
  char **__ptr;
  
  iVar1 = (this->m_Memory).m_GrowSize;
  this->m_Size = 0;
  if (-1 < iVar1) {
    __ptr = (this->m_Memory).m_pMemory;
    if (__ptr != (char **)0x0) {
      free(__ptr);
      (this->m_Memory).m_pMemory = (char **)0x0;
      (this->m_Memory).m_NumAllocated = 0;
      if ((this->m_Memory).m_GrowSize < 0) {
        return;
      }
    }
    (this->m_Memory).m_NumAllocated = 0;
  }
  return;
}


// CVarGetFloat  @ 000923e0
float CVarGetFloat(char *szVarName)

{
  cvar_s **ppcVar1;
  int iVar2;
  cvar_s *pcVar3;
  float fVar4;
  char *apcStack_10 [3];
  
  apcStack_10[0] = szVarName;
  (*g_engdstAddrs.pfnGetCvarPointer)(apcStack_10);
  fVar4 = 0.0;
  pcVar3 = cvar_vars;
  if (cvar_vars != (cvar_t *)0x0) {
    while (iVar2 = Q_stricmp(apcStack_10[0],pcVar3->name), iVar2 != 0) {
      ppcVar1 = &pcVar3->next;
      pcVar3 = *ppcVar1;
      if (*ppcVar1 == (cvar_s *)0x0) {
        return 0.0;
      }
    }
    fVar4 = Q_atof(pcVar3->string);
  }
  return fVar4;
}


// CVarGetPointer  @ 00092400
cvar_t * CVarGetPointer(char *szVarName)

{
  cvar_s *pcVar1;
  int iVar2;
  
  (*g_engdstAddrs.pfnGetCvarPointer)(&szVarName);
  pcVar1 = cvar_vars;
  while ((pcVar1 != (cvar_t *)0x0 && (iVar2 = Q_stricmp(szVarName,pcVar1->name), iVar2 != 0))) {
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}


// CVarGetString  @ 000923f0
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


// CVarRegister  @ 00092430
void CVarRegister(cvar_t *pCvar)

{
  if (pCvar != (cvar_t *)0x0) {
    pCvar->flags = pCvar->flags | 8;
    Cvar_RegisterVariable(pCvar);
    return;
  }
  return;
}


// CVarSetFloat  @ 00092410
void CVarSetFloat(char *szVarName,float flValue)

{
  cvar_s *var;
  cvarhook_s *pcVar1;
  char *pcVar2;
  int iVar3;
  char acStack_30 [32];
  char *pcStack_10;
  
  (*g_engdstAddrs.Cvar_SetValue)(&szVarName,&flValue);
  if (ABS(flValue - (float)(int)flValue) < 1e-06) {
    snprintf(acStack_30,0x20,"%d",(int)flValue);
  }
  else {
    snprintf(acStack_30,0x20,"%f",(double)flValue);
  }
  pcVar2 = szVarName;
  pcStack_10 = szVarName;
  (*g_engdstAddrs.pfnGetCvarPointer)(&pcStack_10);
  var = cvar_vars;
  while( true ) {
    if (var == (cvar_s *)0x0) {
      Con_DPrintf("Cvar_Set: variable %s not found\n",pcVar2);
      return;
    }
    iVar3 = Q_stricmp(pcStack_10,var->name);
    if (iVar3 == 0) break;
    var = var->next;
  }
  Cvar_DirectSet(var,acStack_30);
  pcVar1 = cvar_hooks;
  while( true ) {
    if (pcVar1 == (cvarhook_t *)0x0) {
      return;
    }
    if (var == pcVar1->cvar) break;
    pcVar1 = pcVar1->next;
  }
  (*pcVar1->hook)(var);
  return;
}


// CVarSetString  @ 00092420
void CVarSetString(char *szVarName,char *szValue)

{
  cvar_s *pcVar1;
  cvar_s *var;
  cvarhook_s *pcVar2;
  int iVar3;
  char *apcStack_10 [2];
  
  apcStack_10[0] = szVarName;
  (*g_engdstAddrs.pfnGetCvarPointer)(apcStack_10);
  var = cvar_vars;
  while( true ) {
    if (var == (cvar_s *)0x0) {
      Con_DPrintf("Cvar_Set: variable %s not found\n",szVarName);
      return;
    }
    iVar3 = Q_stricmp(apcStack_10[0],var->name);
    if (iVar3 == 0) break;
    var = var->next;
  }
  Cvar_DirectSet(var,szValue);
  if (cvar_hooks == (cvarhook_t *)0x0) {
    return;
  }
  pcVar1 = cvar_hooks->cvar;
  pcVar2 = cvar_hooks;
  while( true ) {
    if (var == pcVar1) {
      (*pcVar2->hook)(var);
      return;
    }
    pcVar2 = pcVar2->next;
    if (pcVar2 == (cvarhook_s *)0x0) break;
    pcVar1 = pcVar2->cvar;
  }
  return;
}


// CacheSystemCompare  @ 000c19b0
int CacheSystemCompare(void *ppcs1,void *ppcs2)

{
  int iVar1;
  
                    /* Unresolved local var: cache_system_t * pcs1@[???]
                       Unresolved local var: cache_system_t * pcs2@[???] */
  iVar1 = strcasecmp((char *)(*(int *)ppcs1 + 8),(char *)(*(int *)ppcs2 + 8));
  return iVar1;
}


// CalcSurfaceExtents  @ 000823e0
void CalcSurfaceExtents(msurface_t *s)

{
  ushort uVar1;
  mtexinfo_t *pmVar2;
  int iVar3;
  float fVar4;
  short sVar5;
  int iVar6;
  mvertex_t *unaff_EBX;
  float fVar7;
  float fVar8;
  float local_50;
  float local_4c;
  float local_48;
  
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
  local_48 = -99999.0;
  local_50 = 999999.0;
  pmVar2 = s->texinfo;
  if (s->numedges < 1) {
    sVar5 = -0x1869;
    iVar6 = 0xf423;
  }
  else {
    local_48 = -99999.0;
    iVar6 = 0;
    fVar8 = -99999.0;
    local_4c = -99999.0;
    fVar7 = 999999.0;
    do {
      iVar3 = loadmodel->surfedges[s->firstedge + iVar6];
      if (iVar3 < 0) {
        uVar1 = loadmodel->edges[-iVar3].v[1];
      }
      else {
        uVar1 = loadmodel->edges[iVar3].v[0];
      }
      unaff_EBX = loadmodel->vertexes + uVar1;
      fVar4 = pmVar2->vecs[0][2] * unaff_EBX->position[2] +
              pmVar2->vecs[0][1] * unaff_EBX->position[1] +
              pmVar2->vecs[0][0] * unaff_EBX->position[0] + pmVar2->vecs[0][3];
      if (fVar4 < fVar7) {
        fVar7 = fVar4;
      }
      if (fVar8 < fVar4) {
        fVar8 = fVar4;
      }
      fVar4 = unaff_EBX->position[2] * pmVar2->vecs[1][2] +
              unaff_EBX->position[1] * pmVar2->vecs[1][1] +
              unaff_EBX->position[0] * pmVar2->vecs[1][0] + pmVar2->vecs[1][3];
      if (fVar4 < local_50) {
        local_50 = fVar4;
      }
      if (local_4c < fVar4) {
        local_4c = fVar4;
        local_48 = fVar4;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != s->numedges);
    fVar7 = floorf(fVar7 * 0.0625);
    iVar6 = (int)fVar7;
    fVar8 = ceilf(fVar8 * 0.0625);
    sVar5 = (short)(int)fVar8;
  }
  sVar5 = (sVar5 - (short)iVar6) * 0x10;
  s->texturemins[0] = (short)(iVar6 << 4);
  s->extents[0] = sVar5;
  if (((pmVar2->flags & 1) == 0) && (0x100 < sVar5)) {
    Sys_Error("Bad surface extents %d/%d at position (%d,%d,%d)",(int)sVar5,(int)s->extents[1],
              (int)unaff_EBX->position[0],(int)unaff_EBX->position[1],(int)unaff_EBX->position[2]);
  }
  fVar8 = floorf(local_50 * 0.0625);
  fVar7 = ceilf(local_48 * 0.0625);
  s->texturemins[1] = (short)((int)fVar8 << 4);
  sVar5 = ((short)(int)fVar7 - (short)(int)fVar8) * 0x10;
  s->extents[1] = sVar5;
  if (((pmVar2->flags & 1) == 0) && (0x100 < sVar5)) {
    Sys_Error("Bad surface extents %d/%d at position (%d,%d,%d)",(int)s->extents[0],(int)sVar5,
              (int)unaff_EBX->position[0],(int)unaff_EBX->position[1],(int)unaff_EBX->position[2]);
    return;
  }
  return;
}


// CheckChallengeNr  @ 000a0620
qboolean CheckChallengeNr(netadr_t *adr,int nChallengeValue)

{
  qboolean qVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if ((nChallengeValue != -1) && (adr != (netadr_t *)0x0)) {
    iVar2 = 0;
    do {
      qVar1 = NET_CompareBaseAdr(*adr,g_rg_sv_challenges[iVar2].adr);
      if (qVar1 != false) {
        if (g_rg_sv_challenges[iVar2].challenge != nChallengeValue) {
          return false;
        }
        return (uint)((float)realtime <= (float)g_rg_sv_challenges[iVar2].time + 3600.0);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x400);
  }
  return false;
}


// CheckGore  @ 000757e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CheckGore(void)

{
  undefined1 local_8c [140];
  
                    /* Unresolved local var: char[128] szSubKey@[???]
                       Unresolved local var: int nBufferLen@[???]
                       Unresolved local var: char[128] szBuffer@[???]
                       Unresolved local var: qboolean bGore@[???] */
  Q_memset(local_8c,0,0x80);
  if (bLowViolenceBuild == false) {
    Cvar_SetValue("violence_hblood",1.0);
    Cvar_SetValue("violence_hgibs",1.0);
    Cvar_SetValue("violence_ablood",1.0);
    Cvar_SetValue("violence_agibs",1.0);
    return;
  }
  Cvar_SetValue("violence_hblood",0.0);
  Cvar_SetValue("violence_hgibs",0.0);
  Cvar_SetValue("violence_ablood",0.0);
  Cvar_SetValue("violence_agibs",0.0);
  return;
}


// CheckIP  @ 000ce5d0
int CheckIP(netadr_t_conflict adr)

{
  bool bVar1;
  
  bVar1 = CIPRateLimit::CheckIP(&rateChecker,adr);
  return (uint)bVar1;
}


// CheckLiblistForFallbackDir  @ 0006e270
void CheckLiblistForFallbackDir
               (char *pGameDir,bool bLanguage,char *pLanguage,bool bLowViolenceBuild)

{
  char *__dest;
  int iVar1;
  int iVar2;
  int iVar3;
  FileHandle_t file;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined1 uVar8;
  byte bVar9;
  char *pcVar10;
  char local_149c [4095];
  undefined1 local_49d;
  char local_49c [511];
  undefined1 local_29d;
  char local_29c [511];
  char local_9d [141];
  
  bVar9 = 0;
                    /* Unresolved local var: char[512] szTemp@[???]
                       Unresolved local var: bool bSuccess@[???]
                       Unresolved local var: FileHandle_t hFile@[???] */
  snprintf(local_49c,0x1ff,"%s/liblist.gam",pGameDir);
  COM_FixSlashes(local_49c);
  (**(code **)(*(int *)g_pFileSystem + 0x80))(g_pFileSystem,local_49c);
  iVar3 = strcasecmp(com_gamedir,pGameDir);
  if (iVar3 == 0) {
    file = FS_Open("liblist.gam","rt");
  }
  else {
    snprintf(local_49c,0x1ff,"../%s/liblist.gam",pGameDir);
    COM_FixSlashes(local_49c);
    file = FS_Open(local_49c,"rt");
  }
                    /* Unresolved local var: char[128] szFallback@[???]
                       Unresolved local var: char[512] szLine@[???]
                       Unresolved local var: int outputBufferSize@[???] */
  if (file == (FileHandle_t)0x0) {
    return;
  }
  do {
    do {
      iVar3 = FS_EndOfFile(file);
      if (iVar3 != 0) goto LAB_0006e650;
      local_29c[0] = '\0';
      FS_ReadLine(local_29c,0x1ff,file);
      local_9d[0] = '\0';
      iVar3 = strncasecmp(local_29c,"fallback_dir",0xc);
    } while (iVar3 != 0);
                    /* Unresolved local var: char * start@[DW_OP_reg7(EDI)]
                       Unresolved local var: char * end@[DW_OP_reg0(EAX)]
                       Unresolved local var: int bytesToCopy@[???] */
    pcVar4 = strchr(local_29c,0x22);
    if (pcVar4 == (char *)0x0) goto LAB_0006e650;
    pcVar5 = strchr(pcVar4 + 1,0x22);
    if ((pcVar5 == (char *)0x0) || (pcVar5 = pcVar5 + (-1 - (int)pcVar4), (char *)0x7e < pcVar5))
    goto LAB_0006e650;
  } while (pcVar5 == (char *)0x0);
  __dest = local_9d + 1;
  strncpy(__dest,pcVar4 + 1,(size_t)pcVar5);
  local_9d[(int)(pcVar5 + 1)] = '\0';
  iVar3 = strcasecmp(pGameDir,__dest);
  if (iVar3 == 0) goto LAB_0006e650;
  if (bLowViolenceBuild) {
    snprintf(local_49c,0x1ff,"%s/%s_lv",s_pBaseDir,__dest);
    local_29d = 0;
    COM_FixSlashes(local_49c);
    (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_49c,"GAME_FALLBACK");
  }
  iVar3 = COM_CheckParm("-addons");
  if ((iVar3 != 0) ||
     (iVar3 = (*registry->_vptr_IRegistry[2])(registry,"addons_folder",0), 0 < iVar3)) {
    snprintf(local_49c,0x1ff,"%s/%s_addon",s_pBaseDir,__dest);
    local_29d = 0;
    COM_FixSlashes(local_49c);
    (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_49c,"GAME_FALLBACK");
  }
  if ((bLanguage) && (pLanguage != (char *)0x0)) {
    snprintf(local_49c,0x1ff,"%s/%s_%s",s_pBaseDir,__dest,pLanguage);
    local_29d = 0;
    COM_FixSlashes(local_49c);
    (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_49c,"GAME_FALLBACK");
    iVar3 = COM_CheckParm("-steam");
    if (iVar3 == 0) {
                    /* Unresolved local var: char[4096] baseDir@[???]
                       Unresolved local var: char * tempPtr@[???] */
      Q_strncpy(local_149c,s_pBaseDir,0xfff);
      local_49d = 0;
      pcVar4 = Q_strstr(local_149c,"\\game");
      if (pcVar4 != (char *)0x0) {
        *pcVar4 = '\0';
        snprintf(local_49c,0x1ff,"%s\\localization\\%s_%s",local_149c,__dest,pLanguage);
        local_29d = 0;
        COM_FixSlashes(local_49c);
        (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_49c,"GAME_FALLBACK");
      }
    }
  }
  iVar3 = COM_CheckParm("-nohdmodels");
  if ((iVar3 == 0) && (iVar3 = (*registry->_vptr_IRegistry[2])(registry,"hdmodels",1), 0 < iVar3)) {
    snprintf(local_49c,0x1ff,"%s/%s_hd",s_pBaseDir,__dest);
    local_29d = 0;
    COM_FixSlashes(local_49c);
    (**(code **)(*(int *)g_pFileSystem + 0xd8))(g_pFileSystem,local_49c,"GAME_FALLBACK");
  }
  pcVar10 = __dest;
  snprintf(local_49c,0x1ff,"%s/%s",s_pBaseDir,__dest);
  uVar8 = 1;
  local_29d = 0;
  COM_FixSlashes(local_49c);
  (**(code **)(*(int *)g_pFileSystem + 0x14))(g_pFileSystem,local_49c,"GAME_FALLBACK");
  iVar3 = 6;
  pcVar4 = __dest;
  pcVar5 = "valve";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    uVar8 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar9 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar9 * -2 + 1;
  } while ((bool)uVar8);
  if ((bool)uVar8) goto LAB_0006e650;
                    /* Unresolved local var: int BufLen@[???]
                       Unresolved local var: char * szFileName@[???] */
  pcVar4 = operator_new__(0x80);
  snprintf(pcVar4,0x7f,"Resource/%s_%%language%%.txt",__dest,pcVar10);
  iVar2 = g_fallbackLocalizationFiles.m_Size;
  iVar3 = g_fallbackLocalizationFiles.m_Memory.m_NumAllocated;
  pcVar4[0x7f] = '\0';
  if (iVar2 < iVar3) {
    iVar7 = iVar2 + 1;
  }
  else {
    iVar7 = iVar2 + 1;
    iVar6 = iVar7 - iVar3;
                    /* Unresolved local var: int growSize@[???] */
    if (g_fallbackLocalizationFiles.m_Memory.m_GrowSize < 0) {
      iVar1 = g_fallbackLocalizationFiles.m_Memory.m_GrowSize;
      if (0 < iVar6) goto LAB_0006e60e;
    }
    else {
      iVar1 = iVar6;
      if (((iVar6 < 1) &&
          (iVar1 = g_fallbackLocalizationFiles.m_Memory.m_GrowSize,
          g_fallbackLocalizationFiles.m_Memory.m_GrowSize == 0)) && (iVar1 = 1, iVar3 != 0)) {
        iVar1 = iVar3;
      }
    }
    g_fallbackLocalizationFiles.m_Memory.m_NumAllocated = iVar3 + iVar1;
    if (g_fallbackLocalizationFiles.m_Memory.m_pMemory == (char **)0x0) {
      g_fallbackLocalizationFiles.m_Memory.m_pMemory =
           malloc(g_fallbackLocalizationFiles.m_Memory.m_NumAllocated * 4);
    }
    else {
      g_fallbackLocalizationFiles.m_Memory.m_pMemory =
           realloc(g_fallbackLocalizationFiles.m_Memory.m_pMemory,
                   g_fallbackLocalizationFiles.m_Memory.m_NumAllocated * 4);
      iVar7 = g_fallbackLocalizationFiles.m_Size + 1;
    }
  }
LAB_0006e60e:
                    /* Unresolved local var: int numToMove@[???] */
  iVar3 = (iVar7 - iVar2) + -1;
  g_fallbackLocalizationFiles.m_Size = iVar7;
  if (0 < iVar3) {
    memmove(g_fallbackLocalizationFiles.m_Memory.m_pMemory + iVar2 + 1,
            g_fallbackLocalizationFiles.m_Memory.m_pMemory + iVar2,iVar3 * 4);
  }
  if (g_fallbackLocalizationFiles.m_Memory.m_pMemory + iVar2 != (char **)0x0) {
    g_fallbackLocalizationFiles.m_Memory.m_pMemory[iVar2] = pcVar4;
  }
  CheckLiblistForFallbackDir(__dest,bLanguage,pLanguage,bLowViolenceBuild);
LAB_0006e650:
  FS_Close(file);
  return;
}


// CleanupName  @ 000bca30
void CleanupName(char *in,char *out)

{
  char cVar1;
  __int32_t **pp_Var2;
  uint uVar3;
  uint uVar4;
  undefined1 (*pauVar5) [16];
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
                    /* Unresolved local var: int i@[???] */
  cVar1 = *in;
  if (cVar1 == '\0') {
    uVar3 = 0;
  }
  else {
                    /* Unresolved local var: int __res@[???] */
    pp_Var2 = __ctype_toupper_loc();
    *out = (char)(*pp_Var2)[cVar1];
    if (in[1] == '\0') {
      uVar3 = 1;
    }
    else {
      out[1] = (char)(*pp_Var2)[in[1]];
      if (in[2] == '\0') {
        uVar3 = 2;
      }
      else {
        out[2] = (char)(*pp_Var2)[in[2]];
        if (in[3] == '\0') {
          uVar3 = 3;
        }
        else {
          out[3] = (char)(*pp_Var2)[in[3]];
          if (in[4] == '\0') {
            uVar3 = 4;
          }
          else {
            out[4] = (char)(*pp_Var2)[in[4]];
            if (in[5] == '\0') {
              uVar3 = 5;
            }
            else {
              out[5] = (char)(*pp_Var2)[in[5]];
              if (in[6] == '\0') {
                uVar3 = 6;
              }
              else {
                out[6] = (char)(*pp_Var2)[in[6]];
                if (in[7] == '\0') {
                  uVar3 = 7;
                }
                else {
                  out[7] = (char)(*pp_Var2)[in[7]];
                  if (in[8] == '\0') {
                    uVar3 = 8;
                  }
                  else {
                    out[8] = (char)(*pp_Var2)[in[8]];
                    if (in[9] == '\0') {
                      uVar3 = 9;
                    }
                    else {
                      out[9] = (char)(*pp_Var2)[in[9]];
                      if (in[10] == '\0') {
                        uVar3 = 10;
                      }
                      else {
                        out[10] = (char)(*pp_Var2)[in[10]];
                        if (in[0xb] == '\0') {
                          uVar3 = 0xb;
                        }
                        else {
                          out[0xb] = (char)(*pp_Var2)[in[0xb]];
                          if (in[0xc] == '\0') {
                            uVar3 = 0xc;
                          }
                          else {
                            out[0xc] = (char)(*pp_Var2)[in[0xc]];
                            if (in[0xd] == '\0') {
                              uVar3 = 0xd;
                            }
                            else {
                              out[0xd] = (char)(*pp_Var2)[in[0xd]];
                              if (in[0xe] == '\0') {
                                uVar3 = 0xe;
                              }
                              else {
                                out[0xe] = (char)(*pp_Var2)[in[0xe]];
                                if (in[0xf] != '\0') {
                                  out[0xf] = (char)(*pp_Var2)[in[0xf]];
                                  return;
                                }
                                uVar3 = 0xf;
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
  uVar8 = ~uVar3 + 0x11;
  uVar6 = -(int)(out + uVar3) & 0xf;
  if (uVar8 < uVar6) {
    uVar6 = uVar8;
  }
  uVar4 = uVar3;
  if (uVar6 != 0) {
    do {
      out[uVar4] = '\0';
      uVar4 = uVar4 + 1;
    } while (uVar4 - uVar3 < uVar6);
    if (uVar8 == uVar6) {
      return;
    }
  }
  uVar7 = uVar8 - uVar6 >> 4;
  if (uVar7 != 0) {
    pauVar5 = (undefined1 (*) [16])(out + uVar3 + uVar6);
    uVar3 = 0;
    do {
      uVar3 = uVar3 + 1;
      *pauVar5 = (undefined1  [16])0x0;
      pauVar5 = pauVar5 + 1;
    } while (uVar3 < uVar7);
    uVar4 = uVar4 + uVar7 * 0x10;
    if (uVar8 - uVar6 == uVar7 * 0x10) {
      return;
    }
  }
  do {
    out[uVar4] = '\0';
    if (uVar4 + 1 == 0x10) {
      return;
    }
    out[uVar4 + 1] = '\0';
    uVar4 = uVar4 + 2;
  } while (uVar4 != 0x10);
  return;
}


// ClearIOStates  @ 00098760
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClearIOStates(void)

{
  return;
}


// ClearLink  @ 000bea20
void ClearLink(link_t *l)

{
  l->next = l;
  l->prev = l;
  return;
}


// ClientPrintf  @ 0008be70
void ClientPrintf(edict_t_conflict *pEdict,PRINT_TYPE ptype,char *szMsg)

{
  client_s *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int entnum@[???] */
  iVar2 = NUM_FOR_EDICT((edict_t *)pEdict);
  pcVar1 = svs.clients;
  if ((iVar2 < 1) || (svs.maxclients < iVar2)) {
    Con_Printf("tried to sprint to a non-client\n");
    return;
  }
  iVar2 = iVar2 + -1;
  if (svs.clients[iVar2].fakeclient != false) {
    return;
  }
  if (ptype == print_center) {
    MSG_WriteChar(&svs.clients[iVar2].netchan.message,0x1a);
  }
  else {
    if ((ptype != print_console) && (ptype != print_chat)) {
      Con_Printf("invalid PRINT_TYPE %i\n");
      return;
    }
    MSG_WriteByte(&svs.clients[iVar2].netchan.message,8);
  }
  MSG_WriteString(&pcVar1[iVar2].netchan.message,szMsg);
  return;
}


// ClipVelocity  @ 000b1d90
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
  fVar1 = (fVar1 * in[2] + in[1] * normal[1] + *in * *normal) * overbounce;
  fVar2 = *in - *normal * fVar1;
  *out = fVar2;
  if ((-0.1 < fVar2) && (fVar2 < 0.1)) {
    *out = 0.0;
  }
  fVar2 = in[1] - normal[1] * fVar1;
  out[1] = fVar2;
  if ((-0.1 < fVar2) && (fVar2 < 0.1)) {
    out[1] = 0.0;
  }
  fVar1 = in[2] - fVar1 * normal[2];
  out[2] = fVar1;
  if ((-0.1 < fVar1) && (fVar1 < 0.1)) {
    out[2] = 0.0;
  }
  return uVar3;
}


// CloseSecurityModule  @ 00085330
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CloseSecurityModule(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 auStack_1f8 [125];
  
                    /* Unresolved local var: cldll_func_dst_t.conflict cldstNull@[???]
                       Unresolved local var: cl_enginefunc_dst_t.conflict engdstNull@[???] */
  if (g_module.fLoaded != 0) {
    uVar2 = 0;
    do {
      uVar3 = uVar2;
      uVar1 = *(undefined4 *)((int)&PTR_NullDst_000e5904 + uVar3);
      *(undefined4 *)((int)auStack_1f8 + uVar3) =
           *(undefined4 *)((int)&PTR_NullDst_000e5900 + uVar3);
      *(undefined4 *)((int)auStack_1f8 + uVar3 + 4) = uVar1;
      uVar2 = uVar3 + 8;
    } while (uVar3 + 8 < 0x1e8);
    *(undefined4 *)((int)auStack_1f8 + uVar3 + 8) =
         *(undefined4 *)((int)&PTR_NullDst_000e5908 + uVar3);
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
  }
  return;
}


// CommatizeNumber  @ 000c2ee0
char * CommatizeNumber(int num,char *pout)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_8c [62];
  char local_4e [49];
  undefined1 local_1d;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[50] outbuf@[???] */
  Q_memset(local_8c,0,0x32);
  if (num != 0) {
                    /* Unresolved local var: char[50] tempbuf@[???]
                       Unresolved local var: int temp@[???] */
    do {
      iVar2 = num >> 0x1f;
      iVar3 = num / 1000 + iVar2;
      iVar4 = num + (iVar3 - iVar2) * -1000;
      num = iVar3 - iVar2;
      Q_strncpy(local_4e,local_8c,0x31);
      local_1d = 0;
      snprintf(local_8c,0x32,",%03i%s",iVar4,local_4e);
    } while (num != 0);
  }
  iVar2 = Q_strlen(local_8c);
  if (iVar2 < 1) {
    if (iVar2 == 0) {
LAB_000c2fb6:
      Q_strcpy(pout,"0");
      return pout;
    }
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    if ((local_8c[0] == '0') || (local_8c[0] == ',')) {
      do {
        iVar3 = iVar3 + 1;
        if (iVar3 == iVar2) goto LAB_000c2fb6;
        cVar1 = local_8c[iVar3];
      } while ((cVar1 == ',') || (cVar1 == '0'));
    }
  }
  Q_strcpy(pout,local_8c + iVar3);
  return pout;
}


// CommonLoadSecurityModule  @ 00085410
void CommonLoadSecurityModule(void *nAddrModule)

{
  uint uVar1;
  engdata_t local_88;
  
                    /* Unresolved local var: engdata_t engdata@[???] */
  if (g_modfuncs.m_nVersion == 0x43210004) {
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
           *(undefined4 *)((int)&DAT_000e5b00 + uVar1);
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x7c);
    (*g_modfuncs.m_pfnSetEngData)(&local_88);
    (*g_modfuncs.m_pfnModuleLoaded)();
    g_module.fLoaded = 1;
  }
  else {
    CloseSecurityModule();
  }
  return;
}


// ComparePath1  @ 000c2e80
int ComparePath1(char *path1,char *path2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 1;
  cVar1 = *path1;
  if ((((cVar1 != '\\') && (cVar1 != '/')) && (cVar1 != '\0')) && (iVar2 = 0, cVar1 == *path2)) {
    iVar2 = 0;
    while (((cVar1 = path1[iVar2 + 1], cVar1 != '\\' && (cVar1 != '/')) && (cVar1 != '\0'))) {
      iVar2 = iVar2 + 1;
      if (cVar1 != path2[iVar2]) {
        return 0;
      }
    }
    iVar2 = 1;
  }
  return iVar2;
}


// ConstructTutorMessageDecayBuffer  @ 000686c0
void ConstructTutorMessageDecayBuffer(int *buffer,int bufferLength)

{
  return;
}


// ContinueLoadingProgressBar  @ 000c7aa0
void ContinueLoadingProgressBar(char *loadingType,int progressPoint,float progressFraction)

{
  return;
}


// ConvertNameToLocalPlatform  @ 000960c0
char * ConvertNameToLocalPlatform(char *pchInName)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  size_t sVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  uint local_20c [127];
  undefined1 local_d;
  
  if ((*pchInName != '_') || (pchInName[1] != 'Z')) {
    pcVar1 = strchr(pchInName,0x40);
    if (pcVar1 == (char *)0x0) {
      pchInName = "unknown";
    }
    else {
                    /* Unresolved local var: char[512] szTempName@[???]
                       Unresolved local var: char * pchAt@[???]
                       Unresolved local var: char * pchClassName@[???]
                       Unresolved local var: char * pchFunctionName@[???] */
      strncpy((char *)local_20c,pchInName,0x200);
      local_d = 0;
      pcVar2 = strchr((char *)local_20c,0x40);
      pcVar1 = pcVar2 + 1;
      *pcVar2 = '\0';
      puVar8 = local_20c;
      do {
        puVar7 = puVar8;
        uVar3 = *puVar7 + 0xfefefeff & ~*puVar7;
        uVar4 = uVar3 & 0x80808080;
        puVar8 = puVar7 + 1;
      } while (uVar4 == 0);
      if ((uVar3 & 0x8080) == 0) {
        puVar8 = (uint *)((int)puVar7 + 6);
        uVar4 = uVar4 >> 0x10;
      }
      sVar5 = strlen(pcVar1);
      pchInName = ConvertNameToLocalPlatform::s_szNewName;
      snprintf(ConvertNameToLocalPlatform::s_szNewName,0x200,"_ZN%d%s%d%sEv",sVar5,pcVar1,
               (char *)((int)puVar8 +
                       ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)local_20c)),local_20c);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: void * addr@[???] */
      iVar6 = dlsym(g_rgextdll[0].lDLLHandle,ConvertNameToLocalPlatform::s_szNewName);
      puVar8 = local_20c;
      if (iVar6 == 0) {
        do {
          puVar7 = puVar8;
          uVar3 = *puVar7 + 0xfefefeff & ~*puVar7;
          uVar4 = uVar3 & 0x80808080;
          puVar8 = puVar7 + 1;
        } while (uVar4 == 0);
        if ((uVar3 & 0x8080) == 0) {
          puVar8 = (uint *)((int)puVar7 + 6);
          uVar4 = uVar4 >> 0x10;
        }
        sVar5 = strlen(pcVar1);
        pchInName = ConvertNameToLocalPlatform::s_szNewName;
        snprintf(ConvertNameToLocalPlatform::s_szNewName,0x200,"_ZN%d%s%d%sEP11CBaseEntity",sVar5,
                 pcVar1,(char *)((int)puVar8 +
                                ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)local_20c)),
                 local_20c);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: void * addr@[???] */
        iVar6 = dlsym(g_rgextdll[0].lDLLHandle,ConvertNameToLocalPlatform::s_szNewName);
        puVar8 = local_20c;
        if (iVar6 == 0) {
          do {
            puVar7 = puVar8;
            uVar3 = *puVar7 + 0xfefefeff & ~*puVar7;
            uVar4 = uVar3 & 0x80808080;
            puVar8 = puVar7 + 1;
          } while (uVar4 == 0);
          if ((uVar3 & 0x8080) == 0) {
            puVar8 = (uint *)((int)puVar7 + 6);
            uVar4 = uVar4 >> 0x10;
          }
          sVar5 = strlen(pcVar1);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: void * addr@[???] */
          pchInName = "unknown";
          snprintf(ConvertNameToLocalPlatform::s_szNewName,0x200,
                   "_ZN%d%s%d%sEP11CBaseEntityS1_8USE_TYPEf",sVar5,pcVar1,
                   (char *)((int)puVar8 +
                           ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)local_20c)),
                   local_20c);
          iVar6 = dlsym(g_rgextdll[0].lDLLHandle,ConvertNameToLocalPlatform::s_szNewName);
          if (iVar6 != 0) {
            pchInName = ConvertNameToLocalPlatform::s_szNewName;
          }
        }
      }
    }
  }
  return pchInName;
}


// CopyString  @ 0005bc50
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


// CreateEntityList  @ 0007b4e0
int CreateEntityList(SAVERESTOREDATA *pSaveData,int levelMask)

{
  ENTITYTABLE *pEVar1;
  edict_t *e;
  int iVar2;
  uint uVar3;
  string_t sVar4;
  char *pcVar5;
  int *piVar6;
  int iVar7;
  ENTITYINIT p_Var8;
  client_s *pcVar9;
  edict_t_conflict *peVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  int local_34;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int movedCount@[???]
                       Unresolved local var: int active@[???]
                       Unresolved local var: edict_t * pent@[???] */
  if (pSaveData->tableCount < 1) {
    return 0;
  }
  iVar12 = 0;
  iVar11 = 0;
LAB_0007b500:
  peVar10 = (edict_t_conflict *)0x0;
  piVar6 = (int *)((int)&pSaveData->pTable->id + iVar11);
  if (((piVar6[5] != 0) && (piVar6[3] != 0)) && (iVar7 = *piVar6, 0 < iVar7)) {
    bVar13 = (levelMask & piVar6[4]) == 0;
    if (svs.maxclients < iVar7) {
      if (bVar13) goto LAB_0007b5b0;
      iVar12 = iVar12 + 1;
      peVar10 = CreateNamedEntity(piVar6[5]);
      *(edict_t_conflict **)((int)&pSaveData->pTable->pent + iVar11) = peVar10;
      iVar7 = pSaveData->tableCount;
      iVar11 = iVar11 + 0x18;
      if (iVar7 <= iVar12) goto LAB_0007b5c2;
      goto LAB_0007b500;
    }
    pcVar9 = svs.clients + iVar7 + -1;
    peVar10 = pcVar9->edict;
    if (!bVar13) {
      if (-1 < piVar6[4]) {
        Sys_Error("ENTITY IS NOT A PLAYER: %d\n",iVar12);
        piVar6 = (int *)((int)&pSaveData->pTable->id + iVar11);
        pcVar9 = svs.clients + *piVar6 + -1;
      }
      if ((peVar10 == (edict_t_conflict *)0x0) || (pcVar9->active == false)) {
        peVar10 = (edict_t_conflict *)0x0;
        goto LAB_0007b5b0;
      }
      sVar4 = piVar6[5];
                    /* Unresolved local var: ENTITYINIT pEntityInit@[???] */
      if (sVar4 == 0) {
        Sys_Error("Bad class!!\n");
      }
      ReleaseEntityDLLFields(peVar10);
      InitEntityDLLFields(peVar10);
      pcVar5 = pr_strings;
      (peVar10->v).classname = sVar4;
      p_Var8 = GetEntityInit(pcVar5 + sVar4);
      if (p_Var8 != (ENTITYINIT)0x0) {
        (*p_Var8)(&peVar10->v);
      }
      iVar12 = iVar12 + 1;
      *(edict_t_conflict **)((int)&pSaveData->pTable->pent + iVar11) = peVar10;
      iVar7 = pSaveData->tableCount;
      iVar11 = iVar11 + 0x18;
      if (iVar7 <= iVar12) goto LAB_0007b5c2;
      goto LAB_0007b500;
    }
  }
LAB_0007b5b0:
  piVar6[1] = (int)peVar10;
  iVar12 = iVar12 + 1;
  iVar7 = pSaveData->tableCount;
  iVar11 = iVar11 + 0x18;
  if (iVar7 <= iVar12) goto LAB_0007b5c2;
  goto LAB_0007b500;
LAB_0007b5c2:
  if (iVar7 < 1) {
    local_34 = 0;
  }
  else {
    iVar11 = 0;
    local_34 = 0;
    iVar12 = 0;
    do {
      while( true ) {
        pEVar1 = pSaveData->pTable;
        e = *(edict_t **)((int)&pEVar1->pent + iVar11);
        pSaveData->currentIndex = iVar12;
        iVar2 = *(int *)((int)&pEVar1->location + iVar11);
        pSaveData->size = iVar2;
        pSaveData->pCurrentData = pSaveData->pBaseData + iVar2;
        if ((e != (edict_t *)0x0) &&
           (uVar3 = *(uint *)((int)&pEVar1->flags + iVar11), (levelMask & uVar3) != 0)) break;
LAB_0007b61b:
        iVar12 = iVar12 + 1;
        iVar11 = iVar11 + 0x18;
        if (iVar7 <= iVar12) {
          return local_34;
        }
      }
      if ((uVar3 & 0x10000000) != 0) {
        Con_DPrintf("Merging changes for global: %s\n",
                    pr_strings + *(int *)((int)&pEVar1->classname + iVar11));
        (*gEntityInterface.pfnRestore)((edict_t_conflict *)e,pSaveData,1);
        ED_Free((edict_t_conflict *)e);
        iVar7 = pSaveData->tableCount;
        goto LAB_0007b61b;
      }
      iVar7 = NUM_FOR_EDICT(e);
      Con_DPrintf("Transferring %s (%d)\n",
                  pr_strings + *(int *)((int)&pSaveData->pTable->classname + iVar11),iVar7);
      iVar7 = (*gEntityInterface.pfnRestore)((edict_t_conflict *)e,pSaveData,0);
      if (iVar7 < 0) {
LAB_0007b7a6:
        ED_Free((edict_t_conflict *)e);
        iVar7 = pSaveData->tableCount;
        goto LAB_0007b61b;
      }
      SV_LinkEdict((edict_t_conflict *)e,false);
      iVar7 = (int)&pSaveData->pTable->id + iVar11;
                    /* Unresolved local var: vec3_t point@[???] */
      if ((-1 < *(int *)(iVar7 + 0x10)) &&
         ((((e->v).movetype != 0xc || (peVar10 = (e->v).aiment, peVar10 == (edict_t_conflict *)0x0))
          || (((peVar10->v).flags & 8) == 0)))) {
        g_groupmask = (e->v).groupinfo;
        local_28 = ((e->v).absmin[0] + (e->v).absmax[0]) * 0.5;
        local_24 = ((e->v).absmin[1] + (e->v).absmax[1]) * 0.5;
        local_20 = ((e->v).absmin[2] + (e->v).absmax[2]) * 0.5;
        iVar7 = SV_PointContents(&local_28);
        if (iVar7 == -2) {
          Con_DPrintf("Suppressing %s\n",
                      pr_strings + *(int *)((int)&pSaveData->pTable->classname + iVar11));
          goto LAB_0007b7a6;
        }
        iVar7 = (int)&pSaveData->pTable->id + iVar11;
      }
      *(undefined4 *)(iVar7 + 0x10) = 0x40000000;
      iVar12 = iVar12 + 1;
      iVar11 = iVar11 + 0x18;
      iVar7 = pSaveData->tableCount;
      local_34 = local_34 + 1;
    } while (iVar12 < iVar7);
  }
  return local_34;
}


// CreateInterface  @ 000d4a50
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
                    /* WARNING: Could not recover jumptable at 0x000d4a9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar3 = (*pIVar1->m_CreateFn)();
  return pIVar3;
}


// CreateInterfaceLocal  @ 000d4980
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
                    /* WARNING: Could not recover jumptable at 0x000d49cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pIVar3 = (*pIVar1->m_CreateFn)();
  return pIVar3;
}


// CreateNamedEntity  @ 0008d8f0
edict_t_conflict * CreateNamedEntity(int className)

{
  edict_t_conflict *ed;
  ENTITYINIT p_Var1;
  edict_t_conflict *peVar2;
  
                    /* Unresolved local var: edict_t.conflict * pedict@[???]
                       Unresolved local var: ENTITYINIT pEntityInit@[???] */
  if (className == 0) {
    Sys_Error("Spawned a NULL entity!");
  }
  ed = ED_Alloc();
  (ed->v).classname = className;
  p_Var1 = GetEntityInit(pr_strings + className);
  if (p_Var1 == (ENTITYINIT)0x0) {
    peVar2 = (edict_t_conflict *)0x0;
    ED_Free(ed);
    Con_DPrintf("Can\'t create entity: %s\n",pr_strings + className);
  }
  else {
    (*p_Var1)(&ed->v);
    peVar2 = ed;
  }
  return peVar2;
}


// CrossProduct  @ 000805e0
void CrossProduct(vec_t *v1,vec_t *v2,vec_t *cross)

{
  *cross = v1[1] * v2[2] - v1[2] * v2[1];
  cross[1] = v1[2] * *v2 - *v1 * v2[2];
  cross[2] = *v1 * v2[1] - v1[1] * *v2;
  return;
}


// DirectoryCopy  @ 0007bc70
void DirectoryCopy(char *pPath,FileHandle_t pFile)

{
  char *pInput;
  FileHandle_t file;
  uint uVar1;
  uint size;
  undefined1 local_628 [1024];
  char local_228 [260];
  char local_124 [260];
  uint local_20 [4];
  
                    /* Unresolved local var: char * findfn@[???]
                       Unresolved local var: char[260] basefindfn@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: FILE * pCopy@[???]
                       Unresolved local var: char[260] szName@[???] */
  pInput = Sys_FindFirst(pPath,local_228);
  if (pInput != (char *)0x0) {
    do {
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
      snprintf(local_124,0x104,"%s%s",Host_SaveGameDirectory::szDirectory,pInput);
      COM_FixSlashes(local_124);
      file = FS_OpenPathID(local_124,"rb","GAMECONFIG");
      uVar1 = 0;
      if (file != (FileHandle_t)0x0) {
        uVar1 = FS_Size(file);
      }
      local_20[0] = uVar1;
      FS_Write(pInput,0x104,1,pFile);
      FS_Write(local_20,4,1,pFile);
                    /* Unresolved local var: char[1024] buf@[???]
                       Unresolved local var: int size@[???] */
      for (uVar1 = local_20[0]; 0 < (int)uVar1; uVar1 = uVar1 - size) {
        size = 0x400;
        if ((int)uVar1 < 0x401) {
          size = uVar1;
        }
        FS_Read(local_628,size,1,file);
        FS_Write(local_628,size,1,pFile);
      }
      FS_Close(file);
      pInput = Sys_FindNext(local_228);
    } while (pInput != (char *)0x0);
  }
  Sys_FindClose();
  return;
}


// DirectoryCount  @ 0007c7b0
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


// DirectoryExtract  @ 0007c5f0
void DirectoryExtract(FileHandle_t pFile,int fileCount)

{
  char *pcVar1;
  char *pcVar2;
  FileHandle_t pOutput;
  int iVar3;
  char local_22c [259];
  undefined1 local_129;
  char local_124 [260];
  int local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: FILE * pCopy@[???]
                       Unresolved local var: char[260] szName@[???]
                       Unresolved local var: char[260] fileName@[???] */
  if (0 < fileCount) {
    iVar3 = 0;
    do {
                    /* Unresolved local var: char * pchFileExtension@[???] */
      FS_Read(local_22c,0x104,1,pFile);
      local_129 = 0;
      FS_Read(local_20,4,1,pFile);
      pcVar1 = COM_LastFileExtension(local_22c);
      if (pcVar1 == (char *)0x0) {
LAB_0007c68f:
        FS_Seek(pFile,local_20[0],FILESYSTEM_SEEK_CURRENT);
      }
      else {
        pcVar2 = Q_strstr(local_22c,"\\");
        if (pcVar2 != (char *)0x0) goto LAB_0007c68f;
        pcVar2 = Q_strstr(local_22c,":");
        if (pcVar2 != (char *)0x0) goto LAB_0007c68f;
        pcVar2 = Q_strstr(local_22c,"..");
        if (pcVar2 != (char *)0x0) goto LAB_0007c68f;
        pcVar2 = Q_strstr(local_22c,"~");
        if ((((pcVar2 != (char *)0x0) || (local_22c[0] == '/')) || (*pcVar1 != 'H')) ||
           (pcVar1[1] != 'L')) goto LAB_0007c68f;
        pcVar1 = Host_SaveGameDirectory();
        snprintf(local_124,0x104,"%s%s",pcVar1,local_22c);
        COM_FixSlashes(local_124);
        pOutput = FS_OpenPathID(local_124,"wb","GAMECONFIG");
        FileCopy(pOutput,pFile,local_20[0]);
        FS_Close(pOutput);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != fileCount);
  }
  return;
}


// DispatchDirectUserMsg  @ 00068560
int DispatchDirectUserMsg(char *pszName,int iSize,void *pBuf)

{
  return 0;
}


// DoesSphereIntersect  @ 000949d0
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
                        ((fVar7 * fVar7 + fVar6 * fVar6 + fVar4 * fVar4) - fSphereRadiusSquared) *
                        (fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1) * 4.0);
}


// EngCheckParm  @ 00091530
int EngCheckParm(char *pchCmdLineToken,char **pchNextVal)

{
  int iVar1;
  char *local_14;
  char **local_10 [4];
  
  local_14 = pchCmdLineToken;
  local_10[0] = pchNextVal;
                    /* Unresolved local var: int i@[DW_OP_reg0(EAX)] */
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


// EngineFprintf  @ 00096d30
void EngineFprintf(void *pfile,char *szFmt,...)

{
  AlertMessage(at_console,"EngineFprintf:  Obsolete API\n");
  return;
}


// EngineWrapper::DemoUpdateClientData  @ 00098be0
/* DWARF original prototype: void DemoUpdateClientData(EngineWrapper * this, client_data_s * cdat)
    */

void __thiscall EngineWrapper::DemoUpdateClientData(EngineWrapper *this,client_data_s *cdat)

{
  return;
}


// EngineWrapper::EngineWrapper  @ 000997f0
/* DWARF original prototype: void EngineWrapper(EngineWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall EngineWrapper::EngineWrapper(EngineWrapper *this,int __in_chrg,void **__vtt_parm)

{
  _func_int_varargs **pp_Var1;
  void **in_stack_ffffffec;
  
  (this->super_IEngineWrapper)._vptr_IEngineWrapper =
       (_func_int_varargs **)&PTR__IEngineWrapper_000e8888;
  BaseSystemModule::BaseSystemModule(&this->super_BaseSystemModule,__in_chrg + 4,in_stack_ffffffec);
  pp_Var1 = *(_func_int_varargs ***)__in_chrg;
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = pp_Var1;
  *(undefined4 *)&this->super_BaseSystemModule = *(undefined4 *)(__in_chrg + 0xc);
  *(undefined4 *)(pp_Var1[-3] + -4 + (int)((this->super_BaseSystemModule).m_Name + -0x1c)) =
       *(undefined4 *)(__in_chrg + 0x10);
  return;
}


// EngineWrapper::EngineWrapper  @ 00099840
/* DWARF original prototype: void EngineWrapper(EngineWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall EngineWrapper::EngineWrapper(EngineWrapper *this,int __in_chrg,void **__vtt_parm)

{
  void **in_stack_ffffffec;
  
  *(undefined ***)&this->super_BaseSystemModule = &PTR__ISystemModule_000e8828;
  (this->super_IEngineWrapper)._vptr_IEngineWrapper =
       (_func_int_varargs **)&PTR__IEngineWrapper_000e8888;
  BaseSystemModule::BaseSystemModule(&this->super_BaseSystemModule,0xe8214,in_stack_ffffffec);
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = (_func_int_varargs **)0xe824c;
  *(undefined4 *)&this->super_BaseSystemModule = 0xe830c;
  return;
}


// EngineWrapper::ExecuteCommand  @ 0009a690
/* virtual thunk to EngineWrapper::ExecuteCommand(int, char*) */

void __thiscall EngineWrapper::ExecuteCommand(EngineWrapper *this,int param_1,char *param_2)

{
  ExecuteCommand((EngineWrapper *)
                 ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-7] + -4 +
                 (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1,param_2);
  return;
}


// EngineWrapper::ExecuteCommand  @ 0009a6a0
/* non-virtual thunk to EngineWrapper::ExecuteCommand(int, char*) */

void __thiscall EngineWrapper::ExecuteCommand(EngineWrapper *this,int param_1,char *param_2)

{
  ExecuteCommand((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1,
                 param_2);
  return;
}


// EngineWrapper::ExecuteCommand  @ 0009a6b0
/* DWARF original prototype: void ExecuteCommand(EngineWrapper * this, int commandID, char *
   commandLine) */

void __thiscall EngineWrapper::ExecuteCommand(EngineWrapper *this,int commandID,char *commandLine)

{
  BaseSystemModule::ExecuteCommand(&this->super_BaseSystemModule,commandID,commandLine);
  return;
}


// EngineWrapper::GetCvarFloat  @ 00099250
/* DWARF original prototype: float GetCvarFloat(EngineWrapper * this, char * szName) */

float __thiscall EngineWrapper::GetCvarFloat(EngineWrapper *this,char *szName)

{
  float fVar1;
  cvar_t *pcVar2;
  
                    /* Unresolved local var: cvar_t * cv@[DW_OP_reg0(EAX)] */
  pcVar2 = Cvar_FindVar(szName);
  fVar1 = 0.0;
  if (pcVar2 != (cvar_t *)0x0) {
    fVar1 = pcVar2->value;
  }
  return fVar1;
}


// EngineWrapper::GetCvarString  @ 00099220
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


// EngineWrapper::GetName  @ 0009a5a0
/* virtual thunk to EngineWrapper::GetName() */

void __thiscall EngineWrapper::GetName(EngineWrapper *this)

{
  GetName((EngineWrapper *)
          ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0xe] + -4 +
          (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetName  @ 0009a5b0
/* non-virtual thunk to EngineWrapper::GetName() */

void __thiscall EngineWrapper::GetName(EngineWrapper *this)

{
  GetName((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetName  @ 0009a5c0
/* DWARF original prototype: char * GetName(EngineWrapper * this) */

char * __thiscall EngineWrapper::GetName(EngineWrapper *this)

{
  char *pcVar1;
  
  pcVar1 = BaseSystemModule::GetName(&this->super_BaseSystemModule);
  return pcVar1;
}


// EngineWrapper::GetSerial  @ 0009a570
/* virtual thunk to EngineWrapper::GetSerial() */

void __thiscall EngineWrapper::GetSerial(EngineWrapper *this)

{
  GetSerial((EngineWrapper *)
            ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0xb] + -4 +
            (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetSerial  @ 0009a580
/* non-virtual thunk to EngineWrapper::GetSerial() */

void __thiscall EngineWrapper::GetSerial(EngineWrapper *this)

{
  GetSerial((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetSerial  @ 0009a590
/* DWARF original prototype: int GetSerial(EngineWrapper * this) */

int __thiscall EngineWrapper::GetSerial(EngineWrapper *this)

{
  int iVar1;
  
  iVar1 = BaseSystemModule::GetSerial(&this->super_BaseSystemModule);
  return iVar1;
}


// EngineWrapper::GetState  @ 0009a5d0
/* virtual thunk to EngineWrapper::GetState() */

void __thiscall EngineWrapper::GetState(EngineWrapper *this)

{
  GetState((EngineWrapper *)
           ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0xf] + -4 +
           (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetState  @ 0009a5e0
/* non-virtual thunk to EngineWrapper::GetState() */

void __thiscall EngineWrapper::GetState(EngineWrapper *this)

{
  GetState((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetState  @ 0009a5f0
/* DWARF original prototype: int GetState(EngineWrapper * this) */

int __thiscall EngineWrapper::GetState(EngineWrapper *this)

{
  int iVar1;
  
  iVar1 = BaseSystemModule::GetState(&this->super_BaseSystemModule);
  return iVar1;
}


// EngineWrapper::GetStatusLine  @ 00098b90
/* virtual thunk to EngineWrapper::GetStatusLine() */

void __thiscall EngineWrapper::GetStatusLine(EngineWrapper *this)

{
  GetStatusLine((EngineWrapper *)
                ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0xc] + -4 +
                (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetStatusLine  @ 00098ba0
/* non-virtual thunk to EngineWrapper::GetStatusLine() */

void __thiscall EngineWrapper::GetStatusLine(EngineWrapper *this)

{
  GetStatusLine((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetStatusLine  @ 00098bb0
/* DWARF original prototype: char * GetStatusLine(EngineWrapper * this) */

char * __thiscall EngineWrapper::GetStatusLine(EngineWrapper *this)

{
  return "No status available.\n";
}


// EngineWrapper::GetSystem  @ 0009a540
/* virtual thunk to EngineWrapper::GetSystem() */

void __thiscall EngineWrapper::GetSystem(EngineWrapper *this)

{
  GetSystem((EngineWrapper *)
            ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-10] + -4 +
            (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetSystem  @ 0009a550
/* non-virtual thunk to EngineWrapper::GetSystem() */

void __thiscall EngineWrapper::GetSystem(EngineWrapper *this)

{
  GetSystem((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetSystem  @ 0009a560
/* DWARF original prototype: IBaseSystem * GetSystem(EngineWrapper * this) */

IBaseSystem * __thiscall EngineWrapper::GetSystem(EngineWrapper *this)

{
  IBaseSystem *pIVar1;
  
  pIVar1 = BaseSystemModule::GetSystem(&this->super_BaseSystemModule);
  return pIVar1;
}


// EngineWrapper::GetTraceEntity  @ 00098c40
/* DWARF original prototype: int GetTraceEntity(EngineWrapper * this) */

int __thiscall EngineWrapper::GetTraceEntity(EngineWrapper *this)

{
  return 0;
}


// EngineWrapper::GetType  @ 00098b60
/* virtual thunk to EngineWrapper::GetType() */

void __thiscall EngineWrapper::GetType(EngineWrapper *this)

{
  GetType((EngineWrapper *)
          ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0xd] + -4 +
          (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetType  @ 00098b70
/* non-virtual thunk to EngineWrapper::GetType() */

void __thiscall EngineWrapper::GetType(EngineWrapper *this)

{
  GetType((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetType  @ 00098b80
/* DWARF original prototype: char * GetType(EngineWrapper * this) */

char * __thiscall EngineWrapper::GetType(EngineWrapper *this)

{
  return "enginewrapper002";
}


// EngineWrapper::GetVersion  @ 0009a600
/* virtual thunk to EngineWrapper::GetVersion() */

void __thiscall EngineWrapper::GetVersion(EngineWrapper *this)

{
  GetVersion((EngineWrapper *)
             ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0x10] + -4 +
             (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::GetVersion  @ 0009a610
/* non-virtual thunk to EngineWrapper::GetVersion() */

void __thiscall EngineWrapper::GetVersion(EngineWrapper *this)

{
  GetVersion((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::GetVersion  @ 0009a620
/* DWARF original prototype: int GetVersion(EngineWrapper * this) */

int __thiscall EngineWrapper::GetVersion(EngineWrapper *this)

{
  int iVar1;
  
  iVar1 = BaseSystemModule::GetVersion(&this->super_BaseSystemModule);
  return iVar1;
}


// EngineWrapper::GetViewAngles  @ 00098bd0
/* DWARF original prototype: bool GetViewAngles(EngineWrapper * this, float * angles) */

bool __thiscall EngineWrapper::GetViewAngles(EngineWrapper *this,float *angles)

{
  return false;
}


// EngineWrapper::GetViewOrigin  @ 00098bc0
/* DWARF original prototype: bool GetViewOrigin(EngineWrapper * this, float * origin) */

bool __thiscall EngineWrapper::GetViewOrigin(EngineWrapper *this,float *origin)

{
  return false;
}


// EngineWrapper::HudWeaponAnim  @ 00098c00
/* DWARF original prototype: void HudWeaponAnim(EngineWrapper * this, int iAnim, int body) */

void __thiscall EngineWrapper::HudWeaponAnim(EngineWrapper *this,int iAnim,int body)

{
  return;
}


// EngineWrapper::Init  @ 0009a630
/* virtual thunk to EngineWrapper::Init(IBaseSystem*, int, char*) */

void __thiscall
EngineWrapper::Init(EngineWrapper *this,IBaseSystem *param_1,int param_2,char *param_3)

{
  Init((EngineWrapper *)
       ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-4] + -4 +
       (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1,param_2,param_3);
  return;
}


// EngineWrapper::Init  @ 0009a640
/* non-virtual thunk to EngineWrapper::Init(IBaseSystem*, int, char*) */

void __thiscall
EngineWrapper::Init(EngineWrapper *this,IBaseSystem *param_1,int param_2,char *param_3)

{
  Init((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1,param_2,
       param_3);
  return;
}


// EngineWrapper::Init  @ 0009a650
/* DWARF original prototype: bool Init(EngineWrapper * this, IBaseSystem * system, int serial, char
   * name) */

bool __thiscall EngineWrapper::Init(EngineWrapper *this,IBaseSystem *system,int serial,char *name)

{
  bool bVar1;
  
  bVar1 = BaseSystemModule::Init(&this->super_BaseSystemModule,system,serial,name);
  return bVar1;
}


// EngineWrapper::ReceiveSignal  @ 0009a4b0
/* virtual thunk to EngineWrapper::ReceiveSignal(ISystemModule*, unsigned int, void*) */

void __thiscall
EngineWrapper::ReceiveSignal(EngineWrapper *this,ISystemModule *param_1,uint param_2,void *param_3)

{
  ReceiveSignal((EngineWrapper *)
                ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-6] + -4 +
                (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1,param_2,param_3);
  return;
}


// EngineWrapper::ReceiveSignal  @ 0009a4c0
/* non-virtual thunk to EngineWrapper::ReceiveSignal(ISystemModule*, unsigned int, void*) */

void __thiscall
EngineWrapper::ReceiveSignal(EngineWrapper *this,ISystemModule *param_1,uint param_2,void *param_3)

{
  ReceiveSignal((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1,
                param_2,param_3);
  return;
}


// EngineWrapper::ReceiveSignal  @ 0009a4d0
/* DWARF original prototype: void ReceiveSignal(EngineWrapper * this, ISystemModule * module, uint
   signal, void * data) */

void __thiscall
EngineWrapper::ReceiveSignal(EngineWrapper *this,ISystemModule *module,uint signal,void *data)

{
  BaseSystemModule::ReceiveSignal(&this->super_BaseSystemModule,module,signal,data);
  return;
}


// EngineWrapper::RegisterListener  @ 0009a4e0
/* virtual thunk to EngineWrapper::RegisterListener(ISystemModule*) */

void __thiscall EngineWrapper::RegisterListener(EngineWrapper *this,ISystemModule *param_1)

{
  RegisterListener((EngineWrapper *)
                   ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-8] + -4 +
                   (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1);
  return;
}


// EngineWrapper::RegisterListener  @ 0009a4f0
/* non-virtual thunk to EngineWrapper::RegisterListener(ISystemModule*) */

void __thiscall EngineWrapper::RegisterListener(EngineWrapper *this,ISystemModule *param_1)

{
  RegisterListener((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1
                  );
  return;
}


// EngineWrapper::RegisterListener  @ 0009a500
/* DWARF original prototype: void RegisterListener(EngineWrapper * this, ISystemModule * module) */

void __thiscall EngineWrapper::RegisterListener(EngineWrapper *this,ISystemModule *module)

{
  BaseSystemModule::RegisterListener(&this->super_BaseSystemModule,module);
  return;
}


// EngineWrapper::RemoveListener  @ 0009a510
/* virtual thunk to EngineWrapper::RemoveListener(ISystemModule*) */

void __thiscall EngineWrapper::RemoveListener(EngineWrapper *this,ISystemModule *param_1)

{
  RemoveListener((EngineWrapper *)
                 ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-9] + -4 +
                 (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1);
  return;
}


// EngineWrapper::RemoveListener  @ 0009a520
/* non-virtual thunk to EngineWrapper::RemoveListener(ISystemModule*) */

void __thiscall EngineWrapper::RemoveListener(EngineWrapper *this,ISystemModule *param_1)

{
  RemoveListener((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1);
  return;
}


// EngineWrapper::RemoveListener  @ 0009a530
/* DWARF original prototype: void RemoveListener(EngineWrapper * this, ISystemModule * module) */

void __thiscall EngineWrapper::RemoveListener(EngineWrapper *this,ISystemModule *module)

{
  BaseSystemModule::RemoveListener(&this->super_BaseSystemModule,module);
  return;
}


// EngineWrapper::RunFrame  @ 0009a660
/* virtual thunk to EngineWrapper::RunFrame(double) */

void __thiscall EngineWrapper::RunFrame(EngineWrapper *this,double param_1)

{
  RunFrame((EngineWrapper *)
           ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-5] + -4 +
           (int)((this->super_BaseSystemModule).m_Name + -0x1c)),param_1);
  return;
}


// EngineWrapper::RunFrame  @ 0009a670
/* non-virtual thunk to EngineWrapper::RunFrame(double) */

void __thiscall EngineWrapper::RunFrame(EngineWrapper *this,double param_1)

{
  RunFrame((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),param_1);
  return;
}


// EngineWrapper::RunFrame  @ 0009a680
/* DWARF original prototype: void RunFrame(EngineWrapper * this, double time) */

void __thiscall EngineWrapper::RunFrame(EngineWrapper *this,double time)

{
  BaseSystemModule::RunFrame(&this->super_BaseSystemModule,time);
  return;
}


// EngineWrapper::SetCvar  @ 00099200
/* DWARF original prototype: void SetCvar(EngineWrapper * this, char * szName, char * szValue) */

void __thiscall EngineWrapper::SetCvar(EngineWrapper *this,char *szName,char *szValue)

{
  Cvar_Set(szName,szValue);
  return;
}


// EngineWrapper::ShutDown  @ 0009a6c0
/* virtual thunk to EngineWrapper::ShutDown() */

void __thiscall EngineWrapper::ShutDown(EngineWrapper *this)

{
  ShutDown((EngineWrapper *)
           ((this->super_IEngineWrapper)._vptr_IEngineWrapper[-0x11] + -4 +
           (int)((this->super_BaseSystemModule).m_Name + -0x1c)));
  return;
}


// EngineWrapper::ShutDown  @ 0009a6d0
/* non-virtual thunk to EngineWrapper::ShutDown() */

void __thiscall EngineWrapper::ShutDown(EngineWrapper *this)

{
  ShutDown((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4));
  return;
}


// EngineWrapper::ShutDown  @ 0009a6e0
/* DWARF original prototype: void ShutDown(EngineWrapper * this) */

void __thiscall EngineWrapper::ShutDown(EngineWrapper *this)

{
  BaseSystemModule::ShutDown(&this->super_BaseSystemModule);
  return;
}


// EngineWrapper::ValidStuffText  @ 00098c30
/* DWARF original prototype: bool ValidStuffText(EngineWrapper * this, char * pMsg) */

bool __thiscall EngineWrapper::ValidStuffText(EngineWrapper *this,char *pMsg)

{
  return true;
}


// EngineWrapper::~EngineWrapper  @ 00099100
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


// EngineWrapper::~EngineWrapper  @ 00099110
/* non-virtual thunk to EngineWrapper::~EngineWrapper() */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~EngineWrapper((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),
                 in_stack_00000008,in_stack_0000000c);
  return;
}


// EngineWrapper::~EngineWrapper  @ 00099120
/* DWARF original prototype: void ~EngineWrapper(EngineWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this,int __in_chrg,void **__vtt_parm)

{
  void **in_stack_ffffffec;
  
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = (_func_int_varargs **)0xe824c;
  *(undefined4 *)&this->super_BaseSystemModule = 0xe830c;
  BaseSystemModule::~BaseSystemModule(&this->super_BaseSystemModule,0xe8214,in_stack_ffffffec);
  (this->super_IEngineWrapper)._vptr_IEngineWrapper =
       (_func_int_varargs **)&PTR__IEngineWrapper_000e8888;
  *(undefined ***)&this->super_BaseSystemModule = &PTR__IBaseInterface_000e7cf0;
  return;
}


// EngineWrapper::~EngineWrapper  @ 00099500
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


// EngineWrapper::~EngineWrapper  @ 00099510
/* non-virtual thunk to EngineWrapper::~EngineWrapper() */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~EngineWrapper((EngineWrapper *)((int)&this[-1].super_BaseSystemModule.m_SystemTime + 4),
                 in_stack_00000008,in_stack_0000000c);
  return;
}


// EngineWrapper::~EngineWrapper  @ 00099520
/* DWARF original prototype: void ~EngineWrapper(EngineWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this,int __in_chrg,void **__vtt_parm)

{
  void **in_stack_ffffffec;
  
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = (_func_int_varargs **)0xe824c;
  *(undefined4 *)&this->super_BaseSystemModule = 0xe830c;
  BaseSystemModule::~BaseSystemModule(&this->super_BaseSystemModule,0xe8214,in_stack_ffffffec);
  (this->super_IEngineWrapper)._vptr_IEngineWrapper =
       (_func_int_varargs **)&PTR__IEngineWrapper_000e8888;
  *(undefined ***)&this->super_BaseSystemModule = &PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// EngineWrapper::~EngineWrapper  @ 00099880
/* DWARF original prototype: void ~EngineWrapper(EngineWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall EngineWrapper::~EngineWrapper(EngineWrapper *this,int __in_chrg,void **__vtt_parm)

{
  _func_int_varargs **pp_Var1;
  void **in_stack_ffffffec;
  
  pp_Var1 = *(_func_int_varargs ***)__in_chrg;
  (this->super_IEngineWrapper)._vptr_IEngineWrapper = pp_Var1;
  *(undefined4 *)&this->super_BaseSystemModule = *(undefined4 *)(__in_chrg + 0xc);
  *(undefined4 *)(pp_Var1[-3] + -4 + (int)((this->super_BaseSystemModule).m_Name + -0x1c)) =
       *(undefined4 *)(__in_chrg + 0x10);
  BaseSystemModule::~BaseSystemModule(&this->super_BaseSystemModule,__in_chrg + 4,in_stack_ffffffec)
  ;
  (this->super_IEngineWrapper)._vptr_IEngineWrapper =
       (_func_int_varargs **)&PTR__IEngineWrapper_000e8888;
  return;
}


// EntOffsetOfPEntity  @ 00092260
int EntOffsetOfPEntity(edict_t *pEdict)

{
  return (int)pEdict - (int)sv.edicts;
}


// EntityInSolid  @ 0007b440
int EntityInSolid(edict_t *pent)

{
  edict_t_conflict *peVar1;
  int iVar2;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t point@[???] */
  if ((((pent->v).movetype == 0xc) && (peVar1 = (pent->v).aiment, peVar1 != (edict_t_conflict *)0x0)
      ) && (((peVar1->v).flags & 8) != 0)) {
    return 0;
  }
  g_groupmask = (pent->v).groupinfo;
  local_18 = ((pent->v).absmin[0] + (pent->v).absmax[0]) * 0.5;
  local_14 = ((pent->v).absmin[1] + (pent->v).absmax[1]) * 0.5;
  local_10 = ((pent->v).absmin[2] + (pent->v).absmax[2]) * 0.5;
  iVar2 = SV_PointContents(&local_18);
  return (uint)(iVar2 == -2);
}


// EntityInit  @ 00079c40
void EntityInit(edict_t *pEdict,int className)

{
  char *pcVar1;
  ENTITYINIT UNRECOVERED_JUMPTABLE;
  
                    /* Unresolved local var: ENTITYINIT pEntityInit@[???] */
  if (className == 0) {
    Sys_Error("Bad class!!\n");
  }
  ReleaseEntityDLLFields((edict_t_conflict *)pEdict);
  InitEntityDLLFields((edict_t_conflict *)pEdict);
  pcVar1 = pr_strings;
  (pEdict->v).classname = className;
  UNRECOVERED_JUMPTABLE = GetEntityInit(pcVar1 + className);
  if (UNRECOVERED_JUMPTABLE != (ENTITYINIT)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00079c92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(&pEdict->v);
    return;
  }
  return;
}


// EntityPatchRead  @ 0007ac60
void EntityPatchRead(SAVERESTOREDATA *pSaveData,char *level)

{
  FileHandle_t file;
  int iVar1;
  char local_128 [260];
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: char[260] name@[???]
                       Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int entityId@[???] */
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
  snprintf(local_128,0x104,"%s%s.HL3",Host_SaveGameDirectory::szDirectory,level);
  COM_FixSlashes(local_128);
  file = FS_OpenPathID(local_128,"rb","GAMECONFIG");
  if (file != (FileHandle_t)0x0) {
    FS_Read(&local_24,4,1,file);
    if (0 < local_24) {
      iVar1 = 0;
      do {
        iVar1 = iVar1 + 1;
        FS_Read(local_20,4,1,file);
        pSaveData->pTable[local_20[0]].flags = 0x40000000;
      } while (iVar1 < local_24);
    }
    FS_Close(file);
  }
  return;
}


// EntityPatchWrite  @ 0007a3a0
void EntityPatchWrite(SAVERESTOREDATA *pSaveData,char *level)

{
  FileHandle_t file;
  ENTITYTABLE *pEVar1;
  int iVar2;
  char local_140 [260];
  int local_3c [4];
  int local_2c [7];
  
                    /* Unresolved local var: char[260] name@[???]
                       Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int size@[???] */
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
  snprintf(local_140,0x104,"%s%s.HL3",Host_SaveGameDirectory::szDirectory,level);
  COM_FixSlashes(local_140);
  file = FS_OpenPathID(local_140,"wb","GAMECONFIG");
  if (file != (FileHandle_t)0x0) {
    local_2c[0] = 0;
    local_3c[0] = 0;
    if (0 < pSaveData->tableCount) {
      pEVar1 = pSaveData->pTable;
      local_2c[0] = 0;
      local_3c[0] = 0;
      do {
        local_2c[0] = (local_2c[0] + 1) - (uint)((pEVar1->flags & 0x40000000U) == 0);
        local_3c[0] = local_3c[0] + 1;
        pEVar1 = pEVar1 + 1;
      } while (local_3c[0] != pSaveData->tableCount);
    }
    FS_Write(local_2c,4,1,file);
    iVar2 = pSaveData->tableCount;
    local_3c[0] = 0;
    if (0 < iVar2) {
      do {
        while ((pSaveData->pTable[local_3c[0]].flags & 0x40000000) != 0) {
          FS_Write(local_3c,4,1,file);
          iVar2 = pSaveData->tableCount;
          local_3c[0] = local_3c[0] + 1;
          if (iVar2 <= local_3c[0]) goto LAB_0007a536;
        }
        local_3c[0] = local_3c[0] + 1;
      } while (local_3c[0] < iVar2);
    }
LAB_0007a536:
    FS_Close(file);
  }
  return;
}


// EntryInTable  @ 0007b350
int EntryInTable(SAVERESTOREDATA *pSaveData,char *pMapName,int index)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = index + 1;
  iVar3 = -1;
  if (iVar1 < pSaveData->connectionCount) {
    while (iVar2 = Q_strcmp(pSaveData->levelList[iVar1].mapName,pMapName), iVar3 = iVar1, iVar2 != 0
          ) {
      iVar1 = iVar1 + 1;
      if (pSaveData->connectionCount <= iVar1) {
        return -1;
      }
    }
  }
  return iVar3;
}


// F  @ 00097d50
void F(IEngineAPI **api)

{
  CreateInterfaceFn p_Var1;
  IBaseInterface *pIVar2;
  
  p_Var1 = Sys_GetFactoryThis();
  pIVar2 = (*p_Var1)("VENGINE_LAUNCHER_API_VERSION002",(int *)0x0);
  *api = (IEngineAPI *)pIVar2;
  return;
}


// FIsBlob  @ 0006f4d0
char FIsBlob(char *pstFileName)

{
  return '\0';
}


// FileCopy  @ 0007bbf0
void FileCopy(FileHandle_t pOutput,FileHandle_t pInput,int fileSize)

{
  int size;
  undefined1 local_41c [1036];
  
                    /* Unresolved local var: char[1024] buf@[???]
                       Unresolved local var: int size@[???] */
  if (0 < fileSize) {
    do {
      size = 0x400;
      if (fileSize < 0x401) {
        size = fileSize;
      }
      fileSize = fileSize - size;
      FS_Read(local_41c,size,1,pInput);
      FS_Write(local_41c,size,1,pOutput);
    } while (0 < fileSize);
  }
  return;
}


// FileSize  @ 0007bbd0
int FileSize(FileHandle_t pFile)

{
  uint uVar1;
  
  if (pFile != (FileHandle_t)0x0) {
    uVar1 = FS_Size(pFile);
    return uVar1;
  }
  return 0;
}


// FindAddressInTable  @ 00096080
char * FindAddressInTable(extensiondll_t *pDll,uint32 function)

{
  int iVar1;
  char *pcVar2;
  undefined1 local_1c [8];
  char *local_14;
  
                    /* Unresolved local var: Dl_info addrInfo@[???] */
  iVar1 = dladdr(function,local_1c);
  pcVar2 = (char *)0x0;
  if (iVar1 != 0) {
    pcVar2 = local_14;
  }
  return pcVar2;
}


// FindEntityByString  @ 0008dbb0
edict_t_conflict *
FindEntityByString(edict_t_conflict *pEdictStartSearchAfter,char *pszField,char *pszValue)

{
  edict_t_conflict *peVar1;
  int iVar2;
  int iVar3;
  edict_t_conflict *peVar4;
  int iVar5;
  char *s1;
  int iVar6;
  int local_28;
  
                    /* Unresolved local var: int iField@[???] */
  iVar2 = iGetIndex(pszField);
  peVar4 = (edict_t_conflict *)0x0;
  if ((iVar2 != -1) && (pszValue != (char *)0x0)) {
    iVar5 = 1;
    if (pEdictStartSearchAfter != (edict_t_conflict *)0x0) {
      iVar5 = NUM_FOR_EDICT((edict_t *)pEdictStartSearchAfter);
      iVar5 = iVar5 + 1;
    }
                    /* Unresolved local var: int e@[???]
                       Unresolved local var: char * t@[???]
                       Unresolved local var: edict_t.conflict * ed@[???] */
    peVar4 = sv.edicts;
    if (iVar5 < sv.num_edicts) {
      iVar6 = iVar5 * 0x324;
      local_28 = sv.num_edicts;
      do {
        peVar1 = (edict_t_conflict *)((int)peVar4->leafnums + iVar6 + -0x18);
        if (peVar1->free == 0) {
          s1 = pr_strings + *(int *)((int)(peVar1->v).origin + iVar2 + -8);
          if ((s1 != (char *)0x0) && (pr_strings != s1)) {
            iVar3 = Q_strcmp(s1,pszValue);
            if (iVar3 == 0) {
              return peVar1;
            }
            local_28 = sv.num_edicts;
            peVar4 = sv.edicts;
          }
        }
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x324;
      } while (iVar5 < local_28);
    }
  }
  return peVar4;
}


// FindEntityByVars  @ 00092390
edict_t_conflict * FindEntityByVars(entvars_t *pvars)

{
  edict_t_conflict *peVar1;
  edict_t_conflict *peVar2;
  edict_t_conflict *peVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  peVar3 = (edict_t_conflict *)0x0;
                    /* Unresolved local var: edict_t.conflict * pEdict@[???] */
  if ((0 < sv.num_edicts) && (peVar3 = sv.edicts, pvars != &(sv.edicts)->v)) {
    iVar4 = 0;
    peVar1 = sv.edicts;
    do {
      peVar3 = peVar1 + 1;
      iVar4 = iVar4 + 1;
      if (iVar4 == sv.num_edicts) {
        return (edict_t_conflict *)0x0;
      }
      peVar2 = peVar1 + 1;
      peVar1 = peVar3;
    } while (pvars != &peVar2->v);
  }
  return peVar3;
}


// FindEntityInSphere  @ 0008d720
edict_t_conflict * FindEntityInSphere(edict_t_conflict *pEdictStartSearchAfter,float *org,float rad)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  edict_t_conflict *peVar6;
  client_s *pcVar7;
  
                    /* Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: float eorg@[???]
                       Unresolved local var: int e@[???]
                       Unresolved local var: int i@[DW_OP_reg1(ECX)]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float distSquared@[???] */
  iVar5 = 1;
  if (pEdictStartSearchAfter != (edict_t_conflict *)0x0) {
    iVar5 = NUM_FOR_EDICT((edict_t *)pEdictStartSearchAfter);
    iVar5 = iVar5 + 1;
  }
  fVar4 = rad * rad;
  if (iVar5 < sv.num_edicts) {
    peVar6 = sv.edicts + iVar5;
    pcVar7 = svs.clients + iVar5 + -1;
    do {
      if (((peVar6->free == 0) && ((peVar6->v).classname != 0)) &&
         ((svs.maxclients < iVar5 || (pcVar7->active != false)))) {
        fVar1 = 0.0;
        if (0.0 <= fVar4) {
          fVar1 = *org;
          fVar2 = (peVar6->v).absmin[0];
          if ((fVar1 < fVar2) || (fVar2 = (peVar6->v).absmax[0], fVar2 < fVar1)) {
            fVar1 = (fVar1 - fVar2) * (fVar1 - fVar2) + 0.0;
            if (fVar4 < fVar1) goto LAB_0008d860;
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
LAB_0008d860:
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


// FindMiptex  @ 000bd7d0
int FindMiptex(char *name)

{
  int iVar1;
  int iVar2;
  char (*s2) [64];
  
                    /* Unresolved local var: int i@[???] */
  s2 = miptex;
  iVar2 = 0;
  if (0 < nummiptex) {
    do {
      iVar1 = Q_strcasecmp(name,*s2);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      s2 = s2 + 1;
    } while (iVar2 < nummiptex);
    s2 = miptex + iVar2;
    if (nummiptex == 0x200) {
      Sys_Error("Exceeded MAX_MAP_TEXTURES");
    }
  }
  Q_strncpy(*s2,name,0x3f);
  miptex[iVar2][0x3f] = '\0';
  nummiptex = nummiptex + 1;
  return iVar2;
}


// FindNameInTable  @ 000960b0
uint32 FindNameInTable(extensiondll_t *pDll,char *pName)

{
  uint32 uVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: void * addr@[???] */
  uVar1 = dlsym();
  return uVar1;
}


// FindPassableSpace  @ 00078f80
int FindPassableSpace(edict_t *pEdict,vec_t *direction,float step)

{
  vec_t *veca;
  edict_t_conflict *peVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 100;
  veca = (pEdict->v).origin;
  do {
    VectorMA(veca,step,direction,veca);
    peVar1 = SV_TestEntityPosition((edict_t_conflict *)pEdict);
    if (peVar1 == (edict_t_conflict *)0x0) {
      (pEdict->v).oldorigin[0] = (pEdict->v).origin[0];
      (pEdict->v).oldorigin[1] = (pEdict->v).origin[1];
      (pEdict->v).oldorigin[2] = (pEdict->v).origin[2];
      return 1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}


// FloatNoSwap  @ 0005efe0
float FloatNoSwap(float f)

{
  return f;
}


// FloatSwap  @ 0005efb0
float FloatSwap(float f)

{
                    /* Unresolved local var: anon_union_4_2_94730025 dat1@[???]
                       Unresolved local var: anon_union_4_2_94730025 dat2@[???] */
  return (float)(((uint)f & 0xff00) << 8 |
                 (uint)CONCAT11((char)((uint)f >> 0x10),(char)((uint)f >> 0x18)) | (int)f << 0x18);
}


// FloorDivMod  @ 00080c70
void FloorDivMod(double numer,double denom,int *quotient,int *rem)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
                    /* Unresolved local var: int q@[???]
                       Unresolved local var: int r@[???]
                       Unresolved local var: double x@[???] */
  if (denom <= 0.0) {
    Sys_Error("FloorDivMod: bad denominator %d\n",SUB84(denom,0),(int)((ulonglong)denom >> 0x20));
  }
  if (0.0 <= numer) {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    iVar2 = (int)ROUND(numer / denom);
    dVar3 = floor(numer - denom * ROUND(numer / denom));
    iVar1 = (int)dVar3;
  }
  else {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
    dVar3 = ROUND(-numer / denom);
    iVar2 = -(int)dVar3;
    dVar3 = floor(-numer - dVar3 * denom);
    if ((int)dVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar2 = iVar2 + -1;
      iVar1 = (int)denom - (int)dVar3;
    }
  }
  *quotient = iVar2;
  *rem = iVar1;
  return;
}


// ForwardSlashes  @ 000bcce0
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


// FreeAllEntPrivateData  @ 000921e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FreeAllEntPrivateData(void)

{
  void *p;
  edict_t_conflict *peVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < sv.num_edicts) {
    iVar2 = 0;
    iVar3 = 0;
    do {
      peVar1 = (edict_t_conflict *)((int)(sv.edicts)->leafnums + iVar3 + -0x18);
      p = peVar1->pvPrivateData;
      if (p != (void *)0x0) {
        if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
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


// FreeBlob  @ 0006f5b0
void FreeBlob(BlobFootprint_t *pblobfootprint)

{
  if (pblobfootprint->m_hDll == 0) {
    return;
  }
  dlclose();
  return;
}


// FreeEntPrivateData  @ 000921a0
void FreeEntPrivateData(edict_t_conflict *pEdict)

{
  void *p;
  
  p = pEdict->pvPrivateData;
  if (p != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(pEdict);
      p = pEdict->pvPrivateData;
    }
    Mem_Free(p);
  }
  pEdict->pvPrivateData = (void *)0x0;
  return;
}


// FunctionFromName  @ 00096eb0
uint32 FunctionFromName(char *pName)

{
  char *pcVar1;
  uint32 uVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uint32 function@[DW_OP_reg0(EAX)]
                       Unresolved local var: char * pchFixedName@[???] */
  pcVar1 = ConvertNameToLocalPlatform(pName);
  if (0 < g_iextdllMac) {
    iVar3 = 0;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: void * addr@[???] */
      uVar2 = dlsym(g_rgextdll[iVar3].lDLLHandle,pcVar1);
      if (uVar2 != 0) {
        return uVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < g_iextdllMac);
  }
  Con_Printf("Can\'t find proc: %s\n",pcVar1);
  return 0;
}


// GameSetBackground  @ 00096020
void GameSetBackground(qboolean bNewSetting)

{
  gfBackground = bNewSetting;
  return;
}


// GameSetState  @ 00096010
void GameSetState(int iState)

{
  giActive = iState;
  return;
}


// GameSetSubState  @ 00095fe0
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


// GetAttachment  @ 00094c20
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
  local_18 = -(pEdict->v).angles[0];
  iVar1 = psVar2->attachmentindex + iAttachment * 0x58;
  local_14 = (pEdict->v).angles[1];
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


// GetBaseDirectory  @ 0006dee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * GetBaseDirectory(void)

{
  return s_pBaseDir;
}


// GetBonePosition  @ 00094b50
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


// GetChallengeNr  @ 000a04a0
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
      goto LAB_000a0565;
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
  g_rg_sv_challenges[local_20].challenge = iVar2 << 0x10 | uVar3;
  g_rg_sv_challenges[local_20].adr.type = net_from.type;
  *&g_rg_sv_challenges[local_20].adr.ip = net_from.ip;
  *(undefined4 *)g_rg_sv_challenges[local_20].adr.ipx = net_from.ipx._0_4_;
  *(undefined4 *)(g_rg_sv_challenges[local_20].adr.ipx + 4) = net_from.ipx._4_4_;
  *(undefined4 *)(g_rg_sv_challenges[local_20].adr.ipx + 8) = net_from._16_4_;
  g_rg_sv_challenges[local_20].time = (int)realtime;
LAB_000a0565:
  return g_rg_sv_challenges[local_20].challenge;
}


// GetCurrentSteamAppName  @ 00097bd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * GetCurrentSteamAppName(void)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = "Counter-Strike";
  iVar1 = strcasecmp(com_gamedir,"cstrike");
  if ((iVar1 != 0) && (iVar1 = strcasecmp(com_gamedir,"cstrike_beta"), iVar1 != 0)) {
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
              pcVar2 = "Condition Zero";
              iVar1 = strcasecmp(com_gamedir,"czero");
              if (iVar1 != 0) {
                pcVar2 = "Half-Life";
              }
            }
          }
        }
      }
    }
  }
  return pcVar2;
}


// GetDispatch  @ 00096030
DISPATCHFUNCTION GetDispatch(char *pname)

{
  DISPATCHFUNCTION p_Var1;
  extensiondll_t *peVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DISPATCHFUNCTION pDispatch@[???] */
  if (0 < g_iextdllMac) {
    peVar2 = g_rgextdll;
    iVar3 = 0;
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


// GetEntityIllum  @ 0008dc90
int GetEntityIllum(edict_t_conflict *pEnt)

{
  int iVar1;
  
                    /* Unresolved local var: int iReturn@[DW_OP_reg0(EAX)]
                       Unresolved local var: colorVec cvFloorColor@[???]
                       Unresolved local var: int iIndex@[???] */
  if (pEnt == (edict_t_conflict *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = NUM_FOR_EDICT((edict_t *)pEnt);
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


// GetEntityInit  @ 00096320
ENTITYINIT GetEntityInit(char *pClassName)

{
  ENTITYINIT p_Var1;
  extensiondll_t *peVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DISPATCHFUNCTION pDispatch@[???] */
  if (0 < g_iextdllMac) {
    peVar2 = g_rgextdll;
    iVar3 = 0;
    do {
      p_Var1 = (ENTITYINIT)dlsym(peVar2->lDLLHandle,pClassName);
      if (p_Var1 != (ENTITYINIT)0x0) {
        return p_Var1;
      }
      iVar3 = iVar3 + 1;
      peVar2 = peVar2 + 1;
    } while (iVar3 < g_iextdllMac);
  }
  return (ENTITYINIT)0x0;
}


// GetFileSystemFactory  @ 0006def0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * GetFileSystemFactory(void)

{
  return g_FileSystemFactory;
}


// GetGameAppID  @ 000ae150
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int GetGameAppID(void)

{
  int iVar1;
  char local_214 [260];
  char local_110 [264];
  
                    /* Unresolved local var: char[260] gd@[???]
                       Unresolved local var: char[260] arg@[???]
                       Unresolved local var: int i@[???] */
  COM_ParseDirectoryFromCmd("-game",local_110,0x104,"valve");
  COM_FileBase(local_110,local_214);
  iVar1 = strcasecmp(g_GameToAppIDMap[0].pGameDir,local_214);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = strcasecmp(g_GameToAppIDMap[1].pGameDir,local_214);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = strcasecmp(g_GameToAppIDMap[2].pGameDir,local_214);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = strcasecmp(g_GameToAppIDMap[3].pGameDir,local_214);
        if (iVar1 == 0) {
          iVar1 = 3;
        }
        else {
          iVar1 = strcasecmp(g_GameToAppIDMap[4].pGameDir,local_214);
          if (iVar1 == 0) {
            iVar1 = 4;
          }
          else {
            iVar1 = strcasecmp(g_GameToAppIDMap[5].pGameDir,local_214);
            if (iVar1 == 0) {
              iVar1 = 5;
            }
            else {
              iVar1 = strcasecmp(g_GameToAppIDMap[6].pGameDir,local_214);
              if (iVar1 == 0) {
                iVar1 = 6;
              }
              else {
                iVar1 = strcasecmp(g_GameToAppIDMap[7].pGameDir,local_214);
                if (iVar1 == 0) {
                  iVar1 = 7;
                }
                else {
                  iVar1 = strcasecmp(g_GameToAppIDMap[8].pGameDir,local_214);
                  if (iVar1 == 0) {
                    iVar1 = 8;
                  }
                  else {
                    iVar1 = strcasecmp(g_GameToAppIDMap[9].pGameDir,local_214);
                    if (iVar1 == 0) {
                      iVar1 = 9;
                    }
                    else {
                      iVar1 = strcasecmp(g_GameToAppIDMap[10].pGameDir,local_214);
                      if (iVar1 != 0) {
                        return 0x46;
                      }
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
  return g_GameToAppIDMap[iVar1].iAppID;
}


// GetIOFunction  @ 00096370
FIELDIOFUNCTION GetIOFunction(char *pName)

{
  FIELDIOFUNCTION p_Var1;
  extensiondll_t *peVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DISPATCHFUNCTION pDispatch@[???] */
  if (0 < g_iextdllMac) {
    peVar2 = g_rgextdll;
    iVar3 = 0;
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


// GetModelPtr  @ 00092530
void * GetModelPtr(edict_t_conflict *pEdict)

{
  void *pvVar1;
  
  if (pEdict != (edict_t_conflict *)0x0) {
    pvVar1 = Mod_Extradata(sv.models[(pEdict->v).modelindex]);
    return pvVar1;
  }
  return (void *)0x0;
}


// GetModuleHandle  @ 000852f0
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


// GetModuleHandle  @ 000d49f0
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


// GetRateRegistrySetting  @ 00097d20
char * GetRateRegistrySetting(char *pchDef)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*registry->_vptr_IRegistry[4])(registry,"rate",pchDef);
  return pcVar1;
}


// GetStatsString  @ 000780d0
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
  snprintf(buf,bufSize - 1,"%5.2f %5.2f %5.2f %7i %5i %7.2f %7i",(double)((float)cpuPercent * 100.0)
           ,(double)fVar1,(double)fVar2,(int)(dVar6 - (double)startTime) / 0x3c,iVar4,dVar3,iVar5);
  buf[bufSize + -1] = '\0';
  return;
}


// GetTimesTutorMessageShown  @ 000686e0
int GetTimesTutorMessageShown(int id)

{
  return -1;
}


// GetVarsOfEnt  @ 00092380
entvars_t * GetVarsOfEnt(edict_t_conflict *pEdict)

{
  return &pEdict->v;
}


// GreatestCommonDivisor  @ 00080da0
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


// IBaseInterface::~IBaseInterface  @ 00098ac0
/* DWARF original prototype: void ~IBaseInterface(IBaseInterface * this, int __in_chrg) */

void __thiscall IBaseInterface::~IBaseInterface(IBaseInterface *this,int __in_chrg)

{
  this->_vptr_IBaseInterface = (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  return;
}


// IBaseInterface::~IBaseInterface  @ 00098b50
/* DWARF original prototype: void ~IBaseInterface(IBaseInterface * this, int __in_chrg) */

void __thiscall IBaseInterface::~IBaseInterface(IBaseInterface *this,int __in_chrg)

{
  this->_vptr_IBaseInterface = (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// IBaseSystem::~IBaseSystem  @ 0009a430
/* virtual thunk to IBaseSystem::~IBaseSystem() */

void __thiscall IBaseSystem::~IBaseSystem(IBaseSystem *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~IBaseSystem((IBaseSystem *)(&this->field_0x0 + *(int *)((int)*this + -0xc)),in_stack_00000008,
               in_stack_0000000c);
  return;
}


// IBaseSystem::~IBaseSystem  @ 0009a440
/* DWARF original prototype: void ~IBaseSystem(IBaseSystem * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall IBaseSystem::~IBaseSystem(IBaseSystem *this,int __in_chrg,void **__vtt_parm)

{
  *this = (IBaseSystem)&PTR__IBaseInterface_000e7cf0;
  return;
}


// IBaseSystem::~IBaseSystem  @ 0009a700
/* virtual thunk to IBaseSystem::~IBaseSystem() */

void __thiscall IBaseSystem::~IBaseSystem(IBaseSystem *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~IBaseSystem((IBaseSystem *)(&this->field_0x0 + *(int *)((int)*this + -0xc)),in_stack_00000008,
               in_stack_0000000c);
  return;
}


// IBaseSystem::~IBaseSystem  @ 0009a710
/* DWARF original prototype: void ~IBaseSystem(IBaseSystem * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall IBaseSystem::~IBaseSystem(IBaseSystem *this,int __in_chrg,void **__vtt_parm)

{
  *this = (IBaseSystem)&PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// IDedicatedServerAPI::~IDedicatedServerAPI  @ 00098ae0
/* DWARF original prototype: void ~IDedicatedServerAPI(IDedicatedServerAPI * this, int __in_chrg) */

void __thiscall IDedicatedServerAPI::~IDedicatedServerAPI(IDedicatedServerAPI *this,int __in_chrg)

{
  (this->super_IBaseInterface)._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  return;
}


// IDedicatedServerAPI::~IDedicatedServerAPI  @ 00098b30
/* DWARF original prototype: void ~IDedicatedServerAPI(IDedicatedServerAPI * this, int __in_chrg) */

void __thiscall IDedicatedServerAPI::~IDedicatedServerAPI(IDedicatedServerAPI *this,int __in_chrg)

{
  (this->super_IBaseInterface)._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// IEngine::~IEngine  @ 0009aa40
/* DWARF original prototype: void ~IEngine(IEngine * this, int __in_chrg) */

void __thiscall IEngine::~IEngine(IEngine *this,int __in_chrg)

{
  this->_vptr_IEngine = (_func_int_varargs **)&PTR__IEngine_000e89e8;
  return;
}


// IEngine::~IEngine  @ 0009aa50
/* DWARF original prototype: void ~IEngine(IEngine * this, int __in_chrg) */

void __thiscall IEngine::~IEngine(IEngine *this,int __in_chrg)

{
  this->_vptr_IEngine = (_func_int_varargs **)&PTR__IEngine_000e89e8;
  operator_delete(this);
  return;
}


// IEngineAPI::~IEngineAPI  @ 00098ad0
/* DWARF original prototype: void ~IEngineAPI(IEngineAPI * this, int __in_chrg) */

void __thiscall IEngineAPI::~IEngineAPI(IEngineAPI *this,int __in_chrg)

{
  (this->super_IBaseInterface)._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  return;
}


// IEngineAPI::~IEngineAPI  @ 00098b40
/* DWARF original prototype: void ~IEngineAPI(IEngineAPI * this, int __in_chrg) */

void __thiscall IEngineAPI::~IEngineAPI(IEngineAPI *this,int __in_chrg)

{
  (this->super_IBaseInterface)._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// IEngineWrapper::~IEngineWrapper  @ 0009a450
/* DWARF original prototype: void ~IEngineWrapper(IEngineWrapper * this, int __in_chrg) */

void __thiscall IEngineWrapper::~IEngineWrapper(IEngineWrapper *this,int __in_chrg)

{
  this->_vptr_IEngineWrapper = (_func_int_varargs **)&PTR__IEngineWrapper_000e8888;
  return;
}


// IEngineWrapper::~IEngineWrapper  @ 0009a6f0
/* DWARF original prototype: void ~IEngineWrapper(IEngineWrapper * this, int __in_chrg) */

void __thiscall IEngineWrapper::~IEngineWrapper(IEngineWrapper *this,int __in_chrg)

{
  this->_vptr_IEngineWrapper = (_func_int_varargs **)&PTR__IEngineWrapper_000e8888;
  operator_delete(this);
  return;
}


// IGame::~IGame  @ 0009ab80
/* DWARF original prototype: void ~IGame(IGame * this, int __in_chrg) */

void __thiscall IGame::~IGame(IGame *this,int __in_chrg)

{
  this->_vptr_IGame = (_func_int_varargs **)&PTR__IGame_000e8ac8;
  return;
}


// IGame::~IGame  @ 0009abc0
/* DWARF original prototype: void ~IGame(IGame * this, int __in_chrg) */

void __thiscall IGame::~IGame(IGame *this,int __in_chrg)

{
  this->_vptr_IGame = (_func_int_varargs **)&PTR__IGame_000e8ac8;
  operator_delete(this);
  return;
}


// IGameServerData::~IGameServerData  @ 000c9bd0
/* DWARF original prototype: void ~IGameServerData(IGameServerData * this, int __in_chrg) */

void __thiscall IGameServerData::~IGameServerData(IGameServerData *this,int __in_chrg)

{
  (this->super_IBaseInterface)._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  return;
}


// IGameServerData::~IGameServerData  @ 000c9be0
/* DWARF original prototype: void ~IGameServerData(IGameServerData * this, int __in_chrg) */

void __thiscall IGameServerData::~IGameServerData(IGameServerData *this,int __in_chrg)

{
  (this->super_IBaseInterface)._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// IObjectContainer::~IObjectContainer  @ 000d3430
/* DWARF original prototype: void ~IObjectContainer(IObjectContainer * this, int __in_chrg) */

void __thiscall IObjectContainer::~IObjectContainer(IObjectContainer *this,int __in_chrg)

{
  this->_vptr_IObjectContainer = (_func_int_varargs **)&PTR__IObjectContainer_000edf68;
  return;
}


// IObjectContainer::~IObjectContainer  @ 000d3440
/* DWARF original prototype: void ~IObjectContainer(IObjectContainer * this, int __in_chrg) */

void __thiscall IObjectContainer::~IObjectContainer(IObjectContainer *this,int __in_chrg)

{
  this->_vptr_IObjectContainer = (_func_int_varargs **)&PTR__IObjectContainer_000edf68;
  operator_delete(this);
  return;
}


// ISystemModule::~ISystemModule  @ 0009a420
/* DWARF original prototype: void ~ISystemModule(ISystemModule * this, int __in_chrg) */

void __thiscall ISystemModule::~ISystemModule(ISystemModule *this,int __in_chrg)

{
  (this->super_IBaseInterface)._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  return;
}


// ISystemModule::~ISystemModule  @ 0009a720
/* DWARF original prototype: void ~ISystemModule(ISystemModule * this, int __in_chrg) */

void __thiscall ISystemModule::~ISystemModule(ISystemModule *this,int __in_chrg)

{
  (this->super_IBaseInterface)._vptr_IBaseInterface =
       (_func_int_varargs **)&PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// IndexOfEdict  @ 00092270
int IndexOfEdict(edict_t *pEdict)

{
  int iVar1;
  
                    /* Unresolved local var: int index@[???] */
  iVar1 = 0;
  if ((pEdict != (edict_t *)0x0) &&
     ((iVar1 = ((int)pEdict - (int)sv.edicts >> 2) * 0x28c1979, iVar1 < 0 ||
      (iVar1 - sv.max_edicts != 0 && sv.max_edicts <= iVar1)))) {
    Sys_Error("Bad entity in IndexOfEdict()");
  }
  return iVar1;
}


// InitEntityDLLFields  @ 00092110
void InitEntityDLLFields(edict_t_conflict *pEdict)

{
  (pEdict->v).pContainingEntity = pEdict;
  return;
}


// InsertLinkAfter  @ 000bea70
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


// InsertLinkBefore  @ 000bea50
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


// InterfaceReg::InterfaceReg  @ 000d4a30
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


// InterpolateAngles  @ 000800d0
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
    if (180.0 < fVar1) goto LAB_000802f8;
LAB_00080127:
    if (fVar1 < -180.0) {
      start[1] = fVar1 + 360.0;
    }
    fVar1 = start[2];
    if (180.0 < fVar1) goto LAB_00080157;
LAB_00080316:
    if (-180.0 <= fVar1) goto LAB_0008016a;
    start[2] = fVar1 + 360.0;
    fVar1 = *end;
    if (180.0 < fVar1) goto LAB_00080341;
LAB_0008017e:
    if (fVar1 < -180.0) {
      fVar1 = fVar1 + 360.0;
      *end = fVar1;
    }
    fVar2 = end[1];
    if (fVar2 <= 180.0) goto LAB_000801a5;
LAB_0008035e:
    end[1] = fVar2 - 360.0;
    fVar2 = end[2];
    if (fVar2 <= 180.0) goto LAB_0008037c;
LAB_000801d7:
    end[2] = fVar2 - 360.0;
  }
  else {
    if (fVar1 < -180.0) {
      *start = fVar1 + 360.0;
    }
    fVar1 = start[1];
    if (fVar1 <= 180.0) goto LAB_00080127;
LAB_000802f8:
    start[1] = fVar1 - 360.0;
    fVar1 = start[2];
    if (fVar1 <= 180.0) goto LAB_00080316;
LAB_00080157:
    start[2] = fVar1 - 360.0;
LAB_0008016a:
                    /* Unresolved local var: int i@[???] */
    fVar1 = *end;
    if (fVar1 <= 180.0) goto LAB_0008017e;
LAB_00080341:
    fVar1 = fVar1 - 360.0;
    *end = fVar1;
    fVar2 = end[1];
    if (180.0 < fVar2) goto LAB_0008035e;
LAB_000801a5:
    if (fVar2 < -180.0) {
      end[1] = fVar2 + 360.0;
    }
    fVar2 = end[2];
    if (180.0 < fVar2) goto LAB_000801d7;
LAB_0008037c:
    if (fVar2 < -180.0) {
      end[2] = fVar2 + 360.0;
      fVar2 = *start;
      fVar1 = fVar1 - fVar2;
      goto joined_r0x000801fa;
    }
  }
  fVar2 = *start;
  fVar1 = fVar1 - fVar2;
joined_r0x000801fa:
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
  output[2] = start[2] + fVar1 * frac;
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


// Invert24To16  @ 00080de0
fixed16_t Invert24To16(fixed16_t val)

{
  fixed16_t fVar1;
  
  fVar1 = -1;
  if (0xff < val) {
    fVar1 = (fixed16_t)(1.0995116e+12 / (float)val + 0.5);
  }
  return fVar1;
}


// InvertMatrix  @ 0007f2e0
/* WARNING: Type propagation algorithm not settling */

int InvertMatrix(float *m,float *out)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float fVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
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
  local_8c[9] = m[5];
  local_8c[2] = m[8];
  fVar2 = m[4];
  local_8c[6] = 0.0;
  local_8c[1] = fVar2;
  local_8c[3] = m[0xc];
  local_8c[8] = m[1];
  local_8c[5] = 0.0;
  local_8c[10] = m[9];
  local_8c[0x10] = m[2];
  local_8c[0xb] = m[0xd];
  local_8c[0xd] = 1.0;
  local_8c[0xf] = 0.0;
  local_8c[0xe] = 0.0;
  local_8c[0xc] = 0.0;
  local_8c[0x11] = m[6];
  local_8c[0x18] = m[3];
  local_8c[0x16] = 1.0;
  local_8c[0x12] = m[10];
  local_8c[0x19] = m[7];
  fVar5 = ABS(local_8c[0x18]);
  local_8c[0x13] = m[0xe];
  fVar3 = ABS(local_8c[0x10]);
  local_8c[0x17] = 0.0;
  local_8c[0x15] = 0.0;
  local_8c[0x14] = 0.0;
  local_8c[0x1a] = m[0xb];
  local_8c[0x1b] = m[0xf];
  local_8c[0x1f] = 1.0;
  local_8c[0x1e] = 0.0;
  local_8c[0x1d] = 0.0;
  local_8c[0x1c] = 0.0;
  if (fVar3 < fVar5) {
    pfVar10 = local_8c + 0x10;
    pfVar12 = local_8c + 0x18;
    pfVar11 = pfVar12;
    fVar4 = local_8c[0x18];
    fVar6 = local_8c[0x18];
    local_8c[0x18] = local_8c[0x10];
    fVar8 = m[7];
    fVar3 = fVar5;
    if (ABS(local_8c[8]) < fVar5) goto LAB_0007f93c;
LAB_0007f448:
    fVar3 = ABS(local_8c[8]);
    pfVar11 = local_8c + 8;
    fVar4 = local_8c[8];
    fVar5 = local_8c[8];
    local_8c[8] = fVar6;
    if (ABS(local_8c[0]) < fVar3) {
LAB_0007f95a:
      fVar5 = local_8c[0];
      fVar3 = fVar2;
      pfVar7 = local_8c;
      pfVar1 = pfVar11;
      local_8c[0] = fVar4;
      fVar2 = local_8c[9];
      fVar6 = local_8c[8];
      goto code_r0x0007f968;
    }
  }
  else {
    pfVar10 = local_8c + 0x18;
    pfVar12 = local_8c + 0x10;
    pfVar11 = pfVar12;
    fVar4 = local_8c[0x10];
    fVar6 = local_8c[0x10];
    fVar8 = m[6];
    if (fVar3 <= ABS(local_8c[8])) goto LAB_0007f448;
LAB_0007f93c:
    local_8c[9] = fVar8;
    pfVar12 = local_8c + 8;
    fVar5 = fVar4;
    fVar6 = local_8c[8];
    if (ABS(local_8c[0]) < fVar3) goto LAB_0007f95a;
  }
  pfVar1 = local_8c;
  fVar3 = local_8c[9];
  pfVar7 = pfVar11;
code_r0x0007f968:
  if (local_8c[0] == 0.0) {
    return 0;
  }
  fVar5 = fVar5 / local_8c[0];
  fVar6 = fVar6 / local_8c[0];
  local_8c[0] = local_8c[0x18] / local_8c[0];
  pfVar7[1] = fVar3 - fVar5 * fVar2;
  pfVar12[1] = pfVar12[1] - fVar6 * fVar2;
  pfVar10[1] = pfVar10[1] - fVar2 * local_8c[0];
  fVar2 = pfVar1[2];
  pfVar7[2] = pfVar7[2] - fVar5 * fVar2;
  pfVar12[2] = pfVar12[2] - fVar6 * fVar2;
  pfVar10[2] = pfVar10[2] - fVar2 * local_8c[0];
  fVar2 = pfVar1[3];
  pfVar7[3] = pfVar7[3] - fVar5 * fVar2;
  pfVar12[3] = pfVar12[3] - fVar6 * fVar2;
  pfVar10[3] = pfVar10[3] - fVar2 * local_8c[0];
  fVar2 = pfVar1[4];
  if (fVar2 == 0.0) {
    fVar2 = pfVar1[5];
  }
  else {
    pfVar7[4] = pfVar7[4] - fVar5 * fVar2;
    pfVar12[4] = pfVar12[4] - fVar6 * fVar2;
    pfVar10[4] = pfVar10[4] - fVar2 * local_8c[0];
    fVar2 = pfVar1[5];
  }
  if (fVar2 == 0.0) {
    fVar2 = pfVar1[6];
  }
  else {
    pfVar7[5] = pfVar7[5] - fVar5 * fVar2;
    pfVar12[5] = pfVar12[5] - fVar6 * fVar2;
    pfVar10[5] = pfVar10[5] - fVar2 * local_8c[0];
    fVar2 = pfVar1[6];
  }
  if (fVar2 == 0.0) {
    fVar2 = pfVar1[7];
  }
  else {
    pfVar7[6] = pfVar7[6] - fVar5 * fVar2;
    pfVar12[6] = pfVar12[6] - fVar6 * fVar2;
    pfVar10[6] = pfVar10[6] - fVar2 * local_8c[0];
    fVar2 = pfVar1[7];
  }
  if (fVar2 != 0.0) {
    pfVar7[7] = pfVar7[7] - fVar5 * fVar2;
    pfVar12[7] = pfVar12[7] - fVar6 * fVar2;
    pfVar10[7] = pfVar10[7] - local_8c[0] * fVar2;
  }
  fVar2 = pfVar10[1];
  fVar6 = ABS(fVar2);
  fVar3 = pfVar12[1];
  fVar4 = ABS(fVar3);
  pfVar11 = pfVar12;
  fVar5 = fVar2;
  if (fVar6 <= fVar4) {
    pfVar11 = pfVar10;
    pfVar10 = pfVar12;
    fVar5 = fVar3;
    fVar3 = fVar2;
    fVar6 = fVar4;
  }
  fVar2 = pfVar7[1];
  fVar4 = fVar2;
  pfVar12 = pfVar10;
  if (fVar6 <= ABS(fVar2)) {
    fVar4 = fVar5;
    pfVar12 = pfVar7;
    pfVar7 = pfVar10;
    fVar5 = fVar2;
  }
  iVar9 = 0;
  if (fVar5 != 0.0) {
    fVar4 = fVar4 / fVar5;
    fVar3 = fVar3 / fVar5;
    pfVar7[2] = pfVar7[2] - pfVar12[2] * fVar4;
    pfVar11[2] = pfVar11[2] - pfVar12[2] * fVar3;
    pfVar7[3] = pfVar7[3] - pfVar12[3] * fVar4;
    pfVar11[3] = pfVar11[3] - pfVar12[3] * fVar3;
    fVar2 = pfVar12[4];
    if (fVar2 != 0.0) {
      pfVar7[4] = pfVar7[4] - fVar4 * fVar2;
      pfVar11[4] = pfVar11[4] - fVar2 * fVar3;
    }
    fVar2 = pfVar12[5];
    if (fVar2 != 0.0) {
      pfVar7[5] = pfVar7[5] - fVar4 * fVar2;
      pfVar11[5] = pfVar11[5] - fVar2 * fVar3;
    }
    fVar2 = pfVar12[6];
    if (fVar2 != 0.0) {
      pfVar7[6] = pfVar7[6] - fVar4 * fVar2;
      pfVar11[6] = pfVar11[6] - fVar2 * fVar3;
    }
    fVar2 = pfVar12[7];
    if (fVar2 != 0.0) {
      pfVar7[7] = pfVar7[7] - fVar4 * fVar2;
      pfVar11[7] = pfVar11[7] - fVar2 * fVar3;
    }
    fVar2 = pfVar11[2];
    fVar3 = pfVar7[2];
    fVar5 = fVar2;
    pfVar10 = pfVar11;
    if (ABS(fVar2) <= ABS(fVar3)) {
      fVar5 = fVar3;
      fVar3 = fVar2;
      pfVar10 = pfVar7;
      pfVar7 = pfVar11;
    }
    iVar9 = 0;
    if (fVar5 != 0.0) {
      fVar3 = fVar3 / fVar5;
      fVar4 = pfVar7[3] - pfVar10[3] * fVar3;
      pfVar7[3] = fVar4;
      fVar6 = pfVar7[4] - pfVar10[4] * fVar3;
      pfVar7[4] = fVar6;
      fVar8 = pfVar7[5] - pfVar10[5] * fVar3;
      pfVar7[5] = fVar8;
      fVar5 = pfVar7[6] - pfVar10[6] * fVar3;
      pfVar7[6] = fVar5;
      fVar2 = pfVar7[7] - fVar3 * pfVar10[7];
      pfVar7[7] = fVar2;
      iVar9 = 0;
      if (fVar4 != 0.0) {
        fVar4 = 1.0 / fVar4;
        fVar6 = fVar6 * fVar4;
        pfVar7[4] = fVar6;
        pfVar7[5] = fVar8 * fVar4;
        pfVar7[6] = fVar5 * fVar4;
        pfVar7[7] = fVar4 * fVar2;
        fVar2 = pfVar10[3];
        fVar3 = 1.0 / pfVar10[2];
        pfVar10[4] = (pfVar10[4] - fVar6 * fVar2) * fVar3;
        pfVar10[5] = (pfVar10[5] - pfVar7[5] * fVar2) * fVar3;
        pfVar10[6] = (pfVar10[6] - pfVar7[6] * fVar2) * fVar3;
        pfVar10[7] = (pfVar10[7] - fVar2 * pfVar7[7]) * fVar3;
        fVar2 = pfVar12[3];
        pfVar12[4] = pfVar12[4] - pfVar7[4] * fVar2;
        pfVar12[5] = pfVar12[5] - pfVar7[5] * fVar2;
        pfVar12[6] = pfVar12[6] - pfVar7[6] * fVar2;
        pfVar12[7] = pfVar12[7] - fVar2 * pfVar7[7];
        fVar2 = pfVar1[3];
        pfVar1[4] = pfVar1[4] - pfVar7[4] * fVar2;
        pfVar1[5] = pfVar1[5] - pfVar7[5] * fVar2;
        pfVar1[6] = pfVar1[6] - pfVar7[6] * fVar2;
        pfVar1[7] = pfVar1[7] - fVar2 * pfVar7[7];
        fVar2 = pfVar12[2];
        fVar3 = 1.0 / pfVar12[1];
        pfVar12[4] = (pfVar12[4] - pfVar10[4] * fVar2) * fVar3;
        pfVar12[5] = (pfVar12[5] - pfVar10[5] * fVar2) * fVar3;
        pfVar12[6] = (pfVar12[6] - pfVar10[6] * fVar2) * fVar3;
        pfVar12[7] = (pfVar12[7] - fVar2 * pfVar10[7]) * fVar3;
        fVar2 = pfVar1[2];
        fVar5 = pfVar1[4] - pfVar10[4] * fVar2;
        pfVar1[4] = fVar5;
        fVar4 = pfVar1[5] - pfVar10[5] * fVar2;
        pfVar1[5] = fVar4;
        fVar6 = pfVar1[6] - pfVar10[6] * fVar2;
        pfVar1[6] = fVar6;
        fVar8 = pfVar1[7] - fVar2 * pfVar10[7];
        pfVar1[7] = fVar8;
        fVar2 = pfVar1[1];
        fVar3 = 1.0 / *pfVar1;
        fVar5 = (fVar5 - pfVar12[4] * fVar2) * fVar3;
        pfVar1[4] = fVar5;
        fVar4 = (fVar4 - pfVar12[5] * fVar2) * fVar3;
        pfVar1[5] = fVar4;
        fVar6 = (fVar6 - pfVar12[6] * fVar2) * fVar3;
        pfVar1[6] = fVar6;
        fVar3 = (fVar8 - fVar2 * pfVar12[7]) * fVar3;
        pfVar1[7] = fVar3;
        fVar2 = pfVar12[4];
        *out = fVar5;
        out[4] = fVar4;
        out[8] = fVar6;
        out[0xc] = fVar3;
        out[1] = fVar2;
        out[5] = pfVar12[5];
        out[9] = pfVar12[6];
        out[0xd] = pfVar12[7];
        out[2] = pfVar10[4];
        out[6] = pfVar10[5];
        out[10] = pfVar10[6];
        out[0xe] = pfVar10[7];
        out[3] = pfVar7[4];
        out[7] = pfVar7[5];
        out[0xb] = pfVar7[6];
        out[0xf] = pfVar7[7];
        iVar9 = 1;
      }
    }
  }
  return iVar9;
}


// IsCZPlayerModel  @ 000ce620
qboolean IsCZPlayerModel(uint32 crc,char *filename)

{
  int iVar1;
  char *__s2;
  
  if (filename == (char *)0x0) {
    return 0;
  }
  if (crc == 0x35ac6fed) {
LAB_000ce730:
    __s2 = "models/player/gign/gign.mdl";
  }
  else {
    if (0x35ac6fed < crc) {
      if (crc == 0x72db74e4) {
LAB_000ce790:
        __s2 = "models/player/vip/vip.mdl";
        goto LAB_000ce750;
      }
      if (crc < 0x72db74e5) {
        if (crc != 0x43e67ff3) {
          if (crc < 0x43e67ff4) {
            if (crc != 0x3bcaa016) {
              return 0;
            }
            __s2 = "models/player/militia/militia.mdl";
            goto LAB_000ce750;
          }
          if (crc != 0x4986827b) {
            if (crc != 0x56dd2d02) {
              return 0;
            }
            goto LAB_000ce6fe;
          }
LAB_000ce810:
          __s2 = "models/player/arctic/arctic.mdl";
          goto LAB_000ce750;
        }
      }
      else {
        if (crc == 0xc7f0dbf3) goto LAB_000ce740;
        if (crc < 0xc7f0dbf4) {
          if (crc != 0xa37d8680) {
            if (crc != 0xc37369f6) {
              return 0;
            }
            goto LAB_000ce6c4;
          }
          goto LAB_000ce810;
        }
        if (crc == 0xec43f76d) goto LAB_000ce768;
        if (crc != 0xf141ae3f) {
          return 0;
        }
      }
      __s2 = "models/player/sas/sas.mdl";
      goto LAB_000ce750;
    }
    if (crc != 0x1b6c4115) {
      if (crc < 0x1b6c4116) {
        if (crc == 0x68168db) {
LAB_000ce740:
          __s2 = "models/player/urban/urban.mdl";
          goto LAB_000ce750;
        }
        if (crc < 0x68168dc) {
          if (crc != 0x2b95e5f) {
            return 0;
          }
          goto LAB_000ce790;
        }
        if (crc == 0xda8922a) {
LAB_000ce6fe:
          __s2 = "models/player/gsg9/gsg9.mdl";
          goto LAB_000ce750;
        }
        if (crc != 0x1aaa3360) {
          return 0;
        }
        goto LAB_000ce730;
      }
      if (crc == 0x270fb2d7) {
LAB_000ce768:
        __s2 = "models/player/terror/terror.mdl";
        goto LAB_000ce750;
      }
      if (0x270fb2d7 < crc) {
        if (crc == 0x27fb4d2f) {
          __s2 = "models/player/spetsnaz/spetsnaz.mdl";
          goto LAB_000ce750;
        }
        if (crc != 0x29fe156c) {
          return 0;
        }
LAB_000ce6c4:
        __s2 = "models/player/leet/leet.mdl";
        goto LAB_000ce750;
      }
      if (crc != 0x1f3cd80b) {
        return 0;
      }
    }
    __s2 = "models/player/guerilla/guerilla.mdl";
  }
LAB_000ce750:
  iVar1 = strcasecmp(filename,__s2);
  return (uint)(iVar1 == 0);
}


// IsComment  @ 000bbdb0
int IsComment(char *pText)

{
  int iVar1;
  
  iVar1 = 1;
  if (pText != (char *)0x0) {
                    /* Unresolved local var: int length@[???] */
    iVar1 = Q_strlen(pText);
    if (iVar1 < 2) {
      return (uint)(iVar1 != 1);
    }
    iVar1 = 0;
    if (*pText == '/') {
      return (uint)(pText[1] == '/');
    }
  }
  return iVar1;
}


// IsEndOfText  @ 000bbe20
int IsEndOfText(char *pText)

{
  uint uVar1;
  
  uVar1 = 0;
  if (pText != (char *)0x0) {
    uVar1 = (uint)(*pText == '}');
  }
  return uVar1;
}


// IsGameSubscribed  @ 000ae370
qboolean IsGameSubscribed(char *game)

{
  return false;
}


// IsSafeFileToDownload  @ 000a8f50
qboolean IsSafeFileToDownload(char *filename)

{
  char *pcVar1;
  char *pcVar2;
  qboolean qVar3;
  char local_100c [4096];
  
                    /* Unresolved local var: char * first@[???]
                       Unresolved local var: char * last@[???]
                       Unresolved local var: char[4096] lwrfilename@[???] */
  qVar3 = false;
  if (filename != (char *)0x0) {
    Q_strncpy(local_100c,filename,0x1000);
    Q_strlwr(local_100c);
    pcVar1 = Q_strstr(local_100c,":");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = Q_strstr(local_100c,"..");
      if (pcVar1 == (char *)0x0) {
        pcVar1 = Q_strstr(local_100c,"~");
        if (pcVar1 == (char *)0x0) {
          if ((local_100c[0] == '\\') || (local_100c[0] == '/')) {
            qVar3 = false;
          }
          else {
            pcVar1 = strchr(local_100c,0x2e);
            pcVar2 = strrchr(local_100c,0x2e);
            if (pcVar1 == pcVar2) {
              pcVar1 = Q_stristr(local_100c,".cfg");
              if (pcVar1 == (char *)0x0) {
                pcVar1 = Q_stristr(local_100c,".rc");
                if (pcVar1 == (char *)0x0) {
                  pcVar1 = Q_stristr(local_100c,".lst");
                  if (pcVar1 == (char *)0x0) {
                    pcVar1 = Q_stristr(local_100c,".exe");
                    if (pcVar1 == (char *)0x0) {
                      pcVar1 = Q_stristr(local_100c,".vbs");
                      if (pcVar1 == (char *)0x0) {
                        pcVar1 = Q_stristr(local_100c,".com");
                        if (pcVar1 == (char *)0x0) {
                          pcVar1 = Q_stristr(local_100c,".bat");
                          if (pcVar1 == (char *)0x0) {
                            pcVar1 = Q_stristr(local_100c,".dll");
                            if (pcVar1 == (char *)0x0) {
                              pcVar1 = Q_stristr(local_100c,".ini");
                              if (pcVar1 == (char *)0x0) {
                                pcVar1 = Q_stristr(local_100c,".log");
                                if (pcVar1 == (char *)0x0) {
                                  pcVar1 = Q_stristr(local_100c,"halflife.wad");
                                  if (pcVar1 == (char *)0x0) {
                                    pcVar1 = Q_stristr(local_100c,"pak0.pak");
                                    if (pcVar1 == (char *)0x0) {
                                      pcVar1 = Q_stristr(local_100c,"xeno.wad");
                                      if (pcVar1 == (char *)0x0) {
                                        pcVar1 = Q_stristr(local_100c,".so");
                                        if (pcVar1 == (char *)0x0) {
                                          pcVar1 = Q_stristr(local_100c,".dylib");
                                          if (pcVar1 == (char *)0x0) {
                                            pcVar1 = Q_stristr(local_100c,".sys");
                                            if (pcVar1 == (char *)0x0) {
                                              pcVar1 = Q_stristr(local_100c,".asi");
                                              if (pcVar1 == (char *)0x0) {
                                                pcVar1 = Q_stristr(local_100c,".mix");
                                                if (pcVar1 == (char *)0x0) {
                                                  pcVar1 = Q_stristr(local_100c,".flt");
                                                  qVar3 = (qboolean)(pcVar1 == (char *)0x0);
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
  }
  return qVar3;
}


// IsStartOfText  @ 000bbe00
int IsStartOfText(char *pText)

{
  uint uVar1;
  
  uVar1 = 0;
  if (pText != (char *)0x0) {
    uVar1 = (uint)(*pText == '{');
  }
  return uVar1;
}


// IsToken  @ 000bc0c0
int IsToken(char *pText,char *pTokenName)

{
  int iVar1;
  
  if ((pTokenName != (char *)0x0) && (pText != (char *)0x0)) {
    iVar1 = Q_strlen(pTokenName);
    iVar1 = Q_strnicmp(pText + 1,pTokenName,iVar1);
    return (uint)(iVar1 == 0);
  }
  return 0;
}


// IsWhiteSpace  @ 000bbe40
int IsWhiteSpace(char space)

{
  if ((space != '\t') && (space != ' ')) {
    return (uint)(space == '\n' || space == '\r');
  }
  return 1;
}


// LandmarkOrigin  @ 0007b3c0
void LandmarkOrigin(SAVERESTOREDATA *pSaveData,vec_t *output,char *pLandmarkName)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < pSaveData->connectionCount) {
    iVar2 = 0;
    do {
      iVar1 = Q_strcmp(pSaveData->levelList[iVar2].landmarkName,pLandmarkName);
      if (iVar1 == 0) {
        *output = pSaveData->levelList[iVar2].vecLandmarkOrigin[0];
        output[1] = pSaveData->levelList[iVar2].vecLandmarkOrigin[1];
        output[2] = pSaveData->levelList[iVar2].vecLandmarkOrigin[2];
        return;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < pSaveData->connectionCount);
  }
  *output = 0.0;
  output[1] = 0.0;
  output[2] = 0.0;
  return;
}


// Length  @ 00080620
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


// LoadAdjacentEntities  @ 0007b870
void LoadAdjacentEntities(char *pOldLevel,char *pLandmarkName)

{
  char *level;
  float fVar1;
  float fVar2;
  int iVar3;
  SAVERESTOREDATA *pSaveData;
  byte bVar4;
  int iVar5;
  uint levelMask;
  int iVar6;
  float local_62c;
  float local_628;
  float local_620;
  float local_61c;
  int local_614;
  undefined1 local_60c [36];
  int local_5e8;
  char local_5e0 [32];
  char local_5c0 [36];
  float local_59c [323];
  SAVE_HEADER local_90;
  
                    /* Unresolved local var: SAVERESTOREDATA currentLevelData@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int test@[???]
                       Unresolved local var: int flags@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: int movedCount@[???]
                       Unresolved local var: SAVE_HEADER header@[???]
                       Unresolved local var: vec3_t landmarkOrigin@[???] */
  Q_memset(local_60c,0,0x574);
  gGlobalVariables.pSaveData = local_60c;
  (*gEntityInterface.pfnParmsChangeLevel)();
  if (0 < local_5e8) {
    iVar6 = 0;
    local_614 = 0;
    do {
      iVar5 = 0;
      if (iVar6 != 0) {
        do {
          iVar3 = Q_strcmp(local_5e0 + iVar6 * 0x50,local_5e0 + iVar5 * 0x50);
          if (iVar3 == 0) {
            if (iVar5 < iVar6) goto LAB_0007b8fb;
            break;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 != iVar6);
      }
      level = local_5e0 + iVar6 * 0x50;
      pSaveData = LoadSaveData(level);
      if (pSaveData != (SAVERESTOREDATA *)0x0) {
        ParseSaveTables(pSaveData,&local_90,0);
        EntityPatchRead(pSaveData,level);
                    /* Unresolved local var: int i@[???] */
        pSaveData->time = (float)sv.time;
        pSaveData->fUseLandmark = 1;
        if (0 < local_5e8) {
          iVar5 = 0;
          do {
            iVar3 = Q_strcmp(local_5c0 + iVar5 * 0x50,pLandmarkName);
            if (iVar3 == 0) {
              local_620 = local_59c[iVar5 * 0x14];
              local_61c = local_59c[iVar5 * 0x14 + 1];
              local_628 = local_59c[iVar5 * 0x14 + 2];
              goto LAB_0007b9ef;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < local_5e8);
        }
        local_628 = 0.0;
        local_61c = 0.0;
        local_620 = 0.0;
LAB_0007b9ef:
                    /* Unresolved local var: int i@[???] */
        if (0 < pSaveData->connectionCount) {
          iVar5 = 0;
          do {
            iVar3 = Q_strcmp(pSaveData->levelList[iVar5].landmarkName,pLandmarkName);
            if (iVar3 == 0) {
              local_62c = pSaveData->levelList[iVar5].vecLandmarkOrigin[0];
              pSaveData->vecLandmarkOffset[0] = local_62c;
              fVar1 = pSaveData->levelList[iVar5].vecLandmarkOrigin[1];
              pSaveData->vecLandmarkOffset[1] = fVar1;
              fVar2 = pSaveData->levelList[iVar5].vecLandmarkOrigin[2];
              pSaveData->vecLandmarkOffset[2] = fVar2;
              goto LAB_0007ba59;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < pSaveData->connectionCount);
        }
        pSaveData->vecLandmarkOffset[0] = 0.0;
        pSaveData->vecLandmarkOffset[1] = 0.0;
        pSaveData->vecLandmarkOffset[2] = 0.0;
        local_62c = 0.0;
        fVar2 = local_62c;
        fVar1 = local_62c;
LAB_0007ba59:
        pSaveData->vecLandmarkOffset[0] = local_620 - local_62c;
        pSaveData->vecLandmarkOffset[1] = local_61c - fVar1;
        pSaveData->vecLandmarkOffset[2] = local_628 - fVar2;
        iVar5 = Q_strcmp(level,pOldLevel);
                    /* Unresolved local var: int i@[???] */
        iVar3 = 0;
        levelMask = -(uint)(iVar5 == 0) & 0x80000000;
        if (0 < pSaveData->connectionCount) {
          do {
            while (iVar5 = Q_strcmp(pSaveData->levelList[iVar3].mapName,sv.name), iVar5 == 0) {
              if (iVar3 < 0) goto joined_r0x0007bb48;
              bVar4 = (byte)iVar3;
              iVar3 = iVar3 + 1;
              levelMask = levelMask | 1 << (bVar4 & 0x1f);
              if (pSaveData->connectionCount <= iVar3) goto joined_r0x0007bb48;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < pSaveData->connectionCount);
        }
joined_r0x0007bb48:
        if (levelMask != 0) {
          local_614 = CreateEntityList(pSaveData,levelMask);
        }
        if (local_614 != 0) {
          EntityPatchWrite(pSaveData,level);
        }
        if (pSaveData->pTokens != (char **)0x0) {
          Mem_Free(pSaveData->pTokens);
          pSaveData->pTokens = (char **)0x0;
          pSaveData->tokenCount = 0;
        }
        Mem_Free(pSaveData);
        gGlobalVariables.pSaveData = (void *)0x0;
      }
LAB_0007b8fb:
      iVar6 = iVar6 + 1;
    } while (iVar6 < local_5e8);
  }
  gGlobalVariables.pSaveData = (void *)0x0;
  return;
}


// LoadEntityDLLs  @ 00097000
void LoadEntityDLLs(char *szBaseDir)

{
  int iVar1;
  FileHandle_t file;
  uint *puVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  code *pcVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  extensiondll_t *peVar10;
  uint *puVar11;
  char *pcVar12;
  char local_23b4 [8192];
  char local_3b4 [260];
  char local_2b0 [260];
  uint local_1ac [63];
  undefined1 local_ad;
  char local_a0 [64];
  char local_60 [63];
  undefined1 local_21;
  char *local_20 [4];
  
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
  SV_ResetModInfo();
  g_iextdllMac = 0;
  Q_memset(g_rgextdll,0,600);
  Q_strncpy(local_a0,com_gamedir,0x3f);
  iVar1 = Q_stricmp(local_a0,"valve");
  if (iVar1 != 0) {
    gmodinfo.bIsMod = true;
  }
  puVar11 = (uint *)&DAT_000e5296;
  snprintf(local_2b0,0x104,"%s","liblist.gam");
  file = FS_Open(local_2b0,"rb");
  if (file == (FileHandle_t)0x0) {
                    /* Unresolved local var: char * findfn@[???] */
    snprintf(local_3b4,0x104,"%s/*.so",g_szExtensionDllSubDir);
                    /* Unresolved local var: char * psz@[???] */
    if (g_hfind != -1) {
      Sys_Error("Sys_FindFirst without close");
      FS_FindClose(g_hfind);
    }
    pcVar12 = (char *)0x0;
    pcVar3 = FS_FindFirst(local_3b4,&g_hfind,(char *)0x0);
    if (pcVar3 != (char *)0x0) {
      do {
        pcVar12 = "%s/%s/%s";
        snprintf(local_23b4,0x2000,"%s/%s/%s",szBaseDir,g_szExtensionDllSubDir,pcVar3);
        LoadThisDll(local_23b4);
                    /* Unresolved local var: char * psz@[???] */
        pcVar3 = FS_FindNext(g_hfind);
      } while (pcVar3 != (char *)0x0);
    }
    if (g_hfind != -1) {
      FS_FindClose(g_hfind);
      g_hfind = -1;
    }
  }
  else {
                    /* Unresolved local var: int index@[???] */
    puVar2 = (uint *)FS_Size(file);
    if ((0x40000 < (int)puVar2) || (puVar2 == (uint *)0x0)) {
      puVar11 = puVar2;
      Sys_Error("Game listing file size is bogus [%s: size %i]","liblist.gam",puVar2);
    }
    pcVar3 = Mem_Malloc((size_t)((int)puVar2 + 1));
    if (pcVar3 == (char *)0x0) {
      Sys_Error("Could not allocate space for game listing file of %i bytes",
                (char *)((int)puVar2 + 1),puVar11);
    }
    pcVar12 = (char *)0x1;
    puVar11 = (uint *)FS_Read(pcVar3,(int)puVar2,1,file);
    if (puVar11 != puVar2) {
      Sys_Error("Error reading in game listing file, expected %i bytes, read %i",puVar2,puVar11);
      pcVar12 = (char *)puVar11;
    }
    pcVar3[(int)puVar2] = '\0';
                    /* Unresolved local var: char * pos@[???]
                       Unresolved local var: char * sep@[???] */
    com_ignorecolons = true;
    pcVar4 = pcVar3;
    while( true ) {
      pcVar4 = COM_Parse(pcVar4);
      iVar1 = Q_strlen(com_token);
      if (iVar1 < 1) break;
      Q_strncpy(local_60,com_token,0x3f);
      local_21 = 0;
      pcVar4 = COM_Parse(pcVar4);
      pcVar12 = (char *)0xff;
      Q_strncpy((char *)local_1ac,com_token,0xff);
      local_ad = 0;
      iVar1 = Q_stricmp(local_60,"gamedll_linux");
      if (iVar1 == 0) {
        iVar1 = COM_CheckParm("-dll");
        if ((iVar1 != 0) && (iVar1 < com_argc + -1)) {
          pcVar12 = (char *)0xff;
          Q_strncpy((char *)local_1ac,com_argv[iVar1 + 1],0xff);
          local_ad = 0;
        }
        if (((((char)local_1ac[0] == '\\') || ((char)local_1ac[0] == '/')) ||
            (pcVar5 = Q_strstr((char *)local_1ac,":"), pcVar5 != (char *)0x0)) ||
           ((pcVar5 = Q_strstr((char *)local_1ac,".."), pcVar5 != (char *)0x0 &&
            (pcVar5 = Q_strstr(pcVar5 + 2,".."), pcVar5 != (char *)0x0)))) {
          Con_DPrintf("Skipping library with illegal characters in path: %s\n",local_1ac);
        }
        else {
          pcVar5 = strchr((char *)local_1ac,0x5f);
          if (pcVar5 != (char *)0x0) {
            *pcVar5 = '\0';
            puVar11 = local_1ac;
            do {
              puVar2 = puVar11;
              uVar7 = *puVar2 + 0xfefefeff & ~*puVar2;
              uVar8 = uVar7 & 0x80808080;
              puVar11 = puVar2 + 1;
            } while (uVar8 == 0);
            if ((uVar7 & 0x8080) == 0) {
              puVar11 = (uint *)((int)puVar2 + 6);
              uVar8 = uVar8 >> 0x10;
            }
            builtin_strncpy((char *)((int)puVar11 + (-3 - (uint)CARRY1((byte)uVar8,(byte)uVar8))),
                            ".so",4);
          }
          pcVar5 = COM_LastFileExtension((char *)local_1ac);
          iVar1 = Q_stricmp(pcVar5,"so");
          if (iVar1 == 0) {
            FS_GetLocalPath((char *)local_1ac,local_23b4,0x2000);
            pcVar12 = (char *)local_1ac;
            Con_DPrintf("\nAdding:  %s/%s\n",local_a0);
            LoadThisDll(local_23b4);
          }
          else {
            Con_DPrintf("Skipping non-shared library:  %s\n",local_1ac);
          }
        }
      }
      else {
        iVar1 = Q_stricmp(local_60,"url_info");
        if (iVar1 == 0) {
          gmodinfo.bIsMod = true;
          pcVar12 = (char *)0xff;
          Q_strncpy(gmodinfo.szInfo,(char *)local_1ac,0xff);
          gmodinfo.szInfo[0xff] = '\0';
        }
        else {
          iVar1 = Q_stricmp(local_60,"url_dl");
          if (iVar1 == 0) {
            gmodinfo.bIsMod = true;
            pcVar12 = (char *)0xff;
            Q_strncpy(gmodinfo.szDL,(char *)local_1ac,0xff);
            gmodinfo.szDL[0xff] = '\0';
          }
          else {
            iVar1 = Q_stricmp(local_60,"version");
            if (iVar1 == 0) {
              gmodinfo.bIsMod = true;
              pcVar12 = (char *)0xa;
              gmodinfo.version = strtol((char *)local_1ac,(char **)0x0,10);
            }
            else {
              iVar1 = Q_stricmp(local_60,"size");
              if (iVar1 == 0) {
                gmodinfo.bIsMod = true;
                pcVar12 = (char *)0xa;
                gmodinfo.size = strtol((char *)local_1ac,(char **)0x0,10);
              }
              else {
                iVar1 = Q_stricmp(local_60,"svonly");
                if (iVar1 == 0) {
                  gmodinfo.bIsMod = true;
                  pcVar12 = (char *)0xa;
                  lVar9 = strtol((char *)local_1ac,(char **)0x0,10);
                  gmodinfo.svonly = (qboolean)(lVar9 != 0);
                }
                else {
                  iVar1 = Q_stricmp(local_60,"cldll");
                  if (iVar1 == 0) {
                    gmodinfo.bIsMod = true;
                    pcVar12 = (char *)0xa;
                    lVar9 = strtol((char *)local_1ac,(char **)0x0,10);
                    gmodinfo.cldll = (qboolean)(lVar9 != 0);
                  }
                  else {
                    iVar1 = Q_stricmp(local_60,"secure");
                    if (iVar1 == 0) {
                      gmodinfo.bIsMod = true;
                      pcVar12 = (char *)0xa;
                      lVar9 = strtol((char *)local_1ac,(char **)0x0,10);
                      gmodinfo.secure = (qboolean)(lVar9 != 0);
                    }
                    else {
                      iVar1 = Q_stricmp(local_60,"hlversion");
                      if (iVar1 == 0) {
                        pcVar12 = (char *)0x1f;
                        Q_strncpy(gmodinfo.szHLVersion,(char *)local_1ac,0x1f);
                        gmodinfo.szHLVersion[0x1f] = '\0';
                      }
                      else {
                        iVar1 = Q_stricmp(local_60,"edicts");
                        if (iVar1 == 0) {
                          pcVar12 = (char *)0xa;
                          lVar9 = strtol((char *)local_1ac,(char **)0x0,10);
                          gmodinfo.num_edicts = 900;
                          if (899 < lVar9) {
                            gmodinfo.num_edicts = lVar9;
                          }
                        }
                        else {
                          iVar1 = Q_stricmp(local_60,"crcclientdll");
                          if (iVar1 == 0) {
                            gmodinfo.bIsMod = true;
                            pcVar12 = (char *)0xa;
                            lVar9 = strtol((char *)local_1ac,(char **)0x0,10);
                            gmodinfo.clientcrccheck = (qboolean)(lVar9 != 0);
                          }
                          else {
                            iVar1 = Q_stricmp(local_60,"type");
                            if (iVar1 == 0) {
                              iVar1 = strcasecmp((char *)local_1ac,"singleplayer_only");
                              if (iVar1 == 0) {
                                gmodinfo.type = SINGLEPLAYER_ONLY;
                              }
                              else {
                                iVar1 = strcasecmp((char *)local_1ac,"multiplayer_only");
                                gmodinfo.type = -(uint)(iVar1 == 0) & MULTIPLAYER_ONLY;
                              }
                            }
                            else {
                              iVar1 = Q_stricmp(local_60,"fallback_dir");
                              if (iVar1 == 0) {
                                COM_AddDefaultDir((char *)local_1ac);
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
    com_ignorecolons = false;
    Mem_Free(pcVar3);
    FS_Close(file);
  }
  gNewDLLFunctions.pfnGameShutdown = (_func_void *)0x0;
  gNewDLLFunctions.pfnShouldCollide = (_func_int_edict_t_ptr_edict_t_ptr *)0x0;
  gNewDLLFunctions.pfnCvarValue = (_func_void_edict_t_ptr_char_ptr *)0x0;
  gNewDLLFunctions.pfnCvarValue2 = (_func_void_edict_t_ptr_int_char_ptr_char_ptr *)0x0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DISPATCHFUNCTION pDispatch@[???] */
  gNewDLLFunctions.pfnOnFreeEntPrivateData = (_func_void_edict_t_ptr_conflict *)0x0;
  if (0 < g_iextdllMac) {
    peVar10 = g_rgextdll;
    iVar1 = 0;
    do {
      pcVar6 = (code *)dlsym(peVar10->lDLLHandle,"GetNewDLLFunctions");
      if (pcVar6 != (code *)0x0) {
        local_20[0] = (char *)0x1;
        (*pcVar6)(&gNewDLLFunctions,local_20);
        break;
      }
      iVar1 = iVar1 + 1;
      peVar10 = peVar10 + 1;
    } while (iVar1 < g_iextdllMac);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DISPATCHFUNCTION pDispatch@[???] */
    if (0 < g_iextdllMac) {
      peVar10 = g_rgextdll;
      iVar1 = 0;
      do {
        pcVar6 = (code *)dlsym(peVar10->lDLLHandle,"GetEntityAPI2");
        if (pcVar6 != (code *)0x0) {
          local_20[0] = (char *)0x8c;
          iVar1 = (*pcVar6)(&gEntityInterface,local_20);
          if (iVar1 != 0) goto LAB_000974f8;
          Con_Printf("==================\n");
          Con_Printf("Game DLL version mismatch\n");
          pcVar12 = (char *)0x8c;
          pcVar3 = local_20[0];
          Con_Printf("DLL version is %i, engine version is %i\n",local_20[0],0x8c);
          if ((int)local_20[0] < 0x8d) goto LAB_00097670;
          Con_Printf("Engine appears to be outdated, check for updates\n",pcVar3,pcVar12);
          goto LAB_00097687;
        }
        iVar1 = iVar1 + 1;
        peVar10 = peVar10 + 1;
      } while (iVar1 < g_iextdllMac);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DISPATCHFUNCTION pDispatch@[???] */
      if (0 < g_iextdllMac) {
        peVar10 = g_rgextdll;
        iVar1 = 0;
        do {
          pcVar6 = (code *)dlsym(peVar10->lDLLHandle,"GetEntityAPI");
          if (pcVar6 != (code *)0x0) {
            local_20[0] = (char *)0x8c;
            iVar1 = (*pcVar6)(&gEntityInterface,0x8c);
            if (iVar1 != 0) {
LAB_000974f8:
              pcVar12 = (*gEntityInterface.pfnGetGameDescription)();
              pcVar3 = "mod";
              if (gmodinfo.bIsMod == false) {
                pcVar3 = "game";
              }
              Con_DPrintf("Dll loaded for %s %s\n",pcVar3,pcVar12);
              return;
            }
            Con_Printf("==================\n");
            Con_Printf("Game DLL version mismatch\n");
LAB_00097670:
            pcVar3 = local_a0;
            Con_Printf("The game DLL for %s appears to be outdated, check for updates\n",pcVar3,
                       pcVar12);
LAB_00097687:
            Con_Printf("==================\n",pcVar3,pcVar12);
            Host_Error("\n");
            return;
          }
          iVar1 = iVar1 + 1;
          peVar10 = peVar10 + 1;
        } while (iVar1 < g_iextdllMac);
      }
    }
  }
  Host_Error("Couldn\'t get DLL API from %s!",local_23b4);
  return;
}


// LoadGame  @ 0007d4a0
int LoadGame(char *pName)

{
  qboolean qVar1;
  char *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int iRet@[DW_OP_reg6(ESI)]
                       Unresolved local var: qboolean q@[???] */
  qVar1 = scr_skipupdate;
                    /* Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: GAME_HEADER gameHeader@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: char * pTempNumber@[???]
                       Unresolved local var: char[5] szNumber@[???]
                       Unresolved local var: char * pchLoadExtension@[???]
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


// LoadGamestate  @ 0007adb0
int LoadGamestate(char *level,int createPlayers)

{
  string_t sVar1;
  int iVar2;
  char *pcVar3;
  SAVERESTOREDATA *pSaveData;
  int iVar4;
  int *piVar5;
  int iVar6;
  ENTITYINIT p_Var7;
  edict_t_conflict *peVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  SAVE_HEADER local_90;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: SAVE_HEADER header@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: edict_t * pent@[???] */
  pSaveData = LoadSaveData(level);
  iVar4 = 0;
  if (pSaveData != (SAVERESTOREDATA *)0x0) {
    ParseSaveTables(pSaveData,&local_90,1);
    EntityPatchRead(pSaveData,level);
    Cvar_SetValue("skill",(float)local_90.skillLevel);
    Q_strncpy(sv.name,local_90.mapName,0x3f);
    sv.name[0x3f] = '\0';
    Cvar_Set("sv_skyname",local_90.skyName);
    Cvar_SetValue("sv_skycolor_r",(float)local_90.skyColor_r);
    Cvar_SetValue("sv_skycolor_g",(float)local_90.skyColor_g);
    Cvar_SetValue("sv_skycolor_b",(float)local_90.skyColor_b);
    Cvar_SetValue("sv_skyvec_x",local_90.skyVec_x);
    Cvar_SetValue("sv_skyvec_y",local_90.skyVec_y);
    Cvar_SetValue("sv_skyvec_z",local_90.skyVec_z);
    if (0 < pSaveData->tableCount) {
      iVar4 = 0;
      fVar10 = 0.0;
      fVar11 = local_90.skyVec_z;
      do {
        while( true ) {
          peVar8 = sv.edicts;
          piVar5 = (int *)((int)&pSaveData->pTable->id + iVar4);
          sVar1 = piVar5[5];
          if (((sVar1 == 0) || (piVar5[3] == 0)) || ((piVar5[4] & 0x40000000U) != 0)) break;
          iVar6 = *piVar5;
          if (iVar6 == 0) {
                    /* Unresolved local var: ENTITYINIT pEntityInit@[???] */
            ReleaseEntityDLLFields(sv.edicts);
            InitEntityDLLFields(peVar8);
            pcVar3 = pr_strings;
            (peVar8->v).classname = sVar1;
            p_Var7 = GetEntityInit(pcVar3 + sVar1);
            if (p_Var7 != (ENTITYINIT)0x0) {
              (*p_Var7)(&peVar8->v);
            }
LAB_0007b0b3:
            piVar5 = (int *)((int)&pSaveData->pTable->id + iVar4);
          }
          else {
            if (svs.maxclients < iVar6) {
              peVar8 = CreateNamedEntity(sVar1);
              goto LAB_0007b0b3;
            }
            if (-1 < piVar5[4]) {
              fVar11 = fVar10;
              Sys_Error("ENTITY IS NOT A PLAYER: %d\n",fVar10);
              piVar5 = (int *)((int)&pSaveData->pTable->id + iVar4);
              iVar6 = *piVar5;
            }
            peVar8 = svs.clients[iVar6 + -1].edict;
            if ((createPlayers == 0) || (peVar8 == (edict_t_conflict *)0x0)) {
              peVar8 = (edict_t_conflict *)0x0;
            }
            else {
              sVar1 = piVar5[5];
                    /* Unresolved local var: ENTITYINIT pEntityInit@[???] */
              if (sVar1 == 0) {
                Sys_Error("Bad class!!\n",fVar11);
              }
              ReleaseEntityDLLFields(peVar8);
              InitEntityDLLFields(peVar8);
              pcVar3 = pr_strings;
              (peVar8->v).classname = sVar1;
              p_Var7 = GetEntityInit(pcVar3 + sVar1);
              if (p_Var7 == (ENTITYINIT)0x0) goto LAB_0007b0b3;
              (*p_Var7)(&peVar8->v);
              piVar5 = (int *)((int)&pSaveData->pTable->id + iVar4);
            }
          }
          piVar5[1] = (int)peVar8;
          fVar10 = (float)((int)fVar10 + 1);
          iVar4 = iVar4 + 0x18;
          iVar6 = pSaveData->tableCount;
          if (iVar6 <= (int)fVar10) goto LAB_0007af80;
        }
        piVar5[1] = 0;
        fVar10 = (float)((int)fVar10 + 1);
        iVar4 = iVar4 + 0x18;
        iVar6 = pSaveData->tableCount;
      } while ((int)fVar10 < iVar6);
LAB_0007af80:
      if (0 < iVar6) {
        iVar4 = 0;
        iVar9 = 0;
        do {
          while( true ) {
            peVar8 = *(edict_t_conflict **)((int)&pSaveData->pTable->pent + iVar4);
            pSaveData->currentIndex = iVar9;
            iVar2 = *(int *)((int)&pSaveData->pTable->location + iVar4);
            pSaveData->size = iVar2;
            pSaveData->pCurrentData = pSaveData->pBaseData + iVar2;
            if (peVar8 != (edict_t_conflict *)0x0) break;
LAB_0007afa1:
            iVar9 = iVar9 + 1;
            iVar4 = iVar4 + 0x18;
            if (iVar6 <= iVar9) goto LAB_0007b000;
          }
          iVar6 = (*gEntityInterface.pfnRestore)(peVar8,pSaveData,0);
          if (-1 < iVar6) {
            SV_LinkEdict(peVar8,false);
            iVar6 = pSaveData->tableCount;
            goto LAB_0007afa1;
          }
          iVar9 = iVar9 + 1;
          *(undefined4 *)((int)&pSaveData->pTable->pent + iVar4) = 0;
          iVar4 = iVar4 + 0x18;
          ED_Free(peVar8);
          iVar6 = pSaveData->tableCount;
        } while (iVar9 < iVar6);
      }
    }
LAB_0007b000:
    if (pSaveData->pTokens != (char **)0x0) {
      Mem_Free(pSaveData->pTokens);
      pSaveData->pTokens = (char **)0x0;
      pSaveData->tokenCount = 0;
    }
    Mem_Free(pSaveData);
    iVar4 = 1;
    gGlobalVariables.pSaveData = (void *)0x0;
    sv.time = (double)local_90.time;
  }
  return iVar4;
}


// LoadSaveData  @ 00079cc0
SAVERESTOREDATA * LoadSaveData(char *level)

{
  char *pcVar1;
  FileHandle_t file;
  int iVar2;
  SAVERESTOREDATA *pSVar3;
  char **ppcVar4;
  SAVERESTOREDATA *pOutput;
  SAVERESTOREDATA *pSVar5;
  char local_160 [260];
  int local_5c [4];
  int local_4c [4];
  int local_3c [4];
  int local_2c [3];
  int local_20 [4];
  
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
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
  snprintf(local_160,0x104,"%s%s.HL1",Host_SaveGameDirectory::szDirectory,level);
  COM_FixSlashes(local_160);
  Con_Printf("Loading game from %s...\n",local_160);
  file = FS_OpenPathID(local_160,"rb","GAMECONFIG");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("ERROR: couldn\'t open.\n");
    return (SAVERESTOREDATA *)0x0;
  }
  FS_Read(local_5c,4,1,file);
  if ((local_5c[0] == 0x564c4156) && (FS_Read(local_5c,4,1,file), local_5c[0] < 0x72)) {
    FS_Read(local_20,4,1,file);
    FS_Read(local_2c,4,1,file);
    FS_Read(local_4c,4,1,file);
    FS_Read(local_3c,4,1,file);
    if ((-1 < local_20[0]) &&
       (((-1 < local_4c[0] && (-1 < local_3c[0])) && (local_3c[0] <= 0x7fffffff - local_20[0])))) {
      if (((uint)(local_2c[0] * 0x18) <= 0x7fffffffU - (local_20[0] + local_3c[0])) &&
         (iVar2 = local_20[0] + local_3c[0] + local_2c[0] * 0x18, 0x573 < 0x7fffffffU - iVar2)) {
        pSVar3 = Mem_Calloc(iVar2 + 0x574,1);
        if (pSVar3 != (SAVERESTOREDATA *)0x0) {
          pOutput = pSVar3 + 1;
          pSVar3->tableCount = local_2c[0];
          pSVar3->tokenCount = local_4c[0];
          pSVar3->tokenSize = local_3c[0];
          Q_strncpy(pSVar3->szCurrentMapName,level,0x1f);
          pSVar3->szCurrentMapName[0x1f] = '\0';
          if (0 < local_3c[0]) {
            FS_Read(pOutput,pSVar3->tokenSize,1,file);
            ppcVar4 = pSVar3->pTokens;
            if (ppcVar4 == (char **)0x0) {
              ppcVar4 = Mem_Calloc(local_4c[0],4);
              pSVar3->pTokens = ppcVar4;
            }
            local_5c[0] = 0;
            if (0 < local_4c[0]) {
              while( true ) {
                pSVar5 = (SAVERESTOREDATA *)0x0;
                if (*(char *)&pOutput->pBaseData != '\0') {
                  pSVar5 = pOutput;
                }
                ppcVar4[local_5c[0]] = (char *)pSVar5;
                do {
                  ppcVar4 = &pOutput->pBaseData;
                  pOutput = (SAVERESTOREDATA *)((int)&pOutput->pBaseData + 1);
                } while (*(char *)ppcVar4 != '\0');
                local_5c[0] = local_5c[0] + 1;
                if (local_4c[0] <= local_5c[0]) break;
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
          pSVar3->bufferSize = local_20[0];
          pSVar3->vecLandmarkOffset[1] = 0.0;
          pSVar3->vecLandmarkOffset[2] = 0.0;
          gGlobalVariables.pSaveData = pSVar3;
          FS_Read(pSVar3->pBaseData,local_20[0],1,file);
        }
        FS_Close(file);
        return pSVar3;
      }
    }
  }
  FS_Close(file);
  return (SAVERESTOREDATA *)0x0;
}


// LoadSecurityModuleFromDisk  @ 000854b0
void LoadSecurityModuleFromDisk(char *pszDllName)

{
  BlobFootprint_t BVar1;
  char *pcVar2;
  code *pcVar3;
  uint uVar4;
  engdata_t local_88;
  
                    /* Unresolved local var: void * nAddrModule@[???]
                       Unresolved local var: void * pvPco@[???]
                       Unresolved local var: PTYPE pfP@[???] */
  g_modfuncs.m_nVersion = 0x43210004;
  NLoadBlobFile(pszDllName,&g_blobfootprintModule,&g_modfuncs,'\x01');
  BVar1 = g_blobfootprintModule;
  if (g_blobfootprintModule.m_hDll != 0) {
    pcVar2 = malloc(0x10000);
    g_pvModuleSpecial = pcVar2;
    pcVar3 = (code *)dlsym(BVar1.m_hDll,&DAT_000e5b7c);
    (*pcVar3)(pcVar2);
                    /* Unresolved local var: engdata_t engdata@[???] */
    if (g_modfuncs.m_nVersion == 0x43210004) {
      if (g_modfuncs.m_pfnSetEngineVersion != (PFN_SETENGINEVERSION)0x0) {
        (*g_modfuncs.m_pfnSetEngineVersion)(3);
      }
      (*g_modfuncs.m_pfnLoadMod)(pcVar2);
      (*g_modfuncs.m_pfnGetEngDstAddrs)((cl_enginefunc_dst_t *)&g_engdstAddrs);
      if (g_modfuncs.m_pfnSetModSHelpers != (PFN_SETMODSHELPERS)0x0) {
        (*g_modfuncs.m_pfnSetModSHelpers)(&g_modshelpers);
      }
      uVar4 = 0;
      do {
        *(undefined4 *)((int)&local_88.pcl_enginefuncs + uVar4) =
             *(undefined4 *)((int)&DAT_000e5b00 + uVar4);
        uVar4 = uVar4 + 4;
      } while (uVar4 < 0x7c);
      (*g_modfuncs.m_pfnSetEngData)(&local_88);
      (*g_modfuncs.m_pfnModuleLoaded)();
      g_module.fLoaded = 1;
    }
    else {
      CloseSecurityModule();
    }
  }
  return;
}


// LoadThisDll  @ 00096d50
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


// LongNoSwap  @ 0005efa0
int32 LongNoSwap(int32 l)

{
  return l;
}


// LongSwap  @ 0005ef70
int32 LongSwap(int32 l)

{
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???]
                       Unresolved local var: uchar b3@[???]
                       Unresolved local var: uchar b4@[???] */
  return ((uint)l >> 8 & 0xff00) + l * 0x1000000 + ((uint)l >> 8 & 0xff) * 0x10000 +
         ((uint)l >> 0x18);
}


// MD5Final  @ 00067890
void MD5Final(uchar *digest,MD5Context_t *ctx)

{
  uint uVar1;
  
                    /* Unresolved local var: uint count@[???]
                       Unresolved local var: uchar * p@[???] */
  uVar1 = ctx->bits[0] >> 3 & 0x3f;
  ctx->in[uVar1] = 0x80;
  if (0x3f - uVar1 < 8) {
    Q_memset(ctx->in + uVar1 + 1,0,0x3f - uVar1);
    MD5Transform(ctx->buf,(uint *)ctx->in);
    Q_memset(ctx->in,0,0x38);
  }
  else {
    Q_memset(ctx->in + uVar1 + 1,0,0x37 - uVar1);
  }
  *(uint *)(ctx->in + 0x38) = ctx->bits[0];
  *(uint *)(ctx->in + 0x3c) = ctx->bits[1];
  MD5Transform(ctx->buf,(uint *)ctx->in);
  Q_memcpy(digest,ctx,0x10);
  Q_memset(ctx,0,4);
  return;
}


// MD5Init  @ 00067060
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


// MD5Transform  @ 00067090
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
  uVar6 = *in;
  uVar7 = in[1];
  uVar13 = *buf + 0xd76aa478 + uVar6 + ((buf[3] ^ buf[2]) & buf[1] ^ buf[3]);
  uVar14 = (uVar13 * 0x80 | uVar13 >> 0x19) + buf[1];
  uVar1 = ((buf[2] ^ buf[1]) & uVar14 ^ buf[2]) + buf[3] + 0xe8c7b756 + uVar7;
  uVar13 = in[2];
  uVar2 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar14;
  uVar8 = ((buf[1] ^ uVar14) & uVar2 ^ buf[1]) + buf[2] + 0x242070db + uVar13;
  uVar1 = in[3];
  uVar9 = (uVar8 * 0x20000 | uVar8 >> 0xf) + uVar2;
  uVar18 = ((uVar2 ^ uVar14) & uVar9 ^ uVar14) + buf[1] + 0xc1bdceee + uVar1;
  uVar8 = in[4];
  uVar19 = (uVar18 * 0x400000 | uVar18 >> 10) + uVar9;
  uVar18 = ((uVar9 ^ uVar2) & uVar19 ^ uVar2) + uVar14 + 0xf57c0faf + uVar8;
  uVar14 = in[5];
  uVar15 = (uVar18 * 0x80 | uVar18 >> 0x19) + uVar19;
  uVar18 = ((uVar19 ^ uVar9) & uVar15 ^ uVar9) + uVar2 + 0x4787c62a + uVar14;
  uVar2 = in[6];
  uVar3 = (uVar18 * 0x1000 | uVar18 >> 0x14) + uVar15;
  uVar9 = ((uVar15 ^ uVar19) & uVar3 ^ uVar19) + uVar9 + 0xa8304613 + uVar2;
  uVar18 = in[7];
  uVar10 = (uVar9 * 0x20000 | uVar9 >> 0xf) + uVar3;
  uVar19 = ((uVar3 ^ uVar15) & uVar10 ^ uVar15) + uVar19 + 0xfd469501 + uVar18;
  uVar9 = in[8];
  uVar20 = (uVar19 * 0x400000 | uVar19 >> 10) + uVar10;
  uVar19 = ((uVar10 ^ uVar3) & uVar20 ^ uVar3) + uVar15 + 0x698098d8 + uVar9;
  uVar15 = in[9];
  uVar16 = (uVar19 * 0x80 | uVar19 >> 0x19) + uVar20;
  uVar19 = ((uVar20 ^ uVar10) & uVar16 ^ uVar10) + uVar3 + 0x8b44f7af + uVar15;
  uVar3 = in[10];
  uVar4 = (uVar19 * 0x1000 | uVar19 >> 0x14) + uVar16;
  uVar10 = ((uVar16 ^ uVar20) & uVar4 ^ uVar20) + (uVar10 - 0xa44f) + uVar3;
  uVar19 = in[0xb];
  uVar11 = (uVar10 * 0x20000 | uVar10 >> 0xf) + uVar4;
  uVar20 = ((uVar4 ^ uVar16) & uVar11 ^ uVar16) + uVar20 + 0x895cd7be + uVar19;
  uVar10 = in[0xc];
  uVar21 = (uVar20 * 0x400000 | uVar20 >> 10) + uVar11;
  uVar20 = uVar16 + 0x6b901122 + uVar10 + ((uVar11 ^ uVar4) & uVar21 ^ uVar4);
  uVar16 = in[0xd];
  uVar12 = (uVar20 * 0x80 | uVar20 >> 0x19) + uVar21;
  uVar20 = ((uVar21 ^ uVar11) & uVar12 ^ uVar11) + uVar4 + 0xfd987193 + uVar16;
  uVar4 = in[0xe];
  uVar5 = (uVar20 * 0x1000 | uVar20 >> 0x14) + uVar12;
  uVar11 = uVar11 + 0xa679438e + uVar4 + ((uVar12 ^ uVar21) & uVar5 ^ uVar21);
  uVar20 = in[0xf];
  uVar17 = (uVar11 * 0x20000 | uVar11 >> 0xf) + uVar5;
  uVar11 = uVar21 + 0x49b40821 + uVar20 + ((uVar5 ^ uVar12) & uVar17 ^ uVar12);
  uVar21 = (uVar11 * 0x400000 | uVar11 >> 10) + uVar17;
  uVar11 = ((uVar21 ^ uVar17) & uVar5 ^ uVar17) + uVar7 + 0xf61e2562 + uVar12;
  uVar11 = (uVar11 * 0x20 | uVar11 >> 0x1b) + uVar21;
  uVar5 = ((uVar11 ^ uVar21) & uVar17 ^ uVar21) + uVar2 + 0xc040b340 + uVar5;
  uVar5 = (uVar5 * 0x200 | uVar5 >> 0x17) + uVar11;
  uVar12 = ((uVar5 ^ uVar11) & uVar21 ^ uVar11) + uVar19 + 0x265e5a51 + uVar17;
  uVar12 = (uVar12 * 0x4000 | uVar12 >> 0x12) + uVar5;
  uVar17 = ((uVar12 ^ uVar5) & uVar11 ^ uVar5) + uVar6 + 0xe9b6c7aa + uVar21;
  uVar17 = (uVar17 * 0x100000 | uVar17 >> 0xc) + uVar12;
  uVar11 = ((uVar17 ^ uVar12) & uVar5 ^ uVar12) + uVar14 + 0xd62f105d + uVar11;
  uVar11 = (uVar11 * 0x20 | uVar11 >> 0x1b) + uVar17;
  uVar5 = ((uVar11 ^ uVar17) & uVar12 ^ uVar17) + uVar3 + 0x2441453 + uVar5;
  uVar5 = (uVar5 * 0x200 | uVar5 >> 0x17) + uVar11;
  uVar12 = ((uVar5 ^ uVar11) & uVar17 ^ uVar11) + uVar20 + 0xd8a1e681 + uVar12;
  uVar12 = (uVar12 * 0x4000 | uVar12 >> 0x12) + uVar5;
  uVar17 = ((uVar12 ^ uVar5) & uVar11 ^ uVar5) + uVar8 + 0xe7d3fbc8 + uVar17;
  uVar17 = (uVar17 * 0x100000 | uVar17 >> 0xc) + uVar12;
  uVar11 = ((uVar17 ^ uVar12) & uVar5 ^ uVar12) + uVar15 + 0x21e1cde6 + uVar11;
  uVar11 = (uVar11 * 0x20 | uVar11 >> 0x1b) + uVar17;
  uVar5 = ((uVar11 ^ uVar17) & uVar12 ^ uVar17) + uVar4 + 0xc33707d6 + uVar5;
  uVar5 = (uVar5 * 0x200 | uVar5 >> 0x17) + uVar11;
  uVar12 = ((uVar5 ^ uVar11) & uVar17 ^ uVar11) + uVar1 + 0xf4d50d87 + uVar12;
  uVar12 = (uVar12 * 0x4000 | uVar12 >> 0x12) + uVar5;
  uVar17 = ((uVar12 ^ uVar5) & uVar11 ^ uVar5) + uVar9 + 0x455a14ed + uVar17;
  uVar17 = (uVar17 * 0x100000 | uVar17 >> 0xc) + uVar12;
  uVar11 = ((uVar17 ^ uVar12) & uVar5 ^ uVar12) + uVar16 + 0xa9e3e905 + uVar11;
  uVar11 = (uVar11 * 0x20 | uVar11 >> 0x1b) + uVar17;
  uVar5 = ((uVar11 ^ uVar17) & uVar12 ^ uVar17) + uVar13 + 0xfcefa3f8 + uVar5;
  uVar5 = (uVar5 * 0x200 | uVar5 >> 0x17) + uVar11;
  uVar12 = ((uVar5 ^ uVar11) & uVar17 ^ uVar11) + uVar18 + 0x676f02d9 + uVar12;
  uVar12 = (uVar12 * 0x4000 | uVar12 >> 0x12) + uVar5;
  uVar17 = ((uVar12 ^ uVar5) & uVar11 ^ uVar5) + uVar10 + 0x8d2a4c8a + uVar17;
  uVar21 = (uVar17 * 0x100000 | uVar17 >> 0xc) + uVar12;
  uVar11 = (uVar14 - 0x5c6be) + uVar11 + (uVar12 ^ uVar5 ^ uVar21);
  uVar11 = (uVar11 * 0x10 | uVar11 >> 0x1c) + uVar21;
  uVar5 = (uVar21 ^ uVar12 ^ uVar11) + uVar9 + 0x8771f681 + uVar5;
  uVar5 = (uVar5 * 0x800 | uVar5 >> 0x15) + uVar11;
  uVar12 = (uVar11 ^ uVar21 ^ uVar5) + uVar19 + 0x6d9d6122 + uVar12;
  uVar17 = (uVar12 * 0x10000 | uVar12 >> 0x10) + uVar5;
  uVar12 = (uVar5 ^ uVar11 ^ uVar17) + uVar4 + 0xfde5380c + uVar21;
  uVar21 = (uVar12 * 0x800000 | uVar12 >> 9) + uVar17;
  uVar11 = (uVar17 ^ uVar5 ^ uVar21) + uVar7 + 0xa4beea44 + uVar11;
  uVar11 = (uVar11 * 0x10 | uVar11 >> 0x1c) + uVar21;
  uVar5 = uVar8 + 0x4bdecfa9 + uVar5 + (uVar21 ^ uVar17 ^ uVar11);
  uVar12 = (uVar5 * 0x800 | uVar5 >> 0x15) + uVar11;
  uVar5 = uVar18 + 0xf6bb4b60 + uVar17 + (uVar11 ^ uVar21 ^ uVar12);
  uVar17 = (uVar5 * 0x10000 | uVar5 >> 0x10) + uVar12;
  uVar5 = (uVar12 ^ uVar11 ^ uVar17) + uVar3 + 0xbebfbc70 + uVar21;
  uVar5 = (uVar5 * 0x800000 | uVar5 >> 9) + uVar17;
  uVar11 = uVar16 + 0x289b7ec6 + uVar11 + (uVar17 ^ uVar12 ^ uVar5);
  uVar21 = (uVar11 * 0x10 | uVar11 >> 0x1c) + uVar5;
  uVar11 = uVar6 + 0xeaa127fa + uVar12 + (uVar5 ^ uVar17 ^ uVar21);
  uVar12 = (uVar11 * 0x800 | uVar11 >> 0x15) + uVar21;
  uVar11 = (uVar21 ^ uVar5 ^ uVar12) + uVar1 + 0xd4ef3085 + uVar17;
  uVar11 = (uVar11 * 0x10000 | uVar11 >> 0x10) + uVar12;
  uVar5 = uVar2 + 0x4881d05 + uVar5 + (uVar12 ^ uVar21 ^ uVar11);
  uVar17 = (uVar5 * 0x800000 | uVar5 >> 9) + uVar11;
  uVar5 = uVar15 + 0xd9d4d039 + uVar21 + (uVar11 ^ uVar12 ^ uVar17);
  uVar21 = (uVar5 * 0x10 | uVar5 >> 0x1c) + uVar17;
  uVar5 = (uVar17 ^ uVar11 ^ uVar21) + uVar10 + 0xe6db99e5 + uVar12;
  uVar5 = (uVar5 * 0x800 | uVar5 >> 0x15) + uVar21;
  uVar11 = uVar20 + 0x1fa27cf8 + uVar11 + (uVar21 ^ uVar17 ^ uVar5);
  uVar12 = (uVar11 * 0x10000 | uVar11 >> 0x10) + uVar5;
  uVar11 = uVar13 + 0xc4ac5665 + uVar17 + (uVar5 ^ uVar21 ^ uVar12);
  uVar17 = (uVar11 * 0x800000 | uVar11 >> 9) + uVar12;
  uVar6 = ((~uVar5 | uVar17) ^ uVar12) + uVar6 + 0xf4292244 + uVar21;
  uVar11 = (uVar6 * 0x40 | uVar6 >> 0x1a) + uVar17;
  uVar6 = ((~uVar12 | uVar11) ^ uVar17) + uVar18 + 0x432aff97 + uVar5;
  uVar6 = (uVar6 * 0x400 | uVar6 >> 0x16) + uVar11;
  uVar18 = ((~uVar17 | uVar6) ^ uVar11) + uVar4 + 0xab9423a7 + uVar12;
  uVar4 = (uVar18 * 0x8000 | uVar18 >> 0x11) + uVar6;
  uVar14 = ((~uVar11 | uVar4) ^ uVar6) + uVar14 + 0xfc93a039 + uVar17;
  uVar18 = (uVar14 * 0x200000 | uVar14 >> 0xb) + uVar4;
  uVar14 = uVar10 + 0x655b59c3 + uVar11 + ((~uVar6 | uVar18) ^ uVar4);
  uVar14 = (uVar14 * 0x40 | uVar14 >> 0x1a) + uVar18;
  uVar6 = uVar1 + 0x8f0ccc92 + uVar6 + ((~uVar4 | uVar14) ^ uVar18);
  uVar6 = (uVar6 * 0x400 | uVar6 >> 0x16) + uVar14;
  uVar1 = (uVar3 - 0x100b83) + uVar4 + ((~uVar18 | uVar6) ^ uVar14);
  uVar3 = (uVar1 * 0x8000 | uVar1 >> 0x11) + uVar6;
  uVar7 = ((~uVar14 | uVar3) ^ uVar6) + uVar7 + 0x85845dd1 + uVar18;
  uVar7 = (uVar7 * 0x200000 | uVar7 >> 0xb) + uVar3;
  uVar1 = ((~uVar6 | uVar7) ^ uVar3) + uVar9 + 0x6fa87e4f + uVar14;
  uVar14 = (uVar1 * 0x40 | uVar1 >> 0x1a) + uVar7;
  uVar6 = ((~uVar3 | uVar14) ^ uVar7) + uVar20 + 0xfe2ce6e0 + uVar6;
  uVar6 = (uVar6 * 0x400 | uVar6 >> 0x16) + uVar14;
  uVar1 = ((~uVar7 | uVar6) ^ uVar14) + uVar2 + 0xa3014314 + uVar3;
  uVar1 = (uVar1 * 0x8000 | uVar1 >> 0x11) + uVar6;
  uVar7 = ((~uVar14 | uVar1) ^ uVar6) + uVar16 + 0x4e0811a1 + uVar7;
  uVar7 = (uVar7 * 0x200000 | uVar7 >> 0xb) + uVar1;
  uVar8 = ((~uVar6 | uVar7) ^ uVar1) + uVar8 + 0xf7537e82 + uVar14;
  uVar14 = (uVar8 * 0x40 | uVar8 >> 0x1a) + uVar7;
  uVar6 = uVar19 + 0xbd3af235 + uVar6 + ((~uVar1 | uVar14) ^ uVar7);
  uVar8 = (uVar6 * 0x400 | uVar6 >> 0x16) + uVar14;
  uVar6 = ((~uVar7 | uVar8) ^ uVar14) + uVar13 + 0x2ad7d2bb + uVar1;
  uVar6 = (uVar6 * 0x8000 | uVar6 >> 0x11) + uVar8;
  uVar7 = ((~uVar14 | uVar6) ^ uVar8) + uVar15 + 0xeb86d391 + uVar7;
  buf[3] = uVar8 + buf[3];
  *buf = uVar14 + *buf;
  buf[1] = (uVar7 * 0x200000 | uVar7 >> 0xb) + buf[1] + uVar6;
  buf[2] = uVar6 + buf[2];
  return;
}


// MD5Update  @ 00067970
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
  uVar3 = ctx->bits[1];
  local_20 = buf;
  uVar1 = ctx->bits[0];
  local_24 = len;
  uVar2 = uVar1 + len * 8;
  ctx->bits[0] = uVar2;
  if (uVar2 < uVar1) {
    uVar3 = uVar3 + 1;
  }
  in = ctx->in;
  uVar2 = uVar1 >> 3 & 0x3f;
  ctx->bits[1] = (len >> 0x1d) + uVar3;
  if (uVar2 != 0) {
                    /* Unresolved local var: uchar * p@[???] */
    local_24 = 0x40 - uVar2;
    if (len < local_24) {
      Q_memcpy(ctx->in + uVar2,buf,len);
      return;
    }
    Q_memcpy(ctx->in + uVar2,buf,local_24);
    MD5Transform(ctx->buf,(uint *)in);
    local_20 = buf + local_24;
    local_24 = len - local_24;
  }
  src = local_20;
  uVar2 = local_24;
  if (0x3f < local_24) {
    do {
      uVar2 = uVar2 - 0x40;
      Q_memcpy(in,src,0x40);
      MD5Transform(ctx->buf,(uint *)in);
      src = src + 0x40;
    } while (0x3f < uVar2);
    local_20 = local_20 + (local_24 - 0x40 & 0xffffffc0) + 0x40;
    local_24 = local_24 & 0x3f;
  }
  Q_memcpy(in,local_20,local_24);
  return;
}


// MaskExceptions  @ 00095c60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MaskExceptions(void)

{
  return;
}


// ModelFrameCount  @ 00094d10
int ModelFrameCount(model_t *model)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int count@[???] */
  iVar4 = 1;
  if (model != (model_t *)0x0) {
    if (model->type == mod_sprite) {
                    /* Unresolved local var: msprite_t * psprite@[???] */
      iVar4 = *(int *)((int)(model->cache).data + 0xc);
    }
    else {
      if (model->type != mod_studio) {
        return 1;
      }
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudiobodyparts_t * pbodypart@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???] */
      pvVar1 = Mod_Extradata(model);
      if (pvVar1 == (void *)0x0) {
        return 1;
      }
      iVar3 = *(int *)((int)pvVar1 + 0xd0) + (int)pvVar1;
      if (*(int *)((int)pvVar1 + 0xcc) < 1) {
        return 1;
      }
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 * *(int *)(iVar3 + 0x40);
        iVar3 = iVar3 + 0x4c;
      } while (iVar2 != *(int *)((int)pvVar1 + 0xcc));
    }
    if (iVar4 < 1) {
      return 1;
    }
  }
  return iVar4;
}


// ModelFrames  @ 0008bd40
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


// NLoadBlobFile  @ 0006f4e0
void * NLoadBlobFile(char *pstFileName,BlobFootprint_t *pblobfootprint,void *pv,char fLoadAsDll)

{
  void *pvVar1;
  code *pcVar2;
  void *pvVar3;
  char local_100c [2048];
  char local_80c [2052];
  
                    /* Unresolved local var: void * nRet@[???] */
  pvVar3 = (void *)0x0;
  if (fLoadAsDll != '\0') {
                    /* Unresolved local var: char[2048] rgchNew@[???]
                       Unresolved local var: char[2048] rgchLocalPath@[???]
                       Unresolved local var: int32 hmoduleT@[???] */
    strcpy(local_100c,pstFileName);
    (**(code **)(*(int *)g_pFileSystem + 0x84))(g_pFileSystem,local_100c,local_80c,0x800);
    pvVar1 = FS_LoadLibrary(local_80c);
    pblobfootprint->m_hDll = (int32)pvVar1;
    pvVar3 = pvVar1;
    if (pvVar1 != (void *)0x0) {
                    /* Unresolved local var: FTYPE pfF@[???] */
      pcVar2 = (code *)dlsym(pvVar1,&DAT_000e440d);
      if (pcVar2 == (code *)0x0) {
        pvVar3 = (void *)0x0;
        dlclose(pvVar1);
      }
      else {
        (*pcVar2)(pv);
      }
    }
  }
  return pvVar3;
}


// NameForFunction  @ 00096e40
char * NameForFunction(uint32 function)

{
  int iVar1;
  int iVar2;
  undefined1 local_1c [8];
  char *local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * pName@[DW_OP_reg0(EAX)] */
  if (0 < g_iextdllMac) {
    iVar2 = 0;
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


// NetadrToSockadr  @ 000c41b0
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


// NormalizeAngles  @ 0007fff0
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


// NotifyDedicatedServerUI  @ 000c98d0
void NotifyDedicatedServerUI(char *message)

{
  int *piVar1;
  uchar *puVar2;
  bool bVar3;
  int iVar4;
  ListElem_t *this;
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int> *in_stack_ffffffe4;
  int in_stack_ffffffe8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: CUtlBuffer * response@[???] */
  iVar4 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::InsertBefore
                    (in_stack_ffffffe4,in_stack_ffffffe8);
  this = g_ServerRemoteAccess.m_ResponsePackets.m_Memory.m_pMemory + iVar4;
  if (((this->m_Element).packet.m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut((CUtlBuffer *)this,4);
    if (bVar3) {
      puVar2 = (this->m_Element).packet.m_Memory.m_pMemory + (this->m_Element).packet.m_Put;
      puVar2[0] = '\0';
      puVar2[1] = '\0';
      puVar2[2] = '\0';
      puVar2[3] = '\0';
      piVar1 = &(this->m_Element).packet.m_Put;
      *piVar1 = *piVar1 + 4;
    }
  }
  else {
    CUtlBuffer::Printf((CUtlBuffer *)this,"%d",0);
  }
  if (((this->m_Element).packet.m_Flags & 1) == 0) {
    bVar3 = CUtlBuffer::CheckPut((CUtlBuffer *)this,4);
    if (bVar3) {
      puVar2 = (this->m_Element).packet.m_Memory.m_pMemory + (this->m_Element).packet.m_Put;
      puVar2[0] = '\x01';
      puVar2[1] = '\0';
      puVar2[2] = '\0';
      puVar2[3] = '\0';
      piVar1 = &(this->m_Element).packet.m_Put;
      *piVar1 = *piVar1 + 4;
    }
  }
  else {
    CUtlBuffer::Printf((CUtlBuffer *)this,"%d",1);
  }
  CUtlBuffer::PutString((CUtlBuffer *)this,message);
  return;
}


// NullDst  @ 000852e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void NullDst(void)

{
  return;
}


// ObjectList::Add  @ 000d3130
/* DWARF original prototype: bool Add(ObjectList * this, void * newObject) */

bool __thiscall ObjectList::Add(ObjectList *this,void *newObject)

{
  element_s *peVar1;
  bool bVar2;
  
                    /* Unresolved local var: element_t * newElement@[???] */
  peVar1 = Mem_ZeroMalloc(0xc);
  bVar2 = false;
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
    bVar2 = true;
  }
  return bVar2;
}


// ObjectList::AddHead  @ 000d3290
/* DWARF original prototype: bool AddHead(ObjectList * this, void * newObject) */

bool __thiscall ObjectList::AddHead(ObjectList *this,void *newObject)

{
  element_s *peVar1;
  bool bVar2;
  
                    /* Unresolved local var: element_t * newElement@[???] */
  peVar1 = Mem_ZeroMalloc(0xc);
  bVar2 = false;
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
    bVar2 = true;
  }
  return bVar2;
}


// ObjectList::AddTail  @ 000d3360
/* DWARF original prototype: bool AddTail(ObjectList * this, void * newObject) */

bool __thiscall ObjectList::AddTail(ObjectList *this,void *newObject)

{
  element_s *peVar1;
  bool bVar2;
  
                    /* Unresolved local var: element_t * newElement@[???] */
  peVar1 = Mem_ZeroMalloc(0xc);
  bVar2 = false;
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
    bVar2 = true;
  }
  return bVar2;
}


// ObjectList::Clear  @ 000d30a0
/* DWARF original prototype: void Clear(ObjectList * this, bool freeElementsMemory) */

void __thiscall ObjectList::Clear(ObjectList *this,bool freeElementsMemory)

{
  element_s *peVar1;
  element_s *peVar2;
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
      peVar1 = p->next;
      Mem_Free(p);
      while (peVar1 != (element_s *)0x0) {
        peVar2 = peVar1->next;
        Mem_Free(peVar1);
        peVar1 = peVar2;
      }
    }
  }
  this->current = (element_t *)0x0;
  this->tail = (element_t *)0x0;
  this->head = (element_t *)0x0;
  this->number = 0;
  return;
}


// ObjectList::Contains  @ 000d2f30
/* DWARF original prototype: bool Contains(ObjectList * this, void * object) */

bool __thiscall ObjectList::Contains(ObjectList *this,void *object)

{
  element_t *peVar1;
  
                    /* Unresolved local var: element_t * e@[???] */
  peVar1 = this->head;
  while( true ) {
    if (peVar1 == (element_t *)0x0) {
      return false;
    }
    if (peVar1->object == object) break;
    peVar1 = peVar1->next;
  }
  this->current = peVar1;
  return true;
}


// ObjectList::CountElements  @ 000d2f20
/* DWARF original prototype: int CountElements(ObjectList * this) */

int __thiscall ObjectList::CountElements(ObjectList *this)

{
  return this->number;
}


// ObjectList::GetFirst  @ 000d2fa0
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


// ObjectList::GetNext  @ 000d2fd0
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


// ObjectList::Init  @ 000d2f70
/* DWARF original prototype: void Init(ObjectList * this) */

void __thiscall ObjectList::Init(ObjectList *this)

{
  this->current = (element_t *)0x0;
  this->tail = (element_t *)0x0;
  this->head = (element_t *)0x0;
  this->number = 0;
  return;
}


// ObjectList::IsEmpty  @ 000d2f10
/* DWARF original prototype: bool IsEmpty(ObjectList * this) */

bool __thiscall ObjectList::IsEmpty(ObjectList *this)

{
  return this->head == (element_t *)0x0;
}


// ObjectList::ObjectList  @ 000d3260
/* DWARF original prototype: void ObjectList(ObjectList * this) */

void __thiscall ObjectList::ObjectList(ObjectList *this)

{
  (this->super_IObjectContainer)._vptr_IObjectContainer =
       (_func_int_varargs **)&PTR__ObjectList_000edf28;
  this->current = (element_t *)0x0;
  this->tail = (element_t *)0x0;
  this->head = (element_t *)0x0;
  this->number = 0;
  return;
}


// ObjectList::Remove  @ 000d2ff0
/* DWARF original prototype: bool Remove(ObjectList * this, void * object) */

bool __thiscall ObjectList::Remove(ObjectList *this,void *object)

{
  element_t *p;
  element_t *peVar1;
  
                    /* Unresolved local var: element_t * e@[???] */
  p = this->head;
  while( true ) {
    if (p == (element_t *)0x0) {
      return false;
    }
    if (p->object == object) break;
    p = p->next;
  }
  if (p->prev != (element_s *)0x0) {
    p->prev->next = p->next;
  }
  if (p->next != (element_s *)0x0) {
    p->next->prev = p->prev;
  }
  if (this->head == p) {
    peVar1 = this->tail;
    this->head = p->next;
  }
  else {
    peVar1 = this->tail;
  }
  if (peVar1 == p) {
    peVar1 = this->current;
    this->tail = p->prev;
  }
  else {
    peVar1 = this->current;
  }
  if (peVar1 == p) {
    this->current = p->next;
  }
  Mem_Free(p);
  this->number = this->number + -1;
  return p != (element_t *)0x0;
}


// ObjectList::RemoveHead  @ 000d32f0
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


// ObjectList::RemoveTail  @ 000d33c0
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


// ObjectList::~ObjectList  @ 000d3190
/* DWARF original prototype: void ~ObjectList(ObjectList * this, int __in_chrg) */

void __thiscall ObjectList::~ObjectList(ObjectList *this,int __in_chrg)

{
  element_t *p;
  element_s *peVar1;
  
                    /* Unresolved local var: element_t * ne@[???]
                       Unresolved local var: element_t * e@[???] */
  p = this->head;
  (this->super_IObjectContainer)._vptr_IObjectContainer =
       (_func_int_varargs **)&PTR__ObjectList_000edf28;
  while (p != (element_t *)0x0) {
    peVar1 = p->next;
    Mem_Free(p);
    p = peVar1;
  }
  this->current = (element_t *)0x0;
  this->tail = (element_t *)0x0;
  this->head = (element_t *)0x0;
  this->number = 0;
  (this->super_IObjectContainer)._vptr_IObjectContainer =
       (_func_int_varargs **)&PTR__IObjectContainer_000edf68;
  return;
}


// ObjectList::~ObjectList  @ 000d31f0
/* DWARF original prototype: void ~ObjectList(ObjectList * this, int __in_chrg) */

void __thiscall ObjectList::~ObjectList(ObjectList *this,int __in_chrg)

{
  element_t *p;
  element_s *peVar1;
  
                    /* Unresolved local var: element_t * ne@[???]
                       Unresolved local var: element_t * e@[???] */
  p = this->head;
  (this->super_IObjectContainer)._vptr_IObjectContainer =
       (_func_int_varargs **)&PTR__ObjectList_000edf28;
  while (p != (element_t *)0x0) {
    peVar1 = p->next;
    Mem_Free(p);
    p = peVar1;
  }
  this->current = (element_t *)0x0;
  this->tail = (element_t *)0x0;
  this->head = (element_t *)0x0;
  this->number = 0;
  (this->super_IObjectContainer)._vptr_IObjectContainer =
       (_func_int_varargs **)&PTR__IObjectContainer_000edf68;
  operator_delete(this);
  return;
}


// PEntityOfEntIndex  @ 000922b0
edict_t_conflict * PEntityOfEntIndex(int iEntIndex)

{
  edict_t_conflict *peVar1;
  
  peVar1 = (edict_t_conflict *)0x0;
                    /* Unresolved local var: edict_t.conflict * pEdict@[DW_OP_reg0(EAX)] */
  if (((-1 < iEntIndex) && (iEntIndex < sv.max_edicts)) &&
     ((peVar1 = sv.edicts + iEntIndex, peVar1 == (edict_t_conflict *)0x0 ||
      ((peVar1->free != 0 || (peVar1->pvPrivateData == (void *)0x0)))))) {
    if (iEntIndex < svs.maxclients) {
      if (peVar1->free != 0) {
        peVar1 = (edict_t_conflict *)0x0;
      }
      return peVar1;
    }
    return (edict_t_conflict *)0x0;
  }
  return peVar1;
}


// PEntityOfEntIndexAllEntities  @ 00092310
edict_t_conflict * PEntityOfEntIndexAllEntities(int iEntIndex)

{
  edict_t_conflict *peVar1;
  
  peVar1 = (edict_t_conflict *)0x0;
                    /* Unresolved local var: edict_t.conflict * pEdict@[DW_OP_reg0(EAX)] */
  if (((-1 < iEntIndex) && (iEntIndex < sv.max_edicts)) &&
     ((peVar1 = sv.edicts + iEntIndex, peVar1 == (edict_t_conflict *)0x0 ||
      ((peVar1->free != 0 || (peVar1->pvPrivateData == (void *)0x0)))))) {
    if (iEntIndex <= svs.maxclients) {
      if (peVar1->free != 0) {
        peVar1 = (edict_t_conflict *)0x0;
      }
      return peVar1;
    }
    return (edict_t_conflict *)0x0;
  }
  return peVar1;
}


// PEntityOfEntOffset  @ 00092250
edict_t_conflict * PEntityOfEntOffset(int iEntOffset)

{
  return (edict_t_conflict *)((int)(sv.edicts)->leafnums + iEntOffset + -0x18);
}


// PVSFindEntities  @ 0008d3f0
edict_t_conflict * PVSFindEntities(edict_t_conflict *pplayer)

{
  model_s *pmVar1;
  mleaf_t *leaf;
  uchar *puVar2;
  int iVar3;
  edict_t_conflict *peVar4;
  mnode_t *pmVar5;
  int iVar6;
  int iVar7;
  edict_t_conflict *peVar8;
  edict_t_conflict *peVar9;
  int iVar10;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t.conflict * pent@[???]
                       Unresolved local var: edict_t.conflict * pchain@[???]
                       Unresolved local var: edict_t.conflict * pentPVS@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: uchar * ppvs@[???]
                       Unresolved local var: mleaf_t * pleaf@[???] */
  local_28 = (pplayer->v).origin[0] + (pplayer->v).view_ofs[0];
  local_24 = (pplayer->v).origin[1] + (pplayer->v).view_ofs[1];
  local_20 = (pplayer->v).origin[2] + (pplayer->v).view_ofs[2];
  leaf = Mod_PointInLeaf(&local_28,sv.worldmodel);
  puVar2 = Mod_LeafPVS(leaf,sv.worldmodel);
  pmVar1 = sv.worldmodel;
                    /* Unresolved local var: mnode_t * node@[???]
                       Unresolved local var: int i@[???] */
  iVar6 = (sv.worldmodel)->numleafs;
  iVar3 = r_visframecount + 1;
  r_visframecount = iVar3;
  if (0 < iVar6) {
    iVar7 = 0;
    iVar10 = 0x30;
    do {
      if (((int)(uint)puVar2[iVar7 >> 3] >> ((byte)iVar7 & 7) & 1U) != 0) {
        iVar6 = (int)pmVar1->leafs->minmaxs + iVar10 + -8;
        do {
          if (iVar3 == *(int *)(iVar6 + 4)) break;
          *(int *)(iVar6 + 4) = iVar3;
          iVar6 = *(int *)(iVar6 + 0x14);
        } while (iVar6 != 0);
        iVar6 = pmVar1->numleafs;
      }
      iVar7 = iVar7 + 1;
      iVar10 = iVar10 + 0x30;
    } while (iVar7 < iVar6);
  }
  peVar9 = sv.edicts;
  if (1 < sv.num_edicts) {
    iVar7 = 0x324;
    iVar3 = 1;
    iVar6 = sv.num_edicts;
    do {
      peVar8 = (edict_t_conflict *)((int)(sv.edicts)->leafnums + iVar7 + -0x18);
      if (peVar8->free == 0) {
        peVar4 = peVar8;
        if (((peVar8->v).movetype == 0xc) &&
           (peVar4 = (peVar8->v).aiment, peVar4 == (edict_t_conflict *)0x0)) {
          peVar4 = peVar8;
        }
        pmVar5 = PVSNode((sv.worldmodel)->nodes,(peVar4->v).absmin,(peVar4->v).absmax);
        iVar6 = sv.num_edicts;
        if (pmVar5 != (mnode_t *)0x0) {
          (peVar8->v).chain = peVar9;
          iVar6 = sv.num_edicts;
          peVar9 = peVar8;
        }
      }
      iVar3 = iVar3 + 1;
      iVar7 = iVar7 + 0x324;
    } while (iVar3 < iVar6);
  }
  if (cl.worldmodel != (model_s *)0x0) {
    r_oldviewleaf = (mleaf_t *)0x0;
    R_MarkLeaves();
  }
  return peVar9;
}


// PVSMark  @ 0008d360
void PVSMark(model_t *pmodel,uchar *ppvs)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: mnode_t * node@[???]
                       Unresolved local var: int i@[???] */
  iVar2 = pmodel->numleafs;
  iVar1 = r_visframecount + 1;
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


// PVSNode  @ 0008d260
mnode_t * PVSNode(mnode_t *node,vec_t *emins,vec_t *emaxs)

{
  byte bVar1;
  mplane_t *p;
  mnode_t *pmVar2;
  uint uVar3;
  
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: mnode_t * splitNode@[???] */
  if (node->visframe == r_visframecount) {
    do {
      if (node->contents < 0) {
        if (node->contents == -2) {
          node = (mnode_t *)0x0;
        }
        return node;
      }
      p = node->plane;
      bVar1 = p->type;
      if (bVar1 < 3) {
        uVar3 = 0;
        if ((p->dist <= emins[bVar1]) || (uVar3 = 3, p->dist < emaxs[bVar1])) {
LAB_0008d28a:
          pmVar2 = PVSNode(node->children[0],emins,emaxs);
          if (pmVar2 != (mnode_t *)0x0) {
            return pmVar2;
          }
          goto joined_r0x0008d317;
        }
      }
      else {
        uVar3 = BoxOnPlaneSide(emins,emaxs,p);
        if ((uVar3 & 1) != 0) goto LAB_0008d28a;
joined_r0x0008d317:
        if ((uVar3 & 2) == 0) {
          return (mnode_t *)0x0;
        }
      }
      node = node->children[1];
    } while (node->visframe == r_visframecount);
  }
  return (mnode_t *)0x0;
}


// ParseDirective  @ 000bc120
int ParseDirective(char *pText)

{
  char *s1;
  int iVar1;
  int iVar2;
  float local_2c;
  float local_28;
  float local_24;
  
  iVar1 = 0;
  if ((pText != (char *)0x0) && (*pText == '$')) {
                    /* Unresolved local var: float[8] tempFloat@[???] */
    s1 = pText + 1;
    iVar1 = Q_strlen("position");
    iVar1 = Q_strnicmp(s1,"position",iVar1);
    if (iVar1 == 0) {
      iVar2 = ParseFloats(pText,&local_2c,2);
      iVar1 = 1;
      if (iVar2 != 0) {
        gMessageParms.x = local_2c;
        gMessageParms.y = local_28;
      }
    }
    else {
      iVar1 = Q_strlen("effect");
      iVar1 = Q_strnicmp(s1,"effect",iVar1);
      if (iVar1 == 0) {
        iVar2 = ParseFloats(pText,&local_2c,1);
        iVar1 = 1;
        if (iVar2 != 0) {
          gMessageParms.effect = (int)local_2c;
        }
      }
      else {
        iVar1 = Q_strlen("fxtime");
        iVar1 = Q_strnicmp(s1,"fxtime",iVar1);
        if (iVar1 == 0) {
          iVar2 = ParseFloats(pText,&local_2c,1);
          iVar1 = 1;
          if (iVar2 != 0) {
            gMessageParms.fxtime = local_2c;
          }
        }
        else {
          iVar1 = Q_strlen("color2");
          iVar1 = Q_strnicmp(s1,"color2",iVar1);
          if (iVar1 == 0) {
            iVar2 = ParseFloats(pText,&local_2c,3);
            iVar1 = 1;
            if (iVar2 != 0) {
              gMessageParms.r2 = (uchar)(int)local_2c;
              gMessageParms.g2 = (uchar)(int)local_28;
              gMessageParms.b2 = (uchar)(int)local_24;
            }
          }
          else {
            iVar1 = Q_strlen("color");
            iVar1 = Q_strnicmp(s1,"color",iVar1);
            if (iVar1 == 0) {
              iVar2 = ParseFloats(pText,&local_2c,3);
              iVar1 = 1;
              if (iVar2 != 0) {
                gMessageParms.r1 = (uchar)(int)local_2c;
                gMessageParms.g1 = (uchar)(int)local_28;
                gMessageParms.b1 = (uchar)(int)local_24;
              }
            }
            else {
              iVar1 = Q_strlen("fadein");
              iVar1 = Q_strnicmp(s1,"fadein",iVar1);
              if (iVar1 == 0) {
                iVar2 = ParseFloats(pText,&local_2c,1);
                iVar1 = 1;
                if (iVar2 != 0) {
                  gMessageParms.fadein = local_2c;
                }
              }
              else {
                iVar1 = Q_strlen("fadeout");
                iVar1 = Q_strnicmp(s1,"fadeout",iVar1);
                if (iVar1 == 0) {
                  iVar2 = ParseFloats(pText,&local_2c,3);
                  iVar1 = 1;
                  if (iVar2 != 0) {
                    gMessageParms.fadeout = local_2c;
                    iVar1 = 1;
                  }
                }
                else {
                  iVar1 = IsToken(pText,"holdtime");
                  if (iVar1 == 0) {
                    Con_DPrintf("Unknown token: %s\n",pText);
                    iVar1 = 1;
                  }
                  else {
                    iVar2 = ParseFloats(pText,&local_2c,3);
                    iVar1 = 1;
                    if (iVar2 != 0) {
                      gMessageParms.holdtime = local_2c;
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
  return iVar1;
}


// ParseFloats  @ 000bbf30
int ParseFloats(char *pText,float *pFloat,int count)

{
  char cVar1;
  char *pcVar2;
  float fVar3;
  
                    /* Unresolved local var: char * pTemp@[???]
                       Unresolved local var: int index@[???] */
  if ((0 < count) && (pText != (char *)0x0)) {
    do {
                    /* Unresolved local var: int pos@[???] */
      cVar1 = *pText;
      if (cVar1 != '\0') {
        if (((cVar1 != '\t') && (cVar1 != ' ')) && (cVar1 != '\n' && cVar1 != '\r')) {
          do {
            pText = pText + 1;
            cVar1 = *pText;
            if (cVar1 == '\0') goto LAB_000bbfe0;
          } while (((cVar1 != '\t') && (cVar1 != ' ')) && (cVar1 != '\n' && cVar1 != '\r'));
        }
        do {
          pcVar2 = pText + 1;
          if (((cVar1 != '\t') && (cVar1 != ' ')) && ((cVar1 != '\n' && (cVar1 != '\r')))) break;
                    /* Unresolved local var: int pos@[???] */
          cVar1 = *pcVar2;
          pText = pcVar2;
        } while (cVar1 != '\0');
      }
LAB_000bbfe0:
      count = count + -1;
      fVar3 = Q_atof(pText);
      *pFloat = fVar3;
      pFloat = pFloat + 1;
    } while ((pText != (char *)0x0) && (0 < count));
  }
  return (uint)(count == 0);
}


// ParseSaveTables  @ 0007a0a0
/* WARNING: Removing unreachable block (ram,0x0007a1ed) */
/* WARNING: Removing unreachable block (ram,0x0007a200) */
/* WARNING: Removing unreachable block (ram,0x0007a262) */
/* WARNING: Removing unreachable block (ram,0x0007a280) */

void ParseSaveTables(SAVERESTOREDATA *pSaveData,SAVE_HEADER *pHeader,int updateGlobals)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  char **ppcVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int local_60;
  char local_5c [76];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: SAVELIGHTSTYLE light@[???] */
  if (0 < pSaveData->tableCount) {
    iVar6 = 0;
    iVar7 = 0;
    do {
      iVar6 = iVar6 + 1;
      (*gEntityInterface.pfnSaveReadFields)
                (pSaveData,"ETABLE",(void *)((int)&pSaveData->pTable->id + iVar7),
                 gEntityTableDescription,5);
      *(undefined4 *)((int)&pSaveData->pTable->pent + iVar7) = 0;
      iVar7 = iVar7 + 0x18;
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
  pSaveData->vecLandmarkOffset[1] = 0.0;
  pSaveData->time = fVar1;
  pSaveData->vecLandmarkOffset[2] = 0.0;
  if (0 < iVar6) {
    iVar6 = 0;
    do {
      iVar7 = iVar6 + 1;
      (*gEntityInterface.pfnSaveReadFields)
                (pSaveData,"ADJACENCY",pSaveData->levelList + iVar6,gAdjacencyDescription,4);
      iVar6 = iVar7;
    } while (iVar7 < pSaveData->connectionCount);
  }
  if (updateGlobals != 0) {
    ppcVar4 = sv.lightstyles;
    uVar5 = 0;
    do {
      uVar5 = uVar5 + 1;
      ppcVar4[0] = (char *)0x0;
      ppcVar4[1] = (char *)0x0;
      ppcVar4[2] = (char *)0x0;
      ppcVar4[3] = (char *)0x0;
      ppcVar4 = ppcVar4 + 4;
    } while (uVar5 < 0x10);
  }
  if (0 < pHeader->lightStyleCount) {
    iVar6 = 0;
    if (updateGlobals != 0) {
      do {
        iVar6 = iVar6 + 1;
        (*gEntityInterface.pfnSaveReadFields)
                  (pSaveData,"LIGHTSTYLE",&local_60,gLightstyleDescription,2);
        iVar7 = local_60;
        iVar2 = Q_strlen(local_5c);
        pcVar3 = Hunk_Alloc(iVar2 + 1);
        sv.lightstyles[iVar7] = pcVar3;
        Q_strncpy(sv.lightstyles[local_60],local_5c,3);
        sv.lightstyles[local_60][3] = '\0';
      } while (iVar6 < pHeader->lightStyleCount);
      return;
    }
    do {
      iVar6 = iVar6 + 1;
      (*gEntityInterface.pfnSaveReadFields)
                (pSaveData,"LIGHTSTYLE",&local_60,gLightstyleDescription,2);
    } while (iVar6 < pHeader->lightStyleCount);
  }
  return;
}


// PollDInputDevices  @ 00068660
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PollDInputDevices(void)

{
  return;
}


// ProcessTutorMessageDecayBuffer  @ 000686d0
void ProcessTutorMessageDecayBuffer(int *buffer,int bufferLength)

{
  return;
}


// PvAllocEntPrivateData  @ 00092120
void * PvAllocEntPrivateData(edict_t_conflict *pEdict,int32 cb)

{
  void *pvVar1;
  
  pvVar1 = pEdict->pvPrivateData;
  if (pvVar1 != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(pEdict);
      pvVar1 = pEdict->pvPrivateData;
    }
    Mem_Free(pvVar1);
  }
  pvVar1 = (void *)0x0;
  pEdict->pvPrivateData = (void *)0x0;
  if (0 < cb) {
    pvVar1 = Mem_Calloc(1,cb);
    pEdict->pvPrivateData = pvVar1;
  }
  return pvVar1;
}


// PvEntPrivateData  @ 00092180
void * PvEntPrivateData(edict_t_conflict *pEdict)

{
  if (pEdict != (edict_t_conflict *)0x0) {
    return pEdict->pvPrivateData;
  }
  return (void *)0x0;
}


// QuaternionMatrix  @ 00092d30
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


// QuaternionSlerp  @ 00092a60
void QuaternionSlerp(vec_t *p,vec_t *q,float t,vec_t *qt)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  double dVar10;
  double dVar11;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: float b@[???] */
  fVar1 = *p;
  fVar2 = *q;
  fVar8 = q[1];
  fVar7 = p[1] - fVar8;
  fVar6 = p[1] + fVar8;
  fVar3 = p[2];
  fVar9 = q[2];
  fVar4 = p[3];
  fVar5 = q[3];
  if ((fVar5 + fVar4) * (fVar5 + fVar4) +
      (fVar9 + fVar3) * (fVar9 + fVar3) + fVar6 * fVar6 + (fVar2 + fVar1) * (fVar2 + fVar1) + 0.0 <
      (fVar4 - fVar5) * (fVar4 - fVar5) +
      (fVar3 - fVar9) * (fVar3 - fVar9) + fVar7 * fVar7 + (fVar1 - fVar2) * (fVar1 - fVar2) + 0.0) {
    *q = -fVar2;
    fVar8 = -fVar8;
    q[1] = fVar8;
    q[2] = -fVar9;
    q[3] = -fVar5;
    fVar1 = *p;
    fVar3 = p[2];
    fVar4 = p[3];
  }
  cosom = fVar4 * q[3] + fVar3 * q[2] + p[1] * fVar8 + fVar1 * *q;
  if (cosom + 1.0 <= 1e-06) {
    *qt = -fVar8;
    qt[1] = *q;
    fVar2 = q[3];
    qt[2] = -fVar2;
    qt[3] = q[2];
    dVar11 = sin((double)((1.0 - t) * 1.5707964));
    sclp = (float)dVar11;
    dVar10 = sin((double)t * 1.5707963705062866);
    sclq = (float)dVar10;
    *qt = sclq * *qt + (float)dVar11 * *p;
    qt[1] = sclq * qt[1] + sclp * p[1];
    qt[2] = -fVar2 * sclq + p[2] * sclp;
    return;
  }
  if (1e-06 < 1.0 - cosom) {
    fVar8 = acosf(cosom);
    omega = fVar8;
    fVar9 = sinf(fVar8);
    sinom = fVar9;
    dVar11 = sin((1.0 - (double)t) * (double)fVar8);
    fVar2 = (float)dVar11 / fVar9;
    sclp = fVar2;
    dVar11 = sin((double)(fVar8 * t));
    t = (float)dVar11 / fVar9;
  }
  else {
    fVar2 = 1.0 - t;
    sclp = fVar2;
  }
  sclq = t;
  *qt = t * *q + fVar2 * *p;
  fVar8 = sclp;
  fVar2 = sclq;
  qt[1] = q[1] * sclq + p[1] * sclp;
  qt[2] = fVar2 * q[2] + fVar8 * p[2];
  qt[3] = q[3] * sclq + p[3] * sclp;
  return;
}


// QueryClientCvarValue  @ 00091370
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


// QueryClientCvarValue2  @ 00091410
void QueryClientCvarValue2(edict_t *player,char *cvarName,int requestID)

{
  int iVar1;
  sizebuf_t *sb;
  
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


// QueryClientCvarValueCmd  @ 000910b0
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
          e = (edict_t *)pcVar4->edict;
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


// QueryClientCvarValueCmd2  @ 000911e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QueryClientCvarValueCmd2(void)

{
  edict_t *e;
  int iVar1;
  char *pcVar2;
  int iVar3;
  long c;
  client_s *pcVar4;
  sizebuf_t *sb;
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
          e = (edict_t *)pcVar4->edict;
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


// RadiusFromBounds  @ 00083480
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


// RandomFloat  @ 00090740
float RandomFloat(float flLow,float flHigh)

{
  float fVar1;
  int32 iVar2;
  
                    /* Unresolved local var: float fl@[DW_OP_reg12(ST1)] */
  (*g_engdstAddrs.pfnRandomFloat)(&flLow,&flHigh);
                    /* Unresolved local var: float temp@[???] */
  iVar2 = ran1();
  fVar1 = 0.9999999;
  if ((float)iVar2 * 4.656613e-10 <= 0.9999999) {
    fVar1 = (float)iVar2 * 4.656613e-10;
  }
  return flLow + (flHigh - flLow) * fVar1;
}


// RandomLong  @ 000907a0
int32 RandomLong(int32 lLow,int32 lHigh)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: uint32 maxAcceptable@[???]
                       Unresolved local var: uint32 x@[???]
                       Unresolved local var: uint32 n@[???] */
  (*g_engdstAddrs.pfnRandomLong)(&lLow,&lHigh);
  uVar1 = (lHigh - lLow) + 1;
  if (-1 < lHigh - lLow) {
    do {
      uVar2 = ran1();
    } while (0x7fffffffU - (int)(0x80000000 % (ulonglong)uVar1) < uVar2);
    lLow = uVar2 % uVar1 + lLow;
  }
  return lLow;
}


// RegUserMsg  @ 000a87a0
int RegUserMsg(char *pszName,int iSize)

{
  UserMsg *pUVar1;
  int iVar2;
  UserMsg *pUVar3;
  int iVar4;
  
                    /* Unresolved local var: UserMsg * pUserMsgs@[???]
                       Unresolved local var: UserMsg * pNewMsg@[???]
                       Unresolved local var: int iFound@[???]
                       Unresolved local var: int iRet@[???] */
  if (0xff < giNextUserMsg) {
    Con_Printf("Not enough room to register message %s\n",pszName);
    return 0;
  }
  iVar4 = 0;
  if (pszName != (char *)0x0) {
    iVar2 = Q_strlen(pszName);
    if (0xb < iVar2) {
      Con_Printf("Message name too long: %s\n",pszName);
      return 0;
    }
    pUVar1 = sv_gpUserMsgs;
    if (iSize < 0xc1) {
      while( true ) {
        if (pUVar1 == (UserMsg *)0x0) {
          pUVar3 = Mem_ZeroMalloc(0x20);
          pUVar3->iSize = iSize;
          pUVar3->iMsg = giNextUserMsg;
          giNextUserMsg = giNextUserMsg + 1;
          Q_strcpy(pUVar3->szName,pszName);
          pUVar1 = pUVar3;
          pUVar3->next = sv_gpNewUserMsgs;
          sv_gpNewUserMsgs = pUVar1;
          return pUVar3->iMsg;
        }
        iVar4 = Q_strcmp(pszName,pUVar1->szName);
        if (iVar4 == 0) break;
        pUVar1 = pUVar1->next;
      }
      iVar4 = pUVar1->iMsg;
    }
  }
  return iVar4;
}


// RegisterTutorMessageShown  @ 000686f0
void RegisterTutorMessageShown(int mid)

{
  return;
}


// ReleaseEntityDLLFields  @ 000920d0
void ReleaseEntityDLLFields(edict_t_conflict *pEdict)

{
  void *p;
  
  p = pEdict->pvPrivateData;
  if (p != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(pEdict);
      p = pEdict->pvPrivateData;
    }
    Mem_Free(p);
  }
  pEdict->pvPrivateData = (void *)0x0;
  return;
}


// ReleaseEntityDlls  @ 00096760
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
  if (g_rgextdll < g_rgextdll + iVar1) {
    peVar2 = g_rgextdll;
    do {
      dlclose(peVar2->lDLLHandle);
      peVar2->lDLLHandle = (void *)0x0;
      if (peVar2->functionTable != (functiontable_t *)0x0) {
        Mem_Free(peVar2->functionTable);
      }
      peVar2->functionTable = (functiontable_t *)0x0;
      peVar2 = peVar2 + 1;
    } while (peVar2 < g_rgextdll + iVar1);
  }
  svs.dll_initialized = false;
  return;
}


// RemoveLink  @ 000bea30
void RemoveLink(link_t *l)

{
  l->next->prev = l->prev;
  l->prev->next = l->next;
  return;
}


// ReplyServerChallenge  @ 000a0700
void ReplyServerChallenge(netadr_t *adr)

{
  int c;
  sizebuf_t local_30;
  byte local_1c [20];
  
                    /* Unresolved local var: char[16] buffer@[???]
                       Unresolved local var: sizebuf_t buf@[???] */
  local_30.buffername = "SVC_Challenge";
  local_30.maxsize = 0x10;
  local_30.cursize = 0;
  local_30.data = local_1c;
  local_30.flags = 1;
  MSG_WriteLong(&local_30,-1);
  MSG_WriteByte(&local_30,0x41);
  c = GetChallengeNr(adr);
  MSG_WriteLong(&local_30,c);
  NET_SendPacket(NS_SERVER,local_30.cursize,local_30.data,*adr);
  return;
}


// RequireValidChallenge  @ 000a0420
qboolean RequireValidChallenge(netadr_t *adr)

{
  return (uint)(sv_enableoldqueries.value == 0.0);
}


// ResetTutorMessageDecayData  @ 00068700
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ResetTutorMessageDecayData(void)

{
  return;
}


// SafeRead  @ 000bc9e0
void SafeRead(FileHandle_t f,void *buffer,int count)

{
  int iVar1;
  
  iVar1 = FS_Read(buffer,count,1,f);
  if (iVar1 != count) {
    Sys_Error("File read failure");
    return;
  }
  return;
}


// SaveExit  @ 00079a80
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


// SaveGame  @ 0007c4c0
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


// SaveGameSlot  @ 0007be40
BOOL SaveGameSlot(char *pSaveName,char *pSaveComment)

{
  char cVar1;
  SAVERESTOREDATA *pSVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  FileHandle_t file;
  int iVar6;
  char *str;
  int iVar7;
  char local_49c [260];
  char local_398 [260];
  char local_294 [256];
  char local_194 [256];
  char local_94 [31];
  undefined1 local_75;
  char local_74 [79];
  undefined1 local_25;
  int local_24;
  undefined4 local_20 [4];
  
                    /* Unresolved local var: char[256] hlPath@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: char * pTokenData@[???]
                       Unresolved local var: int tag@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: FILE * pFile@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: GAME_HEADER gameHeader@[???] */
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
  FS_CreateDirHierarchy(Host_SaveGameDirectory::szDirectory,"GAMECONFIG");
  pSVar2 = SaveGamestate();
  if (pSVar2 == (SAVERESTOREDATA *)0x0) {
    return 0;
  }
  if (pSVar2->pTokens != (char **)0x0) {
    Mem_Free(pSVar2->pTokens);
    pSVar2->pTokens = (char **)0x0;
    pSVar2->tokenCount = 0;
  }
  Mem_Free(pSVar2);
  gGlobalVariables.pSaveData = (void *)0x0;
  pSVar2 = SaveInit((int)pSVar2);
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: char * findfn@[???] */
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
  snprintf(local_294,0x100,"%s*.HL?",Host_SaveGameDirectory::szDirectory);
  COM_FixSlashes(local_294);
  pcVar3 = Sys_FindFirstPathID(local_294,"GAMECONFIG");
  local_24 = 0;
  while (pcVar3 != (char *)0x0) {
    pcVar3 = Sys_FindNext((char *)0x0);
    local_24 = local_24 + 1;
  }
  Sys_FindClose();
  Q_strncpy(local_94,sv.name,0x1f);
  local_75 = 0;
  Q_strncpy(local_74,pSaveComment,0x4f);
  local_25 = 0;
  (*gEntityInterface.pfnSaveWriteFields)(pSVar2,"GameHeader",local_94,gGameHeaderDescription,3);
  (*gEntityInterface.pfnSaveGlobalState)(pSVar2);
  pcVar3 = pSVar2->pCurrentData;
  iVar7 = 0;
  if (pSVar2->pTokens != (char **)0x0) {
    iVar7 = 0;
    if (0 < pSVar2->tokenCount) {
      str = *pSVar2->pTokens;
      do {
        if (str == (char *)0x0) {
          iVar4 = pSVar2->size + 1;
          pSVar2->size = iVar4;
          if (pSVar2->bufferSize < iVar4) goto LAB_0007c485;
          pcVar5 = pSVar2->pCurrentData;
          *pcVar5 = '\0';
          pcVar5 = pcVar5 + 1;
          pSVar2->pCurrentData = pcVar5;
          if (pSVar2->tokenCount <= iVar7 + 1) goto LAB_0007c09e;
        }
        else {
                    /* Unresolved local var: char * pszToken@[???] */
          iVar6 = pSVar2->size;
          iVar4 = Q_strlen(str);
          iVar4 = iVar6 + 1 + iVar4;
          pSVar2->size = iVar4;
          if (pSVar2->bufferSize < iVar4) {
LAB_0007c485:
            Con_Printf("Token Table Save/Restore overflow!");
            pSVar2->size = pSVar2->bufferSize;
            pSVar2->tokenSize = (int)pSVar2->pCurrentData - (int)pcVar3;
            goto LAB_0007c0b6;
          }
          pcVar5 = pSVar2->pCurrentData;
          do {
            cVar1 = *str;
            str = str + 1;
            *pcVar5 = cVar1;
            pcVar5 = pcVar5 + 1;
            pSVar2->pCurrentData = pcVar5;
          } while (cVar1 != '\0');
          if (pSVar2->tokenCount <= iVar7 + 1) goto LAB_0007c09e;
        }
        iVar7 = iVar7 + 1;
        str = pSVar2->pTokens[iVar7];
      } while( true );
    }
    iVar4 = pSVar2->size;
    iVar7 = 0;
    iVar6 = pSVar2->bufferSize;
    goto LAB_0007c0aa;
  }
LAB_0007c0a4:
  iVar4 = pSVar2->size;
  iVar6 = pSVar2->bufferSize;
LAB_0007c0aa:
  pSVar2->tokenSize = iVar7;
  if (iVar4 < iVar6) {
    pSVar2->size = iVar4 - iVar7;
  }
LAB_0007c0b6:
  Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
  snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
  snprintf(local_194,0xfc,"%s%s",Host_SaveGameDirectory::szDirectory,pSaveName);
  COM_DefaultExtension(local_194,".sav");
  COM_FixSlashes(local_194);
  Con_DPrintf("Saving game to %s...\n",local_194);
  iVar7 = Q_stricmp(pSaveName,"quick");
  if ((iVar7 != 0) || (iVar7 = Q_stricmp(pSaveName,"autosave"), iVar7 != 0)) {
                    /* Unresolved local var: char[260] newName@[???]
                       Unresolved local var: char[260] oldName@[???] */
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
    snprintf(local_49c,0x104,"%s%s%02d.sav",Host_SaveGameDirectory::szDirectory,pSaveName,1);
    COM_FixSlashes(local_49c);
    FS_RemoveFile(local_49c,"GAMECONFIG");
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
    snprintf(local_398,0x104,"%s%s.sav",Host_SaveGameDirectory::szDirectory,pSaveName);
    COM_FixSlashes(local_398);
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
    snprintf(local_49c,0x104,"%s%s%02d.sav",Host_SaveGameDirectory::szDirectory,pSaveName,1);
    COM_FixSlashes(local_49c);
    FS_Rename(local_398,local_49c);
  }
  file = FS_OpenPathID(local_194,"wb","GAMECONFIG");
  local_20[0] = 0x5641534a;
  FS_Write(local_20,4,1,file);
  local_20[0] = 0x71;
  FS_Write(local_20,4,1,file);
  FS_Write(&pSVar2->size,4,1,file);
  FS_Write(&pSVar2->tokenCount,4,1,file);
  FS_Write(&pSVar2->tokenSize,4,1,file);
  FS_Write(pcVar3,pSVar2->tokenSize,1,file);
  FS_Write(pSVar2->pBaseData,pSVar2->size,1,file);
  DirectoryCopy(local_294,file);
  FS_Close(file);
  if (pSVar2->pTokens != (char **)0x0) {
    Mem_Free(pSVar2->pTokens);
    pSVar2->pTokens = (char **)0x0;
    pSVar2->tokenCount = 0;
  }
  Mem_Free(pSVar2);
  gGlobalVariables.pSaveData = (void *)0x0;
  return 1;
LAB_0007c09e:
  iVar7 = (int)pcVar5 - (int)pcVar3;
  goto LAB_0007c0a4;
}


// SaveGamestate  @ 0007a550
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

SAVERESTOREDATA * SaveGamestate(void)

{
  int *piVar1;
  char cVar2;
  edict_t_conflict *peVar3;
  char **ppcVar4;
  FileHandle_t file;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  SAVERESTOREDATA *pSaveData;
  char *pcVar8;
  int local_1fc;
  int local_1f8;
  char *local_1f4;
  char local_1e4 [256];
  undefined1 local_e4 [4];
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  float local_cc;
  char local_c8 [31];
  undefined1 local_a9;
  char local_a8 [31];
  undefined1 local_89;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  char local_6c [63];
  undefined1 local_2d;
  int local_2c [7];
  
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
  pSaveData = (SAVERESTOREDATA *)0x0;
  if (gEntityInterface.pfnParmsChangeLevel != (_func_void *)0x0) {
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
    pcVar8 = Host_SaveGameDirectory::szDirectory;
    FS_CreateDirHierarchy(Host_SaveGameDirectory::szDirectory,"GAMECONFIG");
    pSaveData = SaveInit((int)pcVar8);
    Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
    snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
    snprintf(local_1e4,0x100,"%s%s.HL1",Host_SaveGameDirectory::szDirectory,0x506a28);
    COM_FixSlashes(local_1e4);
    (*gEntityInterface.pfnParmsChangeLevel)();
    local_e0 = build_number();
    local_cc = (float)sv.time;
    local_dc = (int)skill.value;
    local_d8 = pSaveData->tableCount;
    local_d4 = pSaveData->connectionCount;
    Q_strncpy(local_a8,sv_skyname.string,0x1f);
    pSaveData->time = 0.0;
    local_89 = 0;
    local_74 = 0;
    local_78 = 0;
    local_7c = 0;
    local_80 = 0;
    local_84 = 0;
    local_88 = 0;
    Q_strncpy(local_c8,sv.name,0x1f);
    local_d0 = 0;
    local_a9 = 0;
    ppcVar4 = sv.lightstyles;
    do {
      local_d0 = (local_d0 + 1) - (uint)(*ppcVar4 == (char *)0x0);
      ppcVar4 = ppcVar4 + 1;
    } while (ppcVar4 != (char **)&sv.num_edicts);
    local_2c[0] = 0x40;
    (*gEntityInterface.pfnSaveWriteFields)
              (pSaveData,"Save Header",local_e4,gSaveHeaderDescription,0xd);
    pSaveData->time = local_cc;
    local_2c[0] = 0;
    if (0 < pSaveData->connectionCount) {
      do {
        (*gEntityInterface.pfnSaveWriteFields)
                  (pSaveData,"ADJACENCY",pSaveData->levelList + local_2c[0],gAdjacencyDescription,4)
        ;
        local_2c[0] = local_2c[0] + 1;
      } while (local_2c[0] < pSaveData->connectionCount);
    }
    local_2c[0] = 0;
    do {
      if (sv.lightstyles[local_2c[0]] != (char *)0x0) {
        local_70 = local_2c[0];
        Q_strncpy(local_6c,sv.lightstyles[local_2c[0]],0x3f);
        local_2d = 0;
        (*gEntityInterface.pfnSaveWriteFields)
                  (pSaveData,"LIGHTSTYLE",&local_70,gLightstyleDescription,2);
      }
      local_2c[0] = local_2c[0] + 1;
    } while (local_2c[0] < 0x40);
    local_2c[0] = 0;
    if (sv.num_edicts < 1) {
      local_1f8 = pSaveData->size;
      pcVar8 = pSaveData->pCurrentData;
      local_1fc = 0;
      local_1f4 = pcVar8;
    }
    else {
      do {
        peVar3 = sv.edicts;
        pSaveData->currentIndex = local_2c[0];
        pSaveData->pTable[local_2c[0]].location = pSaveData->size;
        pSaveData->pTable[local_2c[0]].size = 0;
        if (((peVar3[local_2c[0]].free == 0) &&
            ((*gEntityInterface.pfnSave)(peVar3 + local_2c[0],pSaveData), 0 < local_2c[0])) &&
           (local_2c[0] <= svs.maxclients)) {
          piVar1 = &pSaveData->pTable[local_2c[0]].flags;
          *piVar1 = *piVar1 | 0x80000000;
        }
        local_2c[0] = local_2c[0] + 1;
      } while (local_2c[0] < sv.num_edicts);
      local_1f8 = pSaveData->size;
      local_2c[0] = 0;
      local_1f4 = pSaveData->pCurrentData;
      if (sv.num_edicts < 1) {
        local_1fc = 0;
        pcVar8 = local_1f4;
      }
      else {
        do {
          (*gEntityInterface.pfnSaveWriteFields)
                    (pSaveData,"ETABLE",pSaveData->pTable + local_2c[0],gEntityTableDescription,5);
          local_2c[0] = local_2c[0] + 1;
        } while (local_2c[0] < sv.num_edicts);
        local_1fc = pSaveData->size - local_1f8;
        pcVar8 = pSaveData->pCurrentData;
      }
    }
    iVar5 = 0;
    if ((pSaveData->pTokens != (char **)0x0) && (local_2c[0] = 0, 0 < pSaveData->tokenCount)) {
      pcVar7 = *pSaveData->pTokens;
      pcVar6 = pcVar8;
      if (pcVar7 == (char *)0x0) goto LAB_0007ac10;
      do {
        do {
                    /* Unresolved local var: char * pszToken@[???] */
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          *pcVar6 = cVar2;
          pcVar6 = pcVar6 + 1;
          pSaveData->pCurrentData = pcVar6;
        } while (cVar2 != '\0');
        while( true ) {
          local_2c[0] = local_2c[0] + 1;
          if (pSaveData->tokenCount <= local_2c[0]) {
            iVar5 = (int)pcVar6 - (int)pcVar8;
            goto LAB_0007a91a;
          }
          pcVar7 = pSaveData->pTokens[local_2c[0]];
          if (pcVar7 != (char *)0x0) break;
LAB_0007ac10:
          *pcVar6 = '\0';
          pcVar6 = pcVar6 + 1;
          pSaveData->pCurrentData = pcVar6;
        }
      } while( true );
    }
LAB_0007a91a:
    pSaveData->tokenSize = iVar5;
    COM_CreatePath(local_1e4);
    file = FS_OpenPathID(local_1e4,"wb","GAMECONFIG");
    if (file == (FileHandle_t)0x0) {
      pSaveData = (SAVERESTOREDATA *)0x0;
      Con_Printf("Unable to open save game file %s.",local_1e4);
    }
    else {
      local_2c[0] = 0x564c4156;
      FS_Write(local_2c,4,1,file);
      local_2c[0] = 0x71;
      FS_Write(local_2c,4,1,file);
      FS_Write(&pSaveData->size,4,1,file);
      FS_Write(&pSaveData->tableCount,4,1,file);
      FS_Write(&pSaveData->tokenCount,4,1,file);
      FS_Write(&pSaveData->tokenSize,4,1,file);
      FS_Write(pcVar8,pSaveData->tokenSize,1,file);
      FS_Write(local_1f4,local_1fc,1,file);
      FS_Write(pSaveData->pBaseData,local_1f8,1,file);
      FS_Close(file);
      EntityPatchWrite(pSaveData,sv.name);
      Q_memset(Host_SaveGameDirectory::szDirectory,0,0x104);
      snprintf(Host_SaveGameDirectory::szDirectory,0x104,"SAVE/");
      snprintf(local_1e4,0x100,"%s%s.HL2",Host_SaveGameDirectory::szDirectory,0x506a28);
      COM_FixSlashes(local_1e4);
    }
  }
  return pSaveData;
}


// SaveInit  @ 00077650
SAVERESTOREDATA * SaveInit(int size)

{
  int iVar1;
  edict_t_conflict *peVar2;
  SAVERESTOREDATA *pSVar3;
  char **ppcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * pEdict@[???] */
  pSVar3 = Mem_Calloc(sv.num_edicts * 0x18 + 0x80574,1);
  pSVar3->pTable = (ENTITYTABLE *)(pSVar3 + 1);
  pSVar3->tokenSize = 0;
  pSVar3->tokenCount = 0xfff;
  ppcVar4 = Mem_Calloc(0xfff,4);
  pSVar3->pTokens = ppcVar4;
  if (0 < sv.num_edicts) {
    iVar5 = 0;
    iVar6 = 0;
    iVar7 = 0;
    do {
      peVar2 = sv.edicts;
      *(int *)((int)&pSVar3->pTable->id + iVar5) = iVar7;
      iVar7 = iVar7 + 1;
      iVar1 = iVar6 + -0x18;
      iVar6 = iVar6 + 0x324;
      *(int *)((int)&pSVar3->pTable->pent + iVar5) = (int)peVar2->leafnums + iVar1;
      *(undefined4 *)((int)&pSVar3->pTable->flags + iVar5) = 0;
      *(undefined4 *)((int)&pSVar3->pTable->location + iVar5) = 0;
      *(undefined4 *)((int)&pSVar3->pTable->size + iVar5) = 0;
      *(undefined4 *)((int)&pSVar3->pTable->classname + iVar5) = 0;
      iVar5 = iVar5 + 0x18;
    } while (iVar7 < sv.num_edicts);
  }
  pSVar3->tableCount = sv.num_edicts;
  pSVar3->connectionCount = 0;
  iVar5 = sv.num_edicts;
  pSVar3->size = 0;
  pSVar3->bufferSize = 0x80000;
  pSVar3->fUseLandmark = 0;
  pSVar3->pBaseData = (char *)(pSVar3->pTable + iVar5);
  pSVar3->pCurrentData = (char *)(pSVar3->pTable + iVar5);
  gGlobalVariables.pSaveData = pSVar3;
  pSVar3->time = gGlobalVariables.time;
  pSVar3->vecLandmarkOffset[0] = vec3_origin[0];
  pSVar3->vecLandmarkOffset[1] = vec3_origin[1];
  pSVar3->vecLandmarkOffset[2] = vec3_origin[2];
  return pSVar3;
}


// SaveInit  @ 00079930
SAVERESTOREDATA * SaveInit(int size)

{
  int iVar1;
  edict_t_conflict *peVar2;
  SAVERESTOREDATA *pSVar3;
  char **ppcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * pEdict@[???] */
  if (size < 1) {
    size = 0x80000;
  }
  pSVar3 = Mem_Calloc(size + 0x574 + sv.num_edicts * 0x18,1);
  pSVar3->pTable = (ENTITYTABLE *)(pSVar3 + 1);
  pSVar3->tokenSize = 0;
  pSVar3->tokenCount = 0xfff;
  ppcVar4 = Mem_Calloc(0xfff,4);
  pSVar3->pTokens = ppcVar4;
  if (0 < sv.num_edicts) {
    iVar5 = 0;
    iVar6 = 0;
    iVar7 = 0;
    do {
      peVar2 = sv.edicts;
      *(int *)((int)&pSVar3->pTable->id + iVar5) = iVar7;
      iVar7 = iVar7 + 1;
      iVar1 = iVar6 + -0x18;
      iVar6 = iVar6 + 0x324;
      *(int *)((int)&pSVar3->pTable->pent + iVar5) = (int)peVar2->leafnums + iVar1;
      *(undefined4 *)((int)&pSVar3->pTable->flags + iVar5) = 0;
      *(undefined4 *)((int)&pSVar3->pTable->location + iVar5) = 0;
      *(undefined4 *)((int)&pSVar3->pTable->size + iVar5) = 0;
      *(undefined4 *)((int)&pSVar3->pTable->classname + iVar5) = 0;
      iVar5 = iVar5 + 0x18;
    } while (iVar7 < sv.num_edicts);
  }
  pSVar3->tableCount = sv.num_edicts;
  pSVar3->connectionCount = 0;
  iVar5 = sv.num_edicts;
  pSVar3->size = 0;
  pSVar3->bufferSize = size;
  pSVar3->fUseLandmark = 0;
  pSVar3->pBaseData = (char *)(pSVar3->pTable + iVar5);
  pSVar3->pCurrentData = (char *)(pSVar3->pTable + iVar5);
  gGlobalVariables.pSaveData = pSVar3;
  pSVar3->time = gGlobalVariables.time;
  pSVar3->vecLandmarkOffset[0] = vec3_origin[0];
  pSVar3->vecLandmarkOffset[1] = vec3_origin[1];
  pSVar3->vecLandmarkOffset[2] = vec3_origin[2];
  return pSVar3;
}


// SaveReadComment  @ 00079b60
void SaveReadComment(FileHandle_t f,char *name)

{
  int iVar1;
  GAME_HEADER local_84;
  int local_10 [2];
  
                    /* Unresolved local var: GAME_HEADER gameHeader@[???] */
                    /* Unresolved local var: int tag@[???]
                       Unresolved local var: char * pszTokenList@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int tokenCount@[???]
                       Unresolved local var: int tokenSize@[???] */
  FS_Read(local_10,4,1,f);
  if ((local_10[0] == 0x5641534a) && (FS_Read(local_10,4,1,f), local_10[0] == 0x71)) {
    iVar1 = SaveReadHeader(f,&local_84,0);
    if (iVar1 == 0) {
      return;
    }
    Q_strcpy(name,local_84.comment);
    return;
  }
  FS_Close(f);
  return;
}


// SaveReadHeader  @ 00077950
int __regparm3 SaveReadHeader(FileHandle_t pFile,GAME_HEADER *pHeader,int readGlobalState)

{
  SAVERESTOREDATA *p;
  char **ppcVar1;
  int iVar2;
  SAVERESTOREDATA *pSVar3;
  SAVERESTOREDATA *pOutput;
  int local_3c [4];
  int local_2c [3];
  int local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int tag@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int tokenCount@[???]
                       Unresolved local var: int tokenSize@[???]
                       Unresolved local var: char * pszTokenList@[???]
                       Unresolved local var: SAVERESTOREDATA * pSaveData@[???] */
  FS_Read(local_20,4,1,pFile);
  FS_Read(local_3c,4,1,pFile);
  FS_Read(local_2c,4,1,pFile);
  if ((((-1 < local_20[0]) && (-1 < local_3c[0])) && (-1 < local_2c[0])) &&
     ((local_2c[0] <= 0x7fffffff - local_20[0] &&
      (0x573 < 0x7fffffffU - (local_20[0] + local_2c[0]))))) {
    p = Mem_Calloc(local_20[0] + local_2c[0] + 0x574,1);
    if (p != (SAVERESTOREDATA *)0x0) {
      p->tableCount = 0;
      pOutput = p + 1;
      p->pTable = (ENTITYTABLE *)0x0;
      p->connectionCount = 0;
      if (0 < local_2c[0]) {
        p->tokenSize = local_2c[0];
        p->tokenCount = local_3c[0];
        FS_Read(pOutput,local_2c[0],1,pFile);
        ppcVar1 = p->pTokens;
        if (ppcVar1 == (char **)0x0) {
          ppcVar1 = Mem_Calloc(local_3c[0],4);
          p->pTokens = ppcVar1;
        }
        if (0 < local_3c[0]) {
          iVar2 = 0;
          while( true ) {
            pSVar3 = (SAVERESTOREDATA *)0x0;
            if (*(char *)&pOutput->pBaseData != '\0') {
              pSVar3 = pOutput;
            }
            ppcVar1[iVar2] = (char *)pSVar3;
            do {
              ppcVar1 = &pOutput->pBaseData;
              pOutput = (SAVERESTOREDATA *)((int)&pOutput->pBaseData + 1);
            } while (*(char *)ppcVar1 != '\0');
            iVar2 = iVar2 + 1;
            if (local_3c[0] <= iVar2) break;
            ppcVar1 = p->pTokens;
          }
        }
      }
      p->pBaseData = (char *)pOutput;
      p->size = 0;
      p->time = 0.0;
      p->bufferSize = local_20[0];
      p->fUseLandmark = 0;
      p->pCurrentData = (char *)pOutput;
      FS_Read(pOutput,local_20[0],1,pFile);
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


// SaveReadHeader  @ 00079ac0
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


// SaveSpawnParms  @ 000924d0
void SaveSpawnParms(edict_t_conflict *pEdict)

{
  uint uVar1;
  
                    /* Unresolved local var: int eoffset@[DW_OP_reg3(EBX)]
                       Unresolved local var: client_t * client@[???] */
                    /* Unresolved local var: int b@[???] */
  uVar1 = (uint)((int)pEdict - (int)sv.edicts) / 0x324;
  if (sv.num_edicts <= (int)uVar1) {
    Sys_Error("NUM_FOR_EDICT: bad pointer");
  }
  if ((uVar1 != 0) && ((int)uVar1 <= svs.maxclients)) {
    return;
  }
  Host_Error("Entity is not a client");
  return;
}


// SeedRandomNumberGenerator  @ 000905c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SeedRandomNumberGenerator(void)

{
  time_t tVar1;
  
  tVar1 = time((time_t *)0x0);
  idum = -tVar1;
  if (tVar1 == -1000 || idum < 1000) {
    if (-1000 < idum) {
      idum = -0x153ad38 - tVar1;
    }
    return;
  }
  idum = tVar1;
  return;
}


// ServerPrint  @ 0008be50
void ServerPrint(char *szMsg)

{
  Con_Printf("%s",szMsg);
  return;
}


// SetCStrikeFlags  @ 000a7740
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


// SetCareerAudioState  @ 00068710
void SetCareerAudioState(int state)

{
  return;
}


// SetLoadingProgressBarStatusText  @ 000c7ab0
void SetLoadingProgressBarStatusText(char *statusText)

{
  return;
}


// SetMinMaxSize  @ 0008baf0
void SetMinMaxSize(edict_t_conflict *e,float *min,float *max,qboolean rotate)

{
  float fVar1;
  float fVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  
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
    Host_Error("backwards mins/maxs");
    if (min[1] <= max[1]) goto LAB_0008bb31;
LAB_0008bbd6:
    Host_Error("backwards mins/maxs");
    fVar1 = min[2];
    fVar2 = max[2];
    if (fVar1 <= fVar2) goto LAB_0008bb41;
  }
  else {
    if (max[1] < min[1]) goto LAB_0008bbd6;
LAB_0008bb31:
    fVar1 = min[2];
    fVar2 = max[2];
    if (fVar1 <= fVar2) goto LAB_0008bb41;
  }
  Host_Error("backwards mins/maxs");
  fVar1 = min[2];
  fVar2 = max[2];
LAB_0008bb41:
  vVar3 = *min;
  vVar4 = max[1];
  vVar5 = min[1];
  vVar6 = *max;
  (e->v).mins[2] = fVar1;
  (e->v).mins[0] = vVar3;
  (e->v).maxs[2] = fVar2;
  (e->v).maxs[1] = vVar4;
  (e->v).mins[1] = vVar5;
  (e->v).maxs[0] = vVar6;
  (e->v).size[0] = *max - *min;
  (e->v).size[1] = max[1] - min[1];
  (e->v).size[2] = max[2] - min[2];
  SV_LinkEdict(e,false);
  return;
}


// SetRateRegistrySetting  @ 00097cf0
void SetRateRegistrySetting(char *pchRate)

{
  (*registry->_vptr_IRegistry[5])(registry,"rate",pchRate);
  return;
}


// ShortNoSwap  @ 0005ef60
short ShortNoSwap(short l)

{
  return l;
}


// ShortSwap  @ 0005ef40
short ShortSwap(short l)

{
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???] */
  return ((ushort)l >> 8) + l * 0x100;
}


// SkipSpace  @ 000bbe70
char * SkipSpace(char *pText)

{
  char cVar1;
  
  if (pText != (char *)0x0) {
                    /* Unresolved local var: int pos@[???] */
    cVar1 = *pText;
    while ((cVar1 != '\0' &&
           ((((cVar1 == '\t' || (cVar1 == ' ')) || (cVar1 == '\n')) || (cVar1 == '\r'))))) {
      cVar1 = pText[1];
      pText = pText + 1;
    }
  }
  return pText;
}


// SkipText  @ 000bbec0
char * SkipText(char *pText)

{
  char cVar1;
  
                    /* Unresolved local var: int pos@[???] */
  if ((((pText != (char *)0x0) && (cVar1 = *pText, cVar1 != '\0')) && (cVar1 != ' ')) &&
     ((cVar1 != '\t' && (cVar1 != '\r' && cVar1 != '\n')))) {
    do {
      pText = pText + 1;
      cVar1 = *pText;
      if (cVar1 == '\0') {
        return pText;
      }
      if (cVar1 == '\t') {
        return pText;
      }
      if (cVar1 == ' ') {
        return pText;
      }
    } while (cVar1 != '\n' && cVar1 != '\r');
  }
  return pText;
}


// SockadrToNetadr  @ 000c4240
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


// StartLoadingProgressBar  @ 000c7a90
void StartLoadingProgressBar(char *loadingType,int numProgressPoints)

{
  return;
}


// Steam3Client  @ 000d0420
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CSteam3Client * Steam3Client(void)

{
  return &s_Steam3Client;
}


// Steam3Server  @ 000d0410
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CSteam3Server * Steam3Server(void)

{
  return s_Steam3Server;
}


// StringToFilter  @ 000a88a0
qboolean StringToFilter(char *s,ipfilter_t *f)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_bc [128];
  uint local_3c [4];
  uint local_2c [7];
  
                    /* Unresolved local var: char[128] num@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uchar[4] b@[???]
                       Unresolved local var: uchar[4] m@[???] */
  iVar4 = 0;
  local_3c[0] = 0;
  local_2c[0] = 0;
  do {
    cVar1 = *s;
    if (9 < (byte)(cVar1 - 0x30U)) {
      Con_Printf("Bad filter address: %s\n",s);
      return false;
    }
    iVar3 = 0;
    do {
      iVar2 = iVar3;
      local_bc[iVar2] = cVar1;
      iVar3 = iVar2 + 1;
      cVar1 = s[iVar3];
    } while ((byte)(cVar1 - 0x30U) < 10);
    local_bc[iVar2 + 1] = '\0';
    iVar2 = Q_atoi(local_bc);
    *(char *)((int)local_3c + iVar4) = (char)iVar2;
    if ((char)iVar2 != '\0') {
      *(undefined1 *)((int)local_2c + iVar4) = 0xff;
    }
    if (s[iVar3] == '\0') break;
    iVar4 = iVar4 + 1;
    s = s + iVar3 + 1;
  } while (iVar4 != 4);
  f->mask = local_2c[0];
  f->compare = local_3c[0];
  return true;
}


// SurfaceAtPoint  @ 0008c5e0
msurface_t * SurfaceAtPoint(model_t *pModel,mnode_t *node,vec_t *start,vec_t *end)

{
  float fVar1;
  float fVar2;
  float fVar3;
  mplane_t *pmVar4;
  mtexinfo_t *pmVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  uint uVar9;
  msurface_t *pmVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float local_2c;
  float local_28;
  float local_24;
  
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
    return (msurface_t *)0x0;
  }
  pmVar4 = node->plane;
  fVar1 = *start;
  fVar2 = start[1];
  fVar3 = start[2];
  fVar7 = (fVar3 * pmVar4->normal[2] + fVar2 * pmVar4->normal[1] + fVar1 * pmVar4->normal[0]) -
          pmVar4->dist;
  fVar6 = (pmVar4->normal[1] * end[1] + pmVar4->normal[0] * *end + pmVar4->normal[2] * end[2]) -
          pmVar4->dist;
  uVar8 = (uint)(fVar7 < 0.0);
  uVar9 = (uint)(fVar6 < 0.0);
  if (uVar9 != uVar8) {
    fVar7 = fVar7 / (fVar7 - fVar6);
    fVar1 = (*end - fVar1) * fVar7 + fVar1;
    fVar2 = (end[1] - fVar2) * fVar7 + fVar2;
    fVar3 = (end[2] - fVar3) * fVar7 + fVar3;
    local_2c = fVar1;
    local_28 = fVar2;
    local_24 = fVar3;
    pmVar10 = SurfaceAtPoint(pModel,node->children[uVar8],start,&local_2c);
    if (pmVar10 != (msurface_t *)0x0) {
      return pmVar10;
    }
    if (node->numsurfaces != 0) {
      pmVar10 = pModel->surfaces + node->firstsurface;
      iVar11 = 0;
      do {
        pmVar5 = pmVar10->texinfo;
        iVar12 = (int)(pmVar5->vecs[0][2] * fVar3 +
                       pmVar5->vecs[0][1] * fVar2 + pmVar5->vecs[0][0] * fVar1 + pmVar5->vecs[0][3])
        ;
        if (pmVar10->texturemins[0] <= iVar12) {
          iVar13 = (int)(pmVar5->vecs[1][2] * fVar3 +
                         pmVar5->vecs[1][1] * fVar2 + pmVar5->vecs[1][0] * fVar1 +
                        pmVar5->vecs[1][3]);
          if (((pmVar10->texturemins[1] <= iVar13) &&
              (iVar12 - pmVar10->texturemins[0] <= (int)pmVar10->extents[0])) &&
             (iVar13 - pmVar10->texturemins[1] <= (int)pmVar10->extents[1])) {
            return pmVar10;
          }
        }
        iVar11 = iVar11 + 1;
        pmVar10 = pmVar10 + 1;
      } while (iVar11 < (int)(uint)node->numsurfaces);
    }
    start = &local_2c;
    uVar9 = (uint)(uVar8 == 0);
  }
  pmVar10 = SurfaceAtPoint(pModel,node->children[uVar9],start,end);
  return pmVar10;
}


// SwapPic  @ 000be9f0
void SwapPic(qpic_t *pic)

{
  int32 iVar1;
  
  iVar1 = (*LittleLong)(pic->width);
  pic->width = iVar1;
  iVar1 = (*LittleLong)(pic->height);
  pic->height = iVar1;
  return;
}


// SystemWrapper::AddModule  @ 000992a0
/* DWARF original prototype: bool AddModule(SystemWrapper * this, ISystemModule * module, char *
   name) */

bool __thiscall SystemWrapper::AddModule(SystemWrapper *this,ISystemModule *module,char *name)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if (module != (ISystemModule *)0x0) {
    iVar1 = (*(module->super_IBaseInterface)._vptr_IBaseInterface[2])
                      (module,this,this->m_SerialCounter,name);
    if ((char)iVar1 == '\0') {
      (**(code **)((int)this->super_IBaseSystem + 0x4c))
                (this,"ERROR! System::AddModule: couldn\'t initialize module %s.\n",name);
    }
    else {
      bVar2 = true;
      ObjectList::AddHead(&this->m_Modules,module);
      this->m_SerialCounter = this->m_SerialCounter + 1;
    }
  }
  return bVar2;
}


// SystemWrapper::CheckParam  @ 000990c0
/* DWARF original prototype: char * CheckParam(SystemWrapper * this, char * param) */

char * __thiscall SystemWrapper::CheckParam(SystemWrapper *this,char *param)

{
  int iVar1;
  char *pcVar2;
  
                    /* Unresolved local var: int pos@[???] */
  iVar1 = COM_CheckParm(param);
  pcVar2 = (char *)0x0;
  if (iVar1 != 0) {
    pcVar2 = "";
    if (iVar1 + 1 < com_argc) {
      pcVar2 = com_argv[iVar1 + 1];
    }
  }
  return pcVar2;
}


// SystemWrapper::DPrintf  @ 00098ec0
/* DWARF original prototype: void DPrintf(SystemWrapper * this, char * fmt, ...) */

void __thiscall SystemWrapper::DPrintf(SystemWrapper *this,char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  vsnprintf(DPrintf::lexical_block_0::string,0x2000,fmt,&stack0x0000000c);
  Con_DPrintf(DPrintf::lexical_block_0::string);
  return;
}


// SystemWrapper::DispatchCommand  @ 0009a1b0
/* DWARF original prototype: bool DispatchCommand(SystemWrapper * this, char * command) */

bool __thiscall SystemWrapper::DispatchCommand(SystemWrapper *this,char *command)

{
  char *__s;
  size_t __n;
  int iVar1;
  
                    /* Unresolved local var: command_t * cmd@[???] */
  if ((command != (char *)0x0) && (*command != '\0')) {
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


// SystemWrapper::Errorf  @ 00098e40
/* DWARF original prototype: void Errorf(SystemWrapper * this, char * fmt, ...) */

void __thiscall SystemWrapper::Errorf(SystemWrapper *this,char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  vsnprintf(Errorf::lexical_block_0::string,0x400,fmt,&stack0x0000000c);
  (**(code **)((int)this->super_IBaseSystem + 0x4c))(this,"***** FATAL ERROR *****\n");
  (**(code **)((int)this->super_IBaseSystem + 0x4c))
            (this,&DAT_000e5296,Errorf::lexical_block_0::string);
  (**(code **)((int)this->super_IBaseSystem + 0x4c))(this,"*** STOPPING SYSTEM ***\n");
  (**(code **)((int)this->super_IBaseSystem + 0x9c))(this);
  return;
}


// SystemWrapper::ExecuteCommand  @ 0009a050
/* virtual thunk to SystemWrapper::ExecuteCommand(int, char*) */

void __thiscall SystemWrapper::ExecuteCommand(SystemWrapper *this,int param_1,char *param_2)

{
  ExecuteCommand((SystemWrapper *)
                 ((this->super_BaseSystemModule).m_Name +
                 *(int *)((int)this->super_IBaseSystem + -0x1c) + -0x20),param_1,param_2);
  return;
}


// SystemWrapper::ExecuteCommand  @ 0009a060
/* non-virtual thunk to SystemWrapper::ExecuteCommand(int, char*) */

void __thiscall SystemWrapper::ExecuteCommand(SystemWrapper *this,int param_1,char *param_2)

{
  ExecuteCommand((SystemWrapper *)&this[-1].m_EngineWrapper,param_1,param_2);
  return;
}


// SystemWrapper::ExecuteCommand  @ 0009a070
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
                    /* WARNING: Could not recover jumptable at 0x0009a0a1. Too many branches */
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


// SystemWrapper::ExecuteFile  @ 00098f00
/* DWARF original prototype: void ExecuteFile(SystemWrapper * this, char * filename) */

void __thiscall SystemWrapper::ExecuteFile(SystemWrapper *this,char *filename)

{
  char local_40c [1023];
  undefined1 local_d;
  
                    /* Unresolved local var: char[1024] cmd@[???] */
  snprintf(local_40c,0x3ff,"exec %s\n",filename);
  local_d = 0;
  Cmd_ExecuteString(local_40c,src_command);
  return;
}


// SystemWrapper::ExecuteString  @ 0009a260
/* DWARF original prototype: void ExecuteString(SystemWrapper * this, char * commands) */

void __thiscall SystemWrapper::ExecuteString(SystemWrapper *this,char *commands)

{
  bool bVar1;
  SystemWrapper *in_EAX;
  uint uVar2;
  char cVar3;
  char *in_EDX;
  char *pcVar4;
  char local_10c [256];
  
                    /* Unresolved local var: char[256] singleCmd@[???]
                       Unresolved local var: bool quotes@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char * c@[???]
                       Unresolved local var: char * c@[DW_OP_reg2(EDX)] */
  if (in_EDX != (char *)0x0) {
    cVar3 = '\0';
    pcVar4 = in_EDX;
    if (*in_EDX == '\0') goto LAB_0009a299;
    do {
      if ((*pcVar4 == '%') || (*pcVar4 < ' ')) {
        *pcVar4 = ' ';
      }
      pcVar4 = pcVar4 + 1;
    } while ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0'));
  }
  cVar3 = *in_EDX;
LAB_0009a299:
  bVar1 = false;
  uVar2 = 1;
  pcVar4 = local_10c;
  local_10c[0] = cVar3;
  do {
    if (cVar3 == '\"') {
      bVar1 = (bool)(bVar1 ^ 1);
LAB_0009a323:
      pcVar4 = pcVar4 + 1;
    }
    else {
      if (cVar3 == ';') {
        if (bVar1) {
          pcVar4 = pcVar4 + 1;
          goto LAB_0009a2e8;
        }
      }
      else if (cVar3 != '\0') goto LAB_0009a323;
      *pcVar4 = '\0';
      pcVar4 = local_10c;
      cVar3 = local_10c[0];
      while (cVar3 == ' ') {
        pcVar4 = pcVar4 + 1;
        cVar3 = *pcVar4;
      }
      DispatchCommand(in_EAX,pcVar4);
      pcVar4 = local_10c;
      uVar2 = 0;
    }
LAB_0009a2e8:
    if (*in_EDX == '\0') {
      return;
    }
    in_EDX = in_EDX + 1;
    uVar2 = uVar2 + 1;
    cVar3 = *in_EDX;
    *pcVar4 = cVar3;
    if (0xff < uVar2) {
      (**(code **)((int)in_EAX->super_IBaseSystem + 0x4c))();
      return;
    }
  } while( true );
}


// SystemWrapper::ExecuteString  @ 0009a340
/* DWARF original prototype: void ExecuteString(SystemWrapper * this, char * commands) */

void __thiscall SystemWrapper::ExecuteString(SystemWrapper *this,char *commands)

{
                    /* Unresolved local var: char[256] singleCmd@[???]
                       Unresolved local var: bool quotes@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char * c@[???] */
  if ((commands != (char *)0x0) && (*commands != '\0')) {
    ExecuteString(this,commands);
    return;
  }
  return;
}


// SystemWrapper::FindModule  @ 00099db0
/* DWARF original prototype: ISystemModule * FindModule(SystemWrapper * this, char * type, char *
   name) */

ISystemModule * __thiscall SystemWrapper::FindModule(SystemWrapper *this,char *type,char *name)

{
  ISystemModule *pIVar1;
  char *pcVar2;
  int iVar3;
  ObjectList *this_00;
  
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


// SystemWrapper::FreeFile  @ 00098e10
/* DWARF original prototype: void FreeFile(SystemWrapper * this, uchar * fileHandle) */

void __thiscall SystemWrapper::FreeFile(SystemWrapper *this,uchar *fileHandle)

{
  COM_FreeFile(fileHandle);
  return;
}


// SystemWrapper::GetCommandMatches  @ 00098cf0
/* DWARF original prototype: void GetCommandMatches(SystemWrapper * this, char * string, ObjectList
   * pMatchList) */

void __thiscall
SystemWrapper::GetCommandMatches(SystemWrapper *this,char *string,ObjectList *pMatchList)

{
                    /* WARNING: Could not recover jumptable at 0x00098d06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(pMatchList->super_IObjectContainer)._vptr_IObjectContainer[5])();
  return;
}


// SystemWrapper::GetFileSystem  @ 00098ca0
/* DWARF original prototype: IFileSystem * GetFileSystem(SystemWrapper * this) */

IFileSystem * __thiscall SystemWrapper::GetFileSystem(SystemWrapper *this)

{
  return g_pFileSystem;
}


// SystemWrapper::GetLibrary  @ 00099b70
/* DWARF original prototype: library_t * GetLibrary(SystemWrapper * this, char * name) */

library_t * __thiscall SystemWrapper::GetLibrary(SystemWrapper *this,char *name)

{
  library_t *plVar1;
  int iVar2;
  CSysModule *pModule;
  CreateInterfaceFn p_Var3;
  IBaseSystem IVar4;
  ObjectList *this_00;
  char *pcVar5;
  char local_101c [4095];
  undefined1 local_1d;
  
                    /* Unresolved local var: char[4096] fixedname@[???]
                       Unresolved local var: library_t * lib@[???] */
  strncpy(local_101c,name,0xfff);
  local_1d = 0;
  COM_FixSlashes(local_101c);
  this_00 = &this->m_Libraries;
  plVar1 = ObjectList::GetFirst(this_00);
  while (plVar1 != (library_t *)0x0) {
    iVar2 = strcasecmp(name,plVar1->name);
    if (iVar2 == 0) {
      return plVar1;
    }
    plVar1 = ObjectList::GetNext(this_00);
  }
  plVar1 = Mem_Malloc(0x1008);
  if (plVar1 == (library_t *)0x0) {
    (**(code **)((int)this->super_IBaseSystem + 0x50))
              (this,"ERROR! System::GetLibrary: out of memory (%s).\n",name);
  }
  else {
    snprintf(plVar1->name,0x1000,"%s.so",local_101c);
    FS_GetLocalCopy(plVar1->name);
    pModule = Sys_LoadModule(plVar1->name);
    plVar1->handle = pModule;
    if (pModule == (CSysModule *)0x0) {
      IVar4 = this->super_IBaseSystem;
      pcVar5 = "ERROR! System::GetLibrary: coulnd\'t load library (%s).\n";
    }
    else {
      p_Var3 = Sys_GetFactory(pModule);
      plVar1->createInterfaceFn = p_Var3;
      if (p_Var3 != (CreateInterfaceFn)0x0) {
        ObjectList::Add(this_00,plVar1);
        (**(code **)((int)this->super_IBaseSystem + 0x50))(this,"Loaded library %s.\n",plVar1);
        return plVar1;
      }
      IVar4 = this->super_IBaseSystem;
      pcVar5 = "ERROR! System::GetLibrary: coulnd\'t get object factory(%s).\n";
    }
    (**(code **)((int)IVar4 + 0x50))(this,pcVar5,plVar1);
    Mem_Free(plVar1);
  }
  return (library_t *)0x0;
}


// SystemWrapper::GetModule  @ 00099e70
/* DWARF original prototype: ISystemModule * GetModule(SystemWrapper * this, char * interfacename,
   char * library, char * instancename) */

ISystemModule * __thiscall
SystemWrapper::GetModule(SystemWrapper *this,char *interfacename,char *library,char *instancename)

{
  IBaseInterface *pIVar1;
  library_t *plVar2;
  
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
  pIVar1 = &FindModule(this,interfacename,instancename)->super_IBaseInterface;
  if (pIVar1 == (IBaseInterface *)0x0) {
                    /* Unresolved local var: ISystemModule * module@[???]
                       Unresolved local var: library_t * lib@[???] */
    plVar2 = GetLibrary(this,library);
    if (plVar2 != (library_t *)0x0) {
      pIVar1 = (*plVar2->createInterfaceFn)(interfacename,(int *)0x0);
      if (pIVar1 == (IBaseInterface *)0x0) {
        (**(code **)((int)this->super_IBaseSystem + 0x4c))
                  (this,"ERROR! System::GetModule: interface \"%s\" not found in library %s.\n",
                   interfacename,plVar2);
      }
      else {
        (**(code **)((int)this->super_IBaseSystem + 0x90))(this,pIVar1,instancename);
      }
    }
  }
  return (ISystemModule *)pIVar1;
}


// SystemWrapper::GetStatusLine  @ 00098c50
/* virtual thunk to SystemWrapper::GetStatusLine() */

void __thiscall SystemWrapper::GetStatusLine(SystemWrapper *this)

{
  GetStatusLine((SystemWrapper *)
                ((this->super_BaseSystemModule).m_Name +
                *(int *)((int)this->super_IBaseSystem + -0x30) + -0x20));
  return;
}


// SystemWrapper::GetStatusLine  @ 00098c60
/* non-virtual thunk to SystemWrapper::GetStatusLine() */

void __thiscall SystemWrapper::GetStatusLine(SystemWrapper *this)

{
  GetStatusLine((SystemWrapper *)&this[-1].m_EngineWrapper);
  return;
}


// SystemWrapper::GetStatusLine  @ 00098c70
/* DWARF original prototype: char * GetStatusLine(SystemWrapper * this) */

char * __thiscall SystemWrapper::GetStatusLine(SystemWrapper *this)

{
  return "No status available.\n";
}


// SystemWrapper::GetTick  @ 00098cb0
/* DWARF original prototype: uint GetTick(SystemWrapper * this) */

uint __thiscall SystemWrapper::GetTick(SystemWrapper *this)

{
  return this->m_Tick;
}


// SystemWrapper::GetTime  @ 00098c90
/* DWARF original prototype: double GetTime(SystemWrapper * this) */

double __thiscall SystemWrapper::GetTime(SystemWrapper *this)

{
  return (this->super_BaseSystemModule).m_SystemTime;
}


// SystemWrapper::GetType  @ 00098cc0
/* virtual thunk to SystemWrapper::GetType() */

void __thiscall SystemWrapper::GetType(SystemWrapper *this)

{
  GetType((SystemWrapper *)
          ((this->super_BaseSystemModule).m_Name +
          *(int *)((int)this->super_IBaseSystem + -0x34) + -0x20));
  return;
}


// SystemWrapper::GetType  @ 00098cd0
/* non-virtual thunk to SystemWrapper::GetType() */

void __thiscall SystemWrapper::GetType(SystemWrapper *this)

{
  GetType((SystemWrapper *)&this[-1].m_EngineWrapper);
  return;
}


// SystemWrapper::GetType  @ 00098ce0
/* DWARF original prototype: char * GetType(SystemWrapper * this) */

char * __thiscall SystemWrapper::GetType(SystemWrapper *this)

{
  return "basesystem002";
}


// SystemWrapper::Init  @ 00099410
/* virtual thunk to SystemWrapper::Init(IBaseSystem*, int, char*) */

void __thiscall
SystemWrapper::Init(SystemWrapper *this,IBaseSystem *param_1,int param_2,char *param_3)

{
  Init((SystemWrapper *)
       ((this->super_BaseSystemModule).m_Name +
       *(int *)((int)this->super_IBaseSystem + -0x10) + -0x20),param_1,param_2,param_3);
  return;
}


// SystemWrapper::Init  @ 00099420
/* non-virtual thunk to SystemWrapper::Init(IBaseSystem*, int, char*) */

void __thiscall
SystemWrapper::Init(SystemWrapper *this,IBaseSystem *param_1,int param_2,char *param_3)

{
  Init((SystemWrapper *)&this[-1].m_EngineWrapper,param_1,param_2,param_3);
  return;
}


// SystemWrapper::Init  @ 00099430
/* DWARF original prototype: bool Init(SystemWrapper * this, IBaseSystem * system, int serial, char
   * name) */

bool __thiscall SystemWrapper::Init(SystemWrapper *this,IBaseSystem *system,int serial,char *name)

{
  IEngineWrapper *pIVar1;
  
  BaseSystemModule::Init(&this->super_BaseSystemModule,system,serial,name);
  ObjectList::Init(&this->m_Commands);
  ObjectList::Init(&this->m_Modules);
  ObjectList::Init(&this->m_Libraries);
  ObjectList::Init(&(this->super_BaseSystemModule).m_Listener);
  pIVar1 = operator_new(0x130);
  pIVar1[1]._vptr_IEngineWrapper = (_func_int_varargs **)&PTR__ISystemModule_000e8828;
  pIVar1->_vptr_IEngineWrapper = (_func_int_varargs **)&PTR__IEngineWrapper_000e8888;
  BaseSystemModule::BaseSystemModule((BaseSystemModule *)(pIVar1 + 1),0xe8214,(void **)serial);
  pIVar1->_vptr_IEngineWrapper = (_func_int_varargs **)(EngineWrapper::vtable + 0xc);
  pIVar1[1]._vptr_IEngineWrapper = (_func_int_varargs **)(EngineWrapper::vtable + 0xcc);
  this->m_EngineWrapper = pIVar1;
  (**(code **)((int)this->super_IBaseSystem + 0x90))(this,pIVar1,"enginewrapper002");
  (this->super_BaseSystemModule).m_State = 3;
  return true;
}


// SystemWrapper::InitVGUI  @ 00098d10
/* DWARF original prototype: bool InitVGUI(SystemWrapper * this, IVGuiModule * module) */

bool __thiscall SystemWrapper::InitVGUI(SystemWrapper *this,IVGuiModule *module)

{
  return false;
}


// SystemWrapper::LoadFile  @ 00098e20
/* DWARF original prototype: uchar * LoadFile(SystemWrapper * this, char * name, int * length) */

uchar * __thiscall SystemWrapper::LoadFile(SystemWrapper *this,char *name,int *length)

{
  uchar *puVar1;
  
                    /* Unresolved local var: uchar * buffer@[???] */
  puVar1 = COM_LoadFile(name,5,length);
  return puVar1;
}


// SystemWrapper::LogConsole  @ 00099270
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


// SystemWrapper::Printf  @ 00098f60
/* DWARF original prototype: void Printf(SystemWrapper * this, char * fmt, ...) */

void __thiscall SystemWrapper::Printf(SystemWrapper *this,char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  vsnprintf(Printf::lexical_block_0::string,0x2000,fmt,&stack0x0000000c);
  Con_Printf("%s",Printf::lexical_block_0::string);
  return;
}


// SystemWrapper::RedirectOutput  @ 00098fb0
/* DWARF original prototype: void RedirectOutput(SystemWrapper * this, char * buffer, int maxSize)
    */

void __thiscall SystemWrapper::RedirectOutput(SystemWrapper *this,char *buffer,int maxSize)

{
  Con_Printf("WARNIG! SystemWrapper::RedirectOutput: not implemented.\n");
  return;
}


// SystemWrapper::RegisterCommand  @ 00099330
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
  do {
    if (pcVar1 == (char *)0x0) {
LAB_0009937e:
                    /* Unresolved local var: command_t * cmd@[???] */
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
    if (iVar2 == 0) {
      if (pcVar1 != (char *)0x0) {
        (**(code **)((int)this->super_IBaseSystem + 0x4c))
                  (this,"WARNING! System::RegisterCommand: command \"%s\" already exists.\n",name);
        return false;
      }
      goto LAB_0009937e;
    }
    pcVar1 = ObjectList::GetNext(this_00);
  } while( true );
}


// SystemWrapper::RemoveModule  @ 00098d20
/* DWARF original prototype: bool RemoveModule(SystemWrapper * this, ISystemModule * module) */

bool __thiscall SystemWrapper::RemoveModule(SystemWrapper *this,ISystemModule *module)

{
  void *object;
  int *object_00;
  int iVar1;
  int iVar2;
  bool bVar3;
  ObjectList *pOVar4;
  
                    /* Unresolved local var: command_t * cmd@[???]
                       Unresolved local var: ISystemModule * mod@[???] */
  bVar3 = true;
  if (module != (ISystemModule *)0x0) {
    (*(module->super_IBaseInterface)._vptr_IBaseInterface[0xf])(module);
    pOVar4 = &this->m_Commands;
    object = ObjectList::GetFirst(pOVar4);
    while (object != (void *)0x0) {
      iVar1 = (**(code **)(**(int **)((int)object + 0x24) + 0x24))(*(int **)((int)object + 0x24));
      iVar2 = (*(module->super_IBaseInterface)._vptr_IBaseInterface[9])(module);
      if (iVar1 == iVar2) {
        ObjectList::Remove(pOVar4,object);
        Mem_Free(object);
      }
      object = ObjectList::GetNext(pOVar4);
    }
    pOVar4 = &this->m_Modules;
    object_00 = ObjectList::GetFirst(pOVar4);
    bVar3 = false;
    if (object_00 != (int *)0x0) {
      do {
        iVar1 = (**(code **)(*object_00 + 0x24))(object_00);
        iVar2 = (*(module->super_IBaseInterface)._vptr_IBaseInterface[9])(module);
        if (iVar1 == iVar2) {
          ObjectList::Remove(pOVar4,object_00);
          return true;
        }
        object_00 = ObjectList::GetNext(pOVar4);
      } while (object_00 != (int *)0x0);
      bVar3 = false;
    }
  }
  return bVar3;
}


// SystemWrapper::RunFrame  @ 00099600
/* virtual thunk to SystemWrapper::RunFrame(double) */

void __thiscall SystemWrapper::RunFrame(SystemWrapper *this,double param_1)

{
  RunFrame((SystemWrapper *)
           ((this->super_BaseSystemModule).m_Name +
           *(int *)((int)this->super_IBaseSystem + -0x14) + -0x20),param_1);
  return;
}


// SystemWrapper::RunFrame  @ 00099610
/* non-virtual thunk to SystemWrapper::RunFrame(double) */

void __thiscall SystemWrapper::RunFrame(SystemWrapper *this,double param_1)

{
  RunFrame((SystemWrapper *)&this[-1].m_EngineWrapper,param_1);
  return;
}


// SystemWrapper::RunFrame  @ 00099620
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


// SystemWrapper::SetFPS  @ 0009a470
/* DWARF original prototype: void SetFPS(SystemWrapper * this, float fps) */

void __thiscall SystemWrapper::SetFPS(SystemWrapper *this,float fps)

{
  return;
}


// SystemWrapper::SetStatusLine  @ 00098fc0
/* DWARF original prototype: void SetStatusLine(SystemWrapper * this, char * text) */

void __thiscall SystemWrapper::SetStatusLine(SystemWrapper *this,char *text)

{
  Con_Printf("TODO: SystemWrapper::SetStatusLine ?\n");
  return;
}


// SystemWrapper::SetTitle  @ 00098fd0
/* DWARF original prototype: void SetTitle(SystemWrapper * this, char * text) */

void __thiscall SystemWrapper::SetTitle(SystemWrapper *this,char *text)

{
  Con_Printf("TODO: SystemWrapper::SetTitle ?\n");
  return;
}


// SystemWrapper::ShowConsole  @ 0009a480
/* DWARF original prototype: void ShowConsole(SystemWrapper * this, bool visible) */

void __thiscall SystemWrapper::ShowConsole(SystemWrapper *this,bool visible)

{
  return;
}


// SystemWrapper::ShutDown  @ 00098fe0
/* virtual thunk to SystemWrapper::ShutDown() */

void __thiscall SystemWrapper::ShutDown(SystemWrapper *this)

{
  ShutDown((SystemWrapper *)
           ((this->super_BaseSystemModule).m_Name +
           *(int *)((int)this->super_IBaseSystem + -0x44) + -0x20));
  return;
}


// SystemWrapper::ShutDown  @ 00098ff0
/* non-virtual thunk to SystemWrapper::ShutDown() */

void __thiscall SystemWrapper::ShutDown(SystemWrapper *this)

{
  ShutDown((SystemWrapper *)&this[-1].m_EngineWrapper);
  return;
}


// SystemWrapper::ShutDown  @ 00099000
/* DWARF original prototype: void ShutDown(SystemWrapper * this) */

void __thiscall SystemWrapper::ShutDown(SystemWrapper *this)

{
  IEngineWrapper *pIVar1;
  int *piVar2;
  void *p;
  
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
    (*pIVar1->_vptr_IEngineWrapper[1])(pIVar1);
  }
  Cmd_RemoveWrapperCmds();
  (this->super_BaseSystemModule).m_State = 4;
  return;
}


// SystemWrapper::Stop  @ 00098c80
/* DWARF original prototype: void Stop(SystemWrapper * this) */

void __thiscall SystemWrapper::Stop(SystemWrapper *this)

{
  (this->super_BaseSystemModule).m_State = 4;
  return;
}


// SystemWrapper::SystemWrapper  @ 000998c0
/* DWARF original prototype: void SystemWrapper(SystemWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall SystemWrapper::SystemWrapper(SystemWrapper *this,int __in_chrg,void **__vtt_parm)

{
  IBaseSystem IVar1;
  void **in_stack_ffffffec;
  
  IVar1 = *(IBaseSystem *)(__in_chrg + 4);
  this->super_IBaseSystem = IVar1;
  *(undefined4 *)((this->super_BaseSystemModule).m_Name + *(int *)((int)IVar1 + -0x48) + -0x20) =
       *(undefined4 *)(__in_chrg + 8);
  BaseSystemModule::BaseSystemModule
            (&this->super_BaseSystemModule,__in_chrg + 0xc,in_stack_ffffffec);
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


// SystemWrapper::SystemWrapper  @ 00099930
/* DWARF original prototype: void SystemWrapper(SystemWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall SystemWrapper::SystemWrapper(SystemWrapper *this,int __in_chrg,void **__vtt_parm)

{
  void **in_stack_ffffffec;
  
  this->super_IBaseSystem = (IBaseSystem)&PTR__IBaseSystem_000e84c8;
  BaseSystemModule::BaseSystemModule(&this->super_BaseSystemModule,0xe857c,in_stack_ffffffec);
  this->super_IBaseSystem = (IBaseSystem)0xe85e8;
  *(undefined4 *)&this->super_BaseSystemModule = 0xe86d4;
  ObjectList::ObjectList(&this->m_Modules);
  ObjectList::ObjectList(&this->m_Libraries);
  ObjectList::ObjectList(&this->m_Commands);
  return;
}


// SystemWrapper::~SystemWrapper  @ 00099160
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


// SystemWrapper::~SystemWrapper  @ 00099170
/* non-virtual thunk to SystemWrapper::~SystemWrapper() */

void __thiscall SystemWrapper::~SystemWrapper(SystemWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~SystemWrapper((SystemWrapper *)&this[-1].m_EngineWrapper,in_stack_00000008,in_stack_0000000c);
  return;
}


// SystemWrapper::~SystemWrapper  @ 00099180
/* DWARF original prototype: void ~SystemWrapper(SystemWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall SystemWrapper::~SystemWrapper(SystemWrapper *this,int __in_chrg,void **__vtt_parm)

{
  int in_stack_ffffffe8;
  void **in_stack_ffffffec;
  
  this->super_IBaseSystem = (IBaseSystem)0xe85e8;
  *(undefined4 *)&this->super_BaseSystemModule = 0xe86d4;
  ObjectList::~ObjectList(&this->m_Commands,in_stack_ffffffe8);
  ObjectList::~ObjectList(&this->m_Libraries,in_stack_ffffffe8);
  ObjectList::~ObjectList(&this->m_Modules,in_stack_ffffffe8);
  BaseSystemModule::~BaseSystemModule(&this->super_BaseSystemModule,0xe857c,in_stack_ffffffec);
  this->super_IBaseSystem = (IBaseSystem)&PTR__IBaseInterface_000e7cf0;
  return;
}


// SystemWrapper::~SystemWrapper  @ 00099570
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


// SystemWrapper::~SystemWrapper  @ 00099580
/* non-virtual thunk to SystemWrapper::~SystemWrapper() */

void __thiscall SystemWrapper::~SystemWrapper(SystemWrapper *this)

{
  int in_stack_00000008;
  void **in_stack_0000000c;
  
  ~SystemWrapper((SystemWrapper *)&this[-1].m_EngineWrapper,in_stack_00000008,in_stack_0000000c);
  return;
}


// SystemWrapper::~SystemWrapper  @ 00099590
/* DWARF original prototype: void ~SystemWrapper(SystemWrapper * this, int __in_chrg, void * *
   __vtt_parm) */

void __thiscall SystemWrapper::~SystemWrapper(SystemWrapper *this,int __in_chrg,void **__vtt_parm)

{
  int in_stack_ffffffe8;
  void **in_stack_ffffffec;
  
  this->super_IBaseSystem = (IBaseSystem)0xe85e8;
  *(undefined4 *)&this->super_BaseSystemModule = 0xe86d4;
  ObjectList::~ObjectList(&this->m_Commands,in_stack_ffffffe8);
  ObjectList::~ObjectList(&this->m_Libraries,in_stack_ffffffe8);
  ObjectList::~ObjectList(&this->m_Modules,in_stack_ffffffe8);
  BaseSystemModule::~BaseSystemModule(&this->super_BaseSystemModule,0xe857c,in_stack_ffffffec);
  this->super_IBaseSystem = (IBaseSystem)&PTR__IBaseInterface_000e7cf0;
  operator_delete(this);
  return;
}


// SystemWrapper::~SystemWrapper  @ 00099990
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


// SystemWrapperCommandForwarder  @ 0009a360
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SystemWrapperCommandForwarder(void)

{
  SystemWrapper *pSVar1;
  char *__src;
  int iVar2;
  uint uVar3;
  uint uVar4;
  BaseSystemModule *pBVar5;
  SystemWrapper *pSVar6;
  SystemWrapper *__dest;
  SystemWrapper local_40c [2];
  undefined1 local_d;
  
                    /* Unresolved local var: char[1024] cmd@[???] */
  __dest = local_40c;
  __src = Cmd_Argv(0);
  pSVar6 = __dest;
  strcpy((char *)__dest,__src);
  iVar2 = Cmd_Argc();
  pSVar1 = __dest;
  if (1 < iVar2) {
    do {
      pSVar6 = pSVar1;
      uVar3 = (int)pSVar6->super_IBaseSystem + 0xfefefeffU & ~(uint)pSVar6->super_IBaseSystem;
      uVar4 = uVar3 & 0x80808080;
      pSVar1 = (SystemWrapper *)&pSVar6->super_BaseSystemModule;
    } while (uVar4 == 0);
    pBVar5 = &pSVar6->super_BaseSystemModule;
    if ((uVar3 & 0x8080) == 0) {
      pBVar5 = (BaseSystemModule *)&(pSVar6->super_BaseSystemModule).field_0x2;
      uVar4 = uVar4 >> 0x10;
    }
    *(undefined2 *)((int)pBVar5 + (-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4))) = 0x20;
    __src = Cmd_Args();
    strcat((char *)__dest,__src);
    pSVar6 = __dest;
  }
                    /* Unresolved local var: char[256] singleCmd@[???]
                       Unresolved local var: bool quotes@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: char * c@[???] */
  local_d = 0;
  if (local_40c[0].super_IBaseSystem._0_1_ != '\0') {
    SystemWrapper::ExecuteString(pSVar6,__src);
  }
  return;
}


// SzFromIndex  @ 00092370
char * SzFromIndex(int iString)

{
  return pr_strings + iString;
}


// TextMessageGet  @ 000bc8c0
client_textmessage_t * TextMessageGet(char *pName)

{
  int iVar1;
  int iVar2;
  client_textmessage_t *pcVar3;
  
                    /* Unresolved local var: int i@[???] */
  pcVar3 = gNetworkTextMessage;
  (*g_engdstAddrs.pfnTextMessageGet)(&pName);
  iVar1 = Q_stricmp(pName,"__NETMESSAGE__1");
  if (iVar1 != 0) {
    pcVar3 = gNetworkTextMessage + 1;
    iVar1 = Q_stricmp(pName,"__NETMESSAGE__2");
    if (iVar1 != 0) {
      pcVar3 = gNetworkTextMessage + 2;
      iVar1 = Q_stricmp(pName,"__NETMESSAGE__3");
      if (iVar1 != 0) {
        pcVar3 = gNetworkTextMessage + 3;
        iVar1 = Q_stricmp(pName,"__NETMESSAGE__4");
        if (((iVar1 != 0) &&
            (pcVar3 = (client_textmessage_t *)0x0, gMessageTable != (client_textmessage_t *)0x0)) &&
           (0 < gMessageTableCount)) {
          iVar1 = 0;
          do {
            iVar2 = Q_stricmp(pName,*(char **)((int)&gMessageTable->pName + (int)pcVar3));
            if (iVar2 == 0) {
              return (client_textmessage_t *)((int)&gMessageTable->effect + (int)&pcVar3->effect);
            }
            iVar1 = iVar1 + 1;
            pcVar3 = pcVar3 + 1;
          } while (iVar1 < gMessageTableCount);
          pcVar3 = (client_textmessage_t *)0x0;
        }
      }
    }
  }
  return pcVar3;
}


// TextMessageInit  @ 000bc880
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void TextMessageInit(void)

{
  uchar *pMemFile;
  int local_10 [4];
  
                    /* Unresolved local var: int fileSize@[???]
                       Unresolved local var: uchar * pMemFile@[???] */
  if (gMessageTable != (client_textmessage_t *)0x0) {
    Mem_Free(gMessageTable);
    gMessageTable = (client_textmessage_t *)0x0;
  }
  pMemFile = COM_LoadTempFile("titles.txt",local_10);
  if (pMemFile != (uchar *)0x0) {
    TextMessageParse(pMemFile,local_10[0]);
  }
  return;
}


// TextMessageParse  @ 000bc480
void __regparm3 TextMessageParse(uchar *pMemFile,int fileSize)

{
  char *pcVar1;
  bool bVar2;
  client_textmessage_t *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *dest;
  int *piVar7;
  client_textmessage_t *dest_00;
  int iVar8;
  int iVar9;
  int local_f210;
  int local_f208;
  int local_f204;
  uchar *local_f200;
  undefined4 local_f1fc [9];
  int aiStack_f1d8 [10991];
  char local_461c [16384];
  char local_61c;
  char local_61b;
  char local_41c;
  undefined1 local_41b [511];
  char local_21c [511];
  undefined1 local_1d;
  
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
                    /* Unresolved local var: int filePos@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int last@[???]
                       Unresolved local var: int stop@[???] */
  local_f208 = 0;
  if (pMemFile == (uchar *)0x0) {
    local_f204 = 0;
  }
  else {
    iVar9 = 0;
    local_f208 = 0;
    bVar2 = false;
    local_f210 = 0;
    local_f204 = 0;
    if (0 < fileSize) {
      do {
        iVar6 = iVar9;
        iVar4 = iVar9 + 0x1ff;
        if (fileSize - iVar9 < 0x200) {
          iVar4 = fileSize;
        }
        do {
          iVar8 = iVar6 + 1;
          if (pMemFile[iVar6] == '\n') break;
          iVar6 = iVar8;
        } while (iVar8 < iVar4);
        if (iVar9 == iVar8) break;
                    /* Unresolved local var: int size@[???] */
        iVar6 = iVar8 - iVar9;
        Q_memcpy(&local_41c,pMemFile + iVar9,iVar6);
        if (iVar6 < 0x200) {
          local_41b[iVar6 + -1] = 0;
        }
        if (999 < local_f208) {
          Sys_Error("tmessage::TextMessageParse : messageCount>=MAX_MESSAGES");
        }
        TrimSpace(&local_41c,&local_61c);
        if (bVar2) {
          if (local_61c == '}') {
                    /* Unresolved local var: int length@[???] */
            iVar6 = Q_strlen(local_21c);
            if (0x4000 < iVar6 + local_f204) {
              Con_DPrintf("Error parsing file!  length > %i bytes\n",0x4000);
              return;
            }
            Q_strcpy(local_461c + local_f204,local_21c);
            pMemFile[iVar9 + -1] = '\0';
            uVar5 = 0;
            do {
              *(undefined4 *)((int)local_f1fc + uVar5 + local_f208 * 0x2c) =
                   *(undefined4 *)((int)&gMessageParms.effect + uVar5);
              uVar5 = uVar5 + 4;
            } while (uVar5 < 0x2c);
            aiStack_f1d8[local_f208 * 0xb] = (int)(local_461c + local_f204);
            iVar9 = Q_strlen(local_21c);
            local_f204 = local_f204 + 1 + iVar9;
            aiStack_f1d8[local_f208 * 0xb + 1] = (int)local_f200;
            bVar2 = false;
            local_f208 = local_f208 + 1;
          }
          else if (local_61c == '{') {
            Con_DPrintf("Unexpected \'{\' found, line %d\n",local_f210);
            return;
          }
        }
        else {
                    /* Unresolved local var: int length@[???] */
          iVar9 = Q_strlen(&local_61c);
          if (iVar9 < 2) {
            if (iVar9 != 1) goto LAB_000bc7f6;
          }
          else if ((local_61c == '/') && (local_61b == '/')) {
LAB_000bc7f6:
            bVar2 = false;
            goto LAB_000bc6f0;
          }
          iVar9 = ParseDirective(&local_61c);
          bVar2 = false;
          if (iVar9 == 0) {
            if (local_61c == '{') {
              local_f200 = pMemFile + iVar8;
              bVar2 = true;
            }
            else {
              if (local_61c == '}') {
                Con_DPrintf("Unexpected \'}\' found, line %d\n",local_f210);
                return;
              }
              Q_strncpy(local_21c,&local_61c,0x1ff);
              local_1d = 0;
            }
          }
        }
LAB_000bc6f0:
        local_f210 = local_f210 + 1;
        iVar9 = iVar8;
      } while (iVar8 < fileSize);
    }
  }
  Con_DPrintf("Parsed %d text messages\n",local_f208);
  if (local_f208 == 0) {
    iVar9 = 0;
  }
  else {
    piVar7 = aiStack_f1d8 + 1;
    iVar9 = 0;
    iVar6 = 0;
    do {
      pcVar1 = (char *)*piVar7;
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 0xb;
      iVar4 = Q_strlen(pcVar1);
      iVar9 = iVar9 + 1 + iVar4;
    } while (iVar6 != local_f208);
  }
  gMessageTable = Mem_Malloc(local_f204 + iVar9 + local_f208 * 0x2c);
  Q_memcpy(gMessageTable,local_f1fc,local_f208 * 0x2c);
  dest_00 = gMessageTable + local_f208;
  Q_memcpy(dest_00,local_461c,local_f204);
  pcVar1 = gMessageTable->pName;
  if (local_f208 != 0) {
    iVar6 = 0;
    dest = (char *)((int)&dest_00->effect + local_f204);
    iVar9 = 0;
    do {
      pcVar3 = gMessageTable;
      iVar6 = iVar6 + 1;
      piVar7 = (int *)((int)&gMessageTable->pName + iVar9);
      *piVar7 = (int)dest_00 + (*piVar7 - (int)pcVar1);
      Q_strcpy(dest,*(char **)((int)&pcVar3->pMessage + iVar9));
      *(char **)((int)&gMessageTable->pMessage + iVar9) = dest;
      iVar9 = iVar9 + 0x2c;
      iVar4 = Q_strlen(dest);
      dest = dest + iVar4 + 1;
    } while (iVar6 != local_f208);
  }
  gMessageTableCount = local_f208;
  return;
}


// TextMessageShutdown  @ 000bc860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void TextMessageShutdown(void)

{
  if (gMessageTable != (client_textmessage_t *)0x0) {
    Mem_Free(gMessageTable);
    gMessageTable = (client_textmessage_t *)0x0;
  }
  return;
}


// TokenLine::CheckToken  @ 000d36e0
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
      if ((this->m_token[iVar4] != (char *)0x0) &&
         (iVar2 = strcmp(parm,this->m_token[iVar4]), iVar2 == 0)) {
                    /* Unresolved local var: char * ret@[???] */
        pcVar3 = "";
        if (iVar4 + 1 != iVar1) {
          pcVar3 = this->m_token[iVar4 + 1];
        }
        return pcVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != iVar1);
  }
  return (char *)0x0;
}


// TokenLine::CountToken  @ 000d3750
/* DWARF original prototype: int CountToken(TokenLine * this) */

int __thiscall TokenLine::CountToken(TokenLine *this)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int i@[???] */
  if (this->m_tokenNumber < 1) {
    iVar1 = 0;
  }
  else {
    iVar2 = 0;
    iVar1 = 0;
    do {
      if (this->m_token[iVar2] != (char *)0x0) {
        iVar1 = iVar1 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != this->m_tokenNumber);
  }
  return iVar1;
}


// TokenLine::GetLine  @ 000d36b0
/* DWARF original prototype: char * GetLine(TokenLine * this) */

char * __thiscall TokenLine::GetLine(TokenLine *this)

{
  return this->m_fullLine;
}


// TokenLine::GetRestOfLine  @ 000d3790
/* DWARF original prototype: char * GetRestOfLine(TokenLine * this, int i) */

char * __thiscall TokenLine::GetRestOfLine(TokenLine *this,int i)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if (i < this->m_tokenNumber) {
    pcVar1 = this->m_token[i] + 0x800;
  }
  return pcVar1;
}


// TokenLine::GetToken  @ 000d36c0
/* DWARF original prototype: char * GetToken(TokenLine * this, int i) */

char * __thiscall TokenLine::GetToken(TokenLine *this,int i)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if (i < this->m_tokenNumber) {
    pcVar1 = this->m_token[i];
  }
  return pcVar1;
}


// TokenLine::SetLine  @ 000d3470
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
  
  bVar9 = 0;
                    /* Unresolved local var: char * charPointer@[???] */
  this->m_tokenNumber = 0;
  if ((newLine == (char *)0x0) || (sVar2 = strlen(newLine), 0x7fe < sVar2)) {
    pcVar6 = this->m_fullLine;
    uVar5 = 0x800;
    bVar8 = ((uint)pcVar6 & 1) != 0;
    if (bVar8) {
      this->m_fullLine[0] = '\0';
      pcVar6 = this->m_fullLine + 1;
      uVar5 = 0x7ff;
    }
    if (((uint)pcVar6 & 2) != 0) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      uVar5 = uVar5 - 2;
      pcVar6 = pcVar6 + 2;
    }
    if (((uint)pcVar6 & 4) != 0) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      uVar5 = uVar5 - 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      pcVar6 = pcVar6 + (uint)bVar9 * -8 + 4;
    }
    if ((uVar5 & 2) != 0) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6 = pcVar6 + 2;
    }
    if (bVar8) {
      *pcVar6 = '\0';
    }
    pcVar6 = this->m_tokenBuffer;
    uVar5 = 0x800;
    bVar8 = ((uint)pcVar6 & 1) != 0;
    if (bVar8) {
      this->m_tokenBuffer[0] = '\0';
      pcVar6 = this->m_tokenBuffer + 1;
      uVar5 = 0x7ff;
    }
    if (((uint)pcVar6 & 2) != 0) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      uVar5 = uVar5 - 2;
      pcVar6 = pcVar6 + 2;
    }
    if (((uint)pcVar6 & 4) != 0) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      uVar5 = uVar5 - 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      pcVar6 = pcVar6 + (uint)bVar9 * -8 + 4;
    }
    if ((uVar5 & 2) != 0) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6 = pcVar6 + 2;
    }
    if (bVar8) {
      *pcVar6 = '\0';
    }
    return false;
  }
  pcVar6 = this->m_tokenBuffer;
  strncpy(this->m_fullLine,newLine,0x7ff);
  this->m_fullLine[0x7ff] = '\0';
  strncpy(pcVar6,newLine,0x7ff);
  this->m_tokenBuffer[0x7ff] = '\0';
  while( true ) {
    iVar4 = this->m_tokenNumber;
    if ((*pcVar6 == '\0') || (0x7f < iVar4)) break;
    if (0x5d < (byte)(*pcVar6 - 0x21U)) {
      do {
        pcVar6 = pcVar6 + 1;
        cVar1 = *pcVar6;
        if ((byte)(cVar1 - 0x21U) < 0x5e) break;
      } while (cVar1 != '\0');
      if (cVar1 == '\0') break;
    }
    this->m_token[iVar4] = pcVar6;
    if (*pcVar6 == '\"') {
      pcVar7 = pcVar6 + 1;
      this->m_token[iVar4] = pcVar7;
      cVar1 = pcVar6[1];
      while ((cVar1 != '\"' && (cVar1 != '\0'))) {
        pcVar7 = pcVar7 + 1;
        cVar1 = *pcVar7;
      }
    }
    else {
      this->m_token[this->m_tokenNumber] = pcVar6;
      cVar1 = *pcVar6;
      pcVar7 = pcVar6;
      while ((byte)(cVar1 - 0x21U) < 0x5e) {
        pcVar7 = pcVar7 + 1;
        cVar1 = *pcVar7;
      }
    }
    iVar4 = iVar4 + 1;
    this->m_tokenNumber = iVar4;
    if (*pcVar7 == '\0') break;
    *pcVar7 = '\0';
    pcVar6 = pcVar7 + 1;
  }
  return iVar4 != 0x80;
}


// TokenLine::TokenLine  @ 000d37b0
/* DWARF original prototype: void TokenLine(TokenLine * this, char * string) */

void __thiscall TokenLine::TokenLine(TokenLine *this,char *string)

{
  this->_vptr_TokenLine = (_func_int_varargs **)&PTR__TokenLine_000edfd0;
  SetLine(this,string);
  return;
}


// TokenLine::TokenLine  @ 000d37c0
/* DWARF original prototype: void TokenLine(TokenLine * this) */

void __thiscall TokenLine::TokenLine(TokenLine *this)

{
  this->_vptr_TokenLine = (_func_int_varargs **)&PTR__TokenLine_000edfd0;
  return;
}


// TokenLine::~TokenLine  @ 000d3450
/* DWARF original prototype: void ~TokenLine(TokenLine * this, int __in_chrg) */

void __thiscall TokenLine::~TokenLine(TokenLine *this,int __in_chrg)

{
  this->_vptr_TokenLine = (_func_int_varargs **)&PTR__TokenLine_000edfd0;
  return;
}


// TokenLine::~TokenLine  @ 000d3460
/* DWARF original prototype: void ~TokenLine(TokenLine * this, int __in_chrg) */

void __thiscall TokenLine::~TokenLine(TokenLine *this,int __in_chrg)

{
  this->_vptr_TokenLine = (_func_int_varargs **)&PTR__TokenLine_000edfd0;
  operator_delete(this);
  return;
}


// TraceHull  @ 0008c320
void TraceHull(float *v1,float *v2,int fNoMonsters,int hullNumber,edict_t_conflict *pentToSkip,
              TraceResult *ptr)

{
  vec_t (*maxs) [3];
  vec_t (*mins) [3];
  trace_t local_44;
  
                    /* Unresolved local var: trace_t trace@[???] */
  if ((uint)hullNumber < 4) {
    maxs = gHullMaxs + hullNumber;
    mins = gHullMins + hullNumber;
  }
  else {
    mins = gHullMins;
    maxs = gHullMaxs;
  }
  SV_Move(&local_44,v1,*mins,*maxs,v2,fNoMonsters,pentToSkip,false);
  ptr->fAllSolid = local_44.allsolid;
  ptr->fStartSolid = local_44.startsolid;
  ptr->fInOpen = local_44.inopen;
  ptr->fInWater = local_44.inwater;
  ptr->flFraction = local_44.fraction;
  ptr->flPlaneDist = local_44.plane.dist;
  ptr->pHit = local_44.ent;
  ptr->iHitgroup = local_44.hitgroup;
  ptr->vecEndPos[0] = local_44.endpos[0];
  ptr->vecEndPos[1] = local_44.endpos[1];
  ptr->vecEndPos[2] = local_44.endpos[2];
  ptr->vecPlaneNormal[0] = local_44.plane.normal[0];
  ptr->vecPlaneNormal[1] = local_44.plane.normal[1];
  ptr->vecPlaneNormal[2] = local_44.plane.normal[2];
  return;
}


// TraceInit  @ 000c7ef0
void TraceInit(char *i,char *s,int listnum)

{
  int iVar1;
  undefined4 *puVar2;
  CUtlVector<CInitTracker::InitFunc*> *this;
  int in_stack_ffffffd8;
  InitFunc **in_stack_ffffffdc;
  
                    /* Unresolved local var: InitFunc * f@[???] */
  this = (CUtlVector<CInitTracker::InitFunc*> *)0x24;
  puVar2 = operator_new(0x24);
  *puVar2 = i;
  puVar2[1] = s;
  iVar1 = g_InitTracker.m_nNumFuncs[listnum];
  *(undefined8 *)(puVar2 + 5) = 0;
  puVar2[2] = 1;
  *(undefined8 *)(puVar2 + 7) = 0;
  puVar2[3] = iVar1;
  *(undefined1 *)(puVar2 + 4) = 0;
  CUtlVector<CInitTracker::InitFunc*>::InsertBefore(this,in_stack_ffffffd8,in_stack_ffffffdc);
  g_InitTracker.m_nNumFuncs[listnum] = g_InitTracker.m_nNumFuncs[listnum] + 1;
  return;
}


// TraceModel  @ 0008c420
void TraceModel(float *v1,float *v2,int hullNumber,edict_t_conflict *pent,TraceResult *ptr)

{
  model_s *pmVar1;
  vec_t (*mins) [3];
  vec_t (*maxs) [3];
  int local_64;
  int local_60;
  trace_t local_5c;
  
                    /* Unresolved local var: trace_t trace@[???]
                       Unresolved local var: int oldSolid@[???]
                       Unresolved local var: int oldMovetype@[???]
                       Unresolved local var: model_t * pmodel@[???] */
  if ((uint)hullNumber < 4) {
    maxs = gHullMaxs + hullNumber;
    mins = gHullMins + hullNumber;
  }
  else {
    mins = gHullMins;
    maxs = gHullMaxs;
  }
  pmVar1 = sv.models[(pent->v).modelindex];
  if (pmVar1 == (model_s *)0x0) {
    SV_ClipMoveToEntity(&local_5c,pent,v1,*mins,*maxs,v2);
  }
  else {
    if (pmVar1->type == mod_brush) {
      local_60 = (pent->v).solid;
      local_64 = (pent->v).movetype;
      (pent->v).solid = 4;
      (pent->v).movetype = 7;
    }
    SV_ClipMoveToEntity(&local_5c,pent,v1,*mins,*maxs,v2);
    if (pmVar1->type == mod_brush) {
      (pent->v).solid = local_60;
      (pent->v).movetype = local_64;
    }
  }
  ptr->fAllSolid = local_5c.allsolid;
  ptr->fStartSolid = local_5c.startsolid;
  ptr->fInOpen = local_5c.inopen;
  ptr->fInWater = local_5c.inwater;
  ptr->flFraction = local_5c.fraction;
  ptr->flPlaneDist = local_5c.plane.dist;
  ptr->pHit = local_5c.ent;
  ptr->iHitgroup = local_5c.hitgroup;
  ptr->vecEndPos[0] = local_5c.endpos[0];
  ptr->vecEndPos[1] = local_5c.endpos[1];
  ptr->vecEndPos[2] = local_5c.endpos[2];
  ptr->vecPlaneNormal[0] = local_5c.plane.normal[0];
  ptr->vecPlaneNormal[1] = local_5c.plane.normal[1];
  ptr->vecPlaneNormal[2] = local_5c.plane.normal[2];
  return;
}


// TraceMonsterHull  @ 0008cf40
int TraceMonsterHull(edict_t_conflict *pEdict,float *v1,float *v2,int fNoMonsters,
                    edict_t_conflict *pentToSkip,TraceResult *ptr)

{
  uint uVar1;
  trace_t local_4c;
  
                    /* Unresolved local var: trace_t trace@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  SV_Move(&local_4c,v1,(pEdict->v).mins,(pEdict->v).maxs,v2,fNoMonsters,pentToSkip,
          (uint)(((pEdict->v).flags & 0x800000) != 0));
  if (ptr != (TraceResult *)0x0) {
    ptr->flFraction = local_4c.fraction;
    ptr->fAllSolid = local_4c.allsolid;
    ptr->fStartSolid = local_4c.startsolid;
    ptr->fInOpen = local_4c.inopen;
    ptr->fInWater = local_4c.inwater;
    ptr->flPlaneDist = local_4c.plane.dist;
    ptr->pHit = local_4c.ent;
    ptr->iHitgroup = local_4c.hitgroup;
    ptr->vecEndPos[0] = local_4c.endpos[0];
    ptr->vecEndPos[1] = local_4c.endpos[1];
    ptr->vecEndPos[2] = local_4c.endpos[2];
    ptr->vecPlaneNormal[0] = local_4c.plane.normal[0];
    ptr->vecPlaneNormal[1] = local_4c.plane.normal[1];
    ptr->vecPlaneNormal[2] = local_4c.plane.normal[2];
  }
  uVar1 = 1;
  if ((local_4c.allsolid == false) && (local_4c.fraction == 1.0)) {
    uVar1 = (uint)NAN(local_4c.fraction);
  }
  return uVar1;
}


// TraceShutdown  @ 000c7d70
void TraceShutdown(char *s,int listnum)

{
  int *piVar1;
  InitFunc **ppIVar2;
  int iVar3;
  int iVar4;
  InitFunc *pIVar5;
  int iVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: InitFunc * f@[???] */
  iVar6 = g_InitTracker.m_nNumFuncs[listnum];
  if (iVar6 == 0) {
    Sys_Printf("Mismatched shutdown function %s\n");
    return;
  }
  if (0 < iVar6) {
    ppIVar2 = g_InitTracker.m_Funcs[listnum].m_Memory.m_pMemory;
    pIVar5 = *ppIVar2;
    if (pIVar5->referencecount == 0) {
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 1;
        if (iVar3 == iVar6) goto LAB_000c7dce;
        pIVar5 = ppIVar2[iVar3];
      } while (pIVar5->referencecount == 0);
    }
    iVar3 = strcasecmp(pIVar5->shutdownname,s);
    if ((iVar3 != 0) && (pIVar5->warningprinted == false)) {
      pIVar5->warningprinted = true;
      iVar6 = g_InitTracker.m_nNumFuncs[listnum];
      if (iVar6 < 1) goto LAB_000c7e40;
    }
LAB_000c7dce:
    ppIVar2 = g_InitTracker.m_Funcs[listnum].m_Memory.m_pMemory;
    iVar3 = 0;
    do {
                    /* Unresolved local var: InitFunc * f@[???] */
      pIVar5 = ppIVar2[iVar3];
      iVar4 = strcasecmp(pIVar5->shutdownname,s);
      if (iVar4 == 0) {
        piVar1 = &pIVar5->referencecount;
        *piVar1 = *piVar1 + -1;
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != iVar6);
  }
LAB_000c7e40:
  Sys_Printf("Shutdown function %s not in list!!!\n");
  return;
}


// TraceSphere  @ 0008c410
void TraceSphere(float *v1,float *v2,int fNoMonsters,float radius,edict_t_conflict *pentToSkip,
                TraceResult *ptr)

{
  Sys_Error("TraceSphere not yet implemented!\n");
  return;
}


// TraceTexture  @ 0008c870
char * TraceTexture(edict_t_conflict *pTextureEntity,float *v1,float *v2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  hull_s *phVar5;
  msurface_t *pmVar6;
  int iVar7;
  model_s *pModel;
  texture_t *ptVar8;
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
  if (pTextureEntity == (edict_t_conflict *)0x0) {
    if (sv.worldmodel == (model_s *)0x0) {
      return (char *)0x0;
    }
    iVar7 = 0;
    pModel = sv.worldmodel;
    local_64 = *v1;
    local_60 = v1[1];
    local_5c = v1[2];
    local_58 = *v2;
    local_54 = v2[1];
    local_50 = v2[2];
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
      local_64 = fVar4 * local_38 + fVar3 * local_3c + fVar2 * local_40;
      local_60 = -(local_2c * fVar4 + local_30 * fVar3 + local_34 * fVar2);
      local_5c = fVar4 * local_20 + fVar3 * local_24 + fVar2 * local_28;
      local_58 = local_38 * local_44 + local_3c * local_48 + local_40 * local_4c;
      local_54 = -(local_44 * local_2c + local_48 * local_30 + local_4c * local_34);
      local_50 = local_44 * local_20 + local_24 * local_48 + local_28 * local_4c;
    }
  }
  ptVar8 = (texture_t *)0x0;
  if (((pModel->type == mod_brush) && (pModel->nodes != (mnode_t *)0x0)) &&
     (pmVar6 = SurfaceAtPoint(pModel,pModel->nodes + iVar7,&local_64,&local_58),
     pmVar6 != (msurface_t *)0x0)) {
    ptVar8 = pmVar6->texinfo->texture;
  }
  return ptVar8->name;
}


// TrimSpace  @ 000bc010
void TrimSpace(char *source,char *dest)

{
  char *src;
  char cVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int start@[???]
                       Unresolved local var: int end@[???]
                       Unresolved local var: int length@[???] */
  iVar2 = Q_strlen(source);
  iVar3 = 0;
  cVar1 = *source;
  src = source;
  while ((cVar1 != '\0' &&
         ((((cVar1 == '\t' || (cVar1 == ' ')) || (cVar1 == '\n')) || (cVar1 == '\r'))))) {
    iVar3 = iVar3 + 1;
    src = source + iVar3;
    cVar1 = source[iVar3];
  }
  iVar2 = iVar2 + -1;
  if (0 < iVar2) {
    do {
      cVar1 = source[iVar2];
      if (((cVar1 != '\t') && (cVar1 != ' ')) && ((cVar1 != '\n' && (cVar1 != '\r')))) break;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar3 = (iVar2 + 1) - iVar3;
  iVar2 = 0;
  if (0 < iVar3) {
    Q_strncpy(dest,src,iVar3);
    iVar2 = iVar3;
  }
  dest[iVar2] = '\0';
  return;
}


// ValidChallenge  @ 000a07b0
qboolean ValidChallenge(netadr_t *adr,int challengeNr)

{
  qboolean qVar1;
  int iVar2;
  sizebuf_t local_40;
  byte local_2c [28];
  
  qVar1 = false;
  if ((sv.active != false) && (1 < svs.maxclients)) {
    if (sv_enableoldqueries.value == 0.0) {
                    /* Unresolved local var: int i@[???] */
      if ((challengeNr != -1) && (iVar2 = 0, adr != (netadr_t *)0x0)) {
        do {
          qVar1 = NET_CompareBaseAdr(*adr,g_rg_sv_challenges[iVar2].adr);
          if (qVar1 != false) {
            if ((challengeNr == g_rg_sv_challenges[iVar2].challenge) &&
               ((float)realtime <= (float)g_rg_sv_challenges[iVar2].time + 3600.0))
            goto LAB_000a07ea;
            break;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 != 0x400);
      }
                    /* Unresolved local var: char[16] buffer@[???]
                       Unresolved local var: sizebuf_t buf@[???] */
      local_40.data = local_2c;
      local_40.cursize = 0;
      local_40.buffername = "SVC_Challenge";
      local_40.maxsize = 0x10;
      local_40.flags = 1;
      MSG_WriteLong(&local_40,-1);
      MSG_WriteByte(&local_40,0x41);
      iVar2 = GetChallengeNr(adr);
      MSG_WriteLong(&local_40,iVar2);
      NET_SendPacket(NS_SERVER,local_40.cursize,local_40.data,*adr);
      qVar1 = false;
    }
    else {
LAB_000a07ea:
      qVar1 = true;
    }
  }
  return qVar1;
}


// ValidCmd  @ 0008d590
qboolean ValidCmd(char *pCmd)

{
  int iVar1;
  qboolean qVar2;
  
                    /* Unresolved local var: int len@[???] */
  iVar1 = Q_strlen(pCmd);
  qVar2 = false;
  if (iVar1 != 0) {
    qVar2 = (qboolean)(pCmd[iVar1 + -1] == ';' || pCmd[iVar1 + -1] == '\n');
  }
  return qVar2;
}


// ValidInfoChallenge  @ 000a0440
qboolean ValidInfoChallenge(netadr_t *adr,char *nugget)

{
  qboolean qVar1;
  int iVar2;
  
  qVar1 = false;
  if (((nugget != (char *)0x0) && (sv.active != false)) && (1 < svs.maxclients)) {
    if (sv_enableoldqueries.value == 0.0) {
      iVar2 = Q_stricmp(nugget,"Source Engine Query");
      return (uint)(iVar2 == 0);
    }
    qVar1 = true;
  }
  return qVar1;
}


// VectorAngles  @ 000808e0
void VectorAngles(vec_t *forward,vec_t *angles)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  
                    /* Unresolved local var: float tmp@[???]
                       Unresolved local var: float yaw@[???]
                       Unresolved local var: float pitch@[???] */
  if ((forward[1] == 0.0) && (*forward == 0.0)) {
    if (forward[2] <= 0.0) {
      fVar1 = 0.0;
      fVar2 = 270.0;
    }
    else {
      fVar1 = 0.0;
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


// VectorCompare  @ 000804c0
int VectorCompare(vec_t *v1,vec_t *v2)

{
                    /* Unresolved local var: int i@[???] */
  if (*v1 != *v2) {
    return 0;
  }
  if (v1[1] != v2[1]) {
    return 0;
  }
  return (uint)(v1[2] == v2[2]);
}


// VectorInverse  @ 000806d0
void VectorInverse(vec_t *v)

{
  *v = -*v;
  v[1] = -v[1];
  v[2] = -v[2];
  return;
}


// VectorMA  @ 00080510
void VectorMA(vec_t *veca,float scale,vec_t *vecb,vec_t *vecc)

{
  *vecc = *vecb * scale + *veca;
  vecc[1] = vecb[1] * scale + veca[1];
  vecc[2] = scale * vecb[2] + veca[2];
  return;
}


// VectorMatrix  @ 00080740
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
    return;
  }
  return;
}


// VectorNormalize  @ 00080660
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
  if (fVar2 == 0.0) {
    return fVar2;
  }
  fVar1 = 1.0 / fVar2;
  *v = *v * fVar1;
  v[1] = v[1] * fVar1;
  v[2] = fVar1 * v[2];
  return fVar2;
}


// VectorScale  @ 000806f0
void VectorScale(vec_t *in,float scale,vec_t *out)

{
  *out = *in * scale;
  out[1] = in[1] * scale;
  out[2] = scale * in[2];
  return;
}


// VectorTransform  @ 00080460
void VectorTransform(vec_t *in1,float (*in2) [4],vec_t *out)

{
  *out = in1[2] * (*in2)[2] + in1[1] * (*in2)[1] + *in1 * (*in2)[0] + (*in2)[3];
  out[1] = in1[2] * in2[1][2] + in1[1] * in2[1][1] + *in1 * in2[1][0] + in2[1][3];
  out[2] = in1[2] * in2[2][2] + in1[1] * in2[2][1] + *in1 * in2[2][0] + in2[2][3];
  return;
}


// anglemod  @ 0007f0a0
float anglemod(float a)

{
  return (float)((int)(a * 182.04445) & 0xffff) * 0.005493164;
}


// bsPutUChar  @ 000d8363
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


// bsPutUInt32  @ 000d81c0
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


// fallbackSort  @ 000de000
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
LAB_000de176:
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
LAB_000de1ed:
  uVar9 = local_b58 + 1;
  uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
  uVar13 = uVar9 & 0x1f;
  uVar14 = uVar3 & 1 << (sbyte)uVar13;
  while (uVar14 != 0) {
    if (uVar13 == 0) goto joined_r0x000de6ad;
    uVar9 = uVar9 + 1;
    uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
    uVar13 = uVar9 & 0x1f;
    uVar14 = uVar3 & 1 << (sbyte)uVar13;
  }
  goto LAB_000de241;
joined_r0x000de6ad:
  while (uVar3 == 0xffffffff) {
    uVar9 = uVar9 + 0x20;
    uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
  }
  uVar3 = 1 << ((byte)uVar9 & 0x1f) & uVar3;
  while (uVar3 != 0) {
    uVar9 = uVar9 + 1;
    uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4) & 1 << ((byte)uVar9 & 0x1f);
  }
LAB_000de241:
  iVar6 = uVar9 - 1;
  if (param_1 <= iVar6) goto LAB_000de7e9;
  uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
  uVar14 = uVar9 & 0x1f;
  local_b70 = iVar6;
  if ((uVar3 & 1 << (sbyte)uVar14) != 0) goto LAB_000de2aa;
  do {
    if (uVar14 == 0) goto joined_r0x000de6fb;
    uVar9 = uVar9 + 1;
    uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
    uVar14 = uVar9 & 0x1f;
  } while ((uVar3 & 1 << (sbyte)uVar14) == 0);
LAB_000de2a3:
  local_b70 = uVar9 - 1;
LAB_000de2aa:
  local_b58 = local_b70;
  if (param_1 <= local_b70) goto LAB_000de7e9;
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
LAB_000de407:
        local_b68 = iVar8;
        if (iVar8 == 0) goto LAB_000de785;
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
LAB_000de4b3:
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
                else if (iVar11 - local_b94 < 0) goto LAB_000de667;
                piVar7 = piVar7 + -1;
                iVar15 = iVar12;
                if (iVar12 < iVar4) goto LAB_000de4c6;
              } while( true );
            }
          }
        }
LAB_000de4c6:
        if (local_b84 < local_b80) goto LAB_000de407;
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
  goto LAB_000de1ed;
joined_r0x000de6fb:
  while (uVar3 == 0) {
    uVar9 = uVar9 + 0x20;
    uVar3 = *(uint *)(in_ECX + ((int)uVar9 >> 5) * 4);
  }
  local_b70 = uVar9 - 1;
  if ((1 << ((byte)uVar9 & 0x1f) & uVar3) != 0) goto LAB_000de2aa;
  do {
    uVar9 = uVar9 + 1;
  } while ((*(uint *)(in_ECX + ((int)uVar9 >> 5) * 4) & 1 << ((byte)uVar9 & 0x1f)) == 0);
  goto LAB_000de2a3;
LAB_000de7e9:
  if (3 < param_2) {
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
      *(char *)(in_EDX + *(int *)(in_EAX + iVar8 * 4)) = (char)iVar6;
    }
    if (0xff < iVar6) {
      BZ2_bz__AssertH__fail();
      return;
    }
    return;
  }
  goto LAB_000de176;
LAB_000de667:
  if (iVar15 < iVar4) goto LAB_000de4c6;
  iVar4 = *(int *)(in_EAX + -4 + local_b8c * 4);
  *(int *)(in_EAX + -4 + local_b8c * 4) = iVar10;
  *piVar7 = iVar4;
  iVar10 = local_b8c;
  goto LAB_000de4b3;
LAB_000de785:
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
  goto LAB_000de1ed;
}


// fran1  @ 00090700
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


// hudCheckParm  @ 000914d0
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


// iGetIndex  @ 0008d990
int iGetIndex(char *pszField)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 local_4b0 [4];
  undefined1 local_4ac [180];
  undefined1 local_3f8 [4];
  undefined1 local_3f4 [4];
  undefined1 local_3f0 [264];
  undefined1 local_2e8 [4];
  undefined1 local_2e4 [4];
  undefined1 local_2e0 [4];
  undefined1 local_2dc [20];
  undefined1 local_2c8 [4];
  undefined1 local_2c4 [4];
  undefined1 local_2c0 [4];
  undefined1 local_2bc [176];
  char local_20c [511];
  undefined1 local_d;
  
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: char[512] sz@[???]
                       Unresolved local var: entvars_t t@[???] */
  Q_strncpy(local_20c,pszField,0x1ff);
  local_d = 0;
  Q_strlwr(local_20c);
  iVar1 = Q_strcmp(local_20c,"classname");
  if (iVar1 == 0) {
    puVar2 = local_4b0;
  }
  else {
    iVar1 = Q_strcmp(local_20c,"model");
    if (iVar1 == 0) {
      puVar2 = local_3f8;
    }
    else {
      iVar1 = Q_strcmp(local_20c,"viewmodel");
      if (iVar1 == 0) {
        puVar2 = local_3f4;
      }
      else {
        iVar1 = Q_strcmp(local_20c,"weaponmodel");
        if (iVar1 == 0) {
          puVar2 = local_3f0;
        }
        else {
          iVar1 = Q_strcmp(local_20c,"netname");
          if (iVar1 == 0) {
            puVar2 = local_2e0;
          }
          else {
            iVar1 = Q_strcmp(local_20c,"target");
            if (iVar1 == 0) {
              puVar2 = local_2e8;
            }
            else {
              iVar1 = Q_strcmp(local_20c,"targetname");
              if (iVar1 == 0) {
                puVar2 = local_2e4;
              }
              else {
                iVar1 = Q_strcmp(local_20c,"message");
                if (iVar1 == 0) {
                  puVar2 = local_2dc;
                }
                else {
                  iVar1 = Q_strcmp(local_20c,"noise");
                  if (iVar1 == 0) {
                    puVar2 = local_2c8;
                  }
                  else {
                    iVar1 = Q_strcmp(local_20c,"noise1");
                    if (iVar1 == 0) {
                      puVar2 = local_2c4;
                    }
                    else {
                      iVar1 = Q_strcmp(local_20c,"noise2");
                      if (iVar1 == 0) {
                        puVar2 = local_2c0;
                      }
                      else {
                        iVar1 = Q_strcmp(local_20c,"noise3");
                        if (iVar1 == 0) {
                          puVar2 = local_2bc;
                        }
                        else {
                          iVar1 = Q_strcmp(local_20c,"globalname");
                          if (iVar1 != 0) {
                            return -1;
                          }
                          puVar2 = local_4ac;
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
  return (int)puVar2 - (int)local_4b0;
}


// mainSort  @ 000de90f
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
LAB_000ded11:
  iVar8 = aiStack_9cc[local_11e4];
  puVar10 = (uint *)(iVar8 * 0x400 + param_1);
  local_1200 = 0;
  local_11fc = puVar10;
LAB_000ded4b:
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
LAB_000dee22:
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
                      if (!bVar32) goto LAB_000df53b;
                      bVar31 = in_EDX[iVar29 + 2] < in_EDX[iVar28 + 2];
                      bVar32 = in_EDX[iVar29 + 2] == in_EDX[iVar28 + 2];
                      if (!bVar32) goto LAB_000df53b;
                      bVar31 = in_EDX[iVar29 + 3] < in_EDX[iVar28 + 3];
                      bVar32 = in_EDX[iVar29 + 3] == in_EDX[iVar28 + 3];
                      if (!bVar32) goto LAB_000df53b;
                      bVar31 = in_EDX[iVar29 + 4] < in_EDX[iVar28 + 4];
                      bVar32 = in_EDX[iVar29 + 4] == in_EDX[iVar28 + 4];
                      if (!bVar32) goto LAB_000df53b;
                      bVar31 = in_EDX[iVar29 + 5] < in_EDX[iVar28 + 5];
                      bVar32 = in_EDX[iVar29 + 5] == in_EDX[iVar28 + 5];
                      if (!bVar32) goto LAB_000df53b;
                      bVar31 = in_EDX[iVar29 + 6] < in_EDX[iVar28 + 6];
                      bVar32 = in_EDX[iVar29 + 6] == in_EDX[iVar28 + 6];
                      if (!bVar32) goto LAB_000df53b;
                      bVar31 = in_EDX[iVar29 + 7] < in_EDX[iVar28 + 7];
                      bVar32 = in_EDX[iVar29 + 7] == in_EDX[iVar28 + 7];
                      if (!bVar32) goto LAB_000df53b;
                      bVar31 = in_EDX[iVar29 + 8] < in_EDX[iVar28 + 8];
                      bVar32 = in_EDX[iVar29 + 8] == in_EDX[iVar28 + 8];
                      if (!bVar32) goto LAB_000df53b;
                      bVar31 = in_EDX[iVar29 + 9] < in_EDX[iVar28 + 9];
                      bVar32 = in_EDX[iVar29 + 9] == in_EDX[iVar28 + 9];
                      if (!bVar32) goto LAB_000df53b;
                      bVar31 = in_EDX[iVar29 + 10] < in_EDX[iVar28 + 10];
                      bVar32 = in_EDX[iVar29 + 10] == in_EDX[iVar28 + 10];
                      if (!bVar32) goto LAB_000df53b;
                      bVar31 = in_EDX[iVar29 + 0xb] < in_EDX[iVar28 + 0xb];
                      bVar32 = in_EDX[iVar29 + 0xb] == in_EDX[iVar28 + 0xb];
                      if (!bVar32) goto LAB_000df53b;
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
LAB_000e025d:
                          bVar31 = !bVar31 && !bVar32;
                          goto LAB_000df53e;
                        }
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 1) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 1) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000e025d;
                        bVar31 = in_EDX[local_1260 + 2] < in_EDX[uVar19 + 2];
                        bVar32 = in_EDX[local_1260 + 2] == in_EDX[uVar19 + 2];
                        if (!bVar32) goto LAB_000e025d;
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 2) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 2) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000e025d;
                        bVar31 = in_EDX[local_1260 + 3] < in_EDX[uVar19 + 3];
                        bVar32 = in_EDX[local_1260 + 3] == in_EDX[uVar19 + 3];
                        if (!bVar32) goto LAB_000e025d;
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 3) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 3) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000e025d;
                        bVar31 = in_EDX[local_1260 + 4] < in_EDX[uVar19 + 4];
                        bVar32 = in_EDX[local_1260 + 4] == in_EDX[uVar19 + 4];
                        if (!bVar32) break;
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 4) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 4) * 2);
                        if (uVar5 != uVar4) {
                          bVar31 = uVar4 < uVar5;
                          goto LAB_000df53e;
                        }
                        bVar31 = in_EDX[local_1260 + 5] < in_EDX[uVar19 + 5];
                        bVar32 = in_EDX[local_1260 + 5] == in_EDX[uVar19 + 5];
                        if (!bVar32) {
LAB_000e0206:
                          bVar31 = !bVar31 && !bVar32;
                          goto LAB_000df53e;
                        }
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 5) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 5) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000e0206;
                        bVar31 = in_EDX[local_1260 + 6] < in_EDX[uVar19 + 6];
                        bVar32 = in_EDX[local_1260 + 6] == in_EDX[uVar19 + 6];
                        if (!bVar32) goto LAB_000e0206;
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 6) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 6) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000e0206;
                        bVar31 = in_EDX[local_1260 + 7] < in_EDX[uVar19 + 7];
                        bVar32 = in_EDX[local_1260 + 7] == in_EDX[uVar19 + 7];
                        if (!bVar32) goto LAB_000df53b;
                        uVar4 = *(ushort *)(in_ECX + (uVar19 + 7) * 2);
                        uVar5 = *(ushort *)(in_ECX + (local_1260 + 7) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000df53b;
                        uVar30 = local_1260 + 8;
                        uVar19 = uVar19 + 8;
                        local_1260 = uVar30 - param_2;
                        if (uVar30 < param_2) {
                          local_1260 = uVar30;
                        }
                        if (param_2 <= uVar19) {
                          uVar19 = uVar19 - param_2;
                        }
                        *param_4 = *param_4 + -1;
                        local_11d0 = local_11d0 + -8;
                        if (local_11d0 < 0) {
                          local_123c = (int *)(in_EAX + local_1240 * 4);
                          goto LAB_000df866;
                        }
                      }
                      bVar31 = !bVar31 && !bVar32;
                    }
                    else {
LAB_000df53b:
                      bVar31 = !bVar31 && !bVar32;
                    }
LAB_000df53e:
                    if (!bVar31) {
                      local_123c = (int *)(in_EAX + local_1240 * 4);
                      break;
                    }
                    local_123c[iVar16] = *local_123c;
                    iVar26 = iVar26 + iVar11;
                    local_1240 = iVar26 + iVar16;
                    piVar15 = local_123c + -iVar16;
                  } while (iVar25 <= local_1240);
LAB_000df866:
                  *local_123c = iVar17;
                  if (local_1230 < local_1234 + 1) break;
                  iVar26 = *(int *)(in_EAX + 4 + local_1234 * 4);
                  iVar28 = local_1228 + 1;
                  local_1240 = iVar28 + iVar16;
                  iVar17 = iVar22 + iVar26;
                  piVar15 = local_121c + -1;
                  do {
                    local_1238 = piVar15;
                    iVar29 = iVar22 + *local_1238;
                    bVar31 = in_EDX[iVar29] < in_EDX[iVar17];
                    bVar32 = in_EDX[iVar29] == in_EDX[iVar17];
                    if (bVar32) {
                      bVar31 = in_EDX[iVar29 + 1] < in_EDX[iVar17 + 1];
                      bVar32 = in_EDX[iVar29 + 1] == in_EDX[iVar17 + 1];
                      if (!bVar32) goto LAB_000df8c6;
                      bVar31 = in_EDX[iVar29 + 2] < in_EDX[iVar17 + 2];
                      bVar32 = in_EDX[iVar29 + 2] == in_EDX[iVar17 + 2];
                      if (!bVar32) goto LAB_000df8c6;
                      bVar31 = in_EDX[iVar29 + 3] < in_EDX[iVar17 + 3];
                      bVar32 = in_EDX[iVar29 + 3] == in_EDX[iVar17 + 3];
                      if (!bVar32) goto LAB_000df8c6;
                      bVar31 = in_EDX[iVar29 + 4] < in_EDX[iVar17 + 4];
                      bVar32 = in_EDX[iVar29 + 4] == in_EDX[iVar17 + 4];
                      if (!bVar32) goto LAB_000df8c6;
                      bVar31 = in_EDX[iVar29 + 5] < in_EDX[iVar17 + 5];
                      bVar32 = in_EDX[iVar29 + 5] == in_EDX[iVar17 + 5];
                      if (!bVar32) goto LAB_000df8c6;
                      bVar31 = in_EDX[iVar29 + 6] < in_EDX[iVar17 + 6];
                      bVar32 = in_EDX[iVar29 + 6] == in_EDX[iVar17 + 6];
                      if (!bVar32) goto LAB_000df8c6;
                      bVar31 = in_EDX[iVar29 + 7] < in_EDX[iVar17 + 7];
                      bVar32 = in_EDX[iVar29 + 7] == in_EDX[iVar17 + 7];
                      if (!bVar32) goto LAB_000df8c6;
                      bVar31 = in_EDX[iVar29 + 8] < in_EDX[iVar17 + 8];
                      bVar32 = in_EDX[iVar29 + 8] == in_EDX[iVar17 + 8];
                      if (!bVar32) goto LAB_000df8c6;
                      bVar31 = in_EDX[iVar29 + 9] < in_EDX[iVar17 + 9];
                      bVar32 = in_EDX[iVar29 + 9] == in_EDX[iVar17 + 9];
                      if (!bVar32) goto LAB_000df8c6;
                      bVar31 = in_EDX[iVar29 + 10] < in_EDX[iVar17 + 10];
                      bVar32 = in_EDX[iVar29 + 10] == in_EDX[iVar17 + 10];
                      if (!bVar32) goto LAB_000df8c6;
                      bVar31 = in_EDX[iVar29 + 0xb] < in_EDX[iVar17 + 0xb];
                      bVar32 = in_EDX[iVar29 + 0xb] == in_EDX[iVar17 + 0xb];
                      if (!bVar32) goto LAB_000df8c6;
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
                          goto LAB_000df8c9;
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
                        if (!bVar32) goto LAB_000df8c6;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 7) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 7) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000df8c6;
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
                          goto LAB_000dfbf2;
                        }
                      }
                      bVar31 = !bVar31 && !bVar32;
                    }
                    else {
LAB_000df8c6:
                      bVar31 = !bVar31 && !bVar32;
                    }
LAB_000df8c9:
                    if (!bVar31) {
                      local_1238 = (int *)(in_EAX + local_1240 * 4);
                      break;
                    }
                    local_1238[iVar16] = *local_1238;
                    iVar28 = iVar28 + iVar11;
                    local_1240 = iVar28 + iVar16;
                    piVar15 = local_1238 + -iVar16;
                  } while (iVar25 <= local_1240);
LAB_000dfbf2:
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
                      if (!bVar32) goto LAB_000dfc54;
                      bVar31 = in_EDX[iVar29 + 2] < in_EDX[iVar17 + 2];
                      bVar32 = in_EDX[iVar29 + 2] == in_EDX[iVar17 + 2];
                      if (!bVar32) goto LAB_000dfc54;
                      bVar31 = in_EDX[iVar29 + 3] < in_EDX[iVar17 + 3];
                      bVar32 = in_EDX[iVar29 + 3] == in_EDX[iVar17 + 3];
                      if (!bVar32) goto LAB_000dfc54;
                      bVar31 = in_EDX[iVar29 + 4] < in_EDX[iVar17 + 4];
                      bVar32 = in_EDX[iVar29 + 4] == in_EDX[iVar17 + 4];
                      if (!bVar32) goto LAB_000dfc54;
                      bVar31 = in_EDX[iVar29 + 5] < in_EDX[iVar17 + 5];
                      bVar32 = in_EDX[iVar29 + 5] == in_EDX[iVar17 + 5];
                      if (!bVar32) goto LAB_000dfc54;
                      bVar31 = in_EDX[iVar29 + 6] < in_EDX[iVar17 + 6];
                      bVar32 = in_EDX[iVar29 + 6] == in_EDX[iVar17 + 6];
                      if (!bVar32) goto LAB_000dfc54;
                      bVar31 = in_EDX[iVar29 + 7] < in_EDX[iVar17 + 7];
                      bVar32 = in_EDX[iVar29 + 7] == in_EDX[iVar17 + 7];
                      if (!bVar32) goto LAB_000dfc54;
                      bVar31 = in_EDX[iVar29 + 8] < in_EDX[iVar17 + 8];
                      bVar32 = in_EDX[iVar29 + 8] == in_EDX[iVar17 + 8];
                      if (!bVar32) goto LAB_000dfc54;
                      bVar31 = in_EDX[iVar29 + 9] < in_EDX[iVar17 + 9];
                      bVar32 = in_EDX[iVar29 + 9] == in_EDX[iVar17 + 9];
                      if (!bVar32) goto LAB_000dfc54;
                      bVar31 = in_EDX[iVar29 + 10] < in_EDX[iVar17 + 10];
                      bVar32 = in_EDX[iVar29 + 10] == in_EDX[iVar17 + 10];
                      if (!bVar32) goto LAB_000dfc54;
                      bVar31 = in_EDX[iVar29 + 0xb] < in_EDX[iVar17 + 0xb];
                      bVar32 = in_EDX[iVar29 + 0xb] == in_EDX[iVar17 + 0xb];
                      if (!bVar32) goto LAB_000dfc54;
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
                          goto LAB_000dfc57;
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
                        if (!bVar32) goto LAB_000dfc54;
                        uVar4 = *(ushort *)(in_ECX + (uVar30 + 7) * 2);
                        uVar5 = *(ushort *)(in_ECX + (uVar19 + 7) * 2);
                        bVar31 = uVar5 < uVar4;
                        bVar32 = uVar5 == uVar4;
                        if (!bVar32) goto LAB_000dfc54;
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
                          goto LAB_000dff86;
                        }
                      }
                      bVar31 = !bVar31 && !bVar32;
                    }
                    else {
LAB_000dfc54:
                      bVar31 = !bVar31 && !bVar32;
                    }
LAB_000dfc57:
                    if (!bVar31) {
                      local_1238 = (int *)(in_EAX + local_1240 * 4);
                      break;
                    }
                    local_1238[iVar16] = *local_1238;
                    iVar28 = iVar28 + iVar11;
                    local_1240 = iVar16 + iVar28;
                    piVar15 = local_1238 + -iVar16;
                  } while (iVar25 <= local_1240);
LAB_000dff86:
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
          if (local_120c == 0) goto LAB_000df1ea;
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
LAB_000deef8:
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
                else if ((int)(in_EDX[iVar11 + iVar22] - uVar19) < 0) goto LAB_000df1c3;
                piVar15 = piVar15 + -1;
                iVar25 = iVar16;
                if (iVar16 < (int)uVar30) goto joined_r0x000df00c;
              } while( true );
            }
          }
joined_r0x000df00c:
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
        goto LAB_000dee22;
      }
    }
    goto LAB_000df213;
  }
  goto LAB_000df222;
LAB_000df1ea:
  local_11e8 = local_11e8 + 1 + (iVar21 - uVar14);
  uVar19 = *local_11fc;
LAB_000df213:
  *local_11fc = uVar19 | 0x200000;
LAB_000df222:
  local_1200 = local_1200 + 1;
  local_11fc = local_11fc + 1;
  if (local_1200 == 0x100) goto code_r0x000df243;
  goto LAB_000ded4b;
LAB_000df1c3:
  if (iVar25 < (int)uVar30) goto joined_r0x000df00c;
  iVar25 = *(int *)(in_EAX + -4 + local_1248 * 4);
  *(int *)(in_EAX + -4 + local_1248 * 4) = iVar11;
  *piVar15 = iVar25;
  goto LAB_000deef8;
code_r0x000df243:
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
  if (local_11e4 == 0xff) goto LAB_000e00b0;
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
LAB_000e00b0:
    if (3 < param_3) {
      fprintf(_stderr,"        %d pointers, %d sorted, %d scanned\n",param_2,local_11e8,
              param_2 - local_11e8);
    }
    return;
  }
  goto LAB_000ded11;
}


// memfgets  @ 000bbd10
char * memfgets(uchar *pMemFile,int fileSize,int *pFilePos,char *pBuffer,int bufferSize)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int filePos@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int last@[???]
                       Unresolved local var: int stop@[???] */
  iVar1 = *pFilePos;
  if (((pBuffer != (char *)0x0) && (pMemFile != (uchar *)0x0)) && (iVar1 < fileSize)) {
    iVar4 = iVar1 + -1 + bufferSize;
    if (fileSize - iVar1 < bufferSize) {
      iVar4 = fileSize;
    }
    iVar2 = iVar1;
    if (iVar1 < iVar4) {
      do {
        iVar3 = iVar2 + 1;
        if (pMemFile[iVar2] == '\n') break;
        iVar2 = iVar3;
      } while (iVar3 < iVar4);
      if (iVar1 != iVar3) {
                    /* Unresolved local var: int size@[???] */
        iVar4 = iVar3 - iVar1;
        Q_memcpy(pBuffer,pMemFile + iVar1,iVar4);
        if (iVar4 < bufferSize) {
          pBuffer[iVar4] = '\0';
        }
        *pFilePos = iVar3;
        return pBuffer;
      }
    }
  }
  return (char *)0x0;
}


// memsearch  @ 000634f0
int memsearch(uchar *start,int count,int search)

{
  byte bVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = -1;
  if (0 < count) {
    iVar2 = 0;
    bVar1 = *start;
    while ((uint)bVar1 != search) {
      iVar2 = iVar2 + 1;
      if (iVar2 == count) {
        return -1;
      }
      bVar1 = start[iVar2];
    }
  }
  return iVar2;
}


// myfeof  @ 000d59ab
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


// ran1  @ 00090610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int32 ran1(void)

{
  int iVar1;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: int32 k@[???] */
  if ((idum < 1) || (ran1::iy == 0)) {
    idum = -idum;
    iVar1 = 0x27;
    if (idum < 1) {
      idum = 1;
    }
    do {
      idum = idum * 0x41a7 + (idum / 0x1f31d) * -0x7fffffff;
      if (idum < 0) {
        idum = idum + 0x7fffffff;
      }
      if (iVar1 < 0x20) {
        ran1::iv[iVar1] = idum;
      }
      iVar1 = iVar1 + -1;
    } while (iVar1 != -1);
    ran1::iy = ran1::iv[0];
  }
  idum = idum * 0x41a7 + (idum / 0x1f31d) * -0x7fffffff;
  if (idum < 0) {
    idum = idum + 0x7fffffff;
  }
  iVar1 = ran1::iy + 0x3ffffff;
  if (-1 < ran1::iy) {
    iVar1 = ran1::iy;
  }
  ran1::iy = ran1::iv[iVar1 >> 0x1a];
  ran1::iv[iVar1 >> 0x1a] = idum;
  return ran1::iy;
}


// va  @ 00063440
char * va(char *format,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  va::current = va::current + 1U & 0xf;
  vsnprintf(va::string[va::current],0x400,format,&stack0x00000008);
  return va::string[va::current];
}


// vstr  @ 00063490
char * vstr(vec_t *v)

{
  vstr::idx = vstr::idx + 1U & 0xf;
  snprintf(vstr::string[vstr::idx],0x400,"%.4f %.4f %.4f",(double)*v,(double)v[1],(double)v[2]);
  return vstr::string[vstr::idx];
}


