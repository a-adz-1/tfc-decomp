// FindHintNode__12CBaseMonster  @ 000c6e10
int FindHintNode__12CBaseMonster(int *param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float local_54;
  float fStack_50;
  float fStack_4c;
  float local_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  
  if (WorldGraph == 0) {
    (*DAT_001755b4)(2,"find_hintnode: graph not ready!\n");
  }
  else {
    if (DAT_001758d8 <= DAT_00177984) {
      DAT_00177984 = 0;
    }
    iVar4 = 0;
    if (0 < DAT_001758d8) {
      do {
        iVar3 = (iVar4 + DAT_00177984) % DAT_001758d8;
        pfVar1 = (float *)(DAT_001758cc + iVar3 * 0x58);
        if (((*(short *)(pfVar1 + 0x14) != 0) &&
            (iVar2 = (**(code **)(param_1[0xf2] + 0x1c0))(param_1,(int)*(short *)(pfVar1 + 0x14)),
            iVar2 != 0)) &&
           ((*(short *)((int)pfVar1 + 0x52) == 0 ||
            (iVar2 = LookupActivity__14CBaseAnimatingi(param_1,(int)*(short *)((int)pfVar1 + 0x52)),
            iVar2 != -1)))) {
          iVar2 = *param_1;
          local_48 = *pfVar1 + *(float *)(iVar2 + 0x154);
          fStack_44 = pfVar1[1] + *(float *)(iVar2 + 0x158);
          fStack_40 = pfVar1[2] + *(float *)(iVar2 + 0x15c);
          local_54 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x154);
          fStack_50 = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x158);
          fStack_4c = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x15c);
          UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                    (&local_54,&local_48,1,*(undefined4 *)(iVar2 + 0x1e8),auStack_3c);
          if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40) {
            DAT_00177984 = iVar3 + 1;
            return iVar3;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_001758d8);
    }
    DAT_00177984 = 0;
  }
  return -1;
}


