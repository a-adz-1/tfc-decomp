// BounceSound__8CGrenade  @ 000a728c
void BounceSound__8CGrenade(int *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  iVar1 = (*DAT_001a7fa8)(0,2);
  if (iVar1 == 1) {
    uVar3 = *(undefined4 *)(*param_1 + 0x208);
    pcVar2 = "weapons/grenade_hit2.wav";
  }
  else if (iVar1 < 2) {
    if (iVar1 != 0) {
      return;
    }
    uVar3 = *(undefined4 *)(*param_1 + 0x208);
    pcVar2 = "weapons/grenade_hit1.wav";
  }
  else {
    if (iVar1 != 2) {
      return;
    }
    uVar3 = *(undefined4 *)(*param_1 + 0x208);
    pcVar2 = "weapons/grenade_hit3.wav";
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar3,2,pcVar2,0x3e800000,0x3f4ccccd,0,100);
  return;
}


