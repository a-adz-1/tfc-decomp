// ED_Alloc  @ 0806f680
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * ED_Alloc(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = svs;
  do {
    do {
      iVar3 = iVar3 + 1;
      if (DAT_08140434 <= iVar3) {
        if (DAT_08140438 <= iVar3) {
          if (DAT_08140438 == 0) {
            Sys_Error("ED_Alloc: No edicts yet");
          }
          Sys_Error("ED_Alloc: no free edicts");
        }
        DAT_08140434 = DAT_08140434 + 1;
        piVar2 = (int *)(DAT_0814043c + iVar3 * 0x2c8);
        goto LAB_0806f724;
      }
      piVar2 = (int *)(DAT_0814043c + iVar3 * 0x2c8);
    } while (*piVar2 == 0);
    if ((float)piVar2[0x35] < 2.0) break;
    fVar1 = (float)_DAT_0811d24c - (float)piVar2[0x35];
  } while ((byte)(0.5 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.5) << 0xe) >> 8)) != 1);
LAB_0806f724:
  ED_ClearEdict(piVar2);
  return piVar2;
}


// ED_ClearEdict  @ 0806f640
void ED_ClearEdict(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1 + 0x37;
  for (iVar1 = 0x7b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *param_1 = 0;
  ReleaseEntityDLLFields(param_1);
  InitEntityDLLFields(param_1);
  return;
}


// ED_Count  @ 0806f840
void ED_Count(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  iVar5 = 0;
  local_8 = 0;
  iVar4 = 0;
  iVar3 = 0;
  iVar2 = 0;
  if (0 < DAT_08140434) {
    iVar4 = 0;
    do {
      piVar1 = (int *)(DAT_0814043c + iVar2 * 0x2c8);
      if (*piVar1 == 0) {
        iVar3 = iVar3 + 1;
        if (piVar1[0x72] != 0) {
          local_8 = local_8 + 1;
        }
        if (piVar1[0x5d] != 0) {
          iVar4 = iVar4 + 1;
        }
        if (piVar1[0x71] == 4) {
          iVar5 = iVar5 + 1;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_08140434);
  }
  Con_Printf("num_edicts:%3i\n",DAT_08140434);
  Con_Printf("active    :%3i\n",iVar3);
  Con_Printf("view      :%3i\n",iVar4);
  Con_Printf("touch     :%3i\n",local_8);
  Con_Printf("step      :%3i\n",iVar5);
  return;
}


// ED_Free  @ 0806f740
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ED_Free(int *param_1)

{
  if (*param_1 == 0) {
    SV_UnlinkEdict(param_1);
    FreeEntPrivateData(param_1);
    *param_1 = 1;
    param_1[1] = param_1[1] + 1;
    param_1[0x98] = 0;
    param_1[0x5d] = 0;
    param_1[0x8a] = 0;
    param_1[0x5c] = 0;
    param_1[0x99] = 0;
    param_1[0x73] = 0;
    param_1[0x7b] = 0;
    param_1[0x80] = 0;
    param_1[0x76] = 0;
    param_1[0x39] = vec3_origin._0_4_;
    param_1[0x3a] = vec3_origin._4_4_;
    param_1[0x3b] = vec3_origin._8_4_;
    param_1[0x4b] = vec3_origin._0_4_;
    param_1[0x4c] = vec3_origin._4_4_;
    param_1[0x4d] = vec3_origin._8_4_;
    param_1[0x70] = -0x40800000;
    param_1[0x72] = 0;
    param_1[0x35] = (int)(float)_DAT_0811d24c;
  }
  return;
}


// ED_LoadFromFile  @ 0806fcf0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ED_LoadFromFile(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  gGlobalVariables._0_4_ = (undefined4)_DAT_0811d24c;
  piVar3 = (int *)0x0;
  while( true ) {
    iVar1 = COM_Parse(param_1);
    if (iVar1 == 0) break;
    if (com_token != '{') {
      Sys_Error("ED_LoadFromFile: found %s when expecting {",&com_token);
    }
    piVar2 = DAT_0814043c;
    if (piVar3 == (int *)0x0) {
      ReleaseEntityDLLFields(DAT_0814043c);
      InitEntityDLLFields(piVar2);
    }
    else {
      piVar2 = (int *)ED_Alloc();
    }
    param_1 = ED_ParseEdict(iVar1,piVar2);
    piVar3 = piVar2;
    if (*piVar2 == 0) {
      if (((byte)(0.0 < (float)deathmatch._12_4_ |
                  (byte)((ushort)((ushort)NAN((float)deathmatch._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)deathmatch._12_4_ == 0.0) << 0xe) >> 8)) == 0x40)
         || ((*(byte *)((int)piVar2 + 0x25d) & 8) == 0)) {
        if (piVar2[0x37] == 0) {
          Con_Printf("No classname for:\n");
          ED_Free(piVar2);
        }
        else {
          iVar1 = (*DAT_08178ea4)(piVar2);
          if ((iVar1 < 0) || ((*(byte *)((int)piVar2 + 0x263) & 0x40) != 0)) {
            ED_Free(piVar2);
          }
          SV_FlushSignon();
        }
      }
      else {
        ED_Free(piVar2);
        iVar4 = iVar4 + 1;
      }
    }
  }
  Con_DPrintf("%i entities inhibited\n",iVar4);
  return;
}


// ED_NewString  @ 0806f900
char * ED_NewString(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = (char *)Hunk_Alloc(uVar3);
  iVar5 = 0;
  if (0 < (int)uVar3) {
    pcVar4 = pcVar2;
    do {
      if ((param_1[iVar5] == '\\') && (iVar5 < (int)(uVar3 - 1))) {
        iVar5 = iVar5 + 1;
        if (param_1[iVar5] == 'n') {
          *pcVar4 = '\n';
        }
        else {
          *pcVar4 = '\\';
        }
      }
      else {
        *pcVar4 = param_1[iVar5];
      }
      pcVar4 = pcVar4 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar3);
  }
  return pcVar2;
}


// ED_ParseEdict  @ 0806f980
int ED_ParseEdict(int param_1,char **param_2)

{
  float fVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  char *pcVar9;
  char **ppcVar10;
  char *pcVar11;
  bool bVar12;
  longdouble lVar13;
  char **local_154;
  char **ppcStack_150;
  char *local_114;
  char *local_110;
  char *local_10c;
  undefined4 local_108;
  char local_104 [256];
  char ***pppcVar8;
  
  if (param_2 != DAT_0814043c) {
    ppcVar10 = param_2 + 0x37;
    for (iVar5 = 0x7b; iVar5 != 0; iVar5 = iVar5 + -1) {
      *ppcVar10 = (char *)0x0;
      ppcVar10 = ppcVar10 + 1;
    }
  }
  ppcStack_150 = param_2;
  local_154 = (char **)0x806f9b2;
  InitEntityDLLFields();
  local_154 = param_2;
  SuckOutClassname(param_1);
  bVar3 = false;
  pcVar4 = (code *)GetEntityInit(param_2[0x37] + pr_strings);
  if (pcVar4 == (code *)0x0) {
    ppcStack_150 = (char **)0x80a3970;
    local_154 = (char **)0x806fa1b;
    pcVar4 = (code *)GetEntityInit();
    if (pcVar4 == (code *)0x0) {
      ppcStack_150 = (char **)(param_2[0x37] + pr_strings);
      pppcVar8 = &local_154;
      local_154 = (char **)0x80a3983;
      Con_DPrintf();
      goto LAB_0806fa9a;
    }
    ppcStack_150 = param_2 + 0x37;
    local_154 = (char **)0x806fa2f;
    (*pcVar4)();
    local_114 = "custom";
    local_110 = "customclass";
    local_10c = param_2[0x37] + pr_strings;
    local_108 = 0;
    local_154 = &local_114;
    (*DAT_08178eb8)(param_2);
    bVar3 = true;
    puVar7 = &stack0xfffffeb4;
  }
  else {
    ppcStack_150 = param_2 + 0x37;
    local_154 = (char **)0x806f9f4;
    (*pcVar4)();
    bVar3 = true;
    puVar7 = &stack0xfffffeb4;
  }
LAB_0806faa0:
  *(int *)(puVar7 + -4) = param_1;
  *(undefined4 *)(puVar7 + -8) = 0x806faa9;
  iVar5 = COM_Parse();
  if (com_token == '}') {
    if (!bVar3) {
      *param_2 = (char *)0x1;
      param_2[1] = param_2[1] + 1;
    }
    return iVar5;
  }
  if (iVar5 == 0) {
    *(char **)(puVar7 + -4) = "ED_ParseEntity: EOF without closing brace";
    *(undefined4 *)(puVar7 + -8) = 0x806faca;
    Sys_Error();
  }
  *(char **)(puVar7 + -4) = &com_token;
  *(char **)(puVar7 + -8) = local_104;
  *(undefined4 *)(puVar7 + -0xc) = 0x806fade;
  strcpy(*(char **)(puVar7 + -8),*(char **)(puVar7 + -4));
  uVar6 = 0xffffffff;
  pcVar9 = local_104;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  uVar6 = ~uVar6;
  while ((uVar6 - 1 != 0 && (*(char *)((int)&local_108 + uVar6 + 2) == ' '))) {
    *(undefined1 *)((int)&local_108 + uVar6 + 2) = 0;
    uVar6 = uVar6 - 1;
  }
  *(int *)(puVar7 + -4) = iVar5;
  *(undefined4 *)(puVar7 + -8) = 0x806fb14;
  param_1 = COM_Parse();
  if (param_1 == 0) {
    *(char **)(puVar7 + -4) = "ED_ParseEntity: EOF without closing brace";
    *(undefined4 *)(puVar7 + -8) = 0x806fb28;
    Sys_Error();
  }
  if (com_token == '}') {
    *(char **)(puVar7 + -4) = "ED_ParseEntity: closing brace without data";
    *(undefined4 *)(puVar7 + -8) = 0x806fb3e;
    Sys_Error();
  }
  pcVar9 = param_2[0x37];
  if (pcVar9 + pr_strings != (char *)0x0) goto code_r0x0806fb54;
  goto LAB_0806fb6a;
code_r0x0806fb54:
  *(char **)(puVar7 + -4) = &com_token;
  *(char **)(puVar7 + -8) = pcVar9 + pr_strings;
  *(undefined4 *)(puVar7 + -0xc) = 0x806fb5f;
  iVar5 = strcmp(*(char **)(puVar7 + -8),*(char **)(puVar7 + -4));
  if (iVar5 != 0) {
LAB_0806fb6a:
    iVar5 = 6;
    bVar12 = true;
    pcVar9 = local_104;
    pcVar11 = "angle";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar12 = *pcVar9 == *pcVar11;
      pcVar9 = pcVar9 + 1;
      pcVar11 = pcVar11 + 1;
    } while (bVar12);
    if (bVar12) {
      *(undefined4 *)(puVar7 + -4) = 0;
      *(undefined4 *)(puVar7 + -8) = 0;
      *(char **)(puVar7 + -0xc) = &com_token;
      *(undefined4 *)(puVar7 + -0x10) = 0x806fb93;
      lVar13 = (longdouble)__strtod_internal();
      fVar1 = (float)lVar13;
      if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
        *(double *)(puVar7 + -8) = (double)(float)param_2[0x4d];
        *(double *)(puVar7 + -0x10) = (double)fVar1;
        *(double *)(puVar7 + -0x18) = (double)(float)param_2[0x4b];
        *(char **)(puVar7 + -0x1c) = "%f %f %f";
        *(char **)(puVar7 + -0x20) = &com_token;
        *(undefined4 *)(puVar7 + -0x24) = 0x806fbe2;
        sprintf(*(char **)(puVar7 + -0x20),*(char **)(puVar7 + -0x1c));
      }
      else {
        if ((int)ROUND(fVar1) == -1) {
          *(char **)(puVar7 + -4) = "-90 0 0";
        }
        else {
          *(char **)(puVar7 + -4) = "90 0 0";
        }
        *(char **)(puVar7 + -8) = &com_token;
        *(undefined4 *)(puVar7 + -0xc) = 0x806fc3f;
        sprintf(*(char **)(puVar7 + -8),*(char **)(puVar7 + -4));
      }
      builtin_strncpy(local_104,"angles",7);
    }
    local_114 = param_2[0x37] + pr_strings;
    local_110 = local_104;
    local_10c = &com_token;
    local_108 = 0;
    *(char ***)(puVar7 + -4) = &local_114;
    pppcVar8 = (char ***)(puVar7 + -8);
    *(char ***)(puVar7 + -8) = param_2;
    *(undefined4 *)(puVar7 + -0xc) = 0x806fcae;
    (*DAT_08178eb8)();
LAB_0806fa9a:
    puVar7 = (undefined1 *)((int)pppcVar8 + 8);
  }
  goto LAB_0806faa0;
}


