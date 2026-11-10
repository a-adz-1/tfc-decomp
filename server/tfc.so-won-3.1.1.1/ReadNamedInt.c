// ReadNamedInt__8CRestorePCc  @ 00120ce8
undefined4 ReadNamedInt__8CRestorePCc(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  
  uVar1 = ReadShort__8CRestore(param_1);
  ReadShort__8CRestore(param_1);
  puVar2 = (undefined4 *)BufferPointer__8CRestore(param_1);
  BufferSkipBytes__8CRestorei(param_1,uVar1);
  return *puVar2;
}


