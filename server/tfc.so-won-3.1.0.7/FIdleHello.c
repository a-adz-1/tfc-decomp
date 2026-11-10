// FIdleHello__12CTalkMonster  @ 000f5d34
undefined4 FIdleHello__12CTalkMonster(int *param_1)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar1 = FOkToSpeak__12CTalkMonster(param_1);
  if ((((iVar1 != 0) && ((*(byte *)(param_1 + 0x1a3) & 8) == 0)) &&
      (iVar1 = FindNearestFriend__12CTalkMonsteri(param_1,1), iVar1 != 0)) &&
     ((iVar2 = (**(code **)(param_1[0x111] + 0x138))(param_1,iVar1), iVar2 != 0 &&
      (iVar2 = (**(code **)(param_1[0x111] + 0xe0))(param_1,iVar1), iVar2 != 0)))) {
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x1bd,iVar1);
    if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
      iVar1 = param_1[0x111];
      lVar3 = (longdouble)(*DAT_001c118c)(0x40400000,0x40600000,0x3f800000,0x40000000);
      iVar2 = param_1[0x1ae];
    }
    else {
      iVar1 = param_1[0x111];
      lVar3 = (longdouble)(*DAT_001c118c)(0x40400000,0x40600000,0x3f800000,0x40000000);
      iVar2 = param_1[0x1af];
    }
    (**(code **)(iVar1 + 0x188))(param_1,iVar2,(float)lVar3);
    *(byte *)(param_1 + 0x1a3) = *(byte *)(param_1 + 0x1a3) | 8;
    return 1;
  }
  return 0;
}


