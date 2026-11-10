// GetState__13EngineWrapper  @ 000996fc
undefined4 GetState__13EngineWrapper(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetState__16BaseSystemModule(param_1 + 4);
  return uVar1;
}


// GetState__13SystemWrapper  @ 00099938
undefined4 GetState__13SystemWrapper(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetState__16BaseSystemModule(param_1 + 4);
  return uVar1;
}


// GetState__16BaseSystemModule  @ 000cb760
undefined4 GetState__16BaseSystemModule(int param_1)

{
  return *(undefined4 *)(param_1 + 0x11c);
}


// GetState__7CEngine  @ 00099dd8
undefined4 GetState__7CEngine(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


