// LookupActivity__14CBaseAnimatingi  @ 000c2070
void LookupActivity__14CBaseAnimatingi(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_0019f7c8)(*(undefined4 *)(*param_1 + 0x208));
  LookupActivity__FPvP9entvars_si(uVar1,*param_1,param_2);
  return;
}


// LookupActivity__FPvP9entvars_si  @ 00087c18
int LookupActivity__FPvP9entvars_si(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_1 == 0) {
    local_10 = 0;
  }
  else {
    local_c = 0;
    local_10 = -1;
    iVar2 = param_1 + *(int *)(param_1 + 0xa8);
    iVar4 = 0;
    local_14 = *(int *)(param_1 + 0xa4);
    if (0 < local_14) {
      do {
        iVar3 = iVar4 * 0xb0;
        if (*(int *)(iVar2 + 0x28 + iVar3) == param_3) {
          local_c = local_c + *(int *)(iVar2 + 0x2c + iVar3);
          if (local_c != 0) {
            iVar1 = (*DAT_0019f808)(0,local_c + -1);
            local_14 = *(int *)(param_1 + 0xa4);
            if (*(int *)(iVar2 + 0x2c + iVar3) <= iVar1) goto LAB_00087cbe;
          }
          local_10 = iVar4;
        }
LAB_00087cbe:
        iVar4 = iVar4 + 1;
      } while (iVar4 < local_14);
    }
  }
  return local_10;
}


