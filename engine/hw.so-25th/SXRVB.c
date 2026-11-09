// SXRVB_CheckNewReverbVal  @ 001ab3d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SXRVB_CheckNewReverbVal(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  dlyline_t *pdVar4;
  int idelay;
  
                    /* Unresolved local var: dlyline_t * pdly@[???]
                       Unresolved local var: int delaysamples@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int mod@[???] */
  if (sxrvb_size.value != sxrvb_sizeprev) {
    sxrvb_sizeprev = sxrvb_size.value;
    if (sxrvb_size.value != 0.0) {
      idelay = 1;
      pdVar4 = rgsxdly;
      do {
        fVar2 = 0.1;
        if (sxrvb_size.value < 0.1) {
          fVar2 = sxrvb_size.value;
        }
        fVar2 = (float)shm->speed * fVar2;
        rgsxdly[1].mod = (shm->speed / 0x2b11) * 500 << ((byte)sxhires & 0x1f);
        while( true ) {
          iVar3 = (int)fVar2 << ((byte)sxhires & 0x1f);
          iVar1 = pdVar4[1].mod;
          if (pdVar4[1].lpdelayline == (sample_t *)0x0) {
            pdVar4[1].delaysamples = iVar3;
            SXDLY_Init(idelay,0.1);
          }
          pdVar4[1].mod = iVar1;
          pdVar4[1].modcur = iVar1;
          if (iVar3 != pdVar4[1].delaysamples) {
            iVar3 = pdVar4[1].idelayinput - iVar3;
            pdVar4[1].idelayoutputxf = iVar3;
            if (iVar3 < 0) {
              pdVar4[1].idelayoutputxf = iVar3 + pdVar4[1].cdelaysamplesmax;
            }
            pdVar4[1].xfade = 0x20;
          }
                    /* Unresolved local var: dlyline_t * pdly@[???] */
          if ((pdVar4[1].delaysamples == 0) && (pdVar4[1].lpdelayline != (sample_t *)0x0)) {
            free(pdVar4[1].hdelayline);
            pdVar4[1].hdelayline = (HANDLE)0x0;
            pdVar4[1].lpdelayline = (sample_t *)0x0;
          }
          idelay = idelay + 1;
          pdVar4 = pdVar4 + 1;
          if (idelay == 3) goto LAB_001ab59a;
          if (idelay != 2) break;
          fVar2 = 0.1;
          if (sxrvb_size.value * 0.71 < 0.1) {
            fVar2 = sxrvb_size.value * 0.71;
          }
          fVar2 = (float)shm->speed * fVar2;
          rgsxdly[2].mod = (shm->speed / 0x2b11) * 700 << ((byte)sxhires & 0x1f);
        }
      } while( true );
    }
                    /* Unresolved local var: dlyline_t * pdly@[???] */
    if (rgsxdly[1].lpdelayline != (sample_t *)0x0) {
      free(rgsxdly[1].hdelayline);
      rgsxdly[1].hdelayline = (HANDLE)0x0;
      rgsxdly[1].lpdelayline = (sample_t *)0x0;
    }
                    /* Unresolved local var: dlyline_t * pdly@[???] */
    if (rgsxdly[2].lpdelayline != (sample_t *)0x0) {
      free(rgsxdly[2].hdelayline);
      rgsxdly[2].hdelayline = (HANDLE)0x0;
      rgsxdly[2].lpdelayline = (sample_t *)0x0;
    }
  }
LAB_001ab59a:
  rgsxdly[1].lp = (int)sxrvb_lp.value;
  rgsxdly[2].lp = (int)sxrvb_lp.value;
  rgsxdly[1].delayfeed = (int)(sxrvb_feedback.value * 255.0);
  rgsxdly[2].delayfeed = (int)(sxrvb_feedback.value * 255.0);
  return;
}


// SXRVB_DoAMod  @ 001abac0
void SXRVB_DoAMod(int count)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  portable_samplepair_t *ppVar9;
  int local_28;
  
  fVar4 = sxmod_lowpass.value;
                    /* Unresolved local var: int valtl@[???]
                       Unresolved local var: int valtr@[???]
                       Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: portable_samplepair_t * pbuf@[???]
                       Unresolved local var: int countr@[???]
                       Unresolved local var: int fLowpass@[???]
                       Unresolved local var: int fmod@[???] */
  fVar3 = sxmod_mod.value;
  if (((sxmod_lowpass.value != 0.0) || (sxmod_mod.value != 0.0)) && (count != 0)) {
    local_28 = count;
    ppVar9 = paintbuffer;
    do {
      iVar5 = rgsxlp[6];
      iVar1 = ppVar9->left;
      iVar2 = ppVar9->right;
      iVar6 = iVar2;
      iVar8 = iVar1;
      if (fVar4 != 0.0) {
        iVar6 = rgsxlp[1] + rgsxlp[0] + rgsxlp[2] + rgsxlp[3] + rgsxlp[4];
        rgsxlp[4] = rgsxlp[5];
        iVar7 = rgsxlp[6] + rgsxlp[5];
        rgsxlp[0] = rgsxlp[1];
        rgsxlp[1] = rgsxlp[2];
        rgsxlp[2] = rgsxlp[3];
        rgsxlp[6] = rgsxlp[7];
        iVar8 = iVar6 + iVar1 >> 2;
        iVar6 = iVar7 + rgsxlp[7] + rgsxlp[8] + rgsxlp[9] + iVar2 >> 2;
        rgsxlp[5] = iVar5;
        rgsxlp[7] = rgsxlp[8];
        rgsxlp[3] = iVar1;
        rgsxlp[8] = iVar2;
        rgsxlp[9] = iVar2;
      }
      if (fVar3 != 0.0) {
        sxmod1cur = sxmod1cur + -1;
        if (sxmod1cur < 0) {
          sxmod1cur = sxmod1;
        }
        if (sxmod1 == 0) {
          sxamodlt = RandomLong(0x20,0xff);
        }
        iVar1 = sxmod2cur + -1;
        sxmod2cur = sxmod2;
        if (-1 < iVar1) {
          sxmod2cur = iVar1;
        }
        if (sxmod2 == 0) {
          sxamodlt = RandomLong(0x20,0xff);
        }
        iVar8 = iVar8 * sxamodl >> 8;
        iVar6 = iVar6 * sxamodr >> 8;
        if (sxamodl < sxamodlt) {
          sxamodl = sxamodl + 1;
        }
        else if (sxamodlt < sxamodl) {
          sxamodl = sxamodl + -1;
        }
        if (sxamodr < sxamodrt) {
          sxamodr = sxamodr + 1;
        }
        else if (sxamodrt < sxamodr) {
          sxamodr = sxamodr + -1;
        }
      }
      if (iVar8 < -0x8000) {
        iVar8 = -0x8000;
      }
      if (iVar6 < -0x8000) {
        iVar6 = -0x8000;
      }
      if (0x7fff < iVar8) {
        iVar8 = 0x7fff;
      }
      if (0x7fff < iVar6) {
        iVar6 = 0x7fff;
      }
      ppVar9->left = iVar8;
      ppVar9->right = iVar6;
      local_28 = local_28 + -1;
      ppVar9 = ppVar9 + 1;
    } while (local_28 != 0);
  }
  return;
}


// SXRVB_DoReverb  @ 001ab610
void SXRVB_DoReverb(int count)

{
  short *psVar1;
  int iVar2;
  int32 iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_3c;
  portable_samplepair_t *local_38;
  int local_2c;
  int local_20;
  
                    /* Unresolved local var: int val@[???]
                       Unresolved local var: int valt@[???]
                       Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: sample_t sampledly@[???]
                       Unresolved local var: sample_t samplexf@[???]
                       Unresolved local var: portable_samplepair_t * pbuf@[???]
                       Unresolved local var: int countr@[???]
                       Unresolved local var: int voutm@[???]
                       Unresolved local var: int vlr@[???] */
  if ((rgsxdly[1].lpdelayline == (sample_t *)0x0) || (count == 0)) {
    return;
  }
  local_2c = 0;
  local_38 = paintbuffer;
  do {
    iVar5 = rgsxdly[1].idelayoutput;
    iVar4 = local_38->left;
    iVar2 = local_38->right;
    local_3c = iVar4 + iVar2 >> 1;
    rgsxdly[1].modcur = rgsxdly[1].modcur + -1;
    if (rgsxdly[1].modcur < 0) {
      rgsxdly[1].modcur = rgsxdly[1].mod;
    }
    iVar6 = (int)rgsxdly[1].lpdelayline[rgsxdly[1].idelayoutput];
    if (rgsxdly[1].xfade == 0) {
      if ((iVar2 != 0 || iVar4 != 0) || (iVar6 != 0)) {
        if (rgsxdly[1].mod == 0) {
          iVar3 = RandomLong(0,0xff);
          rgsxdly[1].idelayoutputxf = (iVar3 * rgsxdly[1].delaysamples >> 9) + iVar5;
          if (rgsxdly[1].cdelaysamplesmax <= rgsxdly[1].idelayoutputxf) {
            rgsxdly[1].idelayoutputxf = rgsxdly[1].idelayoutputxf - rgsxdly[1].cdelaysamplesmax;
          }
          iVar7 = 0x1f;
          rgsxdly[1].xfade = 0x20;
          iVar5 = 0;
          goto LAB_001ab82b;
        }
        goto LAB_001ab869;
      }
      rgsxdly[1].lp0 = 0;
      rgsxdly[1].lpdelayline[rgsxdly[1].idelayinput] = 0;
      iVar5 = 0;
    }
    else {
      iVar5 = 0x20 - rgsxdly[1].xfade;
      iVar7 = rgsxdly[1].xfade + -1;
LAB_001ab82b:
      psVar1 = rgsxdly[1].lpdelayline + rgsxdly[1].idelayoutputxf;
      rgsxdly[1].idelayoutputxf = rgsxdly[1].idelayoutputxf + 1;
      iVar6 = (int)(short)((short)(iVar6 * rgsxdly[1].xfade >> 5) + (short)(iVar5 * *psVar1 >> 5));
      if (rgsxdly[1].cdelaysamplesmax <= rgsxdly[1].idelayoutputxf) {
        rgsxdly[1].idelayoutputxf = 0;
      }
      iVar5 = rgsxdly[1].idelayoutputxf;
      rgsxdly[1].xfade = iVar7;
      if (iVar7 != 0) {
        iVar5 = rgsxdly[1].idelayoutput;
      }
LAB_001ab869:
      rgsxdly[1].idelayoutput = iVar5;
      iVar7 = local_3c;
      if (iVar6 != 0) {
        iVar7 = (rgsxdly[1].delayfeed * iVar6 >> 8) + local_3c;
        if (iVar7 < -0x8000) {
          iVar7 = -0x8000;
        }
        if (0x7fff < iVar7) {
          iVar7 = 0x7fff;
        }
      }
      iVar5 = iVar7;
      if (rgsxdly[1].lp != 0) {
        iVar5 = rgsxdly[1].lp0 + iVar7 >> 1;
        rgsxdly[1].lp0 = iVar7;
      }
      rgsxdly[1].lpdelayline[rgsxdly[1].idelayinput] = (sample_t)iVar5;
    }
    iVar6 = rgsxdly[2].idelayoutput;
    rgsxdly[1].idelayinput = rgsxdly[1].idelayinput + 1;
    if (rgsxdly[1].cdelaysamplesmax <= rgsxdly[1].idelayinput) {
      rgsxdly[1].idelayinput = 0;
    }
    rgsxdly[1].idelayoutput = rgsxdly[1].idelayoutput + 1;
    if (rgsxdly[1].cdelaysamplesmax <= rgsxdly[1].idelayoutput) {
      rgsxdly[1].idelayoutput = 0;
    }
    rgsxdly[2].modcur = rgsxdly[2].modcur + -1;
    if (rgsxdly[2].modcur < 0) {
      rgsxdly[2].modcur = rgsxdly[2].mod;
    }
    if (rgsxdly[2].lpdelayline != (sample_t *)0x0) {
      iVar7 = (int)rgsxdly[2].lpdelayline[rgsxdly[2].idelayoutput];
      if (rgsxdly[2].xfade == 0) {
        if ((iVar4 != 0 || iVar2 != 0) || (iVar7 != 0)) {
          if (rgsxdly[2].mod == 0) {
            iVar3 = RandomLong(0,0xff);
            rgsxdly[2].idelayoutputxf = iVar6 + (iVar3 * rgsxdly[2].delaysamples >> 9);
            if (rgsxdly[2].cdelaysamplesmax <= rgsxdly[2].idelayoutputxf) {
              rgsxdly[2].idelayoutputxf = rgsxdly[2].idelayoutputxf - rgsxdly[2].cdelaysamplesmax;
            }
            rgsxdly[2].xfade = 0x20;
            local_20 = 0x1f;
            iVar6 = 0;
            goto LAB_001ab94e;
          }
          goto LAB_001ab98f;
        }
        rgsxdly[2].lp0 = 0;
        rgsxdly[2].lpdelayline[rgsxdly[2].idelayinput] = 0;
      }
      else {
        iVar6 = 0x20 - rgsxdly[2].xfade;
        local_20 = rgsxdly[2].xfade + -1;
LAB_001ab94e:
        psVar1 = rgsxdly[2].lpdelayline + rgsxdly[2].idelayoutputxf;
        rgsxdly[2].idelayoutputxf = rgsxdly[2].idelayoutputxf + 1;
        iVar7 = (int)(short)((short)(iVar7 * rgsxdly[2].xfade >> 5) + (short)(iVar6 * *psVar1 >> 5))
        ;
        if (rgsxdly[2].cdelaysamplesmax <= rgsxdly[2].idelayoutputxf) {
          rgsxdly[2].idelayoutputxf = 0;
        }
        iVar6 = rgsxdly[2].idelayoutputxf;
        if (local_20 != 0) {
          iVar6 = rgsxdly[2].idelayoutput;
        }
        rgsxdly[2].xfade = local_20;
        rgsxdly[2].idelayoutput = iVar6;
LAB_001ab98f:
        iVar6 = rgsxdly[2].lp0;
        if (iVar7 != 0) {
          local_3c = (iVar7 * rgsxdly[2].delayfeed >> 8) + local_3c;
          if (local_3c < -0x8000) {
            local_3c = -0x8000;
          }
          if (0x7fff < local_3c) {
            local_3c = 0x7fff;
          }
        }
        if (rgsxdly[2].lp != 0) {
          rgsxdly[2].lp0 = local_3c;
          local_3c = iVar6 + local_3c >> 1;
        }
        iVar5 = iVar5 + local_3c;
        rgsxdly[2].lpdelayline[rgsxdly[2].idelayinput] = (sample_t)local_3c;
      }
      rgsxdly[2].idelayinput = rgsxdly[2].idelayinput + 1;
      if (rgsxdly[2].cdelaysamplesmax <= rgsxdly[2].idelayinput) {
        rgsxdly[2].idelayinput = 0;
      }
      rgsxdly[2].idelayoutput = rgsxdly[2].idelayoutput + 1;
      if (rgsxdly[2].cdelaysamplesmax <= rgsxdly[2].idelayoutput) {
        rgsxdly[2].idelayoutput = 0;
      }
    }
    iVar5 = iVar5 * 0xb >> 6;
    iVar4 = iVar4 + iVar5;
    iVar5 = iVar5 + iVar2;
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
    local_38->right = iVar5;
    local_38->left = iVar4;
    if (count + -1 == local_2c) {
      return;
    }
    local_2c = local_2c + 1;
    local_38 = local_38 + 1;
  } while( true );
}


