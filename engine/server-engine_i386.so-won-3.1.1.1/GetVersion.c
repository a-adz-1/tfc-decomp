// GetVersion__13EngineWrapper  @ 00099738
undefined4 GetVersion__13EngineWrapper(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetVersion__16BaseSystemModule(param_1 + 4);
  return uVar1;
}


// GetVersion__13SystemWrapper  @ 00099974
undefined4 GetVersion__13SystemWrapper(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetVersion__16BaseSystemModule(param_1 + 4);
  return uVar1;
}


// GetVersion__16BaseSystemModule  @ 000cb370
undefined4 GetVersion__16BaseSystemModule(void)

{
  undefined4 uVar1;
  
  uVar1 = COM_BuildNumber__Fv();
  return uVar1;
}


