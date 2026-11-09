// Ghidra decompilation of functions from pm_shared/pm_debug.c
// 7 functions, ordered by original source line

// PM_ShowClipBox  @ 001757b0  (line 76)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_ShowClipBox(void)

{
  return;
}


// PM_ParticleLine  @ 001756e0  (line 84)

void __regparm3 PM_ParticleLine(vec_t *start,vec_t *end,int pcolor,float life,float vert)

{
  float fVar1;
  float fVar2;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float linestep@[???] */
  local_28 = *end - *start;
  local_24 = end[1] - start[1];
  local_20 = end[2] - start[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *start;
      local_30 = local_24 * fVar1 + start[1];
      local_2c = local_20 * fVar1 + start[2];
      (*pmove->PM_Particle)(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
  return;
}


// PM_ParticleLine  @ 001757c0  (line 85)

void PM_ParticleLine(vec_t *start,vec_t *end,int pcolor,float life,float vert)

{
  float fVar1;
  float fVar2;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
  local_28 = *end - *start;
  local_24 = end[1] - start[1];
  local_20 = end[2] - start[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *start;
      local_30 = local_24 * fVar1 + start[1];
      local_2c = local_20 * fVar1 + start[2];
      (*pmove->PM_Particle)(&local_34,pcolor,life,0,(int)vert);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
  return;
}


// PM_DrawRectangle  @ 001758b0  (line 117)

void PM_DrawRectangle(vec_t *tl,vec_t *bl,vec_t *tr,vec_t *br,int pcolor,float life)

{
  float in_stack_ffffffc8;
  
  PM_ParticleLine(tl,bl,pcolor,life,in_stack_ffffffc8);
  PM_ParticleLine(bl,br,pcolor,life,in_stack_ffffffc8);
  PM_ParticleLine(br,tr,pcolor,life,in_stack_ffffffc8);
  PM_ParticleLine(tr,tl,pcolor,life,(float)bl);
  return;
}


// PM_DrawPhysEntBBox  @ 00175940  (line 131)

void PM_DrawPhysEntBBox(int num,int pcolor,float life)

{
  float fVar1;
  float fVar2;
  float fVar3;
  model_s *pmVar4;
  playermove_t *ppVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  vec_t *in_stack_fffffe98;
  float local_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float local_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float local_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float local_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float local_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float local_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
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
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: float gap@[???]
                       Unresolved local var: vec3_t modelmins@[???]
                       Unresolved local var: vec3_t modelmaxs@[???] */
  ppVar5 = pmove;
  if ((0 < num) && (num < pmove->numphysent)) {
    pmVar4 = pmove->physents[num].model;
    if (pmVar4 == (model_s *)0x0) {
      fStack_a8 = pmove->physents[num].maxs[1] + pmove->physents[num].origin[1];
      fStack_a4 = pmove->physents[num].maxs[2] + pmove->physents[num].origin[2];
      local_ac = pmove->physents[num].origin[0] + pmove->physents[num].maxs[0];
      local_9c = pmove->physents[num].maxs[1] + pmove->physents[num].origin[1];
      fStack_98 = pmove->physents[num].maxs[2] + pmove->physents[num].origin[2];
      fStack_a0 = pmove->physents[num].mins[0] + pmove->physents[num].origin[0];
      fStack_90 = pmove->physents[num].mins[1] + pmove->physents[num].origin[1];
      local_8c = pmove->physents[num].maxs[2] + pmove->physents[num].origin[2];
      fStack_94 = pmove->physents[num].maxs[0] + pmove->physents[num].origin[0];
      fStack_84 = pmove->physents[num].mins[1] + pmove->physents[num].origin[1];
      fStack_80 = pmove->physents[num].maxs[2] + pmove->physents[num].origin[2];
      fStack_88 = pmove->physents[num].mins[0] + pmove->physents[num].origin[0];
      fStack_78 = pmove->physents[num].maxs[1] + pmove->physents[num].origin[1];
      fStack_74 = pmove->physents[num].mins[2] + pmove->physents[num].origin[2];
      local_7c = pmove->physents[num].maxs[0] + pmove->physents[num].origin[0];
      local_6c = pmove->physents[num].maxs[1] + pmove->physents[num].origin[1];
      fStack_68 = pmove->physents[num].mins[2] + pmove->physents[num].origin[2];
      fStack_70 = pmove->physents[num].mins[0] + pmove->physents[num].origin[0];
      fStack_60 = pmove->physents[num].mins[1] + pmove->physents[num].origin[1];
      local_5c = pmove->physents[num].mins[2] + pmove->physents[num].origin[2];
      fStack_64 = pmove->physents[num].maxs[0] + pmove->physents[num].origin[0];
      fStack_54 = pmove->physents[num].mins[1] + pmove->physents[num].origin[1];
      fStack_50 = pmove->physents[num].mins[2] + pmove->physents[num].origin[2];
      fStack_58 = pmove->physents[num].mins[0] + pmove->physents[num].origin[0];
    }
    else {
      fVar1 = pmove->physents[num].origin[0];
      fVar2 = pmove->physents[num].origin[1];
      fVar3 = pmove->physents[num].origin[2];
      in_stack_fffffe98 = &local_48;
      (*pmove->PM_GetModelBounds)(pmVar4,in_stack_fffffe98,&local_3c);
      fStack_a0 = local_48;
      fStack_90 = local_44;
      local_ac = local_3c + 0.0;
      fStack_88 = local_48;
      fStack_a8 = local_38 + 0.0;
      fStack_84 = local_44;
      fStack_a4 = local_34 + 0.0;
      fStack_74 = local_40;
      fStack_70 = local_48;
      fStack_68 = local_40;
      fStack_60 = local_44;
      local_5c = local_40;
      fStack_58 = local_48;
      fStack_54 = local_44;
      fStack_50 = local_40;
      local_9c = fStack_a8;
      fStack_98 = fStack_a4;
      fStack_94 = local_ac;
      local_8c = fStack_a4;
      fStack_80 = fStack_a4;
      local_7c = local_ac;
      fStack_78 = fStack_a8;
      local_6c = fStack_a8;
      fStack_64 = local_ac;
      if (((ppVar5->physents[num].angles[0] != 0.0) || (ppVar5->physents[num].angles[1] != 0.0)) ||
         (ppVar5->physents[num].angles[2] != 0.0)) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
        in_stack_fffffe98 = &local_30;
        AngleVectorsTranspose(ppVar5->physents[num].angles,in_stack_fffffe98,&local_24,&local_18);
        fVar14 = fStack_a8 * local_14;
        fVar9 = local_ac * local_24;
        fVar10 = local_ac * local_18;
        fVar6 = fStack_a0 * local_24;
        fVar7 = fStack_a0 * local_18;
        fVar8 = fStack_94 * local_24;
        local_ac = local_ac * local_30 + fStack_a8 * local_2c + fStack_a4 * local_28;
        fStack_a8 = fVar9 + fStack_a8 * local_20 + fStack_a4 * local_1c;
        fStack_a4 = fVar10 + fVar14 + fStack_a4 * local_10;
        fStack_a0 = fStack_a0 * local_30 + local_9c * local_2c + fStack_98 * local_28;
        fVar13 = local_9c * local_14;
        fVar11 = fStack_90 * local_14;
        fVar12 = fStack_84 * local_14;
        fVar9 = fStack_94 * local_18;
        fVar10 = fStack_88 * local_24;
        fVar14 = fStack_88 * local_18;
        local_9c = fVar6 + local_9c * local_20 + fStack_98 * local_1c;
        fStack_98 = fVar7 + fVar13 + fStack_98 * local_10;
        fStack_94 = fStack_94 * local_30 + fStack_90 * local_2c + local_8c * local_28;
        fStack_90 = fVar8 + fStack_90 * local_20 + local_8c * local_1c;
        local_8c = fVar9 + fVar11 + local_8c * local_10;
        fStack_88 = fStack_88 * local_30 + fStack_84 * local_2c + fStack_80 * local_28;
        fStack_84 = fVar10 + fStack_84 * local_20 + fStack_80 * local_1c;
        fStack_80 = fVar14 + fVar12 + fStack_80 * local_10;
        fVar9 = local_7c * local_24;
        fVar7 = local_7c * local_18;
        fVar8 = fStack_78 * local_14;
        fVar10 = fStack_70 * local_24;
        fVar14 = fStack_70 * local_18;
        fVar6 = fStack_64 * local_24;
        local_7c = local_7c * local_30 + fStack_78 * local_2c + fStack_74 * local_28;
        fStack_78 = fVar9 + fStack_78 * local_20 + fStack_74 * local_1c;
        fStack_74 = fVar7 + fVar8 + fStack_74 * local_10;
        fStack_70 = fStack_70 * local_30 + local_6c * local_2c + fStack_68 * local_28;
        fVar8 = local_6c * local_14;
        fVar9 = fStack_64 * local_18;
        local_24 = fStack_58 * local_24;
        local_18 = fStack_58 * local_18;
        fVar7 = fStack_60 * local_14;
        local_14 = fStack_54 * local_14;
        local_6c = fVar10 + local_6c * local_20 + fStack_68 * local_1c;
        fStack_68 = fVar14 + fVar8 + fStack_68 * local_10;
        fStack_64 = fStack_64 * local_30 + fStack_60 * local_2c + local_5c * local_28;
        fStack_60 = fVar6 + fStack_60 * local_20 + local_5c * local_1c;
        local_5c = fVar9 + fVar7 + local_5c * local_10;
        fStack_58 = fStack_58 * local_30 + fStack_54 * local_2c + fStack_50 * local_28;
        fStack_54 = local_24 + fStack_54 * local_20 + fStack_50 * local_1c;
        fStack_50 = local_18 + local_14 + fStack_50 * local_10;
      }
      local_9c = local_9c + fVar2;
      fStack_98 = fStack_98 + fVar3;
      fStack_94 = fStack_94 + fVar1;
      fStack_90 = fStack_90 + fVar2;
      local_ac = local_ac + fVar1;
      fStack_a8 = fStack_a8 + fVar2;
      fStack_a4 = fStack_a4 + fVar3;
      fStack_a0 = fStack_a0 + fVar1;
      local_8c = local_8c + fVar3;
      fStack_88 = fStack_88 + fVar1;
      fStack_84 = fStack_84 + fVar2;
      fStack_80 = fStack_80 + fVar3;
      local_6c = fVar2 + local_6c;
      fStack_68 = fVar3 + fStack_68;
      fStack_64 = fVar1 + fStack_64;
      fStack_60 = fVar2 + fStack_60;
      local_5c = fVar3 + local_5c;
      fStack_58 = fVar1 + fStack_58;
      fStack_54 = fVar2 + fStack_54;
      fStack_50 = fVar3 + fStack_50;
      local_7c = fVar1 + local_7c;
      fStack_78 = fVar2 + fStack_78;
      fStack_74 = fVar3 + fStack_74;
      fStack_70 = fVar1 + fStack_70;
    }
    PM_ParticleLine(&local_7c,&local_ac,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&local_ac,&fStack_94,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_94,&fStack_64,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_64,&local_7c,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_a0,&local_ac,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&local_ac,&local_7c,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&local_7c,&fStack_70,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_70,&fStack_a0,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_94,&local_ac,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&local_ac,&fStack_a0,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_a0,&fStack_88,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_88,&fStack_94,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_70,&fStack_58,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_58,&fStack_88,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_88,&fStack_a0,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_a0,&fStack_70,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_88,&fStack_58,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_58,&fStack_64,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_64,&fStack_94,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_94,&fStack_88,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_64,&fStack_58,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_58,&fStack_70,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&fStack_70,&local_7c,pcolor,life,(float)in_stack_fffffe98);
    PM_ParticleLine(&local_7c,&fStack_64,pcolor,life,(float)in_stack_fffffe98);
  }
  return;
}


// PM_DrawBBox  @ 00176220  (line 221)

void PM_DrawBBox(vec_t *mins,vec_t *maxs,vec_t *origin,int pcolor,float life)

{
  float in_stack_ffffff88;
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
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: float gap@[???] */
  local_68 = maxs[1] + 0.0 + origin[1];
  local_64 = maxs[2] + 0.0 + origin[2];
  local_6c = *maxs + 0.0 + *origin;
  local_60 = *mins + *origin;
  local_50 = origin[1] + mins[1];
  local_34 = mins[2] + origin[2];
  local_5c = local_68;
  local_58 = local_64;
  local_54 = local_6c;
  local_4c = local_64;
  local_48 = local_60;
  local_44 = local_50;
  local_40 = local_64;
  local_3c = local_6c;
  local_38 = local_68;
  local_30 = local_60;
  local_2c = local_68;
  local_28 = local_34;
  local_24 = local_6c;
  local_20 = local_50;
  local_1c = local_34;
  local_18 = local_60;
  local_14 = local_50;
  local_10 = local_34;
  PM_ParticleLine(&local_3c,&local_6c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_6c,&local_54,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_54,&local_24,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_24,&local_3c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_60,&local_6c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_6c,&local_3c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_3c,&local_30,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_30,&local_60,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_54,&local_6c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_6c,&local_60,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_60,&local_48,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_48,&local_54,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_30,&local_18,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_18,&local_48,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_48,&local_60,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_60,&local_30,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_48,&local_18,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_18,&local_24,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_24,&local_54,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_54,&local_48,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_24,&local_18,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_18,&local_30,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_30,&local_3c,pcolor,life,in_stack_ffffff88);
  PM_ParticleLine(&local_3c,&local_24,pcolor,life,in_stack_ffffff88);
  return;
}


// PM_ViewEntity  @ 001764c0  (line 263)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_ViewEntity(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  model_s *pmVar4;
  playermove_t *ppVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  pmtrace_t *forward;
  float local_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  float local_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float local_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  float local_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float local_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  pmtrace_t local_d0;
  float local_8c;
  float local_88;
  float local_84;
  float local_7c;
  float local_78;
  float local_74;
  float local_6c;
  float local_68;
  float local_64;
  vec_t local_60 [3];
  vec_t local_54 [2];
  pmtrace_t local_4c;
  
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: float raydist@[???]
                       Unresolved local var: vec3_t origin@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: pmtrace_t trace@[???]
                       Unresolved local var: int pcolor@[???]
                       Unresolved local var: float fup@[???] */
  AngleVectors(pmove->angles,&local_8c,local_60,local_54);
  forward = &local_d0;
  local_7c = pmove->origin[0];
  local_78 = pmove->origin[1];
  local_74 = pmove->origin[2];
  local_6c = local_8c * 256.0 + local_7c;
  local_68 = local_88 * 256.0 + local_78;
  local_64 = local_84 * 256.0 + local_74;
  (*pmove->PM_PlayerTrace)(forward,&local_7c,&local_6c,2,-1);
  ppVar5 = pmove;
                    /* Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: float gap@[???]
                       Unresolved local var: vec3_t modelmins@[???]
                       Unresolved local var: vec3_t modelmaxs@[???]
                       Unresolved local var: vec3_t tmp@[???] */
  if ((0 < (int)local_d0.plane.dist) && ((int)local_d0.plane.dist < pmove->numphysent)) {
    pmVar4 = pmove->physents[(int)local_d0.plane.dist].model;
    if (pmVar4 == (model_s *)0x0) {
      fStack_13c = pmove->physents[(int)local_d0.plane.dist].maxs[1] +
                   pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_138 = pmove->physents[(int)local_d0.plane.dist].maxs[2] +
                   pmove->physents[(int)local_d0.plane.dist].origin[2];
      local_140 = pmove->physents[(int)local_d0.plane.dist].maxs[0] +
                  pmove->physents[(int)local_d0.plane.dist].origin[0];
      local_130 = pmove->physents[(int)local_d0.plane.dist].maxs[1] +
                  pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_12c = pmove->physents[(int)local_d0.plane.dist].maxs[2] +
                   pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_134 = pmove->physents[(int)local_d0.plane.dist].mins[0] +
                   pmove->physents[(int)local_d0.plane.dist].origin[0];
      fStack_124 = pmove->physents[(int)local_d0.plane.dist].mins[1] +
                   pmove->physents[(int)local_d0.plane.dist].origin[1];
      local_120 = pmove->physents[(int)local_d0.plane.dist].maxs[2] +
                  pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_128 = pmove->physents[(int)local_d0.plane.dist].maxs[0] +
                   pmove->physents[(int)local_d0.plane.dist].origin[0];
      fStack_118 = pmove->physents[(int)local_d0.plane.dist].mins[1] +
                   pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_114 = pmove->physents[(int)local_d0.plane.dist].maxs[2] +
                   pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_11c = pmove->physents[(int)local_d0.plane.dist].mins[0] +
                   pmove->physents[(int)local_d0.plane.dist].origin[0];
      fStack_10c = pmove->physents[(int)local_d0.plane.dist].maxs[1] +
                   pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_108 = pmove->physents[(int)local_d0.plane.dist].mins[2] +
                   pmove->physents[(int)local_d0.plane.dist].origin[2];
      local_110 = pmove->physents[(int)local_d0.plane.dist].maxs[0] +
                  pmove->physents[(int)local_d0.plane.dist].origin[0];
      local_100 = pmove->physents[(int)local_d0.plane.dist].maxs[1] +
                  pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_fc = pmove->physents[(int)local_d0.plane.dist].mins[2] +
                  pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_104 = pmove->physents[(int)local_d0.plane.dist].mins[0] +
                   pmove->physents[(int)local_d0.plane.dist].origin[0];
      fStack_f4 = pmove->physents[(int)local_d0.plane.dist].mins[1] +
                  pmove->physents[(int)local_d0.plane.dist].origin[1];
      local_f0 = pmove->physents[(int)local_d0.plane.dist].mins[2] +
                 pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_f8 = pmove->physents[(int)local_d0.plane.dist].maxs[0] +
                  pmove->physents[(int)local_d0.plane.dist].origin[0];
      fStack_e8 = pmove->physents[(int)local_d0.plane.dist].mins[1] +
                  pmove->physents[(int)local_d0.plane.dist].origin[1];
      fStack_e4 = pmove->physents[(int)local_d0.plane.dist].mins[2] +
                  pmove->physents[(int)local_d0.plane.dist].origin[2];
      fStack_ec = pmove->physents[(int)local_d0.plane.dist].mins[0] +
                  pmove->physents[(int)local_d0.plane.dist].origin[0];
    }
    else {
      fVar1 = pmove->physents[(int)local_d0.plane.dist].origin[0];
      fVar2 = pmove->physents[(int)local_d0.plane.dist].origin[1];
      fVar3 = pmove->physents[(int)local_d0.plane.dist].origin[2];
      forward = &local_4c;
      (*pmove->PM_GetModelBounds)(pmVar4,(float *)forward,(float *)&local_4c.inwater);
      fStack_134 = (float)local_4c.allsolid;
      fStack_124 = (float)local_4c.startsolid;
      local_140 = (float)local_4c.inwater + 0.0;
      fStack_11c = (float)local_4c.allsolid;
      fStack_13c = local_4c.fraction + 0.0;
      fStack_118 = (float)local_4c.startsolid;
      fStack_138 = local_4c.endpos[0] + 0.0;
      fStack_108 = (float)local_4c.inopen;
      fStack_104 = (float)local_4c.allsolid;
      fStack_fc = (float)local_4c.inopen;
      fStack_f4 = (float)local_4c.startsolid;
      local_f0 = (float)local_4c.inopen;
      fStack_ec = (float)local_4c.allsolid;
      fStack_e8 = (float)local_4c.startsolid;
      fStack_e4 = (float)local_4c.inopen;
      local_130 = fStack_13c;
      fStack_12c = fStack_138;
      fStack_128 = local_140;
      local_120 = fStack_138;
      fStack_114 = fStack_138;
      local_110 = local_140;
      fStack_10c = fStack_13c;
      local_100 = fStack_13c;
      fStack_f8 = local_140;
      if (((ppVar5->physents[(int)local_d0.plane.dist].angles[0] != 0.0) ||
          (ppVar5->physents[(int)local_d0.plane.dist].angles[1] != 0.0)) ||
         (ppVar5->physents[(int)local_d0.plane.dist].angles[2] != 0.0)) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
        forward = (pmtrace_t *)(local_4c.endpos + 1);
        AngleVectorsTranspose
                  (ppVar5->physents[(int)local_d0.plane.dist].angles,(vec_t *)forward,
                   local_4c.plane.normal + 1,(vec_t *)&local_4c.ent);
        fVar14 = fStack_13c * local_4c.deltavelocity[0];
        fVar9 = local_140 * local_4c.plane.normal[1];
        fVar10 = local_140 * (float)local_4c.ent;
        fVar6 = fStack_134 * local_4c.plane.normal[1];
        fVar7 = fStack_134 * (float)local_4c.ent;
        fVar8 = fStack_128 * local_4c.plane.normal[1];
        local_140 = local_140 * local_4c.endpos[1] + fStack_13c * local_4c.endpos[2] +
                    fStack_138 * local_4c.plane.normal[0];
        fStack_13c = fVar9 + fStack_13c * local_4c.plane.normal[2] +
                     fStack_138 * local_4c.plane.dist;
        fStack_138 = fVar10 + fVar14 + fStack_138 * local_4c.deltavelocity[1];
        fStack_134 = fStack_134 * local_4c.endpos[1] + local_130 * local_4c.endpos[2] +
                     fStack_12c * local_4c.plane.normal[0];
        fVar13 = local_130 * local_4c.deltavelocity[0];
        fVar11 = fStack_124 * local_4c.deltavelocity[0];
        fVar12 = fStack_118 * local_4c.deltavelocity[0];
        fVar9 = fStack_128 * (float)local_4c.ent;
        fVar10 = fStack_11c * local_4c.plane.normal[1];
        fVar14 = fStack_11c * (float)local_4c.ent;
        local_130 = fVar6 + local_130 * local_4c.plane.normal[2] + fStack_12c * local_4c.plane.dist;
        fStack_12c = fVar7 + fVar13 + fStack_12c * local_4c.deltavelocity[1];
        fStack_128 = fStack_128 * local_4c.endpos[1] + fStack_124 * local_4c.endpos[2] +
                     local_120 * local_4c.plane.normal[0];
        fStack_124 = fVar8 + fStack_124 * local_4c.plane.normal[2] + local_120 * local_4c.plane.dist
        ;
        local_120 = fVar9 + fVar11 + local_120 * local_4c.deltavelocity[1];
        fStack_11c = fStack_11c * local_4c.endpos[1] + fStack_118 * local_4c.endpos[2] +
                     fStack_114 * local_4c.plane.normal[0];
        fStack_118 = fVar10 + fStack_118 * local_4c.plane.normal[2] +
                     fStack_114 * local_4c.plane.dist;
        fStack_114 = fVar14 + fVar12 + fStack_114 * local_4c.deltavelocity[1];
        fVar9 = local_110 * local_4c.plane.normal[1];
        fVar10 = local_110 * (float)local_4c.ent;
        fVar8 = fStack_10c * local_4c.deltavelocity[0];
        fVar14 = fStack_104 * local_4c.plane.normal[1];
        fVar6 = fStack_104 * (float)local_4c.ent;
        fVar7 = fStack_f8 * local_4c.plane.normal[1];
        local_110 = local_110 * local_4c.endpos[1] + fStack_10c * local_4c.endpos[2] +
                    fStack_108 * local_4c.plane.normal[0];
        fStack_10c = fVar9 + fStack_10c * local_4c.plane.normal[2] +
                     fStack_108 * local_4c.plane.dist;
        fStack_108 = fVar10 + fVar8 + fStack_108 * local_4c.deltavelocity[1];
        fStack_104 = fStack_104 * local_4c.endpos[1] + local_100 * local_4c.endpos[2] +
                     fStack_fc * local_4c.plane.normal[0];
        fVar11 = local_100 * local_4c.deltavelocity[0];
        fVar9 = fStack_f8 * (float)local_4c.ent;
        local_4c.plane.normal[1] = fStack_ec * local_4c.plane.normal[1];
        fVar10 = fStack_ec * (float)local_4c.ent;
        fVar8 = fStack_f4 * local_4c.deltavelocity[0];
        local_4c.deltavelocity[0] = fStack_e8 * local_4c.deltavelocity[0];
        local_100 = fVar14 + local_100 * local_4c.plane.normal[2] + fStack_fc * local_4c.plane.dist;
        fStack_fc = fVar6 + fVar11 + fStack_fc * local_4c.deltavelocity[1];
        fStack_f8 = fStack_f8 * local_4c.endpos[1] + fStack_f4 * local_4c.endpos[2] +
                    local_f0 * local_4c.plane.normal[0];
        fStack_f4 = fVar7 + fStack_f4 * local_4c.plane.normal[2] + local_f0 * local_4c.plane.dist;
        local_f0 = fVar9 + fVar8 + local_f0 * local_4c.deltavelocity[1];
        fStack_ec = fStack_ec * local_4c.endpos[1] + fStack_e8 * local_4c.endpos[2] +
                    fStack_e4 * local_4c.plane.normal[0];
        fStack_e8 = local_4c.plane.normal[1] + fStack_e8 * local_4c.plane.normal[2] +
                    fStack_e4 * local_4c.plane.dist;
        fStack_e4 = fVar10 + local_4c.deltavelocity[0] + fStack_e4 * local_4c.deltavelocity[1];
      }
      local_130 = local_130 + fVar2;
      fStack_12c = fStack_12c + fVar3;
      fStack_128 = fStack_128 + fVar1;
      fStack_124 = fStack_124 + fVar2;
      local_140 = local_140 + fVar1;
      fStack_13c = fStack_13c + fVar2;
      fStack_138 = fStack_138 + fVar3;
      fStack_134 = fStack_134 + fVar1;
      local_120 = local_120 + fVar3;
      fStack_11c = fStack_11c + fVar1;
      fStack_118 = fStack_118 + fVar2;
      fStack_114 = fStack_114 + fVar3;
      local_100 = fVar2 + local_100;
      fStack_fc = fVar3 + fStack_fc;
      fStack_f8 = fVar1 + fStack_f8;
      fStack_f4 = fVar2 + fStack_f4;
      local_f0 = fVar3 + local_f0;
      fStack_ec = fVar1 + fStack_ec;
      fStack_e8 = fVar2 + fStack_e8;
      fStack_e4 = fVar3 + fStack_e4;
      local_110 = fVar1 + local_110;
      fStack_10c = fVar2 + fStack_10c;
      fStack_108 = fVar3 + fStack_108;
      fStack_104 = fVar1 + fStack_104;
    }
    PM_ParticleLine(&local_110,&local_140,0x6f,0.3,(float)forward);
    PM_ParticleLine(&local_140,&fStack_128,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_128,&fStack_f8,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_f8,&local_110,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_134,&local_140,0x6f,0.3,(float)forward);
    PM_ParticleLine(&local_140,&local_110,0x6f,0.3,(float)forward);
    PM_ParticleLine(&local_110,&fStack_104,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_104,&fStack_134,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_128,&local_140,0x6f,0.3,(float)forward);
    PM_ParticleLine(&local_140,&fStack_134,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_134,&fStack_11c,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_11c,&fStack_128,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_104,&fStack_ec,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_ec,&fStack_11c,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_11c,&fStack_134,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_134,&fStack_104,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_11c,&fStack_ec,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_ec,&fStack_f8,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_f8,&fStack_128,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_128,&fStack_11c,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_f8,&fStack_ec,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_ec,&fStack_104,0x6f,0.3,(float)forward);
    PM_ParticleLine(&fStack_104,&local_110,0x6f,0.3,(float)forward);
    PM_ParticleLine(&local_110,&fStack_f8,0x6f,0.3,(float)forward);
  }
  return;
}


