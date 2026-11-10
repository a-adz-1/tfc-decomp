// frame_dummy  @ 0009a6b8
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void frame_dummy(void)

{
  __register_frame_info(&cie_00157354,object_8);
  return;
}


// frame_init  @ 00120b20
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void frame_init(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  void *local_14;
  undefined4 local_10;
  void *local_c;
  undefined4 local_8;
  
  piVar3 = (int *)param_1[3];
  if (piVar3 == (int *)0x0) {
    local_20 = count_fdes(param_1[2]);
  }
  else {
    local_20 = 0;
    iVar1 = *piVar3;
    while (iVar1 != 0) {
      iVar1 = count_fdes(iVar1);
      local_20 = local_20 + iVar1;
      piVar3 = piVar3 + 1;
      iVar1 = *piVar3;
    }
  }
  param_1[4] = local_20;
  local_14 = malloc(local_20 * 4);
  local_c = malloc(local_20 * 4);
  local_10 = 0;
  local_8 = 0;
  local_1c = 0xffffffff;
  local_18 = 0;
  piVar3 = (int *)param_1[3];
  if (piVar3 == (int *)0x0) {
    add_fdes(param_1[2],&local_14,&local_1c,&local_18);
  }
  else {
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      do {
        add_fdes(iVar1,&local_14,&local_1c,&local_18);
        piVar3 = piVar3 + 1;
        iVar1 = *piVar3;
      } while (iVar1 != 0);
    }
  }
  uVar2 = end_fde_sort(&local_14,local_20);
  param_1[3] = uVar2;
  *param_1 = local_1c;
  param_1[1] = local_18;
  return;
}


