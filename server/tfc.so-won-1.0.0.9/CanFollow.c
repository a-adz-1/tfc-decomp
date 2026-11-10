// CanFollow__12CTalkMonster  @ 000f31a0
byte CanFollow__12CTalkMonster(int param_1)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  
  if (((*(int *)(param_1 + 0x4e8) != 6) ||
      (iVar1 = CanInterrupt__12CCineMonster(*(undefined4 *)(param_1 + 0x60c)), iVar1 != 0)) &&
     (iVar1 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x88))(param_1), iVar1 != 0)) {
    bVar3 = false;
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x478);
    if (iVar1 != 0) {
      piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x478);
      bVar3 = (*(byte *)(*piVar2 + 0x184) & 8) != 0;
    }
    return bVar3 ^ 1;
  }
  return 0;
}


