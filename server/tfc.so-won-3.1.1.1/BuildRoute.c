// BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity  @ 000bcae0
undefined4
BuildRoute__12CBaseMonsterRC6VectoriP11CBaseEntity
          (int *param_1,int *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = 0;
  param_1[0x165] = 0;
  param_1[0x183] = 0;
  if ((param_3 & 1) == 0) {
    if ((param_3 & 2) == 0) {
      if ((param_3 & 0x10) == 0) {
        if ((param_3 & 0x20) == 0) {
          if ((param_3 & 0x40) != 0) {
            iVar1 = 0x40;
          }
        }
        else {
          iVar1 = 0x20;
        }
      }
      else {
        iVar1 = 0x10;
      }
    }
    else {
      iVar1 = 2;
    }
  }
  else {
    iVar1 = 1;
  }
  param_1[0x182] = iVar1;
  param_1[0x162] = *param_2;
  param_1[0x163] = param_2[1];
  param_1[0x164] = param_2[2];
  local_24 = param_3 | 0x80;
  param_1[0x165] = local_24;
  iVar1 = (**(code **)(param_1[0x115] + 0x140))(param_1,*param_1 + 8,param_2,param_4,&local_20);
  if (iVar1 != 2) {
    if ((iVar1 == 1) ||
       (iVar1 = (**(code **)(param_1[0x115] + 0x1a4))
                          (param_1,*param_1 + 8,param_2,local_20,param_4,&local_10), iVar1 == 0)) {
      local_1c = *param_2;
      local_18 = param_2[1];
      local_14 = param_2[2];
      iVar1 = FGetNodeRoute__12CBaseMonsterG6Vector(param_1,&local_1c);
      if (iVar1 == 0) {
        return 0;
      }
      param_1[0x185] = *param_2;
      param_1[0x186] = param_2[1];
      param_1[0x187] = param_2[2];
    }
    else {
      param_1[0x162] = local_10;
      param_1[0x163] = local_c;
      param_1[0x164] = local_8;
      param_1[0x165] = param_3 | 8;
      param_1[0x166] = *param_2;
      param_1[0x167] = param_2[1];
      param_1[0x168] = param_2[2];
      param_1[0x169] = local_24;
    }
    RouteSimplify__12CBaseMonsterP11CBaseEntity(param_1,param_4);
    return 1;
  }
  return 1;
}


