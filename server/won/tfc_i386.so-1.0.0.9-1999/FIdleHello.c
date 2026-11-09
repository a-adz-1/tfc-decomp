// FIdleHello__12CTalkMonster  @ 000f2460
undefined4 FIdleHello__12CTalkMonster(int *param_1)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar1 = FOkToSpeak__12CTalkMonster(param_1);
  if ((((iVar1 != 0) && ((*(byte *)(param_1 + 0x184) & 8) == 0)) &&
      (iVar1 = FindNearestFriend__12CTalkMonsteri(param_1,1), iVar1 != 0)) &&
     ((iVar2 = (**(code **)(param_1[0xf2] + 0x130))(param_1,iVar1), iVar2 != 0 &&
      (iVar2 = (**(code **)(param_1[0xf2] + 0xd8))(param_1,iVar1), iVar2 != 0)))) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x19e,iVar1);
    if ((*(byte *)(*param_1 + 0x181) & 1) == 0) {
      iVar1 = param_1[0xf2];
      lVar3 = (longdouble)(*DAT_0017562c)(0x40400000,0x40600000,0x3f800000,0x40000000);
      iVar2 = param_1[399];
    }
    else {
      iVar1 = param_1[0xf2];
      lVar3 = (longdouble)(*DAT_0017562c)(0x40400000,0x40600000,0x3f800000,0x40000000);
      iVar2 = param_1[400];
    }
    (**(code **)(iVar1 + 0x180))(param_1,iVar2,(float)lVar3);
    *(byte *)(param_1 + 0x184) = *(byte *)(param_1 + 0x184) | 8;
    return 1;
  }
  return 0;
}


