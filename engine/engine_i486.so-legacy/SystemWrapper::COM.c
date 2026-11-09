// SystemWrapper::COM_GetBaseDir  @ 0009a490
/* non-virtual thunk to SystemWrapper::COM_GetBaseDir() */

void __thiscall SystemWrapper::COM_GetBaseDir(SystemWrapper *this)

{
  COM_GetBaseDir((SystemWrapper *)&this[-1].m_EngineWrapper);
  return;
}


// SystemWrapper::COM_GetBaseDir  @ 0009a4a0
/* DWARF original prototype: char * COM_GetBaseDir(SystemWrapper * this) */

char * __thiscall SystemWrapper::COM_GetBaseDir(SystemWrapper *this)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0009a4ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(**(code **)((int)this->super_IBaseSystem + 0xa0))();
  return pcVar1;
}


