// DeathSound__11CBasePlayer  @ 000d6880
void DeathSound__11CBasePlayer(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if (*(int *)(*param_1 + 0x1a0) == 3) {
    uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
    uVar4 = 0;
    pcVar3 = "player/h2odeath.wav";
  }
  else {
    iVar1 = (*DAT_00175628)(1,4);
    if (iVar1 == 2) {
      uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
      uVar4 = 0x3f4ccccd;
      pcVar3 = "player/death3.wav";
    }
    else if (iVar1 < 3) {
      if (iVar1 != 1) {
        return;
      }
      uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
      uVar4 = 0x3f4ccccd;
      pcVar3 = "player/death1.wav";
    }
    else if (iVar1 == 3) {
      uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
      uVar4 = 0x3f4ccccd;
      pcVar3 = "player/death4.wav";
    }
    else {
      if (iVar1 != 4) {
        return;
      }
      uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
      uVar4 = 0x3f4ccccd;
      pcVar3 = "player/death5.wav";
    }
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar2,2,pcVar3,0x3f800000,uVar4,0,100);
  return;
}


// DeathSound__12CBaseMonster  @ 000c85e0
void DeathSound__12CBaseMonster(void)

{
  return;
}


