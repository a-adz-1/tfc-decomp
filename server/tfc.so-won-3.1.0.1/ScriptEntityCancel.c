// ScriptEntityCancel__FP7edict_s  @ 000dcc68
void ScriptEntityCancel__FP7edict_s(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x80);
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  iVar1 = strcmp((char *)(*piVar3 + *(int *)(gpGlobals + 0x98)),"scripted_sequence");
  if (iVar1 == 0) {
    iVar1 = param_1 + 0x80;
    if (param_1 == 0) {
      iVar1 = 0;
    }
    iVar1 = GetClassPtr__H1Z12CCineMonster_PX01_PX01(iVar1);
    iVar1 = __opP11CBaseEntity__7EHANDLE(iVar1 + 0x484);
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x4c))(iVar1);
    }
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x4f4) == 6)) {
      *(undefined4 *)(iVar2 + 0x614) = 2;
      CineCleanup__12CBaseMonster(iVar2);
    }
  }
  return;
}


