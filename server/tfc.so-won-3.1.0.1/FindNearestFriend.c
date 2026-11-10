// FindNearestFriend__12CTalkMonsteri  @ 000e8a88
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FindNearestFriend__12CTalkMonsteri(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  float local_80;
  int *local_7c;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 auStack_38 [16];
  float fStack_28;
  
  piVar6 = (int *)0x0;
  local_7c = (int *)0x0;
  local_80 = 1e+07;
  iVar4 = *param_1;
  local_44 = *(float *)(iVar4 + 8);
  local_40 = *(float *)(iVar4 + 0xc);
  local_3c = *(float *)(iVar4 + 0xd8);
  iVar4 = 3;
  if (param_2 != 0) {
    iVar4 = 1;
  }
  while (iVar4 = iVar4 + -1, -1 < iVar4) {
    if (param_2 == 0) {
      iVar3 = (**(code **)(param_1[0xf5] + 0x21c))(param_1,iVar4);
      pcVar5 = *(char **)(_12CTalkMonster_m_szFriends + iVar3 * 4);
    }
    else {
      pcVar5 = "player";
    }
    if (pcVar5 != (char *)0x0) {
      while (piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,pcVar5),
            piVar6 != (int *)0x0) {
        if ((((piVar6 != param_1) &&
             (iVar3 = (**(code **)(piVar6[0xf5] + 0x88))(piVar6), iVar3 != 0)) &&
            (iVar3 = (**(code **)(piVar6[0xf5] + 0x4c))(piVar6), iVar3 != 0)) &&
           ((*(int *)(iVar3 + 0x4f4) != 6 && (*(int *)(iVar3 + 0x4f4) != 5)))) {
          fStack_50 = *(float *)(*piVar6 + 8);
          fStack_4c = *(float *)(*piVar6 + 0xc);
          fStack_48 = *(float *)(*piVar6 + 0xd8);
          if ((SQRT((local_3c - fStack_48) * (local_3c - fStack_48) +
                    (local_40 - fStack_4c) * (local_40 - fStack_4c) +
                    (local_44 - fStack_50) * (local_44 - fStack_50)) < local_80) &&
             (UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                        (&local_44,&fStack_50,1,*(undefined4 *)(*param_1 + 0x208),auStack_38),
             (byte)((byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) == 0x40)) {
            fVar1 = SQRT((local_3c - fStack_48) * (local_3c - fStack_48) +
                         (local_40 - fStack_4c) * (local_40 - fStack_4c) +
                         (local_44 - fStack_50) * (local_44 - fStack_50));
            fVar2 = (float)_FUN_0013d610;
            if (0x3f < (byte)((fVar2 < fVar1 |
                               (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
              local_80 = SQRT((local_3c - fStack_48) * (local_3c - fStack_48) +
                              (local_40 - fStack_4c) * (local_40 - fStack_4c) +
                              (local_44 - fStack_50) * (local_44 - fStack_50));
              local_7c = piVar6;
            }
          }
        }
      }
    }
  }
  return local_7c;
}


