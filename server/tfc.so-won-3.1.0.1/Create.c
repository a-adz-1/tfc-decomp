// Create__11CBaseEntityPcRC6VectorT2P7edict_s  @ 00087368
int * Create__11CBaseEntityPcRC6VectorT2P7edict_s
                (int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = (*DAT_001a7e9c)(param_1 - *(int *)(gpGlobals + 0x98));
  bVar1 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    if ((iVar2 == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(iVar2 + 0x7c);
    }
    *(undefined4 *)(*piVar4 + 0x198) = param_4;
    iVar2 = *piVar4;
    *(undefined4 *)(iVar2 + 8) = *param_2;
    *(undefined4 *)(iVar2 + 0xc) = param_2[1];
    *(undefined4 *)(iVar2 + 0x10) = param_2[2];
    iVar2 = *piVar4;
    *(undefined4 *)(iVar2 + 0x50) = *param_3;
    *(undefined4 *)(iVar2 + 0x54) = param_3[1];
    *(undefined4 *)(iVar2 + 0x58) = param_3[2];
    DispatchSpawn__FP7edict_s(*(undefined4 *)(*piVar4 + 0x208));
    return piVar4;
  }
  (*DAT_001a7f34)(1,"NULL Ent in Create!\n");
  return (int *)0x0;
}


