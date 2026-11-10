// EntSelectSpawnPoint__FP7edict_s  @ 000da010
undefined4 EntSelectSpawnPoint__FP7edict_s(int param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  char *pcVar11;
  bool bVar12;
  
  iVar5 = param_1;
  if ((param_1 == 0) && (iVar5 = (*DAT_001c1134)(0), iVar5 == 0)) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(iVar5 + 0x7c);
  }
  if (*(int *)(iVar5 + 0x120) != 0) {
    piVar6 = (int *)FindTeamSpawnPoint__11CBaseEntity(iVar5);
    bVar12 = false;
    if (piVar6 == (int *)0x0) {
LAB_000da095:
      bVar12 = true;
    }
    else {
      bVar4 = false;
      if ((*(int *)(*piVar6 + 0x208) == 0) ||
         (iVar5 = (*DAT_001c1138)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
        bVar4 = true;
      }
      if (bVar4) goto LAB_000da095;
    }
    piVar10 = g_pLastSpawn;
    if (!bVar12) goto LAB_000da508;
  }
  piVar6 = g_pLastSpawn;
  fVar1 = *(float *)(gpGlobals + 0x18);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = *(float *)(gpGlobals + 0x14);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
code_r0x000da44c:
      if (*(int *)(gpGlobals + 0x10) == 0) {
LAB_000da472:
        piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"info_player_start");
      }
      else {
        iVar5 = -1;
        pcVar11 = (char *)(*(int *)(gpGlobals + 0x98) + *(int *)(gpGlobals + 0x10));
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          cVar2 = *pcVar11;
          pcVar11 = pcVar11 + 1;
        } while (cVar2 != '\0');
        if (iVar5 == -2) goto LAB_000da472;
        piVar6 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc
                                  (0,*(int *)(gpGlobals + 0x10) + *(int *)(gpGlobals + 0x98));
      }
      if ((piVar6 != (int *)0x0) && (*(int *)(*piVar6 + 0x208) != 0)) {
        (*DAT_001c1138)(*(int *)(*piVar6 + 0x208));
      }
    }
    else {
      iVar5 = (*DAT_001c1188)(1,5);
      if (0 < iVar5) {
        uVar9 = -iVar5 & 3;
        if (uVar9 != 0) {
          if (uVar9 < 3) {
            if (uVar9 < 2) {
              piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                        (piVar6,"info_player_deathmatch");
              iVar5 = iVar5 + -1;
            }
            piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                      (piVar6,"info_player_deathmatch");
            iVar5 = iVar5 + -1;
          }
          piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                    (piVar6,"info_player_deathmatch");
          iVar5 = iVar5 + -1;
          if (iVar5 < 1) goto LAB_000da251;
        }
        do {
          uVar7 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,"info_player_deathmatch");
          uVar7 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(uVar7,"info_player_deathmatch");
          uVar7 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(uVar7,"info_player_deathmatch");
          piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                    (uVar7,"info_player_deathmatch");
          iVar5 = iVar5 + -4;
        } while (0 < iVar5);
      }
LAB_000da251:
      bVar12 = false;
      if (piVar6 == (int *)0x0) {
LAB_000da284:
        bVar12 = true;
      }
      else {
        bVar4 = false;
        if ((*(int *)(*piVar6 + 0x208) == 0) ||
           (iVar5 = (*DAT_001c1138)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
          bVar4 = true;
        }
        if (bVar4) goto LAB_000da284;
      }
      piVar10 = piVar6;
      if (bVar12) {
        piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                  (piVar6,"info_player_deathmatch");
        piVar10 = piVar6;
      }
      do {
        bVar12 = false;
        if (piVar6 == (int *)0x0) {
LAB_000da2d7:
          bVar12 = true;
        }
        else {
          bVar4 = false;
          if ((*(int *)(*piVar6 + 0x208) == 0) ||
             (iVar5 = (*DAT_001c1138)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
            bVar4 = true;
          }
          if (bVar4) goto LAB_000da2d7;
        }
        if ((!bVar12) && (iVar5 = IsSpawnPointValid__FR6Vector(*piVar6 + 8), iVar5 != 0)) {
          bVar12 = false;
          if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(*piVar6 + 8)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(*(float *)(*piVar6 + 8) == 0.0) << 0xe) >> 8)) == 0x40
              ) && (fVar1 = *(float *)(*piVar6 + 0xc),
                   (byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                         (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
            fVar1 = *(float *)(*piVar6 + 0x10);
            bVar12 = (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
          }
          if (!bVar12) goto LAB_000da4c4;
        }
        piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                  (piVar6,"info_player_deathmatch");
      } while (piVar6 != piVar10);
      bVar12 = false;
      if (piVar6 == (int *)0x0) {
LAB_000da3a8:
        bVar12 = true;
      }
      else {
        bVar4 = false;
        if ((*(int *)(*piVar6 + 0x208) == 0) ||
           (iVar5 = (*DAT_001c1138)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
          bVar4 = true;
        }
        if (bVar4) goto LAB_000da3a8;
      }
      if (bVar12) goto code_r0x000da44c;
      piVar10 = (int *)0x0;
      while (piVar10 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                        (piVar10,*piVar6 + 8,0x43000000), piVar10 != (int *)0x0) {
        if (((*(byte *)(*piVar10 + 0x1a4) & 8) != 0) && (*(int *)(*piVar10 + 0x208) != param_1)) {
          iVar3 = piVar10[0x111];
          iVar8 = (*DAT_001c1140)(0,0x43960000,0);
          iVar5 = iVar8 + 0x80;
          if (iVar8 == 0) {
            iVar5 = 0;
          }
          iVar8 = (*DAT_001c1140)(0,iVar5);
          iVar5 = iVar8 + 0x80;
          if (iVar8 == 0) {
            iVar5 = 0;
          }
          (**(code **)(iVar3 + 0x38))(piVar10,iVar5);
        }
      }
    }
  }
  else {
    piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(g_pLastSpawn,"info_player_coop");
    bVar12 = false;
    if (piVar6 == (int *)0x0) {
LAB_000da110:
      bVar12 = true;
    }
    else {
      bVar4 = false;
      if ((*(int *)(*piVar6 + 0x208) == 0) ||
         (iVar5 = (*DAT_001c1138)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
        bVar4 = true;
      }
      if (bVar4) goto LAB_000da110;
    }
    if (bVar12) {
      piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                (g_pLastSpawn,"info_player_start");
      bVar12 = false;
      if (piVar6 == (int *)0x0) {
LAB_000da16a:
        bVar12 = true;
      }
      else {
        bVar4 = false;
        if ((*(int *)(*piVar6 + 0x208) == 0) ||
           (iVar5 = (*DAT_001c1138)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
          bVar4 = true;
        }
        if (bVar4) goto LAB_000da16a;
      }
      if (bVar12) {
        uVar7 = FUN_000da44c();
        return uVar7;
      }
    }
  }
LAB_000da4c4:
  bVar12 = false;
  if (piVar6 == (int *)0x0) {
LAB_000da4f7:
    bVar12 = true;
  }
  else {
    bVar4 = false;
    if ((*(int *)(*piVar6 + 0x208) == 0) ||
       (iVar5 = (*DAT_001c1138)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
      bVar4 = true;
    }
    if (bVar4) goto LAB_000da4f7;
  }
  piVar10 = piVar6;
  if (bVar12) {
    (*DAT_001c1114)(4,"PutClientInServer: no info_player_start on level");
    uVar7 = (*DAT_001c1140)(0);
    return uVar7;
  }
LAB_000da508:
  g_pLastSpawn = piVar10;
  return *(undefined4 *)(*piVar6 + 0x208);
}


