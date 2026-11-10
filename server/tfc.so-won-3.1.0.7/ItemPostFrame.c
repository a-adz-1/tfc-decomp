// ItemPostFrame__11CBasePlayer  @ 000dc6d4
void ItemPostFrame__11CBasePlayer(int param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x864);
  if (iVar2 == 0) {
    fVar1 = *(float *)(param_1 + 0x648);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      (**(code **)(*(int *)(param_1 + 0x444) + 0x22c))(param_1);
      if (*(int *)(param_1 + 0x8b4) != 0) {
        (**(code **)(*(int *)(*(int *)(param_1 + 0x8b4) + 0x444) + 0x134))
                  (*(int *)(param_1 + 0x8b4));
      }
    }
  }
  return;
}


// ItemPostFrame__14CTFSniperRifle  @ 0012d610
void ItemPostFrame__14CTFSniperRifle(int param_1)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  undefined1 local_2c [16];
  int local_1c;
  byte local_8;
  
  (**(code **)(*(int *)(param_1 + 0x444) + 0x118))(param_1,local_2c);
  piVar4 = *(int **)(param_1 + 0x464);
  if (((*(byte *)(*piVar4 + 0x181) & 8) == 0) ||
     (fVar2 = *(float *)(param_1 + 0x47c),
     (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1)) {
    iVar5 = *(int *)(param_1 + 0x464);
    if (((*(byte *)(iVar5 + 0x6b8) & 1) != 0) &&
       (fVar2 = *(float *)(param_1 + 0x478),
       (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
      if ((*(byte *)(iVar5 + 0x85) & 8) != 0) {
        *(byte *)(iVar5 + 0x85) = *(byte *)(iVar5 + 0x85) & 0xf7;
        TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x464));
        if ((*(byte *)(**(int **)(param_1 + 0x464) + 0x1a5) & 2) == 0) {
          ClientPrint__FP9entvars_siPCcN42
                    (**(undefined4 **)(param_1 + 0x464),4,"#Sniper_cantfire",0,0,0,0);
        }
        else {
          (**(code **)(*(int *)(param_1 + 0x444) + 0x170))(param_1);
        }
        *(undefined4 *)(param_1 + 0x4c4) = 0;
        if (*(int *)(param_1 + 0x4c0) != 0) {
          (**(code **)(*(int *)(*(int *)(param_1 + 0x4c0) + 0x444) + 0x40))
                    (*(int *)(param_1 + 0x4c0),0,0,1);
        }
        *(undefined4 *)(param_1 + 0x4c0) = 0;
        *(undefined4 *)(param_1 + 0x490) = 0;
      }
      goto LAB_0012d980;
    }
    if (((*(byte *)(**(int **)(param_1 + 0x464) + 0x180) & 1) != 0) &&
       (fVar2 = *(float *)(param_1 + 0x478),
       (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
      if ((*(byte *)((int)*(int **)(param_1 + 0x464) + 0x85) & 8) == 0) {
        iVar5 = **(int **)(param_1 + 0x464);
        fVar2 = *(float *)(iVar5 + 0x20);
        fVar3 = *(float *)(iVar5 + 0x24);
        fVar2 = SQRT(fVar3 * fVar3 + fVar2 * fVar2);
        if ((byte)(50.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 50.0) << 0xe) >> 8)) != 1) {
          *(undefined4 *)(param_1 + 0x490) = 0x42480000;
          *(undefined4 *)(param_1 + 0x4c4) = 1;
          *(undefined4 *)(param_1 + 0x494) = 0;
          pbVar1 = (byte *)((int)*(int **)(param_1 + 0x464) + 0x85);
          *pbVar1 = *pbVar1 | 8;
          TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x464));
          (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,1,1);
          *(undefined4 *)(param_1 + 0x480) = 0x447a0000;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x4c4) = 1;
        fVar2 = *(float *)(param_1 + 0x490);
        if (0x3f < (byte)((400.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 400.0) << 0xe) >> 8)) - 1)) {
          *(float *)(param_1 + 0x490) =
               -*(float *)(param_1 + 0x494) * 50.0 + *(float *)(param_1 + 0x490);
          *(undefined4 *)(param_1 + 0x494) = 0;
        }
        UpdateSpot__14CTFSniperRifle(param_1);
      }
      goto LAB_0012d980;
    }
    if ((*(uint *)(**(int **)(param_1 + 0x464) + 0x180) & 0x801) != 0) goto LAB_0012d980;
    *(undefined4 *)(param_1 + 0x474) = 0;
    iVar5 = (**(code **)(*(int *)(param_1 + 0x444) + 0x16c))(param_1);
    if ((iVar5 == 0) &&
       (fVar2 = *(float *)(param_1 + 0x478),
       0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1))) {
      if (((local_8 & 4) == 0) &&
         (iVar5 = UTIL_GetNextBestWeapon__FP11CBasePlayerP15CBasePlayerItem
                            (*(undefined4 *)(param_1 + 0x464),param_1), iVar5 != 0)) {
        *(undefined4 *)(param_1 + 0x478) = 0x3e99999a;
        return;
      }
    }
    else if (((*(int *)(param_1 + 0x4b0) == 0) && ((local_8 & 2) == 0)) &&
            (fVar2 = *(float *)(param_1 + 0x478),
            0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1))) {
      pcVar6 = *(code **)(*(int *)(param_1 + 0x444) + 0x178);
      goto LAB_0012d9a3;
    }
  }
  else {
    if ((local_1c != 0) &&
       (iVar5 = (**(code **)(*(int *)(param_1 + 0x444) + 0x148))(param_1),
       piVar4[iVar5 + 0x231] == 0)) {
      *(undefined4 *)(param_1 + 0x474) = 1;
    }
    (**(code **)(*(int *)(param_1 + 0x444) + 0x174))(param_1);
    pbVar1 = (byte *)(**(int **)(param_1 + 0x464) + 0x181);
    *pbVar1 = *pbVar1 & 0xf7;
LAB_0012d980:
    iVar5 = (**(code **)(*(int *)(param_1 + 0x444) + 0x184))(param_1);
    if (iVar5 == 0) {
      return;
    }
  }
  pcVar6 = *(code **)(*(int *)(param_1 + 0x444) + 0x17c);
LAB_0012d9a3:
  (*pcVar6)(param_1);
  return;
}


// ItemPostFrame__15CBasePlayerItem  @ 00121fec
void ItemPostFrame__15CBasePlayerItem(void)

{
  return;
}


// ItemPostFrame__17CBasePlayerWeapon  @ 0011fe58
void ItemPostFrame__17CBasePlayerWeapon(int param_1)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  undefined1 local_58 [28];
  int local_3c;
  undefined1 local_2c [8];
  int local_24;
  int local_10;
  byte bStack_8;
  
  (**(code **)(*(int *)(param_1 + 0x444) + 0x118))(param_1,local_2c);
  if (*(int *)(param_1 + 0xb0) == 0) {
    piVar6 = (int *)(*(int *)(param_1 + 0x464) + 0x8c4 + *(int *)(param_1 + 0x4a8) * 4);
  }
  else {
    piVar6 = *(int **)(param_1 + 0xb0);
  }
  if ((*(int *)(param_1 + 0x4a0) != 0) &&
     (fVar2 = *(float *)(*(int *)(param_1 + 0x464) + 0x648),
     (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
    (**(code **)(*(int *)(param_1 + 0x444) + 0x118))(param_1,local_58);
    local_3c = local_3c - *(int *)(param_1 + 0x4b0);
    iVar4 = *piVar6;
    if (local_3c < *piVar6) {
      iVar4 = local_3c;
    }
    *(int *)(param_1 + 0x4b0) = *(int *)(param_1 + 0x4b0) + iVar4;
    *piVar6 = *piVar6 - iVar4;
    *(undefined4 *)(param_1 + 0x4a0) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x464) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
  }
  if (((*(byte *)(**(int **)(param_1 + 0x464) + 0x180) & 1) != 0) &&
     (fVar2 = *(float *)(param_1 + 0x478),
     (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
    if (((*(int *)(param_1 + 0x4b0) == 0) && (local_24 != 0)) ||
       ((local_10 == -1 && (*piVar6 == 0)))) {
      *(undefined4 *)(param_1 + 0x474) = 1;
    }
    iVar4 = *(int *)(param_1 + 0x464);
    if (((*(int *)(iVar4 + 100) != 0) || (*(int *)(iVar4 + 0x1d4) != 0)) ||
       (*(int *)(iVar4 + 0x1d8) != 0)) {
      Spy_RemoveDisguise__11CBasePlayer(*(undefined4 *)(param_1 + 0x464));
    }
    piVar6 = *(int **)(param_1 + 0x464);
    fVar2 = (float)piVar6[0x109];
    fVar3 = *gpGlobals;
    if ((0x3f < (byte)((fVar2 < fVar3 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) &&
       ((float)piVar6[0x110] < *gpGlobals)) {
      *(float *)(param_1 + 0x440) = *gpGlobals + 1.0;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*piVar6 + 0x208),3,"items/damage2.wav",0x3f800000,0x3f4ccccd,0,100)
      ;
    }
    pcVar5 = *(code **)(*(int *)(param_1 + 0x444) + 0x170);
LAB_0012004a:
    (*pcVar5)(param_1);
    FUN_00120110();
    return;
  }
  if ((((*(byte *)(**(int **)(param_1 + 0x464) + 0x181) & 0x20) != 0) && (local_10 != -1)) &&
     (*(int *)(param_1 + 0x4a0) == 0)) {
    pcVar5 = *(code **)(*(int *)(param_1 + 0x444) + 0x178);
    goto LAB_0012004a;
  }
  if ((*(uint *)(**(int **)(param_1 + 0x464) + 0x180) & 0x801) == 0) {
    *(undefined4 *)(param_1 + 0x474) = 0;
    iVar4 = (**(code **)(*(int *)(param_1 + 0x444) + 0x16c))(param_1);
    if ((iVar4 == 0) &&
       (fVar2 = *(float *)(param_1 + 0x478),
       0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1))) {
      if (((bStack_8 & 4) == 0) &&
         (iVar4 = (**(code **)(*g_pGameRules + 0x1c))
                            (g_pGameRules,*(undefined4 *)(param_1 + 0x464),param_1), iVar4 != 0)) {
        *(undefined4 *)(param_1 + 0x478) = 0x3e99999a;
        return;
      }
    }
    else if (((*(int *)(param_1 + 0x4b0) == 0) && ((bStack_8 & 2) == 0)) &&
            (fVar2 = *(float *)(param_1 + 0x478),
            0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1))) {
      pcVar5 = *(code **)(*(int *)(param_1 + 0x444) + 0x178);
      goto LAB_00120133;
    }
  }
  else {
    iVar4 = (**(code **)(*(int *)(param_1 + 0x444) + 0x184))(param_1);
    if (iVar4 == 0) {
      return;
    }
  }
  pcVar5 = *(code **)(*(int *)(param_1 + 0x444) + 0x17c);
LAB_00120133:
  (*pcVar5)(param_1);
  return;
}


