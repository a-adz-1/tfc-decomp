// ScriptEntityCancel__FP7edict_s  @ 000e7cb0
void ScriptEntityCancel__FP7edict_s(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(param_1 + 0xdc);
  }
  iVar2 = strcmp((char *)(*piVar1 + *(int *)(gpGlobals + 0x98)),"scripted_sequence");
  if (iVar2 == 0) {
    if (param_1 == 0) {
      param_1 = 0;
    }
    else {
      param_1 = param_1 + 0xdc;
    }
    iVar2 = GetClassPtr__H1Z12CCineMonster_PX01_PX01(param_1);
    iVar2 = __opP11CBaseEntity__7EHANDLE(iVar2 + 0x478);
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x4c))(iVar2);
    }
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x4e8) == 6)) {
      *(undefined4 *)(iVar3 + 0x608) = 2;
      CineCleanup__12CBaseMonster(iVar3);
    }
  }
  return;
}


