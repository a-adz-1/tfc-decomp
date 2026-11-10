// SUB_CallUseToggle__11CBaseEntity  @ 00112bbc
void SUB_CallUseToggle__11CBaseEntity(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0x454) + 0xb8))(param_1,param_1,param_1,3,0);
  return;
}


// SUB_DoNothing__11CBaseEntity  @ 000f6808
void SUB_DoNothing__11CBaseEntity(void)

{
  return;
}


// SUB_FadeOut__11CBaseEntity  @ 00097348
void SUB_FadeOut__11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = *param_1;
  fVar1 = *(float *)(iVar2 + 0x14c);
  if ((byte)((fVar1 < 7.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 7.0) << 0xe) >> 8)) - 1) < 0x40) {
    *(undefined4 *)(iVar2 + 0x14c) = 0;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
  }
  else {
    *(float *)(iVar2 + 0x14c) = fVar1 - 7.0;
    *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  }
  return;
}


// SUB_Remove__11CBaseEntity  @ 000f58c8
void SUB_Remove__11CBaseEntity(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (((*(byte *)(iVar2 + 0x1a6) & 1) != 0) && (iVar1 = 0, 0 < DAT_0019fb3c)) {
    do {
      if (*(int *)(DAT_0019fb30 + 8 + iVar1 * 0x18) == iVar2) {
        *(undefined4 *)(DAT_0019fb30 + 8 + iVar1 * 0x18) = 0;
        iVar2 = *param_1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_0019fb3c);
  }
  if (*(int *)(iVar2 + 4) != 0) {
    EntitySetState__12CGlobalStatei12GLOBALESTATE(&gGlobalState,*(int *)(iVar2 + 4),2);
    iVar2 = *param_1;
  }
  if (0.0 < *(float *)(iVar2 + 0x160)) {
    *(undefined4 *)(iVar2 + 0x160) = 0;
    (*DAT_0019f794)(2,"SUB_Remove called on entity with health > 0\n");
    iVar2 = *param_1;
  }
  (*DAT_0019f6f8)(*(undefined4 *)(iVar2 + 0x208));
  return;
}


// SUB_StartFadeOut__11CBaseEntity  @ 000973ec
void SUB_StartFadeOut__11CBaseEntity(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x148) == 0) {
    *(undefined4 *)(iVar1 + 0x14c) = 0x437f0000;
    *(undefined4 *)(*param_1 + 0x148) = 2;
    iVar1 = *param_1;
  }
  *(undefined4 *)(iVar1 + 0x10c) = 0;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x60) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 100) = DAT_0019f668;
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_FadeOut__11CBaseEntity;
  return;
}


// SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf  @ 000f5ac0
void SUB_UseTargets__10CBaseDelayP11CBaseEntity8USE_TYPEf
               (int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (param_2 != 0) {
    iVar3 = (**(code **)(*(int *)(param_2 + 0x454) + 0x2c))(param_2);
    if (iVar3 != 2) goto LAB_000f5b09;
  }
  DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,param_2,1);
LAB_000f5b09:
  if ((*(int *)(*param_1 + 0x1c8) != 0) || (param_1[0x117] != 0)) {
    fVar1 = (float)param_1[0x116];
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      if (param_1[0x117] != 0) {
        (*DAT_0019f794)(2,"KillTarget: %s\n",param_1[0x117] + (int)gpGlobals[0x26]);
        iVar3 = (*DAT_0019f6d8)(0,"targetname",param_1[0x117] + (int)gpGlobals[0x26]);
        do {
          bVar2 = false;
          if (iVar3 == 0) {
LAB_000f5cf7:
            bVar2 = true;
          }
          else {
            iVar5 = (*DAT_0019f7b8)(iVar3);
            if (iVar5 == 0) goto LAB_000f5cf7;
          }
          if (bVar2) break;
          iVar5 = iVar3;
          if (iVar3 == 0) {
            iVar5 = (*DAT_0019f7b4)(0);
            if (iVar5 != 0) goto LAB_000f5c6b;
            uVar6 = 0;
          }
          else {
LAB_000f5c6b:
            uVar6 = *(undefined4 *)(iVar5 + 0x7c);
          }
          UTIL_Remove__FP11CBaseEntity(uVar6);
          (*DAT_0019f794)(2,"killing %s\n",*(int *)(iVar3 + 0x80) + (int)gpGlobals[0x26]);
          iVar3 = (*DAT_0019f6d8)(iVar3,"targetname",param_1[0x117] + (int)gpGlobals[0x26]);
        } while( true );
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
      *(float *)(*piVar4 + 0x104) = *gpGlobals + (float)param_1[0x116];
      piVar4[3] = -0x10000;
      piVar4[4] = (int)DelayThink__10CBaseDelay;
      *(undefined4 *)(*piVar4 + 0x180) = param_3;
      piVar4[0x117] = param_1[0x117];
      piVar4[0x116] = 0;
      *(undefined4 *)(*piVar4 + 0x1c8) = *(undefined4 *)(*param_1 + 0x1c8);
    }
  }
  return;
}


// SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf  @ 000f6684
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


