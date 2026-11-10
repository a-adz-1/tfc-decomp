// Listen__12CBaseMonster  @ 000aeb18
void Listen__12CBaseMonster(int param_1)

{
  float fVar1;
  code *pcVar2;
  float fVar3;
  float fVar4;
  undefined1 *puVar5;
  float fVar6;
  float *pfVar7;
  int iVar8;
  undefined1 *puVar9;
  int aiStackY_44 [2];
  float local_28 [10];
  
  *(undefined4 *)(param_1 + 0x5a4) = 0xffffffff;
  *(uint *)(param_1 + 0x478) = *(uint *)(param_1 + 0x478) & 0xfff9ffbf;
  *(undefined4 *)(param_1 + 0x5a8) = 0;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x1c8))(param_1);
  fVar6 = (float)ActiveList__9CSoundEnt();
  *(uint *)(param_1 + 0x478) = *(uint *)(param_1 + 0x478) & 0xfff9ffbf;
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x1d4))(param_1);
  puVar5 = &stack0xffffffc8;
  while (fVar6 != -NAN) {
    *(float *)(puVar5 + -4) = fVar6;
    *(undefined4 *)(puVar5 + -8) = 0xaebb2;
    pfVar7 = (float *)SoundPointerForIndex__9CSoundEnti();
    puVar9 = puVar5;
    if ((pfVar7 != (float *)0x0) && ((*(uint *)(puVar5 + 0x18) & (uint)pfVar7[3]) != 0)) {
      *(undefined1 **)(puVar5 + 0x10) = puVar5 + 0x20;
      iVar8 = *(int *)(param_1 + 0x3d4);
      *(int *)(puVar5 + -4) = param_1;
      *(undefined1 **)(puVar5 + -8) = puVar5 + 0x20;
      pcVar2 = *(code **)(iVar8 + 0xcc);
      *(code **)(puVar5 + 0x10) = pcVar2;
      *(undefined4 *)(puVar5 + -0xc) = 0xaebea;
      (*pcVar2)();
      puVar9 = puVar5 + -4;
      fVar1 = *pfVar7 - *(float *)(puVar5 + 0x1c);
      fVar4 = pfVar7[1] - *(float *)(puVar5 + 0x20);
      fVar3 = pfVar7[2] - *(float *)(puVar5 + 0x24);
      *(float *)(puVar5 + 0x28) = fVar1;
      *(float *)(puVar5 + 0x2c) = fVar4;
      *(float *)(puVar5 + 0x30) = fVar3;
      *(float *)(puVar5 + 0x18) = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1);
      fVar1 = *(float *)(puVar5 + 0x18);
      fVar3 = *(float *)(puVar5 + 0x10) * (float)(int)pfVar7[4];
      if ((byte)(fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) != 1) {
        pfVar7[7] = *(float *)(param_1 + 0x5a4);
        *(float **)(puVar5 + -8) = pfVar7;
        *(undefined4 *)(puVar5 + -0xc) = 0xaec4d;
        iVar8 = FIsSound__6CSound();
        puVar9 = puVar5 + -4;
        if (iVar8 == 0) {
          if (((uint)pfVar7[3] & 0x18) != 0) {
            *(byte *)(param_1 + 0x478) = *(byte *)(param_1 + 0x478) | 0x40;
          }
          *(byte *)(param_1 + 0x47a) = *(byte *)(param_1 + 0x47a) | 4;
        }
        else {
          *(byte *)(param_1 + 0x47a) = *(byte *)(param_1 + 0x47a) | 2;
        }
        *(uint *)(param_1 + 0x5a8) = *(uint *)(param_1 + 0x5a8) | (uint)pfVar7[3];
        *(float *)(param_1 + 0x5a4) = fVar6;
      }
    }
    puVar5 = puVar9;
    fVar6 = pfVar7[6];
  }
  return;
}


