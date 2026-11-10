// StartDeathCam__11CBasePlayer  @ 000d67e8
void StartDeathCam__11CBasePlayer(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  undefined1 auStack_50 [20];
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar2 = *param_1;
  bVar6 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar2 + 0x174))) << 10) >> 8
                    ) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar2 + 0x174)) << 0xe) >> 8)) == 0x40
      ) && ((byte)((byte)((ushort)((ushort)(NAN(DAT_001c0fe4) || NAN(*(float *)(iVar2 + 0x178))) <<
                                  10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001c0fe4 == *(float *)(iVar2 + 0x178)) << 0xe) >> 8))
            == 0x40)) {
    fVar1 = *(float *)(iVar2 + 0x17c);
    bVar6 = (byte)(DAT_001c0fe8 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_001c0fe8) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_001c0fe8 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar6) {
    return;
  }
  iVar2 = (*DAT_001c1058)(0,"classname","info_intermission");
  bVar6 = false;
  if ((iVar2 == 0) || (iVar3 = (*DAT_001c1138)(iVar2), iVar3 == 0)) {
    bVar6 = true;
  }
  if (bVar6) {
    CopyToBodyQue__FP9entvars_s(*param_1);
    uStack_4 = 0x43000000;
    uStack_c = 0;
    uStack_8 = 0;
    iVar2 = *param_1;
    fStack_18 = *(float *)(iVar2 + 8);
    fStack_14 = *(float *)(iVar2 + 0xc);
    fStack_10 = *(float *)(iVar2 + 0x10) + 128.0;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (iVar2 + 8,&fStack_18,1,*(undefined4 *)(iVar2 + 0x208),auStack_50);
    fStack_18 = fStack_3c;
    fStack_14 = fStack_38;
    fStack_10 = fStack_34;
    iVar2 = *param_1;
    fStack_5c = fStack_3c - *(float *)(iVar2 + 8);
    fStack_58 = fStack_38 - *(float *)(iVar2 + 0xc);
    fStack_54 = fStack_34 - *(float *)(iVar2 + 0x10);
    UTIL_VecToAngles__FRC6Vector(&uStack_c,&fStack_5c);
    StartObserver__11CBasePlayerG6VectorT1(param_1,&fStack_18,&uStack_c);
    return;
  }
  iVar3 = (*DAT_001c1188)(0,3);
  if (0 < iVar3) {
    uVar5 = -iVar3 & 3;
    if (uVar5 != 0) {
      if (uVar5 < 3) {
        if (uVar5 < 2) {
          iVar4 = (*DAT_001c1058)(iVar2,"classname","info_intermission");
          if (iVar4 != 0) {
            iVar2 = iVar4;
          }
          iVar3 = iVar3 + -1;
        }
        iVar4 = (*DAT_001c1058)(iVar2,"classname","info_intermission");
        if (iVar4 != 0) {
          iVar2 = iVar4;
        }
        iVar3 = iVar3 + -1;
      }
      iVar4 = (*DAT_001c1058)(iVar2,"classname","info_intermission");
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      iVar3 = iVar3 + -1;
      if (iVar3 < 1) goto LAB_000d69f3;
    }
    do {
      iVar4 = (*DAT_001c1058)(iVar2,"classname","info_intermission");
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      iVar4 = (*DAT_001c1058)(iVar2,"classname","info_intermission");
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      iVar4 = (*DAT_001c1058)(iVar2,"classname","info_intermission");
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      iVar4 = (*DAT_001c1058)(iVar2,"classname","info_intermission");
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      iVar3 = iVar3 + -4;
    } while (0 < iVar3);
  }
LAB_000d69f3:
  CopyToBodyQue__FP9entvars_s(*param_1);
  uStack_c = *(undefined4 *)(iVar2 + 0x88);
  uStack_8 = *(undefined4 *)(iVar2 + 0x8c);
  uStack_4 = *(undefined4 *)(iVar2 + 0x90);
  fStack_18 = *(float *)(iVar2 + 0xf4);
  fStack_14 = *(float *)(iVar2 + 0xf8);
  fStack_10 = *(float *)(iVar2 + 0xfc);
  StartObserver__11CBasePlayerG6VectorT1(param_1,&uStack_c,&fStack_18);
  return;
}


