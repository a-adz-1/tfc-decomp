// UTIL_BloodDrips  @ 0007dde0
void UTIL_BloodDrips(Vector *origin,Vector *direction,int color,int amount)

{
  return;
}


// UTIL_ClientPrintAll  @ 0007de60
void UTIL_ClientPrintAll(int param_1,char *param_2,char *param_3,char *param_4,char *param_5,
                        char *param_6)

{
  return;
}


// UTIL_DecalTrace  @ 0007ddf0
void UTIL_DecalTrace(TraceResult *pTrace,int decalNumber)

{
  return;
}


// UTIL_FindEntityInMap  @ 00079290
/* WARNING: Type propagation algorithm not settling */

int UTIL_FindEntityInMap(char *name,float *origin,float *angle)

{
  char *pcVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  cl_entity_s *pcVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  uint *puVar10;
  uint *puVar11;
  int iVar12;
  char *pcVar13;
  bool bVar14;
  bool bVar15;
  undefined1 uVar16;
  byte bVar17;
  double dVar18;
  char local_51c [1020];
  char acStack_120 [4];
  uint local_11c [67];
  
  bVar17 = 0;
                    /* Unresolved local var: int n@[???]
                       Unresolved local var: int found@[???]
                       Unresolved local var: char[256] keyname@[???]
                       Unresolved local var: char[1024] token@[???]
                       Unresolved local var: cl_entity_t * pEnt@[???]
                       Unresolved local var: char * data@[???] */
  pcVar5 = (*gEngfuncs.GetEntityByIndex)(0);
  if (((pcVar5 != (cl_entity_s *)0x0) && (pcVar5->model != (model_s *)0x0)) &&
     (pcVar6 = pcVar5->model->entities, pcVar6 != (char *)0x0)) {
    pcVar1 = acStack_120 + 4;
    do {
      pcVar6 = (*gEngfuncs.COM_ParseFile)(pcVar6,local_51c);
      if (local_51c[0] == '\0') {
        return 0;
      }
      if (local_51c[0] == '}') {
        return 0;
      }
      if (pcVar6 == (char *)0x0) {
LAB_00079508:
        (*gEngfuncs.Con_DPrintf)("UTIL_FindEntityInMap: EOF without closing brace\n");
        return 0;
      }
      if (local_51c[0] != '{') {
        (*gEngfuncs.Con_DPrintf)("UTIL_FindEntityInMap: expected {\n");
        return 0;
      }
      bVar3 = false;
      while (pcVar6 = (*gEngfuncs.COM_ParseFile)(pcVar6,local_51c), local_51c[0] != '}') {
        if (pcVar6 == (char *)0x0) goto LAB_00079508;
        strcpy(acStack_120 + 4,local_51c);
        puVar11 = (uint *)(acStack_120 + 4);
        do {
          puVar10 = puVar11;
          uVar7 = *puVar10 + 0xfefefeff & ~*puVar10;
          uVar8 = uVar7 & 0x80808080;
          puVar11 = puVar10 + 1;
        } while (uVar8 == 0);
        if ((uVar7 & 0x8080) == 0) {
          puVar11 = (uint *)((int)puVar10 + 6);
          uVar8 = uVar8 >> 0x10;
        }
        iVar12 = (int)puVar11 + ((-3 - (uint)CARRY1((byte)uVar8,(byte)uVar8)) - (int)pcVar1);
        if ((iVar12 != 0) && (acStack_120[iVar12 + 3] == ' ')) {
          pcVar9 = acStack_120 + iVar12 + 3;
          do {
            *pcVar9 = '\0';
            if (pcVar9 == pcVar1) break;
            pcVar9 = pcVar9 + -1;
          } while (*pcVar9 == ' ');
        }
        pcVar6 = (*gEngfuncs.COM_ParseFile)(pcVar6,local_51c);
        if (pcVar6 == (char *)0x0) goto LAB_00079508;
        if (local_51c[0] == '}') {
          (*gEngfuncs.Con_DPrintf)("UTIL_FindEntityInMap: closing brace without data");
          return 0;
        }
        iVar12 = 10;
        bVar14 = false;
        pcVar9 = pcVar1;
        pcVar13 = "classname";
        do {
          if (iVar12 == 0) break;
          iVar12 = iVar12 + -1;
          bVar14 = *pcVar9 == *pcVar13;
          pcVar9 = pcVar9 + (uint)bVar17 * -2 + 1;
          pcVar13 = pcVar13 + (uint)bVar17 * -2 + 1;
        } while (bVar14);
        bVar15 = false;
        bVar4 = bVar3;
        if (bVar14) {
          iVar12 = strcmp(local_51c,name);
          bVar15 = iVar12 == 0;
          bVar4 = true;
          if (!bVar15) {
            bVar4 = bVar3;
          }
        }
        bVar3 = bVar4;
        iVar12 = 6;
        pcVar9 = pcVar1;
        pcVar13 = "angle";
        do {
          if (iVar12 == 0) break;
          iVar12 = iVar12 + -1;
          bVar15 = *pcVar9 == *pcVar13;
          pcVar9 = pcVar9 + (uint)bVar17 * -2 + 1;
          pcVar13 = pcVar13 + (uint)bVar17 * -2 + 1;
        } while (bVar15);
        uVar16 = false;
        if (bVar15) {
                    /* Unresolved local var: float y@[???] */
          dVar18 = strtod(local_51c,(char **)0x0);
          fVar2 = (float)dVar18;
          uVar16 = fVar2 == 0.0;
          if (fVar2 < 0.0) {
            uVar16 = (int)dVar18 == -1;
            if ((bool)uVar16) {
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
            angle[1] = fVar2;
          }
          angle[2] = 0.0;
        }
        iVar12 = 7;
        pcVar9 = pcVar1;
        pcVar13 = "angles";
        do {
          if (iVar12 == 0) break;
          iVar12 = iVar12 + -1;
          uVar16 = *pcVar9 == *pcVar13;
          pcVar9 = pcVar9 + (uint)bVar17 * -2 + 1;
          pcVar13 = pcVar13 + (uint)bVar17 * -2 + 1;
        } while ((bool)uVar16);
        if ((bool)uVar16) {
          UTIL_StringToVector(angle,local_51c);
        }
        iVar12 = 7;
        pcVar9 = pcVar1;
        pcVar13 = "origin";
        do {
          if (iVar12 == 0) break;
          iVar12 = iVar12 + -1;
          uVar16 = *pcVar9 == *pcVar13;
          pcVar9 = pcVar9 + (uint)bVar17 * -2 + 1;
          pcVar13 = pcVar13 + (uint)bVar17 * -2 + 1;
        } while ((bool)uVar16);
        if ((bool)uVar16) {
          UTIL_StringToVector(origin,local_51c);
        }
      }
      if (bVar3) {
        return 1;
      }
    } while (pcVar6 != (char *)0x0);
  }
  return 0;
}


// UTIL_GetNextBestWeapon  @ 0007de40
BOOL UTIL_GetNextBestWeapon(CBasePlayer *pPlayer,CBasePlayerItem *pCurrentWeapon)

{
  return 1;
}


// UTIL_GunshotDecalTrace  @ 0007de00
void UTIL_GunshotDecalTrace(TraceResult *pTrace,int decalNumber)

{
  return;
}


// UTIL_IsValidEntity  @ 0007de20
BOOL UTIL_IsValidEntity(edict_t *pent)

{
  return 1;
}


// UTIL_LogPrintf  @ 0007de50
void UTIL_LogPrintf(char *param_1,...)

{
  return;
}


// UTIL_MakeVectors  @ 0007de10
void UTIL_MakeVectors(Vector *vecAngles)

{
  return;
}


// UTIL_ParticleBox  @ 000811c0
/* WARNING: Type propagation algorithm not settling */

void UTIL_ParticleBox(CBasePlayer *player,float *mins,float *maxs,float life,uchar r,uchar g,uchar b
                     )

{
  entvars_t *peVar1;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  peVar1 = (player->super_CBaseMonster).super_CBaseToggle.super_CBaseAnimating.super_CBaseDelay.
           super_CBaseEntity.pev;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector mmin@[???]
                       Unresolved local var: Vector mmax@[???] */
  local_18 = (peVar1->origin).x;
  local_24 = *mins + local_18;
  local_18 = local_18 + *maxs;
  local_14 = (peVar1->origin).y;
  local_20 = mins[1] + local_14;
  local_14 = local_14 + maxs[1];
  local_10 = (peVar1->origin).z;
  local_1c = mins[2] + local_10;
  local_10 = local_10 + maxs[2];
  (*(gEngfuncs.pEfxAPI)->R_ParticleBox)(&local_24,&local_18,'\x05','\0',0xff,0.0);
  return;
}


// UTIL_ParticleBoxes  @ 00081250
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void UTIL_ParticleBoxes(void)

{
  int iVar1;
  cl_entity_s *pcVar2;
  int iVar3;
  physent_s_conflict *ppVar4;
  int iVar5;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: cl_entity_t * player@[???]
                       Unresolved local var: Vector mins@[???]
                       Unresolved local var: Vector maxs@[???] */
  iVar5 = 1;
  (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  pcVar2 = (*gEngfuncs.GetLocalPlayer)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(pcVar2->index + -1);
  do {
    ppVar4 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(iVar5);
    if (ppVar4 == (physent_s_conflict *)0x0) break;
    iVar1 = ppVar4->info;
    if (0 < iVar1) {
      iVar3 = (*gEngfuncs.GetMaxClients)();
      if (iVar1 <= iVar3) {
        local_20 = (ppVar4->origin).z;
        local_2c = (ppVar4->mins).z + local_20;
        local_24 = (ppVar4->origin).y;
        local_30 = (ppVar4->mins).y + local_24;
        local_28 = (ppVar4->origin).x;
        local_34 = (ppVar4->mins).x + local_28;
        local_20 = local_20 + (ppVar4->maxs).z;
        local_24 = local_24 + (ppVar4->maxs).y;
        local_28 = local_28 + (ppVar4->maxs).x;
        (*(gEngfuncs.pEfxAPI)->R_ParticleBox)(&local_34,&local_28,'\0','\0',0xff,2.0);
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 100);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  return;
}


// UTIL_ParticleLine  @ 00081350
void UTIL_ParticleLine(CBasePlayer *player,float *start,float *end,float life,uchar r,uchar g,
                      uchar b)

{
                    /* WARNING: Could not recover jumptable at 0x000813a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(gEngfuncs.pEfxAPI)->R_ParticleLine)(start,end,r,g,b,life);
  return;
}


// UTIL_PrecacheOther  @ 0007ddd0
void UTIL_PrecacheOther(char *szClassname)

{
  return;
}


// UTIL_SetOrigin  @ 0007de30
void UTIL_SetOrigin(entvars_t *param_1,Vector *org)

{
  return;
}


// UTIL_SharedRandomFloat  @ 0008c080
float UTIL_SharedRandomFloat(uint seed,float low,float high)

{
  uint uVar1;
  int local_1c;
  
                    /* Unresolved local var: uint range@[???] */
  uVar1 = (seed_table[(int)low + seed + (int)high & 0xff] * 0x10dcd + 1 +
          seed_table[seed_table[(int)low + seed + (int)high & 0xff] * 0x10dcd & 0xff]) * 0x10dcd;
  glSeed = uVar1 + 1 + seed_table[uVar1 & 0xff];
  local_1c = (int)(longlong)ROUND(high - low);
  if (local_1c != 0) {
                    /* Unresolved local var: int tensixrand@[???]
                       Unresolved local var: float offset@[???] */
    glSeed = glSeed * 0x10dcd + 1 + seed_table[glSeed * 0x10dcd & 0xff];
    low = (float)(glSeed & 0xffff) * 1.5258789e-05 *
          (float)((longlong)ROUND(high - low) & 0xffffffff) + low;
  }
  return low;
}


// UTIL_SharedRandomLong  @ 0008c020
int UTIL_SharedRandomLong(uint seed,int low,int high)

{
  uint uVar1;
  
                    /* Unresolved local var: uint range@[???] */
  uVar1 = (high - low) + 1;
  glSeed = seed_table[seed + low + high & 0xff];
  if (uVar1 != 1) {
                    /* Unresolved local var: int offset@[???]
                       Unresolved local var: int rnum@[???] */
    glSeed = glSeed * 0x10dcd + 1 + seed_table[glSeed * 0x10dcd & 0xff];
    low = low + (glSeed & 0xfffffff) % uVar1;
  }
  return low;
}


// UTIL_StringToVector  @ 00079160
void UTIL_StringToVector(float *pVector,char *pString)

{
  char cVar1;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *__dest;
  uint uVar7;
  int iVar8;
  double dVar9;
  char local_9c;
  char local_9b [126];
  undefined1 local_1d;
  
                    /* Unresolved local var: char * pstr@[???]
                       Unresolved local var: char * pfront@[???]
                       Unresolved local var: char[128] tempString@[???]
                       Unresolved local var: int j@[???] */
  iVar8 = 0;
  __dest = &local_9c;
  strncpy(__dest,pString,0x80);
  local_1d = 0;
  do {
    dVar9 = strtod(__dest,(char **)0x0);
    pVector[iVar8] = (float)dVar9;
    cVar1 = *__dest;
    if ((cVar1 != '\0') && (cVar1 != ' ')) {
      do {
        __dest = __dest + 1;
        cVar1 = *__dest;
        if (cVar1 == ' ') break;
      } while (cVar1 != '\0');
    }
    if (cVar1 == '\0') {
      if (iVar8 == 2) {
        return;
      }
      uVar6 = 2 - iVar8;
      uVar4 = -(((uint)(pVector + iVar8 + 1) & 0xf) >> 2) & 3;
      if (uVar6 < uVar4) {
        uVar4 = uVar6;
      }
      iVar2 = iVar8 + 1;
      if (uVar4 == 0) goto LAB_00079221;
      uVar7 = 0;
      do {
        uVar7 = uVar7 + 1;
        pVector[iVar2] = 0.0;
        iVar2 = iVar2 + 1;
      } while (uVar7 < uVar4);
      if (uVar6 != uVar4) {
LAB_00079221:
        uVar7 = uVar6 - uVar4 >> 2;
        if (uVar7 != 0) {
          pfVar3 = pVector + iVar8 + uVar4 + 1;
          uVar5 = 0;
          do {
            uVar5 = uVar5 + 1;
            *pfVar3 = 0.0;
            pfVar3[1] = 0.0;
            pfVar3[2] = 0.0;
            pfVar3[3] = 0.0;
            pfVar3 = pfVar3 + 4;
          } while (uVar5 < uVar7);
          iVar2 = iVar2 + uVar7 * 4;
          if (uVar6 - uVar4 == uVar7 * 4) {
            return;
          }
        }
        do {
          pVector[iVar2] = 0.0;
          if (iVar2 + 1 == 3) {
            return;
          }
          pVector[iVar2 + 1] = 0.0;
          iVar2 = iVar2 + 2;
        } while (iVar2 != 3);
      }
      return;
    }
    iVar8 = iVar8 + 1;
    __dest = __dest + 1;
    if (iVar8 == 3) {
      return;
    }
  } while( true );
}


// UTIL_TraceLine  @ 000810d0
void UTIL_TraceLine(Vector *vecStart,Vector *vecEnd,IGNORE_MONSTERS igmon,edict_t *pentIgnore,
                   TraceResult *ptr)

{
  uint uVar1;
  TraceResult *pTVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar4 = 0x38;
  bVar6 = ((uint)ptr & 1) != 0;
  pTVar2 = ptr;
  if (bVar6) {
    uVar4 = 0x37;
    *(undefined1 *)&ptr->fAllSolid = 0;
    pTVar2 = (TraceResult *)((int)&ptr->fAllSolid + 1);
  }
  if (((uint)pTVar2 & 2) != 0) {
    *(undefined2 *)&pTVar2->fAllSolid = 0;
    uVar4 = uVar4 - 2;
    pTVar2 = (TraceResult *)((int)&pTVar2->fAllSolid + 2);
  }
  uVar1 = 0;
  do {
    uVar5 = uVar1;
    *(undefined4 *)((int)&pTVar2->fAllSolid + uVar5) = 0;
    *(undefined4 *)((int)&pTVar2->fStartSolid + uVar5) = 0;
    *(undefined4 *)((int)&pTVar2->fInOpen + uVar5) = 0;
    *(undefined4 *)((int)&pTVar2->fInWater + uVar5) = 0;
    uVar1 = uVar5 + 0x10;
  } while (uVar5 + 0x10 < (uVar4 & 0xfffffff0));
  puVar3 = (undefined4 *)((int)&pTVar2->flFraction + uVar5);
  if ((uVar4 & 8) != 0) {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3 = puVar3 + 2;
  }
  if ((uVar4 & 4) != 0) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if ((uVar4 & 2) != 0) {
    *(undefined2 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 2);
  }
  if (!bVar6) {
    ptr->flFraction = 1.0;
    return;
  }
  *(undefined1 *)puVar3 = 0;
  ptr->flFraction = 1.0;
  return;
}


// UTIL_WeaponTimeBase  @ 0008bfc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float UTIL_WeaponTimeBase(void)

{
  return 0.0;
}


