// MortarExplode__7CMortar  @ 000c353c
void MortarExplode__7CMortar(int *param_1)

{
  int iVar1;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  float fStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  float fStack_3c;
  undefined1 auStack_38 [20];
  undefined1 auStack_24 [36];
  
  (*DAT_001c10d8)(0,0x17,0,0);
  (*DAT_001c10e0)(0);
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001c10f4)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001c10f4)(*(float *)(*param_1 + 0x10) + 1024.0);
  (*DAT_001c10e8)(param_1[0x1aa]);
  (*DAT_001c10e0)(0);
  (*DAT_001c10e0)(0);
  (*DAT_001c10e0)(1);
  (*DAT_001c10e0)(0x28);
  (*DAT_001c10e0)(0);
  (*DAT_001c10e0)(0xff);
  (*DAT_001c10e0)(0xa0);
  (*DAT_001c10e0)(100);
  (*DAT_001c10e0)(0x80);
  (*DAT_001c10e0)(0);
  (*DAT_001c10dc)();
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0x44800000;
  iVar1 = *param_1;
  uStack_44 = *(undefined4 *)(iVar1 + 8);
  uStack_40 = *(undefined4 *)(iVar1 + 0xc);
  fStack_3c = *(float *)(iVar1 + 0x10) - 1024.0;
  uStack_5c = *(undefined4 *)(iVar1 + 8);
  uStack_58 = *(undefined4 *)(iVar1 + 0xc);
  fStack_54 = *(float *)(iVar1 + 0x10) + 1024.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&uStack_5c,&uStack_44,0,*(undefined4 *)(iVar1 + 0x208),auStack_38);
  (**(code **)(param_1[0x111] + 0x220))(param_1,auStack_38,0x800040);
  UTIL_ScreenShake__FRC6Vectorffff(auStack_24,0x41c80000,0x43160000,0x3f800000,0x443b8000);
  return;
}


