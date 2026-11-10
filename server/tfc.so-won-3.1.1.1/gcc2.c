// gcc2_compiled.  @ 00086770
void processEntry gcc2_compiled_(void)

{
  code *pcVar1;
  
  if (completed_3 == 0) {
    while (*(int *)p_2 != 0) {
      pcVar1 = *(code **)p_2;
      p_2 = p_2 + 4;
      (*pcVar1)();
    }
    __deregister_frame_info(&cie_00177a78);
    completed_3 = 1;
  }
  return;
}


// gcc2_compiled.  @ 00086c24
void gcc2_compiled_(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  __11CBaseEntity(g_DefaultArea);
  iVar2 = 0x19ecf8;
  iVar1 = 0xb;
  g_DefaultArea._1108_4_ = __vt_8CAreaDef;
  do {
    Clear__15DBAreaClassData(iVar2);
    iVar2 = iVar2 + 0xc;
    bVar3 = iVar1 != 0;
    iVar1 = iVar1 + -1;
  } while (bVar3);
  g_nActiveAreas = g_nActiveAreas + 1;
  g_DefaultArea[0x4e8] = 'D';
  g_DefaultArea[0x4e9] = 'e';
  g_DefaultArea[0x4ea] = 'f';
  g_DefaultArea[0x4eb] = 'a';
  g_DefaultArea[0x4ec] = 'u';
  g_DefaultArea[0x4ed] = 'l';
  g_DefaultArea[0x4ee] = 't';
  g_DefaultArea[0x4ef] = 'A';
  g_DefaultArea[0x4f0] = 'r';
  g_DefaultArea[0x4f1] = 'e';
  g_DefaultArea[0x4f2] = 'a';
  g_DefaultArea[0x4f3] = '\0';
  g_DefaultArea._1288_4_ = 0;
  g_pActiveAreas = g_DefaultArea;
  return;
}


// gcc2_compiled.  @ 000b1fd8
void gcc2_compiled_(void)

{
  g_vecZero = 0;
  DAT_0019f664 = 0;
  DAT_0019f668 = 0;
  return;
}


// gcc2_compiled.  @ 0013e220
void gcc2_compiled_(void)

{
  undefined *puVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR__GLOBAL__I_voice_serverdebug_0019c298;
  puVar1 = PTR__GLOBAL__I_voice_serverdebug_0019c298;
  while (puVar1 != (undefined *)0xffffffff) {
    (*(code *)*ppuVar2)();
    ppuVar2 = ppuVar2 + -1;
    puVar1 = *ppuVar2;
  }
  return;
}


