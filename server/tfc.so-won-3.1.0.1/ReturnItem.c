// ReturnItem__11CBaseEntity  @ 000fe58c
void ReturnItem__11CBaseEntity(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001a7f54)(0);
    if (iVar1 != 0) goto LAB_000fe5c4;
    piVar2 = (int *)0x0;
  }
  else {
LAB_000fe5c4:
    piVar2 = *(int **)(iVar1 + 0x7c);
  }
  piVar2[3] = 0;
  piVar2[4] = 0;
  piVar2[0x86] = 2;
  if ((*(byte *)((int)piVar2 + 0x221) & 0x20) != 0) {
    iVar1 = strcmp((char *)(*(int *)*piVar2 + *(int *)(gpGlobals + 0x98)),"item_tfgoal");
    if (iVar1 == 0) {
      *(undefined4 *)(*piVar2 + 0x10c) = 2;
      goto LAB_000fe634;
    }
  }
  *(undefined4 *)(*piVar2 + 0x10c) = 1;
LAB_000fe634:
  *(undefined4 *)(*piVar2 + 0x108) = 0;
  *(undefined4 *)(*piVar2 + 0x194) = 0;
  piVar2[5] = -0x10000;
  piVar2[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_001a7e04;
  *(undefined4 *)(iVar1 + 0x58) = DAT_001a7e08;
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0x1c);
  *(byte *)(*piVar2 + 0x118) = *(byte *)(*piVar2 + 0x118) & 0x7f;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar2,*piVar2 + 8);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*piVar2 + 0x208),1,"items/itembk2.wav",0x3f800000,0x3f4ccccd,0,0x96);
  tfgoalitem_checkgoalreturn__FP11CBaseEntity(piVar2);
  if ((param_1[0x23] != 2) && ((*(int *)(*piVar2 + 500) != 0 || (piVar2[0xca] != 0)))) {
    for (iVar1 = 1; iVar1 <= *(int *)(gpGlobals + 0x90); iVar1 = iVar1 + 1) {
      puVar3 = (undefined4 *)UTIL_PlayerByIndex__Fi(iVar1);
      if (puVar3 != (undefined4 *)0x0) {
        if (puVar3[0x48] == piVar2[0x87]) {
          iVar4 = *(int *)(*piVar2 + 500);
        }
        else {
          iVar4 = piVar2[0xca];
        }
        ClientPrint__FP9entvars_siPCcN42(*puVar3,4,iVar4 + *(int *)(gpGlobals + 0x98),0,0,0,0);
      }
    }
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


