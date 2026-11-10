// FindHintNode__12CBaseMonster  @ 000c0b8c
int FindHintNode__12CBaseMonster(int *param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [16];
  float fStack_28;
  
  if (WorldGraph == 0) {
    (*DAT_001c1114)(2,"find_hintnode: graph not ready!\n");
  }
  else {
    if (DAT_001c1498 <= DAT_001c3544) {
      DAT_001c3544 = 0;
    }
    iVar4 = 0;
    if (0 < DAT_001c1498) {
      do {
        iVar3 = (iVar4 + DAT_001c3544) % DAT_001c1498;
        pfVar1 = (float *)(DAT_001c148c + iVar3 * 0x58);
        if (((*(short *)(pfVar1 + 0x14) != 0) &&
            (iVar2 = (**(code **)(param_1[0x111] + 0x1c8))(param_1,(int)*(short *)(pfVar1 + 0x14)),
            iVar2 != 0)) &&
           ((*(short *)((int)pfVar1 + 0x52) == 0 ||
            (iVar2 = LookupActivity__14CBaseAnimatingi(param_1,(int)*(short *)((int)pfVar1 + 0x52)),
            iVar2 != -1)))) {
          iVar2 = *param_1;
          local_44 = *pfVar1 + *(float *)(iVar2 + 0x174);
          local_40 = pfVar1[1] + *(float *)(iVar2 + 0x178);
          local_3c = pfVar1[2] + *(float *)(iVar2 + 0x17c);
          local_50 = *(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x174);
          local_4c = *(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x178);
          local_48 = *(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x17c);
          UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                    (&local_50,&local_44,1,*(undefined4 *)(iVar2 + 0x208),local_38);
          if ((byte)(1.0 < fStack_28 | (byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) == 0x40) {
            DAT_001c3544 = iVar3 + 1;
            return iVar3;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_001c1498);
    }
    DAT_001c3544 = 0;
  }
  return -1;
}


