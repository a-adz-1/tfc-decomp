// LimitFollowers__12CTalkMonsterP11CBaseEntityi  @ 000f1d60
void LimitFollowers__12CTalkMonsterP11CBaseEntityi(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  
  iVar3 = 0;
  local_8 = 0;
  iVar4 = 0;
  do {
    while( true ) {
      iVar3 = EnumFriends__12CTalkMonsterP11CBaseEntityii(param_1,iVar3,iVar4,0);
      if (iVar3 == 0) break;
      iVar1 = (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x4c))(iVar3);
      if (iVar1 != 0) {
        iVar2 = __opP11CBaseEntity__7EHANDLE(iVar1 + 0x478);
        if ((iVar2 == param_2) && (local_8 = local_8 + 1, param_3 < local_8)) {
          (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x210))(iVar1,1);
        }
      }
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  return;
}


