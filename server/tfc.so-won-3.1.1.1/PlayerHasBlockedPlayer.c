// PlayerHasBlockedPlayer__13CVoiceGameMgrP11CBasePlayerT1  @ 0013b17c
undefined4
PlayerHasBlockedPlayer__13CVoiceGameMgrP11CBasePlayerT1(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_2 != (int *)0x0) && (param_3 != (int *)0x0)) {
    iVar1 = (*DAT_0019f7bc)(*(undefined4 *)(*param_2 + 0x208));
    iVar1 = iVar1 + -1;
    iVar2 = (*DAT_0019f7bc)(*(undefined4 *)(*param_3 + 0x208));
    iVar2 = iVar2 + -1;
    if ((-1 < iVar1) &&
       (((iVar1 < *(int *)(param_1 + 0xc) && (-1 < iVar2)) && (iVar2 < *(int *)(param_1 + 0xc))))) {
      uVar3 = 1 << ((byte)iVar2 & 0x1f);
      return CONCAT31((int3)(uVar3 >> 8),((&g_BanMasks)[iVar1 + (iVar2 >> 5)] & uVar3) != 0);
    }
  }
  return 0;
}


