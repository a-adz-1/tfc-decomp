// ChangeSchedule__12CBaseMonsterP10Schedule_t  @ 000e4bf0
void ChangeSchedule__12CBaseMonsterP10Schedule_t(int param_1,int param_2)

{
  char *pcVar1;
  
  *(int *)(param_1 + 0x4f4) = param_2;
  *(undefined4 *)(param_1 + 0x4f8) = 0;
  *(undefined4 *)(param_1 + 0x4f0) = 0;
  *(undefined4 *)(param_1 + 0x46c) = 0;
  *(undefined4 *)(param_1 + 0x5e4) = 0;
  if ((*(byte *)(param_2 + 10) & 2) == 0) {
    if (*(int *)(*(int *)(param_1 + 0x4f4) + 0xc) == 0) {
      return;
    }
  }
  else if (*(int *)(param_2 + 0xc) == 0) {
    pcVar1 = "COND_HEAR_SOUND with no sound mask!\n";
    goto LAB_000e4c5d;
  }
  if ((*(byte *)(*(int *)(param_1 + 0x4f4) + 10) & 2) != 0) {
    return;
  }
  pcVar1 = "Sound mask without COND_HEAR_SOUND!\n";
LAB_000e4c5d:
  (*DAT_001755b4)(2,pcVar1);
  return;
}


