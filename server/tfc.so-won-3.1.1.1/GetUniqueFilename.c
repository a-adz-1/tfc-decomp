// GetUniqueFilename__FPCcT0Pc  @ 0013b354
undefined4 GetUniqueFilename__FPCcT0Pc(undefined4 param_1,undefined4 param_2,char *param_3)

{
  FILE *__stream;
  int iVar1;
  
  iVar1 = 0;
  do {
    sprintf(param_3,"%s%d.%s",param_1,iVar1,param_2);
    __stream = fopen(param_3,"rb");
    if (__stream == (FILE *)0x0) {
      return 1;
    }
    fclose(__stream);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 32000);
  return 0;
}


