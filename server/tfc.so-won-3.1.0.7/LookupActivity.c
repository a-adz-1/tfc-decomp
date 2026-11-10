// LookupActivity__14CBaseAnimatingi  @ 000bed1c
void LookupActivity__14CBaseAnimatingi(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_001c1148)(*(undefined4 *)(*param_1 + 0x208));
  LookupActivity__FPvP9entvars_si(uVar1,*param_1,param_2);
  return;
}


// LookupActivity__FPvP9entvars_si  @ 0008748c
int LookupActivity__FPvP9entvars_si(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *local_c;
  int local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    iVar1 = param_1 + *(int *)(param_1 + 0xa8);
    iVar2 = 0;
    local_8 = -1;
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0xa4)) {
      piVar3 = (int *)(iVar1 + 0x2c);
      local_c = (int *)(iVar1 + 0x28);
      do {
        if ((*local_c == param_3) &&
           ((iVar2 = iVar2 + *piVar3, iVar2 == 0 ||
            (iVar1 = (*DAT_001c1188)(0,iVar2 + -1), iVar1 < *piVar3)))) {
          local_8 = iVar4;
        }
        piVar3 = piVar3 + 0x2c;
        local_c = local_c + 0x2c;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0xa4));
    }
  }
  return local_8;
}


