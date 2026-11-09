// Ghidra decompilation of functions from cl_dll/ev_tfc.cpp
// 102 functions, ordered by original source line

// EV_TFC_PlayTextureSound  @ 00048390  (line 355)

float EV_TFC_PlayTextureSound(int idx,pmtrace_t *ptr,float *vecSrc,float *vecEnd,int iBulletType)

{
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  char cVar2;
  int iVar3;
  int iVar4;
  int32 iVar5;
  char *pcVar6;
  int32 iVar7;
  int in_GS_OFFSET;
  longdouble extraout_ST0;
  float fVar8;
  char *pcVar9;
  float local_c8;
  float local_c4;
  char *local_b0 [4];
  char local_a0 [2];
  char local_9e [62];
  char local_60 [12];
  undefined1 local_54;
  int local_20;
  
                    /* Unresolved local var: char chTextureType@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: float fvolbar@[???]
                       Unresolved local var: char *[4] rgsz@[???]
                       Unresolved local var: int cnt@[???]
                       Unresolved local var: float fattn@[???]
                       Unresolved local var: int entity@[???]
                       Unresolved local var: char * pTextureName@[???]
                       Unresolved local var: char[64] texname@[???]
                       Unresolved local var: char[64] szbuffer@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(ptr);
  if (iVar3 < 1) {
    if ((iVar3 != 0) ||
       (pcVar9 = (*(gEngfuncs.pEventAPI)->EV_TraceTexture)(ptr->ent,vecSrc,vecEnd),
       pcVar9 == (char *)0x0)) goto LAB_00048450;
    pcVar6 = local_a0;
    __strcpy_chk(pcVar6,pcVar9,0x40);
    if ((local_a0[0] - 0x2bU & 0xfd) == 0) {
      pcVar6 = local_9e;
      local_a0[0] = local_9e[0];
    }
    if ((local_a0[0] == '{' || local_a0[0] == '~') || ((byte)(local_a0[0] - 0x20U) < 2)) {
      pcVar6 = pcVar6 + 1;
    }
    __strcpy_chk(local_60,pcVar6,0x40);
    local_54 = 0;
    cVar2 = PM_FindTextureType(local_60);
    switch(cVar2) {
    case 'D':
      local_b0[0] = "player/pl_dirt1.wav";
      iVar7 = 2;
      local_c4 = 0.1;
      local_b0[1] = "player/pl_dirt2.wav";
      local_b0[2] = "player/pl_dirt3.wav";
      local_c8 = 0.9;
      fVar8 = 0.8;
      break;
    default:
      goto switchD_000485cb_caseD_45;
    case 'F':
      goto switchD_000485cb_caseD_46;
    case 'G':
      iVar7 = 1;
      local_b0[0] = "player/pl_grate1.wav";
      local_c4 = 0.5;
      local_b0[1] = "player/pl_grate4.wav";
      fVar8 = 0.8;
      local_c8 = 0.9;
      break;
    case 'M':
      local_b0[0] = "player/pl_metal1.wav";
      iVar7 = 1;
      local_c4 = 0.3;
      local_b0[1] = "player/pl_metal2.wav";
      fVar8 = 0.8;
      local_c8 = 0.9;
      break;
    case 'P':
    case 'Y':
      local_c4 = 0.2;
      local_b0[1] = "debris/glass2.wav";
      iVar7 = 2;
      local_b0[0] = "debris/glass1.wav";
      local_c8 = 0.8;
      local_b0[2] = "debris/glass3.wav";
      goto LAB_0004847d;
    case 'S':
      local_b0[0] = "player/pl_slosh1.wav";
      local_c4 = 0.0;
      iVar7 = 3;
      local_b0[1] = "player/pl_slosh3.wav";
      local_b0[2] = "player/pl_slosh2.wav";
      local_c8 = 0.9;
      local_b0[3] = "player/pl_slosh4.wav";
      fVar8 = 0.8;
      break;
    case 'T':
      fVar8 = 0.8;
      local_b0[2] = "player/pl_tile2.wav";
      local_c4 = 0.2;
      iVar7 = 3;
      local_b0[0] = "player/pl_tile1.wav";
      local_b0[1] = "player/pl_tile3.wav";
      local_b0[3] = "player/pl_tile4.wav";
      local_c8 = 0.8;
      break;
    case 'V':
      iVar7 = 1;
      local_b0[0] = "player/pl_duct1.wav";
      local_c4 = 0.3;
      local_b0[1] = "player/pl_duct1.wav";
      fVar8 = 0.8;
      local_c8 = 0.5;
      break;
    case 'W':
      iVar7 = 2;
      local_b0[0] = "debris/wood1.wav";
      local_c4 = 0.2;
      local_b0[1] = "debris/wood2.wav";
      local_b0[2] = "debris/wood3.wav";
      local_c8 = 0.9;
      fVar8 = 0.8;
    }
  }
  else {
    iVar4 = (*gEngfuncs.GetMaxClients)();
    if (iVar3 <= iVar4) {
switchD_000485cb_caseD_46:
      if (iBulletType == 5) {
        local_c4 = 0.0;
        goto LAB_00048521;
      }
      fVar8 = 1.0;
      local_b0[0] = "weapons/bullet_hit1.wav";
      local_c8 = 1.0;
      local_c4 = 0.2;
      local_b0[1] = "weapons/bullet_hit2.wav";
      iVar7 = 1;
      goto LAB_000484a3;
    }
LAB_00048450:
    cVar2 = '\0';
switchD_000485cb_caseD_45:
    local_b0[0] = "player/pl_step1.wav";
    iVar7 = 1;
    local_c4 = 0.6;
    local_b0[1] = "player/pl_step2.wav";
    local_c8 = 0.9;
LAB_0004847d:
    if (((cVar2 == 'P') && (ptr->fraction != 1.0)) &&
       (iVar5 = (*gEngfuncs.pfnRandomLong)(0,1), iVar5 != 0)) {
      (*(gEngfuncs.pEfxAPI)->R_SparkEffect)(&(ptr->endpos).x,8,-200,200);
      (*gEngfuncs.pfnRandomFloat)(0.7,1.0);
      iVar5 = (*gEngfuncs.pfnRandomLong)(0,1);
      if (iVar5 == 0) {
        pcVar9 = "buttons/spark5.wav";
      }
      else {
        if (iVar5 != 1) {
          fVar8 = 0.8;
          goto LAB_000484a3;
        }
        pcVar9 = "buttons/spark6.wav";
      }
      (*(gEngfuncs.pEventAPI)->EV_PlaySound)
                (0,&(ptr->endpos).x,6,pcVar9,(float)extraout_ST0,0.8,0,100);
      fVar8 = 0.8;
    }
    else {
                    /* Unresolved local var: float flVolume@[???] */
      fVar8 = 0.8;
    }
  }
LAB_000484a3:
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar5 = (*gEngfuncs.pfnRandomLong)(0,0xf);
  iVar7 = (*gEngfuncs.pfnRandomLong)(0,iVar7);
  (*p_Var1)(0,&(ptr->endpos).x,6,local_b0[iVar7],local_c8,fVar8,0,iVar5 + 0x60);
LAB_00048521:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_c4;
}


// EV_TFC_DamageDecal  @ 00048940  (line 508)

char * EV_TFC_DamageDecal(int entity,int bitsDamageType)

{
  physent_s_conflict *ppVar1;
  int32 iVar2;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
  EV_TFC_DamageDecal::decalname._0_4_ = EV_TFC_DamageDecal::decalname._0_4_ & 0xffffff00;
  ppVar1 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(entity);
  if ((ppVar1 != (physent_s_conflict *)0x0) && (ppVar1->rendermode != 4)) {
    if (ppVar1->rendermode != 0) {
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
      builtin_strncpy(EV_TFC_DamageDecal::decalname,"{bproof1",9);
      return EV_TFC_DamageDecal::decalname;
    }
    iVar2 = (*gEngfuncs.pfnRandomLong)(0,4);
    __sprintf_chk(EV_TFC_DamageDecal::decalname,1,0x20,"{shot%i",iVar2 + 1);
  }
  return EV_TFC_DamageDecal::decalname;
}


// EV_TFC_GunshotDecalTrace  @ 00047e10  (line 536)

void __regparm3 EV_TFC_GunshotDecalTrace(pmtrace_t *pTrace,char *name)

{
  Vector *pVVar1;
  _func_void_int_int_int_float_ptr_int *p_Var2;
  _func_int_int *p_Var3;
  int32 iVar4;
  physent_s_conflict *ppVar5;
  int iVar6;
  int iVar7;
  longdouble lVar8;
  char *pcVar9;
  
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
  pVVar1 = &pTrace->endpos;
  (*(gEngfuncs.pEfxAPI)->R_BulletImpactParticles)(&pVVar1->x);
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,0x7fff);
  if (iVar4 < 0x3fff) {
    switch(iVar4 % 5) {
    case 0:
      pcVar9 = "weapons/ric1.wav";
      break;
    case 1:
      pcVar9 = "weapons/ric2.wav";
      break;
    case 2:
      pcVar9 = "weapons/ric3.wav";
      break;
    case 3:
      pcVar9 = "weapons/ric4.wav";
      break;
    case 4:
      pcVar9 = "weapons/ric5.wav";
      break;
    default:
      goto switchD_00047e8f_default;
    }
    (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&pVVar1->x,0,pcVar9,1.0,0.8,0,100);
  }
switchD_00047e8f_default:
  ppVar5 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
  if ((ppVar5 != (physent_s_conflict *)0x0) &&
     (((ppVar5->solid == 4 || (ppVar5->movetype == 0xd)) &&
      (lVar8 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("r_decals"), lVar8 != (longdouble)0)))) {
    p_Var2 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
    iVar6 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(pTrace);
    p_Var3 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
    iVar7 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(name);
    iVar7 = (*p_Var3)(iVar7);
    (*p_Var2)(iVar7,iVar6,0,&pVVar1->x,0);
  }
  return;
}


// EV_TFC_GunshotDecalTrace  @ 000489e0  (line 537)

void EV_TFC_GunshotDecalTrace(pmtrace_t *pTrace,char *name)

{
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
  if (((name != (char *)0x0) && (*name != '\0')) && (pTrace->fraction != 1.0)) {
    EV_TFC_GunshotDecalTrace(pTrace,name);
    return;
  }
  return;
}


// EV_TFC_DecalTrace  @ 00048a20  (line 574)

void EV_TFC_DecalTrace(pmtrace_t *pTrace,char *name)

{
  _func_void_int_int_int_float_ptr_int *p_Var1;
  _func_int_int *p_Var2;
  physent_s_conflict *ppVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  
                    /* Unresolved local var: physent_t * pe@[???] */
  if ((((name != (char *)0x0) && (*name != '\0')) &&
      (ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent),
      ppVar3 != (physent_s_conflict *)0x0)) &&
     (((ppVar3->solid == 4 || (ppVar3->movetype == 0xd)) &&
      (lVar6 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("r_decals"), lVar6 != (longdouble)0)))) {
                    /* Unresolved local var: physent_t * pe@[???] */
    p_Var1 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
    iVar4 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(pTrace);
    p_Var2 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
    iVar5 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(name);
    iVar5 = (*p_Var2)(iVar5);
    (*p_Var1)(iVar5,iVar4,0,&(pTrace->endpos).x,0);
  }
  return;
}


// EV_TFC_DecalGunshot  @ 00048bd0  (line 593)

void EV_TFC_DecalGunshot(pmtrace_t *pTrace,int iBulletType)

{
  float fVar1;
  int iVar2;
  physent_s_conflict *ppVar3;
  int32 iVar4;
  char *name;
  
                    /* Unresolved local var: physent_t * pe@[???] */
  ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
  if ((ppVar3 != (physent_s_conflict *)0x0) && ((ppVar3->solid == 4 || (ppVar3->movetype == 0xd))))
  {
                    /* Unresolved local var: physent_t * pe@[???] */
    if (iBulletType == 7) {
      if (pTrace->fraction != 1.0) {
        name = "hwshot1";
        goto LAB_00048cb3;
      }
    }
    else {
      iVar2 = pTrace->ent;
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
      EV_TFC_DamageDecal::decalname._0_4_ = EV_TFC_DamageDecal::decalname._0_4_ & 0xffffff00;
      if (iBulletType == 10) {
        ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(iVar2);
        if ((ppVar3 != (physent_s_conflict *)0x0) && (ppVar3->rendermode != 4)) {
          if (ppVar3->rendermode == 0) {
            iVar4 = (*gEngfuncs.pfnRandomLong)(0,4);
            __sprintf_chk(EV_TFC_DamageDecal::decalname,1,0x20,"{shot%i",iVar4 + 1);
          }
          else {
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
            builtin_strncpy(EV_TFC_DamageDecal::decalname,"{bproof1",9);
          }
        }
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
        if (EV_TFC_DamageDecal::decalname[0] == '\0') {
          return;
        }
        fVar1 = pTrace->fraction;
      }
      else {
        if (iBulletType == 5) {
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
          ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(iVar2);
          if ((ppVar3 != (physent_s_conflict *)0x0) && (ppVar3->rendermode != 4)) {
            if (ppVar3->rendermode == 0) {
              iVar4 = (*gEngfuncs.pfnRandomLong)(0,4);
              __sprintf_chk(EV_TFC_DamageDecal::decalname,1,0x20,"{shot%i",iVar4 + 1);
            }
            else {
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
              builtin_strncpy(EV_TFC_DamageDecal::decalname,"{bproof1",9);
            }
          }
          EV_TFC_DecalTrace(pTrace,EV_TFC_DamageDecal::decalname);
          return;
        }
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
        ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(iVar2);
        if ((ppVar3 != (physent_s_conflict *)0x0) && (ppVar3->rendermode != 4)) {
          if (ppVar3->rendermode == 0) {
            iVar4 = (*gEngfuncs.pfnRandomLong)(0,4);
            __sprintf_chk(EV_TFC_DamageDecal::decalname,1,0x20,"{shot%i",iVar4 + 1);
          }
          else {
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
            builtin_strncpy(EV_TFC_DamageDecal::decalname,"{bproof1",9);
          }
        }
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
        if (EV_TFC_DamageDecal::decalname[0] == '\0') {
          return;
        }
        fVar1 = pTrace->fraction;
      }
      if (fVar1 != 1.0) {
        name = EV_TFC_DamageDecal::decalname;
LAB_00048cb3:
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
        EV_TFC_GunshotDecalTrace(pTrace,name);
        return;
      }
    }
  }
  return;
}


// EV_TFC_CheckTracer  @ 00048e50  (line 629)

int EV_TFC_CheckTracer(int idx,float *vecSrc,float *end,float *forward,float *right,int iBulletType,
                      int iTracerFreq,int *tracerCount)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
                    /* Unresolved local var: int tracer@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: qboolean player@[???] */
  bVar1 = false;
  if (0 < idx) {
    iVar2 = (*gEngfuncs.GetMaxClients)();
    bVar1 = idx <= iVar2;
  }
  if ((iTracerFreq == 0) ||
     (iVar2 = *tracerCount, *tracerCount = iVar2 + 1, iVar2 % iTracerFreq != 0)) {
    uVar3 = 0;
  }
  else {
                    /* Unresolved local var: Vector vecTracerSrc@[???] */
    if (bVar1) {
                    /* Unresolved local var: Vector offset@[???] */
      local_20 = 0xc0800000;
      local_28 = 0;
      local_24 = 0;
      local_34 = *forward * 16.0 + *right + *right + *vecSrc + 0.0;
      local_30 = forward[1] * 16.0 + right[1] + right[1] + vecSrc[1] + 0.0;
      local_2c = forward[2] * 16.0 + right[2] + right[2] + vecSrc[2] + -4.0;
    }
    else {
      local_34 = *vecSrc;
      local_30 = vecSrc[1];
      local_2c = vecSrc[2];
    }
    uVar3 = (uint)(iTracerFreq != 1);
    if (iBulletType != 6) {
      EV_CreateTracer(&local_34,end);
    }
  }
  return uVar3;
}


// EV_TFC_ShouldShowBlood  @ 00048f80  (line 674)

int EV_TFC_ShouldShowBlood(int color)

{
  uint uVar1;
  longdouble lVar2;
  char *pcVar3;
  
  if (color != -1) {
    if (color == 0xf7) {
      pcVar3 = "violence_hblood";
    }
    else {
      pcVar3 = "violence_ablood";
    }
    lVar2 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)(pcVar3);
    uVar1 = (uint)(NAN((longdouble)0) || NAN(lVar2));
    if ((longdouble)0 != lVar2) {
      uVar1 = 1;
    }
    return uVar1;
  }
  return 0;
}


// EV_TFC_BloodDrips  @ 000481b0  (line 692)

void __regparm3 EV_TFC_BloodDrips(float *origin,int color,int amount)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int local_24;
  
                    /* Unresolved local var: int drop@[???]
                       Unresolved local var: int spray@[???]
                       Unresolved local var: float size@[???] */
  iVar3 = (*gEngfuncs.GetMaxClients)();
  if (1 < iVar3) {
    amount = amount * 2;
  }
  if (amount < 0x100) {
    local_24 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/bloodspray.spr");
    iVar3 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/blood.spr");
    iVar2 = amount / 10;
    if (iVar2 < 4) {
      fVar1 = 3.0;
    }
    else {
      fVar1 = 16.0;
      if (iVar2 < 0x11) {
        fVar1 = (float)iVar2;
      }
    }
  }
  else {
    local_24 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/bloodspray.spr");
    iVar3 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/blood.spr");
    fVar1 = 16.0;
  }
  (*(gEngfuncs.pEfxAPI)->R_BloodSprite)(origin,color,local_24,iVar3,fVar1);
  return;
}


// EV_TFC_BloodDrips  @ 00048fe0  (line 693)

void EV_TFC_BloodDrips(float *origin,int color,int amount)

{
  bool bVar1;
  longdouble lVar2;
  
                    /* Unresolved local var: int drop@[???]
                       Unresolved local var: int spray@[???]
                       Unresolved local var: float size@[???] */
  if (color == -1) {
    return;
  }
  if (color == 0xf7) {
    lVar2 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("violence_hblood");
    bVar1 = lVar2 == (longdouble)0;
    if (NAN(lVar2) || NAN((longdouble)0)) goto LAB_00049050;
  }
  else {
    lVar2 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("violence_ablood");
    bVar1 = lVar2 == (longdouble)0;
    if (NAN(lVar2) || NAN((longdouble)0)) goto LAB_00049050;
  }
  if (bVar1) {
    return;
  }
LAB_00049050:
  if (amount == 0) {
    return;
  }
  EV_TFC_BloodDrips(origin,color,amount);
  return;
}


// EV_TFC_RandomBloodVector  @ 00049070  (line 722)

void EV_TFC_RandomBloodVector(float *direction)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-1.0,1.0);
  *direction = (float)lVar1;
  lVar1 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-1.0,1.0);
  direction[1] = (float)lVar1;
  lVar1 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.0,1.0);
  direction[2] = (float)lVar1;
  return;
}


// EV_TFC_BloodDecalTrace  @ 000490d0  (line 729)

void EV_TFC_BloodDecalTrace(pmtrace_t *pTrace,int bloodColor)

{
  _func_void_int_int_int_float_ptr_int *p_Var1;
  _func_int_int *p_Var2;
  int32 iVar3;
  physent_s_conflict *ppVar4;
  int iVar5;
  int iVar6;
  int in_GS_OFFSET;
  longdouble lVar7;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: char[32] decalname@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,5);
  if (bloodColor != -1) {
    if (bloodColor == 0xf7) {
      lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("violence_hblood");
      if (lVar7 != (longdouble)0) {
        __sprintf_chk(local_40,1,0x20,"{blood%i",iVar3 + 1);
        EV_TFC_DecalTrace(pTrace,local_40);
      }
    }
    else {
      lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("violence_ablood");
      if (lVar7 != (longdouble)0) {
        __sprintf_chk(local_40,1,0x20,"{yblood%i",iVar3 + 1);
                    /* Unresolved local var: physent_t * pe@[???] */
        if ((((local_40[0] != '\0') &&
             (ppVar4 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent),
             ppVar4 != (physent_s_conflict *)0x0)) &&
            ((ppVar4->solid == 4 || (ppVar4->movetype == 0xd)))) &&
           (lVar7 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("r_decals"), lVar7 != (longdouble)0)) {
                    /* Unresolved local var: physent_t * pe@[???] */
          p_Var1 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
          iVar5 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(pTrace);
          p_Var2 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
          iVar6 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(local_40);
          iVar6 = (*p_Var2)(iVar6);
          (*p_Var1)(iVar6,iVar5,0,&(pTrace->endpos).x,0);
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


// EV_TFC_TraceBleed  @ 00049290  (line 751)

void EV_TFC_TraceBleed(float flDamage,float *vecDir,pmtrace_t *ptr,int bitsDamageType,int bloodcolor
                      )

{
  int iVar1;
  longdouble lVar2;
  float local_88;
  float local_84;
  int local_80;
  float local_78;
  float local_74;
  float local_70;
  float local_6c [3];
  pmtrace_s local_60;
  
                    /* Unresolved local var: pmtrace_t Bloodtr@[???]
                       Unresolved local var: Vector vecTraceDir@[???]
                       Unresolved local var: float flNoise@[???]
                       Unresolved local var: int cCount@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: Vector trend@[???] */
  if (((flDamage != 0.0) && (bloodcolor != -1)) && ((bitsDamageType & 0x8000c7U) != 0)) {
    if (flDamage < 10.0) {
      local_80 = 1;
      local_84 = -0.1;
      local_88 = 0.1;
    }
    else if (25.0 <= flDamage) {
      local_80 = 4;
      local_84 = -0.3;
      local_88 = 0.3;
    }
    else {
      local_80 = 2;
      local_84 = -0.2;
      local_88 = 0.2;
    }
    iVar1 = 0;
    do {
      VectorScale(vecDir,-1.0,&local_78);
      lVar2 = (longdouble)(*gEngfuncs.pfnRandomFloat)(local_84,local_88);
      local_78 = (float)(lVar2 + (longdouble)local_78);
      lVar2 = (longdouble)(*gEngfuncs.pfnRandomFloat)(local_84,local_88);
      local_74 = (float)(lVar2 + (longdouble)local_74);
      lVar2 = (longdouble)(*gEngfuncs.pfnRandomFloat)(local_84,local_88);
      local_70 = (float)(lVar2 + (longdouble)local_70);
      VectorMA(&(ptr->endpos).x,-172.0,&local_78,local_6c);
      (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&(ptr->endpos).x,local_6c,2,-1,&local_60);
      if (local_60.fraction != 1.0) {
        EV_TFC_BloodDecalTrace(&local_60,bloodcolor);
      }
      iVar1 = iVar1 + 1;
    } while (local_80 != iVar1);
  }
  return;
}


// EV_TFC_SpawnBlood  @ 00049490  (line 811)

void EV_TFC_SpawnBlood(float *vecSpot,int bloodColor,float flDamage)

{
  bool bVar1;
  longdouble lVar2;
  
                    /* Unresolved local var: int drop@[???]
                       Unresolved local var: int spray@[???]
                       Unresolved local var: float size@[???] */
  if (bloodColor == -1) {
    return;
  }
  if (bloodColor == 0xf7) {
    lVar2 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("violence_hblood");
    bVar1 = lVar2 == (longdouble)0;
    if (NAN(lVar2) || NAN((longdouble)0)) goto LAB_00049510;
  }
  else {
    lVar2 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("violence_ablood");
    bVar1 = lVar2 == (longdouble)0;
    if (NAN(lVar2) || NAN((longdouble)0)) goto LAB_00049510;
  }
  if (bVar1) {
    return;
  }
LAB_00049510:
  if ((int)flDamage == 0) {
    return;
  }
  EV_TFC_BloodDrips(vecSpot,bloodColor,(int)flDamage);
  return;
}


// EV_TFC_GetTeamIndex  @ 00049530  (line 816)

int EV_TFC_GetTeamIndex(int idx)

{
  int iVar1;
  cl_entity_s *pcVar2;
  
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  if (0 < idx) {
    iVar1 = (*gEngfuncs.GetMaxClients)();
    if (idx <= iVar1) {
      pcVar2 = GetEntity(idx);
      if (pcVar2 != (cl_entity_s *)0x0) {
        return (pcVar2->curstate).team;
      }
    }
  }
  return -1;
}


// EV_TFC_IsAllyTeam  @ 00049570  (line 830)

int EV_TFC_IsAllyTeam(int iTeam1,int iTeam2)

{
  char *__nptr;
  uint uVar1;
  uint local_20 [4];
  uint local_10;
  
                    /* Unresolved local var: int teamallies@[???]
                       Unresolved local var: int[5] team_ally@[???]
                       Unresolved local var: int i@[???] */
  __nptr = (*gEngfuncs.PhysInfo_ValueForKey)("ta");
  uVar1 = strtol(__nptr,(char **)0x0,10);
  local_20[0] = uVar1 & 0x1f;
  local_20[1] = (int)uVar1 >> 5 & 0x1f;
  local_20[2] = (int)uVar1 >> 10 & 0x1f;
  local_10 = (int)uVar1 >> 0x14 & 0x1f;
  local_20[3] = (int)uVar1 >> 0xf & 0x1f;
  return (uint)(iTeam1 == iTeam2) | (int)local_20[iTeam1] >> ((char)iTeam2 - 1U & 0x1f) & 1U;
}


// EV_TFC_IsAlly  @ 00049600  (line 851)

int EV_TFC_IsAlly(int idx1,int idx2)

{
  int iVar1;
  cl_entity_s *pcVar2;
  int iVar3;
  char *__nptr;
  uint uVar4;
  uint local_20 [4];
  uint local_10;
  
                    /* Unresolved local var: cl_entity_t * player@[???]
                       Unresolved local var: int t1@[???]
                       Unresolved local var: int t2@[???] */
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  if (((idx1 < 1) || (iVar1 = (*gEngfuncs.GetMaxClients)(), iVar1 < idx1)) ||
     (pcVar2 = GetEntity(idx1), pcVar2 == (cl_entity_s *)0x0)) {
    iVar1 = -1;
  }
  else {
    iVar1 = (pcVar2->curstate).team;
  }
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  if (((((0 < idx2) && (iVar3 = (*gEngfuncs.GetMaxClients)(), idx2 <= iVar3)) &&
       ((pcVar2 = GetEntity(idx2), pcVar2 != (cl_entity_s *)0x0 &&
        ((iVar3 = (pcVar2->curstate).team, 1 < iVar1 + 1U && (1 < iVar3 + 1U)))))) &&
      (pcVar2 = (*gEngfuncs.GetLocalPlayer)(), pcVar2 != (cl_entity_s *)0x0)) &&
     ((iVar1 < 5 && (iVar3 < 5)))) {
                    /* Unresolved local var: int teamallies@[???]
                       Unresolved local var: int[5] team_ally@[???]
                       Unresolved local var: int i@[???] */
    __nptr = (*gEngfuncs.PhysInfo_ValueForKey)("ta");
    uVar4 = strtol(__nptr,(char **)0x0,10);
    local_20[0] = uVar4 & 0x1f;
    local_20[1] = (int)uVar4 >> 5 & 0x1f;
    local_20[2] = (int)uVar4 >> 10 & 0x1f;
    local_10 = (int)uVar4 >> 0x14 & 0x1f;
    local_20[3] = (int)uVar4 >> 0xf & 0x1f;
    return (uint)(iVar3 == iVar1) | (int)local_20[iVar1] >> ((char)iVar3 - 1U & 0x1f) & 1U;
  }
  return 0;
}


// EV_TFC_TraceAttack  @ 00048290  (line 882)

void __regparm3
EV_TFC_TraceAttack(int idx,float flDamage,float *vecDir,pmtrace_t *ptr,int bitsDamageType)

{
  int iVar1;
  int iVar2;
  cl_entity_s *pcVar3;
  longdouble extraout_ST0;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
  VectorScale((float *)flDamage,-4.0,&local_24);
  local_18 = vecDir[5] - local_24;
  local_14 = vecDir[6] - local_20;
  local_10 = vecDir[7] - local_1c;
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)((pmtrace_s *)vecDir);
  if ((0 < iVar1) && (iVar2 = (*gEngfuncs.GetMaxClients)(), iVar1 <= iVar2)) {
                    /* Unresolved local var: int blood@[???]
                       Unresolved local var: cl_entity_t * ent@[???] */
    iVar2 = (*gEngfuncs.GetMaxClients)();
    if ((iVar2 < iVar1) || (pcVar3 = GetEntity(iVar1), pcVar3 == (cl_entity_s *)0x0)) {
      iVar1 = -1;
    }
    else {
      iVar1 = (pcVar3->curstate).team;
    }
                    /* Unresolved local var: cl_entity_t * ent@[???] */
    if (((idx < 1) || (iVar2 = (*gEngfuncs.GetMaxClients)(), iVar2 < idx)) ||
       (pcVar3 = GetEntity(idx), pcVar3 == (cl_entity_s *)0x0)) {
      iVar2 = -1;
    }
    else {
      iVar2 = (pcVar3->curstate).team;
    }
    if (iVar2 != iVar1) {
                    /* Unresolved local var: int drop@[???]
                       Unresolved local var: int spray@[???]
                       Unresolved local var: float size@[???] */
      (*gEngfuncs.pfnGetCvarFloat)("violence_hblood");
      if ((extraout_ST0 != (longdouble)0) && ((int)(float)ptr != 0)) {
        EV_TFC_BloodDrips(&local_18,0xf7,(int)(float)ptr);
      }
    }
  }
  return;
}


// EV_TFC_TraceAttack  @ 000499f0  (line 883)

void EV_TFC_TraceAttack(int idx,float flDamage,float *vecDir,pmtrace_t *ptr,int bitsDamageType)

{
  int iVar1;
  int iVar2;
  cl_entity_s *pcVar3;
  longdouble extraout_ST0;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
  if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
    VectorScale(vecDir,-4.0,&local_24);
    local_18 = (ptr->endpos).x - local_24;
    local_14 = (ptr->endpos).y - local_20;
    local_10 = (ptr->endpos).z - local_1c;
    iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(ptr);
    if ((0 < iVar1) && (iVar2 = (*gEngfuncs.GetMaxClients)(), iVar1 <= iVar2)) {
                    /* Unresolved local var: int blood@[???]
                       Unresolved local var: cl_entity_t * ent@[???] */
      iVar2 = (*gEngfuncs.GetMaxClients)();
      if ((iVar2 < iVar1) || (pcVar3 = GetEntity(iVar1), pcVar3 == (cl_entity_s *)0x0)) {
        iVar1 = -1;
      }
      else {
        iVar1 = (pcVar3->curstate).team;
      }
                    /* Unresolved local var: cl_entity_t * ent@[???] */
      if (((idx < 1) || (iVar2 = (*gEngfuncs.GetMaxClients)(), iVar2 < idx)) ||
         (pcVar3 = GetEntity(idx), pcVar3 == (cl_entity_s *)0x0)) {
        iVar2 = -1;
      }
      else {
        iVar2 = (pcVar3->curstate).team;
      }
      if (iVar2 != iVar1) {
                    /* Unresolved local var: int drop@[???]
                       Unresolved local var: int spray@[???]
                       Unresolved local var: float size@[???] */
        (*gEngfuncs.pfnGetCvarFloat)("violence_hblood");
        if ((extraout_ST0 != (longdouble)0) && ((int)flDamage != 0)) {
          EV_TFC_BloodDrips(&local_18,0xf7,(int)flDamage);
        }
      }
    }
  }
  return;
}


// EV_TFC_FireBullets  @ 00049b20  (line 923)

void EV_TFC_FireBullets(int idx,float *forward,float *right,float *up,int cShots,float *vecSrc,
                       float *vecDirShooting,float *vecSpread,float flDistance,int iBulletType,
                       int iTracerFreq,int *tracerCount,int iDamage)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int in_GS_OFFSET;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  float *bitsDamageType;
  int local_d0;
  int local_b0;
  float local_a4;
  float local_a0;
  float local_9c [6];
  pmtrace_s local_84;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int iShot@[???]
                       Unresolved local var: Vector vecRight@[???]
                       Unresolved local var: Vector vecUp@[???]
                       Unresolved local var: int tracer@[???]
                       Unresolved local var: int cMultiGunShots@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  fVar4 = *right;
  fVar1 = right[1];
  fVar2 = right[2];
  if (0 < cShots) {
    local_b0 = 0;
    local_d0 = 1;
    do {
      do {
                    /* Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector spread@[???] */
        (*gEngfuncs.pfnRandomFloat)(-0.5,0.5);
        (*gEngfuncs.pfnRandomFloat)(-0.5,0.5);
        (*gEngfuncs.pfnRandomFloat)(-0.5,0.5);
        (*gEngfuncs.pfnRandomFloat)(-0.5,0.5);
        lVar5 = extraout_ST0_02 + (longdouble)(float)extraout_ST0_01;
        lVar6 = (longdouble)(float)((longdouble)(float)extraout_ST0 + extraout_ST0_00);
      } while ((longdouble)1 < lVar5 * lVar5 + lVar6 * lVar6);
      lVar6 = lVar6 * (longdouble)*vecSpread;
      lVar5 = lVar5 * (longdouble)vecSpread[1];
      lVar7 = (longdouble)*up * lVar5 + (longdouble)fVar4 * lVar6 + (longdouble)*vecDirShooting;
      local_a4 = (float)lVar7;
      local_9c[1] = (float)(lVar7 * (longdouble)flDistance + (longdouble)*vecSrc);
      lVar7 = (longdouble)up[1] * lVar5 + (longdouble)fVar1 * lVar6 + (longdouble)vecDirShooting[1];
      local_a0 = (float)lVar7;
      local_9c[2] = (float)(lVar7 * (longdouble)flDistance + (longdouble)vecSrc[1]);
      lVar6 = lVar5 * (longdouble)up[2] + lVar6 * (longdouble)fVar2 + (longdouble)vecDirShooting[2];
      local_9c[0] = (float)lVar6;
      local_9c[3] = (float)(lVar6 * (longdouble)flDistance + (longdouble)vecSrc[2]);
      (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
      (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
      (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(idx + -1);
      (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
      (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(vecSrc,local_9c + 1,2,-1,&local_84);
      bitsDamageType = vecSrc;
      iVar3 = EV_TFC_CheckTracer(idx,vecSrc,&local_84.endpos.x,forward,right,iBulletType,iTracerFreq
                                 ,tracerCount);
      if (local_84.fraction != 1.0) {
        if (iDamage == 0) {
          if (iBulletType == 3) {
            if (iVar3 == 0) {
              EV_TFC_PlayTextureSound(idx,&local_84,vecSrc,local_9c + 1,3);
              EV_TFC_DecalGunshot(&local_84,3);
            }
          }
          else if (iBulletType == 4) {
            if (iVar3 == 0) {
              EV_TFC_DecalGunshot(&local_84,4);
            }
          }
          else if (iBulletType == 2) {
            if (iVar3 == 0) {
              EV_TFC_PlayTextureSound(idx,&local_84,vecSrc,local_9c + 1,2);
              EV_TFC_DecalGunshot(&local_84,2);
            }
          }
          else if (iVar3 == 0) {
            EV_TFC_PlayTextureSound(idx,&local_84,vecSrc,local_9c + 1,iBulletType);
            EV_TFC_DecalGunshot(&local_84,iBulletType);
          }
        }
        else {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
          if (cShots == 1) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
            if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
              EV_TFC_TraceAttack(idx,(float)&local_a4,(float *)&local_84,(pmtrace_t *)(float)iDamage
                                 ,(int)bitsDamageType);
            }
            EV_TFC_PlayTextureSound(idx,&local_84,vecSrc,local_9c + 1,iBulletType);
            EV_TFC_DecalGunshot(&local_84,iBulletType);
            (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
            break;
          }
          if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
            EV_TFC_TraceAttack(idx,(float)&local_a4,(float *)&local_84,(pmtrace_t *)(float)iDamage,
                               (int)bitsDamageType);
          }
          local_b0 = local_b0 + 1;
        }
      }
      (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
      local_d0 = local_d0 + 1;
    } while (local_d0 <= cShots);
    if (local_b0 != 0) {
      iVar3 = 0;
      do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int[5] decal_index@[???]
                       Unresolved local var: char[32] decalname@[???]
                       Unresolved local var: Vector size@[???] */
        iVar3 = iVar3 + 1;
        __sprintf_chk(local_40,1,0x20,"{shot%i",iVar3);
        fVar4 = (float)(*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(local_40);
        local_9c[iVar3] = fVar4;
      } while (iVar3 != 5);
      local_a4 = *vecSpread;
      local_a0 = vecSpread[1];
      local_9c[0] = 0.0;
      (*(gEngfuncs.pEfxAPI)->R_MultiGunshot)
                (vecSrc,vecDirShooting,&local_a4,local_b0,5,(int *)(local_9c + 1));
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// EV_FireTFCShotgun  @ 0004a0b0  (line 1041)

void EV_FireTFCShotgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  int model;
  qboolean qVar2;
  int32 iVar3;
  longdouble lVar4;
  float local_a0 [3];
  float local_94 [3];
  float local_88 [3];
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70 [3];
  float local_64 [3];
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [6];
  
                    /* Unresolved local var: Vector ShellVelocity@[???]
                       Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_4c = args->origin[0];
  local_48 = args->origin[1];
  local_44 = args->origin[2];
  local_40 = args->angles[0];
  local_3c = args->angles[1];
  local_38 = args->angles[2];
  local_34 = args->velocity[0];
  local_30 = args->velocity[1];
  idx = args->entindex;
  local_2c = args->velocity[2];
  (*gEngfuncs.pfnAngleVectors)(&local_40,&local_58,local_64,local_70);
  model = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/shotgunshell.mdl");
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    EV_MuzzleFlash();
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(1,2);
  }
  EV_GetDefaultShellInfo
            (args,&local_4c,&local_34,local_a0,local_94,&local_58,local_64,local_70,20.0,-12.0,4.0);
  EV_EjectBrass(local_94,local_a0,local_3c,model,2);
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
  lVar4 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.95,1.0);
  (*p_Var1)(idx,&local_4c,1,"weapons/sbarrel1.wav",(float)lVar4,0.8,0,iVar3 + 0x5d);
  EV_GetGunPosition(args,local_88,&local_4c);
  local_7c = local_58;
  local_78 = local_54;
  local_74 = local_50;
  local_28[0] = 0.04;
  local_28[1] = 0.04;
  local_28[2] = 0.0;
  EV_TFC_FireBullets(idx,&local_58,local_64,local_70,6,local_88,&local_7c,local_28,2048.0,6,0,
                     &g_tr_decal[0x1f].hitgroup + idx,4);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    V_PunchAxis(0,-2.0);
  }
  return;
}


// EV_ReloadTFCShotgun  @ 0004a3f0  (line 1088)

void EV_ReloadTFCShotgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  qboolean qVar2;
  int32 iVar3;
  int iVar4;
  char *pcVar5;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  idx = args->entindex;
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(3,2);
  }
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,1);
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  if (iVar3 == 0) {
    iVar4 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
    pcVar5 = "weapons/reload3.wav";
  }
  else {
    iVar4 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
    pcVar5 = "weapons/reload1.wav";
  }
  (*p_Var1)(idx,&local_18,3,pcVar5,1.0,0.8,0,iVar4 + 0x55);
  return;
}


// EV_PumpTFCShotgun  @ 0004a500  (line 1115)

void EV_PumpTFCShotgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  int32 iVar2;
  qboolean qVar3;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int resetanim@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  idx = args->entindex;
  if (args->bparam1 != 0) {
    qVar3 = EV_IsLocal(idx);
    if (qVar3 != 0) {
      (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(4,2);
    }
  }
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar2 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
  (*p_Var1)(idx,&local_18,3,"weapons/scock1.wav",1.0,0.8,0,iVar2 + 0x5f);
  return;
}


// EV_TFC_NailTouch  @ 000480f0  (line 1136)

void EV_TFC_NailTouch(tempent_s *ent,pmtrace_t *ptr)

{
  physent_s_conflict *ppVar1;
  int32 iVar2;
  int in_GS_OFFSET;
  char local_30 [32];
  int local_10;
  
                    /* Unresolved local var: char[32] decalname@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  ppVar1 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(ptr->ent);
  if ((ppVar1 != (physent_s_conflict *)0x0) && ((ppVar1->solid == 4 || (ppVar1->movetype == 0xd))))
  {
                    /* Unresolved local var: char[32] decalname@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
    local_30[0] = '\0';
    iVar2 = (*gEngfuncs.pfnRandomLong)(0,4);
    __sprintf_chk(local_30,1,0x20,"{shot%i",iVar2 + 1);
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
    if ((local_30[0] != '\0') && (ptr->fraction != 1.0)) {
      EV_TFC_GunshotDecalTrace(ptr,local_30);
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// EV_TFC_TranqNailTouch  @ 00047fb0  (line 1152)

void EV_TFC_TranqNailTouch(tempent_s *ent,pmtrace_t *ptr)

{
  int iVar1;
  int iVar2;
  int32 iVar3;
  physent_s_conflict *ppVar4;
  int in_GS_OFFSET;
  char local_30 [32];
  int local_10;
  
                    /* Unresolved local var: char[32] decalname@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: qboolean player@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(ptr);
  if (0 < iVar1) {
    iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(ptr);
    iVar2 = (*gEngfuncs.GetMaxClients)();
    if (iVar1 <= iVar2) {
      local_30[0] = '\0';
      iVar3 = (*gEngfuncs.pfnRandomLong)(0,4);
      __sprintf_chk(local_30,1,0x20,"{shot%i",iVar3 + 1);
      goto LAB_00048050;
    }
  }
  local_30[0] = '\0';
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,4);
  __sprintf_chk(local_30,1,0x20,"{shot%i",iVar3 + 1);
                    /* Unresolved local var: physent_t * pe@[???] */
  ppVar4 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(ptr->ent);
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
  if (((ppVar4 != (physent_s_conflict *)0x0) &&
      (((ppVar4->solid == 4 || (ppVar4->movetype == 0xd)) && (local_30[0] != '\0')))) &&
     (ptr->fraction != 1.0)) {
    EV_TFC_GunshotDecalTrace(ptr,local_30);
  }
LAB_00048050:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// EV_TFC_WaterLevel  @ 0004a5d0  (line 1174)

float EV_TFC_WaterLevel(float *position,float minz,float maxz)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector midUp@[???]
                       Unresolved local var: float diff@[???] */
  local_18 = *position;
  local_14 = position[1];
  local_10 = minz;
  iVar3 = (*gEngfuncs.PM_PointContents)(&local_18,(int *)0x0);
  fVar1 = minz;
  if (iVar3 == -3) {
    local_10 = maxz;
    iVar3 = (*gEngfuncs.PM_PointContents)(&local_18,(int *)0x0);
    fVar1 = maxz;
    if (iVar3 != -3) {
      fVar2 = maxz - minz;
      fVar1 = local_10;
      while (1.0 < fVar2) {
        local_10 = fVar2 * 0.5 + minz;
        iVar3 = (*gEngfuncs.PM_PointContents)(&local_18,(int *)0x0);
        if (iVar3 == -3) {
          minz = local_10;
        }
        else {
          maxz = local_10;
        }
        fVar1 = local_10;
        fVar2 = maxz - minz;
      }
    }
  }
  return fVar1;
}


// EV_TFC_BubbleTrail  @ 0004a6f0  (line 1207)

void EV_TFC_BubbleTrail(float *from,float *to,int count,int modelindex)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_3c;
  float local_38;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float flHeight@[???] */
                    /* Unresolved local var: Vector midUp@[???]
                       Unresolved local var: float diff@[???] */
  local_3c = from[2];
  local_28 = *from;
  local_24 = from[1];
  local_20 = local_3c;
  iVar3 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
  fVar1 = local_3c;
  if (iVar3 == -3) {
    local_38 = local_3c + 256.0;
    local_20 = local_38;
    iVar3 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
    fVar1 = local_38;
    if (iVar3 != -3) {
      fVar2 = local_38 - local_3c;
      while (fVar1 = local_20, 1.0 < fVar2) {
        local_20 = fVar2 * 0.5 + local_3c;
        iVar3 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
        if (iVar3 == -3) {
          local_3c = local_20;
        }
        else {
          local_38 = local_20;
        }
        fVar2 = local_38 - local_3c;
      }
    }
  }
  fVar1 = fVar1 - from[2];
  if (fVar1 < 8.0) {
    local_3c = to[2];
                    /* Unresolved local var: Vector midUp@[???]
                       Unresolved local var: float diff@[???] */
    local_28 = *to;
    local_24 = to[1];
    local_20 = local_3c;
    iVar3 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
    fVar1 = local_3c;
    if (iVar3 == -3) {
      local_38 = local_3c + 256.0;
      local_20 = local_38;
      iVar3 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
      fVar1 = local_38;
      if (iVar3 != -3) {
        fVar2 = local_38 - local_3c;
        while (fVar1 = local_20, 1.0 < fVar2) {
          local_20 = fVar2 * 0.5 + local_3c;
          iVar3 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
          if (iVar3 == -3) {
            local_3c = local_20;
          }
          else {
            local_38 = local_20;
          }
          fVar2 = local_38 - local_3c;
        }
      }
    }
    fVar1 = fVar1 - to[2];
    if (fVar1 < 8.0) {
      return;
    }
    fVar1 = (to[2] + fVar1) - from[2];
  }
  if (0xff < count) {
    count = 0xff;
  }
  (*(gEngfuncs.pEfxAPI)->R_BubbleTrail)(from,to,fVar1,modelindex,count,8.0);
  return;
}


// EV_TFC_ClientProjectile  @ 0004a9a0  (line 1231)

void EV_TFC_ClientProjectile
               (float *vecOrigin,float *vecVelocity,short sModelIndex,int iOwnerIndex,int iLife,
               _func_void_tempent_s_ptr_pmtrace_t_ptr *hitcallback)

{
                    /* WARNING: Could not recover jumptable at 0x0004a9be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(gEngfuncs.pEfxAPI)->R_Projectile)
            (vecOrigin,vecVelocity,(int)sModelIndex,iLife,iOwnerIndex,
             (_func_void_tempent_s_ptr_pmtrace_s_ptr *)hitcallback);
  return;
}


// EV_FireTFCNailgun  @ 0004a9d0  (line 1236)

void EV_FireTFCNailgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  int iVar2;
  qboolean qVar3;
  int32 iVar4;
  longdouble lVar5;
  float local_70 [3];
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40 [3];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: Vector vecVelocity@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_34 = args->origin[0];
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  idx = args->entindex;
  (*gEngfuncs.pfnAngleVectors)(&local_28,local_4c,local_58,local_64);
  iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/nail.mdl");
  qVar3 = EV_IsLocal(idx);
  if (qVar3 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(5,2);
  }
  EV_GetGunPosition(args,local_70,&local_34);
  VectorMA(local_70,-4.0,local_64,local_70);
  VectorMA(local_70,2.0,local_58,local_70);
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
  lVar5 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.95,1.0);
  (*p_Var1)(idx,&local_34,1,"weapons/airgun_1.wav",(float)lVar5,0.8,0,iVar4 + 0x5d);
  VectorScale(local_4c,1000.0,local_40);
  (*(gEngfuncs.pEfxAPI)->R_Projectile)(local_70,local_40,(int)(short)iVar2,6,idx,EV_TFC_NailTouch);
  qVar3 = EV_IsLocal(idx);
  if (qVar3 != 0) {
    V_PunchAxis(0,-1.0);
  }
  return;
}


// EV_FireTFCAutoRifle  @ 0004abd0  (line 1279)

void EV_FireTFCAutoRifle(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  physent_s_conflict *ppVar2;
  int32 iVar3;
  float *bitsDamageType;
  float local_c0 [3];
  float local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  float local_a8 [3];
  float local_9c [3];
  float local_90 [3];
  float local_84;
  undefined4 local_80;
  undefined4 local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  pmtrace_t local_60;
  
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_78 = args->origin[0];
  local_74 = args->origin[1];
  local_70 = args->origin[2];
  local_6c = args->angles[0];
  local_68 = args->angles[1];
  local_64 = args->angles[2];
  idx = args->entindex;
  (*gEngfuncs.pfnAngleVectors)(&local_6c,&local_84,local_90,local_9c);
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(6,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_78,1,"weapons/sniper.wav",0.9,0.8,0,100);
  EV_GetGunPosition(args,local_c0,&local_78);
  local_b4 = local_84;
  local_b0 = local_80;
  local_ac = local_7c;
  VectorMA(local_c0,8192.0,&local_b4,local_a8);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(idx + -1);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  bitsDamageType = local_a8;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_c0,local_a8,2,-1,&local_60);
  if (local_60.fraction != 1.0) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
    if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
      EV_TFC_TraceAttack(idx,(float)&local_b4,(float *)&local_60,(pmtrace_t *)0x41000000,
                         (int)bitsDamageType);
    }
    EV_TFC_PlayTextureSound(idx,&local_60,local_c0,local_a8,3);
                    /* Unresolved local var: physent_t * pe@[???] */
    ppVar2 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_60.ent);
    if ((ppVar2 != (physent_s_conflict *)0x0) && ((ppVar2->solid == 4 || (ppVar2->movetype == 0xd)))
       ) {
                    /* Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: int idx@[???] */
      EV_TFC_DamageDecal::decalname._0_4_ = EV_TFC_DamageDecal::decalname._0_4_ & 0xffffff00;
      ppVar2 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_60.ent);
      if ((ppVar2 != (physent_s_conflict *)0x0) && (ppVar2->rendermode != 4)) {
        if (ppVar2->rendermode == 0) {
          iVar3 = (*gEngfuncs.pfnRandomLong)(0,4);
          __sprintf_chk(EV_TFC_DamageDecal::decalname,1,0x20,"{shot%i",iVar3 + 1);
        }
        else {
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
          builtin_strncpy(EV_TFC_DamageDecal::decalname,"{bproof1",9);
        }
      }
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
      if ((EV_TFC_DamageDecal::decalname[0] != '\0') && (local_60.fraction != 1.0)) {
        EV_TFC_GunshotDecalTrace(&local_60,EV_TFC_DamageDecal::decalname);
      }
    }
  }
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  return;
}


// EV_FireTFCSuperShotgun  @ 0004aef0  (line 1330)

void EV_FireTFCSuperShotgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  int model;
  qboolean qVar2;
  int32 iVar3;
  longdouble lVar4;
  float local_a0 [3];
  float local_94 [3];
  float local_88 [3];
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70 [3];
  float local_64 [3];
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [6];
  
                    /* Unresolved local var: Vector ShellVelocity@[???]
                       Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_4c = args->origin[0];
  local_48 = args->origin[1];
  local_44 = args->origin[2];
  local_40 = args->angles[0];
  local_3c = args->angles[1];
  local_38 = args->angles[2];
  local_34 = args->velocity[0];
  local_30 = args->velocity[1];
  idx = args->entindex;
  local_2c = args->velocity[2];
  (*gEngfuncs.pfnAngleVectors)(&local_40,&local_58,local_64,local_70);
  model = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/shotgunshell.mdl");
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    EV_MuzzleFlash();
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(1,2);
  }
  EV_GetDefaultShellInfo
            (args,&local_4c,&local_34,local_a0,local_94,&local_58,local_64,local_70,20.0,-12.0,4.0);
  EV_EjectBrass(local_94,local_a0,local_3c,model,2);
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,0x1f);
  lVar4 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.95,1.0);
  (*p_Var1)(idx,&local_4c,1,"weapons/shotgn2.wav",(float)lVar4,0.8,0,iVar3 + 0x5d);
  EV_GetGunPosition(args,local_88,&local_4c);
  local_7c = local_58;
  local_78 = local_54;
  local_74 = local_50;
  local_28[0] = 0.04;
  local_28[1] = 0.04;
  local_28[2] = 0.0;
  EV_TFC_FireBullets(idx,&local_58,local_64,local_70,0xe,local_88,&local_7c,local_28,2048.0,6,4,
                     &g_tr_decal[0x1f].hitgroup + idx,4);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    V_PunchAxis(0,-4.0);
  }
  return;
}


// EV_FireTFCSuperNailgun  @ 0004b230  (line 1378)

void EV_FireTFCSuperNailgun(event_args_t *args)

{
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  int iVar2;
  qboolean qVar3;
  int32 iVar4;
  float local_70 [3];
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40 [3];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: Vector vecVelocity@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_34 = args->origin[0];
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  idx = args->entindex;
  (*gEngfuncs.pfnAngleVectors)(&local_28,local_4c,local_58,local_64);
  iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/nail.mdl");
  qVar3 = EV_IsLocal(idx);
  if (qVar3 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(5,2);
  }
  EV_GetGunPosition(args,local_70,&local_34);
  VectorMA(local_70,-4.0,local_64,local_70);
  VectorMA(local_70,2.0,local_58,local_70);
  p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
  iVar4 = (*gEngfuncs.pfnRandomLong)(0,0xf);
  (*p_Var1)(idx,&local_34,1,"weapons/spike2.wav",1.0,0.8,0,iVar4 + 0x5e);
  VectorScale(local_4c,1000.0,local_40);
  (*(gEngfuncs.pEfxAPI)->R_Projectile)(local_70,local_40,(int)(short)iVar2,6,idx,EV_TFC_NailTouch);
  qVar3 = EV_IsLocal(idx);
  if (qVar3 != 0) {
    V_PunchAxis(0,-1.0);
  }
  return;
}


// EV_TFC_Assault_WindUp  @ 0004b420  (line 1421)

void EV_TFC_Assault_WindUp(event_args_t *args)

{
  int iVar1;
  int idx;
  qboolean qVar2;
  longdouble extraout_ST0;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???] */
  idx = args->entindex;
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  iVar1 = idx + -1;
  g_flSpinDownTime[iVar1] = 0.0;
  (*gEngfuncs.GetClientTime)();
  g_flSpinUpTime[iVar1] = (float)(extraout_ST0 + (longdouble)3.5);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(2,2);
  }
  g_bACSpinning[iVar1] = 0;
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,6,"weapons/asscan2.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,6,"weapons/asscan4.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,1,"weapons/asscan3.wav");
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,1,"weapons/asscan1.wav",0.98,0.8,0,0x7d);
  return;
}


// EV_TFC_Assault_WindDown  @ 0004b540  (line 1443)

void EV_TFC_Assault_WindDown(event_args_t *args)

{
  int iVar1;
  int idx;
  qboolean qVar2;
  longdouble extraout_ST0;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???] */
  idx = args->entindex;
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  iVar1 = idx + -1;
  if (g_flSpinUpTime[iVar1] == 0.0) {
    (*gEngfuncs.GetClientTime)();
    g_flSpinDownTime[iVar1] = (float)(extraout_ST0 + (longdouble)3.0);
  }
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(3,2);
  }
  g_bACSpinning[iVar1] = 0;
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,6,"weapons/asscan2.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,6,"weapons/asscan4.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(idx,1,"weapons/asscan1.wav");
  if (args->bparam1 == 0) {
    (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,1,"weapons/asscan3.wav",0.98,0.8,0,0x7d);
  }
  return;
}


// EV_TFC_Assault_Start  @ 0004b690  (line 1467)

void EV_TFC_Assault_Start(event_args_t *args)

{
  int iVar1;
  int iVar2;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  iVar2 = args->entindex;
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  iVar1 = iVar2 + -1;
  g_flSpinDownTime[iVar1] = 0.0;
  g_flSpinUpTime[iVar1] = 0.0;
  g_bACSpinning[iVar1] = 0;
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(iVar2,6,"weapons/asscan2.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(iVar2,6,"weapons/asscan4.wav");
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(iVar2,&local_18,6,"weapons/asscan2.wav",0.98,0.8,0,0x7d);
  return;
}


// EV_TFC_Assault_Fire  @ 0004b760  (line 1489)

void EV_TFC_Assault_Fire(event_args_t *args)

{
  int idx;
  int iVar1;
  int model;
  qboolean qVar2;
  float local_a0 [3];
  float local_94 [3];
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [6];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: Vector ShellVelocity@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecAiming@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: int oddammo@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_4c = args->origin[0];
  local_48 = args->origin[1];
  local_44 = args->origin[2];
  local_40 = args->angles[0];
  local_3c = args->angles[1];
  local_38 = args->angles[2];
  local_34 = args->velocity[0];
  local_30 = args->velocity[1];
  idx = args->entindex;
  local_2c = args->velocity[2];
  iVar1 = args->bparam1;
  model = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/shell.mdl");
  (*gEngfuncs.pfnAngleVectors)(&local_40,&local_70,&local_7c,&local_88);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    EV_MuzzleFlash();
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(4,2);
  }
  g_bACSpinning[idx + -1] = 0;
  if (iVar1 != 0) {
    EV_GetDefaultShellInfo
              (args,&local_4c,&local_34,local_94,local_a0,&local_70,&local_7c,&local_88,15.0,-25.0,
               6.0);
    EV_EjectBrass(local_a0,local_94,local_3c,model,1);
  }
  EV_GetGunPosition(args,&local_64,&local_4c);
  local_58 = local_70;
  local_64 = local_7c + local_7c + local_88 * -4.0 + local_64;
  local_54 = local_6c;
  local_50 = local_68;
  local_28[0] = 0.1;
  local_28[1] = 0.1;
  local_28[2] = 0.0;
  local_60 = local_78 + local_78 + local_84 * -4.0 + local_60;
  local_5c = local_80 * -4.0 + local_74 + local_74 + local_5c;
  EV_TFC_FireBullets(idx,&local_70,&local_7c,&local_88,5,&local_64,&local_58,local_28,8192.0,7,8,
                     tracerCount + idx + -1,8);
  return;
}


// EV_TFC_Assault_StartSpin  @ 0004ba90  (line 1540)

void EV_TFC_Assault_StartSpin(event_args_t *args)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  iVar1 = args->entindex;
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  *(undefined4 *)(&DAT_000e6a7c + iVar1 * 4) = 1;
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(iVar1,6,"weapons/asscan2.wav");
  (*(gEngfuncs.pEventAPI)->EV_StopSound)(iVar1,6,"weapons/asscan4.wav");
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(iVar1,&local_18,6,"weapons/asscan4.wav",0.98,0.8,0,0x7d);
  return;
}


// EV_TFC_Assault_Spin  @ 0004bb50  (line 1559)

void EV_TFC_Assault_Spin(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  idx = args->entindex;
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(4,2);
  }
  *(undefined4 *)(&DAT_000e6a7c + idx * 4) = 1;
  return;
}


// EV_TFC_Flame_Fire  @ 0004bb90  (line 1577)

void EV_TFC_Flame_Fire(event_args_t *args)

{
  int idx;
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  qboolean qVar5;
  int iVar6;
  float local_90;
  float local_8c;
  float local_7c;
  undefined4 local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  float local_68;
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  
                    /* Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: Vector BubbleSpot@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: Vector vecVelocity@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: int bubble@[???]
                       Unresolved local var: int underwater@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  iVar6 = args->bparam1;
  local_40 = args->origin[0];
  local_3c = args->origin[1];
  local_38 = args->origin[2];
  local_34 = args->angles[0];
  local_30 = args->angles[1];
  local_2c = args->angles[2];
  idx = args->entindex;
  iVar3 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/fthrow.spr");
  iVar4 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/bubble.spr");
  (*gEngfuncs.pfnAngleVectors)(&local_34,local_4c,local_58,local_64);
  qVar5 = EV_IsLocal(idx);
  if (qVar5 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(5,2);
  }
  EV_GetGunPosition(args,&local_7c,&local_40);
  VectorMA(&local_7c,-8.0,local_64,&local_7c);
  VectorMA(&local_7c,8.0,local_58,&local_7c);
  VectorMA(&local_7c,16.0,local_4c,&local_7c);
  if (iVar6 == 0) {
    VectorScale(local_4c,600.0,&local_28);
    (*(gEngfuncs.pEfxAPI)->R_Projectile)
              (&local_7c,&local_28,(int)(short)iVar3,1,idx,
               (_func_void_tempent_s_ptr_pmtrace_s_ptr *)0x0);
    (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_40,1,"weapons/flmfire2.wav",0.9,0.8,0,100);
    return;
  }
                    /* Unresolved local var: float flHeight@[???]
                       Unresolved local var: Vector midUp@[???]
                       Unresolved local var: float diff@[???] */
  VectorMA(&local_7c,128.0,local_4c,&local_70);
  local_90 = local_74;
  local_28 = local_7c;
  local_24 = local_78;
  local_20 = local_74;
  iVar6 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
  fVar1 = local_90;
  if (iVar6 == -3) {
    local_8c = local_90 + 256.0;
    local_20 = local_8c;
    iVar6 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
    fVar1 = local_8c;
    if (iVar6 != -3) {
      fVar2 = local_8c - local_90;
      while (fVar1 = local_20, 1.0 < fVar2) {
        local_20 = fVar2 * 0.5 + local_90;
        iVar6 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
        if (iVar6 == -3) {
          local_90 = local_20;
        }
        else {
          local_8c = local_20;
        }
        fVar2 = local_8c - local_90;
      }
    }
  }
  local_90 = local_68;
  fVar1 = fVar1 - local_74;
  if (fVar1 < 8.0) {
                    /* Unresolved local var: Vector midUp@[???]
                       Unresolved local var: float diff@[???] */
    local_28 = local_70;
    local_24 = local_6c;
    local_20 = local_68;
    iVar6 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
    fVar1 = local_90;
    if (iVar6 == -3) {
      local_8c = local_90 + 256.0;
      local_20 = local_8c;
      iVar6 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
      fVar1 = local_8c;
      if (iVar6 != -3) {
        fVar2 = local_8c - local_90;
        while (fVar1 = local_20, 1.0 < fVar2) {
          local_20 = fVar2 * 0.5 + local_90;
          iVar6 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
          if (iVar6 == -3) {
            local_90 = local_20;
          }
          else {
            local_8c = local_20;
          }
          fVar2 = local_8c - local_90;
        }
      }
    }
    if (fVar1 - local_68 < 8.0) {
      return;
    }
    fVar1 = (local_68 + (fVar1 - local_68)) - local_74;
  }
  (*(gEngfuncs.pEfxAPI)->R_BubbleTrail)(&local_7c,&local_70,fVar1,iVar4,4,8.0);
  return;
}


// EV_TFC_Knife  @ 0004c080  (line 1630)

void EV_TFC_Knife(event_args_t *args)

{
  return;
}


// EV_TFC_Tranquilizer  @ 0004c090  (line 1636)

void EV_TFC_Tranquilizer(event_args_t *args)

{
  int idx;
  int iVar1;
  qboolean qVar2;
  float local_70 [3];
  float local_64 [3];
  float local_58 [3];
  float local_4c [3];
  float local_40 [3];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: Vector vecVelocity@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_34 = args->origin[0];
  local_30 = args->origin[1];
  local_2c = args->origin[2];
  local_28 = args->angles[0];
  local_24 = args->angles[1];
  local_20 = args->angles[2];
  idx = args->entindex;
  (*gEngfuncs.pfnAngleVectors)(&local_28,local_4c,local_58,local_64);
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/nail.mdl");
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    EV_MuzzleFlash();
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(3,1);
  }
  EV_GetGunPosition(args,local_70,&local_34);
  VectorMA(local_70,-4.0,local_64,local_70);
  VectorMA(local_70,2.0,local_58,local_70);
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_34,1,"weapons/dartgun.wav",0.9,0.8,0,100);
  VectorScale(local_4c,1500.0,local_40);
  (*(gEngfuncs.pEfxAPI)->R_Projectile)
            (local_70,local_40,(int)(short)iVar1,6,idx,EV_TFC_TranqNailTouch);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    V_PunchAxis(0,-2.0);
  }
  return;
}


// EV_TFC_RailDie  @ 00049730  (line 1679)

void EV_TFC_RailDie(particle_s *particle)

{
  byte bVar1;
  physent_s_conflict *ppVar2;
  int iVar3;
  qboolean qVar4;
  int32 iVar5;
  int in_GS_OFFSET;
  longdouble extraout_ST0;
  vec_t local_b4;
  vec_t local_b0;
  vec_t local_ac;
  vec_t local_a8;
  vec_t local_a4;
  vec_t local_a0;
  float local_9c [3];
  float local_90 [3];
  pmtrace_t local_84;
  char local_40 [32];
  int local_20;
  
                    /* Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector back@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: int context@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (particle == (particle_s *)0x0) goto LAB_00049918;
                    /* Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector back@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: int context@[???] */
  local_a8 = (particle->vel).x;
  local_a4 = (particle->vel).y;
  local_a0 = (particle->vel).z;
  bVar1 = particle->context;
  VectorNormalize(&local_a8);
  local_b4 = local_a8;
  local_b0 = local_a4;
  local_ac = local_a0;
  VectorInverse(&local_b4);
  VectorMA((float *)particle,128.0,&local_b4,local_9c);
  VectorMA(local_9c,256.0,&local_a8,local_90);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(bVar1 - 1);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_9c,local_90,2,-1,&local_84);
  if (local_84.ent != -1) {
                    /* Unresolved local var: physent_t * pe@[???] */
    ppVar2 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(local_84.ent);
    iVar3 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_84);
    qVar4 = EV_IsPlayer(iVar3);
    if (qVar4 != 0) {
      iVar3 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_84);
      iVar3 = EV_TFC_IsAlly(iVar3,(uint)bVar1);
      if (iVar3 == 0) {
                    /* Unresolved local var: int drop@[???]
                       Unresolved local var: int spray@[???]
                       Unresolved local var: float size@[???] */
        if (((cl_localblood != (cvar_t *)0x0) && (cl_localblood->value != 0.0)) &&
           ((*gEngfuncs.pfnGetCvarFloat)("violence_hblood"), extraout_ST0 != (longdouble)0)) {
          EV_TFC_BloodDrips(&local_84.endpos.x,0xf7,0x19);
        }
        goto LAB_00049910;
      }
    }
    if ((ppVar2 != (physent_s_conflict *)0x0) && ((ppVar2->solid == 4 || (ppVar2->movetype == 0xd)))
       ) {
                    /* Unresolved local var: char[32] decalname@[???]
                       Unresolved local var: int idx@[???] */
      local_40[0] = '\0';
      iVar5 = (*gEngfuncs.pfnRandomLong)(0,4);
      __sprintf_chk(local_40,1,0x20,"{shot%i",iVar5 + 1);
                    /* Unresolved local var: int iRand@[???]
                       Unresolved local var: physent_t * pe@[???] */
      if ((local_40[0] != '\0') && (local_84.fraction != 1.0)) {
        EV_TFC_GunshotDecalTrace(&local_84,local_40);
      }
    }
  }
LAB_00049910:
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
LAB_00049918:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// EV_TFC_Railgun  @ 0004c280  (line 1736)

void EV_TFC_Railgun(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  float fVar2;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0 [3];
  float local_b4 [3];
  float local_a8 [3];
  float local_9c [3];
  float local_90 [3];
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  pmtrace_s local_60;
  
                    /* Unresolved local var: Vector ShellOrigin@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector tracerVelocity@[???]
                       Unresolved local var: int shell@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: float flSpread@[???]
                       Unresolved local var: float flTracerDist@[???]
                       Unresolved local var: Vector delta@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_78 = args->origin[0];
  local_74 = args->origin[1];
  local_70 = args->origin[2];
  local_6c = args->angles[0];
  local_68 = args->angles[1];
  local_64 = args->angles[2];
  idx = args->entindex;
  (*gEngfuncs.pfnAngleVectors)(&local_6c,local_90,local_9c,local_a8);
  (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/nail.mdl");
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    EV_MuzzleFlash();
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(1,2);
  }
  EV_GetGunPosition(args,&local_d8,&local_78);
  VectorMA(&local_d8,-4.0,local_a8,&local_d8);
  VectorMA(&local_d8,2.0,local_9c,&local_d8);
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_78,1,"weapons/railgun.wav",0.9,0.8,0,100);
  local_cc = local_d8;
  local_c8 = local_d4;
  local_c4 = local_d0;
  VectorMA(&local_cc,4096.0,local_90,local_c0);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(idx + -1);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_cc,local_c0,2,-1,&local_60);
  local_84 = local_60.endpos.x - local_cc;
  local_80 = local_60.endpos.y - local_c8;
  local_7c = local_60.endpos.z - local_c4;
  fVar2 = Length(&local_84);
  VectorScale(local_90,1500.0,local_b4);
  (*(gEngfuncs.pEfxAPI)->R_UserTracerParticle)
            (&local_d8,local_b4,fVar2 / 1500.0,2,1.0,(uchar)idx,EV_TFC_RailDie);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    V_PunchAxis(0,-2.0);
  }
  return;
}


// EV_TFC_LookupDoorSound  @ 0004c570  (line 1801)

char * EV_TFC_LookupDoorSound(int type,int index)

{
  uint uVar1;
  uint uVar2;
  
                    /* Unresolved local var: int idx@[???] */
  builtin_strncpy(EV_TFC_LookupDoorSound::sound,"common/null.wav",0x10);
  if (type == 0) {
    switch((uint)index >> 8 & 0xff) {
    default:
switchD_0004c5b0_caseD_0:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"common/null.",0xc);
      builtin_strncpy(EV_TFC_LookupDoorSound::sound + 0xc,"wav",4);
      return EV_TFC_LookupDoorSound::sound;
    case 1:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove1.wav",0x14);
      break;
    case 2:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove2.wav",0x14);
      break;
    case 3:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove3.wav",0x14);
      break;
    case 4:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove4.wav",0x14);
      break;
    case 5:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove5.wav",0x14);
      break;
    case 6:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove6.wav",0x14);
      break;
    case 7:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove7.wav",0x14);
      break;
    case 8:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove8.wav",0x14);
      break;
    case 9:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove9.wav",0x14);
      break;
    case 10:
      uVar1 = 0;
      do {
        uVar2 = uVar1;
        *(undefined4 *)(EV_TFC_LookupDoorSound::sound + uVar2) =
             *(undefined4 *)("doors/doormove10.wav" + uVar2);
        uVar1 = uVar2 + 4;
      } while (uVar2 + 4 < 0x14);
      EV_TFC_LookupDoorSound::sound[uVar2 + 4] = "doors/doormove10.wav"[uVar2 + 4];
    }
  }
  else if (type == 1) {
    switch(index & 0xff) {
    default:
      goto switchD_0004c5b0_caseD_0;
    case 1:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop1.wav",0x14);
      break;
    case 2:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop2.wav",0x14);
      break;
    case 3:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop3.wav",0x14);
      break;
    case 4:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop4.wav",0x14);
      break;
    case 5:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop5.wav",0x14);
      break;
    case 6:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop6.wav",0x14);
      break;
    case 7:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop7.wav",0x14);
      break;
    case 8:
      builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop8.wav",0x14);
    }
  }
  return EV_TFC_LookupDoorSound::sound;
}


// EV_TFC_DoorGoDown  @ 0004d170  (line 1904)

void EV_TFC_DoorGoDown(event_args_t *args)

{
  _func_void_int_int_char_ptr *p_Var1;
  uint uVar2;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var3;
  uint uVar4;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: int soundindex@[???] */
                    /* Unresolved local var: int idx@[???] */
  p_Var1 = (gEngfuncs.pEventAPI)->EV_StopSound;
  builtin_strncpy(EV_TFC_LookupDoorSound::sound,"common/null.wav",0x10);
  switch((uint)args->iparam1 >> 8 & 0xff) {
  default:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"common/null.wav",0x10);
    (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
                    /* Unresolved local var: int idx@[???] */
    p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"common/null.wav",0x10);
    break;
  case 1:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove1.wav",0x14);
    (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
    p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove1.wav",0x14);
    break;
  case 2:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove2.wav",0x14);
    (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
    p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove2.wav",0x14);
    break;
  case 3:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove3.wav",0x14);
    (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
    p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove3.wav",0x14);
    break;
  case 4:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove4.wav",0x14);
    (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
    p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove4.wav",0x14);
    break;
  case 5:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove5.wav",0x14);
    (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
    p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove5.wav",0x14);
    break;
  case 6:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove6.wav",0x14);
    (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
    p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove6.wav",0x14);
    break;
  case 7:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove7.wav",0x14);
    (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
    p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove7.wav",0x14);
    break;
  case 8:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove8.wav",0x14);
    (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
    p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove8.wav",0x14);
    break;
  case 9:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove9.wav",0x14);
    (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
    p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove9.wav",0x14);
    break;
  case 10:
    uVar2 = 0;
    do {
      uVar4 = uVar2;
      *(undefined4 *)(EV_TFC_LookupDoorSound::sound + uVar4) =
           *(undefined4 *)("doors/doormove10.wav" + uVar4);
      uVar2 = uVar4 + 4;
    } while (uVar4 + 4 < 0x14);
    EV_TFC_LookupDoorSound::sound[uVar4 + 4] = "doors/doormove10.wav"[uVar4 + 4];
    (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
    p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    uVar2 = 0;
    do {
      uVar4 = uVar2;
      *(undefined4 *)(EV_TFC_LookupDoorSound::sound + uVar4) =
           *(undefined4 *)("doors/doormove10.wav" + uVar4);
      uVar2 = uVar4 + 4;
    } while (uVar4 + 4 < 0x14);
    EV_TFC_LookupDoorSound::sound[uVar4 + 4] = "doors/doormove10.wav"[uVar4 + 4];
  }
  (*p_Var3)(-1,args->origin,6,EV_TFC_LookupDoorSound::sound,1.0,0.8,0,100);
  return;
}


// EV_TFC_DoorHitBottom  @ 0004ddf0  (line 1922)

void EV_TFC_DoorHitBottom(event_args_t *args)

{
  _func_void_int_int_char_ptr *p_Var1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: int soundindex@[???] */
  p_Var1 = (gEngfuncs.pEventAPI)->EV_StopSound;
                    /* Unresolved local var: int idx@[???] */
  uVar2 = args->iparam1;
  builtin_strncpy(EV_TFC_LookupDoorSound::sound,"common/null.wav",0x10);
  switch(uVar2 >> 8 & 0xff) {
  default:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"common/null.wav",0x10);
    break;
  case 1:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove1.wav",0x14);
    break;
  case 2:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove2.wav",0x14);
    break;
  case 3:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove3.wav",0x14);
    break;
  case 4:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove4.wav",0x14);
    break;
  case 5:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove5.wav",0x14);
    break;
  case 6:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove6.wav",0x14);
    break;
  case 7:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove7.wav",0x14);
    break;
  case 8:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove8.wav",0x14);
    break;
  case 9:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doormove9.wav",0x14);
    break;
  case 10:
    uVar3 = 0;
    do {
      uVar4 = uVar3;
      *(undefined4 *)(EV_TFC_LookupDoorSound::sound + uVar4) =
           *(undefined4 *)("doors/doormove10.wav" + uVar4);
      uVar3 = uVar4 + 4;
    } while (uVar4 + 4 < 0x14);
    EV_TFC_LookupDoorSound::sound[uVar4 + 4] = "doors/doormove10.wav"[uVar4 + 4];
  }
                    /* Unresolved local var: int idx@[???] */
  (*p_Var1)(-1,6,EV_TFC_LookupDoorSound::sound);
  switch(uVar2 & 0xff) {
  default:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"common/null.wav",0x10);
    break;
  case 1:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop1.wav",0x14);
    break;
  case 2:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop2.wav",0x14);
    break;
  case 3:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop3.wav",0x14);
    break;
  case 4:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop4.wav",0x14);
    break;
  case 5:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop5.wav",0x14);
    break;
  case 6:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop6.wav",0x14);
    break;
  case 7:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop7.wav",0x14);
    break;
  case 8:
    builtin_strncpy(EV_TFC_LookupDoorSound::sound,"doors/doorstop8.wav",0x14);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)
            (-1,args->origin,6,EV_TFC_LookupDoorSound::sound,1.0,0.8,0,100);
  return;
}


// EV_TFC_Explode  @ 0004e390  (line 1932)

void EV_TFC_Explode(float *org,int dmg,float fExplosionScale,qboolean bDontSpark,pmtrace_t *pTrace,
                   int bitsDamageType)

{
  int iVar1;
  int iVar2;
  int32 iVar3;
  bool bVar4;
  longdouble lVar5;
  char *pcVar6;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float flRndSound@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: int iContents@[???]
                       Unresolved local var: int fireball@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int explosion_outside@[???] */
  local_28 = *org;
  local_24 = org[1];
  local_20 = org[2];
  if (pTrace->fraction != 1.0) {
    iVar1 = dmg;
    if (0x17 < dmg) {
      iVar1 = dmg + -0x18;
    }
    VectorMA(&(pTrace->endpos).x,(float)iVar1 * 0.6,(float *)&pTrace->plane,&local_28);
  }
  iVar1 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
  bVar4 = false;
  if (iVar1 == -2) {
    iVar1 = (*gEngfuncs.PM_PointContents)(org,(int *)0x0);
    bVar4 = iVar1 == -2;
  }
  if (fExplosionScale == 0.0) {
    fExplosionScale = (float)(dmg + -0x32) * 0.6;
  }
  iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/explode01.spr");
  (*(gEngfuncs.pEfxAPI)->R_Explosion)(&local_28,iVar2,fExplosionScale * 0.1,15.0,3);
  if (!bVar4) {
    lVar5 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.0,1.0);
    if ((longdouble)0.5 <= lVar5) {
      EV_TFC_DecalTrace(pTrace,"{scorch2");
    }
    else {
      EV_TFC_DecalTrace(pTrace,"{scorch1");
    }
  }
  (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,2);
  if (iVar3 == 1) {
    pcVar6 = "weapons/debris2.wav";
  }
  else if (iVar3 == 2) {
    pcVar6 = "weapons/debris3.wav";
  }
  else {
    if (iVar3 != 0) goto LAB_0004e49e;
    pcVar6 = "weapons/debris1.wav";
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&local_28,2,pcVar6,0.55,0.8,0,100);
LAB_0004e49e:
                    /* Unresolved local var: int sparkCount@[DW_OP_reg7(EDI)] */
  if (((iVar1 != -3) && (bDontSpark == 0)) && (iVar3 = (*gEngfuncs.pfnRandomLong)(0,3), 0 < iVar3))
  {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      (*(gEngfuncs.pEfxAPI)->R_SparkShower)(&local_28);
    } while (iVar3 != iVar1);
  }
  return;
}


// EV_TFC_Explosion  @ 0004e690  (line 2013)

void EV_TFC_Explosion(event_args_t *args)

{
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_s local_50;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
  local_5c = args->origin[0];
  local_58 = args->origin[1];
  local_54 = args->origin[2];
  local_68 = local_5c + 0.0;
  local_64 = local_58 + 0.0;
  local_60 = local_54 + 8.0;
  local_74 = local_68 + 0.0;
  local_70 = local_64 + 0.0;
  local_6c = local_60 - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_68,&local_74,2,-1,&local_50);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_5c,0x78,0.0,1,&local_50,0x4000040);
  return;
}


// EV_TFC_Grenade  @ 0004e780  (line 2039)

void EV_TFC_Grenade(event_args_t *args)

{
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_s local_50;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
  local_5c = args->origin[0];
  local_58 = args->origin[1];
  local_54 = args->origin[2];
  local_68 = local_5c + 0.0;
  local_64 = local_58 + 0.0;
  local_60 = local_54 + 8.0;
  local_74 = local_68 + 0.0;
  local_70 = local_64 + 0.0;
  local_6c = local_60 - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_68,&local_74,2,-1,&local_50);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_5c,0x78,0.0,1,&local_50,0x40);
  return;
}


// EV_TFC_EngineerGrenade  @ 0004e870  (line 2061)

void EV_TFC_EngineerGrenade(int param_1)

{
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_s local_50;
  
  local_74 = *(float *)(param_1 + 8);
  local_70 = *(float *)(param_1 + 0xc);
  local_6c = *(float *)(param_1 + 0x10);
  local_68 = local_74 + 0.0;
  local_64 = local_70 + 0.0;
  local_60 = local_6c + 8.0;
  local_5c = local_68 + 0.0;
  local_58 = local_64 + 0.0;
  local_54 = local_60 - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_68,&local_5c,2,-1,&local_50);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_74,0xb4,78.0,1,&local_50,0x40);
  return;
}


// EV_TFC_Concussion  @ 0004e960  (line 2089)

void EV_TFC_Concussion(event_args_t *args)

{
  int iVar1;
  int32 iVar2;
  char *pcVar3;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_s local_50;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int blast@[???]
                       Unresolved local var: Vector origin@[???] */
  local_5c = args->origin[0];
  local_58 = args->origin[1];
  local_54 = args->origin[2];
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/shockwave.spr");
  local_68 = local_5c + 0.0;
  local_64 = local_58 + 0.0;
  local_60 = local_54 + 8.0;
  local_74 = local_68 + 0.0;
  local_70 = local_64 + 0.0;
  local_6c = local_60 - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_68,&local_74,2,-1,&local_50);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  iVar2 = (*gEngfuncs.pfnRandomLong)(0,2);
  if (iVar2 == 1) {
    pcVar3 = "weapons/concgren_blast2.wav";
  }
  else if (iVar2 == 2) {
    pcVar3 = "weapons/concgren_blast3.wav";
  }
  else {
    if (iVar2 != 0) goto LAB_0004ea60;
    pcVar3 = "weapons/concgren_blast1.wav";
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&local_5c,2,pcVar3,1.0,0.8,0,100);
LAB_0004ea60:
  local_68 = local_5c;
  local_64 = local_58;
  local_60 = local_54 + 16.0;
  local_74 = local_5c;
  local_70 = local_58;
  local_6c = local_60 + 600.0;
  (*(gEngfuncs.pEfxAPI)->R_BeamCirclePoints)
            (0x15,&local_68,&local_74,iVar1,0.2,70.0,0.0,1.0,0.0,0,0.0,1.0,1.0,1.0);
  return;
}


// EV_TFC_NormalGrenade  @ 0004ebc0  (line 2139)

void EV_TFC_NormalGrenade(event_args_t *args)

{
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_s local_50;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
  local_5c = args->origin[0];
  local_58 = args->origin[1];
  local_54 = args->origin[2];
  local_68 = local_5c + 0.0;
  local_64 = local_58 + 0.0;
  local_60 = local_54 + 8.0;
  local_74 = local_68 + 0.0;
  local_70 = local_64 + 0.0;
  local_6c = local_60 - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_68,&local_74,2,-1,&local_50);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_5c,0xb4,0.0,1,&local_50,0x40);
  return;
}


// EV_TFC_MirvGrenadeMain  @ 0004ecb0  (line 2161)

void EV_TFC_MirvGrenadeMain(int param_1)

{
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_s local_50;
  
  local_5c = *(float *)(param_1 + 8);
  local_58 = *(float *)(param_1 + 0xc);
  local_54 = *(float *)(param_1 + 0x10);
  local_68 = local_5c + 0.0;
  local_64 = local_58 + 0.0;
  local_60 = local_54 + 8.0;
  local_74 = local_68 + 0.0;
  local_70 = local_64 + 0.0;
  local_6c = local_60 - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_68,&local_74,2,-1,&local_50);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_5c,0xb4,0.0,1,&local_50,0x40);
  return;
}


// EV_TFC_MirvGrenade  @ 0004eda0  (line 2170)

void EV_TFC_MirvGrenade(event_args_t *args)

{
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_s local_50;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
  local_5c = args->origin[0];
  local_58 = args->origin[1];
  local_54 = args->origin[2];
  local_68 = local_5c + 0.0;
  local_64 = local_58 + 0.0;
  local_60 = local_54 + 8.0;
  local_74 = local_68 + 0.0;
  local_70 = local_64 + 0.0;
  local_6c = local_60 - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_68,&local_74,2,-1,&local_50);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_5c,0xb4,0.0,1,&local_50,0x40);
  return;
}


// EV_TFC_ExplodeFire  @ 0004ee90  (line 2176)

void EV_TFC_ExplodeFire(float *org,int dmg,qboolean bDontSpark,pmtrace_t *pTrace,int bitsDamageType)

{
  int iVar1;
  int iVar2;
  int32 iVar3;
  longdouble lVar4;
  char *pcVar5;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float flRndSound@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: int iContents@[???]
                       Unresolved local var: int fireball@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float fExplosionScale@[???] */
  local_28 = *org;
  local_24 = org[1];
  local_20 = org[2];
  if (pTrace->fraction != 1.0) {
    if (0x17 < dmg) {
      dmg = dmg + -0x18;
    }
    VectorMA(&(pTrace->endpos).x,(float)dmg * 0.6,(float *)&pTrace->plane,&local_28);
  }
  iVar1 = (*gEngfuncs.PM_PointContents)(&local_28,(int *)0x0);
  if ((iVar1 == -2) && (iVar1 = (*gEngfuncs.PM_PointContents)(org,(int *)0x0), iVar1 == -2)) {
    return;
  }
  iVar2 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/explode01.spr");
  (*(gEngfuncs.pEfxAPI)->R_Explosion)(&local_28,iVar2,3.0,15.0,3);
  lVar4 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.0,1.0);
  if (lVar4 < (longdouble)0.5) {
    EV_TFC_DecalTrace(pTrace,"{scorch1");
  }
  else {
    EV_TFC_DecalTrace(pTrace,"{scorch2");
  }
  (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
  iVar3 = (*gEngfuncs.pfnRandomLong)(0,2);
  if (iVar3 == 1) {
    pcVar5 = "weapons/debris2.wav";
  }
  else if (iVar3 == 2) {
    pcVar5 = "weapons/debris3.wav";
  }
  else {
    if (iVar3 != 0) goto LAB_0004efa8;
    pcVar5 = "weapons/debris1.wav";
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&local_28,2,pcVar5,0.55,0.8,0,100);
LAB_0004efa8:
                    /* Unresolved local var: int sparkCount@[DW_OP_reg7(EDI)] */
  if (((iVar1 != -3) && (bDontSpark == 0)) && (iVar3 = (*gEngfuncs.pfnRandomLong)(0,3), 0 < iVar3))
  {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      (*(gEngfuncs.pEfxAPI)->R_SparkShower)(&local_28);
    } while (iVar3 != iVar1);
  }
  return;
}


// EV_TFC_NapalmFire  @ 0004f140  (line 2254)

void EV_TFC_NapalmFire(event_args_t *args)

{
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_t local_50;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
  local_5c = args->origin[0];
  local_58 = args->origin[1];
  local_54 = args->origin[2];
  local_68 = local_5c + 0.0;
  local_64 = local_58 + 0.0;
  local_60 = local_54 + 8.0;
  local_74 = local_68 + 0.0;
  local_70 = local_64 + 0.0;
  local_6c = local_60 - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_68,&local_74,2,-1,&local_50);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_ExplodeFire(&local_5c,0x14,1,&local_50,0x4000040);
  return;
}


// EV_TFC_NapalmBurn  @ 0004f220  (line 2278)

void EV_TFC_NapalmBurn(event_args_t *args)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int firemodel@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/playerflame.spr");
  (*(gEngfuncs.pEfxAPI)->R_FireField)(&local_18,100,iVar1,0xc,0x12,0.8);
  return;
}


// EV_TFC_Gas  @ 0004f2a0  (line 2290)

void EV_TFC_Gas(event_args_t *args)

{
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  (*(gEngfuncs.pEfxAPI)->R_ParticleBurst)(&local_18,0xf0,0xc3,2.0);
  return;
}


// EV_TFC_EMP  @ 0004f300  (line 2298)

void EV_TFC_EMP(event_args_t *args)

{
  int iVar1;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_s local_50;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int blast@[???]
                       Unresolved local var: Vector origin@[???] */
  local_5c = args->origin[0];
  local_58 = args->origin[1];
  local_54 = args->origin[2];
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/shockwave.spr");
  local_68 = local_5c + 0.0;
  local_64 = local_58 + 0.0;
  local_60 = local_54 + 8.0;
  local_74 = local_68 + 0.0;
  local_70 = local_64 + 0.0;
  local_6c = local_60 - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_68,&local_74,2,-1,&local_50);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,&local_5c,2,"weapons/emp_1.wav",1.0,0.8,0,100);
  local_68 = local_5c;
  local_64 = local_58;
  local_60 = local_54 + 16.0;
  local_74 = local_5c;
  local_70 = local_58;
  local_6c = local_60 + 600.0;
  (*(gEngfuncs.pEfxAPI)->R_BeamCirclePoints)
            (0x15,&local_68,&local_74,iVar1,0.2,70.0,0.0,1.0,0.0,0,0.0,1.0,1.0,0.0);
  return;
}


// EV_TFC_NailgrenadeNail  @ 0004f4d0  (line 2336)

void EV_TFC_NailgrenadeNail(event_args_t *args)

{
  float fVar1;
  uint uVar2;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var3;
  int iVar4;
  int32 iVar5;
  int iVar6;
  char *pcVar7;
  int local_64;
  float local_58 [3];
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40 [3];
  float local_34 [3];
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector velocity@[???]
                       Unresolved local var: float flYaw@[???]
                       Unresolved local var: int shell@[DW_OP_reg0(EAX)]
                       Unresolved local var: int yaw@[???]
                       Unresolved local var: int owner@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float j@[???]
                       Unresolved local var: Vector org@[???] */
  local_4c = 0.0;
  local_44 = 0;
  local_28 = args->origin[0];
  local_24 = args->origin[1];
  local_20 = args->origin[2];
  fVar1 = args->fparam1;
  uVar2 = args->iparam1;
  local_48 = (float)(uVar2 & 0x7ff) * 0.25;
  iVar4 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("models/nail.mdl");
  local_64 = 4;
  do {
    local_48 = anglemod(fVar1 + local_48);
    (*gEngfuncs.pfnAngleVectors)(&local_4c,local_40,(float *)0x0,(float *)0x0);
    VectorMA(&local_28,12.0,local_40,local_58);
    VectorScale(local_40,1000.0,local_34);
    (*(gEngfuncs.pEfxAPI)->R_Projectile)
              (local_58,local_34,(int)(short)iVar4,6,(int)uVar2 >> 0xb & 0x1f,EV_TFC_NailTouch);
    iVar5 = (*gEngfuncs.pfnRandomLong)(0,5);
    if (iVar5 == 0) {
      iVar5 = (*gEngfuncs.pfnRandomLong)(0,1);
      p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
      if (iVar5 == 0) {
        iVar6 = (*gEngfuncs.pfnRandomLong)(0,0xf);
        pcVar7 = "weapons/airgun_1.wav";
      }
      else {
        iVar6 = (*gEngfuncs.pfnRandomLong)(0,0xf);
        pcVar7 = "weapons/spike2.wav";
      }
      (*p_Var3)(-1,local_58,1,pcVar7,1.0,0.8,0,iVar6 + 0x5e);
    }
    local_64 = local_64 + -1;
  } while (local_64 != 0);
  return;
}


// EV_TFC_NailGrenade  @ 0004f6e0  (line 2391)

void EV_TFC_NailGrenade(event_args_t *args)

{
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_s local_50;
  
                    /* Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector upV@[???]
                       Unresolved local var: Vector downV@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector origin@[???] */
  local_5c = args->origin[0];
  local_58 = args->origin[1];
  local_54 = args->origin[2];
  local_68 = local_5c + 0.0;
  local_64 = local_58 + 0.0;
  local_60 = local_54 + 8.0;
  local_74 = local_68 + 0.0;
  local_70 = local_64 + 0.0;
  local_6c = local_60 - 40.0;
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_68,&local_74,2,-1,&local_50);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  EV_TFC_Explode(&local_5c,0xb4,78.0,1,&local_50,0x40);
  return;
}


// EV_TFC_FireRPG  @ 0004f7d0  (line 2416)

void EV_TFC_FireRPG(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  idx = args->entindex;
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(2,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,1,"weapons/rocketfire1.wav",0.9,0.8,0,100);
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,3,"weapons/glauncher.wav",0.7,0.8,0,100);
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    V_PunchAxis(0,-5.0);
  }
  return;
}


// EV_TFC_FireIC  @ 0004f8e0  (line 2442)

void EV_TFC_FireIC(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  idx = args->entindex;
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(3,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,1,"weapons/sgun1.wav",0.9,0.8,0,100);
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    V_PunchAxis(0,-5.0);
  }
  return;
}


// EV_TFC_SniperHit  @ 0004f9b0  (line 2466)

void EV_TFC_SniperHit(event_args_s *args)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  int in_GS_OFFSET;
  float local_11c;
  float local_118;
  float local_114;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: int hit@[???]
                       Unresolved local var: int gib@[???]
                       Unresolved local var: float vol@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: char[256] sz@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_11c = args->origin[0];
  local_118 = args->origin[1];
  local_114 = args->origin[2];
  iVar1 = args->entindex;
  fVar2 = (float)args->iparam1 / 100.0;
  if (args->bparam2 == 0) {
    if (args->bparam1 == 0) {
      builtin_strncpy(local_110,"weapons/ric3.wav",0x11);
    }
    else {
      uVar3 = 0;
      do {
        *(undefined4 *)(local_110 + uVar3) = *(undefined4 *)("weapons/bullet_hit2.wav" + uVar3);
        uVar3 = uVar3 + 4;
      } while (uVar3 < 0x18);
    }
  }
  else {
    uVar3 = 0;
    do {
      uVar4 = uVar3;
      *(undefined4 *)(local_110 + uVar4) = *(undefined4 *)("common/bodysplat.wav" + uVar4);
      uVar3 = uVar4 + 4;
    } while (uVar4 + 4 < 0x14);
    fVar2 = 1.0;
    local_110[uVar4 + 4] = "common/bodysplat.wav"[uVar4 + 4];
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(iVar1,&local_11c,6,local_110,fVar2,0.8,0,100);
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// EV_FireTFCSniper  @ 0004faf0  (line 2501)

void EV_FireTFCSniper(event_args_t *args)

{
  int iVar1;
  int idx;
  qboolean qVar2;
  int idx_00;
  float *bitsDamageType;
  float local_c0 [3];
  float local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  float local_a8 [3];
  float local_9c [3];
  float local_90 [3];
  float local_84;
  undefined4 local_80;
  undefined4 local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  pmtrace_s local_60;
  
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int iDamage@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  iVar1 = args->iparam1;
  local_78 = args->origin[0];
  local_74 = args->origin[1];
  local_70 = args->origin[2];
  local_6c = args->angles[0];
  local_68 = args->angles[1];
  local_64 = args->angles[2];
  idx = args->entindex;
  (*gEngfuncs.pfnAngleVectors)(&local_6c,&local_84,local_90,local_9c);
  qVar2 = EV_IsLocal(idx);
  if (qVar2 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(2,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_78,1,"ambience/rifle1.wav",0.9,0.8,0,100);
  EV_GetGunPosition(args,local_c0,&local_78);
  local_b4 = local_84;
  local_b0 = local_80;
  local_ac = local_7c;
  VectorMA(local_c0,2.0,local_9c,local_c0);
  VectorMA(local_c0,8192.0,&local_b4,local_a8);
  (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(idx + -1);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  bitsDamageType = local_a8;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_c0,local_a8,2,-1,&local_60);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  if (local_60.fraction != 1.0) {
    idx_00 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_60);
    qVar2 = EV_IsPlayer(idx_00);
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
    if ((qVar2 != 0) && ((cl_localblood == (cvar_t *)0x0 || (cl_localblood->value != 0.0)))) {
      EV_TFC_TraceAttack(idx,(float)&local_b4,(float *)&local_60,(pmtrace_t *)(float)iVar1,
                         (int)bitsDamageType);
    }
    EV_TFC_PlayTextureSound(idx,&local_60,local_c0,local_a8,3);
    EV_TFC_DecalGunshot(&local_60,3);
    return;
  }
  return;
}


// EV_TFC_GrenadeLauncher  @ 0004fd90  (line 2559)

void EV_TFC_GrenadeLauncher(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  idx = args->entindex;
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(2,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,3,"weapons/glauncher.wav",0.7,0.8,0,100);
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    V_PunchAxis(0,-2.0);
  }
  return;
}


// EV_TFC_PipeLauncher  @ 0004fe60  (line 2583)

void EV_TFC_PipeLauncher(event_args_t *args)

{
  int idx;
  qboolean qVar1;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  idx = args->entindex;
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(3,2);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_18,3,"weapons/glauncher.wav",0.7,0.8,0,100);
  qVar1 = EV_IsLocal(idx);
  if (qVar1 != 0) {
    V_PunchAxis(0,-2.0);
  }
  return;
}


// EV_TFC_PlayKnifeAnim  @ 0004ff30  (line 2612)

int EV_TFC_PlayKnifeAnim(int iAnimType)

{
  return (-(uint)((uint)iAnimType < 2) & 3) - 1;
}


// EV_TFC_PlayMedkitAnim  @ 0004ff40  (line 2625)

int EV_TFC_PlayMedkitAnim(int iAnimType)

{
  if (iAnimType != 0) {
    return (uint)(iAnimType == 1) * 4 + -1;
  }
  return 2;
}


// EV_TFC_PlaySpannerAnim  @ 0004ff70  (line 2643)

int EV_TFC_PlaySpannerAnim(int iAnimType)

{
  if (iAnimType != 0) {
    return (uint)(iAnimType == 1) * 4 + -1;
  }
  return 1;
}


// EV_TFC_PlayCrowbarAnim  @ 0004ffa0  (line 2660)

int EV_TFC_PlayCrowbarAnim(int iAnimType)

{
  int iVar1;
  
  iVar1 = EV_TFC_PlayCrowbarAnim::m_iSwing;
  if (iAnimType == 0) {
    EV_TFC_PlayCrowbarAnim::m_iSwing = EV_TFC_PlayCrowbarAnim::m_iSwing + 1;
    if (iVar1 % 3 == 1) {
      return 5;
    }
    if (iVar1 % 3 != 2) {
      return (-(uint)(iVar1 == (iVar1 / 3) * 3) & 5) - 1;
    }
    return 7;
  }
  if (iAnimType != 1) {
    return -1;
  }
  EV_TFC_PlayCrowbarAnim::m_iSwing = EV_TFC_PlayCrowbarAnim::m_iSwing + 1;
  if (iVar1 % 2 != 0) {
    return (uint)(iVar1 % 2 == 1) * 5 + 3;
  }
  return 6;
}


// EV_TFC_PlayAxeAnim  @ 00050060  (line 2697)

void EV_TFC_PlayAxeAnim(int idx,int classid,int iAnimType)

{
  int iVar1;
  qboolean qVar2;
  int iVar3;
  
                    /* Unresolved local var: int anim@[???] */
  qVar2 = EV_IsLocal(idx);
  if (qVar2 == 0) {
    return;
  }
                    /* Unresolved local var: int anim@[???] */
  if (classid == 1) {
    if (iAnimType == 0) {
      iVar3 = 1;
      goto LAB_0005010c;
    }
LAB_00050104:
    iVar3 = 3;
    if (iAnimType != 1) {
      return;
    }
  }
  else {
    if (classid < 2) {
      if (classid != 0) {
        return;
      }
      if (1 < (uint)iAnimType) {
        return;
      }
    }
    else {
      if (classid != 2) {
        if (classid != 3) {
          return;
        }
        if (iAnimType == 0) {
          iVar1 = EV_TFC_PlayCrowbarAnim::m_iSwing + 1;
          if (EV_TFC_PlayCrowbarAnim::m_iSwing % 3 == 1) {
            iVar3 = 5;
            EV_TFC_PlayCrowbarAnim::m_iSwing = iVar1;
          }
          else if (EV_TFC_PlayCrowbarAnim::m_iSwing % 3 == 2) {
            iVar3 = 7;
            EV_TFC_PlayCrowbarAnim::m_iSwing = iVar1;
          }
          else {
            if (EV_TFC_PlayCrowbarAnim::m_iSwing != (EV_TFC_PlayCrowbarAnim::m_iSwing / 3) * 3) {
              EV_TFC_PlayCrowbarAnim::m_iSwing = iVar1;
              return;
            }
            iVar3 = 4;
            EV_TFC_PlayCrowbarAnim::m_iSwing = iVar1;
          }
        }
        else {
          if (iAnimType != 1) {
            return;
          }
          if (EV_TFC_PlayCrowbarAnim::m_iSwing % 2 == 0) {
            iVar3 = 6;
            EV_TFC_PlayCrowbarAnim::m_iSwing = EV_TFC_PlayCrowbarAnim::m_iSwing + 1;
          }
          else {
            iVar3 = (uint)(EV_TFC_PlayCrowbarAnim::m_iSwing % 2 == 1) * 5 + 3;
            EV_TFC_PlayCrowbarAnim::m_iSwing = EV_TFC_PlayCrowbarAnim::m_iSwing + 1;
          }
        }
        goto LAB_0005010c;
      }
      if (iAnimType != 0) goto LAB_00050104;
    }
    iVar3 = 2;
  }
LAB_0005010c:
  qVar2 = EV_IsLocal(idx);
  if (qVar2 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0005013c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(iVar3,2);
  return;
}


// EV_TFC_PlayAxeSound  @ 000501d0  (line 2729)

void EV_TFC_PlayAxeSound(int idx,int classid,float *origin,int iSoundType,float fSoundData)

{
  int32 iVar1;
  int iVar2;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var3;
  int iVar4;
  char *pcVar5;
  
  if (classid == 2) {
    return;
  }
  if (iSoundType != 1) {
    if (iSoundType == 2) {
      iVar1 = (*gEngfuncs.pfnRandomLong)(0,1);
      if (iVar1 == 0) {
        p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
        iVar2 = (*gEngfuncs.pfnRandomLong)(0,3);
        pcVar5 = "weapons/cbar_hit1.wav";
      }
      else {
        if (iVar1 != 1) {
          return;
        }
        p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
        iVar2 = (*gEngfuncs.pfnRandomLong)(0,3);
        pcVar5 = "weapons/cbar_hit2.wav";
      }
      iVar2 = iVar2 + 0x62;
      iVar4 = 3;
    }
    else {
      if (iSoundType != 0) {
        return;
      }
      p_Var3 = (gEngfuncs.pEventAPI)->EV_PlaySound;
      iVar1 = (*gEngfuncs.pfnRandomLong)(0,0xf);
      fSoundData = 1.0;
      iVar2 = iVar1 + 0x5e;
      pcVar5 = "weapons/cbar_miss1.wav";
      iVar4 = 1;
    }
    (*p_Var3)(idx,origin,iVar4,pcVar5,fSoundData,0.8,0,iVar2);
    return;
  }
  iVar1 = (*gEngfuncs.pfnRandomLong)(0,2);
  if (iVar1 == 1) {
    pcVar5 = "weapons/cbar_hitbod2.wav";
  }
  else if (iVar1 == 2) {
    pcVar5 = "weapons/cbar_hitbod3.wav";
  }
  else {
    if (iVar1 != 0) {
      return;
    }
    pcVar5 = "weapons/cbar_hitbod1.wav";
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,origin,1,pcVar5,1.0,0.8,0,100);
  return;
}


// EV_TFC_AxeHit  @ 00050410  (line 2776)

int EV_TFC_AxeHit(int idx,float *origin,float *forward,float *right,int entity,float *vecDir,
                 pmtrace_t *ptr)

{
  int iVar1;
  int iVar2;
  qboolean qVar3;
  cl_entity_s *pcVar4;
  longdouble extraout_ST0;
  float *bitsDamageType;
  float local_30 [3];
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: cl_entity_t * player@[???] */
  if ((((entity < 1) || (iVar1 = (*gEngfuncs.GetMaxClients)(), iVar1 < entity)) ||
      (pcVar4 = GetEntity(entity + -1), pcVar4 == (cl_entity_s *)0x0)) ||
     ((pcVar4->curstate).playerclass != 8)) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
    if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
      VectorScale(vecDir,-4.0,&local_24);
      local_18 = (ptr->endpos).x - local_24;
      local_14 = (ptr->endpos).y - local_20;
      local_10 = (ptr->endpos).z - local_1c;
      iVar1 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(ptr);
      if ((0 < iVar1) && (iVar2 = (*gEngfuncs.GetMaxClients)(), iVar1 <= iVar2)) {
                    /* Unresolved local var: int blood@[???]
                       Unresolved local var: cl_entity_t * ent@[???] */
        iVar2 = (*gEngfuncs.GetMaxClients)();
        if ((iVar2 < iVar1) || (pcVar4 = GetEntity(iVar1), pcVar4 == (cl_entity_s *)0x0)) {
          iVar1 = -1;
        }
        else {
          iVar1 = (pcVar4->curstate).team;
        }
                    /* Unresolved local var: cl_entity_t * ent@[???] */
        if (((idx < 1) || (iVar2 = (*gEngfuncs.GetMaxClients)(), iVar2 < idx)) ||
           (pcVar4 = GetEntity(idx), pcVar4 == (cl_entity_s *)0x0)) {
          iVar2 = -1;
        }
        else {
          iVar2 = (pcVar4->curstate).team;
        }
                    /* Unresolved local var: int drop@[???]
                       Unresolved local var: int spray@[???]
                       Unresolved local var: float size@[???] */
        if ((iVar2 != iVar1) &&
           ((*gEngfuncs.pfnGetCvarFloat)("violence_hblood"), extraout_ST0 != (longdouble)0)) {
          EV_TFC_BloodDrips(&local_18,0xf7,0x14);
        }
      }
    }
  }
  else {
                    /* Unresolved local var: Vector tf@[???]
                       Unresolved local var: Vector tu@[???]
                       Unresolved local var: Vector tr@[???]
                       Unresolved local var: int anim@[???]
                       Unresolved local var: float flResult@[???] */
    bitsDamageType = local_30;
    (*gEngfuncs.pfnAngleVectors)(&(pcVar4->curstate).angles.x,bitsDamageType,&local_24,&local_18);
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
    if (local_18 * forward[1] - *forward * local_14 <= 0.0) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
      if ((cl_localblood == (cvar_t *)0x0) || (iVar1 = 2, cl_localblood->value != 0.0)) {
        iVar1 = 2;
        EV_TFC_TraceAttack(idx,(float)vecDir,(float *)ptr,(pmtrace_t *)0x42200000,
                           (int)bitsDamageType);
      }
    }
    else if ((cl_localblood == (cvar_t *)0x0) || (iVar1 = 3, cl_localblood->value != 0.0)) {
      iVar1 = 3;
      EV_TFC_TraceAttack(idx,(float)vecDir,(float *)ptr,(pmtrace_t *)0x42f00000,(int)bitsDamageType)
      ;
    }
    qVar3 = EV_IsLocal(idx);
    if (qVar3 != 0) {
      (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(iVar1,2);
    }
  }
  return 1;
}


// EV_TFC_Spanner  @ 00050670  (line 2823)

int EV_TFC_Spanner(int idx,float *origin,float *forward,float *right,int entity,float *vecDir,
                  pmtrace_t *ptr)

{
  int iVar1;
  cl_entity_s *pcVar2;
  int iVar3;
  char *__nptr;
  uint uVar4;
  int in_stack_ffffffc8;
  uint local_20 [4];
  uint local_10;
  
                    /* Unresolved local var: cl_entity_t * player@[???]
                       Unresolved local var: int t1@[???]
                       Unresolved local var: int t2@[???]
                       Unresolved local var: cl_entity_t * ent@[???] */
  if (((idx < 1) || (iVar1 = (*gEngfuncs.GetMaxClients)(), iVar1 < idx)) ||
     (pcVar2 = GetEntity(idx), pcVar2 == (cl_entity_s *)0x0)) {
    iVar1 = -1;
  }
  else {
    iVar1 = (pcVar2->curstate).team;
  }
                    /* Unresolved local var: cl_entity_t * ent@[???] */
  if (((((0 < entity) && (iVar3 = (*gEngfuncs.GetMaxClients)(), entity <= iVar3)) &&
       ((pcVar2 = GetEntity(entity), pcVar2 != (cl_entity_s *)0x0 &&
        ((iVar3 = (pcVar2->curstate).team, 1 < iVar1 + 1U && (1 < iVar3 + 1U)))))) &&
      (pcVar2 = (*gEngfuncs.GetLocalPlayer)(), pcVar2 != (cl_entity_s *)0x0)) &&
     ((iVar1 < 5 && (iVar3 < 5)))) {
                    /* Unresolved local var: int teamallies@[???]
                       Unresolved local var: int[5] team_ally@[???]
                       Unresolved local var: int i@[???] */
    __nptr = (*gEngfuncs.PhysInfo_ValueForKey)("ta");
    in_stack_ffffffc8 = 0;
    uVar4 = strtol(__nptr,(char **)0x0,10);
    local_20[0] = uVar4 & 0x1f;
    local_20[1] = (int)uVar4 >> 5 & 0x1f;
    local_20[2] = (int)uVar4 >> 10 & 0x1f;
    local_20[3] = (int)uVar4 >> 0xf & 0x1f;
    local_10 = (int)uVar4 >> 0x14 & 0x1f;
    if (((int)local_20[iVar1] >> ((char)iVar3 - 1U & 0x1f) & 1U) != 0 || iVar3 == iVar1) {
      return 1;
    }
  }
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
  if ((cl_localblood != (cvar_t *)0x0) && (cl_localblood->value == 0.0)) {
    return 1;
  }
  EV_TFC_TraceAttack(idx,(float)vecDir,(float *)ptr,(pmtrace_t *)0x41a00000,in_stack_ffffffc8);
  return 1;
}


// EV_TFC_Medkit  @ 000507e0  (line 2837)

int EV_TFC_Medkit(int idx,float *origin,float *forward,float *right,int entity,float *vecDir,
                 pmtrace_t *ptr)

{
  int iVar1;
  cl_entity_s *pcVar2;
  
                    /* Unresolved local var: cl_entity_t * state@[???] */
  if ((0 < entity) && (iVar1 = (*gEngfuncs.GetMaxClients)(), entity <= iVar1)) {
                    /* Unresolved local var: cl_entity_t * state@[???] */
    pcVar2 = GetEntity(entity + -1);
    iVar1 = EV_TFC_IsAlly(idx,entity);
    if (iVar1 == 0) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
      if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
        EV_TFC_TraceAttack(idx,(float)vecDir,(float *)ptr,(pmtrace_t *)0x41200000,entity);
        iVar1 = (pcVar2->curstate).playerclass;
      }
      else {
        iVar1 = (pcVar2->curstate).playerclass;
      }
      if (iVar1 != 5) {
        (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,origin,2,"player/death2.wav",1.0,0.8,0,100);
      }
    }
    return 1;
  }
  return 0;
}


// EV_TFC_Axe  @ 000508f0  (line 2866)

void EV_TFC_Axe(event_args_t *args)

{
  int classid;
  int idx;
  _func_void_int_float_ptr_int_char_ptr_float_float_int_int *p_Var1;
  ushort uVar2;
  qboolean qVar3;
  int32 iVar4;
  uint uVar5;
  int iVar6;
  cl_entity_s *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  float fSoundData;
  float local_f8 [3];
  float local_ec [3];
  float local_e0 [3];
  float local_d4 [3];
  float local_c8 [3];
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  pmtrace_s local_a4;
  pmtrace_s local_60;
  
                    /* Unresolved local var: int fDidHit@[???]
                       Unresolved local var: int m_bHullHit@[???]
                       Unresolved local var: int classid@[???]
                       Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  classid = args->iparam1;
  local_bc = args->origin[0];
  local_b8 = args->origin[1];
  local_b4 = args->origin[2];
  local_b0 = args->angles[0];
  local_ac = args->angles[1];
  local_a8 = args->angles[2];
  idx = args->entindex;
  (*gEngfuncs.pfnAngleVectors)(&local_b0,local_c8,local_d4,local_e0);
  iVar9 = idx + -1;
  EV_GetGunPosition(args,local_f8,&local_bc);
  VectorMA(local_f8,32.0,local_c8,local_ec);
  (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(iVar9);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_f8,local_ec,0,-1,&local_a4);
  if (1.0 <= local_a4.fraction) {
                    /* Unresolved local var: pmtrace_t tr2@[???] */
    (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(1);
    (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_f8,local_ec,0,-1,&local_60);
    if (local_60.fraction < 1.0) {
      uVar5 = 0;
      do {
        *(undefined4 *)((int)&local_a4.allsolid + uVar5) =
             *(undefined4 *)((int)&local_60.allsolid + uVar5);
        uVar5 = uVar5 + 4;
      } while (uVar5 < 0x44);
    }
  }
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  gp_tr_decal[iVar9] = (pmtrace_t *)0x0;
  if (1.0 <= local_a4.fraction) {
                    /* Unresolved local var: int anim@[???] */
    qVar3 = EV_IsLocal(idx);
    if (qVar3 != 0) {
                    /* Unresolved local var: int anim@[???] */
      if (classid == 1) {
        iVar9 = 1;
        goto LAB_00050de5;
      }
      if (classid < 2) {
        if (classid != 0) goto LAB_00050b50;
LAB_00050b28:
        iVar9 = 2;
LAB_00050b2d:
        qVar3 = EV_IsLocal(idx);
        if (qVar3 == 0) goto LAB_00050b50;
      }
      else {
        if (classid == 2) goto LAB_00050b28;
        if (classid != 3) goto LAB_00050b50;
        iVar10 = EV_TFC_PlayCrowbarAnim::m_iSwing + 1;
        if (EV_TFC_PlayCrowbarAnim::m_iSwing % 3 != 1) {
          if (EV_TFC_PlayCrowbarAnim::m_iSwing % 3 == 2) {
            iVar9 = 7;
            EV_TFC_PlayCrowbarAnim::m_iSwing = iVar10;
            goto LAB_00050de5;
          }
          bVar11 = EV_TFC_PlayCrowbarAnim::m_iSwing != (EV_TFC_PlayCrowbarAnim::m_iSwing / 3) * 3;
          EV_TFC_PlayCrowbarAnim::m_iSwing = iVar10;
          if (bVar11) goto LAB_00050b57;
          iVar9 = 4;
          goto LAB_00050b2d;
        }
        iVar9 = 5;
        EV_TFC_PlayCrowbarAnim::m_iSwing = iVar10;
LAB_00050de5:
        qVar3 = EV_IsLocal(idx);
        if (qVar3 == 0) goto LAB_00050b57;
      }
      (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(iVar9,2);
    }
LAB_00050b50:
    if (classid == 2) {
      return;
    }
LAB_00050b57:
    p_Var1 = (gEngfuncs.pEventAPI)->EV_PlaySound;
    iVar4 = (*gEngfuncs.pfnRandomLong)(0,0xf);
    (*p_Var1)(idx,&local_bc,1,"weapons/cbar_miss1.wav",1.0,0.8,0,iVar4 + 0x5e);
    return;
  }
                    /* Unresolved local var: float flVol@[???]
                       Unresolved local var: int fHitWorld@[???]
                       Unresolved local var: int ent@[???]
                       Unresolved local var: ushort m_usAxeDecal@[???] */
  uVar5 = 0;
  do {
    *(undefined4 *)((int)&g_tr_decal[iVar9].allsolid + uVar5) =
         *(undefined4 *)((int)&local_a4.allsolid + uVar5);
    uVar5 = uVar5 + 4;
  } while (uVar5 < 0x44);
                    /* Unresolved local var: int anim@[???] */
  gp_tr_decal[iVar9] = g_tr_decal + iVar9;
  qVar3 = EV_IsLocal(idx);
  if (qVar3 == 0) {
LAB_00050c69:
    iVar10 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_a4);
    if (classid == 1) goto LAB_00050f00;
    if (classid < 2) {
      if (classid == 0) goto LAB_00050ca6;
LAB_00050e70:
      if (gp_tr_decal[iVar9] == (pmtrace_t *)0x0) {
        return;
      }
      iVar6 = 0;
      goto LAB_00050ced;
    }
    if (classid == 2) {
LAB_00050eb4:
                    /* Unresolved local var: cl_entity_t * state@[???] */
      gp_tr_decal[iVar9] = (pmtrace_t *)0x0;
      if (iVar10 < 1) {
        return;
      }
      iVar6 = (*gEngfuncs.GetMaxClients)();
      if (iVar6 < iVar10) {
        iVar6 = 0;
        goto LAB_00050ce2;
      }
                    /* Unresolved local var: cl_entity_t * state@[???] */
      pcVar7 = GetEntity(iVar10 + -1);
      iVar6 = iVar10;
      iVar8 = EV_TFC_IsAlly(idx,iVar10);
      if (iVar8 == 0) {
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
        if ((cl_localblood == (cvar_t *)0x0) || (cl_localblood->value != 0.0)) {
          EV_TFC_TraceAttack(idx,(float)local_c8,(float *)&local_a4,(pmtrace_t *)0x41200000,iVar6);
        }
        if ((pcVar7->curstate).playerclass != 5) {
          (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_bc,2,"player/death2.wav",1.0,0.8,0,100);
        }
      }
      goto LAB_00050f14;
    }
    if (classid != 3) goto LAB_00050e70;
LAB_00050ca6:
    iVar6 = EV_TFC_AxeHit(idx,&local_bc,local_c8,local_d4,iVar10,local_c8,&local_a4);
LAB_00050ce2:
    if (gp_tr_decal[iVar9] != (pmtrace_t *)0x0) goto LAB_00050ced;
  }
  else {
                    /* Unresolved local var: int anim@[???] */
    if (classid != 1) {
      if (classid < 2) {
        iVar10 = 2;
        if (classid == 0) {
LAB_00050c59:
          qVar3 = EV_IsLocal(idx);
          if (qVar3 != 0) goto LAB_00050f55;
        }
        goto LAB_00050c69;
      }
      if (classid == 2) {
        qVar3 = EV_IsLocal(idx);
        if (qVar3 != 0) goto LAB_00050f50;
        iVar10 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_a4);
        goto LAB_00050eb4;
      }
      if (classid != 3) goto LAB_00050c69;
      if (EV_TFC_PlayCrowbarAnim::m_iSwing % 2 == 0) {
        iVar10 = 6;
      }
      else {
        iVar10 = 8;
        if (EV_TFC_PlayCrowbarAnim::m_iSwing % 2 != 1) {
          iVar10 = 3;
          EV_TFC_PlayCrowbarAnim::m_iSwing = EV_TFC_PlayCrowbarAnim::m_iSwing + 1;
          goto LAB_00050c59;
        }
      }
      EV_TFC_PlayCrowbarAnim::m_iSwing = EV_TFC_PlayCrowbarAnim::m_iSwing + 1;
      qVar3 = EV_IsLocal(idx);
      if (qVar3 != 0) goto LAB_00050f55;
      iVar10 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_a4);
      goto LAB_00050ca6;
    }
    qVar3 = EV_IsLocal(idx);
    if (qVar3 != 0) {
LAB_00050f50:
      iVar10 = 3;
LAB_00050f55:
      (*(gEngfuncs.pEventAPI)->EV_WeaponAnimation)(iVar10,2);
      goto LAB_00050c69;
    }
    iVar10 = (*(gEngfuncs.pEventAPI)->EV_IndexFromTrace)(&local_a4);
LAB_00050f00:
    iVar6 = iVar10;
    iVar8 = EV_TFC_IsAlly(idx,iVar10);
                    /* Unresolved local var: Vector dir@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: int hitindex@[???] */
    if ((iVar8 == 0) && ((cl_localblood == (cvar_t *)0x0 || (cl_localblood->value != 0.0)))) {
      EV_TFC_TraceAttack(idx,(float)local_c8,(float *)&local_a4,(pmtrace_t *)0x41a00000,iVar6);
    }
LAB_00050f14:
    iVar6 = 1;
    if (gp_tr_decal[iVar9] == (pmtrace_t *)0x0) goto LAB_00050d73;
LAB_00050ced:
    uVar2 = (*(gEngfuncs.pEventAPI)->EV_PrecacheEvent)(1,"events/wpn/tf_axedecal.sc");
    (*(gEngfuncs.pEventAPI)->EV_PlaybackEvent)
              (idx,(edict_s *)0x0,uVar2,0.2,&local_bc,&local_b0,0.0,0.0,0,0,0,0);
  }
  if (iVar6 == 0) {
    return;
  }
LAB_00050d73:
  qVar3 = EV_IsPlayer(iVar10);
  if (qVar3 == 0) {
    fSoundData = EV_TFC_PlayTextureSound(idx,&local_a4,local_f8,local_f8,5);
    iVar9 = (*gEngfuncs.GetMaxClients)();
    iVar10 = 2;
    if (1 < iVar9) {
      fSoundData = 1.0;
    }
  }
  else {
    fSoundData = 0.0;
    iVar10 = 1;
  }
                    /* Unresolved local var: float fvolbar@[???] */
  EV_TFC_PlayAxeSound(idx,classid,&local_bc,iVar10,fSoundData);
  return;
}


// EV_TFC_AxeDecal  @ 000510a0  (line 2989)

void EV_TFC_AxeDecal(event_args_t *args)

{
  pmtrace_t *pTrace;
  physent_s_conflict *ppVar1;
  int32 iVar2;
  int iVar3;
  
                    /* Unresolved local var: int idx@[???] */
  iVar3 = args->entindex + -1;
  pTrace = gp_tr_decal[iVar3];
  if (pTrace != (pmtrace_t *)0x0) {
                    /* Unresolved local var: physent_t * pe@[???] */
    ppVar1 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
    if ((ppVar1 != (physent_s_conflict *)0x0) && ((ppVar1->solid == 4 || (ppVar1->movetype == 0xd)))
       ) {
                    /* Unresolved local var: physent_t * pe@[???] */
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
      EV_TFC_DamageDecal::decalname._0_4_ = EV_TFC_DamageDecal::decalname._0_4_ & 0xffffff00;
      ppVar1 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
      if ((ppVar1 != (physent_s_conflict *)0x0) && (ppVar1->rendermode != 4)) {
        if (ppVar1->rendermode == 0) {
          iVar2 = (*gEngfuncs.pfnRandomLong)(0,4);
          __sprintf_chk(EV_TFC_DamageDecal::decalname,1,0x20,"{shot%i",iVar2 + 1);
        }
        else {
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: physent_t * pe@[???] */
          builtin_strncpy(EV_TFC_DamageDecal::decalname,"{bproof1",9);
        }
      }
      EV_TFC_DecalTrace(pTrace,EV_TFC_DamageDecal::decalname);
    }
    gp_tr_decal[iVar3] = (pmtrace_t *)0x0;
  }
  return;
}


// EV_TFC_SteamShot  @ 00051190  (line 3002)

void EV_TFC_SteamShot(event_args_t *args)

{
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)
            (args->entindex,&local_18,3,"ambience/steamburst1.wav",1.0,0.8,0,100);
  return;
}


// EV_TFC_NormalShot  @ 00051210  (line 3012)

void EV_TFC_NormalShot(event_args_t *args)

{
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)
            (args->entindex,&local_18,3,"items/medshot4.wav",1.0,0.8,0,100);
  return;
}


// EV_TFC_SuperShot  @ 00051290  (line 3022)

void EV_TFC_SuperShot(event_args_t *args)

{
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???] */
  local_18 = args->origin[0];
  local_14 = args->origin[1];
  local_10 = args->origin[2];
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)
            (args->entindex,&local_18,3,"items/medshot5.wav",1.0,0.8,0,100);
  return;
}


// EV_TFC_GibTouchCallback  @ 00048af0  (line 3036)

void EV_TFC_GibTouchCallback(tempent_s *ent,pmtrace_t *ptr)

{
  int *piVar1;
  int32 iVar2;
  int in_GS_OFFSET;
  longdouble lVar3;
  float fVar4;
  char local_30 [32];
  int local_10;
  
                    /* Unresolved local var: float vel@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  fVar4 = Length(&(ent->entity).baseline.origin.x);
  if ((0.0 < fVar4) && (0 < (ent->entity).curstate.team)) {
                    /* Unresolved local var: float vel@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: char[32] decalname@[???] */
    iVar2 = (*gEngfuncs.pfnRandomLong)(0,5);
    lVar3 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("violence_hblood");
    if (lVar3 != (longdouble)0) {
      __sprintf_chk(local_30,1,0x20,"{blood%i",iVar2 + 1);
      EV_TFC_DecalTrace(ptr,local_30);
    }
    piVar1 = &(ent->entity).curstate.team;
    *piVar1 = *piVar1 + -1;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// EV_TFC_GibCallback  @ 00047c90  (line 3052)

void EV_TFC_GibCallback(tempent_s *ent,float frametime,float currenttime)

{
  int iVar1;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  longdouble extraout_ST0_03;
  float fVar2;
  
                    /* Unresolved local var: float vel@[???] */
  fVar2 = Length(&(ent->entity).baseline.origin.x);
  iVar1 = (ent->entity).curstate.playerclass;
  if (iVar1 == 2) {
    (ent->entity).curstate.playerclass = 3;
    (*gEngfuncs.GetClientTime)();
    (ent->entity).curstate.renderamt = 0xff;
    (ent->entity).curstate.rendermode = 2;
    ent->die = (float)(extraout_ST0_02 + (longdouble)2.5);
    return;
  }
  if (iVar1 < 3) {
    if (iVar1 == 1) {
      fVar2 = (ent->entity).baseline.fuser1 - frametime;
      (ent->entity).baseline.fuser1 = fVar2;
      if (fVar2 <= 0.0) {
        (ent->entity).curstate.playerclass = 2;
      }
      goto LAB_00047d39;
    }
  }
  else {
    if (iVar1 == 3) {
      if (7 < (ent->entity).curstate.renderamt) {
        (*gEngfuncs.GetClientTime)();
        ent->die = (float)(extraout_ST0 + (longdouble)1.0);
        (ent->entity).curstate.renderamt =
             (int)((float)(ent->entity).curstate.renderamt - frametime * 70.0);
        return;
      }
      (ent->entity).curstate.renderamt = 0;
      (*gEngfuncs.GetClientTime)();
      ent->die = (float)((longdouble)0.2 + extraout_ST0_03);
      (ent->entity).curstate.playerclass = 4;
      return;
    }
    if (iVar1 == 4) {
      return;
    }
  }
  if (fVar2 == 0.0) {
    (ent->entity).curstate.playerclass = 1;
    (ent->entity).baseline.fuser1 = cl_giblife->value;
    (*gEngfuncs.GetClientTime)();
    ent->die = (float)(extraout_ST0_01 + (longdouble)1.0);
    return;
  }
LAB_00047d39:
  (*gEngfuncs.GetClientTime)();
  ent->die = (float)(extraout_ST0_00 + (longdouble)1.0);
  return;
}


// EV_TFC_GibVelocityCheck  @ 00051310  (line 3102)

void EV_TFC_GibVelocityCheck(float *vel)

{
  float fVar1;
  
                    /* Unresolved local var: float length@[???] */
  fVar1 = Length(vel);
  if (1500.0 < fVar1) {
    VectorScale(vel,1500.0 / fVar1,vel);
  }
  return;
}


// EV_TFC_CreateGib  @ 00051350  (line 3114)

tempent_s * EV_TFC_CreateGib(float *origin,float *attackdir,int multiplier,int ishead)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  float fVar4;
  float fVar5;
  model_s *pmVar6;
  TEMPENTITY *pTVar7;
  int32 iVar8;
  int iVar9;
  Vector *pVVar10;
  vec_t *pvVar11;
  longdouble lVar12;
  float fVar13;
  float local_48;
  int local_38;
  float local_34 [9];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TEMPENTITY * pGib@[???]
                       Unresolved local var: model_s * model@[???]
                       Unresolved local var: float[3] mins0@[???]
                       Unresolved local var: float[3] maxs0@[???]
                       Unresolved local var: float extent@[???]
                       Unresolved local var: int modelindex@[???]
                       Unresolved local var: float vmultiple@[???] */
  pmVar6 = (*gEngfuncs.CL_LoadModel)("models/hgibs.mdl",&local_38);
  if (pmVar6 != (model_s *)0x0) {
    if (multiplier == 1) {
      local_48 = 0.7;
    }
    else {
      local_48 = 4.0;
      if (multiplier == 2) {
        local_48 = 2.0;
      }
    }
    fVar13 = cl_gibvelscale->value;
    (*(gEngfuncs.pEventAPI)->EV_LocalPlayerBounds)(0,local_34,local_34 + 3);
    pTVar7 = (*(gEngfuncs.pEfxAPI)->CL_TentEntAllocCustom)(origin,pmVar6,0,EV_TFC_GibCallback);
    if (pTVar7 != (TEMPENTITY *)0x0) {
      if (ishead == 0) {
        iVar8 = (*gEngfuncs.pfnRandomLong)(1,5);
        (pTVar7->entity).curstate.body = iVar8;
      }
      else {
        (pTVar7->entity).curstate.body = 0;
      }
      iVar9 = 0;
      do {
        fVar4 = (local_34 + 3)[iVar9];
        fVar5 = local_34[iVar9];
        lVar12 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-1.0,1.0);
        (&(pTVar7->entity).attachment[-2].x)[iVar9] =
             (float)((longdouble)(fVar4 - fVar5) * (longdouble)0.5 * lVar12 +
                    (longdouble)(&(pTVar7->entity).attachment[-2].x)[iVar9]);
        iVar9 = iVar9 + 1;
      } while (iVar9 != 3);
      if (ishead == 0) {
        pVVar10 = &(pTVar7->entity).curstate.velocity;
        VectorScale(attackdir,-1.0,&pVVar10->x);
        do {
          pvVar11 = &pVVar10->y;
          lVar12 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-0.25,0.25);
          pVVar10->x = (float)(lVar12 + (longdouble)pVVar10->x);
          lVar12 = (longdouble)(*gEngfuncs.pfnRandomFloat)(300.0,400.0);
          pVVar10->x = (float)(lVar12 * (longdouble)(local_48 * fVar13) * (longdouble)pVVar10->x);
          pVVar10 = (Vector *)pvVar11;
        } while (&(pTVar7->entity).curstate.mins != (Vector *)pvVar11);
        lVar12 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,200.0);
        (pTVar7->entity).baseline.angles.x = (float)lVar12;
        lVar12 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,200.0);
        (pTVar7->entity).baseline.angles.y = (float)lVar12;
      }
      else {
        lVar12 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-100.0,100.0);
        (pTVar7->entity).curstate.velocity.x = (float)lVar12;
        lVar12 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-100.0,100.0);
        (pTVar7->entity).curstate.velocity.y = (float)lVar12;
        lVar12 = (longdouble)(*gEngfuncs.pfnRandomFloat)(200.0,300.0);
        (pTVar7->entity).curstate.velocity.z = (float)lVar12;
        lVar12 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,200.0);
        (pTVar7->entity).baseline.angles.x = (float)lVar12;
        lVar12 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,300.0);
        (pTVar7->entity).baseline.angles.y = (float)lVar12;
      }
                    /* Unresolved local var: float length@[???] */
      pVVar10 = &(pTVar7->entity).curstate.velocity;
      fVar13 = Length(&pVVar10->x);
      if (1500.0 < fVar13) {
        VectorScale(&pVVar10->x,1500.0 / fVar13,&pVVar10->x);
      }
      fVar13 = pTVar7->die;
      vVar1 = (pTVar7->entity).curstate.velocity.x;
      vVar2 = (pTVar7->entity).curstate.velocity.y;
      vVar3 = (pTVar7->entity).curstate.velocity.z;
      pTVar7->flags = pTVar7->flags | 0x26;
      (pTVar7->entity).baseline.origin.x = vVar1;
      pTVar7->die = fVar13 + 1.0;
      (pTVar7->entity).baseline.origin.y = vVar2;
      (pTVar7->entity).baseline.origin.z = vVar3;
      (pTVar7->entity).curstate.solid = 0;
      (pTVar7->entity).curstate.playerclass = 0;
      pTVar7->hitcallback = EV_TFC_GibTouchCallback;
      (pTVar7->entity).curstate.team = 5;
      return pTVar7;
    }
  }
  return (tempent_s *)0x0;
}


// EV_TFC_Gibs  @ 00051660  (line 3218)

void EV_TFC_Gibs(event_args_t *args)

{
  Vector *pVVar1;
  vec_t vVar2;
  vec_t vVar3;
  vec_t vVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  model_s *pmVar10;
  TEMPENTITY *pTVar11;
  int32 iVar12;
  Vector *pVVar13;
  vec_t *pvVar14;
  int iVar15;
  longdouble lVar16;
  float fVar17;
  int local_70;
  int local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34 [9];
  
                    /* Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector attackdir@[???]
                       Unresolved local var: int cSplat@[???]
                       Unresolved local var: int cGibs@[???]
                       Unresolved local var: int multiplier@[???] */
  local_4c = args->origin[0];
  local_48 = args->origin[1];
  local_44 = args->origin[2];
  local_40 = args->angles[0];
  local_3c = args->angles[1];
  local_38 = args->angles[2];
  iVar15 = args->iparam1;
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)
            (args->entindex,&local_4c,1,"common/bodysplat.wav",1.0,0.8,0,100);
  iVar8 = (int)cl_gibcount->value;
  if (0 < iVar8) {
    iVar9 = 0x40;
    if (iVar8 < 0x40) {
      iVar9 = iVar8;
    }
    local_70 = 0;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TEMPENTITY * pGib@[???]
                       Unresolved local var: model_s * model@[???]
                       Unresolved local var: float[3] mins0@[???]
                       Unresolved local var: float[3] maxs0@[???]
                       Unresolved local var: float extent@[???]
                       Unresolved local var: int modelindex@[???]
                       Unresolved local var: float vmultiple@[???] */
    do {
      pmVar10 = (*gEngfuncs.CL_LoadModel)("models/hgibs.mdl",&local_50);
      if (pmVar10 != (model_s *)0x0) {
        if (iVar15 == 1) {
          fVar17 = 0.7;
        }
        else {
          fVar17 = 4.0;
          if (iVar15 == 2) {
            fVar17 = 2.0;
          }
        }
        fVar5 = cl_gibvelscale->value;
        (*(gEngfuncs.pEventAPI)->EV_LocalPlayerBounds)(0,local_34,local_34 + 3);
        pTVar11 = (*(gEngfuncs.pEfxAPI)->CL_TentEntAllocCustom)
                            (&local_4c,pmVar10,0,EV_TFC_GibCallback);
        if (pTVar11 != (TEMPENTITY *)0x0) {
          iVar8 = 0;
          iVar12 = (*gEngfuncs.pfnRandomLong)(1,5);
          (pTVar11->entity).curstate.body = iVar12;
          do {
            fVar6 = (local_34 + 3)[iVar8];
            fVar7 = local_34[iVar8];
            lVar16 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-1.0,1.0);
            (&(pTVar11->entity).attachment[-2].x)[iVar8] =
                 (float)((longdouble)(fVar6 - fVar7) * (longdouble)0.5 * lVar16 +
                        (longdouble)(&(pTVar11->entity).attachment[-2].x)[iVar8]);
            iVar8 = iVar8 + 1;
          } while (iVar8 != 3);
          pVVar1 = &(pTVar11->entity).curstate.velocity;
          VectorScale(&local_40,-1.0,&pVVar1->x);
          pVVar13 = pVVar1;
          do {
            pvVar14 = &pVVar13->y;
            lVar16 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-0.25,0.25);
            pVVar13->x = (float)(lVar16 + (longdouble)pVVar13->x);
            lVar16 = (longdouble)(*gEngfuncs.pfnRandomFloat)(300.0,400.0);
            pVVar13->x = (float)(lVar16 * (longdouble)(fVar17 * fVar5) * (longdouble)pVVar13->x);
            pVVar13 = (Vector *)pvVar14;
          } while (&(pTVar11->entity).curstate.mins != (Vector *)pvVar14);
          lVar16 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,200.0);
          (pTVar11->entity).baseline.angles.x = (float)lVar16;
          lVar16 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,200.0);
          (pTVar11->entity).baseline.angles.y = (float)lVar16;
                    /* Unresolved local var: float length@[???] */
          fVar17 = Length(&pVVar1->x);
          if (1500.0 < fVar17) {
            VectorScale(&pVVar1->x,1500.0 / fVar17,&pVVar1->x);
          }
          fVar17 = pTVar11->die;
          vVar2 = (pTVar11->entity).curstate.velocity.x;
          vVar3 = (pTVar11->entity).curstate.velocity.y;
          vVar4 = (pTVar11->entity).curstate.velocity.z;
          pTVar11->flags = pTVar11->flags | 0x26;
          (pTVar11->entity).curstate.solid = 0;
          (pTVar11->entity).baseline.origin.x = vVar2;
          pTVar11->die = fVar17 + 1.0;
          (pTVar11->entity).baseline.origin.y = vVar3;
          (pTVar11->entity).baseline.origin.z = vVar4;
          (pTVar11->entity).curstate.playerclass = 0;
          pTVar11->hitcallback = EV_TFC_GibTouchCallback;
          (pTVar11->entity).curstate.team = 5;
        }
      }
      local_70 = local_70 + 1;
    } while (local_70 < iVar9);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: TEMPENTITY * pGib@[???]
                       Unresolved local var: model_s * model@[???]
                       Unresolved local var: float[3] mins0@[???]
                       Unresolved local var: float[3] maxs0@[???]
                       Unresolved local var: float extent@[???]
                       Unresolved local var: int modelindex@[???]
                       Unresolved local var: float vmultiple@[???] */
  pmVar10 = (*gEngfuncs.CL_LoadModel)("models/hgibs.mdl",&local_50);
  if (pmVar10 != (model_s *)0x0) {
    (*(gEngfuncs.pEventAPI)->EV_LocalPlayerBounds)(0,local_34,local_34 + 3);
    pTVar11 = (*(gEngfuncs.pEfxAPI)->CL_TentEntAllocCustom)(&local_4c,pmVar10,0,EV_TFC_GibCallback);
    if (pTVar11 != (TEMPENTITY *)0x0) {
      (pTVar11->entity).curstate.body = 0;
      iVar15 = 0;
      do {
        fVar17 = (local_34 + 3)[iVar15];
        fVar5 = local_34[iVar15];
        lVar16 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-1.0,1.0);
        (&(pTVar11->entity).attachment[-2].x)[iVar15] =
             (float)((longdouble)(fVar17 - fVar5) * (longdouble)0.5 * lVar16 +
                    (longdouble)(&(pTVar11->entity).attachment[-2].x)[iVar15]);
        iVar15 = iVar15 + 1;
      } while (iVar15 != 3);
      pVVar1 = &(pTVar11->entity).curstate.velocity;
      lVar16 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-100.0,100.0);
      (pTVar11->entity).curstate.velocity.x = (float)lVar16;
      lVar16 = (longdouble)(*gEngfuncs.pfnRandomFloat)(-100.0,100.0);
      (pTVar11->entity).curstate.velocity.y = (float)lVar16;
      lVar16 = (longdouble)(*gEngfuncs.pfnRandomFloat)(200.0,300.0);
      (pTVar11->entity).curstate.velocity.z = (float)lVar16;
      lVar16 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,200.0);
      (pTVar11->entity).baseline.angles.x = (float)lVar16;
      lVar16 = (longdouble)(*gEngfuncs.pfnRandomFloat)(100.0,300.0);
      (pTVar11->entity).baseline.angles.y = (float)lVar16;
                    /* Unresolved local var: float length@[???] */
      fVar17 = Length(&pVVar1->x);
      if (1500.0 < fVar17) {
        VectorScale(&pVVar1->x,1500.0 / fVar17,&pVVar1->x);
      }
      fVar17 = pTVar11->die;
      vVar2 = (pTVar11->entity).curstate.velocity.x;
      vVar3 = (pTVar11->entity).curstate.velocity.y;
      vVar4 = (pTVar11->entity).curstate.velocity.z;
      pTVar11->flags = pTVar11->flags | 0x26;
      (pTVar11->entity).baseline.origin.x = vVar2;
      pTVar11->die = fVar17 + 1.0;
      (pTVar11->entity).baseline.origin.y = vVar3;
      (pTVar11->entity).baseline.origin.z = vVar4;
      (pTVar11->entity).curstate.solid = 0;
      (pTVar11->entity).curstate.playerclass = 0;
      pTVar11->hitcallback = EV_TFC_GibTouchCallback;
      (pTVar11->entity).curstate.team = 5;
    }
  }
  return;
}


// EV_TFC_BenchmarkWallMark  @ 00051b50  (line 3252)

void EV_TFC_BenchmarkWallMark(pmtrace_t *pTrace,char *name)

{
  _func_int_int *p_Var1;
  _func_void_int_int_int_float_ptr_int *p_Var2;
  int iVar3;
  longdouble lVar4;
  
  if (((name != (char *)0x0) && (*name != '\0')) && (pTrace->fraction != 1.0)) {
    (pTrace->endpos).z = (pTrace->endpos).z + g_fZAdjust;
    lVar4 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("r_decals");
    if (lVar4 != (longdouble)0) {
      p_Var1 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
      p_Var2 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
      iVar3 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)(name);
      iVar3 = (*p_Var1)(iVar3);
      (*p_Var2)(iVar3,0,0,&(pTrace->endpos).x,0);
    }
  }
  return;
}


// EV_TFC_BenchMarkTrace  @ 00051c10  (line 3268)

void EV_TFC_BenchMarkTrace(pmtrace_t *pTrace)

{
  _func_int_int *p_Var1;
  _func_void_int_int_int_float_ptr_int *p_Var2;
  physent_s_conflict *ppVar3;
  int iVar4;
  longdouble lVar5;
  
                    /* Unresolved local var: physent_t * pe@[???] */
  ppVar3 = (*(gEngfuncs.pEventAPI)->EV_GetPhysent)(pTrace->ent);
  if ((ppVar3 != (physent_s_conflict *)0x0) &&
     (((ppVar3->solid == 4 || (ppVar3->movetype == 0xd)) && (pTrace->fraction != 1.0)))) {
    (pTrace->endpos).z = (pTrace->endpos).z + g_fZAdjust;
    lVar5 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("r_decals");
    if (lVar5 != (longdouble)0) {
      p_Var1 = (gEngfuncs.pEfxAPI)->Draw_DecalIndex;
      p_Var2 = (gEngfuncs.pEfxAPI)->R_DecalShoot;
      iVar4 = (*(gEngfuncs.pEfxAPI)->Draw_DecalIndexFromName)("{dot");
      iVar4 = (*p_Var1)(iVar4);
      (*p_Var2)(iVar4,0,0,&(pTrace->endpos).x,0);
    }
  }
  return;
}


// EV_Benchmark  @ 00051ce0  (line 3283)

void EV_Benchmark(event_args_t *args)

{
  int idx;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  float local_c0 [3];
  float local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  float local_a8 [3];
  float local_9c [3];
  float local_90 [3];
  float local_84;
  undefined4 local_80;
  undefined4 local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  pmtrace_t local_60;
  
                    /* Unresolved local var: Vector vecSrc@[???]
                       Unresolved local var: Vector vecDir@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int iDamage@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angles@[???]
                       Unresolved local var: Vector velocity@[???] */
  local_74 = args->origin[1];
  local_70 = args->origin[2];
  local_6c = args->angles[0];
  local_68 = args->angles[1];
  local_64 = args->angles[2];
  local_78 = args->origin[0];
  idx = args->entindex;
  (*gEngfuncs.pfnAngleVectors)(&local_6c,&local_84,local_90,local_9c);
  EV_IsLocal(idx);
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(idx,&local_78,1,"common/wpn_select.wav",0.9,0.8,0,100);
  EV_GetGunPosition(args,local_c0,&local_78);
  local_b4 = local_84;
  local_b0 = local_80;
  local_ac = local_7c;
  VectorMA(local_c0,2.0,local_9c,local_c0);
  VectorMA(local_c0,8192.0,&local_b4,local_a8);
  (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(idx + -1);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(local_c0,local_a8,2,-1,&local_60);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  if ((local_60.fraction != 1.0) &&
     ((*gEngfuncs.GetClientTime)(), (longdouble)g_nTime < extraout_ST0)) {
    EV_TFC_BenchMarkTrace(&local_60);
    (*gEngfuncs.GetClientTime)();
    g_nTime = (float)((longdouble)0.05 + extraout_ST0_00);
    return;
  }
  return;
}


// FindEntity  @ 00051f10  (line 3364)

eventnode_t * FindEntity(int index)

{
  eventnode_s *peVar1;
  
                    /* Unresolved local var: eventnode_t * node@[DW_OP_reg0(EAX)] */
  peVar1 = (eventnode_t *)0x0;
  if (g_pEventListHead != (eventnode_t *)0x0) {
    peVar1 = g_pEventListHead;
    if (index == g_pEventListHead->data->entindex) {
      return g_pEventListHead;
    }
    do {
      peVar1 = peVar1->next;
      if (peVar1 == (eventnode_s *)0x0) {
        return (eventnode_t *)0x0;
      }
    } while (peVar1->data->entindex != index);
  }
  return peVar1;
}


// AddEvent  @ 00051f50  (line 3380)

void AddEvent(eventnode_t *node)

{
  eventnode_t *peVar1;
  eventnode_t *peVar2;
  
  if (node != (eventnode_t *)0x0) {
    peVar1 = g_pEventListHead;
    if (g_pEventListHead == (eventnode_t *)0x0) {
      g_pEventListHead = node;
      node->next = (eventnode_s *)0x0;
      node->prev = (eventnode_s *)0x0;
      return;
    }
    do {
      peVar2 = peVar1;
      peVar1 = peVar2->next;
    } while (peVar2->next != (eventnode_s *)0x0);
    node->prev = peVar2;
    node->next = (eventnode_s *)0x0;
    peVar2->next = node;
  }
  return;
}


// RemoveEvent  @ 00051fa0  (line 3407)

void RemoveEvent(eventnode_t *node)

{
  eventnode_s *peVar1;
  
  if ((node == (eventnode_t *)0x0) || (g_pEventListHead == (eventnode_t *)0x0)) {
    return;
  }
  if (node == g_pEventListHead) {
    g_pEventListHead = (eventnode_t *)0x0;
    if (node->next != (eventnode_s *)0x0) {
      node->next->prev = (eventnode_s *)0x0;
      g_pEventListHead = node->next;
    }
    free(node);
    return;
  }
  peVar1 = node->prev;
  if ((node->next != (eventnode_s *)0x0) && (peVar1 != (eventnode_s *)0x0)) {
    node->next->prev = peVar1;
    node->prev->next = node->next;
    free(node);
    return;
  }
  peVar1->next = (eventnode_s *)0x0;
  free(node);
  return;
}


// EV_TFC_BuildingEvent  @ 00052020  (line 3438)

void EV_TFC_BuildingEvent(event_args_t *args)

{
  float fVar1;
  eventnode_s *peVar2;
  int *piVar3;
  eventnode_t *peVar4;
  uint uVar5;
  eventnode_s *peVar6;
  event_args_t *peVar7;
  event_args_t *peVar8;
  event_args_t *peVar9;
  undefined2 *puVar10;
  uint uVar11;
  int iVar12;
  eventnode_t *peVar13;
  uint uVar14;
  event_args_t *peVar15;
  undefined2 *puVar16;
  bool bVar17;
  
                    /* Unresolved local var: eventnode_t * temp@[???] */
  peVar4 = g_pEventListHead;
  if (args != (event_args_t *)0x0) {
                    /* Unresolved local var: eventnode_t * node@[???] */
    if (g_pEventListHead == (eventnode_t *)0x0) {
LAB_0005205e:
                    /* Unresolved local var: eventnode_t * pEventNode@[???] */
      if ((args->bparam1 != 0) && (peVar6 = operator_new(0xc), peVar6 != (eventnode_s *)0x0)) {
                    /* Unresolved local var: event_args_t * pEventData@[???] */
        peVar6->data = (event_args_t *)0x0;
        peVar6->prev = (eventnode_s *)0x0;
        peVar6->next = (eventnode_s *)0x0;
        peVar7 = operator_new(0x48);
        if (peVar7 == (event_args_t *)0x0) {
          operator_delete(peVar6);
          return;
        }
        bVar17 = ((uint)peVar7 & 1) != 0;
        uVar14 = 0x48;
        peVar8 = peVar7;
        peVar15 = args;
        if (bVar17) {
          peVar8 = (event_args_t *)((int)&peVar7->flags + 1);
          uVar14 = 0x47;
          peVar15 = (event_args_t *)((int)&args->flags + 1);
          *(char *)&peVar7->flags = (char)args->flags;
        }
        peVar9 = peVar8;
        if (((uint)peVar8 & 2) != 0) {
          piVar3 = &peVar15->flags;
          peVar9 = (event_args_t *)((int)&peVar8->flags + 2);
          peVar15 = (event_args_t *)((int)&peVar15->flags + 2);
          uVar14 = uVar14 - 2;
          *(short *)&peVar8->flags = (short)*piVar3;
        }
        uVar5 = 0;
        do {
          uVar11 = uVar5;
          *(undefined4 *)((int)peVar9->origin + (uVar11 - 8)) =
               *(undefined4 *)((int)peVar15->origin + (uVar11 - 8));
          uVar5 = uVar11 + 4;
        } while (uVar11 + 4 < (uVar14 & 0xfffffffc));
        puVar10 = (undefined2 *)((int)peVar9->origin + (uVar11 - 4));
        puVar16 = (undefined2 *)((int)peVar15->origin + (uVar11 - 4));
        iVar12 = 0;
        if ((uVar14 & 2) != 0) {
          *puVar10 = *puVar16;
          iVar12 = 2;
        }
        if (bVar17) {
          *(undefined1 *)((int)puVar10 + iVar12) = *(undefined1 *)((int)puVar16 + iVar12);
        }
        uVar14 = args->iparam1;
        peVar6->data = peVar7;
        if ((uVar14 & 0x800) != 0) {
          fVar1 = args->fparam1;
          peVar7->iparam1 = uVar14 & 0xfffff7ff;
          peVar7->entindex = (int)fVar1;
        }
        peVar4 = g_pEventListHead;
        if (g_pEventListHead == (eventnode_t *)0x0) {
          g_pEventListHead = peVar6;
          peVar6->next = (eventnode_s *)0x0;
          peVar6->prev = (eventnode_s *)0x0;
        }
        else {
          do {
            peVar13 = peVar4;
            peVar4 = peVar13->next;
          } while (peVar13->next != (eventnode_s *)0x0);
          peVar6->prev = peVar13;
          peVar6->next = (eventnode_s *)0x0;
          peVar13->next = peVar6;
        }
      }
    }
    else {
      peVar7 = g_pEventListHead->data;
      iVar12 = peVar7->entindex;
      peVar6 = g_pEventListHead;
      while (args->entindex != iVar12) {
        peVar6 = peVar6->next;
        if (peVar6 == (eventnode_s *)0x0) goto LAB_0005205e;
        peVar7 = peVar6->data;
        iVar12 = peVar7->entindex;
      }
      if (args->bparam1 != 1) {
        uVar14 = args->iparam1;
        if ((uVar14 & 0x100) != 0) {
          peVar7->origin[0] = args->origin[0];
          peVar6->data->origin[1] = args->origin[1];
          peVar6->data->origin[2] = args->origin[2];
          return;
        }
        if ((uVar14 & 0x400) == 0) {
          peVar7->iparam1 = peVar7->iparam1 & ~uVar14;
          if ((args->iparam1 & 0x200) != 0) {
            peVar6->data->bparam2 = 0;
          }
          if (peVar6->data->iparam1 != 0) {
            return;
          }
        }
        if (peVar4 == peVar6) {
          g_pEventListHead = (eventnode_t *)0x0;
          if (peVar6->next != (eventnode_s *)0x0) {
            peVar6->next->prev = (eventnode_s *)0x0;
            g_pEventListHead = peVar6->next;
          }
        }
        else {
          peVar2 = peVar6->prev;
          if ((peVar6->next == (eventnode_s *)0x0) || (peVar2 == (eventnode_s *)0x0)) {
            peVar2->next = (eventnode_s *)0x0;
          }
          else {
            peVar6->next->prev = peVar2;
            peVar6->prev->next = peVar6->next;
          }
        }
        free(peVar6);
        return;
      }
      peVar7->iparam1 = peVar7->iparam1 | args->iparam1;
      peVar6->data->iparam2 = args->iparam2;
      uVar14 = args->iparam1;
      if ((uVar14 & 0x200) != 0) {
        peVar6->data->bparam2 = args->bparam2;
        uVar14 = args->iparam1;
      }
      if ((uVar14 & 0x800) != 0) {
        peVar6->data->entindex = (int)args->fparam1;
        piVar3 = &peVar6->data->iparam1;
        *piVar3 = *piVar3 & 0xfffff7ff;
        return;
      }
    }
  }
  return;
}


// ClearEventList  @ 000522e0  (line 3543)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ClearEventList(void)

{
  eventnode_s *peVar1;
  eventnode_t *peVar2;
  
  peVar2 = g_pEventListHead;
  while (peVar2 != (eventnode_t *)0x0) {
    peVar1 = peVar2->next;
    operator_delete(peVar2->data);
    operator_delete(peVar2);
    peVar2 = peVar1;
  }
  g_pEventListHead = (eventnode_t *)0x0;
  g_flNextEventListThink = 0.0;
  return;
}


// RunEventList  @ 00052af0  (line 3560)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void RunEventList(void)

{
  int *piVar1;
  float fVar2;
  eventnode_s *peVar3;
  eventnode_s *peVar4;
  eventnode_t *__ptr;
  int iVar5;
  uint uVar6;
  Vector *pVVar7;
  int iVar8;
  event_args_t *args;
  longdouble lVar9;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: eventnode_t * temp@[???]
                       Unresolved local var: eventnode_t * next@[???] */
  if (g_flNextEventListThink == 0.0) {
    fVar2 = gpGlobals->time;
  }
  else {
    fVar2 = gpGlobals->time;
    if (fVar2 < g_flNextEventListThink) {
      return;
    }
  }
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: int sprite@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: Vector team@[???] */
  g_flNextEventListThink = fVar2 + 0.1;
  peVar3 = g_pEventListHead;
  do {
    __ptr = peVar3;
    if (__ptr == (eventnode_t *)0x0) {
      return;
    }
    args = __ptr->data;
    peVar3 = __ptr->next;
    uVar6 = args->iparam1;
    if ((((uVar6 & 0x10) != 0) && (args != (event_args_t *)0x0)) &&
       ((args->fparam2 == 0.0 || (args->fparam2 <= gpGlobals->time)))) {
      lVar9 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.0,1.0);
      if ((longdouble)0.98 < lVar9) {
        args->fparam2 = gpGlobals->time + 6.0;
        (*(gEngfuncs.pEventAPI)->EV_PlaySound)
                  (-1,args->origin,6,"misc/teleport_ready.wav",1.0,0.5,0,100);
      }
      args = __ptr->data;
      uVar6 = args->iparam1;
    }
    if ((uVar6 & 0x80) != 0) {
      (*(gEngfuncs.pEventAPI)->EV_PlaySound)
                (-1,args->origin,6,"misc/teleport_out.wav",1.0,0.5,0,100);
      piVar1 = &__ptr->data->iparam1;
      *piVar1 = *piVar1 & 0xffffff7f;
      piVar1 = &__ptr->data->iparam1;
      *piVar1 = *piVar1 | 4;
      args = __ptr->data;
      uVar6 = args->iparam1;
    }
    if ((uVar6 & 0x40) != 0) {
      (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,args->origin,6,"misc/teleport_in.wav",1.0,0.5,0,100)
      ;
      piVar1 = &__ptr->data->iparam1;
      *piVar1 = *piVar1 & 0xffffffbf;
      piVar1 = &__ptr->data->iparam1;
      *piVar1 = *piVar1 | 8;
      args = __ptr->data;
      uVar6 = args->iparam1;
    }
    if ((uVar6 & 0x20) != 0) {
      (*(gEngfuncs.pEventAPI)->EV_PlaySound)
                (-1,args->origin,6,"misc/teleport_ready.wav",1.0,0.5,0,100);
      piVar1 = &__ptr->data->iparam1;
      *piVar1 = *piVar1 & 0xffffffdf;
      args = __ptr->data;
      uVar6 = args->iparam1;
    }
    if ((uVar6 & 1) != 0) {
      DoSparkSmokeEffect(args);
      args = __ptr->data;
      uVar6 = args->iparam1;
    }
    if (((uVar6 & 0xc) != 0) && (args != (event_args_t *)0x0)) {
      iVar5 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/shellchrome.spr");
      if ((args->iparam1 & 4) == 0) {
        iVar8 = DoTeleporterRings::iExitCount + -1;
        DoTeleporterRings::iExitCount = iVar8;
        if (-1 < iVar8) goto LAB_00052b9f;
        local_2c = 14.0;
        DoTeleporterRings::iExitCount = 6;
      }
      else {
        iVar8 = DoTeleporterRings::iEntryCount + 1;
        DoTeleporterRings::iEntryCount = iVar8;
        if (iVar8 < 7) {
LAB_00052b9f:
          local_2c = (float)(iVar8 * -0xe + 0x62);
        }
        else {
          local_2c = 98.0;
          DoTeleporterRings::iEntryCount = 0;
        }
      }
      local_34 = args->origin[0];
      pVVar7 = &g_vBlack;
      local_30 = args->origin[1];
      uVar6 = args->iparam2 - 1;
      local_2c = local_2c + args->origin[2];
      local_20 = local_2c + 125.0;
      if (uVar6 < 4) {
        pVVar7 = *(Vector **)(CSWTCH_319 + uVar6 * 4);
      }
      local_28 = local_34;
      local_24 = local_30;
      (*(gEngfuncs.pEfxAPI)->R_BeamCirclePoints)
                (0x15,&local_34,&local_28,iVar5,0.2,10.0,0.0,1.0,0.0,0,0.0,pVVar7->x,pVVar7->y,
                 pVVar7->z);
      args = __ptr->data;
      uVar6 = args->iparam1;
    }
    if ((uVar6 & 0x200) != 0) {
      DoTeleporterParticles(args);
      uVar6 = __ptr->data->iparam1;
    }
    if ((uVar6 == 0) && (g_pEventListHead != (eventnode_t *)0x0)) {
      if (g_pEventListHead == __ptr) {
        g_pEventListHead = (eventnode_t *)0x0;
        if (__ptr->next != (eventnode_s *)0x0) {
          __ptr->next->prev = (eventnode_s *)0x0;
          g_pEventListHead = __ptr->next;
        }
      }
      else {
        peVar4 = __ptr->prev;
        if ((__ptr->next == (eventnode_s *)0x0) || (peVar4 == (eventnode_s *)0x0)) {
          peVar4->next = (eventnode_s *)0x0;
        }
        else {
          __ptr->next->prev = peVar4;
          __ptr->prev->next = __ptr->next;
        }
      }
      free(__ptr);
    }
  } while( true );
}


// RandomSparkSound  @ 00052330  (line 3638)

void RandomSparkSound(float *origin)

{
  char *pcVar1;
  longdouble lVar2;
  longdouble lVar3;
  
                    /* Unresolved local var: char * sound@[???]
                       Unresolved local var: float flVolume@[???] */
  lVar2 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.2,0.45);
  lVar3 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.0,1.0);
  pcVar1 = "buttons/spark6.wav";
  if ((uint)(int)(lVar3 * (longdouble)6.0) < 5) {
    pcVar1 = *(char **)(CSWTCH_313 + (int)(lVar3 * (longdouble)6.0) * 4);
  }
  (*(gEngfuncs.pEventAPI)->EV_PlaySound)(-1,origin,6,pcVar1,(float)lVar2,0.8,0,100);
  return;
}


// DoSparkSmokeEffect  @ 000523d0  (line 3657)

void DoSparkSmokeEffect(event_args_t *args)

{
  Vector *pVVar1;
  _func_TEMPENTITY_ptr_float_ptr_int_float *p_Var2;
  _func_void_TEMPENTITY_ptr_float *p_Var3;
  int32 iVar4;
  int32 iVar5;
  int32 iVar6;
  int iVar7;
  int iVar8;
  TEMPENTITY *pTVar9;
  char *pcVar10;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_s local_50;
  
  if (args != (event_args_t *)0x0) {
    (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
    if ((longdouble)0.8 < extraout_ST0) {
                    /* Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: Vector vecstart@[???]
                       Unresolved local var: Vector vecend@[???] */
      local_68 = args->origin[0];
      local_64 = args->origin[1];
      local_60 = args->origin[2];
      iVar4 = (*gEngfuncs.pfnRandomLong)(0xf,0x32);
      iVar5 = (*gEngfuncs.pfnRandomLong)(-0x32,0x32);
      iVar6 = (*gEngfuncs.pfnRandomLong)(-0x32,0x32);
      local_54 = (float)iVar4 + local_60;
      local_58 = (float)iVar5 + local_64;
      local_5c = (float)iVar6 + local_68;
      (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
      (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
      (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_5c,&local_68,0,-1,&local_50);
      (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
      iVar8 = args->entindex;
      iVar7 = PM_GetPhysEntInfo(local_50.ent);
      if (iVar8 == iVar7) {
        pVVar1 = &local_50.endpos;
        (*(gEngfuncs.pEfxAPI)->R_SparkEffect)(&pVVar1->x,8,-200,200);
                    /* Unresolved local var: char * sound@[???]
                       Unresolved local var: float flVolume@[???] */
        (*gEngfuncs.pfnRandomFloat)(0.2,0.45);
        (*gEngfuncs.pfnRandomFloat)(0.0,1.0);
        pcVar10 = "buttons/spark6.wav";
        if ((uint)(int)(extraout_ST0_01 * (longdouble)6.0) < 5) {
          pcVar10 = *(char **)(CSWTCH_313 + (int)(extraout_ST0_01 * (longdouble)6.0) * 4);
        }
        (*(gEngfuncs.pEventAPI)->EV_PlaySound)
                  (-1,&pVVar1->x,6,pcVar10,(float)extraout_ST0_00,0.8,0,100);
        if ((args->iparam1 & 2) != 0) {
          local_50.endpos.z = local_50.endpos.z - 8.0;
          p_Var2 = (gEngfuncs.pEfxAPI)->R_DefaultSprite;
          p_Var3 = (gEngfuncs.pEfxAPI)->R_Sprite_Smoke;
          iVar8 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/steam1.spr");
          pTVar9 = (*p_Var2)(&pVVar1->x,iVar8,15.0);
          (*p_Var3)(pTVar9,0.8);
        }
      }
    }
  }
  return;
}


// GetTeamColor  @ 00052650  (line 3703)

Vector * GetTeamColor(int team_no)

{
  Vector *pVVar1;
  
  pVVar1 = &g_vBlack;
  if (team_no - 1U < 4) {
    pVVar1 = *(Vector **)(CSWTCH_319 + (team_no - 1U) * 4);
  }
  return pVVar1;
}


// DoTeleporterRings  @ 00052670  (line 3721)

void DoTeleporterRings(event_args_t *args)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  Vector *pVVar4;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: int sprite@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: Vector team@[???] */
  if (args == (event_args_t *)0x0) {
    return;
  }
                    /* Unresolved local var: Vector vecSpot@[???]
                       Unresolved local var: Vector vecEnd@[???]
                       Unresolved local var: int sprite@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: Vector team@[???] */
  iVar1 = (*(gEngfuncs.pEventAPI)->EV_FindModelIndex)("sprites/shellchrome.spr");
  if ((args->iparam1 & 4) == 0) {
    iVar3 = DoTeleporterRings::iExitCount + -1;
    DoTeleporterRings::iExitCount = iVar3;
    if (iVar3 < 0) {
      local_1c = 14.0;
      DoTeleporterRings::iExitCount = 6;
      goto LAB_000526c2;
    }
  }
  else {
    iVar3 = DoTeleporterRings::iEntryCount + 1;
    DoTeleporterRings::iEntryCount = iVar3;
    if (6 < iVar3) {
      local_1c = 98.0;
      DoTeleporterRings::iEntryCount = 0;
      goto LAB_000526c2;
    }
  }
  local_1c = (float)(iVar3 * -0xe + 0x62);
LAB_000526c2:
  local_24 = args->origin[0];
  pVVar4 = &g_vBlack;
  local_20 = args->origin[1];
  uVar2 = args->iparam2 - 1;
  local_1c = local_1c + args->origin[2];
  local_10 = local_1c + 125.0;
  if (uVar2 < 4) {
    pVVar4 = *(Vector **)(CSWTCH_319 + uVar2 * 4);
  }
  local_18 = local_24;
  local_14 = local_20;
  (*(gEngfuncs.pEfxAPI)->R_BeamCirclePoints)
            (0x15,&local_24,&local_18,iVar1,0.2,10.0,0.0,1.0,0.0,0,0.0,pVVar4->x,pVVar4->y,pVVar4->z
            );
  return;
}


// DoTeleporterParticles  @ 000527e0  (line 3763)

void DoTeleporterParticles(event_args_t *args)

{
  float fVar1;
  float fVar2;
  _2globalvars_t *p1Var3;
  pfnEngSrc_GetSpritePointer_t p_Var4;
  HANDLE_SPRITE HVar5;
  model_s *pmVar6;
  int32 iVar7;
  undefined4 *puVar8;
  int32 iVar9;
  int32 iVar10;
  int iVar11;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  longdouble extraout_ST0_01;
  longdouble extraout_ST0_02;
  float local_44;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: model_s * pSprite@[???]
                       Unresolved local var: int count@[???] */
  p_Var4 = gEngfuncs.GetSpritePointer;
  if (args != (event_args_t *)0x0) {
    HVar5 = (*gEngfuncs.pfnSPR_Load)("sprites/particle.spr");
    pmVar6 = (*p_Var4)(HVar5);
                    /* Unresolved local var: int i@[???] */
    if ((pmVar6 != (model_s *)0x0) && (iVar7 = (*gEngfuncs.pfnRandomLong)(10,0xf), 0 < iVar7)) {
      iVar11 = 0;
      do {
        while( true ) {
          fVar1 = args->origin[0];
          fVar2 = args->origin[1];
          local_44 = args->origin[2];
          iVar9 = (*gEngfuncs.pfnRandomLong)(-0xf,0xf);
          iVar10 = (*gEngfuncs.pfnRandomLong)(-0xf,0xf);
          if (args->bparam2 == 0) {
            local_44 = local_44 + 12.0;
          }
          else {
                    /* Unresolved local var: Vector origin@[???]
                       Unresolved local var: Vector angle@[???]
                       Unresolved local var: CBaseParticle * pParticle@[???] */
            local_44 = local_44 + 98.0;
          }
          (*gEngfuncs.pfnRandomFloat)(0.0,255.0);
          (*gEngfuncs.pfnRandomFloat)(0.0,255.0);
          (*gEngfuncs.pfnRandomFloat)(0.0,255.0);
          puVar8 = (undefined4 *)
                   (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[9])
                             (g_pParticleMan,0x114);
          *puVar8 = &PTR_Think_000bf7f0;
          if (puVar8 == (undefined4 *)0x0) {
            return;
          }
          local_20 = local_44;
          local_34 = 0;
          local_30 = 0;
          local_2c = 0x3f800000;
          local_28 = (float)iVar9 + fVar1;
          local_24 = (float)iVar10 + fVar2;
          (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[10])
                    (g_pParticleMan,puVar8,&local_28,&local_34,pmVar6,0x40400000,0x437f0000);
          puVar8[0x1a] = (float)extraout_ST0_01;
          puVar8[0x1b] = (float)extraout_ST0_00;
          puVar8[0x1c] = (float)extraout_ST0;
          puVar8[0xf] = 0;
          puVar8[0x16] = 4;
          puVar8[0xc] = 0x41200000;
          puVar8[0x15] = 0;
          puVar8[7] = 0;
          (*gEngfuncs.pfnRandomFloat)(0.0,0.5);
          puVar8[4] = puVar8[4] | 0x20;
          puVar8[1] = puVar8[1] & 0xffffff80 | 0x1c;
          p1Var3 = gpGlobals;
          puVar8[0x2f] = (float)extraout_ST0_02;
          fVar1 = p1Var3->time;
          puVar8[0x2c] = 0;
          puVar8[0x2d] = 0x437f0000;
          puVar8[0x2e] = 0;
          puVar8[0xe] = fVar1 + 0.75;
          if (args->bparam2 == 0) break;
          iVar9 = (*gEngfuncs.pfnRandomLong)(-0x32,0x32);
          iVar11 = iVar11 + 1;
          puVar8[0x20] = 0;
          puVar8[0x21] = 0;
          puVar8[0x22] = (float)(iVar9 + -0x4b);
          if (iVar7 == iVar11) {
            return;
          }
        }
        iVar9 = (*gEngfuncs.pfnRandomLong)(-0x32,0x32);
        iVar11 = iVar11 + 1;
        puVar8[0x20] = 0;
        puVar8[0x21] = 0;
        puVar8[0x22] = (float)(iVar9 + 0x4b);
      } while (iVar7 != iVar11);
    }
  }
  return;
}


// PlayTeleporterAmbientSound  @ 00052f80  (line 3827)

void PlayTeleporterAmbientSound(event_args_t *args)

{
  longdouble lVar1;
  
  if ((args != (event_args_t *)0x0) &&
     (((args->fparam2 == 0.0 || (args->fparam2 <= gpGlobals->time)) &&
      (lVar1 = (longdouble)(*gEngfuncs.pfnRandomFloat)(0.0,1.0), (longdouble)0.98 < lVar1)))) {
    args->fparam2 = gpGlobals->time + 6.0;
    (*(gEngfuncs.pEventAPI)->EV_PlaySound)
              (-1,args->origin,6,"misc/teleport_ready.wav",1.0,0.5,0,100);
    return;
  }
  return;
}


// CheckEventsFinished  @ 00053040  (line 3846)

void CheckEventsFinished(eventnode_t *node)

{
  eventnode_s *peVar1;
  
  if (((node != (eventnode_t *)0x0) && (node->data->iparam1 == 0)) &&
     (g_pEventListHead != (eventnode_t *)0x0)) {
    if (node == g_pEventListHead) {
      g_pEventListHead = (eventnode_t *)0x0;
      if (node->next != (eventnode_s *)0x0) {
        node->next->prev = (eventnode_s *)0x0;
        g_pEventListHead = node->next;
      }
    }
    else {
      peVar1 = node->prev;
      if ((node->next == (eventnode_s *)0x0) || (peVar1 == (eventnode_s *)0x0)) {
        peVar1->next = (eventnode_s *)0x0;
      }
      else {
        node->next->prev = peVar1;
        node->prev->next = node->next;
      }
    }
    free(node);
    return;
  }
  return;
}


