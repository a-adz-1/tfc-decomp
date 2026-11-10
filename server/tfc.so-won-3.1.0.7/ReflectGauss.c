// ReflectGauss__11CBaseEntity  @ 0010f8a4
bool ReflectGauss__11CBaseEntity(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = false;
  iVar2 = (**(code **)(param_1[0x111] + 0x90))(param_1);
  if (iVar2 != 0) {
    fVar1 = *(float *)(*param_1 + 0x16c);
    bVar3 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40;
  }
  return bVar3;
}


