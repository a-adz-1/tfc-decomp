// ForceRespawn__11CBasePlayer  @ 000e2d40
void ForceRespawn__11CBasePlayer(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  param_1[0x338] = 1;
  piVar1 = param_1 + 0x1f8;
  iVar2 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar2 != 0) {
    iVar2 = __rf__7EHANDLE(piVar1);
    (**(code **)(*(int *)(iVar2 + 0x3c8) + 0xb0))(iVar2,param_1,param_1,0,0);
    __as__7EHANDLEP11CBaseEntity(piVar1,0);
  }
  param_1[0x19c] = 0;
  param_1[0x1ec] = 0;
  param_1[0x192] = 0;
  param_1[0xe8] = 0;
  param_1[0xe9] = 0;
  param_1[0xeb] = 0;
  param_1[0xea] = 0;
  param_1[0x33e] = (int)(*gpGlobals + 1.0);
  param_1[0x72] = 0;
  param_1[0x25e] = 0;
  param_1[0x25d] = 0;
  if ((*(byte *)(param_1 + 0x22) & 1) != 0) {
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) & 0xfe;
    param_1[0x21] = 1;
  }
  if ((*(byte *)(param_1 + 0x22) & 8) == 0) {
    param_1[0x22] = 0;
  }
  else {
    param_1[0x22] = 8;
  }
  TeamFortress_ExecClassScript__11CBasePlayer(param_1);
  TeamFortress_SetSpeed__11CBasePlayer(param_1);
  (**(code **)(*g_pGameRules + 0x60))(g_pGameRules,param_1);
  uVar3 = LookupActivity__14CBaseAnimatingi(param_1,1);
  *(undefined4 *)(*param_1 + 0x108) = uVar3;
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x185) & 0x40) == 0) {
    local_1c = 0x41800000;
    local_18 = 0x41800000;
    local_14 = 0x42100000;
    puVar5 = &local_1c;
    local_10 = 0xc1800000;
    local_c = 0xc1800000;
    local_8 = 0xc2100000;
    puVar4 = &local_10;
    iVar2 = *param_1;
  }
  else {
    local_10 = 0x41800000;
    local_c = 0x41800000;
    local_8 = 0x41900000;
    puVar5 = &local_10;
    local_1c = 0xc1800000;
    local_18 = 0xc1800000;
    local_14 = 0xc1900000;
    puVar4 = &local_1c;
  }
  UTIL_SetSize__FP9entvars_tRC6VectorT1(iVar2,puVar4,puVar5);
  return;
}


