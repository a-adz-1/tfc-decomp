// FUN_0006e21c  @ 0006e21c
void FUN_0006e21c(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}


// _DotProduct  @ 000d8cf0
vec_t _DotProduct(vec_t *v1,vec_t *v2)

{
  return v1[2] * v2[2] + v1[1] * v2[1] + *v1 * *v2;
}


// _GLOBAL__sub_I_gEngfuncs  @ 0006e630
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_gEngfuncs(void)

{
  gHUD.m_pHudList = (HUDLIST *)0x0;
  gHUD.m_iSpriteCount = 0;
  gHUD.m_Ammo.super_CHudBase._vptr_CHudBase = (_func_int_varargs **)&PTR__CHudAmmo_000e4d28;
  gHUD.m_Health.super_CHudBase._vptr_CHudBase = (_func_int_varargs **)&PTR__CHudHealth_000e5348;
  gHUD.m_Spectator.super_CHudBase._vptr_CHudBase =
       (_func_int_varargs **)&PTR__CHudSpectator_000e28a8;
  CInterpolation::CInterpolation(&gHUD.m_Spectator.m_WayInterpolation);
  gHUD.m_Geiger.super_CHudBase._vptr_CHudBase = (_func_int_varargs **)&PTR__CHudGeiger_000e52a8;
  gHUD.m_Flash.super_CHudBase._vptr_CHudBase = (_func_int_varargs **)&PTR__CHudFlashlight_000e5188;
  gHUD.m_Message.super_CHudBase._vptr_CHudBase = (_func_int_varargs **)&PTR__CHudMessage_000e5b88;
  gHUD.m_StatusBar.super_CHudBase._vptr_CHudBase =
       (_func_int_varargs **)&PTR__CHudStatusBar_000e5d08;
  gHUD.m_DeathNotice.super_CHudBase._vptr_CHudBase =
       (_func_int_varargs **)&PTR__CHudDeathNotice_000e4f28;
  gHUD.m_SayText.super_CHudBase._vptr_CHudBase = (_func_int_varargs **)&PTR__CHudSayText_000e5c28;
  gHUD.m_Menu.super_CHudBase._vptr_CHudBase = (_func_int_varargs **)&PTR__CHudMenu_000e5b08;
  gHUD.m_StatusIcons.super_CHudBase._vptr_CHudBase =
       (_func_int_varargs **)&PTR__CHudStatusIcons_000e5c88;
  gHUD.m_Benchmark.super_CHudBase._vptr_CHudBase =
       (_func_int_varargs **)&PTR__CHudBenchmark_000e5508;
  gHUD.m_Battery.super_CHudBase._vptr_CHudBase = (_func_int_varargs **)&PTR__CHudBattery_000e4e28;
  gHUD.m_Train.super_CHudBase._vptr_CHudBase = (_func_int_varargs **)&PTR__CHudTrain_000e6448;
  gHUD.m_TextMessage.super_CHudBase._vptr_CHudBase =
       (_func_int_varargs **)&PTR__CHudTextMessage_000e63e8;
  gHUD.m_AmmoSecondary.super_CHudBase._vptr_CHudBase =
       (_func_int_varargs **)&PTR__CHudAmmoSecondary_000e4da8;
  __cxa_atexit(CHud::~CHud,&gHUD,&__dso_handle);
  __g_CClientExports_singleton.super_IGameClientExports.super_IBaseInterface._vptr_IBaseInterface =
       (IGameClientExports)&PTR__CClientExports_000e50a8;
  __cxa_atexit(CClientExports::~CClientExports,&__g_CClientExports_singleton,&__dso_handle);
  InterfaceReg::InterfaceReg
            (&__g_CreateCClientExportsIGameClientExports_reg,
             __CreateCClientExportsIGameClientExports_interface,"GameClientExports001");
  return;
}


// _GLOBAL__sub_I_g_Gun  @ 0006e2d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Struct "CTFSuperShotgun": ignoring overlapping field "m_usFireSuperShotgun" */
/* WARNING: Struct "CTFSuperNailgun": ignoring overlapping field "m_usFireSuperNailGun" */

void _GLOBAL__sub_I_g_Gun(void)

{
  CBasePlayer::CBasePlayer(&player);
  __cxa_atexit(CBasePlayer::~CBasePlayer,&player,&__dso_handle);
  g_Gun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFShotgun_000f1208;
  __cxa_atexit(CTFShotgun::~CTFShotgun,&g_Gun,&__dso_handle);
  g_Super.super_CTFShotgun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFSuperShotgun_000f13a8;
  __cxa_atexit(CTFSuperShotgun::~CTFSuperShotgun,&g_Super,&__dso_handle);
  g_NG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFNailgun_000f0ac8;
  __cxa_atexit(CTFNailgun::~CTFNailgun,&g_NG,&__dso_handle);
  g_SNG.super_CTFNailgun.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFSuperNailgun_000f0c68;
  __cxa_atexit(CTFSuperNailgun::~CTFSuperNailgun,&g_SNG,&__dso_handle);
  g_Tranq.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFTranq_000f1748;
  __cxa_atexit(CTFTranq::~CTFTranq,&g_Tranq,&__dso_handle);
  g_Flame.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFFlamethrower_000f02e8;
  __cxa_atexit(CTFFlamethrower::~CTFFlamethrower,&g_Flame,&__dso_handle);
  g_IC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFIncendiaryC_000f08e8;
  __cxa_atexit(CTFIncendiaryC::~CTFIncendiaryC,&g_IC,&__dso_handle);
  g_Rail.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFRailgun_000f0e48;
  __cxa_atexit(CTFRailgun::~CTFRailgun,&g_Rail,&__dso_handle);
  g_RPG.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFRpg_000f1008;
  __cxa_atexit(CTFRpg::~CTFRpg,&g_RPG,&__dso_handle);
  g_AR.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFAutoRifle_000ef988;
  __cxa_atexit(CTFAutoRifle::~CTFAutoRifle,&g_AR,&__dso_handle);
  g_AC.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFAssaultC_000ef7a8;
  __cxa_atexit(CTFAssaultC::~CTFAssaultC,&g_AC,&__dso_handle);
  g_GL.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFGrenadeLauncher_000f0568;
  __cxa_atexit(CTFGrenadeLauncher::~CTFGrenadeLauncher,&g_GL,&__dso_handle);
  g_PL.super_CTFGrenadeLauncher.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFPipebombLauncher_000f0708;
  __cxa_atexit(CTFPipebombLauncher::~CTFPipebombLauncher,&g_PL,&__dso_handle);
  g_Sniper.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.super_CBaseDelay.
  super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFSniperRifle_000f1568;
  __cxa_atexit(CTFSniperRifle::~CTFSniperRifle,&g_Sniper,&__dso_handle);
  g_Knife.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFKnife_000eff28;
  __cxa_atexit(CTFKnife::~CTFKnife,&g_Knife,&__dso_handle);
  g_Spanner.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFSpanner_000efd88;
  __cxa_atexit(CTFSpanner::~CTFSpanner,&g_Spanner,&__dso_handle);
  g_Medkit.super_CTFAxe.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.
  super_CBaseAnimating.super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity =
       (_func_int_varargs **)&PTR__CTFMedikit_000f00c8;
  __cxa_atexit(CTFMedikit::~CTFMedikit,&g_Medkit,&__dso_handle);
  g_Crowbar.super_CCrowbar.super_CBasePlayerWeapon.super_CBasePlayerItem.super_CBaseAnimating.
  super_CBaseDelay.super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CTFAxe_000efbe8
  ;
  __cxa_atexit(CTFAxe::~CTFAxe,&g_Crowbar,&__dso_handle);
  g_Spot.super_CBaseEntity._vptr_CBaseEntity = (_func_int_varargs **)&PTR__CLaserSpot_000e3628;
  __cxa_atexit(CLaserSpot::~CLaserSpot,&g_Spot,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_PlayerInfoList  @ 0006e600
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_PlayerInfoList(void)

{
  g_VoiceStatusHelper.super_IVoiceStatusHelper._vptr_IVoiceStatusHelper =
       (IVoiceStatusHelper)&PTR__CHLVoiceStatusHelper_000e4928;
  __cxa_atexit(CHLVoiceStatusHelper::~CHLVoiceStatusHelper,&g_VoiceStatusHelper,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_StudioRenderer  @ 0006e760
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_StudioRenderer(void)

{
  CGameStudioModelRenderer::CGameStudioModelRenderer(&g_StudioRenderer);
  __cxa_atexit(CGameStudioModelRenderer::~CGameStudioModelRenderer,&g_StudioRenderer,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_VoiceStatus  @ 0006e7c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_VoiceStatus(void)

{
  CVoiceStatus::CVoiceStatus(&g_VoiceStatus);
  __cxa_atexit(CVoiceStatus::~CVoiceStatus,&g_VoiceStatus,&__dso_handle);
  return;
}


// _GLOBAL__sub_I_g_bACSpinning  @ 0006e250
void processEntry _GLOBAL__sub_I_g_bACSpinning(void)

{
  g_vRed.x = 255.0;
  g_vRed.y = 0.0;
  g_vRed.z = 0.0;
  g_vBlue.x = 0.0;
  g_vBlue.y = 0.0;
  g_vBlue.z = 255.0;
  g_vYellow.x = 255.0;
  g_vYellow.y = 255.0;
  g_vYellow.z = 0.0;
  g_vGreen.x = 0.0;
  g_vGreen.y = 255.0;
  g_vGreen.z = 0.0;
  g_vBlack.x = 0.0;
  g_vBlack.y = 0.0;
  g_vBlack.z = 0.0;
  return;
}


// _GLOBAL__sub_I_g_vecZero  @ 0006e2b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_vecZero(void)

{
  g_vecZero.x = 0.0;
  g_vecZero.y = 0.0;
  g_vecZero.z = 0.0;
  return;
}


// _GLOBAL__sub_I_vec3_origin  @ 0006e7a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_vec3_origin(void)

{
  vec3_origin.x = 0.0;
  vec3_origin.y = 0.0;
  vec3_origin.z = 0.0;
  return;
}


// _VectorAdd  @ 000d8d40
void _VectorAdd(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca + *vecb;
  out[1] = veca[1] + vecb[1];
  out[2] = veca[2] + vecb[2];
  return;
}


// _VectorCopy  @ 000d8d70
void _VectorCopy(vec_t *in,vec_t *out)

{
  *out = *in;
  out[1] = in[1];
  out[2] = in[2];
  return;
}


// _VectorSubtract  @ 000d8d10
void _VectorSubtract(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca - *vecb;
  out[1] = veca[1] - vecb[1];
  out[2] = veca[2] - vecb[2];
  return;
}


// __CmdFunc_BenchMark  @ 000923e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_BenchMark(void)

{
  g_benchSwitchTime = gHUD.m_flTime + 10.0;
  g_currentstage = 1;
  CHudBenchmark::StartNextSection(&gHUD.m_Benchmark,1);
  gHUD.m_Benchmark.super_CHudBase.m_iFlags = gHUD.m_Benchmark.super_CHudBase.m_iFlags | 1;
  gHUD.m_Benchmark.m_fDrawTime = gHUD.m_flTime + 10.0;
  return;
}


// __CmdFunc_Close  @ 00085c60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Close(void)

{
  if (gpActiveSel != (WEAPON *)0x0) {
    gpLastSel = gpActiveSel;
    gpActiveSel = (WEAPON *)0x0;
    (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudoff.wav",1.0);
    return;
  }
  (*gEngfuncs.pfnClientCmd)("escape");
  return;
}


// __CmdFunc_CloseCommandMenu  @ 00082860
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_CloseCommandMenu(void)

{
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::InputSignalHideCommandMenu(gViewPort);
  }
  return;
}


// __CmdFunc_ForceCloseCommandMenu  @ 00082840
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_ForceCloseCommandMenu(void)

{
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::HideCommandMenu(gViewPort);
  }
  return;
}


// __CmdFunc_InputPlayerSpecial  @ 00082880
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_InputPlayerSpecial(void)

{
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::InputPlayerSpecial(gViewPort);
  }
  return;
}


// __CmdFunc_NextWeapon  @ 00085d40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_NextWeapon(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
  if ((gHUD.m_fPlayerDead != 0) || (((byte)gHUD.m_iHideHUDDisplay & 5) != 0)) {
    return;
  }
  if (gpActiveSel < (WEAPON *)0x2) {
    gpActiveSel = gHUD.m_Ammo.m_pWeapon;
  }
  if (gpActiveSel == (WEAPON *)0x0) {
    iVar4 = 0;
    iVar2 = 0;
  }
  else {
    iVar4 = gpActiveSel->iSlot;
    iVar2 = gpActiveSel->iSlotPos + 1;
  }
                    /* Unresolved local var: int loop@[???] */
  iVar5 = 2;
  if (4 < iVar4) goto LAB_00085e25;
  do {
    iVar3 = iVar4 * 0x18;
    if (4 < iVar2) goto LAB_00085e16;
    do {
      do {
                    /* Unresolved local var: WEAPON * wsp@[DW_OP_reg0(EAX)] */
        gpActiveSel = *(WEAPON **)(iVar3 + 0x11b2a0 + iVar2 * 4);
        if (gpActiveSel != (WEAPON *)0x0) {
          if (gpActiveSel->iMax1 == -1) {
            return;
          }
          iVar1 = gpActiveSel->iAmmoType;
          if (iVar1 == -1) {
            return;
          }
          if (0 < gpActiveSel->iClip) {
            return;
          }
          if ((-1 < iVar1) && (gWR.riAmmo[iVar1] != 0)) {
            return;
          }
          if ((-1 < gpActiveSel->iAmmo2Type) && (gWR.riAmmo[gpActiveSel->iAmmo2Type] != 0)) {
            return;
          }
          if ((gpActiveSel->iFlags & 1) != 0) {
            return;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 5);
LAB_00085e16:
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x18;
      iVar2 = 0;
    } while (iVar4 != 5);
LAB_00085e25:
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      gpActiveSel = (WEAPON *)0x0;
      return;
    }
    iVar4 = 0;
  } while( true );
}


// __CmdFunc_OpenCommandMenu  @ 000828a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_OpenCommandMenu(void)

{
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::ShowCommandMenu(gViewPort,gViewPort->m_StandardMenu);
  }
  return;
}


// __CmdFunc_PrevWeapon  @ 00085e60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_PrevWeapon(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
  if ((gHUD.m_fPlayerDead != 0) || (((byte)gHUD.m_iHideHUDDisplay & 5) != 0)) {
    return;
  }
  if (gpActiveSel < (WEAPON *)0x2) {
    gpActiveSel = gHUD.m_Ammo.m_pWeapon;
  }
  if (gpActiveSel == (WEAPON *)0x0) {
    iVar4 = 4;
    iVar2 = 4;
  }
  else {
    iVar4 = gpActiveSel->iSlot;
    iVar2 = gpActiveSel->iSlotPos + -1;
  }
                    /* Unresolved local var: int loop@[???] */
  iVar5 = 2;
  if (iVar4 < 0) goto LAB_00085f38;
  do {
    iVar3 = iVar4 * 0x18;
    if (iVar2 < 0) goto LAB_00085f26;
    do {
      do {
                    /* Unresolved local var: WEAPON * wsp@[DW_OP_reg0(EAX)] */
        gpActiveSel = *(WEAPON **)(iVar3 + 0x11b2a0 + iVar2 * 4);
        if (gpActiveSel != (WEAPON *)0x0) {
          if (gpActiveSel->iMax1 == -1) {
            return;
          }
          iVar1 = gpActiveSel->iAmmoType;
          if (iVar1 == -1) {
            return;
          }
          if (0 < gpActiveSel->iClip) {
            return;
          }
          if ((-1 < iVar1) && (gWR.riAmmo[iVar1] != 0)) {
            return;
          }
          if ((-1 < gpActiveSel->iAmmo2Type) && (gWR.riAmmo[gpActiveSel->iAmmo2Type] != 0)) {
            return;
          }
          if ((gpActiveSel->iFlags & 1) != 0) {
            return;
          }
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != -1);
LAB_00085f26:
      iVar4 = iVar4 + -1;
      iVar3 = iVar3 + -0x18;
      iVar2 = 4;
    } while (iVar4 != -1);
LAB_00085f38:
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      gpActiveSel = (WEAPON *)0x0;
      return;
    }
    iVar4 = 4;
  } while( true );
}


// __CmdFunc_Slot1  @ 00086520
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot1(void)

{
  bool bVar1;
  WeaponsResource *in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,0);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            (in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// __CmdFunc_Slot10  @ 00086720
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot10(void)

{
  bool bVar1;
  WeaponsResource *in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,9);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            (in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// __CmdFunc_Slot2  @ 000864e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot2(void)

{
  bool bVar1;
  WeaponsResource *in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,1);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            (in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// __CmdFunc_Slot3  @ 00086560
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot3(void)

{
  bool bVar1;
  WeaponsResource *in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,2);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            (in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// __CmdFunc_Slot4  @ 000865a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot4(void)

{
  bool bVar1;
  WeaponsResource *in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,3);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            (in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// __CmdFunc_Slot5  @ 000865e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot5(void)

{
  bool bVar1;
  WeaponsResource *in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,4);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            (in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// __CmdFunc_Slot6  @ 00086620
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot6(void)

{
  bool bVar1;
  WeaponsResource *in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,5);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            (in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// __CmdFunc_Slot7  @ 00086660
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot7(void)

{
  bool bVar1;
  WeaponsResource *in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,6);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            (in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// __CmdFunc_Slot8  @ 000866a0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot8(void)

{
  bool bVar1;
  WeaponsResource *in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,7);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            (in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// __CmdFunc_Slot9  @ 000866e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_Slot9(void)

{
  bool bVar1;
  WeaponsResource *in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,8);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            (in_stack_00000004,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// __CmdFunc_ToggleServerBrowser  @ 00082820
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_ToggleServerBrowser(void)

{
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::ToggleServerBrowser(gViewPort);
  }
  return;
}


// __CreateCClientExportsIGameClientExports_interface  @ 0008e490
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

IBaseInterface * __CreateCClientExportsIGameClientExports_interface(void)

{
  return (IBaseInterface *)&__g_CClientExports_singleton;
}


// __MsgFunc_AllowSpec  @ 00082420
int __MsgFunc_AllowSpec(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_AllowSpec(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_AmmoPickup  @ 00085c10
int __MsgFunc_AmmoPickup(char *pszName,int iSize,void *pbuf)

{
  int iId;
  uint uVar1;
  
                    /* Unresolved local var: int iIndex@[???]
                       Unresolved local var: int iCount@[???] */
  BEGIN_READ(pbuf,iSize);
  iId = READ_BYTE();
  uVar1 = READ_BYTE();
  HistoryResource::AddToHistory(&gHR,1,iId,(uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f));
  return 1;
}


// __MsgFunc_AmmoX  @ 00085850
int __MsgFunc_AmmoX(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  uint uVar2;
  
                    /* Unresolved local var: int iIndex@[???]
                       Unresolved local var: int iCount@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  uVar2 = READ_BYTE();
  gWR.riAmmo[iVar1] = uVar2 ^ (int)uVar2 >> 0x1f;
  gWR.riAmmo[iVar1] = gWR.riAmmo[iVar1] - ((int)uVar2 >> 0x1f);
  return 1;
}


// __MsgFunc_Battery  @ 0008bcf0
int __MsgFunc_Battery(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  gHUD.m_Battery.super_CHudBase.m_iFlags = gHUD.m_Battery.super_CHudBase.m_iFlags | 1;
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_SHORT();
  iVar2 = READ_SHORT();
  if ((iVar1 != gHUD.m_Battery.m_iBat) || (iVar2 != gHUD.m_Battery.m_iBatMax)) {
    gHUD.m_Battery.m_fFade = 100.0;
    gHUD.m_Battery.m_iBat = iVar1;
    gHUD.m_Battery.m_iBatMax = iVar2;
  }
  return 1;
}


// __MsgFunc_Bench  @ 00091ba0
int __MsgFunc_Bench(char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  char acStack_154 [256];
  net_status_s nStack_54;
  
  READ_BYTE();
  gHUD.m_Benchmark.m_fReceiveTime = gHUD.m_flTime;
  fVar1 = gHUD.m_flTime - gHUD.m_Benchmark.m_fSendTime;
  gHUD.m_Benchmark.m_StoredLatency = 1.0;
  if ((fVar1 <= 1.0) && (gHUD.m_Benchmark.m_StoredLatency = 0.0, 0.0 <= fVar1)) {
    gHUD.m_Benchmark.m_StoredLatency = fVar1;
  }
  gHUD.m_Benchmark.m_StoredPacketLoss = 0.0;
  (*(gEngfuncs.pNetAPI)->Status)(&nStack_54);
  if (nStack_54.connected != 0) {
    sprintf(acStack_154,"%i.%i.%i.%i",(uint)nStack_54.remote_address.ip[0],
            (uint)nStack_54.remote_address.ip[1],(uint)nStack_54.remote_address.ip[2],
            (uint)nStack_54.remote_address.ip[3]);
    if (nStack_54.remote_address.type != NA_IP) {
      gHUD.m_Benchmark.m_nStoredHopCount = 0;
      return 1;
    }
    Trace_StartTrace(&gHUD.m_Benchmark.m_nStoredHopCount,&gHUD.m_Benchmark.m_nTraceDone,acStack_154)
    ;
  }
  return 1;
}


// __MsgFunc_BuildSt  @ 00082660
int __MsgFunc_BuildSt(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_BuildSt(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_Concuss  @ 00082900
int __MsgFunc_Concuss(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHud::MsgFunc_Concuss(&gHUD,pszName,iSize,pbuf);
  return iVar1;
}


// __MsgFunc_CurWeapon  @ 000855b0
int __MsgFunc_CurWeapon(char *pszName,int iSize,void *pbuf)

{
  WEAPON *pWVar1;
  wrect_t wVar2;
  wrect_t wVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
                    /* Unresolved local var: int fOnTarget@[???]
                       Unresolved local var: int iState@[???]
                       Unresolved local var: int iId@[???]
                       Unresolved local var: int iClip@[???]
                       Unresolved local var: WEAPON * pWeapon@[DW_OP_reg2(EDX)] */
  BEGIN_READ(pbuf,iSize);
  iVar4 = READ_BYTE();
  iVar5 = READ_CHAR();
  iVar6 = READ_CHAR();
  if (iVar5 < 1) {
    wVar2.right = CHudAmmo::MsgFunc_CurWeapon::lexical_block_0::nullrc.right;
    wVar2.left = CHudAmmo::MsgFunc_CurWeapon::lexical_block_0::nullrc.left;
    wVar2.top = CHudAmmo::MsgFunc_CurWeapon::lexical_block_0::nullrc.top;
    wVar2.bottom = CHudAmmo::MsgFunc_CurWeapon::lexical_block_0::nullrc.bottom;
    (*gEngfuncs.pfnSetCrosshair)(0,wVar2,0,0,0);
    return 0;
  }
  if (g_iUser1 != 4) {
    gHUD.m_fPlayerDead = 0;
  }
  pWVar1 = gWR.rgWeapons + iVar5;
  if (iVar6 < -1) {
    gWR.rgWeapons[iVar5].iClip = -iVar6;
  }
  else {
    gWR.rgWeapons[iVar5].iClip = iVar6;
  }
  if (iVar4 == 0) {
    return 1;
  }
  gHUD.m_Ammo.m_pWeapon = pWVar1;
  if (gHUD.m_iFOV < 0x5a) {
    if ((iVar4 < 2) || (iVar4 = gWR.rgWeapons[iVar5].hZoomedAutoaim, iVar4 == 0)) {
      (*gEngfuncs.pfnSetCrosshair)
                (gWR.rgWeapons[iVar5].hZoomedCrosshair,gWR.rgWeapons[iVar5].rcZoomedCrosshair,0xff,
                 0xff,0xff);
      goto LAB_000856ae;
    }
    iVar6 = gWR.rgWeapons[iVar5].rcZoomedAutoaim.left;
    iVar8 = gWR.rgWeapons[iVar5].rcZoomedAutoaim.right;
    iVar7 = gWR.rgWeapons[iVar5].rcZoomedAutoaim.top;
    iVar5 = gWR.rgWeapons[iVar5].rcZoomedAutoaim.bottom;
  }
  else {
    if ((iVar4 < 2) || (iVar4 = gWR.rgWeapons[iVar5].hAutoaim, iVar4 == 0)) {
      (*gEngfuncs.pfnSetCrosshair)
                (gWR.rgWeapons[iVar5].hCrosshair,gWR.rgWeapons[iVar5].rcCrosshair,0xff,0xff,0xff);
      goto LAB_000856ae;
    }
    iVar6 = gWR.rgWeapons[iVar5].rcAutoaim.left;
    iVar8 = gWR.rgWeapons[iVar5].rcAutoaim.right;
    iVar7 = gWR.rgWeapons[iVar5].rcAutoaim.top;
    iVar5 = gWR.rgWeapons[iVar5].rcAutoaim.bottom;
  }
  wVar3.right = iVar8;
  wVar3.left = iVar6;
  wVar3.top = iVar7;
  wVar3.bottom = iVar5;
  (*gEngfuncs.pfnSetCrosshair)(iVar4,wVar3,0xff,0xff,0xff);
LAB_000856ae:
  gHUD.m_Ammo.super_CHudBase.m_iFlags = gHUD.m_Ammo.super_CHudBase.m_iFlags | 1;
  gHUD.m_Ammo.m_fFade = 200.0;
  return 1;
}


// __MsgFunc_Damage  @ 0008fb20
int __MsgFunc_Damage(char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40 [3];
  vec_t local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  vec_t local_24;
  vec_t local_20;
  
                    /* Unresolved local var: int armor@[???]
                       Unresolved local var: int damageTaken@[???]
                       Unresolved local var: long bitsDamage@[???]
                       Unresolved local var: Vector vecFrom@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar5 = READ_BYTE();
  iVar6 = READ_BYTE();
  uVar7 = READ_LONG();
                    /* Unresolved local var: int i@[???] */
  fVar11 = READ_COORD();
  fVar12 = READ_COORD();
  fVar13 = READ_COORD();
  iVar4 = giDmgHeight;
  fVar15 = gHUD.m_flTime;
                    /* Unresolved local var: DAMAGE_IMAGE * pdmg@[???]
                       Unresolved local var: long bitsOn@[???] */
                    /* Unresolved local var: int i@[???] */
  uVar10 = ~gHUD.m_Health.m_bitsDamage;
  iVar8 = giDmgWidth;
  if (giDmgWidth < 0) {
    iVar8 = giDmgWidth + 7;
  }
  iVar2 = giDmgHeight * -2;
  iVar9 = 0;
  do {
    uVar1 = giDmgFlags[iVar9];
    if (((uVar1 & gHUD.m_Health.m_bitsDamage) != 0) &&
       (gHUD.m_Health.m_dmg[iVar9].fExpire = fVar15 + 2.0,
       gHUD.m_Health.m_dmg[iVar9].fBaseline == 0.0)) {
      gHUD.m_Health.m_dmg[iVar9].fBaseline = fVar15;
    }
    if ((uVar1 & uVar10 & uVar7) != 0) {
      gHUD.m_Health.m_dmg[iVar9].x = iVar8 >> 3;
      gHUD.m_Health.m_dmg[iVar9].y = iVar2 + gHUD.m_scrinfo.iHeight;
      gHUD.m_Health.m_dmg[iVar9].fExpire = fVar15 + 2.0;
      if (iVar9 == 0) {
LAB_0008fc58:
        if (gHUD.m_Health.m_dmg[1].y != 0) {
          gHUD.m_Health.m_dmg[1].y = gHUD.m_Health.m_dmg[1].y - iVar4;
        }
        if (iVar9 != 2) goto LAB_0008fc6f;
LAB_0008fc86:
        if (gHUD.m_Health.m_dmg[3].y != 0) {
          gHUD.m_Health.m_dmg[3].y = gHUD.m_Health.m_dmg[3].y - iVar4;
        }
        if (iVar9 != 4) goto LAB_0008fc9d;
LAB_0008fcb4:
        if (gHUD.m_Health.m_dmg[5].y != 0) {
          gHUD.m_Health.m_dmg[5].y = gHUD.m_Health.m_dmg[5].y - iVar4;
        }
        if (iVar9 != 6) goto LAB_0008fccb;
LAB_0008fce2:
        if (gHUD.m_Health.m_dmg[7].y != 0) {
          gHUD.m_Health.m_dmg[7].y = gHUD.m_Health.m_dmg[7].y - iVar4;
        }
        if (iVar9 != 8) goto LAB_0008fcf9;
LAB_0008fd10:
        if (gHUD.m_Health.m_dmg[9].y != 0) {
          gHUD.m_Health.m_dmg[9].y = gHUD.m_Health.m_dmg[9].y - iVar4;
        }
        if (iVar9 != 10) goto LAB_0008fd2b;
      }
      else {
        if (gHUD.m_Health.m_dmg[0].y != 0) {
          gHUD.m_Health.m_dmg[0].y = gHUD.m_Health.m_dmg[0].y - iVar4;
        }
        if (iVar9 != 1) goto LAB_0008fc58;
LAB_0008fc6f:
        if (gHUD.m_Health.m_dmg[2].y != 0) {
          gHUD.m_Health.m_dmg[2].y = gHUD.m_Health.m_dmg[2].y - iVar4;
        }
        if (iVar9 != 3) goto LAB_0008fc86;
LAB_0008fc9d:
        if (gHUD.m_Health.m_dmg[4].y != 0) {
          gHUD.m_Health.m_dmg[4].y = gHUD.m_Health.m_dmg[4].y - iVar4;
        }
        if (iVar9 != 5) goto LAB_0008fcb4;
LAB_0008fccb:
        if (gHUD.m_Health.m_dmg[6].y != 0) {
          gHUD.m_Health.m_dmg[6].y = gHUD.m_Health.m_dmg[6].y - iVar4;
        }
        if (iVar9 != 7) goto LAB_0008fce2;
LAB_0008fcf9:
        if (gHUD.m_Health.m_dmg[8].y != 0) {
          gHUD.m_Health.m_dmg[8].y = gHUD.m_Health.m_dmg[8].y - iVar4;
        }
        if (iVar9 != 9) goto LAB_0008fd10;
LAB_0008fd2b:
        if (gHUD.m_Health.m_dmg[10].y != 0) {
          gHUD.m_Health.m_dmg[10].y = gHUD.m_Health.m_dmg[10].y - iVar4;
        }
        if (iVar9 == 0xb) break;
      }
                    /* Unresolved local var: int j@[???] */
      if (gHUD.m_Health.m_dmg[0xb].y != 0) {
        gHUD.m_Health.m_dmg[0xb].y = gHUD.m_Health.m_dmg[0xb].y - iVar4;
      }
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 != 0xc);
  gHUD.m_Health.m_bitsDamage = gHUD.m_Health.m_bitsDamage | uVar7;
  if ((0 < iVar5) || (0 < iVar6)) {
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: float side@[???]
                       Unresolved local var: float front@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: Vector vecAngles@[???]
                       Unresolved local var: float flDistToTarget@[???] */
    if ((fVar11 == 0.0) && ((fVar12 == 0.0 && (fVar13 == 0.0)))) {
      gHUD.m_Health.m_fAttackFront = 0.0;
      gHUD.m_Health.m_fAttackRear = 0.0;
      gHUD.m_Health.m_fAttackLeft = 0.0;
      gHUD.m_Health.m_fAttackRight = 0.0;
    }
    else {
      local_34 = gHUD.m_vecOrigin.x;
      fVar11 = fVar11 - gHUD.m_vecOrigin.x;
      local_30 = gHUD.m_vecOrigin.y;
      fVar12 = fVar12 - gHUD.m_vecOrigin.y;
      local_2c = gHUD.m_vecOrigin.z;
      fVar13 = fVar13 - gHUD.m_vecOrigin.z;
      local_28 = gHUD.m_vecAngles.x;
      local_24 = gHUD.m_vecAngles.y;
      local_20 = gHUD.m_vecAngles.z;
      fVar3 = fVar13 * fVar13 + fVar12 * fVar12 + fVar11 * fVar11;
      fVar15 = SQRT(fVar3);
      fVar14 = fVar15;
      if (NAN(fVar15)) {
        fVar14 = sqrtf(fVar3);
        fVar15 = sqrtf(fVar3);
      }
      fVar3 = 0.0;
      if (fVar15 == 0.0) {
        fVar13 = 1.0;
        fVar11 = fVar3;
      }
      else {
        fVar15 = 1.0 / fVar15;
        fVar13 = fVar13 * fVar15;
        fVar3 = fVar15 * fVar11;
        fVar11 = fVar12 * fVar15;
      }
      (*gEngfuncs.pfnAngleVectors)(&local_28,&local_58,&local_4c,local_40);
      if (fVar14 <= 50.0) {
        gHUD.m_Health.m_fAttackFront = 1.0;
        gHUD.m_Health.m_fAttackRear = 1.0;
        gHUD.m_Health.m_fAttackLeft = 1.0;
        gHUD.m_Health.m_fAttackRight = 1.0;
      }
      else {
        fVar12 = local_54 * fVar11 + local_58 * fVar3 + local_50 * fVar13;
        if (0.0 < fVar12) {
          if (0.3 < fVar12) {
            if (gHUD.m_Health.m_fAttackFront <= fVar12) {
              gHUD.m_Health.m_fAttackFront = fVar12;
            }
          }
        }
        else {
                    /* Unresolved local var: float f@[???] */
          fVar12 = 0.0 - fVar12;
          if (0.3 < fVar12) {
            if (gHUD.m_Health.m_fAttackRear <= fVar12) {
              gHUD.m_Health.m_fAttackRear = fVar12;
            }
          }
        }
        fVar13 = fVar13 * local_44 + fVar11 * local_48 + fVar3 * local_4c;
        if (0.0 < fVar13) {
          if (0.3 < fVar13) {
            if (gHUD.m_Health.m_fAttackRight <= fVar13) {
              gHUD.m_Health.m_fAttackRight = fVar13;
            }
          }
        }
        else {
                    /* Unresolved local var: float f@[???] */
          fVar13 = 0.0 - fVar13;
          if (0.3 < fVar13) {
            if (gHUD.m_Health.m_fAttackLeft <= fVar13) {
              gHUD.m_Health.m_fAttackLeft = fVar13;
            }
          }
        }
      }
    }
  }
  return 1;
}


// __MsgFunc_DeathMsg  @ 0008c550
int __MsgFunc_DeathMsg(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  int victim;
  char *pcVar2;
  char cVar3;
  float *pfVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  undefined1 uVar9;
  byte bVar10;
  longdouble extraout_ST0;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30;
  
  bVar10 = 0;
                    /* Unresolved local var: int killer@[???]
                       Unresolved local var: int victim@[???]
                       Unresolved local var: char[32] killedwith@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char * killer_name@[???]
                       Unresolved local var: char * victim_name@[???]
                       Unresolved local var: int spr@[???] */
  gHUD.m_DeathNotice.super_CHudBase.m_iFlags = gHUD.m_DeathNotice.super_CHudBase.m_iFlags | 1;
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  victim = READ_BYTE();
  local_3c = CONCAT13(local_3c._3_1_,0x5f64);
  pcVar2 = READ_STRING();
  strncat((char *)&local_3c,pcVar2,0x20);
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::DeathMsg(gViewPort,iVar1,victim);
  }
  iVar5 = 0;
  CHudSpectator::DeathMessage(&gHUD.m_Spectator,victim);
  if ((((rgDeathNoticeList[0].iId != 0) && (iVar5 = 1, rgDeathNoticeList[1].iId != 0)) &&
      (iVar5 = 2, rgDeathNoticeList[2].iId != 0)) && (iVar5 = 3, rgDeathNoticeList[3].iId != 0)) {
    memmove(rgDeathNoticeList,rgDeathNoticeList + 1,0x270);
  }
  if (gViewPort != (TeamFortressViewport *)0x0) {
    TeamFortressViewport::GetAllPlayersInfo(gViewPort);
  }
  pcVar2 = g_PlayerInfoList[iVar1].name;
  cVar3 = (char)victim;
  if (pcVar2 == (char *)0x0) {
    rgDeathNoticeList[iVar5].szKiller[0] = '\0';
    if (cVar3 != -1) goto LAB_0008c6af;
LAB_0008c9b0:
    rgDeathNoticeList[iVar5].szVictim[0] = '\0';
    if (cVar3 == -1) {
      rgDeathNoticeList[iVar5].iNonPlayerKill = 1;
      strcpy(rgDeathNoticeList[iVar5].szVictim,(char *)((int)&local_3c + 2));
      goto LAB_0008c75a;
    }
  }
  else {
    pfVar4 = g_ColorGrey;
    if ((ushort)g_PlayerExtraInfo[iVar1].teamnumber < 5) {
      pfVar4 = *(float **)(CSWTCH_82 + (uint)(ushort)g_PlayerExtraInfo[iVar1].teamnumber * 4);
    }
    rgDeathNoticeList[iVar5].KillerColor = pfVar4;
    strncpy(rgDeathNoticeList[iVar5].szKiller,pcVar2,0x20);
    rgDeathNoticeList[iVar5].szKiller[0x1f] = '\0';
    if (cVar3 == -1) goto LAB_0008c9b0;
LAB_0008c6af:
    pcVar2 = g_PlayerInfoList[victim].name;
    if (pcVar2 == (char *)0x0) goto LAB_0008c9b0;
    pfVar4 = g_ColorGrey;
    if ((ushort)g_PlayerExtraInfo[victim].teamnumber < 5) {
      pfVar4 = *(float **)(CSWTCH_82 + (uint)(ushort)g_PlayerExtraInfo[victim].teamnumber * 4);
    }
    rgDeathNoticeList[iVar5].VictimColor = pfVar4;
    strncpy(rgDeathNoticeList[iVar5].szVictim,pcVar2,0x20);
    rgDeathNoticeList[iVar5].szVictim[0x1f] = '\0';
  }
  if ((iVar1 == 0) || (bVar8 = false, iVar1 == victim)) {
    bVar8 = iVar5 * 0x9b == 0;
    rgDeathNoticeList[iVar5].iSuicide = 1;
  }
  iVar1 = 0xb;
  pcVar2 = (char *)&local_3c;
  pcVar6 = "d_teammate";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar8 = *pcVar2 == *pcVar6;
    pcVar2 = pcVar2 + (uint)bVar10 * -2 + 1;
    pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
  } while (bVar8);
  if (bVar8) {
    rgDeathNoticeList[iVar5].iTeamKill = 1;
  }
LAB_0008c75a:
  iVar1 = CHud::GetSpriteIndex(&gHUD,(char *)&local_3c);
  rgDeathNoticeList[iVar5].iId = iVar1;
  (*gEngfuncs.pfnGetCvarFloat)("hud_deathnotice_time");
  DEATHNOTICE_DISPLAY_TIME = (int)extraout_ST0;
  rgDeathNoticeList[iVar5].flDisplayTime = (float)DEATHNOTICE_DISPLAY_TIME + gHUD.m_flTime;
  if (rgDeathNoticeList[iVar5].iNonPlayerKill != 0) {
    (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar5].szKiller);
    (*gEngfuncs.pfnConsolePrint)(" killed a ");
    (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar5].szVictim);
    (*gEngfuncs.pfnConsolePrint)("\n");
    return 1;
  }
  if (rgDeathNoticeList[iVar5].iSuicide == 0) {
    if (rgDeathNoticeList[iVar5].iTeamKill == 0) {
      (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar5].szKiller);
      (*gEngfuncs.pfnConsolePrint)(" killed ");
      (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar5].szVictim);
    }
    else {
      (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar5].szKiller);
      (*gEngfuncs.pfnConsolePrint)(" killed his teammate ");
      (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar5].szVictim);
    }
  }
  else {
    uVar9 = rgDeathNoticeList[iVar5].szVictim == (char *)0x0;
    (*gEngfuncs.pfnConsolePrint)(rgDeathNoticeList[iVar5].szVictim);
    iVar1 = 8;
    pcVar2 = (char *)&local_3c;
    pcVar6 = "d_world";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      uVar9 = *pcVar2 == *pcVar6;
      pcVar2 = pcVar2 + (uint)bVar10 * -2 + 1;
      pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
    } while ((bool)uVar9);
    if ((bool)uVar9) {
      (*gEngfuncs.pfnConsolePrint)(" died");
    }
    else {
      (*gEngfuncs.pfnConsolePrint)(" killed self");
    }
  }
  bVar8 = (char)local_3c == '\r';
  if ('\r' < (char)local_3c) {
    iVar1 = 8;
    pcVar2 = (char *)&local_3c;
    pcVar6 = "d_world";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar8 = *pcVar2 == *pcVar6;
      pcVar2 = pcVar2 + (uint)bVar10 * -2 + 1;
      pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
    } while (bVar8);
    if ((!bVar8) && (uVar9 = rgDeathNoticeList[iVar5].iTeamKill == 0, (bool)uVar9)) {
      (*gEngfuncs.pfnConsolePrint)(" with ");
      pcVar2 = (char *)((int)&local_3c + 2);
      iVar1 = 5;
      pcVar6 = pcVar2;
      pcVar7 = "egon";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        uVar9 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
        pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
      } while ((bool)uVar9);
      if ((bool)uVar9) {
        local_3c = 0x6c675f64;
        local_38 = 0x206e6f75;
        local_34 = 0x6e7567;
      }
      iVar1 = 6;
      pcVar6 = pcVar2;
      pcVar7 = "gauss";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        uVar9 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
        pcVar7 = pcVar7 + (uint)bVar10 * -2 + 1;
      } while ((bool)uVar9);
      if ((bool)uVar9) {
        local_3c = 0x61745f64;
        local_38 = 0x61632075;
        local_34 = 0x6e6f6e6e;
        local_30 = 0;
      }
      (*gEngfuncs.pfnConsolePrint)(pcVar2);
    }
  }
  (*gEngfuncs.pfnConsolePrint)("\n");
  return 1;
}


// __MsgFunc_Detpack  @ 00082720
int __MsgFunc_Detpack(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_Detpack(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_Feign  @ 00082760
int __MsgFunc_Feign(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_Feign(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_FlashBat  @ 0008f2a0
int __MsgFunc_FlashBat(char *pszName,int iSize,void *pbuf)

{
                    /* Unresolved local var: int x@[???] */
  BEGIN_READ(pbuf,iSize);
  gHUD.m_Flash.m_iBat = READ_BYTE();
  gHUD.m_Flash.m_flBat = (float)gHUD.m_Flash.m_iBat / 100.0;
  return 1;
}


// __MsgFunc_Flashlight  @ 0008f2e0
int __MsgFunc_Flashlight(char *pszName,int iSize,void *pbuf)

{
                    /* Unresolved local var: int x@[???] */
  BEGIN_READ(pbuf,iSize);
  gHUD.m_Flash.m_fOn = READ_BYTE();
  gHUD.m_Flash.m_iBat = READ_BYTE();
  gHUD.m_Flash.m_flBat = (float)gHUD.m_Flash.m_iBat / 100.0;
  return 1;
}


// __MsgFunc_GameMode  @ 000828d0
int __MsgFunc_GameMode(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHud::MsgFunc_GameMode(&gHUD,pszName,iSize,pbuf);
  return iVar1;
}


// __MsgFunc_GameTitle  @ 0009a8f0
int __MsgFunc_GameTitle(char *pszName,int iSize,void *pbuf)

{
  gHUD.m_Message.m_pGameTitle = (*gEngfuncs.pfnTextMessageGet)("GAMETITLE");
  if (gHUD.m_Message.m_pGameTitle != (client_textmessage_s *)0x0) {
    gHUD.m_Message.m_gameTitleTime = gHUD.m_flTime;
    if ((gHUD.m_Message.super_CHudBase.m_iFlags & 1U) == 0) {
      gHUD.m_Message.super_CHudBase.m_iFlags = gHUD.m_Message.super_CHudBase.m_iFlags | 1;
    }
  }
  return 1;
}


// __MsgFunc_Geiger  @ 0008f800
int __MsgFunc_Geiger(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  gHUD.m_Geiger.super_CHudBase.m_iFlags = gHUD.m_Geiger.super_CHudBase.m_iFlags | 1;
  gHUD.m_Geiger.m_iGeigerRange = iVar1 << 2;
  return 1;
}


// __MsgFunc_Health  @ 0008fad0
int __MsgFunc_Health(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
                    /* Unresolved local var: int x@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  gHUD.m_Health.super_CHudBase.m_iFlags = gHUD.m_Health.super_CHudBase.m_iFlags | 1;
  if (iVar1 != gHUD.m_Health.m_iHealth) {
    gHUD.m_Health.m_fFade = 100.0;
    gHUD.m_Health.m_iHealth = iVar1;
  }
  return 1;
}


// __MsgFunc_HideWeapon  @ 00085490
int __MsgFunc_HideWeapon(char *pszName,int iSize,void *pbuf)

{
  wrect_t wVar1;
  int iVar2;
  
  BEGIN_READ(pbuf,iSize);
  gHUD.m_iHideHUDDisplay = READ_BYTE();
  iVar2 = (*gEngfuncs.IsSpectateOnly)();
  if (iVar2 == 0) {
    if ((gHUD.m_iHideHUDDisplay & 5U) != 0) {
      gpActiveSel = (WEAPON *)0x0;
      wVar1.right = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.right;
      wVar1.left = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.left;
      wVar1.top = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.top;
      wVar1.bottom = CHudAmmo::MsgFunc_HideWeapon::lexical_block_0::nullrc.bottom;
      (*gEngfuncs.pfnSetCrosshair)(0,wVar1,0,0,0);
      return 1;
    }
    if (gHUD.m_Ammo.m_pWeapon != (WEAPON *)0x0) {
      (*gEngfuncs.pfnSetCrosshair)
                ((gHUD.m_Ammo.m_pWeapon)->hCrosshair,(gHUD.m_Ammo.m_pWeapon)->rcCrosshair,0xff,0xff,
                 0xff);
    }
  }
  return 1;
}


// __MsgFunc_HudText  @ 0009a930
int __MsgFunc_HudText(char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  float fVar2;
  client_textmessage_t *pcVar3;
  client_textmessage_t *pcVar4;
  char *__src;
  client_textmessage_t *pcVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: char * pString@[???] */
  BEGIN_READ(pbuf,iSize);
  __src = READ_STRING();
  fVar2 = gHUD.m_flTime;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: client_textmessage_t * tempMessage@[???] */
  if (gHUD.m_Message.m_pMessages[0] == (client_textmessage_t *)0x0) {
    iVar7 = 0;
  }
  else if (gHUD.m_Message.m_pMessages[1] == (client_textmessage_t *)0x0) {
    iVar7 = 1;
  }
  else if (gHUD.m_Message.m_pMessages[2] == (client_textmessage_t *)0x0) {
    iVar7 = 2;
  }
  else if (gHUD.m_Message.m_pMessages[3] == (client_textmessage_t *)0x0) {
    iVar7 = 3;
  }
  else if (gHUD.m_Message.m_pMessages[4] == (client_textmessage_t *)0x0) {
    iVar7 = 4;
  }
  else if (gHUD.m_Message.m_pMessages[5] == (client_textmessage_t *)0x0) {
    iVar7 = 5;
  }
  else if (gHUD.m_Message.m_pMessages[6] == (client_textmessage_t *)0x0) {
    iVar7 = 6;
  }
  else if (gHUD.m_Message.m_pMessages[7] == (client_textmessage_t *)0x0) {
    iVar7 = 7;
  }
  else if (gHUD.m_Message.m_pMessages[8] == (client_textmessage_t *)0x0) {
    iVar7 = 8;
  }
  else if (gHUD.m_Message.m_pMessages[9] == (client_textmessage_t *)0x0) {
    iVar7 = 9;
  }
  else if (gHUD.m_Message.m_pMessages[10] == (client_textmessage_t *)0x0) {
    iVar7 = 10;
  }
  else if (gHUD.m_Message.m_pMessages[0xb] == (client_textmessage_t *)0x0) {
    iVar7 = 0xb;
  }
  else if (gHUD.m_Message.m_pMessages[0xc] == (client_textmessage_t *)0x0) {
    iVar7 = 0xc;
  }
  else if (gHUD.m_Message.m_pMessages[0xd] == (client_textmessage_t *)0x0) {
    iVar7 = 0xd;
  }
  else if (gHUD.m_Message.m_pMessages[0xe] == (client_textmessage_t *)0x0) {
    iVar7 = 0xe;
  }
  else {
    if (gHUD.m_Message.m_pMessages[0xf] != (client_textmessage_t *)0x0) goto LAB_0009aa29;
    iVar7 = 0xf;
  }
  if (*__src == '#') {
    pcVar5 = (*gEngfuncs.pfnTextMessageGet)(__src + 1);
  }
  else {
    pcVar5 = (*gEngfuncs.pfnTextMessageGet)(__src);
  }
  if (pcVar5 == (client_textmessage_t *)0x0) {
    g_pCustomMessage.effect = 2;
    g_pCustomMessage.a1 = 'd';
    g_pCustomMessage.b1 = 'd';
    g_pCustomMessage.g1 = 'd';
    g_pCustomMessage.r1 = 'd';
    g_pCustomMessage.r2 = 0xf0;
    g_pCustomMessage.g2 = 'n';
    g_pCustomMessage.b2 = '\0';
    g_pCustomMessage.a2 = '\0';
    g_pCustomMessage.x = -1.0;
    g_pCustomMessage.y = 0.7;
    g_pCustomMessage.fadein = 0.01;
    g_pCustomMessage.fadeout = 1.5;
    g_pCustomMessage.fxtime = 0.25;
    g_pCustomMessage.holdtime = 5.0;
    g_pCustomMessage.pName = g_pCustomName;
    strcpy(g_pCustomText,__src);
    g_pCustomMessage.pMessage = g_pCustomText;
    pcVar5 = &g_pCustomMessage;
  }
  pcVar3 = gHUD.m_Message.m_pMessages[0];
  if (gHUD.m_Message.m_pMessages[0] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[0]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[0] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[1];
  if (gHUD.m_Message.m_pMessages[1] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[1]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[1] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[2];
  if (gHUD.m_Message.m_pMessages[2] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[2]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[2] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[3];
  if (gHUD.m_Message.m_pMessages[3] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[3]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[3] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[4];
  if (gHUD.m_Message.m_pMessages[4] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[4]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[4] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[5];
  if (gHUD.m_Message.m_pMessages[5] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[5]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[5] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[6];
  if (gHUD.m_Message.m_pMessages[6] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[6]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[6] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[7];
  if (gHUD.m_Message.m_pMessages[7] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[7]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[7] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[8];
  if (gHUD.m_Message.m_pMessages[8] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[8]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[8] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[9];
  if (gHUD.m_Message.m_pMessages[9] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[9]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[9] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[10];
  if (gHUD.m_Message.m_pMessages[10] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[10]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[10] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[0xb];
  if (gHUD.m_Message.m_pMessages[0xb] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[0xb]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[0xb] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[0xc];
  if (gHUD.m_Message.m_pMessages[0xc] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[0xc]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[0xc] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[0xd];
  if (gHUD.m_Message.m_pMessages[0xd] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[0xd]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[0xd] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[0xe];
  if (gHUD.m_Message.m_pMessages[0xe] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[0xe]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (fVar1 < 0.0001) {
        gHUD.m_Message.m_pMessages[0xe] = (client_textmessage_t *)0x0;
      }
    }
  }
  pcVar3 = gHUD.m_Message.m_pMessages[0xf];
  pcVar4 = gHUD.m_Message.m_pMessages[0xf];
  if (gHUD.m_Message.m_pMessages[0xf] != (client_textmessage_t *)0x0) {
    iVar6 = strcmp(pcVar5->pMessage,gHUD.m_Message.m_pMessages[0xf]->pMessage);
    if (iVar6 == 0) goto LAB_0009aa29;
    fVar1 = pcVar5->y - pcVar3->y;
    if (fVar1 <= 0.0) {
      fVar1 = 0.0 - fVar1;
    }
    pcVar4 = gHUD.m_Message.m_pMessages[0xf];
    if (fVar1 < 0.0001) {
      fVar1 = pcVar5->x - pcVar3->x;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      pcVar4 = (client_textmessage_t *)0x0;
      if (0.0001 <= fVar1) {
        pcVar4 = gHUD.m_Message.m_pMessages[0xf];
      }
    }
  }
  gHUD.m_Message.m_pMessages[0xf] = pcVar4;
  gHUD.m_Message.m_pMessages[iVar7] = pcVar5;
  gHUD.m_Message.m_startTime[iVar7] = fVar2;
LAB_0009aa29:
  gHUD.m_Message.m_parms.time = gHUD.m_flTime;
  if ((gHUD.m_Message.super_CHudBase.m_iFlags & 1U) == 0) {
    gHUD.m_Message.super_CHudBase.m_iFlags = gHUD.m_Message.super_CHudBase.m_iFlags | 1;
  }
  return 1;
}


// __MsgFunc_InitHUD  @ 00082960
int __MsgFunc_InitHUD(char *pszName,int iSize,void *pbuf)

{
  CHud::MsgFunc_InitHUD(&gHUD,pszName,iSize,pbuf);
  return 1;
}


// __MsgFunc_ItemPickup  @ 000858f0
int __MsgFunc_ItemPickup(char *pszName,int iSize,void *pbuf)

{
  char *szName;
  
                    /* Unresolved local var: char * szName@[???] */
  BEGIN_READ(pbuf,iSize);
  szName = READ_STRING();
  HistoryResource::AddToHistory(&gHR,3,szName,0);
  return 1;
}


// __MsgFunc_Logo  @ 000823c0
int __MsgFunc_Logo(char *pszName,int iSize,void *pbuf)

{
  BEGIN_READ(pbuf,iSize);
  gHUD.m_iLogo = READ_BYTE();
  return 1;
}


// __MsgFunc_MOTD  @ 000826a0
int __MsgFunc_MOTD(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_MOTD(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_RandomPC  @ 00082620
int __MsgFunc_RandomPC(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_RandomPC(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_ReqState  @ 000c6de0
int __MsgFunc_ReqState(char *pszName,int iSize,void *pbuf)

{
  char cVar1;
  char *pcVar2;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  char *this;
  undefined1 in_stack_ffffffe8;
  
  if (g_pInternalVoiceStatus != (CVoiceStatus *)0x0) {
    this = "voice_clientdebug";
    (*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
    if (extraout_ST0 == (longdouble)0) {
                    /* Unresolved local var: char * pLevelName@[???]
                       Unresolved local var: int bCVarModEnable@[???]
                       Unresolved local var: char[2048] str@[???]
                       Unresolved local var: bool bChange@[???] */
      pcVar2 = (*gEngfuncs.pfnGetLevelName)();
      cVar1 = *pcVar2;
    }
    else {
      this = "CVoiceStatus::HandleReqStateMsg\n";
      (*gEngfuncs.pfnConsolePrint)("CVoiceStatus::HandleReqStateMsg\n");
      pcVar2 = (*gEngfuncs.pfnGetLevelName)();
      cVar1 = *pcVar2;
    }
    if (cVar1 != '\0') {
      CVoiceStatus::UpdateServerState((CVoiceStatus *)this,(bool)in_stack_ffffffe8);
      return 1;
    }
    (*gEngfuncs.pfnGetCvarFloat)("voice_clientdebug");
    if (extraout_ST0_00 != (longdouble)0) {
      (*gEngfuncs.pfnConsolePrint)("CVoiceStatus::UpdateServerState: pLevelName[0]==0\n");
      return 1;
    }
  }
  return 1;
}


// __MsgFunc_ResetFade  @ 00082460
int __MsgFunc_ResetFade(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_ResetFade(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_ResetHUD  @ 000823f0
int __MsgFunc_ResetHUD(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHud::MsgFunc_ResetHUD(&gHUD,pszName,iSize,pbuf);
  return iVar1;
}


// __MsgFunc_SayText  @ 0009e3e0
int __MsgFunc_SayText(char *pszName,int iSize,void *pbuf)

{
  char *__needle;
  bool bVar1;
  int clientIndex;
  char *__haystack;
  char *pcVar2;
  float *pfVar3;
  int line;
  size_t sVar4;
  
                    /* Unresolved local var: int client_index@[???] */
  BEGIN_READ(pbuf,iSize);
  clientIndex = READ_BYTE();
  __haystack = READ_STRING();
                    /* Unresolved local var: int i@[???] */
  if ((gViewPort != (TeamFortressViewport *)0x0) &&
     (bVar1 = TeamFortressViewport::AllowedToPrintText(gViewPort), !bVar1)) {
    (*gEngfuncs.pfnConsolePrint)(__haystack);
    return 1;
  }
  line = 0;
  if ((((g_szLineBuffer[0][0] != '\0') && (line = 1, g_szLineBuffer[1][0] != '\0')) &&
      (line = 2, g_szLineBuffer[2][0] != '\0')) &&
     ((line = 3, g_szLineBuffer[3][0] != '\0' && (line = 4, g_szLineBuffer[4][0] != '\0')))) {
    while( true ) {
      (*gEngfuncs.pfnConsolePrint)(g_szLineBuffer[0]);
      g_szLineBuffer[5][0] = '\0';
      memmove(g_szLineBuffer,g_szLineBuffer + 1,0x500);
      memmove(g_pflNameColors,g_pflNameColors + 1,0x14);
      memmove(g_iNameLengths,g_iNameLengths + 1,0x14);
      g_szLineBuffer[4][0] = '\0';
      if (g_szLineBuffer[0][0] != ' ') break;
      g_szLineBuffer[0][0] = '\x02';
    }
    line = 4;
  }
  g_iNameLengths[line] = 0;
  g_pflNameColors[line] = (float *)0x0;
  if ((*__haystack == '\x02') && (0 < clientIndex)) {
                    /* Unresolved local var: char * pName@[???] */
    (*gEngfuncs.pfnGetPlayerInfo)(clientIndex,g_PlayerInfoList + clientIndex);
    __needle = g_PlayerInfoList[clientIndex].name;
                    /* Unresolved local var: char * nameInString@[DW_OP_reg1(ECX)] */
    if ((__needle != (char *)0x0) && (pcVar2 = strstr(__haystack,__needle), pcVar2 != (char *)0x0))
    {
      sVar4 = strlen(__needle);
      g_iNameLengths[line] = (int)(pcVar2 + (sVar4 - (int)__haystack));
      pfVar3 = GetClientColor(clientIndex);
      g_pflNameColors[line] = pfVar3;
    }
  }
  sVar4 = iSize - 1;
  if ((int)sVar4 < 0x100) {
    sVar4 = 0x100;
  }
  strncpy(g_szLineBuffer[line],__haystack,sVar4);
  CHudSayText::EnsureTextFitsInOneLineAndWrapIfHaveTo(&gHUD.m_SayText,line);
  if (line == 0) {
    flScrollTime = gHUD.m_flTime + (gHUD.m_SayText.m_HUD_saytext_time)->value;
  }
  gHUD.m_SayText.super_CHudBase.m_iFlags = gHUD.m_SayText.super_CHudBase.m_iFlags | 1;
  (*gEngfuncs.pfnPlaySoundByName)("misc/talk.wav",1.0);
  Y_START = gHUD.m_scrinfo.iHeight + -0x3c + line_height * -7;
  return 1;
}


// __MsgFunc_ScoreInfo  @ 000825a0
int __MsgFunc_ScoreInfo(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_ScoreInfo(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_SecAmmoIcon  @ 0008af20
int __MsgFunc_SecAmmoIcon(char *pszName,int iSize,void *pbuf)

{
  char *SpriteName;
  
  BEGIN_READ(pbuf,iSize);
  SpriteName = READ_STRING();
  gHUD.m_AmmoSecondary.m_HUD_ammoicon = CHud::GetSpriteIndex(&gHUD,SpriteName);
  return 1;
}


// __MsgFunc_SecAmmoVal  @ 0008af60
int __MsgFunc_SecAmmoVal(char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int index@[???]
                       Unresolved local var: int count@[???] */
  BEGIN_READ(pbuf,iSize);
  uVar1 = READ_BYTE();
  if (3 < uVar1) {
    return 1;
  }
  iVar2 = READ_BYTE();
  gHUD.m_AmmoSecondary.m_iAmmoAmounts[uVar1] = iVar2;
  iVar2 = gHUD.m_AmmoSecondary.super_CHudBase.m_iFlags;
                    /* Unresolved local var: int i@[???] */
  iVar5 = 0;
  if (-1 < gHUD.m_AmmoSecondary.m_iAmmoAmounts[0]) {
    iVar5 = gHUD.m_AmmoSecondary.m_iAmmoAmounts[0];
  }
  gHUD.m_AmmoSecondary.super_CHudBase.m_iFlags = gHUD.m_AmmoSecondary.super_CHudBase.m_iFlags | 1;
  iVar4 = 0;
  if (-1 < gHUD.m_AmmoSecondary.m_iAmmoAmounts[1]) {
    iVar4 = gHUD.m_AmmoSecondary.m_iAmmoAmounts[1];
  }
  iVar6 = 0;
  if (-1 < gHUD.m_AmmoSecondary.m_iAmmoAmounts[2]) {
    iVar6 = gHUD.m_AmmoSecondary.m_iAmmoAmounts[2];
  }
  iVar3 = 0;
  if (-1 < gHUD.m_AmmoSecondary.m_iAmmoAmounts[3]) {
    iVar3 = gHUD.m_AmmoSecondary.m_iAmmoAmounts[3];
  }
  if (iVar3 + iVar4 + iVar5 + iVar6 != 0) {
    gHUD.m_AmmoSecondary.m_fFade = 200.0;
    return 1;
  }
  gHUD.m_AmmoSecondary.super_CHudBase.m_iFlags = iVar2 & 0xfffffffe;
  return 1;
}


// __MsgFunc_ServerName  @ 000825e0
int __MsgFunc_ServerName(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_ServerName(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_SetFOV  @ 00082990
int __MsgFunc_SetFOV(char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  longdouble lVar5;
  
                    /* Unresolved local var: int newfov@[???]
                       Unresolved local var: int def_fov@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar3 = READ_BYTE();
  lVar5 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("default_fov");
  if ((cl_lw == (cvar_t *)0x0) || (cl_lw->value == 0.0)) {
    g_lastFOV = (float)iVar3;
    iVar4 = (int)lVar5;
    gHUD.m_iFOV = iVar4;
    if ((iVar3 != 0) && (gHUD.m_iFOV = iVar3, iVar3 != iVar4)) {
      fVar2 = g_lastFOV / (float)iVar4;
      fVar1 = sensitivity->value;
      lVar5 = (longdouble)(*gEngfuncs.pfnGetCvarFloat)("zoom_sensitivity_ratio");
      gHUD.m_flMouseSensitivity = (float)((longdouble)(fVar2 * fVar1) * lVar5);
      return 1;
    }
    gHUD.m_flMouseSensitivity = 0.0;
  }
  return 1;
}


// __MsgFunc_ShowMenu  @ 0009a280
int __MsgFunc_ShowMenu(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  char *local_10 [2];
  
                    /* Unresolved local var: char * temp@[???]
                       Unresolved local var: int DisplayTime@[???]
                       Unresolved local var: int NeedMore@[???] */
  local_10[0] = (char *)0x0;
  BEGIN_READ(pbuf,iSize);
  gHUD.m_Menu.m_bitsValidSlots = READ_SHORT();
  iVar1 = READ_CHAR();
  iVar2 = READ_BYTE();
  if (iVar1 < 1) {
    gHUD.m_Menu.m_flShutoffTime = -1.0;
  }
  else {
    gHUD.m_Menu.m_flShutoffTime = (float)iVar1 + gHUD.m_flTime;
  }
  if (gHUD.m_Menu.m_bitsValidSlots == 0) {
    gHUD.m_Menu.super_CHudBase.m_iFlags = gHUD.m_Menu.super_CHudBase.m_iFlags & 0xfffffffe;
    gHUD.m_Menu.m_fMenuDisplayed = 0;
  }
  else {
    puVar7 = (uint *)g_szPrelocalisedMenuString;
    if (gHUD.m_Menu.m_fWaitingForMore == 0) {
      pcVar3 = READ_STRING();
      strncpy(g_szPrelocalisedMenuString,pcVar3,0x200);
    }
    else {
      do {
        puVar6 = puVar7;
        uVar4 = *puVar6 + 0xfefefeff & ~*puVar6;
        uVar5 = uVar4 & 0x80808080;
        puVar7 = puVar6 + 1;
      } while (uVar5 == 0);
      if ((uVar4 & 0x8080) == 0) {
        puVar7 = (uint *)((int)puVar6 + 6);
        uVar5 = uVar5 >> 0x10;
      }
      pcVar3 = READ_STRING();
      strncat(g_szPrelocalisedMenuString,pcVar3,
              0x200 - ((int)puVar7 + (-0x12aee3 - (uint)CARRY1((byte)uVar5,(byte)uVar5))));
    }
    g_szPrelocalisedMenuString[0x1ff] = '\0';
    if (iVar2 == 0) {
      g_szPrelocalisedMenuString[0x1ff] = '\0';
      pcVar3 = CHudTextMessage::BufferedLocaliseTextString(g_szPrelocalisedMenuString);
      strcpy(g_szMenuString,pcVar3);
      iVar1 = KB_ConvertString(g_szMenuString,local_10);
      pcVar3 = local_10[0];
      if (iVar1 != 0) {
        strcpy(g_szMenuString,local_10[0]);
        free(pcVar3);
      }
    }
    gHUD.m_Menu.m_fMenuDisplayed = 1;
    gHUD.m_Menu.super_CHudBase.m_iFlags = gHUD.m_Menu.super_CHudBase.m_iFlags | 1;
  }
  gHUD.m_Menu.m_fWaitingForMore = iVar2;
  return 1;
}


// __MsgFunc_SpecFade  @ 000824a0
int __MsgFunc_SpecFade(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_SpecFade(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_Spectator  @ 000824e0
int __MsgFunc_Spectator(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_Spectator(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_StatusIcon  @ 0009e9c0
int __MsgFunc_StatusIcon(char *pszName,int iSize,void *pbuf)

{
  icon_sprite_t *__dest;
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  wrect_t *pwVar6;
  cl_entity_s *pcVar7;
  uint uVar8;
  HSPRITE HVar9;
  int iVar10;
  
                    /* Unresolved local var: int ShouldEnable@[???]
                       Unresolved local var: char * pszIconName@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  pcVar2 = READ_STRING();
  if (iVar1 != 0) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???] */
    iVar1 = READ_BYTE();
    iVar3 = READ_BYTE();
    iVar4 = READ_BYTE();
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int spr_index@[???] */
    uVar8 = 0;
    iVar5 = strcasecmp(gHUD.m_StatusIcons.m_IconList[0].szSpriteName,pcVar2);
    if (iVar5 != 0) {
      uVar8 = 1;
      iVar5 = strcasecmp(gHUD.m_StatusIcons.m_IconList[1].szSpriteName,pcVar2);
      if (iVar5 != 0) {
        uVar8 = 2;
        iVar5 = strcasecmp(gHUD.m_StatusIcons.m_IconList[2].szSpriteName,pcVar2);
        if (iVar5 != 0) {
          uVar8 = 3;
          iVar5 = strcasecmp(gHUD.m_StatusIcons.m_IconList[3].szSpriteName,pcVar2);
          if ((((iVar5 != 0) && (uVar8 = 0, gHUD.m_StatusIcons.m_IconList[0].spr != 0)) &&
              (uVar8 = 1, gHUD.m_StatusIcons.m_IconList[1].spr != 0)) &&
             (uVar8 = 2, gHUD.m_StatusIcons.m_IconList[2].spr != 0)) {
            uVar8 = -(uint)(gHUD.m_StatusIcons.m_IconList[3].spr == 0) & 3;
          }
        }
      }
    }
    iVar5 = CHud::GetSpriteIndex(&gHUD,pcVar2);
    pwVar6 = gHUD.m_rgrcRects;
    HVar9 = 0;
    if (-1 < iVar5) {
      HVar9 = gHUD.m_rghSprites[iVar5];
    }
    iVar10 = uVar8 * 0x30;
    *(HSPRITE *)((int)&gHUD.m_AmmoSecondary + iVar10 + 0x6c) = HVar9;
    pwVar6 = pwVar6 + iVar5;
    *(int *)((int)&gHUD.m_AmmoSecondary + iVar10 + 0x70) = pwVar6->left;
    *(int *)((int)&gHUD.m_AmmoSecondary + iVar10 + 0x74) = pwVar6->right;
    *(int *)((int)&gHUD.m_AmmoSecondary + iVar10 + 0x78) = pwVar6->top;
    *(int *)((int)&gHUD.m_AmmoSecondary + iVar10 + 0x7c) = pwVar6->bottom;
    iVar5 = uVar8 * 0x30;
    *(char *)((int)&gHUD.m_AmmoSecondary + iVar5 + 0x80) = (char)iVar1;
    *(char *)((int)&gHUD.m_AmmoSecondary + iVar5 + 0x81) = (char)iVar3;
    __dest = gHUD.m_StatusIcons.m_IconList + uVar8;
    *(char *)((int)&gHUD.m_AmmoSecondary + iVar5 + 0x82) = (char)iVar4;
    strcpy(__dest->szSpriteName,pcVar2);
    pcVar2 = strstr(__dest->szSpriteName,"grenade");
    if (pcVar2 != (char *)0x0) {
                    /* Unresolved local var: cl_entity_t.conflict * pthisplayer@[???] */
      pcVar7 = (*gEngfuncs.GetLocalPlayer)();
      (*(gEngfuncs.pEventAPI)->EV_PlaySound)
                (pcVar7->index,&(pcVar7->origin).x,6,"weapons/timer.wav",1.0,0.8,0,100);
    }
    gHUD.m_StatusIcons.super_CHudBase.m_iFlags = gHUD.m_StatusIcons.super_CHudBase.m_iFlags | 1;
    return 1;
  }
                    /* Unresolved local var: int i@[???] */
  iVar1 = strcasecmp(gHUD.m_StatusIcons.m_IconList[0].szSpriteName,pcVar2);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = strcasecmp(gHUD.m_StatusIcons.m_IconList[1].szSpriteName,pcVar2);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = strcasecmp(gHUD.m_StatusIcons.m_IconList[2].szSpriteName,pcVar2);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = strcasecmp(gHUD.m_StatusIcons.m_IconList[3].szSpriteName,pcVar2);
        if (iVar1 != 0) {
          return 1;
        }
        iVar1 = 3;
      }
    }
  }
  uVar8 = 0;
  iVar1 = iVar1 * 0x30;
  do {
    *(undefined4 *)(iVar1 + 0x11d740 + uVar8) = 0;
    *(undefined4 *)(iVar1 + 0x11d744 + uVar8) = 0;
    *(undefined4 *)(iVar1 + 0x11d748 + uVar8) = 0;
    *(undefined4 *)(iVar1 + 0x11d74c + uVar8) = 0;
    uVar8 = uVar8 + 0x10;
  } while (uVar8 < 0x30);
  return 1;
}


// __MsgFunc_StatusText  @ 0009f3b0
int __MsgFunc_StatusText(char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  char *__src;
  
                    /* Unresolved local var: int line@[???] */
  BEGIN_READ(pbuf,iSize);
  uVar1 = READ_BYTE();
  if (uVar1 < 4) {
    __src = READ_STRING();
    strncpy(gHUD.m_StatusBar.m_szStatusText[uVar1],__src,0x80);
    gHUD.m_StatusBar.m_szStatusText[uVar1][0x7f] = '\0';
    gHUD.m_StatusBar.super_CHudBase.m_iFlags = gHUD.m_StatusBar.super_CHudBase.m_iFlags | 1;
    gHUD.m_StatusBar.m_bReparseString = 1;
  }
  return 1;
}


// __MsgFunc_StatusValue  @ 0009f360
int __MsgFunc_StatusValue(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int index@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  if (iVar1 - 1U < 8) {
    iVar2 = READ_SHORT();
    gHUD.m_StatusBar.m_iStatusValues[iVar1] = iVar2;
    gHUD.m_StatusBar.m_bReparseString = 1;
  }
  return 1;
}


// __MsgFunc_TeamInfo  @ 00082520
int __MsgFunc_TeamInfo(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_TeamInfo(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_TeamNames  @ 000827a0
int __MsgFunc_TeamNames(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_TeamNames(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_TeamScore  @ 00082560
int __MsgFunc_TeamScore(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_TeamScore(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_TextMsg  @ 000a60f0
int __MsgFunc_TextMsg(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  client_textmessage_s *pcVar8;
  char *pcVar9;
  
                    /* Unresolved local var: int msg_dest@[???]
                       Unresolved local var: char * msg_text@[???]
                       Unresolved local var: char * sstr1@[???]
                       Unresolved local var: char * sstr2@[???]
                       Unresolved local var: char * sstr3@[???]
                       Unresolved local var: char * sstr4@[???]
                       Unresolved local var: char * psz@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar4 = READ_BYTE();
  pcVar5 = READ_STRING();
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[DW_OP_reg0(EAX)] */
    if ((((*pcVar5 == '#') &&
         (pcVar8 = (*gEngfuncs.pfnTextMessageGet)(pcVar5 + 1), pcVar8 != (client_textmessage_s *)0x0
         )) && (pcVar9 = pcVar8->pMessage, pcVar9 != (char *)0x0)) &&
       (pcVar5 = pcVar9, pcVar8->effect < 0)) {
      iVar4 = -pcVar8->effect;
    }
  }
  strncpy(CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[0],pcVar5,0x80);
  CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[0][0x7f] = '\0';
  pcVar5 = READ_STRING();
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[DW_OP_reg0(EAX)] */
    if (((*pcVar5 == '#') &&
        (pcVar8 = (*gEngfuncs.pfnTextMessageGet)(pcVar5 + 1), pcVar8 != (client_textmessage_s *)0x0)
        ) && (pcVar8->pMessage != (char *)0x0)) {
      pcVar5 = pcVar8->pMessage;
    }
  }
  strncpy(CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[1],pcVar5,0x80);
                    /* Unresolved local var: int s@[???] */
  CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[1][0x7f] = '\0';
  pcVar5 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[1];
  do {
    pcVar9 = pcVar5;
    uVar6 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar7 = uVar6 & 0x80808080;
    pcVar5 = pcVar9 + 4;
  } while (uVar7 == 0);
  if ((uVar6 & 0x8080) == 0) {
    pcVar5 = pcVar9 + 6;
    uVar7 = uVar7 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar7,(byte)uVar7);
  if ((pcVar5[iVar1 + -4] == '\r') || (pcVar5[iVar1 + -4] == '\n')) {
    pcVar5[iVar1 + -4] = '\0';
  }
  pcVar5 = READ_STRING();
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[DW_OP_reg0(EAX)] */
    if (((*pcVar5 == '#') &&
        (pcVar8 = (*gEngfuncs.pfnTextMessageGet)(pcVar5 + 1), pcVar8 != (client_textmessage_s *)0x0)
        ) && (pcVar8->pMessage != (char *)0x0)) {
      pcVar5 = pcVar8->pMessage;
    }
  }
  strncpy(CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[2],pcVar5,0x80);
                    /* Unresolved local var: int s@[???] */
  CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[2][0x7f] = '\0';
  pcVar5 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[2];
  do {
    pcVar9 = pcVar5;
    uVar6 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar7 = uVar6 & 0x80808080;
    pcVar5 = pcVar9 + 4;
  } while (uVar7 == 0);
  if ((uVar6 & 0x8080) == 0) {
    pcVar5 = pcVar9 + 6;
    uVar7 = uVar7 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar7,(byte)uVar7);
  if ((pcVar5[iVar1 + -4] == '\r') || (pcVar5[iVar1 + -4] == '\n')) {
    pcVar5[iVar1 + -4] = '\0';
  }
  pcVar5 = READ_STRING();
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[DW_OP_reg0(EAX)] */
    if (((*pcVar5 == '#') &&
        (pcVar8 = (*gEngfuncs.pfnTextMessageGet)(pcVar5 + 1), pcVar8 != (client_textmessage_s *)0x0)
        ) && (pcVar8->pMessage != (char *)0x0)) {
      pcVar5 = pcVar8->pMessage;
    }
  }
  strncpy(CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[3],pcVar5,0x80);
                    /* Unresolved local var: int s@[???] */
  CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[3][0x7f] = '\0';
  pcVar5 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[3];
  do {
    pcVar9 = pcVar5;
    uVar6 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar7 = uVar6 & 0x80808080;
    pcVar5 = pcVar9 + 4;
  } while (uVar7 == 0);
  if ((uVar6 & 0x8080) == 0) {
    pcVar5 = pcVar9 + 6;
    uVar7 = uVar7 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar7,(byte)uVar7);
  if ((pcVar5[iVar1 + -4] == '\r') || (pcVar5[iVar1 + -4] == '\n')) {
    pcVar5[iVar1 + -4] = '\0';
  }
  pcVar5 = READ_STRING();
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "";
  }
  else {
                    /* Unresolved local var: client_textmessage_t * clmsg@[DW_OP_reg0(EAX)] */
    if (((*pcVar5 == '#') &&
        (pcVar8 = (*gEngfuncs.pfnTextMessageGet)(pcVar5 + 1), pcVar8 != (client_textmessage_s *)0x0)
        ) && (pcVar8->pMessage != (char *)0x0)) {
      pcVar5 = pcVar8->pMessage;
    }
  }
  strncpy(CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[4],pcVar5,0x80);
                    /* Unresolved local var: int s@[???] */
  CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[4][0x7f] = '\0';
  pcVar5 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[4];
  do {
    pcVar9 = pcVar5;
    uVar6 = *(uint *)pcVar9 + 0xfefefeff & ~*(uint *)pcVar9;
    uVar7 = uVar6 & 0x80808080;
    pcVar5 = pcVar9 + 4;
  } while (uVar7 == 0);
  if ((uVar6 & 0x8080) == 0) {
    pcVar5 = pcVar9 + 6;
    uVar7 = uVar7 >> 0x10;
  }
  iVar1 = -(uint)CARRY1((byte)uVar7,(byte)uVar7);
  if ((pcVar5[iVar1 + -4] == '\r') || (pcVar5[iVar1 + -4] == '\n')) {
    pcVar5[iVar1 + -4] = '\0';
  }
  if ((gViewPort == (TeamFortressViewport *)0x0) ||
     (bVar2 = TeamFortressViewport::AllowedToPrintText(gViewPort), bVar2)) {
    if (iVar4 == 2) {
      safe_sprintf(CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5],0x80,
                   CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[0],0x131540,0x1315c0,
                   0x131640,0x1316c0);
                    /* Unresolved local var: char * ch@[???] */
      if (CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5][0] != '\0') {
        pcVar5 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5];
        cVar3 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5][0];
        do {
          if (cVar3 == '\r') {
            *pcVar5 = '\n';
          }
          pcVar5 = pcVar5 + 1;
          cVar3 = *pcVar5;
        } while (cVar3 != '\0');
      }
LAB_000a6490:
      (*gEngfuncs.pfnConsolePrint)((char *)0x131740);
      return 1;
    }
    if (iVar4 < 3) {
      if (iVar4 == 1) {
        CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5][0] = '\x01';
        safe_sprintf(CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5] + 1,0x80,
                     CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[0],0x131540,0x1315c0,
                     0x131640,0x1316c0);
                    /* Unresolved local var: char * ch@[???] */
        if (CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5][0] != '\0') {
          pcVar5 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5];
          cVar3 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5][0];
          do {
            while (cVar3 == '\r') {
              *pcVar5 = '\n';
              pcVar5 = pcVar5 + 1;
              cVar3 = *pcVar5;
              if (cVar3 == '\0') goto LAB_000a6490;
            }
            pcVar5 = pcVar5 + 1;
            cVar3 = *pcVar5;
          } while (cVar3 != '\0');
        }
        goto LAB_000a6490;
      }
    }
    else {
      if (iVar4 == 3) {
        safe_sprintf(CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5],0x80,
                     CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[0],0x131540,0x1315c0,
                     0x131640,0x1316c0);
                    /* Unresolved local var: char * ch@[???] */
        if (CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5][0] != '\0') {
          pcVar5 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5];
          cVar3 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5][0];
          do {
            while (cVar3 == '\r') {
              *pcVar5 = '\n';
              pcVar5 = pcVar5 + 1;
              cVar3 = *pcVar5;
              if (cVar3 == '\0') goto LAB_000a6687;
            }
            pcVar5 = pcVar5 + 1;
            cVar3 = *pcVar5;
          } while (cVar3 != '\0');
        }
LAB_000a6687:
        CHudSayText::SayTextPrint
                  (&gHUD.m_SayText,CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5],0x80,
                   -1);
        return 1;
      }
      if (iVar4 == 4) {
        safe_sprintf(CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5],0x80,
                     CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[0],0x131540,0x1315c0,
                     0x131640,0x1316c0);
                    /* Unresolved local var: char * ch@[???] */
        if (CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5][0] != '\0') {
          pcVar5 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5];
          cVar3 = CHudTextMessage::MsgFunc_TextMsg::lexical_block_0::szBuf[5][0];
          do {
            while (cVar3 == '\r') {
              *pcVar5 = '\n';
              pcVar5 = pcVar5 + 1;
              cVar3 = *pcVar5;
              if (cVar3 == '\0') goto LAB_000a651f;
            }
            pcVar5 = pcVar5 + 1;
            cVar3 = *pcVar5;
          } while (cVar3 != '\0');
        }
LAB_000a651f:
        (*gEngfuncs.pfnCenterPrint)((char *)0x131740);
        return 1;
      }
    }
  }
  return 1;
}


// __MsgFunc_Train  @ 000a72f0
int __MsgFunc_Train(char *pszName,int iSize,void *pbuf)

{
  BEGIN_READ(pbuf,iSize);
  gHUD.m_Train.m_iPos = READ_BYTE();
  if (gHUD.m_Train.m_iPos == 0) {
    gHUD.m_Train.super_CHudBase.m_iFlags = gHUD.m_Train.super_CHudBase.m_iFlags & 0xfffffffe;
    return 1;
  }
  gHUD.m_Train.super_CHudBase.m_iFlags = gHUD.m_Train.super_CHudBase.m_iFlags | 1;
  return 1;
}


// __MsgFunc_VGUIMenu  @ 000826e0
int __MsgFunc_VGUIMenu(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_VGUIMenu(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_ValClass  @ 000827e0
int __MsgFunc_ValClass(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = 0;
  if (gViewPort != (TeamFortressViewport *)0x0) {
    iVar1 = TeamFortressViewport::MsgFunc_ValClass(gViewPort,pszName,iSize,pbuf);
  }
  return iVar1;
}


// __MsgFunc_ViewMode  @ 00082930
int __MsgFunc_ViewMode(char *pszName,int iSize,void *pbuf)

{
  CHud::MsgFunc_ViewMode(&gHUD,pszName,iSize,pbuf);
  return 1;
}


// __MsgFunc_VoiceMask  @ 000c77e0
int __MsgFunc_VoiceMask(char *pszName,int iSize,void *pbuf)

{
  if (g_pInternalVoiceStatus != (CVoiceStatus *)0x0) {
    CVoiceStatus::HandleVoiceMaskMsg(g_pInternalVoiceStatus,iSize,pbuf);
  }
  return 1;
}


// __MsgFunc_WeapPickup  @ 000858a0
int __MsgFunc_WeapPickup(char *pszName,int iSize,void *pbuf)

{
  int iId;
  
                    /* Unresolved local var: int iIndex@[???] */
  BEGIN_READ(pbuf,iSize);
  iId = READ_BYTE();
  HistoryResource::AddToHistory(&gHR,2,iId,0);
  return 1;
}


// __MsgFunc_WeaponList  @ 00088130
int __MsgFunc_WeaponList(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHudAmmo::MsgFunc_WeaponList(&gHUD.m_Ammo,pszName,iSize,pbuf);
  return iVar1;
}


// __do_global_ctors_aux  @ 000e1868
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void __do_global_ctors_aux(void)

{
  undefined **ppuVar1;
  
  for (ppuVar1 = &PTR__GLOBAL__sub_I_g_VoiceStatus_00108870; (code *)*ppuVar1 != (code *)0xffffffff;
      ppuVar1 = ppuVar1 + -1) {
    (*(code *)*ppuVar1)();
  }
  return;
}


// __do_global_dtors_aux  @ 0006e7f4
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Removing unreachable block (ram,0x0006e83d) */

void __do_global_dtors_aux(void)

{
  if (completed_5793 == '\0') {
    __cxa_finalize(__dso_handle);
    completed_5793 = '\x01';
  }
  return;
}


// __i686.get_pc_thunk.bx  @ 0006e89a
/* WARNING: This is an inlined function */

void __i686_get_pc_thunk_bx(void)

{
  return;
}


// __tcf_0  @ 000b1810
void __tcf_0(void *param_1)

{
  int *piVar1;
  
  piVar1 = &CSchemeManager::CSchemeManager::lexical_block_0::tmpSchemes[0x3f].ownFontPointer;
  do {
    if ((cvar_t *)*piVar1 != (cvar_t *)0x0) {
      operator_delete((cvar_t *)piVar1[-1]);
    }
    piVar1 = piVar1 + -0x1f;
  } while ((cvar_t **)piVar1 != &g_CV_BitmapFonts);
  return;
}


// _fini  @ 000e1890
void _fini(void)

{
  __do_global_dtors_aux();
  return;
}


// _init  @ 0006e1ec
int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  __gmon_start__();
  frame_dummy();
  iVar1 = __do_global_ctors_aux();
  return iVar1;
}


