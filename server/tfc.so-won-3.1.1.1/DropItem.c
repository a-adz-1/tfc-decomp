// DropItem__12CBaseMonsterPcRC6VectorT2  @ 000c15d0
int * DropItem__12CBaseMonsterPcRC6VectorT2
                (int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  longdouble lVar5;
  
  if (param_2 == 0) {
    pcVar4 = "DropItem() - No item name!\n";
  }
  else {
    piVar3 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                              (param_2,param_3,param_4,*(undefined4 *)(*param_1 + 0x208));
    if (piVar3 != (int *)0x0) {
      iVar1 = *param_1;
      iVar2 = *piVar3;
      *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar1 + 0x20);
      *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar1 + 0x24);
      *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar1 + 0x28);
      iVar1 = *piVar3;
      lVar5 = (longdouble)(*DAT_0019f80c)(0,0x42c80000);
      *(undefined4 *)(iVar1 + 0x5c) = 0;
      *(float *)(iVar1 + 0x60) = (float)lVar5;
      *(undefined4 *)(iVar1 + 100) = 0;
      return piVar3;
    }
    pcVar4 = "DropItem() - Didn\'t create!\n";
  }
  (*DAT_0019f794)(1,pcVar4);
  return (int *)0x0;
}


