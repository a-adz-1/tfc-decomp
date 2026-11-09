// Ghidra decompilation of functions from tfc/h_export.cpp
// 1 functions, ordered by original source line

// GiveFnptrsToDll  @ 000e0190  (line 64)

void GiveFnptrsToDll(enginefuncs_t *pengfuncsFromEngine,globalvars_t *pGlobals)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  do {
    uVar3 = uVar2;
    uVar1 = *(undefined4 *)((int)&pengfuncsFromEngine->pfnPrecacheSound + uVar3);
    *(undefined4 *)((int)&g_engfuncs.pfnPrecacheModel + uVar3) =
         *(undefined4 *)((int)&pengfuncsFromEngine->pfnPrecacheModel + uVar3);
    *(undefined4 *)((int)&g_engfuncs.pfnPrecacheSound + uVar3) = uVar1;
    uVar2 = uVar3 + 8;
  } while (uVar3 + 8 < 0x278);
  *(undefined4 *)((int)&g_engfuncs.pfnSetModel + uVar3) =
       *(undefined4 *)((int)&pengfuncsFromEngine->pfnSetModel + uVar3);
  gpGlobals = pGlobals;
  return;
}


