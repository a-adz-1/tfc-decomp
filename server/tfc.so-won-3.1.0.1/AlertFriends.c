// AlertFriends__12CTalkMonster  @ 000e87b4
void AlertFriends__12CTalkMonster(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  do {
    while( true ) {
      iVar4 = EnumFriends__12CTalkMonsterP11CBaseEntityii(param_1,iVar4,iVar3,1);
      if (iVar4 == 0) break;
      iVar1 = (**(code **)(*(int *)(iVar4 + 0x3d4) + 0x4c))(iVar4);
      iVar2 = (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x88))(iVar1);
      if (iVar2 != 0) {
        *(byte *)(iVar1 + 0x5bc) = *(byte *)(iVar1 + 0x5bc) | 1;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return;
}


