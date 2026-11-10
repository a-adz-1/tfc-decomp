// ChangeSchedule__12CBaseMonsterP10Schedule_t  @ 000e56bc
void ChangeSchedule__12CBaseMonsterP10Schedule_t(int param_1,int param_2)

{
  char *pcVar1;
  
  *(int *)(param_1 + 0x570) = param_2;
  *(undefined4 *)(param_1 + 0x574) = 0;
  *(undefined4 *)(param_1 + 0x56c) = 0;
  *(undefined4 *)(param_1 + 0x4e8) = 0;
  *(undefined4 *)(param_1 + 0x660) = 0;
  if ((*(byte *)(param_2 + 10) & 2) == 0) {
    if (*(int *)(*(int *)(param_1 + 0x570) + 0xc) == 0) {
      return;
    }
  }
  else if (*(int *)(param_2 + 0xc) == 0) {
    pcVar1 = "COND_HEAR_SOUND with no sound mask!\n";
    goto LAB_000e5740;
  }
  if ((*(byte *)(*(int *)(param_1 + 0x570) + 10) & 2) != 0) {
    return;
  }
  pcVar1 = "Sound mask without COND_HEAR_SOUND!\n";
LAB_000e5740:
  (*DAT_001c1114)(2,pcVar1);
  return;
}


