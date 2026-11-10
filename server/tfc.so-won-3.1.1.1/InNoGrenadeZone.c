// InNoGrenadeZone__8CGrenadeG6Vector  @ 000b0690
undefined4 InNoGrenadeZone__8CGrenadeG6Vector(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = (int *)0x0;
  do {
    do {
      do {
        piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,"func_nogrenades");
        if (piVar6 == (int *)0x0) {
          return 0;
        }
        iVar5 = *piVar6;
        fVar1 = *param_2;
        fVar2 = *(float *)(iVar5 + 0xdc);
      } while ((byte)(fVar1 < fVar2 |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1);
      fVar2 = param_2[1];
      fVar3 = *(float *)(iVar5 + 0xe0);
    } while ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1);
    fVar3 = param_2[2];
    fVar4 = *(float *)(iVar5 + 0xe4);
  } while (((((byte)(fVar3 < fVar4 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar4)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar3 == fVar4) << 0xe) >> 8)) == 1) ||
            (*(float *)(iVar5 + 0xe8) < fVar1)) || (*(float *)(iVar5 + 0xec) < fVar2)) ||
          (*(float *)(iVar5 + 0xf0) < fVar3));
  piVar6 = (int *)SpriteCreate__7CSpritePCcRC6Vectori("sprites/xflare1.spr",param_2,1);
  piVar6[3] = -0x10000;
  piVar6[4] = (int)AnimateUntilDead__7CSprite;
  *(undefined4 *)(*piVar6 + 0x138) = 0x42700000;
  *(float *)(*piVar6 + 0x1e4) = (float)piVar6[0x117] / 60.0 + *gpGlobals;
  *(float *)(*piVar6 + 0x104) = *gpGlobals;
  *(undefined4 *)(*piVar6 + 0x148) = 5;
  *(undefined4 *)(*piVar6 + 0x150) = 0x437f0000;
  *(undefined4 *)(*piVar6 + 0x154) = 0x437f0000;
  *(undefined4 *)(*piVar6 + 0x158) = 0x437f0000;
  *(undefined4 *)(*piVar6 + 0x14c) = 0x437f0000;
  *(undefined4 *)(*piVar6 + 0x15c) = 0xe;
  *(undefined4 *)(*piVar6 + 0x144) = 0x3e800000;
  *(byte *)(*param_1 + 0x1a7) = *(byte *)(*param_1 + 0x1a7) | 0x40;
  return 1;
}


