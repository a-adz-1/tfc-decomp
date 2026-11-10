// DumpGlobals__12CGlobalState  @ 0011d480
void DumpGlobals__12CGlobalState(int *param_1)

{
  int iVar1;
  
  (*DAT_001755b4)(1,"-- Globals --\n");
  for (iVar1 = *param_1; iVar1 != 0; iVar1 = *(int *)(iVar1 + 100)) {
    (*DAT_001755b4)(1,"%s: %s (%s)\n",iVar1,iVar1 + 0x40,
                    *(undefined4 *)(estates_680 + *(int *)(iVar1 + 0x60) * 4));
  }
  return;
}


