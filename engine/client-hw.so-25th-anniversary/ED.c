// ED_Alloc  @ 000d5140
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

edict_t * ED_Alloc(void)

{
  void *p;
  edict_t *peVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * e@[???] */
  iVar2 = svs.maxclients + 1;
  if (iVar2 < sv.num_edicts) {
    peVar1 = sv.edicts + iVar2;
    do {
      if ((peVar1->free != false) &&
         (((double)peVar1->freetime < 2.0 || (0.5 < sv.time - (double)peVar1->freetime))))
      goto LAB_000d51d4;
      iVar2 = iVar2 + 1;
      peVar1 = peVar1 + 1;
    } while (iVar2 != sv.num_edicts);
  }
  if (sv.max_edicts <= iVar2) {
    if (sv.max_edicts == 0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("ED_Alloc: No edicts yet");
    }
                    /* WARNING: Subroutine does not return */
    Sys_Error("ED_Alloc: no free edicts");
  }
  sv.num_edicts = sv.num_edicts + 1;
  peVar1 = sv.edicts + iVar2;
LAB_000d51d4:
  Q_memset(&peVar1->v,0,0x2a4);
  p = peVar1->pvPrivateData;
  peVar1->free = false;
  if (p != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(peVar1);
      p = peVar1->pvPrivateData;
    }
    Mem_Free(p);
  }
  peVar1->pvPrivateData = (void *)0x0;
  (peVar1->v).pContainingEntity = peVar1;
  return peVar1;
}


// ED_ClearEdict  @ 000d50e0
void ED_ClearEdict(edict_t *e)

{
  void *p;
  
  Q_memset(&e->v,0,0x2a4);
  p = e->pvPrivateData;
  e->free = false;
  if (p != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(e);
      p = e->pvPrivateData;
    }
    Mem_Free(p);
  }
  e->pvPrivateData = (void *)0x0;
  (e->v).pContainingEntity = e;
  return;
}


// ED_Count  @ 000d5360
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ED_Count(void)

{
  edict_t *peVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: int active@[???]
                       Unresolved local var: int models@[???]
                       Unresolved local var: int solid@[???]
                       Unresolved local var: int step@[???] */
  if (sv.num_edicts < 1) {
    iVar2 = 0;
    iVar4 = 0;
    iVar5 = 0;
    iVar3 = 0;
  }
  else {
    iVar4 = 0;
    iVar5 = 0;
    iVar2 = 0;
    iVar3 = 0;
    peVar1 = sv.edicts;
    do {
      if (peVar1->free == false) {
        iVar3 = iVar3 + 1;
        iVar4 = (iVar4 + 1) - (uint)((peVar1->v).solid == 0);
        iVar5 = (iVar5 + 1) - (uint)((peVar1->v).model == 0);
        iVar2 = iVar2 + (uint)((peVar1->v).movetype == 4);
      }
      peVar1 = peVar1 + 1;
    } while (sv.edicts + sv.num_edicts != peVar1);
  }
  Con_Printf("num_edicts:%3i\n",sv.num_edicts);
  Con_Printf("active    :%3i\n",iVar3);
  Con_Printf("view      :%3i\n",iVar5);
  Con_Printf("touch     :%3i\n",iVar4);
  Con_Printf("step      :%3i\n",iVar2);
  return;
}


// ED_Free  @ 000d5260
void ED_Free(edict_t *ed)

{
  float fVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  void *p;
  
  if (ed->free != false) {
    return;
  }
  SV_UnlinkEdict(ed);
  p = ed->pvPrivateData;
  if (p != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(ed);
      p = ed->pvPrivateData;
    }
    Mem_Free(p);
  }
  ed->serialnumber = ed->serialnumber + 1;
  ed->free = true;
  vVar2 = vec3_origin[0];
  (ed->v).flags = 0;
  (ed->v).origin[0] = vVar2;
  vVar3 = vec3_origin[1];
  (ed->v).colormap = 0;
  (ed->v).origin[1] = vVar3;
  vVar4 = vec3_origin[2];
  (ed->v).skin = 0;
  (ed->v).origin[2] = vVar4;
  (ed->v).angles[0] = vVar2;
  (ed->v).angles[1] = vVar3;
  (ed->v).angles[2] = vVar4;
  fVar1 = (float)sv.time;
  ed->pvPrivateData = (void *)0x0;
  (ed->v).model = 0;
  (ed->v).takedamage = 0.0;
  (ed->v).modelindex = 0;
  (ed->v).frame = 0.0;
  (ed->v).scale = 0.0;
  (ed->v).gravity = 0.0;
  (ed->v).nextthink = -1.0;
  (ed->v).solid = 0;
  ed->freetime = fVar1;
  return;
}


// ED_LoadFromFile  @ 000d5530
void ED_LoadFromFile(char *data)

{
  float fVar1;
  edict_t *peVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  bool bVar6;
  char *szInputStream;
  void *pvVar7;
  int iVar8;
  edict_t *pEdict;
  int iVar9;
  
                    /* Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: int inhibit@[???] */
  iVar9 = 0;
  pEdict = (edict_t *)0x0;
  gGlobalVariables.time = (float)sv.time;
LAB_000d5550:
  do {
    while( true ) {
      do {
        szInputStream = COM_Parse(data);
        peVar2 = pEdict;
        pEdict = sv.edicts;
        while( true ) {
          sv.edicts = pEdict;
          if (szInputStream == (char *)0x0) {
            Con_DPrintf("%i entities inhibited\n",iVar9);
            return;
          }
          if (com_token[0] != '{') {
                    /* WARNING: Subroutine does not return */
            Host_Error("ED_LoadFromFile: found %s when expecting {",com_token);
          }
          if (peVar2 == (edict_t *)0x0) {
            pvVar7 = pEdict->pvPrivateData;
            if (pvVar7 != (void *)0x0) {
              if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
                (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(pEdict);
                pvVar7 = pEdict->pvPrivateData;
              }
              Mem_Free(pvVar7);
            }
            pEdict->pvPrivateData = (void *)0x0;
            (pEdict->v).pContainingEntity = pEdict;
          }
          else {
            pEdict = ED_Alloc();
          }
                    /* Unresolved local var: qboolean init@[???]
                       Unresolved local var: bool[256] keyname@[???]
                       Unresolved local var: int n@[???]
                       Unresolved local var: ENTITYINIT pEntityInit@[???]
                       Unresolved local var: char * className@[???]
                       Unresolved local var: KeyValueData kvd@[???]
                       Unresolved local var: bool bRes@[???] */
          if (pEdict != sv.edicts) {
            Q_memset(&pEdict->v,0,0x2a4);
          }
          (pEdict->v).pContainingEntity = pEdict;
          bVar6 = SuckOutClassname(szInputStream,pEdict);
          if (bVar6) break;
          pEdict->serialnumber = pEdict->serialnumber + 1;
          pEdict->free = true;
          szInputStream = COM_Parse(szInputStream);
          peVar2 = pEdict;
          pEdict = sv.edicts;
        }
        data = ED_ParseEdict(szInputStream,pEdict);
      } while (pEdict->free != false);
      if ((deathmatch.value == 0.0) || (((pEdict->v).spawnflags & 0x800) == 0)) break;
      SV_UnlinkEdict(pEdict);
      pvVar7 = pEdict->pvPrivateData;
      if (pvVar7 != (void *)0x0) {
        if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
          (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(pEdict);
          pvVar7 = pEdict->pvPrivateData;
        }
        Mem_Free(pvVar7);
      }
      pEdict->serialnumber = pEdict->serialnumber + 1;
      pEdict->free = true;
      vVar3 = vec3_origin[0];
      iVar9 = iVar9 + 1;
      (pEdict->v).modelindex = 0;
      (pEdict->v).origin[0] = vVar3;
      vVar4 = vec3_origin[1];
      (pEdict->v).colormap = 0;
      (pEdict->v).origin[1] = vVar4;
      vVar5 = vec3_origin[2];
      (pEdict->v).skin = 0;
      (pEdict->v).origin[2] = vVar5;
      (pEdict->v).angles[0] = vVar3;
      (pEdict->v).angles[1] = vVar4;
      (pEdict->v).angles[2] = vVar5;
      fVar1 = (float)sv.time;
      pEdict->pvPrivateData = (void *)0x0;
      (pEdict->v).flags = 0;
      (pEdict->v).model = 0;
      (pEdict->v).takedamage = 0.0;
      (pEdict->v).frame = 0.0;
      (pEdict->v).scale = 0.0;
      (pEdict->v).gravity = 0.0;
      (pEdict->v).nextthink = -1.0;
      (pEdict->v).solid = 0;
      pEdict->freetime = fVar1;
    }
    if ((pEdict->v).classname != 0) goto LAB_000d5820;
    Con_Printf("No classname for:\n");
  } while (pEdict->free != false);
  goto LAB_000d573c;
LAB_000d5820:
  iVar8 = (*gEntityInterface.pfnSpawn)(pEdict);
  if (((iVar8 < 0) || (((pEdict->v).flags & 0x40000000) != 0)) && (pEdict->free == false)) {
LAB_000d573c:
    SV_UnlinkEdict(pEdict);
    pvVar7 = pEdict->pvPrivateData;
    if (pvVar7 != (void *)0x0) {
      if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr *)0x0) {
        (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(pEdict);
        pvVar7 = pEdict->pvPrivateData;
      }
      Mem_Free(pvVar7);
    }
    pEdict->serialnumber = pEdict->serialnumber + 1;
    pEdict->free = true;
    vVar3 = vec3_origin[0];
    (pEdict->v).flags = 0;
    (pEdict->v).origin[0] = vVar3;
    vVar4 = vec3_origin[1];
    (pEdict->v).colormap = 0;
    (pEdict->v).origin[1] = vVar4;
    vVar5 = vec3_origin[2];
    (pEdict->v).skin = 0;
    (pEdict->v).origin[2] = vVar5;
    (pEdict->v).angles[0] = vVar3;
    (pEdict->v).angles[1] = vVar4;
    (pEdict->v).angles[2] = vVar5;
    fVar1 = (float)sv.time;
    pEdict->pvPrivateData = (void *)0x0;
    (pEdict->v).model = 0;
    (pEdict->v).takedamage = 0.0;
    (pEdict->v).modelindex = 0;
    (pEdict->v).frame = 0.0;
    (pEdict->v).scale = 0.0;
    (pEdict->v).gravity = 0.0;
    (pEdict->v).nextthink = -1.0;
    (pEdict->v).solid = 0;
    pEdict->freetime = fVar1;
  }
  goto LAB_000d5550;
}


// ED_NewString  @ 000d5430
char * ED_NewString(char *string)

{
  int size;
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: char * new_s@[DW_OP_reg0(EAX)]
                       Unresolved local var: char * new_p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int l@[???] */
  iVar2 = Q_strlen(string);
  size = iVar2 + 1;
  pcVar3 = Hunk_Alloc(size);
  if (0 < size) {
    iVar5 = 0;
    pcVar4 = pcVar3 + 1;
    do {
      while ((pcVar1 = string + iVar5, *pcVar1 != '\\' || (iVar2 <= iVar5))) {
        iVar5 = iVar5 + 1;
        pcVar4[-1] = *pcVar1;
        pcVar4 = pcVar4 + 1;
        if (size <= iVar5) {
          return pcVar3;
        }
      }
      if (string[iVar5 + 1] == 'n') {
        pcVar4[-1] = '\n';
      }
      else {
        pcVar4[-1] = '\\';
      }
      iVar5 = iVar5 + 2;
      pcVar4 = pcVar4 + 1;
    } while (iVar5 < size);
  }
  return pcVar3;
}


// ED_ParseEdict  @ 000d4dc0
char * __regparm3 ED_ParseEdict(char *data,edict_t *ent)

{
  bool bVar1;
  code *pcVar2;
  char *data_00;
  int iVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  float fVar5;
  KeyValueData local_130;
  char local_120 [255];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: qboolean init@[???]
                       Unresolved local var: bool[256] keyname@[???]
                       Unresolved local var: int n@[???]
                       Unresolved local var: ENTITYINIT pEntityInit@[???]
                       Unresolved local var: char * className@[???]
                       Unresolved local var: KeyValueData kvd@[???]
                       Unresolved local var: bool bRes@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar2 = (code *)GetEntityInit(pr_strings + (ent->v).classname);
  if (pcVar2 == (code *)0x0) {
    pcVar2 = (code *)GetEntityInit(0x2583f6);
    if (pcVar2 == (code *)0x0) {
      Con_DPrintf("Can\'t init %s\n",pr_strings + (ent->v).classname);
      bVar1 = false;
    }
    else {
      (*pcVar2)(&ent->v);
      local_130.szClassName = "custom";
      local_130.szKeyName = "customclass";
      local_130.fHandled = 0;
      local_130.szValue = pr_strings + (ent->v).classname;
      (*gEntityInterface.pfnKeyValue)(ent,&local_130);
      bVar1 = true;
    }
  }
  else {
    (*pcVar2)(&ent->v);
    bVar1 = true;
  }
LAB_000d4e20:
  data_00 = COM_Parse(data);
  if (com_token[0] == '}') {
    if (!bVar1) {
      ent->serialnumber = ent->serialnumber + 1;
      ent->free = true;
    }
    if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
      return data_00;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  if (data_00 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("ED_ParseEntity: EOF without closing brace");
  }
  Q_strncpy(local_120,com_token,0xff);
  local_21 = 0;
  iVar3 = Q_strlen(local_120);
  if ((iVar3 != 0) && (local_120[iVar3 + -1] == ' ')) {
    pcVar4 = local_120 + iVar3 + -1;
    do {
      *pcVar4 = '\0';
      if (local_120 == pcVar4) break;
      pcVar4 = pcVar4 + -1;
    } while (*pcVar4 == ' ');
  }
  data = COM_Parse(data_00);
  if (data == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Host_Error("ED_ParseEntity: EOF without closing brace");
  }
  if (com_token[0] == '}') {
                    /* WARNING: Subroutine does not return */
    Host_Error("ED_ParseEntity: closing brace without data");
  }
  if (pr_strings + (ent->v).classname != (char *)0x0) goto code_r0x000d4eba;
  goto LAB_000d4ed3;
code_r0x000d4eba:
  iVar3 = Q_strcmp(pr_strings + (ent->v).classname,com_token);
  if (iVar3 != 0) {
LAB_000d4ed3:
    iVar3 = Q_strcmp(local_120,"angle");
    if (iVar3 == 0) {
                    /* Unresolved local var: float y@[???] */
      fVar5 = Q_atof(com_token);
      if (fVar5 < 0.0) {
        if ((int)fVar5 == -1) {
          builtin_strncpy(com_token,"-90 0 0",8);
        }
        else {
          builtin_strncpy(com_token,"90 0",4);
          com_token[4] = ' ';
          com_token[5] = '0';
          com_token[6] = '\0';
        }
      }
      else {
        __snprintf_chk(com_token,0x800,1,0x800,"%f %f %f",(double)(ent->v).angles[0],(double)fVar5,
                       (double)(ent->v).angles[2]);
      }
      Q_strcpy(local_120,"angles");
    }
    local_130.szValue = com_token;
    local_130.szClassName = pr_strings + (ent->v).classname;
    local_130.fHandled = 0;
    local_130.szKeyName = local_120;
    (*gEntityInterface.pfnKeyValue)(ent,&local_130);
  }
  goto LAB_000d4e20;
}


// ED_ParseEdict  @ 000d54b0
char * ED_ParseEdict(char *data,edict_t *ent)

{
  bool bVar1;
  char *pcVar2;
  
                    /* Unresolved local var: qboolean init@[???]
                       Unresolved local var: bool[256] keyname@[???]
                       Unresolved local var: int n@[???]
                       Unresolved local var: ENTITYINIT pEntityInit@[???]
                       Unresolved local var: char * className@[???]
                       Unresolved local var: KeyValueData kvd@[???]
                       Unresolved local var: bool bRes@[???] */
  if (sv.edicts != ent) {
    Q_memset(&ent->v,0,0x2a4);
  }
  (ent->v).pContainingEntity = ent;
  bVar1 = SuckOutClassname(data,ent);
  if (!bVar1) {
    ent->serialnumber = ent->serialnumber + 1;
    ent->free = true;
    return data;
  }
  pcVar2 = ED_ParseEdict(data,ent);
  return pcVar2;
}


