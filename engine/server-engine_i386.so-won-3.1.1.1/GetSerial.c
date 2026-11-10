// GetSerial__13EngineWrapper  @ 00099684
undefined4 GetSerial__13EngineWrapper(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetSerial__16BaseSystemModule(param_1 + 4);
  return uVar1;
}


// GetSerial__13SystemWrapper  @ 000998c0
undefined4 GetSerial__13SystemWrapper(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetSerial__16BaseSystemModule(param_1 + 4);
  return uVar1;
}


// GetSerial__16BaseSystemModule  @ 000cb39c
undefined4 GetSerial__16BaseSystemModule(int param_1)

{
  return *(undefined4 *)(param_1 + 0x120);
}


