// Ghidra decompilation of functions from tfc/areadef.cpp
// 14 functions, ordered by original source line

// info_areadef  @ 000ada10  (line 14)

void info_areadef(entvars_t *pev)

{
  CAreaDef *pCVar1;
  edict_t *peVar2;
  
                    /* Unresolved local var: entvars_t * pev@[???] */
  if (pev == (entvars_t *)0x0) {
    peVar2 = (*g_engfuncs.pfnCreateEntity)();
    if (peVar2 != (edict_t *)0x0) {
      pev = &peVar2->v;
    }
  }
  if ((pev->pContainingEntity != (edict_t *)0x0) &&
     (pev->pContainingEntity->pvPrivateData != (void *)0x0)) {
    return;
  }
  pCVar1 = CBaseEntity::operator_new(0x528,pev);
  (pCVar1->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CAreaDef_00177dc8;
  pCVar1->m_ClassData[0].m_DB_PingTotal = 0;
  pCVar1->m_ClassData[0].m_DB_nPingTests = 0;
  pCVar1->m_ClassData[0].m_DB_TimeInArea = 0;
  pCVar1->m_ClassData[1].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&pCVar1->m_ClassData[1].m_DB_nPingTests = (undefined1  [16])0x0;
  *(undefined1 (*) [16])&pCVar1->m_ClassData[2].m_DB_TimeInArea = (undefined1  [16])0x0;
  pCVar1->m_ClassData[4].m_DB_PingTotal = 0;
  pCVar1->m_ClassData[4].m_DB_nPingTests = 0;
  pCVar1->m_ClassData[4].m_DB_TimeInArea = 0;
  pCVar1->m_ClassData[5].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&pCVar1->m_ClassData[5].m_DB_nPingTests = (undefined1  [16])0x0;
  *(undefined1 (*) [16])&pCVar1->m_ClassData[6].m_DB_TimeInArea = (undefined1  [16])0x0;
  pCVar1->m_ClassData[8].m_DB_PingTotal = 0;
  pCVar1->m_ClassData[8].m_DB_nPingTests = 0;
  pCVar1->m_ClassData[8].m_DB_TimeInArea = 0;
  pCVar1->m_ClassData[9].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&pCVar1->m_ClassData[9].m_DB_nPingTests = (undefined1  [16])0x0;
  *(undefined1 (*) [16])&pCVar1->m_ClassData[10].m_DB_TimeInArea = (undefined1  [16])0x0;
  pCVar1->m_AreaName[0] = '\0';
  (pCVar1->super_CBaseEntity).pev = pev;
  pCVar1->m_pNext = g_pActiveAreas;
  g_nActiveAreas = g_nActiveAreas + 1;
  g_pActiveAreas = pCVar1;
  return;
}


// CAreaDef::Restore  @ 000ad870  (line 21)

/* DWARF original prototype: int Restore(CAreaDef * this, CRestore * restore) */

int __thiscall CAreaDef::Restore(CAreaDef *this,CRestore *restore)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Restore(&this->super_CBaseEntity,restore);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CRestore::ReadFields(restore,"CAreaDef",this,m_SaveData,1);
  }
  return iVar2;
}


// CAreaDef::Save  @ 000ad8d0  (line 21)

/* DWARF original prototype: int Save(CAreaDef * this, CSave * save) */

int __thiscall CAreaDef::Save(CAreaDef *this,CSave *save)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CBaseEntity::Save(&this->super_CBaseEntity,save);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = CSave::WriteFields(save,"CAreaDef",this,m_SaveData,1);
  }
  return iVar2;
}


// DBAreaClassData::DBAreaClassData  @ 000adaf0  (line 38)

/* DWARF original prototype: void DBAreaClassData(DBAreaClassData * this) */

void __thiscall DBAreaClassData::DBAreaClassData(DBAreaClassData *this)

{
  this->m_DB_PingTotal = 0;
  this->m_DB_nPingTests = 0;
  this->m_DB_TimeInArea = 0;
  return;
}


// DBAreaClassData::Clear  @ 000adb10  (line 45)

/* DWARF original prototype: void Clear(DBAreaClassData * this) */

void __thiscall DBAreaClassData::Clear(DBAreaClassData *this)

{
  this->m_DB_PingTotal = 0;
  this->m_DB_nPingTests = 0;
  this->m_DB_TimeInArea = 0;
  return;
}


// DBAreaClassData::MergeData  @ 000adb30  (line 53)

/* DWARF original prototype: void MergeData(DBAreaClassData * this, DBAreaClassData * pSource) */

void __thiscall DBAreaClassData::MergeData(DBAreaClassData *this,DBAreaClassData *pSource)

{
  this->m_DB_PingTotal = this->m_DB_PingTotal + pSource->m_DB_PingTotal;
  this->m_DB_nPingTests = this->m_DB_nPingTests + pSource->m_DB_nPingTests;
  this->m_DB_TimeInArea = this->m_DB_TimeInArea + pSource->m_DB_TimeInArea;
  pSource->m_DB_PingTotal = 0;
  pSource->m_DB_nPingTests = 0;
  pSource->m_DB_TimeInArea = 0;
  return;
}


// CAreaDef::CAreaDef  @ 000adb60  (line 65)

/* DWARF original prototype: void CAreaDef(CAreaDef * this, bool bDefaultArea) */

void __thiscall CAreaDef::CAreaDef(CAreaDef *this,bool bDefaultArea)

{
  CAreaDef *pCVar1;
  
  (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CAreaDef_00177dc8;
  this->m_ClassData[0].m_DB_PingTotal = 0;
  this->m_ClassData[0].m_DB_nPingTests = 0;
  this->m_ClassData[0].m_DB_TimeInArea = 0;
  this->m_ClassData[1].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&this->m_ClassData[1].m_DB_nPingTests = (undefined1  [16])0x0;
  g_nActiveAreas = g_nActiveAreas + 1;
  *(undefined1 (*) [16])&this->m_ClassData[2].m_DB_TimeInArea = (undefined1  [16])0x0;
  this->m_ClassData[4].m_DB_PingTotal = 0;
  this->m_ClassData[4].m_DB_nPingTests = 0;
  this->m_ClassData[4].m_DB_TimeInArea = 0;
  this->m_ClassData[5].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&this->m_ClassData[5].m_DB_nPingTests = (undefined1  [16])0x0;
  *(undefined1 (*) [16])&this->m_ClassData[6].m_DB_TimeInArea = (undefined1  [16])0x0;
  this->m_ClassData[8].m_DB_PingTotal = 0;
  this->m_ClassData[8].m_DB_nPingTests = 0;
  this->m_ClassData[8].m_DB_TimeInArea = 0;
  this->m_ClassData[9].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&this->m_ClassData[9].m_DB_nPingTests = (undefined1  [16])0x0;
  *(undefined1 (*) [16])&this->m_ClassData[10].m_DB_TimeInArea = (undefined1  [16])0x0;
  pCVar1 = g_pActiveAreas;
  if (!bDefaultArea) {
    this->m_AreaName[0] = '\0';
    g_pActiveAreas = this;
    this->m_pNext = pCVar1;
    return;
  }
  builtin_strncpy(this->m_AreaName,"Defa",4);
  builtin_strncpy(this->m_AreaName + 4,"ultA",4);
  builtin_strncpy(this->m_AreaName + 8,"rea",4);
  this->m_pNext = (CAreaDef *)0x0;
  g_pActiveAreas = this;
  return;
}


// CAreaDef::~CAreaDef  @ 000ad820  (line 84)

/* DWARF original prototype: void ~CAreaDef(CAreaDef * this, int __in_chrg) */

void __thiscall CAreaDef::~CAreaDef(CAreaDef *this,int __in_chrg)

{
  CAreaDef *pCVar1;
  CAreaDef **ppCVar2;
  
  (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CAreaDef_00177dc8;
                    /* Unresolved local var: CAreaDef * * pPrev@[???]
                       Unresolved local var: CAreaDef * pCur@[???] */
  g_nActiveAreas = g_nActiveAreas + -1;
  if (g_pActiveAreas != (CAreaDef *)0x0) {
    pCVar1 = g_pActiveAreas;
    if (this == g_pActiveAreas) {
      ppCVar2 = &g_pActiveAreas;
    }
    else {
      do {
        ppCVar2 = &pCVar1->m_pNext;
        pCVar1 = pCVar1->m_pNext;
        if (pCVar1 == (CAreaDef *)0x0) goto LAB_000ad854;
      } while (this != pCVar1);
    }
    *ppCVar2 = pCVar1->m_pNext;
    (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBaseEntity_00194048;
    return;
  }
LAB_000ad854:
  (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBaseEntity_00194048;
  return;
}


// CAreaDef::~CAreaDef  @ 000ad9c0  (line 84)

/* DWARF original prototype: void ~CAreaDef(CAreaDef * this, int __in_chrg) */

void __thiscall CAreaDef::~CAreaDef(CAreaDef *this,int __in_chrg)

{
  CAreaDef *pCVar1;
  CAreaDef **ppCVar2;
  
  (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CAreaDef_00177dc8;
                    /* Unresolved local var: CAreaDef * * pPrev@[???]
                       Unresolved local var: CAreaDef * pCur@[???] */
  g_nActiveAreas = g_nActiveAreas + -1;
  if (g_pActiveAreas != (CAreaDef *)0x0) {
    pCVar1 = g_pActiveAreas;
    if (this == g_pActiveAreas) {
      ppCVar2 = &g_pActiveAreas;
    }
    else {
      do {
        ppCVar2 = &pCVar1->m_pNext;
        pCVar1 = pCVar1->m_pNext;
        if (pCVar1 == (CAreaDef *)0x0) goto LAB_000ad9f4;
      } while (this != pCVar1);
    }
    *ppCVar2 = pCVar1->m_pNext;
    (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBaseEntity_00194048;
    return;
  }
LAB_000ad9f4:
  (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CBaseEntity_00194048;
  return;
}


// CAreaDef::KeyValue  @ 000ad930  (line 106)

/* DWARF original prototype: void KeyValue(CAreaDef * this, KeyValueData * pkvd) */

void __thiscall CAreaDef::KeyValue(CAreaDef *this,KeyValueData *pkvd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  bVar4 = &stack0x00000000 == (undefined1 *)0x2c;
  iVar1 = 9;
  pcVar2 = pkvd->szKeyName;
  pcVar3 = "areaname";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    CBaseEntity::KeyValue(&this->super_CBaseEntity,pkvd);
    return;
  }
  strncpy(this->m_AreaName,pkvd->szValue,0x1f);
  this->m_AreaName[0x1f] = '\0';
  pkvd->fHandled = 1;
  return;
}


// CAreaDef::GetClassData  @ 000adc10  (line 121)

/* DWARF original prototype: DBAreaClassData * GetClassData(CAreaDef * this, char * pClassName) */

DBAreaClassData * __thiscall CAreaDef::GetClassData(CAreaDef *this,char *pClassName)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = strcasecmp(pClassName,sClassNames[0]);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = strcasecmp(pClassName,sClassNames[1]);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = strcasecmp(pClassName,sClassNames[2]);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = strcasecmp(pClassName,sClassNames[3]);
        if (iVar1 == 0) {
          iVar1 = 3;
        }
        else {
          iVar1 = strcasecmp(pClassName,sClassNames[4]);
          if (iVar1 == 0) {
            iVar1 = 4;
          }
          else {
            iVar1 = strcasecmp(pClassName,sClassNames[5]);
            if (iVar1 == 0) {
              iVar1 = 5;
            }
            else {
              iVar1 = strcasecmp(pClassName,sClassNames[6]);
              if (iVar1 == 0) {
                iVar1 = 6;
              }
              else {
                iVar1 = strcasecmp(pClassName,sClassNames[7]);
                if (iVar1 == 0) {
                  iVar1 = 7;
                }
                else {
                  iVar1 = strcasecmp(pClassName,sClassNames[8]);
                  if (iVar1 == 0) {
                    iVar1 = 8;
                  }
                  else {
                    iVar1 = strcasecmp(pClassName,sClassNames[9]);
                    if (iVar1 == 0) {
                      iVar1 = 9;
                    }
                    else {
                      iVar1 = strcasecmp(pClassName,sClassNames[10]);
                      if (iVar1 == 0) {
                        iVar1 = 10;
                      }
                      else {
                        iVar1 = strcasecmp(pClassName,sClassNames[0xb]);
                        if (iVar1 != 0) {
                          return (DBAreaClassData *)0x0;
                        }
                        iVar1 = 0xb;
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
  return this->m_ClassData + iVar1;
}


// CAreaDef::MergeData  @ 000ade20  (line 133)

/* DWARF original prototype: void MergeData(CAreaDef * this, CAreaDef * pSource) */

void __thiscall CAreaDef::MergeData(CAreaDef *this,CAreaDef *pSource)

{
  int *piVar1;
  
                    /* Unresolved local var: int i@[???] */
  this->m_ClassData[0].m_DB_PingTotal =
       this->m_ClassData[0].m_DB_PingTotal + pSource->m_ClassData[0].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[0].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[0].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[0].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[0].m_DB_TimeInArea;
  pSource->m_ClassData[0].m_DB_PingTotal = 0;
  pSource->m_ClassData[0].m_DB_nPingTests = 0;
  pSource->m_ClassData[0].m_DB_TimeInArea = 0;
  this->m_ClassData[1].m_DB_PingTotal =
       this->m_ClassData[1].m_DB_PingTotal + pSource->m_ClassData[1].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[1].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[1].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[1].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[1].m_DB_TimeInArea;
  pSource->m_ClassData[1].m_DB_PingTotal = 0;
  pSource->m_ClassData[1].m_DB_nPingTests = 0;
  pSource->m_ClassData[1].m_DB_TimeInArea = 0;
  this->m_ClassData[2].m_DB_PingTotal =
       this->m_ClassData[2].m_DB_PingTotal + pSource->m_ClassData[2].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[2].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[2].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[2].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[2].m_DB_TimeInArea;
  pSource->m_ClassData[2].m_DB_PingTotal = 0;
  pSource->m_ClassData[2].m_DB_nPingTests = 0;
  pSource->m_ClassData[2].m_DB_TimeInArea = 0;
  this->m_ClassData[3].m_DB_PingTotal =
       this->m_ClassData[3].m_DB_PingTotal + pSource->m_ClassData[3].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[3].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[3].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[3].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[3].m_DB_TimeInArea;
  pSource->m_ClassData[3].m_DB_PingTotal = 0;
  pSource->m_ClassData[3].m_DB_nPingTests = 0;
  pSource->m_ClassData[3].m_DB_TimeInArea = 0;
  this->m_ClassData[4].m_DB_PingTotal =
       this->m_ClassData[4].m_DB_PingTotal + pSource->m_ClassData[4].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[4].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[4].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[4].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[4].m_DB_TimeInArea;
  pSource->m_ClassData[4].m_DB_PingTotal = 0;
  pSource->m_ClassData[4].m_DB_nPingTests = 0;
  pSource->m_ClassData[4].m_DB_TimeInArea = 0;
  this->m_ClassData[5].m_DB_PingTotal =
       this->m_ClassData[5].m_DB_PingTotal + pSource->m_ClassData[5].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[5].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[5].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[5].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[5].m_DB_TimeInArea;
  pSource->m_ClassData[5].m_DB_PingTotal = 0;
  pSource->m_ClassData[5].m_DB_nPingTests = 0;
  pSource->m_ClassData[5].m_DB_TimeInArea = 0;
  this->m_ClassData[6].m_DB_PingTotal =
       this->m_ClassData[6].m_DB_PingTotal + pSource->m_ClassData[6].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[6].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[6].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[6].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[6].m_DB_TimeInArea;
  pSource->m_ClassData[6].m_DB_PingTotal = 0;
  pSource->m_ClassData[6].m_DB_nPingTests = 0;
  pSource->m_ClassData[6].m_DB_TimeInArea = 0;
  this->m_ClassData[7].m_DB_PingTotal =
       this->m_ClassData[7].m_DB_PingTotal + pSource->m_ClassData[7].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[7].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[7].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[7].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[7].m_DB_TimeInArea;
  pSource->m_ClassData[7].m_DB_PingTotal = 0;
  pSource->m_ClassData[7].m_DB_nPingTests = 0;
  pSource->m_ClassData[7].m_DB_TimeInArea = 0;
  this->m_ClassData[8].m_DB_PingTotal =
       this->m_ClassData[8].m_DB_PingTotal + pSource->m_ClassData[8].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[8].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[8].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[8].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[8].m_DB_TimeInArea;
  pSource->m_ClassData[8].m_DB_PingTotal = 0;
  pSource->m_ClassData[8].m_DB_nPingTests = 0;
  pSource->m_ClassData[8].m_DB_TimeInArea = 0;
  this->m_ClassData[9].m_DB_PingTotal =
       this->m_ClassData[9].m_DB_PingTotal + pSource->m_ClassData[9].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[9].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[9].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[9].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[9].m_DB_TimeInArea;
  pSource->m_ClassData[9].m_DB_PingTotal = 0;
  pSource->m_ClassData[9].m_DB_nPingTests = 0;
  pSource->m_ClassData[9].m_DB_TimeInArea = 0;
  this->m_ClassData[10].m_DB_PingTotal =
       this->m_ClassData[10].m_DB_PingTotal + pSource->m_ClassData[10].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[10].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[10].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[10].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[10].m_DB_TimeInArea;
  pSource->m_ClassData[10].m_DB_PingTotal = 0;
  pSource->m_ClassData[10].m_DB_nPingTests = 0;
  pSource->m_ClassData[10].m_DB_TimeInArea = 0;
  this->m_ClassData[0xb].m_DB_PingTotal =
       this->m_ClassData[0xb].m_DB_PingTotal + pSource->m_ClassData[0xb].m_DB_PingTotal;
  piVar1 = &this->m_ClassData[0xb].m_DB_nPingTests;
  *piVar1 = *piVar1 + pSource->m_ClassData[0xb].m_DB_nPingTests;
  piVar1 = &this->m_ClassData[0xb].m_DB_TimeInArea;
  *piVar1 = *piVar1 + pSource->m_ClassData[0xb].m_DB_TimeInArea;
  pSource->m_ClassData[0xb].m_DB_PingTotal = 0;
  pSource->m_ClassData[0xb].m_DB_nPingTests = 0;
  pSource->m_ClassData[0xb].m_DB_TimeInArea = 0;
  return;
}


// CAreaDef::ClearClassData  @ 000ae100  (line 140)

/* DWARF original prototype: void ClearClassData(CAreaDef * this) */

void __thiscall CAreaDef::ClearClassData(CAreaDef *this)

{
  this->m_ClassData[0].m_DB_PingTotal = 0;
  this->m_ClassData[0].m_DB_nPingTests = 0;
  this->m_ClassData[0].m_DB_TimeInArea = 0;
  this->m_ClassData[1].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&this->m_ClassData[1].m_DB_nPingTests = (undefined1  [16])0x0;
  *(undefined1 (*) [16])&this->m_ClassData[2].m_DB_TimeInArea = (undefined1  [16])0x0;
  this->m_ClassData[4].m_DB_PingTotal = 0;
  this->m_ClassData[4].m_DB_nPingTests = 0;
  this->m_ClassData[4].m_DB_TimeInArea = 0;
  this->m_ClassData[5].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&this->m_ClassData[5].m_DB_nPingTests = (undefined1  [16])0x0;
  *(undefined1 (*) [16])&this->m_ClassData[6].m_DB_TimeInArea = (undefined1  [16])0x0;
  this->m_ClassData[8].m_DB_PingTotal = 0;
  this->m_ClassData[8].m_DB_nPingTests = 0;
  this->m_ClassData[8].m_DB_TimeInArea = 0;
  this->m_ClassData[9].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&this->m_ClassData[9].m_DB_nPingTests = (undefined1  [16])0x0;
  *(undefined1 (*) [16])&this->m_ClassData[10].m_DB_TimeInArea = (undefined1  [16])0x0;
  return;
}


// _GLOBAL__sub_I_info_areadef  @ 000aca10  (line 143)

void processEntry _GLOBAL__sub_I_info_areadef(void)

{
  CAreaDef::CAreaDef(&g_DefaultArea,true);
  __cxa_atexit(CAreaDef::~CAreaDef,&g_DefaultArea,&__dso_handle);
  return;
}


