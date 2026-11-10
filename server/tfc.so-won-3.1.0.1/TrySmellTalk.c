// TrySmellTalk__12CTalkMonster  @ 000e9c78
void TrySmellTalk__12CTalkMonster(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  
  iVar3 = FOkToSpeak__12CTalkMonster(param_1);
  if (iVar3 != 0) {
    fVar1 = *gpGlobals;
    fVar2 = *(float *)(param_1 + 0x67c);
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      *(byte *)(param_1 + 0x61c) = *(byte *)(param_1 + 0x61c) & 0x7f;
    }
    if ((-1 < *(char *)(param_1 + 0x61c)) && ((*(byte *)(param_1 + 0x47a) & 4) != 0)) {
      iVar3 = *(int *)(param_1 + 0x3d4);
      lVar4 = (longdouble)(*DAT_001a7fac)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
      (**(code **)(iVar3 + 0x180))(param_1,*(undefined4 *)(param_1 + 0x664),(float)lVar4);
      *(float *)(param_1 + 0x67c) = *gpGlobals + 60.0;
      *(byte *)(param_1 + 0x61c) = *(byte *)(param_1 + 0x61c) | 0x80;
    }
  }
  return;
}


