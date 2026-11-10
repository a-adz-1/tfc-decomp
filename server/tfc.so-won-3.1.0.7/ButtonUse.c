// ButtonUse__11CBaseButtonP11CBaseEntityT18USE_TYPEf  @ 0008be08
void ButtonUse__11CBaseButtonP11CBaseEntityT18USE_TYPEf
               (int *param_1,int param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  int iVar1;
  
  if (((1 < param_1[0x119] - 2U) &&
      (((*(byte *)(param_1 + 0x8a) & 8) == 0 ||
       ((byte)((byte)((ushort)((ushort)NAN(param_5) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_5 == 8.0) << 0xe) >> 8)) == 0x40)))) &&
     (((param_2 != 0 &&
       (iVar1 = (**(code **)(*(int *)(param_2 + 0x444) + 0x2c))(param_2), iVar1 != 2)) ||
      (iVar1 = ActivationSucceeded__FP11CBaseEntityP11CBasePlayerT0(param_1,param_2,0), iVar1 != 0))
     )) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x12e,param_2);
    if (param_1[0x119] == 0) {
      if ((param_1[0x13a] == 0) && (iVar1 = *param_1, (*(byte *)(iVar1 + 0x1a0) & 0x20) != 0)) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar1 + 0x208),2,
                   *(int *)(iVar1 + 0x1e8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,100)
        ;
        ButtonReturn__11CBaseButton(param_1);
      }
    }
    else {
      ButtonActivate__11CBaseButton(param_1);
    }
  }
  return;
}


