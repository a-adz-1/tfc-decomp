// PainSound__11CBasePlayer  @ 000c7fb8
void PainSound__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  char *pcVar4;
  longdouble lVar5;
  undefined4 uVar6;
  
  iVar3 = *param_1;
  if (0.0 <= *(float *)(iVar3 + 0x160)) {
    if ((*(int *)(iVar3 + 0x1c4) == -3) && (*(int *)(iVar3 + 0x1c0) == 3)) {
      lVar5 = (longdouble)(*DAT_001a7fac)(0,0x3f800000);
      if (lVar5 <= (longdouble)0.5) {
        uVar6 = *(undefined4 *)(*param_1 + 0x208);
        pcVar4 = "player/drown2.wav";
      }
      else {
        uVar6 = *(undefined4 *)(*param_1 + 0x208);
        pcVar4 = "player/drown1.wav";
      }
    }
    else {
      fVar1 = *(float *)(*param_1 + 0x200);
      fVar2 = *gpGlobals;
      if (0x3f < (byte)((fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
        param_1[0xc0] = 0;
        return;
      }
      *(float *)(*param_1 + 0x200) = *gpGlobals + 0.5;
      if (param_1[0xc0] == 1) {
        param_1[0xc0] = 0;
        uVar6 = *(undefined4 *)(*param_1 + 0x208);
        pcVar4 = "player/axhit1.wav";
      }
      else {
        iVar3 = (*DAT_001a7fa8)(1,6);
        *(int *)(*param_1 + 0x1e8) = (int)&DAT_00139fe6 - (int)gpGlobals[0x26];
        if (iVar3 == 1) {
          iVar3 = *param_1;
          pcVar4 = "player/pain1.wav";
        }
        else if (iVar3 == 2) {
          iVar3 = *param_1;
          pcVar4 = "player/pain2.wav";
        }
        else if (iVar3 == 3) {
          iVar3 = *param_1;
          pcVar4 = "player/pain3.wav";
        }
        else if (iVar3 == 4) {
          iVar3 = *param_1;
          pcVar4 = "player/pain4.wav";
        }
        else if (iVar3 == 5) {
          iVar3 = *param_1;
          pcVar4 = "player/pain5.wav";
        }
        else {
          iVar3 = *param_1;
          pcVar4 = "player/pain6.wav";
        }
        *(int *)(iVar3 + 0x1e8) = (int)pcVar4 - (int)gpGlobals[0x26];
        uVar6 = *(undefined4 *)(*param_1 + 0x208);
        pcVar4 = (char *)(*(int *)(*param_1 + 0x1e8) + (int)gpGlobals[0x26]);
      }
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar6,2,pcVar4,0x3f800000,0x3f4ccccd,0,100);
  }
  return;
}


// PainSound__12CBaseMonster  @ 000b7440
void PainSound__12CBaseMonster(void)

{
  return;
}


