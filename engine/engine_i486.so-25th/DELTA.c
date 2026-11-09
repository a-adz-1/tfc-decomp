// DELTA_AddDefinition  @ 00049a60
void DELTA_AddDefinition(char *name,delta_definition_t *pdef,int numelements)

{
  delta_definition_list_s *pdVar1;
  delta_definition_list_t *pdVar2;
  int iVar3;
  delta_definition_list_t *pdVar4;
  char *pcVar5;
  
  pdVar1 = g_defs;
  while( true ) {
    if (pdVar1 == (delta_definition_list_t *)0x0) {
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
      pdVar4 = Mem_ZeroMalloc(0x10);
      pdVar2 = pdVar4;
      pdVar4->next = g_defs;
      g_defs = pdVar2;
      pcVar5 = Mem_Strdup(name);
      pdVar4->ptypename = pcVar5;
      pdVar4->pdefinition = pdef;
      pdVar4->numelements = numelements;
      return;
    }
    iVar3 = Q_stricmp(name,pdVar1->ptypename);
    if (iVar3 == 0) break;
    pdVar1 = pdVar1->next;
  }
  pdVar1->pdefinition = pdef;
  pdVar1->numelements = numelements;
  return;
}


// DELTA_AddEncoder  @ 00049260
void DELTA_AddEncoder(char *name,_func_void_delta_s_ptr_uchar_ptr_uchar_ptr *conditionalencode)

{
  delta_encoder_t *pdVar1;
  char *pcVar2;
  
                    /* Unresolved local var: delta_encoder_t * p@[???] */
  pdVar1 = Mem_ZeroMalloc(0xc);
  pcVar2 = Mem_Strdup(name);
  pdVar1->name = pcVar2;
  pdVar1->conditionalencode = conditionalencode;
  pdVar1->next = g_encoders;
  g_encoders = pdVar1;
  return;
}


// DELTA_BuildFromLinks  @ 000493a0
delta_t * DELTA_BuildFromLinks(delta_link_t **pplinks)

{
  delta_t *pdVar1;
  delta_link_s *pdVar2;
  delta_description_s *pdVar3;
  size_t size;
  delta_link_t *pdVar4;
  int iVar5;
  delta_link_s *pdVar6;
  delta_description_s *dest;
  
                    /* Unresolved local var: delta_description_t * pdesc@[???]
                       Unresolved local var: delta_description_t * pcur@[???]
                       Unresolved local var: delta_t * pdelta@[???]
                       Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int i@[???] */
  pdVar1 = Mem_ZeroMalloc(0x30);
                    /* Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: delta_link_t * n@[???]
                       Unresolved local var: delta_link_t * newlist@[???] */
  if (*pplinks == (delta_link_t *)0x0) {
    size = 0;
    iVar5 = 0;
  }
  else {
    pdVar6 = *pplinks;
    pdVar4 = (delta_link_t *)0x0;
    do {
      pdVar2 = pdVar6;
      pdVar6 = pdVar2->next;
      pdVar2->next = pdVar4;
      pdVar4 = pdVar2;
    } while (pdVar6 != (delta_link_s *)0x0);
    *pplinks = pdVar2;
    iVar5 = 0;
    do {
                    /* Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: int c@[???] */
      pdVar2 = pdVar2->next;
      iVar5 = iVar5 + 1;
    } while (pdVar2 != (delta_link_s *)0x0);
    size = iVar5 * 0x44;
  }
  pdVar3 = Mem_ZeroMalloc(size);
  pdVar6 = *pplinks;
  dest = pdVar3;
  if (pdVar6 != (delta_link_t *)0x0) {
    do {
      Q_memcpy(dest,pdVar6->delta,0x44);
      Mem_Free(pdVar6->delta);
      pdVar6->delta = (delta_description_t *)0x0;
      pdVar6 = pdVar6->next;
      dest = dest + 1;
    } while (pdVar6 != (delta_link_s *)0x0);
                    /* Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: delta_link_t * n@[???] */
    pdVar4 = *pplinks;
    while (pdVar4 != (delta_link_t *)0x0) {
      pdVar6 = pdVar4->next;
      Mem_Free(pdVar4);
      pdVar4 = pdVar6;
    }
  }
  *pplinks = (delta_link_t *)0x0;
  pdVar1->dynamic = 1;
  pdVar1->fieldCount = iVar5;
  pdVar1->pdd = pdVar3;
  return pdVar1;
}


// DELTA_CheckDelta  @ 00048640
int DELTA_CheckDelta(uchar *from,uchar *to,delta_t *pFields)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int sendfields@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  if (0 < pFields->fieldCount) {
    iVar4 = 0;
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      pcVar1 = pFields->pdd->fieldName + iVar4 + 0x34;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      iVar4 = iVar4 + 0x44;
    } while (iVar2 < pFields->fieldCount);
  }
  DELTA_MarkSendFields(from,to,pFields);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  iVar2 = pFields->fieldCount;
  iVar4 = 0;
  if (0 < iVar2) {
    iVar3 = 0;
    iVar4 = 0;
    iVar5 = 0;
    do {
      if ((pFields->pdd->fieldName[iVar3 + 0x34] & 1U) != 0) {
        pcVar1 = pFields->pdd->fieldName + iVar3 + 0x38;
        *(int *)pcVar1 = *(int *)pcVar1 + 1;
        iVar4 = iVar4 + 1;
        iVar2 = pFields->fieldCount;
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x44;
    } while (iVar5 < iVar2);
  }
  return iVar4;
}


// DELTA_ClearDefinitions  @ 00049af0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DELTA_ClearDefinitions(void)

{
  delta_definition_list_s *pdVar1;
  delta_definition_list_t *p;
  
  p = g_defs;
  while (p != (delta_definition_list_t *)0x0) {
    pdVar1 = p->next;
    Mem_Free(p->ptypename);
    Mem_Free(p);
    p = pdVar1;
  }
  g_defs = (delta_definition_list_t *)0x0;
  return;
}


// DELTA_ClearEncoders  @ 000492a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DELTA_ClearEncoders(void)

{
  delta_encoder_s *pdVar1;
  delta_encoder_t *p;
  
  p = g_encoders;
  while (p != (delta_encoder_t *)0x0) {
    pdVar1 = p->next;
    Mem_Free(p->name);
    Mem_Free(p);
    p = pdVar1;
  }
  g_encoders = (delta_encoder_t *)0x0;
  return;
}


// DELTA_ClearFlags  @ 00047ce0
void DELTA_ClearFlags(delta_t *pFields)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  if (0 < pFields->fieldCount) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      pcVar1 = pFields->pdd->fieldName + iVar3 + 0x34;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      iVar3 = iVar3 + 0x44;
    } while (iVar2 < pFields->fieldCount);
  }
  return;
}


// DELTA_ClearLinks  @ 00049370
void DELTA_ClearLinks(delta_link_t **plinks)

{
  delta_link_s *pdVar1;
  delta_link_t *p;
  
                    /* Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: delta_link_t * n@[???] */
  p = *plinks;
  while (p != (delta_link_t *)0x0) {
    pdVar1 = p->next;
    Mem_Free(p);
    p = pdVar1;
  }
  *plinks = (delta_link_t *)0x0;
  return;
}


// DELTA_ClearRegistrations  @ 0004a290
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DELTA_ClearRegistrations(void)

{
  delta_registry_s *pdVar1;
  delta_registry_t *p;
  delta_t *p_00;
  
  p = g_deltaregistry;
  while (p != (delta_registry_t *)0x0) {
    pdVar1 = p->next;
    Mem_Free(p->name);
    p_00 = p->pdesc;
    if (p_00 != (delta_t *)0x0) {
      if (p_00->dynamic != 0) {
        Mem_Free(p_00->pdd);
        p_00 = p->pdesc;
      }
      Mem_Free(p_00);
      p->pdesc = (delta_t *)0x0;
    }
    Mem_Free(p);
    p = pdVar1;
  }
  g_deltaregistry = (delta_registry_t *)0x0;
  return;
}


// DELTA_ClearStats  @ 0004a350
void DELTA_ClearStats(delta_t *p)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if ((p != (delta_t *)0x0) && (0 < p->fieldCount)) {
    iVar2 = 0;
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      pcVar1 = p->pdd->fieldName + iVar2 + 0x38;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      pcVar1 = p->pdd->fieldName + iVar2 + 0x3c;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      iVar2 = iVar2 + 0x44;
    } while (iVar3 < p->fieldCount);
  }
  return;
}


// DELTA_ClearStats_f  @ 000479b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DELTA_ClearStats_f(void)

{
  char *pcVar1;
  delta_t *pdVar2;
  delta_registry_s *pdVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: delta_registry_t * p@[???] */
  Con_Printf("Clearing delta stats\n");
  for (pdVar3 = g_deltaregistry; pdVar3 != (delta_registry_t *)0x0; pdVar3 = pdVar3->next) {
    pdVar2 = pdVar3->pdesc;
                    /* Unresolved local var: int i@[???] */
    if ((pdVar2 != (delta_t *)0x0) && (0 < pdVar2->fieldCount)) {
      iVar4 = 0;
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 1;
        pcVar1 = pdVar2->pdd->fieldName + iVar4 + 0x38;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        pcVar1 = pdVar2->pdd->fieldName + iVar4 + 0x3c;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        iVar4 = iVar4 + 0x44;
      } while (iVar5 < pdVar2->fieldCount);
    }
  }
  return;
}


// DELTA_CountLinks  @ 00049330
int DELTA_CountLinks(delta_link_t *plinks)

{
  int iVar1;
  
                    /* Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: int c@[???] */
  iVar1 = 0;
  if (plinks == (delta_link_t *)0x0) {
    return iVar1;
  }
  do {
    plinks = plinks->next;
    iVar1 = iVar1 + 1;
  } while (plinks != (delta_link_s *)0x0);
  return iVar1;
}


// DELTA_CountSendFields  @ 00047f90
int DELTA_CountSendFields(delta_t *pFields)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  iVar5 = pFields->fieldCount;
  if (iVar5 < 1) {
    iVar2 = 0;
  }
  else {
    iVar3 = 0;
    iVar2 = 0;
    iVar4 = 0;
    do {
      if ((pFields->pdd->fieldName[iVar3 + 0x34] & 1U) != 0) {
        pcVar1 = pFields->pdd->fieldName + iVar3 + 0x38;
        *(int *)pcVar1 = *(int *)pcVar1 + 1;
        iVar2 = iVar2 + 1;
        iVar5 = pFields->fieldCount;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x44;
    } while (iVar4 < iVar5);
  }
  return iVar2;
}


// DELTA_DumpStats_f  @ 00047a20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DELTA_DumpStats_f(void)

{
  delta_t *pdVar1;
  delta_description_s *pdVar2;
  delta_registry_s *pdVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  
                    /* Unresolved local var: delta_registry_t * p@[???] */
  Con_Printf("Delta Stats\n");
  for (pdVar3 = g_deltaregistry; pdVar3 != (delta_registry_t *)0x0; pdVar3 = pdVar3->next) {
    pdVar1 = pdVar3->pdesc;
                    /* Unresolved local var: int i@[???] */
    if (pdVar1 != (delta_t *)0x0) {
      pcVar6 = pdVar3->name;
                    /* Unresolved local var: int i@[???] */
      pcVar4 = (char *)0x0;
      Con_Printf("Stats for \'%s\'\n",pcVar6);
      if (0 < pdVar1->fieldCount) {
        iVar5 = 0;
        do {
          pdVar2 = pdVar1->pdd;
          pcVar4 = pcVar4 + 1;
          pcVar6 = pcVar4;
          Con_Printf("  %02i % 10s:  s % 5i r % 5i\n",pcVar4,pdVar2->fieldName + iVar5,
                     *(undefined4 *)(pdVar2->fieldName + iVar5 + 0x38),
                     *(undefined4 *)(pdVar2->fieldName + iVar5 + 0x3c));
          iVar5 = iVar5 + 0x44;
        } while ((int)pcVar4 < pdVar1->fieldCount);
      }
      Con_Printf("\n",pcVar6);
    }
  }
  return;
}


// DELTA_FindDefinition  @ 00049b30
delta_definition_t * DELTA_FindDefinition(char *name,int *count)

{
  delta_definition_list_s *pdVar1;
  int iVar2;
  
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar1 = g_defs;
  *count = 0;
  while( true ) {
    if (pdVar1 == (delta_definition_list_t *)0x0) {
      return (delta_definition_t *)0x0;
    }
    iVar2 = Q_stricmp(name,pdVar1->ptypename);
    if (iVar2 == 0) break;
    pdVar1 = pdVar1->next;
  }
  *count = pdVar1->numelements;
  return pdVar1->pdefinition;
}


// DELTA_FindField  @ 00047ac0
delta_description_t * DELTA_FindField(delta_t *pFields,char *pszField)

{
  int iVar1;
  int iVar2;
  int iVar3;
  delta_description_t *pdVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  iVar3 = 0;
  iVar2 = 0;
  if (0 < pFields->fieldCount) {
    do {
      pdVar4 = (delta_description_t *)(pFields->pdd->fieldName + iVar2 + -4);
      iVar1 = Q_strcasecmp(pdVar4->fieldName,pszField);
      if (iVar1 == 0) {
        return pdVar4;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x44;
    } while (iVar3 < pFields->fieldCount);
  }
  Con_Printf("DELTA_FindField:  Warning, couldn\'t find %s\n",pszField);
  return (delta_description_t *)0x0;
}


// DELTA_FindFieldIndex  @ 00047b30
int DELTA_FindFieldIndex(delta_s *pFields,char *fieldname)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  iVar3 = 0;
  iVar2 = 0;
  if (0 < pFields->fieldCount) {
    do {
      iVar1 = Q_strcasecmp(pFields->pdd->fieldName + iVar3,fieldname);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x44;
    } while (iVar2 < pFields->fieldCount);
  }
  Con_Printf("DELTA_FindFieldIndex:  Warning, couldn\'t find %s\n",fieldname);
  return -1;
}


// DELTA_FindOffset  @ 000494a0
int DELTA_FindOffset(int count,delta_definition_t *pdef,char *fieldname)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  if (0 < count) {
    do {
      iVar1 = Q_stricmp(fieldname,pdef->fieldName);
      if (iVar1 == 0) {
        return pdef->fieldOffset;
      }
      iVar2 = iVar2 + 1;
      pdef = pdef + 1;
    } while (count != iVar2);
  }
  Sys_Error("Couldn\'t find offset for %s!!!\n",fieldname);
  return 0;
}


// DELTA_FreeDescription  @ 00049a20
void DELTA_FreeDescription(delta_t **ppdesc)

{
  delta_t *p;
  
  if ((ppdesc != (delta_t **)0x0) && (p = *ppdesc, p != (delta_t *)0x0)) {
    if (p->dynamic != 0) {
      Mem_Free(p->pdd);
      p = *ppdesc;
    }
    Mem_Free(p);
    *ppdesc = (delta_t *)0x0;
  }
  return;
}


// DELTA_Init  @ 0004a430
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DELTA_Init(void)

{
  delta_definition_list_s *pdVar1;
  delta_definition_list_t *pdVar2;
  delta_definition_list_t *pdVar3;
  char *pcVar4;
  int iVar5;
  
  Cmd_AddCommand("delta_stats",DELTA_DumpStats_f);
  Cmd_AddCommand("delta_clear",DELTA_ClearStats_f);
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  for (pdVar1 = g_defs; pdVar1 != (delta_definition_list_t *)0x0; pdVar1 = pdVar1->next) {
    iVar5 = Q_stricmp("clientdata_t",pdVar1->ptypename);
    if (iVar5 == 0) {
      pdVar1->pdefinition = g_ClientDataDefinition;
      pdVar1->numelements = 0x38;
      pdVar2 = g_defs;
      goto joined_r0x0004a4e0;
    }
  }
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar2 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar2;
  pcVar4 = Mem_Strdup("clientdata_t");
  pdVar3->pdefinition = g_ClientDataDefinition;
  pdVar3->numelements = 0x38;
  pdVar3->ptypename = pcVar4;
  pdVar2 = g_defs;
joined_r0x0004a4e0:
  do {
    if (pdVar2 == (delta_definition_list_t *)0x0) break;
    iVar5 = Q_stricmp("weapon_data_t",pdVar2->ptypename);
    if (iVar5 == 0) {
      pdVar2->pdefinition = g_WeaponDataDefinition;
      pdVar2->numelements = 0x16;
      pdVar2 = g_defs;
      goto joined_r0x0004a558;
    }
    pdVar2 = pdVar2->next;
  } while( true );
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar2 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar2;
  pcVar4 = Mem_Strdup("weapon_data_t");
  pdVar3->pdefinition = g_WeaponDataDefinition;
  pdVar3->numelements = 0x16;
  pdVar3->ptypename = pcVar4;
  pdVar2 = g_defs;
joined_r0x0004a558:
  do {
    if (pdVar2 == (delta_definition_list_t *)0x0) break;
    iVar5 = Q_stricmp("usercmd_t",pdVar2->ptypename);
    if (iVar5 == 0) {
      pdVar2->pdefinition = g_UsercmdDataDefinition;
      pdVar2->numelements = 0x10;
      pdVar2 = g_defs;
      goto joined_r0x0004a5d0;
    }
    pdVar2 = pdVar2->next;
  } while( true );
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar2 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar2;
  pcVar4 = Mem_Strdup("usercmd_t");
  pdVar3->pdefinition = g_UsercmdDataDefinition;
  pdVar3->numelements = 0x10;
  pdVar3->ptypename = pcVar4;
  pdVar2 = g_defs;
joined_r0x0004a5d0:
  do {
    if (pdVar2 == (delta_definition_list_t *)0x0) break;
    iVar5 = Q_stricmp("entity_state_t",pdVar2->ptypename);
    if (iVar5 == 0) {
      pdVar2->pdefinition = g_EntityDataDefinition;
      pdVar2->numelements = 0x57;
      pdVar2 = g_defs;
      goto joined_r0x0004a648;
    }
    pdVar2 = pdVar2->next;
  } while( true );
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar2 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar2;
  pcVar4 = Mem_Strdup("entity_state_t");
  pdVar3->pdefinition = g_EntityDataDefinition;
  pdVar3->numelements = 0x57;
  pdVar3->ptypename = pcVar4;
  pdVar2 = g_defs;
joined_r0x0004a648:
  do {
    if (pdVar2 == (delta_definition_list_t *)0x0) break;
    iVar5 = Q_stricmp("entity_state_player_t",pdVar2->ptypename);
    if (iVar5 == 0) {
      pdVar2->pdefinition = g_EntityDataDefinition;
      pdVar2->numelements = 0x57;
      pdVar2 = g_defs;
      goto joined_r0x0004a6c0;
    }
    pdVar2 = pdVar2->next;
  } while( true );
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar2 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar2;
  pcVar4 = Mem_Strdup("entity_state_player_t");
  pdVar3->pdefinition = g_EntityDataDefinition;
  pdVar3->numelements = 0x57;
  pdVar3->ptypename = pcVar4;
  pdVar2 = g_defs;
joined_r0x0004a6c0:
  do {
    if (pdVar2 == (delta_definition_list_t *)0x0) {
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
      pdVar3 = Mem_ZeroMalloc(0x10);
      pdVar2 = pdVar3;
      pdVar3->next = g_defs;
      g_defs = pdVar2;
      pcVar4 = Mem_Strdup("custom_entity_state_t");
      pdVar3->pdefinition = g_EntityDataDefinition;
      pdVar3->numelements = 0x57;
      pdVar3->ptypename = pcVar4;
      pdVar2 = g_defs;
joined_r0x0004a738:
      while( true ) {
        if (pdVar2 == (delta_definition_list_t *)0x0) {
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
          pdVar3 = Mem_ZeroMalloc(0x10);
          pdVar2 = pdVar3;
          pdVar3->next = g_defs;
          g_defs = pdVar2;
          pcVar4 = Mem_Strdup("event_t");
          pdVar3->pdefinition = g_EventDataDefinition;
          pdVar3->numelements = 0xe;
          pdVar3->ptypename = pcVar4;
          return;
        }
        iVar5 = Q_stricmp("event_t",pdVar2->ptypename);
        if (iVar5 == 0) break;
        pdVar2 = pdVar2->next;
      }
      pdVar2->pdefinition = g_EventDataDefinition;
      pdVar2->numelements = 0xe;
      return;
    }
    iVar5 = Q_stricmp("custom_entity_state_t",pdVar2->ptypename);
    if (iVar5 == 0) {
      pdVar2->pdefinition = g_EntityDataDefinition;
      pdVar2->numelements = 0x57;
      pdVar2 = g_defs;
      goto joined_r0x0004a738;
    }
    pdVar2 = pdVar2->next;
  } while( true );
}


// DELTA_Load  @ 0004a1d0
qboolean DELTA_Load(char *name,delta_t **ppdesc,char *pszFile)

{
  byte *pstream;
  qboolean qVar1;
  
                    /* Unresolved local var: char * pbuf@[???]
                       Unresolved local var: qboolean bret@[???] */
  pstream = COM_LoadFile(pszFile,5,(int *)0x0);
  if (pstream != (byte *)0x0) {
    qVar1 = DELTA_ParseDescription(name,ppdesc,(char *)pstream);
    Mem_Free(pstream);
    return qVar1;
  }
  Sys_Error("DELTA_Load:  Couldn\'t load file %s\n",pszFile);
  return false;
}


// DELTA_LookupEncoder  @ 000492e0
encoder_t DELTA_LookupEncoder(char *name)

{
  delta_encoder_s *pdVar1;
  int iVar2;
  
  pdVar1 = g_encoders;
  while( true ) {
    if (pdVar1 == (delta_encoder_t *)0x0) {
      return (encoder_t)0x0;
    }
    iVar2 = Q_stricmp(pdVar1->name,name);
    if (iVar2 == 0) break;
    pdVar1 = pdVar1->next;
  }
  return pdVar1->conditionalencode;
}


// DELTA_LookupRegistration  @ 0004a300
delta_t ** DELTA_LookupRegistration(char *name)

{
  delta_registry_s *pdVar1;
  int iVar2;
  
  pdVar1 = g_deltaregistry;
  while( true ) {
    if (pdVar1 == (delta_registry_t *)0x0) {
      return (delta_t **)0x0;
    }
    iVar2 = Q_stricmp(pdVar1->name,name);
    if (iVar2 == 0) break;
    pdVar1 = pdVar1->next;
  }
  return &pdVar1->pdesc;
}


// DELTA_MarkSendFields  @ 00047fe0
void DELTA_MarkSendFields(uchar *from,uchar *to,delta_t *pFields)

{
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  float fVar4;
  uint uVar5;
  __int32_t **pp_Var6;
  int iVar7;
  uchar *puVar8;
  int iVar9;
  delta_description_s *pdVar10;
  uchar *puVar11;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float f1@[???]
                       Unresolved local var: float f2@[???]
                       Unresolved local var: char * st1@[???]
                       Unresolved local var: char * st2@[???]
                       Unresolved local var: delta_description_t * pTest@[???]
                       Unresolved local var: int fieldType@[???]
                       Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int done@[???] */
  iVar9 = 0;
  iVar3 = pFields->fieldCount;
  if (0 < iVar3) {
    do {
      pdVar10 = pFields->pdd + iVar9;
      uVar5 = pdVar10->fieldType & 0x7fffffff;
      if (uVar5 == 8) {
LAB_000481c0:
        if (*(int *)(from + pdVar10->fieldOffset) != *(int *)(to + pdVar10->fieldOffset)) {
LAB_000480c0:
          pdVar10->flags = (ushort)*(undefined4 *)&pdVar10->flags | 1;
        }
      }
      else if (uVar5 < 9) {
        if (uVar5 == 2) {
          if (*(short *)(to + pdVar10->fieldOffset) != *(short *)(from + pdVar10->fieldOffset))
          goto LAB_000480c0;
        }
        else {
          if (uVar5 == 4) goto LAB_000481c0;
          if (uVar5 != 1) goto LAB_00048141;
          if (from[pdVar10->fieldOffset] != to[pdVar10->fieldOffset]) goto LAB_000480c0;
        }
      }
      else if (uVar5 == 0x20) {
        iVar7 = pdVar10->fieldOffset;
        fVar4 = 100.0;
LAB_00048189:
        if ((int)(fVar4 * *(float *)(from + iVar7)) != (int)(fVar4 * *(float *)(to + iVar7)))
        goto LAB_000480c0;
      }
      else {
        if (uVar5 < 0x21) {
          if (uVar5 == 0x10) goto LAB_000481c0;
        }
        else {
          if (uVar5 == 0x40) {
            iVar7 = pdVar10->fieldOffset;
            fVar4 = 1000.0;
            goto LAB_00048189;
          }
          if (uVar5 == 0x80) {
            puVar8 = from + pdVar10->fieldOffset;
            uVar1 = *puVar8;
            puVar11 = to + pdVar10->fieldOffset;
            if (uVar1 == '\0') {
LAB_000481f0:
              if (*puVar11 == '\0') goto LAB_000480ca;
            }
            else {
              uVar2 = *puVar11;
              if (uVar2 != '\0') {
                pp_Var6 = __ctype_tolower_loc();
                do {
                  if ((*pp_Var6)[(char)uVar1] != (*pp_Var6)[(char)uVar2]) break;
                  puVar8 = puVar8 + 1;
                  uVar1 = *puVar8;
                  puVar11 = puVar11 + 1;
                  if (uVar1 == '\0') goto LAB_000481f0;
                  uVar2 = *puVar11;
                } while (uVar2 != '\0');
              }
            }
            goto LAB_000480c0;
          }
        }
LAB_00048141:
        Con_Printf("Bad field type %i\n",uVar5);
      }
LAB_000480ca:
      iVar9 = iVar9 + 1;
    } while (iVar3 != iVar9);
  }
  if (pFields->conditionalencode == (encoder_t)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00048103. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pFields->conditionalencode)(pFields,from,to);
  return;
}


// DELTA_ParseDelta  @ 000489a0
int DELTA_ParseDelta(uchar *from,uchar *to,delta_t *pFields,int nBufSize)

{
  int *piVar1;
  float fVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  uint32 uVar6;
  uint32 uVar7;
  int iVar8;
  int iVar9;
  uchar *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uchar *puVar14;
  int iVar15;
  uint *puVar16;
  uint *puVar17;
  delta_description_s *pdVar18;
  uint uVar19;
  float fVar20;
  uint local_34;
  uint local_24 [5];
  
                    /* Unresolved local var: delta_description_t * pTest@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int[2] bits@[???]
                       Unresolved local var: int nbytes@[???]
                       Unresolved local var: int bitfieldnumber@[???]
                       Unresolved local var: int bit@[???]
                       Unresolved local var: uchar * pdest@[???]
                       Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int fieldType@[???]
                       Unresolved local var: int fieldSign@[???]
                       Unresolved local var: uchar b2@[???]
                       Unresolved local var: char sb2@[???]
                       Unresolved local var: ushort s2@[???]
                       Unresolved local var: short ss2@[???]
                       Unresolved local var: uint si2@[???]
                       Unresolved local var: int i2@[???]
                       Unresolved local var: float f2@[???]
                       Unresolved local var: float t@[???]
                       Unresolved local var: int addt@[???]
                       Unresolved local var: char * st2@[???]
                       Unresolved local var: char * st1@[???]
                       Unresolved local var: char c@[???]
                       Unresolved local var: int startbit@[???] */
  iVar5 = MSG_CurrentBit();
  Q_memset(local_24,0,8);
  uVar6 = MSG_ReadBits(3);
  puVar16 = local_24;
  if (0 < (int)uVar6) {
    do {
      puVar17 = (uint *)((int)puVar16 + 1);
      uVar7 = MSG_ReadBits(8);
      *(char *)puVar16 = (char)uVar7;
      puVar16 = puVar17;
    } while (puVar17 != (uint *)((int)local_24 + uVar6));
  }
  iVar15 = 0;
  iVar8 = pFields->fieldCount;
  if (0 < iVar8) {
    do {
      pdVar18 = pFields->pdd + iVar15;
      iVar9 = pdVar18->fieldOffset;
      if ((iVar9 < nBufSize) && (-1 < iVar9)) {
        uVar19 = pdVar18->fieldType;
        uVar13 = uVar19 & 0x7fffffff;
        if ((local_24[0x1f < iVar15] & 1 << ((byte)iVar15 & 0x1f)) == 0) {
          if (uVar13 == 8) {
            if (iVar9 + 3 < nBufSize) {
              *(undefined4 *)(to + iVar9) = *(undefined4 *)(from + iVar9);
            }
          }
          else if (uVar13 < 9) {
            if (uVar13 == 2) {
              if (iVar9 + 1 < nBufSize) {
                *(undefined2 *)(to + iVar9) = *(undefined2 *)(from + iVar9);
              }
            }
            else {
              if (uVar13 == 4) goto LAB_00048ce1;
              if (uVar13 != 1) goto LAB_00048b6b;
              to[iVar9] = from[iVar9];
            }
          }
          else if (uVar13 == 0x20) {
LAB_00048ce1:
            if (iVar9 + 3 < nBufSize) {
              *(undefined4 *)(to + iVar9) = *(undefined4 *)(from + iVar9);
            }
          }
          else {
            if (uVar13 < 0x21) {
              if (uVar13 == 0x10) goto LAB_00048ce1;
            }
            else {
              if (uVar13 == 0x40) goto LAB_00048ce1;
              if (uVar13 == 0x80) {
                iVar12 = 0;
                iVar11 = iVar9;
                puVar10 = to + iVar9;
                while (iVar11 + iVar12 < nBufSize) {
                  iVar11 = iVar12 + iVar9;
                  iVar12 = iVar12 + 1;
                  *puVar10 = from[iVar11];
                  if (from[iVar12 + iVar9] == '\0') goto joined_r0x00049053;
                  puVar10 = puVar10 + 1;
                  iVar11 = pdVar18->fieldOffset;
                }
                if (iVar12 != 0) {
                  puVar10[-1] = '\0';
                }
                goto joined_r0x00049053;
              }
            }
LAB_00048b6b:
            Con_Printf("unparseable field type %i\n",uVar13);
          }
        }
        else {
          piVar1 = &(pdVar18->stats).receivedcount;
          *piVar1 = *piVar1 + 1;
          uVar19 = uVar19 & 0x80000000;
          if (uVar13 == 8) {
            if (iVar9 + 3 < nBufSize) {
              if (uVar19 == 0) {
                local_34 = MSG_ReadBits(pdVar18->significant_bits);
                fVar20 = pdVar18->premultiply;
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  local_34 = (uint)((float)(int)local_34 / fVar20);
                }
                fVar20 = pdVar18->postmultiply;
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  *(int *)(to + iVar9) = (int)((float)(int)local_34 * fVar20);
                  goto joined_r0x00049053;
                }
              }
              else {
                local_34 = MSG_ReadSBits(pdVar18->significant_bits);
                fVar20 = pdVar18->premultiply;
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  local_34 = (uint)(longlong)ROUND((float)local_34 / fVar20);
                }
                fVar20 = pdVar18->postmultiply;
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  local_34 = (uint)(longlong)ROUND((float)local_34 * fVar20);
                }
              }
              *(uint *)(to + iVar9) = local_34;
            }
          }
          else if (uVar13 < 9) {
            if (uVar13 == 2) {
              if (iVar9 + 1 < nBufSize) {
                if (uVar19 == 0) {
                  uVar6 = MSG_ReadBits(pdVar18->significant_bits);
                  fVar20 = pdVar18->premultiply;
                  uVar19 = uVar6 & 0xffff;
                  if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                    uVar19 = (int)((float)uVar19 / fVar20) & 0xffff;
                  }
                  sVar4 = (short)uVar19;
                  fVar20 = pdVar18->postmultiply;
                  if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                    sVar4 = (short)(int)((float)uVar19 * fVar20);
                  }
                }
                else {
                  iVar11 = MSG_ReadSBits(pdVar18->significant_bits);
                  fVar20 = pdVar18->premultiply;
                  sVar4 = (short)iVar11;
                  if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                    sVar4 = (short)(int)((float)sVar4 / fVar20);
                  }
                  fVar20 = pdVar18->postmultiply;
                  if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                    sVar4 = (short)(int)((float)sVar4 * fVar20);
                  }
                }
                *(short *)(to + iVar9) = sVar4;
              }
            }
            else if (uVar13 == 4) {
              if (iVar9 + 3 < nBufSize) {
                if (uVar19 == 0) {
                  uVar6 = MSG_ReadBits(pdVar18->significant_bits);
                  fVar20 = (float)uVar6;
                }
                else {
                  iVar9 = MSG_ReadSBits(pdVar18->significant_bits);
                  fVar20 = (float)iVar9;
                }
                fVar2 = pdVar18->premultiply;
                if ((fVar2 < 0.9999) || (1.0001 < fVar2)) {
                  fVar20 = fVar20 / fVar2;
                }
                fVar2 = pdVar18->postmultiply;
                if ((fVar2 < 0.9999) || (1.0001 < fVar2)) {
                  fVar20 = fVar2 * fVar20;
                }
                goto LAB_00048c40;
              }
            }
            else {
              if (uVar13 != 1) goto LAB_00048b6b;
              if (uVar19 == 0) {
                uVar6 = MSG_ReadBits(pdVar18->significant_bits);
                bVar3 = (byte)uVar6;
                fVar20 = pdVar18->premultiply;
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  bVar3 = (byte)(int)((float)(uVar6 & 0xff) / fVar20);
                }
                fVar20 = pdVar18->postmultiply;
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  to[iVar9] = (byte)(int)((float)bVar3 * fVar20);
                  goto joined_r0x00049053;
                }
              }
              else {
                iVar11 = MSG_ReadSBits(pdVar18->significant_bits);
                bVar3 = (byte)iVar11;
                fVar20 = pdVar18->premultiply;
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  bVar3 = (byte)(int)((float)(short)(char)bVar3 / fVar20);
                }
                fVar20 = pdVar18->postmultiply;
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  bVar3 = (byte)(int)((float)(short)(char)bVar3 * fVar20);
                }
              }
              to[iVar9] = bVar3;
            }
          }
          else if (uVar13 == 0x20) {
            if (iVar9 + 3 < nBufSize) {
              iVar9 = MSG_ReadSBits(8);
              *(float *)(to + pdVar18->fieldOffset) =
                   ((float)(int)((float)cl.mtime[0] * 100.0) - (float)iVar9) / 100.0;
            }
          }
          else if (uVar13 < 0x21) {
            if (uVar13 != 0x10) goto LAB_00048b6b;
            if (iVar9 + 3 < nBufSize) {
              fVar20 = MSG_ReadBitAngle(pdVar18->significant_bits);
              goto LAB_00048c40;
            }
          }
          else if (uVar13 == 0x40) {
            if (iVar9 + 3 < nBufSize) {
              iVar9 = MSG_ReadSBits(pdVar18->significant_bits);
              fVar2 = pdVar18->premultiply;
              fVar20 = fVar2 * (float)cl.mtime[0] - (float)iVar9;
              if (0.9999 <= fVar2) {
                if (1.0001 < fVar2) {
                  fVar20 = fVar20 / fVar2;
                }
              }
              else {
                fVar20 = fVar20 / fVar2;
              }
LAB_00048c40:
              *(float *)(to + pdVar18->fieldOffset) = fVar20;
            }
          }
          else {
            if (uVar13 != 0x80) goto LAB_00048b6b;
            puVar14 = to + iVar9;
            puVar10 = puVar14;
            while (iVar11 = (int)puVar10 - (int)puVar14, iVar9 + iVar11 < nBufSize) {
              uVar6 = MSG_ReadBits(8);
              *puVar10 = (uchar)uVar6;
              if ((uchar)uVar6 == '\0') goto joined_r0x00049053;
              puVar10 = puVar10 + 1;
              iVar9 = pdVar18->fieldOffset;
            }
            if (iVar11 != 0) {
              puVar10[-1] = '\0';
            }
          }
        }
      }
joined_r0x00049053:
      iVar15 = iVar15 + 1;
    } while (iVar8 != iVar15);
  }
  iVar8 = MSG_CurrentBit();
  return iVar8 - iVar5;
}


// DELTA_ParseDescription  @ 00049cf0
qboolean DELTA_ParseDescription(char *name,delta_t **ppdesc,char *pstream)

{
  delta_definition_t *pdefinition;
  int iVar1;
  int iVar2;
  qboolean qVar3;
  int *piVar4;
  qboolean qVar5;
  delta_t *pdVar6;
  int *piVar7;
  delta_description_s *dest;
  int *piVar8;
  int *p;
  delta_definition_list_s *pdVar9;
  int in_GS_OFFSET;
  delta_description_s *local_78;
  char *local_6c;
  delta_link_t local_68;
  char local_60 [31];
  undefined1 local_41;
  char local_40 [31];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: delta_link_t * links@[???]
                       Unresolved local var: delta_definition_t * pdefinition@[???]
                       Unresolved local var: char[32] encoder@[???]
                       Unresolved local var: char[32] source@[???]
                       Unresolved local var: int count@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_60[0] = '\0';
  if (ppdesc == (delta_t **)0x0) {
    Sys_Error("DELTA_ParseDescription with no delta_description_t\n");
    qVar5 = false;
  }
  else {
    *ppdesc = (delta_t *)0x0;
    if (pstream == (char *)0x0) {
      Sys_Error("DELTA_ParseDescription with no data stream\n");
      qVar5 = false;
    }
    else {
      local_6c = pstream;
      piVar8 = (int *)0x0;
                    /* Unresolved local var: delta_link_t * newlink@[???]
                       Unresolved local var: delta_link_t link@[???]
                       Unresolved local var: delta_description_t * delta@[???] */
LAB_00049d48:
      local_6c = COM_Parse(local_6c);
      iVar1 = Q_strlen(com_token);
      if (0 < iVar1) {
        iVar1 = Q_stricmp(com_token,name);
        if (iVar1 == 0) {
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
          pdVar9 = g_defs;
          if (g_defs != (delta_definition_list_t *)0x0) {
            while (iVar1 = Q_stricmp(com_token,pdVar9->ptypename), iVar1 != 0) {
              pdVar9 = pdVar9->next;
              if (pdVar9 == (delta_definition_list_s *)0x0) goto LAB_0004a019;
            }
            iVar1 = pdVar9->numelements;
            pdefinition = pdVar9->pdefinition;
            if (pdefinition != (delta_definition_t *)0x0) {
              local_6c = COM_Parse(local_6c);
              iVar2 = Q_strlen(com_token);
              if (iVar2 < 1) {
                Sys_Error("DELTA_ParseDescription:  Unknown encoder :  %s\nValid values:\nnone\ngamedll funcname\nclientdll funcname\n"
                          ,com_token);
                qVar5 = false;
              }
              else {
                iVar2 = Q_stricmp(com_token,"none");
                if (iVar2 == 0) goto LAB_00049e70;
                Q_strncpy(local_40,com_token,0x1f);
                local_21 = 0;
                local_6c = COM_Parse(local_6c);
                iVar2 = Q_strlen(com_token);
                if (0 < iVar2) {
                  Q_strncpy(local_60,com_token,0x1f);
                  local_41 = 0;
LAB_00049e70:
                  do {
                    local_6c = COM_Parse(local_6c);
                    iVar2 = Q_strlen(com_token);
                    if ((iVar2 < 1) || (iVar2 = Q_stricmp(com_token,"}"), iVar2 == 0))
                    goto LAB_00049d48;
                    iVar2 = Q_stricmp(com_token,"{");
                    if (iVar2 != 0) {
                      Con_Printf("DELTA_ParseDescription:  Expecting {, got %s\n",com_token);
                      qVar5 = false;
                      goto LAB_0004a000;
                    }
                    while (iVar2 = Q_stricmp(com_token,"}"), iVar2 != 0) {
                      local_6c = COM_Parse(local_6c);
                      iVar2 = Q_strlen(com_token);
                      if (iVar2 < 1) goto LAB_00049e70;
                      Q_memset(&local_68,0,8);
                      local_68.delta = Mem_ZeroMalloc(0x44);
                      qVar3 = DELTA_ParseField(iVar1,pdefinition,&local_68,&local_6c);
                      qVar5 = false;
                      if (qVar3 == false) goto LAB_0004a000;
                      piVar4 = Mem_ZeroMalloc(8);
                      *piVar4 = (int)piVar8;
                      piVar4[1] = (int)local_68.delta;
                      piVar8 = piVar4;
                    }
                    COM_UngetToken();
                  } while( true );
                }
                Sys_Error("DELTA_ParseDescription:  Expecting encoder\n");
                qVar5 = false;
              }
              goto LAB_0004a000;
            }
          }
LAB_0004a019:
          Sys_Error("DELTA_ParseDescription:  Unknown data type:  %s\n",com_token);
          qVar5 = false;
          goto LAB_0004a000;
        }
        local_6c = COM_Parse(local_6c);
        do {
          local_6c = COM_Parse(local_6c);
          iVar1 = Q_strlen(com_token);
          if (iVar1 < 1) {
            Sys_Error("Error during description skip");
            break;
          }
          iVar1 = Q_stricmp(com_token,"}");
        } while (iVar1 != 0);
        goto LAB_00049d48;
      }
      pdVar6 = Mem_ZeroMalloc(0x30);
                    /* Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: delta_link_t * n@[???]
                       Unresolved local var: delta_link_t * newlist@[???] */
      if (piVar8 == (int *)0x0) {
                    /* Unresolved local var: delta_description_t * pdesc@[???]
                       Unresolved local var: delta_description_t * pcur@[???]
                       Unresolved local var: delta_t * pdelta@[???]
                       Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int i@[???] */
        iVar1 = 0;
        local_78 = Mem_ZeroMalloc(0);
      }
      else {
        piVar4 = (int *)0x0;
        do {
          p = piVar8;
          piVar7 = piVar4;
          piVar8 = (int *)*p;
          *p = (int)piVar7;
          piVar4 = p;
        } while (piVar8 != (int *)0x0);
        iVar1 = 0;
                    /* Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: int c@[???] */
        for (; iVar1 = iVar1 + 1, piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
        }
        local_78 = Mem_ZeroMalloc(iVar1 * 0x44);
        dest = local_78;
        piVar8 = p;
        do {
          Q_memcpy(dest,(void *)piVar8[1],0x44);
          Mem_Free((void *)piVar8[1]);
          piVar8[1] = 0;
          piVar8 = (int *)*piVar8;
          dest = dest + 1;
        } while (piVar8 != (int *)0x0);
        do {
                    /* Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: delta_link_t * n@[???] */
          piVar8 = (int *)*p;
          Mem_Free(p);
          p = piVar8;
        } while (piVar8 != (int *)0x0);
      }
      pdVar6->fieldCount = iVar1;
      pdVar6->dynamic = 1;
      pdVar6->pdd = local_78;
      *ppdesc = pdVar6;
      iVar1 = Q_strlen(local_60);
      if (iVar1 < 1) {
        qVar5 = true;
      }
      else {
        Q_strncpy((*ppdesc)->conditionalencodename,local_60,0x1f);
        (*ppdesc)->conditionalencodename[0x1f] = '\0';
        (*ppdesc)->conditionalencode = (encoder_t)0x0;
        qVar5 = true;
      }
    }
  }
LAB_0004a000:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return qVar5;
}


// DELTA_ParseField  @ 00049700
qboolean DELTA_ParseField(int count,delta_definition_t *pdefinition,delta_link_t *pField,
                         char **pstream)

{
  delta_description_t *pdVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  qboolean qVar6;
  float fVar7;
  double dVar8;
  qboolean local_2c;
  
                    /* Unresolved local var: qboolean readpost@[???] */
  iVar3 = Q_stricmp(com_token,"DEFINE_DELTA");
  if (iVar3 == 0) {
    bVar2 = false;
  }
  else {
    iVar3 = Q_stricmp(com_token,"DEFINE_DELTA_POST");
    bVar2 = true;
    if (iVar3 != 0) {
      Sys_Error("DELTA_ParseField:  Expecting DEFINE_*, got %s\n",com_token);
      return false;
    }
  }
  pcVar4 = COM_Parse(*pstream);
  *pstream = pcVar4;
  iVar3 = Q_stricmp(com_token,"(");
  if (iVar3 != 0) {
    Sys_Error("DELTA_ParseField:  Expecting (, got %s\n",com_token);
    return false;
  }
  pcVar4 = COM_Parse(*pstream);
  *pstream = pcVar4;
  iVar3 = Q_strlen(com_token);
  if (iVar3 < 1) {
    Sys_Error("DELTA_ParseField:  Expecting fieldname\n");
    return false;
  }
                    /* Unresolved local var: int i@[???] */
  Q_strncpy(pField->delta->fieldName,com_token,0x1f);
  pField->delta->fieldName[0x1f] = '\0';
  pdVar1 = pField->delta;
  if (0 < count) {
    iVar3 = 0;
    do {
      iVar5 = Q_stricmp(com_token,pdefinition->fieldName);
      if (iVar5 == 0) {
        iVar3 = pdefinition->fieldOffset;
        goto LAB_00049820;
      }
      iVar3 = iVar3 + 1;
      pdefinition = pdefinition + 1;
    } while (count != iVar3);
  }
  Sys_Error("Couldn\'t find offset for %s!!!\n",com_token);
  iVar3 = 0;
LAB_00049820:
  pdVar1->fieldOffset = iVar3;
  pcVar4 = COM_Parse(*pstream);
  *pstream = pcVar4;
  qVar6 = DELTA_ParseType(pField->delta,pstream);
  local_2c = false;
  if (qVar6 != false) {
    pcVar4 = COM_Parse(*pstream);
    *pstream = pcVar4;
    pField->delta->fieldSize = 1;
    pdVar1 = pField->delta;
    iVar3 = Q_atoi(com_token);
    pdVar1->significant_bits = iVar3;
    pcVar4 = COM_Parse(*pstream);
    *pstream = pcVar4;
    pcVar4 = COM_Parse(pcVar4);
    *pstream = pcVar4;
    pdVar1 = pField->delta;
    fVar7 = Q_atof(com_token);
    pdVar1->premultiply = fVar7;
    if (bVar2) {
      pcVar4 = COM_Parse(*pstream);
      *pstream = pcVar4;
      pcVar4 = COM_Parse(pcVar4);
      *pstream = pcVar4;
      pdVar1 = pField->delta;
      dVar8 = strtod(com_token,(char **)0x0);
      pdVar1->postmultiply = (float)dVar8;
    }
    else {
      pField->delta->postmultiply = 1.0;
    }
    pcVar4 = COM_Parse(*pstream);
    *pstream = pcVar4;
    iVar3 = Q_stricmp(com_token,")");
    if (iVar3 == 0) {
      pcVar4 = COM_Parse(*pstream);
      *pstream = pcVar4;
      iVar3 = Q_stricmp(com_token,",");
      local_2c = true;
      if (iVar3 != 0) {
        local_2c = true;
        COM_UngetToken();
      }
    }
    else {
      Con_Printf("DELTA_ParseField:  Expecting ), got %s\n",com_token);
      local_2c = false;
    }
  }
  return local_2c;
}


// DELTA_ParseOneField  @ 00049c10
qboolean DELTA_ParseOneField(char **ppstream,delta_link_t **pplist,int count,
                            delta_definition_t *pdefinition)

{
  char *pcVar1;
  qboolean qVar2;
  delta_link_t *pdVar3;
  int iVar4;
  delta_link_t local_24 [2];
  
                    /* Unresolved local var: delta_link_t * newlink@[???]
                       Unresolved local var: delta_link_t link@[???]
                       Unresolved local var: delta_description_t * delta@[???] */
  while( true ) {
    iVar4 = Q_stricmp(com_token,"}");
    if (iVar4 == 0) {
      COM_UngetToken();
      return true;
    }
    pcVar1 = COM_Parse(*ppstream);
    *ppstream = pcVar1;
    iVar4 = Q_strlen(com_token);
    if (iVar4 < 1) break;
    Q_memset(local_24,0,8);
    local_24[0].delta = Mem_ZeroMalloc(0x44);
    qVar2 = DELTA_ParseField(count,pdefinition,local_24,ppstream);
    if (qVar2 == false) {
      return false;
    }
    pdVar3 = Mem_ZeroMalloc(8);
    pdVar3->delta = local_24[0].delta;
    pdVar3->next = *pplist;
    *pplist = pdVar3;
  }
  return true;
}


// DELTA_ParseType  @ 00049510
qboolean DELTA_ParseType(delta_description_t *pdelta,char **pstream)

{
  char *pcVar1;
  int iVar2;
  
  while( true ) {
    do {
      pcVar1 = COM_Parse(*pstream);
      *pstream = pcVar1;
      iVar2 = Q_strlen(com_token);
      if (iVar2 < 1) {
        Con_Printf("DELTA_ParseField:  Expecting fieldtype info\n");
        return false;
      }
      iVar2 = Q_stricmp(com_token,"|");
    } while (iVar2 == 0);
    iVar2 = Q_stricmp(com_token,",");
    if (iVar2 == 0) break;
    iVar2 = Q_stricmp(com_token,"DT_SIGNED");
    if (iVar2 == 0) {
      pdelta->fieldType = pdelta->fieldType | 0x80000000;
    }
    else {
      iVar2 = Q_stricmp(com_token,"DT_BYTE");
      if (iVar2 == 0) {
        pdelta->fieldType = pdelta->fieldType | 1;
      }
      else {
        iVar2 = Q_stricmp(com_token,"DT_SHORT");
        if (iVar2 == 0) {
          pdelta->fieldType = pdelta->fieldType | 2;
        }
        else {
          iVar2 = Q_stricmp(com_token,"DT_FLOAT");
          if (iVar2 == 0) {
            pdelta->fieldType = pdelta->fieldType | 4;
          }
          else {
            iVar2 = Q_stricmp(com_token,"DT_INTEGER");
            if (iVar2 == 0) {
              pdelta->fieldType = pdelta->fieldType | 8;
            }
            else {
              iVar2 = Q_stricmp(com_token,"DT_ANGLE");
              if (iVar2 == 0) {
                pdelta->fieldType = pdelta->fieldType | 0x10;
              }
              else {
                iVar2 = Q_stricmp(com_token,"DT_TIMEWINDOW_8");
                if (iVar2 == 0) {
                  pdelta->fieldType = pdelta->fieldType | 0x20;
                }
                else {
                  iVar2 = Q_stricmp(com_token,"DT_TIMEWINDOW_BIG");
                  if (iVar2 == 0) {
                    pdelta->fieldType = pdelta->fieldType | 0x40;
                  }
                  else {
                    iVar2 = Q_stricmp(com_token,"DT_STRING");
                    if (iVar2 != 0) {
                      Sys_Error("DELTA_ParseField:  Unknown type or type flag %s\n",com_token);
                      return false;
                    }
                    pdelta->fieldType = pdelta->fieldType | 0x80;
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


// DELTA_PrintStats  @ 0004a3a0
void DELTA_PrintStats(char *name,delta_t *p)

{
  delta_description_s *pdVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (p != (delta_t *)0x0) {
                    /* Unresolved local var: int i@[???] */
    iVar2 = 0;
    Con_Printf("Stats for \'%s\'\n",name);
    if (0 < p->fieldCount) {
      iVar3 = 0;
      do {
        pdVar1 = p->pdd;
        iVar2 = iVar2 + 1;
        Con_Printf("  %02i % 10s:  s % 5i r % 5i\n",iVar2,pdVar1->fieldName + iVar3,
                   *(undefined4 *)(pdVar1->fieldName + iVar3 + 0x38),
                   *(undefined4 *)(pdVar1->fieldName + iVar3 + 0x3c));
        iVar3 = iVar3 + 0x44;
      } while (iVar2 < p->fieldCount);
    }
    Con_Printf("\n");
    return;
  }
  return;
}


// DELTA_RegisterDescription  @ 0004a250
void DELTA_RegisterDescription(char *name)

{
  delta_registry_t *pdVar1;
  delta_registry_t *pdVar2;
  char *pcVar3;
  
                    /* Unresolved local var: delta_registry_t * p@[???] */
  pdVar2 = Mem_ZeroMalloc(0xc);
  pdVar1 = pdVar2;
  pdVar2->next = g_deltaregistry;
  g_deltaregistry = pdVar1;
  pcVar3 = Mem_Strdup(name);
  pdVar2->pdesc = (delta_t *)0x0;
  pdVar2->name = pcVar3;
  return;
}


// DELTA_ReverseLinks  @ 00049350
void DELTA_ReverseLinks(delta_link_t **plinks)

{
  delta_link_s *pdVar1;
  delta_link_t *pdVar2;
  delta_link_t *pdVar3;
  
                    /* Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: delta_link_t * n@[???]
                       Unresolved local var: delta_link_t * newlist@[???] */
  pdVar2 = *plinks;
  if (pdVar2 != (delta_link_t *)0x0) {
    pdVar1 = pdVar2;
    pdVar3 = (delta_link_t *)0x0;
    do {
      pdVar2 = pdVar1;
      pdVar1 = pdVar2->next;
      pdVar2->next = pdVar3;
      pdVar3 = pdVar2;
    } while (pdVar1 != (delta_link_s *)0x0);
  }
  *plinks = pdVar2;
  return;
}


// DELTA_SetField  @ 00047ba0
void DELTA_SetField(delta_s *pFields,char *fieldname)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
                    /* Unresolved local var: delta_description_t * pTest@[???] */
  iVar3 = 0;
  iVar2 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  if (0 < pFields->fieldCount) {
    do {
      pcVar4 = pFields->pdd->fieldName + iVar2 + -4;
      iVar1 = Q_strcasecmp(pcVar4 + 4,fieldname);
      if (iVar1 == 0) {
        if (pcVar4 != (char *)0x0) {
          *(ushort *)&((delta_stats_t *)(pcVar4 + 0x38))->sendcount =
               (ushort)((delta_stats_t *)(pcVar4 + 0x38))->sendcount | 1;
        }
        return;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x44;
    } while (iVar3 < pFields->fieldCount);
  }
  Con_Printf("DELTA_FindField:  Warning, couldn\'t find %s\n");
  return;
}


// DELTA_SetFieldByIndex  @ 00047ca0
void DELTA_SetFieldByIndex(delta_s *pFields,int fieldNumber)

{
  pFields->pdd[fieldNumber].flags = (ushort)*(undefined4 *)&pFields->pdd[fieldNumber].flags | 1;
  return;
}


// DELTA_SetSendFlagBits  @ 00048210
void DELTA_SetSendFlagBits(delta_t *pFields,int *bits,int *bytecount)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: delta_description_t * pTest@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int lastbit@[???]
                       Unresolved local var: int bytenumber@[???]
                       Unresolved local var: int bitnumber@[???]
                       Unresolved local var: int fieldCount@[???] */
  Q_memset(bits,0,8);
  iVar2 = pFields->fieldCount + -1;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else {
    iVar3 = -1;
    iVar1 = iVar2 * 0x44;
    do {
      if ((pFields->pdd->fieldName[iVar1 + 0x34] & 1U) != 0) {
        if (iVar3 == -1) {
          iVar3 = iVar2;
        }
        bits[0x1f < iVar2] = bits[0x1f < iVar2] | 1 << ((byte)iVar2 & 0x1f);
      }
      iVar2 = iVar2 + -1;
      iVar1 = iVar1 + -0x44;
    } while (iVar2 != -1);
    iVar2 = (iVar3 >> 3) + 1;
  }
  *bytecount = iVar2;
  return;
}


// DELTA_Shutdown  @ 0004a7b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DELTA_Shutdown(void)

{
  delta_encoder_s *pdVar1;
  delta_definition_list_s *pdVar2;
  delta_registry_s *pdVar3;
  delta_encoder_t *p;
  delta_definition_list_t *p_00;
  delta_registry_t *p_01;
  delta_t *p_02;
  
  p = g_encoders;
  while (p != (delta_encoder_t *)0x0) {
    pdVar1 = p->next;
    Mem_Free(p->name);
    Mem_Free(p);
    p = pdVar1;
  }
                    /* Unresolved local var: delta_definition_list_t * p@[???]
                       Unresolved local var: delta_definition_list_t * n@[???] */
  g_encoders = (delta_encoder_t *)0x0;
  p_00 = g_defs;
  while (p_00 != (delta_definition_list_t *)0x0) {
    pdVar2 = p_00->next;
    Mem_Free(p_00->ptypename);
    Mem_Free(p_00);
    p_00 = pdVar2;
  }
  g_defs = (delta_definition_list_t *)0x0;
  p_01 = g_deltaregistry;
                    /* Unresolved local var: delta_registry_t * p@[???]
                       Unresolved local var: delta_registry_t * n@[???] */
  while (p_01 != (delta_registry_t *)0x0) {
    pdVar3 = p_01->next;
    Mem_Free(p_01->name);
    p_02 = p_01->pdesc;
    if (p_02 != (delta_t *)0x0) {
      if (p_02->dynamic != 0) {
        Mem_Free(p_02->pdd);
        p_02 = p_01->pdesc;
      }
      Mem_Free(p_02);
      p_01->pdesc = (delta_t *)0x0;
    }
    Mem_Free(p_01);
    p_01 = pdVar3;
  }
  g_deltaregistry = (delta_registry_t *)0x0;
  return;
}


// DELTA_SkipDescription  @ 00049b90
void DELTA_SkipDescription(char **pstream)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = COM_Parse(*pstream);
  *pstream = pcVar1;
  while( true ) {
    pcVar1 = COM_Parse(pcVar1);
    *pstream = pcVar1;
    iVar2 = Q_strlen(com_token);
    if (iVar2 < 1) {
      Sys_Error("Error during description skip");
      return;
    }
    iVar2 = Q_stricmp(com_token,"}");
    if (iVar2 == 0) break;
    pcVar1 = *pstream;
  }
  return;
}


// DELTA_TestDelta  @ 00047d10
int DELTA_TestDelta(uchar *from,uchar *to,delta_t *pFields)

{
  int iVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  uint uVar5;
  uchar *puVar6;
  __int32_t **pp_Var7;
  int iVar8;
  uchar uVar9;
  int iVar10;
  int iVar11;
  delta_description_s *pdVar12;
  int local_30;
  int local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float f1@[???]
                       Unresolved local var: float f2@[???]
                       Unresolved local var: char * st1@[???]
                       Unresolved local var: char * st2@[???]
                       Unresolved local var: delta_description_t * pTest@[???]
                       Unresolved local var: int fieldType@[???]
                       Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int length@[???]
                       Unresolved local var: int different@[???]
                       Unresolved local var: int neededBits@[???]
                       Unresolved local var: int highestBit@[???] */
  iVar2 = pFields->fieldCount;
  if (iVar2 < 1) {
    local_30 = 0;
  }
  else {
    local_24 = -1;
    iVar11 = 0;
    local_30 = 0;
    do {
      while( true ) {
        pdVar12 = pFields->pdd + iVar11;
        uVar5 = pdVar12->fieldType & 0x7fffffff;
        iVar10 = local_30;
        if (uVar5 != 8) break;
LAB_00047f48:
        if (*(int *)(from + pdVar12->fieldOffset) != *(int *)(to + pdVar12->fieldOffset)) {
LAB_00047efd:
          iVar10 = local_30 + pdVar12->significant_bits;
          local_24 = iVar11;
        }
joined_r0x00047f3a:
        local_30 = iVar10;
        iVar11 = iVar11 + 1;
        if (iVar2 == iVar11) goto LAB_00047e2b;
      }
      if (uVar5 < 9) {
        if (uVar5 == 2) {
          if (*(short *)(to + pdVar12->fieldOffset) != *(short *)(from + pdVar12->fieldOffset))
          goto LAB_00047efd;
        }
        else {
          if (uVar5 == 4) goto LAB_00047f48;
          if (uVar5 != 1) goto LAB_00047ea1;
          if (from[pdVar12->fieldOffset] != to[pdVar12->fieldOffset]) {
            iVar10 = local_30 + pdVar12->significant_bits;
            local_24 = iVar11;
          }
        }
        goto joined_r0x00047f3a;
      }
      if (uVar5 == 0x20) {
        iVar8 = pdVar12->fieldOffset;
        fVar3 = 100.0;
LAB_00047ed1:
        if ((int)(fVar3 * *(float *)(from + iVar8)) != (int)(fVar3 * *(float *)(to + iVar8)))
        goto LAB_00047efd;
        goto joined_r0x00047f3a;
      }
      if (uVar5 < 0x21) {
        if (uVar5 == 0x10) goto LAB_00047f48;
      }
      else {
        if (uVar5 == 0x40) {
          iVar8 = pdVar12->fieldOffset;
          fVar3 = 1000.0;
          goto LAB_00047ed1;
        }
        if (uVar5 == 0x80) {
          iVar8 = pdVar12->fieldOffset;
          puVar6 = to + iVar8;
          uVar9 = *puVar6;
          if (uVar9 != '\0') {
            iVar10 = 0;
            bVar4 = false;
            do {
              while (iVar1 = iVar10 * 8, bVar4) {
                iVar10 = iVar10 + 1;
                bVar4 = true;
                uVar9 = puVar6[iVar10];
                if (uVar9 == '\0') goto LAB_00047e07;
              }
                    /* Unresolved local var: int __res@[???] */
              pp_Var7 = __ctype_tolower_loc();
                    /* Unresolved local var: int __res@[???] */
              if ((*pp_Var7)[(char)from[iVar10 + iVar8]] != (*pp_Var7)[(char)uVar9]) {
                bVar4 = true;
                pdVar12->flags = (ushort)*(undefined4 *)&pdVar12->flags | 1;
              }
              iVar10 = iVar10 + 1;
              uVar9 = puVar6[iVar10];
            } while (uVar9 != '\0');
LAB_00047e07:
            iVar10 = local_30 + 0x10 + iVar1;
            if (!bVar4) {
              iVar10 = local_30;
            }
          }
          goto joined_r0x00047f3a;
        }
      }
LAB_00047ea1:
      iVar11 = iVar11 + 1;
      Con_Printf("Bad field type %i\n",uVar5);
    } while (iVar2 != iVar11);
LAB_00047e2b:
    if (local_24 != -1) {
      local_30 = local_30 + 8 + (local_24 >> 3) * 8;
    }
  }
  return local_30;
}


// DELTA_UnsetField  @ 00047c20
void DELTA_UnsetField(delta_s *pFields,char *fieldname)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
                    /* Unresolved local var: delta_description_t * pTest@[???] */
  iVar3 = 0;
  iVar2 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  if (0 < pFields->fieldCount) {
    do {
      pcVar4 = pFields->pdd->fieldName + iVar2 + -4;
      iVar1 = Q_strcasecmp(pcVar4 + 4,fieldname);
      if (iVar1 == 0) {
        if (pcVar4 != (char *)0x0) {
          *(ushort *)&((delta_stats_t *)(pcVar4 + 0x38))->sendcount =
               (ushort)((delta_stats_t *)(pcVar4 + 0x38))->sendcount & 0xfffe;
        }
        return;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x44;
    } while (iVar3 < pFields->fieldCount);
  }
  Con_Printf("DELTA_FindField:  Warning, couldn\'t find %s\n");
  return;
}


// DELTA_UnsetFieldByIndex  @ 00047cc0
void DELTA_UnsetFieldByIndex(delta_s *pFields,int fieldNumber)

{
  pFields->pdd[fieldNumber].flags = (ushort)*(undefined4 *)&pFields->pdd[fieldNumber].flags & 0xfffe
  ;
  return;
}


// DELTA_WriteDelta  @ 000486d0
int DELTA_WriteDelta(uchar *from,uchar *to,qboolean force,delta_t *pFields,_func_void *callback)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  uint32 data;
  bool bVar9;
  uint local_24 [5];
  
                    /* Unresolved local var: int sendfields@[???] */
  iVar3 = 0;
  iVar2 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  if (0 < pFields->fieldCount) {
    do {
      iVar2 = iVar2 + 1;
      pcVar1 = pFields->pdd->fieldName + iVar3 + 0x34;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      iVar3 = iVar3 + 0x44;
    } while (iVar2 < pFields->fieldCount);
  }
  DELTA_MarkSendFields(from,to,pFields);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  iVar2 = pFields->fieldCount;
  bVar9 = true;
  if (0 < iVar2) {
    iVar4 = 0;
    iVar8 = 0;
    iVar3 = 0;
    do {
      if ((pFields->pdd->fieldName[iVar4 + 0x34] & 1U) != 0) {
        pcVar1 = pFields->pdd->fieldName + iVar4 + 0x38;
        *(int *)pcVar1 = *(int *)pcVar1 + 1;
        iVar8 = iVar8 + 1;
        iVar2 = pFields->fieldCount;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x44;
    } while (iVar3 < iVar2);
    bVar9 = iVar8 == 0;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int bytecount@[???]
                       Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int[2] bits@[???]
                       Unresolved local var: uchar * pdest@[???] */
  if ((force == false) && (bVar9)) {
    return 1;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int bytecount@[???]
                       Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int[2] bits@[???]
                       Unresolved local var: uchar * pdest@[???]
                       Unresolved local var: delta_description_t * pTest@[???]
                       Unresolved local var: int lastbit@[???]
                       Unresolved local var: int bytenumber@[???]
                       Unresolved local var: int bitnumber@[???] */
  Q_memset(local_24,0,8);
  iVar2 = pFields->fieldCount + -1;
  if (iVar2 < 0) {
    if (callback == (_func_void *)0x0) {
      MSG_WriteBits(0,3);
      goto LAB_0004881a;
    }
    data = 0;
LAB_000487e4:
    (*callback)();
  }
  else {
    iVar3 = -1;
    psVar5 = &pFields->pdd[pFields->fieldCount + -1].flags;
    do {
      if ((*psVar5 & 1) != 0) {
        if (iVar3 == -1) {
          iVar3 = iVar2;
        }
        puVar6 = local_24 + (0x1f < iVar2);
        *puVar6 = *puVar6 | 1 << ((byte)iVar2 & 0x1f);
      }
      iVar2 = iVar2 + -1;
      psVar5 = psVar5 + -0x22;
    } while (iVar2 != -1);
    data = (iVar3 >> 3) + 1;
    if (callback != (_func_void *)0x0) goto LAB_000487e4;
  }
  MSG_WriteBits(data,3);
  puVar6 = local_24;
  if (data != 0) {
    do {
      puVar7 = (uint *)((int)puVar6 + 1);
      MSG_WriteBits((uint)(byte)*puVar6,8);
      puVar6 = puVar7;
    } while (puVar7 != (uint *)((int)local_24 + data));
  }
LAB_0004881a:
  DELTA_WriteMarkedFields(from,to,pFields);
  return 1;
}


// DELTA_WriteMarkedFields  @ 000482a0
void DELTA_WriteMarkedFields(uchar *from,uchar *to,delta_t *pFields)

{
  float fVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  delta_description_s *pdVar5;
  uint uVar6;
  int iVar7;
  uchar *puVar8;
  uint32 data;
  int iVar9;
  uint32 local_24;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pTest@[???]
                       Unresolved local var: int fieldSign@[???]
                       Unresolved local var: int fieldType@[???]
                       Unresolved local var: float f2@[???]
                       Unresolved local var: uchar b2@[???]
                       Unresolved local var: ushort s2@[???]
                       Unresolved local var: uint i2@[???]
                       Unresolved local var: char * st2@[???]
                       Unresolved local var: char sb2@[???]
                       Unresolved local var: short ss2@[???]
                       Unresolved local var: int si2@[???]
                       Unresolved local var: int fieldCount@[???] */
  iVar2 = pFields->fieldCount;
  if (0 < iVar2) {
    iVar7 = 0;
    do {
      pdVar5 = pFields->pdd + iVar7;
      if ((pdVar5->flags & 1) != 0) {
        uVar4 = pdVar5->fieldType & 0x7fffffff;
        uVar6 = pdVar5->fieldType & 0x80000000;
        if (uVar4 == 8) {
          fVar1 = pdVar5->premultiply;
          local_24 = *(uint32 *)(to + pdVar5->fieldOffset);
          if (uVar6 == 0) {
            if ((fVar1 < 0.9999) || (1.0001 < fVar1)) {
              local_24 = (uint32)(longlong)ROUND((float)local_24 * fVar1);
            }
            MSG_WriteBits(local_24,pdVar5->significant_bits);
          }
          else {
            if ((fVar1 < 0.9999) || (1.0001 < fVar1)) {
              local_24 = (uint32)((float)(int)local_24 * fVar1);
            }
            MSG_WriteSBits(local_24,pdVar5->significant_bits);
          }
        }
        else if (uVar4 < 9) {
          if (uVar4 == 2) {
            if (uVar6 == 0) {
              MSG_WriteBits((int)((float)*(ushort *)(to + pdVar5->fieldOffset) * pdVar5->premultiply
                                 ) & 0xffff,pdVar5->significant_bits);
            }
            else {
              MSG_WriteSBits((int)(short)(int)((float)*(short *)(to + pdVar5->fieldOffset) *
                                              pdVar5->premultiply),pdVar5->significant_bits);
            }
          }
          else if (uVar4 == 4) {
            iVar9 = pdVar5->significant_bits;
            data = (uint32)(*(float *)(to + pdVar5->fieldOffset) * pdVar5->premultiply);
            if (uVar6 == 0) {
LAB_0004834b:
              MSG_WriteBits(data,iVar9);
            }
            else {
              MSG_WriteSBits(data,iVar9);
            }
          }
          else {
            if (uVar4 != 1) goto LAB_0004837d;
            if (uVar6 == 0) {
              MSG_WriteBits((int)((float)to[pdVar5->fieldOffset] * pdVar5->premultiply) & 0xff,
                            pdVar5->significant_bits);
            }
            else {
              MSG_WriteSBits((int)(char)(int)((float)(short)(char)to[pdVar5->fieldOffset] *
                                             pdVar5->premultiply),pdVar5->significant_bits);
            }
          }
        }
        else if (uVar4 == 0x20) {
          fVar1 = (float)sv.time * 100.0;
          iVar9 = 8;
          fVar3 = *(float *)(to + pdVar5->fieldOffset) * 100.0;
LAB_0004849f:
          MSG_WriteSBits((int)fVar1 - (int)fVar3,iVar9);
        }
        else {
          if (uVar4 < 0x21) {
            if (uVar4 == 0x10) {
              MSG_WriteBitAngle(*(float *)(to + pdVar5->fieldOffset),pdVar5->significant_bits);
              goto LAB_00048350;
            }
          }
          else {
            if (uVar4 == 0x40) {
              iVar9 = pdVar5->significant_bits;
              fVar1 = pdVar5->premultiply * (float)sv.time;
              fVar3 = pdVar5->premultiply * *(float *)(to + pdVar5->fieldOffset);
              goto LAB_0004849f;
            }
            if (uVar4 == 0x80) {
              for (puVar8 = to + pdVar5->fieldOffset; (puVar8 != (uchar *)0x0 && (*puVar8 != '\0'));
                  puVar8 = puVar8 + 1) {
                MSG_WriteBits((int)(char)*puVar8,8);
              }
              iVar9 = 8;
              data = 0;
              goto LAB_0004834b;
            }
          }
LAB_0004837d:
          Con_Printf("unknown send field type\n");
        }
      }
LAB_00048350:
      iVar7 = iVar7 + 1;
    } while (iVar2 != iVar7);
  }
  return;
}


