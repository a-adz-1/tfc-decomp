// SUB_CallUseToggle__11CBaseEntity  @ 0010e140
void SUB_CallUseToggle__11CBaseEntity(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0xb0))(param_1,param_1,param_1,3,0);
  return;
}


// SUB_DoNothing__11CBaseEntity  @ 000f03e0
void SUB_DoNothing__11CBaseEntity(void)

{
  return;
}


// SUB_FadeOut__11CBaseEntity  @ 000a4f90
void SUB_FadeOut__11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 300);
  if ((byte)(7.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 7.0) << 0xe) >> 8)) == 1) {
    *(float *)(iVar2 + 300) = *(float *)(iVar2 + 300) - 7.0;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  }
  else {
    *(undefined4 *)(*param_1 + 300) = 0;
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.2;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  return;
}


// SUB_Remove__11CBaseEntity  @ 000f0380
void SUB_Remove__11CBaseEntity(int *param_1)

{
  float fVar1;
  
  UpdateOnRemove__11CBaseEntity(param_1);
  fVar1 = *(float *)(*param_1 + 0x140);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    *(undefined4 *)(*param_1 + 0x140) = 0;
    (*DAT_001755b4)(2,"SUB_Remove called on entity with health > 0\n");
  }
  (*DAT_00175518)(*(undefined4 *)(*param_1 + 0x1e8));
  return;
}


// SUB_StartFadeOut__11CBaseEntity  @ 000a4f00
void SUB_StartFadeOut__11CBaseEntity(int *param_1)

{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x128) == 0) {
    *(undefined4 *)(*param_1 + 300) = 0x437f0000;
    *(undefined4 *)(*param_1 + 0x128) = 2;
  }
  *(undefined4 *)(*param_1 + 0xec) = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_00175484;
  *(undefined4 *)(iVar1 + 100) = DAT_00175488;
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_FadeOut__11CBaseEntity;
  return;
}


// SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf  @ 000f0640
void SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf
               (int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  bool bVar2;
  float *pfVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (param_2 == 0) {
    iVar5 = 0;
  }
  else {
    iVar7 = (**(code **)(*(int *)(param_2 + 0x3c8) + 0x28))(param_2);
    iVar5 = param_2;
    if (iVar7 != 2) goto LAB_000f068b;
  }
  DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,iVar5,1);
LAB_000f068b:
  if ((*(int *)(*param_1 + 0x1a8) != 0) || (param_1[0xf4] != 0)) {
    fVar1 = (float)param_1[0xf3];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      if (param_1[0xf4] != 0) {
        (*DAT_001755b4)(2,"KillTarget: %s\n",param_1[0xf4] + (int)gpGlobals[0x26]);
        iVar5 = param_1[0xf4] + (int)gpGlobals[0x26];
        iVar7 = 0;
        while( true ) {
          iVar7 = (*DAT_001754f8)(iVar7,"targetname",iVar5);
          bVar2 = false;
          if ((iVar7 == 0) || (iVar5 = (*DAT_001755d8)(iVar7), iVar5 == 0)) {
            bVar2 = true;
          }
          if (bVar2) break;
          iVar5 = iVar7;
          if ((iVar7 == 0) && (iVar5 = (*DAT_001755d4)(0), iVar5 == 0)) {
            uVar6 = 0;
          }
          else {
            uVar6 = *(undefined4 *)(iVar5 + 0xd8);
          }
          UTIL_Remove__FP11CBaseEntity(uVar6);
          (*DAT_001755b4)(2,"killing %s\n",*(int *)(iVar7 + 0xdc) + (int)gpGlobals[0x26]);
          iVar5 = param_1[0xf4] + (int)gpGlobals[0x26];
        }
      }
      if (*(int *)(*param_1 + 0x1a8) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(*param_1 + 0x1a8) + (int)gpGlobals[0x26],param_2,param_1,param_3,param_4
                  );
      }
    }
    else {
      piVar4 = (int *)GetClassPtr__H1Z10CBaseDelay_PX01_PX01(0);
      pfVar3 = gpGlobals;
      *(int *)*piVar4 = (int)"DelayedUse" - (int)gpGlobals[0x26];
      *(float *)(*piVar4 + 0xe4) = *pfVar3 + (float)param_1[0xf3];
      piVar4[3] = -0x10000;
      piVar4[4] = (int)DelayThink__10CBaseDelay;
      *(undefined4 *)(*piVar4 + 0x160) = param_3;
      piVar4[0xf4] = param_1[0xf4];
      piVar4[0xf3] = 0;
      *(undefined4 *)(*piVar4 + 0x1a8) = *(undefined4 *)(*param_1 + 0x1a8);
    }
  }
  return;
}


// SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf  @ 000f0500
void SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(int *)(*param_1 + 0x1a8) != 0) {
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
              (*(int *)(*param_1 + 0x1a8) + *(int *)(gpGlobals + 0x98),param_2,param_1,param_3,
               param_4);
  }
  return;
}


