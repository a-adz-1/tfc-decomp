// Ghidra decompilation of functions from pm_shared/pm_debug.c
// 6 functions, ordered by original source line

// PM_ShowClipBox  @ 000ac640  (line 30)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_ShowClipBox(void)

{
  return;
}


// PM_ParticleLine  @ 000ac650  (line 85)

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
  if (0.0 <= fVar2) {
    fVar1 = 0.0;
    do {
      local_34 = local_28 * fVar1 + *start;
      local_30 = local_24 * fVar1 + start[1];
      local_2c = fVar1 * local_20 + start[2];
      (*pmove->PM_Particle)(&local_34,pcolor,life,0,(int)vert);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
  return;
}


// PM_DrawRectangle  @ 000ac720  (line 117)

void PM_DrawRectangle(vec_t *tl,vec_t *bl,vec_t *tr,vec_t *br,int pcolor,float life)

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
  local_28 = *bl - *tl;
  local_24 = bl[1] - tl[1];
  local_20 = bl[2] - tl[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *tl;
      local_30 = local_24 * fVar1 + tl[1];
      local_2c = fVar1 * local_20 + tl[2];
      (*pmove->PM_Particle)(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
  local_28 = *br - *bl;
  local_24 = br[1] - bl[1];
  local_20 = br[2] - bl[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *bl;
      local_30 = local_24 * fVar1 + bl[1];
      local_2c = fVar1 * local_20 + bl[2];
      (*pmove->PM_Particle)(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
  local_28 = *tr - *br;
  local_24 = tr[1] - br[1];
  local_20 = tr[2] - br[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *br;
      local_30 = local_24 * fVar1 + br[1];
      local_2c = fVar1 * local_20 + br[2];
      (*pmove->PM_Particle)(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
  local_28 = *tl - *tr;
  local_24 = tl[1] - tr[1];
  local_20 = tl[2] - tr[2];
  fVar2 = VectorNormalize(&local_28);
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    do {
      local_34 = local_28 * fVar1 + *tr;
      local_30 = local_24 * fVar1 + tr[1];
      local_2c = fVar1 * local_20 + tr[2];
      (*pmove->PM_Particle)(&local_34,pcolor,life,0,0);
      fVar1 = fVar1 + 2.0;
    } while (fVar1 <= fVar2);
  }
  return;
}


// PM_DrawPhysEntBBox  @ 000aca60  (line 131)

void PM_DrawPhysEntBBox(int num,int pcolor,float life)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  model_s *pmVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  playermove_t *ppVar12;
  int *piVar13;
  int *piVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  int *local_10c;
  vec_t *local_dc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c [4];
  float local_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float local_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float local_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float local_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float local_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  
                    /* Unresolved local var: physent_t.conflict * pe@[???]
                       Unresolved local var: vec3_t org@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: float gap@[???]
                       Unresolved local var: vec3_t modelmins@[???]
                       Unresolved local var: vec3_t modelmaxs@[???] */
  ppVar12 = pmove;
  if ((num < pmove->numphysent) && (0 < num)) {
    pmVar7 = pmove->physents[num].model;
    if (pmVar7 != (model_s *)0x0) {
      fVar5 = pmove->physents[num].origin[0];
      fVar26 = pmove->physents[num].origin[1];
      fVar6 = pmove->physents[num].origin[2];
      (*pmove->PM_GetModelBounds)(pmVar7,&local_b8,&local_ac);
      local_7c[0] = local_ac + 0.0;
      local_7c[1] = local_a8 + 0.0;
      local_7c[2] = local_a4 + 0.0;
      local_7c[3] = local_b8;
      fStack_60 = local_b4;
      fStack_58 = local_b8;
      fStack_54 = local_b4;
      fStack_44 = local_b0;
      fStack_40 = local_b8;
      fStack_38 = local_b0;
      fStack_30 = local_b4;
      local_2c = local_b0;
      fStack_28 = local_b8;
      fStack_24 = local_b4;
      fStack_20 = local_b0;
      local_6c = local_7c[1];
      fStack_68 = local_7c[2];
      fStack_64 = local_7c[0];
      local_5c = local_7c[2];
      fStack_50 = local_7c[2];
      local_4c = local_7c[0];
      fStack_48 = local_7c[1];
      local_3c = local_7c[1];
      fStack_34 = local_7c[0];
      if (((ppVar12->physents[num].angles[0] != 0.0) || (ppVar12->physents[num].angles[1] != 0.0))
         || (ppVar12->physents[num].angles[2] != 0.0)) {
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???] */
        AngleVectorsTranspose(ppVar12->physents[num].angles,&fStack_a0,&local_94,&local_88);
        fVar24 = local_7c[0] * local_94;
        fVar25 = local_7c[0] * local_88;
        fVar21 = local_7c[1] * local_84;
        fVar15 = local_7c[3] * local_94;
        fVar16 = local_7c[3] * local_88;
        fVar17 = fStack_64 * local_94;
        local_7c[0] = local_7c[2] * fStack_98 + local_7c[0] * fStack_a0 + local_7c[1] * fStack_9c;
        local_7c[1] = local_7c[2] * local_8c + fVar24 + local_7c[1] * local_90;
        local_7c[2] = local_7c[2] * local_80 + fVar25 + fVar21;
        local_7c[3] = fStack_68 * fStack_98 + local_7c[3] * fStack_a0 + local_6c * fStack_9c;
        fVar21 = local_6c * local_84;
        fVar22 = local_5c * fStack_98;
        fVar23 = local_5c * local_8c;
        local_6c = fVar15 + local_6c * local_90 + fStack_68 * local_8c;
        fStack_68 = fVar16 + fVar21 + fStack_68 * local_80;
        fVar21 = fStack_54 * local_84;
        fVar15 = fStack_58 * local_94;
        fVar16 = fStack_58 * local_88;
        local_5c = fStack_64 * local_88 + fStack_60 * local_84 + local_5c * local_80;
        fStack_58 = fStack_58 * fStack_a0 + fStack_54 * fStack_9c + fStack_50 * fStack_98;
        fStack_54 = fVar15 + fStack_54 * local_90 + fStack_50 * local_8c;
        fStack_50 = fVar16 + fVar21 + fStack_50 * local_80;
        fVar24 = local_84 * fStack_48;
        fVar20 = fStack_9c * local_3c;
        fVar15 = local_94 * local_4c;
        fVar16 = local_88 * local_4c;
        fVar21 = fStack_38 * fStack_98;
        local_4c = fStack_44 * fStack_98 + fStack_9c * fStack_48 + fStack_a0 * local_4c;
        fStack_48 = fStack_44 * local_8c + local_90 * fStack_48 + fVar15;
        fStack_44 = fStack_44 * local_80 + fVar24 + fVar16;
        fVar15 = local_3c * local_84;
        fVar25 = fStack_34 * local_94;
        fVar18 = local_2c * fStack_98;
        fVar19 = local_2c * local_8c;
        local_3c = local_3c * local_90 + fStack_40 * local_94 + fStack_38 * local_8c;
        fStack_38 = fVar15 + fStack_40 * local_88 + fStack_38 * local_80;
        fVar24 = fStack_24 * local_84;
        fVar15 = fStack_28 * local_94;
        fVar16 = fStack_28 * local_88;
        local_2c = local_2c * local_80 + fStack_34 * local_88 + fStack_30 * local_84;
        fStack_28 = fStack_20 * fStack_98 + fStack_28 * fStack_a0 + fStack_24 * fStack_9c;
        fStack_24 = fStack_20 * local_8c + fVar15 + fStack_24 * local_90;
        fStack_20 = fStack_20 * local_80 + fVar16 + fVar24;
        fStack_64 = fStack_64 * fStack_a0 + fStack_60 * fStack_9c + fVar22;
        fStack_60 = fVar17 + fStack_60 * local_90 + fVar23;
        fStack_40 = fVar21 + fVar20 + fStack_a0 * fStack_40;
        fStack_34 = fStack_30 * fStack_9c + fStack_34 * fStack_a0 + fVar18;
        fStack_30 = fStack_30 * local_90 + fVar25 + fVar19;
      }
      local_dc = &local_88;
                    /* try { // try from 000ad08c to 000bd090 has its CatchHandler @ 000aef02 */
      local_10c = PM_boxpnt[0] + 3;
      local_5c = local_5c + fVar6;
      fStack_58 = fStack_58 + fVar5;
      fStack_54 = fStack_54 + fVar26;
      fStack_50 = fStack_50 + fVar6;
                    /* try { // try from 000ad0a9 to 000bd19c has its CatchHandler @ 000accb0 */
      local_6c = local_6c + fVar26;
      fStack_68 = fStack_68 + fVar6;
      fStack_64 = fStack_64 + fVar5;
      fStack_60 = fStack_60 + fVar26;
      local_7c[0] = local_7c[0] + fVar5;
      local_7c[1] = local_7c[1] + fVar26;
      local_7c[2] = local_7c[2] + fVar6;
      local_7c[3] = local_7c[3] + fVar5;
      local_3c = fVar26 + local_3c;
      fStack_38 = fVar6 + fStack_38;
      fStack_34 = fVar5 + fStack_34;
      fStack_30 = fVar26 + fStack_30;
      local_2c = local_2c + fVar6;
      fStack_28 = fStack_28 + fVar5;
      fStack_24 = fStack_24 + fVar26;
      fStack_20 = fStack_20 + fVar6;
      local_4c = fVar5 + local_4c;
      fStack_48 = fVar26 + fStack_48;
      fStack_44 = fVar6 + fStack_44;
      fStack_40 = fVar5 + fStack_40;
      do {
        iVar8 = *local_10c;
        pfVar1 = local_7c + iVar8 * 3;
        iVar9 = local_10c[-1];
        pfVar2 = local_7c + iVar9 * 3;
        iVar10 = (*(int (*) [4])(local_10c + -3))[0];
        pfVar3 = local_7c + iVar10 * 3;
        iVar11 = local_10c[-2];
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
        pfVar4 = local_7c + iVar11 * 3;
        local_88 = *pfVar3 - *pfVar4;
        local_84 = local_7c[iVar10 * 3 + 1] - local_7c[iVar11 * 3 + 1];
        local_80 = local_7c[iVar10 * 3 + 2] - local_7c[iVar11 * 3 + 2];
        fVar26 = VectorNormalize(local_dc);
        fVar5 = 0.0;
        if (0.0 <= fVar26) {
          do {
                    /* try { // try from 000ad1ba to 000bd1be has its CatchHandler @ 000aeef2 */
            local_94 = local_88 * fVar5 + *pfVar4;
            local_90 = local_84 * fVar5 + local_7c[iVar11 * 3 + 1];
                    /* try { // try from 000ad1dc to 000bd28a has its CatchHandler @ 000accb0 */
            local_8c = fVar5 * local_80 + local_7c[iVar11 * 3 + 2];
            (*pmove->PM_Particle)(&local_94,pcolor,life,0,0);
            fVar5 = fVar5 + 2.0;
          } while (fVar5 <= fVar26);
        }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
        local_88 = *pfVar1 - *pfVar3;
        local_84 = local_7c[iVar8 * 3 + 1] - local_7c[iVar10 * 3 + 1];
        local_80 = local_7c[iVar8 * 3 + 2] - local_7c[iVar10 * 3 + 2];
        fVar26 = VectorNormalize(local_dc);
        fVar5 = 0.0;
        if (0.0 <= fVar26) {
          do {
            local_94 = local_88 * fVar5 + *pfVar3;
                    /* try { // try from 000ad2b5 to 000bd2b9 has its CatchHandler @ 000aeee6 */
            local_90 = local_84 * fVar5 + local_7c[iVar10 * 3 + 1];
                    /* try { // try from 000ad2cc to 000bd404 has its CatchHandler @ 000accb0 */
            local_8c = fVar5 * local_80 + local_7c[iVar10 * 3 + 2];
            (*pmove->PM_Particle)(&local_94,pcolor,life,0,0);
            fVar5 = fVar5 + 2.0;
          } while (fVar5 <= fVar26);
        }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
        local_88 = *pfVar2 - *pfVar1;
        local_84 = local_7c[iVar9 * 3 + 1] - local_7c[iVar8 * 3 + 1];
        local_80 = local_7c[iVar9 * 3 + 2] - local_7c[iVar8 * 3 + 2];
        fVar26 = VectorNormalize(local_dc);
        fVar5 = 0.0;
        if (0.0 <= fVar26) {
          do {
            local_94 = local_88 * fVar5 + *pfVar1;
            local_90 = local_84 * fVar5 + local_7c[iVar8 * 3 + 1];
            local_8c = fVar5 * local_80 + local_7c[iVar8 * 3 + 2];
            (*pmove->PM_Particle)(&local_94,pcolor,life,0,0);
            fVar5 = fVar5 + 2.0;
          } while (fVar5 <= fVar26);
        }
                    /* Unresolved local var: float linestep@[???]
                       Unresolved local var: float curdist@[???]
                       Unresolved local var: float len@[???]
                       Unresolved local var: vec3_t curpos@[???]
                       Unresolved local var: vec3_t diff@[???]
                       Unresolved local var: int i@[???] */
        local_88 = *pfVar4 - *pfVar2;
        local_84 = local_7c[iVar11 * 3 + 1] - local_7c[iVar9 * 3 + 1];
        local_80 = local_7c[iVar11 * 3 + 2] - local_7c[iVar9 * 3 + 2];
                    /* try { // try from 000ad436 to 000bd46c has its CatchHandler @ 000aefe5 */
        fVar26 = VectorNormalize(local_dc);
        fVar5 = 0.0;
        if (0.0 <= fVar26) {
          do {
            local_94 = local_88 * fVar5 + *pfVar2;
            local_90 = local_84 * fVar5 + local_7c[iVar9 * 3 + 1];
            local_8c = fVar5 * local_80 + local_7c[iVar9 * 3 + 2];
            (*pmove->PM_Particle)(&local_94,pcolor,life,0,0);
            fVar5 = fVar5 + 2.0;
          } while (fVar5 <= fVar26);
        }
                    /* try { // try from 000ad4e3 to 000bd54a has its CatchHandler @ 000aefe5 */
        local_10c = local_10c + 4;
      } while (local_10c != (int *)0xcc1ec);
      return;
    }
    local_7c[1] = pmove->physents[num].origin[1] + pmove->physents[num].maxs[1];
    local_7c[2] = pmove->physents[num].origin[2] + pmove->physents[num].maxs[2];
    local_7c[0] = pmove->physents[num].maxs[0] + pmove->physents[num].origin[0];
    local_7c[3] = pmove->physents[num].mins[0] + pmove->physents[num].origin[0];
                    /* catch() { ... } // from try @ 000accef with catch @ 000accb0
                       catch() { ... } // from try @ 000acd89 with catch @ 000accb0
                       catch() { ... } // from try @ 000ace1b with catch @ 000accb0
                       catch() { ... } // from try @ 000aceaa with catch @ 000accb0
                       catch() { ... } // from try @ 000acf8a with catch @ 000accb0
                       catch() { ... } // from try @ 000ad02b with catch @ 000accb0
                       catch() { ... } // from try @ 000ad0a9 with catch @ 000accb0
                       catch() { ... } // from try @ 000ad1dc with catch @ 000accb0
                       catch() { ... } // from try @ 000ad2cc with catch @ 000accb0
                       catch() { ... } // from try @ 000ad568 with catch @ 000accb0
                       catch() { ... } // from try @ 000ad625 with catch @ 000accb0
                       catch() { ... } // from try @ 000ad663 with catch @ 000accb0
                       catch() { ... } // from try @ 000ad6a8 with catch @ 000accb0
                       catch() { ... } // from try @ 000ad6e3 with catch @ 000accb0
                       catch() { ... } // from try @ 000ad8df with catch @ 000accb0
                       catch() { ... } // from try @ 000ad997 with catch @ 000accb0
                       catch() { ... } // from try @ 000ad9df with catch @ 000accb0
                       catch() { ... } // from try @ 000ada1d with catch @ 000accb0
                       catch() { ... } // from try @ 000adadf with catch @ 000accb0
                       catch() { ... } // from try @ 000adbca with catch @ 000accb0
                       catch() { ... } // from try @ 000adc82 with catch @ 000accb0
                       catch() { ... } // from try @ 000adcca with catch @ 000accb0
                       catch() { ... } // from try @ 000add08 with catch @ 000accb0
                       catch() { ... } // from try @ 000addef with catch @ 000accb0
                       catch() { ... } // from try @ 000adeda with catch @ 000accb0
                       catch() { ... } // from try @ 000adf97 with catch @ 000accb0
                       catch() { ... } // from try @ 000adfd5 with catch @ 000accb0
                       catch() { ... } // from try @ 000ae01a with catch @ 000accb0
                       catch() { ... } // from try @ 000ae0f7 with catch @ 000accb0
                       catch() { ... } // from try @ 000ae26b with catch @ 000accb0
                       catch() { ... } // from try @ 000ae311 with catch @ 000accb0
                       catch() { ... } // from try @ 000ae3bb with catch @ 000accb0
                       catch() { ... } // from try @ 000ae3f9 with catch @ 000accb0
                       catch() { ... } // from try @ 000ae43e with catch @ 000accb0
                       catch() { ... } // from try @ 000ae4e3 with catch @ 000accb0
                       catch() { ... } // from try @ 000ae532 with catch @ 000accb0
                       catch() { ... } // from try @ 000ae693 with catch @ 000accb0
                       catch() { ... } // from try @ 000ae73b with catch @ 000accb0
                       catch() { ... } // from try @ 000ae779 with catch @ 000accb0
                       catch() { ... } // from try @ 000ae7be with catch @ 000accb0
                       catch() { ... } // from try @ 000ae829 with catch @ 000accb0 */
    fStack_60 = pmove->physents[num].origin[1] + pmove->physents[num].mins[1];
    fStack_44 = pmove->physents[num].origin[2] + pmove->physents[num].mins[2];
    piVar13 = PM_boxpnt[0] + 3;
    local_6c = local_7c[1];
    fStack_68 = local_7c[2];
    fStack_64 = local_7c[0];
    local_5c = local_7c[2];
    fStack_58 = local_7c[3];
    fStack_54 = fStack_60;
    fStack_50 = local_7c[2];
    local_4c = local_7c[0];
    fStack_48 = local_7c[1];
    fStack_40 = local_7c[3];
    local_3c = local_7c[1];
    fStack_38 = fStack_44;
    fStack_34 = local_7c[0];
    fStack_30 = fStack_60;
    local_2c = fStack_44;
    fStack_28 = local_7c[3];
    fStack_24 = fStack_60;
    fStack_20 = fStack_44;
    do {
      piVar14 = piVar13 + 4;
      PM_DrawRectangle(local_7c + piVar13[-2] * 3,local_7c + (*(int (*) [4])(piVar13 + -3))[0] * 3,
                       local_7c + piVar13[-1] * 3,local_7c + *piVar13 * 3,pcolor,life);
      piVar13 = piVar14;
    } while (piVar14 != (int *)0xcc1ec);
  }
  return;
}


// PM_DrawBBox  @ 000ad500  (line 221)

void PM_DrawBBox(vec_t *mins,vec_t *maxs,vec_t *origin,int pcolor,float life)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float fVar12;
  int *piVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_94;
  float fStack_90;
  float fStack_8c;
  float local_88;
  float fStack_84;
  float fStack_80;
  float afStack_7c [4];
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: vec3_t tmp@[???]
                       Unresolved local var: vec_t[8][3] p@[???]
                       Unresolved local var: float gap@[???] */
  piVar13 = PM_boxpnt[0] + 3;
  afStack_7c[1] = maxs[1] + 0.0 + origin[1];
  afStack_7c[2] = maxs[2] + 0.0 + origin[2];
  afStack_7c[0] = *maxs + 0.0 + *origin;
  afStack_7c[3] = *origin + *mins;
  fStack_6c = afStack_7c[1];
  fStack_68 = afStack_7c[2];
  fStack_60 = origin[1] + mins[1];
  fStack_64 = afStack_7c[0];
  fStack_5c = afStack_7c[2];
  fStack_58 = afStack_7c[3];
  fStack_54 = fStack_60;
  fStack_50 = afStack_7c[2];
  fStack_44 = origin[2] + mins[2];
  fStack_4c = afStack_7c[0];
  fStack_48 = afStack_7c[1];
  fStack_40 = afStack_7c[3];
  fStack_3c = afStack_7c[1];
  fStack_38 = fStack_44;
  fStack_34 = afStack_7c[0];
  fStack_30 = fStack_60;
  fStack_2c = fStack_44;
  fStack_28 = afStack_7c[3];
  fStack_24 = fStack_60;
  fStack_20 = fStack_44;
  do {
    iVar8 = *piVar13;
    iVar9 = piVar13[-1];
    iVar10 = (*(int (*) [4])(piVar13 + -3))[0];
    iVar11 = piVar13[-2];
    fVar1 = afStack_7c[iVar10 * 3];
    fVar2 = afStack_7c[iVar11 * 3];
    local_88 = fVar1 - fVar2;
    fVar3 = afStack_7c[iVar10 * 3 + 1];
    fVar16 = afStack_7c[iVar11 * 3 + 1];
    fStack_84 = fVar3 - fVar16;
    fVar4 = afStack_7c[iVar10 * 3 + 2];
    fVar5 = afStack_7c[iVar11 * 3 + 2];
    fStack_80 = fVar4 - fVar5;
    fVar14 = VectorNormalize(&local_88);
    fVar6 = 0.0;
    if (0.0 <= fVar14) {
      do {
        local_94 = local_88 * fVar6 + fVar2;
        fStack_90 = fStack_84 * fVar6 + fVar16;
        fStack_8c = fVar6 * fStack_80 + fVar5;
        (*pmove->PM_Particle)(&local_94,pcolor,life,0,0);
        fVar6 = fVar6 + 2.0;
      } while (fVar6 <= fVar14);
    }
    fVar6 = afStack_7c[iVar8 * 3];
    local_88 = fVar6 - fVar1;
    fVar14 = afStack_7c[iVar8 * 3 + 1];
    fStack_84 = fVar14 - fVar3;
    fVar7 = afStack_7c[iVar8 * 3 + 2];
    fStack_80 = fVar7 - fVar4;
    fVar15 = VectorNormalize(&local_88);
    fVar12 = 0.0;
    if (0.0 <= fVar15) {
      do {
        local_94 = local_88 * fVar12 + fVar1;
        fStack_90 = fStack_84 * fVar12 + fVar3;
        fStack_8c = fVar12 * fStack_80 + fVar4;
        (*pmove->PM_Particle)(&local_94,pcolor,life,0,0);
        fVar12 = fVar12 + 2.0;
      } while (fVar12 <= fVar15);
    }
    fVar1 = afStack_7c[iVar9 * 3];
    local_88 = fVar1 - fVar6;
    fVar3 = afStack_7c[iVar9 * 3 + 1];
    fStack_84 = fVar3 - fVar14;
    fVar4 = afStack_7c[iVar9 * 3 + 2];
    fStack_80 = fVar4 - fVar7;
    fVar15 = VectorNormalize(&local_88);
    fVar12 = 0.0;
    if (0.0 <= fVar15) {
      do {
        local_94 = local_88 * fVar12 + fVar6;
        fStack_90 = fStack_84 * fVar12 + fVar14;
        fStack_8c = fVar12 * fStack_80 + fVar7;
        (*pmove->PM_Particle)(&local_94,pcolor,life,0,0);
        fVar12 = fVar12 + 2.0;
      } while (fVar12 <= fVar15);
    }
    local_88 = fVar2 - fVar1;
    fStack_84 = fVar16 - fVar3;
    fStack_80 = fVar5 - fVar4;
    fVar16 = VectorNormalize(&local_88);
    fVar2 = 0.0;
    if (0.0 <= fVar16) {
      do {
        local_94 = local_88 * fVar2 + fVar1;
        fStack_90 = fStack_84 * fVar2 + fVar3;
        fStack_8c = fVar2 * fStack_80 + fVar4;
        (*pmove->PM_Particle)(&local_94,pcolor,life,0,0);
        fVar2 = fVar2 + 2.0;
      } while (fVar2 <= fVar16);
    }
    piVar13 = piVar13 + 4;
  } while (piVar13 != (int *)0xcc1ec);
  return;
}


// PM_ViewEntity  @ 000ad9b0  (line 263)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_ViewEntity(void)

{
  float local_8c;
  float local_88;
  float local_84;
  vec_t local_80 [3];
  vec_t local_74 [3];
  vec_t local_68;
  vec_t local_64;
  vec_t local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_t_conflict local_50;
  
                    /* Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: float raydist@[???]
                       Unresolved local var: vec3_t origin@[???]
                       Unresolved local var: vec3_t end@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: pmtrace_t.conflict trace@[???]
                       Unresolved local var: int pcolor@[???]
                       Unresolved local var: float fup@[???] */
                    /* try { // try from 000ad9c2 to 000bd9c6 has its CatchHandler @ 000af0b5 */
  AngleVectors(pmove->angles,&local_8c,local_80,local_74);
                    /* try { // try from 000ad9df to 000bd9e3 has its CatchHandler @ 000accb0 */
  local_68 = pmove->origin[0];
  local_64 = pmove->origin[1];
                    /* try { // try from 000ada05 to 000bda09 has its CatchHandler @ 000af0a5 */
  local_60 = pmove->origin[2];
  local_5c = local_8c * 256.0 + pmove->origin[0];
                    /* try { // try from 000ada1d to 000bda21 has its CatchHandler @ 000accb0 */
  local_58 = local_88 * 256.0 + pmove->origin[1];
  local_54 = local_84 * 256.0 + pmove->origin[2];
                    /* try { // try from 000ada48 to 000bda4c has its CatchHandler @ 000af045 */
  (*pmove->PM_PlayerTrace)(&local_50,&local_68,&local_5c,2,-1);
  if (0 < (int)local_50.plane.dist) {
    PM_DrawPhysEntBBox((int)local_50.plane.dist,0x6f,0.3);
  }
  return;
}


