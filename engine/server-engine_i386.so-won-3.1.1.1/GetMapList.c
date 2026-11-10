// GetMapList__19CServerRemoteAccessR10CUtlBuffer  @ 000c7938
void GetMapList__19CServerRemoteAccessR10CUtlBuffer(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  char local_2048 [4096];
  char local_1048 [4096];
  char *local_48;
  char local_44 [64];
  
  strcpy(local_44,"maps/*.bsp");
  local_48 = (char *)Sys_FindFirst(local_44,0);
  while (local_48 != (char *)0x0) {
    snprintf(local_1048,0xfff,"maps/%s",local_48);
    FS_GetLocalPath(local_1048,local_1048,0xfff);
    pcVar1 = strstr(local_1048,&com_gamedir);
    if (pcVar1 != (char *)0x0) {
      strcpy(local_2048,local_48);
      pcVar1 = strstr(local_2048,".bsp");
      if (pcVar1 != (char *)0x0) {
        *pcVar1 = '\0';
      }
      PutString__10CUtlBufferPCc(param_2,local_2048);
      PutString__10CUtlBufferPCc(param_2,&DAT_000edde7);
    }
    local_48 = (char *)Sys_FindNext(0);
  }
  Sys_FindClose();
  PutChar__10CUtlBufferc(param_2,0);
  return;
}


