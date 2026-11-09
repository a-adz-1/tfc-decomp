// AcceptableSpeaker__17CScriptedSentenceP12CBaseMonster  @ 000e8960
undefined4 AcceptableSpeaker__17CScriptedSentenceP12CBaseMonster(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  if ((*(byte *)(*param_1 + 0x180) & 2) != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_2 + 0x478);
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = (undefined4 *)__rf__7EHANDLE(param_2 + 0x478);
    iVar1 = strcmp((char *)(*(int *)*puVar2 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar1 != 0) {
      return 0;
    }
  }
  iVar1 = (**(code **)(*(int *)(param_2 + 0x3c8) + 0x17c))
                    (param_2,(*(byte *)(*param_1 + 0x180) & 4) != 0);
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}


