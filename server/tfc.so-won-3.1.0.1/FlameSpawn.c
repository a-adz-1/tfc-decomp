// FlameSpawn__8CTFFlameP11CBaseEntityT1  @ 000d8e68
int * FlameSpawn__8CTFFlameP11CBaseEntityT1(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)GetClassPtr__H1Z8CTFFlame_PX01_PX01(0);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar1,*param_2 + 8);
  (**(code **)(piVar1[0xf5] + 8))(piVar1);
  *(undefined4 *)(*piVar1 + 400) = *(undefined4 *)(*param_2 + 0x208);
  *(undefined4 *)(*piVar1 + 0x198) = *(undefined4 *)(*param_1 + 0x208);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*piVar1 + 0x208),2,"ambience/fire1.wav",0x3f800000,0x3f000000,0,100);
  (*DAT_001a7ef8)(4,0x17,*param_2 + 8,0);
  (*DAT_001a7f00)(0x79);
  uVar2 = (*DAT_001a7f5c)(*(undefined4 *)(*param_2 + 0x208));
  (*DAT_001a7f08)(uVar2);
  (*DAT_001a7f08)((int)g_sModelIndexPlayerFlame);
  (*DAT_001a7f00)(5);
  (*DAT_001a7f00)(0x19);
  (*DAT_001a7efc)();
  *(undefined4 *)(*piVar1 + 0x108) = 0xc;
  *(undefined4 *)(*piVar1 + 0x194) = *(undefined4 *)(*param_2 + 0x208);
  return piVar1;
}


