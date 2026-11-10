// TeleportTouch__12CBaseTriggerP11CBaseEntity  @ 00114118
void TeleportTouch__12CBaseTriggerP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  iVar1 = *param_2;
  if (((((*(byte *)(iVar1 + 0x1a4) & 0x28) != 0) &&
       (iVar4 = UTIL_IsMasterTriggered__Fi(param_1[0x139]), iVar4 != 0)) &&
      ((((*(byte *)(*param_1 + 0x1a0) ^ 1) & 1) == 0 || ((*(byte *)(iVar1 + 0x1a4) & 0x20) == 0))))
     && (((*(byte *)(*param_1 + 0x1a0) & 2) == 0 || ((*(byte *)(iVar1 + 0x1a4) & 8) == 0)))) {
    iVar4 = (*DAT_001c1058)(0,"targetname",*(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98));
    bVar2 = false;
    if ((iVar4 == 0) || (iVar5 = (*DAT_001c1138)(iVar4), iVar5 == 0)) {
      bVar2 = true;
    }
    if ((!bVar2) &&
       (iVar5 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar5 != 0)
       ) {
      iVar5 = iVar4 + 0x80;
      if (iVar4 == 0) {
        iVar5 = 0;
      }
      local_c = *(undefined4 *)(iVar5 + 8);
      local_8 = *(undefined4 *)(iVar5 + 0xc);
      local_4 = *(float *)(iVar5 + 0x10);
      if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
        local_4 = local_4 - *(float *)(*param_2 + 0xe4);
      }
      local_4 = local_4 + 1.0;
      *(byte *)(iVar1 + 0x1a5) = *(byte *)(iVar1 + 0x1a5) & 0xfd;
      UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar1,&local_c);
      *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar4 + 0xd0);
      *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar4 + 0xd4);
      *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar4 + 0xd8);
      if ((*(byte *)(iVar1 + 0x1a4) & 8) != 0) {
        *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(iVar4 + 0xd0);
        *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(iVar4 + 0xd4);
        *(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(iVar4 + 0xd8);
      }
      *(undefined4 *)(iVar1 + 0xa0) = 1;
      uVar3 = g_vecZero;
      *(undefined4 *)(iVar1 + 0x2c) = g_vecZero;
      *(undefined4 *)(iVar1 + 0x30) = DAT_001c0fe4;
      *(undefined4 *)(iVar1 + 0x34) = DAT_001c0fe8;
      *(undefined4 *)(iVar1 + 0x20) = uVar3;
      *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x30);
      *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar1 + 0x34);
    }
  }
  return;
}


