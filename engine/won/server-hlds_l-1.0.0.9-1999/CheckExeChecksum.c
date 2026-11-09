// CheckExeChecksum__Fv  @ 08089f60
undefined4 CheckExeChecksum__Fv(void)

{
  int iVar1;
  FILE *pFVar2;
  size_t sVar3;
  int local_11c;
  char local_118 [260];
  int local_14 [4];
  
  local_11c = 0;
  strcpy(local_118,g_szEXEName);
  iVar1 = MD5_Hash_File(local_14,local_118,1,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  pFVar2 = fopen("hlds_l.dat","rb");
  if (pFVar2 != (FILE *)0x0) {
    iVar1 = CheckParm__FPCcPPc("-newdat",0);
    if (iVar1 == 0) {
      sVar3 = fread(&local_11c,4,1,pFVar2);
      fclose(pFVar2);
      if (sVar3 != 1) {
        return 1;
      }
      if (local_14[0] == local_11c) {
        return 1;
      }
      printf(
            "Your Dedicated Server executable appears to have been modified.  Please check your system for viruses and then re-install Half-Life.\n\n"
            );
      return 0;
    }
    fclose(pFVar2);
  }
  local_11c = local_14[0];
  pFVar2 = fopen("hlds_l.dat","wb");
  if (pFVar2 != (FILE *)0x0) {
    fwrite(&local_11c,4,1,pFVar2);
    fclose(pFVar2);
  }
  return 1;
}


