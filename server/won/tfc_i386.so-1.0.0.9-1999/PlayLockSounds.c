// PlayLockSounds__FP9entvars_tP10locksoundsii  @ 000a8f80
void PlayLockSounds__FP9entvars_tP10locksoundsii(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  float local_8;
  
  if (param_4 == 0) {
    local_8 = 3.0;
  }
  else {
    local_8 = 0.5;
  }
  if (param_3 == 0) {
    bVar3 = false;
    if ((param_2[2] != 0) && ((float)param_2[6] < *gpGlobals)) {
      bVar3 = true;
    }
    bVar4 = false;
    if (((param_2[3] != 0) && (*(char *)((int)param_2 + 0x21) == '\0')) &&
       ((float)param_2[7] < *gpGlobals)) {
      bVar4 = true;
    }
    if ((bVar3) && (bVar4)) {
      uVar2 = 0x3e800000;
    }
    else {
      uVar2 = 0x3f800000;
    }
    if (bVar3) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(param_1 + 0x1e8),3,param_2[2] + (int)gpGlobals[0x26],uVar2,
                 0x3f4ccccd,0,100);
      param_2[6] = (int)(local_8 + *gpGlobals);
    }
    if (!bVar4) {
      return;
    }
    iVar1 = param_2[5];
    iVar5 = SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii
                      (*(undefined4 *)(param_1 + 0x1e8),param_2[3] + (int)gpGlobals[0x26],0x3f59999a
                       ,0x3f4ccccd,0,100,iVar1,0);
    param_2[5] = iVar5;
    param_2[4] = 0;
    *(bool *)((int)param_2 + 0x21) = iVar1 == iVar5;
  }
  else {
    bVar3 = false;
    if ((*param_2 != 0) && ((float)param_2[6] < *gpGlobals)) {
      bVar3 = true;
    }
    bVar4 = false;
    if (((param_2[1] != 0) && ((char)param_2[8] == '\0')) && ((float)param_2[7] < *gpGlobals)) {
      bVar4 = true;
    }
    if ((bVar3) && (bVar4)) {
      uVar2 = 0x3e800000;
    }
    else {
      uVar2 = 0x3f800000;
    }
    if (bVar3) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(param_1 + 0x1e8),3,*param_2 + (int)gpGlobals[0x26],uVar2,0x3f4ccccd
                 ,0,100);
      param_2[6] = (int)(local_8 + *gpGlobals);
    }
    if (!bVar4) {
      return;
    }
    iVar1 = param_2[4];
    iVar5 = SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii
                      (*(undefined4 *)(param_1 + 0x1e8),param_2[1] + (int)gpGlobals[0x26],0x3f59999a
                       ,0x3f4ccccd,0,100,iVar1,0);
    param_2[4] = iVar5;
    param_2[5] = 0;
    *(bool *)(param_2 + 8) = iVar1 == iVar5;
  }
  param_2[7] = (int)(*gpGlobals + 6.0);
  return;
}


