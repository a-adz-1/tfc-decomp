// ItemPostFrame__11CBasePlayer  @ 000d100c
void ItemPostFrame__11CBasePlayer(int param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x7f4);
  if (iVar2 == 0) {
    fVar1 = *(float *)(param_1 + 0x5d8);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x224))(param_1);
      if (*(int *)(param_1 + 0x844) != 0) {
        (**(code **)(*(int *)(*(int *)(param_1 + 0x844) + 0x3d4) + 300))(*(int *)(param_1 + 0x844));
      }
    }
  }
  return;
}


// ItemPostFrame__14CTFSniperRifle  @ 0011d078
void ItemPostFrame__14CTFSniperRifle(void)

{
  FUN_0011d083();
  return;
}


// ItemPostFrame__15CBasePlayerItem  @ 0011243c
void ItemPostFrame__15CBasePlayerItem(void)

{
  return;
}


// ItemPostFrame__17CBasePlayerWeapon  @ 0011030c
void ItemPostFrame__17CBasePlayerWeapon(int param_1)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  undefined1 auStack_58 [28];
  int iStack_3c;
  undefined1 local_2c [8];
  int iStack_24;
  int iStack_10;
  byte bStack_8;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x110))(param_1,local_2c);
  if (*(int *)(param_1 + 0xb0) == 0) {
    piVar6 = (int *)(*(int *)(param_1 + 0x3f4) + 0x850 + *(int *)(param_1 + 0x438) * 4);
  }
  else {
    piVar6 = *(int **)(param_1 + 0xb0);
  }
  if ((*(int *)(param_1 + 0x430) != 0) &&
     (fVar2 = *(float *)(*(int *)(param_1 + 0x3f4) + 0x5d8),
     (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x110))(param_1,auStack_58);
    iStack_3c = iStack_3c - *(int *)(param_1 + 0x440);
    iVar4 = *piVar6;
    if (iStack_3c < *piVar6) {
      iVar4 = iStack_3c;
    }
    *(int *)(param_1 + 0x440) = *(int *)(param_1 + 0x440) + iVar4;
    *piVar6 = *piVar6 - iVar4;
    *(undefined4 *)(param_1 + 0x430) = 0;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x3f4) + 0x84);
    *pbVar1 = *pbVar1 & 0xfd;
  }
  if (((*(byte *)(**(int **)(param_1 + 0x3f4) + 0x180) & 1) != 0) &&
     (fVar2 = *(float *)(param_1 + 0x408),
     (byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1)) {
    if (((*(int *)(param_1 + 0x440) == 0) && (iStack_24 != 0)) ||
       ((iStack_10 == -1 && (*piVar6 == 0)))) {
      *(undefined4 *)(param_1 + 0x404) = 1;
    }
    iVar4 = *(int *)(param_1 + 0x3f4);
    if (((*(int *)(iVar4 + 100) != 0) || (*(int *)(iVar4 + 0x1d4) != 0)) ||
       (*(int *)(iVar4 + 0x1d8) != 0)) {
      Spy_RemoveDisguise__11CBasePlayer(*(undefined4 *)(param_1 + 0x3f4));
    }
    piVar6 = *(int **)(param_1 + 0x3f4);
    fVar2 = (float)piVar6[0xed];
    fVar3 = *gpGlobals;
    if ((0x3f < (byte)((fVar2 < fVar3 |
                        (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1)) &&
       ((float)piVar6[0xf4] < *gpGlobals)) {
      *(float *)(param_1 + 0x3d0) = *gpGlobals + 1.0;
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*piVar6 + 0x208),3,"items/damage2.wav",0x3f800000,0x3f4ccccd,0,100)
      ;
    }
    pcVar5 = *(code **)(*(int *)(param_1 + 0x3d4) + 0x168);
LAB_001104fe:
    (*pcVar5)(param_1);
    FUN_001105c4();
    return;
  }
  if ((((*(byte *)(**(int **)(param_1 + 0x3f4) + 0x181) & 0x20) != 0) && (iStack_10 != -1)) &&
     (*(int *)(param_1 + 0x430) == 0)) {
    pcVar5 = *(code **)(*(int *)(param_1 + 0x3d4) + 0x170);
    goto LAB_001104fe;
  }
  if ((*(uint *)(**(int **)(param_1 + 0x3f4) + 0x180) & 0x801) == 0) {
    *(undefined4 *)(param_1 + 0x404) = 0;
    iVar4 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x164))(param_1);
    if ((iVar4 == 0) &&
       (fVar2 = *(float *)(param_1 + 0x408),
       0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1))) {
      if (((bStack_8 & 4) == 0) &&
         (iVar4 = (**(code **)(*g_pGameRules + 0x1c))
                            (g_pGameRules,*(undefined4 *)(param_1 + 0x3f4),param_1), iVar4 != 0)) {
        *(undefined4 *)(param_1 + 0x408) = 0x3e99999a;
        return;
      }
    }
    else if (((*(int *)(param_1 + 0x440) == 0) && ((bStack_8 & 2) == 0)) &&
            (fVar2 = *(float *)(param_1 + 0x408),
            0x3f < (byte)((0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) - 1))) {
      pcVar5 = *(code **)(*(int *)(param_1 + 0x3d4) + 0x170);
      goto LAB_001105e7;
    }
  }
  else {
    iVar4 = (**(code **)(*(int *)(param_1 + 0x3d4) + 0x17c))(param_1);
    if (iVar4 == 0) {
      return;
    }
  }
  pcVar5 = *(code **)(*(int *)(param_1 + 0x3d4) + 0x174);
LAB_001105e7:
  (*pcVar5)(param_1);
  return;
}


