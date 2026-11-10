// StartDeathCam__11CBasePlayer  @ 000cb14c
void StartDeathCam__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  float local_5c;
  float local_58;
  float local_54;
  undefined1 local_50 [20];
  float local_3c;
  float local_38;
  float local_34;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = *param_1;
  bVar6 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x174))) << 10) >> 8
                    ) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x174)) << 0xe) >> 8)) == 0x40
      ) && ((byte)((byte)((ushort)((ushort)(NAN(DAT_001a7e04) || NAN(*(float *)(iVar2 + 0x178))) <<
                                  10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001a7e04 == *(float *)(iVar2 + 0x178)) << 0xe) >> 8))
            == 0x40)) {
    fVar1 = *(float *)(iVar2 + 0x17c);
    bVar6 = (byte)(DAT_001a7e08 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_001a7e08) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001a7e08 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar6) {
    return;
  }
  iVar2 = (*DAT_001a7e78)(0,"classname","info_intermission");
  bVar6 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_001a7f58)(iVar2), iVar3 == 0)) {
    bVar6 = true;
  }
  if (bVar6) {
    CopyToBodyQue__FP9entvars_s(*param_1);
    local_4 = 0x43000000;
    local_c = 0;
    local_8 = 0;
    iVar2 = *param_1;
    local_18 = *(float *)(iVar2 + 8);
    local_14 = *(float *)(iVar2 + 0xc);
    local_10 = *(float *)(iVar2 + 0x10) + 128.0;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (iVar2 + 8,&local_18,1,*(undefined4 *)(iVar2 + 0x208),local_50);
    local_18 = local_3c;
    local_14 = local_38;
    local_10 = local_34;
    iVar2 = *param_1;
    local_5c = local_3c - *(float *)(iVar2 + 8);
    local_58 = local_38 - *(float *)(iVar2 + 0xc);
    local_54 = local_34 - *(float *)(iVar2 + 0x10);
    UTIL_VecToAngles__FRC6Vector(&local_c,&local_5c);
    StartObserver__11CBasePlayerG6VectorT1(param_1,&local_18,&local_c);
    return;
  }
  iVar3 = (*DAT_001a7fa8)(0,3);
  if (0 < iVar3) {
    uVar5 = -iVar3 & 3;
    if (uVar5 != 0) {
      if (uVar5 < 3) {
        if (uVar5 < 2) {
          iVar4 = (*DAT_001a7e78)(iVar2,"classname","info_intermission");
          if (iVar4 != 0) {
            iVar2 = iVar4;
          }
          iVar3 = iVar3 + -1;
        }
        iVar4 = (*DAT_001a7e78)(iVar2,"classname","info_intermission");
        if (iVar4 != 0) {
          iVar2 = iVar4;
        }
        iVar3 = iVar3 + -1;
      }
      iVar4 = (*DAT_001a7e78)(iVar2,"classname","info_intermission");
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      iVar3 = iVar3 + -1;
      if (iVar3 < 1) goto LAB_000cb357;
    }
    do {
      iVar4 = (*DAT_001a7e78)(iVar2,"classname","info_intermission");
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      iVar4 = (*DAT_001a7e78)(iVar2,"classname","info_intermission");
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      iVar4 = (*DAT_001a7e78)(iVar2,"classname","info_intermission");
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      iVar4 = (*DAT_001a7e78)(iVar2,"classname","info_intermission");
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      iVar3 = iVar3 + -4;
    } while (0 < iVar3);
  }
LAB_000cb357:
  CopyToBodyQue__FP9entvars_s(*param_1);
  local_c = *(undefined4 *)(iVar2 + 0x88);
  local_8 = *(undefined4 *)(iVar2 + 0x8c);
  local_4 = *(undefined4 *)(iVar2 + 0x90);
  local_18 = *(float *)(iVar2 + 0xf4);
  local_14 = *(float *)(iVar2 + 0xf8);
  local_10 = *(float *)(iVar2 + 0xfc);
  StartObserver__11CBasePlayerG6VectorT1(param_1,&local_c,&local_18);
  return;
}


