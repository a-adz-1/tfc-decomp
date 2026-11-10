// PlayLockSounds__FP9entvars_sP10locksoundsii  @ 0009cac8
void PlayLockSounds__FP9entvars_sP10locksoundsii(int param_1,int *param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  float local_8;
  
  local_8 = 3.0;
  if (param_4 != 0) {
    local_8 = 0.5;
  }
  if (param_3 == 0) {
    bVar6 = false;
    if (param_2[2] != 0) {
      fVar1 = (float)param_2[6];
      fVar2 = *gpGlobals;
      bVar6 = (byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1;
    }
    bVar7 = false;
    if ((param_2[3] != 0) && (*(char *)((int)param_2 + 0x21) == '\0')) {
      fVar1 = (float)param_2[7];
      fVar2 = *gpGlobals;
      bVar7 = (byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1;
    }
    uVar3 = 0x3f800000;
    if (bVar6) {
      if (bVar7) {
        uVar3 = 0x3e800000;
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(param_1 + 0x208),3,param_2[2] + (int)gpGlobals[0x26],uVar3,
                 0x3f4ccccd,0,100);
      param_2[6] = (int)(local_8 + *gpGlobals);
    }
    if (!bVar7) {
      return;
    }
    iVar4 = param_2[5];
    iVar5 = SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii
                      (*(undefined4 *)(param_1 + 0x208),param_2[3] + (int)gpGlobals[0x26],0x3f59999a
                       ,0x3f4ccccd,0,100,iVar4,0);
    param_2[5] = iVar5;
    param_2[4] = 0;
    *(bool *)((int)param_2 + 0x21) = iVar4 == iVar5;
  }
  else {
    bVar6 = false;
    if (*param_2 != 0) {
      fVar1 = (float)param_2[6];
      fVar2 = *gpGlobals;
      bVar6 = (byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1;
    }
    bVar7 = false;
    if ((param_2[1] != 0) && ((char)param_2[8] == '\0')) {
      fVar1 = (float)param_2[7];
      fVar2 = *gpGlobals;
      bVar7 = (byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1;
    }
    uVar3 = 0x3f800000;
    if (bVar6) {
      if (bVar7) {
        uVar3 = 0x3e800000;
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(param_1 + 0x208),3,*param_2 + (int)gpGlobals[0x26],uVar3,0x3f4ccccd
                 ,0,100);
      param_2[6] = (int)(local_8 + *gpGlobals);
    }
    if (!bVar7) {
      return;
    }
    iVar4 = param_2[4];
    iVar5 = SENTENCEG_PlaySequentialSz__FP7edict_sPCcffiiii
                      (*(undefined4 *)(param_1 + 0x208),param_2[1] + (int)gpGlobals[0x26],0x3f59999a
                       ,0x3f4ccccd,0,100,iVar4,0);
    param_2[4] = iVar5;
    param_2[5] = 0;
    *(bool *)(param_2 + 8) = iVar4 == iVar5;
  }
  param_2[7] = (int)(*gpGlobals + 6.0);
  return;
}


