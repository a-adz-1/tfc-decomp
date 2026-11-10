// ScriptEntityCancel__FP7edict_s  @ 000eb0f8
void ScriptEntityCancel__FP7edict_s(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar2 = (int *)(param_1 + 0x80);
  piVar4 = piVar2;
  if (param_1 == 0) {
    piVar4 = (int *)0x0;
  }
  iVar1 = strcmp((char *)(*piVar4 + *(int *)(gpGlobals + 0x98)),"scripted_sequence");
  if (iVar1 == 0) {
    if (param_1 == 0) {
      piVar2 = (int *)0x0;
    }
    iVar1 = GetClassPtr__H1Z12CCineMonster_PX01_PX01(piVar2);
    iVar1 = __opP11CBaseEntity__7EHANDLE(iVar1 + 0x504);
    iVar3 = 0;
    if (iVar1 != 0) {
      iVar3 = (**(code **)(*(int *)(iVar1 + 0x454) + 0x50))(iVar1);
    }
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x574) == 6)) {
      *(undefined4 *)(iVar3 + 0x694) = 2;
      CineCleanup__12CBaseMonster(iVar3);
    }
  }
  return;
}


