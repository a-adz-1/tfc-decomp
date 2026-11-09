// PlaySound__10CTFMedikitif  @ 000fa300
void PlaySound__10CTFMedikitif(void)

{
  return;
}


// PlaySound__19CMomentaryRotButton  @ 0009f5a0
void PlaySound__19CMomentaryRotButton(int *param_1)

{
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),2,
             *(int *)(*param_1 + 0x1c8) + *(int *)(gpGlobals + 0x98),0x3f800000,0x3f4ccccd,0,100);
  return;
}


// PlaySound__6CTFAxeif  @ 000f8a80
void PlaySound__6CTFAxeif(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uStack_28;
  char *pcStack_24;
  undefined4 uStack_20;
  char *pcStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (param_2 == 1) {
    uStack_c = 2;
    uStack_10 = 0;
    iStack_14 = 0xf8aeb;
    iVar1 = (*DAT_00175628)();
    if (iVar1 == 1) {
      uVar2 = *(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8);
      uStack_c = 100;
      uStack_10 = 0;
      iStack_14 = 0x3f4ccccd;
      uStack_18 = 0x3f800000;
      pcStack_1c = "weapons/cbar_hitbod2.wav";
      puVar3 = &uStack_20;
      uStack_20 = 1;
    }
    else if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      uVar2 = *(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8);
      uStack_c = 100;
      uStack_10 = 0;
      iStack_14 = 0x3f4ccccd;
      uStack_18 = 0x3f800000;
      pcStack_1c = "weapons/cbar_hitbod1.wav";
      puVar3 = &uStack_20;
      uStack_20 = 1;
    }
    else {
      if (iVar1 != 2) {
        return;
      }
      uVar2 = *(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8);
      uStack_c = 100;
      uStack_10 = 0;
      iStack_14 = 0x3f4ccccd;
      uStack_18 = 0x3f800000;
      pcStack_1c = "weapons/cbar_hitbod3.wav";
      puVar3 = &uStack_20;
      uStack_20 = 1;
    }
  }
  else {
    if (param_2 < 2) {
      if (param_2 != 0) {
        return;
      }
      uStack_c = 0xf;
      uStack_10 = 0;
      iStack_14 = 0xf8abb;
      iStack_14 = (*DAT_00175628)();
      iStack_14 = iStack_14 + 0x5e;
      uStack_20 = 0x3f800000;
      pcStack_24 = "weapons/cbar_miss1.wav";
      uStack_28 = 1;
    }
    else {
      if (param_2 != 2) {
        return;
      }
      uStack_c = 1;
      uStack_10 = 0;
      iStack_14 = 0xf8bab;
      iVar1 = (*DAT_00175628)();
      if (iVar1 == 0) {
        uStack_c = 3;
        uStack_10 = 0;
        iStack_14 = 0xf8bcb;
        iStack_14 = (*DAT_00175628)();
        pcStack_24 = "weapons/cbar_hit1.wav";
      }
      else {
        if (iVar1 != 1) {
          return;
        }
        uStack_c = 3;
        uStack_10 = 0;
        iStack_14 = 0xf8beb;
        iStack_14 = (*DAT_00175628)();
        pcStack_24 = "weapons/cbar_hit2.wav";
      }
      iStack_14 = iStack_14 + 0x62;
      uStack_20 = param_3;
      uStack_28 = 3;
    }
    uStack_18 = 0;
    pcStack_1c = (char *)0x3f4ccccd;
    puVar3 = &uStack_28;
    uVar2 = *(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8);
  }
  *(undefined4 *)((int)puVar3 + -4) = uVar2;
  *(undefined4 *)((int)puVar3 + -8) = 0xf8c14;
  EMIT_SOUND_DYN__FP7edict_siPCcffii();
  return;
}


