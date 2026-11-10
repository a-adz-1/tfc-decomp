// GetTeamName__Fi  @ 0010e7d0
undefined1 * GetTeamName__Fi(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 < 1) {
    puVar1 = &DAT_0014977c;
  }
  else {
    puVar1 = *(undefined1 **)(sTNameCvars + param_1 * 4 + 0x1c);
  }
  return puVar1;
}


