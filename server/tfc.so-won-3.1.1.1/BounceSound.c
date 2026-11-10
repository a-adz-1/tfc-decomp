// BounceSound__8CGrenade  @ 000b1528
void BounceSound__8CGrenade(int *param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  iVar1 = (*DAT_0019f808)(0,2);
  if (iVar1 == 1) {
    uVar3 = *(undefined4 *)(*param_1 + 0x208);
    pcVar2 = (code *)"weapons/grenade_hit2.wav";
  }
  else if (iVar1 < 2) {
    if (iVar1 != 0) {
      return;
    }
    uVar3 = *(undefined4 *)(*param_1 + 0x208);
    pcVar2 = FUN_0014c1c0;
  }
  else {
    if (iVar1 != 2) {
      return;
    }
    uVar3 = *(undefined4 *)(*param_1 + 0x208);
    pcVar2 = (code *)"weapons/grenade_hit3.wav";
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar3,2,pcVar2,0x3e800000,0x3f4ccccd,0,100);
  return;
}


