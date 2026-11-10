// SetValue__19CServerRemoteAccessPCcT1  @ 000c6ed8
void SetValue__19CServerRemoteAccessPCcT1(undefined4 param_1,char *param_2,char *param_3)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  int local_8;
  
  iVar1 = strcasecmp(param_2,"map");
  if (iVar1 == 0) {
    Cbuf_AddText("changelevel ");
    Cbuf_AddText(param_3);
    Cbuf_AddText(&DAT_000edde7);
    Cbuf_Execute();
  }
  else {
    iVar1 = strcasecmp(param_2,"mapcycle");
    if (iVar1 == 0) {
      local_8 = FS_Open(mapcyclefile._4_4_,&DAT_000eddf2);
      if (local_8 == 0) {
        Con_Printf("Couldn\'t write to read-only file %s, using file _dev_mapcycle.txt instead.\n",
                   mapcyclefile._4_4_);
        Cvar_DirectSet(mapcyclefile,"_temp_mapcycle.txt");
        local_8 = FS_Open(mapcyclefile._4_4_,&DAT_000eddf2);
        if (local_8 == 0) {
          return;
        }
      }
      uVar3 = 1;
      iVar1 = local_8;
      sVar2 = strlen(param_3);
      FS_Write(param_3,sVar2 + 1,uVar3,iVar1);
      FS_Close(local_8);
    }
    else {
      iVar1 = Cvar_FindVar(param_2);
      if (iVar1 != 0) {
        Cvar_DirectSet(iVar1,param_3);
      }
    }
  }
  return;
}


