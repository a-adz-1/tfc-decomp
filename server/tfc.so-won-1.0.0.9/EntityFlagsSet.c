// EntityFlagsSet__18CSaveRestoreBufferii  @ 00118e30
undefined4 EntityFlagsSet__18CSaveRestoreBufferii(int *param_1,int param_2,uint param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  
  if (((*param_1 == 0) || (param_2 < 0)) || (*(int *)(*param_1 + 0x20) < param_2)) {
    uVar2 = 0;
  }
  else {
    puVar1 = (uint *)(*(int *)(*param_1 + 0x28) + 0x10 + param_2 * 0x18);
    *puVar1 = *puVar1 | param_3;
    uVar2 = *(undefined4 *)(*(int *)(*param_1 + 0x28) + 0x10 + param_2 * 0x18);
  }
  return uVar2;
}


