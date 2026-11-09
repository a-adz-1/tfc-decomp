// ShutUpFriends__12CTalkMonster  @ 000f1d00
void ShutUpFriends__12CTalkMonster(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    while( true ) {
      iVar2 = EnumFriends__12CTalkMonsterP11CBaseEntityii(param_1,iVar2,iVar3,1);
      if (iVar2 == 0) break;
      iVar1 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x4c))(iVar2);
      if (iVar1 != 0) {
        (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x188))(iVar1);
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return;
}


