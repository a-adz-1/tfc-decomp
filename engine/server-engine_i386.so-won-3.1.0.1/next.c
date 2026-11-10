// next_stack_level  @ 000a06a0
int * next_stack_level(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)__frame_state_for(param_1,param_3);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    if (*(char *)(*(ushort *)(piVar1 + 0x16) + 0x5c + (int)param_2) == '\0') {
      iVar2 = *param_2;
    }
    else {
      iVar2 = get_reg((uint)*(ushort *)(piVar1 + 0x16),param_2,0);
    }
    *piVar1 = iVar2;
    *piVar1 = *piVar1 + piVar1[2];
  }
  return piVar1;
}


