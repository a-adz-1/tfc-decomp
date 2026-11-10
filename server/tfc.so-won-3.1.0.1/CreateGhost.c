// CreateGhost__11CBasePlayer  @ 000eb488
void CreateGhost__11CBasePlayer(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                            ("ghost",&g_vecZero,&g_vecZero,*(undefined4 *)(*param_1 + 0x208));
  piVar1[0x7d] = param_1[0x7d];
  piVar1[0x48] = param_1[0x48];
  *(undefined4 *)(*piVar1 + 0x164) = *(undefined4 *)(*param_1 + 0x164);
  piVar1[0x4b] = param_1[0x4b];
  *(undefined4 *)(*piVar1 + 0x1d0) = *(undefined4 *)(*param_1 + 0x1d0);
  *(undefined4 *)(*piVar1 + 0x20c) = *(undefined4 *)(*param_1 + 0x20c);
  if ((*(byte *)(param_1 + 0x21) & 8) != 0) {
    piVar1[0x21] = 8;
  }
  return;
}


