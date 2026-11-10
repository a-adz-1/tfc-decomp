// PlayTrack__15CTriggerCDAudio  @ 00119264
void PlayTrack__15CTriggerCDAudio(int *param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined2 in_FPUControlWord;
  char *pcVar4;
  char local_50 [64];
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
  iVar1 = (int)ROUND(*(float *)(*param_1 + 0x160));
  local_10 = iVar1;
  iVar2 = (*DAT_0019f7c0)(1);
  if (iVar2 != 0) {
    if (iVar1 + 1U < 0x20) {
      if (iVar1 != -1) {
        sprintf(local_50,"cd play %3d\n",iVar1);
        (*DAT_0019f744)(iVar2,local_50);
        goto LAB_00119318;
      }
      pcVar4 = "cd pause\n";
      pcVar3 = DAT_0019f744;
    }
    else {
      pcVar4 = "TriggerCDAudio - Track %d out of range\n";
      iVar2 = 1;
      pcVar3 = DAT_0019f794;
    }
    (*pcVar3)(iVar2,pcVar4);
  }
LAB_00119318:
  param_1[5] = 0;
  param_1[6] = 0;
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


