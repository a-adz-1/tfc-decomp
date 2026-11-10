// IRelationship__12CBaseMonsterP11CBaseEntity  @ 000b2a78
void IRelationship__12CBaseMonsterP11CBaseEntity(void)

{
  FUN_000b2a81();
  return;
}


// IRelationship__12CTalkMonsterP11CBaseEntity  @ 000e9d3c
undefined4 IRelationship__12CTalkMonsterP11CBaseEntity(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (((*(byte *)(*param_2 + 0x1a4) & 8) == 0) || ((*(byte *)(param_1 + 0x5bc) & 1) == 0)) {
    uVar1 = IRelationship__12CBaseMonsterP11CBaseEntity(param_1,param_2);
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


