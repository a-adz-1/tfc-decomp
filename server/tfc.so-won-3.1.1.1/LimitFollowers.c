// LimitFollowers__12CTalkMonsterP11CBaseEntityi  @ 000f7604
void LimitFollowers__12CTalkMonsterP11CBaseEntityi(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_50;
  int local_4c;
  
  iVar4 = 0;
  local_50 = 0;
  local_4c = 0;
  do {
    iVar3 = (**(code **)(*(int *)(param_1 + 0x454) + 0x224))(param_1,local_4c);
    uVar1 = *(undefined4 *)(_12CTalkMonster_m_szFriends + iVar3 * 4);
    do {
      iVar4 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar4,uVar1);
      if (iVar4 == 0) {
        iVar4 = 0;
        break;
      }
    } while ((iVar4 == param_1) ||
            (iVar3 = (**(code **)(*(int *)(iVar4 + 0x454) + 0x8c))(iVar4), iVar3 == 0));
    if (iVar4 == 0) {
      local_4c = local_4c + 1;
      if (2 < local_4c) {
        return;
      }
    }
    else {
      iVar3 = (**(code **)(*(int *)(iVar4 + 0x454) + 0x50))(iVar4);
      if (((iVar3 != 0) && (iVar2 = __opP11CBaseEntity__7EHANDLE(iVar3 + 0x504), iVar2 == param_2))
         && (local_50 = local_50 + 1, param_3 < local_50)) {
        (**(code **)(*(int *)(iVar3 + 0x454) + 0x218))(iVar3,1);
      }
    }
  } while( true );
}


