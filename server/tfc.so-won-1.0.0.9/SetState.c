// SetState__12CBaseMonster12MONSTERSTATE  @ 000c89d0
void SetState__12CBaseMonster12MONSTERSTATE(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 1) {
    iVar1 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x470);
    if (iVar1 != 0) {
      __as__7EHANDLEP11CBaseEntity(param_1 + 0x470,0);
      (*DAT_001755b4)(2,"Stripped\n");
    }
  }
  *(int *)(param_1 + 0x4e8) = param_2;
  *(int *)(param_1 + 0x4ec) = param_2;
  return;
}


