// FIdleStare__12CTalkMonster  @ 000f8d3c
bool FIdleStare__12CTalkMonster(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  
  iVar2 = FOkToSpeak__12CTalkMonster(param_1);
  if (iVar2 != 0) {
    iVar1 = *(int *)(param_1 + 0x454);
    lVar4 = (longdouble)(*DAT_0019f80c)(0x40a00000,0x40f00000,0x3f800000,0x40000000);
    (**(code **)(iVar1 + 0x188))(param_1,*(undefined4 *)(param_1 + 0x6b4),(float)lVar4);
    uVar3 = FindNearestFriend__12CTalkMonsteri(param_1,1);
    __as__7EHANDLEP11CBaseEntity(param_1 + 0x704,uVar3);
  }
  return iVar2 != 0;
}


