// ItemTouch__5CItemP11CBaseEntity  @ 000b5d64
void ItemTouch__5CItemP11CBaseEntity(int param_1,int *param_2)

{
  int iVar1;
  
  if (((*(byte *)(*param_2 + 0x1a4) & 8) != 0) &&
     (iVar1 = (**(code **)(*g_pGameRules + 0x94))(g_pGameRules,param_2,param_1), iVar1 != 0)) {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x454) + 0x108))(param_1,param_2);
    if (iVar1 == 0) {
      if (gEvilImpulse101 == 0) {
        return;
      }
    }
    else {
      SUB_UseTargets__11CBaseEntityP11CBaseEntity8USE_TYPEf(param_1,param_2,3,0);
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      (**(code **)(*g_pGameRules + 0x98))(g_pGameRules,param_2,param_1);
      iVar1 = (**(code **)(*g_pGameRules + 0x9c))(g_pGameRules,param_1);
      if (iVar1 == 5) {
        (**(code **)(*(int *)(param_1 + 0x454) + 0xc0))(param_1);
        return;
      }
    }
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


