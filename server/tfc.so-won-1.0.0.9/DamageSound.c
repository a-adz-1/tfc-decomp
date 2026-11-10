// DamageSound__10CBreakable  @ 000b2620
void DamageSound__10CBreakable(int *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  longdouble lVar4;
  char *local_1c [4];
  char *local_c;
  char *local_8;
  
  iVar3 = param_1[0xf5];
  iVar1 = (*DAT_00175628)(0,2);
  if (iVar1 == 0) {
    iVar1 = (*DAT_00175628)(0,0x22);
    iVar1 = iVar1 + 0x5f;
  }
  else {
    iVar1 = 100;
  }
  lVar4 = (longdouble)(*DAT_0017562c)(0x3f400000,0x3f800000);
  if ((iVar3 == 6) && (iVar2 = (*DAT_00175628)(0,1), iVar2 != 0)) {
    iVar3 = 2;
  }
  switch(iVar3) {
  case 0:
  case 6:
  case 7:
    local_1c[0] = "debris/glass1.wav";
    local_1c[1] = "debris/glass2.wav";
    local_1c[2] = "debris/glass3.wav";
    unaff_EBX = 3;
    break;
  case 1:
    local_1c[0] = "debris/wood1.wav";
    local_1c[1] = "debris/wood2.wav";
    local_1c[2] = "debris/wood3.wav";
    unaff_EBX = 3;
    break;
  case 2:
    local_1c[0] = "debris/metal1.wav";
    local_1c[1] = "debris/metal3.wav";
    local_1c[2] = "debris/metal2.wav";
    unaff_EBX = 2;
    break;
  case 3:
    local_1c[0] = "debris/flesh1.wav";
    local_1c[1] = "debris/flesh2.wav";
    local_1c[2] = "debris/flesh3.wav";
    local_1c[3] = "debris/flesh5.wav";
    local_c = "debris/flesh6.wav";
    local_8 = "debris/flesh7.wav";
    unaff_EBX = 6;
    break;
  case 4:
  case 8:
    local_1c[0] = "debris/concrete1.wav";
    local_1c[1] = "debris/concrete2.wav";
    local_1c[2] = "debris/concrete3.wav";
    unaff_EBX = 3;
    break;
  case 5:
    unaff_EBX = 0;
  default:
    if (unaff_EBX == 0) {
      return;
    }
  }
  iVar3 = (*DAT_00175628)(0,unaff_EBX + -1,(float)lVar4,0x3f4ccccd,0,iVar1);
  EMIT_SOUND_DYN__FP7edict_siPCcffii(*(undefined4 *)(*param_1 + 0x1e8),2,local_1c[iVar3]);
  return;
}


