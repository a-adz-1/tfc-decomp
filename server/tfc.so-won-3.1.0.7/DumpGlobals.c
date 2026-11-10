// DumpGlobals__12CGlobalState  @ 0012296c
void DumpGlobals__12CGlobalState(int *param_1)

{
  int iVar1;
  
  (*DAT_001c1114)(1,"-- Globals --\n");
  for (iVar1 = *param_1; iVar1 != 0; iVar1 = *(int *)(iVar1 + 100)) {
    (*DAT_001c1114)(1,"%s: %s (%s)\n",iVar1,iVar1 + 0x40,
                    *(undefined4 *)(estates_716 + *(int *)(iVar1 + 0x60) * 4));
  }
  return;
}


