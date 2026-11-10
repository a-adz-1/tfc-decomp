// idprintf__FPUci  @ 000970bc
undefined1 * idprintf__FPUci(byte *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  char local_10 [12];
  
  memset(szReturn_2,0,0x80);
  iVar2 = 0;
  if (0 < (int)param_2) {
    uVar1 = param_2 & 3;
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          sprintf(local_10,"%02x",(uint)*param_1);
          strcat(szReturn_2,local_10);
        }
        sprintf(local_10,"%02x",(uint)param_1[2 < uVar1]);
        strcat(szReturn_2,local_10);
        iVar2 = (2 < uVar1) + 1;
      }
      sprintf(local_10,"%02x",(uint)param_1[iVar2]);
      strcat(szReturn_2,local_10);
      iVar2 = iVar2 + 1;
      if ((int)param_2 <= iVar2) {
        return szReturn_2;
      }
    }
    do {
      sprintf(local_10,"%02x",(uint)param_1[iVar2]);
      strcat(szReturn_2,local_10);
      sprintf(local_10,"%02x",(uint)param_1[iVar2 + 1]);
      strcat(szReturn_2,local_10);
      sprintf(local_10,"%02x",(uint)param_1[iVar2 + 2]);
      strcat(szReturn_2,local_10);
      sprintf(local_10,"%02x",(uint)param_1[iVar2 + 3]);
      strcat(szReturn_2,local_10);
      iVar2 = iVar2 + 4;
    } while (iVar2 < (int)param_2);
  }
  return szReturn_2;
}


