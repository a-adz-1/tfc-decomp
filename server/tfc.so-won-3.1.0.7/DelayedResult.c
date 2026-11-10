// DelayedResult__11CBaseEntity  @ 0010b4a4
void DelayedResult__11CBaseEntity(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*param_1 + 400);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      uVar2 = 0;
      goto LAB_0010b4e2;
    }
  }
  uVar2 = *(undefined4 *)(iVar1 + 0x7c);
LAB_0010b4e2:
  if (param_1[0x86] == 4) {
    DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,uVar2,param_1[0x23]);
  }
  return;
}


