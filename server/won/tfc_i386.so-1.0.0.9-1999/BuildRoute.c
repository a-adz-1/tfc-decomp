// BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity  @ 000c31e0
undefined4
BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity
          (int *param_1,int *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  RouteNew__12CBaseMonster(param_1);
  iVar1 = RouteClassify__12CBaseMonsteri(param_1,param_3);
  param_1[0x15f] = iVar1;
  param_1[0x13f] = *param_2;
  param_1[0x140] = param_2[1];
  param_1[0x141] = param_2[2];
  param_1[0x142] = param_3 | 0x80;
  iVar1 = (**(code **)(param_1[0xf2] + 0x138))(param_1,*param_1 + 8,param_2,param_4,&local_20);
  if (iVar1 != 2) {
    if ((iVar1 == 1) ||
       (iVar1 = (**(code **)(param_1[0xf2] + 0x19c))
                          (param_1,*param_1 + 8,param_2,local_20,param_4,&local_10), iVar1 == 0)) {
      local_1c = *param_2;
      local_18 = param_2[1];
      local_14 = param_2[2];
      iVar1 = FGetNodeRoute__12CBaseMonsterG6Vector(param_1,&local_1c);
      if (iVar1 == 0) {
        return 0;
      }
      param_1[0x162] = *param_2;
      param_1[0x163] = param_2[1];
      param_1[0x164] = param_2[2];
    }
    else {
      param_1[0x13f] = local_10;
      param_1[0x140] = local_c;
      param_1[0x141] = local_8;
      param_1[0x142] = param_3 | 8;
      param_1[0x143] = *param_2;
      param_1[0x144] = param_2[1];
      param_1[0x145] = param_2[2];
      param_1[0x146] = param_3 | 0x80;
    }
    RouteSimplify__12CBaseMonsterP11CBaseEntity(param_1,param_4);
  }
  return 1;
}


