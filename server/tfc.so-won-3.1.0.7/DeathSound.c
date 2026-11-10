// DeathSound__11CBasePlayer  @ 000d39d8
void DeathSound__11CBasePlayer(int *param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (*(int *)(*param_1 + 0x1c0) == 3) {
    uVar1 = *(undefined4 *)(*param_1 + 0x208);
    pcVar2 = "player/h2odeath.wav";
    uVar3 = 0;
  }
  else {
    uVar1 = (*DAT_001c1188)(1,4);
    switch(uVar1) {
    case 1:
      uVar1 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/death1.wav";
      break;
    case 2:
      uVar1 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/death3.wav";
      break;
    case 3:
      uVar1 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = (char *)FUN_0014ae3c;
      break;
    case 4:
      uVar1 = *(undefined4 *)(*param_1 + 0x208);
      pcVar2 = "player/death5.wav";
      break;
    default:
      goto LAB_000d3a9c;
    }
    uVar3 = 0x3f4ccccd;
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar1,2,pcVar2,0x3f800000,uVar3,0,100);
LAB_000d3a9c:
  return;
}


// DeathSound__12CBaseMonster  @ 000c26ac
void DeathSound__12CBaseMonster(void)

{
  return;
}


