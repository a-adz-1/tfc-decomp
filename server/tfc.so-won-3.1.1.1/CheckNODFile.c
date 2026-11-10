// CheckNODFile__6CGraphPc  @ 000cb094
undefined4 CheckNODFile__6CGraphPc(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iStack_2008;
  char local_2004 [4];
  char local_2000 [4];
  char local_1ffc [4];
  char local_1ff8;
  undefined4 local_1004;
  undefined2 local_1000;
  
  local_1004 = 0x7370616d;
  local_1000 = 0x2f;
  strcat((char *)&local_1004,param_2);
  strcat((char *)&local_1004,".bsp");
  local_2004[0] = 'm';
  local_2004[1] = 'a';
  local_2004[2] = 'p';
  local_2004[3] = 's';
  local_2000[0] = '/';
  local_2000[1] = 'g';
  local_2000[2] = 'r';
  local_2000[3] = 'a';
  local_1ffc[0] = 'p';
  local_1ffc[1] = 'h';
  local_1ffc[2] = 's';
  local_1ffc[3] = '/';
  local_1ff8 = '\0';
  strcat(local_2004,param_2);
  strcat(local_2004,".nod");
  iVar1 = (*pcRam0019f828)(&local_1004,local_2004,&iStack_2008);
  if (iVar1 != 0) {
    if (iStack_2008 < 1) {
      return 1;
    }
    (*DAT_0019f794)(2,".NOD File will be updated\n\n");
  }
  return 0;
}


