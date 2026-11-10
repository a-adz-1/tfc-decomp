// FindHintNode__12CBaseMonster  @ 000bfe98
int FindHintNode__12CBaseMonster(int *param_1)

{
  float *pfVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  
  if (WorldGraph == 0) {
    (*DAT_0019f794)(2,"find_hintnode: graph not ready!\n");
  }
  else {
    if (DAT_0019fb38 <= iRam001a1be4) {
      iRam001a1be4 = 0;
    }
    iStack_58 = 0;
    if (0 < DAT_0019fb38) {
      do {
        iVar5 = (iStack_58 + iRam001a1be4) % DAT_0019fb38;
        pfVar1 = (float *)(DAT_0019fb2c + iVar5 * 0x58);
        if ((*(short *)(pfVar1 + 0x14) != 0) &&
           (iVar3 = (**(code **)(param_1[0x115] + 0x1c8))(param_1,(int)*(short *)(pfVar1 + 0x14)),
           iVar3 != 0)) {
          if (*(short *)((int)pfVar1 + 0x52) != 0) {
            sVar2 = *(short *)((int)pfVar1 + 0x52);
            uVar4 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
            iVar3 = LookupActivity__FPvP9entvars_si(uVar4,*param_1,(int)sVar2);
            if (iVar3 == -1) goto LAB_000c004b;
          }
          iVar3 = *param_1;
          fStack_48 = *pfVar1 + *(float *)(iVar3 + 0x174);
          fStack_44 = pfVar1[1] + *(float *)(iVar3 + 0x178);
          fStack_40 = pfVar1[2] + *(float *)(iVar3 + 0x17c);
          fStack_54 = *(float *)(iVar3 + 8) + *(float *)(iVar3 + 0x174);
          fStack_50 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 0x178);
          fStack_4c = *(float *)(iVar3 + 0x10) + *(float *)(iVar3 + 0x17c);
          UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                    (&fStack_54,&fStack_48,1,*(undefined4 *)(iVar3 + 0x208),auStack_3c);
          if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40) {
            iRam001a1be4 = iVar5 + 1;
            return iVar5;
          }
        }
LAB_000c004b:
        iStack_58 = iStack_58 + 1;
      } while (iStack_58 < DAT_0019fb38);
    }
    iRam001a1be4 = 0;
  }
  return -1;
}


