// CheckSuitUpdate__11CBasePlayer  @ 000d87b4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CheckSuitUpdate__11CBasePlayer(int *param_1)

{
  int iVar1;
  int iVar2;
  int iStack_24;
  undefined2 auStack_18 [10];
  
  iVar2 = param_1[0x1d1];
  if (*(int *)(*param_1 + 0x168) < 0) {
    UpdateGeigerCounter__11CBasePlayer(param_1);
    iVar1 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
    if (((iVar1 == 0) && ((float)param_1[0x1cc] <= *gpGlobals)) && (0.0 < (float)param_1[0x1cc])) {
      iStack_24 = 0;
      do {
        iVar1 = param_1[iVar2 + 0x1cd];
        if (iVar1 != 0) {
          param_1[iVar2 + 0x1cd] = 0;
          if (iVar1 < 1) {
            EMIT_GROUPID_SUIT__FP7edict_si(*(undefined4 *)(*param_1 + 0x208),-iVar1);
          }
          else {
            auStack_18[0] = 0x21;
            strcat((char *)auStack_18,gszallsentencenames + iVar1 * 0x10);
            EMIT_SOUND_SUIT__FP7edict_sPCc(*(undefined4 *)(*param_1 + 0x208),auStack_18);
          }
          param_1[0x1cc] = (int)((float)_FUN_00150770 + *gpGlobals);
          return;
        }
        iVar2 = iVar2 + 1;
        if (iVar2 == 4) {
          iVar2 = 0;
        }
        iStack_24 = iStack_24 + 1;
      } while (iStack_24 < 4);
      param_1[0x1cc] = 0;
    }
  }
  return;
}


