// DispatchAnimEvents__14CBaseAnimatingf  @ 000befa4
void DispatchAnimEvents__14CBaseAnimatingf(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  undefined1 local_8 [8];
  
  iVar7 = (*DAT_001c1148)(*(undefined4 *)(*param_1 + 0x208));
  if (iVar7 != 0) {
    fVar1 = (float)param_1[0x116];
    iVar8 = *param_1;
    fVar2 = *(float *)(iVar8 + 0x134);
    fVar3 = (float)param_1[0x114];
    fVar4 = *(float *)(iVar8 + 0x138);
    fVar5 = *(float *)(iVar8 + 0x130);
    fVar6 = (float)param_1[0x114] * 0.1 * *(float *)(iVar8 + 0x138) + *(float *)(iVar8 + 0x130);
    param_1[0x116] = (int)(*(float *)(iVar8 + 0x134) + 0.1);
    param_1[0x117] = 0;
    if (((byte)((256.0 < fVar6 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar6 == 256.0) << 0xe) >> 8)) - 1) < 0x40) ||
       ((byte)(0.0 < fVar6 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar6 == 0.0) << 0xe) >> 8)) != 1)) {
      param_1[0x117] = 1;
    }
    iVar8 = 0;
    while (iVar8 = GetAnimationEvent__FPvP9entvars_sP14MonsterEvent_tffi
                             (iVar7,*param_1,local_8,(fVar1 - fVar2) * fVar3 * fVar4 + fVar5,fVar6,
                              iVar8), iVar8 != 0) {
      (**(code **)(param_1[0x111] + 0x108))(param_1,local_8);
    }
    return;
  }
  (*DAT_001c1114)(2,"Gibbed monster is thinking!\n");
  return;
}


