// ControllerPostFrame__9CFuncTank  @ 000b46e0
void ControllerPostFrame__9CFuncTank(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float local_44;
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
  undefined1 local_10 [12];
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0xf4];
  if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) &&
     ((*(byte *)(*(int *)param_1[0xf3] + 0x160) & 1) != 0)) {
    (*DAT_00175510)(*param_1 + 0x50,local_10,0,0);
    local_14 = (*gpGlobals - 1.0 / (float)param_1[0x101]) - 0.01;
    param_1[0x100] = (int)local_14;
    (*DAT_00175510)(*param_1 + 0x50,&local_2c,&local_38,&local_44);
    fVar1 = (float)param_1[0x106];
    iVar4 = *param_1;
    fVar2 = (float)param_1[0x107];
    fVar3 = (float)param_1[0x108];
    local_20 = *(float *)(iVar4 + 8) + fVar1 * local_2c + fVar2 * local_38 + fVar3 * local_44;
    local_1c = *(float *)(iVar4 + 0xc) + fVar1 * local_28 + fVar2 * local_34 + fVar3 * local_40;
    local_18 = *(float *)(iVar4 + 0x10) + fVar1 * local_24 + fVar2 * local_30 + fVar3 * local_3c;
    (**(code **)(param_1[0xf2] + 0x100))(param_1,&local_20,local_10,*(undefined4 *)param_1[0xf3]);
    if ((param_1[0xf3] != 0) && ((*(byte *)(*(int *)param_1[0xf3] + 0x184) & 8) != 0)) {
      ((int *)param_1[0xf3])[0x186] = 1000;
    }
    param_1[0xf4] = (int)(1.0 / (float)param_1[0x101] + *gpGlobals);
  }
  return;
}


