// ReadNamedString__8CRestorePCc  @ 00120c94
undefined4 ReadNamedString__8CRestorePCc(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar1 = ReadShort__8CRestore(param_1);
  ReadShort__8CRestore(param_1);
  uVar2 = BufferPointer__8CRestore(param_1);
  BufferSkipBytes__8CRestorei(param_1,uVar1);
  return uVar2;
}


