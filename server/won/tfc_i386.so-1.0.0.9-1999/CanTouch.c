// CanTouch__9CItemSodaP11CBaseEntity  @ 000b0050
void CanTouch__9CItemSodaP11CBaseEntity(int *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  
  if ((*(byte *)(*param_2 + 0x184) & 8) != 0) {
    (**(code **)(param_2[0xf2] + 0x38))(param_2,0x3f800000,0);
    bVar1 = false;
    if ((*(int *)(*param_1 + 0x178) == 0) ||
       (iVar2 = (*DAT_001755d8)(*(int *)(*param_1 + 0x178)), iVar2 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      *(undefined4 *)(*(int *)(*param_1 + 0x178) + 0x220) = 0;
    }
    *(undefined4 *)(*param_1 + 0xec) = 0;
    *(undefined4 *)(*param_1 + 0xe8) = 0;
    *(undefined4 *)(*param_1 + 0xf8) = 0x80;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    *(undefined4 *)(*param_1 + 0xe4) = *gpGlobals;
    return;
  }
  return;
}


