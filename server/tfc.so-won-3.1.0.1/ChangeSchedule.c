// ChangeSchedule__12CBaseMonsterP10Schedule_t  @ 000d9620
void ChangeSchedule__12CBaseMonsterP10Schedule_t(int param_1,int param_2)

{
  char *pcVar1;
  
  *(int *)(param_1 + 0x500) = param_2;
  *(undefined4 *)(param_1 + 0x504) = 0;
  *(undefined4 *)(param_1 + 0x4fc) = 0;
  *(undefined4 *)(param_1 + 0x478) = 0;
  *(undefined4 *)(param_1 + 0x5f0) = 0;
  if ((*(byte *)(param_2 + 10) & 2) == 0) {
    if (*(int *)(*(int *)(param_1 + 0x500) + 0xc) == 0) {
      return;
    }
  }
  else if (*(int *)(param_2 + 0xc) == 0) {
    pcVar1 = "COND_HEAR_SOUND with no sound mask!\n";
    goto LAB_000d96a4;
  }
  if ((*(byte *)(*(int *)(param_1 + 0x500) + 10) & 2) != 0) {
    return;
  }
  pcVar1 = "Sound mask without COND_HEAR_SOUND!\n";
LAB_000d96a4:
  (*DAT_001a7f34)(2,pcVar1);
  return;
}


