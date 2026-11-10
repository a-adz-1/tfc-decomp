// DLL_SetModKey  @ 0009376c
void DLL_SetModKey(undefined4 *param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = Q_stricmp(param_2,"url_info");
  if (iVar1 == 0) {
    *param_1 = 1;
    param_1 = param_1 + 1;
  }
  else {
    iVar1 = Q_stricmp(param_2,"url_dl");
    if (iVar1 == 0) {
      *param_1 = 1;
      param_1 = param_1 + 0x41;
    }
    else {
      iVar1 = Q_stricmp(param_2,"version");
      if (iVar1 == 0) {
        *param_1 = 1;
        iVar1 = atoi(param_3);
        param_1[0x89] = iVar1;
        return;
      }
      iVar1 = Q_stricmp(param_2,&DAT_000aec4e);
      if (iVar1 == 0) {
        *param_1 = 1;
        iVar1 = atoi(param_3);
        param_1[0x8a] = iVar1;
        return;
      }
      iVar1 = Q_stricmp(param_2,"svonly");
      if (iVar1 == 0) {
        *param_1 = 1;
        iVar1 = atoi(param_3);
        param_1[0x8b] = (uint)(iVar1 != 0);
        return;
      }
      iVar1 = Q_stricmp(param_2,"cldll");
      if (iVar1 == 0) {
        *param_1 = 1;
        iVar1 = atoi(param_3);
        param_1[0x8c] = (uint)(iVar1 != 0);
        return;
      }
      iVar1 = Q_stricmp(param_2,"hlversion");
      if (iVar1 != 0) {
        return;
      }
      param_1 = param_1 + 0x81;
    }
  }
  Q_strcpy(param_1,param_3);
  return;
}


