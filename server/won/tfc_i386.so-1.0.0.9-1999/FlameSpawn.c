// FlameSpawn__8CTFFlameP11CBaseEntityT1  @ 000e4610
int * FlameSpawn__8CTFFlameP11CBaseEntityT1(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)GetClassPtr__H1Z8CTFFlame_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar1,*param_2 + 8);
  (**(code **)(piVar1[0xf2] + 8))(piVar1);
  *(undefined4 *)(*piVar1 + 0x170) = *(undefined4 *)(*param_2 + 0x1e8);
  *(undefined4 *)(*piVar1 + 0x178) = *(undefined4 *)(*param_1 + 0x1e8);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*piVar1 + 0x1e8),2,"ambience/fire1.wav",0x3f800000,0x3f000000,0,100);
  (*DAT_00175578)(4,0x17,*param_2 + 8,0);
  (*DAT_00175580)(0x79);
  uVar2 = (*DAT_001755dc)(*(undefined4 *)(*param_2 + 0x1e8));
  (*DAT_00175588)(uVar2);
  (*DAT_00175588)((int)g_sModelIndexPlayerFlame);
  (*DAT_00175580)(5);
  (*DAT_00175580)(0x19);
  (*DAT_0017557c)();
  *(undefined4 *)(*piVar1 + 0xe8) = 0xc;
  *(undefined4 *)(*piVar1 + 0x174) = *(undefined4 *)(*param_2 + 0x1e8);
  return piVar1;
}


