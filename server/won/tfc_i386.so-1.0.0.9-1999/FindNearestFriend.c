// FindNearestFriend__12CTalkMonsteri  @ 000f1f50
int * FindNearestFriend__12CTalkMonsteri(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  float local_84;
  int *local_80;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  
  piVar4 = (int *)0x0;
  local_80 = (int *)0x0;
  local_84 = 1e+07;
  iVar3 = *param_1;
  local_48 = *(float *)(iVar3 + 8);
  local_44 = *(float *)(iVar3 + 0xc);
  local_40 = *(float *)(iVar3 + 0xb8);
  iVar3 = 3;
  if (param_2 != 0) {
    iVar3 = 1;
  }
  while (iVar3 = iVar3 + -1, -1 < iVar3) {
    if (param_2 == 0) {
      iVar2 = (**(code **)(param_1[0xf2] + 0x21c))(param_1,iVar3);
      pcVar5 = *(char **)(_12CTalkMonster_m_szFriends + iVar2 * 4);
    }
    else {
      pcVar5 = "player";
    }
    if (pcVar5 != (char *)0x0) {
      while (piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,pcVar5),
            piVar4 != (int *)0x0) {
        if ((((piVar4 != param_1) &&
             (iVar2 = (**(code **)(piVar4[0xf2] + 0x88))(piVar4), iVar2 != 0)) &&
            (iVar2 = (**(code **)(piVar4[0xf2] + 0x4c))(piVar4), iVar2 != 0)) &&
           ((*(int *)(iVar2 + 0x4e8) != 6 && (*(int *)(iVar2 + 0x4e8) != 5)))) {
          fStack_54 = *(float *)(*piVar4 + 8);
          fStack_50 = *(float *)(*piVar4 + 0xc);
          fStack_4c = *(float *)(*piVar4 + 0xb8);
          fVar1 = SQRT((local_40 - fStack_4c) * (local_40 - fStack_4c) +
                       (local_44 - fStack_50) * (local_44 - fStack_50) +
                       (local_48 - fStack_54) * (local_48 - fStack_54));
          if (((byte)(fVar1 < local_84 |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(local_84)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == local_84) << 0xe) >> 8)) == 1) &&
             ((UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                         (&local_48,&fStack_54,1,*(undefined4 *)(*param_1 + 0x1e8),auStack_3c),
              (byte)((byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40 &&
              (SQRT((local_40 - fStack_4c) * (local_40 - fStack_4c) +
                    (local_44 - fStack_50) * (local_44 - fStack_50) +
                    (local_48 - fStack_54) * (local_48 - fStack_54)) < 500.0)))) {
            local_84 = SQRT((local_40 - fStack_4c) * (local_40 - fStack_4c) +
                            (local_44 - fStack_50) * (local_44 - fStack_50) +
                            (local_48 - fStack_54) * (local_48 - fStack_54));
            local_80 = piVar4;
          }
        }
      }
    }
  }
  return local_80;
}


