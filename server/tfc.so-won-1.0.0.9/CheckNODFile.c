// CheckNODFile__6CGraphPc  @ 000cdf10
undefined4 CheckNODFile__6CGraphPc(undefined4 param_1,char *param_2)

{
  int iVar1;
  int local_808;
  char local_804 [1024];
  char local_404 [1024];
  
  builtin_strncpy(local_404,"maps/",6);
  strcat(local_404,param_2);
  strcat(local_404,".bsp");
  builtin_strncpy(local_804,"maps/graphs/",0xd);
  strcat(local_804,param_2);
  strcat(local_804,".nod");
  iVar1 = (*DAT_00175648)(local_404,local_804,&local_808);
  if (iVar1 != 0) {
    if (local_808 < 1) {
      return 1;
    }
    (*DAT_001755b4)(2,".NOD File will be updated\n\n");
  }
  return 0;
}


