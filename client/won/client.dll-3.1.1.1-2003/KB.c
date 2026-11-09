// KB_Find  @ 27026120
undefined4 __thiscall KB_Find(void *this,byte *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  void *extraout_ECX;
  
  puVar1 = DAT_270b58e0;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    uVar2 = FUN_27052700(this,param_1,(byte *)(puVar1 + 2));
    if (uVar2 == 0) break;
    puVar1 = (undefined4 *)*puVar1;
    this = extraout_ECX;
  }
  return puVar1[1];
}


