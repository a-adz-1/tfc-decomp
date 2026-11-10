// LimitFollowers__12CTalkMonsterP11CBaseEntityi  @ 000e8880
void LimitFollowers__12CTalkMonsterP11CBaseEntityi(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_4;
  
  iVar4 = 0;
  local_4 = 0;
  iVar3 = 0;
  do {
    while( true ) {
      iVar4 = EnumFriends__12CTalkMonsterP11CBaseEntityii(param_1,iVar4,iVar3,0);
      if (iVar4 == 0) break;
      iVar1 = (**(code **)(*(int *)(iVar4 + 0x3d4) + 0x4c))(iVar4);
      if (iVar1 != 0) {
        iVar2 = __opP11CBaseEntity__7EHANDLE(iVar1 + 0x484);
        if ((iVar2 == param_2) && (local_4 = local_4 + 1, param_3 < local_4)) {
          (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x210))(iVar1,1);
        }
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return;
}


