// BeamInit__5CBeamPCci  @ 000ab830
void BeamInit__5CBeamPCci(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *(byte *)(*param_1 + 0x187) = *(byte *)(*param_1 + 0x187) | 0x20;
  *(undefined4 *)(*param_1 + 0x130) = 0x437f0000;
  *(undefined4 *)(*param_1 + 0x134) = 0x437f0000;
  *(undefined4 *)(*param_1 + 0x138) = 0x437f0000;
  *(undefined4 *)(*param_1 + 300) = 0x437f0000;
  *(undefined4 *)(*param_1 + 0xf4) = 0;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  *(undefined4 *)(*param_1 + 0x114) = 0;
  *(int *)(*param_1 + 0x98) = param_2 - *(int *)(gpGlobals + 0x98);
  uVar1 = (*g_engfuncs)(param_2);
  *(undefined4 *)(*param_1 + 0x94) = uVar1;
  *(float *)(*param_1 + 0x124) = (float)param_3;
  *(undefined4 *)(*param_1 + 0xf0) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  return;
}


