// old_find_exception_handler  @ 00126430
uint old_find_exception_handler(uint param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  uint *local_c;
  int local_8;
  
  if (param_2 != (uint *)0x0) {
    iVar1 = -1;
    local_8 = 0;
    if (*param_2 != 0xffffffff) {
      local_c = param_2 + 1;
      puVar2 = param_2;
      do {
        if ((param_1 < *puVar2) || (*local_c <= param_1)) {
          if ((-1 < iVar1) && (param_1 < *puVar2)) break;
        }
        else if ((iVar1 == -1) ||
                ((*local_c <= param_2[iVar1 * 3 + 1] && (param_2[iVar1 * 3] <= *puVar2)))) {
          iVar1 = local_8;
        }
        puVar2 = puVar2 + 3;
        local_c = local_c + 3;
        local_8 = local_8 + 1;
      } while (*puVar2 != 0xffffffff);
    }
    if (iVar1 != -1) {
      return param_2[iVar1 * 3 + 2];
    }
  }
  return 0;
}


