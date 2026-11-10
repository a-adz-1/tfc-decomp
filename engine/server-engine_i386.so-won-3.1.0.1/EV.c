// EV_PlayReliableEvent  @ 0006e408
void EV_PlayReliableEvent
               (int param_1,undefined4 param_2,undefined2 param_3,float param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_94 [72];
  undefined4 local_4c [18];
  
  if (g_peventdelta == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("g_peventdelta","/home/jihad/valve/goldsrc/engine/pr_cmds.c",0x5ce,
                  "EV_PlayReliableEvent");
  }
  Q_memset(local_94,0,0x48);
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_5;
    param_5 = param_5 + 1;
    puVar2 = puVar2 + 1;
  }
  local_4c[1] = param_2;
  param_1 = param_1 + 0x74;
  MSG_WriteByte(param_1,0x15);
  MSG_StartBitWriting(param_1);
  MSG_WriteBits(param_3,10);
  DELTA_WriteDelta(local_94,local_4c,1,g_peventdelta,0);
  if ((byte)((byte)((ushort)((ushort)NAN(param_4) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_4 == 0.0) << 0xe) >> 8)) == 0x40) {
    MSG_WriteBits(0,1);
  }
  else {
    MSG_WriteBits(1,1);
    MSG_WriteBits((int)ROUND(param_4 * 100.0),0x10);
  }
  MSG_EndBitWriting(param_1);
  return;
}


// EV_Playback  @ 0006e554
void EV_Playback(uint param_1,int param_2,ushort param_3,int param_4,undefined4 *param_5,
                undefined4 *param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  ushort *puVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  int *piVar13;
  uint *puVar14;
  int *local_88;
  ushort *local_84;
  int local_80;
  int local_74;
  int local_70;
  ushort *local_6c;
  int local_60;
  uint local_58 [2];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_74 = -1;
  if ((param_1 & 0x40) == 0) {
    Q_memset(local_58,0,0x48);
    iVar5 = VectorCompare(param_5,&vec3_origin);
    if (iVar5 == 0) {
      local_50 = *param_5;
      local_4c = param_5[1];
      local_48 = param_5[2];
      local_58[0] = local_58[0] | 1;
    }
    iVar5 = VectorCompare(param_6,&vec3_origin);
    if (iVar5 == 0) {
      local_44 = *param_6;
      local_40 = param_6[1];
      local_3c = param_6[2];
      local_58[0] = local_58[0] | 2;
    }
    local_20 = param_9;
    local_1c = param_10;
    local_18 = param_11;
    local_14 = param_12;
    local_28 = param_7;
    local_24 = param_8;
    if ((ushort)(param_3 - 1) < 0xff) {
      uVar10 = (uint)param_3;
      if (*(int *)(&DAT_00184694 + uVar10 * 0x10) != 0) {
        if (param_2 == 0) {
          local_10 = local_50;
          local_c = local_4c;
          local_8 = local_48;
        }
        else {
          local_10 = *(undefined4 *)(param_2 + 0x88);
          local_c = *(undefined4 *)(param_2 + 0x8c);
          local_8 = *(undefined4 *)(param_2 + 0x90);
          local_74 = NUM_FOR_EDICT(param_2);
          if (((0 < local_74) && (local_74 <= DAT_001ab4e8)) &&
             ((*(byte *)(param_2 + 0x225) & 0x40) != 0)) {
            local_2c = 1;
          }
          if ((local_58[0] & 1) == 0) {
            local_50 = *(undefined4 *)(param_2 + 0x88);
            local_4c = *(undefined4 *)(param_2 + 0x8c);
            local_48 = *(undefined4 *)(param_2 + 0x90);
          }
          if ((local_58[0] & 2) == 0) {
            local_44 = *(undefined4 *)(param_2 + 0xd0);
            local_40 = *(undefined4 *)(param_2 + 0xd4);
            local_3c = *(undefined4 *)(param_2 + 0xd8);
          }
        }
        uVar7 = SV_PointLeafnum(&local_10);
        local_60 = 0;
        if (DAT_001ab4e8 < 1) {
          return;
        }
        local_80 = 0;
        do {
          piVar13 = (int *)(local_80 + DAT_001ab4e4);
          if (((*piVar13 == 0) || (piVar13[1] == 0)) ||
             ((piVar13[3] == 0 || ((piVar13[2] == 0 || (piVar13[0x918] != 0)))))) goto LAB_0006ea7f;
          if ((param_2 == 0) ||
             ((uVar2 = *(uint *)(param_2 + 0x2c0), uVar2 == 0 ||
              (uVar3 = *(uint *)(piVar13[0x12b9] + 0x2c0), uVar3 == 0)))) {
LAB_0006e7d5:
            if (((((param_1 & 4) != 0) || (param_2 == 0)) ||
                (iVar5 = SV_ValidClientMulticast(piVar13,uVar7,4), iVar5 != 0)) &&
               ((((piVar13 != host_client || ((param_1 & 1) == 0)) || (piVar13[0x13d3] == 0)) &&
                (((param_1 & 0x10) == 0 || (piVar13[0x12b9] == param_2)))))) {
              if ((param_1 & 2) == 0) {
                puVar1 = (ushort *)(piVar13 + 0xd39);
                local_70 = -1;
                iVar5 = local_70;
                if ((param_1 & 8) != 0) {
                  iVar11 = 0;
                  local_88 = piVar13 + 0xd3a;
                  local_84 = puVar1;
                  do {
                    local_6c = local_84;
                    if (((*local_84 == param_3) && (local_74 != -1)) &&
                       (iVar5 = iVar11, (short)*local_88 == local_74)) break;
                    local_6c = local_84 + 0x2c;
                    if (((local_84[0x2c] == param_3) && (local_74 != -1)) &&
                       (iVar5 = iVar11 + 1, (short)local_88[0x16] == local_74)) break;
                    local_6c = local_84 + 0x58;
                    if (((local_84[0x58] == param_3) && (local_74 != -1)) &&
                       (iVar5 = iVar11 + 2, (short)local_88[0x2c] == local_74)) break;
                    local_6c = local_84 + 0x84;
                    if (((local_84[0x84] == param_3) && (local_74 != -1)) &&
                       (iVar5 = iVar11 + 3, (short)local_88[0x42] == local_74)) break;
                    local_88 = local_88 + 0x58;
                    local_84 = local_84 + 0xb0;
                    iVar11 = iVar11 + 4;
                    iVar5 = local_70;
                  } while (iVar11 < 0x40);
                }
                local_70 = iVar5;
                if (local_70 == -1) {
                  iVar5 = 0;
                  puVar9 = puVar1;
                  do {
                    iVar11 = iVar5;
                    iVar4 = iVar5;
                    local_6c = puVar9;
                    if (*puVar9 == 0) break;
                    local_6c = puVar9 + 0x2c;
                    iVar11 = iVar5 + 1;
                    iVar4 = iVar11;
                    if (*local_6c == 0) break;
                    iVar11 = iVar5 + 2;
                    local_6c = puVar9 + 0x58;
                    iVar4 = iVar11;
                    if (puVar9[0x58] == 0) break;
                    iVar11 = iVar5 + 3;
                    local_6c = puVar9 + 0x84;
                    iVar4 = iVar11;
                    if (puVar9[0x84] == 0) break;
                    puVar9 = puVar9 + 0xb0;
                    iVar5 = iVar5 + 4;
                    iVar11 = iVar5;
                    iVar4 = local_70;
                  } while (iVar5 < 0x40);
                  local_70 = iVar4;
                  if (0x3f < iVar11) {
                    if (local_70 == -1) {
                      Con_DPrintf("EV_Playback:  no slot for %s on %s\n",
                                  *(undefined4 *)(&DAT_0018468c + uVar10 * 0x10),piVar13 + 0x130f);
                    }
                    else {
                      local_6c = puVar1 + local_70 * 0x2c;
                    }
                  }
                  if (local_70 == -1) goto LAB_0006ea7f;
                }
                *local_6c = param_3;
                local_6c[1] = 0xffff;
                if (param_2 == 0) {
                  local_6c[2] = 0xffff;
                }
                else {
                  local_6c[2] = (ushort)local_74;
                }
                puVar12 = local_58;
                puVar14 = (uint *)(local_6c + 6);
                for (iVar5 = 0x12; iVar5 != 0; iVar5 = iVar5 + -1) {
                  *puVar14 = *puVar12;
                  puVar12 = puVar12 + 1;
                  puVar14 = puVar14 + 1;
                }
                *(int *)(local_6c + 4) = param_4;
              }
              else {
                if (param_2 == 0) {
                  uVar8 = 0;
                }
                else {
                  uVar8 = NUM_FOR_EDICT(param_2,uVar10,param_4,local_58);
                }
                EV_PlayReliableEvent(piVar13,uVar8);
              }
            }
          }
          else if (g_groupop == 0) {
            if ((uVar3 & uVar2) != 0) goto LAB_0006e7d5;
          }
          else if ((g_groupop != 1) || ((uVar2 & uVar3) == 0)) goto LAB_0006e7d5;
LAB_0006ea7f:
          local_80 = local_80 + 0x5054;
          local_60 = local_60 + 1;
          if (DAT_001ab4e8 <= local_60) {
            return;
          }
        } while( true );
      }
      pcVar6 = "EV_Playback:  no event for index %i\n";
    }
    else {
      pcVar6 = "EV_Playback:  index out of range %i\n";
    }
    Con_DPrintf(pcVar6,param_3);
  }
  return;
}


// EV_Precache  @ 0006e1cc
uint EV_Precache(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int *local_114;
  undefined4 local_10c;
  char local_108 [260];
  
  if (DAT_00186fa0 != 1) {
    iVar4 = 0x10;
    uVar3 = 1;
    do {
      if ((*(int *)(&DAT_0018468c + iVar4) != 0) &&
         (iVar1 = Q_stricmp(*(int *)(&DAT_0018468c + iVar4),param_2), iVar1 == 0))
      goto LAB_0006e3c9;
      if ((*(int *)((int)&DAT_0018469c + iVar4) != 0) &&
         (iVar1 = Q_stricmp(*(int *)((int)&DAT_0018469c + iVar4),param_2), iVar1 == 0)) {
        return uVar3 + 1 & 0xffff;
      }
      if ((*(int *)((int)&DAT_001846ac + iVar4) != 0) &&
         (iVar1 = Q_stricmp(*(int *)((int)&DAT_001846ac + iVar4),param_2), iVar1 == 0)) {
        return uVar3 + 2 & 0xffff;
      }
      iVar4 = iVar4 + 0x30;
      uVar3 = uVar3 + 3;
    } while ((int)uVar3 < 0x100);
    Host_Error("EV_Precache: \'%s\' Precache can only be done in spawn functions",param_2);
  }
  PR_CheckEmptyString(param_2);
  local_114 = &DAT_0018469c;
  iVar4 = 0x10;
  uVar3 = 1;
  do {
    if (*local_114 == 0) {
      if (param_1 != 1) {
        Host_Error("EV_Precache:  only file type 1 supported currently\n");
        return 0;
      }
      sprintf(local_108,"%s",param_2);
      COM_FixSlashes(local_108);
      iVar1 = COM_LoadFile(local_108,5,&local_10c);
      if (iVar1 != 0) {
        *local_114 = param_2;
        *(undefined4 *)(&DAT_00184690 + iVar4) = local_10c;
        *(int *)(&DAT_00184694 + iVar4) = iVar1;
        *(short *)(iVar4 + 0x184688) = (short)uVar3;
LAB_0006e3c9:
        return uVar3 & 0xffff;
      }
      pcVar2 = "EV_Precache:  file %s missing from server\n";
      goto LAB_0006e3f1;
    }
    iVar1 = Q_stricmp(*local_114,param_2);
    if (iVar1 == 0) goto LAB_0006e3c9;
    local_114 = local_114 + 4;
    iVar4 = iVar4 + 0x10;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x100);
  pcVar2 = "EV_Precache: \'%s\' overflow";
LAB_0006e3f1:
  Host_Error(pcVar2,param_2);
  return 0;
}


// EV_SV_Playback  @ 0006eaa8
void EV_SV_Playback(uint param_1,int param_2,undefined2 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                   undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  if ((param_1 & 0x40) == 0) {
    if ((param_2 < 0) || (DAT_001ab4e8 <= param_2)) {
      Host_Error("EV_SV_Playback:  Client index %i out of range\n",param_2);
    }
    else {
      EV_Playback(param_1,*(undefined4 *)(DAT_001ab4e4 + 0x4ae4 + param_2 * 0x5054),param_3,param_4,
                  param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12);
    }
  }
  return;
}


