// CanFollow__12CTalkMonster  @ 000e9f50
byte CanFollow__12CTalkMonster(int param_1)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  
  if (((*(int *)(param_1 + 0x4f4) != 6) ||
      (iVar1 = CanInterrupt__12CCineMonster(*(undefined4 *)(param_1 + 0x618)), iVar1 != 0)) &&
     (iVar1 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x88))(param_1), iVar1 != 0)) {
    bVar3 = false;
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x484);
    if (iVar1 != 0) {
      piVar2 = (int *)__rf__7EHANDLE(param_1 + 0x484);
      bVar3 = (*(byte *)(*piVar2 + 0x1a4) & 8) != 0;
    }
    return bVar3 ^ 1;
  }
  return 0;
}


