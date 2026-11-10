// LookupActivityHeaviest__14CBaseAnimatingi  @ 000b3b00
void LookupActivityHeaviest__14CBaseAnimatingi(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001a7f68)(*(undefined4 *)(*param_1 + 0x208));
  LookupActivityHeaviest__FPvP9entvars_si(uVar1,*param_1,param_2);
  return;
}


// LookupActivityHeaviest__FPvP9entvars_si  @ 0007f610
int LookupActivityHeaviest__FPvP9entvars_si(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_10;
  int *local_c;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar5 = param_1 + *(int *)(param_1 + 0xa8);
  local_10 = 0;
  iVar4 = -1;
  iVar1 = 0;
  if (*(int *)(param_1 + 0xa4) < 1) {
    return -1;
  }
  piVar2 = (int *)(iVar5 + 0x2c);
  local_c = (int *)(iVar5 + 0x28);
  uVar3 = *(uint *)(param_1 + 0xa4) & 3;
  if (0 < *(int *)(param_1 + 0xa4)) {
    if (uVar3 == 0) goto LAB_0007f720;
    if (1 < uVar3) {
      if (2 < uVar3) {
        if ((*(int *)(iVar5 + 0x28) == param_3) && (0 < *(int *)(iVar5 + 0x2c))) {
          local_10 = *(int *)(iVar5 + 0x2c);
          iVar4 = 0;
        }
        piVar2 = (int *)(iVar5 + 0xdc);
        local_c = (int *)(iVar5 + 0xd8);
        iVar1 = 1;
      }
      if ((*local_c == param_3) && (local_10 < *piVar2)) {
        local_10 = *piVar2;
        iVar4 = iVar1;
      }
      piVar2 = piVar2 + 0x2c;
      local_c = local_c + 0x2c;
      iVar1 = iVar1 + 1;
    }
  }
  if ((*local_c == param_3) && (local_10 < *piVar2)) {
    local_10 = *piVar2;
    iVar4 = iVar1;
  }
  piVar2 = piVar2 + 0x2c;
  local_c = local_c + 0x2c;
  iVar1 = iVar1 + 1;
  if (*(int *)(param_1 + 0xa4) <= iVar1) {
    return iVar4;
  }
LAB_0007f720:
  do {
    if ((*local_c == param_3) && (local_10 < *piVar2)) {
      local_10 = *piVar2;
      iVar4 = iVar1;
    }
    if ((local_c[0x2c] == param_3) && (local_10 < piVar2[0x2c])) {
      local_10 = piVar2[0x2c];
      iVar4 = iVar1 + 1;
    }
    if ((local_c[0x58] == param_3) && (local_10 < piVar2[0x58])) {
      local_10 = piVar2[0x58];
      iVar4 = iVar1 + 2;
    }
    iVar5 = iVar1 + 3;
    if ((local_c[0x84] == param_3) && (iVar5 = local_10, local_10 < piVar2[0x84])) {
      iVar4 = iVar1 + 3;
      local_10 = piVar2[0x84];
    }
    piVar2 = piVar2 + 0xb0;
    local_c = local_c + 0xb0;
    iVar1 = iVar1 + 4;
  } while (iVar1 < *(int *)(iVar5 + 0xa4));
  return iVar4;
}


