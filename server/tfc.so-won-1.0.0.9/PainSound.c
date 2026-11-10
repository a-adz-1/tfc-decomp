// PainSound__11CBasePlayer  @ 000d64b0
void PainSound__11CBasePlayer(int *param_1)

{
  float *pfVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  iVar2 = *param_1;
  if (0.0 <= *(float *)(iVar2 + 0x140)) {
    if ((*(int *)(iVar2 + 0x1a4) == -3) && (*(int *)(iVar2 + 0x1a0) == 3)) {
      lVar3 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
      lVar4 = (longdouble)0.5;
      if ((byte)(lVar4 < lVar3 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar4 == lVar3) << 0xe) >> 8)) == 1) {
        uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
        pcVar6 = "player/drown1.wav";
      }
      else {
        uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
        pcVar6 = "player/drown2.wav";
      }
    }
    else {
      if (*gpGlobals < *(float *)(*param_1 + 0x1e0)) {
        param_1[0xc0] = 0;
        return;
      }
      *(float *)(*param_1 + 0x1e0) = *gpGlobals + 0.5;
      if (param_1[0xc0] == 1) {
        param_1[0xc0] = 0;
        uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
        pcVar6 = "player/axhit1.wav";
      }
      else {
        iVar2 = (*DAT_00175628)(1,6);
        pfVar1 = gpGlobals;
        *(int *)(*param_1 + 0x1c8) = (int)&DAT_00139266 - (int)gpGlobals[0x26];
        if (iVar2 == 1) {
          *(int *)(*param_1 + 0x1c8) = (int)"player/pain1.wav" - (int)pfVar1[0x26];
        }
        else {
          if (iVar2 == 2) {
            iVar2 = *param_1;
            pcVar6 = "player/pain2.wav";
          }
          else if (iVar2 == 3) {
            iVar2 = *param_1;
            pcVar6 = "player/pain3.wav";
          }
          else if (iVar2 == 4) {
            iVar2 = *param_1;
            pcVar6 = "player/pain4.wav";
          }
          else if (iVar2 == 5) {
            iVar2 = *param_1;
            pcVar6 = "player/pain5.wav";
          }
          else {
            iVar2 = *param_1;
            pcVar6 = "player/pain6.wav";
          }
          *(int *)(iVar2 + 0x1c8) = (int)pcVar6 - (int)gpGlobals[0x26];
        }
        uVar5 = *(undefined4 *)(*param_1 + 0x1e8);
        pcVar6 = (char *)(*(int *)(*param_1 + 0x1c8) + (int)gpGlobals[0x26]);
      }
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,2,pcVar6,0x3f800000,0x3f4ccccd,0,100);
  }
  return;
}


// PainSound__12CBaseMonster  @ 000c85b0
void PainSound__12CBaseMonster(void)

{
  return;
}


