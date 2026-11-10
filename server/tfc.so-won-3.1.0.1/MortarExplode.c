// MortarExplode__7CMortar  @ 000b829c
void MortarExplode__7CMortar(int *param_1)

{
  int iVar1;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  undefined1 local_38 [20];
  undefined1 local_24 [36];
  
  (*DAT_001a7ef8)(0,0x17,0,0);
  (*DAT_001a7f00)(0);
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 8));
  (*DAT_001a7f14)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_001a7f14)(*(float *)(*param_1 + 0x10) + 1024.0);
  (*DAT_001a7f08)(param_1[0x18e]);
  (*DAT_001a7f00)(0);
  (*DAT_001a7f00)(0);
  (*DAT_001a7f00)(1);
  (*DAT_001a7f00)(0x28);
  (*DAT_001a7f00)(0);
  (*DAT_001a7f00)(0xff);
  (*DAT_001a7f00)(0xa0);
  (*DAT_001a7f00)(100);
  (*DAT_001a7f00)(0x80);
  (*DAT_001a7f00)(0);
  (*DAT_001a7efc)();
  local_50 = 0;
  local_4c = 0;
  local_48 = 0x44800000;
  iVar1 = *param_1;
  local_44 = *(undefined4 *)(iVar1 + 8);
  local_40 = *(undefined4 *)(iVar1 + 0xc);
  local_3c = *(float *)(iVar1 + 0x10) - 1024.0;
  local_5c = *(undefined4 *)(iVar1 + 8);
  local_58 = *(undefined4 *)(iVar1 + 0xc);
  local_54 = *(float *)(iVar1 + 0x10) + 1024.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_5c,&local_44,0,*(undefined4 *)(iVar1 + 0x208),local_38);
  (**(code **)(param_1[0xf5] + 0x218))(param_1,local_38,0x800040);
  UTIL_ScreenShake__FRC6Vectorffff(local_24,0x41c80000,0x43160000,0x3f800000,0x443b8000);
  return;
}


