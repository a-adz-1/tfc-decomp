// StopControl__9CFuncTank  @ 000b4640
void StopControl__9CFuncTank(int *param_1)

{
  int iVar1;
  
  if (param_1[0xf3] != 0) {
    if (*(int *)(param_1[0xf3] + 0x830) != 0) {
      iVar1 = *(int *)(param_1[0xf3] + 0x830);
      (**(code **)(*(int *)(iVar1 + 0x3c8) + 0x118))(iVar1);
    }
    (*DAT_001755b4)(1,"stopped using TANK\n");
    *(byte *)(param_1[0xf3] + 0x808) = *(byte *)(param_1[0xf3] + 0x808) & 0xfe;
    *(undefined4 *)(*param_1 + 0xe4) = 0;
    param_1[0xf3] = 0;
    iVar1 = *param_1;
    if ((*(byte *)(iVar1 + 0x180) & 1) != 0) {
      *(float *)(iVar1 + 0xe4) = *(float *)(iVar1 + 0xe0) + 1.0;
    }
  }
  return;
}


