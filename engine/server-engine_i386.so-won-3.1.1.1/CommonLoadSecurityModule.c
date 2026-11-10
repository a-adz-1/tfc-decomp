// CommonLoadSecurityModule__Fi  @ 0007fc4c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CommonLoadSecurityModule__Fi(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_80 [31];
  
  if (DAT_001198c0 == 0x43210004) {
    if (_DAT_001198d0 != (code *)0x0) {
      (*_DAT_001198d0)(3);
    }
    (*g_modfuncs)(param_1);
    (*DAT_00119890)(g_engdstAddrs);
    puVar2 = &DAT_000f1df8;
    puVar3 = local_80;
    for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    (*DAT_001198bc)(local_80);
    (*DAT_00119894)();
    g_module._16_4_ = 1;
  }
  else {
    CloseSecurityModule();
  }
  return;
}


