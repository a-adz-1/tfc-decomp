// ReadAuthList__Fv  @ 000cc6d0
undefined4 * ReadAuthList__Fv(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int local_18;
  undefined4 *local_14;
  int local_8;
  
  puVar2 = (undefined4 *)Crypt_ParseServers__FPc(g_szServerFile);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    uVar3 = clock();
    srand(uVar3);
    uVar3 = clock();
    srand(uVar3);
    uVar3 = clock();
    srand(uVar3);
    local_8 = 0;
    for (local_14 = puVar2; local_14 != (undefined4 *)0x0; local_14 = (undefined4 *)*local_14) {
      local_8 = local_8 + 1;
    }
    if (local_8 != 1) {
      puVar4 = (undefined4 *)__builtin_vec_new(local_8 * 4);
      local_8 = 0;
      for (local_14 = puVar2; local_14 != (undefined4 *)0x0; local_14 = (undefined4 *)*local_14) {
        puVar4[local_8] = local_14;
        local_8 = local_8 + 1;
      }
      for (local_18 = 0; local_18 < 100; local_18 = local_18 + 1) {
        iVar5 = rand();
        iVar6 = rand();
        uVar1 = puVar4[iVar5 % local_8];
        puVar4[iVar5 % local_8] = puVar4[iVar6 % local_8];
        puVar4[iVar6 % local_8] = uVar1;
      }
      for (local_18 = 0; local_18 < local_8 + -1; local_18 = local_18 + 1) {
        *(undefined4 *)puVar4[local_18] = puVar4[local_18 + 1];
      }
      *(undefined4 *)puVar4[local_8 + -1] = 0;
      puVar2 = (undefined4 *)*puVar4;
      if (puVar4 != (undefined4 *)0x0) {
        __builtin_vec_delete(puVar4);
      }
    }
  }
  return puVar2;
}


