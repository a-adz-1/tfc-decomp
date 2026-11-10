// Listen__12CBaseMonster  @ 000bafc4
void Listen__12CBaseMonster(int param_1)

{
  code *pcVar1;
  float fVar2;
  float fVar3;
  undefined1 *puVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  undefined1 *puVar8;
  longdouble lVar9;
  int aiStackY_48 [2];
  uint local_28;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  *(undefined4 *)(param_1 + 0x624) = 0xffffffff;
  *(uint *)(param_1 + 0x4f8) = *(uint *)(param_1 + 0x4f8) & 0xfff9ffbf;
  *(undefined4 *)(param_1 + 0x628) = 0;
  local_28 = (**(code **)(*(int *)(param_1 + 0x454) + 0x1d0))(param_1);
  if (*(int *)(param_1 + 0x580) != 0) {
    local_28 = local_28 & *(uint *)(*(int *)(param_1 + 0x580) + 0xc);
  }
  fVar5 = (float)ActiveList__9CSoundEnt();
  *(uint *)(param_1 + 0x4f8) = *(uint *)(param_1 + 0x4f8) & 0xfff9ffbf;
  lVar9 = (longdouble)(**(code **)(*(int *)(param_1 + 0x454) + 0x1dc))(param_1);
  puVar4 = &stack0xffffffc4;
  while (fVar5 != -NAN) {
    *(float *)(puVar4 + -4) = fVar5;
    *(undefined4 *)(puVar4 + -8) = 0xbb059;
    pfVar6 = (float *)SoundPointerForIndex__9CSoundEnti();
    puVar8 = puVar4;
    if ((pfVar6 != (float *)0x0) && (((uint)pfVar6[3] & local_28) != 0)) {
      iVar7 = *(int *)(param_1 + 0x454);
      *(int *)(puVar4 + -4) = param_1;
      *(float **)(puVar4 + -8) = &local_1c;
      pcVar1 = *(code **)(iVar7 + 0xd4);
      *(undefined4 *)(puVar4 + -0xc) = 0xbb085;
      (*pcVar1)();
      local_10 = *pfVar6 - local_1c;
      local_c = pfVar6[1] - local_18;
      local_8 = pfVar6[2] - local_14;
      puVar8 = puVar4 + -4;
      fVar2 = SQRT(local_8 * local_8 + local_c * local_c + local_10 * local_10);
      fVar3 = (float)lVar9 * (float)(int)pfVar6[4];
      if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 1) {
        pfVar6[7] = *(float *)(param_1 + 0x624);
        *(float **)(puVar4 + -8) = pfVar6;
        *(undefined4 *)(puVar4 + -0xc) = 0xbb0db;
        iVar7 = FIsSound__6CSound();
        puVar8 = puVar4 + -4;
        if (iVar7 == 0) {
          if (((uint)pfVar6[3] & 0x18) == 0) {
            *(byte *)(param_1 + 0x4fa) = *(byte *)(param_1 + 0x4fa) | 4;
          }
          else {
            *(uint *)(param_1 + 0x4f8) = *(uint *)(param_1 + 0x4f8) | 0x40040;
          }
        }
        else {
          *(byte *)(param_1 + 0x4fa) = *(byte *)(param_1 + 0x4fa) | 2;
        }
        *(uint *)(param_1 + 0x628) = *(uint *)(param_1 + 0x628) | (uint)pfVar6[3];
        *(float *)(param_1 + 0x624) = fVar5;
      }
    }
    puVar4 = puVar8;
    fVar5 = pfVar6[6];
  }
  return;
}


