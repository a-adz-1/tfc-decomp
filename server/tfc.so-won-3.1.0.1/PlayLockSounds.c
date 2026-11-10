// PlayLockSounds__FP9entvars_sP10locksoundsii  @ 00092fb0
void PlayLockSounds__FP9entvars_sP10locksoundsii(int param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  float local_4;
  
  local_4 = 3.0;
  if (param_4 != 0) {
    local_4 = 0.5;
  }
  if (param_3 == 0) {
    bVar4 = false;
    if (param_2[2] != 0) {
      bVar4 = (float)param_2[6] < *gpGlobals;
    }
    bVar5 = false;
    if ((param_2[3] != 0) && (*(char *)((int)param_2 + 0x21) == '\0')) {
      bVar5 = (float)param_2[7] < *gpGlobals;
    }
    uVar1 = 0x3f800000;
    if (bVar4) {
      if (bVar5) {
        uVar1 = 0x3e800000;
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(param_1 + 0x208),3,param_2[2] + (int)gpGlobals[0x26],uVar1,
                 0x3f4ccccd,0,100);
      param_2[6] = (int)(local_4 + *gpGlobals);
    }
    if (!bVar5) {
      return;
    }
    iVar2 = param_2[5];
    iVar3 = SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii
                      (*(undefined4 *)(param_1 + 0x208),param_2[3] + (int)gpGlobals[0x26],0x3f59999a
                       ,0x3f4ccccd,0,100,iVar2,0);
    param_2[5] = iVar3;
    param_2[4] = 0;
    *(bool *)((int)param_2 + 0x21) = iVar2 == iVar3;
  }
  else {
    bVar4 = false;
    if (*param_2 != 0) {
      bVar4 = (float)param_2[6] < *gpGlobals;
    }
    bVar5 = false;
    if ((param_2[1] != 0) && ((char)param_2[8] == '\0')) {
      bVar5 = (float)param_2[7] < *gpGlobals;
    }
    uVar1 = 0x3f800000;
    if (bVar4) {
      if (bVar5) {
        uVar1 = 0x3e800000;
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(param_1 + 0x208),3,*param_2 + (int)gpGlobals[0x26],uVar1,0x3f4ccccd
                 ,0,100);
      param_2[6] = (int)(local_4 + *gpGlobals);
    }
    if (!bVar5) {
      return;
    }
    iVar2 = param_2[4];
    iVar3 = SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii
                      (*(undefined4 *)(param_1 + 0x208),param_2[1] + (int)gpGlobals[0x26],0x3f59999a
                       ,0x3f4ccccd,0,100,iVar2,0);
    param_2[4] = iVar3;
    param_2[5] = 0;
    *(bool *)(param_2 + 8) = iVar2 == iVar3;
  }
  param_2[7] = (int)(*gpGlobals + 6.0);
  return;
}


