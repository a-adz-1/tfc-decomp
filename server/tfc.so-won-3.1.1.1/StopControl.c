// StopControl__9CFuncTank  @ 000ac8d0
void StopControl__9CFuncTank(int *param_1)

{
  int iVar1;
  
  if (param_1[0x116] != 0) {
    iVar1 = *(int *)(param_1[0x116] + 0x8dc);
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 0x454) + 0x120))(iVar1);
    }
    (*DAT_0019f794)(1,"stopped using TANK\n");
    *(byte *)(param_1[0x116] + 0x8b4) = *(byte *)(param_1[0x116] + 0x8b4) & 0xfe;
    *(undefined4 *)(*param_1 + 0x104) = 0;
    iVar1 = *param_1;
    param_1[0x116] = 0;
    if ((*(byte *)(iVar1 + 0x1a0) & 1) != 0) {
      *(float *)(iVar1 + 0x104) = *(float *)(iVar1 + 0x100) + 1.0;
    }
  }
  return;
}


