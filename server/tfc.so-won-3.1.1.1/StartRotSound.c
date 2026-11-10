// StartRotSound__9CFuncTank  @ 000ac6d0
void StartRotSound__9CFuncTank(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((*(int *)(iVar1 + 0x1e8) != 0) && (-1 < *(short *)(iVar1 + 0x1a0))) {
    *(byte *)(iVar1 + 0x1a1) = *(byte *)(iVar1 + 0x1a1) | 0x80;
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,
               *(int *)(*param_1 + 0x1e8) + *(int *)(gpGlobals + 0x98),0x3f59999a,0x3f4ccccd,0,100);
  }
  return;
}


