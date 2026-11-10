// GetWeaponData__FP7edict_sP13weapon_data_s  @ 000944d0
undefined4 GetWeaponData__FP7edict_sP13weapon_data_s(int param_1,void *param_2)

{
  uint *puVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_34;
  undefined1 local_2c [32];
  uint local_c;
  
  iVar4 = *(int *)(param_1 + 0x288);
  if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0x7c);
  }
  memset(param_2,0,0xb00);
  if (iVar4 != 0) {
    local_34 = 0;
    do {
      if (*(int *)(local_34 * 4 + iVar4 + 0x89c) != 0) {
        for (iVar3 = *(int *)(local_34 * 4 + iVar4 + 0x89c); iVar3 != 0;
            iVar3 = *(int *)(iVar3 + 0x468)) {
          iVar5 = (**(code **)(*(int *)(iVar3 + 0x444) + 0x150))(iVar3);
          if (iVar5 != 0) {
            memset(local_2c,0,0x2c);
            (**(code **)(*(int *)(iVar5 + 0x444) + 0x118))(iVar5,local_2c);
            if (local_c < 0x20) {
              puVar1 = (uint *)((int)param_2 + local_c * 0x58);
              *puVar1 = local_c;
              puVar1[1] = *(uint *)(iVar5 + 0x4b0);
              fVar2 = *(float *)(iVar5 + 0x488);
              if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
                fVar2 = -0.001;
              }
              puVar1[8] = (uint)fVar2;
              fVar2 = *(float *)(iVar5 + 0x480);
              if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
                fVar2 = -0.001;
              }
              puVar1[4] = (uint)fVar2;
              fVar2 = *(float *)(iVar5 + 0x478);
              if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
                fVar2 = -0.001;
              }
              puVar1[2] = (uint)fVar2;
              fVar2 = *(float *)(iVar5 + 0x47c);
              if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
                fVar2 = -0.001;
              }
              puVar1[3] = (uint)fVar2;
              fVar2 = *(float *)(iVar5 + 0x484);
              if (0x3f < (byte)((-0.001 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar2 == -0.001) << 0xe) >> 8)) - 1)) {
                fVar2 = -0.001;
              }
              puVar1[7] = (uint)fVar2;
              fVar2 = *(float *)(iVar5 + 0x494);
              if (0x3f < (byte)((-1.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar2 == -1.0) << 0xe) >> 8)) - 1)) {
                fVar2 = -1.0;
              }
              puVar1[0xb] = (uint)fVar2;
              puVar1[5] = *(uint *)(iVar5 + 0x4a0);
              puVar1[6] = *(uint *)(iVar5 + 0x4a4);
              puVar1[9] = *(uint *)(iVar5 + 0x48c);
              puVar1[10] = *(uint *)(iVar5 + 0x490);
              puVar1[0xc] = *(uint *)(iVar5 + 0x498);
              puVar1[0xd] = *(uint *)(iVar5 + 0x49c);
            }
          }
        }
      }
      local_34 = local_34 + 1;
    } while (local_34 < 6);
  }
  return 1;
}


