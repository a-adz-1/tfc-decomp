// FOkToSpeak__12CTalkMonster  @ 000f22b0
undefined4 FOkToSpeak__12CTalkMonster(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (((((param_1[0x13a] != 5) && (param_1[0x13b] != 5)) && (*(int *)(*param_1 + 0x150) == 0)) &&
      ((fVar1 = *gpGlobals,
       0x3f < (byte)((fVar1 < _12CTalkMonster_g_talkWaitTime |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_12CTalkMonster_g_talkWaitTime)) <<
                                     10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == _12CTalkMonster_g_talkWaitTime) << 0xe) >> 8)
                     ) - 1) && ((*(byte *)(*param_1 + 0x180) & 2) == 0)))) &&
     ((param_1[0x13a] != 5 && (iVar3 = (**(code **)(param_1[0xf2] + 0x88))(param_1), iVar3 != 0))))
  {
    iVar3 = (*DAT_00175504)(*(undefined4 *)(*param_1 + 0x1e8));
    bVar2 = false;
    if ((iVar3 == 0) || (iVar3 = (*DAT_001755d8)(iVar3), iVar3 == 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11c);
      if (iVar3 != 0) {
        iVar3 = param_1[0xf2];
        uVar4 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11c);
        iVar3 = (**(code **)(iVar3 + 0xd8))(param_1,uVar4);
        if (iVar3 != 0) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}


