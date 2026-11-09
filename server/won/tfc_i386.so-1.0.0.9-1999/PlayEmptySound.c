// PlayEmptySound__17CBasePlayerWeapon  @ 0011bbe0
undefined4 PlayEmptySound__17CBasePlayerWeapon(int param_1)

{
  if (*(int *)(param_1 + 0x3f4) != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),1,"weapons/357_cock1.wav",
               0x3f4ccccd,0x3f4ccccd,0,100);
    *(undefined4 *)(param_1 + 0x3f4) = 0;
  }
  return 0;
}


