// EntityFlagsSet__18CSaveRestoreBufferii  @ 001215c0
undefined4 EntityFlagsSet__18CSaveRestoreBufferii(int *param_1,int param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *param_1;
  if (((iVar2 == 0) || (param_2 < 0)) || (*(int *)(iVar2 + 0x20) < param_2)) {
    uVar3 = 0;
  }
  else {
    puVar1 = (uint *)(*(int *)(iVar2 + 0x28) + 0x10 + param_2 * 0x18);
    *puVar1 = *puVar1 | param_3;
    uVar3 = *(undefined4 *)(*(int *)(*param_1 + 0x28) + 0x10 + param_2 * 0x18);
  }
  return uVar3;
}


