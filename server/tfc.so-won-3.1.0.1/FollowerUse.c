// FollowerUse__12CTalkMonsterP11CBaseEntityT18USE_TYPEf  @ 000e9fd8
void FollowerUse__12CTalkMonsterP11CBaseEntityT18USE_TYPEf
               (int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  code *pcVar2;
  char *pcVar3;
  
  if ((((float)param_1[0x19c] <= *gpGlobals) && (param_3 != (int *)0x0)) &&
     ((*(byte *)(*param_3 + 0x1a4) & 8) != 0)) {
    if ((*(byte *)(*param_1 + 0x1a1) & 1) == 0) {
      iVar1 = CanFollow__12CTalkMonster(param_1);
      if (iVar1 == 0) {
        pcVar3 = (char *)0x1;
        pcVar2 = *(code **)(param_1[0xf5] + 0x210);
      }
      else {
        LimitFollowers__12CTalkMonsterP11CBaseEntityi(param_1,param_3,1);
        if ((*(byte *)(param_1 + 0x16f) & 1) == 0) {
          StartFollowing__12CTalkMonsterP11CBaseEntity(param_1,param_3);
          *(byte *)(param_1 + 0x187) = *(byte *)(param_1 + 0x187) | 8;
          return;
        }
        pcVar3 = "I\'m not following you, you evil person!\n";
        param_1 = (int *)0x1;
        pcVar2 = DAT_001a7f34;
      }
      (*pcVar2)(param_1,pcVar3);
    }
    else {
      (**(code **)(param_1[0xf5] + 0x214))(param_1);
    }
  }
  return;
}


