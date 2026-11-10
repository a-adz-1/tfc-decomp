// AcceptableSpeaker__17CScriptedSentenceP12CBaseMonster  @ 000e9aa4
undefined4 AcceptableSpeaker__17CScriptedSentenceP12CBaseMonster(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 2) != 0) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_2 + 0x4f4);
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = (undefined4 *)__rf__7EHANDLE(param_2 + 0x4f4);
    iVar1 = strcmp((char *)(*(int *)*puVar2 + *(int *)(gpGlobals + 0x98)),"player");
    if (iVar1 != 0) {
      return 0;
    }
  }
  iVar1 = (**(code **)(*(int *)(param_2 + 0x444) + 0x184))
                    (param_2,(*(byte *)(*param_1 + 0x1a0) & 4) != 0);
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}


