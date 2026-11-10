// FallThink__15CBasePlayerItem  @ 0010ff34
void FallThink__15CBasePlayerItem(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  if ((*(byte *)(*param_1 + 0x1a5) & 2) != 0) {
    iVar2 = *(int *)(*param_1 + 0x198);
    bVar1 = false;
    if ((iVar2 == 0) || (iVar2 = (*DAT_001a7f58)(iVar2), iVar2 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      iVar2 = (*DAT_001a7fa8)(0,0x1d);
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x208),2,"items/weapondrop1.wav",0x3f800000,0x3f4ccccd,0
                 ,iVar2 + 0x5f);
    }
    *(undefined4 *)(*param_1 + 0x50) = 0;
    *(undefined4 *)(*param_1 + 0x58) = 0;
    Materialize__15CBasePlayerItem(param_1);
    return;
  }
  return;
}


