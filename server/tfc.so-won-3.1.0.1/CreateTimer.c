// CreateTimer__11CBaseEntityi  @ 000f4fa8
void CreateTimer__11CBaseEntityi(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Create__11CBaseEntityPcRC6VectorT2P7edict_s
                    ("timer",&g_vecZero,&g_vecZero,*(undefined4 *)(*param_1 + 0x208));
  *(undefined4 *)(iVar1 + 0x3a8) = param_2;
  return;
}


