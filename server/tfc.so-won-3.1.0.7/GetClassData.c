// GetClassData__8CAreaDefPCc  @ 00087210
int GetClassData__8CAreaDefPCc(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  param_1 = param_1 + 0x448;
  do {
    iVar1 = strcasecmp(param_2,(&sClassNames)[iVar2]);
    if (iVar1 == 0) {
      return param_1;
    }
    iVar1 = strcasecmp(param_2,(&PTR_s_Scout_00169224)[iVar2]);
    if (iVar1 == 0) {
      return param_1 + 0xc;
    }
    iVar1 = strcasecmp(param_2,(&PTR_s_Sniper_00169228)[iVar2]);
    if (iVar1 == 0) {
      return param_1 + 0x18;
    }
    param_1 = param_1 + 0x24;
    iVar2 = iVar2 + 3;
  } while (iVar2 < 0xc);
  return 0;
}


