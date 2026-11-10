// TrySmellTalk__12CTalkMonster  @ 000f88dc
void TrySmellTalk__12CTalkMonster(int param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar2 = FOkToSpeak__12CTalkMonster(param_1);
  if (iVar2 != 0) {
    if (*(float *)(param_1 + 0x6fc) < *gpGlobals) {
      *(byte *)(param_1 + 0x69c) = *(byte *)(param_1 + 0x69c) & 0x7f;
    }
    if ((-1 < *(char *)(param_1 + 0x69c)) && ((*(byte *)(param_1 + 0x4fa) & 4) != 0)) {
      iVar2 = *(int *)(param_1 + 0x454);
      lVar3 = (longdouble)(*DAT_0019f80c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
      (**(code **)(iVar2 + 0x188))(param_1,*(undefined4 *)(param_1 + 0x6e4),(float)lVar3);
      fVar1 = *gpGlobals;
      *(byte *)(param_1 + 0x69c) = *(byte *)(param_1 + 0x69c) | 0x80;
      *(float *)(param_1 + 0x6fc) = fVar1 + 60.0;
    }
  }
  return;
}


