// PainSound__11CBasePlayer  @ 000d38d0
void PainSound__11CBasePlayer(int *param_1)

{
  int iVar1;
  char *pcVar2;
  longdouble lVar3;
  undefined4 uVar4;
  
  iVar1 = *param_1;
  if (0.0 <= *(float *)(iVar1 + 0x160)) {
    if ((*(int *)(iVar1 + 0x1c4) == -3) && (*(int *)(iVar1 + 0x1c0) == 3)) {
      lVar3 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
      if (lVar3 <= (longdouble)0.5) {
        uVar4 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = "player/drown2.wav";
      }
      else {
        uVar4 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = "player/drown1.wav";
      }
    }
    else {
      if (*gpGlobals < *(float *)(iVar1 + 0x200)) {
        param_1[199] = 0;
        return;
      }
      *(float *)(iVar1 + 0x200) = *gpGlobals + 0.5;
      if (param_1[199] == 1) {
        param_1[199] = 0;
        uVar4 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = "player/axhit1.wav";
      }
      else {
        iVar1 = (*DAT_0019f808)(1,6);
        *(int *)(*param_1 + 0x1e8) = (int)&DAT_0014fc86 - (int)gpGlobals[0x26];
        if (iVar1 == 1) {
          iVar1 = *param_1;
          pcVar2 = "player/pain1.wav";
        }
        else if (iVar1 == 2) {
          iVar1 = *param_1;
          pcVar2 = "player/pain2.wav";
        }
        else if (iVar1 == 3) {
          iVar1 = *param_1;
          pcVar2 = "player/pain3.wav";
        }
        else if (iVar1 == 4) {
          iVar1 = *param_1;
          pcVar2 = "player/pain4.wav";
        }
        else if (iVar1 == 5) {
          iVar1 = *param_1;
          pcVar2 = "player/pain5.wav";
        }
        else {
          iVar1 = *param_1;
          pcVar2 = "player/pain6.wav";
        }
        *(int *)(iVar1 + 0x1e8) = (int)pcVar2 - (int)gpGlobals[0x26];
        uVar4 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = (char *)(*(int *)(*param_1 + 0x1e8) + (int)gpGlobals[0x26]);
      }
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar4,2,pcVar2,0x3f800000,0x3f4ccccd,0,100);
  }
  return;
}


// PainSound__12CBaseMonster  @ 000c2f68
void PainSound__12CBaseMonster(void)

{
  return;
}


