// DLL_SetModKey  @ 08088a80
void DLL_SetModKey(undefined4 *param_1,char *param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *__dest;
  
  iVar1 = strcasecmp(param_2,"url_info");
  if (iVar1 == 0) {
    *param_1 = 1;
    __dest = (char *)(param_1 + 1);
  }
  else {
    iVar1 = strcasecmp(param_2,"url_dl");
    if (iVar1 == 0) {
      *param_1 = 1;
      __dest = (char *)(param_1 + 0x41);
    }
    else {
      iVar1 = strcasecmp(param_2,"version");
      if (iVar1 == 0) {
        *param_1 = 1;
        uVar2 = __strtol_internal(param_3,0,10,0);
        param_1[0x89] = uVar2;
        goto LAB_08088c02;
      }
      iVar1 = strcasecmp(param_2,"size");
      if (iVar1 == 0) {
        *param_1 = 1;
        uVar2 = __strtol_internal(param_3,0,10,0);
        param_1[0x8a] = uVar2;
        goto LAB_08088c02;
      }
      iVar1 = strcasecmp(param_2,"svonly");
      if (iVar1 == 0) {
        *param_1 = 1;
        iVar1 = __strtol_internal(param_3,0,10,0);
        param_1[0x8b] = (uint)(iVar1 != 0);
        goto LAB_08088c02;
      }
      iVar1 = strcasecmp(param_2,"cldll");
      if (iVar1 == 0) {
        *param_1 = 1;
        iVar1 = __strtol_internal(param_3,0,10,0);
        param_1[0x8c] = (uint)(iVar1 != 0);
        goto LAB_08088c02;
      }
      iVar1 = strcasecmp(param_2,"hlversion");
      if (iVar1 != 0) goto LAB_08088c02;
      __dest = (char *)(param_1 + 0x81);
    }
  }
  strcpy(__dest,param_3);
LAB_08088c02:
  Con_Printf("DLL:  %s - %s\n",param_2,param_3);
  return;
}


