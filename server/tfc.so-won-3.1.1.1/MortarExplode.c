// MortarExplode__7CMortar  @ 000c3b9c
void MortarExplode__7CMortar(int *param_1)

{
  int iVar1;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  float fStack_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  float fStack_40;
  undefined1 auStack_3c [20];
  undefined1 auStack_28 [36];
  
  (*DAT_0019f758)(0,0x17,0,0);
  (*DAT_0019f760)(0);
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(float *)(*param_1 + 0x10) + 1024.0);
  (*DAT_0019f768)(param_1[0x1ae]);
  (*DAT_0019f760)(0);
  (*DAT_0019f760)(0);
  (*DAT_0019f760)(1);
  (*DAT_0019f760)(0x28);
  (*DAT_0019f760)(0);
  (*DAT_0019f760)(0xff);
  (*DAT_0019f760)(0xa0);
  (*DAT_0019f760)(100);
  (*DAT_0019f760)(0x80);
  (*DAT_0019f760)(0);
  (*DAT_0019f75c)();
  local_54 = 0;
  local_50 = 0;
  local_4c = 0x44800000;
  iVar1 = *param_1;
  fStack_40 = *(float *)(iVar1 + 0x10) - 1024.0;
  uStack_48 = *(undefined4 *)(iVar1 + 8);
  uStack_44 = *(undefined4 *)(iVar1 + 0xc);
  fStack_58 = *(float *)(iVar1 + 0x10) + 1024.0;
  uStack_60 = *(undefined4 *)(iVar1 + 8);
  uStack_5c = *(undefined4 *)(iVar1 + 0xc);
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&uStack_60,&uStack_48,0,*(undefined4 *)(iVar1 + 0x208),auStack_3c);
  (**(code **)(param_1[0x115] + 0x220))(param_1,auStack_3c,0x800040);
  UTIL_ScreenShake__FRC6Vectorffff(auStack_28,0x41c80000,0x43160000,0x3f800000,0x443b8000);
  return;
}


