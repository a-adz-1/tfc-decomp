// StopControl__9CFuncTank  @ 000a0360
void StopControl__9CFuncTank(int *param_1)

{
  int iVar1;
  
  if (param_1[0xf6] != 0) {
    if (*(int *)(param_1[0xf6] + 0x844) != 0) {
      iVar1 = *(int *)(param_1[0xf6] + 0x844);
      (**(code **)(*(int *)(iVar1 + 0x3d4) + 0x118))(iVar1);
    }
    (*DAT_001a7f34)(1,"stopped using TANK\n");
    *(byte *)(param_1[0xf6] + 0x81c) = *(byte *)(param_1[0xf6] + 0x81c) & 0xfe;
    *(undefined4 *)(*param_1 + 0x104) = 0;
    param_1[0xf6] = 0;
    iVar1 = *param_1;
    if ((*(byte *)(iVar1 + 0x1a0) & 1) != 0) {
      *(float *)(iVar1 + 0x104) = *(float *)(iVar1 + 0x100) + 1.0;
    }
  }
  return;
}


