// CheckSuitUpdate__11CBasePlayer  @ 000cd64c
void CheckSuitUpdate__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined2 local_14 [10];
  
  iVar4 = param_1[0x1ab];
  if (*(int *)(*param_1 + 0x168) < 0) {
    UpdateGeigerCounter__11CBasePlayer(param_1);
    iVar3 = (**(code **)(*g_pGameRules + 0x20))(g_pGameRules);
    if (iVar3 == 0) {
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x1a6];
      if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) &&
         (0.0 < (float)param_1[0x1a6])) {
        iVar3 = param_1[iVar4 + 0x1a7];
        if (iVar3 == 0) {
          iVar4 = iVar4 + 1;
          if (iVar4 == 4) {
            iVar4 = 0;
          }
          iVar3 = param_1[iVar4 + 0x1a7];
          if (iVar3 == 0) {
            iVar4 = iVar4 + 1;
            if (iVar4 == 4) {
              iVar4 = 0;
            }
            iVar3 = param_1[iVar4 + 0x1a7];
            if (iVar3 == 0) {
              iVar4 = iVar4 + 1;
              if (iVar4 == 4) {
                iVar4 = 0;
              }
              iVar3 = param_1[iVar4 + 0x1a7];
              if (iVar3 == 0) {
                param_1[0x1a6] = 0;
                return;
              }
            }
          }
        }
        param_1[iVar4 + 0x1a7] = 0;
        if (iVar3 < 1) {
          EMIT_GROUPID_SUIT__FP7edict_si(*(undefined4 *)(*param_1 + 0x208),-iVar3);
        }
        else {
          local_14[0] = 0x21;
          strcat((char *)local_14,gszallsentencenames + iVar3 * 0x10);
          EMIT_SOUND_SUIT__FP7edict_sPCc(*(undefined4 *)(*param_1 + 0x208),local_14);
        }
        param_1[0x1a6] = (int)(*gpGlobals + 3.5);
      }
    }
  }
  return;
}


