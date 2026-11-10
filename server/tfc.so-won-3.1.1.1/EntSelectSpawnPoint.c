// EntSelectSpawnPoint__FP7edict_s  @ 000d9860
undefined4 EntSelectSpawnPoint__FP7edict_s(int param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint *puVar10;
  int *piVar11;
  uint uVar12;
  int *piVar13;
  bool bVar14;
  
  iVar5 = param_1;
  if ((param_1 == 0) && (iVar5 = (*DAT_0019f7b4)(0), iVar5 == 0)) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(iVar5 + 0x7c);
  }
  if (*(int *)(iVar5 + 0x120) != 0) {
    piVar6 = (int *)FindTeamSpawnPoint__11CBaseEntity(iVar5);
    bVar14 = false;
    if (piVar6 == (int *)0x0) {
LAB_000d98ea:
      bVar14 = true;
    }
    else {
      bVar3 = false;
      if ((*(int *)(*piVar6 + 0x208) == 0) ||
         (iVar5 = (*DAT_0019f7b8)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
        bVar3 = true;
      }
      if (bVar3) goto LAB_000d98ea;
    }
    piVar13 = g_pLastSpawn;
    if (!bVar14) goto LAB_000d9d4c;
  }
  piVar6 = g_pLastSpawn;
  fVar1 = *(float *)(gpGlobals + 0x18);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    fVar1 = *(float *)(gpGlobals + 0x14);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      for (iVar5 = (*DAT_0019f808)(1,5); 0 < iVar5; iVar5 = iVar5 + -1) {
        piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                  (piVar6,"info_player_deathmatch");
      }
      bVar14 = false;
      if (piVar6 == (int *)0x0) {
LAB_000d9a6f:
        bVar14 = true;
      }
      else {
        bVar3 = false;
        if ((*(int *)(*piVar6 + 0x208) == 0) ||
           (iVar5 = (*DAT_0019f7b8)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
          bVar3 = true;
        }
        if (bVar3) goto LAB_000d9a6f;
      }
      piVar13 = piVar6;
      if (bVar14) {
        piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                  (piVar6,"info_player_deathmatch");
        piVar13 = piVar6;
      }
      do {
        bVar14 = false;
        if (piVar6 == (int *)0x0) {
LAB_000d9acc:
          bVar14 = true;
        }
        else {
          bVar3 = false;
          if ((*(int *)(*piVar6 + 0x208) == 0) ||
             (iVar5 = (*DAT_0019f7b8)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
            bVar3 = true;
          }
          if (bVar3) goto LAB_000d9acc;
        }
        if (!bVar14) {
          iVar5 = *piVar6;
          piVar11 = (int *)0x0;
          do {
            piVar11 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                       (piVar11,iVar5 + 8,0x42c00000);
            if (piVar11 == (int *)0x0) {
              bVar14 = false;
              if (((byte)((byte)((ushort)((ushort)NAN(*(float *)(*piVar6 + 8)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(*(float *)(*piVar6 + 8) == 0.0) << 0xe) >> 8)) ==
                   0x40) &&
                 (fVar1 = *(float *)(*piVar6 + 0xc),
                 (byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40)) {
                fVar1 = *(float *)(*piVar6 + 0x10);
                bVar14 = (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
              }
              if (!bVar14) goto LAB_000d9cff;
              break;
            }
          } while ((*(byte *)(*piVar11 + 0x1a4) & 8) == 0);
        }
        piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                  (piVar6,"info_player_deathmatch");
      } while (piVar6 != piVar13);
      bVar14 = false;
      if (piVar6 == (int *)0x0) {
LAB_000d9bb7:
        bVar14 = true;
      }
      else {
        bVar3 = false;
        if ((*(int *)(*piVar6 + 0x208) == 0) ||
           (iVar5 = (*DAT_0019f7b8)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
          bVar3 = true;
        }
        if (bVar3) goto LAB_000d9bb7;
      }
      if (!bVar14) {
        piVar13 = (int *)0x0;
        while (piVar13 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                          (piVar13,*piVar6 + 8,0x43000000), piVar13 != (int *)0x0) {
          if (((*(byte *)(*piVar13 + 0x1a4) & 8) != 0) && (*(int *)(*piVar13 + 0x208) != param_1)) {
            iVar2 = piVar13[0x115];
            iVar7 = (*DAT_0019f7c0)(0,0x43960000,0);
            iVar5 = iVar7 + 0x80;
            if (iVar7 == 0) {
              iVar5 = 0;
            }
            iVar7 = (*DAT_0019f7c0)(0,iVar5);
            iVar5 = iVar7 + 0x80;
            if (iVar7 == 0) {
              iVar5 = 0;
            }
            (**(code **)(iVar2 + 0x38))(piVar13,iVar5);
          }
        }
        goto LAB_000d9cff;
      }
    }
LAB_000d9c64:
    if (*(int *)(gpGlobals + 0x10) == 0) {
LAB_000d9cc0:
      piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"info_player_start");
    }
    else {
      puVar10 = (uint *)(*(int *)(gpGlobals + 0x98) + *(int *)(gpGlobals + 0x10));
      uVar12 = (uint)puVar10 & 3;
      puVar4 = puVar10;
      if (uVar12 == 0) {
LAB_000d9c9a:
        do {
          puVar8 = puVar4;
          uVar12 = *puVar8;
          if ((char)uVar12 == '\0') goto LAB_000d9cbc;
          if ((char)(uVar12 >> 8) == '\0') goto LAB_000d9cbb;
          if ((uVar12 & 0xff0000) == 0) goto LAB_000d9cba;
          puVar4 = puVar8 + 1;
        } while ((uVar12 & 0xff000000) != 0);
        puVar8 = (uint *)((int)puVar8 + 1);
LAB_000d9cba:
        puVar8 = (uint *)((int)puVar8 + 1);
LAB_000d9cbb:
        puVar8 = (uint *)((int)puVar8 + 1);
      }
      else {
        puVar8 = puVar10;
        if ((POPCOUNT(uVar12) & 1U) == 0) {
LAB_000d9c95:
          if ((char)*puVar8 != '\0') {
            puVar4 = (uint *)((int)puVar8 + 1);
            goto LAB_000d9c9a;
          }
        }
        else if (uVar12 == 2) {
LAB_000d9c90:
          if ((char)*puVar8 != '\0') {
            puVar8 = (uint *)((int)puVar8 + 1);
            goto LAB_000d9c95;
          }
        }
        else if ((char)*puVar10 != '\0') {
          puVar8 = (uint *)((int)puVar10 + 1);
          goto LAB_000d9c90;
        }
      }
LAB_000d9cbc:
      if (puVar8 == puVar10) goto LAB_000d9cc0;
      piVar6 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc(0,puVar10);
    }
    if ((piVar6 != (int *)0x0) && (*(int *)(*piVar6 + 0x208) != 0)) {
      (*DAT_0019f7b8)(*(int *)(*piVar6 + 0x208));
    }
  }
  else {
    piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(g_pLastSpawn,"info_player_coop");
    bVar14 = false;
    if (piVar6 == (int *)0x0) {
LAB_000d996c:
      bVar14 = true;
    }
    else {
      bVar3 = false;
      if ((*(int *)(*piVar6 + 0x208) == 0) ||
         (iVar5 = (*DAT_0019f7b8)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
        bVar3 = true;
      }
      if (bVar3) goto LAB_000d996c;
    }
    if (bVar14) {
      piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc
                                (g_pLastSpawn,"info_player_start");
      bVar14 = false;
      if (piVar6 == (int *)0x0) {
LAB_000d99cf:
        bVar14 = true;
      }
      else {
        bVar3 = false;
        if ((*(int *)(*piVar6 + 0x208) == 0) ||
           (iVar5 = (*DAT_0019f7b8)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
          bVar3 = true;
        }
        if (bVar3) goto LAB_000d99cf;
      }
      if (bVar14) goto LAB_000d9c64;
    }
  }
LAB_000d9cff:
  bVar14 = false;
  if (piVar6 == (int *)0x0) {
LAB_000d9d37:
    bVar14 = true;
  }
  else {
    bVar3 = false;
    if ((*(int *)(*piVar6 + 0x208) == 0) ||
       (iVar5 = (*DAT_0019f7b8)(*(int *)(*piVar6 + 0x208)), iVar5 == 0)) {
      bVar3 = true;
    }
    if (bVar3) goto LAB_000d9d37;
  }
  piVar13 = piVar6;
  if (bVar14) {
    (*DAT_0019f794)(4,"PutClientInServer: no info_player_start on level");
    uVar9 = (*DAT_0019f7c0)(0);
    return uVar9;
  }
LAB_000d9d4c:
  g_pLastSpawn = piVar13;
  return *(undefined4 *)(*piVar6 + 0x208);
}


