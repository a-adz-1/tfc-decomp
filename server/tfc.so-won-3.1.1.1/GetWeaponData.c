// GetWeaponData__FP7edict_sP13weapon_data_s  @ 0009369c
undefined4 GetWeaponData__FP7edict_sP13weapon_data_s(int param_1,void *param_2)

{
  uint *puVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int local_38;
  undefined1 local_30 [32];
  uint local_10;
  
  iVar5 = *(int *)(param_1 + 0x288);
  if ((iVar5 == 0) && (iVar5 = (*DAT_0019f7b4)(0), iVar5 == 0)) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(iVar5 + 0x7c);
  }
  memset(param_2,0,0xb00);
  if (iVar5 != 0) {
    local_38 = 0;
    do {
      for (iVar3 = *(int *)(iVar5 + 0x8c4 + local_38 * 4); iVar3 != 0;
          iVar3 = *(int *)(iVar3 + 0x478)) {
        iVar6 = (**(code **)(*(int *)(iVar3 + 0x454) + 0x150))(iVar3);
        if (iVar6 != 0) {
          memset(local_30,0,0x2c);
          (**(code **)(*(int *)(iVar6 + 0x454) + 0x118))(iVar6,local_30);
          if (local_10 < 0x20) {
            puVar1 = (uint *)((int)param_2 + local_10 * 0x58);
            *puVar1 = local_10;
            puVar1[1] = *(uint *)(iVar6 + 0x4c0);
            fVar2 = *(float *)(iVar6 + 0x498);
            fVar4 = -0.001;
            if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
              fVar2 = fVar4;
            }
            puVar1[8] = (uint)fVar2;
            fVar2 = *(float *)(iVar6 + 0x490);
            if (*(float *)(iVar6 + 0x490) < -0.001) {
              fVar2 = fVar4;
            }
            puVar1[4] = (uint)fVar2;
            fVar2 = *(float *)(iVar6 + 0x488);
            if (*(float *)(iVar6 + 0x488) < -0.001) {
              fVar2 = fVar4;
            }
            puVar1[2] = (uint)fVar2;
            fVar2 = *(float *)(iVar6 + 0x48c);
            if (*(float *)(iVar6 + 0x48c) < -0.001) {
              fVar2 = fVar4;
            }
            puVar1[3] = (uint)fVar2;
            fVar2 = *(float *)(iVar6 + 0x494);
            if (fVar2 < -0.001) {
              fVar2 = fVar4;
            }
            puVar1[7] = (uint)fVar2;
            fVar2 = *(float *)(iVar6 + 0x4a4);
            if (0x3f < (byte)((-1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) - 1)) {
              fVar2 = -1.0;
            }
            puVar1[0xb] = (uint)fVar2;
            puVar1[5] = *(uint *)(iVar6 + 0x4b0);
            puVar1[6] = *(uint *)(iVar6 + 0x4b4);
            puVar1[9] = *(uint *)(iVar6 + 0x49c);
            puVar1[10] = *(uint *)(iVar6 + 0x4a0);
            puVar1[0xc] = *(uint *)(iVar6 + 0x4a8);
            puVar1[0xd] = *(uint *)(iVar6 + 0x4ac);
          }
        }
      }
      local_38 = local_38 + 1;
    } while (local_38 < 6);
  }
  return 1;
}


