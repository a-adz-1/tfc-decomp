// BreakTouch__10CBreakableP11CBaseEntity  @ 000a818c
void BreakTouch__10CBreakableP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  
  iVar2 = *param_2;
  if (((*(byte *)(iVar2 + 0x1a4) & 8) != 0) &&
     (iVar4 = IsBreakable__10CBreakable(param_1), iVar4 != 0)) {
    if ((*(byte *)(*param_1 + 0x1a0) & 2) != 0) {
      fVar3 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                   *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                   *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20)) * 0.01;
      fVar1 = *(float *)(*param_1 + 0x160);
      if ((byte)(fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) != 1) {
        param_1[5] = 0;
        param_1[6] = 0;
        (**(code **)(param_1[0x115] + 0x38))(param_1,iVar2,iVar2,fVar3,1);
        (**(code **)(param_2[0x115] + 0x38))(param_2,*param_1,*param_1,fVar3 * 0.25,4);
      }
    }
    if (((*(byte *)(*param_1 + 0x1a0) & 4) != 0) &&
       (*(float *)(*param_1 + 0xf0) - 2.0 <= *(float *)(iVar2 + 0xcc))) {
      DamageSound__10CBreakable(param_1);
      param_1[3] = -0x10000;
      param_1[4] = (int)Die__10CBreakable;
      param_1[5] = 0;
      param_1[6] = 0;
      fVar1 = (float)param_1[0x116];
      if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
        param_1[0x116] = 0x3dcccccd;
        fVar1 = 0.1;
      }
      *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + fVar1;
    }
  }
  return;
}


