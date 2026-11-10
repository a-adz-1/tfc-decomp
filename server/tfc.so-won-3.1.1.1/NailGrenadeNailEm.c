// NailGrenadeNailEm__14CTFNailGrenade  @ 0010138c
void NailGrenadeNailEm__14CTFNailGrenade(int *param_1)

{
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  param_1[3] = -0x10000;
  param_1[4] = (int)NailGrenadeLaunchNail__14CTFNailGrenade;
  *(undefined4 *)(*param_1 + 0x20c) = 0;
  return;
}


