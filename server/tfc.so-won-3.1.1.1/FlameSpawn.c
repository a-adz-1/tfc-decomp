// FlameSpawn__8CTFFlameP11CBaseEntityT1  @ 000e6280
int * FlameSpawn__8CTFFlameP11CBaseEntityT1(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)GetClassPtr__H1Z8CTFFlame_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar1,*param_2 + 8);
  (**(code **)(piVar1[0x115] + 0xc))(piVar1);
  *(undefined4 *)(*piVar1 + 400) = *(undefined4 *)(*param_2 + 0x208);
  *(undefined4 *)(*piVar1 + 0x198) = *(undefined4 *)(*param_1 + 0x208);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*piVar1 + 0x208),2,"ambience/fire1.wav",0x3f800000,0x3f000000,0,100);
  (*DAT_0019f758)(4,0x17,*param_2 + 8,0);
  (*DAT_0019f760)(0x79);
  uVar2 = (*DAT_0019f7bc)(*(undefined4 *)(*param_2 + 0x208));
  (*DAT_0019f768)(uVar2);
  (*DAT_0019f768)((int)g_sModelIndexPlayerFlame);
  (*DAT_0019f760)(5);
  (*DAT_0019f760)(0x19);
  (*DAT_0019f75c)();
  *(undefined4 *)(*piVar1 + 0x108) = 0xc;
  *(undefined4 *)(*piVar1 + 0x194) = *(undefined4 *)(*param_2 + 0x208);
  return piVar1;
}


