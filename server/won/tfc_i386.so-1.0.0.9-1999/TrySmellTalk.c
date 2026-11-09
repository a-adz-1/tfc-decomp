// TrySmellTalk__12CTalkMonster  @ 000f2ef0
void TrySmellTalk__12CTalkMonster(int param_1)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = FOkToSpeak__12CTalkMonster(param_1);
  if (iVar1 != 0) {
    if (*(float *)(param_1 + 0x670) < *gpGlobals) {
      *(byte *)(param_1 + 0x610) = *(byte *)(param_1 + 0x610) & 0x7f;
    }
    if ((-1 < *(char *)(param_1 + 0x610)) && ((*(byte *)(param_1 + 0x46e) & 4) != 0)) {
      iVar1 = *(int *)(param_1 + 0x3c8);
      lVar2 = (longdouble)(*DAT_0017562c)(0x40333333,0x404ccccd,0x3f800000,0x40000000);
      (**(code **)(iVar1 + 0x180))(param_1,*(undefined4 *)(param_1 + 0x658),(float)lVar2);
      *(float *)(param_1 + 0x670) = *gpGlobals + 60.0;
      *(byte *)(param_1 + 0x610) = *(byte *)(param_1 + 0x610) | 0x80;
    }
  }
  return;
}


