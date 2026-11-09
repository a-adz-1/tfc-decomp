// AlertFriends__12CTalkMonster  @ 000f1c90
void AlertFriends__12CTalkMonster(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  do {
    while( true ) {
      iVar3 = EnumFriends__12CTalkMonsterP11CBaseEntityii(param_1,iVar3,iVar4,1);
      if (iVar3 == 0) break;
      iVar1 = (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x4c))(iVar3);
      iVar2 = (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x88))(iVar1);
      if (iVar2 != 0) {
        *(byte *)(iVar1 + 0x5b0) = *(byte *)(iVar1 + 0x5b0) | 1;
      }
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  return;
}


