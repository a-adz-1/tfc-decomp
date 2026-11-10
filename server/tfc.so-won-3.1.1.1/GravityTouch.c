// GravityTouch__15CTriggerGravityP11CBaseEntity  @ 00118130
void GravityTouch__15CTriggerGravityP11CBaseEntity(int *param_1,int *param_2)

{
  if ((*(byte *)(*param_2 + 0x1a4) & 8) != 0) {
    *(undefined4 *)(*param_2 + 0x11c) = *(undefined4 *)(*param_1 + 0x11c);
  }
  return;
}


