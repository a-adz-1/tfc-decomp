// ClearClassData__8CAreaDef  @ 00086d5c
void ClearClassData__8CAreaDef(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    puVar1 = (undefined4 *)(param_1 + 0x458 + iVar2 * 0xc);
    iVar2 = iVar2 + 1;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  } while (iVar2 < 0xc);
  return;
}


