// EntSelectSpawnPoint__FP7edict_s  @ 000dc2c0
undefined4 EntSelectSpawnPoint__FP7edict_s(int param_1)

{
  float fVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  char *pcVar9;
  bool bVar10;
  
  iVar4 = param_1;
  if ((param_1 == 0) && (iVar4 = (*DAT_001755d4)(0), iVar4 == 0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0xd8);
  }
  if (*(int *)(iVar4 + 0x120) != 0) {
    piVar5 = (int *)FindTeamSpawnPoint__11CBaseEntity(iVar4);
    bVar10 = false;
    if (piVar5 == (int *)0x0) {
LAB_000dc332:
      bVar10 = true;
    }
    else {
      bVar3 = false;
      if ((*(int *)(*piVar5 + 0x1e8) == 0) ||
         (iVar4 = (*DAT_001755d8)(*(int *)(*piVar5 + 0x1e8)), iVar4 == 0)) {
        bVar3 = true;
      }
      if (bVar3) goto LAB_000dc332;
    }
    piVar8 = g_pLastSpawn;
    if (!bVar10) goto LAB_000dc6fd;
  }
  piVar5 = g_pLastSpawn;
  fVar1 = *(float *)(gpGlobals + 0x18);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = *(float *)(gpGlobals + 0x14);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      for (iVar4 = (*DAT_00175628)(1,5); 0 < iVar4; iVar4 = iVar4 + -1) {
        piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                  (piVar5,"info_player_deathmatch");
      }
      bVar10 = false;
      if (piVar5 == (int *)0x0) {
LAB_000dc475:
        bVar10 = true;
      }
      else {
        bVar3 = false;
        if ((*(int *)(*piVar5 + 0x1e8) == 0) ||
           (iVar4 = (*DAT_001755d8)(*(int *)(*piVar5 + 0x1e8)), iVar4 == 0)) {
          bVar3 = true;
        }
        if (bVar3) goto LAB_000dc475;
      }
      piVar8 = piVar5;
      if (bVar10) {
        piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                  (piVar5,"info_player_deathmatch");
        piVar8 = piVar5;
      }
      do {
        bVar10 = false;
        if (piVar5 == (int *)0x0) {
LAB_000dc4c0:
          bVar10 = true;
        }
        else {
          bVar3 = false;
          if ((*(int *)(*piVar5 + 0x1e8) == 0) ||
             (iVar4 = (*DAT_001755d8)(*(int *)(*piVar5 + 0x1e8)), iVar4 == 0)) {
            bVar3 = true;
          }
          if (bVar3) goto LAB_000dc4c0;
        }
        if ((!bVar10) && (iVar4 = IsSpawnPointValid__FR6Vector(*piVar5 + 8), iVar4 != 0)) {
          bVar10 = false;
          if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(*piVar5 + 8)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(*(float *)(*piVar5 + 8) == 0.0) << 0xe) >> 8)) == 0x40
              ) && (fVar1 = *(float *)(*piVar5 + 0xc),
                   (byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
            fVar1 = *(float *)(*piVar5 + 0x10);
            bVar10 = (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
          }
          if (!bVar10) goto LAB_000dc6c2;
        }
        piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                  (piVar5,"info_player_deathmatch");
      } while (piVar5 != piVar8);
      bVar10 = false;
      if (piVar5 == (int *)0x0) {
LAB_000dc580:
        bVar10 = true;
      }
      else {
        bVar3 = false;
        if ((*(int *)(*piVar5 + 0x1e8) == 0) ||
           (iVar4 = (*DAT_001755d8)(*(int *)(*piVar5 + 0x1e8)), iVar4 == 0)) {
          bVar3 = true;
        }
        if (bVar3) goto LAB_000dc580;
      }
      if (!bVar10) {
        piVar8 = (int *)0x0;
        while (piVar8 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                         (piVar8,*piVar5 + 8,0x43000000), piVar8 != (int *)0x0) {
          if (((*(byte *)(*piVar8 + 0x184) & 8) != 0) && (*(int *)(*piVar8 + 0x1e8) != param_1)) {
            iVar4 = piVar8[0xf2];
            iVar6 = (*DAT_001755e0)(0,0x43960000,0);
            if (iVar6 == 0) {
              iVar6 = 0;
            }
            else {
              iVar6 = iVar6 + 0xdc;
            }
            iVar6 = (*DAT_001755e0)(0,iVar6);
            if (iVar6 == 0) {
              iVar6 = 0;
            }
            else {
              iVar6 = iVar6 + 0xdc;
            }
            (**(code **)(iVar4 + 0x34))(piVar8,iVar6);
          }
        }
        goto LAB_000dc6c2;
      }
    }
LAB_000dc640:
    if (*(int *)(gpGlobals + 0x10) == 0) {
LAB_000dc664:
      piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"info_player_start");
    }
    else {
      iVar4 = -1;
      pcVar9 = (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(gpGlobals + 0x10));
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        cVar2 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar2 != '\0');
      if (iVar4 == -2) goto LAB_000dc664;
      piVar5 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc
                                (0,*(int *)(gpGlobals + 0x10) + *(int *)(gpGlobals + 0x98));
    }
    if ((piVar5 != (int *)0x0) && (*(int *)(*piVar5 + 0x1e8) != 0)) {
      (*DAT_001755d8)(*(int *)(*piVar5 + 0x1e8));
    }
  }
  else {
    piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(g_pLastSpawn,"info_player_coop");
    bVar10 = false;
    if (piVar5 == (int *)0x0) {
LAB_000dc39a:
      bVar10 = true;
    }
    else {
      bVar3 = false;
      if ((*(int *)(*piVar5 + 0x1e8) == 0) ||
         (iVar4 = (*DAT_001755d8)(*(int *)(*piVar5 + 0x1e8)), iVar4 == 0)) {
        bVar3 = true;
      }
      if (bVar3) goto LAB_000dc39a;
    }
    if (bVar10) {
      piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                (g_pLastSpawn,"info_player_start");
      bVar10 = false;
      if (piVar5 == (int *)0x0) {
LAB_000dc3e8:
        bVar10 = true;
      }
      else {
        bVar3 = false;
        if ((*(int *)(*piVar5 + 0x1e8) == 0) ||
           (iVar4 = (*DAT_001755d8)(*(int *)(*piVar5 + 0x1e8)), iVar4 == 0)) {
          bVar3 = true;
        }
        if (bVar3) goto LAB_000dc3e8;
      }
      if (bVar10) goto LAB_000dc640;
    }
  }
LAB_000dc6c2:
  bVar10 = false;
  if (piVar5 == (int *)0x0) {
LAB_000dc6ee:
    bVar10 = true;
  }
  else {
    bVar3 = false;
    if ((*(int *)(*piVar5 + 0x1e8) == 0) ||
       (iVar4 = (*DAT_001755d8)(*(int *)(*piVar5 + 0x1e8)), iVar4 == 0)) {
      bVar3 = true;
    }
    if (bVar3) goto LAB_000dc6ee;
  }
  piVar8 = piVar5;
  if (bVar10) {
    (*DAT_001755b4)(4,"PutClientInServer: no info_player_start on level");
    uVar7 = (*DAT_001755e0)(0);
    return uVar7;
  }
LAB_000dc6fd:
  g_pLastSpawn = piVar8;
  return *(undefined4 *)(*piVar5 + 0x1e8);
}


