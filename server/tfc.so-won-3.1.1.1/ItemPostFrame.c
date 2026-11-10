// ItemPostFrame__11CBasePlayer  @ 000e5348
void ItemPostFrame__11CBasePlayer(int param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x88c);
  if ((iVar2 == 0) &&
     (fVar1 = *(float *)(param_1 + 0x658),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1)) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x22c))(param_1);
    iVar2 = *(int *)(param_1 + 0x8dc);
    if (iVar2 != 0) {
      (**(code **)(*(int *)(iVar2 + 0x454) + 0x134))(iVar2);
    }
  }
  return;
}


// ItemPostFrame__14CTFSniperRifle  @ 0013164c
void ItemPostFrame__14CTFSniperRifle(int param_1)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  undefined1 local_30 [16];
  int local_20;
  byte bStack_c;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x118))(param_1,local_30);
  piVar4 = *(int **)(param_1 + 0x474);
  if (((*(byte *)(*piVar4 + 0x181) & 8) == 0) ||
     (fVar2 = *(float *)(param_1 + 0x48c),
     (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1)) {
    if (((*(byte *)(piVar4 + 0x1b7) & 1) != 0) &&
       (fVar2 = *(float *)(param_1 + 0x488),
       (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
      if ((piVar4[0x21] & 0x800U) != 0) {
        piVar4[0x21] = piVar4[0x21] & 0xfffff7ff;
        TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x474));
        if ((*(byte *)(**(int **)(param_1 + 0x474) + 0x1a5) & 2) == 0) {
          ClientPrint__FP9entvars_siPCcN42(**(int **)(param_1 + 0x474),4,"#Sniper_cantfire",0,0,0,0)
          ;
        }
        else {
          (**(code **)(*(int *)(param_1 + 0x454) + 0x170))(param_1);
        }
        *(undefined4 *)(param_1 + 0x4d4) = 0;
        iVar5 = *(int *)(param_1 + 0x4d0);
        if (iVar5 != 0) {
          (**(code **)(*(int *)(iVar5 + 0x454) + 0x40))(iVar5,0,0,1);
        }
        *(undefined4 *)(param_1 + 0x4d0) = 0;
        *(undefined4 *)(param_1 + 0x4a0) = 0;
      }
      goto LAB_00131978;
    }
    iVar5 = *piVar4;
    if (((*(byte *)(iVar5 + 0x180) & 1) != 0) &&
       (fVar2 = *(float *)(param_1 + 0x488),
       (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
      if ((*(byte *)((int)piVar4 + 0x85) & 8) == 0) {
        fVar2 = SQRT(*(float *)(iVar5 + 0x24) * *(float *)(iVar5 + 0x24) +
                     *(float *)(iVar5 + 0x20) * *(float *)(iVar5 + 0x20));
        if ((byte)(50.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 50.0) << 0xe) >> 8)) != 1) {
          *(undefined4 *)(param_1 + 0x4d4) = 1;
          *(undefined4 *)(param_1 + 0x4a0) = 0x42480000;
          *(undefined4 *)(param_1 + 0x4a4) = 0;
          *(byte *)((int)piVar4 + 0x85) = *(byte *)((int)piVar4 + 0x85) | 8;
          TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x474));
          (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,1,1);
          *(undefined4 *)(param_1 + 0x490) = 0x447a0000;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x4d4) = 1;
        fVar2 = *(float *)(param_1 + 0x4a0);
        if (0x3f < (byte)((400.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 400.0) << 0xe) >> 8)) - 1)) {
          fVar3 = *(float *)(param_1 + 0x4a4);
          *(undefined4 *)(param_1 + 0x4a4) = 0;
          *(float *)(param_1 + 0x4a0) = -fVar3 * 50.0 + fVar2;
        }
        UpdateSpot__14CTFSniperRifle(param_1);
      }
      goto LAB_00131978;
    }
    if ((*(uint *)(*piVar4 + 0x180) & 0x801) != 0) goto LAB_00131978;
    *(undefined4 *)(param_1 + 0x484) = 0;
    iVar5 = (**(code **)(*(int *)(param_1 + 0x454) + 0x16c))(param_1);
    if ((iVar5 == 0) &&
       (fVar2 = *(float *)(param_1 + 0x488),
       0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1))) {
      if (((bStack_c & 4) == 0) &&
         (iVar5 = UTIL_GetNextBestWeapon__FP11CBasePlayerP15CBasePlayerItem
                            (*(undefined4 *)(param_1 + 0x474),param_1), iVar5 != 0)) {
        *(undefined4 *)(param_1 + 0x488) = 0x3e99999a;
        return;
      }
    }
    else if (((*(int *)(param_1 + 0x4c0) == 0) && ((bStack_c & 2) == 0)) &&
            (fVar2 = *(float *)(param_1 + 0x488),
            0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1))) {
      pcVar6 = *(code **)(*(int *)(param_1 + 0x454) + 0x178);
      goto LAB_0013199b;
    }
  }
  else {
    if ((local_20 != 0) &&
       (iVar5 = (**(code **)(*(int *)(param_1 + 0x454) + 0x148))(param_1),
       piVar4[iVar5 + 0x23b] == 0)) {
      *(undefined4 *)(param_1 + 0x484) = 1;
    }
    (**(code **)(*(int *)(param_1 + 0x454) + 0x174))(param_1);
    pbVar1 = (byte *)(**(int **)(param_1 + 0x474) + 0x181);
    *pbVar1 = *pbVar1 & 0xf7;
LAB_00131978:
    iVar5 = (**(code **)(*(int *)(param_1 + 0x454) + 0x184))(param_1);
    if (iVar5 == 0) {
      return;
    }
  }
  pcVar6 = *(code **)(*(int *)(param_1 + 0x454) + 0x17c);
LAB_0013199b:
  (*pcVar6)(param_1);
  return;
}


// ItemPostFrame__15CBasePlayerItem  @ 0012667c
void ItemPostFrame__15CBasePlayerItem(void)

{
  return;
}


// ItemPostFrame__17CBasePlayerWeapon  @ 00123ef8
void ItemPostFrame__17CBasePlayerWeapon(int param_1)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  int *piVar7;
  int local_60;
  undefined1 local_5c [28];
  int local_40;
  undefined1 local_30 [8];
  int local_28;
  int local_14;
  byte bStack_c;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x118))(param_1,local_30);
  piVar7 = *(int **)(param_1 + 0xb0);
  if (piVar7 == (int *)0x0) {
    piVar6 = *(int **)(param_1 + 0x474);
    piVar7 = piVar6 + *(int *)(param_1 + 0x4b8) + 0x23b;
  }
  else {
    piVar6 = *(int **)(param_1 + 0x474);
  }
  if ((*(int *)(param_1 + 0x4b0) != 0) &&
     (fVar2 = (float)piVar6[0x196],
     (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x118))(param_1,local_5c);
    local_40 = local_40 - *(int *)(param_1 + 0x4c0);
    local_60 = *piVar7;
    if (local_40 < *piVar7) {
      local_60 = local_40;
    }
    *(int *)(param_1 + 0x4c0) = *(int *)(param_1 + 0x4c0) + local_60;
    *piVar7 = *piVar7 - local_60;
    *(undefined4 *)(param_1 + 0x4b0) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
    piVar6 = *(int **)(param_1 + 0x474);
  }
  if (((*(byte *)(*piVar6 + 0x180) & 1) != 0) &&
     (fVar2 = *(float *)(param_1 + 0x488),
     (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
    if (((*(int *)(param_1 + 0x4c0) == 0) && (local_28 != 0)) ||
       ((local_14 == -1 && (*piVar7 == 0)))) {
      *(undefined4 *)(param_1 + 0x484) = 1;
      piVar6 = *(int **)(param_1 + 0x474);
    }
    if (((piVar6[0x19] != 0) || (piVar6[0x75] != 0)) || (piVar6[0x76] != 0)) {
      Spy_RemoveDisguise__11CBasePlayer(piVar6);
      piVar6 = *(int **)(param_1 + 0x474);
    }
    fVar2 = *gpGlobals;
    if ((fVar2 < (float)piVar6[0x10d]) &&
       (fVar3 = (float)piVar6[0x114],
       0x3f < (byte)((fVar2 < fVar3 |
                      (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1))) {
      *(float *)(param_1 + 0x450) = fVar2 + 1.0;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*piVar6 + 0x208),3,"items/damage2.wav",0x3f800000,0x3f4ccccd,0,100)
      ;
    }
    pcVar5 = *(code **)(*(int *)(param_1 + 0x454) + 0x170);
LAB_001240d3:
    (*pcVar5)(param_1);
    FUN_00124190();
    return;
  }
  if ((((*(byte *)(*piVar6 + 0x181) & 0x20) != 0) && (local_14 != -1)) &&
     (*(int *)(param_1 + 0x4b0) == 0)) {
    pcVar5 = *(code **)(*(int *)(param_1 + 0x454) + 0x178);
    goto LAB_001240d3;
  }
  if ((*(uint *)(*piVar6 + 0x180) & 0x801) == 0) {
    *(undefined4 *)(param_1 + 0x484) = 0;
    iVar4 = (**(code **)(*(int *)(param_1 + 0x454) + 0x16c))(param_1);
    if ((iVar4 == 0) &&
       (fVar2 = *(float *)(param_1 + 0x488),
       0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1))) {
      if (((bStack_c & 4) == 0) &&
         (iVar4 = (**(code **)(*g_pGameRules + 0x1c))
                            (g_pGameRules,*(undefined4 *)(param_1 + 0x474),param_1), iVar4 != 0)) {
        *(undefined4 *)(param_1 + 0x488) = 0x3e99999a;
        return;
      }
    }
    else if (((*(int *)(param_1 + 0x4c0) == 0) && ((bStack_c & 2) == 0)) &&
            (fVar2 = *(float *)(param_1 + 0x488),
            0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1))) {
      pcVar5 = *(code **)(*(int *)(param_1 + 0x454) + 0x178);
      goto LAB_001241b3;
    }
  }
  else {
    iVar4 = (**(code **)(*(int *)(param_1 + 0x454) + 0x184))(param_1);
    if (iVar4 == 0) {
      return;
    }
  }
  pcVar5 = *(code **)(*(int *)(param_1 + 0x454) + 0x17c);
LAB_001241b3:
  (*pcVar5)(param_1);
  return;
}


