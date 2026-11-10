// gcc2_compiled.  @ 0007f080
void processEntry gcc2_compiled_(void)

{
  code *pcVar1;
  
  if (completed_3 == 0) {
    while (*(int *)p_2 != 0) {
      pcVar1 = *(code **)p_2;
      p_2 = p_2 + 4;
      (*pcVar1)();
    }
    __deregister_frame_info(&cie_0015fd34);
    completed_3 = 1;
  }
  return;
}


// gcc2_compiled.  @ 000a7b5c
void gcc2_compiled_(void)

{
  g_vecZero = 0;
  DAT_001a7e04 = 0;
  DAT_001a7e08 = 0;
  return;
}


// gcc2_compiled.  @ 00128c70
void gcc2_compiled_(void)

{
  undefined *puVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR__GLOBAL__I__13CActAnimating_m_SaveData_001a5054;
  puVar1 = PTR__GLOBAL__I__13CActAnimating_m_SaveData_001a5054;
  while (puVar1 != (undefined *)0xffffffff) {
    (*(code *)*ppuVar2)();
    ppuVar2 = ppuVar2 + -1;
    puVar1 = *ppuVar2;
  }
  return;
}


