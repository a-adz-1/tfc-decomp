// BuildMapCycleListHints__FPPc  @ 00096c7c
undefined4 BuildMapCycleListHints__FPPc(int *param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  void *pvVar3;
  int iVar4;
  size_t sVar5;
  char local_428 [264];
  int local_320;
  char local_31c [260];
  undefined1 local_218 [260];
  void *local_114;
  size_t local_110;
  char local_10c [261];
  undefined1 local_7;
  
  COM_FileBase(&com_gamedir,local_218);
  sprintf(local_31c,"%s\\%s",local_218,mapcyclefile._4_4_);
  local_320 = FS_Open(local_31c,&DAT_000e77eb);
  if (local_320 == 0) {
    Con_Printf("Unable to open %s",local_31c);
    uVar1 = 0;
  }
  else {
    sprintf(local_10c,"%s\\%s\\%s%s\r\n",szReslistsBaseDir,local_218,szCommonPreloads,szReslistsExt)
    ;
    sVar2 = strlen(local_10c);
    pvVar3 = malloc(sVar2 + 1);
    *param_1 = (int)pvVar3;
    if (*param_1 == 0) {
      Con_Printf("Unable to allocate memory for map cycle hints list");
      uVar1 = 0;
    }
    else {
      strcpy((char *)*param_1,local_10c);
      local_110 = FS_Size(local_320);
      if ((local_110 != 0) && (local_114 = malloc(local_110), local_114 != (void *)0x0)) {
        iVar4 = FS_Read(local_114,local_110,1,local_320);
        if (iVar4 == 1) {
          while( true ) {
            local_114 = (void *)COM_Parse(local_114);
            sVar2 = strlen(&com_token);
            if (sVar2 == 0) break;
            strncpy(local_10c,&com_token,0x105);
            local_7 = 0;
            iVar4 = COM_TokenWaiting(local_114);
            if (iVar4 != 0) {
              local_114 = (void *)COM_Parse(local_114);
            }
            snprintf(local_428,0x106,"%s\\%s\\%s%s\r\n",szReslistsBaseDir,local_218,local_10c,
                     szReslistsExt);
            sVar2 = strlen((char *)*param_1);
            sVar5 = strlen(local_428);
            pvVar3 = realloc((void *)*param_1,sVar5 + sVar2 + 2);
            *param_1 = (int)pvVar3;
            if (*param_1 == 0) {
              Con_Printf("Unable to reallocate memory for map cycle hints list");
              return 0;
            }
            strcat((char *)*param_1,local_428);
          }
        }
        free(local_114);
      }
      FS_Close(local_320);
      sprintf(local_10c,"%s\\%s\\mp_maps.txt\r\n",szReslistsBaseDir,local_218);
      sVar2 = strlen((char *)*param_1);
      sVar5 = strlen(local_10c);
      pvVar3 = realloc((void *)*param_1,sVar5 + sVar2 + 2);
      *param_1 = (int)pvVar3;
      strcat((char *)*param_1,local_10c);
      uVar1 = 1;
    }
  }
  return uVar1;
}


