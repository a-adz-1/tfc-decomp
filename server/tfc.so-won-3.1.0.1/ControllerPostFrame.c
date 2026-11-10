// ControllerPostFrame__9CFuncTank  @ 000a0410
void ControllerPostFrame__9CFuncTank(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0xf7];
  if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) &&
     ((*(byte *)(*(int *)param_1[0xf6] + 0x180) & 1) != 0)) {
    (*DAT_001a7e90)(*param_1 + 0x50,local_c,0,0);
    local_10 = (*gpGlobals - 1.0 / (float)param_1[0x104]) - 0.01;
    param_1[0x103] = (int)local_10;
    (*DAT_001a7e90)(*param_1 + 0x50,&local_28,&local_34,&local_40);
    fVar1 = (float)param_1[0x109];
    fVar2 = (float)param_1[0x10a];
    fVar3 = (float)param_1[0x10b];
    local_1c = *(float *)(*param_1 + 8) + fVar1 * local_28 + fVar2 * local_34 + fVar3 * local_40;
    local_18 = *(float *)(*param_1 + 0xc) + fVar1 * local_24 + fVar2 * local_30 + fVar3 * local_3c;
    local_14 = *(float *)(*param_1 + 0x10) + fVar1 * local_20 + fVar2 * local_2c + fVar3 * local_38;
    (**(code **)(param_1[0xf5] + 0x100))(param_1,&local_1c,local_c,*(undefined4 *)param_1[0xf6]);
    if ((param_1[0xf6] != 0) && ((*(byte *)(*(int *)param_1[0xf6] + 0x1a4) & 8) != 0)) {
      ((int *)param_1[0xf6])[0x18a] = 1000;
    }
    param_1[0xf7] = (int)(1.0 / (float)param_1[0x104] + *gpGlobals);
  }
  return;
}


