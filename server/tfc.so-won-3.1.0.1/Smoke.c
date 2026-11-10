// Smoke__13CEnvExplosion  @ 0009d4e4
void Smoke__13CEnvExplosion(int *param_1)

{
  if ((*(byte *)(*param_1 + 0x1a0) & 8) == 0) {
    (*DAT_001a7ef8)(5,0x17,*param_1 + 8,0);
    (*DAT_001a7f00)(5);
    (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 8));
    (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0xc));
    (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0x10));
    (*DAT_001a7f08)((int)g_sModelIndexSmoke);
    (*DAT_001a7f00)((char)param_1[0x188]);
    (*DAT_001a7f00)(0xc);
    (*DAT_001a7efc)();
  }
  if ((*(byte *)(*param_1 + 0x1a0) & 2) == 0) {
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


// Smoke__8CGrenade  @ 000a6960
void Smoke__8CGrenade(void)

{
  FUN_000a696a();
  return;
}


