// KeyValues::operator_delete  @ 002621b0
/* DWARF original name: operator delete */

void KeyValues::operator_delete(void *pMem)

{
  IKeyValues *pIVar1;
  
  pIVar1 = keyvalues();
  (**(code **)(*(int *)pIVar1 + 0x10))(pIVar1,pMem);
  return;
}


// KeyValues::operator_delete  @ 002621d0
/* DWARF original name: operator delete */

void KeyValues::operator_delete(void *pMem,int nBlockUse,char *pFileName,int nLine)

{
  IKeyValues *pIVar1;
  
  pIVar1 = keyvalues();
                    /* WARNING: Could not recover jumptable at 0x002621ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)pIVar1 + 0x10))();
  return;
}


// KeyValues::operator_new  @ 00262170
/* DWARF original name: operator new */

void * KeyValues::operator_new(size_t iAllocSize)

{
  IKeyValues *pIVar1;
  void *pvVar2;
  
  pIVar1 = keyvalues();
  pvVar2 = (void *)(**(code **)(*(int *)pIVar1 + 0xc))(pIVar1,iAllocSize);
  return pvVar2;
}


// KeyValues::operator_new  @ 00262190
/* DWARF original name: operator new */

void * KeyValues::operator_new(size_t iAllocSize,int nBlockUse,char *pFileName,int nLine)

{
  IKeyValues *pIVar1;
  void *pvVar2;
  
  pIVar1 = keyvalues();
                    /* WARNING: Could not recover jumptable at 0x002621ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar2 = (void *)(**(code **)(*(int *)pIVar1 + 0xc))();
  return pvVar2;
}


