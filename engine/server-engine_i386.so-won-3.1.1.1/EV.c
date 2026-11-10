// EV_PlayReliableEvent  @ 00089628
void EV_PlayReliableEvent
               (int param_1,undefined4 param_2,undefined2 param_3,float param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_4ac [72];
  undefined4 local_464 [18];
  char *local_41c [2];
  undefined1 *local_414;
  undefined4 local_410;
  int local_40c;
  undefined1 local_408 [1026];
  undefined2 local_6;
  
  local_6 = param_3;
  if (*(int *)(param_1 + 0x2438) == 0) {
    Q_memset(local_41c,0,0x14);
    local_41c[0] = "Reliable Event";
    local_414 = local_408;
    local_40c = 0;
    local_410 = 0x400;
    Q_memset(local_4ac,0,0x48);
    puVar2 = local_464;
    for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_5;
      param_5 = param_5 + 1;
      puVar2 = puVar2 + 1;
    }
    local_464[1] = param_2;
    MSG_WriteByte(local_41c,0x15);
    MSG_StartBitWriting(local_41c);
    MSG_WriteBits(local_6,10);
    DELTA_WriteDelta(local_4ac,local_464,1,g_peventdelta,0);
    if ((byte)((byte)((ushort)((ushort)NAN(param_4) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_4 == 0.0) << 0xe) >> 8)) == 0x40) {
      MSG_WriteBits(0,1);
    }
    else {
      MSG_WriteBits(1,1);
      MSG_WriteBits((int)ROUND(param_4 * 100.0),0x10);
    }
    MSG_EndBitWriting(local_41c);
    if (*(int *)(param_1 + 0x80) < local_40c + *(int *)(param_1 + 0x84)) {
      Netchan_CreateFragments(1,param_1 + 0x1c,local_41c);
    }
    else {
      SZ_Write(param_1 + 0x74,local_414,local_40c);
    }
  }
  return;
}


// EV_Playback  @ 00089828
void EV_Playback(uint param_1,int param_2,ushort param_3,int param_4,undefined4 *param_5,
                undefined4 *param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint *puVar5;
  int local_84;
  int local_80;
  uint local_78 [4];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  ushort *local_2c;
  int *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int *local_c;
  ushort local_6;
  
  local_6 = param_3;
  local_80 = -1;
  if ((param_1 & 0x40) == 0) {
    Q_memset(local_78,0,0x48);
    iVar1 = VectorCompare(param_5,&vec3_origin);
    if (iVar1 == 0) {
      local_78[2] = *param_5;
      local_78[3] = param_5[1];
      local_68 = param_5[2];
      local_78[0] = local_78[0] | 1;
    }
    iVar1 = VectorCompare(param_6,&vec3_origin);
    if (iVar1 == 0) {
      local_64 = *param_6;
      local_60 = param_6[1];
      local_5c = param_6[2];
      local_78[0] = local_78[0] | 2;
    }
    local_48 = param_7;
    local_44 = param_8;
    local_40 = param_9;
    local_3c = param_10;
    local_38 = param_11;
    local_34 = param_12;
    if ((local_6 == 0) || (0xff < local_6)) {
      Con_DPrintf("EV_Playback:  index out of range %i\n",local_6);
    }
    else if (*(int *)(&DAT_0039cfb4 + (uint)local_6 * 0x10) == 0) {
      Con_DPrintf("EV_Playback:  no event for index %i\n",local_6);
    }
    else {
      if (param_2 == 0) {
        local_1c = local_78[2];
        local_18 = local_78[3];
        local_14 = local_68;
      }
      else {
        local_1c = *(undefined4 *)(param_2 + 0x88);
        local_18 = *(undefined4 *)(param_2 + 0x8c);
        local_14 = *(undefined4 *)(param_2 + 0x90);
        local_80 = NUM_FOR_EDICT(param_2);
        if (((0 < local_80) && (local_80 <= DAT_00524288)) &&
           ((*(uint *)(param_2 + 0x224) & 0x4000) != 0)) {
          local_4c = 1;
        }
        if ((local_78[0] & 1) == 0) {
          local_78[2] = *(undefined4 *)(param_2 + 0x88);
          local_78[3] = *(undefined4 *)(param_2 + 0x8c);
          local_68 = *(undefined4 *)(param_2 + 0x90);
        }
        if ((local_78[0] & 2) == 0) {
          local_64 = *(undefined4 *)(param_2 + 0xd0);
          local_60 = *(undefined4 *)(param_2 + 0xd4);
          local_5c = *(undefined4 *)(param_2 + 0xd8);
        }
      }
      local_20 = 4;
      local_24 = SV_PointLeafnum(&local_1c);
      for (local_10 = 0; local_10 < DAT_00524288; local_10 = local_10 + 1) {
        local_c = (int *)(DAT_00524284 + local_10 * 0x4eec);
        if (((*local_c == 0) || (local_c[1] == 0)) ||
           ((local_c[3] == 0 || ((local_c[2] == 0 || (local_c[0x90e] != 0)))))) goto LAB_00089dab;
        if ((param_2 == 0) ||
           ((*(int *)(param_2 + 0x2c0) == 0 || (*(int *)(local_c[0x12a1] + 0x2c0) == 0)))) {
LAB_00089b90:
          if ((((((param_1 & 4) != 0) || (param_2 == 0)) ||
               (iVar1 = SV_ValidClientMulticast(local_c,local_24,local_20), iVar1 != 0)) &&
              (((local_c != host_client || ((param_1 & 1) == 0)) || (local_c[0x1376] == 0)))) &&
             (((param_1 & 0x10) == 0 || (local_c[0x12a1] == param_2)))) {
            if ((param_1 & 2) == 0) {
              local_28 = local_c + 0xd21;
              local_30 = -1;
              if ((param_1 & 8) != 0) {
                for (local_84 = 0; local_84 < 0x40; local_84 = local_84 + 1) {
                  local_2c = (ushort *)(local_28 + local_84 * 0x16);
                  if (((*local_2c == local_6) && (local_80 != -1)) &&
                     ((short)local_2c[2] == local_80)) {
                    local_30 = local_84;
                    break;
                  }
                }
              }
              if (local_30 == -1) {
                for (local_84 = 0; local_84 < 0x40; local_84 = local_84 + 1) {
                  local_2c = (ushort *)(local_28 + local_84 * 0x16);
                  if (*(ushort *)(local_28 + local_84 * 0x16) == 0) {
                    local_30 = local_84;
                    break;
                  }
                }
                if ((0x3f < local_84) && (local_30 != -1)) {
                  local_2c = (ushort *)(local_28 + local_30 * 0x16);
                }
              }
              if (local_30 != -1) {
                *local_2c = local_6;
                local_2c[1] = 0xffff;
                if (param_2 == 0) {
                  local_2c[2] = 0xffff;
                }
                else {
                  local_2c[2] = (ushort)local_80;
                }
                puVar4 = local_78;
                puVar5 = (uint *)(local_2c + 6);
                for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
                  *puVar5 = *puVar4;
                  puVar4 = puVar4 + 1;
                  puVar5 = puVar5 + 1;
                }
                *(int *)(local_2c + 4) = param_4;
              }
            }
            else {
              puVar4 = local_78;
              uVar2 = (uint)local_6;
              iVar1 = param_4;
              if (param_2 == 0) {
                uVar3 = 0;
              }
              else {
                uVar3 = NUM_FOR_EDICT(param_2);
              }
              EV_PlayReliableEvent(local_c,uVar3,uVar2,iVar1,puVar4);
            }
          }
        }
        else if (g_groupop == 0) {
          if ((*(uint *)(param_2 + 0x2c0) & *(uint *)(local_c[0x12a1] + 0x2c0)) != 0)
          goto LAB_00089b90;
        }
        else if ((g_groupop != 1) ||
                ((*(uint *)(param_2 + 0x2c0) & *(uint *)(local_c[0x12a1] + 0x2c0)) == 0))
        goto LAB_00089b90;
LAB_00089dab:
      }
    }
  }
  return;
}


// EV_Precache  @ 00089364
uint EV_Precache(int param_1,int param_2)

{
  int iVar1;
  char local_114 [260];
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_c = 0;
  if (param_2 == 0) {
    Host_Error(FUN_000e5c94);
  }
  else {
    iVar1 = PR_IsEmptyString(param_2);
    if (iVar1 == 0) {
      if (DAT_003a78c4 != 1) {
        for (local_8 = 1; (int)local_8 < 0x100; local_8 = local_8 + 1) {
          if ((*(int *)(&DAT_0039cfac + local_8 * 0x10) != 0) &&
             (iVar1 = Q_stricmp(*(undefined4 *)(&DAT_0039cfac + local_8 * 0x10),param_2), iVar1 == 0
             )) {
            return local_8 & 0xffff;
          }
        }
        Host_Error("EV_Precache: \'%s\' Precache can only be done in spawn functions",param_2);
      }
      for (local_8 = 1; (int)local_8 < 0x100; local_8 = local_8 + 1) {
        if (*(int *)(&DAT_0039cfac + local_8 * 0x10) == 0) {
          if (param_1 != 1) {
            Host_Error("EV_Precache:  only file type 1 supported currently\n");
            return 0;
          }
          snprintf(local_114,0x104,"%s",param_2);
          COM_FixSlashes(local_114);
          local_c = COM_LoadFile(local_114,5,&local_10);
          if (local_c == 0) {
            Host_Error("EV_Precache:  file %s missing from server\n",param_2);
            return 0;
          }
          *(int *)(&DAT_0039cfac + local_8 * 0x10) = param_2;
          *(undefined4 *)(local_8 * 0x10 + 0x39cfb0) = local_10;
          *(int *)(&DAT_0039cfb4 + local_8 * 0x10) = local_c;
          *(short *)(local_8 * 0x10 + 0x39cfa8) = (short)local_8;
          return local_8 & 0xffff;
        }
        iVar1 = Q_stricmp(*(undefined4 *)(&DAT_0039cfac + local_8 * 0x10),param_2);
        if (iVar1 == 0) {
          return local_8 & 0xffff;
        }
      }
      Host_Error(FUN_000e5d94,param_2);
    }
    else {
      Host_Error("EV_Precache: Bad string \'%s\'",param_2);
    }
  }
  return 0;
}


// EV_SV_Playback  @ 00089dc4
void EV_SV_Playback(uint param_1,int param_2,undefined2 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                   undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  if ((param_1 & 0x40) == 0) {
    if ((param_2 < 0) || (DAT_00524288 <= param_2)) {
      Host_Error("EV_SV_Playback:  Client index %i out of range\n",param_2);
    }
    else {
      EV_Playback(param_1,*(undefined4 *)(DAT_00524284 + 0x4a84 + param_2 * 0x4eec),param_3,param_4,
                  param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12);
    }
  }
  return;
}


