// SVC_GameDllQuery  @ 000a1770
int SVC_GameDllQuery(char *s)

{
  netadr_t to;
  int iVar1;
  undefined4 local_810;
  char local_80c [2044];
  int local_10 [3];
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int maxsize@[???]
                       Unresolved local var: uchar[2048] data@[???]
                       Unresolved local var: int valid@[???] */
  iVar1 = 0;
  if ((sv.active != false) && (1 < svs.maxclients)) {
    Q_memset(&local_810,0,0x800);
    local_10[0] = 0x7fc;
    iVar1 = (*gEntityInterface.pfnConnectionlessPacket)(&net_from,s,local_80c,local_10);
    if ((local_10[0] != 0) && (local_10[0] < 0x7fd)) {
      local_810 = 0xffffffff;
      to.ip[0] = net_from.ip[0];
      to.ip[1] = net_from.ip[1];
      to.ip[2] = net_from.ip[2];
      to.ip[3] = net_from.ip[3];
      to.type = net_from.type;
      to.ipx[0] = net_from.ipx[0];
      to.ipx[1] = net_from.ipx[1];
      to.ipx[2] = net_from.ipx[2];
      to.ipx[3] = net_from.ipx[3];
      to.ipx[4] = net_from.ipx[4];
      to.ipx[5] = net_from.ipx[5];
      to.ipx[6] = net_from.ipx[6];
      to.ipx[7] = net_from.ipx[7];
      to.ipx[8] = net_from.ipx[8];
      to.ipx[9] = net_from.ipx[9];
      to.port = net_from.port;
      NET_SendPacket(NS_SERVER,local_10[0] + 4,&local_810,to);
    }
  }
  return iVar1;
}


// SVC_GetChallenge  @ 0009fda0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_GetChallenge(void)

{
  netadr_t a;
  netadr_t to;
  int iVar1;
  qboolean qVar2;
  qboolean qVar3;
  int32 iVar4;
  uint uVar5;
  char *s1;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  bool bVar10;
  uint64 uVar11;
  char local_41c [1036];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int oldest@[???]
                       Unresolved local var: int oldestTime@[???]
                       Unresolved local var: char[1024] data@[???]
                       Unresolved local var: int protocol@[???]
                       Unresolved local var: qboolean steam@[???] */
  iVar1 = Cmd_Argc();
  bVar10 = false;
  if (iVar1 == 2) {
    s1 = Cmd_Argv(1);
    iVar1 = Q_stricmp(s1,"steam");
    bVar10 = iVar1 == 0;
  }
  piVar8 = &g_rg_sv_challenges[0].time;
  iVar9 = 0x7fffffff;
  iVar6 = 0;
  iVar1 = 0;
  do {
    a.ip[0] = net_from.ip[0];
    a.ip[1] = net_from.ip[1];
    a.ip[2] = net_from.ip[2];
    a.ip[3] = net_from.ip[3];
    a.type = net_from.type;
    a.ipx[0] = net_from.ipx[0];
    a.ipx[1] = net_from.ipx[1];
    a.ipx[2] = net_from.ipx[2];
    a.ipx[3] = net_from.ipx[3];
    a.ipx[4] = net_from.ipx[4];
    a.ipx[5] = net_from.ipx[5];
    a.ipx[6] = net_from.ipx[6];
    a.ipx[7] = net_from.ipx[7];
    a.ipx[8] = net_from.ipx[8];
    a.ipx[9] = net_from.ipx[9];
    a.port = net_from.port;
    qVar2 = NET_CompareBaseAdr(a,g_rg_sv_challenges[iVar6].adr);
    iVar7 = iVar6;
    if (qVar2 != false) goto LAB_0009fe5d;
    iVar7 = iVar1;
    if (*piVar8 < iVar9) {
      iVar7 = iVar6;
      iVar9 = *piVar8;
    }
    iVar6 = iVar6 + 1;
    piVar8 = piVar8 + 7;
    iVar1 = iVar7;
  } while (iVar6 != 0x400);
  iVar4 = RandomLong(0,0x8fff);
  uVar5 = RandomLong(0,0xffff);
  g_rg_sv_challenges[iVar7].challenge = iVar4 << 0x10 | uVar5;
  g_rg_sv_challenges[iVar7].adr.type = net_from.type;
  *&g_rg_sv_challenges[iVar7].adr.ip = net_from.ip;
  *(undefined4 *)g_rg_sv_challenges[iVar7].adr.ipx = net_from.ipx._0_4_;
  *(undefined4 *)(g_rg_sv_challenges[iVar7].adr.ipx + 4) = net_from.ipx._4_4_;
  *(undefined4 *)(g_rg_sv_challenges[iVar7].adr.ipx + 8) = net_from._16_4_;
  g_rg_sv_challenges[iVar7].time = (int)realtime;
LAB_0009fe5d:
  if (bVar10) {
    qVar3 = Steam_GSBSecure();
    uVar11 = Steam_GSGetSteamID();
    snprintf(local_41c,0x400,"%c%c%c%c%c00000000 %u %i %llim %d\n",0xff,0xff,0xff,0xff,0x41,
             g_rg_sv_challenges[iVar7].challenge,3,(int)uVar11,(int)(uVar11 >> 0x20),qVar3);
  }
  else {
    Con_DPrintf("Server requiring authentication\n");
    snprintf(local_41c,0x400,"%c%c%c%c%c00000000 %u %i\n",0xff,0xff,0xff,0xff,0x41,
             g_rg_sv_challenges[iVar7].challenge,2);
  }
  iVar1 = Q_strlen(local_41c);
  to.ip[0] = net_from.ip[0];
  to.ip[1] = net_from.ip[1];
  to.ip[2] = net_from.ip[2];
  to.ip[3] = net_from.ip[3];
  to.type = net_from.type;
  to.ipx[0] = net_from.ipx[0];
  to.ipx[1] = net_from.ipx[1];
  to.ipx[2] = net_from.ipx[2];
  to.ipx[3] = net_from.ipx[3];
  to.ipx[4] = net_from.ipx[4];
  to.ipx[5] = net_from.ipx[5];
  to.ipx[6] = net_from.ipx[6];
  to.ipx[7] = net_from.ipx[7];
  to.ipx[8] = net_from.ipx[8];
  to.ipx[9] = net_from.ipx[9];
  to.port = net_from.port;
  NET_SendPacket(NS_SERVER,iVar1 + 1,local_41c,to);
  return;
}


// SVC_Info  @ 000a0f30
void SVC_Info(qboolean bDetailed)

{
  netadr_t a;
  netadr_t to;
  client_s *pcVar1;
  char *pcVar2;
  qboolean c;
  qboolean qVar3;
  int iVar4;
  int iVar5;
  qboolean c_00;
  byte local_ad8 [1400];
  char local_560 [512];
  char local_360 [512];
  char local_160 [260];
  char local_5c [32];
  sizebuf_t local_3c [2];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: uchar[1400] data@[???]
                       Unresolved local var: char[512] szModURL_Info@[???]
                       Unresolved local var: char[512] szModURL_DL@[???]
                       Unresolved local var: int mod_version@[???]
                       Unresolved local var: int mod_size@[???]
                       Unresolved local var: int isMod@[???]
                       Unresolved local var: char[260] gd@[???]
                       Unresolved local var: qboolean cldll@[???]
                       Unresolved local var: qboolean svonly@[???]
                       Unresolved local var: char[32] szHLVersion@[???] */
  local_3c[0].maxsize = 0x578;
  local_3c[0].cursize = 0;
  local_3c[0].data = local_ad8;
  local_3c[0].flags = 1;
  local_3c[0].buffername = "SVC_Info";
  if ((sv.active != false) && (1 < svs.maxclients)) {
    iVar5 = 0;
    iVar4 = 0;
    pcVar1 = svs.clients;
    do {
      if (((pcVar1->active != false) || (pcVar1->spawned != false)) || (pcVar1->connected != false))
      {
        iVar5 = iVar5 + 1;
      }
      iVar4 = iVar4 + 1;
      pcVar1 = pcVar1 + 1;
    } while (iVar4 != svs.maxclients);
    MSG_WriteLong(local_3c,-1);
    if (bDetailed == false) {
      MSG_WriteByte(local_3c,0x43);
    }
    else {
      MSG_WriteByte(local_3c,0x6d);
    }
    if (noip == false) {
      a.ip[0] = net_local_adr.ip[0];
      a.ip[1] = net_local_adr.ip[1];
      a.ip[2] = net_local_adr.ip[2];
      a.ip[3] = net_local_adr.ip[3];
      a.type = net_local_adr.type;
      a.ipx[0] = net_local_adr.ipx[0];
      a.ipx[1] = net_local_adr.ipx[1];
      a.ipx[2] = net_local_adr.ipx[2];
      a.ipx[3] = net_local_adr.ipx[3];
      a.ipx[4] = net_local_adr.ipx[4];
      a.ipx[5] = net_local_adr.ipx[5];
      a.ipx[6] = net_local_adr.ipx[6];
      a.ipx[7] = net_local_adr.ipx[7];
      a.ipx[8] = net_local_adr.ipx[8];
      a.ipx[9] = net_local_adr.ipx[9];
      a.port = net_local_adr.port;
      pcVar2 = NET_AdrToString(a);
      MSG_WriteString(local_3c,pcVar2);
    }
    else {
      MSG_WriteString(local_3c,"LOOPBACK");
    }
    pcVar2 = Cvar_VariableString("hostname");
    MSG_WriteString(local_3c,pcVar2);
    MSG_WriteString(local_3c,sv.name);
    COM_FileBase(com_gamedir,local_160);
    MSG_WriteString(local_3c,local_160);
    pcVar2 = (*gEntityInterface.pfnGetGameDescription)();
    MSG_WriteString(local_3c,pcVar2);
    MSG_WriteByte(local_3c,iVar5);
                    /* Unresolved local var: int maxplayers@[???] */
    iVar4 = (int)sv_visiblemaxplayers.value;
    if ((int)sv_visiblemaxplayers.value < 0) {
      iVar4 = svs.maxclients;
    }
    MSG_WriteByte(local_3c,iVar4);
    MSG_WriteByte(local_3c,0x30);
    if (bDetailed != false) {
      if (cls.state == ca_dedicated) {
        MSG_WriteByte(local_3c,100);
      }
      else {
        MSG_WriteByte(local_3c,0x6c);
      }
      MSG_WriteByte(local_3c,0x6c);
      iVar4 = Q_strlen(sv_password.string);
      if ((iVar4 < 1) || (iVar4 = Q_stricmp(sv_password.string,"none"), iVar4 == 0)) {
        MSG_WriteByte(local_3c,0);
      }
      else {
        MSG_WriteByte(local_3c,1);
      }
      if (gmodinfo.bIsMod == false) {
        Q_strcpy(local_560,"");
        Q_strcpy(local_360,"");
        Q_strcpy(local_5c,"");
        c = true;
        iVar4 = 1;
        iVar5 = 0;
        c_00 = false;
      }
      else {
        Q_strcpy(local_560,gmodinfo.szInfo);
        Q_strcpy(local_360,gmodinfo.szDL);
        Q_strcpy(local_5c,gmodinfo.szHLVersion);
        c = gmodinfo.svonly;
        iVar4 = gmodinfo.version;
        iVar5 = gmodinfo.size;
        c_00 = gmodinfo.cldll;
      }
      if (gmodinfo.bIsMod == false) {
        MSG_WriteByte(local_3c,0);
      }
      else {
        MSG_WriteByte(local_3c,1);
        MSG_WriteString(local_3c,local_560);
        MSG_WriteString(local_3c,local_360);
        MSG_WriteString(local_3c,"");
        MSG_WriteLong(local_3c,iVar4);
        MSG_WriteLong(local_3c,iVar5);
        MSG_WriteByte(local_3c,c);
        MSG_WriteByte(local_3c,c_00);
      }
      qVar3 = Steam_GSBSecure();
      MSG_WriteByte(local_3c,(uint)(qVar3 != 0));
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int fakeclients@[???] */
      iVar4 = 0;
      if (0 < svs.maxclients) {
        iVar5 = 0;
        pcVar1 = svs.clients;
        do {
                    /* Unresolved local var: client_t * client@[???] */
          if (pcVar1->fakeclient != false) {
            iVar4 = iVar4 + 1;
          }
          iVar5 = iVar5 + 1;
          pcVar1 = pcVar1 + 1;
        } while (iVar5 != svs.maxclients);
      }
      MSG_WriteByte(local_3c,iVar4);
    }
    to.ip[0] = net_from.ip[0];
    to.ip[1] = net_from.ip[1];
    to.ip[2] = net_from.ip[2];
    to.ip[3] = net_from.ip[3];
    to.type = net_from.type;
    to.ipx[0] = net_from.ipx[0];
    to.ipx[1] = net_from.ipx[1];
    to.ipx[2] = net_from.ipx[2];
    to.ipx[3] = net_from.ipx[3];
    to.ipx[4] = net_from.ipx[4];
    to.ipx[5] = net_from.ipx[5];
    to.ipx[6] = net_from.ipx[6];
    to.ipx[7] = net_from.ipx[7];
    to.ipx[8] = net_from.ipx[8];
    to.ipx[9] = net_from.ipx[9];
    to.port = net_from.port;
    NET_SendPacket(NS_SERVER,local_3c[0].cursize,local_3c[0].data,to);
  }
  return;
}


// SVC_InfoString  @ 000a0960
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_InfoString(void)

{
  netadr_t a;
  netadr_t to;
  client_s *pcVar1;
  char *pcVar2;
  qboolean qVar3;
  qboolean qVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint local_fc0;
  char local_fb8 [2048];
  byte local_7b8 [1400];
  char local_240 [260];
  char local_13c [255];
  undefined1 local_3d;
  sizebuf_t local_3c;
  char local_1e [14];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int proxy@[???]
                       Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: uchar[1400] data@[???]
                       Unresolved local var: char[256] address@[???]
                       Unresolved local var: char[260] gd@[???]
                       Unresolved local var: char[2048] info@[???]
                       Unresolved local var: int iHasPW@[???]
                       Unresolved local var: char[2] szOS@[???] */
  local_3c.buffername = "SVC_InfoString";
  local_3c.maxsize = 0x578;
  local_3c.cursize = 0;
  local_3c.data = local_7b8;
  local_3c.flags = 1;
  if (((noip == false) && (sv.active != false)) && (1 < svs.maxclients)) {
    iVar6 = 0;
    iVar5 = 0;
    iVar7 = 0;
    pcVar1 = svs.clients;
    do {
      if (((pcVar1->active != false) || (pcVar1->spawned != false)) || (pcVar1->connected != false))
      {
        iVar6 = (iVar6 + 1) - (uint)(pcVar1->proxy == false);
        iVar7 = iVar7 + 1;
      }
      iVar5 = iVar5 + 1;
      pcVar1 = pcVar1 + 1;
    } while (iVar5 != svs.maxclients);
    local_13c[0] = '\0';
    a.ip = net_local_adr.ip;
    a.type = net_local_adr.type;
    a.ipx._0_4_ = net_local_adr.ipx._0_4_;
    a.ipx._4_4_ = net_local_adr.ipx._4_4_;
    a._16_4_ = net_local_adr._16_4_;
    pcVar2 = NET_AdrToString(a);
    Q_strncpy(local_13c,pcVar2,0xff);
    local_3d = 0;
    local_fc0 = 0;
    if (*sv_password.string != '\0') {
      iVar5 = Q_stricmp(sv_password.string,"none");
      local_fc0 = (uint)(iVar5 != 0);
    }
    Q_strcpy(local_1e,"l");
    local_fb8[0] = '\0';
    pcVar2 = va("%i",0x30);
    Info_SetValueForKey(local_fb8,"protocol",pcVar2,0x800);
    Info_SetValueForKey(local_fb8,"address",local_13c,0x800);
    pcVar2 = va("%i",iVar7);
    Info_SetValueForKey(local_fb8,"players",pcVar2,0x800);
    pcVar2 = va("%i",iVar6);
                    /* Unresolved local var: int maxplayers@[???] */
    Info_SetValueForKey(local_fb8,"proxytarget",pcVar2,0x800);
    qVar3 = Master_IsLanGame();
    pcVar2 = va("%i",(uint)(qVar3 != false));
    Info_SetValueForKey(local_fb8,"lan",pcVar2,0x800);
    iVar5 = (int)sv_visiblemaxplayers.value;
    if ((int)sv_visiblemaxplayers.value < 0) {
      iVar5 = svs.maxclients;
    }
    pcVar2 = va("%i",iVar5);
    Info_SetValueForKey(local_fb8,"max",pcVar2,0x800);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int fakeclients@[???] */
    iVar5 = 0;
    if (0 < svs.maxclients) {
      iVar6 = 0;
      pcVar1 = svs.clients;
      do {
                    /* Unresolved local var: client_t * client@[???] */
        if (pcVar1->fakeclient != false) {
          iVar5 = iVar5 + 1;
        }
        iVar6 = iVar6 + 1;
        pcVar1 = pcVar1 + 1;
      } while (iVar6 != svs.maxclients);
    }
    pcVar2 = va("%i",iVar5);
    Info_SetValueForKey(local_fb8,"bots",pcVar2,0x800);
    COM_FileBase(com_gamedir,local_240);
    Info_SetValueForKey(local_fb8,"gamedir",local_240,0x800);
    pcVar2 = (*gEntityInterface.pfnGetGameDescription)();
    Info_SetValueForKey(local_fb8,"description",pcVar2,0x800);
    pcVar2 = Cvar_VariableString("hostname");
    Info_SetValueForKey(local_fb8,"hostname",pcVar2,0x800);
    Info_SetValueForKey(local_fb8,"map",sv.name,0x800);
    pcVar2 = "d";
    if (cls.state != ca_dedicated) {
      pcVar2 = "l";
    }
    Info_SetValueForKey(local_fb8,"type",pcVar2,0x800);
    pcVar2 = va("%i",local_fc0);
    Info_SetValueForKey(local_fb8,"password",pcVar2,0x800);
    Info_SetValueForKey(local_fb8,"os",local_1e,0x800);
    qVar4 = Steam_GSBSecure();
    pcVar2 = "1";
    if (qVar4 == 0) {
      pcVar2 = "0";
    }
    Info_SetValueForKey(local_fb8,"secure",pcVar2,0x800);
    if (gmodinfo.bIsMod != false) {
      pcVar2 = va("%i",1);
      Info_SetValueForKey(local_fb8,"mod",pcVar2,0x800);
      pcVar2 = va("%i",gmodinfo.version);
      Info_SetValueForKey(local_fb8,"modversion",pcVar2,0x800);
      pcVar2 = va("%i",gmodinfo.svonly);
      Info_SetValueForKey(local_fb8,"svonly",pcVar2,0x800);
      pcVar2 = va("%i",gmodinfo.cldll);
      Info_SetValueForKey(local_fb8,"cldll",pcVar2,0x800);
    }
    MSG_WriteLong(&local_3c,-1);
    MSG_WriteString(&local_3c,"infostringresponse");
    MSG_WriteString(&local_3c,local_fb8);
    to.ip[0] = net_from.ip[0];
    to.ip[1] = net_from.ip[1];
    to.ip[2] = net_from.ip[2];
    to.ip[3] = net_from.ip[3];
    to.type = net_from.type;
    to.ipx[0] = net_from.ipx[0];
    to.ipx[1] = net_from.ipx[1];
    to.ipx[2] = net_from.ipx[2];
    to.ipx[3] = net_from.ipx[3];
    to.ipx[4] = net_from.ipx[4];
    to.ipx[5] = net_from.ipx[5];
    to.ipx[6] = net_from.ipx[6];
    to.ipx[7] = net_from.ipx[7];
    to.ipx[8] = net_from.ipx[8];
    to.ipx[9] = net_from.ipx[9];
    to.port = net_from.port;
    NET_SendPacket(NS_SERVER,local_3c.cursize,local_3c.data,to);
  }
  return;
}


// SVC_Ping  @ 0009fd30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_Ping(void)

{
  netadr_t to;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
                    /* Unresolved local var: char[6] data@[???] */
  local_12 = 0xff;
  local_11 = 0xff;
  local_10 = 0xff;
  local_f = 0xff;
  local_e = 0x6a;
  local_d = 0;
  to.ip = net_from.ip;
  to.type = net_from.type;
  to.ipx._0_4_ = net_from.ipx._0_4_;
  to.ipx._4_4_ = net_from.ipx._4_4_;
  to._16_4_ = net_from._16_4_;
  NET_SendPacket(NS_SERVER,6,&local_12,to);
  return;
}


// SVC_PlayerInfo  @ 000a1400
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_PlayerInfo(void)

{
  netadr_t to;
  int iVar1;
  client_s *pcVar2;
  int iVar3;
  client_s *pcVar4;
  int local_844;
  byte local_83c [2048];
  sizebuf_t local_3c [2];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: uchar[2048] data@[???] */
  local_3c[0].buffername = "SVC_PlayerInfo";
  local_3c[0].maxsize = 0x800;
  local_3c[0].cursize = 0;
  local_3c[0].data = local_83c;
  local_3c[0].flags = 1;
  if ((sv.active != false) && (1 < svs.maxclients)) {
    MSG_WriteLong(local_3c,-1);
    MSG_WriteByte(local_3c,0x44);
    iVar1 = 0;
    if (0 < svs.maxclients) {
      iVar3 = 0;
      pcVar2 = svs.clients;
      do {
        if (pcVar2->active != false) {
          iVar1 = iVar1 + 1;
        }
        iVar3 = iVar3 + 1;
        pcVar2 = pcVar2 + 1;
      } while (iVar3 != svs.maxclients);
    }
    MSG_WriteByte(local_3c,iVar1);
    pcVar2 = svs.clients;
    if (0 < svs.maxclients) {
      iVar3 = 0;
      local_844 = 0;
      iVar1 = svs.maxclients;
      pcVar4 = svs.clients;
      do {
        if (*(int *)((int)svs.clients + ((int)pcVar4 - (int)pcVar2)) == 0) {
          if (iVar1 <= iVar3 + 1) break;
        }
        else {
          local_844 = local_844 + 1;
          MSG_WriteByte(local_3c,local_844);
          MSG_WriteString(local_3c,pcVar4->name);
          MSG_WriteLong(local_3c,(int)(pcVar4->edict->v).frags);
          MSG_WriteFloat(local_3c,(float)realtime - (pcVar4->netchan).connect_time);
          iVar1 = svs.maxclients;
          if (svs.maxclients <= iVar3 + 1) break;
        }
        iVar3 = iVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while( true );
    }
    to.ip[0] = net_from.ip[0];
    to.ip[1] = net_from.ip[1];
    to.ip[2] = net_from.ip[2];
    to.ip[3] = net_from.ip[3];
    to.type = net_from.type;
    to.ipx[0] = net_from.ipx[0];
    to.ipx[1] = net_from.ipx[1];
    to.ipx[2] = net_from.ipx[2];
    to.ipx[3] = net_from.ipx[3];
    to.ipx[4] = net_from.ipx[4];
    to.ipx[5] = net_from.ipx[5];
    to.ipx[6] = net_from.ipx[6];
    to.ipx[7] = net_from.ipx[7];
    to.ipx[8] = net_from.ipx[8];
    to.ipx[9] = net_from.ipx[9];
    to.port = net_from.port;
    NET_SendPacket(NS_SERVER,local_3c[0].cursize,local_3c[0].data,to);
  }
  return;
}


// SVC_RuleInfo  @ 000a15c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_RuleInfo(void)

{
  cvar_s *pcVar1;
  netadr_t to;
  int iVar2;
  byte local_202c [8192];
  sizebuf_t local_2c;
  
                    /* Unresolved local var: int nNumRules@[???]
                       Unresolved local var: cvar_t * var@[???]
                       Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: uchar[8192] data@[???] */
  local_2c.buffername = "SVC_RuleInfo";
  local_2c.maxsize = 0x2000;
  local_2c.data = local_202c;
  local_2c.cursize = 0;
  local_2c.flags = 1;
  if (((sv.active == false) || (svs.maxclients < 2)) ||
     (iVar2 = Cvar_CountServerVariables(), iVar2 < 1)) {
    return;
  }
  MSG_WriteLong(&local_2c,-1);
  MSG_WriteByte(&local_2c,0x45);
  MSG_WriteShort(&local_2c,iVar2);
  pcVar1 = cvar_vars;
  do {
    while( true ) {
      if (pcVar1 == (cvar_t *)0x0) {
        to.ip[0] = net_from.ip[0];
        to.ip[1] = net_from.ip[1];
        to.ip[2] = net_from.ip[2];
        to.ip[3] = net_from.ip[3];
        to.type = net_from.type;
        to.ipx[0] = net_from.ipx[0];
        to.ipx[1] = net_from.ipx[1];
        to.ipx[2] = net_from.ipx[2];
        to.ipx[3] = net_from.ipx[3];
        to.ipx[4] = net_from.ipx[4];
        to.ipx[5] = net_from.ipx[5];
        to.ipx[6] = net_from.ipx[6];
        to.ipx[7] = net_from.ipx[7];
        to.ipx[8] = net_from.ipx[8];
        to.ipx[9] = net_from.ipx[9];
        to.port = net_from.port;
        NET_SendPacket(NS_SERVER,local_2c.cursize,local_2c.data,to);
        return;
      }
      if ((pcVar1->flags & 4) != 0) break;
LAB_000a1670:
      pcVar1 = pcVar1->next;
    }
    MSG_WriteString(&local_2c,pcVar1->name);
    if ((pcVar1->flags & 0x20) == 0) {
      MSG_WriteString(&local_2c,pcVar1->string);
      goto LAB_000a1670;
    }
    iVar2 = Q_strlen(pcVar1->string);
    if ((0 < iVar2) && (iVar2 = Q_stricmp(pcVar1->string,"none"), iVar2 != 0)) {
      MSG_WriteString(&local_2c,"1");
      goto LAB_000a1670;
    }
    MSG_WriteString(&local_2c,"0");
    pcVar1 = pcVar1->next;
  } while( true );
}


// SVC_ServiceChallenge  @ 0009bf50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_ServiceChallenge(void)

{
  netadr_t a;
  netadr_t to;
  char *s1;
  int iVar1;
  qboolean qVar2;
  int32 iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int local_a0;
  char local_9c [140];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int oldest@[???]
                       Unresolved local var: int oldestTime@[???]
                       Unresolved local var: char[128] data@[???]
                       Unresolved local var: char * type@[???] */
  s1 = Cmd_Argv(1);
  if ((s1 != (char *)0x0) && (*s1 != '\0')) {
    iVar1 = Q_stricmp(s1,"rcon");
    if (iVar1 == 0) {
      piVar5 = &g_rg_sv_challenges[0].time;
      local_a0 = 0;
      iVar6 = 0x7fffffff;
      iVar1 = 0;
      do {
        a.ip[0] = net_from.ip[0];
        a.ip[1] = net_from.ip[1];
        a.ip[2] = net_from.ip[2];
        a.ip[3] = net_from.ip[3];
        a.type = net_from.type;
        a.ipx[0] = net_from.ipx[0];
        a.ipx[1] = net_from.ipx[1];
        a.ipx[2] = net_from.ipx[2];
        a.ipx[3] = net_from.ipx[3];
        a.ipx[4] = net_from.ipx[4];
        a.ipx[5] = net_from.ipx[5];
        a.ipx[6] = net_from.ipx[6];
        a.ipx[7] = net_from.ipx[7];
        a.ipx[8] = net_from.ipx[8];
        a.ipx[9] = net_from.ipx[9];
        a.port = net_from.port;
        qVar2 = NET_CompareBaseAdr(a,g_rg_sv_challenges[iVar1].adr);
        if (qVar2 != false) goto LAB_0009c03f;
        if (*piVar5 < iVar6) {
          iVar6 = *piVar5;
          local_a0 = iVar1;
        }
        iVar1 = iVar1 + 1;
        piVar5 = piVar5 + 7;
      } while (iVar1 != 0x400);
      iVar3 = RandomLong(0,0x8fff);
      uVar4 = RandomLong(0,0xffff);
      g_rg_sv_challenges[local_a0].challenge = iVar3 << 0x10 | uVar4;
      g_rg_sv_challenges[local_a0].adr.type = net_from.type;
      *&g_rg_sv_challenges[local_a0].adr.ip = net_from.ip;
      *(undefined4 *)g_rg_sv_challenges[local_a0].adr.ipx = net_from.ipx._0_4_;
      *(undefined4 *)(g_rg_sv_challenges[local_a0].adr.ipx + 4) = net_from.ipx._4_4_;
      *(undefined4 *)(g_rg_sv_challenges[local_a0].adr.ipx + 8) = net_from._16_4_;
      g_rg_sv_challenges[local_a0].time = (int)realtime;
      iVar1 = local_a0;
LAB_0009c03f:
      snprintf(local_9c,0x80,"%c%c%c%cchallenge %s %u\n",0xff,0xff,0xff,0xff,s1,
               g_rg_sv_challenges[iVar1].challenge);
      iVar1 = Q_strlen(local_9c);
      to.ip[0] = net_from.ip[0];
      to.ip[1] = net_from.ip[1];
      to.ip[2] = net_from.ip[2];
      to.ip[3] = net_from.ip[3];
      to.type = net_from.type;
      to.ipx[0] = net_from.ipx[0];
      to.ipx[1] = net_from.ipx[1];
      to.ipx[2] = net_from.ipx[2];
      to.ipx[3] = net_from.ipx[3];
      to.ipx[4] = net_from.ipx[4];
      to.ipx[5] = net_from.ipx[5];
      to.ipx[6] = net_from.ipx[6];
      to.ipx[7] = net_from.ipx[7];
      to.ipx[8] = net_from.ipx[8];
      to.ipx[9] = net_from.ipx[9];
      to.port = net_from.port;
      NET_SendPacket(NS_SERVER,iVar1 + 1,local_9c,to);
      return;
    }
  }
  return;
}


// SVC_ServiceChallenge  @ 000a00a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_ServiceChallenge(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int oldest@[???]
                       Unresolved local var: int oldestTime@[???]
                       Unresolved local var: char[128] data@[???]
                       Unresolved local var: char * type@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    return;
  }
  SVC_ServiceChallenge();
  return;
}


