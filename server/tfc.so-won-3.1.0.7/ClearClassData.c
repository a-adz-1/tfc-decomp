// ClearClassData__8CAreaDef  @ 00087330
void ClearClassData__8CAreaDef(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  param_1 = param_1 + 0x448;
  do {
    Clear__15DBAreaClassData(param_1);
    Clear__15DBAreaClassData(param_1 + 0xc);
    Clear__15DBAreaClassData(param_1 + 0x18);
    Clear__15DBAreaClassData(param_1 + 0x24);
    Clear__15DBAreaClassData(param_1 + 0x30);
    Clear__15DBAreaClassData(param_1 + 0x3c);
    param_1 = param_1 + 0x48;
    iVar1 = iVar1 + 6;
  } while (iVar1 < 0xc);
  return;
}


