// SXDLY_CheckNewDelayVal  @ 001ab0c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SXDLY_CheckNewDelayVal(void)

{
  float fVar1;
  
                    /* Unresolved local var: dlyline_t * pdly@[???] */
  if (sxdly_delay.value != sxdly_delayprev) {
    if (sxdly_delay.value == 0.0) {
                    /* Unresolved local var: dlyline_t * pdly@[???] */
      if (rgsxdly[0].lpdelayline != (sample_t *)0x0) {
        free(rgsxdly[0].hdelayline);
        rgsxdly[0].hdelayline = (HANDLE)0x0;
        rgsxdly[0].lpdelayline = (sample_t *)0x0;
      }
      sxdly_delayprev = sxdly_delay.value;
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
      sxdly_delayprev = sxdly_delay.value;
      rgsxdly[0].idelayoutput = rgsxdly[0].cdelaysamplesmax - rgsxdly[0].delaysamples;
                    /* Unresolved local var: dlyline_t * pdly@[???] */
      if ((rgsxdly[0].delaysamples == 0) && (rgsxdly[0].lpdelayline != (sample_t *)0x0)) {
        free(rgsxdly[0].hdelayline);
        rgsxdly[0].hdelayline = (HANDLE)0x0;
        rgsxdly[0].lpdelayline = (sample_t *)0x0;
      }
    }
  }
  rgsxdly[0].lp = (int)sxdly_lp.value;
  rgsxdly[0].delayfeed = (int)(sxdly_feedback.value * 255.0);
  return;
}


// SXDLY_CheckNewStereoDelayVal  @ 001aad60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SXDLY_CheckNewStereoDelayVal(void)

{
  float fVar1;
  int iVar2;
  
                    /* Unresolved local var: dlyline_t * pdly@[???]
                       Unresolved local var: int delaysamples@[???] */
  if (sxste_delay.value != sxste_delayprev) {
    if (sxste_delay.value == 0.0) {
                    /* Unresolved local var: dlyline_t * pdly@[???] */
      if (rgsxdly[3].lpdelayline != (sample_t *)0x0) {
        free(rgsxdly[3].hdelayline);
        rgsxdly[3].hdelayline = (HANDLE)0x0;
        rgsxdly[3].lpdelayline = (sample_t *)0x0;
      }
      sxste_delayprev = 0.0;
    }
    else {
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
      sxste_delayprev = sxste_delay.value;
      rgsxdly[3].mod = 0;
      rgsxdly[3].modcur = 0;
                    /* Unresolved local var: dlyline_t * pdly@[???] */
      if ((rgsxdly[3].delaysamples == 0) && (rgsxdly[3].lpdelayline != (sample_t *)0x0)) {
        free(rgsxdly[3].hdelayline);
        rgsxdly[3].hdelayline = (HANDLE)0x0;
        rgsxdly[3].lpdelayline = (sample_t *)0x0;
        return;
      }
    }
  }
  return;
}


// SXDLY_DoDelay  @ 001ab250
void SXDLY_DoDelay(int count)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  portable_samplepair_t *ppVar6;
  int local_14;
  
                    /* Unresolved local var: int val@[???]
                       Unresolved local var: int valt@[???]
                       Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: sample_t sampledly@[???]
                       Unresolved local var: portable_samplepair_t * pbuf@[???]
                       Unresolved local var: int countr@[???] */
  if ((rgsxdly[0].lpdelayline != (sample_t *)0x0) && (count != 0)) {
    ppVar6 = paintbuffer;
    while( true ) {
      iVar1 = rgsxdly[0].lp0;
      local_14 = count + -1;
      iVar5 = ppVar6->right;
      iVar4 = ppVar6->left;
      if ((iVar5 == 0 && iVar4 == 0) && (rgsxdly[0].lpdelayline[rgsxdly[0].idelayoutput] == 0)) {
        rgsxdly[0].lp1 = 0;
        rgsxdly[0].lp0 = 0;
        rgsxdly[0].lpdelayline[rgsxdly[0].idelayinput] = 0;
      }
      else {
        iVar2 = (rgsxdly[0].lpdelayline[rgsxdly[0].idelayoutput] * rgsxdly[0].delayfeed >> 8) +
                (iVar4 + iVar5 >> 1);
        if (iVar2 < -0x8000) {
          iVar2 = -0x8000;
        }
        if (0x7fff < iVar2) {
          iVar2 = 0x7fff;
        }
        iVar3 = iVar2;
        if (rgsxdly[0].lp != 0) {
          rgsxdly[0].lp0 = rgsxdly[0].lp1;
          iVar3 = iVar1 + rgsxdly[0].lp1 + iVar2 * 2 >> 2;
          rgsxdly[0].lp1 = iVar2;
        }
        rgsxdly[0].lpdelayline[rgsxdly[0].idelayinput] = (sample_t)iVar3;
        iVar4 = iVar4 + (iVar3 >> 2);
        iVar5 = iVar5 + (iVar3 >> 2);
        if (iVar4 < -0x8000) {
          iVar4 = -0x8000;
        }
        if (iVar5 < -0x8000) {
          iVar5 = -0x8000;
        }
        if (0x7fff < iVar4) {
          iVar4 = 0x7fff;
        }
        if (0x7fff < iVar5) {
          iVar5 = 0x7fff;
        }
        ppVar6->left = iVar4;
        ppVar6->right = iVar5;
      }
      rgsxdly[0].idelayinput = rgsxdly[0].idelayinput + 1;
      if (rgsxdly[0].cdelaysamplesmax <= rgsxdly[0].idelayinput) {
        rgsxdly[0].idelayinput = 0;
      }
      rgsxdly[0].idelayoutput = rgsxdly[0].idelayoutput + 1;
      if (rgsxdly[0].cdelaysamplesmax <= rgsxdly[0].idelayoutput) {
        rgsxdly[0].idelayoutput = 0;
      }
      if (count == 1) break;
      ppVar6 = ppVar6 + 1;
      count = local_14;
    }
  }
  return;
}


// SXDLY_DoStereoDelay  @ 001aaec0
void SXDLY_DoStereoDelay(int count)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int32 iVar4;
  int iVar5;
  int iVar6;
  int local_2c;
  int local_20;
  
                    /* Unresolved local var: int left@[???]
                       Unresolved local var: sample_t sampledly@[???]
                       Unresolved local var: sample_t samplexf@[???]
                       Unresolved local var: portable_samplepair_t * pbuf@[???]
                       Unresolved local var: int countr@[???] */
  if ((rgsxdly[3].lpdelayline == (sample_t *)0x0) || (count == 0)) {
    return;
  }
  iVar5 = 0;
  do {
    iVar3 = rgsxdly[3].idelayoutput;
    if ((rgsxdly[3].mod != 0) && (rgsxdly[3].modcur = rgsxdly[3].modcur + -1, rgsxdly[3].modcur < 0)
       ) {
      rgsxdly[3].modcur = rgsxdly[3].mod;
    }
    iVar6 = (int)rgsxdly[3].lpdelayline[rgsxdly[3].idelayoutput];
    iVar2 = paintbuffer[iVar5].left;
    if (rgsxdly[3].xfade == 0) {
      if ((iVar6 != 0) || (iVar2 != 0)) {
        if ((rgsxdly[3].modcur == 0) && (rgsxdly[3].mod != 0)) {
          iVar4 = RandomLong(0,0xff);
          rgsxdly[3].idelayoutputxf = (iVar4 * rgsxdly[3].delaysamples >> 9) + iVar3;
          if (rgsxdly[3].cdelaysamplesmax <= rgsxdly[3].idelayoutputxf) {
            rgsxdly[3].idelayoutputxf = rgsxdly[3].idelayoutputxf - rgsxdly[3].cdelaysamplesmax;
          }
          local_20 = 0x7f;
          rgsxdly[3].xfade = 0x80;
          local_2c = 0;
          goto LAB_001aafa1;
        }
        goto LAB_001aafe0;
      }
      rgsxdly[3].lpdelayline[rgsxdly[3].idelayinput] = 0;
    }
    else {
      local_2c = 0x80 - rgsxdly[3].xfade;
      local_20 = rgsxdly[3].xfade + -1;
LAB_001aafa1:
      psVar1 = rgsxdly[3].lpdelayline + rgsxdly[3].idelayoutputxf;
      rgsxdly[3].idelayoutputxf = rgsxdly[3].idelayoutputxf + 1;
      iVar6 = (int)(short)((short)(rgsxdly[3].xfade * iVar6 >> 7) + (short)(*psVar1 * local_2c >> 7)
                          );
      if (rgsxdly[3].cdelaysamplesmax <= rgsxdly[3].idelayoutputxf) {
        rgsxdly[3].idelayoutputxf = 0;
      }
      rgsxdly[3].xfade = local_20;
      if (local_20 == 0) {
        rgsxdly[3].idelayoutput = rgsxdly[3].idelayoutputxf;
      }
LAB_001aafe0:
      iVar3 = -0x8000;
      if (-0x8001 < iVar2) {
        iVar3 = iVar2;
      }
      if (0x7fff < iVar3) {
        iVar3 = 0x7fff;
      }
      rgsxdly[3].lpdelayline[rgsxdly[3].idelayinput] = (sample_t)iVar3;
      paintbuffer[iVar5].left = iVar6;
    }
    rgsxdly[3].idelayinput = rgsxdly[3].idelayinput + 1;
    if (rgsxdly[3].cdelaysamplesmax <= rgsxdly[3].idelayinput) {
      rgsxdly[3].idelayinput = 0;
    }
    rgsxdly[3].idelayoutput = rgsxdly[3].idelayoutput + 1;
    if (rgsxdly[3].cdelaysamplesmax <= rgsxdly[3].idelayoutput) {
      rgsxdly[3].idelayoutput = 0;
    }
    if (iVar5 == count + -1) {
      return;
    }
    iVar5 = iVar5 + 1;
  } while( true );
}


// SXDLY_Free  @ 001aad20
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


// SXDLY_Init  @ 001aab90
qboolean SXDLY_Init(int idelay,float delay)

{
  int iVar1;
  size_t __size;
  int iVar2;
  sample_t *dest;
  
                    /* Unresolved local var: int cbsamples@[DW_OP_reg6(ESI)]
                       Unresolved local var: HANDLE hData@[???]
                       Unresolved local var: HPSTR lpData@[???]
                       Unresolved local var: dlyline_t * pdly@[???] */
  if (0.4 < delay) {
    delay = 0.4;
    if (rgsxdly[idelay].lpdelayline == (sample_t *)0x0) goto LAB_001aac48;
LAB_001aabd1:
    free(rgsxdly[idelay].hdelayline);
    rgsxdly[idelay].hdelayline = (HANDLE)0x0;
    rgsxdly[idelay].lpdelayline = (sample_t *)0x0;
  }
  else if (rgsxdly[idelay].lpdelayline != (sample_t *)0x0) goto LAB_001aabd1;
  if (delay == 0.0) {
    return true;
  }
LAB_001aac48:
  iVar2 = ((int)((float)shm->speed * delay) << ((byte)sxhires & 0x1f)) + 1;
  __size = iVar2 * 2;
  rgsxdly[idelay].cdelaysamplesmax = iVar2;
  dest = malloc(__size);
  if (dest == (sample_t *)0x0) {
    Con_SafePrintf("Sound FX: Out of memory.\n");
  }
  else {
    Q_memset(dest,0,__size);
    iVar2 = rgsxdly[idelay].cdelaysamplesmax;
    iVar1 = rgsxdly[idelay].delaysamples;
    rgsxdly[idelay].hdelayline = dest;
    rgsxdly[idelay].lpdelayline = dest;
    rgsxdly[idelay].idelayinput = 0;
    rgsxdly[idelay].idelayoutput = iVar2 - iVar1;
    rgsxdly[idelay].xfade = 0;
    rgsxdly[idelay].lp = 1;
    rgsxdly[idelay].mod = 0;
    rgsxdly[idelay].modcur = 0;
    rgsxdly[idelay].lp2 = 0;
    rgsxdly[idelay].lp1 = 0;
    rgsxdly[idelay].lp0 = 0;
  }
  return (uint)(dest != (sample_t *)0x0);
}


