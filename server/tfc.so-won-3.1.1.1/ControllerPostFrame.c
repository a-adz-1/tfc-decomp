// ControllerPostFrame__9CFuncTank  @ 000aa408
void ControllerPostFrame__9CFuncTank(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
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
  
  if (((float)param_1[0x117] <= *gpGlobals) &&
     ((*(byte *)(*(int *)param_1[0x116] + 0x180) & 1) != 0)) {
    (*DAT_0019f6f0)(*param_1 + 0x50,local_10,0,0);
    local_14 = (*gpGlobals - 1.0 / (float)param_1[0x124]) - 0.01;
    param_1[0x123] = (int)local_14;
    (*DAT_0019f6f0)(*param_1 + 0x50,&local_2c,&local_38,&local_44);
    fVar1 = (float)param_1[0x129];
    iVar4 = *param_1;
    fVar2 = (float)param_1[0x12a];
    fVar3 = (float)param_1[299];
    local_20 = local_2c * fVar1 + *(float *)(iVar4 + 8) + local_38 * fVar2 + local_44 * fVar3;
    local_1c = local_28 * fVar1 + *(float *)(iVar4 + 0xc) + local_34 * fVar2 + local_40 * fVar3;
    local_18 = fVar1 * local_24 + *(float *)(iVar4 + 0x10) + fVar2 * local_30 + fVar3 * local_3c;
    (**(code **)(param_1[0x115] + 0x108))(param_1,&local_20,local_10,*(undefined4 *)param_1[0x116]);
    piVar5 = (int *)param_1[0x116];
    if ((piVar5 != (int *)0x0) && ((*(byte *)(*piVar5 + 0x1a4) & 8) != 0)) {
      piVar5[0x1af] = 1000;
    }
    param_1[0x117] = (int)(1.0 / (float)param_1[0x124] + *gpGlobals);
  }
  return;
}


