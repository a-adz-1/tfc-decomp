// SVC_GameDllQuery  @ 000809c0
/* WARNING: Type propagation algorithm not settling */

int __regparm3 SVC_GameDllQuery(char *s)

{
  netadr_t to;
  int iVar1;
  int in_GS_OFFSET;
  int local_814 [2];
  char local_80c [2044];
  int local_10;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int maxsize@[???]
                       Unresolved local var: byte[2048] data@[???]
                       Unresolved local var: int valid@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_814 + 1,0,0x800);
  local_814[0] = 0x7fc;
  iVar1 = (*gEntityInterface.pfnConnectionlessPacket)(&net_from,s,local_80c,local_814);
  if ((local_814[0] < 0x7fd) && (local_814[0] != 0)) {
    local_814[1] = 0xffffffff;
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
    NET_SendPacket(NS_SERVER,local_814[0] + 4,local_814 + 1,to);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SVC_GameDllQuery  @ 00088080
int SVC_GameDllQuery(char *s)

{
  int iVar1;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int maxsize@[???]
                       Unresolved local var: byte[2048] data@[???]
                       Unresolved local var: int valid@[???] */
  if ((sv.active != false) && (1 < svs.maxclients)) {
    iVar1 = SVC_GameDllQuery(s);
    return iVar1;
  }
  return 0;
}


// SVC_GetChallenge  @ 00086230
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_GetChallenge(void)

{
  netadr_t a;
  netadr_t to;
  bool bVar1;
  int iVar2;
  qboolean qVar3;
  qboolean qVar4;
  int32 iVar5;
  uint uVar6;
  char *s1;
  int iVar7;
  int *piVar8;
  int iVar9;
  int in_GS_OFFSET;
  uint64 uVar10;
  char local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int oldest@[???]
                       Unresolved local var: int oldestTime@[???]
                       Unresolved local var: char[1024] data@[???]
                       Unresolved local var: int protocol@[???]
                       Unresolved local var: qboolean steam@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = Cmd_Argc();
  if (iVar2 == 2) {
    s1 = Cmd_Argv(1);
    iVar2 = Q_stricmp(s1,"steam");
    if (iVar2 != 0) goto LAB_00086257;
                    /* Unresolved local var: uint64 uSteamID@[???] */
    uVar10 = Steam_GSGetSteamID();
    iVar2 = NET_IsConfigured();
    if ((iVar2 != 0) && (qVar4 = Steam_GSSteamIDIsValidOrLAN(uVar10), qVar4 == 0))
    goto LAB_000863e1;
    bVar1 = true;
  }
  else {
LAB_00086257:
    bVar1 = false;
  }
  piVar8 = &g_rg_sv_challenges[0].time;
  iVar9 = 0x7fffffff;
  iVar2 = 0;
  iVar7 = 0;
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
    qVar3 = NET_CompareBaseAdr(a,g_rg_sv_challenges[iVar7].adr);
    if (qVar3 != false) {
      iVar2 = iVar7;
      if (bVar1) goto LAB_00086400;
      goto LAB_0008630a;
    }
    if (*piVar8 < iVar9) {
      iVar9 = *piVar8;
      iVar2 = iVar7;
    }
    iVar7 = iVar7 + 1;
    piVar8 = piVar8 + 7;
  } while (iVar7 != 0x400);
  iVar5 = RandomLong(0,0x8fff);
  uVar6 = RandomLong(0,0xffff);
  g_rg_sv_challenges[iVar2].challenge = uVar6 | iVar5 << 0x10;
  g_rg_sv_challenges[iVar2].adr.type = net_from.type;
  *&g_rg_sv_challenges[iVar2].adr.ip = net_from.ip;
  *(undefined4 *)g_rg_sv_challenges[iVar2].adr.ipx = net_from.ipx._0_4_;
  *(undefined4 *)(g_rg_sv_challenges[iVar2].adr.ipx + 4) = net_from.ipx._4_4_;
  *(undefined4 *)(g_rg_sv_challenges[iVar2].adr.ipx + 8) = net_from._16_4_;
  g_rg_sv_challenges[iVar2].time = (int)realtime;
  if (bVar1) {
LAB_00086400:
    qVar4 = Steam_GSBSecure();
    uVar10 = Steam_GSGetSteamID();
    __snprintf_chk(local_420,0x400,1,0x400,"%c%c%c%c%c00000000 %u %i %llim %d\n",0xff,0xff,0xff,0xff
                   ,0x41,g_rg_sv_challenges[iVar2].challenge,3,uVar10,qVar4);
  }
  else {
LAB_0008630a:
    Con_DPrintf("Server requiring authentication\n");
    __snprintf_chk(local_420,0x400,1,0x400,"%c%c%c%c%c00000000 %u %i\n",0xff,0xff,0xff,0xff,0x41,
                   g_rg_sv_challenges[iVar2].challenge,2);
  }
  iVar2 = Q_strlen(local_420);
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
  NET_SendPacket(NS_SERVER,iVar2 + 1,local_420,to);
LAB_000863e1:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SVC_Info  @ 000877f0
void SVC_Info(qboolean bDetailed)

{
  netadr_t a;
  netadr_t to;
  client_s *pcVar1;
  char *pcVar2;
  qboolean qVar3;
  qboolean qVar4;
  qboolean *pqVar5;
  int c;
  int iVar6;
  qboolean c_00;
  int in_GS_OFFSET;
  sizebuf_t local_ad0;
  char local_abc [32];
  char local_a9c [260];
  char local_998 [512];
  char local_798 [512];
  byte local_598 [1400];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: byte[1400] data@[???]
                       Unresolved local var: char[512] szModURL_Info@[???]
                       Unresolved local var: char[512] szModURL_DL@[???]
                       Unresolved local var: int mod_version@[???]
                       Unresolved local var: int mod_size@[???]
                       Unresolved local var: int isMod@[???]
                       Unresolved local var: char[260] gd@[???]
                       Unresolved local var: qboolean cldll@[???]
                       Unresolved local var: qboolean svonly@[???]
                       Unresolved local var: char[32] szHLVersion@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_ad0.maxsize = 0x578;
  local_ad0.cursize = 0;
  local_ad0.data = local_598;
  local_ad0.buffername = "SVC_Info";
  local_ad0.flags = 1;
  if ((sv.active == false) || (svs.maxclients < 2)) goto LAB_00087bb7;
  iVar6 = 0;
  pcVar1 = svs.clients;
  do {
    if (((pcVar1->active != false) || (pcVar1->spawned != false)) || (pcVar1->connected != false)) {
      iVar6 = iVar6 + 1;
    }
    pcVar1 = pcVar1 + 1;
  } while (svs.clients + svs.maxclients != pcVar1);
  MSG_WriteLong(&local_ad0,-1);
  if (bDetailed == false) {
    MSG_WriteByte(&local_ad0,0x43);
    if (noip != false) goto LAB_00087bff;
LAB_000878cd:
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
    MSG_WriteString(&local_ad0,pcVar2);
  }
  else {
    MSG_WriteByte(&local_ad0,0x6d);
    if (noip == false) goto LAB_000878cd;
LAB_00087bff:
    MSG_WriteString(&local_ad0,"LOOPBACK");
  }
  pcVar2 = Cvar_VariableString("hostname");
  MSG_WriteString(&local_ad0,pcVar2);
  MSG_WriteString(&local_ad0,sv.name);
  COM_FileBase(com_gamedir,local_a9c);
  MSG_WriteString(&local_ad0,local_a9c);
  pcVar2 = (*gEntityInterface.pfnGetGameDescription)();
  MSG_WriteString(&local_ad0,pcVar2);
  MSG_WriteByte(&local_ad0,iVar6);
                    /* Unresolved local var: int maxplayers@[???] */
  iVar6 = (int)sv_visiblemaxplayers.value;
  if ((int)sv_visiblemaxplayers.value < 0) {
    iVar6 = svs.maxclients;
  }
  MSG_WriteByte(&local_ad0,iVar6);
  MSG_WriteByte(&local_ad0,0x30);
  if (bDetailed != false) {
    if (cls.state == ca_dedicated) {
      MSG_WriteByte(&local_ad0,100);
    }
    else {
      MSG_WriteByte(&local_ad0,0x6c);
    }
    MSG_WriteByte(&local_ad0,0x6c);
    iVar6 = Q_strlen(sv_password.string);
    if ((iVar6 < 1) || (iVar6 = Q_stricmp(sv_password.string,"none"), iVar6 == 0)) {
      MSG_WriteByte(&local_ad0,0);
    }
    else {
      MSG_WriteByte(&local_ad0,1);
    }
    if (gmodinfo.bIsMod == false) {
      Q_strcpy(local_998,"");
      Q_strcpy(local_798,"");
      Q_strcpy(local_abc,"");
      qVar3 = true;
      iVar6 = 1;
      c = 0;
      c_00 = false;
    }
    else {
      Q_strcpy(local_998,gmodinfo.szInfo);
      Q_strcpy(local_798,gmodinfo.szDL);
      Q_strcpy(local_abc,gmodinfo.szHLVersion);
      qVar3 = gmodinfo.svonly;
      iVar6 = gmodinfo.version;
      c = gmodinfo.size;
      c_00 = gmodinfo.cldll;
    }
    if (gmodinfo.bIsMod == false) {
      MSG_WriteByte(&local_ad0,0);
    }
    else {
      MSG_WriteByte(&local_ad0,1);
      MSG_WriteString(&local_ad0,local_998);
      MSG_WriteString(&local_ad0,local_798);
      MSG_WriteString(&local_ad0,"");
      MSG_WriteLong(&local_ad0,iVar6);
      MSG_WriteLong(&local_ad0,c);
      MSG_WriteByte(&local_ad0,qVar3);
      MSG_WriteByte(&local_ad0,c_00);
    }
    qVar4 = Steam_GSBSecure();
    MSG_WriteByte(&local_ad0,(uint)(qVar4 != 0));
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int fakeclients@[???] */
    if (svs.maxclients < 1) {
      iVar6 = 0;
    }
    else {
      pqVar5 = &(svs.clients)->fakeclient;
      iVar6 = 0;
      do {
        qVar3 = *pqVar5;
        pqVar5 = pqVar5 + 0x199a;
        iVar6 = (iVar6 + 1) - (uint)(qVar3 == false);
      } while (pqVar5 != &svs.clients[svs.maxclients].fakeclient);
    }
    MSG_WriteByte(&local_ad0,iVar6);
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
  NET_SendPacket(NS_SERVER,local_ad0.cursize,local_ad0.data,to);
LAB_00087bb7:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SVC_InfoString  @ 00087150
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_InfoString(void)

{
  netadr_t a;
  netadr_t to;
  client_s *pcVar1;
  char *pcVar2;
  qboolean qVar3;
  qboolean *pqVar4;
  qboolean qVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int in_GS_OFFSET;
  uint local_fc4;
  char *local_fc0;
  char local_fb2 [2];
  sizebuf_t local_fb0;
  char local_f9c [255];
  undefined1 local_e9d;
  char local_e9c [260];
  byte local_d98 [1400];
  char local_820 [2048];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int proxy@[???]
                       Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: byte[1400] data@[???]
                       Unresolved local var: char[256] address@[???]
                       Unresolved local var: char[260] gd@[???]
                       Unresolved local var: char[2048] info@[???]
                       Unresolved local var: int iHasPW@[???]
                       Unresolved local var: char[2] szOS@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_fb0.maxsize = 0x578;
  local_fb0.cursize = 0;
  local_fb0.data = local_d98;
  local_fb0.buffername = "SVC_InfoString";
  local_fb0.flags = 1;
  if (((noip == false) && (sv.active != false)) && (1 < svs.maxclients)) {
    iVar7 = 0;
    iVar8 = 0;
    pcVar1 = svs.clients;
    do {
      if (((pcVar1->active != false) || (pcVar1->spawned != false)) || (pcVar1->connected != false))
      {
        iVar8 = (iVar8 + 1) - (uint)(pcVar1->proxy == false);
        iVar7 = iVar7 + 1;
      }
      pcVar1 = pcVar1 + 1;
    } while (svs.clients + svs.maxclients != pcVar1);
    local_f9c[0] = '\0';
    a.ip = net_local_adr.ip;
    a.type = net_local_adr.type;
    a.ipx._0_4_ = net_local_adr.ipx._0_4_;
    a.ipx._4_4_ = net_local_adr.ipx._4_4_;
    a._16_4_ = net_local_adr._16_4_;
    pcVar2 = NET_AdrToString(a);
    Q_strncpy(local_f9c,pcVar2,0xff);
    local_e9d = 0;
    if (*sv_password.string == '\0') {
      Q_strcpy(local_fb2,"l");
      local_820[0] = '\0';
      pcVar2 = va("%i",0x30);
      Info_SetValueForKey(local_820,"protocol",pcVar2,0x800);
      Info_SetValueForKey(local_820,"address",local_f9c,0x800);
      pcVar2 = va("%i",iVar7);
      Info_SetValueForKey(local_820,"players",pcVar2,0x800);
      local_fc4 = 0;
    }
    else {
      iVar6 = Q_stricmp(sv_password.string,"none");
      local_fc4 = (uint)(iVar6 != 0);
      Q_strcpy(local_fb2,"l");
      local_820[0] = '\0';
      pcVar2 = va("%i",0x30);
      Info_SetValueForKey(local_820,"protocol",pcVar2,0x800);
      Info_SetValueForKey(local_820,"address",local_f9c,0x800);
      pcVar2 = va("%i",iVar7);
      Info_SetValueForKey(local_820,"players",pcVar2,0x800);
    }
    local_fc0 = local_fb2;
                    /* Unresolved local var: int maxplayers@[???] */
    pcVar2 = va("%i",iVar8);
    Info_SetValueForKey(local_820,"proxytarget",pcVar2,0x800);
    qVar3 = Master_IsLanGame();
    pcVar2 = va("%i",(uint)(qVar3 != false));
    Info_SetValueForKey(local_820,"lan",pcVar2,0x800);
    iVar7 = (int)sv_visiblemaxplayers.value;
    if ((int)sv_visiblemaxplayers.value < 0) {
      iVar7 = svs.maxclients;
    }
    pcVar2 = va("%i",iVar7);
    Info_SetValueForKey(local_820,"max",pcVar2,0x800);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int fakeclients@[???] */
    if (svs.maxclients < 1) {
      iVar7 = 0;
    }
    else {
      pqVar4 = &(svs.clients)->fakeclient;
      iVar7 = 0;
      do {
        qVar3 = *pqVar4;
        pqVar4 = pqVar4 + 0x199a;
        iVar7 = (iVar7 + 1) - (uint)(qVar3 == false);
      } while (&svs.clients[svs.maxclients].fakeclient != pqVar4);
    }
    pcVar2 = va("%i",iVar7);
    Info_SetValueForKey(local_820,"bots",pcVar2,0x800);
    COM_FileBase(com_gamedir,local_e9c);
    Info_SetValueForKey(local_820,"gamedir",local_e9c,0x800);
    pcVar2 = (*gEntityInterface.pfnGetGameDescription)();
    Info_SetValueForKey(local_820,"description",pcVar2,0x800);
    pcVar2 = Cvar_VariableString("hostname");
    Info_SetValueForKey(local_820,"hostname",pcVar2,0x800);
    Info_SetValueForKey(local_820,"map",sv.name,0x800);
    pcVar2 = "l";
    if (cls.state == ca_dedicated) {
      pcVar2 = "d";
    }
    Info_SetValueForKey(local_820,"type",pcVar2,0x800);
    pcVar2 = va("%i",local_fc4);
    Info_SetValueForKey(local_820,"password",pcVar2,0x800);
    Info_SetValueForKey(local_820,"os",local_fc0,0x800);
    qVar5 = Steam_GSBSecure();
    pcVar2 = "0";
    if (qVar5 != 0) {
      pcVar2 = "1";
    }
    Info_SetValueForKey(local_820,"secure",pcVar2,0x800);
    if (gmodinfo.bIsMod != false) {
      pcVar2 = va("%i",1);
      Info_SetValueForKey(local_820,"mod",pcVar2,0x800);
      pcVar2 = va("%i",gmodinfo.version);
      Info_SetValueForKey(local_820,"modversion",pcVar2,0x800);
      pcVar2 = va("%i",gmodinfo.svonly);
      Info_SetValueForKey(local_820,"svonly",pcVar2,0x800);
      pcVar2 = va("%i",gmodinfo.cldll);
      Info_SetValueForKey(local_820,"cldll",pcVar2,0x800);
    }
    MSG_WriteLong(&local_fb0,-1);
    MSG_WriteString(&local_fb0,"infostringresponse");
    MSG_WriteString(&local_fb0,local_820);
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
    NET_SendPacket(NS_SERVER,local_fb0.cursize,local_fb0.data,to);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SVC_Ping  @ 000861a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_Ping(void)

{
  netadr_t to;
  int in_GS_OFFSET;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[6] data@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_16 = 0xff;
  local_15 = 0xff;
  local_14 = 0xff;
  local_13 = 0xff;
  local_12 = 0x6a;
  local_11 = 0;
  to.ip = net_from.ip;
  to.type = net_from.type;
  to.ipx._0_4_ = net_from.ipx._0_4_;
  to.ipx._4_4_ = net_from.ipx._4_4_;
  to._16_4_ = net_from._16_4_;
  NET_SendPacket(NS_SERVER,6,&local_16,to);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SVC_PlayerInfo  @ 00087ce0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_PlayerInfo(void)

{
  netadr_t to;
  qboolean *pqVar1;
  client_s *pcVar2;
  int c;
  int iVar3;
  char *s;
  int iVar4;
  int in_GS_OFFSET;
  sizebuf_t local_834;
  byte local_820 [2048];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: byte[2048] data@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_834.data = local_820;
  local_834.buffername = "SVC_PlayerInfo";
  local_834.maxsize = 0x800;
  local_834.cursize = 0;
  local_834.flags = 1;
  if ((sv.active != false) && (1 < svs.maxclients)) {
    MSG_WriteLong(&local_834,-1);
    MSG_WriteByte(&local_834,0x44);
    if (svs.maxclients < 1) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      pcVar2 = svs.clients;
      do {
        pqVar1 = &pcVar2->active;
        pcVar2 = pcVar2 + 1;
        iVar3 = (iVar3 + 1) - (uint)(*pqVar1 == false);
      } while (pcVar2 != svs.clients + svs.maxclients);
    }
    MSG_WriteByte(&local_834,iVar3);
    pcVar2 = svs.clients;
    if (0 < svs.maxclients) {
      c = 0;
      s = (svs.clients)->name;
      iVar4 = 0;
      iVar3 = svs.maxclients;
      do {
        if (*(int *)(s + (int)svs.clients + (-0x6358 - (int)pcVar2)) == 0) {
          if (iVar3 <= iVar4 + 1) break;
        }
        else {
          c = c + 1;
          MSG_WriteByte(&local_834,c);
          MSG_WriteString(&local_834,s);
          MSG_WriteLong(&local_834,(int)((*(edict_t **)(s + -0x164))->v).frags);
          MSG_WriteFloat(&local_834,(float)realtime - *(float *)(s + -0x631c));
          iVar3 = svs.maxclients;
          if (svs.maxclients <= iVar4 + 1) break;
        }
        iVar4 = iVar4 + 1;
        s = s + 0x6668;
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
    NET_SendPacket(NS_SERVER,local_834.cursize,local_834.data,to);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SVC_RuleInfo  @ 00087ec0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_RuleInfo(void)

{
  netadr_t to;
  int iVar1;
  cvar_s *pcVar2;
  int in_GS_OFFSET;
  sizebuf_t local_2024;
  byte local_2010 [8192];
  int local_10;
  
                    /* Unresolved local var: int nNumRules@[???]
                       Unresolved local var: cvar_t * var@[???]
                       Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: byte[8192] data@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_2024.buffername = "SVC_RuleInfo";
  local_2024.maxsize = 0x2000;
  local_2024.cursize = 0;
  local_2024.data = local_2010;
  local_2024.flags = 1;
  if (((sv.active == false) || (svs.maxclients < 2)) ||
     (iVar1 = Cvar_CountServerVariables(), iVar1 < 1)) {
LAB_00088020:
    if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  MSG_WriteLong(&local_2024,-1);
  MSG_WriteByte(&local_2024,0x45);
  MSG_WriteShort(&local_2024,iVar1);
  pcVar2 = cvar_vars;
joined_r0x00087f61:
  if (pcVar2 != (cvar_t *)0x0) {
    do {
      if ((pcVar2->flags & 4) != 0) {
        MSG_WriteString(&local_2024,pcVar2->name);
        if ((pcVar2->flags & 0x20) == 0) {
          MSG_WriteString(&local_2024,pcVar2->string);
        }
        else {
          iVar1 = Q_strlen(pcVar2->string);
          if ((iVar1 < 1) || (iVar1 = Q_stricmp(pcVar2->string,"none"), iVar1 == 0))
          goto LAB_00087fb8;
          MSG_WriteString(&local_2024,"1");
        }
      }
      pcVar2 = pcVar2->next;
      if (pcVar2 == (cvar_s *)0x0) break;
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
  NET_SendPacket(NS_SERVER,local_2024.cursize,local_2024.data,to);
  goto LAB_00088020;
LAB_00087fb8:
  MSG_WriteString(&local_2024,"0");
  pcVar2 = pcVar2->next;
  goto joined_r0x00087f61;
}


// SVC_ServiceChallenge  @ 000865b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SVC_ServiceChallenge(void)

{
  netadr_t a;
  netadr_t to;
  int iVar1;
  char *s1;
  qboolean qVar2;
  int32 iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int in_GS_OFFSET;
  int local_b0;
  char local_a0 [128];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int oldest@[???]
                       Unresolved local var: int oldestTime@[???]
                       Unresolved local var: char[128] data@[???]
                       Unresolved local var: char * type@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    s1 = Cmd_Argv(1);
    if ((s1 != (char *)0x0) && (*s1 != '\0')) {
      iVar1 = Q_stricmp(s1,"rcon");
      if (iVar1 == 0) {
        piVar5 = &g_rg_sv_challenges[0].time;
        iVar6 = 0x7fffffff;
        iVar1 = 0;
        local_b0 = 0;
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
          if (qVar2 != false) goto LAB_00086700;
          if (*piVar5 < iVar6) {
            iVar6 = *piVar5;
            local_b0 = iVar1;
          }
          iVar1 = iVar1 + 1;
          piVar5 = piVar5 + 7;
        } while (iVar1 != 0x400);
        iVar3 = RandomLong(0,0x8fff);
        uVar4 = RandomLong(0,0xffff);
        g_rg_sv_challenges[local_b0].challenge = uVar4 | iVar3 << 0x10;
        g_rg_sv_challenges[local_b0].adr.type = net_from.type;
        *&g_rg_sv_challenges[local_b0].adr.ip = net_from.ip;
        *(undefined4 *)g_rg_sv_challenges[local_b0].adr.ipx = net_from.ipx._0_4_;
        *(undefined4 *)(g_rg_sv_challenges[local_b0].adr.ipx + 4) = net_from.ipx._4_4_;
        *(undefined4 *)(g_rg_sv_challenges[local_b0].adr.ipx + 8) = net_from._16_4_;
        g_rg_sv_challenges[local_b0].time = (int)realtime;
        iVar1 = local_b0;
LAB_00086700:
        __snprintf_chk(local_a0,0x80,1,0x80,"%c%c%c%cchallenge %s %u\n",0xff,0xff,0xff,0xff,s1,
                       g_rg_sv_challenges[iVar1].challenge);
        iVar1 = Q_strlen(local_a0);
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
        NET_SendPacket(NS_SERVER,iVar1 + 1,local_a0,to);
      }
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


