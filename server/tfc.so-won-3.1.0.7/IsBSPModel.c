// IsBSPModel__11CBaseEntity  @ 0010f8fc
undefined4 IsBSPModel__11CBaseEntity(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(*param_1 + 0x10c) == 4) || (*(int *)(*param_1 + 0x108) == 0xd)) {
    uVar1 = 1;
  }
  return uVar1;
}


