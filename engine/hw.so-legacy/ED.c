// ED_Alloc  @ 001389f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

edict_t_conflict * ED_Alloc(void)

{
  void *pvVar1;
  edict_t_conflict *peVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t.conflict * e@[???] */
  iVar3 = svs.maxclients + 1;
  if (iVar3 < sv.num_edicts) {
    peVar2 = sv.edicts + iVar3;
    do {
      if ((peVar2->free != 0) &&
         (((double)peVar2->freetime < 2.0 || (0.5 < sv.time - (double)peVar2->freetime)))) {
        Q_memset(&peVar2->v,0,0x2a4);
        pvVar1 = peVar2->pvPrivateData;
        peVar2->free = 0;
        if (pvVar1 != (void *)0x0) {
          if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
            (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(peVar2);
            pvVar1 = peVar2->pvPrivateData;
          }
          Mem_Free(pvVar1);
        }
        peVar2->pvPrivateData = (void *)0x0;
        (peVar2->v).pContainingEntity = peVar2;
        return peVar2;
      }
      iVar3 = iVar3 + 1;
      peVar2 = peVar2 + 1;
    } while (iVar3 != sv.num_edicts);
  }
  if (sv.max_edicts <= iVar3) {
    if (sv.max_edicts == 0) {
      Sys_Error("ED_Alloc: No edicts yet");
    }
    Sys_Error("ED_Alloc: no free edicts");
  }
  sv.num_edicts = sv.num_edicts + 1;
  peVar2 = sv.edicts + iVar3;
  Q_memset(&peVar2->v,0,0x2a4);
  pvVar1 = peVar2->pvPrivateData;
  peVar2->free = 0;
  if (pvVar1 != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(peVar2);
      pvVar1 = peVar2->pvPrivateData;
    }
    Mem_Free(pvVar1);
  }
  peVar2->pvPrivateData = (void *)0x0;
  (peVar2->v).pContainingEntity = peVar2;
  return peVar2;
}


// ED_ClearEdict  @ 00138990
void ED_ClearEdict(edict_t_conflict *e)

{
  void *p;
  
  Q_memset(&e->v,0,0x2a4);
  p = e->pvPrivateData;
  e->free = 0;
  if (p != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(e);
      p = e->pvPrivateData;
    }
    Mem_Free(p);
  }
  e->pvPrivateData = (void *)0x0;
  (e->v).pContainingEntity = e;
  return;
}


// ED_Count  @ 00138b90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ED_Count(void)

{
  int iVar1;
  int iVar2;
  edict_t_conflict *peVar3;
  int iVar4;
  int iVar5;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: int active@[???]
                       Unresolved local var: int models@[???]
                       Unresolved local var: int solid@[???]
                       Unresolved local var: int step@[???] */
  if (sv.num_edicts < 1) {
    iVar4 = 0;
    local_20 = 0;
    iVar5 = 0;
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    local_20 = 0;
    iVar5 = 0;
    iVar1 = 0;
    iVar4 = 0;
    peVar3 = sv.edicts;
    do {
      if (peVar3->free == 0) {
        iVar5 = iVar5 + 1;
        iVar2 = (iVar2 + 1) - (uint)((peVar3->v).solid == 0);
        iVar4 = (iVar4 + 1) - (uint)((peVar3->v).model == 0);
        local_20 = local_20 + (uint)((peVar3->v).movetype == 4);
      }
      iVar1 = iVar1 + 1;
      peVar3 = peVar3 + 1;
    } while (iVar1 != sv.num_edicts);
  }
  Con_Printf("num_edicts:%3i\n",sv.num_edicts);
  Con_Printf("active    :%3i\n",iVar5);
  Con_Printf("view      :%3i\n",iVar4);
  Con_Printf("touch     :%3i\n",iVar2);
  Con_Printf("step      :%3i\n",local_20);
  return;
}


// ED_Free  @ 001388a0
void __regparm3 ED_Free(edict_t_conflict *ed)

{
  float fVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  void *p;
  
  SV_UnlinkEdict(ed);
  p = ed->pvPrivateData;
  if (p != (void *)0x0) {
    if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
      (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(ed);
      p = ed->pvPrivateData;
    }
    Mem_Free(p);
  }
  ed->serialnumber = ed->serialnumber + 1;
  (ed->v).flags = 0;
  ed->free = 1;
  (ed->v).colormap = 0;
  fVar1 = (float)sv.time;
  (ed->v).skin = 0;
  vVar4 = vec3_origin[2];
  ed->freetime = fVar1;
  (ed->v).model = 0;
  vVar3 = vec3_origin[1];
  (ed->v).modelindex = 0;
  vVar2 = vec3_origin[0];
  ed->pvPrivateData = (void *)0x0;
  (ed->v).origin[2] = vVar4;
  (ed->v).angles[2] = vVar4;
  (ed->v).takedamage = 0.0;
  (ed->v).frame = 0.0;
  (ed->v).scale = 0.0;
  (ed->v).gravity = 0.0;
  (ed->v).origin[0] = vVar2;
  (ed->v).origin[1] = vVar3;
  (ed->v).angles[0] = vVar2;
  (ed->v).angles[1] = vVar3;
  (ed->v).nextthink = -1.0;
  (ed->v).solid = 0;
  return;
}


// ED_Free  @ 00138b70
void ED_Free(edict_t_conflict *ed)

{
  if (ed->free != 0) {
    return;
  }
  ED_Free(ed);
  return;
}


// ED_LoadFromFile  @ 00139100
void ED_LoadFromFile(char *data)

{
  float fVar1;
  edict_t_conflict *peVar2;
  vec_t vVar3;
  vec_t vVar4;
  vec_t vVar5;
  char *data_00;
  void *pvVar6;
  int iVar7;
  edict_t_conflict *ent;
  int iVar8;
  
                    /* Unresolved local var: edict_t.conflict * ent@[???]
                       Unresolved local var: int inhibit@[???] */
  iVar8 = 0;
  ent = (edict_t_conflict *)0x0;
  gGlobalVariables.time = (float)sv.time;
LAB_00139120:
  do {
    data_00 = COM_Parse(data);
    peVar2 = ent;
    while( true ) {
      if (data_00 == (char *)0x0) {
        Con_DPrintf("%i entities inhibited\n",iVar8);
        return;
      }
      if (com_token[0] != '{') {
        Host_Error("ED_LoadFromFile: found %s when expecting {",com_token);
      }
      ent = sv.edicts;
      if (peVar2 == (edict_t_conflict *)0x0) {
        pvVar6 = (sv.edicts)->pvPrivateData;
        if (pvVar6 != (void *)0x0) {
          if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
            (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(sv.edicts);
            pvVar6 = ent->pvPrivateData;
          }
          Mem_Free(pvVar6);
        }
        ent->pvPrivateData = (void *)0x0;
        (ent->v).pContainingEntity = ent;
      }
      else {
        ent = ED_Alloc();
      }
      data = ED_ParseEdict(data_00,ent);
      if (ent->free != 0) goto LAB_00139120;
      if ((deathmatch.value != 0.0) && (((ent->v).spawnflags & 0x800) != 0)) {
        iVar8 = iVar8 + 1;
        ED_Free(ent);
        goto LAB_00139120;
      }
      if ((ent->v).classname != 0) break;
      Con_Printf("No classname for:\n");
      if (ent->free != 0) goto LAB_00139120;
      SV_UnlinkEdict(ent);
      pvVar6 = ent->pvPrivateData;
      if (pvVar6 != (void *)0x0) {
        if (gNewDLLFunctions.pfnOnFreeEntPrivateData != (_func_void_edict_t_ptr_conflict *)0x0) {
          (*gNewDLLFunctions.pfnOnFreeEntPrivateData)(ent);
          pvVar6 = ent->pvPrivateData;
        }
        Mem_Free(pvVar6);
      }
      ent->serialnumber = ent->serialnumber + 1;
      (ent->v).flags = 0;
      ent->free = 1;
      (ent->v).model = 0;
      fVar1 = (float)sv.time;
      (ent->v).skin = 0;
      vVar5 = vec3_origin[2];
      (ent->v).modelindex = 0;
      vVar4 = vec3_origin[1];
      (ent->v).colormap = 0;
      vVar3 = vec3_origin[0];
      ent->pvPrivateData = (void *)0x0;
      (ent->v).origin[2] = vVar5;
      (ent->v).angles[2] = vVar5;
      (ent->v).takedamage = 0.0;
      (ent->v).frame = 0.0;
      (ent->v).scale = 0.0;
      (ent->v).gravity = 0.0;
      (ent->v).origin[0] = vVar3;
      (ent->v).origin[1] = vVar4;
      (ent->v).angles[0] = vVar3;
      (ent->v).angles[1] = vVar4;
      (ent->v).nextthink = -1.0;
      (ent->v).solid = 0;
      ent->freetime = fVar1;
      data_00 = COM_Parse(data);
      peVar2 = ent;
    }
    iVar7 = (*gEntityInterface.pfnSpawn)(ent);
    if (((iVar7 < 0) || (((ent->v).flags & 0x40000000) != 0)) && (ent->free == 0)) {
      ED_Free(ent);
    }
  } while( true );
}


// ED_NewString  @ 00138c70
char * ED_NewString(char *string)

{
  int size;
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
                    /* Unresolved local var: char * new_s@[DW_OP_reg0(EAX)]
                       Unresolved local var: char * new_p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int l@[???] */
  iVar2 = Q_strlen(string);
  size = iVar2 + 1;
  pcVar3 = Hunk_Alloc(size);
  if (0 < size) {
    pcVar6 = pcVar3 + 1;
    iVar4 = 0;
    do {
      while ((pcVar1 = string + iVar4, *pcVar1 == '\\' && (iVar4 < iVar2))) {
        iVar5 = iVar4 + 1;
        iVar4 = iVar4 + 2;
        pcVar6[-1] = ((string[iVar5] != 'n') - 1U & 0xae) + 0x5c;
        pcVar6 = pcVar6 + 1;
        if (size <= iVar4) {
          return pcVar3;
        }
      }
      iVar4 = iVar4 + 1;
      pcVar6[-1] = *pcVar1;
      pcVar6 = pcVar6 + 1;
    } while (iVar4 < size);
  }
  return pcVar3;
}


// ED_ParseEdict  @ 00138ce0
char * ED_ParseEdict(char *data,edict_t_conflict *ent)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  ENTITYINIT p_Var5;
  int iVar6;
  float fVar7;
  undefined4 local_240;
  char local_23c [255];
  undefined1 local_13d;
  char local_13c [255];
  undefined1 local_3d;
  KeyValueData local_3c;
  KeyValueData local_2c;
  
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
                    /* Unresolved local var: bool[256] szKeyName@[???]
                       Unresolved local var: KeyValueData kvd@[???]
                       Unresolved local var: char * pszLastString@[???] */
  local_3c.szValue = "";
  (ent->v).pContainingEntity = ent;
  local_3c.szClassName = (char *)0x0;
  local_3c.fHandled = 0;
  pcVar4 = data;
  local_3c.szKeyName = local_13c;
  do {
    pcVar4 = COM_Parse(pcVar4);
    if ((pcVar4 == (char *)0x0) || (com_token[0] == '}')) goto LAB_00138db5;
    Q_strncpy(local_13c,com_token,0xff);
    local_3d = 0;
    pcVar4 = COM_Parse(pcVar4);
    if (pcVar4 == (char *)0x0) break;
    iVar3 = Q_strcmp(local_13c,"classname");
  } while (iVar3 != 0);
  local_3c.szValue = com_token;
  (*gEntityInterface.pfnKeyValue)(ent,&local_3c);
  if (local_3c.fHandled == 0) {
    Host_Error("SuckOutClassname: parse error");
  }
  p_Var5 = GetEntityInit(pr_strings + (ent->v).classname);
  if (p_Var5 == (ENTITYINIT)0x0) {
    p_Var5 = GetEntityInit("custom");
    if (p_Var5 == (ENTITYINIT)0x0) {
      bVar1 = false;
      Con_DPrintf("Can\'t init %s\n",pr_strings + (ent->v).classname);
    }
    else {
      (*p_Var5)(&ent->v);
      local_2c.szClassName = "custom";
      local_2c.szKeyName = "customclass";
      local_2c.szValue = pr_strings + (ent->v).classname;
      bVar1 = true;
      local_2c.fHandled = 0;
      (*gEntityInterface.pfnKeyValue)(ent,&local_2c);
    }
  }
  else {
    bVar1 = true;
    (*p_Var5)(&ent->v);
  }
LAB_00138e40:
  data = COM_Parse(data);
  if (com_token[0] == '}') {
    if (bVar1) {
      return data;
    }
LAB_00138db5:
    ent->serialnumber = ent->serialnumber + 1;
    ent->free = 1;
    return data;
  }
  if (data == (char *)0x0) {
    Sys_Error("ED_ParseEntity: EOF without closing brace");
  }
  Q_strncpy(local_23c,com_token,0xff);
  local_13d = 0;
  iVar3 = Q_strlen(local_23c);
  if ((iVar3 != 0) && (local_23c[iVar3 + -1] == ' ')) {
    iVar2 = iVar3 + -2;
    iVar3 = iVar3 + -1;
    do {
      iVar6 = iVar2;
      local_23c[iVar3] = '\0';
      if (iVar6 == -1) break;
      iVar2 = iVar6 + -1;
      iVar3 = iVar6;
    } while (local_23c[iVar6] == ' ');
  }
  data = COM_Parse(data);
  if (data == (char *)0x0) {
    Host_Error("ED_ParseEntity: EOF without closing brace");
  }
  if (com_token[0] == '}') {
    Host_Error("ED_ParseEntity: closing brace without data");
  }
  if (pr_strings + (ent->v).classname != (char *)0x0) goto code_r0x00138ee0;
  goto LAB_00138ef9;
code_r0x00138ee0:
  iVar3 = Q_strcmp(pr_strings + (ent->v).classname,com_token);
  if (iVar3 != 0) {
LAB_00138ef9:
    iVar3 = Q_strcmp(local_23c,"angle");
    if (iVar3 == 0) {
                    /* Unresolved local var: float y@[???] */
      fVar7 = Q_atof(com_token);
      if (0.0 <= fVar7) {
        snprintf(com_token,0x800,"%f %f %f",(double)(ent->v).angles[0],(double)fVar7,
                 (double)(ent->v).angles[2]);
      }
      else {
        local_240 = fVar7;
        if ((int)fVar7 == -1) {
          snprintf(com_token,0x800,"-90 0 0");
        }
        else {
          snprintf(com_token,0x800,"90 0 0");
        }
      }
      Q_strcpy(local_23c,"angles");
    }
    local_2c.szValue = com_token;
    local_2c.szClassName = pr_strings + (ent->v).classname;
    local_2c.fHandled = 0;
    local_2c.szKeyName = local_23c;
    (*gEntityInterface.pfnKeyValue)(ent,&local_2c);
  }
  goto LAB_00138e40;
}


