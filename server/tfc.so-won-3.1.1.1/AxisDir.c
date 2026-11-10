// AxisDir__11CBaseToggleP9entvars_s  @ 000f6388
void AxisDir__11CBaseToggleP9entvars_s(int param_1)

{
  undefined4 uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((*(byte *)(param_1 + 0x1a0) & 0x40) == 0) {
    if (*(char *)(param_1 + 0x1a0) < '\0') {
      uVar1 = 0x3f800000;
      local_c = 0;
    }
    else {
      uVar1 = 0;
      local_c = 0x3f800000;
    }
    local_8 = 0;
  }
  else {
    uVar1 = 0;
    local_c = 0;
    local_8 = 0x3f800000;
  }
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  *(undefined4 *)(param_1 + 0x48) = local_c;
  *(undefined4 *)(param_1 + 0x4c) = local_8;
  return;
}


