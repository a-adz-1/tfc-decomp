// AxisDir__11CBaseToggleP9entvars_t  @ 000f0fa0
void AxisDir__11CBaseToggleP9entvars_t(int param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((*(byte *)(param_1 + 0x180) & 0x40) == 0) {
    if (*(char *)(param_1 + 0x180) < '\0') {
      local_10 = 0x3f800000;
      local_c = 0;
    }
    else {
      local_10 = 0;
      local_c = 0x3f800000;
    }
    local_8 = 0;
  }
  else {
    local_10 = 0;
    local_c = 0;
    local_8 = 0x3f800000;
  }
  *(undefined4 *)(param_1 + 0x44) = local_10;
  *(undefined4 *)(param_1 + 0x48) = local_c;
  *(undefined4 *)(param_1 + 0x4c) = local_8;
  return;
}


