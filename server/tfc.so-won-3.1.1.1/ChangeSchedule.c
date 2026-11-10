// ChangeSchedule__12CBaseMonsterP10Schedule_t  @ 000e9108
void ChangeSchedule__12CBaseMonsterP10Schedule_t(int param_1,int param_2)

{
  code *pcVar1;
  
  *(int *)(param_1 + 0x580) = param_2;
  *(undefined4 *)(param_1 + 0x584) = 0;
  *(undefined4 *)(param_1 + 0x57c) = 0;
  *(undefined4 *)(param_1 + 0x4f8) = 0;
  *(undefined4 *)(param_1 + 0x670) = 0;
  if ((*(byte *)(param_2 + 10) & 2) == 0) {
    if (*(int *)(param_2 + 0xc) == 0) {
      return;
    }
  }
  else if (*(int *)(param_2 + 0xc) == 0) {
    pcVar1 = FUN_00151760;
    goto LAB_000e9186;
  }
  if ((*(byte *)(*(int *)(param_1 + 0x580) + 10) & 2) != 0) {
    return;
  }
  pcVar1 = (code *)"Sound mask without COND_HEAR_SOUND!\n";
LAB_000e9186:
  (*DAT_0019f794)(2,pcVar1);
  return;
}


