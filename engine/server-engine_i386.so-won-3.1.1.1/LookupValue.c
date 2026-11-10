// LookupValue__19CServerRemoteAccessPCcR10CUtlBuffer  @ 000c70cc
/* WARNING: Removing unreachable block (ram,0x000c7398) */

undefined4 LookupValue__19CServerRemoteAccessPCcR10CUtlBuffer(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStackY_264 [5];
  undefined4 uStackY_250;
  
  uStackY_250 = 0xc70f4;
  iVar1 = LookupStringValue__19CServerRemoteAccessPCc();
  if (iVar1 == 0) {
    uStackY_250 = 0xc7141;
    iVar1 = strcasecmp(param_2,"stats");
    if (iVar1 == 0) {
      uStackY_250 = 0xc715e;
      GetStatsString();
      uStackY_250 = 0xc7174;
      PutString__10CUtlBufferPCc();
      uStackY_250 = 0xc7185;
      PutChar__10CUtlBufferc();
    }
    else {
      uStackY_250 = 0xc71a5;
      iVar1 = strcasecmp(param_2,"banlist");
      if (iVar1 == 0) {
        uStackY_250 = 0xc71be;
        GetUserBanList__19CServerRemoteAccessR10CUtlBuffer();
      }
      else {
        uStackY_250 = 0xc71dd;
        iVar1 = strcasecmp(param_2,"playerlist");
        if (iVar1 == 0) {
          uStackY_250 = 0xc71f6;
          GetPlayerList__19CServerRemoteAccessR10CUtlBuffer();
        }
        else {
          uStackY_250 = 0xc7215;
          iVar1 = strcasecmp(param_2,"maplist");
          if (iVar1 == 0) {
            uStackY_250 = 0xc722e;
            GetMapList__19CServerRemoteAccessR10CUtlBuffer();
          }
          else {
            uStackY_250 = 0xc724d;
            iVar1 = strcasecmp(param_2,"uptime");
            if (iVar1 == 0) {
              Sys_FloatTime();
              Host_GetStartTime();
              uStackY_250 = 0xc72ba;
              PutInt__10CUtlBufferi();
              uStackY_250 = 0xc72cb;
              PutChar__10CUtlBufferc();
            }
            else {
              uStackY_250 = 0xc72e9;
              iVar1 = strcasecmp(param_2,"ipaddress");
              if (iVar1 == 0) {
                puVar2 = &net_local_adr;
                puVar3 = auStackY_264;
                for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *puVar3 = *puVar2;
                  puVar2 = puVar2 + 1;
                  puVar3 = puVar3 + 1;
                }
                NET_AdrToString();
                uStackY_250 = 0xc7322;
                PutString__10CUtlBufferPCc();
                uStackY_250 = 0xc7333;
                PutChar__10CUtlBufferc();
              }
              else {
                uStackY_250 = 0xc7351;
                iVar1 = strcasecmp(param_2,"mapcycle");
                if (iVar1 != 0) {
                  uStackY_250 = 0xc73e2;
                  PutChar__10CUtlBufferc();
                  return 0;
                }
                uStackY_250 = 0xc737d;
                COM_LoadFileForMe();
              }
            }
          }
        }
      }
    }
  }
  else {
    uStackY_250 = 0xc7112;
    PutString__10CUtlBufferPCc();
    uStackY_250 = 0xc7123;
    PutChar__10CUtlBufferc();
  }
  return 1;
}


