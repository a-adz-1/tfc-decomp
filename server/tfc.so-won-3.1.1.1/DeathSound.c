// DeathSound__11CBasePlayer  @ 000d3c94
void DeathSound__11CBasePlayer(int *param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (*(int *)(*param_1 + 0x1c0) == 3) {
    uVar1 = *(undefined4 *)(*param_1 + 0x208);
    uVar3 = 0;
    pcVar2 = "player/h2odeath.wav";
  }
  else {
    uVar1 = (*DAT_0019f808)(1,4);
    switch(uVar1) {
    case 1:
      uVar1 = *(undefined4 *)(*param_1 + 0x208);
      uVar3 = 0x3f4ccccd;
      pcVar2 = "player/death1.wav";
      break;
    case 2:
      uVar1 = *(undefined4 *)(*param_1 + 0x208);
      uVar3 = 0x3f4ccccd;
      pcVar2 = "player/death3.wav";
      break;
    case 3:
      uVar1 = *(undefined4 *)(*param_1 + 0x208);
      uVar3 = 0x3f4ccccd;
      pcVar2 = "player/death4.wav";
      break;
    case 4:
      uVar1 = *(undefined4 *)(*param_1 + 0x208);
      uVar3 = 0x3f4ccccd;
      pcVar2 = "player/death5.wav";
      break;
    default:
      goto switchD_000d3cfa_default;
    }
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar1,2,pcVar2,0x3f800000,uVar3,0,100);
switchD_000d3cfa_default:
  return;
}


// DeathSound__12CBaseMonster  @ 000c2f80
void DeathSound__12CBaseMonster(void)

{
  return;
}


