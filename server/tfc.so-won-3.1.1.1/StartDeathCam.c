// StartDeathCam__11CBasePlayer  @ 000d634c
void StartDeathCam__11CBasePlayer(int *param_1)

{
  float fVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  float **ppfVar5;
  bool bVar6;
  float *pfStack_8c;
  char *pcStack_88;
  char *pcStack_84;
  float *pfStack_80;
  float local_60;
  float local_5c;
  float local_58;
  undefined1 local_54 [20];
  float local_40;
  float local_3c;
  float local_38;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  bVar6 = false;
  iVar3 = *param_1;
  if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x174)) || NAN(g_vecZero)) << 10) >> 8
                    ) |
             (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x174) == g_vecZero) << 0xe) >> 8)) == 0x40
      ) && ((byte)((byte)((ushort)((ushort)(NAN(DAT_0019f664) || NAN(*(float *)(iVar3 + 0x178))) <<
                                  10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f664 == *(float *)(iVar3 + 0x178)) << 0xe) >> 8))
            == 0x40)) {
    fVar1 = *(float *)(iVar3 + 0x17c);
    bVar6 = (byte)(DAT_0019f668 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_0019f668) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_0019f668 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar6) {
    return;
  }
  pfStack_80 = (float *)0x150374;
  pcStack_84 = "classname";
  pcStack_88 = (char *)0x0;
  pfStack_8c = (float *)0xd63d8;
  pcVar2 = (char *)(*DAT_0019f6d8)();
  bVar6 = false;
  if (pcVar2 != (char *)0x0) {
    pcStack_84 = (char *)0xd63f2;
    pfStack_80 = (float *)pcVar2;
    iVar3 = (*DAT_0019f7b8)();
    if (iVar3 != 0) goto LAB_000d63fe;
  }
  bVar6 = true;
LAB_000d63fe:
  if (bVar6) {
    pfStack_80 = (float *)*param_1;
    pcStack_84 = (char *)0xd64ab;
    CopyToBodyQue__FP9entvars_s();
    local_8 = 0x43000000;
    local_10 = 0;
    local_c = 0;
    iVar3 = *param_1;
    local_14 = *(float *)(iVar3 + 0x10) + 128.0;
    pfStack_80 = (float *)local_54;
    local_1c = *(float *)(iVar3 + 8);
    local_18 = *(float *)(iVar3 + 0xc);
    pcStack_84 = *(char **)(iVar3 + 0x208);
    pcStack_88 = (char *)0x1;
    pfStack_8c = &local_1c;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult(iVar3 + 8);
    local_1c = local_40;
    local_18 = local_3c;
    local_14 = local_38;
    iVar3 = *param_1;
    local_60 = local_40 - *(float *)(iVar3 + 8);
    local_5c = local_3c - *(float *)(iVar3 + 0xc);
    local_58 = local_38 - *(float *)(iVar3 + 0x10);
    pfStack_80 = &local_60;
    pcStack_88 = (char *)0xd6540;
    pcStack_84 = (char *)&local_10;
    UTIL_VecToAngles__FRC6Vector();
    ppfVar5 = &pfStack_8c;
    pfStack_8c = &local_1c;
    pcStack_88 = (char *)&local_10;
  }
  else {
    pfStack_80 = (float *)0x3;
    pcStack_84 = (char *)0x0;
    pcStack_88 = (char *)0xd6418;
    for (iVar3 = (*DAT_0019f808)(); 0 < iVar3; iVar3 = iVar3 + -1) {
      pfStack_80 = (float *)0x150374;
      pcStack_84 = "classname";
      pfStack_8c = (float *)0xd643e;
      pcStack_88 = pcVar2;
      pcVar4 = (char *)(*DAT_0019f6d8)();
      if (pcVar4 != (char *)0x0) {
        pcVar2 = pcVar4;
      }
    }
    pfStack_80 = (float *)*param_1;
    pcStack_84 = (char *)0xd6459;
    CopyToBodyQue__FP9entvars_s();
    local_10 = *(undefined4 *)(pcVar2 + 0x88);
    local_c = *(undefined4 *)(pcVar2 + 0x8c);
    local_8 = *(undefined4 *)(pcVar2 + 0x90);
    local_1c = *(float *)(pcVar2 + 0xf4);
    local_18 = *(float *)(pcVar2 + 0xf8);
    local_14 = *(float *)(pcVar2 + 0xfc);
    pfStack_80 = &local_1c;
    pcStack_84 = (char *)&local_10;
    ppfVar5 = (float **)&pcStack_84;
  }
  *(int **)((int)ppfVar5 + -4) = param_1;
  *(undefined4 *)((int)ppfVar5 + -8) = 0xd654b;
  StartObserver__11CBasePlayerG6VectorT1();
  return;
}


