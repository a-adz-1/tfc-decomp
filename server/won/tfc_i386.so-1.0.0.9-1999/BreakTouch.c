// BreakTouch__10CBreakableP11CBaseEntity  @ 000b27c0
void BreakTouch__10CBreakableP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  
  iVar2 = *param_2;
  if (((*(byte *)(iVar2 + 0x184) & 8) != 0) &&
     (iVar4 = IsBreakable__10CBreakable(param_1), iVar4 != 0)) {
    if (((*(byte *)(*param_1 + 0x180) & 2) != 0) &&
       (fVar1 = SQRT(*(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x28) +
                     *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24) +
                     *(float *)(iVar2 + 0x20) * *(float *)(iVar2 + 0x20)) * 0.01,
       *(float *)(*param_1 + 0x140) <= fVar1)) {
      param_1[5] = 0;
      param_1[6] = 0;
      (**(code **)(param_1[0xf2] + 0x34))(param_1,iVar2,iVar2,fVar1,1);
      (**(code **)(param_2[0xf2] + 0x34))(param_2,*param_1,*param_1,fVar1 * 0.25,4);
    }
    if ((*(byte *)(*param_1 + 0x180) & 4) != 0) {
      fVar3 = *(float *)(*param_1 + 0xd0) - 2.0;
      fVar1 = *(float *)(iVar2 + 0xac);
      if ((byte)((fVar3 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar1)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar3 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
        DamageSound__10CBreakable(param_1);
        param_1[3] = -0x10000;
        param_1[4] = (int)Die__10CBreakable;
        param_1[5] = 0;
        param_1[6] = 0;
        if ((byte)((byte)((ushort)((ushort)NAN((float)param_1[0xf3]) << 10) >> 8) |
                  (byte)((ushort)((ushort)((float)param_1[0xf3] == 0.0) << 0xe) >> 8)) == 0x40) {
          param_1[0xf3] = 0x3dcccccd;
        }
        *(float *)(*param_1 + 0xe4) = *(float *)(*param_1 + 0xe0) + (float)param_1[0xf3];
      }
    }
  }
  return;
}


