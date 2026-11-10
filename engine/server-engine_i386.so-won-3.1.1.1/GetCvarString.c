// GetCvarString__13EngineWrapperPc  @ 00097a0c
undefined4 GetCvarString__13EngineWrapperPc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Cvar_FindVar(param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  return uVar2;
}


