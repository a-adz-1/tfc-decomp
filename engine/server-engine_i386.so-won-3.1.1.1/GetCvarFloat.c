// GetCvarFloat__13EngineWrapperPc  @ 000979c0
longdouble GetCvarFloat__13EngineWrapperPc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = Cvar_FindVar(param_2);
  if (iVar1 == 0) {
    lVar2 = (longdouble)0;
  }
  else {
    lVar2 = (longdouble)*(float *)(iVar1 + 0xc);
  }
  return lVar2;
}


