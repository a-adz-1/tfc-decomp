// DelayedResult__11CBaseEntity  @ 0010b700
void DelayedResult__11CBaseEntity(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*param_1 + 0x170);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001755d4)(0);
    if (iVar1 == 0) {
      uVar2 = 0;
      goto LAB_0010b732;
    }
  }
  uVar2 = *(undefined4 *)(iVar1 + 0xd8);
LAB_0010b732:
  if (param_1[0x86] == 4) {
    DoResults__FP11CBaseEntityP11CBasePlayeri(param_1,uVar2,param_1[0x24]);
  }
  return;
}


