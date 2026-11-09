// Ghidra decompilation of functions from tfc/areadef.cpp
// 14 functions, ordered by original source line

// info_areadef  @ 0006d500  (line 14)

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
  (pCVar1->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CAreaDef_00147354;
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


// CAreaDef::Restore  @ 0006d440  (line 21)

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


// CAreaDef::Save  @ 0006d4a0  (line 21)

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


// DBAreaClassData::DBAreaClassData  @ 0006d5e0  (line 38)

/* DWARF original prototype: void DBAreaClassData(DBAreaClassData * this) */

void __thiscall DBAreaClassData::DBAreaClassData(DBAreaClassData *this)

{
  this->m_DB_PingTotal = 0;
  this->m_DB_nPingTests = 0;
  this->m_DB_TimeInArea = 0;
  return;
}


// DBAreaClassData::Clear  @ 0006d600  (line 45)

/* DWARF original prototype: void Clear(DBAreaClassData * this) */

void __thiscall DBAreaClassData::Clear(DBAreaClassData *this)

{
  this->m_DB_PingTotal = 0;
  this->m_DB_nPingTests = 0;
  this->m_DB_TimeInArea = 0;
  return;
}


// DBAreaClassData::MergeData  @ 0006d620  (line 53)

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


// CAreaDef::CAreaDef  @ 0006d650  (line 65)

/* DWARF original prototype: void CAreaDef(CAreaDef * this, bool bDefaultArea) */

void __thiscall CAreaDef::CAreaDef(CAreaDef *this,bool bDefaultArea)

{
  CAreaDef *pCVar1;
  
  (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CAreaDef_00147354;
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


// CAreaDef::~CAreaDef  @ 0006d310  (line 84)

/* DWARF original prototype: void ~CAreaDef(CAreaDef * this, int __in_chrg) */

void __thiscall CAreaDef::~CAreaDef(CAreaDef *this,int __in_chrg)

{
  CAreaDef *pCVar1;
  CAreaDef *pCVar2;
  CAreaDef **ppCVar3;
  
  (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CAreaDef_00147354;
                    /* Unresolved local var: CAreaDef * * pPrev@[???]
                       Unresolved local var: CAreaDef * pCur@[???] */
  g_nActiveAreas = g_nActiveAreas + -1;
  if (g_pActiveAreas == (CAreaDef *)0x0) {
    return;
  }
  pCVar1 = g_pActiveAreas;
  if (this == g_pActiveAreas) {
    ppCVar3 = &g_pActiveAreas;
    pCVar1 = this;
  }
  else {
    do {
      pCVar2 = pCVar1;
      pCVar1 = pCVar2->m_pNext;
      if (pCVar1 == (CAreaDef *)0x0) {
        return;
      }
    } while (this != pCVar1);
    ppCVar3 = &pCVar2->m_pNext;
  }
  *ppCVar3 = pCVar1->m_pNext;
  return;
}


// CAreaDef::~CAreaDef  @ 0006d360  (line 84)

/* DWARF original prototype: void ~CAreaDef(CAreaDef * this, int __in_chrg) */

void __thiscall CAreaDef::~CAreaDef(CAreaDef *this,int __in_chrg)

{
  CAreaDef *pCVar1;
  CAreaDef *pCVar2;
  CAreaDef **ppCVar3;
  
  (this->super_CBaseEntity)._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CAreaDef_00147354;
                    /* Unresolved local var: CAreaDef * * pPrev@[???]
                       Unresolved local var: CAreaDef * pCur@[???] */
  g_nActiveAreas = g_nActiveAreas + -1;
  if (g_pActiveAreas == (CAreaDef *)0x0) {
    return;
  }
  pCVar1 = g_pActiveAreas;
  if (this == g_pActiveAreas) {
    ppCVar3 = &g_pActiveAreas;
    pCVar1 = this;
  }
  else {
    do {
      pCVar2 = pCVar1;
      pCVar1 = pCVar2->m_pNext;
      if (pCVar1 == (CAreaDef *)0x0) {
        return;
      }
    } while (this != pCVar1);
    ppCVar3 = &pCVar2->m_pNext;
  }
  *ppCVar3 = pCVar1->m_pNext;
  return;
}


// CAreaDef::KeyValue  @ 0006d3b0  (line 106)

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


// CAreaDef::GetClassData  @ 0006d700  (line 121)

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


// CAreaDef::MergeData  @ 0006d910  (line 133)

/* DWARF original prototype: void MergeData(CAreaDef * this, CAreaDef * pSource) */

void __thiscall CAreaDef::MergeData(CAreaDef *this,CAreaDef *pSource)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  
  if ((this->m_ClassData < pSource->m_ClassData + 4) &&
     (pSource->m_ClassData < this->m_ClassData + 4)) {
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
    iVar2 = pSource->m_ClassData[2].m_DB_PingTotal;
    pSource->m_ClassData[1].m_DB_TimeInArea = 0;
    this->m_ClassData[2].m_DB_PingTotal = this->m_ClassData[2].m_DB_PingTotal + iVar2;
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
    iVar2 = pSource->m_ClassData[4].m_DB_PingTotal;
    pSource->m_ClassData[3].m_DB_TimeInArea = 0;
    this->m_ClassData[4].m_DB_PingTotal = this->m_ClassData[4].m_DB_PingTotal + iVar2;
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
    iVar2 = pSource->m_ClassData[6].m_DB_PingTotal;
    pSource->m_ClassData[5].m_DB_TimeInArea = 0;
    this->m_ClassData[6].m_DB_PingTotal = this->m_ClassData[6].m_DB_PingTotal + iVar2;
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
    iVar2 = pSource->m_ClassData[8].m_DB_PingTotal;
    pSource->m_ClassData[7].m_DB_TimeInArea = 0;
    this->m_ClassData[8].m_DB_PingTotal = this->m_ClassData[8].m_DB_PingTotal + iVar2;
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
    iVar2 = pSource->m_ClassData[10].m_DB_PingTotal;
    pSource->m_ClassData[9].m_DB_TimeInArea = 0;
    this->m_ClassData[10].m_DB_PingTotal = this->m_ClassData[10].m_DB_PingTotal + iVar2;
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
                    /* Unresolved local var: int i@[???] */
  iVar2 = pSource->m_ClassData[2].m_DB_TimeInArea;
  iVar3 = pSource->m_ClassData[3].m_DB_PingTotal;
  iVar4 = pSource->m_ClassData[3].m_DB_nPingTests;
  iVar5 = pSource->m_ClassData[3].m_DB_TimeInArea;
  iVar6 = pSource->m_ClassData[0].m_DB_PingTotal;
  iVar7 = pSource->m_ClassData[0].m_DB_nPingTests;
  iVar8 = pSource->m_ClassData[0].m_DB_TimeInArea;
  iVar9 = pSource->m_ClassData[1].m_DB_PingTotal;
  iVar10 = pSource->m_ClassData[1].m_DB_TimeInArea;
  iVar11 = pSource->m_ClassData[2].m_DB_PingTotal;
  iVar12 = pSource->m_ClassData[2].m_DB_nPingTests;
  iVar13 = this->m_ClassData[1].m_DB_TimeInArea;
  iVar14 = this->m_ClassData[2].m_DB_PingTotal;
  iVar15 = this->m_ClassData[2].m_DB_nPingTests;
  iVar16 = this->m_ClassData[2].m_DB_TimeInArea;
  iVar17 = this->m_ClassData[3].m_DB_PingTotal;
  iVar18 = this->m_ClassData[3].m_DB_nPingTests;
  iVar19 = this->m_ClassData[3].m_DB_TimeInArea;
  iVar20 = this->m_ClassData[0].m_DB_PingTotal;
  iVar21 = this->m_ClassData[0].m_DB_nPingTests;
  iVar22 = this->m_ClassData[0].m_DB_TimeInArea;
  iVar23 = this->m_ClassData[1].m_DB_PingTotal;
  this->m_ClassData[1].m_DB_nPingTests =
       pSource->m_ClassData[1].m_DB_nPingTests + this->m_ClassData[1].m_DB_nPingTests;
  this->m_ClassData[1].m_DB_TimeInArea = iVar10 + iVar13;
  this->m_ClassData[2].m_DB_PingTotal = iVar11 + iVar14;
  this->m_ClassData[2].m_DB_nPingTests = iVar12 + iVar15;
  this->m_ClassData[2].m_DB_TimeInArea = iVar16 + iVar2;
  this->m_ClassData[3].m_DB_PingTotal = iVar17 + iVar3;
  this->m_ClassData[3].m_DB_nPingTests = iVar18 + iVar4;
  this->m_ClassData[3].m_DB_TimeInArea = iVar19 + iVar5;
  this->m_ClassData[0].m_DB_PingTotal = iVar20 + iVar6;
  this->m_ClassData[0].m_DB_nPingTests = iVar21 + iVar7;
  this->m_ClassData[0].m_DB_TimeInArea = iVar22 + iVar8;
  this->m_ClassData[1].m_DB_PingTotal = iVar23 + iVar9;
  iVar2 = pSource->m_ClassData[6].m_DB_TimeInArea;
  iVar3 = pSource->m_ClassData[7].m_DB_PingTotal;
  iVar4 = pSource->m_ClassData[7].m_DB_nPingTests;
  iVar5 = pSource->m_ClassData[7].m_DB_TimeInArea;
  pSource->m_ClassData[0].m_DB_PingTotal = 0;
  pSource->m_ClassData[0].m_DB_nPingTests = 0;
  pSource->m_ClassData[0].m_DB_TimeInArea = 0;
  pSource->m_ClassData[1].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&pSource->m_ClassData[1].m_DB_nPingTests = (undefined1  [16])0x0;
  *(undefined1 (*) [16])&pSource->m_ClassData[2].m_DB_TimeInArea = (undefined1  [16])0x0;
  iVar6 = pSource->m_ClassData[4].m_DB_PingTotal;
  iVar7 = pSource->m_ClassData[4].m_DB_nPingTests;
  iVar8 = pSource->m_ClassData[4].m_DB_TimeInArea;
  iVar9 = pSource->m_ClassData[5].m_DB_PingTotal;
  iVar10 = pSource->m_ClassData[5].m_DB_nPingTests;
  iVar11 = pSource->m_ClassData[5].m_DB_TimeInArea;
  iVar12 = pSource->m_ClassData[6].m_DB_PingTotal;
  iVar13 = pSource->m_ClassData[6].m_DB_nPingTests;
  iVar14 = this->m_ClassData[5].m_DB_nPingTests;
  iVar15 = this->m_ClassData[5].m_DB_TimeInArea;
  iVar16 = this->m_ClassData[6].m_DB_PingTotal;
  iVar17 = this->m_ClassData[6].m_DB_nPingTests;
  iVar18 = this->m_ClassData[7].m_DB_PingTotal;
  iVar19 = this->m_ClassData[7].m_DB_nPingTests;
  iVar20 = this->m_ClassData[7].m_DB_TimeInArea;
  iVar21 = this->m_ClassData[4].m_DB_PingTotal;
  iVar22 = this->m_ClassData[4].m_DB_nPingTests;
  iVar23 = this->m_ClassData[4].m_DB_TimeInArea;
  iVar24 = this->m_ClassData[5].m_DB_PingTotal;
  this->m_ClassData[6].m_DB_TimeInArea = this->m_ClassData[6].m_DB_TimeInArea + iVar2;
  this->m_ClassData[7].m_DB_PingTotal = iVar18 + iVar3;
  this->m_ClassData[7].m_DB_nPingTests = iVar19 + iVar4;
  this->m_ClassData[7].m_DB_TimeInArea = iVar20 + iVar5;
  this->m_ClassData[5].m_DB_nPingTests = iVar10 + iVar14;
  this->m_ClassData[5].m_DB_TimeInArea = iVar11 + iVar15;
  this->m_ClassData[6].m_DB_PingTotal = iVar12 + iVar16;
  this->m_ClassData[6].m_DB_nPingTests = iVar13 + iVar17;
  this->m_ClassData[4].m_DB_PingTotal = iVar21 + iVar6;
  this->m_ClassData[4].m_DB_nPingTests = iVar22 + iVar7;
  this->m_ClassData[4].m_DB_TimeInArea = iVar23 + iVar8;
  this->m_ClassData[5].m_DB_PingTotal = iVar24 + iVar9;
  pSource->m_ClassData[4].m_DB_PingTotal = 0;
  pSource->m_ClassData[4].m_DB_nPingTests = 0;
  pSource->m_ClassData[4].m_DB_TimeInArea = 0;
  pSource->m_ClassData[5].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&pSource->m_ClassData[5].m_DB_nPingTests = (undefined1  [16])0x0;
  *(undefined1 (*) [16])&pSource->m_ClassData[6].m_DB_TimeInArea = (undefined1  [16])0x0;
  iVar2 = pSource->m_ClassData[10].m_DB_TimeInArea;
  iVar3 = pSource->m_ClassData[0xb].m_DB_PingTotal;
  iVar4 = pSource->m_ClassData[0xb].m_DB_nPingTests;
  iVar5 = pSource->m_ClassData[0xb].m_DB_TimeInArea;
  iVar6 = this->m_ClassData[9].m_DB_TimeInArea;
  iVar7 = this->m_ClassData[10].m_DB_PingTotal;
  iVar8 = this->m_ClassData[10].m_DB_nPingTests;
  iVar9 = pSource->m_ClassData[9].m_DB_TimeInArea;
  iVar10 = pSource->m_ClassData[10].m_DB_PingTotal;
  iVar11 = pSource->m_ClassData[10].m_DB_nPingTests;
  iVar12 = pSource->m_ClassData[8].m_DB_PingTotal;
  iVar13 = pSource->m_ClassData[8].m_DB_nPingTests;
  iVar14 = pSource->m_ClassData[8].m_DB_TimeInArea;
  iVar15 = pSource->m_ClassData[9].m_DB_PingTotal;
  iVar16 = this->m_ClassData[10].m_DB_TimeInArea;
  iVar17 = this->m_ClassData[0xb].m_DB_PingTotal;
  iVar18 = this->m_ClassData[0xb].m_DB_nPingTests;
  iVar19 = this->m_ClassData[0xb].m_DB_TimeInArea;
  iVar20 = this->m_ClassData[8].m_DB_PingTotal;
  iVar21 = this->m_ClassData[8].m_DB_nPingTests;
  iVar22 = this->m_ClassData[8].m_DB_TimeInArea;
  iVar23 = this->m_ClassData[9].m_DB_PingTotal;
  this->m_ClassData[9].m_DB_nPingTests =
       pSource->m_ClassData[9].m_DB_nPingTests + this->m_ClassData[9].m_DB_nPingTests;
  this->m_ClassData[9].m_DB_TimeInArea = iVar9 + iVar6;
  this->m_ClassData[10].m_DB_PingTotal = iVar10 + iVar7;
  this->m_ClassData[10].m_DB_nPingTests = iVar11 + iVar8;
  this->m_ClassData[8].m_DB_PingTotal = iVar20 + iVar12;
  this->m_ClassData[8].m_DB_nPingTests = iVar21 + iVar13;
  this->m_ClassData[8].m_DB_TimeInArea = iVar22 + iVar14;
  this->m_ClassData[9].m_DB_PingTotal = iVar23 + iVar15;
  this->m_ClassData[10].m_DB_TimeInArea = iVar16 + iVar2;
  this->m_ClassData[0xb].m_DB_PingTotal = iVar17 + iVar3;
  this->m_ClassData[0xb].m_DB_nPingTests = iVar18 + iVar4;
  this->m_ClassData[0xb].m_DB_TimeInArea = iVar19 + iVar5;
  pSource->m_ClassData[8].m_DB_PingTotal = 0;
  pSource->m_ClassData[8].m_DB_nPingTests = 0;
  pSource->m_ClassData[8].m_DB_TimeInArea = 0;
  pSource->m_ClassData[9].m_DB_PingTotal = 0;
  *(undefined1 (*) [16])&pSource->m_ClassData[9].m_DB_nPingTests = (undefined1  [16])0x0;
  *(undefined1 (*) [16])&pSource->m_ClassData[10].m_DB_TimeInArea = (undefined1  [16])0x0;
  return;
}


// CAreaDef::ClearClassData  @ 0006dd70  (line 140)

/* DWARF original prototype: void ClearClassData(CAreaDef * this) */

void __thiscall CAreaDef::ClearClassData(CAreaDef *this)

{
                    /* Unresolved local var: int i@[???] */
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


// _GLOBAL__sub_I_info_areadef  @ 0006c320  (line 143)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_info_areadef(void)

{
  CAreaDef::CAreaDef(&g_DefaultArea,true);
  __cxa_atexit(CAreaDef::~CAreaDef,&g_DefaultArea,&__dso_handle);
  return;
}


