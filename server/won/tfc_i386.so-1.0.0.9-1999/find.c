// find_exception_handler  @ 0011fa14
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 find_exception_handler(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint *puStack_c;
  int *local_8;
  
  if (param_2 != (undefined4 *)0x0) {
    puVar2 = param_2 + 2;
    if (param_2[2] != -1) {
      local_8 = param_2 + 5;
      puStack_c = param_2 + 3;
      puVar3 = param_2;
      do {
        puVar3 = puVar3 + 4;
        if (((*puVar2 <= param_1 - 1U) && (param_1 - 1U < *puStack_c)) &&
           ((*local_8 == 0 ||
            (((code *)*param_3 != (code *)0x0 &&
             (iVar1 = (*(code *)*param_3)(param_3,*local_8,param_2), iVar1 != 0)))))) {
          return *puVar3;
        }
        puVar2 = puVar2 + 4;
        local_8 = local_8 + 4;
        puStack_c = puStack_c + 4;
      } while (*puVar2 != 0xffffffff);
    }
  }
  return 0;
}


// find_fde  @ 00120c40
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int find_fde(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint local_c;
  uint local_8;
  
  puVar3 = objects;
  if (objects != (uint *)0x0) {
    do {
      uVar2 = *puVar3;
      if (uVar2 == 0) {
        frame_init(puVar3);
        uVar2 = *puVar3;
      }
    } while (((param_1 < uVar2) || (puVar3[1] <= param_1)) &&
            (puVar3 = (uint *)puVar3[5], puVar3 != (uint *)0x0));
    if (puVar3 != (uint *)0x0) {
      local_c = 0;
      local_8 = puVar3[4];
      if (local_8 != 0) {
        do {
          uVar2 = local_c + local_8 >> 1;
          iVar1 = *(int *)(puVar3[3] + uVar2 * 4);
          if (*(uint *)(iVar1 + 8) <= param_1) {
            if (param_1 < *(uint *)(iVar1 + 8) + *(int *)(iVar1 + 0xc)) {
              return iVar1;
            }
            local_c = uVar2 + 1;
            uVar2 = local_8;
          }
          local_8 = uVar2;
        } while (local_c < local_8);
      }
    }
  }
  return 0;
}


