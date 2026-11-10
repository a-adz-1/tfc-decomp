// find_exception_handler  @ 00136ea0
undefined4 find_exception_handler(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint *puStack_c;
  int *piStack_8;
  
  if (param_2 != (undefined4 *)0x0) {
    puVar2 = param_2 + 2;
    if (param_2[2] != -1) {
      piStack_8 = param_2 + 5;
      puStack_c = param_2 + 3;
      puVar3 = param_2;
      do {
        puVar3 = puVar3 + 4;
        if (((*puVar2 <= param_1 - 1U) && (param_1 - 1U < *puStack_c)) &&
           ((*piStack_8 == 0 ||
            (((code *)*param_3 != (code *)0x0 &&
             (iVar1 = (*(code *)*param_3)(param_3,*piStack_8,param_2), iVar1 != 0)))))) {
          return *puVar3;
        }
        puVar2 = puVar2 + 4;
        piStack_8 = piStack_8 + 4;
        puStack_c = puStack_c + 4;
      } while (*puVar2 != 0xffffffff);
    }
  }
  return 0;
}


