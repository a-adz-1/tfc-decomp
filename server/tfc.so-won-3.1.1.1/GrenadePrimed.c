// GrenadePrimed__15CTFPrimeGrenade  @ 000ff24c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GrenadePrimed__15CTFPrimeGrenade(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*param_1 + 0x198);
  if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar2 + 0x7c);
  }
  bVar1 = false;
  if (*(int *)(iVar2 + 0x80) == 0) {
    if (((*(byte *)(iVar2 + 0x85) & 4) == 0) &&
       (iVar3 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x8c))(iVar2), iVar3 != 0)) {
      *(float *)(*param_1 + 0x104) = (float)_FUN_00154578 + *gpGlobals;
      if (*gpGlobals <= (float)param_1[0x1ae]) {
        return;
      }
      bVar1 = true;
    }
    *(uint *)(iVar2 + 0x84) = *(uint *)(iVar2 + 0x84) & 0xfffffbfe;
    if (bVar1) {
      ExplodeInHand__15CTFPrimeGrenade(param_1);
    }
    else {
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x454) + 0x8c))(iVar2);
      if (iVar2 == 0) {
        DeadThrow__15CTFPrimeGrenade(param_1);
      }
      else {
        Throw__15CTFPrimeGrenade(param_1);
      }
    }
  }
  else {
    *(undefined4 *)(iVar2 + 0x80) = 0;
    *(uint *)(iVar2 + 0x84) = *(uint *)(iVar2 + 0x84) & 0xfffffbfe;
    dremove__FP11CBaseEntity(param_1);
  }
  return;
}


