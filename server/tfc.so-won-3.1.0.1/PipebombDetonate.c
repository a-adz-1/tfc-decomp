// PipebombDetonate__10CTFGrenade  @ 000f470c
void PipebombDetonate__10CTFGrenade(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  undefined1 local_38 [56];
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001a7f54)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_000f474e;
    }
  }
  iVar1 = *(int *)(iVar1 + 0x7c);
LAB_000f474e:
  iVar2 = (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x28))(iVar1);
  if (iVar2 == 2) {
    *(int *)(iVar1 + 0xd14) = *(int *)(iVar1 + 0xd14) + -1;
  }
  iVar1 = *param_1;
  local_5c = *(undefined4 *)(iVar1 + 8);
  local_58 = *(undefined4 *)(iVar1 + 0xc);
  local_3c = *(float *)(iVar1 + 0x10) + 8.0;
  local_48 = 0xc2000000;
  local_50 = 0;
  local_4c = 0;
  local_54 = local_3c + -32.0;
  local_44 = local_5c;
  local_40 = local_58;
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (&local_44,&local_5c,1,*(undefined4 *)(iVar1 + 0x208),local_38);
  (**(code **)(param_1[0xf5] + 0x218))(param_1,local_38,0x4000040);
  return;
}


