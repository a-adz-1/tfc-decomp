// SaveTouch__12CTriggerSaveP11CBaseEntity  @ 00112140
void SaveTouch__12CTriggerSaveP11CBaseEntity(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = UTIL_IsMasterTriggered__Fi(*(undefined4 *)(param_1 + 0x468));
  if ((iVar1 != 0) && ((*(byte *)(*param_2 + 0x184) & 8) != 0)) {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    UTIL_Remove__FP11CBaseEntity(param_1);
    (*DAT_0017555c)("autosave\n");
  }
  return;
}


