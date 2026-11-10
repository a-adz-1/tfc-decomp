// FindNearestFriend__12CTalkMonsteri  @ 000f5764
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FindNearestFriend__12CTalkMonsteri(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  float local_80;
  int *local_7c;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  undefined1 auStack_38 [16];
  float fStack_28;
  
  piVar5 = (int *)0x0;
  local_7c = (int *)0x0;
  local_80 = 1e+07;
  iVar3 = *param_1;
  fStack_44 = *(float *)(iVar3 + 8);
  fStack_40 = *(float *)(iVar3 + 0xc);
  fStack_3c = *(float *)(iVar3 + 0xd8);
  iVar3 = 3;
  if (param_2 != 0) {
    iVar3 = 1;
  }
  while (iVar3 = iVar3 + -1, -1 < iVar3) {
    if (param_2 == 0) {
      iVar2 = (**(code **)(param_1[0x111] + 0x224))(param_1,iVar3);
      pcVar4 = *(char **)(_12CTalkMonster_m_szFriends + iVar2 * 4);
    }
    else {
      pcVar4 = "player";
    }
    if (pcVar4 != (char *)0x0) {
      while (piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,pcVar4),
            piVar5 != (int *)0x0) {
        if ((((piVar5 != param_1) &&
             (iVar2 = (**(code **)(piVar5[0x111] + 0x8c))(piVar5), iVar2 != 0)) &&
            (iVar2 = (**(code **)(piVar5[0x111] + 0x50))(piVar5), iVar2 != 0)) &&
           ((*(int *)(iVar2 + 0x564) != 6 && (*(int *)(iVar2 + 0x564) != 5)))) {
          fStack_50 = *(float *)(*piVar5 + 8);
          fStack_4c = *(float *)(*piVar5 + 0xc);
          fStack_48 = *(float *)(*piVar5 + 0xd8);
          if ((SQRT((fStack_3c - fStack_48) * (fStack_3c - fStack_48) +
                    (fStack_40 - fStack_4c) * (fStack_40 - fStack_4c) +
                    (fStack_44 - fStack_50) * (fStack_44 - fStack_50)) < local_80) &&
             ((UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                         (&fStack_44,&fStack_50,1,*(undefined4 *)(*param_1 + 0x208),auStack_38),
              (byte)((byte)((ushort)((ushort)(NAN((float)_FUN_0014e3d8) || NAN(fStack_28)) << 10) >>
                           8) |
                    (byte)((ushort)((ushort)((float)_FUN_0014e3d8 == fStack_28) << 0xe) >> 8)) ==
              0x40 && (fVar1 = SQRT((fStack_3c - fStack_48) * (fStack_3c - fStack_48) +
                                    (fStack_40 - fStack_4c) * (fStack_40 - fStack_4c) +
                                    (fStack_44 - fStack_50) * (fStack_44 - fStack_50)),
                      0x3f < (byte)((500.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8)
                                    | (byte)((ushort)((ushort)(fVar1 == 500.0) << 0xe) >> 8)) - 1)))
             )) {
            local_80 = SQRT((fStack_3c - fStack_48) * (fStack_3c - fStack_48) +
                            (fStack_40 - fStack_4c) * (fStack_40 - fStack_4c) +
                            (fStack_44 - fStack_50) * (fStack_44 - fStack_50));
            local_7c = piVar5;
          }
        }
      }
    }
  }
  return local_7c;
}


