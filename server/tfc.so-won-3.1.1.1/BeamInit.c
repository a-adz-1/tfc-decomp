// BeamInit__5CBeamPCci  @ 000a5544
void BeamInit__5CBeamPCci(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 0x20;
  *(undefined4 *)(*param_1 + 0x150) = 0x437f0000;
  *(undefined4 *)(*param_1 + 0x154) = 0x437f0000;
  *(undefined4 *)(*param_1 + 0x158) = 0x437f0000;
  *(undefined4 *)(*param_1 + 0x14c) = 0x437f0000;
  *(undefined4 *)(*param_1 + 0x114) = 0;
  *(undefined4 *)(*param_1 + 0x130) = 0;
  *(undefined4 *)(*param_1 + 0x134) = 0;
  *(int *)(*param_1 + 0xb8) = param_2 - *(int *)(gpGlobals + 0x98);
  uVar1 = (*g_engfuncs)(param_2);
  *(undefined4 *)(*param_1 + 0xb4) = uVar1;
  *(float *)(*param_1 + 0x144) = (float)param_3;
  *(undefined4 *)(*param_1 + 0x110) = 0;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  *(undefined4 *)(*param_1 + 0x148) = 0;
  return;
}


