// Listen__12CBaseMonster  @ 000c1070
void Listen__12CBaseMonster(int param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  undefined1 *puVar6;
  longdouble lVar7;
  int aiStackY_44 [2];
  uint local_24;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  *(undefined4 *)(param_1 + 0x598) = 0xffffffff;
  *(uint *)(param_1 + 0x46c) = *(uint *)(param_1 + 0x46c) & 0xfff9ffbf;
  *(undefined4 *)(param_1 + 0x59c) = 0;
  local_24 = (**(code **)(*(int *)(param_1 + 0x3c8) + 0x1c8))(param_1);
  if (*(int *)(param_1 + 0x4f4) != 0) {
    local_24 = local_24 & *(uint *)(*(int *)(param_1 + 0x4f4) + 0xc);
  }
  fVar3 = (float)ActiveList__9CSoundEnt();
  *(uint *)(param_1 + 0x46c) = *(uint *)(param_1 + 0x46c) & 0xfff9ffbf;
  lVar7 = (longdouble)(**(code **)(*(int *)(param_1 + 0x3c8) + 0x1d4))(param_1);
  puVar2 = &stack0xffffffc8;
  while (fVar3 != -NAN) {
    *(float *)(puVar2 + -4) = fVar3;
    *(undefined4 *)(puVar2 + -8) = 0xc10fa;
    pfVar4 = (float *)SoundPointerForIndex__9CSoundEnti();
    puVar6 = puVar2;
    if ((pfVar4 != (float *)0x0) && ((local_24 & (uint)pfVar4[3]) != 0)) {
      iVar5 = *(int *)(param_1 + 0x3c8);
      *(int *)(puVar2 + -4) = param_1;
      *(float **)(puVar2 + -8) = &local_1c;
      pcVar1 = *(code **)(iVar5 + 0xcc);
      *(undefined4 *)(puVar2 + -0xc) = 0xc1126;
      (*pcVar1)();
      puVar6 = puVar2 + -4;
      local_10 = *pfVar4 - local_1c;
      local_c = pfVar4[1] - local_18;
      local_8 = pfVar4[2] - local_14;
      if (SQRT(local_8 * local_8 + local_c * local_c + local_10 * local_10) <=
          (float)lVar7 * (float)(int)pfVar4[4]) {
        pfVar4[7] = *(float *)(param_1 + 0x598);
        *(float **)(puVar2 + -8) = pfVar4;
        *(undefined4 *)(puVar2 + -0xc) = 0xc1182;
        iVar5 = FIsSound__6CSound();
        puVar6 = puVar2 + -4;
        if (iVar5 == 0) {
          if (((uint)pfVar4[3] & 0x18) != 0) {
            *(byte *)(param_1 + 0x46c) = *(byte *)(param_1 + 0x46c) | 0x40;
          }
          *(byte *)(param_1 + 0x46e) = *(byte *)(param_1 + 0x46e) | 4;
        }
        else {
          *(byte *)(param_1 + 0x46e) = *(byte *)(param_1 + 0x46e) | 2;
        }
        *(uint *)(param_1 + 0x59c) = *(uint *)(param_1 + 0x59c) | (uint)pfVar4[3];
        *(float *)(param_1 + 0x598) = fVar3;
      }
    }
    puVar2 = puVar6;
    fVar3 = pfVar4[6];
  }
  return;
}


