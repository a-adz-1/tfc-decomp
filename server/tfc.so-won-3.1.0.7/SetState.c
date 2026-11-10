// SetState__12CBaseMonster12MONSTERSTATE  @ 000c2a5c
void SetState__12CBaseMonster12MONSTERSTATE(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 1) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4ec);
    if (iVar1 != 0) {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x4ec,0);
      (*DAT_001c1114)(2,"Stripped\n");
    }
  }
  *(int *)(param_1 + 0x564) = param_2;
  *(int *)(param_1 + 0x568) = param_2;
  return;
}


