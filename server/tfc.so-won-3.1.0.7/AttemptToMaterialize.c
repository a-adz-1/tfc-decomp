// AttemptToMaterialize__15CBasePlayerItem  @ 0011fbe4
void AttemptToMaterialize__15CBasePlayerItem(int *param_1)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(**(code **)(*g_pGameRules + 0x8c))(g_pGameRules,param_1);
  if ((byte)((byte)((ushort)((ushort)(NAN((longdouble)0.0) || NAN(lVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)0.0 == lVar1) << 0xe) >> 8)) == 0x40) {
    Materialize__15CBasePlayerItem(param_1);
  }
  else {
    *(float *)(*param_1 + 0x104) = (float)(lVar1 + (longdouble)*gpGlobals);
  }
  return;
}


