// SUB_CallUseToggle__11CBaseEntity  @ 001003c4
void SUB_CallUseToggle__11CBaseEntity(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0xb0))(param_1,param_1,param_1,3,0);
  return;
}


// SUB_DoNothing__11CBaseEntity  @ 000e6c48
void SUB_DoNothing__11CBaseEntity(void)

{
  return;
}


// SUB_FadeOut__11CBaseEntity  @ 0008d94c
void SUB_FadeOut__11CBaseEntity(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(float *)(iVar1 + 0x14c) <= 7.0) {
    *(undefined4 *)(*param_1 + 0x14c) = 0;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
    *(float *)(iVar1 + 0x14c) = *(float *)(iVar1 + 0x14c) - 7.0;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// SUB_Remove__11CBaseEntity  @ 000e6bd8
void SUB_Remove__11CBaseEntity(int *param_1)

{
  UpdateOnRemove__11CBaseEntity(param_1);
  if (0.0 < *(float *)(*param_1 + 0x160)) {
    *(undefined4 *)(*param_1 + 0x160) = 0;
    (*DAT_001a7f34)(2,"SUB_Remove called on entity with health > 0\n");
  }
  (*DAT_001a7e98)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// SUB_StartFadeOut__11CBaseEntity  @ 0008d8b8
void SUB_StartFadeOut__11CBaseEntity(int *param_1)

{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x148) == 0) {
    *(undefined4 *)(*param_1 + 0x14c) = 0x437f0000;
    *(undefined4 *)(*param_1 + 0x148) = 2;
  }
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 100) = DAT_001a7e08;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_FadeOut__11CBaseEntity;
  return;
}


// SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf  @ 000e6f04
void SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf
               (int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
  if ((param_2 == 0) ||
     (iVar3 = (**(code **)(*(int *)(param_2 + 0x3d4) + 0x28))(param_2), iVar3 == 2)) {
    DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,param_2,1);
  }
  if ((*(int *)(*param_1 + 0x1c8) != 0) || (param_1[0xf7] != 0)) {
    fVar1 = (float)param_1[0xf6];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      if (param_1[0xf7] != 0) {
        (*DAT_001a7f34)(2,"KillTarget: %s\n",param_1[0xf7] + (int)gpGlobals[0x26]);
        iVar3 = param_1[0xf7] + (int)gpGlobals[0x26];
        iVar6 = 0;
        while( true ) {
          iVar6 = (*DAT_001a7e78)(iVar6,"targetname",iVar3);
          bVar2 = false;
          if ((iVar6 == 0) || (iVar3 = (*DAT_001a7f58)(iVar6), iVar3 == 0)) {
            bVar2 = true;
          }
          if (bVar2) break;
          iVar3 = iVar6;
          if ((iVar6 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
            uVar5 = 0;
          }
          else {
            uVar5 = *(undefined4 *)(iVar3 + 0x7c);
          }
          UTIL_Remove__FP11CBaseEntity(uVar5);
          (*DAT_001a7f34)(2,"killing %s\n",*(int *)(iVar6 + 0x80) + (int)gpGlobals[0x26]);
          iVar3 = param_1[0xf7] + (int)gpGlobals[0x26];
        }
      }
      if (*(int *)(*param_1 + 0x1c8) != 0) {
        FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                  (*(int *)(*param_1 + 0x1c8) + (int)gpGlobals[0x26],param_2,param_1,param_3,param_4
                  );
      }
    }
    else {
      piVar4 = (int *)GetClassPtr__H1Z10CBaseDelay_PX01_PX01(0);
      *(int *)*piVar4 = (int)"DelayedUse" - (int)gpGlobals[0x26];
      *(float *)(*piVar4 + 0x104) = *gpGlobals + (float)param_1[0xf6];
      piVar4[3] = -0x10000;
      piVar4[4] = (int)DelayThink__10CBaseDelay;
      *(undefined4 *)(*piVar4 + 0x180) = param_3;
      piVar4[0xf7] = param_1[0xf7];
      piVar4[0xf6] = 0;
      *(undefined4 *)(*piVar4 + 0x1c8) = *(undefined4 *)(*param_1 + 0x1c8);
    }
  }
  return;
}


// SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf  @ 000e6d88
void SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(int *)(*param_1 + 0x1c8) != 0) {
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
              (*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98),param_2,param_1,param_3,
               param_4);
  }
  return;
}


