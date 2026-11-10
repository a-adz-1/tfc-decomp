// FindNearestFriend__12CTalkMonsteri  @ 000f7798
int * FindNearestFriend__12CTalkMonsteri(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  float local_84;
  int *local_80;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float local_2c;
  
  piVar6 = (int *)0x0;
  local_80 = (int *)0x0;
  local_84 = 1e+07;
  iVar3 = *param_1;
  local_48 = *(float *)(iVar3 + 8);
  local_44 = *(float *)(iVar3 + 0xc);
  iVar4 = 3;
  local_40 = *(float *)(iVar3 + 0xd8);
  if (param_2 != 0) {
    iVar4 = 1;
  }
  while (iVar4 = iVar4 + -1, -1 < iVar4) {
    if (param_2 == 0) {
      iVar3 = (**(code **)(param_1[0x115] + 0x224))(param_1,iVar4);
      pcVar5 = *(char **)(_12CTalkMonster_m_szFriends + iVar3 * 4);
    }
    else {
      pcVar5 = "player";
    }
    if (pcVar5 != (char *)0x0) {
      while (piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,pcVar5),
            piVar6 != (int *)0x0) {
        if ((((piVar6 != param_1) &&
             (iVar3 = (**(code **)(piVar6[0x115] + 0x8c))(piVar6), iVar3 != 0)) &&
            (iVar3 = (**(code **)(piVar6[0x115] + 0x50))(piVar6), iVar3 != 0)) &&
           ((*(int *)(iVar3 + 0x574) != 6 && (*(int *)(iVar3 + 0x574) != 5)))) {
          local_54 = *(float *)(*piVar6 + 8);
          local_50 = *(float *)(*piVar6 + 0xc);
          local_4c = *(float *)(*piVar6 + 0xd8);
          if ((SQRT((local_40 - local_4c) * (local_40 - local_4c) +
                    (local_44 - local_50) * (local_44 - local_50) +
                    (local_48 - local_54) * (local_48 - local_54)) < local_84) &&
             (UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                        (&local_48,&local_54,1,*(undefined4 *)(*param_1 + 0x208),local_3c),
             (byte)((byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40)) {
            fVar1 = (local_40 - local_4c) * (local_40 - local_4c) +
                    (local_44 - local_50) * (local_44 - local_50) +
                    (local_48 - local_54) * (local_48 - local_54);
            fVar2 = SQRT(fVar1);
            if (0x3f < (byte)((500.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar2 == 500.0) << 0xe) >> 8)) - 1)) {
              local_84 = SQRT(fVar1);
              local_80 = piVar6;
            }
          }
        }
      }
    }
  }
  return local_80;
}


