// CheckNODFile__6CGraphPc  @ 000bdd60
undefined4 CheckNODFile__6CGraphPc(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_2004;
  char local_2000 [4];
  char local_1ffc [4];
  char local_1ff8 [4];
  char local_1ff4;
  undefined4 local_1000;
  undefined2 local_ffc;
  
  local_1000 = 0x7370616d;
  local_ffc = 0x2f;
  strcat((char *)&local_1000,param_2);
  strcat((char *)&local_1000,".bsp");
  local_2000[0] = 'm';
  local_2000[1] = 'a';
  local_2000[2] = 'p';
  local_2000[3] = 's';
  local_1ffc[0] = '/';
  local_1ffc[1] = 'g';
  local_1ffc[2] = 'r';
  local_1ffc[3] = 'a';
  local_1ff8[0] = 'p';
  local_1ff8[1] = 'h';
  local_1ff8[2] = 's';
  local_1ff8[3] = '/';
  local_1ff4 = '\0';
  strcat(local_2000,param_2);
  strcat(local_2000,".nod");
  uVar2 = 1;
  iVar1 = (*DAT_001a7fc8)(&local_1000,local_2000,&local_2004);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (0 < local_2004) {
    (*DAT_001a7f34)(2,".NOD File will be updated\n\n");
    uVar2 = 0;
  }
  return uVar2;
}


