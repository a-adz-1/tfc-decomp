// ItemPostFrame__11CBasePlayer  @ 000de3d0
void ItemPostFrame__11CBasePlayer(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x7e0);
  if (iVar3 == 0) {
    fVar1 = *gpGlobals;
    fVar2 = *(float *)(param_1 + 0x5cc);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x224))(param_1);
      if (*(int *)(param_1 + 0x830) != 0) {
        (**(code **)(*(int *)(*(int *)(param_1 + 0x830) + 0x3c8) + 300))(*(int *)(param_1 + 0x830));
      }
    }
  }
  return;
}


// ItemPostFrame__14CTFSniperRifle  @ 001035a0
void ItemPostFrame__14CTFSniperRifle(int param_1)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  float *pfVar5;
  int iVar6;
  code *pcVar7;
  undefined1 local_30 [16];
  int local_20;
  byte bStack_c;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x110))(param_1,local_30);
  pfVar5 = gpGlobals;
  piVar4 = *(int **)(param_1 + 1000);
  if ((*(byte *)(*piVar4 + 0x161) & 8) == 0) {
LAB_00103650:
    iVar6 = *(int *)(param_1 + 1000);
    if ((*(byte *)(iVar6 + 0x638) & 1) != 0) {
      fVar2 = *(float *)(param_1 + 0x3fc);
      fVar3 = *gpGlobals;
      if ((byte)((fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1) < 0x40) {
        if ((*(byte *)(iVar6 + 0x89) & 8) != 0) {
          *(byte *)(iVar6 + 0x89) = *(byte *)(iVar6 + 0x89) & 0xf7;
          TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 1000));
          if ((*(byte *)(**(int **)(param_1 + 1000) + 0x185) & 2) != 0) {
            (**(code **)(*(int *)(param_1 + 0x3c8) + 0x164))(param_1);
            FUN_001036f0();
            return;
          }
          ClientPrint__FP9entvars_tiPCcN42
                    (**(undefined4 **)(param_1 + 1000),4,"#Sniper_cantfire",0,0,0,0);
          *(undefined4 *)(param_1 + 0x434) = 0;
          if (*(int *)(param_1 + 0x430) != 0) {
            (**(code **)(*(int *)(*(int *)(param_1 + 0x430) + 0x3c8) + 0x3c))
                      (*(int *)(param_1 + 0x430),0,1);
          }
          *(undefined4 *)(param_1 + 0x430) = 0;
        }
        goto LAB_00103950;
      }
    }
    if ((*(byte *)(**(int **)(param_1 + 1000) + 0x160) & 1) != 0) {
      fVar2 = *(float *)(param_1 + 0x3fc);
      fVar3 = *gpGlobals;
      if ((byte)((fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1) < 0x40) {
        if ((*(byte *)((int)*(int **)(param_1 + 1000) + 0x89) & 8) == 0) {
          iVar6 = **(int **)(param_1 + 1000);
          fVar2 = *(float *)(iVar6 + 0x20);
          fVar3 = *(float *)(iVar6 + 0x24);
          if (SQRT(fVar3 * fVar3 + fVar2 * fVar2 + 0.0) <= 50.0) {
            *(undefined4 *)(param_1 + 0x424) = 0x42480000;
            *(undefined4 *)(param_1 + 0x434) = 1;
            *(float *)(param_1 + 0x428) = *gpGlobals;
            pbVar1 = (byte *)((int)*(int **)(param_1 + 1000) + 0x89);
            *pbVar1 = *pbVar1 | 8;
            TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 1000));
            (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,1);
            *(float *)(param_1 + 0x404) = *gpGlobals + 99999.0;
          }
        }
        else {
          if (*(float *)(param_1 + 0x424) < 400.0) {
            *(float *)(param_1 + 0x424) =
                 (*gpGlobals - *(float *)(param_1 + 0x428)) * 50.0 + *(float *)(param_1 + 0x424);
            *(float *)(param_1 + 0x428) = *pfVar5;
          }
          UpdateSpot__14CTFSniperRifle(param_1);
        }
        goto LAB_00103950;
      }
    }
    if ((*(uint *)(**(int **)(param_1 + 1000) + 0x160) & 0x801) != 0) goto LAB_00103950;
    *(undefined4 *)(param_1 + 0x3f8) = 0;
    iVar6 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x160))(param_1);
    if (iVar6 == 0) {
      fVar2 = *(float *)(param_1 + 0x3fc);
      fVar3 = *gpGlobals;
      if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 1) goto LAB_00103910;
      if (((bStack_c & 4) == 0) &&
         (iVar6 = (**(code **)(*g_pGameRules + 0x1c))
                            (g_pGameRules,*(undefined4 *)(param_1 + 1000),param_1), iVar6 != 0)) {
        *(float *)(param_1 + 0x3fc) = *gpGlobals + 0.3;
        return;
      }
    }
    else {
LAB_00103910:
      if ((*(int *)(param_1 + 0x410) == 0) && ((bStack_c & 2) == 0)) {
        fVar2 = *(float *)(param_1 + 0x3fc);
        fVar3 = *gpGlobals;
        if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) {
          pcVar7 = *(code **)(*(int *)(param_1 + 0x3c8) + 0x16c);
          goto LAB_00103973;
        }
      }
    }
  }
  else {
    fVar2 = *(float *)(param_1 + 0x400);
    fVar3 = *gpGlobals;
    if (0x3f < (byte)((fVar2 < fVar3 |
                       (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1))
    goto LAB_00103650;
    if ((local_20 != 0) &&
       (iVar6 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x140))(param_1),
       piVar4[iVar6 + 0x20f] == 0)) {
      *(undefined4 *)(param_1 + 0x3f8) = 1;
    }
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x168))(param_1);
    pbVar1 = (byte *)(**(int **)(param_1 + 1000) + 0x161);
    *pbVar1 = *pbVar1 & 0xf7;
LAB_00103950:
    iVar6 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x178))(param_1);
    if (iVar6 == 0) {
      return;
    }
  }
  pcVar7 = *(code **)(*(int *)(param_1 + 0x3c8) + 0x170);
LAB_00103973:
  (*pcVar7)(param_1);
  return;
}


// ItemPostFrame__15CBasePlayerItem  @ 0011cc10
void ItemPostFrame__15CBasePlayerItem(void)

{
  return;
}


// ItemPostFrame__17CBasePlayerWeapon  @ 0011b030
void ItemPostFrame__17CBasePlayerWeapon(int param_1)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  undefined1 local_5c [28];
  int local_40;
  undefined1 local_30 [8];
  int local_28;
  int local_14;
  byte local_c;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x110))(param_1,local_30);
  if (*(int *)(param_1 + 0xb0) == 0) {
    piVar6 = (int *)(*(int *)(param_1 + 1000) + 0x83c + *(int *)(param_1 + 0x408) * 4);
  }
  else {
    piVar6 = *(int **)(param_1 + 0xb0);
  }
  if (*(int *)(param_1 + 0x41c) != 0) {
    fVar2 = *(float *)(*(int *)(param_1 + 1000) + 0x5cc);
    fVar3 = *gpGlobals;
    if ((byte)((fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1) < 0x40) {
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x110))(param_1,local_5c);
      local_40 = local_40 - *(int *)(param_1 + 0x410);
      iVar4 = *piVar6;
      if (local_40 < *piVar6) {
        iVar4 = local_40;
      }
      *(int *)(param_1 + 0x410) = *(int *)(param_1 + 0x410) + iVar4;
      *piVar6 = *piVar6 - iVar4;
      *(undefined4 *)(param_1 + 0x41c) = 0;
      pbVar1 = (byte *)(*(int *)(param_1 + 1000) + 0x88);
      *pbVar1 = *pbVar1 & 0xfd;
    }
  }
  if ((*(byte *)(**(int **)(param_1 + 1000) + 0x160) & 1) != 0) {
    fVar2 = *(float *)(param_1 + 0x3fc);
    fVar3 = *gpGlobals;
    if ((byte)((fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1) < 0x40) {
      if (((*(int *)(param_1 + 0x410) == 0) && (local_28 != 0)) ||
         ((local_14 == -1 && (*piVar6 == 0)))) {
        *(undefined4 *)(param_1 + 0x3f8) = 1;
      }
      iVar4 = *(int *)(param_1 + 1000);
      if (((*(int *)(iVar4 + 0x68) != 0) || (*(int *)(iVar4 + 0x1d4) != 0)) ||
         (*(int *)(iVar4 + 0x1d8) != 0)) {
        Spy_RemoveDisguise__11CBasePlayer(*(undefined4 *)(param_1 + 1000));
      }
      piVar6 = *(int **)(param_1 + 1000);
      if (*gpGlobals < (float)piVar6[0xea]) {
        fVar2 = (float)piVar6[0xf1];
        fVar3 = *gpGlobals;
        if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) {
          *(float *)(param_1 + 0x3c4) = *gpGlobals + 1.0;
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(*piVar6 + 0x1e8),3,"items/damage2.wav",0x3f800000,0x3f4ccccd,0,
                     100);
        }
      }
      pcVar5 = *(code **)(*(int *)(param_1 + 0x3c8) + 0x164);
      goto LAB_0011b21d;
    }
  }
  if ((((*(byte *)(**(int **)(param_1 + 1000) + 0x161) & 0x20) != 0) && (local_14 != -1)) &&
     (*(int *)(param_1 + 0x41c) == 0)) {
    pcVar5 = *(code **)(*(int *)(param_1 + 0x3c8) + 0x16c);
LAB_0011b21d:
    (*pcVar5)(param_1);
    FUN_0011b310();
    return;
  }
  if ((*(uint *)(**(int **)(param_1 + 1000) + 0x160) & 0x801) == 0) {
    *(undefined4 *)(param_1 + 0x3f8) = 0;
    iVar4 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x160))(param_1);
    if (iVar4 == 0) {
      fVar2 = *(float *)(param_1 + 0x3fc);
      fVar3 = *gpGlobals;
      if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) {
        if (((local_c & 4) == 0) &&
           (iVar4 = (**(code **)(*g_pGameRules + 0x1c))
                              (g_pGameRules,*(undefined4 *)(param_1 + 1000),param_1), iVar4 != 0)) {
          *(float *)(param_1 + 0x3fc) = *gpGlobals + 0.3;
          return;
        }
        goto LAB_0011b326;
      }
    }
    if ((*(int *)(param_1 + 0x410) == 0) && ((local_c & 2) == 0)) {
      fVar2 = *(float *)(param_1 + 0x3fc);
      fVar3 = *gpGlobals;
      if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) {
        pcVar5 = *(code **)(*(int *)(param_1 + 0x3c8) + 0x16c);
        goto LAB_0011b333;
      }
    }
  }
  else {
    iVar4 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x178))(param_1);
    if (iVar4 == 0) {
      return;
    }
  }
LAB_0011b326:
  pcVar5 = *(code **)(*(int *)(param_1 + 0x3c8) + 0x170);
LAB_0011b333:
  (*pcVar5)(param_1);
  return;
}


