// GetSystem__13EngineWrapper  @ 00099648
undefined4 GetSystem__13EngineWrapper(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetSystem__16BaseSystemModule(param_1 + 4);
  return uVar1;
}


// GetSystem__13SystemWrapper  @ 00099884
undefined4 GetSystem__13SystemWrapper(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetSystem__16BaseSystemModule(param_1 + 4);
  return uVar1;
}


// GetSystem__16BaseSystemModule  @ 000cb3b0
undefined4 GetSystem__16BaseSystemModule(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}


