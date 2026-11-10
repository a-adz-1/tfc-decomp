// CanTouch__9CItemSodaP11CBaseEntity  @ 000a2dcc
void CanTouch__9CItemSodaP11CBaseEntity(int *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if ((*(byte *)(*param_2 + 0x1a4) & 8) == 0) {
    return;
  }
  (**(code **)(param_2[0x115] + 0x3c))(param_2,0x3f800000,0);
  iVar3 = *param_1;
  bVar1 = false;
  if (*(int *)(iVar3 + 0x198) != 0) {
    iVar2 = (*DAT_0019f7b8)(*(int *)(iVar3 + 0x198));
    iVar3 = *param_1;
    if (iVar2 != 0) goto LAB_000a2e31;
  }
  bVar1 = true;
LAB_000a2e31:
  if (!bVar1) {
    *(undefined4 *)(*(int *)(iVar3 + 0x198) + 0x1e4) = 0;
    iVar3 = *param_1;
  }
  *(undefined4 *)(iVar3 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


