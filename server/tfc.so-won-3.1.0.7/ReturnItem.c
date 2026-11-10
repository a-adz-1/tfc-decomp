// ReturnItem__11CBaseEntity  @ 0010cf40
void ReturnItem__11CBaseEntity(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 != 0) goto LAB_0010cf7a;
    piVar2 = (int *)0x0;
  }
  else {
LAB_0010cf7a:
    piVar2 = *(int **)(iVar1 + 0x7c);
  }
  piVar2[3] = 0;
  piVar2[4] = 0;
  piVar2[0x86] = 2;
  if ((*(byte *)((int)piVar2 + 0x229) & 0x20) != 0) {
    iVar1 = strcmp((char *)(*(int *)*piVar2 + *(int *)(gpGlobals + 0x98)),"item_tfgoal");
    if (iVar1 == 0) {
      *(undefined4 *)(*piVar2 + 0x10c) = 2;
      goto LAB_0010cfe8;
    }
  }
  *(undefined4 *)(*piVar2 + 0x10c) = 1;
LAB_0010cfe8:
  *(undefined4 *)(*piVar2 + 0x108) = 0;
  *(undefined4 *)(*piVar2 + 0x194) = 0;
  piVar2[5] = -0x10000;
  piVar2[6] = (int)item_tfgoal_touch__11CBaseEntityP11CBaseEntity;
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x50) = g_vecZero;
  *(undefined4 *)(iVar1 + 0x54) = DAT_001c0fe4;
  *(undefined4 *)(iVar1 + 0x58) = DAT_001c0fe8;
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0x1c);
  *(byte *)(*piVar2 + 0x118) = *(byte *)(*piVar2 + 0x118) & 0x7f;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar2,*piVar2 + 8);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*piVar2 + 0x208),1,"items/itembk2.wav",0x3f800000,0x3f4ccccd,0,0x96);
  tfgoalitem_checkgoalreturn__FP11CBaseEntity(piVar2);
  if ((param_1[0x23] != 2) &&
     ((((*(int *)(*piVar2 + 500) != 0 || (piVar2[0xdc] != 0)) || (piVar2[0xec] != 0)) ||
      (piVar2[0xed] != 0)))) {
    for (iVar1 = 1; iVar1 <= *(int *)(gpGlobals + 0x90); iVar1 = iVar1 + 1) {
      piVar3 = (int *)UTIL_PlayerByIndex__Fi(iVar1);
      if (piVar3 != (int *)0x0) {
        if (piVar2[0x89] != 0) {
          iVar4 = GetTeamCheckTeam__FPCc(piVar2[0x89] + *(int *)(gpGlobals + 0x98));
          piVar2[0x87] = iVar4;
        }
        if (piVar3[0x48] == piVar2[0x87]) {
          if (*(int *)(*piVar2 + 500) == 0) {
            if (piVar2[0xec] != 0) {
              iVar4 = piVar2[0xec];
LAB_0010d1c3:
              ClientPrint__FP9entvars_siPCcN42(*piVar3,4,iVar4 + *(int *)(gpGlobals + 0x98),0,0,0,0)
              ;
            }
          }
          else {
            uVar5 = *(undefined4 *)(*piVar3 + 0x208);
            iVar4 = *(int *)(*piVar2 + 500);
LAB_0010d190:
            UTIL_ShowMessage__FPCcP7edict_s(iVar4 + *(int *)(gpGlobals + 0x98),uVar5);
          }
        }
        else {
          if (piVar2[0xdc] != 0) {
            uVar5 = *(undefined4 *)(*piVar3 + 0x208);
            iVar4 = piVar2[0xdc];
            goto LAB_0010d190;
          }
          if (piVar2[0xed] != 0) {
            iVar4 = piVar2[0xed];
            goto LAB_0010d1c3;
          }
        }
      }
    }
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


