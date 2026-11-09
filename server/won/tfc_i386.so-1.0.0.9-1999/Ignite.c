// Ignite__11CBasePlayerP9entvars_tT1  @ 000e24b0
void Ignite__11CBasePlayerP9entvars_tT1(int *param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  (**(code **)(param_1[0xf2] + 0x34))(param_1,param_2,param_3,0x40c00000,8);
  if (*gpGlobals < cb_prematch_time) {
    return;
  }
  fVar1 = (float)param_1[0x72];
  if ((byte)((4.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 4.0) << 0xe) >> 8)) - 1) < 0x40) {
    *(byte *)((int)param_1 + 0x8a) = *(byte *)((int)param_1 + 0x8a) | 2;
    return;
  }
  if (((*(byte *)(param_1 + 0xf) & 0x10) != 0) &&
     (fVar1 = *(float *)(*param_1 + 0x19c),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) {
    return;
  }
  iVar2 = *(int *)(param_3 + 0x1e8);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 0xd8);
  }
  if ((((int)ROUND(gpGlobals[7]) & 0x10U) != 0) &&
     (iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,uVar4), iVar2 != 0)) {
    return;
  }
  param_1[0x72] = (int)((float)param_1[0x72] + 1.0);
  ClientPrint__FP9entvars_tiPCcN42(*param_1,4,"#Pyro_onfire",0,0,0,0);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),2,"ambience/flameburst1.wav",0x3f800000,0x3f4ccccd,0,
             100);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x72]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x72] == 1.0) << 0xe) >> 8)) == 0x40) {
    piVar3 = (int *)FlameSpawn__8CTFFlameP11CBaseEntityT1(uVar4,param_1);
    *(byte *)(*piVar3 + 0xf8) = *(byte *)(*piVar3 + 0xf8) & 0x7f;
  }
  return;
}


