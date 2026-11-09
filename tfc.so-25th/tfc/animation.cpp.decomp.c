// Ghidra decompilation of functions from tfc/animation.cpp
// 15 functions, ordered by original source line

// ExtractBbox  @ 0006df60  (line 52)

int ExtractBbox(void *pmodel,int sequence,float *mins,float *maxs)

{
  int iVar1;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
  if (pmodel != (void *)0x0) {
    iVar1 = sequence * 0xb0 + *(int *)((int)pmodel + 0xa8);
    *mins = *(float *)((int)pmodel + iVar1 + 0x60);
    mins[1] = *(float *)((int)pmodel + iVar1 + 100);
    mins[2] = *(float *)((int)pmodel + iVar1 + 0x68);
    *maxs = *(float *)((int)pmodel + iVar1 + 0x6c);
    maxs[1] = *(float *)((int)pmodel + iVar1 + 0x70);
    maxs[2] = *(float *)((int)pmodel + iVar1 + 0x74);
    return 1;
  }
  return 0;
}


// LookupActivity  @ 0006dfe0  (line 76)

int LookupActivity(void *pmodel,entvars_t *pev,int activity)

{
  int iVar1;
  int iVar2;
  int32 iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: int weighttotal@[???]
                       Unresolved local var: int seq@[???] */
  if (pmodel == (void *)0x0) {
    return 0;
  }
                    /* Unresolved local var: int i@[???] */
  iVar2 = *(int *)((int)pmodel + 0xa4);
  if (iVar2 < 1) {
    iVar4 = -1;
  }
  else {
    iVar6 = *(int *)((int)pmodel + 0xa8) + (int)pmodel;
    iVar7 = 0;
    iVar5 = -1;
    iVar1 = 0;
    do {
      while (iVar4 = iVar1, *(int *)(iVar6 + 0x28) != activity) {
LAB_0006e020:
        iVar6 = iVar6 + 0xb0;
        iVar1 = iVar4 + 1;
        if (iVar2 <= iVar4 + 1) {
          return iVar5;
        }
      }
      iVar7 = iVar7 + *(int *)(iVar6 + 0x2c);
      if (iVar7 != 0) {
        iVar3 = (*g_engfuncs.pfnRandomLong)(0,iVar7 + -1);
        iVar2 = *(int *)((int)pmodel + 0xa4);
        if (*(int *)(iVar6 + 0x2c) <= iVar3) goto LAB_0006e020;
      }
      iVar6 = iVar6 + 0xb0;
      iVar5 = iVar4;
      iVar1 = iVar4 + 1;
    } while (iVar4 + 1 < iVar2);
  }
  return iVar4;
}


// LookupActivityHeaviest  @ 0006e0a0  (line 104)

int LookupActivityHeaviest(void *pmodel,entvars_t *pev,int activity)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: int weight@[???]
                       Unresolved local var: int seq@[???] */
  if (pmodel == (void *)0x0) {
    return 0;
  }
                    /* Unresolved local var: int i@[???] */
  iVar2 = *(int *)((int)pmodel + 0xa4);
  if (iVar2 < 1) {
    iVar4 = -1;
  }
  else {
    iVar6 = (int)pmodel + *(int *)((int)pmodel + 0xa8);
    iVar4 = -1;
    iVar3 = 0;
    iVar7 = 0;
    do {
      while ((iVar5 = iVar3, *(int *)(iVar6 + 0x28) == activity &&
             (piVar1 = (int *)(iVar6 + 0x2c), iVar7 < *piVar1))) {
        iVar6 = iVar6 + 0xb0;
        iVar4 = iVar5;
        iVar3 = iVar5 + 1;
        iVar7 = *piVar1;
        if (iVar5 + 1 == iVar2) {
          return iVar5;
        }
      }
      iVar6 = iVar6 + 0xb0;
      iVar3 = iVar5 + 1;
    } while (iVar5 + 1 != iVar2);
  }
  return iVar4;
}


// GetEyePosition  @ 0006e110  (line 133)

void GetEyePosition(void *pmodel,float *vecEyePosition)

{
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???] */
  if (pmodel != (void *)0x0) {
    *vecEyePosition = *(float *)((int)pmodel + 0x4c);
    vecEyePosition[1] = *(float *)((int)pmodel + 0x50);
    vecEyePosition[2] = *(float *)((int)pmodel + 0x54);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0006e152. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_engfuncs.pfnAlertMessage)(at_console,"GetEyePosition() Can\'t get pstudiohdr ptr!\n");
  return;
}


// LookupSequence  @ 0006e160  (line 148)

int LookupSequence(void *pmodel,char *label)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__s1;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
  if (pmodel == (void *)0x0) {
    return 0;
  }
                    /* Unresolved local var: int i@[???] */
  iVar1 = *(int *)((int)pmodel + 0xa4);
  if (0 < iVar1) {
    __s1 = (char *)((int)pmodel + *(int *)((int)pmodel + 0xa8));
    iVar3 = 0;
    do {
      iVar2 = strcasecmp(__s1,label);
      if (iVar2 == 0) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      __s1 = __s1 + 0xb0;
    } while (iVar3 != iVar1);
  }
  return -1;
}


// IsSoundEvent  @ 0006e1e0  (line 170)

int IsSoundEvent(int eventNumber)

{
  return (uint)((eventNumber - 0x3ecU & 0xfffffffb) == 0);
}


// SequencePrecache  @ 0006e200  (line 178)

void SequencePrecache(void *pmodel,char *pSequenceName)

{
  char *pcVar1;
  _func_int_char_ptr *p_Var2;
  int iVar3;
  int iVar4;
  char *__s1;
  int iVar5;
  char *pcVar6;
  
                    /* Unresolved local var: int index@[???] */
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
  if (pmodel != (void *)0x0) {
                    /* Unresolved local var: int i@[???] */
    iVar4 = *(int *)((int)pmodel + 0xa4);
    if (0 < iVar4) {
      __s1 = (char *)(*(int *)((int)pmodel + 0xa8) + (int)pmodel);
      iVar5 = 0;
      do {
        iVar3 = strcasecmp(__s1,pSequenceName);
        if (iVar3 == 0) {
          if (iVar5 < 0) {
            return;
          }
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: mstudioevent_t * pevent@[???] */
          if (iVar4 <= iVar5) {
            return;
          }
                    /* Unresolved local var: int i@[???] */
          iVar4 = *(int *)(__s1 + 0x30);
          if (iVar4 < 1) {
            return;
          }
          pcVar6 = (char *)((int)pmodel + *(int *)(__s1 + 0x34) + 0xc);
          iVar5 = 0;
          do {
            iVar3 = *(int *)(pcVar6 + -8);
            if ((iVar3 < 5000) && ((iVar3 - 0x3ecU & 0xfffffffb) == 0)) {
              if (*pcVar6 == '\0') {
                (*g_engfuncs.pfnAlertMessage)
                          (at_error,"Bad sound event %d in sequence %s :: %s (sound is \"%s\")\n",
                           iVar3,(int)pmodel + 8,pSequenceName,pcVar6);
              }
              p_Var2 = g_engfuncs.pfnPrecacheSound;
              pcVar1 = gpGlobals->pStringBase;
              iVar4 = (*g_engfuncs.pfnAllocString)(pcVar6);
              (*p_Var2)(pcVar1 + iVar4);
              iVar4 = *(int *)(__s1 + 0x30);
            }
            iVar5 = iVar5 + 1;
            pcVar6 = pcVar6 + 0x4c;
          } while (iVar5 < iVar4);
          return;
        }
        iVar5 = iVar5 + 1;
        __s1 = __s1 + 0xb0;
      } while (iVar5 != iVar4);
    }
  }
  return;
}


// GetSequenceInfo  @ 0006e320  (line 218)

void GetSequenceInfo(void *pmodel,entvars_t *pev,float *pflFrameRate,float *pflGroundSpeed)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
  if (pmodel != (void *)0x0) {
    if (*(int *)((int)pmodel + 0xa4) <= pev->sequence) {
      *pflFrameRate = 0.0;
      *pflGroundSpeed = 0.0;
      return;
    }
    iVar4 = pev->sequence * 0xb0 + *(int *)((int)pmodel + 0xa8);
    iVar3 = *(int *)((int)pmodel + iVar4 + 0x38);
    if (1 < iVar3) {
      *pflFrameRate = (*(float *)((int)pmodel + iVar4 + 0x20) * 256.0) / (float)(iVar3 + -1);
      fVar1 = *(float *)((int)pmodel + iVar4 + 0x4c);
      fVar5 = *(float *)((int)pmodel + iVar4 + 0x50);
      fVar2 = *(float *)((int)pmodel + iVar4 + 0x54);
      fVar1 = fVar2 * fVar2 + fVar5 * fVar5 + fVar1 * fVar1;
      fVar5 = SQRT(fVar1);
      if (NAN(fVar5)) {
        fVar5 = sqrtf(fVar1);
      }
      *pflGroundSpeed = fVar5;
      *pflGroundSpeed =
           (fVar5 * *(float *)((int)pmodel + iVar4 + 0x20)) /
           (float)(*(int *)((int)pmodel + iVar4 + 0x38) + -1);
      return;
    }
    *pflFrameRate = 256.0;
    *pflGroundSpeed = 0.0;
  }
  return;
}


// GetSequenceFlags  @ 0006e400  (line 251)

int GetSequenceFlags(void *pmodel,entvars_t *pev)

{
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???] */
  if ((pmodel != (void *)0x0) && (pev->sequence < *(int *)((int)pmodel + 0xa4))) {
    return *(int *)((int)pmodel + *(int *)((int)pmodel + 0xa8) + pev->sequence * 0xb0 + 0x24);
  }
  return 0;
}


// GetAnimationEvent  @ 0006e440  (line 309)

int GetAnimationEvent(void *pmodel,entvars_t *pev,MonsterEvent_t *pMonsterEvent,float flStart,
                     float flEnd,int index)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  int iVar7;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: int events@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: mstudioevent_t * pevent@[???] */
  if (((pmodel != (void *)0x0) && (pev->sequence < *(int *)((int)pmodel + 0xa4))) &&
     (pMonsterEvent != (MonsterEvent_t *)0x0)) {
    iVar7 = pev->sequence * 0xb0 + *(int *)((int)pmodel + 0xa8);
    iVar1 = *(int *)((int)pmodel + iVar7 + 0x30);
    if ((index <= iVar1) && (iVar1 != 0)) {
      iVar2 = *(int *)((int)pmodel + iVar7 + 0x38);
      if (iVar2 < 2) {
        fVar3 = 1.0;
        fVar4 = 0.0;
      }
      else {
        fVar3 = (float)(iVar2 + -1) * 0.00390625;
        fVar4 = fVar3 * flStart;
        fVar3 = fVar3 * flEnd;
      }
      if (index < iVar1) {
        piVar6 = (int *)((int)pmodel + *(int *)((int)pmodel + iVar7 + 0x34) + index * 0x4c);
        do {
          if ((piVar6[1] < 5000) &&
             (((fVar5 = (float)*piVar6, fVar4 <= fVar5 && (fVar5 < fVar3)) ||
              (((*(byte *)((int)pmodel + iVar7 + 0x24) & 1) != 0 &&
               (((float)(iVar2 + -1) <= fVar3 && (fVar5 < (fVar3 - (float)iVar2) + 1.0)))))))) {
            pMonsterEvent->event = piVar6[1];
            pMonsterEvent->options = (char *)(piVar6 + 3);
            return index + 1;
          }
          index = index + 1;
          piVar6 = piVar6 + 0x13;
        } while (iVar1 != index);
      }
    }
  }
  return 0;
}


// SetController  @ 0006e5c0  (line 356)

float SetController(void *pmodel,entvars_t *pev,int iController,float flValue)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudiobonecontroller_t * pbonecontroller@[???]
                       Unresolved local var: int setting@[???] */
  if ((pmodel != (void *)0x0) && (iController < *(int *)((int)pmodel + 0x94))) {
    iVar4 = *(int *)((int)pmodel + 0x98) + iController * 0x18;
    fVar1 = *(float *)((int)pmodel + iVar4 + 0xc);
    fVar2 = *(float *)((int)pmodel + iVar4 + 8);
    if ((*(byte *)((int)pmodel + iVar4 + 4) & 0x38) != 0) {
      if (fVar1 < fVar2) {
        flValue = -flValue;
      }
      if (fVar2 + 359.0 < fVar1) {
        if (flValue <= 360.0) {
          if (flValue < 0.0) {
            flValue = (float)(int)(flValue / -360.0 + 1.0) * 360.0 + flValue;
          }
        }
        else {
          flValue = flValue - (float)(int)(flValue / 360.0) * 360.0;
        }
      }
      else {
        fVar3 = (fVar1 + fVar2) * 0.5;
        if (fVar3 + 180.0 < flValue) {
          flValue = flValue - 360.0;
        }
        if (flValue < fVar3 - 180.0) {
          flValue = flValue + 360.0;
        }
      }
    }
    iVar5 = (int)(((flValue - fVar2) * 255.0) / (fVar1 - fVar2));
    if (iVar5 < 0) {
      fVar1 = 0.0;
      bVar6 = '\0';
    }
    else if (iVar5 < 0x100) {
      bVar6 = (byte)iVar5;
      fVar1 = (float)iVar5 * 0.003921569;
    }
    else {
      fVar1 = 1.0;
      bVar6 = 0xff;
    }
    pev->controller[iController] = bVar6;
    fVar2 = *(float *)((int)pmodel + iVar4 + 8);
    flValue = fVar2 + (*(float *)((int)pmodel + iVar4 + 0xc) - fVar2) * fVar1;
  }
  return flValue;
}


// SetBlending  @ 0006e780  (line 404)

float SetBlending(void *pmodel,entvars_t *pev,int iBlender,float flValue)

{
  int iVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  int iVar6;
  byte bVar7;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: int setting@[???] */
  if (pmodel == (void *)0x0) {
    return flValue;
  }
  iVar1 = pev->sequence * 0xb0 + *(int *)((int)pmodel + 0xa8) + iBlender * 4;
  uVar4 = *(uint *)((int)pmodel + iVar1 + 0x80);
  if (uVar4 != 0) {
    fVar2 = *(float *)((int)pmodel + iVar1 + 0x90);
    fVar3 = *(float *)((int)pmodel + iVar1 + 0x88);
    if ((uVar4 & 0x38) != 0) {
      if (fVar2 < fVar3) {
        flValue = -flValue;
      }
      if (fVar2 <= fVar3 + 359.0) {
        fVar5 = (fVar2 + fVar3) * 0.5;
        if (fVar5 + 180.0 < flValue) {
          flValue = flValue - 360.0;
        }
        if (flValue < fVar5 - 180.0) {
          flValue = flValue + 360.0;
        }
      }
    }
    iVar6 = (int)(((flValue - fVar3) * 255.0) / (fVar2 - fVar3));
    if (iVar6 < 0) {
      fVar2 = 0.0;
      bVar7 = '\0';
    }
    else if (iVar6 < 0x100) {
      bVar7 = (byte)iVar6;
      fVar2 = (float)iVar6 * 0.003921569;
    }
    else {
      fVar2 = 1.0;
      bVar7 = 0xff;
    }
    pev->blending[iBlender] = bVar7;
    fVar3 = *(float *)((int)pmodel + iVar1 + 0x88);
    flValue = fVar3 + (*(float *)((int)pmodel + iVar1 + 0x90) - fVar3) * fVar2;
  }
  return flValue;
}


// FindTransition  @ 0006e8e0  (line 448)

/* WARNING: Variable defined which should be unmapped: iGoalAnim */

int FindTransition(void *pmodel,int iEndingAnim,int iGoalAnim,int *piDir)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudioseqdesc_t * pseqdesc@[???]
                       Unresolved local var: int iEndNode@[???]
                       Unresolved local var: byte * pTransition@[???]
                       Unresolved local var: int iInternNode@[???]
                       Unresolved local var: int i@[???] */
  if (pmodel == (void *)0x0) {
    return iGoalAnim;
  }
  iVar2 = *(int *)((int)pmodel + 0xa8);
  iVar1 = iEndingAnim * 0xb0 + iVar2;
  uVar3 = *(uint *)((int)pmodel + iVar1 + 0xa0);
  if ((uVar3 != 0) && (uVar5 = *(uint *)((int)pmodel + iGoalAnim * 0xb0 + iVar2 + 0xa0), uVar5 != 0)
     ) {
    if (0 < *piDir) {
      uVar3 = *(uint *)((int)pmodel + iVar1 + 0xa4);
    }
    if (uVar3 == uVar5) {
      *piDir = 1;
    }
    else {
      uVar5 = (uint)*(byte *)((int)pmodel +
                             *(int *)((int)pmodel + 0xf0) +
                             (uVar3 - 1) * *(int *)((int)pmodel + 0xec) + uVar5 + -1);
      if (uVar5 != 0) {
        if (0 < *(int *)((int)pmodel + 0xa4)) {
          puVar4 = (uint *)((int)pmodel + iVar2 + 0xa4);
          iVar2 = 0;
          do {
            if ((uVar3 == puVar4[-1]) && (uVar5 == *puVar4)) {
              *piDir = 1;
              return iVar2;
            }
            if (((puVar4[1] != 0) && (*puVar4 == uVar3)) && (uVar5 == puVar4[-1])) {
              *piDir = -1;
              return iVar2;
            }
            iVar2 = iVar2 + 1;
            puVar4 = puVar4 + 0x2c;
          } while (iVar2 != *(int *)((int)pmodel + 0xa4));
        }
        (*g_engfuncs.pfnAlertMessage)(at_console,"error in transition graph");
        return iGoalAnim;
      }
    }
  }
  return iGoalAnim;
}


// SetBodygroup  @ 0006ea20  (line 515)

void SetBodygroup(void *pmodel,entvars_t *pev,int iGroup,int iValue)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudiobodyparts_t * pbodypart@[???]
                       Unresolved local var: int iCurrent@[???] */
  if ((pmodel != (void *)0x0) && (iGroup <= *(int *)((int)pmodel + 0xcc))) {
    iVar2 = *(int *)((int)pmodel + 0xd0) + iGroup * 0x4c;
    iVar1 = *(int *)((int)pmodel + iVar2 + 0x40);
    if (iValue < iVar1) {
      iVar2 = *(int *)((int)pmodel + iVar2 + 0x44);
      pev->body = iVar2 * iValue + (pev->body - ((pev->body / iVar2) % iVar1) * iVar2);
    }
  }
  return;
}


// GetBodygroup  @ 0006eaa0  (line 537)

int GetBodygroup(void *pmodel,entvars_t *pev,int iGroup)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: studiohdr_t * pstudiohdr@[???]
                       Unresolved local var: mstudiobodyparts_t * pbodypart@[???]
                       Unresolved local var: int iCurrent@[???] */
  iVar3 = 0;
  if ((pmodel != (void *)0x0) && (iGroup <= *(int *)((int)pmodel + 0xcc))) {
    iVar2 = *(int *)((int)pmodel + 0xd0) + iGroup * 0x4c;
    iVar1 = *(int *)((int)pmodel + iVar2 + 0x40);
    if (1 < iVar1) {
      iVar3 = (pev->body / *(int *)((int)pmodel + iVar2 + 0x44)) % iVar1;
    }
  }
  return iVar3;
}


