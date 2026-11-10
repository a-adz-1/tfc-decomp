// GetClassData__8CAreaDefPCc  @ 00086de4
int GetClassData__8CAreaDefPCc(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = strcasecmp(param_2,(&sClassNames)[iVar2]);
    if (iVar1 == 0) {
      return param_1 + 0x458 + iVar2 * 0xc;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xc);
  return 0;
}


