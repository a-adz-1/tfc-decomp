// CheckSuitUpdate__11CBasePlayer  @ 000db370
void CheckSuitUpdate__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_18 [20];
  
  iVar4 = param_1[0x1a6];
  if (*(int *)(*param_1 + 0x148) < 0) {
    UpdateGeigerCounter__11CBasePlayer(param_1);
    iVar3 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
    if (((iVar3 == 0) && ((float)param_1[0x1a1] <= *gpGlobals)) &&
       (fVar1 = (float)param_1[0x1a1],
       (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) {
      iVar3 = 0;
      do {
        iVar2 = param_1[iVar4 + 0x1a2];
        if (iVar2 != 0) {
          param_1[iVar4 + 0x1a2] = 0;
          if (iVar2 < 1) {
            EMIT_GROUPID_SUIT__FP7edict_si(*(undefined4 *)(*param_1 + 0x1e8),-iVar2);
          }
          else {
            local_18[0] = '!';
            local_18[1] = '\0';
            strcat(local_18,gszallsentencenames + iVar2 * 0x10);
            EMIT_SOUND_SUIT__FP7edict_sPCc(*(undefined4 *)(*param_1 + 0x1e8),local_18);
          }
          param_1[0x1a1] = (int)(*gpGlobals + 3.5);
          return;
        }
        iVar4 = iVar4 + 1;
        if (iVar4 == 4) {
          iVar4 = 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      param_1[0x1a1] = 0;
    }
  }
  return;
}


