// ED_Alloc  @ 00071394
int * ED_Alloc(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int local_c;
  
  iVar3 = DAT_001ab4e8 + 1;
  if (iVar3 < DAT_00186f8c) {
    local_c = iVar3 * 0x324;
    do {
      piVar2 = (int *)(local_c + DAT_00186f94);
      if ((*piVar2 != 0) &&
         (((float)piVar2[0x1e] < 2.0 ||
          (fVar1 = (float)DAT_0015358c - (float)piVar2[0x1e],
          (byte)(0.5 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.5) << 0xe) >> 8)) == 1)))) goto LAB_0007147f;
      local_c = local_c + 0x324;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00186f8c);
  }
  if (DAT_00186f90 <= iVar3) {
    if (DAT_00186f90 == 0) {
      Sys_Error("ED_Alloc: No edicts yet");
    }
    Sys_Error("ED_Alloc: no free edicts");
  }
  DAT_00186f8c = DAT_00186f8c + 1;
  piVar2 = (int *)(DAT_00186f94 + iVar3 * 0x324);
LAB_0007147f:
  ED_ClearEdict(piVar2);
  return piVar2;
}


// ED_ClearEdict  @ 00071350
void ED_ClearEdict(undefined4 *param_1)

{
  Q_memset(param_1 + 0x20,0,0x2a4);
  *param_1 = 0;
  ReleaseEntityDLLFields(param_1);
  InitEntityDLLFields(param_1);
  return;
}


// ED_Count  @ 0007158c
void ED_Count(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  iVar3 = 0;
  if (0 < DAT_00186f8c) {
    iVar2 = 0;
    do {
      piVar1 = (int *)(iVar2 + DAT_00186f94);
      if (*piVar1 == 0) {
        local_8 = local_8 + 1;
        if (piVar1[99] != 0) {
          local_10 = local_10 + 1;
        }
        if (piVar1[0x4e] != 0) {
          local_c = local_c + 1;
        }
        if (piVar1[0x62] == 4) {
          local_14 = local_14 + 1;
        }
      }
      iVar2 = iVar2 + 0x324;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00186f8c);
  }
  Con_Printf("num_edicts:%3i\n",DAT_00186f8c);
  Con_Printf("active    :%3i\n",local_8);
  Con_Printf("view      :%3i\n",local_c);
  Con_Printf("touch     :%3i\n",local_10);
  Con_Printf("step      :%3i\n",local_14);
  return;
}


// ED_Free  @ 00071494
void ED_Free(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    SV_UnlinkEdict(param_1);
    FreeEntPrivateData(param_1);
    *param_1 = 1;
    param_1[1] = param_1[1] + 1;
    param_1[0x89] = 0;
    param_1[0x4e] = 0;
    param_1[0x4d] = 0;
    param_1[0x8a] = 0;
    param_1[100] = 0;
    param_1[0x7b] = 0;
    param_1[0x6c] = 0;
    param_1[0x71] = 0;
    param_1[0x67] = 0;
    param_1[0x22] = vec3_origin;
    param_1[0x23] = DAT_000b2e2c;
    param_1[0x24] = DAT_000b2e30;
    param_1[0x34] = vec3_origin;
    param_1[0x35] = DAT_000b2e2c;
    iVar1 = DAT_000b2e30;
    param_1[99] = 0;
    param_1[0x36] = iVar1;
    param_1[0x61] = -0x40800000;
    param_1[0x1e] = (int)(float)DAT_0015358c;
  }
  return;
}


// ED_LoadFromFile  @ 00071a2c
void ED_LoadFromFile(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_c;
  
  local_c = 0;
  gGlobalVariables = (float)DAT_0015358c;
  piVar3 = (int *)0x0;
  while( true ) {
    iVar1 = COM_Parse(param_1);
    if (iVar1 == 0) break;
    if (com_token != '{') {
      Sys_Error("ED_LoadFromFile: found %s when expecting {",&com_token);
    }
    piVar2 = DAT_00186f94;
    if (piVar3 == (int *)0x0) {
      ReleaseEntityDLLFields(DAT_00186f94);
      InitEntityDLLFields(piVar2);
    }
    else {
      piVar2 = (int *)ED_Alloc();
    }
    param_1 = ED_ParseEdict(iVar1,piVar2);
    piVar3 = piVar2;
    if (*piVar2 == 0) {
      if (((byte)((float)deathmatch._12_4_ < 0.0 |
                  (byte)((ushort)((ushort)NAN((float)deathmatch._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)deathmatch._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)
         || ((*(byte *)((int)piVar2 + 0x221) & 8) == 0)) {
        if (piVar2[0x20] == 0) {
          Con_Printf("No classname for:\n");
          ED_Free(piVar2);
        }
        else {
          iVar1 = (*DAT_00386224)(piVar2);
          if ((iVar1 < 0) || ((*(byte *)((int)piVar2 + 0x227) & 0x40) != 0)) {
            ED_Free(piVar2);
          }
        }
      }
      else {
        ED_Free(piVar2);
        local_c = local_c + 1;
      }
    }
  }
  Con_DPrintf("%i entities inhibited\n",local_c);
  return;
}


// ED_NewString  @ 00071684
char * ED_NewString(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
  iVar2 = Q_strlen(param_1);
  iVar1 = iVar2 + 1;
  pcVar3 = (char *)Hunk_Alloc(iVar1);
  iVar5 = 0;
  pcVar4 = pcVar3;
  if (0 < iVar1) {
    do {
      if ((*(char *)(iVar5 + param_1) == '\\') && (iVar5 < iVar2)) {
        iVar5 = iVar5 + 1;
        if (*(char *)(iVar5 + param_1) == 'n') {
          *pcVar4 = '\n';
        }
        else {
          *pcVar4 = '\\';
        }
      }
      else {
        *pcVar4 = *(char *)(iVar5 + param_1);
      }
      iVar5 = iVar5 + 1;
      pcVar4 = pcVar4 + 1;
    } while (iVar5 < iVar1);
  }
  return pcVar3;
}


// ED_ParseEdict  @ 000716f8
int ED_ParseEdict(int param_1,char **param_2)

{
  bool bVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined1 *puVar6;
  longdouble lVar8;
  char **local_140;
  char **ppcStack_13c;
  char *local_114;
  char *local_110;
  char *local_10c;
  undefined4 local_108;
  char local_104 [256];
  char ***pppcVar7;
  
  puVar6 = &stack0xfffffec8;
  if (param_2 != DAT_00186f94) {
    ppcStack_13c = (char **)0x2a4;
    local_140 = (char **)0x0;
    Q_memset(param_2 + 0x20);
  }
  ppcStack_13c = param_2;
  local_140 = (char **)0x7173d;
  InitEntityDLLFields();
  local_140 = param_2;
  SuckOutClassname(param_1);
  bVar1 = false;
  pcVar2 = (code *)GetEntityInit(param_2[0x20] + pr_strings);
  if (pcVar2 == (code *)0x0) {
    local_140 = (char **)0x71798;
    ppcStack_13c = (char **)"custom";
    pcVar2 = (code *)GetEntityInit();
    if (pcVar2 == (code *)0x0) {
      ppcStack_13c = (char **)(param_2[0x20] + pr_strings);
      local_140 = (char **)0xaa143;
      pppcVar7 = &local_140;
      Con_DPrintf();
      goto LAB_00071817;
    }
    ppcStack_13c = param_2 + 0x20;
    local_140 = (char **)0x717aa;
    (*pcVar2)();
    local_110 = "customclass";
    local_10c = param_2[0x20] + pr_strings;
    local_108 = 0;
    local_140 = &local_114;
    local_114 = "custom";
    (*DAT_00386238)(param_2);
    bVar1 = true;
  }
  else {
    ppcStack_13c = param_2 + 0x20;
    local_140 = (char **)0x71779;
    (*pcVar2)();
    bVar1 = true;
    puVar6 = &stack0xfffffec8;
  }
LAB_0007181c:
  *(int *)(puVar6 + -4) = param_1;
  *(undefined4 *)(puVar6 + -8) = 0x71825;
  iVar3 = COM_Parse();
  if (com_token == '}') {
    if (!bVar1) {
      *param_2 = (char *)0x1;
      param_2[1] = param_2[1] + 1;
    }
    return iVar3;
  }
  if (iVar3 == 0) {
    *(char **)(puVar6 + -4) = "ED_ParseEntity: EOF without closing brace";
    *(undefined4 *)(puVar6 + -8) = 0x71850;
    Sys_Error();
  }
  *(char **)(puVar6 + -4) = &com_token;
  *(char **)(puVar6 + -8) = local_104;
  *(undefined4 *)(puVar6 + -0xc) = 0x71860;
  Q_strcpy();
  *(char **)(puVar6 + -0xc) = local_104;
  *(undefined4 *)(puVar6 + -0x10) = 0x71866;
  iVar4 = Q_strlen();
  while ((iVar4 != 0 && (iVar4 = iVar4 + -1, local_104[iVar4] == ' '))) {
    local_104[iVar4] = '\0';
  }
  *(int *)(puVar6 + -4) = iVar3;
  *(undefined4 *)(puVar6 + -8) = 0x7188c;
  param_1 = COM_Parse();
  if (param_1 == 0) {
    *(char **)(puVar6 + -4) = "ED_ParseEntity: EOF without closing brace";
    *(undefined4 *)(puVar6 + -8) = 0x718a2;
    Sys_Error();
  }
  if (com_token == '}') {
    *(char **)(puVar6 + -4) = "ED_ParseEntity: closing brace without data";
    *(undefined4 *)(puVar6 + -8) = 0x718bc;
    Sys_Error();
  }
  pcVar5 = param_2[0x20];
  if (pcVar5 + pr_strings != (char *)0x0) goto code_r0x000718cf;
  goto LAB_000718e7;
code_r0x000718cf:
  *(char **)(puVar6 + -4) = &com_token;
  *(char **)(puVar6 + -8) = pcVar5 + pr_strings;
  *(undefined4 *)(puVar6 + -0xc) = 0x718dc;
  iVar3 = Q_strcmp();
  if (iVar3 != 0) {
LAB_000718e7:
    *(char **)(puVar6 + -4) = "angle";
    *(char **)(puVar6 + -8) = local_104;
    *(undefined4 *)(puVar6 + -0xc) = 0x718f4;
    iVar3 = Q_strcmp();
    if (iVar3 == 0) {
      *(char **)(puVar6 + -4) = &com_token;
      *(undefined4 *)(puVar6 + -8) = 0x71919;
      lVar8 = (longdouble)Q_atof();
      if (lVar8 < (longdouble)0) {
        if ((int)ROUND(lVar8) == -1) {
          pcVar5 = "-90 0 0";
        }
        else {
          pcVar5 = "90 0 0";
        }
        *(char **)(puVar6 + -4) = pcVar5;
        *(char **)(puVar6 + -8) = &com_token;
        *(undefined4 *)(puVar6 + -0xc) = 0x719ab;
        sprintf(*(char **)(puVar6 + -8),*(char **)(puVar6 + -4));
      }
      else {
        *(double *)(puVar6 + -8) = (double)(float)param_2[0x36];
        *(double *)(puVar6 + -0x10) = (double)lVar8;
        *(double *)(puVar6 + -0x18) = (double)(float)param_2[0x34];
        *(char **)(puVar6 + -0x1c) = "%f %f %f";
        *(char **)(puVar6 + -0x20) = &com_token;
        *(undefined4 *)(puVar6 + -0x24) = 0x71958;
        sprintf(*(char **)(puVar6 + -0x20),*(char **)(puVar6 + -0x1c));
      }
      *(char **)(puVar6 + -4) = "angles";
      *(char **)(puVar6 + -8) = local_104;
      *(undefined4 *)(puVar6 + -0xc) = 0x719bb;
      Q_strcpy();
    }
    local_114 = param_2[0x20] + pr_strings;
    local_10c = &com_token;
    local_108 = 0;
    local_110 = local_104;
    *(char ***)(puVar6 + -4) = &local_114;
    pppcVar7 = (char ***)(puVar6 + -8);
    *(char ***)(puVar6 + -8) = param_2;
    *(undefined4 *)(puVar6 + -0xc) = 0x71a01;
    (*DAT_00386238)();
LAB_00071817:
    puVar6 = (undefined1 *)((int)pppcVar7 + 8);
  }
  goto LAB_0007181c;
}


