// FIdleHello__12CTalkMonster  @ 000e9058
undefined4 FIdleHello__12CTalkMonster(int *param_1)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar1 = FOkToSpeak__12CTalkMonster(param_1);
  if ((((iVar1 != 0) && ((*(byte *)(param_1 + 0x187) & 8) == 0)) &&
      (iVar1 = FindNearestFriend__12CTalkMonsteri(param_1,1), iVar1 != 0)) &&
     ((iVar2 = (**(code **)(param_1[0xf5] + 0x130))(param_1,iVar1), iVar2 != 0 &&
      (iVar2 = (**(code **)(param_1[0xf5] + 0xd8))(param_1,iVar1), iVar2 != 0)))) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x1a1,iVar1);
    if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
      iVar1 = param_1[0xf5];
      lVar3 = (longdouble)(*DAT_001a7fac)(0x40400000,0x40600000,0x3f800000,0x40000000);
      iVar2 = param_1[0x192];
    }
    else {
      iVar1 = param_1[0xf5];
      lVar3 = (longdouble)(*DAT_001a7fac)(0x40400000,0x40600000,0x3f800000,0x40000000);
      iVar2 = param_1[0x193];
    }
    (**(code **)(iVar1 + 0x180))(param_1,iVar2,(float)lVar3);
    *(byte *)(param_1 + 0x187) = *(byte *)(param_1 + 0x187) | 8;
    return 1;
  }
  return 0;
}


