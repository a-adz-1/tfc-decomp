// FSaveGraph__6CGraphPc  @ 000c87bc
undefined4 FSaveGraph__6CGraphPc(int *param_1,char *param_2)

{
  undefined4 uVar1;
  FILE *__s;
  undefined4 local_1008;
  char local_1004 [4096];
  
  local_1008 = 0x10;
  if ((*param_1 == 0) || (param_1[1] == 0)) {
    (*DAT_0019f794)(2,"Graph not ready!\n");
    uVar1 = 0;
  }
  else {
    (*DAT_0019f82c)(local_1004);
    strcat(local_1004,"/maps");
    mkdir(local_1004,0x1ff);
    strcat(local_1004,"/graphs");
    mkdir(local_1004,0x1ff);
    strcat(local_1004,"/");
    strcat(local_1004,param_2);
    strcat(local_1004,".nod");
    __s = fopen(local_1004,"wb");
    (*DAT_0019f794)(2,"Created: %s\n",local_1004);
    if (__s == (FILE *)0x0) {
      (*DAT_0019f794)(2,"Couldn\'t Create: %s\n",local_1004);
      uVar1 = 0;
    }
    else {
      fwrite(&local_1008,4,1,__s);
      fwrite(param_1,0x20cc,1,__s);
      fwrite((void *)param_1[3],0x58,param_1[6],__s);
      fwrite((void *)param_1[4],0x18,param_1[7],__s);
      fwrite((void *)param_1[9],0x10,param_1[6],__s);
      if (((void *)param_1[5] != (void *)0x0) && (param_1[8] != 0)) {
        fwrite((void *)param_1[5],1,param_1[8],__s);
      }
      if (((void *)param_1[0x82f] != (void *)0x0) && (param_1[0x830] != 0)) {
        fwrite((void *)param_1[0x82f],2,param_1[0x830],__s);
      }
      fclose(__s);
      uVar1 = 1;
    }
  }
  return uVar1;
}


