// SX_Free  @ 001aaaf0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SX_Free(void)

{
                    /* Unresolved local var: int i@[???] */
                    /* Unresolved local var: dlyline_t * pdly@[???] */
  if (rgsxdly[0].lpdelayline != (sample_t *)0x0) {
    free(rgsxdly[0].hdelayline);
    rgsxdly[0].hdelayline = (HANDLE)0x0;
    rgsxdly[0].lpdelayline = (sample_t *)0x0;
  }
                    /* Unresolved local var: dlyline_t * pdly@[???] */
  if (rgsxdly[1].lpdelayline != (sample_t *)0x0) {
    free(rgsxdly[1].hdelayline);
    rgsxdly[1].hdelayline = (HANDLE)0x0;
    rgsxdly[1].lpdelayline = (sample_t *)0x0;
  }
  if (rgsxdly[2].lpdelayline != (sample_t *)0x0) {
    free(rgsxdly[2].hdelayline);
    rgsxdly[2].hdelayline = (HANDLE)0x0;
    rgsxdly[2].lpdelayline = (sample_t *)0x0;
  }
                    /* Unresolved local var: dlyline_t * pdly@[???] */
  if (rgsxdly[3].lpdelayline != (sample_t *)0x0) {
    free(rgsxdly[3].hdelayline);
    rgsxdly[3].hdelayline = (HANDLE)0x0;
    rgsxdly[3].lpdelayline = (sample_t *)0x0;
  }
  return;
}


// SX_Init  @ 001aa940
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SX_Init(void)

{
  Q_memset(rgsxdly,0,0xf0);
  Q_memset(rgsxlp,0,0x28);
  sxamodr = 0xff;
  sxdly_delayprev = -1.0;
  sxrvb_sizeprev = -1.0;
  sxste_delayprev = -1.0;
  sxhiresprev = (int)NAN(hisound.value);
  if (hisound.value != 0.0) {
    sxhiresprev = 1;
  }
  sxamodl = 0xff;
  sxamodrt = 0xff;
  sxroom_typeprev = -1.0;
  sxamodlt = 0xff;
  if (shm != (dma_t *)0x0) {
    sxmod1 = (shm->speed / 0x2b11) * 0x15e;
    sxmod2 = (shm->speed / 0x2b11) * 0x1c2;
  }
  sxhires = sxhiresprev;
  sxmod2cur = sxmod2;
  sxmod1cur = sxmod1;
  Cvar_RegisterVariable(&sxdly_delay);
  Cvar_RegisterVariable(&sxdly_feedback);
  Cvar_RegisterVariable(&sxdly_lp);
  Cvar_RegisterVariable(&sxrvb_size);
  Cvar_RegisterVariable(&sxrvb_feedback);
  Cvar_RegisterVariable(&sxrvb_lp);
  Cvar_RegisterVariable(&sxste_delay);
  Cvar_RegisterVariable(&sxmod_lowpass);
  Cvar_RegisterVariable(&sxmod_mod);
  Cvar_RegisterVariable(&sxroom_type);
  Cvar_RegisterVariable(&sxroomwater_type);
  Cvar_RegisterVariable(&sxroom_off);
  return;
}


// SX_ReloadRoomFX  @ 001abfc0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SX_ReloadRoomFX(void)

{
  sxroom_typeprev = -1.0;
  sxdly_delayprev = -1.0;
  sxrvb_sizeprev = -1.0;
  sxste_delayprev = -1.0;
  return;
}


// SX_RoomFX  @ 001abda0
void __regparm3 SX_RoomFX(int count,int fFilter,int fTimefx)

{
  float fVar1;
  uint uVar2;
  
                    /* Unresolved local var: int fReset@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float roomType@[???] */
  sxhires = (int)NAN(hisound.value);
  if (hisound.value != 0.0) {
    sxhires = 1;
  }
  if (sxhires != sxhiresprev) {
    sxrvb_sizeprev = -1.0;
    sxhiresprev = sxhires;
    sxroom_typeprev = sxrvb_sizeprev;
    sxdly_delayprev = sxrvb_sizeprev;
    sxste_delayprev = sxrvb_sizeprev;
  }
  fVar1 = sxroomwater_type.value;
  if (cl.waterlevel < 3) {
    fVar1 = sxroom_type.value;
  }
  if (fVar1 == sxroom_typeprev) {
    if (fVar1 == 0.0) {
      return;
    }
  }
  else {
    uVar2 = (uint)fVar1;
    sxroom_typeprev = fVar1;
    if (uVar2 < 0x1d) {
      Cvar_SetValue("room_lp",rgsxpre[uVar2].room_lp);
      Cvar_SetValue("room_mod",rgsxpre[uVar2].room_mod);
      Cvar_SetValue("room_size",rgsxpre[uVar2].room_size);
      Cvar_SetValue("room_refl",rgsxpre[uVar2].room_refl);
      Cvar_SetValue("room_rvblp",rgsxpre[uVar2].room_rvblp);
      Cvar_SetValue("room_delay",rgsxpre[uVar2].room_delay);
      Cvar_SetValue("room_feedback",rgsxpre[uVar2].room_feedback);
      Cvar_SetValue("room_dlylp",rgsxpre[uVar2].room_dlylp);
      Cvar_SetValue("room_left",rgsxpre[uVar2].room_left);
    }
    SXRVB_CheckNewReverbVal();
    SXDLY_CheckNewDelayVal();
    SXDLY_CheckNewStereoDelayVal();
  }
  SXRVB_CheckNewReverbVal();
  SXDLY_CheckNewDelayVal();
  SXDLY_CheckNewStereoDelayVal();
  if (fFilter != 0) {
    SXRVB_DoAMod(count);
  }
  if (fTimefx != 0) {
    SXRVB_DoReverb(count);
    SXDLY_DoDelay(count);
    SXDLY_DoStereoDelay(count);
  }
  return;
}


// SX_RoomFX  @ 001abfe0
void SX_RoomFX(int count,int fFilter,int fTimefx)

{
  float fVar1;
  uint uVar2;
  
                    /* Unresolved local var: int fReset@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float roomType@[???] */
  if (sxroom_off.value == 0.0) {
                    /* Unresolved local var: int fReset@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: float roomType@[???] */
    sxhires = (int)NAN(hisound.value);
    if (hisound.value != 0.0) {
      sxhires = 1;
    }
    if (sxhires != sxhiresprev) {
      sxrvb_sizeprev = -1.0;
      sxhiresprev = sxhires;
      sxroom_typeprev = sxrvb_sizeprev;
      sxdly_delayprev = sxrvb_sizeprev;
      sxste_delayprev = sxrvb_sizeprev;
    }
    fVar1 = sxroomwater_type.value;
    if (cl.waterlevel < 3) {
      fVar1 = sxroom_type.value;
    }
    if (fVar1 == sxroom_typeprev) {
      if (fVar1 == 0.0) {
        return;
      }
    }
    else {
      uVar2 = (uint)fVar1;
      sxroom_typeprev = fVar1;
      if (uVar2 < 0x1d) {
        Cvar_SetValue("room_lp",rgsxpre[uVar2].room_lp);
        Cvar_SetValue("room_mod",rgsxpre[uVar2].room_mod);
        Cvar_SetValue("room_size",rgsxpre[uVar2].room_size);
        Cvar_SetValue("room_refl",rgsxpre[uVar2].room_refl);
        Cvar_SetValue("room_rvblp",rgsxpre[uVar2].room_rvblp);
        Cvar_SetValue("room_delay",rgsxpre[uVar2].room_delay);
        Cvar_SetValue("room_feedback",rgsxpre[uVar2].room_feedback);
        Cvar_SetValue("room_dlylp",rgsxpre[uVar2].room_dlylp);
        Cvar_SetValue("room_left",rgsxpre[uVar2].room_left);
      }
      SXRVB_CheckNewReverbVal();
      SXDLY_CheckNewDelayVal();
      SXDLY_CheckNewStereoDelayVal();
    }
    SXRVB_CheckNewReverbVal();
    SXDLY_CheckNewDelayVal();
    SXDLY_CheckNewStereoDelayVal();
    if (fFilter != 0) {
      SXRVB_DoAMod(count);
    }
    if (fTimefx != 0) {
      SXRVB_DoReverb(count);
      SXDLY_DoDelay(count);
      SXDLY_DoStereoDelay(count);
      return;
    }
  }
  return;
}


