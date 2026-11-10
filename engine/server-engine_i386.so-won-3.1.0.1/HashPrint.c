// HashPrint__11AuthRequestPUci  @ 0009bc00
undefined1 * HashPrint__11AuthRequestPUci(undefined4 param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  char local_10 [12];
  
  memset(szReturn_467,0,0x80);
  iVar2 = 0;
  if (0 < (int)param_3) {
    uVar1 = param_3 & 3;
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          sprintf(local_10,"%02x",(uint)*param_2);
          strcat(szReturn_467,local_10);
        }
        sprintf(local_10,"%02x",(uint)param_2[2 < uVar1]);
        strcat(szReturn_467,local_10);
        iVar2 = (2 < uVar1) + 1;
      }
      sprintf(local_10,"%02x",(uint)param_2[iVar2]);
      strcat(szReturn_467,local_10);
      iVar2 = iVar2 + 1;
      if ((int)param_3 <= iVar2) {
        return szReturn_467;
      }
    }
    do {
      sprintf(local_10,"%02x",(uint)param_2[iVar2]);
      strcat(szReturn_467,local_10);
      sprintf(local_10,"%02x",(uint)param_2[iVar2 + 1]);
      strcat(szReturn_467,local_10);
      sprintf(local_10,"%02x",(uint)param_2[iVar2 + 2]);
      strcat(szReturn_467,local_10);
      sprintf(local_10,"%02x",(uint)param_2[iVar2 + 3]);
      strcat(szReturn_467,local_10);
      iVar2 = iVar2 + 4;
    } while (iVar2 < (int)param_3);
  }
  return szReturn_467;
}


