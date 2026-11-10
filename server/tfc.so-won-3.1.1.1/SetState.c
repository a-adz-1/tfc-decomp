// SetState__12CBaseMonster12MONSTERSTATE  @ 000c3700
void SetState__12CBaseMonster12MONSTERSTATE(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 1) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
    if (iVar1 != 0) {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x4fc,0);
      (*DAT_0019f794)(2,"Stripped\n");
    }
  }
  *(int *)(param_1 + 0x574) = param_2;
  *(int *)(param_1 + 0x578) = param_2;
  return;
}


