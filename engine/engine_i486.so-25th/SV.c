// SV_ActivateServer  @ 0008ea20
void SV_ActivateServer(int runPhysics)

{
  sizebuf_t *sb;
  int iVar1;
  UserMsg *pUVar2;
  client_t *pcVar3;
  int iVar4;
  _UserMsg *p_Var5;
  int iVar6;
  int in_GS_OFFSET;
  sizebuf_t sStack_10034;
  byte abStack_10020 [65552];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uchar[65536] data@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&sStack_10034,0,0x14);
  sStack_10034.data = abStack_10020;
  sStack_10034.buffername = "Activate Server";
  sStack_10034.cursize = 0;
  sStack_10034.maxsize = 0x10000;
  if (g_bCS_CZ_Flags_Initialized == 0) {
    iVar4 = strcasecmp(com_gamedir,"cstrike");
    if ((iVar4 == 0) || (iVar4 = strcasecmp(com_gamedir,"cstrike_beta"), iVar4 == 0)) {
      g_bIsCStrike = 1;
    }
    else {
      iVar4 = strcasecmp(com_gamedir,"czero");
      if (iVar4 == 0) {
        g_bIsCZero = 1;
      }
      else {
        iVar4 = strcasecmp(com_gamedir,"czeror");
        if (iVar4 == 0) {
          g_bIsCZeroRitual = 1;
        }
        else {
          iVar4 = strcasecmp(com_gamedir,"terror");
          if (iVar4 == 0) {
            g_bIsTerrorStrike = 1;
          }
          else {
            iVar4 = strcasecmp(com_gamedir,"tfc");
            if (iVar4 == 0) {
              g_bIsTFC = 1;
            }
            else {
              iVar4 = strcasecmp(com_gamedir,"valve");
              if (iVar4 == 0) {
                g_bIsHL1 = 1;
              }
            }
          }
        }
      }
    }
    g_bCS_CZ_Flags_Initialized = 1;
  }
  Cvar_Set("sv_newunit","0");
  ContinueLoadingProgressBar("Server",8,0.0);
  (*gEntityInterface.pfnServerActivate)(sv.edicts,sv.num_edicts,svs.maxclients);
  Steam_Activate();
  ContinueLoadingProgressBar("Server",9,0.0);
  SV_CreateGenericResources();
  sv.active = true;
  sv.state = ss_active;
  ContinueLoadingProgressBar("Server",10,0.0);
  if (runPhysics == 0) {
    host_frametime._0_4_ = 0xd2f1a9fc;
    host_frametime._4_4_ = 0x3f50624d;
    SV_Physics();
  }
  else {
    host_frametime._0_4_ = 0x9999999a;
    if (svs.maxclients < 2) {
      host_frametime._4_4_ = 0x3fb99999;
      SV_Physics();
      SV_Physics();
    }
    else {
      iVar4 = 0x10;
      host_frametime._4_4_ = 0x3fe99999;
      do {
        SV_Physics();
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  SV_CreateBaseline();
  iVar6 = 0;
  SV_CreateResourceList();
  sv.num_consistency = SV_TransferConsistencyInfo();
  host_client = svs.clients;
  iVar4 = svs.maxclients;
  if (0 < svs.maxclients) {
    do {
      while (((host_client->active == false && (host_client->connected == false)) ||
             (host_client->fakeclient != false))) {
        iVar6 = iVar6 + 1;
        host_client = host_client + 1;
        if (iVar4 <= iVar6) goto LAB_0008ed30;
      }
      Netchan_Clear(&host_client->netchan);
      if (svs.maxclients < 2) {
        SV_SendServerinfo(&sStack_10034,host_client);
      }
      else {
        sb = &(host_client->netchan).message;
        MSG_WriteByte(sb,9);
        MSG_WriteString(sb,"reconnect\n");
        Netchan_Transmit(&host_client->netchan,0,(byte *)0x0);
      }
      pUVar2 = sv_gpNewUserMsgs;
      if (sv_gpUserMsgs != (UserMsg *)0x0) {
                    /* Unresolved local var: UserMsg * pTemp@[???] */
        sv_gpNewUserMsgs = sv_gpUserMsgs;
        p_Var5 = sv_gpUserMsgs;
        do {
                    /* Unresolved local var: UserMsg * pMsg@[???] */
          MSG_WriteByte(&sStack_10034,0x27);
          MSG_WriteByte(&sStack_10034,p_Var5->iMsg);
          MSG_WriteByte(&sStack_10034,p_Var5->iSize);
          MSG_WriteLong(&sStack_10034,*(int *)p_Var5->szName);
          MSG_WriteLong(&sStack_10034,*(int *)(p_Var5->szName + 4));
          MSG_WriteLong(&sStack_10034,*(int *)(p_Var5->szName + 8));
          MSG_WriteLong(&sStack_10034,*(int *)(p_Var5->szName + 0xc));
          p_Var5 = p_Var5->next;
        } while (p_Var5 != (_UserMsg *)0x0);
      }
      pcVar3 = host_client;
      iVar6 = iVar6 + 1;
      sv_gpNewUserMsgs = pUVar2;
      host_client->hasusrmsgs = true;
      Netchan_CreateFragments(true,&pcVar3->netchan,&sStack_10034);
      Netchan_FragSend(&host_client->netchan);
      SZ_Clear(&sStack_10034);
      host_client = host_client + 1;
      iVar4 = svs.maxclients;
    } while (iVar6 < svs.maxclients);
  }
LAB_0008ed30:
  HPAK_FlushHostQueue();
  if (svs.maxclients < 2) {
    Con_DPrintf("Game started\n");
  }
  else {
    Con_DPrintf("%i player server started\n",svs.maxclients);
  }
  Log_Printf("Started map \"%s\" (CRC \"%i\")\n",0x4ff2a8,sv.worldmapCRC);
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_AddCorrectGravity  @ 0009a600
void SV_AddCorrectGravity(edict_t *ent)

{
  float fVar1;
  vec_t vVar2;
  float fVar3;
  uint uVar4;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  uVar4 = nanmask;
  fVar1 = (ent->v).gravity;
  fVar3 = 1.0;
  if (fVar1 != 0.0) {
    fVar3 = fVar1;
  }
                    /* Unresolved local var: int i@[???] */
  (ent->v).velocity[2] =
       (float)host_frametime * (ent->v).basevelocity[2] +
       ((ent->v).velocity[2] - fVar3 * sv_gravity.value * 0.5 * (float)host_frametime);
  vVar2 = (ent->v).velocity[0];
  (ent->v).basevelocity[2] = 0.0;
  if (((uint)vVar2 & uVar4) == uVar4) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar4 = nanmask;
    (ent->v).velocity[0] = 0.0;
  }
  if (((uint)(ent->v).origin[0] & uVar4) == uVar4) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[0] = 0.0;
  }
  fVar1 = (ent->v).velocity[0];
  if (sv_maxvelocity.value < fVar1) {
    Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[0] = sv_maxvelocity.value;
  }
  else if (fVar1 < -sv_maxvelocity.value) {
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[0] = -sv_maxvelocity.value;
  }
  uVar4 = nanmask;
  if (nanmask == ((uint)(ent->v).velocity[1] & nanmask)) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar4 = nanmask;
    (ent->v).velocity[1] = 0.0;
  }
  if (uVar4 == ((uint)(ent->v).origin[1] & uVar4)) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[1] = 0.0;
  }
  fVar1 = (ent->v).velocity[1];
  if (sv_maxvelocity.value < fVar1) {
    Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[1] = sv_maxvelocity.value;
  }
  else if (fVar1 < -sv_maxvelocity.value) {
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[1] = -sv_maxvelocity.value;
  }
  uVar4 = nanmask;
  if (nanmask == ((uint)(ent->v).velocity[2] & nanmask)) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar4 = nanmask;
    (ent->v).velocity[2] = 0.0;
  }
  if (((uint)(ent->v).origin[2] & uVar4) == uVar4) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[2] = 0.0;
  }
  fVar1 = (ent->v).velocity[2];
  if (fVar1 <= sv_maxvelocity.value) {
    if (-sv_maxvelocity.value <= fVar1) {
      return;
    }
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[2] = -sv_maxvelocity.value;
    return;
  }
  Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
  (ent->v).velocity[2] = sv_maxvelocity.value;
  return;
}


// SV_AddFailedRcon  @ 000882e0
void SV_AddFailedRcon(netadr_t *adr)

{
  undefined8 uVar1;
  undefined4 uVar2;
  bool bVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  qboolean qVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  uint uVar13;
  float *pfVar14;
  uint uVar15;
  rcon_failure_t *prVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  float local_38;
  int local_34;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int best@[???]
                       Unresolved local var: float best_update@[???]
                       Unresolved local var: float time@[???]
                       Unresolved local var: qboolean found@[???]
                       Unresolved local var: rcon_failure_t * r@[???]
                       Unresolved local var: int failed@[???] */
  iVar7 = (int)sv_rcon_minfailures.value;
  sv_rcon_minfailures.value = (float)iVar7;
  sv_rcon_maxfailures.value = (float)(int)sv_rcon_maxfailures.value;
  sv_rcon_minfailuretime.value = (float)(int)sv_rcon_minfailuretime.value;
  if ((float)iVar7 < 1.0) {
    Cvar_SetValue("sv_rcon_minfailures",1.0);
  }
  if (20.0 < sv_rcon_minfailures.value) {
    Cvar_SetValue("sv_rcon_minfailures",20.0);
  }
  if (sv_rcon_maxfailures.value < 1.0) {
    Cvar_SetValue("sv_rcon_maxfailures",1.0);
  }
  if (20.0 < sv_rcon_maxfailures.value) {
    Cvar_SetValue("sv_rcon_maxfailures",20.0);
  }
  fVar6 = sv_rcon_maxfailures.value;
  if (sv_rcon_maxfailures.value < sv_rcon_minfailures.value) {
                    /* Unresolved local var: float temp@[???] */
    Cvar_SetValue("sv_rcon_maxfailures",sv_rcon_minfailures.value);
    Cvar_SetValue("sv_rcon_minfailures",fVar6);
  }
  if (sv_rcon_minfailuretime.value < 1.0) {
    Cvar_SetValue("sv_rcon_minfailuretime",1.0);
  }
  prVar16 = g_rgRconFailures;
  local_34 = 0;
  iVar7 = 0;
  local_38 = -99999.0;
  do {
    if (prVar16->active == false) {
      fVar6 = (float)realtime;
      goto LAB_0008845a;
    }
    qVar8 = NET_CompareAdr(prVar16->adr,*adr);
    if (qVar8 != false) {
      if (g_rgRconFailures[iVar7].shouldreject != false) {
        return;
      }
      fVar6 = (float)realtime;
      g_rgRconFailures[iVar7].shouldreject = false;
      g_rgRconFailures[iVar7].active = true;
      uVar17 = g_rgRconFailures[iVar7].num_failures;
      g_rgRconFailures[iVar7].last_update = fVar6;
      fVar5 = sv_rcon_maxfailures.value;
      g_rgRconFailures[iVar7].adr.type = adr->type;
      *(undefined4 *)g_rgRconFailures[iVar7].adr.ip = *(undefined4 *)adr->ip;
      *(undefined4 *)g_rgRconFailures[iVar7].adr.ipx = *(undefined4 *)adr->ipx;
      *(undefined4 *)(g_rgRconFailures[iVar7].adr.ipx + 4) = *(undefined4 *)(adr->ipx + 4);
      *(undefined4 *)(g_rgRconFailures[iVar7].adr.ipx + 8) = *(undefined4 *)(adr->ipx + 8);
      if (fVar5 <= (float)(int)uVar17) {
        iVar7 = uVar17 - 1;
        goto LAB_00088757;
      }
      iVar7 = prVar16->num_failures;
      uVar17 = iVar7 + 1;
      goto LAB_000887a3;
    }
    fVar6 = (float)realtime;
    fVar5 = fVar6 - prVar16->last_update;
    if (local_38 < fVar5) {
      local_38 = fVar5;
      local_34 = iVar7;
    }
    iVar7 = iVar7 + 1;
    prVar16 = prVar16 + 1;
  } while (iVar7 != 0x20);
  prVar16 = g_rgRconFailures + local_34;
LAB_0008845a:
  prVar16->active = true;
  prVar16->shouldreject = false;
  prVar16->last_update = fVar6;
  fVar5 = sv_rcon_maxfailures.value;
  bVar3 = 0.0 < sv_rcon_maxfailures.value;
  (prVar16->adr).type = adr->type;
  *(undefined4 *)(prVar16->adr).ip = *(undefined4 *)adr->ip;
  *(undefined4 *)(prVar16->adr).ipx = *(undefined4 *)adr->ipx;
  *(undefined4 *)((prVar16->adr).ipx + 4) = *(undefined4 *)(adr->ipx + 4);
  uVar2 = *(undefined4 *)(adr->ipx + 8);
  prVar16->num_failures = 0;
  *(undefined4 *)((prVar16->adr).ipx + 8) = uVar2;
  if (bVar3) {
    prVar16->failure_times[0] = fVar6;
    prVar16->num_failures = 1;
    uVar17 = 1;
    uVar9 = 1;
LAB_000884c7:
    uVar15 = (uint)(fVar6 - prVar16->failure_times[0] < sv_rcon_minfailuretime.value);
    if (uVar9 == 1) {
      local_38 = 1.4013e-45;
    }
    else {
      uVar15 = uVar15 + (fVar6 - prVar16->failure_times[1] < sv_rcon_minfailuretime.value);
      if (uVar9 == 2) {
        local_38 = 2.8026e-45;
      }
      else {
        uVar15 = uVar15 + (fVar6 - prVar16->failure_times[2] < sv_rcon_minfailuretime.value);
        if (uVar9 == 3) {
          local_38 = 4.2039e-45;
        }
        else {
          uVar15 = uVar15 + (fVar6 - prVar16->failure_times[3] < sv_rcon_minfailuretime.value);
          if (uVar9 == 5) {
            uVar15 = uVar15 + (fVar6 - prVar16->failure_times[4] < sv_rcon_minfailuretime.value);
            local_38 = 7.00649e-45;
          }
          else {
            local_38 = 5.60519e-45;
          }
        }
      }
    }
    uVar13 = uVar9;
    if (uVar9 != uVar17) goto LAB_0008857d;
  }
  else {
    uVar17 = 0;
    iVar7 = -1;
LAB_00088757:
    iVar12 = 1;
    if (1.0 < fVar5) {
      do {
        prVar16->failure_times[iVar12 + -1] = prVar16->failure_times[iVar12];
        iVar12 = iVar12 + 1;
      } while ((float)iVar12 < fVar5);
    }
    prVar16->num_failures = iVar7;
LAB_000887a3:
    prVar16->num_failures = uVar17;
    prVar16->failure_times[iVar7] = fVar6;
    if ((int)uVar17 < 1) {
      fVar6 = 0.0;
      goto LAB_000886f8;
    }
    uVar13 = -(((uint)prVar16->failure_times & 0xf) >> 2) & 3;
    if (uVar17 < uVar13) {
      uVar13 = uVar17;
    }
    uVar9 = uVar17;
    if (((int)uVar17 < 6) || (uVar9 = uVar13, uVar13 != 0)) goto LAB_000884c7;
    uVar15 = 0;
    local_38 = 0.0;
LAB_0008857d:
    uVar9 = ((uVar17 - uVar13) - 4 >> 2) + 1;
    iVar12 = uVar9 * 4;
    iVar7 = uVar17 - 1;
    if ((int)uVar17 < 1) {
      iVar7 = 0;
    }
    if (2 < iVar7 - uVar13) {
      uVar10 = 0;
      iVar7 = 0;
      iVar18 = 0;
      iVar19 = 0;
      iVar20 = 0;
      pfVar14 = prVar16->failure_times + uVar13;
      do {
        pfVar4 = pfVar14 + 2;
        uVar1 = *(undefined8 *)pfVar14;
        uVar10 = uVar10 + 1;
        pfVar14 = pfVar14 + 4;
        iVar7 = iVar7 + (-(uint)(fVar6 - (float)uVar1 < sv_rcon_minfailuretime.value) & 1);
        iVar18 = iVar18 + (-(uint)(fVar6 - (float)((ulonglong)uVar1 >> 0x20) <
                                  sv_rcon_minfailuretime.value) & 1);
        iVar19 = iVar19 + (-(uint)(fVar6 - (float)*(undefined8 *)pfVar4 <
                                  sv_rcon_minfailuretime.value) & 1);
        iVar20 = iVar20 + (-(uint)(fVar6 - (float)((ulonglong)*(undefined8 *)pfVar4 >> 0x20) <
                                  sv_rcon_minfailuretime.value) & 1);
      } while (uVar10 < uVar9);
      local_38 = (float)((int)local_38 + iVar12);
      uVar15 = uVar15 + iVar7 + iVar19 + iVar18 + iVar20;
      if (uVar17 - uVar13 == iVar12) goto LAB_000886f0;
    }
    uVar15 = uVar15 + (fVar6 - prVar16->failure_times[(int)local_38] < sv_rcon_minfailuretime.value)
    ;
    if (((int)local_38 + 1 < (int)uVar17) &&
       (uVar15 = uVar15 + (fVar6 - prVar16->failure_times[(int)local_38 + 1] <
                          sv_rcon_minfailuretime.value), (int)local_38 + 2 < (int)uVar17)) {
      uVar15 = uVar15 + (fVar6 - prVar16->failure_times[(int)local_38 + 2] <
                        sv_rcon_minfailuretime.value);
    }
  }
LAB_000886f0:
  fVar6 = (float)(int)uVar15;
LAB_000886f8:
  if (sv_rcon_minfailures.value <= fVar6) {
    pcVar11 = NET_AdrToString(*adr);
    Con_Printf("User %s will be banned for rcon hacking\n",pcVar11);
    prVar16->shouldreject = true;
  }
  return;
}


// SV_AddGravity  @ 0009a230
void SV_AddGravity(edict_t *ent)

{
  float fVar1;
  vec_t vVar2;
  float fVar3;
  uint uVar4;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  uVar4 = nanmask;
  fVar1 = (ent->v).gravity;
  fVar3 = 1.0;
  if (fVar1 != 0.0) {
    fVar3 = fVar1;
  }
                    /* Unresolved local var: int i@[???] */
  (ent->v).velocity[2] =
       (float)host_frametime * (ent->v).basevelocity[2] +
       ((ent->v).velocity[2] - fVar3 * sv_gravity.value * (float)host_frametime);
  vVar2 = (ent->v).velocity[0];
  (ent->v).basevelocity[2] = 0.0;
  if (((uint)vVar2 & uVar4) == uVar4) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar4 = nanmask;
    (ent->v).velocity[0] = 0.0;
  }
  if (((uint)(ent->v).origin[0] & uVar4) == uVar4) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[0] = 0.0;
  }
  fVar1 = (ent->v).velocity[0];
  if (sv_maxvelocity.value < fVar1) {
    Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[0] = sv_maxvelocity.value;
  }
  else if (fVar1 < -sv_maxvelocity.value) {
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[0] = -sv_maxvelocity.value;
  }
  uVar4 = nanmask;
  if (nanmask == ((uint)(ent->v).velocity[1] & nanmask)) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar4 = nanmask;
    (ent->v).velocity[1] = 0.0;
  }
  if (uVar4 == ((uint)(ent->v).origin[1] & uVar4)) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[1] = 0.0;
  }
  fVar1 = (ent->v).velocity[1];
  if (sv_maxvelocity.value < fVar1) {
    Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[1] = sv_maxvelocity.value;
  }
  else if (fVar1 < -sv_maxvelocity.value) {
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[1] = -sv_maxvelocity.value;
  }
  uVar4 = nanmask;
  if (nanmask == ((uint)(ent->v).velocity[2] & nanmask)) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar4 = nanmask;
    (ent->v).velocity[2] = 0.0;
  }
  if (((uint)(ent->v).origin[2] & uVar4) == uVar4) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[2] = 0.0;
  }
  fVar1 = (ent->v).velocity[2];
  if (fVar1 <= sv_maxvelocity.value) {
    if (-sv_maxvelocity.value <= fVar1) {
      return;
    }
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[2] = -sv_maxvelocity.value;
    return;
  }
  Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
  (ent->v).velocity[2] = sv_maxvelocity.value;
  return;
}


// SV_AddIP_f  @ 000814d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_AddIP_f(void)

{
  uchar auVar1 [4];
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char cVar6;
  ipfilter_t *piVar7;
  char *pcVar8;
  client_s *pcVar9;
  int iVar10;
  int in_GS_OFFSET;
  float fVar11;
  float fVar12;
  uint local_bc;
  uint local_a8;
  uint local_a4;
  char local_a0 [128];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float banTime@[???]
                       Unresolved local var: ipfilter_t tempFilter@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = Cmd_Argc();
  if (iVar3 == 3) {
    iVar3 = 0;
    pcVar4 = Cmd_Argv(1);
    fVar12 = Q_atof(pcVar4);
    pcVar4 = Cmd_Argv(2);
    local_a8 = 0;
    local_a4 = 0;
    do {
                    /* Unresolved local var: char[128] num@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: byte[4] b@[???]
                       Unresolved local var: byte[4] m@[???] */
      cVar6 = *pcVar4;
      if (9 < (byte)(cVar6 - 0x30U)) {
        Con_Printf("Bad filter address: %s\n",pcVar4);
        Con_Printf(
                  "Invalid IP address!\nUsage: addip <minutes> <ipaddress>\nUse 0 minutes for permanent\n"
                  );
        goto LAB_000814ff;
      }
      iVar5 = 0;
      do {
        pcVar8 = pcVar4;
        iVar10 = iVar5;
        pcVar4 = pcVar8 + 1;
        local_a0[iVar10] = cVar6;
        cVar6 = *pcVar4;
        iVar5 = iVar10 + 1;
      } while ((byte)(cVar6 - 0x30U) < 10);
      local_a0[iVar10 + 1] = '\0';
      iVar5 = Q_atoi(local_a0);
      *(char *)((int)&local_a8 + iVar3) = (char)iVar5;
      if ((char)iVar5 != '\0') {
        local_a0[iVar3 + -4] = -1;
      }
      if (*pcVar4 == '\0') break;
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar8 + 2;
    } while (iVar3 != 4);
    if (numipfilters < 1) {
      iVar3 = 0;
    }
    else {
      piVar7 = ipfilters;
      iVar3 = 0;
      do {
        if ((piVar7->mask == local_a4) && (piVar7->compare == local_a8)) {
          ipfilters[iVar3].banTime = fVar12;
          fVar11 = 0.0;
          if (fVar12 != 0.0) {
            fVar11 = fVar12 * 60.0 + (float)realtime;
          }
          ipfilters[iVar3].banEndTime = fVar11;
          goto LAB_000814ff;
        }
        iVar3 = iVar3 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar3 != numipfilters);
      if (0x7fff < iVar3) {
        Con_Printf("IP filter list is full\n");
        goto LAB_000814ff;
      }
    }
    numipfilters = numipfilters + 1;
    if (fVar12 < 0.01) {
      ipfilters[iVar3].banTime = 0.0;
      fVar12 = 0.0;
    }
    else {
      ipfilters[iVar3].banTime = fVar12;
      if (fVar12 == 0.0) {
        fVar12 = 0.0;
      }
      else {
        fVar12 = fVar12 * 60.0 + (float)realtime;
      }
    }
    iVar5 = svs.maxclients;
    ipfilters[iVar3].mask = local_a4;
    pcVar9 = svs.clients;
    host_client = svs.clients;
    ipfilters[iVar3].compare = local_a8;
    iVar10 = 0;
    ipfilters[iVar3].banEndTime = fVar12;
    if (0 < iVar5) {
      do {
        if ((((pcVar9->connected != false) && (pcVar9->active != false)) &&
            (pcVar9->spawned != false)) && (pcVar9->fakeclient == false)) {
          net_from.type = (pcVar9->netchan).remote_address.type;
          auVar1 = *&(pcVar9->netchan).remote_address.ip;
          net_from.ipx._0_4_ = *(undefined4 *)(pcVar9->netchan).remote_address.ipx;
          net_from.ipx._4_4_ = *(undefined4 *)((pcVar9->netchan).remote_address.ipx + 4);
          net_from._16_4_ = *(undefined4 *)((pcVar9->netchan).remote_address.ipx + 8);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uint in@[???] */
          iVar3 = numipfilters + -1;
          piVar7 = ipfilters + iVar3;
          host_client = pcVar9;
          net_from.ip = auVar1;
          if (-1 < iVar3) {
            do {
              iVar2 = numipfilters;
              if (((piVar7->compare == 0xffffffff) || ((double)piVar7->banEndTime == 0.0)) ||
                 (realtime < (double)piVar7->banEndTime)) {
                if (piVar7->compare == (piVar7->mask & (uint)auVar1)) {
                  local_bc = (uint)(longlong)ROUND(sv_filterban.value);
                  goto LAB_000817f8;
                }
              }
              else {
                if (iVar3 + 1 < numipfilters) {
                  memmove(piVar7,piVar7 + 1,((numipfilters + 0xfffffff) - iVar3) * 0x10);
                }
                numipfilters = iVar2 + -1;
              }
              iVar3 = iVar3 + -1;
              piVar7 = piVar7 + -1;
            } while (iVar3 != -1);
          }
          local_bc = (uint)!NAN(sv_filterban.value);
          if (sv_filterban.value != 0.0) {
            local_bc = 0;
          }
LAB_000817f8:
          if (local_bc != 0) {
            SV_ClientPrintf("The server operator has added you to banned list\n");
            SV_DropClient(host_client,false,"Added to banned list");
            pcVar9 = host_client;
            iVar5 = svs.maxclients;
          }
        }
        iVar10 = iVar10 + 1;
        pcVar9 = pcVar9 + 1;
        host_client = pcVar9;
      } while (iVar10 < iVar5);
    }
  }
  else {
    Con_Printf("Usage: addip <minutes> <ipaddress>\nUse 0 minutes for permanent\n");
  }
LAB_000814ff:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_AddLinksToPM  @ 000a1860
void SV_AddLinksToPM(areanode_t *node,vec_t *origin)

{
  undefined4 uVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  model_s *src;
  playermove_t *ppVar5;
  uint uVar6;
  bool bVar7;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t pmove_mins@[???]
                       Unresolved local var: vec3_t pmove_maxs@[???] */
  Q_memset(pmove->physents,0,0xe0);
  Q_memset(pmove->visents,0,0xe0);
  src = sv.worldmodel;
  ppVar5 = pmove;
  bVar7 = sv.worldmodel != (model_s *)0x0;
  pmove->physents[0].model = sv.worldmodel;
  if (bVar7) {
    Q_strncpy(ppVar5->physents[0].name,src->name,0x20);
    ppVar5 = pmove;
    pmove->physents[0].name[0x1f] = '\0';
  }
  vVar4 = vec3_origin[2];
  vVar3 = vec3_origin[1];
  vVar2 = vec3_origin[0];
  ppVar5->physents[0].info = 0;
  ppVar5->physents[0].origin[0] = vVar2;
  ppVar5->physents[0].origin[1] = vVar3;
  ppVar5->physents[0].origin[2] = vVar4;
  ppVar5->physents[0].solid = 4;
  ppVar5->physents[0].movetype = 0;
  ppVar5->physents[0].takedamage = 1;
  ppVar5->numphysent = 1;
  uVar6 = 0;
  ppVar5->physents[0].blooddecal = 0;
  ppVar5->numvisent = 1;
  do {
    uVar1 = *(undefined4 *)(ppVar5->physents[0].name + uVar6);
    *(undefined4 *)(ppVar5->visents[0].name + uVar6 + 4) =
         *(undefined4 *)(ppVar5->physents[0].name + uVar6 + 4);
    *(undefined4 *)(ppVar5->visents[0].name + uVar6) = uVar1;
    uVar6 = uVar6 + 8;
  } while (uVar6 < 0xe0);
  ppVar5->nummoveent = 0;
  local_24 = *origin - 256.0;
  local_18 = *origin + 256.0;
  local_20 = origin[1] - 256.0;
  local_14 = origin[1] + 256.0;
  local_1c = origin[2] - 256.0;
  local_10 = origin[2] + 256.0;
  SV_AddLinksToPM_(node,&local_24,&local_18);
  return;
}


// SV_AddLinksToPM_  @ 000a0e80
void SV_AddLinksToPM_(areanode_t *node,float *pmove_mins,float *pmove_maxs)

{
  link_s *plVar1;
  int iVar2;
  undefined4 uVar3;
  model_s *pmVar4;
  playermove_t *ppVar5;
  int iVar6;
  uint uVar7;
  link_s **pplVar8;
  physent_t *ppVar9;
  link_s *plVar10;
  link_s *plVar11;
  int iVar12;
  float fVar13;
  link_s *local_30;
  
  do {
    plVar1 = (node->solid_edicts).next;
LAB_000a0eee:
    while (plVar11 = plVar1, plVar11 != &node->solid_edicts) {
      plVar1 = plVar11->next;
      plVar10 = plVar11[0x57].prev;
      if (plVar10 == (link_s *)0x0) goto LAB_000a0ed0;
      if (g_groupop != 0) goto LAB_000a1400;
      if (((sv_player->v).groupinfo & (uint)plVar10) != 0) goto LAB_000a0ed0;
    }
    iVar2 = node->axis;
    if (iVar2 == -1) {
      return;
    }
    fVar13 = node->dist;
    iVar6 = iVar2 * 4;
    if (fVar13 < pmove_maxs[iVar2]) {
      SV_AddLinksToPM_(node->children[0],pmove_mins,pmove_maxs);
      iVar6 = node->axis << 2;
      fVar13 = node->dist;
    }
    if (fVar13 <= *(float *)((int)pmove_mins + iVar6)) {
      return;
    }
    node = node->children[1];
  } while( true );
LAB_000a1400:
  if ((g_groupop == 1) && (((sv_player->v).groupinfo & (uint)plVar10) != 0)) goto LAB_000a0eee;
LAB_000a0ed0:
  if (((edict_t *)plVar11[0x42].prev == sv_player) ||
     (((undefined1 *)0x2 < (undefined1 *)((int)&plVar11[0x30].next[-1].next + 2U) &&
      (plVar11[0x30].next != (link_s *)0x0)))) goto LAB_000a0eee;
  iVar6 = NUM_FOR_EDICT((edict_t *)(plVar11 + -1));
  ppVar5 = pmove;
  iVar2 = pmove->numvisent;
  pmove->numvisent = iVar2 + 1;
  *(int *)((int)&__DT_REL[iVar2 * 0x1c + 0x25c8].r_offset + (int)ppVar5->physents) = iVar6;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c2].r_info + (int)ppVar5->physents) =
       plVar11[0x10].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c3].r_offset + (int)ppVar5->physents) =
       plVar11[0x10].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c3].r_info + (int)ppVar5->physents) =
       plVar11[0x11].prev;
  if ((iVar6 < 1) || (svs.maxclients < iVar6)) {
    ppVar5->visents[iVar2].player = 0;
  }
  else {
    if ((((((host_client->lw != 0) && (host_client->lc != 0)) && (sv_unlag.value != 0.0)) &&
         ((1 < svs.maxclients && (iVar12 = iVar6 + -1, iVar12 < svs.maxclients && -1 < iVar12)))) &&
        (host_client->active != false)) &&
       ((truepositions[iVar12].active != 0 && (truepositions[iVar12].needrelink != 0)))) {
      ppVar5->visents[iVar2].origin[0] = truepositions[iVar12].oldorg[0];
      ppVar5->visents[iVar2].origin[1] = truepositions[iVar12].oldorg[1];
      ppVar5->visents[iVar2].origin[2] = truepositions[iVar12].oldorg[2];
    }
    *(undefined4 *)((int)&__DT_REL[iVar2 * 0x1c + 0x25c2].r_offset + (int)ppVar5->physents) =
         *(undefined4 *)((int)&__DT_REL[iVar2 * 0x1c + 0x25c8].r_offset + (int)ppVar5->physents);
  }
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c8].r_info + (int)ppVar5->physents) =
       plVar11[0x19].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c9].r_offset + (int)ppVar5->physents) =
       plVar11[0x19].next;
  plVar10 = plVar11[0x1a].prev;
  *(undefined4 *)((int)&__DT_REL[iVar2 * 0x1c + 0x25c4].r_info + (int)ppVar5->physents) = 0;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c9].r_info + (int)ppVar5->physents) = plVar10;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25cb].r_offset + (int)ppVar5->physents) =
       plVar11[0x38].prev;
  plVar10 = plVar11[0x30].next;
  if (plVar10 == (link_s *)0x4) {
    plVar10 = plVar11[0x25].next;
  }
  else {
    if (plVar10 != (link_s *)0x0) {
                    /* Unresolved local var: model_t * pModel@[???] */
      *(undefined4 *)((int)&__DT_REL[iVar2 * 0x1c + 0x25c4].r_offset + (int)ppVar5->physents) = 0;
      if (plVar10 == (link_s *)0x2) {
        if ((plVar11[0x25].next != (link_s *)0x0) &&
           (pmVar4 = sv.models[(int)plVar11[0x25].next], pmVar4 != (model_s *)0x0)) {
          if ((pmVar4->flags & 0x200) != 0) {
            *(model_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c4].r_info + (int)ppVar5->physents) =
                 pmVar4;
          }
          Q_strncpy(ppVar5->visents[iVar2].name,pmVar4->name,0x20);
          *(char *)((int)&__DT_REL[iVar2 * 0x1c + 0x25c1].r_info +
                   (int)(ppVar5->physents[0].name + 3)) = '\0';
        }
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c5].r_offset + (int)ppVar5->physents) =
             plVar11[0x2a].next;
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c5].r_info + (int)ppVar5->physents) =
             plVar11[0x2b].prev;
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c6].r_offset + (int)ppVar5->physents) =
             plVar11[0x2b].next;
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c6].r_info + (int)ppVar5->physents) =
             plVar11[0x2c].prev;
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c7].r_offset + (int)ppVar5->physents) =
             plVar11[0x2c].next;
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c7].r_info + (int)ppVar5->physents) =
             plVar11[0x2d].prev;
      }
      else {
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c5].r_offset + (int)ppVar5->physents) =
             plVar11[0x2a].next;
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c5].r_info + (int)ppVar5->physents) =
             plVar11[0x2b].prev;
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c6].r_offset + (int)ppVar5->physents) =
             plVar11[0x2b].next;
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c6].r_info + (int)ppVar5->physents) =
             plVar11[0x2c].prev;
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c7].r_offset + (int)ppVar5->physents) =
             plVar11[0x2c].next;
        *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c7].r_info + (int)ppVar5->physents) =
             plVar11[0x2d].prev;
        if (plVar11[0xf].prev == (link_s *)0x0) {
          ppVar5->visents[iVar2].name[0] = '?';
          ppVar5->visents[iVar2].name[1] = '\0';
        }
        else {
          Q_strncpy(ppVar5->visents[iVar2].name,pr_strings + (int)plVar11[0xf].prev,0x20);
        }
        ppVar5->visents[iVar2].name[0x1f] = '\0';
      }
      goto LAB_000a102c;
    }
    plVar10 = plVar11[0x25].next;
    if (plVar10 == (link_s *)0x0) {
      *(undefined4 *)((int)&__DT_REL[iVar2 * 0x1c + 0x25c4].r_offset + (int)ppVar5->physents) = 0;
      goto LAB_000a102c;
    }
  }
  pmVar4 = sv.models[(int)plVar10];
  *(model_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25c4].r_offset + (int)ppVar5->physents) = pmVar4;
  Q_strncpy(ppVar5->visents[iVar2].name,pmVar4->name,0x20);
  *(char *)((int)&__DT_REL[iVar2 * 0x1c + 0x25c1].r_info + (int)(ppVar5->physents[0].name + 3)) =
       '\0';
LAB_000a102c:
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25ca].r_offset + (int)ppVar5->physents) =
       plVar11[0x30].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25ca].r_info + (int)ppVar5->physents) =
       plVar11[0x31].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25cb].r_info + (int)ppVar5->physents) =
       plVar11[0x35].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25cc].r_offset + (int)ppVar5->physents) =
       plVar11[0x34].prev;
  Q_memcpy(ppVar5->visents[iVar2].controller,&plVar11[0x36].next,4);
  Q_memcpy(ppVar5->visents[iVar2].blending,plVar11 + 0x37,2);
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25cd].r_info + (int)ppVar5->physents) =
       plVar11[0x30].prev;
  *(undefined4 *)((int)&__DT_REL[iVar2 * 0x1c + 0x25ce].r_offset + (int)ppVar5->physents) = 0;
  *(undefined4 *)((int)&__DT_REL[iVar2 * 0x1c + 0x25ce].r_info + (int)ppVar5->physents) = 0;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d0].r_offset + (int)ppVar5->physents) =
       plVar11[0x57].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d0].r_info + (int)ppVar5->physents) =
       plVar11[0x58].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d1].r_offset + (int)ppVar5->physents) =
       plVar11[0x58].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d1].r_info + (int)ppVar5->physents) =
       plVar11[0x59].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d2].r_offset + (int)ppVar5->physents) =
       plVar11[0x59].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d2].r_info + (int)ppVar5->physents) =
       plVar11[0x5a].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d3].r_offset + (int)ppVar5->physents) =
       plVar11[0x5a].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d3].r_info + (int)ppVar5->physents) =
       plVar11[0x5b].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d4].r_offset + (int)ppVar5->physents) =
       plVar11[0x5b].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d4].r_info + (int)ppVar5->physents) =
       plVar11[0x5c].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d5].r_offset + (int)ppVar5->physents) =
       plVar11[0x5c].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d5].r_info + (int)ppVar5->physents) =
       plVar11[0x5d].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d6].r_offset + (int)ppVar5->physents) =
       plVar11[0x5d].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d6].r_info + (int)ppVar5->physents) =
       plVar11[0x5e].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d7].r_offset + (int)ppVar5->physents) =
       plVar11[0x5e].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d7].r_info + (int)ppVar5->physents) =
       plVar11[0x5f].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d8].r_offset + (int)ppVar5->physents) =
       plVar11[0x5f].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d8].r_info + (int)ppVar5->physents) =
       plVar11[0x60].prev;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d9].r_offset + (int)ppVar5->physents) =
       plVar11[0x60].next;
  *(link_s **)((int)&__DT_REL[iVar2 * 0x1c + 0x25d9].r_info + (int)ppVar5->physents) =
       plVar11[0x61].prev;
  if (plVar11[0x30].next == (link_s *)0x0) {
    if ((plVar11[0x31].prev == (link_s *)0x0) || (plVar11[0x25].next == (link_s *)0x0))
    goto LAB_000a0eee;
    plVar10 = plVar11[0x43].next;
  }
  else {
    plVar10 = plVar11[0x43].next;
    if ((((uint)plVar10 & 0x800000) != 0) && (plVar11[0x30].next == (link_s *)0x4))
    goto LAB_000a0eee;
  }
  if (((((edict_t *)(plVar11 + -1) != sv_player) &&
       ((((uint)plVar10 & 8) == 0 || (0.0 < (float)plVar11[0x3b].prev)))) &&
      (((float)plVar11[0x2b].next != 0.0 || ((float)plVar11[0x2d].prev != 1.0)))) &&
     (fVar13 = Length((vec_t *)&plVar11[0x2d].next), fVar13 != 0.0)) {
    local_30 = plVar11 + 0x29;
    pplVar8 = &plVar11[0x27].next;
    if (((((((uint)plVar11[0x43].next & 8) != 0) && (host_client->lw != 0)) &&
         (host_client->lc != 0)) &&
        (((sv_unlag.value != 0.0 && (1 < svs.maxclients)) &&
         ((iVar6 = iVar6 + -1, iVar6 < svs.maxclients && -1 < iVar6 &&
          ((host_client->active != false && (truepositions[iVar6].active != 0)))))))) &&
       (truepositions[iVar6].needrelink != 0)) {
      pplVar8 = (link_s **)truepositions[iVar6].oldabsmin;
      local_30 = (link_s *)truepositions[iVar6].oldabsmax;
    }
    if (((((float)*pplVar8 <= *pmove_maxs) && (*pmove_mins <= (float)local_30->prev)) &&
        ((float)pplVar8[1] <= pmove_maxs[1])) &&
       (((pmove_mins[1] <= (float)local_30->next && ((float)pplVar8[2] <= pmove_maxs[2])) &&
        (pmove_mins[2] <= (float)local_30[1].prev)))) {
      if ((plVar11[0x30].next == (link_s *)0x0) && (plVar11[0x31].prev == (link_s *)0xfffffff0)) {
        iVar6 = pmove->nummoveent;
        if (0x3f < iVar6) {
          Con_DPrintf("SV_AddLinksToPM:  pmove->nummoveent >= MAX_MOVEENTS\n");
          goto LAB_000a0eee;
        }
        ppVar9 = pmove->moveents + iVar6;
        pmove->nummoveent = iVar6 + 1;
      }
      else {
        iVar6 = pmove->numphysent;
        if (599 < iVar6) {
          Con_DPrintf("SV_AddLinksToPM:  pmove->numphysent >= MAX_PHYSENTS\n");
          return;
        }
        ppVar9 = pmove->physents + iVar6;
        pmove->numphysent = iVar6 + 1;
      }
      uVar7 = 0;
      do {
        uVar3 = *(undefined4 *)(ppVar5->visents[iVar2].name + uVar7 + 4);
        *(undefined4 *)(ppVar9->name + uVar7) = *(undefined4 *)(ppVar5->visents[iVar2].name + uVar7)
        ;
        *(undefined4 *)(ppVar9->name + uVar7 + 4) = uVar3;
        uVar7 = uVar7 + 8;
      } while (uVar7 < 0xe0);
    }
  }
  goto LAB_000a0eee;
}


// SV_AddLogAddress_f  @ 0007fdc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_AddLogAddress_f(void)

{
  netadr_t a;
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  char *str;
  qboolean qVar4;
  loglist *plVar5;
  LOGLIST_T *pLVar6;
  int in_GS_OFFSET;
  bool bVar7;
  netadr_t local_138;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: int nPort@[???]
                       Unresolved local var: char[260] szAdr@[???]
                       Unresolved local var: netadr_t adr@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = Cmd_Argc();
  if (iVar2 == 3) {
    pcVar3 = Cmd_Argv(1);
    str = Cmd_Argv(2);
    iVar2 = Q_atoi(str);
    if (iVar2 == 0) {
      Con_Printf("logaddress_add:  must specify a valid port\n");
    }
    else if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {
      Con_Printf("logaddress_add:  unparseable address\n");
    }
    else {
      __snprintf_chk(local_124,0x104,1,0x104,"%s:%i",pcVar3,iVar2);
      qVar4 = NET_StringToAdr(local_124,&local_138);
      plVar5 = firstLog;
      if (qVar4 == false) {
        Con_Printf("logaddress_add:  unable to resolve %s\n",local_124);
      }
      else if (firstLog == (LOGLIST_T *)0x0) {
        plVar5 = malloc(0x24);
        firstLog = plVar5;
        if (plVar5 == (loglist *)0x0) {
LAB_0008002a:
          Con_Printf("logaddress_add:  error allocating new node\n");
        }
        else {
LAB_0007ffaf:
          (plVar5->log).net_address.type = local_138.type;
          *&(plVar5->log).net_address.ip = local_138.ip;
          *(undefined4 *)(plVar5->log).net_address.ipx = local_138.ipx._0_4_;
          *(undefined4 *)((plVar5->log).net_address.ipx + 4) = local_138.ipx._4_4_;
          plVar5->next = (loglist *)0x0;
          *(undefined4 *)((plVar5->log).net_address.ipx + 8) = local_138._16_4_;
          a.ip[0] = local_138.ip[0];
          a.ip[1] = local_138.ip[1];
          a.ip[2] = local_138.ip[2];
          a.ip[3] = local_138.ip[3];
          a.type = local_138.type;
          a.ipx[0] = local_138.ipx[0];
          a.ipx[1] = local_138.ipx[1];
          a.ipx[2] = local_138.ipx[2];
          a.ipx[3] = local_138.ipx[3];
          a.ipx[4] = local_138.ipx[4];
          a.ipx[5] = local_138.ipx[5];
          a.ipx[6] = local_138.ipx[6];
          a.ipx[7] = local_138.ipx[7];
          a.ipx[8] = local_138.ipx[8];
          a.ipx[9] = local_138.ipx[9];
          a.port = local_138.port;
          pcVar3 = NET_AdrToString(a);
          Con_Printf("logaddress_add:  %s\n",pcVar3);
        }
      }
      else {
                    /* Unresolved local var: LOGLIST_T * list@[???]
                       Unresolved local var: char found@[???] */
        iVar2 = memcmp((firstLog->log).net_address.ip,local_138.ip,4);
        uVar1 = local_138.port;
        if (iVar2 == 0) {
          bVar7 = (plVar5->log).net_address.port == local_138.port;
        }
        else {
          bVar7 = false;
        }
        do {
          pLVar6 = plVar5;
          plVar5 = pLVar6->next;
          if (plVar5 == (loglist *)0x0) {
            if (!bVar7) {
                    /* Unresolved local var: LOGLIST_T * tmp@[???] */
              plVar5 = malloc(0x24);
              if (plVar5 == (loglist *)0x0) goto LAB_0008002a;
              pLVar6->next = plVar5;
              goto LAB_0007ffaf;
            }
            break;
          }
          iVar2 = memcmp((pLVar6->log).net_address.ip,local_138.ip,4);
        } while ((iVar2 != 0) || ((pLVar6->log).net_address.port != uVar1));
        Con_Printf("logaddress_add:  address already in list\n");
      }
    }
  }
  else {
    Con_Printf("logaddress_add:  usage\nlogaddress_add ip port\n");
    for (plVar5 = firstLog; plVar5 != (LOGLIST_T *)0x0; plVar5 = plVar5->next) {
                    /* Unresolved local var: LOGLIST_T * list@[???] */
      pcVar3 = NET_AdrToString((plVar5->log).net_address);
      Con_Printf("current:  %s\n",pcVar3);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_AddResource  @ 0008d3c0
void SV_AddResource(resourcetype_t type,char *name,int size,uchar flags,int index)

{
  int iVar1;
  
                    /* Unresolved local var: resource_t * r@[???] */
  iVar1 = sv.num_resources;
                    /* try { // try from 0008d3c5 to 0009d3c9 has its CatchHandler @ 0008d41a */
                    /* try { // try from 0008d3d3 to 0009d3d7 has its CatchHandler @ 0008d3f4 */
  if (0x4ff < sv.num_resources) {
    Sys_Error("Too many resources on server.");
  }
  sv.num_resources = sv.num_resources + 1;
  sv.resourcelist[iVar1].type = type;
  Q_strncpy(sv.resourcelist[iVar1].szFileName,name,0x3f);
  sv.resourcelist[iVar1].szFileName[0x3f] = '\0';
  sv.resourcelist[iVar1].ucFlags = flags;
  sv.resourcelist[iVar1].nDownloadSize = size;
  sv.resourcelist[iVar1].nIndex = index;
  return;
}


// SV_AddSampleToHashedLookupTable  @ 000829f0
void SV_AddSampleToHashedLookupTable(char *pszSample,int iSampleIndex)

{
  char cVar1;
  __int32_t **pp_Var2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int starting_index@[???] */
                    /* Unresolved local var: uint hash@[???] */
  cVar1 = *pszSample;
  if (cVar1 == '\0') {
    uVar3 = 0;
    uVar5 = uVar3;
  }
  else {
    pp_Var2 = __ctype_tolower_loc();
    uVar3 = 0;
    do {
      iVar4 = (int)cVar1;
      pszSample = pszSample + 1;
      cVar1 = *pszSample;
      uVar3 = (*pp_Var2)[iVar4] + uVar3 * 2;
    } while (cVar1 != '\0');
    uVar3 = uVar3 % 0x3ff;
    uVar5 = uVar3;
  }
  while (*(short *)(uVar3 + 0x518828 + uVar3 + 0x195a0) != 0) {
    uVar3 = uVar3 + 1;
    hashstrings_collisions = hashstrings_collisions + 1;
    if (uVar3 == 0x3ff) {
      uVar3 = 0;
    }
    if (uVar3 == uVar5) {
      Sys_Error("SV_AddSampleToHashedLookupTable: NO FREE SLOTS IN SOUND LOOKUP TABLE");
    }
  }
  *(short *)(uVar3 + 0x518828 + uVar3 + 0x195a0) = (short)iSampleIndex;
  return;
}


// SV_AddToFatPAS  @ 0008a360
/* WARNING: Removing unreachable block (ram,0x0008a413) */
/* WARNING: Removing unreachable block (ram,0x0008a7bf) */
/* WARNING: Removing unreachable block (ram,0x0008a797) */
/* WARNING: Removing unreachable block (ram,0x0008a7ab) */
/* WARNING: Removing unreachable block (ram,0x0008a7e7) */
/* WARNING: Removing unreachable block (ram,0x0008a7fb) */
/* WARNING: Removing unreachable block (ram,0x0008a80f) */
/* WARNING: Removing unreachable block (ram,0x0008a57b) */
/* WARNING: Removing unreachable block (ram,0x0008a41e) */
/* WARNING: Removing unreachable block (ram,0x0008a436) */
/* WARNING: Removing unreachable block (ram,0x0008a44f) */
/* WARNING: Removing unreachable block (ram,0x0008a468) */
/* WARNING: Removing unreachable block (ram,0x0008a481) */
/* WARNING: Removing unreachable block (ram,0x0008a49a) */
/* WARNING: Removing unreachable block (ram,0x0008a4b3) */
/* WARNING: Removing unreachable block (ram,0x0008a4cc) */
/* WARNING: Removing unreachable block (ram,0x0008a4e5) */
/* WARNING: Removing unreachable block (ram,0x0008a4fe) */
/* WARNING: Removing unreachable block (ram,0x0008a517) */
/* WARNING: Removing unreachable block (ram,0x0008a530) */
/* WARNING: Removing unreachable block (ram,0x0008a549) */
/* WARNING: Removing unreachable block (ram,0x0008a562) */
/* WARNING: Removing unreachable block (ram,0x0008a7dd) */
/* WARNING: Removing unreachable block (ram,0x0008a819) */
/* WARNING: Removing unreachable block (ram,0x0008a805) */
/* WARNING: Removing unreachable block (ram,0x0008a7f1) */
/* WARNING: Removing unreachable block (ram,0x0008a7b5) */
/* WARNING: Removing unreachable block (ram,0x0008a7a1) */
/* WARNING: Removing unreachable block (ram,0x0008a7c9) */
/* WARNING: Removing unreachable block (ram,0x0008a7d3) */

void SV_AddToFatPAS(vec_t *org,mnode_t *node)

{
  uint uVar1;
  uint *puVar2;
  mplane_t *pmVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  for (; iVar8 = node->contents, -1 < iVar8; node = node->children[1]) {
    while( true ) {
      pmVar3 = node->plane;
      fVar4 = (org[2] * pmVar3->normal[2] + org[1] * pmVar3->normal[1] + *org * pmVar3->normal[0]) -
              pmVar3->dist;
      if (fVar4 <= 8.0) break;
      node = node->children[0];
      iVar8 = node->contents;
      if (iVar8 < 0) goto LAB_0008a3ad;
    }
    if (-8.0 <= fVar4) {
      SV_AddToFatPAS(org,node->children[0]);
    }
  }
LAB_0008a3ad:
                    /* Unresolved local var: int leafnum@[???] */
  if ((iVar8 != -2) &&
     (pbVar9 = CM_LeafPAS(((int)node - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555),
     iVar8 = fatpasbytes, 0 < fatpasbytes)) {
    if ((fatpas < pbVar9 + 0x10 && pbVar9 < fatpas + 0x10) || ((uint)fatpasbytes < 0x13)) {
      iVar11 = 0;
      do {
        fatpas[iVar11] = fatpas[iVar11] | pbVar9[iVar11];
        iVar11 = iVar11 + 1;
      } while (iVar8 != iVar11);
      return;
    }
    uVar1 = (fatpasbytes - 0x10U >> 4) + 1;
    iVar10 = uVar1 * 0x10;
    iVar11 = 0;
    if (0xe < fatpasbytes - 1U) {
      iVar11 = 0;
      uVar12 = 0;
      do {
        uVar12 = uVar12 + 1;
        puVar2 = (uint *)(pbVar9 + iVar11);
        uVar5 = puVar2[1];
        uVar6 = puVar2[2];
        uVar7 = puVar2[3];
        *(uint *)(fatpas + iVar11) = *puVar2 | *(uint *)(fatpas + iVar11);
        *(uint *)(fatpas + iVar11 + 4) = uVar5 | *(uint *)(fatpas + iVar11 + 4);
        *(uint *)(fatpas + iVar11 + 8) = uVar6 | *(uint *)(fatpas + iVar11 + 8);
        *(uint *)(fatpas + iVar11 + 0xc) = uVar7 | *(uint *)(fatpas + iVar11 + 0xc);
        iVar11 = iVar11 + 0x10;
      } while (uVar12 < uVar1);
      iVar11 = iVar10;
      if (iVar8 == iVar10) {
        return;
      }
    }
    fatpas[iVar11] = fatpas[iVar11] | pbVar9[iVar11];
    if (((((iVar11 + 1 < iVar8) &&
          (fatpas[iVar11 + 1] = fatpas[iVar11 + 1] | pbVar9[iVar11 + 1], iVar11 + 2 < iVar8)) &&
         (fatpas[iVar11 + 2] = fatpas[iVar11 + 2] | pbVar9[iVar11 + 2], iVar11 + 3 < iVar8)) &&
        (((fatpas[iVar11 + 3] = fatpas[iVar11 + 3] | pbVar9[iVar11 + 3], iVar11 + 4 < iVar8 &&
          (fatpas[iVar11 + 4] = fatpas[iVar11 + 4] | pbVar9[iVar11 + 4], iVar11 + 5 < iVar8)) &&
         ((fatpas[iVar11 + 5] = fatpas[iVar11 + 5] | pbVar9[iVar11 + 5], iVar11 + 6 < iVar8 &&
          ((fatpas[iVar11 + 6] = fatpas[iVar11 + 6] | pbVar9[iVar11 + 6], iVar11 + 7 < iVar8 &&
           (fatpas[iVar11 + 7] = fatpas[iVar11 + 7] | pbVar9[iVar11 + 7], iVar11 + 8 < iVar8))))))))
       && ((fatpas[iVar11 + 8] = fatpas[iVar11 + 8] | pbVar9[iVar11 + 8], iVar11 + 9 < iVar8 &&
           ((((fatpas[iVar11 + 9] = fatpas[iVar11 + 9] | pbVar9[iVar11 + 9], iVar11 + 10 < iVar8 &&
              (fatpas[iVar11 + 10] = fatpas[iVar11 + 10] | pbVar9[iVar11 + 10], iVar11 + 0xb < iVar8
              )) && (fatpas[iVar11 + 0xb] = fatpas[iVar11 + 0xb] | pbVar9[iVar11 + 0xb],
                    iVar11 + 0xc < iVar8)) &&
            (fatpas[iVar11 + 0xc] = fatpas[iVar11 + 0xc] | pbVar9[iVar11 + 0xc],
            iVar11 + 0xd < iVar8)))))) {
      fatpas[iVar11 + 0xd] = fatpas[iVar11 + 0xd] | pbVar9[iVar11 + 0xd];
      if (iVar11 + 0xe < iVar8) {
        fatpas[iVar11 + 0xe] = fatpas[iVar11 + 0xe] | pbVar9[iVar11 + 0xe];
      }
    }
  }
  return;
}


// SV_AddToFatPVS  @ 00089e40
/* WARNING: Removing unreachable block (ram,0x00089ee6) */
/* WARNING: Removing unreachable block (ram,0x0008a28f) */
/* WARNING: Removing unreachable block (ram,0x0008a267) */
/* WARNING: Removing unreachable block (ram,0x0008a27b) */
/* WARNING: Removing unreachable block (ram,0x0008a2b7) */
/* WARNING: Removing unreachable block (ram,0x0008a2cb) */
/* WARNING: Removing unreachable block (ram,0x0008a2df) */
/* WARNING: Removing unreachable block (ram,0x0008a04e) */
/* WARNING: Removing unreachable block (ram,0x00089ef1) */
/* WARNING: Removing unreachable block (ram,0x00089f09) */
/* WARNING: Removing unreachable block (ram,0x00089f22) */
/* WARNING: Removing unreachable block (ram,0x00089f3b) */
/* WARNING: Removing unreachable block (ram,0x00089f54) */
/* WARNING: Removing unreachable block (ram,0x00089f6d) */
/* WARNING: Removing unreachable block (ram,0x00089f86) */
/* WARNING: Removing unreachable block (ram,0x00089f9f) */
/* WARNING: Removing unreachable block (ram,0x00089fb8) */
/* WARNING: Removing unreachable block (ram,0x00089fd1) */
/* WARNING: Removing unreachable block (ram,0x00089fea) */
/* WARNING: Removing unreachable block (ram,0x0008a003) */
/* WARNING: Removing unreachable block (ram,0x0008a01c) */
/* WARNING: Removing unreachable block (ram,0x0008a035) */
/* WARNING: Removing unreachable block (ram,0x0008a2ad) */
/* WARNING: Removing unreachable block (ram,0x0008a2e9) */
/* WARNING: Removing unreachable block (ram,0x0008a2d5) */
/* WARNING: Removing unreachable block (ram,0x0008a2c1) */
/* WARNING: Removing unreachable block (ram,0x0008a285) */
/* WARNING: Removing unreachable block (ram,0x0008a271) */
/* WARNING: Removing unreachable block (ram,0x0008a299) */
/* WARNING: Removing unreachable block (ram,0x0008a2a3) */

void SV_AddToFatPVS(vec_t *org,mnode_t *node)

{
  uint uVar1;
  uint *puVar2;
  float *pfVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  mleaf_s *pmVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  
  for (; pmVar9 = (mleaf_s *)((mleaf_t *)node)->contents, -1 < (int)pmVar9;
      node = (mnode_t *)((mleaf_t *)node)->firstmarksurface) {
    while( true ) {
      pfVar3 = (float *)((mleaf_t *)node)->compressed_vis;
      fVar4 = (org[2] * pfVar3[2] + org[1] * pfVar3[1] + *org * *pfVar3) - pfVar3[3];
      if (fVar4 <= 8.0) break;
      node = (mnode_t *)((mleaf_t *)node)->efrags;
      pmVar9 = (mleaf_s *)((mleaf_t *)node)->contents;
      if ((int)pmVar9 < 0) goto LAB_00089e8d;
    }
    if (-8.0 <= fVar4) {
      SV_AddToFatPVS(org,(mnode_t *)((mleaf_t *)node)->efrags);
    }
  }
LAB_00089e8d:
  if ((pmVar9 != (mleaf_s *)0xfffffffe) &&
     (pbVar10 = Mod_LeafPVS((mleaf_t *)node,sv.worldmodel), iVar8 = fatbytes, 0 < fatbytes)) {
    if ((fatpvs < pbVar10 + 0x10 && pbVar10 < fatpvs + 0x10) || ((uint)fatbytes < 0x13)) {
      iVar12 = 0;
      do {
        fatpvs[iVar12] = fatpvs[iVar12] | pbVar10[iVar12];
        iVar12 = iVar12 + 1;
      } while (iVar8 != iVar12);
      return;
    }
    uVar1 = (fatbytes - 0x10U >> 4) + 1;
    iVar11 = uVar1 * 0x10;
    iVar12 = 0;
    if (0xe < fatbytes - 1U) {
      iVar12 = 0;
      uVar13 = 0;
      do {
        uVar13 = uVar13 + 1;
        puVar2 = (uint *)(pbVar10 + iVar12);
        uVar5 = puVar2[1];
        uVar6 = puVar2[2];
        uVar7 = puVar2[3];
        *(uint *)(fatpvs + iVar12) = *puVar2 | *(uint *)(fatpvs + iVar12);
        *(uint *)(fatpvs + iVar12 + 4) = uVar5 | *(uint *)(fatpvs + iVar12 + 4);
        *(uint *)(fatpvs + iVar12 + 8) = uVar6 | *(uint *)(fatpvs + iVar12 + 8);
        *(uint *)(fatpvs + iVar12 + 0xc) = uVar7 | *(uint *)(fatpvs + iVar12 + 0xc);
        iVar12 = iVar12 + 0x10;
      } while (uVar13 < uVar1);
      iVar12 = iVar11;
      if (iVar8 == iVar11) {
        return;
      }
    }
    fatpvs[iVar12] = fatpvs[iVar12] | pbVar10[iVar12];
    if (((((iVar12 + 1 < iVar8) &&
          (fatpvs[iVar12 + 1] = fatpvs[iVar12 + 1] | pbVar10[iVar12 + 1], iVar12 + 2 < iVar8)) &&
         (fatpvs[iVar12 + 2] = fatpvs[iVar12 + 2] | pbVar10[iVar12 + 2], iVar12 + 3 < iVar8)) &&
        (((fatpvs[iVar12 + 3] = fatpvs[iVar12 + 3] | pbVar10[iVar12 + 3], iVar12 + 4 < iVar8 &&
          (fatpvs[iVar12 + 4] = fatpvs[iVar12 + 4] | pbVar10[iVar12 + 4], iVar12 + 5 < iVar8)) &&
         ((fatpvs[iVar12 + 5] = fatpvs[iVar12 + 5] | pbVar10[iVar12 + 5], iVar12 + 6 < iVar8 &&
          ((fatpvs[iVar12 + 6] = fatpvs[iVar12 + 6] | pbVar10[iVar12 + 6], iVar12 + 7 < iVar8 &&
           (fatpvs[iVar12 + 7] = fatpvs[iVar12 + 7] | pbVar10[iVar12 + 7], iVar12 + 8 < iVar8)))))))
        ) && ((fatpvs[iVar12 + 8] = fatpvs[iVar12 + 8] | pbVar10[iVar12 + 8], iVar12 + 9 < iVar8 &&
              ((((fatpvs[iVar12 + 9] = fatpvs[iVar12 + 9] | pbVar10[iVar12 + 9], iVar12 + 10 < iVar8
                 && (fatpvs[iVar12 + 10] = fatpvs[iVar12 + 10] | pbVar10[iVar12 + 10],
                    iVar12 + 0xb < iVar8)) &&
                (fatpvs[iVar12 + 0xb] = fatpvs[iVar12 + 0xb] | pbVar10[iVar12 + 0xb],
                iVar12 + 0xc < iVar8)) &&
               (fatpvs[iVar12 + 0xc] = fatpvs[iVar12 + 0xc] | pbVar10[iVar12 + 0xc],
               iVar12 + 0xd < iVar8)))))) {
      fatpvs[iVar12 + 0xd] = fatpvs[iVar12 + 0xd] | pbVar10[iVar12 + 0xd];
      if (iVar12 + 0xe < iVar8) {
        fatpvs[iVar12 + 0xe] = fatpvs[iVar12 + 0xe] | pbVar10[iVar12 + 0xe];
      }
    }
  }
  return;
}


// SV_AddToResourceList  @ 0009edf0
void SV_AddToResourceList(resource_t *pResource,resource_t *pList)

{
  if ((pResource->pPrev == (resource_s *)0x0) && (pResource->pNext == (resource_s *)0x0)) {
    pResource->pPrev = pList->pPrev;
    pList->pPrev->pNext = pResource;
    pList->pPrev = pResource;
    pResource->pNext = pList;
    return;
  }
  Con_Printf("Resource already linked\n");
  return;
}


// SV_AllocClientFrames  @ 00081ef0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_AllocClientFrames(void)

{
  client_frame_t *pcVar1;
  client_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclientslimit) {
    iVar3 = 0;
    pcVar2 = svs.clients;
    do {
      if (pcVar2->frames != (client_frame_t *)0x0) {
        Con_DPrintf("Allocating over frame pointer?\n");
      }
      iVar3 = iVar3 + 1;
      pcVar1 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0x1870);
      pcVar2->frames = pcVar1;
      pcVar2 = pcVar2 + 1;
    } while (iVar3 < svs.maxclientslimit);
  }
  return;
}


// SV_AllocPacketEntities  @ 00081fc0
void SV_AllocPacketEntities(client_frame_t *frame)

{
  entity_state_s *peVar1;
  
                    /* Unresolved local var: packet_entities_t * pack@[???]
                       Unresolved local var: int allocatedslots@[???] */
  if ((frame != (client_frame_t *)0x0) &&
     ((frame->entities).num_entities = 0, (frame->entities).entities == (entity_state_s *)0x0)) {
                    /* Unresolved local var: packet_entities_t * pack@[???]
                       Unresolved local var: int allocatedslots@[???] */
    peVar1 = Mem_ZeroMalloc(0x55000);
    (frame->entities).entities = peVar1;
  }
  return;
}


// SV_BanId_f  @ 00094610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_BanId_f(void)

{
  client_t *client;
  float fVar1;
  uint64 uVar2;
  client_t *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  userfilter_t *id;
  client_s *pcVar9;
  USERID_t *id_00;
  USERID_t *id_01;
  int iVar10;
  int in_GS_OFFSET;
  bool bVar11;
  float fVar12;
  char local_1e0;
  char local_1df [5];
  char local_1da [57];
  undefined1 local_1a1;
  char local_1a0 [63];
  undefined1 local_161;
  char local_160 [63];
  undefined1 local_121;
  char local_120 [63];
  undefined1 local_e1;
  undefined1 local_a1;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float banTime@[???]
                       Unresolved local var: USERID_t * id@[???]
                       Unresolved local var: char * pszCmdGiver@[???]
                       Unresolved local var: char[256] szreason@[???]
                       Unresolved local var: char[64] idstring@[???]
                       Unresolved local var: qboolean bKick@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar4 = Cmd_Argc();
  if ((iVar4 < 3) || (iVar4 = Cmd_Argc(), 8 < iVar4)) {
    Con_Printf("Usage:  banid <minutes> <uniqueid or #userid> { kick }\n");
    Con_Printf("Use 0 minutes for permanent\n");
    pcVar3 = host_client;
    uVar2 = CONCAT44(SV_StringToUserID::id.m_SteamID._4_4_,
                     (undefined4)SV_StringToUserID::id.m_SteamID);
  }
  else {
    pcVar5 = Cmd_Argv(1);
    fVar12 = Q_atof(pcVar5);
    fVar1 = 0.0;
    if (0.01 <= fVar12) {
      fVar1 = fVar12;
    }
    pcVar5 = Cmd_Argv(2);
    strncpy(&local_1e0,pcVar5,0x3f);
    local_1a1 = 0;
    iVar4 = Cmd_Argc();
    bVar11 = false;
    if (3 < iVar4) {
      iVar4 = Cmd_Argc();
      pcVar5 = Cmd_Argv(iVar4 + -1);
      iVar4 = Q_strcasecmp(pcVar5,&DAT_000d416b);
      bVar11 = iVar4 == 0;
    }
    if (local_1e0 == '#') {
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int search@[???] */
      iVar4 = Q_strlen(&local_1e0);
      if (iVar4 == 1) {
        iVar4 = Cmd_Argc();
        if (iVar4 < 3) {
          Con_Printf("Insufficient arguments to banid\n");
          pcVar3 = host_client;
          uVar2 = CONCAT44(SV_StringToUserID::id.m_SteamID._4_4_,
                           (undefined4)SV_StringToUserID::id.m_SteamID);
          goto LAB_0009466d;
        }
        pcVar5 = Cmd_Argv(3);
        iVar4 = Q_atoi(pcVar5);
      }
      else {
        iVar4 = Q_atoi(local_1df);
      }
      if (0 < svs.maxclients) {
        iVar10 = 0;
        pcVar9 = svs.clients;
        do {
          if ((((pcVar9->active != false) || (pcVar9->connected != false)) ||
              (pcVar9->spawned != false)) &&
             ((pcVar9->fakeclient == false && (iVar4 == pcVar9->userid)))) {
            id_00 = &pcVar9->network_userid;
            if (id_00 != (USERID_t *)0x0) goto LAB_0009489c;
            break;
          }
          iVar10 = iVar10 + 1;
          pcVar9 = pcVar9 + 1;
        } while (iVar10 != svs.maxclients);
      }
      Con_Printf("SV_BanId_f:  Couldn\'t find #userid %u\n",iVar4);
      pcVar3 = host_client;
      uVar2 = CONCAT44(SV_StringToUserID::id.m_SteamID._4_4_,
                       (undefined4)SV_StringToUserID::id.m_SteamID);
    }
    else {
                    /* Unresolved local var: client_t * cl@[???] */
      iVar4 = Q_strnicmp(&local_1e0,"STEAM_",6);
      if ((iVar4 == 0) || (iVar4 = Q_strnicmp(&local_1e0,"VALVE_",6), iVar4 == 0)) {
        pcVar5 = Cmd_Argv(6);
        pcVar8 = Cmd_Argv(4);
        pcVar6 = Cmd_Argv(2);
        __snprintf_chk(&local_1e0,0x3f,1,0x40,"%s:%s:%s",pcVar6,pcVar8,pcVar5);
        local_1a1 = 0;
      }
      iVar10 = 0;
      iVar4 = svs.maxclients;
      pcVar9 = svs.clients;
      if (0 < svs.maxclients) {
        do {
          if ((((pcVar9->active != false) || (pcVar9->connected != false)) ||
              (pcVar9->spawned != false)) && (pcVar9->fakeclient == false)) {
            SV_GetClientIDString::idstr._0_4_ = SV_GetClientIDString::idstr._0_4_ & 0xffffff00;
            if (pcVar9 != (client_s *)0x0) {
              if (((pcVar9->netchan).remote_address.type == NA_LOOPBACK) &&
                 ((pcVar9->network_userid).idtype == 2)) {
                builtin_strncpy(SV_GetClientIDString::idstr,"VALVE_ID_LOOPBACK",0x12);
              }
              else {
                    /* Unresolved local var: USERID_t * id@[???] */
                pcVar5 = SV_GetIDString(&pcVar9->network_userid);
                snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar5);
              }
            }
            iVar7 = Q_stricmp(SV_GetClientIDString::idstr,&local_1e0);
            iVar4 = svs.maxclients;
            if (iVar7 == 0) {
              id_00 = &pcVar9->network_userid;
              if (id_00 != (USERID_t *)0x0) goto LAB_0009489c;
              break;
            }
          }
          iVar10 = iVar10 + 1;
          pcVar9 = pcVar9 + 1;
        } while (iVar10 < iVar4);
      }
      Q_memset(&SV_StringToUserID::id,0,0x10);
      if (local_1e0 != '\0') {
                    /* Unresolved local var: char[128] szTemp@[???]
                       Unresolved local var: char * pszUserID@[???] */
        iVar4 = Q_strnicmp(&local_1e0,"STEAM_",6);
        if (iVar4 == 0) {
          strncpy(local_120,local_1da,0x7f);
          SV_StringToUserID::id.idtype = 1;
        }
        else {
          strncpy(local_120,local_1da,0x7f);
          SV_StringToUserID::id.idtype = 2;
        }
        local_a1 = 0;
        SV_StringToUserID::id.m_SteamID = Steam_StringToSteamID(local_120);
      }
      id_00 = &SV_StringToUserID::id;
LAB_0009489c:
      iVar4 = numuserfilters;
      if (numuserfilters < 1) {
        iVar10 = 0;
      }
      else {
        id = userfilters;
        iVar10 = 0;
                    /* Unresolved local var: char[64] szID1@[???]
                       Unresolved local var: char[64] szID2@[???] */
        do {
          iVar7 = (id->userid).idtype;
          if ((iVar7 == id_00->idtype) && (iVar7 - 1U < 2)) {
            pcVar5 = SV_GetIDString(&id->userid);
            strncpy(local_160,pcVar5,0x3f);
            local_121 = 0;
            pcVar5 = SV_GetIDString(id_00);
            strncpy(local_120,pcVar5,0x3f);
            local_e1 = 0;
            iVar7 = strcasecmp(local_160,local_120);
            iVar4 = numuserfilters;
            if (iVar7 == 0) {
              if (iVar10 < numuserfilters) goto LAB_00094958;
              break;
            }
          }
          iVar10 = iVar10 + 1;
          id = id + 1;
        } while (iVar10 < iVar4);
        if (0x7fff < iVar4) {
          Con_Printf("SV_BanId_f:  User filter list is full\n");
          pcVar3 = host_client;
          uVar2 = SV_StringToUserID::id.m_SteamID;
          goto LAB_0009466d;
        }
      }
      numuserfilters = iVar4 + 1;
LAB_00094958:
      userfilters[iVar10].banTime = fVar1;
      if (fVar1 == 0.0) {
        userfilters[iVar10].banEndTime = 0.0;
        userfilters[iVar10].userid.idtype = id_00->idtype;
        *(int *)&userfilters[iVar10].userid.m_SteamID = (int)id_00->m_SteamID;
        *(undefined4 *)((int)&userfilters[iVar10].userid.m_SteamID + 4) =
             *(undefined4 *)((int)&id_00->m_SteamID + 4);
        builtin_strncpy(local_120 + 8,"tly",4);
        userfilters[iVar10].userid.clientip = id_00->clientip;
        builtin_strncpy(local_120,"permanen",8);
      }
      else {
        userfilters[iVar10].banEndTime = fVar1 * 60.0 + (float)realtime;
        userfilters[iVar10].userid.idtype = id_00->idtype;
        *(int *)&userfilters[iVar10].userid.m_SteamID = (int)id_00->m_SteamID;
        *(undefined4 *)((int)&userfilters[iVar10].userid.m_SteamID + 4) =
             *(undefined4 *)((int)&id_00->m_SteamID + 4);
        userfilters[iVar10].userid.clientip = id_00->clientip;
        __snprintf_chk(local_120,0x100,1,0x100,"for %.2f minutes",(double)fVar1);
      }
      pcVar3 = host_client;
      if (cmd_source == src_command) {
        pcVar5 = "Console";
      }
      else {
        pcVar5 = host_client->name;
      }
      uVar2 = SV_StringToUserID::id.m_SteamID;
      if (bVar11) {
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: client_t * save@[???] */
        id_01 = &(svs.clients)->network_userid;
        iVar10 = 0;
        iVar4 = svs.maxclients;
        if (0 < svs.maxclients) {
          do {
            client = (client_t *)(id_01 + -0x620);
            if ((((id_01[-0x620].idtype != 0) || (id_01[-0x620].clientip != 0)) ||
                ((int)id_01[-0x620].m_SteamID != 0)) &&
               (((*(int *)((int)&id_01[-0x2e3].m_SteamID + 4) == 0 && (id_01 != (USERID_t *)0x0)) &&
                ((id_01->idtype == id_00->idtype && (id_01->idtype - 1U < 2)))))) {
                    /* Unresolved local var: char[64] szID1@[???]
                       Unresolved local var: char[64] szID2@[???] */
              pcVar8 = SV_GetIDString(id_01);
              strncpy(local_1a0,pcVar8,0x3f);
              local_161 = 0;
              pcVar8 = SV_GetIDString(id_00);
              strncpy(local_160,pcVar8,0x3f);
              local_121 = 0;
              iVar7 = strcasecmp(local_1a0,local_160);
              iVar4 = svs.maxclients;
              if (iVar7 == 0) {
                host_client = client;
                if (sv_logbans.value != 0.0) {
                  pcVar8 = SV_GetClientIDString(client);
                  Log_Printf("Ban: \"%s<%i><%s><>\" was kicked and banned \"%s\" by \"%s\"\n",
                             host_client->name,host_client->userid,pcVar8,local_120,pcVar5);
                }
                SV_ClientPrintf("You have been kicked and banned %s by the server op.\n",local_120);
                SV_DropClient(host_client,false,"Kicked and banned");
                uVar2 = SV_StringToUserID::id.m_SteamID;
                break;
              }
            }
            iVar10 = iVar10 + 1;
            id_01 = (USERID_t *)((int)&id_01[0x666].m_SteamID + 4);
            uVar2 = SV_StringToUserID::id.m_SteamID;
          } while (iVar10 < iVar4);
        }
      }
      else if (sv_logbans.value != 0.0) {
        pcVar8 = SV_GetIDString(id_00);
        Log_Printf("Ban: \"<><%s><>\" was banned \"%s\" by \"%s\"\n",pcVar8,local_120,pcVar5);
        pcVar3 = host_client;
        uVar2 = SV_StringToUserID::id.m_SteamID;
      }
    }
  }
LAB_0009466d:
  host_client = pcVar3;
  SV_StringToUserID::id.m_SteamID._4_4_ = (undefined4)(uVar2 >> 0x20);
  SV_StringToUserID::id.m_SteamID._0_4_ = (undefined4)uVar2;
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
  SV_StringToUserID::id.m_SteamID = uVar2;
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_BatchUploadRequest  @ 0009f0a0
void SV_BatchUploadRequest(client_t *cl)

{
  resource_s *prVar1;
  resource_s *prVar2;
  client_t *pcVar3;
  char *pcVar4;
  qboolean qVar5;
  int in_GS_OFFSET;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???]
                       Unresolved local var: char[260] filename@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  prVar1 = (cl->resourcesneeded).pNext;
joined_r0x0009f0e9:
  prVar2 = prVar1;
  if (prVar2 == &cl->resourcesneeded) {
    if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  prVar1 = prVar2->pNext;
  if ((prVar2->ucFlags & 2) != 0) goto code_r0x0009f0fe;
  if (prVar2 == (resource_s *)0x0) goto LAB_0009f250;
  prVar2->pPrev->pNext = prVar1;
  goto LAB_0009f15c;
code_r0x0009f0fe:
  if (prVar2->type == t_decal) {
    if ((prVar2->ucFlags & 4) == 0) {
      Con_Printf("Non customization in upload queue!\n");
    }
    else {
      pcVar4 = MD5_Print(prVar2->rgucMD5_hash);
      __snprintf_chk(local_124,0x104,1,0x104,"!MD5%s",pcVar4);
      qVar5 = SV_CheckFile(&(cl->netchan).message,local_124);
      if (qVar5 == false) goto joined_r0x0009f0e9;
    }
    if (prVar2 == (resource_s *)0x0) {
LAB_0009f250:
      Con_DPrintf("Null resource passed to SV_MoveToOnHandList\n");
    }
    else {
      prVar2->pPrev->pNext = prVar2->pNext;
LAB_0009f15c:
      prVar2->pNext->pPrev = prVar2->pPrev;
      prVar2->pPrev = (resource_s *)0x0;
      pcVar3 = host_client;
      prVar2->pNext = (resource_s *)0x0;
      prVar2->pPrev = (pcVar3->resourcesonhand).pPrev;
      ((pcVar3->resourcesonhand).pPrev)->pNext = prVar2;
      (pcVar3->resourcesonhand).pPrev = prVar2;
      prVar2->pNext = &pcVar3->resourcesonhand;
    }
  }
  goto joined_r0x0009f0e9;
}


// SV_BeginFileDownload_f  @ 00090440
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_BeginFileDownload_f(void)

{
  char cVar1;
  client_t *pcVar2;
  int iVar3;
  char *s1;
  qboolean qVar4;
  size_t sVar5;
  int in_GS_OFFSET;
  uchar *local_c4;
  int local_c0;
  uchar local_bc [16];
  char local_ac;
  undefined1 local_ab;
  undefined1 local_aa;
  undefined1 local_a9;
  undefined1 local_a8;
  undefined1 local_a7;
  undefined1 local_a6;
  undefined1 local_a5;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_a2;
  undefined1 local_a1;
  undefined1 local_a0;
  resource_s local_98;
  int local_10;
  
                    /* Unresolved local var: char * name@[???]
                       Unresolved local var: char[20] szModuleC@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_ac = '!';
  local_ab = 0x4d;
  local_aa = 0x6f;
  local_a9 = 100;
  local_a8 = 0x75;
  local_a7 = 0x6c;
  local_a6 = 0x65;
  local_a5 = 0x43;
  local_a4 = 0x2e;
  local_a3 = 100;
  local_a2 = 0x6c;
  local_a1 = 0x6c;
  local_a0 = 0;
  iVar3 = Cmd_Argc();
  if ((((iVar3 < 2) || (cmd_source == src_command)) || (s1 = Cmd_Argv(1), s1 == (char *)0x0)) ||
     ((*s1 == '\0' || ((iVar3 = Q_strncmp(s1,&local_ac,0xc), iVar3 == 0 && (svs.isSecure != false)))
      ))) goto LAB_000904d3;
  qVar4 = IsSafeFileToDownload(s1);
  pcVar2 = host_client;
  if ((qVar4 == false) || (sv_allow_download.value == 0.0)) {
    cVar1 = *s1;
joined_r0x0009063d:
    if (cVar1 != '\0') {
      MSG_WriteByte(&(host_client->netchan).message,0x31);
      MSG_WriteString(&(host_client->netchan).message,s1);
    }
  }
  else {
    if (host_client->fully_connected == false) {
      cVar1 = *s1;
      if (cVar1 != '!') {
        if ((sv_send_resources.value != 0.0) &&
           (((sv_downloadurl.string == (char *)0x0 || (*sv_downloadurl.string == '\0')) ||
            ((sVar5 = strlen(sv_downloadurl.string), 0x7f < sVar5 || (sv_allow_dlfile.value != 0.0))
            )))) {
          iVar3 = Netchan_CreateFileFragments(true,&pcVar2->netchan,s1);
          if (iVar3 != 0) {
            Netchan_FragSend(&host_client->netchan);
            goto LAB_000904d3;
          }
          cVar1 = *s1;
        }
        goto joined_r0x0009063d;
      }
    }
    else {
      cVar1 = *s1;
      if (cVar1 != '!') goto joined_r0x0009063d;
    }
    iVar3 = Q_strlen(s1);
    if ((iVar3 == 0x24) && (iVar3 = Q_strnicmp(s1,"!MD5",4), iVar3 == 0)) {
                    /* Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: resource_t custResource@[???]
                       Unresolved local var: uchar * pbuf@[???]
                       Unresolved local var: int size@[???] */
      local_c4 = (uchar *)0x0;
      local_c0 = 0;
      if (sv_send_logos.value != 0.0) {
        Q_memset(&local_98,0,0x88);
        COM_HexConvert(s1 + 4,0x20,local_bc);
        qVar4 = HPAK_ResourceForHash("custom.hpk",local_bc,&local_98);
        if (((qVar4 != false) &&
            (HPAK_GetDataPointer("custom.hpk",&local_98,&local_c4,&local_c0),
            local_c4 != (uchar *)0x0)) && (local_c0 != 0)) {
          Netchan_CreateFileFragmentsFromBuffer(true,&host_client->netchan,s1,local_c4,local_c0);
          Netchan_FragSend(&host_client->netchan);
          Mem_Free(local_c4);
        }
        goto LAB_000904d3;
      }
    }
    if (*s1 != '\0') {
      SV_FailDownload(s1);
    }
  }
LAB_000904d3:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_BeginRedirect  @ 00088270
void SV_BeginRedirect(redirect_t rd,netadr_t *addr)

{
  sv_redirected = rd;
  sv_redirectto.type = addr->type;
  sv_redirectto.ip = *&addr->ip;
  sv_redirectto.ipx._0_4_ = *(undefined4 *)addr->ipx;
  sv_redirectto.ipx._4_4_ = *(undefined4 *)(addr->ipx + 4);
  outputbuf[0] = '\0';
  sv_redirectto._16_4_ = *(undefined4 *)(addr->ipx + 8);
  return;
}


// SV_BroadcastCommand  @ 0008e370
void SV_BroadcastCommand(char *fmt,...)

{
  int iVar1;
  sizebuf_t *buf;
  int iVar2;
  int in_GS_OFFSET;
  sizebuf_t local_4a4;
  byte local_490 [128];
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] string@[???]
                       Unresolved local var: char[128] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_4a4.buffername = "Broadcast Command";
  local_4a4.data = local_490;
  local_4a4.cursize = 0;
  local_4a4.maxsize = 0x80;
  local_4a4.flags = 1;
  if (sv.active != false) {
    __vsnprintf_chk(local_410,0x400,1,0x400,fmt,&stack0x00000008);
    MSG_WriteByte(&local_4a4,9);
    MSG_WriteString(&local_4a4,local_410);
    if ((local_4a4.flags & 2) == 0) {
      iVar2 = 0;
      buf = &((svs.clients)->netchan).message;
      iVar1 = svs.maxclients;
      if (0 < svs.maxclients) {
        do {
          if ((((*(int *)&buf[-6].flags != 0) || (buf[-6].cursize != 0)) ||
              (buf[-6].data != (byte *)0x0)) && (buf[0x291].cursize == 0)) {
            SZ_Write(buf,local_4a4.data,local_4a4.cursize);
            iVar1 = svs.maxclients;
          }
          iVar2 = iVar2 + 1;
          buf = (sizebuf_t *)&buf[0x51e].cursize;
        } while (iVar2 < iVar1);
      }
    }
    else {
      Sys_Error("SV_BroadcastCommand:  Overflowed on %s, %i is max size\n",local_410,
                local_4a4.maxsize);
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_BroadcastPrintf  @ 00053a20
void SV_BroadcastPrintf(char *fmt,...)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???]
                       Unresolved local var: int i@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar4 = 0;
  __vsnprintf_chk(local_410,0x400,1,0x400,fmt,&stack0x00000008);
  iVar2 = svs.maxclients;
  iVar3 = 0;
  if (0 < svs.maxclients) {
    do {
      while (((puVar1 = ((svs.clients)->netchan).remote_address.ip + iVar3 + -0x24,
              *(int *)puVar1 == 0 && (*(int *)(puVar1 + 4) == 0)) ||
             (*(int *)(puVar1 + 0x33d8) != 0))) {
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x6668;
        if (iVar2 <= iVar4) goto LAB_00053af0;
      }
      iVar4 = iVar4 + 1;
      MSG_WriteByte((sizebuf_t *)(puVar1 + 0x74),8);
      MSG_WriteString((sizebuf_t *)(((svs.clients)->netchan).message_buf + iVar3 + -0x14),local_410)
      ;
      iVar2 = svs.maxclients;
      iVar3 = iVar3 + 0x6668;
    } while (iVar4 < svs.maxclients);
  }
LAB_00053af0:
  Con_DPrintf("%s",local_410);
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_BuildHashedSoundLookupTable  @ 000828e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_BuildHashedSoundLookupTable(void)

{
  char cVar1;
  __int32_t **pp_Var2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  
                    /* Unresolved local var: int sound_num@[???] */
  Q_memset(sv.sound_precache_hashedlookup,0,0x7fe);
  iVar7 = 0;
  do {
    pcVar5 = sv.sound_precache[iVar7];
    if (pcVar5 == (char *)0x0) {
      sv.sound_precache_hashedlookup_built = true;
      return;
    }
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int starting_index@[???]
                       Unresolved local var: uint hash@[???] */
    cVar1 = *pcVar5;
    if (cVar1 == '\0') {
      uVar3 = 0;
      uVar6 = uVar3;
    }
    else {
      pp_Var2 = __ctype_tolower_loc();
      uVar3 = 0;
      do {
        iVar4 = (int)cVar1;
        pcVar5 = pcVar5 + 1;
        cVar1 = *pcVar5;
        uVar3 = (*pp_Var2)[iVar4] + uVar3 * 2;
      } while (cVar1 != '\0');
      uVar3 = uVar3 % 0x3ff;
      uVar6 = uVar3;
    }
    while (*(short *)(uVar3 + 0x518828 + uVar3 + 0x195a0) != 0) {
      uVar3 = uVar3 + 1;
      hashstrings_collisions = hashstrings_collisions + 1;
      if (uVar3 == 0x3ff) {
        uVar3 = 0;
      }
      if (uVar3 == uVar6) {
        Sys_Error("SV_AddSampleToHashedLookupTable: NO FREE SLOTS IN SOUND LOOKUP TABLE");
      }
    }
    *(short *)(uVar3 + 0x518828 + uVar3 + 0x195a0) = (short)iVar7;
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0x200);
  sv.sound_precache_hashedlookup_built = true;
  return;
}


// SV_BuildReconnect  @ 0008e620
void SV_BuildReconnect(sizebuf_t *msg)

{
  MSG_WriteByte(msg,9);
  MSG_WriteString(msg,"reconnect\n");
  return;
}


// SV_BuildSoundMsg  @ 00082540
qboolean SV_BuildSoundMsg(edict_t *entity,int channel,char *sample,int volume,float attenuation,
                         int fFlags,int pitch,float *origin,sizebuf_t *buffer)

{
  float fVar1;
  uint32 data;
  uint32 data_00;
  int iVar2;
  
                    /* Unresolved local var: int sound_num@[???]
                       Unresolved local var: int field_mask@[???]
                       Unresolved local var: int ent@[???] */
  if ((uint)volume < 0x100) {
    if (0.0 <= attenuation) goto LAB_0008256d;
LAB_000827d2:
    Con_Printf("SV_StartSound: attenuation = %f",(double)attenuation);
    attenuation = 0.0;
    fVar1 = attenuation;
  }
  else {
    Con_Printf("SV_StartSound: volume = %i",volume);
    volume = ~(volume >> 0x1f) & 0xff;
    if (attenuation < 0.0) goto LAB_000827d2;
LAB_0008256d:
    fVar1 = attenuation;
    if (4.0 < attenuation) {
      Con_Printf("SV_StartSound: attenuation = %f",(double)attenuation);
      fVar1 = 4.0;
      if (attenuation < 0.0) {
        fVar1 = 0.0;
      }
    }
  }
  if (7 < (uint)channel) {
    Con_Printf("SV_StartSound: channel = %i",channel);
    channel = ~(channel >> 0x1f) & 7;
  }
  if (0xff < (uint)pitch) {
    Con_Printf("SV_StartSound: pitch = %i",pitch);
    pitch = ~(pitch >> 0x1f) & 7;
  }
  if (sample != (char *)0x0) {
    if (*sample == '!') {
      fFlags = fFlags | 0x10;
      data = Q_atoi(sample + 1);
      if (0x7ff < (int)data) {
        Con_Printf("invalid sentence number: %s",sample + 1);
        return false;
      }
      goto LAB_000825d5;
    }
    if (*sample == '#') {
      fFlags = fFlags | 0x10;
      iVar2 = Q_atoi(sample + 1);
      data = iVar2 + 0x800;
      goto LAB_000825d5;
    }
  }
  data = SV_LookupSoundIndex(sample);
  if ((data == 0) || (sv.sound_precache[data] == (char *)0x0)) {
    Con_Printf("SV_StartSound: %s not precached (%d)\n",sample,data);
    return false;
  }
LAB_000825d5:
  data_00 = NUM_FOR_EDICT(entity);
  if (volume != 0xff) {
    fFlags = fFlags | 1;
  }
  if (fVar1 != 1.0) {
    fFlags = fFlags | 2;
  }
  if (pitch != 100) {
    fFlags = fFlags | 8;
  }
  if (0xff < (int)data) {
    fFlags = fFlags | 4;
  }
  MSG_WriteByte(buffer,6);
  MSG_StartBitWriting(buffer);
  MSG_WriteBits(fFlags,9);
  if ((fFlags & 1U) != 0) {
    MSG_WriteBits(volume,8);
  }
  if ((fFlags & 2U) != 0) {
    MSG_WriteBits((int)(fVar1 * 64.0),8);
  }
  MSG_WriteBits(channel,3);
  MSG_WriteBits(data_00,0xb);
  if ((int)data < 0x100) {
    MSG_WriteBits(data,8);
  }
  else {
    MSG_WriteBits(data,0x10);
  }
  MSG_WriteBitVec3Coord(origin);
  if ((fFlags & 8U) != 0) {
    MSG_WriteBits(pitch,8);
  }
  MSG_EndBitWriting(buffer);
  return true;
}


// SV_CalcClientTime  @ 000a1e00
float SV_CalcClientTime(client_t *cl)

{
  float fVar1;
  float fVar2;
  float fVar3;
  client_frame_t *pcVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: float minping@[???]
                       Unresolved local var: float maxping@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int backtrack@[???] */
  iVar8 = (int)sv_unlagsamples.value;
  if (iVar8 < 1) {
    iVar8 = 1;
  }
  iVar9 = 0x10;
  if (SV_UPDATE_BACKUP < 0x11) {
    iVar9 = SV_UPDATE_BACKUP;
  }
  if (iVar9 <= iVar8) {
    iVar8 = iVar9;
  }
  if (iVar8 < 1) {
    return 0.0;
  }
  pcVar4 = cl->frames;
  uVar5 = (cl->netchan).incoming_acknowledged;
  fVar1 = pcVar4[uVar5 & SV_UPDATE_MASK].ping_time;
  if (0.0 < fVar1) {
    fVar6 = fVar1 + 0.0;
    iVar9 = 1;
    if (iVar8 != 1) goto LAB_000a1e74;
  }
  else {
    if (iVar8 == 1) {
      return 0.0;
    }
    iVar9 = 0;
    fVar6 = 0.0;
LAB_000a1e74:
    if (pcVar4[uVar5 - 1 & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar8 != 2) goto LAB_000a1e9d;
    }
    else {
      iVar9 = iVar9 + 1;
      fVar6 = pcVar4[uVar5 - 1 & SV_UPDATE_MASK].ping_time + fVar6;
      if (iVar8 == 2) goto LAB_000a2110;
LAB_000a1e9d:
      if (pcVar4[uVar5 - 2 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 3) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 2 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 3) goto LAB_000a2110;
      }
      if (pcVar4[uVar5 - 3 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 4) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 3 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 4) goto LAB_000a2110;
      }
      if (pcVar4[uVar5 - 4 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 5) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 4 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 5) goto LAB_000a2110;
      }
      if (pcVar4[uVar5 - 5 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 6) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 5 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 6) goto LAB_000a2110;
      }
      if (pcVar4[uVar5 - 6 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 7) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 6 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 7) goto LAB_000a2110;
      }
      if (pcVar4[uVar5 - 7 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 8) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 7 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 8) goto LAB_000a2110;
      }
      if (pcVar4[uVar5 - 8 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 9) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 8 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 9) goto LAB_000a2110;
      }
      if (pcVar4[uVar5 - 9 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 10) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 9 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 10) goto LAB_000a2110;
      }
      if (pcVar4[uVar5 - 10 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 0xb) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 10 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 0xb) goto LAB_000a2110;
      }
      if (pcVar4[uVar5 - 0xb & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 0xc) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 0xb & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 0xc) goto LAB_000a2110;
      }
      if (pcVar4[uVar5 - 0xc & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 0xd) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 0xc & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 0xd) goto LAB_000a2110;
      }
      if (pcVar4[uVar5 - 0xd & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar8 == 0xe) goto LAB_000a20e0;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar4[uVar5 - 0xd & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar8 == 0xe) goto LAB_000a2110;
      }
      if (0.0 < pcVar4[uVar5 - 0xe & SV_UPDATE_MASK].ping_time) {
        fVar6 = pcVar4[uVar5 - 0xe & SV_UPDATE_MASK].ping_time + fVar6;
        iVar9 = iVar9 + 1;
      }
      if ((iVar8 == 0x10) && (0.0 < pcVar4[uVar5 - 0xf & SV_UPDATE_MASK].ping_time)) {
        fVar6 = pcVar4[uVar5 - 0xf & SV_UPDATE_MASK].ping_time + fVar6;
        iVar9 = iVar9 + 1;
      }
    }
LAB_000a20e0:
    if (iVar9 == 0) {
      return 0.0;
    }
  }
LAB_000a2110:
  iVar8 = SV_UPDATE_BACKUP;
  if (4 < SV_UPDATE_BACKUP) {
    iVar8 = 4;
  }
  fVar6 = fVar6 / (float)iVar9;
  if (iVar8 < 1) {
    return fVar6;
  }
  fVar7 = 9999.0;
  if (fVar1 <= 0.0) {
    if (iVar8 == 1) {
      return fVar6;
    }
    fVar1 = -9999.0;
  }
  else {
    if (fVar1 < 9999.0) {
      fVar7 = fVar1;
    }
    if (fVar1 <= -9999.0) {
      fVar1 = -9999.0;
    }
    if (iVar8 == 1) goto LAB_000a2214;
  }
  fVar2 = pcVar4[uVar5 - 1 & SV_UPDATE_MASK].ping_time;
  fVar3 = fVar1;
  if (0.0 < fVar2) {
    if (fVar2 < fVar7) {
      fVar7 = fVar2;
    }
    fVar3 = fVar2;
    if (fVar2 <= fVar1) {
      fVar3 = fVar1;
    }
  }
  fVar1 = fVar3;
  if (iVar8 != 2) {
    fVar1 = pcVar4[uVar5 - 2 & SV_UPDATE_MASK].ping_time;
    fVar2 = fVar3;
    if (0.0 < fVar1) {
      if (fVar1 < fVar7) {
        fVar7 = fVar1;
      }
      fVar2 = fVar1;
      if (fVar1 <= fVar3) {
        fVar2 = fVar3;
      }
    }
    fVar1 = fVar2;
    if ((iVar8 == 4) && (fVar3 = pcVar4[SV_UPDATE_MASK & uVar5 - 3].ping_time, 0.0 < fVar3)) {
      if (fVar3 < fVar7) {
        fVar7 = fVar3;
      }
      fVar1 = fVar3;
      if (fVar3 <= fVar2) {
        fVar1 = fVar2;
      }
    }
  }
LAB_000a2214:
  if (fVar7 <= fVar1) {
    fVar2 = 0.0;
    if (ABS(fVar1 - fVar7) <= 0.2) {
      fVar2 = fVar6;
    }
    return fVar2;
  }
  return fVar6;
}


// SV_CalcPing  @ 00089550
int SV_CalcPing(client_t *cl)

{
  client_frame_t *pcVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int idx@[???] */
  if (cl->fakeclient != false) {
    return 0;
  }
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int idx@[???] */
  if (SV_UPDATE_BACKUP < 0x20) {
    iVar5 = SV_UPDATE_BACKUP / 2;
    if (iVar5 < 1) {
      return 0;
    }
  }
  else {
    iVar5 = 0x10;
  }
  pcVar1 = cl->frames;
  iVar2 = (cl->netchan).incoming_acknowledged;
  if (pcVar1[iVar2 - 1U & SV_UPDATE_MASK].ping_time <= 0.0) {
    if (iVar5 == 1) {
      return 0;
    }
    fVar3 = 0.0;
    iVar4 = 0;
  }
  else {
    iVar4 = 1;
    fVar3 = pcVar1[iVar2 - 1U & SV_UPDATE_MASK].ping_time + 0.0;
    if (iVar5 == 1) goto LAB_00089858;
  }
  if (pcVar1[iVar2 - 2U & SV_UPDATE_MASK].ping_time <= 0.0) {
    if (iVar5 != 2) goto LAB_000895e1;
  }
  else {
    iVar4 = iVar4 + 1;
    fVar3 = pcVar1[iVar2 - 2U & SV_UPDATE_MASK].ping_time + fVar3;
    if (iVar5 == 2) goto LAB_00089858;
LAB_000895e1:
    if (pcVar1[iVar2 - 3U & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 3) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 3U & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 3) goto LAB_00089858;
    }
    if (pcVar1[iVar2 - 4U & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 4) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 4U & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 4) goto LAB_00089858;
    }
    if (pcVar1[iVar2 - 5U & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 5) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 5U & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 5) goto LAB_00089858;
    }
    if (pcVar1[iVar2 - 6U & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 6) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 6U & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 6) goto LAB_00089858;
    }
    if (pcVar1[iVar2 - 7U & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 7) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 7U & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 7) goto LAB_00089858;
    }
    if (pcVar1[iVar2 - 8U & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 8) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 8U & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 8) goto LAB_00089858;
    }
    if (pcVar1[iVar2 - 9U & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 9) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 9U & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 9) goto LAB_00089858;
    }
    if (pcVar1[iVar2 - 10U & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 10) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 10U & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 10) goto LAB_00089858;
    }
    if (pcVar1[iVar2 - 0xbU & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 0xb) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 0xbU & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 0xb) goto LAB_00089858;
    }
    if (pcVar1[iVar2 - 0xcU & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 0xc) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 0xcU & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 0xc) goto LAB_00089858;
    }
    if (pcVar1[iVar2 - 0xdU & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 0xd) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 0xdU & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 0xd) goto LAB_00089858;
    }
    if (pcVar1[iVar2 - 0xeU & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar5 == 0xe) goto LAB_00089820;
    }
    else {
      iVar4 = iVar4 + 1;
      fVar3 = pcVar1[iVar2 - 0xeU & SV_UPDATE_MASK].ping_time + fVar3;
      if (iVar5 == 0xe) goto LAB_00089858;
    }
    if (0.0 < pcVar1[iVar2 - 0xfU & SV_UPDATE_MASK].ping_time) {
      fVar3 = pcVar1[iVar2 - 0xfU & SV_UPDATE_MASK].ping_time + fVar3;
      iVar4 = iVar4 + 1;
    }
    if ((iVar5 == 0x10) && (0.0 < pcVar1[iVar2 - 0x10U & SV_UPDATE_MASK].ping_time)) {
      fVar3 = pcVar1[iVar2 - 0x10U & SV_UPDATE_MASK].ping_time + fVar3;
      iVar4 = iVar4 + 1;
    }
  }
LAB_00089820:
  if (iVar4 == 0) {
    return 0;
  }
LAB_00089858:
  if (fVar3 / (float)iVar4 < 0.0) {
    return 0;
  }
  return (int)((fVar3 / (float)iVar4) * 1000.0);
}


// SV_CheckAllEnts  @ 000990c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckAllEnts(void)

{
  uint uVar1;
  edict_t *peVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int e@[???]
                       Unresolved local var: edict_t * check@[???] */
  if (sv.num_edicts < 2) {
    return;
  }
  iVar5 = 0x324;
  iVar3 = 1;
  iVar4 = sv.num_edicts;
  do {
    while (peVar2 = (edict_t *)((int)(sv.edicts)->leafnums + iVar5 + -0x18), peVar2->free != false)
    {
LAB_00099110:
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x324;
      if (iVar4 <= iVar3) {
        return;
      }
    }
    uVar1 = (peVar2->v).movetype;
    if ((0xc < uVar1) || (((byte)(0x1181 >> ((byte)uVar1 & 0x1f)) & 1) != 1)) {
      peVar2 = SV_TestEntityPosition(peVar2);
      iVar4 = sv.num_edicts;
      if (peVar2 != (edict_t *)0x0) {
        Con_Printf("entity in invalid position\n");
        iVar4 = sv.num_edicts;
      }
      goto LAB_00099110;
    }
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 0x324;
    if (iVar4 <= iVar3) {
      return;
    }
  } while( true );
}


// SV_CheckBlendingInterface  @ 0005e6d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckBlendingInterface(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: SV_BLENDING_INTERFACE_FUNC studio_interface@[???] */
  R_ResetSvBlending();
  if (0 < g_iextdllMac) {
    iVar3 = 0;
    do {
      pcVar1 = (code *)dlsym(g_rgextdll[iVar3].lDLLHandle,"Server_GetBlendingInterface");
      if (pcVar1 != (code *)0x0) {
        iVar2 = (*pcVar1)(1,&g_pSvBlendingAPI,&server_studio_api,rotationmatrix,bonetransform);
        if (iVar2 != 0) {
          return;
        }
        Con_DPrintf("Couldn\'t get server .dll studio model blending interface. Version mismatch?\n"
                   );
        R_ResetSvBlending();
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < g_iextdllMac);
  }
  return;
}


// SV_CheckBottom  @ 00095930
qboolean SV_CheckBottom(edict_t *ent)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  vec_t vVar7;
  int iVar8;
  int iVar9;
  qboolean monsterClipBrush;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  trace_t local_54;
  
                    /* Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t stop@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: float mid@[???]
                       Unresolved local var: float bottom@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  fVar2 = (ent->v).origin[0] + (ent->v).mins[0];
  g_groupmask = (ent->v).groupinfo;
  uVar1 = (ent->v).flags;
  fVar3 = (ent->v).origin[1] + (ent->v).mins[1];
  fVar4 = (ent->v).origin[2] + (ent->v).mins[2];
  fVar5 = (ent->v).origin[0] + (ent->v).maxs[0];
  fVar6 = (ent->v).origin[1] + (ent->v).maxs[1];
  local_64 = fVar4 - 1.0;
  local_6c = fVar2;
  local_68 = fVar3;
  iVar8 = SV_PointContents(&local_6c);
  if (iVar8 == -2) {
    g_groupmask = (ent->v).groupinfo;
    local_6c = fVar2;
    local_68 = fVar6;
    iVar8 = SV_PointContents(&local_6c);
    if (iVar8 == -2) {
      g_groupmask = (ent->v).groupinfo;
      local_6c = fVar5;
      local_68 = fVar3;
      iVar8 = SV_PointContents(&local_6c);
      if (iVar8 == -2) {
        g_groupmask = (ent->v).groupinfo;
        local_6c = fVar5;
        local_68 = fVar6;
        iVar8 = SV_PointContents(&local_6c);
        if (iVar8 == -2) goto LAB_00095a67;
      }
    }
  }
  local_64 = fVar4 + sv_stepsize.value;
  monsterClipBrush = uVar1 >> 0x17 & true;
  local_6c = (fVar2 + fVar5) * 0.5;
  c_no = c_no + 1;
  local_68 = (fVar3 + fVar6) * 0.5;
  local_58 = local_64 - (sv_stepsize.value + sv_stepsize.value);
  local_60 = local_6c;
  local_5c = local_68;
  SV_Move(&local_54,&local_6c,vec3_origin,vec3_origin,&local_60,1,ent,monsterClipBrush);
  vVar7 = local_54.endpos[2];
  if (local_54.fraction == 1.0) {
    return false;
  }
  iVar8 = 0;
  do {
    fVar4 = fVar2;
    if (iVar8 != 0) {
      fVar4 = fVar5;
    }
    iVar9 = 0;
    do {
      local_68 = fVar6;
      if (iVar9 == 0) {
        local_68 = fVar3;
      }
      local_6c = fVar4;
      local_60 = fVar4;
      local_5c = local_68;
      SV_Move(&local_54,&local_6c,vec3_origin,vec3_origin,&local_60,1,ent,monsterClipBrush);
      if (local_54.fraction == 1.0) {
        return false;
      }
      if (sv_stepsize.value < vVar7 - local_54.endpos[2]) {
        return false;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 2);
    iVar8 = iVar8 + 1;
  } while (iVar8 != 2);
LAB_00095a67:
  c_yes = c_yes + 1;
  return true;
}


// SV_CheckChallenge  @ 00085530
int SV_CheckChallenge(netadr_t *adr,int nChallengeValue)

{
  netadr_t a;
  qboolean qVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (adr == (netadr_t *)0x0) {
    Sys_Error("SV_CheckChallenge:  Null address\n");
    return 0;
  }
  qVar1 = NET_IsLocalAddress(*adr);
  if (qVar1 == false) {
    iVar2 = 0;
    while( true ) {
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
      qVar1 = NET_CompareBaseAdr(a,g_rg_sv_challenges[iVar2].adr);
      if (qVar1 != false) break;
                    /* Unresolved local var: int i@[???] */
      iVar2 = iVar2 + 1;
      if (iVar2 == 0x400) {
        SV_RejectConnection(adr,"No challenge for your address.\n");
        return 0;
      }
    }
    if (nChallengeValue != g_rg_sv_challenges[iVar2].challenge) {
      SV_RejectConnection(adr,"Bad challenge.\n");
      return 0;
    }
  }
  return 1;
}


// SV_CheckCmdTimes  @ 00080af0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckCmdTimes(void)

{
  client_s *pcVar1;
  double dVar2;
  double *pdVar3;
  double *pdVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  
  dVar2 = realtime;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: float dif@[???] */
  lVar5 = (longdouble)realtime;
  if (((longdouble)1 <= lVar5 - (longdouble)SV_CheckCmdTimes::lastreset) &&
     (SV_CheckCmdTimes::lastreset = realtime, 0 < svs.maxclients)) {
    lVar6 = (longdouble)clockwindow.value;
    pcVar1 = svs.clients + svs.maxclients;
    pdVar3 = &(svs.clients)->cmdtime;
    do {
      while ((*(qboolean *)(pdVar3 + -0x682) != false &&
             (((client_s *)((int)pdVar3 + -0x341c))->active != false))) {
        lVar7 = (longdouble)pdVar3[-1];
        if (lVar7 == (longdouble)0) {
          pdVar3[-1] = dVar2;
          lVar7 = lVar5;
        }
        lVar8 = (longdouble)(float)(((longdouble)*pdVar3 + lVar7) - lVar5);
        if (lVar6 < lVar8) {
          pdVar3[1] = (double)(lVar5 + lVar6);
          *pdVar3 = (double)(lVar5 - lVar7);
          break;
        }
        if (-lVar6 <= lVar8) break;
        pdVar4 = pdVar3 + 0xccd;
        *pdVar3 = (double)(lVar5 - lVar7);
        pdVar3 = pdVar4;
        if (&pcVar1->cmdtime == pdVar4) {
          return;
        }
      }
      pdVar3 = pdVar3 + 0xccd;
    } while (&pcVar1->cmdtime != pdVar3);
  }
  return;
}


// SV_CheckCmdTimes  @ 00090b30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckCmdTimes(void)

{
  qboolean qVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: float dif@[???] */
  qVar1 = Host_IsSinglePlayerGame();
  if (qVar1 == false) {
    SV_CheckCmdTimes();
    return;
  }
  return;
}


// SV_CheckFile  @ 0009e600
qboolean SV_CheckFile(sizebuf_t *msg,char *filename)

{
  int iVar1;
  qboolean qVar2;
  char *pcVar3;
  int in_GS_OFFSET;
  resource_s local_98;
  int local_10;
  
                    /* Unresolved local var: resource_t p@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&local_98,0,0x88);
  iVar1 = Q_strlen(filename);
  if ((iVar1 == 0x24) && (iVar1 = Q_strnicmp(filename,"!MD5",4), iVar1 == 0)) {
    COM_HexConvert(filename + 4,0x20,local_98.rgucMD5_hash);
    qVar2 = HPAK_GetDataPointer("custom.hpk",&local_98,(uchar **)0x0,(int *)0x0);
    if (qVar2 == false) goto LAB_0009e664;
  }
  else {
LAB_0009e664:
    if (sv_allow_upload.value != 0.0) {
      MSG_WriteByte(msg,9);
      pcVar3 = MD5_Print(local_98.rgucMD5_hash);
      pcVar3 = va("upload \"!MD5%s\"\n",pcVar3);
      MSG_WriteString(msg,pcVar3);
      qVar2 = false;
      goto LAB_0009e67b;
    }
  }
  qVar2 = true;
LAB_0009e67b:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_CheckForDuplicateNames  @ 00085ad0
int SV_CheckForDuplicateNames(char *userinfo,qboolean bIsReconnecting,int nExcludeSlot)

{
  char *s1;
  int iVar1;
  char *pcVar2;
  int iVar3;
  int in_GS_OFFSET;
  int local_58;
  int local_54;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: char[32] newname@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: char * val@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: int dupc@[???]
                       Unresolved local var: int retval@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  s1 = Info_ValueForKey(userinfo,"name");
  if (((((s1 != (char *)0x0) && (*s1 != '\0')) && (iVar1 = Q_stricmp(s1,"console"), iVar1 != 0)) &&
      ((pcVar2 = Q_strstr(s1,".."), pcVar2 == (char *)0x0 &&
       (pcVar2 = Q_strstr(s1,"\""), pcVar2 == (char *)0x0)))) &&
     (pcVar2 = Q_strstr(s1,"\\"), pcVar2 == (char *)0x0)) {
    local_54 = 0;
    local_58 = 1;
    do {
      iVar1 = 0;
      pcVar2 = (svs.clients)->name;
      while (((nExcludeSlot == iVar1 && (bIsReconnecting != false)) ||
             ((*(qboolean *)(pcVar2 + -0x634c) == false ||
              (iVar3 = Q_stricmp(pcVar2,s1), iVar3 != 0))))) {
        iVar1 = iVar1 + 1;
        pcVar2 = pcVar2 + 0x6668;
        if (iVar1 == 0x20) goto LAB_00085b3a;
      }
      if (*s1 == '(') {
        if (s1[2] == ')') {
          s1 = s1 + 3;
        }
        else if (s1[3] == ')') {
          s1 = s1 + 4;
        }
      }
      __snprintf_chk(local_40,0x20,1,0x20,"(%d)%-0.*s",local_58,0x1c,s1);
      Info_SetValueForKey(userinfo,"name",local_40,0x100);
      s1 = Info_ValueForKey(userinfo,"name");
      local_54 = 1;
      local_58 = local_58 + 1;
    } while( true );
  }
  Info_SetValueForKey(userinfo,"name","unamed",0x100);
  local_54 = 1;
LAB_00085b3a:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_54;
}


// SV_CheckForDuplicateSteamID  @ 00092ba0
int SV_CheckForDuplicateSteamID(client_t *client)

{
  client_s *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  char local_a0 [63];
  undefined1 local_61;
  char local_60 [63];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int nRet@[???]
                       Unresolved local var: int nCount@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((sv_lan.value == 0.0) && (0 < svs.maxclients)) {
                    /* Unresolved local var: client_t * cl@[???] */
    iVar5 = 0;
    iVar4 = svs.maxclients;
    do {
      pcVar1 = svs.clients + iVar5;
      if ((((pcVar1->connected != false) && (pcVar1->fakeclient == false)) &&
          (iVar3 = (pcVar1->network_userid).idtype, iVar3 - 1U < 2)) &&
         (((pcVar1 != client && (&client->network_userid != (USERID_t *)0x0)) &&
          ((&pcVar1->network_userid != (USERID_t *)0x0 && (iVar3 == (client->network_userid).idtype)
           ))))) {
                    /* Unresolved local var: char[64] szID1@[???]
                       Unresolved local var: char[64] szID2@[???] */
        pcVar2 = SV_GetIDString(&client->network_userid);
        strncpy(local_a0,pcVar2,0x3f);
        local_61 = 0;
        pcVar2 = SV_GetIDString(&pcVar1->network_userid);
        strncpy(local_60,pcVar2,0x3f);
        local_21 = 0;
        iVar3 = strcasecmp(local_a0,local_60);
        iVar4 = svs.maxclients;
        if (iVar3 == 0) goto LAB_00092c4a;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  iVar5 = -1;
LAB_00092c4a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_CheckForRcon  @ 00090b50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckForRcon(void)

{
  netadr_t to;
  int iVar1;
  uchar auVar2 [4];
  qboolean qVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  ipfilter_t *__dest;
  int in_GS_OFFSET;
  int local_7c;
  char local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((((sv.active == false) && (cls.state == ca_dedicated)) && (giActive != 3)) &&
     (host_initialized != false)) {
    while (qVar3 = NET_GetPacket(NS_SERVER), auVar2 = net_from.ip, qVar3 != false) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uint in@[???] */
      iVar5 = numipfilters + -1;
      __dest = ipfilters + iVar5;
      if (-1 < iVar5) {
        do {
          iVar1 = numipfilters;
          if (((__dest->compare == 0xffffffff) || ((double)__dest->banEndTime == 0.0)) ||
             (realtime < (double)__dest->banEndTime)) {
            if (__dest->compare == (__dest->mask & (uint)auVar2)) {
              local_7c = (int)(longlong)ROUND(sv_filterban.value);
              if (local_7c != 0) goto LAB_00090d51;
              goto LAB_00090c7e;
            }
          }
          else {
            if (iVar5 + 1 < numipfilters) {
              memmove(__dest,__dest + 1,((numipfilters + 0xfffffff) - iVar5) * 0x10);
            }
            numipfilters = iVar1 + -1;
          }
          iVar5 = iVar5 + -1;
          __dest = __dest + -1;
        } while (iVar5 != -1);
      }
      if (sv_filterban.value == 0.0) {
LAB_00090d51:
                    /* Unresolved local var: char[64] szMessage@[???] */
        uVar6 = 0;
        do {
          *(undefined4 *)(local_60 + uVar6) =
               *(undefined4 *)("You have been banned from this server.\n" + uVar6);
          uVar6 = uVar6 + 4;
        } while (uVar6 < 0x28);
        SZ_Clear(&net_message);
        MSG_WriteLong(&net_message,-1);
        MSG_WriteByte(&net_message,0x6c);
        MSG_WriteString(&net_message,local_60);
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
        NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,to);
        SZ_Clear(&net_message);
        NET_CheckCleanupFakeIPConnection(NS_SERVER,(netadr_t_conflict *)&net_from);
      }
      else {
LAB_00090c7e:
        if (*(int *)net_message.data == -1) {
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char * c@[???] */
          MSG_BeginReading();
          MSG_ReadLong();
          pcVar4 = MSG_ReadStringLine();
          Cmd_TokenizeString(pcVar4);
          pcVar4 = Cmd_Argv(0);
          iVar5 = Q_strcmp(pcVar4,"getchallenge");
          if (iVar5 == 0) {
            SVC_GetChallenge();
          }
          else {
            iVar5 = Q_stricmp(pcVar4,"challenge");
            if (iVar5 == 0) {
              SVC_ServiceChallenge();
            }
            else {
              iVar5 = Q_strcmp(pcVar4,"rcon");
              if (iVar5 == 0) {
                SV_Rcon(&net_from);
              }
            }
          }
        }
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_CheckIPConnectionReuse  @ 00085760
int SV_CheckIPConnectionReuse(netadr_t *adr)

{
  qboolean qVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: int i@[???] */
  if (0 < svs.maxclients) {
    iVar5 = 0;
    iVar4 = 0;
    iVar6 = 0;
    iVar3 = svs.maxclients;
    do {
                    /* Unresolved local var: client_t * cl@[???] */
      while ((*(int *)((int)(&((svs.clients)->netchan).remote_address + -1) + iVar5) == 0 ||
             (*(int *)(((svs.clients)->netchan).remote_address.ip + iVar5 + -0x1c) != 0))) {
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x6668;
        if (iVar3 <= iVar4) goto LAB_00085810;
      }
      qVar1 = NET_CompareBaseAdr(*adr,*(netadr_t *)
                                       (((svs.clients)->netchan).remote_address.ip + iVar5 + -4));
      if (qVar1 != false) {
        iVar6 = iVar6 + 1;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x6668;
      iVar3 = svs.maxclients;
    } while (iVar4 < svs.maxclients);
LAB_00085810:
    if (5 < iVar6) {
                    /* Unresolved local var: int count@[???]
                       Unresolved local var: int i@[???] */
      pcVar2 = NET_AdrToString(*adr);
      Log_Printf("Too many connect packets from %s\n",pcVar2);
      return 0;
    }
  }
  return 1;
}


// SV_CheckIPRestrictions  @ 00085670
int SV_CheckIPRestrictions(netadr_t *adr,int nAuthProtocol)

{
  netadr_t b;
  qboolean qVar1;
  
  if (((nAuthProtocol != 3) || (sv_lan.value != 0.0)) && (nAuthProtocol != 2)) {
    if (sv_lan.value == 0.0) {
      return 0;
    }
    b.ip = net_local_adr.ip;
    b.type = net_local_adr.type;
    b.ipx._0_4_ = net_local_adr.ipx._0_4_;
    b.ipx._4_4_ = net_local_adr.ipx._4_4_;
    b._16_4_ = net_local_adr._16_4_;
    qVar1 = NET_CompareClassBAdr(*adr,b);
    if (qVar1 == false) {
      qVar1 = NET_IsReservedAdr(*adr);
      return (uint)(qVar1 != false);
    }
  }
  return 1;
}


// SV_CheckKeyInfo  @ 00085920
int SV_CheckKeyInfo(netadr_t *adr,char *protinfo,ushort *port,int *pAuthProtocol,char *pszRaw,
                   int nRawSize,char *cdkey)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: int nAuthProtocol@[???] */
  pcVar1 = Info_ValueForKey(protinfo,"prot");
  iVar2 = Q_atoi(pcVar1);
  if (3 < iVar2 - 1U) {
    SV_RejectConnection(adr,"Invalid connection.\n");
    return 0;
  }
  pcVar1 = Info_ValueForKey(protinfo,"raw");
  iVar3 = Q_strlen(pcVar1);
  if (iVar3 < 1) {
LAB_00085a2d:
    SV_RejectConnection(adr,"Invalid authentication certificate length.\n");
    iVar2 = 0;
  }
  else {
    if (iVar2 == 2) {
      iVar3 = Q_strlen(pcVar1);
      if (iVar3 != 0x20) goto LAB_00085a2d;
      Q_strncpy(pszRaw,pcVar1,nRawSize);
      pszRaw[nRawSize + -1] = '\0';
      Q_strncpy(cdkey,pcVar1,0x40);
    }
    else {
      Q_strncpy(pszRaw,pcVar1,nRawSize);
      pszRaw[nRawSize + -1] = '\0';
      pcVar1 = Info_ValueForKey(protinfo,"cdkey");
      iVar3 = Q_strlen(pcVar1);
      if (iVar3 != 0x20) {
        SV_RejectConnection(adr,"Invalid hashed CD key.\n");
        return 0;
      }
      Q_strncpy(cdkey,pcVar1,0x40);
    }
    iVar3 = Q_atoi("27005");
    *port = (ushort)iVar3;
    *pAuthProtocol = iVar2;
    iVar2 = 1;
  }
  return iVar2;
}


// SV_CheckMapDifferences  @ 00090ea0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckMapDifferences(void)

{
  int iVar1;
  client_s *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???] */
  iVar1 = svs.maxclients;
  if ((5.0 <= realtime - SV_CheckMapDifferences::lastcheck) &&
     (SV_CheckMapDifferences::lastcheck = realtime, 0 < svs.maxclients)) {
    iVar3 = 0;
    pcVar2 = svs.clients;
    do {
      if ((((pcVar2->active != false) && (pcVar2->crcValue != 0)) &&
          ((pcVar2->netchan).remote_address.type != NA_LOOPBACK)) &&
         (pcVar2->crcValue != sv.worldmapCRC)) {
        (pcVar2->netchan).message.flags = (pcVar2->netchan).message.flags | 2;
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 1;
    } while (iVar3 != iVar1);
  }
  return;
}


// SV_CheckMovingGround  @ 000a1af0
void SV_CheckMovingGround(edict_t *player,float frametime)

{
  vec_t *pvVar1;
  edict_t *peVar2;
  uint uVar3;
  
                    /* Unresolved local var: edict_t * groundentity@[???] */
  uVar3 = (player->v).flags;
  if ((((uVar3 & 0x200) != 0) && (peVar2 = (player->v).groundentity, peVar2 != (edict_t *)0x0)) &&
     (((peVar2->v).flags & 4) != 0)) {
    pvVar1 = (player->v).basevelocity;
    if ((uVar3 & 0x400000) == 0) {
      VectorScale((peVar2->v).movedir,(peVar2->v).speed,pvVar1);
    }
    else {
      VectorMA(pvVar1,(peVar2->v).speed,(peVar2->v).movedir,pvVar1);
    }
    uVar3 = (player->v).flags | 0x400000;
    (player->v).flags = uVar3;
  }
  if ((uVar3 & 0x400000) == 0) {
    pvVar1 = (player->v).velocity;
    VectorMA(pvVar1,frametime * 0.5 + 1.0,(player->v).basevelocity,pvVar1);
    uVar3 = (player->v).flags;
    (player->v).basevelocity[0] = 0.0;
    (player->v).basevelocity[1] = 0.0;
    (player->v).basevelocity[2] = 0.0;
  }
  (player->v).flags = uVar3 & 0xffbfffff;
  return;
}


// SV_CheckProtocol  @ 00085450
int SV_CheckProtocol(netadr_t *adr,int nProtocol)

{
  int iVar1;
  char *pcVar2;
  
  if (adr == (netadr_t *)0x0) {
    Sys_Error("SV_CheckProtocol:  Null address\n");
  }
  else {
    if (nProtocol == 0x30) {
      return 1;
    }
    if (0x30 < nProtocol) {
      iVar1 = Q_strlen(sv_contact.string);
      pcVar2 = "(no email address specified)";
      if (0 < iVar1) {
        pcVar2 = sv_contact.string;
      }
      SV_RejectConnection(adr,
                          "This server is using an older protocol ( %i ) than your client ( %i ).  If you believe this server is outdated, you can contact the server administrator at %s.\n"
                          ,0x30,nProtocol,pcVar2);
      return 0;
    }
    SV_RejectConnection(adr,
                        "This server is using a newer protocol ( %i ) than your client ( %i ).  You should check for updates to your client.\n"
                        ,0x30,nProtocol);
  }
  return 0;
}


// SV_CheckRate  @ 00089010
void SV_CheckRate(client_t *cl)

{
  float fVar1;
  
  if ((0.0 < sv_maxrate.value) && (sv_maxrate.value < (float)(cl->netchan).rate)) {
    if (100000.0 <= sv_maxrate.value) {
      (cl->netchan).rate = 100000.0;
    }
    else {
      (cl->netchan).rate = (double)sv_maxrate.value;
    }
  }
  if ((0.0 < sv_minrate.value) && ((float)(cl->netchan).rate < sv_minrate.value)) {
    fVar1 = sv_minrate.value;
    if (sv_minrate.value <= 1000.0) {
      fVar1 = 1000.0;
    }
    (cl->netchan).rate = (double)fVar1;
  }
  return;
}


// SV_CheckRconFailure  @ 000889e0
qboolean SV_CheckRconFailure(netadr_t *adr)

{
  qboolean qVar1;
  rcon_failure_t *prVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: rcon_failure_t * r@[???] */
  prVar2 = g_rgRconFailures;
  do {
    if (prVar2->active != false) {
      qVar1 = NET_CompareAdr(*adr,prVar2->adr);
      if ((qVar1 != false) && (prVar2->shouldreject != false)) {
        return true;
      }
    }
    prVar2 = prVar2 + 1;
    if (prVar2 == (rcon_failure_t *)&hashstrings_collisions) {
      return false;
    }
  } while( true );
}


// SV_CheckSaveGameCommentInterface  @ 0005e760
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckSaveGameCommentInterface(void)

{
  SV_SAVEGAMECOMMENT_FUNC p_Var1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char * pszFunction@[???]
                       Unresolved local var: SV_SAVEGAMECOMMENT_FUNC pTemp@[???] */
  if (0 < g_iextdllMac) {
    iVar2 = 0;
    do {
      p_Var1 = (SV_SAVEGAMECOMMENT_FUNC)dlsym(g_rgextdll[iVar2].lDLLHandle,"SV_SaveGameComment");
      if (p_Var1 != (SV_SAVEGAMECOMMENT_FUNC)0x0) {
        g_pSaveGameCommentFunc = p_Var1;
        return;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < g_iextdllMac);
  }
  return;
}


// SV_CheckSphereIntersection  @ 00078420
qboolean SV_CheckSphereIntersection(edict_t *ent,vec_t *start,vec_t *end)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  qboolean qVar11;
  void *pvVar12;
  int iVar13;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float radiusSquared@[???]
                       Unresolved local var: vec3_t maxDim@[???]
                       Unresolved local var: vec3_t traceOrg@[???]
                       Unresolved local var: vec3_t traceDir@[???]
                       Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
  qVar11 = true;
  if (((ent->v).flags & 8) != 0) {
    fVar1 = *start;
    fVar2 = start[1];
    fVar3 = start[2];
    fVar4 = *end - fVar1;
    fVar5 = end[1] - fVar2;
    fVar6 = end[2] - fVar3;
    pvVar12 = Mod_Extradata(sv.models[(ent->v).modelindex]);
    iVar13 = (ent->v).sequence * 0xb0 + *(int *)((int)pvVar12 + 0xa8);
    fVar7 = ABS(*(float *)((int)pvVar12 + iVar13 + 0x60));
    fVar10 = ABS(*(float *)((int)pvVar12 + iVar13 + 0x6c));
    if (fVar7 <= fVar10) {
      fVar7 = fVar10;
    }
    fVar10 = ABS(*(float *)((int)pvVar12 + iVar13 + 100));
    fVar9 = ABS(*(float *)((int)pvVar12 + iVar13 + 0x70));
    if (fVar10 <= fVar9) {
      fVar10 = fVar9;
    }
    fVar9 = ABS(*(float *)((int)pvVar12 + iVar13 + 0x68));
    fVar8 = ABS(*(float *)((int)pvVar12 + iVar13 + 0x74));
    if (fVar9 <= fVar8) {
      fVar9 = fVar8;
    }
                    /* Unresolved local var: vec3_t P@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: float b@[???]
                       Unresolved local var: float c@[???]
                       Unresolved local var: float insideSqr@[???] */
    fVar1 = fVar1 - (ent->v).origin[0];
    fVar2 = fVar2 - (ent->v).origin[1];
    fVar3 = fVar3 - (ent->v).origin[2];
    fVar8 = fVar6 * fVar3 + fVar5 * fVar2 + fVar4 * fVar1;
    fVar8 = fVar8 + fVar8;
    qVar11 = (qboolean)
             (1e-06 < fVar8 * fVar8 -
                      (fVar6 * fVar6 + fVar5 * fVar5 + fVar4 * fVar4) * 4.0 *
                      ((fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1) -
                      (fVar9 * fVar9 + fVar10 * fVar10 + fVar7 * fVar7 + 0.0)));
  }
  return qVar11;
}


// SV_CheckTimeouts  @ 00089480
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CheckTimeouts(void)

{
  float fVar1;
  int iVar2;
  client_s *cl;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: float droptime@[???] */
  fVar1 = (float)realtime - sv_timeout.value;
  if (0 < svs.maxclients) {
    iVar3 = 0;
    iVar2 = svs.maxclients;
    cl = svs.clients;
    do {
      while (((cl->fakeclient != false ||
              (((cl->connected == false && (cl->active == false)) && (cl->spawned == false)))) ||
             (fVar1 <= (cl->netchan).last_received))) {
        iVar3 = iVar3 + 1;
        cl = cl + 1;
        if (iVar2 <= iVar3) {
          return;
        }
      }
      iVar3 = iVar3 + 1;
      SV_BroadcastPrintf("%s timed out\n",cl->name);
      SV_DropClient(cl,false,"Timed out");
      iVar2 = svs.maxclients;
      cl = cl + 1;
    } while (iVar3 < svs.maxclients);
  }
  return;
}


// SV_CheckUpdateRate  @ 00085130
void SV_CheckUpdateRate(double *rate)

{
  if (*rate == 0.0) {
    *(undefined4 *)rate = 0x9999999a;
    *(undefined4 *)((int)rate + 4) = 0x3fa99999;
    return;
  }
  if ((sv_maxupdaterate.value != 0.0) && (sv_maxupdaterate.value <= 0.001)) {
    Cvar_Set("sv_maxupdaterate","30.0");
  }
  if ((sv_minupdaterate.value != 0.0) && (sv_minupdaterate.value <= 0.001)) {
    Cvar_Set("sv_minupdaterate","1.0");
  }
  if ((sv_maxupdaterate.value != 0.0) && ((float)*rate < 1.0 / sv_maxupdaterate.value)) {
    *rate = (double)(1.0 / sv_maxupdaterate.value);
  }
  if ((sv_minupdaterate.value != 0.0) && (1.0 / sv_minupdaterate.value < (float)*rate)) {
    *rate = (double)(1.0 / sv_minupdaterate.value);
  }
  return;
}


// SV_CheckUserInfo  @ 00085cf0
int SV_CheckUserInfo(netadr_t *adr,char *userinfo,qboolean bIsReconnecting,int nReconnectSlot,
                    char *name)

{
  float fVar1;
  char *pcVar2;
  qboolean qVar3;
  size_t sVar4;
  char *pcVar5;
  int iVar6;
  qboolean qVar7;
  client_s *pcVar8;
  int iVar9;
  int in_GS_OFFSET;
  char local_40 [31];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char * pChar@[???]
                       Unresolved local var: char[32] newname@[???]
                       Unresolved local var: int proxies@[???]
                       Unresolved local var: int i@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  qVar3 = NET_IsLocalAddress(*adr);
  if (((qVar3 == false) && (*sv_password.string != '\0')) &&
     (iVar6 = Q_stricmp(sv_password.string,"none"), iVar6 != 0)) {
    pcVar5 = Info_ValueForKey(userinfo,"password");
    iVar6 = Q_strcmp(sv_password.string,pcVar5);
    if (iVar6 != 0) {
      pcVar5 = NET_AdrToString(*adr);
      Con_Printf("%s:  password failed\n",pcVar5);
      SZ_Clear(&net_message);
      MSG_WriteLong(&net_message,-1);
      MSG_WriteByte(&net_message,0x38);
      MSG_WriteString(&net_message,"BADPASSWORD");
      NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,*adr);
      SZ_Clear(&net_message);
      iVar6 = 0;
      goto LAB_00085d87;
    }
  }
  sVar4 = strlen(userinfo);
  if (((sVar4 < 5) || (pcVar5 = strstr(userinfo,"\\\\"), pcVar5 != (char *)0x0)) ||
     (userinfo[sVar4 - 1] == '\\')) {
LAB_00085d74:
    SV_RejectConnection(adr,"Unknown HLTV client type.\n");
    iVar6 = 0;
  }
  else {
    Info_RemoveKey(userinfo,"password");
    pcVar5 = Info_ValueForKey(userinfo,"name");
    iVar6 = Q_strlen(pcVar5);
    if (iVar6 == 0) {
      Q_strcpy(local_40,"unnamed");
    }
    else {
      Q_strncpy(local_40,pcVar5,0x20);
      local_21 = 0;
    }
    pcVar5 = local_40;
    do {
      pcVar2 = local_40;
      if (*pcVar5 == '\0') break;
      if ((byte)(*pcVar5 - 0x25U) < 2) {
        *pcVar5 = ' ';
      }
      pcVar5 = pcVar5 + 1;
    } while (pcVar5 != (char *)0x0);
    while (local_40[0] == '#') {
      *pcVar2 = ' ';
      local_40[0] = pcVar2[1];
      pcVar2 = pcVar2 + 1;
    }
    TrimSpace(local_40,name);
    qVar7 = Q_UnicodeValidate(name);
    if (qVar7 == 0) {
      Q_UnicodeRepair(name);
    }
    Info_SetValueForKey(userinfo,"name",name,0x100);
    iVar6 = SV_CheckForDuplicateNames(userinfo,bIsReconnecting,nReconnectSlot);
    if (iVar6 != 0) {
      pcVar5 = Info_ValueForKey(userinfo,"name");
      Q_strncpy(name,pcVar5,0x20);
      name[0x1f] = '\0';
    }
    pcVar5 = Info_ValueForKey(userinfo,"*hltv");
    iVar6 = Q_strlen(pcVar5);
    if (iVar6 != 0) {
      iVar6 = Q_atoi(pcVar5);
      if (iVar6 == 1) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
        if (svs.maxclients < 1) {
          fVar1 = 0.0;
        }
        else {
          iVar6 = 0;
          iVar9 = 0;
          pcVar8 = svs.clients;
          do {
            if (((pcVar8->active != false) || (pcVar8->spawned != false)) ||
               (pcVar8->connected != false)) {
              iVar6 = (iVar6 + 1) - (uint)(pcVar8->proxy == false);
            }
            iVar9 = iVar9 + 1;
            pcVar8 = pcVar8 + 1;
          } while (svs.maxclients != iVar9);
          fVar1 = (float)iVar6;
        }
        if ((sv_proxies.value <= fVar1) && (bIsReconnecting == false)) {
          SV_RejectConnection(adr,"Proxy slots are full.\n");
          iVar6 = 0;
          goto LAB_00085d87;
        }
      }
      else {
        if (iVar6 == 3) {
          SV_RejectConnection(adr,"Please connect to HLTV master proxy.\n");
          iVar6 = 0;
          goto LAB_00085d87;
        }
        if (iVar6 != 0) goto LAB_00085d74;
      }
    }
    iVar6 = 1;
  }
LAB_00085d87:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}


// SV_CheckVelocity  @ 00099160
void SV_CheckVelocity(edict_t *ent)

{
  float fVar1;
  uint uVar2;
  
                    /* Unresolved local var: int i@[???] */
  uVar2 = nanmask;
  if (((uint)(ent->v).velocity[0] & nanmask) == nanmask) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar2 = nanmask;
    (ent->v).velocity[0] = 0.0;
  }
  if (uVar2 == ((uint)(ent->v).origin[0] & uVar2)) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[0] = 0.0;
  }
  fVar1 = (ent->v).velocity[0];
  if (sv_maxvelocity.value < fVar1) {
    Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[0] = sv_maxvelocity.value;
  }
  else if (fVar1 < -sv_maxvelocity.value) {
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[0] = -sv_maxvelocity.value;
  }
  uVar2 = nanmask;
  if (nanmask == ((uint)(ent->v).velocity[1] & nanmask)) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar2 = nanmask;
    (ent->v).velocity[1] = 0.0;
  }
  if (uVar2 == ((uint)(ent->v).origin[1] & uVar2)) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[1] = 0.0;
  }
  fVar1 = (ent->v).velocity[1];
  if (sv_maxvelocity.value < fVar1) {
    Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[1] = sv_maxvelocity.value;
  }
  else if (fVar1 < -sv_maxvelocity.value) {
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[1] = -sv_maxvelocity.value;
  }
  uVar2 = nanmask;
  if (nanmask == ((uint)(ent->v).velocity[2] & nanmask)) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar2 = nanmask;
    (ent->v).velocity[2] = 0.0;
  }
  if (((uint)(ent->v).origin[2] & uVar2) == uVar2) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[2] = 0.0;
  }
  fVar1 = (ent->v).velocity[2];
  if (fVar1 <= sv_maxvelocity.value) {
    if (-sv_maxvelocity.value <= fVar1) {
      return;
    }
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[2] = -sv_maxvelocity.value;
    return;
  }
  Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
  (ent->v).velocity[2] = sv_maxvelocity.value;
  return;
}


// SV_CheckVisibility  @ 0008ba10
int SV_CheckVisibility(edict_s *entity,uchar *pset)

{
  int iVar1;
  qboolean qVar2;
  int iVar3;
  short *psVar4;
  int local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean visible@[???]
                       Unresolved local var: edict_t * e@[???] */
  if (pset == (uchar *)0x0) {
    return 1;
  }
  if (entity->headnode < 0) {
    if (0 < entity->num_leafs) {
      if (((int)(uint)pset[(int)entity->leafnums[0] >> 3] >> ((byte)entity->leafnums[0] & 7) & 1U)
          != 0) {
        return 1;
      }
      psVar4 = entity->leafnums;
      do {
        psVar4 = psVar4 + 1;
        if (psVar4 == entity->leafnums + entity->num_leafs) {
          return 0;
        }
      } while (((int)(uint)pset[(int)*psVar4 >> 3] >> ((byte)*psVar4 & 7) & 1U) == 0);
      return 1;
    }
    iVar3 = 0;
  }
  else {
    psVar4 = entity->leafnums;
    do {
      local_20[0] = (int)*psVar4;
      if (local_20[0] == -1) {
        local_20[0] = -1;
        break;
      }
                    /* Unresolved local var: int leaf@[???] */
      if (((int)(uint)pset[local_20[0] >> 3] >> ((byte)*psVar4 & 7) & 1U) != 0) {
        return 1;
      }
      psVar4 = psVar4 + 1;
    } while (&entity->freetime != (float *)psVar4);
    qVar2 = CM_HeadnodeVisible((sv.worldmodel)->nodes + entity->headnode,pset,local_20);
    iVar3 = 0;
    if (qVar2 != false) {
      iVar1 = entity->num_leafs;
      entity->leafnums[iVar1] = (short)local_20[0];
      iVar3 = 2;
      entity->num_leafs = (iVar1 + 1) % 0x30;
    }
  }
  return iVar3;
}


// SV_CheckWater  @ 0009be40
qboolean SV_CheckWater(edict_t *ent)

{
  vec_t *veca;
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: vec3_t point@[???]
                       Unresolved local var: int cont@[???]
                       Unresolved local var: int truecont@[???] */
  g_groupmask = (ent->v).groupinfo;
  (ent->v).watertype = -1;
  (ent->v).waterlevel = 0;
  local_28 = ((ent->v).absmin[0] + (ent->v).absmax[0]) * 0.5;
  local_24 = ((ent->v).absmin[1] + (ent->v).absmax[1]) * 0.5;
  local_20 = (ent->v).absmin[2] + 1.0;
  iVar3 = SV_PointContents(&local_28);
  if (iVar3 + 0xeU < 0xc) {
    fVar1 = (ent->v).absmin[2];
    fVar2 = (ent->v).absmax[2];
    (ent->v).watertype = iVar3;
    (ent->v).waterlevel = 1;
    if (fVar1 == fVar2) {
LAB_0009beec:
      iVar4 = 3;
      (ent->v).waterlevel = 3;
    }
    else {
      g_groupmask = (ent->v).groupinfo;
      local_20 = (fVar1 + fVar2) * 0.5;
      iVar4 = SV_PointContents(&local_28);
      if (iVar4 + 0xeU < 0xc) {
        local_28 = local_28 + (ent->v).view_ofs[0];
        (ent->v).waterlevel = 2;
        g_groupmask = (ent->v).groupinfo;
        local_24 = local_24 + (ent->v).view_ofs[1];
        local_20 = local_20 + (ent->v).view_ofs[2];
        iVar4 = SV_PointContents(&local_28);
        if (iVar4 + 0xeU < 0xc) goto LAB_0009beec;
      }
      iVar4 = (ent->v).waterlevel;
    }
    if (5 < iVar3 + 0xeU) goto LAB_0009bf40;
    veca = (ent->v).basevelocity;
    VectorMA(veca,(float)iVar4 * 50.0,SV_CheckWater::lexical_block_0::current_table[-9 - iVar3],veca
            );
  }
  iVar4 = (ent->v).waterlevel;
LAB_0009bf40:
  return (uint)(1 < iVar4);
}


// SV_CheckWaterTransition  @ 0009c950
void SV_CheckWaterTransition(edict_t *ent)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int cont@[???]
                       Unresolved local var: vec3_t point@[???] */
  g_groupmask = (ent->v).groupinfo;
  local_18 = ((ent->v).absmin[0] + (ent->v).absmax[0]) * 0.5;
  local_14 = ((ent->v).absmin[1] + (ent->v).absmax[1]) * 0.5;
  local_10 = (ent->v).absmin[2] + 1.0;
  iVar3 = SV_PointContents(&local_18);
  iVar4 = (ent->v).watertype;
  if (iVar4 == 0) {
    (ent->v).watertype = iVar3;
    (ent->v).waterlevel = 1;
  }
  else {
    if (0xb < iVar3 + 0xeU) {
      if (iVar4 != -1) {
        SV_StartSound(0,ent,0,"player/pl_wade2.wav",0xff,1.0,0,100);
      }
      (ent->v).watertype = -1;
      (ent->v).waterlevel = 0;
      return;
    }
    if (iVar4 == -1) {
      SV_StartSound(0,ent,0,"player/pl_wade1.wav",0xff,1.0,0,100);
      (ent->v).velocity[2] = (ent->v).velocity[2] * 0.5;
    }
    fVar1 = (ent->v).absmin[2];
    fVar2 = (ent->v).absmax[2];
    (ent->v).watertype = iVar3;
    (ent->v).waterlevel = 1;
    if (fVar1 == fVar2) {
LAB_0009ca08:
      (ent->v).waterlevel = 3;
      return;
    }
    g_groupmask = (ent->v).groupinfo;
    local_10 = (fVar1 + fVar2) * 0.5;
    iVar4 = SV_PointContents(&local_18);
    if (iVar4 + 0xeU < 0xc) {
      local_18 = local_18 + (ent->v).view_ofs[0];
      (ent->v).waterlevel = 2;
      g_groupmask = (ent->v).groupinfo;
      local_14 = local_14 + (ent->v).view_ofs[1];
      local_10 = local_10 + (ent->v).view_ofs[2];
      iVar4 = SV_PointContents(&local_18);
      if (iVar4 + 0xeU < 0xc) goto LAB_0009ca08;
    }
  }
  return;
}


// SV_CleanupEnts  @ 0008c410
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CleanupEnts(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int e@[???]
                       Unresolved local var: edict_t * ent@[???] */
  iVar3 = 0x324;
  iVar2 = 1;
  if (1 < sv.num_edicts) {
    do {
      iVar2 = iVar2 + 1;
      puVar1 = (uint *)((int)((sv.edicts)->v).size + iVar3 + 0x24);
      *puVar1 = *puVar1 & 0xffffffdd;
      iVar3 = iVar3 + 0x324;
    } while (iVar2 < sv.num_edicts);
  }
  return;
}


// SV_ClearCaches  @ 0008de90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ClearCaches(void)

{
  char **ppcVar1;
  
                    /* Unresolved local var: int i@[???] */
  ppcVar1 = &sv.event_precache[1].filename;
  do {
    if (*ppcVar1 == (char *)0x0) {
      return;
    }
    *ppcVar1 = (char *)0x0;
    if (ppcVar1[2] != (char *)0x0) {
      Mem_Free(ppcVar1[2]);
    }
    ppcVar1[2] = (char *)0x0;
    ppcVar1 = ppcVar1 + 4;
  } while (ppcVar1 != sv.sound_precache + 1);
  return;
}


// SV_ClearClientStates  @ 000544e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ClearClientStates(void)

{
  client_s *cl;
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclients) {
    iVar1 = 0;
    cl = svs.clients;
    do {
      iVar1 = iVar1 + 1;
      COM_ClearCustomizationList(&cl->customdata,false);
      SV_ClearResourceLists(cl);
      cl = cl + 1;
    } while (iVar1 < svs.maxclients);
  }
  return;
}


// SV_ClearEntities  @ 0008fd30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ClearEntities(void)

{
  edict_t *pEdict;
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (0 < sv.num_edicts) {
    iVar3 = 0;
    iVar2 = 0;
    iVar1 = sv.num_edicts;
    do {
                    /* Unresolved local var: edict_t * pEdict@[???] */
      while (pEdict = (edict_t *)((int)(sv.edicts)->leafnums + iVar3 + -0x18), pEdict->free != false
            ) {
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x324;
        if (iVar1 <= iVar2) {
          return;
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x324;
      ReleaseEntityDLLFields(pEdict);
      iVar1 = sv.num_edicts;
    } while (iVar2 < sv.num_edicts);
  }
  return;
}


// SV_ClearFrames  @ 00082000
void SV_ClearFrames(client_frame_t **frames)

{
  entity_state_s *p;
  client_frame_t *p_00;
  int iVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_frame_t * pframe@[???] */
  p_00 = *frames;
  if (p_00 != (client_frame_t *)0x0) {
    if (0 < SV_UPDATE_BACKUP) {
      iVar1 = 0;
      do {
                    /* Unresolved local var: packet_entities_t * pack@[???] */
        if (p_00 != (client_frame_t *)0x0) {
          p = (p_00->entities).entities;
          if (p != (entity_state_s *)0x0) {
            Mem_Free(p);
          }
          (p_00->entities).entities = (entity_state_s *)0x0;
          (p_00->entities).num_entities = 0;
        }
        *(undefined4 *)&p_00->senttime = 0;
        iVar1 = iVar1 + 1;
        *(undefined4 *)((int)&p_00->senttime + 4) = 0;
        p_00->ping_time = -1.0;
        p_00 = p_00 + 1;
      } while (iVar1 < SV_UPDATE_BACKUP);
      p_00 = *frames;
    }
    Mem_Free(p_00);
    *frames = (client_frame_t *)0x0;
  }
  return;
}


// SV_ClearPacketEntities  @ 00081f80
void SV_ClearPacketEntities(client_frame_t *frame)

{
  entity_state_s *p;
  
                    /* Unresolved local var: packet_entities_t * pack@[???] */
  if (frame != (client_frame_t *)0x0) {
    p = (frame->entities).entities;
    if (p != (entity_state_s *)0x0) {
      Mem_Free(p);
    }
    (frame->entities).entities = (entity_state_s *)0x0;
    (frame->entities).num_entities = 0;
  }
  return;
}


// SV_ClearResourceList  @ 0009ee40
void SV_ClearResourceList(resource_t *pList)

{
  resource_s *prVar1;
  resource_t *p;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  p = pList->pNext;
  while ((p != (resource_t *)0x0 && (pList != p))) {
    prVar1 = p->pNext;
    p->pPrev->pNext = prVar1;
    p->pNext->pPrev = p->pPrev;
    p->pPrev = (resource_s *)0x0;
    p->pNext = (resource_s *)0x0;
    Mem_Free(p);
    p = prVar1;
  }
  pList->pPrev = pList;
  pList->pNext = pList;
  return;
}


// SV_ClearResourceLists  @ 0009e770
void SV_ClearResourceLists(client_t *cl)

{
  resource_t *prVar1;
  resource_s *prVar2;
  resource_s *prVar3;
  
  if (cl == (client_t *)0x0) {
    Sys_Error("SV_ClearResourceLists with NULL client!");
  }
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  prVar1 = &cl->resourcesneeded;
  prVar3 = (cl->resourcesneeded).pNext;
  while ((prVar3 != (resource_s *)0x0 && (prVar1 != prVar3))) {
    prVar2 = prVar3->pNext;
    prVar3->pPrev->pNext = prVar2;
    prVar3->pNext->pPrev = prVar3->pPrev;
    prVar3->pPrev = (resource_s *)0x0;
    prVar3->pNext = (resource_s *)0x0;
    Mem_Free(prVar3);
    prVar3 = prVar2;
  }
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  prVar3 = (cl->resourcesonhand).pNext;
  (cl->resourcesneeded).pPrev = prVar1;
  (cl->resourcesneeded).pNext = prVar1;
  prVar1 = &cl->resourcesonhand;
  if ((prVar1 != prVar3) && (prVar3 != (resource_s *)0x0)) {
    do {
      prVar2 = prVar3->pNext;
      prVar3->pPrev->pNext = prVar2;
      prVar3->pNext->pPrev = prVar3->pPrev;
      prVar3->pPrev = (resource_s *)0x0;
      prVar3->pNext = (resource_s *)0x0;
      Mem_Free(prVar3);
      if (prVar2 == (resource_s *)0x0) break;
      prVar3 = prVar2;
    } while (prVar1 != prVar2);
  }
  (cl->resourcesonhand).pPrev = prVar1;
  (cl->resourcesonhand).pNext = prVar1;
  return;
}


// SV_ClearWorld  @ 000a9470
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ClearWorld(void)

{
  uint uVar1;
  uint uVar2;
  float local_3c;
  float local_38;
  vec_t local_34;
  float local_30 [2];
  vec_t local_28;
  float local_24 [2];
  vec_t local_1c;
  float local_18;
  float local_14;
  vec_t local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???] */
  box_hull.planes = box_planes;
  box_hull.firstclipnode = 0;
  box_hull.lastclipnode = 5;
  box_hull.clipnodes = box_clipnodes;
  uVar1 = 0;
  do {
    uVar2 = uVar1 + 4;
    *(undefined4 *)((int)beam_hull.clip_mins + (uVar1 - 0x10)) =
         *(undefined4 *)((int)box_hull.clip_mins + (uVar1 - 0x10));
    uVar1 = uVar2;
  } while (uVar2 < 0x28);
  beam_hull.planes = beam_planes;
  box_clipnodes[0].children[1] = 1;
  box_clipnodes[1].planenum = 1;
  box_clipnodes[1].children[1] = -1;
  box_clipnodes[1].children[0] = 2;
  box_clipnodes[2].planenum = 2;
  box_clipnodes[2].children[0] = -1;
  box_clipnodes[3].children[1] = -1;
  box_clipnodes[3].children[0] = 4;
  box_clipnodes[4].planenum = 4;
  box_clipnodes[4].children[0] = -1;
  box_clipnodes[0].planenum = 0;
  box_clipnodes[0].children[0] = -1;
  box_clipnodes[4].children[1] = 5;
  box_clipnodes[2].children[1] = 3;
  box_clipnodes[3].planenum = 3;
  box_planes[0].type = '\0';
  box_planes[0].normal[0] = 1.0;
  beam_planes[0].type = '\x05';
  box_planes[1].type = '\0';
  box_planes[1].normal[0] = 1.0;
  beam_planes[1].type = '\x05';
  box_planes[2].type = '\x01';
  box_planes[2].normal[1] = 1.0;
  beam_planes[2].type = '\x05';
  box_planes[3].type = '\x01';
  box_planes[3].normal[1] = 1.0;
  beam_planes[3].type = '\x05';
  box_planes[4].type = '\x02';
  box_planes[4].normal[2] = 1.0;
  beam_planes[4].type = '\x05';
  box_clipnodes[5].planenum = 5;
  box_clipnodes[5].children[1] = -1;
  box_clipnodes[5].children[0] = -2;
  box_planes[5].type = '\x02';
  box_planes[5].normal[2] = 1.0;
  beam_planes[5].type = '\x05';
  Q_memset(sv_areanodes,0,0x400);
                    /* Unresolved local var: areanode_t * anode@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: vec3_t mins1@[???]
                       Unresolved local var: vec3_t maxs1@[???]
                       Unresolved local var: vec3_t mins2@[???]
                       Unresolved local var: vec3_t maxs2@[???] */
  sv_numareanodes = 1;
  sv_areanodes[0].trigger_edicts.prev = &sv_areanodes[0].trigger_edicts;
  sv_areanodes[0].solid_edicts.prev = &sv_areanodes[0].solid_edicts;
  sv_areanodes[0].trigger_edicts.next = &sv_areanodes[0].trigger_edicts;
  sv_areanodes[0].solid_edicts.next = &sv_areanodes[0].solid_edicts;
  local_18 = (sv.worldmodel)->maxs[0];
  local_3c = (sv.worldmodel)->mins[0];
  local_14 = (sv.worldmodel)->maxs[1];
  local_38 = (sv.worldmodel)->mins[1];
  sv_areanodes[0].axis = (int)(local_18 - local_3c <= local_14 - local_38);
  sv_areanodes[0].dist =
       ((sv.worldmodel)->maxs[sv_areanodes[0].axis] + (sv.worldmodel)->mins[sv_areanodes[0].axis]) *
       0.5;
  local_34 = (sv.worldmodel)->mins[2];
  local_28 = (sv.worldmodel)->maxs[2];
  local_24[0] = local_3c;
  local_24[1] = local_38;
  local_24[sv_areanodes[0].axis] = sv_areanodes[0].dist;
  local_30[0] = local_18;
  local_30[1] = local_14;
  local_30[sv_areanodes[0].axis] = sv_areanodes[0].dist;
  local_1c = local_34;
  local_10 = local_28;
  sv_areanodes[0].children[0] = SV_CreateAreaNode(1,local_24,&local_18);
  sv_areanodes[0].children[1] = SV_CreateAreaNode(1,&local_3c,local_30);
  return;
}


// SV_ClientPrintf  @ 00053960
void SV_ClientPrintf(char *fmt,...)

{
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (host_client->fakeclient == false) {
    __vsnprintf_chk(local_410,0x400,1,0x400,fmt,&stack0x00000008);
    MSG_WriteByte(&(host_client->netchan).message,8);
    MSG_WriteString(&(host_client->netchan).message,local_410);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_ClipMoveToEntity  @ 000ab050
trace_t * SV_ClipMoveToEntity(trace_t *__return_storage_ptr__,edict_t *ent,vec_t *start,vec_t *mins,
                             vec_t *maxs,vec_t *end)

{
  uint uVar1;
  trace_t local_44;
  
                    /* Unresolved local var: trace_t goodtrace@[???] */
                    /* Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: model_t * pmodel@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int rotated@[???]
                       Unresolved local var: int idx@[???] */
  if (ent != (edict_t *)0x0) {
    SV_SingleClipMoveToEntity(ent,start,mins,maxs,end,&local_44);
  }
  uVar1 = 0;
  do {
    *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar1 - 0x14)) =
         *(undefined4 *)((int)local_44.endpos + (uVar1 - 0x14));
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x38);
  return __return_storage_ptr__;
}


// SV_ClipToLinks  @ 000ab0a0
void SV_ClipToLinks(areanode_t *node,moveclip_t *clip)

{
  edict_t *ent;
  float fVar1;
  link_s *plVar2;
  link_s *plVar3;
  edict_t *peVar4;
  link_s *plVar5;
  int iVar6;
  qboolean qVar7;
  uint uVar8;
  qboolean local_c4 [4];
  float local_b4;
  edict_t *local_94;
  trace_t local_8c;
  qboolean local_54 [4];
  float local_44;
  
                    /* Unresolved local var: link_t * l@[???]
                       Unresolved local var: link_t * next@[???]
                       Unresolved local var: edict_t * touch@[???]
                       Unresolved local var: trace_t trace@[???] */
  plVar3 = (node->solid_edicts).next;
joined_r0x000ab0c7:
  while( true ) {
    plVar5 = plVar3;
    if (plVar5 == &node->solid_edicts) {
      iVar6 = node->axis;
      if (iVar6 != -1) {
        fVar1 = node->dist;
        if (fVar1 < clip->boxmaxs[iVar6]) {
          SV_ClipToLinks(node->children[0],clip);
          iVar6 = node->axis;
          fVar1 = node->dist;
        }
        if (clip->boxmins[iVar6] < fVar1) {
          SV_ClipToLinks(node->children[1],clip);
          return;
        }
      }
      return;
    }
    plVar2 = plVar5[0x57].prev;
    plVar3 = plVar5->next;
    if (((plVar2 == (link_s *)0x0) || (clip->passedict == (edict_t *)0x0)) ||
       (uVar8 = (clip->passedict->v).groupinfo, uVar8 == 0)) break;
    if (g_groupop != 0) goto LAB_000ab388;
    if (((uint)plVar2 & uVar8) != 0) break;
  }
  goto LAB_000ab110;
LAB_000ab388:
  if ((g_groupop != 1) || (((uint)plVar2 & uVar8) == 0)) {
LAB_000ab110:
    if ((plVar5[0x30].next != (link_s *)0x0) &&
       (ent = (edict_t *)(plVar5 + -1), ent != clip->passedict)) {
      if (plVar5[0x30].next == (link_s *)0x1) {
        Sys_Error("Trigger in clipping list");
      }
      if ((gNewDLLFunctions.pfnShouldCollide == (_func_int_edict_t_ptr_edict_t_ptr *)0x0) ||
         (iVar6 = (*gNewDLLFunctions.pfnShouldCollide)(ent,clip->passedict), iVar6 != 0)) {
        if (plVar5[0x30].next == (link_s *)0x4) {
          if ((((uint)plVar5[0x43].next & 0x800000) != 0) && (clip->monsterClipBrush == false))
          goto joined_r0x000ab0c7;
        }
        else if ((clip->type == 1) && (plVar5[0x30].prev != (link_s *)0xd)) goto joined_r0x000ab0c7;
        if ((((((clip->ignoretrans == 0) || (plVar5[0x38].prev == (link_s *)0x0)) ||
              (((uint)plVar5[0x43].next & 0x2000000) != 0)) &&
             ((clip->boxmins[0] <= (float)plVar5[0x29].prev &&
              (clip->boxmins[1] <= (float)plVar5[0x29].next)))) &&
            (clip->boxmins[2] <= (float)plVar5[0x2a].prev)) &&
           ((((float)plVar5[0x27].next <= clip->boxmaxs[0] &&
             ((float)plVar5[0x28].prev <= clip->boxmaxs[1])) &&
            (((float)plVar5[0x28].next <= clip->boxmaxs[2] &&
             ((plVar5[0x30].next == (link_s *)0x3 ||
              (qVar7 = SV_CheckSphereIntersection(ent,clip->start,clip->end), qVar7 != false))))))))
        {
          peVar4 = clip->passedict;
          if (peVar4 == (edict_t *)0x0) {
            if ((clip->trace).allsolid != false) {
              return;
            }
          }
          else {
            if (((peVar4->v).size[0] != 0.0) && ((float)plVar5[0x2d].next == 0.0))
            goto joined_r0x000ab0c7;
            if ((clip->trace).allsolid != false) {
              return;
            }
            if ((peVar4 == (edict_t *)plVar5[0x42].prev) || (ent == (peVar4->v).owner))
            goto joined_r0x000ab0c7;
          }
          if (((uint)plVar5[0x43].next & 0x20) == 0) {
                    /* Unresolved local var: trace_t goodtrace@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: model_t * pmodel@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int rotated@[???]
                       Unresolved local var: int idx@[???] */
            if (ent != (edict_t *)0x0) {
              SV_SingleClipMoveToEntity(ent,clip->start,clip->mins,clip->maxs,clip->end,&local_8c);
            }
            uVar8 = 0;
            do {
              *(undefined4 *)((int)local_54 + uVar8) =
                   *(undefined4 *)((int)local_8c.endpos + (uVar8 - 0x14));
              uVar8 = uVar8 + 4;
            } while (uVar8 < 0x38);
            uVar8 = 0;
            local_54[1] = local_8c.startsolid;
            local_44 = local_8c.fraction;
            local_54[0] = local_8c.allsolid;
            do {
              *(undefined4 *)((int)local_c4 + uVar8) = *(undefined4 *)((int)local_54 + uVar8);
              uVar8 = uVar8 + 4;
            } while (uVar8 < 0x38);
          }
          else {
                    /* Unresolved local var: trace_t goodtrace@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: model_t * pmodel@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int rotated@[???]
                       Unresolved local var: int idx@[???] */
            if (ent != (edict_t *)0x0) {
              SV_SingleClipMoveToEntity(ent,clip->start,clip->mins2,clip->maxs2,clip->end,&local_8c)
              ;
            }
            uVar8 = 0;
            do {
              *(undefined4 *)((int)local_c4 + uVar8) =
                   *(undefined4 *)((int)local_8c.endpos + (uVar8 - 0x14));
              uVar8 = uVar8 + 4;
            } while (uVar8 < 0x38);
          }
          if ((local_8c.allsolid != false || local_8c.startsolid != false) ||
             (local_8c.fraction < (clip->trace).fraction)) {
            local_b4 = local_8c.fraction;
            local_c4[1] = local_8c.startsolid;
            uVar8 = 0;
            local_c4[0] = local_8c.allsolid;
            local_94 = ent;
            if ((clip->trace).startsolid == false) {
              do {
                *(undefined4 *)((int)(clip->trace).endpos + (uVar8 - 0x14)) =
                     *(undefined4 *)((int)local_c4 + uVar8);
                uVar8 = uVar8 + 4;
              } while (uVar8 < 0x38);
            }
            else {
              do {
                *(undefined4 *)((int)(clip->trace).endpos + (uVar8 - 0x14)) =
                     *(undefined4 *)((int)local_c4 + uVar8);
                uVar8 = uVar8 + 4;
              } while (uVar8 < 0x38);
              (clip->trace).startsolid = true;
            }
          }
        }
      }
    }
  }
  goto joined_r0x000ab0c7;
}


// SV_ClipToWorldbrush  @ 000ab880
void SV_ClipToWorldbrush(areanode_t *node,moveclip_t *clip)

{
  edict_t *ent;
  float fVar1;
  link_s *plVar2;
  link_s *plVar3;
  int iVar4;
  uint uVar5;
  qboolean local_8c [4];
  float local_7c;
  edict_t *local_5c;
  trace_t local_54;
  
                    /* Unresolved local var: link_t * l@[???]
                       Unresolved local var: link_t * next@[???]
                       Unresolved local var: edict_t * touch@[???]
                       Unresolved local var: trace_t trace@[???] */
  plVar2 = (node->solid_edicts).next;
  while (plVar3 = plVar2, plVar3 != &node->solid_edicts) {
    plVar2 = plVar3->next;
    if ((((((plVar3[0x30].next == (link_s *)0x4) &&
           (ent = (edict_t *)(plVar3 + -1), ent != clip->passedict)) &&
          (((uint)plVar3[0x43].next & 0x2000000) != 0)) &&
         ((clip->boxmins[0] <= (float)plVar3[0x29].prev &&
          (clip->boxmins[1] <= (float)plVar3[0x29].next)))) &&
        ((clip->boxmins[2] <= (float)plVar3[0x2a].prev &&
         (((float)plVar3[0x27].next <= clip->boxmaxs[0] &&
          ((float)plVar3[0x28].prev <= clip->boxmaxs[1])))))) &&
       ((float)plVar3[0x28].next <= clip->boxmaxs[2])) {
      if ((clip->trace).allsolid != false) {
        return;
      }
                    /* Unresolved local var: trace_t goodtrace@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: model_t * pmodel@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int rotated@[???]
                       Unresolved local var: int idx@[???] */
      if (ent != (edict_t *)0x0) {
        SV_SingleClipMoveToEntity(ent,clip->start,clip->mins,clip->maxs,clip->end,&local_54);
      }
      uVar5 = 0;
      do {
        *(undefined4 *)((int)local_8c + uVar5) =
             *(undefined4 *)((int)local_54.endpos + (uVar5 - 0x14));
        uVar5 = uVar5 + 4;
      } while (uVar5 < 0x38);
      if ((local_54.startsolid != false || local_54.allsolid != false) ||
         (local_54.fraction < (clip->trace).fraction)) {
        local_7c = local_54.fraction;
        local_8c[1] = local_54.startsolid;
        uVar5 = 0;
        local_8c[0] = local_54.allsolid;
        local_5c = ent;
        if ((clip->trace).startsolid == false) {
          do {
            *(undefined4 *)((int)(clip->trace).endpos + (uVar5 - 0x14)) =
                 *(undefined4 *)((int)local_8c + uVar5);
            uVar5 = uVar5 + 4;
          } while (uVar5 < 0x38);
        }
        else {
          do {
            *(undefined4 *)((int)(clip->trace).endpos + (uVar5 - 0x14)) =
                 *(undefined4 *)((int)local_8c + uVar5);
            uVar5 = uVar5 + 4;
          } while (uVar5 < 0x38);
          (clip->trace).startsolid = true;
        }
      }
    }
  }
  iVar4 = node->axis;
  if (iVar4 != -1) {
    fVar1 = node->dist;
    if (fVar1 < clip->boxmaxs[iVar4]) {
      SV_ClipToWorldbrush(node->children[0],clip);
      iVar4 = node->axis;
      fVar1 = node->dist;
    }
    if (clip->boxmins[iVar4] < fVar1) {
      SV_ClipToWorldbrush(node->children[1],clip);
      return;
    }
  }
  return;
}


// SV_CloseEnough  @ 00097b70
qboolean SV_CloseEnough(edict_t *ent,edict_t *goal,float dist)

{
                    /* Unresolved local var: int i@[???] */
  if (((((goal->v).absmin[0] <= (ent->v).absmax[0] + dist) &&
       ((ent->v).absmin[0] - dist <= (goal->v).absmax[0])) &&
      ((goal->v).absmin[1] <= (ent->v).absmax[1] + dist)) &&
     (((ent->v).absmin[1] - dist <= (goal->v).absmax[1] &&
      ((goal->v).absmin[2] <= (ent->v).absmax[2] + dist)))) {
    return (uint)((ent->v).absmin[2] - dist <= (goal->v).absmax[2]);
  }
  return false;
}


// SV_CompareUserID  @ 00092920
qboolean SV_CompareUserID(USERID_t *id1,USERID_t *id2)

{
  qboolean qVar1;
  char *pcVar2;
  int iVar3;
  int in_GS_OFFSET;
  char local_90 [63];
  undefined1 local_51;
  char local_50 [63];
  undefined1 local_11;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  qVar1 = false;
  if ((id1 == (USERID_t *)0x0) || (id2 == (USERID_t *)0x0)) {
    qVar1 = false;
  }
  else if ((id1->idtype == id2->idtype) && (id1->idtype - 1U < 2)) {
                    /* Unresolved local var: char[64] szID1@[???]
                       Unresolved local var: char[64] szID2@[???] */
    pcVar2 = SV_GetIDString(id1);
    strncpy(local_90,pcVar2,0x3f);
    local_51 = 0;
    pcVar2 = SV_GetIDString(id2);
    strncpy(local_50,pcVar2,0x3f);
    local_11 = 0;
    iVar3 = strcasecmp(local_90,local_50);
    qVar1 = (qboolean)(iVar3 == 0);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return qVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_ComputeLatency  @ 000a23a0
void SV_ComputeLatency(client_t *cl)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  client_frame_t *pcVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: float minping@[???]
                       Unresolved local var: float maxping@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int backtrack@[???] */
  iVar9 = (int)sv_unlagsamples.value;
  if (iVar9 < 1) {
    iVar9 = 1;
  }
  iVar10 = 0x10;
  if (SV_UPDATE_BACKUP < 0x11) {
    iVar10 = SV_UPDATE_BACKUP;
  }
  if (iVar9 < iVar10) {
    iVar10 = iVar9;
  }
  if (iVar10 < 1) {
LAB_000a2690:
    fVar8 = 0.0;
    goto LAB_000a26a4;
  }
  uVar4 = (cl->netchan).incoming_acknowledged;
  pcVar5 = cl->frames;
  fVar1 = pcVar5[uVar4 & SV_UPDATE_MASK].ping_time;
  if (0.0 < fVar1) {
    fVar6 = fVar1 + 0.0;
    iVar9 = 1;
    if (iVar10 != 1) goto LAB_000a2414;
  }
  else {
    if (iVar10 == 1) goto LAB_000a2690;
    iVar9 = 0;
    fVar6 = 0.0;
LAB_000a2414:
    if (pcVar5[uVar4 - 1 & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar10 != 2) goto LAB_000a243d;
    }
    else {
      iVar9 = iVar9 + 1;
      fVar6 = pcVar5[uVar4 - 1 & SV_UPDATE_MASK].ping_time + fVar6;
      if (iVar10 == 2) goto LAB_000a26c0;
LAB_000a243d:
      if (pcVar5[uVar4 - 2 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 3) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 2 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 3) goto LAB_000a26c0;
      }
      if (pcVar5[uVar4 - 3 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 4) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 3 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 4) goto LAB_000a26c0;
      }
      if (pcVar5[uVar4 - 4 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 5) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 4 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 5) goto LAB_000a26c0;
      }
      if (pcVar5[uVar4 - 5 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 6) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 5 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 6) goto LAB_000a26c0;
      }
      if (pcVar5[uVar4 - 6 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 7) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 6 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 7) goto LAB_000a26c0;
      }
      if (pcVar5[uVar4 - 7 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 8) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 7 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 8) goto LAB_000a26c0;
      }
      if (pcVar5[uVar4 - 8 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 9) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 8 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 9) goto LAB_000a26c0;
      }
      if (pcVar5[uVar4 - 9 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 10) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 9 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 10) goto LAB_000a26c0;
      }
      if (pcVar5[uVar4 - 10 & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 0xb) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 10 & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 0xb) goto LAB_000a26c0;
      }
      if (pcVar5[uVar4 - 0xb & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 0xc) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 0xb & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 0xc) goto LAB_000a26c0;
      }
      if (pcVar5[uVar4 - 0xc & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 0xd) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 0xc & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 0xd) goto LAB_000a26c0;
      }
      if (pcVar5[uVar4 - 0xd & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar10 == 0xe) goto LAB_000a2680;
      }
      else {
        iVar9 = iVar9 + 1;
        fVar6 = pcVar5[uVar4 - 0xd & SV_UPDATE_MASK].ping_time + fVar6;
        if (iVar10 == 0xe) goto LAB_000a26c0;
      }
      if (0.0 < pcVar5[uVar4 - 0xe & SV_UPDATE_MASK].ping_time) {
        fVar6 = pcVar5[uVar4 - 0xe & SV_UPDATE_MASK].ping_time + fVar6;
        iVar9 = iVar9 + 1;
      }
      if ((iVar10 == 0x10) && (0.0 < pcVar5[uVar4 - 0xf & SV_UPDATE_MASK].ping_time)) {
        fVar6 = pcVar5[uVar4 - 0xf & SV_UPDATE_MASK].ping_time + fVar6;
        iVar9 = iVar9 + 1;
      }
    }
LAB_000a2680:
    if (iVar9 == 0) goto LAB_000a2690;
  }
LAB_000a26c0:
  iVar10 = SV_UPDATE_BACKUP;
  if (4 < SV_UPDATE_BACKUP) {
    iVar10 = 4;
  }
  fVar6 = fVar6 / (float)iVar9;
  fVar8 = fVar6;
  if (iVar10 < 1) goto LAB_000a26a4;
  fVar7 = 9999.0;
  if (fVar1 <= 0.0) {
    if (iVar10 == 1) goto LAB_000a26a4;
    fVar1 = -9999.0;
LAB_000a2712:
    fVar2 = pcVar5[uVar4 - 1 & SV_UPDATE_MASK].ping_time;
    fVar3 = fVar1;
    if (0.0 < fVar2) {
      if (fVar2 < fVar7) {
        fVar7 = fVar2;
      }
      fVar3 = fVar2;
      if (fVar2 <= fVar1) {
        fVar3 = fVar1;
      }
    }
    fVar1 = fVar3;
    if (iVar10 != 2) {
      fVar1 = pcVar5[uVar4 - 2 & SV_UPDATE_MASK].ping_time;
      fVar2 = fVar3;
      if (0.0 < fVar1) {
        if (fVar1 < fVar7) {
          fVar7 = fVar1;
        }
        fVar2 = fVar1;
        if (fVar1 <= fVar3) {
          fVar2 = fVar3;
        }
      }
      fVar1 = fVar2;
      if ((iVar10 == 4) && (fVar3 = pcVar5[SV_UPDATE_MASK & uVar4 - 3].ping_time, 0.0 < fVar3)) {
        if (fVar3 < fVar7) {
          fVar7 = fVar3;
        }
        fVar1 = fVar3;
        if (fVar3 <= fVar2) {
          fVar1 = fVar2;
        }
      }
    }
  }
  else {
    if (fVar1 < 9999.0) {
      fVar7 = fVar1;
    }
    if (fVar1 <= -9999.0) {
      fVar1 = -9999.0;
    }
    if (iVar10 != 1) goto LAB_000a2712;
  }
  if ((fVar7 <= fVar1) && (fVar8 = 0.0, ABS(fVar1 - fVar7) <= 0.2)) {
    fVar8 = fVar6;
  }
LAB_000a26a4:
  cl->latency = fVar8;
  return;
}


// SV_ConnectClient  @ 00093140
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ConnectClient(void)

{
  resource_t *prVar1;
  netadr_t adr;
  netadr_t a;
  netadr_t a_00;
  netadr_t a_01;
  netadr_t a_02;
  netadr_t a_03;
  netadr_t a_04;
  netadr_t a_05;
  netadr_t a_06;
  netadr_t adr_00;
  netadr_t adr_01;
  netadr_t b;
  double dVar2;
  ushort uVar3;
  int iVar4;
  char *pcVar5;
  qboolean qVar6;
  char *pcVar7;
  uint uVar8;
  client_frame_t *pcVar9;
  edict_t *peVar10;
  qboolean qVar11;
  uint32_t uVar12;
  client_t *pcVar13;
  client_t **ppClient;
  int iVar14;
  netadr_t *pnVar15;
  netadrtype_t *pnVar16;
  int in_GS_OFFSET;
  byte bVar17;
  usercmd_t *dest;
  client_t *pcVar18;
  uchar auVar19 [4];
  netadrtype_t nVar20;
  netadrtype_t nVar21;
  netadrtype_t nVar22;
  undefined4 uVar23;
  char *userinfo;
  undefined4 uVar24;
  netadrtype_t nVar25;
  uchar cdkey [4];
  char *pcVar26;
  code *pfnNetchan_Blocksize;
  ushort local_ea2;
  client_t *local_ea0;
  int local_e9c;
  netadrtype_t local_e98;
  netadr_t local_e94;
  char local_e80 [32];
  char local_e60 [64];
  client_t *local_e20 [128];
  char local_c20 [1023];
  undefined1 local_821;
  char local_820 [1023];
  undefined1 local_421;
  undefined1 local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: netadr_t adr@[???]
                       Unresolved local var: int edictnum@[???]
                       Unresolved local var: int nClientSlot@[???]
                       Unresolved local var: char[1024] userinfo@[???]
                       Unresolved local var: char[1024] protinfo@[???]
                       Unresolved local var: char[64] cdkey@[???]
                       Unresolved local var: char * s@[???]
                       Unresolved local var: char[32] name@[???]
                       Unresolved local var: char[512] szRawCertificate@[???]
                       Unresolved local var: int nAuthProtocol@[???]
                       Unresolved local var: ushort port@[???]
                       Unresolved local var: qboolean reconnect@[???]
                       Unresolved local var: qboolean bIsSecure@[???] */
  bVar17 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_e98 = ~NA_UNUSED;
  local_ea0 = (client_t *)0x0;
  local_e94.type = net_from.type;
  local_e94.ip = net_from.ip;
  local_e94.ipx._0_4_ = net_from.ipx._0_4_;
  local_e94.ipx._4_4_ = net_from.ipx._4_4_;
  local_e94._16_4_ = net_from._16_4_;
  iVar4 = Q_atoi("27005");
  local_ea2 = (ushort)iVar4;
  iVar4 = Cmd_Argc();
  if (iVar4 < 5) {
    SV_RejectConnection(&local_e94,"Insufficient connection info\n");
    goto LAB_000931c5;
  }
  pcVar5 = Cmd_Argv(1);
  iVar4 = Q_atoi(pcVar5);
  if (iVar4 != 0x30) {
    if (iVar4 < 0x31) {
      SV_RejectConnection(&local_e94,
                          "This server is using a newer protocol ( %i ) than your client ( %i ).  You should check for updates to your client.\n"
                         );
    }
    else {
      Q_strlen(sv_contact.string);
      SV_RejectConnection(&local_e94,
                          "This server is using an older protocol ( %i ) than your client ( %i ).  If you believe this server is outdated, you can contact the server administrator at %s.\n"
                         );
    }
    goto LAB_000931c5;
  }
                    /* Unresolved local var: int i@[???] */
  iVar14 = 0;
  pcVar5 = Cmd_Argv(2);
  iVar4 = Q_atoi(pcVar5);
  adr.ip[0] = local_e94.ip[0];
  adr.ip[1] = local_e94.ip[1];
  adr.ip[2] = local_e94.ip[2];
  adr.ip[3] = local_e94.ip[3];
  adr.type = local_e94.type;
  adr.ipx[0] = local_e94.ipx[0];
  adr.ipx[1] = local_e94.ipx[1];
  adr.ipx[2] = local_e94.ipx[2];
  adr.ipx[3] = local_e94.ipx[3];
  adr.ipx[4] = local_e94.ipx[4];
  adr.ipx[5] = local_e94.ipx[5];
  adr.ipx[6] = local_e94.ipx[6];
  adr.ipx[7] = local_e94.ipx[7];
  adr.ipx[8] = local_e94.ipx[8];
  adr.ipx[9] = local_e94.ipx[9];
  adr.port = local_e94.port;
  qVar6 = NET_IsLocalAddress(adr);
  if (qVar6 == false) {
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
      qVar6 = NET_CompareBaseAdr(a,g_rg_sv_challenges[iVar14].adr);
      if (qVar6 != false) {
        if (iVar4 == g_rg_sv_challenges[iVar14].challenge) goto LAB_00093351;
        SV_RejectConnection(&local_e94,"Bad challenge.\n");
        goto LAB_000931c5;
      }
                    /* Unresolved local var: int i@[???] */
      iVar14 = iVar14 + 1;
    } while (iVar14 != 0x400);
    SV_RejectConnection(&local_e94,"No challenge for your address.\n");
    goto LAB_000931c5;
  }
LAB_00093351:
  ppClient = local_e20;
  Q_memset(ppClient,0,0x200);
  pcVar5 = Cmd_Argv(3);
  iVar4 = Info_IsValid(pcVar5);
  if (iVar4 == 0) {
    SV_RejectConnection(&local_e94,"Invalid protinfo in connect command\n");
    goto LAB_000931c5;
  }
  Q_strncpy(local_820,pcVar5,0x3ff);
  local_421 = 0;
  cdkey = (uchar  [4])local_e60;
  nVar25 = 0x200;
  iVar4 = SV_CheckKeyInfo(&local_e94,local_820,&local_ea2,(int *)&local_e98,(char *)ppClient,0x200,
                          (char *)cdkey);
  if (iVar4 == 0) goto LAB_000931c5;
  if (((sv_lan.value != 0.0) || (local_e98 != NA_IP)) && (local_e98 != NA_BROADCAST)) {
    if (sv_lan.value == 0.0) {
LAB_00093462:
      SV_RejectConnection(&local_e94,"LAN servers are restricted to local clients (class C).\n");
      goto LAB_000931c5;
    }
    a_00.ip[0] = local_e94.ip[0];
    a_00.ip[1] = local_e94.ip[1];
    a_00.ip[2] = local_e94.ip[2];
    a_00.ip[3] = local_e94.ip[3];
    a_00.type = local_e94.type;
    a_00.ipx[0] = local_e94.ipx[0];
    a_00.ipx[1] = local_e94.ipx[1];
    a_00.ipx[2] = local_e94.ipx[2];
    a_00.ipx[3] = local_e94.ipx[3];
    a_00.ipx[4] = local_e94.ipx[4];
    a_00.ipx[5] = local_e94.ipx[5];
    a_00.ipx[6] = local_e94.ipx[6];
    a_00.ipx[7] = local_e94.ipx[7];
    a_00.ipx[8] = local_e94.ipx[8];
    a_00.ipx[9] = local_e94.ipx[9];
    a_00.port = local_e94.port;
    b.ip[0] = net_local_adr.ip[0];
    b.ip[1] = net_local_adr.ip[1];
    b.ip[2] = net_local_adr.ip[2];
    b.ip[3] = net_local_adr.ip[3];
    b.type = net_local_adr.type;
    b.ipx[0] = net_local_adr.ipx[0];
    b.ipx[1] = net_local_adr.ipx[1];
    b.ipx[2] = net_local_adr.ipx[2];
    b.ipx[3] = net_local_adr.ipx[3];
    b.ipx[4] = net_local_adr.ipx[4];
    b.ipx[5] = net_local_adr.ipx[5];
    b.ipx[6] = net_local_adr.ipx[6];
    b.ipx[7] = net_local_adr.ipx[7];
    b.ipx[8] = net_local_adr.ipx[8];
    b.ipx[9] = net_local_adr.ipx[9];
    b.port = net_local_adr.port;
    nVar22 = local_e94.type;
    auVar19 = local_e94.ip;
    nVar20 = local_e94.ipx._0_4_;
    uVar23 = local_e94.ipx._4_4_;
    uVar24 = local_e94._16_4_;
    nVar25 = net_local_adr.type;
    cdkey = net_local_adr.ip;
    qVar6 = NET_CompareClassBAdr(a_00,b);
    if (qVar6 == false) {
      pnVar15 = &local_e94;
      pnVar16 = (netadrtype_t *)&stack0xfffff114;
      for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pnVar16 = pnVar15->type;
        pnVar15 = (netadr_t *)((int)pnVar15 + (uint)bVar17 * -8 + 4);
        pnVar16 = pnVar16 + (uint)bVar17 * -2 + 1;
      }
      a_01.ip[0] = auVar19[0];
      a_01.ip[1] = auVar19[1];
      a_01.ip[2] = auVar19[2];
      a_01.ip[3] = auVar19[3];
      a_01.type = nVar22;
      a_01.ipx[0] = (char)nVar20;
      a_01.ipx[1] = (char)(nVar20 >> 8);
      a_01.ipx[2] = (char)(nVar20 >> 0x10);
      a_01.ipx[3] = (char)(nVar20 >> 0x18);
      a_01.ipx[4] = (uchar)uVar23;
      a_01.ipx[5] = SUB41(uVar23,1);
      a_01.ipx[6] = SUB41(uVar23,2);
      a_01.ipx[7] = SUB41(uVar23,3);
      a_01.ipx[8] = (uchar)uVar24;
      a_01.ipx[9] = SUB41(uVar24,1);
      a_01.port = SUB42(uVar24,2);
      qVar6 = NET_IsReservedAdr(a_01);
      if (qVar6 == false) goto LAB_00093462;
    }
  }
  pcVar5 = Cmd_Argv(4);
  iVar4 = Q_strlen(pcVar5);
  if ((iVar4 < 0x101) && (iVar4 = Info_IsValid(pcVar5), iVar4 != 0)) {
    Q_strncpy(local_c20,pcVar5,0x3ff);
    local_821 = 0;
    qVar6 = Master_IsLanGame();
    if (((qVar6 != false) || (local_e98 - NA_BROADCAST < 2)) && (local_e9c = 0, 0 < svs.maxclients))
    {
      do {
        local_ea0 = svs.clients + local_e9c;
        pnVar15 = &(local_ea0->netchan).remote_address;
        nVar25 = pnVar15->type;
        cdkey = *&(local_ea0->netchan).remote_address.ip;
        a_02.ip[0] = local_e94.ip[0];
        a_02.ip[1] = local_e94.ip[1];
        a_02.ip[2] = local_e94.ip[2];
        a_02.ip[3] = local_e94.ip[3];
        a_02.type = local_e94.type;
        a_02.ipx[0] = local_e94.ipx[0];
        a_02.ipx[1] = local_e94.ipx[1];
        a_02.ipx[2] = local_e94.ipx[2];
        a_02.ipx[3] = local_e94.ipx[3];
        a_02.ipx[4] = local_e94.ipx[4];
        a_02.ipx[5] = local_e94.ipx[5];
        a_02.ipx[6] = local_e94.ipx[6];
        a_02.ipx[7] = local_e94.ipx[7];
        a_02.ipx[8] = local_e94.ipx[8];
        a_02.ipx[9] = local_e94.ipx[9];
        a_02.port = local_e94.port;
        qVar6 = NET_CompareAdr(a_02,*pnVar15);
        if (qVar6 != false) {
          qVar6 = true;
          goto LAB_00093598;
        }
        local_e9c = local_e9c + 1;
      } while (local_e9c < svs.maxclients);
    }
    qVar6 = false;
LAB_00093598:
    pcVar5 = local_e80;
    iVar4 = SV_CheckUserInfo(&local_e94,local_c20,qVar6,local_e9c,pcVar5);
    if (iVar4 != 0) {
      userinfo = local_c20;
      nVar22 = local_e98;
      iVar4 = SV_FinishCertificateCheck(&local_e94,local_e98,(char *)ppClient,userinfo);
      if (iVar4 != 0) {
        if (qVar6 == false) {
          ppClient = &local_ea0;
          iVar4 = SV_FindEmptySlot(&local_e94,&local_e9c,ppClient);
          if (iVar4 == 0) goto LAB_000931c5;
        }
        else {
          pcVar13 = local_ea0;
          Steam_NotifyClientDisconnect((client_t_conflict *)local_ea0);
          if (((local_ea0->active != false) || (local_ea0->spawned != false)) &&
             (pcVar18 = (client_t *)local_ea0->edict, pcVar18 != (client_t *)0x0)) {
            (*gEntityInterface.pfnClientDisconnect)((edict_t *)pcVar18);
            pcVar13 = pcVar18;
          }
          pnVar15 = &local_e94;
          pnVar16 = (netadrtype_t *)&stack0xfffff114;
          for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
            *pnVar16 = pnVar15->type;
            pnVar15 = (netadr_t *)((int)pnVar15 + (uint)bVar17 * -8 + 4);
            pnVar16 = pnVar16 + (uint)bVar17 * -2 + 1;
          }
          a_06.ip[0] = (char)nVar22;
          a_06.ip[1] = (char)(nVar22 >> 8);
          a_06.ip[2] = (char)(nVar22 >> 0x10);
          a_06.ip[3] = (char)(nVar22 >> 0x18);
          a_06.type = (netadrtype_t)pcVar13;
          a_06.ipx._0_4_ = ppClient;
          a_06.ipx._4_4_ = userinfo;
          a_06._16_4_ = pcVar5;
          NET_AdrToString(a_06);
          Con_Printf("%s:reconnect\n");
        }
        iVar4 = SV_CheckIPConnectionReuse(&local_e94);
        pcVar13 = local_ea0;
        if (iVar4 != 0) {
          iVar4 = g_userid + 1;
          local_ea0->userid = g_userid;
          host_client = local_ea0;
          g_userid = iVar4;
          if (local_e98 == NA_IP) {
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: char[1024] szSteamAuthBuf@[???] */
            userinfo = (char *)0x400;
            ppClient = (client_t **)(net_message.cursize - msg_readcount);
            if (0x3fe < (int)ppClient - 1U) {
              SV_RejectConnection(&local_e94,"STEAM certificate length error! %i/%i\n");
              goto LAB_000931c5;
            }
            __memcpy_chk();
            uVar8 = NET_NetAdr_GetIPNetworkByteOrder((netadr_t_conflict *)&local_e94);
            (pcVar13->network_userid).clientip = uVar8;
            pcVar13 = host_client;
            if (local_e94.type == NA_LOOPBACK) {
              if (sv_lan.value <= 0.0) {
                uVar8 = NET_NetAdr_GetIPNetworkByteOrder((netadr_t_conflict *)&net_local_adr);
                (pcVar13->network_userid).clientip = uVar8;
              }
              else {
                uVar12 = htonl(0x7f000001);
                (pcVar13->network_userid).clientip = uVar12;
              }
            }
            uVar3 = local_e94.port;
            if (local_e94.port == 0) {
              uVar3 = local_ea2;
            }
            (host_client->netchan).remote_address.port = uVar3;
            qVar11 = Steam_NotifyClientConnect
                               ((client_t_conflict *)local_ea0,local_420,(uint)ppClient);
            pcVar13 = host_client;
            if (qVar11 == 0) {
              if (sv_lan.value == 0.0) {
                SV_RejectConnection(&local_e94,"STEAM validation rejected\n");
                goto LAB_000931c5;
              }
              (host_client->network_userid).idtype = 1;
              *(undefined4 *)&(pcVar13->network_userid).m_SteamID = 0;
              *(undefined4 *)((int)&(pcVar13->network_userid).m_SteamID + 4) = 0;
            }
          }
          else {
            if (local_e98 != NA_BROADCAST) {
              SV_RejectConnection(&local_e94,"Invalid authentication type\n");
              goto LAB_000931c5;
            }
                    /* Unresolved local var: char * val@[???] */
            pcVar7 = Info_ValueForKey(local_c20,"*hltv");
            iVar4 = Q_strlen(pcVar7);
                    /* Unresolved local var: int i@[???] */
            if ((iVar4 == 0) || (iVar4 = Q_atoi(pcVar7), pcVar13 = host_client, iVar4 != 1)) {
              SV_RejectConnection(&local_e94,"Invalid validation type\n");
              goto LAB_000931c5;
            }
            (host_client->network_userid).idtype = 3;
            *(undefined4 *)&(pcVar13->network_userid).m_SteamID = 0;
            *(undefined4 *)((int)&(pcVar13->network_userid).m_SteamID + 4) = 0;
            uVar8 = NET_NetAdr_GetIPNetworkByteOrder((netadr_t_conflict *)&local_e94);
            (pcVar13->network_userid).clientip = uVar8;
            Steam_NotifyBotConnect((client_t_conflict *)local_ea0);
            pcVar13 = host_client;
          }
          SV_ClearResourceLists(pcVar13);
          SV_ClearFrames(&host_client->frames);
          pcVar13 = host_client;
          pcVar9 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0x1870);
          pcVar13->frames = pcVar9;
          pcVar13 = host_client;
          prVar1 = &host_client->resourcesneeded;
          (host_client->resourcesneeded).pPrev = prVar1;
          (pcVar13->resourcesneeded).pNext = prVar1;
          (pcVar13->resourcesonhand).pPrev = &pcVar13->resourcesonhand;
          (pcVar13->resourcesonhand).pNext = &pcVar13->resourcesonhand;
          peVar10 = EDICT_NUM(local_e9c + 1);
          pcVar13 = host_client;
          host_client->edict = peVar10;
          if (g_modfuncs.m_pfnConnectClient != (PFN_CONNECTCLIENT)0x0) {
            (*g_modfuncs.m_pfnConnectClient)(local_e9c);
            pcVar13 = host_client;
          }
          pfnNetchan_Blocksize = SV_GetFragmentSize;
          iVar4 = ((int)local_ea0 - (int)svs.clients >> 3) * 0x4ffec005;
          pnVar15 = &local_e94;
          pnVar16 = (netadrtype_t *)&stack0xfffff11c;
          pcVar18 = local_ea0;
          for (iVar14 = 5; iVar14 != 0; iVar14 = iVar14 + -1) {
            *pnVar16 = pnVar15->type;
            pnVar15 = (netadr_t *)((int)pnVar15 + (uint)bVar17 * -8 + 4);
            pnVar16 = pnVar16 + (uint)bVar17 * -2 + 1;
          }
          adr_01.ip = (uchar  [4])userinfo;
          adr_01.type = (netadrtype_t)ppClient;
          adr_01.ipx._0_4_ = pcVar5;
          adr_01.ipx[4] = (char)nVar25;
          adr_01.ipx[5] = (char)(nVar25 >> 8);
          adr_01.ipx[6] = (char)(nVar25 >> 0x10);
          adr_01.ipx[7] = (char)(nVar25 >> 0x18);
          adr_01._16_4_ = cdkey;
          Netchan_Setup(NS_SERVER,&pcVar13->netchan,adr_01,iVar4,pcVar18,pfnNetchan_Blocksize);
          pcVar13 = host_client;
          *(undefined4 *)&host_client->next_messageinterval = 0x9999999a;
          dest = &pcVar13->lastcmd;
          dVar2 = realtime + 0.05;
          *(undefined4 *)((int)&pcVar13->next_messageinterval + 4) = 0x3fa99999;
          pcVar13->delta_sequence = -1;
          pcVar13->next_messagetime = dVar2;
          nVar21 = 0x34;
          nVar20 = NA_UNUSED;
          Q_memset(dest,0,0x34);
          pcVar13 = host_client;
          nVar22 = (host_client->netchan).remote_address.type;
          *(undefined4 *)&host_client->nextping = 0;
          *(undefined4 *)((int)&pcVar13->nextping + 4) = 0xbff00000;
          if (nVar22 == NA_LOOPBACK) {
            Con_DPrintf("Local connection.\n");
          }
          else {
            pnVar15 = &(pcVar13->netchan).remote_address;
            pnVar16 = (netadrtype_t *)&stack0xfffff114;
            for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
              *pnVar16 = pnVar15->type;
              pnVar15 = (netadr_t *)((int)pnVar15 + (uint)bVar17 * -8 + 4);
              pnVar16 = pnVar16 + (uint)bVar17 * -2 + 1;
            }
            a_03.ip[0] = (char)nVar20;
            a_03.ip[1] = (char)(nVar20 >> 8);
            a_03.ip[2] = (char)(nVar20 >> 0x10);
            a_03.ip[3] = (char)(nVar20 >> 0x18);
            a_03.type = (netadrtype_t)dest;
            a_03.ipx[0] = (char)nVar21;
            a_03.ipx[1] = (char)(nVar21 >> 8);
            a_03.ipx[2] = (char)(nVar21 >> 0x10);
            a_03.ipx[3] = (char)(nVar21 >> 0x18);
            a_03.ipx._4_4_ = userinfo;
            a_03._16_4_ = pcVar5;
            NET_AdrToString(a_03);
            Con_DPrintf("Client %s connected\nAdr: %s\n");
          }
          pcVar7 = local_e60;
          nVar22 = 0x20;
          pcVar26 = host_client->hashedcdkey;
          Q_strncpy(pcVar26,pcVar7,0x20);
          pcVar13 = host_client;
          host_client->active = false;
          pcVar13->hashedcdkey[0x20] = '\0';
          pcVar13 = host_client;
          host_client->spawned = false;
          pcVar13->connected = true;
          pcVar13->uploading = false;
          pcVar13->fully_connected = false;
          Steam_GSBSecure();
          build_number();
          pnVar15 = &(host_client->netchan).remote_address;
          pnVar16 = (netadrtype_t *)&stack0xfffff114;
          for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
            *pnVar16 = pnVar15->type;
            pnVar15 = (netadr_t *)((int)pnVar15 + (uint)bVar17 * -8 + 4);
            pnVar16 = pnVar16 + (uint)bVar17 * -2 + 1;
          }
          a_04.ip = (uchar  [4])pcVar7;
          a_04.type = (netadrtype_t)pcVar26;
          a_04.ipx[0] = (char)nVar22;
          a_04.ipx[1] = (char)(nVar22 >> 8);
          a_04.ipx[2] = (char)(nVar22 >> 0x10);
          a_04.ipx[3] = (char)(nVar22 >> 0x18);
          a_04.ipx._4_4_ = userinfo;
          a_04._16_4_ = pcVar5;
          NET_AdrToString(a_04);
          pcVar26 = "%c %i \"%s\" %i %i";
          pnVar15 = &local_e94;
          pnVar16 = (netadrtype_t *)&stack0xfffff118;
          for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
            *pnVar16 = pnVar15->type;
            pnVar15 = (netadr_t *)((int)pnVar15 + (uint)bVar17 * -8 + 4);
            pnVar16 = pnVar16 + (uint)bVar17 * -2 + 1;
          }
          nVar20 = NA_LOOPBACK;
          adr_00.ip[0] = (char)nVar22;
          adr_00.ip[1] = (char)(nVar22 >> 8);
          adr_00.ip[2] = (char)(nVar22 >> 0x10);
          adr_00.ip[3] = (char)(nVar22 >> 0x18);
          adr_00.type = (netadrtype_t)pcVar7;
          adr_00.ipx._0_4_ = userinfo;
          adr_00.ipx._4_4_ = pcVar5;
          adr_00.ipx[8] = (char)nVar25;
          adr_00.ipx[9] = (char)(nVar25 >> 8);
          adr_00.port = (short)(nVar25 >> 0x10);
          Netchan_OutOfBandPrint(NS_SERVER,adr_00,pcVar26);
          pnVar15 = &(host_client->netchan).remote_address;
          pnVar16 = (netadrtype_t *)&stack0xfffff114;
          for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
            *pnVar16 = pnVar15->type;
            pnVar15 = (netadr_t *)((int)pnVar15 + (uint)bVar17 * -8 + 4);
            pnVar16 = pnVar16 + (uint)bVar17 * -2 + 1;
          }
          a_05.ip = (uchar  [4])pcVar7;
          a_05.type = nVar20;
          a_05.ipx[0] = (char)nVar22;
          a_05.ipx[1] = (char)(nVar22 >> 8);
          a_05.ipx[2] = (char)(nVar22 >> 0x10);
          a_05.ipx[3] = (char)(nVar22 >> 0x18);
          a_05.ipx._4_4_ = userinfo;
          a_05._16_4_ = pcVar5;
          NET_AdrToString(a_05);
          SV_GetClientIDString(host_client);
          Log_Printf("\"%s<%i><%s><>\" connected, address \"%s\"\n");
          Q_strncpy(host_client->userinfo,local_c20,0x100);
          pcVar13 = host_client;
          host_client->userinfo[0xff] = '\0';
          SV_ExtractFromUserinfo(pcVar13);
          pcVar5 = va("%lld");
          Info_SetValueForStarKey(host_client->userinfo,"*sid",pcVar5,0x100);
          pcVar13 = host_client;
          (host_client->datagram).data = host_client->datagram_buf;
          (pcVar13->datagram).flags = 1;
          (pcVar13->datagram).maxsize = 6000;
          (pcVar13->datagram).buffername = pcVar13->name;
          pcVar13->sendinfo_time = 0.0;
        }
      }
    }
  }
  else {
    SV_RejectConnection(&local_e94,"Invalid userinfo in connect command\n");
  }
LAB_000931c5:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_ConnectionlessPacket  @ 00093c80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ConnectionlessPacket(void)

{
  char cVar1;
  netadr_t a;
  netadr_t to;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int in_GS_OFFSET;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char * args@[???]
                       Unresolved local var: char * s@[???]
                       Unresolved local var: char * c@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  MSG_BeginReading();
  MSG_ReadLong();
  pcVar3 = MSG_ReadStringLine();
  Cmd_TokenizeString(pcVar3);
  pcVar4 = Cmd_Argv(0);
  iVar5 = Q_strcmp(pcVar4,"ping");
  if (iVar5 == 0) {
LAB_00093d30:
                    /* Unresolved local var: char[6] data@[???] */
    local_16 = 0xff;
    local_15 = 0xff;
    local_14 = 0xff;
    local_13 = 0xff;
    local_12 = 0x6a;
    local_11 = 0;
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
    NET_SendPacket(NS_SERVER,6,&local_16,to);
  }
  else {
    cVar1 = *pcVar4;
    if (cVar1 == 'i') {
      if ((pcVar4[1] == '\0') || (pcVar4[1] == '\n')) goto LAB_00093d30;
    }
    else if (cVar1 == 'j') {
      if ((pcVar4[1] == '\0') || (pcVar4[1] == '\n')) {
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
        pcVar4 = NET_AdrToString(a);
        Con_Printf("A2A_ACK from %s\n",pcVar4);
        goto LAB_00093cf8;
      }
    }
    else {
      bVar2 = true;
      if ((byte)(cVar1 + 0xb1U) < 9) {
        bVar2 = (bool)((byte)(0x1e9 >> (cVar1 + 0xb1U & 0x1f)) & 1 ^ 1);
      }
      if (bVar2 <= (cVar1 == 's')) goto LAB_00093cf8;
    }
    iVar5 = Q_stricmp(pcVar4,"log");
    if (iVar5 == 0) {
      if (((sv_logrelay.value != 0.0) && (pcVar3 != (char *)0x0)) &&
         (iVar5 = Q_strlen(pcVar3), 4 < iVar5)) {
        iVar5 = Q_strlen("log ");
        pcVar3 = pcVar3 + iVar5;
        if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
          Con_Printf("%s\n",pcVar3);
        }
      }
    }
    else {
      iVar5 = Q_strcmp(pcVar4,"getchallenge");
      if (iVar5 == 0) {
        SVC_GetChallenge();
      }
      else {
        iVar5 = Q_stricmp(pcVar4,"challenge");
        if (iVar5 == 0) {
          SVC_ServiceChallenge();
        }
        else {
          iVar5 = Q_strcmp(pcVar4,"connect");
          if (iVar5 == 0) {
            SV_ConnectClient();
          }
          else {
            iVar5 = Q_strcmp(pcVar4,"pstat");
            if (iVar5 == 0) {
              if (g_modfuncs.m_pfnPlayerStatus != (PFN_PLAYERSTATUS)0x0) {
                (*g_modfuncs.m_pfnPlayerStatus)(net_message.data,net_message.cursize);
              }
            }
            else {
              iVar5 = Q_strcmp(pcVar4,"rcon");
              if (iVar5 == 0) {
                SV_Rcon(&net_from);
              }
              else {
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int maxsize@[???]
                       Unresolved local var: byte[2048] data@[???]
                       Unresolved local var: int valid@[???] */
                if ((sv.active != false) && (1 < svs.maxclients)) {
                  SVC_GameDllQuery(pcVar3);
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00093cf8:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_ConvertPMTrace  @ 000a1c00
void SV_ConvertPMTrace(trace_t *dest,pmtrace_t *src,edict_t *ent)

{
  dest->allsolid = src->allsolid;
  dest->startsolid = src->startsolid;
  dest->inopen = src->inopen;
  dest->inwater = src->inwater;
  dest->fraction = src->fraction;
  dest->endpos[0] = src->endpos[0];
  dest->endpos[1] = src->endpos[1];
  dest->endpos[2] = src->endpos[2];
  (dest->plane).normal[0] = (src->plane).normal[0];
  (dest->plane).normal[1] = (src->plane).normal[1];
  (dest->plane).normal[2] = (src->plane).normal[2];
  (dest->plane).dist = (src->plane).dist;
  dest->hitgroup = src->hitgroup;
  dest->ent = ent;
  return;
}


// SV_CopyEdictToPhysent  @ 000a09f0
void SV_CopyEdictToPhysent(physent_t *pe,int e,edict_t *check)

{
  vec_t vVar1;
  string_t sVar2;
  model_s *pmVar3;
  int iVar4;
  
  pe->info = e;
  pe->origin[0] = (check->v).origin[0];
  pe->origin[1] = (check->v).origin[1];
  pe->origin[2] = (check->v).origin[2];
  if ((e < 1) || (svs.maxclients < e)) {
    pe->player = 0;
  }
  else {
    if (((((host_client->lw != 0) && (host_client->lc != 0)) && (sv_unlag.value != 0.0)) &&
        ((1 < svs.maxclients && (iVar4 = e + -1, iVar4 < svs.maxclients && -1 < iVar4)))) &&
       ((host_client->active != false &&
        ((truepositions[iVar4].active != 0 && (truepositions[iVar4].needrelink != 0)))))) {
      pe->origin[0] = truepositions[iVar4].oldorg[0];
      pe->origin[1] = truepositions[iVar4].oldorg[1];
      pe->origin[2] = truepositions[iVar4].oldorg[2];
    }
    pe->player = e;
  }
  pe->angles[0] = (check->v).angles[0];
  pe->angles[1] = (check->v).angles[1];
  vVar1 = (check->v).angles[2];
  pe->studiomodel = (model_s *)0x0;
  pe->angles[2] = vVar1;
  pe->rendermode = (check->v).rendermode;
  iVar4 = (check->v).solid;
  if (iVar4 == 4) {
    iVar4 = (check->v).modelindex;
  }
  else {
    if (iVar4 != 0) {
                    /* Unresolved local var: model_t * pModel@[???] */
      pe->model = (model_s *)0x0;
      if (iVar4 == 2) {
        iVar4 = (check->v).modelindex;
        if ((iVar4 != 0) && (pmVar3 = sv.models[iVar4], pmVar3 != (model_s *)0x0)) {
          if ((pmVar3->flags & 0x200) != 0) {
            pe->studiomodel = pmVar3;
          }
          Q_strncpy(pe->name,pmVar3->name,0x20);
          pe->name[0x1f] = '\0';
        }
        pe->mins[0] = (check->v).mins[0];
        pe->mins[1] = (check->v).mins[1];
        pe->mins[2] = (check->v).mins[2];
        pe->maxs[0] = (check->v).maxs[0];
        pe->maxs[1] = (check->v).maxs[1];
        pe->maxs[2] = (check->v).maxs[2];
      }
      else {
        pe->mins[0] = (check->v).mins[0];
        pe->mins[1] = (check->v).mins[1];
        pe->mins[2] = (check->v).mins[2];
        pe->maxs[0] = (check->v).maxs[0];
        pe->maxs[1] = (check->v).maxs[1];
        pe->maxs[2] = (check->v).maxs[2];
        sVar2 = (check->v).classname;
        if (sVar2 == 0) {
          pe->name[0] = '?';
          pe->name[1] = '\0';
        }
        else {
          Q_strncpy(pe->name,pr_strings + sVar2,0x20);
        }
        pe->name[0x1f] = '\0';
      }
      goto LAB_000a0aa8;
    }
    iVar4 = (check->v).modelindex;
    if (iVar4 == 0) {
      pe->model = (model_s *)0x0;
      goto LAB_000a0aa8;
    }
  }
  pmVar3 = sv.models[iVar4];
  pe->model = pmVar3;
  Q_strncpy(pe->name,pmVar3->name,0x20);
  pe->name[0x1f] = '\0';
LAB_000a0aa8:
  pe->solid = (check->v).solid;
  pe->skin = (check->v).skin;
  pe->frame = (check->v).frame;
  pe->sequence = (check->v).sequence;
  Q_memcpy(pe->controller,(check->v).controller,4);
  Q_memcpy(pe->blending,(check->v).blending,2);
  iVar4 = (check->v).movetype;
  pe->blooddecal = 0;
  pe->takedamage = 0;
  pe->movetype = iVar4;
  pe->iuser1 = (check->v).iuser1;
  pe->iuser2 = (check->v).iuser2;
  pe->iuser3 = (check->v).iuser3;
  pe->iuser4 = (check->v).iuser4;
  pe->fuser1 = (check->v).fuser1;
  pe->fuser2 = (check->v).fuser2;
  pe->fuser3 = (check->v).fuser3;
  pe->fuser4 = (check->v).fuser4;
  pe->vuser1[0] = (check->v).vuser1[0];
  pe->vuser1[1] = (check->v).vuser1[1];
  pe->vuser1[2] = (check->v).vuser1[2];
  pe->vuser2[0] = (check->v).vuser2[0];
  pe->vuser2[1] = (check->v).vuser2[1];
  pe->vuser2[2] = (check->v).vuser2[2];
  pe->vuser3[0] = (check->v).vuser3[0];
  pe->vuser3[1] = (check->v).vuser3[1];
  pe->vuser3[2] = (check->v).vuser3[2];
  pe->vuser4[0] = (check->v).vuser4[0];
  pe->vuser4[1] = (check->v).vuser4[1];
  pe->vuser4[2] = (check->v).vuser4[2];
  return;
}


// SV_CountPlayers  @ 00082090
void SV_CountPlayers(int *clients)

{
  client_s *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[DW_OP_reg0(EAX)] */
  *clients = 0;
  if (0 < svs.maxclients) {
    iVar3 = 0;
    pcVar1 = svs.clients;
    iVar2 = svs.maxclients;
    do {
      if (((pcVar1->active != false) || (pcVar1->spawned != false)) || (pcVar1->connected != false))
      {
        *clients = *clients + 1;
        iVar2 = svs.maxclients;
      }
      iVar3 = iVar3 + 1;
      pcVar1 = pcVar1 + 1;
    } while (iVar3 < iVar2);
  }
  return;
}


// SV_CountProxies  @ 000820f0
void SV_CountProxies(int *proxies)

{
  client_s *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[DW_OP_reg0(EAX)] */
  *proxies = 0;
  if (0 < svs.maxclients) {
    iVar3 = 0;
    pcVar1 = svs.clients;
    iVar2 = svs.maxclients;
    do {
      if ((((pcVar1->active != false) || (pcVar1->spawned != false)) || (pcVar1->connected != false)
          ) && (pcVar1->proxy != false)) {
        *proxies = *proxies + 1;
        iVar2 = svs.maxclients;
      }
      iVar3 = iVar3 + 1;
      pcVar1 = pcVar1 + 1;
    } while (iVar3 < iVar2);
  }
  return;
}


// SV_CreateAreaNode  @ 000a8b30
areanode_t * SV_CreateAreaNode(int depth,vec_t *mins,vec_t *maxs)

{
  areanode_t *paVar1;
  link_s *plVar2;
  vec_t vVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  vec_t vVar7;
  vec_t vVar8;
  uint uVar9;
  int iVar10;
  areanode_t *paVar11;
  int iVar12;
  int iVar13;
  vec_t local_ac [3];
  float local_a0 [2];
  vec_t local_98;
  vec_t local_94 [3];
  float local_88 [2];
  vec_t local_80;
  float local_7c [2];
  vec_t local_74;
  float local_70 [2];
  vec_t local_68;
  float local_64 [2];
  vec_t local_5c;
  float local_58 [2];
  vec_t local_50;
  float local_4c;
  float local_48;
  vec_t local_44;
  float local_40 [2];
  vec_t local_38;
  float local_34 [2];
  vec_t local_2c;
  float local_28;
  float local_24;
  vec_t local_20;
  
                    /* Unresolved local var: areanode_t * anode@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: vec3_t mins1@[???]
                       Unresolved local var: vec3_t maxs1@[???]
                       Unresolved local var: vec3_t mins2@[???]
                       Unresolved local var: vec3_t maxs2@[???] */
  iVar6 = sv_numareanodes;
  paVar1 = sv_areanodes + sv_numareanodes;
  iVar12 = sv_numareanodes + 1;
  plVar2 = (link_s *)(sv_numareanodes * 0x20 + 0x54f0d0);
  sv_areanodes[sv_numareanodes].trigger_edicts.next = plVar2;
  sv_areanodes[sv_numareanodes].trigger_edicts.prev = plVar2;
  plVar2 = (link_s *)(sv_numareanodes * 0x20 + 0x54f0d8);
  paVar11 = sv_areanodes + sv_numareanodes;
  sv_numareanodes = iVar12;
  (paVar11->solid_edicts).next = plVar2;
  sv_areanodes[iVar6].solid_edicts.prev = plVar2;
  if (depth != 4) {
    uVar9 = (uint)(*maxs - *mins <= maxs[1] - mins[1]);
    sv_areanodes[iVar6].axis = uVar9;
    fVar4 = (maxs[uVar9] + mins[uVar9]) * 0.5;
    sv_areanodes[iVar6].dist = fVar4;
    local_98 = maxs[2];
    local_ac[0] = *mins;
    local_ac[1] = mins[1];
    vVar3 = mins[2];
    local_94[0] = *mins;
    local_94[1] = mins[1];
    local_28 = *maxs;
    local_a0[0] = local_28;
    local_24 = maxs[1];
                    /* Unresolved local var: areanode_t * anode@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: vec3_t mins1@[???]
                       Unresolved local var: vec3_t maxs1@[???]
                       Unresolved local var: vec3_t mins2@[???]
                       Unresolved local var: vec3_t maxs2@[???] */
    local_a0[1] = local_24;
    local_88[0] = local_28;
    local_88[1] = local_24;
    local_94[uVar9] = fVar4;
    vVar8 = local_94[1];
    vVar7 = local_94[0];
    local_a0[uVar9] = fVar4;
    iVar13 = iVar6 + 2;
    plVar2 = (link_s *)(iVar12 * 0x20 + 0x54f0d0);
    sv_areanodes[iVar12].trigger_edicts.next = plVar2;
    sv_areanodes[iVar12].trigger_edicts.prev = plVar2;
    plVar2 = (link_s *)(iVar12 * 0x20 + 0x54f0d8);
    sv_areanodes[iVar12].solid_edicts.next = plVar2;
    sv_areanodes[iVar12].solid_edicts.prev = plVar2;
    local_ac[2] = vVar3;
    local_94[2] = vVar3;
    local_80 = local_98;
    if (depth == 3) {
      sv_areanodes[iVar12].axis = -1;
      sv_areanodes[iVar12].children[1] = (areanode_s *)0x0;
      sv_areanodes[iVar12].children[0] = (areanode_s *)0x0;
    }
    else {
      uVar9 = (uint)(local_28 - local_94[0] <= local_24 - local_94[1]);
      fVar4 = local_88[uVar9];
                    /* Unresolved local var: areanode_t * anode@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: vec3_t mins1@[???]
                       Unresolved local var: vec3_t maxs1@[???]
                       Unresolved local var: vec3_t mins2@[???]
                       Unresolved local var: vec3_t maxs2@[???] */
      fVar5 = local_94[uVar9];
      sv_areanodes[iVar12].axis = uVar9;
      plVar2 = (link_s *)(iVar13 * 0x20 + 0x54f0d0);
      fVar4 = (fVar4 + fVar5) * 0.5;
      sv_areanodes[iVar13].trigger_edicts.next = plVar2;
      sv_areanodes[iVar13].trigger_edicts.prev = plVar2;
      plVar2 = (link_s *)(iVar13 * 0x20 + 0x54f0d8);
      sv_areanodes[iVar13].solid_edicts.next = plVar2;
      sv_areanodes[iVar13].solid_edicts.prev = plVar2;
      sv_areanodes[iVar12].dist = fVar4;
      local_7c[0] = local_94[0];
      local_7c[1] = local_94[1];
      local_64[0] = local_94[0];
      local_64[1] = local_94[1];
      local_70[0] = local_28;
      local_70[1] = local_24;
      local_58[0] = local_28;
      local_58[1] = local_24;
      local_64[uVar9] = fVar4;
      local_70[uVar9] = fVar4;
      iVar10 = iVar6 + 3;
      local_74 = vVar3;
      local_68 = local_98;
      local_5c = vVar3;
      local_50 = local_98;
      if (depth == 2) {
        sv_areanodes[iVar13].axis = -1;
        sv_areanodes[iVar13].children[1] = (areanode_s *)0x0;
        sv_areanodes[iVar13].children[0] = (areanode_s *)0x0;
      }
      else {
        uVar9 = (uint)(local_28 - local_64[0] <= local_24 - local_64[1]);
        fVar4 = local_58[uVar9];
        fVar5 = local_64[uVar9];
        sv_numareanodes = iVar10;
        sv_areanodes[iVar13].axis = uVar9;
        fVar4 = (fVar4 + fVar5) * 0.5;
        sv_areanodes[iVar13].dist = fVar4;
        local_4c = local_64[0];
        local_48 = local_64[1];
        local_34[0] = local_64[0];
        local_34[1] = local_64[1];
        local_34[uVar9] = fVar4;
        local_40[0] = local_28;
        local_40[1] = local_24;
        local_40[uVar9] = fVar4;
        local_44 = vVar3;
        local_38 = local_98;
        local_2c = vVar3;
        local_20 = local_98;
        paVar11 = SV_CreateAreaNode(depth + 3,local_34,&local_28);
        sv_areanodes[iVar13].children[0] = paVar11;
        paVar11 = SV_CreateAreaNode(depth + 3,&local_4c,local_40);
        sv_areanodes[iVar13].children[1] = paVar11;
        iVar10 = sv_numareanodes;
      }
      sv_areanodes[iVar12].children[0] = sv_areanodes + iVar13;
                    /* Unresolved local var: areanode_t * anode@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: vec3_t mins1@[???]
                       Unresolved local var: vec3_t maxs1@[???]
                       Unresolved local var: vec3_t mins2@[???]
                       Unresolved local var: vec3_t maxs2@[???] */
      iVar13 = iVar10 + 1;
      plVar2 = (link_s *)(iVar10 * 0x20 + 0x54f0d0);
      sv_areanodes[iVar10].trigger_edicts.next = plVar2;
      sv_areanodes[iVar10].trigger_edicts.prev = plVar2;
      plVar2 = (link_s *)(iVar10 * 0x20 + 0x54f0d8);
      sv_numareanodes = iVar13;
      sv_areanodes[iVar10].solid_edicts.next = plVar2;
      sv_areanodes[iVar10].solid_edicts.prev = plVar2;
      if (depth == 2) {
        sv_areanodes[iVar10].axis = -1;
        sv_areanodes[iVar10].children[1] = (areanode_s *)0x0;
        sv_areanodes[iVar10].children[0] = (areanode_s *)0x0;
      }
      else {
        uVar9 = (uint)(local_70[0] - vVar7 <= local_70[1] - vVar8);
        fVar4 = local_70[uVar9];
        fVar5 = local_7c[uVar9];
        sv_areanodes[iVar10].axis = uVar9;
        fVar4 = (fVar4 + fVar5) * 0.5;
        sv_areanodes[iVar10].dist = fVar4;
        local_4c = vVar7;
        local_48 = vVar8;
        local_34[0] = vVar7;
        local_34[1] = vVar8;
        local_40[0] = local_70[0];
        local_40[1] = local_70[1];
        local_38 = local_68;
        local_28 = local_70[0];
        local_24 = local_70[1];
        local_20 = local_68;
        local_34[uVar9] = fVar4;
        local_40[uVar9] = fVar4;
        local_44 = vVar3;
        local_2c = vVar3;
        paVar11 = SV_CreateAreaNode(depth + 3,local_34,&local_28);
        sv_areanodes[iVar10].children[0] = paVar11;
        paVar11 = SV_CreateAreaNode(depth + 3,&local_4c,local_40);
        sv_areanodes[iVar10].children[1] = paVar11;
        iVar13 = sv_numareanodes;
      }
      sv_areanodes[iVar12].children[1] = sv_areanodes + iVar10;
    }
    vVar8 = local_ac[2];
    vVar7 = local_ac[1];
    vVar3 = local_ac[0];
                    /* Unresolved local var: areanode_t * anode@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: vec3_t mins1@[???]
                       Unresolved local var: vec3_t maxs1@[???]
                       Unresolved local var: vec3_t mins2@[???]
                       Unresolved local var: vec3_t maxs2@[???] */
    iVar10 = iVar13 + 1;
    sv_numareanodes = iVar10;
    sv_areanodes[iVar6].children[0] = sv_areanodes + iVar12;
    plVar2 = (link_s *)(iVar13 * 0x20 + 0x54f0d0);
    sv_areanodes[iVar13].trigger_edicts.next = plVar2;
    sv_areanodes[iVar13].trigger_edicts.prev = plVar2;
    plVar2 = (link_s *)(iVar13 * 0x20 + 0x54f0d8);
    sv_areanodes[iVar13].solid_edicts.next = plVar2;
    sv_areanodes[iVar13].solid_edicts.prev = plVar2;
    if (depth == 3) {
      sv_areanodes[iVar13].axis = -1;
      sv_areanodes[iVar13].children[1] = (areanode_s *)0x0;
      sv_areanodes[iVar13].children[0] = (areanode_s *)0x0;
    }
    else {
      local_5c = local_ac[2];
      local_68 = local_98;
      uVar9 = (uint)(local_a0[0] - local_ac[0] <= local_a0[1] - local_ac[1]);
      fVar4 = local_a0[uVar9];
                    /* Unresolved local var: areanode_t * anode@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: vec3_t mins1@[???]
                       Unresolved local var: vec3_t maxs1@[???]
                       Unresolved local var: vec3_t mins2@[???]
                       Unresolved local var: vec3_t maxs2@[???] */
      fVar5 = local_ac[uVar9];
      sv_areanodes[iVar13].axis = uVar9;
      plVar2 = (link_s *)(iVar10 * 0x20 + 0x54f0d0);
      fVar4 = (fVar4 + fVar5) * 0.5;
      sv_areanodes[iVar10].trigger_edicts.next = plVar2;
      sv_areanodes[iVar10].trigger_edicts.prev = plVar2;
      plVar2 = (link_s *)(iVar10 * 0x20 + 0x54f0d8);
      local_74 = local_ac[2];
      local_50 = local_98;
      sv_areanodes[iVar10].solid_edicts.next = plVar2;
      sv_areanodes[iVar10].solid_edicts.prev = plVar2;
      sv_areanodes[iVar13].dist = fVar4;
      local_7c[0] = local_ac[0];
      local_7c[1] = local_ac[1];
      local_64[0] = local_ac[0];
      local_64[1] = local_ac[1];
      local_70[0] = local_a0[0];
      local_70[1] = local_a0[1];
      local_58[0] = local_a0[0];
      local_58[1] = local_a0[1];
      local_64[uVar9] = fVar4;
      local_70[uVar9] = fVar4;
      iVar12 = iVar13 + 2;
      if (depth == 2) {
        sv_areanodes[iVar10].axis = -1;
        sv_areanodes[iVar10].children[1] = (areanode_s *)0x0;
        sv_areanodes[iVar10].children[0] = (areanode_s *)0x0;
      }
      else {
        local_38 = local_98;
        local_20 = local_98;
        uVar9 = (uint)(local_a0[0] - local_64[0] <= local_a0[1] - local_64[1]);
        fVar4 = local_58[uVar9];
        fVar5 = local_64[uVar9];
        sv_numareanodes = iVar12;
        sv_areanodes[iVar10].axis = uVar9;
        fVar4 = (fVar4 + fVar5) * 0.5;
        sv_areanodes[iVar10].dist = fVar4;
        local_4c = local_64[0];
        local_48 = local_64[1];
        local_44 = local_ac[2];
        local_34[0] = local_64[0];
        local_34[1] = local_64[1];
        local_2c = local_ac[2];
        local_40[0] = local_a0[0];
        local_40[1] = local_a0[1];
        local_28 = local_a0[0];
        local_24 = local_a0[1];
        local_34[uVar9] = fVar4;
        local_40[uVar9] = fVar4;
        paVar11 = SV_CreateAreaNode(depth + 3,local_34,&local_28);
        sv_areanodes[iVar10].children[0] = paVar11;
        paVar11 = SV_CreateAreaNode(depth + 3,&local_4c,local_40);
        sv_areanodes[iVar10].children[1] = paVar11;
        iVar12 = sv_numareanodes;
      }
      sv_areanodes[iVar13].children[0] = sv_areanodes + iVar10;
                    /* Unresolved local var: areanode_t * anode@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: vec3_t mins1@[???]
                       Unresolved local var: vec3_t maxs1@[???]
                       Unresolved local var: vec3_t mins2@[???]
                       Unresolved local var: vec3_t maxs2@[???] */
      sv_numareanodes = iVar12 + 1;
      plVar2 = (link_s *)(iVar12 * 0x20 + 0x54f0d0);
      sv_areanodes[iVar12].trigger_edicts.next = plVar2;
      sv_areanodes[iVar12].trigger_edicts.prev = plVar2;
      plVar2 = (link_s *)(iVar12 * 0x20 + 0x54f0d8);
      sv_areanodes[iVar12].solid_edicts.next = plVar2;
      sv_areanodes[iVar12].solid_edicts.prev = plVar2;
      if (depth == 2) {
        sv_areanodes[iVar12].axis = -1;
        sv_areanodes[iVar12].children[1] = (areanode_s *)0x0;
        sv_areanodes[iVar12].children[0] = (areanode_s *)0x0;
      }
      else {
        local_2c = vVar8;
        local_44 = vVar8;
        uVar9 = (uint)(local_70[0] - vVar3 <= local_70[1] - vVar7);
        fVar4 = local_70[uVar9];
        fVar5 = local_7c[uVar9];
        sv_areanodes[iVar12].axis = uVar9;
        fVar4 = (fVar4 + fVar5) * 0.5;
        sv_areanodes[iVar12].dist = fVar4;
        local_4c = vVar3;
        local_48 = vVar7;
        local_34[0] = vVar3;
        local_34[1] = vVar7;
        local_40[0] = local_70[0];
        local_40[1] = local_70[1];
        local_38 = local_68;
        local_28 = local_70[0];
        local_24 = local_70[1];
        local_20 = local_68;
        local_34[uVar9] = fVar4;
        local_40[uVar9] = fVar4;
        paVar11 = SV_CreateAreaNode(depth + 3,local_34,&local_28);
        sv_areanodes[iVar12].children[0] = paVar11;
        paVar11 = SV_CreateAreaNode(depth + 3,&local_4c,local_40);
        sv_areanodes[iVar12].children[1] = paVar11;
      }
      sv_areanodes[iVar13].children[1] = sv_areanodes + iVar12;
    }
    sv_areanodes[iVar6].children[1] = sv_areanodes + iVar13;
    return paVar1;
  }
  sv_areanodes[iVar6].axis = -1;
  sv_areanodes[iVar6].children[1] = (areanode_s *)0x0;
  sv_areanodes[iVar6].children[0] = (areanode_s *)0x0;
  return paVar1;
}


// SV_CreateBaseline  @ 0008e060
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CreateBaseline(void)

{
  uint data;
  bool bVar1;
  delta_t *pFields;
  int *piVar2;
  edict_s *peVar3;
  int iVar4;
  int iVar5;
  uint32 data_00;
  int iVar6;
  int in_GS_OFFSET;
  uchar local_174 [340];
  int local_20;
  
                    /* Unresolved local var: edict_t * svent@[???]
                       Unresolved local var: int entnum@[???]
                       Unresolved local var: qboolean player@[???]
                       Unresolved local var: qboolean custom@[???]
                       Unresolved local var: entity_state_t nullstate@[???] */
                    /* Unresolved local var: int i@[???] */
  iVar4 = 0;
  sv.instance_baselines = &g_sv_instance_baselines;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_174,0,0x154);
  sv_playermodel = -1;
  do {
    if (sv.model_precache[iVar4] == (char *)0x0) break;
    iVar5 = Q_strcasecmp(sv.model_precache[iVar4],"models/player.mdl");
    if (iVar5 == 0) {
      sv_playermodel = iVar4;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x200);
  iVar6 = 0;
  iVar5 = 0;
  iVar4 = sv.num_edicts;
  if (0 < sv.num_edicts) {
    do {
      peVar3 = (edict_s *)((int)(sv.edicts)->leafnums + iVar6 + -0x18);
      if ((peVar3->free == false) && ((iVar5 <= svs.maxclients || ((peVar3->v).modelindex != 0)))) {
        bVar1 = iVar5 <= svs.maxclients;
        sv.baselines[iVar5].number = iVar5;
        sv.baselines[iVar5].entityType = 1;
        if (((peVar3->v).flags & 0x20000000) != 0) {
          sv.baselines[iVar5].entityType = 2;
        }
        (*gEntityInterface.pfnCreateBaseline)
                  ((uint)(0 < iVar5 && bVar1),iVar5,sv.baselines + iVar5,peVar3,sv_playermodel,
                   player_mins[0],player_maxs[0]);
        iVar4 = sv.num_edicts;
        sv_lastnum = iVar5;
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x324;
    } while (iVar5 < iVar4);
  }
  iVar5 = 0;
  (*gEntityInterface.pfnCreateInstancedBaselines)();
  data_00 = 0;
  MSG_WriteByte(&sv.signon,0x16);
  MSG_StartBitWriting(&sv.signon);
  iVar4 = sv.num_edicts;
  if (0 < sv.num_edicts) {
    do {
      piVar2 = (int *)((int)(sv.edicts)->leafnums + iVar5 + -0x18);
      if ((*piVar2 == 0) && (((int)data_00 <= svs.maxclients || (piVar2[0x4d] != 0)))) {
        MSG_WriteBits(data_00,0xb);
        data = sv.baselines[data_00].entityType;
        MSG_WriteBits(data,2);
        pFields = g_pcustomentitydelta;
        if (((data & 1) != 0) &&
           (((int)data_00 < 1 || (pFields = g_pplayerdelta, svs.maxclients < (int)data_00)))) {
          pFields = g_pentitydelta;
        }
                    /* try { // try from 0008e212 to 0009e216 has its CatchHandler @ 0008dfa0 */
        DELTA_WriteDelta(local_174,(uchar *)(sv.baselines + data_00),true,pFields,(_func_void *)0x0)
        ;
        iVar4 = sv.num_edicts;
      }
      data_00 = data_00 + 1;
      iVar5 = iVar5 + 0x324;
    } while ((int)data_00 < iVar4);
  }
  iVar4 = 0;
  MSG_WriteBits(0xffff,0x10);
  MSG_WriteBits((sv.instance_baselines)->number,6);
  if (0 < (sv.instance_baselines)->number) {
    do {
      iVar5 = iVar4 + 1;
      DELTA_WriteDelta(local_174,(uchar *)((sv.instance_baselines)->baseline + iVar4),true,
                       g_pentitydelta,(_func_void *)0x0);
      iVar4 = iVar5;
    } while (iVar5 < (sv.instance_baselines)->number);
  }
  MSG_EndBitWriting(&sv.signon);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_CreateCustomizationList  @ 0009e870
/* WARNING: Removing unreachable block (ram,0x0009e8a1) */

void SV_CreateCustomizationList(client_t *pHost)

{
  int iVar1;
  qboolean qVar2;
  customization_s *pcVar3;
  resource_t *pResource;
  customization_t *local_24;
  int local_20 [4];
  
                    /* Unresolved local var: resource_t * pResource@[???] */
  pResource = (pHost->resourcesonhand).pNext;
  (pHost->customdata).pNext = (customization_s *)0x0;
  if (pResource == &pHost->resourcesonhand) {
    return;
  }
LAB_0009e910:
  do {
                    /* Unresolved local var: customization_t * pCust@[???]
                       Unresolved local var: qboolean bNoError@[???]
                       Unresolved local var: int nLumps@[???] */
    local_20[0] = 0;
    qVar2 = COM_CreateCustomization(&pHost->customdata,pResource,-1,3,&local_24,local_20);
    if (qVar2 != false) {
      local_24->nUserData2 = local_20[0];
      (*gEntityInterface.pfnPlayerCustomization)(pHost->edict,local_24);
      goto LAB_0009e8f4;
    }
    if (sv_allow_upload.value == 0.0) {
      Con_Printf("Ignoring custom decal from %s\n",pHost->name);
      goto LAB_0009e8f4;
    }
    Con_Printf("Ignoring invalid custom decal from %s\n",pHost->name);
    pResource = pResource->pNext;
    while( true ) {
      if (pResource == &pHost->resourcesonhand) {
        return;
      }
      pcVar3 = (pHost->customdata).pNext;
      if (pcVar3 == (customization_s *)0x0) break;
      while (iVar1 = Q_memcmp((pcVar3->resource).rgucMD5_hash,pResource->rgucMD5_hash,0x10),
            iVar1 != 0) {
        pcVar3 = pcVar3->pNext;
        if (pcVar3 == (customization_s *)0x0) goto LAB_0009e910;
      }
      Con_DPrintf("SV_CreateCustomization list, ignoring dup. resource for player %s\n",pHost->name)
      ;
LAB_0009e8f4:
      pResource = pResource->pNext;
    }
  } while( true );
}


// SV_CreateGenericResources  @ 0008d450
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CreateGenericResources(void)

{
  __int32_t *p_Var1;
  byte *buffer;
  byte *data;
  int iVar2;
  char *pcVar3;
  __int32_t **pp_Var4;
  __int32_t _Var5;
  qboolean qVar6;
  char (*s) [64];
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  int in_GS_OFFSET;
  byte *local_140;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char[260] filename@[???]
                       Unresolved local var: char * buffer@[???]
                       Unresolved local var: char * data@[???] */
  pcVar3 = local_124;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  COM_StripExtension(sv.modelname,pcVar3);
  COM_DefaultExtension(pcVar3,".res");
  COM_FixSlashes(pcVar3);
  buffer = COM_LoadFile(pcVar3,5,(int *)0x0);
  if (buffer != (byte *)0x0) {
    data = buffer;
    if (((*buffer == 0xef) && (buffer[1] == 0xbb)) && (data = buffer + 3, buffer[2] != 0xbf)) {
      data = buffer;
    }
    Con_DPrintf("Precaching from %s\n",pcVar3);
    Con_DPrintf("----------------------------------\n");
    sv.num_generic_names = 0;
LAB_0008d4f0:
    data = (byte *)COM_Parse((char *)data);
    iVar2 = Q_strlen(com_token);
    if (0 < iVar2) {
      if ((com_token[0] != '\\') && (com_token[0] != '/')) {
        pcVar3 = Q_strstr(com_token,"..");
        if (pcVar3 != (char *)0x0) {
          pcVar3 = com_token;
          Con_Printf("Can\'t precache resource with invalid relative path %s\n");
          goto LAB_0008d4f0;
        }
        pcVar3 = Q_strstr(com_token,":");
        if (pcVar3 == (char *)0x0) {
                    /* Unresolved local var: char * pLetter@[???] */
          uVar9 = (uint)(byte)com_token[0];
          if (com_token[0] != '\0') {
            pp_Var4 = __ctype_tolower_loc();
            pbVar10 = (byte *)(com_token + 1);
            p_Var1 = *pp_Var4;
            local_140 = (byte *)com_token;
                    /* try { // try from 0008d62b to 0009d62f has its CatchHandler @ 0008d67c */
            if (p_Var1[0x2e] == p_Var1[uVar9]) goto LAB_0008d64b;
            pbVar10 = (byte *)(com_token + 1);
            while (*pbVar10 != 0) {
              _Var5 = p_Var1[*pbVar10];
              pbVar8 = pbVar10;
              while (pbVar10 = pbVar8 + 1, local_140 = pbVar8, p_Var1[0x2e] == _Var5) {
LAB_0008d64b:
                    /* Unresolved local var: char * pMatch@[???]
                       Unresolved local var: char * pTest@[???] */
                if (*pbVar10 == 0) goto LAB_0008d6c0;
                    /* Unresolved local var: int __res@[???] */
                _Var5 = p_Var1[*pbVar10];
                pbVar8 = pbVar10;
                if (_Var5 == p_Var1[99]) {
                  pbVar7 = (byte *)0xd0bcd;
                  do {
                    pbVar7 = pbVar7 + 1;
                    pbVar10 = pbVar10 + 1;
                    if (*pbVar7 == 0) {
                      if (local_140 == (byte *)0x0) goto LAB_0008d6c0;
                      pcVar3 = com_token;
                      Con_Printf("Can\'t precache .cfg files:  %s\n");
                      goto LAB_0008d4f0;
                    }
                    if (*pbVar10 == 0) goto LAB_0008d6c0;
                    /* try { // try from 0008d678 to 0009d68d has its CatchHandler @ 0008d5a0 */
                    /* catch() { ... } // from try @ 0008d62b with catch @ 0008d67c */
                  } while (p_Var1[*pbVar10] == p_Var1[*pbVar7]);
                }
              }
            }
LAB_0008d6c0:
                    /* catch() { ... } // from try @ 0008d6e9 with catch @ 0008d6c0
                       catch() { ... } // from try @ 0008d778 with catch @ 0008d6c0 */
            pp_Var4 = __ctype_tolower_loc();
            pbVar10 = (byte *)(com_token + 1);
            p_Var1 = *pp_Var4;
            _Var5 = p_Var1[uVar9];
                    /* try { // try from 0008d6e9 to 0009d729 has its CatchHandler @ 0008d6c0 */
LAB_0008d6f0:
            do {
                    /* Unresolved local var: char * pLetter@[???] */
              if (p_Var1[0x2e] == _Var5) {
                    /* Unresolved local var: char * pMatch@[???]
                       Unresolved local var: char * pTest@[???] */
                if (*pbVar10 == 0) break;
                    /* Unresolved local var: int __res@[???] */
                _Var5 = p_Var1[0x72];
                    /* Unresolved local var: int __res@[???] */
                iVar2 = p_Var1[*pbVar10];
                if (_Var5 == p_Var1[*pbVar10]) {
                  pbVar7 = &DAT_000d94dc;
                  pbVar8 = pbVar10;
                  do {
                    pbVar7 = pbVar7 + 1;
                    pbVar8 = pbVar8 + 1;
                    if (*pbVar7 == 0) {
                      if (pbVar10 == (byte *)0x1) goto LAB_0008d784;
                      pcVar3 = com_token;
                    /* catch() { ... } // from try @ 0008d743 with catch @ 0008d76b */
                      Con_Printf("Can\'t precache .rc files:  %s\n");
                    /* try { // try from 0008d778 to 0009d77c has its CatchHandler @ 0008d6c0 */
                      goto LAB_0008d4f0;
                    }
                    if (*pbVar8 == 0) goto LAB_0008d784;
                    /* try { // try from 0008d743 to 0009d747 has its CatchHandler @ 0008d76b */
                  } while (p_Var1[*pbVar8] == p_Var1[*pbVar7]);
                  pbVar10 = pbVar10 + 1;
                  goto LAB_0008d6f0;
                }
              }
              else {
                if (*pbVar10 == 0) break;
                iVar2 = p_Var1[*pbVar10];
              }
              _Var5 = iVar2;
              pbVar10 = pbVar10 + 1;
            } while( true );
          }
LAB_0008d784:
          pcVar3 = Q_stristr(com_token,".lst");
          if (pcVar3 == (char *)0x0) {
            pcVar3 = Q_stristr(com_token,".exe");
            if (pcVar3 == (char *)0x0) {
              pcVar3 = Q_stristr(com_token,".vbs");
              if (pcVar3 == (char *)0x0) {
                pcVar3 = Q_stristr(com_token,".com");
                if (pcVar3 == (char *)0x0) {
                  pcVar3 = Q_stristr(com_token,".bat");
                  if (pcVar3 == (char *)0x0) {
                    pcVar3 = Q_stristr(com_token,".dll");
                    if (pcVar3 == (char *)0x0) {
                      pcVar3 = Q_stristr(com_token,".asi");
                      if (pcVar3 == (char *)0x0) {
                        pcVar3 = Q_stristr(com_token,".mix");
                        if (pcVar3 == (char *)0x0) {
                          pcVar3 = Q_stristr(com_token,".flt");
                          if (pcVar3 == (char *)0x0) {
                            qVar6 = PR_IsEmptyString(com_token);
                            if (qVar6 == false) {
                              Q_strncpy(sv.generic_precache_names[sv.num_generic_names],com_token,
                                        0x3f);
                              s = sv.generic_precache_names + sv.num_generic_names;
                              sv.generic_precache_names[sv.num_generic_names][0x3f] = '\0';
                              PF_precache_generic_I(*s);
                              pcVar3 = sv.generic_precache_names[sv.num_generic_names];
                              Con_DPrintf("  %s\n",pcVar3);
                              sv.num_generic_names = sv.num_generic_names + 1;
                            }
                            else {
                              pcVar3 = com_token;
                              Con_Printf("Can\'t precache invalid files:  %s\n");
                            }
                          }
                          else {
                            pcVar3 = com_token;
                            Con_Printf("Can\'t precache .flt files:  %s\n");
                          }
                        }
                        else {
                          pcVar3 = com_token;
                          Con_Printf("Can\'t precache .mix files:  %s\n");
                        }
                      }
                      else {
                        pcVar3 = com_token;
                        Con_Printf("Can\'t precache .asi files:  %s\n");
                      }
                    }
                    else {
                      pcVar3 = com_token;
                      Con_Printf("Can\'t precache .dll files:  %s\n");
                    }
                  }
                  else {
                    pcVar3 = com_token;
                    Con_Printf("Can\'t precache .bat files:  %s\n");
                  }
                }
                else {
                  pcVar3 = com_token;
                  Con_Printf("Can\'t precache .com files:  %s\n");
                }
              }
              else {
                pcVar3 = com_token;
                Con_Printf("Can\'t precache .vbs files:  %s\n");
              }
            }
            else {
              pcVar3 = com_token;
              Con_Printf("Can\'t precache .exe files:  %s\n");
            }
          }
          else {
            pcVar3 = com_token;
            Con_Printf("Can\'t precache .lst files:  %s\n");
          }
          goto LAB_0008d4f0;
        }
      }
      pcVar3 = com_token;
      Con_Printf("Can\'t precache resource with absolute path %s\n");
      goto LAB_0008d4f0;
    }
    Con_DPrintf("----------------------------------\n",pcVar3);
                    /* catch() { ... } // from try @ 0008d5c7 with catch @ 0008d5a0
                       catch() { ... } // from try @ 0008d678 with catch @ 0008d5a0 */
    COM_FreeFile(buffer);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_CreatePacketEntities  @ 0008ae40
int SV_CreatePacketEntities(sv_delta_t type,client_t *client,packet_entities_t *to,sizebuf_t *msg)

{
  entity_state_s *to_00;
  string_t sVar1;
  int iVar2;
  edict_t *peVar3;
  uint uVar4;
  qboolean custom;
  delta_t *pdVar5;
  int iVar6;
  entity_state_t *to_01;
  uint32 uVar7;
  int iVar8;
  uint32 data;
  int index;
  bool bVar9;
  packet_entities_t *local_48;
  int local_44;
  uint32 local_24;
  entity_state_s *local_20 [4];
  
                    /* Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: client_frame_t * fromframe@[???]
                       Unresolved local var: packet_entities_t * from@[???]
                       Unresolved local var: int oldindex@[???]
                       Unresolved local var: int newindex@[???]
                       Unresolved local var: int oldnum@[???]
                       Unresolved local var: int newnum@[???]
                       Unresolved local var: int oldmax@[???]
                       Unresolved local var: qboolean custom@[???]
                       Unresolved local var: int offset@[???]
                       Unresolved local var: int numbase@[???] */
  local_24 = 0;
  if (type == sv_packet_delta) {
    uVar4 = client->delta_sequence & SV_UPDATE_MASK;
    local_48 = &client->frames[uVar4].entities;
    local_44 = client->frames[uVar4].entities.num_entities;
    MSG_WriteByte(msg,0x29);
    MSG_WriteShort(msg,to->num_entities);
    MSG_WriteByte(msg,client->delta_sequence);
  }
  else {
    MSG_WriteByte(msg,0x28);
    MSG_WriteShort(msg,to->num_entities);
    local_44 = 0;
    local_48 = (packet_entities_t *)0x0;
  }
  index = 0;
  iVar8 = 0;
  MSG_StartBitWriting(msg);
  iVar6 = to->num_entities;
LAB_0008aeb0:
  do {
    if (index < iVar6) goto LAB_0008af60;
LAB_0008aeb8:
    if (local_44 <= iVar8) {
      MSG_WriteBits(0,0x10);
      MSG_EndBitWriting(msg);
      return msg->cursize;
    }
    uVar7 = 9999;
    while( true ) {
      data = local_48->entities[iVar8].number;
      bVar9 = SBORROW4(data,uVar7);
      iVar2 = data - uVar7;
      if (data == uVar7) break;
      while( true ) {
        if (bVar9 == iVar2 < 0) {
                    /* Unresolved local var: entity_state_t * baseline@[???] */
          peVar3 = EDICT_NUM(uVar7);
          to_01 = to->entities + index;
          uVar4 = to_01->entityType & 2;
          custom = (qboolean)(uVar4 != 0);
          g_svdeltacallback.numbase = (int *)&local_24;
          g_svdeltacallback.newbl = false;
          g_svdeltacallback.newblindex = 0;
          g_svdeltacallback.full = (qboolean)(local_48 == (packet_entities_t *)0x0);
          g_svdeltacallback.remove = false;
          g_svdeltacallback.offset = 0;
          local_20[0] = sv.baselines + uVar7;
          g_svdeltacallback.num = uVar7;
          g_svdeltacallback.custom = custom;
          if (((sv_instancedbaseline.value == 0.0) ||
              (iVar6 = (sv.instance_baselines)->number, iVar6 == 0)) || ((int)uVar7 <= sv_lastnum))
          {
            if (local_48 == (packet_entities_t *)0x0) {
              iVar6 = SV_FindBestBaseline(index,local_20,to->entities,uVar7,custom);
              if (iVar6 != 0) {
                g_svdeltacallback.remove = false;
                g_svdeltacallback.newblindex = 0;
                g_svdeltacallback.numbase = (int *)&local_24;
                g_svdeltacallback.newbl = false;
                g_svdeltacallback.full = true;
                g_svdeltacallback.num = uVar7;
                g_svdeltacallback.custom = custom;
                g_svdeltacallback.offset = iVar6;
              }
              to_01 = to->entities + index;
            }
            goto joined_r0x0008b186;
          }
                    /* Unresolved local var: int i@[???] */
          if (iVar6 < 1) goto joined_r0x0008b186;
          sVar1 = (sv.instance_baselines)->classname[0];
          iVar2 = 0;
          goto joined_r0x0008b14a;
        }
        if (bVar9 == iVar2 < 0) goto LAB_0008aeb0;
                    /* Unresolved local var: int delta@[???] */
        uVar7 = data - local_24;
        MSG_WriteBits(1,1);
        if (uVar7 - 1 < 0x3f) {
          MSG_WriteBits(0,1);
          MSG_WriteBits(uVar7,6);
        }
        else {
          MSG_WriteBits(1,1);
          MSG_WriteBits(data,0xb);
        }
        iVar8 = iVar8 + 1;
        iVar6 = to->num_entities;
        local_24 = data;
        if (iVar6 <= index) goto LAB_0008aeb8;
LAB_0008af60:
        data = 9999;
        uVar7 = to->entities[index].number;
        if (iVar8 < local_44) break;
        bVar9 = SBORROW4(9999,uVar7);
        iVar2 = 9999 - uVar7;
        if (iVar2 == 0) goto LAB_0008af93;
      }
    }
LAB_0008af93:
    to_00 = to->entities + index;
    g_svdeltacallback.remove = false;
    bVar9 = (to_00->entityType & 2U) != 0;
    g_svdeltacallback.custom = (qboolean)bVar9;
    g_svdeltacallback.numbase = (int *)&local_24;
    g_svdeltacallback.newbl = false;
    g_svdeltacallback.newblindex = 0;
    g_svdeltacallback.full = false;
    g_svdeltacallback.offset = 0;
    g_svdeltacallback.num = data;
    if (bVar9) {
      DELTA_WriteDelta((uchar *)(local_48->entities + iVar8),(uchar *)to_00,false,
                       g_pcustomentitydelta,SV_InvokeCallback);
    }
    else {
      if (((int)data < 1) || (pdVar5 = g_pplayerdelta, svs.maxclients < (int)data)) {
        pdVar5 = g_pentitydelta;
      }
      DELTA_WriteDelta((uchar *)(local_48->entities + iVar8),(uchar *)to_00,false,pdVar5,
                       SV_InvokeCallback);
    }
    iVar8 = iVar8 + 1;
    index = index + 1;
    iVar6 = to->num_entities;
  } while( true );
joined_r0x0008b14a:
  if (sVar1 == (peVar3->v).classname) goto LAB_0008b3b4;
  if (iVar6 == iVar2 + 1) goto joined_r0x0008b186;
  sVar1 = (sv.instance_baselines)->classname[iVar2 + 1];
  iVar2 = iVar2 + 1;
  goto joined_r0x0008b14a;
LAB_0008b3b4:
  g_svdeltacallback.newbl = true;
  local_20[0] = (entity_state_s *)((sv.instance_baselines)->baseline + iVar2);
  g_svdeltacallback.newblindex = iVar2;
joined_r0x0008b186:
  pdVar5 = g_pcustomentitydelta;
  if ((uVar4 == 0) && (((int)uVar7 < 1 || (pdVar5 = g_pplayerdelta, svs.maxclients < (int)uVar7))))
  {
    pdVar5 = g_pentitydelta;
  }
  index = index + 1;
  DELTA_WriteDelta((uchar *)local_20[0],(uchar *)to_01,true,pdVar5,SV_InvokeCallback);
  iVar6 = to->num_entities;
  goto LAB_0008aeb0;
}


// SV_CreateResourceList  @ 0008d9f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_CreateResourceList(void)

{
  uchar uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  char **ppcVar8;
  int iVar9;
  decalname_t *src;
  
                    /* Unresolved local var: char * * s@[???]
                       Unresolved local var: int ffirstsent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int nSize@[???] */
  sv.num_resources = 0;
  if (sv.generic_precache[1] != (char *)0x0) {
    ppcVar8 = sv.generic_precache + 1;
    iVar9 = 1;
    pcVar5 = sv.generic_precache[1];
    do {
      uVar7 = 0;
      if (1 < svs.maxclients) {
        uVar7 = FS_FileSize(pcVar5);
        pcVar5 = *ppcVar8;
      }
                    /* Unresolved local var: resource_t * r@[???] */
      iVar4 = sv.num_resources;
      if (0x4ff < sv.num_resources) {
        Sys_Error("Too many resources on server.");
      }
      sv.num_resources = sv.num_resources + 1;
      ppcVar8 = ppcVar8 + 1;
      sv.resourcelist[iVar4].type = t_generic;
      Q_strncpy(sv.resourcelist[iVar4].szFileName,pcVar5,0x3f);
      sv.resourcelist[iVar4].nIndex = iVar9;
      iVar9 = iVar9 + 1;
      sv.resourcelist[iVar4].szFileName[0x3f] = '\0';
      sv.resourcelist[iVar4].nDownloadSize = uVar7;
      sv.resourcelist[iVar4].ucFlags = '\x01';
      pcVar5 = *ppcVar8;
    } while (pcVar5 != (char *)0x0);
  }
  if (sv.sound_precache[1] != (char *)0x0) {
    iVar9 = 1;
    bVar2 = false;
    ppcVar8 = sv.sound_precache + 1;
    pcVar5 = sv.sound_precache[1];
    do {
      while (iVar4 = sv.num_resources, *pcVar5 != '!') {
        uVar7 = 0;
        if (1 < svs.maxclients) {
          pcVar5 = va("sound/%s",pcVar5);
          uVar7 = FS_FileSize(pcVar5);
          pcVar5 = *ppcVar8;
        }
                    /* Unresolved local var: resource_t * r@[???] */
        iVar4 = sv.num_resources;
        if (0x4ff < sv.num_resources) {
          Sys_Error("Too many resources on server.");
        }
        sv.num_resources = sv.num_resources + 1;
        sv.resourcelist[iVar4].type = t_sound;
        Q_strncpy(sv.resourcelist[iVar4].szFileName,pcVar5,0x3f);
        sv.resourcelist[iVar4].szFileName[0x3f] = '\0';
        sv.resourcelist[iVar4].ucFlags = '\0';
        sv.resourcelist[iVar4].nIndex = iVar9;
        sv.resourcelist[iVar4].nDownloadSize = uVar7;
LAB_0008db9a:
        ppcVar8 = ppcVar8 + 1;
        pcVar5 = *ppcVar8;
        iVar9 = iVar9 + 1;
        if (pcVar5 == (char *)0x0) goto LAB_0008dbd0;
      }
      if (!bVar2) {
                    /* Unresolved local var: resource_t * r@[???] */
        if (0x4ff < sv.num_resources) {
          Sys_Error("Too many resources on server.");
        }
        sv.num_resources = sv.num_resources + 1;
        sv.resourcelist[iVar4].type = t_sound;
        Q_strncpy(sv.resourcelist[iVar4].szFileName,"!",0x3f);
        sv.resourcelist[iVar4].szFileName[0x3f] = '\0';
        sv.resourcelist[iVar4].nDownloadSize = 0;
        sv.resourcelist[iVar4].ucFlags = '\x01';
        sv.resourcelist[iVar4].nIndex = iVar9;
        bVar2 = true;
        goto LAB_0008db9a;
      }
      ppcVar8 = ppcVar8 + 1;
      bVar2 = true;
      pcVar5 = *ppcVar8;
      iVar9 = iVar9 + 1;
    } while (pcVar5 != (char *)0x0);
  }
LAB_0008dbd0:
  if (sv.model_precache[1] != (char *)0x0) {
    iVar9 = 1;
    ppcVar8 = sv.model_precache + 1;
    pcVar5 = sv.model_precache[1];
    do {
      uVar7 = 0;
      if ((1 < svs.maxclients) && (*pcVar5 != '*')) {
        uVar7 = FS_FileSize(pcVar5);
        pcVar5 = *ppcVar8;
      }
                    /* Unresolved local var: resource_t * r@[???] */
      iVar4 = sv.num_resources;
      uVar1 = sv.model_precache_flags[iVar9];
      if (0x4ff < sv.num_resources) {
        Sys_Error("Too many resources on server.");
      }
      sv.num_resources = sv.num_resources + 1;
      ppcVar8 = ppcVar8 + 1;
      sv.resourcelist[iVar4].type = t_model;
      Q_strncpy(sv.resourcelist[iVar4].szFileName,pcVar5,0x3f);
      sv.resourcelist[iVar4].nIndex = iVar9;
      iVar9 = iVar9 + 1;
      sv.resourcelist[iVar4].szFileName[0x3f] = '\0';
      sv.resourcelist[iVar4].nDownloadSize = uVar7;
      sv.resourcelist[iVar4].ucFlags = uVar1;
      pcVar5 = *ppcVar8;
    } while (pcVar5 != (char *)0x0);
  }
  if (0 < sv_decalnamecount) {
    iVar9 = 0;
    src = sv_decalnames;
    do {
      iVar6 = Draw_DecalSize(iVar9);
      iVar4 = sv.num_resources;
                    /* Unresolved local var: resource_t * r@[???] */
      if (0x4ff < sv.num_resources) {
        Sys_Error("Too many resources on server.");
      }
      sv.num_resources = sv.num_resources + 1;
      sv.resourcelist[iVar4].type = t_decal;
      Q_strncpy(sv.resourcelist[iVar4].szFileName,src->name,0x3f);
      sv.resourcelist[iVar4].nIndex = iVar9;
      iVar3 = sv_decalnamecount;
      iVar9 = iVar9 + 1;
      sv.resourcelist[iVar4].szFileName[0x3f] = '\0';
      sv.resourcelist[iVar4].nDownloadSize = iVar6;
      sv.resourcelist[iVar4].ucFlags = '\0';
      src = src + 1;
    } while (iVar9 < iVar3);
  }
  ppcVar8 = &sv.event_precache[1].pszScript;
  iVar9 = 1;
  do {
    iVar4 = sv.num_resources;
    if (*ppcVar8 == (char *)0x0) {
      return;
    }
                    /* Unresolved local var: resource_t * r@[???] */
    iVar6 = (int)ppcVar8[-1];
    pcVar5 = ppcVar8[-2];
    if (0x4ff < sv.num_resources) {
      Sys_Error("Too many resources on server.");
    }
    sv.num_resources = sv.num_resources + 1;
    ppcVar8 = ppcVar8 + 4;
    sv.resourcelist[iVar4].type = t_eventscript;
    Q_strncpy(sv.resourcelist[iVar4].szFileName,pcVar5,0x3f);
    sv.resourcelist[iVar4].nIndex = iVar9;
    iVar9 = iVar9 + 1;
    sv.resourcelist[iVar4].szFileName[0x3f] = '\0';
    sv.resourcelist[iVar4].nDownloadSize = iVar6;
    sv.resourcelist[iVar4].ucFlags = '\x01';
  } while (iVar9 != 0x100);
  return;
}


// SV_Customization  @ 0009e9d0
void SV_Customization(client_t *pPlayer,resource_t *pResource,qboolean bSkipPlayer)

{
  int iVar1;
  int c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int nPlayerNumber@[???] */
  host_client = svs.clients;
  if (svs.maxclients < 1) {
LAB_0009eb76:
    Sys_Error("Couldn\'t find player index for customization.");
    return;
  }
  c = 0;
  if (svs.clients != pPlayer) {
    c = 0;
    do {
      c = c + 1;
      host_client = host_client + 1;
      if (c == svs.maxclients) goto LAB_0009eb76;
    } while (pPlayer != host_client);
    host_client = pPlayer;
    if (c == -1) goto LAB_0009eb76;
  }
  iVar1 = 0;
  host_client = svs.clients;
  do {
    if ((((host_client->active != false) || (host_client->spawned != false)) &&
        (host_client->fakeclient == false)) && ((bSkipPlayer == false || (host_client != pPlayer))))
    {
      MSG_WriteByte(&(host_client->netchan).message,0x2e);
      MSG_WriteByte(&(host_client->netchan).message,c);
      MSG_WriteByte(&(host_client->netchan).message,pResource->type);
      MSG_WriteString(&(host_client->netchan).message,pResource->szFileName);
      MSG_WriteShort(&(host_client->netchan).message,pResource->nIndex);
      MSG_WriteLong(&(host_client->netchan).message,pResource->nDownloadSize);
      MSG_WriteByte(&(host_client->netchan).message,(uint)pResource->ucFlags);
      if ((pResource->ucFlags & 4) != 0) {
        SZ_Write(&(host_client->netchan).message,pResource->rgucMD5_hash,0x10);
      }
    }
    iVar1 = iVar1 + 1;
    host_client = host_client + 1;
  } while (iVar1 < svs.maxclients);
  return;
}


// SV_DeallocateDynamicData  @ 00081e30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_DeallocateDynamicData(void)

{
  if (g_moved_edict != (edict_t **)0x0) {
    Mem_Free(g_moved_edict);
  }
  if (g_moved_from != (vec3_t *)0x0) {
    Mem_Free(g_moved_from);
  }
  g_moved_edict = (edict_t **)0x0;
  g_moved_from = (vec3_t *)0x0;
  return;
}


// SV_DelLogAddress_f  @ 00080040
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_DelLogAddress_f(void)

{
  loglist *plVar1;
  netadr_t a;
  ushort uVar2;
  LOGLIST_T *pLVar3;
  int iVar4;
  char *pcVar5;
  char *str;
  qboolean qVar6;
  LOGLIST_T *__ptr;
  LOGLIST_T *pLVar7;
  int in_GS_OFFSET;
  netadr_t local_138;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: int nPort@[???]
                       Unresolved local var: char[260] szAdr@[???]
                       Unresolved local var: netadr_t adr@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar4 = Cmd_Argc();
  if (iVar4 == 3) {
    pcVar5 = Cmd_Argv(1);
    str = Cmd_Argv(2);
    iVar4 = Q_atoi(str);
    if (iVar4 == 0) {
      Con_Printf("logaddress_del:  must specify a valid port\n");
    }
    else if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {
      Con_Printf("logaddress_del:  unparseable address\n");
    }
    else {
      __snprintf_chk(local_124,0x104,1,0x104,"%s:%i",pcVar5,iVar4);
      qVar6 = NET_StringToAdr(local_124,&local_138);
      if (qVar6 == false) {
        Con_Printf("logaddress_del:  unable to resolve %s\n",local_124);
      }
      else if (firstLog == (LOGLIST_T *)0x0) {
        Con_Printf("logaddress_del:  No addresses added yet\n");
      }
      else {
                    /* Unresolved local var: LOGLIST_T * list@[???]
                       Unresolved local var: LOGLIST_T * prev@[???]
                       Unresolved local var: char found@[???] */
        uVar2 = local_138.port;
        pLVar3 = firstLog;
        pLVar7 = (LOGLIST_T *)0x0;
        do {
          __ptr = pLVar3;
          iVar4 = memcmp((__ptr->log).net_address.ip,local_138.ip,4);
          if ((iVar4 == 0) && ((__ptr->log).net_address.port == uVar2)) {
            if (pLVar7 == (LOGLIST_T *)0x0) {
              firstLog = (LOGLIST_T *)0x0;
            }
            else {
              pLVar7->next = __ptr->next;
            }
            a.ip[0] = local_138.ip[0];
            a.ip[1] = local_138.ip[1];
            a.ip[2] = local_138.ip[2];
            a.ip[3] = local_138.ip[3];
            a.type = local_138.type;
            a.ipx[0] = local_138.ipx[0];
            a.ipx[1] = local_138.ipx[1];
            a.ipx[2] = local_138.ipx[2];
            a.ipx[3] = local_138.ipx[3];
            a.ipx[4] = local_138.ipx[4];
            a.ipx[5] = local_138.ipx[5];
            a.ipx[6] = local_138.ipx[6];
            a.ipx[7] = local_138.ipx[7];
            a.ipx[8] = local_138.ipx[8];
            a.ipx[9] = local_138.ipx[9];
            a.port = local_138.port;
            pcVar5 = NET_AdrToString(a);
            Con_Printf("deleting:  %s\n",pcVar5);
            free(__ptr);
            goto LAB_000800be;
          }
          pLVar3 = __ptr->next;
          pLVar7 = __ptr;
        } while (__ptr->next != (loglist *)0x0);
        Con_Printf("logaddress_del:  Couldn\'t find address in list\n");
      }
    }
  }
  else {
    Con_Printf("logaddress_del:  usage\nlogaddress_del ip port\n");
    for (plVar1 = firstLog; plVar1 != (LOGLIST_T *)0x0; plVar1 = plVar1->next) {
                    /* Unresolved local var: LOGLIST_T * list@[???] */
      pcVar5 = NET_AdrToString((plVar1->log).net_address);
      Con_Printf("current:  %s\n",pcVar5);
    }
  }
LAB_000800be:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_DownloadingModules  @ 00081a00
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_DownloadingModules(void)

{
  int in_GS_OFFSET;
  char local_44 [52];
  int local_10;
  
                    /* Unresolved local var: char[52] message@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  builtin_strncpy(local_44,"Downloading Security Module from Speakeasy.net ...\n",0x34);
  Con_Printf(local_44);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_DropClient  @ 00053be0
void SV_DropClient(client_t *cl,qboolean crash,char *fmt,...)

{
  sizebuf_t *sb;
  float fVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint *puVar7;
  uint *puVar8;
  int in_GS_OFFSET;
  byte local_610;
  undefined1 local_60f [510];
  undefined1 local_411;
  uint local_410 [256];
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: byte[512] final@[???]
                       Unresolved local var: float connection_time@[???]
                       Unresolved local var: va_list argptr@[???]
                       Unresolved local var: bool[1024] string@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_410,0x400,1,0x400,fmt,&stack0x00000010);
  if (crash == false) {
    pcVar6 = (char *)0x0;
    if (cl->fakeclient == false) {
      sb = &(cl->netchan).message;
      MSG_WriteByte(sb,2);
      MSG_WriteString(sb,(char *)local_410);
      local_610 = '\x02';
      puVar8 = local_410;
      do {
        puVar7 = puVar8;
        uVar4 = *puVar7 + 0xfefefeff & ~*puVar7;
        uVar5 = uVar4 & 0x80808080;
        puVar8 = puVar7 + 1;
      } while (uVar5 == 0);
      bVar3 = (byte)uVar5;
      if ((uVar4 & 0x8080) == 0) {
        bVar3 = (byte)(uVar5 >> 0x10);
        puVar8 = (uint *)((int)puVar7 + 6);
      }
      iVar2 = (-3 - (uint)CARRY1(bVar3,bVar3)) - (int)local_410;
      pcVar6 = (char *)((int)puVar8 + iVar2 + 1);
      if ((char *)0x1ff < pcVar6) {
        pcVar6 = (char *)0x1ff;
      }
      __strncpy_chk(local_60f,local_410,pcVar6,0x1ff);
      local_411 = 0;
      pcVar6 = (char *)((int)puVar8 + iVar2 + 2);
      if ((char *)0x1ff < (char *)((int)puVar8 + iVar2 + 1)) {
        pcVar6 = (char *)0x200;
      }
    }
    if ((cl->edict != (edict_t *)0x0) && (cl->spawned != false)) {
      (*gEntityInterface.pfnClientDisconnect)(cl->edict);
    }
    Sys_Printf("Dropped %s from server\nReason:  %s\n",cl->name,local_410);
    if (cl->fakeclient == false) {
      Netchan_Transmit(&cl->netchan,(int)pcVar6,&local_610);
    }
  }
  fVar1 = (float)realtime - (cl->netchan).connect_time;
  if (60.0 < fVar1) {
    svs.stats.cumulative_sessiontime = fVar1 + svs.stats.cumulative_sessiontime;
    svs.stats.num_sessions = svs.stats.num_sessions + 1;
  }
  NET_CheckCleanupFakeIPConnection
            ((cl->netchan).sock,(netadr_t_conflict *)&(cl->netchan).remote_address);
  Netchan_Clear(&cl->netchan);
  Steam_NotifyClientDisconnect((client_t_conflict *)cl);
  cl->active = false;
  cl->fakeclient = false;
  cl->spawned = false;
  cl->proxy = false;
  cl->connection_started = realtime;
  cl->connected = false;
  cl->hasusrmsgs = false;
  cl->fully_connected = false;
  cl->name[0] = '\0';
  COM_ClearCustomizationList(&cl->customdata,false);
  cl->edict = (edict_t *)0x0;
  Q_memset(cl->userinfo,0,0x100);
  Q_memset(cl->physinfo,0,0x100);
  SV_FullClientUpdate(cl,&sv.reliable_datagram);
  NotifyDedicatedServerUI("UpdatePlayers");
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_Drop_f  @ 00088210
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Drop_f(void)

{
  if (cmd_source != src_command) {
    SV_FlushRedirect();
    sv_redirected = RD_NONE;
    SV_BroadcastPrintf("%s dropped\n",host_client->name);
    SV_DropClient(host_client,false,"Client sent \'drop\'");
    return;
  }
  Cmd_ForwardToServer();
  return;
}


// SV_EmitEvents  @ 00089b20
void SV_EmitEvents(client_t *cl,packet_entities_t *pack,sizebuf_t *msg)

{
  int iVar1;
  uint uVar2;
  event_info_s *peVar3;
  short sVar4;
  event_state_t *peVar5;
  uint32 data;
  int iVar6;
  short *psVar7;
  uint32 uVar8;
  int *piVar9;
  int iVar10;
  event_args_t *to;
  int iVar11;
  uchar local_64 [84];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int ev@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * info@[???]
                       Unresolved local var: entity_state_t * state@[???]
                       Unresolved local var: int ev_count@[???]
                       Unresolved local var: int etofind@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: event_args_t nullargs@[???] */
  Q_memset(local_64,0,0x48);
  uVar8 = 0;
  peVar5 = &cl->events;
  do {
    peVar3 = peVar5->ei;
    peVar5 = (event_state_t *)(peVar5->ei + 1);
    uVar8 = (uVar8 + 1) - (uint)(peVar3->index == 0);
  } while (peVar5 != (event_state_t *)&cl->edict);
  if (uVar8 != 0) {
    data = 0x1f;
    if ((int)uVar8 < 0x20) {
      data = uVar8;
    }
    psVar7 = &(cl->events).ei[0].packet_index;
    do {
      if (((event_info_s *)(psVar7 + -1))->index != 0) {
        iVar11 = pack->num_entities;
        iVar10 = (int)psVar7[1];
        if (iVar11 < 1) {
LAB_00089bf7:
          *psVar7 = (short)iVar11;
          *(int *)(psVar7 + 7) = iVar10;
        }
        else {
          if (iVar10 == pack->entities->number) {
            sVar4 = 0;
          }
          else {
            iVar6 = 0;
            piVar9 = &pack->entities[1].number;
            do {
              iVar6 = iVar6 + 1;
              if (iVar6 == iVar11) goto LAB_00089bf7;
              iVar1 = *piVar9;
              piVar9 = piVar9 + 0x55;
            } while (iVar10 != iVar1);
            sVar4 = (short)iVar6;
          }
          *psVar7 = sVar4;
          uVar2 = ((event_args_t *)(psVar7 + 5))->flags;
          *(int *)(psVar7 + 0x1b) = 0;
          if ((uVar2 & 1) == 0) {
            *(float *)(psVar7 + 9) = 0.0;
            *(float *)(psVar7 + 0xb) = 0.0;
            *(float *)(psVar7 + 0xd) = 0.0;
          }
          if ((uVar2 & 2) == 0) {
            *(float *)(psVar7 + 0xf) = 0.0;
            *(float *)(psVar7 + 0x11) = 0.0;
            *(float *)(psVar7 + 0x13) = 0.0;
          }
        }
      }
      psVar7 = psVar7 + 0x2c;
    } while (psVar7 != (undefined2 *)((int)&cl->edict + 2));
    iVar11 = 0;
    MSG_WriteByte(msg,3);
    MSG_StartBitWriting(msg);
    MSG_WriteBits(data,5);
    to = &(cl->events).ei[0].args;
    do {
      while (*(ushort *)((int)(to + -1) + 0x3c) == 0) {
        *(uchar *)((int)&to[-0xffffffff00000001].iparam2 + 2) = 0xff;
        *(uchar *)((int)&to[-0xffffffff00000001].iparam2 + 3) = 0xff;
        piVar9 = &to[1].flags;
        *(uchar *)&to[-0xffffffff00000001].bparam1 = 0xff;
        *(uchar *)((int)&to[-0xffffffff00000001].bparam1 + 1) = 0xff;
        to = (event_args_t *)(piVar9 + 4);
        if (&cl->network_userid == (USERID_t *)(piVar9 + 4)) goto LAB_00089c9d;
      }
      if (iVar11 < (int)data) {
        MSG_WriteBits((uint)*(ushort *)((int)(to + -1) + 0x3c),10);
        if (*(short *)((int)(to + -1) + 0x3e) == -1) {
LAB_00089de0:
          MSG_WriteBits(0,1);
        }
        else {
          MSG_WriteBits(1,1);
          MSG_WriteBits((int)*(short *)((int)(to + -1) + 0x3e),0xb);
          iVar10 = Q_memcmp(local_64,to,0x48);
          if (iVar10 == 0) goto LAB_00089de0;
          MSG_WriteBits(1,1);
          DELTA_WriteDelta(local_64,(uchar *)to,true,g_peventdelta,(_func_void *)0x0);
        }
        if (*(float *)((int)(to + -1) + 0x44) == 0.0) {
          MSG_WriteBits(0,1);
        }
        else {
          MSG_WriteBits(1,1);
          MSG_WriteBits((int)(*(float *)((int)(to + -1) + 0x44) * 100.0),0x10);
        }
      }
      *(uchar *)&to[-0xffffffff00000001].iparam2 = '\0';
      *(uchar *)((int)&to[-0xffffffff00000001].iparam2 + 1) = '\0';
      piVar9 = &to[1].flags;
      iVar11 = iVar11 + 1;
      *(uchar *)((int)&to[-0xffffffff00000001].iparam2 + 2) = 0xff;
      *(uchar *)((int)&to[-0xffffffff00000001].iparam2 + 3) = 0xff;
      *(uchar *)&to[-0xffffffff00000001].bparam1 = 0xff;
      *(uchar *)((int)&to[-0xffffffff00000001].bparam1 + 1) = 0xff;
      to = (event_args_t *)(piVar9 + 4);
    } while (&cl->network_userid != (USERID_t *)(piVar9 + 4));
LAB_00089c9d:
    MSG_EndBitWriting(msg);
  }
  return;
}


// SV_EmitPacketEntities  @ 0008b3f0
void SV_EmitPacketEntities(client_t *client,packet_entities_t *to,sizebuf_t *msg)

{
  if (client->delta_sequence != -1) {
    SV_CreatePacketEntities(sv_packet_delta,client,to,msg);
    return;
  }
  SV_CreatePacketEntities(sv_packet_nodelta,client,to,msg);
  return;
}


// SV_EmitPings  @ 0008bb50
void SV_EmitPings(client_t *client,sizebuf_t *msg)

{
  int iVar1;
  client_frame_t *pcVar2;
  float fVar3;
  int iVar4;
  uint data;
  int iVar5;
  uint32 data_00;
  uint32 data_01;
  uint32 uVar6;
  client_s *pcVar7;
  int local_28;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int ping@[???]
                       Unresolved local var: int packet_loss@[???] */
  MSG_WriteByte(msg,0x11);
  MSG_StartBitWriting(msg);
  iVar4 = svs.maxclients;
  data_01 = 0;
  pcVar7 = svs.clients;
  if (0 < svs.maxclients) {
    do {
      while (pcVar7->active == false) {
        data_01 = data_01 + 1;
        pcVar7 = pcVar7 + 1;
        if (iVar4 <= (int)data_01) goto LAB_0008bf9d;
      }
                    /* Unresolved local var: int i@[???] */
      iVar4 = (int)pcVar7 - (int)svs.clients >> 3;
      if (realtime < pcVar7->nextping) {
        data_00 = (uint32)SV_GetNetInfo::lastloss[iVar4 * 0x4ffec005];
        data = (uint)SV_GetNetInfo::lastping[iVar4 * -0x30013ffb];
      }
      else {
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int idx@[???] */
        pcVar7->nextping = realtime + 2.0;
        if (pcVar7->fakeclient == false) {
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int idx@[???] */
          if (SV_UPDATE_BACKUP < 0x20) {
            iVar5 = SV_UPDATE_BACKUP / 2;
            if (iVar5 < 1) goto LAB_0008bf20;
          }
          else {
            iVar5 = 0x10;
          }
          iVar1 = (pcVar7->netchan).incoming_acknowledged;
          pcVar2 = pcVar7->frames;
          if (pcVar2[iVar1 - 1U & SV_UPDATE_MASK].ping_time <= 0.0) {
            if (iVar5 != 1) {
              fVar3 = 0.0;
              local_28 = 0;
              goto LAB_0008bc47;
            }
            goto LAB_0008bf20;
          }
          fVar3 = pcVar2[iVar1 - 1U & SV_UPDATE_MASK].ping_time + 0.0;
          local_28 = 1;
          if (iVar5 != 1) {
LAB_0008bc47:
            if (pcVar2[iVar1 - 2U & SV_UPDATE_MASK].ping_time <= 0.0) {
              if (iVar5 != 2) goto LAB_0008bc73;
LAB_0008bf02:
              if (local_28 == 0) goto LAB_0008bf20;
            }
            else {
              local_28 = local_28 + 1;
              fVar3 = pcVar2[iVar1 - 2U & SV_UPDATE_MASK].ping_time + fVar3;
              if (iVar5 != 2) {
LAB_0008bc73:
                if (pcVar2[iVar1 - 3U & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 3) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 3U & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 3) goto LAB_0008bec6;
                }
                if (pcVar2[iVar1 - 4U & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 4) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 4U & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 4) goto LAB_0008bec6;
                }
                if (pcVar2[iVar1 - 5U & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 5) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 5U & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 5) goto LAB_0008bec6;
                }
                if (pcVar2[iVar1 - 6U & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 6) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 6U & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 6) goto LAB_0008bec6;
                }
                if (pcVar2[iVar1 - 7U & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 7) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 7U & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 7) goto LAB_0008bec6;
                }
                if (pcVar2[iVar1 - 8U & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 8) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 8U & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 8) goto LAB_0008bec6;
                }
                if (pcVar2[iVar1 - 9U & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 9) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 9U & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 9) goto LAB_0008bec6;
                }
                if (pcVar2[iVar1 - 10U & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 10) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 10U & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 10) goto LAB_0008bec6;
                }
                if (pcVar2[iVar1 - 0xbU & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 0xb) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 0xbU & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 0xb) goto LAB_0008bec6;
                }
                if (pcVar2[iVar1 - 0xcU & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 0xc) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 0xcU & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 0xc) goto LAB_0008bec6;
                }
                if (pcVar2[iVar1 - 0xdU & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 0xd) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 0xdU & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 0xd) goto LAB_0008bec6;
                }
                if (pcVar2[iVar1 - 0xeU & SV_UPDATE_MASK].ping_time <= 0.0) {
                  if (iVar5 == 0xe) goto LAB_0008bf02;
                }
                else {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 0xeU & SV_UPDATE_MASK].ping_time + fVar3;
                  if (iVar5 == 0xe) goto LAB_0008bec6;
                }
                if (0.0 < pcVar2[iVar1 - 0xfU & SV_UPDATE_MASK].ping_time) {
                  local_28 = local_28 + 1;
                  fVar3 = pcVar2[iVar1 - 0xfU & SV_UPDATE_MASK].ping_time + fVar3;
                }
                if ((iVar5 != 0x10) || (pcVar2[SV_UPDATE_MASK & iVar1 - 0x10U].ping_time <= 0.0))
                goto LAB_0008bf02;
                local_28 = local_28 + 1;
                fVar3 = pcVar2[SV_UPDATE_MASK & iVar1 - 0x10U].ping_time + fVar3;
              }
            }
          }
LAB_0008bec6:
          if (fVar3 / (float)local_28 < 0.0) goto LAB_0008bf20;
          data = (int)((fVar3 / (float)local_28) * 1000.0) & 0xffff;
        }
        else {
LAB_0008bf20:
          data = 0;
        }
        SV_GetNetInfo::lastping[iVar4 * -0x30013ffb] = (ushort)data;
        data_00 = (int)pcVar7->packet_loss & 0xff;
        SV_GetNetInfo::lastloss[iVar4 * 0x4ffec005] = (byte)(int)pcVar7->packet_loss;
      }
      pcVar7 = pcVar7 + 1;
      MSG_WriteBits(1,1);
      uVar6 = data_01 + 1;
      MSG_WriteBits(data_01,5);
      MSG_WriteBits(data,0xc);
      MSG_WriteBits(data_00,7);
      iVar4 = svs.maxclients;
      data_01 = uVar6;
    } while ((int)uVar6 < svs.maxclients);
  }
LAB_0008bf9d:
  MSG_WriteBits(0,1);
  MSG_EndBitWriting(msg);
  return;
}


// SV_EndRedirect  @ 000882c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_EndRedirect(void)

{
  SV_FlushRedirect();
  sv_redirected = RD_NONE;
  return;
}


// SV_EstablishTimeBase  @ 000a3430
void SV_EstablishTimeBase(client_t *cl,usercmd_t *cmds,int dropped,int numbackup,int numcmds)

{
  byte bVar1;
  double dVar2;
  int iVar3;
  byte *pbVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: double runcmd_time@[???]
                       Unresolved local var: double time_at_end@[???] */
  if (dropped < 0x18) {
    if (numbackup < dropped) {
      dVar2 = 0.0;
      iVar3 = dropped;
      do {
        iVar3 = iVar3 + -1;
        dVar2 = dVar2 + (double)(cl->lastcmd).msec / 1000.0;
        dropped = numbackup;
      } while (numbackup != iVar3);
    }
    else {
      dVar2 = 0.0;
    }
    if (0 < dropped) {
                    /* Unresolved local var: int cmdnum@[???] */
      pbVar4 = &cmds[dropped + numcmds + -1].msec;
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + -0x34;
        dVar2 = (double)bVar1 / 1000.0 + dVar2;
      } while (pbVar4 != &cmds[numcmds + -1].msec);
    }
  }
  else {
    dVar2 = 0.0;
  }
  if (0 < numcmds) {
    pbVar4 = &cmds[numcmds + -1].msec;
    do {
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + -0x34;
      dVar2 = (double)bVar1 / 1000.0 + dVar2;
    } while (&cmds[-1].msec != pbVar4);
  }
  cl->svtimebase = (sv.time + host_frametime) - dVar2;
  return;
}


// SV_EstimateNeededResources  @ 0009eef0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SV_EstimateNeededResources(void)

{
  resource_s *prVar1;
  qboolean qVar2;
  resource_s *prVar3;
  int iVar4;
  
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: int missing@[???]
                       Unresolved local var: int size@[???] */
  iVar4 = 0;
  prVar3 = (host_client->resourcesneeded).pNext;
  prVar1 = &host_client->resourcesneeded;
  if (prVar3 != prVar1) {
    do {
      while (prVar3->type != t_decal) {
        prVar3 = prVar3->pNext;
        if (prVar3 == prVar1) {
          return iVar4;
        }
      }
      qVar2 = HPAK_ResourceForHash("custom.hpk",prVar3->rgucMD5_hash,(resource_s *)0x0);
      if ((qVar2 == false) && (prVar3->nDownloadSize != 0)) {
        prVar3->ucFlags = prVar3->ucFlags | 2;
        iVar4 = iVar4 + prVar3->nDownloadSize;
      }
      prVar3 = prVar3->pNext;
      prVar1 = &host_client->resourcesneeded;
    } while (prVar3 != prVar1);
  }
  return iVar4;
}


// SV_ExecuteClientMessage  @ 000a3520
void SV_ExecuteClientMessage(client_t *cl)

{
  client_frame_t *pcVar1;
  uint uVar2;
  longdouble lVar3;
  float fVar4;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: client_frame_t * frame@[???] */
  g_balreadymoved = false;
  lVar3 = (longdouble)realtime;
  pcVar1 = cl->frames + ((cl->netchan).incoming_acknowledged & SV_UPDATE_MASK);
  fVar4 = (float)((lVar3 - (longdouble)pcVar1->senttime) - (longdouble)cl->next_messageinterval);
  pcVar1->ping_time = fVar4;
  if ((longdouble)pcVar1->senttime == (longdouble)0) {
    pcVar1->ping_time = 0.0;
  }
  else if ((lVar3 - (longdouble)cl->connection_started < (longdouble)2.0) && (0.0 < fVar4)) {
    pcVar1->ping_time = 0.0;
  }
  fVar4 = SV_CalcClientTime(cl);
  sv_player = cl->edict;
  host_client = cl;
  cl->delta_sequence = -1;
  pmove = &g_svmove;
  cl->latency = fVar4;
  while( true ) {
    if (msg_badread != false) {
      Con_Printf("SV_ReadClientMessage: badread\n");
      return;
    }
    uVar2 = MSG_ReadByte();
    if (uVar2 == 0xffffffff) break;
    if (0xb < uVar2) {
      Con_Printf("SV_ReadClientMessage: unknown command char (%d)\n",uVar2);
      SV_DropClient(cl,false,"Bad command character in client command");
      return;
    }
    if (sv_clcfuncs[uVar2].pfnParse != (_func_void_client_t_ptr *)0x0) {
                    /* Unresolved local var: _func_void_client_t_ptr * func@[???] */
      (*sv_clcfuncs[uVar2].pfnParse)(cl);
    }
  }
  return;
}


// SV_ExtractFromUserinfo  @ 0008c5f0
void SV_ExtractFromUserinfo(client_t *cl)

{
  client_s *pcVar1;
  float fVar2;
  double dVar3;
  char *pcVar4;
  char *pcVar5;
  qboolean qVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  client_s *pcVar11;
  int in_GS_OFFSET;
  int local_70;
  char local_60 [31];
  undefined1 local_41;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: char * val@[???]
                       Unresolved local var: char * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: int dupc@[???]
                       Unresolved local var: char[32] newname@[???]
                       Unresolved local var: char[32] rawname@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar8 = cl->userinfo;
  pcVar4 = Info_ValueForKey(pcVar8,"name");
  Q_strncpy(local_60,pcVar4,0x1f);
  local_41 = 0;
  Q_strcpy(local_40,local_60);
  pcVar5 = local_40;
  while (local_40[0] == '#') {
    *pcVar5 = ' ';
    pcVar5 = pcVar5 + 1;
    local_40[0] = *pcVar5;
  }
  TrimSpace(local_40,local_60);
  qVar6 = Q_UnicodeValidate(local_60);
  if (qVar6 == 0) {
    Q_UnicodeRepair(local_60);
  }
  iVar7 = Q_strlen(local_60);
  if ((((iVar7 < 1) || (iVar7 = Q_stricmp(local_60,"console"), iVar7 == 0)) ||
      (pcVar5 = Q_strstr(local_60,".."), pcVar5 != (char *)0x0)) ||
     ((pcVar5 = Q_strstr(local_60,"\""), pcVar5 != (char *)0x0 ||
      (pcVar5 = Q_strstr(local_60,"\\"), pcVar5 != (char *)0x0)))) {
    pcVar5 = "unnamed";
  }
  else {
    iVar7 = Q_strcmp(pcVar4,local_60);
    if (iVar7 == 0) goto LAB_0008c704;
    pcVar5 = local_60;
  }
  Info_SetValueForKey(pcVar8,"name",pcVar5,0x100);
  pcVar4 = Info_ValueForKey(pcVar8,"name");
LAB_0008c704:
  local_70 = 1;
  do {
    pcVar1 = svs.clients + 0x20;
    pcVar11 = svs.clients;
    while (((pcVar11->active == false || (pcVar11->spawned == false)) ||
           ((cl == pcVar11 || (iVar7 = Q_stricmp(pcVar11->name,pcVar4), iVar7 != 0))))) {
      pcVar11 = pcVar11 + 1;
      if (pcVar11 == pcVar1) {
        pcVar5 = cl->name;
        (*gEntityInterface.pfnClientUserInfoChanged)(cl->edict,pcVar8);
        pcVar4 = Info_ValueForKey(pcVar8,"name");
        Q_strncpy(pcVar5,pcVar4,0x1f);
        cl->name[0x1f] = '\0';
        ISteamGameServer_BUpdateUserData((cl->network_userid).m_SteamID,pcVar5,0);
        pcVar4 = Info_ValueForKey(pcVar8,"rate");
        iVar7 = Q_strlen(pcVar4);
        if (iVar7 != 0) {
          iVar7 = Q_atoi(pcVar4);
          if (iVar7 < 1000) {
            dVar3 = 1000.0;
          }
          else {
            iVar10 = 100000;
            if (iVar7 < 0x186a1) {
              iVar10 = iVar7;
            }
            dVar3 = (double)iVar10;
          }
          (cl->netchan).rate = dVar3;
        }
        pcVar4 = Info_ValueForKey(pcVar8,"topcolor");
        iVar7 = Q_strlen(pcVar4);
        if (iVar7 == 0) {
          Con_DPrintf("topcolor unchanged for %s\n",pcVar5);
        }
        else {
          iVar7 = Q_atoi(pcVar4);
          cl->topcolor = iVar7;
        }
        pcVar4 = Info_ValueForKey(pcVar8,"bottomcolor");
        iVar7 = Q_strlen(pcVar4);
        if (iVar7 == 0) {
          Con_DPrintf("bottomcolor unchanged for %s\n",pcVar5);
        }
        else {
          iVar7 = Q_atoi(pcVar4);
          cl->bottomcolor = iVar7;
        }
        pcVar5 = Info_ValueForKey(pcVar8,"cl_updaterate");
        iVar7 = Q_strlen(pcVar5);
        if (iVar7 != 0) {
          iVar7 = Q_atoi(pcVar5);
          if (iVar7 < 10) {
            fVar2 = 0.1;
          }
          else {
            fVar2 = 1.0 / (float)iVar7;
          }
          cl->next_messageinterval = (double)fVar2;
        }
        pcVar5 = Info_ValueForKey(pcVar8,"cl_lw");
        iVar7 = Q_strlen(pcVar5);
        if (iVar7 == 0) {
          cl->lw = 0;
        }
        else {
          iVar7 = Q_atoi(pcVar5);
          cl->lw = (uint)(iVar7 != 0);
        }
        pcVar5 = Info_ValueForKey(pcVar8,"cl_lc");
        iVar7 = Q_strlen(pcVar5);
        if (iVar7 == 0) {
          cl->lc = 0;
        }
        else {
          iVar7 = Q_atoi(pcVar5);
          cl->lc = (uint)(iVar7 != 0);
        }
        pcVar8 = Info_ValueForKey(pcVar8,"*hltv");
        iVar7 = Q_strlen(pcVar8);
        if (iVar7 == 0) {
          cl->proxy = false;
        }
        else {
          iVar7 = Q_atoi(pcVar8);
          cl->proxy = (uint)(iVar7 == 1);
        }
        if (cl->next_messageinterval == 0.0) {
          *(undefined4 *)&cl->next_messageinterval = 0x9999999a;
          *(undefined4 *)((int)&cl->next_messageinterval + 4) = 0x3fa99999;
        }
        else {
          if ((sv_maxupdaterate.value != 0.0) && (sv_maxupdaterate.value <= 0.001)) {
            Cvar_Set("sv_maxupdaterate","30.0");
          }
          if ((sv_minupdaterate.value <= 0.001) && (sv_minupdaterate.value != 0.0)) {
            Cvar_Set("sv_minupdaterate","1.0");
          }
          fVar2 = sv_minupdaterate.value;
          if ((sv_maxupdaterate.value != 0.0) &&
             ((float)cl->next_messageinterval < 1.0 / sv_maxupdaterate.value)) {
            cl->next_messageinterval = (double)(1.0 / sv_maxupdaterate.value);
          }
          if ((fVar2 != 0.0) && (fVar2 = 1.0 / fVar2, fVar2 < (float)cl->next_messageinterval)) {
            cl->next_messageinterval = (double)fVar2;
          }
        }
        if ((0.0 < sv_maxrate.value) && (sv_maxrate.value < (float)(cl->netchan).rate)) {
          fVar2 = sv_maxrate.value;
          if (100000.0 <= sv_maxrate.value) {
            fVar2 = 100000.0;
          }
          (cl->netchan).rate = (double)fVar2;
        }
        if ((0.0 < sv_minrate.value) && ((float)(cl->netchan).rate < sv_minrate.value)) {
          fVar2 = 1000.0;
          if (1000.0 < sv_minrate.value) {
            fVar2 = sv_minrate.value;
          }
          (cl->netchan).rate = (double)fVar2;
        }
        if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return;
      }
    }
    uVar9 = Q_strlen(pcVar4);
    if (0x1f < uVar9) {
      pcVar4[0x1c] = '\0';
    }
    if (*pcVar4 == '(') {
      if (pcVar4[2] == ')') {
        pcVar4 = pcVar4 + 3;
      }
      else if (pcVar4[3] == ')') {
        pcVar4 = pcVar4 + 4;
      }
    }
    __snprintf_chk(local_60,0x20,1,0x20,"(%d)%-0.*s",local_70,0x1c,pcVar4);
    Info_SetValueForKey(pcVar8,"name",local_60,0x100);
    pcVar4 = Info_ValueForKey(pcVar8,"name");
    local_70 = local_70 + 1;
  } while( true );
}


// SV_FailDownload  @ 00080ab0
void __regparm3 SV_FailDownload(char *filename)

{
  MSG_WriteByte(&(host_client->netchan).message,0x31);
  MSG_WriteString(&(host_client->netchan).message,filename);
  return;
}


// SV_FailDownload  @ 00090130
void SV_FailDownload(char *filename)

{
  if ((filename != (char *)0x0) && (*filename != '\0')) {
    MSG_WriteByte(&(host_client->netchan).message,0x31);
    MSG_WriteString(&(host_client->netchan).message,filename);
  }
  return;
}


// SV_FatPAS  @ 0008a830
byte * SV_FatPAS(float *org)

{
  fatpasbytes = (sv.worldmodel)->numleafs + 0x1f >> 3;
  Q_memset(fatpas,0,fatpasbytes);
  SV_AddToFatPAS(org,(sv.worldmodel)->nodes);
  return fatpas;
}


// SV_FatPVS  @ 0008a300
byte * SV_FatPVS(float *org)

{
  fatbytes = (sv.worldmodel)->numleafs + 0x1f >> 3;
  Q_memset(fatpvs,0,fatbytes);
  SV_AddToFatPVS(org,(sv.worldmodel)->nodes);
  return fatpvs;
}


// SV_FileInConsistencyList  @ 000a0590
qboolean SV_FileInConsistencyList(char *filename,consistency_t **ppconsist)

{
  char *s2;
  consistency_t *pcVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  iVar3 = 0;
  pcVar1 = sv.consistency_list;
  s2 = sv.consistency_list[0].filename;
  while( true ) {
    pcVar1 = pcVar1 + 1;
    if (s2 == (char *)0x0) {
      return false;
    }
    iVar2 = Q_stricmp(filename,s2);
    if (iVar2 == 0) break;
    s2 = pcVar1->filename;
    iVar3 = iVar3 + 1;
  }
  if (ppconsist == (consistency_t **)0x0) {
    return true;
  }
  *ppconsist = sv.consistency_list + iVar3;
  return true;
}


// SV_FilterPacket  @ 000892a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean SV_FilterPacket(void)

{
  int iVar1;
  uchar auVar2 [4];
  qboolean qVar3;
  ipfilter_t *__dest;
  int iVar4;
  qboolean local_2c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uint in@[???] */
  auVar2 = net_from.ip;
  iVar4 = numipfilters + -1;
  __dest = ipfilters + iVar4;
  if (-1 < iVar4) {
    do {
      iVar1 = numipfilters;
      if (((__dest->compare == 0xffffffff) || ((double)__dest->banEndTime == 0.0)) ||
         (realtime < (double)__dest->banEndTime)) {
        if (__dest->compare == (__dest->mask & (uint)auVar2)) {
          local_2c = (qboolean)(longlong)ROUND(sv_filterban.value);
          return local_2c;
        }
      }
      else {
        if (iVar4 + 1 < numipfilters) {
          memmove(__dest,__dest + 1,((numipfilters + 0xfffffff) - iVar4) * 0x10);
        }
        numipfilters = iVar1 + -1;
      }
      iVar4 = iVar4 + -1;
      __dest = __dest + -1;
    } while (iVar4 != -1);
  }
  qVar3 = (qboolean)!NAN(sv_filterban.value);
  if (sv_filterban.value != 0.0) {
    qVar3 = false;
  }
  return qVar3;
}


// SV_FilterUser  @ 00092a10
qboolean SV_FilterUser(USERID_t *userid)

{
  char *pcVar1;
  int iVar2;
  USERID_t *id;
  int iVar3;
  int in_GS_OFFSET;
  qboolean local_bc;
  char local_a0 [63];
  undefined1 local_61;
  char local_60 [63];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = numuserfilters + -1;
  id = (USERID_t *)((int)sv_decalnames + numuserfilters * 0x18 + 0x21e8);
  if (-1 < iVar3) {
    do {
      iVar2 = numuserfilters;
      if (((float)id[1].idtype == 0.0) || ((float)realtime < (float)id[1].idtype)) {
        if (((userid != (USERID_t *)0x0) && (userid->idtype == id->idtype)) &&
           (userid->idtype - 1U < 2)) {
                    /* Unresolved local var: char[64] szID1@[???]
                       Unresolved local var: char[64] szID2@[???] */
          pcVar1 = SV_GetIDString(userid);
          strncpy(local_a0,pcVar1,0x3f);
          local_61 = 0;
          pcVar1 = SV_GetIDString(id);
          strncpy(local_60,pcVar1,0x3f);
          local_21 = 0;
          iVar2 = strcasecmp(local_a0,local_60);
          if (iVar2 == 0) {
            local_bc = (qboolean)(longlong)ROUND(sv_filterban.value);
            goto LAB_00092b79;
          }
        }
      }
      else {
        if (iVar3 + 1 < numuserfilters) {
          memmove(id,(void *)((int)&id[1].m_SteamID + 4),(numuserfilters - iVar3) * 0x18 - 0x18);
        }
        numuserfilters = iVar2 + -1;
      }
      iVar3 = iVar3 + -1;
      id = (USERID_t *)((int)&id[-2].m_SteamID + 4);
    } while (iVar3 != -1);
  }
  local_bc = (qboolean)!NAN(sv_filterban.value);
  if (sv_filterban.value != 0.0) {
    local_bc = false;
  }
LAB_00092b79:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_bc;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_FindBestBaseline  @ 0008ab70
int SV_FindBestBaseline(int index,entity_state_t **baseline,entity_state_t *to,int num,
                       qboolean custom)

{
  int iVar1;
  delta_t *pdVar2;
  int iVar3;
  int iVar4;
  entity_state_t *peVar5;
  entity_state_t *to_00;
  int local_24;
  
                    /* Unresolved local var: int bestbitnumber@[???]
                       Unresolved local var: int bitnumber@[???]
                       Unresolved local var: int bestfound@[???]
                       Unresolved local var: int i@[???] */
  iVar4 = index + -1;
  pdVar2 = g_pcustomentitydelta;
  if ((custom == false) && ((num < 1 || (pdVar2 = g_pplayerdelta, svs.maxclients < num)))) {
    pdVar2 = g_pentitydelta;
  }
  to_00 = to + index;
  iVar1 = DELTA_TestDelta((uchar *)*baseline,(uchar *)to_00,pdVar2);
  iVar1 = iVar1 + -6;
  if ((iVar4 < 0) || (iVar1 < 1)) {
    iVar4 = 0;
  }
  else {
    if (num < 1) {
      peVar5 = to + index + -1;
      local_24 = index;
      if (custom == false) {
        if (to_00->entityType == peVar5->entityType) goto LAB_0008adac;
        while (((iVar4 = iVar4 + -1, 0 < iVar1 && (-1 < iVar4)) &&
               (peVar5 = peVar5 + -1, index + -0x3f != iVar4))) {
          if (to_00->entityType == peVar5->entityType) {
LAB_0008adac:
            iVar3 = DELTA_TestDelta((uchar *)peVar5,(uchar *)to_00,g_pentitydelta);
            if (iVar3 < iVar1) {
              iVar1 = iVar3;
              local_24 = iVar4;
            }
          }
        }
      }
      else {
        do {
          if ((peVar5->entityType == to_00->entityType) &&
             (iVar3 = DELTA_TestDelta((uchar *)peVar5,(uchar *)to_00,g_pcustomentitydelta),
             iVar3 < iVar1)) {
            iVar1 = iVar3;
            local_24 = iVar4;
          }
          iVar4 = iVar4 + -1;
        } while (((0 < iVar1) && (-1 < iVar4)) && (peVar5 = peVar5 + -1, index + -0x3f != iVar4));
      }
    }
    else {
      local_24 = index;
      peVar5 = to + index + -1;
      if (custom == false) {
        do {
          if (to_00->entityType == peVar5->entityType) {
            pdVar2 = g_pplayerdelta;
            if (svs.maxclients < num) {
              pdVar2 = g_pentitydelta;
            }
            iVar3 = DELTA_TestDelta((uchar *)peVar5,(uchar *)to_00,pdVar2);
            if (iVar3 < iVar1) {
              iVar1 = iVar3;
              local_24 = iVar4;
            }
          }
        } while (((0 < iVar1) && (iVar4 = iVar4 + -1, -1 < iVar4)) &&
                (peVar5 = peVar5 + -1, index + -0x3f != iVar4));
      }
      else {
        do {
          if ((to_00->entityType == peVar5->entityType) &&
             (iVar3 = DELTA_TestDelta((uchar *)peVar5,(uchar *)to_00,g_pcustomentitydelta),
             iVar3 < iVar1)) {
            iVar1 = iVar3;
            local_24 = iVar4;
          }
          iVar4 = iVar4 + -1;
        } while (((0 < iVar1) && (-1 < iVar4)) && (peVar5 = peVar5 + -1, iVar4 != index + -0x3f));
      }
    }
    iVar4 = index - local_24;
    if (iVar4 != 0) {
      *baseline = to + local_24;
    }
  }
  return iVar4;
}


// SV_FindEmptySlot  @ 00086120
int SV_FindEmptySlot(netadr_t *adr,int *pslot,client_t **ppClient)

{
  client_s *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int slot@[???]
                       Unresolved local var: int clients@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclients) {
    iVar2 = 0;
    pcVar1 = svs.clients;
    do {
      if (((pcVar1->active == false) && (pcVar1->spawned == false)) && (pcVar1->connected == false))
      {
        *pslot = iVar2;
        *ppClient = pcVar1;
        return 1;
      }
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 1;
    } while (svs.maxclients != iVar2);
  }
  SV_RejectConnection(adr,"Server is full.\n");
  return 0;
}


// SV_FindEntInPack  @ 000a2af0
entity_state_t * SV_FindEntInPack(int index,packet_entities_t *pack)

{
  entity_state_t *peVar1;
  entity_state_t *peVar2;
  entity_state_t *peVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  if (pack->num_entities < 1) {
LAB_000a2b2d:
    peVar3 = (entity_state_t *)0x0;
  }
  else {
    peVar3 = pack->entities;
    if (index != peVar3->number) {
      iVar4 = 0;
      peVar1 = peVar3;
      do {
        peVar3 = peVar1 + 1;
        iVar4 = iVar4 + 1;
        if (iVar4 == pack->num_entities) goto LAB_000a2b2d;
        peVar2 = peVar1 + 1;
        peVar1 = peVar3;
      } while (peVar2->number != index);
    }
  }
  return peVar3;
}


// SV_FindModelNumbers  @ 00082150
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_FindModelNumbers(void)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar2 = 0;
  sv_playermodel = -1;
  do {
    if (sv.model_precache[iVar2] == (char *)0x0) {
      return;
    }
    iVar1 = Q_strcasecmp(sv.model_precache[iVar2],"models/player.mdl");
    if (iVar1 == 0) {
      sv_playermodel = iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x200);
  return;
}


// SV_FindTouchedLeafs  @ 000a9a60
void SV_FindTouchedLeafs(edict_t *ent,mnode_t *node,int *topnode)

{
  byte bVar1;
  mplane_t *p;
  int iVar2;
  uint uVar3;
  
                    /* Unresolved local var: mplane_t * splitplane@[???]
                       Unresolved local var: mleaf_t * leaf@[???]
                       Unresolved local var: int sides@[???]
                       Unresolved local var: int leafnum@[???] */
  if (node->contents == -2) {
    return;
  }
  if (-1 < node->contents) {
    do {
      p = node->plane;
      bVar1 = p->type;
      if (bVar1 < 3) {
        if (p->dist <= (ent->v).absmin[bVar1]) {
          uVar3 = 0;
          goto LAB_000a9abc;
        }
        if (p->dist < (ent->v).absmax[bVar1]) goto LAB_000a9aae;
      }
      else {
        uVar3 = BoxOnPlaneSide((ent->v).absmin,(ent->v).absmax,p);
        if (uVar3 == 3) {
LAB_000a9aae:
          if (*topnode == -1) {
            *topnode = ((int)node - (int)(sv.worldmodel)->nodes >> 3) * -0x33333333;
          }
          uVar3 = 2;
        }
        else {
          if ((uVar3 & 1) == 0) {
            if ((uVar3 & 2) == 0) {
              return;
            }
            goto LAB_000a9ad3;
          }
          uVar3 = uVar3 & 2;
        }
LAB_000a9abc:
        SV_FindTouchedLeafs(ent,node->children[0],topnode);
        if (uVar3 == 0) {
          return;
        }
      }
LAB_000a9ad3:
      node = node->children[1];
      if (node->contents == -2) {
        return;
      }
    } while (-1 < node->contents);
  }
  iVar2 = ent->num_leafs;
  if (iVar2 < 0x30) {
    ent->leafnums[iVar2] = (short)((int)node - (int)(sv.worldmodel)->leafs >> 4) * -0x5555 + -1;
    ent->num_leafs = iVar2 + 1;
    return;
  }
  ent->num_leafs = 0x31;
  return;
}


// SV_FinishCertificateCheck  @ 00085870
int SV_FinishCertificateCheck(netadr_t *adr,int nAuthProtocol,char *szRawCertificate,char *userinfo)

{
  int iVar1;
  char *str;
  
                    /* Unresolved local var: int nHashCount@[???]
                       Unresolved local var: char * val@[???] */
  if (nAuthProtocol != 2) {
    iVar1 = strcasecmp(szRawCertificate,"steam");
    if (iVar1 == 0) {
      return 1;
    }
    SV_RejectConnection(adr,"Expecting STEAM authentication USERID ticket!\n");
    return 0;
  }
  iVar1 = Q_strlen(szRawCertificate);
  if (iVar1 == 0x20) {
    if (adr->type == NA_LOOPBACK) {
      return 1;
    }
                    /* Unresolved local var: int nHashCount@[???]
                       Unresolved local var: char * val@[???] */
    str = Info_ValueForKey(userinfo,"*hltv");
    iVar1 = Q_strlen(str);
                    /* Unresolved local var: int i@[???] */
    if ((iVar1 != 0) && (iVar1 = Q_atoi(str), iVar1 == 1)) {
      return 1;
    }
  }
  SV_RejectConnection(adr,"Invalid CD Key.\n");
  return 0;
}


// SV_FixCheckBottom  @ 00096f50
void SV_FixCheckBottom(edict_t *ent)

{
  int *piVar1;
  
  piVar1 = &(ent->v).flags;
  *piVar1 = *piVar1 | 0x400;
  return;
}


// SV_FixupGravityVelocity  @ 0009a9e0
void SV_FixupGravityVelocity(edict_t *ent)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  uVar3 = nanmask;
  fVar1 = (ent->v).gravity;
  fVar2 = 1.0;
  if (fVar1 != 0.0) {
    fVar2 = fVar1;
  }
                    /* Unresolved local var: int i@[???] */
  (ent->v).velocity[2] =
       (ent->v).velocity[2] - fVar2 * sv_gravity.value * (float)host_frametime * 0.5;
  if (((uint)(ent->v).velocity[0] & uVar3) == uVar3) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar3 = nanmask;
    (ent->v).velocity[0] = 0.0;
  }
  if (((uint)(ent->v).origin[0] & uVar3) == uVar3) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[0] = 0.0;
  }
  fVar1 = (ent->v).velocity[0];
  if (sv_maxvelocity.value < fVar1) {
    Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[0] = sv_maxvelocity.value;
  }
  else if (fVar1 < -sv_maxvelocity.value) {
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[0] = -sv_maxvelocity.value;
  }
  uVar3 = nanmask;
  if (nanmask == ((uint)(ent->v).velocity[1] & nanmask)) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar3 = nanmask;
    (ent->v).velocity[1] = 0.0;
  }
  if (uVar3 == ((uint)(ent->v).origin[1] & uVar3)) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[1] = 0.0;
  }
  fVar1 = (ent->v).velocity[1];
  if (sv_maxvelocity.value < fVar1) {
    Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[1] = sv_maxvelocity.value;
  }
  else if (fVar1 < -sv_maxvelocity.value) {
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[1] = -sv_maxvelocity.value;
  }
  uVar3 = nanmask;
  if (nanmask == ((uint)(ent->v).velocity[2] & nanmask)) {
    Con_Printf("Got a NaN velocity on %s\n",pr_strings + (ent->v).classname);
    uVar3 = nanmask;
    (ent->v).velocity[2] = 0.0;
  }
  if (((uint)(ent->v).origin[2] & uVar3) == uVar3) {
    Con_Printf("Got a NaN origin on %s\n",pr_strings + (ent->v).classname);
    (ent->v).origin[2] = 0.0;
  }
  fVar1 = (ent->v).velocity[2];
  if (fVar1 <= sv_maxvelocity.value) {
    if (-sv_maxvelocity.value <= fVar1) {
      return;
    }
    Con_DPrintf("Got a velocity too low on %s\n",pr_strings + (ent->v).classname);
    (ent->v).velocity[2] = -sv_maxvelocity.value;
    return;
  }
  Con_DPrintf("Got a velocity too high on %s\n",pr_strings + (ent->v).classname);
  (ent->v).velocity[2] = sv_maxvelocity.value;
  return;
}


// SV_FlushRedirect  @ 000880b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_FlushRedirect(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int in_GS_OFFSET;
  int iStackY_50;
  netadr_t nStack_40;
  char *local_24;
  undefined2 local_20 [2];
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (sv_redirected == RD_PACKET) {
                    /* Unresolved local var: sizebuf_t buf@[???]
                       Unresolved local var: byte * data@[???] */
    iStackY_50 = 0x88134;
    iVar1 = Q_strlen(outputbuf);
    local_24 = "Redirected Text";
    iVar1 = -(iVar1 + 0x25U & 0xfffffff0);
    puVar3 = &stack0xffffffb4 + iVar1;
    *(char **)(&stack0xffffffb4 + iVar1) = outputbuf;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0x88153;
    iVar2 = Q_strlen(*(char **)(&stack0xffffffb4 + iVar1));
    local_1c = (int)local_20 + iVar1;
    *(undefined4 *)(&stack0xffffffb8 + iVar1) = 0xffffffff;
    *(char ***)(&stack0xffffffb4 + iVar1) = &local_24;
    local_14 = 0;
    local_20[0] = 1;
    local_18 = iVar2 + 7;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0x88180;
    MSG_WriteLong(*(sizebuf_t **)(&stack0xffffffb4 + iVar1),*(int *)(&stack0xffffffb8 + iVar1));
    *(undefined4 *)(&stack0xffffffb8 + iVar1) = 0x6c;
    *(char ***)(&stack0xffffffb4 + iVar1) = &local_24;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0x88191;
    MSG_WriteByte(*(sizebuf_t **)(&stack0xffffffb4 + iVar1),*(int *)(&stack0xffffffb8 + iVar1));
    *(char **)(&stack0xffffffb8 + iVar1) = outputbuf;
    *(char ***)(&stack0xffffffb4 + iVar1) = &local_24;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0x881a2;
    MSG_WriteString(*(sizebuf_t **)(&stack0xffffffb4 + iVar1),*(char **)(&stack0xffffffb8 + iVar1));
    *(undefined4 *)(&stack0xffffffb8 + iVar1) = 0;
    *(char ***)(&stack0xffffffb4 + iVar1) = &local_24;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0x881b0;
    MSG_WriteByte(*(sizebuf_t **)(&stack0xffffffb4 + iVar1),*(int *)(&stack0xffffffb8 + iVar1));
    *(undefined4 *)(&stack0xffffffb4 + iVar1) = 1;
    *(netadrtype_t *)((int)&nStack_40 + iVar1) = sv_redirectto.type;
    *(uchar (*) [4])((int)&nStack_40 + iVar1 + 4) = sv_redirectto.ip;
    *(undefined4 *)((int)&nStack_40 + iVar1 + 8) = sv_redirectto.ipx._0_4_;
    *(undefined4 *)((int)&nStack_40 + iVar1 + 0xc) = sv_redirectto.ipx._4_4_;
    *(undefined4 *)((int)&nStack_40 + iVar1 + 0x10) = sv_redirectto._16_4_;
    *(int *)(&stack0xffffffbc + iVar1) = local_1c;
    *(undefined4 *)(&stack0xffffffb8 + iVar1) = local_14;
    *(undefined4 *)((int)&iStackY_50 + iVar1) = 0x881f7;
    NET_SendPacket(*(netsrc_t *)(&stack0xffffffb4 + iVar1),*(int *)(&stack0xffffffb8 + iVar1),
                   *(void **)(&stack0xffffffbc + iVar1),*(netadr_t *)((int)&nStack_40 + iVar1));
  }
  else {
    puVar3 = &stack0xffffffb4;
    if (sv_redirected == RD_CLIENT) {
      iStackY_50 = 0x88109;
      MSG_WriteByte(&(host_client->netchan).message,8);
      iStackY_50 = 0x88122;
      MSG_WriteString(&(host_client->netchan).message,outputbuf);
      puVar3 = &stack0xffffffb4;
    }
  }
  outputbuf[0] = '\0';
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar3 + -4) = &UNK_00088201;
  __stack_chk_fail();
}


// SV_FlyDirection  @ 00096a10
qboolean SV_FlyDirection(edict_t *ent,vec_t *direction)

{
  vec_t *mins;
  vec_t *maxs;
  float fVar1;
  float fVar2;
  float fVar3;
  edict_t *peVar4;
  uint uVar5;
  int iVar6;
  qboolean qVar7;
  uint uVar8;
  trace_t local_ac;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  int local_54 [4];
  float local_44;
  vec_t local_40;
  vec_t local_3c;
  vec_t vStack_38;
  edict_t *peStack_24;
  
                    /* Unresolved local var: vec3_t oldorigin@[???] */
                    /* Unresolved local var: float dz@[???]
                       Unresolved local var: vec3_t oldorg@[???]
                       Unresolved local var: vec3_t neworg@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * enemy@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  fVar1 = (ent->v).origin[0];
  fVar2 = (ent->v).origin[1];
  fVar3 = (ent->v).origin[2];
  local_6c = *direction + fVar1;
  uVar8 = (ent->v).flags;
  local_68 = direction[1] + fVar2;
  qVar7 = uVar8 >> 0x17 & true;
  local_64 = direction[2] + fVar3;
  if ((uVar8 & 3) == 0) {
    local_64 = local_64 + sv_stepsize.value;
    mins = (ent->v).mins;
    maxs = (ent->v).maxs;
    local_58 = local_64 - (sv_stepsize.value + sv_stepsize.value);
    local_60 = local_6c;
    local_5c = local_68;
    SV_Move(&local_ac,&local_6c,mins,maxs,&local_60,0,ent,qVar7);
    uVar8 = 0;
    do {
      *(undefined4 *)((int)local_54 + uVar8) =
           *(undefined4 *)((int)local_ac.endpos + (uVar8 - 0x14));
      uVar8 = uVar8 + 4;
    } while (uVar8 < 0x38);
    if (local_54[0] == 0) {
      if (local_54[1] != 0) {
        local_64 = local_64 - sv_stepsize.value;
        SV_Move(&local_ac,&local_6c,mins,maxs,&local_60,0,ent,qVar7);
        uVar8 = 0;
        do {
          *(undefined4 *)((int)local_54 + uVar8) =
               *(undefined4 *)((int)local_ac.endpos + (uVar8 - 0x14));
          uVar8 = uVar8 + 4;
        } while (uVar8 < 0x38);
        if ((local_54[0] != 0) || (local_54[1] != 0)) goto LAB_00096bc0;
      }
      if (local_44 == 1.0) {
        uVar8 = (ent->v).flags;
        if ((uVar8 & 0x400) == 0) goto LAB_00096bc0;
        (ent->v).origin[0] = (ent->v).origin[0] + *direction;
        (ent->v).origin[1] = (ent->v).origin[1] + direction[1];
        fVar1 = (ent->v).origin[2];
        fVar2 = direction[2];
        (ent->v).flags = uVar8 & 0xfffffdff;
        (ent->v).origin[2] = fVar1 + fVar2;
      }
      else {
        (ent->v).origin[0] = local_40;
        (ent->v).origin[1] = local_3c;
        (ent->v).origin[2] = vStack_38;
        qVar7 = SV_CheckBottom(ent);
        if (qVar7 == false) {
          if (((ent->v).flags & 0x400) == 0) {
            (ent->v).origin[0] = fVar1;
            (ent->v).origin[1] = fVar2;
            (ent->v).origin[2] = fVar3;
            goto LAB_00096bc0;
          }
        }
        else {
          uVar8 = (ent->v).flags;
          if ((uVar8 & 0x400) != 0) {
            (ent->v).flags = uVar8 & 0xfffffbff;
          }
          (ent->v).groundentity = peStack_24;
        }
      }
LAB_00096d46:
      SV_LinkEdict(ent,true);
      return true;
    }
  }
  else {
    uVar8 = 0;
    while( true ) {
      peVar4 = (ent->v).enemy;
      if (((uVar8 & 1) == 0) && (peVar4 != (edict_t *)0x0)) {
        fVar3 = fVar3 - (peVar4->v).origin[2];
        if (40.0 < fVar3) {
          local_64 = local_64 - 8.0;
        }
        if (fVar3 < 30.0) {
          local_64 = local_64 + 8.0;
        }
      }
      SV_Move(&local_ac,(ent->v).origin,(ent->v).mins,(ent->v).maxs,&local_6c,0,ent,qVar7);
      uVar5 = 0;
      do {
        *(undefined4 *)((int)local_54 + uVar5) =
             *(undefined4 *)((int)local_ac.endpos + (uVar5 - 0x14));
        uVar5 = uVar5 + 4;
      } while (uVar5 < 0x38);
      if (local_44 == 1.0) break;
      if ((peVar4 == (edict_t *)0x0) || (uVar8 = uVar8 + 1, uVar8 == 2)) goto LAB_00096bc0;
      fVar3 = (ent->v).origin[2];
      local_6c = (ent->v).origin[0] + *direction;
      local_68 = (ent->v).origin[1] + direction[1];
      local_64 = direction[2] + fVar3;
    }
    g_groupmask = (ent->v).groupinfo;
    if ((((ent->v).flags & 2) == 0) || (iVar6 = SV_PointContents(&local_40), iVar6 != -1)) {
      (ent->v).origin[0] = local_40;
      (ent->v).origin[1] = local_3c;
      (ent->v).origin[2] = vStack_38;
      goto LAB_00096d46;
    }
  }
LAB_00096bc0:
  SV_LinkEdict(ent,true);
  return false;
}


// SV_FlyMove  @ 00099790
/* WARNING: Type propagation algorithm not settling */

int SV_FlyMove(edict_t *ent,float time,trace_t *steptrace)

{
  vec_t *maxs;
  vec_t *mins;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float fVar9;
  vec_t vVar10;
  vec_t vVar11;
  qboolean monsterClipBrush;
  uint uVar12;
  int iVar13;
  uint uVar14;
  float *pfVar15;
  float local_188;
  float local_184;
  int local_148;
  int local_130;
  trace_t local_12c;
  float local_e0;
  float local_dc;
  float fStack_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  trace_t tStack_c8;
  trace_t tStack_90;
  float local_58 [4];
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float fStack_20;
  
                    /* Unresolved local var: int bumpcount@[???]
                       Unresolved local var: int numbumps@[???]
                       Unresolved local var: vec3_t dir@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: int numplanes@[???]
                       Unresolved local var: vec_t[5][3] planes@[???]
                       Unresolved local var: vec3_t primal_velocity@[???]
                       Unresolved local var: vec3_t original_velocity@[???]
                       Unresolved local var: vec3_t new_velocity@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: trace_t test@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: float time_left@[???]
                       Unresolved local var: int blocked@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  uVar14 = 0;
  local_148 = 0;
  local_130 = 4;
  fVar1 = (ent->v).velocity[0];
  maxs = (ent->v).maxs;
  fVar2 = (ent->v).velocity[1];
  fVar3 = (ent->v).velocity[2];
  monsterClipBrush = (uint)(ent->v).flags >> 0x17 & true;
  mins = (ent->v).mins;
  local_188 = fVar3;
  local_184 = fVar2;
  fVar4 = fVar1;
  fVar7 = fVar1;
  fVar6 = fVar3;
  fVar5 = fVar2;
  do {
    if (((fVar4 == 0.0) && (fVar5 == 0.0)) && (fVar6 == 0.0)) {
      return uVar14;
    }
    local_d4 = fVar4 * time + (ent->v).origin[0];
    local_d0 = fVar5 * time + (ent->v).origin[1];
    local_cc = fVar6 * time + (ent->v).origin[2];
    SV_Move(&local_12c,(ent->v).origin,mins,maxs,&local_d4,0,ent,monsterClipBrush);
    vVar11 = vec3_origin[2];
    vVar10 = vec3_origin[1];
    uVar12 = 0;
    do {
      *(undefined4 *)((int)tStack_c8.endpos + (uVar12 - 0x14)) =
           *(undefined4 *)((int)local_12c.endpos + (uVar12 - 0x14));
      uVar12 = uVar12 + 4;
    } while (uVar12 < 0x38);
    if (tStack_c8.allsolid != false) {
      (ent->v).velocity[0] = vec3_origin[0];
      (ent->v).velocity[1] = vVar10;
      (ent->v).velocity[2] = vVar11;
      return 4;
    }
    if ((0.0 < tStack_c8.fraction) &&
       (SV_Move(&tStack_90,tStack_c8.endpos,mins,maxs,tStack_c8.endpos,0,ent,monsterClipBrush),
       tStack_90.allsolid != true)) {
      fVar7 = (ent->v).velocity[0];
      local_148 = 0;
      local_184 = (ent->v).velocity[1];
      local_188 = (ent->v).velocity[2];
      (ent->v).origin[0] = tStack_c8.endpos[0];
      (ent->v).origin[1] = tStack_c8.endpos[1];
      (ent->v).origin[2] = tStack_c8.endpos[2];
    }
    if (tStack_c8.fraction == 1.0) {
      return uVar14;
    }
    if (tStack_c8.ent == (edict_t *)0x0) {
      Sys_Error("SV_FlyMove: !trace.ent");
    }
    if (0.7 < tStack_c8.plane.normal[2]) {
      iVar8 = ((tStack_c8.ent)->v).solid;
      uVar14 = uVar14 | 1;
      if (((iVar8 == 4) || (((tStack_c8.ent)->v).movetype == 0xd)) || (iVar8 == 3)) {
        uVar12 = (ent->v).flags;
      }
      else {
        uVar12 = (ent->v).flags;
        if ((uVar12 & 8) == 0) goto LAB_000999b6;
      }
      (ent->v).flags = uVar12 | 0x200;
      (ent->v).groundentity = tStack_c8.ent;
    }
LAB_000999b6:
    if ((tStack_c8.plane.normal[2] == 0.0) && (uVar14 = uVar14 | 2, steptrace != (trace_t *)0x0)) {
      uVar12 = 0;
      do {
        *(undefined4 *)((int)steptrace->endpos + (uVar12 - 0x14)) =
             *(undefined4 *)((int)tStack_c8.endpos + (uVar12 - 0x14));
        uVar12 = uVar12 + 4;
      } while (uVar12 < 0x38);
    }
    SV_Impact(ent,tStack_c8.ent,&tStack_c8);
    vVar11 = vec3_origin[2];
    vVar10 = vec3_origin[1];
    if (ent->free != false) {
      return uVar14;
    }
    time = time - time * tStack_c8.fraction;
    if (4 < local_148) {
      (ent->v).velocity[0] = vec3_origin[0];
      (ent->v).velocity[1] = vVar10;
      (ent->v).velocity[2] = vVar11;
      return uVar14;
    }
    iVar8 = local_148 + 1;
    local_58[local_148 * 3] = tStack_c8.plane.normal[0];
    local_58[local_148 * 3 + 1] = tStack_c8.plane.normal[1];
    local_58[local_148 * 3 + 2] = tStack_c8.plane.normal[2];
    if (((iVar8 == 1) && ((ent->v).movetype == 3)) &&
       ((((ent->v).flags & 0x200) == 0 || ((ent->v).friction != 1.0)))) {
                    /* Unresolved local var: float backoff@[???]
                       Unresolved local var: float change@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int blocked@[???] */
      if (local_58[2] <= 0.7) {
        fVar4 = (local_188 * local_58[2] + local_184 * local_58[1] + local_58[0] * fVar7) *
                ((1.0 - (ent->v).friction) * sv_bounce.value + 1.0);
      }
      else {
        fVar4 = local_188 * local_58[2] + local_184 * local_58[1] + local_58[0] * fVar7;
      }
                    /* Unresolved local var: float backoff@[???]
                       Unresolved local var: float change@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int blocked@[???] */
      fVar5 = fVar7 - local_58[0] * fVar4;
      fVar7 = fVar5;
      if ((-0.1 < fVar5) && (fVar7 = 0.0, 0.1 <= fVar5)) {
        fVar7 = fVar5;
      }
      fVar5 = local_184 - local_58[1] * fVar4;
      local_184 = fVar5;
      if ((-0.1 < fVar5) && (local_184 = 0.0, 0.1 <= fVar5)) {
        local_184 = fVar5;
      }
      fVar4 = local_188 - fVar4 * local_58[2];
      local_188 = fVar4;
      if ((-0.1 < fVar4) && (local_188 = 0.0, 0.1 <= fVar4)) {
        local_188 = fVar4;
      }
      (ent->v).velocity[0] = fVar7;
      (ent->v).velocity[1] = local_184;
      (ent->v).velocity[2] = local_188;
      fVar4 = fVar7;
      fVar6 = local_188;
      fVar5 = local_184;
    }
    else {
      pfVar15 = local_58;
      iVar13 = 0;
      do {
                    /* Unresolved local var: float backoff@[???]
                       Unresolved local var: float change@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int blocked@[???] */
        fVar6 = local_188 * pfVar15[2] + local_184 * pfVar15[1] + *pfVar15 * fVar7;
        fVar5 = fVar7 - *pfVar15 * fVar6;
        fVar4 = fVar5;
        if ((-0.1 < fVar5) && (fVar4 = 0.0, 0.1 <= fVar5)) {
          fVar4 = fVar5;
        }
        fVar9 = local_184 - pfVar15[1] * fVar6;
        fVar5 = fVar9;
        if ((-0.1 < fVar9) && (fVar5 = 0.0, 0.1 <= fVar9)) {
          fVar5 = fVar9;
        }
        fVar9 = local_188 - fVar6 * pfVar15[2];
        fVar6 = fVar9;
        if ((-0.1 < fVar9) && (fVar6 = 0.0, 0.1 <= fVar9)) {
          fVar6 = fVar9;
        }
        if (iVar13 == 0) {
          if (iVar8 == 1) break;
LAB_00099c3c:
          if (0.0 <= local_44 * fVar6 + local_58[3] * fVar4 + local_48 * fVar5) {
            if (iVar8 == 2) break;
            if (iVar13 != 2) goto LAB_00099c70;
            if (iVar8 == 3) break;
LAB_00099ca4:
            if (0.0 <= local_2c * fVar6 + local_34 * fVar4 + local_30 * fVar5) {
              if (iVar8 == 5) {
                if (iVar13 != 4) goto LAB_00099cd4;
                goto LAB_00099d52;
              }
LAB_00099de0:
              if (iVar8 == 4) break;
            }
          }
        }
        else if (0.0 <= local_58[2] * fVar6 + fVar4 * local_58[0] + local_58[1] * fVar5) {
          if (iVar8 == 1) break;
          if (iVar13 != 1) goto LAB_00099c3c;
          if (iVar8 == 2) break;
LAB_00099c70:
          if (0.0 <= local_38 * fVar6 + local_40 * fVar4 + local_3c * fVar5) {
            if (iVar8 == 3) break;
            if (iVar13 != 3) goto LAB_00099ca4;
            if (iVar8 != 5) goto LAB_00099de0;
LAB_00099cd4:
            if (0.0 <= fStack_20 * fVar6 + local_28 * fVar4 + local_24 * fVar5) break;
          }
        }
        iVar13 = iVar13 + 1;
        pfVar15 = pfVar15 + 3;
      } while (iVar13 != iVar8);
      if (iVar8 == iVar13) {
        if (iVar8 != 2) {
          return uVar14;
        }
        CrossProduct(local_58,local_58 + 3,&local_e0);
        VectorScale(&local_e0,
                    fStack_d8 * (ent->v).velocity[2] +
                    local_dc * (ent->v).velocity[1] + local_e0 * (ent->v).velocity[0],
                    (ent->v).velocity);
        fVar4 = (ent->v).velocity[0];
        fVar5 = (ent->v).velocity[1];
        fVar6 = (ent->v).velocity[2];
      }
      else {
LAB_00099d52:
        (ent->v).velocity[0] = fVar4;
        (ent->v).velocity[1] = fVar5;
        (ent->v).velocity[2] = fVar6;
      }
      vVar11 = vec3_origin[2];
      vVar10 = vec3_origin[1];
      if (fVar3 * fVar6 + fVar1 * fVar4 + fVar2 * fVar5 <= 0.0) {
        (ent->v).velocity[0] = vec3_origin[0];
        (ent->v).velocity[1] = vVar10;
        (ent->v).velocity[2] = vVar11;
        return uVar14;
      }
    }
    local_130 = local_130 + -1;
    local_148 = iVar8;
    if (local_130 == 0) {
      return uVar14;
    }
  } while( true );
}


// SV_ForceFullClientsUpdate  @ 000a1c80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ForceFullClientsUpdate(void)

{
  client_t *pcVar1;
  int iVar2;
  client_s *cl;
  int iVar3;
  int in_GS_OFFSET;
  sizebuf_t local_2424;
  byte local_2410 [9216];
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: uchar[9216] data@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&local_2424,0,0x14);
  local_2424.buffername = "Force Update";
  local_2424.data = local_2410;
  local_2424.cursize = 0;
  local_2424.maxsize = 0x2400;
  pcVar1 = host_client;
  if (0 < svs.maxclients) {
    iVar3 = 0;
    iVar2 = svs.maxclients;
    cl = svs.clients;
    do {
      if ((((cl == pcVar1) || (cl->active != false)) || (cl->connected != false)) ||
         (cl->spawned != false)) {
        SV_FullClientUpdate(cl,&local_2424);
        pcVar1 = host_client;
        iVar2 = svs.maxclients;
      }
      iVar3 = iVar3 + 1;
      cl = cl + 1;
    } while (iVar3 < iVar2);
  }
  Con_DPrintf("Client %s started recording. Send full update.\n",pcVar1->name);
  Netchan_CreateFragments(true,&host_client->netchan,&local_2424);
  Netchan_FragSend(&host_client->netchan);
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_Frame  @ 00094400
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Frame(void)

{
  float fVar1;
  qboolean qVar2;
  int iVar3;
  client_s *pcVar4;
  int iVar5;
  
  if (sv.active == false) {
    return;
  }
  gGlobalVariables.frametime = (float)host_frametime;
  sv.oldtime = sv.time;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: float dif@[???] */
  qVar2 = Host_IsSinglePlayerGame();
  if (qVar2 == false) {
    SV_CheckCmdTimes();
  }
  SV_ReadPackets();
  if ((sv.paused == false) &&
     ((1 < svs.maxclients ||
      ((key_dest == key_game && ((cls.state == ca_active || (cls.state == ca_dedicated)))))))) {
    SV_Physics();
    sv.time = sv.time + host_frametime;
  }
  SV_QueryMovevarsChanged();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: float droptime@[???] */
  iVar5 = 0;
  SV_RequestMissingResourcesFromClients();
  fVar1 = (float)realtime - sv_timeout.value;
  iVar3 = svs.maxclients;
  pcVar4 = svs.clients;
  if (0 < svs.maxclients) {
    do {
      while ((pcVar4->fakeclient != false ||
             ((((pcVar4->connected == false && (pcVar4->active == false)) &&
               (pcVar4->spawned == false)) || (fVar1 <= (pcVar4->netchan).last_received))))) {
        iVar5 = iVar5 + 1;
        pcVar4 = pcVar4 + 1;
        if (iVar3 <= iVar5) goto LAB_0009451a;
      }
      iVar5 = iVar5 + 1;
      SV_BroadcastPrintf("%s timed out\n",pcVar4->name);
      SV_DropClient(pcVar4,false,"Timed out");
      iVar3 = svs.maxclients;
      pcVar4 = pcVar4 + 1;
    } while (iVar5 < svs.maxclients);
  }
LAB_0009451a:
  SV_SendClientMessages();
  iVar3 = svs.maxclients;
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???] */
  if ((5.0 <= realtime - SV_CheckMapDifferences::lastcheck) &&
     (SV_CheckMapDifferences::lastcheck = realtime, 0 < svs.maxclients)) {
    iVar5 = 0;
    pcVar4 = svs.clients;
    do {
      if (((pcVar4->active != false) && (pcVar4->crcValue != 0)) &&
         (((pcVar4->netchan).remote_address.type != NA_LOOPBACK &&
          (pcVar4->crcValue != sv.worldmapCRC)))) {
        (pcVar4->netchan).message.flags = (pcVar4->netchan).message.flags | 2;
      }
      iVar5 = iVar5 + 1;
      pcVar4 = pcVar4 + 1;
    } while (iVar5 != iVar3);
  }
  SV_GatherStatistics();
  Steam_RunFrame();
  return;
}


// SV_FullClientUpdate  @ 000899d0
void SV_FullClientUpdate(client_t *cl,sizebuf_t *sb)

{
  int iVar1;
  int in_GS_OFFSET;
  uchar local_188 [16];
  MD5Context_t local_178;
  char local_120 [255];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] info@[???]
                       Unresolved local var: char[16] digest@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (int)cl - (int)svs.clients;
  Q_strncpy(local_120,cl->userinfo,0xff);
  local_21 = 0;
  Info_RemovePrefixedKeys(local_120,'_');
  MSG_WriteByte(sb,0xd);
  MSG_WriteByte(sb,(iVar1 >> 3) * 0x4ffec005);
  MSG_WriteLong(sb,cl->userid);
  MSG_WriteString(sb,local_120);
  MD5Init(&local_178);
  MD5Update(&local_178,(uchar *)cl->hashedcdkey,0x40);
  MD5Final(local_188,&local_178);
  MSG_WriteBuf(sb,0x10,local_188);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_FullUpdate_Internal  @ 000a3880
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SV_FullUpdate_Internal(void)

{
  float fVar1;
  double dVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  if (host_client->active == false) {
    Con_DPrintf("%s is trying to fullupdate when not active at (%f)\n",host_client->name,sv.time);
    return 0;
  }
                    /* Unresolved local var: int entIndex@[???]
                       Unresolved local var: float ltime@[???] */
  iVar3 = IndexOfEdict(host_client->edict);
  dVar2 = sv.time;
  lVar4 = (longdouble)s_LastFullUpdate[iVar3];
  lVar5 = (longdouble)sv.time;
  if (lVar5 < lVar4) {
    lVar4 = (longdouble)0;
    s_LastFullUpdate[iVar3] = 0.0;
  }
  fVar1 = (float)(lVar5 - lVar4);
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  else if (0.45 <= fVar1) goto LAB_000a3904;
  if ((longdouble)0.45 < lVar5) {
    Con_DPrintf("%s is spamming fullupdate: (%f) (%f) (%f)\n",host_client->name,dVar2,(double)lVar4,
                (double)fVar1);
    return 0;
  }
LAB_000a3904:
  s_LastFullUpdate[iVar3] = (float)dVar2;
  SV_ForceFullClientsUpdate();
  return 1;
}


// SV_FullUpdate_f  @ 000a3770
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_FullUpdate_f(void)

{
  float fVar1;
  double dVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  if (cmd_source == src_command) {
    Cmd_ForwardToServer();
    return;
  }
  if (host_client->active == false) {
    Con_DPrintf("%s is trying to fullupdate when not active at (%f)\n",host_client->name,sv.time);
  }
  else {
                    /* Unresolved local var: int entIndex@[???]
                       Unresolved local var: float ltime@[???] */
    iVar3 = IndexOfEdict(host_client->edict);
    dVar2 = sv.time;
    lVar4 = (longdouble)s_LastFullUpdate[iVar3];
    lVar5 = (longdouble)sv.time;
    if (lVar5 < lVar4) {
      lVar4 = (longdouble)0;
      s_LastFullUpdate[iVar3] = 0.0;
    }
    fVar1 = (float)(lVar5 - lVar4);
    if (fVar1 <= 0.0) {
      fVar1 = 0.0;
    }
    else if (0.45 <= fVar1) goto LAB_000a37f4;
    if (lVar5 <= (longdouble)0.45) {
LAB_000a37f4:
      s_LastFullUpdate[iVar3] = (float)dVar2;
      SV_ForceFullClientsUpdate();
      (*gEntityInterface.pfnClientCommand)(sv_player);
      return;
    }
    Con_DPrintf("%s is spamming fullupdate: (%f) (%f) (%f)\n",host_client->name,dVar2,(double)lVar4,
                (double)fVar1);
  }
  return;
}


// SV_GatherStatistics  @ 00081b40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_GatherStatistics(void)

{
  float fVar1;
  float fVar2;
  client_s *pcVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int players@[???]
                       Unresolved local var: float occup@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: float v@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (svs.next_cleartime < realtime) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
    if (svs.maxclients < 1) {
      iVar5 = 0;
    }
    else {
      iVar4 = 0;
      iVar5 = 0;
      pcVar3 = svs.clients;
      do {
        if (((pcVar3->active != false) || (pcVar3->spawned != false)) ||
           (pcVar3->connected != false)) {
          iVar5 = iVar5 + 1;
        }
        iVar4 = iVar4 + 1;
        pcVar3 = pcVar3 + 1;
      } while (svs.maxclients != iVar4);
    }
    svs.next_cleartime = realtime + 3600.0;
    Q_memset(&svs.stats,0,0x38);
    svs.stats.maxusers = iVar5;
    svs.stats.minusers = iVar5;
    return;
  }
  if (realtime < svs.next_sampletime) {
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  svs.stats.num_samples = svs.stats.num_samples + 1;
  svs.next_sampletime = realtime + 60.0;
  if (svs.maxclients < 1) {
    fVar1 = 0.0;
    iVar5 = 0;
  }
  else {
    iVar4 = 0;
    iVar5 = 0;
    pcVar3 = svs.clients;
    do {
      if (((pcVar3->active != false) || (pcVar3->spawned != false)) || (pcVar3->connected != false))
      {
        iVar5 = iVar5 + 1;
      }
      iVar4 = iVar4 + 1;
      pcVar3 = pcVar3 + 1;
    } while (iVar4 != svs.maxclients);
    fVar1 = (float)iVar5 * 100.0;
  }
  svs.stats.cumulative_occupancy = fVar1 / (float)svs.maxclients + svs.stats.cumulative_occupancy;
  if (0 < svs.stats.num_samples) {
    svs.stats.occupancy = svs.stats.cumulative_occupancy / (float)svs.stats.num_samples;
  }
  iVar4 = iVar5;
  if ((svs.stats.minusers <= iVar5) && (iVar4 = svs.stats.minusers, svs.stats.maxusers < iVar5)) {
    svs.stats.maxusers = iVar5;
  }
  svs.stats.minusers = iVar4;
  if (svs.maxclients + -1 <= iVar5) {
    svs.stats.at_capacity = svs.stats.at_capacity + 1;
  }
  if (iVar5 < 2) {
    svs.stats.at_empty = svs.stats.at_empty + 1;
  }
  if (svs.stats.num_samples < 1) {
    if (svs.maxclients < 1) {
      svs.stats.cumulative_latency = svs.stats.cumulative_latency + 0.0;
      goto LAB_00081d90;
    }
LAB_00081d0c:
    fVar1 = 0.0;
    iVar5 = 0;
    iVar4 = 0;
    pcVar3 = svs.clients;
    do {
      if ((pcVar3->active != false) && (pcVar3->fakeclient == false)) {
        fVar1 = fVar1 + pcVar3->latency;
        iVar5 = iVar5 + 1;
      }
      iVar4 = iVar4 + 1;
      pcVar3 = pcVar3 + 1;
    } while (iVar4 != svs.maxclients);
    fVar2 = 0.0;
    if (iVar5 != 0) {
      fVar2 = fVar1 / (float)iVar5;
    }
    svs.stats.cumulative_latency = fVar2 + svs.stats.cumulative_latency;
    if (svs.stats.num_samples < 1) goto LAB_00081d90;
  }
  else {
    svs.stats.capacity_percent =
         ((float)svs.stats.at_capacity * 100.0) / (float)svs.stats.num_samples;
    svs.stats.empty_percent = ((float)svs.stats.at_empty * 100.0) / (float)svs.stats.num_samples;
    if (0 < svs.maxclients) goto LAB_00081d0c;
    svs.stats.cumulative_latency = svs.stats.cumulative_latency + 0.0;
  }
  svs.stats.average_latency = svs.stats.cumulative_latency / (float)svs.stats.num_samples;
LAB_00081d90:
  if (svs.stats.num_sessions < 1) {
    return;
  }
  svs.stats.average_session_len = svs.stats.cumulative_sessiontime / (float)svs.stats.num_sessions;
  return;
}


// SV_GetClientIDString  @ 00092e80
char * SV_GetClientIDString(client_t *client)

{
  uint64 *puVar1;
  int iVar2;
  char *pcVar3;
  TSteamGlobalUserID_conflict local_18 [2];
  
  SV_GetClientIDString::idstr._0_4_ = SV_GetClientIDString::idstr._0_4_ & 0xffffff00;
  if (client == (client_t *)0x0) {
    return SV_GetClientIDString::idstr;
  }
  iVar2 = (client->network_userid).idtype;
  if (((client->netchan).remote_address.type == NA_LOOPBACK) && (iVar2 == 2)) {
    builtin_strncpy(SV_GetClientIDString::idstr,"VALVE_ID_LOOPBACK",0x12);
    return SV_GetClientIDString::idstr;
  }
                    /* Unresolved local var: USERID_t * id@[???] */
  SV_GetIDString::idstr._0_4_ = SV_GetIDString::idstr._0_4_ & 0xffffff00;
  if (iVar2 == 2) {
    if (sv_lan.value != 0.0) {
      builtin_strncpy(SV_GetIDString::idstr,"VALVE_ID_LAN",0xc);
      SV_GetIDString::idstr._12_4_ = (uint)(uint3)SV_GetIDString::idstr._13_3_ << 8;
      goto LAB_00092ed2;
    }
    puVar1 = &(client->network_userid).m_SteamID;
    if (*(int *)((int)&(client->network_userid).m_SteamID + 4) == 0 && (int)*puVar1 == 0) {
      builtin_strncpy(SV_GetIDString::idstr,"VALVE_ID_PENDING",0x11);
      goto LAB_00092ed2;
    }
    Steam_Steam3IDtoSteam2(local_18,*puVar1);
    pcVar3 = "VALVE_%u:%u:%u";
  }
  else {
    if (iVar2 == 3) {
      builtin_strncpy(SV_GetIDString::idstr,"HLTV",4);
      SV_GetIDString::idstr._4_4_ = SV_GetIDString::idstr._4_4_ & 0xffffff00;
      goto LAB_00092ed2;
    }
    if (iVar2 != 1) {
      builtin_strncpy(SV_GetIDString::idstr,"UNKNOWN",8);
      goto LAB_00092ed2;
    }
    if (sv_lan.value != 0.0) {
      builtin_strncpy(SV_GetIDString::idstr,"STEAM_ID_LAN",0xc);
      SV_GetIDString::idstr._12_4_ = (uint)(uint3)SV_GetIDString::idstr._13_3_ << 8;
      goto LAB_00092ed2;
    }
    puVar1 = &(client->network_userid).m_SteamID;
    if (*(int *)((int)&(client->network_userid).m_SteamID + 4) == 0 && (int)*puVar1 == 0) {
      builtin_strncpy(SV_GetIDString::idstr,"STEAM_ID_PENDING",0x11);
      goto LAB_00092ed2;
    }
                    /* Unresolved local var: TSteamGlobalUserID steam2ID@[???] */
    Steam_Steam3IDtoSteam2(local_18,*puVar1);
    pcVar3 = "STEAM_%u:%u:%u";
  }
                    /* Unresolved local var: TSteamGlobalUserID steam2ID@[???] */
  __snprintf_chk(SV_GetIDString::idstr,0x3f,1,0x40,pcVar3,local_18[0].m_SteamInstanceID,
                 local_18[0].m_SteamLocalUserID._4_4_,local_18[0].m_SteamLocalUserID._0_4_);
  SV_GetIDString::idstr[0x3f] = '\0';
LAB_00092ed2:
  snprintf(SV_GetClientIDString::idstr,0x3f,"%s",SV_GetIDString::idstr);
  return SV_GetClientIDString::idstr;
}


// SV_GetFakeClientCount  @ 00086a90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SV_GetFakeClientCount(void)

{
  qboolean qVar1;
  int iVar2;
  qboolean *pqVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int fakeclients@[???] */
  if (0 < svs.maxclients) {
    pqVar3 = &(svs.clients)->fakeclient;
    iVar2 = 0;
    do {
      qVar1 = *pqVar3;
      pqVar3 = pqVar3 + 0x199a;
      iVar2 = (iVar2 + 1) - (uint)(qVar1 == false);
    } while (pqVar3 != &svs.clients[svs.maxclients].fakeclient);
    return iVar2;
  }
  return 0;
}


// SV_GetFileNameModuleC  @ 000795f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * SV_GetFileNameModuleC(void)

{
  int in_GS_OFFSET;
  undefined1 local_128;
  undefined1 local_127;
  undefined1 local_126;
  undefined1 local_125;
  undefined1 local_124;
  undefined1 local_123;
  undefined1 local_122;
  undefined1 local_121;
  undefined1 local_120;
  undefined1 local_11f;
  undefined1 local_11e;
  undefined1 local_11d;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char[260] gamedir@[???]
                       Unresolved local var: char[20] szModule@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_128 = 0x4d;
  local_127 = 0x6f;
  local_126 = 100;
  local_125 = 0x75;
  local_124 = 0x6c;
  local_123 = 0x65;
  local_122 = 0x43;
  local_121 = 0x2e;
  local_120 = 100;
  local_11f = 0x6c;
  local_11e = 0x6c;
  local_11d = 0;
  COM_FileBase(com_gamedir,local_114);
  __snprintf_chk(SV_GetFileNameModuleC::moduleFileName,0x103,1,0x104,"%s/%s",local_114,&local_128);
  SV_GetFileNameModuleC::moduleFileName[0x103] = '\0';
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return SV_GetFileNameModuleC::moduleFileName;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_GetFileNameModuleS  @ 00079550
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * SV_GetFileNameModuleS(void)

{
  int in_GS_OFFSET;
  char local_12c [24];
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char[260] gamedir@[???]
                       Unresolved local var: char[20] szModule@[???] */
  builtin_strncpy(local_12c,"ModuleS_i386.so",0x10);
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  COM_FileBase(com_gamedir,local_114);
  __snprintf_chk(SV_GetFileNameModuleS::moduleFileName,0x103,1,0x104,"%s/%s",local_114,local_12c);
  SV_GetFileNameModuleS::moduleFileName[0x103] = '\0';
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return SV_GetFileNameModuleS::moduleFileName;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_GetFragmentSize  @ 00080670
int SV_GetFragmentSize(void *state)

{
  char *str;
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: client_t * cl@[???] */
  iVar2 = 0x400;
  if ((((*(int *)state != 0) && (*(int *)((int)state + 4) != 0)) &&
      (*(int *)((int)state + 0xc) != 0)) && (*(int *)((int)state + 8) != 0)) {
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: char * val@[???] */
    iVar2 = 0x100;
    str = Info_ValueForKey((char *)((int)state + 0x6210),"cl_dlmax");
    iVar1 = Q_strlen(str);
    if (iVar1 != 0) {
      iVar1 = Q_atoi(str);
      if (0xff < iVar1) {
        iVar2 = iVar1;
      }
      if (0x400 < iVar2) {
        iVar2 = 0x400;
      }
    }
  }
  return iVar2;
}


// SV_GetIDString  @ 00091f70
char * SV_GetIDString(USERID_t *id)

{
  int iVar1;
  char *pcVar2;
  TSteamGlobalUserID_conflict local_18 [2];
  
  SV_GetIDString::idstr._0_4_ = SV_GetIDString::idstr._0_4_ & 0xffffff00;
  if (id != (USERID_t *)0x0) {
    iVar1 = id->idtype;
    if (iVar1 == 2) {
      if (sv_lan.value == 0.0) {
        if (*(int *)((int)&id->m_SteamID + 4) != 0 || (int)id->m_SteamID != 0) {
                    /* Unresolved local var: TSteamGlobalUserID steam2ID@[???] */
          Steam_Steam3IDtoSteam2(local_18,id->m_SteamID);
          pcVar2 = "VALVE_%u:%u:%u";
LAB_000920d9:
          __snprintf_chk(SV_GetIDString::idstr,0x3f,1,0x40,pcVar2,local_18[0].m_SteamInstanceID,
                         local_18[0].m_SteamLocalUserID._4_4_,local_18[0].m_SteamLocalUserID._0_4_);
          SV_GetIDString::idstr[0x3f] = '\0';
          return SV_GetIDString::idstr;
        }
        builtin_strncpy(SV_GetIDString::idstr,"VALVE_ID_PENDING",0x11);
      }
      else {
        builtin_strncpy(SV_GetIDString::idstr,"VALVE_ID_LAN",0xc);
        SV_GetIDString::idstr._12_4_ = (uint)(uint3)SV_GetIDString::idstr._13_3_ << 8;
      }
    }
    else {
      if (iVar1 == 3) {
        builtin_strncpy(SV_GetIDString::idstr,"HLTV",4);
        SV_GetIDString::idstr._4_4_ = SV_GetIDString::idstr._4_4_ & 0xffffff00;
        return SV_GetIDString::idstr;
      }
      if (iVar1 == 1) {
        if (sv_lan.value == 0.0) {
          if (*(int *)((int)&id->m_SteamID + 4) != 0 || (int)id->m_SteamID != 0) {
                    /* Unresolved local var: TSteamGlobalUserID steam2ID@[???] */
            Steam_Steam3IDtoSteam2(local_18,id->m_SteamID);
            pcVar2 = "STEAM_%u:%u:%u";
            goto LAB_000920d9;
          }
          builtin_strncpy(SV_GetIDString::idstr,"STEAM_ID_PENDING",0x11);
        }
        else {
          builtin_strncpy(SV_GetIDString::idstr,"STEAM_ID_LAN",0xc);
          SV_GetIDString::idstr._12_4_ = (uint)(uint3)SV_GetIDString::idstr._13_3_ << 8;
        }
      }
      else {
        builtin_strncpy(SV_GetIDString::idstr,"UNKNOWN",8);
      }
    }
  }
  return SV_GetIDString::idstr;
}


// SV_GetModInfo  @ 00086ae0
qboolean SV_GetModInfo(char *pszInfo,char *pszDL,int *version,int *size,qboolean *svonly,
                      qboolean *cldll,char *pszHLVersion)

{
  if (gmodinfo.bIsMod == false) {
    Q_strcpy(pszInfo,"");
    Q_strcpy(pszDL,"");
    Q_strcpy(pszHLVersion,"");
    *version = 1;
    *size = 0;
    *svonly = true;
    *cldll = false;
    return gmodinfo.bIsMod;
  }
  Q_strcpy(pszInfo,gmodinfo.szInfo);
  Q_strcpy(pszDL,gmodinfo.szDL);
  Q_strcpy(pszHLVersion,gmodinfo.szHLVersion);
  *version = gmodinfo.version;
  *size = gmodinfo.size;
  *svonly = gmodinfo.svonly;
  *cldll = gmodinfo.cldll;
  return gmodinfo.bIsMod;
}


// SV_GetNetInfo  @ 0008b4e0
void SV_GetNetInfo(client_t *client,int *ping,int *packet_loss)

{
  float fVar1;
  int iVar2;
  client_frame_t *pcVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
                    /* Unresolved local var: int i@[???] */
  iVar5 = (int)client - (int)svs.clients >> 3;
  if (realtime < client->nextping) {
    uVar6 = (uint)SV_GetNetInfo::lastloss[iVar5 * 0x4ffec005];
    uVar8 = (uint)SV_GetNetInfo::lastping[iVar5 * -0x30013ffb];
    goto LAB_0008b570;
  }
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int idx@[???] */
  client->nextping = realtime + 2.0;
  if (client->fakeclient == false) {
    if (SV_UPDATE_BACKUP < 0x20) {
      iVar9 = SV_UPDATE_BACKUP / 2;
      if (iVar9 < 1) goto LAB_0008b550;
    }
    else {
      iVar9 = 0x10;
    }
    iVar2 = (client->netchan).incoming_acknowledged;
    pcVar3 = client->frames;
    if (pcVar3[iVar2 - 1U & SV_UPDATE_MASK].ping_time <= 0.0) {
      if (iVar9 != 1) {
        fVar1 = 0.0;
        iVar7 = 0;
        goto LAB_0008b5d5;
      }
      goto LAB_0008b550;
    }
    iVar7 = 1;
    fVar1 = pcVar3[iVar2 - 1U & SV_UPDATE_MASK].ping_time + 0.0;
    if (iVar9 != 1) {
LAB_0008b5d5:
      if (pcVar3[iVar2 - 2U & SV_UPDATE_MASK].ping_time <= 0.0) {
        if (iVar9 != 2) goto LAB_0008b5fe;
      }
      else {
        iVar7 = iVar7 + 1;
        fVar1 = pcVar3[iVar2 - 2U & SV_UPDATE_MASK].ping_time + fVar1;
        if (iVar9 == 2) goto LAB_0008b850;
LAB_0008b5fe:
        if (pcVar3[iVar2 - 3U & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 3) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 3U & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 3) goto LAB_0008b850;
        }
        if (pcVar3[iVar2 - 4U & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 4) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 4U & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 4) goto LAB_0008b850;
        }
        if (pcVar3[iVar2 - 5U & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 5) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 5U & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 5) goto LAB_0008b850;
        }
        if (pcVar3[iVar2 - 6U & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 6) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 6U & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 6) goto LAB_0008b850;
        }
        if (pcVar3[iVar2 - 7U & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 7) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 7U & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 7) goto LAB_0008b850;
        }
        if (pcVar3[iVar2 - 8U & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 8) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 8U & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 8) goto LAB_0008b850;
        }
        if (pcVar3[iVar2 - 9U & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 9) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 9U & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 9) goto LAB_0008b850;
        }
        if (pcVar3[iVar2 - 10U & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 10) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 10U & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 10) goto LAB_0008b850;
        }
        if (pcVar3[iVar2 - 0xbU & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 0xb) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 0xbU & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 0xb) goto LAB_0008b850;
        }
        if (pcVar3[iVar2 - 0xcU & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 0xc) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 0xcU & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 0xc) goto LAB_0008b850;
        }
        if (pcVar3[iVar2 - 0xdU & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 0xd) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 0xdU & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 0xd) goto LAB_0008b850;
        }
        if (pcVar3[iVar2 - 0xeU & SV_UPDATE_MASK].ping_time <= 0.0) {
          if (iVar9 == 0xe) goto LAB_0008b840;
        }
        else {
          iVar7 = iVar7 + 1;
          fVar1 = pcVar3[iVar2 - 0xeU & SV_UPDATE_MASK].ping_time + fVar1;
          if (iVar9 == 0xe) goto LAB_0008b850;
        }
        if (0.0 < pcVar3[iVar2 - 0xfU & SV_UPDATE_MASK].ping_time) {
          fVar1 = pcVar3[iVar2 - 0xfU & SV_UPDATE_MASK].ping_time + fVar1;
          iVar7 = iVar7 + 1;
        }
        if ((iVar9 == 0x10) && (0.0 < pcVar3[SV_UPDATE_MASK & iVar2 - 0x10U].ping_time)) {
          fVar1 = pcVar3[SV_UPDATE_MASK & iVar2 - 0x10U].ping_time + fVar1;
          iVar7 = iVar7 + 1;
        }
      }
LAB_0008b840:
      if (iVar7 == 0) goto LAB_0008b550;
    }
LAB_0008b850:
    if (fVar1 / (float)iVar7 < 0.0) goto LAB_0008b550;
    uVar6 = (uint)((fVar1 / (float)iVar7) * 1000.0);
    uVar8 = uVar6 & 0xffff;
    uVar4 = (ushort)uVar6;
  }
  else {
LAB_0008b550:
                    /* Unresolved local var: float ping@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: int back@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int idx@[???] */
    uVar8 = 0;
    uVar4 = 0;
  }
  fVar1 = client->packet_loss;
  SV_GetNetInfo::lastping[iVar5 * -0x30013ffb] = uVar4;
  SV_GetNetInfo::lastloss[iVar5 * 0x4ffec005] = (byte)(int)fVar1;
  uVar6 = (int)fVar1 & 0xff;
LAB_0008b570:
  *ping = uVar8;
  *packet_loss = uVar6;
  return;
}


// SV_GetPlayerHulls  @ 000579b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_GetPlayerHulls(void)

{
  int iVar1;
  int iVar2;
  vec_t (*pavVar3) [3];
  vec_t (*pavVar4) [3];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iResult@[DW_OP_reg0(EAX)] */
  pavVar4 = player_mins;
  pavVar3 = player_maxs;
  iVar2 = 0;
  do {
    iVar1 = (*gEntityInterface.pfnGetHullBounds)(iVar2,*pavVar4,*pavVar3);
    if (iVar1 == 0) {
      return;
    }
    iVar2 = iVar2 + 1;
    pavVar4 = pavVar4 + 1;
    pavVar3 = pavVar3 + 1;
  } while (iVar2 != 4);
  return;
}


// SV_GetTrueMinMax  @ 000a2a60
void SV_GetTrueMinMax(int player,float **fmin,float **fmax)

{
  if (((((host_client->lw != 0) && (host_client->lc != 0)) && (sv_unlag.value != 0.0)) &&
      ((1 < svs.maxclients && (player < svs.maxclients && -1 < player)))) &&
     ((host_client->active != false &&
      ((truepositions[player].active != 0 && (truepositions[player].needrelink != 0)))))) {
    *fmin = truepositions[player].oldabsmin;
    *fmax = truepositions[player].oldabsmax;
  }
  return;
}


// SV_GetTrueOrigin  @ 000a29a0
void SV_GetTrueOrigin(int player,vec_t *origin)

{
  if (((((host_client->lw != 0) && (host_client->lc != 0)) && (sv_unlag.value != 0.0)) &&
      ((1 < svs.maxclients && (player < svs.maxclients && -1 < player)))) &&
     ((host_client->active != false &&
      ((truepositions[player].active != 0 && (truepositions[player].needrelink != 0)))))) {
    *origin = truepositions[player].oldorg[0];
    origin[1] = truepositions[player].oldorg[1];
    origin[2] = truepositions[player].oldorg[2];
  }
  return;
}


// SV_HandleRconPacket  @ 00090a90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_HandleRconPacket(void)

{
  char *pcVar1;
  int iVar2;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: char * c@[???] */
  MSG_BeginReading();
  MSG_ReadLong();
  pcVar1 = MSG_ReadStringLine();
  Cmd_TokenizeString(pcVar1);
  pcVar1 = Cmd_Argv(0);
  iVar2 = Q_strcmp(pcVar1,"getchallenge");
  if (iVar2 == 0) {
    SVC_GetChallenge();
    return;
  }
  iVar2 = Q_stricmp(pcVar1,"challenge");
  if (iVar2 != 0) {
    iVar2 = Q_strcmp(pcVar1,"rcon");
    if (iVar2 == 0) {
      SV_Rcon(&net_from);
    }
    return;
  }
  SVC_ServiceChallenge();
  return;
}


// SV_HasEventsInQueue  @ 0008b4a0
qboolean SV_HasEventsInQueue(client_t *client)

{
  event_state_t *peVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: event_state_t * es@[???]
                       Unresolved local var: event_info_t * ei@[???] */
  if (client != (client_t *)0x0) {
    peVar1 = &client->events;
    do {
      if (peVar1->ei[0].index != 0) {
        return true;
      }
      peVar1 = (event_state_t *)(peVar1->ei + 1);
    } while (peVar1 != (event_state_t *)&client->edict);
  }
  return false;
}


// SV_HashString  @ 000822d0
int SV_HashString(char *string,int iBounds)

{
  char cVar1;
  __int32_t **pp_Var2;
  uint uVar3;
  int iVar4;
  
                    /* Unresolved local var: uint hash@[???] */
  cVar1 = *string;
  if (cVar1 == '\0') {
    uVar3 = 0;
  }
  else {
    pp_Var2 = __ctype_tolower_loc();
    uVar3 = 0;
    do {
      iVar4 = (int)cVar1;
      string = string + 1;
      cVar1 = *string;
      uVar3 = (*pp_Var2)[iVar4] + uVar3 * 2;
    } while (cVar1 != '\0');
    uVar3 = uVar3 % (uint)iBounds;
  }
  return uVar3;
}


// SV_HitgroupForStudioHull  @ 00077dc0
int SV_HitgroupForStudioHull(int index)

{
  return studio_hull_hitgroup[index];
}


// SV_HullForBeam  @ 000a8440
hull_t * SV_HullForBeam(vec_t *start,vec_t *end,vec_t *size)

{
  vec_t local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t tmp@[???] */
  beam_planes[0].normal[0] = *end - *start;
  beam_planes[0].normal[1] = end[1] - start[1];
  beam_planes[0].normal[2] = end[2] - start[2];
  VectorNormalize(beam_planes[0].normal);
  beam_planes[1].normal[0] = beam_planes[0].normal[0];
  beam_planes[1].normal[1] = beam_planes[0].normal[1];
  beam_planes[1].normal[2] = beam_planes[0].normal[2];
  beam_planes[0].dist =
       end[2] * beam_planes[0].normal[2] +
       end[1] * beam_planes[0].normal[1] + *end * beam_planes[0].normal[0];
  beam_planes[1].dist =
       start[2] * beam_planes[0].normal[2] +
       beam_planes[0].normal[1] * start[1] + beam_planes[0].normal[0] * *start;
  if (ABS(beam_planes[0].normal[2]) < 0.9) {
    local_10 = 1.0;
    local_18 = 0.0;
  }
  else {
    local_18 = 1.0;
    local_10 = 0.0;
  }
  local_14 = 0.0;
  CrossProduct(beam_planes[0].normal,&local_18,beam_planes[2].normal);
  VectorNormalize(beam_planes[2].normal);
  beam_planes[3].normal[0] = beam_planes[2].normal[0];
  beam_planes[3].normal[1] = beam_planes[2].normal[1];
  beam_planes[3].normal[2] = beam_planes[2].normal[2];
  beam_planes[2].dist =
       (start[2] + beam_planes[2].normal[2]) * beam_planes[2].normal[2] +
       (start[1] + beam_planes[2].normal[1]) * beam_planes[2].normal[1] +
       (*start + beam_planes[2].normal[0]) * beam_planes[2].normal[0];
  local_18 = *start - beam_planes[2].normal[0];
  local_14 = start[1] - beam_planes[2].normal[1];
  local_10 = start[2] - beam_planes[2].normal[2];
  beam_planes[3].dist =
       beam_planes[2].normal[0] * local_18 + local_14 * beam_planes[2].normal[1] +
       beam_planes[2].normal[2] * local_10;
  CrossProduct(beam_planes[2].normal,beam_planes[0].normal,beam_planes[4].normal);
  VectorNormalize(beam_planes[4].normal);
  beam_planes[5].normal[0] = beam_planes[4].normal[0];
  beam_planes[5].normal[1] = beam_planes[4].normal[1];
  beam_planes[5].normal[2] = beam_planes[4].normal[2];
  beam_planes[0].dist =
       ABS(beam_planes[0].normal[2] * size[2]) +
       ABS(beam_planes[0].normal[1] * size[1]) + ABS(beam_planes[0].normal[0] * *size) +
       beam_planes[0].dist;
  beam_planes[1].dist =
       beam_planes[1].dist -
       (ABS(beam_planes[1].normal[2] * size[2]) +
       ABS(beam_planes[1].normal[1] * size[1]) + ABS(beam_planes[1].normal[0] * *size));
  beam_planes[2].dist =
       ABS(beam_planes[2].normal[2] * size[2]) +
       ABS(beam_planes[2].normal[1] * size[1]) + ABS(beam_planes[2].normal[0] * *size) +
       beam_planes[2].dist;
  beam_planes[3].dist =
       beam_planes[3].dist -
       (ABS(beam_planes[3].normal[2] * size[2]) +
       ABS(beam_planes[3].normal[1] * size[1]) + ABS(beam_planes[3].normal[0] * *size));
  beam_planes[4].dist =
       ABS(size[2] * beam_planes[4].normal[2]) +
       ABS(size[1] * beam_planes[4].normal[1]) + ABS(*size * beam_planes[4].normal[0]) +
       (start[2] + beam_planes[4].normal[2]) * beam_planes[4].normal[2] +
       (start[1] + beam_planes[4].normal[1]) * beam_planes[4].normal[1] +
       (*start + beam_planes[4].normal[0]) * beam_planes[4].normal[0];
  beam_planes[5].dist =
       ((start[2] - beam_planes[4].normal[2]) * beam_planes[4].normal[2] +
       (start[1] - beam_planes[4].normal[1]) * beam_planes[4].normal[1] +
       (*start - beam_planes[4].normal[0]) * beam_planes[4].normal[0]) -
       (ABS(beam_planes[4].normal[2] * size[2]) +
       ABS(beam_planes[4].normal[1] * size[1]) + ABS(beam_planes[4].normal[0] * *size));
  return &beam_hull;
}


// SV_HullForBox  @ 000a83e0
hull_t * SV_HullForBox(vec_t *mins,vec_t *maxs)

{
  box_planes[0].dist = *maxs;
  box_planes[1].dist = *mins;
  box_planes[2].dist = maxs[1];
  box_planes[3].dist = mins[1];
  box_planes[4].dist = maxs[2];
  box_planes[5].dist = mins[2];
  return &box_hull;
}


// SV_HullForBsp  @ 000a8760
hull_s * SV_HullForBsp(edict_t *ent,vec_t *mins,vec_t *maxs,vec_t *offset)

{
  float fVar1;
  float fVar2;
  float fVar3;
  model_s *pmVar4;
  hull_s *phVar5;
  
                    /* Unresolved local var: model_t * model@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: vec3_t size@[???] */
  pmVar4 = sv.models[(ent->v).modelindex];
  if (pmVar4 == (model_s *)0x0) {
    Sys_Error("Hit a %s with no model (%s)",pr_strings + (ent->v).classname,
              pr_strings + (ent->v).model);
  }
  else if (pmVar4->type == mod_brush) goto LAB_000a879f;
  Sys_Error("Hit a %s with no model (%s)",pr_strings + (ent->v).classname,
            pr_strings + (ent->v).model);
  Sys_Error("MOVETYPE_PUSH with a non bsp model");
LAB_000a879f:
  fVar1 = *maxs - *mins;
  if (fVar1 <= 8.0) {
    fVar1 = pmVar4->hulls[0].clip_mins[0];
    phVar5 = pmVar4->hulls;
    *offset = fVar1;
    fVar2 = pmVar4->hulls[0].clip_mins[1];
    offset[1] = fVar2;
    fVar3 = pmVar4->hulls[0].clip_mins[2];
    offset[2] = fVar3;
  }
  else {
    if (fVar1 <= 36.0) {
      phVar5 = pmVar4->hulls + 3;
      if (36.0 < maxs[2] - mins[2]) {
        phVar5 = pmVar4->hulls + 1;
      }
    }
    else {
      phVar5 = pmVar4->hulls + 2;
    }
    fVar1 = phVar5->clip_mins[0] - *mins;
    *offset = fVar1;
    fVar2 = phVar5->clip_mins[1] - mins[1];
    offset[1] = fVar2;
    fVar3 = phVar5->clip_mins[2] - mins[2];
    offset[2] = fVar3;
  }
  *offset = fVar1 + (ent->v).origin[0];
  offset[1] = fVar2 + (ent->v).origin[1];
  offset[2] = fVar3 + (ent->v).origin[2];
  return phVar5;
}


// SV_HullForEntity  @ 000a88f0
hull_t * SV_HullForEntity(edict_t *ent,vec_t *mins,vec_t *maxs,vec_t *offset)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  model_s *pmVar5;
  hull_t *phVar6;
  
                    /* Unresolved local var: vec3_t hullmins@[???]
                       Unresolved local var: vec3_t hullmaxs@[???]
                       Unresolved local var: hull_t * hull@[???] */
  if ((ent->v).solid != 4) {
    box_planes[1].dist = (ent->v).mins[0] - *maxs;
    box_planes[3].dist = (ent->v).mins[1] - maxs[1];
    box_planes[5].dist = (ent->v).mins[2] - maxs[2];
    box_planes[2].dist = (ent->v).maxs[1] - mins[1];
    box_planes[4].dist = (ent->v).maxs[2] - mins[2];
    box_planes[0].dist = (ent->v).maxs[0] - *mins;
    *offset = (ent->v).origin[0];
    offset[1] = (ent->v).origin[1];
    offset[2] = (ent->v).origin[2];
    return &box_hull;
  }
  iVar4 = (ent->v).movetype;
  if ((iVar4 != 7) && (iVar4 != 0xd)) {
    Sys_Error("SOLID_BSP without MOVETYPE_PUSH");
  }
                    /* Unresolved local var: model_t * model@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: vec3_t size@[???] */
  pmVar5 = sv.models[(ent->v).modelindex];
  if (pmVar5 == (model_s *)0x0) {
    Sys_Error("Hit a %s with no model (%s)",pr_strings + (ent->v).classname,
              pr_strings + (ent->v).model);
  }
  else if (pmVar5->type == mod_brush) goto LAB_000a8a35;
  Sys_Error("Hit a %s with no model (%s)",pr_strings + (ent->v).classname,
            pr_strings + (ent->v).model);
  Sys_Error("MOVETYPE_PUSH with a non bsp model");
LAB_000a8a35:
  fVar1 = *maxs - *mins;
  if (fVar1 <= 8.0) {
    fVar1 = pmVar5->hulls[0].clip_mins[0];
    phVar6 = pmVar5->hulls;
    *offset = fVar1;
    fVar2 = pmVar5->hulls[0].clip_mins[1];
    offset[1] = fVar2;
    fVar3 = pmVar5->hulls[0].clip_mins[2];
    offset[2] = fVar3;
  }
  else {
    if (36.0 < fVar1) {
      phVar6 = pmVar5->hulls + 2;
    }
    else {
      phVar6 = pmVar5->hulls + 3;
      if (36.0 < maxs[2] - mins[2]) {
        phVar6 = pmVar5->hulls + 1;
      }
    }
    fVar1 = phVar6->clip_mins[0] - *mins;
    *offset = fVar1;
    fVar2 = phVar6->clip_mins[1] - mins[1];
    offset[1] = fVar2;
    fVar3 = phVar6->clip_mins[2] - mins[2];
    offset[2] = fVar3;
  }
  *offset = fVar1 + (ent->v).origin[0];
  offset[1] = fVar2 + (ent->v).origin[1];
  offset[2] = fVar3 + (ent->v).origin[2];
  return phVar6;
}


// SV_HullForStudioModel  @ 00077fa0
hull_t * SV_HullForStudioModel(edict_t *pEdict,vec_t *mins,vec_t *maxs,vec_t *offset,int *pNumHulls)

{
  float fVar1;
  float fVar2;
  float fVar3;
  vec_t scale;
  bool bVar4;
  bool bVar5;
  int iVar6;
  hull_t *phVar7;
  int iVar8;
  int in_GS_OFFSET;
  uint local_5c;
  byte local_3e [2];
  vec_t local_3c;
  float local_38;
  float local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  byte local_24 [4];
  int local_20;
  
                    /* Unresolved local var: qboolean useComplexHull@[???]
                       Unresolved local var: vec3_t size@[???]
                       Unresolved local var: float factor@[???]
                       Unresolved local var: int bSkipShield@[???] */
  local_3c = *maxs - *mins;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_38 = maxs[1] - mins[1];
  local_34 = maxs[2] - mins[2];
  iVar6 = VectorCompare(vec3_origin,&local_3c);
  if ((iVar6 == 0) || (((byte)gGlobalVariables.trace_flags & 1) != 0)) {
LAB_00078030:
    bVar4 = false;
    scale = 0.5;
    bVar5 = false;
    if ((pEdict->v).gamestate == 1) goto LAB_000782e0;
    local_5c = 0;
LAB_0007804b:
    if (((sv.models[(pEdict->v).modelindex]->flags & 0x200) == 0) && (!bVar4)) {
      *pNumHulls = 1;
      phVar7 = SV_HullForEntity(pEdict,mins,maxs,offset);
      goto LAB_0007815f;
    }
  }
  else {
    if (((pEdict->v).flags & 8) == 0) {
      scale = 0.5;
    }
    else {
      if (sv_clienttrace.value == 0.0) goto LAB_00078030;
      scale = sv_clienttrace.value * 0.5;
      local_34 = 1.0;
      local_38 = 1.0;
      local_3c = 1.0;
    }
    if ((pEdict->v).gamestate == 1) {
      bVar5 = true;
LAB_000782e0:
      bVar4 = bVar5;
      if ((g_bIsTerrorStrike == 1) || (g_bIsCStrike == 1)) {
        local_5c = 1;
      }
      else {
        local_5c = (uint)(g_bIsCZero == 1);
      }
      goto LAB_0007804b;
    }
    local_5c = 0;
  }
  VectorScale(&local_3c,scale,&local_3c);
  *offset = 0.0;
  offset[1] = 0.0;
  offset[2] = 0.0;
  if (((pEdict->v).flags & 8) == 0) {
    phVar7 = R_StudioHull(sv.models[(pEdict->v).modelindex],(pEdict->v).frame,(pEdict->v).sequence,
                          (pEdict->v).angles,(pEdict->v).origin,&local_3c,(pEdict->v).controller,
                          (pEdict->v).blending,pNumHulls,pEdict,local_5c);
  }
  else {
                    /* Unresolved local var: vec3_t angles@[???]
                       Unresolved local var: int iBlend@[???]
                       Unresolved local var: byte[2] blending@[???]
                       Unresolved local var: byte[4] controller@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
    pstudiohdr = Mod_Extradata(sv.models[(pEdict->v).modelindex]);
    iVar6 = (pEdict->v).sequence;
    local_2c = (pEdict->v).angles[1];
    local_28 = (pEdict->v).angles[2];
    local_30 = (pEdict->v).angles[0];
    iVar8 = iVar6 * 0xb0 + pstudiohdr->seqindex;
    fVar3 = (float)(int)(local_30 * 3.0);
    fVar1 = *(float *)((int)pstudiohdr->bbmax + iVar8 + 0xc);
    if (fVar3 < fVar1) {
      local_3e[0] = '\0';
      local_30 = local_30 - fVar1 / 3.0;
    }
    else {
      fVar2 = *(float *)((int)pstudiohdr->bbmax + iVar8 + 0x14);
      if (fVar2 < fVar3) {
        local_3e[0] = 0xff;
        local_30 = local_30 - fVar2 / 3.0;
      }
      else {
        local_3e[0] = '\x7f';
        if (0.1 <= fVar2 - fVar1) {
          local_3e[0] = (byte)(int)(((fVar3 - fVar1) * 255.0) / (fVar2 - fVar1));
        }
        local_30 = 0.0;
      }
    }
    local_3e[1] = 0;
    local_24[0] = '\x7f';
    local_24[1] = 0x7f;
    local_24[2] = 0x7f;
    local_24[3] = 0x7f;
    phVar7 = R_StudioHull(sv.models[(pEdict->v).modelindex],(pEdict->v).frame,iVar6,&local_30,
                          (pEdict->v).origin,&local_3c,local_24,local_3e,pNumHulls,pEdict,local_5c);
  }
LAB_0007815f:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return phVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_HullPointContents  @ 000a9e50
int SV_HullPointContents(hull_t *hull,int num,vec_t *p)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  float fVar3;
  
  while (-1 < num) {
    if ((num < hull->firstclipnode) || (hull->lastclipnode < num)) {
      Sys_Error("SV_HullPointContents: bad node number");
    }
    pdVar1 = hull->clipnodes + num;
    pmVar2 = hull->planes + pdVar1->planenum;
    if (pmVar2->type < 3) {
      fVar3 = p[pmVar2->type] - pmVar2->dist;
    }
    else {
      fVar3 = (pmVar2->normal[2] * p[2] + pmVar2->normal[1] * p[1] + pmVar2->normal[0] * *p) -
              pmVar2->dist;
    }
    if (fVar3 < 0.0) {
      num = (int)pdVar1->children[1];
    }
    else {
      num = (int)pdVar1->children[0];
    }
  }
  return num;
}


// SV_IgnoreHLTV  @ 0009fb10
void SV_IgnoreHLTV(client_t *cl)

{
  return;
}


// SV_Impact  @ 000995a0
void SV_Impact(edict_t *e1,edict_t *e2,trace_t *ptrace)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  gGlobalVariables.time = (float)sv.time;
  if ((((e1->v).flags | (e2->v).flags) & 0x40000000U) != 0) {
    return;
  }
  uVar1 = (e1->v).groupinfo;
  if ((uVar1 != 0) && (uVar2 = (e2->v).groupinfo, uVar2 != 0)) {
    if (g_groupop == 0) {
      if ((uVar1 & uVar2) == 0) {
        return;
      }
    }
    else if ((g_groupop == 1) && ((uVar1 & uVar2) != 0)) {
      return;
    }
  }
  if ((e1->v).solid == 0) {
    iVar3 = (e2->v).solid;
  }
  else {
    SV_SetGlobalTrace(ptrace);
    (*gEntityInterface.pfnTouch)(e1,e2);
    iVar3 = (e2->v).solid;
  }
  if (iVar3 == 0) {
    return;
  }
  SV_SetGlobalTrace(ptrace);
                    /* WARNING: Could not recover jumptable at 0x00099647. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEntityInterface.pfnTouch)(e2,e1);
  return;
}


// SV_InactivateClients  @ 00090030
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InactivateClients(void)

{
  char *dest;
  int iVar1;
  client_s *cl;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (0 < svs.maxclients) {
    iVar2 = 0;
    iVar1 = svs.maxclients;
    cl = svs.clients;
    do {
      while (((cl->active != false || (cl->connected != false)) || (cl->spawned != false))) {
        if (cl->fakeclient != false) {
          SV_DropClient(cl,false,"Dropping fakeclient on level change");
          iVar1 = svs.maxclients;
          break;
        }
        iVar2 = iVar2 + 1;
        cl->m_bSentNewResponse = false;
        cl->active = false;
        cl->connected = true;
        cl->spawned = false;
        cl->fully_connected = false;
        cl->hasusrmsgs = false;
        SZ_Clear(&(cl->netchan).message);
        SZ_Clear(&cl->datagram);
        COM_ClearCustomizationList(&cl->customdata,false);
        dest = cl->physinfo;
        cl = cl + 1;
        Q_memset(dest,0,0x100);
        iVar1 = svs.maxclients;
        if (svs.maxclients <= iVar2) {
          return;
        }
      }
      iVar2 = iVar2 + 1;
      cl = cl + 1;
    } while (iVar2 < iVar1);
  }
  return;
}


// SV_Init  @ 00091680
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Init(void)

{
  int iVar1;
  client_frame_t *pcVar2;
  int iVar3;
  undefined4 *p;
  client_s *pcVar4;
  char (*pacVar5) [5];
  uchar *dest;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???] */
  Cmd_AddCommand("banid",SV_BanId_f);
  Cmd_AddCommand("removeid",SV_RemoveId_f);
  Cmd_AddCommand("listid",SV_ListId_f);
  Cmd_AddCommand("writeid",SV_WriteId_f);
  Cmd_AddCommand("resetrcon",SV_ResetRcon_f);
  Cmd_AddCommand("logaddress",SV_SetLogAddress_f);
  Cmd_AddCommand("logaddress_add",SV_AddLogAddress_f);
  Cmd_AddCommand("logaddress_del",SV_DelLogAddress_f);
  Cmd_AddCommand("log",SV_ServerLog_f);
  Cmd_AddCommand("serverinfo",SV_Serverinfo_f);
  Cmd_AddCommand("localinfo",SV_Localinfo_f);
  Cmd_AddCommand("showinfo",SV_ShowServerinfo_f);
  Cmd_AddCommand("user",SV_User_f);
  Cmd_AddCommand("users",SV_Users_f);
  Cmd_AddCommand("dlfile",SV_BeginFileDownload_f);
  Cmd_AddCommand("addip",SV_AddIP_f);
  Cmd_AddCommand("removeip",SV_RemoveIP_f);
  Cmd_AddCommand("listip",SV_ListIP_f);
  Cmd_AddCommand("writeip",SV_WriteIP_f);
  Cmd_AddCommand("dropclient",SV_Drop_f);
  Cmd_AddCommand("spawn",SV_Spawn_f);
  Cmd_AddCommand("new",SV_New_f);
  Cmd_AddCommand("sendres",SV_SendRes_f);
  Cmd_AddCommand("sendents",SV_SendEnts_f);
  Cmd_AddCommand("fullupdate",SV_FullUpdate_f);
  Cvar_RegisterVariable(&sv_failuretime);
  Cvar_RegisterVariable(&sv_voiceenable);
  Cvar_RegisterVariable(&rcon_password);
  Cvar_RegisterVariable(&sv_enableoldqueries);
  Cvar_RegisterVariable(&mp_consistency);
  Cvar_RegisterVariable(&sv_instancedbaseline);
  Cvar_RegisterVariable(&sv_contact);
  Cvar_RegisterVariable(&sv_unlag);
  Cvar_RegisterVariable(&sv_maxunlag);
  Cvar_RegisterVariable(&sv_unlagpush);
  Cvar_RegisterVariable(&sv_unlagsamples);
  Cvar_RegisterVariable(&sv_filterban);
  Cvar_RegisterVariable(&sv_maxupdaterate);
  Cvar_RegisterVariable(&sv_minupdaterate);
  Cvar_RegisterVariable(&sv_logrelay);
  Cvar_RegisterVariable(&sv_lan);
  iVar1 = PF_IsDedicatedServer();
  if (iVar1 == 0) {
    Cvar_DirectSet(&sv_lan,"1");
  }
  else {
    Cvar_DirectSet(&sv_lan,"0");
  }
  Cvar_RegisterVariable(&sv_lan_rate);
  Cvar_RegisterVariable(&sv_proxies);
  Cvar_RegisterVariable(&sv_outofdatetime);
  Cvar_RegisterVariable(&sv_allow_shaders);
  Cvar_RegisterVariable(&sv_visiblemaxplayers);
  Cvar_RegisterVariable(&sv_password);
  Cvar_RegisterVariable(&sv_aim);
  Cvar_RegisterVariable(&sv_allow_autoaim);
  Cvar_RegisterVariable(&violence_hblood);
  Cvar_RegisterVariable(&violence_ablood);
  Cvar_RegisterVariable(&violence_hgibs);
  Cvar_RegisterVariable(&violence_agibs);
  Cvar_RegisterVariable(&sv_newunit);
  Cvar_RegisterVariable(&sv_gravity);
  Cvar_RegisterVariable(&sv_friction);
  Cvar_RegisterVariable(&sv_edgefriction);
  Cvar_RegisterVariable(&sv_stopspeed);
  Cvar_RegisterVariable(&sv_maxspeed);
  Cvar_RegisterVariable(&sv_footsteps);
  Cvar_RegisterVariable(&sv_accelerate);
  Cvar_RegisterVariable(&sv_rollangle);
  Cvar_RegisterVariable(&sv_rollspeed);
  Cvar_RegisterVariable(&sv_stepsize);
  Cvar_RegisterVariable(&sv_bounce);
  Cvar_RegisterVariable(&sv_airaccelerate);
  Cvar_RegisterVariable(&sv_wateraccelerate);
  Cvar_RegisterVariable(&sv_waterfriction);
  Cvar_RegisterVariable(&sv_skycolor_r);
  Cvar_RegisterVariable(&sv_skycolor_g);
  Cvar_RegisterVariable(&sv_skycolor_b);
  Cvar_RegisterVariable(&sv_skyvec_x);
  Cvar_RegisterVariable(&sv_skyvec_y);
  Cvar_RegisterVariable(&sv_skyvec_z);
  Cvar_RegisterVariable(&sv_timeout);
  Cvar_RegisterVariable(&sv_clienttrace);
  Cvar_RegisterVariable(&sv_zmax);
  Cvar_RegisterVariable(&sv_wateramp);
  Cvar_RegisterVariable(&sv_skyname);
  Cvar_RegisterVariable(&sv_maxvelocity);
  Cvar_RegisterVariable(&sv_cheats);
  Cvar_HookVariable(sv_cheats.name,&sv_cheats_hook);
  iVar1 = COM_CheckParm("-dev");
  if (iVar1 != 0) {
    Cvar_SetValue("sv_cheats",1.0);
  }
  Cvar_RegisterVariable(&sv_spectatormaxspeed);
  Cvar_RegisterVariable(&sv_allow_download);
  Cvar_RegisterVariable(&sv_allow_upload);
  Cvar_RegisterVariable(&sv_max_upload);
  Cvar_RegisterVariable(&sv_max_upload_count);
  Cvar_RegisterVariable(&sv_send_logos);
  Cvar_RegisterVariable(&sv_send_resources);
  Cvar_RegisterVariable(&sv_logbans);
  Cvar_RegisterVariable(&hpk_maxsize);
  Cvar_RegisterVariable(&mapcyclefile);
  Cvar_HookVariable(mapcyclefile.name,&mapcyclefile_hook);
  Cvar_RegisterVariable(&motdfile);
  Cvar_RegisterVariable(&servercfgfile);
  Cvar_RegisterVariable(&mapchangecfgfile);
  Cvar_RegisterVariable(&disconcfgfile);
  Cvar_RegisterVariable(&lservercfgfile);
  Cvar_RegisterVariable(&logsdir);
  Cvar_RegisterVariable(&bannedcfgfile);
  Cvar_RegisterVariable(&sv_rcon_minfailures);
  Cvar_RegisterVariable(&sv_rcon_maxfailures);
  Cvar_RegisterVariable(&sv_rcon_minfailuretime);
  Cvar_RegisterVariable(&sv_rcon_banpenalty);
  Cvar_RegisterVariable(&sv_minrate);
  Cvar_RegisterVariable(&sv_maxrate);
  Cvar_RegisterVariable(&max_queries_sec);
  Cvar_RegisterVariable(&max_queries_sec_global);
  Cvar_RegisterVariable(&max_queries_window);
  Cvar_RegisterVariable(&sv_logblocks);
  Cvar_RegisterVariable(&sv_downloadurl);
  Cvar_RegisterVariable(&sv_version);
  Cvar_RegisterVariable(&sv_allow_dlfile);
  Cvar_RegisterVariable(&sv_use_steam_networking);
  Cvar_RegisterVariable(&ui_cmd_on_connect);
  Cvar_RegisterVariable(&_sv_override_scientist_mdl);
  iVar1 = 0;
  pacVar5 = localmodels;
  do {
    iVar3 = iVar1 + 1;
    __snprintf_chk(pacVar5,5,1,0xffffffff,&DAT_000d51fd,iVar1);
    iVar1 = iVar3;
    pacVar5 = pacVar5 + 1;
  } while (iVar3 != 0x200);
  iVar1 = 0;
  svs.isSecure = false;
  local_20 = 0;
  if (0 < svs.maxclientslimit) {
    do {
      dest = ((svs.clients)->netchan).remote_address.ip + iVar1 + -0x24;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_frame_t * pframe@[???] */
      p = *(undefined4 **)(dest + 0x4bf0);
      if (p != (undefined4 *)0x0) {
        if (0 < SV_UPDATE_BACKUP) {
          iVar3 = 0;
          do {
                    /* Unresolved local var: packet_entities_t * pack@[???] */
            if (p != (undefined4 *)0x0) {
              if ((void *)p[0x61b] != (void *)0x0) {
                Mem_Free((void *)p[0x61b]);
              }
              p[0x61b] = 0;
              p[0x5fa] = 0;
            }
            *p = 0;
            iVar3 = iVar3 + 1;
            p[1] = 0;
            p[2] = 0xbf800000;
            p = p + 0x61c;
          } while (iVar3 < SV_UPDATE_BACKUP);
          p = *(undefined4 **)(dest + 0x4bf0);
        }
        Mem_Free(p);
        *(undefined4 *)(dest + 0x4bf0) = 0;
      }
      iVar1 = iVar1 + 0x6668;
      Q_memset(dest,0,0x6668);
      local_20 = local_20 + 1;
      *(int *)(dest + 0x6408) = (int)dest + 0x6384;
      *(int *)(dest + 0x6404) = (int)dest + 0x6384;
      *(int *)(dest + 0x6490) = (int)dest + 0x640c;
      *(int *)(dest + 0x648c) = (int)dest + 0x640c;
    } while (local_20 < svs.maxclientslimit);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  PM_Init(&g_svmove);
  if (0 < svs.maxclientslimit) {
    iVar1 = 0;
    pcVar4 = svs.clients;
    do {
      if (pcVar4->frames != (client_frame_t *)0x0) {
        Con_DPrintf("Allocating over frame pointer?\n");
      }
      iVar1 = iVar1 + 1;
      pcVar2 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0x1870);
      pcVar4->frames = pcVar2;
      pcVar4 = pcVar4 + 1;
    } while (iVar1 < svs.maxclientslimit);
  }
  SV_InitDeltas();
  return;
}


// SV_InitBoxHull  @ 000a8240
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InitBoxHull(void)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???] */
  box_hull.clipnodes = box_clipnodes;
  box_hull.planes = box_planes;
  box_hull.firstclipnode = 0;
  box_hull.lastclipnode = 5;
  uVar1 = 0;
  do {
    uVar2 = uVar1 + 4;
    *(undefined4 *)((int)beam_hull.clip_mins + (uVar1 - 0x10)) =
         *(undefined4 *)((int)box_hull.clip_mins + (uVar1 - 0x10));
    uVar1 = uVar2;
  } while (uVar2 < 0x28);
  beam_hull.planes = beam_planes;
  box_clipnodes[0].children[1] = 1;
  box_clipnodes[1].planenum = 1;
  box_clipnodes[1].children[1] = -1;
  box_clipnodes[1].children[0] = 2;
  box_clipnodes[2].planenum = 2;
  box_clipnodes[2].children[0] = -1;
  box_clipnodes[3].children[1] = -1;
  box_clipnodes[3].children[0] = 4;
  box_clipnodes[4].planenum = 4;
  box_clipnodes[0].planenum = 0;
  box_clipnodes[0].children[0] = -1;
  box_clipnodes[4].children[0] = -1;
  box_clipnodes[2].children[1] = 3;
  box_clipnodes[3].planenum = 3;
  box_clipnodes[4].children[1] = 5;
  box_planes[0].type = '\0';
  box_planes[0].normal[0] = 1.0;
  beam_planes[0].type = '\x05';
  box_planes[1].type = '\0';
  box_planes[1].normal[0] = 1.0;
  beam_planes[1].type = '\x05';
  box_planes[2].type = '\x01';
  box_planes[2].normal[1] = 1.0;
  beam_planes[2].type = '\x05';
  box_planes[3].type = '\x01';
  box_planes[3].normal[1] = 1.0;
  beam_planes[3].type = '\x05';
  box_planes[4].type = '\x02';
  box_planes[4].normal[2] = 1.0;
  beam_planes[4].type = '\x05';
  box_clipnodes[5].planenum = 5;
  box_clipnodes[5].children[1] = -1;
  box_clipnodes[5].children[0] = -2;
  box_planes[5].type = '\x02';
  box_planes[5].normal[2] = 1.0;
  beam_planes[5].type = '\x05';
  return;
}


// SV_InitDeltas  @ 00090fd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InitDeltas(void)

{
  qboolean qVar1;
  delta_info_t *pdVar2;
  char *pcVar3;
  int iVar4;
  delta_t *local_10 [2];
  
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  Con_DPrintf("Initializing deltas\n");
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("clientdata_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("clientdata_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("entity_state_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("entity_state_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("entity_state_player_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("entity_state_player_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("custom_entity_state_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("custom_entity_state_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("usercmd_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("usercmd_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("weapon_data_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("weapon_data_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10[0] = (delta_t *)0x0;
  qVar1 = DELTA_Load("event_t",local_10,"delta.lst");
  if (qVar1 == false) {
    Sys_Error("Error parsing %s!!!\n","delta.lst");
    pdVar2 = g_sv_delta;
  }
  else {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup("delta.lst");
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup("event_t");
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10[0];
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
  }
  for (; pdVar2 != (delta_info_t *)0x0; pdVar2 = pdVar2->next) {
                    /* Unresolved local var: delta_info_t * p@[???] */
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("entity_state_player_t",pcVar3);
    if (iVar4 == 0) {
      g_pplayerdelta = pdVar2->delta;
      pdVar2 = g_sv_delta;
      if (g_pplayerdelta == (delta_t *)0x0) goto LAB_000912fe;
      goto joined_r0x00091318;
    }
  }
  pcVar3 = "entity_state_player_t";
  Sys_Error("Couldn\'t find delta for %s\n","entity_state_player_t");
  g_pplayerdelta = (delta_t *)0x0;
LAB_000912fe:
  Sys_Error("No entity_state_player_t encoder on server!\n",pcVar3);
  pdVar2 = g_sv_delta;
joined_r0x00091318:
  do {
    if (pdVar2 == (delta_info_t *)0x0) break;
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("entity_state_t",pcVar3);
    if (iVar4 == 0) {
      g_pentitydelta = pdVar2->delta;
      pdVar2 = g_sv_delta;
      if (g_pentitydelta == (delta_t *)0x0) goto LAB_0009136c;
      goto joined_r0x00091388;
    }
    pdVar2 = pdVar2->next;
  } while( true );
  pcVar3 = "entity_state_t";
  Sys_Error("Couldn\'t find delta for %s\n","entity_state_t");
  g_pentitydelta = (delta_t *)0x0;
LAB_0009136c:
  Sys_Error("No entity_state_t encoder on server!\n",pcVar3);
  pdVar2 = g_sv_delta;
joined_r0x00091388:
  do {
    if (pdVar2 == (delta_info_t *)0x0) break;
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("custom_entity_state_t",pcVar3);
    if (iVar4 == 0) {
      g_pcustomentitydelta = pdVar2->delta;
      pdVar2 = g_sv_delta;
      if (g_pcustomentitydelta == (delta_t *)0x0) goto LAB_000913dc;
      goto joined_r0x000913f8;
    }
    pdVar2 = pdVar2->next;
  } while( true );
  pcVar3 = "custom_entity_state_t";
  Sys_Error("Couldn\'t find delta for %s\n","custom_entity_state_t");
  g_pcustomentitydelta = (delta_t *)0x0;
LAB_000913dc:
  Sys_Error("No custom_entity_state_t encoder on server!\n",pcVar3);
  pdVar2 = g_sv_delta;
joined_r0x000913f8:
  do {
    if (pdVar2 == (delta_info_t *)0x0) break;
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("clientdata_t",pcVar3);
    if (iVar4 == 0) {
      g_pclientdelta = pdVar2->delta;
      pdVar2 = g_sv_delta;
      if (g_pclientdelta == (delta_t *)0x0) goto LAB_0009144c;
      goto joined_r0x00091468;
    }
    pdVar2 = pdVar2->next;
  } while( true );
  pcVar3 = "clientdata_t";
  Sys_Error("Couldn\'t find delta for %s\n","clientdata_t");
  g_pclientdelta = (delta_t *)0x0;
LAB_0009144c:
  Sys_Error("No clientdata_t encoder on server!\n",pcVar3);
  pdVar2 = g_sv_delta;
joined_r0x00091468:
  do {
    if (pdVar2 == (delta_info_t *)0x0) break;
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("weapon_data_t",pcVar3);
    if (iVar4 == 0) {
      g_pweapondelta = pdVar2->delta;
      pdVar2 = g_sv_delta;
      if (g_pweapondelta == (delta_t *)0x0) goto LAB_000914bd;
      goto joined_r0x000914d8;
    }
    pdVar2 = pdVar2->next;
  } while( true );
  pcVar3 = "weapon_data_t";
  Sys_Error("Couldn\'t find delta for %s\n","weapon_data_t");
  g_pweapondelta = (delta_t *)0x0;
LAB_000914bd:
  Sys_Error("No weapon_data_t encoder on server!\n",pcVar3);
  pdVar2 = g_sv_delta;
joined_r0x000914d8:
  do {
    if (pdVar2 == (delta_info_t *)0x0) {
      pcVar3 = "event_t";
      Sys_Error("Couldn\'t find delta for %s\n","event_t");
      g_peventdelta = (delta_t *)0x0;
LAB_0009152d:
      Sys_Error("No event_t encoder on server!\n",pcVar3);
      return;
    }
    pcVar3 = pdVar2->name;
    iVar4 = Q_stricmp("event_t",pcVar3);
    if (iVar4 == 0) {
      g_peventdelta = pdVar2->delta;
      if (g_peventdelta != (delta_t *)0x0) {
        return;
      }
      goto LAB_0009152d;
    }
    pdVar2 = pdVar2->next;
  } while( true );
}


// SV_InitEncoders  @ 00091640
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InitEncoders(void)

{
  char *str;
  delta_t *pdVar1;
  delta_info_s *pdVar2;
  int iVar3;
  encoder_t p_Var4;
  
  for (pdVar2 = g_sv_delta; pdVar2 != (delta_info_t *)0x0; pdVar2 = pdVar2->next) {
    pdVar1 = pdVar2->delta;
    str = pdVar1->conditionalencodename;
    iVar3 = Q_strlen(str);
    if (0 < iVar3) {
      p_Var4 = DELTA_LookupEncoder(str);
      pdVar1->conditionalencode = p_Var4;
    }
  }
  return;
}


// SV_InitStudioHull  @ 000758e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InitStudioHull(void)

{
  hull_t *phVar1;
  hull_t *phVar2;
  mplane_t *pmVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???] */
  if (studio_hull[0].planes != (mplane_t *)0x0) {
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int side@[???] */
  studio_clipnodes[0].planenum = 0;
  studio_clipnodes[1].planenum = 1;
  studio_clipnodes[1].children[1] = -1;
  studio_clipnodes[1].children[0] = 2;
  studio_clipnodes[2].planenum = 2;
  studio_clipnodes[2].children[0] = -1;
  studio_clipnodes[2].children[1] = 3;
  studio_clipnodes[3].children[0] = 4;
  studio_clipnodes[4].planenum = 4;
  studio_clipnodes[4].children[0] = -1;
  studio_clipnodes[0].children[0] = -1;
  studio_clipnodes[4].children[1] = 5;
  studio_clipnodes[0].children[1] = 1;
  studio_clipnodes[3].planenum = 3;
  studio_clipnodes[5].planenum = 5;
  studio_clipnodes[5].children[1] = -1;
  studio_clipnodes[5].children[0] = -2;
  pmVar3 = studio_planes;
  studio_clipnodes[3].children[1] = -1;
  phVar1 = studio_hull;
  do {
    phVar1->planes = pmVar3;
    phVar2 = phVar1 + 1;
    pmVar3 = pmVar3 + 6;
    phVar1->clipnodes = studio_clipnodes;
    phVar1->firstclipnode = 0;
    phVar1->lastclipnode = 5;
    phVar1 = phVar2;
  } while (phVar2 != (hull_t *)studio_hull_hitgroup);
  return;
}


// SV_InvokeCallback  @ 000812d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_InvokeCallback(void)

{
  int *piVar1;
  int data;
  qboolean qVar2;
  qboolean qVar3;
  qboolean qVar4;
  int data_00;
  qboolean qVar5;
  int data_01;
  uint32 data_02;
  uint data_03;
  
  data_01 = g_svdeltacallback.offset;
  qVar5 = g_svdeltacallback.full;
  data_00 = g_svdeltacallback.newblindex;
  qVar4 = g_svdeltacallback.newbl;
  qVar3 = g_svdeltacallback.custom;
  qVar2 = g_svdeltacallback.remove;
  data = g_svdeltacallback.num;
  piVar1 = g_svdeltacallback.numbase;
                    /* Unresolved local var: int delta@[???] */
  data_02 = g_svdeltacallback.num - *g_svdeltacallback.numbase;
  if (g_svdeltacallback.full == false) {
    data_03 = (uint)(g_svdeltacallback.remove != false);
LAB_00081349:
    MSG_WriteBits(data_03,1);
    if (data_02 - 1 < 0x3f) {
      MSG_WriteBits(0,1);
      MSG_WriteBits(data_02,6);
      *piVar1 = data;
      goto joined_r0x000813c5;
    }
    MSG_WriteBits(1,1);
    MSG_WriteBits(data,0xb);
  }
  else {
    if (data_02 != 1) {
      data_03 = 0;
      goto LAB_00081349;
    }
    MSG_WriteBits(1,1);
  }
  *piVar1 = data;
joined_r0x000813c5:
  if (qVar2 == false) {
    MSG_WriteBits((uint)(qVar3 != false),1);
    if ((sv.instance_baselines)->number != 0) {
      if (qVar4 != false) {
        MSG_WriteBits(1,1);
        MSG_WriteBits(data_00,6);
        return;
      }
      MSG_WriteBits(0,1);
    }
    if ((qVar5 != false) && (qVar4 == false)) {
      if (data_01 == 0) {
        MSG_WriteBits(0,1);
      }
      else {
        MSG_WriteBits(1,1);
        MSG_WriteBits(data_01,6);
      }
    }
  }
  return;
}


// SV_IsPlayerIndex  @ 00081f60
qboolean SV_IsPlayerIndex(int index)

{
  if (0 < index) {
    return (uint)(index <= svs.maxclients);
  }
  return false;
}


// SV_IsSimulating  @ 00090e50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean SV_IsSimulating(void)

{
  qboolean qVar1;
  
  if (sv.paused != false) {
    return false;
  }
  if (svs.maxclients < 2) {
    qVar1 = false;
    if (key_dest == key_game) {
      return (uint)(cls.state == ca_dedicated || cls.state == ca_active);
    }
  }
  else {
    qVar1 = true;
  }
  return qVar1;
}


// SV_KickPlayer  @ 00092660
/* WARNING: Removing unreachable block (ram,0x000927b2) */

void SV_KickPlayer(int nPlayerSlot,int nReason)

{
  uchar *puVar1;
  client_s *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  undefined1 *puVar8;
  client_s *pcVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int in_GS_OFFSET;
  bool bVar13;
  USERID_t local_430;
  undefined4 local_420;
  undefined1 auStack_41c [1020];
  int local_20;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: USERID_t id@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char[1024] rgchT@[???] */
  pcVar9 = svs.clients;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((-1 < nPlayerSlot) && (nPlayerSlot < svs.maxclients)) {
    if ((svs.clients[nPlayerSlot].connected != false) && (svs.isSecure != false)) {
      local_430.idtype = svs.clients[nPlayerSlot].network_userid.idtype;
      pcVar2 = svs.clients + nPlayerSlot;
      local_430.m_SteamID._0_4_ = (undefined4)svs.clients[nPlayerSlot].network_userid.m_SteamID;
      local_430.m_SteamID._4_4_ =
           *(undefined4 *)((int)&svs.clients[nPlayerSlot].network_userid.m_SteamID + 4);
      local_430.clientip = svs.clients[nPlayerSlot].network_userid.clientip;
      pcVar3 = SV_GetIDString(&local_430);
      uVar11 = 0x173;
      Log_Printf("Secure: \"%s<%i><%s><>\" was detected cheating and dropped from the server.\n",
                 pcVar2->name,pcVar9[nPlayerSlot].userid,pcVar3,nReason);
      puVar8 = (undefined1 *)((int)&local_420 + 2);
      bVar13 = ((uint)puVar8 & 2) != 0;
      pcVar3 = 
      "********************************************\nYou have been automatically disconnected\nfrom this secure server because an illegal\ncheat was detected on your computer.\nRepeat violators may be permanently banned\nfrom all secure servers.\n\nFor help cleaning your system of cheats, visit:\nhttp://www.counter-strike.net/cheat.html\n********************************************\n\n"
      ;
      local_420._0_1_ = 8;
      local_420._1_1_ = 10;
      if (bVar13) {
        puVar8 = auStack_41c;
        pcVar3 = 
        "******************************************\nYou have been automatically disconnected\nfrom this secure server because an illegal\ncheat was detected on your computer.\nRepeat violators may be permanently banned\nfrom all secure servers.\n\nFor help cleaning your system of cheats, visit:\nhttp://www.counter-strike.net/cheat.html\n********************************************\n\n"
        ;
        uVar11 = 0x171;
        local_420._2_1_ = '*';
        local_420._3_1_ = '*';
      }
      uVar4 = 0;
      do {
        *(undefined4 *)(puVar8 + uVar4) = *(undefined4 *)(pcVar3 + uVar4);
        *(undefined4 *)(puVar8 + uVar4 + 4) = *(undefined4 *)(pcVar3 + uVar4 + 4);
        uVar4 = uVar4 + 8;
      } while (uVar4 < (uVar11 & 0xfffffff8));
      iVar5 = 0;
      if (!bVar13) {
        *(undefined2 *)(puVar8 + uVar4) = *(undefined2 *)(pcVar3 + uVar4);
        iVar5 = 2;
      }
      *(char *)((int)(puVar8 + uVar4) + iVar5) = (pcVar3 + uVar4)[iVar5];
      puVar7 = &local_420;
      do {
        puVar6 = puVar7;
        uVar4 = *puVar6 + 0xfefefeff & ~*puVar6;
        uVar11 = uVar4 & 0x80808080;
        puVar7 = puVar6 + 1;
      } while (uVar11 == 0);
      if ((uVar4 & 0x8080) == 0) {
        puVar7 = (uint *)((int)puVar6 + 6);
        uVar11 = uVar11 >> 0x10;
      }
      Netchan_Transmit(&svs.clients[nPlayerSlot].netchan,
                       (int)((int)puVar7 +
                            (-(int)&local_420 - (uint)CARRY1((byte)uVar11,(byte)uVar11)) + -2),
                       (byte *)&local_420);
      __snprintf_chk(&local_420,0x400,1,0x400,
                     "%s was automatically disconnected\nfrom this secure server.\n",
                     svs.clients[nPlayerSlot].name);
      pcVar9 = svs.clients;
      if (0 < svs.maxclients) {
        iVar12 = 0;
        iVar10 = 0;
        iVar5 = svs.maxclients;
        do {
          puVar1 = (pcVar9->netchan).remote_address.ip + iVar12 + -0x24;
          if (((*(int *)puVar1 != 0) || (*(int *)(puVar1 + 4) != 0)) &&
             (*(int *)(puVar1 + 0x33d8) == 0)) {
            MSG_WriteByte((sizebuf_t *)(puVar1 + 0x74),0x1a);
            MSG_WriteString((sizebuf_t *)(((svs.clients)->netchan).message_buf + iVar12 + -0x14),
                            (char *)&local_420);
            iVar5 = svs.maxclients;
            pcVar9 = svs.clients;
          }
          iVar10 = iVar10 + 1;
          iVar12 = iVar12 + 0x6668;
        } while (iVar10 < iVar5);
      }
      SV_DropClient(pcVar9 + nPlayerSlot,false,"Automatically dropped by cheat detector");
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_LinkContents  @ 000a9ee0
int SV_LinkContents(areanode_t *node,vec_t *pos)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  short sVar3;
  link_s *plVar4;
  link_s *plVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  link_s *plVar9;
  hull_s *phVar10;
  int iVar11;
  int iVar12;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [6];
  
                    /* Unresolved local var: link_t * l@[???]
                       Unresolved local var: link_t * next@[???]
                       Unresolved local var: edict_t * touch@[???]
                       Unresolved local var: int contents@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t localPosition@[???]
                       Unresolved local var: model_t * pModel@[???] */
  plVar4 = (node->solid_edicts).next;
joined_r0x000a9ef7:
  do {
    plVar9 = plVar4;
    if (plVar9 == &node->solid_edicts) {
      if (node->axis == -1) {
        return -1;
      }
      if (pos[node->axis] <= node->dist) {
        if (pos[node->axis] < node->dist) {
          iVar11 = SV_LinkContents(node->children[1],pos);
          return iVar11;
        }
        return -1;
      }
      iVar11 = SV_LinkContents(node->children[0],pos);
      return iVar11;
    }
    plVar4 = plVar9->next;
  } while (plVar9[0x30].next != (link_s *)0x0);
  plVar5 = plVar9[0x57].prev;
  if (plVar5 != (link_s *)0x0) {
    if (g_groupop == 0) {
      if ((g_groupmask & (uint)plVar5) == 0) goto joined_r0x000a9ef7;
    }
    else if ((g_groupop == 1) && ((g_groupmask & (uint)plVar5) != 0)) goto joined_r0x000a9ef7;
  }
  if (((((sv.models[(int)plVar9[0x25].next] != (model_s *)0x0) &&
        (sv.models[(int)plVar9[0x25].next]->type == mod_brush)) &&
       (*pos <= (float)plVar9[0x29].prev)) &&
      ((pos[1] <= (float)plVar9[0x29].next && (pos[2] <= (float)plVar9[0x2a].prev)))) &&
     (((float)plVar9[0x27].next <= *pos &&
      (((float)plVar9[0x28].prev <= pos[1] && ((float)plVar9[0x28].next <= pos[2])))))) {
    if ((link_s **)0xc8 < &plVar9[0x31].prev[0xc].next) {
      Con_DPrintf("Invalid contents on trigger field: %s\n",pr_strings + (int)plVar9[0xf].prev);
    }
    phVar10 = SV_HullForBsp((edict_t *)(plVar9 + -1),vec3_origin,vec3_origin,&local_34);
    fVar6 = *pos - local_34;
    iVar11 = phVar10->firstclipnode;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
    fVar7 = pos[1] - local_30;
    local_28[0] = fVar6;
    fVar8 = pos[2] - local_2c;
    local_28[1] = fVar7;
    local_28[2] = fVar8;
    iVar12 = iVar11;
    if (-1 < iVar11) {
      do {
        if ((iVar12 < iVar11) || (phVar10->lastclipnode < iVar12)) {
          Sys_Error("SV_HullPointContents: bad node number");
        }
        pdVar1 = phVar10->clipnodes + iVar12;
        pmVar2 = phVar10->planes + pdVar1->planenum;
        if (pmVar2->type < 3) {
          if (0.0 <= local_28[pmVar2->type] - pmVar2->dist) goto LAB_000aa07f;
LAB_000aa0e0:
          sVar3 = pdVar1->children[1];
        }
        else {
          if ((fVar8 * pmVar2->normal[2] + fVar7 * pmVar2->normal[1] + fVar6 * pmVar2->normal[0]) -
              pmVar2->dist < 0.0) goto LAB_000aa0e0;
LAB_000aa07f:
          sVar3 = pdVar1->children[0];
        }
        iVar12 = (int)sVar3;
        if (iVar12 < 0) break;
        iVar11 = phVar10->firstclipnode;
      } while( true );
    }
    if (iVar12 != -1) {
      return (int)plVar9[0x31].prev;
    }
  }
  goto joined_r0x000a9ef7;
}


// SV_LinkEdict  @ 000a9bd0
void SV_LinkEdict(edict_t *ent,qboolean touch_triggers)

{
  link_t *plVar1;
  link_s *plVar2;
  edict_t *peVar3;
  areanode_t *paVar4;
  int iVar5;
  int iVar6;
  int local_10 [3];
  
                    /* Unresolved local var: areanode_t * node@[???]
                       Unresolved local var: int topnode@[???] */
  plVar2 = (ent->area).prev;
  if (plVar2 != (link_s *)0x0) {
    ((ent->area).next)->prev = plVar2;
    ((ent->area).prev)->next = (ent->area).next;
    (ent->area).next = (link_s *)0x0;
    (ent->area).prev = (link_s *)0x0;
  }
  if ((ent != sv.edicts) && (ent->free == false)) {
    (*gEntityInterface.pfnSetAbsBox)(ent);
    if (((ent->v).movetype == 0xc) && (peVar3 = (ent->v).aiment, peVar3 != (edict_t *)0x0)) {
      ent->headnode = peVar3->headnode;
      ent->num_leafs = peVar3->num_leafs;
      Q_memcpy(ent->leafnums,peVar3->leafnums,0x60);
    }
    else {
      local_10[0] = -1;
      iVar5 = (ent->v).modelindex;
      ent->num_leafs = 0;
      ent->headnode = -1;
      if ((iVar5 != 0) &&
         (SV_FindTouchedLeafs(ent,(sv.worldmodel)->nodes,local_10), 0x30 < ent->num_leafs)) {
        ent->num_leafs = 0;
        ent->headnode = local_10[0];
        Q_memset(ent->leafnums,0xff,0x60);
      }
    }
    iVar5 = (ent->v).solid;
    if (iVar5 == 0) {
      if (-2 < (ent->v).skin) {
        return;
      }
    }
    else {
                    /* Unresolved local var: model_t * model@[???] */
      if ((iVar5 == 4) && (sv.models[(ent->v).modelindex] == (model_s *)0x0)) {
        iVar5 = Q_strlen(pr_strings + (ent->v).model);
        if (iVar5 == 0) {
          Con_DPrintf("Inserted %s with no model\n",pr_strings + (ent->v).classname);
          return;
        }
        iVar5 = (ent->v).solid;
      }
    }
    for (paVar4 = sv_areanodes; iVar6 = paVar4->axis, iVar6 != -1; paVar4 = paVar4->children[1]) {
      while( true ) {
        if ((ent->v).absmin[iVar6] <= paVar4->dist) break;
        paVar4 = paVar4->children[0];
        iVar6 = paVar4->axis;
        if (iVar6 == -1) goto LAB_000a9c97;
      }
      if (paVar4->dist <= (ent->v).absmax[iVar6]) break;
    }
LAB_000a9c97:
    plVar1 = &ent->area;
    if (iVar5 == 1) {
      (ent->area).next = &paVar4->trigger_edicts;
      plVar2 = (paVar4->trigger_edicts).prev;
      (ent->area).prev = plVar2;
      plVar2->next = plVar1;
      ((ent->area).next)->prev = plVar1;
    }
    else {
      (ent->area).next = &paVar4->solid_edicts;
      plVar2 = (paVar4->solid_edicts).prev;
      (ent->area).prev = plVar2;
      plVar2->next = plVar1;
      ((ent->area).next)->prev = plVar1;
    }
    if ((touch_triggers != false) && (SV_LinkEdict::iTouchLinkSemaphore == 0)) {
      SV_LinkEdict::iTouchLinkSemaphore = 1;
      SV_TouchLinks(ent,sv_areanodes);
      SV_LinkEdict::iTouchLinkSemaphore = 0;
    }
  }
  return;
}


// SV_ListIP_f  @ 000803b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ListIP_f(void)

{
  float *pfVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: byte[4] b@[???] */
  if (numipfilters < 1) {
    Con_Printf("IP filter list: empty\n");
    return;
  }
  Con_Printf("IP filter list:\n");
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: byte[4] b@[???] */
  if (0 < numipfilters) {
    puVar3 = &ipfilters[0].compare;
    iVar4 = 0;
    do {
      while( true ) {
        pfVar1 = (float *)(puVar3 + 2);
        uVar2 = *puVar3;
        if ((double)*pfVar1 != 0.0) break;
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 4;
        Con_Printf("%3i.%3i.%3i.%3i : permanent\n",uVar2 & 0xff,uVar2 >> 8 & 0xff,
                   uVar2 >> 0x10 & 0xff,uVar2 >> 0x18);
        if (numipfilters <= iVar4) {
          return;
        }
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 4;
      Con_Printf("%3i.%3i.%3i.%3i : %.3f min\n",uVar2 & 0xff,uVar2 >> 8 & 0xff,uVar2 >> 0x10 & 0xff,
                 uVar2 >> 0x18,(double)*pfVar1);
    } while (iVar4 < numipfilters);
  }
  return;
}


// SV_ListId_f  @ 00080db0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ListId_f(void)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  uint64 *puVar4;
  int iVar5;
  TSteamGlobalUserID_conflict local_28 [2];
  
                    /* Unresolved local var: int i@[???] */
  if (numuserfilters < 1) {
    Con_Printf("UserID filter list: empty\n");
    return;
  }
  Con_Printf("UserID filter list: %i entries\n",numuserfilters);
                    /* Unresolved local var: int i@[???] */
  if (0 < numuserfilters) {
    puVar4 = &userfilters[0].userid.m_SteamID;
                    /* Unresolved local var: TSteamGlobalUserID steam2ID@[???] */
    iVar5 = 1;
    do {
      while( true ) {
        fVar1 = *(float *)(puVar4 + 2);
        if ((double)fVar1 != 0.0) break;
        iVar2 = ((USERID_t *)((int)puVar4 + -4))->idtype;
        SV_GetIDString::idstr._0_4_ = (uint)(uint3)SV_GetIDString::idstr._1_3_ << 8;
        if (iVar2 == 2) {
          if (sv_lan.value == 0.0) {
            if (*(int *)((int)puVar4 + 4) == 0 && (int)*puVar4 == 0) {
              builtin_strncpy(SV_GetIDString::idstr,"VALVE_ID_PENDING",0x11);
            }
            else {
                    /* Unresolved local var: TSteamGlobalUserID steam2ID@[???] */
              Steam_Steam3IDtoSteam2(local_28,*puVar4);
LAB_00081145:
              __snprintf_chk(SV_GetIDString::idstr,0x3f,1,0x40);
              SV_GetIDString::idstr[0x3f] = '\0';
            }
          }
          else {
            builtin_strncpy(SV_GetIDString::idstr,"VALVE_ID_LAN",0xc);
            SV_GetIDString::idstr._12_4_ = (uint)(uint3)SV_GetIDString::idstr._13_3_ << 8;
          }
        }
        else if (iVar2 == 3) {
          builtin_strncpy(SV_GetIDString::idstr,"HLTV",4);
          SV_GetIDString::idstr._4_4_ = (uint)(uint3)SV_GetIDString::idstr._5_3_ << 8;
        }
        else if (iVar2 == 1) {
          if (sv_lan.value == 0.0) {
            if (*(int *)((int)puVar4 + 4) != 0 || (int)*puVar4 != 0) {
                    /* Unresolved local var: TSteamGlobalUserID steam2ID@[???] */
              Steam_Steam3IDtoSteam2(local_28,*puVar4);
              goto LAB_00081145;
            }
            builtin_strncpy(SV_GetIDString::idstr,"STEAM_ID_PENDING",0x11);
          }
          else {
            builtin_strncpy(SV_GetIDString::idstr,"STEAM_ID_LAN",0xc);
            SV_GetIDString::idstr._12_4_ = (uint)(uint3)SV_GetIDString::idstr._13_3_ << 8;
          }
        }
        else {
          builtin_strncpy(SV_GetIDString::idstr,"UNKNOWN",8);
        }
        puVar4 = puVar4 + 3;
        Con_Printf("%i %s : permanent\n",iVar5,SV_GetIDString::idstr);
        bVar3 = numuserfilters <= iVar5;
        iVar5 = iVar5 + 1;
        if (bVar3) {
          return;
        }
      }
      iVar2 = ((USERID_t *)((int)puVar4 + -4))->idtype;
      SV_GetIDString::idstr._0_4_ = (uint)(uint3)SV_GetIDString::idstr._1_3_ << 8;
      if (iVar2 == 2) {
        if (sv_lan.value == 0.0) {
          if (*(int *)((int)puVar4 + 4) == 0 && (int)*puVar4 == 0) {
            builtin_strncpy(SV_GetIDString::idstr,"VALVE_ID_PENDING",0x11);
          }
          else {
            Steam_Steam3IDtoSteam2(local_28,*puVar4);
LAB_000810d9:
            __snprintf_chk(SV_GetIDString::idstr,0x3f,1,0x40);
            SV_GetIDString::idstr[0x3f] = '\0';
          }
        }
        else {
          builtin_strncpy(SV_GetIDString::idstr,"VALVE_ID_LAN",0xc);
          SV_GetIDString::idstr._12_4_ = (uint)(uint3)SV_GetIDString::idstr._13_3_ << 8;
        }
      }
      else if (iVar2 == 3) {
        builtin_strncpy(SV_GetIDString::idstr,"HLTV",4);
        SV_GetIDString::idstr._4_4_ = (uint)(uint3)SV_GetIDString::idstr._5_3_ << 8;
      }
      else if (iVar2 == 1) {
        if (sv_lan.value == 0.0) {
          if (*(int *)((int)puVar4 + 4) != 0 || (int)*puVar4 != 0) {
                    /* Unresolved local var: TSteamGlobalUserID steam2ID@[???] */
            Steam_Steam3IDtoSteam2(local_28,*puVar4);
            goto LAB_000810d9;
          }
          builtin_strncpy(SV_GetIDString::idstr,"STEAM_ID_PENDING",0x11);
        }
        else {
          builtin_strncpy(SV_GetIDString::idstr,"STEAM_ID_LAN",0xc);
          SV_GetIDString::idstr._12_4_ = (uint)(uint3)SV_GetIDString::idstr._13_3_ << 8;
        }
      }
      else {
        builtin_strncpy(SV_GetIDString::idstr,"UNKNOWN",8);
      }
      puVar4 = puVar4 + 3;
      Con_Printf("%i %s : %.3f min\n",iVar5,SV_GetIDString::idstr,(double)fVar1);
      bVar3 = iVar5 < numuserfilters;
      iVar5 = iVar5 + 1;
    } while (bVar3);
  }
  return;
}


// SV_LoadEntities  @ 0008fd10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_LoadEntities(void)

{
  ED_LoadFromFile((sv.worldmodel)->entities);
  return;
}


// SV_Localinfo_f  @ 000804a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Localinfo_f(void)

{
  int iVar1;
  char *pcVar2;
  char *key;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    Con_Printf("Local info settings:\n");
    Info_Print(localinfo);
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    pcVar2 = Cmd_Argv(1);
    if (*pcVar2 != '*') {
      pcVar2 = Cmd_Argv(2);
      key = Cmd_Argv(1);
      Info_SetValueForKey(localinfo,key,pcVar2,0x8000);
      return;
    }
    Con_Printf("Star variables cannot be changed.\n");
  }
  else {
    Con_Printf("usage: localinfo [ <key> <value> ]\n");
  }
  return;
}


// SV_LookupDelta  @ 000818c0
delta_t * SV_LookupDelta(char *name)

{
  delta_info_s *pdVar1;
  int iVar2;
  
  pdVar1 = g_sv_delta;
  while( true ) {
    if (pdVar1 == (delta_info_t *)0x0) {
      Sys_Error("Couldn\'t find delta for %s\n",name);
      return (delta_t *)0x0;
    }
    iVar2 = Q_stricmp(name,pdVar1->name);
    if (iVar2 == 0) break;
    pdVar1 = pdVar1->next;
  }
  return pdVar1->delta;
}


// SV_LookupSoundIndex  @ 00082310
int SV_LookupSoundIndex(char *sample)

{
  char cVar1;
  __int32_t **pp_Var2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint local_20;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int starting_index@[???] */
                    /* Unresolved local var: uint hash@[???] */
  cVar1 = *sample;
  if (cVar1 == '\0') {
    local_20 = 0;
  }
  else {
    pp_Var2 = __ctype_tolower_loc();
    local_20 = 0;
    pcVar3 = sample;
    do {
      iVar5 = (int)cVar1;
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
      local_20 = (*pp_Var2)[iVar5] + local_20 * 2;
    } while (cVar1 != '\0');
    local_20 = local_20 % 0x3ff;
  }
  uVar7 = local_20;
  if (sv.sound_precache_hashedlookup_built == false) {
    iVar5 = 1;
    if (sv.state == ss_loading) {
      while( true ) {
        if (sv.sound_precache[iVar5] == (char *)0x0) {
          return 0;
        }
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int starting_index@[???] */
        iVar6 = Q_strcasecmp(sample,sv.sound_precache[iVar5]);
        if (iVar6 == 0) break;
        iVar5 = iVar5 + 1;
        if (iVar5 == 0x200) {
          return 0;
        }
      }
      return iVar5;
    }
                    /* Unresolved local var: int sound_num@[???] */
    Q_memset(sv.sound_precache_hashedlookup,0,0x7fe);
    iVar5 = 0;
    do {
      pcVar3 = sv.sound_precache[iVar5];
      if (pcVar3 == (char *)0x0) break;
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int starting_index@[???]
                       Unresolved local var: uint hash@[???] */
      cVar1 = *pcVar3;
      if (cVar1 == '\0') {
        uVar4 = 0;
        uVar8 = uVar4;
      }
      else {
        pp_Var2 = __ctype_tolower_loc();
        uVar4 = 0;
        do {
          iVar6 = (int)cVar1;
          pcVar3 = pcVar3 + 1;
          cVar1 = *pcVar3;
          uVar4 = (*pp_Var2)[iVar6] + uVar4 * 2;
        } while (cVar1 != '\0');
        uVar4 = uVar4 % 0x3ff;
        uVar8 = uVar4;
      }
      while (*(short *)(uVar4 + 0x518828 + uVar4 + 0x195a0) != 0) {
        uVar4 = uVar4 + 1;
        hashstrings_collisions = hashstrings_collisions + 1;
        if (uVar4 == 0x3ff) {
          uVar4 = 0;
        }
        if (uVar4 == uVar8) {
          Sys_Error("SV_AddSampleToHashedLookupTable: NO FREE SLOTS IN SOUND LOOKUP TABLE");
        }
      }
      *(short *)(uVar4 + 0x518828 + uVar4 + 0x195a0) = (short)iVar5;
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x200);
    sv.sound_precache_hashedlookup_built = true;
  }
  while( true ) {
    iVar5 = (int)*(short *)(uVar7 + 0x518828 + uVar7 + 0x195a0);
    if (iVar5 == 0) {
      return 0;
    }
    iVar5 = Q_strcasecmp(sample,sv.sound_precache[iVar5]);
    if (iVar5 == 0) break;
    uVar7 = uVar7 + 1;
    if (0x3fe < (int)uVar7) {
      uVar7 = 0;
    }
    if (uVar7 == local_20) {
      return 0;
    }
  }
  return (int)*(short *)(uVar7 + 0x518828 + uVar7 + 0x195a0);
}


// SV_ModelIndex  @ 0008d350
int SV_ModelIndex(char *name)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = 0;
  if ((name != (char *)0x0) && (iVar2 = 0, *name != '\0')) {
    do {
      iVar1 = iVar2;
      if (sv.model_precache[iVar2] == (char *)0x0) break;
      iVar1 = Q_strcasecmp(sv.model_precache[iVar2],name);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2;
    } while (iVar2 != 0x200);
    Sys_Error("SV_ModelIndex: model %s not precached",name);
  }
  return iVar1;
}


// SV_Move  @ 000abf10
trace_t * SV_Move(trace_t *__return_storage_ptr__,vec_t *start,vec_t *mins,vec_t *maxs,vec_t *end,
                 int type,edict_t *passedict,qboolean monsterClipBrush)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  trace_t local_110;
  undefined4 auStack_d8 [14];
  moveclip_t local_a0;
  
                    /* Unresolved local var: moveclip_t clip@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t worldEndPoint@[???]
                       Unresolved local var: float worldFraction@[???] */
  Q_memset(&local_a0,0,0x84);
                    /* Unresolved local var: trace_t goodtrace@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: model_t * pmodel@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int rotated@[???]
                       Unresolved local var: int idx@[???] */
  if (sv.edicts != (edict_t *)0x0) {
    SV_SingleClipMoveToEntity(sv.edicts,start,mins,maxs,end,&local_110);
  }
  uVar4 = 0;
  do {
    *(undefined4 *)((int)auStack_d8 + uVar4) =
         *(undefined4 *)((int)local_110.endpos + (uVar4 - 0x14));
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x38);
  uVar4 = 0;
  do {
    *(undefined4 *)((int)local_a0.trace.endpos + (uVar4 - 0x14)) =
         *(undefined4 *)((int)auStack_d8 + uVar4);
    fVar3 = local_a0.trace.fraction;
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x38);
  if (local_a0.trace.fraction == 0.0) {
    uVar4 = 0;
    do {
      *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar4 - 0x14)) =
           *(undefined4 *)((int)local_a0.trace.endpos + (uVar4 - 0x14));
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x38);
  }
  else {
    local_a0.end = (float *)&local_110;
    local_a0.type = (short)(byte)type;
    local_110.allsolid = (qboolean)local_a0.trace.endpos[0];
    local_110.startsolid = (qboolean)local_a0.trace.endpos[1];
    local_110.inopen = (qboolean)local_a0.trace.endpos[2];
    local_a0.ignoretrans = (short)((uint)type >> 8);
    local_a0.trace.fraction = 1.0;
    local_a0.start = start;
    local_a0.passedict = passedict;
    local_a0.mins = mins;
    local_a0.maxs = maxs;
    local_a0.monsterClipBrush = monsterClipBrush;
    if (type == 2) {
      local_a0.mins2[0] = -15.0;
      local_a0.maxs2[0] = 15.0;
      local_a0.mins2[1] = -15.0;
      local_a0.maxs2[1] = 15.0;
      local_a0.mins2[2] = -15.0;
      local_a0.maxs2[2] = 15.0;
    }
    else {
      local_a0.mins2[0] = *mins;
      local_a0.mins2[1] = mins[1];
      local_a0.mins2[2] = mins[2];
      local_a0.maxs2[0] = *maxs;
      local_a0.maxs2[1] = maxs[1];
      local_a0.maxs2[2] = maxs[2];
    }
                    /* Unresolved local var: int i@[???] */
    fVar1 = *start;
    fVar2 = fVar1;
    if (local_a0.trace.endpos[0] <= fVar1) {
      fVar2 = local_a0.trace.endpos[0];
      local_a0.trace.endpos[0] = fVar1;
    }
    local_a0.boxmaxs[0] = local_a0.trace.endpos[0] + local_a0.maxs2[0] + 1.0;
    local_a0.boxmins[0] = (fVar2 + local_a0.mins2[0]) - 1.0;
    fVar1 = start[1];
    fVar2 = fVar1;
    if (local_a0.trace.endpos[1] <= fVar1) {
      fVar2 = local_a0.trace.endpos[1];
      local_a0.trace.endpos[1] = fVar1;
    }
    local_a0.boxmaxs[1] = local_a0.trace.endpos[1] + local_a0.maxs2[1] + 1.0;
    local_a0.boxmins[1] = (fVar2 + local_a0.mins2[1]) - 1.0;
    fVar1 = start[2];
    fVar2 = local_a0.trace.endpos[2];
    if (fVar1 < local_a0.trace.endpos[2]) {
      fVar2 = fVar1;
      fVar1 = local_a0.trace.endpos[2];
    }
    local_a0.boxmaxs[2] = fVar1 + local_a0.maxs2[2] + 1.0;
    local_a0.boxmins[2] = (fVar2 + local_a0.mins2[2]) - 1.0;
    SV_ClipToLinks(sv_areanodes,&local_a0);
    gGlobalVariables.trace_ent = local_a0.trace.ent;
    uVar4 = 0;
    local_a0.trace.fraction = fVar3 * local_a0.trace.fraction;
    do {
      *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar4 - 0x14)) =
           *(undefined4 *)((int)local_a0.trace.endpos + (uVar4 - 0x14));
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x38);
  }
  return __return_storage_ptr__;
}


// SV_MoveBounds  @ 000aba90
void SV_MoveBounds(vec_t *start,vec_t *mins,vec_t *maxs,vec_t *end,vec_t *boxmins,vec_t *boxmaxs)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (*start < *end) {
    *boxmins = (*start + *mins) - 1.0;
    *boxmaxs = *end + *maxs + 1.0;
    fVar1 = end[1];
    fVar2 = start[1];
    if (fVar2 < fVar1) goto LAB_000abb32;
  }
  else {
    *boxmins = (*end + *mins) - 1.0;
    *boxmaxs = *start + *maxs + 1.0;
    fVar1 = end[1];
    fVar2 = start[1];
    if (fVar2 < fVar1) {
LAB_000abb32:
      boxmins[1] = (fVar2 + mins[1]) - 1.0;
      boxmaxs[1] = end[1] + maxs[1] + 1.0;
      fVar1 = end[2];
      fVar2 = start[2];
      if (fVar1 <= fVar2) goto LAB_000abb62;
      goto LAB_000abb0a;
    }
  }
  boxmins[1] = (fVar1 + mins[1]) - 1.0;
  boxmaxs[1] = start[1] + maxs[1] + 1.0;
  fVar1 = end[2];
  fVar2 = start[2];
  if (fVar1 <= fVar2) {
LAB_000abb62:
    boxmins[2] = (fVar1 + mins[2]) - 1.0;
    boxmaxs[2] = start[2] + maxs[2] + 1.0;
    return;
  }
LAB_000abb0a:
  boxmins[2] = (fVar2 + mins[2]) - 1.0;
  boxmaxs[2] = end[2] + maxs[2] + 1.0;
  return;
}


// SV_MoveNoEnts  @ 000abbb0
/* WARNING: Type propagation algorithm not settling */

trace_t * SV_MoveNoEnts(trace_t *__return_storage_ptr__,vec_t *start,vec_t *mins,vec_t *maxs,
                       vec_t *end,int type,edict_t *passedict)

{
  float fVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  float fVar5;
  uint uVar6;
  trace_t local_110;
  undefined4 auStack_d8 [14];
  moveclip_t local_a0;
  
                    /* Unresolved local var: moveclip_t clip@[???]
                       Unresolved local var: vec3_t worldEndPoint@[???]
                       Unresolved local var: float worldFraction@[???] */
  Q_memset(&local_a0,0,0x84);
                    /* Unresolved local var: trace_t goodtrace@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: model_t * pmodel@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int rotated@[???]
                       Unresolved local var: int idx@[???] */
  if (sv.edicts != (edict_t *)0x0) {
    SV_SingleClipMoveToEntity(sv.edicts,start,mins,maxs,end,&local_110);
  }
  uVar6 = 0;
  do {
    *(undefined4 *)((int)auStack_d8 + uVar6) =
         *(undefined4 *)((int)local_110.endpos + (uVar6 - 0x14));
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0x38);
  uVar6 = 0;
  do {
    *(undefined4 *)((int)local_a0.trace.endpos + (uVar6 - 0x14)) =
         *(undefined4 *)((int)auStack_d8 + uVar6);
    fVar5 = local_a0.trace.fraction;
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0x38);
  uVar6 = 0;
  if (local_a0.trace.fraction != 0.0) {
    local_a0.end = (float *)&local_110;
    local_110.allsolid = (qboolean)local_a0.trace.endpos[0];
    local_a0.type = (short)(byte)type;
    local_a0.mins2[0] = *mins;
    local_a0.mins2[1] = mins[1];
    local_a0.mins2[2] = mins[2];
                    /* Unresolved local var: int i@[???] */
    fVar1 = *start;
    local_a0.ignoretrans = (short)((uint)type >> 8);
    local_a0.maxs2[0] = *maxs;
    local_a0.maxs2[1] = maxs[1];
    local_a0.maxs2[2] = maxs[2];
    local_a0.passedict = passedict;
    local_110.startsolid = (qboolean)local_a0.trace.endpos[1];
    local_110.inopen = (qboolean)local_a0.trace.endpos[2];
    local_a0.trace.fraction = 1.0;
    local_a0.start = start;
    local_a0.mins = mins;
    local_a0.maxs = maxs;
    local_a0.monsterClipBrush = false;
    if (fVar1 < local_a0.trace.endpos[0]) {
      fVar2 = start[1];
      vVar4 = local_a0.trace.endpos[0];
      local_a0.trace.endpos[0] = fVar1;
    }
    else {
      fVar2 = start[1];
      vVar4 = fVar1;
    }
    local_a0.boxmins[0] = (local_a0.trace.endpos[0] + local_a0.mins2[0]) - 1.0;
    local_a0.boxmaxs[0] = vVar4 + local_a0.maxs2[0] + 1.0;
    if (fVar2 < local_a0.trace.endpos[1]) {
      fVar1 = start[2];
      fVar3 = local_a0.trace.endpos[1];
      local_a0.trace.endpos[1] = fVar2;
    }
    else {
      fVar1 = start[2];
      fVar3 = fVar2;
    }
    local_a0.boxmins[1] = (local_a0.trace.endpos[1] + local_a0.mins2[1]) - 1.0;
    local_a0.boxmaxs[1] = fVar3 + local_a0.maxs2[1] + 1.0;
    fVar2 = local_a0.trace.endpos[2];
    if (fVar1 < local_a0.trace.endpos[2]) {
      fVar2 = fVar1;
      fVar1 = local_a0.trace.endpos[2];
    }
    local_a0.boxmaxs[2] = fVar1 + local_a0.maxs2[2] + 1.0;
    local_a0.boxmins[2] = (fVar2 + local_a0.mins2[2]) - 1.0;
    SV_ClipToWorldbrush(sv_areanodes,&local_a0);
    gGlobalVariables.trace_ent = local_a0.trace.ent;
    uVar6 = 0;
    local_a0.trace.fraction = fVar5 * local_a0.trace.fraction;
    do {
      *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar6 - 0x14)) =
           *(undefined4 *)((int)local_a0.trace.endpos + (uVar6 - 0x14));
      uVar6 = uVar6 + 4;
    } while (uVar6 < 0x38);
    return __return_storage_ptr__;
  }
  do {
    *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar6 - 0x14)) =
         *(undefined4 *)((int)local_a0.trace.endpos + (uVar6 - 0x14));
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0x38);
  return __return_storage_ptr__;
}


// SV_MoveToOnHandList  @ 0009ed70
void SV_MoveToOnHandList(resource_t *pResource)

{
  client_t *pcVar1;
  
  if (pResource != (resource_t *)0x0) {
    pResource->pPrev->pNext = pResource->pNext;
    pResource->pNext->pPrev = pResource->pPrev;
    pResource->pPrev = (resource_s *)0x0;
    pcVar1 = host_client;
    pResource->pNext = (resource_s *)0x0;
    pResource->pPrev = (pcVar1->resourcesonhand).pPrev;
    ((pcVar1->resourcesonhand).pPrev)->pNext = pResource;
    (pcVar1->resourcesonhand).pPrev = pResource;
    pResource->pNext = &pcVar1->resourcesonhand;
    return;
  }
  Con_DPrintf("Null resource passed to SV_MoveToOnHandList\n");
  return;
}


// SV_MoveToOrigin_I  @ 000988e0
void SV_MoveToOrigin_I(edict_t *ent,float *pflGoal,float dist,int iStrafe)

{
  vec_t *maxs;
  vec_t *mins;
  float fVar1;
  float fVar2;
  float fVar3;
  edict_t *peVar4;
  uint uVar5;
  int iVar6;
  qboolean qVar7;
  uint uVar8;
  double local_dc;
  double local_d4;
  trace_t local_cc;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54 [5];
  vec_t local_40;
  vec_t local_3c;
  vec_t vStack_38;
  edict_t *peStack_24;
  
                    /* Unresolved local var: vec3_t vecGoal@[???]
                       Unresolved local var: vec3_t vecDir@[???]
                       Unresolved local var: float flReturn@[???] */
  local_84 = *pflGoal;
  local_80 = pflGoal[1];
  local_7c = pflGoal[2];
  uVar8 = (ent->v).flags;
  if ((uVar8 & 0x203) == 0) {
    return;
  }
  if (iStrafe == 0) {
    fVar1 = (ent->v).ideal_yaw * 3.1415927;
    sincos((double)((fVar1 + fVar1) / 360.0),&local_d4,&local_dc);
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    local_54[0] = (float)local_dc * dist;
    local_54[2] = 0.0;
    local_54[1] = dist * (float)local_d4;
    qVar7 = SV_movestep(ent,local_54,false);
    if (qVar7 == false) {
      SV_LinkEdict(ent,true);
      SV_NewChaseDir2(ent,&local_84,dist);
      return;
    }
  }
  else {
    local_78 = local_84 - (ent->v).origin[0];
    local_74 = local_80 - (ent->v).origin[1];
    if ((uVar8 & 3) == 0) {
      local_70 = 0.0;
    }
    else {
      local_70 = local_7c - (ent->v).origin[2];
    }
    VectorNormalize(&local_78);
    VectorScale(&local_78,dist,&local_78);
                    /* Unresolved local var: vec3_t oldorigin@[???]
                       Unresolved local var: float dz@[???]
                       Unresolved local var: vec3_t oldorg@[???]
                       Unresolved local var: vec3_t neworg@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * enemy@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
    uVar8 = (ent->v).flags;
    fVar1 = (ent->v).origin[0];
    fVar2 = (ent->v).origin[1];
    qVar7 = uVar8 >> 0x17 & true;
    fVar3 = (ent->v).origin[2];
    local_6c = local_78 + fVar1;
    local_68 = local_74 + fVar2;
    local_64 = local_70 + fVar3;
    if ((uVar8 & 3) == 0) {
      local_64 = local_64 + sv_stepsize.value;
      maxs = (ent->v).maxs;
      mins = (ent->v).mins;
      local_58 = local_64 - (sv_stepsize.value + sv_stepsize.value);
      local_60 = local_6c;
      local_5c = local_68;
      SV_Move(&local_cc,&local_6c,mins,maxs,&local_60,0,ent,qVar7);
      uVar8 = 0;
      do {
        *(undefined4 *)((int)local_54 + uVar8) =
             *(undefined4 *)((int)local_cc.endpos + (uVar8 - 0x14));
        uVar8 = uVar8 + 4;
      } while (uVar8 < 0x38);
      if (local_54[0] == 0.0) {
        if (local_54[1] != 0.0) {
          local_64 = local_64 - sv_stepsize.value;
          SV_Move(&local_cc,&local_6c,mins,maxs,&local_60,0,ent,qVar7);
          uVar8 = 0;
          do {
            *(undefined4 *)((int)local_54 + uVar8) =
                 *(undefined4 *)((int)local_cc.endpos + (uVar8 - 0x14));
            uVar8 = uVar8 + 4;
          } while (uVar8 < 0x38);
          if ((local_54[0] != 0.0) || (local_54[1] != 0.0)) goto LAB_00098b6c;
        }
        if (local_54[4] == 1.0) {
          uVar8 = (ent->v).flags;
          if ((uVar8 & 0x400) != 0) {
            (ent->v).flags = uVar8 & 0xfffffdff;
            (ent->v).origin[0] = (ent->v).origin[0] + local_78;
            (ent->v).origin[1] = (ent->v).origin[1] + local_74;
            (ent->v).origin[2] = (ent->v).origin[2] + local_70;
          }
        }
        else {
          (ent->v).origin[0] = local_40;
          (ent->v).origin[1] = local_3c;
          (ent->v).origin[2] = vStack_38;
          qVar7 = SV_CheckBottom(ent);
          if (qVar7 == false) {
            if (((ent->v).flags & 0x400) == 0) {
              (ent->v).origin[0] = fVar1;
              (ent->v).origin[1] = fVar2;
              (ent->v).origin[2] = fVar3;
            }
          }
          else {
            uVar8 = (ent->v).flags;
            if ((uVar8 & 0x400) != 0) {
              (ent->v).flags = uVar8 & 0xfffffbff;
            }
            (ent->v).groundentity = peStack_24;
          }
        }
      }
    }
    else {
      uVar8 = 0;
      while( true ) {
        peVar4 = (ent->v).enemy;
        if (((uVar8 & 1) == 0) && (peVar4 != (edict_t *)0x0)) {
          fVar3 = fVar3 - (peVar4->v).origin[2];
          if (40.0 < fVar3) {
            local_64 = local_64 - 8.0;
          }
          if (fVar3 < 30.0) {
            local_64 = local_64 + 8.0;
          }
        }
        SV_Move(&local_cc,(ent->v).origin,(ent->v).mins,(ent->v).maxs,&local_6c,0,ent,qVar7);
        uVar5 = 0;
        do {
          *(undefined4 *)((int)local_54 + uVar5) =
               *(undefined4 *)((int)local_cc.endpos + (uVar5 - 0x14));
          uVar5 = uVar5 + 4;
        } while (uVar5 < 0x38);
        if (local_54[4] == 1.0) break;
        if ((peVar4 == (edict_t *)0x0) || (uVar8 = uVar8 + 1, uVar8 == 2)) goto LAB_00098b6c;
        fVar3 = (ent->v).origin[2];
        local_6c = (ent->v).origin[0] + local_78;
        local_68 = (ent->v).origin[1] + local_74;
        local_64 = local_70 + fVar3;
      }
      g_groupmask = (ent->v).groupinfo;
      if ((((ent->v).flags & 2) == 0) || (iVar6 = SV_PointContents(&local_40), iVar6 != -1)) {
        (ent->v).origin[0] = local_40;
        (ent->v).origin[1] = local_3c;
        (ent->v).origin[2] = vStack_38;
      }
    }
  }
LAB_00098b6c:
  SV_LinkEdict(ent,true);
  return;
}


// SV_Multicast  @ 00082b90
void SV_Multicast(edict_t *ent,vec_t *origin,int to,qboolean reliable)

{
  uint uVar1;
  uint uVar2;
  client_t *pcVar3;
  client_t *pcVar4;
  client_t *pcVar5;
  mleaf_t *pmVar6;
  client_s *pcVar7;
  client_t *pcVar8;
  uint uVar9;
  qboolean qVar10;
  byte *pbVar11;
  sizebuf_t *buf;
  byte bVar12;
  int iVar13;
  int iVar14;
  int local_24;
  
                    /* Unresolved local var: client_t * client@[???]
                       Unresolved local var: int leafnum@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: sizebuf_t * pBuffer@[???]
                       Unresolved local var: client_t * save@[???] */
  pcVar4 = host_client;
                    /* Unresolved local var: mleaf_t * pLeaf@[???] */
  pmVar6 = Mod_PointInLeaf(origin,sv.worldmodel);
  if (pmVar6 == (mleaf_t *)0x0) {
    local_24 = 0;
  }
  else {
    local_24 = ((int)pmVar6 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555;
  }
  if ((ent == (edict_t *)0x0) || ((host_client != (client_t *)0x0 && (ent == host_client->edict))))
  {
    pcVar5 = host_client;
    if (svs.maxclients < 1) goto LAB_00082d06;
  }
  else {
    if (svs.maxclients < 1) goto LAB_00082d06;
    pcVar5 = svs.clients;
    if (ent != (svs.clients)->edict) {
      iVar14 = 0;
      pcVar7 = svs.clients;
      do {
        iVar14 = iVar14 + 1;
        pcVar8 = pcVar7 + 1;
        pcVar5 = host_client;
        if (iVar14 == svs.maxclients) break;
        pcVar3 = pcVar7 + 1;
        pcVar7 = pcVar8;
        pcVar5 = pcVar8;
      } while (ent != pcVar3->edict);
    }
  }
                    /* Unresolved local var: byte * mask@[???]
                       Unresolved local var: int destination@[???] */
  host_client = pcVar5;
  iVar14 = 0;
  uVar9 = to & 0xffffff7f;
  pcVar7 = svs.clients;
LAB_00082c50:
  do {
    if ((pcVar7->active == false) || (((to & 0x80U) != 0 && (host_client == pcVar7))))
    goto LAB_00082cf3;
    if ((ent == (edict_t *)0x0) ||
       ((uVar1 = (ent->v).groupinfo, uVar1 == 0 ||
        (uVar2 = (pcVar7->edict->v).groupinfo, uVar2 == 0)))) {
LAB_00082ca0:
      qVar10 = Host_IsSinglePlayerGame();
      if ((qVar10 == false) && (pcVar7->proxy == false)) {
        if (uVar9 != 2) {
          if (uVar9 == 4) {
            pbVar11 = CM_LeafPAS(local_24);
            goto LAB_00082d36;
          }
          if (uVar9 == 1) goto LAB_00082da0;
          Con_Printf("MULTICAST: Error %d!\n",to);
LAB_00082ce8:
          gPacketSuppressed = gPacketSuppressed + sv.multicast.cursize;
          goto LAB_00082cf3;
        }
        pbVar11 = CM_LeafPVS(local_24);
LAB_00082d36:
        if (pbVar11 != (byte *)0x0) {
                    /* Unresolved local var: int bitNumber@[???]
                       Unresolved local var: mleaf_t * pLeaf@[???] */
          pmVar6 = Mod_PointInLeaf((pcVar7->edict->v).origin,sv.worldmodel);
          if (pmVar6 == (mleaf_t *)0x0) {
            bVar12 = 7;
            iVar13 = -1;
          }
          else {
            iVar13 = ((int)pmVar6 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
            bVar12 = (byte)iVar13 & 7;
            iVar13 = iVar13 >> 3;
          }
          if (((int)(uint)pbVar11[iVar13] >> bVar12 & 1U) == 0) goto LAB_00082ce8;
        }
      }
LAB_00082da0:
      buf = &(pcVar7->netchan).message;
      if (reliable == false) {
        buf = &pcVar7->datagram;
      }
      if (sv.multicast.cursize < buf->maxsize - buf->cursize) {
        iVar14 = iVar14 + 1;
        pcVar7 = pcVar7 + 1;
        SZ_Write(buf,sv.multicast.data,sv.multicast.cursize);
        if (svs.maxclients <= iVar14) break;
        goto LAB_00082c50;
      }
    }
    else if (g_groupop == 0) {
      if ((uVar1 & uVar2) != 0) goto LAB_00082ca0;
    }
    else if ((g_groupop != 1) || ((uVar1 & uVar2) == 0)) goto LAB_00082ca0;
LAB_00082cf3:
    iVar14 = iVar14 + 1;
    pcVar7 = pcVar7 + 1;
  } while (iVar14 < svs.maxclients);
LAB_00082d06:
  SZ_Clear(&sv.multicast);
  host_client = pcVar4;
  return;
}


// SV_NewChaseDir  @ 00096f60
void SV_NewChaseDir(edict_t *actor,edict_t *enemy,float dist)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int32 iVar9;
  qboolean qVar10;
  uint uVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  float local_4c;
  double local_2c;
  double local_24;
  float local_18;
  float local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: float deltax@[???]
                       Unresolved local var: float deltay@[???]
                       Unresolved local var: float[3] d@[???]
                       Unresolved local var: float tdir@[???]
                       Unresolved local var: float olddir@[???]
                       Unresolved local var: float turnaround@[???] */
  fVar13 = anglemod((float)((int)((actor->v).ideal_yaw / 45.0) * 0x2d));
  fVar14 = anglemod(fVar13 - 180.0);
  fVar2 = (enemy->v).origin[0] - (actor->v).origin[0];
  fVar3 = (enemy->v).origin[1] - (actor->v).origin[1];
  if (10.0 < fVar2) {
    if (fVar3 < -10.0) {
      local_4c = 0.0;
      fVar4 = 270.0;
      fVar5 = 315.0;
LAB_00097400:
      bVar7 = true;
      if (fVar5 != fVar14) {
        bVar7 = true;
        qVar10 = SV_StepDirection(actor,fVar5,dist);
        if (qVar10 != false) {
          return;
        }
      }
LAB_00097012:
      iVar9 = RandomLong(0,1);
      bVar8 = true;
      bVar6 = true;
      fVar5 = fVar4;
      if (iVar9 == 0) {
LAB_00097050:
        uVar11 = (int)fVar3 >> 0x1f;
        uVar12 = (int)fVar2 >> 0x1f;
        fVar5 = fVar4;
        bVar6 = bVar8;
        if ((int)(((int)fVar3 ^ uVar11) - uVar11) <= (int)(((int)fVar2 ^ uVar12) - uVar12)) {
          fVar5 = local_4c;
          local_4c = fVar4;
          bVar6 = bVar7;
          bVar7 = bVar8;
        }
      }
      bVar8 = bVar7;
      if (((fVar14 != fVar5) && (bVar6)) &&
         (qVar10 = SV_StepDirection(actor,fVar5,dist), qVar10 != false)) {
        return;
      }
    }
    else {
      if (10.0 < fVar3) {
        local_4c = 0.0;
        fVar4 = 90.0;
        fVar5 = 45.0;
        goto LAB_00097400;
      }
      local_4c = 0.0;
LAB_000970fe:
      iVar9 = RandomLong(0,1);
      bVar7 = true;
      bVar8 = true;
      if (iVar9 == 0) {
        bVar8 = false;
        fVar4 = -1.0;
        goto LAB_00097050;
      }
    }
    if (((fVar14 != local_4c) && (bVar8)) &&
       (qVar10 = SV_StepDirection(actor,local_4c,dist), qVar10 != false)) {
      return;
    }
  }
  else {
    if (fVar2 < -10.0) {
      if (fVar3 < -10.0) {
        fVar4 = 270.0;
        local_4c = 180.0;
        fVar5 = 215.0;
      }
      else {
        if (fVar3 <= 10.0) {
          local_4c = 180.0;
          goto LAB_000970fe;
        }
        local_4c = 180.0;
        fVar4 = 90.0;
        fVar5 = 135.0;
      }
      goto LAB_00097400;
    }
    if (fVar3 < -10.0) {
      bVar7 = false;
      local_4c = -1.0;
      fVar4 = 270.0;
      goto LAB_00097012;
    }
    if (10.0 < fVar3) {
      bVar7 = false;
      local_4c = -1.0;
      fVar4 = 90.0;
      goto LAB_00097012;
    }
    iVar9 = RandomLong(0,1);
    if (iVar9 == 0) {
      bVar7 = false;
      fVar4 = -1.0;
      bVar8 = false;
      local_4c = -1.0;
      goto LAB_00097050;
    }
  }
  if (fVar13 != -1.0) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    sincos((double)((fVar13 * 3.1415927 + fVar13 * 3.1415927) / 360.0),&local_24,&local_2c);
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = (float)local_24 * dist;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) goto LAB_00097470;
    SV_LinkEdict(actor,true);
  }
  iVar9 = RandomLong(0,1);
  if (iVar9 == 0) {
    if (fVar14 == 315.0) {
LAB_0009749c:
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
      local_18 = dist * 1.1924881e-08;
      local_10 = 0;
      local_14 = dist * -1.0;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_000974da;
      SV_LinkEdict(actor,true);
      if (fVar14 != 225.0) goto LAB_000977eb;
LAB_000975b5:
      local_18 = dist * -1.0;
      local_10 = 0;
      local_14 = dist * -8.742278e-08;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_000974da;
      SV_LinkEdict(actor,true);
      if (fVar14 != 135.0) goto LAB_00097856;
LAB_00097620:
      local_18 = dist * -4.371139e-08;
      local_10 = 0;
      local_14 = dist * 1.0;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_000974da;
      SV_LinkEdict(actor,true);
      if (fVar14 != 45.0) goto LAB_000978c1;
LAB_0009768b:
      local_14 = dist * 0.0;
      local_18 = dist;
      goto LAB_0009769f;
    }
    local_18 = dist * 0.70710665;
    local_10 = 0;
    local_14 = dist * -0.7071069;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) goto LAB_000974da;
    SV_LinkEdict(actor,true);
    if (fVar14 != 270.0) goto LAB_0009749c;
LAB_000977eb:
    local_18 = dist * -0.7071068;
    local_10 = 0;
    local_14 = dist * -0.7071067;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) goto LAB_000974da;
    SV_LinkEdict(actor,true);
    if (fVar14 != 180.0) goto LAB_000975b5;
LAB_00097856:
    local_18 = dist * -0.70710677;
    local_10 = 0;
    local_14 = dist * 0.70710677;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) goto LAB_000974da;
    SV_LinkEdict(actor,true);
    if (fVar14 != 90.0) goto LAB_00097620;
LAB_000978c1:
    local_18 = dist * 0.70710677;
    local_10 = 0;
    local_14 = dist * 0.70710677;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) goto LAB_000974da;
    SV_LinkEdict(actor,true);
    if (fVar14 != 0.0) goto LAB_0009768b;
  }
  else {
    if (fVar14 != 0.0) {
      local_14 = dist * 0.0;
      local_18 = dist;
      local_10 = 0;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_000974da;
      SV_LinkEdict(actor,true);
    }
    if (fVar14 == 45.0) {
LAB_000971cb:
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
      local_18 = dist * -4.371139e-08;
      local_10 = 0;
      local_14 = dist * 1.0;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_000974da;
      SV_LinkEdict(actor,true);
      if (fVar14 != 135.0) goto LAB_000979eb;
LAB_00097236:
      local_18 = dist * -1.0;
      local_10 = 0;
      local_14 = dist * -8.742278e-08;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_000974da;
      SV_LinkEdict(actor,true);
      if (fVar14 != 225.0) goto LAB_00097a56;
LAB_000972a1:
      local_18 = dist * 1.1924881e-08;
      local_10 = 0;
      local_14 = dist * -1.0;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_000974da;
      SV_LinkEdict(actor,true);
      if (fVar14 == 315.0) goto LAB_0009730c;
    }
    else {
      local_18 = dist * 0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_000974da;
      SV_LinkEdict(actor,true);
      if (fVar14 != 90.0) goto LAB_000971cb;
LAB_000979eb:
      local_18 = dist * -0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_000974da;
      SV_LinkEdict(actor,true);
      if (fVar14 != 180.0) goto LAB_00097236;
LAB_00097a56:
      local_18 = dist * -0.7071068;
      local_10 = 0;
      local_14 = dist * -0.7071067;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_000974da;
      SV_LinkEdict(actor,true);
      if (fVar14 != 270.0) goto LAB_000972a1;
    }
    local_18 = dist * 0.70710665;
    local_14 = dist * -0.7071069;
LAB_0009769f:
    local_10 = 0;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) {
LAB_000974da:
      SV_LinkEdict(actor,true);
      return;
    }
    SV_LinkEdict(actor,true);
  }
LAB_0009730c:
  if (fVar14 != -1.0) {
    sincos((double)((fVar14 * 3.1415927 + fVar14 * 3.1415927) / 360.0),&local_24,&local_2c);
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = (float)local_24 * dist;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) {
LAB_00097470:
      SV_LinkEdict(actor,true);
      return;
    }
    SV_LinkEdict(actor,true);
  }
  (actor->v).ideal_yaw = fVar13;
  qVar10 = SV_CheckBottom(actor);
  if (qVar10 != false) {
    return;
  }
  piVar1 = &(actor->v).flags;
  *piVar1 = *piVar1 | 0x400;
  return;
}


// SV_NewChaseDir2  @ 00097cd0
void SV_NewChaseDir2(edict_t *actor,vec_t *vecGoal,float dist)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int32 iVar9;
  qboolean qVar10;
  uint uVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  float local_4c;
  double local_2c;
  double local_24;
  float local_18;
  float local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: float deltax@[???]
                       Unresolved local var: float deltay@[???]
                       Unresolved local var: float[3] d@[???]
                       Unresolved local var: float tdir@[???]
                       Unresolved local var: float olddir@[???]
                       Unresolved local var: float turnaround@[???] */
  fVar13 = anglemod((float)((int)((actor->v).ideal_yaw / 45.0) * 0x2d));
  fVar14 = anglemod(fVar13 - 180.0);
  fVar2 = *vecGoal - (actor->v).origin[0];
  fVar3 = vecGoal[1] - (actor->v).origin[1];
  if (10.0 < fVar2) {
    if (fVar3 < -10.0) {
      local_4c = 0.0;
      fVar4 = 270.0;
      fVar5 = 315.0;
LAB_00098170:
      bVar7 = true;
      if (fVar5 != fVar14) {
        bVar7 = true;
        qVar10 = SV_StepDirection(actor,fVar5,dist);
        if (qVar10 != false) {
          return;
        }
      }
LAB_00097d7a:
      iVar9 = RandomLong(0,1);
      bVar8 = true;
      bVar6 = true;
      fVar5 = fVar4;
      if (iVar9 == 0) {
LAB_00097db8:
        uVar11 = (int)fVar3 >> 0x1f;
        uVar12 = (int)fVar2 >> 0x1f;
        fVar5 = fVar4;
        bVar6 = bVar8;
        if ((int)(((int)fVar3 ^ uVar11) - uVar11) <= (int)(((int)fVar2 ^ uVar12) - uVar12)) {
          fVar5 = local_4c;
          local_4c = fVar4;
          bVar6 = bVar7;
          bVar7 = bVar8;
        }
      }
      bVar8 = bVar7;
      if (((fVar14 != fVar5) && (bVar6)) &&
         (qVar10 = SV_StepDirection(actor,fVar5,dist), qVar10 != false)) {
        return;
      }
    }
    else {
      if (10.0 < fVar3) {
        local_4c = 0.0;
        fVar4 = 90.0;
        fVar5 = 45.0;
        goto LAB_00098170;
      }
      local_4c = 0.0;
LAB_00097e6e:
      iVar9 = RandomLong(0,1);
      bVar7 = true;
      bVar8 = true;
      if (iVar9 == 0) {
        bVar8 = false;
        fVar4 = -1.0;
        goto LAB_00097db8;
      }
    }
    if (((fVar14 != local_4c) && (bVar8)) &&
       (qVar10 = SV_StepDirection(actor,local_4c,dist), qVar10 != false)) {
      return;
    }
  }
  else {
    if (fVar2 < -10.0) {
      if (fVar3 < -10.0) {
        fVar4 = 270.0;
        local_4c = 180.0;
        fVar5 = 215.0;
      }
      else {
        if (fVar3 <= 10.0) {
          local_4c = 180.0;
          goto LAB_00097e6e;
        }
        local_4c = 180.0;
        fVar4 = 90.0;
        fVar5 = 135.0;
      }
      goto LAB_00098170;
    }
    if (fVar3 < -10.0) {
      bVar7 = false;
      local_4c = -1.0;
      fVar4 = 270.0;
      goto LAB_00097d7a;
    }
    if (10.0 < fVar3) {
      bVar7 = false;
      local_4c = -1.0;
      fVar4 = 90.0;
      goto LAB_00097d7a;
    }
    iVar9 = RandomLong(0,1);
    if (iVar9 == 0) {
      bVar7 = false;
      fVar4 = -1.0;
      bVar8 = false;
      local_4c = -1.0;
      goto LAB_00097db8;
    }
  }
  if (fVar13 != -1.0) {
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    sincos((double)((fVar13 * 3.1415927 + fVar13 * 3.1415927) / 360.0),&local_24,&local_2c);
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = (float)local_24 * dist;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) goto LAB_000981e0;
    SV_LinkEdict(actor,true);
  }
  iVar9 = RandomLong(0,1);
  if (iVar9 == 0) {
    if (fVar14 == 315.0) {
LAB_0009820c:
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
      local_18 = dist * 1.1924881e-08;
      local_10 = 0;
      local_14 = dist * -1.0;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_0009824a;
      SV_LinkEdict(actor,true);
      if (fVar14 != 225.0) goto LAB_0009855b;
LAB_00098325:
      local_18 = dist * -1.0;
      local_10 = 0;
      local_14 = dist * -8.742278e-08;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_0009824a;
      SV_LinkEdict(actor,true);
      if (fVar14 != 135.0) goto LAB_000985c6;
LAB_00098390:
      local_18 = dist * -4.371139e-08;
      local_10 = 0;
      local_14 = dist * 1.0;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_0009824a;
      SV_LinkEdict(actor,true);
      if (fVar14 != 45.0) goto LAB_00098631;
LAB_000983fb:
      local_14 = dist * 0.0;
      local_18 = dist;
      goto LAB_0009840f;
    }
    local_18 = dist * 0.70710665;
    local_10 = 0;
    local_14 = dist * -0.7071069;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) goto LAB_0009824a;
    SV_LinkEdict(actor,true);
    if (fVar14 != 270.0) goto LAB_0009820c;
LAB_0009855b:
    local_18 = dist * -0.7071068;
    local_10 = 0;
    local_14 = dist * -0.7071067;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) goto LAB_0009824a;
    SV_LinkEdict(actor,true);
    if (fVar14 != 180.0) goto LAB_00098325;
LAB_000985c6:
    local_18 = dist * -0.70710677;
    local_10 = 0;
    local_14 = dist * 0.70710677;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) goto LAB_0009824a;
    SV_LinkEdict(actor,true);
    if (fVar14 != 90.0) goto LAB_00098390;
LAB_00098631:
    local_18 = dist * 0.70710677;
    local_10 = 0;
    local_14 = dist * 0.70710677;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) goto LAB_0009824a;
    SV_LinkEdict(actor,true);
    if (fVar14 != 0.0) goto LAB_000983fb;
  }
  else {
    if (fVar14 != 0.0) {
      local_14 = dist * 0.0;
      local_18 = dist;
      local_10 = 0;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_0009824a;
      SV_LinkEdict(actor,true);
    }
    if (fVar14 == 45.0) {
LAB_00097f3b:
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
      local_18 = dist * -4.371139e-08;
      local_10 = 0;
      local_14 = dist * 1.0;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_0009824a;
      SV_LinkEdict(actor,true);
      if (fVar14 != 135.0) goto LAB_0009875b;
LAB_00097fa6:
      local_18 = dist * -1.0;
      local_10 = 0;
      local_14 = dist * -8.742278e-08;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_0009824a;
      SV_LinkEdict(actor,true);
      if (fVar14 != 225.0) goto LAB_000987c6;
LAB_00098011:
      local_18 = dist * 1.1924881e-08;
      local_10 = 0;
      local_14 = dist * -1.0;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_0009824a;
      SV_LinkEdict(actor,true);
      if (fVar14 == 315.0) goto LAB_0009807c;
    }
    else {
      local_18 = dist * 0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_0009824a;
      SV_LinkEdict(actor,true);
      if (fVar14 != 90.0) goto LAB_00097f3b;
LAB_0009875b:
      local_18 = dist * -0.70710677;
      local_10 = 0;
      local_14 = dist * 0.70710677;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_0009824a;
      SV_LinkEdict(actor,true);
      if (fVar14 != 180.0) goto LAB_00097fa6;
LAB_000987c6:
      local_18 = dist * -0.7071068;
      local_10 = 0;
      local_14 = dist * -0.7071067;
      qVar10 = SV_movestep(actor,&local_18,false);
      if (qVar10 != false) goto LAB_0009824a;
      SV_LinkEdict(actor,true);
      if (fVar14 != 270.0) goto LAB_00098011;
    }
    local_18 = dist * 0.70710665;
    local_14 = dist * -0.7071069;
LAB_0009840f:
    local_10 = 0;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) {
LAB_0009824a:
      SV_LinkEdict(actor,true);
      return;
    }
    SV_LinkEdict(actor,true);
  }
LAB_0009807c:
  if (fVar14 != -1.0) {
    sincos((double)((fVar14 * 3.1415927 + fVar14 * 3.1415927) / 360.0),&local_24,&local_2c);
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
    local_10 = 0;
    local_18 = (float)local_2c * dist;
    local_14 = (float)local_24 * dist;
    qVar10 = SV_movestep(actor,&local_18,false);
    if (qVar10 != false) {
LAB_000981e0:
      SV_LinkEdict(actor,true);
      return;
    }
    SV_LinkEdict(actor,true);
  }
  (actor->v).ideal_yaw = fVar13;
  qVar10 = SV_CheckBottom(actor);
  if (qVar10 != false) {
    return;
  }
  piVar1 = &(actor->v).flags;
  *piVar1 = *piVar1 | 0x400;
  return;
}


// SV_New_f  @ 00083d40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_New_f(void)

{
  int iVar1;
  edict_t *peVar2;
  qboolean *pqVar3;
  UserMsg *pUVar4;
  double dVar5;
  char *pcVar6;
  qboolean qVar7;
  int iVar8;
  client_t *pcVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  _UserMsg *p_Var13;
  client_t *pcVar14;
  int in_GS_OFFSET;
  sizebuf_t sStack_1035c;
  uchar auStack_10348 [16];
  char acStack_10338 [64];
  MD5Context_t MStack_102f8;
  char acStack_102a0 [4];
  char acStack_1029c [124];
  char acStack_10220 [256];
  char acStack_10120 [255];
  undefined1 uStack_10021;
  byte abStack_10020 [65552];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: uchar[65536] data@[???]
                       Unresolved local var: sizebuf_t msg@[???]
                       Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: char[128] szRejectReason@[???]
                       Unresolved local var: char[256] szAddress@[???]
                       Unresolved local var: char[64] szName@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&sStack_1035c,0,0x14);
  pcVar9 = host_client;
  dVar5 = realtime;
  sStack_1035c.buffername = "New Connection";
  sStack_1035c.data = abStack_10020;
  sStack_1035c.cursize = 0;
  sStack_1035c.maxsize = 0x10000;
  if (((cmd_source != src_command) &&
      ((host_client->hasusrmsgs == false || (host_client->m_bSentNewResponse == false)))) &&
     ((host_client->spawned == false || (host_client->active != false)))) {
    peVar2 = host_client->edict;
    host_client->connected = true;
    pcVar9->connection_started = dVar5;
    pcVar9->m_sendrescount = 0;
    SZ_Clear(&(pcVar9->netchan).message);
    SZ_Clear(&host_client->datagram);
    Netchan_Clear(&host_client->netchan);
    SV_SendServerinfo(&sStack_1035c,host_client);
    pUVar4 = sv_gpNewUserMsgs;
    if (sv_gpUserMsgs != (UserMsg *)0x0) {
                    /* Unresolved local var: UserMsg * pTemp@[???] */
      sv_gpNewUserMsgs = sv_gpUserMsgs;
      p_Var13 = sv_gpUserMsgs;
      do {
                    /* Unresolved local var: UserMsg * pMsg@[???] */
        MSG_WriteByte(&sStack_1035c,0x27);
        MSG_WriteByte(&sStack_1035c,p_Var13->iMsg);
        MSG_WriteByte(&sStack_1035c,p_Var13->iSize);
        MSG_WriteLong(&sStack_1035c,*(int *)p_Var13->szName);
        MSG_WriteLong(&sStack_1035c,*(int *)(p_Var13->szName + 4));
        MSG_WriteLong(&sStack_1035c,*(int *)(p_Var13->szName + 8));
        MSG_WriteLong(&sStack_1035c,*(int *)(p_Var13->szName + 0xc));
        p_Var13 = p_Var13->next;
      } while (p_Var13 != (_UserMsg *)0x0);
    }
    pcVar9 = host_client;
    pqVar3 = &host_client->active;
    sv_gpNewUserMsgs = pUVar4;
    host_client->hasusrmsgs = true;
    if (((*pqVar3 != false) || (pcVar9->spawned != false)) && (pcVar9->edict != (edict_t *)0x0)) {
      (*gEntityInterface.pfnClientDisconnect)(pcVar9->edict);
      pcVar9 = host_client;
    }
    snprintf(acStack_10338,0x40,"%s",pcVar9->name);
    pcVar6 = NET_AdrToString((host_client->netchan).remote_address);
    snprintf(acStack_10220,0x100,"%s",pcVar6);
    uVar11 = 0;
    do {
      uVar10 = uVar11;
      *(undefined4 *)(acStack_102a0 + uVar10) =
           *(undefined4 *)("Connection rejected by game\n" + uVar10);
      uVar11 = uVar10 + 4;
    } while (uVar11 < 0x1c);
    acStack_102a0[uVar11] = "Connection rejected by game\n"[uVar10 + 4];
    qVar7 = (*gEntityInterface.pfnClientConnect)(peVar2,acStack_10338,acStack_10220,acStack_102a0);
    if (qVar7 == false) {
      MSG_WriteByte(&(host_client->netchan).message,9);
      pcVar6 = va("echo %s\n",acStack_102a0);
      MSG_WriteString(&(host_client->netchan).message,pcVar6);
      SV_DropClient(host_client,false,"Server refused connection because:  %s",acStack_102a0);
    }
    else {
      MSG_WriteByte(&sStack_1035c,9);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] info@[???]
                       Unresolved local var: char[16] digest@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
      pcVar6 = Info_Serverinfo();
      pcVar6 = va("fullserverinfo \"%s\"\n",pcVar6);
      MSG_WriteString(&sStack_1035c,pcVar6);
      MSG_WriteByte(&sStack_1035c,9);
      uVar11 = (uint)NAN(sv_allow_shaders.value);
      if (sv_allow_shaders.value != 0.0) {
        uVar11 = 1;
      }
      pcVar6 = va("allow_shaders %d\n",uVar11);
      MSG_WriteString(&sStack_1035c,pcVar6);
      MSG_WriteByte(&sStack_1035c,9);
      uVar11 = (uint)NAN(sv_allow_autoaim.value);
      if (sv_allow_autoaim.value != 0.0) {
        uVar11 = 1;
      }
      pcVar6 = va("allow_autoaim %d\n",uVar11);
      MSG_WriteString(&sStack_1035c,pcVar6);
      iVar12 = 0;
      pcVar9 = host_client;
      iVar8 = svs.maxclients;
      pcVar14 = svs.clients;
      if (0 < svs.maxclients) {
        do {
          if (((pcVar14 == pcVar9) || (pcVar14->active != false)) ||
             ((pcVar14->connected != false || (pcVar14->spawned != false)))) {
            iVar8 = (int)pcVar14 - (int)svs.clients;
            Q_strncpy(acStack_10120,pcVar14->userinfo,0xff);
            uStack_10021 = 0;
            Info_RemovePrefixedKeys(acStack_10120,'_');
            MSG_WriteByte(&sStack_1035c,0xd);
            MSG_WriteByte(&sStack_1035c,(iVar8 >> 3) * 0x4ffec005);
            MSG_WriteLong(&sStack_1035c,pcVar14->userid);
            MSG_WriteString(&sStack_1035c,acStack_10120);
            MD5Init(&MStack_102f8);
            MD5Update(&MStack_102f8,(uchar *)pcVar14->hashedcdkey,0x40);
            MD5Final(auStack_10348,&MStack_102f8);
            MSG_WriteBuf(&sStack_1035c,0x10,auStack_10348);
            pcVar9 = host_client;
            iVar8 = svs.maxclients;
          }
          iVar12 = iVar12 + 1;
          pcVar14 = pcVar14 + 1;
        } while (iVar12 < iVar8);
      }
      Netchan_CreateFragments(true,&pcVar9->netchan,&sStack_1035c);
      Netchan_FragSend(&host_client->netchan);
      host_client->m_bSentNewResponse = true;
    }
  }
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_ParseConsistencyResponse  @ 0009fb20
void SV_ParseConsistencyResponse(client_t *pSenderClient)

{
  uchar *src;
  int iVar1;
  char *pcVar2;
  uint32 uVar3;
  uint32 uVar4;
  int iVar5;
  int in_GS_OFFSET;
  int local_1c8;
  int local_1c4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  float local_19c;
  float local_198;
  float local_194;
  float local_190;
  float local_18c;
  float local_188;
  float local_184;
  undefined1 local_180 [32];
  undefined1 local_160 [32];
  uchar local_140;
  undefined1 local_13f [12];
  undefined1 local_133 [19];
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: int value@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * r@[???]
                       Unresolved local var: int dropclient@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: vec3_t cmins@[???]
                       Unresolved local var: vec3_t cmaxs@[???]
                       Unresolved local var: byte[32] readbuffer@[???]
                       Unresolved local var: byte[32] nullbuffer@[???]
                       Unresolved local var: byte[32] resbuffer@[???]
                       Unresolved local var: FORCE_TYPE ft@[???]
                       Unresolved local var: int length@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_160,0,0x20);
  iVar1 = MSG_ReadShort();
  if ((iVar1 < 1) || (net_message.cursize < iVar1 + msg_readcount)) {
    pcVar2 = NET_AdrToString((host_client->netchan).remote_address);
    Con_Printf("SV_ParseConsistencyResponse:  %s:%s sent invalid message length: %d\n",
               host_client->name,pcVar2,iVar1);
    SV_DropClient(host_client,false,"Invalid ParseConsistency message");
    msg_badread = true;
  }
  else {
    COM_UnMunge(net_message.data + msg_readcount,iVar1,svs.spawncount);
    MSG_StartBitReading(&net_message);
    local_1c8 = 0;
    local_1c4 = 0;
    while (uVar4 = MSG_ReadBits(1), uVar4 != 0) {
      uVar4 = MSG_ReadBits(0xc);
      if ((((int)uVar4 < 0) || (sv.num_resources <= (int)uVar4)) ||
         (-1 < (char)sv.resourcelist[uVar4].ucFlags)) {
        MSG_EndBitReading(&net_message);
        goto LAB_0009fdbc;
      }
      src = sv.resourcelist[uVar4].rguc_reserved;
      Q_memcpy(local_180,src,0x20);
      iVar5 = Q_memcmp(local_180,local_160,0x20);
      iVar1 = local_1c8;
      if (iVar5 == 0) {
        uVar3 = MSG_ReadBits(0x20);
        iVar1 = uVar4 + 1;
        if (uVar3 == *(uint32 *)sv.resourcelist[uVar4].rgucMD5_hash) {
          iVar1 = local_1c8;
        }
      }
      else {
        MSG_ReadBitData(&local_198,0xc);
        MSG_ReadBitData(&local_18c,0xc);
        Q_memcpy(&local_140,src,0x20);
        COM_UnMunge(&local_140,0x20,svs.spawncount);
        if (local_140 == '\x02') {
          Q_memcpy(&local_1b0,local_13f,0xc);
          Q_memcpy(&local_1a4,local_133,0xc);
          if ((((local_198 < local_1b0) || (local_1a4 < local_18c)) ||
              ((local_194 < local_1ac || ((local_1a0 < local_188 || (local_190 < local_1a8)))))) ||
             (local_19c < local_184)) {
LAB_0009fe98:
            iVar1 = uVar4 + 1;
          }
        }
        else if (local_140 == '\x03') {
          Q_memcpy(&local_1b0,local_13f,0xc);
          Q_memcpy(&local_1a4,local_133,0xc);
          if ((((((local_198 != -1.0) || (local_194 != -1.0)) || (local_190 != -1.0)) ||
               ((local_18c != -1.0 || (local_188 != -1.0)))) || (local_184 != -1.0)) &&
             (((local_198 < local_1b0 || (local_1a4 < local_18c)) ||
              ((local_194 < local_1ac ||
               (((local_1a0 < local_188 || (local_190 < local_1a8)) || (local_19c < local_184)))))))
             ) goto LAB_0009fe98;
        }
        else {
          if (local_140 != '\x01') {
            msg_badread = true;
            local_1c8 = uVar4 + 1;
            break;
          }
          Q_memcpy(&local_1b0,local_13f,0xc);
          Q_memcpy(&local_1a4,local_133,0xc);
          iVar5 = VectorCompare(&local_198,&local_1b0);
          if ((iVar5 == 0) || (iVar5 = VectorCompare(&local_18c,&local_1a4), iVar5 == 0))
          goto LAB_0009fe98;
        }
      }
      local_1c8 = iVar1;
      if (msg_badread != false) break;
      local_1c4 = local_1c4 + 1;
    }
    MSG_EndBitReading(&net_message);
    if ((local_1c8 < 0) || (local_1c4 != sv.num_consistency)) {
LAB_0009fdbc:
      msg_badread = true;
      pcVar2 = NET_AdrToString((host_client->netchan).remote_address);
      Con_Printf("SV_ParseConsistencyResponse:  %s:%s sent bad file data\n",host_client->name,pcVar2
                );
      SV_DropClient(host_client,false,"Bad file data");
    }
    else if (local_1c8 == 0) {
      host_client->has_force_unmodified = false;
    }
    else {
                    /* Unresolved local var: char[256] dropmessage@[???] */
      local_120[0] = '\0';
      iVar1 = (*gEntityInterface.pfnInconsistentFile)
                        (host_client->edict,(char *)((local_1c8 + -1) * 0x88 + 0x4ff3c0),local_120);
      if (iVar1 != 0) {
        iVar1 = Q_strlen(local_120);
        if (0 < iVar1) {
          SV_ClientPrintf("%s",local_120);
        }
        SV_DropClient(host_client,false,"Bad file %s",local_120);
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_ParseCvarValue  @ 000a01e0
void SV_ParseCvarValue(client_t *cl)

{
  char *pcVar1;
  
                    /* Unresolved local var: char * value@[???] */
  pcVar1 = MSG_ReadString();
  if (gNewDLLFunctions.pfnCvarValue != (_func_void_edict_t_ptr_char_ptr *)0x0) {
    (*gNewDLLFunctions.pfnCvarValue)(cl->edict,pcVar1);
  }
  Con_DPrintf("Cvar query response: name:%s, value:%s\n",cl->name,pcVar1);
  return;
}


// SV_ParseCvarValue2  @ 000a0410
void SV_ParseCvarValue2(client_t *cl)

{
  int iVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  char local_11f [254];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: char * value@[???]
                       Unresolved local var: char[255] cvarName@[???]
                       Unresolved local var: int requestID@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = MSG_ReadLong();
  pcVar2 = MSG_ReadString();
  Q_strncpy(local_11f,pcVar2,0xff);
  local_21 = 0;
  pcVar2 = MSG_ReadString();
  if (gNewDLLFunctions.pfnCvarValue2 != (_func_void_edict_t_ptr_int_char_ptr_char_ptr *)0x0) {
    (*gNewDLLFunctions.pfnCvarValue2)(cl->edict,iVar1,local_11f,pcVar2);
  }
  Con_DPrintf("Cvar query response: name:%s, request ID %d, cvar:%s, value:%s\n",cl->name,iVar1,
              local_11f,pcVar2);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_ParseDelta  @ 000a0240
void SV_ParseDelta(client_t *pSenderClient)

{
  client_t *pcVar1;
  int iVar2;
  
  pcVar1 = host_client;
  iVar2 = MSG_ReadByte();
  pcVar1->delta_sequence = iVar2;
  return;
}


// SV_ParseMove  @ 000a4890
void SV_ParseMove(client_t *pSenderClient)

{
  byte bVar1;
  client_frame_t *pcVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  double dVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  byte *pbVar16;
  int iVar17;
  byte *pbVar18;
  usercmd_t *puVar19;
  edict_t *peVar20;
  uint uVar21;
  usercmd_t *puVar22;
  int iVar23;
  client_t *pcVar24;
  bool bVar25;
  char *pcVar26;
  byte local_d84;
  usercmd_t local_d50;
  usercmd_t local_d1c [64];
  
                    /* Unresolved local var: usercmd_t[64] cmds@[???]
                       Unresolved local var: usercmd_t * from@[???]
                       Unresolved local var: usercmd_t * to@[???]
                       Unresolved local var: int numbackup@[???]
                       Unresolved local var: int numcmds@[???]
                       Unresolved local var: int totalcmds@[???]
                       Unresolved local var: float packet_loss@[???]
                       Unresolved local var: usercmd_t cmdNull@[???]
                       Unresolved local var: byte cbpktchecksum@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: int bits@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int placeholder@[???]
                       Unresolved local var: byte cbchecksum@[???]
                       Unresolved local var: int mlen@[???]
                       Unresolved local var: int packetLossByte@[???] */
  iVar7 = SV_UPDATE_MASK;
  if (g_balreadymoved != false) {
    msg_badread = true;
    return;
  }
  g_balreadymoved = true;
  pcVar2 = host_client->frames;
  uVar15 = (host_client->netchan).incoming_acknowledged;
  Q_memset(&local_d50,0,0x34);
  iVar14 = msg_readcount;
  iVar9 = MSG_ReadByte();
  iVar10 = MSG_ReadByte();
  if ((iVar9 < 1) || (iVar17 = iVar14 + 2, net_message.maxsize < iVar17 + iVar9)) {
    Con_Printf("SV_ParseMove: invalid length: %d\n",iVar9);
    pcVar26 = "Invalid Move message";
LAB_000a494f:
    SV_DropClient(host_client,false,pcVar26);
    msg_badread = true;
    return;
  }
  COM_UnMunge(net_message.data + iVar17,iVar9,(host_client->netchan).incoming_sequence);
  uVar11 = MSG_ReadByte();
  pSenderClient->m_bLoopback = uVar11 >> 7 & true;
  iVar9 = MSG_ReadByte();
  iVar12 = MSG_ReadByte();
  uVar21 = iVar9 + iVar12;
  iVar13 = iVar12 + -1;
  net_drop = net_drop - iVar13;
  if (0x3e < uVar21) {
    pcVar26 = NET_AdrToString((host_client->netchan).remote_address);
    Con_Printf("SV_ReadClientMessage: too many cmds %i sent for %s/%s\n",uVar21,host_client->name,
               pcVar26);
    pcVar26 = "CMD_MAXBACKUP hit";
    goto LAB_000a494f;
  }
  iVar23 = uVar21 - 1;
  if (iVar23 != -1) {
    puVar19 = &local_d50;
    puVar22 = local_d1c + iVar23;
    do {
      iVar23 = iVar23 + -1;
      MSG_ReadUsercmd(puVar22,puVar19);
      puVar19 = puVar22;
      puVar22 = puVar22 + -1;
    } while (iVar23 != -1);
  }
  if (sv.active == false) {
    return;
  }
  if ((host_client->active == false) && (host_client->spawned == false)) {
    return;
  }
  if (msg_badread != false) {
    pcVar26 = NET_AdrToString((host_client->netchan).remote_address);
    Con_Printf("Client %s:%s sent a bogus command packet\n",host_client->name,pcVar26);
    return;
  }
  bVar8 = COM_BlockSequenceCRCByte
                    (net_message.data + iVar17,~(iVar14 + 1U) + msg_readcount,
                     (host_client->netchan).incoming_sequence);
  pcVar24 = host_client;
  local_d84 = (byte)iVar10;
  if (bVar8 != local_d84) {
    pcVar26 = NET_AdrToString((host_client->netchan).remote_address);
    Con_DPrintf("Failed command checksum for %s:%s\n",host_client->name,pcVar26);
    msg_badread = true;
    return;
  }
  bVar25 = sv.paused == false;
  host_client->packet_loss = (float)(int)(uVar11 & 0xffffff7f);
  peVar20 = sv_player;
  iVar14 = net_drop;
  if ((bVar25) &&
     (((1 < svs.maxclients || (key_dest == key_game)) && (((sv_player->v).flags & 0x1000) == 0)))) {
    (sv_player->v).button = (uint)local_d1c[0].buttons;
    dVar5 = sv.time;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: double runcmd_time@[???]
                       Unresolved local var: double time_at_end@[???] */
    (peVar20->v).v_angle[0] = local_d1c[0].viewangles[0];
    (peVar20->v).v_angle[1] = local_d1c[0].viewangles[1];
    (peVar20->v).v_angle[2] = local_d1c[0].viewangles[2];
    (peVar20->v).light_level = (uint)local_d1c[0].lightlevel;
    dVar5 = dVar5 + host_frametime;
    if (iVar14 < 0x18) goto LAB_000a4e3b;
    if (iVar13 < 0) {
      pcVar24->svtimebase = dVar5;
      goto LAB_000a4cec;
    }
    dVar6 = 0.0;
LAB_000a4c5e:
    puVar19 = local_d1c + iVar12;
    do {
      puVar22 = puVar19 + -1;
      puVar19 = puVar19 + -1;
      dVar6 = (double)puVar22->msec / 1000.0 + dVar6;
    } while (puVar19 != local_d1c);
    pcVar24->svtimebase = dVar5 - dVar6;
    if (iVar14 < 0x18) goto joined_r0x000a4ee3;
  }
  else {
    if (0 < iVar12) {
      pbVar18 = &local_d1c[0].msec;
      do {
        *pbVar18 = '\0';
        *(float *)(pbVar18 + 0xe) = 0.0;
        *(float *)(pbVar18 + 0x12) = 0.0;
        *(float *)(pbVar18 + 0x16) = 0.0;
        *(ushort *)(pbVar18 + 0x1c) = 0;
        if (((sv_player->v).flags & 0x1000) != 0) {
          pbVar18[0x1e] = '\0';
        }
        pbVar16 = pbVar18 + 0x34;
        *(vec_t *)(pbVar18 + 2) = (sv_player->v).v_angle[0];
        *(vec_t *)(pbVar18 + 6) = (sv_player->v).v_angle[1];
        *(vec_t *)(pbVar18 + 10) = (sv_player->v).v_angle[2];
        pbVar18 = pbVar16;
      } while (pbVar16 != &local_d1c[iVar12].msec);
    }
    iVar14 = 0;
    dVar5 = host_frametime + sv.time;
    net_drop = 0;
    (sv_player->v).button = (uint)local_d1c[0].buttons;
    (peVar20->v).light_level = (uint)local_d1c[0].lightlevel;
LAB_000a4e3b:
    if (iVar9 < iVar14) {
      dVar6 = 0.0;
      iVar17 = iVar14;
      do {
        iVar17 = iVar17 + -1;
        dVar6 = dVar6 + (double)(pcVar24->lastcmd).msec / 1000.0;
        iVar10 = iVar9;
      } while (iVar9 != iVar17);
    }
    else {
      dVar6 = 0.0;
      iVar10 = iVar14;
    }
    if (0 < iVar10) {
                    /* Unresolved local var: int cmdnum@[???] */
      pbVar18 = &(&local_d50)[iVar10 + iVar12].msec;
      do {
        bVar1 = *pbVar18;
        pbVar18 = pbVar18 + -0x34;
        dVar6 = (double)bVar1 / 1000.0 + dVar6;
      } while (pbVar18 != &(&local_d50)[iVar12].msec);
    }
    if (-1 < iVar13) goto LAB_000a4c5e;
    pcVar24->svtimebase = dVar5 - dVar6;
joined_r0x000a4ee3:
    while (iVar9 < iVar14) {
      SV_RunCmd(&pcVar24->lastcmd,0);
      iVar14 = net_drop + -1;
      pcVar24 = host_client;
      net_drop = iVar14;
    }
    while (0 < iVar14) {
                    /* Unresolved local var: int cmdnum@[???] */
      iVar14 = iVar12 + -1 + iVar14;
      SV_RunCmd(local_d1c + iVar14,(pcVar24->netchan).incoming_sequence - iVar14);
      iVar14 = net_drop + -1;
      pcVar24 = host_client;
      net_drop = iVar14;
    }
    peVar20 = sv_player;
    if (iVar13 < 0) goto LAB_000a4cec;
  }
  puVar19 = local_d1c + iVar13;
  do {
    iVar14 = (pcVar24->netchan).incoming_sequence - iVar13;
    iVar13 = iVar13 + -1;
    SV_RunCmd(puVar19,iVar14);
    peVar20 = sv_player;
    puVar19 = puVar19 + -1;
    pcVar24 = host_client;
  } while (iVar13 != -1);
LAB_000a4cec:
  uVar15 = uVar15 & iVar7;
  uVar11 = 0;
  do {
    *(undefined4 *)((int)(pcVar24->lastcmd).viewangles + (uVar11 - 4)) =
         *(undefined4 *)((int)local_d1c[0].viewangles + (uVar11 - 4));
    uVar11 = uVar11 + 4;
  } while (uVar11 < 0x34);
  fVar3 = pcVar2[uVar15].ping_time - ((float)(pcVar24->lastcmd).msec * 0.5) / 1000.0;
  fVar4 = 0.0;
  if (0.0 <= fVar3) {
    fVar4 = fVar3;
  }
  pcVar2[uVar15].ping_time = fVar4;
  if ((longdouble)(peVar20->v).animtime <= (longdouble)sv.time + (longdouble)host_frametime) {
    return;
  }
  (peVar20->v).animtime = (float)((longdouble)sv.time + (longdouble)host_frametime);
  return;
}


// SV_ParseResourceList  @ 0009f2e0
void SV_ParseResourceList(client_t *pSenderClient)

{
  resource_s *prVar1;
  float fVar2;
  int iVar3;
  resource_s *prVar4;
  char *src;
  resourcetype_t rVar5;
  int iVar6;
  uint uVar7;
  resource_s *prVar8;
  int iVar9;
  qboolean qVar10;
  resource_t *prVar11;
  client_t *pcVar12;
  int iVar13;
  client_t *pcVar14;
  double dVar15;
  resourceinfo_t local_3c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int total@[???]
                       Unresolved local var: int totalsize@[???]
                       Unresolved local var: resource_t * resource@[???]
                       Unresolved local var: resourceinfo_t ri@[???]
                       Unresolved local var: int maxupload@[???] */
  iVar3 = MSG_ReadShort();
  pcVar14 = host_client;
  iVar9 = iVar3;
  if (((0.0 < sv_max_upload_count.value) &&
      (iVar9 = (int)sv_max_upload_count.value, iVar3 <= (int)sv_max_upload_count.value)) &&
     (iVar9 = 0, -1 < iVar3)) {
    iVar9 = iVar3;
  }
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  prVar11 = &host_client->resourcesneeded;
  prVar4 = (host_client->resourcesneeded).pNext;
  pcVar12 = host_client;
  while ((host_client = pcVar12, prVar4 != (resource_s *)0x0 && (prVar11 != prVar4))) {
    prVar8 = prVar4->pNext;
    prVar4->pPrev->pNext = prVar8;
    prVar4->pNext->pPrev = prVar4->pPrev;
    prVar4->pPrev = (resource_s *)0x0;
    prVar4->pNext = (resource_s *)0x0;
    Mem_Free(prVar4);
    prVar4 = prVar8;
    pcVar12 = host_client;
  }
  (pcVar14->resourcesneeded).pPrev = prVar11;
  (pcVar14->resourcesneeded).pNext = prVar11;
  prVar11 = &pcVar12->resourcesonhand;
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  prVar4 = (pcVar12->resourcesonhand).pNext;
  fVar2 = sv_max_upload.value;
  while ((sv_max_upload.value = fVar2, prVar4 != (resource_s *)0x0 && (prVar11 != prVar4))) {
    prVar8 = prVar4->pNext;
    prVar4->pPrev->pNext = prVar8;
    prVar4->pNext->pPrev = prVar4->pPrev;
    prVar4->pPrev = (resource_s *)0x0;
    prVar4->pNext = (resource_s *)0x0;
    Mem_Free(prVar4);
    prVar4 = prVar8;
    fVar2 = sv_max_upload.value;
  }
  iVar3 = 0x40000000;
  (pcVar12->resourcesonhand).pPrev = prVar11;
  (pcVar12->resourcesonhand).pNext = prVar11;
  if (0.0 < fVar2) {
    iVar3 = (int)(fVar2 * 1048576.0);
  }
  if (0 < iVar9) {
    iVar13 = 0;
    do {
      prVar4 = Mem_ZeroMalloc(0x88);
      src = MSG_ReadString();
      Q_strncpy(prVar4->szFileName,src,0x3f);
      prVar4->szFileName[0x3f] = '\0';
      rVar5 = MSG_ReadByte();
      prVar4->type = rVar5;
      iVar6 = MSG_ReadShort();
      prVar4->nIndex = iVar6;
      iVar6 = MSG_ReadLong();
      prVar4->nDownloadSize = iVar6;
      uVar7 = MSG_ReadByte();
      prVar4->pPrev = (resource_s *)0x0;
      prVar4->pNext = (resource_s *)0x0;
      prVar4->ucFlags = (byte)uVar7 & 0xfd;
      if (((uVar7 & 4) == 0) ||
         ((MSG_ReadBuf(0x10,prVar4->rgucMD5_hash), prVar4->pPrev == (resource_s *)0x0 &&
          (prVar4->pNext == (resource_s *)0x0)))) {
        pcVar14 = host_client;
        prVar11 = &host_client->resourcesneeded;
        prVar4->pPrev = (host_client->resourcesneeded).pPrev;
        ((pcVar14->resourcesneeded).pPrev)->pNext = prVar4;
        qVar10 = msg_badread;
        (pcVar14->resourcesneeded).pPrev = prVar4;
        prVar4->pNext = prVar11;
        pcVar14 = host_client;
      }
      else {
        Con_Printf("Resource already linked\n");
        pcVar14 = host_client;
        qVar10 = msg_badread;
      }
      host_client = pcVar14;
      if (qVar10 != false) {
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
        prVar4 = (pcVar14->resourcesneeded).pNext;
        prVar11 = &pcVar14->resourcesneeded;
        if ((prVar11 == prVar4) || (prVar4 == (resource_s *)0x0)) goto LAB_0009f5c4;
        goto LAB_0009f57c;
      }
      if (((t_world < prVar4->type) || (iVar3 < prVar4->nDownloadSize)) ||
         (prVar4->nDownloadSize < 0)) {
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
        prVar4 = (pcVar14->resourcesneeded).pNext;
        prVar11 = &pcVar14->resourcesneeded;
        if ((prVar4 == (resource_s *)0x0) || (prVar11 == prVar4)) goto LAB_0009f6bc;
        goto LAB_0009f674;
      }
      iVar13 = iVar13 + 1;
    } while (iVar9 != iVar13);
  }
  if (sv_allow_upload.value != 0.0) {
    Con_DPrintf("Verifying and uploading resources...\n");
  }
  iVar9 = COM_SizeofResourceList(&host_client->resourcesneeded,&local_3c);
  if (iVar9 != 0) {
                    /* Unresolved local var: int bytestodownload@[???] */
    dVar15 = (double)((float)iVar9 * 0.0009765625);
    Con_DPrintf("Custom resources total %.2fK\n",dVar15);
    if (local_3c.info[2].size != 0) {
      dVar15 = (double)local_3c.info[2].size * 0.0009765625;
      Con_DPrintf("  Models:  %.2fK\n",dVar15);
    }
    if (local_3c.info[0].size != 0) {
      dVar15 = (double)((float)local_3c.info[0].size * 0.0009765625);
      Con_DPrintf("  Sounds:  %.2fK\n",dVar15);
    }
    if (local_3c.info[3].size != 0) {
      dVar15 = (double)((float)local_3c.info[3].size * 0.0009765625);
      Con_DPrintf("  Decals:  %.2fK\n",dVar15);
    }
    if (local_3c.info[1].size != 0) {
      dVar15 = (double)((float)local_3c.info[1].size * 0.0009765625);
      Con_DPrintf("  Skins :  %.2fK\n",dVar15);
    }
    if (local_3c.info[4].size != 0) {
      dVar15 = (double)((float)local_3c.info[4].size * 0.0009765625);
      Con_DPrintf("  Generic :  %.2fK\n",dVar15);
    }
    if (local_3c.info[5].size != 0) {
      dVar15 = (double)((float)local_3c.info[5].size * 0.0009765625);
      Con_DPrintf("  Events  :  %.2fK\n",dVar15);
    }
    Con_DPrintf("----------------------\n",dVar15);
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: int missing@[???]
                       Unresolved local var: int size@[???] */
    prVar8 = (host_client->resourcesneeded).pNext;
    prVar4 = &host_client->resourcesneeded;
    pcVar14 = host_client;
    if (prVar8 == prVar4) {
      pcVar12 = host_client;
      if (iVar3 < 0) goto LAB_0009fa6c;
      iVar9 = 0;
    }
    else {
      iVar9 = 0;
      do {
        while (prVar8->type != t_decal) {
          prVar8 = prVar8->pNext;
          if (prVar8 == prVar4) goto LAB_0009f898;
        }
        qVar10 = HPAK_ResourceForHash("custom.hpk",prVar8->rgucMD5_hash,(resource_s *)0x0);
        if ((qVar10 == false) && (prVar8->nDownloadSize != 0)) {
          prVar8->ucFlags = prVar8->ucFlags | 2;
          iVar9 = iVar9 + prVar8->nDownloadSize;
        }
        prVar8 = prVar8->pNext;
        prVar4 = &host_client->resourcesneeded;
        pcVar14 = host_client;
      } while (prVar8 != prVar4);
LAB_0009f898:
      if (iVar3 < iVar9) {
        prVar8 = (pcVar14->resourcesneeded).pNext;
        pcVar12 = pcVar14;
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
        while ((prVar8 != (resource_s *)0x0 && (prVar8 != prVar4))) {
          prVar1 = prVar8->pNext;
          prVar8->pPrev->pNext = prVar1;
          prVar8->pNext->pPrev = prVar8->pPrev;
          prVar8->pPrev = (resource_s *)0x0;
          prVar8->pNext = (resource_s *)0x0;
          Mem_Free(prVar8);
          prVar8 = prVar1;
          pcVar12 = host_client;
        }
LAB_0009fa6c:
        (pcVar14->resourcesneeded).pPrev = prVar4;
        (pcVar14->resourcesneeded).pNext = prVar4;
        prVar11 = &pcVar12->resourcesonhand;
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
        prVar4 = (pcVar12->resourcesonhand).pNext;
        while ((prVar4 != (resource_s *)0x0 && (prVar4 != prVar11))) {
          prVar8 = prVar4->pNext;
          prVar4->pPrev->pNext = prVar8;
          prVar4->pNext->pPrev = prVar4->pPrev;
          prVar4->pPrev = (resource_s *)0x0;
          prVar4->pNext = (resource_s *)0x0;
          Mem_Free(prVar4);
          prVar4 = prVar8;
        }
        (pcVar12->resourcesonhand).pPrev = prVar11;
        (pcVar12->resourcesonhand).pNext = prVar11;
        return;
      }
      if (0x400 < iVar9) {
        Con_DPrintf("Resources to request: %.2fK\n",(double)((float)iVar9 * 0.0009765625));
        goto LAB_0009f8c6;
      }
    }
    Con_DPrintf("Resources to request: %i bytes\n",iVar9);
  }
LAB_0009f8c6:
  pcVar14 = host_client;
  host_client->uploading = true;
  pcVar14->uploaddoneregistering = false;
  SV_BatchUploadRequest(pcVar14);
  return;
  while (prVar4 = prVar8, prVar11 != prVar8) {
LAB_0009f57c:
    prVar8 = prVar4->pNext;
    prVar4->pPrev->pNext = prVar8;
    prVar4->pNext->pPrev = prVar4->pPrev;
    prVar4->pPrev = (resource_s *)0x0;
    prVar4->pNext = (resource_s *)0x0;
    Mem_Free(prVar4);
    if (prVar8 == (resource_s *)0x0) break;
  }
LAB_0009f5c4:
  pcVar12 = host_client;
  (pcVar14->resourcesneeded).pPrev = prVar11;
  (pcVar14->resourcesneeded).pNext = prVar11;
  prVar4 = &pcVar12->resourcesonhand;
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  prVar8 = (pcVar12->resourcesonhand).pNext;
  while ((prVar8 != (resource_s *)0x0 && (prVar4 != prVar8))) {
    prVar1 = prVar8->pNext;
    prVar8->pPrev->pNext = prVar1;
    prVar8->pNext->pPrev = prVar8->pPrev;
    prVar8->pPrev = (resource_s *)0x0;
    prVar8->pNext = (resource_s *)0x0;
    Mem_Free(prVar8);
    prVar8 = prVar1;
  }
  goto LAB_0009f630;
  while (prVar4 = prVar8, prVar11 != prVar8) {
LAB_0009f674:
    prVar8 = prVar4->pNext;
    prVar4->pPrev->pNext = prVar8;
    prVar4->pNext->pPrev = prVar4->pPrev;
    prVar4->pPrev = (resource_s *)0x0;
    prVar4->pNext = (resource_s *)0x0;
    Mem_Free(prVar4);
    if (prVar8 == (resource_s *)0x0) break;
  }
LAB_0009f6bc:
  pcVar12 = host_client;
  (pcVar14->resourcesneeded).pPrev = prVar11;
  (pcVar14->resourcesneeded).pNext = prVar11;
  prVar4 = &pcVar12->resourcesonhand;
  prVar8 = (pcVar12->resourcesonhand).pNext;
  if ((prVar4 != prVar8) && (prVar8 != (resource_s *)0x0)) {
    do {
      prVar1 = prVar8->pNext;
      prVar8->pPrev->pNext = prVar1;
      prVar8->pNext->pPrev = prVar8->pPrev;
      prVar8->pPrev = (resource_s *)0x0;
      prVar8->pNext = (resource_s *)0x0;
      Mem_Free(prVar8);
      if (prVar1 == (resource_s *)0x0) break;
      prVar8 = prVar1;
    } while (prVar4 != prVar1);
  }
LAB_0009f630:
                    /* Unresolved local var: resource_t * p@[???]
                       Unresolved local var: resource_t * n@[???] */
  (pcVar12->resourcesonhand).pPrev = prVar4;
  (pcVar12->resourcesonhand).pNext = prVar4;
  return;
}


// SV_ParseStringCommand  @ 000a0500
void SV_ParseStringCommand(client_t *pSenderClient)

{
  char *data;
  command_t cVar1;
  int iVar2;
  command_t *pcVar3;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: int ret@[???] */
  data = MSG_ReadString();
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: int i@[???] */
  COM_Parse(data);
  if (clcommands[0].command != (char *)0x0) {
    pcVar3 = clcommands;
    cVar1 = clcommands[0];
    do {
      pcVar3 = pcVar3 + 1;
      iVar2 = Q_strcasecmp(com_token,cVar1.command);
      if (iVar2 == 0) {
        Cmd_ExecuteString(data,src_client);
        return;
      }
      cVar1.command = pcVar3->command;
    } while (cVar1.command != (char *)0x0);
  }
  iVar2 = Q_strlen(data);
  if (0x7f < iVar2) {
    data[0x7f] = '\0';
  }
  Cmd_TokenizeString(data);
                    /* WARNING: Could not recover jumptable at 0x000a0587. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEntityInterface.pfnClientCommand)(sv_player);
  return;
}


// SV_ParseVoiceData  @ 000a0260
void SV_ParseVoiceData(client_t *cl)

{
  client_s *pcVar1;
  uint iSize;
  uint iSize_00;
  int iVar2;
  client_s *pcVar3;
  sizebuf_t *sb;
  int in_GS_OFFSET;
  undefined1 local_1020 [4096];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int iClient@[???]
                       Unresolved local var: int nDataLength@[???]
                       Unresolved local var: char[4096] chReceived@[???]
                       Unresolved local var: client_t * pDestClient@[???] */
  pcVar1 = svs.clients;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iSize = MSG_ReadShort();
  if (iSize < 0x1001) {
    MSG_ReadBuf(iSize,local_1020);
    cl->m_lastvoicetime = sv.time;
    if (sv_voiceenable.value != 0.0) {
      iVar2 = 0;
                    /* Unresolved local var: qboolean bLocal@[???]
                       Unresolved local var: int nSendLength@[???] */
      do {
        pcVar3 = svs.clients + iVar2;
        if ((((cl->m_VoiceStreams[0] & 1 << ((byte)iVar2 & 0x1f)) != 0) || (cl == pcVar3)) &&
           ((pcVar3->active != false || (cl == pcVar3 || pcVar3->connected != false)))) {
          iSize_00 = iSize;
          if ((cl == pcVar3) && (iSize_00 = 0, cl->m_bLoopback != false)) {
            iSize_00 = iSize;
          }
          if ((int)((pcVar3->datagram).cursize + iSize + 6) < (pcVar3->datagram).maxsize) {
            sb = &pcVar3->datagram;
            MSG_WriteByte(sb,0x35);
            MSG_WriteByte(sb,((int)cl - (int)pcVar1 >> 3) * 0x4ffec005 & 0xff);
            MSG_WriteShort(sb,iSize_00);
            MSG_WriteBuf(sb,iSize_00,local_1020);
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x20);
    }
  }
  else {
    Con_DPrintf("SV_ParseVoiceData: invalid incoming packet.\n");
    SV_DropClient(cl,false,"Invalid voice data\n");
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_Physics  @ 0009de40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Physics(void)

{
  vec_t *pvVar1;
  edict_t *peVar2;
  vec_t vVar3;
  vec_t vVar4;
  uint uVar5;
  int iVar6;
  edict_t *ent;
  int iVar7;
  int iVar8;
  longdouble lVar9;
  longdouble lVar10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: edict_t * groundentity@[???] */
  iVar8 = 0;
  gGlobalVariables.time = (float)sv.time;
  (*gEntityInterface.pfnStartFrame)();
  if (0 < sv.num_edicts) {
    iVar7 = 0;
    iVar6 = sv.num_edicts;
    do {
      ent = (edict_t *)((int)(sv.edicts)->leafnums + iVar8 + -0x18);
      if (ent->free == false) {
        if (gGlobalVariables.force_retouch != 0.0) {
          SV_LinkEdict(ent,true);
        }
        if ((iVar7 < 1) || (iVar6 = sv.num_edicts, svs.maxclients < iVar7)) {
          uVar5 = (ent->v).flags;
          if (((uVar5 & 0x200) != 0) &&
             ((peVar2 = (ent->v).groundentity, peVar2 != (edict_t *)0x0 &&
              (((peVar2->v).flags & 4) != 0)))) {
            pvVar1 = (ent->v).basevelocity;
            if ((uVar5 & 0x400000) == 0) {
              VectorScale((peVar2->v).movedir,(peVar2->v).speed,pvVar1);
            }
            else {
              VectorMA(pvVar1,(peVar2->v).speed,(peVar2->v).movedir,pvVar1);
            }
            uVar5 = (ent->v).flags | 0x400000;
            (ent->v).flags = uVar5;
          }
          if ((uVar5 & 0x400000) == 0) {
            pvVar1 = (ent->v).velocity;
            VectorMA(pvVar1,(float)host_frametime * 0.5 + 1.0,(ent->v).basevelocity,pvVar1);
            vVar4 = vec3_origin[2];
            vVar3 = vec3_origin[1];
            uVar5 = (ent->v).flags;
            (ent->v).basevelocity[0] = vec3_origin[0];
            (ent->v).basevelocity[1] = vVar3;
            (ent->v).basevelocity[2] = vVar4;
          }
          (ent->v).flags = uVar5 & 0xffbfffff;
          iVar6 = (ent->v).movetype;
          if (iVar6 == 7) {
            SV_Physics_Pusher(ent);
            goto LAB_0009dfa0;
          }
          if (iVar6 == 0) {
                    /* Unresolved local var: float thinktime@[???] */
            if ((uVar5 & 0x40000000) == 0) {
              lVar9 = (longdouble)(ent->v).nextthink;
              iVar6 = sv.num_edicts;
              if (((longdouble)0 < lVar9) &&
                 (lVar9 <= (longdouble)host_frametime + (longdouble)sv.time)) {
                if (lVar9 < (longdouble)sv.time) {
                  lVar9 = (longdouble)(float)sv.time;
                }
                (ent->v).nextthink = 0.0;
                gGlobalVariables.time = (float)lVar9;
                (*gEntityInterface.pfnThink)(ent);
                iVar6 = sv.num_edicts;
                if (((ent->v).flags & 0x40000000) != 0) goto LAB_0009e130;
              }
              goto LAB_0009dfc5;
            }
LAB_0009e130:
            ED_Free(ent);
          }
          else if (iVar6 == 0xc) {
                    /* Unresolved local var: float thinktime@[???] */
            if ((uVar5 & 0x40000000) == 0) {
              lVar9 = (longdouble)(ent->v).nextthink;
              if (((longdouble)0 < lVar9) &&
                 (lVar9 <= (longdouble)host_frametime + (longdouble)sv.time)) {
                if (lVar9 < (longdouble)sv.time) {
                  lVar9 = (longdouble)(float)sv.time;
                }
                (ent->v).nextthink = 0.0;
                gGlobalVariables.time = (float)lVar9;
                (*gEntityInterface.pfnThink)(ent);
                if (((ent->v).flags & 0x40000000) != 0) goto LAB_0009e2f0;
                iVar6 = sv.num_edicts;
                if (ent->free != false) goto LAB_0009dfc5;
              }
            }
            else {
LAB_0009e2f0:
              ED_Free(ent);
              if (ent->free != false) goto LAB_0009dfa0;
            }
            peVar2 = (ent->v).aiment;
            if (peVar2 == (edict_t *)0x0) {
              Con_DPrintf("%s movetype FOLLOW with NULL aiment\n",pr_strings + (ent->v).classname);
              (ent->v).movetype = 0;
            }
            else {
              (ent->v).origin[0] = (peVar2->v).origin[0] + (ent->v).v_angle[0];
              (ent->v).origin[1] = (peVar2->v).origin[1] + (ent->v).v_angle[1];
              (ent->v).origin[2] = (peVar2->v).origin[2] + (ent->v).v_angle[2];
              (ent->v).angles[0] = (peVar2->v).angles[0];
              (ent->v).angles[1] = (peVar2->v).angles[1];
              (ent->v).angles[2] = (peVar2->v).angles[2];
              SV_LinkEdict(ent,true);
            }
          }
          else if (iVar6 == 8) {
                    /* Unresolved local var: float thinktime@[???] */
            if ((uVar5 & 0x40000000) == 0) {
              lVar9 = (longdouble)(ent->v).nextthink;
              if (lVar9 <= (longdouble)0) {
LAB_0009e288:
                lVar10 = (longdouble)host_frametime;
              }
              else {
                lVar10 = (longdouble)host_frametime;
                if (lVar9 <= (longdouble)sv.time + lVar10) {
                  if (lVar9 < (longdouble)sv.time) {
                    lVar9 = (longdouble)(float)sv.time;
                  }
                  (ent->v).nextthink = 0.0;
                  gGlobalVariables.time = (float)lVar9;
                  (*gEntityInterface.pfnThink)(ent);
                  if (((ent->v).flags & 0x40000000) != 0) goto LAB_0009e3a0;
                  iVar6 = sv.num_edicts;
                  if (ent->free != false) goto LAB_0009dfc5;
                  goto LAB_0009e288;
                }
              }
              pvVar1 = (ent->v).angles;
              VectorMA(pvVar1,(float)lVar10,(ent->v).avelocity,pvVar1);
              pvVar1 = (ent->v).origin;
              VectorMA(pvVar1,(float)host_frametime,(ent->v).velocity,pvVar1);
              SV_LinkEdict(ent,false);
            }
            else {
LAB_0009e3a0:
              ED_Free(ent);
              if (ent->free == false) goto LAB_0009e288;
            }
          }
          else if ((iVar6 == 4) || (iVar6 == 0xd)) {
            SV_Physics_Step(ent);
          }
          else if ((iVar6 - 5U < 2) || (iVar6 - 9U < 3)) {
            SV_Physics_Toss(ent);
          }
          else {
            Sys_Error("SV_Physics: %s bad movetype %d",pr_strings + (ent->v).classname,iVar6);
          }
LAB_0009dfa0:
          iVar6 = sv.num_edicts;
          if (((ent->v).flags & 0x40000000) != 0) {
            ED_Free(ent);
            iVar6 = sv.num_edicts;
          }
        }
      }
LAB_0009dfc5:
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x324;
    } while (iVar7 < iVar6);
  }
  if (gGlobalVariables.force_retouch != 0.0) {
    gGlobalVariables.force_retouch = gGlobalVariables.force_retouch - 1.0;
  }
  return;
}


// SV_Physics_Follow  @ 0009c6e0
void SV_Physics_Follow(edict_t *ent)

{
  edict_t *peVar1;
  longdouble lVar2;
  
                    /* Unresolved local var: float thinktime@[???] */
  if (((ent->v).flags & 0x40000000) == 0) {
    lVar2 = (longdouble)(ent->v).nextthink;
    if ((lVar2 <= (longdouble)0) || ((longdouble)host_frametime + (longdouble)sv.time < lVar2))
    goto LAB_0009c726;
    if (lVar2 < (longdouble)sv.time) {
      lVar2 = (longdouble)(float)sv.time;
    }
    (ent->v).nextthink = 0.0;
    gGlobalVariables.time = (float)lVar2;
    (*gEntityInterface.pfnThink)(ent);
    if (((ent->v).flags & 0x40000000) != 0) goto LAB_0009c6f1;
  }
  else {
LAB_0009c6f1:
    ED_Free(ent);
  }
  if (ent->free != false) {
    return;
  }
LAB_0009c726:
  peVar1 = (ent->v).aiment;
  if (peVar1 == (edict_t *)0x0) {
    Con_DPrintf("%s movetype FOLLOW with NULL aiment\n",pr_strings + (ent->v).classname);
    (ent->v).movetype = 0;
    return;
  }
  (ent->v).origin[0] = (peVar1->v).origin[0] + (ent->v).v_angle[0];
  (ent->v).origin[1] = (peVar1->v).origin[1] + (ent->v).v_angle[1];
  (ent->v).origin[2] = (peVar1->v).origin[2] + (ent->v).v_angle[2];
  (ent->v).angles[0] = (peVar1->v).angles[0];
  (ent->v).angles[1] = (peVar1->v).angles[1];
  (ent->v).angles[2] = (peVar1->v).angles[2];
  SV_LinkEdict(ent,true);
  return;
}


// SV_Physics_Noclip  @ 0009c840
void SV_Physics_Noclip(edict_t *ent)

{
  vec_t *pvVar1;
  qboolean qVar2;
  longdouble lVar3;
  longdouble lVar4;
  
                    /* Unresolved local var: float thinktime@[???] */
  if (((ent->v).flags & 0x40000000) == 0) {
    lVar3 = (longdouble)(ent->v).nextthink;
    if ((longdouble)0 < lVar3) {
      lVar4 = (longdouble)host_frametime;
      if ((longdouble)sv.time + lVar4 < lVar3) goto LAB_0009c8ee;
      if (lVar3 < (longdouble)sv.time) {
        lVar3 = (longdouble)(float)sv.time;
      }
      (ent->v).nextthink = 0.0;
      gGlobalVariables.time = (float)lVar3;
      (*gEntityInterface.pfnThink)(ent);
      if (((ent->v).flags & 0x40000000) != 0) goto LAB_0009c851;
      qVar2 = ent->free;
      goto joined_r0x0009c8d0;
    }
  }
  else {
LAB_0009c851:
    ED_Free(ent);
    qVar2 = ent->free;
joined_r0x0009c8d0:
    if (qVar2 != false) {
      return;
    }
  }
  lVar4 = (longdouble)host_frametime;
LAB_0009c8ee:
  pvVar1 = (ent->v).angles;
  VectorMA(pvVar1,(float)lVar4,(ent->v).avelocity,pvVar1);
  pvVar1 = (ent->v).origin;
  VectorMA(pvVar1,(float)host_frametime,(ent->v).velocity,pvVar1);
  SV_LinkEdict(ent,false);
  return;
}


// SV_Physics_None  @ 0009c630
void SV_Physics_None(edict_t *ent)

{
  longdouble lVar1;
  
                    /* Unresolved local var: float thinktime@[???] */
  if (((ent->v).flags & 0x40000000) == 0) {
    lVar1 = (longdouble)(ent->v).nextthink;
    if (((longdouble)0 < lVar1) && (lVar1 <= (longdouble)host_frametime + (longdouble)sv.time)) {
      if (lVar1 < (longdouble)sv.time) {
        lVar1 = (longdouble)(float)sv.time;
      }
      (ent->v).nextthink = 0.0;
      gGlobalVariables.time = (float)lVar1;
      (*gEntityInterface.pfnThink)(ent);
      if (((ent->v).flags & 0x40000000) != 0) goto LAB_0009c641;
    }
    return;
  }
LAB_0009c641:
  ED_Free(ent);
  return;
}


// SV_Physics_Pusher  @ 0009bbc0
void SV_Physics_Pusher(edict_t *ent)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  vec_t *pvVar6;
  double dVar7;
  
                    /* Unresolved local var: float thinktime@[???]
                       Unresolved local var: float oldltime@[???]
                       Unresolved local var: float movetime@[???]
                       Unresolved local var: int i@[???] */
  fVar1 = (ent->v).ltime;
  fVar2 = (ent->v).nextthink;
  fVar3 = (float)host_frametime;
  if (((fVar1 + fVar3 <= fVar2) || (fVar3 = fVar2 - fVar1, 0.0 <= fVar3)) && (fVar3 != 0.0)) {
    if ((((ent->v).avelocity[0] == 0.0) && ((ent->v).avelocity[1] == 0.0)) &&
       ((ent->v).avelocity[2] == 0.0)) {
      SV_PushMove(ent,fVar3);
    }
    else if ((((ent->v).velocity[0] == 0.0) && ((ent->v).velocity[1] == 0.0)) &&
            ((ent->v).velocity[2] == 0.0)) {
      SV_PushRotate(ent,fVar3);
    }
    else {
                    /* Unresolved local var: float savetime@[???] */
      iVar5 = SV_PushRotate(ent,fVar3);
      if (iVar5 != 0) {
        fVar4 = (ent->v).ltime;
        (ent->v).ltime = fVar1;
        SV_PushMove(ent,fVar3);
        if ((ent->v).ltime < fVar4) {
          (ent->v).ltime = fVar4;
        }
      }
    }
  }
  pvVar6 = (ent->v).angles;
  do {
    fVar3 = *pvVar6;
    if ((fVar3 < -3600.0) || (3600.0 < fVar3)) {
      dVar7 = fmod((double)fVar3,3600.0);
      *pvVar6 = (float)dVar7;
    }
    pvVar6 = pvVar6 + 1;
  } while ((ent->v).avelocity != pvVar6);
  if ((fVar1 < fVar2) && ((((ent->v).flags & 0x200000) != 0 || (fVar2 <= (ent->v).ltime)))) {
    gGlobalVariables.time = (float)sv.time;
    (ent->v).nextthink = 0.0;
                    /* WARNING: Could not recover jumptable at 0x0009bd82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEntityInterface.pfnThink)(ent);
    return;
  }
  return;
}


// SV_Physics_Step  @ 0009d800
void SV_Physics_Step(edict_t *ent)

{
  int *piVar1;
  vec_t *start;
  float fVar2;
  uint uVar3;
  float fVar4;
  qboolean qVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longdouble lVar9;
  float fVar10;
  float fVar11;
  trace_t local_54;
  
                    /* Unresolved local var: qboolean wasonground@[???]
                       Unresolved local var: qboolean inwater@[???]
                       Unresolved local var: qboolean hitsound@[???]
                       Unresolved local var: float * vel@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float newspeed@[???]
                       Unresolved local var: float control@[???]
                       Unresolved local var: float friction@[???] */
  PF_WaterMove(ent);
  SV_CheckVelocity(ent);
  uVar3 = (ent->v).flags;
  qVar5 = SV_CheckWater(ent);
  if ((((ent->v).flags & 0x8000) != 0) && (0 < (ent->v).waterlevel)) {
                    /* Unresolved local var: float waterLevel@[???] */
    fVar10 = SV_Submerged(ent);
    fVar2 = (float)host_frametime;
    iVar6 = (ent->v).skin;
                    /* Unresolved local var: float ent_gravity@[???] */
    fVar11 = (ent->v).gravity;
    fVar4 = 1.0;
    if (fVar11 != 0.0) {
      fVar4 = fVar11;
    }
    (ent->v).velocity[2] =
         fVar2 * (ent->v).basevelocity[2] +
         ((ent->v).velocity[2] - fVar4 * sv_gravity.value * fVar2);
    (ent->v).basevelocity[2] = 0.0;
    SV_CheckVelocity(ent);
    (ent->v).velocity[2] = (float)iVar6 * fVar10 * fVar2 + (ent->v).velocity[2];
  }
  if ((uVar3 & 0x200) == 0) {
    uVar3 = (ent->v).flags;
    if (((uVar3 & 1) == 0) &&
       ((((uVar3 & 2) == 0 || ((ent->v).waterlevel < 1)) && (qVar5 == false)))) {
                    /* Unresolved local var: float ent_gravity@[???] */
      fVar11 = (ent->v).gravity;
      fVar2 = 1.0;
      if (fVar11 != 0.0) {
        fVar2 = fVar11;
      }
      (ent->v).velocity[2] =
           (float)host_frametime * (ent->v).basevelocity[2] +
           ((ent->v).velocity[2] - fVar2 * sv_gravity.value * (float)host_frametime);
      (ent->v).basevelocity[2] = 0.0;
      SV_CheckVelocity(ent);
    }
    iVar6 = VectorCompare((ent->v).velocity,vec_origin);
    if ((iVar6 != 0) && (iVar6 = VectorCompare((ent->v).basevelocity,vec_origin), iVar6 != 0)) {
LAB_0009dc4f:
      if (gGlobalVariables.force_retouch != 0.0) {
                    /* Unresolved local var: trace_t trace@[???] */
        start = (ent->v).origin;
        SV_Move(&local_54,start,(ent->v).mins,(ent->v).maxs,start,0,ent,
                (uint)(ent->v).flags >> 0x17 & true);
        if (((local_54.fraction < 1.0) || ((float)local_54.startsolid != 0.0)) &&
           (local_54.ent != (edict_t *)0x0)) {
          SV_Impact(ent,local_54.ent,&local_54);
        }
      }
      goto LAB_0009daab;
    }
    piVar1 = &(ent->v).flags;
    *piVar1 = *piVar1 & 0xfffffdff;
  }
  else {
    iVar6 = VectorCompare((ent->v).velocity,vec_origin);
    if ((iVar6 != 0) && (iVar6 = VectorCompare((ent->v).basevelocity,vec_origin), iVar6 != 0))
    goto LAB_0009dc4f;
    piVar1 = &(ent->v).flags;
    *piVar1 = *piVar1 & 0xfffffdff;
    if ((0.0 < (ent->v).health) || (qVar5 = SV_CheckBottom(ent), qVar5 != false)) {
      fVar11 = (ent->v).velocity[0];
      fVar2 = (ent->v).velocity[1];
      fVar2 = fVar2 * fVar2 + fVar11 * fVar11;
      fVar11 = SQRT(fVar2);
      if (NAN(fVar11)) {
        fVar11 = sqrtf(fVar2);
      }
      if (fVar11 != 0.0) {
        fVar4 = sv_friction.value * (ent->v).friction;
        (ent->v).friction = 1.0;
        fVar2 = sv_stopspeed.value;
        if (sv_stopspeed.value <= fVar11) {
          fVar2 = fVar11;
        }
        fVar2 = fVar11 - fVar2 * (float)host_frametime * fVar4;
        fVar4 = 0.0;
        if (0.0 <= fVar2) {
          fVar4 = fVar2;
        }
        fVar2 = (ent->v).velocity[0] * (fVar4 / fVar11);
        fVar11 = (fVar4 / fVar11) * (ent->v).velocity[1];
        goto LAB_0009d930;
      }
    }
  }
  fVar2 = (ent->v).velocity[0];
  fVar11 = (ent->v).velocity[1];
LAB_0009d930:
                    /* Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: vec3_t point@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  iVar6 = 1;
  iVar8 = 0;
  (ent->v).velocity[0] = fVar2 + (ent->v).basevelocity[0];
  (ent->v).velocity[1] = fVar11 + (ent->v).basevelocity[1];
  (ent->v).velocity[2] = (ent->v).velocity[2] + (ent->v).basevelocity[2];
  SV_CheckVelocity(ent);
  SV_FlyMove(ent,(float)host_frametime,(trace_t *)0x0);
  SV_CheckVelocity(ent);
  (ent->v).velocity[0] = (ent->v).velocity[0] - (ent->v).basevelocity[0];
  (ent->v).velocity[1] = (ent->v).velocity[1] - (ent->v).basevelocity[1];
  (ent->v).velocity[2] = (ent->v).velocity[2] - (ent->v).basevelocity[2];
  SV_CheckVelocity(ent);
  fVar11 = (ent->v).origin[0] + (ent->v).mins[0];
  fVar2 = (ent->v).origin[1] + (ent->v).mins[1];
  fVar4 = (ent->v).origin[0] + (ent->v).maxs[0];
  fVar10 = (ent->v).origin[1] + (ent->v).maxs[1];
  local_54.inopen = (qboolean)(((ent->v).origin[2] + (ent->v).mins[2]) - 1.0);
  do {
    local_54.startsolid = (qboolean)fVar2;
    if (iVar8 == 0) {
      g_groupmask = (ent->v).groupinfo;
      local_54.allsolid = (qboolean)fVar11;
      iVar7 = SV_PointContents((vec_t *)&local_54);
      if (iVar7 == -2) goto LAB_0009dda0;
      g_groupmask = (ent->v).groupinfo;
      local_54.allsolid = (qboolean)fVar11;
      local_54.startsolid = (qboolean)fVar10;
      iVar7 = SV_PointContents((vec_t *)&local_54);
      if (iVar7 == -2) goto LAB_0009dda0;
    }
    else {
      g_groupmask = (ent->v).groupinfo;
      local_54.allsolid = (qboolean)fVar4;
      iVar7 = SV_PointContents((vec_t *)&local_54);
      if (iVar7 == -2) {
LAB_0009dda0:
        piVar1 = &(ent->v).flags;
        *piVar1 = *piVar1 | 0x200;
      }
      else {
        g_groupmask = (ent->v).groupinfo;
        local_54.allsolid = (qboolean)fVar4;
        local_54.startsolid = (qboolean)fVar10;
        iVar7 = SV_PointContents((vec_t *)&local_54);
        if (iVar7 == -2) goto LAB_0009dda0;
      }
      if (iVar6 == 2) break;
    }
    iVar8 = iVar8 + 1;
    iVar6 = iVar6 + 1;
  } while( true );
  SV_LinkEdict(ent,true);
LAB_0009daab:
                    /* Unresolved local var: float thinktime@[???] */
  if (((ent->v).flags & 0x40000000) == 0) {
    lVar9 = (longdouble)(ent->v).nextthink;
    if ((lVar9 <= (longdouble)0) || ((longdouble)host_frametime + (longdouble)sv.time < lVar9))
    goto LAB_0009dad6;
    if (lVar9 < (longdouble)sv.time) {
      lVar9 = (longdouble)(float)sv.time;
    }
    (ent->v).nextthink = 0.0;
    gGlobalVariables.time = (float)lVar9;
    (*gEntityInterface.pfnThink)(ent);
    if (((ent->v).flags & 0x40000000) == 0) goto LAB_0009dad6;
  }
  ED_Free(ent);
LAB_0009dad6:
  SV_CheckWaterTransition(ent);
  return;
}


// SV_Physics_Toss  @ 0009cb70
void SV_Physics_Toss(edict_t *ent)

{
  vec_t *veca;
  int *piVar1;
  float fVar2;
  float fVar3;
  qboolean qVar4;
  edict_t *peVar5;
  float fVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  vec_t *pvVar13;
  longdouble lVar14;
  float local_60;
  float local_5c;
  float local_58;
  trace_t local_54;
  
                    /* Unresolved local var: trace_t trace@[???]
                       Unresolved local var: vec3_t move@[???]
                       Unresolved local var: float backoff@[???] */
                    /* Unresolved local var: vec3_t point@[???]
                       Unresolved local var: int cont@[???]
                       Unresolved local var: int truecont@[???] */
  (ent->v).waterlevel = 0;
  (ent->v).watertype = -1;
  g_groupmask = (ent->v).groupinfo;
  local_54.allsolid = (qboolean)(((ent->v).absmin[0] + (ent->v).absmax[0]) * 0.5);
  local_54.startsolid = (qboolean)(((ent->v).absmin[1] + (ent->v).absmax[1]) * 0.5);
  local_54.inopen = (qboolean)((ent->v).absmin[2] + 1.0);
  iVar10 = SV_PointContents((vec_t *)&local_54);
  if (iVar10 + 0xeU < 0xc) {
    fVar2 = (ent->v).absmin[2];
    fVar3 = (ent->v).absmax[2];
    (ent->v).watertype = iVar10;
    (ent->v).waterlevel = 1;
    if (fVar2 == fVar3) {
LAB_0009cc1b:
      (ent->v).waterlevel = 3;
    }
    else {
      g_groupmask = (ent->v).groupinfo;
      local_54.inopen = (qboolean)((fVar2 + fVar3) * 0.5);
      iVar12 = SV_PointContents((vec_t *)&local_54);
      if (iVar12 + 0xeU < 0xc) {
        local_54.allsolid = (qboolean)((float)local_54.allsolid + (ent->v).view_ofs[0]);
        (ent->v).waterlevel = 2;
        g_groupmask = (ent->v).groupinfo;
        local_54.startsolid = (qboolean)((float)local_54.startsolid + (ent->v).view_ofs[1]);
        local_54.inopen = (qboolean)((float)local_54.inopen + (ent->v).view_ofs[2]);
        iVar12 = SV_PointContents((vec_t *)&local_54);
        if (iVar12 + 0xeU < 0xc) goto LAB_0009cc1b;
      }
    }
    if (iVar10 + 0xeU < 6) {
      pvVar13 = (ent->v).basevelocity;
      VectorMA(pvVar13,(float)(ent->v).waterlevel * 50.0,
               SV_CheckWater::lexical_block_0::current_table[-9 - iVar10],pvVar13);
    }
  }
                    /* Unresolved local var: float thinktime@[???] */
  uVar11 = (ent->v).flags;
  if ((uVar11 & 0x40000000) == 0) {
    lVar14 = (longdouble)(ent->v).nextthink;
    if ((lVar14 <= (longdouble)0) || ((longdouble)host_frametime + (longdouble)sv.time < lVar14))
    goto LAB_0009cd1e;
    if (lVar14 < (longdouble)sv.time) {
      lVar14 = (longdouble)(float)sv.time;
    }
    (ent->v).nextthink = 0.0;
    gGlobalVariables.time = (float)lVar14;
    (*gEntityInterface.pfnThink)(ent);
    if (((ent->v).flags & 0x40000000) != 0) goto LAB_0009cc6f;
    qVar4 = ent->free;
  }
  else {
LAB_0009cc6f:
    ED_Free(ent);
    qVar4 = ent->free;
  }
  if (qVar4 != false) {
    return;
  }
  uVar11 = (ent->v).flags;
LAB_0009cd1e:
  if (((0.0 < (ent->v).velocity[2]) || (peVar5 = (ent->v).groundentity, peVar5 == (edict_t *)0x0))
     || (((peVar5->v).flags & 0x28) != 0)) {
    uVar11 = uVar11 & 0xfffffdff;
    (ent->v).flags = uVar11;
  }
  if (((uVar11 & 0x200) != 0) &&
     (iVar10 = VectorCompare((ent->v).velocity,vec_origin), vVar8 = vec3_origin[2],
     vVar7 = vec3_origin[1], iVar10 != 0)) {
    (ent->v).avelocity[0] = vec3_origin[0];
    (ent->v).avelocity[1] = vVar7;
    (ent->v).avelocity[2] = vVar8;
    iVar10 = VectorCompare((ent->v).basevelocity,vec_origin);
    if (iVar10 != 0) {
      return;
    }
  }
  pvVar13 = (ent->v).velocity;
  SV_CheckVelocity(ent);
  uVar11 = (ent->v).movetype;
  if (((uVar11 & 0xfffffffd) != 9) && (uVar11 != 5)) {
                    /* Unresolved local var: float ent_gravity@[???] */
    fVar2 = (ent->v).gravity;
    fVar3 = 1.0;
    if (fVar2 != 0.0) {
      fVar3 = fVar2;
    }
    (ent->v).velocity[2] =
         (float)host_frametime * (ent->v).basevelocity[2] +
         ((ent->v).velocity[2] - fVar3 * sv_gravity.value * (float)host_frametime);
    (ent->v).basevelocity[2] = 0.0;
    SV_CheckVelocity(ent);
  }
  veca = (ent->v).angles;
  VectorMA(veca,(float)host_frametime,(ent->v).avelocity,veca);
  (ent->v).velocity[0] = (ent->v).velocity[0] + (ent->v).basevelocity[0];
  (ent->v).velocity[1] = (ent->v).velocity[1] + (ent->v).basevelocity[1];
  (ent->v).velocity[2] = (ent->v).velocity[2] + (ent->v).basevelocity[2];
  SV_CheckVelocity(ent);
  VectorScale(pvVar13,(float)host_frametime,&local_60);
  (ent->v).velocity[0] = (ent->v).velocity[0] - (ent->v).basevelocity[0];
  (ent->v).velocity[1] = (ent->v).velocity[1] - (ent->v).basevelocity[1];
  (ent->v).velocity[2] = (ent->v).velocity[2] - (ent->v).basevelocity[2];
  SV_PushEntity(&local_54,ent,&local_60);
  SV_CheckVelocity(ent);
  vVar7 = vec3_origin[0];
  if ((float)local_54.allsolid == 0.0) {
    if (local_54.fraction != 1.0) {
      if (ent->free != false) {
        return;
      }
      iVar10 = (ent->v).movetype;
      if (iVar10 == 10) {
        fVar2 = 2.0 - (ent->v).friction;
      }
      else {
        fVar2 = 2.0;
        if (iVar10 != 0xb) {
          fVar2 = 1.0;
        }
      }
                    /* Unresolved local var: float backoff@[???]
                       Unresolved local var: float change@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int blocked@[???] */
      fVar3 = (ent->v).velocity[1];
      fVar2 = ((ent->v).velocity[2] * local_54.plane.normal[2] +
              local_54.plane.normal[0] * (ent->v).velocity[0] + local_54.plane.normal[1] * fVar3) *
              fVar2;
      fVar6 = (ent->v).velocity[0] - local_54.plane.normal[0] * fVar2;
      (ent->v).velocity[0] = fVar6;
      if ((-0.1 < fVar6) && (fVar6 < 0.1)) {
        (ent->v).velocity[0] = 0.0;
      }
      fVar3 = fVar3 - local_54.plane.normal[1] * fVar2;
      (ent->v).velocity[1] = fVar3;
      if ((-0.1 < fVar3) && (fVar3 < 0.1)) {
        (ent->v).velocity[1] = 0.0;
      }
      fVar2 = (ent->v).velocity[2] - fVar2 * local_54.plane.normal[2];
      (ent->v).velocity[2] = fVar2;
      if ((-0.1 < fVar2) && (fVar2 < 0.1)) {
        (ent->v).velocity[2] = 0.0;
      }
      if (0.7 < local_54.plane.normal[2]) {
                    /* Unresolved local var: float vel@[???] */
        local_60 = (ent->v).velocity[0] + (ent->v).basevelocity[0];
        local_5c = (ent->v).velocity[1] + (ent->v).basevelocity[1];
        local_58 = (ent->v).velocity[2] + (ent->v).basevelocity[2];
        fVar2 = (float)host_frametime;
        if (local_58 < fVar2 * sv_gravity.value) {
          piVar1 = &(ent->v).flags;
          *piVar1 = *piVar1 | 0x200;
          (ent->v).velocity[2] = 0.0;
          (ent->v).groundentity = local_54.ent;
        }
        vVar7 = vec3_origin[0];
        if ((local_58 * local_58 + local_5c * local_5c + local_60 * local_60 < 900.0) ||
           (1 < iVar10 - 10U)) {
          (ent->v).velocity[0] = vec3_origin[0];
          vVar8 = vec3_origin[1];
          piVar1 = &(ent->v).flags;
          *piVar1 = *piVar1 | 0x200;
          (ent->v).velocity[1] = vVar8;
          vVar9 = vec3_origin[2];
          (ent->v).groundentity = local_54.ent;
          (ent->v).velocity[2] = vVar9;
          (ent->v).avelocity[0] = vVar7;
          (ent->v).avelocity[1] = vVar8;
          (ent->v).avelocity[2] = vVar9;
        }
        else {
          VectorScale(pvVar13,fVar2 * (1.0 - local_54.fraction) * 0.9,&local_60);
          VectorMA(&local_60,(1.0 - local_54.fraction) * (float)host_frametime * 0.9,
                   (ent->v).basevelocity,&local_60);
          SV_PushEntity(&local_54,ent,&local_60);
        }
      }
    }
    SV_CheckWaterTransition(ent);
    return;
  }
  (ent->v).velocity[0] = vec3_origin[0];
  vVar8 = vec3_origin[1];
  (ent->v).velocity[1] = vec3_origin[1];
  vVar9 = vec3_origin[2];
  (ent->v).velocity[2] = vec3_origin[2];
  (ent->v).avelocity[0] = vVar7;
  (ent->v).avelocity[1] = vVar8;
  (ent->v).avelocity[2] = vVar9;
  return;
}


// SV_PlayerRunPreThink  @ 000a19f0
void SV_PlayerRunPreThink(edict_t *player,float time)

{
  gGlobalVariables.time = time;
                    /* WARNING: Could not recover jumptable at 0x000a19fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEntityInterface.pfnPlayerPreThink)(player);
  return;
}


// SV_PlayerRunThink  @ 000a1a10
qboolean SV_PlayerRunThink(edict_t *ent,float frametime,double clienttimebase)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  uint uVar4;
  
                    /* Unresolved local var: float thinktime@[???] */
  fVar3 = (float)clienttimebase;
  uVar2 = (ent->v).flags;
  uVar4 = uVar2 & 0x40000000;
  if ((-1 < (int)uVar2) && (uVar4 == 0)) {
    fVar1 = (ent->v).nextthink;
    if (fVar1 <= 0.0) {
      return true;
    }
    if (fVar3 + frametime < fVar1) {
      return true;
    }
    if (fVar1 < fVar3) {
      fVar1 = fVar3;
    }
    (ent->v).nextthink = 0.0;
    gGlobalVariables.time = fVar1;
    (*gEntityInterface.pfnThink)(ent);
    uVar4 = (ent->v).flags & 0x40000000;
  }
  if (uVar4 != 0) {
    ED_Free(ent);
  }
  return (uint)(ent->free == false);
}


// SV_PointContents  @ 000aa1e0
int SV_PointContents(vec_t *p)

{
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  model_s *pmVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int cont@[???]
                       Unresolved local var: int entityContents@[???] */
  pmVar3 = sv.worldmodel;
  iVar5 = 0;
  do {
    while( true ) {
      if ((iVar5 < pmVar3->hulls[0].firstclipnode) || (pmVar3->hulls[0].lastclipnode < iVar5)) {
        Sys_Error("SV_HullPointContents: bad node number");
      }
      pdVar1 = pmVar3->hulls[0].clipnodes + iVar5;
      pmVar2 = pmVar3->hulls[0].planes + pdVar1->planenum;
      if (2 < pmVar2->type) break;
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
      if (0.0 <= p[pmVar2->type] - pmVar2->dist) goto LAB_000aa206;
LAB_000aa269:
      iVar5 = (int)pdVar1->children[1];
      if (iVar5 < 0) goto LAB_000aa271;
    }
    if ((pmVar2->normal[2] * p[2] + pmVar2->normal[1] * p[1] + pmVar2->normal[0] * *p) -
        pmVar2->dist < 0.0) goto LAB_000aa269;
LAB_000aa206:
    iVar5 = (int)pdVar1->children[0];
  } while (-1 < iVar5);
LAB_000aa271:
  if (iVar5 + 0xeU < 6) {
    iVar5 = -3;
  }
  else if (iVar5 == -2) {
    return -2;
  }
  iVar4 = SV_LinkContents(sv_areanodes,p);
  if (iVar4 == -1) {
    iVar4 = iVar5;
  }
  return iVar4;
}


// SV_PointLeafnum  @ 0008a890
int SV_PointLeafnum(vec_t *p)

{
  mleaf_t *pmVar1;
  
                    /* Unresolved local var: mleaf_t * pLeaf@[???] */
  pmVar1 = Mod_PointInLeaf(p,sv.worldmodel);
  if (pmVar1 != (mleaf_t *)0x0) {
    return ((int)pmVar1 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555;
  }
  return 0;
}


// SV_PreRunCmd  @ 000a09e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_PreRunCmd(void)

{
  return;
}


// SV_ProcessFile  @ 000890b0
void SV_ProcessFile(client_t *cl,char *filename)

{
  resource_s *prVar1;
  customization_s *pcVar2;
  resource_s *pResource;
  int iVar3;
  qboolean qVar4;
  int in_GS_OFFSET;
  uchar local_30 [16];
  int local_20;
  
                    /* Unresolved local var: customization_t * pList@[???]
                       Unresolved local var: resource_t * resource@[???]
                       Unresolved local var: resource_t * next@[???]
                       Unresolved local var: uchar[16] md5@[???]
                       Unresolved local var: qboolean bFound@[???]
                       Unresolved local var: qboolean bNoError@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*filename == '!') {
    COM_HexConvert(filename + 4,0x20,local_30);
    prVar1 = (cl->resourcesneeded).pNext;
    do {
      pResource = prVar1;
      if (pResource == &cl->resourcesneeded) {
        Con_Printf("SV_ProcessFile:  Unrequested decal\n");
        goto LAB_000890ed;
      }
      prVar1 = pResource->pNext;
      iVar3 = Q_memcmp(pResource->rgucMD5_hash,local_30,0x10);
    } while (iVar3 != 0);
    iVar3 = (cl->netchan).tempbuffersize;
    if (pResource->nDownloadSize == iVar3) {
      HPAK_AddLump(true,"custom.hpk",pResource,(cl->netchan).tempbuffer,(FileHandle_t)0x0);
      pResource->ucFlags = pResource->ucFlags & 0xfd;
      SV_MoveToOnHandList(pResource);
      for (pcVar2 = (cl->customdata).pNext; pcVar2 != (customization_s *)0x0; pcVar2 = pcVar2->pNext
          ) {
        iVar3 = Q_memcmp((pcVar2->resource).rgucMD5_hash,pResource->rgucMD5_hash,0x10);
        if (iVar3 == 0) {
          Con_DPrintf("Duplicate resource received and ignored.\n");
          goto LAB_000890ed;
        }
      }
      qVar4 = COM_CreateCustomization
                        (&cl->customdata,pResource,-1,7,(customization_t **)0x0,(int *)0x0);
      if (qVar4 == false) {
        Con_Printf("Error parsing custom decal from %s\n",cl->name);
      }
    }
    else {
      Con_Printf("SV_ProcessFile:  Downloaded %i bytes for purported %i byte file\n",iVar3,
                 pResource->nDownloadSize);
    }
  }
  else {
    Con_Printf("Ignoring non-customization file upload of %s\n",filename);
  }
LAB_000890ed:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_PropagateCustomizations  @ 0008dee0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_PropagateCustomizations(void)

{
  sizebuf_t *sb;
  client_t *pcVar1;
  int iVar2;
  customization_s *pcVar3;
  int c;
  
                    /* Unresolved local var: client_t * pHost@[???]
                       Unresolved local var: customization_t * pCust@[???]
                       Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: int i@[???] */
  pcVar1 = host_client;
  c = 0;
  sb = &(host_client->netchan).message;
  host_client = svs.clients;
  iVar2 = svs.maxclients;
  if (0 < svs.maxclients) {
    do {
      if (((host_client->active != false) || (host_client->spawned != false)) &&
         (host_client->fakeclient == false)) {
        pcVar3 = (host_client->customdata).pNext;
joined_r0x0008df37:
        if (pcVar3 != (customization_s *)0x0) {
          do {
            if (pcVar3->bInUse != false) {
              MSG_WriteByte(sb,0x2e);
              MSG_WriteByte(sb,c);
              MSG_WriteByte(sb,(pcVar3->resource).type);
              MSG_WriteString(sb,(pcVar3->resource).szFileName);
              MSG_WriteShort(sb,(pcVar3->resource).nIndex);
              MSG_WriteLong(sb,(pcVar3->resource).nDownloadSize);
              MSG_WriteByte(sb,(uint)(pcVar3->resource).ucFlags);
              if (((pcVar3->resource).ucFlags & 4) != 0) goto code_r0x0008dfc7;
            }
            pcVar3 = pcVar3->pNext;
            iVar2 = svs.maxclients;
            if (pcVar3 == (customization_s *)0x0) break;
          } while( true );
        }
      }
      c = c + 1;
      host_client = host_client + 1;
    } while (c < iVar2);
  }
  host_client = pcVar1;
  return;
code_r0x0008dfc7:
  SZ_Write(sb,(pcVar3->resource).rgucMD5_hash,0x10);
  pcVar3 = pcVar3->pNext;
  iVar2 = svs.maxclients;
  goto joined_r0x0008df37;
}


// SV_PushEntity  @ 0009ada0
trace_t * SV_PushEntity(trace_t *__return_storage_ptr__,edict_t *ent,vec_t *push)

{
  uint uVar1;
  uint uVar2;
  trace_t local_9c;
  float local_50;
  float local_4c;
  float local_48;
  trace_t tStack_44;
  
                    /* Unresolved local var: trace_t trace@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: qboolean monsterClip@[???]
                       Unresolved local var: int moveType@[???] */
  local_50 = (ent->v).origin[0] + *push;
  local_4c = (ent->v).origin[1] + push[1];
  local_48 = (ent->v).origin[2] + push[2];
  if ((ent->v).movetype == 9) {
    uVar2 = 2;
  }
  else {
    uVar2 = (uint)((uint)(ent->v).solid < 2);
  }
  SV_Move(&local_9c,(ent->v).origin,(ent->v).mins,(ent->v).maxs,&local_50,uVar2,ent,
          (uint)(ent->v).flags >> 0x17 & true);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)tStack_44.endpos + (uVar2 - 0x14)) =
         *(undefined4 *)((int)local_9c.endpos + (uVar2 - 0x14));
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x38);
  if (tStack_44.fraction != 0.0) {
    (ent->v).origin[0] = tStack_44.endpos[0];
    (ent->v).origin[1] = tStack_44.endpos[1];
    (ent->v).origin[2] = tStack_44.endpos[2];
  }
  SV_LinkEdict(ent,true);
  if ((tStack_44.ent == (edict_t *)0x0) ||
     (gGlobalVariables.time = (float)sv.time,
     (((ent->v).flags | ((tStack_44.ent)->v).flags) & 0x40000000U) != 0)) goto LAB_0009af08;
  uVar2 = (ent->v).groupinfo;
  if ((uVar2 != 0) && (uVar1 = ((tStack_44.ent)->v).groupinfo, uVar1 != 0)) {
    if (g_groupop == 0) {
      if ((uVar2 & uVar1) == 0) goto LAB_0009af08;
    }
    else if ((g_groupop == 1) && ((uVar2 & uVar1) != 0)) goto LAB_0009af08;
  }
  if ((ent->v).solid != 0) {
    SV_SetGlobalTrace(&tStack_44);
    (*gEntityInterface.pfnTouch)(ent,tStack_44.ent);
  }
  if (((tStack_44.ent)->v).solid != 0) {
    SV_SetGlobalTrace(&tStack_44);
    (*gEntityInterface.pfnTouch)(tStack_44.ent,ent);
  }
LAB_0009af08:
  uVar2 = 0;
  do {
    *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar2 - 0x14)) =
         *(undefined4 *)((int)tStack_44.endpos + (uVar2 - 0x14));
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x38);
  return __return_storage_ptr__;
}


// SV_PushMove  @ 0009afe0
void SV_PushMove(edict_t *pusher,float movetime)

{
  vec_t vVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  vec_t vVar5;
  vec_t vVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  vec3_t *pavVar13;
  edict_t *peVar14;
  undefined4 *puVar15;
  uint uVar16;
  int iVar17;
  int *piVar18;
  edict_t *ent;
  int iVar19;
  int iVar20;
  int iVar21;
  int local_7c;
  trace_t local_6c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int e@[???]
                       Unresolved local var: edict_t * check@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???]
                       Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t entorig@[???]
                       Unresolved local var: vec3_t pushorig@[???]
                       Unresolved local var: int num_moved@[???] */
  local_28 = (pusher->v).velocity[0];
  if (((local_28 == 0.0) && ((pusher->v).velocity[1] == 0.0)) && ((pusher->v).velocity[2] == 0.0)) {
    (pusher->v).ltime = (pusher->v).ltime + movetime;
  }
  else {
    fVar2 = (pusher->v).origin[0];
    fVar3 = (pusher->v).origin[1];
    fVar4 = (pusher->v).origin[2];
    local_28 = local_28 * movetime;
    fVar7 = (pusher->v).absmin[0] + local_28;
    fVar8 = (pusher->v).absmax[0] + local_28;
    (pusher->v).origin[0] = local_28 + fVar2;
    local_24 = movetime * (pusher->v).velocity[1];
    fVar10 = (pusher->v).absmin[1] + local_24;
    fVar9 = (pusher->v).absmax[1] + local_24;
    (pusher->v).origin[1] = local_24 + fVar3;
    local_20 = movetime * (pusher->v).velocity[2];
    fVar12 = (pusher->v).absmin[2] + local_20;
    fVar11 = (pusher->v).absmax[2] + local_20;
    (pusher->v).origin[2] = local_20 + fVar4;
    (pusher->v).ltime = (pusher->v).ltime + movetime;
    SV_LinkEdict(pusher,false);
    if (((pusher->v).solid != 0) && (1 < sv.num_edicts)) {
      local_7c = 0;
      iVar21 = 1;
      iVar20 = 0x324;
      iVar19 = sv.num_edicts;
      do {
        while (ent = (edict_t *)((int)(sv.edicts)->leafnums + iVar20 + -0x18), ent->free != false) {
LAB_0009b460:
          iVar21 = iVar21 + 1;
          iVar20 = iVar20 + 0x324;
          if (iVar19 <= iVar21) {
            return;
          }
        }
        uVar16 = (ent->v).movetype;
        if ((0xc < uVar16) || (((byte)(0x1181 >> ((byte)uVar16 & 0x1f)) & 1) != 1)) {
          if ((((ent->v).flags & 0x200) == 0) || (pusher != (ent->v).groundentity)) {
            if (((fVar8 <= (ent->v).absmin[0]) ||
                ((((fVar9 <= (ent->v).absmin[1] || (fVar11 <= (ent->v).absmin[2])) ||
                  ((ent->v).absmax[0] <= fVar7)) ||
                 (((ent->v).absmax[1] <= fVar10 || ((ent->v).absmax[2] <= fVar12)))))) ||
               (peVar14 = SV_TestEntityPosition(ent), iVar19 = sv.num_edicts,
               peVar14 == (edict_t *)0x0)) goto LAB_0009b460;
            uVar16 = (ent->v).movetype;
          }
          if (uVar16 != 3) {
            piVar18 = &(ent->v).flags;
            *piVar18 = *piVar18 & 0xfffffdff;
          }
          vVar1 = (ent->v).origin[0];
          vVar5 = (ent->v).origin[1];
          vVar6 = (ent->v).origin[2];
          g_moved_from[local_7c][0] = vVar1;
          pavVar13 = g_moved_from;
          g_moved_from[local_7c][1] = (ent->v).origin[1];
          iVar17 = local_7c + 1;
          pavVar13[local_7c][2] = (ent->v).origin[2];
          g_moved_edict[local_7c] = ent;
          (pusher->v).solid = 0;
          SV_PushEntity(&local_6c,ent,&local_28);
          (pusher->v).solid = 4;
          peVar14 = SV_TestEntityPosition(ent);
          iVar19 = sv.num_edicts;
          local_7c = iVar17;
          if ((peVar14 != (edict_t *)0x0) && ((ent->v).mins[0] != (ent->v).maxs[0])) {
            if (1 < (uint)(ent->v).solid) {
              (ent->v).origin[0] = vVar1;
              (ent->v).origin[1] = vVar5;
              (ent->v).origin[2] = vVar6;
              SV_LinkEdict(ent,true);
              (pusher->v).origin[0] = fVar2;
              (pusher->v).origin[1] = fVar3;
              (pusher->v).origin[2] = fVar4;
              SV_LinkEdict(pusher,false);
              (pusher->v).ltime = (pusher->v).ltime - movetime;
              iVar19 = 0;
              (*gEntityInterface.pfnBlocked)(pusher,ent);
              iVar20 = 0;
              do {
                iVar21 = iVar19 * 3;
                iVar20 = iVar20 + 1;
                piVar18 = (int *)((int)g_moved_edict + iVar19);
                iVar19 = iVar19 + 4;
                puVar15 = (undefined4 *)((int)*g_moved_from + iVar21);
                *(undefined4 *)(*piVar18 + 0x88) = *puVar15;
                *(undefined4 *)(*piVar18 + 0x8c) = puVar15[1];
                *(undefined4 *)(*piVar18 + 0x90) = puVar15[2];
                SV_LinkEdict((edict_t *)*piVar18,false);
              } while (iVar17 != iVar20);
              return;
            }
            vVar1 = (ent->v).mins[2];
            (ent->v).mins[1] = 0.0;
            (ent->v).mins[0] = 0.0;
            (ent->v).maxs[2] = vVar1;
            (ent->v).maxs[0] = 0.0;
            (ent->v).maxs[1] = 0.0;
            iVar19 = sv.num_edicts;
          }
          goto LAB_0009b460;
        }
        iVar21 = iVar21 + 1;
        iVar20 = iVar20 + 0x324;
        if (iVar19 <= iVar21) {
          return;
        }
      } while( true );
    }
  }
  return;
}


// SV_PushRotate  @ 0009b4b0
int SV_PushRotate(edict_t *pusher,float movetime)

{
  vec_t *angles;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  vec_t vVar6;
  vec_t vVar7;
  vec_t vVar8;
  float fVar9;
  float fVar10;
  vec3_t *pavVar11;
  edict_t *peVar12;
  edict_t *peVar13;
  undefined4 *puVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int local_dc;
  float local_d8;
  trace_t local_bc;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int e@[???]
                       Unresolved local var: edict_t * check@[???]
                       Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t amove@[???]
                       Unresolved local var: vec3_t entorig@[???]
                       Unresolved local var: vec3_t pushorig@[???]
                       Unresolved local var: int num_moved@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: vec3_t start@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t forwardNow@[???]
                       Unresolved local var: vec3_t rightNow@[???]
                       Unresolved local var: vec3_t upNow@[???] */
  if ((((pusher->v).avelocity[0] == 0.0) && ((pusher->v).avelocity[1] == 0.0)) &&
     ((pusher->v).avelocity[2] == 0.0)) {
    (pusher->v).ltime = (pusher->v).ltime + movetime;
  }
  else {
    fVar1 = (pusher->v).avelocity[0];
    angles = (pusher->v).angles;
    fVar9 = movetime * (pusher->v).avelocity[1];
    fVar2 = (pusher->v).avelocity[2];
    AngleVectors(angles,&local_40,&local_34,&local_28);
    fVar3 = (pusher->v).angles[0];
    fVar4 = (pusher->v).angles[1];
    fVar5 = (pusher->v).angles[2];
    (pusher->v).angles[0] = movetime * fVar1 + fVar3;
    (pusher->v).angles[1] = fVar9 + fVar4;
    (pusher->v).angles[2] = movetime * fVar2 + fVar5;
    AngleVectorsTranspose(angles,&local_64,&local_58,&local_4c);
    (pusher->v).ltime = (pusher->v).ltime + movetime;
    SV_LinkEdict(pusher,false);
    if (((pusher->v).solid != 0) && (1 < sv.num_edicts)) {
      local_dc = 0;
      iVar20 = 1;
      iVar19 = 0x324;
      iVar18 = sv.num_edicts;
      do {
        while (peVar13 = (edict_t *)((int)(sv.edicts)->leafnums + iVar19 + -0x18),
              peVar13->free == false) {
          uVar15 = (peVar13->v).movetype;
          if ((0xc < uVar15) || (((byte)(0x1181 >> ((byte)uVar15 & 0x1f)) & 1) != 1)) {
            if ((((peVar13->v).flags & 0x200) == 0) || (pusher != (peVar13->v).groundentity)) {
              if ((((pusher->v).absmax[0] <= (peVar13->v).absmin[0]) ||
                  (((((pusher->v).absmax[1] <= (peVar13->v).absmin[1] ||
                     ((pusher->v).absmax[2] <= (peVar13->v).absmin[2])) ||
                    ((peVar13->v).absmax[0] <= (pusher->v).absmin[0])) ||
                   (((peVar13->v).absmax[1] <= (pusher->v).absmin[1] ||
                    ((peVar13->v).absmax[2] <= (pusher->v).absmin[2])))))) ||
                 (peVar12 = SV_TestEntityPosition(peVar13), iVar18 = sv.num_edicts,
                 peVar12 == (edict_t *)0x0)) break;
              uVar15 = (peVar13->v).movetype;
            }
            if (uVar15 != 3) {
              piVar17 = &(peVar13->v).flags;
              *piVar17 = *piVar17 & 0xfffffdff;
            }
            vVar6 = (peVar13->v).origin[0];
            vVar7 = (peVar13->v).origin[1];
            vVar8 = (peVar13->v).origin[2];
            g_moved_from[local_dc][0] = vVar6;
            pavVar11 = g_moved_from;
            g_moved_from[local_dc][1] = (peVar13->v).origin[1];
            iVar16 = local_dc + 1;
            pavVar11[local_dc][2] = (peVar13->v).origin[2];
            g_moved_edict[local_dc] = peVar13;
            if (sv.max_edicts <= iVar16) {
              Sys_Error("Out of edicts in simulator!\n");
            }
            if ((peVar13->v).movetype == 0xd) {
              local_70 = ((peVar13->v).absmin[0] + (peVar13->v).absmax[0]) * 0.5 -
                         (pusher->v).origin[0];
              local_6c = ((peVar13->v).absmin[1] + (peVar13->v).absmax[1]) * 0.5 -
                         (pusher->v).origin[1];
              local_d8 = ((peVar13->v).absmin[2] + (peVar13->v).absmax[2]) * 0.5 -
                         (pusher->v).origin[2];
            }
            else {
              local_70 = (peVar13->v).origin[0] - (pusher->v).origin[0];
              local_6c = (peVar13->v).origin[1] - (pusher->v).origin[1];
              local_d8 = (peVar13->v).origin[2] - (pusher->v).origin[2];
            }
            (pusher->v).solid = 0;
            fVar10 = local_38 * local_d8 + local_3c * local_6c + local_40 * local_70;
            fVar2 = -(local_2c * local_d8 + local_30 * local_6c + local_34 * local_70);
            fVar1 = local_24 * local_6c + local_28 * local_70 + local_20 * local_d8;
            local_70 = (fVar1 * local_5c + fVar2 * local_60 + fVar10 * local_64) - local_70;
            local_6c = (local_50 * fVar1 + local_54 * fVar2 + local_58 * fVar10) - local_6c;
            local_68 = (local_44 * fVar1 + local_48 * fVar2 + local_4c * fVar10) - local_d8;
            SV_PushEntity(&local_bc,peVar13,&local_70);
            (pusher->v).solid = 4;
            if ((peVar13->v).movetype != 0xd) {
              if (((peVar13->v).flags & 8) == 0) {
                (peVar13->v).angles[0] = (peVar13->v).angles[0] + 0.0;
                (peVar13->v).angles[1] = fVar9 + (peVar13->v).angles[1];
                (peVar13->v).angles[2] = (peVar13->v).angles[2] + 0.0;
              }
              else {
                fVar1 = (peVar13->v).avelocity[1];
                (peVar13->v).fixangle = 2;
                (peVar13->v).avelocity[1] = fVar9 + fVar1;
              }
            }
            peVar12 = SV_TestEntityPosition(peVar13);
            iVar18 = sv.num_edicts;
            local_dc = iVar16;
            if ((peVar12 != (edict_t *)0x0) && ((peVar13->v).mins[0] != (peVar13->v).maxs[0])) {
              if (1 < (uint)(peVar13->v).solid) {
                iVar19 = 0;
                (peVar13->v).origin[0] = vVar6;
                (peVar13->v).origin[1] = vVar7;
                (peVar13->v).origin[2] = vVar8;
                SV_LinkEdict(peVar13,true);
                (pusher->v).angles[0] = fVar3;
                (pusher->v).angles[1] = fVar4;
                (pusher->v).angles[2] = fVar5;
                SV_LinkEdict(pusher,false);
                (pusher->v).ltime = (pusher->v).ltime - movetime;
                iVar18 = 0;
                (*gEntityInterface.pfnBlocked)(pusher,peVar13);
                do {
                  piVar17 = (int *)((int)g_moved_edict + iVar18);
                  puVar14 = (undefined4 *)((int)*g_moved_from + iVar18 * 3);
                  *(undefined4 *)(*piVar17 + 0x88) = *puVar14;
                  *(undefined4 *)(*piVar17 + 0x8c) = puVar14[1];
                  *(undefined4 *)(*piVar17 + 0x90) = puVar14[2];
                  peVar13 = (edict_t *)*piVar17;
                  if (((peVar13->v).flags & 8) == 0) {
                    if ((peVar13->v).movetype != 0xd) {
                      (peVar13->v).angles[1] = (peVar13->v).angles[1] - fVar9;
                      peVar13 = (edict_t *)*piVar17;
                    }
                  }
                  else {
                    (peVar13->v).avelocity[1] = 0.0;
                    peVar13 = (edict_t *)*piVar17;
                  }
                  iVar19 = iVar19 + 1;
                  iVar18 = iVar18 + 4;
                  SV_LinkEdict(peVar13,false);
                } while (iVar16 != iVar19);
                return 0;
              }
              vVar6 = (peVar13->v).mins[2];
              (peVar13->v).mins[1] = 0.0;
              (peVar13->v).mins[0] = 0.0;
              (peVar13->v).maxs[2] = vVar6;
              (peVar13->v).maxs[0] = 0.0;
              (peVar13->v).maxs[1] = 0.0;
              iVar18 = sv.num_edicts;
            }
            break;
          }
          iVar20 = iVar20 + 1;
          iVar19 = iVar19 + 0x324;
          if (iVar18 <= iVar20) {
            return 1;
          }
        }
        iVar20 = iVar20 + 1;
        iVar19 = iVar19 + 0x324;
      } while (iVar20 < iVar18);
    }
  }
  return 1;
}


// SV_QueryMovevarsChanged  @ 00083540
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_QueryMovevarsChanged(void)

{
  int iVar1;
  sizebuf_t *message;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if ((((((((sv_maxspeed.value != movevars.maxspeed) || (sv_gravity.value != movevars.gravity)) ||
          (sv_stopspeed.value != movevars.stopspeed)) ||
         (((sv_spectatormaxspeed.value != movevars.spectatormaxspeed ||
           (sv_accelerate.value != movevars.accelerate)) ||
          ((sv_airaccelerate.value != movevars.airaccelerate ||
           ((sv_wateraccelerate.value != movevars.wateraccelerate ||
            (sv_friction.value != movevars.friction)))))))) ||
        (sv_edgefriction.value != movevars.edgefriction)) ||
       (((sv_waterfriction.value != movevars.waterfriction || (movevars.entgravity != 1.0)) ||
        (sv_bounce.value != movevars.bounce)))) ||
      (((sv_stepsize.value != movevars.stepsize || (sv_maxvelocity.value != movevars.maxvelocity))
       || ((sv_zmax.value != movevars.zmax ||
           ((sv_wateramp.value != movevars.waveHeight ||
            (sv_footsteps.value != (float)movevars.footsteps)))))))) ||
     ((sv_rollangle.value != movevars.rollangle ||
      (((((sv_rollspeed.value != movevars.rollspeed || (sv_skycolor_r.value != movevars.skycolor_r))
         || (sv_skycolor_g.value != movevars.skycolor_g)) ||
        ((sv_skycolor_b.value != movevars.skycolor_b || (sv_skyvec_x.value != movevars.skyvec_x))))
       || ((sv_skyvec_y.value != movevars.skyvec_y ||
           ((sv_skyvec_z.value != movevars.skyvec_z ||
            (iVar1 = Q_strcmp(sv_skyname.string,movevars.skyName), iVar1 != 0)))))))))) {
    SV_SetMoveVars();
    message = &((svs.clients)->netchan).message;
    if (0 < svs.maxclients) {
      iVar2 = 0;
      iVar1 = svs.maxclients;
      do {
        if ((message[0x291].cursize == 0) &&
           (((*(int *)&message[-6].flags != 0 || (message[-6].data != (byte *)0x0)) ||
            (message[-6].cursize != 0)))) {
          SV_WriteMovevarsToClient(message);
          iVar1 = svs.maxclients;
        }
        iVar2 = iVar2 + 1;
        message = (sizebuf_t *)&message[0x51e].cursize;
      } while (iVar2 < iVar1);
    }
  }
  return;
}


// SV_Rcon  @ 00088d40
void SV_Rcon(netadr_t *net_from)

{
  netadrtype_t nVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  netadr_t a;
  netadr_t a_00;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  int in_GS_OFFSET;
  char local_620 [512];
  char local_420 [1023];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int invalid@[???]
                       Unresolved local var: char[1024] remaining@[???]
                       Unresolved local var: char[512] rcon_buff@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: char * data@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar7 = SV_Rcon_Validate();
  iVar10 = net_message.cursize;
  iVar8 = Q_strlen("rcon");
  pbVar6 = net_message.data;
  iVar10 = iVar10 - iVar8;
  if (iVar10 - 1U < 0x1fe) {
    iVar8 = Q_strlen("rcon");
    Q_memcpy(local_620,pbVar6 + iVar8,iVar10);
    nVar1 = net_from->type;
    local_620[iVar10] = '\0';
    uVar2 = *(undefined4 *)net_from->ip;
    uVar3 = *(undefined4 *)net_from->ipx;
    uVar4 = *(undefined4 *)(net_from->ipx + 4);
    uVar5 = *(undefined4 *)(net_from->ipx + 8);
    if (iVar7 == 0) {
      a.ip[0] = (char)uVar2;
      a.ip[1] = (char)((uint)uVar2 >> 8);
      a.ip[2] = (char)((uint)uVar2 >> 0x10);
      a.ip[3] = (char)((uint)uVar2 >> 0x18);
      a.type = nVar1;
      a.ipx[0] = (char)uVar3;
      a.ipx[1] = (char)((uint)uVar3 >> 8);
      a.ipx[2] = (char)((uint)uVar3 >> 0x10);
      a.ipx[3] = (char)((uint)uVar3 >> 0x18);
      a.ipx[4] = (char)uVar4;
      a.ipx[5] = (char)((uint)uVar4 >> 8);
      a.ipx[6] = (char)((uint)uVar4 >> 0x10);
      a.ipx[7] = (char)((uint)uVar4 >> 0x18);
      a.ipx[8] = (char)uVar5;
      a.ipx[9] = (char)((uint)uVar5 >> 8);
      a.port = (short)((uint)uVar5 >> 0x10);
      pcVar9 = NET_AdrToString(a);
      Con_Printf("Rcon from %s:\n%s\n",pcVar9,local_620);
      pcVar9 = NET_AdrToString(*net_from);
      Log_Printf("Rcon: \"%s\" from \"%s\"\n",local_620,pcVar9);
      sv_redirected = RD_PACKET;
      sv_redirectto.type = net_from->type;
      sv_redirectto.ip = *&net_from->ip;
      sv_redirectto.ipx._0_4_ = *(undefined4 *)net_from->ipx;
      sv_redirectto.ipx._4_4_ = *(undefined4 *)(net_from->ipx + 4);
      sv_redirectto._16_4_ = *(undefined4 *)(net_from->ipx + 8);
                    /* Unresolved local var: char * data@[???] */
      outputbuf[0] = '\0';
      pcVar9 = COM_Parse(local_620);
      pcVar9 = COM_Parse(pcVar9);
      pcVar9 = COM_Parse(pcVar9);
      if (pcVar9 == (char *)0x0) {
        Con_Printf("Empty rcon\n");
        goto LAB_00088d9d;
      }
      Q_strncpy(local_420,pcVar9,0x3ff);
      local_21 = 0;
      Cmd_ExecuteString(local_420,src_command);
    }
    else {
      a_00.ip[0] = (char)uVar2;
      a_00.ip[1] = (char)((uint)uVar2 >> 8);
      a_00.ip[2] = (char)((uint)uVar2 >> 0x10);
      a_00.ip[3] = (char)((uint)uVar2 >> 0x18);
      a_00.type = nVar1;
      a_00.ipx[0] = (char)uVar3;
      a_00.ipx[1] = (char)((uint)uVar3 >> 8);
      a_00.ipx[2] = (char)((uint)uVar3 >> 0x10);
      a_00.ipx[3] = (char)((uint)uVar3 >> 0x18);
      a_00.ipx[4] = (char)uVar4;
      a_00.ipx[5] = (char)((uint)uVar4 >> 8);
      a_00.ipx[6] = (char)((uint)uVar4 >> 0x10);
      a_00.ipx[7] = (char)((uint)uVar4 >> 0x18);
      a_00.ipx[8] = (char)uVar5;
      a_00.ipx[9] = (char)((uint)uVar5 >> 8);
      a_00.port = (short)((uint)uVar5 >> 0x10);
      pcVar9 = NET_AdrToString(a_00);
      Con_Printf("Bad Rcon from %s:\n%s\n",pcVar9,local_620);
      pcVar9 = NET_AdrToString(*net_from);
      Log_Printf("Bad Rcon: \"%s\" from \"%s\"\n",local_620,pcVar9);
      sv_redirected = RD_PACKET;
      sv_redirectto.type = net_from->type;
      sv_redirectto.ip = *&net_from->ip;
      sv_redirectto.ipx._0_4_ = *(undefined4 *)net_from->ipx;
      sv_redirectto.ipx._4_4_ = *(undefined4 *)(net_from->ipx + 4);
      sv_redirectto._16_4_ = *(undefined4 *)(net_from->ipx + 8);
      outputbuf[0] = '\0';
      if ((iVar7 == 2) || (*rcon_password.string != '\0')) {
        Con_Printf("Bad rcon_password.\n");
      }
      else {
        Con_Printf("Bad rcon_password.\nNo password set for this server.\n");
      }
    }
    SV_FlushRedirect();
    sv_redirected = RD_NONE;
  }
LAB_00088d9d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_Rcon_Validate  @ 00088a70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SV_Rcon_Validate(void)

{
  netadr_t a;
  netadr_t a_00;
  netadr_t a_01;
  netadr_t adr;
  netadr_t a_02;
  int iVar1;
  qboolean qVar2;
  char *pcVar3;
  char *s1;
  rcon_failure_t *prVar4;
  int iVar5;
  
  iVar1 = Cmd_Argc();
  if ((2 < iVar1) && (iVar1 = Q_strlen(rcon_password.string), iVar1 != 0)) {
    if (sv_rcon_banpenalty.value < 0.0) {
      Cvar_SetValue("sv_rcon_banpenalty",0.0);
    }
    prVar4 = g_rgRconFailures;
    do {
      if (((prVar4->active != false) &&
          (a.ip[0] = net_from.ip[0], a.ip[1] = net_from.ip[1], a.ip[2] = net_from.ip[2],
          a.ip[3] = net_from.ip[3], a.type = net_from.type, a.ipx[0] = net_from.ipx[0],
          a.ipx[1] = net_from.ipx[1], a.ipx[2] = net_from.ipx[2], a.ipx[3] = net_from.ipx[3],
          a.ipx[4] = net_from.ipx[4], a.ipx[5] = net_from.ipx[5], a.ipx[6] = net_from.ipx[6],
          a.ipx[7] = net_from.ipx[7], a.ipx[8] = net_from.ipx[8], a.ipx[9] = net_from.ipx[9],
          a.port = net_from.port, qVar2 = NET_CompareAdr(a,prVar4->adr), qVar2 != false)) &&
         (prVar4->shouldreject != false)) {
        a_00.ip[0] = net_from.ip[0];
        a_00.ip[1] = net_from.ip[1];
        a_00.ip[2] = net_from.ip[2];
        a_00.ip[3] = net_from.ip[3];
        a_00.type = net_from.type;
        a_00.ipx[0] = net_from.ipx[0];
        a_00.ipx[1] = net_from.ipx[1];
        a_00.ipx[2] = net_from.ipx[2];
        a_00.ipx[3] = net_from.ipx[3];
        a_00.ipx[4] = net_from.ipx[4];
        a_00.ipx[5] = net_from.ipx[5];
        a_00.ipx[6] = net_from.ipx[6];
        a_00.ipx[7] = net_from.ipx[7];
        a_00.ipx[8] = net_from.ipx[8];
        a_00.ipx[9] = net_from.ipx[9];
        a_00.port = net_from.port;
        pcVar3 = NET_AdrToString(a_00);
        Con_Printf("Banning %s for rcon hacking attempts\n",pcVar3);
        a_01.ip[0] = net_from.ip[0];
        a_01.ip[1] = net_from.ip[1];
        a_01.ip[2] = net_from.ip[2];
        a_01.ip[3] = net_from.ip[3];
        a_01.type = net_from.type;
        a_01.ipx[0] = net_from.ipx[0];
        a_01.ipx[1] = net_from.ipx[1];
        a_01.ipx[2] = net_from.ipx[2];
        a_01.ipx[3] = net_from.ipx[3];
        a_01.ipx[4] = net_from.ipx[4];
        a_01.ipx[5] = net_from.ipx[5];
        a_01.ipx[6] = net_from.ipx[6];
        a_01.ipx[7] = net_from.ipx[7];
        a_01.ipx[8] = net_from.ipx[8];
        a_01.ipx[9] = net_from.ipx[9];
        a_01.port = net_from.port;
        pcVar3 = NET_BaseAdrToString(a_01);
        pcVar3 = va("addip %i %s\n",(int)sv_rcon_banpenalty.value,pcVar3);
        Cbuf_AddText(pcVar3);
        return 3;
      }
      prVar4 = prVar4 + 1;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: rcon_failure_t * r@[???] */
    } while (prVar4 != (rcon_failure_t *)&hashstrings_collisions);
                    /* Unresolved local var: int i@[???] */
    iVar5 = 0;
    pcVar3 = Cmd_Argv(1);
    iVar1 = Q_atoi(pcVar3);
    adr.ip[0] = net_from.ip[0];
    adr.ip[1] = net_from.ip[1];
    adr.ip[2] = net_from.ip[2];
    adr.ip[3] = net_from.ip[3];
    adr.type = net_from.type;
    adr.ipx[0] = net_from.ipx[0];
    adr.ipx[1] = net_from.ipx[1];
    adr.ipx[2] = net_from.ipx[2];
    adr.ipx[3] = net_from.ipx[3];
    adr.ipx[4] = net_from.ipx[4];
    adr.ipx[5] = net_from.ipx[5];
    adr.ipx[6] = net_from.ipx[6];
    adr.ipx[7] = net_from.ipx[7];
    adr.ipx[8] = net_from.ipx[8];
    adr.ipx[9] = net_from.ipx[9];
    adr.port = net_from.port;
    qVar2 = NET_IsLocalAddress(adr);
    if (qVar2 == false) {
      while (a_02.ip[0] = net_from.ip[0], a_02.ip[1] = net_from.ip[1], a_02.ip[2] = net_from.ip[2],
            a_02.ip[3] = net_from.ip[3], a_02.type = net_from.type, a_02.ipx[0] = net_from.ipx[0],
            a_02.ipx[1] = net_from.ipx[1], a_02.ipx[2] = net_from.ipx[2],
            a_02.ipx[3] = net_from.ipx[3], a_02.ipx[4] = net_from.ipx[4],
            a_02.ipx[5] = net_from.ipx[5], a_02.ipx[6] = net_from.ipx[6],
            a_02.ipx[7] = net_from.ipx[7], a_02.ipx[8] = net_from.ipx[8],
            a_02.ipx[9] = net_from.ipx[9], a_02.port = net_from.port,
            qVar2 = NET_CompareBaseAdr(a_02,g_rg_sv_challenges[iVar5].adr), qVar2 == false) {
                    /* Unresolved local var: int i@[???] */
        iVar5 = iVar5 + 1;
        if (iVar5 == 0x400) {
          SV_RejectConnection(&net_from,"No challenge for your address.\n");
          return 2;
        }
      }
      if (iVar1 != g_rg_sv_challenges[iVar5].challenge) {
        SV_RejectConnection(&net_from,"Bad challenge.\n");
        return 2;
      }
    }
    pcVar3 = rcon_password.string;
    s1 = Cmd_Argv(2);
    iVar1 = Q_strcmp(s1,pcVar3);
    if (iVar1 == 0) {
      return 0;
    }
    SV_AddFailedRcon(&net_from);
  }
  return 1;
}


// SV_ReachedGoal  @ 00097c30
qboolean SV_ReachedGoal(edict_t *ent,vec_t *vecGoal,float flDist)

{
                    /* Unresolved local var: int i@[???] */
  if ((((*vecGoal <= (ent->v).absmax[0] + flDist) && ((ent->v).absmin[0] - flDist <= *vecGoal)) &&
      (vecGoal[1] <= (ent->v).absmax[1] + flDist)) &&
     (((ent->v).absmin[1] - flDist <= vecGoal[1] && (vecGoal[2] <= (ent->v).absmax[2] + flDist)))) {
    return (uint)((ent->v).absmin[2] - flDist <= vecGoal[2]);
  }
  return false;
}


// SV_ReadPackets  @ 00093f80
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ReadPackets(void)

{
  netchan_t *chan;
  netadr_t a;
  netadr_t_conflict adr;
  netadr_t a_00;
  netadr_t to;
  uchar auVar1 [4];
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint16_t port;
  qboolean qVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  uint32_t fromip;
  ipfilter_t *__dest;
  int iVar9;
  client_s *cl;
  int in_GS_OFFSET;
  int local_7c;
  char local_60 [64];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: qboolean file@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  do {
    qVar5 = NET_GetPacket(NS_SERVER);
    auVar1 = net_from.ip;
    uVar2 = net_from.ipx._0_4_;
    uVar3 = net_from.ipx._4_4_;
    uVar4 = net_from._16_4_;
    while( true ) {
      net_from.ip = auVar1;
      net_from.ipx._0_4_ = uVar2;
      net_from.ipx._4_4_ = uVar3;
      net_from._16_4_ = uVar4;
      if (qVar5 == false) {
        net_from.ip[0] = auVar1[0];
        net_from.ip[1] = auVar1[1];
        net_from.ip[2] = auVar1[2];
        net_from.ip[3] = auVar1[3];
        net_from.ipx[0] = (uchar)uVar2;
        net_from.ipx[1] = SUB41(uVar2,1);
        net_from.ipx[2] = SUB41(uVar2,2);
        net_from.ipx[3] = SUB41(uVar2,3);
        net_from.ipx[4] = (uchar)uVar3;
        net_from.ipx[5] = SUB41(uVar3,1);
        net_from.ipx[6] = SUB41(uVar3,2);
        net_from.ipx[7] = SUB41(uVar3,3);
        net_from.ipx[8] = (uchar)uVar4;
        net_from.ipx[9] = SUB41(uVar4,1);
        net_from.port = SUB42(uVar4,2);
        if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
          net_from.ip = auVar1;
          net_from.ipx._0_4_ = uVar2;
          net_from.ipx._4_4_ = uVar3;
          net_from._16_4_ = uVar4;
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return;
      }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: uint in@[???] */
      iVar7 = numipfilters + -1;
      __dest = ipfilters + iVar7;
      if (-1 < iVar7) {
        do {
          iVar9 = numipfilters;
          if (((__dest->compare == 0xffffffff) || ((double)__dest->banEndTime == 0.0)) ||
             (realtime < (double)__dest->banEndTime)) {
            if (__dest->compare == (__dest->mask & (uint)auVar1)) {
              local_7c = (int)(longlong)ROUND(sv_filterban.value);
              if (local_7c != 0) goto LAB_000941f1;
              goto LAB_0009407e;
            }
          }
          else {
            if (iVar7 + 1 < numipfilters) {
              memmove(__dest,__dest + 1,((numipfilters + 0xfffffff) - iVar7) * 0x10);
            }
            numipfilters = iVar9 + -1;
          }
          iVar7 = iVar7 + -1;
          __dest = __dest + -1;
        } while (iVar7 != -1);
      }
      if (sv_filterban.value != 0.0) break;
LAB_000941f1:
                    /* Unresolved local var: char[64] szMessage@[???] */
      uVar6 = 0;
      do {
        *(undefined4 *)(local_60 + uVar6) =
             *(undefined4 *)("You have been banned from this server.\n" + uVar6);
        uVar6 = uVar6 + 4;
      } while (uVar6 < 0x28);
      SZ_Clear(&net_message);
      MSG_WriteLong(&net_message,-1);
      MSG_WriteByte(&net_message,0x6c);
      MSG_WriteString(&net_message,local_60);
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
      NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,to);
      SZ_Clear(&net_message);
      NET_CheckCleanupFakeIPConnection(NS_SERVER,(netadr_t_conflict *)&net_from);
      qVar5 = NET_GetPacket(NS_SERVER);
      auVar1 = net_from.ip;
      uVar2 = net_from.ipx._0_4_;
      uVar3 = net_from.ipx._4_4_;
      uVar4 = net_from._16_4_;
    }
LAB_0009407e:
    if (*(int *)net_message.data == -1) {
      adr.ip[0] = net_from.ip[0];
      adr.ip[1] = net_from.ip[1];
      adr.ip[2] = net_from.ip[2];
      adr.ip[3] = net_from.ip[3];
      adr.type = net_from.type;
      adr.ipx[0] = net_from.ipx[0];
      adr.ipx[1] = net_from.ipx[1];
      adr.ipx[2] = net_from.ipx[2];
      adr.ipx[3] = net_from.ipx[3];
      adr.ipx[4] = (char)net_from.ipx._4_2_;
      adr.ipx[5] = (char)((ushort)net_from.ipx._4_2_ >> 8);
      adr.ipx[6] = (char)net_from.ipx._6_2_;
      adr.ipx[7] = (char)((ushort)net_from.ipx._6_2_ >> 8);
      adr.ipx[8] = net_from.ipx[8];
      adr.ipx[9] = net_from.ipx[9];
      adr.port = net_from.port;
      iVar7 = CheckIP(adr);
      if (iVar7 == 0) {
        if (sv_logblocks.value != 0.0) {
          a_00.ip[0] = net_from.ip[0];
          a_00.ip[1] = net_from.ip[1];
          a_00.ip[2] = net_from.ip[2];
          a_00.ip[3] = net_from.ip[3];
          a_00.type = net_from.type;
          a_00.ipx[0] = net_from.ipx[0];
          a_00.ipx[1] = net_from.ipx[1];
          a_00.ipx[2] = net_from.ipx[2];
          a_00.ipx[3] = net_from.ipx[3];
          a_00.ipx[4] = (char)net_from.ipx._4_2_;
          a_00.ipx[5] = (char)((ushort)net_from.ipx._4_2_ >> 8);
          a_00.ipx[6] = (char)net_from.ipx._6_2_;
          a_00.ipx[7] = (char)((ushort)net_from.ipx._6_2_ >> 8);
          a_00.ipx[8] = net_from.ipx[8];
          a_00.ipx[9] = net_from.ipx[9];
          a_00.port = net_from.port;
          pcVar8 = NET_AdrToString(a_00);
          Log_Printf("Traffic from %s was blocked for exceeding rate limits\n",pcVar8);
        }
      }
      else {
        port = htons(net_from.port);
        fromip = ntohl((uint32_t)net_from.ip);
        Steam_HandleIncomingPacket(net_message.data,net_message.cursize,fromip,port);
        SV_ConnectionlessPacket();
      }
    }
    else if (0 < svs.maxclients) {
      iVar9 = 0;
      iVar7 = svs.maxclients;
      cl = svs.clients;
      do {
        if ((((cl->connected != false) || (cl->active != false)) || (cl->spawned != false)) &&
           (a.ip[0] = net_from.ip[0], a.ip[1] = net_from.ip[1], a.ip[2] = net_from.ip[2],
           a.ip[3] = net_from.ip[3], a.type = net_from.type, a.ipx[0] = net_from.ipx[0],
           a.ipx[1] = net_from.ipx[1], a.ipx[2] = net_from.ipx[2], a.ipx[3] = net_from.ipx[3],
           a.ipx[4] = (char)net_from.ipx._4_2_, a.ipx[5] = (char)((ushort)net_from.ipx._4_2_ >> 8),
           a.ipx[6] = (char)net_from.ipx._6_2_, a.ipx[7] = (char)((ushort)net_from.ipx._6_2_ >> 8),
           a.ipx[8] = net_from.ipx[8], a.ipx[9] = net_from.ipx[9], a.port = net_from.port,
           qVar5 = NET_CompareAdr(a,(cl->netchan).remote_address), iVar7 = svs.maxclients,
           qVar5 != false)) {
          chan = &cl->netchan;
          qVar5 = Netchan_Process(chan);
          if (qVar5 != false) {
            if (svs.maxclients == 1) {
              cl->send_message = true;
            }
            if (((cl->active == false) || (cl->spawned == false)) || (cl->fully_connected == false))
            {
              cl->send_message = true;
            }
            SV_ExecuteClientMessage(cl);
            gGlobalVariables.frametime = (float)host_frametime;
          }
          qVar5 = Netchan_IncomingReady(chan);
          iVar7 = svs.maxclients;
          if (qVar5 != false) {
            qVar5 = Netchan_CopyNormalFragments(chan);
            if (qVar5 != false) {
              MSG_BeginReading();
              SV_ExecuteClientMessage(cl);
            }
            qVar5 = Netchan_CopyFileFragments(chan);
            iVar7 = svs.maxclients;
            if (qVar5 != false) {
              host_client = cl;
              SV_ProcessFile(cl,(cl->netchan).incomingfilename);
              iVar7 = svs.maxclients;
            }
          }
        }
        iVar9 = iVar9 + 1;
        cl = cl + 1;
      } while (iVar9 < iVar7);
    }
  } while( true );
}


// SV_ReallocateDynamicData  @ 00081e70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ReallocateDynamicData(void)

{
  int iVar1;
  
                    /* Unresolved local var: int nSize@[???] */
  iVar1 = sv.max_edicts;
  if (sv.max_edicts != 0) {
    if (g_moved_edict != (edict_t **)0x0) {
      Con_Printf("Reallocate on moved_edict\n");
    }
    g_moved_edict = Mem_ZeroMalloc(iVar1 * 4);
    if (g_moved_from != (vec3_t *)0x0) {
      Con_Printf("Reallocate on moved_from\n");
    }
    g_moved_from = Mem_ZeroMalloc(iVar1 * 0xc);
    return;
  }
  Con_DPrintf("SV_ReallocateDynamicData with sv.max_edicts == 0");
  return;
}


// SV_ReconnectAllClients  @ 0008e650
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ReconnectAllClients(void)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int in_GS_OFFSET;
  bool bVar7;
  char local_42 [34];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[34] message@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar7 = ((uint)local_42 & 2) != 0;
  if (bVar7) {
    pcVar3 = local_42 + 2;
    pcVar2 = "rver updating Security Module.\n";
    uVar5 = 0x20;
    local_42[0] = 'S';
    local_42[1] = 'e';
  }
  else {
    pcVar2 = "Server updating Security Module.\n";
    uVar5 = 0x22;
    pcVar3 = local_42;
  }
  uVar1 = 0;
  do {
    *(undefined4 *)(pcVar3 + uVar1) = *(undefined4 *)(pcVar2 + uVar1);
    uVar1 = uVar1 + 4;
  } while (uVar1 < (uVar5 & 0xfffffffc));
  if (!bVar7) {
    *(undefined2 *)(pcVar3 + uVar1) = *(undefined2 *)(pcVar2 + uVar1);
  }
  iVar6 = 0;
  host_client = svs.clients;
  iVar4 = svs.maxclients;
  if (0 < svs.maxclients) {
    do {
      while (((host_client->active == false && (host_client->connected == false)) ||
             (host_client->fakeclient != false))) {
        iVar6 = iVar6 + 1;
        host_client = host_client + 1;
        if (iVar4 <= iVar6) goto LAB_0008e789;
      }
      iVar6 = iVar6 + 1;
      Netchan_Clear(&host_client->netchan);
      MSG_WriteByte(&(host_client->netchan).message,8);
      MSG_WriteString(&(host_client->netchan).message,local_42);
      MSG_WriteByte(&(host_client->netchan).message,9);
      MSG_WriteString(&(host_client->netchan).message,"retry\n");
      SV_DropClient(host_client,false,local_42);
      host_client = host_client + 1;
      iVar4 = svs.maxclients;
    } while (iVar6 < svs.maxclients);
  }
LAB_0008e789:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_RecursiveHullCheck  @ 000aa2c0
/* WARNING: Type propagation algorithm not settling */

qboolean SV_RecursiveHullCheck
                   (hull_t *hull,int num,float p1f,float p2f,vec_t *p1,vec_t *p2,trace_t *trace)

{
  dclipnode_t *pdVar1;
  dclipnode_t *pdVar2;
  mplane_t *pmVar3;
  byte bVar4;
  short sVar5;
  float fVar6;
  mplane_t *pmVar7;
  qboolean qVar8;
  bool bVar9;
  int iVar10;
  int iVar11;
  float local_48;
  float local_44;
  float local_3c;
  float local_28 [6];
  
                    /* Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???]
                       Unresolved local var: float t1@[???]
                       Unresolved local var: float t2@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t mid@[???]
                       Unresolved local var: int side@[???]
                       Unresolved local var: float midf@[???] */
  if (num < 0) {
    if (num == -2) {
      trace->startsolid = true;
      return true;
    }
    trace->allsolid = false;
    if (num == -1) {
      trace->inopen = true;
      return true;
    }
    if (num != -0xf) {
      trace->inwater = true;
      return true;
    }
    return true;
  }
  if (((num < hull->firstclipnode) || (hull->lastclipnode < num)) ||
     (pmVar7 = hull->planes, pmVar7 == (mplane_t *)0x0)) {
    Sys_Error("SV_RecursiveHullCheck: bad node number");
    pmVar7 = hull->planes;
  }
  pdVar1 = hull->clipnodes + num;
  pmVar7 = pmVar7 + pdVar1->planenum;
  bVar4 = pmVar7->type;
  if (bVar4 < 3) {
    local_44 = p1[bVar4] - pmVar7->dist;
    fVar6 = p2[bVar4] - pmVar7->dist;
  }
  else {
    local_44 = (pmVar7->normal[2] * p1[2] + pmVar7->normal[1] * p1[1] + pmVar7->normal[0] * *p1) -
               pmVar7->dist;
    fVar6 = (pmVar7->normal[2] * p2[2] + pmVar7->normal[1] * p2[1] + pmVar7->normal[0] * *p2) -
            pmVar7->dist;
  }
  if ((0.0 <= local_44) && (0.0 <= fVar6)) {
    qVar8 = SV_RecursiveHullCheck(hull,(int)pdVar1->children[0],p1f,p2f,p1,p2,trace);
    return qVar8;
  }
  if (local_44 < 0.0) {
    if (fVar6 < 0.0) {
      qVar8 = SV_RecursiveHullCheck(hull,(int)pdVar1->children[1],p1f,p2f,p1,p2,trace);
      return qVar8;
    }
  }
  else if (0.0 <= local_44) {
    local_48 = (local_44 - 0.03125) / (local_44 - fVar6);
    goto joined_r0x000aa78c;
  }
  local_48 = (local_44 + 0.03125) / (local_44 - fVar6);
joined_r0x000aa78c:
  if (local_48 < 0.0) {
    local_48 = 0.0;
  }
  else if (1.0 < local_48) {
    local_48 = 1.0;
  }
  if (nanmask != ((uint)local_48 & nanmask)) {
    local_3c = local_48 * (p2f - p1f) + p1f;
    local_28[0] = (*p2 - *p1) * local_48 + *p1;
    local_28[1] = (p2[1] - p1[1]) * local_48 + p1[1];
    local_28[2] = (p2[2] - p1[2]) * local_48 + p1[2];
    qVar8 = SV_RecursiveHullCheck
                      (hull,(int)pdVar1->children[local_44 < 0.0],p1f,local_3c,p1,local_28,trace);
    if (qVar8 != false) {
      bVar9 = local_44 >= 0.0;
      sVar5 = pdVar1->children[bVar9];
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
      while (iVar10 = (int)sVar5, -1 < iVar10) {
        while( true ) {
          if ((iVar10 < hull->firstclipnode) || (hull->lastclipnode < iVar10)) {
            Sys_Error("SV_HullPointContents: bad node number");
          }
          pdVar2 = hull->clipnodes + iVar10;
          pmVar3 = hull->planes + pdVar2->planenum;
          if (pmVar3->type < 3) {
            fVar6 = local_28[pmVar3->type] - pmVar3->dist;
          }
          else {
            fVar6 = (pmVar3->normal[2] * local_28[2] +
                    pmVar3->normal[1] * local_28[1] + pmVar3->normal[0] * local_28[0]) -
                    pmVar3->dist;
          }
          if (0.0 <= fVar6) break;
          iVar10 = (int)pdVar2->children[1];
          if (iVar10 < 0) goto LAB_000aa5fc;
        }
        sVar5 = pdVar2->children[0];
      }
LAB_000aa5fc:
      if (iVar10 != -2) {
        qVar8 = SV_RecursiveHullCheck
                          (hull,(int)pdVar1->children[bVar9],local_3c,p2f,local_28,p2,trace);
        return qVar8;
      }
      if (trace->allsolid == false) {
        if (local_44 < 0.0) {
          (trace->plane).normal[0] = vec3_origin[0] - pmVar7->normal[0];
          (trace->plane).normal[1] = vec3_origin[1] - pmVar7->normal[1];
          (trace->plane).normal[2] = vec3_origin[2] - pmVar7->normal[2];
          (trace->plane).dist = -pmVar7->dist;
        }
        else {
          (trace->plane).normal[0] = pmVar7->normal[0];
          (trace->plane).normal[1] = pmVar7->normal[1];
          (trace->plane).normal[2] = pmVar7->normal[2];
          (trace->plane).dist = pmVar7->dist;
        }
                    /* Unresolved local var: float d@[???]
                       Unresolved local var: dclipnode_t * node@[???]
                       Unresolved local var: mplane_t * plane@[???] */
        while (iVar10 = hull->firstclipnode, iVar11 = iVar10, iVar10 < 0) {
LAB_000aa6f3:
          if (iVar11 != -2) {
            trace->fraction = local_3c;
            trace->endpos[0] = local_28[0];
            trace->endpos[1] = local_28[1];
            trace->endpos[2] = local_28[2];
            return false;
          }
          local_48 = local_48 - 0.1;
          if (local_48 < 0.0) {
            trace->fraction = local_3c;
            trace->endpos[0] = local_28[0];
            trace->endpos[1] = local_28[1];
            trace->endpos[2] = local_28[2];
            Con_DPrintf("backup past 0\n");
            return false;
          }
          local_3c = (p2f - p1f) * local_48 + p1f;
          local_28[0] = (*p2 - *p1) * local_48 + *p1;
          local_28[1] = (p2[1] - p1[1]) * local_48 + p1[1];
          local_28[2] = (p2[2] - p1[2]) * local_48 + p1[2];
        }
        do {
          if ((iVar11 < iVar10) || (hull->lastclipnode < iVar11)) {
            Sys_Error("SV_HullPointContents: bad node number");
          }
          pdVar1 = hull->clipnodes + iVar11;
          pmVar7 = hull->planes + pdVar1->planenum;
          if (pmVar7->type < 3) {
            if (0.0 <= local_28[pmVar7->type] - pmVar7->dist) goto LAB_000aa68f;
LAB_000aa6eb:
            sVar5 = pdVar1->children[1];
          }
          else {
            if ((pmVar7->normal[2] * local_28[2] +
                pmVar7->normal[1] * local_28[1] + pmVar7->normal[0] * local_28[0]) - pmVar7->dist <
                0.0) goto LAB_000aa6eb;
LAB_000aa68f:
            sVar5 = pdVar1->children[0];
          }
          iVar11 = (int)sVar5;
          if (iVar11 < 0) goto LAB_000aa6f3;
          iVar10 = hull->firstclipnode;
        } while( true );
      }
    }
  }
  return false;
}


// SV_RecursiveWaterLevel  @ 0009bff0
float SV_RecursiveWaterLevel(vec_t *center,float out,float in,int count)

{
  float in_00;
  int iVar1;
  int iVar2;
  float in_01;
  vec_t local_24;
  vec_t local_20;
  float local_1c;
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
  in_00 = (out - in) * 0.5 + in;
  in_01 = in_00;
  if (count + 1 < 6) {
    local_1c = in_00 + center[2];
    local_24 = *center;
    local_20 = center[1];
    iVar1 = SV_PointContents(&local_24);
    if (iVar1 == -3) {
      in_01 = SV_RecursiveWaterLevel(center,out,in_00,count + 1);
    }
    else {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
      iVar1 = count + 2;
      in_01 = in + (in_00 - in) * 0.5;
      if (iVar1 < 6) {
        local_10 = in_01 + center[2];
        local_18 = *center;
        local_14 = center[1];
        iVar2 = SV_PointContents(&local_18);
        if (iVar2 == -3) {
          in_01 = SV_RecursiveWaterLevel(center,in_00,in_01,iVar1);
        }
        else {
          in_01 = SV_RecursiveWaterLevel(center,in_01,in,iVar1);
        }
      }
    }
  }
  return in_01;
}


// SV_RegisterDelta  @ 00090f30
void SV_RegisterDelta(char *name,char *loadfile)

{
  qboolean qVar1;
  delta_info_t *pdVar2;
  char *pcVar3;
  delta_t *local_10;
  
                    /* Unresolved local var: delta_t * pdesc@[???]
                       Unresolved local var: delta_info_t * p@[???] */
  local_10 = (delta_t *)0x0;
  qVar1 = DELTA_Load(name,&local_10,loadfile);
  if (qVar1 != false) {
    pdVar2 = Mem_ZeroMalloc(0x10);
    pcVar3 = Mem_Strdup(loadfile);
    pdVar2->loadfile = pcVar3;
    pcVar3 = Mem_Strdup(name);
    pdVar2->name = pcVar3;
    pdVar2->delta = local_10;
    pdVar2->next = g_sv_delta;
    g_sv_delta = pdVar2;
    return;
  }
  Sys_Error("Error parsing %s!!!\n",loadfile);
  return;
}


// SV_RegisterResources  @ 0009eb90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_RegisterResources(void)

{
  resource_t *prVar1;
  resource_s *s;
  client_t *pHost;
  int iVar2;
  int c;
  
                    /* Unresolved local var: resource_t * pResource@[???]
                       Unresolved local var: client_t * pHost@[???] */
  pHost = host_client;
  s = (host_client->resourcesonhand).pNext;
  prVar1 = &host_client->resourcesonhand;
  host_client->uploading = false;
  do {
    while( true ) {
      if (s == prVar1) {
        host_client = pHost;
        return;
      }
      SV_CreateCustomizationList(pHost);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int nPlayerNumber@[???] */
      host_client = svs.clients;
      if (0 < svs.maxclients) break;
LAB_0009ed4e:
      Sys_Error("Couldn\'t find player index for customization.");
      s = s->pNext;
    }
    c = 0;
    if (pHost != svs.clients) {
      c = 0;
      host_client = svs.clients;
      do {
        c = c + 1;
        host_client = host_client + 1;
        if (c == svs.maxclients) goto LAB_0009ed4e;
      } while (pHost != host_client);
      host_client = pHost;
      if (c == -1) goto LAB_0009ed4e;
    }
    iVar2 = 0;
    host_client = svs.clients;
    do {
      if ((((host_client->active != false) || (host_client->spawned != false)) &&
          (host_client->fakeclient == false)) && (pHost != host_client)) {
        MSG_WriteByte(&(host_client->netchan).message,0x2e);
        MSG_WriteByte(&(host_client->netchan).message,c);
        MSG_WriteByte(&(host_client->netchan).message,s->type);
        MSG_WriteString(&(host_client->netchan).message,s->szFileName);
        MSG_WriteShort(&(host_client->netchan).message,s->nIndex);
        MSG_WriteLong(&(host_client->netchan).message,s->nDownloadSize);
        MSG_WriteByte(&(host_client->netchan).message,(uint)s->ucFlags);
        if ((s->ucFlags & 4) != 0) {
          SZ_Write(&(host_client->netchan).message,s->rgucMD5_hash,0x10);
        }
      }
      iVar2 = iVar2 + 1;
      host_client = host_client + 1;
    } while (iVar2 < svs.maxclients);
    s = s->pNext;
  } while( true );
}


// SV_RejectConnection  @ 00085280
void SV_RejectConnection(netadr_t *adr,char *fmt,...)

{
  int in_GS_OFFSET;
  char local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] text@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __vsnprintf_chk(local_410,0x400,1,0x400,fmt,&stack0x0000000c);
  SZ_Clear(&net_message);
  MSG_WriteLong(&net_message,-1);
  MSG_WriteByte(&net_message,0x39);
  MSG_WriteString(&net_message,local_410);
  NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,*adr);
  SZ_Clear(&net_message);
  NET_CheckCleanupFakeIPConnection(NS_SERVER,(netadr_t_conflict *)adr);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_RejectConnectionForPassword  @ 000853a0
void SV_RejectConnectionForPassword(netadr_t *adr)

{
  SZ_Clear(&net_message);
  MSG_WriteLong(&net_message,-1);
  MSG_WriteByte(&net_message,0x38);
  MSG_WriteString(&net_message,"BADPASSWORD");
  NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,*adr);
  SZ_Clear(&net_message);
  return;
}


// SV_RemoveFromResourceList  @ 0009eeb0
void SV_RemoveFromResourceList(resource_t *pResource)

{
  pResource->pPrev->pNext = pResource->pNext;
  pResource->pNext->pPrev = pResource->pPrev;
  pResource->pPrev = (resource_s *)0x0;
  pResource->pNext = (resource_s *)0x0;
  return;
}


// SV_RemoveIP_f  @ 00080c30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_RemoveIP_f(void)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  ipfilter_t *piVar5;
  char *pcVar6;
  int iVar7;
  int in_GS_OFFSET;
  uint local_98;
  uint local_94;
  char local_90 [128];
  int local_10;
  
                    /* Unresolved local var: ipfilter_t f@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar3 = Cmd_Argv(1);
  local_98 = 0;
  iVar7 = 0;
  local_94 = 0;
  do {
                    /* Unresolved local var: char[128] num@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: byte[4] b@[???]
                       Unresolved local var: byte[4] m@[???] */
    cVar2 = *pcVar3;
    if (9 < (byte)(cVar2 - 0x30U)) {
      Con_Printf("Bad filter address: %s\n",pcVar3);
      goto LAB_00080d7d;
    }
    iVar1 = 0;
    do {
      pcVar6 = pcVar3;
      iVar4 = iVar1;
      pcVar3 = pcVar6 + 1;
      local_90[iVar4] = cVar2;
      cVar2 = *pcVar3;
      iVar1 = iVar4 + 1;
    } while ((byte)(cVar2 - 0x30U) < 10);
    local_90[iVar4 + 1] = '\0';
    iVar4 = Q_atoi(local_90);
    iVar1 = numipfilters;
    *(char *)((int)&local_98 + iVar7) = (char)iVar4;
    if ((char)iVar4 != '\0') {
      local_90[iVar7 + -4] = -1;
    }
    if (*pcVar3 == '\0') break;
    iVar7 = iVar7 + 1;
    pcVar3 = pcVar6 + 2;
  } while (iVar7 != 4);
  if (0 < numipfilters) {
    piVar5 = ipfilters;
    iVar7 = 0;
    do {
      if ((piVar5->mask == local_94) && (piVar5->compare == local_98)) {
        if (iVar7 + 1 < numipfilters) {
          memmove(ipfilters + iVar7,ipfilters + iVar7 + 1,
                  ((numipfilters + 0xfffffff) - iVar7) * 0x10);
        }
        iVar1 = iVar1 + -1;
        numipfilters = iVar1;
        ipfilters[iVar1].banTime = 0.0;
        ipfilters[iVar1].banEndTime = 0.0;
        ipfilters[iVar1].compare = 0;
        ipfilters[iVar1].mask = 0;
        Con_Printf("IP filter removed.\n");
        goto LAB_00080d7d;
      }
      iVar7 = iVar7 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar7 != numipfilters);
  }
  pcVar3 = Cmd_Argv(1);
  Con_Printf("removeip: couldn\'t find %s.\n",pcVar3);
LAB_00080d7d:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_RemoveId_f  @ 000921b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_RemoveId_f(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  userfilter_t *id;
  int in_GS_OFFSET;
  USERID_t local_60;
  char local_50;
  char local_4f [62];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: char[64] idstring@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = Cmd_Argc();
  if ((iVar1 == 2) || (iVar1 = Cmd_Argc(), iVar1 == 6)) {
    pcVar2 = Cmd_Argv(1);
    strncpy(&local_50,pcVar2,0x3f);
    local_11 = 0;
    if (local_50 == '\0') {
      Con_Printf("SV_RemoveId_f:  Id string is empty!\n");
    }
    else if (local_50 == '#') {
                    /* Unresolved local var: int slot@[???] */
      iVar6 = Q_atoi(local_4f);
      iVar1 = numuserfilters;
      if ((iVar6 < 1) || (numuserfilters < iVar6)) {
        Con_Printf("SV_RemoveId_f:  invalid slot #%i\n",iVar6);
      }
      else {
                    /* Unresolved local var: USERID_t id@[???] */
        local_60.idtype = userfilters[iVar6 + -1].userid.idtype;
        local_60.m_SteamID._0_4_ = (undefined4)userfilters[iVar6 + -1].userid.m_SteamID;
        local_60.m_SteamID._4_4_ =
             *(undefined4 *)((int)&userfilters[iVar6 + -1].userid.m_SteamID + 4);
        local_60.clientip = userfilters[iVar6 + -1].userid.clientip;
        if (iVar6 < numuserfilters) {
          memmove((void *)((int)sv_decalnames + iVar6 * 0x18 + 0x21e8),userfilters + iVar6,
                  (numuserfilters - iVar6) * 0x18);
        }
        numuserfilters = iVar1 + -1;
        pcVar2 = SV_GetIDString(&local_60);
        Con_Printf("UserID filter removed for %s, id %s\n",&local_50,pcVar2);
      }
    }
    else {
      iVar1 = Q_strnicmp(&local_50,"STEAM_",6);
      if ((iVar1 == 0) || (iVar1 = Q_strnicmp(&local_50,"VALVE_",6), iVar1 == 0)) {
        pcVar2 = Cmd_Argv(5);
        pcVar3 = Cmd_Argv(3);
        pcVar4 = Cmd_Argv(1);
        __snprintf_chk(&local_50,0x3f,1,0x40,"%s:%s:%s",pcVar4,pcVar3,pcVar2);
        local_11 = 0;
      }
      if (0 < numuserfilters) {
        id = userfilters;
        iVar1 = 0;
        do {
          pcVar2 = SV_GetIDString(&id->userid);
          iVar5 = Q_stricmp(pcVar2,&local_50);
          iVar6 = numuserfilters;
          if (iVar5 == 0) {
            if (iVar1 + 1 < numuserfilters) {
              memmove(userfilters + iVar1,userfilters + iVar1 + 1,
                      (numuserfilters - iVar1) * 0x18 - 0x18);
            }
            numuserfilters = iVar6 + -1;
            Con_Printf("UserID filter removed for %s\n",&local_50);
            goto LAB_000921e2;
          }
          iVar1 = iVar1 + 1;
          id = id + 1;
        } while (iVar1 < numuserfilters);
      }
      Con_Printf("removeid: couldn\'t find %s\n",&local_50);
    }
  }
  else {
    Con_Printf("Usage:  removeid <uniqueid | #slotnumber>\n");
  }
LAB_000921e2:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_RequestMissingResources  @ 0009f270
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean SV_RequestMissingResources(void)

{
  client_t *pcVar1;
  
  pcVar1 = host_client;
  if (((host_client->uploading != false) && (host_client->uploaddoneregistering == false)) &&
     ((host_client->resourcesneeded).pNext == &host_client->resourcesneeded)) {
    SV_RegisterResources();
    SV_PropagateCustomizations();
    if (sv_allow_upload.value != 0.0) {
      Con_DPrintf("Custom resource propagation complete.\n");
    }
    pcVar1->uploaddoneregistering = true;
  }
  return false;
}


// SV_RequestMissingResourcesFromClients  @ 0009ef70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_RequestMissingResourcesFromClients(void)

{
  int iVar1;
  client_t *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  host_client = svs.clients;
  if (0 < svs.maxclients) {
    iVar3 = 0;
    iVar1 = svs.maxclients;
    pcVar2 = svs.clients;
    do {
      if ((((pcVar2->active != false) || (pcVar2->spawned != false)) && (pcVar2->uploading != false)
          ) && ((pcVar2->uploaddoneregistering == false &&
                ((pcVar2->resourcesneeded).pNext == &pcVar2->resourcesneeded)))) {
        host_client = pcVar2;
        SV_RegisterResources();
        SV_PropagateCustomizations();
        if (sv_allow_upload.value != 0.0) {
          Con_DPrintf("Custom resource propagation complete.\n");
        }
        iVar1 = svs.maxclients;
        pcVar2->uploaddoneregistering = true;
        pcVar2 = host_client;
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 1;
      host_client = pcVar2;
    } while (iVar3 < iVar1);
  }
  return;
}


// SV_ResetModInfo  @ 00086860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ResetModInfo(void)

{
  FileHandle_t file;
  uint size;
  char *pOutput;
  char *pcVar1;
  int iVar2;
  int in_GS_OFFSET;
  uint uVar3;
  char local_264 [63];
  undefined1 local_225;
  char local_224 [255];
  undefined1 local_125;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: char * pszInputStream@[???]
                       Unresolved local var: char * pStreamPos@[???]
                       Unresolved local var: char[260] szDllListFile@[???]
                       Unresolved local var: int nFileSize@[???]
                       Unresolved local var: int nBytesRead@[???]
                       Unresolved local var: FileHandle_t hLibListFile@[???]
                       Unresolved local var: char[64] szKey@[???]
                       Unresolved local var: char[256] szValue@[???] */
  uVar3 = 0x244;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&gmodinfo,0,0x244);
  gmodinfo.version = 1;
  gmodinfo.svonly = true;
  gmodinfo.num_edicts = 0x4b0;
  builtin_strncpy(local_124,"liblist.gam",0xc);
  file = FS_Open(local_124,"rb");
  if (file != (FileHandle_t)0x0) {
    size = FS_Size(file);
    if ((size == 0) || (0x40000 < (int)size)) {
      uVar3 = size;
      Sys_Error("Game listing file size is bogus [%s: size %i]","liblist.gam",size);
    }
    pOutput = Mem_Malloc(size + 1);
    if (pOutput == (char *)0x0) {
      Sys_Error("Could not allocate space for game listing file of %i bytes",size + 1,uVar3);
    }
    uVar3 = FS_Read(pOutput,size,1,file);
    if (size != uVar3) {
      Sys_Error("Error reading in game listing file, expected %i bytes, read %i",size,uVar3);
    }
    pOutput[size] = '\0';
    com_ignorecolons = true;
    pcVar1 = pOutput;
    while( true ) {
      pcVar1 = COM_Parse(pcVar1);
      iVar2 = Q_strlen(com_token);
      if (iVar2 < 1) break;
      Q_strncpy(local_264,com_token,0x3f);
      local_225 = 0;
      pcVar1 = COM_Parse(pcVar1);
      Q_strncpy(local_224,com_token,0xff);
      local_125 = 0;
      iVar2 = Q_stricmp(local_264,"gamedll_linux");
      if (iVar2 != 0) {
        DLL_SetModKey(&gmodinfo,local_264,local_224);
      }
    }
    com_ignorecolons = false;
    Mem_Free(pOutput);
    FS_Close(file);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_ResetRcon_f  @ 00080380
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ResetRcon_f(void)

{
  Q_memset(g_rgRconFailures,0,0xe80);
  return;
}


// SV_RestoreMove  @ 000a32a0
void SV_RestoreMove(client_t *host_client)

{
  int iVar1;
  int iVar2;
  int iVar3;
  vec_t *v2;
  int iVar4;
  client_t *pcVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: sv_adjusted_positions_t * pos@[???] */
  if (nofind == false) {
    iVar1 = (*gEntityInterface.pfnAllowLagCompensation)();
    if (((((iVar1 != 0) && (1 < svs.maxclients)) && (sv_unlag.value != 0.0)) &&
        ((host_client->lw != 0 && (host_client->lc != 0)))) && (host_client->active != false)) {
      v2 = truepositions[0].oldorg;
      iVar4 = 0;
      iVar3 = 0;
      iVar1 = svs.maxclients;
      do {
        pcVar5 = (client_t *)(((svs.clients)->netchan).remote_address.ip + iVar4 + -0x24);
        if (((host_client != pcVar5) && (pcVar5->active != false)) &&
           ((iVar2 = VectorCompare(v2 + -3,v2), iVar1 = svs.maxclients, iVar2 == 0 &&
            (v2[-4] != 0.0)))) {
          if (((sv_adjusted_positions_t *)(v2 + -5))->active == 0) {
            Con_DPrintf("SV_RestoreMove:  Tried to restore \'inactive\' player %i/%s\n",iVar3,
                        pcVar5->name);
            iVar1 = svs.maxclients;
          }
          else {
            iVar2 = VectorCompare(v2 + 3,(pcVar5->edict->v).origin);
            iVar1 = svs.maxclients;
            if (iVar2 != 0) {
              (pcVar5->edict->v).origin[0] = *v2;
              (pcVar5->edict->v).origin[1] = v2[1];
              (pcVar5->edict->v).origin[2] = v2[2];
              SV_LinkEdict(pcVar5->edict,false);
              iVar1 = svs.maxclients;
            }
          }
        }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: sv_adjusted_positions_t * pos@[???] */
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x6668;
        v2 = v2 + 0x16;
      } while (iVar3 < iVar1);
    }
    return;
  }
  nofind = false;
  return;
}


// SV_RunCmd  @ 000a3990
void SV_RunCmd(usercmd_t *ucmd,int random_seed)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  vec_t *pvVar8;
  edict_t *peVar9;
  playermove_t *ppVar10;
  edict_t *peVar11;
  uint uVar12;
  client_t *pcVar13;
  byte bVar14;
  int iVar15;
  float fVar16;
  usercmd_t local_78;
  trace_t local_44;
  
                    /* Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int n@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: float frametime@[???]
                       Unresolved local var: usercmd_t cmd@[???] */
  pcVar13 = host_client;
  uVar6 = 0;
  do {
    *(undefined4 *)((int)local_78.viewangles + (uVar6 - 4)) =
         *(undefined4 *)((int)ucmd->viewangles + (uVar6 - 4));
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0x34);
  if (realtime < host_client->ignorecmdtime) {
    host_client->cmdtime = (double)((float)ucmd->msec / 1000.0 + (float)host_client->cmdtime);
    return;
  }
  *(undefined4 *)((int)&host_client->ignorecmdtime + 4) = 0;
  *(undefined4 *)&pcVar13->ignorecmdtime = 0;
  if (50.0 < (float)local_78.msec) {
                    /* Unresolved local var: float oldmsec@[???] */
    bVar14 = (byte)(int)((float)ucmd->msec * 0.5);
    local_78.msec = bVar14;
    SV_RunCmd(&local_78,random_seed);
    local_78.impulse = '\0';
    local_78.msec = bVar14;
    SV_RunCmd(&local_78,random_seed);
    return;
  }
  if (pcVar13->fakeclient == false) {
    SV_SetupMove(pcVar13);
  }
  (*gEntityInterface.pfnCmdStart)(sv_player,ucmd,random_seed);
  pcVar13 = host_client;
  fVar4 = (float)ucmd->msec * 0.001;
  host_client->svtimebase = (double)(fVar4 + (float)host_client->svtimebase);
  peVar11 = sv_player;
  pcVar13->cmdtime = (double)((float)ucmd->msec / 1000.0 + (float)pcVar13->cmdtime);
  if ((ucmd->impulse != 0) && ((peVar11->v).impulse = (uint)ucmd->impulse, ucmd->impulse == 0xcc)) {
    SV_FullUpdate_Internal();
    peVar11 = sv_player;
  }
  (peVar11->v).clbasevelocity[0] = 0.0;
  (peVar11->v).clbasevelocity[1] = 0.0;
  (peVar11->v).clbasevelocity[2] = 0.0;
  (peVar11->v).button = (uint)ucmd->buttons;
                    /* Unresolved local var: edict_t * groundentity@[???] */
  uVar6 = (peVar11->v).flags;
  if ((((uVar6 & 0x200) != 0) && (peVar9 = (peVar11->v).groundentity, peVar9 != (edict_t *)0x0)) &&
     (((peVar9->v).flags & 4) != 0)) {
    pvVar8 = (peVar11->v).basevelocity;
    if ((uVar6 & 0x400000) == 0) {
      VectorScale((peVar9->v).movedir,(peVar9->v).speed,pvVar8);
    }
    else {
      VectorMA(pvVar8,(peVar9->v).speed,(peVar9->v).movedir,pvVar8);
    }
    uVar6 = (peVar11->v).flags | 0x400000;
    (peVar11->v).flags = uVar6;
  }
  if ((uVar6 & 0x400000) == 0) {
    pvVar8 = (peVar11->v).velocity;
    VectorMA(pvVar8,fVar4 * 0.5 + 1.0,(peVar11->v).basevelocity,pvVar8);
    uVar6 = (peVar11->v).flags;
    (peVar11->v).basevelocity[0] = 0.0;
    (peVar11->v).basevelocity[1] = 0.0;
    (peVar11->v).basevelocity[2] = 0.0;
  }
  ppVar10 = pmove;
  (peVar11->v).flags = uVar6 & 0xffbfffff;
  peVar11 = sv_player;
  ppVar10->oldangles[0] = (sv_player->v).v_angle[0];
  ppVar10->oldangles[1] = (peVar11->v).v_angle[1];
  ppVar10->oldangles[2] = (peVar11->v).v_angle[2];
  if ((peVar11->v).fixangle == 0) {
    (peVar11->v).v_angle[0] = ucmd->viewangles[0];
    (peVar11->v).v_angle[1] = ucmd->viewangles[1];
    (peVar11->v).v_angle[2] = ucmd->viewangles[2];
  }
  gGlobalVariables.time = (float)host_client->svtimebase;
  (*gEntityInterface.pfnPlayerPreThink)(peVar11);
  peVar11 = sv_player;
                    /* Unresolved local var: float thinktime@[???] */
  uVar6 = (sv_player->v).flags;
  uVar12 = uVar6 & 0x40000000;
  if ((uVar12 == 0) && (-1 < (int)uVar6)) {
    fVar16 = (sv_player->v).nextthink;
    if (fVar16 <= 0.0) goto LAB_000a3ca0;
    fVar5 = (float)host_client->svtimebase;
    if (fVar4 + fVar5 < fVar16) goto LAB_000a3ca0;
    gGlobalVariables.time = fVar16;
    if (fVar16 < fVar5) {
      gGlobalVariables.time = (float)host_client->svtimebase;
    }
    (sv_player->v).nextthink = 0.0;
    (*gEntityInterface.pfnThink)(peVar11);
    uVar12 = (peVar11->v).flags & 0x40000000;
  }
  if (uVar12 != 0) {
    ED_Free(peVar11);
  }
LAB_000a3ca0:
  fVar16 = Length((sv_player->v).basevelocity);
  peVar11 = sv_player;
  if (0.0 < fVar16) {
    vVar1 = (sv_player->v).basevelocity[2];
    (sv_player->v).clbasevelocity[0] = (sv_player->v).basevelocity[0];
    vVar2 = (peVar11->v).basevelocity[1];
    (peVar11->v).clbasevelocity[2] = vVar1;
    (peVar11->v).clbasevelocity[1] = vVar2;
  }
  pcVar13 = host_client;
  ppVar10 = pmove;
  pmove->server = true;
  ppVar10->multiplayer = (uint)(1 < svs.maxclients);
  ppVar10->time = (float)pcVar13->svtimebase * 1000.0;
  uVar6 = (peVar11->v).flags;
  ppVar10->maxspeed = sv_maxspeed.value;
  ppVar10->usehull = uVar6 >> 0xe & 1;
  ppVar10->clientmaxspeed = (peVar11->v).maxspeed;
  ppVar10->flDuckTime = (float)(peVar11->v).flDuckTime;
  ppVar10->bInDuck = (peVar11->v).bInDuck;
  ppVar10->flTimeStepSound = (peVar11->v).flTimeStepSound;
  ppVar10->iStepLeft = (peVar11->v).iStepLeft;
  ppVar10->flFallVelocity = (peVar11->v).flFallVelocity;
  ppVar10->flSwimTime = (float)(peVar11->v).flSwimTime;
  ppVar10->oldbuttons = (peVar11->v).oldbuttons;
  Q_strncpy(ppVar10->physinfo,pcVar13->physinfo,0xff);
  peVar11 = sv_player;
  ppVar10 = pmove;
  pmove->physinfo[0xff] = '\0';
  ppVar10->velocity[0] = (peVar11->v).velocity[0];
  ppVar10->velocity[1] = (peVar11->v).velocity[1];
  ppVar10->velocity[2] = (peVar11->v).velocity[2];
  ppVar10->movedir[0] = (peVar11->v).movedir[0];
  ppVar10->movedir[1] = (peVar11->v).movedir[1];
  ppVar10->movedir[2] = (peVar11->v).movedir[2];
  ppVar10->angles[0] = (peVar11->v).v_angle[0];
  ppVar10->angles[1] = (peVar11->v).v_angle[1];
  ppVar10->angles[2] = (peVar11->v).v_angle[2];
  ppVar10->basevelocity[0] = (peVar11->v).basevelocity[0];
  ppVar10->basevelocity[1] = (peVar11->v).basevelocity[1];
  ppVar10->basevelocity[2] = (peVar11->v).basevelocity[2];
  ppVar10->view_ofs[0] = (peVar11->v).view_ofs[0];
  ppVar10->view_ofs[1] = (peVar11->v).view_ofs[1];
  ppVar10->view_ofs[2] = (peVar11->v).view_ofs[2];
  ppVar10->punchangle[0] = (peVar11->v).punchangle[0];
  ppVar10->punchangle[1] = (peVar11->v).punchangle[1];
  ppVar10->punchangle[2] = (peVar11->v).punchangle[2];
  ppVar10->deadflag = (peVar11->v).deadflag;
  ppVar10->effects = (peVar11->v).effects;
  uVar6 = 0;
  ppVar10->gravity = (peVar11->v).gravity;
  fVar16 = (peVar11->v).friction;
  ppVar10->spectator = 0;
  ppVar10->friction = fVar16;
  ppVar10->waterjumptime = (peVar11->v).teleport_time;
  do {
    *(undefined4 *)((int)(ppVar10->cmd).viewangles + (uVar6 - 4)) =
         *(undefined4 *)((int)local_78.viewangles + (uVar6 - 4));
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0x34);
  ppVar10->dead = (uint)((peVar11->v).health <= 0.0);
  ppVar10->movetype = (peVar11->v).movetype;
  ppVar10->flags = (peVar11->v).flags;
  iVar7 = NUM_FOR_EDICT(peVar11);
  ppVar10->player_index = iVar7 + -1;
  peVar11 = sv_player;
  ppVar10 = pmove;
  pvVar8 = pmove->origin;
  pmove->iuser1 = (sv_player->v).iuser1;
  ppVar10->iuser2 = (peVar11->v).iuser2;
  ppVar10->iuser3 = (peVar11->v).iuser3;
  ppVar10->iuser4 = (peVar11->v).iuser4;
  ppVar10->fuser1 = (peVar11->v).fuser1;
  ppVar10->fuser2 = (peVar11->v).fuser2;
  ppVar10->fuser3 = (peVar11->v).fuser3;
  ppVar10->fuser4 = (peVar11->v).fuser4;
  ppVar10->vuser1[0] = (peVar11->v).vuser1[0];
  ppVar10->vuser1[1] = (peVar11->v).vuser1[1];
  ppVar10->vuser1[2] = (peVar11->v).vuser1[2];
  ppVar10->vuser2[0] = (peVar11->v).vuser2[0];
  ppVar10->vuser2[1] = (peVar11->v).vuser2[1];
  ppVar10->vuser2[2] = (peVar11->v).vuser2[2];
  ppVar10->vuser3[0] = (peVar11->v).vuser3[0];
  ppVar10->vuser3[1] = (peVar11->v).vuser3[1];
  ppVar10->vuser3[2] = (peVar11->v).vuser3[2];
  ppVar10->vuser4[0] = (peVar11->v).vuser4[0];
  ppVar10->vuser4[1] = (peVar11->v).vuser4[1];
  ppVar10->vuser4[2] = (peVar11->v).vuser4[2];
  *pvVar8 = (peVar11->v).origin[0];
  ppVar10->origin[1] = (peVar11->v).origin[1];
  ppVar10->origin[2] = (peVar11->v).origin[2];
  SV_AddLinksToPM(sv_areanodes,pvVar8);
  ppVar10 = pmove;
  pmove->frametime = fVar4;
  ppVar10->runfuncs = true;
  ppVar10->PM_PlaySound = PM_SV_PlaySound;
  ppVar10->PM_TraceTexture = PM_SV_TraceTexture;
  ppVar10->PM_PlaybackEventFull = PM_SV_PlaybackEventFull;
  (*gEntityInterface.pfnPM_Move)(ppVar10,true);
  peVar11 = sv_player;
  ppVar10 = pmove;
  (sv_player->v).deadflag = pmove->deadflag;
  (peVar11->v).effects = ppVar10->effects;
  (peVar11->v).teleport_time = ppVar10->waterjumptime;
  (peVar11->v).waterlevel = ppVar10->waterlevel;
  (peVar11->v).watertype = ppVar10->watertype;
  uVar6 = ppVar10->flags;
  (peVar11->v).flags = uVar6;
  (peVar11->v).friction = ppVar10->friction;
  (peVar11->v).movetype = ppVar10->movetype;
  (peVar11->v).maxspeed = ppVar10->clientmaxspeed;
  (peVar11->v).iStepLeft = ppVar10->iStepLeft;
  (peVar11->v).view_ofs[0] = ppVar10->view_ofs[0];
  (peVar11->v).view_ofs[1] = ppVar10->view_ofs[1];
  (peVar11->v).view_ofs[2] = ppVar10->view_ofs[2];
  (peVar11->v).movedir[0] = ppVar10->movedir[0];
  (peVar11->v).movedir[1] = ppVar10->movedir[1];
  (peVar11->v).movedir[2] = ppVar10->movedir[2];
  (peVar11->v).punchangle[0] = ppVar10->punchangle[0];
  (peVar11->v).punchangle[1] = ppVar10->punchangle[1];
  (peVar11->v).punchangle[2] = ppVar10->punchangle[2];
  if (ppVar10->onground == -1) {
    (peVar11->v).flags = uVar6 & 0xfffffdff;
  }
  else {
    (peVar11->v).flags = uVar6 | 0x200;
    peVar9 = EDICT_NUM(ppVar10->physents[ppVar10->onground].info);
    (peVar11->v).groundentity = peVar9;
    ppVar10 = pmove;
    peVar11 = sv_player;
  }
  iVar7 = (peVar11->v).fixangle;
  (peVar11->v).origin[0] = ppVar10->origin[0];
  (peVar11->v).origin[1] = ppVar10->origin[1];
  (peVar11->v).origin[2] = ppVar10->origin[2];
  (peVar11->v).velocity[0] = ppVar10->velocity[0];
  (peVar11->v).velocity[1] = ppVar10->velocity[1];
  (peVar11->v).velocity[2] = ppVar10->velocity[2];
  (peVar11->v).basevelocity[0] = ppVar10->basevelocity[0];
  (peVar11->v).basevelocity[1] = ppVar10->basevelocity[1];
  (peVar11->v).basevelocity[2] = ppVar10->basevelocity[2];
  if (iVar7 == 0) {
    (peVar11->v).v_angle[0] = ppVar10->angles[0];
    (peVar11->v).v_angle[1] = ppVar10->angles[1];
    (peVar11->v).v_angle[2] = ppVar10->angles[2];
    (peVar11->v).angles[0] = ppVar10->angles[0];
    (peVar11->v).angles[1] = ppVar10->angles[1];
    (peVar11->v).angles[2] = ppVar10->angles[2];
    (peVar11->v).angles[0] = -ppVar10->angles[0] / 3.0;
  }
  (peVar11->v).bInDuck = ppVar10->bInDuck;
  (peVar11->v).flDuckTime = (int)ppVar10->flDuckTime;
  (peVar11->v).flTimeStepSound = ppVar10->flTimeStepSound;
  (peVar11->v).flFallVelocity = ppVar10->flFallVelocity;
  (peVar11->v).flSwimTime = (int)ppVar10->flSwimTime;
  (peVar11->v).oldbuttons = (uint)(ppVar10->cmd).buttons;
  (peVar11->v).iuser1 = ppVar10->iuser1;
  (peVar11->v).iuser2 = ppVar10->iuser2;
  (peVar11->v).iuser3 = ppVar10->iuser3;
  (peVar11->v).iuser4 = ppVar10->iuser4;
  (peVar11->v).fuser1 = ppVar10->fuser1;
  (peVar11->v).fuser2 = ppVar10->fuser2;
  (peVar11->v).fuser3 = ppVar10->fuser3;
  (peVar11->v).fuser4 = ppVar10->fuser4;
  (peVar11->v).vuser1[0] = ppVar10->vuser1[0];
  (peVar11->v).vuser1[1] = ppVar10->vuser1[1];
  (peVar11->v).vuser1[2] = ppVar10->vuser1[2];
  (peVar11->v).vuser2[0] = ppVar10->vuser2[0];
  (peVar11->v).vuser2[1] = ppVar10->vuser2[1];
  (peVar11->v).vuser2[2] = ppVar10->vuser2[2];
  (peVar11->v).vuser3[0] = ppVar10->vuser3[0];
  (peVar11->v).vuser3[1] = ppVar10->vuser3[1];
  (peVar11->v).vuser3[2] = ppVar10->vuser3[2];
  (peVar11->v).vuser4[0] = ppVar10->vuser4[0];
  (peVar11->v).vuser4[1] = ppVar10->vuser4[1];
  (peVar11->v).vuser4[2] = ppVar10->vuser4[2];
  SetMinMaxSize(peVar11,player_mins[ppVar10->usehull],player_maxs[ppVar10->usehull],false);
  peVar11 = sv_player;
  pcVar13 = host_client;
  if ((host_client->edict->v).solid != 0) {
                    /* Unresolved local var: vec3_t vel@[???]
                       Unresolved local var: pmtrace_t * tr@[???] */
    SV_LinkEdict(sv_player,true);
    vVar1 = (sv_player->v).velocity[0];
    vVar2 = (sv_player->v).velocity[1];
    vVar3 = (sv_player->v).velocity[2];
    if (0 < pmove->numtouch) {
      iVar7 = 0;
      do {
        iVar15 = iVar7 + 1;
        local_44.ent = EDICT_NUM(pmove->physents[pmove->touchindex[iVar7].ent].info);
        peVar11 = sv_player;
        pvVar8 = pmove->forward + iVar7 * 0x11 + -5;
        local_44.allsolid = *(qboolean *)(CL_ShutDownClientStatic + (int)pvVar8);
        local_44.fraction = *(float *)(ClientDLL_MoveClient + (int)pvVar8);
        local_44.endpos[0] = *(vec_t *)(&DAT_000454a4 + (int)pvVar8);
        local_44.endpos[1] = *(vec_t *)(&DAT_000454a8 + (int)pvVar8);
        local_44.startsolid = *(qboolean *)(&DAT_00045494 + (int)pvVar8);
        local_44.endpos[2] = *(vec_t *)(&DAT_000454ac + (int)pvVar8);
        local_44.inopen = *(qboolean *)(&DAT_00045498 + (int)pvVar8);
        local_44.plane.normal[0] = *(vec_t *)(CL_Shutdown + (int)pvVar8);
        local_44.plane.normal[1] = *(vec_t *)(&DAT_000454b4 + (int)pvVar8);
        local_44.plane.normal[2] = *(vec_t *)(&DAT_000454b8 + (int)pvVar8);
        local_44.inwater = *(qboolean *)(&DAT_0004549c + (int)pvVar8);
        local_44.plane.dist = *(float *)(&DAT_000454bc + (int)pvVar8);
        local_44.hitgroup = *(int *)(ClientDLL_CAM_Think + (int)pvVar8);
        (sv_player->v).velocity[0] = *(vec_t *)(&DAT_000454c4 + (int)pvVar8);
        (peVar11->v).velocity[1] = *(vec_t *)(&DAT_000454c8 + (int)pvVar8);
        (peVar11->v).velocity[2] = *(vec_t *)(&DAT_000454cc + (int)pvVar8);
        SV_Impact(local_44.ent,peVar11,&local_44);
        iVar7 = iVar15;
      } while (iVar15 < pmove->numtouch);
    }
    peVar11 = sv_player;
    (sv_player->v).velocity[0] = vVar1;
    pcVar13 = host_client;
    (peVar11->v).velocity[1] = vVar2;
    (peVar11->v).velocity[2] = vVar3;
  }
  gGlobalVariables.time = (float)pcVar13->svtimebase;
  gGlobalVariables.frametime = fVar4;
  (*gEntityInterface.pfnPlayerPostThink)(peVar11);
  (*gEntityInterface.pfnCmdEnd)(sv_player);
  if (host_client->fakeclient != false) {
    return;
  }
  SV_RestoreMove(host_client);
  return;
}


// SV_RunMapChangeConfig  @ 0008e910
void SV_RunMapChangeConfig(char *pszLevel)

{
  size_t sVar1;
  int in_GS_OFFSET;
  char acStack_110 [256];
  int iStack_10;
  
  iStack_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (mapchangecfgfile.string != (char *)0x0) {
    sVar1 = strlen(mapchangecfgfile.string);
    if (2 < sVar1) {
      AlertMessage(at_console,"Executing map change config file\n");
      __snprintf_chk(acStack_110,0x100,1,0x100,"exec %s\n",mapchangecfgfile.string);
      Cbuf_AddText(acStack_110);
    }
  }
  if (pszLevel != (char *)0x0) {
    sVar1 = strlen(pszLevel);
    if (2 < sVar1) {
      __snprintf_chk(acStack_110,0x100,1,0x100,"exec maps/%s_load.cfg\n",pszLevel);
      Cbuf_AddText(acStack_110);
    }
  }
  if (iStack_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_RunThink  @ 000994e0
qboolean SV_RunThink(edict_t *ent)

{
  longdouble lVar1;
  
                    /* Unresolved local var: float thinktime@[???] */
  if (((ent->v).flags & 0x40000000) == 0) {
    lVar1 = (longdouble)(ent->v).nextthink;
    if (lVar1 <= (longdouble)0) {
      return true;
    }
    if ((longdouble)host_frametime + (longdouble)sv.time < lVar1) {
      return true;
    }
    if (lVar1 < (longdouble)sv.time) {
      lVar1 = (longdouble)(float)sv.time;
    }
    (ent->v).nextthink = 0.0;
    gGlobalVariables.time = (float)lVar1;
    (*gEntityInterface.pfnThink)(ent);
    if (((ent->v).flags & 0x40000000) == 0) goto LAB_000994f9;
  }
  ED_Free(ent);
LAB_000994f9:
  return (uint)(ent->free == false);
}


// SV_SendBan  @ 000893a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SendBan(void)

{
  netadr_t to;
  uint uVar1;
  int in_GS_OFFSET;
  char local_50 [64];
  int local_10;
  
                    /* Unresolved local var: char[64] szMessage@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = 0;
  do {
    *(undefined4 *)(local_50 + uVar1) =
         *(undefined4 *)("You have been banned from this server.\n" + uVar1);
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x28);
  SZ_Clear(&net_message);
  MSG_WriteLong(&net_message,-1);
  MSG_WriteByte(&net_message,0x6c);
  MSG_WriteString(&net_message,local_50);
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
  NET_SendPacket(NS_SERVER,net_message.cursize,net_message.data,to);
  SZ_Clear(&net_message);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_SendClientDatagram  @ 0008c450
qboolean SV_SendClientDatagram(client_t *client)

{
  int in_GS_OFFSET;
  sizebuf_t local_1794;
  byte local_1780 [6000];
  int local_10;
  
                    /* Unresolved local var: byte[6000] buf@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_1794.buffername = "Client Datagram";
  local_1794.maxsize = 6000;
  local_1794.cursize = 0;
  local_1794.flags = 1;
  local_1794.data = local_1780;
  MSG_WriteByte(&local_1794,7);
  MSG_WriteFloat(&local_1794,(float)sv.time);
  SV_WriteClientdataToMessage(client,&local_1794);
  SV_WriteEntitiesToClient(client,&local_1794);
  if (((client->datagram).flags & 2) == 0) {
    SZ_Write(&local_1794,(client->datagram).data,(client->datagram).cursize);
  }
  else {
    Con_Printf("WARNING: datagram overflowed for %s\n",client->name);
  }
  SZ_Clear(&client->datagram);
  if ((local_1794.flags & 2) != 0) {
    Con_Printf("WARNING: msg overflowed for %s\n",client->name);
    SZ_Clear(&local_1794);
  }
  Netchan_Transmit(&client->netchan,local_1794.cursize,local_1780);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return true;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_SendClientMessages  @ 0008d070
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SendClientMessages(void)

{
  uint *puVar1;
  double dVar2;
  qboolean *pqVar3;
  client_t *pcVar4;
  qboolean qVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int i@[???] */
  iVar7 = 0;
  SV_UpdateToReliableMessages();
  host_client = svs.clients;
  iVar6 = svs.maxclients;
  if (0 < svs.maxclients) {
    do {
      while ((((pcVar4 = host_client, pqVar3 = &host_client->active, *pqVar3 == false &&
               (host_client->connected == false)) && (host_client->spawned == false)) ||
             (host_client->fakeclient != false))) {
LAB_0008d0a0:
        iVar7 = iVar7 + 1;
        host_client = pcVar4 + 1;
        if (iVar6 <= iVar7) goto LAB_0008d190;
      }
      if (host_client->skip_message != false) {
        host_client->skip_message = false;
        goto LAB_0008d0a0;
      }
      if ((host_limitlocal.value == 0.0) &&
         ((host_client->netchan).remote_address.type == NA_LOOPBACK)) {
                    /* try { // try from 0008d325 to 0009d329 has its CatchHandler @ 0008d280 */
        host_client->send_message = true;
                    /* catch() { ... } // from try @ 0008d2fb with catch @ 0008d32a */
      }
                    /* try { // try from 0008d2fb to 0009d2ff has its CatchHandler @ 0008d32a */
      if (((*pqVar3 != false) && (pcVar4->spawned != false)) &&
         ((pcVar4->fully_connected != false &&
          (pcVar4->next_messagetime <= realtime + host_frametime)))) {
                    /* catch() { ... } // from try @ 0008d2be with catch @ 0008d314 */
        pcVar4->send_message = true;
      }
      if (((pcVar4->netchan).message.flags & 2) == 0) {
        if (pcVar4->send_message != false) {
          if (realtime - (double)(pcVar4->netchan).last_received <= (double)sv_failuretime.value) {
            qVar5 = Netchan_CanPacket(&pcVar4->netchan);
            pcVar4 = host_client;
            iVar6 = svs.maxclients;
            goto joined_r0x0008d270;
          }
          pcVar4->send_message = false;
        }
        goto LAB_0008d0a0;
      }
      SZ_Clear(&(pcVar4->netchan).message);
      SZ_Clear(&host_client->datagram);
      SV_BroadcastPrintf("%s overflowed\n",host_client->name);
      Con_Printf("WARNING: reliable overflow for %s\n",host_client->name);
      SV_DropClient(host_client,false,"Reliable channel overflowed");
      pcVar4 = host_client;
      host_client->send_message = true;
      *(undefined4 *)&(pcVar4->netchan).cleartime = 0;
      *(undefined4 *)((int)&(pcVar4->netchan).cleartime + 4) = 0;
      qVar5 = Netchan_CanPacket(&pcVar4->netchan);
      pcVar4 = host_client;
      iVar6 = svs.maxclients;
joined_r0x0008d270:
      svs.maxclients = iVar6;
      if (qVar5 != false) {
                    /* catch() { ... } // from try @ 0008d325 with catch @ 0008d280 */
        dVar2 = realtime + host_frametime;
        host_client = pcVar4;
        pcVar4->send_message = false;
        pcVar4->next_messagetime = dVar2 + pcVar4->next_messageinterval;
        if (((pcVar4->active == false) || (pcVar4->spawned == false)) ||
           (pcVar4->fully_connected == false)) {
                    /* try { // try from 0008d2be to 0009d2c2 has its CatchHandler @ 0008d314 */
          Netchan_Transmit(&pcVar4->netchan,0,(byte *)0x0);
          pcVar4 = host_client;
          iVar6 = svs.maxclients;
        }
        else {
          SV_SendClientDatagram(pcVar4);
          pcVar4 = host_client;
          iVar6 = svs.maxclients;
        }
        goto LAB_0008d0a0;
      }
      iVar7 = iVar7 + 1;
      pcVar4->chokecount = pcVar4->chokecount + 1;
      host_client = pcVar4 + 1;
    } while (iVar7 < iVar6);
  }
LAB_0008d190:
                    /* Unresolved local var: int e@[???]
                       Unresolved local var: edict_t * ent@[???] */
  iVar6 = 0x324;
  iVar7 = 1;
  if (1 < sv.num_edicts) {
    do {
      iVar7 = iVar7 + 1;
      puVar1 = (uint *)((int)((sv.edicts)->v).size + iVar6 + 0x24);
      *puVar1 = *puVar1 & 0xffffffdd;
      iVar6 = iVar6 + 0x324;
    } while (iVar7 < sv.num_edicts);
  }
  return;
}


// SV_SendConsistencyList  @ 000a08a0
void SV_SendConsistencyList(sizebuf_t *msg)

{
  client_t *pcVar1;
  int iVar2;
  uint32 uVar3;
  int iVar4;
  uint32 data;
  bool bVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * r@[???]
                       Unresolved local var: int lastcheck@[???]
                       Unresolved local var: int delta@[DW_OP_reg7(EDI)] */
  pcVar1 = host_client;
  bVar5 = svs.maxclients != 1;
  host_client->has_force_unmodified = false;
  if ((((bVar5) && (mp_consistency.value != 0.0)) && (sv.num_consistency != 0)) &&
     (pcVar1->proxy == false)) {
    pcVar1->has_force_unmodified = true;
    MSG_WriteBits(1,1);
    if (0 < sv.num_resources) {
      iVar4 = 0x4ff3c0;
      uVar3 = 0;
      data = 0;
      iVar2 = sv.num_resources;
      do {
        if ((iVar4 != 0) && (*(char *)(iVar4 + 0x4c) < '\0')) {
          MSG_WriteBits(1,1);
          if ((int)(data - uVar3) < 0x20) {
            MSG_WriteBits(1,1);
            MSG_WriteBits(data - uVar3,5);
            iVar2 = sv.num_resources;
            uVar3 = data;
          }
          else {
            MSG_WriteBits(0,1);
            MSG_WriteBits(data,10);
            iVar2 = sv.num_resources;
            uVar3 = data;
          }
        }
        data = data + 1;
        iVar4 = iVar4 + 0x88;
      } while ((int)data < iVar2);
    }
  }
  MSG_WriteBits(0,1);
  return;
}


// SV_SendEnts_f  @ 000a3730
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SendEnts_f(void)

{
  if (cmd_source != src_command) {
    if (((host_client->active != false) && (host_client->spawned != false)) &&
       (host_client->connected != false)) {
      host_client->fully_connected = true;
    }
    return;
  }
  Cmd_ForwardToServer();
  return;
}


// SV_SendRes_f  @ 000844c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SendRes_f(void)

{
  int iVar1;
  int in_GS_OFFSET;
  sizebuf_t sStack_10024;
  byte abStack_10010 [65548];
  
                    /* Unresolved local var: uchar[65536] data@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&sStack_10024,0,0x14);
  sStack_10024.buffername = "SendResources";
  sStack_10024.data = abStack_10010;
  sStack_10024.cursize = 0;
  sStack_10024.maxsize = 0x10000;
  if (((cmd_source != src_command) &&
      ((host_client->spawned == false || (host_client->active != false)))) &&
     ((svs.maxclients < 2 || (host_client->m_sendrescount < 2)))) {
    host_client->m_sendrescount = host_client->m_sendrescount + 1;
    SV_SendResources(&sStack_10024);
    Netchan_CreateFragments(true,&host_client->netchan,&sStack_10024);
    Netchan_FragSend(&host_client->netchan);
  }
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_SendResources  @ 00084290
void SV_SendResources(sizebuf_t *msg)

{
  uchar *m1;
  int iVar1;
  size_t sVar2;
  int iVar3;
  resource_t *p;
  int in_GS_OFFSET;
  undefined1 local_40 [32];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: byte[32] nullbuffer@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_40,0,0x20);
  MSG_WriteByte(msg,0x2d);
  MSG_WriteLong(msg,svs.spawncount);
  MSG_WriteLong(msg,0);
  if ((sv_downloadurl.string != (char *)0x0) && (*sv_downloadurl.string != '\0')) {
    sVar2 = strlen(sv_downloadurl.string);
    if (sVar2 < 0x80) {
      MSG_WriteByte(msg,0x38);
      MSG_WriteString(msg,sv_downloadurl.string);
    }
  }
  MSG_WriteByte(msg,0x2b);
  MSG_StartBitWriting(msg);
  MSG_WriteBits(sv.num_resources,0xc);
  if (0 < sv.num_resources) {
    p = sv.resourcelist;
    iVar3 = 0;
    do {
      while( true ) {
        MSG_WriteBits(p->type,4);
        MSG_WriteBitString(p->szFileName);
        MSG_WriteBits(p->nIndex,0xc);
        MSG_WriteBits(p->nDownloadSize,0x18);
        MSG_WriteBits(p->ucFlags & 3,3);
        if ((p->ucFlags & 4) != 0) {
          MSG_WriteBitData(p->rgucMD5_hash,0x10);
        }
        m1 = p->rguc_reserved;
        iVar1 = Q_memcmp(m1,local_40,0x20);
        if (iVar1 != 0) break;
        iVar3 = iVar3 + 1;
        p = p + 1;
        MSG_WriteBits(0,1);
        if (sv.num_resources <= iVar3) goto LAB_00084432;
      }
      iVar3 = iVar3 + 1;
      p = p + 1;
      MSG_WriteBits(1,1);
      MSG_WriteBitData(m1,0x20);
    } while (iVar3 < sv.num_resources);
  }
LAB_00084432:
  SV_SendConsistencyList(msg);
  MSG_EndBitWriting(msg);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_SendServerinfo  @ 000838b0
void SV_SendServerinfo(sizebuf_t *msg,client_t *client)

{
  uint32 data;
  delta_info_s *pdVar1;
  int iVar2;
  int iVar3;
  char *s;
  byte *s_00;
  uint c;
  uint32 uVar4;
  int in_GS_OFFSET;
  CRC32_t local_868;
  uchar local_864 [68];
  char local_820 [2048];
  int local_20;
  
                    /* Unresolved local var: char[2048] message@[???]
                       Unresolved local var: int ffirstsent@[???]
                       Unresolved local var: int playernum@[???]
                       Unresolved local var: char * mapcyclelist@[???]
                       Unresolved local var: int len@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((developer.value != 0.0) || (1 < svs.maxclients)) {
    MSG_WriteByte(msg,8);
    iVar3 = svs.spawncount;
    iVar2 = build_number();
    __snprintf_chk(local_820,0x800,1,0x800,"%c\nBUILD %d SERVER (%i CRC)\nServer # %i\n",2,iVar2,0,
                   iVar3);
    MSG_WriteString(msg,local_820);
  }
                    /* Unresolved local var: int mungebuffer@[???] */
  MSG_WriteByte(msg,0xb);
  MSG_WriteLong(msg,0x30);
  MSG_WriteLong(msg,svs.spawncount);
  iVar3 = NUM_FOR_EDICT(client->edict);
  local_868 = sv.worldmapCRC;
  COM_Munge3((uchar *)&local_868,4,(uint)(byte)~(byte)(iVar3 + -1));
  MSG_WriteLong(msg,local_868);
  MSG_WriteBuf(msg,0x10,sv.clientdllmd5);
  MSG_WriteByte(msg,svs.maxclients);
  MSG_WriteByte(msg,iVar3 + -1);
  if ((coop.value == 0.0) && (deathmatch.value != 0.0)) {
    MSG_WriteByte(msg,1);
  }
  else {
    MSG_WriteByte(msg,0);
  }
  COM_FileBase(com_gamedir,local_820);
  MSG_WriteString(msg,local_820);
  s = Cvar_VariableString("hostname");
  MSG_WriteString(msg,s);
  MSG_WriteString(msg,sv.modelname);
  s_00 = COM_LoadFileForMe(mapcyclefile.string,(int *)&local_868);
  if ((s_00 == (byte *)0x0) || (local_868 == 0)) {
    MSG_WriteString(msg,"mapcycle failure");
  }
  else {
    if (0x2000 < (int)local_868) {
      local_868 = 0x2000;
      s_00[0x1fff] = '\0';
    }
    MSG_WriteString(msg,(char *)s_00);
    COM_FreeFile(s_00);
  }
  MSG_WriteByte(msg,0);
  MSG_WriteByte(msg,0x36);
  MSG_WriteString(msg,com_clientfallback);
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: delta_info_t * p@[???]
                       Unresolved local var: delta_description_t nulldesc@[???]
                       Unresolved local var: delta_description_t * from@[???]
                       Unresolved local var: delta_description_t * to@[???] */
  c = (uint)NAN(sv_cheats.value);
  if (sv_cheats.value != 0.0) {
    c = 1;
  }
  MSG_WriteByte(msg,c);
  Q_memset(local_864,0,0x44);
  for (pdVar1 = g_sv_delta; pdVar1 != (delta_info_t *)0x0; pdVar1 = pdVar1->next) {
    MSG_WriteByte(msg,0xe);
    MSG_WriteString(msg,pdVar1->name);
    data = pdVar1->delta->fieldCount;
    MSG_StartBitWriting(msg);
    uVar4 = 0;
    MSG_WriteBits(data,0x10);
    if (0 < (int)data) {
      iVar3 = 0;
      do {
        uVar4 = uVar4 + 1;
        iVar2 = iVar3 + -4;
        iVar3 = iVar3 + 0x44;
        DELTA_WriteDelta(local_864,(uchar *)(pdVar1->delta->pdd->fieldName + iVar2),true,
                         &g_MetaDelta,(_func_void *)0x0);
      } while (data != uVar4);
    }
    MSG_EndBitWriting(msg);
  }
  SV_SetMoveVars();
  SV_WriteMovevarsToClient(msg);
  MSG_WriteByte(msg,0x20);
  MSG_WriteByte(msg,gGlobalVariables.cdAudioTrack);
  MSG_WriteByte(msg,gGlobalVariables.cdAudioTrack);
  MSG_WriteByte(msg,5);
  iVar3 = NUM_FOR_EDICT(client->edict);
  MSG_WriteShort(msg,iVar3);
  iVar3 = *(int *)(in_GS_OFFSET + 0x14);
  client->spawned = false;
  client->connected = true;
  client->fully_connected = false;
  if (local_20 != iVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_SendUserReg  @ 00085090
void SV_SendUserReg(sizebuf_t *msg)

{
  _UserMsg *p_Var1;
  
  for (p_Var1 = sv_gpNewUserMsgs; p_Var1 != (UserMsg *)0x0; p_Var1 = p_Var1->next) {
                    /* Unresolved local var: UserMsg * pMsg@[???] */
    MSG_WriteByte(msg,0x27);
    MSG_WriteByte(msg,p_Var1->iMsg);
    MSG_WriteByte(msg,p_Var1->iSize);
    MSG_WriteLong(msg,*(int *)p_Var1->szName);
    MSG_WriteLong(msg,*(int *)(p_Var1->szName + 4));
    MSG_WriteLong(msg,*(int *)(p_Var1->szName + 8));
    MSG_WriteLong(msg,*(int *)(p_Var1->szName + 0xc));
  }
  return;
}


// SV_ServerLog_f  @ 00080260
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ServerLog_f(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = Cmd_Argc();
  if (iVar1 == 2) {
    pcVar2 = Cmd_Argv(1);
    iVar1 = Q_stricmp(pcVar2,"off");
    if (iVar1 == 0) {
      if (svs.log.active != false) {
        if (svs.log.file != (void *)0x0) {
          Log_Printf("Log file closed\n");
          FS_Close(svs.log.file);
          svs.log.file = (void *)0x0;
        }
        Con_Printf("Server logging disabled.\n");
        svs.log.active = false;
        return;
      }
    }
    else {
      pcVar2 = Cmd_Argv(1);
      iVar1 = Q_stricmp(pcVar2,"on");
      if (iVar1 == 0) {
        svs.log.active = true;
        Log_Open();
        return;
      }
      pcVar2 = Cmd_Argv(1);
      Con_Printf("log:  unknown parameter %s, \'on\' and \'off\' are valid\n",pcVar2);
    }
  }
  else {
    Con_Printf("usage:  log < on | off >\n");
    if (svs.log.active != false) {
      Con_Printf("currently logging\n");
      return;
    }
    Con_Printf("not currently logging\n");
  }
  return;
}


// SV_ServerShutdown  @ 0008ef20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ServerShutdown(void)

{
  byte bVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  int in_GS_OFFSET;
  char local_110 [256];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((disconcfgfile.string != (char *)0x0) && (sVar2 = strlen(disconcfgfile.string), 2 < sVar2)) {
                    /* Unresolved local var: char[256] szCommand@[???] */
    AlertMessage(at_console,"Executing disconnect config file\n");
    __snprintf_chk(local_110,0x100,1,0x100,"exec %s\n",disconcfgfile.string);
    Cbuf_AddText(local_110);
  }
  pcVar6 = sv.name;
  do {
    pcVar5 = pcVar6;
    uVar3 = *(uint *)pcVar5 + 0xfefefeff & ~*(uint *)pcVar5;
    uVar4 = uVar3 & 0x80808080;
    pcVar6 = pcVar5 + 4;
  } while (uVar4 == 0);
  bVar1 = (byte)uVar4;
  if ((uVar3 & 0x8080) == 0) {
    bVar1 = (byte)(uVar4 >> 0x10);
    pcVar6 = pcVar5 + 6;
  }
  if ((char *)0x2 < pcVar6 + (-0x4ff2ab - (uint)CARRY1(bVar1,bVar1))) {
                    /* Unresolved local var: char[256] szCommand@[???] */
    __snprintf_chk(local_110,0x100,1,0x100,"exec maps/%s_unload.cfg\n",0x4ff2a8);
    Cbuf_AddText(local_110);
  }
  Steam_NotifyOfLevelChange();
  gGlobalVariables.time = (float)sv.time;
  if ((svs.dll_initialized != false) && (sv.active != false)) {
    (*gEntityInterface.pfnServerDeactivate)();
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_Serverinfo_f  @ 0008e4f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Serverinfo_f(void)

{
  int iVar1;
  char *pcVar2;
  char *key;
  char *s;
  cvar_t *pcVar3;
  float fVar4;
  
                    /* Unresolved local var: cvar_t * var@[???] */
  iVar1 = Cmd_Argc();
  if (iVar1 == 1) {
    Con_Printf("Server info settings:\n");
    pcVar2 = Info_Serverinfo();
    Info_Print(pcVar2);
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    pcVar2 = Cmd_Argv(1);
    if (*pcVar2 != '*') {
                    /* Unresolved local var: cvar_t * var@[???] */
      pcVar2 = Cmd_Argv(2);
      key = Cmd_Argv(1);
      s = Info_Serverinfo();
      Info_SetValueForKey(s,key,pcVar2,0x200);
      pcVar2 = Cmd_Argv(1);
      pcVar3 = Cvar_FindVar(pcVar2);
      if (pcVar3 != (cvar_t *)0x0) {
        Z_Free(pcVar3->string);
        pcVar2 = Cmd_Argv(2);
        pcVar2 = CopyString(pcVar2);
        pcVar3->string = pcVar2;
        fVar4 = Q_atof(pcVar2);
        pcVar3->value = fVar4;
      }
      pcVar2 = Info_Serverinfo();
      SV_BroadcastCommand("fullserverinfo \"%s\"\n",pcVar2);
      return;
    }
    Con_Printf("Star variables cannot be changed.\n");
  }
  else {
    Con_Printf("usage: serverinfo [ <key> <value> ]\n");
  }
  return;
}


// SV_SetCallback  @ 0008a8f0
void SV_SetCallback(int num,qboolean remove,qboolean custom,int *numbase,qboolean full,int offset)

{
  g_svdeltacallback.newblindex = 0;
  g_svdeltacallback.num = num;
  g_svdeltacallback.remove = remove;
  g_svdeltacallback.custom = custom;
  g_svdeltacallback.numbase = numbase;
  g_svdeltacallback.newbl = false;
  g_svdeltacallback.full = full;
  g_svdeltacallback.offset = offset;
  return;
}


// SV_SetGlobalTrace  @ 0006ef70
void SV_SetGlobalTrace(trace_t *ptrace)

{
  gGlobalVariables.trace_allsolid = (float)ptrace->allsolid;
  gGlobalVariables.trace_startsolid = (float)ptrace->startsolid;
  gGlobalVariables.trace_fraction = ptrace->fraction;
  gGlobalVariables.trace_inwater = (float)ptrace->inwater;
  gGlobalVariables.trace_inopen = (float)ptrace->inopen;
  gGlobalVariables.trace_endpos[0] = ptrace->endpos[0];
  gGlobalVariables.trace_endpos[1] = ptrace->endpos[1];
  gGlobalVariables.trace_endpos[2] = ptrace->endpos[2];
  gGlobalVariables.trace_plane_normal[0] = (ptrace->plane).normal[0];
  gGlobalVariables.trace_plane_normal[1] = (ptrace->plane).normal[1];
  gGlobalVariables.trace_plane_normal[2] = (ptrace->plane).normal[2];
  gGlobalVariables.trace_plane_dist = (ptrace->plane).dist;
  gGlobalVariables.trace_ent = ptrace->ent;
  if (ptrace->ent == (edict_t *)0x0) {
    gGlobalVariables.trace_ent = sv.edicts;
  }
  gGlobalVariables.trace_hitgroup = ptrace->hitgroup;
  return;
}


// SV_SetLogAddress_f  @ 0007fbd0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SetLogAddress_f(void)

{
  netadr_t a;
  netadr_t a_00;
  int iVar1;
  char *str;
  char *pcVar2;
  qboolean qVar3;
  int in_GS_OFFSET;
  netadr_t local_128;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char * s@[???]
                       Unresolved local var: int nPort@[???]
                       Unresolved local var: char[260] szAdr@[???]
                       Unresolved local var: netadr_t adr@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = Cmd_Argc();
  if (iVar1 == 3) {
    pcVar2 = Cmd_Argv(1);
    str = Cmd_Argv(2);
    iVar1 = Q_atoi(str);
    if (iVar1 == 0) {
      Con_Printf("logaddress:  must specify a valid port\n");
    }
    else if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
      Con_Printf("logaddress:  unparseable address\n");
    }
    else {
      __snprintf_chk(local_114,0x104,1,0x104,"%s:%i",pcVar2,iVar1);
      qVar3 = NET_StringToAdr(local_114,&local_128);
      if (qVar3 == false) {
        Con_Printf("logaddress:  unable to resolve %s\n",local_114);
      }
      else {
        svs.log.net_log = true;
        svs.log.net_address.type = local_128.type;
        svs.log.net_address.ip[0] = local_128.ip[0];
        svs.log.net_address.ip[1] = local_128.ip[1];
        svs.log.net_address.ip[2] = local_128.ip[2];
        svs.log.net_address.ip[3] = local_128.ip[3];
        svs.log.net_address.ipx[0] = local_128.ipx[0];
        svs.log.net_address.ipx[1] = local_128.ipx[1];
        svs.log.net_address.ipx[2] = local_128.ipx[2];
        svs.log.net_address.ipx[3] = local_128.ipx[3];
        svs.log.net_address.ipx[4] = local_128.ipx[4];
        svs.log.net_address.ipx[5] = local_128.ipx[5];
        svs.log.net_address.ipx[6] = local_128.ipx[6];
        svs.log.net_address.ipx[7] = local_128.ipx[7];
        svs.log.net_address.ipx[8] = local_128.ipx[8];
        svs.log.net_address.ipx[9] = local_128.ipx[9];
        svs.log.net_address.port = local_128.port;
        a_00.ip[0] = local_128.ip[0];
        a_00.ip[1] = local_128.ip[1];
        a_00.ip[2] = local_128.ip[2];
        a_00.ip[3] = local_128.ip[3];
        a_00.type = local_128.type;
        a_00.ipx[0] = local_128.ipx[0];
        a_00.ipx[1] = local_128.ipx[1];
        a_00.ipx[2] = local_128.ipx[2];
        a_00.ipx[3] = local_128.ipx[3];
        a_00.ipx[4] = local_128.ipx[4];
        a_00.ipx[5] = local_128.ipx[5];
        a_00.ipx[6] = local_128.ipx[6];
        a_00.ipx[7] = local_128.ipx[7];
        a_00.ipx[8] = local_128.ipx[8];
        a_00.ipx[9] = local_128.ipx[9];
        a_00.port = local_128.port;
        pcVar2 = NET_AdrToString(a_00);
        Con_Printf("logaddress:  %s\n",pcVar2);
      }
    }
  }
  else {
    Con_Printf("logaddress:  usage\nlogaddress ip port\n");
    if (svs.log.active != false) {
      a.ip[0] = svs.log.net_address.ip[0];
      a.ip[1] = svs.log.net_address.ip[1];
      a.ip[2] = svs.log.net_address.ip[2];
      a.ip[3] = svs.log.net_address.ip[3];
      a.type = svs.log.net_address.type;
      a.ipx[0] = svs.log.net_address.ipx[0];
      a.ipx[1] = svs.log.net_address.ipx[1];
      a.ipx[2] = svs.log.net_address.ipx[2];
      a.ipx[3] = svs.log.net_address.ipx[3];
      a.ipx[4] = svs.log.net_address.ipx[4];
      a.ipx[5] = svs.log.net_address.ipx[5];
      a.ipx[6] = svs.log.net_address.ipx[6];
      a.ipx[7] = svs.log.net_address.ipx[7];
      a.ipx[8] = svs.log.net_address.ipx[8];
      a.ipx[9] = svs.log.net_address.ipx[9];
      a.port = svs.log.net_address.port;
      pcVar2 = NET_AdrToString(a);
      Con_Printf("current:  %s\n",pcVar2);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_SetMaxclients  @ 00090780
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SetMaxclients(void)

{
  entity_state_s *p;
  float value;
  client_frame_t *pcVar1;
  client_s *pcVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  iVar4 = 0;
  iVar3 = svs.maxclientslimit;
  pcVar2 = svs.clients;
  if (0 < svs.maxclientslimit) {
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_frame_t * pframe@[???] */
      pcVar1 = pcVar2->frames;
      if (pcVar1 != (client_frame_t *)0x0) {
        if (0 < SV_UPDATE_BACKUP) {
          iVar3 = 0;
          do {
                    /* Unresolved local var: packet_entities_t * pack@[???] */
            if (pcVar1 != (client_frame_t *)0x0) {
              p = (pcVar1->entities).entities;
              if (p != (entity_state_s *)0x0) {
                Mem_Free(p);
              }
              (pcVar1->entities).entities = (entity_state_s *)0x0;
              (pcVar1->entities).num_entities = 0;
            }
            *(undefined4 *)&pcVar1->senttime = 0;
            iVar3 = iVar3 + 1;
            *(undefined4 *)((int)&pcVar1->senttime + 4) = 0;
            pcVar1->ping_time = -1.0;
            pcVar1 = pcVar1 + 1;
          } while (iVar3 < SV_UPDATE_BACKUP);
          pcVar1 = pcVar2->frames;
        }
        Mem_Free(pcVar1);
        pcVar2->frames = (client_frame_t *)0x0;
        iVar3 = svs.maxclientslimit;
      }
      iVar4 = iVar4 + 1;
      pcVar2 = pcVar2 + 1;
    } while (iVar4 < iVar3);
  }
  svs.maxclients = 1;
  iVar3 = COM_CheckParm("-maxplayers");
  if (iVar3 == 0) {
    if (g_bIsDedicatedServer == false) goto LAB_000909d5;
    iVar4 = 0xccd00;
    svs.maxclients = 6;
    svs.maxclientslimit = 0x20;
    cls.state = ca_dedicated;
    iVar3 = 6;
  }
  else {
    svs.maxclients = Q_atoi(com_argv[iVar3 + 1]);
LAB_000909d5:
    cls.state = (cactive_t)(g_bIsDedicatedServer == false);
    if (svs.maxclients < 1) {
      svs.maxclients = 6;
      iVar3 = 6;
joined_r0x00090a39:
      if (g_bIsDedicatedServer != false) {
        iVar4 = 0xccd00;
        svs.maxclientslimit = 0x20;
        SV_UPDATE_BACKUP = 0x40;
        SV_UPDATE_MASK = 0x3f;
        goto LAB_000908ab;
      }
      if (host_parms.memsize < 0x1000001) {
        iVar4 = 0x199a0;
        svs.maxclientslimit = 4;
        SV_UPDATE_MASK = 0x3f;
        SV_UPDATE_BACKUP = 0x40;
        goto LAB_000908ab;
      }
    }
    else {
      if (0x20 < svs.maxclients) {
        svs.maxclients = 0x20;
        iVar3 = 0x20;
        goto joined_r0x00090a39;
      }
      iVar3 = svs.maxclients;
      if ((g_bIsDedicatedServer == false) && (host_parms.memsize < 0x1000001)) {
        iVar4 = 0x199a0;
        svs.maxclientslimit = 4;
        goto LAB_0009088a;
      }
    }
    iVar4 = 0xccd00;
    svs.maxclientslimit = 0x20;
  }
LAB_0009088a:
  SV_UPDATE_MASK = 0x3f;
  SV_UPDATE_BACKUP = 0x40;
  if (iVar3 == 1) {
    SV_UPDATE_MASK = 7;
    SV_UPDATE_BACKUP = 8;
  }
LAB_000908ab:
  svs.clients = Hunk_AllocName(iVar4,"clients");
  if (0 < svs.maxclientslimit) {
    iVar3 = 0;
    pcVar2 = svs.clients;
    do {
      iVar3 = iVar3 + 1;
      Q_memset(pcVar2,0,0x6668);
      (pcVar2->resourcesneeded).pPrev = &pcVar2->resourcesneeded;
      (pcVar2->resourcesneeded).pNext = &pcVar2->resourcesneeded;
      (pcVar2->resourcesonhand).pPrev = &pcVar2->resourcesonhand;
      (pcVar2->resourcesonhand).pNext = &pcVar2->resourcesonhand;
      pcVar2 = pcVar2 + 1;
    } while (iVar3 < svs.maxclientslimit);
  }
  value = 0.0;
  if (1 < svs.maxclients) {
    value = 1.0;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  iVar3 = 0;
  Cvar_SetValue("deathmatch",value);
  pcVar2 = svs.clients;
  if (0 < svs.maxclientslimit) {
    do {
      if (pcVar2->frames != (client_frame_t *)0x0) {
        Con_DPrintf("Allocating over frame pointer?\n");
      }
      iVar3 = iVar3 + 1;
      pcVar1 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0x1870);
      pcVar2->frames = pcVar1;
      pcVar2 = pcVar2 + 1;
    } while (iVar3 < svs.maxclientslimit);
  }
  iVar3 = svs.maxclientslimit;
  if (svs.maxclients <= svs.maxclientslimit) {
    iVar3 = svs.maxclients;
  }
  svs.maxclients = iVar3;
  return;
}


// SV_SetMoveVars  @ 00083360
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SetMoveVars(void)

{
  qboolean local_1c;
  
  movevars.gravity = sv_gravity.value;
  movevars.stopspeed = sv_stopspeed.value;
  movevars.maxspeed = sv_maxspeed.value;
  movevars.spectatormaxspeed = sv_spectatormaxspeed.value;
  movevars.accelerate = sv_accelerate.value;
  movevars.airaccelerate = sv_airaccelerate.value;
  movevars.wateraccelerate = sv_wateraccelerate.value;
  movevars.friction = sv_friction.value;
  movevars.edgefriction = sv_edgefriction.value;
  movevars.waterfriction = sv_waterfriction.value;
  movevars.bounce = sv_bounce.value;
  movevars.stepsize = sv_stepsize.value;
  movevars.maxvelocity = sv_maxvelocity.value;
  movevars.zmax = sv_zmax.value;
  movevars.waveHeight = sv_wateramp.value;
  movevars.entgravity = 1.0;
  local_1c = (qboolean)(longlong)ROUND(sv_footsteps.value);
  movevars.footsteps = local_1c;
  movevars.rollangle = sv_rollangle.value;
  movevars.rollspeed = sv_rollspeed.value;
  movevars.skycolor_r = sv_skycolor_r.value;
  movevars.skycolor_g = sv_skycolor_g.value;
  movevars.skycolor_b = sv_skycolor_b.value;
  movevars.skyvec_x = sv_skyvec_x.value;
  movevars.skyvec_y = sv_skyvec_y.value;
  movevars.skyvec_z = sv_skyvec_z.value;
  Q_strncpy(movevars.skyName,sv_skyname.string,0x1f);
  movevars.skyName[0x1f] = '\0';
  return;
}


// SV_SetNewInfo  @ 0008a940
void SV_SetNewInfo(int newblindex)

{
  g_svdeltacallback.newbl = true;
  g_svdeltacallback.newblindex = newblindex;
  return;
}


// SV_SetPlayer  @ 000a3680
qboolean SV_SetPlayer(int idnum)

{
  client_s *pcVar1;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: int i@[???] */
  pcVar1 = svs.clients;
  while ((((pcVar1->spawned == false || (pcVar1->active == false)) || (pcVar1->connected == false))
         || (pcVar1->userid != idnum))) {
    pcVar1 = pcVar1 + 1;
    if (pcVar1 == svs.clients + 0x20) {
      Con_Printf("Userid %i is not on the server\n",idnum);
      return false;
    }
  }
  host_client = pcVar1;
  sv_player = pcVar1->edict;
  return true;
}


// SV_SetStudioHullPlane  @ 00077540
void SV_SetStudioHullPlane(mplane_t *pplane,int iBone,int k,float dist)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  pplane->type = '\x05';
  fVar1 = bonetransform[iBone][0][k];
  pplane->normal[0] = fVar1;
  fVar2 = bonetransform[iBone][1][k];
  pplane->normal[1] = fVar2;
  fVar3 = bonetransform[iBone][2][k];
  pplane->normal[2] = fVar3;
  pplane->dist = fVar3 * bonetransform[iBone][2][3] +
                 fVar2 * bonetransform[iBone][1][3] + fVar1 * bonetransform[iBone][0][3] + dist;
  return;
}


// SV_SetupMove  @ 000a2b40
void SV_SetupMove(client_t *host_client)

{
  sv_adjusted_positions_t *psVar1;
  vec_t vVar2;
  edict_t *peVar3;
  client_frame_t *pcVar4;
  int iVar5;
  entity_state_s *peVar6;
  float fVar7;
  entity_state_s *peVar8;
  entity_state_s *peVar9;
  int iVar10;
  sv_adjusted_positions_t *psVar11;
  int iVar12;
  int iVar13;
  client_s *pcVar14;
  vec_t *pvVar15;
  client_frame_t *pcVar16;
  int iVar17;
  entity_state_s *peVar18;
  int iVar19;
  longdouble lVar20;
  longdouble lVar21;
  longdouble lVar22;
  uint local_5c;
  float local_54;
  client_frame_t *local_4c;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int clindex@[???]
                       Unresolved local var: client_t * cl@[???]
                       Unresolved local var: float targettime@[???]
                       Unresolved local var: float cl_interptime@[???]
                       Unresolved local var: float correct@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: client_frame_t * pnext@[???]
                       Unresolved local var: int msg@[???]
                       Unresolved local var: packet_entities_t * ppack@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: entity_state_t * state@[???]
                       Unresolved local var: entity_state_t * pnextstate@[???]
                       Unresolved local var: vec3_t origin@[???]
                       Unresolved local var: sv_adjusted_positions_t * pos@[???] */
  Q_memset(truepositions,0,0xb00);
  nofind = true;
  iVar10 = (*gEntityInterface.pfnAllowLagCompensation)();
  if (iVar10 == 0) {
    return;
  }
  if (sv_unlag.value == 0.0) {
    return;
  }
  if (host_client->lw == 0) {
    return;
  }
  if (host_client->lc == 0) {
    return;
  }
  if (svs.maxclients < 2) {
    return;
  }
  if (host_client->active == false) {
    return;
  }
  psVar11 = truepositions;
  nofind = false;
  psVar1 = truepositions + svs.maxclients;
  pcVar14 = svs.clients;
  do {
    if ((host_client != pcVar14) && (pcVar14->active != false)) {
      peVar3 = pcVar14->edict;
      psVar11->oldorg[0] = (peVar3->v).origin[0];
      psVar11->oldorg[1] = (peVar3->v).origin[1];
      psVar11->oldorg[2] = (peVar3->v).origin[2];
      psVar11->oldabsmin[0] = (peVar3->v).absmin[0];
      psVar11->oldabsmin[1] = (peVar3->v).absmin[1];
      psVar11->oldabsmin[2] = (peVar3->v).absmin[2];
      psVar11->oldabsmax[0] = (peVar3->v).absmax[0];
      psVar11->oldabsmax[1] = (peVar3->v).absmax[1];
      vVar2 = (peVar3->v).absmax[2];
      psVar11->active = 1;
      psVar11->oldabsmax[2] = vVar2;
    }
    psVar11 = psVar11 + 1;
    pcVar14 = pcVar14 + 1;
  } while (psVar11 != psVar1);
  lVar21 = (longdouble)host_client->latency;
  if ((longdouble)1.5 < (longdouble)host_client->latency) {
    lVar21 = (longdouble)1.5;
  }
  lVar20 = (longdouble)sv_maxunlag.value;
  if (lVar20 != (longdouble)0) {
    lVar22 = lVar21;
    if (lVar20 < (longdouble)0) {
      Cvar_SetValue("sv_maxunlag",0.0);
      lVar20 = (longdouble)sv_maxunlag.value;
      lVar22 = (longdouble)(float)lVar21;
    }
    lVar21 = lVar20;
    if (lVar22 < lVar20) {
      lVar21 = lVar22;
    }
  }
  iVar13 = svs.maxclients;
  iVar19 = SV_UPDATE_BACKUP;
  iVar10 = SV_UPDATE_MASK;
  lVar20 = (longdouble)(host_client->lastcmd).lerp_msec / (longdouble)1000.0;
  if ((longdouble)0.1 < lVar20) {
    lVar20 = (longdouble)0.1;
  }
  if (lVar20 < (longdouble)host_client->next_messageinterval) {
    lVar20 = (longdouble)(float)host_client->next_messageinterval;
  }
  lVar21 = (longdouble)
           (float)((((longdouble)realtime - lVar21) - lVar20) + (longdouble)sv_unlagpush.value);
  if ((longdouble)realtime < lVar21) {
    lVar21 = (longdouble)(float)realtime;
  }
  if (0 < SV_UPDATE_BACKUP) {
    local_4c = (client_frame_t *)0x0;
                    /* Unresolved local var: int i@[???] */
    local_5c = 0;
    pcVar4 = host_client->frames;
    do {
      pcVar16 = pcVar4 + (~local_5c + (host_client->netchan).outgoing_sequence & iVar10);
      iVar5 = (pcVar16->entities).num_entities;
      if (0 < iVar5) {
        peVar6 = (pcVar16->entities).entities;
        pvVar15 = peVar6->origin;
        do {
          fVar7 = pvVar15[-3];
          if (((0 < (int)fVar7) && ((int)fVar7 <= iVar13)) &&
             (iVar12 = (int)fVar7 + -1, truepositions[iVar12].deadflag == 0)) {
            if ((int)pvVar15[0x27] < 1) {
              truepositions[iVar12].deadflag = 1;
            }
            if (((uint)pvVar15[0xb] & 0x20) != 0) {
              truepositions[iVar12].deadflag = 1;
            }
            if (truepositions[iVar12].temp_org_setflag == 0) {
              truepositions[iVar12].temp_org_setflag = 1;
              fVar7 = *pvVar15;
            }
            else {
              fVar7 = *pvVar15;
              if (((128.0 < ABS(fVar7 - truepositions[iVar12].temp_org[0])) ||
                  (128.0 < ABS(pvVar15[1] - truepositions[iVar12].temp_org[1]))) ||
                 (128.0 < ABS(pvVar15[2] - truepositions[iVar12].temp_org[2]))) {
                truepositions[iVar12].deadflag = 1;
                fVar7 = *pvVar15;
              }
            }
            truepositions[iVar12].temp_org[0] = fVar7;
            truepositions[iVar12].temp_org[1] = pvVar15[1];
            truepositions[iVar12].temp_org[2] = pvVar15[2];
          }
          pvVar15 = pvVar15 + 0x55;
        } while (peVar6[iVar5].origin != pvVar15);
      }
      lVar20 = (longdouble)pcVar16->senttime;
      if (lVar20 < lVar21) {
        if (lVar21 - lVar20 <= (longdouble)1) {
          if (local_4c == (client_frame_t *)0x0) {
            local_54 = 0.0;
            local_4c = pcVar16;
          }
          else {
                    /* Unresolved local var: float dt@[???] */
            lVar22 = (longdouble)(float)((longdouble)local_4c->senttime - lVar20);
            if (lVar22 == (longdouble)0) {
              local_54 = 0.0;
            }
            else {
              local_54 = (float)((lVar21 - lVar20) / lVar22);
              if (local_54 <= 1.0) {
                if (local_54 < 0.0) {
                  local_54 = 0.0;
                }
              }
              else {
                local_54 = 1.0;
              }
            }
          }
          iVar10 = 0;
          iVar19 = 0;
          local_5c = iVar5;
          if (iVar5 < 1) {
            return;
          }
          goto LAB_000a2fb0;
        }
        break;
      }
      local_5c = local_5c + 1;
      local_4c = pcVar16;
    } while (local_5c != iVar19);
  }
  Q_memset(truepositions,0,0xb00);
  nofind = true;
  return;
LAB_000a2fb0:
  peVar6 = (pcVar16->entities).entities;
  iVar13 = *(int *)((int)peVar6->origin + iVar10 + -0xc);
  if (((0 < iVar13) && (iVar13 <= svs.maxclients)) &&
     ((pcVar14 = svs.clients + iVar13 + -1, host_client != pcVar14 &&
      ((pcVar14->active != false && (iVar5 = iVar13 + -1, truepositions[iVar5].deadflag == 0)))))) {
    if (truepositions[iVar5].active == 0) {
      Con_DPrintf("tried to store off position of bogus player %i/%s\n",iVar19,pcVar14->name);
      local_5c = (pcVar16->entities).num_entities;
    }
    else {
                    /* Unresolved local var: int i@[???] */
      iVar12 = (local_4c->entities).num_entities;
      if (iVar12 < 1) {
LAB_000a3089:
        local_34 = *(vec_t *)((int)peVar6->origin + iVar10);
        local_30 = *(vec_t *)((int)peVar6->origin + iVar10 + 4);
        local_2c = *(vec_t *)((int)peVar6->origin + iVar10 + 8);
      }
      else {
        peVar18 = (local_4c->entities).entities;
        if (iVar13 != peVar18->number) {
          iVar17 = 0;
          peVar8 = peVar18;
          do {
            peVar18 = peVar8 + 1;
            iVar17 = iVar17 + 1;
            if (iVar17 == iVar12) goto LAB_000a3089;
            peVar9 = peVar8 + 1;
            peVar8 = peVar18;
          } while (iVar13 != peVar9->number);
        }
        if (peVar18 == (entity_state_s *)0x0) goto LAB_000a3089;
                    /* Unresolved local var: vec3_t delta@[???] */
        pvVar15 = (vec_t *)((int)peVar6->origin + iVar10);
        local_28 = peVar18->origin[0] - *pvVar15;
        local_24 = peVar18->origin[1] - *(float *)((int)peVar6->origin + iVar10 + 4);
        local_20 = peVar18->origin[2] - *(float *)((int)peVar6->origin + iVar10 + 8);
        VectorMA(pvVar15,local_54,&local_28,&local_34);
      }
      truepositions[iVar5].neworg[0] = local_34;
      truepositions[iVar5].neworg[1] = local_30;
      truepositions[iVar5].neworg[2] = local_2c;
      peVar3 = pcVar14->edict;
      truepositions[iVar5].initial_correction_org[0] = local_34;
      truepositions[iVar5].initial_correction_org[1] = local_30;
      truepositions[iVar5].initial_correction_org[2] = local_2c;
      iVar13 = VectorCompare(&local_34,(peVar3->v).origin);
      if (iVar13 == 0) {
        (pcVar14->edict->v).origin[0] = local_34;
        (pcVar14->edict->v).origin[1] = local_30;
        (pcVar14->edict->v).origin[2] = local_2c;
        SV_LinkEdict(pcVar14->edict,false);
        truepositions[iVar5].needrelink = 1;
      }
      local_5c = (pcVar16->entities).num_entities;
    }
  }
  iVar19 = iVar19 + 1;
  iVar10 = iVar10 + 0x154;
  if ((int)local_5c <= iVar19) {
    return;
  }
  goto LAB_000a2fb0;
}


// SV_ShouldUpdatePing  @ 0008b440
qboolean SV_ShouldUpdatePing(client_t *client)

{
  if (client->proxy == false) {
    return (uint)((client->lastcmd).buttons & 0x8000);
  }
  if (client->nextping <= realtime) {
    client->nextping = realtime + 2.0;
    return true;
  }
  return false;
}


// SV_ShowServerinfo_f  @ 000a3700
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_ShowServerinfo_f(void)

{
  char *s;
  
  if (cmd_source != src_command) {
    s = Info_Serverinfo();
    Info_Print(s);
    return;
  }
  Cmd_ForwardToServer();
  return;
}


// SV_Shutdown  @ 00091f10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Shutdown(void)

{
  delta_info_s *pdVar1;
  delta_info_t *p;
  
  p = g_sv_delta;
  while (p != (delta_info_t *)0x0) {
    pdVar1 = p->next;
    if (p->delta != (delta_t *)0x0) {
      DELTA_FreeDescription(&p->delta);
    }
    Mem_Free(p->name);
    Mem_Free(p->loadfile);
    Mem_Free(p);
    p = pdVar1;
  }
  g_sv_delta = (delta_info_t *)0x0;
  return;
}


// SV_SingleClipMoveToEntity  @ 000aa950
void __regparm3
SV_SingleClipMoveToEntity
          (edict_t *ent,vec_t *start,vec_t *mins,vec_t *maxs,vec_t *end,trace_t *trace)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  hull_t *hull;
  int iVar8;
  int local_a4;
  int local_94;
  vec_t local_90;
  vec_t local_8c;
  vec_t local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  trace_t local_54;
  
                    /* Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: model_t * pmodel@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int rotated@[???]
                       Unresolved local var: int idx@[???] */
  Q_memset(trace,0,0x38);
  trace->fraction = 1.0;
  trace->allsolid = true;
  trace->endpos[0] = *end;
  trace->endpos[1] = end[1];
  trace->endpos[2] = end[2];
  iVar7 = (ent->v).modelindex;
  if (((iVar7 < 0) || (sv.models[iVar7] == (model_s *)0x0)) ||
     (sv.models[iVar7]->type != mod_studio)) {
                    /* Unresolved local var: vec3_t hullmins@[???]
                       Unresolved local var: vec3_t hullmaxs@[???]
                       Unresolved local var: hull_t * hull@[???] */
    iVar7 = (ent->v).solid;
    if (iVar7 == 4) {
      iVar7 = (ent->v).movetype;
      if ((iVar7 != 7) && (iVar7 != 0xd)) {
        Sys_Error("SOLID_BSP without MOVETYPE_PUSH");
      }
      hull = SV_HullForBsp(ent,mins,maxs,&local_90);
      iVar7 = (ent->v).solid;
    }
    else {
      box_planes[1].dist = (ent->v).mins[0] - *maxs;
      box_planes[3].dist = (ent->v).mins[1] - maxs[1];
      hull = &box_hull;
      box_planes[5].dist = (ent->v).mins[2] - maxs[2];
      box_planes[2].dist = (ent->v).maxs[1] - mins[1];
      box_planes[4].dist = (ent->v).maxs[2] - mins[2];
      box_planes[0].dist = (ent->v).maxs[0] - *mins;
      local_90 = (ent->v).origin[0];
      local_8c = (ent->v).origin[1];
      local_88 = (ent->v).origin[2];
    }
    local_94 = 1;
  }
  else {
    hull = SV_HullForStudioModel(ent,mins,maxs,&local_90,&local_94);
    iVar7 = (ent->v).solid;
  }
  bVar5 = false;
  local_84 = *start - local_90;
  local_80 = start[1] - local_8c;
  local_7c = start[2] - local_88;
  local_78 = *end - local_90;
  local_74 = end[1] - local_8c;
  local_70 = end[2] - local_88;
  if ((iVar7 == 4) &&
     ((((ent->v).angles[0] != 0.0 || ((ent->v).angles[1] != 0.0)) || ((ent->v).angles[2] != 0.0))))
  {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
    AngleVectors((ent->v).angles,&local_6c,&local_60,(vec_t *)&local_54);
    fVar2 = local_64 * local_7c + local_68 * local_80 + local_6c * local_84;
    fVar1 = -(local_58 * local_7c + local_5c * local_80 + local_60 * local_84);
    local_7c = local_7c * (float)local_54.inopen +
               local_80 * (float)local_54.startsolid + local_84 * (float)local_54.allsolid;
    fVar4 = local_64 * local_70 + local_68 * local_74 + local_6c * local_78;
    fVar3 = -(local_58 * local_70 + local_5c * local_74 + local_60 * local_78);
    local_70 = (float)local_54.inopen * local_70 +
               local_74 * (float)local_54.startsolid + (float)local_54.allsolid * local_78;
    bVar5 = true;
    local_84 = fVar2;
    local_80 = fVar1;
    local_78 = fVar4;
    local_74 = fVar3;
    if (local_94 != 1) goto LAB_000aaae6;
LAB_000aae4a:
    SV_RecursiveHullCheck(hull,hull->firstclipnode,0.0,1.0,&local_84,&local_78,trace);
  }
  else {
    if (local_94 == 1) goto LAB_000aae4a;
LAB_000aaae6:
                    /* Unresolved local var: int closest@[???]
                       Unresolved local var: trace_t testtrace@[???] */
    local_a4 = 0;
    if (0 < local_94) {
      iVar7 = 0;
      do {
        while( true ) {
          iVar8 = iVar7;
          Q_memset(&local_54,0,0x38);
          local_54.endpos[0] = *end;
          local_54.endpos[1] = end[1];
          local_54.endpos[2] = end[2];
          local_54.allsolid = true;
          local_54.fraction = 1.0;
          SV_RecursiveHullCheck(hull,hull->firstclipnode,0.0,1.0,&local_84,&local_78,&local_54);
          if ((((iVar8 == 0) || ((float)local_54.allsolid != 0.0)) ||
              ((float)local_54.startsolid != 0.0)) || (local_54.fraction < trace->fraction)) break;
LAB_000aabea:
          hull = hull + 1;
          iVar7 = iVar8 + 1;
          if (local_94 <= iVar8 + 1) goto LAB_000aabf8;
        }
        uVar6 = 0;
        local_a4 = iVar8;
        if (trace->startsolid != false) {
          do {
            *(undefined4 *)((int)trace->endpos + (uVar6 - 0x14)) =
                 *(undefined4 *)((int)local_54.endpos + (uVar6 - 0x14));
            uVar6 = uVar6 + 4;
          } while (uVar6 < 0x38);
          trace->startsolid = true;
          goto LAB_000aabea;
        }
        do {
          *(undefined4 *)((int)trace->endpos + (uVar6 - 0x14)) =
               *(undefined4 *)((int)local_54.endpos + (uVar6 - 0x14));
          uVar6 = uVar6 + 4;
        } while (uVar6 < 0x38);
        hull = hull + 1;
        iVar7 = iVar8 + 1;
      } while (iVar8 + 1 < local_94);
    }
LAB_000aabf8:
    iVar7 = SV_HitgroupForStudioHull(local_a4);
    trace->hitgroup = iVar7;
  }
  fVar1 = trace->fraction;
  if (fVar1 != 1.0) {
    if (bVar5) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t temp@[???] */
      AngleVectorsTranspose((ent->v).angles,&local_6c,&local_60,(vec_t *)&local_54);
      fVar1 = (trace->plane).normal[0];
      fVar2 = (trace->plane).normal[1];
      fVar3 = (trace->plane).normal[2];
      (trace->plane).normal[0] = local_64 * fVar3 + local_68 * fVar2 + local_6c * fVar1;
      (trace->plane).normal[1] = local_58 * fVar3 + local_5c * fVar2 + local_60 * fVar1;
      (trace->plane).normal[2] =
           fVar3 * (float)local_54.inopen +
           fVar2 * (float)local_54.startsolid + fVar1 * (float)local_54.allsolid;
      fVar1 = trace->fraction;
    }
    trace->endpos[0] = (*end - *start) * fVar1 + *start;
    trace->endpos[1] = (end[1] - start[1]) * fVar1 + start[1];
    trace->endpos[2] = (end[2] - start[2]) * fVar1 + start[2];
    if (fVar1 < 1.0) goto LAB_000aac6a;
  }
  if (trace->startsolid == false) {
    return;
  }
LAB_000aac6a:
  trace->ent = ent;
  return;
}


// SV_SingleClipMoveToEntity  @ 000aaff0
void SV_SingleClipMoveToEntity
               (edict_t *ent,vec_t *start,vec_t *mins,vec_t *maxs,vec_t *end,trace_t *trace)

{
                    /* Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: model_t * pmodel@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int rotated@[???]
                       Unresolved local var: int idx@[???] */
  if ((trace != (trace_t *)0x0) && (ent != (edict_t *)0x0)) {
    SV_SingleClipMoveToEntity(ent,start,mins,maxs,end,trace);
    return;
  }
  return;
}


// SV_SkipUpdates  @ 0008c590
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_SkipUpdates(void)

{
  client_t *pcVar1;
  int iVar2;
  client_s *pcVar3;
  int iVar4;
  
  iVar2 = svs.maxclients;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[DW_OP_reg0(EAX)] */
  pcVar1 = host_client;
  if (0 < svs.maxclients) {
    iVar4 = 0;
    pcVar3 = svs.clients;
    do {
      if ((((pcVar3->active != false) || (pcVar3->connected != false)) || (pcVar3->spawned != false)
          ) && (pcVar1->fakeclient == false)) {
        pcVar3->skip_message = true;
      }
      iVar4 = iVar4 + 1;
      pcVar3 = pcVar3 + 1;
    } while (iVar4 != iVar2);
  }
  return;
}


// SV_SpawnServer  @ 0008f0a0
int SV_SpawnServer(qboolean bIsDemo,char *server,char *startspot)

{
  edict_t *peVar1;
  entity_state_s *p;
  float fVar2;
  int iVar3;
  size_t sVar4;
  client_frame_t *pcVar5;
  BOOL BVar6;
  model_t *pmVar7;
  edict_t **ppeVar8;
  char *pcVar9;
  client_s *pcVar10;
  int iVar11;
  char **ppcVar12;
  int iVar13;
  char (*name) [5];
  int in_GS_OFFSET;
  char local_160 [63];
  undefined1 local_121;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: client_t * cl@[???]
                       Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char * pszhost@[???]
                       Unresolved local var: char[64] oldname@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((sv.active != false) && (1 < svs.maxclients)) {
    iVar11 = 0;
    pcVar9 = (svs.clients)->name;
    iVar13 = svs.maxclients;
    do {
      if ((((((client_s *)(pcVar9 + -0x6358))->active != false) ||
           (*(qboolean *)(pcVar9 + -0x6354) != false)) || (*(qboolean *)(pcVar9 + -0x634c) != false)
          ) && ((peVar1 = *(edict_t **)(pcVar9 + -0x164), peVar1 != (edict_t *)0x0 &&
                (peVar1->free == false)))) {
        if (peVar1->pvPrivateData == (void *)0x0) {
          Con_Printf("Skipping reconnect on %s, no pvPrivateData\n",pcVar9);
          iVar13 = svs.maxclients;
        }
        else {
          (*gEntityInterface.pfnClientDisconnect)(peVar1);
          iVar13 = svs.maxclients;
        }
      }
      iVar11 = iVar11 + 1;
      pcVar9 = pcVar9 + 0x6668;
    } while (iVar11 < iVar13);
  }
  if (g_bOutOfDateRestart == true) {
    g_bOutOfDateRestart = false;
    Cmd_ExecuteString("quit\n",src_command);
  }
  Log_Open();
  Log_Printf("Loading map \"%s\"\n",server);
  if ((mapchangecfgfile.string != (char *)0x0) &&
     (sVar4 = strlen(mapchangecfgfile.string), 2 < sVar4)) {
                    /* Unresolved local var: char[256] szCommand@[???] */
    AlertMessage(at_console,"Executing map change config file\n");
    __snprintf_chk(local_120,0x100,1,0x100,"exec %s\n",mapchangecfgfile.string);
    Cbuf_AddText(local_120);
  }
  if ((server != (char *)0x0) && (sVar4 = strlen(server), 2 < sVar4)) {
                    /* Unresolved local var: char[256] szCommand@[???] */
    __snprintf_chk(local_120,0x100,1,0x100,"exec maps/%s_load.cfg\n",server);
    Cbuf_AddText(local_120);
  }
  Log_PrintServerVars();
  NET_Config((uint)(1 < svs.maxclients));
  pcVar9 = Cvar_VariableString("hostname");
  if ((pcVar9 != (char *)0x0) && (*pcVar9 == '\0')) {
    if (gEntityInterface.pfnGetGameDescription == (_func_char_ptr *)0x0) {
      Cvar_Set("hostname","Half-Life");
    }
    else {
      pcVar9 = (*gEntityInterface.pfnGetGameDescription)();
      Cvar_Set("hostname",pcVar9);
    }
  }
  scr_centertime_off = 0.0;
  if (startspot == (char *)0x0) {
    Con_DPrintf("Spawn Server %s\n",server);
  }
  else {
    Con_DPrintf("Spawn Server %s: [%s]\n",server,startspot);
  }
  gHostSpawnCount = gHostSpawnCount + 1;
  svs.spawncount = gHostSpawnCount;
  if (coop.value != 0.0) {
    Cvar_SetValue("deathmatch",0.0);
  }
  current_skill = (int)(skill.value + 0.5);
  if (current_skill < 0) {
    current_skill = 0;
    fVar2 = 0.0;
  }
  else if (current_skill < 4) {
    fVar2 = (float)current_skill;
  }
  else {
    fVar2 = 3.0;
    current_skill = 3;
  }
  Cvar_SetValue("skill",fVar2);
  ContinueLoadingProgressBar("Server",2,0.0);
  HPAK_CheckSize("custom");
  local_160[0] = '\0';
  Q_strncpy(local_160,sv.name,0x3f);
  local_121 = 0;
  Host_ClearMemory(false);
  if (svs.maxclientslimit < 1) {
    if (svs.maxclients == 1) {
      SV_UPDATE_BACKUP = 8;
      SV_UPDATE_MASK = 7;
    }
    else {
      SV_UPDATE_BACKUP = 0x40;
      SV_UPDATE_MASK = 0x3f;
    }
  }
  else {
    iVar11 = 0;
    iVar13 = svs.maxclientslimit;
    pcVar10 = svs.clients;
    do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_frame_t * pframe@[???] */
      pcVar5 = pcVar10->frames;
      if (pcVar5 != (client_frame_t *)0x0) {
        if (0 < SV_UPDATE_BACKUP) {
          iVar13 = 0;
          do {
                    /* Unresolved local var: packet_entities_t * pack@[???] */
            if (pcVar5 != (client_frame_t *)0x0) {
              p = (pcVar5->entities).entities;
              if (p != (entity_state_s *)0x0) {
                Mem_Free(p);
              }
              (pcVar5->entities).entities = (entity_state_s *)0x0;
              (pcVar5->entities).num_entities = 0;
            }
            *(undefined4 *)&pcVar5->senttime = 0;
            iVar13 = iVar13 + 1;
            *(undefined4 *)((int)&pcVar5->senttime + 4) = 0;
            pcVar5->ping_time = -1.0;
            pcVar5 = pcVar5 + 1;
          } while (iVar13 < SV_UPDATE_BACKUP);
          pcVar5 = pcVar10->frames;
        }
        Mem_Free(pcVar5);
        pcVar10->frames = (client_frame_t *)0x0;
        iVar13 = svs.maxclientslimit;
      }
      iVar11 = iVar11 + 1;
      pcVar10 = pcVar10 + 1;
    } while (iVar11 < iVar13);
    SV_UPDATE_MASK = 7;
    if (svs.maxclients != 1) {
      SV_UPDATE_MASK = 0x3f;
    }
    SV_UPDATE_BACKUP = 0x40;
    if (svs.maxclients == 1) {
      SV_UPDATE_BACKUP = 8;
    }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
    if (0 < iVar13) {
      iVar13 = 0;
      pcVar10 = svs.clients;
      do {
        if (pcVar10->frames != (client_frame_t *)0x0) {
          Con_DPrintf("Allocating over frame pointer?\n");
        }
        iVar13 = iVar13 + 1;
        pcVar5 = Mem_ZeroMalloc(SV_UPDATE_BACKUP * 0x1870);
        pcVar10->frames = pcVar5;
        pcVar10 = pcVar10 + 1;
      } while (iVar13 < svs.maxclientslimit);
    }
  }
  Q_memset(&sv,0,0x473ac);
  Q_strncpy(sv.oldname,local_160,0x3f);
  sv.oldname[0x3f] = '\0';
  Q_strncpy(sv.name,server,0x3f);
  sv.name[0x3f] = '\0';
  if (startspot == (char *)0x0) {
    sv.startspot[0] = '\0';
  }
  else {
    Q_strncpy(sv.startspot,startspot,0x3f);
    sv.startspot[0x3f] = '\0';
  }
  pr_strings = gNullString;
  gGlobalVariables.pStringBase = gNullString;
  if (svs.maxclients == 1) {
    Cvar_SetValue("sv_clienttrace",1.0);
  }
  sv.max_edicts = COM_EntsForPlayerSlots(svs.maxclients);
  if (g_moved_edict != (edict_t **)0x0) {
    Mem_Free(g_moved_edict);
  }
  if (g_moved_from != (vec3_t *)0x0) {
    Mem_Free(g_moved_from);
  }
                    /* Unresolved local var: int nSize@[???] */
  iVar13 = sv.max_edicts;
  g_moved_edict = (edict_t **)0x0;
  g_moved_from = (vec3_t *)0x0;
  if (sv.max_edicts == 0) {
    Con_DPrintf("SV_ReallocateDynamicData with sv.max_edicts == 0");
  }
  else {
    g_moved_edict = Mem_ZeroMalloc(sv.max_edicts * 4);
    if (g_moved_from != (vec3_t *)0x0) {
      Con_Printf("Reallocate on moved_from\n");
    }
    g_moved_from = Mem_ZeroMalloc(iVar13 * 0xc);
  }
  gGlobalVariables.maxEntities = sv.max_edicts;
  sv.edicts = Hunk_AllocName(sv.max_edicts * 0x324,"edicts");
  sv.baselines = Hunk_AllocName(sv.max_edicts * 0x154,"baselines");
  gGlobalVariables.maxClients = svs.maxclients;
  sv.datagram.data = sv.datagram_buf;
  sv.signon.data = sv.signon_data;
  sv.datagram.maxsize = 6000;
  sv.datagram.cursize = 0;
  sv.datagram.buffername = "Server Datagram";
  sv.reliable_datagram.maxsize = 6000;
  sv.reliable_datagram.cursize = 0;
  sv.reliable_datagram.data = sv.reliable_datagram_buf;
  sv.reliable_datagram.buffername = "Server Reliable Datagram";
  sv.multicast.maxsize = 0x400;
  sv.multicast.data = sv.multicast_buf;
  sv.spectator.data = sv.spectator_buf;
  sv.num_edicts = svs.maxclients + 1;
  sv.signon.cursize = 0;
  sv.multicast.buffername = "Server Multicast Buffer";
  sv.spectator.maxsize = 0x400;
  sv.spectator.buffername = "Server Spectator Buffer";
  sv.signon.maxsize = 0x8000;
  sv.signon.buffername = "Server Signon Buffer";
  if (0 < svs.maxclients) {
    iVar11 = sv.num_edicts * 0x324;
    iVar13 = 0x324;
    ppeVar8 = &(svs.clients)->edict;
    do {
      iVar3 = iVar13 + -0x18;
      iVar13 = iVar13 + 0x324;
      *ppeVar8 = (edict_t *)((int)(sv.edicts)->leafnums + iVar3);
      ppeVar8 = ppeVar8 + 0x199a;
    } while (iVar11 - iVar13 != 0);
  }
  sv.state = ss_loading;
  sv.paused = false;
  sv.time._0_4_ = 0;
  sv.time._4_4_ = 0x3ff00000;
  gGlobalVariables.time = 1.0;
  ContinueLoadingProgressBar("Server",3,0.0);
  __snprintf_chk(0x4ff368,0x40,1,0x40,"maps/%s.bsp",server);
  sv.worldmodel = Mod_ForName(sv.modelname,false,false);
  if (sv.worldmodel == (model_t *)0x0) {
    Con_Printf("Couldn\'t spawn server %s\n",0x4ff368);
    sv.active = false;
    iVar13 = 0;
  }
  else {
    ContinueLoadingProgressBar("Server",4,0.0);
    if (gmodinfo.clientcrccheck != false) {
                    /* Unresolved local var: char[64] szDllName@[???] */
      builtin_strncpy(local_120,"cl_dlls//client.dll",0x14);
      COM_FixSlashes(local_120);
      BVar6 = MD5_Hash_File(sv.clientdllmd5,local_120,0,0,(uint *)0x0);
      if (BVar6 == 0) {
        Con_Printf("Couldn\'t CRC client side dll:  %s\n",local_120);
        sv.active = false;
        iVar13 = 0;
        goto LAB_0008fa83;
      }
    }
    ContinueLoadingProgressBar("Server",6,0.0);
    if (svs.maxclients < 2) {
      sv.worldmapCRC = 0;
    }
    else {
      CRC32_Init(&sv.worldmapCRC);
      iVar13 = CRC_MapFile(&sv.worldmapCRC,sv.modelname);
      if (iVar13 == 0) {
        Con_Printf("Couldn\'t CRC server map:  %s\n",0x4ff368);
        sv.active = false;
        iVar13 = 0;
        goto LAB_0008fa83;
      }
      CM_CalcPAS(sv.worldmodel);
    }
    sv.models[1] = sv.worldmodel;
    SV_ClearWorld();
    sv.model_precache_flags[1] = sv.model_precache_flags[1] | 1;
    sv.model_precache[1] = sv.modelname;
    sv.sound_precache[0] = pr_strings;
    sv.model_precache[0] = pr_strings;
    sv.generic_precache[0] = pr_strings;
    if (1 < (sv.worldmodel)->numsubmodels) {
      name = localmodels;
      iVar13 = 1;
      ppcVar12 = sv.model_precache + 2;
      do {
        name = name + 1;
        *ppcVar12 = *name;
        iVar11 = iVar13 + 1;
        pmVar7 = Mod_ForName(*name,false,false);
        ppcVar12[0x200] = pmVar7->name;
        sv.model_precache_flags[iVar13 + 1] = sv.model_precache_flags[iVar13 + 1] | 1;
        iVar13 = iVar11;
        ppcVar12 = ppcVar12 + 1;
      } while (iVar11 < (sv.worldmodel)->numsubmodels);
    }
    peVar1 = sv.edicts;
    Q_memset(&(sv.edicts)->v,0,0x2a4);
    peVar1->free = false;
    pcVar9 = pr_strings;
    fVar2 = coop.value;
    (peVar1->v).model = (int)sv.worldmodel - (int)pr_strings;
    (peVar1->v).modelindex = 1;
    (peVar1->v).solid = 4;
    (peVar1->v).movetype = 7;
    if (fVar2 == 0.0) {
      gGlobalVariables.deathmatch = deathmatch.value;
    }
    else {
      gGlobalVariables.coop = fVar2;
    }
    gGlobalVariables.serverflags = (float)svs.serverflags;
    gGlobalVariables.mapname = 0x4ff2a8 - (int)pcVar9;
    gGlobalVariables.startspot = 0x4ff328 - (int)pcVar9;
    if (deathmatch.value == 0.0) {
      Cvar_Set("sv_allow_shaders","1");
      Cvar_Set("sv_allow_autoaim","1");
    }
    else {
      Cvar_Set("sv_skyname","desert");
      Cvar_Set("sv_skycolor_r","0");
      Cvar_Set("sv_skycolor_g","0");
      Cvar_Set("sv_skycolor_b","0");
      Cvar_Set("sv_skyvec_x","0");
      Cvar_Set("sv_skyvec_y","0");
      Cvar_Set("sv_skyvec_z","0");
      Cvar_Set("room_type","0");
      Cvar_Set("sv_allow_shaders","0");
      Cvar_Set("sv_allow_autoaim","0");
    }
    SV_SetMoveVars();
    iVar13 = 1;
  }
LAB_0008fa83:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar13;
}


// SV_Spawn_f  @ 00084eb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Spawn_f(void)

{
  int iVar1;
  client_t *pcVar2;
  int iVar3;
  char *pcVar4;
  long lVar5;
  int in_GS_OFFSET;
  sizebuf_t sStack_10024;
  byte abStack_10010 [65544];
  
                    /* Unresolved local var: uchar[65536] data@[???]
                       Unresolved local var: sizebuf_t msg@[???] */
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&sStack_10024,0,0x14);
  sStack_10024.buffername = "Spawning";
  sStack_10024.data = abStack_10010;
  sStack_10024.cursize = 0;
  sStack_10024.maxsize = 0x10000;
  iVar3 = Cmd_Argc();
  pcVar2 = host_client;
  if (iVar3 == 3) {
    if (cmd_source == src_command) {
      Con_Printf("spawn is not valid from the console\n");
    }
    else if (host_client->spawned == false) {
      pcVar4 = Cmd_Argv(2);
      lVar5 = strtol(pcVar4,(char **)0x0,10);
      pcVar2->crcValue = lVar5;
      COM_UnMunge2((uchar *)&host_client->crcValue,4,0xffU - svs.spawncount & 0xff);
      if (cls.demoplayback == false) {
        pcVar4 = Cmd_Argv(1);
        iVar3 = Q_atoi(pcVar4);
        if (iVar3 != svs.spawncount) {
          SV_New_f();
          goto LAB_00084f18;
        }
      }
      SZ_Write(&sStack_10024,sv.signon.data,sv.signon.cursize);
      SV_WriteSpawn(&sStack_10024);
      MSG_WriteByte(&sStack_10024,0x34);
      MSG_WriteString(&sStack_10024,"");
      MSG_WriteByte(&sStack_10024,0);
      Netchan_CreateFragments(true,&host_client->netchan,&sStack_10024);
      Netchan_FragSend(&host_client->netchan);
    }
    else {
      Con_Printf("spawn is not valid when already spawned\n");
    }
  }
  else {
    Con_Printf("spawn is not valid\n");
  }
LAB_00084f18:
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_StartParticle  @ 000821a0
void SV_StartParticle(vec_t *org,vec_t *dir,int color,int count)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int v@[???] */
  if (0x1760 < sv.datagram.cursize) {
    return;
  }
  iVar2 = 0;
  MSG_WriteByte(&sv.datagram,0x12);
  MSG_WriteCoord(&sv.datagram,*org);
  MSG_WriteCoord(&sv.datagram,org[1]);
  MSG_WriteCoord(&sv.datagram,org[2]);
  do {
    iVar1 = (int)(dir[iVar2] * 16.0);
    if (iVar1 < -0x80) {
      iVar1 = -0x80;
    }
    if (0x7f < iVar1) {
      iVar1 = 0x7f;
    }
    iVar2 = iVar2 + 1;
    MSG_WriteChar(0x53aee8,iVar1);
  } while (iVar2 != 3);
  MSG_WriteByte(&sv.datagram,count);
  MSG_WriteByte(&sv.datagram,color);
  return;
}


// SV_StartSound  @ 00082e70
void SV_StartSound(int recipients,edict_t *entity,int channel,char *sample,int volume,
                  float attenuation,int fFlags,int pitch)

{
  qboolean qVar1;
  int iVar2;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean sendPAS@[???]
                       Unresolved local var: vec3_t origin@[???] */
  local_28 = ((entity->v).maxs[0] + (entity->v).mins[0]) * 0.5 + (entity->v).origin[0];
  local_24 = ((entity->v).maxs[1] + (entity->v).mins[1]) * 0.5 + (entity->v).origin[1];
  local_20 = ((entity->v).mins[2] + (entity->v).maxs[2]) * 0.5 + (entity->v).origin[2];
  qVar1 = SV_BuildSoundMsg(entity,channel,sample,volume,attenuation,fFlags,pitch,&local_28,
                           &sv.multicast);
  if (qVar1 != false) {
                    /* Unresolved local var: int flags@[???] */
    if ((channel == 6) || ((fFlags & 0x20U) != 0)) {
      iVar2 = 1;
      if (recipients == 1) {
        iVar2 = 0x81;
      }
      qVar1 = Host_IsSinglePlayerGame();
      if (qVar1 == false) {
        SV_Multicast(entity,&local_28,iVar2,true);
      }
      else {
        SV_Multicast(entity,&local_28,iVar2,false);
      }
    }
    else {
      iVar2 = 0x84;
      if (recipients != 1) {
        iVar2 = 4;
      }
      SV_Multicast(entity,&local_28,iVar2,false);
    }
  }
  return;
}


// SV_StepDirection  @ 00096480
qboolean SV_StepDirection(edict_t *ent,float yaw,float dist)

{
  vec_t *maxs;
  vec_t *mins;
  float fVar1;
  float fVar2;
  float fVar3;
  edict_t *peVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  int iVar8;
  qboolean qVar9;
  uint uVar10;
  trace_t local_cc;
  float local_80;
  double local_7c;
  double local_74;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  int local_54 [4];
  float local_44;
  vec_t local_40;
  vec_t local_3c;
  vec_t vStack_38;
  edict_t *peStack_24;
  
                    /* Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t oldorigin@[???] */
  local_80 = (yaw * 3.1415927 + yaw * 3.1415927) / 360.0;
  sincos((double)local_80,&local_74,&local_7c);
  fVar5 = (float)local_7c * dist;
  fVar6 = dist * (float)local_74;
                    /* Unresolved local var: float dz@[???]
                       Unresolved local var: vec3_t oldorg@[???]
                       Unresolved local var: vec3_t neworg@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * enemy@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  uVar10 = (ent->v).flags;
  fVar1 = (ent->v).origin[0];
  fVar2 = (ent->v).origin[1];
  fVar3 = (ent->v).origin[2];
  local_6c = fVar5 + fVar1;
  qVar9 = uVar10 >> 0x17 & true;
  local_68 = fVar6 + fVar2;
  local_80 = fVar6;
  if ((uVar10 & 3) == 0) {
    local_64 = fVar3 + 0.0 + sv_stepsize.value;
    maxs = (ent->v).maxs;
    mins = (ent->v).mins;
    local_58 = local_64 - (sv_stepsize.value + sv_stepsize.value);
    local_60 = local_6c;
    local_5c = local_68;
    SV_Move(&local_cc,&local_6c,mins,maxs,&local_60,0,ent,qVar9);
    uVar10 = 0;
    do {
      *(undefined4 *)((int)local_54 + uVar10) =
           *(undefined4 *)((int)local_cc.endpos + (uVar10 - 0x14));
      uVar10 = uVar10 + 4;
    } while (uVar10 < 0x38);
    if (local_54[0] == 0) {
      if (local_54[1] != 0) {
        local_64 = local_64 - sv_stepsize.value;
        SV_Move(&local_cc,&local_6c,mins,maxs,&local_60,0,ent,qVar9);
        uVar10 = 0;
        do {
          *(undefined4 *)((int)local_54 + uVar10) =
               *(undefined4 *)((int)local_cc.endpos + (uVar10 - 0x14));
          uVar10 = uVar10 + 4;
        } while (uVar10 < 0x38);
        if ((local_54[0] != 0) || (local_54[1] != 0)) goto LAB_00096690;
      }
      if (local_44 == 1.0) {
        uVar10 = (ent->v).flags;
        if ((uVar10 & 0x400) == 0) goto LAB_00096690;
        (ent->v).flags = uVar10 & 0xfffffdff;
        (ent->v).origin[0] = fVar5 + (ent->v).origin[0];
        (ent->v).origin[1] = fVar6 + (ent->v).origin[1];
        (ent->v).origin[2] = (ent->v).origin[2] + 0.0;
      }
      else {
        (ent->v).origin[0] = local_40;
        (ent->v).origin[1] = local_3c;
        (ent->v).origin[2] = vStack_38;
        qVar9 = SV_CheckBottom(ent);
        if (qVar9 == false) {
          if (((ent->v).flags & 0x400) == 0) {
            (ent->v).origin[0] = fVar1;
            (ent->v).origin[1] = fVar2;
            (ent->v).origin[2] = fVar3;
            goto LAB_00096690;
          }
        }
        else {
          uVar10 = (ent->v).flags;
          if ((uVar10 & 0x400) != 0) {
            (ent->v).flags = uVar10 & 0xfffffbff;
          }
          (ent->v).groundentity = peStack_24;
        }
      }
LAB_00096816:
      SV_LinkEdict(ent,true);
      return true;
    }
  }
  else {
    uVar10 = 0;
    while( true ) {
      peVar4 = (ent->v).enemy;
      local_64 = fVar3 + 0.0;
      if (((uVar10 & 1) == 0) && (peVar4 != (edict_t *)0x0)) {
        fVar3 = fVar3 - (peVar4->v).origin[2];
        if (40.0 < fVar3) {
          local_64 = local_64 - 8.0;
        }
        if (fVar3 < 30.0) {
          local_64 = local_64 + 8.0;
        }
      }
      SV_Move(&local_cc,(ent->v).origin,(ent->v).mins,(ent->v).maxs,&local_6c,0,ent,qVar9);
      uVar7 = 0;
      do {
        *(undefined4 *)((int)local_54 + uVar7) =
             *(undefined4 *)((int)local_cc.endpos + (uVar7 - 0x14));
        uVar7 = uVar7 + 4;
      } while (uVar7 < 0x38);
      if (local_44 == 1.0) break;
      if ((peVar4 == (edict_t *)0x0) || (uVar10 = uVar10 + 1, uVar10 == 2)) goto LAB_00096690;
      fVar3 = (ent->v).origin[2];
      local_6c = fVar5 + (ent->v).origin[0];
      local_68 = fVar6 + (ent->v).origin[1];
    }
    g_groupmask = (ent->v).groupinfo;
    if ((((ent->v).flags & 2) == 0) || (iVar8 = SV_PointContents(&local_40), iVar8 != -1)) {
      (ent->v).origin[0] = local_40;
      (ent->v).origin[1] = local_3c;
      (ent->v).origin[2] = vStack_38;
      goto LAB_00096816;
    }
  }
LAB_00096690:
  SV_LinkEdict(ent,true);
  return false;
}


// SV_StringToUserID  @ 0008ff40
USERID_t * SV_StringToUserID(char *str)

{
  int iVar1;
  int in_GS_OFFSET;
  uint64 uVar2;
  char local_90 [127];
  undefined1 local_11;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&SV_StringToUserID::id,0,0x10);
  uVar2 = CONCAT44(SV_StringToUserID::id.m_SteamID._4_4_,(undefined4)SV_StringToUserID::id.m_SteamID
                  );
  if ((str != (char *)0x0) &&
     (uVar2 = CONCAT44(SV_StringToUserID::id.m_SteamID._4_4_,
                       (undefined4)SV_StringToUserID::id.m_SteamID), *str != '\0')) {
                    /* Unresolved local var: char[128] szTemp@[???]
                       Unresolved local var: char * pszUserID@[???] */
    iVar1 = Q_strnicmp(str,"STEAM_",6);
    if (iVar1 == 0) {
      strncpy(local_90,str + 6,0x7f);
      SV_StringToUserID::id.idtype = 1;
    }
    else {
      strncpy(local_90,str + 6,0x7f);
      SV_StringToUserID::id.idtype = 2;
    }
    local_11 = 0;
    uVar2 = Steam_StringToSteamID(local_90);
  }
  SV_StringToUserID::id.m_SteamID._4_4_ = (undefined4)(uVar2 >> 0x20);
  SV_StringToUserID::id.m_SteamID._0_4_ = (undefined4)uVar2;
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return &SV_StringToUserID::id;
  }
  SV_StringToUserID::id.m_SteamID = uVar2;
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_StudioSetupBones  @ 00076b80
/* WARNING: Type propagation algorithm not settling */

void SV_StudioSetupBones(model_t *pModel,float frame,int sequence,vec_t *angles,vec_t *origin,
                        byte *pcontroller,byte *pblending,int iBone,edict_t *edict)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  studiohdr_t *psVar8;
  studiohdr_t *psVar9;
  int iVar10;
  void *pvVar11;
  uint uVar12;
  int iVar13;
  dmodel_t *pdVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  vec_t vVar19;
  int iVar20;
  vec_t vVar21;
  int iVar22;
  int iVar23;
  char *local_284;
  int local_27c;
  int local_278;
  float local_26c [8];
  float local_24c;
  float local_248;
  float local_244;
  vec_t local_240;
  float local_23c;
  float local_238 [2];
  vec_t local_230;
  float local_22c;
  float local_228;
  float local_224;
  vec_t local_220;
  vec_t local_21c [131];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: float f@[???]
                       Unresolved local var: float s@[???]
                       Unresolved local var: float[8] adj@[???]
                       Unresolved local var: mstudiobone_t * pbones@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: mstudioanim_t * panim@[???]
                       Unresolved local var: float[3][4] bonematrix@[???]
                       Unresolved local var: int[128] chain@[???]
                       Unresolved local var: int chainlength@[???] */
  if ((sequence < 0) || (pstudiohdr->numseq <= sequence)) {
    Con_DPrintf("SV_StudioSetupBones:  sequence %i/%i out of range for model %s\n",sequence,
                pstudiohdr->numseq,pstudiohdr->name);
    local_278 = 0;
  }
  else {
    local_278 = sequence * 0xb0;
  }
  psVar8 = pstudiohdr;
  iVar4 = pstudiohdr->boneindex;
  iVar10 = local_278 + pstudiohdr->seqindex;
                    /* Unresolved local var: mstudioseqgroup_t * pseqgroup@[???]
                       Unresolved local var: cache_user_t * paSequences@[???] */
  iVar13 = *(int *)((int)pstudiohdr->bbmax + iVar10 + 0x20);
  if (iVar13 == 0) {
    local_284 = pstudiohdr->name + *(int *)((int)pstudiohdr->bbmax + iVar10) + -8;
  }
  else {
    iVar20 = pstudiohdr->seqgroupindex;
    pdVar14 = pModel->submodels;
    iVar22 = iVar13;
    if (pdVar14 == (dmodel_t *)0x0) {
      pdVar14 = Mem_Calloc(0x10,4);
      pModel->submodels = pdVar14;
      iVar22 = *(int *)((int)psVar8->bbmax + iVar10 + 0x20);
    }
    pvVar11 = Cache_Check((cache_user_t *)(pdVar14->mins + iVar22));
    if (pvVar11 == (void *)0x0) {
      Con_DPrintf("loading %s\n",psVar8->name + iVar20 + iVar13 * 0x68 + 0x18);
      COM_LoadCacheFile(psVar8->name + iVar20 + iVar13 * 0x68 + 0x18,
                        (cache_user_s *)
                        (pdVar14->mins + *(int *)((int)psVar8->bbmax + iVar10 + 0x20)));
    }
    local_284 = (char *)(*(int *)((int)psVar8->bbmax + iVar10) +
                        (int)pdVar14->mins[*(int *)((int)psVar8->bbmax + iVar10 + 0x20)]);
  }
  if ((iBone < -1) || (uVar12 = pstudiohdr->numbones, (int)uVar12 <= iBone)) {
    iBone = 0;
LAB_00076c66:
    uVar12 = 0;
    do {
      uVar12 = uVar12 + 1;
      (&local_220)[uVar12] = (vec_t)iBone;
      iBone = *(int *)(psVar8->name + iBone * 0x70 + iVar4 + 0x18);
    } while ((vec_t)iBone != -NAN);
LAB_00076c98:
    local_27c = uVar12 - 1;
  }
  else {
    if (iBone != -1) goto LAB_00076c66;
    if ((int)uVar12 < 1) goto LAB_00076c98;
    uVar17 = ((int)local_21c + (uVar12 + 0x3ffffffc) * 4 & 0xf) >> 2;
    if (uVar12 <= uVar17) {
      uVar17 = uVar12;
    }
    uVar15 = uVar12;
    if (((int)uVar12 < 8) || (uVar15 = uVar17, uVar17 != 0)) {
      local_27c = uVar12 - 1;
      *(undefined4 *)((int)local_21c + local_27c * 4) = 0;
      if (uVar15 == 1) {
        vVar19 = 1.4013e-45;
      }
      else {
        local_238[uVar12 + 5] = 1.4013e-45;
        if (uVar15 == 2) {
          vVar19 = 2.8026e-45;
        }
        else {
          local_238[uVar12 + 4] = 2.8026e-45;
          if (uVar15 == 3) {
            vVar19 = 4.2039e-45;
          }
          else {
            local_238[uVar12 + 3] = 4.2039e-45;
            if (uVar15 == 4) {
              vVar19 = 5.60519e-45;
            }
            else {
              local_238[uVar12 + 2] = 5.60519e-45;
              if (uVar15 == 5) {
                vVar19 = 7.00649e-45;
              }
              else {
                local_238[uVar12 + 1] = 7.00649e-45;
                if (uVar15 == 7) {
                  vVar19 = 9.80909e-45;
                  local_238[uVar12] = 8.40779e-45;
                }
                else {
                  vVar19 = 8.40779e-45;
                }
              }
            }
          }
        }
      }
      uVar17 = uVar15;
      if (uVar12 != uVar15) goto LAB_0007722e;
    }
    else {
      vVar19 = 0.0;
LAB_0007722e:
      local_27c = uVar12 - 1;
      uVar15 = ((uVar12 - uVar17) - 4 >> 2) + 1;
      iVar13 = uVar15 * 4;
      if (2 < local_27c - uVar17) {
        iVar20 = (int)vVar19 + 1;
        iVar22 = (int)vVar19 + 2;
        iVar23 = (int)vVar19 + 3;
        uVar16 = 0;
        piVar18 = (int *)((int)local_21c + ((uVar12 + 0x3ffffffc) - uVar17) * 4);
        vVar21 = vVar19;
        do {
          uVar16 = uVar16 + 1;
          *piVar18 = iVar23;
          piVar18[1] = iVar22;
          piVar18[2] = iVar20;
          piVar18[3] = (int)vVar21;
          vVar21 = (vec_t)((int)vVar21 + 4);
          iVar20 = iVar20 + 4;
          iVar22 = iVar22 + 4;
          iVar23 = iVar23 + 4;
          piVar18 = piVar18 + -4;
        } while (uVar16 < uVar15);
        vVar19 = (vec_t)((int)vVar19 + iVar13);
        if (iVar13 == uVar12 - uVar17) goto LAB_00076c9d;
      }
      (&local_220)[uVar12 - (int)vVar19] = vVar19;
      vVar21 = (vec_t)((int)vVar19 + 1);
      if ((int)vVar21 < (int)uVar12) {
        vVar19 = (vec_t)((int)vVar19 + 2);
        (&local_220)[uVar12 - (int)vVar21] = vVar21;
        if ((int)vVar19 < (int)uVar12) {
          (&local_220)[uVar12 - (int)vVar19] = vVar19;
          iVar13 = *(int *)(psVar8->name + iVar10 + 0x30);
          goto joined_r0x000772e5;
        }
      }
    }
  }
LAB_00076c9d:
  iVar13 = *(int *)(psVar8->name + iVar10 + 0x30);
joined_r0x000772e5:
  if (iVar13 < 2) {
    iVar13 = 0;
    fVar1 = 0.0;
  }
  else {
    fVar1 = (float)(iVar13 + -1) * frame * 0.00390625;
    iVar13 = (int)fVar1;
    fVar1 = fVar1 - (float)iVar13;
  }
  R_StudioCalcBoneAdj(0.0,local_26c,pcontroller,pcontroller,'\0');
  iVar20 = local_27c;
  if (-1 < local_27c) {
    do {
      iVar22 = *(int *)((int)local_21c + iVar20 * 4);
      iVar20 = iVar20 + -1;
      R_StudioCalcBoneQuaterion
                (iVar13,fVar1,(mstudiobone_t *)(psVar8->name + iVar22 * 0x70 + iVar4 + -8),
                 (mstudioanim_t *)(local_284 + iVar22 * 0xc),local_26c,
                 SV_StudioSetupBones::q[iVar22]);
      R_StudioCalcBonePosition
                (iVar13,fVar1,(mstudiobone_t *)(psVar8->name + iVar22 * 0x70 + iVar4 + -8),
                 (mstudioanim_t *)(local_284 + iVar22 * 0xc),local_26c,
                 SV_StudioSetupBones::pos[iVar22]);
    } while (iVar20 != -1);
  }
  psVar9 = pstudiohdr;
  if (1 < *(int *)((int)psVar8->bbmin + iVar10 + 8)) {
                    /* Unresolved local var: float b@[???] */
    local_278 = local_278 + pstudiohdr->seqindex;
                    /* Unresolved local var: mstudioseqgroup_t * pseqgroup@[???]
                       Unresolved local var: cache_user_t * paSequences@[???] */
    iVar10 = *(int *)((int)pstudiohdr->bbmax + local_278 + 0x20);
    if (iVar10 == 0) {
      local_284 = pstudiohdr->name + *(int *)((int)pstudiohdr->bbmax + local_278) + -8;
    }
    else {
      iVar20 = pstudiohdr->seqgroupindex;
      pdVar14 = pModel->submodels;
      iVar22 = iVar10;
      if (pdVar14 == (dmodel_t *)0x0) {
        pdVar14 = Mem_Calloc(0x10,4);
        pModel->submodels = pdVar14;
        iVar22 = *(int *)((int)psVar9->bbmax + local_278 + 0x20);
      }
      pvVar11 = Cache_Check((cache_user_t *)(pdVar14->mins + iVar22));
      if (pvVar11 == (void *)0x0) {
        Con_DPrintf("loading %s\n",psVar9->name + iVar20 + iVar10 * 0x68 + 0x18);
        COM_LoadCacheFile(psVar9->name + iVar20 + iVar10 * 0x68 + 0x18,
                          (cache_user_s *)
                          (pdVar14->mins + *(int *)((int)psVar9->bbmax + local_278 + 0x20)));
      }
      local_284 = (char *)(*(int *)((int)psVar9->bbmax + local_278) +
                          (int)pdVar14->mins[*(int *)((int)psVar9->bbmax + local_278 + 0x20)]);
    }
    iVar10 = pstudiohdr->numbones;
    iVar20 = local_27c;
    if (-1 < local_27c) {
      do {
        iVar22 = *(int *)((int)local_21c + iVar20 * 4);
        iVar20 = iVar20 + -1;
        R_StudioCalcBoneQuaterion
                  (iVar13,fVar1,(mstudiobone_t *)(psVar8->name + iVar22 * 0x70 + iVar4 + -8),
                   (mstudioanim_t *)(local_284 + iVar10 * 0xc + iVar22 * 0xc),local_26c,
                   SV_StudioSetupBones::lexical_block_1::q2[iVar22]);
        R_StudioCalcBonePosition
                  (iVar13,fVar1,(mstudiobone_t *)(psVar8->name + iVar22 * 0x70 + iVar4 + -8),
                   (mstudioanim_t *)(local_284 + iVar10 * 0xc + iVar22 * 0xc),local_26c,
                   SV_StudioSetupBones::lexical_block_1::pos2[iVar22]);
      } while (iVar20 != -1);
    }
    R_StudioSlerpBones(SV_StudioSetupBones::q,SV_StudioSetupBones::pos,
                       SV_StudioSetupBones::lexical_block_1::q2,
                       SV_StudioSetupBones::lexical_block_1::pos2,(float)*pblending / 255.0);
  }
  AngleMatrix(angles,rotationmatrix);
  rotationmatrix[0][3] = *origin;
  rotationmatrix[1][3] = origin[1];
  rotationmatrix[2][3] = origin[2];
  if (-1 < local_27c) {
    do {
      while( true ) {
        iVar13 = *(int *)((int)local_21c + local_27c * 4);
        fVar1 = SV_StudioSetupBones::q[iVar13][1];
        fVar5 = (fVar1 + fVar1) * fVar1;
        fVar2 = SV_StudioSetupBones::q[iVar13][2];
        local_238[0] = (fVar2 + fVar2) * fVar2;
        local_24c = (1.0 - fVar5) - local_238[0];
        fVar3 = SV_StudioSetupBones::q[iVar13][0];
        fVar6 = fVar3 + fVar3;
        fVar7 = SV_StudioSetupBones::q[iVar13][3] + SV_StudioSetupBones::q[iVar13][3];
        local_23c = fVar1 * fVar6 + fVar2 * fVar7;
        local_22c = fVar2 * fVar6 - fVar1 * fVar7;
        local_248 = fVar1 * fVar6 - fVar2 * fVar7;
        local_224 = 1.0 - fVar6 * fVar3;
        local_238[0] = local_224 - local_238[0];
        local_238[1] = fVar2 * (fVar1 + fVar1);
        local_228 = local_238[1] + fVar7 * fVar3;
        local_244 = fVar1 * fVar7 + fVar2 * fVar6;
        local_238[1] = local_238[1] - fVar7 * fVar3;
        local_224 = local_224 - fVar5;
        local_240 = SV_StudioSetupBones::pos[iVar13][0];
        local_230 = SV_StudioSetupBones::pos[iVar13][1];
        local_220 = SV_StudioSetupBones::pos[iVar13][2];
        if (*(int *)(psVar8->name + iVar13 * 0x70 + iVar4 + 0x18) != -1) break;
        local_27c = local_27c + -1;
        R_ConcatTransforms(rotationmatrix,(float (*) [4])&local_24c,bonetransform[iVar13]);
        if (local_27c == -1) {
          return;
        }
      }
      local_27c = local_27c + -1;
      R_ConcatTransforms(bonetransform[*(int *)(psVar8->name + iVar13 * 0x70 + iVar4 + 0x18)],
                         (float (*) [4])&local_24c,bonetransform[iVar13]);
    } while (local_27c != -1);
  }
  return;
}


// SV_Submerged  @ 0009c160
float SV_Submerged(edict_t *ent)

{
  float in;
  float fVar1;
  int iVar2;
  float fVar3;
  float local_58;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: float start@[???]
                       Unresolved local var: float end@[???]
                       Unresolved local var: float bottom@[???]
                       Unresolved local var: vec3_t center@[???] */
  iVar2 = (ent->v).waterlevel;
  local_3c = ((ent->v).absmin[0] + (ent->v).absmax[0]) * 0.5;
  local_38 = ((ent->v).absmin[1] + (ent->v).absmax[1]) * 0.5;
  fVar3 = (ent->v).absmax[2];
  local_34 = ((ent->v).absmin[2] + fVar3) * 0.5;
  in = (ent->v).absmin[2] - local_34;
  if (iVar2 == 2) {
LAB_0009c372:
    fVar3 = fVar3 - local_34;
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
    local_58 = fVar3 * 0.5 + 0.0;
    local_28 = local_34 + local_58;
    local_30 = local_3c;
    local_2c = local_38;
    iVar2 = SV_PointContents(&local_30);
    if (iVar2 == -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
      local_18 = local_3c;
      local_14 = local_38;
      fVar1 = local_58 + (fVar3 - local_58) * 0.5;
      local_10 = fVar1 + local_34;
      iVar2 = SV_PointContents(&local_18);
      if (iVar2 == -3) {
        fVar3 = SV_RecursiveWaterLevel(&local_3c,fVar3,fVar1,2);
      }
      else {
        fVar3 = SV_RecursiveWaterLevel(&local_3c,fVar1,local_58,2);
      }
      goto LAB_0009c482;
    }
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
    local_24 = local_3c;
    local_20 = local_38;
    fVar3 = local_58 * 0.5 + 0.0;
    local_1c = fVar3 + local_34;
    iVar2 = SV_PointContents(&local_24);
    if (iVar2 != -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
      local_18 = local_3c;
      local_14 = local_38;
      fVar1 = fVar3 * 0.5 + 0.0;
      local_10 = fVar1 + local_34;
      iVar2 = SV_PointContents(&local_18);
      if (iVar2 == -3) {
        fVar3 = SV_RecursiveWaterLevel(&local_3c,fVar3,fVar1,3);
      }
      else {
        fVar3 = SV_RecursiveWaterLevel(&local_3c,fVar1,0.0,3);
      }
      goto LAB_0009c482;
    }
  }
  else {
    if (iVar2 == 3) {
                    /* Unresolved local var: vec3_t point@[???] */
      g_groupmask = (ent->v).groupinfo;
      local_18 = local_3c;
      local_14 = local_38;
      local_10 = fVar3;
      iVar2 = SV_PointContents(&local_18);
      if (iVar2 == -3) {
        return (ent->v).maxs[2] - (ent->v).mins[2];
      }
      fVar3 = (ent->v).absmax[2];
      goto LAB_0009c372;
    }
    if (iVar2 != 1) {
      return 0.0;
    }
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
    local_58 = in + (0.0 - in) * 0.5;
    local_28 = local_34 + local_58;
    local_30 = local_3c;
    local_2c = local_38;
    iVar2 = SV_PointContents(&local_30);
    if (iVar2 == -3) {
      fVar3 = SV_RecursiveWaterLevel(&local_3c,0.0,local_58,1);
      goto LAB_0009c482;
    }
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
    local_24 = local_3c;
    local_20 = local_38;
    fVar3 = (local_58 - in) * 0.5 + in;
    local_1c = fVar3 + local_34;
    iVar2 = SV_PointContents(&local_24);
    if (iVar2 != -3) {
                    /* Unresolved local var: vec3_t test@[???]
                       Unresolved local var: float offset@[???] */
      local_18 = local_3c;
      local_14 = local_38;
      fVar1 = in + (fVar3 - in) * 0.5;
      local_10 = fVar1 + local_34;
      iVar2 = SV_PointContents(&local_18);
      if (iVar2 == -3) {
        fVar3 = SV_RecursiveWaterLevel(&local_3c,fVar3,fVar1,3);
      }
      else {
        fVar3 = SV_RecursiveWaterLevel(&local_3c,fVar1,in,3);
      }
      goto LAB_0009c482;
    }
  }
  fVar3 = SV_RecursiveWaterLevel(&local_3c,local_58,fVar3,2);
LAB_0009c482:
  return fVar3 - in;
}


// SV_TestEntityPosition  @ 000ab4f0
edict_t * SV_TestEntityPosition(edict_t *ent)

{
  vec_t *maxs;
  vec_t *start;
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  float local_11c;
  float local_118;
  float local_114;
  trace_t local_110;
  undefined4 auStack_d8 [14];
  moveclip_t local_a0;
  
                    /* Unresolved local var: trace_t trace@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
                    /* Unresolved local var: moveclip_t clip@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t worldEndPoint@[???]
                       Unresolved local var: float worldFraction@[???] */
  uVar5 = (ent->v).flags;
  maxs = (ent->v).maxs;
  start = (ent->v).origin;
  Q_memset(&local_a0,0,0x84);
                    /* Unresolved local var: trace_t goodtrace@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t start_l@[???]
                       Unresolved local var: vec3_t end_l@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: model_t * pmodel@[???]
                       Unresolved local var: int numhulls@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int rotated@[???]
                       Unresolved local var: int idx@[???] */
  if (sv.edicts != (edict_t *)0x0) {
    SV_SingleClipMoveToEntity(sv.edicts,start,(ent->v).mins,maxs,start,&local_110);
  }
  uVar4 = 0;
  do {
    *(undefined4 *)((int)auStack_d8 + uVar4) =
         *(undefined4 *)((int)local_110.endpos + (uVar4 - 0x14));
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x38);
  uVar4 = 0;
  do {
    *(undefined4 *)((int)local_a0.trace.endpos + (uVar4 - 0x14)) =
         *(undefined4 *)((int)auStack_d8 + uVar4);
    fVar3 = local_a0.trace.fraction;
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x38);
  if (local_a0.trace.fraction == 0.0) {
    uVar5 = 0;
    do {
      *(undefined4 *)((int)local_110.endpos + (uVar5 - 0x14)) =
           *(undefined4 *)((int)local_a0.trace.endpos + (uVar5 - 0x14));
      uVar5 = uVar5 + 4;
    } while (uVar5 < 0x38);
  }
  else {
    local_a0.end = &local_11c;
    local_11c = local_a0.trace.endpos[0];
    local_a0.mins2[0] = (ent->v).mins[0];
    local_a0.mins2[1] = (ent->v).mins[1];
    local_a0.mins2[2] = (ent->v).mins[2];
    local_a0.maxs2[0] = (ent->v).maxs[0];
    local_a0.maxs2[1] = (ent->v).maxs[1];
    local_a0.maxs2[2] = (ent->v).maxs[2];
                    /* Unresolved local var: int i@[???] */
    fVar1 = (ent->v).origin[0];
    local_a0.monsterClipBrush = uVar5 >> 0x17 & true;
    local_118 = local_a0.trace.endpos[1];
    local_114 = local_a0.trace.endpos[2];
    local_a0.trace.fraction = 1.0;
    local_a0.type = 0;
    local_a0.ignoretrans = 0;
    local_a0.passedict = ent;
    fVar2 = fVar1;
    if (local_a0.trace.endpos[0] <= fVar1) {
      fVar2 = local_a0.trace.endpos[0];
      local_a0.trace.endpos[0] = fVar1;
    }
    local_a0.boxmaxs[0] = local_a0.trace.endpos[0] + local_a0.maxs2[0] + 1.0;
    local_a0.boxmins[0] = (fVar2 + local_a0.mins2[0]) - 1.0;
    fVar1 = (ent->v).origin[1];
    fVar2 = fVar1;
    if (local_a0.trace.endpos[1] <= fVar1) {
      fVar2 = local_a0.trace.endpos[1];
      local_a0.trace.endpos[1] = fVar1;
    }
    local_a0.boxmaxs[1] = local_a0.trace.endpos[1] + local_a0.maxs2[1] + 1.0;
    local_a0.boxmins[1] = (fVar2 + local_a0.mins2[1]) - 1.0;
    fVar1 = (ent->v).origin[2];
    fVar2 = local_a0.trace.endpos[2];
    if (fVar1 < local_a0.trace.endpos[2]) {
      fVar2 = fVar1;
      fVar1 = local_a0.trace.endpos[2];
    }
    local_a0.boxmaxs[2] = fVar1 + local_a0.maxs2[2] + 1.0;
    local_a0.boxmins[2] = (fVar2 + local_a0.mins2[2]) - 1.0;
    local_a0.mins = (ent->v).mins;
    local_a0.maxs = maxs;
    local_a0.start = start;
    SV_ClipToLinks(sv_areanodes,&local_a0);
    gGlobalVariables.trace_ent = local_a0.trace.ent;
    uVar5 = 0;
    local_a0.trace.fraction = fVar3 * local_a0.trace.fraction;
    do {
      *(undefined4 *)((int)local_110.endpos + (uVar5 - 0x14)) =
           *(undefined4 *)((int)local_a0.trace.endpos + (uVar5 - 0x14));
      uVar5 = uVar5 + 4;
    } while (uVar5 < 0x38);
  }
  uVar5 = 0;
  do {
    *(undefined4 *)((int)local_a0.boxmins + uVar5) =
         *(undefined4 *)((int)local_110.endpos + (uVar5 - 0x14));
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x38);
  if (local_a0.boxmins[1] != 0.0) {
    SV_SetGlobalTrace((trace_t *)&local_a0);
    return (edict_t *)local_a0.maxs2[1];
  }
  return (edict_t *)0x0;
}


// SV_TouchLinks  @ 000a9760
void SV_TouchLinks(edict_t *ent,areanode_t *node)

{
  edict_t *ent_00;
  dclipnode_t *pdVar1;
  mplane_t *pmVar2;
  float fVar3;
  short sVar4;
  link_s *plVar5;
  link_s *plVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  link_s *plVar11;
  hull_s *phVar12;
  int iVar13;
  int iVar14;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [6];
  
                    /* Unresolved local var: link_t * l@[???]
                       Unresolved local var: link_t * next@[???]
                       Unresolved local var: edict_t * touch@[???]
                       Unresolved local var: model_t * pModel@[???] */
                    /* Unresolved local var: int contents@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: vec3_t offset@[???]
                       Unresolved local var: vec3_t localPosition@[???] */
  plVar5 = (node->trigger_edicts).next;
joined_r0x000a9785:
  while( true ) {
    do {
      plVar11 = plVar5;
      if (plVar11 == &node->trigger_edicts) {
        iVar14 = node->axis;
        if (iVar14 != -1) {
          fVar3 = node->dist;
          if (fVar3 < (ent->v).absmax[iVar14]) {
            SV_TouchLinks(ent,node->children[0]);
            iVar14 = node->axis;
            fVar3 = node->dist;
          }
          if ((ent->v).absmin[iVar14] < fVar3) {
            SV_TouchLinks(ent,node->children[1]);
            return;
          }
        }
        return;
      }
      ent_00 = (edict_t *)(plVar11 + -1);
      plVar5 = plVar11->next;
    } while (ent_00 == ent);
    plVar6 = plVar11[0x57].prev;
    if ((plVar6 == (link_s *)0x0) || (uVar7 = (ent->v).groupinfo, uVar7 == 0)) break;
    if (g_groupop == 0) goto code_r0x000a97c0;
    if ((g_groupop != 1) || ((uVar7 & (uint)plVar6) == 0)) break;
  }
  goto LAB_000a97d0;
code_r0x000a97c0:
  if ((uVar7 & (uint)plVar6) != 0) {
LAB_000a97d0:
    if (((plVar11[0x30].next == (link_s *)0x1) &&
        (((((ent->v).absmin[0] <= (float)plVar11[0x29].prev &&
           ((ent->v).absmin[1] <= (float)plVar11[0x29].next)) &&
          ((ent->v).absmin[2] <= (float)plVar11[0x2a].prev)) &&
         (((float)plVar11[0x27].next <= (ent->v).absmax[0] &&
          ((float)plVar11[0x28].prev <= (ent->v).absmax[1])))))) &&
       ((float)plVar11[0x28].next <= (ent->v).absmax[2])) {
      if ((sv.models[(int)plVar11[0x25].next] != (model_s *)0x0) &&
         (sv.models[(int)plVar11[0x25].next]->type == mod_brush)) {
        phVar12 = SV_HullForBsp(ent_00,(ent->v).mins,(ent->v).maxs,&local_34);
        fVar3 = (ent->v).origin[0] - local_34;
        iVar14 = phVar12->firstclipnode;
        fVar8 = (ent->v).origin[1] - local_30;
        local_28[0] = fVar3;
        fVar9 = (ent->v).origin[2] - local_2c;
        local_28[1] = fVar8;
        local_28[2] = fVar9;
        iVar13 = iVar14;
        if (-1 < iVar14) {
          while( true ) {
            if ((iVar14 < iVar13) || (phVar12->lastclipnode < iVar14)) {
              Sys_Error("SV_HullPointContents: bad node number");
            }
            pdVar1 = phVar12->clipnodes + iVar14;
            pmVar2 = phVar12->planes + pdVar1->planenum;
            if (pmVar2->type < 3) {
              fVar10 = local_28[pmVar2->type] - pmVar2->dist;
            }
            else {
              fVar10 = (fVar9 * pmVar2->normal[2] +
                       fVar8 * pmVar2->normal[1] + fVar3 * pmVar2->normal[0]) - pmVar2->dist;
            }
            if (fVar10 < 0.0) {
              sVar4 = pdVar1->children[1];
            }
            else {
              sVar4 = pdVar1->children[0];
            }
            iVar14 = (int)sVar4;
            if (iVar14 < 0) break;
            iVar13 = phVar12->firstclipnode;
          }
        }
        if (iVar14 != -2) goto joined_r0x000a9785;
      }
      gGlobalVariables.time = (float)sv.time;
      (*gEntityInterface.pfnTouch)(ent_00,ent);
    }
  }
  goto joined_r0x000a9785;
}


// SV_Trace_Toss  @ 0009e400
trace_t * SV_Trace_Toss(trace_t *__return_storage_ptr__,edict_t *ent,edict_t *ignore)

{
  vec_t *veca;
  float fVar1;
  float fVar2;
  double dVar3;
  int in_GS_OFFSET;
  float local_35c;
  float local_358;
  float local_354;
  float local_350;
  float local_34c;
  float local_348;
  edict_t local_344;
  int local_20;
  
                    /* Unresolved local var: edict_t tempent@[???]
                       Unresolved local var: edict_t * tent@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: vec3_t move@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: double save_frametime@[???] */
  dVar3 = host_frametime;
  veca = local_344.v.angles;
  host_frametime = 0.05;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memcpy(&local_344,ent,0x324);
  do {
    SV_CheckVelocity(&local_344);
                    /* Unresolved local var: float ent_gravity@[???] */
    fVar1 = 1.0;
    if (local_344.v.gravity != 0.0) {
      fVar1 = local_344.v.gravity;
    }
    fVar2 = (float)host_frametime * local_344.v.basevelocity[2];
    local_344.v.basevelocity[2] = 0.0;
    local_344.v.velocity[2] =
         fVar2 + (local_344.v.velocity[2] - fVar1 * sv_gravity.value * (float)host_frametime);
    SV_CheckVelocity(&local_344);
    VectorMA(veca,(float)host_frametime,local_344.v.avelocity,veca);
    VectorScale(local_344.v.velocity,(float)host_frametime,&local_35c);
    local_350 = local_344.v.origin[0] + local_35c;
    local_34c = local_344.v.origin[1] + local_358;
    local_348 = local_344.v.origin[2] + local_354;
    SV_Move(__return_storage_ptr__,local_344.v.origin,local_344.v.mins,local_344.v.maxs,&local_350,0
            ,&local_344,false);
    local_344.v.origin[0] = __return_storage_ptr__->endpos[0];
    local_344.v.origin[1] = __return_storage_ptr__->endpos[1];
    local_344.v.origin[2] = __return_storage_ptr__->endpos[2];
  } while ((__return_storage_ptr__->ent == ignore) ||
          (__return_storage_ptr__->ent == (edict_t *)0x0));
  host_frametime = dVar3;
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return __return_storage_ptr__;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_TransferConsistencyInfo  @ 000a0610
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SV_TransferConsistencyInfo(void)

{
  char *s2;
  int iVar1;
  int iVar2;
  consistency_t *pcVar3;
  resource_t *s1;
  uchar *data;
  int in_GS_OFFSET;
  float *src;
  int local_148;
  int local_144;
  float local_13c [3];
  float local_130 [3];
  char local_124 [259];
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: resource_t * r@[???]
                       Unresolved local var: char[260] filename@[???]
                       Unresolved local var: consistency_t * pc@[???]
                       Unresolved local var: vec3_t mins@[???]
                       Unresolved local var: vec3_t maxs@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (sv.num_resources < 1) {
    local_144 = 0;
  }
  else {
    data = sv.resourcelist[0].rguc_reserved;
    local_148 = 0;
    local_144 = 0;
    iVar1 = sv.num_resources;
    do {
      s1 = (resource_t *)(data + -0x5e);
                    /* Unresolved local var: int i@[???] */
      if (((s1 != (resource_t *)0x0) && (-1 < (char)data[-0x12])) &&
         (sv.consistency_list[0].filename != (char *)0x0)) {
        pcVar3 = sv.consistency_list;
        iVar2 = 0;
        s2 = sv.consistency_list[0].filename;
        do {
          pcVar3 = pcVar3 + 1;
          iVar1 = Q_stricmp((char *)s1,s2);
          if (iVar1 == 0) {
            data[-0x12] = data[-0x12] | 0x80;
            if (*(resourcetype_t *)(data + -0x1e) == t_sound) {
              __snprintf_chk(local_124,0x104,1,0x104,"sound/%s",s1);
            }
            else {
              Q_strncpy(local_124,(char *)s1,0x103);
              local_21 = 0;
            }
            MD5_Hash_File(data + -0x11,local_124,0,0,(uint *)0x0);
            if (*(resourcetype_t *)(data + -0x1e) == t_model) {
              iVar1 = sv.consistency_list[iVar2].check_type;
              if (iVar1 == 1) {
                iVar1 = R_GetStudioBounds(local_124,local_13c,local_130);
                if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
                  Host_Error("Server unable to get bounds for %s\n",local_124);
                }
                Q_memcpy(data + 1,local_13c,0xc);
                src = local_130;
              }
              else {
                if ((iVar1 < 1) || (3 < iVar1)) goto LAB_000a0705;
                src = sv.consistency_list[iVar2].maxs;
                Q_memcpy(data + 1,sv.consistency_list[iVar2].mins,0xc);
              }
              Q_memcpy(data + 0xd,src,0xc);
              *data = (uchar)sv.consistency_list[iVar2].check_type;
              COM_Munge(data,0x20,svs.spawncount);
            }
LAB_000a0705:
            local_144 = local_144 + 1;
            iVar1 = sv.num_resources;
            break;
          }
          s2 = pcVar3->filename;
          iVar2 = iVar2 + 1;
          iVar1 = sv.num_resources;
        } while (s2 != (char *)0x0);
      }
      local_148 = local_148 + 1;
      data = data + 0x88;
    } while (local_148 < iVar1);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_144;
}


// SV_UnlagCheckTeleport  @ 000a2950
int SV_UnlagCheckTeleport(vec_t *v1,vec_t *v2)

{
                    /* Unresolved local var: int i@[???] */
  if ((ABS(*v1 - *v2) <= 128.0) && (ABS(v1[1] - v2[1]) <= 128.0)) {
    return (uint)(128.0 < ABS(v1[2] - v2[2]));
  }
  return 1;
}


// SV_UnlinkEdict  @ 000a9730
void SV_UnlinkEdict(edict_t *ent)

{
  link_s *plVar1;
  
  plVar1 = (ent->area).prev;
  if (plVar1 != (link_s *)0x0) {
    ((ent->area).next)->prev = plVar1;
    ((ent->area).prev)->next = (ent->area).next;
    (ent->area).next = (link_s *)0x0;
    (ent->area).prev = (link_s *)0x0;
  }
  return;
}


// SV_UpdateToReliableMessages  @ 0008cd20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_UpdateToReliableMessages(void)

{
  _UserMsg *p_Var1;
  float fVar2;
  client_s *cl;
  int iVar3;
  UserMsg *pUVar4;
  sizebuf_t *psVar5;
  int iVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: client_t * client@[???] */
  iVar6 = 0;
  host_client = svs.clients;
  cl = svs.clients;
  iVar3 = svs.maxclients;
  if (0 < svs.maxclients) {
    do {
      host_client = cl;
      if (cl->edict != (edict_t *)0x0) {
        if ((cl->sendinfo != false) && (fVar2 = (float)realtime, cl->sendinfo_time <= fVar2)) {
          cl->sendinfo = false;
          cl->sendinfo_time = fVar2 + 1.0;
          SV_ExtractFromUserinfo(cl);
          SV_FullClientUpdate(host_client,&sv.reliable_datagram);
        }
        iVar3 = svs.maxclients;
        if ((host_client->fakeclient == false) &&
           ((host_client->active != false || (host_client->connected != false)))) {
          psVar5 = &(host_client->netchan).message;
          for (p_Var1 = sv_gpNewUserMsgs; svs.maxclients = iVar3, p_Var1 != (UserMsg *)0x0;
              p_Var1 = p_Var1->next) {
                    /* Unresolved local var: UserMsg * pMsg@[???] */
            MSG_WriteByte(psVar5,0x27);
            MSG_WriteByte(psVar5,p_Var1->iMsg);
            MSG_WriteByte(psVar5,p_Var1->iSize);
            MSG_WriteLong(psVar5,*(int *)p_Var1->szName);
            MSG_WriteLong(psVar5,*(int *)(p_Var1->szName + 4));
            MSG_WriteLong(psVar5,*(int *)(p_Var1->szName + 8));
            MSG_WriteLong(psVar5,*(int *)(p_Var1->szName + 0xc));
            iVar3 = svs.maxclients;
          }
        }
      }
      iVar6 = iVar6 + 1;
      cl = host_client + 1;
      host_client = cl;
    } while (iVar6 < iVar3);
  }
  if (sv_gpNewUserMsgs != (UserMsg *)0x0) {
    p_Var1 = sv_gpUserMsgs;
    pUVar4 = sv_gpNewUserMsgs;
    if (sv_gpUserMsgs != (UserMsg *)0x0) {
      do {
        pUVar4 = p_Var1;
        p_Var1 = pUVar4->next;
      } while (p_Var1 != (_UserMsg *)0x0);
      pUVar4->next = sv_gpNewUserMsgs;
      pUVar4 = sv_gpUserMsgs;
    }
    sv_gpUserMsgs = pUVar4;
    sv_gpNewUserMsgs = (UserMsg *)0x0;
  }
  if (((byte)sv.datagram.flags & 2) != 0) {
    Con_DPrintf("sv.datagram overflowed!\n");
    SZ_Clear(&sv.datagram);
  }
  if (((byte)sv.spectator.flags & 2) != 0) {
    Con_DPrintf("sv.spectator overflowed!\n");
    SZ_Clear(&sv.spectator);
  }
  iVar6 = 0;
  psVar5 = &(svs.clients)->datagram;
  iVar3 = svs.maxclients;
  if (0 < svs.maxclients) {
    do {
      if ((*(int *)&psVar5[-6].flags == 0) && (psVar5[-0x29e].maxsize != 0)) {
        if (*(int *)&psVar5[-0x297].flags + sv.reliable_datagram.cursize <
            (int)psVar5[-0x297].buffername) {
          SZ_Write((sizebuf_t *)&psVar5[-0x298].data,sv.reliable_datagram.data,
                   sv.reliable_datagram.cursize);
          if (psVar5->maxsize <= psVar5->cursize + sv.datagram.cursize) goto LAB_0008cf6d;
LAB_0008ced2:
          SZ_Write(psVar5,sv.datagram.data,sv.datagram.cursize);
        }
        else {
          Netchan_CreateFragments(true,(netchan_t *)(psVar5 + -0x29c),&sv.reliable_datagram);
          if (psVar5->cursize + sv.datagram.cursize < psVar5->maxsize) goto LAB_0008ced2;
LAB_0008cf6d:
          Con_DPrintf("Warning:  Ignoring unreliable datagram for %s, would overflow\n",
                      &psVar5[0x25a].flags);
        }
        iVar3 = svs.maxclients;
        if ((psVar5[-6].data != (byte *)0x0) &&
           (psVar5->cursize + sv.spectator.cursize < psVar5->maxsize)) {
          SZ_Write(psVar5,sv.spectator.data,sv.spectator.cursize);
          iVar3 = svs.maxclients;
        }
      }
      iVar6 = iVar6 + 1;
      psVar5 = (sizebuf_t *)&psVar5[0x51e].cursize;
    } while (iVar6 < iVar3);
  }
  SZ_Clear(&sv.reliable_datagram);
  SZ_Clear(&sv.datagram);
  SZ_Clear(&sv.spectator);
  return;
}


// SV_UploadComplete  @ 0009f030
qboolean SV_UploadComplete(client_t *cl)

{
  if ((cl->resourcesneeded).pNext == &cl->resourcesneeded) {
    SV_RegisterResources();
    SV_PropagateCustomizations();
    if (sv_allow_upload.value != 0.0) {
      Con_DPrintf("Custom resource propagation complete.\n");
    }
    cl->uploaddoneregistering = true;
    return true;
  }
  return false;
}


// SV_User_f  @ 00080560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_User_f(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  client_s *pcVar5;
  int iVar6;
  
                    /* Unresolved local var: int uid@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (sv.active == false) {
    Con_Printf("Can\'t \'user\', not running a server\n");
    return;
  }
  iVar1 = Cmd_Argc();
  if (iVar1 != 2) {
    Con_Printf("Usage: user <username / userid>\n");
    return;
  }
                    /* Unresolved local var: int uid@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_t * cl@[???] */
  iVar6 = 0;
  pcVar2 = Cmd_Argv(1);
  iVar3 = Q_atoi(pcVar2);
  iVar1 = svs.maxclients;
  pcVar5 = svs.clients;
  if (0 < svs.maxclients) {
    do {
      if ((((pcVar5->active != false) || (pcVar5->spawned != false)) || (pcVar5->connected != false)
          ) && ((pcVar5->fakeclient == false && (pcVar5->name[0] != '\0')))) {
        if (iVar3 == pcVar5->userid) {
LAB_00080658:
          Info_Print(pcVar5->userinfo);
          return;
        }
        pcVar2 = Cmd_Argv(1);
        iVar4 = Q_strcmp(pcVar5->name,pcVar2);
        iVar1 = svs.maxclients;
        if (iVar4 == 0) goto LAB_00080658;
      }
      iVar6 = iVar6 + 1;
      pcVar5 = pcVar5 + 1;
    } while (iVar6 < iVar1);
  }
  Con_Printf("User not in server.\n");
  return;
}


// SV_Users_f  @ 00092cf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_Users_f(void)

{
  int iVar1;
  char *pcVar2;
  client_s *pcVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: client_t * cl@[???] */
  if (sv.active == false) {
    Con_Printf("Can\'t \'users\', not running a server\n");
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???]
                       Unresolved local var: client_t * cl@[???] */
  Con_Printf("userid : uniqueid : name\n");
  Con_Printf("------ : ---------: ----\n");
  if (svs.maxclients < 1) {
    iVar5 = 0;
  }
  else {
    iVar4 = 0;
    iVar5 = 0;
    iVar1 = svs.maxclients;
    pcVar3 = svs.clients;
    do {
      while ((((pcVar3->active == false && (pcVar3->spawned == false)) &&
              (pcVar3->connected == false)) ||
             ((pcVar3->fakeclient != false || (pcVar3->name[0] == '\0'))))) {
        iVar4 = iVar4 + 1;
        pcVar3 = pcVar3 + 1;
        if (iVar1 <= iVar4) goto LAB_00092e06;
      }
      SV_GetClientIDString::idstr._0_4_ = SV_GetClientIDString::idstr._0_4_ & 0xffffff00;
      if (pcVar3 != (client_s *)0x0) {
        if (((pcVar3->netchan).remote_address.type == NA_LOOPBACK) &&
           ((pcVar3->network_userid).idtype == 2)) {
          builtin_strncpy(SV_GetClientIDString::idstr,"VALVE_ID_LOOPBACK",0x12);
        }
        else {
                    /* Unresolved local var: USERID_t * id@[???] */
          pcVar2 = SV_GetIDString(&pcVar3->network_userid);
          snprintf(SV_GetClientIDString::idstr,0x3f,"%s",pcVar2);
        }
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 1;
      Con_Printf("%6i : %s : %s\n",pcVar3->userid,SV_GetClientIDString::idstr,pcVar3->name);
      iVar1 = svs.maxclients;
      pcVar3 = pcVar3 + 1;
    } while (iVar4 < svs.maxclients);
  }
LAB_00092e06:
  Con_Printf("%i users\n",iVar5);
  return;
}


// SV_ValidClientMulticast  @ 00082aa0
qboolean SV_ValidClientMulticast(client_t *client,int soundLeaf,int to)

{
  qboolean qVar1;
  byte *pbVar2;
  mleaf_t *pmVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  
                    /* Unresolved local var: byte * mask@[???]
                       Unresolved local var: int destination@[???] */
  qVar1 = Host_IsSinglePlayerGame();
  if ((qVar1 == false) && (client->proxy == false)) {
    uVar6 = to & 0xffffff7f;
    if (uVar6 == 2) {
      pbVar2 = CM_LeafPVS(soundLeaf);
    }
    else {
      if (uVar6 != 4) {
        if (uVar6 == 1) {
          return true;
        }
        Con_Printf("MULTICAST: Error %d!\n",to);
        return false;
      }
      pbVar2 = CM_LeafPAS(soundLeaf);
    }
    if (pbVar2 != (byte *)0x0) {
                    /* Unresolved local var: int bitNumber@[???]
                       Unresolved local var: mleaf_t * pLeaf@[???] */
      pmVar3 = Mod_PointInLeaf((client->edict->v).origin,sv.worldmodel);
      if (pmVar3 == (mleaf_t *)0x0) {
        bVar4 = 7;
        iVar5 = -1;
      }
      else {
        iVar5 = ((int)pmVar3 - (int)(sv.worldmodel)->leafs >> 4) * -0x55555555 + -1;
        bVar4 = (byte)iVar5 & 7;
        iVar5 = iVar5 >> 3;
      }
      return (int)(uint)pbVar2[iVar5] >> bVar4 & true;
    }
  }
  return true;
}


// SV_ValidateClientCommand  @ 000a1da0
int SV_ValidateClientCommand(char *pszCommand)

{
  command_t cVar1;
  command_t *pcVar2;
  int iVar3;
  
                    /* Unresolved local var: char * p@[???]
                       Unresolved local var: int i@[???] */
  pcVar2 = clcommands;
  COM_Parse(pszCommand);
  cVar1 = clcommands[0];
  while( true ) {
    pcVar2 = pcVar2 + 1;
    if (cVar1.command == (char *)0x0) {
      return 0;
    }
    iVar3 = Q_strcasecmp(com_token,cVar1.command);
    if (iVar3 == 0) break;
    cVar1.command = pcVar2->command;
  }
  return 1;
}


// SV_WriteClientdataToMessage  @ 000845b0
void SV_WriteClientdataToMessage(client_t *client,sizebuf_t *msg)

{
  clientdata_t *to;
  vec_t *pvVar1;
  edict_s *peVar2;
  client_frame_t *pcVar3;
  double dVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  weapon_data_t *to_00;
  weapon_data_t *from;
  client_frame_t *pcVar8;
  clientdata_t *from_00;
  uint32 data;
  int in_GS_OFFSET;
  weapon_data_t local_254;
  clientdata_t local_1fc;
  int local_20;
  
                    /* Unresolved local var: int bits@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: clientdata_t * from@[???]
                       Unresolved local var: clientdata_t * to@[???]
                       Unresolved local var: clientdata_t baseline@[???]
                       Unresolved local var: qboolean force@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(&local_1fc,0,0x1dc);
  dVar4 = realtime;
  peVar2 = client->edict;
  pcVar8 = client->frames + ((client->netchan).outgoing_sequence & SV_UPDATE_MASK);
  pcVar8->ping_time = -1.0;
  pcVar8->senttime = dVar4;
  if (client->chokecount != 0) {
    MSG_WriteByte(msg,0x2a);
    client->chokecount = 0;
  }
  iVar7 = (peVar2->v).fixangle;
  if (iVar7 != 0) {
    if (iVar7 == 2) {
      MSG_WriteByte(msg,0x26);
      MSG_WriteHiresAngle(msg,(peVar2->v).avelocity[1]);
      (peVar2->v).avelocity[1] = 0.0;
    }
    else {
      iVar7 = 0;
      MSG_WriteByte(msg,10);
      do {
        pvVar1 = (peVar2->v).angles + iVar7;
        iVar7 = iVar7 + 1;
        MSG_WriteHiresAngle(msg,*pvVar1);
      } while (iVar7 != 3);
    }
    (peVar2->v).fixangle = 0;
  }
  to = &pcVar8->clientdata;
  Q_memset(to,0,0x1dc);
  (*gEntityInterface.pfnUpdateClientData)(peVar2,SUB14(host_client->lw != 0,0),to);
  MSG_WriteByte(msg,0xf);
  if (client->proxy == false) {
    MSG_StartBitWriting(msg);
    if (host_client->delta_sequence == 0xffffffff) {
      from_00 = &local_1fc;
      MSG_WriteBits(0,1);
    }
    else {
      pcVar3 = host_client->frames;
      uVar5 = host_client->delta_sequence & SV_UPDATE_MASK;
      MSG_WriteBits(1,1);
      from_00 = &pcVar3[uVar5].clientdata;
      MSG_WriteBits(host_client->delta_sequence,8);
    }
    DELTA_WriteDelta((uchar *)from_00,(uchar *)to,true,g_pclientdelta,(_func_void *)0x0);
    if (host_client->lw != 0) {
                    /* Unresolved local var: weapon_data_t * fdata@[???]
                       Unresolved local var: weapon_data_t * tdata@[???]
                       Unresolved local var: weapon_data_t wbaseline@[???] */
      to_00 = pcVar8->weapondata;
      Q_memset(&local_254,0,0x58);
      iVar7 = (*gEntityInterface.pfnGetWeaponData)(host_client->edict,to_00);
      if (iVar7 != 0) {
        iVar7 = 0x240 - (int)to_00;
        data = 0;
        while( true ) {
          if (host_client->delta_sequence == 0xffffffff) {
            from = &local_254;
          }
          else {
            from = host_client->frames[host_client->delta_sequence & SV_UPDATE_MASK].weapondata +
                   data;
          }
          iVar6 = DELTA_CheckDelta((uchar *)from,(uchar *)to_00,g_pweapondelta);
          if (iVar6 != 0) {
            MSG_WriteBits(1,1);
            MSG_WriteBits(data,6);
            DELTA_WriteDelta((uchar *)from,(uchar *)to_00,true,g_pweapondelta,(_func_void *)0x0);
          }
          data = data + 1;
          if (data == 0x40) break;
          to_00 = (weapon_data_t *)((uchar *)((int)to_00 + iVar7) + (int)pcVar8);
        }
      }
    }
    MSG_WriteBits(0,1);
    MSG_EndBitWriting(msg);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_WriteDeltaDescriptionsToClient  @ 00083240
void SV_WriteDeltaDescriptionsToClient(sizebuf_t *msg)

{
  uint32 data;
  delta_info_s *pdVar1;
  int iVar2;
  uint32 uVar3;
  int iVar4;
  int in_GS_OFFSET;
  uchar local_64 [68];
  int local_20;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: delta_info_t * p@[???]
                       Unresolved local var: delta_description_t nulldesc@[???]
                       Unresolved local var: delta_description_t * from@[???]
                       Unresolved local var: delta_description_t * to@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_memset(local_64,0,0x44);
  for (pdVar1 = g_sv_delta; pdVar1 != (delta_info_t *)0x0; pdVar1 = pdVar1->next) {
    MSG_WriteByte(msg,0xe);
    MSG_WriteString(msg,pdVar1->name);
    data = pdVar1->delta->fieldCount;
    uVar3 = 0;
    MSG_StartBitWriting(msg);
    MSG_WriteBits(data,0x10);
    if (0 < (int)data) {
      iVar4 = 0;
      do {
        uVar3 = uVar3 + 1;
        iVar2 = iVar4 + -4;
        iVar4 = iVar4 + 0x44;
        DELTA_WriteDelta(local_64,(uchar *)(pdVar1->delta->pdd->fieldName + iVar2),true,&g_MetaDelta
                         ,(_func_void *)0x0);
      } while (data != uVar3);
    }
    MSG_EndBitWriting(msg);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_WriteDeltaHeader  @ 0008a960
void SV_WriteDeltaHeader(int num,qboolean remove,qboolean custom,int *numbase,qboolean newbl,
                        int newblindex,qboolean full,int offset)

{
  uint32 data;
  
                    /* Unresolved local var: int delta@[???] */
  data = num - *numbase;
  if (full == false) {
    MSG_WriteBits((uint)(remove != false),1);
    if (0x3e < data - 1) goto LAB_0008a9d7;
LAB_0008aa3b:
    MSG_WriteBits(0,1);
    MSG_WriteBits(data,6);
    *numbase = num;
  }
  else {
    if (data == 1) {
      MSG_WriteBits(1,1);
    }
    else {
      MSG_WriteBits(0,1);
      if (data - 1 < 0x3f) goto LAB_0008aa3b;
LAB_0008a9d7:
      MSG_WriteBits(1,1);
      MSG_WriteBits(num,0xb);
    }
    *numbase = num;
  }
  if (remove == false) {
    MSG_WriteBits((uint)(custom != false),1);
    if ((sv.instance_baselines)->number != 0) {
      if (newbl != false) {
        MSG_WriteBits(1,1);
        remove = 6;
        num = newblindex;
        goto LAB_0008aac0;
      }
      MSG_WriteBits(0,1);
    }
    if ((full != false) && (newbl == false)) {
      if (offset == 0) {
        remove = true;
        num = 0;
      }
      else {
        MSG_WriteBits(1,1);
        num = offset;
        remove = 6;
      }
LAB_0008aac0:
      MSG_WriteBits(num,remove);
      return;
    }
  }
  return;
}


// SV_WriteEntitiesToClient  @ 0008c150
void SV_WriteEntitiesToClient(client_t *client,sizebuf_t *msg)

{
  packet_entities_t *to;
  int iVar1;
  uchar *puVar2;
  ushort uVar3;
  int iVar4;
  entity_state_s *peVar5;
  uchar *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  client_frame_t *pcVar10;
  int iVar11;
  uchar *local_24;
  uchar *local_20 [4];
  
                    /* Unresolved local var: packet_entities_t * pack@[???]
                       Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: client_frame_t * frame@[???]
                       Unresolved local var: qboolean sendping@[???]
                       Unresolved local var: int e@[???]
                       Unresolved local var: byte * pvs@[???]
                       Unresolved local var: byte * pas@[???]
                       Unresolved local var: int ev_count@[???]
                       Unresolved local var: int skipents@[???]
                       Unresolved local var: byte * pSet@[???] */
  local_24 = (uchar *)0x0;
  local_20[0] = (uchar *)0x0;
  pcVar10 = client->frames + ((client->netchan).outgoing_sequence & SV_UPDATE_MASK);
  (*gEntityInterface.pfnSetupVisibility)(client->pViewEntity,client->edict,&local_24,local_20);
  puVar2 = local_24;
  to = &pcVar10->entities;
  if (client->proxy == false) {
    uVar3 = (client->lastcmd).buttons & 0x8000;
  }
  else if (realtime < client->nextping) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
    client->nextping = realtime + 2.0;
  }
  iVar1 = client->lw;
                    /* Unresolved local var: packet_entities_t * pack@[???]
                       Unresolved local var: int allocatedslots@[???] */
  if ((pcVar10 != (client_frame_t *)0x0) &&
     ((pcVar10->entities).num_entities = 0, (pcVar10->entities).entities == (entity_state_s *)0x0))
  {
                    /* Unresolved local var: packet_entities_t * pack@[???]
                       Unresolved local var: int allocatedslots@[???] */
    peVar5 = Mem_ZeroMalloc(0x55000);
    (pcVar10->entities).entities = peVar5;
  }
  (pcVar10->entities).num_entities = 0;
  if (1 < sv.num_edicts) {
    iVar9 = 0x324;
    iVar8 = 1;
    iVar11 = 0;
    iVar4 = sv.num_edicts;
    do {
      if ((iVar8 < 1) || (svs.maxclients < iVar8)) {
        iVar4 = (pcVar10->entities).num_entities;
        iVar7 = 0;
joined_r0x0008c26b:
        if (0x3ff < iVar4) {
          Con_DPrintf("Too many entities in visible packet list.\n");
          break;
        }
        iVar7 = (*gEntityInterface.pfnAddToFullPack)
                          ((pcVar10->entities).entities + iVar4,iVar8,
                           (edict_t *)((int)(sv.edicts)->leafnums + iVar9 + -0x18),
                           host_client->edict,SUB14(iVar1 != 0,0),iVar7,puVar2);
        iVar4 = sv.num_edicts;
        if (iVar7 != 0) {
          (pcVar10->entities).num_entities = (pcVar10->entities).num_entities + 1;
          iVar4 = sv.num_edicts;
        }
      }
      else {
                    /* Unresolved local var: int player@[???]
                       Unresolved local var: client_t * client@[???]
                       Unresolved local var: edict_t * ent@[???]
                       Unresolved local var: entity_state_t * state@[???] */
        puVar6 = ((svs.clients)->netchan).remote_address.ip + iVar11 + -0x24;
        if (((*(int *)puVar6 != 0) || (*(int *)(puVar6 + 4) != 0)) &&
           (iVar7 = 1, *(int *)(puVar6 + 0x33dc) == 0)) {
          iVar4 = (pcVar10->entities).num_entities;
          goto joined_r0x0008c26b;
        }
      }
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 0x324;
      iVar11 = iVar11 + 0x6668;
    } while (iVar8 < iVar4);
  }
  if (client->delta_sequence == -1) {
    SV_CreatePacketEntities(sv_packet_nodelta,client,to,msg);
  }
  else {
    SV_CreatePacketEntities(sv_packet_delta,client,to,msg);
  }
  SV_EmitEvents(client,to,msg);
  if (uVar3 != 0) {
    SV_EmitPings(client,msg);
  }
  return;
}


// SV_WriteIP_f  @ 00080700
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_WriteIP_f(void)

{
  uint uVar1;
  FileHandle_t file;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int in_GS_OFFSET;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: byte[4] b@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float banTime@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  builtin_strncpy(local_114,"listip.cfg",0xb);
  Con_Printf("Writing %s.\n",local_114);
  file = FS_Open(local_114,"wb");
  if (file == (FileHandle_t)0x0) {
    Con_Printf("Couldn\'t open %s\n",local_114);
  }
  else {
    if (0 < numipfilters) {
      puVar3 = &ipfilters[0].compare;
      iVar4 = 0;
      iVar2 = numipfilters;
      do {
        while (uVar1 = *puVar3, (float)puVar3[2] == 0.0) {
          iVar4 = iVar4 + 1;
          puVar3 = puVar3 + 4;
          FS_FPrintf(file,"addip 0.0 %i.%i.%i.%i\n",uVar1 & 0xff,uVar1 >> 8 & 0xff,
                     uVar1 >> 0x10 & 0xff,uVar1 >> 0x18);
          iVar2 = numipfilters;
          if (numipfilters <= iVar4) goto LAB_000807de;
        }
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 4;
      } while (iVar4 < iVar2);
    }
LAB_000807de:
    FS_Close(file);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_WriteId_f  @ 00092480
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SV_WriteId_f(void)

{
  char *pcVar1;
  int iVar2;
  FileHandle_t file;
  userfilter_t *id;
  int iVar3;
  int in_GS_OFFSET;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: FILE * f@[???]
                       Unresolved local var: char[260] name@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float banTime@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((bannedcfgfile.string == (char *)0x0) || (*bannedcfgfile.string == '\0')) {
    Con_Printf("Couldn\'t open banned config file, no file name specified.\n");
  }
  else if ((((*bannedcfgfile.string == '/') ||
            (pcVar1 = Q_strstr(bannedcfgfile.string,":"), pcVar1 != (char *)0x0)) ||
           (pcVar1 = Q_strstr(bannedcfgfile.string,".."), pcVar1 != (char *)0x0)) ||
          (pcVar1 = Q_strstr(bannedcfgfile.string,"\\"), pcVar1 != (char *)0x0)) {
    Con_Printf("Couldn\'t open %s (contains illegal characters).\n",bannedcfgfile.string);
  }
  else {
    Q_strncpy(local_114,bannedcfgfile.string,0xff);
    COM_DefaultExtension(local_114,".cfg");
    pcVar1 = COM_LastFileExtension(local_114);
    iVar2 = Q_strcmp(pcVar1,"cfg");
    if (iVar2 == 0) {
      Con_Printf("Writing %s.\n",local_114);
      file = FS_Open(local_114,"wt");
      if (file == (FileHandle_t)0x0) {
        Con_Printf("Couldn\'t open %s\n",local_114);
      }
      else {
        iVar3 = 0;
        id = userfilters;
        iVar2 = numuserfilters;
        if (0 < numuserfilters) {
          do {
            if (id->banTime == 0.0) {
              pcVar1 = SV_GetIDString(&id->userid);
              FS_FPrintf(file,"banid 0.0 %s\n",pcVar1);
              iVar2 = numuserfilters;
            }
            iVar3 = iVar3 + 1;
            id = id + 1;
          } while (iVar3 < iVar2);
        }
        FS_Close(file);
      }
    }
    else {
      Con_Printf("Couldn\'t open %s (wrong file extension, must be .cfg).\n",local_114);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// SV_WriteMovevarsToClient  @ 00082fe0
void SV_WriteMovevarsToClient(sizebuf_t *message)

{
  MSG_WriteByte(message,0x2c);
  MSG_WriteFloat(message,movevars.gravity);
  MSG_WriteFloat(message,movevars.stopspeed);
  MSG_WriteFloat(message,movevars.maxspeed);
  MSG_WriteFloat(message,movevars.spectatormaxspeed);
  MSG_WriteFloat(message,movevars.accelerate);
  MSG_WriteFloat(message,movevars.airaccelerate);
  MSG_WriteFloat(message,movevars.wateraccelerate);
  MSG_WriteFloat(message,movevars.friction);
  MSG_WriteFloat(message,movevars.edgefriction);
  MSG_WriteFloat(message,movevars.waterfriction);
  MSG_WriteFloat(message,movevars.entgravity);
  MSG_WriteFloat(message,movevars.bounce);
  MSG_WriteFloat(message,movevars.stepsize);
  MSG_WriteFloat(message,movevars.maxvelocity);
  MSG_WriteFloat(message,movevars.zmax);
  MSG_WriteFloat(message,movevars.waveHeight);
  MSG_WriteByte(message,(uint)(movevars.footsteps != false));
  MSG_WriteFloat(message,movevars.rollangle);
  MSG_WriteFloat(message,movevars.rollspeed);
  MSG_WriteFloat(message,movevars.skycolor_r);
  MSG_WriteFloat(message,movevars.skycolor_g);
  MSG_WriteFloat(message,movevars.skycolor_b);
  MSG_WriteFloat(message,movevars.skyvec_x);
  MSG_WriteFloat(message,movevars.skyvec_y);
  MSG_WriteFloat(message,movevars.skyvec_z);
  MSG_WriteString(message,movevars.skyName);
  return;
}


// SV_WriteSpawn  @ 00084990
void SV_WriteSpawn(sizebuf_t *msg)

{
  int *piVar1;
  char **ppcVar2;
  edict_t *peVar3;
  edict_t *peVar4;
  client_t *pcVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  client_s *pcVar9;
  char *s;
  int in_GS_OFFSET;
  uchar local_6a4 [16];
  MD5Context_t local_694 [2];
  char local_594 [36];
  int local_570;
  char local_568 [211];
  undefined1 local_495;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] name@[???]
                       Unresolved local var: SAVERESTOREDATA currentLevelData@[???]
                       Unresolved local var: client_t * client@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (sv.loadgame == false) {
    sv.state = ss_loading;
    ReleaseEntityDLLFields(sv_player);
    Q_memset(&sv_player->v,0,0x2a4);
    InitEntityDLLFields(sv_player);
    peVar3 = sv_player;
    iVar6 = NUM_FOR_EDICT(sv_player);
    peVar4 = sv_player;
    pcVar5 = host_client;
    (peVar3->v).colormap = iVar6;
    (peVar4->v).netname = (int)pcVar5 + (0x6358 - (int)pr_strings);
    if (pcVar5->proxy != false) {
      piVar1 = &(peVar4->v).flags;
      *piVar1 = *piVar1 | 0x100000;
    }
    gGlobalVariables.time = (float)sv.time;
    (*gEntityInterface.pfnClientPutInServer)(peVar4);
    sv.state = ss_active;
  }
  else {
    if (host_client->proxy != false) {
      Con_Printf("ERROR! Spectator mode doesn\'t work with saved game.\n");
      goto LAB_00084c4c;
    }
    sv.paused = false;
  }
  SZ_Clear(&(host_client->netchan).message);
  SZ_Clear(&host_client->datagram);
  MSG_WriteByte(msg,7);
  MSG_WriteFloat(msg,(float)sv.time);
  iVar6 = svs.maxclients;
  pcVar9 = svs.clients;
  pcVar5 = host_client;
  host_client->sendinfo = true;
  if (0 < iVar6) {
    iVar8 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: char[256] info@[???]
                       Unresolved local var: char[16] digest@[???]
                       Unresolved local var: MD5Context_t ctx@[???] */
    do {
      if ((((pcVar5 == pcVar9) || (pcVar9->active != false)) || (pcVar9->connected != false)) ||
         (pcVar9->spawned != false)) {
        iVar6 = (int)pcVar9 - (int)svs.clients;
        Q_strncpy(local_594,pcVar9->userinfo,0xff);
        local_495 = 0;
        Info_RemovePrefixedKeys(local_594,'_');
        MSG_WriteByte(msg,0xd);
        MSG_WriteByte(msg,(iVar6 >> 3) * 0x4ffec005);
        MSG_WriteLong(msg,pcVar9->userid);
        MSG_WriteString(msg,local_594);
        MD5Init(local_694);
        MD5Update(local_694,(uchar *)pcVar9->hashedcdkey,0x40);
        MD5Final(local_6a4,local_694);
        MSG_WriteBuf(msg,0x10,local_6a4);
        iVar6 = svs.maxclients;
      }
      iVar8 = iVar8 + 1;
      pcVar9 = pcVar9 + 1;
      pcVar5 = host_client;
    } while (iVar8 < iVar6);
  }
  iVar6 = 0;
  do {
    MSG_WriteByte(msg,0xc);
    MSG_WriteByte(msg,iVar6);
    ppcVar2 = sv.lightstyles + iVar6;
    iVar6 = iVar6 + 1;
    MSG_WriteString(msg,*ppcVar2);
  } while (iVar6 != 0x40);
  if (host_client->proxy == false) {
    MSG_WriteByte(msg,10);
    MSG_WriteHiresAngle(msg,(sv_player->v).v_angle[0]);
    MSG_WriteHiresAngle(msg,(sv_player->v).v_angle[1]);
    MSG_WriteHiresAngle(msg,0.0);
    SV_WriteClientdataToMessage(host_client,msg);
    if (sv.loadgame != false) {
      Q_memset(local_594,0,0x574);
      gGlobalVariables.pSaveData = local_594;
      (*gEntityInterface.pfnParmsChangeLevel)();
      MSG_WriteByte(msg,0x21);
      pcVar7 = Host_SaveGameDirectory();
      s = local_568;
      __snprintf_chk(local_694,0x100,1,0x100,"%s%s.HL2",pcVar7,0x4ff2a8);
      COM_FixSlashes((char *)local_694);
      iVar6 = 0;
      MSG_WriteString(msg,(char *)local_694);
      MSG_WriteByte(msg,local_570);
      if (0 < local_570) {
        do {
          iVar6 = iVar6 + 1;
          MSG_WriteString(msg,s);
          s = s + 0x50;
        } while (iVar6 < local_570);
      }
      sv.loadgame = false;
      gGlobalVariables.pSaveData = (void *)0x0;
    }
  }
  MSG_WriteByte(msg,0x19);
  MSG_WriteByte(msg,1);
  host_client->active = true;
  pcVar5 = host_client;
  *(undefined4 *)&host_client->connecttime = 0;
  *(undefined4 *)((int)&pcVar5->connecttime + 4) = 0;
  *(undefined4 *)&pcVar5->ignorecmdtime = 0;
  *(undefined4 *)((int)&pcVar5->ignorecmdtime + 4) = 0;
  *(undefined4 *)&pcVar5->cmdtime = 0;
  *(undefined4 *)((int)&pcVar5->cmdtime + 4) = 0;
  pcVar5->spawned = true;
  pcVar5->connected = true;
  pcVar5->fully_connected = false;
  NotifyDedicatedServerUI("UpdatePlayers");
LAB_00084c4c:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SV_WriteVoiceCodec  @ 0008e020
void SV_WriteVoiceCodec(sizebuf_t *pBuf)

{
  MSG_WriteByte(pBuf,0x34);
  MSG_WriteString(pBuf,"");
  MSG_WriteByte(pBuf,0);
  return;
}


// SV_movestep  @ 00095f00
qboolean SV_movestep(edict_t *ent,vec_t *move,qboolean relink)

{
  vec_t *mins;
  vec_t *maxs;
  float fVar1;
  float fVar2;
  float fVar3;
  edict_t *peVar4;
  uint uVar5;
  int iVar6;
  qboolean qVar7;
  uint uVar8;
  trace_t local_ac;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  int local_54 [4];
  float local_44;
  vec_t local_40;
  vec_t local_3c;
  vec_t vStack_38;
  edict_t *peStack_24;
  
                    /* Unresolved local var: float dz@[???]
                       Unresolved local var: vec3_t oldorg@[???]
                       Unresolved local var: vec3_t neworg@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: edict_t * enemy@[???]
                       Unresolved local var: qboolean monsterClip@[???] */
  fVar1 = (ent->v).origin[0];
  fVar2 = (ent->v).origin[1];
  fVar3 = (ent->v).origin[2];
  local_6c = *move + fVar1;
  uVar8 = (ent->v).flags;
  local_68 = move[1] + fVar2;
  qVar7 = uVar8 >> 0x17 & true;
  local_64 = move[2] + fVar3;
  if ((uVar8 & 3) == 0) {
    local_64 = local_64 + sv_stepsize.value;
    mins = (ent->v).mins;
    maxs = (ent->v).maxs;
    local_58 = local_64 - (sv_stepsize.value + sv_stepsize.value);
    local_60 = local_6c;
    local_5c = local_68;
    SV_Move(&local_ac,&local_6c,mins,maxs,&local_60,0,ent,qVar7);
    uVar8 = 0;
    do {
      *(undefined4 *)((int)local_54 + uVar8) =
           *(undefined4 *)((int)local_ac.endpos + (uVar8 - 0x14));
      uVar8 = uVar8 + 4;
    } while (uVar8 < 0x38);
    if (local_54[0] == 0) {
      if (local_54[1] != 0) {
        local_64 = local_64 - sv_stepsize.value;
        SV_Move(&local_ac,&local_6c,mins,maxs,&local_60,0,ent,qVar7);
        uVar8 = 0;
        do {
          *(undefined4 *)((int)local_54 + uVar8) =
               *(undefined4 *)((int)local_ac.endpos + (uVar8 - 0x14));
          uVar8 = uVar8 + 4;
        } while (uVar8 < 0x38);
        if (local_54[0] != 0) {
          return false;
        }
        if (local_54[1] != 0) {
          return false;
        }
      }
      if (local_44 != 1.0) {
        (ent->v).origin[0] = local_40;
        (ent->v).origin[1] = local_3c;
        (ent->v).origin[2] = vStack_38;
        qVar7 = SV_CheckBottom(ent);
        if (qVar7 == false) {
          if (((ent->v).flags & 0x400) == 0) {
            (ent->v).origin[0] = fVar1;
            (ent->v).origin[1] = fVar2;
            (ent->v).origin[2] = fVar3;
            return false;
          }
        }
        else {
          uVar8 = (ent->v).flags;
          if ((uVar8 & 0x400) != 0) {
            (ent->v).flags = uVar8 & 0xfffffbff;
          }
          (ent->v).groundentity = peStack_24;
        }
        goto joined_r0x00096399;
      }
      uVar8 = (ent->v).flags;
      if ((uVar8 & 0x400) != 0) {
        (ent->v).origin[0] = (ent->v).origin[0] + *move;
        (ent->v).origin[1] = (ent->v).origin[1] + move[1];
        (ent->v).origin[2] = (ent->v).origin[2] + move[2];
        if (relink != false) {
          SV_LinkEdict(ent,true);
          uVar8 = (ent->v).flags;
        }
        (ent->v).flags = uVar8 & 0xfffffdff;
        return true;
      }
    }
  }
  else {
    uVar8 = 0;
    while( true ) {
      peVar4 = (ent->v).enemy;
      if (((uVar8 & 1) == 0) && (peVar4 != (edict_t *)0x0)) {
        fVar3 = fVar3 - (peVar4->v).origin[2];
        if (40.0 < fVar3) {
          local_64 = local_64 - 8.0;
        }
        if (fVar3 < 30.0) {
          local_64 = local_64 + 8.0;
        }
      }
      SV_Move(&local_ac,(ent->v).origin,(ent->v).mins,(ent->v).maxs,&local_6c,0,ent,qVar7);
      uVar5 = 0;
      do {
        *(undefined4 *)((int)local_54 + uVar5) =
             *(undefined4 *)((int)local_ac.endpos + (uVar5 - 0x14));
        uVar5 = uVar5 + 4;
      } while (uVar5 < 0x38);
      if (local_44 == 1.0) break;
      if (peVar4 == (edict_t *)0x0) {
        return false;
      }
      uVar8 = uVar8 + 1;
      if (uVar8 == 2) {
        return false;
      }
      fVar3 = (ent->v).origin[2];
      local_6c = (ent->v).origin[0] + *move;
      local_68 = (ent->v).origin[1] + move[1];
      local_64 = move[2] + fVar3;
    }
    g_groupmask = (ent->v).groupinfo;
    if ((((ent->v).flags & 2) == 0) || (iVar6 = SV_PointContents(&local_40), iVar6 != -1)) {
      (ent->v).origin[0] = local_40;
      (ent->v).origin[1] = local_3c;
      (ent->v).origin[2] = vStack_38;
joined_r0x00096399:
      if (relink == false) {
        return true;
      }
      SV_LinkEdict(ent,true);
      return true;
    }
  }
  return false;
}


// SV_movetest  @ 00095c30
qboolean SV_movetest(edict_t *ent,vec_t *move,qboolean relink)

{
  vec_t *maxs;
  vec_t *mins;
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  qboolean qVar5;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  trace_t local_54;
  
                    /* Unresolved local var: vec3_t oldorg@[???]
                       Unresolved local var: vec3_t neworg@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: trace_t trace@[???] */
  fVar1 = (ent->v).origin[0];
  maxs = (ent->v).maxs;
  mins = (ent->v).mins;
  fVar2 = (ent->v).origin[1];
  fVar3 = (ent->v).origin[2];
  local_6c = *move + fVar1;
  local_68 = move[1] + fVar2;
  local_64 = move[2] + fVar3 + sv_stepsize.value;
  local_58 = local_64 - (sv_stepsize.value + sv_stepsize.value);
  local_60 = local_6c;
  local_5c = local_68;
  SV_MoveNoEnts(&local_54,&local_6c,mins,maxs,&local_60,0,ent);
  if (local_54.allsolid == false) {
    if (local_54.startsolid != false) {
      local_64 = local_64 - sv_stepsize.value;
      SV_MoveNoEnts(&local_54,&local_6c,mins,maxs,&local_60,0,ent);
      if (local_54.allsolid != false || local_54.startsolid != false) {
        return false;
      }
    }
    if (local_54.fraction != 1.0) {
      (ent->v).origin[0] = local_54.endpos[0];
      (ent->v).origin[1] = local_54.endpos[1];
      (ent->v).origin[2] = local_54.endpos[2];
      qVar5 = SV_CheckBottom(ent);
      if (qVar5 == false) {
        if (((ent->v).flags & 0x400) == 0) {
          (ent->v).origin[0] = fVar1;
          (ent->v).origin[1] = fVar2;
          (ent->v).origin[2] = fVar3;
          return false;
        }
      }
      else {
        uVar4 = (ent->v).flags;
        if ((uVar4 & 0x400) != 0) {
          (ent->v).flags = uVar4 & 0xfffffbff;
        }
        (ent->v).groundentity = local_54.ent;
      }
      if (relink != false) {
        SV_LinkEdict(ent,true);
      }
      return true;
    }
    uVar4 = (ent->v).flags;
    if ((uVar4 & 0x400) != 0) {
      (ent->v).origin[0] = (ent->v).origin[0] + *move;
      (ent->v).origin[1] = (ent->v).origin[1] + move[1];
      (ent->v).origin[2] = (ent->v).origin[2] + move[2];
      if (relink != false) {
        SV_LinkEdict(ent,true);
        uVar4 = (ent->v).flags;
      }
      (ent->v).flags = uVar4 & 0xfffffdff;
      return true;
    }
  }
  return false;
}


