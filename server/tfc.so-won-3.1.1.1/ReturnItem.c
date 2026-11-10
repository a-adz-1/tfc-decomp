// ReturnItem__11CBaseEntity  @ 0010fc48
void ReturnItem__11CBaseEntity(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int local_8;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 != 0) goto LAB_0010fc83;
    piVar3 = (int *)0x0;
  }
  else {
LAB_0010fc83:
    piVar3 = *(int **)(iVar1 + 0x7c);
  }
  piVar3[3] = 0;
  piVar3[4] = 0;
  piVar3[0x86] = 2;
  if ((*(byte *)((int)piVar3 + 0x229) & 0x20) != 0) {
    iVar1 = strcmp((char *)(*(int *)*piVar3 + *(int *)(gpGlobals + 0x98)),"item_tfgoal");
    if (iVar1 == 0) {
      *(undefined4 *)(*piVar3 + 0x10c) = 2;
      goto LAB_0010fcec;
    }
  }
  *(undefined4 *)(*piVar3 + 0x10c) = 1;
LAB_0010fcec:
  *(undefined4 *)(*piVar3 + 0x108) = 0;
  *(undefined4 *)(*piVar3 + 0x194) = 0;
  piVar3[5] = -0x10000;
  piVar3[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
  iVar1 = *piVar3;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_0019f664;
  *(undefined4 *)(iVar1 + 0x58) = DAT_0019f668;
  iVar1 = *piVar3;
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0x1c);
  *(byte *)(*piVar3 + 0x118) = *(byte *)(*piVar3 + 0x118) & 0x7f;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar3,*piVar3 + 8);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*piVar3 + 0x208),1,"items/itembk2.wav",0x3f800000,0x3f4ccccd,0,0x96);
  tfgoalitem_checkgoalreturn__FP11CBaseEntity(piVar3);
  if ((param_1[0x23] != 2) &&
     ((((*(int *)(*piVar3 + 500) != 0 || (piVar3[0xe0] != 0)) || (piVar3[0xf0] != 0)) ||
      (piVar3[0xf1] != 0)))) {
    for (local_8 = 1; local_8 <= *(int *)(gpGlobals + 0x90); local_8 = local_8 + 1) {
      piVar2 = (int *)UTIL_PlayerByIndex__Fi(local_8);
      if (piVar2 != (int *)0x0) {
        if (piVar3[0x89] != 0) {
          iVar1 = GetTeamCheckTeam__FPCc(piVar3[0x89] + *(int *)(gpGlobals + 0x98));
          piVar3[0x87] = iVar1;
        }
        if (piVar2[0x48] == piVar3[0x87]) {
          if (*(int *)(*piVar3 + 500) == 0) {
            iVar1 = piVar3[0xf0];
LAB_0010fe8e:
            if (iVar1 != 0) {
              ClientPrint__FP9entvars_siPCcN42(*piVar2,4,iVar1 + *(int *)(gpGlobals + 0x98),0,0,0,0)
              ;
            }
            goto LAB_0010feb6;
          }
          uVar4 = *(undefined4 *)(*piVar2 + 0x208);
          iVar1 = *(int *)(*piVar3 + 500) + *(int *)(gpGlobals + 0x98);
        }
        else {
          if (piVar3[0xe0] == 0) {
            iVar1 = piVar3[0xf1];
            goto LAB_0010fe8e;
          }
          uVar4 = *(undefined4 *)(*piVar2 + 0x208);
          iVar1 = piVar3[0xe0] + *(int *)(gpGlobals + 0x98);
        }
        UTIL_ShowMessage__FPCcP7edict_s(iVar1,uVar4);
      }
LAB_0010feb6:
    }
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


