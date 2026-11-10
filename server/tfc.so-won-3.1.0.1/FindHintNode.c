// FindHintNode__12CBaseMonster  @ 000b592c
int FindHintNode__12CBaseMonster(int *param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  undefined1 auStack_38 [16];
  float fStack_28;
  
  if (WorldGraph == 0) {
    (*DAT_001a7f34)(2,"find_hintnode: graph not ready!\n");
  }
  else {
    if (DAT_001a82b8 <= DAT_001aa364) {
      DAT_001aa364 = 0;
    }
    iVar4 = 0;
    if (0 < DAT_001a82b8) {
      do {
        iVar3 = (iVar4 + DAT_001aa364) % DAT_001a82b8;
        pfVar1 = (float *)(DAT_001a82ac + iVar3 * 0x58);
        if (((*(short *)(pfVar1 + 0x14) != 0) &&
            (iVar2 = (**(code **)(param_1[0xf5] + 0x1c0))(param_1,(int)*(short *)(pfVar1 + 0x14)),
            iVar2 != 0)) &&
           ((*(short *)((int)pfVar1 + 0x52) == 0 ||
            (iVar2 = LookupActivity__14CBaseAnimatingi(param_1,(int)*(short *)((int)pfVar1 + 0x52)),
            iVar2 != -1)))) {
          iVar2 = *param_1;
          fStack_44 = *pfVar1 + *(float *)(iVar2 + 0x174);
          fStack_40 = pfVar1[1] + *(float *)(iVar2 + 0x178);
          fStack_3c = pfVar1[2] + *(float *)(iVar2 + 0x17c);
          fStack_50 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
          fStack_4c = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
          fStack_48 = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
          UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                    (&fStack_50,&fStack_44,1,*(undefined4 *)(iVar2 + 0x208),auStack_38);
          if ((byte)(1.0 < fStack_28 | (byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) == 0x40) {
            DAT_001aa364 = iVar3 + 1;
            return iVar3;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_001a82b8);
    }
    DAT_001aa364 = 0;
  }
  return -1;
}


