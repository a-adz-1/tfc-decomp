// SXDLY_CheckNewDelayVal  @ 001fc8f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SXDLY_CheckNewDelayVal(void)

{
  float fVar1;
  
                    /* Unresolved local var: dlyline_t * pdly@[???] */
  fVar1 = sxdly_delayprev;
  if (sxdly_delay.value != sxdly_delayprev) {
    if (sxdly_delay.value == 0.0) {
                    /* Unresolved local var: dlyline_t * pdly@[???] */
      fVar1 = sxdly_delay.value;
      if (rgsxdly[0].lpdelayline != (sample_t *)0x0) {
        free(rgsxdly[0].hdelayline);
        rgsxdly[0].hdelayline = (HANDLE)0x0;
        rgsxdly[0].lpdelayline = (sample_t *)0x0;
        fVar1 = sxdly_delay.value;
      }
    }
    else {
      fVar1 = 0.4;
      if (sxdly_delay.value < 0.4) {
        fVar1 = sxdly_delay.value;
      }
      rgsxdly[0].delaysamples = (int)((float)shm->speed * fVar1) << ((byte)sxhires & 0x1f);
      if ((rgsxdly[0].lpdelayline != (sample_t *)0x0) ||
         (SXDLY_Init(0,0.4), rgsxdly[0].lpdelayline != (sample_t *)0x0)) {
        Q_memset(rgsxdly[0].lpdelayline,0,rgsxdly[0].cdelaysamplesmax * 2);
        rgsxdly[0].lp1 = 0;
        rgsxdly[0].lp0 = 0;
        rgsxdly[0].lp2 = 0;
      }
      rgsxdly[0].idelayinput = 0;
      rgsxdly[0].idelayoutput = rgsxdly[0].cdelaysamplesmax - rgsxdly[0].delaysamples;
      sxdly_delayprev = sxdly_delay.value;
      fVar1 = sxdly_delayprev;
                    /* Unresolved local var: dlyline_t * pdly@[???] */
      if ((rgsxdly[0].delaysamples == 0) && (rgsxdly[0].lpdelayline != (sample_t *)0x0)) {
        free(rgsxdly[0].hdelayline);
        rgsxdly[0].hdelayline = (HANDLE)0x0;
        rgsxdly[0].lpdelayline = (sample_t *)0x0;
        fVar1 = sxdly_delayprev;
      }
    }
  }
  sxdly_delayprev = fVar1;
  rgsxdly[0].lp = (int)sxdly_lp.value;
  rgsxdly[0].delayfeed = (int)(sxdly_feedback.value * 255.0);
  return;
}


// SXDLY_CheckNewStereoDelayVal  @ 001fc530
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SXDLY_CheckNewStereoDelayVal(void)

{
  float fVar1;
  int iVar2;
  
                    /* Unresolved local var: dlyline_t * pdly@[???]
                       Unresolved local var: int delaysamples@[???] */
  fVar1 = 0.1;
  if (sxste_delay.value < 0.1) {
    fVar1 = sxste_delay.value;
  }
  iVar2 = (int)((float)shm->speed * fVar1) << ((byte)sxhires & 0x1f);
  if (rgsxdly[3].lpdelayline == (sample_t *)0x0) {
    rgsxdly[3].delaysamples = iVar2;
    SXDLY_Init(3,0.1);
  }
  if (iVar2 != rgsxdly[3].delaysamples) {
    rgsxdly[3].idelayoutputxf = rgsxdly[3].idelayinput - iVar2;
    if (rgsxdly[3].idelayoutputxf < 0) {
      rgsxdly[3].idelayoutputxf = rgsxdly[3].idelayoutputxf + rgsxdly[3].cdelaysamplesmax;
    }
    rgsxdly[3].xfade = 0x80;
  }
  rgsxdly[3].mod = 0;
  sxste_delayprev = sxste_delay.value;
  rgsxdly[3].modcur = 0;
                    /* Unresolved local var: dlyline_t * pdly@[???] */
  if ((rgsxdly[3].delaysamples == 0) && (rgsxdly[3].lpdelayline != (sample_t *)0x0)) {
    free(rgsxdly[3].hdelayline);
    rgsxdly[3].hdelayline = (HANDLE)0x0;
    rgsxdly[3].lpdelayline = (sample_t *)0x0;
    return;
  }
  return;
}


// SXDLY_CheckNewStereoDelayVal  @ 001fc670
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SXDLY_CheckNewStereoDelayVal(void)

{
                    /* Unresolved local var: dlyline_t * pdly@[???]
                       Unresolved local var: int delaysamples@[???] */
  if (sxste_delay.value == sxste_delayprev) {
    return;
  }
  if (sxste_delay.value != 0.0) {
    SXDLY_CheckNewStereoDelayVal();
    return;
  }
                    /* Unresolved local var: dlyline_t * pdly@[???] */
  if (rgsxdly[3].lpdelayline != (sample_t *)0x0) {
    free(rgsxdly[3].hdelayline);
    rgsxdly[3].hdelayline = (HANDLE)0x0;
    rgsxdly[3].lpdelayline = (sample_t *)0x0;
  }
  sxste_delayprev = 0.0;
  return;
}


// SXDLY_DoDelay  @ 001fcab0
void SXDLY_DoDelay(int count)

{
  portable_samplepair_t *ppVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int val@[???]
                       Unresolved local var: int valt@[???]
                       Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: sample_t sampledly@[???]
                       Unresolved local var: portable_samplepair_t * pbuf@[???]
                       Unresolved local var: int countr@[???] */
  if ((rgsxdly[0].lpdelayline != (sample_t *)0x0) && (count != 0)) {
    ppVar1 = paintbuffer;
    while( true ) {
      count = count + -1;
      iVar5 = ppVar1->left;
      iVar4 = ppVar1->right;
      if (((rgsxdly[0].lpdelayline[rgsxdly[0].idelayoutput] == 0) && (iVar5 == 0)) && (iVar4 == 0))
      {
        rgsxdly[0].lp1 = 0;
        rgsxdly[0].lp0 = 0;
        rgsxdly[0].lpdelayline[rgsxdly[0].idelayinput] = 0;
      }
      else {
        iVar2 = (rgsxdly[0].lpdelayline[rgsxdly[0].idelayoutput] * rgsxdly[0].delayfeed >> 8) +
                (iVar5 + iVar4 >> 1);
        if (iVar2 < -0x8000) {
          iVar2 = -0x8000;
        }
        if (0x7fff < iVar2) {
          iVar2 = 0x7fff;
        }
        iVar3 = iVar2;
        if (rgsxdly[0].lp != 0) {
          iVar3 = rgsxdly[0].lp1 + rgsxdly[0].lp0 + iVar2 * 2 >> 2;
          rgsxdly[0].lp0 = rgsxdly[0].lp1;
          rgsxdly[0].lp1 = iVar2;
        }
        rgsxdly[0].lpdelayline[rgsxdly[0].idelayinput] = (sample_t)iVar3;
        iVar5 = iVar5 + (iVar3 >> 2);
        iVar4 = iVar4 + (iVar3 >> 2);
        if (iVar5 < -0x8000) {
          iVar5 = -0x8000;
        }
        if (iVar4 < -0x8000) {
          iVar4 = -0x8000;
        }
        if (0x7fff < iVar5) {
          iVar5 = 0x7fff;
        }
        if (0x7fff < iVar4) {
          iVar4 = 0x7fff;
        }
        ppVar1->left = iVar5;
        ppVar1->right = iVar4;
      }
      rgsxdly[0].idelayinput = rgsxdly[0].idelayinput + 1;
      if (rgsxdly[0].cdelaysamplesmax <= rgsxdly[0].idelayinput) {
        rgsxdly[0].idelayinput = 0;
      }
      rgsxdly[0].idelayoutput = rgsxdly[0].idelayoutput + 1;
      if (rgsxdly[0].cdelaysamplesmax <= rgsxdly[0].idelayoutput) {
        rgsxdly[0].idelayoutput = 0;
      }
      if (count == 0) break;
      ppVar1 = ppVar1 + 1;
    }
  }
  return;
}


// SXDLY_DoStereoDelay  @ 001fc6f0
void SXDLY_DoStereoDelay(int count)

{
  int32 iVar1;
  short sVar2;
  int iVar3;
  portable_samplepair_t *ppVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_28;
  int local_24;
  
                    /* Unresolved local var: int left@[???]
                       Unresolved local var: sample_t sampledly@[???]
                       Unresolved local var: sample_t samplexf@[???]
                       Unresolved local var: portable_samplepair_t * pbuf@[???]
                       Unresolved local var: int countr@[???] */
  if ((rgsxdly[3].lpdelayline != (sample_t *)0x0) && (count != 0)) {
    local_24 = count;
    ppVar4 = paintbuffer;
    do {
      iVar3 = rgsxdly[3].idelayoutput;
      if ((rgsxdly[3].mod != 0) &&
         (rgsxdly[3].modcur = rgsxdly[3].modcur + -1, rgsxdly[3].modcur < 0)) {
        rgsxdly[3].modcur = rgsxdly[3].mod;
      }
      iVar7 = ppVar4->left;
      iVar6 = (int)rgsxdly[3].lpdelayline[rgsxdly[3].idelayoutput];
      if ((iVar6 != 0) || (rgsxdly[3].xfade != 0)) {
        if (rgsxdly[3].xfade == 0) goto LAB_001fc850;
LAB_001fc7c0:
        local_28 = rgsxdly[3].idelayoutputxf;
        sVar2 = (short)((0x80 - rgsxdly[3].xfade) *
                        (int)rgsxdly[3].lpdelayline[rgsxdly[3].idelayoutputxf] >> 7);
        iVar5 = rgsxdly[3].xfade + -1;
LAB_001fc7eb:
        rgsxdly[3].idelayoutputxf = local_28 + 1;
        iVar6 = (int)(short)((short)(iVar6 * rgsxdly[3].xfade >> 7) + sVar2);
        if (rgsxdly[3].cdelaysamplesmax <= rgsxdly[3].idelayoutputxf) {
          rgsxdly[3].idelayoutputxf = 0;
        }
        iVar3 = rgsxdly[3].idelayoutputxf;
        rgsxdly[3].xfade = iVar5;
        if (iVar5 != 0) {
          iVar3 = rgsxdly[3].idelayoutput;
        }
LAB_001fc824:
        rgsxdly[3].idelayoutput = iVar3;
        if (iVar7 < -0x8000) {
          iVar7 = -0x8000;
        }
        if (0x7fff < iVar7) {
          iVar7 = 0x7fff;
        }
        rgsxdly[3].lpdelayline[rgsxdly[3].idelayinput] = (sample_t)iVar7;
        ppVar4->left = iVar6;
      }
      else {
        if (iVar7 != 0) {
LAB_001fc850:
          if ((rgsxdly[3].modcur == 0) && (rgsxdly[3].mod != 0)) {
            iVar1 = RandomLong(0,0xff);
            iVar3 = (iVar1 * rgsxdly[3].delaysamples >> 9) + iVar3;
            iVar5 = 0x7f;
            local_28 = iVar3 - rgsxdly[3].cdelaysamplesmax;
            if (iVar3 < rgsxdly[3].cdelaysamplesmax) {
              local_28 = iVar3;
            }
            sVar2 = 0;
            rgsxdly[3].xfade = 0x80;
            goto LAB_001fc7eb;
          }
          if (rgsxdly[3].xfade != 0) goto LAB_001fc7c0;
          goto LAB_001fc824;
        }
        rgsxdly[3].lpdelayline[rgsxdly[3].idelayinput] = 0;
      }
      rgsxdly[3].idelayinput = rgsxdly[3].idelayinput + 1;
      if (rgsxdly[3].cdelaysamplesmax <= rgsxdly[3].idelayinput) {
        rgsxdly[3].idelayinput = 0;
      }
      iVar3 = rgsxdly[3].idelayoutput + 1;
      rgsxdly[3].idelayoutput = 0;
      if (iVar3 < rgsxdly[3].cdelaysamplesmax) {
        rgsxdly[3].idelayoutput = iVar3;
      }
      ppVar4 = ppVar4 + 1;
      local_24 = local_24 + -1;
    } while (local_24 != 0);
  }
  return;
}


// SXDLY_Free  @ 001fc630
void SXDLY_Free(int idelay)

{
                    /* Unresolved local var: dlyline_t * pdly@[???] */
  if (rgsxdly[idelay].lpdelayline != (sample_t *)0x0) {
    free(rgsxdly[idelay].hdelayline);
    rgsxdly[idelay].hdelayline = (HANDLE)0x0;
    rgsxdly[idelay].lpdelayline = (sample_t *)0x0;
  }
  return;
}


// SXDLY_Init  @ 001fc3d0
qboolean SXDLY_Init(int idelay,float delay)

{
  int iVar1;
  float fVar2;
  size_t __size;
  qboolean qVar3;
  int iVar4;
  sample_t *dest;
  
                    /* Unresolved local var: int cbsamples@[DW_OP_reg7(EDI)]
                       Unresolved local var: HANDLE hData@[???]
                       Unresolved local var: HPSTR lpData@[???]
                       Unresolved local var: dlyline_t * pdly@[???] */
  fVar2 = 0.4;
  if (delay <= 0.4) {
    fVar2 = delay;
  }
  if (rgsxdly[idelay].lpdelayline != (sample_t *)0x0) {
    free(rgsxdly[idelay].hdelayline);
    rgsxdly[idelay].hdelayline = (HANDLE)0x0;
    rgsxdly[idelay].lpdelayline = (sample_t *)0x0;
  }
  qVar3 = true;
  if (fVar2 != 0.0) {
    iVar4 = ((int)((float)shm->speed * fVar2) << ((byte)sxhires & 0x1f)) + 1;
    __size = iVar4 * 2;
    rgsxdly[idelay].cdelaysamplesmax = iVar4;
    dest = malloc(__size);
    if (dest == (sample_t *)0x0) {
      Con_SafePrintf("Sound FX: Out of memory.\n");
      qVar3 = false;
    }
    else {
      Q_memset(dest,0,__size);
      iVar4 = rgsxdly[idelay].delaysamples;
      rgsxdly[idelay].hdelayline = dest;
      rgsxdly[idelay].lpdelayline = dest;
      rgsxdly[idelay].idelayinput = 0;
      iVar1 = rgsxdly[idelay].cdelaysamplesmax;
      rgsxdly[idelay].xfade = 0;
      rgsxdly[idelay].lp = 1;
      rgsxdly[idelay].mod = 0;
      rgsxdly[idelay].idelayoutput = iVar1 - iVar4;
      qVar3 = true;
      rgsxdly[idelay].modcur = 0;
      rgsxdly[idelay].lp2 = 0;
      rgsxdly[idelay].lp1 = 0;
      rgsxdly[idelay].lp0 = 0;
    }
  }
  return qVar3;
}


