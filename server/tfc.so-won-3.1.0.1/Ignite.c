// Ignite__11CBasePlayerP9entvars_sT1  @ 000d6684
void Ignite__11CBasePlayerP9entvars_sT1(int *param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  (**(code **)(param_1[0xf5] + 0x34))(param_1,param_2,param_3,0x40c00000,8);
  if (*gpGlobals < cb_prematch_time) {
    return;
  }
  if (4.0 <= (float)param_1[0x72]) {
    *(byte *)((int)param_1 + 0x86) = *(byte *)((int)param_1 + 0x86) | 2;
    return;
  }
  if (((*(byte *)(param_1 + 0xe) & 0x10) != 0) &&
     (fVar1 = *(float *)(*param_1 + 0x1bc),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) {
    return;
  }
  iVar2 = *(int *)(param_3 + 0x208);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 0x7c);
  }
  if ((((int)ROUND(gpGlobals[7]) & 0x10U) != 0) &&
     (iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,uVar4), iVar2 != 0)) {
    return;
  }
  param_1[0x72] = (int)((float)param_1[0x72] + 1.0);
  ClientPrint__FP9entvars_siPCcN42(*param_1,4,"#Pyro_onfire",0,0,0,0);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),2,"ambience/flameburst1.wav",0x3f800000,0x3f4ccccd,0,
             100);
  if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0x72]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)param_1[0x72] == 1.0) << 0xe) >> 8)) == 0x40) {
    piVar3 = (int *)FlameSpawn__8CTFFlameP11CBaseEntityT1(uVar4,param_1);
    *(byte *)(*piVar3 + 0x118) = *(byte *)(*piVar3 + 0x118) & 0x7f;
  }
  return;
}


