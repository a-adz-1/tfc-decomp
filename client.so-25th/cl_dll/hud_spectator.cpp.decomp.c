// Ghidra decompilation of functions from cl_dll/hud_spectator.cpp
// 37 functions, ordered by original source line

// SpectatorMode  @ 00055f10  (line 79)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SpectatorMode(void)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  long iNewMainMode;
  
  iVar1 = (*gEngfuncs.Cmd_Argc)();
  if (iVar1 < 2) {
    (*gEngfuncs.Con_Printf)("usage:  spec_mode <Main Mode> [<Inset Mode>]\n");
    return;
  }
  iVar1 = (*gEngfuncs.Cmd_Argc)();
  if (iVar1 != 2) {
    iVar1 = (*gEngfuncs.Cmd_Argc)();
    if (iVar1 != 3) {
      return;
    }
    pcVar2 = (*gEngfuncs.Cmd_Argv)(2);
    lVar3 = strtol(pcVar2,(char **)0x0,10);
    pcVar2 = (*gEngfuncs.Cmd_Argv)(1);
    iNewMainMode = strtol(pcVar2,(char **)0x0,10);
    CHudSpectator::SetModes(&gHUD.m_Spectator,iNewMainMode,lVar3);
    return;
  }
  pcVar2 = (*gEngfuncs.Cmd_Argv)(1);
  lVar3 = strtol(pcVar2,(char **)0x0,10);
  CHudSpectator::SetModes(&gHUD.m_Spectator,lVar3,-1);
  return;
}


// SpectatorSpray  @ 00053cc0  (line 96)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SpectatorSpray(void)

{
  int iVar1;
  pmtrace_s *ppVar2;
  int in_GS_OFFSET;
  float local_9c;
  float local_98;
  float local_94;
  char local_90 [128];
  int local_10;
  
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: char[128] string@[???]
                       Unresolved local var: pmtrace_t * trace@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar1 != 0) {
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: char[128] string@[???]
                       Unresolved local var: pmtrace_t * trace@[???] */
    (*gEngfuncs.pfnAngleVectors)(&v_angles.x,&local_9c,(float *)0x0,(float *)0x0);
    VectorScale(&local_9c,128.0,&local_9c);
    local_9c = local_9c + v_origin.x;
    local_98 = local_98 + v_origin.y;
    local_94 = local_94 + v_origin.z;
    ppVar2 = (*gEngfuncs.PM_TraceLine)(&v_origin.x,&local_9c,0,2,-1);
    if (ppVar2->fraction != 1.0) {
      __sprintf_chk(local_90,1,0x80,"drc_spray %.2f %.2f %.2f %i",(double)(ppVar2->endpos).x,
                    (double)(ppVar2->endpos).y,(double)(ppVar2->endpos).z,ppVar2->ent);
      (*gEngfuncs.pfnServerCmd)(local_90);
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// SpectatorHelp  @ 00053bb0  (line 116)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SpectatorHelp(void)

{
  char cVar1;
  char *pcVar2;
  
  if (gViewPort == (TeamFortressViewport *)0x0) {
                    /* Unresolved local var: char * text@[???] */
    pcVar2 = CHudTextMessage::BufferedLocaliseTextString("#Spec_Help_Text");
    if (pcVar2 != (char *)0x0) {
      while( true ) {
        cVar1 = *pcVar2;
        if (cVar1 == '\0') break;
        if (cVar1 != '\r') {
          (*gEngfuncs.Con_Printf)("%c",(int)cVar1);
        }
        pcVar2 = pcVar2 + 1;
      }
    }
  }
  else {
    TeamFortressViewport::ShowVGUIMenu(gViewPort,9);
  }
  return;
}


// SpectatorMenu  @ 00053c10  (line 138)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SpectatorMenu(void)

{
  int iVar1;
  char *__nptr;
  long lVar2;
  
  iVar1 = (*gEngfuncs.Cmd_Argc)();
  if (1 < iVar1) {
    __nptr = (*gEngfuncs.Cmd_Argv)(1);
    lVar2 = strtol(__nptr,(char **)0x0,10);
    SpectatorPanel::ShowMenu(gViewPort->m_pSpectatorPanel,lVar2 != 0);
    return;
  }
  (*gEngfuncs.Con_Printf)("usage:  spec_menu <0|1>\n");
  return;
}


// ToggleScores  @ 00053c80  (line 150)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ToggleScores(void)

{
  bool bVar1;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::IsScoreBoardVisible(gViewPort);
    if (bVar1) {
      TeamFortressViewport::HideScoreBoard(gViewPort);
    }
    else {
      TeamFortressViewport::ShowScoreBoard(gViewPort);
    }
  }
  return;
}


// CHudSpectator::Init  @ 00053510  (line 167)

/* DWARF original prototype: int Init(CHudSpectator * this) */

int __thiscall CHudSpectator::Init(CHudSpectator *this)

{
  int *piVar1;
  uint uVar2;
  cvar_s *pcVar3;
  uint uVar4;
  overviewInfo_t *poVar5;
  char *pcVar6;
  overviewEntity_t *poVar7;
  bool bVar8;
  byte bVar9;
  
  bVar9 = 0;
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  uVar4 = 0x16c;
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  this->m_FOV = 90.0;
  this->m_flNextObserverInput = 0.0;
  this->m_zoomDelta = 0.0;
  this->m_moveDelta = 0.0;
  uVar2 = (uint)NAN((gHUD.m_SayText.m_HUD_saytext)->value);
  if ((gHUD.m_SayText.m_HUD_saytext)->value != 0.0) {
    uVar2 = 1;
  }
  poVar5 = &this->m_OverviewData;
  this->m_chatEnabled = uVar2;
  bVar8 = ((uint)poVar5 & 1) != 0;
  iJumpSpectator = 0;
  if (bVar8) {
    poVar5 = (overviewInfo_t *)((this->m_OverviewData).map + 1);
    uVar4 = 0x16b;
    (this->m_OverviewData).map[0] = '\0';
  }
  if (((uint)poVar5 & 2) != 0) {
    poVar5->map[0] = '\0';
    poVar5->map[1] = '\0';
    uVar4 = uVar4 - 2;
    poVar5 = (overviewInfo_t *)(poVar5->map + 2);
  }
  uVar2 = 0;
  do {
    pcVar6 = poVar5->map + uVar2;
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = poVar5->map + uVar2 + 4;
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    uVar2 = uVar2 + 8;
  } while (uVar2 < (uVar4 & 0xfffffff8));
  pcVar6 = poVar5->map + uVar2;
  if ((uVar4 & 4) != 0) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  if ((uVar4 & 2) != 0) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6 = pcVar6 + 2;
  }
  if (bVar8) {
    *pcVar6 = '\0';
  }
  poVar7 = this->m_OverviewEntities;
  uVar4 = 0x800;
  bVar8 = ((uint)poVar7 & 1) != 0;
  if (bVar8) {
    *(undefined1 *)&this->m_OverviewEntities[0].hSprite = 0;
    poVar7 = (overviewEntity_t *)((int)&this->m_OverviewEntities[0].hSprite + 1);
    uVar4 = 0x7ff;
  }
  if (((uint)poVar7 & 2) != 0) {
    *(undefined2 *)&poVar7->hSprite = 0;
    uVar4 = uVar4 - 2;
    poVar7 = (overviewEntity_t *)((int)&poVar7->hSprite + 2);
  }
  if (((uint)poVar7 & 4) != 0) {
    poVar7->hSprite = 0;
    uVar4 = uVar4 - 4;
    poVar7 = (overviewEntity_t *)&poVar7->entity;
  }
  for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    poVar7->hSprite = 0;
    poVar7 = (overviewEntity_t *)((int)poVar7 + (uint)bVar9 * -8 + 4);
  }
  if ((uVar4 & 2) != 0) {
    *(undefined2 *)&poVar7->hSprite = 0;
    poVar7 = (overviewEntity_t *)((int)&poVar7->hSprite + 2);
  }
  if (bVar8) {
    *(undefined1 *)&poVar7->hSprite = 0;
  }
  this->m_lastPrimaryObject = 0;
  this->m_lastSecondaryObject = 0;
  (*gEngfuncs.pfnAddCommand)("spec_mode",SpectatorMode);
  (*gEngfuncs.pfnAddCommand)("spec_decal",SpectatorSpray);
  (*gEngfuncs.pfnAddCommand)("spec_help",SpectatorHelp);
  (*gEngfuncs.pfnAddCommand)("spec_menu",SpectatorMenu);
  (*gEngfuncs.pfnAddCommand)("togglescores",ToggleScores);
  pcVar3 = (*gEngfuncs.pfnRegisterVariable)("spec_drawnames","1",0);
  this->m_drawnames = pcVar3;
  pcVar3 = (*gEngfuncs.pfnRegisterVariable)("spec_drawcone","1",0);
  this->m_drawcone = pcVar3;
  pcVar3 = (*gEngfuncs.pfnRegisterVariable)("spec_drawstatus","1",0);
  this->m_drawstatus = pcVar3;
  pcVar3 = (*gEngfuncs.pfnRegisterVariable)("spec_autodirector","1",0);
  this->m_autoDirector = pcVar3;
  pcVar3 = (*gEngfuncs.pfnRegisterVariable)("spec_pip","1",0);
  this->m_pip = pcVar3;
  if ((((this->m_drawnames != (cvar_t *)0x0) && (this->m_drawcone != (cvar_t *)0x0)) &&
      (this->m_drawstatus != (cvar_t *)0x0)) &&
     ((this->m_autoDirector != (cvar_t *)0x0 && (pcVar3 != (cvar_s *)0x0)))) {
    return 1;
  }
  (*gEngfuncs.Con_Printf)("ERROR! Couldn\'t register all spectator variables.\n");
  return 0;
}


// UTIL_StringToVector  @ 00054300  (line 209)

void UTIL_StringToVector(float *pVector,char *pString)

{
  byte bVar1;
  float *pfVar2;
  uint uVar3;
  uint uVar4;
  byte *__dest;
  int iVar5;
  int in_GS_OFFSET;
  double dVar6;
  byte local_90;
  byte local_8f [126];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char * pstr@[???]
                       Unresolved local var: char * pfront@[???]
                       Unresolved local var: char[128] tempString@[???]
                       Unresolved local var: int j@[???] */
  iVar5 = 0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  __dest = &local_90;
  strncpy((char *)__dest,pString,0x80);
  local_11 = 0;
  while( true ) {
    dVar6 = strtod((char *)__dest,(char **)0x0);
    pVector[iVar5] = (float)dVar6;
    bVar1 = *__dest;
    while ((bVar1 & 0xdf) != 0) {
      __dest = __dest + 1;
      bVar1 = *__dest;
    }
    if (bVar1 == 0) break;
    iVar5 = iVar5 + 1;
    __dest = __dest + 1;
    if (iVar5 == 3) {
LAB_00054383:
      if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  }
  if (iVar5 != 2) {
    uVar4 = iVar5 * -4 + 8;
    pfVar2 = pVector + iVar5 + 1;
    if (7 < uVar4) {
      if (((uint)pfVar2 & 1) != 0) {
        *(undefined1 *)pfVar2 = 0;
        uVar4 = iVar5 * -4 + 7;
        pfVar2 = (float *)((int)pfVar2 + 1);
      }
      if (((uint)pfVar2 & 2) != 0) {
        *(undefined2 *)pfVar2 = 0;
        uVar4 = uVar4 - 2;
        pfVar2 = (float *)((int)pfVar2 + 2);
      }
      if (7 < uVar4) {
        uVar3 = 0;
        do {
          *(undefined4 *)((int)pfVar2 + uVar3) = 0;
          *(undefined4 *)((int)pfVar2 + uVar3 + 4) = 0;
          uVar3 = uVar3 + 8;
        } while (uVar3 < (uVar4 & 0xfffffff8));
        pfVar2 = (float *)((int)pfVar2 + uVar3);
      }
    }
    if ((uVar4 & 4) != 0) {
      *pfVar2 = 0.0;
      pfVar2 = pfVar2 + 1;
    }
    if ((uVar4 & 2) != 0) {
      *(undefined2 *)pfVar2 = 0;
      pfVar2 = (float *)((int)pfVar2 + 2);
    }
    if ((uVar4 & 1) != 0) {
      *(undefined1 *)pfVar2 = 0;
    }
  }
  goto LAB_00054383;
}


// UTIL_FindEntityInMap  @ 00054430  (line 237)

int UTIL_FindEntityInMap(char *name,float *origin,float *angle)

{
  char *pcVar1;
  byte bVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  cl_entity_s *pcVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  float *pfVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  char *pcVar14;
  int in_GS_OFFSET;
  bool bVar15;
  bool bVar16;
  byte bVar17;
  double dVar18;
  byte local_5a0;
  byte local_59f [126];
  char local_521 [257];
  char local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: int n@[???]
                       Unresolved local var: int found@[???]
                       Unresolved local var: char[256] keyname@[???]
                       Unresolved local var: char[1024] token@[???]
                       Unresolved local var: cl_entity_t * pEnt@[???]
                       Unresolved local var: char * data@[???] */
  bVar17 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar6 = (*gEngfuncs.GetEntityByIndex)(0);
  if (((pcVar6 != (cl_entity_s *)0x0) && (pcVar6->model != (model_s *)0x0)) &&
     (pcVar7 = pcVar6->model->entities, pcVar7 != (char *)0x0)) {
    pcVar1 = local_521 + 1;
    do {
      pcVar7 = (*gEngfuncs.COM_ParseFile)(pcVar7,local_420);
      if ((local_420[0] == '}') || (local_420[0] == '\0')) break;
      if (pcVar7 == (char *)0x0) {
LAB_00054744:
        (*gEngfuncs.Con_DPrintf)("UTIL_FindEntityInMap: EOF without closing brace\n");
        break;
      }
      if (local_420[0] != '{') {
        (*gEngfuncs.Con_DPrintf)("UTIL_FindEntityInMap: expected {\n");
        iVar8 = 0;
        goto LAB_00054753;
      }
      bVar4 = false;
LAB_000544f0:
      pcVar7 = (*gEngfuncs.COM_ParseFile)(pcVar7,local_420);
      if (local_420[0] != '}') {
        if (pcVar7 == (char *)0x0) goto LAB_00054744;
        iVar8 = __stpcpy_chk(pcVar1,local_420,0x100);
        iVar8 = iVar8 - (int)pcVar1;
        if ((iVar8 != 0) && (local_521[iVar8] == ' ')) {
          pcVar9 = local_521 + iVar8;
          do {
            *pcVar9 = '\0';
            if (pcVar9 == pcVar1) break;
            pcVar9 = pcVar9 + -1;
          } while (*pcVar9 == ' ');
        }
        pcVar7 = (*gEngfuncs.COM_ParseFile)(pcVar7,local_420);
        if (pcVar7 == (char *)0x0) goto LAB_00054744;
        if (local_420[0] == '}') {
          (*gEngfuncs.Con_DPrintf)("UTIL_FindEntityInMap: closing brace without data");
          iVar8 = 0;
          goto LAB_00054753;
        }
        iVar8 = 10;
        bVar15 = false;
        pcVar9 = pcVar1;
        pcVar14 = "classname";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar15 = *pcVar9 == *pcVar14;
          pcVar9 = pcVar9 + (uint)bVar17 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
        } while (bVar15);
        bVar16 = false;
        bVar5 = bVar4;
        if (bVar15) {
          iVar8 = strcmp(local_420,name);
          bVar16 = iVar8 == 0;
          bVar5 = true;
          if (!bVar16) {
            bVar5 = bVar4;
          }
        }
        bVar4 = bVar5;
        iVar8 = 6;
        pcVar9 = pcVar1;
        pcVar14 = "angle";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar16 = *pcVar9 == *pcVar14;
          pcVar9 = pcVar9 + (uint)bVar17 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
        } while (bVar16);
        bVar15 = false;
        if (bVar16) {
                    /* Unresolved local var: float y@[???] */
          dVar18 = strtod(local_420,(char **)0x0);
          fVar3 = (float)dVar18;
          bVar15 = fVar3 == 0.0;
          if (fVar3 < 0.0) {
            bVar15 = (int)dVar18 == -1;
            if (bVar15) {
              *angle = -90.0;
              angle[1] = 0.0;
            }
            else {
              *angle = 90.0;
              angle[1] = 0.0;
            }
          }
          else {
            *angle = 0.0;
            angle[1] = fVar3;
          }
          angle[2] = 0.0;
        }
        iVar8 = 7;
        pcVar9 = pcVar1;
        pcVar14 = "angles";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar15 = *pcVar9 == *pcVar14;
          pcVar9 = pcVar9 + (uint)bVar17 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
        } while (bVar15);
        bVar16 = false;
        if (bVar15) {
                    /* Unresolved local var: char * pstr@[???]
                       Unresolved local var: char * pfront@[???]
                       Unresolved local var: char[128] tempString@[???]
                       Unresolved local var: int j@[???] */
          iVar8 = 0;
          pbVar13 = &local_5a0;
          strncpy((char *)&local_5a0,local_420,0x80);
          local_521[0] = '\0';
          do {
            dVar18 = strtod((char *)pbVar13,(char **)0x0);
            angle[iVar8] = (float)dVar18;
            bVar2 = *pbVar13;
            while ((bVar2 & 0xdf) != 0) {
              pbVar13 = pbVar13 + 1;
              bVar2 = *pbVar13;
            }
            if (bVar2 == 0) {
              bVar16 = iVar8 == 2;
              if (!bVar16) {
                uVar12 = iVar8 * -4 + 8;
                pfVar10 = angle + iVar8 + 1;
                if (7 < uVar12) {
                  if (((uint)pfVar10 & 1) != 0) {
                    *(undefined1 *)pfVar10 = 0;
                    pfVar10 = (float *)((int)pfVar10 + 1);
                    uVar12 = iVar8 * -4 + 7;
                  }
                  if (((uint)pfVar10 & 2) != 0) {
                    *(undefined2 *)pfVar10 = 0;
                    uVar12 = uVar12 - 2;
                    pfVar10 = (float *)((int)pfVar10 + 2);
                  }
                  if (7 < uVar12) {
                    uVar11 = 0;
                    do {
                      *(undefined4 *)((int)pfVar10 + uVar11) = 0;
                      *(undefined4 *)((int)pfVar10 + uVar11 + 4) = 0;
                      uVar11 = uVar11 + 8;
                    } while (uVar11 < (uVar12 & 0xfffffff8));
                    pfVar10 = (float *)((int)pfVar10 + uVar11);
                  }
                }
                if ((uVar12 & 4) != 0) {
                  *pfVar10 = 0.0;
                  pfVar10 = pfVar10 + 1;
                }
                if ((uVar12 & 2) != 0) {
                  *(undefined2 *)pfVar10 = 0;
                  pfVar10 = (float *)((int)pfVar10 + 2);
                }
                bVar16 = (uVar12 & 1) == 0;
                if (!bVar16) {
                  *(undefined1 *)pfVar10 = 0;
                }
              }
              goto LAB_000545e8;
            }
            iVar8 = iVar8 + 1;
            pbVar13 = pbVar13 + 1;
          } while (iVar8 != 3);
          bVar16 = true;
        }
LAB_000545e8:
        iVar8 = 7;
        pcVar9 = pcVar1;
        pcVar14 = "origin";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar16 = *pcVar9 == *pcVar14;
          pcVar9 = pcVar9 + (uint)bVar17 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
        } while (bVar16);
        if (bVar16) {
                    /* Unresolved local var: char * pstr@[???]
                       Unresolved local var: char * pfront@[???]
                       Unresolved local var: char[128] tempString@[???]
                       Unresolved local var: int j@[???] */
          iVar8 = 0;
          pbVar13 = &local_5a0;
          strncpy((char *)&local_5a0,local_420,0x80);
          local_521[0] = '\0';
          do {
            dVar18 = strtod((char *)pbVar13,(char **)0x0);
            origin[iVar8] = (float)dVar18;
            bVar2 = *pbVar13;
            while ((bVar2 & 0xdf) != 0) {
              pbVar13 = pbVar13 + 1;
              bVar2 = *pbVar13;
            }
            if (bVar2 == 0) {
              if (iVar8 != 2) {
                uVar12 = iVar8 * -4 + 8;
                pfVar10 = origin + iVar8 + 1;
                if (7 < uVar12) {
                  if (((uint)pfVar10 & 1) != 0) {
                    *(undefined1 *)pfVar10 = 0;
                    pfVar10 = (float *)((int)pfVar10 + 1);
                    uVar12 = iVar8 * -4 + 7;
                  }
                  if (((uint)pfVar10 & 2) != 0) {
                    *(undefined2 *)pfVar10 = 0;
                    uVar12 = uVar12 - 2;
                    pfVar10 = (float *)((int)pfVar10 + 2);
                  }
                  if (7 < uVar12) {
                    uVar11 = 0;
                    do {
                      *(undefined4 *)((int)pfVar10 + uVar11) = 0;
                      *(undefined4 *)((int)pfVar10 + uVar11 + 4) = 0;
                      uVar11 = uVar11 + 8;
                    } while (uVar11 < (uVar12 & 0xfffffff8));
                    pfVar10 = (float *)((int)pfVar10 + uVar11);
                  }
                }
                if ((uVar12 & 4) != 0) {
                  *pfVar10 = 0.0;
                  pfVar10 = pfVar10 + 1;
                }
                if ((uVar12 & 2) != 0) {
                  *(undefined2 *)pfVar10 = 0;
                  pfVar10 = (float *)((int)pfVar10 + 2);
                }
                if ((uVar12 & 1) != 0) {
                  *(undefined1 *)pfVar10 = 0;
                }
              }
              break;
            }
            iVar8 = iVar8 + 1;
            pbVar13 = pbVar13 + 1;
          } while (iVar8 != 3);
        }
        goto LAB_000544f0;
      }
      if (bVar4) {
        iVar8 = 1;
        goto LAB_00054753;
      }
    } while (pcVar7 != (char *)0x0);
  }
  iVar8 = 0;
LAB_00054753:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHudSpectator::SetSpectatorStartPosition  @ 00054ca0  (line 367)

/* DWARF original prototype: void SetSpectatorStartPosition(CHudSpectator * this) */

void __thiscall CHudSpectator::SetSpectatorStartPosition(CHudSpectator *this)

{
  Vector *angle;
  Vector *origin;
  int iVar1;
  
  angle = &this->m_cameraAngles;
  origin = &this->m_cameraOrigin;
  iVar1 = UTIL_FindEntityInMap("trigger_camera",&origin->x,&angle->x);
  if ((((iVar1 == 0) &&
       (iVar1 = UTIL_FindEntityInMap("info_player_start",&origin->x,&angle->x), iVar1 == 0)) &&
      (iVar1 = UTIL_FindEntityInMap("info_player_deathmatch",&origin->x,&angle->x), iVar1 == 0)) &&
     (iVar1 = UTIL_FindEntityInMap("info_player_coop",&origin->x,&angle->x),
     vJumpAngles[0] = vec3_origin.x, iVar1 == 0)) {
    (this->m_cameraOrigin).x = vec3_origin.x;
    vJumpAngles[1] = vec3_origin.y;
    (this->m_cameraOrigin).y = vec3_origin.y;
    vJumpAngles[2] = vec3_origin.z;
    (this->m_cameraOrigin).z = vec3_origin.z;
    (this->m_cameraAngles).x = vJumpAngles[0];
    (this->m_cameraAngles).y = vJumpAngles[1];
    (this->m_cameraAngles).z = vJumpAngles[2];
    vJumpOrigin[0] = vJumpAngles[0];
    vJumpOrigin[1] = vJumpAngles[1];
    vJumpOrigin[2] = vJumpAngles[2];
    iJumpSpectator = 1;
    return;
  }
  vJumpOrigin[0] = (this->m_cameraOrigin).x;
  vJumpOrigin[1] = (this->m_cameraOrigin).y;
  vJumpOrigin[2] = (this->m_cameraOrigin).z;
  vJumpAngles[0] = (this->m_cameraAngles).x;
  vJumpAngles[1] = (this->m_cameraAngles).y;
  vJumpAngles[2] = (this->m_cameraAngles).z;
  iJumpSpectator = 1;
  return;
}


// CHudSpectator::SetCameraView  @ 00054df0  (line 395)

/* DWARF original prototype: void SetCameraView(CHudSpectator * this, Vector pos, Vector angle,
   float fov) */

void __thiscall CHudSpectator::SetCameraView(CHudSpectator *this,Vector pos,Vector angle,float fov)

{
  this->m_FOV = pos.z;
  vJumpAngles[0] = *(float *)pos.y;
  vJumpAngles[1] = *(float *)((int)pos.y + 4);
  vJumpAngles[2] = *(float *)((int)pos.y + 8);
  vJumpOrigin[0] = *(float *)pos.x;
  vJumpOrigin[1] = *(float *)((int)pos.x + 4);
  vJumpOrigin[2] = *(float *)((int)pos.x + 8);
  (*gEngfuncs.SetViewAngles)(vJumpAngles);
  iJumpSpectator = 1;
  return;
}


// CHudSpectator::AddWaypoint  @ 00054e80  (line 404)

/* DWARF original prototype: void AddWaypoint(CHudSpectator * this, float time, Vector pos, Vector
   angle, float fov, int flags) */

void __thiscall
CHudSpectator::AddWaypoint
          (CHudSpectator *this,float time,Vector pos,Vector angle,float fov,int flags)

{
  int iVar1;
  
  if ((angle.x != 0.0) && (time == 0.0)) {
    vJumpAngles[0] = *(float *)pos.y;
    vJumpAngles[1] = *(float *)((int)pos.y + 4);
    vJumpAngles[2] = *(float *)((int)pos.y + 8);
    vJumpOrigin[0] = *(float *)pos.x;
    vJumpOrigin[1] = *(float *)((int)pos.x + 4);
    vJumpOrigin[2] = *(float *)((int)pos.x + 8);
    this->m_FOV = pos.z;
    (*gEngfuncs.SetViewAngles)(vJumpAngles);
    iJumpSpectator = 1;
    return;
  }
  iVar1 = this->m_NumWayPoints;
  if (0x1f < iVar1) {
                    /* WARNING: Could not recover jumptable at 0x00054ff2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*gEngfuncs.Con_Printf)("Too many camera waypoints!\n");
    return;
  }
  this->m_CamPath[iVar1].angle.x = *(vec_t *)pos.y;
  this->m_CamPath[iVar1].angle.y = *(vec_t *)((int)pos.y + 4);
  this->m_CamPath[this->m_NumWayPoints].angle.z = *(vec_t *)((int)pos.y + 8);
  iVar1 = this->m_NumWayPoints;
  this->m_CamPath[iVar1].position.x = *(vec_t *)pos.x;
  this->m_CamPath[iVar1].position.y = *(vec_t *)((int)pos.x + 4);
  this->m_CamPath[this->m_NumWayPoints].position.z = *(vec_t *)((int)pos.x + 8);
  iVar1 = this->m_NumWayPoints;
  this->m_CamPath[iVar1].fov = pos.z;
  this->m_CamPath[iVar1].flags = (int)angle.x;
  this->m_CamPath[iVar1].time = time;
  (*gEngfuncs.Con_DPrintf)("Added waypoint %i\n",iVar1);
  this->m_NumWayPoints = this->m_NumWayPoints + 1;
  return;
}


// CHudSpectator::SetWayInterpolation  @ 00055000  (line 430)

/* DWARF original prototype: void SetWayInterpolation(CHudSpectator * this, cameraWayPoint_t * prev,
   cameraWayPoint_t * start, cameraWayPoint_t * end, cameraWayPoint_t * next) */

void __thiscall
CHudSpectator::SetWayInterpolation
          (CHudSpectator *this,cameraWayPoint_t *prev,cameraWayPoint_t *start,cameraWayPoint_t *end,
          cameraWayPoint_t *next)

{
  CInterpolation *this_00;
  Vector start_00;
  Vector start_01;
  Vector start_02;
  Vector end_00;
  Vector end_01;
  Vector end_02;
  vec_t in_stack_ffffffa0;
  vec_t in_stack_ffffffa4;
  Vector *pVVar1;
  undefined8 in_stack_ffffffa8;
  vec_t in_stack_ffffffb0;
  Vector *in_stack_ffffffb4;
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
  local_34 = (start->angle).x;
  local_28 = (end->angle).x;
  local_24 = (end->angle).y;
  local_20 = (end->angle).z;
  local_30 = (start->angle).y;
  local_2c = (start->angle).z;
  this_00 = &this->m_WayInterpolation;
  start_00.y = (vec_t)&local_28;
  start_00.x = (vec_t)&local_34;
  start_00.z = in_stack_ffffffa0;
  end_00._4_8_ = in_stack_ffffffa8;
  end_00.x = in_stack_ffffffa4;
  CInterpolation::SetViewAngles(this_00,start_00,end_00);
  CInterpolation::SetFOVs(this_00,start->fov,end->fov);
  CInterpolation::SetSmoothing
            (this_00,(bool)((byte)((uint)start->flags >> 1) & 1),
             (bool)((byte)((uint)start->flags >> 2) & 1));
  if ((prev == (cameraWayPoint_t *)0x0) || (next == (cameraWayPoint_t *)0x0)) {
    if (prev == (cameraWayPoint_t *)0x0) {
      if (next == (cameraWayPoint_t *)0x0) {
        local_28 = (end->position).x;
        local_24 = (end->position).y;
        local_20 = (end->position).z;
        local_34 = (start->position).x;
        local_30 = (start->position).y;
        local_2c = (start->position).z;
        pVVar1 = (Vector *)0x0;
      }
      else {
        local_28 = (end->position).x;
        local_24 = (end->position).y;
        local_30 = (start->position).y;
        local_2c = (start->position).z;
        local_20 = (end->position).z;
        local_34 = (start->position).x;
        pVVar1 = &next->position;
      }
      start_02.y = (vec_t)&local_28;
      start_02.x = (vec_t)&local_34;
      start_02.z = (vec_t)pVVar1;
      end_02.z = in_stack_ffffffb0;
      end_02.x = (vec_t)(int)in_stack_ffffffa8;
      end_02.y = (vec_t)(int)((ulonglong)in_stack_ffffffa8 >> 0x20);
      CInterpolation::SetWaypoints(this_00,(Vector *)0x0,start_02,end_02,in_stack_ffffffb4);
      return;
    }
    local_28 = (end->position).x;
    local_24 = (end->position).y;
    local_20 = (end->position).z;
    local_34 = (start->position).x;
    local_30 = (start->position).y;
    local_2c = (start->position).z;
    pVVar1 = (Vector *)0x0;
  }
  else {
    local_28 = (end->position).x;
    local_24 = (end->position).y;
    local_20 = (end->position).z;
    local_34 = (start->position).x;
    pVVar1 = &next->position;
    local_30 = (start->position).y;
    local_2c = (start->position).z;
  }
  start_01.y = (vec_t)&local_28;
  start_01.x = (vec_t)&local_34;
  start_01.z = (vec_t)pVVar1;
  end_01.z = in_stack_ffffffb0;
  end_01.x = (vec_t)(int)in_stack_ffffffa8;
  end_01.y = (vec_t)(int)((ulonglong)in_stack_ffffffa8 >> 0x20);
  CInterpolation::SetWaypoints(this_00,&prev->position,start_01,end_01,in_stack_ffffffb4);
  return;
}


// CHudSpectator::GetDirectorCamera  @ 00055270  (line 457)

/* DWARF original prototype: bool GetDirectorCamera(CHudSpectator * this, Vector * position, Vector
   * angle) */

bool __thiscall CHudSpectator::GetDirectorCamera(CHudSpectator *this,Vector *position,Vector *angle)

{
  float *end;
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  cl_entity_s *pcVar5;
  int iVar6;
  cameraWayPoint_t *pcVar7;
  cameraWayPoint_t *start;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float now@[???]
                       Unresolved local var: float fov@[???]
                       Unresolved local var: cameraWayPoint_t * wp1@[???]
                       Unresolved local var: cameraWayPoint_t * wp2@[???]
                       Unresolved local var: float fraction@[???] */
  fVar4 = gHUD.m_flTime;
  local_2c = 90.0;
  if (this->m_ChaseEntity == 0) {
    if ((((this->m_IsInterpolating != 0) && (iVar3 = this->m_WayPoint, -1 < iVar3)) &&
        (iVar3 < this->m_NumWayPoints + -1)) && (this->m_CamPath[iVar3].time <= gHUD.m_flTime)) {
      pcVar7 = (cameraWayPoint_t *)&this->m_CamPath[iVar3].time;
      start = (cameraWayPoint_t *)&this->m_CamPath[iVar3 + 1].time;
      while (fVar1 = start->time, fVar1 < fVar4) {
        iVar6 = this->m_WayPoint;
        iVar3 = iVar6 + 1;
        this->m_WayPoint = iVar3;
        if (this->m_NumWayPoints + -1 <= iVar3) {
          this->m_IsInterpolating = 0;
          return false;
        }
        end = &this->m_CamPath[iVar6 + 2].time;
        pcVar7 = start;
        if (iVar3 < 1) {
          SetWayInterpolation(this,(cameraWayPoint_t *)0x0,start,(cameraWayPoint_t *)end,
                              (cameraWayPoint_t *)&this->m_CamPath[iVar6 + 3].time);
          start = (cameraWayPoint_t *)end;
        }
        else {
          SetWayInterpolation(this,(cameraWayPoint_t *)&this->m_CamPath[iVar6].time,start,
                              (cameraWayPoint_t *)end,
                              (cameraWayPoint_t *)&this->m_CamPath[iVar6 + 3].time);
          start = (cameraWayPoint_t *)end;
        }
      }
      fVar2 = pcVar7->time;
      if (fVar2 < fVar1) {
        fVar4 = (fVar4 - fVar2) / (fVar1 - fVar2);
        if (fVar4 < 0.0) {
          fVar4 = 0.0;
        }
        else if (1.0 < fVar4) {
          fVar4 = 1.0;
        }
        CInterpolation::Interpolate(&this->m_WayInterpolation,fVar4,position,angle,&local_2c);
        vJumpOrigin[2] = position->z;
        vJumpAngles[0] = angle->x;
        vJumpAngles[1] = angle->y;
        vJumpAngles[2] = angle->z;
        vJumpOrigin[0] = position->x;
        vJumpOrigin[1] = position->y;
        this->m_FOV = local_2c;
        (*gEngfuncs.SetViewAngles)(vJumpAngles);
        iJumpSpectator = 1;
        return true;
      }
    }
  }
  else {
                    /* Unresolved local var: cl_entity_t * ent@[???] */
    pcVar5 = (*gEngfuncs.GetEntityByIndex)(this->m_ChaseEntity);
    if (pcVar5 != (cl_entity_s *)0x0) {
                    /* Unresolved local var: Vector vt@[???] */
      local_28 = (pcVar5->curstate).origin.x;
      local_24 = (pcVar5->curstate).origin.y;
      local_20 = (pcVar5->curstate).origin.z;
      iVar3 = this->m_ChaseEntity;
      iVar6 = (*gEngfuncs.GetMaxClients)();
      if (iVar3 <= iVar6) {
        if ((pcVar5->curstate).solid == 0) {
          local_20 = local_20 - 8.0;
        }
        else if ((pcVar5->curstate).usehull == 1) {
          local_20 = local_20 + 12.0;
        }
        else {
          local_20 = local_20 + 28.0;
        }
      }
      local_20 = local_20 - position->z;
      local_24 = local_24 - position->y;
      local_28 = local_28 - position->x;
      VectorAngles(&local_28,&angle->x);
      angle->x = -angle->x;
      return true;
    }
  }
  return false;
}


// CHudSpectator::VidInit  @ 00053420  (line 573)

/* DWARF original prototype: int VidInit(CHudSpectator * this) */

int __thiscall CHudSpectator::VidInit(CHudSpectator *this)

{
  HANDLE_SPRITE HVar1;
  
  HVar1 = (*gEngfuncs.pfnSPR_Load)("sprites/iplayer.spr");
  this->m_hsprPlayer = HVar1;
  HVar1 = (*gEngfuncs.pfnSPR_Load)("sprites/iplayerblue.spr");
  this->m_hsprPlayerBlue = HVar1;
  HVar1 = (*gEngfuncs.pfnSPR_Load)("sprites/iplayerred.spr");
  this->m_hsprPlayerRed = HVar1;
  HVar1 = (*gEngfuncs.pfnSPR_Load)("sprites/iplayerdead.spr");
  this->m_hsprPlayerDead = HVar1;
  HVar1 = (*gEngfuncs.pfnSPR_Load)("sprites/tile.spr");
  this->m_hsprUnkownMap = HVar1;
  HVar1 = (*gEngfuncs.pfnSPR_Load)("sprites/laserbeam.spr");
  this->m_hsprBeam = HVar1;
  HVar1 = (*gEngfuncs.pfnSPR_Load)("sprites/camera.spr");
  this->m_hsprCamera = HVar1;
  HVar1 = (*gEngfuncs.pfnSPR_Load)("sprites/crosshairs.spr");
  this->m_lastPrimaryObject = 0;
  this->m_flNextObserverInput = 0.0;
  this->m_lastHudMessage = 0;
  this->m_hCrosshair = HVar1;
  this->m_lastSecondaryObject = 0;
  this->m_iSpectatorNumber = 0;
  iJumpSpectator = 0;
  g_iUser2 = 0;
  g_iUser1 = 0;
  return 1;
}


// CHudSpectator::GetFOV  @ 000555b0  (line 595)

/* DWARF original prototype: float GetFOV(CHudSpectator * this) */

float __thiscall CHudSpectator::GetFOV(CHudSpectator *this)

{
  return this->m_FOV;
}


// CHudSpectator::Draw  @ 00053800  (line 604)

/* DWARF original prototype: int Draw(CHudSpectator * this, float flTime) */

int __thiscall CHudSpectator::Draw(CHudSpectator *this,float flTime)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  uint uVar9;
  vec_t *pvVar10;
  uint *puVar11;
  uint *puVar12;
  hud_player_info_t *phVar13;
  int in_GS_OFFSET;
  int local_13c;
  float local_12c;
  float local_128;
  float local_124;
  uint local_120 [64];
  int local_20;
  
                    /* Unresolved local var: int lx@[???]
                       Unresolved local var: char[256] string@[???]
                       Unresolved local var: float * color@[???] */
  iVar5 = g_iUser1;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar6 = 0;
  if (g_iUser1 != 0) {
    if ((g_iUser1 == 5) && (this->m_zoomDelta != 0.0)) {
      fVar1 = this->m_zoomDelta + this->m_mapZoom;
      if (fVar1 <= 3.0) {
        fVar2 = 0.5;
        if (0.5 <= fVar1) {
          fVar2 = fVar1;
        }
        this->m_mapZoom = fVar2;
      }
      else {
        this->m_mapZoom = 3.0;
      }
    }
    if ((this->m_moveDelta != 0.0) && (iVar5 != 3)) {
                    /* Unresolved local var: Vector right@[???] */
      (*gEngfuncs.pfnAngleVectors)(&v_angles.x,(float *)0x0,&local_12c,(float *)0x0);
      VectorNormalize(&local_12c);
      VectorScale(&local_12c,this->m_moveDelta,&local_12c);
      iVar5 = g_iUser1;
      (this->m_mapOrigin).x = (this->m_mapOrigin).x + local_12c;
      (this->m_mapOrigin).y = (this->m_mapOrigin).y + local_128;
      (this->m_mapOrigin).z = (this->m_mapOrigin).z + local_124;
    }
    if ((4 < iVar5) && (this->m_drawnames->value != 0.0)) {
      phVar13 = g_PlayerInfoList;
      pvVar10 = &this->m_vPlayerPos[0].y;
      TeamFortressViewport::GetAllPlayersInfo(gViewPort);
      local_13c = 1;
      do {
        phVar13 = phVar13 + 1;
        if (0.0 <= pvVar10[1]) {
          if (this->m_pip->value != 0.0) {
            iVar6 = (this->m_OverviewData).insetWindowX;
            fVar4 = (float)gHUD.m_scrinfo.iWidth / 1280.0;
            fVar1 = 1.0;
            fVar2 = fVar1;
            if (1.0 < fVar4) {
              fVar2 = fVar4;
            }
            if (fVar2 * (float)iVar6 < ((Vector *)(pvVar10 + -1))->x) {
                    /* Unresolved local var: int i@[???] */
              iVar5 = (this->m_OverviewData).insetWindowY;
              fVar2 = (float)gHUD.m_scrinfo.iHeight / 720.0;
              fVar3 = fVar1;
              if (1.0 < fVar2) {
                fVar3 = fVar2;
              }
              if (fVar3 * (float)iVar5 < *pvVar10) {
                if (fVar4 <= 1.0) {
                  fVar4 = fVar1;
                }
                if (((Vector *)(pvVar10 + -1))->x <
                    fVar4 * (float)(iVar6 + (this->m_OverviewData).insetWindowWidth)) {
                  if (fVar2 <= 1.0) {
                    fVar2 = fVar1;
                  }
                  if (*pvVar10 < fVar2 * (float)(iVar5 + (this->m_OverviewData).insetWindowHeight))
                  goto LAB_00053a1a;
                }
              }
            }
          }
          pfVar7 = GetClientColor(local_13c);
          __sprintf_chk(local_120,1,0x100,&DAT_000c4b6e,phVar13->name);
          puVar12 = local_120;
          do {
            puVar11 = puVar12;
            uVar8 = *puVar11 + 0xfefefeff & ~*puVar11;
            uVar9 = uVar8 & 0x80808080;
            puVar12 = puVar11 + 1;
          } while (uVar9 == 0);
          if ((uVar8 & 0x8080) == 0) {
            puVar12 = (uint *)((int)puVar11 + 6);
            uVar9 = uVar9 >> 0x10;
          }
          (*gEngfuncs.pfnDrawSetTextColor)(*pfVar7,pfVar7[1],pfVar7[2]);
          (*gEngfuncs.pfnDrawConsoleString)
                    ((int)(((Vector *)(pvVar10 + -1))->x -
                          (float)(int)(((int)puVar12 +
                                       ((-3 - (uint)CARRY1((byte)uVar9,(byte)uVar9)) -
                                       (int)local_120)) * 3)),(int)*pvVar10,(char *)local_120);
        }
LAB_00053a1a:
        pvVar10 = pvVar10 + 3;
        local_13c = local_13c + 1;
      } while ((vec_t *)&this->m_hsprPlayerRed != pvVar10);
    }
    iVar6 = 1;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}


// CHudSpectator::DirectorMessage  @ 00056010  (line 683)

/* DWARF original prototype: void DirectorMessage(CHudSpectator * this, int iSize, void * pbuf) */

void __thiscall CHudSpectator::DirectorMessage(CHudSpectator *this,int iSize,void *pbuf)

{
  Vector pos;
  Vector angle;
  client_textmessage_t *pcVar1;
  pfnEngSrc_pfnFilteredClientCmd_t p_Var2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  cameraWayPoint_t *next;
  undefined4 in_stack_ffffff8c;
  vec_t in_stack_ffffff90;
  float in_stack_ffffff94;
  int in_stack_ffffff98;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float f1@[???]
                       Unresolved local var: float f2@[???]
                       Unresolved local var: char * string@[???]
                       Unresolved local var: Vector v1@[???]
                       Unresolved local var: Vector v2@[???]
                       Unresolved local var: int i1@[???]
                       Unresolved local var: int i2@[???]
                       Unresolved local var: int i3@[???]
                       Unresolved local var: int cmd@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar3 = READ_BYTE();
  p_Var2 = gEngfuncs.pfnFilteredClientCmd;
  switch(iVar3) {
  default:
    (*gEngfuncs.Con_DPrintf)("CHudSpectator::DirectorMessage: unknown command %i.\n",iVar3);
    break;
  case 1:
    g_iPlayerClass = 0;
    g_iTeamNumber = 0;
    CHud::MsgFunc_InitHUD(&gHUD,(char *)0x0,0,(void *)0x0);
    CHud::MsgFunc_ResetHUD(&gHUD,(char *)0x0,0,(void *)0x0);
    break;
  case 2:
    iVar3 = READ_WORD();
    this->m_lastPrimaryObject = iVar3;
    iVar3 = READ_WORD();
    this->m_lastSecondaryObject = iVar3;
    iVar3 = READ_LONG();
    this->m_iObserverFlags = iVar3;
    if (this->m_autoDirector->value != 0.0) {
      iVar3 = this->m_lastPrimaryObject;
      if ((iVar3 != g_iUser2) || (this->m_lastSecondaryObject != g_iUser3)) {
        V_ResetChaseCam();
        iVar3 = this->m_lastPrimaryObject;
        g_iUser3 = this->m_lastSecondaryObject;
      }
      g_iUser2 = iVar3;
      this->m_IsInterpolating = 0;
      this->m_ChaseEntity = 0;
    }
    break;
  case 3:
    if (this->m_autoDirector->value != 0.0) {
      iVar3 = READ_BYTE();
      SetModes(this,iVar3,-1);
    }
    break;
  case 4:
    fVar18 = READ_COORD();
    fVar12 = READ_COORD();
    fVar13 = READ_COORD();
    fVar14 = READ_COORD();
    fVar15 = READ_COORD();
    fVar16 = READ_COORD();
    iVar3 = READ_BYTE();
    iVar11 = READ_WORD();
    if (this->m_autoDirector->value != 0.0) {
      SetModes(this,3,-1);
      vJumpAngles[0] = fVar14;
      vJumpOrigin[0] = fVar18;
      vJumpOrigin[1] = fVar12;
      vJumpOrigin[2] = fVar13;
      this->m_FOV = (float)iVar3;
      vJumpAngles[1] = fVar15;
      vJumpAngles[2] = fVar16;
      (*gEngfuncs.SetViewAngles)(vJumpAngles);
      iJumpSpectator = 1;
      this->m_ChaseEntity = iVar11;
    }
    break;
  case 5:
    READ_FLOAT();
    break;
  case 6:
                    /* Unresolved local var: client_textmessage_t * msg@[???] */
    iVar3 = this->m_lastHudMessage;
    iVar11 = READ_BYTE();
    this->m_HUDMessages[iVar3].effect = iVar11;
    uVar7 = READ_LONG();
    uVar9 = (uVar7 & 0xff0000) >> 0x10;
    pcVar1 = this->m_HUDMessages + iVar3;
    pcVar1->r1 = (char)uVar9;
    pcVar1->g1 = (char)(uVar9 >> 8);
    pcVar1->b1 = (char)(uVar9 >> 0x10);
    pcVar1->a1 = (char)(uVar9 >> 0x18);
    uVar10 = uVar7 >> 8 & 0xff;
    uVar9 = uVar7 & 0xff;
    pcVar1 = this->m_HUDMessages + iVar3;
    pcVar1->g1 = (char)uVar10;
    pcVar1->b1 = (char)(uVar10 >> 8);
    pcVar1->a1 = (char)(uVar10 >> 0x10);
    pcVar1->r2 = (char)(uVar10 >> 0x18);
    pcVar1 = this->m_HUDMessages + iVar3;
    pcVar1->b1 = (char)uVar9;
    pcVar1->a1 = (char)(uVar9 >> 8);
    pcVar1->r2 = (char)(uVar9 >> 0x10);
    pcVar1->g2 = (char)(uVar9 >> 0x18);
    this->m_HUDMessages[iVar3].r2 = (byte)((uVar7 & 0xff0000) >> 0x10);
    this->m_HUDMessages[iVar3].b2 = (byte)uVar7;
    this->m_HUDMessages[iVar3].a1 = 0xff;
    this->m_HUDMessages[iVar3].g2 = (byte)(uVar7 >> 8);
    this->m_HUDMessages[iVar3].a2 = 0xff;
    fVar18 = READ_FLOAT();
    this->m_HUDMessages[iVar3].x = fVar18;
    fVar18 = READ_FLOAT();
    this->m_HUDMessages[iVar3].y = fVar18;
    fVar18 = READ_FLOAT();
    this->m_HUDMessages[iVar3].fadein = fVar18;
    fVar18 = READ_FLOAT();
    this->m_HUDMessages[iVar3].fadeout = fVar18;
    fVar18 = READ_FLOAT();
    this->m_HUDMessages[iVar3].holdtime = fVar18;
    fVar18 = READ_FLOAT();
    this->m_HUDMessages[iVar3].fxtime = fVar18;
    pcVar8 = READ_STRING();
    strncpy(this->m_HUDMessageText[this->m_lastHudMessage],pcVar8,0x80);
    iVar11 = this->m_lastHudMessage;
    this->m_HUDMessageText[iVar11][0x7f] = '\0';
    this->m_HUDMessages[iVar3].pMessage = this->m_HUDMessageText[iVar11];
    this->m_HUDMessages[iVar3].pName = "HUD_MESSAGE";
    CHudMessage::MessageAdd(&gHUD.m_Message,this->m_HUDMessages + iVar3);
    this->m_lastHudMessage = (this->m_lastHudMessage + 1) % 8;
    break;
  case 7:
    pcVar8 = READ_STRING();
    fVar18 = READ_FLOAT();
    (*(gEngfuncs.pEventAPI)->EV_PlaySound)(0,&v_origin.x,4,pcVar8,fVar18,0.8,0,100);
    break;
  case 8:
    READ_LONG();
    iVar3 = READ_LONG();
    this->m_iSpectatorNumber = iVar3;
    READ_WORD();
    TeamFortressViewport::UpdateSpectatorPanel(gViewPort);
    break;
  case 9:
    pcVar8 = READ_STRING();
    CImageLabel::LoadImage(gViewPort->m_pSpectatorPanel->m_TopBanner,pcVar8);
    TeamFortressViewport::UpdateSpectatorPanel(gViewPort);
    break;
  case 10:
    pcVar8 = READ_STRING();
    (*p_Var2)(pcVar8);
    break;
  case 0xe:
    fVar18 = READ_COORD();
    fVar12 = READ_COORD();
    fVar13 = READ_COORD();
    fVar14 = READ_COORD();
    fVar15 = READ_COORD();
    fVar16 = READ_COORD();
    iVar3 = READ_BYTE();
    READ_BYTE();
    if (this->m_autoDirector->value != 0.0) {
      SetModes(this,3,-1);
      vJumpAngles[0] = fVar14;
      vJumpOrigin[0] = fVar18;
      vJumpOrigin[1] = fVar12;
      vJumpOrigin[2] = fVar13;
      this->m_FOV = (float)iVar3;
      vJumpAngles[1] = fVar15;
      vJumpAngles[2] = fVar16;
      (*gEngfuncs.SetViewAngles)(vJumpAngles);
      iJumpSpectator = 1;
    }
    break;
  case 0xf:
    iVar3 = READ_BYTE();
    this->m_NumWayPoints = 0;
    this->m_WayPoint = 0;
    if (0 < iVar3) {
      iVar11 = 0;
      do {
        fVar18 = gHUD.m_flTime;
        iVar11 = iVar11 + 1;
        iVar4 = READ_SHORT();
        fVar12 = READ_COORD();
        fVar13 = READ_COORD();
        fVar14 = READ_COORD();
        fVar15 = READ_COORD();
        fVar16 = READ_COORD();
        fVar17 = READ_COORD();
        iVar5 = READ_BYTE();
        iVar6 = READ_BYTE();
        pos.y = (vec_t)&local_28;
        pos.x = (vec_t)&local_34;
        pos.z = (float)iVar5;
        angle.y = (vec_t)in_stack_ffffff8c;
        angle.x = (vec_t)iVar6;
        angle.z = in_stack_ffffff90;
        local_34 = fVar12;
        local_30 = fVar13;
        local_2c = fVar14;
        local_28 = fVar15;
        local_24 = fVar16;
        local_20 = fVar17;
        AddWaypoint(this,(float)iVar4 / 100.0 + fVar18,pos,angle,in_stack_ffffff94,in_stack_ffffff98
                   );
      } while (iVar3 != iVar11);
    }
    if (this->m_autoDirector->value == 0.0) {
      this->m_NumWayPoints = 0;
    }
    else {
      SetModes(this,3,-1);
      this->m_IsInterpolating = 1;
      if (this->m_NumWayPoints < 3) {
        next = (cameraWayPoint_t *)0x0;
      }
      else {
        next = this->m_CamPath + 2;
      }
      SetWayInterpolation(this,(cameraWayPoint_t *)0x0,this->m_CamPath,this->m_CamPath + 1,next);
    }
  }
  return;
}


// CHudSpectator::FindNextPlayer  @ 000555c0  (line 885)

/* DWARF original prototype: void FindNextPlayer(CHudSpectator * this, bool bReverse) */

void __thiscall CHudSpectator::FindNextPlayer(CHudSpectator *this,bool bReverse)

{
  int iVar1;
  cl_entity_s *pcVar2;
  cl_entity_s *pcVar3;
  int iVar4;
  int in_GS_OFFSET;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: int iStart@[???]
                       Unresolved local var: cl_entity_t * pEnt@[???]
                       Unresolved local var: int iCurrent@[???]
                       Unresolved local var: int iDir@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar1 == 0) {
                    /* Unresolved local var: char[32] cmdstring@[???] */
    __sprintf_chk(local_40,1,0x20,"follownext %i",bReverse);
    (*gEngfuncs.pfnServerCmd)(local_40);
  }
  else {
                    /* Unresolved local var: int iStart@[???]
                       Unresolved local var: cl_entity_t * pEnt@[???]
                       Unresolved local var: int iCurrent@[???]
                       Unresolved local var: int iDir@[???] */
    iVar1 = g_iUser2;
    if (g_iUser2 == 0) {
      iVar1 = 1;
    }
    g_iUser2 = 0;
    TeamFortressViewport::GetAllPlayersInfo(gViewPort);
    iVar4 = iVar1;
    do {
      iVar4 = iVar4 + ((-(uint)!bReverse & 2) - 1);
      if (iVar4 < 0x41) {
        if (iVar4 < 1) {
          iVar4 = 0x40;
        }
      }
      else {
        iVar4 = 1;
      }
      pcVar2 = (*gEngfuncs.GetEntityByIndex)(iVar4);
      if ((((pcVar2 != (cl_entity_s *)0x0) && (pcVar2->player != 0)) &&
          ((pcVar2->curstate).solid != 0)) &&
         ((pcVar3 = (*gEngfuncs.GetLocalPlayer)(), pcVar2 != pcVar3 &&
          (g_PlayerInfoList[pcVar2->index].name != (char *)0x0)))) goto LAB_000556f0;
    } while (iVar4 != iVar1);
    iVar4 = g_iUser2;
    if (g_iUser2 == 0) {
      (*gEngfuncs.Con_DPrintf)("No observer targets.\n");
      vJumpOrigin[0] = (this->m_cameraOrigin).x;
      vJumpOrigin[1] = (this->m_cameraOrigin).y;
      vJumpOrigin[2] = (this->m_cameraOrigin).z;
      vJumpAngles[0] = (this->m_cameraAngles).x;
      vJumpAngles[1] = (this->m_cameraAngles).y;
      vJumpAngles[2] = (this->m_cameraAngles).z;
    }
    else {
LAB_000556f0:
      g_iUser2 = iVar4;
      vJumpOrigin[0] = (pcVar2->origin).x;
      vJumpOrigin[1] = (pcVar2->origin).y;
      vJumpOrigin[2] = (pcVar2->origin).z;
      vJumpAngles[0] = (pcVar2->angles).x;
      vJumpAngles[1] = (pcVar2->angles).y;
      vJumpAngles[2] = (pcVar2->angles).z;
    }
    iJumpSpectator = 1;
    TeamFortressViewport::MsgFunc_ResetFade(gViewPort,(char *)0x0,0,(void *)0x0);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CHudSpectator::FindPlayer  @ 00055840  (line 960)

/* DWARF original prototype: void FindPlayer(CHudSpectator * this, char * name) */

void __thiscall CHudSpectator::FindPlayer(CHudSpectator *this,char *name)

{
  int iVar1;
  cl_entity_s *pcVar2;
  cl_entity_s *pcVar3;
  int iVar4;
  int in_GS_OFFSET;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: cl_entity_t * pEnt@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar1 == 0) {
                    /* Unresolved local var: char[32] cmdstring@[???] */
    __sprintf_chk(local_40,1,0x20,"follow %s",name);
    (*gEngfuncs.pfnServerCmd)(local_40);
  }
  else {
                    /* Unresolved local var: int i@[???] */
    iVar1 = 1;
    g_iUser2 = 0;
    TeamFortressViewport::GetAllPlayersInfo(gViewPort);
    do {
      pcVar2 = (*gEngfuncs.GetEntityByIndex)(iVar1);
      if ((((pcVar2 != (cl_entity_s *)0x0) && (pcVar2->player != 0)) &&
          ((pcVar2->curstate).solid != 0)) &&
         (((pcVar3 = (*gEngfuncs.GetLocalPlayer)(), pcVar2 != pcVar3 &&
           (g_PlayerInfoList[pcVar2->index].name != (char *)0x0)) &&
          (iVar4 = strcasecmp(g_PlayerInfoList[pcVar2->index].name,name), iVar4 == 0))))
      goto LAB_000558ea;
      iVar1 = iVar1 + 1;
    } while (iVar1 != 0x40);
    iVar1 = g_iUser2;
    if (g_iUser2 == 0) {
      (*gEngfuncs.Con_DPrintf)("No observer targets.\n");
      vJumpOrigin[0] = (this->m_cameraOrigin).x;
      vJumpOrigin[1] = (this->m_cameraOrigin).y;
      vJumpOrigin[2] = (this->m_cameraOrigin).z;
      vJumpAngles[0] = (this->m_cameraAngles).x;
      vJumpAngles[1] = (this->m_cameraAngles).y;
      vJumpAngles[2] = (this->m_cameraAngles).z;
    }
    else {
LAB_000558ea:
      g_iUser2 = iVar1;
      vJumpOrigin[0] = (pcVar2->origin).x;
      vJumpOrigin[1] = (pcVar2->origin).y;
      vJumpOrigin[2] = (pcVar2->origin).z;
      vJumpAngles[0] = (pcVar2->angles).x;
      vJumpAngles[1] = (pcVar2->angles).y;
      vJumpAngles[2] = (pcVar2->angles).z;
    }
    iJumpSpectator = 1;
    TeamFortressViewport::MsgFunc_ResetFade(gViewPort,(char *)0x0,0,(void *)0x0);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CHudSpectator::HandleButtonsDown  @ 00056960  (line 1017)

/* DWARF original prototype: void HandleButtonsDown(CHudSpectator * this, int ButtonPressed) */

void __thiscall CHudSpectator::HandleButtonsDown(CHudSpectator *this,int ButtonPressed)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iNewMainMode;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: double time@[???]
                       Unresolved local var: int newMainMode@[???]
                       Unresolved local var: int newInsetMode@[???] */
  (*gEngfuncs.GetClientTime)();
  iNewMainMode = g_iUser1;
  if (((gViewPort != (TeamFortressViewport *)0x0) && (gHUD.m_iIntermission == 0)) && (g_iUser1 != 0)
     ) {
    fVar1 = this->m_pip->value;
    iVar2 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)();
    if (((iVar2 == 0) || (iVar2 = (*gEngfuncs.IsSpectateOnly)(), iVar2 != 0)) &&
       (this->m_flNextObserverInput <= (float)extraout_ST0)) {
      if ((ButtonPressed & 4U) != 0) {
        SpectatorPanel::ShowMenu
                  (gViewPort->m_pSpectatorPanel,
                   (bool)(gViewPort->m_pSpectatorPanel->m_menuVisible ^ 1));
      }
      if ((ButtonPressed & 0x20U) == 0) {
        iVar2 = (int)fVar1;
      }
      else {
                    /* Unresolved local var: int newInsetMode@[???] */
        iVar2 = (int)this->m_pip->value + 1;
        if (g_iUser1 < 5) {
          if (iVar2 < 5) {
            if (iVar2 == 1) {
              iVar2 = 3;
            }
          }
          else {
            iVar2 = 0;
          }
        }
        else if (2 < iVar2) {
          iVar2 = 0;
        }
      }
      iVar3 = (*gEngfuncs.IsSpectateOnly)();
      if (iVar3 != 0) {
        if ((ButtonPressed & 2U) != 0) {
          if (g_iUser1 == 1) {
            iNewMainMode = 2;
          }
          else if (g_iUser1 == 2) {
            iNewMainMode = 4;
          }
          else if (g_iUser1 == 4) {
            iNewMainMode = 3;
          }
          else if (g_iUser1 == 3) {
            iNewMainMode = 5;
          }
          else {
            iNewMainMode = (uint)(g_iUser1 == 5) * 4 + 2;
          }
        }
        if ((ButtonPressed & 0x801U) != 0) {
          FindNextPlayer(this,(bool)((byte)((uint)ButtonPressed >> 0xb) & 1));
          if (g_iUser1 == 3) {
            (*gEngfuncs.SetViewAngles)(vJumpAngles);
            iJumpSpectator = 1;
          }
          this->m_autoDirector->value = 0.0;
        }
      }
      SetModes(this,iNewMainMode,iVar2);
      if (g_iUser1 == 5) {
        if ((ButtonPressed & 8U) != 0) {
          this->m_zoomDelta = 0.01;
        }
        if ((ButtonPressed & 0x10U) != 0) {
          this->m_zoomDelta = -0.01;
        }
        if ((ButtonPressed & 0x200U) != 0) {
          this->m_moveDelta = -12.0;
        }
        if ((ButtonPressed & 0x400U) != 0) {
          this->m_moveDelta = 12.0;
        }
      }
      this->m_flNextObserverInput = (float)extraout_ST0 + 0.2;
    }
  }
  return;
}


// CHudSpectator::HandleButtonsUp  @ 00055a60  (line 1117)

/* DWARF original prototype: void HandleButtonsUp(CHudSpectator * this, int ButtonPressed) */

void __thiscall CHudSpectator::HandleButtonsUp(CHudSpectator *this,int ButtonPressed)

{
  char cVar1;
  
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (cVar1 = (**(code **)(*(int *)gViewPort->m_pSpectatorPanel + 0x28))
                        (gViewPort->m_pSpectatorPanel), cVar1 != '\0')) {
    if ((ButtonPressed & 0x18U) != 0) {
      this->m_zoomDelta = 0.0;
    }
    if ((ButtonPressed & 0x600U) != 0) {
      this->m_moveDelta = 0.0;
    }
  }
  return;
}


// CHudSpectator::SetModes  @ 00055ab0  (line 1131)

/* DWARF original prototype: void SetModes(CHudSpectator * this, int iNewMainMode, int
   iNewInsetMode) */

void __thiscall CHudSpectator::SetModes(CHudSpectator *this,int iNewMainMode,int iNewInsetMode)

{
  int iVar1;
  cl_entity_s *pcVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  cl_entity_s *pcVar6;
  uint *puVar7;
  uint *puVar8;
  int in_GS_OFFSET;
  bool bVar9;
  uint local_90 [32];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (iNewMainMode == -1) {
    iNewMainMode = g_iUser1;
  }
  if (iNewInsetMode == -1) {
    iNewInsetMode = (int)this->m_pip->value;
  }
  this->m_pip->value = (float)iNewInsetMode;
  if (5 < iNewMainMode - 1U) {
    (*gEngfuncs.Con_Printf)("Invalid spectator mode.\n");
    goto LAB_00055d08;
  }
  bVar9 = iNewMainMode == g_iUser1;
  this->m_IsInterpolating = 0;
  this->m_ChaseEntity = 0;
  if (bVar9) goto LAB_00055cfb;
                    /* Unresolved local var: char[128] string@[???] */
  iVar1 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar1 == 0) {
                    /* Unresolved local var: char[32] cmdstring@[???] */
    __sprintf_chk(local_90,1,0x20,"specmode %i",iNewMainMode);
    (*gEngfuncs.pfnServerCmd)((char *)local_90);
    goto LAB_00055d08;
  }
  if ((g_iUser2 == 0) && (iNewMainMode != 3)) {
    pcVar2 = (*gEngfuncs.GetEntityByIndex)(this->m_lastPrimaryObject);
    if (((pcVar2 == (cl_entity_s *)0x0) ||
        (((pcVar2->player == 0 || ((pcVar2->curstate).solid == 0)) ||
         (pcVar6 = (*gEngfuncs.GetLocalPlayer)(), pcVar2 == pcVar6)))) ||
       (g_PlayerInfoList[pcVar2->index].name == (char *)0x0)) {
      FindNextPlayer(this,false);
    }
    else {
      g_iUser2 = this->m_lastPrimaryObject;
      g_iUser3 = this->m_lastSecondaryObject;
    }
  }
  switch(iNewMainMode) {
  default:
switchD_00055b83_caseD_0:
    if (1 < g_iUser1 - 3U) goto LAB_00055bce;
    break;
  case 1:
    g_iUser1 = 1;
    goto LAB_00055bce;
  case 2:
    g_iUser1 = 2;
    goto LAB_00055bce;
  case 3:
    g_iUser1 = 3;
    if (g_iUser2 != 0) {
      V_GetChasePos(g_iUser2,&v_cl_angles.x,vJumpOrigin,vJumpAngles);
      (*gEngfuncs.SetViewAngles)(vJumpAngles);
      iJumpSpectator = 1;
      goto switchD_00055b83_caseD_0;
    }
    break;
  case 4:
    g_iUser1 = 4;
    break;
  case 5:
    g_iUser1 = 5;
    this->m_mapZoom = (this->m_OverviewData).zoom;
    goto LAB_00055baa;
  case 6:
    g_iUser1 = 6;
    this->m_mapZoom = (this->m_OverviewData).zoom;
LAB_00055baa:
    (this->m_mapOrigin).x = (this->m_OverviewData).origin.x;
    (this->m_mapOrigin).y = (this->m_OverviewData).origin.y;
    (this->m_mapOrigin).z = (this->m_OverviewData).origin.z;
LAB_00055bce:
    (this->m_crosshairRect).left = 0;
    (this->m_crosshairRect).right = 0;
    (this->m_crosshairRect).top = 0;
    (this->m_crosshairRect).bottom = 0;
    (*gEngfuncs.pfnSetCrosshair)(0,(wrect_t)ZEXT816(0),0,0,0);
    goto LAB_00055c25;
  }
  (this->m_crosshairRect).left = 0x18;
  (this->m_crosshairRect).right = 0x30;
  (this->m_crosshairRect).top = 0;
  (this->m_crosshairRect).bottom = 0x18;
  (*gEngfuncs.pfnSetCrosshair)(this->m_hCrosshair,this->m_crosshairRect,0xff,0xff,0xff);
LAB_00055c25:
  TeamFortressViewport::MsgFunc_ResetFade(gViewPort,(char *)0x0,0,(void *)0x0);
  __sprintf_chk(local_90,1,0x80,"#Spec_Mode%d",g_iUser1);
  pcVar3 = CHudTextMessage::BufferedLocaliseTextString((char *)local_90);
  __sprintf_chk(local_90,1,0x80,&DAT_000bfb94,4,pcVar3);
  puVar8 = local_90;
  do {
    puVar7 = puVar8;
    uVar4 = *puVar7 + 0xfefefeff & ~*puVar7;
    uVar5 = uVar4 & 0x80808080;
    puVar8 = puVar7 + 1;
  } while (uVar5 == 0);
  if ((uVar4 & 0x8080) == 0) {
    puVar8 = (uint *)((int)puVar7 + 6);
    uVar5 = uVar5 >> 0x10;
  }
  CHudTextMessage::MsgFunc_TextMsg
            (&gHUD.m_TextMessage,(char *)0x0,
             (int)((int)puVar8 + (-(int)local_90 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) + -2),
             local_90);
LAB_00055cfb:
  TeamFortressViewport::UpdateSpectatorPanel(gViewPort);
LAB_00055d08:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CHudSpectator::IsActivePlayer  @ 00056c30  (line 1238)

/* DWARF original prototype: bool IsActivePlayer(CHudSpectator * this, cl_entity_t * ent) */

bool __thiscall CHudSpectator::IsActivePlayer(CHudSpectator *this,cl_entity_t *ent)

{
  cl_entity_s *pcVar1;
  
  if (((ent != (cl_entity_t *)0x0) && (ent->player != 0)) && ((ent->curstate).solid != 0)) {
    pcVar1 = (*gEngfuncs.GetLocalPlayer)();
    if (ent != pcVar1) {
      return g_PlayerInfoList[ent->index].name != (char *)0x0;
    }
  }
  return false;
}


// CHudSpectator::ParseOverviewFile  @ 00053e00  (line 1248)

/* DWARF original prototype: bool ParseOverviewFile(CHudSpectator * this) */

bool __thiscall CHudSpectator::ParseOverviewFile(CHudSpectator *this)

{
  bool bVar1;
  int in_EAX;
  int iVar2;
  byte *pbVar3;
  char *pcVar4;
  long lVar5;
  int in_GS_OFFSET;
  double dVar6;
  char local_61e [251];
  undefined1 auStack_523 [4];
  undefined1 local_51f [255];
  char local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: char[255] filename@[???]
                       Unresolved local var: char[255] levelname@[???]
                       Unresolved local var: char[1024] token@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: char * pfile@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = __stpcpy_chk(local_51f,in_EAX + 0x581,0xff);
  auStack_523[iVar2 - (int)local_51f] = 0;
  __sprintf_chk(local_61e,1,0xff,"overviews/%s.txt",local_51f);
  pbVar3 = (*gEngfuncs.COM_LoadFile)(local_61e,5,(int *)0x0);
  if (pbVar3 == (byte *)0x0) {
    (*gEngfuncs.Con_DPrintf)
              ("Couldn\'t open file %s. Using default values for overiew mode.\n",local_61e);
    bVar1 = false;
  }
  else {
    while (pbVar3 = (byte *)(*gEngfuncs.COM_ParseFile)((char *)pbVar3,local_420),
          pbVar3 != (byte *)0x0) {
      iVar2 = strcasecmp(local_420,"global");
      if (iVar2 == 0) {
        pcVar4 = (*gEngfuncs.COM_ParseFile)((char *)pbVar3,local_420);
        iVar2 = strcasecmp(local_420,"{");
        if (iVar2 != 0) goto LAB_000542b0;
        while( true ) {
          pbVar3 = (byte *)(*gEngfuncs.COM_ParseFile)(pcVar4,local_420);
          iVar2 = strcasecmp(local_420,"}");
          if (iVar2 == 0) break;
          iVar2 = strcasecmp(local_420,"zoom");
          if (iVar2 == 0) {
            pcVar4 = (*gEngfuncs.COM_ParseFile)((char *)pbVar3,local_420);
            dVar6 = strtod(local_420,(char **)0x0);
            *(float *)(in_EAX + 0x5c8) = (float)dVar6;
          }
          else {
            iVar2 = strcasecmp(local_420,"origin");
            if (iVar2 == 0) {
              pcVar4 = (*gEngfuncs.COM_ParseFile)((char *)pbVar3,local_420);
              dVar6 = strtod(local_420,(char **)0x0);
              *(float *)(in_EAX + 0x5bc) = (float)dVar6;
              pcVar4 = (*gEngfuncs.COM_ParseFile)(pcVar4,local_420);
              dVar6 = strtod(local_420,(char **)0x0);
              *(float *)(in_EAX + 0x5c0) = (float)dVar6;
              pcVar4 = (*gEngfuncs.COM_ParseFile)(pcVar4,local_420);
              dVar6 = strtod(local_420,(char **)0x0);
              *(float *)(in_EAX + 0x5c4) = (float)dVar6;
            }
            else {
              iVar2 = strcasecmp(local_420,"rotated");
              if (iVar2 == 0) {
                pcVar4 = (*gEngfuncs.COM_ParseFile)((char *)pbVar3,local_420);
                lVar5 = strtol(local_420,(char **)0x0,10);
                *(long *)(in_EAX + 0x6d4) = lVar5;
              }
              else {
                iVar2 = strcasecmp(local_420,"inset");
                if (iVar2 != 0) goto LAB_00054228;
                pcVar4 = (*gEngfuncs.COM_ParseFile)((char *)pbVar3,local_420);
                dVar6 = strtod(local_420,(char **)0x0);
                *(int *)(in_EAX + 0x6d8) = (int)dVar6;
                pcVar4 = (*gEngfuncs.COM_ParseFile)(pcVar4,local_420);
                dVar6 = strtod(local_420,(char **)0x0);
                *(int *)(in_EAX + 0x6dc) = (int)dVar6;
                pcVar4 = (*gEngfuncs.COM_ParseFile)(pcVar4,local_420);
                dVar6 = strtod(local_420,(char **)0x0);
                *(int *)(in_EAX + 0x6e4) = (int)dVar6;
                pcVar4 = (*gEngfuncs.COM_ParseFile)(pcVar4,local_420);
                dVar6 = strtod(local_420,(char **)0x0);
                *(int *)(in_EAX + 0x6e0) = (int)dVar6;
              }
            }
          }
        }
      }
      else {
        iVar2 = strcasecmp(local_420,"layer");
        if (iVar2 == 0) {
          if (*(int *)(in_EAX + 0x5cc) == 1) {
            (*gEngfuncs.Con_Printf)
                      ("Error parsing overview file %s. ( too many layers )\n",local_61e);
            bVar1 = false;
            goto LAB_0005423f;
          }
          pcVar4 = (*gEngfuncs.COM_ParseFile)((char *)pbVar3,local_420);
          iVar2 = strcasecmp(local_420,"{");
          if (iVar2 != 0) {
LAB_000542b0:
            (*gEngfuncs.Con_Printf)("Error parsing overview file %s. (expected { )\n",local_61e);
            bVar1 = false;
            goto LAB_0005423f;
          }
          while( true ) {
            pbVar3 = (byte *)(*gEngfuncs.COM_ParseFile)(pcVar4,local_420);
            iVar2 = strcasecmp(local_420,"}");
            if (iVar2 == 0) break;
            iVar2 = strcasecmp(local_420,"image");
            if (iVar2 == 0) {
              pcVar4 = (*gEngfuncs.COM_ParseFile)((char *)pbVar3,local_420);
              strcpy((char *)(in_EAX + 0x5d4 + *(int *)(in_EAX + 0x5cc) * 0xff),local_420);
            }
            else {
              iVar2 = strcasecmp(local_420,"height");
              if (iVar2 != 0) goto LAB_00054228;
              pcVar4 = (*gEngfuncs.COM_ParseFile)((char *)pbVar3,local_420);
              dVar6 = strtod(local_420,(char **)0x0);
              *(float *)(in_EAX + 0x5d0 + *(int *)(in_EAX + 0x5cc) * 4) = (float)dVar6;
            }
          }
          *(int *)(in_EAX + 0x5cc) = *(int *)(in_EAX + 0x5cc) + 1;
        }
      }
    }
    (*gEngfuncs.COM_FreeFile)((void *)0x0);
    *(undefined4 *)(in_EAX + 0xef4) = *(undefined4 *)(in_EAX + 0x5bc);
    *(undefined4 *)(in_EAX + 0xef0) = *(undefined4 *)(in_EAX + 0x5c8);
    *(undefined4 *)(in_EAX + 0xef8) = *(undefined4 *)(in_EAX + 0x5c0);
    *(undefined4 *)(in_EAX + 0xefc) = *(undefined4 *)(in_EAX + 0x5c4);
    bVar1 = true;
  }
LAB_0005423f:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar1;
LAB_00054228:
  (*gEngfuncs.Con_Printf)("Error parsing overview file %s. (%s unkown)\n",local_61e,local_420);
  bVar1 = false;
  goto LAB_0005423f;
}


// CHudSpectator::ParseOverviewFile  @ 00056c80  (line 1249)

/* DWARF original prototype: bool ParseOverviewFile(CHudSpectator * this) */

bool __thiscall CHudSpectator::ParseOverviewFile(CHudSpectator *this)

{
  overviewInfo_t *poVar1;
  uint uVar2;
  uint uVar3;
  overviewInfo_t *poVar4;
  char *pcVar5;
  bool bVar6;
  
                    /* Unresolved local var: char[255] filename@[???]
                       Unresolved local var: char[255] levelname@[???]
                       Unresolved local var: char[1024] token@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: char * pfile@[???] */
  uVar3 = 0x16c;
  poVar1 = &this->m_OverviewData;
  bVar6 = ((uint)poVar1 & 1) != 0;
  poVar4 = poVar1;
  if (bVar6) {
    uVar3 = 0x16b;
    (this->m_OverviewData).map[0] = '\0';
    poVar4 = (overviewInfo_t *)((this->m_OverviewData).map + 1);
  }
  if (((uint)poVar4 & 2) != 0) {
    poVar4->map[0] = '\0';
    poVar4->map[1] = '\0';
    uVar3 = uVar3 - 2;
    poVar4 = (overviewInfo_t *)(poVar4->map + 2);
  }
  uVar2 = 0;
  do {
    pcVar5 = poVar4->map + uVar2;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = poVar4->map + uVar2 + 4;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    uVar2 = uVar2 + 8;
  } while (uVar2 < (uVar3 & 0xfffffff8));
  pcVar5 = poVar4->map + uVar2;
  if ((uVar3 & 4) != 0) {
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pcVar5 + 4;
  }
  if ((uVar3 & 2) != 0) {
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5 = pcVar5 + 2;
  }
  if (bVar6) {
    *pcVar5 = '\0';
  }
  (this->m_OverviewData).insetWindowX = 4;
  (this->m_OverviewData).insetWindowY = 4;
  (this->m_OverviewData).insetWindowHeight = 0xb4;
  (this->m_OverviewData).insetWindowWidth = 0xf0;
  (this->m_OverviewData).origin.x = 0.0;
  (this->m_OverviewData).origin.y = 0.0;
  (this->m_OverviewData).origin.z = 0.0;
  (this->m_OverviewData).zoom = 1.0;
  (this->m_OverviewData).layers = 0;
  (this->m_OverviewData).layersHeights[0] = 0.0;
  pcVar5 = (*gEngfuncs.pfnGetLevelName)();
  __strcpy_chk(poVar1,pcVar5,0x40);
  if ((this->m_OverviewData).map[0] != '\0') {
    bVar6 = ParseOverviewFile(this);
    return bVar6;
  }
  return false;
}


// CHudSpectator::LoadMapSprites  @ 00056de0  (line 1411)

/* DWARF original prototype: void LoadMapSprites(CHudSpectator * this) */

void __thiscall CHudSpectator::LoadMapSprites(CHudSpectator *this)

{
  model_s *pmVar1;
  
  if ((this->m_OverviewData).layers < 1) {
    this->m_MapSprite = (model_s *)0x0;
    return;
  }
  pmVar1 = (*gEngfuncs.LoadMapSprite)((this->m_OverviewData).layersImages[0]);
  this->m_MapSprite = pmVar1;
  return;
}


// CHudSpectator::DrawOverviewLayer  @ 00056e20  (line 1422)

/* DWARF original prototype: void DrawOverviewLayer(CHudSpectator * this) */

void __thiscall CHudSpectator::DrawOverviewLayer(CHudSpectator *this)

{
  int iVar1;
  float fVar2;
  double __x;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  double dVar8;
  float local_4c;
  float local_48;
  float local_44;
  model_s *local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
                    /* Unresolved local var: float screenaspect@[???]
                       Unresolved local var: float xs@[???]
                       Unresolved local var: float ys@[???]
                       Unresolved local var: float xStep@[???]
                       Unresolved local var: float yStep@[???]
                       Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: int ix@[???]
                       Unresolved local var: int iy@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int xTiles@[???]
                       Unresolved local var: int yTiles@[???]
                       Unresolved local var: int frame@[???]
                       Unresolved local var: qboolean hasMapImage@[???]
                       Unresolved local var: model_t * dummySprite@[???] */
  if (this->m_MapSprite == (model_s *)0x0) {
    bVar7 = false;
    local_3c = (*gEngfuncs.GetSpritePointer)(this->m_hsprUnkownMap);
    local_34 = 8;
    local_2c = 6;
  }
  else {
    local_3c = (*gEngfuncs.GetSpritePointer)(this->m_hsprUnkownMap);
    __x = (double)(this->m_MapSprite->numframes / 0xc);
    dVar8 = SQRT(__x);
    if (NAN(dVar8)) {
      dVar8 = sqrt(__x);
    }
    bVar7 = true;
    local_34 = (int)dVar8 * 4;
    local_2c = (int)dVar8 * 3;
  }
  local_48 = (this->m_OverviewData).origin.x;
  local_44 = (this->m_OverviewData).origin.y;
  fVar6 = ((90.0 - v_angles.x) / 90.0) * (this->m_OverviewData).layersHeights[0];
  (*(gEngfuncs.pTriAPI)->RenderMode)(2);
  (*(gEngfuncs.pTriAPI)->CullFace)(TRI_NONE);
  (*(gEngfuncs.pTriAPI)->Color4f)(1.0,1.0,1.0,1.0);
  fVar2 = (this->m_OverviewData).zoom;
  if ((this->m_OverviewData).rotated == 0) {
    fVar4 = -(8192.0 / fVar2) / (float)local_34;
    fVar3 = fVar2 * 1.3333334;
    local_48 = 4096.0 / fVar3 + local_48;
    if (0 < local_2c) {
      local_30 = 0;
      local_38 = 0;
      while( true ) {
        local_4c = 4096.0 / fVar2 + local_44;
        iVar1 = local_30;
        if (0 < local_34) {
          fVar2 = fVar4 + local_48;
          iVar1 = local_30 + local_34;
          do {
            if (bVar7) {
              (*(gEngfuncs.pTriAPI)->SpriteTexture)(this->m_MapSprite,local_30);
            }
            else {
              (*(gEngfuncs.pTriAPI)->SpriteTexture)(local_3c,0);
            }
            local_30 = local_30 + 1;
            (*(gEngfuncs.pTriAPI)->Begin)(2);
            (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,0.0);
            (*(gEngfuncs.pTriAPI)->Vertex3f)(local_48,local_4c,fVar6);
            (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,1.0);
            (*(gEngfuncs.pTriAPI)->Vertex3f)(fVar2,local_4c,fVar6);
            (*(gEngfuncs.pTriAPI)->TexCoord2f)(1.0,1.0);
            local_4c = local_4c + -(8192.0 / fVar3) / (float)local_2c;
            (*(gEngfuncs.pTriAPI)->Vertex3f)(fVar2,local_4c,fVar6);
            (*(gEngfuncs.pTriAPI)->TexCoord2f)(1.0,0.0);
            (*(gEngfuncs.pTriAPI)->Vertex3f)(local_48,local_4c,fVar6);
            (*(gEngfuncs.pTriAPI)->End)();
          } while (iVar1 != local_30);
        }
        local_30 = iVar1;
        local_48 = fVar4 + local_48;
        local_38 = local_38 + 1;
        if (local_2c == local_38) break;
        fVar2 = (this->m_OverviewData).zoom;
      }
    }
  }
  else {
    fVar3 = 8192.0 / fVar2;
    fVar4 = -(8192.0 / (fVar2 * 1.3333334)) / (float)local_2c;
    local_44 = local_44 + 4096.0 / (fVar2 * 1.3333334);
    if (0 < local_2c) {
      local_28 = 0;
      local_30 = 0;
      while( true ) {
        iVar1 = local_28;
        if (0 < local_34) {
          fVar5 = fVar4 + local_44;
          iVar1 = local_34 + local_28;
          local_4c = local_48 - 4096.0 / fVar2;
          do {
            if (bVar7) {
              (*(gEngfuncs.pTriAPI)->SpriteTexture)(this->m_MapSprite,local_28);
            }
            else {
              (*(gEngfuncs.pTriAPI)->SpriteTexture)(local_3c,0);
            }
            local_28 = local_28 + 1;
            (*(gEngfuncs.pTriAPI)->Begin)(2);
            (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,0.0);
            (*(gEngfuncs.pTriAPI)->Vertex3f)(local_4c,local_44,fVar6);
            (*(gEngfuncs.pTriAPI)->TexCoord2f)(1.0,0.0);
            fVar2 = fVar3 / (float)local_34 + local_4c;
            (*(gEngfuncs.pTriAPI)->Vertex3f)(fVar2,local_44,fVar6);
            (*(gEngfuncs.pTriAPI)->TexCoord2f)(1.0,1.0);
            (*(gEngfuncs.pTriAPI)->Vertex3f)(fVar2,fVar5,fVar6);
            (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,1.0);
            (*(gEngfuncs.pTriAPI)->Vertex3f)(local_4c,fVar5,fVar6);
            (*(gEngfuncs.pTriAPI)->End)();
            local_4c = fVar2;
          } while (local_28 != iVar1);
        }
        local_28 = iVar1;
        local_44 = fVar4 + local_44;
        local_30 = local_30 + 1;
        if (local_2c == local_30) break;
        fVar2 = (this->m_OverviewData).zoom;
      }
    }
  }
  return;
}


// CHudSpectator::DrawOverviewEntities  @ 00057410  (line 1548)

/* DWARF original prototype: void DrawOverviewEntities(CHudSpectator * this) */

void __thiscall CHudSpectator::DrawOverviewEntities(CHudSpectator *this)

{
  float fVar1;
  cl_entity_s *pcVar2;
  float fVar3;
  float fVar4;
  vec_t vVar5;
  vec_t vVar6;
  vec_t *pvVar7;
  model_s *pmVar8;
  int iVar9;
  overviewEntity_t *poVar10;
  float fVar11;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  vec_t local_a8;
  vec_t local_a4;
  float local_a0 [2];
  float local_98;
  float local_94 [3];
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70 [3];
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c [15];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int ir@[???]
                       Unresolved local var: int ig@[???]
                       Unresolved local var: int ib@[???]
                       Unresolved local var: model_s * hSpriteModel@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector point@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector left@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector world@[???]
                       Unresolved local var: Vector screen@[???]
                       Unresolved local var: Vector offset@[???]
                       Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: float r@[???]
                       Unresolved local var: float g@[???]
                       Unresolved local var: float b@[???]
                       Unresolved local var: float sizeScale@[???]
                       Unresolved local var: cl_entity_t * ent@[???]
                       Unresolved local var: float[3][4] rmatrix@[???]
                       Unresolved local var: float zScale@[???] */
  fVar3 = (90.0 - v_angles.x) / 90.0;
  fVar1 = fVar3 * (this->m_OverviewData).layersHeights[0];
  (*(gEngfuncs.pTriAPI)->CullFace)(TRI_NONE);
  pvVar7 = &this->m_vPlayerPos[0].z;
  do {
    *pvVar7 = -1.0;
    pvVar7 = pvVar7 + 3;
  } while ((vec_t *)&this->m_hsprPlayer != pvVar7);
                    /* Unresolved local var: int playerNum@[???] */
  poVar10 = this->m_OverviewEntities;
  do {
    if (poVar10->hSprite != 0) {
      pmVar8 = (*gEngfuncs.GetSpritePointer)(poVar10->hSprite);
      pcVar2 = poVar10->entity;
      (*(gEngfuncs.pTriAPI)->SpriteTexture)(pmVar8,0);
      (*(gEngfuncs.pTriAPI)->RenderMode)(2);
      (*gEngfuncs.pfnAngleVectors)(&(pcVar2->angles).x,&local_88,local_70,(float *)0x0);
      local_b8 = (pcVar2->origin).x;
      local_b4 = (pcVar2->origin).y;
      local_b0 = (pcVar2->origin).z;
      (*(gEngfuncs.pTriAPI)->Begin)(2);
      (*(gEngfuncs.pTriAPI)->Color4f)(1.0,1.0,1.0,1.0);
      (*(gEngfuncs.pTriAPI)->TexCoord2f)(1.0,0.0);
      VectorMA(&local_b8,64.0,local_70,local_a0);
      VectorMA(local_a0,64.0,&local_88,local_a0);
      local_98 = fVar3 * local_98;
      (*(gEngfuncs.pTriAPI)->Vertex3fv)(local_a0);
      (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,0.0);
      VectorMA(&local_b8,64.0,local_70,local_a0);
      VectorMA(local_a0,-64.0,&local_88,local_a0);
      local_98 = fVar3 * local_98;
      (*(gEngfuncs.pTriAPI)->Vertex3fv)(local_a0);
      (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,1.0);
      VectorMA(&local_b8,-64.0,local_70,local_a0);
      VectorMA(local_a0,-64.0,&local_88,local_a0);
      local_98 = fVar3 * local_98;
      (*(gEngfuncs.pTriAPI)->Vertex3fv)(local_a0);
      (*(gEngfuncs.pTriAPI)->TexCoord2f)(1.0,1.0);
      VectorMA(&local_b8,-64.0,local_70,local_a0);
      VectorMA(local_a0,64.0,&local_88,local_a0);
      local_98 = fVar3 * local_98;
      (*(gEngfuncs.pTriAPI)->Vertex3fv)(local_a0);
      (*(gEngfuncs.pTriAPI)->End)();
      if (pcVar2->player != 0) {
        local_b0 = fVar3 * local_b0;
        (*(gEngfuncs.pTriAPI)->RenderMode)(5);
        pmVar8 = (*gEngfuncs.GetSpritePointer)(this->m_hsprBeam);
        (*(gEngfuncs.pTriAPI)->SpriteTexture)(pmVar8,0);
        (*(gEngfuncs.pTriAPI)->Color4f)(1.0,0.627451,0.0,0.3);
        (*(gEngfuncs.pTriAPI)->Begin)(2);
        (*(gEngfuncs.pTriAPI)->TexCoord2f)(1.0,0.0);
        (*(gEngfuncs.pTriAPI)->Vertex3f)(local_b8 + 4.0,local_b4 + 4.0,local_b0 - fVar3);
        (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,0.0);
        (*(gEngfuncs.pTriAPI)->Vertex3f)(local_b8 - 4.0,local_b4 - 4.0,local_b0 - fVar3);
        (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,1.0);
        (*(gEngfuncs.pTriAPI)->Vertex3f)(local_b8 - 4.0,local_b4 - 4.0,fVar1);
        (*(gEngfuncs.pTriAPI)->TexCoord2f)(1.0,1.0);
        (*(gEngfuncs.pTriAPI)->Vertex3f)(local_b8 + 4.0,local_b4 + 4.0,fVar1);
        (*(gEngfuncs.pTriAPI)->End)();
        (*(gEngfuncs.pTriAPI)->Begin)(2);
        (*(gEngfuncs.pTriAPI)->TexCoord2f)(1.0,0.0);
        (*(gEngfuncs.pTriAPI)->Vertex3f)(local_b8 - 4.0,local_b4 + 4.0,local_b0 - fVar3);
        (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,0.0);
        (*(gEngfuncs.pTriAPI)->Vertex3f)(local_b8 + 4.0,local_b4 - 4.0,local_b0 - fVar3);
        (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,1.0);
        (*(gEngfuncs.pTriAPI)->Vertex3f)(local_b8 + 4.0,local_b4 - 4.0,fVar1);
        (*(gEngfuncs.pTriAPI)->TexCoord2f)(1.0,1.0);
        (*(gEngfuncs.pTriAPI)->Vertex3f)(local_b8 - 4.0,local_b4 + 4.0,fVar1);
        (*(gEngfuncs.pTriAPI)->End)();
        iVar9 = (*(gEngfuncs.pTriAPI)->WorldToScreen)(&local_b8,&local_64);
        if (iVar9 == 0) {
          local_5c = 0.0;
          local_64 = (float)gHUD.m_scrinfo.iWidth * (local_64 + 1.0) * 0.5;
          local_60 = (float)gHUD.m_scrinfo.iHeight * (1.0 - local_60) * 0.5;
          local_b8 = local_b8 + 32.0;
          local_b4 = local_b4 + 32.0;
          (*(gEngfuncs.pTriAPI)->WorldToScreen)(&local_b8,&local_58);
          fVar4 = local_60;
          local_58 = (float)gHUD.m_scrinfo.iWidth * (local_58 + 1.0) * 0.5 - local_64;
          local_54 = (float)gHUD.m_scrinfo.iHeight * (1.0 - local_54) * 0.5 - local_60;
          local_50 = 0.0 - local_5c;
          iVar9 = pcVar2->index;
          this->m_vPlayerPos[iVar9 + -1].x = local_64;
          fVar11 = Length(&local_58);
          this->m_vPlayerPos[iVar9 + -1].z = 1.0;
          this->m_vPlayerPos[iVar9 + -1].y = fVar4 + fVar11;
        }
      }
    }
    poVar10 = poVar10 + 1;
  } while ((overviewEntity_t *)&this->m_iObserverFlags != poVar10);
  fVar1 = this->m_pip->value;
  if ((fVar1 != 0.0) && (this->m_drawcone->value != 0.0)) {
    if ((fVar1 == 2.0) || (g_iUser1 == 4)) {
      V_GetInEyePos(g_iUser2,&local_b8,&local_ac);
      fVar1 = local_b8;
      fVar4 = local_b4;
      fVar11 = local_b0;
      vVar5 = local_a8;
      vVar6 = local_a4;
    }
    else if ((fVar1 == 1.0) || (g_iUser1 == 2)) {
      V_GetChasePos(g_iUser2,&v_cl_angles.x,&local_b8,&local_ac);
      fVar1 = local_b8;
      fVar4 = local_b4;
      fVar11 = local_b0;
      vVar5 = local_a8;
      vVar6 = local_a4;
    }
    else {
      fVar1 = v_sim_org.x;
      fVar4 = v_sim_org.y;
      fVar11 = v_sim_org.z;
      vVar5 = v_cl_angles.y;
      vVar6 = v_cl_angles.z;
      if (g_iUser1 != 3) {
        V_GetChasePos(g_iUser2,(float *)0x0,&local_b8,&local_ac);
        fVar1 = local_b8;
        fVar4 = local_b4;
        fVar11 = local_b0;
        vVar5 = local_a8;
        vVar6 = local_a4;
      }
    }
    local_a4 = vVar6;
    local_a8 = vVar5;
    local_b0 = fVar11;
    local_b4 = fVar4;
    local_b8 = fVar1;
    fVar11 = local_b0;
    fVar4 = local_b4;
    fVar1 = local_b8;
    local_ac = 0.0;
    pmVar8 = (*gEngfuncs.GetSpritePointer)(this->m_hsprCamera);
    (*(gEngfuncs.pTriAPI)->RenderMode)(5);
    (*(gEngfuncs.pTriAPI)->SpriteTexture)(pmVar8,0);
    (*(gEngfuncs.pTriAPI)->Color4f)(1.0,0.627451,0.0,1.0);
    (*gEngfuncs.pfnAngleVectors)(&local_ac,local_94,(float *)0x0,(float *)0x0);
    VectorScale(local_94,512.0,local_94);
    local_58 = 0.0;
    local_54 = 45.0;
    local_50 = 0.0;
    AngleMatrix(&local_58,(float (*) [4])local_4c);
    VectorTransform(local_94,(float (*) [4])local_4c,&local_88);
    local_54 = -45.0;
    AngleMatrix(&local_58,(float (*) [4])local_4c);
    VectorTransform(local_94,(float (*) [4])local_4c,&local_7c);
    (*(gEngfuncs.pTriAPI)->Begin)(0);
    (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,0.0);
    (*(gEngfuncs.pTriAPI)->Vertex3f)(fVar1 + local_88,fVar4 + local_84,(fVar11 + local_80) * fVar3);
    (*(gEngfuncs.pTriAPI)->TexCoord2f)(0.0,1.0);
    (*(gEngfuncs.pTriAPI)->Vertex3f)(fVar1,fVar4,fVar3 * fVar11);
    (*(gEngfuncs.pTriAPI)->TexCoord2f)(1.0,1.0);
    (*(gEngfuncs.pTriAPI)->Vertex3f)(fVar1 + local_7c,fVar4 + local_78,(fVar11 + local_74) * fVar3);
    (*(gEngfuncs.pTriAPI)->End)();
  }
  return;
}


// CHudSpectator::DrawOverview  @ 00057ed0  (line 1750)

/* DWARF original prototype: void DrawOverview(CHudSpectator * this) */

void __thiscall CHudSpectator::DrawOverview(CHudSpectator *this)

{
  overviewEntity_t *poVar1;
  overviewEntity_t *poVar2;
  longdouble extraout_ST0;
  
  if (g_iUser1 != 0) {
    if (this->m_iDrawCycle == 0) {
      if (1 < g_iUser1 - 5U) {
        return;
      }
    }
    else if ((this->m_iDrawCycle == 1) && (this->m_pip->value < 3.0)) {
      return;
    }
    DrawOverviewLayer(this);
    DrawOverviewEntities(this);
                    /* Unresolved local var: double time@[???] */
    (*gEngfuncs.GetClientTime)();
    poVar1 = this->m_OverviewEntities;
    do {
      while (extraout_ST0 <= (longdouble)poVar1->killTime) {
        poVar1 = poVar1 + 1;
                    /* Unresolved local var: int i@[???] */
        if (poVar1 == (overviewEntity_t *)&this->m_iObserverFlags) {
          return;
        }
      }
      poVar1->hSprite = 0;
      poVar2 = poVar1 + 1;
      poVar1->entity = (cl_entity_s *)0x0;
      *(undefined4 *)&poVar1->killTime = 0;
      *(undefined4 *)((int)&poVar1->killTime + 4) = 0;
      poVar1 = poVar2;
    } while (poVar2 != (overviewEntity_t *)&this->m_iObserverFlags);
  }
  return;
}


// CHudSpectator::CheckOverviewEntities  @ 00057f80  (line 1767)

/* DWARF original prototype: void CheckOverviewEntities(CHudSpectator * this) */

void __thiscall CHudSpectator::CheckOverviewEntities(CHudSpectator *this)

{
  overviewEntity_t *poVar1;
  overviewEntity_t *poVar2;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: double time@[???] */
  (*gEngfuncs.GetClientTime)();
  poVar1 = this->m_OverviewEntities;
  do {
    while ((longdouble)poVar1->killTime < extraout_ST0) {
      poVar1->hSprite = 0;
      poVar2 = poVar1 + 1;
      poVar1->entity = (cl_entity_s *)0x0;
      *(undefined4 *)&poVar1->killTime = 0;
      *(undefined4 *)((int)&poVar1->killTime + 4) = 0;
      poVar1 = poVar2;
      if (poVar2 == (overviewEntity_t *)&this->m_iObserverFlags) {
        return;
      }
    }
    poVar1 = poVar1 + 1;
                    /* Unresolved local var: int i@[???] */
  } while (poVar1 != (overviewEntity_t *)&this->m_iObserverFlags);
  return;
}


// CHudSpectator::AddOverviewEntity  @ 00057fe0  (line 1782)

/* DWARF original prototype: bool AddOverviewEntity(CHudSpectator * this, int type, cl_entity_s *
   ent, char * modelname) */

bool __thiscall
CHudSpectator::AddOverviewEntity(CHudSpectator *this,int type,cl_entity_s *ent,char *modelname)

{
  cl_entity_s **ppcVar1;
  int iVar2;
  HANDLE_SPRITE HVar3;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: HANDLE_SPRITE hSprite@[???]
                       Unresolved local var: double duration@[???] */
  if ((type == 1 && ent != (cl_entity_s *)0x0) && ((ent->curstate).solid != 0)) {
    if (g_PlayerExtraInfo[ent->index].teamnumber == 1) {
      HVar3 = this->m_hsprPlayerBlue;
    }
    else if (g_PlayerExtraInfo[ent->index].teamnumber == 2) {
      HVar3 = this->m_hsprPlayerRed;
    }
    else {
      HVar3 = this->m_hsprPlayer;
    }
    (*gEngfuncs.GetClientTime)();
                    /* Unresolved local var: int i@[???] */
    iVar2 = 0;
    ppcVar1 = &this->m_OverviewEntities[0].entity;
    do {
      if (*ppcVar1 == (cl_entity_s *)0x0) {
        this->m_OverviewEntities[iVar2].entity = ent;
        this->m_OverviewEntities[iVar2].killTime = (double)(extraout_ST0 - (longdouble)1.0);
        this->m_OverviewEntities[iVar2].hSprite = HVar3;
        return true;
      }
      iVar2 = iVar2 + 1;
      ppcVar1 = ppcVar1 + 4;
    } while (iVar2 != 0x80);
  }
  return false;
}


// CHudSpectator::DeathMessage  @ 000580d0  (line 1815)

/* DWARF original prototype: void DeathMessage(CHudSpectator * this, int victim) */

void __thiscall CHudSpectator::DeathMessage(CHudSpectator *this,int victim)

{
  HANDLE_SPRITE HVar1;
  cl_entity_s *pcVar2;
  cl_entity_s **ppcVar3;
  int iVar4;
  longdouble extraout_ST0;
  
                    /* Unresolved local var: cl_entity_t * pl@[???] */
  pcVar2 = (*gEngfuncs.GetEntityByIndex)(victim);
  if ((pcVar2 != (cl_entity_s *)0x0) && (pcVar2->player != 0)) {
    (*gEngfuncs.GetClientTime)();
                    /* Unresolved local var: int i@[???] */
    iVar4 = 0;
    ppcVar3 = &this->m_OverviewEntities[0].entity;
    do {
      if (*ppcVar3 == (cl_entity_s *)0x0) {
        HVar1 = this->m_hsprPlayerDead;
        this->m_OverviewEntities[iVar4].killTime = (double)(extraout_ST0 + (longdouble)2.0);
        this->m_OverviewEntities[iVar4].entity = pcVar2;
        this->m_OverviewEntities[iVar4].hSprite = HVar1;
        return;
      }
      iVar4 = iVar4 + 1;
      ppcVar3 = ppcVar3 + 4;
    } while (iVar4 != 0x80);
  }
  return;
}


// CHudSpectator::AddOverviewEntityToList  @ 00058160  (line 1824)

/* DWARF original prototype: bool AddOverviewEntityToList(CHudSpectator * this, HANDLE_SPRITE
   sprite, cl_entity_t * ent, double killTime) */

bool __thiscall
CHudSpectator::AddOverviewEntityToList
          (CHudSpectator *this,HANDLE_SPRITE sprite,cl_entity_t *ent,double killTime)

{
  int iVar1;
  cl_entity_s **ppcVar2;
  
                    /* Unresolved local var: int i@[???] */
  iVar1 = 0;
  ppcVar2 = &this->m_OverviewEntities[0].entity;
  do {
    if (*ppcVar2 == (cl_entity_s *)0x0) {
      this->m_OverviewEntities[iVar1].killTime = killTime;
      this->m_OverviewEntities[iVar1].entity = ent;
      this->m_OverviewEntities[iVar1].hSprite = sprite;
      return true;
    }
    iVar1 = iVar1 + 1;
    ppcVar2 = ppcVar2 + 4;
  } while (iVar1 != 0x80);
  return false;
}


// CHudSpectator::CheckSettings  @ 000581c0  (line 1840)

/* DWARF original prototype: void CheckSettings(CHudSpectator * this) */

void __thiscall CHudSpectator::CheckSettings(CHudSpectator *this)

{
  cvar_t *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  char local_30 [32];
  int local_10;
  
  iVar4 = g_iUser1;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  this->m_pip->value = (float)(int)this->m_pip->value;
  pcVar1 = this->m_pip;
  if (iVar4 < 5) {
    if ((pcVar1->value == 1.0) || (pcVar1->value == 2.0)) {
      pcVar1->value = 3.0;
    }
  }
  else if (3.0 <= pcVar1->value) {
    pcVar1->value = 1.0;
  }
  if (gHUD.m_iIntermission != 0) {
    this->m_pip->value = 0.0;
  }
  uVar2 = (uint)NAN((gHUD.m_SayText.m_HUD_saytext)->value);
  if ((gHUD.m_SayText.m_HUD_saytext)->value != 0.0) {
    uVar2 = 1;
  }
  if (this->m_chatEnabled != uVar2) {
    this->m_chatEnabled = uVar2;
    iVar3 = (*gEngfuncs.IsSpectateOnly)();
    iVar4 = g_iUser1;
    if (iVar3 != 0) {
                    /* Unresolved local var: char[32] chatcmd@[???] */
      __sprintf_chk(local_30,1,0x20,"ignoremsg %i",this->m_chatEnabled == 0);
      (*gEngfuncs.pfnServerCmd)(local_30);
      iVar4 = g_iUser1;
    }
  }
  if (iVar4 - 3U < 2) {
    (this->m_crosshairRect).left = 0x18;
    (this->m_crosshairRect).right = 0x30;
    (this->m_crosshairRect).top = 0;
    (this->m_crosshairRect).bottom = 0x18;
    (*gEngfuncs.pfnSetCrosshair)(this->m_hCrosshair,this->m_crosshairRect,0xff,0xff,0xff);
  }
  else {
    (this->m_crosshairRect).left = 0;
    (this->m_crosshairRect).right = 0;
    (this->m_crosshairRect).top = 0;
    (this->m_crosshairRect).bottom = 0;
    (*gEngfuncs.pfnSetCrosshair)(0,(wrect_t)ZEXT816(0),0,0,0);
  }
  if ((g_iTeamNumber - 1U < 2) && (g_iUser1 == 4)) {
    this->m_pip->value = 0.0;
  }
  SpectatorPanel::EnableInsetView(gViewPort->m_pSpectatorPanel,this->m_pip->value != 0.0);
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// CHudSpectator::ToggleInset  @ 00058460  (line 1907)

/* DWARF original prototype: int ToggleInset(CHudSpectator * this, bool allowOff) */

int __thiscall CHudSpectator::ToggleInset(CHudSpectator *this,bool allowOff)

{
  uint uVar1;
  
                    /* Unresolved local var: int newInsetMode@[???] */
  uVar1 = (int)this->m_pip->value + 1;
  if (4 < g_iUser1) {
    if (2 < (int)uVar1) {
      uVar1 = (uint)!allowOff;
    }
    return uVar1;
  }
  if (4 < (int)uVar1) {
    return -(uint)!allowOff & 3;
  }
  if (uVar1 == 1) {
    uVar1 = 3;
  }
  return uVar1;
}


// CHudSpectator::Reset  @ 00054920  (line 1936)

/* DWARF original prototype: void Reset(CHudSpectator * this) */

void __thiscall CHudSpectator::Reset(CHudSpectator *this)

{
  Vector *angle;
  Vector *origin;
  char *pcVar1;
  int iVar2;
  uint uVar3;
  model_s *pmVar4;
  uint uVar5;
  uint uVar6;
  overviewInfo_t *poVar7;
  overviewEntity_t *poVar8;
  bool bVar9;
  byte bVar10;
  CHudSpectator *this_00;
  
  bVar10 = 0;
  pcVar1 = (*gEngfuncs.pfnGetLevelName)();
  this_00 = (CHudSpectator *)&this->m_OverviewData;
  iVar2 = strcmp((char *)this_00,pcVar1);
  if (iVar2 != 0) {
                    /* Unresolved local var: char[255] filename@[???]
                       Unresolved local var: char[255] levelname@[???]
                       Unresolved local var: char[1024] token@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: char * pfile@[???] */
    bVar9 = ((uint)this_00 & 1) != 0;
    uVar6 = 0x16c;
    poVar7 = (overviewInfo_t *)this_00;
    if (bVar9) {
      (this->m_OverviewData).map[0] = '\0';
      poVar7 = (overviewInfo_t *)((this->m_OverviewData).map + 1);
      uVar6 = 0x16b;
    }
    if (((uint)poVar7 & 2) != 0) {
      poVar7->map[0] = '\0';
      poVar7->map[1] = '\0';
      uVar6 = uVar6 - 2;
      poVar7 = (overviewInfo_t *)(poVar7->map + 2);
    }
    uVar5 = 0;
    do {
      uVar3 = uVar5;
      pcVar1 = poVar7->map + uVar3;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      pcVar1 = poVar7->map + uVar3 + 4;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      uVar5 = uVar3 + 8;
    } while (uVar3 + 8 < (uVar6 & 0xfffffff8));
    pcVar1 = poVar7->map + uVar3 + 8;
    if ((uVar6 & 4) != 0) {
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      pcVar1 = pcVar1 + 4;
    }
    if ((uVar6 & 2) != 0) {
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1 = pcVar1 + 2;
    }
    if (bVar9) {
      *pcVar1 = '\0';
    }
    (this->m_OverviewData).insetWindowX = 4;
    (this->m_OverviewData).insetWindowY = 4;
    (this->m_OverviewData).insetWindowHeight = 0xb4;
    (this->m_OverviewData).insetWindowWidth = 0xf0;
    (this->m_OverviewData).origin.x = 0.0;
    (this->m_OverviewData).origin.y = 0.0;
    (this->m_OverviewData).origin.z = 0.0;
    (this->m_OverviewData).zoom = 1.0;
    (this->m_OverviewData).layers = 0;
    (this->m_OverviewData).layersHeights[0] = 0.0;
    pcVar1 = (*gEngfuncs.pfnGetLevelName)();
    __strcpy_chk(this_00,pcVar1,0x40);
    if ((this->m_OverviewData).map[0] != '\0') {
      ParseOverviewFile(this_00);
    }
    if ((this->m_OverviewData).layers < 1) {
      this->m_MapSprite = (model_s *)0x0;
    }
    else {
      pmVar4 = (*gEngfuncs.LoadMapSprite)((this->m_OverviewData).layersImages[0]);
      this->m_MapSprite = pmVar4;
    }
  }
  poVar8 = this->m_OverviewEntities;
  uVar6 = 0x800;
  bVar9 = ((uint)poVar8 & 1) != 0;
  if (bVar9) {
    poVar8 = (overviewEntity_t *)((int)&this->m_OverviewEntities[0].hSprite + 1);
    uVar6 = 0x7ff;
    *(undefined1 *)&this->m_OverviewEntities[0].hSprite = 0;
  }
  if (((uint)poVar8 & 2) != 0) {
    *(undefined2 *)&poVar8->hSprite = 0;
    poVar8 = (overviewEntity_t *)((int)&poVar8->hSprite + 2);
    uVar6 = uVar6 - 2;
  }
  if (((uint)poVar8 & 4) != 0) {
    poVar8->hSprite = 0;
    uVar6 = uVar6 - 4;
    poVar8 = (overviewEntity_t *)&poVar8->entity;
  }
  for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    poVar8->hSprite = 0;
    poVar8 = (overviewEntity_t *)((int)poVar8 + (uint)bVar10 * -8 + 4);
  }
  if ((uVar6 & 2) != 0) {
    *(undefined2 *)&poVar8->hSprite = 0;
    poVar8 = (overviewEntity_t *)((int)&poVar8->hSprite + 2);
  }
  if (bVar9) {
    *(undefined1 *)&poVar8->hSprite = 0;
  }
  angle = &this->m_cameraAngles;
  origin = &this->m_cameraOrigin;
  this->m_FOV = 90.0;
  this->m_IsInterpolating = 0;
  this->m_ChaseEntity = 0;
  iVar2 = UTIL_FindEntityInMap("trigger_camera",&origin->x,&angle->x);
  if ((((iVar2 == 0) &&
       (iVar2 = UTIL_FindEntityInMap("info_player_start",&origin->x,&angle->x), iVar2 == 0)) &&
      (iVar2 = UTIL_FindEntityInMap("info_player_deathmatch",&origin->x,&angle->x), iVar2 == 0)) &&
     (iVar2 = UTIL_FindEntityInMap("info_player_coop",&origin->x,&angle->x),
     vJumpOrigin[0] = vec3_origin.x, iVar2 == 0)) {
    (this->m_cameraOrigin).x = vec3_origin.x;
    vJumpOrigin[1] = vec3_origin.y;
    (this->m_cameraOrigin).y = vec3_origin.y;
    vJumpOrigin[2] = vec3_origin.z;
    (this->m_cameraOrigin).z = vec3_origin.z;
    (this->m_cameraAngles).x = vJumpOrigin[0];
    (this->m_cameraAngles).y = vJumpOrigin[1];
    (this->m_cameraAngles).z = vJumpOrigin[2];
    vJumpAngles[0] = vJumpOrigin[0];
    vJumpAngles[1] = vJumpOrigin[1];
    vJumpAngles[2] = vJumpOrigin[2];
  }
  else {
    vJumpOrigin[0] = (this->m_cameraOrigin).x;
    vJumpOrigin[1] = (this->m_cameraOrigin).y;
    vJumpOrigin[2] = (this->m_cameraOrigin).z;
    vJumpAngles[0] = (this->m_cameraAngles).x;
    vJumpAngles[1] = (this->m_cameraAngles).y;
    vJumpAngles[2] = (this->m_cameraAngles).z;
  }
  iJumpSpectator = 1;
  return;
}


// CHudSpectator::InitHUDData  @ 00056760  (line 1957)

/* DWARF original prototype: void InitHUDData(CHudSpectator * this) */

void __thiscall CHudSpectator::InitHUDData(CHudSpectator *this)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  overviewInfo_t *poVar4;
  char *pcVar5;
  overviewEntity_t *poVar6;
  bool bVar7;
  longdouble extraout_ST0;
  
  uVar3 = 0x16c;
  g_iUser1 = 0;
  this->m_lastSecondaryObject = 0;
  this->m_lastPrimaryObject = 0;
  this->m_lastHudMessage = 0;
  this->m_iSpectatorNumber = 0;
  poVar4 = &this->m_OverviewData;
  iJumpSpectator = 0;
  bVar7 = ((uint)poVar4 & 1) != 0;
  this->m_flNextObserverInput = 0.0;
  g_iUser2 = 0;
  if (bVar7) {
    poVar4 = (overviewInfo_t *)((this->m_OverviewData).map + 1);
    uVar3 = 0x16b;
    (this->m_OverviewData).map[0] = '\0';
  }
  if (((uint)poVar4 & 2) != 0) {
    poVar4->map[0] = '\0';
    poVar4->map[1] = '\0';
    uVar3 = uVar3 - 2;
    poVar4 = (overviewInfo_t *)(poVar4->map + 2);
  }
  uVar1 = 0;
  do {
    pcVar5 = poVar4->map + uVar1;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = poVar4->map + uVar1 + 4;
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    uVar1 = uVar1 + 8;
  } while (uVar1 < (uVar3 & 0xfffffff8));
  pcVar5 = poVar4->map + uVar1;
  if ((uVar3 & 4) != 0) {
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pcVar5 + 4;
  }
  if ((uVar3 & 2) != 0) {
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5 = pcVar5 + 2;
  }
  if (bVar7) {
    *pcVar5 = '\0';
  }
  poVar6 = this->m_OverviewEntities;
  uVar3 = 0x800;
  bVar7 = ((uint)poVar6 & 1) != 0;
  if (bVar7) {
    *(undefined1 *)&this->m_OverviewEntities[0].hSprite = 0;
    poVar6 = (overviewEntity_t *)((int)&this->m_OverviewEntities[0].hSprite + 1);
    uVar3 = 0x7ff;
  }
  if (((uint)poVar6 & 2) != 0) {
    *(undefined2 *)&poVar6->hSprite = 0;
    uVar3 = uVar3 - 2;
    poVar6 = (overviewEntity_t *)((int)&poVar6->hSprite + 2);
  }
  if (((uint)poVar6 & 4) != 0) {
    poVar6->hSprite = 0;
    uVar3 = uVar3 - 4;
    poVar6 = (overviewEntity_t *)&poVar6->entity;
  }
  for (uVar1 = uVar3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    poVar6->hSprite = 0;
    poVar6 = (overviewEntity_t *)&poVar6->entity;
  }
  if ((uVar3 & 2) != 0) {
    *(undefined2 *)&poVar6->hSprite = 0;
    poVar6 = (overviewEntity_t *)((int)&poVar6->hSprite + 2);
  }
  if (bVar7) {
    *(undefined1 *)&poVar6->hSprite = 0;
  }
  iVar2 = (*gEngfuncs.IsSpectateOnly)();
  if ((iVar2 == 0) && (iVar2 = (*(gEngfuncs.pDemoAPI)->IsPlayingback)(), iVar2 == 0)) {
    this->m_autoDirector->value = 0.0;
  }
  else {
    this->m_autoDirector->value = 1.0;
  }
  (*(this->super_CHudBase)._vptr_CHudBase[6])(this);
  SetModes(this,1,0);
  g_iUser2 = 0;
  (*gEngfuncs.pfnGetCvarFloat)("default_fov");
  gHUD.m_iFOV = (int)extraout_ST0;
  return;
}


