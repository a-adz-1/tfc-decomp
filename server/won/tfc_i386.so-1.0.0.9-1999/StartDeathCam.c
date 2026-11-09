// StartDeathCam__11CBasePlayer  @ 000d9040
void StartDeathCam__11CBasePlayer(int *param_1)

{
  float fVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  float **ppfVar5;
  bool bVar6;
  float *pfStack_80;
  char *pcStack_7c;
  char *pcStack_78;
  float *pfStack_74;
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
  
  iVar3 = *param_1;
  bVar6 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(g_vecZero) || NAN(*(float *)(iVar3 + 0x154))) << 10) >> 8
                    ) |
             (byte)((ushort)((ushort)(g_vecZero == *(float *)(iVar3 + 0x154)) << 0xe) >> 8)) == 0x40
      ) && ((byte)((byte)((ushort)((ushort)(NAN(DAT_00175484) || NAN(*(float *)(iVar3 + 0x158))) <<
                                  10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00175484 == *(float *)(iVar3 + 0x158)) << 0xe) >> 8))
            == 0x40)) {
    fVar1 = *(float *)(iVar3 + 0x15c);
    bVar6 = (byte)(DAT_00175488 < fVar1 |
                   (byte)((ushort)((ushort)(NAN(DAT_00175488) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(DAT_00175488 == fVar1) << 0xe) >> 8)) == 0x40;
  }
  if (bVar6) {
    return;
  }
  pfStack_74 = (float *)0x139ad0;
  pcStack_78 = "classname";
  pcStack_7c = (char *)0x0;
  pfStack_80 = (float *)0xd90b8;
  pcVar2 = (char *)(*DAT_001754f8)();
  bVar6 = false;
  if (pcVar2 != (char *)0x0) {
    pcStack_78 = (char *)0xd90cb;
    pfStack_74 = (float *)pcVar2;
    iVar3 = (*DAT_001755d8)();
    if (iVar3 != 0) goto LAB_000d90d7;
  }
  bVar6 = true;
LAB_000d90d7:
  if (bVar6) {
    pfStack_74 = (float *)*param_1;
    pcStack_78 = (char *)0xd9178;
    CopyToBodyQue__FP9entvars_t();
    local_10 = 0;
    local_c = 0;
    local_8 = 0x43000000;
    iVar3 = *param_1;
    local_1c = *(float *)(iVar3 + 8) + 0.0;
    local_18 = *(float *)(iVar3 + 0xc) + 0.0;
    local_14 = *(float *)(iVar3 + 0x10) + 128.0;
    pfStack_74 = (float *)local_54;
    pcStack_78 = *(char **)(iVar3 + 0x1e8);
    pcStack_7c = (char *)0x1;
    pfStack_80 = &local_1c;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult(iVar3 + 8);
    local_1c = local_40;
    local_18 = local_3c;
    local_14 = local_38;
    iVar3 = *param_1;
    local_60 = local_40 - *(float *)(iVar3 + 8);
    local_5c = local_3c - *(float *)(iVar3 + 0xc);
    local_58 = local_38 - *(float *)(iVar3 + 0x10);
    pfStack_74 = &local_60;
    pcStack_7c = (char *)0xd920f;
    pcStack_78 = (char *)&local_10;
    UTIL_VecToAngles__FRC6Vector();
    ppfVar5 = &pfStack_80;
    pfStack_80 = &local_1c;
    pcStack_7c = (char *)&local_10;
  }
  else {
    pfStack_74 = (float *)0x3;
    pcStack_78 = (char *)0x0;
    pcStack_7c = (char *)0xd90ea;
    for (iVar3 = (*DAT_00175628)(); 0 < iVar3; iVar3 = iVar3 + -1) {
      pfStack_74 = (float *)0x139ad0;
      pcStack_78 = "classname";
      pfStack_80 = (float *)0xd9106;
      pcStack_7c = pcVar2;
      pcVar4 = (char *)(*DAT_001754f8)();
      if (pcVar4 != (char *)0x0) {
        pcVar2 = pcVar4;
      }
    }
    pfStack_74 = (float *)*param_1;
    pcStack_78 = (char *)0xd911e;
    CopyToBodyQue__FP9entvars_t();
    local_10 = *(undefined4 *)(pcVar2 + 0xe4);
    local_c = *(undefined4 *)(pcVar2 + 0xe8);
    local_8 = *(undefined4 *)(pcVar2 + 0xec);
    local_1c = *(float *)(pcVar2 + 0x150);
    local_18 = *(float *)(pcVar2 + 0x154);
    local_14 = *(float *)(pcVar2 + 0x158);
    pfStack_74 = &local_1c;
    pcStack_78 = (char *)&local_10;
    ppfVar5 = (float **)&pcStack_78;
  }
  *(int **)((int)ppfVar5 + -4) = param_1;
  *(undefined4 *)((int)ppfVar5 + -8) = 0xd9217;
  StartObserver__11CBasePlayerG6VectorT1();
  return;
}


