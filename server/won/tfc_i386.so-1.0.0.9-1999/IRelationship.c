// IRelationship__12CBaseMonsterP11CBaseEntity  @ 000c4710
undefined4 IRelationship__12CBaseMonsterP11CBaseEntity(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*(int *)(param_2 + 0x3c8) + 0x28))(param_2);
  iVar2 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x28))(param_1);
  return *(undefined4 *)(iEnemy_726 + iVar1 * 4 + iVar2 * 0x38);
}


// IRelationship__12CTalkMonsterP11CBaseEntity  @ 000f2fa0
undefined4 IRelationship__12CTalkMonsterP11CBaseEntity(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (((*(byte *)(*param_2 + 0x184) & 8) == 0) || ((*(byte *)(param_1 + 0x5b0) & 1) == 0)) {
    uVar1 = IRelationship__12CBaseMonsterP11CBaseEntity(param_1,param_2);
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


