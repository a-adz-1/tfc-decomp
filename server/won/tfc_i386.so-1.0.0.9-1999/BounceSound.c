// BounceSound__8CGrenade  @ 000b9920
void BounceSound__8CGrenade(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  iVar1 = (*DAT_00175628)(0,2);
  if (iVar1 == 1) {
    uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
    pcVar3 = "weapons/grenade_hit2.wav";
  }
  else if (iVar1 < 2) {
    if (iVar1 != 0) {
      return;
    }
    uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
    pcVar3 = "weapons/grenade_hit1.wav";
  }
  else {
    if (iVar1 != 2) {
      return;
    }
    uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
    pcVar3 = "weapons/grenade_hit3.wav";
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar2,2,pcVar3,0x3e800000,0x3f4ccccd,0,100);
  return;
}


