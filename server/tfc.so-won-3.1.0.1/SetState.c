// SetState__12CBaseMonster12MONSTERSTATE  @ 000b77bc
void SetState__12CBaseMonster12MONSTERSTATE(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 1) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x47c);
    if (iVar1 != 0) {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x47c,0);
      (*DAT_001a7f34)(2,"Stripped\n");
    }
  }
  *(int *)(param_1 + 0x4f4) = param_2;
  *(int *)(param_1 + 0x4f8) = param_2;
  return;
}


