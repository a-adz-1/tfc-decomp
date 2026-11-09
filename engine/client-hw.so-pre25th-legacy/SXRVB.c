// SXRVB_CheckNewReverbVal  @ 001fcc20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SXRVB_CheckNewReverbVal(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: dlyline_t * pdly@[???]
                       Unresolved local var: int delaysamples@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int mod@[???] */
  if (sxrvb_size.value != sxrvb_sizeprev) {
    sxrvb_sizeprev = sxrvb_size.value;
    if (sxrvb_size.value == 0.0) {
                    /* Unresolved local var: dlyline_t * pdly@[???] */
      if (rgsxdly[1].lpdelayline != (sample_t *)0x0) {
        free(rgsxdly[1].hdelayline);
        rgsxdly[1].hdelayline = (HANDLE)0x0;
        rgsxdly[1].lpdelayline = (sample_t *)0x0;
      }
    }
    else {
      fVar1 = 0.1;
      if (sxrvb_size.value < 0.1) {
        fVar1 = sxrvb_size.value;
      }
      iVar2 = (int)((float)shm->speed * fVar1) << ((byte)sxhires & 0x1f);
      iVar3 = (shm->speed / 0x2b11) * 500 << ((byte)sxhires & 0x1f);
      if (rgsxdly[1].lpdelayline == (sample_t *)0x0) {
        rgsxdly[1].delaysamples = iVar2;
        rgsxdly[1].mod = iVar3;
        SXDLY_Init(1,0.1);
      }
      if (rgsxdly[1].delaysamples != iVar2) {
        rgsxdly[1].idelayoutputxf = rgsxdly[1].idelayinput - iVar2;
        if (rgsxdly[1].idelayoutputxf < 0) {
          rgsxdly[1].idelayoutputxf = rgsxdly[1].idelayoutputxf + rgsxdly[1].cdelaysamplesmax;
        }
        rgsxdly[1].xfade = 0x20;
      }
      rgsxdly[1].mod = iVar3;
      rgsxdly[1].modcur = iVar3;
      if ((rgsxdly[1].delaysamples == 0) && (rgsxdly[1].lpdelayline != (sample_t *)0x0)) {
        free(rgsxdly[1].hdelayline);
        rgsxdly[1].hdelayline = (HANDLE)0x0;
        rgsxdly[1].lpdelayline = (sample_t *)0x0;
      }
      fVar1 = 0.1;
      if (sxrvb_size.value * 0.71 < 0.1) {
        fVar1 = sxrvb_size.value * 0.71;
      }
      iVar2 = (int)((float)shm->speed * fVar1) << ((byte)sxhires & 0x1f);
      iVar3 = (shm->speed / 0x2b11) * 700 << ((byte)sxhires & 0x1f);
      if (rgsxdly[2].lpdelayline == (sample_t *)0x0) {
        rgsxdly[2].delaysamples = iVar2;
        rgsxdly[2].mod = iVar3;
        SXDLY_Init(2,0.1);
      }
      if (rgsxdly[2].delaysamples != iVar2) {
        rgsxdly[2].idelayoutputxf = rgsxdly[2].idelayinput - iVar2;
        if (rgsxdly[2].idelayoutputxf < 0) {
          rgsxdly[2].idelayoutputxf = rgsxdly[2].idelayoutputxf + rgsxdly[2].cdelaysamplesmax;
        }
        rgsxdly[2].xfade = 0x20;
      }
      rgsxdly[2].mod = iVar3;
      rgsxdly[2].modcur = iVar3;
      if (rgsxdly[2].delaysamples != 0) goto LAB_001fcda0;
    }
                    /* Unresolved local var: dlyline_t * pdly@[???] */
    if (rgsxdly[2].lpdelayline != (sample_t *)0x0) {
      free(rgsxdly[2].hdelayline);
      rgsxdly[2].hdelayline = (HANDLE)0x0;
      rgsxdly[2].lpdelayline = (sample_t *)0x0;
    }
  }
LAB_001fcda0:
  rgsxdly[1].lp = (int)sxrvb_lp.value;
  rgsxdly[2].lp = (int)sxrvb_lp.value;
  rgsxdly[1].delayfeed = (int)(sxrvb_feedback.value * 255.0);
  rgsxdly[2].delayfeed = (int)(sxrvb_feedback.value * 255.0);
  return;
}


// SXRVB_DoAMod  @ 001fd3b0
void SXRVB_DoAMod(int count)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  portable_samplepair_t *ppVar8;
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
    ppVar8 = paintbuffer;
    do {
      iVar5 = rgsxlp[0];
      iVar1 = ppVar8->left;
      iVar2 = ppVar8->right;
      iVar6 = iVar2;
      iVar7 = iVar1;
      if (fVar4 != 0.0) {
        rgsxlp[0] = rgsxlp[1];
        iVar5 = iVar5 + rgsxlp[1];
        rgsxlp[1] = rgsxlp[2];
        iVar5 = iVar5 + rgsxlp[2] + rgsxlp[3] + rgsxlp[4];
        rgsxlp[2] = rgsxlp[3];
        iVar6 = rgsxlp[5] + rgsxlp[6];
        rgsxlp[4] = rgsxlp[5];
        rgsxlp[5] = rgsxlp[6];
        iVar7 = iVar5 + iVar1 >> 2;
        rgsxlp[6] = rgsxlp[7];
        iVar6 = iVar6 + rgsxlp[7] + rgsxlp[8] + rgsxlp[9] + iVar2 >> 2;
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
        sxmod2cur = sxmod2cur + -1;
        if (sxmod2cur < 0) {
          sxmod2cur = sxmod2;
        }
        if (sxmod2 == 0) {
          sxamodlt = RandomLong(0x20,0xff);
        }
        iVar7 = iVar7 * sxamodl >> 8;
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
      if (iVar7 < -0x8000) {
        iVar7 = -0x8000;
      }
      if (iVar6 < -0x8000) {
        iVar6 = -0x8000;
      }
      if (0x7fff < iVar7) {
        iVar7 = 0x7fff;
      }
      if (0x7fff < iVar6) {
        iVar6 = 0x7fff;
      }
      ppVar8->left = iVar7;
      ppVar8->right = iVar6;
      ppVar8 = ppVar8 + 1;
      local_28 = local_28 + -1;
    } while (local_28 != 0);
  }
  return;
}


// SXRVB_DoReverb  @ 001fcef0
void SXRVB_DoReverb(int count)

{
  int iVar1;
  int iVar2;
  int32 iVar3;
  int iVar4;
  int iVar5;
  portable_samplepair_t *ppVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int local_30;
  int local_28;
  int local_24;
  
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
  ppVar6 = paintbuffer;
  do {
    iVar2 = rgsxdly[1].idelayoutput;
    local_28 = count + -1;
    iVar1 = ppVar6->right;
    iVar9 = ppVar6->left;
    rgsxdly[1].modcur = rgsxdly[1].modcur + -1;
    iVar4 = iVar1 + iVar9 >> 1;
    if (rgsxdly[1].modcur < 0) {
      rgsxdly[1].modcur = rgsxdly[1].mod;
    }
    iVar8 = (int)rgsxdly[1].lpdelayline[rgsxdly[1].idelayoutput];
    if ((iVar8 != 0) || (rgsxdly[1].xfade != 0)) {
      if (rgsxdly[1].xfade == 0) goto LAB_001fd268;
LAB_001fd0c2:
      local_30 = rgsxdly[1].idelayoutputxf;
      sVar7 = (short)((0x20 - rgsxdly[1].xfade) *
                      (int)rgsxdly[1].lpdelayline[rgsxdly[1].idelayoutputxf] >> 5);
      iVar5 = rgsxdly[1].xfade + -1;
LAB_001fd0ed:
      iVar8 = (int)(short)((short)(iVar8 * rgsxdly[1].xfade >> 5) + sVar7);
      rgsxdly[1].idelayoutputxf = local_30 + 1;
      if (rgsxdly[1].cdelaysamplesmax <= rgsxdly[1].idelayoutputxf) {
        rgsxdly[1].idelayoutputxf = 0;
      }
      iVar2 = rgsxdly[1].idelayoutputxf;
      rgsxdly[1].xfade = iVar5;
      if (iVar5 != 0) {
        iVar2 = rgsxdly[1].idelayoutput;
      }
LAB_001fd128:
      rgsxdly[1].idelayoutput = iVar2;
      iVar2 = iVar4;
      if (iVar8 != 0) {
        iVar8 = (iVar8 * rgsxdly[1].delayfeed >> 8) + iVar4;
        iVar2 = -0x8000;
        if (-0x8001 < iVar8) {
          iVar2 = iVar8;
        }
        if (0x7fff < iVar2) {
          iVar2 = 0x7fff;
        }
      }
      iVar8 = iVar2;
      if (rgsxdly[1].lp != 0) {
        iVar8 = iVar2 + rgsxdly[1].lp0 >> 1;
        rgsxdly[1].lp0 = iVar2;
      }
      rgsxdly[1].lpdelayline[rgsxdly[1].idelayinput] = (sample_t)iVar8;
    }
    else {
      if (iVar1 != 0 || iVar9 != 0) {
LAB_001fd268:
        if (rgsxdly[1].mod == 0) {
          iVar3 = RandomLong(0,0xff);
          iVar2 = (iVar3 * rgsxdly[1].delaysamples >> 9) + iVar2;
          iVar5 = 0x1f;
          local_30 = iVar2 - rgsxdly[1].cdelaysamplesmax;
          if (iVar2 < rgsxdly[1].cdelaysamplesmax) {
            local_30 = iVar2;
          }
          sVar7 = 0;
          rgsxdly[1].xfade = 0x20;
          goto LAB_001fd0ed;
        }
        if (rgsxdly[1].xfade != 0) goto LAB_001fd0c2;
        goto LAB_001fd128;
      }
      iVar8 = 0;
      rgsxdly[1].lp0 = 0;
      rgsxdly[1].lpdelayline[rgsxdly[1].idelayinput] = 0;
    }
    iVar2 = rgsxdly[2].idelayoutput;
    rgsxdly[1].idelayinput = rgsxdly[1].idelayinput + 1;
    if (rgsxdly[1].cdelaysamplesmax <= rgsxdly[1].idelayinput) {
      rgsxdly[1].idelayinput = 0;
    }
    iVar5 = rgsxdly[1].idelayoutput + 1;
    rgsxdly[1].idelayoutput = 0;
    if (iVar5 < rgsxdly[1].cdelaysamplesmax) {
      rgsxdly[1].idelayoutput = iVar5;
    }
    rgsxdly[2].modcur = rgsxdly[2].modcur + -1;
    if (rgsxdly[2].modcur < 0) {
      rgsxdly[2].modcur = rgsxdly[2].mod;
    }
    if (rgsxdly[2].lpdelayline != (sample_t *)0x0) {
      local_30 = (int)rgsxdly[2].lpdelayline[rgsxdly[2].idelayoutput];
      if ((local_30 != 0) || (rgsxdly[2].xfade != 0)) {
        if (rgsxdly[2].xfade == 0) goto LAB_001fd288;
LAB_001fd190:
        local_24 = rgsxdly[2].idelayoutputxf;
        sVar7 = (short)((0x20 - rgsxdly[2].xfade) *
                        (int)rgsxdly[2].lpdelayline[rgsxdly[2].idelayoutputxf] >> 5);
        iVar5 = rgsxdly[2].xfade + -1;
LAB_001fd1bb:
        local_30 = (int)(short)((short)(rgsxdly[2].xfade * local_30 >> 5) + sVar7);
        rgsxdly[2].idelayoutputxf = local_24 + 1;
        if (rgsxdly[2].cdelaysamplesmax <= rgsxdly[2].idelayoutputxf) {
          rgsxdly[2].idelayoutputxf = 0;
        }
        iVar2 = rgsxdly[2].idelayoutputxf;
        rgsxdly[2].xfade = iVar5;
        if (iVar5 != 0) {
          iVar2 = rgsxdly[2].idelayoutput;
        }
LAB_001fd1fc:
        rgsxdly[2].idelayoutput = iVar2;
        if (local_30 != 0) {
          iVar4 = iVar4 + (local_30 * rgsxdly[2].delayfeed >> 8);
          if (iVar4 < -0x8000) {
            iVar4 = -0x8000;
          }
          if (0x7fff < iVar4) {
            iVar4 = 0x7fff;
          }
        }
        iVar2 = iVar4;
        if (rgsxdly[2].lp != 0) {
          iVar2 = iVar4 + rgsxdly[2].lp0 >> 1;
          rgsxdly[2].lp0 = iVar4;
        }
        iVar8 = iVar8 + iVar2;
        rgsxdly[2].lpdelayline[rgsxdly[2].idelayinput] = (sample_t)iVar2;
      }
      else {
        if (iVar1 != 0 || iVar9 != 0) {
LAB_001fd288:
          if (rgsxdly[2].mod == 0) {
            iVar3 = RandomLong(0,0xff);
            iVar2 = (iVar3 * rgsxdly[2].delaysamples >> 9) + iVar2;
            iVar5 = 0x1f;
            rgsxdly[2].xfade = 0x20;
            local_24 = iVar2 - rgsxdly[2].cdelaysamplesmax;
            if (iVar2 < rgsxdly[2].cdelaysamplesmax) {
              local_24 = iVar2;
            }
            sVar7 = 0;
            goto LAB_001fd1bb;
          }
          if (rgsxdly[2].xfade != 0) goto LAB_001fd190;
          goto LAB_001fd1fc;
        }
        rgsxdly[2].lp0 = 0;
        rgsxdly[2].lpdelayline[rgsxdly[2].idelayinput] = 0;
      }
      rgsxdly[2].idelayinput = rgsxdly[2].idelayinput + 1;
      if (rgsxdly[2].cdelaysamplesmax <= rgsxdly[2].idelayinput) {
        rgsxdly[2].idelayinput = 0;
      }
      iVar2 = rgsxdly[2].idelayoutput + 1;
      rgsxdly[2].idelayoutput = 0;
      if (iVar2 < rgsxdly[2].cdelaysamplesmax) {
        rgsxdly[2].idelayoutput = iVar2;
      }
    }
    iVar2 = iVar8 * 0xb >> 6;
    iVar9 = iVar9 + iVar2;
    iVar2 = iVar2 + iVar1;
    if (iVar9 < -0x8000) {
      iVar9 = -0x8000;
    }
    if (iVar2 < -0x8000) {
      iVar2 = -0x8000;
    }
    if (0x7fff < iVar9) {
      iVar9 = 0x7fff;
    }
    if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    ppVar6->left = iVar9;
    ppVar6->right = iVar2;
    if (local_28 == 0) {
      return;
    }
    ppVar6 = ppVar6 + 1;
    count = local_28;
  } while( true );
}


