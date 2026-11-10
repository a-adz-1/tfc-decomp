// StopRotSound__9CFuncTank  @ 000ac670
void StopRotSound__9CFuncTank(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(short *)(iVar1 + 0x1a0) < 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x208),6,*(int *)(iVar1 + 0x1e8) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
    iVar1 = *param_1;
  }
  *(byte *)(iVar1 + 0x1a1) = *(byte *)(iVar1 + 0x1a1) & 0x7f;
  return;
}


