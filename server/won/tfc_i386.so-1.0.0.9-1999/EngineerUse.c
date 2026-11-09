// EngineerUse__11CBaseEntityP11CBasePlayer  @ 0010dde0
undefined4 EngineerUse__11CBaseEntityP11CBasePlayer(void)

{
  return 0;
}


// EngineerUse__11CBasePlayerP11CBasePlayer  @ 000e3030
undefined4 EngineerUse__11CBasePlayerP11CBasePlayer(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar1 = *(float *)(*param_1 + 0x198);
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    *(int *)(*param_1 + 0x198) = param_1[0x3b];
  }
  iVar4 = 10;
  if (param_2[0x37] < 0xb) {
    iVar4 = param_2[0x37];
  }
  iVar3 = iVar4 * 5;
  fVar1 = (float)param_1[0x3c] - *(float *)(*param_1 + 0x19c);
  fVar2 = (float)iVar3;
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
    iVar3 = (int)ROUND(fVar1);
    iVar4 = (int)ROUND(ROUND((double)iVar3 * 0.25));
  }
  if (0 < iVar3) {
    *(float *)(*param_1 + 0x19c) = (float)iVar3 + *(float *)(*param_1 + 0x19c);
    if ((float)param_1[0x3c] < *(float *)(*param_1 + 0x19c)) {
      *(int *)(*param_1 + 0x19c) = param_1[0x3c];
    }
    param_2[0x37] = param_2[0x37] - iVar4;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_2 + 0x1e8),1,"items/r_item2.wav",0x3f800000,0x3f4ccccd,0,100);
  }
  return 1;
}


// EngineerUse__12CTFDispenserP11CBasePlayer  @ 000a8cf0
undefined4 EngineerUse__12CTFDispenserP11CBasePlayer(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = UTIL_dtos3__Fi((int)ROUND(*(float *)(*param_1 + 0x19c)),0);
  uVar1 = UTIL_dtos2__Fi(param_1[0x39],uVar1);
  uVar1 = UTIL_dtos1__Fi((int)ROUND(*(float *)(*param_1 + 0x140)),uVar1);
  ClientPrint__FP9entvars_tiPCcN42(*param_2,1,"#Dispenser_has",uVar1);
  param_2[0x45] = 0x41800000;
  __as__7EHANDLEP11CBaseEntity(param_2 + 0x4e,param_1);
  piVar2 = (int *)CreateTimer__11CBaseEntityi(param_2,0xc);
  *(undefined4 *)(*piVar2 + 0x170) = *(undefined4 *)(*param_1 + 0x1e8);
  piVar2[3] = -0x10000;
  piVar2[4] = (int)Timer_CheckBuildDistance__11CBaseEntity;
  *(float *)(*piVar2 + 0xe4) = *gpGlobals + 0.3;
  return 1;
}


// EngineerUse__12CTFSentrygunP11CBasePlayer  @ 000ea730
undefined4 EngineerUse__12CTFSentrygunP11CBasePlayer(int *param_1,int param_2)

{
  int *piVar1;
  
  *(undefined4 *)(param_2 + 0x114) = 0x41880000;
  __as__7EHANDLEP11CBaseEntity(param_2 + 0x138,param_1);
  piVar1 = (int *)CreateTimer__11CBaseEntityi(param_2,0xc);
  *(undefined4 *)(*piVar1 + 0x170) = *(undefined4 *)(*param_1 + 0x1e8);
  piVar1[3] = -0x10000;
  piVar1[4] = (int)Timer_CheckBuildDistance__11CBaseEntity;
  *(float *)(*piVar1 + 0xe4) = *gpGlobals + 0.3;
  return 1;
}


