// DamageSound__10CBreakable  @ 000a7fa0
void DamageSound__10CBreakable(int *param_1)

{
  int iVar1;
  int unaff_ESI;
  int iVar2;
  longdouble lVar3;
  int local_20;
  char *local_1c [4];
  char *local_c;
  char *local_8;
  
  iVar2 = param_1[0x118];
  iVar1 = (*DAT_0019f808)(0,2);
  if (iVar1 == 0) {
    local_20 = (*DAT_0019f808)(0,0x22);
    local_20 = local_20 + 0x5f;
  }
  else {
    local_20 = 100;
  }
  lVar3 = (longdouble)(*DAT_0019f80c)(0x3f400000,0x3f800000);
  if ((iVar2 == 6) && (iVar1 = (*DAT_0019f808)(0,1), iVar1 != 0)) {
    iVar2 = 2;
  }
  switch(iVar2) {
  case 0:
  case 6:
  case 7:
    local_1c[0] = "debris/glass1.wav";
    local_1c[1] = "debris/glass2.wav";
    local_1c[2] = "debris/glass3.wav";
    break;
  case 1:
    local_1c[0] = "debris/wood1.wav";
    local_1c[1] = "debris/wood2.wav";
    local_1c[2] = "debris/wood3.wav";
    break;
  case 2:
    local_1c[0] = "debris/metal1.wav";
    local_1c[1] = "debris/metal3.wav";
    local_1c[2] = "debris/metal2.wav";
    unaff_ESI = 2;
    goto LAB_000a813e;
  case 3:
    local_1c[0] = "debris/flesh1.wav";
    local_1c[1] = "debris/flesh2.wav";
    local_1c[2] = "debris/flesh3.wav";
    local_1c[3] = "debris/flesh5.wav";
    local_c = "debris/flesh6.wav";
    local_8 = "debris/flesh7.wav";
    unaff_ESI = 6;
    goto LAB_000a813e;
  case 4:
  case 8:
    local_1c[0] = "debris/concrete1.wav";
    local_1c[1] = "debris/concrete2.wav";
    local_1c[2] = "debris/concrete3.wav";
    break;
  case 5:
    unaff_ESI = 0;
  default:
    if (unaff_ESI == 0) {
      return;
    }
    goto LAB_000a813e;
  }
  unaff_ESI = 3;
LAB_000a813e:
  iVar2 = (*DAT_0019f808)(0,unaff_ESI + -1,(float)lVar3,0x3f4ccccd,0,local_20);
  EMIT_SOUND_DYN__FP7edict_siPCcffii(*(undefined4 *)(*param_1 + 0x208),2,local_1c[iVar2]);
  return;
}


