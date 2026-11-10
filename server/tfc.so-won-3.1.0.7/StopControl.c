// StopControl__9CFuncTank  @ 000aad88
void StopControl__9CFuncTank(int *param_1)

{
  int iVar1;
  
  if (param_1[0x112] != 0) {
    if (*(int *)(param_1[0x112] + 0x8b4) != 0) {
      iVar1 = *(int *)(param_1[0x112] + 0x8b4);
      (**(code **)(*(int *)(iVar1 + 0x444) + 0x120))(iVar1);
    }
    (*DAT_001c1114)(1,"stopped using TANK\n");
    *(byte *)(param_1[0x112] + 0x88c) = *(byte *)(param_1[0x112] + 0x88c) & 0xfe;
    *(undefined4 *)(*param_1 + 0x104) = 0;
    param_1[0x112] = 0;
    iVar1 = *param_1;
    if ((*(byte *)(iVar1 + 0x1a0) & 1) != 0) {
      *(float *)(iVar1 + 0x104) = *(float *)(iVar1 + 0x100) + 1.0;
    }
  }
  return;
}


