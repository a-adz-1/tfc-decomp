// LookupStringValue__19CServerRemoteAccessPCc  @ 000c7404
undefined1 * LookupStringValue__19CServerRemoteAccessPCc(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int local_10;
  int local_c;
  
  iVar1 = Cvar_FindVar(param_2);
  if (iVar1 == 0) {
    iVar1 = strcasecmp(param_2,"map");
    if (iVar1 == 0) {
      puVar2 = &DAT_0036bc88;
    }
    else {
      iVar1 = strcasecmp(param_2,"playercount");
      if (iVar1 == 0) {
        local_c = 0;
        for (local_10 = 0; local_10 < DAT_00524288; local_10 = local_10 + 1) {
          if (((*(int *)(DAT_00524284 + local_10 * 0x4eec) != 0) ||
              (*(int *)(DAT_00524284 + 4 + local_10 * 0x4eec) != 0)) ||
             (*(int *)(DAT_00524284 + 0xc + local_10 * 0x4eec) != 0)) {
            local_c = local_c + 1;
          }
        }
        snprintf(s_ReturnBuf_204,0x1f,"%d",local_c);
        puVar2 = s_ReturnBuf_204;
      }
      else {
        iVar1 = strcasecmp(param_2,"maxplayers");
        if (iVar1 == 0) {
          snprintf(s_ReturnBuf_204,0x1f,"%d",DAT_00524288);
          puVar2 = s_ReturnBuf_204;
        }
        else {
          iVar1 = strcasecmp(param_2,"gamedescription");
          if (iVar1 == 0) {
            puVar2 = (undefined1 *)(*DAT_0036afb0)();
          }
          else {
            puVar2 = (undefined1 *)0x0;
          }
        }
      }
    }
  }
  else {
    puVar2 = *(undefined1 **)(iVar1 + 4);
  }
  return puVar2;
}


