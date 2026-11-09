// SystemWrapper::COM_GetBaseDir  @ 0007f040
/* DWARF original prototype: char * COM_GetBaseDir(SystemWrapper * this) */

char * __thiscall SystemWrapper::COM_GetBaseDir(SystemWrapper *this)

{
  code *UNRECOVERED_JUMPTABLE;
  char *pcVar1;
  
  do {
    UNRECOVERED_JUMPTABLE = *(code **)((int)this->super_IBaseSystem + 0xa0);
  } while (UNRECOVERED_JUMPTABLE == COM_GetBaseDir);
                    /* WARNING: Could not recover jumptable at 0x0007f05c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*UNRECOVERED_JUMPTABLE)();
  return pcVar1;
}


// SystemWrapper::COM_GetBaseDir  @ 0007f060
/* non-virtual thunk to SystemWrapper::COM_GetBaseDir() */

void __thiscall SystemWrapper::COM_GetBaseDir(SystemWrapper *this)

{
  COM_GetBaseDir((SystemWrapper *)&this[-1].m_EngineWrapper);
  return;
}


