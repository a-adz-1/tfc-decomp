// ForceRespawn__11CBasePlayer  @ 000d6fcc
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ForceRespawn__11CBasePlayer(int *param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  param_1[0x342] = 1;
  (*DAT_001a7ef8)(2,0x17,0,0);
  (*DAT_001a7f00)(0x7d);
  uVar2 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(uVar2);
  (*DAT_001a7efc)();
  if (param_1[0x1c] != 0) {
    param_1[0x1c] = 0;
    iVar3 = *param_1;
    *(undefined4 *)(iVar3 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar3 + 0x24) = DAT_001a7e04;
    *(undefined4 *)(iVar3 + 0x28) = DAT_001a7e08;
    iVar3 = *param_1;
    uStack_4 = 0x41e00000;
    uStack_c = 0;
    uStack_8 = 0;
    *(undefined4 *)(iVar3 + 0x174) = 0;
    *(undefined4 *)(iVar3 + 0x178) = 0;
    *(undefined4 *)(iVar3 + 0x17c) = 0x41e00000;
    *(undefined4 *)(*param_1 + 0x108) = 3;
    *(undefined4 *)(*param_1 + 0x170) = 0;
    *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xfd;
    if (param_1[0x211] != 0) {
      (**(code **)(*(int *)(param_1[0x211] + 0x3d4) + 0x118))(param_1[0x211]);
    }
    *(undefined4 *)(*param_1 + 0x138) = 0xbf800000;
    param_1[0x25e] = 0;
    SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,6);
  }
  piVar1 = param_1 + 0x1fd;
  iVar3 = __opP11CBaseEntity__7EHANDLE(piVar1);
  if (iVar3 != 0) {
    iVar3 = __rf__7EHANDLE(piVar1);
    (**(code **)(*(int *)(iVar3 + 0x3d4) + 0xb0))(iVar3,param_1,param_1,0,0);
    __as__7EHANDLEP11CBaseEntity(piVar1,0);
  }
  param_1[0x1a1] = 0;
  param_1[0x1f1] = 0;
  param_1[0x196] = 0;
  param_1[0xeb] = 0;
  param_1[0xec] = 0;
  param_1[0xee] = 0;
  param_1[0xed] = 0;
  param_1[0x34a] = (int)(*gpGlobals + 1.0);
  param_1[0x72] = 0;
  param_1[0x265] = 0;
  param_1[0x264] = 0;
  if ((*(byte *)(param_1 + 0x21) & 1) != 0) {
    *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) & 0xfe;
    param_1[0x20] = 1;
  }
  if ((*(byte *)(param_1 + 0x21) & 8) == 0) {
    param_1[0x21] = 0;
  }
  else {
    param_1[0x21] = 8;
  }
  TeamFortress_ExecClassScript__11CBasePlayer(param_1);
  TeamFortress_SetSpeed__11CBasePlayer(param_1);
  (**(code **)(*g_pGameRules + 0x60))(g_pGameRules,param_1);
  uVar4 = LookupActivity__14CBaseAnimatingi(param_1,1);
  *(undefined4 *)(*param_1 + 0x128) = uVar4;
  iVar3 = *param_1;
  if ((*(byte *)(iVar3 + 0x1a5) & 0x40) == 0) {
    uStack_14 = 0x41800000;
    uStack_10 = 0x42100000;
    puVar6 = &uStack_18;
    uStack_8 = 0xc1800000;
    uStack_4 = 0xc2100000;
    puVar5 = &uStack_c;
    iVar3 = *param_1;
  }
  else {
    uStack_8 = 0x41800000;
    uStack_4 = _FUN_0013b614;
    puVar6 = &uStack_c;
    uStack_14 = 0xc1800000;
    uStack_10 = 0xc1900000;
    puVar5 = &uStack_18;
  }
  uStack_18 = uStack_14;
  uStack_c = uStack_8;
  UTIL_SetSize__FP9entvars_sRC6VectorT1(iVar3,puVar5,puVar6);
  return;
}


