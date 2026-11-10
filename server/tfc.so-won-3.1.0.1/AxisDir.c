// AxisDir__11CBaseToggleP9entvars_s  @ 000e7934
void AxisDir__11CBaseToggleP9entvars_s(int param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(byte *)(param_1 + 0x1a0) & 0x40) == 0) {
    if (*(char *)(param_1 + 0x1a0) < '\0') {
      local_c = 0x3f800000;
      local_8 = 0;
    }
    else {
      local_c = 0;
      local_8 = 0x3f800000;
    }
    local_4 = 0;
  }
  else {
    local_c = 0;
    local_8 = 0;
    local_4 = 0x3f800000;
  }
  *(undefined4 *)(param_1 + 0x44) = local_c;
  *(undefined4 *)(param_1 + 0x48) = local_8;
  *(undefined4 *)(param_1 + 0x4c) = local_4;
  return;
}


