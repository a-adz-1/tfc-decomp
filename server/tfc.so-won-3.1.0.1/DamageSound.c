// DamageSound__10CBreakable  @ 0009de64
void DamageSound__10CBreakable(int *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  longdouble lVar4;
  char *local_18 [4];
  char *pcStack_8;
  char *pcStack_4;
  
  iVar3 = param_1[0xf8];
  iVar1 = (*DAT_001a7fa8)(0,2);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001a7fa8)(0,0x22);
    iVar1 = iVar1 + 0x5f;
  }
  else {
    iVar1 = 100;
  }
  lVar4 = (longdouble)(*DAT_001a7fac)(0x3f400000,0x3f800000);
  if ((iVar3 == 6) && (iVar2 = (*DAT_001a7fa8)(0,1), iVar2 != 0)) {
    iVar3 = 2;
  }
  switch(iVar3) {
  case 0:
  case 6:
  case 7:
    local_18[0] = "debris/glass1.wav";
    local_18[1] = "debris/glass2.wav";
    local_18[2] = "debris/glass3.wav";
    break;
  case 1:
    local_18[0] = "debris/wood1.wav";
    local_18[1] = "debris/wood2.wav";
    local_18[2] = "debris/wood3.wav";
    break;
  case 2:
    local_18[0] = "debris/metal1.wav";
    local_18[1] = "debris/metal3.wav";
    local_18[2] = "debris/metal2.wav";
    unaff_ESI = 2;
    goto LAB_0009e012;
  case 3:
    local_18[0] = "debris/flesh1.wav";
    local_18[1] = "debris/flesh2.wav";
    local_18[2] = "debris/flesh3.wav";
    local_18[3] = "debris/flesh5.wav";
    pcStack_8 = "debris/flesh6.wav";
    pcStack_4 = "debris/flesh7.wav";
    unaff_ESI = 6;
    goto LAB_0009e012;
  case 4:
  case 8:
    local_18[0] = "debris/concrete1.wav";
    local_18[1] = "debris/concrete2.wav";
    local_18[2] = "debris/concrete3.wav";
    break;
  case 5:
    unaff_ESI = 0;
  default:
    if (unaff_ESI == 0) {
      return;
    }
    goto LAB_0009e012;
  }
  unaff_ESI = 3;
LAB_0009e012:
  iVar3 = (*DAT_001a7fa8)(0,unaff_ESI + -1,(float)lVar4,0x3f4ccccd,0,iVar1);
  EMIT_SOUND_DYN__FP7edict_siPCcffii(*(undefined4 *)(*param_1 + 0x208),2,local_18[iVar3]);
  return;
}


