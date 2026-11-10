// DispatchAnimEvents__14CBaseAnimatingf  @ 000b3d44
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
  undefined1 auStack_8 [8];
  
  iVar7 = (*DAT_001a7f68)(*(undefined4 *)(*param_1 + 0x208));
  if (iVar7 != 0) {
    fVar1 = (float)param_1[0xfa];
    iVar8 = *param_1;
    fVar2 = *(float *)(iVar8 + 0x134);
    fVar3 = (float)param_1[0xf8];
    fVar4 = *(float *)(iVar8 + 0x138);
    fVar5 = *(float *)(iVar8 + 0x130);
    fVar6 = (float)param_1[0xf8] * 0.1 * *(float *)(iVar8 + 0x138) + *(float *)(iVar8 + 0x130);
    param_1[0xfa] = (int)(*(float *)(iVar8 + 0x134) + 0.1);
    param_1[0xfb] = 0;
    if (((byte)((256.0 < fVar6 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar6 == 256.0) << 0xe) >> 8)) - 1) < 0x40) ||
       ((byte)(0.0 < fVar6 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar6 == 0.0) << 0xe) >> 8)) != 1)) {
      param_1[0xfb] = 1;
    }
    iVar8 = 0;
    while (iVar8 = GetAnimationEvent__FPvP9entvars_sP14MonsterEvent_tffi
                             (iVar7,*param_1,auStack_8,(fVar1 - fVar2) * fVar3 * fVar4 + fVar5,fVar6
                              ,iVar8), iVar8 != 0) {
      (**(code **)(param_1[0xf5] + 0x100))(param_1,auStack_8);
    }
    return;
  }
  (*DAT_001a7f34)(2,"Gibbed monster is thinking!\n");
  return;
}


