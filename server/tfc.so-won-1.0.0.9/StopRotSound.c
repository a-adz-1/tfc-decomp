// StopRotSound__9CFuncTank  @ 000b5920
void StopRotSound__9CFuncTank(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(short *)(iVar1 + 0x180) < 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(iVar1 + 0x1e8),6,*(int *)(iVar1 + 0x1c8) + *(int *)(gpGlobals + 0x98)
               ,0,0,0x20,100);
  }
  *(byte *)(*param_1 + 0x181) = *(byte *)(*param_1 + 0x181) & 0x7f;
  return;
}


