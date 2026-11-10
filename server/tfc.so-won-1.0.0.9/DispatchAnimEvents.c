// DispatchAnimEvents__14CBaseAnimatingf  @ 000c5680
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
  undefined1 auStack_c [8];
  
  iVar7 = (*DAT_001755e8)(*(undefined4 *)(*param_1 + 0x1e8));
  if (iVar7 == 0) {
    (*DAT_001755b4)(2,"Gibbed monster is thinking!\n");
  }
  else {
    fVar1 = (float)param_1[0xf7];
    iVar8 = *param_1;
    fVar2 = *(float *)(iVar8 + 0x114);
    fVar3 = (float)param_1[0xf5];
    fVar4 = *(float *)(iVar8 + 0x118);
    fVar5 = *(float *)(iVar8 + 0x110);
    fVar6 = (float)param_1[0xf5] * 0.1 * *(float *)(iVar8 + 0x118) + *(float *)(iVar8 + 0x110);
    param_1[0xf7] = (int)(*(float *)(iVar8 + 0x114) + 0.1);
    param_1[0xf8] = 0;
    if (((byte)((256.0 < fVar6 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar6 == 256.0) << 0xe) >> 8)) - 1) < 0x40) ||
       (fVar6 <= 0.0)) {
      param_1[0xf8] = 1;
    }
    iVar8 = 0;
    while( true ) {
      iVar8 = GetAnimationEvent__FPvP9entvars_tP14MonsterEvent_tffi
                        (iVar7,*param_1,auStack_c,(fVar1 - fVar2) * fVar3 * fVar4 + fVar5,fVar6,
                         iVar8);
      if (iVar8 == 0) break;
      (**(code **)(param_1[0xf2] + 0x100))(param_1,auStack_c);
    }
  }
  return;
}


