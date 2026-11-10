// GravityTouch__15CTriggerGravityP11CBaseEntity  @ 00112370
void GravityTouch__15CTriggerGravityP11CBaseEntity(int *param_1,int *param_2)

{
  if ((*(byte *)(*param_2 + 0x184) & 8) != 0) {
    *(undefined4 *)(*param_2 + 0xfc) = *(undefined4 *)(*param_1 + 0xfc);
  }
  return;
}


