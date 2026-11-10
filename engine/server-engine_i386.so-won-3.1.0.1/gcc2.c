// gcc2_compiled.  @ 0003f230
void processEntry gcc2_compiled_(void)

{
  code *pcVar1;
  
  if (completed_3 == 0) {
    while (*(int *)p_2 != 0) {
      pcVar1 = *(code **)p_2;
      p_2 = p_2 + 4;
      (*pcVar1)();
    }
    __deregister_frame_info(&cie_000b5288);
    completed_3 = 1;
  }
  return;
}


// gcc2_compiled.  @ 000a3030
void gcc2_compiled_(void)

{
  undefined *puVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR__GLOBAL__I_WSAGetLastError__Fv_000bb260;
  puVar1 = PTR__GLOBAL__I_WSAGetLastError__Fv_000bb260;
  while (puVar1 != (undefined *)0xffffffff) {
    (*(code *)*ppuVar2)();
    ppuVar2 = ppuVar2 + -1;
    puVar1 = *ppuVar2;
  }
  return;
}


