// FOkToSpeak__12CTalkMonster  @ 000f79dc
undefined4 FOkToSpeak__12CTalkMonster(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((((param_1[0x15d] != 5) && (param_1[0x15e] != 5)) && (*(int *)(*param_1 + 0x170) == 0)) &&
      ((_12CTalkMonster_g_talkWaitTime < *gpGlobals && ((*(byte *)(*param_1 + 0x1a0) & 2) == 0))))
     && (iVar2 = (**(code **)(param_1[0x115] + 0x8c))(param_1), iVar2 != 0)) {
    iVar2 = (*DAT_0019f6e4)(*(undefined4 *)(*param_1 + 0x208));
    bVar1 = false;
    if ((iVar2 == 0) || (iVar2 = (*DAT_0019f7b8)(iVar2), iVar2 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13f);
      if (iVar2 != 0) {
        iVar2 = param_1[0x115];
        uVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13f);
        iVar2 = (**(code **)(iVar2 + 0xe0))(param_1,uVar3);
        if (iVar2 != 0) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}


