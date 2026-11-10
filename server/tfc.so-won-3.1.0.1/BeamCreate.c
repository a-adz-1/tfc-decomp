// BeamCreate__5CBeamPCci  @ 00095cf0
undefined4 * BeamCreate__5CBeamPCci(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)GetClassPtr__H1Z5CBeam_PX01_PX01(0);
  *(int *)*puVar1 = (int)&DAT_00134870 - *(int *)(gpGlobals + 0x98);
  BeamInit__5CBeamPCci(puVar1,param_1,param_2);
  return puVar1;
}


