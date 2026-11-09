// MortarExplode__7CMortar  @ 000c9310
void MortarExplode__7CMortar(int *param_1)

{
  int iVar1;
  float local_60;
  float fStack_5c;
  float fStack_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 auStack_3c [20];
  undefined1 auStack_28 [36];
  
  (*DAT_00175578)(0,0x17,0,0);
  (*DAT_00175580)(0);
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 8));
  (*DAT_00175594)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_00175594)(*(float *)(*param_1 + 0x10) + 1024.0);
  (*DAT_00175588)(param_1[0x189]);
  (*DAT_00175580)(0);
  (*DAT_00175580)(0);
  (*DAT_00175580)(1);
  (*DAT_00175580)(0x28);
  (*DAT_00175580)(0);
  (*DAT_00175580)(0xff);
  (*DAT_00175580)(0xa0);
  (*DAT_00175580)(100);
  (*DAT_00175580)(0x80);
  (*DAT_00175580)(0);
  (*DAT_0017557c)();
  local_54 = 0;
  local_50 = 0;
  local_4c = 0x44800000;
  iVar1 = *param_1;
  local_48 = *(float *)(iVar1 + 8) - 0.0;
  local_44 = *(float *)(iVar1 + 0xc) - 0.0;
  local_40 = *(float *)(iVar1 + 0x10) - 1024.0;
  local_60 = *(float *)(iVar1 + 8) + 0.0;
  fStack_5c = *(float *)(iVar1 + 0xc) + 0.0;
  fStack_58 = *(float *)(iVar1 + 0x10) + 1024.0;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_60,&local_48,0,*(undefined4 *)(iVar1 + 0x1e8),auStack_3c);
  (**(code **)(param_1[0xf2] + 0x218))(param_1,auStack_3c,0x800040);
  UTIL_ScreenShake__FRC6Vectorffff(auStack_28,0x41c80000,0x43160000,0x3f800000,0x443b8000);
  return;
}


