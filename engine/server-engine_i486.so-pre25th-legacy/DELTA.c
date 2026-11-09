// DELTA_AddDefinition  @ 0006ca20
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
      pdVar4 = Mem_ZeroMalloc(0x10);
      pdVar2 = pdVar4;
      pdVar4->next = g_defs;
      g_defs = pdVar2;
      pcVar5 = Mem_Strdup(name);
      pdVar4->pdefinition = pdef;
      pdVar4->numelements = numelements;
      pdVar4->ptypename = pcVar5;
      return;
    }
    iVar3 = Q_stricmp(name,pdVar1->ptypename);
    if (iVar3 == 0) break;
    pdVar1 = pdVar1->next;
  }
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar1->pdefinition = pdef;
  pdVar1->numelements = numelements;
  return;
}


// DELTA_AddEncoder  @ 0006c210
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


// DELTA_BuildFromLinks  @ 0006c370
delta_t * DELTA_BuildFromLinks(delta_link_t **pplinks)

{
  delta_t *pdVar1;
  delta_link_s *pdVar2;
  delta_description_s *pdVar3;
  size_t size;
  delta_link_t *pdVar4;
  delta_description_s *dest;
  int iVar5;
  delta_link_s *pdVar6;
  
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
  pdVar6 = *pplinks;
  pdVar4 = (delta_link_t *)0x0;
  if (*pplinks == (delta_link_t *)0x0) {
    size = 0;
    iVar5 = 0;
  }
  else {
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


// DELTA_CheckDelta  @ 0006b530
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


// DELTA_ClearDefinitions  @ 0006cab0
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


// DELTA_ClearEncoders  @ 0006c250
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


// DELTA_ClearFlags  @ 0006ab50
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


// DELTA_ClearLinks  @ 0006c330
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


// DELTA_ClearRegistrations  @ 0006d110
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


// DELTA_ClearStats  @ 0006d1d0
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


// DELTA_ClearStats_f  @ 0006a820
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


// DELTA_CountLinks  @ 0006c2e0
int DELTA_CountLinks(delta_link_t *plinks)

{
  int iVar1;
  
                    /* Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: int c@[???] */
  iVar1 = 0;
  for (; plinks != (delta_link_t *)0x0; plinks = plinks->next) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


// DELTA_CountSendFields  @ 0006adf0
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
  iVar2 = 0;
  iVar5 = pFields->fieldCount;
  if (0 < iVar5) {
    iVar3 = 0;
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


// DELTA_DumpStats_f  @ 0006a890
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
    pcVar6 = pdVar3->name;
                    /* Unresolved local var: int i@[???] */
    if (pdVar1 != (delta_t *)0x0) {
      Con_Printf("Stats for \'%s\'\n",pcVar6);
      if (0 < pdVar1->fieldCount) {
        pcVar4 = (char *)0x0;
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


// DELTA_FindDefinition  @ 0006cb00
delta_definition_t * DELTA_FindDefinition(char *name,int *count)

{
  delta_definition_t *pdVar1;
  int iVar2;
  delta_definition_list_s *pdVar3;
  bool bVar4;
  
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3 = g_defs;
  pdVar1 = (delta_definition_t *)0x0;
  bVar4 = g_defs != (delta_definition_list_t *)0x0;
  *count = 0;
  if (bVar4) {
    while (iVar2 = Q_stricmp(name,pdVar3->ptypename), iVar2 != 0) {
      pdVar3 = pdVar3->next;
      if (pdVar3 == (delta_definition_list_s *)0x0) {
        return (delta_definition_t *)0x0;
      }
    }
    *count = pdVar3->numelements;
    pdVar1 = pdVar3->pdefinition;
  }
  return pdVar1;
}


// DELTA_FindField  @ 0006a930
delta_description_t * DELTA_FindField(delta_t *pFields,char *pszField)

{
  int iVar1;
  int iVar2;
  int iVar3;
  delta_description_t *pdVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  if (0 < pFields->fieldCount) {
    iVar2 = 0;
    iVar3 = 0;
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


// DELTA_FindFieldIndex  @ 0006a9a0
int DELTA_FindFieldIndex(delta_s *pFields,char *fieldname)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  if (0 < pFields->fieldCount) {
    iVar3 = 0;
    iVar2 = 0;
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


// DELTA_FindOffset  @ 0006c470
int DELTA_FindOffset(int count,delta_definition_t *pdef,char *fieldname)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < count) {
    iVar2 = 0;
    do {
      iVar1 = Q_stricmp(fieldname,pdef->fieldName);
      if (iVar1 == 0) {
        return pdef->fieldOffset;
      }
      iVar2 = iVar2 + 1;
      pdef = pdef + 1;
    } while (iVar2 != count);
  }
  Sys_Error("Couldn\'t find offset for %s!!!\n",fieldname);
  return 0;
}


// DELTA_FreeDescription  @ 0006c9e0
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


// DELTA_Init  @ 0006d2b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DELTA_Init(void)

{
  delta_definition_list_t *pdVar1;
  int iVar2;
  delta_definition_list_s *pdVar3;
  char *pcVar4;
  
  Cmd_AddCommand("delta_stats",DELTA_DumpStats_f);
  Cmd_AddCommand("delta_clear",DELTA_ClearStats_f);
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  for (pdVar3 = g_defs; pdVar3 != (delta_definition_list_t *)0x0; pdVar3 = pdVar3->next) {
    iVar2 = Q_stricmp("clientdata_t",pdVar3->ptypename);
    if (iVar2 == 0) goto LAB_0006d311;
  }
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar1 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar1;
  pcVar4 = Mem_Strdup("clientdata_t");
  pdVar3->ptypename = pcVar4;
LAB_0006d311:
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3->pdefinition = g_ClientDataDefinition;
  pdVar3->numelements = 0x38;
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  for (pdVar3 = g_defs; pdVar3 != (delta_definition_list_t *)0x0; pdVar3 = pdVar3->next) {
    iVar2 = Q_stricmp("weapon_data_t",pdVar3->ptypename);
    if (iVar2 == 0) goto LAB_0006d351;
  }
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar1 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar1;
  pcVar4 = Mem_Strdup("weapon_data_t");
  pdVar3->ptypename = pcVar4;
LAB_0006d351:
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3->pdefinition = g_WeaponDataDefinition;
  pdVar3->numelements = 0x16;
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  for (pdVar3 = g_defs; pdVar3 != (delta_definition_list_t *)0x0; pdVar3 = pdVar3->next) {
    iVar2 = Q_stricmp("usercmd_t",pdVar3->ptypename);
    if (iVar2 == 0) goto LAB_0006d391;
  }
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar1 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar1;
  pcVar4 = Mem_Strdup("usercmd_t");
  pdVar3->ptypename = pcVar4;
LAB_0006d391:
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3->pdefinition = g_UsercmdDataDefinition;
  pdVar3->numelements = 0x10;
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  for (pdVar3 = g_defs; pdVar3 != (delta_definition_list_t *)0x0; pdVar3 = pdVar3->next) {
    iVar2 = Q_stricmp("entity_state_t",pdVar3->ptypename);
    if (iVar2 == 0) goto LAB_0006d3d1;
  }
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar1 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar1;
  pcVar4 = Mem_Strdup("entity_state_t");
  pdVar3->ptypename = pcVar4;
LAB_0006d3d1:
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3->pdefinition = g_EntityDataDefinition;
  pdVar3->numelements = 0x57;
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  for (pdVar3 = g_defs; pdVar3 != (delta_definition_list_t *)0x0; pdVar3 = pdVar3->next) {
    iVar2 = Q_stricmp("entity_state_player_t",pdVar3->ptypename);
    if (iVar2 == 0) goto LAB_0006d411;
  }
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar1 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar1;
  pcVar4 = Mem_Strdup("entity_state_player_t");
  pdVar3->ptypename = pcVar4;
LAB_0006d411:
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3->pdefinition = g_EntityDataDefinition;
  pdVar3->numelements = 0x57;
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  for (pdVar3 = g_defs; pdVar3 != (delta_definition_list_t *)0x0; pdVar3 = pdVar3->next) {
    iVar2 = Q_stricmp("custom_entity_state_t",pdVar3->ptypename);
    if (iVar2 == 0) goto LAB_0006d451;
  }
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar1 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar1;
  pcVar4 = Mem_Strdup("custom_entity_state_t");
  pdVar3->ptypename = pcVar4;
LAB_0006d451:
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3->pdefinition = g_EntityDataDefinition;
  pdVar3->numelements = 0x57;
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  for (pdVar3 = g_defs; pdVar3 != (delta_definition_list_t *)0x0; pdVar3 = pdVar3->next) {
    iVar2 = Q_stricmp("event_t",pdVar3->ptypename);
    if (iVar2 == 0) goto LAB_0006d48d;
  }
  pdVar3 = Mem_ZeroMalloc(0x10);
  pdVar1 = pdVar3;
  pdVar3->next = g_defs;
  g_defs = pdVar1;
  pcVar4 = Mem_Strdup("event_t");
  pdVar3->ptypename = pcVar4;
LAB_0006d48d:
                    /* Unresolved local var: delta_definition_list_t * p@[???] */
  pdVar3->pdefinition = g_EventDataDefinition;
  pdVar3->numelements = 0xe;
  return;
}


// DELTA_Load  @ 0006d050
qboolean DELTA_Load(char *name,delta_t **ppdesc,char *pszFile)

{
  uchar *pstream;
  qboolean qVar1;
  
                    /* Unresolved local var: char * pbuf@[???]
                       Unresolved local var: qboolean bret@[???] */
  pstream = COM_LoadFile(pszFile,5,(int *)0x0);
  if (pstream != (uchar *)0x0) {
    qVar1 = DELTA_ParseDescription(name,ppdesc,(char *)pstream);
    Mem_Free(pstream);
    return qVar1;
  }
  Sys_Error("DELTA_Load:  Couldn\'t load file %s\n",pszFile);
  return false;
}


// DELTA_LookupEncoder  @ 0006c290
encoder_t DELTA_LookupEncoder(char *name)

{
  encoder_t p_Var1;
  int iVar2;
  delta_encoder_s *pdVar3;
  
                    /* Unresolved local var: delta_encoder_t * p@[???] */
  p_Var1 = (encoder_t)0x0;
  pdVar3 = g_encoders;
  if (g_encoders != (delta_encoder_t *)0x0) {
    while (iVar2 = Q_stricmp(pdVar3->name,name), iVar2 != 0) {
      pdVar3 = pdVar3->next;
      if (pdVar3 == (delta_encoder_s *)0x0) {
        return (encoder_t)0x0;
      }
    }
    p_Var1 = pdVar3->conditionalencode;
  }
  return p_Var1;
}


// DELTA_LookupRegistration  @ 0006d180
delta_t ** DELTA_LookupRegistration(char *name)

{
  delta_t **ppdVar1;
  int iVar2;
  delta_registry_s *pdVar3;
  
                    /* Unresolved local var: delta_registry_t * p@[???] */
  ppdVar1 = (delta_t **)0x0;
  pdVar3 = g_deltaregistry;
  if (g_deltaregistry != (delta_registry_t *)0x0) {
    while (iVar2 = Q_stricmp(pdVar3->name,name), iVar2 != 0) {
      pdVar3 = pdVar3->next;
      if (pdVar3 == (delta_registry_s *)0x0) {
        return (delta_t **)0x0;
      }
    }
    ppdVar1 = &pdVar3->pdesc;
  }
  return ppdVar1;
}


// DELTA_MarkSendFields  @ 0006ae30
void DELTA_MarkSendFields(uchar *from,uchar *to,delta_t *pFields)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  __int32_t **pp_Var4;
  uchar *puVar5;
  uchar uVar6;
  uchar uVar7;
  int iVar8;
  uchar *puVar9;
  char *pcVar10;
  int local_38;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float f1@[???]
                       Unresolved local var: float f2@[???]
                       Unresolved local var: char * st1@[???]
                       Unresolved local var: char * st2@[???]
                       Unresolved local var: delta_description_t * pTest@[???]
                       Unresolved local var: int fieldType@[???]
                       Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int done@[???] */
  iVar1 = pFields->fieldCount;
  if (0 < iVar1) {
    iVar8 = 0;
    local_38 = 0;
    do {
      pcVar10 = pFields->pdd->fieldName + iVar8 + -4;
      uVar3 = *(uint *)pcVar10 & 0x7fffffff;
      if (uVar3 == 8) {
LAB_0006aef0:
        if (*(int *)(from + *(uint *)(pcVar10 + 0x24)) != *(int *)(to + *(uint *)(pcVar10 + 0x24)))
        {
LAB_0006af10:
          *(ushort *)&((delta_stats_t *)(pcVar10 + 0x38))->sendcount =
               (ushort)((delta_stats_t *)(pcVar10 + 0x38))->sendcount | 1;
        }
      }
      else if (uVar3 < 9) {
        if (uVar3 == 2) {
          if (*(short *)(to + *(uint *)(pcVar10 + 0x24)) !=
              *(short *)(from + *(uint *)(pcVar10 + 0x24))) goto LAB_0006af10;
        }
        else {
          if (uVar3 == 4) goto LAB_0006aef0;
          if (uVar3 != 1) goto LAB_0006ae87;
          if (from[*(uint *)(pcVar10 + 0x24)] != to[*(uint *)(pcVar10 + 0x24)]) goto LAB_0006af10;
        }
      }
      else if (uVar3 == 0x20) {
        uVar3 = *(uint *)(pcVar10 + 0x24);
        fVar2 = 100.0;
LAB_0006af69:
        if ((int)(fVar2 * *(float *)(from + uVar3)) != (int)(fVar2 * *(float *)(to + uVar3)))
        goto LAB_0006af10;
      }
      else {
        if (uVar3 < 0x21) {
          if (uVar3 == 0x10) goto LAB_0006aef0;
        }
        else {
          if (uVar3 == 0x40) {
            uVar3 = *(uint *)(pcVar10 + 0x24);
            fVar2 = 1000.0;
            goto LAB_0006af69;
          }
          if (uVar3 == 0x80) {
            puVar5 = from + *(uint *)(pcVar10 + 0x24);
            uVar7 = *puVar5;
            puVar9 = to + *(uint *)(pcVar10 + 0x24);
            if (uVar7 == '\0') {
LAB_0006b084:
              if (*puVar9 == '\0') goto LAB_0006aea0;
            }
            else {
              uVar6 = *puVar9;
              if (uVar6 != '\0') {
                pp_Var4 = __ctype_tolower_loc();
                do {
                    /* Unresolved local var: int __res@[???] */
                    /* Unresolved local var: int __res@[???] */
                  if ((*pp_Var4)[(char)uVar7] != (*pp_Var4)[(char)uVar6]) {
                    *(ushort *)&((delta_stats_t *)(pcVar10 + 0x38))->sendcount =
                         (ushort)((delta_stats_t *)(pcVar10 + 0x38))->sendcount | 1;
                    goto LAB_0006aea0;
                  }
                  uVar7 = puVar5[1];
                  puVar9 = puVar9 + 1;
                  if (uVar7 == '\0') goto LAB_0006b084;
                  uVar6 = *puVar9;
                  puVar5 = puVar5 + 1;
                } while (uVar6 != '\0');
              }
            }
            goto LAB_0006af10;
          }
        }
LAB_0006ae87:
        Con_Printf("Bad field type %i\n",uVar3);
      }
LAB_0006aea0:
      local_38 = local_38 + 1;
      iVar8 = iVar8 + 0x44;
    } while (local_38 != iVar1);
  }
  if (pFields->conditionalencode == (encoder_t)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0006b076. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pFields->conditionalencode)(pFields,from,to);
  return;
}


// DELTA_ParseDelta  @ 0006b850
/* WARNING: Type propagation algorithm not settling */

int DELTA_ParseDelta(uchar *from,uchar *to,delta_t *pFields,int nBufSize)

{
  float fVar1;
  uchar uVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  uint32 uVar6;
  uint32 uVar7;
  int iVar8;
  uint uVar9;
  uchar *puVar10;
  int iVar11;
  uint uVar12;
  uchar *puVar13;
  uint32 uVar14;
  char *pcVar15;
  int iVar16;
  uint uVar17;
  uchar *puVar18;
  int iVar19;
  float fVar20;
  uint local_4c;
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
  if (0 < (int)uVar6) {
    uVar14 = 0;
    do {
      uVar7 = MSG_ReadBits(8);
      *(char *)((int)local_24 + uVar14) = (char)uVar7;
      uVar14 = uVar14 + 1;
    } while (uVar6 != uVar14);
  }
  iVar8 = pFields->fieldCount;
  if (0 < iVar8) {
    iVar16 = 0;
    iVar11 = 0;
    do {
      pcVar15 = pFields->pdd->fieldName + iVar16 + -4;
      uVar9 = *(uint *)(pcVar15 + 0x24);
      if ((-1 < (int)uVar9) && ((int)uVar9 < nBufSize)) {
        uVar12 = *(uint *)pcVar15 & 0x7fffffff;
        if ((local_24[0x1f < iVar11] & 1 << ((byte)iVar11 & 0x1f)) == 0) {
          if (uVar12 == 8) {
            if ((int)(uVar9 + 3) < nBufSize) {
              *(undefined4 *)(to + uVar9) = *(undefined4 *)(from + uVar9);
            }
          }
          else if (uVar12 < 9) {
            if (uVar12 == 2) {
              if ((int)(uVar9 + 1) < nBufSize) {
                *(undefined2 *)(to + uVar9) = *(undefined2 *)(from + uVar9);
              }
            }
            else {
              if (uVar12 == 4) goto LAB_0006ba00;
              if (uVar12 != 1) goto LAB_0006b9af;
              to[uVar9] = from[uVar9];
            }
          }
          else if (uVar12 == 0x20) {
LAB_0006ba00:
            if ((int)(uVar9 + 3) < nBufSize) {
              *(undefined4 *)(to + uVar9) = *(undefined4 *)(from + uVar9);
            }
          }
          else {
            if (uVar12 < 0x21) {
              if (uVar12 == 0x10) goto LAB_0006ba00;
            }
            else {
              if (uVar12 == 0x40) goto LAB_0006ba00;
              if (uVar12 == 0x80) {
                puVar13 = from + uVar9;
                iVar19 = 0;
                puVar18 = to + uVar9;
                do {
                  puVar10 = puVar18;
                  uVar2 = *puVar13;
                  puVar13 = puVar13 + 1;
                  *puVar10 = uVar2;
                  if (*puVar13 == '\0') goto joined_r0x0006bff0;
                  iVar19 = iVar19 + 1;
                  puVar18 = puVar10 + 1;
                } while ((int)(*(uint *)(pcVar15 + 0x24) + iVar19) < nBufSize);
                *puVar10 = '\0';
                goto joined_r0x0006bff0;
              }
            }
LAB_0006b9af:
            Con_Printf("unparseable field type %i\n",uVar12);
          }
        }
        else {
          *(uint *)(pcVar15 + 0x40) = *(uint *)(pcVar15 + 0x40) + 1;
          uVar17 = *(uint *)pcVar15 & 0x80000000;
          if (uVar12 == 8) {
            if ((int)(uVar9 + 3) < nBufSize) {
              if (uVar17 == 0) {
                local_4c = MSG_ReadBits((int)*(float *)(pcVar15 + 0x2c));
                fVar20 = *(float *)(pcVar15 + 0x30);
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  local_4c = (uint)((float)(int)local_4c / fVar20);
                }
                fVar20 = *(float *)(pcVar15 + 0x34);
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  local_4c = (uint)((float)(int)local_4c * fVar20);
                }
              }
              else {
                local_4c = MSG_ReadSBits((int)*(float *)(pcVar15 + 0x2c));
                fVar20 = *(float *)(pcVar15 + 0x30);
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  local_4c = (uint)(longlong)ROUND((float)local_4c / fVar20);
                }
                fVar20 = *(float *)(pcVar15 + 0x34);
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  local_4c = (uint)(longlong)ROUND((float)local_4c * fVar20);
                }
              }
              *(uint *)(to + uVar9) = local_4c;
            }
          }
          else if (uVar12 < 9) {
            if (uVar12 == 2) {
              if ((int)(uVar9 + 1) < nBufSize) {
                if (uVar17 == 0) {
                  uVar6 = MSG_ReadBits((int)*(float *)(pcVar15 + 0x2c));
                  fVar20 = *(float *)(pcVar15 + 0x30);
                  uVar12 = uVar6 & 0xffff;
                  if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                    uVar12 = (int)((float)uVar12 / fVar20) & 0xffff;
                  }
                  sVar4 = (short)uVar12;
                  fVar20 = *(float *)(pcVar15 + 0x34);
                  if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                    sVar4 = (short)(int)((float)uVar12 * fVar20);
                  }
                }
                else {
                  iVar19 = MSG_ReadSBits((int)*(float *)(pcVar15 + 0x2c));
                  fVar20 = *(float *)(pcVar15 + 0x30);
                  sVar4 = (short)iVar19;
                  if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                    sVar4 = (short)(int)((float)sVar4 / fVar20);
                  }
                  fVar20 = *(float *)(pcVar15 + 0x34);
                  if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                    sVar4 = (short)(int)((float)sVar4 * fVar20);
                  }
                }
                *(short *)(to + uVar9) = sVar4;
              }
            }
            else if (uVar12 == 4) {
              if ((int)(uVar9 + 3) < nBufSize) {
                if (uVar17 == 0) {
                  uVar6 = MSG_ReadBits((int)*(float *)(pcVar15 + 0x2c));
                  fVar20 = (float)uVar6;
                }
                else {
                  iVar19 = MSG_ReadSBits((int)*(float *)(pcVar15 + 0x2c));
                  fVar20 = (float)iVar19;
                }
                fVar1 = *(float *)(pcVar15 + 0x30);
                if ((fVar1 < 0.9999) || (1.0001 < fVar1)) {
                  fVar20 = fVar20 / fVar1;
                }
                fVar1 = *(float *)(pcVar15 + 0x34);
                if ((fVar1 < 0.9999) || (1.0001 < fVar1)) {
                  fVar20 = fVar1 * fVar20;
                }
                *(float *)(to + *(uint *)(pcVar15 + 0x24)) = fVar20;
              }
            }
            else {
              if (uVar12 != 1) goto LAB_0006b9af;
              if (uVar17 == 0) {
                uVar6 = MSG_ReadBits((int)*(float *)(pcVar15 + 0x2c));
                bVar3 = (byte)uVar6;
                fVar20 = *(float *)(pcVar15 + 0x30);
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  bVar3 = (byte)(int)((float)(uVar6 & 0xff) / fVar20);
                }
                fVar20 = *(float *)(pcVar15 + 0x34);
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  bVar3 = (byte)(int)((float)bVar3 * fVar20);
                }
              }
              else {
                iVar19 = MSG_ReadSBits((int)*(float *)(pcVar15 + 0x2c));
                bVar3 = (byte)iVar19;
                fVar20 = *(float *)(pcVar15 + 0x30);
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  bVar3 = (byte)(int)((float)(short)(char)bVar3 / fVar20);
                }
                fVar20 = *(float *)(pcVar15 + 0x34);
                if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                  bVar3 = (byte)(int)((float)(short)(char)bVar3 * fVar20);
                }
              }
              to[uVar9] = bVar3;
            }
          }
          else if (uVar12 == 0x20) {
            if ((int)(uVar9 + 3) < nBufSize) {
              iVar19 = MSG_ReadSBits(8);
              *(float *)(to + *(uint *)(pcVar15 + 0x24)) =
                   ((float)(int)((float)cl.mtime[0] * 100.0) - (float)iVar19) / 100.0;
            }
          }
          else if (uVar12 < 0x21) {
            if (uVar12 != 0x10) goto LAB_0006b9af;
            if ((int)(uVar9 + 3) < nBufSize) {
              fVar20 = MSG_ReadBitAngle((int)*(float *)(pcVar15 + 0x2c));
              *(float *)(to + *(uint *)(pcVar15 + 0x24)) = fVar20;
            }
          }
          else if (uVar12 == 0x40) {
            if ((int)(uVar9 + 3) < nBufSize) {
              iVar19 = MSG_ReadSBits((int)*(float *)(pcVar15 + 0x2c));
              fVar20 = *(float *)(pcVar15 + 0x30);
              fVar1 = fVar20 * (float)cl.mtime[0] - (float)iVar19;
              if ((fVar20 < 0.9999) || (1.0001 < fVar20)) {
                fVar1 = fVar1 / fVar20;
              }
              *(float *)(to + *(uint *)(pcVar15 + 0x24)) = fVar1;
            }
          }
          else {
            if (uVar12 != 0x80) goto LAB_0006b9af;
            iVar19 = 0;
            puVar18 = to + uVar9;
            while ((int)(uVar9 + iVar19) < nBufSize) {
              uVar6 = MSG_ReadBits(8);
              *puVar18 = (uchar)uVar6;
              if ((uchar)uVar6 == '\0') goto joined_r0x0006bff0;
              puVar18 = puVar18 + 1;
              iVar19 = iVar19 + 1;
              uVar9 = *(uint *)(pcVar15 + 0x24);
            }
            if (iVar19 != 0) {
              puVar18[-1] = '\0';
            }
          }
        }
      }
joined_r0x0006bff0:
      iVar16 = iVar16 + 0x44;
      iVar11 = iVar11 + 1;
    } while (iVar11 != iVar8);
  }
  iVar8 = MSG_CurrentBit();
  return iVar8 - iVar5;
}


// DELTA_ParseDescription  @ 0006ccd0
qboolean DELTA_ParseDescription(char *name,delta_t **ppdesc,char *pstream)

{
  delta_definition_t *pdefinition;
  delta_definition_list_t *pdVar1;
  int iVar2;
  int iVar3;
  qboolean qVar4;
  delta_t *pdVar5;
  qboolean local_80;
  char local_7c [31];
  undefined1 local_5d;
  char local_5c [31];
  undefined1 local_3d;
  char *local_3c [4];
  delta_link_t *local_2c [7];
  
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: delta_link_t * links@[???]
                       Unresolved local var: delta_definition_t * pdefinition@[???]
                       Unresolved local var: char[32] encoder@[???]
                       Unresolved local var: char[32] source@[???]
                       Unresolved local var: int count@[???] */
  local_2c[0] = (delta_link_t *)0x0;
  local_7c[0] = '\0';
  if (ppdesc == (delta_t **)0x0) {
    Sys_Error("DELTA_ParseDescription with no delta_description_t\n");
    local_80 = false;
  }
  else {
    *ppdesc = (delta_t *)0x0;
    if (pstream == (char *)0x0) {
      Sys_Error("DELTA_ParseDescription with no data stream\n");
      local_80 = false;
    }
    else {
      local_3c[0] = pstream;
LAB_0006cd1c:
      local_3c[0] = COM_Parse(local_3c[0]);
      iVar2 = Q_strlen(com_token);
      if (0 < iVar2) {
        iVar2 = Q_stricmp(com_token,name);
        pdVar1 = g_defs;
        if (iVar2 == 0) {
          while( true ) {
            if (pdVar1 == (delta_definition_list_t *)0x0) goto LAB_0006d000;
            iVar2 = Q_stricmp(com_token,pdVar1->ptypename);
            if (iVar2 == 0) break;
            pdVar1 = pdVar1->next;
          }
          iVar2 = pdVar1->numelements;
          pdefinition = pdVar1->pdefinition;
          if (pdefinition == (delta_definition_t *)0x0) {
LAB_0006d000:
            Sys_Error("DELTA_ParseDescription:  Unknown data type:  %s\n",com_token);
            return false;
          }
          local_3c[0] = COM_Parse(local_3c[0]);
          iVar3 = Q_strlen(com_token);
          if (iVar3 < 1) {
            Sys_Error("DELTA_ParseDescription:  Unknown encoder :  %s\nValid values:\nnone\ngamedll funcname\nclientdll funcname\n"
                      ,com_token);
            return false;
          }
          iVar3 = Q_stricmp(com_token,"none");
          if (iVar3 != 0) {
            Q_strncpy(local_5c,com_token,0x1f);
            local_3d = 0;
            local_3c[0] = COM_Parse(local_3c[0]);
            iVar3 = Q_strlen(com_token);
            if (iVar3 < 1) {
              Sys_Error("DELTA_ParseDescription:  Expecting encoder\n");
              return false;
            }
            Q_strncpy(local_7c,com_token,0x1f);
            local_5d = 0;
          }
          while( true ) {
            local_3c[0] = COM_Parse(local_3c[0]);
            iVar3 = Q_strlen(com_token);
            if ((iVar3 < 1) || (iVar3 = Q_stricmp(com_token,"}"), iVar3 == 0)) break;
            iVar3 = Q_stricmp(com_token,"{");
            if (iVar3 != 0) {
              Con_Printf("DELTA_ParseDescription:  Expecting {, got %s\n",com_token);
              return false;
            }
            qVar4 = DELTA_ParseOneField(local_3c,local_2c,iVar2,pdefinition);
            if (qVar4 == false) {
              return false;
            }
          }
        }
        else {
          local_3c[0] = COM_Parse(local_3c[0]);
          do {
            local_3c[0] = COM_Parse(local_3c[0]);
            iVar2 = Q_strlen(com_token);
            if (iVar2 < 1) {
              Sys_Error("Error during description skip");
              break;
            }
            iVar2 = Q_stricmp(com_token,"}");
          } while (iVar2 != 0);
        }
        goto LAB_0006cd1c;
      }
      pdVar5 = DELTA_BuildFromLinks(local_2c);
      *ppdesc = pdVar5;
      iVar2 = Q_strlen(local_7c);
      local_80 = true;
      if (0 < iVar2) {
        local_80 = true;
        Q_strncpy((*ppdesc)->conditionalencodename,local_7c,0x1f);
        (*ppdesc)->conditionalencodename[0x1f] = '\0';
        (*ppdesc)->conditionalencode = (encoder_t)0x0;
      }
    }
  }
  return local_80;
}


// DELTA_ParseField  @ 0006c6d0
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
  bVar2 = false;
  if (iVar3 != 0) {
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
  Q_strncpy(pField->delta->fieldName,com_token,0x1f);
                    /* Unresolved local var: int i@[???] */
  pField->delta->fieldName[0x1f] = '\0';
  pdVar1 = pField->delta;
  if (0 < count) {
    iVar3 = 0;
    do {
      iVar5 = Q_stricmp(com_token,pdefinition->fieldName);
      if (iVar5 == 0) {
        iVar3 = pdefinition->fieldOffset;
        goto LAB_0006c7dd;
      }
      iVar3 = iVar3 + 1;
      pdefinition = pdefinition + 1;
    } while (iVar3 != count);
  }
  Sys_Error("Couldn\'t find offset for %s!!!\n",com_token);
  iVar3 = 0;
LAB_0006c7dd:
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


// DELTA_ParseOneField  @ 0006cbe0
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


// DELTA_ParseType  @ 0006c4e0
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


// DELTA_PrintStats  @ 0006d220
void DELTA_PrintStats(char *name,delta_t *p)

{
  delta_description_s *pdVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (p != (delta_t *)0x0) {
    Con_Printf("Stats for \'%s\'\n",name);
    if (0 < p->fieldCount) {
      iVar2 = 0;
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


// DELTA_RegisterDescription  @ 0006d0d0
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


// DELTA_ReverseLinks  @ 0006c300
void DELTA_ReverseLinks(delta_link_t **plinks)

{
  delta_link_s *pdVar1;
  delta_link_t *pdVar2;
  delta_link_t *pdVar3;
  
                    /* Unresolved local var: delta_link_t * p@[???]
                       Unresolved local var: delta_link_t * n@[???]
                       Unresolved local var: delta_link_t * newlist@[???] */
  pdVar2 = (delta_link_t *)0x0;
  pdVar3 = *plinks;
  while (pdVar3 != (delta_link_t *)0x0) {
    pdVar1 = pdVar3->next;
    pdVar3->next = pdVar2;
    pdVar2 = pdVar3;
    pdVar3 = pdVar1;
  }
  *plinks = pdVar2;
  return;
}


// DELTA_SetField  @ 0006aa10
void DELTA_SetField(delta_s *pFields,char *fieldname)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
                    /* Unresolved local var: delta_description_t * pTest@[DW_OP_reg7(EDI)] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  if (0 < pFields->fieldCount) {
    iVar2 = 0;
    iVar3 = 0;
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


// DELTA_SetFieldByIndex  @ 0006ab10
void DELTA_SetFieldByIndex(delta_s *pFields,int fieldNumber)

{
  pFields->pdd[fieldNumber].flags = (ushort)*(undefined4 *)&pFields->pdd[fieldNumber].flags | 1;
  return;
}


// DELTA_SetSendFlagBits  @ 0006b0b0
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
  iVar2 = 0;
  Q_memset(bits,0,8);
  iVar1 = pFields->fieldCount + -1;
  if (-1 < iVar1) {
    iVar3 = -1;
    iVar2 = iVar1 * 0x44;
    do {
      if ((pFields->pdd->fieldName[iVar2 + 0x34] & 1U) != 0) {
        if (iVar3 == -1) {
          iVar3 = iVar1;
        }
        bits[0x1f < iVar1] = bits[0x1f < iVar1] | 1 << ((byte)iVar1 & 0x1f);
      }
      iVar1 = iVar1 + -1;
      iVar2 = iVar2 + -0x44;
    } while (iVar1 != -1);
    iVar2 = (iVar3 >> 3) + 1;
  }
  *bytecount = iVar2;
  return;
}


// DELTA_Shutdown  @ 0006d5f0
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
  g_encoders = (delta_encoder_t *)0x0;
  p_00 = g_defs;
                    /* Unresolved local var: delta_definition_list_t * p@[???]
                       Unresolved local var: delta_definition_list_t * n@[???] */
  while (p_00 != (delta_definition_list_t *)0x0) {
    pdVar2 = p_00->next;
    Mem_Free(p_00->ptypename);
    Mem_Free(p_00);
    p_00 = pdVar2;
  }
                    /* Unresolved local var: delta_registry_t * p@[???]
                       Unresolved local var: delta_registry_t * n@[???] */
  g_defs = (delta_definition_list_t *)0x0;
  p_01 = g_deltaregistry;
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


// DELTA_SkipDescription  @ 0006cb60
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


// DELTA_TestDelta  @ 0006ab80
int DELTA_TestDelta(uchar *from,uchar *to,delta_t *pFields)

{
  int iVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  __int32_t **pp_Var8;
  int iVar9;
  uchar uVar10;
  uchar *puVar11;
  uchar *puVar12;
  char *pcVar13;
  int local_30;
  int local_2c;
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
  local_2c = 0;
  iVar1 = pFields->fieldCount;
  if (0 < iVar1) {
    local_30 = 0;
    local_24 = -1;
    iVar6 = 0;
    do {
      while( true ) {
        iVar9 = iVar6;
        pcVar13 = pFields->pdd->fieldName + local_30 + -4;
        uVar7 = *(uint *)pcVar13 & 0x7fffffff;
        iVar6 = local_2c;
        if (uVar7 == 8) break;
        if (uVar7 < 9) {
          if (uVar7 == 2) {
            if (*(short *)(to + *(uint *)(pcVar13 + 0x24)) !=
                *(short *)(from + *(uint *)(pcVar13 + 0x24))) {
LAB_0006acd8:
              iVar6 = local_2c + (int)*(float *)(pcVar13 + 0x2c);
              local_24 = iVar9;
            }
          }
          else {
            if (uVar7 == 4) break;
            if (uVar7 != 1) goto LAB_0006abcf;
            if (from[*(uint *)(pcVar13 + 0x24)] != to[*(uint *)(pcVar13 + 0x24)]) goto LAB_0006acd8;
          }
        }
        else if (uVar7 == 0x20) {
          uVar7 = *(uint *)(pcVar13 + 0x24);
          fVar2 = 100.0;
          fVar3 = *(float *)(from + uVar7) * 100.0;
LAB_0006ac92:
          if ((int)fVar3 != (int)(fVar2 * *(float *)(to + uVar7))) goto LAB_0006ac43;
        }
        else {
          if (uVar7 < 0x21) {
            if (uVar7 == 0x10) break;
          }
          else {
            if (uVar7 == 0x40) {
              uVar7 = *(uint *)(pcVar13 + 0x24);
              fVar2 = 1000.0;
              fVar3 = *(float *)(from + uVar7) * 1000.0;
              goto LAB_0006ac92;
            }
            if (uVar7 == 0x80) {
              puVar12 = to + *(uint *)(pcVar13 + 0x24);
              uVar10 = *puVar12;
              if (uVar10 != '\0') {
                puVar11 = from + *(uint *)(pcVar13 + 0x24);
                bVar4 = false;
                iVar6 = 0;
                do {
                  while (iVar5 = iVar6, !bVar4) {
                    /* Unresolved local var: int __res@[???] */
                    /* Unresolved local var: int __res@[???] */
                    pp_Var8 = __ctype_tolower_loc();
                    if ((*pp_Var8)[(char)*puVar11] != (*pp_Var8)[(char)uVar10]) {
                      bVar4 = true;
                      *(ushort *)&((delta_stats_t *)(pcVar13 + 0x38))->sendcount =
                           (ushort)((delta_stats_t *)(pcVar13 + 0x38))->sendcount | 1;
                    }
                    puVar12 = puVar12 + 1;
                    puVar11 = puVar11 + 1;
                    uVar10 = *puVar12;
                    iVar6 = iVar5 + 8;
                    if (uVar10 == '\0') goto LAB_0006adaa;
                  }
                  puVar12 = puVar12 + 1;
                  puVar11 = puVar11 + 1;
                  uVar10 = *puVar12;
                  bVar4 = true;
                  iVar6 = iVar5 + 8;
                } while (uVar10 != '\0');
LAB_0006adaa:
                iVar6 = local_2c + iVar5 + 0x10;
                if (!bVar4) {
                  iVar6 = local_2c;
                }
              }
              goto LAB_0006abe7;
            }
          }
LAB_0006abcf:
          Con_Printf("Bad field type %i\n",uVar7);
        }
LAB_0006abe7:
        local_2c = iVar6;
        local_30 = local_30 + 0x44;
        iVar6 = iVar9 + 1;
        if (iVar9 + 1 == iVar1) goto LAB_0006ac5a;
      }
      if (*(int *)(from + *(uint *)(pcVar13 + 0x24)) == *(int *)(to + *(uint *)(pcVar13 + 0x24)))
      goto LAB_0006abe7;
LAB_0006ac43:
      local_2c = local_2c + (int)*(float *)(pcVar13 + 0x2c);
      local_30 = local_30 + 0x44;
      iVar6 = iVar9 + 1;
      local_24 = iVar9;
    } while (iVar9 + 1 != iVar1);
LAB_0006ac5a:
    if (local_24 != -1) {
      local_2c = local_2c + 8 + (local_24 >> 3) * 8;
    }
  }
  return local_2c;
}


// DELTA_UnsetField  @ 0006aa90
void DELTA_UnsetField(delta_s *pFields,char *fieldname)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
                    /* Unresolved local var: delta_description_t * pTest@[DW_OP_reg7(EDI)] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  if (0 < pFields->fieldCount) {
    iVar2 = 0;
    iVar3 = 0;
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


// DELTA_UnsetFieldByIndex  @ 0006ab30
void DELTA_UnsetFieldByIndex(delta_s *pFields,int fieldNumber)

{
  pFields->pdd[fieldNumber].flags = (ushort)*(undefined4 *)&pFields->pdd[fieldNumber].flags & 0xfffe
  ;
  return;
}


// DELTA_WriteDelta  @ 0006b5c0
int DELTA_WriteDelta(uchar *from,uchar *to,qboolean force,delta_t *pFields,_func_void *callback)

{
  byte *pbVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  uint32 uVar7;
  uint32 data;
  int iVar8;
  uint local_24 [5];
  
                    /* Unresolved local var: int sendfields@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  if (0 < pFields->fieldCount) {
    iVar4 = 0;
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      pcVar2 = pFields->pdd->fieldName + iVar4 + 0x34;
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      iVar4 = iVar4 + 0x44;
    } while (iVar3 < pFields->fieldCount);
  }
  DELTA_MarkSendFields(from,to,pFields);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: delta_description_t * pitem@[???] */
  iVar3 = pFields->fieldCount;
  if (0 < iVar3) {
    iVar5 = 0;
    iVar8 = 0;
    iVar4 = 0;
    do {
      if ((pFields->pdd->fieldName[iVar5 + 0x34] & 1U) != 0) {
        pcVar2 = pFields->pdd->fieldName + iVar5 + 0x38;
        *(int *)pcVar2 = *(int *)pcVar2 + 1;
        iVar8 = iVar8 + 1;
        iVar3 = pFields->fieldCount;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x44;
    } while (iVar4 < iVar3);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int bytecount@[???]
                       Unresolved local var: int[2] bits@[???]
                       Unresolved local var: uchar * pdest@[???]
                       Unresolved local var: int fieldCount@[???] */
    if (iVar8 != 0) goto LAB_0006b658;
  }
  if (force == false) {
    return 1;
  }
LAB_0006b658:
                    /* Unresolved local var: delta_description_t * pTest@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int lastbit@[???]
                       Unresolved local var: int bitnumber@[???]
                       Unresolved local var: int fieldCount@[???]
                       Unresolved local var: int bytenumber@[???] */
  Q_memset(local_24,0,8);
  iVar3 = pFields->fieldCount + -1;
  if (iVar3 < 0) {
    data = 0;
  }
  else {
    psVar6 = &pFields->pdd[iVar3].flags;
    iVar4 = -1;
    do {
      if ((*psVar6 & 1) != 0) {
        if (iVar4 == -1) {
          iVar4 = iVar3;
        }
        local_24[0x1f < iVar3] = local_24[0x1f < iVar3] | 1 << ((byte)iVar3 & 0x1f);
      }
      iVar3 = iVar3 + -1;
      psVar6 = psVar6 + -0x22;
    } while (iVar3 != -1);
    data = (iVar4 >> 3) + 1;
  }
  if (callback != (_func_void *)0x0) {
    (*callback)();
  }
  MSG_WriteBits(data,3);
  if (0 < (int)data) {
    uVar7 = 0;
    do {
      pbVar1 = (byte *)((int)local_24 + uVar7);
      uVar7 = uVar7 + 1;
      MSG_WriteBits((uint)*pbVar1,8);
    } while (uVar7 != data);
  }
  DELTA_WriteMarkedFields(from,to,pFields);
  return 1;
}


// DELTA_WriteMarkedFields  @ 0006b130
void DELTA_WriteMarkedFields(uchar *from,uchar *to,delta_t *pFields)

{
  uchar uVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  uchar *puVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  uint32 local_34;
  
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
    iVar8 = 0;
    iVar7 = 0;
    do {
      while (pcVar3 = pFields->pdd->fieldName + iVar8 + -4,
            (((delta_stats_t *)(pcVar3 + 0x38))->sendcount & 1) != 0) {
        uVar4 = *(uint *)pcVar3 & 0x7fffffff;
        uVar5 = *(uint *)pcVar3 & 0x80000000;
        if (uVar4 == 8) {
          fVar9 = *(float *)(pcVar3 + 0x30);
          local_34 = *(uint32 *)(to + *(uint *)(pcVar3 + 0x24));
          if (uVar5 == 0) {
            if ((fVar9 < 0.9999) || (1.0001 < fVar9)) {
              local_34 = (uint32)(longlong)ROUND((float)local_34 * fVar9);
            }
            MSG_WriteBits(local_34,(int)*(float *)(pcVar3 + 0x2c));
          }
          else {
            if ((fVar9 < 0.9999) || (1.0001 < fVar9)) {
              local_34 = (uint32)((float)(int)local_34 * fVar9);
            }
            MSG_WriteSBits(local_34,(int)*(float *)(pcVar3 + 0x2c));
          }
          break;
        }
        if (uVar4 < 9) {
          if (uVar4 == 2) {
            if (uVar5 == 0) {
              MSG_WriteBits((int)((float)*(ushort *)(to + *(uint *)(pcVar3 + 0x24)) *
                                 *(float *)(pcVar3 + 0x30)) & 0xffff,(int)*(float *)(pcVar3 + 0x2c))
              ;
            }
            else {
              MSG_WriteSBits((int)(short)(int)((float)*(short *)(to + *(uint *)(pcVar3 + 0x24)) *
                                              *(float *)(pcVar3 + 0x30)),
                             (int)*(float *)(pcVar3 + 0x2c));
            }
          }
          else if (uVar4 == 4) {
            fVar9 = *(float *)(pcVar3 + 0x2c);
            local_34 = (uint32)(longlong)
                               ROUND(*(float *)(to + *(uint *)(pcVar3 + 0x24)) *
                                     *(float *)(pcVar3 + 0x30));
            if (uVar5 != 0) goto LAB_0006b33a;
            MSG_WriteBits(local_34,(int)fVar9);
          }
          else {
            if (uVar4 != 1) goto LAB_0006b169;
            if (uVar5 == 0) {
              MSG_WriteBits((int)((float)to[*(uint *)(pcVar3 + 0x24)] * *(float *)(pcVar3 + 0x30)) &
                            0xff,(int)*(float *)(pcVar3 + 0x2c));
            }
            else {
              MSG_WriteSBits((int)(char)(int)((float)(short)(char)to[*(uint *)(pcVar3 + 0x24)] *
                                             *(float *)(pcVar3 + 0x30)),
                             (int)*(float *)(pcVar3 + 0x2c));
            }
          }
          break;
        }
        if (uVar4 == 0x20) {
          fVar9 = 1.12104e-44;
          local_34 = (int)((float)sv.time * 100.0) -
                     (int)(*(float *)(to + *(uint *)(pcVar3 + 0x24)) * 100.0);
LAB_0006b33a:
          MSG_WriteSBits(local_34,(int)fVar9);
          break;
        }
        if (0x20 < uVar4) {
          if (uVar4 == 0x40) {
            MSG_WriteSBits((int)(*(float *)(pcVar3 + 0x30) * (float)sv.time) -
                           (int)(*(float *)(pcVar3 + 0x30) *
                                *(float *)(to + *(uint *)(pcVar3 + 0x24))),
                           (int)*(float *)(pcVar3 + 0x2c));
          }
          else {
            if (uVar4 != 0x80) goto LAB_0006b169;
            puVar6 = to + *(uint *)(pcVar3 + 0x24);
            if (puVar6 != (uchar *)0x0) {
              uVar1 = *puVar6;
              while (uVar1 != '\0') {
                MSG_WriteBits((int)(char)uVar1,8);
                puVar6 = puVar6 + 1;
                if (puVar6 == (uchar *)0x0) break;
                uVar1 = *puVar6;
              }
            }
            MSG_WriteBits(0,8);
          }
          break;
        }
        if (uVar4 != 0x10) {
LAB_0006b169:
          Con_Printf("unknown send field type\n");
          break;
        }
        iVar7 = iVar7 + 1;
        iVar8 = iVar8 + 0x44;
        MSG_WriteBitAngle(*(float *)(to + *(uint *)(pcVar3 + 0x24)),(int)*(float *)(pcVar3 + 0x2c));
        if (iVar7 == iVar2) {
          return;
        }
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x44;
    } while (iVar7 != iVar2);
  }
  return;
}


