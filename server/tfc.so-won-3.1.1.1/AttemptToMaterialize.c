// AttemptToMaterialize__15CBasePlayerItem  @ 00123d18
void AttemptToMaterialize__15CBasePlayerItem(int *param_1)

{
  int iVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)(**(code **)(*g_pGameRules + 0x8c))(g_pGameRules,param_1);
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0 == lVar2) << 0xe) >> 8)) == 0x40) {
    iVar1 = *param_1;
    if (*(char *)(iVar1 + 0x118) < '\0') {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar1 + 0x208),1,"items/suitchargeok1.wav",0x3f800000,0x3f4ccccd,0,
                 0x96);
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) & 0x7f;
      *(byte *)(*param_1 + 0x118) = *(byte *)(*param_1 + 0x118) | 2;
      iVar1 = *param_1;
    }
    *(undefined4 *)(iVar1 + 0x10c) = 1;
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
    param_1[5] = -0x10000;
    param_1[6] = (int)DefaultTouch__15CBasePlayerItemP11CBaseEntity;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  else {
    *(float *)(*param_1 + 0x104) = (float)((longdouble)*gpGlobals + lVar2);
  }
  return;
}


