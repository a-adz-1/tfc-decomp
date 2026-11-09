// Scheme_Init  @ 000b1940
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Scheme_Init(void)

{
  g_CV_BitmapFonts = (*gEngfuncs.pfnRegisterVariable)("bitmapfonts","1",0);
  return;
}


