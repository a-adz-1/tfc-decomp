// Ghidra decompilation of functions from cl_dll/tri.cpp
// 2 functions, ordered by original source line

// HUD_DrawNormalTriangles  @ 000828f0  (line 26)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_DrawNormalTriangles(void)

{
  CHudSpectator::DrawOverview(&gHUD.m_Spectator);
  return;
}


// HUD_DrawTransparentTriangles  @ 00082910  (line 44)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void HUD_DrawTransparentTriangles(void)

{
  RunEventList();
  if (g_pParticleMan != (IParticleMan *)0x0) {
    (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[3])(g_pParticleMan);
  }
  return;
}


